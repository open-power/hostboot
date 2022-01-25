/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/vpd/runtime/rt_vpd.C $                                */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2022                        */
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

#include <trace/interface.H>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <errl/errludtarget.H>
#include <vpd/vpdreasoncodes.H>
#include <initservice/initserviceif.H>
#include <devicefw/driverif.H>
#include <runtime/interface.h>            // g_hostInterfaces
#include <util/runtime/rt_fwreq_helper.H> // firmware_request_helper
#include <targeting/common/util.H>
#include <util/runtime/util_rt.H>
#include <targeting/runtime/rt_targeting.H>
#include <initservice/initserviceif.H>

#include <eeprom/eepromif.H>

#include "vpd.H"
#include "mvpd.H"
#include "spd.H"

using namespace ERRORLOG;

extern trace_desc_t* g_trac_vpd;

// ------------------------
// Macros for unit testing
//#define TRACUCOMP(args...)  TRACFCOMP(args)
#define TRACUCOMP(args...)
//#define TRACSSCOMP(args...)  TRACFCOMP(args)
#define TRACSSCOMP(args...)

namespace VPD
{

// ------------------------------------------------------------------
// rtVpdInit
// ------------------------------------------------------------------
struct rtVpdInit
{
    rtVpdInit()
    {
        //Nothing to do atm...
    }
};
rtVpdInit g_rtVpdInit;

// ------------------------------------------------------------------
// sendMboxWriteMsg
// ------------------------------------------------------------------
errlHndl_t sendMboxWriteMsg ( size_t i_numBytes,
                              void * i_data,
                              TARGETING::Target * i_target,
                              VPD_MSG_TYPE i_type,
                              VpdWriteMsg_t& i_record )
{
    errlHndl_t l_err = nullptr;

    // Put the handle to the firmware messages out here
    // so it is easier to free later
    hostInterfaces::hbrt_fw_msg *l_req_fw_msg = nullptr;
    hostInterfaces::hbrt_fw_msg *l_resp_fw_msg = nullptr;

    TRACFCOMP( g_trac_vpd, INFO_MRK
               "sendMboxWriteMsg: Send msg to FSP to write VPD type %.8X, "
               "HUID=0x%X offset=0x%X",
               i_type,
               get_huid(i_target),
               i_record.offset );

    do
    {

        if(!INITSERVICE::spBaseServicesEnabled())
        {
            // No SP Base Services available at runtime then simply return
            TRACFCOMP( g_trac_vpd, ERR_MRK
                       "No SP Base Services available at runtime.")
            break;
        }

#ifdef __HOSTBOOT_RUNTIME
        // Check if an sbe VPD override is being applied.
        // If so, then don't write through to hardware
        if(EEPROM::allowVPDOverrides())
        {
            TRACFCOMP( g_trac_vpd, INFO_MRK "sendMboxWriteMsg: VPD updates to the FSP are currently disabled, "
                                            "only an update to the runtime cache was requested");
            break;
        }
#endif

        if ((nullptr == g_hostInterfaces) ||
            (nullptr == g_hostInterfaces->firmware_request))
        {
            TRACFCOMP(g_trac_vpd, ERR_MRK"sendMboxWriteMsg: "
                      "Hypervisor firmware_request interface not linked");

            /*@
             * @errortype
             * @severity         ERRL_SEV_INFORMATIONAL
             * @moduleid         VPD_SEND_MBOX_WRITE_MESSAGE
             * @reasoncode       VPD_RT_NULL_FIRMWARE_REQUEST_PTR
             * @userdata1        HUID of target
             * @userdata2        VPD message type
             * @devdesc          MBOX send not supported in HBRT
             */
             l_err= new ErrlEntry(ERRL_SEV_INFORMATIONAL,
                                  VPD_SEND_MBOX_WRITE_MESSAGE,
                                  VPD_RT_NULL_FIRMWARE_REQUEST_PTR,
                                  TARGETING::get_huid(i_target),
                                  i_type, true);
            break;
        }


        // Note - There is a potential collision on the I2C bus with
        //  the OCC code.  On FSP systems this is handled by the HWSV
        //  code.  On OP systems this is handled by OPAL.

        TARGETING::Target* pNode = nullptr;
        if(i_target != nullptr)
        {
            if(   i_target->getAttr<TARGETING::ATTR_TYPE>()
               == TARGETING::TYPE_NODE)
            {
                pNode = i_target;
            }
            else
            {
                auto nodeType = TARGETING::TYPE_NODE;
                pNode = TARGETING::getParent(i_target,nodeType);
            }
        }

        if(pNode == nullptr)
        {
            TRACFCOMP(g_trac_vpd, ERR_MRK"sendMboxWriteMsg (runtime): "
                      "Failed to determine HUID of node target containing "
                      "(or equalling) requested target with HUID of 0x%08X",
                      TARGETING::get_huid(i_target));
            /*@
             * @errortype
             * @moduleid   VPD_SEND_MBOX_WRITE_MESSAGE
             * @reasoncode VPD_FAILED_TO_RESOLVE_NODE_TARGET
             * @userdata1  HUID of target to update VPD for
             * @userdata2  VPD message type
             * @devdesc    Could not determine which node the target is in
             * @custdesc   Runtime vital product data update failure
             */
            l_err = new ErrlEntry(
                        ERRL_SEV_UNRECOVERABLE,
                        VPD_SEND_MBOX_WRITE_MESSAGE,
                        VPD_FAILED_TO_RESOLVE_NODE_TARGET,
                        TARGETING::get_huid(i_target),
                        i_type,
                        true);
            break;
        }

        const uint32_t targetHUID = i_target->getAttr<TARGETING::ATTR_HUID>();
        i_target->setAttr<TARGETING::ATTR_EECACHE_VPD_STATE>(TARGETING::EECACHE_VPD_STATE_VPD_NEEDS_REFRESH);
        //  FSP will set this for normal reboots, setAttr by HBRT will only survive MPIPL.
        //  Any modifications to VPD will -NOT- take affect until next IPL

        // Get an accurate size of memory needed to transport
        // the data for the firmware_request request struct
        uint32_t l_fsp_req_size = GENERIC_FSP_MBOX_MESSAGE_BASE_SIZE;
        l_fsp_req_size +=   sizeof(VpdWriteMsg_t);

        // add the i_numBytes (extra_data) to bump up total size of payload
        // see vpd.H for layout of data payload sections within VpdWriteMsg_t
        l_fsp_req_size += i_numBytes;

        // The request data size must be at a minimum the size of the
        // FSP generic message (sizeof(GenericFspMboxMessage_t))
        if (l_fsp_req_size < sizeof(GenericFspMboxMessage_t))
        {
            l_fsp_req_size = sizeof(GenericFspMboxMessage_t);
        }

        // Calculate the TOTAL size of hostInterfaces::hbrt_fw_msg which
        // means only adding hostInterfaces::HBRT_FW_MSG_BASE_SIZE to
        // the previous calculated data size
        uint64_t l_req_fw_msg_size = hostInterfaces::HBRT_FW_MSG_BASE_SIZE +
                                     l_fsp_req_size;

        // Create the firmware_request request struct to send data
        l_req_fw_msg =
                  (hostInterfaces::hbrt_fw_msg *)malloc(l_req_fw_msg_size);

        // Initialize the firmware_request request struct
        l_req_fw_msg->generic_msg.initialize();

        // Populate the firmware_request request struct with given data
        l_req_fw_msg->io_type = hostInterfaces::HBRT_FW_MSG_HBRT_FSP_REQ;
        l_req_fw_msg->generic_msg.dataSize = l_fsp_req_size;
        l_req_fw_msg->generic_msg.msgq = MBOX::FSP_VPD_MSGQ;
        l_req_fw_msg->generic_msg.msgType = i_type;
        l_req_fw_msg->generic_msg.__req = GenericFspMboxMessage_t::REQUEST;

        // the full message looks like this, see msg.h msg_t for layout
        struct VpdWriteMsgHBRT_t
        {
            VpdWriteMsg_t vpdInfo;  // VpdWriteMsg_t payloads for data[2]
                                    // from msg.h
            uint8_t vpdData;        // msg_t start of payload of i_numBytes size
        } PACKED;

        VpdWriteMsgHBRT_t* l_msg = reinterpret_cast<VpdWriteMsgHBRT_t*>
          (&(l_req_fw_msg->generic_msg.data));
        l_msg->vpdInfo.offset = i_record.offset;
        l_msg->vpdInfo.targetHUID = targetHUID;
        l_msg->vpdInfo.extra_payload_bytes = i_numBytes;
        memcpy( &(l_msg->vpdData), i_data, i_numBytes );

        // Create the firmware_request response struct to receive data
        // NOTE: For messages to the FSP the response size must match
        // the request size.
        // No need to check for expected response size > request
        // size because they use the same base structure
        uint64_t l_resp_fw_msg_size = l_req_fw_msg_size;
        l_resp_fw_msg =
                   (hostInterfaces::hbrt_fw_msg *)malloc(l_resp_fw_msg_size);
        memset(l_resp_fw_msg, 0, l_resp_fw_msg_size);

        // Trace out the request structure
        TRACFBIN( g_trac_vpd, INFO_MRK"Sending firmware_request",
                  l_req_fw_msg,
                  l_req_fw_msg_size);

        // Make the firmware_request call
        l_err = firmware_request_helper(l_req_fw_msg_size,
                                        l_req_fw_msg,
                                        &l_resp_fw_msg_size,
                                        l_resp_fw_msg);

        if (l_err)
        {
            break;
        }
    } while (0);

    // release the memory created
    if( l_req_fw_msg ) { free(l_req_fw_msg); }
    if( l_resp_fw_msg ) { free(l_resp_fw_msg); }
    l_req_fw_msg = l_resp_fw_msg = nullptr;

    // Commit any errors we get in here because we'd like the main
    //  function to complete even if we can't send the data out
    if (l_err)
    {
        l_err->collectTrace("VPD",512);
        errlCommit( l_err, VPD_COMP_ID );
    }

    return l_err;
}

}; // end namepsace VPD
