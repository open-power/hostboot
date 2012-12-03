/*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/usr/hwpf/hwp/dram_initialization/dram_initialization.H $
 *
 *  IBM CONFIDENTIAL
 *
 *  COPYRIGHT International Business Machines Corp. 2012
 *
 *  p1
 *
 *  Object Code Only (OCO) source materials
 *  Licensed Internal Code Source Materials
 *  IBM HostBoot Licensed Internal Code
 *
 *  The source code for this program is not published or other-
 *  wise divested of its trade secrets, irrespective of what has
 *  been deposited with the U.S. Copyright Office.
 *
 *  Origin: 30
 *
 *  IBM_PROLOG_END_TAG
 */
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
 *      @substepname    mss_scrub
 *      @substepdesc    : Start background scrub
 *          @target_sched   serial
 *  @}
 *  @{
 *      @substepnum     5
 *      @substepname    mss_thermal_init
 *      @substepdesc    : Initialize the thermal sensor
 *          @target_sched   serial
 *  @}
 *  @{
 *      @substepnum     6
 *      @substepname    proc_setup_bars
 *      @substepdesc    : Setup Memory BARs
 *          @target_sched   serial
 *  @}
 *  @{
 *      @substepnum     7
 *      @substepname    proc_pcie_config
 *      @substepdesc    : Configure the PHBs
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
