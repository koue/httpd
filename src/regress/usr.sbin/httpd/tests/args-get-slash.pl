use strict;
use warnings;

# FreeBSD: verify BLOCK_400
my $regex = $ENV{BLOCK400} ? "blocklist400 dropped" : '"GET /" 400 0';

our %args = (
    client => {
	func => sub {
	    my $self = shift;
	    print "GET /\r\n\r\n";
	},
	nocheck => 1
    },
    httpd => {
	loggrep => {
	    qr/$regex/ => 1,
	},
    },
);

1;

