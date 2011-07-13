#ifndef COMMON_H
#define	COMMON_H

#include <stdio.h>							
#include <stdlib.h>
#include <errno.h>
#include <time.h>

#include "config.h"
#include "version.h"
#include "platform.h"

#ifdef HAVE_FEATURES_H
#include <features.h>
#endif

#ifdef HAVE_STRINGS_H
#include <strings.h>
#endif
#ifdef HAVE_STRING_H
#include <string.h>
#endif

#ifdef HAVE_UNISTD_H
#include <unistd.h>
#endif

#ifdef HAVE_SYS_TYPES_H
#include <sys/types.h>
#endif

#ifdef HAVE_SYS_SOCKET_H
#include <sys/socket.h>
#endif

#ifdef HAVE_SIGNAL_H
#include <signal.h>
#endif

#ifdef HAVE_MALLOC_H
#include <malloc.h>
#endif

#ifdef HAVE_NETINET_IN_H
#include <netinet/in.h>
#endif

#ifdef HAVE_ARPA_INET_H
#include <arpa/inet.h>
#endif

#ifdef HAVE_GETOPT_H
#include <getopt.h>
#endif

#ifdef HAVE_NETDB_H
#include <netdb.h>
#endif

#ifdef HAVE_CTYPE_H
#include <ctype.h>
#endif

enum {
    OK = 0,
    ERROR = -1
};

/* AIX seems to have this defined somewhere else */
#ifndef FALSE
enum {
    FALSE,
    TRUE
};
#endif

enum {
    STATE_OK,
    STATE_WARNING,
    STATE_CRITICAL,
    STATE_UNKNOWN,
    STATE_DEPENDENT
};

#define AGENT_PORT 2193
#define DEFAULT_SOCKET_TIMEOUT 10
#define UNKNOWN_SERVICE_MSG "CRITICAL - Unknown service. Specified incorrect port or it's not Dr.Web ES/AV-Desk server\n"
#define CANNOT_CONNECT_MSG "CRITICAL - Cannot connect to server. Specified incorrect port or it's not Dr.Web ES/AV-Desk server\n"

#endif	/* COMMON_H */
