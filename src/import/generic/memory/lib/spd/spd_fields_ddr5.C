/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/generic/memory/lib/spd/spd_fields_ddr5.C $         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2022                             */
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
/// @file spd_fields_ddr5.C
/// @brief DDR5 SPD data fields forward declarations
///

// *HWP HWP Owner: Louis Stermole <stermole@us.ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: HB
// EKB-Mirror-To: hostboot

#include <generic/memory/lib/spd/spd_fields_ddr5.H>

namespace mss
{
namespace spd
{

// These "definitions" are needed to generate linkage for the static constexprs declared in the .H because of ODR-used
// fields<DDR5, BASE_CNFG>

// Note: Spacing out bytes a bit to hopefully reduce merge conflicts
//////////////////////////////////////
//// Bytes 0-18: prior to timings
//////////////////////////////////////
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, BASE_CNFG>::HYBRID;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, BASE_CNFG>::HYBRID_MEDIA;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, BASE_CNFG>::BASE_MODULE;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, BASE_CNFG>::DIE_PER_PACKAGE;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, BASE_CNFG>::DENSITY_PER_DIE;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, BASE_CNFG>::OPERABLE_VDD_FLD;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, BASE_CNFG>::ENDURANT_VDD_FLD;

constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, BASE_CNFG>::OPERABLE_VDDQ_FLD;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, BASE_CNFG>::ENDURANT_VDDQ_FLD;

constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, BASE_CNFG>::OPERABLE_VPP_FLD;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, BASE_CNFG>::ENDURANT_VPP_FLD;

constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, BASE_CNFG>::HEIGHT_3DS;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, BASE_CNFG>::COL_ADDR_BITS;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, BASE_CNFG>::ROW_ADDR_BITS;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, BASE_CNFG>::SDRAM_WIDTH;


//////////////////////////////////////
//// Bytes 19-93: timings
//////////////////////////////////////
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, BASE_CNFG>::TCK_MIN_LSB;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, BASE_CNFG>::TCK_MIN_MSB;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, BASE_CNFG>::TCK_MAX_LSB;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, BASE_CNFG>::TCK_MAX_MSB;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, BASE_CNFG>::CL_FIRST_BYTE;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, BASE_CNFG>::CL_SECOND_BYTE;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, BASE_CNFG>::CL_THIRD_BYTE;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, BASE_CNFG>::CL_FOURTH_BYTE;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, BASE_CNFG>::CL_FIFTH_BYTE;

constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, BASE_CNFG>::TAA_MIN_LSB;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, BASE_CNFG>::TAA_MIN_MSB;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, BASE_CNFG>::TRCD_MIN_LSB;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, BASE_CNFG>::TRCD_MIN_MSB;

//////////////////////////////////////
//// Bytes 230-236: module information
//////////////////////////////////////
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, BASE_CNFG>::RANK_MIX;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, BASE_CNFG>::PACKAGE_RANKS_PER_CHANNEL;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, BASE_CNFG>::BUS_WIDTH;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, BASE_CNFG>::BUS_EXT_WIDTH;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, BASE_CNFG>::CHANNELS_PER_DIMM;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, BASE_CNFG>::CONTINUATION_CODES;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, BASE_CNFG>::LAST_NON_ZERO_BYTE;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, BASE_CNFG>::DRAM_MFR_ID_CODE_LSB;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, BASE_CNFG>::DRAM_MFR_ID_CODE_MSB;

// fields<DDR5, DDIMM_MODULE>
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::SPD_REV_DDIMM_MODULE;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::HI_DDR_SPEED_RATIO;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::MODULE_BASE_HEIGHT;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::MODULE_HEIGHT_MAX;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::MAX_THICKNESS_BACK;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::MAX_THICKNESS_FRONT;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::DESIGN_REV;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::DESIGN_REF_CARD;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::REGISTER_TYPE;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::NUM_ROWS;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::NUM_BUFFERS;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::HEAT_SPREADER_SOL;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::HEAT_SPREADER_CHAR;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::DMB_REV;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::NUM_PACKAGE_RANKS_CHAN1;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::NUM_PACKAGE_RANKS_CHAN0;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::DATA_WIDTH;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::ENABLED_PHY_CH;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::BUS_WIDTH_CH_A;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::BUS_WIDTH_CH_B;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::MOD_THERMAL_SENSOR;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PROTOCOL_SUPPORT;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::SPEED_SUPPORTED_LSB;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::ADDRESS_MIRROR;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::BYTE_ENABLES_LSB;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::BYTE_ENABLES_MSB;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::NIBBLE_ENABLES_LSB0;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::NIBBLE_ENABLES_MSB0;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::NIBBLE_ENABLES_LSB1;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::DDIMM_COMPAT;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::SPARE_DEVICE_LSB0;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::SPARE_DEVICE_MSB0;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::SPARE_DEVICE_LSB1;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::SPD_CONTENT_REVISION;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::VIN_MGMT_NOMINAL;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::VIN_MGMT_OPERABLE;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::VIN_MGMT_ENDURANT;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::VIN_BULK_NOMINAL;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::VIN_BULK_OPERABLE;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::VIN_BULK_ENDURANT;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC0_SEQUENCE;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC1_SEQUENCE;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC2_SEQUENCE;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC3_SEQUENCE;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC0_CONT_CODE;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC0_LAST_NON_ZERO;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC0_REV;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC1_CONT_CODE;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC1_LAST_NON_ZERO;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC1_REV;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC2_CONT_CODE;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC2_LAST_NON_ZERO;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC2_REV;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC3_CONT_CODE;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC3_LAST_NON_ZERO;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC3_REV;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC0_SWA_VOLT_SET;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC0_SWA_RANGE_SELECT;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC0_SWA_VOLT_OFF;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC0_SWA_OFF_DIRECTION;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC0_SWA_DELAY;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC0_SWA_ORDER;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC0_SWB_VOLT_SET;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC0_SWB_RANGE_SELECT;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC0_SWB_VOLT_OFF;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC0_SWB_OFF_DIRECTION;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC0_SWB_DELAY;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC0_SWB_ORDER;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC0_SWC_VOLT_SET;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC0_SWC_RANGE_SELECT;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC0_SWC_VOLT_OFF;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC0_SWC_OFF_DIRECTION;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC0_SWC_DELAY;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC0_SWC_ORDER;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC0_SWD_VOLT_SET;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC0_SWD_RANGE_SELECT;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC0_SWD_VOLT_OFF;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC0_SWD_OFF_DIRECTION;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC0_SWD_DELAY;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC0_SWD_ORDER;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC0_PHASE_COMBIN;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC0_REDUNDANCY;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC1_SWA_VOLT_SET;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC1_SWA_RANGE_SELECT;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC1_SWA_VOLT_OFF;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC1_SWA_OFF_DIRECTION;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC1_SWA_DELAY;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC1_SWA_ORDER;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC1_SWB_VOLT_SET;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC1_SWB_RANGE_SELECT;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC1_SWB_VOLT_OFF;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC1_SWB_OFF_DIRECTION;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC1_SWB_DELAY;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC1_SWB_ORDER;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC1_SWC_VOLT_SET;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC1_SWC_RANGE_SELECT;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC1_SWC_VOLT_OFF;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC1_SWC_OFF_DIRECTION;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC1_SWC_DELAY;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC1_SWC_ORDER;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC1_SWD_VOLT_SET;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC1_SWD_RANGE_SELECT;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC1_SWD_VOLT_OFF;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC1_SWD_OFF_DIRECTION;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC1_SWD_DELAY;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC1_SWD_ORDER;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC1_PHASE_COMBIN;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC1_REDUNDANCY;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC2_SWA_VOLT_SET;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC2_SWA_RANGE_SELECT;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC2_SWA_VOLT_OFF;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC2_SWA_OFF_DIRECTION;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC2_SWA_DELAY;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC2_SWA_ORDER;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC2_SWB_VOLT_SET;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC2_SWB_RANGE_SELECT;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC2_SWB_VOLT_OFF;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC2_SWB_OFF_DIRECTION;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC2_SWB_DELAY;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC2_SWB_ORDER;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC2_SWC_VOLT_SET;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC2_SWC_RANGE_SELECT;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC2_SWC_VOLT_OFF;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC2_SWC_OFF_DIRECTION;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC2_SWC_DELAY;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC2_SWC_ORDER;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC2_SWD_VOLT_SET;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC2_SWD_RANGE_SELECT;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC2_SWD_VOLT_OFF;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC2_SWD_OFF_DIRECTION;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC2_SWD_DELAY;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC2_SWD_ORDER;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC2_PHASE_COMBIN;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC3_SWA_VOLT_SET;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC3_SWA_RANGE_SELECT;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC3_SWA_VOLT_OFF;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC3_SWA_OFF_DIRECTION;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC3_SWA_DELAY;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC3_SWA_ORDER;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC3_SWB_VOLT_SET;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC3_SWB_RANGE_SELECT;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC3_SWB_VOLT_OFF;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC3_SWB_OFF_DIRECTION;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC3_SWB_DELAY;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC3_SWB_ORDER;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC3_SWC_VOLT_SET;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC3_SWC_RANGE_SELECT;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC3_SWC_VOLT_OFF;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC3_SWC_OFF_DIRECTION;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC3_SWC_DELAY;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC3_SWC_ORDER;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC3_SWD_VOLT_SET;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC3_SWD_RANGE_SELECT;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC3_SWD_VOLT_OFF;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC3_SWD_OFF_DIRECTION;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC3_SWD_DELAY;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC3_SWD_ORDER;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC3_PHASE_COMBIN;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::MODULE_RCD;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::RCD_MFG_ID_LSB;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::RCD_MFG_ID_MSB;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::THERM_SENSOR_0_AVAIL;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::THERM_SENSOR_0_USAGE;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::THERM_SENSOR_0_TYPE;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::THERM_SENSOR_1_AVAIL;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::THERM_SENSOR_1_USAGE;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::THERM_SENSOR_1_TYPE;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::THERM_SENSOR_2_AVAIL;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::THERM_SENSOR_2_USAGE;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::THERM_SENSOR_2_TYPE;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::THERM_SENSOR_3_AVAIL;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::THERM_SENSOR_3_USAGE;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::THERM_SENSOR_3_TYPE;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::THERM_SENSOR_0_I2C_ADDRESS;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::THERM_SENSOR_1_I2C_ADDRESS;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::THERM_SENSOR_2_I2C_ADDRESS;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::THERM_SENSOR_3_I2C_ADDRESS;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::THERM_SENSOR_3_LOCATION;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::THERM_SENSOR_2_LOCATION;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::THERM_SENSOR_1_LOCATION;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::THERM_SENSOR_0_LOCATION;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::THERM_SENSOR_DIFF_AVAIL;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::THERM_SENSOR_DIFF_USAGE;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::THERM_SENSOR_DIFF_TYPE;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::THERM_SENSOR_DIFF_I2C_ADDRESS;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::SERIAL_NUMBER_LAST_BYTE;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::MODULE_MFG_ID_CODE_LSB;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::MODULE_MFG_ID_CODE_MSB;

}// spd
}// mss
