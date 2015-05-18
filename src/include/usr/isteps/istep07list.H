/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/isteps/istep07list.H $                        */
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
#ifndef __ISTEPS_ISTEP07LIST_H
#define __ISTEPS_ISTEP07LIST_H

/**
 * @file    istep07list.H
 *
 *  IStep 07    Nest Chiplets
 *  IPL FLow Doc        v1.35 (04/11/13)
 *
 *    07.1    proc_attr_update
 *          : Proc attr update
 *    07.2    proc_a_x_pci_dmi_pll_initf
 *          : PLL Initfile for A, X, PCIe, DMI
 *    07.3    proc_a_x_pci_dmi_pll_setup
 *          : Setup PLL for A, X, PCIe, DMI
 *    07.4    proc_startclock_chiplets
 *          : Start clocks on A, X, PCIe chiplets
 *    07.5    proc_chiplet_scominit
 *          : Apply scom inits to chiplets
 *    07.6    proc_xbus_scominit
 *          : Apply scom inits to Xbus
 *    07.7    proc_abus_scominit
 *          : Apply scom inits to Abus
 *    07.8    proc_pcie_scominit
 *          : Apply scom inits to PCIE  chiplets
 *    07.9    proc_scomoverride_chiplets
 *          : Apply sequenced scom inits
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
                { NONE, EXT_IMAGE, IPL_NOOP, false }
        },
};


const DepModInfo g_istep07Dependancies = {
    {
        DEP_LIB(libnest_chiplets.so),
        DEP_LIB(libslave_sbe.so),
        DEP_LIB(libsecure_boot.so),
        NULL
    }
};

const ExtTaskInfo g_istep07TaskList = {
    &(g_istep07[0]),
    ( sizeof(g_istep07)/sizeof(TaskInfo) ),
    &g_istep07Dependancies
};

};  // end namespace

#endif
