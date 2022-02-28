/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/hwas/common/hwas.H $                          */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2022                        */
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
#ifndef  __HWAS_HWAS_H
#define __HWAS_HWAS_H
/**
 *  @file hwas.H
 *
 *  HardWare Availability Service prototypes.
 *  In trying to keep with C++ tradition, doxygen documentation for functions
 *  are here in the .H file.
 *
 *  All of the following routines are "named isteps" - they are invoked as
 *  tasks by the @ref IStepDispatcher.
 *
 */


/******************************************************************************/
// Includes
/******************************************************************************/
#include <stdint.h>
#include <targeting/common/commontargeting.H>
#include <hwas/common/deconfigGard.H>
#include <hwas/common/hwasError.H>
#include <targeting/common/target.H>

namespace HWAS
{

class HWASDiscovery
{

public:

    /**
     * @brief   discoverTagets   Common HWAS function to build targeting
     *
     *  This routine will walk through all the targets and initialize HWAS STATE
     *  to a known default value (powered off, etc.)
     *
     *  Then call into the hwas platform-specific platPresenceDetect() function
     *  to read the hardware information, and apply it to the target states,
     *  and call into the hwas platform-specific functions:
     *      platReadIDEC() to get and set the ChipID and EC values.
     *      platReadPartialGood() to get and set the partial good vector.
     *  Afterwards, for each target that has been processed, the PG is checked for
     *  its descendants. During that process, a dictionary (l_deconfigPGData) is
     *  filled with the targets that are not functional, as figured out by using VPD.
     *
     * @param  none
     *
     * @return errlHndl_t       valid errlHndl_t handle if there was an error
     *                          nullptr if no errors;
     */
    errlHndl_t discoverTargets();

private:

