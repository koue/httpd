#	$OpenBSD: Makefile,v 1.30 2017/07/03 22:21:47 espie Exp $

LOCALBASE?=	/usr/local
BINDIR?=	${LOCALBASE}/sbin
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

LDADD=		../../../libevent/src/lib/libevent/libevent.a \
		../../../libimsg/src/lib/libutil/libimsg.a
LDADD+= 	/usr/local/lib/libtls.a \
		/usr/local/lib/libssl.a \
		/usr/local/lib/libcrypto.a
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
CFLAGS+=	-I${.CURDIR}/../../../libevent/src/lib/libevent \
		-I${.CURDIR}/../../../libimsg/src/lib/libutil \
		-I${.CURDIR}/../../include \
		-I${LOCALBASE}/include
CFLAGS+=	-D__dead='' \
		-DHAVE_CONFIG_H
CLEANFILES+=	y.tab.h
YFLAGS=

.include <bsd.prog.mk>
