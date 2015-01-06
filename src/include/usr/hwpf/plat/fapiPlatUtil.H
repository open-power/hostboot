/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/hwpf/plat/fapiPlatUtil.H $                    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2015                        */
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
/**
 *  @file fapiPlatUtil.H
 *
 *  @brief Defines miscellaneous utility functions for the platform layer.
 *         Hardware procedure writers will not call these functions.
 *
 */

/*
 * Change Log ******************************************************************
 * Flag     Defect/Feature  User        Date        Description
 * ------   --------------  ----------  ----------- ----------------------------
 *                          whs         11/14/2012  new
 */

#ifndef FAPIPLATUTIL_H_
#define FAPIPLATUTIL_H_

#include <endian.h>
#include <stdlib.h>
#include <util/crc32.H>

#define FAPI_PLAT_GEN_HASH(type, data, size) fapiPlatGenHash<type>(data,size)

template <uint32_t T> uint32_t fapiPlatGenHash
                     (const void* i_data, size_t i_size);

template <> inline uint32_t fapiPlatGenHash <fapi::hash::CRC32>
            (const void* i_data, size_t i_size)
{
    return Util::crc32_calc(i_data, i_size);
}


// defines for endian conversion
#define FAPI_PLAT_BE16TOH(x) be16toh(x)
#define FAPI_PLAT_LE16TOH(x) le16toh(x)
#define FAPI_PLAT_HTOBE16(x) htobe16(x)
#define FAPI_PLAT_HTOLE16(x) htole16(x)

#define FAPI_PLAT_BE32TOH(x) be32toh(x)
#define FAPI_PLAT_LE32TOH(x) le32toh(x)
#define FAPI_PLAT_HTOBE32(x) htobe32(x)
#define FAPI_PLAT_HTOLE32(x) htole32(x)

#define FAPI_PLAT_BE64TOH(x) be64toh(x)
#define FAPI_PLAT_LE64TOH(x) le64toh(x)
#define FAPI_PLAT_HTOBE64(x) htobe64(x)
#define FAPI_PLAT_HTOLE64(x) htole64(x)

#define fapiPlatMalloc(s) malloc(s)
#define fapiPlatFree(p) free(p)

#endif // FAPIPLATUTIL_H_
