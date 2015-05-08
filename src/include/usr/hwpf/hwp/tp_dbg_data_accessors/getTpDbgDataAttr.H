/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/hwpf/hwp/tp_dbg_data_accessors/getTpDbgDataAttr.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015                             */
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
// $Id: getTpDbgDataAttr.H,v 1.1 2015/05/07 20:11:12 thi Exp $
/**
 *  @file getTpDbgDataAttr.H
 *
 *  @brief Prototype for getPervVitalAttr() -
 *         Fetch TP Debug data attributes based on chip EC
 *         from static arrays (fapiTpDbgDataAttr.H)
 */

#ifndef _HWP_GETPERVVITALATTR_
#define _HWP_GETPERVVITALATTR_

#include <fapi.H>
#include <fapiTpDbgDataAttr.H>

// Function pointer typedef definition for HWP call support
typedef fapi::ReturnCode (*getPervVitlRingLengthAttr_FP_t)
     (const fapi::Target &, uint32_t &);

typedef fapi::ReturnCode (*getTpVitlSpyLengthAttr_FP_t)
     (const fapi::Target &, uint32_t &);

typedef fapi::ReturnCode (*getTpVitlSpyOffsetAttr_FP_t)
     (const fapi::Target &, uint32_t (&)[SPY_OFFSET_SIZE]);

extern "C"
{

/**
 * @brief Get processor TP VITL spy length for the specified target CPU.
 *
 * @param i_fapiTarget      -   cpu target
 * @param o_ringLength      -   out: Length of decompressed data
 *
 * @return fapi::ReturnCode -   FAPI_RC_SUCCESS if success,
 *                              relevant error code for failure.
 */
fapi::ReturnCode getPervVitlRingLengthAttr(const fapi::Target  &i_fapiTarget,
                                           uint32_t (&o_ringLength));


/**
 * @brief Get processor PERV VITL ring length for the specified target CPU.
 *
 * @param i_fapiTarget      -   cpu target
 * @param o_spyLength       -   out:    Length of spy
 *
 * @return fapi::ReturnCode -   FAPI_RC_SUCCESS if success,
 *                              relevant error code for failure.
 */
fapi::ReturnCode getTpVitlSpyLengthAttr(const fapi::Target  &i_fapiTarget,
                                           uint32_t (&o_spyLength));


/**
 * @brief Get processor TP VITL spy offsets for the specified target CPU.
 *
 * @param i_fapiTarget      -   cpu target
 * @param o_data            -   out: spy offset data
 *
 * @return fapi::ReturnCode -   FAPI_RC_SUCCESS if success,
 *                              relevant error code for failure.
 */
fapi::ReturnCode getTpVitlSpyOffsetAttr(const fapi::Target  &i_fapiTarget,
                                     uint32_t (&o_data)[SPY_OFFSET_SIZE]);

}

#endif
