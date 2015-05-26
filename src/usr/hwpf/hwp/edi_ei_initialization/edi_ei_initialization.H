/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/edi_ei_initialization/edi_ei_initialization.H $ */
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
#ifndef  __EDI_EI_INITIALIZATION_EDI_EI_INITIALIZATION_H
#define  __EDI_EI_INITIALIZATION_EDI_EI_INITIALIZATION_H

/**
 *  @file edi_ei_initialization.H
 *
 *  EDI, EI Initialization
 *
 *  All of the following routines are "named isteps" - they are invoked as
 *  tasks by the @ref IStepDispatcher.
 *
 *  HWP_IGNORE_VERSION_CHECK
 *
 */

 /*  @tag isteplist
 *  @docversion     v1.28 (12/03/12)
 *  @istepname      edi_ei_initialization
 *  @istepnum       08
 *  @istepdesc      EDI, EI Initialization
 *
 *  @{
 *      @substepnum     1
 *      @substepname    fabric_erepair
 *      @substepdesc    : Restore Fabric/EDI Bus eRepair data
 *          @target_sched   serial
 *  @}
 *  @{
 *      @substepnum     2
 *      @substepname    fabric_io_dccal
 *      @substepdesc    : Calibrate Fabric/EDI interfaces
 *          @target_sched   serial
 *  @}
 *  @{
 *      @substepnum     3
 *      @substepname    fabric_pre_trainadv
 *      @substepdesc    : Advanced pre EI/EDI training
 *          @target_sched   serial
 *  @}
 *  @{
 *      @substepnum     4
 *      @substepname    fabric_io_run_training
 *      @substepdesc    : Run training on internal buses
 *          @target_sched   serial
 *  @}
 *  @{
 *      @substepnum     5
 *      @substepname    fabric_post_trainadv
 *      @substepdesc    : Advanced post EI/EDI training
 *          @target_sched   serial
 *  @}
 *  @{
 *      @substepnum     6
 *      @substepname    host_startprd_pbus
 *      @substepdesc    : Load PRD for powerbus domain
 *          @target_sched   serial
 *  @}
 *  @{
 *      @substepnum     7
 *      @substepname    host_attnlisten_proc
 *      @substepdesc    : Start listening for attentions
 *          @target_sched   serial
 *  @}
 *  @{
 *      @substepnum     8
 *      @substepname    proc_fab_iovalid
 *      @substepdesc    : Lower functional fences on local SMP
 *          @target_sched   serial
 *  @}
 *
 */

/******************************************************************************/
// Includes
/******************************************************************************/
#include    <stdint.h>

namespace   EDI_EI_INITIALIZATION
{



/**
 *  @brief   fabric_erepair
 *
 *           Restore Fabric/EDI Bus eRepair data
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return any errlogs to istep 
 *
 */
void*    call_fabric_erepair( void    *io_pArgs );



/**
 *  @brief   fabric_io_dccal
 *
 *           Calibrate Fabric/EDI interfaces
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return  any errlogs to istep 
 *
 */
void*    call_fabric_io_dccal( void    *io_pArgs );



/**
 *  @brief   fabric_pre_trainadv
 *
 *  08.3 : : Advanced pre EI/EDI training
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return  any errlogs to istep 
 *
 */
void*    call_fabric_pre_trainadv( void    *io_pArgs );



/**
 *  @brief   fabric_io_run_training
 *
 *           Run training on internal buses
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return  any errlogs to istep 
 *
 */
void*    call_fabric_io_run_training( void    *io_pArgs );



/**
 *  @brief   fabric_post_trainadv
 *
 *           Advanced post EI/EDI training
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return  any errlogs to istep 
 *
 */
void*    call_fabric_post_trainadv( void    *io_pArgs );



/**
 *  @brief   proc_smp_link_layer
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return  any errlogs to istep
 *
 */
void*   call_proc_smp_link_layer( void    *io_pArgs );



/**
 *  @brief   host_startprd_pbus
 *
 *           Load PRD for powerbus domain
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return  any errlogs to istep 
 *
 */
void*    call_host_startprd_pbus( void    *io_pArgs );



/**
 *  @brief   host_attnlisten_proc
 *
 *           Start listening for attentions
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return  any errlogs to istep 
 *
 */
void*    call_host_attnlisten_proc( void    *io_pArgs );



/**
 *  @brief   proc_fab_iovalid
 *
 *           Lower functional fences on local SMP
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return  any errlogs to istep 
 *
 */
void*    call_proc_fab_iovalid( void    *io_pArgs );


};   // end namespace

#endif

