EduCoin Seeder
==============

EduCoin-seeder is a crawler for the EDU network, based on [bitcoin-seeder](https://github.com/sipa/bitcoin-seeder),  which exposes a list
of reliable nodes via a built-in DNS server.

Features:
* regularly revisits known nodes to check their availability
* bans nodes after enough failures, or bad behaviour
* accepts nodes down to protocol version 80016 to request new IP addresses from,
  but only reports good (80017) nodes.
* keeps statistics over (exponential) windows of 2 hours, 8 hours,
  1 day and 1 week, to base decisions on.
* very low memory (a few tens of megabytes) and cpu requirements.
* crawlers run in parallel (by default 24 threads simultaneously).

REQUIREMENTS
------------

$ sudo apt-get install build-essential libboost-all-dev libssl-dev

USAGE
-----

Assuming you want to run a dns seed on dnsseed.example.com, you will
need an authorative NS record in example.com's domain record, pointing
to for example vps.example.com:

$ dig -t NS dnsseed.example.com

;; ANSWER SECTION
dnsseed.example.com.   86400    IN      NS     vps.example.com.

On the system vps.example.com, you can now run dnsseed:

./dnsseed -h dnsseed.example.com -n vps.example.com

If you want the DNS server to report SOA records, please provide an
e-mail address (with the @ part replaced by .) using -m.

COMPILING
---------
Compiling will require boost and ssl.  On debian systems, these are provided
by `libboost-dev` and `libssl-dev` respectively.

$ make

This will produce the `dnsseed` binary.


RUNNING AS NON-ROOT
-------------------

Typically, you'll need root privileges to listen to port 53 (name service).

One solution is using an iptables rule (Linux only) to redirect it to
a non-privileged port:

$ iptables -t nat -A PREROUTING -p udp --dport 53 -j REDIRECT --to-port 5353

If properly configured, this will allow you to run dnsseed in userspace, using
the -p 5353 option.

Alternatively, you can use the CAP_NET_BIND_SERVICE capability on Linux kernel
versions greater than 2.2.
versions greater than 2.6.24.

$ setcap 'cap_net_bind_service=+ep' /path/to/dnsseed

`setcap` usually comes pre-installed on most modern distributions, but is 
available in the `libcap2-bin` package on debian and libcap2 on RedHat.