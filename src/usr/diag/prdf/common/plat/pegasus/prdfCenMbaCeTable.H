/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/pegasus/prdfCenMbaCeTable.H $   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2014                        */
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

#ifndef __prdfCenMbaCeTable_H
#define __prdfCenMbaCeTable_H

/** @file  prdfCenMbaCeTable.H */

// Framwork includes
#include <iipCaptureData.h>
#include <prdfParserEnums.H>
#include <prdfPlatServices.H>

// Pegasus includes
#include <prdfCenAddress.H>
#include <prdfCenSymbol.H>

// Other includes
#include <list>

namespace PRDF
{

class CenMark;

/**
 * @brief A table of memory CEs.
 * @note  Only one of these tables will exist per MBA.
 * @note  Will be used to determine when to do a TPS procedure for Targeted
 *        Diagnostics at runtime. Will be used for FFDC only during Hostboot.
 */
class CenMbaCeTable
{

  public: // constants, enums

    /** @brief Return values from addEntry(). */
    enum AddEntryRc
    {
        NO_TH_REACHED    = 0x00, ///< No thresholds reached.
        ENTRY_TH_REACHED = 0x01, ///< The entry threshold has been reached.
        RANK_TH_REACHED  = 0x02, ///< The rank threshold has been reached.
        TABLE_FULL       = 0x04, ///< The table is full of active entries.
    };

  private: // constants, enums

    /** @brief Table size limits. */
    enum TableTHs
    {
        TPS_RANK_ENTRY_TH  =   8, ///< Threshold of entries per rank that
                                  ///< triggers a TPS procedure
        TPS_ENTRY_COUNT_TH =  32, ///< Entry count threshold that triggers
                                  ///< a TPS procedure
    };

  public: // functions

    /**
     * @brief Constructor
     * @param i_mbaTrgt An MBA target.
     */
    explicit CenMbaCeTable( TARGETING::TargetHandle_t i_mbaTrgt ) :
        iv_mbaTrgt( i_mbaTrgt )
    {}

    /**
     * @brief  Will attempt to add a new entry to the table.
     *
     * If an entry already exists, the entry's count is incremented. Otherwise,
     * a new entry is created. Will return TRUE if the CE triggers one of the
     * following TPS conditions:
     *   - A single entry reaches count of TPS_ENTRY_COUNT_TH.
     *   - A rank has an entry count of TPS_RANK_ENTRY_TH.
     *   - The table is full.
     *
     * @param  i_addr   The address reporting the CE.
     * @param  i_symbol The symbol reporting the CE.
     * @param  i_isHard TRUE if a hard CE was detected on this address/symbol.
     * @return Mask of possible return codes (see enum AddEntryRc).
     */
    uint32_t addEntry( const CenAddr & i_addr, const CenSymbol & i_symbol,
                       bool i_isHard = false );

    /**
     * @brief Deactivates all entries in the table.
     */
    void deactivateAll();

    /**
     * @brief Deactivates all entries covered by a rank.
     * @param i_rank The target rank.
     */
    void deactivateRank( const CenRank & i_rank );

    /**
     * @brief Iterates the entire table and returns the number of unique entries
     *        that exist for the target DRAM, half-rank, logical DIMM.
     * @param i_rank      The failing rank.
     * @param i_symbol    The failing symbol.
     * @param o_dramCount The entry count for the target dram.
     * @param o_hrCount   The entry count for the target half-rank (per rank
     *                    per port select).
     * @param o_dimmCount The entry count for the target logical DIMM.
     */
    void getMnfgCounts( const CenRank & i_rank, const CenSymbol & i_symbol,
                        uint32_t & o_dramCount, uint32_t & o_hrCount,
                        uint32_t & o_dimmCount );

    /**
     * @brief Gathers all table data to be stored in capture data.
     * @param io_cd      Capture data struct.
     */
    void addCapData( CaptureData & io_cd );

  private: // structs, typedefs

    /** @brief Individual entries of iv_table. */
    struct TableData
    {
        bool    active;              ///< TRUE if this entry is active
        uint8_t count;               ///< Number of times this entry is detected
        CenAddr addr;                ///< Physical address of this entry
        uint8_t dram;                ///< The DRAM in which the CE was detected
        uint8_t dramPins;            ///< The failing pins of the DRAM
        uint8_t portSlct;            ///< The port select of the DRAM
        CEN_SYMBOL::WiringType type; ///< The wiring type
        bool    isHard;              ///< TRUE if a hard CE was detected
        bool    isDramSpared;        ///< TRUE if on spare DRAM
        bool    isEccSpared;         ///< TRUE if on ECC spare

        /** @brief Default constructor. */
        TableData() :
            active(false), count(0), addr(), dram(0), dramPins(0), portSlct(0),
            type(CEN_SYMBOL::WIRING_INVALID), isHard(false),
            isDramSpared(false), isEccSpared(false)
        {}

        /**
         * @brief Constructor from components.
         * @param i_addr     The physical address of this entry.
         * @param i_dram     The DRAM in which the CE was detected
         * @param i_dramPins The failing pins of the DRAM
         * @param i_type     The wiring type (for DRAM site locations).
         */
        TableData( const CenAddr & i_addr, uint8_t i_dram, uint8_t i_dramPins,
                   uint8_t i_portSlct, CEN_SYMBOL::WiringType i_type,
                   bool i_isHard, bool i_isDramSpared, bool i_isEccSpared ) :
            active(true), count(1), addr(i_addr), dram(i_dram),
            dramPins(i_dramPins), portSlct(i_portSlct), type(i_type),
            isHard(i_isHard), isDramSpared(i_isDramSpared),
            isEccSpared(i_isEccSpared)
        {}

        /** An entry is equivalent if the address and DRAM match. */
        bool operator==( const TableData & i_data ) const
        {
            return ( this->addr == i_data.addr && this->dram == i_data.dram );
        }
    };

    typedef std::list<TableData> CeTable;

  private: // instance variables

    /** MBA associated with this table. */
    TARGETING::TargetHandle_t iv_mbaTrgt;

    /** A storage container for memory fetch CE errors. */
    CeTable iv_table;

};

} // end namespace PRDF

#endif // __prdfCenMbaCeTable_H

