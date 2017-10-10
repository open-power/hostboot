/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/centaur/procedures/hwp/memory/p9c_mss_eff_mb_interleave.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2017                        */
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
/// @file p9c_mss_eff_mb_interleave.C
/// @brief  checks the plugging rules for a centaur and works with interleaving within the centaur
///
/// *HWP HWP Owner: Luke Mulkey <lwmulkey@us.ibm.com>
/// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
/// *HWP Team: Memory
/// *HWP Level: 2
/// *HWP Consumed by: HB

#include <p9c_mss_eff_mb_interleave.H>
#include <dimmConsts.H>
#include <fapi2.H>

extern "C" {

    enum DECONFIG_TYPES  { DECONFIG_PORT_1_SLOT_0_IS_EMPTY_PORT_0_SLOT_0_IS_NOT = 0,
                           DECONFIG_PORT_1_SLOT_0_IS_NOT_EQUAL_TO_PORT_0_SLOT_0_A = 1,
                           DECONFIG_PORT_1_SLOT_0_IS_NOT_EQUAL_TO_PORT_0_SLOT_0_B = 2,
                           DECONFIG_PORT_0_SLOT_1_DECONFIGURED_BECAUSE_PORT_0_SLOT_0_WAS_DECONFIGURED = 3,
                           DECONFIG_PORT_1_SLOT_1_DECONFIGURED_BECAUSE_PORT_0_SLOT_0_WAS_DECONFIGURED = 4,
                           DECONFIG_PORT_0_SLOT_1_DECONFIGURED_BECAUSE_PORT_1_SLOT_1_IS_NOT_EQUAL = 5,
                           DECONFIG_PORT_1_SLOT_1_DECONFIGURED_BECAUSE_PORT_0_SLOT_1_IS_NOT_EQAUL = 6,
                           DECONFIG_PORT_0_SLOT_1_DECONFIGURED_BECAUSE_PORT_0_SLOT_0_IS_NOT_EQUAL = 7,
                           DECONFIG_PORT_1_SLOT_1_DECONFIGURED_BECAUSE_PORT_0_SLOT_0_IS_NOT_EQUAL = 8,
                           DECONFIG_PORT_0_SLOT_1_DECONFIGURED_BECAUSE_PORT_1_SLOT_1_IS_NOT_VALID = 9,
                           DECONFIG_PORT_1_SLOT_1_DECONFIGURED_BECAUSE_PORT_0_SLOT_1_IS_NOT_VALID = 10,
                           DECONFIG_PORT_1_HAS_SOMETHING_BUT_PORT_0_SLOT_0_IS_EMPTY = 11,
                           DECONFIG_PORT_0_SLOT_1_HAS_SOMETHING_BUT_PORT_0_SLOT_0_IS_EMPTY = 12,
                           DECONFIG_SLOT_1_HAS_SOMETHING_BUT_PORT_0_SLOT_0_IS_EMPTY = 13,
                           DECONFIG_INTERLEAVE_MODE_CONTROL_IS_REQUIRED = 99
                         };


    constexpr uint8_t MSS_MBA_ADDR_INTERLEAVE_BIT = 24; // From Eric Retter:
    // the prefetch and cleaner assume that bit 24 is the interleave bit.
    // We put other interleave options in for other settings that could be
    // tried in performance testing

    class mss_eff_mb_dimm
    {
        public:
            uint8_t module_type;
            uint8_t dram_gen;
            uint8_t device_density;
            uint8_t num_of_ranks;
            uint8_t device_width;
            uint8_t module_width;
            uint8_t thermal_sensor;
            uint8_t size;
            fapi2::Target<fapi2::TARGET_TYPE_DIMM> mydimm_target;
            bool  valid;
            uint8_t side;
            uint8_t port;
            uint8_t slot;

            mss_eff_mb_dimm();
            fapi2::ReturnCode load(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_dimms, uint32_t size);
            bool is_valid();
            fapi2::ReturnCode deconfig(uint8_t i_case);
            bool operator!=(const mss_eff_mb_dimm&) const;
    };

    ///
    /// @brief checks the plugging rules for a centaur and works with interleaving within the centaur
    /// @param[in] i_cen_target
    /// @return fapi2::returnCode
    ///
    fapi2::ReturnCode p9c_mss_eff_mb_interleave(const fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP>& i_cen_target)
    {

        mss_eff_mb_dimm l_dimm_array[MAX_MBA_PER_CEN][MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT] = {}; // side, port, dimm
        std::vector<fapi2::Target<fapi2::TARGET_TYPE_DIMM>> l_target_dimm_array[MAX_MBA_PER_CEN];
        uint8_t l_mba = 0;
        uint8_t l_cur_mba_port = 0;
        uint8_t l_cur_mba_dimm = 0;
        uint8_t l_side = 0, l_port = 0, l_slot = 0;
        uint8_t l_hadadeconfig[MAX_MBA_PER_CEN] = {0};
        uint8_t l_mss_derived_mba_cacheline_interleave_mode = 0;
        uint8_t l_mss_mba_addr_interleave_bit = 0;
        uint8_t l_mrw_mba_cacheline_interleave_mode_control = 0;
        uint32_t l_size[MAX_MBA_PER_CEN] = {0};
        uint8_t l_eff_dimm_size[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT] = {0};
        uint8_t l_attr_mrw_strict_mba_plug_rule_checking = 0;
        uint8_t l_deconfig_0_0 = 0;


        do
        {
            // first step, load up the dimms connected to this centaur
            for(l_side = 0; l_side < MAX_MBA_PER_CEN; l_side++)
            {
                for(l_port = 0; l_port < MAX_PORTS_PER_MBA; l_port++)
                {
                    for(l_slot = 0; l_slot < MAX_DIMM_PER_PORT; l_slot++)
                    {
                        l_dimm_array[l_side][l_port][l_slot].side = l_side;
                        l_dimm_array[l_side][l_port][l_slot].port = l_port;
                        l_dimm_array[l_side][l_port][l_slot].slot = l_slot;
                    }
                }
            }

            const auto l_mba_chiplets = i_cen_target.getChildren<fapi2::TARGET_TYPE_MBA>();

            for(const auto& mba_i : l_mba_chiplets)
            {
                FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, mba_i,  l_mba));
                l_target_dimm_array[l_mba] = mba_i.getChildren<fapi2::TARGET_TYPE_DIMM>();

                for (const auto& l_dimm : l_target_dimm_array[l_mba])
                {
                    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_MBA_PORT, l_dimm, l_cur_mba_port));
                    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_MBA_DIMM, l_dimm, l_cur_mba_dimm));
                    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DIMM_SIZE, mba_i,  l_eff_dimm_size));

                    FAPI_INF("Loading up information about dimm for mba %d port %d dimm %d", l_mba, l_cur_mba_port, l_cur_mba_dimm);
                    FAPI_INF("DIMM size is eff_dimm_size[%d][%d] = %d", l_cur_mba_port, l_cur_mba_dimm,
                             l_eff_dimm_size[l_cur_mba_port][l_cur_mba_dimm]);

                    FAPI_TRY(l_dimm_array[l_mba][l_cur_mba_port][l_cur_mba_dimm].load(l_dimm,
                             l_eff_dimm_size[l_cur_mba_port][l_cur_mba_dimm]));
                } // Each DIMM off this MBA
            } // Each MBA

            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_MRW_STRICT_MBA_PLUG_RULE_CHECKING, fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(),
                                   l_attr_mrw_strict_mba_plug_rule_checking));

            if(l_attr_mrw_strict_mba_plug_rule_checking == fapi2::ENUM_ATTR_CEN_MRW_STRICT_MBA_PLUG_RULE_CHECKING_TRUE)
            {

                // - Logical DIMMs are considered to be identical if they have the following attributes in common: Module Type (RDIMM or LRDIMM),
                //   Architecture (DDR3 vs DDR4), Device Density, Number of Ranks, Device Width, Module Width, and Thermal Sensor.

                // Plug Rule 4.1 - Logical DIMMs have to be plugged in pairs on either Port A & B or on Port C & D. Paired DIMMs must be identical.
                // Plug Rule 4.2 - If there is a Logical DIMM plugged in Slot 1 then an identical DIMM must be plugged in Slot0

                // Plug rules 4.1 and 4.2 define valid configurations which are:
                // - DIMM type X populated in slot0 only, slot1 is not populated
                // - DIMM type X populated in slot0 and slot1
                for(l_side = 0; l_side < MAX_MBA_PER_CEN; l_side++)
                {
                    l_hadadeconfig[l_side] = 0;

                    if(l_dimm_array[l_side][0][0].is_valid())   // there is a dimm on port 0, slot 0, this is a must
                    {
                        l_deconfig_0_0 = 0;

                        // case 0, you don't have a pair of dimms on port 0 and port 1, kill port0,0
                        if(! l_dimm_array[l_side][1][0].is_valid())
                        {
                            FAPI_ERR("Deconfig Rule 4.1 :Plug Rule 4.1 violated, Port 1 on Side %d slot 0 is empty Port 0 slot 0 is not", l_side);
                            FAPI_TRY(l_dimm_array[l_side][0][0].deconfig(DECONFIG_PORT_1_SLOT_0_IS_EMPTY_PORT_0_SLOT_0_IS_NOT));
                            l_hadadeconfig[l_side] = 1;
                            l_deconfig_0_0 = 1;
                        }

                        // case 1, you did not kill dimm 0,0, so now check that 0,0 == 1,0
                        if( l_deconfig_0_0 == 0 &&
                            ( l_dimm_array[l_side][0][0] != l_dimm_array[l_side][1][0]))
                        {
                            FAPI_ERR("Deconfig Rule 4.1 :Plug Rule 4.1 violated, Port 1 on Side %d slot 0 is not equal to Port 0 slot 0", l_side);
                            FAPI_TRY(l_dimm_array[l_side][0][0].deconfig(DECONFIG_PORT_1_SLOT_0_IS_NOT_EQUAL_TO_PORT_0_SLOT_0_A));
                            FAPI_TRY(l_dimm_array[l_side][1][0].deconfig(DECONFIG_PORT_1_SLOT_0_IS_NOT_EQUAL_TO_PORT_0_SLOT_0_B));
                            l_hadadeconfig[l_side] = 1;
                            l_deconfig_0_0 = 1;
                        }

                        // if dimm 0,0 is gone, then blow away any dimm 0,1 and 1,1
                        if(l_deconfig_0_0 )
                        {
                            if(l_dimm_array[l_side][0][1].is_valid())
                            {
                                FAPI_ERR("Deconfig Rule 4.1 :Plug Rule 4.1 violated, Port 0 on Side %d slot 1 deconfigured because Port 0 slot 0 was deconfigured",
                                         l_side);
                                FAPI_TRY(l_dimm_array[l_side][0][1].deconfig(
                                             DECONFIG_PORT_0_SLOT_1_DECONFIGURED_BECAUSE_PORT_0_SLOT_0_WAS_DECONFIGURED));
                                l_hadadeconfig[l_side] = 1;
                            }

                            if(l_dimm_array[l_side][1][1].is_valid())
                            {
                                FAPI_ERR("Deconfig Rule 4.1 :Plug Rule 4.1 violated, Port 1 on Side %d slot 1 deconfigured because Port 0 slot 0 was deconfigured",
                                         l_side);
                                FAPI_TRY(l_dimm_array[l_side][1][1].deconfig(
                                             DECONFIG_PORT_1_SLOT_1_DECONFIGURED_BECAUSE_PORT_0_SLOT_0_WAS_DECONFIGURED));
                                l_hadadeconfig[l_side] = 1;
                            }
                        }
                        else   // you have 0,0, so check if there is a 0,1 and 1,1 and they are equal
                        {
                            // and 0,1 must equal 1,1, otherwise, get rid of 0,1 and 1,1
                            if(l_dimm_array[l_side][0][1].is_valid() && l_dimm_array[l_side][1][1].is_valid())
                            {
                                if(l_dimm_array[l_side][0][1] != l_dimm_array[l_side][1][1])
                                {
                                    FAPI_ERR("Deconfig Rule 4.1 :Plug Rule 4.1 violated, Port 0 on Side %d slot 1 deconfigured because Port 1 slot 1 is not equal",
                                             l_side);
                                    FAPI_TRY(l_dimm_array[l_side][0][1].deconfig(DECONFIG_PORT_0_SLOT_1_DECONFIGURED_BECAUSE_PORT_1_SLOT_1_IS_NOT_EQUAL));
                                    FAPI_ERR("Deconfig Rule 4.1 :Plug Rule 4.1 violated, Port 1 on Side %d slot 1 deconfigured because Port 0 slot 1 is not eqaul",
                                             l_side);
                                    FAPI_TRY(l_dimm_array[l_side][1][1].deconfig(DECONFIG_PORT_1_SLOT_1_DECONFIGURED_BECAUSE_PORT_0_SLOT_1_IS_NOT_EQAUL));
                                    l_hadadeconfig[l_side] = 1;
                                }
                                else
                                {
                                    if(l_dimm_array[l_side][0][0] != l_dimm_array[l_side][0][1])
                                    {
                                        FAPI_ERR("Deconfig Rule 4.2 :Plug Rule 4.2 violated, Port 0 on Side %d slot 1 deconfigured because Port 0 slot 0 is not equal",
                                                 l_side);
                                        FAPI_TRY(l_dimm_array[l_side][0][1].deconfig(DECONFIG_PORT_0_SLOT_1_DECONFIGURED_BECAUSE_PORT_0_SLOT_0_IS_NOT_EQUAL));
                                        FAPI_ERR("Deconfig Rule 4.2 :Plug Rule 4.1 violated, Port 1 on Side %d slot 1 deconfigured because Port 0 slot 0 is not equal",
                                                 l_side);
                                        FAPI_TRY(l_dimm_array[l_side][1][1].deconfig(DECONFIG_PORT_1_SLOT_1_DECONFIGURED_BECAUSE_PORT_0_SLOT_0_IS_NOT_EQUAL));
                                        l_hadadeconfig[l_side] = 1;
                                    }
                                }
                            }
                            else
                            {
                                if(l_dimm_array[l_side][0][1].is_valid())
                                {
                                    FAPI_ERR("Deconfig Rule 4.1 :Plug Rule 4.1 violated, Port 0 on Side %d slot 1 deconfigured because Port 1 slot 1 is not valid",
                                             l_side);
                                    FAPI_TRY(l_dimm_array[l_side][0][1].deconfig(DECONFIG_PORT_0_SLOT_1_DECONFIGURED_BECAUSE_PORT_1_SLOT_1_IS_NOT_VALID));
                                }

                                if(l_dimm_array[l_side][1][1].is_valid())
                                {
                                    FAPI_ERR("Deconfig Rule 4.1 :Plug Rule 4.1 violated, Port 1 on Side %d slot 1 deconfigured because Port 0 slot 1 is not valid",
                                             l_side);
                                    FAPI_TRY(l_dimm_array[l_side][1][1].deconfig(DECONFIG_PORT_1_SLOT_1_DECONFIGURED_BECAUSE_PORT_0_SLOT_1_IS_NOT_VALID));
                                    l_hadadeconfig[l_side] = 1;
                                }

                            }
                        }
                    }
                    else   // if there is no slot 0,0, then everything else is invalid
                    {
                        if(l_dimm_array[l_side][1][0].is_valid())
                        {
                            FAPI_ERR("Deconfig Rule 4.1 :Plug Rule 4.1 violated, Port 1 on Side %d has something but Port 0 slot 0 is empty",
                                     l_side);
                            FAPI_TRY(l_dimm_array[l_side][1][0].deconfig(DECONFIG_PORT_1_HAS_SOMETHING_BUT_PORT_0_SLOT_0_IS_EMPTY));
                            l_hadadeconfig[l_side] = 1;
                        }

                        if(l_dimm_array[l_side][0][1].is_valid())   // there is a dimm slot 1, but slot 0 is empty
                        {
                            FAPI_ERR("Deconfig Rule 4.1 :Plug Rule 4.2 violated, Port 0 on Side %d slot 1 has something but Port 0 slot 0 is empty",
                                     l_side);
                            FAPI_TRY(l_dimm_array[l_side][0][1].deconfig(DECONFIG_PORT_0_SLOT_1_HAS_SOMETHING_BUT_PORT_0_SLOT_0_IS_EMPTY));
                            l_hadadeconfig[l_side] = 1;
                        }

                        if(l_dimm_array[l_side][1][1].is_valid())   // there is a dimm slot 1, but slot 0 is empty
                        {
                            FAPI_ERR("Deconfig Rule 4.1 :Plug Rule 4.2 violated, Port 0 on Side %d slot 1 has something but Port 0 slot 0 is empty",
                                     l_side);
                            FAPI_TRY(l_dimm_array[l_side][1][1].deconfig(DECONFIG_SLOT_1_HAS_SOMETHING_BUT_PORT_0_SLOT_0_IS_EMPTY));
                            l_hadadeconfig[l_side] = 1;
                        }
                    }

                    if(l_hadadeconfig[l_side])
                    {
                        FAPI_INF("There was a Deconfig on l_side %d due to a plug rule 4.1 and/or 4.2", l_side);
                    }
                    else
                    {
                        FAPI_INF("No Deconfig on l_side %d so far", l_side);
                    }
                }

                // Deconfig Rule 4.1 - When Plug rules 4.1 or 4.2 are violated all Logical DIMMs behind the MBA in violation are deconfiged.
                //    This error will be redetected on the next IPL no Persistent guard required. This rule is enforced by mss_eff_cnfg HW procedure.

                // Deconfig by Association Rule 4.1 - If a logical DIMM is deconfigured; all logical DIMMs on the same MBA must also be deconfigured by association.
                //    Since MBAs with no configured DIMMs are also deconfigured this will lead to the MBA also being deconfigured.
                //    This error will be redetected on the next IPL no Persistent guard required.
                // Deconfig by Association Rule 4.2 MBAs with no configured DIMMs are deconfigured this will lead to the MBA also being deconfigured.
                //    This error will be redetected on the next IPL no Persistent guard required.

                // Note - In an IS DIMM system that is running in interleave mode: due to the interactions between Plug rules 4.1, 4.2 and 3.3 the IS DIMM will need to be plugged in quads.
                // This means an identical pair of a total size behind one half of a Centaur Pair and another identical pair of the same total size behind the other Centaur in the Pair.
                // Note that the 2 pairs of DIMMs need not be identical to each other just have the same total size.
            } // end of strict checking

            for(l_side = 0; l_side < MAX_MBA_PER_CEN; l_side++)
            {
                for(l_port = 0; l_port < MAX_PORTS_PER_MBA; l_port++)
                {
                    for(l_slot = 0; l_slot < MAX_DIMM_PER_PORT; l_slot++)
                    {
                        l_size[l_side] += l_dimm_array[l_side][l_port][l_slot].size;
                    }
                }
            }

            FAPI_INF("Sizes on each l_side %d %d", l_size[0], l_size[1]);

            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_MRW_MBA_CACHELINE_INTERLEAVE_MODE_CONTROL,
                                   fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(), l_mrw_mba_cacheline_interleave_mode_control));

            switch(l_mrw_mba_cacheline_interleave_mode_control)
            {
                case fapi2::ENUM_ATTR_CEN_MRW_MBA_CACHELINE_INTERLEAVE_MODE_CONTROL_NEVER:
                    l_mss_derived_mba_cacheline_interleave_mode = fapi2::ENUM_ATTR_CEN_MSS_DERIVED_MBA_CACHELINE_INTERLEAVE_MODE_OFF;
                    l_mss_mba_addr_interleave_bit = 0;
                    break;

                case fapi2::ENUM_ATTR_CEN_MRW_MBA_CACHELINE_INTERLEAVE_MODE_CONTROL_REQUIRED:
                    if(l_size[0] != l_size[1])
                    {
                        FAPI_ERR("ATTR_CEN_MRW_MBA_CACHELINE_INTERLEAVE_MODE_CONTROL is REQUIRED, but size on l_side 0 does not match size on l_side 1 sizes %d %d",
                                 l_size[0], l_size[1]);
                        l_mss_derived_mba_cacheline_interleave_mode = fapi2::ENUM_ATTR_CEN_MSS_DERIVED_MBA_CACHELINE_INTERLEAVE_MODE_OFF;
                        l_mss_mba_addr_interleave_bit = 0;

                        for(l_side = 0; l_side < MAX_MBA_PER_CEN; l_side++)
                        {
                            for(l_port = 0; l_port < MAX_PORTS_PER_MBA; l_port++)
                            {
                                for(l_slot = 0; l_slot < MAX_DIMM_PER_PORT; l_slot++)
                                {
                                    if(l_dimm_array[l_side][l_port][l_slot].is_valid())
                                    {
                                        FAPI_ERR("Deconfig INTERLEAVE_MODE_CONTROL is REQUIRED violated Port %d on Side %d l_slot %d", l_port, l_side, l_slot);
                                        FAPI_TRY(l_dimm_array[l_side][l_port][l_slot].deconfig(DECONFIG_INTERLEAVE_MODE_CONTROL_IS_REQUIRED));
                                    }
                                }
                            }
                        }
                    }
                    else
                    {
                        l_mss_derived_mba_cacheline_interleave_mode = fapi2::ENUM_ATTR_CEN_MSS_DERIVED_MBA_CACHELINE_INTERLEAVE_MODE_ON;
                        l_mss_mba_addr_interleave_bit = MSS_MBA_ADDR_INTERLEAVE_BIT;
                    }

                    break;

                case fapi2::ENUM_ATTR_CEN_MRW_MBA_CACHELINE_INTERLEAVE_MODE_CONTROL_REQUESTED:
                    if(l_size[0] != l_size[1])
                    {
                        l_mss_derived_mba_cacheline_interleave_mode = fapi2::ENUM_ATTR_CEN_MSS_DERIVED_MBA_CACHELINE_INTERLEAVE_MODE_OFF;
                        l_mss_mba_addr_interleave_bit = 0;
                    }
                    else
                    {
                        l_mss_derived_mba_cacheline_interleave_mode = fapi2::ENUM_ATTR_CEN_MSS_DERIVED_MBA_CACHELINE_INTERLEAVE_MODE_ON;
                        l_mss_mba_addr_interleave_bit = MSS_MBA_ADDR_INTERLEAVE_BIT;
                    }

                    break;

                default:
                    FAPI_ERR("Internal Error: ATTR_CEN_MRW_MBA_CACHELINE_INTERLEAVE_MODE_CONTROL is not a known value");
                    l_mss_derived_mba_cacheline_interleave_mode = fapi2::ENUM_ATTR_CEN_MSS_DERIVED_MBA_CACHELINE_INTERLEAVE_MODE_OFF;
                    l_mss_mba_addr_interleave_bit = 0;
                    break;

            } // end switch (cachline_interleave_mode_control)

            FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_MSS_DERIVED_MBA_CACHELINE_INTERLEAVE_MODE, i_cen_target,
                                   l_mss_derived_mba_cacheline_interleave_mode));

            FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_MSS_DERIVED_MBA_ADDR_INTERLEAVE_BIT, i_cen_target,
                                   l_mss_mba_addr_interleave_bit));

        }
        while(0);

        FAPI_INF("mb_interleave done");

    fapi_try_exit:
        return fapi2::current_err;
    }

    // default constructor
    mss_eff_mb_dimm::mss_eff_mb_dimm()
    {
        module_type = 0;
        dram_gen = 0;
        device_density = 0;
        num_of_ranks = 0;
        device_width = 0;
        module_width = 0;
        thermal_sensor = 0;
        size = 0;
        valid = 0;
    }

    fapi2::ReturnCode mss_eff_mb_dimm::load(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_dimm, uint32_t i_size)
    {
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_SPD_MODULE_TYPE, i_dimm,  module_type));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_SPD_SDRAM_DEVICE_TYPE, i_dimm,  dram_gen));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_SPD_SDRAM_DENSITY, i_dimm,  device_density));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_SPD_NUM_RANKS, i_dimm,  num_of_ranks));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_SPD_DRAM_WIDTH, i_dimm,  device_width));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_SPD_MODULE_MEMORY_BUS_WIDTH, i_dimm,  module_width));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_SPD_MODULE_THERMAL_SENSOR, i_dimm,  thermal_sensor));
        mydimm_target = i_dimm;

        size = i_size;

        if(i_size != 0)
        {
            valid = 1;
        }
        else
        {
            valid = 0;
        }

    fapi_try_exit:
        return fapi2::current_err;
    }

    bool mss_eff_mb_dimm::is_valid()
    {
        return valid;
    }

    fapi2::ReturnCode mss_eff_mb_dimm::deconfig(uint8_t i_case)
    {
        FAPI_ASSERT(false,
                    fapi2::CEN_MSS_EFF_MB_INTERLEAVE_PLUG_DECONFIG_DIMM().
                    set_DIMM(mydimm_target).
                    set_CASE(i_case),
                    "Deconfiguring a dimm due to a plugging rule violation at centuar/mba level case num %d (%d%d%d)", i_case, side, port,
                    slot);

        valid = 0;
        size = 0;
    fapi_try_exit:
        return fapi2::current_err;
    }

    bool mss_eff_mb_dimm::operator!=(const mss_eff_mb_dimm& a) const
    {
        if( module_type == a.module_type &&
            dram_gen == a.dram_gen &&
            device_density == a.device_density &&
            num_of_ranks == a.num_of_ranks &&
            device_width == a.device_width &&
            module_width == a.module_width &&
            thermal_sensor == a.thermal_sensor &&
            size == a.size )
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }
}
