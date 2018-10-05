/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/mem/prdfMemRowRepair.H $        */
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

/** @file  prdfMemRowRepair.H */

#ifndef __prdfMemRowRepair_H
#define __prdfMemRowRepair_H

#include <prdfPlatServices.H>

#include <prdfMemAddress.H>
#include <prdfMemSymbol.H>
#include <prdfMemConst.H>
#include <prdfParserEnums.H>

namespace PRDF
{

class CaptureData;
class MemSymbol;

/**
 * @brief Container for DIMM's Row Repair Data.
 */
class MemRowRepair
{
  public: // constructors

    /** @brief Default constructor */
    MemRowRepair()
    {
        memset( iv_data, 0x00, sizeof(iv_data) );
    }

    /** @brief Constructor from components */
    MemRowRepair( TARGETING::TargetHandle_t i_dimm, const MemRank & i_rank,
                 const uint8_t (&i_d)[ROW_REPAIR::ROW_REPAIR_SIZE] ) :
        iv_dimm(i_dimm), iv_rank(i_rank)
    {
        memcpy( iv_data, i_d, sizeof(iv_data) );
    }

  public: // functions

    /** @return A reference to the data array. */
    const uint8_t (&getData()const)[ROW_REPAIR::ROW_REPAIR_SIZE]
    {
        return iv_data;
    }

    /** @return The dram the row repair is on. */
    uint8_t getRowRepairDram()
    {
        // The dram position is located in the first 5 bits of row repair data
        return ( (iv_data[0] >> 3 ) & 0x1f );
    }

    /** @return True or false whether this row repair is valid */
    bool isValid()
    {
        // The last bit of row repair data is the validity bit.
        // 1 if valid. 0 if invalid.
        return ( iv_data[ROW_REPAIR::ROW_REPAIR_SIZE-1] & 0x01 );
    }

    /**
     * @brief  Queries if there are is any row repair data present.
     * @return TRUE if any row repair data present.
     */
    bool nonZero() const;

  private: // instance variables

    TARGETING::TargetHandle_t iv_dimm; ///< Target DIMM
    MemRank iv_rank;                   ///< Target rank

    /** A bitmap of all bad DQs for each port. */
    uint8_t iv_data[ROW_REPAIR::ROW_REPAIR_SIZE];
};

//##############################################################################
//                              Utility Functions
//##############################################################################

/**
 * @brief  Reads the row repair data attribute for the target rank and dimm.
 * @param  i_dimm      A dimm target.
 * @param  i_rank      Target rank.
 * @param  o_rowRepair Row repair data container.
 * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
 */
template<TARGETING::TYPE T>
uint32_t getRowRepairData( TARGETING::TargetHandle_t i_dimm,
    const MemRank & i_rank, MemRowRepair & o_rowRepair );

/**
 * @brief  Writes the row repair data attribute for the target rank and dimm.
 * @param  i_dimm      A dimm target.
 * @param  i_rank      Target rank.
 * @param  i_rowRepair Row repair data container.
 * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
 */
template<TARGETING::TYPE T>
uint32_t setRowRepairData( TARGETING::TargetHandle_t i_dimm,
    const MemRank & i_rank, const MemRowRepair & i_rowRepair );

/**
 * @brief  Writes the row repair data attribute for the target rank and dimm.
 * @param  i_dimm A dimm target.
 * @param  i_rank Target rank.
 * @param  i_addr Address for the row repair.
 * @param  i_dram Dram position for the row repair. NOTE: this is the dram
 *                position relative to the Centaur DQs (x8: 0-9, x4: 0-19)
 * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
 */
template<TARGETING::TYPE T>
uint32_t setRowRepairData( TARGETING::TargetHandle_t i_dimm,
    const MemRank & i_rank, const MemAddr & i_addr, uint8_t i_dram );

/**
 * @brief  Clears the row repair data attribute for the target rank and dimm.
 * @param  i_dimm      A dimm target.
 * @param  i_rank      Target rank.
 * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
 */
template<TARGETING::TYPE T>
uint32_t clearRowRepairData( TARGETING::TargetHandle_t i_dimm,
                             const MemRank & i_rank );

} // end namespace PRDF

#endif // __prdfMemRowRepair_H
