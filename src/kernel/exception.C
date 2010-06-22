#include <kernel/types.h>
#include <kernel/console.H>
#include <kernel/task.H>
#include <kernel/taskmgr.H>
#include <kernel/ppcarch.H>

namespace Systemcalls { void TaskEnd(task_t*); }
namespace ExceptionHandles
{
    bool HvEmulation(task_t*);
}

const uint64_t EXCEPTION_SRR1_MASK 	= 0x00000000783F0000;
const uint64_t EXCEPTION_SRR1_HVEMUL	= 0x0000000000080000;

extern "C"
void kernel_execute_prog_ex()
{
    task_t* t = TaskManager::getCurrentTask();
    uint64_t exception = ppc_getSRR1() & EXCEPTION_SRR1_MASK;

    bool handled = false;
    switch(exception)
    {
	case EXCEPTION_SRR1_HVEMUL:
	    handled = ExceptionHandles::HvEmulation(t);
	    break;
    }
    if (!handled)
    {
	printk("Program exception, killing task %d\n", t->tid);
	Systemcalls::TaskEnd(t);
    }
}

namespace ExceptionHandles
{
    bool HvEmulation(task_t* t)
    {
	/*printk("NIP = %llx : Inst = %lx\n",
	       t->context.nip,
	       (*(uint32_t*)t->context.nip));*/

	uint32_t instruction = *(uint32_t*)t->context.nip;

	    // check for mfsprg3
	if ((instruction & 0xfc1fffff) == 0x7c1342a6)
	{
	    t->context.gprs[(instruction & 0x03E00000) >> 21] = 
		    (uint64_t) t;
	    t->context.nip = (void*) (((uint64_t)t->context.nip)+4);
	    return true;
	}

	return false;
    }

}
