/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/secureboot/node_comm/node_comm.C $                    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2022                        */
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
 * @file node_comm.C
 *
 * @brief Implementation of the Secure Node Communications Functions
 *
 */

// ----------------------------------------------
// Includes
// ----------------------------------------------
#include <string.h>
#include <sys/time.h>
#include <sys/task.h>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <errl/errludtarget.H>
#include <errl/errludlogregister.H>
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

// ----------------------------------------------
// Defines
// ----------------------------------------------
// If the link(s) are up the operation should complete right away
// so there will only be a short polling window
#define NODE_COMM_POLL_DELAY_NS (10 * NS_PER_MSEC)  // Sleep for 10ms per poll
// FSP is expecting a reply in 30 seconds, so leave some buffer
#define NODE_COMM_POLL_DELAY_TOTAL_NS (25 * NS_PER_SEC) // Total time 25s


/**
 *  @brief This function waits for the processor to receive a message
 *         from a processor on another node.
 *
 *  @note PAUC target is expected as the input
 */
errlHndl_t nodeCommRecvMessage(TARGETING::Target* i_pTarget,
                               const uint8_t i_linkId,
                               const uint8_t i_mboxId,
                               uint64_t & o_data)
{
    errlHndl_t err = nullptr;
    bool attn_found = false;
    uint8_t actual_linkId = 0;
    uint8_t actual_mboxId = 0;

    const uint64_t interval_ns = NODE_COMM_POLL_DELAY_NS;
    uint64_t time_polled_ns = 0;

    TRACUTCOMP(g_trac_nc,ENTER_MRK"nodeCommRecvMessage: i_pTarget=0x%.08X",
              get_huid(i_pTarget));

    do
    {
        do
        {

        // Look for Attention
        err = nodeCommMapAttn(i_pTarget,
                              attn_found,
                              actual_linkId,
                              actual_mboxId);
        if (err)
        {
            TRACFCOMP(g_trac_nc,ERR_MRK"nodeCommRecvMessage: Error Back "
                      "From nodeCommMapAttn: Tgt=0x%.08X: "
                      TRACE_ERR_FMT,
                      get_huid(i_pTarget),
                      TRACE_ERR_ARGS(err));
            break;
        }
        if (attn_found == true)
        {
            TRACUTCOMP(g_trac_nc,INFO_MRK"nodeCommRecvMessage: "
              "nodeCommMapAttn attn_found (%d) for Tgt=0x%.08X, link=%d, "
              "mbox=%d",
              attn_found, get_huid(i_pTarget), actual_linkId, actual_mboxId);
            break;
        }

        if (time_polled_ns >= NODE_COMM_POLL_DELAY_TOTAL_NS)
        {
            TRACFCOMP(g_trac_nc,ERR_MRK"nodeCommRecvMessage: "
              "timeout: time_polled_ns-0x%.16llX, MAX=0x%.16llX, "
              "interval=0x%.16llX",
              time_polled_ns, NODE_COMM_POLL_DELAY_TOTAL_NS, interval_ns);

            /*@
             * @errortype
             * @reasoncode       RC_NC_WAITING_TIMEOUT
             * @moduleid         MOD_NC_RECV
             * @userdata1[0:31]  Target HUID
             * @userdata1[32:63] Time Polled in ns
             * @userdata2[0:31]  Defined MAX Poll Time in ns
             * @userdata2[32:63] Time Interval Between Polls in ns
             * @devdesc          Timed out waiting to receive message from
             *                   another node
             * @custdesc         Trusted Boot failure
             */
            err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                           MOD_NC_RECV,
                                           RC_NC_WAITING_TIMEOUT,
                                           TWO_UINT32_TO_UINT64(
                                             get_huid(i_pTarget),
                                             time_polled_ns),
                                           TWO_UINT32_TO_UINT64(
                                             NODE_COMM_POLL_DELAY_TOTAL_NS,
                                             interval_ns));

            // This failure could be caused by the other side of the bus
            //  having checkstopped.  Log a procedure callout to direct
            //  service to investigate.
            err->addProcedureCallout(HWAS::EPUB_PRC_MULTINODE_CHECKSTOP,
                                     HWAS::SRCI_PRIORITY_HIGH);

            // Since we know what bus we expected the message on, call it out
            addNodeCommBusCallout(i_pTarget,
                                  i_linkId,
                                  err);

            // Or HB code failed to do the procedure correctly
            err->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                                     HWAS::SRCI_PRIORITY_LOW);

            // Grab FFDC from the target
            getNodeCommFFDC(i_pTarget,
                            err);

            break;
        }

        // Sleep before polling again
        nanosleep( 0, interval_ns );
        task_yield(); // wait patiently
        time_polled_ns += interval_ns;

        } while(attn_found == false);

    if (err)
    {
        break;
    }

    if (attn_found == true)
    {
        // Verify that actual receive link/mboxIds were the same as the
        // expected ones
        if ((actual_linkId != i_linkId) ||
            (actual_mboxId != i_mboxId))
        {
            TRACFCOMP(g_trac_nc,ERR_MRK"nodeCommRecvMessage: "
                      "Expected Link (%d) Mbox (%d) IDs DO NOT Match the "
                      "Actual Link (%d) Mbox (%d) IDs the message was "
                      "received on",
                       i_linkId, i_mboxId,
                       actual_linkId, actual_mboxId);

            /*@
             * @errortype
             * @reasoncode       RC_NCEX_MISMATCH_RECV_LINKS
             * @moduleid         MOD_NC_RECV
             * @userdata1        Target HUID
             * @userdata2[0:15]  Expected Link Id to receive message on
             * @userdata2[16:31] Expected Mailbox Id to receive message on
             * @userdata2[32:47] Actual Link Id message was received on
             * @userdata2[48:63] Actual Mailbox Id message was receiveed on
             * @devdesc          Mismatch between expected and actual Link Mbox
             *                   Ids a secure message was received on
             * @custdesc         Trusted Boot failure
             */
            err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                           MOD_NC_RECV,
                                           RC_NCEX_MISMATCH_RECV_LINKS,
                                           get_huid(i_pTarget),
                                           FOUR_UINT16_TO_UINT64(
                                             i_linkId,
                                             i_mboxId,
                                             actual_linkId,
                                             actual_mboxId));

            // Since we know what bus we expected the message on, call it out
            addNodeCommBusCallout(i_pTarget,
                                  i_linkId,
                                  err);

            // Or HB code failed to do the procedure correctly
            err->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                                     HWAS::SRCI_PRIORITY_LOW);

            // Grab FFDC from the target
            getNodeCommFFDC(i_pTarget,
                            err);

            break;
        }

        //  Read message on the target with Link Mailbox found above
        o_data = 0;
        size_t expSize = sizeof(o_data);
        auto reqSize = expSize;
        err = DeviceFW::deviceRead(i_pTarget,
                                   &o_data,
                                   reqSize,
                                   DEVICE_NODECOMM_ADDRESS(actual_linkId,
                                                           actual_mboxId));

        if (err)
        {
            TRACFCOMP(g_trac_nc,ERR_MRK"nodeCommRecvMessage: Error Back From "
                      "MBox Read: Tgt=0x%.08X, link=%d, mbox=%d: "
                      TRACE_ERR_FMT,
                      get_huid(i_pTarget), actual_linkId, actual_mboxId,
                      TRACE_ERR_ARGS(err));
            break;
        }
        assert(reqSize==expSize,"nodeCommRecvMessage: SCOM deviceRead didn't return expected data size of %d (it was %d)",
               expSize,reqSize);

    }

    } while( 0 );

    TRACUTCOMP(g_trac_nc,EXIT_MRK"nodeCommRecvMessage: "
              "Tgt=0x%.08X, link=%d, mbox=%d attn_found=%d: "
              "data=0x%.16llX. "
              TRACE_ERR_FMT,
              get_huid(i_pTarget), actual_linkId, actual_mboxId,
              attn_found, o_data,
              TRACE_ERR_ARGS(err));

    return err;

} // end of nodeCommRecvMessage


