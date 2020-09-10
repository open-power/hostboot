/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/centaur/procedures/hwp/memory/p9c_mss_volt.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2021                        */
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
/// @file p9c_mss_volt.C
/// @brief Reads in supported DIMM voltages from SPD and determines optimal voltage bin for the DIMM voltage domain.
///
/// *HWP HWP Owner: Luke Mulkey <lwmulkey@us.ibm.com>
/// *HWP HWP Backup: Andre Marin <aamaring@us.ibm.com>
/// *HWP Team: Memory
/// *HWP Level: 2
/// *HWP Consumed by: HB


// supported voltage bins:  DDR3: 1.35   DDR4: 1.25V (expected)

//----------------------------------------------------------------------
//  Includes - FAPI
//----------------------------------------------------------------------
#include <fapi2.H>
#include <p9c_mss_volt.H>

//----------------------------------------------------------------------
//  Constants
//----------------------------------------------------------------------
constexpr uint32_t MAX_TOLERATED_VOLT = 1500;
constexpr uint32_t MAX_TOLERATED_DDR3_VOLT = 1500;
constexpr uint32_t MAX_TOLERATED_DDR4_VOLT = 1200;
constexpr uint32_t DDR3_VPP_VOLT = 0000;
constexpr uint32_t DDR4_VPP_VOLT = 2500;


