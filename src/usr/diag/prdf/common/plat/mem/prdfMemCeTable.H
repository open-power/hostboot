/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/mem/prdfMemCeTable.H $          */
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

#ifndef __prdfMemCeTable_H
#define __prdfMemCeTable_H

/** @file  prdfMemCeTable.H */

// Framwork includes
#include <iipCaptureData.h>
#include <prdfExtensibleChip.H>

// Pegasus includes
#include <prdfMemAddress.H>
#include <prdfMemSymbol.H>
#include <prdfParserEnums.H>

// Other includes
#include <list>

namespace PRDF
{

/**
 * @brief A table of memory CEs.
 * @note  Only one of these tables will exist per OCMB.
 * @note  Will be used to determine when to do a TPS procedure for Targeted
 *        Diagnostics at runtime. Will be used for FFDC only during Hostboot.
 */
template <TARGETING::TYPE T>
class MemCeTable
{

  public: // constants, enums

    /** @brief Return values from addEntry(). */
    enum AddEntryRc
    {
        NO_TH_REACHED    = 0x00, ///< No thresholds reached.
        ENTRY_TH_REACHED = 0x01, ///< The entry threshold has been reached.
        RANK_TH_REACHED  = 0x02, ///< The rank threshold has been reached.
        TABLE_FULL       = 0x04, ///< The table is full of active entries.
        MNFG_TH_DRAM     = 0x08, ///< MNFG DRAM threshold reached.
        MNFG_TH_RANK     = 0x10, ///< MNFG rank threshold reached.
        MNFG_TH_DIMM     = 0x20, ///< MNFG DIMM threshold reached.

        FIELD_TH_ALL     = ENTRY_TH_REACHED | RANK_TH_REACHED | TABLE_FULL,
        MNFG_TH_ALL      = MNFG_TH_DRAM     | MNFG_TH_RANK    | MNFG_TH_DIMM,
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
     * @brief Constructor.
     * @param i_chip OCMB associated with this data.
     */
    explicit MemCeTable( ExtensibleChip * i_chip ) :
        iv_chip( i_chip )
    {
        PRDF_ASSERT( T == iv_chip->getType() );
    }

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
    uint32_t addEntry( const MemAddr & i_addr, const MemSymbol & i_symbol,
                       bool i_isHard = false );

    /**
     * @brief Deactivates all entries covered by a rank.
     * @param i_rank The target rank.
     * @param i_type See enum AddrRangeType.
     */
    void deactivateRank( const MemRank & i_rank, AddrRangeType i_type );

    /**
     * @brief Gathers all table data to be stored in capture data.
     * @param io_cd  Capture data struct.
     */
    void addCapData( CaptureData & io_cd );

  private: // structs, typedefs

    /** @brief Individual entries of iv_table. */
    struct TableData
    {
        bool    active;              ///< TRUE if this entry is active
        uint8_t count;               ///< Number of times this entry is detected
        MemAddr addr;                ///< Physical address of this entry
        uint8_t dram;                ///< The DRAM in which the CE was detected
        uint8_t dramPins;            ///< The failing pins of the DRAM
        uint8_t portSlct;            ///< The port select of the DRAM (MBA only)
        bool    isHard;              ///< TRUE if a hard CE was detected
        bool    isDramSpared;        ///< TRUE if on spare DRAM

        /** @brief Default constructor. */
        TableData() :
            active(false), count(0), addr(), dram(0), dramPins(0), portSlct(0),
            isHard(false), isDramSpared(false)
        {}

        /**
         * @brief Constructor from components.
         * @param i_addr     The physical address of this entry.
         * @param i_dram     The DRAM in which the CE was detected
         * @param i_dramPins The failing pins of the DRAM
         * @param i_type     The wiring type (for DRAM site locations).
         */
        TableData( const MemAddr & i_addr, uint8_t i_dram, uint8_t i_dramPins,
                   uint8_t i_portSlct, bool i_isHard, bool i_isDramSpared ) :
            active(true), count(1), addr(i_addr), dram(i_dram),
            dramPins(i_dramPins), portSlct(i_portSlct), isHard(i_isHard),
            isDramSpared(i_isDramSpared)
        {}

        /** An entry is equivalent if the address and DRAM match. */
        bool operator==( const TableData & i_data ) const
        {
            return ( this->addr == i_data.addr && this->dram == i_data.dram );
        }
    };

    typedef std::list<TableData> CeTable;

  private: // instance variables

    ExtensibleChip * iv_chip; ///< OCMB associated with this data.

    /** A storage container for memory fetch CE errors. */
    CeTable iv_table;

};

} // end namespace PRDF

#endif // __prdfMemCeTable_H