/**
 *  @brief This function sends a message from the processor of
 *         the current node to a processor on another node.
 *
 *  @note PAUC target is expected as the input
 */
errlHndl_t nodeCommSendMessage(TARGETING::Target* i_pTarget,
                                   const uint64_t i_data,
                                   const uint8_t i_linkId,
                                   const uint8_t i_mboxId)
{
    errlHndl_t err = nullptr;

    TRACUTCOMP(g_trac_nc,ENTER_MRK"nodeCommSendMessage: i_pTarget=0x%.08X "
              "to send data=0x%.16llX through linkId=%d mboxId=%d",
              get_huid(i_pTarget), i_data, i_linkId, i_mboxId);

    do
    {
        // Send Data
        uint64_t data = i_data; // to keep i_data const
        size_t expSize = sizeof(i_data);
        auto reqSize = expSize;
        err = DeviceFW::deviceWrite(i_pTarget,
                                    &data,
                                    reqSize,
                                    DEVICE_NODECOMM_ADDRESS(i_linkId,
                                                            i_mboxId));
        if (err)
        {
            TRACFCOMP(g_trac_nc,ERR_MRK"nodeCommSendMessage: Error Back "
                      "From MBox Send: Tgt=0x%.08X, data=0x%.16llX, "
                      "link=%d, mbox=%d: "
                      TRACE_ERR_FMT,
                      get_huid(i_pTarget), i_data, i_linkId, i_mboxId,
                      TRACE_ERR_ARGS(err));
            break;
        }
        assert(reqSize==expSize,"nodeCommSendMessage: SCOM deviceRead didn't return expected data size of %d (it was %d)",
               expSize,reqSize);

    } while( 0 );

    TRACUTCOMP(g_trac_nc,EXIT_MRK"nodeCommSendMessage: iProc=0x%.08X "
              "send data=0x%.16llX through linkId=%d mboxId=%d: "
              TRACE_ERR_FMT,
              get_huid(i_pTarget), i_data, i_linkId, i_mboxId,
              TRACE_ERR_ARGS(err));

    return err;

} // end of nodeCommSendMessage



