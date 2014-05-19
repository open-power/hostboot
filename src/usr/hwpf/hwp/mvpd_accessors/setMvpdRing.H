/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/mvpd_accessors/setMvpdRing.H $               */
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
// $Id: setMvpdRing.H,v 1.2 2013/01/25 21:12:40 whs Exp $
/**
 *  @file setMvpdRing.H
 *
 *  @brief Prototype for setMvpdRing() -
 *          get a repair ring from a MVPD record
 */

 #ifndef    _HWP_SETMVPDRING_
 #define    _HWP_SETMVPDRING_

 #include   <fapi.H>

// function pointer typedef definition for HWP call support
typedef fapi::ReturnCode (*setMvpdRing_FP_t) 
        (fapi::MvpdRecord,fapi::MvpdKeyword, const fapi::Target &,
         const uint8_t, const uint8_t, uint8_t *, uint32_t);

extern "C"
{

/**
 * @brief   set specified ring from MVPD for the specified target CPU.
 *
 * A Ring Id Chiplet Id should be unique in the mvpd Record.
 * The code does not validate. No assumption should be made on which would
 * be updated if there are multiple.
 *
 * The set ring can be the same size or smaller than an existing ring.
 * The ring can be larger than the existing ring or can be added (was
 * not there before) if there is room in the record. 
 *
 * @param i_record          -   Record enumerator
 * @param i_keyword         -   Keyword enumerator
 * Supported Rings are:
 *                   MVPD_RECORD_CP00 - MVPD_KEYWORD_PDR
 *                   MVPD_RECORD_CP00 - MVPD_KEYWORD_PDG
 * @param i_fapiTarget      -   cpu target
 * @param i_chipletId       -   Chiplet ID
 * @param i_ringId          -   Ring ID
 * @param i_pRingBuf        -   pointer to a buffer allocated by the caller
 *                              to with the ring header and data to set.
 *                              Can not be NULL. 
 * @param i_rRingBufsize    -   size of ring buffer that the caller has
 *                              allocated.
 *                              The buffer contains the CompressedScanData
 *                              structure followed by compressed data. The 
 *                              caller does compression and decompression.
 *                              The header needs to include the RS4 magic 
 *                              number. The ring ID and chiplet ID must match
 *                              the passed parameters. The size must match the
 *                              parameter size. 
 *
 *  Buffer:   io_rRingBufsize returns xNN.
 *    byte x0  CompressedScanData structure (rs4 header)
 *    byte x18 compressed data (sizeof CompressedScanData is 0x18)
 *    byte xNN last byte of compressed data*
 *
 * @return fapi::ReturnCode -   FAPI_RC_SUCCESS if success,
 *                              relevant error code for failure.
 */
fapi::ReturnCode setMvpdRing(   fapi::MvpdRecord i_record,
                                fapi::MvpdKeyword i_keyword,
                                const fapi::Target  &i_fapiTarget,
                                const uint8_t       i_chipletId,
                                const uint8_t       i_ringId,
                                uint8_t             *i_pRingBuf,
                                uint32_t            i_rRingBufsize );

}

#endif
