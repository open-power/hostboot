/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/pegasus/prdfCenMbaUeTable.H $   */
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

#ifndef __prdfCenMbaUeTable_H
#define __prdfCenMbaUeTable_H

/** @file prdfCenMbaUeTable.H */

// Framwork includes
#include <iipCaptureData.h>
#include <prdfParserEnums.H>
#include <prdfPlatServices.H>

// Pegasus includes
#include <prdfCenAddress.H>

// Other includes
#include <list>

namespace PRDF
{

/**
 * @brief A table of memory UEs.
 * @note  Only one of these tables will exists per MBA.
 * @note  So far, this table is used only for FFDC.
 */
class CenMbaUeTable
{

  private: // constants, enums

    /** @brief Table size limits. */
    enum TableTHs
    {
        MAX_ENTRY_COUNT = 255, ///< Entry count threshold
    };

  public: // functions

    /**
     * @brief Will attempt to add a new entry to the table.
     * @note  If an entry already exists, the entry's count is incremented and
     *        moved to the end of the queue.
     * @param i_type See enum UE_TABLE::Type.
     * @param i_addr The address in which the UE occured.
     */
    void addEntry( UE_TABLE::Type i_type, const CenAddr & i_addr );

    /**
     * @brief Gathers all table data to be stored in capture data.
     * @param i_mbaTrgt  An MBA target.
     * @param io_cd      Capture data struct.
     */
    void addCapData( TARGETING::TargetHandle_t i_mbaTrgt, CaptureData & io_cd );

  private: // structs, typedefs

    /** @brief Individual entries of iv_table. */
    struct UeTableData
    {
        UE_TABLE::Type  type;  ///< See enum UE_TABLE::Type
        CenAddr         addr;  ///< The address in which the UE occured
        uint8_t         count; ///< Number of times the entry is detected

        /** @brief Default constructor. */
        UeTableData() {}

        /**
         * @brief Constructor from components.
         * @param i_type See enum UE_TABLE::Type.
         * @param i_addr The address in which the UE occured.
         */
        UeTableData( UE_TABLE::Type i_type, const CenAddr & i_addr ) :
            type(i_type), addr(i_addr), count(1)
        {}

        /** An entry is equivalent if the type and address match. */
        bool operator==( const UeTableData & i_data ) const
        {
            return ( this->type == i_data.type && this->addr == i_data.addr );
        }
    };

    typedef std::list<UeTableData> UeTable;

  private: // instance variables

    /** A FIFO that stores the latest memory UE addresses and their types. This
     *  is not a pure FIFO, because if a new entry matches an existing entry,
     *  the existing entries count is incremented and it is moved to the end of
     *  the queue. However, if a new entry does not match an existing entry and
     *  the table is full, the oldest entry will be removed to make room for
     *  the new entry. */
    UeTable iv_table;
};

} // end namespace PRDF

#endif // __prdfCenMbaUeTable_H

