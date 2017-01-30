/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/secureboot/drtm.H $                           */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2017                        */
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

#ifndef __SECUREBOOT_DRTM_H
#define __SECUREBOOT_DRTM_H

#include <initservice/mboxRegs.H>
#include <config.h>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <vector>
#include <secureboot/settings.H>
#include <targeting/common/targetservice.H>

namespace SECUREBOOT
{

namespace DRTM
{

/**
 *  @brief Determine HW DRTM state and cache for code to use
 *
 *  @par Detailed Description:
 *      Reads DRTM related scratch registers, attributes, and proc chip security
 *      settings to determine the DRTM state, and caches DRTM settings in
 *      attributes for use by the code.  It will return an error log if a DRTM
 *      consistency violation is detected.
 *
 *  @param[in] i_scratchReg7 Value of scratch register 7
 *  @param[in] i_scratchReg8 Value of scratch register 8
 *
 *  @return errHndl_t Error log handle indicating success or failure
 *  @retval nullptr Discovered/configured DRTM state successfully
 *  @retval !nullptr Error log providing failure details
 */
errlHndl_t discoverDrtmState(
    const INITSERVICE::SPLESS::MboxScratch7_t& i_scratchReg7,
    const INITSERVICE::SPLESS::MboxScratch8_t& i_scratchReg8);

/**
 *  @brief Returns whether this is a DRTM MPIPL or not
 *
 *  @param[out] o_isDrtmMpipl Returns whether this is a DRTM MPIPL or not
 */
void isDrtmMpipl(bool& o_isDrtmMpipl);

/**
 *  @brief Determines whether DRTM HW settings are consistent across all
 *      processors in a node
 *
 *  @par Detailed Description:
 *      Ensures that, when coming up in a DRTM MPIPL, the L4A, LQA, and SUL bits
 *      are set + LLP and LLS are clear in the processor security register for
 *      all processors in a node. If this is not the case, it returns an error
 *      log. Must only be called after FSI path is established and presence
 *      detect has been confirmed.
 *
 *  @return errHndl_t Error log handle indicating success or failure
 *  @retval nullptr All processors in node have correct DRTM HW signature
 *  @retval !nullptr Error log providing failure details
 */
errlHndl_t validateDrtmHwSignature();

/**
 *  @brief Validates and extends the DRTM payload
 *
 *  @par Detailed Description:
 *      When coming up in a DRTM MPIPL, locates the DRTM payload preserved in
 *      memory, validates its secure signature, and extends its measurement to
 *      TPM dynamic PCR range / dynamic log.
 *
 *  @return errHndl_t Error log handle indicating success or failure
 *  @retval nullptr Validated/extended the DRTM payload
 *  @retval !nullptr Error log providing failure details
 */
errlHndl_t validateDrtmPayload();

/**
 *  @brief Completes the DRTM sequence
 *
 *  @par Detailed Description:
 *      Completes the DRTM sequence by clearing the LQA and L4A security switch
 *      register bits on all the functional processors
 *
 *  @return errHndl_t Error log handle indicating success or failure
 *  @retval nullptr Completed DRTM HW sequencing
 *  @retval !nullptr Error log providing failure details
 */
errlHndl_t completeDrtm();

#ifdef CONFIG_DRTM_TRIGGERING
/**
 *  @brief Initiates a DRTM sequence
 *
 *  @par Detailed Description:
 *      Initiates a DRTM sequence.  This pins the task running this code to the
 *      master processor and sets the LLP bit (for master proc chip) and LLS bit
 *      (for non-masters) on every processor, setting the LL bit for the
 *      processor this task is running on last, so that it doesn't get clobbered
 *      by the SBE core quiesce logic.  It also sets up the master processor
 *      scratch registers to indicate presence and address of the DRTM payload.
 *      If successful, the function will never return becaue the core it's
 *      running on will be quiesced by SBE.
 *
 *  @note: Only valid for RIT protection
 *
 *  @return errHndl_t Error log handle indicating success or failure
 *  @retval nullptr Not possible; on success the function never returns.
 *  @retval !nullptr Error log providing failure details
 */
errlHndl_t initiateDrtm();

/**
 *  @brief Updates DRTM related scratch registers with DRTM payload details
 *
 *  @par Detailed Description:
 *      Updates scratch register 7+8 to record details of the DRTM payload
 *      preserved in memory. This should be called prior to initiating the
 *      DRTM late launch sequence.
 *
 *  @note: Only valid for RIT protection
 *
 *  @param[in] i_drtmPayloadAddrMb DRTM payload physical address in MB
 */
void setDrtmPayloadPhysAddrMb(uint32_t i_drtmPayloadPhysAddrMb);
#endif

} // End DRTM namespace

} // End SECUREBOOT namespace

#endif // End __SECUREBOOT_DRTM_H