/**
 *  @brief Map Attention Bits in FIR Register to specific Link Mailbox
 *
 *  @note PAUC target is expected as the input
 */
errlHndl_t nodeCommMapAttn(TARGETING::Target* i_pTarget,
                           bool & o_attn_found,
                           uint8_t & o_linkId,
                           uint8_t & o_mboxId)
{
    errlHndl_t err = nullptr;
    uint64_t fir_data = 0x0;
    uint64_t fir_data_with_mask = 0x0;
    o_attn_found = false;

    const uint64_t fir_mask = NCDD_FIR_ATTN_MASK;

    const uint64_t fir_addr = NCDD_REG_FIR;

    const size_t expSize = sizeof(fir_data);

    TRACUTCOMP(g_trac_nc,ENTER_MRK
              "nodeCommMapAttn: tgt=0x%X, fir_addr=0x%.16llX",
              get_huid(i_pTarget),
              fir_addr);


    do
    {
    // Read the FIR reg
    auto reqSize = expSize;
    err = DeviceFW::deviceRead(i_pTarget,
                               &fir_data,
                               reqSize,
                               DEVICE_SCOM_ADDRESS(fir_addr));

    if(err)
    {
        TRACFCOMP(g_trac_nc,ERR_MRK"nodeCommMapAttn Read Fail! "
                  " tgt=0x%X, reg_addr=0x%.16llX, data=0x%.16llX "
                  TRACE_ERR_FMT,
                  TARGETING::get_huid(i_pTarget),
                  fir_addr, fir_data,
                  TRACE_ERR_ARGS(err));
        break;
    }
    assert(reqSize==expSize,"nodeCommMapAttn: SCOM deviceRead didn't return expected data size of %d (it was %d)",
           expSize,reqSize);

    // Map Attention bits in the FIR
    fir_data_with_mask = fir_data & fir_mask;
    const int bit_count = __builtin_popcountll(fir_data_with_mask);
    TRACUTCOMP(g_trac_nc,"nodeCommMapAttn: FIR data = 0x%.16llX, "
              "mask=0x%.16llX, data+mask=0x%.16llX, count=%d",
              fir_data, fir_mask, fir_data_with_mask, bit_count);

    if (bit_count == 0)
    {
        TRACUTCOMP(g_trac_nc,INFO_MRK"nodeCommMapAttn: no attentions found: "
                  "FIR data = 0x%.16llX, mask=0x%.16llX, data+mask=0x%.16llX",
                  fir_data, fir_mask, fir_data_with_mask);
        break;
    }
    else if (bit_count > 1)
    {
        TRACFCOMP(g_trac_nc,ERR_MRK"nodeCommMapAttn: "
                  "Too many attentions found (%d) in fir: data=0x%.16llX, "
                  "data+mask=0x%.16llX, fir_addr=0x%.16llX",
                  bit_count, fir_data, fir_data_with_mask, fir_addr);

        /*@
         * @errortype
         * @reasoncode       RC_NC_TOO_MANY_ATTNS_FOUND
         * @moduleid         MOD_NC_MAP_ATTN
         * @userdata1        Raw FIR Data
         * @userdata2[0:31]  Number of Attentions found
         * @userdata2[32:63] Target HUID FIR was read from
         * @devdesc          Too many attentions were found in
         *                   the Node Comm FIR Register
         * @custdesc         Trusted Boot failure
         */
        err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                       MOD_NC_MAP_ATTN,
                                       RC_NC_TOO_MANY_ATTNS_FOUND,
                                       fir_data,
                                       TWO_UINT32_TO_UINT64(
                                         bit_count,
                                         get_huid(i_pTarget)));

        // Likely HB code failed to do the procedure correctly
        err->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                                 HWAS::SRCI_PRIORITY_HIGH);

        // Or unlikely an issue with Processor or its bus
        err->addHwCallout( i_pTarget,
                           HWAS::SRCI_PRIORITY_LOW,
                           HWAS::NO_DECONFIG,
                           HWAS::GARD_NULL );

        // Collect FFDC
        getNodeCommFFDC(i_pTarget, err);

        err->collectTrace(SECURE_COMP_NAME);
        err->collectTrace(NODECOMM_TRACE_NAME);

        break;
    }

    int bit = 0;
    const int possible_attn_bits = __builtin_popcountll(fir_mask);
    for ( ; bit < possible_attn_bits ; ++bit)
    {
        // Start at first bit and shift right to find an attention
        if ( fir_data & (NCDD_START_OF_ATTN_BITS >> bit))
        {
            o_attn_found = true;
            o_linkId = (bit / 2);
            o_mboxId = (bit % 2);

            TRACUTCOMP(g_trac_nc,INFO_MRK"nodeCommMapAttn: tgt=0x%X: "
                      "o_attn_found=%d, o_linkId=%d, mboxId=%d, "
                      TRACE_ERR_FMT,
                      get_huid(i_pTarget), o_attn_found, o_linkId, o_mboxId,
                      TRACE_ERR_ARGS(err));
            break;
        }
    }

    } while( 0 );

    TRACUTCOMP(g_trac_nc,EXIT_MRK"nodeCommMapAttn: tgt=0x%X: "
              "o_attn_found=%d, o_linkId=%d, mboxId=%d, "
              TRACE_ERR_FMT,
              get_huid(i_pTarget), o_attn_found, o_linkId, o_mboxId,
              TRACE_ERR_ARGS(err));

    return err;

} // end of nodeCommMapAttn

