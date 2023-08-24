/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/isteps/istep124list.H $                       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2023                        */
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
#ifndef __ISTEPS_ISTEP124LIST_H
#define __ISTEPS_ISTEP124LIST_H

/**
 * @file    istep124list.H
 *
 *  Istep 12.4 calls 10 hardware procedures. Istep 124 allows a user to
 *  execute these procedures individually in istep mode. The istep number
 *  is determined by shifting the Istep.substep left, so Istep 12.4 becomes
 *  Istep 124. The individual HWPs can then be called as substeps, Istep 124.1
 *  through 124.10.
 *
 *  IStep 124    Step 12.4 ocmb_omi_scominit
 *  P10 IPL FLow Doc        v2.12
 *
 * 124.1 ody_omi_hss_ppe_load [OSBE]
 *       :  Load the OMI SerDes Microcontroller binary image and the memory
 *          register content for each thread into sram
 *
 * 124.2 ody_omi_hss_config [OSBE]
 *       :  Configure the OMI SerDes Microcontroller function prior to starting
 *       :  execution
 *
 * 124.3 ody_omi_hss_ppe_start [OSBE]
 *       :  Start the execution of the OMI SerDes Microcontroller
 *
 * 124.4 ody_omi_hss_bist_init [OSBE]
 *       :  Initialize the OMI SerDes for BIST functionality
 *         (if MNFG_ODY_ENABLE_HSS_BIST set)
 *
 * 124.5 ody_omi_hss_bist_start [OSBE]
 *       :  Start the OMI SerDes BIST (if MNFG_ODY_ENABLE_HSS_BIST set)
 *
 * 124.6 ody_omi_hss_bist_poll [OSBE]
 *       :  Poll for OMI SerDes BIST Complete (if MNFG_ODY_ENABLE_HSS_BIST set)
 *
 * 124.7 ody_omi_hss_bist_cleanup [OSBE]
 *       :  Clean up after the bist run. This includes resetting the PHY to a
 *          known state. (if MNFG_ODY_ENABLE_HSS_BIST set)
 *
 * 124.8 ody_omi_hss_init [OSBE]
 *       :  Initialize the OMI SerDes registers to functional training values
 *
 * 124.9 ody_omi_hss_dccal_start [OSBE]
 *       :  Start OMI SerDes DC Calibration
 *
 * 124.10 ody_omi_hss_dccal_poll [OSBE]
 *       :  Poll OMI SerDes DC Calibration
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
 *  @brief   ody_omi_hss_ppe_load
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return any errlogs to istep
 *
 */
void*  call_ody_omi_hss_ppe_load( void    *io_pArgs );

/**
 *  @brief   ody_omi_hss_config
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return any errlogs to istep
 *
 */
void*  call_ody_omi_hss_config( void    *io_pArgs );

/**
 *  @brief   ody_omi_hss_ppe_start
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return any errlogs to istep
 *
 */
void*  call_ody_omi_hss_ppe_start( void    *io_pArgs );

/**
 *  @brief   ody_omi_hss_bist_init
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return any errlogs to istep
 *
 */
void*  call_ody_omi_hss_bist_init( void    *io_pArgs );

/**
 *  @brief   ody_omi_hss_bist_start
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return any errlogs to istep
 *
 */
void*  call_ody_omi_hss_bist_start( void    *io_pArgs );

/**
 *  @brief   ody_omi_hss_bist_poll
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return any errlogs to istep
 *
 */
void*  call_ody_omi_hss_bist_poll( void    *io_pArgs );

/**
 *  @brief   ody_omi_hss_bist_cleanup
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return any errlogs to istep
 *
 */
void*  call_ody_omi_hss_bist_cleanup( void    *io_pArgs );

/**
 *  @brief   ody_omi_hss_init
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return any errlogs to istep
 *
 */
void*  call_ody_omi_hss_init( void    *io_pArgs );

/**
 *  @brief   ody_omi_hss_dccal_start
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return any errlogs to istep
 *
 */
void*  call_ody_omi_hss_dccal_start( void    *io_pArgs );

/**
 *  @brief   ody_omi_hss_dccal_poll
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return any errlogs to istep
 *
 */
void*  call_ody_omi_hss_dccal_poll( void    *io_pArgs );

};


namespace   INITSERVICE
{

const   TaskInfo    g_istep124[]  =   {
        {
                "",                   // dummy, index 0
                NULL,
                { NONE, EXT_IMAGE, IPL_NOOP, false }
        },
        {
                ISTEPNAME(124,01,"ody_omi_hss_ppe_load"),
                ISTEP_12::call_ody_omi_hss_ppe_load,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, true }
        },
        {
                ISTEPNAME(124,02,"ody_omi_hss_config"),
                ISTEP_12::call_ody_omi_hss_config,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, true }
        },
        {
                ISTEPNAME(124,03,"ody_omi_hss_ppe_start"),
                ISTEP_12::call_ody_omi_hss_ppe_start,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, true }
        },
        {
                ISTEPNAME(124,04,"ody_omi_hss_bist_init"),
                ISTEP_12::call_ody_omi_hss_bist_init,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, true }
        },
        {
                ISTEPNAME(124,05,"ody_omi_hss_bist_start"),
                ISTEP_12::call_ody_omi_hss_bist_start,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, true }
        },
        {
                ISTEPNAME(124,06,"ody_omi_hss_bist_poll"),
                ISTEP_12::call_ody_omi_hss_bist_poll,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, true }
        },
        {
                ISTEPNAME(124,07,"ody_omi_hss_bist_cleanup"),
                ISTEP_12::call_ody_omi_hss_bist_cleanup,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, true }
        },
        {
                ISTEPNAME(124,08,"ody_omi_hss_init"),
                ISTEP_12::call_ody_omi_hss_init,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, true }
        },
        {
                ISTEPNAME(124,09,"ody_omi_hss_dccal_start"),
                ISTEP_12::call_ody_omi_hss_dccal_start,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, true }
        },
        {
                ISTEPNAME(124,10,"ody_omi_hss_dccal_poll"),
                ISTEP_12::call_ody_omi_hss_dccal_poll,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, true }
        },

};

const DepModInfo g_istep124Dependancies = {
    {
        DEP_LIB(libnestmemutils.so),
        DEP_LIB(libisteps_mss.so),
        DEP_LIB(libocmbupd.so),
        DEP_LIB(libistep12.so),
        DEP_LIB(libistep124.so),
        NULL
    }
};

const ExtTaskInfo g_istep124TaskList = {
    &(g_istep124[0]),
    ( sizeof(g_istep124)/sizeof(TaskInfo) ),
    &g_istep124Dependancies
};

};  // end namespace

#endif
