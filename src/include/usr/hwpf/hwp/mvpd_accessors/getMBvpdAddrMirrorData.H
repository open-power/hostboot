/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/hwpf/hwp/mvpd_accessors/getMBvpdAddrMirror.H $ */
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
// $Id$

/**
 *  @file getMBvpdAddrMirror.H
 *
 *  @brief Prototype for getMBvpdAddrMirror() -
 *          get Address Mirroring Data from MBvpd
 */

#ifndef    _HWP_MBVPDADDRMIRRORDATA_
#define    _HWP_MBVPDADDRMIRRORDATA_

#include   <fapi.H>

// function pointer typedef definition for HWP call support
typedef fapi::ReturnCode (*getMBvpdAddrMirrorData_FP_t)
     (const fapi::Target &, uint8_t (&) [2][2]);

extern "C"
{
/**
 * @brief get Address Mirroring Data from cvpd record VSPD keyword AM
 *
 * The Address Mirroring Data attributes are retrieved from cvpd record VSPD
 * keyword AM.
 * There are two mba per memory buffer: position 0 and position 1.
 * There are two ports for each mba and 2 DIMMs per port.
 *
 * cpvd record VSPD keyword AM - 4 bytes
 * -----------------------------------
 * | mba position 0                  |
 * |  -----------------------------  |
 * |  | port 0  (Port A)          |  |
 * |  |  ------------------------ |  |
 * |  |  | DIMM 0 :  4 bits     | |  |
 * |  |  ------------------------ |  |
 * |  |  | DIMM 1 :  4 bits     | |  |
 * |  |  ------------------------ |  |
 * |  |---------------------------|  |
 * |  | port 1  (Port B)          |  |
 * |  |  ------------------------ |  |
 * |  |  | DIMM 0 :  4 bits     | |  |
 * |  |  ------------------------ |  |
 * |  |  | DIMM 1 :  4 bits     | |  |
 * |  |  ------------------------ |  |
 * |  -----------------------------  |
 * |---------------------------------|
 * | mba postion 1                   |
 * |  -----------------------------  |
 * |  | port 0  (Port C)          |  |
 * |  |  ------------------------ |  |
 * |  |  | DIMM 0 :  4 bits     | |  |
 * |  |  ------------------------ |  |
 * |  |  | DIMM 1 :  4 bits     | |  |
 * |  |  ------------------------ |  |
 * |  |---------------------------|  |
 * |  | port 1  (Port D)          |  |
 * |  |  ------------------------ |  |
 * |  |  | DIMM 0 :  4 bits     | |  |
 * |  |  ------------------------ |  |
 * |  |  | DIMM 1 :  4 bits     | |  |
 * |  |  ------------------------ |  |
 * |  -----------------------------  |
 * -----------------------------------
 *
 * Bit definition
 *
 *        RANK0_MIRRORED = 0x08,
 *        RANK1_MIRRORED = 0x04,
 *        RANK2_MIRRORED = 0x02,
 *        RANK3_MIRRORED = 0x01,
 *
 * @param[in]  i_mbaTarget  -   mba target
 * @param[out] o_val        -   2 x 2 array of bytes ([num ports] [num dimms])
 *                              Address Mirroring 4 bits per dimm returned
 *                              in the lower nibble of the byte for the mba
 *
 * @return fapi::ReturnCode -   FAPI_RC_SUCCESS if success,
 *                              relevant error code for failure.
 */
fapi::ReturnCode getMBvpdAddrMirrorData( const fapi::Target &i_mbaTarget,
                              uint8_t (&o_val) [2][2]);

}

#endif
