/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/explorer/procedures/hwp/memory/lib/shared/exp_consts.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2021                        */
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

///
/// @file explorer_check_for_ready.H
/// @brief explorer_check_for_ready HWP declaration
///
// *HWP HWP Owner: Mark Pizzutillo <mark.pizzutillo@us.ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: CI

#ifndef MSS_EXP_CONSTS_H
#define MSS_EXP_CONSTS_H

#ifndef __PPE__
    #include <generic/memory/lib/utils/shared/mss_generic_consts.H>
#endif

namespace mss
{

namespace exp
{

constexpr uint32_t OCMB_ADDR_SHIFT = 3;

#ifndef __PPE__
///
/// @brief enum list for the indexes for the address delays
/// @note Taken from 07-MAY-19 firwmare document
///
enum attr_delay_index
{
    ODT1 = 0,
    ODT0 = 0,
    CS_N0 = 0,
    CS_N1 = 0,
    ADDR13 = 1,
    ADDR5 = 1,
    BG0 = 1,
    CKE1 = 1,
    ADDR17 = 2,
    ADDR7 = 2,
    BA0 = 2,
    ADDR16 = 2,
    ADDR8 = 3,
    BG1 = 3,
    CID1 = 3,
    CID0 = 3,
    ADDR1 = 4,
    ADDR9 = 4,
    ADDR2 = 4,
    CAPARITY = 4,
    ADDR12 = 5,
    ADDR3 = 5,
    ADDR4 = 5,
    ADDR0 = 5,
    CKE0 = 6,
    ADDR15 = 6,
    ACT_N = 6,
    ADDR10 = 6,
    ADDR11 = 7,
    ADDR6 = 7,
    BA1 = 7,
    ADDR14 = 7,
};

///
/// @brief enum list of explorer SPD derived attributes to set
/// @note these attrs are strictly derived from SPD
/// @warning wrapped in exp namesapce to be distinguished from
/// the exp::attr_eff_engine_fields
///
enum class attr_eff_engine_fields
{
    // Template recursive base case
    ATTR_EFF_BASE_CASE = 0,

    // Attrs to set
    BYTE_ENABLES = 1,
    NIBBLE_ENABLES = 2,
    SPD_TAA_MIN = 3,
    FOUR_RANK_MODE = 4,
    DDP_COMPATIBILITY = 5,
    TSV_8H_SUPPORT = 6,
    PSTATES = 7,
    MRAM_SUPPORT = 8,
    SPD_CL_SUPPORTED = 9,
    ADDRESS_MIRROR = 10,
    MODULE_THERMAL_SENSORS = 11,

    THERM_SENSOR_0_AVAIL = 12,
    THERM_SENSOR_0_SECOND_AVAIL = 13,
    THERM_SENSOR_0_TYPE = 14,
    THERM_SENSOR_0_USAGE = 15,
    THERM_SENSOR_0_I2C_ADDR = 16,

    THERM_SENSOR_1_AVAIL = 17,
    THERM_SENSOR_1_SECOND_AVAIL = 18,
    THERM_SENSOR_1_TYPE = 19,
    THERM_SENSOR_1_USAGE = 20,
    THERM_SENSOR_1_I2C_ADDR = 21,

    THERM_SENSOR_DIFF_AVAIL = 22,
    THERM_SENSOR_DIFF_TYPE = 23,
    THERM_SENSOR_DIFF_USAGE = 24,
    THERM_SENSOR_DIFF_I2C_ADDR = 25,

    SUPPORTED_RCD = 26,

    THERM_SENSOR_0_SECOND_I2C_ADDR = 27,
    THERM_SENSOR_1_SECOND_I2C_ADDR = 28,
    THERM_SENSOR_1_SECOND_LOCATION = 29,
    THERM_SENSOR_0_SECOND_LOCATION = 30,
    THERM_SENSOR_1_LOCATION = 31,
    THERM_SENSOR_0_LOCATION = 32,

    // Dispatcher set to last enum value
    DISPATCHER = THERM_SENSOR_0_LOCATION,
};

///
/// @brief enum list of explorer RC response msdg to set
///
enum class attr_rc_resp_engine_fields
{
    // Template recursive base case
    ATTR_EFF_BASE_CASE = 0,

