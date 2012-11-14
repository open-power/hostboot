 /*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/include/usr/hwpf/hwp/mvpdRingFuncs.H $
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


} // extern "C"

#endif // _HWP_REPAIRRINGFUNC
