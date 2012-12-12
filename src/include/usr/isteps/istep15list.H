/*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/include/usr/isteps/istep15list.H $
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
#ifndef __ISTEPS_ISTEP15LIST_H
#define __ISTEPS_ISTEP15LIST_H

/**
 * @file    istep15list.H
 *
 *  IStep 15    Build Winkle Images
 *  IPL FLow Doc        v1.28 (12/03/12)
 *
 *    15.1    host_build_winkle
 *          : Build runtime winkle images
 *    15.2    proc_set_pore_bar
 *          : Tell SLW Eng where winkle image is
 *    15.3    proc_poreslw_init
 *          : Initialize the PORE-SLW engine
 *
 *
 *  Please see the note in initsvcstructs.H for description of
 *      the ISTEPNAME macro.
 *
 */

#include    <initservice/initsvcstructs.H>
#include    <initservice/initsvcreasoncodes.H>

//  include prototypes file
#include    "../../../usr/hwpf/hwp/build_winkle_images/build_winkle_images.H"

namespace   INITSERVICE
{
    const   TaskInfo    g_istep15[]  =   {

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
                ISTEPNAME(15,01,"host_build_winkle"),
                BUILD_WINKLE_IMAGES::call_host_build_winkle,
                {
                        START_FN,
                        EXT_IMAGE,
                        NORMAL_IPL_OP | MPIPL_OP,
                        true,
                }
        },
        {
                ISTEPNAME(15,02,"proc_set_pore_bar"),
                BUILD_WINKLE_IMAGES::call_proc_set_pore_bar,
                {
                        START_FN,
                        EXT_IMAGE,
                        NORMAL_IPL_OP | MPIPL_OP,
                        true,
                }
        },
        {
                ISTEPNAME(15,03,"p8_poreslw_init"),
                BUILD_WINKLE_IMAGES::call_p8_poreslw_init,
                {
                        START_FN,
                        EXT_IMAGE,
                        NORMAL_IPL_OP | MPIPL_OP,
                        true,
                }
        },

        //  END OF LIST!
};

// make a struct from the above with the number of items included
const   ExtTaskInfo g_istep15TaskList    =   {
        &(g_istep15[0]),
        ( sizeof(g_istep15)/sizeof(TaskInfo) ),
        NULL    //  later, depModules struct
};

};  // end namespace

#endif
