/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/isteps/spless_255list.H $                     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2017                        */
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
#ifndef __ISTEPS_SPLESS_255LIST_H
#define __ISTEPS_SPLESS_255LIST_H

/**
 * @file    spless_255list.H
 *
 *  This file DOES NOT contain real isteps.  It contains control "isteps"
 *  for the SP Less communication/control path
 *
 *  Please see the note in initsvcstructs.H for description of
 *      the ISTEPNAME macro.
 *
 */

#include    <initservice/initsvcstructs.H>
#include    <initservice/initsvcreasoncodes.H>
#include <config.h>


/**
 * The following isteps are not used as normal isteps, but instead
 * are for SPless communication/control of Hostboot.  This is "weird"
 * as it is not the normal use of isteps, but it takes advantage of
 * an existing communication path, without adding a lot of extra
 * code into hostboot.
 *
 * NOTE: These isteps are NEVER used for mainline boot and are only
 * used for FSP Less communication
 */

namespace   INITSERVICE
{

    // These constants are used by HB to handle the out of band
    // "isteps".  Note that the actual numbers must be in the
    // Task info list so they get properly parsed into the
    // isteplist.csv file
    const   uint8_t     CONTROL_ISTEP          =   0xFF;
    const   uint8_t     CTL_CONT_TRACE_DISABLE =   0x00;
    const   uint8_t     CTL_CONT_TRACE_ENABLE  =   0x01;
    const   uint8_t     FLUSH_TRACE_BUFS       =   0x02;
    const   uint8_t     DUMP_FAPI_ATTR         =   0x03;
    const   uint8_t     SET_ATTR_OVERRIDES     =   0x04;
    const   uint8_t     CLEAR_ATTR_OVERRIDES   =   0x05;
    const   uint8_t     GET_FAPI_ATTR          =   0x06;


    const   TaskInfo    g_istep255[]  =   {
        {
                ISTEPNAME(255,0, "cont_trace_disable"),
                NULL,
                { NONE, EXT_IMAGE, IPL_NOOP, false }
        },
        {
                ISTEPNAME(255,1, "cont_trace_enable"),
                NULL,
                { NONE, EXT_IMAGE, IPL_NOOP, false }
        },
        {
                ISTEPNAME(255,2, "flush_trace_bufs"),
                NULL,
                { NONE, EXT_IMAGE, IPL_NOOP, false }
        },
        {
                ISTEPNAME(255,3, "dump_fapi_attr"),
                NULL,
                { NONE, EXT_IMAGE, IPL_NOOP, false }
        },
        {
                ISTEPNAME(255,4, "set_attr_overrides"),
                NULL,
                { NONE, EXT_IMAGE, IPL_NOOP, false }
        },
        {
                ISTEPNAME(255,5, "clear_attr_overrides"),
                NULL,
                { NONE, EXT_IMAGE, IPL_NOOP, false }
        },
        {
                ISTEPNAME(255,6, "get_fapi_attr"),
                NULL,
                { NONE, EXT_IMAGE, IPL_NOOP, false }
        },
};

const DepModInfo g_istep255Dependancies = {
    {
        NULL
    }
};

const ExtTaskInfo g_istep255TaskList = {
    &(g_istep255[0]),
    ( sizeof(g_istep255)/sizeof(TaskInfo) ),
    &g_istep255Dependancies
};

};  // end namespace

#endif
