/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/runtime/fakepayload.H $                               */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013                   */
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
