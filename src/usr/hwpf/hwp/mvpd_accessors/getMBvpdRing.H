/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/mvpd_accessors/getMBvpdRing.H $              */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013                   */
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
// $Id: getMBvpdRing.H,v 1.1 2013/10/09 20:53:03 mjjones Exp $
/**
 *  @file getMBvpdRing.H
 *
 *  @brief Prototype for getMBvpdRing() -
 *          get a repair ring from a MBVPD record
 */

 #ifndef    _HWP_GETMBVPDRING_
 #define    _HWP_GETMBVPDRING_

 #include   <fapi.H>

// function pointer typedef definition for HWP call support
typedef fapi::ReturnCode (*getMBvpdRing_FP_t)
     (fapi::MBvpdRecord,fapi::MBvpdKeyword,const fapi::Target &,
      const uint8_t, const uint8_t, uint8_t *, uint32_t &);


extern "C"
{
/**
 * @brief  get specified ring from MBVPD for the specified memory buffer target.
 *
 * A Ring Id Chiplet Id should be unique in the mbvpd record.
 * The code does not validate. No assumption should be made on which would
 * be returned if there are multiple.
 *
 * @param i_record          -   Record enumerator
 * @param i_keyword         -   Keyword enumerator
 * Supported Rings are:
 *                   MBVPD_RECORD_VSPD - MBVPD_KEYWORD_PDD
 * @param i_fapiTarget      -   memory buffer target
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
 * @return fapi::ReturnCode -   FAPI_RC_SUCCESS if success,
 *                              relevant error code for failure.
 */
fapi::ReturnCode getMBvpdRing(  fapi::MBvpdRecord   i_record,
                                fapi::MBvpdKeyword  i_keyword,
                                const fapi::Target  &i_fapiTarget,
                                const uint8_t       i_chipletId,
                                const uint8_t       i_ringId,
                                uint8_t             *io_pRingBuf,
                                uint32_t            &io_rRingBufsize );

}

#endif
