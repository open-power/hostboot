/*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/usr/hwpf/hwp/establish_system_smp/establish_system_smp.H $
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
#ifndef  __ESTABLISH_SYSTEM_SMP_ESTABLISH_SYSTEM_SMP_H
#define  __ESTABLISH_SYSTEM_SMP_ESTABLISH_SYSTEM_SMP_H

/**
 *  @file establish_system_smp.H
 *
 *  Establish System SMP
 *
 *  All of the following routines are "named isteps" - they are invoked as
 *  tasks by the @ref IStepDispatcher.
 *
 *  *****************************************************************
 *  THIS FILE WAS GENERATED ON 2012-04-11:1611
 *  *****************************************************************
 *
 */

 /*  @tag isteplist
 *  @docversion     v1.08 (08/13/12)
 *  @istepname      establish_system_smp
 *  @istepnum       18
 *  @istepdesc      Establish System SMP
 *
 *  @{
 *      @substepnum     8
 *      @substepname    host_coalesce_host
 *      @substepdesc    : Create single host image
 *          @target_sched   serial
 *  @}
 *
 */

/******************************************************************************/
// Includes
/******************************************************************************/
#include    <stdint.h>

namespace   ESTABLISH_SYSTEM_SMP
{



/**
 *  @brief   host_coalesce_host
 *
 *  18.8 : : Create single host image
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return  none
 *
 */
void    call_host_coalesce_host( void    *io_pArgs );



};   // end namespace

#endif

