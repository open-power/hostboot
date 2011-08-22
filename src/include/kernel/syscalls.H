/** @file syscalls.H
 *  @brief Defines all the system call IDs to be shared between the kernel and
 *         the system libc.
 */

#ifndef __KERNEL_SYSCALLS_H
#define __KERNEL_SYSCALLS_H

namespace Systemcalls
{
    /** @enum SysCalls
     *  @brief List of normal system calls and their IDs.
     *
     *  These are passed by userspace code via r3 when the sc instruction is
     *  executed.  The kernel performs a case statement to switch to the
     *  appropriate system call handler.
     */
    enum SysCalls
    {
            /** task_yield() */
	TASK_YIELD = 0,
            /** task_create() */
	TASK_START,
            /** task_end() */
	TASK_END,

            /** msgq_create() */
	MSGQ_CREATE,
            /** msgq_destroy() */
	MSGQ_DESTROY,
            /** VFS internal */
	MSGQ_REGISTER_ROOT,
            /** VFS internal */
	MSGQ_RESOLVE_ROOT,

            /** msg_send() */
	MSG_SEND,
            /** msg_sendrecv() */
	MSG_SENDRECV,
            /** msg_respond() */
	MSG_RESPOND,
            /** msg_wait() */
	MSG_WAIT,

            /** mmio_map() */
	MMIO_MAP,
            /** mmio_unmap() */
	MMIO_UNMAP,
            /** dev_map() */
    DEV_MAP,
            /** dev_unmap() */
    DEV_UNMAP,

            /** nanosleep() */
	TIME_NANOSLEEP,

            /** futex_wait() */
    FUTEX_WAIT,
            /** futex_wake() */
    FUTEX_WAKE,

            /** shutdown() */
    MISC_SHUTDOWN,
            /** cpu_core_type() */
    MISC_CPUCORETYPE,
            /** cpu_dd_level() */
    MISC_CPUDDLEVEL,

            /** mm_alloc_block() */
    MM_ALLOC_BLOCK,

	SYSCALL_MAX
    };

    /** @enum SysCalls_FastPath
     *  @brief List of fast-path system calls and their IDs.
     *
     *  @note If any of these change, their handling in start.S must also be
     *        updated.  The ASM code relies on these values.
     */
    enum SysCalls_FastPath
    {
            /** mmio_hmer_read() */
        MMIO_HMER_READ = 0x0800,
            /** mmio_hmer_write() */
        MMIO_HMER_WRITE = 0x0801,
            /** mmio_scratch_read() */
        MMIO_SCRATCH_READ = 0x0802,
            /** mmio_scratch_write() */
        MMIO_SCRATCH_WRITE = 0x0803,

        SYSCALL_FASTPATH_MAX
    };
};
#endif
