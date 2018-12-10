/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/isteps/nvdimm/nvdimm.H $                      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018                             */
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
#ifndef NVDIMM_EXT_H__
#define NVDIMM_EXT_H__

#include <targeting/common/util.H>

namespace NVDIMM
{
enum nvdimm_err_status
{
    NSTD_VAL_NOPRSV      = 0x08, // memory valid, contents not preserved (genesis)
    NSTD_VAL_NOPRSV_MASK = 0xF7,
    NSTD_VAL_PRSV        = 0x04, // memory contents preserved
    NSTD_VAL_PRSV_MASK   = 0xFB,
    NSTD_ERR_NOPRSV      = 0x02, // memory failed to preserve contents
    NSTD_ERR_NOPRSV_MASK = 0xFD,
    NSTD_ERR_NOBKUP      = 0x01, // memory unable to preserve future content
    NSTD_ERR_NOBKUP_MASK = 0xFE,
    NSTD_ERR             = 0x03, // NSTD_ERR_NOPRSV+NSTD_ERR_NOBKUP
};

#ifndef __HOSTBOOT_RUNTIME
/**
 * @brief Entry function to NVDIMM management
 *        - Restore image from NVDIMM NAND flash to DRAM
 *        - Arms the backup trigger to ddr_reset_n once the restore
 *          is completed
 *        - Erase image
 *
 * @param[in] i_nvdimmList - list of nvdimm targets
 *
 **/
void nvdimm_restore(TARGETING::TargetHandleList &i_nvdimmList);


/**
 * @brief Entry function for updating NV controller code on the NVDIMMs
 *        Each nvdimm will be checked for a possible update.  The update
 *        will be performed if the dimm is a known type and its version level
 *        does not match its corresponding lid's version level.
 *
 * @param[in] i_nvdimmList - list of nvdimm targets
 *
 * @return true if no errors were logged, else false
 *
 **/
bool nvdimm_update(TARGETING::TargetHandleList &i_nvdimmList);

#endif


/**
 * @brief This function erases image on the nvdimm target
 *
 * @param[in] i_nvdimm - nvdimm target with NV controller
 *
 * @return errlHndl_t - Null if successful, otherwise a pointer to
 *      the error log.
 */
errlHndl_t nvdimmEraseNF(TARGETING::Target *i_nvdimm);

/**
 * @brief Set the status flag
 *
 * @param[in] i_nvdimm - nvdimm target
 *
 * @param[in] i_status_flag - status flag to set for each nvdimm
 *
 */
void nvdimmSetStatusFlag(TARGETING::Target *i_nvdimm, const uint8_t i_status_flag);

#ifdef __HOSTBOOT_RUNTIME

/**
 * @brief Check nvdimm error state
 *
 * @param[in] i_nvdimm - nvdimm target
 *
 * @return bool - true if nvdimm is in any error state, false otherwise
 */
bool nvdimmInErrorState(TARGETING::Target *i_nvdimm);

/**
 * @brief This function arms/disarms the trigger based on i_state
 *
 * @param[in] i_nvdimm - nvdimm target with NV controller
 *
 * @param[in] i_state - true to arm, false to disarm
 *
 * @return errlHndl_t - Null if successful, otherwise a pointer to
 *      the error log.
 */
errlHndl_t nvdimmChangeArmState(TARGETING::Target *i_nvdimm, bool i_state);

/**
 * @brief  Arms the trigger to enable backup in the event of a power loss
 *         on each NVDIMM
 *
 *    The trigger (DDR_RESETN to the DIMM) is used to tell the NVDIMM
 *    that we have an EPOW event, so the NV controller can backup the
 *    data from the DRAM to flash.  This will enable the NV controller
 *    to react when it sees the trigger toggles.
 *
 * @param[in] i_nvdimmTargetList : list of dimms that are NVDIMMs
 * @return true if no errors logged, else false
 */
bool nvdimmArm(TARGETING::TargetHandleList &i_nvdimmTargetList);

/**
 * @brief NVDIMM protection state
 *
 *        NOT_PROTECTED - default state
 *        PROTECTED - switches to this when armed & OCC is in control
 *        UNPROTECTED_BECAUSE_ERROR - PRD detected error on NV controller
 *          Note: error will stay with target preventing PROTECTED status
 *                until power is cycled again
 */
enum nvdimm_protection_t
{
    NOT_PROTECTED             = 0,
    PROTECTED                 = 1,
    UNPROTECTED_BECAUSE_ERROR = 2
};

/**
 * @brief Notify PHYP of NVDIMM protection status
 *
 * @param i_target     Processor with NVDIMM
 * @param i_state      Protection state of NVDIMM
 */
errlHndl_t notifyNvdimmProtectionChange(TARGETING::Target* i_target,
                                  const nvdimm_protection_t i_state);
#endif
/**
 * @brief Entry function to NVDIMM initialization
 *        - Checks for ready state
 *        - Waits for the ongoing backup to complete
 *        - Disarms the trigger for draminit
 * @param i_target     nvdimm target
 */
void nvdimm_init(TARGETING::Target *i_nvdimm);

}

#endif  // NVDIMM_EXT_H__

