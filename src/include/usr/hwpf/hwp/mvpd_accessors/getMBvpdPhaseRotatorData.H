/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/hwpf/hwp/mvpd_accessors/getMBvpdPhaseRotatorData.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2014              */
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
// $Id: getMBvpdPhaseRotatorData.H,v 1.8 2013/11/08 18:13:43 whs Exp $

/**
 *  @file getMBvpdPhaseRotatorData.H
 *
 *  @brief Prototype for getMBvpdPhaseRotatorData() -
 *          get Phase Rotator Data from MBvpd
 */

#ifndef    _HWP_MVPDPHASERATORDATA_
#define    _HWP_MVPDPHASERATORDATA_

#include   <fapi.H>

namespace fapi
{
// The MBvpdPhaseRotatorData enumeration is used on the FAPI_ATTR_GET and
// getMBvpdPhaseRotatorData HWP accessor interface. The lower byte (6 bits)
// matches the offset of the vpd field in the MR keyword. This is a convenient
// use of the value for efficiency to index into the vpd keyword data.
//
// Most of the attributes are byte values and can be returned to the requester
// directly. There are some that require special processing. For those, a
// special processing flag is added into the value. This also distinguishes
// values which have the same offset.

// special processing flags to be added on to the MBvpdPhaseRotatorData value
    enum MBvpdPhaseRotatorSpecial
    {
        PHASE_ROT_HIGH_NIBBLE = 0x0100, //bits 0:3 of MSB 0 to LSB 7
                                        //  shifted right 4
        PHASE_ROT_LOW_NIBBLE  = 0x0200, //bits 4:7 of MSB 0 to LSB 7
        PHASE_ROT_PORT00=0x0300, // return vpd port 0 value for 0 and 1
        PHASE_ROT_PORT11=0x0400, // return vpd port 1 value for 0 and 1
    };
// mask to isolate special processing flags
const uint16_t PHASE_ROT_SPECIAL_MASK = 0x0700;

// The offset changed for some of the attributes going from v5.3 of the vpd
// layout to v6.0 and after. There is a work around to use the proper offset
// based on the version
// Flag to be added into MBvpdPhaseRotatorData value for attributes that need
// to be checked for the work around.
const uint8_t  PHASE_ROT_CHK60 = 0x40;  // check version for offset to use

// base values match offset into MR keyword data
    enum MBvpdPhaseRotatorData
    {
        PHASE_ROT_M0_CLK_P0 = 0x00,
        PHASE_ROT_M0_CLK_P1 = 0x01,
        PHASE_ROT_M1_CLK_P0 = 0x02,
        PHASE_ROT_M1_CLK_P1 = 0x03,
        PHASE_ROT_M_CMD_A0 = 0x04,
        PHASE_ROT_M_CMD_A1 = 0x05,
        PHASE_ROT_M_CMD_A2 = 0x06,
        PHASE_ROT_M_CMD_A3 = 0x07,
        PHASE_ROT_M_CMD_A4 = 0x08,
        PHASE_ROT_M_CMD_A5 = 0x09,
        PHASE_ROT_M_CMD_A6 = 0x0a,
        PHASE_ROT_M_CMD_A7 = 0x0b,
        PHASE_ROT_M_CMD_A8 = 0x0c,
        PHASE_ROT_M_CMD_A9 = 0x0d,
        PHASE_ROT_M_CMD_A10 = 0x0e,
        PHASE_ROT_M_CMD_A11 = 0xf,
        PHASE_ROT_M_CMD_A12 = 0x10,
        PHASE_ROT_M_CMD_A13 = 0x11,
        PHASE_ROT_M_CMD_A14 = 0x12,
        PHASE_ROT_M_CMD_A15 = 0x13,
        PHASE_ROT_M_CMD_BA0 = 0x14,
        PHASE_ROT_M_CMD_BA1 = 0x15,
        PHASE_ROT_M_CMD_BA2 = 0x16,
        PHASE_ROT_M_CMD_CASN = 0x17,
        PHASE_ROT_M_CMD_RASN = 0x18,
        PHASE_ROT_M_CMD_WEN = 0x19,
        PHASE_ROT_M_PAR = 0x1a,
        PHASE_ROT_M_ACTN = 0x1b,
        PHASE_ROT_M0_CNTL_CKE0 = 0x1c,
        PHASE_ROT_M0_CNTL_CKE1 = 0x1d,
        PHASE_ROT_M0_CNTL_CKE2 = 0x1e,
        PHASE_ROT_M0_CNTL_CKE3 = 0x1f,
        PHASE_ROT_M0_CNTL_CSN0 = 0x20,
        PHASE_ROT_M0_CNTL_CSN1 = 0x21,
        PHASE_ROT_M0_CNTL_CSN2 = 0x22,
        PHASE_ROT_M0_CNTL_CSN3 = 0x23,
        PHASE_ROT_M0_CNTL_ODT0 = 0x24,
        PHASE_ROT_M0_CNTL_ODT1 = 0x25,
        PHASE_ROT_M1_CNTL_CKE0 = 0x26,
        PHASE_ROT_M1_CNTL_CKE1 = 0x27,
        PHASE_ROT_M1_CNTL_CKE2 = 0x28,
        PHASE_ROT_M1_CNTL_CKE3 = 0x29,
        PHASE_ROT_M1_CNTL_CSN0 = 0x2a,
        PHASE_ROT_M1_CNTL_CSN1 = 0x2b,
        PHASE_ROT_M1_CNTL_CSN2 = 0x2c,
        PHASE_ROT_M1_CNTL_CSN3 = 0x2d,
        PHASE_ROT_M1_CNTL_ODT0 = 0x2e,
        PHASE_ROT_M1_CNTL_ODT1 = 0x2f,
        PHASE_ROT_DRAM_2N_MODE = 0x30,
        PHASE_ROT_TSYS_ADR  = 0x31 | PHASE_ROT_CHK60 | PHASE_ROT_PORT00,
        PHASE_ROT_TSYS_DP18 = 0x31 | PHASE_ROT_CHK60 | PHASE_ROT_PORT11,
// Use these offsets for vpd less than version 6.0
        PHASE_ROT_RLO_V53 = 0x31 | PHASE_ROT_LOW_NIBBLE,
        PHASE_ROT_WLO_V53 = 0x31 | PHASE_ROT_HIGH_NIBBLE,
        PHASE_ROT_GPO_V53= 0x32,
        PHASE_ROT_TSYS_ADR_V53  = 0x33 | PHASE_ROT_PORT00,
        PHASE_ROT_TSYS_DP18_V53 = 0x33 | PHASE_ROT_PORT11,
        // invalid value
        PHASE_ROT_INVALID = 0x3f,
    };
}
// The max base offset value is 0x3e. The MR keyword is 255 bytes.
// There is only room for 63 attributes per port. There are 4 x  64 byte
// sections, but the last one is 1 byte short. See diagram below...
const uint8_t PHASE_ROT_OFFSET_MASK = 0x003f; // mask attr to isolate base
                                              // vpd offsetk

