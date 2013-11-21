/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/establish_system_smp/establish_system_smp.H $ */
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
 *  HWP_IGNORE_VERSION_CHECK
 *
 */

 /*  @tag isteplist
 *  @docversion     v1.35 (04/11/13)
 *  @istepname      establish_system_smp
 *  @istepnum       18
 *  @istepdesc      Establish System SMP
 *
 *  @{
 *      @substepnum     12
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
 *  @brief   structure to hold iovalid processing data
 *
 */
    struct iovalid_msg {
        uint32_t               size;       //!Data length in bytes
        uint16_t               type;       //! IPL/CCM type message
        uint16_t               count;      //! Number of drawer HUIDs in data
        TARGETING::EntityPath drawers[0];  //! Place holder for data
    };

 /**
 *  enum used for sending messages within establishing system smp
 */
    enum
    {
        HOST_COALESCE_TIMER_MSG =   0xA1,
    };

/**
 *  @brief   host_coalesce_host
 *
 *           Create single host image
 *
 *  param[in,out] io_pMsg - input message buffer
 *                          also used for response message to FSP
 *
 *  return any errlogs to istep
 *
 */
errlHndl_t call_host_coalesce_host( );

/**
 *  @brief   host_sys_fab_iovalid_processing
 *
 *           Do hostboot side processing for fsp istep
 *           sys_proc_fab_iovalid
 *
 *  param[in,out] io_pMsg - input message buffer with drawer info,
 *                          also used for response message to FSP
 *
 */
void host_sys_fab_iovalid_processing( msg_t* io_pMsg );

};   // end namespace

#endif

