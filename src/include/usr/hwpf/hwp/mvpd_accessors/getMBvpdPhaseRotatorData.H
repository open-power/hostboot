/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/hwpf/hwp/mvpd_accessors/getMBvpdPhaseRotatorData.H $ */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2013              */
/*                                                                        */
/* p1                                                                     */
/*                                                                        */
/* Object Code Only (OCO) source materials                                */
/* Licensed Internal Code Source Materials                                */
/* IBM HostBoot Licensed Internal Code                                    */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* Origin: 30                                                             */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
// $Id: getMBvpdPhaseRotatorData.H,v 1.2 2013/04/29 16:48:15 whs Exp

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

// values match offset into MR keyword data
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
// The max value is 0x3f. The MR keyword is 255 bytes. There is only room for
// 63 attributes per port. There are 4 x  64 byte sections,
// but the last one is 1 byte short.
    };
}

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
