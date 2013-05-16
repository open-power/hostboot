/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/isteps/istep18list.H $                        */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2013              */
/*                                                                        */
/* p1                                                                     */
/*                                                                        */
/* Object Code Only (OCO) source materials                                */
/* Licensed Internal Code Source Materials                                */
/* IBM HostBoot Licensed Internal Code                                    */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* Origin: 30                                                             */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
#ifndef __ISTEPS_ISTEP18LIST_H
#define __ISTEPS_ISTEP18LIST_H

/**
 * @file    istep18list.H
 *
 *  IStep 18    Establish System SMP
 *  IPL FLow Doc        v1.35 (04/11/13)
 *
 *    18.12    host_coalesce_host
 *          : Create single host image
 *    18.13    proc_tod_setup
 *          : Create TOD topology
 *    18.14    proc_tod_init
 *          : Start TOD to running state
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
#include    "../../../usr/hwpf/hwp/tod_init/tod_init.H"

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
                        false,        // true = check for attentions
                }
        },

        {
                ISTEPNAME(18,01,""),
                NULL,
                {
                        NONE,
                        EXT_IMAGE,
                        IPL_NOOP,
                        false,
                }
        },

        {
                ISTEPNAME(18,02,""),
                NULL,
                {
                        NONE,
                        EXT_IMAGE,
                        IPL_NOOP,
                        false,
                }
        },

        {
                ISTEPNAME(18,03,""),
                NULL,
                {
                        NONE,
                        EXT_IMAGE,
                        IPL_NOOP,
                        false,
                }
        },

        {

                ISTEPNAME(18,04,""),
                NULL,
                {
                        NONE,
                        EXT_IMAGE,
                        IPL_NOOP,
                        false,
                }
        },

        {
                ISTEPNAME(18,05,""),
                NULL,
                {
                        NONE,
                        EXT_IMAGE,
                        IPL_NOOP,
                        false,
                }
        },

        {
                ISTEPNAME(18,06,""),
                NULL,
                {
                        NONE,
                        EXT_IMAGE,
                        IPL_NOOP,
                        false,
                }
        },

        {
                ISTEPNAME(18,07,""),
                NULL,
                {
                        NONE,
                        EXT_IMAGE,
                        IPL_NOOP,
                        false,
                }
        },
        {
                ISTEPNAME(18,08,""),
                NULL,
                {
                        NONE,
                        EXT_IMAGE,
                        IPL_NOOP,
                        false,
                }
        },
        {
                ISTEPNAME(18,09,""),
                NULL,
                {
                        NONE,
                        EXT_IMAGE,
                        IPL_NOOP,
                        false,
                }
        },
        {

                ISTEPNAME(18,10,""),
                NULL,
                {
                        NONE,
                        EXT_IMAGE,
                        IPL_NOOP,
                        false,
                }
        },
        {
                ISTEPNAME(18,11,""),
                NULL,
                {
                        NONE,
                        EXT_IMAGE,
                        IPL_NOOP,
                        false,
                }
        },
        {
                ISTEPNAME(18,12,"host_coalesce_host"),
                ESTABLISH_SYSTEM_SMP::call_host_coalesce_host,
                {
                        START_FN,
                        EXT_IMAGE,
                        NORMAL_IPL_OP | MPIPL_OP,
                        false,
                }
        },
        {
                ISTEPNAME(18,13,"proc_tod_setup"),
                TOD::call_tod_setup,
                {
                        START_FN,
                        EXT_IMAGE,
                        NORMAL_IPL_OP,
                        false,
                }
        },
        {
                ISTEPNAME(18,14,"proc_tod_init"),
                TOD::call_tod_init,
                {
                        START_FN,
                        EXT_IMAGE,
                        NORMAL_IPL_OP,
                        false,
                }
        },

        //  END OF LIST!
};

const DepModInfo  g_istep18Dependancies = {
    {
        DEP_LIB(libestablish_system_smp.so),
        DEP_LIB(libtod_init.so),
        DEP_LIB(libedi_ei_initialization.so),
        { 0 },
    }
};

// make a struct from the above with the number of items included
const   ExtTaskInfo g_istep18TaskList    =   {
        &(g_istep18[0]),
        ( sizeof(g_istep18)/sizeof(TaskInfo) ),
        &g_istep18Dependancies    //  later, depModules struct
};

};  // end namespace

#endif
