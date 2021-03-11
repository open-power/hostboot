/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/nvdimm/nvdimm.H $                              */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2021                        */
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

#ifndef NVDIMM_H__
#define NVDIMM_H__

#include <usr/errl/errlentry.H>
#include <targeting/common/target.H>
#include <targeting/common/commontargeting.H>
#include <targeting/common/util.H>
#include <targeting/common/utilFilter.H>
#include <i2c/eepromif.H>
#include <map>

using namespace EEPROM;

// Trace definition
extern trace_desc_t* g_trac_nvdimm;

namespace NVDIMM
{
#define NVDIMM_SET_USER_DATA_1(left_32_ops_id, right_32_huid) \
            TWO_UINT32_TO_UINT64(left_32_ops_id, right_32_huid)

#define NVDIMM_SET_USER_DATA_2_TIMEOUT(left_32_polled, right_32_timeout) \
            NVDIMM_SET_USER_DATA_1(left_32_polled, right_32_timeout)


// I2C registers for page 0-3, extracted from JEDEC BAEBI spec
// Refer to BAEBI spec for details
// https://www.jedec.org/standards-documents/docs/jesd245a
// The 2 least significant nibbles indicate the register address.
// The most significant nibble indicates the page number where the
// register belongs.
// e.g. for 0x00A, 0x0 = page number, 0x0A = register address
enum i2cReg : uint16_t
{
    OPEN_PAGE = 0x000,
    STD_NUM_PAGES = 0x001,
    VENDOR_START_PAGES = 0x002,
    VENDOR_NUM_PAGES = 0x003,
    HWREV = 0x004,
    SPECREV = 0x006,
    SLOT0_FWREV0 = 0x007,
    SLOT0_FWREV1 = 0x008,
    SLOT1_FWREV0 = 0x009,
    SLOT1_FWREV1 = 0x00A,
    SLOT0_SUBFWREV = 0x00B,
    SLOT1_SUBFWREV = 0x00C,
    CAPABILITIES0 = 0x010,
    CAPABILITIES1 = 0x011,
    ENERGY_SOURCE_POLICY = 0x014,
    HOST_MAX_OPERATION_RETRY = 0x015,
    CSAVE_TRIGGER_SUPPORT = 0x016,
    EVENT_NOTIFICATION_SUPPORT = 0x017,
    CSAVE_TIMEOUT0 = 0x018,
    CSAVE_TIMEOUT1 = 0x019,
    PAGE_SWITCH_LATENCY0 = 0x01A,
    PAGE_SWITCH_LATENCY1 = 0x01B,
    RESTORE_TIMEOUT0 = 0x01C,
    RESTORE_TIMEOUT1 = 0x01D,
    ERASE_TIMEOUT0 = 0x01E,
    ERASE_TIMEOUT1 = 0x01F,
    ARM_TIMEOUT0 = 0x020,
    ARM_TIMEOUT1 = 0x021,
    FIRMWARE_OPS_TIMEOUT0 = 0x022,
    FIRMWARE_OPS_TIMEOUT1 = 0x023,
    ABORT_CMD_TIMEOUT = 0x024,
    MAX_RUNTIME_POWER0 = 0x027,
    MAX_RUNTIME_POWER1 = 0x028,
    CSAVE_POWER_REQ0 = 0x029,
    CSAVE_POWER_REQ1 = 0x02A,
    CSAVE_IDLE_POWER_REQ0 = 0x02B,
    CSAVE_IDLE_POWER_REQ1 = 0x02C,
    CSAVE_MIN_VOLT_REQ0 = 0x02D,
    CSAVE_MIN_VOLT_REQ1 = 0x02E,
    CSAVE_MAX_VOLT_REQ0 = 0x02F,
    CSAVE_MAX_VOLT_REQ1 = 0x030,
    VENDOR_LOG_PAGE_SIZE = 0x031,
    REGION_BLOCK_SIZE = 0x032,
    OPERATIONAL_UNIT_OPS_TIMEOUT0 = 0x033,
    OPERATIONAL_UNIT_OPS_TIMEOUT1 = 0x034,
    FACTORY_DEFAULT_TIMEOUT0 = 0x035,
    FACTORY_DEFAULT_TIMEOUT1 = 0x036,
    MIN_OPERATING_TEMP0 = 0x038,
    MIN_OPERATING_TEMP1 = 0x039,
    MAX_OPERATING_TEMP0 = 0x03A,
    MAX_OPERATING_TEMP1 = 0x03B,
    NVDIMM_MGT_CMD0 = 0x040,
    NVDIMM_MGT_CMD1 = 0x041,
    NVDIMM_FUNC_CMD = 0x043,
    ARM_CMD = 0x045,
    SET_EVENT_NOTIFICATION_CMD = 0x047,
    SET_ES_POLICY_CMD = 0x049,
    FIRMWARE_OPS_CMD = 0x04A,
    OPERATIONAL_UNIT_OPS_CMD = 0x04B,
    NVDIMM_READY = 0x060,
    NVDIMM_CMD_STATUS0 = 0x061,
    NVDIMM_CMD_STATUS1 = 0x062,
    CSAVE_STATUS = 0x064,
    RESTORE_STATUS = 0x066,
    ERASE_STATUS = 0x068,
    ARM_STATUS = 0x06A,
    FACTORY_DEFAULT_STATUS = 0x06C,
    SET_EVENT_NOTIFICATION_STATUS = 0x06E,
    SET_ES_POLICY_STATUS = 0x070,
    FIRMWARE_OPS_STATUS = 0x071,
    OPERATIONAL_UNIT_OPS_STATUS = 0x072,
    ERASE_FAIL_INFO = 0x073,
    ARM_FAIL_INFO = 0x076,
    CSAVE_INFO = 0x080,
    CSAVE_FAIL_INFO0 = 0x084,
    CSAVE_FAIL_INFO1 = 0x085,
    RESTORE_FAIL_INFO = 0x088,
    OPERATIONAL_UNIT_FAIL_INFO = 0x08F,
    NVM_LIFETIME_ERROR_THRESHOLD = 0x090,
    ES_LIFETIME_ERROR_THRESHOLD = 0x091,
    ES_TEMP_ERROR_HIGH_THRESHOLD0 = 0x094,
    ES_TEMP_ERROR_HIGH_THRESHOLD1 = 0x095,
    ES_TEMP_ERROR_LOW_THRESHOLD0 = 0x096,
    ES_TEMP_ERROR_LOW_THRESHOLD1 = 0x097,
    NVM_LIFETIME_WARNING_THRESHOLD = 0x098,
    ES_LIFETIME_WARNING_THRESHOLD = 0x099,
    ES_TEMP_WARNING_HIGH_THRESHOLD0 = 0x09C,
    ES_TEMP_WARNING_HIGH_THRESHOLD1 = 0x09D,
    ES_TEMP_WARNING_LOW_THRESHOLD0 = 0x09E,
    ES_TEMP_WARNING_LOW_THRESHOLD1 = 0x09F,
    MODULE_HEALTH = 0x0A0,
    MODULE_HEALTH_STATUS0 = 0x0A1,
    MODULE_HEALTH_STATUS1 = 0x0A2,
    ERROR_THRESHOLD_STATUS = 0x0A5,
    WARNING_THRESHOLD_STATUS = 0x0A7,
    AUTO_ES_HEALTH_FREQUENCY = 0x0A9,
    MODULE_OPS_CONFIG = 0x0AA,
    NVM_LIFETIME = 0x0C0,
    ES_HWREV = 0x104,
    ES_FWREV0 = 0x106,
    ES_FWREV1 = 0x107,
    SLOT0_ES_FWREV0 = 0x108,
    SLOT0_ES_FWREV1 = 0x109,
    SLOT1_ES_FWREV0 = 0x10A,
    SLOT1_ES_FWREV1 = 0x10B,
    ES_CHARGE_TIMEOUT0 = 0x110,
    ES_CHARGE_TIMEOUT1 = 0x111,
    ES_ATTRIBUTES = 0x114,
    ES_TECH = 0x115,
    MIN_ES_OPERATING_TEMP0 = 0x116,
    MIN_ES_OPERATING_TEMP1 = 0x117,
    MAX_ES_OPERATING_TEMP0 = 0x118,
    MAX_ES_OPERATING_TEMP1 = 0x119,
    ES_FUNC_CMD0 = 0x130,
    ES_CMD_STATUS0 = 0x150,
    ES_LIFETIME = 0x170,
    ES_TEMP0 = 0x171,
    ES_TEMP1 = 0x172,
    ES_RUNTIME0 = 0x173,
    ES_RUNTIME1 = 0x174,
    LAST_CSAVE_DURATION0 = 0x204,
    LAST_CSAVE_DURATION1 = 0x205,
    LAST_RESTORE_DURATION0 = 0x206,
    LAST_RESTORE_DURATION1 = 0x207,
    LAST_ERASE_DURATION0 = 0x208,
    LAST_ERASE_DURATION1 = 0x209,
    CSAVE_SUCCESS_COUNT0 = 0x20A,
    CSAVE_SUCCESS_COUNT1 = 0x20B,
    RESTORE_SUCCESS_COUNT0 = 0x20C,
    RESTORE_SUCCESS_COUNT1 = 0x20D,
    ERASE_SUCCESS_COUNT0 = 0x20E,
    ERASE_SUCCESS_COUNT1 = 0x20F,
    POWER_CYCLE_COUNT0 = 0x210,
    POWER_CYCLE_COUNT1 = 0x211,
    CSAVE_FAILURE_COUNT0 = 0x212,
    CSAVE_FAILURE_COUNT1 = 0x213,
    RESTORE_FAILURE_COUNT0 = 0x214,
    RESTORE_FAILURE_COUNT1 = 0x215,
    ERASE_FAILURE_COUNT0 = 0x216,
    ERASE_FAILURE_COUNT1 = 0x217,
    LAST_ARM_DURATION0 = 0x218,
    LAST_ARM_DURATION1 = 0x219,
    LAST_FACTORY_DEFAULT_DURATION0 = 0x21A,
    LAST_FACTORY_DEFAULT_DURATION1 = 0x21B,
    LAST_FIRMWARE_OPS_DURATION0 = 0x21C,
    LAST_FIRMWARE_OPS_DURATION1 = 0x21D,
    LAST_OPERATIONAL_UNIT_OPS_DURATION0 = 0x21E,
    LAST_OPERATIONAL_UNIT_OPS_DURATION1 = 0x21F,
    ARM_SUCCESS_COUNT0 = 0x220,
    ARM_SUCCESS_COUNT1 = 0x221,
    FACTORY_DEFAULT_SUCCESS_COUNT0 = 0x222,
    FACTORY_DEFAULT_SUCCESS_COUNT1 = 0x223,
    FIRMWARE_SUCCESS_COUNT0 = 0x224,
    FIRMWARE_SUCCESS_COUNT1 = 0x225,
    OPERATIONAL_UNIT_SUCCESS_COUNT0 = 0x226,
    OPERATIONAL_UNIT_SUCCESS_COUNT1 = 0x227,
    ARM_FAILURE_COUNT0 = 0x228,
    ARM_FAILURE_COUNT1 = 0x229,
    FACTORY_DEFAULT_FAILURE_COUNT0 = 0x22A,
    FACTORY_DEFAULT_FAILURE_COUNT1 = 0x22B,
    FIRMWARE_FAILURE_COUNT0 = 0x22C,
    FIRMWARE_FAILURE_COUNT1 = 0x22D,
    OPERATIONAL_UNIT_FAILURE_COUNT0 = 0x22E,
    OPERATIONAL_UNIT_FAILURE_COUNT1 = 0x22F,
    INJECT_OPS_FAILURES0 = 0x260,
    INJECT_OPS_FAILURES1 = 0x261,
    INJECT_ES_FAILURES = 0x264,
    INJECT_FW_FAILURES = 0x265,
    INJECT_BAD_BLOCK_CAP = 0x267,
    INJECT_ERROR_TYPE = 0x268,
    DRAM_ECC_ERROR_COUNT = 0x280,
    DRAM_THRESHOLD_ECC_COUNT = 0x281,
    HOST_MANAGED_ES_ATTRIBUTES = 0x282,
    HOST_CSAVE_FAIL = 0x283,
    HOST_CSAVE_WORKFLOW_FAILURE_COUNT0 = 0x284,
    HOST_CSAVE_WORKFLOW_FAILURE_COUNT1 = 0x285,
    TYPED_BLOCK_DATA = 0x304,
    REGION_ID0 = 0x305,
    REGION_ID1 = 0x306,
    BLOCK_ID = 0x307,
    TYPED_BLOCK_DATA_SIZE0 = 0x308,
    TYPED_BLOCK_DATA_SIZE1 = 0x309,
    TYPED_BLOCK_DATA_SIZE2 = 0x30A,
    OPERATIONAL_UNIT_ID0 = 0x30C,
    OPERATIONAL_UNIT_ID1 = 0x30D,
    OPERATIONAL_UNIT_SIZE0 = 0x310,
    OPERATIONAL_UNIT_SIZE1 = 0x311,
    OPERATIONAL_UNIT_SIZE2 = 0x312,
    OPERATIONAL_UNIT_CRC0 = 0x314,
    OPERATIONAL_UNIT_CRC1 = 0x315,
    FW_REGION_CRC0 = 0x340,
    FW_REGION_CRC1 = 0x341,
    FW_SLOT_INFO = 0x342,
    TYPED_BLOCK_DATA_BYTE0 = 0x380,
    TYPED_BLOCK_DATA_BYTE1 = 0x381,
    TYPED_BLOCK_DATA_BYTE2 = 0x382,
    TYPED_BLOCK_DATA_BYTE3 = 0x383,
    TYPED_BLOCK_DATA_BYTE4 = 0x384,
    TYPED_BLOCK_DATA_BYTE5 = 0x385,
    TYPED_BLOCK_DATA_BYTE6 = 0x386,
    TYPED_BLOCK_DATA_BYTE7 = 0x387,
    TYPED_BLOCK_DATA_BYTE8 = 0x388,
    TYPED_BLOCK_DATA_BYTE9 = 0x389,
    TYPED_BLOCK_DATA_BYTE10 = 0x38A,
    TYPED_BLOCK_DATA_BYTE11 = 0x38B,
    TYPED_BLOCK_DATA_BYTE12 = 0x38C,
    TYPED_BLOCK_DATA_BYTE13 = 0x38D,
    TYPED_BLOCK_DATA_BYTE14 = 0x38E,
    TYPED_BLOCK_DATA_BYTE15 = 0x38F,
    TYPED_BLOCK_DATA_BYTE16 = 0x390,
    TYPED_BLOCK_DATA_BYTE17 = 0x391,
    TYPED_BLOCK_DATA_BYTE18 = 0x392,
    TYPED_BLOCK_DATA_BYTE19 = 0x393,
    TYPED_BLOCK_DATA_BYTE20 = 0x394,
    TYPED_BLOCK_DATA_BYTE21 = 0x395,
    TYPED_BLOCK_DATA_BYTE22 = 0x396,
    TYPED_BLOCK_DATA_BYTE23 = 0x397,
    TYPED_BLOCK_DATA_BYTE24 = 0x398,
    TYPED_BLOCK_DATA_BYTE25 = 0x399,
    TYPED_BLOCK_DATA_BYTE26 = 0x39A,
    TYPED_BLOCK_DATA_BYTE27 = 0x39B,
    TYPED_BLOCK_DATA_BYTE28 = 0x39C,
    TYPED_BLOCK_DATA_BYTE29 = 0x39D,
    TYPED_BLOCK_DATA_BYTE30 = 0x39E,
    TYPED_BLOCK_DATA_BYTE31 = 0x39F,
    TYPED_BLOCK_DATA_OFFSET = 0x3E0,
    PANIC_CNT               = 0x406,
    STATUS_EVENT_INT_INFO1  = 0x40A,
    STATUS_EVENT_INT_INFO2  = 0x40B,
    FLASH_BAD_BLK_PCT       = 0x41D,  // Read only; Percentage of flash blocks
                                      // in the flash array marked as bad blocks
    PARITY_ERROR_COUNT      = 0x423,
    FLASH_ERROR_COUNT0      = 0x428,  // Read only; LSB[7:0]  Flash error count
    FLASH_ERROR_COUNT1      = 0x429,  // Read only;    [15:8]
    FLASH_ERROR_COUNT2      = 0x42A,  // Read only; MSB[23:16]
    FLASH_BAD_BLOCK_COUNT0  = 0x42B,
    FLASH_BAD_BLOCK_COUNT1  = 0x42C,
    BPM_MAGIC_REG1          = 0x430,
    BPM_MAGIC_REG2          = 0x431,
    SCAP_STATUS             = 0x432,
    SCAP_REG                = 0x434,
    SCAP_DATA               = 0x435,
    I2C_REG_PROTECT         = 0x43D,
    BPM_REG_CMD             = 0x440,
    BPM_CMD_STATUS          = 0x441,
    BPM_PAYLOAD_LENGTH      = 0x442,
    BPM_REG_ERR_STATUS      = 0x443,
    BPM_REG_PAYLOAD_START   = 0x444,
    ERASE_VERIFY_CONTROL             = 0x51A,
    ERASE_VERIFY_STATUS              = 0x51B,
    ERASE_VERIFY_RESULT_LSB          = 0x51C,
    ERASE_VERIFY_RESULT_MSB          = 0x51D,
    ERASE_VERIFY_TEST                = 0x51E,
    ENCRYPTION_COMMAND               = 0x51F,
    ENCRYPTION_CONFIG_STATUS         = 0x520,
    ENCRYPTION_ACCESS_KEY_SET        = 0x521,
    ENCRYPTION_ACCESS_KEY_VERIFY     = 0x522,
    ENCRYPTION_ACCESS_KEY_UNLOCK     = 0x523,
    ENCRYPTION_RAMDOM_STRING_SET     = 0x524,
    ENCRYPTION_RANDOM_STRING_VERIFY  = 0x525,
    ENCRYPTION_ERASE_KEY_SET         = 0x526,
    ENCRYPTION_ERASE_KEY_VERIFY      = 0x527,
    ENCRYPTION_ERASE_KEY_TEST        = 0x528,
    ENCRYPTION_ERASE_KEY_TEST_VERIFY = 0x529,
    ENCRYPTION_KEY_VALIDATION        = 0x52A,
};

// i2cReg macros
#define ADDRESS(uint16_address) \
            uint16_address & 0x00FF

#define PAGE(uint16_address) \
            (uint16_address >> 8) & 0x000F

// Up to 10 pages per BAEBI Spec,
// but use page 0 mostly
enum page : uint8_t
{
    ZERO  = 0x00,
    ONE   = 0x01,
    TWO   = 0x02,
    THREE = 0x03,
    FOUR  = 0x04,
    FIVE  = 0x05,
};

// Enums for inputs/expected output to/from the i2c registers
enum i2c_in_values : uint8_t
{
    ARM_RESETN_AND_ATOMIC_SAVE_AND_ERASE        = 0x84,
    ARM_RESETN                                  = 0x04,
    DISARM_RESETN                               = 0x00,
    ES_DEV_MANAGE                               = 0x01, //0x01 for device manage
    ERASE_IMAGE                                 = 0x08,
    RESTORE_IMAGE                               = 0x04,
    RESET_CTRLR                                 = 0x01,
    VALID_IMAGE                                 = 0x01,
    RESET_CONTROLLER                            = 0x01,
    FACTORY_DEFAULT                             = 0x01,
};

enum i2c_out_values : uint8_t
{
    SAVE_IN_PROGRESS            = 0x05,
    RSTR_IN_PROGRESS            = 0x09,
    ERASE_IN_PROGRESS           = 0x11,
    ARM_IN_PROGRESS             = 0x41,
    CHARGE_IN_PROGRESS          = 0x01,
    SAVE_SUCCESS                = 0x01,
    RSTR_SUCCESS                = 0X01,
    ARM_SUCCESS                 = 0X01,
    ERASE_SUCCESS               = 0X01,
    ES_SUCCESS                  = 0x05,
    CHARGE_SUCCESS              = 0x00,
    NV_READY                    = 0xA5,
    FACTORY_RESET_IN_PROGRESS   = 0x03,
    NO_RESET_N                  = 0x20,
    RESET_N_ARMED               = 0x08,
    ES_POLICY_ERROR             = 0x02,
    ARM_ERROR                   = 0X02,
    RSTR_ERROR                  = 0x02,
    SAVE_ERROR                  = 0x02,
    ERASE_ERROR                 = 0x02,
    CLEAR_ALL_STATUS            = 0x3C, //Clears CAVE, RESTORE, ERASE, and ARM status regs
    CSAVE_FAIL_NOT_ENOUGH_ENERGY_FOR_CSAVE = 0x01, // bit in CSAVE_FAIL_INFO1
};

// Timeout-related enum
enum timeout : uint32_t
{
    OPS_POLL_TIME_MS = 5000,
    NV_READY_POLL_TIME_MS = 1000,
    PAGE_SWITCH_POLL_TIME_NS = 100,
    KEY_WRITE_DELAY_MS = 100,
};

// Assign an id to each of the 6 major ops
enum ops_id : uint8_t
{
    SAVE = 0,
    RESTORE,
    ERASE,
    ARM,
    PAGE_SWITCH,
    CHARGE,
};

enum misc
{
    NO_PAGE_VERIFY = 0,
    PAGE_VERIFY = 1,
    ARM_TRIGGER = 1,
    DISARM_TRIGGER = 0,
    LOW = 0,
    HIGH = 1,
};

/**
 * @brief Encryption key data
 */
static constexpr size_t ENC_KEY_SIZE = 32;
struct nvdimmKeyData_t
{
    uint8_t rs[ENC_KEY_SIZE];   // Random String (RS)
    uint8_t ek[ENC_KEY_SIZE];   // Erase Key (EK)
    uint8_t ak[ENC_KEY_SIZE];   // Access Key (AK)
};

struct scap_status_bits
{
    uint8_t Reserved1       : 1; // Bit 7
    uint8_t Bpm_Bsl_Mode    : 1; // Bit 6
    uint8_t Reserved2       : 1; // Bit 5
    uint8_t Present         : 1; // Bit 4
    uint8_t Delay           : 1; // Bit 3
    uint8_t Error           : 1; // Bit 2
    uint8_t Busy            : 1; // Bit 1
    uint8_t Enable          : 1; // Bit 0
} PACKED;

/**
 * @brief Union simplifying manipulation of SCAP_STATUS bits
 */
union scap_status_union
{
    uint8_t full;
    scap_status_bits bit;

