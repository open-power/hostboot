/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/pm/p10_pstate_parameter_block.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2020                        */
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
/// @file  p10_pstate_parameter_block.C
/// @brief Setup Pstate super structure for PGPE/CME HCode
///
/// *HWP HW Owner        : Greg Still <stillgs@us.ibm.com>
/// *HWP FW Owner        : Prasad Bg Ranganath <prasadbgr@in.ibm.com>
/// *HWP Team            : PM
/// *HWP Level           : 2
/// *HWP Consumed by     : HB,PGPE,CME,OCC
///
/// @verbatim
/// Procedure Summary:
///   - Read VPD and attributes to create the Pstate Parameter Block(s) (one each for PGPE,OCC and CMEs).
/// @endverbatim

// *INDENT-OFF*
//
// ----------------------------------------------------------------------
// Includes
// ----------------------------------------------------------------------
#include <fapi2.H>
#include <p10_pstate_parameter_block.H>
#include <p10_setup_evid.H>
#include <p10_pm_utils.H>
#include <mvpd_access_defs.H>

using namespace pm_pstate_parameter_block;

#define IQ_BUFFER_ALLOC            255
#define PSTATE_MAX                 255
#define PSTATE_MIN                 0
#define PROC_PLL_DIVIDER           8
#define CF1_3_PERCENTAGE           0.33
#define CF2_4_PERCENTAGE           0.50
#define NORMAL                     0
#define INVERTED                   1

#define POUNDV_POINT_CALC(VAL,X,Y,Z)     if (VAL == 0) {VAL = ( (Y - X) * Z) + X; }


#define POUNDV_POINTS_CHECK(i) \
                (iv_attr_mvpd_data[i].frequency_mhz == 0 || \
                 iv_attr_mvpd_data[i].vdd_mv        == 0 || \
                 iv_attr_mvpd_data[i].idd_tdp_ac_10ma == 0 || \
                 iv_attr_mvpd_data[i].idd_tdp_dc_10ma == 0 || \
                 iv_attr_mvpd_data[i].idd_rdp_ac_10ma == 0 || \
                 iv_attr_mvpd_data[i].idd_rdp_dc_10ma == 0 || \
                 iv_attr_mvpd_data[i].vcs_mv          == 0 || \
                 iv_attr_mvpd_data[i].ics_tdp_ac_10ma == 0 || \
                 iv_attr_mvpd_data[i].ics_tdp_dc_10ma == 0 || \
                 iv_attr_mvpd_data[i].ics_rdp_ac_10ma == 0 || \
                 iv_attr_mvpd_data[i].ics_rdp_dc_10ma == 0 || \
                 iv_attr_mvpd_data[i].vdd_vmin == 0)

// TODO; need to reenable when RT values are guarenteed to be present
//                 iv_attr_mvpd_data[i].rt_tdp_ac_10ma == 0 ||
//                 iv_attr_mvpd_data[i].rt_tdp_dc_10ma == 0 ||


#define POUNDV_POINTS_PRINT(i,suffix)   \
                  .set_FREQUENCY_##suffix(iv_attr_mvpd_data[i].frequency_mhz)  \
                  .set_VDD_##suffix(iv_attr_mvpd_data[i].vdd_mv) \
                 .set_IDD_TDP_AC_##suffix(iv_attr_mvpd_data[i].idd_tdp_ac_10ma) \
                 .set_IDD_TDP_DC_##suffix(iv_attr_mvpd_data[i].idd_tdp_dc_10ma) \
                 .set_IDD_RDP_AC_##suffix(iv_attr_mvpd_data[i].idd_rdp_ac_10ma) \
                 .set_IDD_RDP_DC_##suffix(iv_attr_mvpd_data[i].idd_rdp_dc_10ma) \
                 .set_VCS_##suffix(iv_attr_mvpd_data[i].vcs_mv) \
                 .set_ICS_TDP_AC_##suffix(iv_attr_mvpd_data[i].ics_tdp_ac_10ma) \
                 .set_ICS_TDP_DC_##suffix(iv_attr_mvpd_data[i].ics_tdp_dc_10ma) \
                 .set_ICS_RDP_AC_##suffix(iv_attr_mvpd_data[i].ics_rdp_ac_10ma) \
                 .set_ICS_RDP_DC_##suffix(iv_attr_mvpd_data[i].ics_rdp_dc_10ma) \
                 .set_ICS_RDP_AC_##suffix(iv_attr_mvpd_data[i].rt_tdp_ac_10ma) \
                 .set_ICS_RDP_DC_##suffix(iv_attr_mvpd_data[i].rt_tdp_dc_10ma) \
                 .set_VDD_VMIN_##suffix(iv_attr_mvpd_data[i].vdd_vmin)

//w => N_L (w > 7 is invalid)
//x => N_S (x > N_L is invalid)
//y => L_S (y > (N_L - S_N) is invalid)
//z => S_N (z > N_S is invalid
#define VALIDATE_FREQUENCY_DROP_VALUES(w, x, y, z, state) \
    if ((w > 7)         ||      \
        (x > w)         ||      \
        (y > (w - z))   ||      \
        (z > x)         ||      \
        ((w | x | y | z) == 0)) \
    { state = 0; }

#define POUNDV_SLOPE_CHECK(x,y)   x > y ? " is GREATER (ERROR!) than " : " is less than "

#define PRINT_LEAD1(_buffer, _format, _var1)                    \
    {                                                           \
        char _temp_buffer[64];                                  \
        strcpy(_buffer,"");                                     \
        sprintf(_temp_buffer, _format, _var1);                 \
        strcat(_buffer, _temp_buffer);                          \
    }

#define HEX_DEC_STR(_buffer, _value)                            \
   {                                                            \
       char _temp_buffer[64];                                   \
       sprintf(_temp_buffer, "0x%04X (%5d)  ", _value, _value); \
       strcat(_buffer, _temp_buffer);                           \
   }

#define HEX_STR(_buffer, _value)                                \
   {                                                            \
       char _temp_buffer[64];                                   \
       sprintf(_temp_buffer, "0x%04X  ", _value);               \
       strcat(_buffer, _temp_buffer);                           \
   }


#define VALIDATE_WOF_HEADER_DATA(a, b, c, d, e, f, g, h, i, state)         \
    if ( ((!a) || (!b) || (!c) || (!d) || (!e) || (!f) || (!g) || (!h) || (!i)))  \
    { state = 0; }

#if 0
// #V sample data
const fapi2::voltageBucketData_t g_vpd_PVData =
{
    1,
    {
//      C-Freq  VDDVLT  IDDTAC  IDDTDC  IDDRAC  IDDRDC  VCSVLT  ICSTAC  ICSTDC  ICSRAC ICSRDC CFGSRT VDDVMN IVDDPP TCPPT
        0x0960, 0x0320, 0x0163, 0x00BD, 0x0191, 0x044C, 0x00C4, 0x0191, 0x06A4, 0x0191,0x06A4,0x041A,0x02F7,0xFDF3,0x2C,0x00,0x00,0x00,0x00,0x00,0x00,   //Psav
        0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,0x0000,0x0000,0x0000,0x0000,0x00,0x00,0x00,0x00,0x00,0x00,0x00,   //CF1
        0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,0x0000,0x0000,0x0000,0x0000,0x00,0x00,0x00,0x00,0x00,0x00,0x00,   //CF2
        0x0C1C, 0x0384, 0x0163, 0x00BD, 0x0191, 0x044C, 0x00C4, 0x0191, 0x06A4, 0x0191,0x06A4,0x041A,0x02F7,0xFDF3,0x2C,0x00,0x00,0x00,0x00,0x00,0x00,   //CF3
        0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,0x0000,0x0000,0x0000,0x0000,0x00,0x00,0x00,0x00,0x00,0x00,0x00,   //CF4
        0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,0x0000,0x0000,0x0000,0x0000,0x00,0x00,0x00,0x00,0x00,0x00,0x00,   //CF5
        0x0FA0, 0x03e8, 0x0163, 0x00BD, 0x0191, 0x044C, 0x00C4, 0x0191, 0x06A4, 0x0191,0x06A4,0x041A,0x02F7,0xFDF3,0x2C,0x00,0x00,0x00,0x00,0x00,0x00,   //CF6
        0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,0x0000,0x0000,0x0000,0x0000,0x00,0x00,0x00,0x00,0x00,0x00,0x00,   //Fmax
    },
    {
//SR    VDNVLT  IDNTAC  IDNTDC  VIOVLT  IIOTAC  IIOTDC  VCIVLT  ICITAC  ICITDC
        0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,
    },
    {
//      PAUFRQ  SSPTAR  VDNPOW  VIOPOW  PCIPOW  SSPACT  IDDRLT VDDTWI  VCSTWI VIOTWI  AMBTWI  MDINPLT
        0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,0x00,   0x00,  0x00,   0x00,   0x00,
//      RDPSPT  TDPSPT  VDDTWCFRQ FFCFREQ  PSFREQ  UTFREQ  FMFREQ  MMATT   IOTT  FFPT
        0x00,   0x00,   0x0DAC,   0x09C4,  0x07D0, 0x0EDA, 0x0FA0, 0x0000, 0x00, 0x00,
    },

};
#endif

// #V sample data
/*const uint8_t g_vpd_PVData[] =
{
    1,
//      C-Freq     VDDVLT     IDDTAC       IDDTDC     IDDRAC     IDDRDC     VCSVLT     ICSTAC     ICSTDC    ICSRAC    ICSRDC    CFGSRT    VDDVMN    IVDDPP   TCPPT
        0x09,0x60, 0x03,0x20, 0x01,0x63, 0x00,0xBD, 0x01,0x91, 0x04,0x4C, 0x00,0xC4, 0x01,0x91, 0x06,0xA4, 0x01,0x91,0x06,0xA4,0x04,0x1A,0x02,0xF7,0xFD,0xF3,0x2C,0x00,0x00,0x00,0x00,0x00,0x00,   //Psav
        0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,   //CF1
        0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,   //CF2
        0x0C,0x1C, 0x03,0x84, 0x01,0x63, 0x00,0xBD, 0x01,0x91, 0x04,0x4C, 0x00,0xC4, 0x01,0x91, 0x06,0xA4, 0x01,0x91,0x06,0xA4,0x04,0x1A,0x02,0xF7,0xFD,0xF3,0x2C,0x00,0x00,0x00,0x00,0x00,0x00,   //CF3
        0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,   //CF4
        0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,   //CF5
        0x0F,0xA0, 0x03,0xE8, 0x01,0x63, 0x00,0xBD, 0x01,0x91, 0x04,0x4C, 0x00,0xC4, 0x01,0x91, 0x06,0xA4, 0x01,0x91,0x06,0xA4,0x04,0x1A,0x02,0xF7,0xFD,0xF3,0x2C,0x00,0x00,0x00,0x00,0x00,0x00,   //CF6
        0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,   //Fmax
//SR      VDNVLT     IDNTAC     IDNTDC     VIOVLT    IIOTAC     IIOTDC     VCIVLT     ICITAC     ICITDC
        0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,
//        PAUFRQ    SSPTAR     VDNPOW     VIOPOW     PCIPOW     SSPACT  IDDRLT  VDDTWI     VCSTWI VIOTWI  AMBTWI  MDINPLT
        0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00,0x00,   0x00,  0x00,   0x00,   0x00,
//      RDPSPT  TDPSPT  VDDTWCFRQ  FFRQMCFREQ
        0x00,   0x00,   0x00,0x00,    0x00,0x00,    0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00,

};*/


const uint8_t g_vpd_PVData[] =
{
    1,
//      C-Freq     VDDVLT     IDDTAC       IDDTDC     IDDRAC     IDDRDC     VCSVLT     ICSTAC     ICSTDC    ICSRAC    ICSRDC    CFGSRT    VDDVMN    IVDDPP   TCPPT
        0x07,0xd0, 0x03,0x84, 0x30,0xd8, 0x12,0xc4, 0x30,0xd8, 0x12,0xc4, 0x03,0x84, 0x01,0x8f, 0x02,0xc4, 0x01,0x8f,0x02,0xc4,0x08,0x20,0x03,0x24,0x43,0x9c,0xaa,0x01,0x7c,0x01,0x00,0x00,0x00,   //CF0
        0x08,0x98, 0x03,0x93, 0x36,0xe5, 0x12,0xf6, 0x36,0xe5, 0x12,0xf6, 0x03,0x93, 0x01,0xc0, 0x02,0xc8, 0x01,0xc0,0x02,0xc8,0x08,0xf0,0x03,0x31,0x49,0xdb,0xaa,0x01,0xab,0x01,0x02,0x00,0x00,   //CF1
        0x09,0x60, 0x03,0xa2, 0x3d,0x2a, 0x13,0x29, 0x3d,0x2a, 0x13,0x29, 0x03,0xa2, 0x01,0xf4, 0x02,0xcd, 0x01,0xf4,0x02,0xcd,0x09,0xc0,0x03,0x3e,0x50,0x53,0xaa,0x01,0xdb,0x01,0x05,0x00,0x00,   //CF2
        0x0a,0x28, 0x03,0xb1, 0x43,0xa7, 0x13,0x5d, 0x43,0xa7, 0x13,0x5d, 0x03,0xb1, 0x02,0x29, 0x02,0xd2, 0x02,0x29,0x02,0xd2,0x0a,0x90,0x03,0x4c,0x57,0x04,0xaa,0x02,0x0e,0x01,0x08,0x00,0x00,   //CF3
        0x0a,0xf0, 0x03,0xc0, 0x4a,0x5d, 0x13,0x91, 0x4a,0x5d, 0x13,0x91, 0x03,0xc0, 0x02,0x60, 0x02,0xd7, 0x02,0x60,0x02,0xd7,0x0b,0x60,0x03,0x59,0x5d,0xee,0xaa,0x02,0x42,0x01,0x0a,0x00,0x00,   //CF4
        0x0b,0x54, 0x03,0xcf, 0x4e,0x97, 0x13,0xc5, 0x4e,0x97, 0x13,0xc5, 0x03,0xcf, 0x02,0x82, 0x02,0xdc, 0x02,0x82,0x02,0xdc,0x0b,0xc8,0x03,0x67,0x62,0x5c,0xaa,0x02,0x63,0x01,0x0d,0x00,0x00,   //CF5
        0x0b,0xb8, 0x03,0xde, 0x52,0xee, 0x13,0xfa, 0x52,0xee, 0x13,0xfa, 0x03,0xde, 0x02,0xa5, 0x02,0xe1, 0x02,0xa5,0x02,0xe1,0x0c,0x30,0x03,0x74,0x66,0xe8,0xaa,0x02,0x84,0x01,0x10,0x00,0x00,   //CF6
        0x0c,0x1c, 0x03,0xe8, 0x56,0xd2, 0x14,0x1e, 0x56,0xd2, 0x14,0x1e, 0x03,0xe8, 0x02,0xc5, 0x02,0xe4, 0x02,0xc5,0x02,0xe4,0x0c,0x98,0x03,0x7d,0x6a,0xf0,0xaa,0x02,0xa3,0x01,0x12,0x00,0x00,   //CF7
//SR      VDNVLT     IDNTAC     IDNTDC     VIOVLT    IIOTAC     IIOTDC     VCIVLT     ICITAC     ICITDC
        0x03,0x84, 0x03,0xd2, 0x00,0xF4, 0x03,0x84, 0x06,0xba, 0x06,0xba, 0x03,0x52, 0x02,0xfd, 0x02,0xfd, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00,0x00,
//        PAUFRQ    SSPTAR     VDNPOW     VIOPOW     PCIPOW     AVDD       SSPACT  IDDRLT       VDDTWI   VCSTWI VIOTWI  AMBTWI  MDINPLT
        0x00,0x00, 0x07,0xd0, 0x01,0x5e, 0x00,0x0b, 0x00,0x1f, 0x00,0x0d, 0x0a,0xb2, 0x10,0x04,  0x0b,   0x02,   0x02,   0x03,  0x00,
//      RDPSPT  TDPSPT  WOFBSCFRQ    FFCFREQ   VDDPsavCoreF VDDCF6CoreF VDDFmaxCF  MMATemp  IOTemp    FFMPT
        0xAA,   0xAA,   0x0b,0x54, 0x07,0xd0, 0x07,0xD0,    0x0b,0xb8, 0x0c,0x1c, 0xbe,    0xa0,   0x07,0xd0,
};


/*
const uint8_t g_vpd_PVData[] =
{
    1,
//      C-Freq     VDDVLT     IDDTAC       IDDTDC     IDDRAC     IDDRDC     VCSVLT     ICSTAC     ICSTDC    ICSRAC    ICSRDC    CFGSRT    VDDVMN    IVDDPP   TCPPT
        0x07,0xd0, 0x02,0xBB, 0x23,0x2a, 0x10,0x50, 0x23,0x2a, 0x10,0x50, 0x02,0xbc, 0x01,0x1f, 0x02,0x86, 0x01,0x1f,0x02,0x86,0x08,0x20,0x02,0x70,0x33,0x7b,0xaa,0x00,0x00,0x00,0x00,0x00,0x00,   //CF0
        0x08,0x98, 0x02,0xdb, 0x28,0xff, 0x10,0xaf, 0x28,0xff, 0x10,0xaf, 0x02,0xdb, 0x01,0x4e, 0x02,0x8f, 0x01,0x4e,0x02,0x8f,0x08,0xf0,0x02,0x8c,0x39,0xae,0xaa,0x00,0x00,0x00,0x00,0x00,0x00,   //CF1
        0x09,0x60, 0x02,0xfa, 0x2f,0x35, 0x11,0x0c, 0x2f,0x35, 0x11,0x0c, 0x02,0xfa, 0x01,0x81, 0x02,0x98, 0x01,0x81,0x02,0x98,0x09,0xc0,0x02,0xa8,0x40,0x41,0xaa,0x00,0x00,0x00,0x00,0x00,0x00,   //CF2
        0x0a,0x28, 0x03,0x20, 0x36,0x7b, 0x11,0x81, 0x36,0x7b, 0x11,0x81, 0x03,0x20, 0x01,0xbd, 0x02,0xa4, 0x01,0xbd,0x02,0xa4,0x0a,0x90,0x02,0xca,0x47,0xfc,0xaa,0x00,0x00,0x00,0x00,0x00,0x00,   //CF3
        0x0a,0xf0, 0x03,0x4e, 0x3f,0x18, 0x12,0x12, 0x3f,0x18, 0x12,0x12, 0x03,0x4e, 0x02,0x03, 0x02,0xb2, 0x02,0x03,0x02,0xb2,0x0b,0x60,0x02,0xf3,0x51,0x2b,0xaa,0x00,0x00,0x00,0x00,0x00,0x00,   //CF4
        0x0b,0x54, 0x03,0x6b, 0x44,0x46, 0x12,0x70, 0x44,0x46, 0x12,0x70, 0x03,0x6b, 0x02,0x2d, 0x02,0xbb, 0x02,0x2D,0x02,0xbb,0x0b,0xc8,0x03,0x0d,0x56,0xb7,0xaa,0x00,0x00,0x00,0x00,0x00,0x00,   //CF5
        0x0b,0xb8, 0x03,0x82, 0x49,0x0d, 0x12,0xbd, 0x49,0x0d, 0x12,0xbd, 0x03,0x82, 0x02,0x54, 0x02,0xc2, 0x02,0x54,0x02,0xc2,0x0c,0x30,0x03,0x21,0x5b,0xca,0xaa,0x00,0x00,0x00,0x00,0x00,0x00,   //CF6
        0x0c,0x1c, 0x03,0xab, 0x4f,0xff, 0x13,0x47, 0x4f,0xff, 0x13,0x47, 0x03,0xab, 0x02,0x8d, 0x02,0xD0, 0x02,0x8d,0x02,0xd0,0x0c,0x98,0x03,0x46,0x63,0x47,0xaa,0x00,0x00,0x00,0x00,0x00,0x00,   //CF7
//SR      VDNVLT     IDNTAC     IDNTDC     VIOVLT    IIOTAC     IIOTDC     VCIVLT     ICITAC     ICITDC
        0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,
//        PAUFRQ    SSPTAR     VDNPOW     VIOPOW     PCIPOW     SSPACT  IDDRLT  VDDTWI     VCSTWI VIOTWI  AMBTWI  MDINPLT
        0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00,0x00,   0x00,  0x00,   0x00,   0x00,
//      RDPSPT  TDPSPT  WOFBSCFRQ    FFCFREQ   VDDPsavCoreF VDDCF6CoreF VDDFmaxCF  MMATemp  IOTemp    FFMPT
        0x00,   0x00,   0x0D,0xAC, 0x0B,0xB8, 0x07,0xD0,    0x0E,0xD8, 0x0F,0xA0, 0x00,    0x00,   0x00,0x00,
};


const uint8_t g_vpd_PVData[] =
{
    1,
//      C-Freq     VDDVLT     IDDTAC       IDDTDC     IDDRAC     IDDRDC     VCSVLT     ICSTAC     ICSTDC    ICSRAC    ICSRDC    CFGSRT    VDDVMN    IVDDPP   TCPPT
        0x08,0x98, 0x02,0x71, 0x07,0x6c, 0x00,0xBD, 0x01,0x91, 0x04,0x4C, 0x03,0x39, 0x00,0x78, 0x06,0xA4, 0x01,0x2D,0x06,0xA4,0x04,0x1A,0x02,0xF7,0xFD,0xF3,0x2C,0x00,0x00,0x00,0x00,0x00,0x00,   //Psav
        0x09,0x60, 0x02,0xA3, 0x08,0x34, 0x00,0xC1, 0x01,0x95, 0x04,0x53, 0x03,0x52, 0x00,0x80, 0x06,0xBD, 0x01,0x31,0x07,0x3A,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,   //CF1
        0x0B,0x54, 0x02,0xEE, 0x09,0x92, 0x00,0xC5, 0x01,0x9F, 0x04,0x58, 0x03,0x6B, 0x00,0x87, 0x06,0xF9, 0x01,0x3B,0x07,0xD0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,   //CF2
        0x0C,0xE4, 0x03,0x2F, 0x0A,0xE1, 0x00,0xCD, 0x01,0xA5, 0x04,0x5C, 0x03,0x84, 0x00,0x91, 0x07,0x2B, 0x01,0x41,0x08,0x1B,0x04,0x1A,0x02,0xF7,0xFD,0xF3,0x2C,0x00,0x00,0x00,0x00,0x00,0x00,   //CF3
        0x0D,0xAC, 0x03,0x70, 0x0B,0xAE, 0x00,0xD3, 0x01,0xB1, 0x04,0x63, 0x03,0x9D, 0x00,0x9C, 0x07,0x67, 0x01,0x4D,0x08,0x66,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,   //CF4
        0x0F,0x3C, 0x03,0xB1, 0x0C,0x76, 0x00,0xDA, 0x01,0xB9, 0x04,0x6A, 0x03,0xB6, 0x00,0xA5, 0x07,0xAD, 0x01,0x55,0x08,0xFC,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,   //CF5
        0x10,0x04, 0x03,0xED, 0x0D,0x7A, 0x00,0xE4, 0x01,0xC7, 0x04,0x6F, 0x03,0xCF, 0x00,0xB2, 0x07,0xD0, 0x01,0x63,0x09,0x60,0x04,0x1A,0x02,0xF7,0xFD,0xF3,0x2C,0x00,0x00,0x00,0x00,0x00,0x00,   //CF6
        0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,   //Fmax
//SR      VDNVLT     IDNTAC     IDNTDC     VIOVLT    IIOTAC     IIOTDC     VCIVLT     ICITAC     ICITDC
        0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,
//        PAUFRQ    SSPTAR     VDNPOW     VIOPOW     PCIPOW     SSPACT  IDDRLT  VDDTWI     VCSTWI VIOTWI  AMBTWI  MDINPLT
        0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00,0x00,   0x00,  0x00,   0x00,   0x00,
//      RDPSPT  TDPSPT  WOFBSCFRQ    FFCFREQ   VDDPsavCoreF VDDCF6CoreF VDDFmaxCF  MMATemp  IOTemp    FFMPT
        0x00,   0x00,   0x0D,0xAC, 0x0B,0xB8, 0x07,0xD0,    0x0E,0xD8, 0x0F,0xA0, 0x00,    0x00,   0x00,0x00,
};
*/

