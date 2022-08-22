/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/perv/p10_start_cbs.C $    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2022                        */
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
/// @file  p10_start_cbs.C
///
/// @brief Start CBS : Trigger CBS
//------------------------------------------------------------------------------
// *HWP HW Maintainer   : Anusha Reddy (anusrang@in.ibm.com)
// *HWP FW Maintainer   : Raja Das (rajadas2@in.ibm.com)
// *HWP Consumed by     : FSP
//------------------------------------------------------------------------------


#include "p10_start_cbs.H"
#include "p10_scom_perv_9.H"
#include "p10_scom_perv_a.H"
#include "p10_scom_perv_c.H"
#include "p10_scom_perv_d.H"
#include "p10_scom_proc_f.H"
#include "p10_avsbus_lib.H"

enum P10_START_CBS_Private_Constants
{
    P10_CFAM_CBS_POLL_COUNT = 200, // Observed Number of times CBS read for CBS_INTERNAL_STATE_VECTOR
    CBS_IDLE_VALUE = 0x002, // Read the value of CBS_CS_INTERNAL_STATE_VECTOR
    P10_CBS_IDLE_HW_NS_DELAY = 640000, // unit is nano seconds [min : 64k x (1/100MHz) = 64k x 10(-8) = 640 us
    //                       max : 64k x (1/50MHz) = 128k x 10(-8) = 1280 us]
    P10_CBS_IDLE_SIM_CYCLE_DELAY = 750000, // unit is sim cycles,to match the poll count change( 250000 * 30 )
    FIFO_RESET = 0x80000000
};

