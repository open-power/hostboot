/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/perv/p9_start_cbs.C $      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2017                        */
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
//------------------------------------------------------------------------------
/// @file  p9_start_cbs.C
///
/// @brief Start CBS : Trigger CBS
//------------------------------------------------------------------------------
// *HWP HW Owner        : Abhishek Agarwal <abagarw8@in.ibm.com>
// *HWP HW Backup Owner : Srinivas V Naga <srinivan@in.ibm.com>
// *HWP FW Owner        : sunil kumar <skumar8j@in.ibm.com>
// *HWP Team            : Perv
// *HWP Level           : 3
// *HWP Consumed by     : SE:HB
//------------------------------------------------------------------------------


//## auto_generated
#include "p9_start_cbs.H"
//## auto_generated
#include "p9_const_common.H"

#include <p9_perv_scom_addresses.H>
#include <p9_perv_scom_addresses_fld.H>
#include <p9_perv_scom_addresses_fixes.H>
#include <p9_perv_scom_addresses_fld_fixes.H>

enum P9_START_CBS_Private_Constants
{
    P9_CFAM_CBS_POLL_COUNT = 20, // Observed Number of times CBS read for CBS_INTERNAL_STATE_VECTOR
    CBS_IDLE_VALUE = 0x002, // Read the value of CBS_CS_INTERNAL_STATE_VECTOR
    P9_CBS_IDLE_HW_NS_DELAY = 640000, // unit is nano seconds [min : 64k x (1/100MHz) = 64k x 10(-8) = 640 us
    //                       max : 64k x (1/50MHz) = 128k x 10(-8) = 1280 us]
    P9_CBS_IDLE_SIM_CYCLE_DELAY = 7500000, // unit is sim cycles,to match the poll count change( 250000 * 30 )
    P9_PIBRESET_HW_NS_DELAY = 4000,  // 256 pibclocks
    P9_PIBRESET_SIM_CYCLE_DELAY = 256000
};

