/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep18/establish_system_smp.H $               */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2018                        */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
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
#ifndef  __ESTABLISH_SYSTEM_SMP_ESTABLISH_SYSTEM_SMP_H
#define  __ESTABLISH_SYSTEM_SMP_ESTABLISH_SYSTEM_SMP_H

/**
 *  @file establish_system_smp.H
 *
 *  Establish System SMP
 *
 */

 /*
 *  @{
 *      @substepnum     7
 *      @substepname    host_sys_fab_iovalid_processing
 *      @substepdesc    : Lower functional fences on sys SMP
 *          @target_sched   serial
 *  @}
 *  @{
 *      @substepnum     10
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

    /******************************************************************************/
    // Globals/Constants
    /******************************************************************************/
    constexpr uint8_t HB_COALESCE_WAITING_FOR_MSG = 0x0;
    constexpr uint8_t HB_COALESCE_MSG_DONE = 0x1;
    constexpr uint32_t MAX_TIME_ALLOWED_MS = 10000;
    constexpr uint8_t NUMBER_OF_POSSIBLE_DRAWERS = 8;
    constexpr uint8_t CONTINUE_WAIT_FOR_MSGS = 0x2;
    constexpr uint8_t TIME_EXPIRED=0x3;

    /**
    *  @brief   structure to hold iovalid processing data
    *
    */
    struct iovalid_msg {
        uint32_t               size;       //!Data length in bytes
        uint16_t               type;       //! IPL/CCM type message
        uint16_t               count;      //! Number of drawers in data
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
    *  Create single host image
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
    *  Do hostboot side processing for fsp istep
    *  sys_proc_fab_iovalid
    *
    *  param[in,out] io_pMsg - input message buffer with drawer info,
    *                          also used for response message to FSP
    *  return NULL
    */
    void* host_sys_fab_iovalid_processing( void* io_pMsg );

    /**
    * @brief  enableSpecialWakeup on all functional cores after
    *         winkle wakeup.
    *
    * @return error log handle
    */
    errlHndl_t enableSpecialWakeup();

    /**
    * @brief  block interrupts on all functional cores
    *
    * @return error log handle
    */
    errlHndl_t blockInterrupts();
};   // end namespace

#endif

