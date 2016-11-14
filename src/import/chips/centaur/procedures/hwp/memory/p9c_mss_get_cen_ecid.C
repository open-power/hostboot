/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/centaur/procedures/hwp/memory/p9c_mss_get_cen_ecid.C $ */
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
/// @file p9c_mss_get_cen_ecid.C
/// @brief HWP for training DRAM delay values
///
/// *HWP HWP Owner: Luke Mulkey <lwmulkey@us.ibm.com>
/// *HWP HWP Backup:
/// *HWP Team: Memory
/// *HWP Level: 2
/// *HWP Consumed by: HB
//////
#include <fapi2.H>
#include <p9c_mss_get_cen_ecid.H>

extern "C" {

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------
    fapi2::ReturnCode  user_ecid(    uint8_t& o_ddr_port_status,
                                     uint8_t& o_cache_enable,
                                     uint8_t& o_centaur_sub_revision,
                                     ecid_user_struct& ecid_struct
                                );

// HWP entry point
    fapi2::ReturnCode p9c_mss_get_cen_ecid(
        const fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP>& i_target,
        uint8_t& o_ddr_port_status,
        uint8_t& o_cache_enable,
        uint8_t& o_centaur_sub_revision,
        ecid_user_struct& ecid_struct
    )
    {
        // return code



        // set the init state attribute to CLOCKS_ON
        uint8_t l_attr_mss_init_state;
        uint8_t l_bluewaterfall_nwell_broken;
        uint8_t l_psro;
        uint64_t ecid[2];
        fapi2::buffer<uint64_t> scom;
        uint8_t l_bluewaterfall_broken;
        uint8_t l_nwell_misplacement;
        uint8_t l_ecidContainsPortLogicBadIndication = 0;
        uint8_t l_checkL4CacheEnableUnknown = 0;
        l_attr_mss_init_state = fapi2::ENUM_ATTR_CEN_MSS_INIT_STATE_CLOCKS_ON;
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_MSS_INIT_STATE, i_target,  l_attr_mss_init_state));


        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_CENTAUR_EC_FEATURE_BLUEWATERFALL_NWELL_BROKEN_CHECK_FLAG,
                               i_target, l_bluewaterfall_nwell_broken),
                 "mss_get_cen_ecid: could not GET ATTR_CEN_CENTAUR_EC_FEATURE_BLUEWATERFALL_NWELL_BROKEN_CHECK_FLAG");

        // For certain Centaur DD1.0* subversions, adjustments need to be made to
        // the bluewaterfall and the transistor misplaced in the nwell.
        // l_bluewaterfall_nwell_broken will be 1 if needing changes and 0 if not
        if(l_bluewaterfall_nwell_broken)
        {
            ecid_struct.io_ec = 0x10;
        }
        else
        {
            ecid_struct.io_ec = 0x20;
        }

        FAPI_INF("Centaur EC version 0x%02x", ecid_struct.io_ec);

        if(ecid_struct.valid)
        {

            FAPI_TRY(mss_parse_ecid(ecid_struct.io_ecid,
                                    ecid_struct.i_checkL4CacheEnableUnknown,
                                    ecid_struct.i_ecidContainsPortLogicBadIndication,
                                    l_bluewaterfall_nwell_broken,
                                    o_ddr_port_status,
                                    o_cache_enable,
                                    o_centaur_sub_revision,
                                    ecid_struct.o_psro,
                                    ecid_struct.o_bluewaterfall_broken,
                                    ecid_struct.o_nwell_misplacement ));

            // procedure is done.
            return fapi2::current_err;
        }


        // mark HWP entry
        FAPI_IMP("Entering mss_get_cen_ecid....");
        FAPI_TRY(fapi2::getScom( i_target, ECID_PART_0_0x00010000, scom ),
                 "mss_get_cen_ecid: could not read scom address 0x00010000");
        scom.reverse();
        FAPI_TRY(scom.extract(ecid_struct.io_ecid[0], 0, 64));

        //gets the second part of the ecid and sets the attribute
        FAPI_TRY(fapi2::getScom( i_target, ECID_PART_1_0x00010001, scom ),
                 "mss_get_cen_ecid: could not read scom address 0x00010001" );
        scom.reverse();
        FAPI_TRY(scom.extract(ecid_struct.io_ecid[1], 0, 64));

        ecid[0] = ecid_struct.io_ecid[0];
        ecid[1] = ecid_struct.io_ecid[1];

        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_ECID, i_target,  ecid), "mss_get_cen_ecid: Could not set ATTR_ECID" );

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_CENTAUR_EC_FEATURE_CHECK_L4_CACHE_ENABLE_UNKNOWN,
                               i_target, l_checkL4CacheEnableUnknown),
                 "mss_get_cen_ecid: could not get ATTR_CEN_CENTAUR_EC_FEATURE_CHECK_L4_CACHE_ENABLE_UNKNOWN");
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_CENTAUR_EC_FEATURE_ECID_CONTAINS_PORT_LOGIC_BAD_INDICATION,
                               i_target, l_ecidContainsPortLogicBadIndication),
                 "mss_get_cen_ecid: could not get ATTR_CEN_CENTAUR_EC_FEATURE_ECID_CONTAINS_PORT_LOGIC_BAD_INDICATION" );

        FAPI_TRY(mss_parse_ecid(ecid,
                                l_checkL4CacheEnableUnknown,
                                l_ecidContainsPortLogicBadIndication,
                                l_bluewaterfall_nwell_broken,
                                o_ddr_port_status,
                                o_cache_enable,
                                o_centaur_sub_revision,
                                l_psro,
                                l_bluewaterfall_broken,
                                l_nwell_misplacement ));

        ecid_struct.o_psro = l_psro;
        ecid_struct.o_bluewaterfall_broken = l_bluewaterfall_broken;
        ecid_struct.o_nwell_misplacement = l_nwell_misplacement;

        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_MSS_PSRO, i_target,  l_psro),
                 "mss_get_cen_ecid: could not set ATTR_CEN_MSS_PSRO" );
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_MSS_BLUEWATERFALL_BROKEN, i_target,  l_bluewaterfall_broken),
                 "mss_get_cen_ecid: could not set ATTR_CEN_MSS_BLUEWATERFALL_BROKEN");
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_MSS_NWELL_MISPLACEMENT, i_target,  l_nwell_misplacement),
                 "mss_get_cen_ecid: could not set ATTR_CEN_MSS_NWELL_MISPLACEMENT");
        // mark HWP exit
        FAPI_IMP("Exiting mss_get_cen_ecid....");
    fapi_try_exit:
        return fapi2::current_err;
    }

