/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/lib/p9_common_poweronoff.H $ */
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
///
/// @file  p9_common_poweronoff.H
/// @brief common procedure for power on/off
///

// *HWP HWP Owner          : David Du       <daviddu@us.ibm.com>
// *HWP Backup HWP Owner   : Greg Still     <stillgs@us.ibm.com>
// *HWP FW Owner           : Sangeetha T S  <sangeet2@in.ibm.com>
// *HWP Team               : PM
// *HWP Consumed by        : SBE:SGPE:CME
// *HWP Level              : 2

#ifndef __P9_COMMON_POWERONOFF_H__
#define __P9_COMMON_POWERONOFF_H__

#include <fapi2.H>
#include <p9_quad_scom_addresses.H>
#include <p9_hcd_common.H>

namespace p9power
{
enum powerOperation_t
{
    POWER_ON      = 0x0,
    POWER_OFF     = 0xFF,
    POWER_ON_VDD  = 0x1,
    POWER_OFF_VDD = 0xFE,
    POWER_ON_VCS  = 0x2,
    POWER_OFF_VCS = 0xFD
};



// For SBE, the initial power-on times are not overly time critical so they are
// hardcoded for the delay necessary when running with the fastest nest (2.4GHz).
// When these same values are used with slower nest frequencies, the delays will
// get longer (more conservative).
//
// For istep 15, the delay settings are computed based on the setting of
// ATTR_FREQ_PB
//
// pfet_delay = (1/nest_frequency_mhz)*1000*4 (PPM clock period in ns) *
//               2^(15-pfet_delay_value).
//
// or
//
//                                                pfet_delay
// 2^(15-pfet_delay_value) =           ------------------------------
//                                     (1/nest_frequency_mhz)*1000*4
//
//                                     pfet_delay * nest_frequency_mhz
// 2^(15-pfet_delay_value  =           ------------------------------
//                                                1000*4
//
//                                    ( pfet_delay * nest_frequency_mhz)
// 15-pfet_delay_value     =      log2(  ------------------------------)
//                                    (             1000*4             )
//
//                                    ( pfet_delay * nest_frequency_mhz)
// pfet_delay_value        = 15 - log2(  ------------------------------)
//                                    (             1000*4             )
//
//            ( pfet_delay * nest_frequency_mhz)
// logexp   = (  ------------------------------)
//            (             1000*4             )
//
//          = pfet_delay * nest_frequency_mhz / (1000 * 4)
//          = pfet_delay * (nest_frequency_mhz / (1000 * 4))
//          = pfet_delay * (2400 / (1000 * 4))
//          = pfet_delay * (.6)
//
// For core delay of 250ns per step, logexp = 250 * .6 = 150
//   --> log2(150) = 8 (rounded up to next integer)
//  -- > pfet_delay_value = 15 - 8 = 7
//
// For EQ delay of 500ns per step, logexp = 500 * .6 = 300
//   --> log2(150) = 9 (rounded up to next integer)
//  -- > pfet_delay_value = 15 - 9 = 6


enum pfetDelays
{
    PFET_DELAY_POWERDOWN_EQ     = 0x1,
    PFET_DELAY_POWERDOWN_CORE   = 0x1,
#ifndef PRODUCT_DEFAULT_PFET_DELAYS
    PFET_DELAY_POWERUP_EQ       = 0x1,
    PFET_DELAY_POWERUP_CORE     = 0x1
#else
    PFET_DELAY_POWERUP_EQ       = 0x6,
    PFET_DELAY_POWERUP_CORE     = 0x7
#endif
};


} // namespace

/// @typedef p9_common_poweronoff_FP_t
/// function pointer typedef definition for HWP call support
/// @todo: consider template solution here
typedef fapi2::ReturnCode (*p9_common_poweronoff_FP_t) (
    const fapi2::Target < fapi2::TARGET_TYPE_EQ |
    fapi2::TARGET_TYPE_CORE > &,
    const p9power::powerOperation_t i_operation);

