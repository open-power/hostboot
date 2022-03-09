/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/vpd/mvpdenums.H $                             */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2022                        */
/* [+] Google Inc.                                                        */
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
/**
 * @file mvpdenums.H
 *
 * @brief Enums for the MVPD fields to be requested.
 *
 */
#ifndef __MVPDENUMS_H
#define __MVPDENUMS_H

#include <vpd/ipvpdenums.H>


namespace MVPD
{

/**
* @brief Enumeration for the MVPD Records that contain
*       the keyword enumerations below.
*/
enum mvpdRecord
{
    MVPD_FIRST_RECORD   = 0x00,
    CRP0        = MVPD_FIRST_RECORD,
    CP00        = 0x01,
    VINI        = 0x02,
    LRP0        = 0x03,
    LRP1        = 0x04,
    LRP2        = 0x05,
    LRP3        = 0x06,
    LRP4        = 0x07,
    LRP5        = 0x08,
    LWP0        = 0x09,
    LWP1        = 0x0a,
    LWP2        = 0x0b,
    LWP3        = 0x0c,
    LWP4        = 0x0d,
    LWP5        = 0x0e,
    VRML        = 0x0f,
    VWML        = 0x10,
    VER0        = 0x11,
    MER0        = 0x12,
    VMSC        = 0x13,

    // Last Record
    MVPD_LAST_RECORD,
    MVPD_TEST_RECORD,   // Test purposes ONLY!

    //Start common IPVPD enums
    MVPD_INVALID_RECORD = IPVPD::INVALID_RECORD,
};

/**
* @brief Enumerations for MVPD keywords that can be
*       accessed in the MVPD.
*/
enum mvpdKeyword
{
    MVPD_FIRST_KEYWORD      = 0x00,
    VD          = MVPD_FIRST_KEYWORD,
    ED          = 0x01,
    TE          = 0x02,
    DD          = 0x03,
    DN          = 0x04,
    PG          = 0x05,
    PK          = 0x06,
    pdR         = 0x07,
    pdV         = 0x08,
    pdH         = 0x09,
    SB          = 0x0a,
    DR          = 0x0b,
    VZ          = 0x0c,
    CC          = 0x0d,
    CE          = 0x0e,
    FN          = 0x0f,
    PN          = 0x10,
    SN          = 0x11,
    PR          = 0x12,
    HE          = 0x13,
    CT          = 0x14,
    HW          = 0x15,
    pdM         = 0x16,
    IN          = 0x17,
    pdI         = 0x18,
    pdG         = 0x19,
    PB          = 0x1a,
    CH          = 0x1b,
    IQ          = 0x1c,
    PM          = 0x1d,
    PZ          = 0x1e,
    n20         = 0x1f,
    n21         = 0x20,
    n30         = 0x21,
    n31         = 0x22,
    L1          = 0x23,
    L2          = 0x24,
    L3          = 0x25,
    L4          = 0x26,
    L5          = 0x27,
    L6          = 0x28,
    L7          = 0x29,
    L8          = 0x2A,
    pdW         = 0x2B,
    RT          = 0x2C,
    AW          = 0x2D,
    CI          = 0x2E,
    pdP         = 0x2F,
    pdS         = 0x30,
    MK          = 0x31,
    B3          = 0x32,
    B4          = 0x33,
    B7          = 0x34,
    VN          = 0x35,

    // Last Keyword
    MVPD_LAST_KEYWORD,
    MVPD_TEST_KEYWORD,  // Test purposes ONLY!

    //Start common IPVPD enums
    FULL_RECORD = IPVPD::FULL_RECORD,
    INVALID_MVPD_KEYWORD    = IPVPD::INVALID_KEYWORD,
};

};  // end MVPD

#endif
