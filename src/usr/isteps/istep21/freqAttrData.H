/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep21/freqAttrData.H $                       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2021                        */
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
#ifndef FREQATTRDATA_H
#define FREQATTRDATA_H

#include <stdint.h>
#include <builtins.h>
#include <limits.h>
#include <errl/errlentry.H>
#include <kernel/intmsghandler.H>
#include <sys/msg.h>
#include <sys/misc.h>
#include <sys/time.h>
#include <sys/internode.h>

#include <map>
#include <algorithm>
#include <arch/pirformat.H>

namespace ISTEP_21
{
    /******************************************************************************/
    // Globals/Constants
    /******************************************************************************/
    constexpr uint8_t  HB_FREQ_ATTR_DATA_WAITING_FOR_MSG = 0x0;
    constexpr uint8_t  HB_FREQ_ATTR_DATA_MSG_DONE = 0x1;
    constexpr uint32_t MAX_TIME_ALLOWED_MS = 10000;
    constexpr uint8_t  CONTINUE_WAIT_FOR_MSGS = 0x2;
    constexpr uint8_t  TIME_EXPIRED=0x3;

    /**
    *  enum used for sending messages within sendFreqAttrData
    */
    enum
    {
        HB_FREQ_ATTR_DATA_TIMER_MSG = 0xA3,
    };

    /**
    *  @brief   structure to hold frequency attribute data
    *
    */
    typedef union
    {
        struct{
            uint16_t nominalFreq;    //ATTR_NOMINAL_FREQ_MHZ
            uint16_t floorFreq;      //ATTR_FREQ_FLOOR_MHZ
            uint16_t ceilingFreq ;   //ATTR_FREQ_CORE_CEILING_MHZ
            uint16_t ultraTurboFreq; //ATTR_ULTRA_TURBO_FREQ_MHZ
            uint16_t turboFreq;      //ATTR_FREQ_CORE_MAX
            uint16_t nestFreq;       //ATTR_FREQ_PB_MHZ
            uint16_t powerModeNom;   //ATTR_SOCKET_POWER_NOMINAL
            uint16_t powerModeTurbo; //ATTR_SOCKET_POWER_TURBO
        };

        struct {
            uint64_t freqData1;
            uint64_t freqData2;
        };

    }freq_data;



    /**
     * @brief Timer function for safe error handling in sendFreqAttrData
     *
     * @description Used inside the sendFreqAttrData() to wait for
     *  responses from other nodes
     * @param[in]  i_msgQPtr -- Pointer to the Message Queue to wait for messages
     *
     * @return void
     */
    void* sendFreqAttrData_timer(void* i_msgQPtr);

    /**
     * @brief Sends the frequency attributes with that of master HB
     *
     * @description On multi-drawer system call_host_start_payload invokes this method
     * @param[in]  None
     *
     * @return errlHndl_t
     */
    errlHndl_t sendFreqAttrData();

     /**
     * @brief Checks the frequency attributes with that of master HB
     *
     * @description Invoked by IpcSp for the message type IPC_FREQ_ATTR_DATA
     * @param[in]   uint64_t i_pstate0 frequency attribute
     *
     * @return errlHndl_t
     */
    errlHndl_t callCheckFreqAttrData(const uint64_t i_pstate0);

};

#endif
