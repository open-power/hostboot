/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/dram_initialization/dram_initialization.H $  */
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
#ifndef  __DRAM_INITIALIZATION_DRAM_INITIALIZATION_H
#define  __DRAM_INITIALIZATION_DRAM_INITIALIZATION_H

#include <errl/errlentry.H>

/**
 *  @file dram_initialization.H
 *
 *  Dram Initialization
 *
 *  All of the following routines are "named isteps" - they are invoked as
 *  tasks by the @ref IStepDispatcher.
 *
 *  *****************************************************************
 *  THIS FILE WAS GENERATED ON 2012-04-11:1608
 *  *****************************************************************
 *
 *  HWP_IGNORE_VERSION_CHECK
 *
 */

 /*  @tag isteplist
 *  @docversion     v1.28 (12/03/12)
 *  @istepname      dram_initialization
 *  @istepnum       14
 *  @istepdesc      Dram Initialization
 *
 *  @{
 *      @substepnum     1
 *      @substepname    host_startprd_dram
 *      @substepdesc    : Load PRD for DRAM domain
 *          @target_sched   serial
 *  @}
 *  @{
 *      @substepnum     2
 *      @substepname    mss_extent_setup
 *      @substepdesc    MSS Extent Setup
 *          @target_sched   serial
 *  @}
 *  @{
 *      @substepnum     3
 *      @substepname    mss_memdiag
 *      @substepdesc     Mainstore Pattern Testing
 *          @target_sched   serial
 *  @}
 *  @{
 *      @substepnum     4
 *      @substepname    mss_thermal_init
 *      @substepdesc    : Initialize the thermal sensor
 *          @target_sched   serial
 *  @}
 *  @{
 *      @substepnum     5
 *      @substepname    proc_pcie_config
 *      @substepdesc    : Configure the PHBs
 *          @target_sched   serial
 *  @}
 *  @{
 *      @substepnum     6
 *      @substepname    mss_power_cleanup
 *      @substepdesc    : Clean up any MCS/Centuars
 *          @target_sched   serial
 *  @}
 *  @{
 *      @substepnum     7
 *      @substepname    proc_setup_bars
 *      @substepdesc    : Setup Memory BARs
 *          @target_sched   serial
 *  @}
 *  @{
 *      @substepnum     8
 *      @substepname    proc_exit_cache_contained
 *      @substepdesc    : Allow execution from memory
 *          @target_sched   serial
 *  @}
 *  @{
 *      @substepnum     9
 *      @substepname    host_mpipl_service
 *      @substepdesc    : host_mpipl_service
 *          @target_sched   serial
 *  @}

 */

namespace   DRAM_INITIALIZATION
{


/**
 *  @brief   host_startprd_dram
 *
 *           Load PRD for DRAM domain
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return  pointer to any errlogs
 *
 */
void*    call_host_startprd_dram( void    *io_pArgs );


/**
 *  @brief   mss_extent_setup
 *
 *           MSS Extent Setup
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return  pointer to any errlogs
 *
 */
void*    call_mss_extent_setup( void    *io_pArgs );

/**
 *  @brief   mss_memdiag
 *
 *  Mainstore Pattern Testing
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return  pointer to any errlogs
 *
 */
void*   call_mss_memdiag( void    *io_pArgs );


/**
 *  @brief   mss_thermal_init
 *
 *           Initialize the thermal sensor
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return  pointer to any errlogs
 *
 */
void*    call_mss_thermal_init( void    *io_pArgs );

/**
 *  @brief   proc_pcie_config
 *
 *           Configure the PHBs
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return  pointer to any errlogs
 *
 */
void*    call_proc_pcie_config( void    *io_pArgs );

/**
 *  @brief   mss_power_cleanup
 *
 *           Clean up any MCS/Centaurs
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return  pointer to any errlogs
 *
 */
void*    call_mss_power_cleanup( void    *io_pArgs );


/**
 *  @brief   proc_setup_bars
 *
 *           Setup Memory BARs
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return  pointer to any errlogs
 *
 */
void*    call_proc_setup_bars( void    *io_pArgs );


/**
 *  @brief   proc_exit_cache_contained
 *
 *           Allow execution from memory
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return  pointer to any errlogs
 *
 */
void*    call_proc_exit_cache_contained( void    *io_pArgs );


/**
 *  @brief   host_mpipl_service
 *
 *           Perform MPIPL tasks
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return  pointer to any errlogs
 *
 *  NOTE: this step will only run as part of an mpipl,
 *        the istep dispatcher will not call this step for
 *        the normal ipl flow
 *
 */
void*   call_host_mpipl_service( void   *io_pArgs);

};   // end namespace

#endif
