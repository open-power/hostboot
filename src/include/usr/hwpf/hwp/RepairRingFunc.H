/*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/include/usr/hwpf/hwp/RepairRingFunc.H $
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
 *  @file RepairRingFunc.H
 *
 *  @brief Prototype for getRepairRing() -
 *          get a repair ring from the MVPD #R record
 */

 #ifndef    _HWP_REPAIRRINGFUNC_
 #define    _HWP_REPAIRRINGFUNC_

 #include   <fapi.H>


extern "C"
{

/**
 * @brief   get specified repair ring from MVPD #R record for the specified
 *          target CPU.
 *
 * @param i_fapiTarget      -   cpu target
 * @param i_ringModifier    -   ringModifier/scanSelect id for the repair ring
 * @param io_pRingBuf       -   pointer to a buffer allocated by the caller
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
fapi::ReturnCode    getRepairRing(  const fapi::Target  &i_fapiTarget,
                                    const uint32_t      i_ringModifier,
                                    uint8_t             *io_pRingBuf,
                                    uint32_t            &io_rRingBufsize );

}

#endif
