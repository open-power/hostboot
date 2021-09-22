/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/isteps/istep_reasoncodes.H $                  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2021                        */
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
#ifndef _ISTEP_REASONCODES_H_
#define _ISTEP_REASONCODES_H_

/**
 * @file    istep_reasoncodes.H
 *
 *  Define the module IDs and reason codes for ISTEP error logs.
 *
 */

#include <hbotcompid.H>
namespace ISTEP
{
    /**
     * @brief Defines the ISTEP error log module IDs
     */
    enum istepModuleId
    {
        MOD_INVALID_MODULE                                = 0x00,
        MOD_REPORTING_ERROR                               = 0x01,
        MOD_START_PAYLOAD_CALL_SHUTDOWN                   = 0x02,
        MOD_HOST_ACTIVATE_SECONDARY_CORES                 = 0x03,
        MOD_BUILD_HCODE_IMAGES                            = 0x04,
        MOD_PROC_SET_PORE_BAR                             = 0x05,
        MOD_HOST_ACTIVATE_BOOT_CORE                       = 0x06,
        // 0x07 Unused
        MOD_ENABLE_CORE_CHECKSTOPS                        = 0x08,
        MOD_DECONFIG_PHBS_BASED_ON_PCI_STATE              = 0x09,
        MOD_COMPUTE_PCIE_CONFIG_ATTRS                     = 0x0A,
        MOD_EXIT_CACHE_CONTAINED                          = 0x0B,
        MOD_HOST_GARD                                     = 0x0C,
        MOD_EDI_EI_IO_RUN_TRAINING                        = 0x0D,
        MOD_LOAD_PAYLOAD                                  = 0x0E,
        MOD_GET_CACHE_DECONFIG                            = 0x0F,
        MOD_THREAD_ACTIVATE                               = 0x10,
        MOD_CHECK_SECONDARY_SBE_SEEPROM_COMPLETE          = 0x11,
        MOD_PM_LOAD_HOST_DATA_TO_SRAM                     = 0x12,
        MOD_VOLTAGE_CONFIG                                = 0x13,
        MOD_PM_VERIFY_OCC_CHKPT                           = 0x14,
        MOD_VALIDATE_SECURITY_SETTINGS                    = 0x15,
        MOD_PROC_EXIT_CACHE_CONTAINED                     = 0x16,
        MOD_CALL_MSS_ATTR_UPDATE                          = 0x1A,
        MOD_SET_IPL_PARMS                                 = 0x1D,
        MOD_OCC_XSTOP_HANDLER                             = 0x1E,
        MOD_REDISCOVER_I2C_TARGETS                        = 0x20,
        MOD_FREQ_ATTR_DATA                                = 0x21,
        MOD_SMP_WRAP_PROC_IOVALID                         = 0x22,
        MOD_APPLY_HCODE_GEN_CPU_REGS                      = 0x23,
        MOD_GET_LANEMASK_FROM_HX_KEYWORD                  = 0x24,
        MOD_MSS_SCRUB                                     = 0x25,
        MOD_CALL_UPDATE_UCD_FLASH                         = 0x26,
        MOD_LOAD_HCODE                                    = 0x27,
        MOD_GET_OMI_FREQ                                  = 0x28,
        MOD_DISCOVER_TARGETS                              = 0x29,
        MOD_MSS_GETECID                                   = 0x30,
        MOD_START_PM_COMPLEX                              = 0x31,
        MOD_RESET_PM_COMPLEX                              = 0x32,
        MOD_SCOPED_HOMER_MAPPER_MAP                       = 0x33,
        MOD_SCOPED_HOMER_MAPPER_UNMAP                     = 0x34,
        MOD_GET_RUNTIME_PM_ADDRESSES                      = 0x35,
        MOD_ENABLE_MEMORY_ENCRYPTION                      = 0x36,
        MOD_SECUREBOOT_LOCKDOWN                           = 0x37,
        MOD_RECOVER_SBE                                   = 0x38,
        MOD_RETRIEVE_EXTEND_SECONDARY_MEASUREMENTS        = 0x39,
        MOD_CALL_HOST_SECUREBOOT_LOCKDOWN                 = 0x3A,
        MOD_WAIT_FOR_SBE_ATTN                             = 0x3B,
        MOD_CHECK_FOR_SECURITY_ACCESS_MISMATCH            = 0x3C,
        MOD_MONITOR_SBE_HALT                              = 0x3D,
        MOD_BIOS_ATTR_PARSERS                             = 0x3F,
    };

