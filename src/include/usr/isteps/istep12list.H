//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/include/usr/isteps/istep12list.H $
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

#ifndef __ISTEPS_ISTEP12LIST_H
#define __ISTEPS_ISTEP12LIST_H

/**
 * @file    istep12list.H
 *
 *  IStep 12    Step 12 MC Init
 *  IPL FLow Doc        v0.99 (02/10/12)
 *
 *  12.1	  host_collect_dimm_spd
 *  	: Collect Master dimm SPD
 *  12.2	  mss_volt
 *  	: Calc dimm voltage
 *  12.3	  mss_freq
 *  	: Calc dimm frequency
 *  12.4	  mss_eff_config
 *  	: Determine effective config
 *
 *  *****************************************************************
 *  THIS FILE WAS GENERATED ON 2012-03-01:1032
 *  *****************************************************************
 *
 *  Please see the note in initsvcstructs.H for description of
 *      the ISTEPNAME macro.
 *
 */

#include    <initservice/initsvcstructs.H>
#include    <initservice/initsvcreasoncodes.H>

//  include prototypes file
#include    "../../../usr/hwpf/hwp/mc_init/mc_init.H"

namespace   INITSERVICE
{
    const   TaskInfo    g_istep12[]  =   {
        // NOTE:  IStep indexes start with 0

        {
                ISTEPNAME(12,0,"host_collect_dimm_spd"),
                MC_INIT::call_host_collect_dimm_spd,
                {
                        START_FN,
                        EXT_IMAGE,
                }
        },      


        {
                ISTEPNAME(12,1,"mss_volt"),
                MC_INIT::call_mss_volt,
                {
                        START_FN,
                        EXT_IMAGE,
                }
        },      


        {
                ISTEPNAME(12,2,"mss_freq"),
                MC_INIT::call_mss_freq,
                {
                        START_FN,
                        EXT_IMAGE,
                }
        },      


        {
                ISTEPNAME(12,3,"mss_eff_config"),
                MC_INIT::call_mss_eff_config,
                {
                        START_FN,
                        EXT_IMAGE,
                }
        },      

  
        //  END OF LIST!
};

// make a struct from the above with the number of items included
const   ExtTaskInfo g_istep12TaskList    =   {
        &(g_istep12[0]),
        ( sizeof(g_istep12)/sizeof(TaskInfo) ),
        NULL    //  later, depModules struct
};

};  // end namespace

#endif
