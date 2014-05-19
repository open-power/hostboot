/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/activate_powerbus/activate_powerbus.H $      */
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

#ifndef  __ACTIVATE_POWERBUS_ACTIVATE_POWERBUS_H
#define  __ACTIVATE_POWERBUS_ACTIVATE_POWERBUS_H

/**
 *  @file activate_powerbus.H
 *
 *  Activate PowerBus
 *
 *  All of the following routines are "named isteps" - they are invoked as
 *  tasks by the @ref IStepDispatcher.
 *
 *  *****************************************************************
 *  THIS FILE WAS GENERATED ON 2012-04-11:1607
 *  *****************************************************************
 *
 *  HWP_IGNORE_VERSION_CHECK
 *
 */

 /*  @tag isteplist
 *  @docversion     v1.28 (12/03/12)
 *  @istepname      activate_powerbus
 *  @istepnum       09
 *  @istepdesc      Activate PowerBus
 *
 *  @{
 *      @substepnum     1
 *      @substepname    proc_build_smp
 *      @substepdesc    : Integrate PgP Islands into SMP
 *          @target_sched   serial
 *  @}
 *  @{
 *      @substepnum     2
 *      @substepname    host_slave_sbe_update
 *      @substepdesc    : execute p8_customize_image
 *          @target_sched   serial
 *  @}
 *
 */

/******************************************************************************/
// Includes
/******************************************************************************/
#include    <stdint.h>

namespace   ACTIVATE_POWERBUS
{



/**
 *  @brief   proc_build_smp
 *
 *           Integrate PgP Islands into SMP
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return  any error logs to istep
 *
 */
void*   call_proc_build_smp( void    *io_pArgs );

/**
 *  @brief  host_slave_sbe_update 
 *
 *          Placeholder for secureboot where Hostboot must update
 *          SEEPROM because FSP cannot.
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return  any error logs to istep
 *
 */
void*   call_host_slave_sbe_update( void * io_pArgs );

};   // end namespace

#endif

