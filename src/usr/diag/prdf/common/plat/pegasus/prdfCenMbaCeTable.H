/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/pegasus/prdfCenMbaCeTable.H $   */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013                   */
/*                                                                        */
/* p1                                                                     */
/*                                                                        */
/* Object Code Only (OCO) source materials                                */
/* Licensed Internal Code Source Materials                                */
/* IBM HostBoot Licensed Internal Code                                    */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* Origin: 30                                                             */
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
     * @return TRUE if TPS is required, FALSE otherwise.
     */
    bool addEntry( const CenAddr & i_addr, const CenSymbol & i_symbol );

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
     * @param i_mbaTrgt  An MBA target.
     * @param io_cd      Capture data struct.
     */
    void addCapData( TARGETING::TargetHandle_t i_mbaTrgt, CaptureData & io_cd );

  private: // structs, typedefs

    /** @brief Individual entries of iv_table. */
    struct TableData
    {
        bool    active;             ///< TRUE if this entry is active
        uint8_t count;              ///< Number of times this entry is detected
        CenAddr addr;               ///< Physical address of this entry
        uint8_t dram;               ///< The DRAM in which the CE was detected
        uint8_t dramPins;           ///< The failing pins of the DRAM
        uint8_t portSlct;           ///< The port select of the DRAM
        CenSymbol::WiringType type; ///< The wiring type

        /** @brief Default constructor. */
        TableData() :
            active(false), count(0), addr(), dram(0), dramPins(0), portSlct(0),
            type(CenSymbol::WIRING_INVALID)
        {}

        /**
         * @brief Constructor from components.
         * @param i_addr     The physical address of this entry.
         * @param i_dram     The DRAM in which the CE was detected
         * @param i_dramPins The failing pins of the DRAM
         * @param i_type     The wiring type (for DRAM site locations).
         */
        TableData( const CenAddr & i_addr, uint8_t i_dram, uint8_t i_dramPins,
                   uint8_t i_portSlct, CenSymbol::WiringType i_type ) :
            active(true), count(1), addr(i_addr), dram(i_dram),
            dramPins(i_dramPins), portSlct(i_portSlct), type(i_type)
        {}

        /** An entry is equivalent if the address and DRAM match. */
        bool operator==( const TableData & i_data ) const
        {
            return ( this->addr == i_data.addr && this->dram == i_data.dram );
        }
    };

    typedef std::list<TableData> CeTable;

  private: // instance variables

    /** A storage container for memory fetch CE errors. */
    CeTable iv_table;

};

} // end namespace PRDF

#endif // __prdfCenMbaCeTable_H

