/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/secureboot/node_comm/node_comm_test.C $               */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2021                        */
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
 * @file node_comm_test.C
 *
 * @brief Implementation of the Secure Node Communications Tests
 *
 */

// ----------------------------------------------
// Includes
// ----------------------------------------------
#include <string.h>
#include <trace/interface.H>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <errl/errludtarget.H>
#include <targeting/common/targetservice.H>
#include <devicefw/userif.H>
#include <devicefw/driverif.H>
#include <secureboot/secure_reasoncodes.H>
#include <secureboot/nodecommif.H>
#include <targeting/common/commontargeting.H>
#include <targeting/common/utilFilter.H>

#include "node_comm.H"


using   namespace   TARGETING;

namespace SECUREBOOT
{

namespace NODECOMM
{

/**
 *  @brief Execute A Single Transmission from one proc to another over Xbus
 */
errlHndl_t nodeCommXbus2ProcTest(void)
{
    errlHndl_t err = nullptr;
    const uint64_t gold_data = 0xFEEDB0B0DEADBEEF;
    uint64_t sent_data = gold_data;
    uint64_t read_data = 0;
    Target* read_tgt = nullptr;
    uint8_t linkId = 0;
    uint8_t mboxId = 0;
    bool attn_found = false;

    do
    {

    // Get a list of all the procs in the system
    TARGETING::TargetHandleList l_cpuTargetList;
    getAllChips(l_cpuTargetList, TYPE_PROC);

    // Need at least 2 procs for this test
    if ( l_cpuTargetList.size() < 2 )
    {
        TRACFCOMP(g_trac_nc,ERR_MRK"nodeCommXbus2ProcTest: need at least "
                  "2 procs - only have %d",
                  l_cpuTargetList.size());

        break;
    }

    TRACUTCOMP(g_trac_nc,ENTER_MRK"nodeCommXbus2ProcTest: Running with %d procs",
              l_cpuTargetList.size());

    // 1) Send Data Out of First Proc Xbus Link Mailbox
    // @TODO RTC 195220 Update this to use PEER_PATH attribute
    if ( l_cpuTargetList.size() != 4)
    {
        linkId = 4;
        mboxId = 0;
    }
    else
    {
        linkId = 0;
        mboxId = 0;
    }
    TARGETING::Target* proc0 = (l_cpuTargetList[0]);
    size_t size=sizeof(sent_data);

    TRACFCOMP(g_trac_nc,"nodeCommXbus2ProcTest: "
              "Sending 0x%016llX to L%d/M%d Using proc0=0x%X",
              sent_data, linkId, mboxId, TARGETING::get_huid(proc0));

    err = DeviceFW::deviceWrite(proc0,
                                &sent_data,
                                size,
                                DEVICE_NODECOMM_ADDRESS(linkId, mboxId));

    if (err)
    {
        TRACFCOMP(g_trac_nc,ERR_MRK"nodeCommXbus2ProcTest: Error Back From "
                  "Xbus MBox Send: Tgt=0x%X, link=%d, mbox=%d: "
                  TRACE_ERR_FMT,
                  get_huid(proc0), linkId, mboxId,
                  TRACE_ERR_ARGS(err));
        break;
    }

    // 2) Loop through targets to see which of them had an attention
    for (const auto & l_cpu_target: l_cpuTargetList)
    {
        attn_found = false;
        read_tgt = l_cpu_target;

        err = nodeCommMapAttn(read_tgt, attn_found, linkId, mboxId);
        if (err)
        {
            TRACFCOMP(g_trac_nc,ERR_MRK"nodeCommXbus2ProcTest: Error Back From "
                      "Map Attn: Tgt=0x%X, attn_found=%d, link=%d, mbox=%d: "
                      TRACE_ERR_FMT,
                      get_huid(read_tgt), attn_found, linkId, mboxId,
                      TRACE_ERR_ARGS(err));
            break;
        }
        if (attn_found == true)
        {
            break;
        }
    }
    if(err)
    {
        break;
    }

    if (attn_found == false)
    {
        TRACFCOMP(g_trac_nc,ERR_MRK"nodeCommXbus2ProcTest: "
                  "No attentions were found! (%d)",
                  attn_found);

        /*@
         * @errortype
         * @reasoncode       RC_NC_NO_ATTN_FOUND
         * @moduleid         MOD_NC_XBUS_TEST
         * @userdata1        Data Sent
         * @userdata2[0:15]  LinkId data was sent from
         * @userdata2[16:31] MboxId data was sent from
         * @userdata2[32:63] Target HUID data was sent from
         * @devdesc          No Attention was found after sending data in
         *                   XBUS Node Comm Test
         * @custdesc         Trusted Boot failure
         */
        err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                       MOD_NC_XBUS_TEST,
                                       RC_NC_NO_ATTN_FOUND,
                                       sent_data,
                                       TWO_UINT16_ONE_UINT32_TO_UINT64(
                                         linkId,
                                         mboxId,
                                         get_huid(proc0)));

        // Likely HB code failed to do the procedure correctly
        err->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                                 HWAS::SRCI_PRIORITY_HIGH);

        // Or unlikely an issue with Processor or its bus
        err->addHwCallout( proc0,
                           HWAS::SRCI_PRIORITY_LOW,
                           HWAS::NO_DECONFIG,
                           HWAS::GARD_NULL );
        break;
    }
    else
    {
        TRACUTCOMP(g_trac_nc,INFO_MRK"nodeCommXbus2ProcTest: "
                  "Attention was found (%d) on tgt=0x%.08X",
                  attn_found, get_huid(read_tgt));
    }


