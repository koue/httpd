#	$OpenBSD: Makefile,v 1.29 2016/09/28 12:02:17 reyk Exp $

LOCALBASE?=	/usr/local
PROG=		httpd
SRCS=		parse.y
SRCS+=		config.c control.c httpd.c log.c logger.c proc.c getdtablecount.c
SRCS+=		server.c server_http.c server_file.c server_fcgi.c

.PATH: ${.CURDIR}/../../lib/libc/gen
SRCS+=	vis.c

.PATH:	${.CURDIR}/../../lib/libc/crypt
SRCS+=	bcrypt.c \
	cryptutil.c

.PATH:	${.CURDIR}/../../lib/libtls
SRCS+=	tls.c \
	tls_bio_cb.c \
	tls_client.c \
	tls_config.c \
	tls_conninfo.c \
	tls_peer.c \
	tls_server.c \
	tls_util.c \
	tls_verify.c \
	tls_ocsp.c


.PATH:	${.CURDIR}/../../lib/libutil
SRCS+=	imsg-buffer.c \
	imsg.c

.PATH:	${.CURDIR}/../../lib/libcrypto/asn1
SRCS+=	a_time_tm.c

.PATH:  ${.CURDIR}/../../../libevent
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

LDADD=		${LIBEVENT} ${LIBTLS} -lssl -lcrypto -lutil -lcrypt -lprocstat
SRCS+=		patterns.c
MAN+=		patterns.7

DPADD=		${LIBEVENT} ${LIBTLS} ${LIBSSL} ${LIBCRYPTO} ${LIBUTIL}
#DEBUG=		-g -DDEBUG=3 -O0
CFLAGS+=	-Wall -I${.CURDIR}
CFLAGS+=	-Wstrict-prototypes -Wmissing-prototypes
CFLAGS+=	-Wmissing-declarations
CFLAGS+=	-Wshadow -Wpointer-arith
CFLAGS+=	-Wsign-compare -Wcast-qual
CFLAGS+=	-I${.CURDIR}/../../../libevent \
		-I${.CURDIR}/../../lib/libutil \
		-I${.CURDIR}/../../lib/libtls \
		-I${.CURDIR}/../../include \
		-L ${LOCALBASE}/lib \
		-I ${LOCALBASE}/include
CFLAGS+=	-D__dead='' \
		-DHAVE_CONFIG_H
CLEANFILES+=	y.tab.h

.include <bsd.prog.mk>
