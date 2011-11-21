//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/kernel/idebug.C $
//
//  IBM CONFIDENTIAL
//
//  COPYRIGHT International Business Machines Corp. 2011
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
#include <kernel/idebug.H>
#include <kernel/console.H>
#include <kernel/cpumgr.H>
#include <kernel/scheduler.H>
#include <sys/task.h>

    // Set Ready = 0, Running = 1, Complete = 0.
static const uint64_t IDEBUG_RUNNING_STATE  = 0x0001000000000000ull;
    // Set Ready = 0, Running = 0, Complete = 1.
static const uint64_t IDEBUG_COMPLETE_STATE = 0x0000010000000000ull;

void InteractiveDebug::startDebugTask()
{
    // Atomically set state to 'running'.
    // Set Ready = 0, Running = 1, Complete = 0.
    __sync_lock_test_and_set(&state_value, IDEBUG_RUNNING_STATE);

    // Create userspace task to execute function.
    task_t* t = TaskManager::createTask(&debugEntryPoint, this, true);
    CpuManager::getCurrentCPU()->scheduler->addTask(t);

    return;
}

void InteractiveDebug::debugEntryPoint(void* i_idObject)
{
    // Detach task so it is cleaned up properly once it exits.
    task_detach();

    // Get interactive debug structure from cast of input paramater.
    InteractiveDebug* interactiveDebug =
        static_cast<InteractiveDebug*>(i_idObject);

    // Get function pointer from 'entry_point_toc'.
    typedef uint64_t(*func)(uint64_t,uint64_t,uint64_t,uint64_t,
                            uint64_t,uint64_t,uint64_t,uint64_t);
    func entry_point =
            reinterpret_cast<func>(interactiveDebug->entry_point_toc);

    // Call function with parameters.
    //     Due to the PowerABI, parameters get passed in r3-r10 and any
    //     unused parameters are ignored by the called function.  You can
    //     therefore treat every function as if it has 8 parameters, even
    //     if it has fewer, and the calling conventions are the same from
    //     an assembly perspective.
    interactiveDebug->return_value =
            entry_point(interactiveDebug->parms[0],
                        interactiveDebug->parms[1],
                        interactiveDebug->parms[2],
                        interactiveDebug->parms[3],
                        interactiveDebug->parms[4],
                        interactiveDebug->parms[5],
                        interactiveDebug->parms[6],
                        interactiveDebug->parms[7]);

    // Atomically set state to 'complete'.
    //     This must be proceeded by a sync to ensure all memory operations
    //     and instructions have fully completed prior to setting the complete
    //     state (due to weak consistency).
    // Set Ready = 0, Running = 0, Complete = 1.
    __sync_synchronize();
    __sync_lock_test_and_set(&interactiveDebug->state_value,
                             IDEBUG_COMPLETE_STATE);

    task_end();
}

