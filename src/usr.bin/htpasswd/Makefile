#	$OpenBSD: Makefile,v 1.1 2014/03/17 12:49:13 florian Exp $
LOCALBASE?=	/usr/local
PROG=		htpasswd
SRCS=		htpasswd.c
MAN=		htpasswd.1

.PATH:	${.CURDIR}/../../lib/libc/crypt
SRCS+=	bcrypt.c \
	blowfish.c \
	cryptutil.c

.PATH:	${.CURDIR}/../../lib/libc/string
SRCS+=	timingsafe_bcmp.c

LDADD=		-lcrypto

DPADD=		${LIBCRYPTO}

CFLAGS+=	-g -W -Wall
CFLAGS+=	-Wstrict-prototypes -Wmissing-prototypes -Wmissing-declarations
CFLAGS+=	-Wshadow -Wpointer-arith -Wcast-qual -Wsign-compare
CFLAGS+=	-I${.CURDIR}/../../usr.sbin/httpd \
		-I${.CURDIR}/../../include \
		-I ${LOCALBASE}/include \
		-L ${LOCALBASE}/lib
CFLAGS+=	-D__dead=''

.include <bsd.prog.mk>
