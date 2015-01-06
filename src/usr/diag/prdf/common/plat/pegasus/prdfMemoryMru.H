/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/pegasus/prdfMemoryMru.H $       */
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

/** @file prdfMemoryMru.H */

#ifndef __prdfMemoryMru_H
#define __prdfMemoryMru_H

#include <prdfCenAddress.H>
#include <prdfMemoryMruData.H>
#include <prdfPlatServices.H>
#include <prdfCenSymbol.H>

namespace PRDF
{

/**
 * @brief This is a container object that assists with callouts and FFDC for the
 *        mainstore memory subsystem. The intent is that it can show with the
 *        smallest possible granularity what part is failing (i.e. DIMM, rank,
 *        DRAM, a single pin on a DRAM, etc.).
 */
class MemoryMru
{
  public: // Constructors

    /** @brief Default contructor. */
    MemoryMru();

    /**
     * @brief Constructor from 32-bit representation of a memory MRU.
     * @param i_memMru A 32-bit representation of a memory MRU.
     */
    explicit MemoryMru( uint32_t i_memMru );

    /**
     * @brief Constructor for single DIMM callouts.
     * @param i_mbaTarget The MBA in which the error occurred.
     * @param i_rank      The rank in which the error occurred.
     * @param i_symbol    The symbol in which the error occurred.
     */
    MemoryMru( TARGETING::TargetHandle_t i_mbaTarget, const CenRank & i_rank,
               const CenSymbol & i_symbol );

    /**
     * @brief Constructor for special callouts.
     * @param i_mbaTarget      The MBA in which error has occurred
     * @param i_rank           The rank in which the error occurred.
     * @param i_specialCallout See enum MemoryMruData::Callout.
     */
    MemoryMru( TARGETING::TargetHandle_t i_mbaTarget, const CenRank & i_rank,
               MemoryMruData::Callout i_specialCallout );

  public: // functions

    /** @return The 32-bit representation of this MemoryMru. */
    uint32_t toUint32() const { return iv_memMruMeld.u; }

    /** @return A list of targets that are represented by this MemoryMru. */
    TARGETING::TargetHandleList getCalloutList() const;

  private: // instance variables

    MemoryMruData::MemMruMeld iv_memMruMeld;

    TARGETING::TargetHandle_t iv_mbaTarget; ///< Target MBA.
    CenRank iv_rank;                        ///< Target rank
    MemoryMruData::Callout iv_special;      ///< See enum MemoryMruData::Callout
    CenSymbol iv_symbol; ///< Target symbol
};

} // end namespace PRDF

#endif // __prdfMemoryMru_H