//Sample data to verify functionality
////
//// WOF sample data
const uint8_t g_wofData[] =
{
    0x57, 0x46, 0x54, 0x48  /*MAGIC CODE WFTH*/,
    0x00, 0x00, 0x00, 0x01  /*version*/,
    0x00, 0x10              /*VRT block size*/,
    0x00, 0x04              /*VRT header size*/,
    0x00, 0x01              /*VRT data size*/,
    0x1                     /*OCS mode*/,
    0x20                    /*core count*/,//16
    0x0C, 0xE4              /*Vcs start*/,
    0x0D, 0x05              /*Vcs step*/,
    0x00, 0x04              /*Vcs size*/,
    0x09, 0xC4              /*Vdd start*/,
    0x01, 0xF4              /*Vdd step*/,
    0x00, 0x1A              /*Vdd size*/,
    0x0C, 0x35              /*Vratio start*/,
    0x02, 0x71              /*Vratio step*/,//16
    0x00, 0x0C              /*Vratio size*/,
    0x13, 0x88              /*IO start*/,
    0x13, 0x88              /*IO step*/,
    0x00, 0x06              /*IO size*/,
    0x00, 0x17              /*AC start*/,
    0x00, 0x02              /*AC step*/,
    0x00, 0x4               /*AC size*/,
    0x00, 0x00              /*reserved*/, //16
    0x00, 0x0               /*Socket Power*/,
    0x00, 0x00              /*SPT Freq*/,
    0x00, 0x00              /*RDP Curr*/,
    0x00, 0x0               /*Boost Curr*/,
    0x00, 0x00, 0x00, 0x00  /* table time stamp*/,
    0x00, 0x0               /*table version*/,
    0x00, 0x0               /*reserved*/, //16
    0x0                     /*TDP VCS Ceff index*/,
    0x0                     /*TDP VDD Ceff index*/,
    0x0                     /*TDP IO Powr index*/,
    0x0                     /*TDP Amb Cond index*/,
    0x0                     /*IO full Wattage*/,
    0x0                     /*IO Disabled wattage*/,
    0x00,  0x00  /* reserved*/, //8
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 /*package name*/,//16
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //16
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //16
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

// These values are for dummy VPD having a 3100MHz UT frequency
const uint8_t g_static_vrt[] =
{
            //Index
    0x70,   //  0
    0x6f,   //  1
    0x6e,   //  2
    0x6d,   //  3
    0x6c,   //  4
    0x6b,   //  5
    0x58,   //  6
    0x54,   //  7
    0x50,   //  8
    0x4C,   //  9
    0x48,   //  10
    0x44    //  11
};


// These values are for parts having a 4000MHz UT frequency
const uint8_t g_static_vrt_hw[] =
{
            //Index
    0xb4,   //  0
    0xb4,   //  1
    0xb4,   //  2
    0xb4,   //  3
    0xb4,   //  4
    0xb2,   //  5
    0xac,   //  6
    0xa6,   //  7
    0xa1,   //  8
    0x9d,   //  9
    0x98,   //  10
    0x93    //  11
};



char const* vpdSetStr[] = VPD_PT_SET_STR;
char const* region_names[] = VPD_OP_SLOPES_REGION_ORDER_STR;

using namespace pm_pstate_parameter_block;

///////////////////////////////////////////////////////////
////////     p10_pstate_parameter_block
///////////////////////////////////////////////////////////
fapi2::ReturnCode
p10_pstate_parameter_block( const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
                           PstateSuperStructure* io_pss,
                           uint8_t* o_buf,
                           uint32_t& io_size)
{
    FAPI_DBG("> p10_pstate_parameter_block");

    PlatPmPPB *l_pmPPB = new PlatPmPPB(i_target);
    GlobalPstateParmBlock_t *l_globalppb = new GlobalPstateParmBlock_t;
    OCCPstateParmBlock_t l_occppb;;

    do
    {

        //Instantiate pstate object

        FAPI_ASSERT(l_pmPPB->iv_init_error == false,
                fapi2::PSTATE_PB_ATTRIBUTE_ACCESS_ERROR()
                .set_CHIP_TARGET(i_target),
                "Pstate Parameter Block attribute access error");


        // -----------------------------------------------------------
        // Clear the PstateSuperStructure and install the magic number
        //----------------------------------------------------------
        memset(io_pss, 0, sizeof(PstateSuperStructure));

        FAPI_INF("Populating magic number in Pstate Parameter block structure");
        (*io_pss).iv_magic = revle64(PSTATE_PARMSBLOCK_MAGIC);

        //Local variables for Global,local and OCC parameter blocks
        // PGPE content
        memset (l_globalppb, 0, sizeof(GlobalPstateParmBlock_t));

        // OCC content
        memset (&l_occppb , 0, sizeof (OCCPstateParmBlock_t));

        //if PSTATES_MODE is off then we dont need to execute further to collect
        //the data.
        if (l_pmPPB->isPstateModeEnabled())
        {
            FAPI_INF("Pstate mode is to not boot the PGPE.  Thus, none of the parameter blocks will be constructed");

            // Set the io_size to 0 so that memory allocation issues won't be
            // detected by the caller.
            io_size = 0;
            break;
        }

        // ----------------
        // Compute Fmax and update pstate0
        // ----------------
//        l_pmPPB->pm_set_frequency();

        // ----------------
        // get VPD data (#V,#W,IQ)
        // ----------------
        FAPI_TRY(l_pmPPB->vpd_init(),"vpd_init function failed");

        // ----------------
        // Compute VPD points for different regions
        // ----------------
        l_pmPPB->compute_vpd_pts();

        // Safe mode freq and volt init
        // ----------------
        FAPI_TRY(l_pmPPB->safe_mode_init());

        // ----------------
        // Retention voltage computation
        // ----------------
        FAPI_TRY(l_pmPPB->compute_retention_vid());

        // ----------------
        // RVRM enablement state
        // ----------------
        FAPI_TRY(l_pmPPB->rvrm_enablement());

        // ----------------
        // RESCLK Initialization
        // ----------------
        l_pmPPB->resclk_init();

        // ----------------
        // Initialize GPPB structure
        // ----------------
        FAPI_TRY(l_pmPPB->gppb_init(l_globalppb));

        // ----------------
        // WOF initialization
        // ----------------
        io_size = 0;
        FAPI_TRY(l_pmPPB->wof_init(
                 o_buf,
                 io_size),
                 "WOF initialization failure");

        // ----------------
        //Initialize OPPB structure
        // ----------------
        FAPI_TRY(l_pmPPB->oppb_init(&l_occppb));


        // ----------------
        //Initialize pstate feature attribute state
        // ----------------
        FAPI_TRY(l_pmPPB->set_global_feature_attributes());


        // Put out the Parmater Blocks to the trace
        gppb_print((l_globalppb));
        oppb_print((&l_occppb));

        // Populate Global,local and OCC parameter blocks into Pstate super structure
        (*io_pss).iv_globalppb = *l_globalppb;
        (*io_pss).iv_occppb = l_occppb;
    }
    while(0);

fapi_try_exit:
    delete l_pmPPB;
    delete l_globalppb;
    FAPI_DBG("< p10_pstate_parameter_block");
    return fapi2::current_err;
}
// END OF PSTATE PARAMETER BLOCK function

///////////////////////////////////////////////////////////
////////    gppb_print
///////////////////////////////////////////////////////////
void gppb_print(GlobalPstateParmBlock_t* i_gppb)
{
    static const uint32_t   BUFFSIZE = 512;
    char                    l_buffer[BUFFSIZE];
    char                    l_temp_buffer[BUFFSIZE];
    const char*     pv_op_str[NUM_OP_POINTS] = PV_OP_STR;
    const char*     prt_region_names[VPD_NUM_SLOPES_REGION] = VPD_OP_SLOPES_REGION_ORDER_STR;
    const char*     prt_rail_names[RUNTIME_RAILS] = RUNTIME_RAIL_STR;
    const char*     prt_dds_slope_names[NUM_POUNDW_DDS_FIELDS] = POUNDW_DDS_FIELDS_STR;
    char vlt_str[][4] = {"VDD","VCS"};
    // Put out the endian-corrected scalars
    FAPI_INF("---------------------------------------------------------------------------------------");
    FAPI_INF("Global Pstate Parameter Block");
    FAPI_INF("---------------------------------------------------------------------------------------");

//    strcpy(l_buffer,"");
//    sprintf (l_temp_buffer, "  %-20s : ","Frequency Ref  (KHz)");
//    strcat(l_buffer, l_temp_buffer);

    PRINT_LEAD1(l_buffer, "%-20s : ","Frequency Ref  (KHz)");
    HEX_DEC_STR(l_buffer,
             revle32(i_gppb->reference_frequency_khz));
    FAPI_INF("%s", l_buffer);

    PRINT_LEAD1(l_buffer, "%-20s : ","Frequency Step (KHz)");
    HEX_DEC_STR(l_buffer,
             revle32(i_gppb->frequency_step_khz));
    FAPI_INF("%s", l_buffer);

    PRINT_LEAD1(l_buffer, "%-20s : ","Frequency Ceil (KHz)");
    HEX_DEC_STR(l_buffer,
             revle32(i_gppb->frequency_ceiling_khz));
    FAPI_INF("%s", l_buffer);

    PRINT_LEAD1(l_buffer, "%-20s : ","Frequency OCC  (MHz)");
    HEX_DEC_STR(l_buffer,
             revle32(i_gppb->occ_complex_frequency_mhz));
    FAPI_INF("%s", l_buffer);

    FAPI_INF("Operating Points:          Freq(MHz)         VDD(mV)       IDTAC(10mA)     IDTDC(10mA)     IDRAC(10mA)     IDRDC(10mA)");
    for (uint32_t i = 0; i < NUM_OP_POINTS; i++)
    {
        strcpy(l_buffer,"");
        sprintf (l_temp_buffer, "  %-20s : ",pv_op_str[i]);
        strcat(l_buffer, l_temp_buffer);

        HEX_DEC_STR(l_buffer,
                revle32(i_gppb->operating_points_set[0][i].frequency_mhz));

        HEX_DEC_STR(l_buffer,
                revle32(i_gppb->operating_points_set[0][i].vdd_mv));

        HEX_DEC_STR(l_buffer,
                revle32(i_gppb->operating_points_set[0][i].idd_tdp_ac_10ma));

        HEX_DEC_STR(l_buffer,
                revle32(i_gppb->operating_points_set[0][i].idd_tdp_dc_10ma));

        HEX_DEC_STR(l_buffer,
                revle32(i_gppb->operating_points_set[0][i].idd_rdp_ac_10ma));

        HEX_DEC_STR(l_buffer,
                revle32(i_gppb->operating_points_set[0][i].idd_rdp_dc_10ma));

        FAPI_INF("%s", l_buffer);
    }

    FAPI_INF("Operating Points:          Freq(MHz)         VCS(mV)       ICTAC(10mA)     ICTDC(10mA)     ICRAC(10mA)     IDRDC(10mA)");
    for (uint32_t i = 0; i < NUM_OP_POINTS; i++)
    {
        PRINT_LEAD1(l_buffer, "  %-20s : ",pv_op_str[i]);

        HEX_DEC_STR(l_buffer,
                revle32(i_gppb->operating_points_set[0][i].frequency_mhz));

        HEX_DEC_STR(l_buffer,
                revle32(i_gppb->operating_points_set[0][i].vcs_mv));

        HEX_DEC_STR(l_buffer,
                revle32(i_gppb->operating_points_set[0][i].ics_tdp_ac_10ma));

        HEX_DEC_STR(l_buffer,
                revle32(i_gppb->operating_points_set[0][i].ics_tdp_dc_10ma));

        HEX_DEC_STR(l_buffer,
                revle32(i_gppb->operating_points_set[0][i].ics_rdp_ac_10ma));

        HEX_DEC_STR(l_buffer,
                revle32(i_gppb->operating_points_set[0][i].ics_rdp_dc_10ma));

        FAPI_INF("%s", l_buffer);
    }

    FAPI_INF("Operating Points:          Freq_GB(mHz)    VDD_vmin(mV)  IDD_POW(10mA) CORE_POWR_TEMP(0.5C)");
    for (uint32_t i = 0; i < NUM_OP_POINTS; i++)
    {
        PRINT_LEAD1(l_buffer, "  %-20s : ",pv_op_str[i]);

        HEX_DEC_STR(l_buffer,
                revle32(i_gppb->operating_points_set[0][i].vdd_vmin));

        HEX_DEC_STR(l_buffer,
                revle32(i_gppb->operating_points_set[0][i].rt_tdp_ac_10ma));

        HEX_DEC_STR(l_buffer,
                revle32(i_gppb->operating_points_set[0][i].rt_tdp_dc_10ma));

        FAPI_INF("%s", l_buffer);
    }



    FAPI_INF("System Parameters:           VDD           VCS           VDN")

    PRINT_LEAD1(l_buffer, "  %-20s : ", "Load line (uOhm)");
    HEX_DEC_STR(l_buffer,
            revle32(i_gppb->vdd_sysparm.loadline_uohm));

    HEX_DEC_STR(l_buffer,
            revle32(i_gppb->vcs_sysparm.loadline_uohm));

    HEX_DEC_STR(l_buffer,
            revle32(i_gppb->vdn_sysparm.loadline_uohm));
    FAPI_INF("%s", l_buffer);

    PRINT_LEAD1(l_buffer, "  %-20s : ", "Dist Loss (uOhm)");
    HEX_DEC_STR(l_buffer,
            revle32(i_gppb->vdd_sysparm.distloss_uohm));
    HEX_DEC_STR(l_buffer,
            revle32(i_gppb->vcs_sysparm.distloss_uohm));
    HEX_DEC_STR(l_buffer,
            revle32(i_gppb->vdn_sysparm.distloss_uohm));
    FAPI_INF("%s", l_buffer);

    PRINT_LEAD1(l_buffer, "  %-20s : ", "Offset (uV)");
    HEX_DEC_STR(l_buffer,
            revle32(i_gppb->vdd_sysparm.distoffset_uv));
    HEX_DEC_STR(l_buffer,
            revle32(i_gppb->vcs_sysparm.distoffset_uv));
    HEX_DEC_STR(l_buffer,
            revle32(i_gppb->vdn_sysparm.distoffset_uv));
    FAPI_INF("%s", l_buffer);

    FAPI_INF("Safe Parameters:");

    PRINT_LEAD1(l_buffer, "  %-20s : ", "Frequency (KHz)");
    HEX_DEC_STR(l_buffer,
             revle32(i_gppb->safe_frequency_khz));
    FAPI_INF("%s", l_buffer);
             ;
    PRINT_LEAD1(l_buffer, "  %-20s : ", "Voltage (mV)");
    HEX_DEC_STR(l_buffer,
             revle32(i_gppb->safe_voltage_mv[SAFE_VOLTAGE_VDD]));
    FAPI_INF("%s", l_buffer);

    FAPI_INF("\nExternal VRM Parameters:");
    for (auto i=0; i < RUNTIME_RAILS; ++i)
    {
        strcpy(l_buffer,"");
        HEX_DEC_STR(l_buffer,
             revle32(i_gppb->ext_vrm_parms.transition_start_ns[i]));
        FAPI_INF("  %-3s %-24s : %s ",
                vlt_str[i],
                "Trans Start (ns)",
                l_buffer);

        strcpy(l_buffer,"");
        HEX_DEC_STR(l_buffer,
                revle32(i_gppb->ext_vrm_parms.transition_rate_inc_uv_per_us[i]));
        FAPI_INF("  %-3s %-24s : %s ",
                vlt_str[i],
                "Trans Rate-Incr (uv/us)",
                l_buffer);

        strcpy(l_buffer,"");
        HEX_DEC_STR(l_buffer,
                revle32(i_gppb->ext_vrm_parms.transition_rate_dec_uv_per_us[i]));
        FAPI_INF("  %-3s %-24s : %s ",
                vlt_str[i],
                "Trans Rate-Decr (uv/us)",
                l_buffer);

        strcpy(l_buffer,"");
        HEX_DEC_STR(l_buffer,
                revle32(i_gppb->ext_vrm_parms.stabilization_time_us[i]));
        FAPI_INF("  %-3s %-24s : %s ",
                vlt_str[i],
                "Stabl Time (us)",
                l_buffer);

        strcpy(l_buffer,"");
        HEX_DEC_STR(l_buffer,
               revle32(i_gppb->ext_vrm_parms.step_size_mv[i]));
        FAPI_INF("  %-3s %-24s : %s ",
                vlt_str[i],
                "Trans Step Size (uV)",
                l_buffer);
    }

#define xstr(s) str(s)
#define str(s) #s
#define PRINT_GPPB_SLOPES(_buffer, _member) \
    { \
        char _temp_buffer[64]; \
        sprintf(_buffer,  "  %-25s", xstr(_member)); \
        FAPI_INF("%s", _buffer); \
        for (auto i = 0; i < NUM_VPD_PTS_SET; ++i) \
        { \
            sprintf(_buffer, "  %20s (%s) : ", vpdSetStr[i], "hex"); \
            for (auto j = 0; j < VPD_NUM_SLOPES_REGION; ++j) \
            { \
                for (auto x = 0; x < RUNTIME_RAILS; ++x) \
                { \
                    sprintf(_temp_buffer, "0x%04X%1s ", \
                            revle16(i_gppb->_member[x][i][j])," "); \
                    strcat(_buffer, _temp_buffer); \
                } \
                strcat(_buffer, " "); \
            } \
            FAPI_INF("%s", _buffer); \
        } \
        FAPI_INF(""); \
        for (auto i = 0; i < NUM_VPD_PTS_SET; ++i) \
        { \
            sprintf(_buffer, "  %20s (%s) : ", vpdSetStr[i], "dec"); \
            for (auto j = 0; j < VPD_NUM_SLOPES_REGION; ++j) \
            { \
                for (auto x = 0; x < RUNTIME_RAILS; ++x) \
                { \
                    sprintf(_temp_buffer, "%6.3f%1s ", \
                            (float)(revle16(i_gppb->_member[x][i][j])) / (1 << VID_SLOPE_FP_SHIFT_12)," "); \
                    strcat(_buffer, _temp_buffer); \
                } \
                strcat(_buffer, " "); \
            } \
            FAPI_INF("%s", _buffer); \
        } \
        FAPI_INF(""); \
    }

    sprintf(l_buffer, "%-22s", "Pstate Slopes / Region");
    sprintf(l_temp_buffer, "%-10s", "");
    strcat(l_buffer, l_temp_buffer);
    for (auto  j = 0; j < VPD_NUM_SLOPES_REGION; ++j)
    {
        sprintf(l_temp_buffer, "   %s       ", prt_region_names[j]);
        strcat(l_buffer, l_temp_buffer);
    }
    FAPI_INF("%s",l_buffer);

    sprintf(l_buffer,  "%-31s", "");
    for (auto  j = 0; j < VPD_NUM_SLOPES_REGION; ++j)
    {
        for (auto x = 0; x < RUNTIME_RAILS; ++x)
        {
            sprintf(l_temp_buffer, "  %s   ", prt_rail_names[x]);
            strcat(l_buffer, l_temp_buffer);
        }
        strcat(l_buffer, " ");
    }
    FAPI_INF("%s", l_buffer);

    PRINT_GPPB_SLOPES(l_buffer, ps_voltage_slopes);
    PRINT_GPPB_SLOPES(l_buffer, ps_voltage_slopes);
    PRINT_GPPB_SLOPES(l_buffer, voltage_ps_slopes);
    PRINT_GPPB_SLOPES(l_buffer, ps_ac_current_tdp);
    PRINT_GPPB_SLOPES(l_buffer, ac_current_ps_tdp);
    PRINT_GPPB_SLOPES(l_buffer, ps_dc_current_tdp);
    PRINT_GPPB_SLOPES(l_buffer, dc_current_ps_tdp);
    PRINT_GPPB_SLOPES(l_buffer, ps_ac_current_rdp);
    PRINT_GPPB_SLOPES(l_buffer, ac_current_ps_rdp);
    PRINT_GPPB_SLOPES(l_buffer, ps_dc_current_rdp);
    PRINT_GPPB_SLOPES(l_buffer, dc_current_ps_rdp);

    int i = VPD_PT_SET_RAW;

    sprintf(l_buffer, "%-28s", "ps_dds_delay_slopes (C0)");
    sprintf(l_temp_buffer, "%-2s", "");
    strcat(l_buffer, l_temp_buffer);
    for (auto  j = 0; j < VPD_NUM_SLOPES_REGION; ++j)
    {
        sprintf(l_temp_buffer, " %s ", prt_region_names[j]);
        strcat(l_buffer, l_temp_buffer);
    }
    FAPI_INF("%s",l_buffer);

    sprintf(l_buffer, " %21s (%s) : ", vpdSetStr[i], "hex");
    for (auto j = 0; j < VPD_NUM_SLOPES_REGION; ++j)
    {
        sprintf(l_temp_buffer, "0x%04X%3s",
                revle16(i_gppb->ps_dds_delay_slopes[i][0][j])," ");
        strcat(l_buffer, l_temp_buffer);
    }
    FAPI_INF("%s", l_buffer);

    sprintf(l_buffer, "%-28s", "ps_dds_slopes (C0) Raw");
    sprintf(l_temp_buffer, "%-2s", "");
    strcat(l_buffer, l_temp_buffer);
    for (auto  j = 0; j < VPD_NUM_SLOPES_REGION; ++j)
    {
        sprintf(l_temp_buffer, " %s ", prt_region_names[j]);
        strcat(l_buffer, l_temp_buffer);
    }
    FAPI_INF("%s",l_buffer);

    for (uint8_t dds_cnt = TRIP_OFFSET; dds_cnt < NUM_POUNDW_DDS_FIELDS; ++dds_cnt)
    {
        sprintf(l_buffer, " %21s (%s) : ", prt_dds_slope_names[dds_cnt], "hex");
        for (auto j = 0; j < VPD_NUM_SLOPES_REGION; ++j)
        {
            sprintf(l_temp_buffer, "0x%04X%3s",
                    revle16(i_gppb->ps_dds_slopes[dds_cnt][i][0][j])," ");
            strcat(l_buffer, l_temp_buffer);
        }
        FAPI_INF("%s", l_buffer);
    }

    sprintf(l_buffer, "AVS Bus topology:");
    FAPI_INF("%s", l_buffer);

    PRINT_LEAD1(l_buffer, "  %-26s : ", "VDD AVS BUS NUM");
    HEX_STR(l_buffer,
            i_gppb->avs_bus_topology.vdd_avsbus_num);
    FAPI_INF("%s", l_buffer);

    PRINT_LEAD1(l_buffer, "  %-26s : ", "VDD AVS BUS RAIL SELECT");
    HEX_STR(l_buffer,
            i_gppb->avs_bus_topology.vdd_avsbus_rail);
    FAPI_INF("%s", l_buffer);

    PRINT_LEAD1(l_buffer, "  %-26s : ", "VCS AVS BUS NUM");
    HEX_STR(l_buffer,
            i_gppb->avs_bus_topology.vcs_avsbus_num);
    FAPI_INF("%s", l_buffer);

    PRINT_LEAD1(l_buffer, "  %-26s : ", "VCS AVS BUS RAIL SELECT");
    HEX_STR(l_buffer,
            i_gppb->avs_bus_topology.vcs_avsbus_rail);
    FAPI_INF("%s", l_buffer);

    PRINT_LEAD1(l_buffer, "  %-26s : ", "VDN AVS BUS NUM");
    HEX_STR(l_buffer,
            i_gppb->avs_bus_topology.vdn_avsbus_num);
    FAPI_INF("%s", l_buffer);

    PRINT_LEAD1(l_buffer, "  %-26s : ", "VDN AVS BUS RAIL SELECT");
    HEX_STR(l_buffer,
            i_gppb->avs_bus_topology.vdn_avsbus_rail);
    FAPI_INF("%s", l_buffer);

    PRINT_LEAD1(l_buffer, "  %-26s : ", "VIO AVS BUS NUM");
    HEX_STR(l_buffer,
            i_gppb->avs_bus_topology.vio_avsbus_num);
    FAPI_INF("%s", l_buffer);

    PRINT_LEAD1(l_buffer, "  %-26s : ", "VII AVS BUS RAIL SELECT");
    HEX_STR(l_buffer,
            i_gppb->avs_bus_topology.vio_avsbus_rail);
    FAPI_INF("%s", l_buffer);

    FAPI_INF("---------------------------------------------------------------------------------------");
}


///////////////////////////////////////////////////////////
////////   gppb_init
///////////////////////////////////////////////////////////
fapi2::ReturnCode PlatPmPPB::gppb_init(
                             GlobalPstateParmBlock_t *io_globalppb)
{
    FAPI_INF(">>>>>>>> gppb_init");
    do
    {
        // Needs to be Endianness corrected going into the block

        io_globalppb->magic.value = revle64(PSTATE_PARMSBLOCK_MAGIC);

        io_globalppb->reference_frequency_khz = revle32(iv_reference_frequency_khz);

        io_globalppb->frequency_step_khz = revle32(iv_frequency_step_khz);

        io_globalppb->frequency_ceiling_khz = revle32(iv_attrs.attr_freq_core_ceiling_mhz * 1000);

        io_globalppb->occ_complex_frequency_mhz = revle32(iv_attrs.attr_pau_frequency_mhz/4);

        FAPI_INF("Pstate Base Frequency %X (%d)",
                revle32(io_globalppb->reference_frequency_khz),
                revle32(io_globalppb->reference_frequency_khz));

        io_globalppb->vdd_sysparm = iv_vdd_sysparam;
        io_globalppb->vcs_sysparm = iv_vcs_sysparam;
        io_globalppb->vdn_sysparm = iv_vdn_sysparam;

        io_globalppb->array_write_vdn_mv = iv_array_vdn_mv;
        io_globalppb->array_write_vdd_mv = iv_array_vdd_mv;
        io_globalppb->rvrm_deadzone_mv   = iv_attrs.attr_rvrm_deadzone_mv;



        //Avs bus topology
        io_globalppb->avs_bus_topology.vdd_avsbus_num  = iv_attrs.attr_avs_bus_num[VDD];
        io_globalppb->avs_bus_topology.vdd_avsbus_rail = iv_attrs.attr_avs_bus_rail_select[VDD];
        io_globalppb->avs_bus_topology.vdn_avsbus_num  = iv_attrs.attr_avs_bus_num[VDN];
        io_globalppb->avs_bus_topology.vdn_avsbus_rail = iv_attrs.attr_avs_bus_rail_select[VDN];
        io_globalppb->avs_bus_topology.vcs_avsbus_num  = iv_attrs.attr_avs_bus_num[VCS];
        io_globalppb->avs_bus_topology.vcs_avsbus_rail = iv_attrs.attr_avs_bus_rail_select[VCS];
        io_globalppb->avs_bus_topology.vio_avsbus_num  = iv_attrs.attr_avs_bus_num[VIO];
        io_globalppb->avs_bus_topology.vio_avsbus_rail = iv_attrs.attr_avs_bus_rail_select[VIO];

        // External VRM parameters
        for(auto i = 0; i < RUNTIME_RAILS; ++i)
        {
            io_globalppb->ext_vrm_parms.transition_start_ns[i] =
                revle32(iv_attrs.attr_ext_vrm_transition_start_ns[i]);
            io_globalppb->ext_vrm_parms.transition_rate_inc_uv_per_us[i] =
                revle32(iv_attrs.attr_ext_vrm_transition_rate_inc_uv_per_us[i]);
            io_globalppb->ext_vrm_parms.transition_rate_dec_uv_per_us[i] =
                revle32(iv_attrs.attr_ext_vrm_transition_rate_dec_uv_per_us[i]);
            io_globalppb->ext_vrm_parms.stabilization_time_us[i] =
                revle32(iv_attrs.attr_ext_vrm_stabilization_time_us[i]);
            io_globalppb->ext_vrm_parms.step_size_mv[i] =
                revle32(iv_attrs.attr_ext_vrm_step_size_mv[i]);
        }

        //Bias values
        memcpy(&io_globalppb->poundv_biases_0p05pct,&iv_bias,sizeof(iv_bias));

        // safe_voltage_mv
        io_globalppb->safe_voltage_mv[SAFE_VOLTAGE_VDD] = revle32(iv_attrs.attr_pm_safe_voltage_mv[VDD]);
        io_globalppb->safe_voltage_mv[SAFE_VOLTAGE_VCS] = revle32(iv_attrs.attr_pm_safe_voltage_mv[VCS]);

        // safe_frequency_khz
        io_globalppb->safe_frequency_khz =
            iv_attrs.attr_pm_safe_frequency_mhz * 1000;
        io_globalppb->safe_frequency_khz = revle32(io_globalppb->safe_frequency_khz);
        FAPI_INF("Safe Mode Frequency %d (0x%X) kHz; VDD Voltage %d (0x%X) mV ",
                revle32(io_globalppb->safe_frequency_khz),
                revle32(io_globalppb->safe_frequency_khz),
                revle32(io_globalppb->safe_voltage_mv[SAFE_VOLTAGE_VDD]),
                revle32(io_globalppb->safe_voltage_mv[SAFE_VOLTAGE_VDD]));

#if 0

        //load vpd operating points
        for (uint32_t i = 0; i < NUM_OP_POINTS; i++)
        {
            io_globalppb->operating_points[i].frequency_mhz   = revle32(iv_attr_mvpd_poundV_biased[i].frequency_mhz);
            io_globalppb->operating_points[i].vdd_mv          = revle32(iv_attr_mvpd_poundV_biased[i].vdd_mv);
            io_globalppb->operating_points[i].idd_tdp_ac_10ma = revle32(iv_attr_mvpd_poundV_biased[i].idd_tdp_ac_10ma);
            io_globalppb->operating_points[i].idd_tdp_dc_10ma = revle32(iv_attr_mvpd_poundV_biased[i].idd_tdp_dc_10ma);
            io_globalppb->operating_points[i].idd_rdp_ac_10ma = revle32(iv_attr_mvpd_poundV_biased[i].idd_rdp_ac_10ma);
            io_globalppb->operating_points[i].idd_rdp_dc_10ma = revle32(iv_attr_mvpd_poundV_biased[i].idd_rdp_dc_10ma);
            io_globalppb->operating_points[i].vcs_mv          = revle32(iv_attr_mvpd_poundV_biased[i].vcs_mv);
            io_globalppb->operating_points[i].ics_tdp_ac_10ma = revle32(iv_attr_mvpd_poundV_biased[i].ics_tdp_ac_10ma);
            io_globalppb->operating_points[i].ics_tdp_dc_10ma = revle32(iv_attr_mvpd_poundV_biased[i].ics_tdp_ac_10ma);
            io_globalppb->operating_points[i].frequency_guardband_sort_mhz =
            revle32(iv_attr_mvpd_poundV_biased[i].frequency_guardband_sort_mhz);
            io_globalppb->operating_points[i].vdd_vmin        = revle32(iv_attr_mvpd_poundV_biased[i].vdd_vmin);
            io_globalppb->operating_points[i].idd_power_pattern_10ma =
            revle32(iv_attr_mvpd_poundV_biased[i].idd_power_pattern_10ma);
            io_globalppb->operating_points[i].core_power_pattern_temp_0p5C =
            revle32(iv_attr_mvpd_poundV_biased[i].core_power_pattern_temp_0p5C);
            io_globalppb->operating_points[i].pstate          = iv_attr_mvpd_poundV_biased[i].pstate;
        }
#endif

        // Initialize res clk data
        memset(&io_globalppb->resclk,0,sizeof(ResClkSetup_t));

        // -----------------------------------------------
        // populate VpdOperatingPoint with biased MVPD attributes
        // -----------------------------------------------
        for (uint8_t i = 0; i < NUM_VPD_PTS_SET; i++)
        {
            for (uint8_t j = 0; j < NUM_OP_POINTS; j++)
            {
                io_globalppb->operating_points_set[i][j].frequency_mhz   = revle32(iv_operating_points[i][j].frequency_mhz);
                io_globalppb->operating_points_set[i][j].vdd_mv          = revle32(iv_operating_points[i][j].vdd_mv);
                io_globalppb->operating_points_set[i][j].idd_tdp_ac_10ma = revle32(iv_operating_points[i][j].idd_tdp_ac_10ma);
                io_globalppb->operating_points_set[i][j].idd_tdp_dc_10ma = revle32(iv_operating_points[i][j].idd_tdp_dc_10ma);
                io_globalppb->operating_points_set[i][j].idd_rdp_ac_10ma = revle32(iv_operating_points[i][j].idd_rdp_ac_10ma);
                io_globalppb->operating_points_set[i][j].idd_rdp_dc_10ma = revle32(iv_operating_points[i][j].idd_rdp_dc_10ma);
                io_globalppb->operating_points_set[i][j].vcs_mv          = revle32(iv_operating_points[i][j].vcs_mv);
                io_globalppb->operating_points_set[i][j].ics_tdp_ac_10ma = revle32(iv_operating_points[i][j].ics_tdp_ac_10ma);
                io_globalppb->operating_points_set[i][j].ics_tdp_dc_10ma = revle32(iv_operating_points[i][j].ics_tdp_ac_10ma);
                io_globalppb->operating_points_set[i][j].vdd_vmin        = revle32(iv_operating_points[i][j].vdd_vmin);
                io_globalppb->operating_points_set[i][j].rt_tdp_ac_10ma =
                    revle32(iv_operating_points[i][j].rt_tdp_ac_10ma);
                io_globalppb->operating_points_set[i][j].rt_tdp_dc_10ma =
                    revle32(iv_operating_points[i][j].rt_tdp_dc_10ma);
                io_globalppb->operating_points_set[i][j].pstate          = iv_operating_points[i][j].pstate;
            }
        }

        // Calculate pre-calculated slopes
        compute_PStateV_I_slope(io_globalppb);

        //Copy over the DDS data
        memcpy(&io_globalppb->dds, &iv_poundW_data.entry, sizeof(((PoundW_t*)0)->entry));
        memcpy(&io_globalppb->dds_alt_cal, &iv_poundW_data.entry_alt_cal, sizeof(((PoundW_t*)0)->entry_alt_cal));
        memcpy(&io_globalppb->dds_tgt_act_bin, &iv_poundW_data.entry_tgt_act_bin, (sizeof(((PoundW_t*)0)->entry_tgt_act_bin)));
        memcpy(&io_globalppb->vdd_cal,  &iv_poundW_data.vdd_cal, (sizeof(((PoundW_t*)0)->vdd_cal)));
        memcpy(&io_globalppb->dds_other, &iv_poundW_data.other, (sizeof(((PoundW_t*)0)->other)));

        //If ATTR_DDS_BIAS_ENABLE = ON, use the ALT_TRIP_OFFSET, ALT_CAL_ADJ,
        //ALT_DELAY values for each core instead of TRIP_OFFSET, CAL_ADJ, DELAY.
        if (iv_attrs.attr_dds_bias_enable)
        {
            for (uint8_t i = 0; i < MAXIMUM_CORES; i++)
            {
                for (uint8_t j = 0; j < NUM_OP_POINTS; j++)
                {
                    io_globalppb->dds[i][j].ddsc.fields.trip_offset = io_globalppb->dds_alt_cal[i][j].alt_cal.fields.alt_trip_offset;
                    io_globalppb->dds[i][j].ddsc.fields.insrtn_dely = io_globalppb->dds_alt_cal[i][j].alt_cal.fields.alt_delay;
                    io_globalppb->dds[i][j].ddsc.fields.calb_adj    = io_globalppb->dds_alt_cal[i][j].alt_cal.fields.alt_cal_adj;
                }
            }

        }

        //Compute dds slopes
        compute_dds_slopes(io_globalppb);

        io_globalppb->dpll_pstate0_value =
            revle32(((iv_attrs.attr_pstate0_freq_mhz) * 1000)  /
                    revle32(io_globalppb->frequency_step_khz));

        FAPI_INF("l_globalppb.dpll_pstate0_value %X (%d)",
                revle32(io_globalppb->dpll_pstate0_value),
                revle32(io_globalppb->dpll_pstate0_value));

        //Set PGPE Flags
        io_globalppb->pgpe_flags[PGPE_FLAG_RESCLK_ENABLE] = iv_resclk_enabled;
        io_globalppb->pgpe_flags[PGPE_FLAG_CURRENT_READ_DISABLE] = iv_attrs.attr_system_current_read_disable;
        io_globalppb->pgpe_flags[PGPE_FLAG_OCS_DISABLE] = !is_ocs_enabled();
        io_globalppb->pgpe_flags[PGPE_FLAG_WOF_ENABLE] = iv_wof_enabled;
        io_globalppb->pgpe_flags[PGPE_FLAG_WOV_UNDERVOLT_ENABLE] = iv_wov_underv_enabled;


        io_globalppb->pgpe_flags[PGPE_FLAG_WOV_OVERVOLT_ENABLE] = iv_wov_overv_enabled;
        io_globalppb->pgpe_flags[PGPE_FLAG_DDS_COARSE_THROTTLE_ENABLE] = iv_attrs.attr_dds_coarse_thr_enable;
        io_globalppb->pgpe_flags[PGPE_FLAG_PMCR_MOST_RECENT_ENABLE] = iv_attrs.attr_pmcr_most_recent_enable;
        io_globalppb->pgpe_flags[PGPE_FLAG_DDS_ENABLE] = iv_dds_enabled;
        io_globalppb->pgpe_flags[PGPE_FLAG_TRIP_MODE] = iv_attrs.attr_dds_trip_mode;
        io_globalppb->pgpe_flags[PGPE_FLAG_TRIP_INTERPOLATION_CONTROL] = iv_attrs.attr_dds_trip_interpolation_control;

        // turn off voltage movement when the WAR MODE defect exists.
        io_globalppb->pgpe_flags[PGPE_FLAG_STATIC_VOLTAGE_ENABLE] =
                            iv_attrs.attr_war_mode == fapi2::ENUM_ATTR_HW543384_WAR_MODE_TIE_NEST_TO_PAU ? 1 : 0;

        if (iv_attrs.attr_pgpe_hcode_function_enable == 0) {
            io_globalppb->pgpe_flags[PGPE_FLAG_OCC_IPC_IMMEDIATE_MODE] = 1;
            io_globalppb->pgpe_flags[PGPE_FLAG_WOF_IPC_IMMEDIATE_MODE] = 1;
        } else {
            io_globalppb->pgpe_flags[PGPE_FLAG_OCC_IPC_IMMEDIATE_MODE] = 0;
            io_globalppb->pgpe_flags[PGPE_FLAG_WOF_IPC_IMMEDIATE_MODE] = 0;
        }
        io_globalppb->pgpe_flags[PGPE_FLAG_PHANTOM_HALT_ENABLE] = iv_attrs.attr_phantom_halt_enable;
        io_globalppb->pgpe_flags[PGPE_FLAG_RVRM_ENABLE] = iv_rvrm_enabled;
        io_globalppb->vcs_vdd_offset_mv= revle16(uint16_t(iv_attrs.attr_vcs_vdd_offset_mv & 0xFF));//Attribute is 1-byte only so truncate it
        io_globalppb->vcs_floor_mv  = revle16(iv_attrs.attr_vcs_floor_mv);

        //WOV parameters
        io_globalppb->wov_sample_125us                = revle32(iv_attrs.attr_wov_sample_125us);
        io_globalppb->wov_max_droop_pct               = revle32(iv_attrs.attr_wov_max_droop_pct);
        io_globalppb->wov_underv_perf_loss_thresh_pct = iv_attrs.attr_wov_underv_perf_loss_thresh_pct;
        io_globalppb->wov_underv_step_incr_pct        = iv_attrs.attr_wov_underv_step_incr_pct;
        io_globalppb->wov_underv_step_decr_pct        = iv_attrs.attr_wov_underv_step_decr_pct;
        io_globalppb->wov_underv_max_pct              = iv_attrs.attr_wov_underv_max_pct;
        io_globalppb->wov_underv_vmin_mv              = revle16(iv_attrs.attr_wov_underv_vmin_mv);
        io_globalppb->wov_overv_vmax_mv               = revle16(iv_attrs.attr_wov_overv_vmax_mv);
        io_globalppb->wov_overv_step_incr_pct         = iv_attrs.attr_wov_overv_step_incr_pct;
        io_globalppb->wov_overv_step_decr_pct         = iv_attrs.attr_wov_overv_step_decr_pct;
        io_globalppb->wov_overv_max_pct               = iv_attrs.attr_wov_overv_max_pct;
        if (io_globalppb->wov_underv_vmin_mv == 0)
        {
            io_globalppb->wov_underv_vmin_mv = revle16(uint16_t(revle32(io_globalppb->safe_voltage_mv[SAFE_VOLTAGE_VDD])));
            FAPI_INF("WOV_VMIN_MV=%u",revle16(io_globalppb->wov_underv_vmin_mv));
            FAPI_INF("SafeVoltage=%u",revle32(io_globalppb->safe_voltage_mv[SAFE_VOLTAGE_VDD]));
        }

    } while (0);

    FAPI_INF("<<<<<<<<<< gppb_init");
    return fapi2::current_err;
}


///////////////////////////////////////////////////////////
////////   oppb_init
///////////////////////////////////////////////////////////
fapi2::ReturnCode PlatPmPPB::oppb_init(
                             OCCPstateParmBlock_t *i_occppb )
{
    FAPI_INF(">>>>>>>> oppb_init");

    do
    {
        fapi2::ATTR_RVRM_VID_Type   l_rvrm_rvid;

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_RVRM_VID,
                               iv_procChip,
                               l_rvrm_rvid));
        // -----------------------------------------------
        // OCC parameter block
        // -----------------------------------------------
        i_occppb->magic.value = revle64(OCC_PARMSBLOCK_MAGIC);

        i_occppb->vdd_sysparm     = iv_vdd_sysparam;
        i_occppb->vcs_sysparm     = iv_vcs_sysparam;
        i_occppb->vdn_sysparm     = iv_vdn_sysparam;

        memcpy(&i_occppb->attr, &iv_attrs, sizeof (Attributes_t));

        //load vpd operating points
        for (uint32_t i = 0; i < NUM_OP_POINTS; i++)
        {
            i_occppb->operating_points[i].frequency_mhz   = revle32(iv_attr_mvpd_poundV_biased[i].frequency_mhz);
            i_occppb->operating_points[i].vdd_mv          = revle32(iv_attr_mvpd_poundV_biased[i].vdd_mv);
            i_occppb->operating_points[i].idd_tdp_ac_10ma = revle32(iv_attr_mvpd_poundV_biased[i].idd_tdp_ac_10ma);
            i_occppb->operating_points[i].idd_tdp_dc_10ma = revle32(iv_attr_mvpd_poundV_biased[i].idd_tdp_dc_10ma);
            i_occppb->operating_points[i].idd_rdp_ac_10ma = revle32(iv_attr_mvpd_poundV_biased[i].idd_rdp_ac_10ma);
            i_occppb->operating_points[i].idd_rdp_dc_10ma = revle32(iv_attr_mvpd_poundV_biased[i].idd_rdp_dc_10ma);
            i_occppb->operating_points[i].vcs_mv          = revle32(iv_attr_mvpd_poundV_biased[i].vcs_mv);
            i_occppb->operating_points[i].ics_tdp_ac_10ma = revle32(iv_attr_mvpd_poundV_biased[i].ics_tdp_ac_10ma);
            i_occppb->operating_points[i].ics_tdp_dc_10ma = revle32(iv_attr_mvpd_poundV_biased[i].ics_tdp_ac_10ma);
            i_occppb->operating_points[i].vdd_vmin        = revle32(iv_attr_mvpd_poundV_biased[i].vdd_vmin);
            i_occppb->operating_points[i].rt_tdp_ac_10ma =
            revle32(iv_attr_mvpd_poundV_biased[i].rt_tdp_ac_10ma);
            i_occppb->operating_points[i].rt_tdp_dc_10ma =
            revle32(iv_attr_mvpd_poundV_biased[i].rt_tdp_dc_10ma);
            i_occppb->operating_points[i].pstate          = iv_attr_mvpd_poundV_biased[i].pstate;
        }


        // frequency_min_khz - Value from Power safe operating point after biases
        Pstate l_ps;

        //Translate safe mode frequency to pstate
        freq2pState((iv_attrs.attr_pm_safe_frequency_mhz * 1000),
                    &l_ps, ROUND_FAST);

        //Compute real frequency
        i_occppb->frequency_min_khz = iv_reference_frequency_khz -
                                     (l_ps * iv_frequency_step_khz);

        i_occppb->frequency_min_khz = revle32(i_occppb->frequency_min_khz);

        // frequency_max_khz - Value from max pstate0
        i_occppb->frequency_max_khz = iv_attrs.attr_pstate0_freq_mhz * 1000;
        i_occppb->frequency_max_khz = revle32(i_occppb->frequency_max_khz);
        FAPI_INF("frequency_max_khz %08x",i_occppb->frequency_max_khz);

        // frequency_ceiling_khz - Maximum operational frquency
        i_occppb->frequency_ceiling_khz = iv_attrs.attr_freq_core_ceiling_mhz * 1000;
        i_occppb->frequency_ceiling_khz = revle32(i_occppb->frequency_ceiling_khz);

        // frequency_step_khz
        i_occppb->frequency_step_khz = revle32(iv_frequency_step_khz);

        if (is_wof_enabled())
        {
            // Iddq Table
            i_occppb->iddq = iv_iddqt;
        }
        else
        {
            iv_wof_enabled = false;
        }

        //Update OCC frequency in OPPB
        i_occppb->occ_complex_frequency_mhz = revle32(iv_occ_freq_mhz);

        // The minimum Pstate must be rounded FAST so that core floor
        // constraints are not violated.
        Pstate pstate_min;
        int rc = freq2pState(revle32(i_occppb->frequency_min_khz),
                             &pstate_min,
                             ROUND_FAST);

        switch (rc)
        {
            case -PSTATE_LT_PSTATE_MIN:
                FAPI_INF("OCC Minimum Frequency was clipped to Pstate 0");
                break;

            case -PSTATE_GT_PSTATE_MAX:
                FAPI_INF("OCC Minimum Frequency %d KHz is outside the range that can be represented"
                         " by a Pstate with a base frequency of %d KHz and step size %d KHz",
                         revle32(i_occppb->frequency_min_khz),
                         (iv_reference_frequency_khz),
                         (iv_frequency_step_khz));
                FAPI_INF("Pstate is set to %X (%d)", pstate_min);
                break;
        }

        i_occppb->pstate_min = pstate_min;
        i_occppb->pstate_min = revle32(i_occppb->pstate_min);
        FAPI_INF("l_occppb.pstate_min 0x%x (%u)", pstate_min, pstate_min);

        //wof_base_frequency_mhz
        i_occppb->tdp_wof_base_frequency_mhz =
            revle32(iv_attr_mvpd_poundV_other_info.tdp_wof_base_freq_mhz);

        //fixed_freq_mode_frequency_mhz
        i_occppb->fixed_freq_mode_frequency_mhz =
            revle32(iv_attr_mvpd_poundV_other_info.fixed_freq_mhz);

        //pstate_max_throttle
        i_occppb->pstate_max_throttle =  revle32(pstate_min + iv_attrs.attr_throttle_pstate_number_limit);

        //VDD voltage (in mV) associated with cores in retention
        i_occppb->vdd_vret_mv =  l_rvrm_rvid << 3;
        i_occppb->vdd_vret_mv = revle32(i_occppb->vdd_vret_mv);

        // Altitude temperature adjustment (in (degrees Celcius/km)*1000)
        i_occppb->altitude_temp_adj_degCpm =  revle32(uint32_t(iv_attrs.attr_system_wof_altitude_temp_adjustment));

        // Altitude base (in meters))
        i_occppb->altitude_reference_m =  revle32(uint32_t(iv_attrs.attr_system_wof_tdp_altitude_reference));

    }while(0);

fapi_try_exit:
    FAPI_INF("<<<<<<<< oppb_init");
    return fapi2::current_err;
}

///////////////////////////////////////////////////////////
////////    oppb_print
///////////////////////////////////////////////////////////
void oppb_print(OCCPstateParmBlock_t* i_oppb)
{
    static const uint32_t   BUFFSIZE = 256;
    char                    l_buffer[BUFFSIZE];
    char                    l_temp_buffer[BUFFSIZE];
    const char*     pv_op_str[NUM_OP_POINTS] = PV_OP_STR;

    // Put out the endian-corrected scalars

    FAPI_INF("---------------------------------------------------------------------------------------");
    FAPI_INF("OCC Pstate Parameter Block");
    FAPI_INF("---------------------------------------------------------------------------------------");

    FAPI_INF("Operating Points:          Freq(MHz)         VDD(mV)       IDTAC(10mA)     IDTDC(10mA)     IDRAC(10mA)     IDRDC(10mA)");
    for (uint32_t i = 0; i < NUM_OP_POINTS; i++)
    {
        strcpy(l_buffer,"");
        sprintf (l_temp_buffer, "  %-18s : ",pv_op_str[i]);
        strcat(l_buffer, l_temp_buffer);

        HEX_DEC_STR(l_buffer,
                revle32(i_oppb->operating_points[i].frequency_mhz));
        HEX_DEC_STR(l_buffer,
                revle32(i_oppb->operating_points[i].vdd_mv));
        HEX_DEC_STR(l_buffer,
                revle32(i_oppb->operating_points[i].idd_tdp_ac_10ma));
        HEX_DEC_STR(l_buffer,
                revle32(i_oppb->operating_points[i].idd_tdp_dc_10ma));
        HEX_DEC_STR(l_buffer,
                revle32(i_oppb->operating_points[i].idd_rdp_ac_10ma));
        HEX_DEC_STR(l_buffer,
                revle32(i_oppb->operating_points[i].idd_rdp_dc_10ma));
        FAPI_INF("%s", l_buffer);
    }

    FAPI_INF("Operating Points:          Freq(MHz)         VCS(mV)       ICTAC(10mA)     ICTDC(10mA)     ICRAC(10mA)     ICRDC(10mA)");
    for (uint32_t i = 0; i < NUM_OP_POINTS; i++)
    {
        strcpy(l_buffer,"");
        sprintf (l_temp_buffer, "  %-18s : ",pv_op_str[i]);
        strcat(l_buffer, l_temp_buffer);

        HEX_DEC_STR(l_buffer,
                revle32(i_oppb->operating_points[i].vcs_mv));
        HEX_DEC_STR(l_buffer,
                revle32(i_oppb->operating_points[i].ics_tdp_ac_10ma));
        HEX_DEC_STR(l_buffer,
                revle32(i_oppb->operating_points[i].ics_tdp_dc_10ma));
        HEX_DEC_STR(l_buffer,
                revle32(i_oppb->operating_points[i].ics_rdp_ac_10ma));
        HEX_DEC_STR(l_buffer,
                revle32(i_oppb->operating_points[i].ics_rdp_dc_10ma));

        FAPI_INF("%s", l_buffer);
    }

    FAPI_INF("Operating Points:          Freq_GB(mHz)    VDD_vmin(mV)  IDD_POW(10mA) CORE_POWR_TEMP(0.5C)");
    for (uint32_t i = 0; i < NUM_OP_POINTS; i++)
    {
        strcpy(l_buffer,"");
        sprintf (l_temp_buffer, "  %-18s : ",pv_op_str[i]);
        strcat(l_buffer, l_temp_buffer);

        HEX_DEC_STR(l_buffer,
                revle32(i_oppb->operating_points[i].vdd_vmin));
        HEX_DEC_STR(l_buffer,
                revle32(i_oppb->operating_points[i].rt_tdp_ac_10ma));
        HEX_DEC_STR(l_buffer,
                revle32(i_oppb->operating_points[i].rt_tdp_dc_10ma));

        FAPI_INF("%s", l_buffer);
    }

    FAPI_INF("System Parameters:                          VDD           VCS           VDN");
    strcpy(l_buffer,"");
    sprintf(l_temp_buffer, "  %-26s :", "Load line (uOhm)");
    strcat(l_buffer, l_temp_buffer);

    sprintf(l_temp_buffer, " %04X (%3d) ",
            revle32(i_oppb->vdd_sysparm.loadline_uohm),
            revle32(i_oppb->vdd_sysparm.loadline_uohm));
    strcat(l_buffer, l_temp_buffer);

    sprintf(l_temp_buffer, " %04X (%3d) ",
            revle32(i_oppb->vcs_sysparm.loadline_uohm),
            revle32(i_oppb->vcs_sysparm.loadline_uohm));
    strcat(l_buffer, l_temp_buffer);

    sprintf(l_temp_buffer, " %04X (%3d) ",
            revle32(i_oppb->vdn_sysparm.loadline_uohm),
            revle32(i_oppb->vdn_sysparm.loadline_uohm));
    strcat(l_buffer, l_temp_buffer);
    FAPI_INF("%s", l_buffer);

    strcpy(l_buffer,"");
    sprintf(l_temp_buffer, "  %-26s :", "Dist Loss (uOhm)");
    strcat(l_buffer, l_temp_buffer);

    sprintf(l_temp_buffer, " %04X (%3d) ",
            revle32(i_oppb->vdd_sysparm.distloss_uohm),
            revle32(i_oppb->vdd_sysparm.distloss_uohm));
    strcat(l_buffer, l_temp_buffer);

    sprintf(l_temp_buffer, " %04X (%3d) ",
            revle32(i_oppb->vcs_sysparm.distloss_uohm),
            revle32(i_oppb->vcs_sysparm.distloss_uohm));
    strcat(l_buffer, l_temp_buffer);

    sprintf(l_temp_buffer, " %04X (%3d) ",
            revle32(i_oppb->vdn_sysparm.distloss_uohm),
            revle32(i_oppb->vdn_sysparm.distloss_uohm));
    strcat(l_buffer, l_temp_buffer);
    FAPI_INF("%s", l_buffer);

    strcpy(l_buffer,"");
    sprintf(l_temp_buffer, "  %-26s :", "Offset (uV)");
    strcat(l_buffer, l_temp_buffer);

    sprintf(l_temp_buffer, " %04X (%3d) ",
            revle32(i_oppb->vdd_sysparm.distoffset_uv),
            revle32(i_oppb->vdd_sysparm.distoffset_uv));
    strcat(l_buffer, l_temp_buffer);

    sprintf(l_temp_buffer, " %04X (%3d) ",
            revle32(i_oppb->vcs_sysparm.distoffset_uv),
            revle32(i_oppb->vcs_sysparm.distoffset_uv));
    strcat(l_buffer, l_temp_buffer);

    sprintf(l_temp_buffer, " %04X (%3d) ",
            revle32(i_oppb->vdn_sysparm.distoffset_uv),
            revle32(i_oppb->vdn_sysparm.distoffset_uv));
    strcat(l_buffer, l_temp_buffer);
    FAPI_INF("%s", l_buffer);

    FAPI_INF("%-28s : 0x%04X (%3d)",
             "Frequency Minumum (kHz)",
             revle32(i_oppb->frequency_min_khz),
             revle32(i_oppb->frequency_min_khz));

    FAPI_INF("%-28s : 0x%04X (%3d)",
             "Frequency Maximum (kHz)",
             revle32(i_oppb->frequency_max_khz),
             revle32(i_oppb->frequency_max_khz));

    FAPI_INF("%-28s : 0x%04X (%3d)",
             "Frequency Ceiling (kHz)",
             revle32(i_oppb->frequency_ceiling_khz),
             revle32(i_oppb->frequency_ceiling_khz));

     FAPI_INF("%-28s : 0x%04X (%3d)",
             "Frequency Step (kHz)",
             revle32(i_oppb->frequency_step_khz),
             revle32(i_oppb->frequency_step_khz));

    FAPI_INF("%-28s : 0x%04X (%3d)",
             "Frequency Minimum (Pstate)",
             revle32(i_oppb->pstate_min),
             revle32(i_oppb->pstate_min));

    FAPI_INF("%-28s : 0x%04X (%3d)",
             "Frequency OCC Complex (MHz)",
             revle32(i_oppb->occ_complex_frequency_mhz),
             revle32(i_oppb->occ_complex_frequency_mhz));

    // Put out the structure to the trace
    iddq_print(&(i_oppb->iddq));

    FAPI_INF("---------------------------------------------------------------------------------------");
}

