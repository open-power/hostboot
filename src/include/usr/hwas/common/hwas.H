/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/hwas/common/hwas.H $                          */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2015                        */
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

namespace HWAS
{

/**
 * @brief   initHardware   Common HWAS function to setup the hardware
 *
 *  It will call into the hwas platform-specific platInitHardware()
 *  function to init the FSI hardware.
 *
 * @param  none
 *
 * @return errlHndl_t       valid errlHndl_t handle if there was an error
 *                          NULL if no errors;
 */
errlHndl_t initHardware();

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
 *
 * @param  none
 *
 * @return errlHndl_t       valid errlHndl_t handle if there was an error
 *                          NULL if no errors;
 */
errlHndl_t discoverTargets();

/**
 * @brief   restrictEXunits   Internal HWAS function to restrict the EXs
 *
 *  This routine will walk through the procs in the list, and turn EX
 *  units to not functional if the number of units is larger than the max
 *  given. This is used for PR keyword and Field Core Override (FCO)
 *  processing.
 *
 * @param[in] i_procRestrict   vector of procRestrict entries
 * @param[in] i_present    boolean for 'present' HWAS value for restricted
 *                          EX units
 * @param[in] i_deconfigReason   DECONFIGURED_BY_ enum or 0
 *
 * @return errlHndl_t       valid errlHndl_t handle if there was an error
 *                          NULL if no errors;
 */

// structure used to store proc information for EX restrict processing
typedef struct {
    TARGETING::TargetHandle_t target;      // proc target
    uint32_t group;             // uniq id for this group - ie: FRUID, node
    uint32_t maxEXs;            // max EX units for this group
    uint8_t procs;              // number of procs in the group
} procRestrict_t;

errlHndl_t restrictEXunits(
    std::vector <procRestrict_t> &i_procRestrict,
    const bool i_present,
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
 * @param[in] i_node  node target to restrict hw check
 *
 * @return error log handle
 */
errlHndl_t checkMinimumHardware(
    const TARGETING::ConstTargetHandle_t i_node = NULL);

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
 * a vector of structs representing functional MCS, MEMBUFS, DIMMS.
 * This vector is then passed to presentByAssoc() which systematically adds
 * targets to another vector to be deconfigured based on their related targets
 * Upon completion of presentByAssoc(), this function iterates
 * through the returned vector and deconfigures any targets marked
 * for deconfiguration.
 */
void invokePresentByAssoc();

/**
 * @brief Algorithm to check if a MCS has a MEMBUF, a MEMBUF has a MCS and DIMM,
 *        and a DIMM has a MEMBUF.
 *
 * The vector o_funcTargets is sorted by affinity path to allow a single pass
 * with some backtracking to check every scenario more efficiently.
 * These checks are needed because of scenarios where targets are non-present
 * and their related targets are not marked as deconfigured
 *
 * @param[in/out] io_funcTargets    A vector of functional MCS, MEMBUFS, DIMMS
 * @param[out]    o_targToDeconfig  A vector of targets to deconfigure, done
 *                                  this way to allow unit tests
 */
void presentByAssoc(TargetInfoVector& io_funcTargets,
                    TargetInfoVector& o_targToDeconfig);

};   // end namespace

#endif
