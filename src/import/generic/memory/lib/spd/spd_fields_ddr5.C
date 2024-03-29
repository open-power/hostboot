/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/generic/memory/lib/spd/spd_fields_ddr5.C $         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2022,2024                        */
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
#ifndef __PPE__
    constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, BASE_CNFG>::HYBRID;
    constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, BASE_CNFG>::HYBRID_MEDIA;
#endif
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, BASE_CNFG>::BASE_MODULE;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, BASE_CNFG>::DIE_PER_PACKAGE;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, BASE_CNFG>::DENSITY_PER_DIE;
#ifndef __PPE__
    constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, BASE_CNFG>::OPERABLE_VDD_FLD;
    constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, BASE_CNFG>::ENDURANT_VDD_FLD;
#endif

#ifndef __PPE__
    constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, BASE_CNFG>::BANK_ADDR_FLD;
    constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, BASE_CNFG>::BANK_GROUP_FLD;
    constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, BASE_CNFG>::OPERABLE_VDDQ_FLD;
    constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, BASE_CNFG>::ENDURANT_VDDQ_FLD;
#endif

#ifndef __PPE__
    constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, BASE_CNFG>::OPERABLE_VPP_FLD;
    constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, BASE_CNFG>::ENDURANT_VPP_FLD;
#endif

constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, BASE_CNFG>::HEIGHT_3DS;
#ifndef __PPE__
    constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, BASE_CNFG>::COL_ADDR_BITS;
#endif
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, BASE_CNFG>::ROW_ADDR_BITS;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, BASE_CNFG>::SDRAM_WIDTH;


//////////////////////////////////////
//// Bytes 19-93: timings
//////////////////////////////////////
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, BASE_CNFG>::TCK_MIN_LSB;
#ifndef __PPE__
    constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, BASE_CNFG>::TCK_MIN_MSB;
#endif
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, BASE_CNFG>::TCK_MAX_LSB;
#ifndef __PPE__
    constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, BASE_CNFG>::TCK_MAX_MSB;
#endif
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, BASE_CNFG>::CL_FIRST_BYTE;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, BASE_CNFG>::CL_SECOND_BYTE;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, BASE_CNFG>::CL_THIRD_BYTE;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, BASE_CNFG>::CL_FOURTH_BYTE;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, BASE_CNFG>::CL_FIFTH_BYTE;

constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, BASE_CNFG>::TAA_MIN_LSB;
#ifndef __PPE__
    constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, BASE_CNFG>::TAA_MIN_MSB;
#endif
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, BASE_CNFG>::TRCD_MIN_LSB;
#ifndef __PPE__
    constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, BASE_CNFG>::TRCD_MIN_MSB;
#endif
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, BASE_CNFG>::TRP_MIN_LSB;
#ifndef __PPE__
    constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, BASE_CNFG>::TRP_MIN_MSB;
    constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, BASE_CNFG>::TRAS_MIN_LSB;
    constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, BASE_CNFG>::TRAS_MIN_MSB;
    constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, BASE_CNFG>::TRC_MIN_LSB;
    constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, BASE_CNFG>::TRC_MIN_MSB;
#endif
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, BASE_CNFG>::TWR_MIN_LSB;
#ifndef __PPE__
    constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, BASE_CNFG>::TWR_MIN_MSB;
#endif
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, BASE_CNFG>::TRFC_SLR_MIN_LSB;
#ifndef __PPE__
    constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, BASE_CNFG>::TRFC_SLR_MIN_MSB;
    constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, BASE_CNFG>::TRFC_SLR2_MIN_LSB;
    constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, BASE_CNFG>::TRFC_SLR2_MIN_MSB;
#endif
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, BASE_CNFG>::TRFC_DLR_MIN_LSB;
#ifndef __PPE__
    constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, BASE_CNFG>::TRFC_DLR_MIN_MSB;
    constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, BASE_CNFG>::TRFC_DLR2_MIN_LSB;
    constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, BASE_CNFG>::TRFC_DLR2_MIN_MSB;
