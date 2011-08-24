//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/kernel/cpuid.C $
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

        // TODO: Salerno PVR support.

        switch(l_pvr & 0xFFFF0000)
        {
            case 0x003F0000:
                return CORE_POWER7;

            case 0x004A0000:
                return CORE_POWER7_PLUS;

            case 0x004B0000:
                return CORE_POWER8_VENICE;

            default:
                return CORE_UNKNOWN;
        }
    }

    uint8_t getCpuDD()
    {
        uint64_t l_pvr = getPVR();
        return ((l_pvr & 0x0F00) >> 4) | (l_pvr & 0x000F);
    }
};


