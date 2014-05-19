/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plugins/prdfDramRepairUsrData.H $    */
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

#ifndef PRDF_DRAM_REPAIR_DATA_H
#define PRDF_DRAM_REPAIR_DATA_H
/**
 * @file  prdfDramRepairUsrData.H
 * @brief ffdc data from dram repairs
 */

#include <stdint.h>
#include <utilstream.H>
#include <prdfCenConst.H>
#include <vector>

namespace PRDF
{
#ifdef PRDF_HOSTBOOT_ERRL_PLUGIN
namespace HOSTBOOT
{
#endif

#ifdef PRDF_FSP_ERRL_PLUGIN
namespace FSP
{
#endif

/* @brief Represent the header information for DRAM Repair data of a MBA
 */
struct DramRepairDataHdr
{
    uint8_t rankCount   : 4; // Number of ranks with DRAM Repair data
    uint8_t isX4Dram    : 1; // Is this mba connected in x4 mode
    uint8_t isSpareDram : 1; // Is spare DRAM supported on DIMMS attached
                             // to this MBA.
    uint8_t reserved    : 2; // Future use
    uint8_t wiringType;     // Future use. In case we need to display the DRAM
                            // site location instead symbols (TBD).

    /**
     * @brief append DramRepairDataHdr to UtilStream buffer
     * @param i_left UtilStream object
     * @param i_right DRAM Repair Header data object
     * @param Upddated Utilstream object
     */
    friend UtilStream& operator<<( UtilStream& i_left,
                                   DramRepairDataHdr& i_right )
    {
        i_left << ( uint8_t )(i_right.rankCount << 4
                   | i_right.isX4Dram << 3
                   | i_right.isSpareDram << 2
                   | i_right.reserved )
               << i_right.wiringType;
        return i_left;
    }

    /**
     * @brief Retrieve DramRepairDataHdr from UtilStream buffer
     * @param i_left UtilStream object
     * @param i_right DRAM Repair Header Data object
     * @param Upddated Utilstream object
     */
    friend UtilStream& operator>>( UtilStream& i_left,
                                   DramRepairDataHdr& i_right)
    {
        uint8_t temp = 0;
        i_left >> temp >> i_right.wiringType;

        i_right.rankCount = temp >> 4;
        i_right.isX4Dram = temp >> 3;
        i_right.isSpareDram = temp >> 2;
        i_right.reserved = temp;

        return i_left;
    }

};

/* @brief Represent the header information for DRAM Repair data of a rank
 */
struct DramRepairRankData
{
    uint8_t rank;   //rank number
    uint8_t chipMark;
    uint8_t symbolMark;
    uint8_t port0Spare;
    uint8_t port1Spare;
    uint8_t eccSpare;

    /**
     * @brief Check if object has some valid symbols
     *        Underlying HWP return 0xff if it cant find any DRAM symbol.
     */
    bool valid()
    {
        return ( ( SYMBOLS_PER_RANK > chipMark )
                  || ( SYMBOLS_PER_RANK > symbolMark )
                  || ( SYMBOLS_PER_RANK > port0Spare )
                  || ( SYMBOLS_PER_RANK > port1Spare )
                  || ( SYMBOLS_PER_RANK > eccSpare) );
    };

    /**
     * @brief append DramRepairRankData to UtilStream buffer
     * @param i_left UtilStream object
     * @param i_right DRAM Repair rank data object
     * @return Upddated Utilstream object
     */
    friend UtilStream& operator<<( UtilStream& i_left,
                                   DramRepairRankData& i_right )
    {
        i_left << i_right.rank << i_right.chipMark << i_right.symbolMark
               << i_right.port0Spare << i_right.port1Spare << i_right.eccSpare;
        return i_left;
    }

    /**
     * @brief Retrieve DramRepairRankData from UtilStream buffer
     * @param i_left UtilStream object
     * @param i_right DRAM Repair rank data object
     * @return Upddated Utilstream object
     */
    friend UtilStream& operator>>( UtilStream& i_left,
                                   DramRepairRankData& i_right)
    {
        i_left >> i_right.rank >> i_right.chipMark >> i_right.symbolMark
               >> i_right.port0Spare >> i_right.port1Spare >> i_right.eccSpare;
        return i_left;
    }
};

/** @brief Represent DRAM Repair data of a MBA
 */
struct DramRepairMbaData
{
    DramRepairDataHdr header;
    std::vector<DramRepairRankData> rankDataList;

    /**
     * @brief append DramRepairMbaData to UtilStream buffer
     * @param i_left UtilStream object
     * @param i_right DRAM Repair Mba data object
     * @return Upddated Utilstream object
     */
    friend UtilStream& operator<<( UtilStream& i_left,
                                   DramRepairMbaData& i_right )
    {
        i_left << i_right.header;

        for(int index = 0; index < i_right.header.rankCount; index++)
        {
            i_left << i_right.rankDataList[index];
        }
        return i_left;
    }

    /**
     * @brief Retrieve DramRepairMbaData from UtilStream buffer
     * @param i_left UtilStream object
     * @param i_right DRAM Repair rank data object
     * @return Upddated Utilstream object
     */
    friend UtilStream& operator>>( UtilStream& i_left,
                                   DramRepairMbaData& i_right)
    {
        //Retrieve Header
        i_left >> i_right.header;

        // Traverse the number of enteries as defined in header
        for(int index = 0; index < i_right.header.rankCount; index++)
        {
            DramRepairRankData rankData;
            i_left >> rankData;
            i_right.rankDataList.push_back(rankData);
        }
        return i_left;
    }
};

#ifdef PRDF_HOSTBOOT_ERRL_PLUGIN
} // end namespace HOSTBOOT
#endif

#ifdef PRDF_FSP_ERRL_PLUGIN
} // end namespace FSP
#endif
} // end namespace PRDF

#endif // end PRDF_DRAM_REPAIR_DATA_H
