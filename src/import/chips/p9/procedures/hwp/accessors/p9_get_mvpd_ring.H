/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/accessors/p9_get_mvpd_ring.H $        */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* EKB Project                                                            */
/*                                                                        */
/* COPYRIGHT 2012,2016                                                    */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
// $Id: p9_get_mvpd_ring.H,v 1.1 2012/07/19 22:00:38 mjjones Exp $
/**
 *  @file p9_get_mvpd_ring.H
 *
 *  @brief Prototype for getMvpdRing() -
 *          get a repair ring from a MVPD record
 */

#ifndef    _HWP_GETMVPDRING_
#define    _HWP_GETMVPDRING_

#include   <fapi2.H>

// function pointer typedef definition for HWP call support
typedef fapi2::ReturnCode (*getMvpdRing_FP_t)
(fapi2::MvpdRecord, fapi2::MvpdKeyword,
 const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>&,
 const uint8_t, const uint8_t, uint8_t*, uint32_t&);


extern "C"
{
    /**
     * @brief   get specified ring from MVPD for the specified target CPU.
     *
     * A Ring Id Chiplet Id should be unique in the mvpd Record.
     * The code does not validate. No assumption should be made on which would
     * be returned if there are multiple.
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
     *                              to receive the ring header and data.
     *                              if NULL, the size of the min buffer required
     *                              buffer will be returned in io_rRingBufsize
     *                              with rc FAPI_RC_SUCCESS.
     * @param io_rRingBufsize   -   in:     size of ring buffer that caller has
     *                                      allocated
     *                              out:    number of BYTES that were copied to the
     *                                      output buffer.
     *                                      If the ring was not found, an error
     *                                      will be returned and this will be 0.
     *                                      If the output buffer is not big enough,
     *                                      an error will be returned and this will
     *                                      be the minimum size required.
     *                              The buffer contains the CompressedScanData
     *                              structure followed by compressed data. The
     *                              caller does compression and decompression.
     *  Buffer:   io_rRingBufsize returns xNN.
     *    byte x0  CompressedScanData structure (rs4 header)
     *    byte x18 compressed data (sizeof CompressedScanData is 0x18)
     *    byte xNN last byte of compressed data
     *
     * @return fapi2::ReturnCode -   FAPI_RC_SUCCESS if success,
     *                               relevant error code for failure.
     */
    fapi2::ReturnCode getMvpdRing( fapi2::MvpdRecord   i_record,
                                   fapi2::MvpdKeyword  i_keyword,
                                   const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>
                                   & i_fapiTarget,
                                   const uint8_t       i_chipletId,
                                   const uint8_t       i_ringId,
                                   uint8_t*             io_pRingBuf,
                                   uint32_t&            io_rRingBufsize );

}

#endif
