/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/pnor/ecc.H $                                  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2021                        */
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
#ifndef __PNOR_ECC_H
#define __PNOR_ECC_H

#include <stdint.h>

#ifdef __HOSTBOOT_MODULE
#include <vector>
#include <assert.h>
#endif

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


#ifdef __HOSTBOOT_MODULE
    /* A structure for holding the offset into a buffer where an ECC error occurred and the error type */
    typedef struct
    {
        size_t offset;
        eccStatus status;
    } eccErrorLocation_t;

    typedef std::vector<eccErrorLocation_t> eccErrors_t;

    /** Remove ECC from a data stream.
     *
     *  @param[in,out] io_src - Source data+ECC stream.
     *  @param[out]    o_dst - Destination buffer for data only.
     *  @param[in]     i_dstSz - Size in bytes of destination ((srcSz / 9) * 8).
     *  @param[out]    o_accumulatedErrors - Optional; A pointer to an eccErrors_t to accumulate
     *                                       ECC errors as they occur so the caller can handle them.
     *                                       NOTE: offsets will be in terms of ECCed io_src data. If caller wants
     *                                       ECCless offsets then caller must covert the returned offsets.
     *
     *  @note i_dstSz must be a multiple of 8 bytes.
     */
    eccStatus removeECC(uint8_t* io_src,
                        uint8_t* o_dst, size_t i_dstSz,
                        eccErrors_t* o_accumulatedErrors = nullptr);
#else
    /** Remove ECC from a data stream.
     *
     *  @param[in,out] io_src - Source data+ECC stream.
     *  @param[out]    o_dst - Destination buffer for data only.
     *  @param[in]     i_dstSz - Size in bytes of destination ((srcSz / 9) * 8).
     *
     *  @note i_dstSz must be a multiple of 8 bytes.
     */
    eccStatus removeECC(uint8_t* io_src,
                        uint8_t* o_dst, size_t i_dstSz);
#endif




#ifdef __HOSTBOOT_MODULE
    /** Given the size of Data, return the size of Data+ECC
     *
     *  @param[in] i_sizeWithoutEcc Size in bytes of data without ECC
     *
     *  @note i_sizeWithoutEcc must be a multiple of 8 bytes or will assert
     *
     * @return size of data with ECC
     */
    inline size_t sizeWithEcc(const size_t i_sizeWithoutEcc)
    {
        bool noRemainder = (i_sizeWithoutEcc % 8) == 0 ? true : false;
        assert (noRemainder, "PNOR::ECC::sizeWithEcc: input needs to be multiple of 8 bytes");
        return (i_sizeWithoutEcc * 9) / 8;
    }
#endif

}
}

#endif
