# FreeBSD port of OpenBSD httpd

The httpd daemon is a HTTP server with FastCGI and TLS support.

http://cvsweb.openbsd.org/src/usr.sbin/httpd/

## Installation

### Requirements
* libressl
* libimsg
* libevent

```
pkg install libressl-devel
git submodule update --init
make
cd src/regress/usr.sbin/httpd/tests/ && make
cd - && make install
```

## Usage

`httpd -f etc/examples/httpd.conf`

## Blocklist

Blocklistd(8) is a daemon that blocks and releases ports on demand. To compile
httpd with blocklistd support use `make -DUSE_BLOCKLIST`. To use blocklistd
along with httpd add `block drop` option in httpd.conf. For example:
```
location "/*.php" {
	block drop
}
```
All requests looking for php files will be dropped by httpd and the IP address
of the client will be send to blocklistd.
