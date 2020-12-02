/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/pnor/ecc.C $                                          */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2020                        */
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
#ifndef bl_pnor_ecc_C
#include <stdio.h>
#include <endian.h>
#include <assert.h>

#include <pnor/ecc.H>
#endif

namespace PNOR
{
namespace ECC
{
    /** Matrix used for ECC calculation.
     *
     *  Each row of this is the set of data word bits that are used for
     *  the calculation of the corresponding ECC bit.  The parity of the
     *  bitset is the value of the ECC bit.
     *
     *  ie. ECC[n] = eccMatrix[n] & data
     *
     *  Note: To make the math easier (and less shifts in resulting code),
     *        row0 = ECC7.  HW numbering is MSB, order here is LSB.
     *
     *  These values come from the HW design of the ECC algorithm.
     */
    static uint64_t eccMatrix[] = {
        //0000000000000000111010000100001000111100000011111001100111111111
        0x0000e8423c0f99ffULL,
        //0000000011101000010000100011110000001111100110011111111100000000
        0x00e8423c0f99ff00ULL,
        //1110100001000010001111000000111110011001111111110000000000000000
        0xe8423c0f99ff0000ULL,
        //0100001000111100000011111001100111111111000000000000000011101000
        0x423c0f99ff0000e8ULL,
        //0011110000001111100110011111111100000000000000001110100001000010
        0x3c0f99ff0000e842ULL,
        //0000111110011001111111110000000000000000111010000100001000111100
        0x0f99ff0000e8423cULL,
        //1001100111111111000000000000000011101000010000100011110000001111
        0x99ff0000e8423c0fULL,
        //1111111100000000000000001110100001000010001111000000111110011001
        0xff0000e8423c0f99ULL
    };

    /** Syndrome calculation matrix.
     *
     *  Maps syndrome to flipped bit.
     *
     *  To perform ECC correction, this matrix is a look-up of the bit
     *  that is bad based on the binary difference of the good and bad
     *  ECC.  This difference is called the "syndrome".
     *
     *  When a particular bit is on in the data, it cause a column from
     *  eccMatrix being XOR'd into the ECC field.  This column is the
     *  "effect" of each bit.  If a bit is flipped in the data then its
     *  "effect" is missing from the ECC.  You can calculate ECC on unknown
     *  quality data and compare the ECC field between the calculated
     *  value and the stored value.  If the difference is zero, then the
     *  data is clean.  If the difference is non-zero, you look up the
     *  difference in the syndrome table to identify the "effect" that
     *  is missing, which is the bit that is flipped.
     *
     *  Notice that ECC bit flips are recorded by a single "effect"
     *  bit (ie. 0x1, 0x2, 0x4, 0x8 ...) and double bit flips are identified
     *  by the UE status in the table.
     *
     *  Bits are in MSB order.
     */
    static uint8_t syndromeMatrix[] = {
        GD, E7, E6, UE, E5, UE, UE, 47, E4, UE, UE, 37, UE, 35, 39, UE,
        E3, UE, UE, 48, UE, 30, 29, UE, UE, 57, 27, UE, 31, UE, UE, UE,
        E2, UE, UE, 17, UE, 18, 40, UE, UE, 58, 22, UE, 21, UE, UE, UE,
        UE, 16, 49, UE, 19, UE, UE, UE, 23, UE, UE, UE, UE, 20, UE, UE,
        E1, UE, UE, 51, UE, 46,  9, UE, UE, 34, 10, UE, 32, UE, UE, 36,
        UE, 62, 50, UE, 14, UE, UE, UE, 13, UE, UE, UE, UE, UE, UE, UE,
        UE, 61,  8, UE, 41, UE, UE, UE, 11, UE, UE, UE, UE, UE, UE, UE,
        15, UE, UE, UE, UE, UE, UE, UE, UE, UE, 12, UE, UE, UE, UE, UE,
        E0, UE, UE, 55, UE, 45, 43, UE, UE, 56, 38, UE,  1, UE, UE, UE,
        UE, 25, 26, UE,  2, UE, UE, UE, 24, UE, UE, UE, UE, UE, 28, UE,
        UE, 59, 54, UE, 42, UE, UE, 44,  6, UE, UE, UE, UE, UE, UE, UE,
         5, UE, UE, UE, UE, UE, UE, UE, UE, UE, UE, UE, UE, UE, UE, UE,
        UE, 63, 53, UE,  0, UE, UE, UE, 33, UE, UE, UE, UE, UE, UE, UE,
         3, UE, UE, 52, UE, UE, UE, UE, UE, UE, UE, UE, UE, UE, UE, UE,
         7, UE, UE, UE, UE, UE, UE, UE, UE, 60, UE, UE, UE, UE, UE, UE,
        UE, UE, UE, UE,  4, UE, UE, UE, UE, UE, UE, UE, UE, UE, UE, UE,
    };

