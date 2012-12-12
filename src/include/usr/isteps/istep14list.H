/*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/include/usr/isteps/istep14list.H $
 *
 *  IBM CONFIDENTIAL
 *
 *  COPYRIGHT International Business Machines Corp. 2012
 *
 *  p1
 *
 *  Object Code Only (OCO) source materials
 *  Licensed Internal Code Source Materials
 *  IBM HostBoot Licensed Internal Code
 *
 *  The source code for this program is not published or other-
 *  wise divested of its trade secrets, irrespective of what has
 *  been deposited with the U.S. Copyright Office.
 *
 *  Origin: 30
 *
 *  IBM_PROLOG_END_TAG
 */
#ifndef __ISTEPS_ISTEP14LIST_H
#define __ISTEPS_ISTEP14LIST_H

/**
 * @file    istep14list.H
 *
 *  IStep 14    Dram Initialization
 *  IPL FLow Doc        v1.28 (12/03/12)
 *
 *    14.1    host_startprd_dram
 *          : Load prd for DRAM domain
 *    14.2    mss_extent_setup
 *          : MSS Extent Setup
 *    14.3    mss_memdiag
 *          : Mainstore Pattern Testing
 *    14.4    mss_scrub
 *          : Start background scrub
 *    14.5    mss_thermal_init
 *          : Initialize the thermal sensor
 *    14.6    proc_setup_bars
 *          : Setup Memory BARs
 *    14.7    proc_pcie_config
 *          : Configure the PHBs
 *    14.8    proc_exit_cache_contained
 *          : Allow execution from memory
 *    14.9    host_mpipl_service
 *          : Perform MPIPL tasks
 *
 *
 *  Please see the note in initsvcstructs.H for description of
 *      the ISTEPNAME macro.
 *
 */

#include    <initservice/initsvcstructs.H>
#include    <initservice/initsvcreasoncodes.H>

//  include prototypes file
#include    "../../../usr/hwpf/hwp/dram_initialization/dram_initialization.H"

namespace   INITSERVICE
{
    const   TaskInfo    g_istep14[]  =   {

        {

                "",         // dummy, index 0
                NULL,
                {
                        NONE,
                        EXT_IMAGE,
                        IPL_NOOP,
                        false,                              // true = check for attentions
                }
        },

        {
                ISTEPNAME(14,01,"host_startprd_dram"),
                DRAM_INITIALIZATION::call_host_startprd_dram,
                {
                        START_FN,
                        EXT_IMAGE,
                        NORMAL_IPL_OP,
                        true,
                }
        },
        {
                ISTEPNAME(14,02,"mss_extent_setup"),
                DRAM_INITIALIZATION::call_mss_extent_setup,
                {
                        START_FN,
                        EXT_IMAGE,
                        NORMAL_IPL_OP,
                        true,
                }
        },
        {
                ISTEPNAME(14,03,"mss_memdiag"),
                DRAM_INITIALIZATION::call_mss_memdiag,
                {
                        START_FN,
                        EXT_IMAGE,
                        NORMAL_IPL_OP,
                        true,
                }
        },
        {
                ISTEPNAME(14,04,"mss_scrub"),
                DRAM_INITIALIZATION::call_mss_scrub,
                {
                        START_FN,
                        EXT_IMAGE,
                        NORMAL_IPL_OP,
                        true,
                }
        },


        {
                ISTEPNAME(14,05,"mss_thermal_init"),
                DRAM_INITIALIZATION::call_mss_thermal_init,
                {
                        START_FN,
                        EXT_IMAGE,
                        NORMAL_IPL_OP,
                        true,
                }
        },


        {
                ISTEPNAME(14,06,"proc_setup_bars"),
                DRAM_INITIALIZATION::call_proc_setup_bars,
                {
                        START_FN,
                        EXT_IMAGE,
                        NORMAL_IPL_OP,
                        true,
                }
        },


        {
                ISTEPNAME(14,07,"proc_pcie_config"),
                DRAM_INITIALIZATION::call_proc_pcie_config,
                {
                        START_FN,
                        EXT_IMAGE,
                        NORMAL_IPL_OP,
                        true,
                }
        },


        {
                ISTEPNAME(14,08,"proc_exit_cache_contained"),
                DRAM_INITIALIZATION::call_proc_exit_cache_contained,
                {
                        START_FN,
                        EXT_IMAGE,
                        NORMAL_IPL_OP | MPIPL_OP,
                        true,
                }
        },
        {
                ISTEPNAME(14,09,"host_mpipl_service"),
                DRAM_INITIALIZATION::call_host_mpipl_service,
                {
                        START_FN,
                        EXT_IMAGE,
                        MPIPL_OP,
                        true,
                }
        },


        //  END OF LIST!
};

// make a struct from the above with the number of items included
const   ExtTaskInfo g_istep14TaskList    =   {
        &(g_istep14[0]),
        ( sizeof(g_istep14)/sizeof(TaskInfo) ),
        NULL    //  later, depModules struct
};

};  // end namespace

#endif
