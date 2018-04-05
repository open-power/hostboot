/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/sbeio/runtime/sbeio_vital_attn.C $                    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018                             */
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
#include <sbeio/runtime/sbeio_vital_attn.H>

#include <runtime/interface.h>             // g_hostInterfaces
#include <util/runtime/rt_fwreq_helper.H>  // firmware_request_helper
#include <sbeio/sbeioreasoncodes.H>        // SBEIO_HANDLE_VITAL_ATTN

extern trace_desc_t* g_trac_sbeio;

using namespace ERRORLOG;
using namespace SBEIO;
using namespace TARGETING;

namespace RT_SBEIO
{
    //------------------------------------------------------------------------
    errlHndl_t vital_attn_inform_opal(TARGETING::TargetHandle_t i_procTarg,
                                      SBE_STATE i_sbeState)
    {
        errlHndl_t l_err = nullptr;
        do
        {
            if ((nullptr == g_hostInterfaces) ||
                (nullptr == g_hostInterfaces->firmware_request))
            {
                TRACFCOMP( g_trac_sbeio, ERR_MRK"handleVitalAttn: "
                          "Hypervisor firmware_request interface not linked");

                /*@
                 * @errortype
                 * @severity      ERRL_SEV_INFORMATIONAL
                 * @moduleid      SBEIO_HANDLE_VITAL_ATTN
                 * @reasoncode    SBEIO_RT_NULL_FIRMWARE_REQUEST_PTR
                 * @userdata1     HUID of target
                 * @userdata2     none
                 * @devdesc       Unable to inform OPAL of SBE failure
                 */
                 l_err = new ErrlEntry( ERRL_SEV_INFORMATIONAL,
                                        SBEIO_HANDLE_VITAL_ATTN,
                                        SBEIO_RT_NULL_FIRMWARE_REQUEST_PTR,
                                        get_huid(i_procTarg),
                                        0, false);

                l_err->addProcedureCallout(HWAS::EPUB_PRC_PHYP_CODE,
                            HWAS::SRCI_PRIORITY_HIGH);

                 break;
            }

            // Create the firmware_request request struct to send data
            hostInterfaces::hbrt_fw_msg l_req_fw_msg;
            uint64_t l_req_fw_msg_size = sizeof(l_req_fw_msg);
            memset(&l_req_fw_msg, 0, l_req_fw_msg_size);

            // Populate the firmware_request request struct with given data
            l_req_fw_msg.io_type =
                            hostInterfaces::HBRT_FW_MSG_TYPE_SBE_STATE;
            l_req_fw_msg.sbe_state.i_procId =
                             i_procTarg->getAttr<ATTR_HBRT_HYP_ID>();
            l_req_fw_msg.sbe_state.i_state = i_sbeState;

            // Create the firmware_request response struct to receive data
            hostInterfaces::hbrt_fw_msg l_resp_fw_msg;
            uint64_t l_resp_fw_msg_size = sizeof(l_resp_fw_msg);
            memset(&l_resp_fw_msg, 0, l_resp_fw_msg_size);

            // Make the firmware_request call
            l_err = firmware_request_helper(l_req_fw_msg_size,
                                            &l_req_fw_msg,
                                            &l_resp_fw_msg_size,
                                            &l_resp_fw_msg);
        }
        while(0);

        return l_err;
    } // end errlHndl_t vital_attn_inform_opal(...)

}  // end namespace RT_SBEIO
