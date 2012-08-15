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
 */

 /*  @tag isteplist
 *  @docversion     v1.08 (08/13/12)
 *  @istepname      dram_initialization
 *  @istepnum       14
 *  @istepdesc      Dram Initialization
 *
 *  @{
 *      @substepnum     1
 *      @substepname    host_startPRD_dram
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
 *
 */

namespace   DRAM_INITIALIZATION
{



/**
 *  @brief   host_startPRD_dram
 *
 *  14.1 : : Load PRD for DRAM domain
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return  none
 *
 */
void    call_host_startPRD_dram( void    *io_pArgs );



/**
 *  @brief   mss_extent_setup
 *
 *  14.2 : MSS Extent Setup
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return  none
 *
 */
void    call_mss_extent_setup( void    *io_pArgs );



/**
 *  @brief   mss_memdiag
 *
 *  14.3 : Mainstore Pattern Testing
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return  none
 *
 */
void    call_mss_memdiag( void    *io_pArgs );



/**
 *  @brief   mss_scrub
 *
 *  14.4 : : Start background scrub
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return  none
 *
 */
void    call_mss_scrub( void    *io_pArgs );



/**
 *  @brief   mss_thermal_init
 *
 *  14.5 : : Initialize the thermal sensor
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return  none
 *
 */
void    call_mss_thermal_init( void    *io_pArgs );



/**
 *  @brief   proc_setup_bars
 *
 *  14.6 : : Setup Memory BARs
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return  none
 *
 */
void    call_proc_setup_bars( void    *io_pArgs );



/**
 *  @brief   proc_pcie_config
 *
 *  14.7 : : Configure the PHBs
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return  none
 *
 */
void    call_proc_pcie_config( void    *io_pArgs );



/**
 *  @brief   proc_exit_cache_contained
 *
 *  14.8 : : Allow execution from memory
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return  none
 *
 */
void    call_proc_exit_cache_contained( void    *io_pArgs );


};   // end namespace

#endif