///////////////////////////////////////////////////////////
////////    wfth_print
///////////////////////////////////////////////////////////
void wfth_print(WofTablesHeader_t* i_wfth)
{
    // Put out the endian-corrected scalars

#define WFTH_PRINT8(_member, _hexwidth, _decwidth) \
FAPI_INF("%-25s = 0x%0*X (%0*d)", #_member, _hexwidth, i_wfth->_member, _decwidth, i_wfth->_member); \

#define WFTH_PRINT16(_member, _hexwidth, _decwidth) \
FAPI_INF("%-25s = 0x%0*X (%0*d)", #_member, _hexwidth, revle16(i_wfth->_member), _decwidth, revle16(i_wfth->_member)); \

#define WFTH_PRINT32(_member, _hexwidth, _decwidth) \
FAPI_INF("%-25s = 0x%0*X (%0*d)", #_member, _hexwidth, revle32(i_wfth->_member), _decwidth, revle32(i_wfth->_member)); \

#define WFTH_PRINTS(_member) \
FAPI_INF("%-25s = %s", #_member, i_wfth->_member);

    FAPI_INF("---------------------------------------------------------------------------------------");
    FAPI_INF("WOF Table Header");
    FAPI_INF("---------------------------------------------------------------------------------------");

    WFTH_PRINTS (magic_number.text);
    WFTH_PRINT8 (header_version,            4, 1);
    WFTH_PRINT8 (vrt_block_size,            4, 5);
    WFTH_PRINT8 (ocs_mode,                  4, 1);
    WFTH_PRINT8 (core_count,                4, 2);
    WFTH_PRINT16(vcs_start,                 4, 5);
    WFTH_PRINT16(vcs_step,                  4, 5);
    WFTH_PRINT16(vcs_size,                  4, 5);
    WFTH_PRINT16(vdd_start,                 4, 5);
    WFTH_PRINT16(vdd_step,                  4, 5);
    WFTH_PRINT16(vdd_size,                  4, 5);
    WFTH_PRINT16(vratio_start,              4, 5);
    WFTH_PRINT16(vratio_step,               4, 5);
    WFTH_PRINT16(vratio_size,               4, 5);
    WFTH_PRINT16(io_start,                  4, 5);
    WFTH_PRINT16(io_step,                   4, 5);
    WFTH_PRINT16(io_size,                   4, 5);
    WFTH_PRINT16(amb_cond_start,            4, 5);
    WFTH_PRINT16(amb_cond_step,             4, 5);
    WFTH_PRINT16(amb_cond_size,             4, 5);
    WFTH_PRINT16(socket_power_w,            4, 5);
    WFTH_PRINT16(sort_power_freq_mhz,       4, 5);
    WFTH_PRINT16(rdp_current_a,             4, 5);
    WFTH_PRINT16(boost_current_a,           4, 5);
    WFTH_PRINT8 (vcs_tdp_ceff_indx,         4, 5);
    WFTH_PRINT8 (vdd_tdp_ceff_indx,         4, 5);
    WFTH_PRINT8 (io_tdp_pwr_indx,           4, 5);
    WFTH_PRINT8 (amb_cond_tdp_indx,         4, 5);
//    WFTH_PRINT8(io_tdp_w,                  4 ,5);
//    WFTH_PRINT8(io_dis_w,                  4 ,5);
    WFTH_PRINT16(sort_ultraturbo_freq_mhz,  4, 5);
    WFTH_PRINT16(table_date_timestamp,     8, 0);
    WFTH_PRINTS(table_version);
    WFTH_PRINTS(package_name);
}

///////////////////////////////////////////////////////////
////////  attr_init
///////////////////////////////////////////////////////////
void PlatPmPPB::attr_init( void )
{
    // Rails:  0-VDD; 1-VCS; 2-VDN; 3-VIO
    const uint32_t EXT_VRM_TRANSITION_START_NS[] = {8000, 8000, 8000, 0};
    const uint32_t EXT_VRM_TRANSITION_RATE_INC_UV_PER_US[] = {10000, 10000, 10000, 0};
    const uint32_t EXT_VRM_TRANSITION_RATE_DEC_UV_PER_US[] = {10000, 10000, 10000, 0};
    const uint32_t EXT_VRM_STABILIZATION_TIME_NS[] = {5, 5, 5, 0};
    const uint32_t EXT_VRM_STEPSIZE_MV[] = {50, 50, 50, 0};

    const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;

    // --------------------------
    // attributes not yet defined
    // --------------------------
    iv_attrs.attr_dpll_bias                 = 0;
    iv_attrs.attr_undervolting              = 0;

    // ---------------------------------------------------------------
    // set ATTR_PROC_DPLL_DIVIDER
    // ---------------------------------------------------------------
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_DPLL_DIVIDER, iv_procChip,
                           iv_attrs.attr_proc_dpll_divider), "fapiGetAttribute of ATTR_PROC_DPLL_DIVIDER failed");

    // If value is 0, set a default
    if (!iv_attrs.attr_proc_dpll_divider)
    {
        iv_attrs.attr_proc_dpll_divider = PROC_PLL_DIVIDER;
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_PROC_DPLL_DIVIDER, iv_procChip,
                               iv_attrs.attr_proc_dpll_divider), "fapiSetAttribute of ATTR_PROC_DPLL_DIVIDER failed");
    }

    FAPI_INF("ATTR_PROC_DPLL_DIVIDER - 0x%x", iv_attrs.attr_proc_dpll_divider);

    // ----------------------------
    // attributes currently defined
    // ----------------------------

#define DATABLOCK_GET_ATTR(attr_name, target, attr_assign) \
FAPI_TRY(FAPI_ATTR_GET(fapi2::attr_name, target, iv_attrs.attr_assign),"Attribute read failed"); \
FAPI_INF("%-54s    = 0x%08x %d", #attr_name, iv_attrs.attr_assign, iv_attrs.attr_assign);

#define DATABLOCK_GET_ATTR_2(attr_name, target, attr_assign) \
FAPI_TRY(FAPI_ATTR_GET(fapi2::attr_name, target, iv_attrs.attr_assign),"Attribute read failed"); \
FAPI_INF("%-54s[0] = 0x%08x %d", #attr_name, iv_attrs.attr_assign[0], iv_attrs.attr_assign[0]);\
FAPI_INF("%-54s[1] = 0x%08x %d", #attr_name, iv_attrs.attr_assign[1], iv_attrs.attr_assign[1]);

#define DATABLOCK_GET_ATTR_4(attr_name, target, attr_assign) \
FAPI_TRY(FAPI_ATTR_GET(fapi2::attr_name, target, iv_attrs.attr_assign),"Attribute read failed"); \
FAPI_INF("%-54s[0] = 0x%08x %d", #attr_name, iv_attrs.attr_assign[0], iv_attrs.attr_assign[0]);\
FAPI_INF("%-54s[1] = 0x%08x %d", #attr_name, iv_attrs.attr_assign[1], iv_attrs.attr_assign[1]);\
FAPI_INF("%-54s[2] = 0x%08x %d", #attr_name, iv_attrs.attr_assign[2], iv_attrs.attr_assign[2]);\
FAPI_INF("%-54s[3] = 0x%08x %d", #attr_name, iv_attrs.attr_assign[3], iv_attrs.attr_assign[3]);

    // Frequency attributes
    DATABLOCK_GET_ATTR(ATTR_SYSTEM_PSTATE0_FREQ_MHZ, FAPI_SYSTEM, attr_pstate0_freq_mhz);
    DATABLOCK_GET_ATTR(ATTR_NOMINAL_FREQ_MHZ, FAPI_SYSTEM, attr_nominal_freq_mhz);

    // Frequency Bias attributes
    DATABLOCK_GET_ATTR(ATTR_FREQ_BIAS, iv_procChip, attr_freq_bias);

    // Voltage Bias attributes
    DATABLOCK_GET_ATTR(ATTR_RVRM_DEADZONE_MV, iv_procChip, attr_rvrm_deadzone_mv);
    DATABLOCK_GET_ATTR(ATTR_VOLTAGE_EXT_BIAS, iv_procChip, attr_voltage_ext_bias);
    DATABLOCK_GET_ATTR(ATTR_VOLTAGE_EXT_VDN_BIAS, iv_procChip, attr_voltage_ext_vdn_bias);
    DATABLOCK_GET_ATTR_4(ATTR_EXTERNAL_VRM_STEPSIZE, iv_procChip, attr_ext_vrm_step_size_mv);
    DATABLOCK_GET_ATTR_4(ATTR_EXTERNAL_VRM_TRANSITION_RATE_DEC_UV_PER_US,
                       iv_procChip, attr_ext_vrm_transition_rate_dec_uv_per_us);
    DATABLOCK_GET_ATTR_4(ATTR_EXTERNAL_VRM_TRANSITION_RATE_INC_UV_PER_US,
                       iv_procChip, attr_ext_vrm_transition_rate_inc_uv_per_us);
    DATABLOCK_GET_ATTR_4(ATTR_EXTERNAL_VRM_TRANSITION_STABILIZATION_TIME_NS,
                       iv_procChip, attr_ext_vrm_stabilization_time_us);
    DATABLOCK_GET_ATTR_4(ATTR_EXTERNAL_VRM_TRANSITION_START_NS,
                       iv_procChip, attr_ext_vrm_transition_start_ns);

    DATABLOCK_GET_ATTR(ATTR_SAFE_MODE_FREQUENCY_MHZ,iv_procChip, attr_pm_safe_frequency_mhz);
    DATABLOCK_GET_ATTR_2(ATTR_SAFE_MODE_VOLTAGE_MV,   iv_procChip, attr_pm_safe_voltage_mv);
    DATABLOCK_GET_ATTR_2(ATTR_SAVE_MODE_NODDS_UPLIFT_MV,   iv_procChip, attr_save_mode_nodds_uplift_mv);

    // AVSBus ... needed by p10_setup_evid
    DATABLOCK_GET_ATTR_4(ATTR_AVSBUS_BUSNUM, iv_procChip, attr_avs_bus_num);
    DATABLOCK_GET_ATTR_4(ATTR_AVSBUS_RAIL,   iv_procChip, attr_avs_bus_rail_select);
    DATABLOCK_GET_ATTR_4(ATTR_BOOT_VOLTAGE, iv_procChip, attr_boot_voltage_mv);
    DATABLOCK_GET_ATTR(ATTR_AVSBUS_FREQUENCY, iv_procChip, attr_avs_bus_freq);
    DATABLOCK_GET_ATTR_4(ATTR_PROC_R_DISTLOSS_UOHM, iv_procChip, attr_proc_r_distloss_uohm);
    DATABLOCK_GET_ATTR_4(ATTR_PROC_R_LOADLINE_UOHM, iv_procChip, attr_proc_r_loadline_uohm);
    DATABLOCK_GET_ATTR_4(ATTR_PROC_VRM_VOFFSET_UV,  iv_procChip, attr_proc_vrm_voffset_uv);
    DATABLOCK_GET_ATTR(ATTR_BOOT_VOLTAGE_BIAS_0P5PCT,  iv_procChip, attr_boot_voltage_biase_0p5pct);

    // Frequency attributes
    DATABLOCK_GET_ATTR(ATTR_FREQ_PAU_MHZ,           FAPI_SYSTEM, attr_pau_frequency_mhz);
    DATABLOCK_GET_ATTR(ATTR_FREQ_CORE_CEILING_MHZ,  iv_procChip, attr_freq_core_ceiling_mhz);
    DATABLOCK_GET_ATTR(ATTR_FREQ_CORE_FLOOR_MHZ,    iv_procChip, attr_freq_core_floor_mhz);
    DATABLOCK_GET_ATTR(ATTR_SYSTEM_FMAX_ENABLE,     FAPI_SYSTEM, attr_fmax_enable);
    DATABLOCK_GET_ATTR(ATTR_HW543384_WAR_MODE,      FAPI_SYSTEM, attr_war_mode);

    // Loadline, Distribution loss and Distribution offset attributes

    // Read IVRM,WOF and DPLL attributes
    DATABLOCK_GET_ATTR(ATTR_SYSTEM_WOF_DISABLE,    FAPI_SYSTEM, attr_system_wof_disable);
    DATABLOCK_GET_ATTR(ATTR_SYSTEM_RVRM_DISABLE,    FAPI_SYSTEM, attr_system_rvrm_disable);
    DATABLOCK_GET_ATTR(ATTR_SYSTEM_DDS_DISABLE,    FAPI_SYSTEM, attr_system_dds_disable);
    DATABLOCK_GET_ATTR(ATTR_SYSTEM_RESCLK_DISABLE, FAPI_SYSTEM, attr_resclk_disable);
    DATABLOCK_GET_ATTR(ATTR_SYSTEM_PSTATES_MODE,   FAPI_SYSTEM, attr_pstate_mode);
    DATABLOCK_GET_ATTR(ATTR_SYSTEM_OCS_DISABLE,         FAPI_SYSTEM, attr_system_ocs_disable);
    DATABLOCK_GET_ATTR(ATTR_SYSTEM_PGPE_CURRENT_READ_DISABLE, FAPI_SYSTEM, attr_system_current_read_disable);

    DATABLOCK_GET_ATTR(ATTR_DDS_BIAS_ENABLE, iv_procChip , attr_dds_bias_enable);
    DATABLOCK_GET_ATTR(ATTR_DDS_COARSE_THROTTLE_ENABLE, iv_procChip , attr_dds_coarse_thr_enable);
    DATABLOCK_GET_ATTR(ATTR_PMCR_MOST_RECENT_MODE,      iv_procChip , attr_pmcr_most_recent_enable);
    DATABLOCK_GET_ATTR(ATTR_PGPE_HCODE_FUNCTION_ENABLE, FAPI_SYSTEM , attr_pgpe_hcode_function_enable);
    DATABLOCK_GET_ATTR(ATTR_PGPE_PHANTOM_HALT_ENABLE,   FAPI_SYSTEM , attr_phantom_halt_enable);
    DATABLOCK_GET_ATTR(ATTR_WOF_THROTTLE_CONTROL_LOOP_DISABLE,    FAPI_SYSTEM, attr_system_wof_throttle_control_loop_disable);
    DATABLOCK_GET_ATTR(ATTR_WOF_PITCH_ENABLE,               FAPI_SYSTEM, attr_system_pitch_enable);
    DATABLOCK_GET_ATTR(ATTR_WOF_THROTTLE_CONTROL_LOOP_MODE, FAPI_SYSTEM, attr_system_wof_throttle_control_loop_mode);
    DATABLOCK_GET_ATTR(ATTR_DDS_TRIP_MODE,    FAPI_SYSTEM, attr_dds_trip_mode);
    DATABLOCK_GET_ATTR(ATTR_DDS_TRIP_INTERPOLATION_CONTROL,    FAPI_SYSTEM, attr_dds_trip_interpolation_control);
    DATABLOCK_GET_ATTR(ATTR_WOF_ALTITUDE_TEMP_ADJUSTMENT, FAPI_SYSTEM, attr_system_wof_altitude_temp_adjustment);
    DATABLOCK_GET_ATTR(ATTR_WOF_TDP_ALTITUDE_REFERENCE_M, FAPI_SYSTEM, attr_system_wof_tdp_altitude_reference);

    //TBD
    //DATABLOCK_GET_ATTR(ATTR_CHIP_EC_FEATURE_WOF_NOT_SUPPORTED, iv_procChip, attr_dd_wof_not_supported);

    DATABLOCK_GET_ATTR(ATTR_FREQ_DPLL_REFCLOCK_KHZ,   FAPI_SYSTEM, freq_proc_refclock_khz);
    DATABLOCK_GET_ATTR(ATTR_PROC_DPLL_DIVIDER,        iv_procChip, proc_dpll_divider);
    DATABLOCK_GET_ATTR(ATTR_SYSTEM_THROTTLE_PSTATE_NUMBER_LIMIT, FAPI_SYSTEM, attr_throttle_pstate_number_limit);
    // AVSBus ... needed by p10_setup_evid
    //Get WOV attributes
    DATABLOCK_GET_ATTR(ATTR_SYSTEM_WOV_OVERV_DISABLE,        FAPI_SYSTEM,attr_wov_overv_disable);
    DATABLOCK_GET_ATTR(ATTR_SYSTEM_WOV_UNDERV_DISABLE,       FAPI_SYSTEM,attr_wov_underv_disable);
    DATABLOCK_GET_ATTR(ATTR_WOV_SAMPLE_125US,               iv_procChip,attr_wov_sample_125us);
    DATABLOCK_GET_ATTR(ATTR_WOV_MAX_DROOP_10THPCT,          iv_procChip,attr_wov_max_droop_pct);
    DATABLOCK_GET_ATTR(ATTR_WOV_UNDERV_PERF_LOSS_THRESH_10THPCT, iv_procChip,attr_wov_underv_perf_loss_thresh_pct);
    DATABLOCK_GET_ATTR(ATTR_WOV_UNDERV_STEP_INCR_10THPCT,   iv_procChip,attr_wov_underv_step_incr_pct);
    DATABLOCK_GET_ATTR(ATTR_WOV_UNDERV_STEP_DECR_10THPCT,   iv_procChip,attr_wov_underv_step_decr_pct);
    DATABLOCK_GET_ATTR(ATTR_WOV_UNDERV_MAX_10THPCT,         iv_procChip,attr_wov_underv_max_pct);
    DATABLOCK_GET_ATTR(ATTR_WOV_UNDERV_VMIN_MV,             iv_procChip,attr_wov_underv_vmin_mv);
    DATABLOCK_GET_ATTR(ATTR_WOV_OVERV_VMAX_SETPOINT_MV,     iv_procChip,attr_wov_overv_vmax_mv);
    DATABLOCK_GET_ATTR(ATTR_WOV_OVERV_STEP_INCR_10THPCT,    iv_procChip,attr_wov_overv_step_incr_pct);
    DATABLOCK_GET_ATTR(ATTR_WOV_OVERV_STEP_DECR_10THPCT,    iv_procChip,attr_wov_overv_step_decr_pct);
    DATABLOCK_GET_ATTR(ATTR_WOV_OVERV_MAX_10THPCT,          iv_procChip,attr_wov_overv_max_pct);

    //VCS attributes
    DATABLOCK_GET_ATTR(ATTR_VCS_FLOOR_MV,                   iv_procChip,attr_vcs_floor_mv);
    DATABLOCK_GET_ATTR(ATTR_VCS_VDD_OFFSET_MV,              iv_procChip,attr_vcs_vdd_offset_mv);


    // Deal with defaults if attributes are not set
#define SET_DEFAULT(_attr_name, _attr_default) \
    if (!(iv_attrs._attr_name)) \
    { \
       iv_attrs._attr_name = _attr_default; \
       FAPI_INF("Setting %-46s    = 0x%08x %d (internal default)", \
                #_attr_name, iv_attrs._attr_name, iv_attrs._attr_name); \
    }

#define SET_DEFAULT_2(_attr_name, _attr_default_0,_attr_default_1) \
    if (!(iv_attrs._attr_name[0] && iv_attrs._attr_name[1])) \
    { \
       iv_attrs._attr_name[0] = _attr_default_0; \
       iv_attrs._attr_name[1] = _attr_default_1; \
       FAPI_INF("Setting %-46s[0] = 0x%08x %d (internal default)", \
                #_attr_name, iv_attrs._attr_name[0], iv_attrs._attr_name[0]); \
       FAPI_INF("Setting %-46s[1] = 0x%08x %d (internal default)", \
                #_attr_name, iv_attrs._attr_name[1], iv_attrs._attr_name[1]); \
    }

#define SET_DEFAULT_4(_attr_name, _attr_default_0,_attr_default_1, _attr_default_2,_attr_default_3) \
    if (!(iv_attrs._attr_name[0] && iv_attrs._attr_name[1] && iv_attrs._attr_name[2] && iv_attrs._attr_name[3])) \
    { \
       iv_attrs._attr_name[0] = _attr_default_0; \
       iv_attrs._attr_name[1] = _attr_default_1; \
       iv_attrs._attr_name[2] = _attr_default_2; \
       iv_attrs._attr_name[3] = _attr_default_3; \
       FAPI_INF("Setting %-46s[0] = 0x%08x %d (internal default)", \
                #_attr_name, iv_attrs._attr_name[0], iv_attrs._attr_name[0]); \
       FAPI_INF("Setting %-46s[1] = 0x%08x %d (internal default)", \
                #_attr_name, iv_attrs._attr_name[1], iv_attrs._attr_name[1]); \
       FAPI_INF("Setting %-46s[2] = 0x%08x %d (internal default)", \
                #_attr_name, iv_attrs._attr_name[2], iv_attrs._attr_name[2]); \
       FAPI_INF("Setting %-46s[3] = 0x%08x %d (internal default)", \
                #_attr_name, iv_attrs._attr_name[3], iv_attrs._attr_name[3]); \
    }



//    SET_DEFAULT(attr_freq_proc_refclock_khz, 133333);
//    SET_DEFAULT(freq_proc_refclock_khz,      133333); // Future: collapse this out
    SET_DEFAULT_4(attr_ext_vrm_transition_start_ns,
        EXT_VRM_TRANSITION_START_NS[0],
        EXT_VRM_TRANSITION_START_NS[1],
        EXT_VRM_TRANSITION_START_NS[2],
        EXT_VRM_TRANSITION_START_NS[3]);
    SET_DEFAULT_4(attr_ext_vrm_transition_rate_inc_uv_per_us,
        EXT_VRM_TRANSITION_RATE_INC_UV_PER_US[0],
        EXT_VRM_TRANSITION_RATE_INC_UV_PER_US[1],
        EXT_VRM_TRANSITION_RATE_INC_UV_PER_US[2],
        EXT_VRM_TRANSITION_RATE_INC_UV_PER_US[3]);
    SET_DEFAULT_4(attr_ext_vrm_transition_rate_dec_uv_per_us,
        EXT_VRM_TRANSITION_RATE_DEC_UV_PER_US[0],
        EXT_VRM_TRANSITION_RATE_DEC_UV_PER_US[1],
        EXT_VRM_TRANSITION_RATE_DEC_UV_PER_US[2],
        EXT_VRM_TRANSITION_RATE_DEC_UV_PER_US[3]);
    SET_DEFAULT_4(attr_ext_vrm_stabilization_time_us,
        EXT_VRM_STABILIZATION_TIME_NS[0],
        EXT_VRM_STABILIZATION_TIME_NS[1],
        EXT_VRM_STABILIZATION_TIME_NS[3],
        EXT_VRM_STABILIZATION_TIME_NS[3]);
    SET_DEFAULT_4(attr_ext_vrm_step_size_mv,
        EXT_VRM_STEPSIZE_MV[0],
        EXT_VRM_STEPSIZE_MV[1],
        EXT_VRM_STEPSIZE_MV[2],
        EXT_VRM_STEPSIZE_MV[3]);

    SET_DEFAULT(attr_wov_sample_125us, 2);
    SET_DEFAULT(attr_wov_max_droop_pct, 125);
    SET_DEFAULT(attr_wov_overv_step_incr_pct, 5);
    SET_DEFAULT(attr_wov_overv_step_decr_pct, 5);
    SET_DEFAULT(attr_wov_overv_max_pct, 0);
    SET_DEFAULT(attr_wov_overv_vmax_mv, 1150);
    SET_DEFAULT(attr_wov_underv_step_incr_pct, 5);
    SET_DEFAULT(attr_wov_underv_step_decr_pct, 5);
    SET_DEFAULT(attr_wov_underv_max_pct, 100);
    SET_DEFAULT(attr_wov_underv_perf_loss_thresh_pct, 5);


    //Ensure that the ranges for WOV attributes are honored
    if (iv_attrs.attr_wov_sample_125us < 2) {
        iv_attrs.attr_wov_sample_125us = 2;
    }

    if(iv_attrs.attr_wov_overv_step_incr_pct > 20) {
        iv_attrs.attr_wov_overv_step_incr_pct = 20;
    }

    if(iv_attrs.attr_wov_overv_step_decr_pct > 20) {
        iv_attrs.attr_wov_overv_step_decr_pct = 20;
    }

    if(iv_attrs.attr_wov_overv_max_pct > 100) {
        iv_attrs.attr_wov_overv_max_pct = 100;
    }

    if(iv_attrs.attr_wov_underv_step_incr_pct > 20) {
        iv_attrs.attr_wov_underv_step_incr_pct = 20;
    }

    if(iv_attrs.attr_wov_underv_step_decr_pct > 20) {
        iv_attrs.attr_wov_underv_step_decr_pct = 20;
    }

    if(iv_attrs.attr_wov_underv_max_pct < 10) {
        iv_attrs.attr_wov_underv_step_decr_pct = 10;
    }

    if (iv_attrs.attr_wov_underv_perf_loss_thresh_pct > 20) {
        iv_attrs.attr_wov_underv_perf_loss_thresh_pct = 20;
    }

    // Deal with critical attributes that are not set and that any defaults chosen
    // could well be very wrong
    FAPI_ASSERT(iv_attrs.attr_pau_frequency_mhz,
                fapi2::PSTATE_PAU_FREQ_EQ_ZERO()
                .set_CHIP_TARGET(iv_procChip),
                "ATTR_FREQ_PAU_MHZ has a zero value");

    // -----------------------------------------------
    // System power distribution parameters
    // -----------------------------------------------
    // VDD rail
    iv_vdd_sysparam.loadline_uohm = revle32(iv_attrs.attr_proc_r_loadline_uohm[0]);
    iv_vdd_sysparam.distloss_uohm = revle32(iv_attrs.attr_proc_r_distloss_uohm[0]);
    iv_vdd_sysparam.distoffset_uv = revle32(iv_attrs.attr_proc_vrm_voffset_uv[0]);

    // VCS rail
    iv_vcs_sysparam.loadline_uohm = revle32(iv_attrs.attr_proc_r_loadline_uohm[1]);
    iv_vcs_sysparam.distloss_uohm = revle32(iv_attrs.attr_proc_r_distloss_uohm[1]);
    iv_vcs_sysparam.distoffset_uv = revle32(iv_attrs.attr_proc_vrm_voffset_uv[1]);

    // VDN rail
    iv_vdn_sysparam.loadline_uohm = revle32(iv_attrs.attr_proc_r_loadline_uohm[2]);
    iv_vdn_sysparam.distloss_uohm = revle32(iv_attrs.attr_proc_r_distloss_uohm[2]);
    iv_vdn_sysparam.distoffset_uv = revle32(iv_attrs.attr_proc_vrm_voffset_uv[2]);

    // VIO rail
    iv_vio_sysparam.loadline_uohm = revle32(iv_attrs.attr_proc_r_loadline_uohm[3]);
    iv_vio_sysparam.distloss_uohm = revle32(iv_attrs.attr_proc_r_distloss_uohm[3]);
    iv_vio_sysparam.distoffset_uv = revle32(iv_attrs.attr_proc_vrm_voffset_uv[3]);

#define SET_ATTR(attr_name, target, attr_assign) \
    FAPI_TRY(FAPI_ATTR_SET(attr_name, target, attr_assign),"Attribute set failed"); \
    FAPI_INF("%-54s    = 0x%08x %d", #attr_name, attr_assign, attr_assign);

    //Set default values
    SET_ATTR(fapi2::ATTR_PSTATES_ENABLED, iv_procChip, iv_pstates_enabled);
    SET_ATTR(fapi2::ATTR_RESCLK_ENABLED,  iv_procChip, iv_resclk_enabled);
    SET_ATTR(fapi2::ATTR_DDS_ENABLED,     iv_procChip, iv_dds_enabled);
    SET_ATTR(fapi2::ATTR_RVRM_ENABLED,    iv_procChip, iv_rvrm_enabled);
    SET_ATTR(fapi2::ATTR_WOF_ENABLED,     iv_procChip, iv_wof_enabled);
    //SET_ATTR(fapi2::ATTR_WOV_UNDERV_ENABLED, iv_procChip, iv_wov_underv_enabled);
    //SET_ATTR(fapi2::ATTR_WOV_OVERV_ENABLED, iv_procChip, iv_wov_overv_enabled);

    iv_pstates_enabled = true;
    iv_resclk_enabled  = true;
    iv_dds_enabled     = true;
    iv_rvrm_enabled    = true;
    iv_wof_enabled     = true;
    iv_ocs_enabled     = true;
    //iv_wov_underv_enabled = true;
    //iv_wov_overv_enabled = true;

    //Calculate nest & frequency_step_khz
    iv_frequency_step_khz = (iv_attrs.attr_freq_proc_refclock_khz /
                             iv_attrs.attr_proc_dpll_divider);

    iv_frequency_step_khz = 16666;
    FAPI_INF ("iv_attrs.attr_freq_proc_refclock_khz %08X iv_attrs.attr_proc_dpll_divider %08x",
         iv_attrs.attr_freq_proc_refclock_khz,iv_attrs.attr_proc_dpll_divider);
    FAPI_INF ("iv_frequency_step_khz %08X %08X", iv_frequency_step_khz, revle32(iv_frequency_step_khz));

    iv_occ_freq_mhz      = iv_attrs.attr_pau_frequency_mhz/4;

    if (iv_attrs.attr_throttle_pstate_number_limit > THROTTLE_PSTATES) {
        iv_attrs.attr_throttle_pstate_number_limit = THROTTLE_PSTATES;
    }


fapi_try_exit:
    if (fapi2::current_err)
    {
        iv_init_error = true;
    }
}

///////////////////////////////////////////////////////////
////////    compute_boot_safe
///////////////////////////////////////////////////////////
fapi2::ReturnCode PlatPmPPB::compute_boot_safe(
                  const VoltageConfigActions_t i_action)
{
    fapi2::ReturnCode l_rc;

    iv_pstates_enabled = true;
    iv_resclk_enabled  = true;
    iv_dds_enabled     = true;
    iv_rvrm_enabled    = true;
    iv_wof_enabled     = false;

    do
    {

        //We only wish to compute voltage setting defaults if the action
        //inputed to the HWP tells us to
        if(i_action == COMPUTE_VOLTAGE_SETTINGS)
        {

            // query VPD if any of the voltage attributes are zero
            // NOTE: P10 does not support VIO via AVSBus so this check is not made
            if (!iv_attrs.attr_boot_voltage_mv[VDD] ||
                !iv_attrs.attr_boot_voltage_mv[VCS] ||
                !iv_attrs.attr_boot_voltage_mv[VDN])
            {
                // ----------------
                // Compute Fmax and update pstate0
                // ----------------
//                l_pmPPB->pm_set_frequency();

                // ----------------
                // get VPD data (#V,#W)
                // ----------------
                FAPI_TRY(vpd_init(),"vpd_init function failed");

                // Compute the VPD operating points
                compute_vpd_pts();

                FAPI_TRY(safe_mode_init());


                if (iv_attrs.attr_boot_voltage_mv[VDN])
                {
                    FAPI_INF("VDN boot voltage override set");
                }
                else if(iv_attrs.attr_avs_bus_num[VDN] == INVALID_BUS_NUM)
                {
                    FAPI_INF("Skipping VDN access as this rail is not configured for AVSBus");
                }
                else
                {
                    FAPI_INF("VDN boot voltage override not set, using VPD value and correcting for applicable load line setting");
                    uint32_t l_int_vdn_mv = (uint32_t)(revle16(iv_poundV_raw_data.static_rails.SRVdnVltg));
                    uint32_t l_idn_ma =(uint32_t)((revle16(iv_poundV_raw_data.static_rails.SRIdnTdpAcCurr) +
                                         revle16(iv_poundV_raw_data.static_rails.SRIdnTdpDcCurr)) * 10);
                    // Returns revle32
                    uint32_t l_ext_vdn_mv = sysparm_uplift(l_int_vdn_mv,
                            l_idn_ma,
                            revle32(iv_vdn_sysparam.loadline_uohm),
                            revle32(iv_vdn_sysparam.distloss_uohm),
                            revle32(iv_vdn_sysparam.distoffset_uv));

                    FAPI_INF("VDN VPD voltage %d mV; Corrected voltage: %d mV; IDN: %d mA; LoadLine: %d uOhm; DistLoss: %d uOhm;  Offst: %d uOhm",
                            l_int_vdn_mv,
                            (l_ext_vdn_mv),
                            l_idn_ma,
                            revle32(iv_vdn_sysparam.loadline_uohm),
                            revle32(iv_vdn_sysparam.distloss_uohm),
                            revle32(iv_vdn_sysparam.distoffset_uv));

                    iv_attrs.attr_boot_voltage_mv[VDN]= (l_ext_vdn_mv);

                    if (iv_attrs.attr_boot_voltage_mv[VDN] >= iv_array_vdn_mv)
                    {
                        iv_attrs.attr_array_write_assist_set = 1;
                    }
                }

                if (iv_attrs.attr_boot_voltage_mv[VIO])
                {
                    FAPI_INF("VIO boot voltage override set");
                }
                else if(iv_attrs.attr_avs_bus_num[VIO] == INVALID_BUS_NUM)
                {
                    FAPI_INF("Skipping VIO VPD access as this rail is not configured for AVSBus");
                }
                else
                {
                    FAPI_INF("VIO boot voltage override not set, using VPD value and correcting for applicable load line setting");
                    uint32_t l_int_vio_mv = (uint32_t)(revle16(iv_poundV_raw_data.static_rails.SRVioVltg));
                    uint32_t l_iio_ma = (uint32_t)((revle16(iv_poundV_raw_data.static_rails.SRIioTdpAcCurr) +
                                         revle16(iv_poundV_raw_data.static_rails.SRIioTdpDcCurr)) * 10);
                    // Returns revle32
                    uint32_t l_ext_vio_mv = sysparm_uplift(l_int_vio_mv,
                            l_iio_ma,
                            revle32(iv_vio_sysparam.loadline_uohm),
                            revle32(iv_vio_sysparam.distloss_uohm),
                            revle32(iv_vio_sysparam.distoffset_uv));

                    FAPI_INF("VIO VPD voltage %d mV; Corrected voltage: %d mV; IDN: %d mA; LoadLine: %d uOhm; DistLoss: %d uOhm;  Offst: %d uOhm",
                            l_int_vio_mv,
                            (l_ext_vio_mv),
                            l_iio_ma,
                            revle32(iv_vio_sysparam.loadline_uohm),
                            revle32(iv_vio_sysparam.distloss_uohm),
                            revle32(iv_vio_sysparam.distoffset_uv));

                    iv_attrs.attr_boot_voltage_mv[VIO]= (l_ext_vio_mv);
                }
            }
            else
            {
#if 0
                FAPI_INF("Using overrides for all boot voltages (VDD/VCS/VDN/VIO) and core frequency");

                // Set safe frequency to the default BOOT_FREQ_MULT
                fapi2::ATTR_BOOT_FREQ_MULT_Type l_boot_freq_mult;
                FAPI_TRY(FAPI_ATTR_GET( fapi2::ATTR_BOOT_FREQ_MULT,
                                        iv_procChip,
                                        l_boot_freq_mult));

                uint32_t l_boot_freq_mhz =
                    ((l_boot_freq_mult * iv_attrs.freq_proc_refclock_khz ) /
                     iv_attrs.proc_dpll_divider )
                    / 1000;



                FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_SAFE_MODE_FREQUENCY_MHZ,
                                       iv_procChip,
                                       l_boot_freq_mhz));
                FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_SAFE_MODE_VOLTAGE_MV,
                                       iv_procChip,
                                       (iv_attrs.vdd_voltage_mv)));
                FAPI_INF("Safe mode Frequency = %d MHz (0x%x), Safe mode voltage = %d mV (0x%x)",
                         l_boot_freq_mhz, l_boot_freq_mhz,
                         (iv_attrs.vdd_voltage_mv), (iv_attrs.vdd_voltage_mv));
#endif
            }

            FAPI_INF("Setting Boot Voltage attributes: VDD = %dmV; VCS = %dmV; VDN = %dmV",
                     iv_attrs.attr_boot_voltage_mv[VDD], iv_attrs.attr_boot_voltage_mv[VCS],
                     iv_attrs.attr_boot_voltage_mv[VDN], iv_attrs.attr_boot_voltage_mv[VIO]);
            FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_BOOT_VOLTAGE, iv_procChip, iv_attrs.attr_boot_voltage_mv),
                     "Error from FAPI_ATTR_SET (ATTR_BOOT_VOLTAGE)");
        }  // COMPUTE_VOLTAGE_SETTINGS
    }
    while(0);

    // trace values to be used
    FAPI_INF("VDD boot voltage = %d mV (0x%x)",
             (iv_attrs.attr_boot_voltage_mv[VDD]), (iv_attrs.attr_boot_voltage_mv[VDD]));
    FAPI_INF("VCS boot voltage = %d mV (0x%x)",
             (iv_attrs.attr_boot_voltage_mv[VCS]), (iv_attrs.attr_boot_voltage_mv[VCS]));
    FAPI_INF("VDN boot voltage = %d mV (0x%x)",
             (iv_attrs.attr_boot_voltage_mv[VDN]), (iv_attrs.attr_boot_voltage_mv[VDN]));
    FAPI_INF("VIO boot voltage = %d mV (0x%x)",
             (iv_attrs.attr_boot_voltage_mv[VIO]), (iv_attrs.attr_boot_voltage_mv[VIO]));

fapi_try_exit:
    return fapi2::current_err;
}

///////////////////////////////////////////////////////////
////////  vpd_init
///////////////////////////////////////////////////////////
fapi2::ReturnCode PlatPmPPB::vpd_init( void )
{
    FAPI_INF(">>>>>>>>>> vpd_init");
    fapi2::ReturnCode l_rc;
    do
    {
        memset (&iv_poundW_data, 0, sizeof(iv_poundW_data));
        memset (&iv_iddqt, 0, sizeof(iv_iddqt));
        memset (iv_operating_points,0,sizeof(iv_operating_points));
        memset (&iv_attr_mvpd_poundV_raw, 0, sizeof(iv_attr_mvpd_poundV_raw));
        memset (&iv_attr_mvpd_poundV_biased, 0, sizeof(iv_attr_mvpd_poundV_biased));

        //Compute fmax, ceil freq
        pm_set_frequency();

        //Read #V data
        FAPI_TRY(get_mvpd_poundV(),
                 "get_mvpd_poundV function failed to retrieve pound V data");

        FAPI_IMP("Creating the stretched VPD structure for Hcode consumption");
        FAPI_TRY(create_stretched_pts(),
                "create_stretched_pts function failed");

        // Apply biased values if any
        FAPI_IMP("Apply Biasing to #V");
        FAPI_TRY(apply_biased_values(),
                "apply_biased_values function failed");

        //Read #AW data
        FAPI_TRY(get_mvpd_poundAW(),
                 "get_mvpd_poundAW function failed to retrieve pound AW data");
        //Read #W data

        // ----------------
        // get VDM Parameters data
        // ----------------
        // Note:  the get_mvpd_poundW has the conditional checking for VDM
        // and WOF enablement as #W has both VDM and WOF content
        l_rc = get_mvpd_poundW();
        if (l_rc)
        {
            FAPI_ASSERT_NOEXIT(false,
                               fapi2::PSTATE_PB_POUND_W_ACCESS_FAIL(fapi2::FAPI2_ERRL_SEV_RECOVERED)
                              .set_CHIP_TARGET(iv_procChip)
                              .set_FAPI_RC(l_rc),
                               "Pstate Parameter Block get_mvpd_poundW function failed");
            fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
        }

        //Read #IQ data

        //if wof is disabled.. don't call IQ function
        if (is_wof_enabled())
        {
            // ----------------
            // get IQ (IDDQ) data
            // ----------------
            FAPI_INF("Getting IQ (IDDQ) Data");
            l_rc = get_mvpd_iddq ();

            if (l_rc)
            {
                FAPI_ASSERT_NOEXIT(false,
                                   fapi2::PSTATE_PB_IQ_ACCESS_ERROR(fapi2::FAPI2_ERRL_SEV_RECOVERED)
                                   .set_CHIP_TARGET(iv_procChip)
                                   .set_FAPI_RC(l_rc),
                                   "Pstate Parameter Block get_mvpd_iddq function failed");
                fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
            }
        }
        else
        {
            FAPI_INF("Skipping IQ (IDDQ) Data as WOF is disabled");
            iv_wof_enabled = false;
        }
#if 0

        FAPI_INF("Load RAW VPD");
        //load_mvpd_operating_point(RAW);

        FAPI_INF("Load VPD");
        // VPD operating point
        //load_mvpd_operating_point(BIASED);
#endif

    }while(0);

    FAPI_INF("<<<<<<<<< vpd_init");

fapi_try_exit:
    return fapi2::current_err;

}

///////////////////////////////////////////////////////////
////////   get_mvpd_poundAW
///////////////////////////////////////////////////////////
fapi2::ReturnCode PlatPmPPB::get_mvpd_poundAW()
{
    FAPI_INF(">>>>>>>>> get_mvpd_poundAW");
    uint8_t* l_fullVpdData = NULL;
    uint32_t l_vpdSize = 0;

    do
    {
        //First read is to get size of vpd record, note the o_buffer is NULL
        FAPI_TRY( getMvpdField(fapi2::MVPD_RECORD_CP00,
                    fapi2::MVPD_KEYWORD_AW,
                    iv_procChip,
                    NULL,
                    l_vpdSize) );


        //save off the actual vpd size
        l_vpdSize = l_vpdSize;
        //Allocate memory for vpd data
        l_fullVpdData = reinterpret_cast<uint8_t*>(malloc(l_vpdSize));


        //Second read is to get data of vpd record
        FAPI_TRY( getMvpdField(fapi2::MVPD_RECORD_CP00,
                    fapi2::MVPD_KEYWORD_AW,
                    iv_procChip,
                    l_fullVpdData,
                    l_vpdSize) );

        //save off the actual vpd size
        l_vpdSize = l_vpdSize;
        //Allocate memory for vpd data
        l_fullVpdData = reinterpret_cast<uint8_t*>(malloc(l_vpdSize));


        //Second read is to get data of vpd record
        FAPI_TRY( getMvpdField(fapi2::MVPD_RECORD_CP00,
                    fapi2::MVPD_KEYWORD_AW,
                    iv_procChip,
                    l_fullVpdData,
                    l_vpdSize) );

        memcpy(&iv_array_vdn_mv,l_fullVpdData,sizeof(iv_array_vdn_mv));
        memcpy(&iv_array_vdd_mv,(l_fullVpdData + 2),sizeof(iv_array_vdd_mv));

    }
    while(0);


fapi_try_exit:
    FAPI_INF("<<<<<<<<< get_mvpd_poundAW");

    return fapi2::current_err;

}

///////////////////////////////////////////////////////////
////////   get_mvpd_poundV
///////////////////////////////////////////////////////////
fapi2::ReturnCode PlatPmPPB::get_mvpd_poundV()
{
    uint8_t    bucket_id        = 0;
    uint8_t*   l_buffer         =
    reinterpret_cast<uint8_t*>(malloc(sizeof(voltageBucketData_t)) );
    uint8_t*   l_buffer_inc     = nullptr;
    char       outstr[50];

    do
    {
        //Read #V data
        FAPI_TRY(p10_pm_get_poundv_bucket(iv_procChip, iv_poundV_raw_data));

        bucket_id = iv_poundV_raw_data.bucketId;
        memset(l_buffer, 0, sizeof(iv_poundV_raw_data));

        // fill chiplet_mvpd_data 2d array with data iN buffer (skip first byte - bucket id)
#define UINT16_GET(__uint8_ptr)   ((uint16_t)( ( (*((const uint8_t *)(__uint8_ptr)) << 8) | *((const uint8_t *)(__uint8_ptr) + 1) ) ))

        uint8_t l_poundv_static_data = 0;
        const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_POUND_V_STATIC_DATA_ENABLE,
                    FAPI_SYSTEM,
                    l_poundv_static_data),
                "Error from FAPI_ATTR_GET for attribute ATTR_POUND_V_STATIC_DATA_ENABLE");

        if (l_poundv_static_data)
        {
            FAPI_INF("attribute ATTR_POUND_V_STATIC_DATA_ENABLE is set");
            memcpy(l_buffer,&g_vpd_PVData,sizeof(g_vpd_PVData));
        }
        else
        {
            FAPI_INF("attribute ATTR_POUND_V_STATIC_DATA_ENABLE is NOT set");
            //memcpy(iv_attr_mvpd_poundV_raw,&iv_poundV_raw_data.nomFreq,sizeof(iv_attr_mvpd_poundV_raw));
            memcpy(l_buffer, &iv_poundV_raw_data, sizeof(iv_poundV_raw_data));
        }



        FAPI_INF("#V bucket id = %u", bucket_id);

        l_buffer_inc = l_buffer;
        l_buffer_inc++;
        for (int i = 0; i < NUM_PV_POINTS; i++)
        {
            //frequency_mhz
            iv_attr_mvpd_poundV_raw[i].frequency_mhz = (uint32_t) UINT16_GET(l_buffer_inc);
            FAPI_INF("#V data = 0x%04X  %-6d", iv_attr_mvpd_poundV_raw[i].frequency_mhz,
                    iv_attr_mvpd_poundV_raw[i].frequency_mhz);
            l_buffer_inc += 2;
            //vdd_mv
            iv_attr_mvpd_poundV_raw[i].vdd_mv= (uint32_t) UINT16_GET(l_buffer_inc);
            FAPI_INF("#V data = 0x%04X  %-6d", iv_attr_mvpd_poundV_raw[i].vdd_mv,
                    iv_attr_mvpd_poundV_raw[i].vdd_mv);
            l_buffer_inc += 2;
            //idd_tdp_ac_10ma
            iv_attr_mvpd_poundV_raw[i].idd_tdp_ac_10ma = (uint32_t) UINT16_GET(l_buffer_inc);
            FAPI_INF("#V data = 0x%04X  %-6d", iv_attr_mvpd_poundV_raw[i].idd_tdp_ac_10ma,
                    iv_attr_mvpd_poundV_raw[i].idd_tdp_ac_10ma);
            l_buffer_inc += 2;
            //idd_tdp_dc_10ma
            iv_attr_mvpd_poundV_raw[i].idd_tdp_dc_10ma = (uint32_t) UINT16_GET(l_buffer_inc);
            FAPI_INF("#V data = 0x%04X  %-6d", iv_attr_mvpd_poundV_raw[i].idd_tdp_dc_10ma,
                    iv_attr_mvpd_poundV_raw[i].idd_tdp_dc_10ma);
            l_buffer_inc += 2;
            //idd_rdp_ac_10ma
            iv_attr_mvpd_poundV_raw[i].idd_rdp_ac_10ma = (uint32_t) UINT16_GET(l_buffer_inc);
            FAPI_INF("#V data = 0x%04X  %-6d", iv_attr_mvpd_poundV_raw[i].idd_rdp_ac_10ma,
                    iv_attr_mvpd_poundV_raw[i].idd_tdp_ac_10ma);
            l_buffer_inc += 2;
            //idd_rdp_dc_10ma
            iv_attr_mvpd_poundV_raw[i].idd_rdp_dc_10ma = (uint32_t) UINT16_GET(l_buffer_inc);
            FAPI_INF("#V data = 0x%04X  %-6d", iv_attr_mvpd_poundV_raw[i].idd_rdp_dc_10ma,
                    iv_attr_mvpd_poundV_raw[i].idd_rdp_dc_10ma);
            l_buffer_inc += 2;
            //vcs_mv
            iv_attr_mvpd_poundV_raw[i].vcs_mv= (uint32_t) UINT16_GET(l_buffer_inc);
            FAPI_INF("#V data = 0x%04X  %-6d", iv_attr_mvpd_poundV_raw[i].vcs_mv,
                    iv_attr_mvpd_poundV_raw[i].vcs_mv);
            l_buffer_inc += 2;
            //ics_tdp_ac_10ma
            iv_attr_mvpd_poundV_raw[i].ics_tdp_ac_10ma = (uint32_t) UINT16_GET(l_buffer_inc);
            FAPI_INF("#V data = 0x%04X  %-6d", iv_attr_mvpd_poundV_raw[i].ics_tdp_ac_10ma,
                    iv_attr_mvpd_poundV_raw[i].ics_tdp_ac_10ma);
            l_buffer_inc += 2;
            //ics_tdp_dc_10ma
            iv_attr_mvpd_poundV_raw[i].ics_tdp_dc_10ma = (uint32_t) UINT16_GET(l_buffer_inc);
            FAPI_INF("#V data = 0x%04X  %-6d", iv_attr_mvpd_poundV_raw[i].ics_tdp_dc_10ma,
                    iv_attr_mvpd_poundV_raw[i].ics_tdp_dc_10ma);
            l_buffer_inc += 2;
            //ics_rdp_ac_10ma
            iv_attr_mvpd_poundV_raw[i].ics_rdp_ac_10ma = (uint32_t) UINT16_GET(l_buffer_inc);
            FAPI_INF("#V data = 0x%04X  %-6d", iv_attr_mvpd_poundV_raw[i].ics_rdp_ac_10ma,
                    iv_attr_mvpd_poundV_raw[i].ics_rdp_ac_10ma);
            l_buffer_inc += 2;
            //ics_rdp_dc_10ma
            iv_attr_mvpd_poundV_raw[i].ics_rdp_dc_10ma = (uint32_t) UINT16_GET(l_buffer_inc);
            FAPI_INF("#V data = 0x%04X  %-6d", iv_attr_mvpd_poundV_raw[i].ics_rdp_dc_10ma,
                    iv_attr_mvpd_poundV_raw[i].ics_rdp_dc_10ma);
            l_buffer_inc += 2;
            //frequency_guardband_sort_mhz
#if 0
            iv_attr_mvpd_poundV_raw[i].frequency_guardband_sort_mhz = (uint32_t) UINT16_GET(l_buffer_inc);
            FAPI_INF("#V data = 0x%04X  %-6d", iv_attr_mvpd_poundV_raw[i].frequency_guardband_sort_mhz,
                    iv_attr_mvpd_poundV_raw[i].frequency_guardband_sort_mhz);
#endif
            l_buffer_inc += 2;
            //vdd_vmin
            iv_attr_mvpd_poundV_raw[i].vdd_vmin = (uint32_t) UINT16_GET(l_buffer_inc);
            FAPI_INF("#V data = 0x%04X  %-6d", iv_attr_mvpd_poundV_raw[i].vdd_vmin,
                    iv_attr_mvpd_poundV_raw[i].vdd_vmin);
            l_buffer_inc += 2;

            //idd_power_pattern_10ma
#if 0
            iv_attr_mvpd_poundV_raw[i].idd_power_pattern_10ma = (uint32_t) UINT16_GET(l_buffer_inc);
            FAPI_INF("#V data = 0x%04X  %-6d", iv_attr_mvpd_poundV_raw[i].idd_power_pattern_10ma,
                    iv_attr_mvpd_poundV_raw[i].idd_power_pattern_10ma);
#endif
            l_buffer_inc += 2;
            //core_power_pattern_temp_0p5C
#if 0
            iv_attr_mvpd_poundV_raw[i].core_power_pattern_temp_0p5C = (uint32_t) *l_buffer_inc;
            FAPI_INF("#V data = 0x%04X  %-6d", iv_attr_mvpd_poundV_raw[i].core_power_pattern_temp_0p5C,
                    iv_attr_mvpd_poundV_raw[i].core_power_pattern_temp_0p5C);
#endif
            l_buffer_inc += 1;

            //rt_tdp_ac_10ma
            iv_attr_mvpd_poundV_raw[i].rt_tdp_ac_10ma = (uint32_t) *l_buffer_inc;
            FAPI_INF("#V data = 0x%04X  %-6d", iv_attr_mvpd_poundV_raw[i].rt_tdp_ac_10ma,
                    iv_attr_mvpd_poundV_raw[i].rt_tdp_ac_10ma);

            l_buffer_inc += 2;

            //rt_tdp_dc_10ma
            iv_attr_mvpd_poundV_raw[i].rt_tdp_dc_10ma = (uint32_t) *l_buffer_inc;
            FAPI_INF("#V data = 0x%04X  %-6d", iv_attr_mvpd_poundV_raw[i].rt_tdp_dc_10ma,
                    iv_attr_mvpd_poundV_raw[i].rt_tdp_dc_10ma);

            // rt_tdp_dc_10ma(wbyte) + spare (2byte)
            l_buffer_inc += 4;
        }

        iv_poundV_bucket_id = bucket_id;
        FAPI_TRY(chk_valid_poundv(false));

        //update_vpd_pts_value();

        uint32_t l_vpd_max_freq = 0;
        uint32_t l_pd_pts = 0;
        if ((iv_attr_mvpd_poundV_raw[CF7].frequency_mhz >
            iv_attr_mvpd_poundV_raw[CF6].frequency_mhz) &&
            iv_attrs.attr_fmax_enable)
        {
            l_vpd_max_freq = iv_attr_mvpd_poundV_raw[CF7].frequency_mhz;
            l_pd_pts = NUM_PV_POINTS;
        }
        else
        {
            iv_attr_mvpd_poundV_raw[CF7].frequency_mhz = 0;
            l_vpd_max_freq = iv_attr_mvpd_poundV_raw[CF6].frequency_mhz;
            l_pd_pts = NUM_PV_POINTS - 1;
        }


        //Update pstate for all points
        for (uint32_t i = 0; i < l_pd_pts; i++)
        {
            iv_attr_mvpd_poundV_raw[i].pstate = (l_vpd_max_freq -
            iv_attr_mvpd_poundV_raw[i].frequency_mhz) * 1000 / (iv_frequency_step_khz);

            iv_vddPsavFreq = (uint32_t)(revle16(iv_poundV_raw_data.other_info.VddPsavCoreFreq));

            iv_vddWofBaseFreq = (uint32_t)(revle16(iv_poundV_raw_data.other_info.VddTdpWofCoreFreq));
            iv_vddUTFreq = (uint32_t)(revle16(iv_poundV_raw_data.other_info.VddUTCoreFreq));
            iv_vddFmaxFreq = (uint32_t)(revle16(iv_poundV_raw_data.other_info.VddFmxCoreFreq));

            FAPI_INF("PSTATE %x %x %d PSAV %x WOF %x UT %x Fmax %x",l_vpd_max_freq,
                     iv_attr_mvpd_poundV_raw[i].frequency_mhz,iv_attr_mvpd_poundV_raw[i].pstate,
                     iv_vddPsavFreq, iv_vddWofBaseFreq,
                      iv_vddUTFreq, iv_vddFmaxFreq);
        }

        // Static Rails

        strcpy(outstr, "vdn_mv");
        iv_attr_mvpd_poundV_static_rails.vdn_mv = (uint32_t) UINT16_GET(l_buffer_inc);
        FAPI_INF("#V data = 0x%04X  %-6d (%s)", iv_attr_mvpd_poundV_static_rails.vdn_mv,
                                                iv_attr_mvpd_poundV_static_rails.vdn_mv,
                                                outstr);
        l_buffer_inc += 2;

        strcpy(outstr, "idn_tdp_ac_10ma");
        iv_attr_mvpd_poundV_static_rails.idn_tdp_ac_10ma = (uint32_t) UINT16_GET(l_buffer_inc);
        FAPI_INF("#V data = 0x%04X  %-6d (%s)", iv_attr_mvpd_poundV_static_rails.idn_tdp_ac_10ma,
                                                iv_attr_mvpd_poundV_static_rails.idn_tdp_ac_10ma,
                                                outstr);
        l_buffer_inc += 2;

        strcpy(outstr, "idn_tdp_dc_10ma");
        iv_attr_mvpd_poundV_static_rails.idn_tdp_dc_10ma = (uint32_t) UINT16_GET(l_buffer_inc);
        FAPI_INF("#V data = 0x%04X  %-6d (%s)", iv_attr_mvpd_poundV_static_rails.idn_tdp_dc_10ma,
                                                iv_attr_mvpd_poundV_static_rails.idn_tdp_dc_10ma,
                                                outstr);
        l_buffer_inc += 2;

        strcpy(outstr, "vio_mv");
        iv_attr_mvpd_poundV_static_rails.vio_mv = (uint32_t) UINT16_GET(l_buffer_inc);
        FAPI_INF("#V data = 0x%04X  %-6d (%s)", iv_attr_mvpd_poundV_static_rails.vio_mv,
                                                iv_attr_mvpd_poundV_static_rails.vio_mv,
                                                outstr);
        l_buffer_inc += 2;

        strcpy(outstr, "iio_tdp_ac_10ma");
        iv_attr_mvpd_poundV_static_rails.iio_tdp_ac_10ma = (uint32_t) UINT16_GET(l_buffer_inc);
        FAPI_INF("#V data = 0x%04X  %-6d (%s)", iv_attr_mvpd_poundV_static_rails.iio_tdp_ac_10ma,
                                                iv_attr_mvpd_poundV_static_rails.iio_tdp_ac_10ma,
                                                outstr);
        l_buffer_inc += 2;

        strcpy(outstr, "iio_tdp_dc_10ma");
        iv_attr_mvpd_poundV_static_rails.iio_tdp_dc_10ma = (uint32_t) UINT16_GET(l_buffer_inc);
        FAPI_INF("#V data = 0x%04X  %-6d (%s)", iv_attr_mvpd_poundV_static_rails.iio_tdp_dc_10ma,
                                                iv_attr_mvpd_poundV_static_rails.iio_tdp_dc_10ma,
                                                outstr);
        l_buffer_inc += 2;

        strcpy(outstr, "vpci_mv");
        iv_attr_mvpd_poundV_static_rails.vpci_mv = (uint32_t) UINT16_GET(l_buffer_inc);
        FAPI_INF("#V data = 0x%04X  %-6d (%s)", iv_attr_mvpd_poundV_static_rails.vpci_mv,
                                                iv_attr_mvpd_poundV_static_rails.vpci_mv,
                                                outstr);
        l_buffer_inc += 2;

        strcpy(outstr, "ipci_tdp_ac_10ma");
        iv_attr_mvpd_poundV_static_rails.ipci_tdp_ac_10ma = (uint32_t) UINT16_GET(l_buffer_inc);
        FAPI_INF("#V data = 0x%04X  %-6d (%s)", iv_attr_mvpd_poundV_static_rails.ipci_tdp_ac_10ma,
                                                iv_attr_mvpd_poundV_static_rails.ipci_tdp_ac_10ma,
                                                outstr);
        l_buffer_inc += 2;

        strcpy(outstr, "ipci_tdp_dc_10ma");
        iv_attr_mvpd_poundV_static_rails.ipci_tdp_dc_10ma = (uint32_t) UINT16_GET(l_buffer_inc);
        FAPI_INF("#V data = 0x%04X  %-6d (%s)", iv_attr_mvpd_poundV_static_rails.ipci_tdp_dc_10ma,
                                                iv_attr_mvpd_poundV_static_rails.ipci_tdp_dc_10ma,
                                                outstr);
        l_buffer_inc += 19;


        // Other Rails

        strcpy(outstr, "pau_frequency_mhz");
        iv_attr_mvpd_poundV_other_info.pau_frequency_mhz = (uint32_t) UINT16_GET(l_buffer_inc);
        FAPI_INF("#V data = 0x%04X  %-6d (%s)", iv_attr_mvpd_poundV_other_info.pau_frequency_mhz,
                                                iv_attr_mvpd_poundV_other_info.pau_frequency_mhz,
                                                outstr);
        l_buffer_inc += 2;

        strcpy(outstr, "total_sort_socket_power_target_W");
        iv_attr_mvpd_poundV_other_info.total_sort_socket_power_target_W = (uint32_t) UINT16_GET(l_buffer_inc);
        FAPI_INF("#V data = 0x%04X  %-6d (%s)", iv_attr_mvpd_poundV_other_info.total_sort_socket_power_target_W,
                                                iv_attr_mvpd_poundV_other_info.total_sort_socket_power_target_W,
                                                outstr);
        l_buffer_inc += 2;

        strcpy(outstr, "vdn_sort_socket_power_alloc_W");
        iv_attr_mvpd_poundV_other_info.vdn_sort_socket_power_alloc_W = (uint32_t) UINT16_GET(l_buffer_inc);
        FAPI_INF("#V data = 0x%04X  %-6d (%s)", iv_attr_mvpd_poundV_other_info.vdn_sort_socket_power_alloc_W,
                                                iv_attr_mvpd_poundV_other_info.vdn_sort_socket_power_alloc_W,
                                                outstr);
        l_buffer_inc += 2;

        strcpy(outstr, "vio_sort_socket_power_alloc_W");
        iv_attr_mvpd_poundV_other_info.vio_sort_socket_power_alloc_W = (uint32_t) UINT16_GET(l_buffer_inc);
        FAPI_INF("#V data = 0x%04X  %-6d (%s)", iv_attr_mvpd_poundV_other_info.vio_sort_socket_power_alloc_W,
                                                iv_attr_mvpd_poundV_other_info.vio_sort_socket_power_alloc_W,
                                                outstr);
        l_buffer_inc += 2;

        strcpy(outstr, "vpci_sort_socket_power_alloc_W");
        iv_attr_mvpd_poundV_other_info.vpci_sort_socket_power_alloc_W = (uint32_t) UINT16_GET(l_buffer_inc);
        FAPI_INF("#V data = 0x%04X  %-6d (%s)", iv_attr_mvpd_poundV_other_info.vpci_sort_socket_power_alloc_W,
                                                iv_attr_mvpd_poundV_other_info.vpci_sort_socket_power_alloc_W,
                                                outstr);
        l_buffer_inc += 2;

        strcpy(outstr, "total_sort_socket_power_actual_0p1W");
        iv_attr_mvpd_poundV_other_info.total_sort_socket_power_actual_0p1W = (uint32_t) UINT16_GET(l_buffer_inc);
        FAPI_INF("#V data = 0x%04X  %-6d (%s)", iv_attr_mvpd_poundV_other_info.total_sort_socket_power_actual_0p1W,
                                                iv_attr_mvpd_poundV_other_info.total_sort_socket_power_actual_0p1W,
                                                outstr);
        l_buffer_inc += 2;

        strcpy(outstr, "idd_rdp_limit_0p1A");
        iv_attr_mvpd_poundV_other_info.idd_rdp_limit_0p1A = (uint32_t) UINT16_GET(l_buffer_inc);
        FAPI_INF("#V data = 0x%04X  %-6d (%s)", iv_attr_mvpd_poundV_other_info.idd_rdp_limit_0p1A,
                                                iv_attr_mvpd_poundV_other_info.idd_rdp_limit_0p1A,
                                                outstr);
        l_buffer_inc += 2;

        strcpy(outstr, "vdd_tdp_wof_index");
        iv_attr_mvpd_poundV_other_info.vdd_tdp_wof_index = (uint32_t) *l_buffer_inc;
        FAPI_INF("#V data = 0x%04X  %-6d (%s)", iv_attr_mvpd_poundV_other_info.vdd_tdp_wof_index,
                                                iv_attr_mvpd_poundV_other_info.vdd_tdp_wof_index,
                                                outstr);
        l_buffer_inc += 1;

        strcpy(outstr, "vcs_tdp_wof_index");
        iv_attr_mvpd_poundV_other_info.vcs_tdp_wof_index = (uint32_t) *l_buffer_inc;
        FAPI_INF("#V data = 0x%04X  %-6d (%s)", iv_attr_mvpd_poundV_other_info.vcs_tdp_wof_index,
                                                iv_attr_mvpd_poundV_other_info.vcs_tdp_wof_index,
                                                outstr);
        l_buffer_inc += 1;

        strcpy(outstr, "vio_tdp_wof_index");
        iv_attr_mvpd_poundV_other_info.vio_tdp_wof_index = (uint32_t) *l_buffer_inc;
        FAPI_INF("#V data = 0x%04X  %-6d (%s)", iv_attr_mvpd_poundV_other_info.vio_tdp_wof_index,
                                                iv_attr_mvpd_poundV_other_info.vio_tdp_wof_index,
                                                outstr);
        l_buffer_inc += 1;

        strcpy(outstr, "amb_cond_tdp_wof_index");
        iv_attr_mvpd_poundV_other_info.amb_cond_tdp_wof_index = (uint32_t) *l_buffer_inc;
        FAPI_INF("#V data = 0x%04X  %-6d (%s)", iv_attr_mvpd_poundV_other_info.amb_cond_tdp_wof_index,
                                                iv_attr_mvpd_poundV_other_info.amb_cond_tdp_wof_index,
                                                outstr);
        l_buffer_inc += 1;

        strcpy(outstr, "mode_interpolation");
        iv_attr_mvpd_poundV_other_info.mode_interpolation = (uint32_t) *l_buffer_inc;
        FAPI_INF("#V data = 0x%04X  %-6d (%s)", iv_attr_mvpd_poundV_other_info.mode_interpolation,
                                                iv_attr_mvpd_poundV_other_info.mode_interpolation,
                                                outstr);
        l_buffer_inc += 1;

        strcpy(outstr, "rdp_sort_power_temp_0p5C");
        iv_attr_mvpd_poundV_other_info.rdp_sort_power_temp_0p5C = (uint32_t) *l_buffer_inc;
        FAPI_INF("#V data = 0x%04X  %-6d (%s)", iv_attr_mvpd_poundV_other_info.rdp_sort_power_temp_0p5C,
                                                iv_attr_mvpd_poundV_other_info.rdp_sort_power_temp_0p5C,
                                                outstr);
        l_buffer_inc += 1;

        strcpy(outstr, "tdp_sort_power_temp_0p5C");
        iv_attr_mvpd_poundV_other_info.tdp_sort_power_temp_0p5C = (uint32_t) *l_buffer_inc;
        FAPI_INF("#V data = 0x%04X  %-6d (%s)", iv_attr_mvpd_poundV_other_info.tdp_sort_power_temp_0p5C,
                                                iv_attr_mvpd_poundV_other_info.tdp_sort_power_temp_0p5C,
                                                outstr);
        l_buffer_inc += 1;

        strcpy(outstr, "tdp_wof_base_freq_mhz");
        iv_attr_mvpd_poundV_other_info.tdp_wof_base_freq_mhz = (uint32_t) UINT16_GET(l_buffer_inc);
        FAPI_INF("#V data = 0x%04X  %-6d (%s)", iv_attr_mvpd_poundV_other_info.tdp_wof_base_freq_mhz,
                                                iv_attr_mvpd_poundV_other_info.tdp_wof_base_freq_mhz,
                                                outstr);
        l_buffer_inc += 2;

        strcpy(outstr, "fixed_freq_mhz");
        iv_attr_mvpd_poundV_other_info.fixed_freq_mhz = (uint32_t) UINT16_GET(l_buffer_inc);
        FAPI_INF("#V data = 0x%04X  %-6d (%s)", iv_attr_mvpd_poundV_other_info.fixed_freq_mhz,
                                                iv_attr_mvpd_poundV_other_info.fixed_freq_mhz,
                                                outstr);
        l_buffer_inc += 2;

        strcpy(outstr, "powersave_freq_mhz");
        iv_attr_mvpd_poundV_other_info.powersave_freq_mhz = (uint32_t) UINT16_GET(l_buffer_inc);
        FAPI_INF("#V data = 0x%04X  %-6d (%s)", iv_attr_mvpd_poundV_other_info.powersave_freq_mhz,
                                                iv_attr_mvpd_poundV_other_info.powersave_freq_mhz,
                                                outstr);
        l_buffer_inc += 2;

        strcpy(outstr, "ultraturbo_freq_mhz");
        iv_attr_mvpd_poundV_other_info.ultraturbo_freq_mhz = (uint32_t) UINT16_GET(l_buffer_inc);
        FAPI_INF("#V data = 0x%04X  %-6d (%s)", iv_attr_mvpd_poundV_other_info.ultraturbo_freq_mhz,
                                                iv_attr_mvpd_poundV_other_info.ultraturbo_freq_mhz,
                                                outstr);
        l_buffer_inc += 2;

        strcpy(outstr, "fmax_freq_mhz");
        iv_attr_mvpd_poundV_other_info.fmax_freq_mhz = (uint32_t) UINT16_GET(l_buffer_inc);
        FAPI_INF("#V data = 0x%04X  %-6d (%s)", iv_attr_mvpd_poundV_other_info.fmax_freq_mhz,
                                                iv_attr_mvpd_poundV_other_info.fmax_freq_mhz,
                                                outstr);
        l_buffer_inc += 2;

        strcpy(outstr, "mma_throttle_temp_0p5C");
        iv_attr_mvpd_poundV_other_info.mma_throttle_temp_0p5C = (uint32_t) *l_buffer_inc;
        FAPI_INF("#V data = 0x%04X  %-6d (%s)", iv_attr_mvpd_poundV_other_info.mma_throttle_temp_0p5C,
                                                iv_attr_mvpd_poundV_other_info.mma_throttle_temp_0p5C,
                                                outstr);
        l_buffer_inc += 1;

        strcpy(outstr, "io_throttle_temp_0p5C");
        iv_attr_mvpd_poundV_other_info.io_throttle_temp_0p5C = (uint32_t) *l_buffer_inc;
        FAPI_INF("#V data = 0x%04X  %-6d (%s)", iv_attr_mvpd_poundV_other_info.io_throttle_temp_0p5C,
                                                iv_attr_mvpd_poundV_other_info.io_throttle_temp_0p5C,
                                                outstr);
        l_buffer_inc += 1;

        strcpy(outstr, "fixed_freq_mode_power_target_0p");
        iv_attr_mvpd_poundV_other_info.fixed_freq_mode_power_target_0p = (uint32_t) UINT16_GET(l_buffer_inc);
        FAPI_INF("#V data = 0x%04X  %-6d (%s)", iv_attr_mvpd_poundV_other_info.fixed_freq_mode_power_target_0p,
                                                iv_attr_mvpd_poundV_other_info.fixed_freq_mode_power_target_0p,
                                                outstr);
        l_buffer_inc += 2;
    }
    while(0);


fapi_try_exit:

    if (fapi2::current_err != fapi2::FAPI2_RC_SUCCESS)
    {
        iv_pstates_enabled = false;
    }
    free (l_buffer);

    return fapi2::current_err;

}

///////////////////////////////////////////////////////////
////////   chk_valid_poundv
///////////////////////////////////////////////////////////
fapi2::ReturnCode PlatPmPPB::chk_valid_poundv(
                      const bool i_biased_state)
{
    const char*     pv_op_str[NUM_PV_POINTS] = VPD_PV_STR;
    uint8_t         i = 0;
    bool            suspend_ut_check = false;
    uint8_t         l_chiplet_num = iv_procChip.getChipletNumber();
    uint8_t attr_poundv_validate_ec_disable = 0;


    //Biased
    if (i_biased_state)
    {
        memcpy (iv_attr_mvpd_data,iv_attr_mvpd_poundV_biased,sizeof(iv_attr_mvpd_data));
    }
    else
    {
        memcpy (iv_attr_mvpd_data,iv_attr_mvpd_poundV_raw,sizeof(iv_attr_mvpd_data));
    }

    FAPI_DBG(">> chk_valid_poundv for %s values", (i_biased_state) ? "biased" : "non-biased" );

    const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;
    fapi2::ATTR_SYSTEM_POUNDV_VALIDITY_HALT_DISABLE_Type      attr_poundv_validity_halt_disable;
//    fapi2::ATTR_CHIP_EC_FEATURE_POUNDV_VALIDATE_DISABLE_Type  attr_poundv_validate_ec_disable;

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_SYSTEM_POUNDV_VALIDITY_HALT_DISABLE,
                FAPI_SYSTEM,
                attr_poundv_validity_halt_disable));

  //  FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_EC_FEATURE_POUNDV_VALIDATE_DISABLE,
    //            iv_procChip,
      //          attr_poundv_validate_ec_disable));

    if (attr_poundv_validate_ec_disable)
    {
        iv_pstates_enabled = false;
        FAPI_INF("**** WARNING : #V zero value checking is not being performed on this chip EC level");
        FAPI_INF("**** WARNING : Pstates are not enabled");
    }
    else
    {
        // check for non-zero freq, voltage, or current in valid operating points
        for (i = 0; i <= NUM_PV_POINTS - 1; i++)
        {
            FAPI_INF("Checking for Zero valued %s data in each #V operating point (%s) " \
                    "f=%u vd=%u idtac=%u idtdc=%u idrac=%u idrdc=%u vc=%u ictac=%u ictdc=%u icrac=%u icrdc=%u vdmin=%u irtrac=%u irtrdc=%u ",
                    (i_biased_state) ? "biased" : "non-biased",
                    pv_op_str[i],
                    iv_attr_mvpd_data[i].frequency_mhz,
                    iv_attr_mvpd_data[i].vdd_mv,
                    iv_attr_mvpd_data[i].idd_tdp_ac_10ma,
                    iv_attr_mvpd_data[i].idd_tdp_dc_10ma,
                    iv_attr_mvpd_data[i].idd_rdp_ac_10ma,
                    iv_attr_mvpd_data[i].idd_rdp_dc_10ma,
                    iv_attr_mvpd_data[i].vcs_mv,
                    iv_attr_mvpd_data[i].ics_tdp_ac_10ma,
                    iv_attr_mvpd_data[i].ics_tdp_dc_10ma,
                    iv_attr_mvpd_data[i].ics_rdp_ac_10ma,
                    iv_attr_mvpd_data[i].ics_rdp_dc_10ma,
                    iv_attr_mvpd_data[i].vdd_vmin,
                    iv_attr_mvpd_data[i].rt_tdp_ac_10ma,
                    iv_attr_mvpd_data[i].rt_tdp_dc_10ma
                    );

            if (is_wof_enabled() &&
                    (strcmp(pv_op_str[i], "CF6") == 0))
            {
                if (POUNDV_POINTS_CHECK(i))
                {
                    if (!strcmp(pv_op_str[i], "CF1") ||
                       (!strcmp(pv_op_str[i], "CF2")) ||
                       (!strcmp(pv_op_str[i], "CF4")) ||
                       (!strcmp(pv_op_str[i], "CF5")) ||
                       (!strcmp(pv_op_str[i], "CF7") ))
                    {
                        if (!strcmp(pv_op_str[i], "CF7"))
                        {
                            iv_poundV_fmax_enable = false;
                        }
                        else
                        {
                            iv_optional_pdv_pts_value_zero = true;
                        }
                        FAPI_INF("Skip logging error for this operating point %s",pv_op_str[i]);
                        continue;
                    }
                    //if we have hit here then,main poundV point itself is
                    //invalid so no need to update the optional points
                    iv_optional_pdv_pts_value_zero  = false;

                    FAPI_INF("**** WARNING: WOF is enabled but zero valued data found in #V (chiplet = %u  bucket id = %u  op point = %s)",
                            l_chiplet_num, iv_poundV_bucket_id, pv_op_str[i]);
                    FAPI_INF("**** WARNING: Disabling WOF and continuing");
                    suspend_ut_check = true;

                    // Set ATTR_WOF_ENABLED so the caller can set header flags
                    iv_wof_enabled = false;

                    // Take out an informational error log and then keep going.
                    if (i_biased_state)
                    {
                        FAPI_ASSERT_NOEXIT(false,
                                fapi2::PSTATE_PB_BIASED_POUNDV_WOF_CF6_ERROR(fapi2::FAPI2_ERRL_SEV_RECOVERED)
                                .set_CHIP_TARGET(iv_procChip)
                                .set_CHIPLET_NUMBER(l_chiplet_num)
                                .set_BUCKET(iv_poundV_bucket_id)
                                POUNDV_POINTS_PRINT(i,A),
                                "Pstate Parameter Block WOF Biased #V CF6 error being logged");
                    }
                    else
                    {
                        FAPI_ASSERT_NOEXIT(false,
                                fapi2::PSTATE_PB_POUNDV_WOF_CF6_ERROR(fapi2::FAPI2_ERRL_SEV_RECOVERED)
                                .set_CHIP_TARGET(iv_procChip)
                                .set_CHIPLET_NUMBER(l_chiplet_num)
                                .set_BUCKET(iv_poundV_bucket_id)
                                POUNDV_POINTS_PRINT(i,A),
                                "Pstate Parameter Block WOF #V CF6 error being logged");
                    }
                    fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
                }
            }
            else if ((!is_wof_enabled()) && (strcmp(pv_op_str[i], "CF6") == 0))
            {
                FAPI_INF("**** NOTE: WOF is disabled so the UltraTurbo VPD is not being checked");
                suspend_ut_check = true;
            }
            else
            {
                if (POUNDV_POINTS_CHECK(i))
                {
                    if (!strcmp(pv_op_str[i], "CF1") ||
                       (!strcmp(pv_op_str[i], "CF2")) ||
                       (!strcmp(pv_op_str[i], "CF4")) ||
                       (!strcmp(pv_op_str[i], "CF5")) ||
                       (!strcmp(pv_op_str[i], "CF7") ))
                    {
                        if (!strcmp(pv_op_str[i], "CF7"))
                        {
                            iv_poundV_fmax_enable = false;
                        }
                        else
                        {
                            iv_optional_pdv_pts_value_zero = true;
                        }
                        FAPI_INF("Skip logging error for this operating point %s",pv_op_str[i]);
                        continue;
                    }
                    //if we have hit here then,main poundV point itself is
                    //invalid so no need to update the optional points
                    iv_optional_pdv_pts_value_zero  = false;
                    iv_pstates_enabled = false;

                    if (attr_poundv_validity_halt_disable)
                    {
                        FAPI_IMP("**** WARNING : halt on #V validity checking has been disabled and errors were found");
                        FAPI_IMP("**** WARNING : Zero valued data found in #V (chiplet = %u  bucket id = %u  op point = %s)",
                                l_chiplet_num, iv_poundV_bucket_id, pv_op_str[i]);
                        FAPI_IMP("**** WARNING : Pstates are not enabled but continuing on.");

                        // Log errors based on biased inputs or not
                        if (i_biased_state)
                        {
                            FAPI_ASSERT_NOEXIT(false,
                                    fapi2::PSTATE_PB_BIASED_POUNDV_ZERO_ERROR(fapi2::FAPI2_ERRL_SEV_RECOVERED)
                                    .set_CHIP_TARGET(iv_procChip)
                                    .set_CHIPLET_NUMBER(l_chiplet_num)
                                    .set_BUCKET(iv_poundV_bucket_id)
                                    .set_POINT(i)
                                    POUNDV_POINTS_PRINT(i,A),
                                    "Pstate Parameter Block Biased #V Zero contents error being logged");
                        }
                        else
                        {
                            FAPI_ASSERT_NOEXIT(false,
                                    fapi2::PSTATE_PB_POUNDV_ZERO_ERROR(fapi2::FAPI2_ERRL_SEV_RECOVERED)
                                    .set_CHIP_TARGET(iv_procChip)
                                    .set_CHIPLET_NUMBER(l_chiplet_num)
                                    .set_BUCKET(iv_poundV_bucket_id)
                                    .set_POINT(i)
                                    POUNDV_POINTS_PRINT(i,A),
                                    "Pstate Parameter Block #V Zero contents error being logged");
                        }
                        fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
                    }
                    else
                    {
                        FAPI_ERR("**** ERROR : Zero valued data found in #V (chiplet = %u  bucket id = %u  op point = %s)",
                                l_chiplet_num, iv_poundV_bucket_id, pv_op_str[i]);

                        // Error out has Pstate and all dependent functions are suspious.
                        if (i_biased_state)
                        {
                            FAPI_ASSERT(false,
                                    fapi2::PSTATE_PB_BIASED_POUNDV_ZERO_ERROR()
                                    .set_CHIP_TARGET(iv_procChip)
                                    .set_CHIPLET_NUMBER(l_chiplet_num)
                                    .set_BUCKET(iv_poundV_bucket_id)
                                    .set_POINT(i)
                                    POUNDV_POINTS_PRINT(i,A),
                                    "Pstate Parameter Block Biased #V Zero contents error being logged");
                        }
                        else
                        {
                            FAPI_ASSERT(false,
                                    fapi2::PSTATE_PB_POUNDV_ZERO_ERROR()
                                    .set_CHIP_TARGET(iv_procChip)
                                    .set_CHIPLET_NUMBER(l_chiplet_num)
                                    .set_BUCKET(iv_poundV_bucket_id)
                                    .set_POINT(i)
                                    POUNDV_POINTS_PRINT(i,A),
                                    "Pstate Parameter Block #V Zero contents error being logged");
                        }
                    }  // Halt disable
                }  // #V point zero check
            }  // WOF and CF6 conditions
        } // Operating poing loop
    } // validate #V EC

    // Adjust the valid operating point based on UltraTurbo presence
    // and WOF enablement
    iv_valid_pdv_points = NUM_PV_POINTS;

    if (suspend_ut_check)
    {
        iv_valid_pdv_points--;
    }

    FAPI_DBG("iv_valid_pdv_points = %d", iv_valid_pdv_points);

    if (attr_poundv_validate_ec_disable)
    {
        iv_pstates_enabled = false;
        FAPI_INF("**** WARNING : #V relationship checking is not being performed on this chip EC level");
        FAPI_INF("**** WARNING : Pstates are not enabled");
    }
    else
    {
        // check valid operating points' values have this relationship (power save <= nominal <= turbo <= ultraturbo)
        for (i = 1; i <= (iv_valid_pdv_points) - 1; i++)
        {
            FAPI_INF("Checking for relationship between #V operating point (%s <= %s)",
                    pv_op_str[i - 1], pv_op_str[i]);

            // Only skip checkinug for WOF not enabled and UltraTurbo.
            if ( is_wof_enabled()    ||
               (!( !is_wof_enabled() &&
               (strcmp(pv_op_str[i], "CF6") == 0))))
            {
                if (!strcmp(pv_op_str[i], "CF1") ||
                    (!strcmp(pv_op_str[i], "CF2")) ||
                    (!strcmp(pv_op_str[i], "CF4")) ||
                    (!strcmp(pv_op_str[i], "CF5")) ||
                    (!strcmp(pv_op_str[i], "CF7") ))
                {
                    FAPI_INF("Skip logging error for this operating point %s",pv_op_str[i]);
                    continue;
                }
                if ((iv_attr_mvpd_data[i - 1].frequency_mhz >
                     iv_attr_mvpd_data[i].frequency_mhz) ||
                    (iv_attr_mvpd_data[i - 1].vdd_mv >
                     iv_attr_mvpd_data[i].vdd_mv) ||
                    (iv_attr_mvpd_data[i - 1].idd_tdp_ac_10ma >
                     iv_attr_mvpd_data[i].idd_tdp_ac_10ma) ||
                    (iv_attr_mvpd_data[i - 1].idd_tdp_dc_10ma >
                    iv_attr_mvpd_data[i].idd_tdp_dc_10ma) ||
                    (iv_attr_mvpd_data[i - 1].idd_rdp_ac_10ma >
                    iv_attr_mvpd_data[i].idd_rdp_ac_10ma) ||
                    (iv_attr_mvpd_data[i  -1].idd_rdp_dc_10ma >
                    iv_attr_mvpd_data[i].idd_rdp_dc_10ma) ||
                    (iv_attr_mvpd_data[i - 1].vcs_mv >
                    iv_attr_mvpd_data[i].vcs_mv) ||
                    (iv_attr_mvpd_data[i - 1].ics_tdp_ac_10ma >
                    iv_attr_mvpd_data[i].ics_tdp_ac_10ma) ||
                    (iv_attr_mvpd_data[i - 1].ics_tdp_dc_10ma >
                    iv_attr_mvpd_data[i].ics_tdp_dc_10ma) ||
                    (iv_attr_mvpd_data[i - 1].ics_rdp_ac_10ma >
                    iv_attr_mvpd_data[i].ics_rdp_ac_10ma) ||
                    (iv_attr_mvpd_data[i - 1].ics_rdp_dc_10ma >
                    iv_attr_mvpd_data[i].ics_rdp_dc_10ma) ||
                    (iv_attr_mvpd_data[i - 1].vdd_vmin >
                    iv_attr_mvpd_data[i].vdd_vmin) ||
                    (iv_attr_mvpd_data[i - 1].rt_tdp_ac_10ma >
                    iv_attr_mvpd_data[i].rt_tdp_ac_10ma) ||
                    (iv_attr_mvpd_data[i - 1].rt_tdp_ac_10ma >
                    iv_attr_mvpd_data[i].rt_tdp_ac_10ma))

                {
                    iv_pstates_enabled = false;

                    if (attr_poundv_validity_halt_disable)
                    {
                        FAPI_IMP("**** WARNING : halt on #V validity checking has been "
                                "disabled and relationship errors were found");
                        FAPI_IMP("**** WARNING : Relationship error between #V operating point "
                                "(%s > %s)(power save <= nominal <= turbo <= ultraturbo) (chiplet = %u  bucket id = %u  op point = %u)",
                                pv_op_str[i - 1], pv_op_str[i], l_chiplet_num, iv_poundV_bucket_id, i);
                        FAPI_IMP("**** WARNING : Pstates are not enabled but continuing on.");
                    }
                    else
                    {
                        FAPI_ERR("**** ERROR : Relation../../xml/attribute_info/pm_plat_attributes.xmlship "
                                "error between #V operating point (%s > %s)(power save <= nominal <= turbo "
                                "<= ultraturbo) (chiplet = %u  bucket id = %u  op point = %u)",
                                pv_op_str[i - 1], pv_op_str[i], l_chiplet_num, iv_poundV_bucket_id,i);
                    }

                    FAPI_INF("%s Frequency value %u is %s %s Frequency value %u",
                            pv_op_str[i - 1], iv_attr_mvpd_data[i - 1].frequency_mhz,
                            POUNDV_SLOPE_CHECK(iv_attr_mvpd_data[i - 1].frequency_mhz,
                                iv_attr_mvpd_data[i].frequency_mhz),pv_op_str[i], iv_attr_mvpd_data[i].frequency_mhz);
                    FAPI_INF("%s VDD voltage value %u is %s %s VDD voltage value %u",
                            pv_op_str[i - 1], iv_attr_mvpd_data[i - 1].vdd_mv,
                            POUNDV_SLOPE_CHECK(iv_attr_mvpd_data[i - 1].vdd_mv,
                                iv_attr_mvpd_data[i].vdd_mv),pv_op_str[i], iv_attr_mvpd_data[i].vdd_mv);
                    FAPI_INF("%s IDD tdp ac value %u is %s %s IDD tdp ac value %u",
                            pv_op_str[i - 1], iv_attr_mvpd_data[i - 1].idd_tdp_ac_10ma,
                            POUNDV_SLOPE_CHECK(iv_attr_mvpd_data[i - 1].idd_tdp_ac_10ma,
                                iv_attr_mvpd_data[i].idd_tdp_ac_10ma),pv_op_str[i], iv_attr_mvpd_data[i].idd_tdp_ac_10ma);
                    FAPI_INF("%s IDD tdp dc value %u is %s %s IDD tdp dc value %u",
                            pv_op_str[i - 1], iv_attr_mvpd_data[i - 1].idd_tdp_dc_10ma,
                            POUNDV_SLOPE_CHECK(iv_attr_mvpd_data[i - 1].idd_tdp_dc_10ma,
                                iv_attr_mvpd_data[i].idd_tdp_dc_10ma),pv_op_str[i], iv_attr_mvpd_data[i].idd_tdp_dc_10ma);
                    FAPI_INF("%s IDD rdp ac value %u is %s %s IDD rdp ac value %u",
                            pv_op_str[i - 1], iv_attr_mvpd_data[i - 1].idd_rdp_ac_10ma,
                            POUNDV_SLOPE_CHECK(iv_attr_mvpd_data[i - 1].idd_rdp_ac_10ma,
                                iv_attr_mvpd_data[i].idd_rdp_ac_10ma),pv_op_str[i], iv_attr_mvpd_data[i].idd_rdp_ac_10ma);
                    FAPI_INF("%s IDD rdp dc value %u is %s %s IDD rdp dc value %u",
                            pv_op_str[i - 1], iv_attr_mvpd_data[i - 1].idd_rdp_dc_10ma,
                            POUNDV_SLOPE_CHECK(iv_attr_mvpd_data[i - 1].idd_rdp_dc_10ma,
                                iv_attr_mvpd_data[i].idd_rdp_dc_10ma),pv_op_str[i], iv_attr_mvpd_data[i].idd_rdp_dc_10ma);
                    FAPI_INF("%s VCS voltage value %u is %s %s VCS voltage value %u",
                            pv_op_str[i - 1], iv_attr_mvpd_data[i - 1].vcs_mv,
                            POUNDV_SLOPE_CHECK(iv_attr_mvpd_data[i - 1].vcs_mv,
                                iv_attr_mvpd_data[i].vcs_mv),pv_op_str[i], iv_attr_mvpd_data[i].vcs_mv);
                    FAPI_INF("%s ICS tdp ac value %u is %s %s ICS tdp ac value %u",
                            pv_op_str[i - 1], iv_attr_mvpd_data[i - 1].ics_tdp_ac_10ma,
                            POUNDV_SLOPE_CHECK(iv_attr_mvpd_data[i - 1].ics_tdp_ac_10ma,
                                iv_attr_mvpd_data[i].ics_tdp_ac_10ma),pv_op_str[i], iv_attr_mvpd_data[i].ics_tdp_ac_10ma);
                    FAPI_INF("%s ICS tdp dc value %u is %s %s ICS tdp dc value %u",
                            pv_op_str[i - 1], iv_attr_mvpd_data[i - 1].ics_tdp_dc_10ma,
                            POUNDV_SLOPE_CHECK(iv_attr_mvpd_data[i - 1].ics_tdp_dc_10ma,
                                iv_attr_mvpd_data[i].ics_tdp_dc_10ma),pv_op_str[i], iv_attr_mvpd_data[i].ics_tdp_dc_10ma);
                    FAPI_INF("%s ICS rdp ac value %u is %s %s ICS rdp ac value %u",
                            pv_op_str[i - 1], iv_attr_mvpd_data[i - 1].ics_rdp_ac_10ma,
                            POUNDV_SLOPE_CHECK(iv_attr_mvpd_data[i - 1].ics_rdp_ac_10ma,
                                iv_attr_mvpd_data[i].ics_rdp_ac_10ma),pv_op_str[i], iv_attr_mvpd_data[i].ics_rdp_ac_10ma);
                    FAPI_INF("%s ICS rdp dc value %u is %s %s ICS rdp dc value %u",
                            pv_op_str[i - 1], iv_attr_mvpd_data[i - 1].ics_rdp_dc_10ma,
                            POUNDV_SLOPE_CHECK(iv_attr_mvpd_data[i - 1].ics_rdp_dc_10ma,
                                iv_attr_mvpd_data[i].ics_rdp_dc_10ma),pv_op_str[i], iv_attr_mvpd_data[i].ics_rdp_dc_10ma);

                    FAPI_INF("%s VDD vmin voltage value %u is %s %s VDD vmin voltage value %u",
                            pv_op_str[i - 1], iv_attr_mvpd_data[i - 1].vdd_vmin,
                            POUNDV_SLOPE_CHECK(iv_attr_mvpd_data[i - 1].vdd_vmin,
                                iv_attr_mvpd_data[i].vdd_vmin),pv_op_str[i], iv_attr_mvpd_data[i].vdd_vmin);
                    FAPI_INF("%s TDP RT AC value %u is %s %s TDP RT AC value %u",
                            pv_op_str[i - 1], iv_attr_mvpd_data[i - 1].rt_tdp_ac_10ma,
                            POUNDV_SLOPE_CHECK(iv_attr_mvpd_data[i - 1].rt_tdp_ac_10ma,
                                iv_attr_mvpd_data[i].rt_tdp_ac_10ma),pv_op_str[i], iv_attr_mvpd_data[i].rt_tdp_ac_10ma);
                    FAPI_INF("%s TDP RT DC value %u is %s %s TDP RT DC value %u",
                            pv_op_str[i - 1], iv_attr_mvpd_data[i - 1].rt_tdp_dc_10ma,
                            POUNDV_SLOPE_CHECK(iv_attr_mvpd_data[i - 1].rt_tdp_dc_10ma,
                                iv_attr_mvpd_data[i].rt_tdp_dc_10ma),pv_op_str[i], iv_attr_mvpd_data[i].rt_tdp_dc_10ma);
                    if (i_biased_state)
                    {
                        if (attr_poundv_validity_halt_disable)
                        {
                            // Log the error only.
                            FAPI_ASSERT_NOEXIT(false,
                                    fapi2::PSTATE_PB_BIASED_POUNDV_SLOPE_ERROR(fapi2::FAPI2_ERRL_SEV_RECOVERED)
                                    .set_CHIP_TARGET(iv_procChip)
                                    .set_CHIPLET_NUMBER(l_chiplet_num)
                                    .set_BUCKET(iv_poundV_bucket_id)
                                    .set_POINT(i)
                                    POUNDV_POINTS_PRINT(i-1,A)
                                    POUNDV_POINTS_PRINT(i,B),
                                    "Pstate Parameter Block Biased #V disorder contents error being logged");

                            fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;

                        }
                        else
                        {
                            // Error out has Pstate and all dependent functions are suspicious.
                            FAPI_ASSERT(false,
                                    fapi2::PSTATE_PB_BIASED_POUNDV_SLOPE_ERROR()
                                    .set_CHIP_TARGET(iv_procChip)
                                    .set_CHIPLET_NUMBER(l_chiplet_num)
                                    .set_BUCKET(iv_poundV_bucket_id)
                                    .set_POINT(i)
                                    POUNDV_POINTS_PRINT(i-1,A)
                                    POUNDV_POINTS_PRINT(i,B),
                                    "Pstate Parameter Block Biased #V disorder contents error being logged");
                        }
                    }
                    else
                    {
                        if (attr_poundv_validity_halt_disable)
                        {
                            // Log the error only.
                            FAPI_ASSERT_NOEXIT(false,
                                    fapi2::PSTATE_PB_POUNDV_SLOPE_ERROR(fapi2::FAPI2_ERRL_SEV_RECOVERED)
                                    .set_CHIP_TARGET(iv_procChip)
                                    .set_CHIPLET_NUMBER(l_chiplet_num)
                                    .set_BUCKET(iv_poundV_bucket_id)
                                    .set_POINT(i)
                                    POUNDV_POINTS_PRINT(i-1,A)
                                    POUNDV_POINTS_PRINT(i,B),

                                    "Pstate Parameter Block #V disorder contents error being logged");

                            fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
                        }
                        else
                        {
                            // Error out has Pstate and all dependent functions are suspicious.
                            FAPI_ASSERT(false,
                                    fapi2::PSTATE_PB_POUNDV_SLOPE_ERROR()
                                    .set_CHIP_TARGET(iv_procChip)
                                    .set_CHIPLET_NUMBER(l_chiplet_num)
                                    .set_BUCKET(iv_poundV_bucket_id)
                                    .set_POINT(i)
                                    POUNDV_POINTS_PRINT(i-1,A)
                                    POUNDV_POINTS_PRINT(i,B),
                                    "Pstate Parameter Block #V disorder contents error being logged");
                        }
                    }
                }  // validity failed
            }  // Skip CF6 check
        } // point loop
    }  // validity disabled

fapi_try_exit:

    FAPI_DBG("<< chk_valid_poundv");
    return fapi2::current_err;
}
void PlatPmPPB::update_vpd_pts_value()
{
    uint8_t i = 0;
    uint8_t l_ps_cf3_idx = 0;
    uint8_t l_cf3_ut_idx = 0;
    const char*     pv_op_str[NUM_PV_POINTS] = VPD_PV_STR;
    //PSAV 0, CF1 1, CF2 2, CF3 3, CF4 4, CF5 5,CF6 6
    for (i = 0; i < NUM_PV_POINTS - 1; ++i)
    {
        if (iv_optional_pdv_pts_value_zero)
        {
            if ((strcmp(pv_op_str[i], "CF1") == 0) ||
                    (strcmp(pv_op_str[i], "CF4") == 0))
            {
                l_ps_cf3_idx = i - 1;
                l_cf3_ut_idx = i + 2;
            }
            else if (((strcmp(pv_op_str[i], "CF2") == 0) ||
                        (strcmp(pv_op_str[i], "CF5") == 0)))
            {
                l_ps_cf3_idx = i - 2;
                l_cf3_ut_idx = i + 1;
            }
            else
            {
                continue;
            }
                POUNDV_POINT_CALC (iv_attr_mvpd_poundV_raw[i].frequency_mhz,
                        iv_attr_mvpd_poundV_raw[l_ps_cf3_idx].frequency_mhz,
                        iv_attr_mvpd_poundV_raw[l_cf3_ut_idx].frequency_mhz,
                        CF1_3_PERCENTAGE);
                POUNDV_POINT_CALC (iv_attr_mvpd_poundV_raw[i].vdd_mv,
                        iv_attr_mvpd_poundV_raw[l_ps_cf3_idx].vdd_mv,
                        iv_attr_mvpd_poundV_raw[l_cf3_ut_idx].vdd_mv,
                        CF1_3_PERCENTAGE);
                POUNDV_POINT_CALC (iv_attr_mvpd_poundV_raw[i].idd_tdp_ac_10ma,
                        iv_attr_mvpd_poundV_raw[l_ps_cf3_idx].idd_tdp_ac_10ma,
                        iv_attr_mvpd_poundV_raw[l_cf3_ut_idx].idd_tdp_ac_10ma,
                        CF1_3_PERCENTAGE);
                POUNDV_POINT_CALC (iv_attr_mvpd_poundV_raw[i].idd_tdp_dc_10ma,
                        iv_attr_mvpd_poundV_raw[l_ps_cf3_idx].idd_tdp_dc_10ma,
                        iv_attr_mvpd_poundV_raw[l_cf3_ut_idx].idd_tdp_dc_10ma,
                        CF1_3_PERCENTAGE);
                POUNDV_POINT_CALC (iv_attr_mvpd_poundV_raw[i].idd_rdp_ac_10ma,
                        iv_attr_mvpd_poundV_raw[l_ps_cf3_idx].idd_rdp_ac_10ma,
                        iv_attr_mvpd_poundV_raw[l_cf3_ut_idx].idd_rdp_ac_10ma,
                        CF1_3_PERCENTAGE);
                POUNDV_POINT_CALC (iv_attr_mvpd_poundV_raw[i].idd_rdp_dc_10ma,
                        iv_attr_mvpd_poundV_raw[l_ps_cf3_idx].idd_rdp_dc_10ma,
                        iv_attr_mvpd_poundV_raw[l_cf3_ut_idx].idd_rdp_dc_10ma,
                        CF1_3_PERCENTAGE);
                POUNDV_POINT_CALC (iv_attr_mvpd_poundV_raw[i].vcs_mv,
                        iv_attr_mvpd_poundV_raw[l_ps_cf3_idx].vcs_mv,
                        iv_attr_mvpd_poundV_raw[l_cf3_ut_idx].vcs_mv,
                        CF1_3_PERCENTAGE);
                POUNDV_POINT_CALC (iv_attr_mvpd_poundV_raw[i].ics_tdp_ac_10ma,
                        iv_attr_mvpd_poundV_raw[l_ps_cf3_idx].ics_tdp_ac_10ma,
                        iv_attr_mvpd_poundV_raw[l_cf3_ut_idx].ics_tdp_ac_10ma,
                        CF1_3_PERCENTAGE);
                POUNDV_POINT_CALC (iv_attr_mvpd_poundV_raw[i].ics_tdp_dc_10ma,
                        iv_attr_mvpd_poundV_raw[l_ps_cf3_idx].ics_tdp_dc_10ma,
                        iv_attr_mvpd_poundV_raw[l_cf3_ut_idx].ics_tdp_dc_10ma,
                        CF1_3_PERCENTAGE);

                POUNDV_POINT_CALC (iv_attr_mvpd_poundV_raw[i].ics_rdp_ac_10ma,
                        iv_attr_mvpd_poundV_raw[l_ps_cf3_idx].ics_rdp_ac_10ma,
                        iv_attr_mvpd_poundV_raw[l_cf3_ut_idx].ics_rdp_ac_10ma,
                        CF1_3_PERCENTAGE);
                POUNDV_POINT_CALC (iv_attr_mvpd_poundV_raw[i].ics_rdp_dc_10ma,
                        iv_attr_mvpd_poundV_raw[l_ps_cf3_idx].ics_rdp_dc_10ma,
                        iv_attr_mvpd_poundV_raw[l_cf3_ut_idx].ics_rdp_dc_10ma,
                        CF1_3_PERCENTAGE);

                POUNDV_POINT_CALC (iv_attr_mvpd_poundV_raw[i].vdd_vmin,
                        iv_attr_mvpd_poundV_raw[l_ps_cf3_idx].vdd_vmin,
                        iv_attr_mvpd_poundV_raw[l_cf3_ut_idx].vdd_vmin,
                        CF1_3_PERCENTAGE);

                POUNDV_POINT_CALC (iv_attr_mvpd_poundV_raw[i].rt_tdp_ac_10ma,
                        iv_attr_mvpd_poundV_raw[l_ps_cf3_idx].rt_tdp_ac_10ma,
                        iv_attr_mvpd_poundV_raw[l_cf3_ut_idx].rt_tdp_ac_10ma,
                        CF1_3_PERCENTAGE);

                POUNDV_POINT_CALC (iv_attr_mvpd_poundV_raw[i].rt_tdp_dc_10ma,
                        iv_attr_mvpd_poundV_raw[l_ps_cf3_idx].rt_tdp_dc_10ma,
                        iv_attr_mvpd_poundV_raw[l_cf3_ut_idx].rt_tdp_dc_10ma,
                        CF1_3_PERCENTAGE);

        } //end of if
    }//end of for
}
///////////////////////////////////////////////////////////
////////   is_dds_enabled
///////////////////////////////////////////////////////////
bool PlatPmPPB::is_dds_enabled()
{
    const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;
//    uint8_t attr_dd_ddsc_not_supported;
    fapi2::ATTR_SYSTEM_DDS_DISABLE_Type attr_system_dds_disable = false;

    FAPI_ATTR_GET(fapi2::ATTR_SYSTEM_DDS_DISABLE, FAPI_SYSTEM, attr_system_dds_disable);
//    FAPI_ATTR_GET(fapi2::ATTR_CHIP_EC_FEATURE_DDSC_NOT_SUPPORTED, iv_procChip, attr_dd_ddsc_not_supported);

    return
        (!(attr_system_dds_disable) &&
 //        !(attr_dd_vdm_not_supported) &&
         iv_dds_enabled)
         ? true : false;
} // end of is_dds_enabled

///////////////////////////////////////////////////////////
////////  is_wof_enabled
///////////////////////////////////////////////////////////
bool PlatPmPPB::is_wof_enabled()
{
//    uint8_t attr_dd_wof_not_supported;
    uint8_t attr_system_wof_disable = false;
    const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;
    FAPI_ATTR_GET(fapi2::ATTR_SYSTEM_WOF_DISABLE, FAPI_SYSTEM, attr_system_wof_disable);
//    FAPI_ATTR_GET(fapi2::ATTR_CHIP_EC_FEATURE_WOF_NOT_SUPPORTED, iv_procChip, attr_dd_wof_not_supported);

    return
        (!(attr_system_wof_disable) &&
 //        !(attr_dd_wof_not_supported) &&
         iv_wof_enabled)
        ? true : false;
} //end of is_wof_enabled

///////////////////////////////////////////////////////////
////////  is_rvrm_enabled
///////////////////////////////////////////////////////////
bool PlatPmPPB::is_rvrm_enabled()
{
    uint8_t attr_system_rvrm_disable = false;
    const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;
    FAPI_ATTR_GET(fapi2::ATTR_SYSTEM_RVRM_DISABLE, FAPI_SYSTEM, attr_system_rvrm_disable);

    return
        (!(attr_system_rvrm_disable) &&
         iv_rvrm_enabled)
        ? true : false;
} //end of is_rvrm_enabled

///////////////////////////////////////////////////////////
////////  is_ocs_enabled
///////////////////////////////////////////////////////////
bool PlatPmPPB::is_ocs_enabled()
{
    fapi2::ATTR_SYSTEM_OCS_DISABLE_Type attr_system_ocs_disable = false;
    const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;
    FAPI_ATTR_GET(fapi2::ATTR_SYSTEM_OCS_DISABLE, FAPI_SYSTEM, attr_system_ocs_disable);

    return
        (!(attr_system_ocs_disable) &&
         iv_ocs_enabled)
        ? true : false;
} //end of is_ocs_enabled

///////////////////////////////////////////////////////////
////////   apply_biased_values
///////////////////////////////////////////////////////////
fapi2::ReturnCode PlatPmPPB::apply_biased_values ()
{
    FAPI_INF(">>>>>>>>>>>>> apply_biased_values");
    const char*     pv_op_str[NUM_PV_POINTS] = VPD_PV_STR;

    do
    {
        // ---------------------------------------------
        // process external and internal bias attributes
        // ---------------------------------------------
        FAPI_IMP("Apply Biasing to #V");

        // Copy to Bias array
        memcpy(iv_attr_mvpd_poundV_biased,iv_attr_mvpd_poundV_raw,sizeof(iv_attr_mvpd_poundV_raw));

        for (int i = 0; i <= NUM_PV_POINTS - 1; i++)
        {
            FAPI_DBG("BIASED #V operating point (%s) f=%u v=%u i=%u v=%u i=%u",
                    pv_op_str[i],
                    iv_attr_mvpd_poundV_biased[i].frequency_mhz,
                    iv_attr_mvpd_poundV_biased[i].vdd_mv,
                    iv_attr_mvpd_poundV_biased[i].idd_tdp_dc_10ma,
                    iv_attr_mvpd_poundV_biased[i].vcs_mv,
                    iv_attr_mvpd_poundV_biased[i].ics_tdp_dc_10ma);
        }

        FAPI_TRY(apply_extint_bias(),
                 "Bias application function failed");

        //Validating Bias values
        FAPI_INF("Validate Biasd Voltage and Frequency values");

        FAPI_TRY(chk_valid_poundv(BIASED));

        //Update pstate for all points
        for (int i = 0; i < NUM_PV_POINTS; i++)
        {
            //TBD
            if (i == VPD_PV_CF7)
                continue;

            // TODO RTC: 211812
            iv_attr_mvpd_poundV_biased[i].pstate = (iv_attr_mvpd_poundV_biased[CF6].frequency_mhz -
            iv_attr_mvpd_poundV_biased[i].frequency_mhz) * 1000 / (iv_frequency_step_khz);

            FAPI_INF("PSTATE %x %x %d",iv_attr_mvpd_poundV_biased[CF6].frequency_mhz,
                     iv_attr_mvpd_poundV_biased[i].frequency_mhz,iv_attr_mvpd_poundV_biased[i].pstate);
        }


        FAPI_DBG("Pstate Base Frequency - after bias %X (%d)",
                 iv_attr_mvpd_poundV_biased[VPD_PV_CF6].frequency_mhz * 1000,
                 iv_attr_mvpd_poundV_biased[VPD_PV_CF6].frequency_mhz * 1000);
    }while(0);

fapi_try_exit:
    FAPI_INF("<<<<<<<<<<<< apply_biased_values");
    return fapi2::current_err;

}


///////////////////////////////////////////////////////////
////////   apply_extint_bias
///////////////////////////////////////////////////////////
fapi2::ReturnCode PlatPmPPB::apply_extint_bias( )
{
    double freq_bias[NUM_PV_POINTS];
    double voltage_ext_vdd_bias[NUM_PV_POINTS];
    double voltage_ext_vcs_bias[NUM_PV_POINTS];
  //  double voltage_ext_vdn_bias;
    uint8_t VDD = 0;
    uint8_t VCS = 1;
   // uint8_t VDN = 2;
  //  uint8_t VIO = 3;

    // Calculate the frequency multiplers and load the biases into the exported
    // structure
    for (auto p = 0; p < NUM_PV_POINTS; p++)
    {
        iv_bias.frequency_0p5pct  = iv_attrs.attr_freq_bias;
        iv_bias.vdd_ext_0p5pct[p] = iv_attrs.attr_voltage_ext_bias[VDD][p];
        iv_bias.vcs_ext_0p5pct[p] = iv_attrs.attr_voltage_ext_bias[VCS][p];


        freq_bias[p]              = calc_bias(iv_bias.frequency_0p5pct);
        voltage_ext_vdd_bias[p]   = calc_bias(iv_bias.vdd_ext_0p5pct[p]);
        voltage_ext_vcs_bias[p]   = calc_bias(iv_bias.vcs_ext_0p5pct[p]);

        FAPI_DBG("    Biases[%d](bias): Freq=%f (%f%%); VDD=%f (%f%%) VCS=%f (%f%%)",
                p,
                freq_bias[p],            iv_bias.frequency_0p5pct/2,
                voltage_ext_vdd_bias[p], iv_bias.vdd_ext_0p5pct[p]/2,
                voltage_ext_vcs_bias[p], iv_bias.vcs_ext_0p5pct[p]/2);
    }


    // VDN bias applied to all operating points
//    voltage_ext_vdn_bias = calc_bias(iv_attrs.attr_voltage_ext_vdn_bias);

    // Change the VPD frequency, VDD and VCS values with the bias multiplers
    for (auto p = 0; p < NUM_PV_POINTS; p++)
    {
        FAPI_DBG("    Orig values[%d](bias): Freq=%d (%f); VDD=%d (%f), VCS=%d (%f)",
                    p,
                    iv_attr_mvpd_poundV_biased[p].frequency_mhz, freq_bias[p],
                    iv_attr_mvpd_poundV_biased[p].vdd_mv, voltage_ext_vdd_bias[p],
                    iv_attr_mvpd_poundV_biased[p].vcs_mv, voltage_ext_vcs_bias[p]);

        double freq_mhz =
            (( (double)iv_attr_mvpd_poundV_biased[p].frequency_mhz) * freq_bias[p]);
        double vdd_mv =
            (( (double)iv_attr_mvpd_poundV_biased[p].vdd_mv) * voltage_ext_vdd_bias[p]);
        double vcs_mv =
            (( (double)iv_attr_mvpd_poundV_biased[p].vcs_mv) * voltage_ext_vcs_bias[p]);

        iv_attr_mvpd_poundV_biased[p].frequency_mhz = (uint16_t)internal_floor(freq_mhz);
        iv_attr_mvpd_poundV_biased[p].vdd_mv        = (uint16_t)internal_ceil(vdd_mv);
        iv_attr_mvpd_poundV_biased[p].vcs_mv        = (uint16_t)internal_ceil(vcs_mv);

        FAPI_DBG("    Biased values[%d]: Freq=%f %d; VDD=%f %d, VCS=%f %d ",
                    p,
                    freq_mhz, iv_attr_mvpd_poundV_biased[p].frequency_mhz,
                    vdd_mv, iv_attr_mvpd_poundV_biased[p].vdd_mv,
                    vcs_mv, iv_attr_mvpd_poundV_biased[p].vcs_mv);
    }

    //TBD for VDN and VIO computation

    return fapi2::FAPI2_RC_SUCCESS;
}

///////////////////////////////////////////////////////////
////////  get_mvpd_poundW
///////////////////////////////////////////////////////////
fapi2::ReturnCode PlatPmPPB::get_mvpd_poundW (void)
{
    fapi2::ddscData_t *l_ddscBuf = new fapi2::ddscData_t;
    uint8_t    bucket_id        = 0;
    uint8_t    version_id       = 0;

    FAPI_DBG(">> get_mvpd_poundW");

    do
    {
        FAPI_DBG("get_mvpd_poundW: VDM enable = %d, WOF enable %d",
                is_dds_enabled(), is_wof_enabled());

        // Exit if both DDS and WOF is disabled
        if ((!is_dds_enabled() && !is_wof_enabled()))
        {
            FAPI_INF("   get_mvpd_poundW: BOTH VDM and WOF are disabled.  Skipping remaining checks");
            iv_dds_enabled = false;
            iv_wof_enabled = false;
            iv_wov_underv_enabled = false;
            iv_wov_overv_enabled = false;
            break;
        }

        // clear out buffer to known value before calling fapiGetMvpdField
        memset(l_ddscBuf, 0, sizeof(fapi2::ddscData_t));

        FAPI_TRY(p10_pm_get_poundw_bucket(iv_procChip, l_ddscBuf));

        bucket_id = l_ddscBuf->bucketId;
        version_id = l_ddscBuf->version;

        FAPI_INF("#W bucket_id  = %u version_id = %u", bucket_id, version_id);


        uint8_t l_poundw_static_data = 0;
        const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_POUND_W_STATIC_DATA_ENABLE,
                    FAPI_SYSTEM,
                    l_poundw_static_data),
                "Error from FAPI_ATTR_GET for attribute ATTR_POUND_W_STATIC_DATA_ENABLE");

        if (l_poundw_static_data)
        {
            FAPI_INF("attribute ATTR_POUND_W_STATIC_DATA_ENABLE is set");
            // copy the data to the pound w structure from a hardcoded table
            //            memcpy (&iv_poundW_data, &g_vpdData, sizeof (g_vpdData));
        }
        else
        {
            FAPI_INF("attribute ATTR_POUND_W_STATIC_DATA_ENABLE is NOT set");
            // copy the data to the pound w structure from the actual VPD image
            memcpy (&iv_poundW_data, l_ddscBuf->ddscData, sizeof (l_ddscBuf->ddscData));
        }

        // validate vid values
        bool l_frequency_value_state = 1;
        VALIDATE_FREQUENCY_DROP_VALUES(iv_poundW_data.other.dpll_settings.fields.N_S_drop_3p125pct,
                iv_poundW_data.other.dpll_settings.fields.N_L_drop_3p125pct,
                iv_poundW_data.other.dpll_settings.fields.L_S_return_3p125pct,
                iv_poundW_data.other.dpll_settings.fields.S_N_return_3p125pct,
                l_frequency_value_state);


        if (!l_frequency_value_state)
        {
            iv_dds_enabled = false;
            break;
        }

        //If we have reached this point, that means DDS is ok to be enabled. Only then we try to
        //enable wov undervolting
        if  (((iv_attrs.attr_wov_underv_force == 1))  &&
                is_wov_underv_enabled() == 1) {
            iv_wov_underv_enabled = true;
            FAPI_INF("UNDERV_TESTED or UNDERV_FORCE set to 1");
        } else{
            iv_wov_underv_enabled = false;
            FAPI_INF("UNDERV_TESTED and UNDERV_FORCE set to 0");
        }
    }
    while(0);

fapi_try_exit:
    delete l_ddscBuf;
    return fapi2::FAPI2_RC_SUCCESS;
}

///////////////////////////////////////////////////////////
////////  is_wov_underv_enabled
///////////////////////////////////////////////////////////
bool PlatPmPPB::is_wov_underv_enabled()
{
    return(!(iv_attrs.attr_wov_underv_disable) &&
         iv_wov_underv_enabled)
         ? true : false;
}

///--------------------------------------
///////////////////////////////////////////////////////////
//////// is_wov_overv_enabled
///////////////////////////////////////////////////////////
bool PlatPmPPB::is_wov_overv_enabled()
{
    return (!(iv_attrs.attr_wov_overv_disable) &&
         iv_wov_overv_enabled)
         ? true : false;
}

///////////////////////////////////////////////////////////
////////  get_mvpd_iddq
///////////////////////////////////////////////////////////
fapi2::ReturnCode PlatPmPPB::get_mvpd_iddq( void )
{

    uint8_t*        l_buffer_iq_c =  nullptr;
    uint32_t        l_record = 0;
    uint32_t        l_bufferSize_iq  = IQ_BUFFER_ALLOC;
    fapi2::ATTR_SYSTEM_IQ_VALIDATION_MODE_Type l_iq_mode = 0;


    // --------------------------------------------
    // Process IQ Keyword (IDDQ) Data
    // --------------------------------------------

    const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_SYSTEM_IQ_VALIDATION_MODE, FAPI_SYSTEM, l_iq_mode));
    // set l_record to appropriate cprx record
    l_record = (uint32_t)fapi2::MVPD_RECORD_CRP0;

    //First read is to get size of vpd record, note the o_buffer is nullptr
    FAPI_TRY( getMvpdField((fapi2::MvpdRecord)l_record,
                fapi2::MVPD_KEYWORD_IQ,
                iv_procChip,
                nullptr,
                l_bufferSize_iq) );

    //Allocate memory for vpd data
    l_buffer_iq_c = reinterpret_cast<uint8_t*>(malloc(l_bufferSize_iq));

    // Get Chip IQ MVPD data from the CRPx records
    FAPI_TRY(getMvpdField((fapi2::MvpdRecord)l_record,
                fapi2::MVPD_KEYWORD_IQ,
                iv_procChip,
                l_buffer_iq_c,
                l_bufferSize_iq));

    //skip keyword version and
    //copy VPD data to IQ structure table
    memcpy(&iv_iddqt, (l_buffer_iq_c+1), l_bufferSize_iq);

    //Verify Payload header data.
    if ( !(iv_iddqt.iddq_version) ||
            !(iv_iddqt.good_normal_cores_per_sort))
    {
        if (l_iq_mode == fapi2::ENUM_ATTR_SYSTEM_IQ_VALIDATION_MODE_INFO)
        {
            FAPI_INF("Pstate Parameter Block IQ Payload data error being logged");
        }
        else
        {


            //iv_wof_enabled = false;//TBD for now commented for wof testing purpose
            //because IQ data was not valid
            FAPI_ASSERT_NOEXIT(false,
                    fapi2::PSTATE_PB_IQ_VPD_ERROR(fapi2::FAPI2_ERRL_SEV_RECOVERED)
                    .set_CHIP_TARGET(iv_procChip)
                    .set_VERSION(iv_iddqt.iddq_version)
                    .set_GOOD_NORMAL_CORES_PER_SORT(iv_iddqt.good_normal_cores_per_sort),
                    "Pstate Parameter Block IQ Payload data error being logged");
            fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
        }
    }

    //Verify ivdd_all_cores_off_caches_off has MSB bit is set
    //if yes then initialized to 0
    for (int i = 0; i < IDDQ_MEASUREMENTS; ++i)
    {
        if ( iv_iddqt.iddq_all_good_cores_off_good_caches_off_5ma[i] & 0x8000)
        {
            iv_iddqt.iddq_all_good_cores_off_good_caches_off_5ma[i] = 0;
        }
    }
    for (int i = 0; i < IDDQ_MEASUREMENTS; ++i)
    {
        iv_iddqt.iddq_all_good_cores_on_caches_on_5ma[i] =
            revle16(iv_iddqt.iddq_all_good_cores_on_caches_on_5ma[i]);
        iv_iddqt.iddq_all_good_cores_off_good_caches_off_5ma[i] =
            revle16(iv_iddqt.iddq_all_good_cores_off_good_caches_off_5ma[i]);
        iv_iddqt.iddq_all_good_cores_off_good_caches_on_5ma[i] =
            revle16(iv_iddqt.iddq_all_good_cores_off_good_caches_on_5ma[i]);
        iv_iddqt.icsq_all_good_cores_on_caches_on_5ma[i] =
            revle16(iv_iddqt.icsq_all_good_cores_on_caches_on_5ma[i]);
        iv_iddqt.icsq_all_good_cores_off_good_caches_off_5ma[i] =
            revle16(iv_iddqt.icsq_all_good_cores_off_good_caches_off_5ma[i]);
        iv_iddqt.icsq_all_good_cores_off_good_caches_on_5ma[i] =
            revle16(iv_iddqt.icsq_all_good_cores_off_good_caches_on_5ma[i]);
    }

    for (int x = 0; x < MAXIMUM_EQ_SETS; ++x)
    {
        for (int i = 0; i < IDDQ_MEASUREMENTS; ++i)
        {
            iv_iddqt.iddq_eqs_good_cores_on_good_caches_on_5ma[x][i] =
                revle16(iv_iddqt.iddq_eqs_good_cores_on_good_caches_on_5ma[x][i]);
            iv_iddqt.icsq_eqs_good_cores_on_good_caches_on_5ma[x][i] =
                revle16(iv_iddqt.icsq_eqs_good_cores_on_good_caches_on_5ma[x][i]);
        }
    }
    // Put out the structure to the trace
    iddq_print(&iv_iddqt);

fapi_try_exit:

    // Free up memory buffer
    free(l_buffer_iq_c);

    if (fapi2::current_err != fapi2::FAPI2_RC_SUCCESS)
    {
        iv_wof_enabled = false;
    }

    return fapi2::current_err;
}

///////////////////////////////////////////////////////////
//////// iddq_print
///////////////////////////////////////////////////////////
void iddq_print(IddqTable_t* i_iddqt)
{
    uint32_t        i, j;
    const char*     idd_meas_str[IDDQ_MEASUREMENTS] = IDDQ_ARRAY_VOLTAGES_STR;
    char            l_buffer_str[1024];   // Temporary formatting string buffer
    char            l_line_str[1024];     // Formatted output line string

    static const uint32_t IDDQ_DESC_SIZE = 50;
    static const uint32_t IDDQ_QUAD_SIZE = IDDQ_DESC_SIZE -
                                            strlen("Quad X:");

    FAPI_INF("IDDQ");

    // Put out the endian-corrected scalars

    // get IQ version and advance pointer 1-byte
    FAPI_INF("  IDDQ Version Number = %u", i_iddqt->iddq_version);
    FAPI_INF("  Sort Info:");
    FAPI_INF("    %-24s : %02d", "Good Cores",             i_iddqt->good_normal_cores_per_sort);
    FAPI_INF("    %-24s : %02d", "Good cores per Cache01", i_iddqt->good_normal_cores_per_EQs[0]);
    FAPI_INF("    %-24s : %02d", "Good cores per Cache23", i_iddqt->good_normal_cores_per_EQs[1]);
    FAPI_INF("    %-24s : %02d", "Good cores per Cache45", i_iddqt->good_normal_cores_per_EQs[2]);
    FAPI_INF("    %-24s : %02d", "Good cores per Cache67", i_iddqt->good_normal_cores_per_EQs[3]);

    FAPI_INF("  %-27s : %d", "MMA state", i_iddqt->mma_not_active);
    FAPI_INF("  %-27s : %d", "MMA leakage percent", i_iddqt->mma_off_leakage_pct);

    // All IQ IDDQ measurements are at 5mA resolution. The OCC wants to
    // consume these at 1mA values.  thus, all values are multiplied by
    // 5 upon installation into the paramater block.
    static const uint32_t CONST_5MA_1MA = 5;
    FAPI_INF("  IDDQ data is converted 5mA units to 1mA units");

#define IDDQ_TRACE(string, size) \
        strcpy(l_line_str, string); \
        sprintf(l_buffer_str, "%-*s", size, l_line_str);\
        strcpy(l_line_str, l_buffer_str); \
        strcpy(l_buffer_str, "");

    // Put out the measurement voltages to the trace.
    IDDQ_TRACE ("  Measurement voltages:", IDDQ_DESC_SIZE);

    for (i = 0; i < IDDQ_MEASUREMENTS; i++)
    {
        sprintf(l_buffer_str, "  %*sV ", 5, idd_meas_str[i]);
        strcat(l_line_str, l_buffer_str);
    }

    FAPI_INF("%s", l_line_str);

#define IDDQ_CURRENT_EXTRACT(_member) \
        { \
        uint16_t _temp = (i_iddqt->_member) * CONST_5MA_1MA;     \
        sprintf(l_buffer_str, "  %6.3f ", (double)_temp/1000);          \
        strcat(l_line_str, l_buffer_str); \
        }

// Temps are all 1B quantities.  Not endianess issues.
#define IDDQ_TEMP_EXTRACT(_member) \
        sprintf(l_buffer_str, "    %4.1f ", ((double)i_iddqt->_member)/2); \
        strcat(l_line_str, l_buffer_str);

    // get IVDDQ measurements with all good cores ON
    IDDQ_TRACE ("  IDDQ all good cores ON:", IDDQ_DESC_SIZE);

    for (i = 0; i < IDDQ_MEASUREMENTS; i++)
    {
        IDDQ_CURRENT_EXTRACT(iddq_all_good_cores_on_caches_on_5ma[i]);
    }

    FAPI_INF("%s", l_line_str);

    // get IVDDQ measurements with all cores and caches OFF
    IDDQ_TRACE ("  IVDDQ all cores, caches OFF:", IDDQ_DESC_SIZE);

    for (i = 0; i < IDDQ_MEASUREMENTS; i++)
    {
       IDDQ_CURRENT_EXTRACT(iddq_all_good_cores_off_good_caches_off_5ma[i]);
    }

    FAPI_INF("%s", l_line_str);;

    // get IVDDQ measurements with all good cores OFF and caches ON
    IDDQ_TRACE ("  IVDDQ all good cores OFF, caches ON:", IDDQ_DESC_SIZE);

    for (i = 0; i < IDDQ_MEASUREMENTS; i++)
    {
        IDDQ_CURRENT_EXTRACT(iddq_all_good_cores_off_good_caches_on_5ma[i]);
    }

    FAPI_INF("%s", l_line_str);

    // get IVDDQ measurements with all good cores in each quad
    for (i = 0; i < MAXIMUM_EQ_SETS; i++)
    {
        IDDQ_TRACE ("  IVDDQ all good cores ON, caches ON:", IDDQ_QUAD_SIZE);
        sprintf(l_buffer_str, "Quad %d:", i);
        strcat(l_line_str, l_buffer_str);

        for (j = 0; j < IDDQ_MEASUREMENTS; j++)
        {
            IDDQ_CURRENT_EXTRACT(iddq_eqs_good_cores_on_good_caches_on_5ma[i][j]);
        }

        FAPI_INF("%s", l_line_str);
    }

    // get ICSQ measurements with all good cores ON
    IDDQ_TRACE ("  ICSQ all good cores ON:", IDDQ_DESC_SIZE);

    for (i = 0; i < IDDQ_MEASUREMENTS; i++)
    {
        IDDQ_CURRENT_EXTRACT(icsq_all_good_cores_on_caches_on_5ma[i]);
    }

    FAPI_INF("%s", l_line_str);

    // get ICSQ measurements with all cores and caches OFF
    IDDQ_TRACE ("  ICSQ all cores, caches OFF:", IDDQ_DESC_SIZE);

    for (i = 0; i < IDDQ_MEASUREMENTS; i++)
    {
       IDDQ_CURRENT_EXTRACT(icsq_all_good_cores_off_good_caches_off_5ma[i]);
    }

    FAPI_INF("%s", l_line_str);;

    // get ICSQ measurements with all good cores OFF and caches ON
    IDDQ_TRACE ("  ICSQ all good cores OFF, caches ON:", IDDQ_DESC_SIZE);

    for (i = 0; i < IDDQ_MEASUREMENTS; i++)
    {
        IDDQ_CURRENT_EXTRACT(icsq_all_good_cores_off_good_caches_on_5ma[i]);
    }

    FAPI_INF("%s", l_line_str);

    // get ICSQ measurements with all good cores in each quad
    for (i = 0; i < MAXIMUM_EQ_SETS; i++)
    {
        IDDQ_TRACE ("  ICSQ all good cores ON, caches ON", IDDQ_QUAD_SIZE);
        sprintf(l_buffer_str, "Quad %d:", i);
        strcat(l_line_str, l_buffer_str);

        for (j = 0; j < IDDQ_MEASUREMENTS; j++)
        {
            IDDQ_CURRENT_EXTRACT(icsq_eqs_good_cores_on_good_caches_on_5ma[i][j]);
        }

        FAPI_INF("%s", l_line_str);
    }

    // get average temperature measurements with all good cores ON
    IDDQ_TRACE ("  Avg temp all good cores ON:",IDDQ_DESC_SIZE);

    for (i = 0; i < IDDQ_MEASUREMENTS; i++)
    {
         IDDQ_TEMP_EXTRACT(avgtemp_all_cores_on_good_caches_on_p5c[i]);
    }

    FAPI_INF("%s", l_line_str);

    // get average temperature measurements with all cores and caches OFF
    IDDQ_TRACE ("  Avg temp all cores OFF, caches OFF:", IDDQ_DESC_SIZE);

    for (i = 0; i < IDDQ_MEASUREMENTS; i++)
    {
        IDDQ_TEMP_EXTRACT(avgtemp_all_cores_off_caches_off_p5c[i]);
    }

    FAPI_INF("%s", l_line_str);

    // get average temperature measurements with all good cores OFF and caches ON
    IDDQ_TRACE ("  Avg temp all good cores OFF, caches ON:",IDDQ_DESC_SIZE);

    for (i = 0; i < IDDQ_MEASUREMENTS; i++)
    {
        IDDQ_TEMP_EXTRACT(avgtemp_all_good_cores_off_good_caches_on_p5c[i]);
    }

    FAPI_INF("%s", l_line_str);
}

/*

int = interpolate
str = stretch
    Case
     UT     d   A               B
CF7         7   int CF7,CF6     CF6
    <- A
CF6 <- B    6   CF6             str CF6,CF5
                                       2
CF5         5   CF5             CF5 (s)

CF4         4   CF4             CF4

CF3         3   CF3             CF3

CF2         2   CF2             CF2

CF1         1   CF1             CF1

CF0         0   CF0             CF0

*/


///////////////////////////////////////////////////////////
////////   find_freq_region
///////////////////////////////////////////////////////////
uint32_t PlatPmPPB::find_freq_region(const uint32_t freq_mhz)
{
    for (auto r = 0; r < NUM_PV_POINTS; ++r)
    {
        FAPI_INF("%08X %08X %d",iv_attr_mvpd_poundV_raw[r].frequency_mhz,
        iv_attr_mvpd_poundV_raw[r+1].frequency_mhz,r);
        if ((freq_mhz >= iv_attr_mvpd_poundV_raw[r].frequency_mhz &&
             freq_mhz <  iv_attr_mvpd_poundV_raw[r+1].frequency_mhz  )  ||
            (freq_mhz >= iv_attr_mvpd_poundV_raw[r].frequency_mhz &&
             iv_attr_mvpd_poundV_raw[r+1].frequency_mhz) == 0)
        {
            return r;
        }
    }
    return 111;
}

///////////////////////////////////////////////////////////
////////   region_steps
///////////////////////////////////////////////////////////
uint32_t PlatPmPPB::region_steps(const uint32_t region)
{

   if (iv_attr_mvpd_poundV_raw[region+1].frequency_mhz == 0)
   {
      return 0;
   }

   return ((iv_attr_mvpd_poundV_raw[region+1].frequency_mhz -
            iv_attr_mvpd_poundV_raw[region].frequency_mhz  ) * 1000 /
            iv_frequency_step_khz );
}


///////////////////////////////////////////////////////////
////////   compute_stretch_point
///////////////////////////////////////////////////////////
// This method computes the new frequency points within a stretched region of the
// RAW #V.  These points are returned in the o_points vector.  (note: this can do
// more that 2 points
void PlatPmPPB::compute_stretched_freq_pt(const uint32_t region,
                                          uint32_t *o_point_mhz)
{
    uint32_t region_start_mhz = iv_attr_mvpd_poundV_raw[region].frequency_mhz;
    uint32_t region_end_mhz = iv_attr_mvpd_poundV_raw[region+1].frequency_mhz;

    uint32_t step_size_mhz =
        (uint32_t) internal_ceil(((float)region_end_mhz - (float)region_start_mhz) / 2);

    *o_point_mhz = region_start_mhz + step_size_mhz;
}

#define INTERPOLATE_FREQ(m_FREQ, round, m_REGION, m_MEMBER, m_VALUE)  \
    {\
        uint16_t m = compute_slope_4_12(iv_attr_mvpd_poundV_raw[m_REGION+1].m_MEMBER,         \
                                        iv_attr_mvpd_poundV_raw[m_REGION].m_MEMBER,           \
                                        iv_attr_mvpd_poundV_raw[m_REGION+1].frequency_mhz,    \
                                        iv_attr_mvpd_poundV_raw[m_REGION].frequency_mhz     );\
        uint32_t x = m_FREQ - iv_attr_mvpd_poundV_raw[m_REGION].frequency_mhz; \
        uint32_t b = iv_attr_mvpd_poundV_raw[m_REGION].m_MEMBER; \
        if (round == ROUND_UP) \
        {\
            m_VALUE = (( m * x ) >> (VID_SLOPE_FP_SHIFT_12 - 1)) + (b << 1) + 1; \
            m_VALUE = m_VALUE >> 1; \
        } \
        else if (round == ROUND_DOWN)\
        { \
            m_VALUE = (( m * x ) >> (VID_SLOPE_FP_SHIFT_12)) + b; \
        }\
    }

///////////////////////////////////////////////////////////
////////   interpolate_freq_point
///////////////////////////////////////////////////////////
void PlatPmPPB::interpolate_freq_pt(const uint32_t freq,
                                    const uint32_t region,
                                    PoundVOpPoint_t *ip)
{
    INTERPOLATE_FREQ( freq, ROUND_UP,   region, vdd_mv,             ip->vdd_mv);
    INTERPOLATE_FREQ( freq, ROUND_UP,   region, idd_tdp_ac_10ma,    ip->idd_tdp_ac_10ma);
    INTERPOLATE_FREQ( freq, ROUND_UP,   region, idd_tdp_dc_10ma,    ip->idd_tdp_dc_10ma);
    INTERPOLATE_FREQ( freq, ROUND_UP,   region, idd_rdp_ac_10ma,    ip->idd_rdp_ac_10ma);
    INTERPOLATE_FREQ( freq, ROUND_UP,   region, idd_rdp_dc_10ma,    ip->idd_rdp_dc_10ma);
    INTERPOLATE_FREQ( freq, ROUND_UP,   region, vcs_mv,             ip->vcs_mv);
    INTERPOLATE_FREQ( freq, ROUND_UP,   region, ics_tdp_ac_10ma,    ip->ics_tdp_ac_10ma);
    INTERPOLATE_FREQ( freq, ROUND_UP,   region, ics_tdp_dc_10ma,    ip->ics_tdp_dc_10ma);
    INTERPOLATE_FREQ( freq, ROUND_UP,   region, ics_rdp_ac_10ma,    ip->ics_rdp_ac_10ma);
    INTERPOLATE_FREQ( freq, ROUND_UP,   region, ics_rdp_dc_10ma,    ip->ics_rdp_dc_10ma);

    ip->vdd_vmin = iv_attr_mvpd_poundV_raw[region].vdd_vmin;
    ip->rt_tdp_ac_10ma = iv_attr_mvpd_poundV_raw[region].rt_tdp_ac_10ma;
    ip->rt_tdp_dc_10ma = iv_attr_mvpd_poundV_raw[region].rt_tdp_dc_10ma;
}


// point set use.
//    VPD_PT_SET_RAW - MVPD as is
//    VPD_PT_SET_STRETCHED - Stretched
//    VPD_PT_SET_BIASED - Biased and stretched
fapi2::ReturnCode PlatPmPPB::create_stretched_pts()
{
    FAPI_INF(">>>>>>>>>> create_stretched_points");

    // COpy the raw data from the vpd
    memcpy (iv_attr_mvpd_poundV_raw_orig,
            iv_attr_mvpd_poundV_raw,
            sizeof(iv_attr_mvpd_poundV_raw));

    if (iv_attrs.attr_fmax_enable == 1)
    {
         FAPI_ASSERT(iv_attr_mvpd_poundV_raw[NUM_PV_POINTS-1].frequency_mhz != 0,
            fapi2::PSTATE_PB_FMAX_ZERO_WHEN_ENABLED()
            .set_CHIP_TARGET(iv_procChip),
            "Fmax #V VPD frequency is 0 which FMax mode is enabled.");

    }
    else
    {
        uint32_t        ur = find_freq_region(iv_attrs.attr_pstate0_freq_mhz);  // UT region
        uint32_t        dr = NUM_PV_POINTS-1;                               // Destination point
        uint32_t        sr = ur;                                            // Source region
        uint32_t        stretch_freq;
        PoundVOpPoint_t ip;

        FAPI_INF("ur %d %08x",ur,iv_attrs.attr_pstate0_freq_mhz);
        FAPI_ASSERT(ur == NUM_PV_POINTS-2,   // (eg for 8 points having 7 regions (0:6) -> region 6)
                fapi2::PSTATE_PB_UT_NOT_REGION6()
                .set_CHIP_TARGET(iv_procChip)
                .set_PSTATE0_FREQ(iv_attrs.attr_pstate0_freq_mhz*1000)
                .set_UT_FREQ(iv_reference_frequency_khz),
                "UltraTurbo must in Region 6");

        // 2 cases: (possible with pointers into a common set of curve fit points)
        // 1. f(UT) > f(CF6)
        // 2. f(UT) = f(CF6) (eg region 6)


        if ( iv_attrs.attr_pstate0_freq_mhz > iv_attr_mvpd_poundV_raw[ur].frequency_mhz)
        {
            FAPI_ASSERT(iv_attr_mvpd_poundV_raw[ur+1].frequency_mhz == 0,
                    fapi2::PSTATE_PB_FMAX_ZERO_UT_INTERPOLATION()
                    .set_CHIP_TARGET(iv_procChip)
                    .set_UT_FREQ(iv_attrs.attr_pstate0_freq_mhz)
                    .set_CF6_FREQ(iv_attr_mvpd_poundV_raw[ur].frequency_mhz),
                    "Fmax #V VPD frequency is 0 and is needed for UltraTurbo interpolation.");

            ip.pstate = (iv_attrs.attr_pstate0_freq_mhz -
                    iv_attr_mvpd_poundV_raw[ur].frequency_mhz) * 1000 / (iv_frequency_step_khz);

            ip.frequency_mhz = iv_attrs.attr_pstate0_freq_mhz;


            //UT freq put in gCF7
            interpolate_freq_pt(iv_attrs.attr_pstate0_freq_mhz, ur, &ip);  // TODO:  use Pstate interpolation?????

            memcpy(&iv_attr_mvpd_poundV_raw[dr],
                    &ip,
                    sizeof(PoundVOpPoint_t));
            --dr;

        }
        else // f(UT) = f(CF6) (eg region 6)
        {
            // Copy CF6 to gCF7
            memcpy(&iv_attr_mvpd_poundV_raw[dr],
                    &iv_attr_mvpd_poundV_raw[ur],
                    sizeof(PoundVOpPoint_t));
            --dr; --sr;

            uint32_t needed_steps = 2;

            FAPI_ASSERT(region_steps(sr) >= needed_steps,
                    fapi2::PSTATE_PB_STRETCH_REGION_LACKS_STEPS()
                    .set_CHIP_TARGET(iv_procChip)
                    .set_UT_FREQ(iv_attrs.attr_pstate0_freq_mhz)
                    .set_STRETCH_REGION(sr)
                    .set_STRETCH_REGION_P1_FREQ(iv_attr_mvpd_poundV_raw[sr+1].frequency_mhz)
                    .set_STRETCH_REGION_FREQ(iv_attr_mvpd_poundV_raw[sr].frequency_mhz),
                    "Fmax #V VPD frequency is 0 and is needed for UltraTurbo interpolation.");

            compute_stretched_freq_pt(sr, &stretch_freq);

            ip.pstate = ((stretch_freq -
                    iv_attr_mvpd_poundV_raw[sr].frequency_mhz) * 1000) / (iv_frequency_step_khz);
            ip.frequency_mhz = stretch_freq;

            interpolate_freq_pt(stretch_freq, sr, &ip);

            memcpy(&iv_attr_mvpd_poundV_raw[dr],
                    &ip,
                    sizeof(PoundVOpPoint_t));
        }
    }

fapi_try_exit:
    FAPI_INF("<<<<<<<<<< create_stretched_points");
    return fapi2::current_err;
}


///////////////////////////////////////////////////////////
////////   compute_vpd_pts
///////////////////////////////////////////////////////////
void PlatPmPPB::compute_vpd_pts()
{
    uint32_t l_vdd_loadline_uohm    = revle32(iv_vdd_sysparam.loadline_uohm);
    uint32_t l_vdd_distloss_uohm    = revle32(iv_vdd_sysparam.distloss_uohm);
    uint32_t l_vdd_distoffset_uv    = revle32(iv_vdd_sysparam.distoffset_uv);
    uint32_t l_vcs_loadline_uohm    = revle32(iv_vcs_sysparam.loadline_uohm);
    uint32_t l_vcs_distloss_uohm    = revle32(iv_vcs_sysparam.distloss_uohm);
    uint32_t l_vcs_distoffset_uv    = revle32(iv_vcs_sysparam.distoffset_uv);


    //RAW POINTS. We just copy them as is
    memcpy (iv_operating_points[VPD_PT_SET_RAW], iv_attr_mvpd_poundV_raw, sizeof(iv_attr_mvpd_poundV_raw));
    for (auto p = 0; p < NUM_PV_POINTS; p++)
    {
        FAPI_DBG("GP: OpPoint=[%d][%d], PS=%3d, Freq=%3X (%4d), Vdd=%3X (%4d)",
                VPD_PT_SET_RAW, p,
                iv_operating_points[VPD_PT_SET_RAW][p].pstate,
                (iv_operating_points[VPD_PT_SET_RAW][p].frequency_mhz),
                (iv_operating_points[VPD_PT_SET_RAW][p].frequency_mhz),
                (iv_operating_points[VPD_PT_SET_RAW][p].vdd_mv),
                (iv_operating_points[VPD_PT_SET_RAW][p].vdd_mv));

        //BIASED POINTS
        uint32_t l_frequency_mhz = (iv_attr_mvpd_poundV_raw[p].frequency_mhz);
        uint32_t l_vdd_mv = (iv_attr_mvpd_poundV_raw[p].vdd_mv);
        uint32_t l_vcs_mv = (iv_attr_mvpd_poundV_raw[p].vcs_mv);

        iv_operating_points[VPD_PT_SET_BIASED][p].vdd_mv =
            bias_adjust_mv(l_vdd_mv, iv_bias.vdd_ext_0p5pct[p]);

        iv_operating_points[VPD_PT_SET_BIASED][p].vcs_mv =
            bias_adjust_mv(l_vcs_mv, iv_bias.vcs_ext_0p5pct[p]);

        iv_operating_points[VPD_PT_SET_BIASED][p].frequency_mhz =
            bias_adjust_mhz(l_frequency_mhz, iv_bias.frequency_0p5pct);

        iv_operating_points[VPD_PT_SET_BIASED][p].idd_tdp_ac_10ma=
            iv_attr_mvpd_poundV_biased[p].idd_tdp_ac_10ma;
        iv_operating_points[VPD_PT_SET_BIASED][p].idd_tdp_dc_10ma=
            iv_attr_mvpd_poundV_biased[p].idd_tdp_dc_10ma;
        iv_operating_points[VPD_PT_SET_BIASED][p].idd_rdp_ac_10ma=
            iv_attr_mvpd_poundV_biased[p].idd_rdp_ac_10ma;
        iv_operating_points[VPD_PT_SET_BIASED][p].idd_rdp_dc_10ma=
            iv_attr_mvpd_poundV_biased[p].idd_rdp_dc_10ma;
        iv_operating_points[VPD_PT_SET_BIASED][p].ics_tdp_ac_10ma=
            iv_attr_mvpd_poundV_biased[p].ics_tdp_ac_10ma;
        iv_operating_points[VPD_PT_SET_BIASED][p].ics_tdp_dc_10ma=
            iv_attr_mvpd_poundV_biased[p].ics_tdp_dc_10ma;
        iv_operating_points[VPD_PT_SET_BIASED][p].ics_rdp_ac_10ma=
            iv_attr_mvpd_poundV_biased[p].ics_rdp_ac_10ma;
        iv_operating_points[VPD_PT_SET_BIASED][p].ics_rdp_dc_10ma=
            iv_attr_mvpd_poundV_biased[p].ics_rdp_dc_10ma;
        iv_operating_points[VPD_PT_SET_BIASED][p].vdd_vmin =
            iv_attr_mvpd_poundV_biased[p].vdd_vmin;
        iv_operating_points[VPD_PT_SET_BIASED][p].rt_tdp_ac_10ma =
            iv_attr_mvpd_poundV_biased[p].rt_tdp_ac_10ma;
        iv_operating_points[VPD_PT_SET_BIASED][p].rt_tdp_dc_10ma =
            iv_attr_mvpd_poundV_biased[p].rt_tdp_dc_10ma;
        iv_operating_points[VPD_PT_SET_BIASED][p].pstate =
            iv_attr_mvpd_poundV_biased[p].pstate;
    }

    // As this is memory to memory, Endianess correction is not necessary.
    iv_reference_frequency_khz =
        (iv_operating_points[VPD_PT_SET_BIASED][VPD_PV_CF6].frequency_mhz) * 1000;

    FAPI_DBG("Reference into GPPB: LE local Freq=%X (%d);  Freq=%X (%d)",
                iv_reference_frequency_khz,
                iv_reference_frequency_khz,
                (iv_reference_frequency_khz),
                (iv_reference_frequency_khz));

    // Now that the VPD_PV_CF6 frequency is known, Pstates can be calculated
    for (auto p = 0; p < NUM_PV_POINTS; p++)
    {
        iv_operating_points[VPD_PT_SET_BIASED][p].pstate =
            ((((iv_operating_points[VPD_PT_SET_BIASED][VPD_PV_CF6].frequency_mhz) -
               (iv_operating_points[VPD_PT_SET_BIASED][p].frequency_mhz)) * 1000) /
             (iv_frequency_step_khz));

        FAPI_DBG("Bi: OpPoint=[%d][%d], PS=%3d, Freq=%3X (%4d), Vdd=%3X (%4d), CF6 Freq=%3X (%4d) Step Freq=%5d",
                    VPD_PT_SET_BIASED, p,
                    iv_operating_points[VPD_PT_SET_BIASED][p].pstate,
                    (iv_operating_points[VPD_PT_SET_BIASED][p].frequency_mhz),
                    (iv_operating_points[VPD_PT_SET_BIASED][p].frequency_mhz),
                    (iv_operating_points[VPD_PT_SET_BIASED][p].vdd_mv),
                    (iv_operating_points[VPD_PT_SET_BIASED][p].vdd_mv),
                    (iv_operating_points[VPD_PT_SET_BIASED][VPD_PV_CF6].frequency_mhz),
                    (iv_operating_points[VPD_PT_SET_BIASED][VPD_PV_CF6].frequency_mhz),
                    (iv_frequency_step_khz));

    }
    //BIASED POINTS and SYSTEM PARMS APPLIED POINTS
    for (auto p = 0; p < NUM_PV_POINTS; p++)
    {
        uint32_t l_vdd_mv = (iv_operating_points[VPD_PT_SET_BIASED][p].vdd_mv);
        uint32_t l_idd_ma = (iv_operating_points[VPD_PT_SET_BIASED][p].idd_tdp_dc_10ma) * 10 +
                             (iv_operating_points[VPD_PT_SET_BIASED][p].idd_tdp_ac_10ma) * 10;
        uint32_t l_vcs_mv = (iv_operating_points[VPD_PT_SET_BIASED][p].vcs_mv);
        uint32_t l_ics_ma = (iv_operating_points[VPD_PT_SET_BIASED][p].ics_tdp_dc_10ma) * 10 +
                             (iv_operating_points[VPD_PT_SET_BIASED][p].ics_tdp_ac_10ma) * 10;

        iv_operating_points[VPD_PT_SET_BIASED_SYSP][p].vdd_mv =
                    sysparm_uplift(l_vdd_mv,
                                   l_idd_ma,
                                   l_vdd_loadline_uohm,
                                   l_vdd_distloss_uohm,
                                   l_vdd_distoffset_uv);


        iv_operating_points[VPD_PT_SET_BIASED_SYSP][p].vcs_mv =
                    sysparm_uplift(l_vcs_mv,
                                   l_ics_ma,
                                   l_vcs_loadline_uohm,
                                   l_vcs_distloss_uohm,
                                   l_vcs_distoffset_uv);

        iv_operating_points[VPD_PT_SET_BIASED_SYSP][p].idd_tdp_ac_10ma=
                   iv_attr_mvpd_poundV_biased[p].idd_tdp_ac_10ma;
        iv_operating_points[VPD_PT_SET_BIASED_SYSP][p].idd_tdp_dc_10ma=
                   iv_attr_mvpd_poundV_biased[p].idd_tdp_dc_10ma;
        iv_operating_points[VPD_PT_SET_BIASED_SYSP][p].idd_rdp_ac_10ma=
                   iv_attr_mvpd_poundV_biased[p].idd_rdp_ac_10ma;
        iv_operating_points[VPD_PT_SET_BIASED_SYSP][p].idd_rdp_dc_10ma=
                   iv_attr_mvpd_poundV_biased[p].idd_rdp_dc_10ma;
        iv_operating_points[VPD_PT_SET_BIASED_SYSP][p].ics_tdp_ac_10ma=
            iv_attr_mvpd_poundV_biased[p].ics_tdp_ac_10ma;
        iv_operating_points[VPD_PT_SET_BIASED_SYSP][p].ics_tdp_dc_10ma=
            iv_attr_mvpd_poundV_biased[p].ics_tdp_dc_10ma;
        iv_operating_points[VPD_PT_SET_BIASED_SYSP][p].ics_rdp_ac_10ma=
            iv_attr_mvpd_poundV_biased[p].ics_rdp_ac_10ma;
        iv_operating_points[VPD_PT_SET_BIASED_SYSP][p].ics_rdp_dc_10ma=
            iv_attr_mvpd_poundV_biased[p].ics_rdp_dc_10ma;
        iv_operating_points[VPD_PT_SET_BIASED_SYSP][p].vdd_vmin =
                   iv_attr_mvpd_poundV_biased[p].vdd_vmin;
        iv_operating_points[VPD_PT_SET_BIASED_SYSP][p].rt_tdp_ac_10ma =
                   iv_attr_mvpd_poundV_biased[p].rt_tdp_ac_10ma;
        iv_operating_points[VPD_PT_SET_BIASED_SYSP][p].rt_tdp_dc_10ma =
                   iv_attr_mvpd_poundV_biased[p].rt_tdp_dc_10ma;
        iv_operating_points[VPD_PT_SET_BIASED_SYSP][p].pstate =
                   iv_attr_mvpd_poundV_biased[p].pstate;
        iv_operating_points[VPD_PT_SET_BIASED_SYSP][p].frequency_mhz =
               iv_operating_points[VPD_PT_SET_BIASED][p].frequency_mhz;
    }

}


///////////////////////////////////////////////////////////
////////  safe_mode_init
///////////////////////////////////////////////////////////
fapi2::ReturnCode PlatPmPPB::safe_mode_init( void )
{
    FAPI_INF(">>>>>>>>>> safe_mode_init");

    if (!iv_attrs.attr_pm_safe_voltage_mv[VDD] ||
            !iv_attrs.attr_pm_safe_voltage_mv[VCS] ||
            !iv_attrs.attr_pm_safe_frequency_mhz)
    {
        //Compute safe mode values
        FAPI_TRY(safe_mode_computation (
                    ),
                "Error from safe_mode_computation function");
    }

fapi_try_exit:
    FAPI_INF("<<<<<<<<<< safe_mode_init");
    return fapi2::current_err;
}

///////////////////////////////////////////////////////////
////////   safe_mode_computation
///////////////////////////////////////////////////////////
fapi2::ReturnCode PlatPmPPB::safe_mode_computation()
{
    const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;
    fapi2::ATTR_SAFE_MODE_FREQUENCY_MHZ_Type l_safe_mode_freq_mhz;
    fapi2::ATTR_SAFE_MODE_VOLTAGE_MV_Type    l_safe_mode_mv;
    uint32_t                                 l_safe_mode_op_ps2freq_mhz;
    uint32_t                                 l_safe_op_freq_mhz;
    uint32_t                                 l_safe_vdm_jump_value;
    uint8_t                                  l_safe_op_ps;;
    uint32_t                                 l_core_floor_mhz;
    uint32_t                                 l_op_pt;
    Pstate                                   l_safe_mode_ps;

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_FREQ_CORE_FLOOR_MHZ,
                           iv_procChip,
                           l_core_floor_mhz));

    // Core floor frequency should be less than ultra turbo freq..
    // if not log an error
    if ((l_core_floor_mhz*1000) > iv_reference_frequency_khz)
    {
        FAPI_ERR("Core floor frequency %08x is greater than UltraTurbo frequency %08x",
                  (l_core_floor_mhz*1000), iv_reference_frequency_khz);
        FAPI_ASSERT(false,
                    fapi2::PSTATE_PB_CORE_FLOOR_FREQ_GT_CF6_FREQ()
                    .set_CHIP_TARGET(iv_procChip)
                    .set_CORE_FLOOR_FREQ(l_core_floor_mhz*1000)
                    .set_UT_FREQ(iv_reference_frequency_khz),
                    "Core floor freqency is greater than UltraTurbo frequency");
    }

    FAPI_INF ("core_floor_mhz 0%08x (%d)",
                l_core_floor_mhz,
                l_core_floor_mhz);
    FAPI_INF("operating_point[VPD_PV_CF0].frequency_mhz 0%08x (%d)",
                (iv_operating_points[VPD_PT_SET_BIASED][VPD_PV_CF0].frequency_mhz),
                (iv_operating_points[VPD_PT_SET_BIASED][VPD_PV_CF0].frequency_mhz));
    FAPI_INF ("reference_freq 0%08x (%d)",
                iv_reference_frequency_khz, iv_reference_frequency_khz);
    FAPI_INF ("step_frequency 0%08x (%d)",
                iv_frequency_step_khz, iv_frequency_step_khz);

    if ( iv_attrs.attr_pm_safe_frequency_mhz)
    {
        l_op_pt = iv_attrs.attr_pm_safe_frequency_mhz;
    }
    else
    {
        l_op_pt = iv_vddPsavFreq;
    }

    // Safe operational frequency is the MAX(core floor, VPD Powersave).
    // PowerSave is the lowest operational frequency that the part was tested at
    if ((iv_attrs.attr_system_dds_disable) &&
        (l_core_floor_mhz > l_op_pt))
    {
        FAPI_INF("Core floor greater that VPD_PV_POWERSAVE");
        l_safe_op_freq_mhz = l_core_floor_mhz;
    }
    else
    {
        FAPI_INF("Core floor less than or equal to VPD_PV_POWERSAVE");
        l_safe_op_freq_mhz = l_op_pt;
    }

    FAPI_INF ("safe_mode_values.safe_op_freq_mhz 0%08x (%d)",
                 l_safe_op_freq_mhz,
                 l_safe_op_freq_mhz);

    // Calculate safe operational pstate.  This must be rounded down to create
    // a faster Pstate than the floor
    l_safe_op_ps = ((float)(iv_reference_frequency_khz) -
                    (float)(l_safe_op_freq_mhz * 1000)) /
                    (float)iv_frequency_step_khz;

    l_safe_mode_op_ps2freq_mhz    = (iv_reference_frequency_khz -
                                    (l_safe_op_ps * iv_frequency_step_khz)) / 1000;

    while (l_safe_mode_op_ps2freq_mhz < l_safe_op_freq_mhz)
    {
        l_safe_op_ps--;

        l_safe_mode_op_ps2freq_mhz =
            (iv_reference_frequency_khz - (l_safe_op_ps * iv_frequency_step_khz)) / 1000;
    }
    if (iv_attrs.attr_system_dds_disable)
    {
        // Calculate safe jump value for large frequency
        l_safe_vdm_jump_value =
            iv_poundW_data.other.dpll_settings.fields.N_L_drop_3p125pct;

        FAPI_INF ("l_safe_vdm_jump_value 0x%x -> %5.2f %%",
                l_safe_vdm_jump_value,
                ((float)l_safe_vdm_jump_value/32)*100);

        // Calculate safe mode frequency - Round up to nearest MHz
        // The uplifted frequency is based on the fact that the DPLL percentage is a
        // "down" value. Hence:
        //     X (uplifted safe) = Y (safe operating) / (1 - droop percentage)
        l_safe_mode_freq_mhz = (uint32_t)
            (((float)l_safe_mode_op_ps2freq_mhz * 1000 /
              (1 - (float)l_safe_vdm_jump_value/32) + 500) / 1000);
    }
    else
    {
        l_safe_mode_freq_mhz = l_safe_mode_op_ps2freq_mhz;
    }

    FAPI_INF("Setting safe mode frequency to %d MHz (0x%x) 0x%x",
              l_safe_mode_freq_mhz,
              l_safe_mode_freq_mhz, iv_reference_frequency_khz);

    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_SAFE_MODE_FREQUENCY_MHZ,
                            iv_procChip,
                            l_safe_mode_freq_mhz));

    // Read back to get any overrides
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_SAFE_MODE_FREQUENCY_MHZ,
                            iv_procChip,
                            l_safe_mode_freq_mhz));

    FAPI_INF ("l_safe_mode_freq_mhz 0x%0x (%d)",
                l_safe_mode_freq_mhz,
                l_safe_mode_freq_mhz);

    // Safe frequency must be less than ultra turbo freq.
    // if not log an error
    if ((l_safe_mode_freq_mhz*1000) > iv_reference_frequency_khz)
    {
        FAPI_ERR("Safe mode frequency %08x is greater than UltraTurbo frequency %08x",
                  (l_safe_mode_freq_mhz*1000), iv_reference_frequency_khz);
        FAPI_ASSERT(false,
                    fapi2::PSTATE_PB_SAFE_FREQ_GT_CF6_FREQ()
                    .set_CHIP_TARGET(iv_procChip)
                    .set_SAFE_FREQ(l_safe_mode_freq_mhz*1000)
                    .set_UT_FREQ(iv_reference_frequency_khz),
                    "Safe mode freqency is greater than UltraTurbo frequency");
    }

    l_safe_mode_ps = ((float)(iv_reference_frequency_khz) -
                     (float)(l_safe_mode_freq_mhz * 1000)) /
                     (float)iv_frequency_step_khz;

    FAPI_INF ("l_safe_mode_ps 0x%x (%d)",l_safe_mode_ps, l_safe_mode_ps);

    // Calculate safe mode voltage
    // Use the biased with system parms operating points

    if (!iv_attrs.attr_system_dds_disable)
    {
        if (iv_attrs.attr_war_mode == fapi2::ENUM_ATTR_HW543384_WAR_MODE_TIE_NEST_TO_PAU)
        {
            l_safe_mode_mv[VDD] = iv_operating_points[VPD_PT_SET_RAW][VPD_PV_CF0].vdd_mv;
            l_safe_mode_mv[VCS] = iv_operating_points[VPD_PT_SET_RAW][VPD_PV_CF0].vcs_mv;
        }
        else
        {
            l_safe_mode_mv[VDD] = ps2v_mv(l_safe_mode_ps, VDD);
            l_safe_mode_mv[VCS] = ps2v_mv(l_safe_mode_ps, VCS);
        }
        FAPI_INF("DDS not enabled Setting safe mode VDD voltage to %d mv (0x%x)",
                l_safe_mode_mv[VDD],
                l_safe_mode_mv[VDD]);
        FAPI_INF("DDS not enabled Setting safe mode VCS voltage to %d mv (0x%x)",
                l_safe_mode_mv[VCS],
                l_safe_mode_mv[VCS]);
    }
    else
    {
        if (iv_attrs.attr_war_mode == fapi2::ENUM_ATTR_HW543384_WAR_MODE_TIE_NEST_TO_PAU)
        {
            l_safe_mode_mv[VDD] = iv_operating_points[VPD_PT_SET_RAW][VPD_PV_CF0].vdd_mv;
            l_safe_mode_mv[VCS] = iv_operating_points[VPD_PT_SET_RAW][VPD_PV_CF0].vcs_mv;
        }
        else
        {
            l_safe_mode_mv[VDD] = ps2v_mv(l_safe_mode_ps, VDD) + iv_attrs.attr_save_mode_nodds_uplift_mv[VDD];
            l_safe_mode_mv[VCS] = ps2v_mv(l_safe_mode_ps, VCS) + iv_attrs.attr_save_mode_nodds_uplift_mv[VCS];
        }

        FAPI_INF("DDS enabled Setting safe mode VDD voltage to %d mv (0x%x) with uplift %d mv (0x%x)",
                l_safe_mode_mv[VDD],
                l_safe_mode_mv[VDD],
                iv_attrs.attr_save_mode_nodds_uplift_mv[VDD],
                iv_attrs.attr_save_mode_nodds_uplift_mv[VDD]);
        FAPI_INF("DDS enabled Setting safe mode VCS voltage to %d mv (0x%x) with uplift %d mv (0x%x)",
                l_safe_mode_mv[VCS],
                l_safe_mode_mv[VCS],
                iv_attrs.attr_save_mode_nodds_uplift_mv[VCS],
                iv_attrs.attr_save_mode_nodds_uplift_mv[VCS]);
    }

    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_SAFE_MODE_VOLTAGE_MV,
                               iv_procChip,
                               l_safe_mode_mv));

    // Read back to get any overrides
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_SAFE_MODE_VOLTAGE_MV,
                                iv_procChip,
                                iv_attrs.attr_pm_safe_voltage_mv));

    // Calculate boot mode voltages
    if (!iv_attrs.attr_boot_voltage_mv[VDD])
    {
        iv_attrs.attr_boot_voltage_mv[VDD] =
                bias_adjust_mv(iv_attrs.attr_pm_safe_voltage_mv[VDD], iv_attrs.attr_boot_voltage_biase_0p5pct);
    }

    if (!iv_attrs.attr_boot_voltage_mv[VCS])
    {
        iv_attrs.attr_boot_voltage_mv[VCS] =
                bias_adjust_mv(iv_attrs.attr_pm_safe_voltage_mv[VCS], iv_attrs.attr_boot_voltage_biase_0p5pct);
    }

    FAPI_INF("VDD boot_mode_mv 0x%x (%d)",
        iv_attrs.attr_boot_voltage_mv[VDD],
        iv_attrs.attr_boot_voltage_mv[VDD]);

    FAPI_INF("VCS boot_mode_mv 0x%x (%d)",
        iv_attrs.attr_boot_voltage_mv[VCS],
        iv_attrs.attr_boot_voltage_mv[VCS]);