#endif
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, BASE_CNFG>::TRRD_L_MIN_LSB;
#ifndef __PPE__
    constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, BASE_CNFG>::TRRD_L_MIN_MSB;
    constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, BASE_CNFG>::TRRD_L_MIN_CLOCK;
#endif
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, BASE_CNFG>::TCCD_L_MIN_LSB;
#ifndef __PPE__
    constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, BASE_CNFG>::TCCD_L_MIN_MSB;
    constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, BASE_CNFG>::TCCD_L_MIN_CLOCK;
#endif
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, BASE_CNFG>::TCCD_L_WR_MIN_LSB;
#ifndef __PPE__
    constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, BASE_CNFG>::TCCD_L_WR_MIN_MSB;
    constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, BASE_CNFG>::TCCD_L_WR_MIN_CLOCK;
#endif
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, BASE_CNFG>::TFAW_MIN_LSB;
#ifndef __PPE__
    constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, BASE_CNFG>::TFAW_MIN_MSB;
    constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, BASE_CNFG>::TFAW_MIN_CLOCK;
#endif
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, BASE_CNFG>::TWTR_L_MIN_LSB;
#ifndef __PPE__
    constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, BASE_CNFG>::TWTR_L_MIN_MSB;
    constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, BASE_CNFG>::TWTR_L_MIN_CLOCK;
#endif
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, BASE_CNFG>::TWTR_S_MIN_LSB;
#ifndef __PPE__
    constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, BASE_CNFG>::TWTR_S_MIN_MSB;
    constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, BASE_CNFG>::TWTR_S_MIN_CLOCK;
#endif
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, BASE_CNFG>::TRTP_MIN_LSB;
#ifndef __PPE__
    constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, BASE_CNFG>::TRTP_MIN_MSB;
    constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, BASE_CNFG>::TRTP_MIN_CLOCK;
#endif

//////////////////////////////////////
//// Bytes 230-236: module information
//////////////////////////////////////
#ifndef __PPE__
    constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, BASE_CNFG>::RANK_MIX;
#endif
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, BASE_CNFG>::PACKAGE_RANKS_PER_PORT1;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, BASE_CNFG>::PACKAGE_RANKS_PER_PORT0;
#ifndef __PPE__
    constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, BASE_CNFG>::BUS_WIDTH_CHA;
    constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, BASE_CNFG>::BUS_WIDTH_CHB;
#endif
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, BASE_CNFG>::ENABLED_PHY_CHANNELS;
#ifndef __PPE__
    constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, BASE_CNFG>::CONTINUATION_CODES;
    constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, BASE_CNFG>::LAST_NON_ZERO_BYTE;
    constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, BASE_CNFG>::DRAM_MFR_ID_CODE_LSB;
    constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, BASE_CNFG>::DRAM_MFR_ID_CODE_MSB;
#endif

// fields<DDR5, DDIMM_MODULE>
#ifndef __PPE__
    constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::SPD_REV_DDIMM_MODULE;
    constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::HASH_SEQ_SERIAL_NUMBER;
    constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::SPD_MANF_ID_FIRST;
    constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::SPD_MANF_ID_SECOND;
    constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::SPD_DEVICE_REV_NUM;
#endif
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC0_MFG_CODE_FIRST;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC0_MFG_CODE_SECOND;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC0_DEVICE_REV_NUM;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC1_MFG_CODE_FIRST;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC1_MFG_CODE_SECOND;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC1_DEVICE_REV_NUM;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC2_MFG_CODE_FIRST;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC2_MFG_CODE_SECOND;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC2_DEVICE_REV_NUM;
#ifndef __PPE__
    constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::THERMAL_SENSOR0_MANF_ID_CODE_FIRST;
    constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::THERMAL_SENSOR0_MANF_ID_CODE_SECOND;