    // Attrs to set
    F0RC00 = 1,
    F0RC01 = 2,
    F0RC03 = 3,
    F0RC04 = 4,
    F0RC05 = 5,
    F0RC0B = 6,
    F0RC0E = 7,
    F0RC0F = 8,
    F0RC1X = 9,
    F0RC7X = 10,
    F1RC00 = 11,
    F1RC02 = 12,
    F1RC03 = 13,
    F1RC04 = 14,
    F1RC05 = 15,

    // Dispatcher set to last enum value
    DISPATCHER = F1RC05,
};

///
/// @brief common explorer sizes
///
enum sizes
{
    MAX_PORT_PER_OCMB = 1,
    MAX_DIMM_PER_PORT = 2,
    MAX_RANK_PER_DIMM = 4,
    MAX_BG_PER_DIMM = 4,
    MAX_DQ_BITS_PER_PORT = 80,
    MAX_SYMBOLS_PER_PORT = 72,
    MAX_RANKS_DIMM1 = 2,
    MAX_MRANK_PER_PORT = MAX_DIMM_PER_PORT * MAX_RANK_PER_DIMM,
    MAX_BYTES_PER_PORT = MAX_DQ_BITS_PER_PORT / BITS_PER_BYTE,
    MAX_NIBBLES_PER_PORT = MAX_DQ_BITS_PER_PORT / BITS_PER_NIBBLE,
    MAX_RCW_RESP_ARRAY_SIZE = 27,
    MAX_DIMM_PER_PROC = 16,

    // Enumerations for the Explorer serial number attribute
    // The hostboot team requested that we only use enumerations for attribute values
    // These are attribute positions in an array, so moving them here
    SERIAL_PART_NUMBER = 3,
    SERIAL_PART_NUMBER_LEN = 7,
    SERIAL_RAW_CARD = 12,
    SERIAL_RAW_CARD_LEN = 2,
    SERIAL_SERIAL_NUMBER = 14,
    SERIAL_SERIAL_NUMBER_LEN = 12,
};

#endif

///
/// @brief explorer ffdc codes
///
enum ffdc_codes : uint16_t
{
    EXP_I2C_GET_FIELD = 0x0000,
    EXP_I2C_SET_FIELD = 0x0001,
    READ_HOST_FW_RESPONSE_STRUCT = 0x0003,
    READ_SENSOR_CACHE_STRUCT = 0x0004,
    READ_CRCT_ENDIAN = 0x0005,
    READ_TRAINING_RESPONSE_STRUCT = 0x0006,
    READ_FW_ADAPTER_PROPERTIES_STRUCT = 0x0007,

    SET_EXP_DRAM_ADDRESS_MIRRORING = 0x1040,
    SET_BYTE_ENABLES = 0x1041,
    SET_NIBBLE_ENABLES = 0x1042,
    SET_TAA_MIN = 0x1043,
    SET_FOUR_RANK_MODE = 0x1044,
    SET_DDP_COMPATIBILITY = 0x1045,
    SET_TSV_8H_SUPPORT = 0x1046,
    SET_VREF_DQ_TRAIN_RANGE = 0x1047,
    SET_PSTATES = 0x1048,
    SET_MRAM_SUPPORT = 0x1049,

    SET_SERDES_FREQ = 0x1051,
    SET_MODULE_THERMAL_SENSORS = 0x1052,

    SET_THERM_SENSOR_0_AVAIL = 0x1053,
    SET_THERM_SENSOR_0_TYPE = 0x1054,
    SET_THERM_SENSOR_0_USAGE = 0x1055,
    SET_THERM_SENSOR_0_I2C_ADDR = 0x1056,

    SET_THERM_SENSOR_1_AVAIL = 0x1057,
    SET_THERM_SENSOR_1_TYPE = 0x1058,
    SET_THERM_SENSOR_1_USAGE = 0x1059,
    SET_THERM_SENSOR_1_I2C_ADDR = 0x105A,

    SET_THERM_SENSOR_DIFF_AVAIL = 0x105B,
    SET_THERM_SENSOR_DIFF_TYPE = 0x105C,
    SET_THERM_SENSOR_DIFF_USAGE = 0x105D,
    SET_THERM_SENSOR_DIFF_I2C_ADDR = 0x105E,