fapi_try_exit:
    return fapi2::current_err;
}

///////////////////////////////////////////////////////////
////////   compute_retention_vid
///////////////////////////////////////////////////////////
fapi2::ReturnCode PlatPmPPB::compute_retention_vid()
{
    const uint32_t              RVRM_MIN_MV = 448;
    const uint32_t              RVRM_MAX_MV = 848;

    uint32_t                    l_psave_mv;
    uint32_t                    l_ret_mv;
    fapi2::ATTR_RVRM_VID_Type   l_rvrm_rvid;


    FAPI_INF("> PlatPmPPB:compute_retention_voltage");

    l_psave_mv = iv_attr_mvpd_poundV_biased[VPD_PV_PSAV].vdd_mv;

    FAPI_DBG("iv_attr_mvpd_poundV_biased[VPD_PV_PSAV].vdd_mv 0x%08x (%d)", l_psave_mv, l_psave_mv);

    l_ret_mv = l_psave_mv;
    if (l_psave_mv < RVRM_MIN_MV)
    {
        FAPI_INF("Retention voltage clipped to minimum circuit value.  Retention: %d, PSave: %d",
                    l_psave_mv, RVRM_MIN_MV);
        l_ret_mv = RVRM_MIN_MV;
    }

    if (l_psave_mv > RVRM_MAX_MV)
    {
        FAPI_INF("Retention voltage clipped to maximum circuit value.  Retention: %d, PSave: %d",
                    l_psave_mv, RVRM_MAX_MV);
        l_ret_mv = RVRM_MAX_MV;
    }

    // Rentention VID has 8mV granularity
    l_rvrm_rvid = l_ret_mv >> 3;

    FAPI_DBG("Retention:  voltage %dmV; VID: 0%08X", l_ret_mv, l_rvrm_rvid);

    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_RVRM_VID,
                               iv_procChip,
                               l_rvrm_rvid));

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_RVRM_VID,
                               iv_procChip,
                               l_rvrm_rvid));

    FAPI_DBG("Retention check VID: 0x%08X", l_rvrm_rvid);

