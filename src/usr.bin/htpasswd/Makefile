#	$OpenBSD: Makefile,v 1.4 2017/07/09 21:23:19 espie Exp $
LOCALBASE?=	/usr/local
BINDIR?=	${LOCALBASE}/bin

PROG=		htpasswd
SRCS=		htpasswd.c

.PATH:	${.CURDIR}/../../lib/libc/crypt
SRCS+=	bcrypt.c \
	blowfish.c \
	cryptutil.c

.ifdef SSLDIR
LDADD=		${SSLDIR}/crypto/.libs/libcrypto.a
.else
LDADD=		/usr/local/lib/libcrypto.a
.endif

DPADD=		${LIBCRYPTO}

CFLAGS+=	-W -Wall
CFLAGS+=	-Wstrict-prototypes -Wmissing-prototypes -Wmissing-declarations
CFLAGS+=	-Wshadow -Wpointer-arith -Wcast-qual -Wsign-compare
CFLAGS+=	-I${.CURDIR}/../../usr.sbin/httpd \
		-I${.CURDIR}/../../include
.ifdef SSLDIR
CFLAGS+= 	-I${SSLDIR}/include
.else
CFLAGS+=	-I${LOCALBASE}/include
.endif

CFLAGS+=	-D__dead=''

.include <bsd.prog.mk>