#endif
#ifndef __PPE__
    constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::THERMAL_SENSORS_CFG_DEVICES;
#endif
#ifndef __PPE__
    constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::THERMAL_SENSOR0_REV_NUM;
    constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::DRAM_SPEC_LEVEL;
    constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::SPD_SPEC_LEVEL;
    constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC0_SPEC_LEVEL;
    constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC1_SPEC_LEVEL;
    constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC2_SPEC_LEVEL;
    constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::THERMAL_SENSOR0_SPEC;
#endif
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::MODULE_BASE_HEIGHT;
#ifndef __PPE__
    constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::MODULE_HEIGHT_MAX;
    constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::MAX_THICKNESS_BACK;
    constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::MAX_THICKNESS_FRONT;
#endif
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::DESIGN_REV;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::DESIGN_REF_CARD;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::REGISTER_TYPE;
#ifndef __PPE__
    constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::NUM_BUFFERS;
    constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::NUM_PACKAGE_RANKS_PORT1;
    constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::NUM_PACKAGE_RANKS_PORT0;
#endif
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC3_MFG_CODE_FIRST;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC3_MFG_CODE_SECOND;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC3_DEVICE_REV_NUM;
#ifndef __PPE__
    constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC3_SPEC_LEVEL;
    constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::THERMAL_SENSOR1_MANF_ID_CODE_FIRST;
    constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::THERMAL_SENSOR1_MANF_ID_CODE_SECOND;
    constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::THERMAL_SENSOR1_REV_NUM;
    constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::THERMAL_SENSOR1_SPEC_LEVEL;
    constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::THERMAL_SENSOR2_MANF_ID_CODE_FIRST;
    constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::THERMAL_SENSOR2_MANF_ID_CODE_SECOND;
    constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::THERMAL_SENSOR2_REV_NUM;
    constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::THERMAL_SENSOR2_SPEC_LEVEL;
    constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::THERMAL_SENSOR3_MANF_ID_CODE_FIRST;
    constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::THERMAL_SENSOR3_MANF_ID_CODE_SECOND;
    constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::THERMAL_SENSOR3_REV_NUM;
    constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::THERMAL_SENSOR3_SPEC_LEVEL;
#endif
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::THERMAL_SENSOR_3_LOCATION;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::THERMAL_SENSOR_2_LOCATION;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::THERMAL_SENSOR_1_LOCATION;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::THERMAL_SENSOR_0_LOCATION;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::THERMAL_SENSOR_0_AVAIL;
#ifndef __PPE__
    constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::THERMAL_SENSOR_0_TYPE;
#endif
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::THERMAL_SENSOR_0_USAGE;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::THERMAL_SENSOR_1_AVAIL;
#ifndef __PPE__
    constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::THERMAL_SENSOR_1_TYPE;
#endif
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::THERMAL_SENSOR_1_USAGE;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::THERMAL_SENSOR_2_AVAIL;
#ifndef __PPE__
    constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::THERMAL_SENSOR_2_TYPE;
#endif
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::THERMAL_SENSOR_2_USAGE;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::THERMAL_SENSOR_3_AVAIL;
#ifndef __PPE__
    constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::THERMAL_SENSOR_3_TYPE;
#endif
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::THERMAL_SENSOR_3_USAGE;
#ifndef __PPE__
    constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::THERMAL_SENSOR_0_I2C_ADDRESS;
    constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::THERMAL_SENSOR_1_I2C_ADDRESS;
    constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::THERMAL_SENSOR_2_I2C_ADDRESS;
    constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::THERMAL_SENSOR_3_I2C_ADDRESS;
#endif
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::THERMAL_SENSOR_DIFF_AVAIL;
#ifndef __PPE__
    constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::THERMAL_SENSOR_DIFF_TYPE;
    constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::THERMAL_SENSOR_DIFF_USAGE;
    constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::THERMAL_SENSOR_DIFF_I2C_ADDRESS;
