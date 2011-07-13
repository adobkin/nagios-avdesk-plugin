##Nagios/Icinga plugin##

This plugin check the Dr.Web ES/AV-Desk service on the specified host and port

###INSTALL###

1. cmake .
2. make
3. copy file check_avdesk to your plugins directory (e.g. /usr/share/nagios)

###USE###

__Add new command:__

    # 'check_avdesk' command definition
    define command {
		command_name	check_avdesk
		command_line	$USER1$/check_avdesk -H $HOSTADDRESS$ -p $ARG1$
    }

__Add new service:__

    define service {
		use 						local-service
		host_name                   test.nsk.av-desk.com
    	service_description         Dr.Web Enterprise
    	check_command				check_avdesk!2193!
    	notifications_enabled		1
    }
