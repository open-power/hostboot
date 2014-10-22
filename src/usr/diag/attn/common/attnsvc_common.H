/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/attn/common/attnsvc_common.H $                   */
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
#ifndef __ATTN_ATTNSVCCOMMON_H
#define __ATTN_ATTNSVCCOMMON_H

/**
 * @file attnsvc_common.H
 *
 * @brief HBATTN common service class definition.
 */

#include "common/attnfwd.H"
#include "common/attnlist.H"

namespace ATTN
{

/**
 * @brief Service Host attention handler background service class definition.
 */
class ServiceCommon
{
    public:

        /**
         * @brief ConfigureMode
         *
         * Up or down for parameter for configure methods.
         */
        enum ConfigureMode
        {
            UP, DOWN,
        };

        /**
         * @brief ctor
         */
        ServiceCommon();

        /**
         * @brief dtor
         */
        ~ServiceCommon();

        /**
         * @brief processAttentions process interrupt task wakeup
         *
         * call prd to analyze attentions
         *
         * @param[i_procs] procs to check for attentions behind
         *
         * @post attentions analyzed by prd.  attentions cleared by prd unmasked
         */
        void processAttentions(const TARGETING::TargetHandleList & i_procs);

        /**
         * @brief handles attentions on a proc
         *
         * call prd to analyze attentions if attentions exist
         *
         * @param[i_proc] proc to check for attentions behind
         *
         * @post attentions analyzed by prd.
         *
         * @retval[0] No error
         * @retval[!0] Unexpected error
         */
        errlHndl_t handleAttentions(const TARGETING::TargetHandle_t i_proc);

    protected:

        /**
         * @brief processAttnPreAck pre EOI interrupt service message
         *        processing
         *
         * Perform the interrupt service message processing steps that must
         * be done before EOI can be sent by the interrupt service.
         *
         * @post interrupt service message ready to be acknowledged
         *
         * @param[in] i_proc processor target handle
         */
        void processAttnPreAck(const TARGETING::TargetHandle_t i_proc);

        /**
         * @brief configureInterrupts enable or
         *   disable interrupts used by the ServiceCommon, on all
         *   functioning processors.
         *
         * @post ServiceCommon (un)hooked to/from interrupt ServiceCommon
         *   for local error and host interrupts.
         * @post Local error and host priority set(cleared).
         * @post Local error and host interrupts (un)masked at GFIR macro.
         *
         * @param[in] i_mode Up or down
         *
         * @retval[0] No error
         * @retval[!0] Unexpected error
         */
        errlHndl_t configureInterrupts(ConfigureMode i_mode);

        /**
         * @brief iv_mutex pendingAttentions protection
         */
        mutex_t iv_mutex;

    private:

        /**
         * @brief copy disabled
         */
        ServiceCommon(const ServiceCommon &);

        /**
         * @brief assignment disabled
         */
        ServiceCommon &operator=(const ServiceCommon &);

        /**
         * @brief AttnSvcTest Provide access to unit test.
         */
        friend class ::AttnSvcTest;
        friend class ::AttnProcTest;
        friend class ::AttnMemTest;
};
}
#endif
