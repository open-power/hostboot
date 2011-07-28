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
