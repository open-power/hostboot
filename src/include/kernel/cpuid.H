//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/include/kernel/cpuid.H $
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
#ifndef __KERNEL_CPUID_H
#define __KERNEL_CPUID_H

#include <stdint.h>
#include <arch/ppc.H>
#include <sys/misc.h>

namespace CpuID
{
    /** @fn getCpuType()
     *  @brief Decode the processor type from the PVR register.
     *
     *  These values come from the pervasive spec for each processor.
     *
     *  @return ProcessorCoreType - Value from enumeration for this core.
     */
    ProcessorCoreType getCpuType();

    /** @fn getCpuDD
     *  @brief Decode the processor DD level from the PVR register.
     *
     *  These offsets come from the pervasive spec for each processor.
     *
     *  @return 1 byte DD level as <major nibble, minor nibble>.
     */
    uint8_t getCpuDD();
};
#endif
