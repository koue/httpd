use strict;
use warnings;

my $regex = $ENV{BLOCKLIST} ? "blocklist dropped" : "dropped";

our %args = (
    client => {
	header => {
		"User-Agent" => "crawlbot"
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
