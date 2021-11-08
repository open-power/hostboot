/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/plat/mem/mds/prdfMemMdsMediaLogCounts.H $   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2021                             */
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
#ifndef __prdfMemMdsMediaLogCounts_H
#define __prdfMemMdsMediaLogCounts_H

#include <prdfMemRank.H>
#include <map>

namespace PRDF
{

namespace MDS
{

//------------------------------------------------------------------------------
//  Class MediaLogCounts
//------------------------------------------------------------------------------

/** @brief Used to store error count information collected from an MDS media
 *         controller's media error logs.
 */
class MediaLogCounts
{
  public:

    /** @brief Default constructor */
    explicit MediaLogCounts( ExtensibleChip * i_ocmb ): iv_ocmb(i_ocmb) {}

    /**
     * @brief  A function to update the error counts stored in iv_errMap based
     *         on the input rank and the associated OCMB.
     * @param  i_rank The input MemRank associated with the media error logs to
     *                be read.
     * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
     */
    uint32_t updateCounts( const MemRank & i_rank );

    /**
     * @brief  A function to check if the error count on any primary rank has
     *         hit the input threshold. A boolean indicating whether some
     *         primary rank has hit threshold will be returned along with
     *         the number of the primary rank that hit threshold.
     * @param  o_prank The primary rank that has hit threshold. Will
     *                 return 0xFF if no rank has hit threshold.
     * @param  i_th    The threshold of errors on a particular primary rank.
     *                 Will default to 8.
     * @return True if some primary rank has hit threshold, else false.
     */
    bool checkPrankCount( uint8_t & o_prank, uint8_t i_th = 8 );

    /**
     * @brief  A function to check if a primary rank that has hit threshold
     *         can be classified as a single bad secondary rank by checking
     *         if a single secondary rank has hit threshold with the other
     *         secondary ranks having an error count of only 1 or less.
     * @param  i_prank The primary rank that has hit threshold.
     * @param  o_srank The secondary rank that can be blamed. Will return 0xFF
     *                 if no particular secondary rank can be blamed.
     * @param  i_th    The threshold of errors on a particular secondary rank.
     *                 Will default to 8.
     * @return True if some secondary rank can be blamed as bad, else false.
     */
    bool checkSrankCount(uint8_t i_prank, uint8_t & o_srank, uint8_t i_th = 8);

    /**
     * @brief  A function to capture the FFDC data from this class.
     * @param  io_sc The step code data struct
     */
    void captureMediaLogCounts( STEP_CODE_DATA_STRUCT & io_sc );

  private:

    /** @brief A struct for defining the error counts that need to be stored.*/
    struct ErrorCounts
    {
        uint16_t ueCount = 0;
        uint16_t nonUeCount = 0;
    };

    /** @brief A map from the primary and secondary ranks to the err counts. */
    std::map<uint8_t, std::map<uint8_t, ErrorCounts>> iv_errMap;

    /** @brief The relevant OCMB chip. */
    ExtensibleChip * iv_ocmb;
};

} //end namespace MDS

} //end namespace PRDF

#endif
