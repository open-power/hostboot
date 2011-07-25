/** @file cpuid.C
 *  Implementation of the cpuid functions.
 */

#include <kernel/cpuid.H>

namespace CpuID
{
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

    uint8_t getCpuDD()
    {
        uint64_t l_pvr = getPVR();
        return ((l_pvr & 0x0F00) >> 4) | (l_pvr & 0x000F);
    }
};


