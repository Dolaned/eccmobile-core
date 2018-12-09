//
//  BRVersionMessage.h
//
//  Created by Dylan Aird 07/12/2018.
//  Copyright (c) 2015 breadwallet LLC
//
//  Permission is hereby granted, free of charge, to any person obtaining a copy
//  of this software and associated documentation files (the "Software"), to deal
//  in the Software without restriction, including without limitation the rights
//  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//  copies of the Software, and to permit persons to whom the Software is
//  furnished to do so, subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included in
//  all copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
//  THE SOFTWARE.

#ifndef BRVersionMessage_h
#define BRVersionMessage_h

// #include "BRKey.h"
// #include "BRInt.h"
// #include <stddef.h>
// #include <inttypes.h>
#include "uthash.h"
#include "utlist.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum
{
    VERSION                 = 0x0000000000000000UL,
    LOCAL_NODE_SERVICES     = 0x0000000000000001UL,
    TIME                    = 0x0000000000000002UL,
    ADDR_YOU                = 0x0000000000000003UL,
    ADDR_ME                 = 0x0000000000000004UL,
    NONCE                   = 0x0000000000000005UL,
    SUBVERSION              = 0x0000000000000006UL,
    NODE_START_HEIGHT       = 0x0000000000000007UL,
    RELAY_TXES              = 0x0000000000000008UL,
} VersionMsgCode;


typedef struct 
{
	VersionMessage *key
	UT_array *data
	UT_hash_handle hh
	
} VersionMessage;








void read();

void write();


const size_t MAX_VERSION_MAP_SIZE = 100000;




