/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/vpd/pvpdenums.H $                             */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2020                        */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* Licensed under the Apache License, Version 2.0 (the "License");        */
/* you may not use this file except in compliance with the License.       */
/* You may obtain a copy of the License at                                */
/*                                                                        */
/*     http://www.apache.org/licenses/LICENSE-2.0                         */
/*                                                                        */
/* Unless required by applicable law or agreed to in writing, software    */
/* distributed under the License is distributed on an "AS IS" BASIS,      */
/* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or        */
/* implied. See the License for the specific language governing           */
/* permissions and limitations under the License.                         */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
#ifndef __PVPDENUMS_H
#define __PVPDENUMS_H

#include <vpd/ipvpdenums.H>

namespace PVPD
{

    /**
     * @brief Enumeration for the PVPD Records that contain
     *       the keyword enumerations below.
     *
     */
    enum pvpdRecord
    {
        PVPD_FIRST_RECORD   = 0x00,
        VINI        = PVPD_FIRST_RECORD,
        VSYS        = 0x01,
        LXR0        = 0x02,
        // Last Record
        PVPD_LAST_RECORD,
        PVPD_TEST_RECORD,   // Test purposes ONLY!

        //Start common IPVPD enums
        PVPD_INVALID_RECORD = IPVPD::INVALID_RECORD,
    };

    /**
     * @brief Enumerations for PVPD keywords that can be
     *       accessed in the PVPD.
     */
    enum pvpdKeyword
    {
        PVPD_FIRST_KEYWORD      = 0x00,
        pdI         = PVPD_FIRST_KEYWORD,
        B3         = 0x01,
        B4         = 0x02,
        B7         = 0x03,
        CC         = 0x04,
        CE         = 0x05,
        CT         = 0x06,
        DR         = 0x07,
        ET         = 0x08,
        FN         = 0x09,
        HE         = 0x0a,
        HW         = 0x0b,
        IN         = 0x0c,
        MM         = 0x0d,
        PF         = 0x0e,
        PN         = 0x0f,
        RT         = 0x10,
        SN         = 0x11,
        SS         = 0x12,
        VD         = 0x13,
        VN         = 0x14,
        VP         = 0x15,
        VS         = 0x16,
        VZ         = 0x17,
        LX         = 0x18,
        MB         = 0x19,
        NV         = 0x1A,
        FG         = 0x1B,
        HX         = 0x1C,
        TS         = 0x1D,
        BR         = 0x1E,
        FV         = 0x1F,
        ID         = 0x20,
        MN         = 0x21,
        RB         = 0x22,
        RG         = 0x23,
        SE         = 0x24,
        SG         = 0x25,
        SU         = 0x26,
        TM         = 0x27,
        TN         = 0x28,
        WN         = 0x29,

        // Last Keyword
        PVPD_LAST_KEYWORD,
        PVPD_TEST_KEYWORD,  // Test purposes ONLY!

        //Start common IPVPD enums
        FULL_RECORD = IPVPD::FULL_RECORD,
        PVPD_INVALID_KEYWORD    = IPVPD::INVALID_KEYWORD,
    };

};  // end PVPD

#endif