    /**
     * @brief   parsePgData     HWASDiscovery function to parse out a PGV
     *
     *  This function will parse out a partial good vector (PGV) from an array
     *  representing VPD data. This function is virtual so that it
     *  can be overridden during test cases.
     *
     * @param[in]     i_pgData           Array representing 24-bit partial good
     *                                 data
     *
     * @param[out]    o_pgDataExpanded   PGV representing 32-bit pg entries
     */
    virtual void parsePgData(
            const std::array<uint8_t, VPD_CP00_PG_DATA_LENGTH>& i_pgData,
            partialGoodVector& o_pgDataExpanded);

};

errlHndl_t discoverTargets();

/**
 * @brief   initHardware   Common HWAS function to setup the hardware
 *
 *  It will call into the hwas platform-specific platInitHardware()
 *  function to init the FSI hardware.
 *
 * @param  none
 *
 * @return errlHndl_t       valid errlHndl_t handle if there was an error
 *                          nullptr if no errors;
 */
errlHndl_t initHardware();



// Maximum number of EXs per proc
#define NUM_EX_PER_EQ     2
#define NUM_EQ_PER_CHIP   8
#define NUM_EX_PER_CHIP   (NUM_EX_PER_EQ * NUM_EQ_PER_CHIP)

// Maximum number of FCs per proc
#define NUM_FC_PER_EQ     2
#define NUM_FC_PER_CHIP   (NUM_FC_PER_EQ * NUM_EQ_PER_CHIP)

// structure used to store proc information for EC restrict processing
typedef struct {
    TARGETING::TargetHandle_t target;      // proc target
    uint32_t group;             // uniq id for this group - ie: FRUID, node
    uint32_t maxECs;            // max EC units for this group
    uint8_t procs;              // number of procs in the group
} procRestrict_t;

/**
 * @brief   restrictECunits   Internal HWAS function to restrict the ECs
 *
 *  This routine will walk through the procs in the list, and turn EC
 *  units to not functional if the number of units is larger than the max
 *  given. This is used for PG keyword and Field Core Override (FCO)
 *  processing.
 *
 * @param[in] i_procRestrict   vector of procRestrict entries
 * @param[in] i_deconfigReason   DECONFIGURED_BY_ enum or 0
 *                               If 0 will set knocked out units
 *                               to be present=false
 *
 * @return errlHndl_t       valid errlHndl_t handle if there was an error
 *                          nullptr if no errors;
 */
errlHndl_t restrictECunits(
    std::vector <procRestrict_t> &i_procRestrict,
    const uint32_t i_deconfigReason);

/**
 * @brief Verifies that the system has enough hardware to proceed through
 *  the IPL.
 *  This function contains checks that are COMMON between HWSV and HB.
 *  platform-specific checks will be called by platCheckMinimimHardware(),
 *  see hwasCommon.H .
 *  If it cannot find minimum hardware, an error will be created and returned.
 *  Error logs will also be created for each hardware module that is not
 *  running.
 *
 * @param[in]     i_nodeOrSys   Level of HW check node or system
 * @param[in/out] io_bootable
 *                 [in]  - If io_bootable is not nullptr, an error for
 *                         system unavailability will not be logged,
 *                         but instead just set the value at io_bootable.
 *                         If io_bootable is nullptr, speculative deconfigs
 *                         will be ignored, and error logs for system
 *                         unavailability, if any, will be logged.
 *                 [out] - If io_bootable is not nullptr, indicate whether
 *                         the system is bootable with current configuration.
 *                           True  - Sufficient HW available to boot
 *                           False - Insufficient HW available to boot
 *
 * @return error log handle, if any, and only if io_bootable is nullptr
 */
errlHndl_t checkMinimumHardware(
    const TARGETING::ConstTargetHandle_t i_nodeOrSys = nullptr,
    bool *io_bootable = nullptr);

/**
*  @brief  Loop through processors, make sure all have the same EC level
*          create an error log for any slave processor that does not match
*          the master's EC level
*
*
*  @return  errlHndl_t   Error returned will be a summary of all errors that
*                        occurred during the procedure, all PLIDs should match
*/
errlHndl_t validateProcessorEcLevels();

/**
 * @brief Determines if passed in ECs are allowed to be mixed without error
 *
 * Called by validateProcessorEcLevels()
 *
 * @param[in] i_model:    Cumulus or Nimbus
 * @param[in] i_baseEC:   EC level of primary chip
 * @param[in] i_compareEC:  EC level of to check against mixing allowed
 *
 * @return bool -- true if mixing allowed, otherwise false
 *                 note that same EC is not mixed, thus returns false
 */
bool mixedECsAllowed(TARGETING::ATTR_MODEL_type i_model,
                     TARGETING::ATTR_EC_type i_baseEC,
                     TARGETING::ATTR_EC_type i_compareEC);


/**
 * @brief  Struct representing a particular target.  Used by
 * invokePresentByAssoc to populate a vector of TargetInfo's for subsequent
 * use by deconfigPresentByAssoc
 */
struct TargetInfo
{
    TARGETING::ATTR_AFFINITY_PATH_type affinityPath;
    TARGETING::Target * pThisTarget;
    TARGETING::ATTR_TYPE_type type;
    HWAS::DeconfigGard::DeconfiguredByReason reason;
};

// Structure populated in invokePresentByAssoc() for use in presentByAssoc()
typedef std::vector<TargetInfo> TargetInfoVector;

/**
 * @brief Invokes presentByAssoc
 *
 * Called by discoverTargets(). This function queries the system and populates
 * a vector of structs representing functional MCS, MEMBUFS, MBAs, MCAs,DIMMS.
 * This vector is then passed to presentByAssoc() which systematically adds
 * targets to another vector to be deconfigured based on their related targets
 * Upon completion of presentByAssoc(), this function iterates
 * through the returned vector and deconfigures any targets marked
 * for deconfiguration.
 */
void invokePresentByAssoc();

/**
 * @brief Deconfigures a target based on type
 *
 * Called by invokePresentByAssoc() after presentByAssoc() is called
 *
 * @param[in] i_targInfo TargetInfo for the target to be deconfigured
 */
void deconfigPresentByAssoc(TargetInfo i_targInfo);

/**
 * @brief Algorithm to validate the memory target structure.
 *
 * This function ensures that targets are deconfigured appropriately based on
 * whether their parents or children are functional.
 *
 * @param[in] i_funcTargets A vector of functional memory targets. The vector
 *                          contains no meaningful data after the function returns.
 */
void presentByAssoc(TARGETING::TargetHandleList& i_funcTargets);

/**
* @brief Algorithm to set up the EQ_GARD and EC_GARD attributes on the proc
*
* @param[in] i_procTarget    Proccesor target to set attributes on
*/
void setChipletGardsOnProc(TARGETING::Target * i_procTarget);


/**
 * @brief Find the ATTR_EC for all processors and calculate the EFFECTIVE_EC
 *        (the lowest EC found)
 *
 */
void calculateEffectiveEC();

/**
 * @brief Mark any MCA units that are present but have a disabled port as
 *        non-functional
 *
 * @return error log handle
 */
errlHndl_t markDisabledMcas();

/*
 * @WARNING: Deprecated. Hostboot code no longer uses PROC_MEM_TO_USE and this
 *           function is a no-op.
 *
 * @brief: This function calls check_for_missing_memory and set
 *         ATTR_PROC_MEM_TO_USE to the processor that we should use
 *         in case of missing memory behind master proc
 *
 * @note:  Only applicable for PHYP based system
 *
 * @param[in]: i_node: Node target to operate on
 *
 * @retval: error log handle
 */
errlHndl_t update_proc_mem_to_use(const TARGETING::Target* i_node);

/**
 * @brief       simple helper fn to get and set hwas state to poweredOn,
 *                  present, functional and then execute any secondary
 *                  behaviors that are required.
 *
 * @param[in]   i_target        pointer to target that we're looking at
 * @param[in]   i_present       boolean indicating present or not
 * @param[in]   i_functional    boolean indicating functional or not
 * @param[in]   i_errlEid       erreid that caused change to non-funcational;
 *                              0 if not associated with an error or if
 *                              functional is true
 *
 * @return      none
 *
 */
void enableHwasState(TARGETING::Target *i_target,
                     bool i_present,
                     bool i_functional,
                     uint32_t i_errlEid);

};   // end namespace

#endif
