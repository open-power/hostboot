/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/mc_config/mc_config.H $                      */
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
#ifndef  __MC_CONFIG_MC_CONFIG_H
#define  __MC_CONFIG_MC_CONFIG_H

/**
 *  @file mc_config.H
 *
 *  Step 12 MC Config
 *
 *  All of the following routines are "named isteps" - they are invoked as
 *  tasks by the @ref IStepDispatcher.
 *
 *  *****************************************************************
 *  THIS FILE WAS GENERATED ON 2012-03-01:1032
 *  *****************************************************************
 *
 *  HWP_IGNORE_VERSION_CHECK
 *
 */

/*  @tag isteplist
 *  @docversion     v1.28 (12/03/12)
 *  @istepname      mc_config
 *  @istepnum       12
 *  @istepdesc      Step 12 MC Config
 *
 *  @{
 *      @substepnum     1
 *      @substepname    host_collect_dimm_spd
 *      @substepdesc    : Collect Master dimm SPD
 *      @target_sched   serial
 *  @}
 *  @{
 *      @substepnum     2
 *      @substepname    mss_volt
 *      @substepdesc    : Calc dimm voltage
 *      @target_sched   serial
 *  @}
 *  @{
 *      @substepnum     3
 *      @substepname    mss_freq
 *      @substepdesc    : Calc dimm frequency
 *      @target_sched   serial
 *  @}
 *  @{
 *      @substepnum     4
 *      @substepname    mss_eff_config
 *      @substepdesc    : Determine effective config
 *      @target_sched   serial
 *  @}
 */
/******************************************************************************/
// Includes
/******************************************************************************/
#include    <stdint.h>
#include    <errl/errlentry.H>
namespace   MC_CONFIG
{



/**
 *  @brief   host_collect_dimm_spd
 *
 *           Collect Master dimm SPD
 *
 *  param[in,out] io_pArgs  -   (normally) a pointer to a TaskArgs struct,
 *                              or NULL.
 *  return  any error logs to istep
 *
 */
void*    call_host_collect_dimm_spd( void * io_pArgs );



/**
 *  @brief   mss_volt
 *
 *            Calc dimm voltage
 *
 *  param[in,out] io_pArgs  -   (normally) a pointer to a TaskArgs struct,
 *                              or NULL.
 *  return  any error logs to istep
 *
 */
void*   call_mss_volt( void * io_pArgs );



/**
 *  @brief   mss_freq
 *
 *           Calc dimm frequency
 *
 *  param[in,out] io_pArgs  -   (normally) a pointer to a TaskArgs struct,
 *                              or NULL.
 *  return  any error logs to istep
 *
 */
void*    call_mss_freq( void * io_pArgs );



/**
 *  @brief   mss_eff_config
 *
 *           Determine effective config
 *
 *  param[in,out] io_pArgs  -   (normally) a pointer to a TaskArgs struct,
 *                              or NULL.
 *  return  any error logs to istep
 *
 */
void*    call_mss_eff_config( void * io_pArgs );

/**
 *  @brief   mss_attr_update
 *
 *  Stub HWP to allow FW to override attributes programmatically
 *
 *  param[in,out] io_pArgs  -   (normally) a pointer to a TaskArgs struct,
 *                              or NULL.
 *  return  any error logs to istep
 *
 */
void*    call_mss_attr_update( void *io_pArgs );


};   // end namespace

#endif

