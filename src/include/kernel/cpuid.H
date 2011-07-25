#ifndef __KERNEL_CPUID_H
#define __KERNEL_CPUID_H

#include <stdint.h>
#include <arch/ppc.H>

namespace CpuID
{
    /** @enum ProcessorCoreType
     *  @brief Enumeration of the different supported processor cores.
     */
    enum ProcessorCoreType
    {
        /** Base Power7 */
        POWER7,
        /** Power7+ */
        POWER7_PLUS,

        /** Power8 "Salerno" (low-end) core */
        POWER8_SALERNO,
        /** Power8 "Venice" (high-end) core */
        POWER8_VENICE,

        UNKNOWN,
    };

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
