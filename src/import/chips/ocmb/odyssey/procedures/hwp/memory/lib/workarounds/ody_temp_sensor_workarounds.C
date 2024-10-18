/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/memory/lib/workarounds/ody_temp_sensor_workarounds.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2024                        */
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
// EKB-Mirror-To: hostboot

///
/// @file ody_temp_sensor_workarounds.C
/// @brief Workarounds for 4U temp sensor usage based on MRW attr
///
// *HWP HWP Owner: Preetham H R <preeragh@in.ibm.com>
// *HWP HWP Backup: Md Yasser <mohammed.yasser11@ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#include <fapi2.H>
#include <generic/memory/lib/utils/find.H>
#include <lib/shared/ody_consts.H>
#include <lib/power_thermal/ody_thermal_init_utils.H>

namespace mss
{
namespace ody
{
namespace workarounds
{

#ifndef __PPE__
///
/// @brief Changes temp sensor usage depending on MRW attr and height of DIMM
/// @param[in] i_target ocmb target on which to operate
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success
/// @note 4U DDIMMs would use MEMCTRL, MC_EXT, and MC_DRAM sensor types
/// (where MC_EXT is really PMIC, and MC_DRAM is really DIMM).
/// Helper function to unit test this functionality
///
fapi2::ReturnCode change_temp_sensor_usage_helper(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target)
{
    uint8_t l_module_height = 0;
    uint8_t l_sensor_usage = fapi2::ENUM_ATTR_MEM_EFF_THERM_SENSOR_0_USAGE_DISABLED;

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MEM_EFF_DRAM_MODULE_HEIGHT, i_target, l_module_height));

    if (l_module_height != fapi2::ENUM_ATTR_MEM_EFF_DRAM_MODULE_HEIGHT_4U)
    {
        FAPI_INF_NO_SBE("Skipping " GENTARGTIDFORMAT " as height is not 4U", GENTARGTID(i_target));
        return fapi2::FAPI2_RC_SUCCESS;
    }

    for(uint8_t l_sensor_index = 0; l_sensor_index < NUM_DTS; l_sensor_index++ )
    {
        FAPI_TRY(mss::ody::thermal::get_therm_sensor_usage[l_sensor_index](i_target,
                 l_sensor_usage));

        if (l_sensor_usage == fapi2::ENUM_ATTR_MEM_EFF_THERM_SENSOR_0_USAGE_DRAM)
        {
            FAPI_DBG(" " GENTARGTIDFORMAT " Changing temperature sensor %d usage from DRAM to DRAM_AND_MEM_BUF_EXT",
                     GENTARGTID(i_target), l_sensor_index);
            FAPI_TRY(mss::ody::thermal::set_therm_sensor_usage[l_sensor_index](i_target,
                     fapi2::ENUM_ATTR_MEM_EFF_THERM_SENSOR_0_USAGE_DRAM_AND_MEM_BUF_EXT));

        }
        else if (l_sensor_usage == fapi2::ENUM_ATTR_MEM_EFF_THERM_SENSOR_0_USAGE_PMIC)
        {
            FAPI_DBG(" " GENTARGTIDFORMAT " Changing temperature sensor %d usage from PMIC to MEM_BUF_EXT",
                     GENTARGTID(i_target), l_sensor_index);
            FAPI_TRY(mss::ody::thermal::set_therm_sensor_usage[l_sensor_index](i_target,
                     fapi2::ENUM_ATTR_MEM_EFF_THERM_SENSOR_0_USAGE_MEM_BUF_EXT));
        }
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Disables DIMM Thermal sensor that are not configured to use
/// @param[in] i_target ocmb target on which to operate
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success
///
fapi2::ReturnCode disable_unused_temp_sensor(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target)
{
    static constexpr uint8_t NULL_SENSOR_POS = 4;
    uint8_t l_sensor_usage = fapi2::ENUM_ATTR_MEM_EFF_THERM_SENSOR_0_USAGE_DISABLED;
    uint8_t l_desired_sensors[NUM_CONFIG_DTS] = {NULL_SENSOR_POS, NULL_SENSOR_POS};
    uint8_t l_therm_sensor_rd_override = fapi2::ENUM_ATTR_MEM_EFF_THERM_SENSOR_READ_OVERRIDE_FALSE;

    // Get ATTR_MEM_EFF_THERM_SENSOR_READ_OVERRIDE Attr Value
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MEM_EFF_THERM_SENSOR_READ_OVERRIDE, i_target, l_therm_sensor_rd_override));

