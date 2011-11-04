//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/include/sys/misc.h $
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
 *  @param[in] i_status The status code to post
 */
extern "C" void shutdown(uint64_t i_status);
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

    /** Power8 "Salerno" (low-end) core */
    CORE_POWER8_SALERNO,
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
 *  @breif Get the number of threads per cpu for this proctype
 *  @return # of threads per cpu
 */
size_t cpu_thread_count();

#ifdef __cplusplus
}
#endif

#endif