fapi_try_exit:
    FAPI_INF("< PlatPmPPB:compute_retention_voltage");
    return fapi2::current_err;
}

///////////////////////////////////////////////////////////
////////   rvrm enablement
///////////////////////////////////////////////////////////
fapi2::ReturnCode PlatPmPPB::rvrm_enablement()
{
    fapi2::ATTR_RVRM_VID_Type   l_rvrm_rvid;
    uint32_t l_rvrm_rvid_mv;
    iv_rvrm_enabled = false;


    do {
        if (!is_rvrm_enabled())
        {
            FAPI_INF("RVRM is not enabled");
            iv_rvrm_enabled = false;
            break;
        }

        fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;
        fapi2::ATTR_IS_SIMULATION_Type is_sim;
        FAPI_TRY(FAPI_ATTR_GET( fapi2::ATTR_IS_SIMULATION, FAPI_SYSTEM, is_sim));

        FAPI_INF("> PlatPmPPB:rvrm_enablement");
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_RVRM_VID,
                        iv_procChip,
                        l_rvrm_rvid));

        FAPI_DBG("Retention check VID: 0x%08X", l_rvrm_rvid);

        // Rentention VID has 8mV granularity
        l_rvrm_rvid_mv = l_rvrm_rvid << 3;

        if (l_rvrm_rvid_mv == 0) {
            iv_rvrm_enabled = false;
        }
    } while(0);

