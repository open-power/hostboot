/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/isteps/istep06list.H $                        */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2011,2013              */
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
#ifndef __ISTEPS_ISTEP6LIST_H
#define __ISTEPS_ISTEP6LIST_H

/**
 * @file    istep6list.H
 *
 *  list of functions called by HWAS (ISTEP 6) - "named isteps"
 *  IPL FLow Doc        v1.28 (12/03/12)
 *
 *  Please see the note in initsvcstructs.H for description of
 *      the ISTEPNAME macro.
 *
 */

#include    <initservice/initsvcstructs.H>
#include    <initservice/initsvcreasoncodes.H>
#include    <hwas/common/hwas.H>
#include    <hwas/hostbootIstep.H>
#include    "../../../usr/hwpf/hwp/slave_sbe/slave_sbe.H"

namespace   INITSERVICE
{

/**
 * @file    istep06list.H
 *
 * @note    IStep definition for Hostboot - Slave SBE
 *
 *  IStep 06    Slave SBE
 *  IPL FLow Doc        v1.28 (12/03/12)
 *
 *  06.1    host_setup
 *        : Setup host environment (non-executable istep)
 *  06.2    host_istep_enable
 *        : Hostboot istep ready (non-executable istep)
 *  06.3    host_init_fsi
 *        : Setup the FSI links to slave chips
 *  06.4    host_set_ipl_parms
 *        : Build ipl parameters
 *  06.5    host_discover_targets 
 *      :   Builds targeting
 *  06.6    host_gard
 *      :   Do Gard
 *  06.7    host_cancontinue_clear
 *      :   Clear deconfigured states
 *  06.8    proc_revert_sbe_mcs_setup
 *      :   Clean up MCS extent regs
 *  06.9    host_slave_sbe_config
 *  06.10   host_sbe_start
 *  06.11   proc_check_slave_sbe_seeprom_complete
 *        : Check Slave SBE Complete
 *  06.12   proc_xmit_sbe
 *        : vSBE Init of Slave Chips
 *
 */
const   TaskInfo    g_istep06[]  =   {
        {
                "",         // dummy, index 0
                NULL,
                {
                        NONE,
                        EXT_IMAGE,
                        IPL_NOOP,
                        false,
                }
        },
        {
                ISTEPNAME(06,01,""),        // not used.
                NULL,
                {
                        NONE,
                        EXT_IMAGE,
                        IPL_NOOP,
                        false,
                }
        },
        {
                ISTEPNAME(06,02,""),        // not used.
                NULL,
                {
                        NONE,
                        EXT_IMAGE,
                        IPL_NOOP,
                        false,
                }
        },

        {
                ISTEPNAME(06,03,"host_init_fsi"),           // substep name
                HWAS::host_init_fsi,                        // pointer to fn
                {
                        START_FN,                           // task type
                        EXT_IMAGE,                          // Extended Module
                        NORMAL_IPL_OP | MPIPL_OP,
                        false,                              // true = check for attentions
                }
        },
        {
                ISTEPNAME(06,04,"host_set_ipl_parms"),
                HWAS::host_set_ipl_parms,
                {
                        START_FN,
                        EXT_IMAGE,
                        NORMAL_IPL_OP | MPIPL_OP,
                        false,
                }
        },
        {
                ISTEPNAME(06,05,"host_discover_targets"),   // substep name
                HWAS::host_discover_targets,                // pointer to fn
                {
                        START_FN,                           // task type
                        EXT_IMAGE,                          // Extended Module
                        NORMAL_IPL_OP | MPIPL_OP,
                        false,
                }
        },
        {
                ISTEPNAME(06,06, "host_gard"),           // substep name
                HWAS::host_gard,                        // pointer to fn
                {
                        START_FN,                       // task type
                        EXT_IMAGE,                      // Extended Module
                        NORMAL_IPL_OP | MPIPL_OP,
                        false,
                }
        },
        {
                ISTEPNAME(06,07,"host_cancontinue_clear"),
                HWAS::host_cancontinue_clear,
                {
                        START_FN,
                        EXT_IMAGE,
                        NORMAL_IPL_OP,
                        false,
                }
        },
        {
                ISTEPNAME(06,08,"proc_revert_sbe_mcs_setup"),
                SLAVE_SBE::call_proc_revert_sbe_mcs_setup,
                {
                        START_FN,
                        EXT_IMAGE,
                        NORMAL_IPL_OP,
                        false,
                }
        },
        {
                ISTEPNAME(06,09,"host_slave_sbe_config"),
                SLAVE_SBE::call_host_slave_sbe_config,
                {
                        START_FN,
                        EXT_IMAGE,
                        NORMAL_IPL_OP,
                        false,
                }
        },

        {
                ISTEPNAME(06,10,"host_sbe_start"),
                SLAVE_SBE::call_host_sbe_start,
                {
                        START_FN,
                        EXT_IMAGE,
                        NORMAL_IPL_OP,
                        false,
                }
        },

        {
                ISTEPNAME(06,11,"proc_check_slave_sbe_seeprom_complete"),
                SLAVE_SBE::call_proc_check_slave_sbe_seeprom_complete,
                {
                        START_FN,
                        EXT_IMAGE,
                        NORMAL_IPL_OP,
                        false,
                }
        },
        {
                ISTEPNAME(06,12,"proc_xmit_sbe"),
                SLAVE_SBE::call_proc_xmit_sbe,
                {
                        START_FN,
                        EXT_IMAGE,
                        NORMAL_IPL_OP,
                        false,
                }
        },

        //  END OF LIST!
};


const DepModInfo  g_istep06Dependancies = {
    {
      DEP_LIB(libslave_sbe.so),
      { 0 },
    }
};

// make a struct from the above with the number of items included
const   ExtTaskInfo g_istep06TaskList    =   {
        &(g_istep06[0]),
        ( sizeof(g_istep06)/sizeof(TaskInfo) ),
         &(g_istep06Dependancies),
        };


};  // end namespace

#endif
