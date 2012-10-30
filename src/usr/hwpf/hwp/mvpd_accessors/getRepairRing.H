 /*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/include/usr/hwpf/hwp/getRepairRing.H $
 *
 *  IBM CONFIDENTIAL
 *
 *  COPYRIGHT International Business Machines Corp. 2012
 *
 *  p1
 *
 *  Object Code Only (OCO) source materials
 *  Licensed Internal Code Source Materials
 *  IBM HostBoot Licensed Internal Code
 *
 *  The source code for this program is not published or other-
 *  wise divested of its trade secrets, irrespective of what has
 *  been deposited with the U.S. Copyright Office.
 *
 *  Origin: 30
 *
 *  IBM_PROLOG_END_TAG
 */
// $Id: RepairRingFunc.H,v 1.1 2012/07/19 22:00:38 mjjones Exp $
/**
 *  @file getRepairRing.H
 *
 *  @brief Prototype for getRepairRing() -
 *          get a repair ring from the MVPD #R record
 */

 #ifndef    _HWP_GETREPAIRRING_
 #define    _HWP_GETREPAIRRING_

 #include   <fapi.H>

// function pointer typedef definition for HWP call support
typedef fapi::ReturnCode (*getRepairRing_FP_t) (const fapi::Target &, const uint8_t, const uint8_t, uint8_t *, uint32_t &);


extern "C"
{
/**
 * @brief   get specified repair ring from MVPD #R record for the specified
 *          target CPU.
 *
 * @param i_fapiTarget      -   cpu target
 * @param i_chipletId       -   Chiplet ID
 * @param i_ringId          -   Ring ID
 * @param io_pRingBuf       -   pointer to a buffer allocated by the caller
 *                              if NULL, the size of the buffer required will
 *                              be returned with FAPI_RC_SUCCESS.
 * @param io_rRingBufsize   -   in:     size of ring buffer that caller has
 *                                      allocated
 *                              out:    number of BYTES that were copied to the
 *                                      output buffer.
 *                                      If the ring was not found, an error
 *                                      will be returned and this will be 0.
 *                                      If the output buffer is not big enough,
 *                                      an error will be returned and this will
 *                                      be the size required.
 *
 * @return fapi::ReturnCode -   FAPI_RC_SUCCESS if success,
 *                              relevant error code for failure.
 */
fapi::ReturnCode getRepairRing( const fapi::Target  &i_fapiTarget,
                                const uint8_t       i_chipletId,
                                const uint8_t       i_ringId,
                                uint8_t             *io_pRingBuf,
                                uint32_t            &io_rRingBufsize );

}

#endif