    /**
     *  @brief Constructor
     */
    scap_status_union()
    : full(0)
    {}
} PACKED;

typedef scap_status_union scap_status_register_t;

// Bits in Health Status Check Registers
enum health_status : uint8_t
{
    // Module Health Status0
    VOLTAGE_REGULATOR_FAILED    = 0x01,
    VDD_LOST                    = 0x02,
    VPP_LOST                    = 0x04,
    VTT_LOST                    = 0x08,
    DRAM_NOT_SELF_REFRESH       = 0x10,
    CONTROLLER_HARDWARE_ERROR   = 0x20,
    NVM_CONTROLLER_ERROR        = 0x40,
    NVM_LIFETIME_ERROR          = 0x80,
    // Module Health Status1
    NOT_ENOUGH_ENERGY_FOR_CSAVE = 0x01,
    INVALID_FIRMWARE_ERROR      = 0x02,
    CONFIG_DATA_ERROR           = 0x04,
    NO_ES_PRESENT               = 0x08,
    ES_POLICY_NOT_SET           = 0x10,
    ES_HARDWARE_FAILURE         = 0x20,
    ES_HEALTH_ASSESSMENT_ERROR  = 0x40,
    // Error Threshold Status
    ES_LIFETIME_ERROR           = 0x02,
    ES_TEMP_ERROR               = 0x04,
};

// Int representation for health status function call
enum health_function : uint8_t
{
    HEALTH_SAVE        = 0x01,
    HEALTH_RESTORE     = 0x02,
    HEALTH_UPDATE      = 0x03,
    HEALTH_PRE_ARM     = 0x04,
    HEALTH_POST_ARM    = 0x05,
};

// Event notification register values
enum event_n : uint8_t
{
    PERSISTENCY_NOTIFICATION            = 0x01,
    SET_EVENT_NOTIFICATION_ERROR        = 0x02,
    WARNING_THRESHOLD_NOTIFICATION      = 0x02,
    PERSISTENCY_ENABLED                 = 0x04,
    WARNING_THRESHOLD_ENABLED           = 0x08,
    ENABLE_NOTIFICATIONS                = 0x03,
    NOTIFICATIONS_ENABLED               = 0x0C,
};

// MBACALFIR register addresses
enum mbacal_addresses : uint32_t
{
    MBACALFIR_AND_MASK_REG = 0x07010904,
    MBACALFIR_OR_MASK_REG  = 0x07010905,
    MBACALFIR_ACTION0_REG  = 0x07010906,
    MBACALFIR_ACTION1_REG  = 0x07010907,
};

// MBACALFIR bit masks for event n
enum mbacal_bitmask_values : uint64_t
{
    MBACALFIR_EVENTN_AND_BIT         = 0xff7fffffffffffff,
    MBACALFIR_EVENTN_OR_BIT          = 0x0080000000000000,
    MBACALFIR_REFRESH_OVERRUN_OR_BIT = 0x2000000000000000,
    MBACALFIR_UNMASK_BIT             = 0xff7fffffffffffff,
};


/**
 * @brief Mask MCBACALFIR to prevent PRD from handling event
 *        Note: if mask fails, this will commit the error internally
 *
 * @param[in] - i_nvdimm - nvdimm target for operation on its parent MCA
 * @param[in] - i_orMaskData - bits to mask via OR (see MBACALFIR_*OR_BIT)
 */
void maskMbacalfir(TARGETING::Target* i_nvdimm, uint64_t i_orMaskData);

/**
 * @brief Wrapper to call deviceOp to read the NV controller via I2C
 *
 * @param[in] i_nvdimm - nvdimm target with NV controller
 *
 * @param[in] i_addr - address/offset for the register to be read
 *
 * @param[out] o_data - returned data from read
 *
 * @param[in] page_verify - read and verify the page associated to the given address.
 *                          Change if needed. Default to true
 *
 * @return errlHndl_t - Null if successful, otherwise a pointer to
 *      the error log.
 */
errlHndl_t nvdimmReadReg(TARGETING::Target* i_nvdimm, uint16_t i_addr, uint8_t & o_data, const bool page_verify = PAGE_VERIFY);

/**
 * @brief Wrapper to call deviceOp to write the NV controller via I2C
 *
 * @param[in] i_nvdimm - nvdimm target with NV controller
 *
 * @param[in] i_addr - address/offset for the register to be written
 *
 * @param[in] i_data - data to register
 *
 * @param[in] page_verify - read and verify the page associated to the given address.
 *                          Change if needed. Default to true
 *
 * @return errlHndl_t - Null if successful, otherwise a pointer to
 *      the error log.
 */
errlHndl_t nvdimmWriteReg(TARGETING::Target* i_nvdimm, uint16_t i_addr, uint8_t i_data, const bool page_verify = PAGE_VERIFY);

/**
 * @brief Check NV controller ready state
 *
 * @param[in] i_nvdimm - nvdimm target
 *
 * @return errlHndl_t - Null if successful, otherwise a pointer to
 *      the error log.
 */
errlHndl_t nvdimmReady(TARGETING::Target *i_nvdimm);

/**
 * @brief This functions opens the NV controller to the specified page
 *        Refer to the BAEBI to see what each page does
 *
 * @param[in] i_nvdimm - nvdimm target with NV controller
 *
 * @param[in] i_page - page number to open to
 *
 * @return errlHndl_t - Null if successful, otherwise a pointer to
 *                      the error log
 */
errlHndl_t nvdimmOpenPage(TARGETING::Target *i_nvdimm, uint8_t i_page);

/**
 * @brief This function polls the status register for the given ops_id
 *
 * @param[in] i_nvdimm - nvdimm target with NV controller
 *
 * @param[in] i_ops_id - id assigned to each operation in nvdimm.H
 *
 * @param[out] o_poll - total polled time in ms
 *
 * @return errlHndl_t - Null if successful, otherwise a pointer to
 *      the error log.
 */
errlHndl_t nvdimmPollStatus(TARGETING::Target *i_nvdimm, ops_id i_ops_id, uint32_t &o_poll);


/**
 * @brief This function sets the energy supply policy to device-managed
 *
 * @param[in] i_nvdimm - nvdimm target with NV controller
 *
 * @return errlHndl_t - Null if successful, otherwise a pointer to
 *      the error log.
 */
errlHndl_t nvdimmSetESPolicy(TARGETING::Target* i_nvdimm);

/**
 * @brief Helper function to handle conflicting attribute keys
 *
 * @param[in] i_attrKeysFw - firmware key attribute
 *
 * @param[in] i_attrKeysAnchor - anchor key attribute
 *
 * @return errlHndl_t - Null if successful, otherwise a pointer to
 *                      the error log
 */
errlHndl_t nvdimm_handleConflictingKeys(
    TARGETING::ATTR_NVDIMM_ENCRYPTION_KEYS_FW_typeStdArr& i_attrKeysFw,
    TARGETING::ATTR_NVDIMM_ENCRYPTION_KEYS_ANCHOR_typeStdArr& i_attrKeysAnchor);


/**
 * @brief Helper function to validate attribute keys
 *
 * @param[in] i_attrData - pointer to attribute key data
 *
 * @return errlHndl_t - Null if successful, otherwise a pointer to
 *                      the error log
 */
errlHndl_t nvdimm_checkValidAttrKeys( nvdimmKeyData_t* i_attrData );


/**
 * @brief Helper function to write encryption key regs (RS/EK/AK)
 *
 * @param[in] i_nvdimm - nvdimm target
 *
 * @param[in] i_keyData - data to write to the key reg
 *
 * @param[in] i_keyReg - enum register to write key
 *
 * @param[in] i_verifyReg - enum register to verify key written
 *
 * @param[in] i_secondAttempt - normally false, true if verif check failed
 *
 * @return errlHndl_t - Null if successful, otherwise a pointer to
 *                      the error log
 */
errlHndl_t nvdimm_setKeyReg(TARGETING::Target* i_nvdimm,
                            uint8_t* i_keyData,
                            uint32_t i_keyReg,
                            uint32_t i_verifyReg,
                            bool i_secondAttempt);


/**
 * @brief Helper function to generate randon number for encryption keys
 *        Generates ENC_KEY_SIZE bytes of data
 *        Different implementations for boot vs runtime
 *
 * @param[out] o_genData - pointer to generated data
 *
 * @return errlHndl_t - Null if successful, otherwise a pointer to
 *                      the error log
 */
errlHndl_t nvdimm_getRandom(uint8_t* o_genData);


/**
 * @brief Helper function to make a random number valid for keys
 *        Keys must not contain 0x00 or 0xFF
 *         - 0x00 KEY_TERMINATE_BYTE terminates a key < 32 bytes
 *         - 0xFF KEY_ABORT_BYTE aborts the key reg write process
 *        This function finds invalid bytes in the first random number
 *         and replaces with bytes from the second random number
 *
 * @param[out] o_genData - pointer to final generated data
 *
 * @param[in] i_xtraData - pointer to extra generated data
 *
 * @return - false if successful, true if failed
 *
 */
bool nvdimm_keyifyRandomNumber(uint8_t* o_genData, uint8_t* i_xtraData);


/**
 * @brief Helper function to validate a random number
 *
 * @param[in] i_genData - pointer to generated data
 *
 * @return - true if valid, false if invalid
 *
 */
bool nvdimm_validRandomNumber(uint8_t* i_genData);


/**
 * @brief Helper function to set encryption error
 *        in ATTR_NVDIMM_ARMED
 *
 * @param[in] i_nvdimm - nvdimm target
 *
 */
void nvdimmSetEncryptionError(TARGETING::Target *i_nvdimm);


/**
 * @brief Helper function to reset the NVDIMM controller
 *
 * @param[in] i_nvdimm - nvdimm target
 *
 * @return errlHndl_t - Null if successful, otherwise a pointer to
 *                      the error log
 */
errlHndl_t nvdimmResetController(TARGETING::Target *i_nvdimm);


/**
 * @brief Helper function to factory reset NVDIMM
 *
 * @param[in] i_nvdimm - nvdimm target
 *
 * @return errlHndl_t - Null if successful, otherwise a pointer to
 *                      the error log
 */
errlHndl_t nvdimm_factory_reset(TARGETING::Target *i_nvdimm);


#ifndef __HOSTBOOT_RUNTIME

/**
 * @brief Helper function to get TPM pointer for random number generation
 *
 * @param[out] - pointer to a functional TPM or nullptr if no TPM found
 *
 * @return errlHndl_t - Null if successful, otherwise a pointer to
 *                      the error log
 */
errlHndl_t nvdimm_getTPM(TARGETING::Target*& o_tpm);

#endif

/**
 * @brief This function checks for valid image on the given target
 *
 * @param[in] i_nvdimm - nvdimm target with NV controller
 *
 * @param[out] o_imgValid - return true if the target has a valid image
 *
 * @return errlHndl_t - Null if successful, otherwise a pointer to
 *      the error log.
 */
errlHndl_t nvdimmValidImage(TARGETING::Target *i_nvdimm, bool &o_imgValid);


/**
 * @brief This function grabs the current slot NVDIMM code is running
 *        Slot 0 is the failure slot, Slot 1 is the updateable slot
 *
 * @param[in] i_nvdimm - nvdimm target with NV controller
 * @param[out] o_slot -  0 or 1
 *
 * @return errlHndl_t - Null if successful, otherwise a pointer to
 *      the error log.
 */
errlHndl_t nvdimmGetRunningSlot(TARGETING::Target *i_nvdimm, uint8_t & o_slot);

} //End NVDIMM namespace


#endif  // NVDIMM_H__