fapi_try_exit:
    FAPI_INF("< PlatPmPPB:rvrm_enablement");
    return fapi2::current_err;
}

///////////////////////////////////////////////////////////
////////   resclk_init
///////////////////////////////////////////////////////////
void PlatPmPPB::resclk_init()
{
    if (iv_attrs.attr_resclk_disable == fapi2::ENUM_ATTR_SYSTEM_RESCLK_DISABLE_OFF)
    {
        iv_resclk_enabled = true;
        FAPI_INF("Resonant Clocks are enabled");
    }
    else
    {
        iv_resclk_enabled = false;
        FAPI_INF("Resonant Clocks are disabled.");
    }
} // end of resclk_init


///////////////////////////////////////////////////////////
////////  ps2v_mv
///////////////////////////////////////////////////////////
uint32_t PlatPmPPB::ps2v_mv(const Pstate i_pstate,
                            const boot_voltage_type i_type)
{

    uint8_t l_SlopeValue =1;
    uint32_t l_boot_voltage = 0;

    FAPI_DBG("i_pstate = 0x%x, (%d)", i_pstate, i_pstate);

    if (i_type == VDD)
    {

        FAPI_INF("l_operating_points[CF0].vdd_mv 0x%-3x (%d)",
                (iv_operating_points[VPD_PT_SET_BIASED_SYSP][VPD_PV_CF0].vdd_mv),
                (iv_operating_points[VPD_PT_SET_BIASED_SYSP][VPD_PV_CF0].vdd_mv));
        FAPI_INF("l_operating_points[CF0].pstate 0x%-3x (%d)",
                iv_operating_points[VPD_PT_SET_BIASED_SYSP][VPD_PV_CF0].pstate,
                iv_operating_points[VPD_PT_SET_BIASED_SYSP][VPD_PV_CF0].pstate);



        uint32_t x = (l_SlopeValue * (-i_pstate + iv_operating_points[VPD_PT_SET_BIASED_SYSP][VPD_PV_CF0].pstate));
        uint32_t y = x >> VID_SLOPE_FP_SHIFT_12;

        uint32_t l_vdd =
            (((l_SlopeValue * (-i_pstate + iv_operating_points[VPD_PT_SET_BIASED_SYSP][VPD_PV_CF0].pstate)) >> VID_SLOPE_FP_SHIFT_12)
             + (iv_operating_points[VPD_PT_SET_BIASED_SYSP][VPD_PV_CF0].vdd_mv));

        // Round up
        l_vdd = (l_vdd << 1) + 1;
        l_vdd = l_vdd >> 1;

        FAPI_DBG("i_pstate = %d "
                "i_operating_points[VPD_PV_CF0].pstate) = %d "
                "i_operating_points[VPD_PV_CF0].vdd_mv  = %d "
                "VID_SLOPE_FP_SHIFT_12 = %X "
                "x = 0x%x  (%d) y = 0x%x (%d)",
                i_pstate,
                iv_operating_points[VPD_PT_SET_BIASED_SYSP][VPD_PV_CF0].pstate,
                (iv_operating_points[VPD_PT_SET_BIASED_SYSP][VPD_PV_CF0].vdd_mv),
                VID_SLOPE_FP_SHIFT_12,
                x, x,
                y, y);
        l_boot_voltage = l_vdd;

        FAPI_INF ("l_vdd 0x%x (%d)", l_vdd, l_vdd);
    }
    if (i_type == VCS)
    {

        FAPI_INF("l_operating_points[VPD_PV_CF0].vcs_mv 0x%-3x (%d)",
                (iv_operating_points[VPD_PT_SET_BIASED_SYSP][VPD_PV_CF0].vcs_mv),
                (iv_operating_points[VPD_PT_SET_BIASED_SYSP][VPD_PV_CF0].vcs_mv));
        FAPI_INF("l_operating_points[VPD_PV_CF0].pstate 0x%-3x (%d)",
                iv_operating_points[VPD_PT_SET_BIASED_SYSP][VPD_PV_CF0].pstate,
                iv_operating_points[VPD_PT_SET_BIASED_SYSP][VPD_PV_CF0].pstate);



        uint32_t x = (l_SlopeValue * (-i_pstate + iv_operating_points[VPD_PT_SET_BIASED_SYSP][VPD_PV_CF0].pstate));
        uint32_t y = x >> VID_SLOPE_FP_SHIFT_12;

        uint32_t l_vcs =
            (((l_SlopeValue * (-i_pstate + iv_operating_points[VPD_PT_SET_BIASED_SYSP][VPD_PV_CF0].pstate)) >> VID_SLOPE_FP_SHIFT_12)
             + (iv_operating_points[VPD_PT_SET_BIASED_SYSP][VPD_PV_CF0].vcs_mv));

        // Round up
        l_vcs = (l_vcs << 1) + 1;
        l_vcs = l_vcs >> 1;

        FAPI_DBG("i_pstate = %d "
                "i_operating_points[VPD_PV_CF0].pstate = %d "
                "i_operating_points[VPD_PV_CF0].vcs_mv  = %d "
                "VID_SLOPE_FP_SHIFT_12 = %X "
                "x = 0x%x  (%d) y = 0x%x (%d)",
                i_pstate,
                iv_operating_points[VPD_PT_SET_BIASED_SYSP][VPD_PV_CF0].pstate,
                (iv_operating_points[VPD_PT_SET_BIASED_SYSP][VPD_PV_CF0].vcs_mv),
                VID_SLOPE_FP_SHIFT_12,
                x, x,
                y, y);
        l_boot_voltage = l_vcs;

        FAPI_INF ("l_vcs 0x%x (%d)", l_vcs, l_vcs);
    }


    return l_boot_voltage;
}

