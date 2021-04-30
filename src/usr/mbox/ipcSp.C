/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/mbox/ipcSp.C $                                        */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2021                        */
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
#include <mbox/ipc_msg_types.H>
#include "ipcSp.H"
#include <runtime/runtime.H>
#include <vfs/vfs.H>
#include <mbox/ipc_reasoncodes.H>
#include <mbox/mboxif.H>
#include <errl/errlmanager.H>
#include <mbox/mbox_reasoncodes.H>
#include <intr/interrupt.H>
#include <initservice/initserviceif.H>
#include <initservice/mboxRegs.H>
#include <sbeio/sbeioif.H>
#include <util/utiltce.H>
#include <util/utilmbox_scratch.H>
#include <targeting/targplatutil.H>
#include <targeting/common/targetservice.H>
#include <targeting/common/attributes.H>
#include <sys/internode.h>
#include <sys/mmio.h>
#include <xscom/xscomif.H>
#include <sys/misc.h>
#include <kernel/misc.H>
#include <arch/memorymap.H>
#include <fapi2/plat_hwp_invoker.H>
#include <errl/errluserdetails.H>
#include <errl/errludtarget.H>
#include <initservice/isteps_trace.H>
#include <isteps/hwpisteperror.H>
#include <util/utilmem.H>
#include <secureboot/trustedbootif.H>
#include <targeting/targplatutil.H>

#ifndef CONFIG_VPO_COMPILE
#include <freqAttrData.H>
#endif

namespace  TU = TARGETING::UTIL;
namespace  TB = TRUSTEDBOOT;

namespace ISTEP_21
{
    extern errlHndl_t callShutdown ( uint64_t i_hbInstance,
                                     bool i_primaryInstance,
                                     const uint64_t i_commBase );
    extern errlHndl_t enableCoreCheckstops();
#ifndef CONFIG_VPO_COMPILE
    extern errlHndl_t callCheckFreqAttrData(uint64_t i_pstate0);
#endif
};

trace_desc_t* g_trac_ipc = NULL;
TRAC_INIT(&g_trac_ipc, IPC_TRACE_NAME, 4*KILOBYTE);

using namespace IPC;
using namespace ERRORLOG;
using namespace TARGETING;

IpcSp::IpcSp()
    :
        iv_msgQ(),
        iv_IsRemoteNodeAddrsValid( false )
{
}

IpcSp::~IpcSp()
{
    msg_q_destroy(iv_msgQ);
}

void IpcSp::init(errlHndl_t & o_errl)
{
    o_errl = Singleton<IpcSp>::instance()._init();
}

void IpcSp::distributeLocalNodeAddr( void )
{
    // Store IPC address for local node in mbox scratch register 7
    //  to identify IPC msg address to remote node(s)
    uint64_t l_localNode;
    uint64_t l_remoteAddr;
    qryLocalIpcInfo( l_localNode, l_remoteAddr );

    // Need to loop around all processors to handle topology id swapping
    //  that creates assymetrical effective topology ids across nodes.
    //  By writing this data to every processor, we can be sure that
    //  whichever proc is chosen for the remote xscom it will have the
    //  data we need.
    TARGETING::TargetHandleList l_procChips;
    getAllChips( l_procChips, TARGETING::TYPE_PROC , true);
    for(auto l_proc : l_procChips)
    {
        Util::writeScratchReg( INITSERVICE::SPLESS::MboxScratch7_t::REG_ADDR,
                               l_remoteAddr>>32,
                               l_proc );
        Util::writeScratchReg( INITSERVICE::SPLESS::MboxScratch8_t::REG_ADDR,
                               l_remoteAddr,
                               l_proc );
    }
}

void IpcSp::acquireRemoteNodeAddrs( void )
{
    Singleton<IpcSp>::instance()._acquireRemoteNodeAddrs();
    return;
}

void* IpcSp::msg_handler(void *unused)
{
    Singleton<IpcSp>::instance().msgHandler();
    return NULL;
}

errlHndl_t IpcSp::_init()
{
    errlHndl_t err = NULL;

    iv_msgQ = msg_q_create();
    err = MBOX::msgq_register(MBOX::HB_IPC_MSGQ,iv_msgQ);


    if(!err)
    {
        task_create(IpcSp::msg_handler, NULL);
    }

    return err;
}

