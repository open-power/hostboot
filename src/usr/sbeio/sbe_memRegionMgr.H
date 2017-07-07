/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/sbeio/sbe_memRegionMgr.H $                            */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017                             */
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
#ifndef __SBE_MEMREGIONMGR_H
#define __SBE_MEMREGIONMGR_H

#include <stdint.h>
#include <errl/errlentry.H>
#include <vector>
#include <sbeio/sbeioif.H>

namespace SBEIO
{

/*
 * @brief Struct containing specifics of a Unsecure Memory Region
 */
struct regionData
{
    uint64_t start_addr; // Start address of region
    uint32_t size;       // Size of region in bytes

    // Control Flags for PSU command -
    // - see SbePsu::psuSetUnsecureMemoryRegionControlFlags
    uint8_t  flags;

    // Target associated with the SBE
    // - If tgt == nullptr it will eventually be updated to the Master Proc
    TARGETING::Target* tgt;

    regionData() : start_addr(0), size(0), flags(0), tgt(nullptr) {}
};

/** @class MemRegionMgr
 *  @brief   Responsible for managing the SBE Unsecure Memory Regions
 *
 */
class MemRegionMgr
{

  private:

    /** Cache of Unsecure Memory Regions that are currently open */
    std::list< regionData >  iv_memRegions;

    /* For Debug purposes: Pring Out Vector of iv_memRegions */
    void printIvMemRegions() const;

    /**
     * @brief Local Function To Open/Close Unsecure Memory Regions
     *
     * @param[in] i_region  Structure containing information about the region
     *
     * @return errlHndl_t Error log handle on failure.
     *
     */
    errlHndl_t doUnsecureMemRegionOp(regionData & i_region);

  public:
    /**
     * @brief Constructor.  Initializes instance variables.
     */
    MemRegionMgr();

    /**
     * Destructor.
     */
    ~MemRegionMgr();

    /**
     * Delete Copy Constructor
     */
    MemRegionMgr(const MemRegionMgr&) = delete;

    /**
     * Delete Copy Assignment
     */
    MemRegionMgr& operator= (const MemRegionMgr&) = delete;

    /**
     * Delete Move Constructor
     */
    MemRegionMgr (MemRegionMgr&&) = delete;

    /**
     * Delete Move Assignment
     */
    MemRegionMgr& operator = (MemRegionMgr&&) = delete;

    /**
     * @brief Open Unsecure Memory Region via the SBE
     *
     * @note: See openUnsecureMemRegion() function in sbeioif.H for details
     *
     */
    errlHndl_t openUnsecureMemRegion(
        const uint64_t i_start_addr,
        const uint32_t i_size,
        const bool     i_isWritable,
        TARGETING::Target* i_target);

   /**
     * @brief Close Unsecure Memory Region
     *
     * @note: See closeUnsecureMemRegion() function in sbeioif.H for details
     *
     */
    errlHndl_t closeUnsecureMemRegion(
        const uint64_t i_start_addr,
        TARGETING::Target* i_target);


    /**
     * @brief Close All Unsecure Memory Regions
     *
     * @note: See closeAllUnsecureMemRegions() function in sbeioif.H for details
     *
     */
    errlHndl_t closeAllUnsecureMemRegions();

}; // class MemRegionMgr


}; // end namespace SBEIO

#endif

