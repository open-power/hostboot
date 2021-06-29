/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/corecache/p10_hcd_corecache_power_control.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2021                        */
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
/// @file  p10_hcd_corecache_power_control.C
/// @brief
///

// *HWP HWP Owner          : David Du               <daviddu@us.ibm.com>
// *HWP Backup HWP Owner   : Greg Still             <stillgs@us.ibm.com>
// *HWP FW Owner           : Prasad Brahmasamurdra  <prasadbgr@in.ibm.com>
// *HWP Team               : PM
// *HWP Consumed by        : SBE:QME
// *HWP Level              : 2


//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------

#include "p10_hcd_corecache_power_control.H"
#include "p10_hcd_common.H"

#ifdef __PPE_QME
    #include "p10_ppe_c.H"
    using namespace scomt::ppe_c;
#else
    #include "p10_scom_c.H"
    using namespace scomt::c;
#endif

//------------------------------------------------------------------------------
// Constant Definitions
//------------------------------------------------------------------------------

enum P10_HCD_CORECACHE_POWER_CONTROL_CONSTANTS
{
    HCD_CORECACHE_POW_CTRL_POLL_TIMEOUT_HW_NS   = 10000000,// 10^5ns = 100us timeout
    HCD_CORECACHE_POW_CTRL_POLL_DELAY_HW_NS     = 500,     // 500ns poll loop delay
    HCD_CORECACHE_POW_CTRL_POLL_DELAY_SIM_CYCLE = 32000,   // 32k sim cycle delay
};

const uint32_t HCD_PFET_OVERRIDES[2] =
{
    BITS32(4, 2),                 //VDD.val/sel
    BITS32(6, 2)                  //VCS.val/sel
};

const uint32_t HCD_PFET_SEQ_STATES[2][2] =
{
    { BIT32(1),    BIT32(3)    },  //VDD_OFF, VCS_OFF
    { BITS32(0, 2), BITS32(2, 2) } //VDD_ON,  VCS_ON
};

const uint32_t HCD_PFET_SENSE_BITS[2][2] =
{
    { BIT32(1),    BIT32(3)    },  //VDD_OFF, VCS_OFF
    { BIT32(0),    BIT32(2)    }   //VDD_ON,  VCS_ON
};

const uint32_t HCD_PFET_FINGER0_SENSE_BITS[3][2] =
{
    { BIT32(4),    BIT32(5)    },  //CL2 VDD VCS
    { BIT32(4),    BIT32(5)    },  //L3 VDD VCS
    { BIT32(2)                 }   //MMA VDD

};

const uint32_t HCD_PFET_ACTUAL_MASKS[2] =
{
    BITS32(16, 8), BITS32(24, 8)   //VDD, VCS
};

const uint32_t HCD_CPMS_PFETCNTL[3] =
{
    CPMS_CL2_PFETCNTL,
    CPMS_L3_PFETCNTL,
    CPMS_MMA_PFETCNTL
};

const uint32_t HCD_CPMS_PFETCNTL_CLR[3] =
{
    CPMS_CL2_PFETCNTL_WO_CLEAR,
    CPMS_L3_PFETCNTL_WO_CLEAR,
    CPMS_MMA_PFETCNTL_WO_CLEAR
};

const uint32_t HCD_CPMS_PFETCNTL_OR[3] =
{
    CPMS_CL2_PFETCNTL_WO_OR,
    CPMS_L3_PFETCNTL_WO_OR,
    CPMS_MMA_PFETCNTL_WO_OR
};

const uint32_t HCD_CPMS_PFETSTAT[3] =
{
    CPMS_CL2_PFETSTAT,
    CPMS_L3_PFETSTAT,
    CPMS_MMA_PFETSTAT
};

//------------------------------------------------------------------------------
// Procedure: p10_hcd_corecache_power_control
//------------------------------------------------------------------------------

