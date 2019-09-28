// Copyright (c) 2019 The EduCoin developers
#ifndef _EDUCOIN_H_
#define _EDUCOIN_H_ 1

#include "protocol.h"

bool TestNode(const CService &cip, int &ban, int &client, std::string &clientSV, int &blocks, std::vector<CAddress>* vAddr);

#endif
