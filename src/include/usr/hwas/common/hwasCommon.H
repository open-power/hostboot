/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/hwas/common/hwasCommon.H $                    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2021                        */
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
/**
 *  @file hwasCommon.H
 *
 *  @brief Notes the HWAS common functions and the HWAS platform-specific
 *          interfaces that need to be defined and implemented.
 */

#ifndef HWASCOMMON_H_
#define HWASCOMMON_H_

#include <map>
#include <hwas/common/vpdConstants.H>
#include <hwas/common/pgLogic.H>

// 'system' headers
#include <stdint.h>
#include <targeting/common/target.H>
#include <targeting/common/targetservice.H>
#include <hwas/common/hwasError.H>
#include <hwas/common/hwasCallout.H>

// platform specific headers

// following file needs to do
//  #define HWAS_DBG(_fmt_, _args_...)
//  #define HWAS_ERR(_fmt_, _args_...)
#include <hwas/hwasPlatTrace.H>

// following file needs to do
//  #define HWAS_ASSERT(_expr_...)
#include <hwas/hwasPlatAssert.H>

namespace HWAS
{

/**
 * @brief platform specific code to determine whether the System is at runtime.
 *
 * @return bool  Return true if the System is at runtime; false if not.
 */

bool platSystemIsAtRuntime();

/**
 * @brief platform specific code to determine if minimum hardware
 * check is allowed.
 *
 * @param[out] o_minHwCheckingAllowed   boolean:
 *             TRUE if minimum hardware checking is allowed
 *             FALSE if minimum hardware checking is not allowed
 *
 * @return errlHndl_t       valid errlHndl_t handle if there was an error
 *                          NULL if no errors;
 */
errlHndl_t platIsMinHwCheckingAllowed(bool &o_minHwCheckingAllowed);

/**
 * @brief platform specific code to determine if the targets in the
 *  input list are present or not. If a target is NOT present, it is erased
 *  from the list
 *
 * @param[in]  io_targets   TargetHandleList of targets to check for presence
 *
 * @return errlHndl_t       valid errlHndl_t handle if there was an error
 *                          NULL if no errors;
 */
errlHndl_t platPresenceDetect(TARGETING::TargetHandleList &io_targets);

/**
 * @brief platform specific code to determine the ID/EC of the input
 *  target. The platform specific code is responsible for setting the
 *  ATTR_EC and ATTR_CHIP_ID in each target.
 *
 * @param[in]  i_target    target to check for chip ID/EC
 *
 * @return errlHndl_t       valid errlHndl_t handle if there was an error
 *                          NULL if no errors;
 */
errlHndl_t platReadIDEC(const TARGETING::TargetHandle_t &i_target);

/**
 * @brief platform specific code to determine the PG vector of the input
 *  target. The platform specific code is responsible for returning the
 *  vector. The caller is responsible for allocating and de-allocating the
 *  space.
 *
 * @param[in]  i_target    target to read the Partial Good keyword from
 * @param[out] o_pgData    pointer to area that will hold the partialGood vector
 *                         read from VPD; must be allocated by the caller,
 *                         and must be VPD_CP00_PG_DATA_LENGTH in size.
 *
 * @return errlHndl_t       valid errlHndl_t handle if there was an error
 *                          NULL if no errors;
 */
errlHndl_t platReadPartialGood(const TARGETING::TargetHandle_t &i_target,
                                void *o_pgData);

/*
 * @brief Platform specific code to call the p10_determine_eco_mode hardware procedure which will determine which cores
 *        from the list are to be used for ECO mode.
 *
 * @param[in,out] io_cores   The list of functional cores to determine which are to be used for ECO mode.
 *
 * @return      errlHndl_t   nullptr on success, otherwise an error log.
 */
errlHndl_t platDetermineEcoCores(const TARGETING::TargetHandleList &io_cores);

/**
 * @brief Checks the PG keyword data to determine if the target chip is
 *  functional. The caller is responsible for allocating and de-allocating the
 *  PG keyword space.
 *
 * @param[in]  i_target    pointer to target that we're looking at
 * @param[in]  i_pgData    array holding the PG keyword read from VPD
 *
 * @return bool Return true if the chip is functional; false if not.
 *
 */
bool isChipFunctional(const TARGETING::TargetHandle_t &i_target,
                      const partialGoodVector &i_pgData);


// This map is used to track the state of previously checked targets in the
// isDescFunctional method. This is used instead of directly looking at
// hwasState to keep the isDescFunctional logic self-contained and work around
// a limitation with the unit testing. Since hwasState can't be changed during
// testing the only other way to verify the algorithm works is by modifing this
// to match the test conditions.
typedef std::map<const TARGETING::TargetHandle_t, bool> pgState_map;

/**
 * @brief                         Checks the PG keyword data to determine if the
 *                                descendant chiplet is functional. The caller
 *                                is responsible for allocating and
 *                                de-allocating the PG keyword space.
 *
 * @param[in]  i_desc             Reference to descendant of target we're looking
 *                                at.
 *
 * @param[in]  i_pgData           Reference to array holding the PG keyword read
 *                                from VPD
 *
 * @param[io]  io_targetStates    Reference to the target state map to prevent
 *                                re-checking targets.
 *
 * @param[io]  io_deconfigTargets Optional argument, store reference to targets
 *                                found to be not functional by VPD data
 *
 * @return bool                   Returns true if the descendant is functional;
 *                                False if not.
 *
 */
bool isDescFunctional(const TARGETING::TargetHandle_t &i_desc,
                      const partialGoodVector &i_pgData,
                      pgState_map &io_targetStates,
                      TARGETING::TargetHandleList *io_deconfigTargets = nullptr);


/**
 * @brief                         Checks the PG keyword data to determine if at
 *                                least one of the descendant chiplets is
 *                                functional. The caller is responsible for
 *                                allocating and de-allocating the PG keyword space.
 *
 * @param[in]  i_pTarget          The target whose descendants need to be
 *                                checked.
 *
 * @param[in]  i_pgData           Reference to array holding the PG keyword read
 *                                from VPD.
 *
 * @param[in]  i_chipFunctional   The functional state of i_pTarget.
 *
 * @param[in]  i_errlEid          Error log ID of the error associated with
 *                                i_pTarget, if any.
 *
 * @param[io]  io_infoErrl        The informational error log that contains PG
 *                                issues.
 *
 * @param[io]  io_createInfoLog   Determines whether or not PG issues exist and
 *                                if the informational log should be created.
 *
 * @param[in] i_isTestcase        Determines if the code is running from a
 *                                testcase and if so will not modify the state
 *                                of the system. Defaulted to false.
 *
 * @param[out] o_testResult       A pointer to the functional state of i_pTarget
 *                                if we are running a test. Default nullptr.
 *
 * @param[io]  io_deconfigTargets Optional argument, will store reference to
 *                                targets marked as notfunctional by VPD data.
 *                                This data is gathered when
 *                                isDescFunctional(...) is called.
 *
 * @return                        Returns an error if encountered, otherwise
 *                                nullptr.
 *
 */
errlHndl_t checkPartialGoodForDescendants(
                const TARGETING::TargetHandle_t &i_pTarget,
                const partialGoodVector &i_pgData,
                const bool i_chipFunctional,
                const uint32_t i_errlEid,
                errlHndl_t io_infoErrl,
                bool* io_createInfoLog,
                bool i_isTestcase = false,
                bool* o_testResult = nullptr,
                TARGETING::TargetHandleList* io_deconfigTargets = nullptr);

/**
* @brief                         This function will propagate a parent's
*                                non-functional status down to all functional
*                                children since children cannot be considered
*                                functional if they have non-functional parents.
*                                NOTE: This function will only mark children
*                                non-functional if the passed-in parent is
*                                non-functional and is in the io_targetStates
*                                map. Therefore, if a parent is passsed in that
*                                is functional or missing from the
*                                io_targetStates map (parent state unknown) this
*                                function behaves as a no-op.
*
* @param[in]  i_desc             Pointer to the parent target we're looking
*                                at. Must not be nullptr.
*
* @param[io]  io_targetStates    Reference to the pgState_map that will be
*                                updated by this function.
*
*/
void markChildrenNonFunctional(const TARGETING::TargetHandle_t &i_parent,
                               pgState_map &io_targetStates);

/**
 * @brief Check whether NMMU 1 should be deconfigured because PAU 0, 4, and 5
 *        are all nonfunctional.
 *
 * @param[in]  i_proc      The proc to examine.
 *
 * @return     Target*     A pointer to NMMU 1 for the given proc if it is
 *                         functional and should be deconfigured; otherwise
 *                         returns nullptr.
 */
TARGETING::Target* shouldPowerGateNMMU1(const TARGETING::Target& i_pProc);


/**
 * @brief Return a list of extra OCAPI IOHSes that need to be deconfigured
 *        because there aren't enough PAUs to associate with all of them.
 *
 * @param[in]  i_pauc         The parent PAUC target
 * @return TargetHandleList   List of targets to deconfigure.
 */
TARGETING::TargetHandleList
disableExtraOcapiIohsTargets(const TARGETING::Target* i_pauc);


/**
 * @deprecated
 * @brief platform specific code to determine the PR vector of the input
 *  target. The platform specific code is responsible for returning the
 *  vector. The caller is responsible for allocating and de-allocating the
 *  space.
 *
 * @param[in]  i_target    target to read the PR keyword from
 * @param[out] o_prData    pointer to area that will hold the PR keyword
 *                          read from VPD; must be malloc'ed by the caller,
 *                          and must be VPD_CP00_PR_DATA_LENGTH in size.
 *
 * @return errlHndl_t       valid errlHndl_t handle if there was an error
 *                          NULL if no errors;
 */
errlHndl_t platReadPR(const TARGETING::TargetHandle_t &i_target,
                      void *o_prData);

/**
 * @brief platform specific code to determine the Lx vector of the input
 *  target. The platform specific code is responsible for returning the
 *  vector. The caller is responsible for allocating and de-allocating the
 *  space.
 *
 * @param[in]  i_mca       MCA target indicating which Lx keyword to read
 * @param[out] o_lxData    pointer to area that will hold the Lx keyword
 *                          read from VPD; must be malloc'ed by the caller,
 *                          and must be VPD_CRP0_LX_DATA_LENGTH in size.
 *
 * @return errlHndl_t       valid errlHndl_t handle if there was an error
 *                          NULL if no errors;
 */
errlHndl_t platReadLx(const TARGETING::TargetHandle_t &i_mca,
                      void *o_lxData);

/**
 * @brief platform specific code to read the Field Core Override
 *
 * @param[in]   i_node      node target, where the FCO is stored
 * @param[out]  o_fco       field core override value
 *
 * @return errlHndl_t       valid errlHndl_t handle if there was an error
 *                          NULL if no errors;
 */
errlHndl_t platGetFCO(
        const TARGETING::TargetHandle_t &i_node,
        uint32_t &o_fco);

/**
 * @brief wrapper function to create new errlog in platform-specific manner.
 *
 * @param[in] i_sev        Severity
 * @param[in] i_modId      Module ID   (from HwasModuleID enum)
 * @param[in] i_reasonCode Reason Code (from HwasReasonCode enum)
 * @param[in] i_user1      User Data 1 (defaults to zero)
 * @param[in] i_user2      User Data 2 (defaults to zero)
 *
 * @return errlHndl_t handle pointing to newly created error log
 */
errlHndl_t hwasError(const uint8_t i_sev,
                     const uint8_t i_modId,
                     const uint16_t i_reasonCode,
                     const uint64_t i_user1 = 0,
                     const uint64_t i_user2 = 0);

/**
 * @brief wrapper function to add a procedure callout to an error log in a
 *  platform-specific manner.
 *
 * @param[io] io_errl     Reference to error log handle. Updated with callout
 * @param[in] i_procedure Procedure to callout
 * @param[in] i_priority  Callout Priority
 */
void hwasErrorAddProcedureCallout(errlHndl_t & io_errl,
                                  const HWAS::epubProcedureID i_procedure,
                                  const HWAS::callOutPriority i_priority);

/**
 * @brief wrapper function to add a procedure callout to an error log in a
 *  platform-specific manner.
 *
 */
void platHwasErrorAddHWCallout(errlHndl_t & io_errl,
                           const TARGETING::ConstTargetHandle_t i_target,
                           const HWAS::callOutPriority i_priority,
                           const HWAS::DeconfigEnum i_deconfigState,
                           const HWAS::GARD_ErrorType i_gardErrorType);

/**
 * @brief wrapper function to update the plid in a platform-specific manner.
 *
 * If io_plid is non-zero then io_errl is updated with io_plid
 * Else io_plid is updated with the plid in io_errl
 *
 * @param[io] io_errl Reference to error log handle.
 * @param[io] io_plid Reference to plid.
 */
void hwasErrorUpdatePlid(errlHndl_t & io_errl,
                         uint32_t & io_plid);


/**
 * @brief wrapper function to add a partial good user detail section to an error
 *        log in a platform-specific manner.
 *
 * @param[io] io_errl              A reference to the error log handle.

 * @param[i]  i_modelAgData        A reference to model-specific AG entries
 * @param[i]  i_pgData             Reference to array holding the PG keyword read
 *                                 from VPD
 */
void hwasErrorAddPartialGoodFFDC(errlHndl_t & io_errl,
                                 const model_ag_entries& i_modelAgData,
                                 const partialGoodVector& i_pgData);


/**
 * @brief wrapper function to add target info to an error log in a
 *        platform-specific way.
 *
 * @param[io] io_errl             A reference to the error log handle.
 * @param[i]  i_target            A constant pointer to the target to be added
 *                                to the error log.
 */
void hwasErrorAddTargetInfo(errlHndl_t & io_errl,
            const TARGETING::ConstTargetHandle_t i_target);

/**
 * @brief Platform-specific checks for minimum hardware.
 *  Verifies that the system has enough hardware to proceed through
 *  the IPL. If it does not, error log(s) will be created and committed
 *  for each problem.
 *
 * If io_plid is non-zero then any newly created Error Logs use io_plid
 * Else io_plid is updated with the plid used in the newly created Error Logs
 *
 * @param[io] io_plid Reference to plid.
 * @param[in] i_node  node target to restrict hw check
 * @param[out] o_bootable Indicates whether system is bootable with current
 *             configuratio, if a non NULL pointer is passed erros will not
 *             be logged if system cannot ipl and just return a true or false.
 */
void platCheckMinimumHardware(uint32_t & io_plid,
                            const TARGETING::ConstTargetHandle_t i_node = NULL,
                            bool *o_bootable = NULL);

} // namespace HWAS

#endif // HWASCOMMON_H_
