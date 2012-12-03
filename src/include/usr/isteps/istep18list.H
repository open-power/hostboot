/*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/include/usr/isteps/istep18list.H $
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
#ifndef __ISTEPS_ISTEP18LIST_H
#define __ISTEPS_ISTEP18LIST_H

/**
 * @file    istep18list.H
 *
 *  IStep 18    Establish System SMP
 *  IPL FLow Doc        v1.28 (12/03/12)
 *
 *    18.10    host_coalesce_host
 *          : Create single host image
 *
 *  *****************************************************************
 *  THIS FILE WAS PARTIALLY GENERATED ON 2012-04-11:1611
 *  *****************************************************************
 *
 *  Please see the note in initsvcstructs.H for description of
 *      the ISTEPNAME macro.
 *
 */

#include    <initservice/initsvcstructs.H>
#include    <initservice/initsvcreasoncodes.H>

//  include prototypes file
#include    "../../../usr/hwpf/hwp/establish_system_smp/establish_system_smp.H"

namespace   INITSERVICE
{
    const   TaskInfo    g_istep18[]  =   {

        {

                "",         // dummy, index 0
                NULL,
                {
                        NONE,
                        EXT_IMAGE,
                        IPL_NOOP,
                }
        },

        {
                ISTEPNAME(18,01,""),
                NULL,
                {
                        NONE,
                        EXT_IMAGE,
                        IPL_NOOP,
                }
        },

        {
                ISTEPNAME(18,02,""),
                NULL,
                {
                        NONE,
                        EXT_IMAGE,
                        IPL_NOOP,
                }
        },

        {
                ISTEPNAME(18,03,""),
                NULL,
                {
                        NONE,
                        EXT_IMAGE,
                        IPL_NOOP,
                }
        },

        {

                ISTEPNAME(18,04,""),
                NULL,
                {
                        NONE,
                        EXT_IMAGE,
                        IPL_NOOP,
                }
        },

        {
                ISTEPNAME(18,05,""),
                NULL,
                {
                        NONE,
                        EXT_IMAGE,
                        IPL_NOOP,
                }
        },

        {
                ISTEPNAME(18,06,""),
                NULL,
                {
                        NONE,
                        EXT_IMAGE,
                        IPL_NOOP,
                }
        },

        {
                ISTEPNAME(18,07,""),
                NULL,
                {
                        NONE,
                        EXT_IMAGE,
                        IPL_NOOP,
                }
        },
        {

                ISTEPNAME(18,08,""),
                NULL,
                {
                        NONE,
                        EXT_IMAGE,
                        IPL_NOOP,
                }
        },
        {

                ISTEPNAME(18,09,""),
                NULL,
                {
                        NONE,
                        EXT_IMAGE,
                        IPL_NOOP,
                }
        },
        {
                ISTEPNAME(18,10,"host_coalesce_host"),
                ESTABLISH_SYSTEM_SMP::call_host_coalesce_host,
                {
                        START_FN,
                        EXT_IMAGE,
                        NORMAL_IPL_OP | MPIPL_OP,
                }
        },


        //  END OF LIST!
};

// make a struct from the above with the number of items included
const   ExtTaskInfo g_istep18TaskList    =   {
        &(g_istep18[0]),
        ( sizeof(g_istep18)/sizeof(TaskInfo) ),
        NULL    //  later, depModules struct
};

};  // end namespace

#endif
