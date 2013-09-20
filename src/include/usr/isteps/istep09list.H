/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/isteps/istep09list.H $                        */
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

#ifndef __ISTEPS_ISTEP09LIST_H
#define __ISTEPS_ISTEP09LIST_H

/**
 * @file    istep09list.H
 *
 *  IStep 09    Activate PowerBus
 *  IPL FLow Doc        v1.28 (12/03/12)
 *
 *    09.1    proc_build_smp
 *          : Integrate PgP Islands into SMP
 *    09.2    host_slave_sbe_update
 *          : placeholder for secure boot
 *
 *  *****************************************************************
 *  THIS FILE WAS GENERATED ON 2012-04-11:1607
 *  *****************************************************************
 *
 *  Please see the note in initsvcstructs.H for description of
 *      the ISTEPNAME macro.
 *
 */

#include    <initservice/initsvcstructs.H>
#include    <initservice/initsvcreasoncodes.H>

//  include prototypes file
#include    "../../../usr/hwpf/hwp/activate_powerbus/activate_powerbus.H"

namespace   INITSERVICE
{
    const   TaskInfo    g_istep09[]  =   {

        {

                "",         // dummy, index 0
                NULL,
                {
                        NONE,
                        EXT_IMAGE,
                        IPL_NOOP,
                        false,                              //true = check for attentions
                }
        },

        {
                ISTEPNAME(09,01,"proc_build_smp"),
                ACTIVATE_POWERBUS::call_proc_build_smp,
                {
                        START_FN,
                        EXT_IMAGE,
                        NORMAL_IPL_OP,
                        true,
                }
        },
        {
                ISTEPNAME(09,02,"host_slave_sbe_update"),
                ACTIVATE_POWERBUS::call_host_slave_sbe_update,
                {
                        START_FN,
                        EXT_IMAGE,
                        NORMAL_IPL_OP,
                        true,
                }
        },


        //  END OF LIST!
};

const DepModInfo  g_istep09Dependancies = {
    {
        DEP_LIB(libactivate_powerbus.so),
        DEP_LIB(libdram_initialization.so),
        DEP_LIB(libsbe.so),
        DEP_LIB(libbuild_winkle_images.so),
        { 0 },
    }
};


// make a struct from the above with the number of items included
const   ExtTaskInfo g_istep09TaskList    =   {
        &(g_istep09[0]),
        ( sizeof(g_istep09)/sizeof(TaskInfo) ),
        &g_istep09Dependancies //  later, depModules struct
};

};  // end namespace

#endif