///////////////////////////////////////////////////////////
////////    freq2pState
///////////////////////////////////////////////////////////
int PlatPmPPB::freq2pState (const uint32_t i_freq_khz,
                            Pstate* o_pstate,
                            const FREQ2PSTATE_ROUNDING i_round)
{
    int rc = 0;
    float pstate32 = 0;

    // ----------------------------------
    // compute pstate for given frequency
    // ----------------------------------
    pstate32 = ((float)((iv_reference_frequency_khz) - (float)i_freq_khz)) /
                (float) (iv_frequency_step_khz);
    // @todo Bug fix from Characterization team to deal with VPD not being
    // exactly in step increments
    //       - not yet included to separate changes
    // As higher Pstate numbers represent lower frequencies, the pstate must be
    // snapped to the nearest *higher* integer value for safety.  (e.g. slower
    // frequencies are safer).
    if ((i_round ==  ROUND_SLOW) && (i_freq_khz))
    {
        *o_pstate  = (Pstate)internal_ceil(pstate32);
        FAPI_DBG("freq2pState: ROUND SLOW");
    }
    else
    {
        *o_pstate  = (Pstate)pstate32;
         FAPI_DBG("freq2pState: ROUND FAST");
    }

    FAPI_DBG("freq2pState: i_freq_khz = %u (0x%X); pstate32 = %f; o_pstate = %u (0x%X)",
                i_freq_khz, i_freq_khz, pstate32, *o_pstate, *o_pstate);
    FAPI_DBG("freq2pState: ref_freq_khz = %u (0x%X); step_freq_khz= %u (0x%X)",
                (iv_reference_frequency_khz),
                (iv_reference_frequency_khz),
                (iv_frequency_step_khz),
                (iv_frequency_step_khz));

    // ------------------------------
    // perform pstate bounds checking
    // ------------------------------
    if (pstate32 < PSTATE_MIN)
    {
        rc = -PSTATE_LT_PSTATE_MIN;
        *o_pstate = PSTATE_MIN;
    }

    if (pstate32 > PSTATE_MAX)
    {
        rc = -PSTATE_GT_PSTATE_MAX;
        *o_pstate = PSTATE_MAX;
    }

    return rc;
}


///////////////////////////////////////////////////////////
////////   get_pstate_attrs
///////////////////////////////////////////////////////////
void PlatPmPPB::get_pstate_attrs(AttributeList &o_attr)
{
    memcpy(&o_attr,&iv_attrs, sizeof(iv_attrs));
} // end of get_pstate_attrs

//
///////////////////////////////////////////////////////////
////////  compute_PStateV_I_slope
///////////////////////////////////////////////////////////
void PlatPmPPB::compute_PStateV_I_slope(
                GlobalPstateParmBlock_t * o_gppb)
{
    uint32_t l_voltage_mv_max = 0;
    uint32_t l_voltage_mv_min = 0;
    uint8_t  l_pstate_max = 0;
    uint8_t  l_pstate_min = 0;
    uint32_t l_current_10ma_ac_tdp_max = 0;
    uint32_t l_current_10ma_ac_tdp_min = 0;
    uint32_t l_current_10ma_dc_tdp_max = 0;
    uint32_t l_current_10ma_dc_tdp_min = 0;

    uint32_t l_current_10ma_ac_rdp_max = 0;
    uint32_t l_current_10ma_ac_rdp_min = 0;
    uint32_t l_current_10ma_dc_rdp_max = 0;
    uint32_t l_current_10ma_dc_rdp_min = 0;

    char vlt_str[][4] = {"VDD","VCS"};
    char cur_str[][4] = {"IDD","ICS"};

    for(auto pt_set = 0; pt_set < NUM_VPD_PTS_SET; ++pt_set)
    {
        // CF6 TURBO pstate check is required only if fmax is enabled, because
        // fmax will be greater than CF6
        if (!(iv_operating_points[pt_set][CF0].pstate) ||
                !(iv_operating_points[pt_set][CF1].pstate) ||
                !(iv_operating_points[pt_set][CF2].pstate) ||
                !(iv_operating_points[pt_set][CF3].pstate) ||
                !(iv_operating_points[pt_set][CF4].pstate) ||
                !(iv_operating_points[pt_set][CF5].pstate))
//                (!(iv_operating_points[pt_set][CF6].pstate) && iv_poundV_fmax_enable)) //TBD
        {
            FAPI_ERR("Non-UltraTurbo PSTATE value shouldn't be zero for %s", vpdSetStr[pt_set]);
            return;
        }

#define COMPUTE_V_I_SLOPES(PS_V_I, slope_type, V_I_MAX, V_I_MIN, PSTATE_MAX, PSTATE_MIN)  \
     if (slope_type == NORMAL) \
    {\
        PS_V_I = revle16( \
                  compute_slope_4_12(V_I_MAX, V_I_MIN, PSTATE_MIN, PSTATE_MAX) );\
    } \
    else if (slope_type == INVERTED) \
    {\
        PS_V_I = revle16( \
                  compute_slope_4_12( PSTATE_MIN, PSTATE_MAX, V_I_MAX, V_I_MIN) );\
    }


        for(auto region(REGION_CF0_CF1); region <= REGION_CF6_CF7; ++region)
        {
            for (auto rails = RUNTIME_RAIL_VDD; rails <= RUNTIME_RAIL_VCS; rails++)
            {
                l_pstate_max = iv_operating_points[pt_set][region + 1].pstate;
                l_pstate_min = iv_operating_points[pt_set][region].pstate;
                //VOLTAGE pstate slopes
                //Calculate slopes
                if (rails == RUNTIME_RAIL_VDD)
                {
                    l_voltage_mv_max = iv_operating_points[pt_set][region + 1].vdd_mv;
                    l_voltage_mv_min = iv_operating_points[pt_set][region].vdd_mv;
                }
                else
                {
                    l_voltage_mv_max = iv_operating_points[pt_set][region + 1].vcs_mv;
                    l_voltage_mv_min = iv_operating_points[pt_set][region].vcs_mv;
                }
                // Pstate value decreases with increasing region.  Thus the values
                // are swapped to result in a positive difference.

                //VDD Voltage slopes
                COMPUTE_V_I_SLOPES(o_gppb->ps_voltage_slopes[rails][pt_set][region],
                                    NORMAL, l_voltage_mv_max,l_voltage_mv_min,
                                    l_pstate_max,l_pstate_min)

                FAPI_DBG("%s ps_voltage_slopes   [%s][%s] 0x%04x %d",vlt_str[rails],
                        vpdSetStr[pt_set], region_names[region],
                        revle16(o_gppb->ps_voltage_slopes[rails][pt_set][region]),
                        revle16(o_gppb->ps_voltage_slopes[rails][pt_set][region]));

                //Voltage inverted slopes
                //Calculate inverted slopes
                // Pstate value decreases with increasing region.  Thus the values
                // are swapped to result in a positive difference.
                COMPUTE_V_I_SLOPES(o_gppb->voltage_ps_slopes[rails][pt_set][region],
                                    INVERTED, l_voltage_mv_max,l_voltage_mv_min,
                                    l_pstate_max,l_pstate_min)

                FAPI_DBG("%s voltage_ps_slopes   [%s][%s] 0x%04x %d", vlt_str[rails],
                        vpdSetStr[pt_set], region_names[region],
                        revle16(o_gppb->voltage_ps_slopes[rails][pt_set][region]),
                        revle16(o_gppb->voltage_ps_slopes[rails][pt_set][region]));

                //CURRENT pstate slopes
                //Calculate slopes
                if (rails == RUNTIME_RAIL_IDD)
                {
                    l_current_10ma_ac_tdp_max = iv_operating_points[pt_set][region + 1].idd_tdp_ac_10ma;
                    l_current_10ma_ac_tdp_min = iv_operating_points[pt_set][region].idd_tdp_ac_10ma;
                    l_current_10ma_dc_tdp_max = iv_operating_points[pt_set][region + 1].idd_tdp_dc_10ma;
                    l_current_10ma_dc_tdp_min = iv_operating_points[pt_set][region].idd_tdp_dc_10ma;

                    l_current_10ma_ac_rdp_max = iv_operating_points[pt_set][region + 1].idd_rdp_ac_10ma;
                    l_current_10ma_ac_rdp_min = iv_operating_points[pt_set][region].idd_rdp_ac_10ma;
                    l_current_10ma_dc_rdp_max = iv_operating_points[pt_set][region + 1].idd_rdp_dc_10ma;
                    l_current_10ma_dc_rdp_min = iv_operating_points[pt_set][region].idd_rdp_dc_10ma;
                }
                else
                {
                    l_current_10ma_ac_tdp_max = iv_operating_points[pt_set][region + 1].ics_tdp_ac_10ma;
                    l_current_10ma_ac_tdp_min = iv_operating_points[pt_set][region].ics_tdp_ac_10ma;
                    l_current_10ma_dc_tdp_max = iv_operating_points[pt_set][region + 1].ics_tdp_dc_10ma;
                    l_current_10ma_dc_tdp_min = iv_operating_points[pt_set][region].ics_tdp_dc_10ma;

                    l_current_10ma_ac_rdp_max = iv_operating_points[pt_set][region + 1].ics_rdp_ac_10ma;
                    l_current_10ma_ac_rdp_min = iv_operating_points[pt_set][region].ics_rdp_ac_10ma;
                    l_current_10ma_dc_rdp_max = iv_operating_points[pt_set][region + 1].ics_rdp_dc_10ma;
                    l_current_10ma_dc_rdp_min = iv_operating_points[pt_set][region].ics_rdp_dc_10ma;
                }

                // Pstate value decreases with increasing region.  Thus the values
                // are swapped to result in a positive difference.
                // AC
                COMPUTE_V_I_SLOPES(o_gppb->ps_ac_current_tdp[rails][pt_set][region],
                                    NORMAL, l_current_10ma_ac_tdp_max,l_current_10ma_ac_tdp_min,
                                    l_pstate_max,l_pstate_min)

                FAPI_DBG("%s AC ps_ac_current_tdp[%s][%s] 0x%04x %d", cur_str[rails], vpdSetStr[pt_set], region_names[region],
                        revle16(o_gppb->ps_ac_current_tdp[rails][pt_set][region]),
                        revle16(o_gppb->ps_ac_current_tdp[rails][pt_set][region]));

                //DC
                COMPUTE_V_I_SLOPES(o_gppb->ps_dc_current_tdp[rails][pt_set][region],
                                    NORMAL, l_current_10ma_dc_tdp_max,l_current_10ma_dc_tdp_min,
                                    l_pstate_max,l_pstate_min)

                FAPI_DBG("%s DC ps_dc_current_tdp[%s][%s] 0x%04x %d",cur_str[rails], vpdSetStr[pt_set], region_names[region],
                        revle16(o_gppb->ps_dc_current_tdp[rails][pt_set][region]),
                        revle16(o_gppb->ps_dc_current_tdp[rails][pt_set][region]));

                //Current inverted slopes
                //Calculate inverted slopes

                // Pstate value decreases with increasing region.  Thus the values
                // are swapped to result in a positive difference.
                // AC
                COMPUTE_V_I_SLOPES(o_gppb->ac_current_ps_tdp[rails][pt_set][region],
                                    INVERTED, l_current_10ma_ac_tdp_max,l_current_10ma_ac_tdp_min,
                                    l_pstate_max,l_pstate_min)
                FAPI_DBG("%s AC ac_current_ps_tdp[%s][%s] 0x%04x %d",cur_str[rails],vpdSetStr[pt_set], region_names[region],
                        revle16(o_gppb->ac_current_ps_tdp[rails][pt_set][region]),
                        revle16(o_gppb->ac_current_ps_tdp[rails][pt_set][region]));

                //DC
                COMPUTE_V_I_SLOPES(o_gppb->dc_current_ps_tdp[rails][pt_set][region],
                                    INVERTED, l_current_10ma_dc_tdp_max,l_current_10ma_dc_tdp_min,
                                    l_pstate_max,l_pstate_min)
                FAPI_DBG("%s DC dc_current_ps_tdp[%s][%s] 0x%04x %d", cur_str[rails],vpdSetStr[pt_set], region_names[region],
                        revle16(o_gppb->dc_current_ps_tdp[rails][pt_set][region]),
                        revle16(o_gppb->dc_current_ps_tdp[rails][pt_set][region]));

                // Pstate value decreases with increasing region.  Thus the values
                // are swapped to result in a positive difference.
                // AC
                COMPUTE_V_I_SLOPES(o_gppb->ps_ac_current_rdp[rails][pt_set][region],
                                    NORMAL, l_current_10ma_ac_rdp_max,l_current_10ma_ac_rdp_min,
                                    l_pstate_max,l_pstate_min)
                FAPI_DBG("%s AC ps_ac_current_rdp[%s][%s] 0x%04x %d", cur_str[rails], vpdSetStr[pt_set], region_names[region],
                        revle16(o_gppb->ps_ac_current_rdp[rails][pt_set][region]),
                        revle16(o_gppb->ps_ac_current_rdp[rails][pt_set][region]));

                //DC
                COMPUTE_V_I_SLOPES(o_gppb->ps_dc_current_rdp[rails][pt_set][region],
                                    NORMAL, l_current_10ma_dc_rdp_max,l_current_10ma_dc_rdp_min,
                                    l_pstate_max,l_pstate_min)
                FAPI_DBG("%s DC ps_dc_current_rdp[%s][%s] 0x%04x %d",cur_str[rails], vpdSetStr[pt_set], region_names[region],
                        revle16(o_gppb->ps_dc_current_rdp[rails][pt_set][region]),
                        revle16(o_gppb->ps_dc_current_rdp[rails][pt_set][region]));

                //Current inverted slopes
                //Calculate inverted slopes

                // Pstate value decreases with increasing region.  Thus the values
                // are swapped to result in a positive difference.
                // AC
                COMPUTE_V_I_SLOPES(o_gppb->ac_current_ps_rdp[rails][pt_set][region],
                                    INVERTED, l_current_10ma_ac_rdp_max,l_current_10ma_ac_rdp_min,
                                    l_pstate_max,l_pstate_min)
                FAPI_DBG("%s AC ac_current_ps_rdp[%s][%s] 0x%04x %d",cur_str[rails],vpdSetStr[pt_set], region_names[region],
                        revle16(o_gppb->ac_current_ps_rdp[rails][pt_set][region]),
                        revle16(o_gppb->ac_current_ps_rdp[rails][pt_set][region]));

                //DC
                COMPUTE_V_I_SLOPES(o_gppb->dc_current_ps_rdp[rails][pt_set][region],
                                    INVERTED, l_current_10ma_dc_rdp_max,l_current_10ma_dc_rdp_min,
                                    l_pstate_max,l_pstate_min)
                FAPI_DBG("%s DC dc_current_ps_rdp[%s][%s] 0x%04x %d", cur_str[rails],vpdSetStr[pt_set], region_names[region],
                        revle16(o_gppb->dc_current_ps_rdp[rails][pt_set][region]),
                        revle16(o_gppb->dc_current_ps_rdp[rails][pt_set][region]));
            }//end of rails
        }//end of region
    } //end of pts

}


///////////////////////////////////////////////////////////
////////  compute_dds_slopes
///////////////////////////////////////////////////////////
void PlatPmPPB::compute_dds_slopes(
                GlobalPstateParmBlock_t * o_gppb)
{
    uint32_t l_max = 0;
    uint32_t l_min = 0;
    for(auto pt_set = 0; pt_set < NUM_VPD_PTS_SET; ++pt_set)
    {
        for(auto region(REGION_CF0_CF1); region <= REGION_CF6_CF7; ++region)
        {
            for (auto cores = 0; cores < MAXIMUM_CORES; cores++)
            {
                //Insertion delay slopes
                o_gppb->ps_dds_delay_slopes[pt_set][cores][region] =
                    revle16(
                            compute_slope_4_12(iv_poundW_data.entry[cores][region+1].ddsc.fields.insrtn_dely,
                                iv_poundW_data.entry[cores][region].ddsc.fields.insrtn_dely,
                                iv_operating_points[pt_set][region].pstate,
                                iv_operating_points[pt_set][region + 1].pstate)
                           );

                FAPI_DBG("ps_dds_delay_slopes [%s][%s] 0x%04x %d",
                        vpdSetStr[pt_set], region_names[region],
                        revle16(o_gppb->ps_dds_delay_slopes[pt_set][cores][region]),
                        revle16(o_gppb->ps_dds_delay_slopes[pt_set][cores][region]));
            }

            for (uint8_t dds_cnt = TRIP_OFFSET; dds_cnt < NUM_POUNDW_DDS_FIELDS; ++dds_cnt)
            {
                for (auto cores = 0; cores < MAXIMUM_CORES; cores++)
                {
                    switch (dds_cnt)
                    {
                        case TRIP_OFFSET:
                            l_max = iv_poundW_data.entry[cores][region+1].ddsc.fields.trip_offset;
                            l_min = iv_poundW_data.entry[cores][region].ddsc.fields.trip_offset;
                            break;
                        case DATA0_OFFSET:
                            l_max = iv_poundW_data.entry[cores][region+1].ddsc.fields.data0_select;
                            l_min = iv_poundW_data.entry[cores][region].ddsc.fields.data0_select;
                            break;
                        case DATA1_OFFSET:
                            l_max = iv_poundW_data.entry[cores][region+1].ddsc.fields.data1_select;
                            l_min = iv_poundW_data.entry[cores][region].ddsc.fields.data1_select;
                            break;
                        case DATA2_OFFSET:
                            l_max = iv_poundW_data.entry[cores][region+1].ddsc.fields.data2_select;
                            l_min = iv_poundW_data.entry[cores][region].ddsc.fields.data2_select;
                            break;
                        case LARGE_DROOP_DETECT:
                            l_max = iv_poundW_data.entry[cores][region+1].ddsc.fields.large_droop;
                            l_min = iv_poundW_data.entry[cores][region].ddsc.fields.large_droop;
                            break;
                        case SMALL_DROOP_DETECT:
                            l_max = iv_poundW_data.entry[cores][region+1].ddsc.fields.small_droop;
                            l_min = iv_poundW_data.entry[cores][region].ddsc.fields.small_droop;
                            break;
                        case SLOPEA_START_DETECT:
                            l_max = iv_poundW_data.entry[cores][region+1].ddsc.fields.slopeA_start;
                            l_min = iv_poundW_data.entry[cores][region].ddsc.fields.slopeA_start;
                            break;
                        case SLOPEA_END_DETECT:
                            l_max = iv_poundW_data.entry[cores][region+1].ddsc.fields.slopeA_end;
                            l_min = iv_poundW_data.entry[cores][region].ddsc.fields.slopeA_end;
                            break;
                        case SLOPEB_START_DETECT:
                            l_max = iv_poundW_data.entry[cores][region+1].ddsc.fields.slopeB_start;
                            l_min = iv_poundW_data.entry[cores][region].ddsc.fields.slopeB_start;
                            break;
                        case SLOPEB_END_DETECT:
                            l_max = iv_poundW_data.entry[cores][region+1].ddsc.fields.slopeB_end;
                            l_min = iv_poundW_data.entry[cores][region].ddsc.fields.slopeB_end;
                            break;
                        case SLOPEA_CYCLES:
                            l_max = iv_poundW_data.entry[cores][region+1].ddsc.fields.slopeA_cycles;
                            l_min = iv_poundW_data.entry[cores][region].ddsc.fields.slopeA_cycles;
                            break;
                        case SLOPEB_CYCLES:
                            l_max = iv_poundW_data.entry[cores][region+1].ddsc.fields.slopeB_cycles;
                            l_min = iv_poundW_data.entry[cores][region].ddsc.fields.slopeB_cycles;
                            break;
                    }

                    o_gppb->ps_dds_slopes[dds_cnt][pt_set][cores][region] =
                                compute_slope_2_6(l_max,
                                    l_min,
                                    iv_operating_points[pt_set][region].pstate,
                                    iv_operating_points[pt_set][region + 1].pstate)
                               ;
                    FAPI_DBG("ps_dds_delay_slopes [%s][%s] 0x%04x %d",
                            vpdSetStr[pt_set], region_names[region],
                            revle16(o_gppb->ps_dds_slopes[dds_cnt][pt_set][cores][region]),
                            revle16(o_gppb->ps_dds_slopes[dds_cnt][pt_set][cores][region]));
                }

            }//end of dds_cnt
        }//end of region
    } //end of pts

}