/// @brief common procedure for power on/off
///
/// @param [in] i_target    TARGET_TYPE_EQ|TARGET_TYPE_CORE target
/// @param [in] i_operation ENUM(ON,OFF)
///
/// @attr
/// @attritem ATTR_PFET_TIMING - EX target, uint32
///
/// @retval FAPI_RC_SUCCESS
#include "p9_hcd_common.H"

//------------------------------------------------------------------------------
// Constant Definitions:
//------------------------------------------------------------------------------
// Define only address offset to be compatible with both core and cache domain

const uint64_t NET_CTRL0_WOR[2] = { C_NET_CTRL0_WOR,
                                    EQ_NET_CTRL0_WOR
                                  };

const uint64_t PPM_PFCS[2]     = { C_PPM_PFCS_SCOM,
                                   EQ_PPM_PFCS_SCOM
                                 };

const uint64_t PPM_PFCS_CLR[2] = { C_PPM_PFCS_SCOM1,
                                   EQ_PPM_PFCS_SCOM1
                                 };

const uint64_t PPM_PFCS_OR[2] = { C_PPM_PFCS_SCOM2,
                                  EQ_PPM_PFCS_SCOM2
                                };

const uint64_t PPM_PFDLY[2] =   { C_PPM_PFDLY,
                                  EQ_PPM_PFDLY
                                };

const uint64_t PPM_PFSNS[2] =   { C_PPM_PFSNS,
                                  EQ_PPM_PFSNS
                                };

// With a PFET step delay of 250ns and 8 steps, the PFET controller needs ~2us to
// complete.  A 500 delay keeps the SGPE off of the PCB bus to let other traffic
// through while potentially adding .5us to the STOP11 time.  For this and the SBE
// usage of this (istep 4), this trade-off is acceptable.

enum { FSM_IDLE_POLLING_HW_NS_DELAY = 500,
       FSM_IDLE_POLLING_SIM_CYCLE_DELAY = 320000,
       PFET_STATE_LENGTH = 2,
       VXX_PG_SEL_LEN = 4
     };

enum pfetRegField { PFET_NOP = 0,
                    PFET_FORCE_VOFF = 1,
                    PFET_NOP_RESERVERD = 2,
                    PFET_FORCE_VON = 3
                  };

enum pgStateOffset { PG_STATE_IDLE_OFFSET = 0,
                     PG_STATE_INC_OFFSET = 1,
                     PG_STATE_DEC_OFFSET = 2,
                     PG_STATE_WAIT_OFFSET = 3
                   };


enum PFCS_Bits { VDD_PFET_FORCE_STATE_BIT = 0,
                 VCS_PFET_FORCE_STATE_BIT = 2,
                 VDD_PFET_VAL_OVERRIDE_BIT = 4,
                 VDD_PFET_SEL_OVERRIDE_BIT = 5,
                 VCS_PFET_VAL_OVERRIDE_BIT = 6,
                 VCS_PFET_SEL_OVERRIDE_BIT = 7,
                 VDD_PFET_REGULATION_FINGER_EN_BIT = 8,
                 VDD_PFET_REGULATION_FINGER_VALUE_BIT = 9,
                 RESERVED1_BIT = 10,
                 VDD_PFET_ENABLE_VALUE_BIT = 12,
                 VDD_PFET_SEL_VALUE_BIT = 20,
                 VCS_PFET_ENABLE_VALUE_BIT = 24,
                 VCS_PFET_SEL_VALUE_BIT = 32,
                 RESERVED2_BIT = 36,
                 VDD_PG_STATE_BIT = 42,
                 VDD_PG_SEL_BIT = 46,
                 VCS_PG_STATE_BIT = 50,
                 VCS_PG_SEL_BIT = 54,
                 RESERVED3_BIT = 58
               };


enum PFSNS_Bits { VDD_PFETS_ENABLED_SENSE_BIT = 0,
                  VDD_PFETS_DISABLED_SENSE_BIT = 1,
                  VCS_PFETS_ENABLED_SENSE_BIT = 2,
                  VCS_PFETS_DISABLED_SENSE_BIT = 3
                };

