/*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/include/kernel/deferred.H $
 *
 *  IBM CONFIDENTIAL
 *
 *  COPYRIGHT International Business Machines Corp. 2012
 *
 *  p1
 *
 *  Object Code Only (OCO) source materials
 *  Licensed Internal Code Source Materials
 *  IBM HostBoot Licensed Internal Code
 *
 *  The source code for this program is not published or other-
 *  wise divested of its trade secrets, irrespective of what has
 *  been deposited with the U.S. Copyright Office.
 *
 *  Origin: 30
 *
 *  IBM_PROLOG_END_TAG
 */
#ifndef __KERNEL_DEFERRED_H
#define __KERNEL_DEFERRED_H

/** @file deferred.H
 *  @brief Definition of kernel's deferred work constructs.
 *
 *  These classes allow the kernel to synchronize all CPUs into kernel-mode
 *  and execute a task.  These work items are queued up to be executed at
 *  the next time-slice expiration (decrementer exception).
 */

#include <kernel/types.h>
#include <kernel/spinlock.H>
#include <kernel/barrier.H>

/** @class DeferredWork
 *  @brief The base work-item type for deferred work.
 *
 *  This class implements the synchronization and state transition for a
 *  general deferred work object.  This class has methods for defining
 *  the behavior at specific points in its execution.  A real behavior
 *  implementation should be defined by inheriting this class and overloading
 *  the desired virtual methods.
 *
 *  The class is closely associated with the DeferredQueue, which is meant to
 *  hold pending DeferredWork objects.  When a DeferredWork is complete it
 *  will remove itself from the DeferredQueue and self-delete.
 *
 *  The state transition is as follows:
 *
 *  <pre>
 *        MASTER           Both            NON-MASTER
 *  1.                   Sync all
 *  2.  masterPreWork                         block
 *  3.                activeMainWork
 *  4.                   Sync all
 *  5.  masterPostWork                        block
 *  6.              Last thread out deletes
 *  </pre>
 *
 *  With the deferred work there is concern as to what to do with CPUs that
 *  come online while a deferred work item is being executed.  For instance,
 *  the Heap Coalescing work could cause data integrity issues if a freshly
 *  activated CPU were to not block with the rest of the CPUs and instead
 *  started executed user-space code.  To deal with this condition a
 *  CPU which is activated after the DeferredWork object was created will
 *  block at masterPreWork and masterPostWork stages and call
 *  nonactiveMainWork.  Typically, the non-active CPUs perform no action
 *  but an implementation could assert for a race-condition that cannot
 *  be handled properly (though should never occur).
 */
class DeferredWork
{
    public:
        /** Default Constructor
         *  Initializes the work item and determines the CPU-activation
         *  sequence number at the time of creation.
         */
        DeferredWork();

        /** Default destructor
         *  Verifies that the work item has completed properly and is
         *  detached from the DeferredQueue.
         */
        virtual ~DeferredWork();

        /** Entry point for DeferredWork execution. */
        void start();

    protected:
        // Functions to override for desired behavior:
            /** Executed by master before "main" but after all active
             *  CPUs are sync'd.
             */
        virtual void masterPreWork() {};
            /** Executed by master after "main" work is complete. */
        virtual void masterPostWork() {};
            /** Executed by all [active] CPUs as the "main" work. */
        virtual void activeMainWork() {};
            /** Executed by all non-active CPUs as the "main" work. */
        virtual void nonactiveMainWork() {};

    private:
        friend class DeferredQueue;

            /** Barrier for synchronization of active CPUs. */
        Barrier iv_barrier;
            /** Count of CPUs in object and pointer to next object.
             *
             *  Stored as "(cpu count << 32) | (DeferredWork* next)".  This
             *  is done so that we can atomically check and/or set both
             *  values.
             */
        volatile uint64_t iv_cpus_and_next;
            /** Sequence ID at the time of creation. */
        uint32_t iv_activeSeqId;
            /** Boolean to indicate masterPreWork is complete. */
        volatile bool iv_releasePre;
            /** Boolean to indicate masterPostWork is complete. */
        volatile bool iv_releasePost;

            // Internal state transition functions.
        void _waitForCpus();
        void _masterPre();
        void _waitAtPre();
        void _masterPost();
        void _waitAtPost();
        void _cleanup();

};

/** @class DeferredQueue
 *  @brief Queue for DeferredWork objects.
 *
 *  This class should have a Singleton instance for the whole kernel.
 *  Periodically, kernel threads can call the 'execute' function to execute
 *  pending work, if any is available.  Additional work can be 'insert'ed.
 */
class DeferredQueue
{
    public:
        /** Default constructor. */
        DeferredQueue();
        /** Default destructor. */
        ~DeferredQueue();

        /** Insert a work item into the queue.
         *
         *  @param i_work - The item to add.
         *
         *  Ownership of the work item is transfered to the queue, which is
         *  responsible for delete once the work is complete.
         */
        static void insert(DeferredWork* i_work);
        /** Execute any pending work items. */
        static void execute();

    private:
        friend class DeferredWork;

            // Instance functions for static pair.
        void _insert(DeferredWork* i_work);
        void _execute();

        /** Remove a completed work item from the queue.
         *
         *  This function is to be called by the master CPU executing the
         *  work item being completed.
         *
         *  The work item is atomically removed from the queue and the
         *  count of CPUs with a pointer to the work item is compared
         *  against the count of CPUs in the work item.  This function
         *  returns when all CPUs that have a pointer are actually inside
         *  the work item (so we can accurately determine when there is
         *  only a single CPU in the work item for delete).
         *
         *  @param i_work - The item to remove.
         */
        void _complete(DeferredWork* i_work);

            /** Spinlock to protect insert / remove operations.
             *
             *  This is effectively a "write" lock on the structure and all
             *  reads are done atomically.  The writers have also use atomic
             *  update operations to ensure the readers (which are never
             *  locked) operate in a thread-safe manner.
             */
        Spinlock lock;
            /** Count of CPUs in first object and pointer to it.
             *
             *  Stored as "(cpu count << 32) | (DeferredWork* ptr)".  This
             *  is done so that we can atomically check and/or set both
             *  values.
             */
        volatile uint64_t iv_cpus_and_next;
};

#endif
