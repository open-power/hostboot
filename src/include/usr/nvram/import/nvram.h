/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/nvram/import/nvram.h $                        */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018                             */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* Licensed under the Apache License, Version 2.0 (the "License");        */
/* you may not use this file except in compliance with the License.       */
/* You may obtain a copy of the License at                                */
/*                                                                        */
/*     http://www.apache.org/licenses/LICENSE-2.0                         */
/*                                                                        */
/* Unless required by applicable law or agreed to in writing, software    */
/* distributed under the License is distributed on an "AS IS" BASIS,      */
/* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or        */
/* implied. See the License for the specific language governing           */
/* permissions and limitations under the License.                         */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
#ifndef __NVRAM_H
#define __NVRAM_H

#include <stdint.h>

typedef uint16_t beint16_t;
typedef beint16_t be16;

struct chrp_nvram_hdr {
    uint8_t     sig;
    uint8_t     cksum;
    be16        len;
    char        name[12];
};

extern "C"
{
int nvram_format(void *nvram_image, uint32_t nvram_size);
int nvram_check(void *nvram_image, uint32_t nvram_size);
void nvram_reinit(void);
bool nvram_validate(void);
bool nvram_has_loaded(void);
bool nvram_wait_for_load(void);

const char *nvram_query(const char *name);
bool nvram_query_eq(const char *key, const char *value);
}
#endif /* __NVRAM_H */
