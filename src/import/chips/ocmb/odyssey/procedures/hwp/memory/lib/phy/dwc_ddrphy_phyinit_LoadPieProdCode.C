/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/memory/lib/phy/dwc_ddrphy_phyinit_LoadPieProdCode.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2022,2024                        */
/* [+] International Business Machines Corp.                              */
/* [+] Synopsys, Inc.                                                     */
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

// Note: Synopsys, Inc. owns the original copyright of the code
// This file is ported into IBM's code stream with the permission of Synopsys, Inc.

// EKB-Mirror-To: hostboot
///
/// @file dwc_ddrphy_phyinit_LoadPieProdCode.C
/// @brief Odyssey PHY init loading PIE production code procedures
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB


#include <fapi2.H>

#include <generic/memory/lib/utils/mss_generic_check.H>
#include <generic/memory/lib/utils/c_str.H>

#include <lib/phy/dwc_ddrphy_phyinit_LoadPieProdCode.H>
#include <lib/phy/ody_ddrphy_phyinit_structs.H>
#include <lib/phy/ody_ddrphy_phyinit_config.H>
#include <lib/phy/ody_ddrphy_csr_defines.H>

#ifdef __PPE__
    #ifdef FAPI_INF
        #undef FAPI_INF
    #endif
    #ifdef FAPI_DBG
        #undef FAPI_DBG
    #endif

    #define FAPI_INF(_fmt_, _args_...)
    #define FAPI_DBG(_fmt_, _args_...)

#endif

