/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/start_payload/start_payload.H $              */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2014              */
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

#ifndef  __START_PAYLOAD_START_PAYLOAD_H
#define  __START_PAYLOAD_START_PAYLOAD_H

/**
 *  @file start_payload.H
 *
 *  Start Payload
 *
 *  All of the following routines are "named isteps" - they are invoked as
 *  tasks by the @ref IStepDispatcher.
 *
 *  HWP_IGNORE_VERSION_CHECK
 *
 */

 /*  @tag isteplist
 *  @docversion     v1.28 (12/03/12)
 *  @istepname      start_payload
 *  @istepnum       21
 *  @istepdesc      Start Payload
 *
 *  @{
 *      @substepnum     1
 *      @substepname    host_runtime_setup
 *      @substepdesc    :
 *          @target_sched   serial
 *  @}
 *  @{
 *      @substepnum     2
 *      @substepname    host_verify_hdat
 *      @substepdesc    :  Start Payload
 *          @target_sched   serial
 *  @}
 *  @{
 *      @substepnum     3
 *      @substepname    host_start_payload
 *      @substepdesc    :  Start Payload
 *          @target_sched   serial
 *  @}
 *
 */

/******************************************************************************/
// Includes
/******************************************************************************/
#include    <stdint.h>

namespace   START_PAYLOAD
{

/**
 *  @brief   host_runtime_setup
 *
 *           Host Runtime Setup
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return  any error logs to istep
 *
 */
void*    call_host_runtime_setup( void    *io_pArgs );

/**
 *  @brief   host_verify_hdat
 *
 *           Secureboot verification of PHYP/AVP image load
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return  any error logs to istep
 *
 */
void*    call_host_verify_hdat( void    *io_pArgs );

/**
 *  @brief   host_start_payload
 *
 *           Start Payload
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return  any error logs to istep
 *
 */
void*    call_host_start_payload( void    *io_pArgs );

};   // end namespace

#endif

