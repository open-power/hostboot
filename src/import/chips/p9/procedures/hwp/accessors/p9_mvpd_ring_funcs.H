/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/accessors/p9_mvpd_ring_funcs.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016                             */
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
// $Id: p9_mvpd_ring_funcs.H,v 1.4 2014/07/16 19:07:08 cswenson Exp $
/**
 *  @file p9_mvpd_ring_funcs.H
 *
 *  @brief Prototype for p9_mvpd_ring_funcs()
 */

#ifndef    _HWP_MVPDRINGFUNCS_
#define    _HWP_MVPDRINGFUNCS_

#include   <fapi2.H>

namespace fapi2
{

///
/// @brief Enumeration of mvpdRingFunc ops
///
enum mvpdRingFuncOp
{
    MVPD_RING_GET,
    MVPD_RING_SET,
};

typedef ReturnCode (*mvpdRingFuncs_FP_t) (
    mvpdRingFuncOp,
    MvpdRecord,
    MvpdKeyword,
    const Target<TARGET_TYPE_PROC_CHIP>&,
    const uint8_t,
    const uint64_t,
    const uint8_t,
    uint8_t*,
    uint32_t& );

extern "C"
{

    /**
     * @brief   get or set the requested ring for the record and keyword
     *          for the specified target CPU.
     *
     *          detailed comments on get and set are in the
     *          getMvpdRing.H and setMvpdRing.H and apply here as well.
     *
     * @param i_mvpdRingFuncOp - indicate get or set via enum mvpdRingFuncOp
     * @param i_record         - Record enumerator
     * @param i_keyword        - Keyword enumerator
     * @param i_fapiTarget     - cpu target
     * @param i_chipletId      - Chiplet ID
     * @param i_evenOddMask    - Even (0) or odd (1) EX. Disregarded for other chiplets.
     * @param i_ringId         - Ring ID
     * @param i_pRingBuf       - The buffer to receive or send the ring
     * @param io_rRingBufsize  - Size of ring / ring buffer
     *
     * @return fapi2::ReturnCode -   FAPI_RC_SUCCESS if success,
     *                              relevant error code for failure.
     */
    ReturnCode mvpdRingFunc( mvpdRingFuncOp       i_mvpdRingFuncOp,
                             MvpdRecord           i_record,
                             MvpdKeyword          i_keyword,
                             const Target<TARGET_TYPE_PROC_CHIP>&
                             i_fapiTarget,
                             const uint8_t        i_chipletId,
                             const uint8_t        i_evenOdd,
                             const uint8_t        i_ringId,
                             uint8_t*             i_pRingBuf,
                             uint32_t&            io_rRingBufsize );

} // extern "C"
} // namespace fapi
#endif
