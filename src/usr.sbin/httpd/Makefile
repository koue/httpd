#	$OpenBSD: Makefile,v 1.32 2026/06/04 05:34:53 deraadt Exp $

LOCALBASE?=	/usr/local
BINDIR?=	${LOCALBASE}/sbin
EVENTDIR?=	${.CURDIR}/../../../libevent
IMSGDIR?=	${.CURDIR}/../../../libimsg

PROG=		httpd
RELINK=		"./${PROG} -n -f /etc/examples/httpd.conf 2> /dev/null"
SRCS=		parse.y
SRCS+=		config.c control.c httpd.c log.c logger.c proc.c server.c
SRCS+=		server_http.c server_file.c server_fcgi.c
.ifdef USE_BLACKLIST
SRCS+=		blacklist.c
.endif


.PATH: ${.CURDIR}/../../lib/libc/gen
SRCS+=	vis.c

.PATH:	${.CURDIR}/../../lib/libc/crypt
SRCS+=	bcrypt.c \
	cryptutil.c

.PATH:	${.CURDIR}/../../lib/libutil
SRCS+=	fmt_scaled.c

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
.ifdef USE_BLACKLIST
LDADD+= 	-lblacklist
.endif
SRCS+=		patterns.c
MAN+=		patterns.7

DPADD=		${LIBTLS} ${LIBSSL} ${LIBCRYPTO}
#DEBUG=		-g -DDEBUG=3 -O0
CFLAGS+=	-Wall -I${.CURDIR} -I${.OBJDIR}
CFLAGS+=	-Wstrict-prototypes -Wmissing-prototypes
CFLAGS+=	-Wmissing-declarations
CFLAGS+=	-Wshadow -Wpointer-arith
CFLAGS+=	-Wsign-compare -Wcast-qual
CFLAGS+=	-I${EVENTDIR}/src/lib/libevent \
		-I${IMSGDIR}/src/lib/libutil \
		-I${.CURDIR}/../../include \
		-I${.CURDIR}/../../lib/libutil

.ifdef SSLDIR
CFLAGS+=	-I${SSLDIR}/include
.else
CFLAGS+=	-I${LOCALBASE}/include
.endif

.ifdef USE_BLACKLIST
CFLAGS+= 	-DUSE_BLACKLIST
.endif

CFLAGS+=	-D__dead='' \
		-DHAVE_CONFIG_H
CLEANFILES+=	y.tab.h
YFLAGS=

.for h in css.h js.h
$h: $h.in
	sed -f ${.CURDIR}/toheader.sed <${.CURDIR}/$h.in >$@.tmp && mv $@.tmp $@
.endfor

server_file.o: css.h js.h
server_file.pieo: css.h js.h

CLEANFILES += css.h js.h

.include <bsd.prog.mk>
