/*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/include/sys/misc.h $
 *
 *  IBM CONFIDENTIAL
 *
 *  COPYRIGHT International Business Machines Corp. 2011-2012
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
#ifndef __SYS_MISC_H
#define __SYS_MISC_H

#include <stdint.h>

/**
 * @enum ShutdownStatus
 *
 * Shutdown values for shutdown command.
 */

enum ShutdownStatus
{
    SHUTDOWN_STATUS_GOOD                = 0x01230000,
    SHUTDOWN_STATUS_UT_FAILED           = 0x01230001,
    SHUTDOWN_STATUS_ISTEP_FAILED        = 0x01230002,
    SHUTDOWN_STATUS_EXTINITSVC_FAILED   = 0x01230003,
    SHUTDOWN_STATUS_INITSVC_FAILED      = 0x01230004,
};

#ifdef __cplusplus
extern "C"
{
#endif

#ifdef __HIDDEN_SYSCALL_SHUTDOWN
/** @fn shutdown()
 *  @brief Shutdown all CPUs (hardware threads)
 *  @param[in] i_status         The status code to post
 *  @param[in] i_payload_base   The base address (target HRMOR) of the payload.
 *  @param[in] i_payload_entry  The offset from base address of the payload
 *                              entry-point.
 */
extern "C" void shutdown(uint64_t i_status,
                         uint64_t i_payload_base,
                         uint64_t i_payload_entry);
#endif

/** @enum ProcessorCoreType
 *  @brief Enumeration of the different supported processor cores.
 */
enum ProcessorCoreType
{
    /** Base Power7 */
    CORE_POWER7,
    /** Power7+ */
    CORE_POWER7_PLUS,

    /** Power8 "Murano" (low-end) core */
    CORE_POWER8_MURANO,
    /** Power8 "Venice" (high-end) core */
    CORE_POWER8_VENICE,

    CORE_UNKNOWN,
};

/** @fn cpu_core_type()
 *  @brief Determine the procesore core type.
 *
 *  @return ProcessorCoreType - Value from enumeration for this core.
 */
ProcessorCoreType cpu_core_type();

/** @fn cpu_dd_level()
 *  @brief Determine the processor DD level.
 *
 *  @return 1 byte DD level as <major nibble, minor nibble>.
 */
uint8_t cpu_dd_level();

/** @fn cpu_thread_count()
 *  @brief Get the number of threads per cpu for this proctype
 *  @return # of threads per cpu
 */
size_t cpu_thread_count();

/** @fn cpu_start_core
 *  @brief Have the kernel start a new core.
 *
 *  @param[in] pir - PIR value of the first thread on the core.
 *
 *  @note The kernel will start all threads on the requested core even
 *        though the callee only requests with a single PIR value.
 *
 *  @return 0 or -(errno) on failure.
 *
 *  @retval -ENXIO - The core ID was outside of the range the kernel is
 *                   prepared to support.
 */
int cpu_start_core(uint64_t pir);

/**
 * @enum CpuSprNames
 *
 * Names for SPR registers for cpu_spr_value().
 */
enum CpuSprNames
{
    CPU_SPR_MSR,
    CPU_SPR_LPCR,
    CPU_SPR_HRMOR,
};

/** @fn cpu_spr_value
 *  @brief Reads the kernel-desired value for an SPR.
 *
 *  This is used, for instance, in building a sleep-winkle image.
 *
 *  @return The desired value of the SPR register.
 */
uint64_t cpu_spr_value(CpuSprNames spr);

/** @fn cpu_master_winkle
 *  @brief Winkle the master core so runtime SLW image can be applied.
 *
 *  This requires that the master core is the only one executing instructions.
 *  Will execute the winkle instruction on all running threads and return when
 *  an IPI is receieved on the master thread of the core.
 *
 *  @retval 0 - Success
 *  @retval -EDEADLK - Cores other than the master are already running.
 *
 *  @note This function will migrate the task to the master thread and in the
 *        process will unset any task affinity.  See task_affinity_unpin().
 */
int cpu_master_winkle();

#ifdef __cplusplus
}
#endif

#endif
