/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/isteps/nvdimm/nvdimm.H $                      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2022                        */
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
#include <runtime/interface.h>

namespace NVDIMM
{

enum nvdimm_err_status
{
    NSTD_VAL_ERASED          = 0x08, // Image erased, SCM device contents not persisted
    NSTD_VAL_ERASED_MASK     = 0xF7,
    NSTD_VAL_RESTORED        = 0x04, // Valid image successfully restored, SCM persisted
    NSTD_VAL_RESTORED_MASK   = 0xFB,
    NSTD_VAL_SR_FAILED       = 0x02, // Save/Restore failed to persist memory contents
    NSTD_VAL_SR_FAILED_MASK  = 0xFD,
    NSTD_VAL_DISARMED        = 0x01, // memory unable to preserve future content
    NSTD_VAL_DISARMED_MASK   = 0xFE,
    NSTD_ERR_VAL_SR          = 0x40, // Partially working. Error detected but save/restore (SR) may still work
    NSTD_ERR_VAL_SR_MASK     = 0xBF,
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
 * @brief Entry function to NVDIMM factory default
 *
 * @param[in] i_nvdimmList - list of nvdimm targets
 *
 * @return true if no errors logged, else false
 */
bool nvdimmFactoryDefault(TARGETING::TargetHandleList &i_nvdimmList);

/**
 * @brief Entry function to NVDIMM secure erase verify
 *
 * @param[in] i_nvdimmList - list of nvdimm targets
 *
 * @return true if no errors logged, else false
 */
bool nvdimmSecureEraseVerifyStart(TARGETING::TargetHandleList &i_nvdimmList);

/**
 * @brief Entry function to NVDIMM secure erase verify status
 *
 * @param[in] i_nvdimmList - list of nvdimm targets
 *
 * @return true if no errors logged, else false
 */
bool nvdimmSecureEraseVerifyStatus(TARGETING::TargetHandleList &i_nvdimmList);

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
 * @return errlHndl_t - nullptr if successful, otherwise a pointer to
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

/**
 * @brief This function arms/disarms the trigger based on i_state
 *
 * @param[in] i_nvdimm - nvdimm target with NV controller
 *
 * @param[in] i_state - true to arm, false to disarm
 *
 * @return errlHndl_t - nullptr if successful, otherwise a pointer to
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
 * @brief Check the ES (enery source)/backup power module(BPM) health status of
 *        the individual NVDIMMs supplied in list
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
 * @param[in] i_nvdimmTargetList - list of NVDIMMs to check the ES health of
 *
 * @return false if one or more NVDIMMs fail ES health check, else true
 */
bool nvDimmEsCheckHealthStatus(const TARGETING::TargetHandleList
                                                        &i_nvdimmTargetList);

/**
 * @brief A wrapper around the call to nvDimmEsCheckHealthStatus
 *
 * @details This will aggregate all the NVDIMMs of the system and pass
 *          them to the call nvDimmEsCheckHealthStatus
 *
 * @see nvDimmEsCheckHealthStatus for more details
 *
 * @return false if one or more NVDIMMs fail an ES health check, else true
 */
bool nvDimmEsCheckHealthStatusOnSystem();


/**
 * @brief Check the NVM (non-volatile memory)/flash health status of the
 *        individual NVDIMMs supplied in list.
 *
 * @details This method will check the flash error count registers
 *          (FLASH_ERROR_COUNT0 to FLASH_ERROR_COUNT2) to determine if the
 *          number of flash error exceeds the maximum allowed.  Will also check
 *          the flash bad block percentage register (FLASH_BAD_BLK_PCT) to
 *          determine if the percentage exceeds the maximum allowed.
 *          If any one of these or both of these fail their perspective
 *          maximums then a callout will be made with either or both failures.
 *
 * @param[in] i_nvdimmTargetList - list of NVDIMMs to check the NVM health of
 *
 * @return false if one or more NVDIMMs fail NVM health check, else true
 */
bool nvDimmNvmCheckHealthStatus(const TARGETING::TargetHandleList
                                                           &i_nvdimmTargetList);

/**
 * @brief A wrapper around the call to nvDimmNvmCheckHealthStatus
 *
 * @details This will aggregate all the NVDIMMs of the system and pass
 *          them to the call nvDimmNvmCheckHealthStatus
 *
 * @see nvDimmNvmCheckHealthStatus for more details
 *
 * @return false if one or more NVDIMMs fail an NVM health check, else true
 */
bool nvDimmNvmCheckHealthStatusOnSystem();


/**
 * @brief Send NV_STATUS to host
 */
void nvdimmSendNvStatus();

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
 *        ENCRYPTION_ENABLED - contents of nvdimm are encrypted
 *        ENCRYPTION_DISABLED - contents of nvdimm are not encrypted
 *        ERASE_VERIFY_STARTED - set secure_erase_verify_complete to 0
 *        ERASE_VERIFY_COMPLETE = set secure_erase_verify_complete to 1
 *        SBE_ACTIVE - set active state
 *        SBE_INACTIVE - set inactive state
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
    ENCRYPTION_ENABLED        = 7,
    ENCRYPTION_DISABLED       = 8,
    ERASE_VERIFY_STARTED      = 9,
    ERASE_VERIFY_COMPLETED    = 10,
    SEND_NV_STATUS            = 11,
    SBE_ACTIVE                = 12,
    SBE_INACTIVE              = 13,
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
 *
 * @return errlHndl_t - nullptr if successful, otherwise a pointer to
 *      the error log.
 */
errlHndl_t notifyNvdimmProtectionChange(TARGETING::Target* i_target,
                                  const nvdimm_protection_t i_state);

/**
 * @brief Get operational unit operation timeout
 *
 * @param[in] i_nvdimm - nvdimm target
 *
 * @param[out] o_timeout - operation timeout
 *
 * @return errlHndl_t - nullptr if successful, otherwise a pointer to
 *      the error log.
 */
errlHndl_t getOperOpsTimeout(TARGETING::Target* i_nvdimm,
                             uint16_t& o_timeout);


/**
 * @brief Wait for operational unit operation to complete
 *
 * @param[in] i_nvdimm - nvdimm target
 *
 * @param[in] i_cmd - operational unit ops command
 *
 * @return errlHndl_t - nullptr if successful, otherwise a pointer to
 *      the error log.
 */
errlHndl_t waitOperOpsComplete(TARGETING::Target* i_nvdimm,
                               uint8_t i_cmd);


/**
 * @brief Get the vendor log unit
 *
 * @param[in] i_nvdimm - nvdimm target
 *
 * @param[in] i_unitId - vendor log unit id
 *
 * @param[out] o_unitData - vendor log unit data
 *
 * @return errlHndl_t - nullptr if successful, otherwise a pointer to
 *      the error log.
 */
errlHndl_t getLogPerUnit(TARGETING::Target* i_nvdimm,
                   uint16_t i_unitId,
                   std::vector<uint8_t>& o_unitData);

/**
 * @brief Calculate host CRC
 *
 * @param[in] i_data - host data
 *
 * @param[in] i_data_size - data size
 *
 * @return crc
 */
uint16_t crc16(const uint8_t * i_data, int i_size);


/**
 * @brief Get operational unit crc
 *
 * @param[in] i_nvdimm - nvdimm target
 *
 * @param[out] o_crc - nvdimm hw crc
 *
 * @return errlHndl_t - nullptr if successful, otherwise a pointer to
 *      the error log.
 */
errlHndl_t getOperUnitCrc(TARGETING::Target* i_nvdimm, uint16_t& o_crc);


/**
 * @brief Compare host and nvdimm checksum
 *
 * @param[in] i_nvdimm - nvdimm target
 *
 * @param[in] i_unitData - data sent to the nvdimm by the host
 *
 * @return errlHndl_t - nullptr if successful, otherwise a pointer to
 *      the error log.
 */
errlHndl_t compareCksum(TARGETING::Target* i_nvdimm,
                        std::vector<uint8_t>& i_unitData);


/**
 * @brief Function to add NVDIMM vendor log data to errorlog FFDC
 *
 * @param[in] i_nvdimm - nvdimm target
 *
 * @param[inout] io_err - error log to add FFDC data.  Must not be nullptr
 *
 */
void nvdimmAddVendorLog(TARGETING::Target *i_nvdimm, errlHndl_t& io_err);


/**
 * @brief Add NVDIMM Update regs to FFDC for errors encountered
 *          during NVDIMM firmware update process
 *        Regs specified in NVDIMM IPL Error Handling Document
 *
 * @param[in] i_nvdimm - nvdimm target
 *
 * @param[in] io_err - error log to add FFDC data. Must not be nullptr
 *
 */
void nvdimmAddUpdateRegs(TARGETING::Target *i_nvdimm, errlHndl_t& io_err);


/**
 * @brief Function to add some NVDIMM Page 4 status regs to errorlog FFDC
 *        PANIC_CNT                  Counts FPGA firmware events
 *        PARITY_ERROR_COUNT         Counts FPGA SRAM parity errors
 *        FLASH_ERROR_COUNT0         Counts FLASH read/write errors
 *        FLASH_ERROR_COUNT1
 *        FLASH_ERROR_COUNT2
 *        FLASH_BAD_BLOCK_COUNT0     Counts bad blocks within the flash array
 *        FLASH_BAD_BLOCK_COUNT1
 *        SCAP_STATUS                BackupPowerModule/SuperCap state
 *        STATUS_EVENT_INT_INFO1     NVDIMM error info
 *        STATUS_EVENT_INT_INFO2
 *
 * @param[in] i_nvdimm - nvdimm target
 *
 * @param[inout] io_err - error log to add FFDC data. Must not be nullptr
 *
 */
void nvdimmAddPage4Regs(TARGETING::Target *i_nvdimm, errlHndl_t& io_err);


/**
 * @brief Entry function to NVDIMM initialization
 *        - Checks for ready state
 *        - Waits for the ongoing backup to complete
 *        - Disarms the trigger for draminit
 * @param i_target     nvdimm target
 */
void nvdimm_init(TARGETING::Target *i_nvdimm);

#ifdef __HOSTBOOT_RUNTIME
/**
 * @brief Collect the Lifetime Percentage from the BPM for every NVDIMM
 *        and send it to PHYP
 */
void nvdimm_stats( void );
#endif

}

#endif  // NVDIMM_EXT_H__

