//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/hwpf/hwp/load_payload/load_payload.H $
//
//  IBM CONFIDENTIAL
//
//  COPYRIGHT International Business Machines Corp. 2012
//
//  p1
//
//  Object Code Only (OCO) source materials
//  Licensed Internal Code Source Materials
//  IBM HostBoot Licensed Internal Code
//
//  The source code for this program is not published or other-
//  wise divested of its trade secrets, irrespective of what has
//  been deposited with the U.S. Copyright Office.
//
//  Origin: 30
//
//  IBM_PROLOG_END

#ifndef  __LOAD_PAYLOAD_LOAD_PAYLOAD_H
#define  __LOAD_PAYLOAD_LOAD_PAYLOAD_H

/**
 *  @file load_payload.H
 *
 *  Load Payload
 *
 *  All of the following routines are "named isteps" - they are invoked as
 *  tasks by the @ref IStepDispatcher.
 *
 *  *****************************************************************
 *  THIS FILE WAS GENERATED ON 2012-04-11:1612
 *  *****************************************************************
 *
 */

 /*  @tag isteplist
 *  @docversion     v1.01 (03/26/12)
 *  @istepname      load_payload
 *  @istepnum       20
 *  @istepdesc      Load Payload
 *
 *  @{
 *      @substepnum     1
 *      @substepname    host_load_payload
 *      @substepdesc    : Load payload
 *          @target_sched   serial
 *  @}
 *
 */

/******************************************************************************/
// Includes
/******************************************************************************/
#include    <stdint.h>

namespace   LOAD_PAYLOAD
{



/**
 *  @brief   host_load_payload
 *
 *  20.1 : : Load payload
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return  none
 *
 */
void    call_host_load_payload( void    *io_pArgs );


};   // end namespace

#endif