#endif
#ifndef __PPE__
    constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::MODULE_RCD_MEDIA_CONTROLLER_TYPE;
    constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::MODULE_RCD_JEDEC_COMPLIANT;
#endif
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::MODULE_RCD;
#ifndef __PPE__
    constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::RCD_MFG_ID_LSB;
    constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::RCD_MFG_ID_MSB;
#endif
#ifndef __PPE__
    constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::RCD_REV_NUM;
    constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::RCD0_I2C_ADDR;
    constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::RCD1_I2C_ADDR;
#endif
#ifndef __PPE__
    constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::SPD_CONTENT_REVISION;
#endif
#ifndef __PPE__
    constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::SPD_REDUNDANCY;
    constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::SPD_REDUNDANCY_I2C_ADDR;
    constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::ORING_MOSFET_SMALL;
    constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::ORING_MOSFET_BIG;
    constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::DMB_I2C_ADDRESS;
    constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::DMB_MFG_CODE1_CONT_CODE;
    constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::DMB_MFG_CODE2_LAST_NON_ZERO;
#endif
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::DMB_REV;
#ifndef __PPE__
    constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::ADC_I2C_ADDRESS;
    constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC_STATUS_MASK0;
    constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC_STATUS_MASK1;
    constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC_PF_THRESHOLD;
    constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC0_IIC_ADDRESS;
    constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC1_IIC_ADDRESS;
    constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC2_IIC_ADDRESS;
    constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC3_IIC_ADDRESS;
    constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC0_SUPPLY_VOLTAGE;
#endif
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC0_SEQUENCE;;
#ifndef __PPE__
    constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC1_SUPPLY_VOLTAGE;
#endif
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC1_SEQUENCE;
#ifndef __PPE__
    constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC2_SUPPLY_VOLTAGE;
#endif
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC2_SEQUENCE;
#ifndef __PPE__
    constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC3_SUPPLY_VOLTAGE;
#endif
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC3_SEQUENCE;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC0_VOLT_RANGE_OFFSET_SWA;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC0_VOLT_RANGE_OFFSET_SWB;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC0_VOLT_RANGE_OFFSET_SWC;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC0_VOLT_RANGE_OFFSET_SWD;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC1_VOLT_RANGE_OFFSET_SWA;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC1_VOLT_RANGE_OFFSET_SWB;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC1_VOLT_RANGE_OFFSET_SWC;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC1_VOLT_RANGE_OFFSET_SWD;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC2_VOLT_RANGE_OFFSET_SWA;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC2_VOLT_RANGE_OFFSET_SWB;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC2_VOLT_RANGE_OFFSET_SWC;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC2_VOLT_RANGE_OFFSET_SWD;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC3_VOLT_RANGE_OFFSET_SWA;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC3_VOLT_RANGE_OFFSET_SWB;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC3_VOLT_RANGE_OFFSET_SWC;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC3_VOLT_RANGE_OFFSET_SWD;
#ifndef __PPE__
    constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC0_VOLT_DOMAINS_SWA;
    constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC0_VOLT_DOMAINS_SWB;
    constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC0_VOLT_DOMAINS_SWC;
    constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC0_VOLT_DOMAINS_SWD;
    constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC1_VOLT_DOMAINS_SWA;
    constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC1_VOLT_DOMAINS_SWB;
    constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC1_VOLT_DOMAINS_SWC;
    constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC1_VOLT_DOMAINS_SWD;
    constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC2_VOLT_DOMAINS_SWA;
    constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC2_VOLT_DOMAINS_SWB;
    constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC2_VOLT_DOMAINS_SWC;
    constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC2_VOLT_DOMAINS_SWD;
    constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC3_VOLT_DOMAINS_SWA;
    constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC3_VOLT_DOMAINS_SWB;
    constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC3_VOLT_DOMAINS_SWC;
    constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC3_VOLT_DOMAINS_SWD;