// function pointer typedef definition for HWP call support
typedef fapi::ReturnCode (*getMBvpdPhaseRotatorData_FP_t)
     (const fapi::Target &, const fapi::MBvpdPhaseRotatorData,
      uint8_t (&)[2]);


extern "C"
{
/**
 * @brief   get Phase Rotator Data from cvpd record VSPD keyword MR
 *
 * There are Phase Rotator attributes for the mba's 2 ports in cvpd
 * record VSPD keyword MR. Each attribute has 2 bytes, one for each port.
 * There are two mba per memory buffer, position 0 and position 1.
 * The Termination Data attributes are retrieved from cvpd record VSPD
 * keyword MT.
 *
 * cpvd record VSPD keyword MR
 * -----------------------------------
 * | mba position 0                  |
 * |  -----------------------------  |
 * |  | port 0  (Port A) 64 bytes |  |
 * |  |---------------------------|  |
 * |  | port 1  (Port B) 64 bytes |  |
 * |  -----------------------------  |
 * |---------------------------------|
 * | mba postion 1                   |
 * |  -----------------------------  |
 * |  | port 0  (Port C) 64 bytes |  |
 * |  |---------------------------|  |
 * |  | port 1  (Port D) 63 bytes |  |
 * |  -----------------------------  |
 * -----------------------------------
 *
 * @param i_mbaTarget       -   mba target
 * @param i_attr            -   Phase Rotator Data attribute enumerator
 * @param o_val             -   Phase Rotator Data for each of the 2 ports
 *                              [0] port A (position 0) Port C (position 1)
 *                              [1] port B (position 0) Port D (position 1)
 *
 * @return fapi::ReturnCode -   FAPI_RC_SUCCESS if success,
 *                              relevant error code for failure.
 */
fapi::ReturnCode getMBvpdPhaseRotatorData(
                              const        fapi::Target &i_mbaTarget,
                              const        fapi::MBvpdPhaseRotatorData i_attr,
                              uint8_t      (&o_val)[2]);

}

#endif