/**
 *  @brief For IOHS OLL FIR Register (0x18011000) bit0 represents whether or
 *         not link0 has been trained and bit1 represents whether or not
 *         link1 has been trained
 */
enum link_trained_values : uint64_t
{
    // Register to read to find out which links on an IOHS are trained
    OLL_FIR_REGISTER      = 0x0000000018011000,

    // Bit Mask values
    IS_LINK0_TRAINED_MASK = 0x8000000000000000,
    IS_LINK1_TRAINED_MASK = 0x4000000000000000,
};

/**
 *  @brief Return the status of whether or not the 2 links connected to the
 *         IOHS Chiplet are trained
 */
errlHndl_t getIohsTrainedLinks(TARGETING::Target* i_pIohs,
                               bool & o_link0_trained,
                               bool & o_link1_trained,
                               uint64_t & o_fir_data)
{
    errlHndl_t err = nullptr;
    o_link0_trained = false;
    o_link1_trained = false;
    o_fir_data = 0;
    const uint64_t fir_addr = OLL_FIR_REGISTER;
    const size_t expSize = sizeof(o_fir_data);

    assert(i_pIohs != nullptr, "getObusTrainedLinks: i_pIohs == nullptr");

    TRACUTCOMP(g_trac_nc,ENTER_MRK
              "getIohsTrainedLinks: IOHS tgt=0x%X",
              get_huid(i_pIohs));

    do
    {
    // Read the IOHS OLL FIR Register
    auto reqSize = expSize;
    err = DeviceFW::deviceRead(i_pIohs,
                               &o_fir_data,
                               reqSize,
                               DEVICE_SCOM_ADDRESS(fir_addr));

    if(err)
    {
        TRACFCOMP(g_trac_nc,ERR_MRK"getObusTrainedLinks: Read Fail! "
                  "tgt=0x%X, fir_addr=0x%.16llX, fir_data=0x%.16llX "
                  TRACE_ERR_FMT,
                  TARGETING::get_huid(i_pIohs),
                  fir_addr, o_fir_data,
                  TRACE_ERR_ARGS(err));
        break;
    }
    assert(reqSize==expSize,"getObusTrainedLinks: SCOM deviceRead didn't return expected data size of %d (it was %d)",
           expSize,reqSize);

    o_link0_trained = (o_fir_data & IS_LINK0_TRAINED_MASK) != 0;
    o_link1_trained = (o_fir_data & IS_LINK1_TRAINED_MASK) != 0;


    } while( 0 );

    TRACFCOMP(g_trac_nc,EXIT_MRK"getIohsTrainedLinks: IOHS tgt=0x%X: "
              "o_link0_trained=%d, o_link1_trained=%d (fir_data=0x%.16llX) "
              TRACE_ERR_FMT,
              get_huid(i_pIohs), o_link0_trained, o_link1_trained, o_fir_data,
              TRACE_ERR_ARGS(err));

    return err;

} // end of getObusTrainedLinks


