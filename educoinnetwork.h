// Copyright (c) 2018 The Bitcoin developers
// Copyright (c) 2019 The EduCoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file license.txt or http://www.opensource.org/licenses/mit-license.php.

#ifndef __INCLUDED_EDUCOINNETWORK_H__
#define __INCLUDED_EDUCOINNETWORK_H__

#include <string>

static const std::string mainnet_seeds[] = {"mainnet-seed.educoin.tools",
											"mainnet-seed2.educoin.tools",
											""};

static const std::string testnet_seeds[] = {"testnet-seed.educoin.tools",
											""};
											
static const int mainnet_port = 17389;
static const int testnet_port = 22525;

static unsigned char pchMessageStart[4] = { 0xfe, 0xf2, 0xef, 0xb4 };
static unsigned char pchMessageStart_testnet[4] = { 0x07, 0x11, 0x05, 0x0b };

#define REQUIRE_VERSION 80016
static const int minimunClientVersion = 1010000;
static const int PROTOCOL_VERSION = 80017;
static const int INIT_PROTO_VERSION = 80016;
#endif // __INCLUDED_EDUCOINNETWORK_H__