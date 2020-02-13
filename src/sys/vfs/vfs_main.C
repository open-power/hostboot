/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/sys/vfs/vfs_main.C $                                      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2010,2020                        */
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
#include <string.h>
#include <errno.h>

#include <sys/msg.h>
#include <sys/vfs.h>
#include <sys/task.h>
#include <sys/sync.h>

#include <util/locked/list.H>
#include <kernel/console.H>  // TODO : Remove this.

const char* VFS_ROOT = "/";
const char* VFS_ROOT_BIN = "/bin/";
const char* VFS_ROOT_DATA = "/data/";
const char* VFS_ROOT_MSG = "/msg/";
const char* VFS_ROOT_MSG_VFS = "/msg/vfs";
const char* VFS_ROOT_MSG_MBOX = "/msg/mbox";
const char* VFS_ROOT_MSG_MCTP_IN = "/msg/mctpin";
const char* VFS_ROOT_MSG_MCTP_OUT = "/msg/mctpout";
const char* VFS_ROOT_MSG_PLDM_REQ_IN = "/msg/pldmreqin";
const char* VFS_ROOT_MSG_PLDM_RSP_IN = "/msg/pldmrspin";
const char* VFS_ROOT_MSG_PLDM_REQ_OUT= "/msg/pldrreqout";

void vfs_module_init();

struct VfsPath
{
    char key[64];

    bool operator!=(VfsPath& r) { return 0 != strcmp(key, r.key); };
};

struct VfsEntry
{
    typedef VfsPath key_type;
    key_type key;
    msg_q_t msg_q;

    VfsEntry* next;
    VfsEntry* prev;
};

void* vfs_main(void* i_barrier)
{
    // Detach this task from the parent
    task_detach();

    barrier_t * barrier = (barrier_t *)i_barrier;
    // Create message queue, register with kernel.
    msg_q_t vfsMsgQ = msg_q_create();
    msg_q_register(vfsMsgQ, VFS_ROOT);

    printk("done.\n");

    // Initalize modules.
    vfs_module_init();

    // Signal with sys/init to continue on.
    barrier_wait(barrier);

    Util::Locked::List<VfsEntry, VfsEntry::key_type> vfsContents;

    while(1)
    {
        msg_t* msg = msg_wait(vfsMsgQ);

        switch(msg->type)
        {
            case VFS_MSG_REGISTER_MSGQ:
                {
                    VfsEntry* e = new VfsEntry();
                    strcpy(e->key.key, (char*) msg->extra_data);
                    e->msg_q = (msg_q_t) msg->data[0];
                    vfsContents.insert(e);

                    printkd("VFS: Registering %p as %s\n",
                            e->msg_q, e->key.key);
                    msg_respond(vfsMsgQ, msg);
                }
                break;

            case VFS_MSG_REMOVE_MSGQ:
                {
                    VfsEntry::key_type k;
                    strcpy(k.key, (char*) msg->extra_data);
                    VfsEntry* e = vfsContents.find(k);
                    if(NULL != e)
                    {
                        msg->data[0] = 0; //(uint64_t) e->msg_q;
                        printkd("VFS: Removing msg queue %s\n",e->key.key);
                        vfsContents.erase(e);
                        delete e;
                    }
                    else
                    {
                        msg->data[0] = (uint64_t) (-ENXIO);
                    }
                    msg_respond(vfsMsgQ, msg);
                }
                break;

            case VFS_MSG_RESOLVE_MSGQ:
                {
                    VfsEntry::key_type k;
                    strcpy(k.key, (char*) msg->extra_data);
                    VfsEntry* e = vfsContents.find(k);
                    if (NULL == e)
                        msg->data[0] = (uint64_t) NULL;
                    else
                        msg->data[0] = (uint64_t) e->msg_q;
                    msg_respond(vfsMsgQ, msg);
                }
                break;

            case VFS_MSG_EXEC:
                {
                    printkd("VFS: Got exec request of %s\n",
                            (const char*)msg->data[0]);

                    VfsSystemModule* module =
                        vfs_find_module(VFS_MODULES,
                                        (const char *) msg->data[0]);

                    void* fnptr = vfs_start_entrypoint(module);

                    // child == -ENOENT means module not found in base image
                    // so send a message to VFS_MSG queue to look in the
                    // extended image VFS_MSG queue will handle the
                    // msg_respond()
                    if( fnptr == reinterpret_cast<void*>(-ENOENT) )
                        // forward msg to usr vfs
                    {
                        VfsEntry::key_type k;
                        strcpy(k.key, VFS_ROOT_MSG_VFS);
                        VfsEntry* e = vfsContents.find(k);
                        if(e != NULL)
                        {
                            msg_t* emsg = msg_allocate();
                            emsg->type = msg->type;
                            emsg->data[0] = (uint64_t) msg;
                            emsg->data[1] = (uint64_t) vfsMsgQ;
                            msg_send(e->msg_q, emsg); // send async msg
                        }
                        else  // Can't find VFS_MSG queue - not started yet
                        {
                            msg->data[0] = (uint64_t) fnptr;
                            msg_respond(vfsMsgQ, msg);
                        }
                    }
                    else // send back child (or errno)
                    {
                        msg->data[0] = (uint64_t) fnptr;
                        msg_respond(vfsMsgQ, msg);
                    }
                }
                break;

            default:
                msg_free(msg);
                break;
        }
    }   // end while(1)
    return NULL;
}

// ----------------------------------------------------------------------------

void* vfs_start_entrypoint(VfsSystemModule * i_module)
{
    void* ptr = reinterpret_cast<void*>(-ENOENT);
    if(i_module != NULL)
    {
        if (i_module->start == NULL)
        {
            // module has no start() routine
            ptr = reinterpret_cast<void*>(-ENOEXEC);
        }
        else
        {
            ptr = reinterpret_cast<void*>(i_module->start);
        }
    }
    return ptr;
}
