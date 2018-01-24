#	$OpenBSD: Makefile,v 1.30 2017/07/03 22:21:47 espie Exp $

LOCALBASE?=	/usr/local
PROG=		httpd
SRCS=		parse.y
SRCS+=		config.c control.c httpd.c log.c logger.c proc.c getdtablecount.c
SRCS+=		server.c server_http.c server_file.c server_fcgi.c

.PATH: ${.CURDIR}/../../lib/libc/stdlib
SRCS+=	reallocarray.c \
	recallocarray.c

.PATH: ${.CURDIR}/../../lib/libc/asr
SRCS+=	asr.c

.PATH: ${.CURDIR}/../../lib/libc/gen
SRCS+=	vis.c

.PATH:	${.CURDIR}/../../lib/libc/crypt
SRCS+=	bcrypt.c \
	cryptutil.c

.PATH:	${.CURDIR}/../../lib/libutil
SRCS+=	imsg-buffer.c \
	imsg.c

.PATH:  ${.CURDIR}/../../lib/libevent
SRCS+=  buffer.c \
        evbuffer.c \
        event.c \
        evlog.c \
        evutil.c \
        kqueue.c \
        poll.c \
        select.c \
        signal.c

MAN=		httpd.8 httpd.conf.5

LDADD=		${LIBEVENT} -ltls -lssl -lcrypto -lutil -lcrypt -lprocstat
SRCS+=		patterns.c
MAN+=		patterns.7

DPADD=		${LIBEVENT} ${LIBTLS} ${LIBSSL} ${LIBCRYPTO} ${LIBUTIL}
#DEBUG=		-g -DDEBUG=3 -O0
CFLAGS+=	-Wall -I${.CURDIR}
CFLAGS+=	-Wstrict-prototypes -Wmissing-prototypes
CFLAGS+=	-Wmissing-declarations
CFLAGS+=	-Wshadow -Wpointer-arith
CFLAGS+=	-Wsign-compare -Wcast-qual
CFLAGS+=	-I${.CURDIR}/../../lib/libevent \
		-I${.CURDIR}/../../lib/libutil \
		-I${.CURDIR}/../../include \
		-I ${LOCALBASE}/include
CFLAGS+=	-D__dead='' \
		-DHAVE_CONFIG_H
LDFLAGS+=	-L ${LOCALBASE}/lib
CLEANFILES+=	y.tab.h
YFLAGS=

.include <bsd.prog.mk>
