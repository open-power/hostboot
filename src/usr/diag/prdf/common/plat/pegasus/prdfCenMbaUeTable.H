/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/pegasus/prdfCenMbaUeTable.H $   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2015                        */
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
     * @brief Constructor
     * @param i_mbaTrgt An MBA target.
     */
    explicit CenMbaUeTable( TARGETING::TargetHandle_t i_mbaTrgt ) :
        iv_mbaTrgt( i_mbaTrgt )
    {}

    /**
     * @brief Will attempt to add a new entry to the table.
     * @note  If an entry already exists, the entry's count is incremented and
     *        moved to the end of the queue.
     * @param i_type See enum UE_TABLE::Type.
     * @param i_addr The address in which the UE occurred.
     */
    void addEntry( UE_TABLE::Type i_type, const CenAddr & i_addr );

    /**
     * @brief Gathers all table data to be stored in capture data.
     * @param io_cd      Capture data struct.
     */
    void addCapData( CaptureData & io_cd );

  private: // structs, typedefs

    /** @brief Individual entries of iv_table. */
    struct UeTableData
    {
        UE_TABLE::Type  type;  ///< See enum UE_TABLE::Type
        CenAddr         addr;  ///< The address in which the UE occurred
        uint8_t         count; ///< Number of times the entry is detected

        /** @brief Default constructor. */
        UeTableData() {}

        /**
         * @brief Constructor from components.
         * @param i_type See enum UE_TABLE::Type.
         * @param i_addr The address in which the UE occurred.
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

    /** MBA associated with this table. */
    TARGETING::TargetHandle_t iv_mbaTrgt;

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

