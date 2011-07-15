#ifndef __KERNEL_CPUID_H
#define __KERNEL_CPUID_H

#include <arch/ppc.H>

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
ALWAYS_INLINE
ProcessorCoreType getCpuType()
{
    uint64_t l_pvr = getPVR();
    
    // Layout of the PVR is (32-bit):
    //     2 nibbles reserved.
    //     2 nibbles chip type.
    //     1 nibble technology.
    //     1 nibble major DD.
    //     1 nibble reserved.
    //     1 nibble minor DD.

    switch(l_pvr & 0xFFFF0000)
    {
        case 0x003F0000:
            return POWER7;

        case 0x004A0000:
            return POWER7_PLUS;

        case 0x004B0000:
            return POWER8_VENICE;

        default:
            return UNKNOWN;
    }
}

/** @fn getCpuDD
 *  @brief Decode the processor DD level from the PVR register.
 *
 *  These offsets come from the pervasive spec for each processor.
 *
 *  @return 1 byte DD level as <major nibble, minor nibble>.
 */
ALWAYS_INLINE
uint8_t getCpuDD()
{
    uint64_t l_pvr = getPVR();
    return ((l_pvr & 0x0F00) >> 4) | (l_pvr & 0x000F);
}

#endif
