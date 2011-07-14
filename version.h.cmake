#ifndef VERSION_H
#define	VERSION_H

#define ICAVDESK_NAME 		"${PROJECT_NAME}"

#define ICAVDESK_AUTHOR 	"Anton Dobkin"
#define ICAVDESK_AUTHOR_EMAIL 	"anton.dobkin@gmail.com"

#define ICAVDESK_VERSION_STRING "${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH}"

#define ICAVDESK_VERSION_MAJOR  ${VERSION_MAJOR}	//!< Мажорная часть версии
#define ICAVDESK_VERSION_MINOR  ${VERSION_MINOR}	//!< Минорная часть версии 
#define ICAVDESK_VERSION_PATCH  ${VERSION_PATCH}	//!< Патч часть версии

/**
 * Числовая версия в шестнадцатеричном формате:
 *
 * 	0xXXYYZZ
 *
 * Где XX - Мажорная часть версии, YY - Минорная часть версии, XX - Патч часть версии.
 * 
 * @ingroup general
 */
#define ICAVDESK_VERSION_NUM  0x${NUM_VERSION}

#endif	/* VERSION_H */

