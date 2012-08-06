/*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/usr/hwpf/hwp/core_activate/core_activate.H $
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
 */

 /*  @tag isteplist
 *  @docversion     v1.01 (03/26/12)
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
 *  16.1 : : Activate master core
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return  none
 *
 */
void    call_host_activate_master( void    *io_pArgs );



/**
 *  @brief   host_activate_slave_cores
 *
 *  16.2 : : Activate slave cores
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return  none
 *
 */
void    call_host_activate_slave_cores( void    *io_pArgs );



/**
 *  @brief   host_ipl_complete
 *
 *  16.3 : : Notify FSP drawer ipl complete
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return  none
 *
 */
void    call_host_ipl_complete( void    *io_pArgs );

};   // end namespace

#endif

