//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/include/usr/isteps/istep13list.H $
//
//  IBM CONFIDENTIAL
//
//  COPYRIGHT International Business Machines Corp. 2012
//
//  p1
//
//  Object Code Only (OCO) source materials
//  Licensed Internal Code Source Materials
//  IBM HostBoot Licensed Internal Code
//
//  The source code for this program is not published or other-
//  wise divested of its trade secrets, irrespective of what has
//  been deposited with the U.S. Copyright Office.
//
//  Origin: 30
//
//  IBM_PROLOG_END

#ifndef __ISTEPS_ISTEP13LIST_H
#define __ISTEPS_ISTEP13LIST_H

/**
 * @file    istep13list.H
 *
 *  IStep 13    Step 13 DRAM Training
 *  IPL FLow Doc        v0.99 (02/10/12)
 *
 *  13.1	  host_disable_vddr
 *  	: Disable VDDR on CanContinue loops
 *  13.2	  mc_pll_setup
 *  	: Setup PLL for MBAs
 *  13.3	  mba_startclocks
 *  	: Start clocks on MBAs
 *  13.4	  host_enable_vddr
 *  	: Enable the VDDR3 Voltage Rail
 *  13.5	  mss_initf
 *  	: Perform scom inits to MC and PHY
 *  13.6	  mss_ddr_phy_reset
 *  	: Soft reset of DDR PHY macros
 *  13.7	  mss_draminit
 *  	: Dram initialize
 *  13.8	  mss_restore_dram_repair
 *  	: Restore Dram repairs
 *  13.9	  mss_draminit_training
 *  	: Dram training
 *  13.10	  mss_draminit_trainadv
 *  	: Advanced dram training
 *  13.11	  mss_draminit_mc
 *  	: Hand off control to MC
 *
 *  *****************************************************************
 *  THIS FILE WAS GENERATED ON 2012-02-27:2142
 *  *****************************************************************
 *
 *  Please see the note in initsvcstructs.H for description of
 *      the ISTEPNAME macro.
 *
 */

#include    <initservice/initsvcstructs.H>
#include    <initservice/initsvcreasoncodes.H>

//  include prototypes file
#include    "../../../usr/hwpf/hwp/dram_training/dram_training.H"

namespace   INITSERVICE
{
const   TaskInfo    g_istep13[]  =   {

        {
                "",         // dummy, index 0
                NULL,
                {
                        NONE,
                        EXT_IMAGE,
                }
        },

        {
                ISTEPNAME(13,01,"host_disable_vddr"),
                DRAM_TRAINING::call_host_disable_vddr,
                {
                        START_FN,
                        EXT_IMAGE,
                }
        },
        {
                ISTEPNAME(13,02,"mc_pll_setup"),
                DRAM_TRAINING::call_mc_pll_setup,
                {
                        START_FN,
                        EXT_IMAGE,
                }
        },
        {
                ISTEPNAME(13,03,"mba_startclocks"),
                DRAM_TRAINING::call_mba_startclocks,
                {
                        START_FN,
                        EXT_IMAGE,
                }
        },
        {
                ISTEPNAME(13,04,"host_enable_vddr"),
                DRAM_TRAINING::call_host_enable_vddr,
                {
                        START_FN,
                        EXT_IMAGE,
                }
        },
        {
                ISTEPNAME(13,05,"mss_initf"),
                DRAM_TRAINING::call_mss_initf,
                {
                        START_FN,
                        EXT_IMAGE,
                }
        },
        {
                ISTEPNAME(13,06,"mss_ddr_phy_reset"),
                DRAM_TRAINING::call_mss_ddr_phy_reset,
                {
                        START_FN,
                        EXT_IMAGE,
                }
        },
        {
                ISTEPNAME(13,07,"mss_draminit"),
                DRAM_TRAINING::call_mss_draminit,
                {
                        START_FN,
                        EXT_IMAGE,
                }
        },
        {
                ISTEPNAME(13,08,"mss_restore_dram_repair"),
                DRAM_TRAINING::call_mss_restore_dram_repair,
                {
                        START_FN,
                        EXT_IMAGE,
                }
        },
        {
                ISTEPNAME(13,09,"mss_draminit_training"),
                DRAM_TRAINING::call_mss_draminit_training,
                {
                        START_FN,
                        EXT_IMAGE,
                }
        },
        {
                ISTEPNAME(13,10,"mss_draminit_trainadv"),
                DRAM_TRAINING::call_mss_draminit_trainadv,
                {
                        START_FN,
                        EXT_IMAGE,
                }
        },
        {
                ISTEPNAME(13,11,"mss_draminit_mc"),
                DRAM_TRAINING::call_mss_draminit_mc,
                {
                        START_FN,
                        EXT_IMAGE,
                }
        },


        //  END OF LIST!
};

// make a struct from the above with the number of items included
const   ExtTaskInfo g_istep13TaskList    =   {
        &(g_istep13[0]),
        ( sizeof(g_istep13)/sizeof(TaskInfo) ),
        NULL    //  later, depModules struct
};

};  // end namespace

#endif