    /**
     * @brief Defines the ISTEP error log reason codes
     */
    enum istepReasonCode
    {
        RC_NO_MIRRORED_MEMORY                    = ISTEP_COMP_ID | 0x00,
        RC_MM_EXTEND_FAILED                      = ISTEP_COMP_ID | 0x01,
        RC_INVALID_REASONCODE                    = ISTEP_COMP_ID | 0x02,
        RC_FAILURE                               = ISTEP_COMP_ID | 0x03,
        RC_TARGET_NULL                           = ISTEP_COMP_ID | 0x04,
        RC_BAD_RC                                = ISTEP_COMP_ID | 0x05,
        RC_FAIL_BOOT_CORE_WINKLE                 = ISTEP_COMP_ID | 0x06,
        RC_MM_UNMAP_ERR                          = ISTEP_COMP_ID | 0x07,
        RC_LOAD_HCODE_FROM_PNOR_FAILED           = ISTEP_COMP_ID | 0x08,
        RC_REPAIR_LOADER_RETRY_OCCURED           = ISTEP_COMP_ID | 0x09,
        RC_MM_MAP_ERR                            = ISTEP_COMP_ID | 0x0A,
        RC_INCORRECT_TARGET_COUNT                = ISTEP_COMP_ID | 0x0B,
        RC_INVALID_TARGET_TYPE                   = ISTEP_COMP_ID | 0x0C,
        RC_INVALID_ATTR_VALUE                    = ISTEP_COMP_ID | 0x0D,
        RC_INVALID_CONFIGURATION                 = ISTEP_COMP_ID | 0x0E,
        RC_INVALID_PCIE_IOP_LANE_CONFIG          = ISTEP_COMP_ID | 0x0F,
        RC_MASTER_CORE_NULL                      = ISTEP_COMP_ID | 0x10,
        RC_MIXED_PBUS_CONNECTION                 = ISTEP_COMP_ID | 0x11,
        RC_SAME_CHIP_PBUS_CONNECTION             = ISTEP_COMP_ID | 0x12,
        RC_CONFLICT_PBUS_CONNECTION              = ISTEP_COMP_ID | 0x13,
        RC_INVALID_RECORD                        = ISTEP_COMP_ID | 0x14,
        RC_INCORRECT_KEWORD_SIZE                 = ISTEP_COMP_ID | 0x15,
        RC_NO_MASTER_CORE_TARGET                 = ISTEP_COMP_ID | 0x16,
        RC_ECMD_INSERT_FAILED                    = ISTEP_COMP_ID | 0x18,
        RC_NO_FUNCTIONAL_PROCS                   = ISTEP_COMP_ID | 0x19,
        RC_NO_PRESENT_EQS                        = ISTEP_COMP_ID | 0x1A,
        RC_NOMINAL_FREQ_MISMATCH                 = ISTEP_COMP_ID | 0x1B,
        RC_PM_OCC_CHKPT_TIMEOUT                  = ISTEP_COMP_ID | 0x1C,
        RC_UPDATE_SECURITY_CTRL_HWP_FAIL         = ISTEP_COMP_ID | 0x1D,
        RC_NO_FUNCTIONAL_MEMORY                  = ISTEP_COMP_ID | 0x1E,
        RC_NO_FUSED_CORE_TARGET                  = ISTEP_COMP_ID | 0x1F,
        RC_POWER_MODE_MISMATCH                   = ISTEP_COMP_ID | 0x20,
        RC_PRIMARY_PROC_SBE_KEYS_HASH_MISMATCH   = ISTEP_COMP_ID | 0x21,
        RC_PRIMARY_PROC_PRIMARY_HASH_READ_FAIL   = ISTEP_COMP_ID | 0x22,
        RC_PRIMARY_PROC_BACKUP_HASH_READ_FAIL    = ISTEP_COMP_ID | 0x23,
        RC_PRIMARY_PROC_CBS_CONTROL_READ_FAIL    = ISTEP_COMP_ID | 0x24,
        RC_SECONDARY_PROC_PRIMARY_HASH_READ_FAIL = ISTEP_COMP_ID | 0x25,
        RC_SECONDARY_PROC_BACKUP_HASH_READ_FAIL  = ISTEP_COMP_ID | 0x26,
        RC_SECONDARY_PROC_CBS_CONTROL_READ_FAIL  = ISTEP_COMP_ID | 0x27,
        RC_PROC_SECURITY_STATE_MISMATCH          = ISTEP_COMP_ID | 0x28,
        RC_MIN_HW_CHECK_FAILED                   = ISTEP_COMP_ID | 0x29,
        RC_PROC_EXTRACT_SBE_MAIN_ERROR           = ISTEP_COMP_ID | 0x30,
        RC_SBE_UPDATE_IN_MPIPL                   = ISTEP_COMP_ID | 0x32,
        RC_NO_FFDC_RETURNED                      = ISTEP_COMP_ID | 0x33,
        RC_P9N_DD1_NOT_SUPPORTED                 = ISTEP_COMP_ID | 0x35,
        RC_PREVENT_REBOOT_IN_MFG_TERM_MODE       = ISTEP_COMP_ID | 0x36,
        RC_FAILED_WRITE_SPR                      = ISTEP_COMP_ID | 0x37,
        RC_FAILED_TO_BOOT_SBE                    = ISTEP_COMP_ID | 0x38,
        RC_REDISCOVERED_TARGETS                  = ISTEP_COMP_ID | 0x39,
        RC_HDAT_SIZE_CHECK_FAILED                = ISTEP_COMP_ID | 0x3A,
        RC_FREQ_ATTR_TIMER_EXPIRED               = ISTEP_COMP_ID | 0x40,
        RC_FREQ_ATTR_TIMER_THREAD_FAIL           = ISTEP_COMP_ID | 0x41,
        RC_FLOOR_FREQ_MISMATCH                   = ISTEP_COMP_ID | 0x42,
        RC_CEIL_FREQ_MISMATCH                    = ISTEP_COMP_ID | 0x43,
        RC_TURBO_FREQ_MISMATCH                   = ISTEP_COMP_ID | 0x44,
        RC_ULTRA_TURBO_FREQ_MISMATCH             = ISTEP_COMP_ID | 0x45,
        RC_NEST_FREQ_MISMATCH                    = ISTEP_COMP_ID | 0x46,
        RC_NO_VALID_MEM_CONFIG                   = ISTEP_COMP_ID | 0x47,
        RC_PRIMARY_GET_SBE_BOOT_SEEPROM_FAIL     = ISTEP_COMP_ID | 0x48,
        RC_SECONDARY_GET_SBE_BOOT_SEEPROM_FAIL   = ISTEP_COMP_ID | 0x49,
        RC_LINK_TRAIN_ERRORS_FROM_HWP            = ISTEP_COMP_ID | 0x4A,
        RC_RISK_LEVEL_TOO_LOW                    = ISTEP_COMP_ID | 0x4B,
        RC_INVALID_HX_KEYWORD_DATA               = ISTEP_COMP_ID | 0x4C,
        RC_PNOR_IPMI_NOT_ENABLED                 = ISTEP_COMP_ID | 0x4D,
        RC_SECONDARY_CORE_WAKEUP_ERROR           = ISTEP_COMP_ID | 0x4E,
        RC_UCD_IMG_NOT_IN_CONTAINER              = ISTEP_COMP_ID | 0x4F,
        RC_MM_UNMAP_FAILED                       = ISTEP_COMP_ID | 0x50,
        RC_OMI_FREQ_MISMATCH                     = ISTEP_COMP_ID | 0x51,
        RC_SBE_UPDATE_UNEXPECTEDLY_FAILED        = ISTEP_COMP_ID | 0x52,
        RC_INVALID_OCMB_CHIP_ID                  = ISTEP_COMP_ID | 0x53,
        RC_INVALID_HOMER_VADDR                   = ISTEP_COMP_ID | 0x54,
        RC_PM_COMPLEX_ADDRESSES_NOT_FOUND        = ISTEP_COMP_ID | 0x55,
        RC_BAD_INTERFACE_RETURN_CODE             = ISTEP_COMP_ID | 0x56,
        RC_COULD_NOT_MAP_HOMER                   = ISTEP_COMP_ID | 0x57,
        RC_COULD_NOT_UNMAP_HOMER                 = ISTEP_COMP_ID | 0x58,
        RC_INVALID_PM_ADDRESS                    = ISTEP_COMP_ID | 0x59,
        RC_SCRATCH_REG_ATTR_MISMATCH             = ISTEP_COMP_ID | 0x5A,
        RC_PRESENCE_MISMATCH_HB                  = ISTEP_COMP_ID | 0x5B,
        RC_PRESENCE_MISMATCH_SP                  = ISTEP_COMP_ID | 0x5C,
        RC_PRIMARY_PROC_SECURE_VERSION_MISMATCH  = ISTEP_COMP_ID | 0x5D,
        RC_MEMCRYPT_KEY_SETUP_FAILED             = ISTEP_COMP_ID | 0x5E,
        RC_MEMCRYPT_LOCK_FAILED                  = ISTEP_COMP_ID | 0x5F,
        RC_RNG_FAILED                            = ISTEP_COMP_ID | 0x60,
        RC_MEMORY_ENCRYPTION_ENABLED             = ISTEP_COMP_ID | 0x61,
        RC_INVALID_PAYLOAD_KIND                  = ISTEP_COMP_ID | 0x62,
        RC_SBE_REPORTED_FFDC                     = ISTEP_COMP_ID | 0x63,
        RC_FAILED_SBE_HRESET                     = ISTEP_COMP_ID | 0x64,
        RC_PCR6_MISMATCH_DETECTED                = ISTEP_COMP_ID | 0x65,
        RC_SBE_COMPROMISED                       = ISTEP_COMP_ID | 0x66,
        RC_WAIT_ATTN_TIMEOUT                     = ISTEP_COMP_ID | 0x67,
        RC_SAB_MISMATCH_DETECTED                 = ISTEP_COMP_ID | 0x68,
        RC_ERROR_READING_HUGE_PAGE_COUNT         = ISTEP_COMP_ID | 0x69,
        RC_ERROR_READING_LMB_SIZE                = ISTEP_COMP_ID | 0x6A,
        RC_INVALID_BOOTSIDE                      = ISTEP_COMP_ID | 0x6B,
        RC_UNHALTED_SBE                          = ISTEP_COMP_ID | 0x6C,
    };

};

#endif
