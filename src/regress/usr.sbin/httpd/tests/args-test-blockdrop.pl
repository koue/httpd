use strict;
use warnings;

# When compiled with USE_BLOCKLIST while running the test a record in
# /var/log/daemon.log should appear:
#
# Jul 18 20:06:02 hostname blocklistd[3647]: processing type=3 fd=5
#     remote=127.0.0.1:13589 msg="abusive behavior" uid=80 gid=80
# Jul 18 20:06:02 hostname blocklistd[3647]: blocked 127.0.0.1/32:36380
#     for 60 seconds

my $regex = $ENV{BLOCKLIST} ? "blocklist dropped" : "dropped";

our %args = (
    client => {
	func => sub {
	    my $self = shift;
	    print "GET /blockdrop HTTP/1.0\r\n\r\n";
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

