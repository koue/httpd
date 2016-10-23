# FreeBSD port of OpenBSD httpd

- OpenBSD branch is cvs copy
- https://github.com/koue/scripts/blob/master/OpenBSD/cvs_checkout_httpd.sh

## Installation

cd httpd/src/ && make

## Usage

httpd -f /etc/httpd.conf <br />
<br />
Note: Don't forget to specify the chroot directory in the config file