///////////////////////////////////////////////////////////
//////// update_vrt
///////////////////////////////////////////////////////////
fapi2::ReturnCode PlatPmPPB::update_vrt(
                             uint8_t* i_pBuffer,
                             VRT_t* o_vrt_data)
{
    uint32_t l_index_0 = 0;
    uint8_t  l_type = 0;
    uint32_t l_freq_khz = 0;
    uint32_t l_step_freq_khz;
    Pstate   l_ps;
    uint8_t  l_temp = 0;

    l_step_freq_khz = (iv_frequency_step_khz);
    FAPI_DBG("l_step_freq_khz = 0x%X (%d)", l_step_freq_khz, l_step_freq_khz);

#define UINT16_GET(__uint8_ptr)   ((uint16_t)( ( (*((const uint8_t *)(__uint8_ptr)) << 8) | *((const uint8_t *)(__uint8_ptr) + 1) ) ))
    //Initialize VRT header

    o_vrt_data->vrtHeader.fields.marker       = *i_pBuffer;
    i_pBuffer++;
    o_vrt_data->vrtHeader.fields.type         = (*i_pBuffer & 0x80) >> 7;
    o_vrt_data->vrtHeader.fields.content      = (*i_pBuffer & 0x40) >> 6;
    o_vrt_data->vrtHeader.fields.version      = (*i_pBuffer & 0x30) >> 4;
    l_temp                                    = (*i_pBuffer & 0x0F);   // upper 4 bits of 5
    i_pBuffer++;
    o_vrt_data->vrtHeader.fields.io_id        = (l_temp << 1) | ((*i_pBuffer & 0x80) >> 7);
    o_vrt_data->vrtHeader.fields.ac_id        = (*i_pBuffer & 0x7C) >> 2;  // 5 bits of 5
    l_temp                                    = (*i_pBuffer & 0x03);  // upper 2 bits of 5
    i_pBuffer++;
    o_vrt_data->vrtHeader.fields.vcs_ceff_id  = (l_temp << 6) | ((*i_pBuffer & 0xE0) >> 5);
    o_vrt_data->vrtHeader.fields.vdd_ceff_id  = (*i_pBuffer & 0x1F);
    i_pBuffer++;

    //find type
    l_type = (o_vrt_data->vrtHeader.fields.type);

    char l_buffer_str[256];   // Temporary formatting string buffer
    char l_line_str[256];     // Formatted output line string

    // Filtering Tracing output to only only QID of 0
    bool b_output_trace = false;
    if (o_vrt_data->vrtHeader.fields.vdd_ceff_id == 25 &&
        o_vrt_data->vrtHeader.fields.io_id == 5 &&
        o_vrt_data->vrtHeader.fields.ac_id == 3)
    {
        b_output_trace = true;
    }

    if (b_output_trace)
    {
        strcpy(l_line_str, "VRT:");
        sprintf(l_buffer_str, " %X Type %X Content %d Ver %d IO %d AC %d VCS %d VDD %2d  ",
                o_vrt_data->vrtHeader.fields.marker,
                o_vrt_data->vrtHeader.fields.type,
                o_vrt_data->vrtHeader.fields.content,
                o_vrt_data->vrtHeader.fields.version,
                o_vrt_data->vrtHeader.fields.io_id,
                o_vrt_data->vrtHeader.fields.ac_id,
                o_vrt_data->vrtHeader.fields.vcs_ceff_id,
                o_vrt_data->vrtHeader.fields.vdd_ceff_id);
        strcat(l_line_str, l_buffer_str);
        FAPI_INF("%s ", l_line_str)
    }
    // Get the frequency biases in place and check that they all match
    double f_freq_bias = 0;
    int freq_bias_value_hp = 0;
    freq_bias_value_hp = iv_bias.frequency_0p5pct;

    f_freq_bias = calc_bias(freq_bias_value_hp);

    if (f_freq_bias != 1)
        FAPI_INF("A frequency bias multiplier of %f being applied to all VRT entries",
                    f_freq_bias);

    //Initialize VRT data part

    for (l_index_0 = 0; l_index_0 < WOF_VRT_SIZE; ++l_index_0)
    {
        strcpy(l_line_str, "    ");
        strcpy(l_buffer_str, "");

        // Offset MHz*1000 (khz) + step (khz) * (sysvalue - 60)
        float l_freq_raw_khz;
        float l_freq_biased_khz;
        l_freq_raw_khz = (float)(1000 * 1000 + (l_step_freq_khz * ((*i_pBuffer) - 60)));

        l_freq_biased_khz = l_freq_raw_khz * f_freq_bias;

        // Round to nearest MHz as that is how the system tables are generated
        float l_freq_raw_up_mhz = (l_freq_biased_khz + 500)/1000;
        float l_freq_raw_dn_mhz = (l_freq_biased_khz)/1000;
        float l_freq_rounded_khz;
        if (l_freq_raw_up_mhz >= l_freq_raw_dn_mhz)
            l_freq_rounded_khz = (uint32_t)(l_freq_raw_up_mhz * 1000);
        else
            l_freq_rounded_khz = (uint32_t)(l_freq_raw_dn_mhz * 1000);

        l_freq_khz = (uint32_t)(l_freq_rounded_khz);

        FAPI_DBG("freq_raw_khz  = %f; freq_biased_khz = %f; freq_rounded = 0x%X (%d); sysvalue = 0x%X (%d)",
                l_freq_raw_khz,
                l_freq_biased_khz,
                l_freq_khz, l_freq_khz,
                *i_pBuffer, *i_pBuffer);

        // Translate to Pstate.  The called function will clip to the
        // legal range.  The rc is only interesting if we care that
        // the pstate was clipped;  in this case, we don't.
        freq2pState(l_freq_khz, &l_ps, ROUND_SLOW);
        o_vrt_data->data[l_index_0] = l_ps;

        // Trace the last 8 values of the 24 for debug. As this is
        // in a loop that is processing over 1000 tables, the last
        // 8 gives a view that can correlate that the input data read
        // is correct without overfilling the HB trace buffer.
        if (b_output_trace)
        {
            sprintf(l_buffer_str, "[%2d] PS 0x%02X MHz %4d",
                    l_index_0, o_vrt_data->data[l_index_0],  l_freq_khz / 1000);
            strcat(l_line_str, l_buffer_str);
            FAPI_INF("%s ", l_line_str);
        }

        i_pBuffer++;
    }

    // Flip the type from System (0) to HOMER (1)
    l_type = 1;
    o_vrt_data->vrtHeader.fields.type =  l_type;

    return fapi2::current_err;
}

///////////////////////////////////////////////////////////
////////  wof_init
/////////////////////////PlatPmPPB//////////////////////////////////
fapi2::ReturnCode PlatPmPPB::wof_init(
                             uint8_t* o_buf,
                             uint32_t& io_size)
{
    FAPI_DBG(">> WOF initialization");

    fapi2::ReturnCode l_rc = 0;
    uint16_t l_vdd_size = 0;
    uint16_t l_vcs_size = 0;
    uint16_t l_io_size  = 0;
    uint16_t l_ac_size  = 0;
    fapi2::ATTR_SYSTEM_WOF_VALIDATION_MODE_Type l_wof_mode;

    //this structure has VRT header + data
    VRT_t l_vrt;
    memset (&l_vrt, 0, sizeof(l_vrt));
    // Use new to avoid over-running the stack
    fapi2::ATTR_WOF_TABLE_DATA_Type* l_wof_table_data =
        (fapi2::ATTR_WOF_TABLE_DATA_Type*)new fapi2::ATTR_WOF_TABLE_DATA_Type;

    do
    {

        if (!is_wof_enabled())
        {
            FAPI_INF("WOF is not enabled");
            iv_wof_enabled = false;
            break;
        }

        FAPI_DBG("l_wof_table_data  addr = %p size = %d",
                l_wof_table_data, sizeof(fapi2::ATTR_WOF_TABLE_DATA_Type));

        // If this attribute is set, fill in l_wof_table_data with the VRT data
        // from the internal, static table.
        const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;
        fapi2::ATTR_SYS_VRT_STATIC_DATA_ENABLE_Type l_sys_vrt_static_data = 0;
        FAPI_ATTR_GET(fapi2::ATTR_SYS_VRT_STATIC_DATA_ENABLE,
                FAPI_SYSTEM,
                l_sys_vrt_static_data);

        if (l_sys_vrt_static_data)
        {
            FAPI_DBG("ATTR_SYS_VRT_STATIC_DATA_ENABLE is SET");

            // Copy base WOF header data
            memcpy (l_wof_table_data, &g_wofData, sizeof(WofTablesHeader_t));
            uint32_t l_index = sizeof(WofTablesHeader_t);

            uint64_t* ptr = (uint64_t*) l_wof_table_data;
            for (auto x = 0; x <8; ++x)
            {

                FAPI_INF("Raw wof_table_data (may be big or little endian based on platform) @  offset  %02d = %016llX", x, *ptr);
                ptr++;
            }


            WofTablesHeader_t* p_wfth;
            p_wfth = reinterpret_cast<WofTablesHeader_t*>(l_wof_table_data);
            FAPI_INF("WFTH: %X", revle32(p_wfth->magic_number.value));

            // Set some defaults into the header
            strcpy(p_wfth->table_version, "Denali.20200125");
            strcpy(p_wfth->package_name,  "DENALI_DCM");

            FAPI_INF("before l_vcs_start %d (0x%X) l_vdd_start %d (0x%X) l_io_start %d (0x%X) l_ac_start %d (0x%X) ",
                        revle16(p_wfth->vcs_start),
                        revle16(p_wfth->vcs_start),
                        revle16(p_wfth->vdd_start),
                        revle16(p_wfth->vdd_start),
                        revle16(p_wfth->io_start),
                        revle16(p_wfth->io_start),
                        revle16(p_wfth->amb_cond_start),
                        revle16(p_wfth->amb_cond_start) );

            FAPI_INF("before l_vcs_size %d (0x%X) l_vdd_size %d (0x%X) l_io_size %d (0x%X) l_ac_size %d (0x%X) ",
                        revle16(p_wfth->vcs_size),
                        revle16(p_wfth->vcs_size),
                        revle16(p_wfth->vdd_size),
                        revle16(p_wfth->vdd_size),
                        revle16(p_wfth->io_size),
                        revle16(p_wfth->io_size),
                        revle16(p_wfth->amb_cond_size),
                        revle16(p_wfth->amb_cond_size) );

            FAPI_INF("before l_vcs_step %d (0x%X) l_vdd_step %d (0x%X) l_io_step %d (0x%X) l_ac_step %d (0x%X) ",
                        revle16(p_wfth->vcs_step),
                        revle16(p_wfth->vcs_step),
                        revle16(p_wfth->vdd_step),
                        revle16(p_wfth->vdd_step),
                        revle16(p_wfth->io_step),
                        revle16(p_wfth->io_step),
                        revle16(p_wfth->amb_cond_step),
                        revle16(p_wfth->amb_cond_step) );

            l_vcs_size = revle16(p_wfth->vcs_size);
            l_vdd_size = revle16(p_wfth->vdd_size);
            l_io_size  = revle16(p_wfth->io_size);
            l_ac_size  = revle16(p_wfth->amb_cond_size);

            //Sample VRT data
            l_vrt.vrtHeader.fields.marker  = 0x56; // "V"
            l_vrt.vrtHeader.fields.type    = 1;    // system
            l_vrt.vrtHeader.fields.content = 0;    // CeffRatio
            l_vrt.vrtHeader.fields.version = 0;    // 12 entry

            FAPI_INF("VRT default: l_vrt fields value 0x%08X marker %X type %d content %d io %02d ac %02d vc %02d vd %02d",
                                    l_vrt.vrtHeader.value,
                                    l_vrt.vrtHeader.fields.marker,
                                    l_vrt.vrtHeader.fields.type,
                                    l_vrt.vrtHeader.fields.content,
                                    l_vrt.vrtHeader.fields.io_id,
                                    l_vrt.vrtHeader.fields.ac_id,
                                    l_vrt.vrtHeader.fields.vcs_ceff_id,
                                    l_vrt.vrtHeader.fields.vdd_ceff_id
                                    );

            for (auto i = 0; i < WOF_VRT_SIZE; ++i)
            {
                fapi2::ATTR_IS_IBM_SIMULATION_Type is_sim;
                FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IS_IBM_SIMULATION, FAPI_SYSTEM, is_sim));
                if (is_sim)
                {
                    l_vrt.data[i] = g_static_vrt[i];
                }
                else
                {
                    l_vrt.data[i] = g_static_vrt_hw[i];
                }
                FAPI_INF("Static System VRT data[%02d] = 0x%X", i, l_vrt.data[i]);
            }

            for (uint32_t vcs = 0; vcs < l_vcs_size; ++vcs)
            {
                l_vrt.vrtHeader.fields.vcs_ceff_id = vcs;
                for (uint32_t vdd = 0; vdd < l_vdd_size; ++vdd)
                {
                    l_vrt.vrtHeader.fields.vdd_ceff_id = vdd;
                    for (uint32_t io = 0; io < l_io_size; ++io)
                    {
                        l_vrt.vrtHeader.fields.io_id = io;
                        for (uint32_t amb = 0; amb < l_ac_size; ++amb)
                        {
                            l_vrt.vrtHeader.fields.ac_id = amb;

                            l_vrt.vrtHeader.value = revle32(l_vrt.vrtHeader.value); // Store to structure in BE
                            memcpy((*l_wof_table_data + l_index), &l_vrt, sizeof (l_vrt));
                            l_vrt.vrtHeader.value = revle32(l_vrt.vrtHeader.value); // Restore the fixed structure

                            FAPI_DBG("VRT default: l_vrt fields value 0x%08X marker %X type %d content %d io %02d ac %02d vc %02d vd %02d",
                                    l_vrt.vrtHeader.value,
                                    l_vrt.vrtHeader.fields.marker,
                                    l_vrt.vrtHeader.fields.type,
                                    l_vrt.vrtHeader.fields.content,
                                    l_vrt.vrtHeader.fields.io_id,
                                    l_vrt.vrtHeader.fields.ac_id,
                                    l_vrt.vrtHeader.fields.vcs_ceff_id,
                                    l_vrt.vrtHeader.fields.vdd_ceff_id
                                    );

                            l_index += sizeof (l_vrt);
                        }
                    }
                }
            }
            io_size = l_index;
            FAPI_DBG("Static io_size = %d", io_size);
        }
        else
        {
            FAPI_DBG("ATTR_SYS_VRT_STATIC_DATA_ENABLE is not SET");
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_SYSTEM_WOF_VALIDATION_MODE, FAPI_SYSTEM, l_wof_mode));

            // Read System VRT data
            l_rc = FAPI_ATTR_GET(fapi2::ATTR_WOF_TABLE_DATA,
                    iv_procChip,
                    (*l_wof_table_data));
            if (l_rc)
            {

                FAPI_INF("Pstate Parameter Block ATTR_WOF_TABLE_DATA attribute failed.  Disabling WOF");
                iv_wof_enabled = false;

                // Write the returned error content to the error log
                fapi2::logError(l_rc,fapi2::FAPI2_ERRL_SEV_UNRECOVERABLE);
                break;
            }
        }

        // Copy WOF header data
        memcpy (o_buf, (*l_wof_table_data), sizeof(WofTablesHeader_t));
        uint32_t l_wof_table_index = sizeof(WofTablesHeader_t);
        uint32_t l_index = sizeof(WofTablesHeader_t);

        //Validate WOF header part
        WofTablesHeader_t* p_wfth;
        p_wfth = reinterpret_cast<WofTablesHeader_t*>(o_buf);

        wfth_print(p_wfth);

        bool l_wof_header_data_state = 1;
        VALIDATE_WOF_HEADER_DATA(
                p_wfth->magic_number.value,
                p_wfth->header_version,
                p_wfth->vrt_block_size,
                p_wfth->vrt_block_header_size,
                p_wfth->vrt_data_size,
                p_wfth->core_count,
                p_wfth->vcs_start,
                p_wfth->vcs_step,
                p_wfth->vcs_size,
                l_wof_header_data_state);

        if (l_wof_header_data_state)
        {
            VALIDATE_WOF_HEADER_DATA(
                    p_wfth->vdd_start,
                    p_wfth->vdd_step,
                    p_wfth->vdd_size,
                    p_wfth->io_start,
                    p_wfth->io_step,
                    p_wfth->io_size,
                    p_wfth->amb_cond_start,
                    p_wfth->amb_cond_step,
                    p_wfth->amb_cond_size,
                    l_wof_header_data_state);
        }

        if (!l_wof_header_data_state)
        {
            iv_wof_enabled = false;
            if (l_wof_mode == fapi2::ENUM_ATTR_SYSTEM_WOF_VALIDATION_MODE_INFO)
            {
                FAPI_INF("Pstate Parameter Block WOF Header validation failed");
            }
            else
            {
                FAPI_ASSERT_NOEXIT(false,
                        fapi2::PSTATE_PB_WOF_HEADER_DATA_INVALID(fapi2::FAPI2_ERRL_SEV_RECOVERED)
                        .set_CHIP_TARGET(FAPI_SYSTEM)
                        .set_MAGIC_NUMBER(p_wfth->magic_number.value)
                        .set_VERSION(p_wfth->header_version)
                        .set_VRT_BLOCK_SIZE(p_wfth->vrt_block_size)
                        .set_VRT_HEADER_SIZE(p_wfth->vrt_block_header_size)
                        .set_VRT_DATA_SIZE(p_wfth->vrt_data_size)
                        .set_CORE_COUNT(p_wfth->core_count)
                        .set_VCS_START(p_wfth->vcs_start)
                        .set_VCS_STEP(p_wfth->vcs_step)
                        .set_VCS_SIZE(p_wfth->vcs_size)
                        .set_VDD_START(p_wfth->vdd_start)
                        .set_VDD_STEP(p_wfth->vdd_step)
                        .set_VDD_SIZE(p_wfth->vdd_size)
                        .set_IO_START(p_wfth->io_start)
                        .set_IO_STEP(p_wfth->io_step)
                        .set_IO_SIZE(p_wfth->io_size)
                        .set_AMB_COND_START(p_wfth->amb_cond_start)
                        .set_AMB_COND_STEP(p_wfth->amb_cond_step)
                        .set_AMB_COND_SIZE(p_wfth->amb_cond_size),
                    "Pstate Parameter Block WOF Header validation failed");
                break;
            }

        }

        l_vcs_size = revle16(p_wfth->vcs_size);
        l_vdd_size = revle16(p_wfth->vdd_size);
        l_io_size  = revle16(p_wfth->io_size);
        l_ac_size  = revle16(p_wfth->amb_cond_size);

        uint32_t l_total_index = l_vcs_size * l_vdd_size * l_io_size * l_ac_size;

        FAPI_INF("WOF: vcs_size %02d, vdd_size %02d io_size %02d, ac_size %02d",
                        l_vcs_size, l_vdd_size, l_io_size,l_ac_size);
        FAPI_INF("WOF: total_index  %02d", l_total_index);

        // Convert system vrt to homer vrt
        for (uint32_t vrt_index = 0;
                vrt_index < l_total_index;
                ++vrt_index)
        {
            FAPI_DBG ("l_wof_table_index %d vrt_index %d", l_wof_table_index, vrt_index);
            FAPI_DBG("Addresses: *l_wof_table_data %p  *l_wof_table_data+l_wof_table_index %p",
                    *l_wof_table_data,  (*l_wof_table_data) + l_wof_table_index);

            l_rc = update_vrt (
                    ((*l_wof_table_data) + l_wof_table_index),
                    &l_vrt
                    );
            if (l_rc)
            {
                iv_wof_enabled = false;
                FAPI_TRY(l_rc);  // Exit the function as a fail
            }

            FAPI_DBG("VRT post update: index %04d  l_vrt fields marker %X io %01d ac %01d vc %02d vd %02d",
                    l_wof_table_index,
                    l_vrt.vrtHeader.fields.marker,
                    l_vrt.vrtHeader.fields.io_id,
                    l_vrt.vrtHeader.fields.ac_id,
                    l_vrt.vrtHeader.fields.vcs_ceff_id,
                    l_vrt.vrtHeader.fields.vdd_ceff_id
                    );

            // Check for "V" at the start of the magic number

            if (l_vrt.vrtHeader.fields.marker != 0x56)
            {
                FAPI_ERR("Marker: %X", l_vrt.vrtHeader.fields.marker);
                iv_wof_enabled = false;
                FAPI_ASSERT_NOEXIT(false,
                        fapi2::PSTATE_PB_VRT_HEADER_DATA_INVALID(fapi2::FAPI2_ERRL_SEV_RECOVERED)
                        .set_CHIP_TARGET(FAPI_SYSTEM)
                        .set_MAGIC_NUMBER(l_vrt.vrtHeader.fields.marker)
                        .set_VRT_INDEX(vrt_index),
                        "Pstate Parameter Block: Invalid VRT Magic word");
                break;
            }
            l_vrt.vrtHeader.value = revle32(l_vrt.vrtHeader.value);
            l_wof_table_index += sizeof (l_vrt);

            memcpy(o_buf + l_index, &l_vrt, sizeof (l_vrt));
            l_index += sizeof (l_vrt);
        }

        io_size = l_index;
        FAPI_DBG("Converted io_size = %d", io_size);

    } while(0);

    // This is for the case that the magic number didn't match and we don't
    // want to fail;  rather, we just disable WOF.
    fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;

    // Check the validity of some PoundW fields
    FAPI_INF("Checking validity of #W.  DCC = 0x%016X", revle64(iv_poundW_data.other.droop_count_control));
    if (iv_poundW_data.other.droop_count_control == 0)
    {

        FAPI_ERR("#W DCCR is 0. Disabling Over-Current Sensor, Undervolting and Overvolting");
        iv_ocs_enabled = false;
        iv_wov_underv_enabled = false;
        iv_wov_overv_enabled = false;

        if (is_wof_enabled())
        {
            FAPI_ERR("WARNING: WOF is enabled with Over-Current Sensor disabled!");
        }

        const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;
        fapi2::ATTR_SYSTEM_PDV_VALIDATION_MODE_Type l_sys_pdw_mode;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_SYSTEM_PDW_VALIDATION_MODE, FAPI_SYSTEM,l_sys_pdw_mode));
        if (l_sys_pdw_mode == fapi2::ENUM_ATTR_SYSTEM_PDW_VALIDATION_MODE_INFO)
        {
            FAPI_ASSERT_NOEXIT(false,
                    fapi2::PSTATE_PB_ZERO_DCCR(fapi2::FAPI2_ERRL_SEV_RECOVERED)
                    .set_CHIP_TARGET(iv_procChip),
                    "Pstate Parameter Block: #W DCCR has value of 0");
        }
        else if (l_sys_pdw_mode == fapi2::ENUM_ATTR_SYSTEM_PDW_VALIDATION_MODE_WARN)
        {
            FAPI_ERR("WARNING: #W DCCR has value of 0");
        }
        else if (l_sys_pdw_mode == fapi2::ENUM_ATTR_SYSTEM_PDW_VALIDATION_MODE_FAIL)
        {
            FAPI_ASSERT(false,
                    fapi2::PSTATE_PB_ZERO_DCCR()
                    .set_CHIP_TARGET(iv_procChip),
                    "Pstate Parameter Block: #W DCCR has value of 0");
        }
    }

fapi_try_exit:
    if (l_wof_table_data)
    {
        delete[] l_wof_table_data;
        l_wof_table_data = nullptr;
    }

    FAPI_DBG("<< WOF initialization");
    return fapi2::current_err;
}
///////////////////////////////////////////////////////////
////////    set_global_feature_attributes
///////////////////////////////////////////////////////////
fapi2::ReturnCode PlatPmPPB::set_global_feature_attributes()
{

    fapi2::ATTR_PSTATES_ENABLED_Type l_ps_enabled =
        (fapi2::ATTR_PSTATES_ENABLED_Type)fapi2::ENUM_ATTR_PSTATES_ENABLED_FALSE;

    fapi2::ATTR_RESCLK_ENABLED_Type l_resclk_enabled =
        (fapi2::ATTR_RESCLK_ENABLED_Type)fapi2::ENUM_ATTR_RESCLK_ENABLED_FALSE;

    fapi2::ATTR_DDS_ENABLED_Type l_dds_enabled =
        (fapi2::ATTR_DDS_ENABLED_Type)fapi2::ENUM_ATTR_DDS_ENABLED_FALSE;

    fapi2::ATTR_WOF_ENABLED_Type l_wof_enabled =
        (fapi2::ATTR_WOF_ENABLED_Type)fapi2::ENUM_ATTR_WOF_ENABLED_FALSE;

    fapi2::ATTR_RVRM_ENABLED_Type l_rvrm_enabled =
        (fapi2::ATTR_RVRM_ENABLED_Type)fapi2::ENUM_ATTR_RVRM_ENABLED_FALSE;

// RTC 247962:need to revisit
#if 0
    fapi2::ATTR_WOV_UNDERV_ENABLED_Type l_wov_underv_enabled =
        (fapi2::ATTR_WOV_UNDERV_ENABLED_Type)fapi2::ENUM_ATTR_WOV_UNDERV_ENABLED_FALSE;

    fapi2::ATTR_WOV_OVERV_ENABLED_Type l_wov_overv_enabled =
        (fapi2::ATTR_WOV_OVERV_ENABLED_Type)fapi2::ENUM_ATTR_WOV_OVERV_ENABLED_FALSE;


      //Check whether to enable WOV Undervolting. WOV can
      //only be enabled if DDSs are enabled
      if (!is_wov_underv_enabled() ||
          !is_dds_enabled())
      {
          FAPI_DBG("UNDERV_DISABLED")
          iv_wov_underv_enabled = false;
      }

      //Check whether to enable WOV Overvolting. WOV can
      //only be enabled if VDMs are enabled
      if (!is_wov_overv_enabled() ||
          !is_dds_enabled())
      {
          FAPI_DBG("OVERV_DISABLED")
          iv_wov_overv_enabled = false;
      }
#endif

    if (iv_pstates_enabled)
    {
        l_ps_enabled = (fapi2::ATTR_PSTATES_ENABLED_Type)fapi2::ENUM_ATTR_PSTATES_ENABLED_TRUE;
    }

    if (iv_resclk_enabled)
    {
        l_resclk_enabled = (fapi2::ATTR_RESCLK_ENABLED_Type)fapi2::ENUM_ATTR_RESCLK_ENABLED_TRUE;
    }

    if (iv_dds_enabled)
    {
        l_dds_enabled = (fapi2::ATTR_DDS_ENABLED_Type)fapi2::ENUM_ATTR_DDS_ENABLED_TRUE;
    }

    if (iv_rvrm_enabled)
    {
        l_rvrm_enabled = (fapi2::ATTR_RVRM_ENABLED_Type)fapi2::ENUM_ATTR_RVRM_ENABLED_TRUE;
    }

    if (iv_wof_enabled)
    {
        l_wof_enabled = (fapi2::ATTR_WOF_ENABLED_Type)fapi2::ENUM_ATTR_WOF_ENABLED_TRUE;
    }

#if 0
    if (iv_wov_underv_enabled)
    {
        l_wov_underv_enabled = (fapi2::ATTR_WOV_UNDERV_ENABLED_Type)fapi2::ENUM_ATTR_WOV_UNDERV_ENABLED_TRUE;
    }

    if (iv_wov_overv_enabled)
    {
        l_wov_overv_enabled = (fapi2::ATTR_WOV_OVERV_ENABLED_Type)fapi2::ENUM_ATTR_WOV_OVERV_ENABLED_TRUE;
    }
#endif



    SET_ATTR(fapi2::ATTR_PSTATES_ENABLED, iv_procChip, l_ps_enabled);
    SET_ATTR(fapi2::ATTR_RESCLK_ENABLED, iv_procChip, l_resclk_enabled);
    SET_ATTR(fapi2::ATTR_DDS_ENABLED, iv_procChip, l_dds_enabled);
    SET_ATTR(fapi2::ATTR_RVRM_ENABLED, iv_procChip, l_rvrm_enabled);
    SET_ATTR(fapi2::ATTR_WOF_ENABLED, iv_procChip, l_wof_enabled);
//    SET_ATTR(fapi2::ATTR_WOV_UNDERV_ENABLED, iv_procChip, l_wov_underv_enabled);
  //  SET_ATTR(fapi2::ATTR_WOV_OVERV_ENABLED, iv_procChip, l_wov_overv_enabled);


fapi_try_exit:
    return fapi2::current_err;
}
///////////////////////////////////////////////////////////
////////  pm_set_frequency
///////////////////////////////////////////////////////////
fapi2::ReturnCode PlatPmPPB::pm_set_frequency()
{
    FAPI_INF("PlatPmPPB::pm_set_frequency >>>>>");

    voltageBucketData_t l_poundV_data;
    uint16_t l_fmax_freq;
    uint16_t l_ut_freq;
    uint16_t l_psav_freq;
    uint16_t l_wofbase_freq;
    uint8_t l_sys_pdv_mode;
    uint16_t l_tmp_psav_freq = 0;
    uint16_t l_tmp_ceil_freq = 0;
    fapi2::ATTR_FREQ_SYSTEM_CORE_FLOOR_MHZ_Type l_sys_freq_core_floor_mhz;
    fapi2::ATTR_FREQ_SYSTEM_CORE_CEILING_MHZ_Type l_sys_freq_core_ceil_mhz;
    fapi2::ATTR_FREQ_CORE_FLOOR_MHZ_Type l_floor_freq_mhz;
    fapi2::ATTR_FREQ_CORE_CEILING_MHZ_Type l_ceil_freq_mhz;

    fapi2::ATTR_CHIP_EC_FEATURE_DD1_LIMITED_FREQUENCY_Type l_limited_freq_mhz;
    const fapi2::ATTR_FREQ_CORE_CEILING_MHZ_Type l_forced_ceil_freq_mhz = 2400;

    do
    {
        auto sys_target = iv_procChip.getParent<fapi2::TARGET_TYPE_SYSTEM>();

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_FREQ_SYSTEM_CORE_FLOOR_MHZ,
                sys_target,l_sys_freq_core_floor_mhz));

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_FREQ_SYSTEM_CORE_CEILING_MHZ,
                sys_target,l_sys_freq_core_ceil_mhz));

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_SYSTEM_PDV_VALIDATION_MODE,
                sys_target, l_sys_pdv_mode));

        //If pstate0 freq is set means, we have already computed other
        //frequencies (floor and ceil) as well
        if (iv_attrs.attr_pstate0_freq_mhz)
        {
            FAPI_INF("PSTATE0 FREQ is already set %08X", iv_attrs.attr_pstate0_freq_mhz);
            break;
        }

        //We loop thru all the processor in the system and will figure out the
        //max of PSAV, FMAX, and UT in that list.  We look for the min of the WOFBase
        //values.  An attribute switch is used to specifically fail the WOFBase check.
        // - Max value of FMAX will be initialized to ATTR_SYSTEM_PSTATE0_FREQ_MHZ
        //   and same value will be initialized to ATTR_FREQ_SYSTEM_CORE_CEIL_MHZ
        // - Max value of PSAV will be initialized to ATTR_FREQ_SYSTEM_CORE_FLOOR_MHZ
        // - Min value of WOFBae will be initialized to ATTR_NOMINAL_FREQ_MHZ
        iv_attrs.attr_pstate0_freq_mhz = 0;
        for (auto l_proc_target : sys_target.getChildren<fapi2::TARGET_TYPE_PROC_CHIP>())
        {

            // Enforce the attribute derived ceiling
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_EC_FEATURE_DD1_LIMITED_FREQUENCY,
                        l_proc_target,l_limited_freq_mhz));
            //This part of the code will enable later, because we are seeing CEIL and
            //FLOOR frequency are set from the MRW to 2000MHZ, But for now we
            //should force the ceil freq to 2400MHZ to make OCC happy
            // Will comeback to this once we sort out, why and how MRW are
            // gettting the ceil and floor values
#if 0
            if (l_limited_freq_mhz)
            {
                if ((l_sys_freq_core_ceil_mhz) &&
                    (l_sys_freq_core_ceil_mhz > l_forced_ceil_freq_mhz))
                {
                    l_sys_freq_core_ceil_mhz = l_forced_ceil_freq_mhz;
                }
                else if (!l_sys_freq_core_ceil_mhz)
                {
                    l_sys_freq_core_ceil_mhz = l_forced_ceil_freq_mhz;
                }
                FAPI_INF("Limited frequency DD level.  Capping to %04d MHz", l_sys_freq_core_ceil_mhz);
            }
#endif
            if (l_limited_freq_mhz)
            {
                l_sys_freq_core_ceil_mhz = l_forced_ceil_freq_mhz;
            }


            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_FREQ_CORE_FLOOR_MHZ,
                        l_proc_target,l_floor_freq_mhz));

            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_FREQ_CORE_CEILING_MHZ,
                        l_proc_target,l_ceil_freq_mhz));
            uint8_t l_poundv_static_data = 0;
            const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_POUND_V_STATIC_DATA_ENABLE,
                        FAPI_SYSTEM,
                        l_poundv_static_data),
                    "Error from FAPI_ATTR_GET for attribute ATTR_POUND_V_STATIC_DATA_ENABLE");

            if (l_poundv_static_data)
            {
                FAPI_INF("attribute ATTR_POUND_V_STATIC_DATA_ENABLE is set");
                memcpy(&l_poundV_data,&g_vpd_PVData,sizeof(g_vpd_PVData));
            }
            else
            {
                //Read #V data from each proc
                FAPI_TRY(p10_pm_get_poundv_bucket(l_proc_target, l_poundV_data));
            }

            l_fmax_freq     = revle16(l_poundV_data.other_info.VddFmxCoreFreq);
            l_ut_freq       = revle16(l_poundV_data.other_info.VddUTCoreFreq);
            l_psav_freq     = revle16(l_poundV_data.other_info.VddPsavCoreFreq);
            l_wofbase_freq  = revle16(l_poundV_data.other_info.VddTdpWofCoreFreq);
            FAPI_INF("VPD fmax_freq=%04d, ut_freq=%04d  psav_freq=%04d, psav_freq=%04d",
                    l_fmax_freq, l_ut_freq, l_wofbase_freq, l_psav_freq);

            //Compute floor freq
            if (!l_tmp_psav_freq)
            {
                l_tmp_psav_freq = l_psav_freq;
            }
            else
            {
                if (l_psav_freq >= l_tmp_psav_freq)
                {
                    l_tmp_psav_freq = l_psav_freq;
                }
                if ( l_floor_freq_mhz >= l_tmp_psav_freq)
                {
                    l_tmp_psav_freq = l_floor_freq_mhz;
                }
            }

            //If the system core floor freq is greater then of psav(of all the
            //procs) then need to update system core floor freq
            FAPI_DBG("floor frequency check:   sys %04d ceil %04d",
                    l_sys_freq_core_floor_mhz, l_floor_freq_mhz);

            if ( l_sys_freq_core_floor_mhz > l_tmp_psav_freq)
            {
                l_tmp_psav_freq = l_sys_freq_core_floor_mhz;
            }
            else if (!l_sys_freq_core_floor_mhz)
            {
                l_sys_freq_core_floor_mhz = l_tmp_psav_freq;
            }

            //Compute FMAX and Ceil freq
            if ( l_fmax_freq > iv_attrs.attr_pstate0_freq_mhz && iv_attrs.attr_fmax_enable == 1)
            {
                iv_attrs.attr_pstate0_freq_mhz = l_fmax_freq;
            }
            else if ( l_fmax_freq == 0  || iv_attrs.attr_fmax_enable == 0)
            {
                if (l_ut_freq > iv_attrs.attr_pstate0_freq_mhz ||
                        iv_attrs.attr_pstate0_freq_mhz == 0)
                {
                    iv_attrs.attr_pstate0_freq_mhz = l_ut_freq;
                }
                else
                {
                    if (l_ut_freq != iv_attrs.attr_pstate0_freq_mhz)
                    {
                        if (l_sys_pdv_mode == fapi2::ENUM_ATTR_SYSTEM_PDV_VALIDATION_MODE_INFO)
                        {
                            FAPI_ASSERT_NOEXIT(false,
                                    fapi2::PSTATE_PB_UT_PSTATE0_FREQ_MISMATCH(fapi2::FAPI2_ERRL_SEV_RECOVERED)
                                    .set_CHIP_TARGET(iv_procChip)
                                    .set_UT_FREQ(l_ut_freq)
                                    .set_PSTATE0_FREQ(iv_attrs.attr_pstate0_freq_mhz),
                                    "Pstate Parameter Block WOF Biased #V CF6 error being logged");
                        }
                        else if (l_sys_pdv_mode == fapi2::ENUM_ATTR_SYSTEM_PDV_VALIDATION_MODE_WARN)
                        {
                            FAPI_ERR("PSTATE0 freq %08x is not equal to UT Freq %08x",iv_attrs.attr_pstate0_freq_mhz,l_ut_freq);
                        }
                        else if (l_sys_pdv_mode == fapi2::ENUM_ATTR_SYSTEM_PDV_VALIDATION_MODE_FAIL)
                        {
                            FAPI_ASSERT(false,
                                    fapi2::PSTATE_PB_UT_PSTATE0_FREQ_MISMATCH()
                                    .set_CHIP_TARGET(iv_procChip)
                                    .set_UT_FREQ(l_ut_freq)
                                    .set_PSTATE0_FREQ(iv_attrs.attr_pstate0_freq_mhz),
                                    "Pstate Parameter Block WOF Biased #V CF6 error being logged");
                        }
                    }
                }
            }

            l_tmp_ceil_freq = l_ceil_freq_mhz;
            if ( iv_attrs.attr_pstate0_freq_mhz > l_ceil_freq_mhz)
            {
                l_tmp_ceil_freq = iv_attrs.attr_pstate0_freq_mhz;
            }
            FAPI_DBG("temp ceiling %04d MHz (0x%X)", l_tmp_ceil_freq, l_tmp_ceil_freq );

            //If the system core ceiling freq is less then of Pstate0 (of all the
            //procs) then need to update system core ceiling freq
            FAPI_DBG("ceiling frequency check:  sys %04d ceil %04d", l_sys_freq_core_ceil_mhz, l_tmp_ceil_freq);
            if ( (l_sys_freq_core_ceil_mhz != 0) && l_sys_freq_core_ceil_mhz < l_tmp_ceil_freq)
            {
                l_tmp_ceil_freq = l_sys_freq_core_ceil_mhz;
            }

            //Compute WOFBase (minumim across chips)
            if (l_wofbase_freq > iv_attrs.attr_nominal_freq_mhz &&
                    iv_attrs.attr_nominal_freq_mhz == 0)
            {
                iv_attrs.attr_nominal_freq_mhz = l_wofbase_freq;
            }
            else
            {
                if (l_wofbase_freq != iv_attrs.attr_nominal_freq_mhz)
                {
                    FAPI_INF("Present System WOF Base freq %04d is not equal to this chip's WOF Base Freq %04d",
                            revle32(iv_attrs.attr_nominal_freq_mhz), l_wofbase_freq);
                    // This does not produce an error log as the system will operate ok
                    // for this case.
                }

                if ( l_wofbase_freq < iv_attrs.attr_nominal_freq_mhz)
                {
                    iv_attrs.attr_nominal_freq_mhz = l_wofbase_freq;
                }
            }

            FAPI_DBG("nominal_freq %04d (%04X)",
                    iv_attrs.attr_nominal_freq_mhz, iv_attrs.attr_nominal_freq_mhz);

            if (l_sys_freq_core_ceil_mhz < iv_attrs.attr_nominal_freq_mhz)
            {
                iv_attrs.attr_nominal_freq_mhz = l_sys_freq_core_ceil_mhz;
                FAPI_INF("Clipping the nominal frequency to the ceiling frequency:  %04d ",
                        iv_attrs.attr_nominal_freq_mhz);
            }

            if (l_sys_freq_core_floor_mhz > iv_attrs.attr_nominal_freq_mhz)
            {
                iv_attrs.attr_nominal_freq_mhz = l_sys_freq_core_floor_mhz;
                FAPI_INF("Raising the nominal frequency to the floor frequency:  %04d ",
                        iv_attrs.attr_nominal_freq_mhz);
            }

        } //end of proc list

        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_SYSTEM_PSTATE0_FREQ_MHZ, sys_target,iv_attrs.attr_pstate0_freq_mhz));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_NOMINAL_FREQ_MHZ, sys_target, iv_attrs.attr_nominal_freq_mhz));

        l_floor_freq_mhz = l_tmp_psav_freq;
        l_ceil_freq_mhz = l_tmp_ceil_freq;

        iv_attrs.attr_freq_core_ceiling_mhz = l_ceil_freq_mhz;
        FAPI_INF("Computed ceiling frequency: %04d (0x%04x)", l_ceil_freq_mhz, l_ceil_freq_mhz);
        FAPI_INF("Computed floor frequency: %04d (0x%04x)", l_sys_freq_core_floor_mhz, l_sys_freq_core_floor_mhz);

        //Update system ceil and floor freq
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_FREQ_SYSTEM_CORE_CEILING_MHZ, sys_target,l_ceil_freq_mhz));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_FREQ_SYSTEM_CORE_FLOOR_MHZ, sys_target,l_sys_freq_core_floor_mhz));

        for (auto l_proc_target : sys_target.getChildren<fapi2::TARGET_TYPE_PROC_CHIP>())
        {
            FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_FREQ_CORE_CEILING_MHZ, l_proc_target,l_ceil_freq_mhz));
            FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_FREQ_CORE_FLOOR_MHZ, l_proc_target,l_floor_freq_mhz));
        }
    }
    while(0);
fapi_try_exit:
    FAPI_INF("PlatPmPPB::pm_set_frequency <<<<<<<");
    return fapi2::current_err;
}
// *INDENT-ON*
