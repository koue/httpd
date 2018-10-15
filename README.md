# FreeBSD port of OpenBSD httpd

The httpd daemon is a HTTP server with FastCGI and TLS support.

http://cvsweb.openbsd.org/cgi-bin/cvsweb/src/usr.sbin/httpd/

## Installation

### Requirements
* libressl

`cd src/ && make && make install`

## Usage

`httpd -f etc/examples/httpd.conf`

## Status

master | develop
-------|--------
[![Build Status](https://cipier.net/status/koue/httpd/master)](https://cipier.net/status/koue/httpd/master) | [![Build Status](https://cipier.net/status/koue/httpd/develop)](https://cipier.net/status/koue/httpd/develop)
