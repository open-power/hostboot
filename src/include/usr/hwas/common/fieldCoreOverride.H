/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/hwas/common/fieldCoreOverride.H $             */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2022                             */
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

#ifndef __FIELD_CORE_OVERRIDE_H
#define __FIELD_CORE_OVERRIDE_H
#include <targeting/common/commontargeting.H>
#include <vector>

#ifdef FSP_BUILD
    #include <tr1/memory>
#else
    #include <memory>
#endif

namespace FCO
{

typedef uint8_t coreDeconfigPriority_t;

// The boot core cannot be deconfigured by FCO this const will make sure the boot core is placed last
// for deconfig consideration.
constexpr coreDeconfigPriority_t BOOT_CORE_PRIORITY = UINT8_MAX;

// ============================
// Metadata structs
// ============================
// Though these contain some extra info that could be gleaned by looking at the targets the FCO code doesn't touch the
// targets directly so that test cases can construct arbitrary systems to test the algorithm against. Currently,
// standalone simics only simulates 2 PROCs compared to P10 Everest's 8 PROCs. 2 PROCs is not sufficient enough to
// exercise all the code paths or sufficiently large FCO values.

// This struct contains the necessary FCO metadata for a single CORE.
typedef struct coreFieldCoreOverrideMetadata
{
    TARGETING::TargetHandle_t target; // core target
    TARGETING::ATTR_CHIP_UNIT_type chipUnit; // Used to get deconfig priority
    // Is this core the boot core?
    bool isBootCore;
    // Has this core been marked for FCO deconfig?
    bool markedForFcoDeconfig;
    // The core target's sibling which is also contained within the FC
    coreFieldCoreOverrideMetadata * fcSiblingCore;

    // Constructors
    coreFieldCoreOverrideMetadata()
    : target(nullptr), chipUnit(0xFF), isBootCore(false),
      markedForFcoDeconfig(false), fcSiblingCore(nullptr) {};

    ~coreFieldCoreOverrideMetadata() = default;


} coreFcoMetadata_t;

typedef std::vector<std::unique_ptr<coreFcoMetadata_t>> coreFcoMetadataList_t;

// This struct holds the necessary FCO metadata for a single PROC.
typedef struct procFieldCoreOverrideMetadata
{

    TARGETING::TargetHandle_t target; // proc target
    // A unique id for this metadata. During IPL, this will be the target's HUID but during test it will be something
    // else since tests don't work with valid pointers to simulate larger systems.
    size_t procId;
    // How many COREs remain for this PROC. This should only include functional non-ECO cores.
    // This value may be modified a number of times during the FCO logic.
    size_t availableCores;
    // Is this the boot proc
    bool isBootProc;
    // The COREs to consider deconfiguring to satisfy FCO. Only include functional, non-ECO cores and the size()
    // should equal availableCores above.
    coreFcoMetadataList_t coreCandidateList;

    // Constructors
    procFieldCoreOverrideMetadata()
    : target(nullptr), procId(0), availableCores(0), isBootProc(false), coreCandidateList() {};
    // Cannot copy construct or copy assign this struct since it's managing a vector of unique_ptr
    procFieldCoreOverrideMetadata(const procFieldCoreOverrideMetadata &) = delete;
    procFieldCoreOverrideMetadata& operator=(const procFieldCoreOverrideMetadata &) = delete;

    ~procFieldCoreOverrideMetadata() = default;

} procFcoMetadata_t;

typedef std::vector<std::unique_ptr<procFcoMetadata_t>> procFcoMetadataList_t;

// This struct holds the FCO metadata for a single node.
typedef struct fieldCoreOverrideRestrictionMetadata
{
    // Max amount of units for this group of PROCs. The value is context sensitive to Fused Cores and Normal Cores
    // but that is accounted for by the FCO algorithm.
    size_t fcoValue;

    // The list of PROCs to consider deconfiguring child units to satisfy FCO. Shouldn't include non-functional PROCs.
    procFcoMetadataList_t procFcoMetadataList;

    // Constructors
    fieldCoreOverrideRestrictionMetadata()
    : fcoValue(0), procFcoMetadataList() {};
    // Cannot copy construct or copy assign this struct since it's managing a vector of unique_ptr
    fieldCoreOverrideRestrictionMetadata(const fieldCoreOverrideRestrictionMetadata&) = delete;
    fieldCoreOverrideRestrictionMetadata& operator=(const fieldCoreOverrideRestrictionMetadata&) = delete;

    ~fieldCoreOverrideRestrictionMetadata() = default;

} fcoRestrictMetadata_t;

// ============================
// Public API Functions
// ============================

/*
 * @brief Takes in a struct which holds all the necessary metadata about the node to perform the FCO logic on and
 *        applies that logic to restrict the number of FC/CORE targets down to the requested FCO value. This function
 *        was designed to operate on a single node since Hostboot is only aware of the node it's running on. Though the
 *        FCO value is a system-wide policy, this code considers the given FCO value in the struct to mean the max
 *        remaining units between the list of PROC targets given. Callers can invoke this function a number of times to
 *        satisfy the system-wide policy on multi-node systems.
 *
 * @param[in/out] io_fcoData   See definition of fcoRestrictMetadata_t for full contents.
 *                             IN: Struct should be composed of functional procs, how many available cores they have
 *                                 (excluding ECO cores), and a vector of all functional, non-ECO cores.
 *                             OUT: Algorithm will have sorted the procs such that the boot proc is first in the list
 *                                  and all procs available core numbers will be the number of functional cores
 *                                  remaining after the logic has been applied. The list of cores will have been sorted
 *                                  by the deconfig priorities given by the chip team and all relevant targets will have
 *                                  their markedForFcoDeconfig flags set. The caller is then responsible for performing
 *                                  the necessary deconfigs.
 */
void applyFieldCoreOverrides(fcoRestrictMetadata_t& io_fcoData);

/* @brief Takes in a reference to a target and applies all the necessary attribute changes to mark the target for
 *        deconfig due to FCO. This includes setting the HWAS state as present, not functional, and setting functional
 *        override so that reconfig loops will consider this target functional in that path. Additionally, it will
 *        update ATTR_PG as necessary by calling updateAttrPG().
 *
 * @param[in] i_target  Reference to a target to deconfig due to FCO.
 *
 */
void setHwasStateForFcoDeconfig(TARGETING::Target & i_target);

/* @brief sets the HWAS state and Attr PG info for the given core target
 *
 * @param[in] coreFcoMetadata_t  A reference to the metadata structure which must have a valid target pointer.
 */
void deconfigCoreByFco(coreFcoMetadata_t & i_core);

/* @brief sets the HWAS state and Attr PG info for the given core and its FC sibling
 *
 * @param[in] coreFcoMetadata_t  A reference to the metadata structure which must have valid target and fcSiblingCore
 *                               pointers.
 */
void deconfigFcByFco(coreFcoMetadata_t & i_core);

}
#endif
