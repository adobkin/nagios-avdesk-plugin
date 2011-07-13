#ifndef _CONFIG_H_
#define _CONFIG_H_ 1

#include "platform.h"

#cmakedefine HAVE_STRERROR_R

/* */
#cmakedefine HAVE_MALLOC_H

/* unistd.h - standard symbolic constants and types. See http://pubs.opengroup.org/onlinepubs/007908799/xsh/unistd.h.html */
#cmakedefine HAVE_UNISTD_H

/* sys/types.h - data types. See http://pubs.opengroup.org/onlinepubs/007908799/xsh/systypes.h.html */
#cmakedefine HAVE_SYS_TYPES_H

/* */
#cmakedefine HAVE_SYS_STAT_H

/* string.h - string operations. See http://pubs.opengroup.org/onlinepubs/007908799/xsh/string.h.html */
#cmakedefine HAVE_STRING_H

/* strings.h - string operations. Defines functions:  strcasecmp, strncasecmp.  See http://pubs.opengroup.org/onlinepubs/007908799/xsh/strings.h.html */
#cmakedefine HAVE_STRINGS_H

/* errno.h - system error numbers. See http://pubs.opengroup.org/onlinepubs/007908799/xsh/errno.h.html */
#cmakedefine HAVE_ERRNO_H

/* time.h - time types. See http://pubs.opengroup.org/onlinepubs/007908799/xsh/time.h.html */
#cmakedefine HAVE_TIME_H

/* stdarg.h - handle variable argument list. See http://pubs.opengroup.org/onlinepubs/007908799/xsh/stdarg.h.html */
#cmakedefine HAVE_STDARG_H

#cmakedefine HAVE_FEATURES_H
#cmakedefine HAVE_GETOPT_H
#cmakedefine HAVE_CTYPE_H
#cmakedefine HAVE_NETINET_IN_H
#cmakedefine HAVE_ARPA_INET_H
#cmakedefine HAVE_NETDB_H

#if defined OS_OPENBSD
#undef HAVE_MALLOC_H
#endif

#if defined HAVE_FEATURES_H
#include <features.h>
#endif

#endif

