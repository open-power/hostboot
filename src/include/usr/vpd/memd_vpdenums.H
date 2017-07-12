/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/vpd/memd_vpdenums.H $                         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2017                        */
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
#ifndef __MEMD_VPDENUMS_H
#define __MEMD_VPDENUMS_H

#include <vpd/ipvpdenums.H>

namespace MEMD_VPD
{

    /**
     * @brief Enumeration for the MEMD_VPD Records that contain
     *       the keyword enumerations below.
     */
    enum MEMD_VPDRecord
    {
        MEMD_VPD_FIRST_RECORD   = 0x00,
        VINI        = MEMD_VPD_FIRST_RECORD,
        MEMD        = 0x01,

        // Last Record
        MEMD_VPD_LAST_RECORD,
        MEMD_VPD_TEST_RECORD,   // Test purposes ONLY!

        //Start common IPVPD enums
        MEMD_VPD_INVALID_RECORD = IPVPD::INVALID_RECORD,
    };

    /**
     * @brief Enumerations for MEMD_VPD keywords that can be
     *       accessed in the MEMD_VPD.
     */
    enum MEMD_VPDKeyword
    {
        MEMD_VPD_FIRST_KEYWORD      = 0x00,
        B3      = MEMD_VPD_FIRST_KEYWORD,
        B4      = 0x01,
        B7      = 0x02,
        CC      = 0x03,
        CE      = 0x04,
        CT      = 0x05,
        DR      = 0x06,
        FC      = 0x07,
        FN      = 0x08,
        HE      = 0x09,
        HW      = 0x0a,
        I2      = 0x0b,
        IN      = 0x0c,
        J0      = 0x0d,
        J1      = 0x0e,
        J2      = 0x0f,
        J3      = 0x10,
        J4      = 0x11,
        J5      = 0x12,
        J6      = 0x13,
        J7      = 0x14,
        J8      = 0x15,
        J9      = 0x16,
        JA      = 0x17,
        JB      = 0x18,
        JC      = 0x19,
        JD      = 0x1a,
        JE      = 0x1b,
        JF      = 0x1c,
        JG      = 0x1d,
        JH      = 0x1e,
        JI      = 0x1f,
        JJ      = 0x20,
        JK      = 0x21,
        JL      = 0x22,
        JM      = 0x23,
        JN      = 0x24,
        JO      = 0x25,
        JP      = 0x26,
        JQ      = 0x27,
        JR      = 0x28,
        JS      = 0x29,
        JT      = 0x2a,
        JU      = 0x2b,
        JV      = 0x2c,
        JW      = 0x2d,
        JX      = 0x2e,
        JY      = 0x2f,
        JZ      = 0x30,
        LX      = 0x31,
        MR      = 0x32,
        MT      = 0x33,
        PF      = 0x34,
        PN      = 0x35,
        PR      = 0x36,
        RB      = 0x37,
        RG      = 0x38,
        RT      = 0x39,
        SE      = 0x3a,
        SN      = 0x3b,
        SO      = 0x3c,
        TM      = 0x3d,
        VM      = 0x3e,
        VZ      = 0x3f,
        X0      = 0x40,
        X1      = 0x41,
        X2      = 0x42,
        X3      = 0x43,
        X4      = 0x44,
        X5      = 0x45,
        X6      = 0x46,
        X7      = 0x47,
        X8      = 0x48,
        X9      = 0x49,
        XA      = 0x4a,
        XB      = 0x4b,
        XC      = 0x4c,
        XD      = 0x4d,
        XE      = 0x4e,
        XF      = 0x4f,
        XG      = 0x50,
        XH      = 0x51,
        XI      = 0x52,
        XJ      = 0x53,
        XK      = 0x54,
        XL      = 0x55,
        XM      = 0x56,
        XN      = 0x57,
        XO      = 0x58,
        XP      = 0x59,
        XQ      = 0x5a,
        XR      = 0x5b,
        XS      = 0x5c,
        XT      = 0x5d,
        XU      = 0x5e,
        XV      = 0x5f,
        XW      = 0x60,
        XX      = 0x61,
        XY      = 0x62,
        XZ      = 0x63,
        Q0      = 0x64,
        Q1      = 0x65,
        Q2      = 0x66,
        Q3      = 0x67,
        Q4      = 0x68,
        Q5      = 0x69,
        Q6      = 0x6A,
        Q7      = 0x6B,
        Q8      = 0x6C,
        CK      = 0X6D,

        // Last Keyword
        MEMD_VPD_LAST_KEYWORD,
        MEMD_VPD_TEST_KEYWORD,  // Test purposes ONLY!

        //Start common IPVPD enums
        FULL_RECORD = IPVPD::FULL_RECORD,
        MEMD_VPD_INVALID_KEYWORD    = IPVPD::INVALID_KEYWORD,
    };

};  // end MEMD_VPD

#endif
