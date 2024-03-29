/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/mem/prdfMemoryMru.H $           */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2023                        */
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

#include <prdfMemAddress.H>
#include <prdfMemoryMruData.H>
#include <prdfPlatServices.H>
#include <prdfMemSymbol.H>
#include <prdfParserEnums.H>

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

    MemoryMru() = delete;  // Don't allow default contructor

    /**
     * @brief Constructor from 32-bit representation of a memory MRU.
     * @param i_memMru A 32-bit representation of a memory MRU.
     */
    explicit MemoryMru( uint32_t i_memMru );

    /**
     * @brief Constructor for single DIMM callouts.
     * @param i_target    The OCMB in which the error occurred.
     * @param i_rank      The rank in which the error occurred.
     * @param i_symbol    The symbol in which the error occurred.
     */
    MemoryMru( TARGETING::TargetHandle_t i_target, const MemRank & i_rank,
               uint8_t i_port, const MemSymbol & i_symbol );

    /**
     * @brief Constructor for special callouts.
     * @param i_target         The OCMB in which error has occurred
     * @param i_rank           The rank in which the error occurred.
     * @param i_specialCallout See enum MemoryMruData::Callout.
     */
    MemoryMru( TARGETING::TargetHandle_t i_target, const MemRank & i_rank,
               uint8_t i_port, MemoryMruData::Callout i_specialCallout );

  public: // functions

    /** @return The 32-bit representation of this MemoryMru. */
    uint32_t toUint32() const { return iv_memMruMeld.u; }

    /** @return A list of targets that are represented by this MemoryMru. */
    TARGETING::TargetHandleList getCalloutList() const;

    /** @return The target associated with this MemoryMru. */
    TARGETING::TargetHandle_t getTrgt() const { return iv_target; }

    /** @return The rank associated with this MemoryMru. */
    MemRank getRank() const { return iv_rank; }

    /** @return The symbol associated with this MemoryMru. */
    MemSymbol getSymbol() const { return iv_symbol; }

  private: // instance variables

    MemoryMruData::MemMruMeld iv_memMruMeld;

    TARGETING::TargetHandle_t iv_target; ///< Target
    MemRank iv_rank;                     ///< Target rank
    MemoryMruData::Callout iv_special;   ///< See enum MemoryMruData::Callout
    MemSymbol iv_symbol;                 ///< Target symbol

  private: // local helper functions

    /** @brief Gets the instance variable values common between constructors */
    void getCommonVars();
};

} // end namespace PRDF

#endif // __prdfMemoryMru_H

