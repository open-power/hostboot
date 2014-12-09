/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/vpd/cvpdenums.H $                             */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2015                        */
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
#ifndef __CVPDENUMS_H
#define __CVPDENUMS_H

#include <vpd/ipvpdenums.H>

namespace CVPD
{

    /**
     * @brief Enumeration for the CVPD Records that contain
     *       the keyword enumerations below.
     */
    enum cvpdRecord
    {
        CVPD_FIRST_RECORD   = 0x00,
        VEIR        = CVPD_FIRST_RECORD,
        VER0        = 0x01,
        MER0        = 0x02,
        VSPD        = 0x03,
        VINI        = 0x04,
        OPFR        = 0x05,
        VNDR        = 0x06,
        SPDX        = 0x07,
        // Last Record
        CVPD_LAST_RECORD,
        CVPD_TEST_RECORD,   // Test purposes ONLY!

        //Start common IPVPD enums
        CVPD_INVALID_RECORD = IPVPD::INVALID_RECORD,
    };

    /**
     * @brief Enumerations for CVPD keywords that can be
     *       accessed in the CVPD.
     */
    enum cvpdKeyword
    {
        CVPD_FIRST_KEYWORD      = 0x00,
        pdI         = CVPD_FIRST_KEYWORD,
        PF          = 0x01,
        MT          = 0x02,
        MR          = 0x03,
        pdA         = 0x04,
        EL          = 0x05,
        LM          = 0x06,
        MW          = 0x07,
        MV          = 0x08,
        AM          = 0x09,
        VZ          = 0x0a,
        pdD         = 0x0b,
        MX          = 0x0c,
        DW          = 0x0d,
        PN          = 0x0e,
        SN          = 0x0f,
        DR          = 0x10,
        CE          = 0x11,
        FN          = 0x12,
        CC          = 0x13,
        HE          = 0x14,
        CT          = 0x15,
        HW          = 0x16,
        VD          = 0x17,
        VN          = 0x18,
        VP          = 0x19,
        VS          = 0x1a,
        M0          = 0x1b,
        M1          = 0x1c,
        M2          = 0x1d,
        M3          = 0x1e,
        M4          = 0x1f,
        M5          = 0x20,
        M6          = 0x21,
        M7          = 0x22,
        M8          = 0x23,
        T1          = 0x24,
        T2          = 0x25,
        T4          = 0x26,
        T5          = 0x27,
        T6          = 0x28,
        T8          = 0x29,
        Q0          = 0x2a,
        Q1          = 0x2b,
        Q2          = 0x2c,
        Q3          = 0x2d,
        Q4          = 0x2e,
        Q5          = 0x2f,
        Q6          = 0x30,
        Q7          = 0x31,
        Q8          = 0x32,
        K0          = 0x33,
        K1          = 0x34,
        K2          = 0x35,
        K3          = 0x36,
        K4          = 0x37,
        K5          = 0x38,
        K6          = 0x39,
        K7          = 0x3a,
        K8          = 0x3b,

        // Last Keyword
        CVPD_LAST_KEYWORD,
        CVPD_TEST_KEYWORD,  // Test purposes ONLY!

        //Start common IPVPD enums
        FULL_RECORD = IPVPD::FULL_RECORD,
        CVPD_INVALID_KEYWORD    = IPVPD::INVALID_KEYWORD,
    };

};  // end CVPD

#endif