    // If this attribute is TRUE then we want to have ody read all available on-board temperature sensors,
    // so we don't want to set the usage to DISABLED for this case.

    if (l_therm_sensor_rd_override == fapi2::ENUM_ATTR_MEM_EFF_THERM_SENSOR_READ_OVERRIDE_FALSE)
    {
        FAPI_TRY(mss::ody::thermal::get_desired_dts(i_target, l_desired_sensors));

        for(uint8_t l_sensor_index = 0; l_sensor_index < NUM_DTS; l_sensor_index++ )
        {
            FAPI_TRY(mss::ody::thermal::get_therm_sensor_usage[l_sensor_index](i_target,
                     l_sensor_usage));

            if ((l_sensor_usage != fapi2::ENUM_ATTR_MEM_EFF_THERM_SENSOR_0_USAGE_DISABLED) &&
                !(l_desired_sensors[DRAM_SENSOR_INDEX] == l_sensor_index || l_desired_sensors[PMIC_SENSOR_INDEX] == l_sensor_index))
            {
                FAPI_TRY(mss::ody::thermal::set_therm_sensor_usage[l_sensor_index](i_target,
                         fapi2::ENUM_ATTR_MEM_EFF_THERM_SENSOR_0_USAGE_DISABLED));
            }

        }
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Changes temp sensor usage depending on MRW attr and height of DIMM
/// @param[in] i_target ocmb target on which to operate
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success
/// @note 4U DDIMMs would use MEMCTRL, MC_EXT, and MC_DRAM sensor types
/// (where MC_EXT is really PMIC, and MC_DRAM is really DIMM)
///
fapi2::ReturnCode change_temp_sensor_usage(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target)
{
    uint8_t l_therm_sensor_override = 0;

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MSS_MRW_OVERRIDE_THERM_SENSOR_USAGE, fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(),
                           l_therm_sensor_override));

