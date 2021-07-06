/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/generic/memory/lib/spd/spd_fields_ddr4.C $         */
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
/// @file spd_fields_ddr4.C
/// @brief SPD data fields forward declarations
///

// *HWP HWP Owner: Louis Stermole <stermole@us.ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: HB
// EKB-Mirror-To: hostboot

#include <generic/memory/lib/spd/spd_fields_ddr4.H>

namespace mss
{
namespace spd
{

// These "definitions" are needed to generate linkage for the static constexprs declared in the .H because of ODR-used

// fields<DDR4, BASE_CNFG>
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, BASE_CNFG>::BYTES_USED;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, BASE_CNFG>::TOTAL_BYTES;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, BASE_CNFG>::REVISION;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, BASE_CNFG>::DEVICE_TYPE;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, BASE_CNFG>::BASE_MODULE;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, BASE_CNFG>::HYBRID;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, BASE_CNFG>::HYBRID_MEDIA;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, BASE_CNFG>::SDRAM_CAPACITY;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, BASE_CNFG>::BANKS_ADDR_BITS;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, BASE_CNFG>::BANK_GROUP_BITS;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, BASE_CNFG>::COL_ADDR_BITS;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, BASE_CNFG>::ROW_ADDR_BITS;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, BASE_CNFG>::PRIM_SIGNAL_LOADING;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, BASE_CNFG>::PRIM_DIE_COUNT;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, BASE_CNFG>::PRIM_PACKAGE_TYPE;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, BASE_CNFG>::MAC;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, BASE_CNFG>::TMAW;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, BASE_CNFG>::PPR;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, BASE_CNFG>::SOFT_PPR;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, BASE_CNFG>::SEC_SIGNAL_LOADING;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, BASE_CNFG>::SEC_DENSITY_RATIO;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, BASE_CNFG>::SEC_DIE_COUNT;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, BASE_CNFG>::SEC_PACKAGE_TYPE;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, BASE_CNFG>::OPERABLE_FLD;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, BASE_CNFG>::ENDURANT_FLD;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, BASE_CNFG>::SDRAM_WIDTH;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, BASE_CNFG>::RANK_MIX;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, BASE_CNFG>::PACKAGE_RANKS;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, BASE_CNFG>::BUS_WIDTH;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, BASE_CNFG>::BUS_EXT_WIDTH;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, BASE_CNFG>::THERM_SENSOR;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, BASE_CNFG>::EXTENDED_MODULE_TYPE;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, BASE_CNFG>::FINE_TIMEBASE;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, BASE_CNFG>::MEDIUM_TIMEBASE;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, BASE_CNFG>::TCK_MIN;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, BASE_CNFG>::TCK_MAX;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, BASE_CNFG>::CL_FIRST_BYTE;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, BASE_CNFG>::CL_SECOND_BYTE;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, BASE_CNFG>::CL_THIRD_BYTE;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, BASE_CNFG>::CL_FOURTH_BYTE;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, BASE_CNFG>::TAA_MIN;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, BASE_CNFG>::TRCD_MIN;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, BASE_CNFG>::TRP_MIN;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, BASE_CNFG>::TRASMIN_MSN;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, BASE_CNFG>::TRASMIN_LSB;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, BASE_CNFG>::TRCMIN_MSN;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, BASE_CNFG>::TRCMIN_LSB;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, BASE_CNFG>::TRFC1MIN_LSB;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, BASE_CNFG>::TRFC1MIN_MSB;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, BASE_CNFG>::TRFC2MIN_LSB;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, BASE_CNFG>::TRFC2MIN_MSB;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, BASE_CNFG>::TRFC4MIN_LSB;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, BASE_CNFG>::TRFC4MIN_MSB;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, BASE_CNFG>::TFAWMIN_MSN;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, BASE_CNFG>::TFAWMIN_LSB;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, BASE_CNFG>::TRRD_S_MIN;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, BASE_CNFG>::TRRD_L_MIN;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, BASE_CNFG>::TCCD_L_MIN;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, BASE_CNFG>::TWRMIN_MSN;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, BASE_CNFG>::TWRMIN_LSB;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, BASE_CNFG>::TWTRMIN_S_MSN;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, BASE_CNFG>::TWTRMIN_S_LSB;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, BASE_CNFG>::TWTRMIN_L_MSN;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, BASE_CNFG>::TWTRMIN_L_LSB;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, BASE_CNFG>::OFFSET_TCCD_L_MIN;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, BASE_CNFG>::OFFSET_TRRD_L_MIN;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, BASE_CNFG>::OFFSET_TRRD_S_MIN;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, BASE_CNFG>::OFFSET_TRC_MIN;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, BASE_CNFG>::OFFSET_TRP_MIN;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, BASE_CNFG>::OFFSET_TRCD_MIN;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, BASE_CNFG>::OFFSET_TAA_MIN;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, BASE_CNFG>::OFFSET_TCK_MAX;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, BASE_CNFG>::OFFSET_TCK_MIN;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, BASE_CNFG>::CRC_LSB;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, BASE_CNFG>::CRC_MSB;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, BASE_CNFG>::CONTINUATION_CODES;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, BASE_CNFG>::LAST_NON_ZERO_BYTE;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, BASE_CNFG>::MODULE_MFG_LOCATION;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, BASE_CNFG>::MODULE_MFG_DATE_LSB;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, BASE_CNFG>::MODULE_MFG_DATE_MSB;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, BASE_CNFG>::MODULE_SERIAL_NUM_BYTE1;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, BASE_CNFG>::MODULE_SERIAL_NUM_BYTE2;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, BASE_CNFG>::MODULE_SERIAL_NUM_BYTE3;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, BASE_CNFG>::MODULE_SERIAL_NUM_BYTE4;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, BASE_CNFG>::MODULE_REV_CODE;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, BASE_CNFG>::DRAM_MFR_ID_CODE_LSB;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, BASE_CNFG>::DRAM_MFR_ID_CODE_MSB;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, BASE_CNFG>::DRAM_STEPPING;

// fields<DDR4, DDIMM_MODULE>
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, DDIMM_MODULE>::SPD_REV_DDIMM_MODULE;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, DDIMM_MODULE>::MODULE_BASE_HEIGHT;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, DDIMM_MODULE>::MODULE_HEIGHT_MAX;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, DDIMM_MODULE>::MAX_THICKNESS_BACK;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, DDIMM_MODULE>::MAX_THICKNESS_FRONT;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, DDIMM_MODULE>::DESIGN_REV;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, DDIMM_MODULE>::NUM_ROWS;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, DDIMM_MODULE>::NUM_BUFFERS;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, DDIMM_MODULE>::HEAT_SPREADER_SOL;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, DDIMM_MODULE>::HEAT_SPREADER_CHAR;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, DDIMM_MODULE>::CONTINUATION_CODE;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, DDIMM_MODULE>::LAST_NON_ZERO;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, DDIMM_MODULE>::DMB_REV;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, DDIMM_MODULE>::NUM_PACKAGE_RANKS_CHAN1;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, DDIMM_MODULE>::NUM_PACKAGE_RANKS_CHAN0;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, DDIMM_MODULE>::DATA_WIDTH;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, DDIMM_MODULE>::NUM_DIMM_CHANNELS;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, DDIMM_MODULE>::BUS_WIDTH_EXT;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, DDIMM_MODULE>::CHANNEL_DATA_WIDTH;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, DDIMM_MODULE>::MOD_THERMAL_SENSOR;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, DDIMM_MODULE>::PROTOCOL_SUPPORT;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, DDIMM_MODULE>::SPEED_SUPPORTED_LSB;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, DDIMM_MODULE>::ADDRESS_MIRROR;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, DDIMM_MODULE>::BYTE_ENABLES_LSB;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, DDIMM_MODULE>::BYTE_ENABLES_MSB;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, DDIMM_MODULE>::NIBBLE_ENABLES_LSB0;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, DDIMM_MODULE>::NIBBLE_ENABLES_MSB0;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, DDIMM_MODULE>::NIBBLE_ENABLES_LSB1;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, DDIMM_MODULE>::DDIMM_COMPAT;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, DDIMM_MODULE>::NUM_P_STATES;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, DDIMM_MODULE>::SPARE_DEVICE_LSB0;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, DDIMM_MODULE>::SPARE_DEVICE_MSB0;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, DDIMM_MODULE>::SPARE_DEVICE_LSB1;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, DDIMM_MODULE>::HI_DDR_SPEED_RATIO;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, DDIMM_MODULE>::SPD_CONTENT_REVISION;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, DDIMM_MODULE>::VIN_MGMT_NOMINAL;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, DDIMM_MODULE>::VIN_MGMT_OPERABLE;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, DDIMM_MODULE>::VIN_MGMT_ENDURANT;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, DDIMM_MODULE>::VIN_BULK_NOMINAL;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, DDIMM_MODULE>::VIN_BULK_OPERABLE;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, DDIMM_MODULE>::VIN_BULK_ENDURANT;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, DDIMM_MODULE>::PMIC0_SEQUENCE;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, DDIMM_MODULE>::PMIC0_CONT_CODE;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, DDIMM_MODULE>::PMIC0_LAST_NON_ZERO;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, DDIMM_MODULE>::PMIC0_REV;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, DDIMM_MODULE>::PMIC1_SEQUENCE;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, DDIMM_MODULE>::PMIC1_CONT_CODE;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, DDIMM_MODULE>::PMIC1_LAST_NON_ZERO;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, DDIMM_MODULE>::PMIC1_REV;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, DDIMM_MODULE>::PMIC0_SWA_VOLT_SET;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, DDIMM_MODULE>::PMIC0_SWA_RANGE_SELECT;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, DDIMM_MODULE>::PMIC0_SWA_VOLT_OFF;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, DDIMM_MODULE>::PMIC0_SWA_OFF_DIRECTION;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, DDIMM_MODULE>::PMIC0_SWA_DELAY;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, DDIMM_MODULE>::PMIC0_SWA_ORDER;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, DDIMM_MODULE>::PMIC0_SWB_VOLT_SET;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, DDIMM_MODULE>::PMIC0_SWB_RANGE_SELECT;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, DDIMM_MODULE>::PMIC0_SWB_VOLT_OFF;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, DDIMM_MODULE>::PMIC0_SWB_OFF_DIRECTION;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, DDIMM_MODULE>::PMIC0_SWB_DELAY;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, DDIMM_MODULE>::PMIC0_SWB_ORDER;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, DDIMM_MODULE>::PMIC0_SWC_VOLT_SET;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, DDIMM_MODULE>::PMIC0_SWC_RANGE_SELECT;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, DDIMM_MODULE>::PMIC0_SWC_VOLT_OFF;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, DDIMM_MODULE>::PMIC0_SWC_OFF_DIRECTION;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, DDIMM_MODULE>::PMIC0_SWC_DELAY;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, DDIMM_MODULE>::PMIC0_SWC_ORDER;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, DDIMM_MODULE>::PMIC0_SWD_VOLT_SET;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, DDIMM_MODULE>::PMIC0_SWD_RANGE_SELECT;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, DDIMM_MODULE>::PMIC0_SWD_VOLT_OFF;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, DDIMM_MODULE>::PMIC0_SWD_OFF_DIRECTION;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, DDIMM_MODULE>::PMIC0_SWD_DELAY;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, DDIMM_MODULE>::PMIC0_SWD_ORDER;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, DDIMM_MODULE>::PMIC0_PHASE_COMBIN;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, DDIMM_MODULE>::PMIC0_REDUNDANCY;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, DDIMM_MODULE>::PMIC1_SWA_VOLT_SET;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, DDIMM_MODULE>::PMIC1_SWA_RANGE_SELECT;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, DDIMM_MODULE>::PMIC1_SWA_VOLT_OFF;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, DDIMM_MODULE>::PMIC1_SWA_OFF_DIRECTION;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, DDIMM_MODULE>::PMIC1_SWA_DELAY;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, DDIMM_MODULE>::PMIC1_SWA_ORDER;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, DDIMM_MODULE>::PMIC1_SWB_VOLT_SET;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, DDIMM_MODULE>::PMIC1_SWB_RANGE_SELECT;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, DDIMM_MODULE>::PMIC1_SWB_VOLT_OFF;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, DDIMM_MODULE>::PMIC1_SWB_OFF_DIRECTION;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, DDIMM_MODULE>::PMIC1_SWB_DELAY;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, DDIMM_MODULE>::PMIC1_SWB_ORDER;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, DDIMM_MODULE>::PMIC1_SWC_VOLT_SET;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, DDIMM_MODULE>::PMIC1_SWC_RANGE_SELECT;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, DDIMM_MODULE>::PMIC1_SWC_VOLT_OFF;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, DDIMM_MODULE>::PMIC1_SWC_OFF_DIRECTION;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, DDIMM_MODULE>::PMIC1_SWC_DELAY;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, DDIMM_MODULE>::PMIC1_SWC_ORDER;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, DDIMM_MODULE>::PMIC1_SWD_VOLT_SET;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, DDIMM_MODULE>::PMIC1_SWD_RANGE_SELECT;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, DDIMM_MODULE>::PMIC1_SWD_VOLT_OFF;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, DDIMM_MODULE>::PMIC1_SWD_OFF_DIRECTION;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, DDIMM_MODULE>::PMIC1_SWD_DELAY;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, DDIMM_MODULE>::PMIC1_SWD_ORDER;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, DDIMM_MODULE>::PMIC1_PHASE_COMBIN;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, DDIMM_MODULE>::PMIC1_REDUNDANCY;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, DDIMM_MODULE>::MODULE_RCD;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, DDIMM_MODULE>::RCD_MFG_ID_LSB;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, DDIMM_MODULE>::RCD_MFG_ID_MSB;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, DDIMM_MODULE>::THERM_SENSOR_0_AVAIL;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, DDIMM_MODULE>::THERM_SENSOR_0_SECOND_AVAIL;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, DDIMM_MODULE>::THERM_SENSOR_0_USAGE;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, DDIMM_MODULE>::THERM_SENSOR_0_TYPE;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, DDIMM_MODULE>::THERM_SENSOR_0_I2C_ADDRESS;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, DDIMM_MODULE>::THERM_SENSOR_1_AVAIL;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, DDIMM_MODULE>::THERM_SENSOR_1_SECOND_AVAIL;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, DDIMM_MODULE>::THERM_SENSOR_1_USAGE;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, DDIMM_MODULE>::THERM_SENSOR_1_TYPE;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, DDIMM_MODULE>::THERM_SENSOR_1_I2C_ADDRESS;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, DDIMM_MODULE>::THERM_SENSOR_DIFF_AVAIL;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, DDIMM_MODULE>::THERM_SENSOR_DIFF_USAGE;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, DDIMM_MODULE>::THERM_SENSOR_DIFF_TYPE;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, DDIMM_MODULE>::THERM_SENSOR_DIFF_I2C_ADDRESS;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, DDIMM_MODULE>::THERM_SENSOR_0_SECOND_I2C_ADDRESS;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, DDIMM_MODULE>::THERM_SENSOR_1_SECOND_I2C_ADDRESS;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, DDIMM_MODULE>::THERM_SENSOR_1_SECOND_LOCATION;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, DDIMM_MODULE>::THERM_SENSOR_0_SECOND_LOCATION;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, DDIMM_MODULE>::THERM_SENSOR_1_LOCATION;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, DDIMM_MODULE>::THERM_SENSOR_0_LOCATION;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, DDIMM_MODULE>::SERIAL_NUMBER_LAST_BYTE;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, DDIMM_MODULE>::MODULE_MFG_ID_CODE_LSB;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, DDIMM_MODULE>::MODULE_MFG_ID_CODE_MSB;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, DDIMM_MODULE>::DRAM_MFR_ID_CODE_LSB;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR4, DDIMM_MODULE>::DRAM_MFR_ID_CODE_MSB;

}// spd
}// mss