// Decoder function which allows us to pass in just the raw ECID data and get it decoded for in the lab
// or we can just use it to set up all the needed attributes

    fapi2::ReturnCode mss_parse_ecid(uint64_t ecid[2],
                                     const uint8_t i_checkL4CacheEnableUnknown,
                                     const uint8_t i_ecidContainsPortLogicBadIndication,
                                     const uint8_t i_bluewaterfall_nwell_broken,
                                     uint8_t& o_ddr_port_status,
                                     uint8_t& o_cache_enable,
                                     uint8_t& o_centaur_sub_revision,
                                     uint8_t& o_psro,
                                     uint8_t& o_bluewaterfall_broken,
                                     uint8_t& o_nwell_misplacement )
    {
//get bit128
        uint8_t bit128 = 0;
        uint8_t bit126 = 0;
        uint8_t bit125 = 0;
        uint8_t bit117_124 = 0;

        fapi2::buffer<uint64_t> scom;

        o_nwell_misplacement = 0;
        o_bluewaterfall_broken = 0;


        FAPI_TRY(scom.insert(ecid[1], 0, 64), "mss_get_cen_ecid: error manipulating fapi2::variable_buffer");
        FAPI_TRY(scom.extract(bit128, 63, 1), "mss_get_cen_ecid: could not extract cache data_valid bit");
        bit128 = bit128 >> 7;

        if(bit128 == 1)   // Cache enable bit is valid
        {

            //gets bits 113 and 114 to determine the state of the cache
            uint8_t bit113_114 = 0;
            FAPI_TRY(scom.extract(bit113_114, 48, 2), "mss_get_cen_ecid: could not extract cache data");
            bit113_114 = bit113_114 >> 6;
            uint8_t t;

            //determines the state of the cache
            if(bit113_114 == 0)
            {
                t = fapi2::ENUM_ATTR_CEN_MSS_CACHE_ENABLE_ON;
            }
            else if(bit113_114 == 1)
            {
                t = fapi2::ENUM_ATTR_CEN_MSS_CACHE_ENABLE_HALF_A;
            }
            else if(bit113_114 == 2)
            {
                t = fapi2::ENUM_ATTR_CEN_MSS_CACHE_ENABLE_HALF_B;
            }
            else
            {
                t = fapi2::ENUM_ATTR_CEN_MSS_CACHE_ENABLE_OFF;
            }

            // Centaur DD1.X chips have an ECBIT in bit127, if this is zero then the
            // cache enable bits are in an unknown state. DD2.X chips and higher do not
            // have an ECBIT. The decision to look at the ECBIT is done with a Chip EC
            // Feature Attribute - the attribute XML can be easily tweaked if it is
            // found that other DD levels also have an ECBIT.
            // Centaur | DataValid | ECBIT  | Return Value   | Firmware Action | Cronus Action**|
            // 1.*     | 0         | 0 or 1 | DIS            | DIS             | DIS            |
            // 1.*     | 1         | 0      | Unk ENA/DIS/A/B| DIS             | ENA/DIS/A/B    |
            // 1.*     | 1         | 1      | ENA/DIS/A/B    | ENA/DIS*        | ENA/DIS/A/B    |
            // != 1.*  | 0         | N/A    | DIS            | DIS             | DIS            |
            // != 1.*  | 1         | N/A    | ENA/DIS/A/B    | ENA/DIS         | ENA/DIS/A/B    |
            //
            // * firmware can suport paritial cache if it wants to for DD1.* (e.g. DD1.0 DD1.01, DD1.1 etc)
            //    However, if it chooses to, it should still make all Unk ones disabled
            // ** Cronus Action - cronus and all fapi2 procedures only support the original defintion of ENA/DIS/A/B
            //    Cronus actually uses its config file for the 4 values and checks the hardware via the get_cen_ecid
            //    procedure during step 11 to make sure the end user does not enable a disable cache
            //    Under cronus, the Unk information is only printed to the screen

            if (i_checkL4CacheEnableUnknown)
            {
                uint8_t bit127 = 0;
                FAPI_TRY(scom.extract(bit127, 62, 1), "mss_get_cen_ecid: could not extract ECBIT bit");
                bit127 = bit127 >> 7;

                if(bit127 == 0)
                {
                    FAPI_INF("mss_get_cen_ecid: Cache Enable Bits are in Unknown State");

                    if(bit113_114 == 0)
                    {
                        t = fapi2::ENUM_ATTR_CEN_MSS_CACHE_ENABLE_UNK_ON;
                    }
                    else if(bit113_114 == 1)
                    {
                        t = fapi2::ENUM_ATTR_CEN_MSS_CACHE_ENABLE_UNK_HALF_A;
                    }
                    else if(bit113_114 == 2)
                    {
                        t = fapi2::ENUM_ATTR_CEN_MSS_CACHE_ENABLE_UNK_HALF_B;
                    }
                    else
                    {
                        t = fapi2::ENUM_ATTR_CEN_MSS_CACHE_ENABLE_UNK_OFF;
                    }
                }
                else
                {
                    FAPI_INF("mss_get_cen_ecid: Cache Enable Bits are in Known State");
                }
            }

            o_cache_enable = t;
        }
        else
        {
            FAPI_INF("Cache Disbled because eDRAM data bits are assumed to be bad");
            o_cache_enable = fapi2::ENUM_ATTR_CEN_MSS_CACHE_ENABLE_OFF;
        }

        //reads in the ECID info for whether a DDR port side is good or bad
        //This is only defined for DD1.x parts
        if(i_ecidContainsPortLogicBadIndication )
        {
            FAPI_TRY(scom.extract(o_ddr_port_status, 50, 2), "mss_get_cen_ecid: could not extract DDR status data" );
            o_ddr_port_status = o_ddr_port_status >> 6;
        }
        else
        {
            o_ddr_port_status = 0x0; // logic in both ports are good
        }


        //116..123         average PSRO from 85C wafer test
        FAPI_TRY(scom.extract(bit117_124, 52, 8), "mss_get_cen_ecid: could not extract PSRO");
        o_psro = bit117_124;

        // read the bit in the ecid to see if we are a DD1.01
        // Bit 124 DD1.01  Indicator Bit. Set to '1' for DD1.01 devices
        FAPI_TRY(scom.extract(bit125, 60, 1), "mss_get_cen_ecid: could not extract dd1.01 indicator bit");
        bit125 = bit125 >> 7;
        o_centaur_sub_revision = bit125;

        // The ecid contains the chip's subrevision, changes in the subrevision should not
        // change firmware behavior but for the exceptions, update attributes to indicate
        // those behaviors
        if (i_bluewaterfall_nwell_broken && (o_centaur_sub_revision < 1))
        {
            // For DD1.00, the transistor misplaced in the nwell needs some setting adjustments to get it to function
            // after DD1.00, we no longer need to make that adjustment
            o_nwell_misplacement = 1;
        }

        FAPI_TRY(scom.extract(bit126, 61, 1), "mss_get_cen_ecid: could not extract dd1.03 indicator bit");
        bit126 = bit126 >> 7;

        // we have to look at both the bluewaterfall and the n-well misplacement to determine the proper values of the n-well
        if (i_bluewaterfall_nwell_broken)
        {
            if(bit126 == 0)
            {
                // on and after DD1.03, we no longer need to make adjustments due to the bluewaterfall - this is before
                o_bluewaterfall_broken = 1;
            }
            else
            {
                o_nwell_misplacement = 0; // Assume if the bluewaterfall is fixed, then the nwell is also fixed
            }
        }

    fapi_try_exit:
        return fapi2::current_err;
    }

    fapi2::ReturnCode  user_ecid(    uint8_t& o_ddr_port_status,
                                     uint8_t& o_cache_enable,
                                     uint8_t& o_centaur_sub_revision,
                                     ecid_user_struct& ecid_struct
                                )
    {

        return mss_parse_ecid(ecid_struct.io_ecid,
                              ecid_struct.i_checkL4CacheEnableUnknown,
                              ecid_struct.i_ecidContainsPortLogicBadIndication,
                              ecid_struct.i_bluewaterfall_nwell_broken,
                              o_ddr_port_status,
                              o_cache_enable,
                              o_centaur_sub_revision,
                              ecid_struct.o_psro,
                              ecid_struct.o_bluewaterfall_broken,
                              ecid_struct.o_nwell_misplacement );

    }


} // extern "C"
