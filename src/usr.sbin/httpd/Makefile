#	$OpenBSD: Makefile,v 1.30 2017/07/03 22:21:47 espie Exp $

LOCALBASE?=	/usr/local
BINDIR?=	${LOCALBASE}/sbin
EVENTDIR?=	${.CURDIR}/../../../libevent
IMSGDIR?=	${.CURDIR}/../../../libimsg

PROG=		httpd
SRCS=		parse.y
SRCS+=		config.c control.c httpd.c log.c logger.c proc.c server.c
SRCS+=		server_http.c server_file.c server_fcgi.c

.PATH: ${.CURDIR}/../../lib/libc/gen
SRCS+=	vis.c

.PATH:	${.CURDIR}/../../lib/libc/crypt
SRCS+=	bcrypt.c \
	cryptutil.c

MAN=		httpd.8 httpd.conf.5

LDADD=		${EVENTDIR}/src/lib/libevent/libevent.a \
		${IMSGDIR}/src/lib/libutil/libimsg.a
.ifdef SSLDIR
LDADD+= 	${SSLDIR}/tls/.libs/libtls.a \
		${SSLDIR}/ssl/.libs/libssl.a \
		${SSLDIR}/crypto/.libs/libcrypto.a
.else
LDADD+= 	/usr/local/lib/libtls.a \
		/usr/local/lib/libssl.a \
		/usr/local/lib/libcrypto.a
.endif

LDADD+= 	-lcrypt -lprocstat -pthread
SRCS+=		patterns.c
MAN+=		patterns.7

DPADD=		${LIBTLS} ${LIBSSL} ${LIBCRYPTO}
#DEBUG=		-g -DDEBUG=3 -O0
CFLAGS+=	-Wall -I${.CURDIR}
CFLAGS+=	-Wstrict-prototypes -Wmissing-prototypes
CFLAGS+=	-Wmissing-declarations
CFLAGS+=	-Wshadow -Wpointer-arith
CFLAGS+=	-Wsign-compare -Wcast-qual
CFLAGS+=	-I${EVENTDIR}/src/lib/libevent \
		-I${IMSGDIR}/src/lib/libutil \
		-I${.CURDIR}/../../include

.ifdef SSLDIR
CFLAGS+=	-I${SSLDIR}/include
.else
CFLAGS+=	-I${LOCALBASE}/include
.endif

CFLAGS+=	-D__dead='' \
		-DHAVE_CONFIG_H
CLEANFILES+=	y.tab.h
YFLAGS=

.include <bsd.prog.mk>
