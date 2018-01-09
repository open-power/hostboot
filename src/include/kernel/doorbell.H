/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/kernel/doorbell.H $                               */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2018                        */
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
#ifndef __KERNEL_DOORBELL_H
#define __KERNEL_DOORBELL_H

/** doorbell_broadcast
 *
 *  Broadcast a doorbell exception to all threads on the same core.
 */
void doorbell_broadcast();

/** doorbell_clear
 *
 *  Clears a pending doorbell from the executing thread, so that the
 *  exception is no longer asserted.
 */
void doorbell_clear();

/** Send a doorbell exception to the given pir
 *
 *  @param i_pir - PIR to send doorbell exception to
 */
void doorbell_send(uint64_t i_pir);

/** Initiate a thread/core wakeup using a doorbell
 *
 *  @param i_pir - PIR to send doorbell to wakeup
 */
void send_doorbell_wakeup(uint64_t i_pir);

/** Send an IPC message using a doorbell
 *
 * @param i_pir - PIR to send IPC message to
 */
void send_doorbell_ipc(uint64_t i_pir);

enum
{
    _DOORBELL_MSG_TYPE = 0x0000000028000000, /// Comes from the ISA.
};

#endif
