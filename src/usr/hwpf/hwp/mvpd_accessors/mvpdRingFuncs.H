/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/mvpd_accessors/mvpdRingFuncs.H $             */
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
// $Id: mvpdRingFuncs.H,v 1.3 2013/10/09 20:54:13 mjjones Exp $
/**
 *  @file mvpdRingFuncs.H
 *
 *  @brief Prototype for mvpdRingFuncs()
 */

 #ifndef    _HWP_MVPDRINGFUNCS_
 #define    _HWP_MVPDRINGFUNCS_

 #include   <fapi.H>

// mvpdRingFunc can be used for get and set
enum mvpdRingFuncOp
{
    MVPD_RING_GET,
    MVPD_RING_SET,
};

// Only get operation for mbvpd Rings
enum mbvpdRingFuncOp
{
    MBVPD_RING_GET,
};

extern "C"
{

/**
 * @brief   get or set the requested ring for the record and keyword
 *          for the specified target CPU.
 *
 *          detailed comments on get and set are in the
 *          getMvpdRing.H and setMvpdRing.H and apply here as well.
 *
 * @param i_mvpdRingFuncOp  -   indicate get or set via enum mvpdRingFuncOp
 * @param i_record          -   Record enumerator
 * @param i_keyword         -   Keyword enumerator
 * @param i_fapiTarget      -   cpu target
 * @param i_chipletId       -   Chiplet ID
 * @param i_ringId          -   Ring ID
 * @param i_pRingBuf        -   The buffer to receive or send the ring
 * @param io_rRingBufsize   -   Size of ring / ring buffer
 *
 * @return fapi::ReturnCode -   FAPI_RC_SUCCESS if success,
 *                              relevant error code for failure.
 */
fapi::ReturnCode mvpdRingFunc(  mvpdRingFuncOp       i_mvpdRingFuncOp,
                                fapi::MvpdRecord     i_record,
                                fapi::MvpdKeyword    i_keyword,
                                const fapi::Target   &i_fapiTarget,
                                const uint8_t        i_chipletId,
                                const uint8_t        i_ringId,
                                uint8_t              *i_pRingBuf,
                                uint32_t             &io_rRingBufsize);

/**
 * @brief   get the requested ring for the record and keyword
 *          for the specified target CPU.
 *
 *          detailed comments on get are in getMbvpdRing.H
 *          and apply here as well.
 *
 * @param i_mbvpdRingFuncOp  -  indicate get or set via enum mbvpdRingFuncOp
 * @param i_record          -   Record enumerator
 * @param i_keyword         -   Keyword enumerator
 * @param i_fapiTarget      -   cpu target
 * @param i_chipletId       -   Chiplet ID
 * @param i_ringId          -   Ring ID
 * @param i_pRingBuf        -   The buffer to receive or send the ring
 * @param io_rRingBufsize   -   Size of ring / ring buffer
 *
 * @return fapi::ReturnCode -   FAPI_RC_SUCCESS if success,
 *                              relevant error code for failure.
 */
fapi::ReturnCode mbvpdRingFunc( mbvpdRingFuncOp i_mbvpdRingFuncOp,
                                fapi::MBvpdRecord i_record,
                                fapi::MBvpdKeyword i_keyword,
                                const fapi::Target &i_fapiTarget,
                                const uint8_t i_chipletId,
                                const uint8_t i_ringId,
                                uint8_t *i_pRingBuf,
                                uint32_t &io_rRingBufsize);


} // extern "C"

#endif