/**
 * @brief Add FFDC for the target to an error log
 *
 * @note PAUC target is expected as the input
 */
void getNodeCommFFDC(TARGETING::Target*  i_pTarget,
                      errlHndl_t          &io_log)
{
    TRACFCOMP(g_trac_nc,ENTER_MRK
              "getNodeCommFFDC: tgt=0x%X, err_plid=0x%X",
              get_huid(i_pTarget),
              ERRL_GETPLID_SAFE(io_log));

    do
    {
    if (io_log == nullptr)
    {
        TRACFCOMP(g_trac_nc,INFO_MRK"getNodeCommFFDC: io_log==nullptr, so "
                  "no FFDC has been collected for tgt=0x%X",
                  get_huid(i_pTarget));
        break;
    }

    // Add Target to log
    ERRORLOG::ErrlUserDetailsTarget(i_pTarget,"Target").addToLog(io_log);

    // Add HW regs
    ERRORLOG::ErrlUserDetailsLogRegister ffdc(i_pTarget);

    // FIR/Control/Status/Data Registers
    ffdc.addData(DEVICE_SCOM_ADDRESS(NCDD_REG_FIR));
    ffdc.addData(DEVICE_SCOM_ADDRESS(NCDD_REG_CTRL));
    ffdc.addData(DEVICE_SCOM_ADDRESS(NCDD_REG_DATA));

    // Loop Through All of the Mailbox Registers Where the Data Could End Up
    uint64_t l_reg = 0;

    for (size_t linkId=0;  linkId <= NCDD_MAX_LINK_ID; ++linkId)
    {
        for (size_t mboxId=0; mboxId <= NCDD_MAX_MBOX_ID; ++mboxId)
        {
            l_reg = getLinkMboxReg(linkId, mboxId);
            ffdc.addData(DEVICE_SCOM_ADDRESS(l_reg));
        }
    }

    ffdc.addToLog(io_log);


    } while( 0 );

    TRACFCOMP(g_trac_nc,EXIT_MRK"getNodeCommFFDC");

    return;

} // end of getNodeCommFFDC