fapi2::ReturnCode p9_start_cbs(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>
                               & i_target_chip,
                               const bool i_sbe_start)
{
    fapi2::buffer<uint32_t> l_read_reg ;
    bool l_read_vdn_pgood_status = false;
    bool l_fsi2pib_status = false;
    fapi2::buffer<uint32_t> l_data32;
    fapi2::buffer<uint32_t> l_data32_cbs_cs;
    int l_timeout = 0;
    fapi2::buffer<uint8_t> l_read_attr;
    FAPI_INF("p9_start_cbs: Entering ...");

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_EC_FEATURE_HW402019_PIBRESET_DELAY,
                           i_target_chip, l_read_attr));

    FAPI_DBG("Clearing  Selfboot message register before every boot ");
    // buffer is init value is 0
    FAPI_TRY(fapi2::putCfamRegister(i_target_chip, PERV_SB_MSG_FSI, l_data32));


    FAPI_DBG("Configuring Prevent SBE start option");
    //Setting CBS_CS register value
    FAPI_TRY(fapi2::getCfamRegister(i_target_chip, PERV_CBS_CS_FSI,
                                    l_data32_cbs_cs));
    l_data32_cbs_cs.setBit<PERV_CBS_CS_OPTION_PREVENT_SBE_START>();
    FAPI_TRY(fapi2::putCfamRegister(i_target_chip, PERV_CBS_CS_FSI,
                                    l_data32_cbs_cs));

    FAPI_DBG("Setting up hreset to 0");
    FAPI_TRY(fapi2::getCfamRegister(i_target_chip, PERV_SB_CS_FSI, l_data32));
    l_data32.clearBit<PERV_SB_CS_START_RESTART_VECTOR0>();
    FAPI_TRY(fapi2::putCfamRegister(i_target_chip, PERV_SB_CS_FSI, l_data32));

    FAPI_DBG("check for VDN_PGOOD");
    //Getting PERV_CBS_ENVSTAT register value
    FAPI_TRY(fapi2::getCfamRegister(i_target_chip, PERV_CBS_ENVSTAT_FSI,
                                    l_data32));
    l_read_vdn_pgood_status = l_data32.getBit<PERV_CBS_ENVSTAT_C4_VDN_GPOOD>();

    FAPI_ASSERT(l_read_vdn_pgood_status,
                fapi2::VDN_PGOOD_NOT_SET()
                .set_MASTER_CHIP(i_target_chip)
                .set_CBS_ENVSTAT_READ(l_data32),
                "ERROR:VDN_PGOOD OFF, CBS_ENVSTAT BIT 2 NOT SET");

    FAPI_DBG("Resetting CFAM Boot Sequencer (CBS) to flush value");
    //Setting CBS_CS register value
    FAPI_TRY(fapi2::getCfamRegister(i_target_chip, PERV_CBS_CS_FSI,
                                    l_data32_cbs_cs));
    l_data32_cbs_cs.clearBit<PERV_CBS_CS_START_BOOT_SEQUENCER>();
    l_data32_cbs_cs.clearBit<PERV_CBS_CS_OPTION_SKIP_SCAN0_CLOCKSTART>();
    FAPI_TRY(fapi2::putCfamRegister(i_target_chip, PERV_CBS_CS_FSI,
                                    l_data32_cbs_cs));


    FAPI_DBG("Triggering CFAM Boot Sequencer (CBS) to start");
    //Setting CBS_CS register value
    l_data32_cbs_cs.setBit<PERV_CBS_CS_START_BOOT_SEQUENCER>();
    FAPI_TRY(fapi2::putCfamRegister(i_target_chip, PERV_CBS_CS_FSI,
                                    l_data32_cbs_cs));

    FAPI_DBG("Check cbs_cs_internal_state_vector");
    l_timeout = P9_CFAM_CBS_POLL_COUNT;

    //UNTIL CBS_CS.CBS_CS_INTERNAL_STATE_VECTOR == CBS_IDLE_VALUE
    while (l_timeout != 0)
    {
        //Getting CBS_CS register value
        FAPI_TRY(fapi2::getCfamRegister(i_target_chip, PERV_CBS_CS_FSI,
                                        l_data32_cbs_cs));
        uint32_t l_poll_data = 0;
        l_data32_cbs_cs.extractToRight<PERV_CBS_CS_INTERNAL_STATE_VECTOR, PERV_CBS_CS_INTERNAL_STATE_VECTOR_LEN>(l_poll_data);

        if (l_poll_data == CBS_IDLE_VALUE)
        {
            break;
        }

        fapi2::delay(P9_CBS_IDLE_HW_NS_DELAY, P9_CBS_IDLE_SIM_CYCLE_DELAY);
        --l_timeout;
    }

    FAPI_DBG("Loop Count :%d", l_timeout);

    FAPI_ASSERT(l_timeout > 0,
                fapi2::CBS_NOT_IN_IDLE_STATE()
                .set_MASTER_CHIP_TARGET(i_target_chip)
                .set_MASTER_CHIP(i_target_chip)
                .set_CBS_CS_READ(l_data32_cbs_cs)
                .set_CBS_CS_IDLE_VALUE(CBS_IDLE_VALUE)
                .set_LOOP_COUNT(P9_CFAM_CBS_POLL_COUNT)
                .set_HW_DELAY(P9_CBS_IDLE_HW_NS_DELAY),
                "ERROR: CBS HAS NOT REACHED IDLE STATE VALUE 0x002 ");

    if ( l_read_attr )
    {
        FAPI_DBG("Setting up Pibreset");
        l_data32.flush<1>();
        FAPI_TRY(fapi2::putCfamRegister(i_target_chip, PERV_FSI2PIB_SET_PIB_RESET_FSI,
                                        l_data32));
        FAPI_DBG("waiting for pibreset to complete");
        fapi2::delay(P9_PIBRESET_HW_NS_DELAY, P9_PIBRESET_SIM_CYCLE_DELAY);
    }

    if ( i_sbe_start )
    {
        FAPI_DBG("Setting up hreset");
        FAPI_TRY(fapi2::getCfamRegister(i_target_chip, PERV_SB_CS_FSI, l_data32));
        l_data32.clearBit<PERV_SB_CS_START_RESTART_VECTOR0>();
        FAPI_TRY(fapi2::putCfamRegister(i_target_chip, PERV_SB_CS_FSI, l_data32));
        l_data32.setBit<PERV_SB_CS_START_RESTART_VECTOR0>();
        FAPI_TRY(fapi2::putCfamRegister(i_target_chip, PERV_SB_CS_FSI, l_data32));
        l_data32.clearBit<PERV_SB_CS_START_RESTART_VECTOR0>();
        FAPI_TRY(fapi2::putCfamRegister(i_target_chip, PERV_SB_CS_FSI, l_data32));
    }

    FAPI_DBG("check for VDD status");
    //Getting FSI2PIB_STATUS register value
    FAPI_TRY(fapi2::getCfamRegister(i_target_chip, PERV_FSI2PIB_STATUS_FSI,
                                    l_data32));
    l_fsi2pib_status = l_data32.getBit<PERV_FSI2PIB_STATUS_VDD_NEST_OBSERVE>();

    FAPI_ASSERT(l_fsi2pib_status,
                fapi2::VDD_NEST_OBSERVE_NOT_SET()
                .set_MASTER_CHIP(i_target_chip)
                .set_FSI2PIB_STATUS_READ(l_data32),
                "ERROR:VDD OFF, FSI2PIB  BIT 16 NOT SET");

    FAPI_INF("p9_start_cbs: Exiting ...");

fapi_try_exit:
    return fapi2::current_err;

}