void IpcSp::msgHandler()
{
    errlHndl_t err = NULL;
    bool mod_loaded = false;

    while(1)
    {
        msg_t* msg = msg_wait(iv_msgQ);

        switch(msg->type)
        {
            case IPC_POPULATE_TPM_INFO_BY_NODE:
            {
                // make sure runtime module is loaded
                if ( !VFS::module_is_loaded( "libruntime.so" ) )
                {
                    err = VFS::module_load( "libruntime.so" );

                    if ( err )
                    {
                        TRACFCOMP( g_trac_ipc,
                                   "Could not load runtime module - must shutdown now!!!" );
                    }
                    else
                    {
                        mod_loaded = true;
                    }
                }

                if(!err)
                {
                    // msg->extra_data contains PAYLOAD Base
                    RUNTIME::setPayloadBaseAddress(
                               reinterpret_cast<uint64_t>(msg->extra_data));

                    // msg->data[0] contains the HDAT TPM info instance
                    // to populate
                    err = RUNTIME::populate_TpmInfoByNode(msg->data[0]);
                    if(err)
                    {
                        TRACFCOMP( g_trac_ipc, ERR_MRK"IpcSp::msgHandler: populate_TpmInfoByNode errored - must shutdown now!!!");
                    }
                }

                if (err)
                {
                    const auto l_errEid = err->eid();
                    errlCommit(err, IPC_COMP_ID);
                    INITSERVICE::doShutdown(l_errEid, true);
                }

                if(mod_loaded)
                {
                    err = VFS::module_unload( "libruntime.so" );

                    if (err)
                    {
                        errlCommit(err, IPC_COMP_ID);
                    }
                    mod_loaded = false;
                }

                // give a response back to the sender
                err = MBOX::send(MBOX::HB_POP_TPM_INFO_MSGQ, msg, msg->data[1]);
                if (err)
                {
                    const auto l_errEid = err->eid();
                    errlCommit(err,IPC_COMP_ID);
                    msg_free(msg);
                    INITSERVICE::doShutdown(l_errEid, true);
                }
                break;
            }

            case IPC_POPULATE_ATTRIBUTES:
                // make sure runtime module is loaded
                if ( !VFS::module_is_loaded( "libruntime.so" ) )
                {
                    err = VFS::module_load( "libruntime.so" );

                    if ( err )
                    {
                        TRACFCOMP( g_trac_ipc,
                                   "Could not load runtime module" );
                    }
                    else
                    {
                        mod_loaded = true;
                    }
                }

                if(!err)
                {
                    // msg->extra_data contains PAYLOAD Base
                    RUNTIME::setPayloadBaseAddress(
                        reinterpret_cast<uint64_t>(msg->extra_data));

                    // msg->data[0] contains the node number
                    err = RUNTIME::populate_HbRsvMem( msg->data[0] );
                }

                if (err)
                {
                    TRACFCOMP( g_trac_ipc, "In ipcSp: populate_node_attribute errored - must shutdown now!!!");
                    uint32_t l_errEid = err->eid();
                    errlCommit(err, IPC_COMP_ID);
                    INITSERVICE::doShutdown(l_errEid, true);
                }

                if(mod_loaded)
                {
                    err = VFS::module_unload( "libruntime.so" );

                    if (err)
                    {
                        errlCommit(err, IPC_COMP_ID);
                    }
                    mod_loaded = false;
                }

                // Respond
                err = MBOX::send(MBOX::HB_POP_ATTR_MSGQ, msg, msg->data[1] );
                if (err)
                {
                    uint32_t l_errEid = err->eid();
                    errlCommit(err,IPC_COMP_ID);
                    INITSERVICE::doShutdown(l_errEid, true);
                }
                break;

            case IPC_TEST_CONNECTION:

                TRACFCOMP( g_trac_ipc,
                           "IPC received the test connection msg - %d:%d",
                            msg->data[0], msg->data[1] );

                // Tell this HB node about the other HB node
                err = INTR::addHbNode(msg->data[1]);
                if( err)
                {
                    errlCommit(err,IPC_COMP_ID);
                }

                //Send a response to indicate the connection has been
                //established
                err = MBOX::send(MBOX::HB_COALESCE_MSGQ, msg, msg->data[1] );

                if (err)
                {
                    errlCommit(err,IPC_COMP_ID);
                }
                break;

            case IPC_QUERY_CHIPINFO:
            {
                TARGETING::TargetHandleList l_procChips;
                getAllChips( l_procChips, TARGETING::TYPE_PROC , true);
                uint64_t l_systemFabricConfigurationMap = 0x0;
                for(auto l_proc : l_procChips)
                {
                    // Get fabric info from proc
                    uint8_t l_fabricTopoId =
                        l_proc->getAttr<TARGETING::ATTR_PROC_FABRIC_EFF_TOPOLOGY_ID>();
                    // Take topology ID X and set the Xth bit in a 16 bit integer
                    // and shift it over by 48 bits to fit 64 bits
                    // Math turns out to be shifting left by 63 - topology id
                    l_systemFabricConfigurationMap |= (1 << (63 - l_fabricTopoId));
                }

                TRACFCOMP( g_trac_ipc,
                           "IPC Query ChipInfo 0x%llX", l_systemFabricConfigurationMap);

                //Send a response with this HB instances chip info
                msg->extra_data = reinterpret_cast<uint64_t*>(l_systemFabricConfigurationMap);
                err = MBOX::send(MBOX::HB_SBE_SYSCONFIG_MSGQ, msg, msg->data[1] );
                if (err)
                {
                    uint32_t l_errEid = err->eid();
                    errlCommit(err,IPC_COMP_ID);
                    INITSERVICE::doShutdown(l_errEid, true);
                }
                break;
             }
             case IPC_SET_SBE_CHIPINFO:
             {
                //Need to send System Configuration down to SBE
                //Primary sends info to set into SBE via msg->extra_data
                uint64_t l_systemFabricConfigurationMap =
                        reinterpret_cast<uint64_t>(msg->extra_data);

                TRACFCOMP( g_trac_ipc,
                           "sending systemConfig[0x%lx] to SBEs",
                           l_systemFabricConfigurationMap);

                TARGETING::TargetHandleList l_procChips;
                getAllChips( l_procChips, TARGETING::TYPE_PROC , true);
                for(auto l_proc : l_procChips)
                {
                    TRACDCOMP( g_trac_ipc,
                               "calling sendSystemConfig on proc 0x%x",
                               TARGETING::get_huid(l_proc));
                    err = SBEIO::sendSystemConfig(l_systemFabricConfigurationMap,
                                                    l_proc);
                    if ( err )
                    {
                        TRACFCOMP( g_trac_ipc,
                                   "sendSystemConfig ERROR : Error sending sbe chip-op to proc 0x%.8X. Returning errorlog, reason=0x%x",
                                   TARGETING::get_huid(l_proc),
                                   err->reasonCode() );
                        break;
                    }
                }

                //If error terminate here
                if(err)
                {
                    TRACFCOMP( g_trac_ipc, "In ipcSp: SBEIO::sendSystemConfig errored - must shutdown now!!!");
                    uint32_t l_errEid = err->eid();
                    errlCommit(err, IPC_COMP_ID);
                    INITSERVICE::doShutdown(l_errEid, true);
                }
                else
                {
                    TRACFCOMP( g_trac_ipc,
                               "Successfully sent all system configs to procs via SBE chip op !!");
                }

                TRACFCOMP( g_trac_ipc,
                           "sending Topology Id Tables to SBEs");
                err = SBEIO::psuSendTopologyIdTable();
                if(err)
                {
                    TRACFCOMP( g_trac_ipc, "In ipcSp: SBEIO::psuSendTopologyIdTable errored - must shutdown now!!!");
                    uint32_t l_errEid = err->eid();
                    errlCommit(err, IPC_COMP_ID);
                    INITSERVICE::doShutdown(l_errEid, true);
                }
                else
                {
                    TRACFCOMP( g_trac_ipc,
                               "Successfully sent topology id tables via SBE chip op !!");
                }

                //Send response back to the primary HB to indicate successful configuration down to SBE
                err = MBOX::send(MBOX::HB_SBE_SYSCONFIG_MSGQ, msg, msg->data[1] );
                if (err)
                {
                    uint32_t l_errEid = err->eid();
                    errlCommit(err,IPC_COMP_ID);
                    INITSERVICE::doShutdown(l_errEid, true);
                }
                break;
             }

            case IPC_FREQ_ATTR_DATA:
            {

                TRACFCOMP( g_trac_ipc,
                           "IPC received the IPC_FREQ_ATTR_DATA msg - %u:%u",
                            msg->data[0]>>32, (msg->data[0]& 0xFFFFFFFF));

                const int NUM_MOD = 2;
                const char * mods[NUM_MOD] =
                   { "libistep21.so","libruntime.so"};
                bool loaded_mods[NUM_MOD] = {false, false};
                for (auto cnt = 0; cnt < NUM_MOD; ++cnt)
                {
                    if ( !VFS::module_is_loaded( mods[cnt] ) )
                    {
                        err = VFS::module_load( mods[cnt] );

                        if ( err )
                        {
                            TRACFCOMP( g_trac_ipc,
                                       "Could not load %s module", mods[cnt] );
                            break;
                        }
                        else
                        {
                            loaded_mods[cnt] = true;
                        }
                    }
                }

                if(!err)
                {
#ifndef CONFIG_VPO_COMPILE
                    uint32_t pstate = msg->data[1];

                    //  Function checks frequency attribute data. Returns an error
                    //  if there is a mismatch with that of HB primary data
                    // temporary hack to send wrong pstate
                    err = ISTEP_21::callCheckFreqAttrData(pstate);
#endif
                }

                if (err)
                {
                   uint32_t l_errEid = err->eid();
                   errlCommit(err,IPC_COMP_ID);
                   INITSERVICE::doShutdown(l_errEid, true);
                }

                for (auto cnt = 0; cnt < NUM_MOD; ++cnt)
                {
                    if ( loaded_mods[cnt] )
                    {
                        err = VFS::module_unload( mods[cnt] );

                        if (err)
                        {
                            errlCommit(err, IPC_COMP_ID);
                        }
                        loaded_mods[cnt] = false;
                    }

                }

                 //Send response back to the primary HB to indicate valid freq attrs
                 err = MBOX::send(MBOX::HB_FREQ_ATTR_DATA_MSGQ, msg, (msg->data[0]& 0xFFFFFFFF) );

                 if (err)
                 {
                    uint32_t l_errEid = err->eid();
                    errlCommit(err,IPC_COMP_ID);
                    INITSERVICE::doShutdown(l_errEid, true);
                 }



             break;

            }

             case IPC_START_PAYLOAD:
            {
                // Save off the Payload ATTN area address that is passed to the
                // slave nodes as extra_data.
                uint64_t l_payloadAttnAreaAddr =
                    reinterpret_cast<uint64_t>(msg->extra_data);
                KernelMisc::g_payload_attn_area_addr = l_payloadAttnAreaAddr;
                const int NUM_MOD = 4;
                const char * mods[NUM_MOD] =
                   {"libp9_cpuWkup.so", "libistep21.so", "libpm.so",
                   "libruntime.so"};
                bool loaded_mods[NUM_MOD] = {false, false, false};
                for (auto cnt = 0; cnt < NUM_MOD; ++cnt)
                {
                    if ( !VFS::module_is_loaded( mods[cnt] ) )
                    {
                        err = VFS::module_load( mods[cnt] );

                        if ( err )
                        {
                            TRACFCOMP( g_trac_ipc,
                                       "Could not load %s module", mods[cnt] );
                            break;
                        }
                        else
                        {
                            loaded_mods[cnt] = true;
                        }
                    }
                }

                if (err) break;

#ifndef CONFIG_VPO_COMPILE
               err = ISTEP_21::enableCoreCheckstops();

                if (err)
                {
                    // Commit the error but continue to shutdown
                    errlCommit(err, IPC_COMP_ID);
                }

                //  Function will not return unless error

                err = ISTEP_21::callShutdown(msg->data[0],false,
                                             msg->data[1]);

                if(err)
                {
                    uint32_t l_errEid = err->eid();
                    errlCommit(err, IPC_COMP_ID);
                    INITSERVICE::doShutdown(l_errEid, true);
                }
#endif
                for (auto cnt = 0; cnt < NUM_MOD; ++cnt)
                {
                    if ( loaded_mods[cnt] )
                    {
                        err = VFS::module_unload( mods[cnt] );

                        if (err)
                        {
                            errlCommit(err, IPC_COMP_ID);
                        }
                        loaded_mods[cnt] = false;
                    }

                }

                msg_free(msg);

                break;
            }

            case IPC_CLOSE_TCES:
            {
               TRACFCOMP( g_trac_ipc,
                          "Closing TCEs on this node (%d)",
                          TARGETING::UTIL::getCurrentNodePhysId());

                // make sure util module is loaded
                const char * libutil = "libutil.so";
                if ( !VFS::module_is_loaded( libutil ) )
                {
                    err = VFS::module_load( libutil );

                    if ( err )
                    {
                        TRACFCOMP( g_trac_ipc,
                                   "Could not load util module" );
                    }
                    else
                    {
                        mod_loaded = true;
                    }
                }

                if(!err)
                {
                    err = TCE::utilClosePayloadTces();
                }

                if(!err)
                {
                    err = TCE::utilDisableTces();
                }

                if(err)
                {
                    uint32_t l_errEid = err->eid();
                    errlCommit(err, IPC_COMP_ID);
                    INITSERVICE::doShutdown(l_errEid, true);
                }

                if(mod_loaded)
                {
                    err = VFS::module_unload( libutil );

                    if (err)
                    {
                        errlCommit(err, IPC_COMP_ID);
                    }
                    else
                    {
                        mod_loaded = false;
                    }
                }

                // Respond
                err = MBOX::send(MBOX::HB_CLOSE_TCES_MSGQ, msg, msg->data[1] );
                if (err)
                {
                    uint32_t l_errEid = err->eid();
                    errlCommit(err,IPC_COMP_ID);
                    INITSERVICE::doShutdown(l_errEid, true);
                }

                break;
            }

            #ifdef CONFIG_TPMDD
            case IPC_PCR_EXTEND:
            {
                const auto receiverNode = TU::getCurrentNodePhysId();
                TRACFCOMP(g_trac_ipc, INFO_MRK
                          "IPC_PCR_EXTEND: Received IPC request to extend a "
                          "measurement to primary TPM on node (%d)",
                          receiverNode);

                void* pRequest = nullptr;
                uint8_t* pDigest = nullptr;
                uint8_t* pLogMsg = nullptr;
                const size_t senderNode = (msg->data[0] & 0xFFFFFFFF);
                size_t transactionId = 0;

                do {

                const size_t intendedReceiverNode = (msg->data[0] >> 32);
                if(receiverNode != intendedReceiverNode)
                {
                    TRACFCOMP(g_trac_ipc, ERR_MRK
                              "IPC_PCR_EXTEND: message routed to node %d but "
                              "arrived on node %d.",
                              intendedReceiverNode,receiverNode);
                    /*@
                    * @errortype
                    * @severity   ERRL_SEV_UNRECOVERABLE
                    * @moduleid   IPC::MOD_IPCSP_MSGHDLR
                    * @reasoncode IPC::RC_INCORRECT_NODE_ROUTING
                    * @userdata1  Intended receiver node
                    * @userdata2  Actual receiver node
                    * @devdesc    Sender node's IPC_PCR_EXTEND message was
                    *             routed to an unintended receiver node.  This
                    *             likely indicates a code bug.
                    * @custdesc   Internal firmware error with trusted boot
                    *             impact
                    */
                    err = new ERRORLOG::ErrlEntry(
                        ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                        IPC::MOD_IPCSP_MSGHDLR,
                        IPC::RC_INCORRECT_NODE_ROUTING,
                        intendedReceiverNode,
                        receiverNode,
                        ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
                    break;
                }

                auto * const reqPhysAddr =
                    reinterpret_cast<void*>(msg->extra_data);
                if(reqPhysAddr == nullptr)
                {
                    TRACFCOMP(g_trac_ipc, ERR_MRK
                              "IPC_PCR_EXTEND: Sender node's IPC_PCR_EXTEND "
                              "message did not contain a valid physical "
                              "address. " TRACE_ERR_FMT,
                              TRACE_ERR_ARGS(err));
                    /*@
                    * @errortype
                    * @severity   ERRL_SEV_UNRECOVERABLE
                    * @moduleid   IPC::MOD_IPCSP_MSGHDLR
                    * @reasoncode IPC::RC_BAD_PHYS_ADDR
                    * @userdata1  Node claimed to have sent the message
                    * @devdesc    Sender node's IPC_PCR_EXTEND message did not
                    *             contain a valid physical address
                    * @custdesc   Internal firmware error with trusted boot
                    *             impact
                    */
                    err = new ERRORLOG::ErrlEntry(
                        ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                        IPC::MOD_IPCSP_MSGHDLR,
                        IPC::RC_BAD_PHYS_ADDR,
                        senderNode,
                        0,
                        ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
                    break;
                }

                // Map physical address into VM, should be page aligned
                const auto reqSize = msg->data[1];
                pRequest = mm_block_map(reqPhysAddr,reqSize);
                if(pRequest == nullptr)
                {
                    TRACFCOMP(g_trac_ipc, ERR_MRK
                              "IPC_PCR_EXTEND: failed in call to mm_block_map. "
                              "reqPhysAddr = %p, reqSize = %d. " TRACE_ERR_FMT,
                              reqPhysAddr, reqSize, TRACE_ERR_ARGS(err));
                    /*@
                    * @errortype
                    * @severity   ERRL_SEV_UNRECOVERABLE
                    * @moduleid   IPC::MOD_IPCSP_MSGHDLR
                    * @reasoncode IPC::RC_BLOCK_MAP_FAIL
                    * @userdata1  Physical address
                    * @userdata2  Size of mapping
                    * @devdesc    Failed to map physical address into the VMM
                    * @custdesc   Internal firmware error with trusted boot
                    *             impact
                    */
                    err = new ERRORLOG::ErrlEntry(
                        ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                        IPC::MOD_IPCSP_MSGHDLR,
                        IPC::RC_BLOCK_MAP_FAIL,
                        reinterpret_cast<uint64_t>(reqPhysAddr),
                        reqSize,
                        ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
                    break;
                }

                // UtilMem object doesn't own the memory, it's just used to
                // deserialize the message data
                UtilMem request(pRequest,reqSize);

                TB::TPM_Pcr pcr = TB::PLATFORM_PCR; // Start with unsupported PCR
                TB::EventTypes eventType = TB::EV_INVALID;
                size_t digestSize = 0;
                size_t logMsgSize = 0;

                request >> transactionId >> pcr >> eventType >> digestSize;
                err = request.getLastError();
                if(err)
                {
                    TRACFCOMP(g_trac_ipc, ERR_MRK
                              "IPC_PCR_EXTEND: failed to deserialize message "
                              "through digestSize field. " TRACE_ERR_FMT,
                              TRACE_ERR_ARGS(err));
                    break;
                }

                TRACFCOMP(g_trac_ipc, INFO_MRK
                          "Transaction ID for this request = 0x%016llX",
                          transactionId);

                pDigest = reinterpret_cast<uint8_t*>(calloc(1,digestSize));

                request.read(pDigest,digestSize);
                request >> logMsgSize;
                err = request.getLastError();
                if(err)
                {
                    TRACFCOMP(g_trac_ipc, ERR_MRK
                              "IPC_PCR_EXTEND: failed to deserialize message "
                              "through logMsgSize field. " TRACE_ERR_FMT,
                              TRACE_ERR_ARGS(err));
                    break;
                }
                pLogMsg = reinterpret_cast<uint8_t*>(calloc(1,digestSize));
                request.read(pLogMsg,logMsgSize);
                err=request.getLastError();
                if(err)
                {
                    TRACFCOMP(g_trac_ipc, ERR_MRK
                              "IPC_PCR_EXTEND: failed to deserialize message "
                              "through logMsg field. " TRACE_ERR_FMT,
                              TRACE_ERR_ARGS(err));
                    break;
                }

                const bool sendAsync = true;
                const bool extendToTpm = true;
                const bool extendToSwLog = true;
                // Prevent receiver of node measurement from itself mirroring
                // the request to the other nodes
                const bool inhibitNodeMirroring = true;

                // Note: nullptr as the target will force the TPM daemon to
                // select the primary TPM by default.  It's ok to extend if the
                // primary TPM is already poisoned.  If it's non-functional the
                // extend will be dropped on the floor.
                TARGETING::Target* pPrimaryTpm = nullptr;
                err = pcrExtend(pcr,
                                eventType,
                                pDigest,
                                digestSize,
                                pLogMsg,
                                logMsgSize,
                                sendAsync,
                                pPrimaryTpm,
                                extendToTpm,
                                extendToSwLog,
                                inhibitNodeMirroring);
                if(err)
                {
                    TRACFCOMP(g_trac_ipc, ERR_MRK
                              "IPC_PCR_EXTEND: failed in call to pcrExtend. "
                              "pcr = %d, eventType = 0x%02X, digestSize = %d, "
                              "logMsgSize = %d. " TRACE_ERR_FMT,
                              pcr,eventType,digestSize,logMsgSize,
                              TRACE_ERR_ARGS(err));
                    break;
                }

                } while(0); // All errors funnel down to here

                if(pRequest)
                {
                    const auto rc = mm_block_unmap(pRequest);
                    if(rc != 0)
                    {
                        TRACFCOMP(g_trac_ipc, ERR_MRK
                                 "IPC_PCR_EXTEND: Unexpected bad rc %d from "
                                 "mm_block_unmap for virtual address %p.",
                                 rc,pRequest);
                        /*@
                        * @errortype
                        * @severity   ERRL_SEV_UNRECOVERABLE
                        * @moduleid   IPC::MOD_IPCSP_MSGHDLR
                        * @reasoncode IPC::RC_BLOCK_UNMAP_FAIL
                        * @userdata1  Return code from mm_block_unmap
                        * @userdata2  Virtual memory address to unmap
                        * @devdesc    Failed to unmap a virtual to physical
                        *             memory mapping previously created via
                        *             mm_block_map.
                        * @custdesc   Internal firmware error with trusted boot
                        *             impact
                        */
                        auto pUnmapErr = new ERRORLOG::ErrlEntry(
                            ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                            IPC::MOD_IPCSP_MSGHDLR,
                            IPC::RC_BLOCK_UNMAP_FAIL,
                            rc,
                            reinterpret_cast<uint64_t>(pRequest),
                            ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
                        if(err)
                        {
                            pUnmapErr->plid(err->plid());
                            errlCommit(pUnmapErr,IPC_COMP_ID);
                        }
                        else
                        {
                            err = pUnmapErr;
                            pUnmapErr = nullptr;
                        }
                    }
                }

                // Ok to free pointers that are already nullptr
                free(pDigest);
                pDigest = nullptr;

                free(pLogMsg);
                pLogMsg = nullptr;

                if(err)
                {
                    TRACFCOMP(g_trac_ipc, ERR_MRK
                              "IPC_PCR_EXTEND: fatal firmware error, shutting "
                              "down.  " TRACE_ERR_FMT,
                              TRACE_ERR_ARGS(err));
                }
                else
                {
                    const auto destNode = senderNode;
                    err = MBOX::send(MBOX::HB_IPC_EXTEND_PCR_MSGQ,
                                     msg, destNode);
                    if (err)
                    {
                        TRACFCOMP(g_trac_ipc, ERR_MRK
                                "IPC_PCR_EXTEND: fatal error in MBOX::send to "
                                "node %d, shutting down. " TRACE_ERR_FMT,
                                destNode,TRACE_ERR_ARGS(err));
                    }
                    else
                    {
                        TRACFCOMP(g_trac_ipc, INFO_MRK
                                  "IPC_PCR_EXTEND: sent response to node %d "
                                  "for transaction ID 0x%016llX.",
                                  destNode,transactionId);
                    }
                }

                if(err)
                {
                    err->collectTrace(MBOX_TRACE_NAME);
                    err->collectTrace(MBOXMSG_TRACE_NAME);
                    err->collectTrace(IPC_TRACE_NAME);

                    const auto eid = err->eid();
                    errlCommit(err,IPC_COMP_ID);
                    const bool inBackground = true;
                    INITSERVICE::doShutdown(eid,inBackground);
                }

                break;
            }
            #endif // End CONFIG_TPMDD specific code

             case IPC_GET_PHYP_HRMOR:
             {
                TRACFCOMP( g_trac_ipc,
                           "IPC received the IPC_GET_PHYP_HRMOR msg - %u:%u",
                            msg->data[0]>>32, (msg->data[0]& 0xFFFFFFFF));

                // this should only be received by the primary node
                const auto l_myNode = TARGETING::UTIL::getCurrentNodePhysId();
                int l_primaryNode = TARGETING::UTIL::getPrimaryNodeNumber();
                assert( l_myNode == l_primaryNode,
                        "IPC_GET_PHYP_HRMOR send to non-primary node" );

                // remember which node sent the message
                IPC::getPhypHrmor_t* my_msg =
                  reinterpret_cast<IPC::getPhypHrmor_t*>(msg);
                int sender = my_msg->sendingNode;

                // fill in the response
                my_msg->payloadAddr =
                  TARGETING::UTIL::assertGetToplevelTarget()
                  ->getAttr<TARGETING::ATTR_PAYLOAD_BASE>();

                //Send response back to the sending HB to indicate valid freq attrs
                err = MBOX::send(MBOX::HB_GET_PHYP_HRMOR_MSGQ,
                                 msg, sender );
                if (err)
                {
                    errlCommit(err,IPC_COMP_ID);
                }

                break;
            }

            default:

                TRACFCOMP( g_trac_ipc,
                           "IPC received an unexpected message type of %d",
                           msg->type);

                /*@ errorlog tag
                 * @errortype  ERRL_SEV_INFORMATIONAL
                 * @moduleid   IPC::MOD_IPCSP_MSGHDLR
                 * @reasoncode IPC::RC_INVALID_MSG_TYPE
                 * @userdata1  Message type
                 * @userdata2  Data word 0 of message
                 *
                 * @devdesc    IPC service provider received an unexpected
                 *             message.
                 *
                 */
                err = new ERRORLOG::ErrlEntry
                    (
                     ERRORLOG::ERRL_SEV_INFORMATIONAL,    // severity
                     IPC::MOD_IPCSP_MSGHDLR,              // moduleid
                     IPC::RC_INVALID_MSG_TYPE,            // reason code
                     msg->type,
                     msg->data[0],
                     true //Add HB Software Callout
                    );
                //@todo: RTC:93750 Create real parseable FFDC class
                err->addFFDC(MBOX_COMP_ID,
                             msg,
                             sizeof(msg_t),
                             1,//version
                             MBOX::MBOX_UDT_MSG_DATA);//subsect

                err->collectTrace(MBOXMSG_TRACE_NAME);
                err->collectTrace(IPC_TRACE_NAME);

                errlCommit(err, IPC_COMP_ID);

                msg_free(msg);

                break;
        }
    }
}


void IpcSp::_acquireRemoteNodeAddrs( void )
{
    if // remote addresses have not been gathered
      (iv_IsRemoteNodeAddrsValid == false)
    {
        TRACFCOMP( g_trac_ipc, ENTER_MRK"_acquireRemoteNodeAddrs" );

        TARGETING::Target * l_sys = NULL;
        TARGETING::targetService().getTopLevelTarget(l_sys);

        if (l_sys)
        {
            // If MPIPL then remote regs are no longer valid
            uint8_t l_IsMpipl =
              l_sys->getAttr<TARGETING::ATTR_IS_MPIPL_HB>();

            if (l_IsMpipl == false )
            {
                // extract current ipc addr attributes
                uint64_t l_ipcDataAddrs[MAX_NODES_PER_SYS];
                l_sys->tryGetAttr
                <TARGETING::ATTR_IPC_NODE_BUFFER_GLOBAL_ADDRESS>
                (l_ipcDataAddrs);
                TRACFBIN( g_trac_ipc, "ATTR_IPC_NODE_BUFFER_GLOBAL_ADDRESS=",l_ipcDataAddrs,sizeof(l_ipcDataAddrs) );

                // extract valid node map
                uint8_t validNodeBitMap =
                        l_sys->getAttr<TARGETING::ATTR_HB_EXISTING_IMAGE>();

                // determine which node is local
                uint64_t l_ThisNode;
                uint64_t l_RemoteAddr;
                qryLocalIpcInfo( l_ThisNode, l_RemoteAddr );
                TRACFCOMP( g_trac_ipc, "l_ThisNode=%X, l_RemoteAddr=%X",
                           l_ThisNode, l_RemoteAddr );

                // loop thru all Nodes
                for ( uint64_t i = 0;
                      i < MAX_NODES_PER_SYS;
                      i++ )
                {
                    if // remote node
                      ( i != l_ThisNode )
                    {
                        if // valid node
                          ( (validNodeBitMap & (0x80 >> i)) != 0  )
                        {
                            // read scoms for remote node
                            uint64_t l_remoteAddrHighBits =
                                    XSCOM::readRemoteScom(i,
                                    INITSERVICE::SPLESS::MboxScratch7_t::REG_ADDR);

                            uint64_t l_remoteAddrLowBits =
                                    XSCOM::readRemoteScom(i,
                                    INITSERVICE::SPLESS::MboxScratch8_t::REG_ADDR);

                            l_RemoteAddr = (l_remoteAddrHighBits ) |
                                           (l_remoteAddrLowBits >> 32);

                            TRACFCOMP( g_trac_ipc,"readRemoteScom"
                                    " node=%d, remoteAddr=0x%x",
                                    i, l_RemoteAddr);
                        } // end valid node
                        else
                        {
                            // set an invalid value for remote address
                            l_RemoteAddr = IPC_INVALID_REMOTE_ADDR | i;
                        }

                        TRACFCOMP( g_trac_ipc, "node%d = %X",
                                   i, l_RemoteAddr );

                        // push results to IPC and Attributes shadow
                        updateRemoteIpcAddr( i, l_RemoteAddr );
                        l_ipcDataAddrs[i] = l_RemoteAddr;
                    } // end remote node
                    else
                    {
                        // local node, do not need to get remote addrs
                    }
                }

                // update attributes
                l_sys->setAttr<TARGETING::ATTR_IPC_NODE_BUFFER_GLOBAL_ADDRESS>
                (l_ipcDataAddrs);
            } // end not mpipl
            else
            {
                // (remote addrs have already been shadowed from attributes)
            }

            // read the scoms only once
            iv_IsRemoteNodeAddrsValid = true;
        } // end acquire scoms

        TRACFCOMP( g_trac_ipc, EXIT_MRK"_acquireRemoteNodeAddrs" );
    } // end remote addrs not gathered
    else
    {
        // (no action needed)
    }

    return;
}
