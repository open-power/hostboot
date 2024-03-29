/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/hwpf/fapi2/include/mvpd_access_defs.H $            */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2020                        */
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

///
/// @file mvpd_access_defs.H
///
/// @brief Defines the Module VPD Records and Keywords
///

#ifndef _FAPI2_MVPDACCESS_DEFS_H_
#define _FAPI2_MVPDACCESS_DEFS_H_

namespace fapi2
{

enum MvpdRecord
{
    MVPD_RECORD_CRP0 = 0x00,
    MVPD_RECORD_CP00 = 0x01,
    MVPD_RECORD_VINI = 0x02,
    MVPD_RECORD_LRP0 = 0x03,
    MVPD_RECORD_LRP1 = 0x04,
    MVPD_RECORD_LRP2 = 0x05,
    MVPD_RECORD_LRP3 = 0x06,
    MVPD_RECORD_LRP4 = 0x07,
    MVPD_RECORD_LRP5 = 0x08,
    MVPD_RECORD_LRP6 = 0x09,
    MVPD_RECORD_LRP7 = 0x0a,
    MVPD_RECORD_LRP8 = 0x0b,
    MVPD_RECORD_LRP9 = 0x0c,
    MVPD_RECORD_LRPA = 0x0d,
    MVPD_RECORD_LRPB = 0x0e,
    MVPD_RECORD_LRPC = 0x0f,
    MVPD_RECORD_LRPD = 0x10,
    MVPD_RECORD_LRPE = 0x11,
    MVPD_RECORD_LWP0 = 0x12,
    MVPD_RECORD_LWP1 = 0x13,
    MVPD_RECORD_LWP2 = 0x14,
    MVPD_RECORD_LWP3 = 0x15,
    MVPD_RECORD_LWP4 = 0x16,
    MVPD_RECORD_LWP5 = 0x17,
    MVPD_RECORD_LWP6 = 0x18,
    MVPD_RECORD_LWP7 = 0x19,
    MVPD_RECORD_LWP8 = 0x1a,
    MVPD_RECORD_LWP9 = 0x1b,
    MVPD_RECORD_LWPA = 0x1c,
    MVPD_RECORD_LWPB = 0x1d,
    MVPD_RECORD_LWPC = 0x1e,
    MVPD_RECORD_LWPD = 0x1f,
    MVPD_RECORD_LWPE = 0x20,
    MVPD_RECORD_VWML = 0x21,
    MVPD_RECORD_MER0 = 0x22,
    MVPD_RECORD_LAST, //useful for testcases
    MVPD_RECORD_FIRST = MVPD_RECORD_CRP0, //useful for testcases
};

enum MvpdKeyword
{
    MVPD_KEYWORD_VD  = 0x00,
    MVPD_KEYWORD_ED  = 0x01,
    MVPD_KEYWORD_TE  = 0x02,
    MVPD_KEYWORD_DD  = 0x03,
    MVPD_KEYWORD_PDP = 0x04,
    MVPD_KEYWORD_ST  = 0x05,
    MVPD_KEYWORD_DN  = 0x06,
    MVPD_KEYWORD_PG  = 0x07,
    MVPD_KEYWORD_PK  = 0x08,
    MVPD_KEYWORD_PDR = 0x09,
    MVPD_KEYWORD_PDV = 0x0a,
    MVPD_KEYWORD_PDH = 0x0b,
    MVPD_KEYWORD_SB  = 0x0c,
    MVPD_KEYWORD_DR  = 0x0d,
    MVPD_KEYWORD_VZ  = 0x0e,
    MVPD_KEYWORD_CC  = 0x0f,
    MVPD_KEYWORD_CE  = 0x10,
    MVPD_KEYWORD_FN  = 0x11,
    MVPD_KEYWORD_PN  = 0x12,
    MVPD_KEYWORD_SN  = 0x13,
    MVPD_KEYWORD_PR  = 0x14,
    MVPD_KEYWORD_HE  = 0x15,
    MVPD_KEYWORD_CT  = 0x16,
    MVPD_KEYWORD_HW  = 0x17,
    MVPD_KEYWORD_PDM = 0x18,
    MVPD_KEYWORD_IN  = 0x19,
    MVPD_KEYWORD_PD2 = 0x1a,
    MVPD_KEYWORD_PD3 = 0x1b,
    MVPD_KEYWORD_OC  = 0x1c,
    MVPD_KEYWORD_FO  = 0x1d,
    MVPD_KEYWORD_PDI = 0x1e,
    MVPD_KEYWORD_PDG = 0x1f,
    MVPD_KEYWORD_MK  = 0x20,
    MVPD_KEYWORD_PB  = 0x21,
    MVPD_KEYWORD_CH  = 0x22,
    MVPD_KEYWORD_IQ  = 0x23,
    MVPD_KEYWORD_L1  = 0x24,
    MVPD_KEYWORD_L2  = 0x25,
    MVPD_KEYWORD_L3  = 0x26,
    MVPD_KEYWORD_L4  = 0x27,
    MVPD_KEYWORD_L5  = 0x28,
    MVPD_KEYWORD_L6  = 0x29,
    MVPD_KEYWORD_L7  = 0x2a,
    MVPD_KEYWORD_L8  = 0x2b,
    MVPD_KEYWORD_PDW = 0x2c,
    MVPD_KEYWORD_AW  = 0x2d,
    MVPD_KEYWORD_CI  = 0x2e,
    MVPD_KEYWORD_PDS = 0x2f,
    MVPD_KEYWORD_LAST, //useful for testcases
    MVPD_KEYWORD_FIRST = MVPD_KEYWORD_VD, //useful for testcases
    MVPD_KEYWORD_UNDEFINED = 0xff, //useful for initializing keyword
};
}

#endif
