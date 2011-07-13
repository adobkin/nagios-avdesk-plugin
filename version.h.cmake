/*
 * Copyright (c) Doctor Web, 2003-2011
 *
 * Following code is the property of Doctor Web, Ltd.
 * Dr.Web is a registred trademark of Doctor Web, Ltd.
 *
 * http://www.drweb.com
 * http://www.av-desk.com
 *
 */

#ifndef VERSION_H
#define	VERSION_H

/**
 * Название библиотеки
 * @ingroup general
 */
#define ICAVDESK_NAME 		"${PROJECT_NAME}"

#define ICAVDESK_AUTHOR 	"Anton Dobkin <anton.dobkin@gmail.com>"

#define ICAVDESK_VERSION_STRING "${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH}"

/**
 * Версия разделенная на части
 * @ingroup general
 */
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

