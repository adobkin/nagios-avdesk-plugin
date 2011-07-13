#include "common.h"

const char *progname = "check_avdesk";
const char *copyright = "2011";
const char *email = "anton.dobkin@gmail.com";

unsigned int avdesk_agent_port = AGENT_PORT;
char *avdesk_host = NULL;
int sd = -1;
short int address_family = AF_INET;
unsigned int timeout = DEFAULT_SOCKET_TIMEOUT;

int verbose = FALSE;

static void print_usage(void);
static void print_help(void);
static int process_arguments(int, char **);
static int check_avdesk(void);
static void socket_timeout_alarm_handler(int);

void icavdesk_free(void *);


int main(int argc, char** argv) {
    int result = STATE_UNKNOWN;
    
    if (process_arguments (argc, argv) == ERROR) {
        printf ("%s: Could not parse arguments\n", progname);
	print_usage();
	exit(STATE_UNKNOWN);
    }
    
    /* initialize alarm signal handling */
    signal (SIGALRM, socket_timeout_alarm_handler);
    /* set socket timeout */
    alarm (timeout);
    
    result = check_avdesk();
    return result;
}

static int process_arguments (int argc, char **argv) {
    int c = 1;
    char *p = NULL;
    int port = -1;
    int tmout = -1;
    char *short_options = "Vh4t:p:H:";
    
    int option = 0;
    static struct option longopts[] = {
        {"version", no_argument, 0, 'V'},
        {"help", no_argument, 0, 'h'},
        {"timeout", required_argument, 0, 't'},
        {"hostname", required_argument, 0, 'H'},
        {"port", required_argument, 0, 'p'},
        {"use-ipv4", no_argument, 0, '4'},
        {NULL, 0, 0, 0}
    };
    
     if (argc < 2) {
        return ERROR;
     }
    
     while( (c = getopt_long (argc, argv, short_options, longopts, &option)) != -1) {
         switch(c) {
             case 'h':
                print_help();
                exit (STATE_OK);
                break;
             case 'V':
                printf("%s %s\n", progname, ICAVDESK_VERSION_STRING);
                exit (STATE_OK);
                break;
             case 'v':
                verbose = TRUE;
                break;
             case '4':
                address_family = AF_INET;
                break;
             case 'H':
                 avdesk_host = strdup (optarg);
                 break;
             case 'p':
                 p = strdup (optarg);
                 port = atoi(p);
                 if( port < 1 || port > 65535 ) {
                     printf("%s: Invalid agent port number '%s'\n", progname, p);
                     icavdesk_free(p);
                     exit(STATE_UNKNOWN);
                 }
                 icavdesk_free(p);
                 p = NULL;
                 avdesk_agent_port = port;
                 break;
             case 't':
                 p = strdup (optarg);
                 tmout = atoi(p);
                 if(tmout < 1 ) {
                     printf("%s: Timeout interval must be a positive integer\n", progname);
                     icavdesk_free(p);
                     exit(STATE_UNKNOWN);
                 }
                 icavdesk_free(p);
                 p = NULL;
                 timeout = tmout;
                 break;
             case '?':
                 exit(STATE_UNKNOWN);
                 break;
         }
     }
    
    if(avdesk_host == NULL) {
        icavdesk_free(avdesk_host);
        printf("%s: You must specify a Dr.Web ES/AV-Desk server IP address or host name", progname);
        exit(STATE_UNKNOWN);
    }
    
    return OK;
}

static void print_usage(void) {
    printf("%s\n", "Usage:");
    printf("  %s -H <host> [-p <port>] [-4] [-t <timeout>]\n", progname);
}

static void print_help(void) {
    printf("%s %s\n", progname, ICAVDESK_VERSION_STRING);
    printf("Copyright (c) 2011 %s\n", ICAVDESK_AUTHOR);
    
    printf("This plugin checks the Dr.Web ES/AV-Desk service on the specified host and port\n");
    printf("\n");
    print_usage();
    printf("\n");
    printf("-h, --help for detailed help\n");
    printf("-V, --version for version information\n");
    printf("-H, --hostname=ADDRESS\n");
    printf("    Host name or IP Address\n");
    printf("-p, --port=INTEGER\n");
    printf("    HTTP port number (default: %d)\n", AGENT_PORT);
    printf("-t, --timeout=INTEGER\n");
    printf("    Seconds before connection times out (default: %d)\n", DEFAULT_SOCKET_TIMEOUT);
    
    printf("\nSend email to %s if you have questions\nregarding use of this software or to submit patches or suggest improvements\n", email);
    printf("\nThe icinga plugins come with ABSOLUTELY NO WARRANTY. You may redistribute\ncopies of the plugins under the terms of the GNU General Public License.\nFor more information about these matters, see the file named COPYING.\n");
}

void icavdesk_free( void *ptr ){
    if ( ptr ) {
	free ( ptr );
    }
}

static int check_avdesk(void) {
    struct sockaddr_in server;
    struct hostent *host = NULL;
    unsigned int buff_len = 1024;
    char in_buff[buff_len+1];
    char protocol[20];
    unsigned int i = 0;
    int rc = -1;
    //struct timeval tv;
    char *start = NULL;
    char *end = NULL;
    
    host = gethostbyname(avdesk_host);
    if(host == NULL){
        printf("CRITICAL - Host not found, code: %d\n", h_errno);
        return STATE_CRITICAL;
    }
    
    memset(&server, 0, sizeof(server));
    server.sin_family = address_family;
    server.sin_port   = htons(avdesk_agent_port);
    memcpy(&server.sin_addr, host->h_addr, sizeof(server.sin_addr));
    
    sd = socket(address_family, SOCK_STREAM, 0);
    if (sd < 0) {
        printf("UNKNOWN - Cannot create socket\n");
        return STATE_UNKNOWN;
    }
    
    if( connect(sd, (struct sockaddr *)&server, sizeof(server)) == -1 ) {
        printf(CANNOT_CONNECT_MSG);
        return STATE_CRITICAL;
    }
    
    rc = recv(sd, & in_buff, buff_len, 0);
    
    if(rc <= 0) {
        printf(UNKNOWN_SERVICE_MSG);
        return STATE_CRITICAL; 
    }
    
    start = strstr(in_buff, "PROTOCOL");
    
    if(start != NULL) {
        start += 9;

        end = strstr(start, "AGENT");
        if(end != NULL) {
            *end = '\0';
        }
        
        while(*start) {
            if(isdigit(*start)) {
               protocol[i] = *start + '\0';
               i++;
            } else if(*start == ' ' && *(start+1) != '\0') {
                protocol[i] = '.';
                i++;
            }
            start++;
        }
        protocol[i] = '\0';

    } else {
       printf(UNKNOWN_SERVICE_MSG);
       return STATE_CRITICAL;  
    }
    
    printf("OK - Protocol: %s\n", protocol);
    return STATE_OK;
}

static void socket_timeout_alarm_handler(int sig)
{
    if (sig == SIGALRM) {
        printf ("CRITICAL - Socket timeout after %d seconds\n", timeout);
    } else {
        printf ("CRITICAL - Abnormal timeout after %d seconds\n", timeout);
    }

    exit (STATE_CRITICAL);
}