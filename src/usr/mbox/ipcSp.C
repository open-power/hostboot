/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/mbox/ipcSp.C $                                        */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013                   */
/*                                                                        */
/* p1                                                                     */
/*                                                                        */
/* Object Code Only (OCO) source materials                                */
/* Licensed Internal Code Source Materials                                */
/* IBM HostBoot Licensed Internal Code                                    */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* Origin: 30                                                             */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
#include <mbox/ipc_msg_types.H>
#include "ipcSp.H"
#include <runtime/runtime.H>
#include <vfs/vfs.H>
#include <mbox/ipc_reasoncodes.H>
#include <mbox/mboxif.H>
#include <errl/errlmanager.H>

trace_desc_t* g_trac_ipc = NULL;
TRAC_INIT(&g_trac_ipc, "IPC", KILOBYTE);

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
                }

                // Respond
                err = MBOX::send(MBOX::HB_POP_ATTR_MSGQ, msg, msg->data[1] );
                if (err)
                {
                    errlCommit(err,IPC_COMP_ID);
                }
                
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
                 * @userdata2  <unused>
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
                     0
                    );

                errlCommit(err, IPC_COMP_ID);

                break;
        }
    }
}


