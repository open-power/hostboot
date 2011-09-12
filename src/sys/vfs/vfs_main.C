//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/sys/vfs/vfs_main.C $
//
//  IBM CONFIDENTIAL
//
//  COPYRIGHT International Business Machines Corp. 2010 - 2011
//
//  p1
//
//  Object Code Only (OCO) source materials
//  Licensed Internal Code Source Materials
//  IBM HostBoot Licensed Internal Code
//
//  The source code for this program is not published or other-
//  wise divested of its trade secrets, irrespective of what has
//  been deposited with the U.S. Copyright Office.
//
//  Origin: 30
//
//  IBM_PROLOG_END
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

void vfs_module_init();

/**
 * Call the module start routine
 * @param[in] i_module VfsSystemModule data for the module
 * @param[in] i_param parameter to pass to task_create() for this module
 * @return tid_t of started task or negative value on error.
 * @retval -ENOENT if i_module is NULL
 * @retval -ENOEXEC if there is no start()
 */
tid_t vfs_exec(VfsSystemModule * i_module, void* i_param);

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

void vfs_main(void* i_barrier)
{
    barrier_t * barrier = (barrier_t *)i_barrier;
    // Create message queue, register with kernel.
    msg_q_t vfsMsgQ = msg_q_create();
    msg_q_register(vfsMsgQ, VFS_ROOT);

    printk("done.\n");

    barrier_wait(barrier);

    // Initalize modules.
    vfs_module_init();

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

		    tid_t child = vfs_exec(module,(void*) msg->data[1]);

                    // child == -ENOENT means module not found in base image
                    // so send a message to VFS_MSG queue to look in the
                    // extended image VFS_MSG queue will handle the
                    // msg_respond()
                    if( child == (tid_t)-ENOENT ) // forward msg to usr vfs
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
                        else  // Cant find VFS_MSG queue - not started yet
                        {
                            msg->data[0] =  child;
                            msg_respond(vfsMsgQ, msg);
                        }
                    }
                    else // send back child (or errno)
                    {
                        msg->data[0] = child;
                        msg_respond(vfsMsgQ, msg);
                    }
		}
		break;

	    default:
		msg_free(msg);
		break;
	}
    }   // end while(1)
}

// ----------------------------------------------------------------------------

tid_t vfs_exec(VfsSystemModule * i_module, void* i_param)
{
    tid_t child = -ENOENT;
    if(i_module != NULL)
    {
        if (i_module->start == NULL)
        {
            child = -ENOEXEC;  // module has no start() routine
        }
        else
        {
            child = task_create(i_module->start, i_param);
        }
    }
    return child;
}



