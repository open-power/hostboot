/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/mbox/ipcSp.C $                                        */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013,2014              */
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

namespace START_PAYLOAD
{
    extern errlHndl_t callShutdown ( uint64_t i_hbInstance,
                                     bool i_masterInstance );
};

trace_desc_t* g_trac_ipc = NULL;
TRAC_INIT(&g_trac_ipc, IPC_TRACE_NAME, KILOBYTE);

using namespace IPC;
using namespace ERRORLOG;

IpcSp::IpcSp()
    :
        iv_msgQ()
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
                    err = RUNTIME::populate_node_attributes( msg->data[0] );
                }

                if (err)
                {
                    errlCommit(err, IPC_COMP_ID);
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
                    errlCommit(err,IPC_COMP_ID);
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

            case IPC_START_PAYLOAD:

                if ( !VFS::module_is_loaded( "libstart_payload.so" ) )
                {
                    err = VFS::module_load( "libstart_payload.so" );

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
                    //  Function will not return unless error
                    err = START_PAYLOAD::callShutdown(msg->data[0],false);
                }

                if(err)
                {
                    errlCommit(err, IPC_COMP_ID);
                }

                if(mod_loaded)
                {
                    err = VFS::module_unload( "libstart_payload.so" );

                    if (err)
                    {
                        errlCommit(err, IPC_COMP_ID);
                    }
                    mod_loaded = false;
                }

                msg_free(msg);

                break;


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