#endif
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC0_SWA_VOLT_SET;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC0_SWA_RANGE_SELECT;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC0_SWA_VOLT_OFF;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC0_SWA_OFF_DIRECTION;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC0_SWA_DELAY;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC0_SWA_ORDER;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC0_SWA_SEQUENCE;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC0_SWB_VOLT_SET;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC0_SWB_RANGE_SELECT;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC0_SWB_VOLT_OFF;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC0_SWB_OFF_DIRECTION;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC0_SWB_DELAY;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC0_SWB_ORDER;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC0_SWB_SEQUENCE;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC0_SWC_VOLT_SET;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC0_SWC_RANGE_SELECT;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC0_SWC_VOLT_OFF;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC0_SWC_OFF_DIRECTION;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC0_SWC_DELAY;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC0_SWC_ORDER;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC0_SWC_SEQUENCE;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC0_SWD_VOLT_SET;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC0_SWD_RANGE_SELECT;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC0_SWD_VOLT_OFF;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC0_SWD_OFF_DIRECTION;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC0_SWD_DELAY;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC0_SWD_ORDER;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC0_SWD_SEQUENCE;
#ifndef __PPE__
    constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC0_REDUNDANCY;
#endif
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC0_PHASE_COMBIN;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC1_SWA_VOLT_SET;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC1_SWA_RANGE_SELECT;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC1_SWA_VOLT_OFF;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC1_SWA_OFF_DIRECTION;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC1_SWA_DELAY;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC1_SWA_ORDER;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC1_SWA_SEQUENCE;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC1_SWB_VOLT_SET;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC1_SWB_RANGE_SELECT;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC1_SWB_VOLT_OFF;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC1_SWB_OFF_DIRECTION;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC1_SWB_DELAY;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC1_SWB_ORDER;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC1_SWB_SEQUENCE;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC1_SWC_VOLT_SET;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC1_SWC_RANGE_SELECT;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC1_SWC_VOLT_OFF;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC1_SWC_OFF_DIRECTION;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC1_SWC_DELAY;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC1_SWC_ORDER;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC1_SWC_SEQUENCE;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC1_SWD_VOLT_SET;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC1_SWD_RANGE_SELECT;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC1_SWD_VOLT_OFF;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC1_SWD_OFF_DIRECTION;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC1_SWD_DELAY;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC1_SWD_ORDER;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC1_SWD_SEQUENCE;
#ifndef __PPE__
    constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC1_REDUNDANCY;
#endif
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC1_PHASE_COMBIN;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC2_SWA_VOLT_SET;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC2_SWA_RANGE_SELECT;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC2_SWA_VOLT_OFF;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC2_SWA_OFF_DIRECTION;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC2_SWA_DELAY;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC2_SWA_ORDER;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC2_SWA_SEQUENCE;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC2_SWB_VOLT_SET;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC2_SWB_RANGE_SELECT;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC2_SWB_VOLT_OFF;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC2_SWB_OFF_DIRECTION;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC2_SWB_DELAY;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC2_SWB_ORDER;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC2_SWB_SEQUENCE;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC2_SWC_VOLT_SET;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC2_SWC_RANGE_SELECT;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC2_SWC_VOLT_OFF;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC2_SWC_OFF_DIRECTION;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC2_SWC_DELAY;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC2_SWC_ORDER;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC2_SWC_SEQUENCE;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC2_SWD_VOLT_SET;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC2_SWD_RANGE_SELECT;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC2_SWD_VOLT_OFF;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC2_SWD_OFF_DIRECTION;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC2_SWD_DELAY;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC2_SWD_ORDER;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC2_SWD_SEQUENCE;
#ifndef __PPE__
    constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC2_REDUNDANCY;