///
/// @brief Loads the PHY Initialization Engine (PIE) code
/// @param[in] i_target - the memory port on which to operate
/// @param[in] i_runtime_config - the runtime configuration
/// @param[in] code_data - hwp_bit_istream for the PIE image data
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode dwc_ddrphy_phyinit_LoadPieProdCode(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
        const runtime_config_t& i_runtime_config,
        fapi2::hwp_bit_istream& code_data)
{
    // This is the size of the PIE code image, computed as sizeof(code_data)/sizeof(code_data[0]) where
    // sizeof(code_data[0]) = 2 since the original array is of type uint16
    constexpr uint16_t COUNTOF_CODE_DATA = 10775;

    static code_section_t code_sections[] =
    {
        { { 0x00090000 },     6, 0x00, 0x01 }, // 0
        { { 0x00041000 },   104, 0x00, 0x01 }, // 1
        { { 0x00000001 },    32, 0x01, 0x02 }, // 2
        { { 0x00000001 },    32, 0x03, 0x02 }, // 3
        { { 0x00000002 },    32, 0x01, 0x02 }, // 4
        { { 0x00000002 },    32, 0x03, 0x02 }, // 5
        { { 0x00000004 },    32, 0x01, 0x02 }, // 6
        { { 0x00000004 },    32, 0x03, 0x02 }, // 7
        { { 0x00000008 },    32, 0x01, 0x02 }, // 8
        { { 0x00000008 },    32, 0x03, 0x02 }, // 9
        { { 0x00000010 },    32, 0x01, 0x02 }, // 10
        { { 0x00000010 },    32, 0x03, 0x02 }, // 11
        { { 0x00000020 },    32, 0x01, 0x02 }, // 12
        { { 0x00000020 },    32, 0x03, 0x02 }, // 13
        { { 0x00000040 },    32, 0x01, 0x02 }, // 14
        { { 0x00000040 },    32, 0x03, 0x02 }, // 15
        { { 0x00000080 },    32, 0x01, 0x02 }, // 16
        { { 0x00000080 },    32, 0x03, 0x02 }, // 17
        { { 0x00000100 },    32, 0x01, 0x02 }, // 18
        { { 0x00000100 },    32, 0x03, 0x02 }, // 19
        { { 0x00000200 },    32, 0x01, 0x02 }, // 20
        { { 0x00000200 },    32, 0x03, 0x02 }, // 21
        { { 0x00000400 },    32, 0x01, 0x02 }, // 22
        { { 0x00000400 },    32, 0x03, 0x02 }, // 23
        { { 0x00000800 },    32, 0x01, 0x02 }, // 24
        { { 0x00000800 },    32, 0x03, 0x02 }, // 25
        { { 0x00001000 },    32, 0x01, 0x02 }, // 26
        { { 0x00001000 },    32, 0x03, 0x02 }, // 27
        { { 0x00002000 },    32, 0x01, 0x02 }, // 28
        { { 0x00002000 },    32, 0x03, 0x02 }, // 29
        { { 0x00004000 },    32, 0x01, 0x02 }, // 30
        { { 0x00004000 },    32, 0x03, 0x02 }, // 31
        { { 0x00008000 },    32, 0x01, 0x02 }, // 32
        { { 0x00008000 },    32, 0x03, 0x02 }, // 33
        { { 0x00010000 },    32, 0x01, 0x02 }, // 34
        { { 0x00010000 },    32, 0x03, 0x02 }, // 35
        { { 0x00020000 },    32, 0x01, 0x02 }, // 36
        { { 0x00020000 },    32, 0x03, 0x02 }, // 37
        { { 0x00040000 },    32, 0x01, 0x02 }, // 38
        { { 0x00040000 },    32, 0x03, 0x02 }, // 39
        { { 0x00080000 },    32, 0x01, 0x02 }, // 40
        { { 0x00080000 },    32, 0x03, 0x02 }, // 41
        { { 0x00100000 },    32, 0x01, 0x02 }, // 42
        { { 0x00100000 },    32, 0x03, 0x02 }, // 43
        { { 0x00200000 },    32, 0x01, 0x02 }, // 44
        { { 0x00200000 },    32, 0x03, 0x02 }, // 45
        { { 0x00400000 },    32, 0x01, 0x02 }, // 46
        { { 0x00400000 },    32, 0x03, 0x02 }, // 47
        { { 0x00800000 },    32, 0x01, 0x02 }, // 48
        { { 0x00800000 },    32, 0x03, 0x02 }, // 49
        { { 0x01000000 },    32, 0x01, 0x02 }, // 50
        { { 0x01000000 },    32, 0x03, 0x02 }, // 51
        { { 0x02000000 },    32, 0x01, 0x02 }, // 52
        { { 0x02000000 },    32, 0x03, 0x02 }, // 53
        { { 0x04000000 },    32, 0x01, 0x02 }, // 54
        { { 0x04000000 },    32, 0x03, 0x02 }, // 55
        { { 0x08000000 },    32, 0x01, 0x02 }, // 56
        { { 0x08000000 },    32, 0x03, 0x02 }, // 57
        { { 0x10000000 },    32, 0x01, 0x02 }, // 58
        { { 0x10000000 },    32, 0x03, 0x02 }, // 59
        { { 0x20000000 },    32, 0x01, 0x02 }, // 60
        { { 0x20000000 },    32, 0x03, 0x02 }, // 61
        { { 0x40000000 },    32, 0x01, 0x02 }, // 62
        { { 0x40000000 },    32, 0x03, 0x02 }, // 63
        { { 0x80000000 },    32, 0x01, 0x02 }, // 64
        { { 0x80000000 },    32, 0x03, 0x02 }, // 65
        { { 0x00000010 },   128, 0x00, 0x02 }, // 66
        { { 0x00000004 },   128, 0x00, 0x03 }, // 67
        { { 0x00000002 },     8, 0x00, 0x03 }, // 68
        { { 0x00020000 },    32, 0x00, 0x02 }, // 69
        { { 0x00040000 },    64, 0x00, 0x02 }, // 70
        { { 0x00000000 },    32, 0x00, 0x00 }, // 71
        { { 0x00000000 },   112, 0x00, 0x00 }, // 72
        { { 0x00000001 },    32, 0x01, 0x02 }, // 73
        { { 0x00000001 },    32, 0x03, 0x02 }, // 74
        { { 0x00000002 },    32, 0x01, 0x02 }, // 75
        { { 0x00000002 },    32, 0x03, 0x02 }, // 76
        { { 0x00000004 },    32, 0x01, 0x02 }, // 77
        { { 0x00000004 },    32, 0x03, 0x02 }, // 78
        { { 0x00000008 },    32, 0x01, 0x02 }, // 79
        { { 0x00000008 },    32, 0x03, 0x02 }, // 80
        { { 0x00000010 },    32, 0x01, 0x02 }, // 81
        { { 0x00000010 },    32, 0x03, 0x02 }, // 82
        { { 0x00000020 },    32, 0x01, 0x02 }, // 83
        { { 0x00000020 },    32, 0x03, 0x02 }, // 84
        { { 0x00000040 },    32, 0x01, 0x02 }, // 85
        { { 0x00000040 },    32, 0x03, 0x02 }, // 86
        { { 0x00000080 },    32, 0x01, 0x02 }, // 87
        { { 0x00000080 },    32, 0x03, 0x02 }, // 88
        { { 0x00000100 },    32, 0x01, 0x02 }, // 89
        { { 0x00000100 },    32, 0x03, 0x02 }, // 90
        { { 0x00000200 },    32, 0x01, 0x02 }, // 91
        { { 0x00000200 },    32, 0x03, 0x02 }, // 92
        { { 0x00000400 },    32, 0x01, 0x02 }, // 93
        { { 0x00000400 },    32, 0x03, 0x02 }, // 94
        { { 0x00000800 },    32, 0x01, 0x02 }, // 95
        { { 0x00000800 },    32, 0x03, 0x02 }, // 96
        { { 0x00001000 },    32, 0x01, 0x02 }, // 97
        { { 0x00001000 },    32, 0x03, 0x02 }, // 98
        { { 0x00002000 },    32, 0x01, 0x02 }, // 99
        { { 0x00002000 },    32, 0x03, 0x02 }, // 100
        { { 0x00004000 },    32, 0x01, 0x02 }, // 101
        { { 0x00004000 },    32, 0x03, 0x02 }, // 102
        { { 0x00008000 },    32, 0x01, 0x02 }, // 103
        { { 0x00008000 },    32, 0x03, 0x02 }, // 104
        { { 0x00010000 },    32, 0x01, 0x02 }, // 105
        { { 0x00010000 },    32, 0x03, 0x02 }, // 106
        { { 0x00020000 },    32, 0x01, 0x02 }, // 107
        { { 0x00020000 },    32, 0x03, 0x02 }, // 108
        { { 0x00040000 },    32, 0x01, 0x02 }, // 109
        { { 0x00040000 },    32, 0x03, 0x02 }, // 110
        { { 0x00080000 },    32, 0x01, 0x02 }, // 111
        { { 0x00080000 },    32, 0x03, 0x02 }, // 112
        { { 0x00100000 },    32, 0x01, 0x02 }, // 113
        { { 0x00100000 },    32, 0x03, 0x02 }, // 114
        { { 0x00200000 },    32, 0x01, 0x02 }, // 115
        { { 0x00200000 },    32, 0x03, 0x02 }, // 116
        { { 0x00400000 },    32, 0x01, 0x02 }, // 117
        { { 0x00400000 },    32, 0x03, 0x02 }, // 118
        { { 0x00800000 },    32, 0x01, 0x02 }, // 119
        { { 0x00800000 },    32, 0x03, 0x02 }, // 120
        { { 0x01000000 },    32, 0x01, 0x02 }, // 121
        { { 0x01000000 },    32, 0x03, 0x02 }, // 122
        { { 0x02000000 },    32, 0x01, 0x02 }, // 123
        { { 0x02000000 },    32, 0x03, 0x02 }, // 124
        { { 0x04000000 },    32, 0x01, 0x02 }, // 125
        { { 0x04000000 },    32, 0x03, 0x02 }, // 126
        { { 0x08000000 },    32, 0x01, 0x02 }, // 127
        { { 0x08000000 },    32, 0x03, 0x02 }, // 128
        { { 0x10000000 },    32, 0x01, 0x02 }, // 129
        { { 0x10000000 },    32, 0x03, 0x02 }, // 130
        { { 0x20000000 },    32, 0x01, 0x02 }, // 131
        { { 0x20000000 },    32, 0x03, 0x02 }, // 132
        { { 0x40000000 },    32, 0x01, 0x02 }, // 133
        { { 0x40000000 },    32, 0x03, 0x02 }, // 134
        { { 0x80000000 },    32, 0x01, 0x02 }, // 135
        { { 0x80000000 },    32, 0x03, 0x02 }, // 136
        { { 0x00000010 },   128, 0x00, 0x02 }, // 137
        { { 0x00000004 },   128, 0x00, 0x03 }, // 138
        { { 0x00000002 },     8, 0x00, 0x03 }, // 139
        { { 0x00020000 },    32, 0x00, 0x02 }, // 140
        { { 0x00040000 },    64, 0x00, 0x02 }, // 141
        { { 0x00000000 },    32, 0x00, 0x00 }, // 142
        { { 0x00000000 },     0, 0x00, 0x00 }, // 143
        { { 0x00042000 },   104, 0x00, 0x01 }, // 144
        { { 0x00000001 },    32, 0x02, 0x02 }, // 145
        { { 0x00000001 },    32, 0x04, 0x02 }, // 146
        { { 0x00000002 },    32, 0x02, 0x02 }, // 147
        { { 0x00000002 },    32, 0x04, 0x02 }, // 148
        { { 0x00000004 },    32, 0x02, 0x02 }, // 149
        { { 0x00000004 },    32, 0x04, 0x02 }, // 150
        { { 0x00000008 },    32, 0x02, 0x02 }, // 151
        { { 0x00000008 },    32, 0x04, 0x02 }, // 152
        { { 0x00000010 },    32, 0x02, 0x02 }, // 153
        { { 0x00000010 },    32, 0x04, 0x02 }, // 154
        { { 0x00000020 },    32, 0x02, 0x02 }, // 155
        { { 0x00000020 },    32, 0x04, 0x02 }, // 156
        { { 0x00000040 },    32, 0x02, 0x02 }, // 157
        { { 0x00000040 },    32, 0x04, 0x02 }, // 158
        { { 0x00000080 },    32, 0x02, 0x02 }, // 159
        { { 0x00000080 },    32, 0x04, 0x02 }, // 160
        { { 0x00000100 },    32, 0x02, 0x02 }, // 161
        { { 0x00000100 },    32, 0x04, 0x02 }, // 162
        { { 0x00000200 },    32, 0x02, 0x02 }, // 163
        { { 0x00000200 },    32, 0x04, 0x02 }, // 164
        { { 0x00000400 },    32, 0x02, 0x02 }, // 165
        { { 0x00000400 },    32, 0x04, 0x02 }, // 166
        { { 0x00000800 },    32, 0x02, 0x02 }, // 167
        { { 0x00000800 },    32, 0x04, 0x02 }, // 168
        { { 0x00001000 },    32, 0x02, 0x02 }, // 169
        { { 0x00001000 },    32, 0x04, 0x02 }, // 170
        { { 0x00002000 },    32, 0x02, 0x02 }, // 171
        { { 0x00002000 },    32, 0x04, 0x02 }, // 172
        { { 0x00004000 },    32, 0x02, 0x02 }, // 173
        { { 0x00004000 },    32, 0x04, 0x02 }, // 174
        { { 0x00008000 },    32, 0x02, 0x02 }, // 175
        { { 0x00008000 },    32, 0x04, 0x02 }, // 176
        { { 0x00010000 },    32, 0x02, 0x02 }, // 177
        { { 0x00010000 },    32, 0x04, 0x02 }, // 178
        { { 0x00020000 },    32, 0x02, 0x02 }, // 179
        { { 0x00020000 },    32, 0x04, 0x02 }, // 180
        { { 0x00040000 },    32, 0x02, 0x02 }, // 181
        { { 0x00040000 },    32, 0x04, 0x02 }, // 182
        { { 0x00080000 },    32, 0x02, 0x02 }, // 183
        { { 0x00080000 },    32, 0x04, 0x02 }, // 184
        { { 0x00100000 },    32, 0x02, 0x02 }, // 185
        { { 0x00100000 },    32, 0x04, 0x02 }, // 186
        { { 0x00200000 },    32, 0x02, 0x02 }, // 187
        { { 0x00200000 },    32, 0x04, 0x02 }, // 188
        { { 0x00400000 },    32, 0x02, 0x02 }, // 189
        { { 0x00400000 },    32, 0x04, 0x02 }, // 190
        { { 0x00800000 },    32, 0x02, 0x02 }, // 191
        { { 0x00800000 },    32, 0x04, 0x02 }, // 192
        { { 0x01000000 },    32, 0x02, 0x02 }, // 193
        { { 0x01000000 },    32, 0x04, 0x02 }, // 194
        { { 0x02000000 },    32, 0x02, 0x02 }, // 195
        { { 0x02000000 },    32, 0x04, 0x02 }, // 196
        { { 0x04000000 },    32, 0x02, 0x02 }, // 197
        { { 0x04000000 },    32, 0x04, 0x02 }, // 198
        { { 0x08000000 },    32, 0x02, 0x02 }, // 199
        { { 0x08000000 },    32, 0x04, 0x02 }, // 200
        { { 0x10000000 },    32, 0x02, 0x02 }, // 201
        { { 0x10000000 },    32, 0x04, 0x02 }, // 202
        { { 0x20000000 },    32, 0x02, 0x02 }, // 203
        { { 0x20000000 },    32, 0x04, 0x02 }, // 204
        { { 0x40000000 },    32, 0x02, 0x02 }, // 205
        { { 0x40000000 },    32, 0x04, 0x02 }, // 206
        { { 0x80000000 },    32, 0x02, 0x02 }, // 207
        { { 0x80000000 },    32, 0x04, 0x02 }, // 208
        { { 0x00000010 },   128, 0x00, 0x02 }, // 209
        { { 0x00000004 },   128, 0x00, 0x03 }, // 210
        { { 0x00000002 },     8, 0x00, 0x03 }, // 211
        { { 0x00020000 },    32, 0x00, 0x02 }, // 212
        { { 0x00040000 },    64, 0x00, 0x02 }, // 213
        { { 0x00000000 },    32, 0x00, 0x00 }, // 214
        { { 0x00000000 },   112, 0x00, 0x00 }, // 215
        { { 0x00000001 },    32, 0x02, 0x02 }, // 216
        { { 0x00000001 },    32, 0x04, 0x02 }, // 217
        { { 0x00000002 },    32, 0x02, 0x02 }, // 218
        { { 0x00000002 },    32, 0x04, 0x02 }, // 219
        { { 0x00000004 },    32, 0x02, 0x02 }, // 220
        { { 0x00000004 },    32, 0x04, 0x02 }, // 221
        { { 0x00000008 },    32, 0x02, 0x02 }, // 222
        { { 0x00000008 },    32, 0x04, 0x02 }, // 223
        { { 0x00000010 },    32, 0x02, 0x02 }, // 224
        { { 0x00000010 },    32, 0x04, 0x02 }, // 225
        { { 0x00000020 },    32, 0x02, 0x02 }, // 226
        { { 0x00000020 },    32, 0x04, 0x02 }, // 227
        { { 0x00000040 },    32, 0x02, 0x02 }, // 228
        { { 0x00000040 },    32, 0x04, 0x02 }, // 229
        { { 0x00000080 },    32, 0x02, 0x02 }, // 230
        { { 0x00000080 },    32, 0x04, 0x02 }, // 231
        { { 0x00000100 },    32, 0x02, 0x02 }, // 232
        { { 0x00000100 },    32, 0x04, 0x02 }, // 233
        { { 0x00000200 },    32, 0x02, 0x02 }, // 234
        { { 0x00000200 },    32, 0x04, 0x02 }, // 235
        { { 0x00000400 },    32, 0x02, 0x02 }, // 236
        { { 0x00000400 },    32, 0x04, 0x02 }, // 237
        { { 0x00000800 },    32, 0x02, 0x02 }, // 238
        { { 0x00000800 },    32, 0x04, 0x02 }, // 239
        { { 0x00001000 },    32, 0x02, 0x02 }, // 240
        { { 0x00001000 },    32, 0x04, 0x02 }, // 241
        { { 0x00002000 },    32, 0x02, 0x02 }, // 242
        { { 0x00002000 },    32, 0x04, 0x02 }, // 243
        { { 0x00004000 },    32, 0x02, 0x02 }, // 244
        { { 0x00004000 },    32, 0x04, 0x02 }, // 245
        { { 0x00008000 },    32, 0x02, 0x02 }, // 246
        { { 0x00008000 },    32, 0x04, 0x02 }, // 247
        { { 0x00010000 },    32, 0x02, 0x02 }, // 248
        { { 0x00010000 },    32, 0x04, 0x02 }, // 249
        { { 0x00020000 },    32, 0x02, 0x02 }, // 250
        { { 0x00020000 },    32, 0x04, 0x02 }, // 251
        { { 0x00040000 },    32, 0x02, 0x02 }, // 252
        { { 0x00040000 },    32, 0x04, 0x02 }, // 253
        { { 0x00080000 },    32, 0x02, 0x02 }, // 254
        { { 0x00080000 },    32, 0x04, 0x02 }, // 255
        { { 0x00100000 },    32, 0x02, 0x02 }, // 256
        { { 0x00100000 },    32, 0x04, 0x02 }, // 257
        { { 0x00200000 },    32, 0x02, 0x02 }, // 258
        { { 0x00200000 },    32, 0x04, 0x02 }, // 259
        { { 0x00400000 },    32, 0x02, 0x02 }, // 260
        { { 0x00400000 },    32, 0x04, 0x02 }, // 261
        { { 0x00800000 },    32, 0x02, 0x02 }, // 262
        { { 0x00800000 },    32, 0x04, 0x02 }, // 263
        { { 0x01000000 },    32, 0x02, 0x02 }, // 264
        { { 0x01000000 },    32, 0x04, 0x02 }, // 265
        { { 0x02000000 },    32, 0x02, 0x02 }, // 266
        { { 0x02000000 },    32, 0x04, 0x02 }, // 267
        { { 0x04000000 },    32, 0x02, 0x02 }, // 268
        { { 0x04000000 },    32, 0x04, 0x02 }, // 269
        { { 0x08000000 },    32, 0x02, 0x02 }, // 270
        { { 0x08000000 },    32, 0x04, 0x02 }, // 271
        { { 0x10000000 },    32, 0x02, 0x02 }, // 272
        { { 0x10000000 },    32, 0x04, 0x02 }, // 273
        { { 0x20000000 },    32, 0x02, 0x02 }, // 274
        { { 0x20000000 },    32, 0x04, 0x02 }, // 275
        { { 0x40000000 },    32, 0x02, 0x02 }, // 276
        { { 0x40000000 },    32, 0x04, 0x02 }, // 277
        { { 0x80000000 },    32, 0x02, 0x02 }, // 278
        { { 0x80000000 },    32, 0x04, 0x02 }, // 279
        { { 0x00000010 },   128, 0x00, 0x02 }, // 280
        { { 0x00000004 },   128, 0x00, 0x03 }, // 281
        { { 0x00000002 },     8, 0x00, 0x03 }, // 282
        { { 0x00020000 },    32, 0x00, 0x02 }, // 283
        { { 0x00040000 },    64, 0x00, 0x02 }, // 284
        { { 0x00000000 },    32, 0x00, 0x00 }, // 285
        { { 0x00000000 },     0, 0x00, 0x00 }, // 286
        { { 0x00090029 },    51, 0x00, 0x01 }, // 287
        { { 0x00080000 },    30, 0x00, 0x02 }, // 288
        { { 0x00000800 },    30, 0x00, 0x02 }, // 289
        { { 0x00000400 },    21, 0x00, 0x02 }, // 290
        { { 0x00000000 },    18, 0x00, 0x00 }, // 291
        { { 0x00000400 },    33, 0x00, 0x02 }, // 292
        { { 0x00000000 },     3, 0x00, 0x00 }, // 293
        { { 0x00000800 },    27, 0x00, 0x02 }, // 294
        { { 0x00080000 },    27, 0x00, 0x02 }, // 295
        { { 0x00000000 },    33, 0x00, 0x00 }, // 296
        { { 0x00000400 },     3, 0x00, 0x02 }, // 297
        { { 0x00000000 },    48, 0x00, 0x00 }, // 298
        { { 0x00000400 },    15, 0x00, 0x02 }, // 299
        { { 0x00000000 },    36, 0x00, 0x00 }, // 300
        { { 0x00000008 },     3, 0x00, 0x02 }, // 301
        { { 0x00001000 },     3, 0x00, 0x02 }, // 302
        { { 0x00000000 },    12, 0x00, 0x00 }, // 303
        { { 0x00002000 },    12, 0x00, 0x02 }, // 304
        { { 0x00004000 },    12, 0x00, 0x02 }, // 305
        { { 0x00008000 },    12, 0x00, 0x02 }, // 306
        { { 0x00010000 },    12, 0x00, 0x02 }, // 307
        { { 0x00000020 },    12, 0x00, 0x02 }, // 308
        { { 0x00000040 },    12, 0x00, 0x02 }, // 309
        { { 0x00000080 },    12, 0x00, 0x02 }, // 310
        { { 0x00000100 },    12, 0x00, 0x02 }, // 311
        { { 0x00000002 },     3, 0x00, 0x03 }, // 312
        { { 0x00000000 },    24, 0x00, 0x00 }, // 313
        { { 0x00000001 },     3, 0x00, 0x02 }, // 314
        { { 0x00000000 },     9, 0x00, 0x00 }, // 315
        { { 0x00000000 },    42, 0x00, 0x00 }, // 316
        { { 0x00090006 },     6, 0x00, 0x01 }, // 317
        { { 0x000d00e7 },     1, 0x00, 0x01 }, // 318
    };
    static uint32_t D5ACSM_1N_StartAddr;
    static uint32_t D5ACSM_2N_StartAddr;
    static uint32_t D5ACSM_2N_StopAddr;
    static uint32_t lp3Addr_StartAddr;
    static uint32_t pptAddr_StartAddr;
    static uint32_t startAddr_StartAddr;
    static code_marker_t code_markers[] =
    {
        { 1, &D5ACSM_1N_StartAddr },
        { 72, &D5ACSM_2N_StartAddr },
        { 143, &D5ACSM_2N_StopAddr },
        { 287, &startAddr_StartAddr },
        { 300, &pptAddr_StartAddr },
        { 316, &lp3Addr_StartAddr },
    };
    uint16_t startAddr = 0;
    uint16_t pptAddr = 0;
    uint16_t lp3Addr = 0;
    uint16_t D5ACSMStartAddrVal_1N = 0;
    uint16_t D5ACSMStartAddrVal_2N = 0;
    uint16_t D5ACSMStopAddrVal_1N = 0;
    uint16_t D5ACSMStopAddrVal_2N = 0;
    uint16_t D5ACSMPtrXlat01 = 0;
    uint16_t D5ACSMPtrXlat23 = 0;
    FAPI_TRY(dwc_ddrphy_phyinit_LoadPIECodeSections(i_target, i_runtime_config, code_sections, COUNTOF(code_sections),
             code_data, COUNTOF_CODE_DATA, code_markers, COUNTOF(code_markers)));
    D5ACSMStartAddrVal_1N = 0;
    D5ACSMStartAddrVal_2N = (D5ACSM_2N_StartAddr - D5ACSM_1N_StartAddr) >> 2;
    D5ACSMStopAddrVal_1N = D5ACSMStartAddrVal_2N - 1;
    D5ACSMStopAddrVal_2N = ((D5ACSM_2N_StopAddr - D5ACSM_1N_StartAddr) >> 2) - 1;
    D5ACSMPtrXlat01 = (D5ACSMStopAddrVal_1N << csr_D5ACSMStopAddrVal0_LSB) | (D5ACSMStartAddrVal_1N <<
                      csr_D5ACSMStartAddrVal0_LSB);
    D5ACSMPtrXlat23 = (D5ACSMStopAddrVal_2N << csr_D5ACSMStopAddrVal0_LSB) | (D5ACSMStartAddrVal_2N <<
                      csr_D5ACSMStartAddrVal0_LSB);

    for(int fsp = 0; fsp < 2; fsp++)
    {
        FAPI_TRY(dwc_ddrphy_phyinit_userCustom_io_write16(i_target, tMASTER | c0 | (csr_D5ACSMPtrXlat0_ADDR + fsp),
                 D5ACSMPtrXlat01));
        FAPI_TRY(dwc_ddrphy_phyinit_userCustom_io_write16(i_target, tMASTER | c0 | (csr_D5ACSMPtrXlat2_ADDR + fsp),
                 D5ACSMPtrXlat23));
    };

    startAddr = (startAddr_StartAddr - startAddr_StartAddr) / 3;

    pptAddr = (pptAddr_StartAddr - startAddr_StartAddr) / 3;

    lp3Addr = (lp3Addr_StartAddr - startAddr_StartAddr) / 3;

    FAPI_DBG(TARGTIDFORMAT
             " seq0b_LoadPstateSeqProductionCode(): ---------------------------------------------------------------------------------------------------\n",
             TARGTID);

    FAPI_DBG(TARGTIDFORMAT
             " seq0b_LoadPstateSeqProductionCode(): Programming the 0B sequencer 0b0000 start vector registers with %d.\n", TARGTID,
             startAddr);

    FAPI_DBG(TARGTIDFORMAT
             " seq0b_LoadPstateSeqProductionCode(): Programming the 0B sequencer 0b1000 start vector register with %d.\n", TARGTID,
             pptAddr);

    FAPI_DBG(TARGTIDFORMAT
             " seq0b_LoadPstateSeqProductionCode(): Programming the 0B sequencer 0b1111 start vector register with %d.\n", TARGTID,
             lp3Addr);

    FAPI_DBG(TARGTIDFORMAT
             " seq0b_LoadPstateSeqProductionCode(): ---------------------------------------------------------------------------------------------------\n",
             TARGTID);

    FAPI_TRY(dwc_ddrphy_phyinit_userCustom_io_write16(i_target, (c0 | tINITENG | csr_StartVector0b0_ADDR), startAddr));

    FAPI_TRY(dwc_ddrphy_phyinit_userCustom_io_write16(i_target, (c0 | tINITENG | csr_StartVector0b8_ADDR), pptAddr));

    FAPI_TRY(dwc_ddrphy_phyinit_userCustom_io_write16(i_target, (c0 | tINITENG | csr_StartVector0b15_ADDR), lp3Addr));

fapi_try_exit :
    return fapi2::current_err;
}
