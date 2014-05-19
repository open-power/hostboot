/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/core_activate/core_activate.H $              */
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
#ifndef  __CORE_ACTIVATE_CORE_ACTIVATE_H
#define  __CORE_ACTIVATE_CORE_ACTIVATE_H

/**
 *  @file core_activate.H
 *
 *  Core Activate
 *
 *  All of the following routines are "named isteps" - they are invoked as
 *  tasks by the @ref IStepDispatcher.
 *
 *  *****************************************************************
 *  THIS FILE WAS GENERATED ON 2012-04-11:1609
 *  *****************************************************************
 *
 *  HWP_IGNORE_VERSION_CHECK
 *
 */

 /*  @tag isteplist
 *  @docversion     v1.28 (12/03/12)
 *  @istepname      core_activate
 *  @istepnum       16
 *  @istepdesc      Core Activate
 *
 *  @{
 *      @substepnum     1
 *      @substepname    host_activate_master
 *      @substepdesc    : Activate master core
 *          @target_sched   serial
 *  @}
 *  @{
 *      @substepnum     2
 *      @substepname    host_activate_slave_cores
 *      @substepdesc    : Activate slave cores
 *          @target_sched   serial
 *  @}
 *  @{
 *      @substepnum     3
 *      @substepname    mss_scrub
 *      @substepdesc    : Start background scrub
 *          @target_sched   serial
 *  @}
 *  @{
 *      @substepnum     4
 *      @substepname    host_ipl_complete
 *      @substepdesc    : Notify FSP drawer ipl complete
 *       *          @target_sched   serial
 *  @}
 *
 */

/******************************************************************************/
// Includes
/******************************************************************************/
#include    <stdint.h>

namespace   CORE_ACTIVATE
{



/**
 *  @brief   host_activate_master
 *
 *           Activate master core
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return  any error logs to istep
 *
 */
void*    call_host_activate_master( void    *io_pArgs );



/**
 *  @brief   host_activate_slave_cores
 *
 *           Activate slave cores
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return  any error logs to istep
 *
 */
void*    call_host_activate_slave_cores( void    *io_pArgs );


/**
 *  @brief   mss_scrub
 *
 *           Start background scrub
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return  pointer to any errlogs
 *
 */
void*    call_mss_scrub( void    *io_pArgs );


/**
 *  @brief   host_ipl_complete
 *
 *           Notify FSP drawer ipl complete
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return  any error logs to istep
 *
 */
void*    call_host_ipl_complete( void    *io_pArgs );

};   // end namespace

#endif

