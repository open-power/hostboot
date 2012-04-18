//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/include/kernel/misc.H $
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
/** @file misc.H
 *  @brief Misc. Kernel functions and utilities.
 */

#ifndef __KERNEL_MISC_H
#define __KERNEL_MISC_H

#include <stdint.h>

namespace KernelMisc
{
    /** @fn shutdown
     *  @brief Sequence kernel to shutdown and switch to payload.
     */
    void shutdown();

    /** @brief Base address (target HRMOR) of the payload. */
    extern uint64_t g_payload_base;
    /** @brief Address from base of payload entry-point. */
    extern uint64_t g_payload_entry;
};
#endif
