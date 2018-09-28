/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/ipmi/runtime/rt_ipmirp.C $                            */
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
/**
 * @file rt_ipmirp.C
 * @brief IPMI resource provider definition for runtime
 */

#include "../ipmirp.H"
#include "../ipmidd.H"
#include <ipmi/ipmi_reasoncodes.H>
#include <ipmi/ipmiif.H>

#include <config.h>
#include <sys/task.h>
#include <initservice/taskargs.H>
#include <initservice/initserviceif.H>
#include <sys/vfs.h>

#include <targeting/common/commontargeting.H>
#include <kernel/ipc.H>
#include <arch/ppc.H>
#include <errl/errlmanager.H>
#include <sys/time.h>
#include <sys/misc.h>
#include <errno.h>
#include <runtime/interface.h>

trace_desc_t * g_trac_ipmi;
TRAC_INIT(&g_trac_ipmi, IPMI_COMP_NAME, 6*KILOBYTE, TRACE::BUFFER_SLOW);

#define IPMI_TRAC(printf_string,args...) \
    TRACFCOMP(g_trac_ipmi,"rt: " printf_string,##args)

namespace IPMI
{
    static size_t g_max_buffer = 0;
    size_t max_buffer(void)
    {
        if (g_max_buffer == 0)
        {
            TARGETING::Target * sys = NULL;
            TARGETING::targetService().getTopLevelTarget( sys );
            if (sys)
            {
                g_max_buffer = sys->getAttr
                                <TARGETING::ATTR_IPMI_MAX_BUFFER_SIZE>();
                IPMI_TRAC( INFO_MRK"getAttr(IPMI_MAX_BUFFER_SIZE) = %d",
                        g_max_buffer);
            }
            else
            {
                IPMI_TRAC( ERR_MRK"IPMI_MAX_BUFFER_SIZE not available" );
            }
        }
        return g_max_buffer;
    }

    ///
    /// @brief  Synchronus message send
    ///
    errlHndl_t sendrecv(const IPMI::command_t& i_cmd,
                        IPMI::completion_code& o_completion_code,
                        size_t& io_len, uint8_t*& io_data)
    {
        errlHndl_t err = NULL;
        int rc = 0;

        // if the buffer is too large this is a programming error.
        assert(io_len <= max_buffer());

        uint8_t netfn = i_cmd.first >> 2; //remove embedded LUN
        IPMI_TRAC("calling sync %x:%x  len=%d",
            netfn, i_cmd.second, io_len);

        if(g_hostInterfaces && g_hostInterfaces->ipmi_msg)
        {
            size_t l_len = max_buffer(); // max size the BMC can return
            uint8_t *l_data = new uint8_t[l_len];

            rc = g_hostInterfaces->ipmi_msg(
                        netfn, i_cmd.second,
                        io_data, io_len,
                        l_data, &l_len);

            if(rc)
            {
                IPMI_TRAC(ERR_MRK
                          "Failed sending ipmi msg (%x:%x) to bmc rc: %d. ",
                          i_cmd.first, i_cmd.second, rc);

                /*@
                 * @errortype           ERRL_SEV_UNRECOVERABLE
                 * @moduleid            IPMI::MOD_IPMIRT
                 * @reasoncode          IPMI::RC_INVALID_SENDRECV
                 * @userdata1[0:31]     rc from ipmi_msg()
                 * @userdata1[32:46]    netfn of failing msg
                 * @userdata1[47:63]    cmd of failing msg
                 * @userdata2           length of failing msg
                 * @devdesc             ipmi_msg() failed
                 * @custdesc            Firmware error
                 */
                err = new ERRORLOG::ErrlEntry(
                            ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                            IPMI::MOD_IPMIRT,
                            IPMI::RC_INVALID_SENDRECV,
                            TWO_UINT32_TO_UINT64(rc,
                                TWO_UINT16_TO_UINT32(netfn, i_cmd.second)),
                            io_len,
                            true);
                err->collectTrace(IPMI_COMP_NAME);
                delete[] io_data;
                io_data = NULL;
                io_len = 0;
            }
            else
            {
                // clean up the memory for the caller
                o_completion_code =
                  static_cast<IPMI::completion_code>(l_data[0]);

                // now need to create the buffer to return
                io_len = l_len - 1; // get rid of the completion_code
                delete[] io_data;
                io_data = new uint8_t[io_len];
                memcpy(io_data, &l_data[1], io_len); // data after CC
            }
            delete[] l_data;
        }
        else
        {
            IPMI_TRAC(ERR_MRK
                      "Host interfaces not initialized; ipmi msg not sent. ");
        }

        return err;
    } // sendrecv

    /*
     * @brief       Asynchronus message send
     *
     * @param[in]   i_cmd,  the command we're sending
     * @param[in]   i_len,  the length of the data
     * @param[in]   i_data, the data we're sending
     * @param[in]   i_type, the type of message we're sending
     *
     */
    errlHndl_t send(const IPMI::command_t& i_cmd,
                    size_t i_len, uint8_t* i_data,
                    IPMI::message_type i_type)
    {
        IPMI::completion_code l_cc = IPMI::CC_UNKBAD;

        // We are calling a synchronous send in an asynchronous function
        // This is needed to enable asynchronous message sending before
        // runtime. A message should be synchronous during runtime, but
        // by ignoring the cc returned and clearing the data, we're making
        // a synchronous function "asynchronous".
        errlHndl_t l_err = sendrecv(i_cmd,l_cc,i_len,i_data);

        if(i_data != NULL)
        {
            delete i_data;
        }

        return l_err;
    }

};
