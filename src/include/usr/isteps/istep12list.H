/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/isteps/istep12list.H $                        */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2020                        */
/* [+] Google Inc.                                                        */
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
#ifndef __ISTEPS_ISTEP12LIST_H
#define __ISTEPS_ISTEP12LIST_H

/**
 * @file    istep12list.H
 *
 *  IStep 12    Step 12 OMI Training
 *  P10 IPL FLow Doc        v0.89.17
 *
 * 12.1  mss_getecid
 *       :  Read out ECID off all Explorers
 * 12.2  omi_attr_update
 *       :  OMI ATTR update
 * 12.3  proc_omi_scominit
 *       :  OMI Scom setup on the processor
 * 12.4  ocmb_omi_scominit
 *       :  OMI Scom setup for Explorer specific inits
 * 12.5  omi_pre_trainadv
 *       :  Advanced pre-OMI training
 * 12.6  omi_setup
 *       :  OMI setup for training
 * 12.7  omi_io_run_training
 *       :  Run training on MC buses
 * 12.8  omi_train_check
 *       :  Check for training errors
 * 12.9  omi_post_trainadv
 *       :  Debug routine for IO Characterization
 * 12.10 host_attnlisten_memb
 *       :  Start attention poll for membuf
 * 12.11 host_omi_init
 *       :  Init the OMI protocol, set the Inband base addresses
 * 12.12 update_omi_firmware
 *       :  Firmware update of Explorer
 *
 *  Please see the note in initsvcstructs.H for description of
 *      the ISTEPNAME macro.
 *
 */

#include    <initservice/initsvcstructs.H>
#include    <initservice/initsvcreasoncodes.H>

//  include prototypes file


namespace   ISTEP_12
{

/**
 *  @brief   mss_getecid
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return any errlogs to istep
 *
 */
void*  call_mss_getecid( void    *io_pArgs );

/**
 *  @brief   omi_attr_update
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return any errlogs to istep
 *
 */
void*  call_omi_attr_update( void    *io_pArgs );

/**
 *  @brief   proc_omi_scominit
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return any errlogs to istep
 *
 */
void*  call_proc_omi_scominit( void    *io_pArgs );

/**
 *  @brief   ocmb_omi_scominit
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return any errlogs to istep
 *
 */
void*  call_ocmb_omi_scominit( void    *io_pArgs );

/**
 *  @brief   omi_pre_trainadv
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return any errlogs to istep
 *
 */
void*  call_omi_pre_trainadv( void    *io_pArgs );

/**
 *  @brief   omi_setup
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return any errlogs to istep
 *
 */
void*  call_omi_setup( void    *io_pArgs );

/**
 *  @brief   omi_io_run_training
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return any errlogs to istep
 *
 */
void*  call_omi_io_run_training( void    *io_pArgs );

/**
 *  @brief   omi_post_trainadv
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return any errlogs to istep
 *
 */
void*  call_omi_post_trainadv( void    *io_pArgs );

/**
 *  @brief   omi_train_check
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return any errlogs to istep
 *
 */
void*  call_omi_train_check( void    *io_pArgs );

/**
 *  @brief   host_omi_init
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return any errlogs to istep
 *
 */
void*  call_host_omi_init( void    *io_pArgs );

/**
 *  @brief   host_attnlisten_memb
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return any errlogs to istep
 *
 */
void*  call_host_attnlisten_memb( void    *io_pArgs );

/**
 *  @brief   update_omi_firmware
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return any errlogs to istep
 *
 */
void*  call_update_omi_firmware( void    *io_pArgs );

};


namespace   INITSERVICE
{

const   TaskInfo    g_istep12[]  =   {
        {
                "",                   // dummy, index 0
                NULL,
                { NONE, EXT_IMAGE, IPL_NOOP, false }
        },
        {
                ISTEPNAME(12,01,"mss_getecid"),
                ISTEP_12::call_mss_getecid,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, true }
        },
        {
                ISTEPNAME(12,02,"omi_attr_update"),
                ISTEP_12::call_omi_attr_update,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, true }
        },
        {
                ISTEPNAME(12,03,"proc_omi_scominit"),
                ISTEP_12::call_proc_omi_scominit,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, true }
        },
        {
                ISTEPNAME(12,04,"ocmb_omi_scominit"),
                ISTEP_12::call_ocmb_omi_scominit,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, true }
        },
        {
                ISTEPNAME(12,05,"omi_pre_trainadv"),
                ISTEP_12::call_omi_pre_trainadv,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, true }
        },
        {
                ISTEPNAME(12,06,"omi_setup"),
                ISTEP_12::call_omi_setup,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, true }
        },
        {
                ISTEPNAME(12,07,"omi_io_run_training"),
                ISTEP_12::call_omi_io_run_training,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, true }
        },
        {
                ISTEPNAME(12,08,"omi_train_check"),
                ISTEP_12::call_omi_train_check,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, true }
        },
        {
                ISTEPNAME(12,09,"omi_post_trainadv"),
                ISTEP_12::call_omi_post_trainadv,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, true }
        },
        {
                ISTEPNAME(12,10,"host_attnlisten_memb"),
                ISTEP_12::call_host_attnlisten_memb,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, true }
        },
        {
                ISTEPNAME(12,11,"host_omi_init"),
                ISTEP_12::call_host_omi_init,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, true }
        },
        {
                ISTEPNAME(12,12,"update_omi_firmware"),
                ISTEP_12::call_update_omi_firmware,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, true }
        },

};

const DepModInfo g_istep12Dependancies = {
    {
        DEP_LIB(libistep12.so),
        DEP_LIB(libnestmemutils.so),
        DEP_LIB(libisteps_mss.so),
        DEP_LIB(libexpupd.so),
        NULL
    }
};

const ExtTaskInfo g_istep12TaskList = {
    &(g_istep12[0]),
    ( sizeof(g_istep12)/sizeof(TaskInfo) ),
    &g_istep12Dependancies
};

};  // end namespace

#endif