    if (l_therm_sensor_override == fapi2::ENUM_ATTR_MSS_MRW_OVERRIDE_THERM_SENSOR_USAGE_ENABLED)
    {
        FAPI_TRY(change_temp_sensor_usage_helper(i_target));
    }

fapi_try_exit:
    return fapi2::current_err;
}
#endif

///
/// @brief Reads the octs, dts0, dts1, dts2, dts3 and writes to the scratch register
/// @tparam START_POS starting position in the scratch register
/// @param[in] i_snsc_thermal_data sensor cache buffer data
/// @param[in,out] io_scratch_buffer Output scratch buffer that has the sensor cache values
/// @return none
///
template<uint8_t START_POS>
void  wr_reg_data_to_scratch_helper(const fapi2::buffer<uint64_t>& i_snsc_thermal_data,
                                    fapi2::buffer<uint64_t>& io_scratch_buffer)
{
    const uint8_t PRESENTBIT_OFFSET = 1;
    const uint8_t VALIDBIT_OFFSET = 2;
    const uint8_t ERRORBIT_OFFSET = 3;
    const uint8_t THERMALDATA_OFFSET = 4;
    const uint8_t THERMALDATA_LEN = 16;
    uint16_t l_thermal_data = 0;

    i_snsc_thermal_data.extractToRight<scomt::ody::ODC_MMIO_SNSC_OCTHERM_THERMALDATA, scomt::ody::ODC_MMIO_SNSC_OCTHERM_THERMALDATA_LEN>
    (l_thermal_data);

    io_scratch_buffer.writeBit < START_POS + PRESENTBIT_OFFSET >
    (i_snsc_thermal_data.getBit<scomt::ody::ODC_MMIO_SNSC_OCTHERM_PRESENTBIT>());
    io_scratch_buffer.writeBit < START_POS + VALIDBIT_OFFSET >
    (i_snsc_thermal_data.getBit<scomt::ody::ODC_MMIO_SNSC_OCTHERM_VALIDBIT>());
    io_scratch_buffer.writeBit < START_POS + ERRORBIT_OFFSET >
    (i_snsc_thermal_data.getBit<scomt::ody::ODC_MMIO_SNSC_OCTHERM_ERRORBIT>());
    io_scratch_buffer.insertFromRight < START_POS + THERMALDATA_OFFSET, THERMALDATA_LEN > (l_thermal_data);
}

///
/// @brief Reads the octs, dts0, dts1 and writes to the scratch register
/// @param[in] i_target ocmb target on which to operate
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success
/// @note The proposed workaround is the following:
/// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
/// | REGISTER  |   |    OCTS      |         DTS0        |       DTS1         |           | SRQ_LFIR |
/// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
/// | 0x8011026 | 0 | 1 2 3  4:19  | 20 21 22 23  24:39  | 40 41 42 43 44:59  | 60 61 62  |     63   |
/// |           | 0 | P V E <temp> | 0  P  V  E   <temp> | 0  P  V  E  <temp> |  0  0  0  |   Event  |
/// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
///
fapi2::ReturnCode wr_data_to_scratch0(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target)
{
    static const uint64_t SCRATCH_REG0 = 0x8011026ull;
    fapi2::buffer<uint64_t> l_scratch_buffer = 0;
    fapi2::buffer<uint64_t> l_snsc_therm_data;

    using TT = mss::temp_sensor_traits<mss::mc_type::ODYSSEY>;

    // Get the OCTS register value
    FAPI_TRY(fapi2::getScom(i_target, scomt::ody::ODC_MMIO_SNSC_OCTHERM, l_snsc_therm_data));

    // Write the register data to the buffer
    wr_reg_data_to_scratch_helper<TT::scratch_reg_offset::SCRATCH_REG_BIT0_OFFSET>(l_snsc_therm_data, l_scratch_buffer);
    FAPI_INF_NO_SBE(" OCTS: 0x%016llx and scratch buffer after OCTS: 0x%016llx for target: " GENTARGTIDFORMAT,
                    l_snsc_therm_data, l_scratch_buffer, GENTARGTID(i_target) );

    // Get the DTS0 register value
    FAPI_TRY(fapi2::getScom(i_target, scomt::ody::ODC_MMIO_SNSC_D0THERM, l_snsc_therm_data));

    // Write the register data to the buffer
    wr_reg_data_to_scratch_helper<TT::scratch_reg_offset::SCRATCH_REG_BIT20_OFFSET>(l_snsc_therm_data, l_scratch_buffer);
    FAPI_INF_NO_SBE(" D0THERM: 0x%016llx and scratch buffer after d0therm: 0x%016llx for target: "  GENTARGTIDFORMAT,
                    l_snsc_therm_data, l_scratch_buffer, GENTARGTID(i_target) );

    // Get the DTS1 register value
    FAPI_TRY(fapi2::getScom(i_target, scomt::ody::ODC_MMIO_SNSC_D1THERM, l_snsc_therm_data));

    // Write the register data to the buffer
    wr_reg_data_to_scratch_helper<TT::scratch_reg_offset::SCRATCH_REG_BIT40_OFFSET>(l_snsc_therm_data, l_scratch_buffer);
    FAPI_INF_NO_SBE(" D1THERM: 0x%016llx and scratch buffer after d1therm: 0x%016llx for target: "  GENTARGTIDFORMAT,
                    l_snsc_therm_data, l_scratch_buffer, GENTARGTID(i_target) );

    // Get the LFIR_RW_WCLEAR register value
    FAPI_TRY(fapi2::getScom(i_target, scomt::ody::ODC_SRQ_LFIR_RW_WCLEAR, l_snsc_therm_data));

    // Write the register data to the buffer
    l_scratch_buffer.writeBit<mss::ody::scratch_fields::LFIR_IN08_BIT>
    (l_snsc_therm_data.getBit<scomt::ody::ODC_SRQ_LFIR_IN08>());
    FAPI_INF_NO_SBE(" ODC_SRQ_LFIR_RW_WCLEAR: 0x%016llx and scratch buffer after lfir_rw_clear : 0x%016llx for target: "
                    GENTARGTIDFORMAT,
                    l_snsc_therm_data, l_scratch_buffer, GENTARGTID(i_target) );

    // Write to the scratch register
    FAPI_TRY(fapi2::putScom(i_target, SCRATCH_REG0, l_scratch_buffer));

fapi_try_exit:
    return fapi2::current_err;

}

///
/// @brief Reads the dts2, dts3, srq_pmu2q and writes to the scratch buffer
/// @param[in] i_target ocmb target on which to operate
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success
/// @note The proposed workaround is the following:
/// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
/// | REGISTER  |      DTS2      |         DTS3        |         SR Cycle Count           |
/// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
/// | 0x8011027 | 0 1 2 3  4:19  | 20 21 22 23  24:39  |             40:63                |
/// |           | 0 P V E <temp> | 0  P  V  E   <temp> |       (side 0 + side 1)          |
/// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
///
fapi2::ReturnCode wr_data_to_scratch1(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target)
{
    static const uint64_t SCRATCH_REG1 = 0x8011027ull;
    fapi2::buffer<uint64_t> l_scratch_buffer;
    fapi2::buffer<uint64_t> l_snsc_therm_data;
    uint32_t l_data_from_scom_reg = 0;

    using TT = mss::temp_sensor_traits<mss::mc_type::ODYSSEY>;

    // Overflow data for 24 bit data
    const uint64_t OVERFLOW_DATA = 0xFFC00000;

    // Get the DTS2 register value
    FAPI_TRY(fapi2::getScom(i_target, scomt::ody::ODC_MMIO_SNSC_D2THERM, l_snsc_therm_data));

    // Write the register data to the buffer
    wr_reg_data_to_scratch_helper<TT::scratch_reg_offset::SCRATCH_REG_BIT0_OFFSET>(l_snsc_therm_data, l_scratch_buffer);
    FAPI_INF_NO_SBE(" scratch buffer after DTS2: 0x%016llx for target: " GENTARGTIDFORMAT, l_scratch_buffer,
                    GENTARGTID(i_target) );

    // Get the DTS3 register value
    FAPI_TRY(fapi2::getScom(i_target, scomt::ody::ODC_MMIO_SNSC_D3THERM, l_snsc_therm_data));

    // Write the register data to the buffer
    wr_reg_data_to_scratch_helper<TT::scratch_reg_offset::SCRATCH_REG_BIT20_OFFSET>(l_snsc_therm_data, l_scratch_buffer);
    FAPI_INF_NO_SBE(" scratch buffer after DTS3: 0x%016llx for target: " GENTARGTIDFORMAT, l_scratch_buffer,
                    GENTARGTID(i_target) );

    // Get the SR Cycle Count register value
    FAPI_TRY(fapi2::getScom(i_target, scomt::ody::ODC_SRQ_PMU2Q, l_snsc_therm_data));

    // The PMU registers are configured to monitor and sum the read/write/SR counts from side 0 and side 1.
    // The result will be stored in 0:31 of the 3 PMU registers. The granularity of the PMU monitor is that it counts every 4
    // events so in order to provide an accurate count to the OCC we have to multiply whatever is in 0:31 by 4 before we copy it into the
    // 0x8011027 reg, if there's an overflow when you do the multiply, the end value is set to max
    l_snsc_therm_data.extractToRight<scomt::ody::ODC_SRQ_PMU2Q_EVENT0_COUNTER, 32>(l_data_from_scom_reg);
    l_data_from_scom_reg = l_data_from_scom_reg >= OVERFLOW_DATA ? 0xffffffff : l_data_from_scom_reg << 2;

    // Write the register data to the buffer
    l_scratch_buffer.insertFromRight<mss::ody::scratch_fields::SR_CYCLE_COUNT_START, mss::ody::scratch_fields::SR_CYCLE_COUNT_LEN>
    (l_data_from_scom_reg);
    l_data_from_scom_reg = 0;

    FAPI_INF_NO_SBE(" scratch buffer after ODC_SRQ_PMU2Q: 0x%016llx for target: " GENTARGTIDFORMAT, l_scratch_buffer,
                    GENTARGTID(i_target) );

    // Write to the scratch register
    FAPI_TRY(fapi2::putScom(i_target, SCRATCH_REG1, l_scratch_buffer));


fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Reads the srq_pmu0q and srq_pmu1q and writes to the scratch buffer
/// @param[in] i_target ocmb target on which to operate
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success
/// @note The proposed workaround is the following:
/// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
/// | REGISTER  |             Reads               |                Writes                 |
/// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
/// | 0x8011028 |          (0:31)                 |                (0:31)                 |
/// |           |    (side 0 + side 1)            |          (side 0 + side 1)            |
/// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
///
fapi2::ReturnCode wr_data_to_scratch2(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target)
{
    static const uint64_t SCRATCH_REG2 = 0x8011028ull;
    fapi2::buffer<uint64_t> l_scratch_buffer;
    fapi2::buffer<uint64_t> l_snsc_therm_data;
    uint32_t l_data_from_scom_reg = 0;

    // Overflow data for 32 bit data
    const uint32_t OVERFLOW_DATA = 0xC0000000;

    // Get the ODC_SRQ_PMU0Q data
    FAPI_TRY(fapi2::getScom(i_target, scomt::ody::ODC_SRQ_PMU0Q, l_snsc_therm_data));

    l_snsc_therm_data.extractToRight<scomt::ody::ODC_SRQ_PMU0Q_EVENT0_COUNTER, mss::ody::scratch_fields::PMU0_READ_COUNT_LEN>
    (l_data_from_scom_reg);
    // The PMU registers are configured to monitor and sum the read/write/SR counts from side 0 and side 1.
    // The result will be stored in 0:31 of the 3 PMU registers. The granularity of the PMU monitor is that it counts every 4
    // events so in order to provide an accurate count to the OCC we have to multiply whatever is in 0:31 by 4 before we copy it into the
    // 0x8011028 reg, if there's an overflow when you do the multiply, the end value is set to max
    l_data_from_scom_reg = l_data_from_scom_reg >= OVERFLOW_DATA ? 0xffffffff : l_data_from_scom_reg << 2;
    l_scratch_buffer.insertFromRight<mss::ody::scratch_fields::PMU0_READ_COUNT_START, mss::ody::scratch_fields::PMU0_READ_COUNT_LEN>
    (l_data_from_scom_reg);
    l_data_from_scom_reg = 0;

    FAPI_INF_NO_SBE(" scratch buffer after ODC_SRQ_PMU0Q: 0x%016llx for target: " GENTARGTIDFORMAT, l_scratch_buffer,
                    GENTARGTID(i_target) );

    FAPI_TRY(fapi2::getScom(i_target, scomt::ody::ODC_SRQ_PMU1Q, l_snsc_therm_data));
    l_snsc_therm_data.extractToRight<scomt::ody::ODC_SRQ_PMU1Q_EVENT0_COUNTER, mss::ody::scratch_fields::PMU1_WRITE_COUNT_LEN>
    (l_data_from_scom_reg);
    // The PMU registers are configured to monitor and sum the read/write/SR counts from side 0 and side 1.
    // The result will be stored in 0:31 of the 3 PMU registers. The granularity of the PMU monitor is that it counts every 4
    // events so in order to provide an accurate count to the OCC we have to multiply whatever is in 0:31 by 4 before we copy it into the
    // 0x8011028 reg, if there's an overflow when you do the multiply, the end value is set to max
    l_data_from_scom_reg = l_data_from_scom_reg >= OVERFLOW_DATA ? 0xffffffff : l_data_from_scom_reg << 2;
    l_scratch_buffer.insertFromRight<mss::ody::scratch_fields::PMU1_WRITE_COUNT_START, mss::ody::scratch_fields::PMU1_WRITE_COUNT_LEN>
    (l_data_from_scom_reg);
    l_data_from_scom_reg = 0;

    FAPI_INF_NO_SBE(" scratch buffer after ODC_SRQ_PMU1Q: 0x%016llx for target: " GENTARGTIDFORMAT, l_scratch_buffer,
                    GENTARGTID(i_target) );

    // Write to the scratch register
    FAPI_TRY(fapi2::putScom(i_target, SCRATCH_REG2, l_scratch_buffer));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Reset the PMU counters used in the workaround
/// @param[in] i_target ocmb target on which to operate
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success
///
fapi2::ReturnCode reset_pmu_counts(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target)
{
    fapi2::buffer<uint64_t> l_pmu_cfg;

    // To reset the counts, we first stop the PMU then hit the start/reset bit
    FAPI_TRY(fapi2::getScom(i_target, scomt::ody::ODC_SRQ_PMUCFGQ, l_pmu_cfg));

    // To stop it we do START_RESET=0, STOP=1
    l_pmu_cfg.clearBit<scomt::ody::ODC_SRQ_PMUCFGQ_CFG_PMU_START_RESET>()
    .setBit<scomt::ody::ODC_SRQ_PMUCFGQ_CFG_PMU_STOP>();
    FAPI_TRY(fapi2::putScom(i_target, scomt::ody::ODC_SRQ_PMUCFGQ, l_pmu_cfg));

    // To reset and start it we do START_RESET=1, STOP=0
    l_pmu_cfg.setBit<scomt::ody::ODC_SRQ_PMUCFGQ_CFG_PMU_START_RESET>()
    .clearBit<scomt::ody::ODC_SRQ_PMUCFGQ_CFG_PMU_STOP>();
    FAPI_TRY(fapi2::putScom(i_target, scomt::ody::ODC_SRQ_PMUCFGQ, l_pmu_cfg));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Start the PMU counters used in the workaround
/// @param[in] i_target ocmb target on which to operate
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success
///
fapi2::ReturnCode start_pmu_counts(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target)
{
    fapi2::buffer<uint64_t> l_pmu_cfg;

    // To reset and start the PMU we do START_RESET=1, STOP=0
    FAPI_TRY(fapi2::getScom(i_target, scomt::ody::ODC_SRQ_PMUCFGQ, l_pmu_cfg));
    l_pmu_cfg.setBit<scomt::ody::ODC_SRQ_PMUCFGQ_CFG_PMU_START_RESET>()
    .clearBit<scomt::ody::ODC_SRQ_PMUCFGQ_CFG_PMU_STOP>();
    FAPI_TRY(fapi2::putScom(i_target, scomt::ody::ODC_SRQ_PMUCFGQ, l_pmu_cfg));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Reads the sensor cache regs and repackaged into scratch registers, then reset counts
/// @param[in] i_target ocmb target on which to operate
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success
///
fapi2::ReturnCode write_sensor_cache_into_scratch_regs(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target)
{
    FAPI_TRY(wr_data_to_scratch0(i_target));
    FAPI_TRY(wr_data_to_scratch1(i_target));
    FAPI_TRY(wr_data_to_scratch2(i_target));
    FAPI_TRY(reset_pmu_counts(i_target));

fapi_try_exit:
    return fapi2::current_err;
}



} // workarounds
} // ody
} // mss
