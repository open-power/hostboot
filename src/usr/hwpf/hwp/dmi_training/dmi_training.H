/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/dmi_training/dmi_training.H $                */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2014              */
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
#ifndef  __DMI_TRAINING_DMI_TRAINING_H
#define __DMI_TRAINING_DMI_TRAINING_H
/**
 *  @file dmi_training.H
 *
 *  All of the following routines are "named isteps" - they are invoked as
 *  tasks by the @ref IStepDispatcher.
 *
 *  HWP_IGNORE_VERSION_CHECK
 *
 */

/*  @tag isteplist
 *  @docversion     v1.18 (12/03/12)
 *  @istepname      dmi_training
 *  @istepnum       11
 *  @istepdesc      DMI Training
 *
 *  @{
 *      @substepnum     1
 *      @substepname    mss_getecid
 *      @substepdesc    : Read out ECID from all centaur chips
 *          @target_sched   serial
 *  @}
 *  @{
 *      @substepnum     2
 *      @substepname    proc_dmi_scominit
 *      @substepdesc    : DMI Scom setup on P8 MCS
 *          @target_sched   serial
 *  @}
 *  @{
 *      @substepnum     3
 *      @substepname    dmi_scominit
 *      @substepdesc    : Scom setup on centaur
 *          @target_sched   serial
 *  @}
 *  @{
 *      @substepnum     4
 *      @substepname    dmi_erepair
 *      @substepdesc    : Restore EDI Bus eRepair data
 *          @target_sched   serial
 *  @}
 *  @{
 *      @substepnum     5
 *      @substepname    dmi_io_dccal
 *      @substepdesc    : Calibrate DMI interfaces
 *          @target_sched   serial
 *  @}
 *  @{
 *      @substepnum     6
 *      @substepname    dmi_pre_trainadv
 *      @substepdesc    : Advanced pre DMI training
 *          @target_sched   serial
 *  @}
 *  @{
 *      @substepnum     7
 *      @substepname    dmi_io_run_training
 *      @substepdesc    : Run training on MC buses
 *          @target_sched   serial
 *  @}
 *  @{
 *      @substepnum     8
 *      @substepname    dmi_post_trainadv
 *      @substepdesc    : Advanced post DMI training
 *          @target_sched   serial
 *  @}
 *  @{
 *      @substepnum     9
 *      @substepname    proc_cen_framelock
 *      @substepdesc    : Initialize EDI Frame
 *          @target_sched   serial
 *  @}
 *  @{
 *      @substepnum     10
 *      @substepname    host_startprd_dmi
 *      @substepdesc    : Load PRD for DMI domain
 *          @target_sched   serial
 *  @}
 *  @{
 *      @substepnum     11
 *      @substepname    host_attnlisten_cen
 *      @substepdesc    : Start listening for attentions
 *          @target_sched   serial
 *  @}
 *  @{
 *      @substepnum    12
 *      @substepname    cen_set_inband_addr
 *      @substepdesc    : Set the Inband base addresses
 *          @target_sched   serial
 *  @}
 *
 */


/******************************************************************************/
// Includes
/******************************************************************************/
#include    <stdint.h>


namespace   DMI_TRAINING
{

/**
 * @brief   mss_getecid
 *
 *          Read out ECID of all centaur chips
 *
 *  param[in,out] io_pArgs  -   (normally) a pointer to a TaskArgs struct,
 *                               or NULL.
 *  return  any error logs to istep
 *
 */
void*    call_mss_getecid( void * io_pArgs );

/**
 * @brief   dmi_attr_update
 *
 *  Stub HWP to allow FW to override attributes programmatically
 *
 *
 *  param[in,out] io_pArgs  -   (normally) a pointer to a TaskArgs struct,
 *                               or NULL.
 *  return  any error logs to istep
 *
 */

void * call_dmi_attr_update( void * io_pArgs );

/**
 * @brief   proc_dmi_scominit
 *
 *          DMI Scom setup on P8 MCS
 *
 *  param[in,out] io_pArgs  -   (normally) a pointer to a TaskArgs struct,
 *                               or NULL.
 *  return  any error logs to istep
 *
 */
void*    call_proc_dmi_scominit( void * io_pArgs );


/**
 * @brief   dmi_scominit
 *
 *          Scom setup on centaur
 *
 *  param[in,out] io_pArgs  -   (normally) a pointer to a TaskArgs struct,
 *                               or NULL.
 *  return  any error logs to istep
 *
 */
void*    call_dmi_scominit( void * io_pArgs );


/**
 *  @brief   dmi_erepair
 *
 *           Restore EDI Bus eRepair data
 *
 *  param[in,out] io_pArgs  -   (normally) a pointer to a TaskArgs struct,
 *                               or NULL.
 *  return  any error logs to istep
 *
 */
void*    call_dmi_erepair( void * io_pArgs );


/**
 *  @brief   dmi_io_dccal
 *
 *           Calibrate DMI interfaces
 *
 *  param[in,out] io_pArgs  -   (normally) a pointer to a TaskArgs struct,
 *                               or NULL.
 *  return  any error logs to istep
 *
 */
void*    call_dmi_io_dccal( void * io_pArgs );


/**
 *  @brief   dmi_pre_trainadv
 *
 *           Advanced pre DMI training
 *
 *  param[in,out] io_pArgs  -   (normally) a pointer to a TaskArgs struct,
 *                               or NULL.
 *  return  any error logs to istep
 *
 */
void*    call_dmi_pre_trainadv( void * io_pArgs );


/**
 *  @brief   dmi_io_run_training
 *
 *           Run training on MC buses
 *
 *  param[in,out] io_pArgs  -   (normally) a pointer to a TaskArgs struct,
 *                               or NULL.
 *  return  any error logs to istep
 *
 */
void*    call_dmi_io_run_training( void * io_pArgs );


/**
 *  @brief   dmi_post_trainadv
 *
 *           Advanced post DMI training
 *
 *  param[in,out] io_pArgs  -   (normally) a pointer to a TaskArgs struct,
 *                               or NULL.
 *  return  any error logs to istep
 *
 */
void*    call_dmi_post_trainadv( void * io_pArgs );


/**
 *  @brief  proc_cen_framelock
 *
 *          Initialize EDI Frame
 *
 *  param[in,out] io_pArgs  -   (normally) a pointer to a TaskArgs struct,
 *                               or NULL.
 *  return  any error logs to istep
 *
 */
void*    call_proc_cen_framelock( void *io_pArgs );


/**
 *  @brief   host_startprd_dmi
 *
 *           Load PRD for DMI domain
 *
 *  param[in,out] io_pArgs  -   (normally) a pointer to a TaskArgs struct,
 *                               or NULL.
 *  return  any error logs to istep
 *
 */
void*    call_host_startprd_dmi( void * io_pArgs );


/**
 *  @brief   host_attnlisten_cen
 *
 *           Start listening for attentions
 *
 *  param[in,out] io_pArgs  -   (normally) a pointer to a TaskArgs struct,
 *                               or NULL.
 *  return  any error logs to istep
 *
 */
void*    call_host_attnlisten_cen( void * io_pArgs );


/**
 *  @brief   cen_set_inband_addr
 *
 *           Set the Inband base addresses
 *
 *  param[in,out] io_pArgs  -   (normally) a pointer to a TaskArgs struct,
 *                               or NULL.
 *  return  any error logs to istep
 *
 */
void*    call_cen_set_inband_addr( void * io_pArgs );


};   // end namespace

#endif
