/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/isteps/nvdimm/nvdimm.H $                      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2019                        */
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
    NSTD_VAL_ERASED          = 0x08, // Image erased, SCM device contents not persisted
    NSTD_VAL_ERASED_MASK     = 0xF7,
    NSTD_VAL_ERROR           = 0x04, // Valid image successfully restored, SCM persisted
    NSTD_VAL_ERROR_MASK      = 0xFB,
    NSTD_VAL_SR_FAILED       = 0x02, // Save/Restore failed to persist memory contents
    NSTD_VAL_SR_FAILED_MASK  = 0xFD,
    NSTD_VAL_DISARMED        = 0x01, // memory unable to preserve future content
    NSTD_VAL_DISARMED_MASK   = 0xFE,
    NSTD_ERR                 = 0x03, // NSTD_ERR_NOPRSV+NSTD_ERR_NOBKUP
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
errlHndl_t nvdimm_restore(TARGETING::TargetHandleList &i_nvdimmList);


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


/**
 * @brief Entry function to set NVDIMM thresholds
 *
 * @param[in] i_nvdimmList - list of nvdimm targets
 *
 **/
void nvdimm_thresholds(TARGETING::TargetHandleList &i_nvdimmList);


#endif


/**
 * @brief Entry function to NVDIMM unlock encryption
 *
 * @param[in] i_nvdimmList - list of nvdimm targets
 *
 * @return true if no errors logged, else false
 */
bool nvdimm_encrypt_unlock(TARGETING::TargetHandleList &i_nvdimmList);


/**
 * @brief Entry function to NVDIMM generate keys
 *        Generate encryption keys and set the FW key attribute
 *
 * @return true if no errors logged, else false
 */
bool nvdimm_gen_keys(void);

/**
 * @brief Entry function to NVDIMM remove keys
 *        Set the FW key attribute = 0
 *        Tell HWSV to clear anchor key attribute
 *
 * @return true if no errors logged, else false
 */
bool nvdimm_remove_keys(void);

/**
 * @brief Entry function to NVDIMM enable encryption
 *
 * @param[in] i_nvdimmList - list of nvdimm targets
 *
 * @return true if no errors logged, else false
 */
bool nvdimm_encrypt_enable(TARGETING::TargetHandleList &i_nvdimmList);

/**
 * @brief Entry function to NVDIMM crypto erase
 *
 * @param[in] i_nvdimmList - list of nvdimm targets
 *
 * @return true if no errors logged, else false
 */
bool nvdimm_crypto_erase(TARGETING::TargetHandleList &i_nvdimmList);

/**
 * @brief Helper function to get list of nvdimm target pointers
 *
 * @param[out] o_nvdimmList - list of nvdimm targets
 *
 */
void nvdimm_getNvdimmList(TARGETING::TargetHandleList &o_nvdimmList);

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
 * @brief  Disarms the trigger to enable backup in the event of a
 *         power loss on each NVDIMM
 *
 * @param[in] i_nvdimmTargetList : list of dimms that are NVDIMMs
 * @return true if no errors logged, else false
 */
bool nvdimmDisarm(TARGETING::TargetHandleList &i_nvdimmTargetList);

/**
 * @brief Check the health status of the individual NVDIMMs supplied in list
 *
 * @details The BPM will trigger the health check when power is applied at the
 *          beginning of the IPL, with results ready to check about 20 mins
 *          later. It is the caller's responsibility to ensure enough time has
 *          passed to make this call.
 *          Excerpt from the Jedec Standard, Byte Addressable Energy Backed
 *          Interface of the interested flags (bits 0 .. 2).
 *          ES_CMD_STATUS0
 *              Bit 0 : Health Check in Progress
 *              Bit 1 : Health Check Succeeded
 *              Bit 2 : Health Check Failed
 *
 * @param[in] i_nvdimmTargetList - list of NVDIMMs to check the health of
 *
 * @return false if one or more NVDIMMs fail health check, else true
 */
bool nvDimmCheckHealthStatus(TARGETING::TargetHandleList &i_nvdimmTargetList);

/**
 * @brief A wrapper around the call to nvDimmCheckHealthStatus
 *
 * @details This will aggregate all the NVDIMMs of the system and pass
 *          them to the call nvDimmCheckHealthStatus
 *
 * @see nvDimmCheckHealthStatus for more details
 *
 * @return false if one or more NVDIMMs fail health check, else true
 */
bool nvDimmCheckHealthStatusOnSystem();


#endif

/**
 * @brief NVDIMM protection state
 *
 *        NVDIMM_ARMED - set armed state
 *        NVDIMM_DISARMED - set disarmed state
 *        OCC_ACTIVE - set active state
 *        OCC_INACTIVE - set inactive state
 *        NVDIMM_FATAL_HW_ERROR - set fatal hw state
 *        NVDIMM_RISKY_HW_ERROR - set risky hw state
 *        NVDIMM_ENCRYPTION_ERROR - set encryption state
 *          Note: fatal error will stay with target preventing
 *                PROTECTED status until power is cycled again
 */
enum nvdimm_protection_t
{
    NVDIMM_ARMED              = 0,
    NVDIMM_DISARMED           = 1,
    OCC_ACTIVE                = 2,
    OCC_INACTIVE              = 3,
    NVDIMM_FATAL_HW_ERROR     = 4,
    NVDIMM_RISKY_HW_ERROR     = 5,
    NVDIMM_ENCRYPTION_ERROR   = 6,
    /* deprecated, still used by PRD */
    UNPROTECTED_BECAUSE_ERROR = 4,
};

/**
 * @brief Notify PHYP of NVDIMM protection status
 *
 * @param i_target     Processor with NVDIMM or NVDIMM itself
 *                      - ARMED state updated per NVDIMM
 *                      - ERROR states updated per NVDIMM
 *                      - OCC state updated per PROC
 * @param i_state      Protection state of NVDIMM
 */
errlHndl_t notifyNvdimmProtectionChange(TARGETING::Target* i_target,
                                  const nvdimm_protection_t i_state);

/**
 * @brief Entry function to NVDIMM initialization
 *        - Checks for ready state
 *        - Waits for the ongoing backup to complete
 *        - Disarms the trigger for draminit
 * @param i_target     nvdimm target
 */
errlHndl_t nvdimm_init(TARGETING::Target *i_nvdimm);

}

#endif  // NVDIMM_EXT_H__

