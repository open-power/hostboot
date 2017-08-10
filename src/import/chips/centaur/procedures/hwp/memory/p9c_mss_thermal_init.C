/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/centaur/procedures/hwp/memory/p9c_mss_thermal_init.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017                             */
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
/// @file p9c_mss_thermal_init.C
/// @brief Configure and start the OCC cache and Centaur thermal cache
///
/// *HWP HWP Owner: Luke Mulkey <lwmulkey@us.ibm.com>
/// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
/// *HWP Team: Memory
/// *HWP Level: 2
/// *HWP Consumed by: HB

//----------------------------------------------------------------------
//  Includes
//----------------------------------------------------------------------
#include <p9c_mss_thermal_init.H>
#include <fapi2.H>
#include <p9c_mss_unmask_errors.H>
#include <cen_gen_scom_addresses.H>
#include <dimmConsts.H>
#include <generic/memory/lib/utils/c_str.H>
extern "C" {
    ///
    ///@brief mss_thermal_init procedure. Configure and start the OCC cache and Centaur thermal cache
    ///@param[in]  i_target  Reference to centaur target
    ///@return ReturnCode
    ///
    fapi2::ReturnCode p9c_mss_thermal_init(const fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP>& i_target)
    {
        FAPI_INF("*** Running mss_thermal_init ***");

        constexpr uint32_t I2C_SETUP_UPPER_HALF = 0xD2314049;
        constexpr uint32_t I2C_SETUP_LOWER_HALF = 0x05000000;
        constexpr uint32_t ACT_MASK_UPPER_HALF = 0x00018000;
        constexpr uint32_t ACT_MASK_LOWER_HALF = 0x00000000;
        // OCC polls cacheline every 2 ms (could vary from this, as seen on scope)
        // For I2C bus at 50kHz (9.6 ms max to read 8 sensors), use interval of 15 for margin and to prevent stall errors when 8 sensors are enabled to be read
        constexpr uint32_t CONFIG_INTERVAL_TIMER = 15;
        constexpr uint32_t CONFIG_STALL_TIMER = 128;
        constexpr uint8_t I2C_BUS_ENCODE_PRIMARY = 0;
        constexpr uint8_t I2C_BUS_ENCODE_SECONDARY = 8;
        constexpr uint8_t MAX_NUM_DIMM_SENSORS = 8;
        constexpr uint8_t MAX_I2C_BUSSES = 2;

        // Variable declaration
        uint8_t l_dimm_ranks_array[MAX_MBA_PER_CEN][MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT] = {0};    // Number of ranks for each configured DIMM in each MBA
        uint8_t l_custom_dimm[MAX_MBA_PER_CEN] = {0};               // Custom DIMM
        uint8_t l_mba_pos = 0;                        // Current MBA for populating rank array
        fapi2::buffer<uint64_t> l_data;
        fapi2::buffer<uint64_t> l_data_scac_enable;
        fapi2::buffer<uint64_t> l_data_scac_addrmap;
        uint8_t l_cdimm_sensor_map = 0;
        uint8_t l_cdimm_sensor_map_primary = 0;
        uint8_t l_cdimm_sensor_map_secondary = 0;
        uint8_t l_cdimm_number_dimm_temp_sensors = 0;
        uint8_t l_i2c_address_map = 0;
        uint8_t l_data_scac_addrmap_offset = 0;
        uint8_t l_i2c_bus_encode = 0;
        uint8_t l_sensor_map_mask = 0;
        uint8_t l_master_i2c_temp_sensor_enable = 0;
        uint8_t l_spare_i2c_temp_sensor_enable = 0;
        uint32_t l_dimm_sensor_cache_addr_map = 0;
        fapi2::buffer<uint64_t> l_reset;
        uint8_t l_enable_safemode_throttle = 0;
        // Get input attributes from MBAs
        const auto l_target_mba_array = i_target.getChildren<fapi2::TARGET_TYPE_MBA>();

        //********************************************
        // Centaur internal temperature polling setup
        //********************************************
        // setup hang pulse
        FAPI_TRY(fapi2::getScom(i_target, CEN_PCBSLNEST_HANG_PULSE_0_REG_PCB, l_data));
        l_data.setBit<1>().setBit<2>();
        FAPI_TRY(fapi2::putScom(i_target, CEN_PCBSLNEST_HANG_PULSE_0_REG_PCB, l_data));
        FAPI_TRY(fapi2::getScom(i_target, CEN_TCN_THERM_MODE_REG_PCB, l_data));
        // setup DTS enables  NOTE: Does this need to be scom'd before enable dts sampling? LM
        l_data.setBit<20>().setBit<21>();
        // setup pulse count and enable DTS sampling
        l_data.setBit<5>().setBit<6>().setBit<7>().setBit<8>().setBit<9>();
        FAPI_TRY(fapi2::putScom(i_target, CEN_TCN_THERM_MODE_REG_PCB, l_data));
        // issue a reset
        l_data.flush<0>().setBit<0>().setBit<1>().setBit<2>().setBit<3>().setBit<4>();
        FAPI_TRY(fapi2::putScom(i_target, CEN_TCN_CONTROL_REG_PCB, l_data));
        // Centaur internal temperature polling setup complete

        for (const auto& mba : l_target_mba_array)
        {
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, mba, l_mba_pos), "Failed to get attr ATTR_CHIP_UNIT_POS on %s",
                     mss::c_str(mba));
            FAPI_INF("MBA_POS: %d", l_mba_pos);

            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_NUM_RANKS_PER_DIMM, mba, l_dimm_ranks_array[l_mba_pos]),
                     "Failed to get attr ATTR_CEN_EFF_NUM_RANKS_PER_DIMM on %s", mss::c_str(mba));
            FAPI_INF("EFF_NUM_RANKS: %d:%d:%d:%d", l_dimm_ranks_array[l_mba_pos][0][0], l_dimm_ranks_array[l_mba_pos][0][1],
                     l_dimm_ranks_array[l_mba_pos][1][0], l_dimm_ranks_array[l_mba_pos][1][1]);

            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_CUSTOM_DIMM, mba,  l_custom_dimm[l_mba_pos]),
                     "Failed to get attr ATTR_CEN_EFF_CUSTOM_DIMM on %s", mss::c_str(mba));
            FAPI_INF("ATTR_EFF_CUSTOM_DIMM: %d", l_custom_dimm[l_mba_pos]);
        }

        // Get attributes for dimm temperature sensor mapping for only a custom dimm so we don't get an error
        // Get attritute for custom dimms for enablement on the master i2c bus
        if ((l_custom_dimm[0] == fapi2::ENUM_ATTR_CEN_EFF_CUSTOM_DIMM_YES)
            || (l_custom_dimm[1] == fapi2::ENUM_ATTR_CEN_EFF_CUSTOM_DIMM_YES))
        {
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_VPD_CDIMM_SENSOR_MAP_PRIMARY, i_target,  l_cdimm_sensor_map_primary),
                     "Failed to get attr ATTR_CEN_VPD_CDIMM_SENSOR_MAP_PRIMARY on %s", mss::c_str(i_target));
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_VPD_CDIMM_SENSOR_MAP_SECONDARY, i_target,  l_cdimm_sensor_map_secondary),
                     "Failed to get attr ATTR_CEN_VPD_CDIMM_SENSOR_MAP_SECONDARY on %s", mss::c_str(i_target));
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_MRW_CDIMM_MASTER_I2C_TEMP_SENSOR_ENABLE,
                                   fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(), l_master_i2c_temp_sensor_enable),
                     "Failed to get attr ATTR_CEN_MRW_CDIMM_MASTER_I2C_TEMP_SENSOR_ENABLE on %s", mss::c_str(i_target));
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_MRW_CDIMM_SPARE_I2C_TEMP_SENSOR_ENABLE,
                                   fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(), l_spare_i2c_temp_sensor_enable),
                     "Failed to get attr ATTR_CEN_MRW_CDIMM_SPARE_I2C_TEMP_SENSOR_ENABLE on %s", mss::c_str(i_target));
        }
        else
        {
            // sensor cache address map for non custom dimm temperature sensors (which i2c bus and i2c address they are)
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_MRW_MEM_SENSOR_CACHE_ADDR_MAP, i_target,  l_dimm_sensor_cache_addr_map),
                     "Failed to get attr ATTR_CEN_MRW_MEM_SENSOR_CACHE_ADDR_MAP on %s", mss::c_str(i_target));
        }

        // Configure Centaur Thermal Cache

        // ---------------------------------
        // Clear the master enable bit
        // ---------------------------------

        FAPI_TRY(fapi2::getScom(i_target, CEN_SCAC_CONFIG, l_data));
        l_data.clearBit<0>(); //Master enable is bit 0
        FAPI_TRY(fapi2::putScom(i_target, CEN_SCAC_CONFIG, l_data));

        // ---------------------------------
        // Mask FIR bit 33
        // Sets if any sensor cache addresses are written while the master enable is set
        // ---------------------------------

        FAPI_TRY(fapi2::getScom(i_target, CEN_SCAC_FIRMASK, l_data));
        l_data.setBit<33>();
        FAPI_TRY(fapi2::putScom(i_target, CEN_SCAC_FIRMASK, l_data));

        // ---------------------------------
        // Program PibTarget<fapi2::TARGET_TYPE_MBA> Register
        // ---------------------------------

        FAPI_TRY(fapi2::getScom(i_target, CEN_SCAC_PIBTARGET, l_data));
        l_data.insert<0, 32, 0>(CEN_I2CM_CONTROL_REGISTER_0_WOX);
        l_data.insert<32, 32, 0>(CEN_I2CM_CONTROL_REGISTER_0_WOX);
        FAPI_TRY(fapi2::putScom(i_target, CEN_SCAC_PIBTARGET, l_data));

        // ---------------------------------
        // Program I2CMCtrl Register
        // ---------------------------------

        FAPI_TRY(fapi2::getScom(i_target, CEN_SCAC_I2CMCTRL_SCAC_I2CMCTRL, l_data));
        l_data.insert<0, 32, 0>(I2C_SETUP_UPPER_HALF);
        l_data.insert<32, 32, 0>(I2C_SETUP_LOWER_HALF);
        FAPI_TRY(fapi2::putScom(i_target, CEN_SCAC_I2CMCTRL_SCAC_I2CMCTRL, l_data));


        // ---------------------------------
        // Program Action Mask Register
        // ---------------------------------

        FAPI_TRY(fapi2::getScom(i_target, CEN_SCAC_ACTIONMASK, l_data));
        l_data.insert<0, 32, 0>(ACT_MASK_UPPER_HALF);
        l_data.insert<32, 32, 0>(ACT_MASK_LOWER_HALF);
        FAPI_TRY(fapi2::putScom(i_target, CEN_SCAC_ACTIONMASK, l_data));


        // ---------------------------------
        // Program SensorCacheConfiguration Register
        // ---------------------------------

        FAPI_TRY(fapi2::getScom(i_target, CEN_SCAC_CONFIG, l_data));
        l_data.setBit<1>();   //Sync to OCC_Read signal
        l_data.insert < 11, 5, 32 - 5 > (CONFIG_INTERVAL_TIMER);
        l_data.insert < 16, 8, 32 - 8 > (CONFIG_STALL_TIMER);
        FAPI_TRY(fapi2::putScom(i_target, CEN_SCAC_CONFIG, l_data));

        // --------------------------------------------------------
        // Program SensorCacheEnable and SensorAddressMap Registers
        // --------------------------------------------------------

        FAPI_TRY(fapi2::getScom(i_target, CEN_SCAC_ENABLE, l_data_scac_enable));

        FAPI_TRY(fapi2::getScom(i_target, CEN_SCAC_ADDRMAP, l_data_scac_addrmap));

        if ((l_custom_dimm[0] == fapi2::ENUM_ATTR_CEN_EFF_CUSTOM_DIMM_YES)
            || (l_custom_dimm[1] == fapi2::ENUM_ATTR_CEN_EFF_CUSTOM_DIMM_YES))
        {

            l_cdimm_number_dimm_temp_sensors = 0;

            // cycle through both primary and secondary i2c busses, determine i2c address and enable bits
            for (uint8_t l_i2c_bus = 0; l_i2c_bus < MAX_I2C_BUSSES; l_i2c_bus++)
            {
                for (uint8_t l_dimm_sensor = 0; l_dimm_sensor < MAX_NUM_DIMM_SENSORS; l_dimm_sensor++)
                {
                    if (l_i2c_bus == 0)
                    {
                        l_i2c_bus_encode = I2C_BUS_ENCODE_PRIMARY;
                        l_cdimm_sensor_map = l_cdimm_sensor_map_primary;
                    }
                    else
                    {
                        l_i2c_bus_encode = I2C_BUS_ENCODE_SECONDARY;
                        l_cdimm_sensor_map = l_cdimm_sensor_map_secondary;
                    }

                    switch (l_dimm_sensor)
                    {
                        case 0:
                            l_sensor_map_mask = 0x01;
                            break;

                        case 1:
                            l_sensor_map_mask = 0x02;
                            break;

                        case 2:
                            l_sensor_map_mask = 0x04;
                            break;

                        case 3:
                            l_sensor_map_mask = 0x08;
                            break;

                        case 4:
                            l_sensor_map_mask = 0x10;
                            break;

                        case 5:
                            l_sensor_map_mask = 0x20;
                            break;

                        case 6:
                            l_sensor_map_mask = 0x40;
                            break;

                        case 7:
                            l_sensor_map_mask = 0x80;
                            break;

                        default:
                            l_sensor_map_mask = 0x00;
                    }

                    if ((l_cdimm_sensor_map & l_sensor_map_mask) != 0)
                    {
                        if(
                            (
                                (l_i2c_bus == 0)
                                &&
                                (l_master_i2c_temp_sensor_enable ==
                                 fapi2::ENUM_ATTR_CEN_MRW_CDIMM_MASTER_I2C_TEMP_SENSOR_ENABLE_ON)
                            )
                            ||
                            (
                                (l_i2c_bus == 1)
                                &&
                                (l_spare_i2c_temp_sensor_enable ==
                                 fapi2::ENUM_ATTR_CEN_MRW_CDIMM_SPARE_I2C_TEMP_SENSOR_ENABLE_ON)
                            )
                        )

                        {
                            FAPI_TRY(l_data_scac_enable.setBit(l_cdimm_number_dimm_temp_sensors));
                        }

                        l_i2c_address_map = l_dimm_sensor + l_i2c_bus_encode;
                        l_data_scac_addrmap_offset = l_cdimm_number_dimm_temp_sensors * 4;
                        FAPI_TRY(l_data_scac_addrmap.insert(l_i2c_address_map, l_data_scac_addrmap_offset , 4, 4));
                        l_cdimm_number_dimm_temp_sensors++;
                        FAPI_ASSERT(l_cdimm_number_dimm_temp_sensors <= MAX_NUM_DIMM_SENSORS,
                                    fapi2::CEN_MSS_CDIMM_INVALID_NUMBER_SENSORS().
                                    set_MEM_CHIP(i_target).
                                    set_FFDC_DATA_1(l_cdimm_sensor_map_primary).
                                    set_FFDC_DATA_2(l_cdimm_sensor_map_secondary),
                                    "Invalid number of dimm temperature sensors specified in the CDIMM VPD MW keyword");

                    } // end if sensor map and mask != 0
                } // end for sensor
            } //end for i2c bus
        } //end if custom dimm
        else
        {
            // Iterate through the num_ranks array to determine what DIMMs are plugged
            // Enable sensor monitoring for each plugged DIMM
            uint32_t l_iterator = 0;

            for (uint32_t l_mba_index = 0; l_mba_index < MAX_MBA_PER_CEN; l_mba_index++)
            {
                if (l_dimm_ranks_array[l_mba_index][0][0] != 0)
                {
                    FAPI_TRY(l_data_scac_enable.setBit(l_iterator));
                }

                l_iterator++;

                if (l_dimm_ranks_array[l_mba_index][0][1] != 0)
                {
                    FAPI_TRY(l_data_scac_enable.setBit(l_iterator));
                }

                l_iterator++;

                if (l_dimm_ranks_array[l_mba_index][1][0] != 0)
                {
                    FAPI_TRY(l_data_scac_enable.setBit(l_iterator));
                }

                l_iterator++;

                if (l_dimm_ranks_array[l_mba_index][1][1] != 0)
                {
                    FAPI_TRY(l_data_scac_enable.setBit(l_iterator));
                }

                l_iterator++;
            }

            l_data_scac_addrmap.insert<0, 32, 0>(l_dimm_sensor_cache_addr_map);

        } //end not custom dimm

        FAPI_TRY(fapi2::putScom(i_target, CEN_SCAC_ENABLE, l_data_scac_enable));

        FAPI_TRY(fapi2::putScom(i_target, CEN_SCAC_ADDRMAP, l_data_scac_addrmap));

        //---------------------------------
        // Reset the I2CM
        //---------------------------------

        l_reset.setBit<0>();
        FAPI_TRY(fapi2::putScom(i_target, CEN_I2CM_RESET_REGISTER_0_WOX, l_reset));

        // ---------------------------------
        // Set the master enable bit
        // ---------------------------------

        FAPI_TRY(fapi2::getScom(i_target, CEN_SCAC_CONFIG, l_data));
        l_data.setBit<0>();
        FAPI_TRY(fapi2::putScom(i_target, CEN_SCAC_CONFIG, l_data));

        // Configure Centaur Thermal Cache COMPLETED

        // Disable Emergency Throttles

        // ---------------------------------
        // Clear the emergency throttle FIR bit (MBS FIR 21)
        // ---------------------------------

        FAPI_TRY(fapi2::getScom(i_target, CEN_MBS_FIR_REG, l_data));
        l_data.clearBit<21>();
        FAPI_TRY(fapi2::putScom(i_target, CEN_MBS_FIR_REG, l_data));


        // ---------------------------------
        // Reset emergency throttle in progress bit (EMER THROT 0)
        // ---------------------------------

        FAPI_TRY(fapi2::getScom(i_target, CEN_MBSEMERTHROQ, l_data));
        l_data.clearBit<0>();
        FAPI_TRY(fapi2::putScom(i_target, CEN_MBSEMERTHROQ, l_data));

        // Disable Emergency Throttles COMPLETED


        // Write the IPL Safe Mode Throttles
        // For centaur DD2 and above since OCC only writes runtime throttles for this

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_CENTAUR_EC_FEATURE_ENABLE_SAFEMODE_THROTTLE,
                               i_target,
                               l_enable_safemode_throttle));

        if (l_enable_safemode_throttle)
        {
            uint32_t l_safemode_throttle_n_per_mba;
            uint32_t l_safemode_throttle_n_per_chip;
            uint32_t l_throttle_d;

            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_MRW_SAFEMODE_MEM_THROTTLE_NUMERATOR_PER_MBA,
                                   fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(),
                                   l_safemode_throttle_n_per_mba));

            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_MRW_SAFEMODE_MEM_THROTTLE_NUMERATOR_PER_CHIP,
                                   fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(),
                                   l_safemode_throttle_n_per_chip));

            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_MRW_MEM_THROTTLE_DENOMINATOR,
                                   fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(),
                                   l_throttle_d));

            // write the N/M throttle control register
            for (const auto& mba : l_target_mba_array)
            {
                FAPI_TRY(fapi2::getScom(mba, CEN_MBA_MBA_FARB3Q, l_data));
                l_data.insertFromRight<0, 15>(l_safemode_throttle_n_per_mba);
                l_data.insertFromRight<15, 16>(l_safemode_throttle_n_per_chip);
                l_data.insertFromRight<31, 14>(l_throttle_d);
                FAPI_TRY(fapi2::putScom(mba, CEN_MBA_MBA_FARB3Q, l_data));
            }
        }

        // If mss_unmask_fetch_errors gets it's own bad rc,
        // it will commit the passed in rc (if non-zero), and return it's own bad rc.
        // Else if mss_unmask_fetch_errors runs clean,
        // it will just return the passed in rc.
        FAPI_TRY(mss_unmask_fetch_errors(i_target));

        FAPI_INF("*** mss_thermal_init COMPLETE ***");
    fapi_try_exit:
        return fapi2::current_err;

    } //end mss_thermal_init

} //end extern C

