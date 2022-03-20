/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/util/runtime/rt_fwreq_helper.H $              */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2010,2022                        */
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
#ifndef __RUNTIME_FWREQ_HELPER_H
#define __RUNTIME_FWREQ_HELPER_H

#include <errl/errlentry.H>     // errlHndl_t
#include <runtime/interface.h>  // hostInterfaces

/**
 * @brief This is a wrapper function for the
 *        hostInterfaces::firmware_request method.  This method
 *        will do the repetitious job of checking for errors,
 *        retry call if necessary and logging errors.
 * @details
 *   req_len bytes are sent to runtime firmware, and resp_len
 *   bytes received in response.
 *
 *   Both req and resp are allocated by the caller. If resp_len
 *   is not large enough to contain the full response, an error
 *   is returned.
 *
 * @param[in]  i_reqLen       length of request data
 * @param[in]  i_req          request data
 * @param[inout] o_respLen    in: size of request data buffer
 *                            out: length of response data
 * @param[in]  o_resp         response data
 * @return errlHndl_t         NULL if successful, otherwise a pointer
 *                            to the error log.
 * @see  src/include/runtime/interface.h for definition of call
 */
errlHndl_t
firmware_request_helper(uint64_t i_reqLen,
                        void *i_req,
                        uint64_t* o_respLen,
                        void *o_resp);

#if (defined(CONFIG_MCTP) || defined(CONFIG_MCTP_TESTCASES))
/**
 *  @brief Send the HBRT_FW_MSG_MCTP_BRIDGE_ENABLED message.
 *
 *  @param[in] i_mctpBridgeState new state - enable / disable
 *
 *  @param[in] i_resetMctpDepthCounter true = force recursive depth count to 1.
 *             Used when exiting from HBRT->PHYP and enabling the bridge. The
 *             next PHYP->HBRT entry will disable the bridge and decrement
 *             the counter so it is 0 at start of HBRT execution. Only allowed
 *             with i_mctpBridgeState = MCTP_BRIDGE_ENABLED.
 *
 *  @return void
 **/
void setMctpBridgeState(hostInterfaces::MCTP_BRIDGE_STATE_t i_mctpBridgeState,
                        const bool i_resetMctpDepthCounter = false);
#endif

// Template to wrap the runtimeInterfaces_t function pointers -> hb function
// connections. Adds MCTP_BRIDGE_DISABLE / MCTP_BRIDGE_ENABLE around all
// of the hb functions. Disabling the bridge prevents additional mctp
// traffic from flooding the queues while hb is handling the current request.
template<typename F>
struct wrap_function;

template<typename Ret, typename... Args>
struct wrap_function<Ret(Args...)>
{
    template<Ret(*original)(Args...)>
    static Ret wrapped(Args... args)
    {
        // wrap_begin_here
#if (defined(CONFIG_MCTP) || defined(CONFIG_MCTP_TESTCASES))
        setMctpBridgeState(hostInterfaces::MCTP_BRIDGE_DISABLED);
#endif

        Ret r = original(args...);

#if (defined(CONFIG_MCTP) || defined(CONFIG_MCTP_TESTCASES))
        // true = force g_MctpDepthCounter to 1 before returning control to phyp
        setMctpBridgeState(hostInterfaces::MCTP_BRIDGE_ENABLED, true);
#endif
        // wrap_end_here

        return r;
    }
};

// Same template to handle hb functions with no return value
template<typename... Args>
struct wrap_function<void(Args...)>
{
    template<void(*original)(Args...)>
    static void wrapped(Args... args)
    {
        // wrap_begin_here
#if (defined(CONFIG_MCTP) || defined(CONFIG_MCTP_TESTCASES))
        setMctpBridgeState(hostInterfaces::MCTP_BRIDGE_DISABLED);
#endif

        original(args...);

#if (defined(CONFIG_MCTP) || defined(CONFIG_MCTP_TESTCASES))
        // true = force g_MctpDepthCounter to 1 before returning control to phyp
        setMctpBridgeState(hostInterfaces::MCTP_BRIDGE_ENABLED, true);
#endif
        // wrap_end_here
    }
};

// Macro to simplify the runtimeInterfaces_t function pointer to
// hb function connection
#define DISABLE_MCTP_WRAPPER(X) wrap_function<decltype(X)>::wrapped<X>

#endif   // __RUNTIME_FWREQ_HELPER_H
