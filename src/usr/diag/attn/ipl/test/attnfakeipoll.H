/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/attn/hostboot/test/attnfakeipoll.H $             */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014                             */
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
#ifndef __TEST_ATTNFAKEIPOLL_H
#define __TEST_ATTNFAKEIPOLL_H

/**
 * @file attnfakeipoll.H
 *
 * @brief HBATTN fake Ipoll mask register class definitions.
 */

#include "attnfakeelement.H"

namespace ATTN
{

/**
 * @brief FakeIpoll Fake ipoll class definition.
 *
 * Attach logic to Ipoll and associated GFIR register modifications.
 */
class FakeIpoll : public FakeReg
{
    public:

        /**
         * @brief ctor
         *
         * @param[in] i_type The bit in the ipoll mask register to implement.
         * @param[in] i_presenter The presenter to which interrupts should
         *                be requested.
         */
        FakeIpoll(
                uint64_t i_type,
                FakePresenter & i_presenter);

        /**
         * @brief dtor
         */
        ~FakeIpoll() {}

        /**
         * @brief install
         *
         * Register this object with the provided system for
         * the appropriate callbacks.
         *
         * @param[in] i_system The system in which to register callbacks.
         */
        void install(FakeSystem & i_system);


        /**
         * @brief processPutReg Process modified register content.
         *
         * Fake implemenation of Ipoll mask.  Generates interrupts when
         * appropriate.
         *
         * @param[in] i_sys System that modified register content.
         * @param[in] i_target Target whose registers were modified.
         * @param[in] i_address Address of register that was modified.
         * @param[in] i_new Register content after modification.
         * @param[in] i_old Register content before modification.
         *
         * @retval[0] No error occurred.
         * @retval[!0] Unexpected error occurred.
         */
        errlHndl_t processPutReg(
                FakeSystem & i_sys,
                TARGETING::TargetHandle_t i_target,
                uint64_t i_address,
                uint64_t i_new,
                uint64_t i_old);

    private:

        /**
         * @brief processEoi Process end of interrupt.
         *
         * Generates interrupts when appropriate.
         *
         * @param[in] i_sys System associated with the interrupt.
         * @param[in] i_source Target proc that generated the interrupt.
         * @param[in] i_type Interrupt type of generated interrupt.
         */
        void processEoi(
                FakeSystem & i_sys,
                TARGETING::TargetHandle_t i_source,
                MessageType i_type);

        /**
         * @brief callback FakePresenter EOI callback.
         *
         * Forwards to processEoi on ipoll instance that generated
         * the interrupt.
         *
         * @param[in] i_source Target proc that generated the interrupt.
         * @param[in] i_type Interrupt type of generated interrupt.
         * @param[in] i_properties pointers to ipoll and system instances.
         */
        static void callback(
                TARGETING::TargetHandle_t i_source,
                MessageType i_type,
                void * i_properties);

        /**
         * @brief interrupt FakePresenter interrupt wrapper.
         *
         * @param[in] i_sys System associated with the interrupt.
         * @param[in] i_source Target proc that generated the interrupt.
         * @param[in] i_type Interrupt type of generated interrupt.
         */
        void interrupt(
                FakeSystem & i_system,
                TARGETING::TargetHandle_t i_source,
                MessageType i_type);

        /**
         * @brief iv_address Address of register to monitor for interrupt
         * condition.
         */
        uint64_t iv_address;

        /**
         * @brief iv_gfirbits Filter watched bits in monitored register.
         */
        uint64_t iv_gfirbits;

        /**
         * @brief iv_ipollbits Ipoll mask bit being implemented.
         */
        uint64_t iv_ipollbits;

        /**
         * @brief iv_presenter Presenter from which interrupts should be
         * requested.
         */
        FakePresenter * iv_presenter;
};
}
#endif
