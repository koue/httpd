#	$OpenBSD: Makefile,v 1.4 2017/07/09 21:23:19 espie Exp $
LOCALBASE?=	/usr/local
BINDIR?=	${LOCALBASE}/bin

PROG=		htpasswd
SRCS=		htpasswd.c

.PATH:	${.CURDIR}/../../lib/libc/crypt
SRCS+=	bcrypt.c \
	blowfish.c \
	cryptutil.c

LDADD=		/usr/local/lib/libcrypto.a

DPADD=		${LIBCRYPTO}

CFLAGS+=	-W -Wall
CFLAGS+=	-Wstrict-prototypes -Wmissing-prototypes -Wmissing-declarations
CFLAGS+=	-Wshadow -Wpointer-arith -Wcast-qual -Wsign-compare
CFLAGS+=	-I${.CURDIR}/../../usr.sbin/httpd \
		-I${.CURDIR}/../../include \
		-I${LOCALBASE}/include
CFLAGS+=	-D__dead=''

.include <bsd.prog.mk>
