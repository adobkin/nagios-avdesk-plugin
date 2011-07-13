#ifndef PLATFORM_H
#define	PLATFORM_H

#ifdef	__cplusplus
extern "C" {
#endif

/* 
 * Pre-defined Operating System Macros: http://predef.sourceforge.net/preos.html
 * Pre-defined MS VC macros: http://msdn.microsoft.com/en-us/library/b0084kay(v=vs.71).aspx
 * Pre-defined GCC marcos: http://gcc.gnu.org/onlinedocs/cpp/Common-Predefined-Macros.html
 */

#if defined(_WIN32) || defined(WIN32) || defined(__WIN32__) || defined(WINDOWS) || defined(_WINDOWS) || defined(__WINDOWS__) \
        || defined(_MSC_VER) || defined(__CYGWIN__) || defined(__MINGW32__) || defined(__BORLANDC__)
#define OS_WINDOWS 1
#endif
    
#if defined(__FreeBSD__)
#define OS_FREEBSD 1
#endif

#if defined(__NetBSD__)
#define OS_NETBSD 1
#endif

#if defined(__OpenBSD__)
#define OS_OPENBSD 1
#endif
    
#if defined(__APPLE__) && defined(__MACH__)
#define OS_MACOSX 1
#endif
    
#if defined(Macintosh) || defined(macintosh)
#define OS_MACOS 1
#endif
    
#if defined(OS_MACOS) || defined(OS_MACOSX)
#define OS_APPLY_FAMILE 1    
#endif

#if defined(sun) || defined(__sun)
#define OS_SOLARIS 1
#endif
    
#if defined(linux) || defined(__linux__)
#define OS_LINUX 1
#endif
    
#if defined(OS_OPENBSD) || defined(OS_FREEBSD) || defined(OS_NETBSD) || defined(OS_APPLE_FAMILY) | defined(OS_SOLARIS)
#define OS_BSD_FAMILY 1
#endif
    
#if defined(OS_LINUX) || defined(OS_BSD_FAMILY)
#define OS_UNIX_FAMILY 1    
#endif
    
#ifdef	__cplusplus
}
#endif

#endif	/* PLATFORM_H */

