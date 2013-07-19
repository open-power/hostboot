/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/hwpf/istepreasoncodes.H $                     */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2013              */
/*                                                                        */
/* p1                                                                     */
/*                                                                        */
/* Object Code Only (OCO) source materials                                */
/* Licensed Internal Code Source Materials                                */
/* IBM HostBoot Licensed Internal Code                                    */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* Origin: 30                                                             */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
/**
 * @file istepreasoncodes.H
 *
 * @brief Reason codes and module ids for the isteps
 *
 */
#ifndef __ISTEPREASONCODES_H
#define __ISTEPREASONCODES_H
// -----------------------------------------------
// Includes
// -----------------------------------------------
#include <hbotcompid.H>

namespace ISTEP
{

/**
* @enum istepModuleid
*
* @brief Module Ids used in created errorlogs.  Indicates which
*      functions an error log was created in.
*
*/
enum istepModuleId
{
    ISTEP_INVALID_MODULE                                = 0x00,
    ISTEP_STARTPAYLOAD_EXECUTE_UNIT_TESTS               = 0x01,
    ISTEP_START_PAYLOAD_CALL_SHUTDOWN                   = 0x02,
    ISTEP_START_PAYLOAD_NOTIFY_FSP                      = 0x03,
    ISTEP_HOST_ACTIVATE_SLAVE_CORES                     = 0x04,
    ISTEP_BUILD_WINKLE_IMAGES                           = 0x05,
    ISTEP_PROC_STARTCLOCK_CHIPLETS                      = 0x06,
    ISTEP_PROC_CHIPLET_SCOMINIT                         = 0x07,
    ISTEP_PROC_SCOMOVERRIDE_CHIPLETS                    = 0x08,
    ISTEP_FABRIC_IO_RUN_TRAINING                        = 0x09,
    ISTEP_PROC_FAB_IOVALID                              = 0x0a,
    ISTEP_PROC_BUILD_SMP                                = 0x0b,
    ISTEP_MSS_MEMDIAG                                   = 0x0c,
    ISTEP_MSS_SCRUB                                     = 0x0d,
    ISTEP_HOST_BUILD_WINKLE                             = 0x0e,
    ISTEP_IO_RUN_TRAINING                               = 0x0f,
    ISTEP_PROC_CEN_FRAMEWORK                            = 0x10,
    ISTEP_MEM_STARTCLOCKS                               = 0x11,
    ISTEP_PROC_SET_PORE_BAR                             = 0x12,
    ISTEP_PROC_PREP_MASTER_WINKLE                       = 0x13,
    ISTEP_HOST_ACTIVATE_MASTER                          = 0x14,
    ISTEP_PROC_SETUP_BARS                               = 0x15,
    ISTEP_PROC_EXIT_CACHE_CONTAINED                     = 0x16,
    ISTEP_MSS_EXTENT_SETUP                              = 0x17,
    ISTEP_MSS_SETUP_BARS                                = 0x18,
    ISTEP_MSS_SCOMINIT                                  = 0x19,
    ISTEP_MSS_DDR_PHY_RESET                             = 0x1a,
    ISTEP_MSS_DRAMINIT                                  = 0x1b,
    ISTEP_MSS_DRAMINIT_TRAINING                         = 0x1c,
    ISTEP_MSS_DRAMINIT_MC                               = 0x1d,
    ISTEP_HOST_COLLECT_DIMM_SPD                         = 0x1e,
    ISTEP_MSS_FREQ                                      = 0x1f,
    ISTEP_MSS_EFF_CONFIG                                = 0x20,
    ISTEP_SBE_CENTAUR_INIT                              = 0x21,
    ISTEP_PROC_REVERT_SBE_MCS_SETUP                     = 0x22,
    ISTEP_HOST_IPL_COMPLETE                             = 0x23,
    ISTEP_PROC_A_X_PCI_DMI_PLL_INITF                    = 0x24,
    ISTEP_PROC_A_X_PCI_DMI_PLL_SETUP                    = 0x25,
    ISTEP_PROC_FAPI_POREVE                              = 0x26,
    ISTEP_PROC_CEN_FRAMELOCK                            = 0x27,
    ISTEP_DMI_SCOMINIT                                  = 0x28,
    ISTEP_DMI_IO_RUN_TRAINING                           = 0x29,
    ISTEP_PROC_OPT_MEMMAP                               = 0x2a,
    ISTEP_MEM_PLL_SETUP                                 = 0x2b,
    ISTEP_PROC_SLW_BUILD                                = 0x2c,
    ISTEP_PROC_FAB_IOVALID_EROR                         = 0x2d,
    ISTEP_LOAD_PORE_IMAGE                               = 0x2e,
    ISTEP_APPLY_PORE_GEN_CPU_REGS                       = 0x2f,
    ISTEP_PROC_PORESLW_INIT                             = 0x30,
    ISTEP_HOST_RUNTIME_SETUP                            = 0x31,
    ISTEP_HOST_VERIFY_HDAT                              = 0x32,
    ISTEP_HOST_START_PAYLOAD                            = 0x33,
    ISTEP_PROC_CHECK_SLAVE_SBE_SEEPROM_COMPLETE         = 0x34,
    ISTEP_PROC_PCIE_SCOMINIT                            = 0x35,
    ISTEP_PROC_PCIE_CONFIG                              = 0x36,
    ISTEP_HOST_MPIPL_SERVICE                            = 0x37,
    ISTEP_PROC_CEN_SET_INBAND_ADDR                      = 0x38,
    ISTEP_MSS_THERMAL_INIT                              = 0x39,
    ISTEP_MSS_VOLT                                      = 0x3A,
    ISTEP_MSS_GETECID                                   = 0x3B,
    ISTEP_MSS_DRAMINIT_TRAINADV                         = 0x3C,
    ISTEP_DMI_IO_RESTORE_EREPAIR                        = 0x3D,
    ISTEP_FABRIC_IO_RESTORE_EREPAIR                     = 0x3E,
    ISTEP_VDDR_ENABLE                                   = 0x3F,
    ISTEP_VDDR_DISABLE                                  = 0x40,
    ISTEP_DMI_IO_DCCAL                                  = 0x41,
    ISTEP_FABRIC_IO_DCCAL                               = 0x42,
    ISTEP_PROC_XBUS_SCOMINIT                            = 0x43,
    ISTEP_PROC_ABUS_SCOMINIT                            = 0x44,
    ISTEP_PROC_DMI_SCOMINIT                             = 0x45,
    ISTEP_MEM_PLL_INITF                                 = 0x46,
    ISTEP_PROC_GETECID                                  = 0x47,
    ISTEP_INITSVC_MOD_ID                                = 0x48,
};

/**
 * @enum istepReasonCode
 *
 * @brief Reasoncodes used to describe what errors are being indicated.
 *
 */
enum istepReasonCode
{
    ISTEP_INVALID_REASONCODE                    = ISTEP_COMP_ID | 0x00,
    ISTEP_CXXTEST_FAILED_TEST                   = ISTEP_COMP_ID | 0x01,
    ISTEP_TARGET_NULL                           = ISTEP_COMP_ID | 0x02,
    ISTEP_MBOX_MSG_NULL                         = ISTEP_COMP_ID | 0x03,
    ISTEP_BAD_RC                                = ISTEP_COMP_ID | 0x04,
    ISTEP_FAIL_MASTER_WINKLE_RC                 = ISTEP_COMP_ID | 0x05,
    ISTEP_SLAVE_SBE_FAILED                      = ISTEP_COMP_ID | 0x06,
    ISTEP_NEST_CHIPLETS_FAILED                  = ISTEP_COMP_ID | 0x07,
    ISTEP_EDI_EI_INITIALIZATION_FAILED          = ISTEP_COMP_ID | 0x08,
    ISTEP_ACTIVATE_POWER_BUS_FAILED             = ISTEP_COMP_ID | 0x09,
    ISTEP_SBE_CENTAUR_INIT_FAILED               = ISTEP_COMP_ID | 0x0a,
    ISTEP_DMI_TRAINING_FAILED                   = ISTEP_COMP_ID | 0x0b,
    ISTEP_MC_CONFIG_FAILED                      = ISTEP_COMP_ID | 0x0c,
    ISTEP_DRAM_TRAINING_FAILED                  = ISTEP_COMP_ID | 0x0d,
    ISTEP_DRAM_INITIALIZATION_FAILED            = ISTEP_COMP_ID | 0x0e,
    ISTEP_BUILD_WINKLE_IMAGES_FAILED            = ISTEP_COMP_ID | 0x0F,
    ISTEP_CORE_ACTIVATE_FAILED                  = ISTEP_COMP_ID | 0x10,
    ISTEP_STEP_SEVENTEEN                        = ISTEP_COMP_ID | 0x11,
    ISTEP_ESTABLISH_SYSTEM_SMP_FAILED           = ISTEP_COMP_ID | 0x12,
    ISTEP_STEP_NINETEEN                         = ISTEP_COMP_ID | 0x13,
    ISTEP_LOAD_PAYLOAD_FAILED                   = ISTEP_COMP_ID | 0x14,
    ISTEP_START_PAYLOAD_FAILED                  = ISTEP_COMP_ID | 0x15,
    ISTEP_RESET_PORE_BARS_FAILED                = ISTEP_COMP_ID | 0x16,
    ISTEP_P8_PORESLW_INIT_FAILED                = ISTEP_COMP_ID | 0x17,
    ISTEP_PROC_CHIPLET_SCOMINIT_FAILED          = ISTEP_COMP_ID | 0x18,
    ISTEP_PROC_XBUS_IF_EXECUTION_FAILED         = ISTEP_COMP_ID | 0x19,
    ISTEP_PROC_ABUS_IF_EXECUTION_FAILED         = ISTEP_COMP_ID | 0x1A,
    ISTEP_DMI_DRIVE_RESTORE_FAILED              = ISTEP_COMP_ID | 0x1B,
    ISTEP_DMI_RECEIVE_RESTORE_FAILED            = ISTEP_COMP_ID | 0x1C,
    ISTEP_FABRIC_DRIVE_RESTORE_FAILED           = ISTEP_COMP_ID | 0x1D,
    ISTEP_FABRIC_RECEIVE_RESTORE_FAILED         = ISTEP_COMP_ID | 0x1E,
    ISTEP_DMI_GET_RESTORE_LANES_FAILED          = ISTEP_COMP_ID | 0x1F,
    ISTEP_FABRIC_GET_RESTORE_LANES_FAILED       = ISTEP_COMP_ID | 0x20,
    ISTEP_GET_PBUS_CONNECTIONS_FAILED           = ISTEP_COMP_ID | 0x21,
    ISTEP_DMI_IO_DCCAL_MCS_FAILED               = ISTEP_COMP_ID | 0x22,
    ISTEP_DMI_IO_DCCAL_MEMBUF_FAILED            = ISTEP_COMP_ID | 0x23,
    ISTEP_FABRIC_IO_DCCAL_ENDPOINT1_FAILED      = ISTEP_COMP_ID | 0x24,
    ISTEP_FABRIC_IO_DCCAL_ENDPOINT2_FAILED      = ISTEP_COMP_ID | 0x25,
    ISTEP_CUSTOMIZE_CHIP_REGIONS_FAILED         = ISTEP_COMP_ID | 0x26,
    ISTEP_MM_UNMAP_ERR                          = ISTEP_COMP_ID | 0x27,
    /**  0x28 - available */
    ISTEP_CEN_REC_ATTN_FAILED                   = ISTEP_COMP_ID | 0x29,
    ISTEP_PROC_REC_ATTN_FAILED                  = ISTEP_COMP_ID | 0x2A,
    ISTEP_PROC_XBUS_SCOMINIT_FAILED             = ISTEP_COMP_ID | 0x2B,
    ISTEP_PROC_ABUS_SCOMINIT_FAILED             = ISTEP_COMP_ID | 0x2C,
    ISTEP_PROC_SWITCH_CFSIM_FAILED              = ISTEP_COMP_ID | 0x2D,
    ISTEP_LOAD_SLW_FROM_PNOR_FAILED             = ISTEP_COMP_ID | 0x2E,
    ISTEP_PROC_GETECID_FAILED                   = ISTEP_COMP_ID | 0x2F,
    ISTEP_TOP_LEVEL_TARGET_NULL                 = ISTEP_COMP_ID | 0x30,
    ISTEP_DECONFIGURE_MBA_FAILED                = ISTEP_COMP_ID | 0x31,
    ISTEP_DECONFIGURE_L4_FAILED                 = ISTEP_COMP_ID | 0x32,
    ISTEP_REPAIR_LOADER_RETRY_OCCURED           = ISTEP_COMP_ID | 0x33,
    ISTEP_PROC_POST_WINKLE_FAILED               = ISTEP_COMP_ID | 0x34,
};  // end ISTEP

}
#endif