#endif
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC2_PHASE_COMBIN;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC3_SWA_VOLT_SET;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC3_SWA_RANGE_SELECT;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC3_SWA_VOLT_OFF;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC3_SWA_OFF_DIRECTION;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC3_SWA_DELAY;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC3_SWA_ORDER;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC3_SWA_SEQUENCE;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC3_SWB_VOLT_SET;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC3_SWB_RANGE_SELECT;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC3_SWB_VOLT_OFF;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC3_SWB_OFF_DIRECTION;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC3_SWB_DELAY;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC3_SWB_ORDER;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC3_SWB_SEQUENCE;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC3_SWC_VOLT_SET;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC3_SWC_RANGE_SELECT;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC3_SWC_VOLT_OFF;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC3_SWC_OFF_DIRECTION;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC3_SWC_DELAY;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC3_SWC_ORDER;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC3_SWC_SEQUENCE;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC3_SWD_VOLT_SET;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC3_SWD_RANGE_SELECT;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC3_SWD_VOLT_OFF;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC3_SWD_OFF_DIRECTION;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC3_SWD_DELAY;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC3_SWD_ORDER;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC3_SWD_SEQUENCE;
#ifndef __PPE__
    constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC3_REDUNDANCY;
#endif
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PMIC3_PHASE_COMBIN;
#ifndef __PPE__
    constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::VIN_MGMT_NOMINAL;
    constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::VIN_MGMT_OPERABLE;
    constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::VIN_MGMT_ENDURANT;
    constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::VIN_BULK_NOMINAL;
    constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::VIN_BULK_OPERABLE;
    constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::VIN_BULK_ENDURANT;
#endif
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::HEAT_SPREADER_SOL;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::HEAT_SPREADER_CHAR;
#ifndef __PPE__
    constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PROTOCOL_SUPPORT;
    constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::SPEED_SUPPORTED_LSB;
#endif
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PHY_A0_B0_MEM_ALERT_PULL_UP_VALUE;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PHY_A1_B1_MEM_ALERT_PULL_UP_VALUE;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PHY_A0_B0_MEM_ALERT;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PHY_A1_B1_MEM_ALERT;
#ifndef __PPE__
    constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::ADDRESS_MIRROR;
#endif
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::BYTE_ENABLES_LSB;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::BYTE_ENABLES_MSB;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::NIBBLE_ENABLES_LSB0;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::NIBBLE_ENABLES_MSB0;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::NIBBLE_ENABLES_LSB1;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::REDUNDANT_CS_EN_CHA0;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::REDUNDANT_CS_EN_CHB0;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::REDUNDANT_CS_EN_CHA1;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::REDUNDANT_CS_EN_CHB1;
#ifndef __PPE__
    constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::MEMORY_CHA0_EXIST;
    constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::MEMORY_CHB0_EXIST;
    constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::MEMORY_CHA1_EXIST;
    constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::MEMORY_CHB1_EXIST;
    constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::SPARE_DEVICE_LSB0;
#endif
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::SPARE_DEVICE_MSB0;
#ifndef __PPE__
    constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::SPARE_DEVICE_LSB1;
#endif
#ifndef __PPE__
    constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::HI_DDR_SPEED_RATIO;
#endif
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PHY_A0_B0_CAL_RESISTOR;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::PHY_A1_B1_CAL_RESISTOR;
#ifndef __PPE__
    constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::SERIAL_NUMBER_LAST_BYTE;
#endif
#ifndef __PPE__
    constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::MODULE_MFG_ID_CODE_LSB;
    constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::MODULE_MFG_ID_CODE_MSB;
    constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::DRAM_MFR_ID_CODE_LSB;
    constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::DRAM_MFR_ID_CODE_MSB;
#endif

constexpr mss::field_t<mss::endian::LITTLE>
fields<DDR5, DDIMM_MODULE>::SERIAL_NUMBER_FIELDS[fields<DDR5, DDIMM_MODULE>::SERIAL_NUMBER_LEN];

}// spd
}// mss
