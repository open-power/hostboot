/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/runtime/preverifiedlidmgr.H $                 */
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
#ifndef __PREVERIFIEDLIDMGR_H
#define __PREVERIFIEDLIDMGR_H

#include <map>
#include <errl/errlentry.H>
#include <pnor/pnorif.H>
#include <runtime/interface.h>
#include <sys/sync.h>
#include <attributeenums.H>

class PreVerifiedLidMgr
{
  public:

    /**
     * @brief Initialize and lock pre verified LID manager
     *
     * @param[in] i_prevAddr - previous HB reserved memory address
     * @param[in] i_prevSize - previous HB reserved memory address size
     * @param[in] i_rangeId - range id for HDAT entries
     *                        [Frequently node ID, see hdatMsVpdRhbAddrRange_t]
     */
    static void initLock(const uint64_t i_prevAddr,
                         const size_t i_prevSize = 0,
                         const uint64_t i_rangeId = 0);

    /**
     * @brief Unlock Pre Verified Lid manager
     */
    static void unlock();

    /**
     * @brief Load PNOR section into HB reserved memory
     *
     * @param[in] i_sec - PNOR section ID
     * @param[in] i_addr - Virtual Address of PNOR section
     * @param[in] i_size - Size of PNOR section
     *
     * @return Error handle if error
     */
    static errlHndl_t loadFromPnor(const PNOR::SectionId i_sec,
                                   const uint64_t i_addr,
                                   const size_t i_size);

  protected:

    /**
     * @brief Default Constructor
     */
    PreVerifiedLidMgr() {}

    /**
     * @brief Default Destructor
     */
    ~PreVerifiedLidMgr() {}

    /**
     * @brief Static instance function
     */
    static PreVerifiedLidMgr& getInstance();

  private:

    // Private Implementations of Static Public Methods

    /**
     * @brief Internal implementation of init function.
     */
    void _initLock(const uint64_t i_prevAddr,
                   const size_t i_prevSize = 0,
                   const uint64_t i_rangeId = 0);

    /**
     * @brief Internal implementation of unlock function.
     */
    void _unlock();

    /**
     * @brief Internal implementation of loadFromPnor function.
     */
    errlHndl_t _loadFromPnor(const PNOR::SectionId i_sec,
                             const uint64_t i_addr,
                             const size_t i_size);

    // Private Members/Variables

    // Cache the payload type
    static TARGETING::PAYLOAD_KIND cv_payloadKind;

    // Bool to check if the first PHYP lid has been loaded or not.
    static bool cv_phypLidSeen;

    // Collection of data needed for Hostboot Reserved Memory
    struct ResvMemInfo
    {
        // Range Id for HDAT entries
        uint64_t rangeId;
        // Current address of HB reserved memory
        uint64_t curAddr;
        // Previous size of HB reserved memory entry
        size_t prevSize;
    };

    // Pointer to either Deafult or PHYP Reserved Memory Info
    static ResvMemInfo* cv_pResvMemInfo;

    // Collection of data needed for Hostboot Reserved Memory
    static ResvMemInfo cv_resvMemInfo;

    // Location for PHYP lids to go.
    static ResvMemInfo cv_phypResvMemInfo;

    // Map of what lids have been loaded already.
    static std::map<uint64_t,bool> cv_lidsLoaded;

    // Mutex to prevent concurrent HB reserved memory operations.
    static mutex_t cv_mutex;

    // Mutex to prevent concurrent loading into HB reserved memory
    static mutex_t cv_loadImageMutex;

    // Function pointer to help finding the next address
    // Depends on the payload kind
    uint64_t (*getNextAddress)(const size_t);

    /**
     * @brief Get aligned reserved memory size for OPAL
     *        Note: Historically we have used the aligned size for OPAL
     *              alignment regardless of mode. Even if that means there is
     *              some wasted space.
     *
     * @return uint64_t - aligned address
     */
    static uint64_t getAlignedSize(const size_t i_imgSize);

    /**
     * @brief Get Next available HB reserved memory address for PHYP mode
     *        Note: PHYP we build up starting at the end of the previously
     *              allocated HOMER/OCC areas,
     *
     * @return uint64_t - next available address
     */
    static uint64_t getNextPhypAddress(const size_t i_prevSize);

    /**
     * @brief Get Next available HB reserved memory address for OPAL mode
     *        Note: OPAL we build downwards from the top of memory where the
     *              HOMER/OCC areas were placed
     *
     * @return uint64_t - next available address
     */
    static uint64_t getNextOpalAddress(const size_t i_curSize);

    /**
     * @brief Check if lid has already been loaded into HB reserved memory
     *
     * @param[in] uint32_t - lid id to check if loaded
     *
     * @return bool - True if previously loaded, false otherwise.
     */
    bool isLidLoaded(uint32_t i_lidId);

    /**
     * @brief Load Image into HB reserved memory
     *
     * @param[in] i_imgAddr - address of generic image
     * @param[in] i_imgSize - address of image size
     *
     * @return Error handle if error
     */
    errlHndl_t loadImage(const uint64_t i_imgAddr,
                         const size_t i_imgSize);

    // Allow test cases to have direct access
    friend class PreVerifiedLidMgrTest;
};


#endif