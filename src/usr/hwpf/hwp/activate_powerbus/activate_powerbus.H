/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/activate_powerbus/activate_powerbus.H $      */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012                   */
/*                                                                        */
/* p1                                                                     */
/*                                                                        */
/* Object Code Only (OCO) source materials                                */
/* Licensed Internal Code Source Materials                                */
/* IBM HostBoot Licensed Internal Code                                    */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* Origin: 30                                                             */
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
 *  @docversion     v1.01 (03/26/12)
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
 *  09.1 : : Integrate PgP Islands into SMP
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return  none
 *
 */
void    call_proc_build_smp( void    *io_pArgs );


};   // end namespace

#endif

