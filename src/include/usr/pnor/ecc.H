/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/pnor/ecc.H $                                  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013,2014              */
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
#ifndef __PNOR_ECC_H
#define __PNOR_ECC_H

#include <stdint.h>

/** @file ecc.H
 *  @brief Interfaces for the P8 8-byte ECC algorithm.
 */

namespace PNOR
{
namespace ECC
{
    /** Status for the ECC removal function. */
    enum eccStatus
    {
        CLEAN,          //< No ECC Error was detected.
        CORRECTED,      //< ECC error detected and corrected.
        UNCORRECTABLE   //< ECC error detected and uncorrectable.
    };

    /** Bit field identifiers for syndrome calculations. */
    enum eccBitfields
    {
        GD = 0xff,      //< Good, ECC matches.
        UE = 0xfe,      //< Uncorrectable.
        E0 = 71,        //< Error in ECC bit 0
        E1 = 70,        //< Error in ECC bit 1
        E2 = 69,        //< Error in ECC bit 2
        E3 = 68,        //< Error in ECC bit 3
        E4 = 67,        //< Error in ECC bit 4
        E5 = 66,        //< Error in ECC bit 5
        E6 = 65,        //< Error in ECC bit 6
        E7 = 64         //< Error in ECC bit 7
    };

    /** Inject ECC into a data stream.
     *
     *  @param[in] i_src - Source data to create ECC on.
     *  @param[in] i_srcSz - Size in bytes of source data.
     *  @param[out] o_dst - Destination buffer of data+ECC.
     *
     *  @note i_srcSz must be a multiple of 8 bytes.
     */
    void injectECC(const uint8_t* i_src, size_t i_srcSz,
                   uint8_t* o_dst);

    /** Remove ECC from a data stream.
     *
     *  @param[in,out] io_src - Source data+ECC stream.
     *  @param[out] o_dst - Destination buffer for data only.
     *  @param[in] i_dstSz - Size in bytes of destination ((srcSz / 9) * 8).
     *
     *  @note i_dstSz must be a multiple of 8 bytes.
     */
    eccStatus removeECC(uint8_t* io_src,
                        uint8_t* o_dst, size_t i_dstSz);

}
}

#endif
