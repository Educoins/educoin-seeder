CXXFLAGS = -O3 -g0 -march=native
LDFLAGS = $(CXXFLAGS)

dnsseed: dns.o educoin.o netbase.o protocol.o db.o main.o util.o
	g++ -pthread $(LDFLAGS) -o dnsseed dns.o educoin.o netbase.o protocol.o db.o main.o util.o -lcrypto

%.o: %.cpp educoin.h netbase.h protocol.h db.h serialize.h uint256.h util.h educoinnetwork.h
	g++ -std=c++11 -pthread $(CXXFLAGS) -Wall -Wno-unused -Wno-sign-compare -Wno-reorder -Wno-comment -c -o $@ $<

dns.o: dns.c
	gcc -pthread -std=c99 $(CXXFLAGS) dns.c -Wall -c -o dns.o

%.o: %.cpp
