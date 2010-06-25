#include <string.h>

#include <sys/msg.h>
#include <sys/vfs.h>

#include <util/locked/list.H>
#include <kernel/console.H>  // TODO : Remove this.

const char* VFS_ROOT = "/";
const char* VFS_ROOT_BIN = "/bin/";
const char* VFS_ROOT_DATA = "/data/";
const char* VFS_ROOT_MSG = "/msg/";

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

void vfs_main(void* unused)
{
    msg_q_t vfsMsgQ = msg_q_create();
    msg_q_register(vfsMsgQ, VFS_ROOT);
    
    printk("done.\n");
    // TODO... barrier with init.

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

		    printk("VFS: Registering %llx as %s\n",
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

	    default:
		msg_free(msg);
		break;
	}
    }
}