fapi2::ReturnCode p10_start_cbs(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>
                                & i_target_chip,
                                const bool i_sbe_start)
{
    using namespace scomt;

    bool l_read_vdn_pgood_status = false;
    fapi2::buffer<uint32_t> l_data32;
    fapi2::buffer<uint32_t> l_data32_cbs_cs;
    fapi2::ATTR_CP_REFCLOCK_SELECT_Type l_cp_refclck_select;
    uint8_t l_callout_clock = fapi2::ENUM_ATTR_CP_REFCLOCK_SELECT_OSC1;
    int l_timeout = 0;
    const auto railType = p10avslib::AVS_VDN;
    uint8_t avsBus = AVSBUS_UNDEF;
    uint8_t avsRail = AVSRAIL_UNDEF;
    fapi2::ATTR_AVSBUS_BUSNUM_Type avsBusArr  = {AVSBUS_UNDEF, AVSBUS_UNDEF, AVSBUS_UNDEF, AVSBUS_UNDEF};
    fapi2::ATTR_AVSBUS_RAIL_Type   avsRailArr = {AVSRAIL_UNDEF, AVSRAIL_UNDEF, AVSRAIL_UNDEF, AVSRAIL_UNDEF};

    FAPI_INF("p10_start_cbs: Entering ...");

    FAPI_DBG("Clearing  Selfboot message register before every boot ");
    FAPI_TRY(fapi2::putCfamRegister(i_target_chip, perv::FSXCOMP_FSXLOG_SB_MSG_FSI, 0));

    FAPI_DBG("Setting up hreset to 0");
    FAPI_TRY(fapi2::getCfamRegister(i_target_chip, perv::FSXCOMP_FSXLOG_SB_CS_FSI, l_data32));
    l_data32.clearBit<perv::FSXCOMP_FSXLOG_SB_CS_START_RESTART_VECTOR0>();
    FAPI_TRY(fapi2::putCfamRegister(i_target_chip, perv::FSXCOMP_FSXLOG_SB_CS_FSI, l_data32));

    FAPI_DBG("check for VDN_PGOOD");
    FAPI_TRY(fapi2::getCfamRegister(i_target_chip, perv::FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI,
                                    l_data32));
    l_read_vdn_pgood_status = l_data32.getBit<perv::FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_VDN_PGOOD>();

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_AVSBUS_BUSNUM, i_target_chip, avsBusArr));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_AVSBUS_RAIL,  i_target_chip, avsRailArr));
    avsBus = avsBusArr[railType];
    avsRail = avsRailArr[railType];

    FAPI_ASSERT(l_read_vdn_pgood_status,
                fapi2::VDN_PGOOD_NOT_SET()
                .set_CBS_ENVSTAT_READ(l_data32)
                .set_AVS_BUS(avsBus)
                .set_AVS_RAIL(avsRail)
                .set_MASTER_CHIP(i_target_chip),
                "ERROR:VDN_PGOOD OFF, CBS_ENVSTAT BIT 2 NOT SET");

    FAPI_DBG("Reset SBE FIFO");
    FAPI_TRY(fapi2::putCfamRegister(i_target_chip, proc::TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_RESET_FSI, FIFO_RESET));

    FAPI_DBG("Resetting CFAM Boot Sequencer (CBS) to flush value and configuring Prevent SBE start option");
    FAPI_TRY(fapi2::getCfamRegister(i_target_chip, perv::FSXCOMP_FSXLOG_CBS_CS_FSI,
                                    l_data32_cbs_cs));
    l_data32_cbs_cs.clearBit<perv::FSXCOMP_FSXLOG_CBS_CS_START_BOOT_SEQUENCER>();
    l_data32_cbs_cs.clearBit<perv::FSXCOMP_FSXLOG_CBS_CS_OPTION_SKIP_SCAN0_CLOCKSTART>();
    l_data32_cbs_cs.writeBit<perv::FSXCOMP_FSXLOG_CBS_CS_OPTION_PREVENT_SBE_START>(!i_sbe_start);
    FAPI_TRY(fapi2::putCfamRegister(i_target_chip, perv::FSXCOMP_FSXLOG_CBS_CS_FSI,
                                    l_data32_cbs_cs));


    FAPI_DBG("Triggering CFAM Boot Sequencer (CBS) to start");
    l_data32_cbs_cs.setBit<perv::FSXCOMP_FSXLOG_CBS_CS_START_BOOT_SEQUENCER>();
    FAPI_TRY(fapi2::putCfamRegister(i_target_chip, perv::FSXCOMP_FSXLOG_CBS_CS_FSI,
                                    l_data32_cbs_cs));

    FAPI_DBG("Check cbs_cs_internal_state_vector");
    l_timeout = P10_CFAM_CBS_POLL_COUNT;

    //UNTIL CBS_CS.CBS_CS_INTERNAL_STATE_VECTOR == CBS_IDLE_VALUE
    while (l_timeout != 0)
    {
        FAPI_TRY(fapi2::getCfamRegister(i_target_chip, perv::FSXCOMP_FSXLOG_CBS_CS_FSI,
                                        l_data32_cbs_cs));
        uint32_t l_poll_data = 0;
        l_data32_cbs_cs.extractToRight<perv::FSXCOMP_FSXLOG_CBS_CS_INTERNAL_STATE_VECTOR,
                                       perv::FSXCOMP_FSXLOG_CBS_CS_INTERNAL_STATE_VECTOR_LEN>(l_poll_data);

        if (l_poll_data == CBS_IDLE_VALUE)
        {
            break;
        }

        fapi2::delay(P10_CBS_IDLE_HW_NS_DELAY, P10_CBS_IDLE_SIM_CYCLE_DELAY);
        --l_timeout;
    }

    FAPI_DBG("Loop Count :%d", l_timeout);

    // Finding the clock used for starting CBS.
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CP_REFCLOCK_SELECT, i_target_chip, l_cp_refclck_select));

    if((l_cp_refclck_select == fapi2::ENUM_ATTR_CP_REFCLOCK_SELECT_OSC0) ||
       (l_cp_refclck_select == fapi2::ENUM_ATTR_CP_REFCLOCK_SELECT_BOTH_OSC0_NORED) ||
       (l_cp_refclck_select == fapi2::ENUM_ATTR_CP_REFCLOCK_SELECT_BOTH_OSC0))
    {
        l_callout_clock = fapi2::ENUM_ATTR_CP_REFCLOCK_SELECT_OSC0;
    }

    FAPI_ASSERT(l_timeout > 0,
                fapi2::CBS_NOT_IN_IDLE_STATE()
                .set_CBS_CS_READ(l_data32_cbs_cs)
                .set_CBS_CS_IDLE_VALUE(CBS_IDLE_VALUE)
                .set_LOOP_COUNT(P10_CFAM_CBS_POLL_COUNT)
                .set_HW_DELAY(P10_CBS_IDLE_HW_NS_DELAY)
                .set_MASTER_CHIP(i_target_chip)
                .set_CLOCK_POS(l_callout_clock),
                "ERROR: CBS HAS NOT REACHED IDLE STATE VALUE 0x002 ");

    FAPI_INF("p10_start_cbs: Exiting ...");

fapi_try_exit:
    return fapi2::current_err;

}
