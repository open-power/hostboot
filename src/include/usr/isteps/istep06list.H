/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/isteps/istep06list.H $                        */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2015                        */
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
#ifndef __ISTEPS_ISTEP6LIST_H
#define __ISTEPS_ISTEP6LIST_H

/**
 * @file    istep6list.H
 *
 *  list of functions called by HWAS (ISTEP 6) - "named isteps"
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
 *  IPL FLow Doc        v1.37 (08/13/13)
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
 *  06.9   host_slave_sbe_config
 *  06.10   host_sbe_start
 *  06.11   proc_check_slave_sbe_seeprom_complete
 *        : Check Slave SBE Complete
 *  06.12    proc_cen_ref_clk_enable
 *      :   Setup centaur ref clocks
 *  06.13   proc_xmit_sbe
 *        : vSBE Init of Slave Chips
 *
 */
const   TaskInfo    g_istep06[]  =   {
        {
                "",         // dummy, index 0
                NULL,
                { NONE, EXT_IMAGE, IPL_NOOP, false }
        },
        {
                ISTEPNAME(06,01,""),        // not used.
                NULL,
                { NONE, EXT_IMAGE, IPL_NOOP, false }
        },
        {
                ISTEPNAME(06,02,""),        // not used.
                NULL,
                { NONE, EXT_IMAGE, IPL_NOOP, false }
        },

        {
                ISTEPNAME(06,03,"host_init_fsi"),
                HWAS::host_init_fsi,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP | MPIPL_OP, false,
                        BASE_INITIALIZATION }
        },
        {
                ISTEPNAME(06,05,"host_discover_targets"),
                HWAS::host_discover_targets,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP | MPIPL_OP, false }
        },
};

const DepModInfo  g_istep06Dependancies = {
    {
      DEP_LIB(libbuild_winkle_images.so), //proc_mailbox_utils
      DEP_LIB(libslave_sbe.so),
      DEP_LIB(libsbe.so),
      DEP_LIB(libporeve.so),
      DEP_LIB(libpstates.so),
      DEP_LIB(libcore_activate.so),
      DEP_LIB(libsecure_boot.so),
#ifdef CONFIG_IPLTIME_CHECKSTOP_ANALYSIS
      DEP_LIB(libocc.so),
#endif
      NULL
    }
};

const ExtTaskInfo g_istep06TaskList = {
    &(g_istep06[0]),
    ( sizeof(g_istep06)/sizeof(TaskInfo) ),
    &(g_istep06Dependancies),
};

};  // end namespace

#endif