fapi2::ReturnCode
p10_hcd_corecache_power_control(
    const fapi2::Target < fapi2::TARGET_TYPE_CORE | fapi2::TARGET_TYPE_MULTICAST, fapi2::MULTICAST_AND > & i_target,
    uint32_t i_command)
{
    fapi2::Target < fapi2::TARGET_TYPE_CORE | fapi2::TARGET_TYPE_MULTICAST > l_mc_or = i_target;//default OR
    fapi2::buffer<buffer_t> l_mmioData        = 0;
    fapi2::buffer<uint64_t> l_scomData        = 0;
    uint32_t                l_pfet_seq_states = 0;
    uint32_t                l_isL3            = (i_command & HCD_PFET_MMA_MASK) >> 1;
    uint32_t                l_isON            = (i_command & HCD_PFET_ON_MASK);
    uint32_t                l_isVCS           = l_isON;
    uint32_t                l_timeout         = 0;
    uint32_t                l_pfet_stat       = 0;
    uint32_t                l_expected_mask   = 0;
#ifdef USE_RUNN
    fapi2::Target < fapi2::TARGET_TYPE_SYSTEM > l_sys;
    fapi2::ATTR_RUNN_MODE_Type                  l_attr_runn_mode;
    FAPI_TRY( FAPI_ATTR_GET( fapi2::ATTR_RUNN_MODE, l_sys, l_attr_runn_mode ) );
#endif

    if (l_isL3 != 2) // if not MMA then figure out if L3 or CL2
    {
        l_isL3 = (i_command & HCD_PFET_L3_MASK)  >> 1;
    }
    else
    {
        l_isVCS = 1; // if MMA only perform VDD, see common bit flip below
    }

    FAPI_INF(">>p10_hcd_corecache_power_control[%x](b1x:L3,bx1:ON)", i_command);

    do
    {
        // l_isVCS is initialized to be same as l_isON value
        // then it is fliped between VDD and VCS in every processing loop
        // The goal is to only process two iterations of loops
        // VDD then VCS or VCS then VDD depends on the ON/OFF operation
        //
        // Here is how this logic works
        //           ON=1   OFF=0  while(On^Vcs)
        // 1st flip: VDD=0  VCS=1  True  -> next loop
        // 2nd flip: VCS=1  VDD=0  False -> terminate
        l_isVCS = l_isVCS ^ 1;

        FAPI_DBG("Make sure that we are not forcing PFET while the state isnt idle");
        FAPI_TRY( HCD_GETMMIO_S(l_mc_or, HCD_CPMS_PFETCNTL[l_isL3], l_scomData ) ); // use Multicast_OR to check 0s

        SCOM_EXTRACT(0, 4, l_pfet_seq_states);
        HCD_ASSERT4((l_pfet_seq_states == 0),
                    CORECACHE_PFET_SEQ_STATE_ERROR,
                    set_POW_COMMAND, i_command,
                    set_PFET_SEQ_STATES, l_pfet_seq_states,
                    set_MC_CORE_TARGET, i_target,
                    set_CORE_SELECT, i_target.getCoreSelect(),
                    "PFET_SEQ_STATE not 0");

        FAPI_DBG("Clear L3/CL2[%x] PFET stage select and value override bits via PFETCNTL[4,5/6,7]", l_isL3);
        FAPI_TRY( HCD_PUTMMIO_S( i_target, HCD_CPMS_PFETCNTL_CLR[l_isL3], SCOM_LOAD32H( HCD_PFET_OVERRIDES[l_isVCS] ) ) );

        FAPI_DBG("Turn L3/CL2[%x] VCS/VDD[%x] ON/OFF[%x]", l_isL3, l_isVCS, l_isON);
        FAPI_TRY( HCD_PUTMMIO_S( i_target, HCD_CPMS_PFETCNTL_OR[l_isL3],
                                 SCOM_LOAD32H( HCD_PFET_SEQ_STATES[l_isON][l_isVCS] ) ) );

        FAPI_DBG("Poll for PFET senses to be proper in PFETSTAT[]");
        l_timeout = HCD_CORECACHE_POW_CTRL_POLL_TIMEOUT_HW_NS /
                    HCD_CORECACHE_POW_CTRL_POLL_DELAY_HW_NS;

        do
        {
            //use multicastAND to check 1
            if( l_isON )
            {
                FAPI_TRY( HCD_GETMMIO_S( i_target, HCD_CPMS_PFETSTAT[l_isL3], l_scomData ) );
            }
            //use multicastOR to check 0
            else
            {
                FAPI_TRY( HCD_GETMMIO_S( l_mc_or, HCD_CPMS_PFETSTAT[l_isL3], l_scomData ) );
            }

            SCOM_GET32H(l_pfet_stat);


#if defined(POWER10_DD_LEVEL) && POWER10_DD_LEVEL != 10

            l_expected_mask = l_isON ? HCD_PFET_FINGER0_SENSE_BITS[l_isL3][l_isVCS] : 0;

            FAPI_DBG("PFETSTAT %x finger0_sense_mask %x", l_pfet_stat, HCD_PFET_FINGER0_SENSE_BITS[l_isL3][l_isVCS]);

            if(
#ifdef USE_RUNN
                ( !l_attr_runn_mode ) &&
#endif
                ( ( l_pfet_stat & HCD_PFET_FINGER0_SENSE_BITS[l_isL3][l_isVCS] ) == l_expected_mask ) )
            {
                break;
            }

#else

            l_expected_mask = l_isON ? HCD_PFET_ACTUAL_MASKS[l_isVCS] : 0;

            FAPI_DBG("PFETSTAT %x actual_mask %x", l_pfet_stat, HCD_PFET_ACTUAL_MASKS[l_isVCS]);

            if(
#ifdef USE_RUNN
                ( !l_attr_runn_mode ) &&
#endif
                ( ( l_pfet_stat & HCD_PFET_ACTUAL_MASKS[l_isVCS] ) == l_expected_mask ) )
            {
                // Introduce 100ns delay before doing next scom
                fapi2::delay(100, 10000);
                break;
            }

#endif

            // Debug read
            //FAPI_TRY( HCD_GETMMIO_S( i_target, HCD_CPMS_PFETCNTL[l_isL3], l_scomData ) );

            fapi2::delay(HCD_CORECACHE_POW_CTRL_POLL_DELAY_HW_NS,
                         HCD_CORECACHE_POW_CTRL_POLL_DELAY_SIM_CYCLE);
        }
        while( (--l_timeout) != 0 );

#if defined(POWER10_DD_LEVEL) && POWER10_DD_LEVEL == 10

        if( l_isVCS == 0 || l_isL3 == 1 )
        {
#endif

            HCD_ASSERT4( (
#ifdef USE_RUNN
                             l_attr_runn_mode ?
#if defined(POWER10_DD_LEVEL) && POWER10_DD_LEVEL != 10
                             ( ( l_pfet_stat & HCD_PFET_FINGER0_SENSE_BITS[l_isL3][l_isVCS] ) == l_expected_mask ) :
#else
                             ( ( l_pfet_stat & HCD_PFET_ACTUAL_MASKS[l_isVCS] ) == l_expected_mask ) :
#endif
#endif
                             (l_timeout != 0) ),
                         CORECACHE_POW_CTRL_TIMEOUT,
                         set_POW_COMMAND, i_command,
                         set_PFET_SENSES, l_pfet_stat,
                         set_MC_CORE_TARGET, i_target,
                         set_CORE_SELECT, i_target.getCoreSelect(),
                         "ERROR: Core/Cache PFET Control Timeout");

#if defined(POWER10_DD_LEVEL) && POWER10_DD_LEVEL == 10
        }

#endif

        FAPI_DBG("Reset PFET Sequencer State via PFETCNTL[0,1/2,3]");
        FAPI_TRY( HCD_PUTMMIO_S( i_target, HCD_CPMS_PFETCNTL_CLR[l_isL3], SCOM_LOAD32H( HCD_PFET_SEQ_STATES[1][l_isVCS] ) ) );

        // Debug read
        //FAPI_DBG("Check PFET Sequencer State via PFETCNTL[0,1/2,3]");
        //FAPI_TRY( HCD_GETMMIO_S( i_target, HCD_CPMS_PFETCNTL[l_isL3], l_scomData ) );

        //SCOM_EXTRACT(0, 4, l_pfet_seq_states);
        //FAPI_DBG("Current PFET Sequencer State is %x, clear value is %x", l_pfet_seq_states, HCD_PFET_SEQ_STATES[1][l_isVCS]);

        if (l_isL3 == 2) // if MMA only perform VDD
        {
            break;
        }
    }
    while( l_isON ^ l_isVCS );

fapi_try_exit:

    FAPI_INF("<<p10_hcd_corecache_power_control");

    return fapi2::current_err;

}
