 /*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/include/usr/hwpf/hwp/setRepairRing.H $
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
 *  @file setRepairRing.H
 *
 *  @brief Prototype for setRepairRing() -
 *          get a repair ring from the MVPD #R record
 */

 #ifndef    _HWP_SETREPAIRRING_
 #define    _HWP_SETREPAIRRING_

 #include   <fapi.H>

// function pointer typedef definition for HWP call support
typedef fapi::ReturnCode (*setRepairRing_FP_t) (const fapi::Target &, const uint8_t, const uint8_t, uint8_t *, uint32_t &);

extern "C"
{

/**
 * @brief   update  specified repair ring in MVPD #R record for the specified
 *          target CPU. The ring must already be present. This function can not
 *          be used to 'add' a ring. The size of the updated ring must exactly
 *          match the exiting ring, which is updated in place. 
 *
 * @param i_fapiTarget      -   cpu target
 * @param i_chipletId       -   Chiplet ID
 * @param i_ringId          -   Ring ID
 * @param io_pRingBuf       -   pointer to a buffer allocated by the caller
 *                              if NULL, the size of the buffer required will
 *                              be returned with FAPI_RC_SUCCESS.
 * @param io_rRingBufsize   -   in:     size of ring buffer that caller has
 *                                      allocated. The size must be the exact
 *                                      size of the existing ring.
 *                              out:    If the ring was not found, an error
 *                                      will be returned and this will be 0.
 *                                      If the passed ring size does not
 *                                      exactly match the existing ring, 
 *                                      an error will be returned and this will
 *                                      be the size required.
 *
 * @return fapi::ReturnCode -   FAPI_RC_SUCCESS if success,
 *                              relevant error code for failure.
 */
fapi::ReturnCode setRepairRing( const fapi::Target  &i_fapiTarget,
                                const uint8_t       i_chipletId,
                                const uint8_t       i_ringId,
                                uint8_t             *io_pRingBuf,
                                uint32_t            &io_rRingBufsize );

}

#endif
