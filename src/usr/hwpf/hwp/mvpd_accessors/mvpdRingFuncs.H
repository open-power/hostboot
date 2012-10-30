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
/**
 *  @file mvpdRingFuncs.H
 *
 *  @brief Prototype for getMvpdRingField() -
 *          return a  buffer containing the entire field with a pointer to
 *          the requested ring.
 */

 #ifndef    _HWP_MVPDRINGFUNCS_
 #define    _HWP_MVPDRINGFUNCS_

 #include   <fapi.H>



extern "C"
{

/**
 * @brief   return mvpd field with pointer to requested ring 
 *          for the specified target CPU.
 *          It is an error if the requested ring is not there.
 *          RC_REPAIR_RING_NOT_FOUND will be returned if the requested
 *          ring is not there.
 *
 * @param i_chipletId       -   Chiplet ID to search for
 * @param i_ringId          -   Ring ID to search for
 * @param i_pFieldBuf       -   The buffer containing the field to search
 * @param i_fieldBufsize    -   Number of bytes in the field buffer 
 * @param o_pRingBuf        -   Pointer to ring in the field buffer
 * @param o_rRingBufsize    -   Size of ring
 *
 * @return fapi::ReturnCode -   FAPI_RC_SUCCESS if success,
 *                              relevant error code for failure.
 */

fapi::ReturnCode findMvpdRingField( const uint8_t   i_chipletId,
                                const uint8_t       i_ringId,
                                uint8_t     * const i_pFieldBuf,
                                uint32_t            i_fieldBufsize,
                                uint8_t           * &o_rRingBuf,
                                uint32_t            &o_rRingBufsize);
} // extern "C"

#endif // _HWP_REPAIRRINGFUNC