    READ_RC_RSP_FIELD = 0x105F,
    SET_F0RC00 = 0x1060,
    SET_F0RC01 = 0x1061,
    SET_F0RC03 = 0x1062,
    SET_F0RC04 = 0x1063,
    SET_F0RC05 = 0x1064,
    SET_F0RC0B = 0x1065,
    SET_F0RC0E = 0x1066,
    SET_F0RC0F = 0x1067,
    SET_F0RC1X = 0x1068,
    SET_F0RC7X = 0x1069,
    SET_F1RC00 = 0x106A,
    SET_F1RC02 = 0x106B,
    SET_F1RC03 = 0x106C,
    SET_F1RC04 = 0x106D,
    SET_F1RC05 = 0x106E,
    SET_SUPPORTED_RCD = 0x106F,

    SET_THERM_SENSOR_0_SECOND_AVAIL = 0x1070,
    SET_THERM_SENSOR_1_SECOND_AVAIL = 0x1071,
    SET_THERM_SENSOR_0_SECOND_I2C_ADDR = 0x1072,
    SET_THERM_SENSOR_1_SECOND_I2C_ADDR = 0x1073,
    SET_THERM_SENSOR_1_SECOND_LOCATION = 0x1074,
    SET_THERM_SENSOR_0_SECOND_LOCATION = 0x1075,
    SET_THERM_SENSOR_1_LOCATION = 0x1076,
    SET_THERM_SENSOR_0_LOCATION = 0x1077,
};

///
/// @brief constants for getecid procedure
///
enum ecid_consts
{
    FUSE_ARRAY_SIZE = 14,
    DATA_IN_SIZE = 16,
    // TK - Will need to be changed once ATTR_ECID is made larger
    ATTR_ECID_SIZE = 2,
};

///
/// @brief constants for getidec procedure
///
enum idec_consts
{
    EXPLR_CHIP_INFO_REG = 0x2134,
    LOCATION_BIT_START = 44,
    LOCATION_BIT_LENGTH = 4,
    CHIPID_BIT_START = 56,
    CHIPID_BIT_LENGTH = 8,

    REVISION_BIT_START  = 50,
    REVISION_BIT_LENGTH = 4,
};



///
/// @brief generic explorer constants
///
enum generic_consts
{
    // Number of DRAM for x4 vs x8
    EXP_NUM_DRAM_X4 = 20,
    EXP_NUM_DRAM_X8 = 10,

    // Map MDS into Power Thermal decoder mapping
    DIMM_TYPE_MDS = 20,

    // Note: restore repairs and our ECC logic use the MC/DFI perspective
    // As such, our spare is located on byte 5
    // Byte where the spare DRAM(s) are located
    SPARE_DQ_BYTE = 5,
};

namespace i2c
{

///
/// @brief List of explorer I2C commands
///
enum cmd_id : uint8_t
{
    FW_BOOT_CONFIG                           = 0x01,
    FW_STATUS                                = 0x02,
    FW_REG_ADDR_LATCH                        = 0x03,
    FW_REG_READ                              = 0x04,
    FW_REG_WRITE                             = 0x05,
    FW_DOWNLOAD                              = 0x06,
    FW_CONT_REG_READ                         = 0x07,
    FW_CONT_REG_WRITE                        = 0x08,
    FW_BYPASS_4SEC_TIMEOUT                   = 0x09,
    FW_PQM_LANE_SET                          = 0x0A,
    FW_PQM_LANE_GET                          = 0x0B,
    FW_PQM_FREQ_SET                          = 0x0C,
    FW_PQM_FREQ_GET                          = 0x0D,
    FW_PQM_LANE_TRAINING                     = 0x0E,
    FW_PQM_TRAINING_RESET                    = 0x0F,
    FW_PQM_RX_ADAPTATION_OBJ_READ            = 0x10,
    FW_PQM_RX_CALIBRATION_VALUE_READ         = 0x11,
    FW_PQM_CSU_CALIBRATION_VALUE_STATUS_READ = 0x12,
    FW_PQM_PRBS_PATTERN_MODE_SET             = 0x13,
    FW_PQM_PRBS_USER_DEFINED_PATTERN_SET     = 0x14,
    FW_PQM_PRBS_MONITOR_CONTROL              = 0x15,
    FW_PQM_PRBS_GENERATOR_CONTROL            = 0x16,
    FW_PQM_PRBS_ERR_COUNT_READ               = 0x17,
    FW_PQM_HORIZONTAL_BATHTUB_GET            = 0x18,
    FW_PQM_VERTICAL_BATHTUB_GET              = 0x19,
    FW_PQM_2D_BATHTUB_GET                    = 0x1A,
    FW_PQM_FORCE_DELAY_LINE_UPDATE           = 0x22,
    FW_TWI_POLL_ABORT                        = 0x23,
    FW_TWI_FFE_SETTINGS                      = 0x24,
    FW_CDR_OFFSET_FROM_CAL_SET               = 0x25,
    FW_CDR_BANDWIDTH_SET                     = 0x26,
    FW_PRBS_CAL_STATUS_READ                  = 0x27,
    FW_CONT_SERDES_CAL_DISABLE               = 0x28,
    FW_READ_ACTIVE_LOGS                      = 0x29,
    FW_READ_SAVED_DDR_PARAMS                 = 0x2A,
};

///
/// @brief common explorer sizes
///
enum sizes
{
    // 32-bit commands
    FW_BOOT_CONFIG_BYTE_LEN = 4,
    FW_STATUS_BYTE_LEN      = 5,
    FW_TWI_FFE_SETTINGS_BYTE_LEN = 8,
    FW_CDR_BANDWIDTH_SET_LEN = 2,
    FW_CDR_OFFSET_FROM_CAL_SET_LEN = 2,