///
/// @brief Reads in supported DIMM voltages from SPD and determines optimal voltage bin for the DIMM voltage domain.
/// @param[in] i_targets_memb -  vector of centaur targets
/// @return FAPI2_RC_SUCCESS iff voltage domain found
///
fapi2::ReturnCode p9c_mss_volt(const std::vector<fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP>>& i_targets_memb)
{
    uint8_t l_dimm_functionality = 0;
    uint8_t l_spd_dramtype = 0;
    uint8_t l_spd_volts = 0;
    uint8_t l_spd_volts_all_dimms = 0xFF; //start assuming all voltages supported
    uint8_t l_dram_ddr3_found_flag = 0;
    uint8_t l_dram_ddr4_found_flag = 0;
    uint8_t l_volt_override = 0x00;
    uint8_t l_volt_override_domain = 0x00;

    uint32_t l_selected_dram_voltage = 0; //this gets written into all centaurs when done.
    uint32_t l_selected_dram_voltage_vpp = 0;
    uint32_t l_tolerated_dram_voltage = MAX_TOLERATED_VOLT; //initially set to the max tolerated voltage
    uint8_t l_dimm_count = 0;
    uint8_t l_compliant_dimm_voltages = 0;

    //Gather whether 1.5V only DIMMs supported
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_MSS_VOLT_COMPLIANT_DIMMS, fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(),
                           l_compliant_dimm_voltages));

    // Iterate through the list of centaurs
    for (const auto& l_cen : i_targets_memb)
    {
        // Get associated MBA's on this centaur
        const auto l_mbaChiplets = l_cen.getChildren<fapi2::TARGET_TYPE_MBA>();

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_MSS_VOLT_OVERRIDE, l_cen, l_volt_override));

        // Note if there is an overrride being applied on the domain
        if ( (l_volt_override != fapi2::ENUM_ATTR_CEN_MSS_VOLT_OVERRIDE_NONE)
             && (l_volt_override_domain == fapi2::ENUM_ATTR_CEN_MSS_VOLT_OVERRIDE_NONE) )
        {
            l_volt_override_domain = l_volt_override;
        }

        // Error if our overides are not the same across the domain
        FAPI_ASSERT(l_volt_override_domain == l_volt_override,
                    fapi2::CEN_MSS_VOLT_OVERIDE_MIXING().
                    set_OVERRIDE_TYPE(l_volt_override).
                    set_OVERRIDE_DOMAIN_TYPE(l_volt_override_domain).
                    set_MEMB_TARGET(l_cen),
                    "Mismatch volt override request.  Domain: 0x%x  Current Target<fapi2::TARGET_TYPE_MBA> Requests: 0x%x",
                    l_volt_override_domain, l_volt_override);

        // Loop through the 2 MBA's
        for (const auto& l_mba : l_mbaChiplets)
        {
            // Get a vector of DIMM targets
            const auto l_dimm_targets = l_mba.getChildren<fapi2::TARGET_TYPE_DIMM>();

            for (const auto& l_dimm : l_dimm_targets)
            {
                FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_SPD_DRAM_DEVICE_TYPE, l_dimm, l_spd_dramtype));
                FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_SPD_MODULE_NOMINAL_VOLTAGE, l_dimm, l_spd_volts));
                FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_FUNCTIONAL, l_dimm, l_dimm_functionality));

                // spd_volts:  bit0= NOT 1.5V bit1=1.35V bit2=1.25V, assume a 1.20V in future for DDR4
                // check for supported voltage/dram type combo  DDR3=12, DDR4=13
                if (l_spd_dramtype == fapi2::ENUM_ATTR_CEN_SPD_DRAM_DEVICE_TYPE_DDR3)
                {
                    l_dram_ddr3_found_flag = 1;
                }
                else if (l_spd_dramtype == fapi2::ENUM_ATTR_CEN_SPD_DRAM_DEVICE_TYPE_DDR4)
                {
                    l_dram_ddr4_found_flag = 1;
                }
                else
                {
                    FAPI_ASSERT(false,
                                fapi2::CEN_MSS_VOLT_UNRECOGNIZED_DRAM_DEVICE_TYPE().
                                set_DEVICE_TYPE(l_spd_dramtype).
                                set_DIMM_TARGET(l_dimm),
                                "Unknown DRAM Device Type 0x%x", l_spd_dramtype);
                }

                if(l_dimm_functionality == fapi2::ENUM_ATTR_FUNCTIONAL_FUNCTIONAL)
                {
                    //AND dimm voltage capabilities together to find aggregate voltage support on all dimms
                    l_spd_volts_all_dimms = l_spd_volts_all_dimms & l_spd_volts;
                }
            }//end of dimms loop
        }//end of mba loop
    }//end of centaur (memb) loop

    // now we figure out if we have a supported ddr type and voltage
    // note: only support DDR3=1.35V and DDR4=1.2xV

    // Mixed Dimms, Deconfig the DDR4.
    if (l_dram_ddr3_found_flag && l_dram_ddr4_found_flag)
    {
        // Iterate through the list of centaurs
        for (const auto& l_cen : i_targets_memb)
        {
            // Get associated MBA's on this centaur
            const auto l_mbaChiplets = l_cen.getChildren<fapi2::TARGET_TYPE_MBA>();

            // Loop through the 2 MBA's
            for (const auto& l_mba : l_mbaChiplets)
            {
                // Get a vector of DIMM targets
                const auto l_dimm_targets = l_mba.getChildren<fapi2::TARGET_TYPE_DIMM>();

                for (const auto& l_dimm : l_dimm_targets)
                {
                    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_SPD_DRAM_DEVICE_TYPE, l_dimm, l_spd_dramtype));

                    FAPI_ASSERT(l_spd_dramtype == fapi2::ENUM_ATTR_CEN_SPD_DRAM_DEVICE_TYPE_DDR4,
                                fapi2::CEN_MSS_VOLT_DDR_TYPE_MIXING_UNSUPPORTED().
                                set_DIMM_DDR4_TARGET(l_dimm).
                                set_DEVICE_TYPE(l_spd_dramtype),
                                "mss_volt: DDR3 and DDR4 mixing not allowed");
                }//end of dimms loop
            }//end of mba loop
        }//end of centaur (memb) loop
    }//end of if(ddr3 && ddr4)

    FAPI_INF( "Bitwise and of all DIMM_SPD: 0x%02x", l_spd_volts_all_dimms);

    // If we are going to land on using 1.5V and we are not enabling that usage via attribute.
    if ( ((l_spd_volts_all_dimms & fapi2::ENUM_ATTR_CEN_SPD_MODULE_NOMINAL_VOLTAGE_OP1_35) !=
          fapi2::ENUM_ATTR_CEN_SPD_MODULE_NOMINAL_VOLTAGE_OP1_35) &&
         ((l_spd_volts_all_dimms & fapi2::ENUM_ATTR_CEN_SPD_MODULE_NOMINAL_VOLTAGE_OP1_2V) !=
          fapi2::ENUM_ATTR_CEN_SPD_MODULE_NOMINAL_VOLTAGE_OP1_2V) &&
         ((l_spd_volts_all_dimms & fapi2::ENUM_ATTR_CEN_SPD_MODULE_NOMINAL_VOLTAGE_NOTOP1_5) !=
          fapi2::ENUM_ATTR_CEN_SPD_MODULE_NOMINAL_VOLTAGE_NOTOP1_5) &&
         (l_compliant_dimm_voltages == fapi2::ENUM_ATTR_CEN_MSS_VOLT_COMPLIANT_DIMMS_PROCEDURE_DEFINED) )
    {

        // Iterate through the list of centaurs
        for (const auto& l_cen : i_targets_memb)
        {
            // Get associated MBA's on this centaur
            const auto l_mbaChiplets = l_cen.getChildren<fapi2::TARGET_TYPE_MBA>();

            // Loop through the 2 MBA's
            for (const auto& l_mba : l_mbaChiplets)
            {
                // Get a vector of DIMM targets
                const auto l_dimm_targets = l_mba.getChildren<fapi2::TARGET_TYPE_DIMM>();

                for (const auto& l_dimm : l_dimm_targets)
                {
                    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_SPD_MODULE_NOMINAL_VOLTAGE, l_dimm, l_spd_volts));
                    FAPI_ASSERT((l_spd_volts & fapi2::ENUM_ATTR_CEN_SPD_MODULE_NOMINAL_VOLTAGE_NOTOP1_5) ==
                                fapi2::ENUM_ATTR_CEN_SPD_MODULE_NOMINAL_VOLTAGE_NOTOP1_5,
                                fapi2::CEN_MSS_VOLT_DDR_TYPE_COMPLIANT_VOLTAGE().
                                set_DIMM_CV_TARGET(l_dimm).
                                set_DIMM_VOLTAGE(l_spd_volts),
                                "One or more DIMMs operate 1.5V which is not supported.");
                }//end of dimms loop
            }//end of mba loop
        }//end of centaur (memb) loop
    }

    //Picking voltages based on overrides or supported voltages.
    if (l_volt_override != fapi2::ENUM_ATTR_CEN_MSS_VOLT_OVERRIDE_NONE)
    {
        if (l_volt_override == fapi2::ENUM_ATTR_CEN_MSS_VOLT_OVERRIDE_VOLT_135)
        {
            l_selected_dram_voltage = 1350;
            FAPI_INF( "mss_volt_overide being applied.  MSS_VOLT_OVERRIDE: 1.35V");
            FAPI_INF( "NOTE: Still checking for violations of tolerated voltage.  If DIMMs cannot tolerate, the override will not be applied.");
        }
        else if (l_volt_override == fapi2::ENUM_ATTR_CEN_MSS_VOLT_OVERRIDE_VOLT_120)
        {
            l_selected_dram_voltage = 1200;
            FAPI_INF( "mss_volt_overide being applied.  MSS_VOLT_OVERRIDE: 1.20V");
            FAPI_INF( "NOTE: Still checking for violations of tolerated voltage.  If DIMMs cannot tolerate, the override will not be applied.");
        }
        else
        {
            FAPI_ASSERT(false,
                        fapi2::CEN_MSS_VOLT_OVERRIDE_UNKNOWN().
                        set_OVERRIDE_TYPE(l_volt_override),
                        "Unknown volt override request.  Override Request: 0x%x", l_volt_override);
        }
    }
    else if (l_dram_ddr3_found_flag
             && ((l_spd_volts_all_dimms & fapi2::ENUM_ATTR_CEN_SPD_MODULE_NOMINAL_VOLTAGE_OP1_35) ==
                 fapi2::ENUM_ATTR_CEN_SPD_MODULE_NOMINAL_VOLTAGE_OP1_35))
    {
        l_selected_dram_voltage = 1350;
        l_selected_dram_voltage_vpp = DDR3_VPP_VOLT;
    }
    else if (l_dram_ddr4_found_flag
             && ((l_spd_volts_all_dimms & fapi2::ENUM_ATTR_CEN_SPD_MODULE_NOMINAL_VOLTAGE_OP1_2V) ==
                 fapi2::ENUM_ATTR_CEN_SPD_MODULE_NOMINAL_VOLTAGE_OP1_2V))
    {
        l_selected_dram_voltage = 1200;
        l_selected_dram_voltage_vpp = DDR4_VPP_VOLT;
    }
    else if  ( ((l_spd_volts_all_dimms & fapi2::ENUM_ATTR_CEN_SPD_MODULE_NOMINAL_VOLTAGE_NOTOP1_5) !=
                fapi2::ENUM_ATTR_CEN_SPD_MODULE_NOMINAL_VOLTAGE_NOTOP1_5) &&
               (l_compliant_dimm_voltages == fapi2::ENUM_ATTR_CEN_MSS_VOLT_COMPLIANT_DIMMS_ALL_VOLTAGES))
    {
        l_selected_dram_voltage = 1500;
        l_selected_dram_voltage_vpp = DDR3_VPP_VOLT;
    }
    else
    {
        // Iterate through the list of centaurs
        for (const auto& l_cen : i_targets_memb)
        {
            // Get associated MBA's on this centaur
            const auto l_mbaChiplets = l_cen.getChildren<fapi2::TARGET_TYPE_MBA>();

            // Loop through the 2 MBA's
            for (const auto& l_mba : l_mbaChiplets)
            {
                // Get a vector of DIMM targets
                const auto l_dimm_targets = l_mba.getChildren<fapi2::TARGET_TYPE_DIMM>();

                for (const auto& l_dimm : l_dimm_targets)
                {
                    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_SPD_MODULE_NOMINAL_VOLTAGE, l_dimm, l_spd_volts));
                    FAPI_ASSERT((l_spd_volts & fapi2::ENUM_ATTR_CEN_SPD_MODULE_NOMINAL_VOLTAGE_NOTOP1_5) !=
                                fapi2::ENUM_ATTR_CEN_SPD_MODULE_NOMINAL_VOLTAGE_NOTOP1_5,
                                fapi2::CEN_MSS_VOLT_DDR_TYPE_REQUIRED_VOLTAGE().
                                set_DIMM_UV_TARGET(l_dimm).
                                set_DIMM_VOLTAGE(l_spd_volts),
                                "One or more DIMMs do not support required voltage for DIMM type");
                }//end of dimms loop
            }//end of mba loop
        }//end of centaur (memb) loop
    }

    // Must check to see if we violate Tolerent voltages of Non-functional Dimms
    // If so we must error/deconfigure on the dimm level primarily then centaur level.
    // Iterate through the list of centaurs
    for (const auto& l_cen : i_targets_memb)
    {
        l_tolerated_dram_voltage = MAX_TOLERATED_VOLT; // using 1.5 as this is the largest supported voltage
        // Get associated MBA's on this centaur
        const auto l_mbaChiplets = l_cen.getChildren<fapi2::TARGET_TYPE_MBA>();

        for (const auto& l_mba : l_mbaChiplets)
        {
            // Get a vector of DIMM targets
            const auto l_dimm_targets = l_mba.getChildren<fapi2::TARGET_TYPE_DIMM>();

            for (const auto& l_dimm : l_dimm_targets)
            {
                FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_FUNCTIONAL, l_dimm, l_dimm_functionality));


                if(l_dimm_functionality == fapi2::ENUM_ATTR_FUNCTIONAL_NON_FUNCTIONAL)
                {
                    if (l_spd_dramtype == fapi2::ENUM_ATTR_CEN_SPD_DRAM_DEVICE_TYPE_DDR3)
                    {
                        if (l_tolerated_dram_voltage > MAX_TOLERATED_DDR3_VOLT)
                        {
                            l_tolerated_dram_voltage =  MAX_TOLERATED_DDR3_VOLT;
                        }

                        FAPI_ASSERT(MAX_TOLERATED_DDR3_VOLT > l_selected_dram_voltage,
                                    fapi2::CEN_MSS_VOLT_TOLERATED_VOLTAGE_VIOLATION().
                                    set_CHIP_TARGET(l_dimm).
                                    set_DIMM_VOLTAGE(l_selected_dram_voltage),
                                    "One or more DIMMs classified non-functional has a"
                                    " tolerated voltage below selected voltage.");
                    }

                    if (l_spd_dramtype == fapi2::ENUM_ATTR_CEN_SPD_DRAM_DEVICE_TYPE_DDR4)
                    {
                        if (l_tolerated_dram_voltage > MAX_TOLERATED_DDR4_VOLT)
                        {
                            l_tolerated_dram_voltage =  MAX_TOLERATED_DDR4_VOLT;
                        }

                        FAPI_ASSERT(MAX_TOLERATED_DDR4_VOLT > l_selected_dram_voltage,
                                    fapi2::CEN_MSS_VOLT_TOLERATED_VOLTAGE_VIOLATION().
                                    set_CHIP_TARGET(l_dimm).
                                    set_DIMM_VOLTAGE(l_selected_dram_voltage),
                                    "One or more DIMMs classified non-functional has a"
                                    " tolerated voltage below selected voltage.");
                    }

                }//End of functional check
            }//End of Dimm loop
        }// End of MBA loop

        FAPI_ASSERT(l_tolerated_dram_voltage > l_selected_dram_voltage,
                    fapi2::CEN_MSS_VOLT_TOLERATED_VOLTAGE_VIOLATION().
                    set_CHIP_TARGET(l_cen).
                    set_DIMM_VOLTAGE(l_selected_dram_voltage),
                    "Deconfiguring the associated Centaur.");
    }//End of Centaur (MEMB) loop

    // Iterate through the list of centaurs again, to update ATTR
    for (const auto& l_cen : i_targets_memb)
    {
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_MSS_VOLT, l_cen, l_selected_dram_voltage));
        FAPI_INF( "mss_volt calculation complete.  MSS_VOLT: %d", l_selected_dram_voltage);
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_MSS_VOLT_VPP, l_cen, l_selected_dram_voltage_vpp));
        FAPI_INF( "mss_volt calculation complete.  MSS_VOLT_VPP: %d", l_selected_dram_voltage_vpp);
    }

    // Initialize DIMM Count Attribute for mss_volt_dimm_count to use
    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_MSS_VMEM_REGULATOR_MAX_DIMM_COUNT, fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(),
                           l_dimm_count));

fapi_try_exit:
    return fapi2::current_err;
}