enum { POWDN_DLY_BIT = 0,
       POWUP_DLY_BIT = 4,
       TP_VDD_PFET_ENABLE_ACTUAL_BIT = 16,
       TP_VCS_PFET_ENABLE_ACTUAL_BIT = 24
     };

enum { POWDN_DLY_LENGTH = 4,
       POWUP_DLY_LENGTH = 4,
       TP_VDD_PFET_ENABLE_ACTUAL_LENGTH = 8,
       TP_VCS_PFET_ENABLE_ACTUAL_LENGTH = 8
     };

// i_operation defines


//------------------------------------------------------------------------------
// Procedure:
//------------------------------------------------------------------------------
template <fapi2::TargetType K>
fapi2::ReturnCode
p9_common_poweronoff(
    const fapi2::Target<K>& i_target,
    const p9power::powerOperation_t i_operation)
{
    uint32_t l_loopsPerMs;

    FAPI_INF(">>p9_common_poweronoff: %d",  i_operation);
    uint32_t l_type = 0;  // Assumes core

    fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP> l_parentProc =
        i_target.template getParent<fapi2::TARGET_TYPE_PROC_CHIP>();

    if((i_target.getType() & fapi2::TARGET_TYPE_EQ))
    {
        l_type = 1;
    }

    uint8_t chipletPos = 0;
    FAPI_ATTR_GET( fapi2::ATTR_CHIP_UNIT_POS, i_target, chipletPos );

    fapi2::buffer<uint64_t> l_data;
    fapi2::buffer<uint64_t> l_temp;  // extractToRight seems the require space to write into.

    ///////////////////////////////////////////////////////////////////////////
    // lambda functions for poweronoff procedure
    ///////////////////////////////////////////////////////////////////////////
    auto pollVddFSMIdle = [&] (PFSNS_Bits pfsnsBit)
    {
        //   Poll for PFETSENSE_REG[VDD_PFETS_ENABLED_SENSE_BIT] or
        //      [VDD_PFETS_DISABLED_SENSE_BIT] for PFET change done (FSM idle)
        //      – Timeout value = 1ms
        FAPI_DBG("Polling for power gate sequencer state: FSM idle");
        l_loopsPerMs = 1E6 / FSM_IDLE_POLLING_HW_NS_DELAY;

        do
        {
            fapi2::delay(FSM_IDLE_POLLING_HW_NS_DELAY,
                         FSM_IDLE_POLLING_SIM_CYCLE_DELAY);

            FAPI_TRY(fapi2::getScom(i_target, PPM_PFSNS[l_type], l_data),
                     "getScom failed for address PPM_PFSNS"); // poll
        }
        while ((l_data.getBit(pfsnsBit, 1) == 0) && (--l_loopsPerMs != 0));

        if( l_type )
        {

            FAPI_ASSERT((l_loopsPerMs != 0),
                        fapi2::VDD_QUAD_PFET_TIMEOUT()
                        .set_PPM_PFSNS_REG_VALUE( l_data )
                        .set_PROC_CHIP( l_parentProc )
                        .set_EQ_NUMBER_IN_ERROR( chipletPos ),
                        "VDD FSM Idle Timeout");
        }
        else
        {
            FAPI_ASSERT((l_loopsPerMs != 0),
                        fapi2::VDD_CORE_PFET_TIMEOUT()
                        .set_PPM_PFSNS_REG_VALUE( l_data )
                        .set_PROC_CHIP( l_parentProc )
                        .set_CORE_NUMBER_IN_ERROR( chipletPos ),
                        "VDD FSM Idle Timeout");
        }

    fapi_try_exit:
        return fapi2::current_err;
    };

    auto pollVcsFSMIdle = [&] (PFSNS_Bits pfsnsBit)
    {
        //   Poll for PFETSENSE_REG[VCS_PFETS_ENABLED_SENSE_BIT] or
        //      [VCS_PFETS_DISABLED_SENSE_BIT] for PFET change done (FSM idle)
        //      – Timeout value = 1ms
        FAPI_DBG("Polling for power gate sequencer state: FSM idle");
        l_loopsPerMs = 1E6 / FSM_IDLE_POLLING_HW_NS_DELAY;

        do
        {
            fapi2::delay(FSM_IDLE_POLLING_HW_NS_DELAY,
                         FSM_IDLE_POLLING_SIM_CYCLE_DELAY);

            FAPI_TRY(fapi2::getScom(i_target, PPM_PFSNS[l_type], l_data),
                     "getScom failed for address PPM_PFSNS");  // poll
        }
        while ((l_data.getBit(pfsnsBit, 1) == 0) && (--l_loopsPerMs != 0));

        if( l_type )
        {

            FAPI_ASSERT((l_loopsPerMs != 0),
                        fapi2::VCS_QUAD_PFET_TIMEOUT()
                        .set_PPM_PFSNS_REG_VALUE( l_data )
                        .set_PROC_CHIP( l_parentProc )
                        .set_EQ_NUMBER_IN_ERROR( chipletPos ),
                        "VCS FSM Idle Timeout" );
        }
        else
        {
            FAPI_ASSERT((l_loopsPerMs != 0),
                        fapi2::VCS_CORE_PFET_TIMEOUT()
                        .set_PPM_PFSNS_REG_VALUE( l_data )
                        .set_PROC_CHIP( l_parentProc )
                        .set_CORE_NUMBER_IN_ERROR( chipletPos ),
                        "VCS FSM Idle Timeout" );
        }

    fapi_try_exit:
        return fapi2::current_err;

    };


    auto powerOnVdd = [&] ()
    {
        // Command the cache PFET controller to power-on
        //   Write PFETCNTLSTAT_REG:
        //     vdd_pfet_force_state = 11 (Force Von)
        //     vdd_pfet_val_override = 0 (Override disabled)
        //     vdd_pfet_sel_override = 0 (Override disabled)
        //     vdd_pfet_enable_regulation_finger = 0
        //         (Regulation finger controlled by FSM)
        FAPI_DBG("Clear VDD PFET stage select and value override bits");
        l_data.flush<0>().
        setBit<VDD_PFET_VAL_OVERRIDE_BIT>().
        setBit<VDD_PFET_SEL_OVERRIDE_BIT>().
        setBit<VDD_PFET_REGULATION_FINGER_EN_BIT>();
        FAPI_TRY(fapi2::putScom(i_target, PPM_PFCS_CLR[l_type], l_data),
                 "putScom failed for address PPM_PFCS");

        FAPI_DBG("Force VDD on");
        l_data.flush<0>().insertFromRight
        <VDD_PFET_FORCE_STATE_BIT, PFET_STATE_LENGTH>(PFET_FORCE_VON);
        FAPI_TRY(fapi2::putScom(i_target, PPM_PFCS_OR[l_type], l_data),
                 "putScom failed for address PPM_PFCS_OR");

        // Check for valid power on completion
        //     Polled Timeout:  100us
        FAPI_TRY(pollVddFSMIdle(VDD_PFETS_ENABLED_SENSE_BIT));

        //    Write PFETCNTLSTAT_REG_WCLEAR
        //      vdd_pfet_force_state = 00 (No Operation);
        //      all fields set to 1 for WAND
        //    Use PPM_PFCS_CLR,
        //      vdd_pfet_force_state = 0b11
        FAPI_DBG("vdd_pfet_force_state = 00, or Idle");
        l_data.flush<0>().insertFromRight
        <VDD_PFET_FORCE_STATE_BIT, PFET_STATE_LENGTH>(~PFET_NOP);
        FAPI_TRY(fapi2::putScom(i_target, PPM_PFCS_CLR[l_type], l_data),
                 "putScom failed for address PPM_PFCS_CLR");

    fapi_try_exit:
        return fapi2::current_err;

    };

    auto powerOnVcs = [&] ()
    {
        // Command the PFET controller to power-on
        //    Write PFETCNTLSTAT_REG_OR with values defined below
        //      vcs_pfet_force_state = 11 (Force Von)
        //    Write to PFETCNTLSTAT_REG_CLR
        //      vcs_pfet_val_override = 0 (Override disabled)
        //      vcs_pfet_sel_override = 0 (Override disabled)
        //      Note there is no vcs_pfet_enable_regulation_finger
        FAPI_DBG("Clear VCS PFET stage select and value override bits");
        l_data.flush<0>().
        setBit<VCS_PFET_VAL_OVERRIDE_BIT>().
        setBit<VCS_PFET_SEL_OVERRIDE_BIT>();
        FAPI_TRY(fapi2::putScom(i_target, PPM_PFCS_CLR[l_type], l_data),
                 "putScom failed for address PPM_PFCS_CLR");

        FAPI_DBG("Force VCS on");
        l_data.flush<0>().insertFromRight
        <VCS_PFET_FORCE_STATE_BIT, PFET_STATE_LENGTH>(PFET_FORCE_VON);
        FAPI_TRY(fapi2::putScom(i_target, PPM_PFCS_OR[l_type], l_data),
                 "putScom failed for address PPM_PFCS_OR");

        // Check for valid power on completion
        //     Polled Timeout:  100us
        FAPI_TRY(pollVcsFSMIdle(VCS_PFETS_ENABLED_SENSE_BIT));

        //   Write PFETCNTLSTAT_REG_WCLEAR
        //      vcs_pfet_force_state = 00 (No Operation);
        //      all fields set to 1 for WAND
        //   Use PPM_PFCS_CLR,  vdd_pfet_force_state = ~(0b00)
        FAPI_DBG("vcs_pfet_force_state = 00, or Idle");
        l_data.flush<0>().insertFromRight
        <VCS_PFET_FORCE_STATE_BIT, PFET_STATE_LENGTH>(~PFET_NOP);
        FAPI_TRY(fapi2::putScom(i_target, PPM_PFCS_CLR[l_type], l_data),
                 "putScom failed for address PPM_PFCS_CLR");

    fapi_try_exit:
        return fapi2::current_err;
    };

    auto powerOffVdd = [&] ()
    {
        // Command the PFET controller to power-off
        //   Write PFETCNTLSTAT_REG:
        //     vdd_pfet_force_state = 01 (Force Voff)
        //     vdd_pfet_val_override = 0 (Override disabled)
        //     vdd_pfet_sel_override = 0 (Override disabled)
        //     vdd_pfet_enable_regulation_finger = 0
        //                   (Regulation finger controlled by FSM)
        FAPI_DBG("Clear VDD PFET stage select and value override bits");
        l_data.flush<0>().
        setBit<VDD_PFET_VAL_OVERRIDE_BIT>().
        setBit<VDD_PFET_SEL_OVERRIDE_BIT>().
        setBit<VDD_PFET_REGULATION_FINGER_EN_BIT>();
        FAPI_TRY(fapi2::putScom(i_target, PPM_PFCS_CLR[l_type], l_data),
                 "putScom failed for address PPM_PFCS");

        FAPI_DBG("Force VDD off");
        l_data.flush<0>().insertFromRight
        <VDD_PFET_FORCE_STATE_BIT, PFET_STATE_LENGTH>(PFET_FORCE_VOFF);
        FAPI_TRY(fapi2::putScom(i_target, PPM_PFCS_OR[l_type], l_data),
                 "putScom failed for address PPM_PFCS");

        // Check for valid power off completion
        //     Polled Timeout:  100us
        FAPI_TRY(pollVddFSMIdle(VDD_PFETS_DISABLED_SENSE_BIT));

        //    Write PFETCNTLSTAT_REG_WCLEAR
        //      vdd_pfet_force_state = 00 (No Operation);
        //      all fields set to 1 for WAND
        //    Use PPM_PFCS_CLR,  vdd_pfet_force_state = 0b11
        FAPI_DBG("vdd_pfet_force_state = 00, or Idle");
        l_data.flush<0>().insertFromRight
        <VDD_PFET_FORCE_STATE_BIT, PFET_STATE_LENGTH>(~PFET_NOP);
        FAPI_TRY(fapi2::putScom(i_target, PPM_PFCS_CLR[l_type], l_data),
                 "putScom failed for address PPM_PFCS_CLR");

    fapi_try_exit:
        return fapi2::current_err;
    };

    auto powerOffVcs = [&] ()
    {
        // Command the PFET controller to power-off
        //    Write PFETCNTLSTAT_REG_OR with values defined below
        //      vcs_pfet_force_state = 11 (Force Voff)
        //      vcs_pfet_val_override = 0 (Override disabled)
        //      vcs_pfet_sel_override = 0 (Override disabled)
        //      Note there is no vcs_pfet_enable_regulation_finger
        FAPI_DBG("Clear VCS PFET stage select and value override bits");
        l_data.flush<0>().
        setBit<VCS_PFET_VAL_OVERRIDE_BIT>().
        setBit<VCS_PFET_SEL_OVERRIDE_BIT>();
        FAPI_TRY(fapi2::putScom(i_target, PPM_PFCS_CLR[l_type], l_data),
                 "putScom failed for address PPM_PFCS_CLR");

        FAPI_DBG("Force VCS off");
        l_data.flush<0>().
        insertFromRight
        <VCS_PFET_FORCE_STATE_BIT, PFET_STATE_LENGTH>(PFET_FORCE_VOFF);
        FAPI_TRY(fapi2::putScom(i_target, PPM_PFCS_OR[l_type], l_data),
                 "putScom failed for address PPM_PFCS_OR");

        // Check for valid power off completion
        //     Polled Timeout:  100us
        FAPI_TRY(pollVcsFSMIdle(VCS_PFETS_DISABLED_SENSE_BIT));

        //   Write PFETCNTLSTAT_REG_WCLEAR
        //      vcs_pfet_force_state = 00 (No Operation);
        //          all fields set to 1 for WAND
        //   Use PPM_PFCS_CLR,  vcs_pfet_force_state = ~(0b00)
        FAPI_DBG("vcs_pfet_force_state = 00, or Idle");
        l_data.flush<0>().insertFromRight
        <VCS_PFET_FORCE_STATE_BIT, PFET_STATE_LENGTH>(~PFET_NOP);
        FAPI_TRY(fapi2::putScom(i_target, PPM_PFCS_CLR[l_type], l_data),
                 "putScom failed for address PPM_PFCS_CLR");

    fapi_try_exit:
        return fapi2::current_err;
    };

    ///////////////////////////////////////////////////////////////////////////
    // Initialization code
    ///////////////////////////////////////////////////////////////////////////

    fapi2::buffer<uint64_t> l_data64;
    FAPI_DBG("Assert PCB fence via NET_CTRL0[25]");
    FAPI_TRY(putScom(i_target, NET_CTRL0_WOR[l_type], MASK_SET(25)));

    FAPI_DBG("Assert chiplet electrical fence via NET_CTRL0[26]");
    FAPI_TRY(putScom(i_target, NET_CTRL0_WOR[l_type], MASK_SET(26)));

    FAPI_DBG("Assert vital thold via NET_CTRL0[16]");
    FAPI_TRY(putScom(i_target, NET_CTRL0_WOR[l_type], MASK_SET(16)));

    if (l_type == 1)
    {
        // upon power off cache, dpll is about to be unlocked
        // to prevent pcb fir fires, need to mask the bit for the time being
        // the error will be cleared and unmasked when dpll is locked again
        FAPI_DBG("Mask DPLL unlock error in FIR via SLAVE_CONFIG[12]");
        FAPI_TRY(getScom(i_target, EQ_SLAVE_CONFIG_REG, l_data64));
        l_data64.setBit<12>();
        FAPI_TRY(putScom(i_target, EQ_SLAVE_CONFIG_REG, l_data64));//
    }

    ///////////////////////////////////////////////////////////////////////////
    // Procedure code
    ///////////////////////////////////////////////////////////////////////////
    switch(i_operation)
    {
        case p9power::POWER_ON:
        case p9power::POWER_ON_VDD:
        case p9power::POWER_ON_VCS:
            {
                // 4.3.8.1 Power-on via Hardware FSM

                // VDD first, VCS second

                // 1)  Read  PFETCNTLSTAT_REG:  check for bits 0:3 being 0b0000
                l_data.flush<0>().
                setBit<VCS_PFET_VAL_OVERRIDE_BIT>().
                setBit<VCS_PFET_SEL_OVERRIDE_BIT>();
                FAPI_TRY(fapi2::putScom(i_target, PPM_PFCS_CLR[l_type], l_data),
                         "putScom failed for address PPM_PFCS_CLR");

                FAPI_DBG("Make sure that we are not forcing PFET for VCS or VDD off");
                FAPI_TRY(fapi2::getScom(i_target, PPM_PFCS[l_type], l_data),
                         "getScom failed for address PPM_PFCS");
                l_data.extractToRight
                <VDD_PFET_FORCE_STATE_BIT, 2 * PFET_STATE_LENGTH>
                (l_temp);
                FAPI_ASSERT((l_temp == 0),
                            fapi2::PFET_FORCE_STATE_ERROR()
                            .set_CHIPLET( i_target )
                            .set_OP_TYPE( i_operation )
                            .set_PFCS_REG_ADDRESS( PPM_PFCS[l_type] )
                            .set_PFCS_REG_VALUE( l_data ),
                            "PFET_FORCE_STATE not 0");

                // 2) Set bits to program HW to enable VDD PFET, and
                // 3) Poll state bit until Pfet sequence is complete
                if (i_operation != p9power::POWER_ON_VCS)
                {
                    FAPI_TRY(powerOnVdd());
                }

                // 4) Set bits to program HW to enable VCS PFET, and
                // 5) Poll state bit until Pfet sequence is complete

                // Note: if (i_target.getType() & fapi2::TARGET_TYPE_EQ) doesn't work.
                //   Created a  POWER_*_VDD label to delineate Vcs and Vdd
                if (i_operation != p9power::POWER_ON_VDD)
                {
                    FAPI_TRY(powerOnVcs());
                }

            }
            break;

        case p9power::POWER_OFF:
        case p9power::POWER_OFF_VDD:
        case p9power::POWER_OFF_VCS:
            {
                // 4.3.8.2 Power-off via Hardware FSM
                // 1)  Read  PFETCNTLSTAT_REG:  check for bits 0:3 being 0b0000
                FAPI_DBG("Make sure that we are not forcing PFET for VCS or VDD off");
                FAPI_TRY(fapi2::getScom(i_target, PPM_PFCS[l_type], l_data),
                         "getScom failed for address PPM_PFCS");

                l_data.extractToRight
                <VDD_PFET_FORCE_STATE_BIT, 2 * PFET_STATE_LENGTH>
                (l_temp);

                FAPI_ASSERT((l_temp == 0),
                            fapi2::PFET_FORCE_STATE_ERROR()
                            .set_CHIPLET( i_target )
                            .set_OP_TYPE( i_operation )
                            .set_PFCS_REG_ADDRESS( PPM_PFCS[l_type] )
                            .set_PFCS_REG_VALUE( l_data ),
                            "PFET_FORCE_STATE not 0");

                // 2) Set bits to program HW to turn off VCS PFET, and
                // 3) Poll state bit until Pfet sequence is complete

                // Note: if (i_target.getType() & fapi2::TARGET_TYPE_EQ) doesn't work.
                //   Created a  POWER_*_VDD label to delineate Vcs and Vdd
                if (i_operation != p9power::POWER_OFF_VDD)
                {
                    FAPI_TRY(powerOffVcs());
                }

                // 4) Set bits to program HW to turn off VDD PFET, and
                // 5) Poll state bit until Pfet sequence is complete
                if (i_operation != p9power::POWER_OFF_VCS)
                {
                    FAPI_TRY(powerOffVdd());
                }
            }
            break;
    }

    FAPI_INF("<<p9_common_poweronoff");
fapi_try_exit:
    return fapi2::current_err;
} // Procedure

#endif  // __P9_COMMON_POWERONOFF_H__