    FW_WRITE_REG_DATA_SIZE  = 0x08,
    FW_REG_ADDR_LATCH_SIZE  = 0x04,
    FW_I2C_SCOM_READ_SIZE   = 0x05,

    // Largest R/W length for bytes of data
    MIN_DATA_BYTES_LEN = 1,
    MAX_DATA_BYTES_LEN = 32,
};

///
/// @brief General I2C status codes
/// @note Shared I2C status codes for EXP_FW_REG_READ, EXP_FW_REG_WRITE,
/// EXP_FW_CONT_REG_READ, and EXP_FW_CONT_REG_WRITE
///
enum status_codes
{
    I2C_SUCCESS          = 0x00,
    ADDRESS_OUT_OF_RANGE = 0x01,
    ADDRESS_PROHIBITED   = 0x02,
    FW_BUSY              = 0xFE,
};

#ifndef __PPE__
///
/// @brief status codes for FW_BOOT_CONFIG
///
enum fw_boot_cfg_status
{
    INVALID_CMD       = 0x01,
    LOOPBACK_FAIL     = 0x02,
    SERDES_INIT_FAIL  = 0x04,
    DLX_CONFIG_FAIL   = 0x08,
    LANE_INV_FAIL     = 0x10,
    PARITY_UECC_ERROR = 0x20,
};

///
/// @brief extended error codes for FW_BOOT_CONFIG
///
enum fw_boot_cfg_ext_err
{
    CSU_FAILED_1        = 0x02,
    CSU_FAILED_2        = 0x23,
    SERDES_CALIB_FAILED = 0x03,
    DLL_LOCK_FAIL       = 0x07,
    DEASSERT_RESET_FAIL = 0x08,
};

#endif

///
/// @brief I2C boot stage options
/// @note certain cmds work in certain boot stages
///
enum boot_stages
{
    BOOT_ROM_STAGE  = 0x01,
    FW_UPGRADE_MODE = 0x02,
    RUNTIME_FW      = 0x03,
};

///
/// @brief Useful constants for i2c scom functionality
///
/// @note FIRST_BYTE_MASK = allows us to mask off first by of
///       an address to check if its an IBM SCOM
///       LAST_THREE_BYTES_MASK = used as part of formula to translate
///       a given address to an IBM scom address
///       OCBM_UNCACHED_OFFSET = Also used as part of formula for translating
///       a given address to the correct IBM or microchip form
///       IBM_SCOM_OFFSET_LHS and IBM_SCOM_OFFSET_RHS are used in formula
///       for calculating IBM scom address for left and right side of addr
///       IBM_SCOM_INDICATOR is the indicator bit in the first byte of an
///       address that tells us if it is a IBM scom or not
///
enum i2c_scom_consts : uint32_t
{
    FIRST_BYTE_MASK       = 0xFF000000,
    LAST_THREE_BYTES_MASK = 0x00FFFFFF,
    OCMB_UNCACHED_OFFSET  = 0xA0000000,
    IBM_SCOM_OFFSET_LHS   = 0x08000000,
    IBM_SCOM_OFFSET_RHS   = 0x08000004,
    IBM_SCOM_INDICATOR    = IBM_SCOM_OFFSET_LHS,
};

///
/// @brief Simple enum allows code to pick between left and right
///
/// This is used when deciding if we are writing/reading from left
/// side of IBM address or right side. This is needed because IBM
/// scoms are 64 bits while the OCMB only has 32 bit regs.
enum addrSide
{
    LHS = 0x00,
    RHS = 0x01
};

} // namespace i2c

///
/// @brief status codes for FW_DDR_PHY_INIT
///
enum fw_ddr_phy_init_status
{
    FW_DDR_PHY_INIT_SUCCESS             = 0x00,

