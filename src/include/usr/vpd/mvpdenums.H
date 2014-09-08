/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/vpd/mvpdenums.H $                             */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2014                        */
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
    LRP6        = 0x09,
    LRP7        = 0x0a,
    LRP8        = 0x0b,
    LRP9        = 0x0c,
    LRPA        = 0x0d,
    LRPB        = 0x0e,
    LRPC        = 0x0f,
    LRPD        = 0x10,
    LRPE        = 0x11,
    LWP0        = 0x12,
    LWP1        = 0x13,
    LWP2        = 0x14,
    LWP3        = 0x15,
    LWP4        = 0x16,
    LWP5        = 0x17,
    LWP6        = 0x18,
    LWP7        = 0x19,
    LWP8        = 0x1a,
    LWP9        = 0x1b,
    LWPA        = 0x1c,
    LWPB        = 0x1d,
    LWPC        = 0x1e,
    LWPD        = 0x1f,
    LWPE        = 0x20,
    VWML        = 0x21,
    MER0        = 0x22,

    // Last Record
    MVPD_LAST_RECORD,
    MVPD_TEST_RECORD,   // Test purposes ONLY!
    MVPD_INVALID_RECORD = 0xFFFF,
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
    pdP         = 0x04,
    ST          = 0x05,
    DN          = 0x06,
    PG          = 0x07,
    PK          = 0x08,
    pdR         = 0x09,
    pdV         = 0x0a,
    pdH         = 0x0b,
    SB          = 0x0c,
    DR          = 0x0d,
    VZ          = 0x0e,
    CC          = 0x0f,
    CE          = 0x10,
    FN          = 0x11,
    PN          = 0x12,
    SN          = 0x13,
    PR          = 0x14,
    HE          = 0x15,
    CT          = 0x16,
    HW          = 0x17,
    pdM         = 0x18,
    IN          = 0x19,
    pd2         = 0x1a,
    pd3         = 0x1b,
    OC          = 0x1c,
    FO          = 0x1d,
    pdI         = 0x1e,
    pdG         = 0x1f,
    MK          = 0x20,
    PB          = 0x21,
    CH          = 0x22,

    // Last Keyword
    MVPD_LAST_KEYWORD,
    MVPD_TEST_KEYWORD,  // Test purposes ONLY!
    INVALID_MVPD_KEYWORD    = 0xFFFF,
};

};  // end MVPD

#endif
