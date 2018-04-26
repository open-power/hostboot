/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/mem/prdfMemRceTable.H $         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2018                        */
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

#ifndef __prdfMemRceTable_H
#define __prdfMemRceTable_H

/** @file  prdfMemRceTable.H */

// Framwork includes
#include <iipCaptureData.h>
#include <prdfPlatServices.H>
#include <prdfThresholdUtils.H>

// Platform includes
#include <prdfMemRank.H>

// Other includes
#include <map>

namespace PRDF
{

/**
 * @brief A table of memory RCEs.
 * @note  Only one of these tables will exist per MBA.
 * @note  Will be used to determine when to do a TPS procedure for Targeted
 *        Diagnostics at runtime. Will be used for FFDC only during Hostboot.
 */
class MemRceTable
{

  public: // functions

    /**
     * @brief Constructor
     * @param i_mbaTrgt An MBA target.
     */
    explicit MemRceTable( ExtensibleChip * i_chip ) :
        iv_chip( i_chip )
    {}

    /**
     * @brief  Will attempt to add a new entry to the table.
     *
     * If an entry already exists, the entry's count is incremented. Otherwise,
     * a new entry is created. Will return TRUE if the RCE triggers TPS
     * conditions:
     *
     * @param  i_rank  rank.
     * @param  i_sc    The step code data struct.
     * @param  i_count RCE count.
     * @return TRUE if TPS is required, FALSE otherwise.
     */
    bool addEntry( const MemRank & i_rank,
                   STEP_CODE_DATA_STRUCT & i_sc, uint8_t i_count = 1  );

    /**
     * @brief Flush entry covered by a rank.
     * @param i_rank The target rank.
     */
    void flushEntry( const MemRank & i_rank );

    /**
     * @brief Gathers all table data to be stored in capture data.
     * @param io_cd      Capture data struct.
     */
    void addCapData( CaptureData & io_cd );

    /** Default Constructor */
    MemRceTable():iv_table(){}

  private: // structs, typedefs

    typedef std::map<MemRank, TimeBasedThreshold> RceTable;

  private: // instance variables

    /** The chip associated with this table. */
    ExtensibleChip * iv_chip;

    /** A storage container for memory RCE errors. */
    RceTable iv_table;
};

} // end namespace PRDF

#endif // __prdfMemRceTable_H

