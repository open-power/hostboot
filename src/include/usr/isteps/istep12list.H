/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/isteps/istep12list.H $                        */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2018                        */
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
 *  IStep 12    Step 12 DMI Training
 *  IPL FLow Doc        v1.07
 *
 * 12.1  mss_getecid
 *       :  Read out ECID off all Centaurs
 * 12.2  dmi_attr_update
 *       :DMI ATTR update
 * 12.3  proc_dmi_scominit
 *       :  DMI Scom setup on P8 MCS
 * 12.4  cen_dmi_scominit
 *       :  Scom setup on centaur
 * 12.5  dmi_erepair
 *          : Restore EDI Bus eRepair data
 * 12.6  dmi_io_dccal
 *       : Calibrate DMI interfaces
 * 12.7  dmi_pre_trainadv
 *       : Advanced pre DMI training
 * 12.8  dmi_io_run_training
 *       : Run training on MC buses
 * 12.9  dmi_post_trainadv
 *       : Advanced post DMI training
 * 12.10 proc_cen_framelock
 *       : Initialize EDI Frame
 * 12.11 host_startprd_dmi
 *       : Load prd for DMI domain
 * 12.12 host_attnlisten_memb
 *       : Start attention poll for membuf 
 * 12.13 cen_set_inband_addr
 *       : Set the Inband base addresses
 *
 *  Please see the note in initsvcstructs.H for description of
 *      the ISTEPNAME macro.
 *
 */

#include    <initservice/initsvcstructs.H>
#include    <initservice/initsvcreasoncodes.H>

//  include prototypes file

#include <config.h>

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
 *  @brief   dmi_attr_update
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return any errlogs to istep 
 *
 */
void*  call_dmi_attr_update( void    *io_pArgs );

/**
 *  @brief   proc_dmi_scominit
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return any errlogs to istep 
 *
 */
void*  call_proc_dmi_scominit( void    *io_pArgs );

/**
 *  @brief   cen_dmi_scominit
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return any errlogs to istep 
 *
 */
void*  call_cen_dmi_scominit( void    *io_pArgs );

/**
 *  @brief   dmi_erepair
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return any errlogs to istep 
 *
 */
void*  call_dmi_erepair( void    *io_pArgs );

/**
 *  @brief   dmi_io_dccal
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return any errlogs to istep 
 *
 */
void*  call_dmi_io_dccal( void    *io_pArgs );

/**
 *  @brief   dmi_pre_trainadv
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return any errlogs to istep 
 *
 */
void*  call_dmi_pre_trainadv( void    *io_pArgs );

/**
 *  @brief   dmi_io_run_training
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return any errlogs to istep 
 *
 */
void*  call_dmi_io_run_training( void    *io_pArgs );

/**
 *  @brief   dmi_post_trainadv
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return any errlogs to istep 
 *
 */
void*  call_dmi_post_trainadv( void    *io_pArgs );

/**
 *  @brief   proc_cen_framelock
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return any errlogs to istep 
 *
 */
void*  call_proc_cen_framelock( void    *io_pArgs );

/**
 *  @brief   host_startprd_dmi
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return any errlogs to istep 
 *
 */
void*  call_host_startprd_dmi( void    *io_pArgs );

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
 *  @brief   cen_set_inband_addr
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return any errlogs to istep 
 *
 */
void*  call_cen_set_inband_addr( void    *io_pArgs );

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
                ISTEPNAME(12,02,"dmi_attr_update"),
                ISTEP_12::call_dmi_attr_update,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, true }
        },
        {
                ISTEPNAME(12,03,"proc_dmi_scominit"),
                ISTEP_12::call_proc_dmi_scominit,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, true }
        },
        {
                ISTEPNAME(12,04,"cen_dmi_scominit"),
                ISTEP_12::call_cen_dmi_scominit,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, true }
        },
        {
                ISTEPNAME(12,05,"dmi_erepair"),
                ISTEP_12::call_dmi_erepair,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, true }
        },
        {
                ISTEPNAME(12,06,"dmi_io_dccal"),
                ISTEP_12::call_dmi_io_dccal,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, true }
        },
        {
                ISTEPNAME(12,07,"dmi_pre_trainadv"),
                ISTEP_12::call_dmi_pre_trainadv,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, true }
        },
        {
                ISTEPNAME(12,08,"dmi_io_run_training"),
                ISTEP_12::call_dmi_io_run_training,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, true }
        },
        {
                ISTEPNAME(12,09,"dmi_post_trainadv"),
                ISTEP_12::call_dmi_post_trainadv,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, true }
        },
        {
                ISTEPNAME(12,10,"proc_cen_framelock"),
                ISTEP_12::call_proc_cen_framelock,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, true }
        },
        {
                ISTEPNAME(12,11,"host_startprd_dmi"),
                ISTEP_12::call_host_startprd_dmi,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, true }
        },
        {
                ISTEPNAME(12,12,"host_attnlisten_memb"),
                ISTEP_12::call_host_attnlisten_memb,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, true }
        },
        {
                ISTEPNAME(12,13,"cen_set_inband_addr"),
                ISTEP_12::call_cen_set_inband_addr,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, true }
        },

};

const DepModInfo g_istep12Dependancies = {
    {
        DEP_LIB(libistep12.so),
        DEP_LIB(libnestmemutils.so),
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