/**
 * @brief Add a bus callout to an error log
 *
 * @note PAUC target is expected as the input
 */
void addNodeCommBusCallout(TARGETING::Target* i_pTarget,
                           const uint8_t i_linkId,
                           errlHndl_t & io_log,
                           HWAS::callOutPriority i_priority)
{
    TRACFCOMP(g_trac_nc,ENTER_MRK
              "addNodeCommBusCallout: tgt=0x%X, linkId=%d, "
              "err_plid=0x%X, priority=%d",
              get_huid(i_pTarget),
              i_linkId,
              ERRL_GETPLID_SAFE(io_log), i_priority);

    // Bus associated with i_pTarget and i_linkId (PHYS_PATH)
    char * l_ep1_path_str = nullptr;

    // PEER_PATH associated with l_ep1
    char * l_ep2_path_str = nullptr;

    bool found_peer_endpoint = false;

    do
    {
    if ((io_log == nullptr) ||
        (i_pTarget == nullptr))
    {
        TRACFCOMP(g_trac_nc,INFO_MRK"addNodeCommBusCallout: io_log==nullptr or "
                  "tgt=0x%X is nullptr, so no bus callout has beed added",
                  get_huid(i_pTarget));
        break;
    }

    // Get Bus Type
    HWAS::busTypeEnum l_bus_type = HWAS::A_BUS_TYPE;

    // Get all Chiplets for this target aligned with the input mode
    TargetHandleList l_busTargetList;
    TYPE l_type = TYPE_IOHS;
    getChildChiplets(l_busTargetList, i_pTarget, l_type, false);

    // Get BUS Instance
    // For each IOHS instance there are 2 links and 2 mailboxes,
    // so divide the linkId by 2 to get bus instance
    uint8_t l_bus_instance_ep1 = i_linkId / 2;


    // Look through Bus Targets looking for specific Bus Instance
    // to find the right PEER_TARGET
    for (const auto & l_busTgt : l_busTargetList)
    {
        found_peer_endpoint = false;
        EntityPath l_ep1 = l_busTgt->getAttr<ATTR_PHYS_PATH>();
        if (l_ep1_path_str != nullptr)
        {
            free(l_ep1_path_str);
        }
        l_ep1_path_str = l_ep1.toString();


        EntityPath l_ep2 = l_busTgt->getAttr<ATTR_PEER_PATH>();
        if (l_ep2_path_str != nullptr)
        {
            free(l_ep2_path_str);
        }
        l_ep2_path_str = l_ep2.toString();

        TRACUTCOMP(g_trac_nc,INFO_MRK"addNodeCommBusCallout: Checking "
                      "i_pTarget 0x%.08X BUS HUID 0x%.08X's (%s) PEER_PATH: %s",
                      get_huid(i_pTarget), get_huid(l_busTgt),
                      l_ep1_path_str,
                      l_ep2_path_str);

        EntityPath::PathElement l_ep2_peBus =
                                  l_ep2.pathElementOfType(l_type);
        if(l_ep2_peBus.type == TYPE_NA)
        {
            TRACUTCOMP(g_trac_nc,INFO_MRK"addNodeCommBusCallout: "
                      "Skipping i_pTarget 0x%.08X "
                      "BUS HUID 0x%.08X's (%s) PEER_PATH %s because "
                      "cannot find BUS in PEER_PATH",
                      get_huid(i_pTarget), get_huid(l_busTgt),
                      l_ep1_path_str, l_ep2_path_str);
            continue;
        }

        if (l_bus_instance_ep1 == l_busTgt->getAttr<ATTR_REL_POS>())
        {
            // Go to depth of TYPE_SMPGROUP, which is one level below IOHS
            TargetHandleList l_smpGroupTargetList;
            getChildAffinityTargets(l_smpGroupTargetList,
                                    l_busTgt,
                                    CLASS_UNIT,
                                    TYPE_SMPGROUP,
                                    false);

            for (auto l_smpGroup : l_smpGroupTargetList)
            {
                EntityPath l_smpGroup_ep =
                             l_smpGroup->getAttr<ATTR_PHYS_PATH>();
                EntityPath::PathElement l_smpGroup_ep_peSmpGroup =
                             l_smpGroup_ep.pathElementOfType(TYPE_SMPGROUP);
                if (l_ep1_path_str != nullptr)
                {
                     free(l_ep1_path_str);
                }
                l_ep1_path_str = l_smpGroup_ep.toString();

                EntityPath l_smpGroup_peer_ep =
                             l_smpGroup->getAttr<ATTR_PEER_PATH>();
                if (l_ep2_path_str != nullptr)
                {
                    free(l_ep2_path_str);
                }
                l_ep2_path_str = l_smpGroup_peer_ep.toString();

                TRACUTCOMP(g_trac_nc,INFO_MRK"addNodeCommBusCallout: "
                           "SMPGROUP HUID: 0x%.08X (%s): rel_pos=%d, "
                           "instance=%d: peer=%s",
                           get_huid(l_smpGroup),
                           l_ep1_path_str,
                           l_smpGroup->getAttr<ATTR_REL_POS>(),
                           l_smpGroup_ep_peSmpGroup.instance,
                           l_ep2_path_str);

                // Find matching instance and relative link Id
                if ((l_smpGroup_ep_peSmpGroup.instance % 2) ==
                    (i_linkId % 2))
                {
                    found_peer_endpoint = true;

                    TRACFCOMP(g_trac_nc,INFO_MRK"addNodeCommBusCallout: "
                              "Using SMPGROUP HUID: 0x%.08X (%s): "
                              "i_linkId=%d, rel_pos=%d, instance=%d: "
                              "peer=%s",
                              get_huid(l_smpGroup),
                              l_ep1_path_str,
                              i_linkId,
                              l_smpGroup->getAttr<ATTR_REL_POS>(),
                              l_smpGroup_ep_peSmpGroup.instance,
                              l_ep2_path_str);

                    // Add Bus Callout
                    io_log->addBusCallout(l_smpGroup_ep,
                                          l_smpGroup_peer_ep,
                                          l_bus_type,
                                          i_priority);

                    // Add HW Callout to deconfigure this SMPGROUP
                    io_log->addHwCallout(l_smpGroup,
                                         i_priority,
                                         HWAS::DECONFIG,
                                         HWAS::GARD_NULL);

                    break;
                }
            }
        }
        else
        {
            TRACUTCOMP(g_trac_nc,INFO_MRK"addNodeCommBusCallout: "
                      "Skipping i_pTarget 0x%.08X BUS HUID 0x%.08X's "
                      "PEER_PATH %s because ep1 bus instance (%d) does not "
                      "match instance (%d) converted from i_linkId (%d)",
                      get_huid(i_pTarget), get_huid(l_busTgt),
                      l_ep2_path_str, l_busTgt->getAttr<ATTR_ORDINAL_ID>(),
                      l_bus_instance_ep1, i_linkId);
        }

        if (found_peer_endpoint == true)
        {
            break;
        }
    }  // for loop for IOHS

    if (found_peer_endpoint == false)
    {
        TRACFCOMP(g_trac_nc,INFO_MRK"addNodeCommBusCallout: Unable to find a "
                  "peer_tgt for tgt=0x%X, linkId=%d, so no bus "
                  "callout has been added",
                  get_huid(i_pTarget),
                  i_linkId);
        break;
    }

    } while( 0 );

    if (l_ep1_path_str != nullptr)
    {
        free(l_ep1_path_str);
        l_ep1_path_str = nullptr;
    }

    if (l_ep2_path_str != nullptr)
    {
        free(l_ep2_path_str);
        l_ep2_path_str = nullptr;
    }

    TRACFCOMP(g_trac_nc,EXIT_MRK"addNodeCommBusCallout");

    return;

} // end of addNodeCommBusCallout

} // End NODECOMM namespace

} // End SECUREBOOT namespace
