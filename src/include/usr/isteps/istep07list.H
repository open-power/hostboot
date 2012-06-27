/*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/include/usr/isteps/istep07list.H $
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
#ifndef __ISTEPS_ISTEP07LIST_H
#define __ISTEPS_ISTEP07LIST_H

/**
 * @file    istep07list.H
 *
 *  IStep 07    Nest Chiplets
 *  IPL FLow Doc        v1.03 (06/26/12)
 *
 *    07.1    proc_a_x_pci_dmi_pll_setup
 *          : Setup PLL for A, X, PCIe, DMI
 *    07.2    proc_startclock_chiplets
 *          : Start clocks on A, X, PCIe chiplets
 *    07.3    proc_chiplet_scominit
 *          : Apply scom inits to chiplets
 *    07.4    proc_pcie_scominit
 *          : Apply scom inits to PCIe chiplets
 *    07.5    proc_scomoverride_chiplets
 *          : Apply sequenced scom inits
 *
 *  *****************************************************************
 *  THIS FILE WAS GENERATED ON 2012-04-11:1605
 *  *****************************************************************
 *
 *  Please see the note in initsvcstructs.H for description of
 *      the ISTEPNAME macro.
 *
 */

#include    <initservice/initsvcstructs.H>
#include    <initservice/initsvcreasoncodes.H>

//  include prototypes file
#include    "../../../usr/hwpf/hwp/nest_chiplets/nest_chiplets.H"

namespace   INITSERVICE
{
    const   TaskInfo    g_istep07[]  =   {

        {

                "",         // dummy, index 0
                NULL,
                {
                        NONE,
                        EXT_IMAGE,
                }
        },

        {
                ISTEPNAME(07,01,"proc_a_x_pci_dmi_pll_setup"),
                NEST_CHIPLETS::call_proc_a_x_pci_dmi_pll_setup,
                {
                        START_FN,
                        EXT_IMAGE,
                }
        },


        {
                ISTEPNAME(07,02,"proc_startclock_chiplets"),
                NEST_CHIPLETS::call_proc_startclock_chiplets,
                {
                        START_FN,
                        EXT_IMAGE,
                }
        },


        {
                ISTEPNAME(07,03,"proc_chiplet_scominit"),
                NEST_CHIPLETS::call_proc_chiplet_scominit,
                {
                        START_FN,
                        EXT_IMAGE,
                }
        },


        {
                ISTEPNAME(07,04,"proc_pcie_scominit"),
                NEST_CHIPLETS::call_proc_pcie_scominit,
                {
                        START_FN,
                        EXT_IMAGE,
                }
        },


        {
                ISTEPNAME(07,05,"proc_scomoverride_chiplets"),
                NEST_CHIPLETS::call_proc_scomoverride_chiplets,
                {
                        START_FN,
                        EXT_IMAGE,
                }
        },


        //  END OF LIST!
};

// make a struct from the above with the number of items included
const   ExtTaskInfo g_istep07TaskList    =   {
        &(g_istep07[0]),
        ( sizeof(g_istep07)/sizeof(TaskInfo) ),
        NULL    //  later, depModules struct
};

};  // end namespace

#endif