    // Unsupported phy_init_mode
    FW_DDR_PHY_INIT_UNSUPPORTED_MODE    = 0x01,
    // Incorrect user_input_msdg size error
    FW_DDR_PHY_INIT_USER_MSDG_SIZE_ERR  = 0x02,
    // Missing user_input_msdg extended data flag
    FW_DDR_PHY_INIT_USER_MSDG_FLAG_ERR  = 0x03,
    // Misc user_input_msdg error
    FW_DDR_PHY_INIT_USER_MSDG_ERROR     = 0x04,
    // TODO: Training fail error will need to be split
    // Todo awaiting follow up RC meetings
    // Training returned as a fail
    FW_DDR_PHY_INIT_TRAINING_FAIL       = 0x05,
};

#ifndef __PPE__
namespace omi
{

///
/// @brief HOST-FW Commands and Responses
///
enum cmd_and_response_id
{
    // initialize the DDR PHY controller when Step-by-Step BOOT mode
    //  is selected
    EXP_FW_PHY_STEP_BY_STEP_INIT = 0x01,

    // sent by the Host along with PHY initialization data copied
    //  into data buffer for FW to use for configuring DDR PHY interface.
    EXP_FW_DDR_PHY_INIT = 0x02,

    // read temperature sensor
    EXP_FW_TEMP_SENSOR_PASS_THROUGH_READ = 0x03,

    // configure temperature sensor
    EXP_FW_TEMP_SENSOR_PASS_THROUGH_WRITE = 0x04,

    // configure interval read mechanism
    EXP_FW_TEMP_SENSOR_CONFIG_INTERVAL_READ = 0x05,

    // transition the FW into runtime mode when Step-by-Step BOOT mode
    //  is selected
    EXP_FW_GO_COMMAND = 0x06,

    // determine various configurations related to controller
    EXP_FW_ADAPTER_PROPERTIES_GET = 0x07,

    // sent by Host along with latest FW executable code, which is
    //  copied into data buffer location so that existing FW can
    //  upgrade the FW image
    EXP_FW_BINARY_UPGRADE = 0x08,

    // find the flash loader version information
    EXP_FW_FLASH_LOADER_VERSION_INFO = 0x09,

    // read the FW logs from various modules of Explorer block
    EXP_FW_LOG = 0x0A,
};

///
/// @brief Command flag definitions
///
enum cmd_flags
{
    NO_FLAGS = 0,
    ADDITIONAL_DATA = 1,
};

///
/// @brief Response argument parameters
///
enum response_arg
{
    RESPONSE_SUCCESS = 0,
    ERROR_CODE = 1,
};

} // namespace omi
#endif

///
/// @brief Explorer FW versions
/// @note this determines what inband commands/features are available
///
enum fw_version
{
    FW_VER_OLD = 397559,
    FW_DTM_SUPPORTED = 402648,
    FW_VER_BOOTLEG = 99999,
};

///
/// @brief Explorer FW API versions
/// @note this determines what i2c commands are available
///
enum fw_api_version
{
    DL_TRAINING_VERSION2_SUPPORTED = 0x01,
    FW_CDR_OFFSET_FROM_CAL_SET_SUPPORTED = 0x01,
    FW_CDR_BANDWIDTH_SET_SUPPORTED = 0x03,
};

} // namespace exp
} // namespace mss

#endif