    // 3) Read message on proc with Link Mailbox found above
    TRACFCOMP(g_trac_nc,"nodeCommXbus2ProcTest: Attention Found on "
              "proc=0x%X for L%d/M%d ",
              TARGETING::get_huid(read_tgt), linkId, mboxId);

    err = DeviceFW::deviceRead(read_tgt,
                               &read_data,
                               size,
                               DEVICE_NODECOMM_ADDRESS(linkId, mboxId));
    if (err)
    {
        TRACFCOMP(g_trac_nc,ERR_MRK"nodeCommXbus2ProcTest: Error Back From "
                  "Xbus MBox Read: Tgt=0x%X, link=%d, mbox=%d: "
                  TRACE_ERR_FMT,
                  get_huid(read_tgt), linkId, mboxId,
                  TRACE_ERR_ARGS(err));
        break;
    }

    // 4) Compare values
    if (read_data == gold_data)
    {
        TRACFCOMP(g_trac_nc,INFO_MRK"nodeCommXbus2ProcTest: "
                  "DATA SUCCESSFULLY READ BACK = 0x%.16llx from "
                  "proc=0x%X's L%d/M%d Mailbox"
                  "L%d/M%d using proc=0x%X",
                  read_data, TARGETING::get_huid(read_tgt), linkId, mboxId);
    }
    else
    {
        TRACFCOMP(g_trac_nc,ERR_MRK"nodeCommXbus2ProcTest: "
                  "DATA NOT READ BACK! Got 0x%.16llx; should be 0x%.16llX. "
                  "Read from proc=0x%X's L%d/M%d Mailbox",
                  read_data, gold_data, TARGETING::get_huid(read_tgt), linkId, mboxId);

        /*@
         * @errortype
         * @reasoncode       RC_NC_DATA_MISCOMPARE
         * @moduleid         MOD_NC_XBUS_TEST
         * @userdata1        Data Read Back
         * @userdata2[0:15]  LinkId data was read from
         * @userdata2[16:31] MboxId data was read from
         * @userdata2[32:63] Target HUID data was read from
         * @devdesc          No Attention was found after sending data in
         *                   Xbus Node Comm Test
         * @custdesc         Trusted Boot failure
         */
        err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                       MOD_NC_XBUS_TEST,
                                       RC_NC_DATA_MISCOMPARE,
                                       read_data,
                                       TWO_UINT16_ONE_UINT32_TO_UINT64(
                                         linkId,
                                         mboxId,
                                         get_huid(read_tgt)));

        // Likely HB code failed to do the procedure correctly
        err->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                                 HWAS::SRCI_PRIORITY_HIGH);

        // Or unlikely an issue with Processor or its bus
        err->addHwCallout( read_tgt,
                           HWAS::SRCI_PRIORITY_LOW,
                           HWAS::NO_DECONFIG,
                           HWAS::GARD_NULL );

        // Collect FFDC
        getNodeCommFFDC(read_tgt, err);

    }

    } while( 0 );

    TRACFCOMP(g_trac_nc,EXIT_MRK"nodeCommXbus2ProcTest: "
              TRACE_ERR_FMT
              "Tgt=0x%X, attn_found=%d, link=%d, mbox=%d",
              TRACE_ERR_ARGS(err),
              get_huid(read_tgt), attn_found, linkId, mboxId);

    if (err)
    {
        err->collectTrace(SECURE_COMP_NAME);
        err->collectTrace(NODECOMM_TRACE_NAME);

        // @TODO RTC 195220 Delete for now as it will fail in simics and
        // cause a processor deconfig.
        delete err;
        err = nullptr;
    }

    return err;

} // end of nodeCommXbus2ProcTest

} // End NODECOMM namespace

} // End SECUREBOOT namespace



