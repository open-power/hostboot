/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/runtime/fakepayload.H $                               */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013,2014              */
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
#ifndef __RUNTIME_FAKEPAYLOAD_H
#define __RUNTIME_FAKEPAYLOAD_H

/** @file fakepayload.H
 *  @brief Interfaces for loading a 'fake' payload when a payload is not
 *         present.
 *
 *  The purpose of the fake payload is to be able to exercise the Hostboot
 *  shutdown path, even when there is not a real payload.
 *
 *  This payload will simply nap all of the processors.
 */
#include <stdint.h>
#include <arch/ppc.H>

namespace RUNTIME
{
    /** @class FakePayload
     *
     *  @brief Handles loading of the fake payload.
     *
     *  Places the payload into the area of memory determined by the
     *  PAYLOAD_BASE / PAYLOAD_ENTRY attributes.
     *
     *  @note This class does not perform verification that the addresses
     *        in the attributes are actually reasonable values.  It is assumed
     *        that attribute verification (ex. for SecureBoot) will be done
     *        elsewhere in a central place for all payloads.
     */
    class FakePayload
    {
        public:
                /** Load payload into memory. */
            static void load();
        private:
                /** The fake payload itself. */
            static void payload()
                __attribute__((no_instrument_function));

                /** Size of the payload (in bytes). */
            static const size_t size;

            /** @brief Size of memory to securely erase before loading
             *         the payload.
             *
             *  For SecureBoot we cannot trust anything the FSP has left in
             *  memory.  While we're loading a payload function into memory,
             *  the FSP had access to memory and could have loaded exception
             *  handlers.  We need to clear out at least this much space in
             *  order to ensure that none of the interrupt handlers could be
             *  residing in memory.
             */
            static const size_t safeClearArea;
    };
}


#endif