    /** Create the ECC field corresponding to a 8-byte data field
     *
     *  @param[in] i_data - The 8 byte data to generate ECC for.
     *  @return The 1 byte ECC corresponding to the data.
     */
    uint8_t generateECC(uint64_t i_data)
    {
        uint8_t result = 0;

        for (int i = 0; i < 8; i++)
        {
            result |= __builtin_parityl(eccMatrix[i] & i_data) << i;
        }

        return result;
    }

    /** Verify the data and ECC match or indicate how they are wrong.
     *
     * @param[in] i_data - The data to check ECC on.
     * @param[in] i_ecc - The [supposed] ECC for the data.
     *
     * @return eccBitfield or 0-64.
     *
     * @retval GD - Indicates the data is good (matches ECC).
     * @retval UE - Indicates the data is uncorrectable.
     * @retval all others - Indication of which bit is incorrect.
     */
    uint8_t verifyECC(uint64_t i_data, uint8_t i_ecc)
    {
        return syndromeMatrix[generateECC(i_data) ^ i_ecc];
    }

    /** Correct the data and/or ECC.
     *
     * @param[in,out] io_data - Data to check / correct.
     * @param[in,out] io_ecc - ECC to check / correct.
     *
     * @return eccBitfield or 0-64.
     *
     * @retval GD - Data is good.
     * @retval UE - Data is uncorrectable.
     * @retval all others - which bit was corrected.
     */
    uint8_t correctECC(uint64_t& io_data, uint8_t& io_ecc)
    {
        uint8_t badBit = verifyECC(io_data, io_ecc);

        if ((badBit != GD) && (badBit != UE))  // Good is done, UE is hopeless.
        {
            // Determine if the ECC or data part is bad, do bit flip.
            if (badBit >= E7)
            {
                io_ecc ^= (1 << (badBit - E7));
            }
            else
            {
                io_data ^= (1ul << (63 - badBit));
            }
        }
        return badBit;
    }

#ifndef bl_pnor_ecc_C
    void injectECC(const uint8_t* i_src, size_t i_srcSz,
                   uint8_t* o_dst)
    {
        assert(0 == (i_srcSz % sizeof(uint64_t)));

        for(size_t i = 0, o = 0;
            i < i_srcSz;
            i += sizeof(uint64_t), o += sizeof(uint64_t) + sizeof(uint8_t))
        {
            // Read data word, copy to destination.
            uint64_t data = *reinterpret_cast<const uint64_t*>(&i_src[i]);
            *reinterpret_cast<uint64_t*>(&o_dst[o]) = data;
            data = be64toh(data);

            // Calculate ECC, copy to destination.
            uint8_t ecc = generateECC(data);
            o_dst[o + sizeof(uint64_t)] = ecc;
        }
    }
#endif


#ifndef __HOSTBOOT_MODULE
    eccStatus removeECC(uint8_t* io_src,
                        uint8_t* o_dst,
                        size_t i_dstSz)
    {
#else
    eccStatus removeECC(uint8_t* io_src,
                        uint8_t* o_dst,
                        size_t i_dstSz,
                        eccErrors_t* o_accumulatedErrors)
    {
        if (o_accumulatedErrors != nullptr)
        {
            o_accumulatedErrors->clear();
        }
#endif
        assert(0 == (i_dstSz % sizeof(uint64_t)));

        eccStatus rc = CLEAN;


        for(size_t i = 0, o = 0;
            o < i_dstSz;
            i += sizeof(uint64_t) + sizeof(uint8_t), o += sizeof(uint64_t))
        {
            // Read data and ECC parts.
            uint64_t data = *reinterpret_cast<uint64_t*>(&io_src[i]);
            data = be64toh(data);
            uint8_t ecc = io_src[i + sizeof(uint64_t)];

            // Calculate failing bit and fix data.
            uint8_t badBit = correctECC(data, ecc);

            // Return data to big endian.
            data = htobe64(data);

            // Perform correction and status update.
            if (badBit == UE)
            {
                rc = UNCORRECTABLE;
            }
            else if (badBit != GD)
            {
                if (rc != UNCORRECTABLE)
                {
                    rc = CORRECTED;
                }
                *reinterpret_cast<uint64_t*>(&io_src[i]) = data;
                io_src[i + sizeof(uint64_t)] = ecc;
            }

#ifdef __HOSTBOOT_MODULE
            // If asked to accumulate ECC errors and one occurred
            if ((o_accumulatedErrors != nullptr)
                && (badBit != GD))
            {
                eccErrorLocation_t eccError;
                eccError.offset = i;
                eccError.status = badBit == UE ? UNCORRECTABLE : CORRECTED;

                // Add the ECC error to the list of errors.
                o_accumulatedErrors->push_back(eccError);
            }
#endif

            // Copy fixed data to destination buffer.
            *reinterpret_cast<uint64_t*>(&o_dst[o]) = data;
        }

        return rc;
    }

}
}

