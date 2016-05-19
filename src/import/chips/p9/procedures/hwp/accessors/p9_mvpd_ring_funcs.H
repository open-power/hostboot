/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/accessors/p9_mvpd_ring_funcs.H $      */
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
     * @param i_ringId         - Ring ID
     * @param i_pRingBuf       - The buffer to receive or send the ring
     * @param io_rRingBufsize  - Size of ring / ring buffer
     *
     * @return fapi2::ReturnCode -   FAPI_RC_SUCCESS if success,
     *                              relevant error code for failure.
     */
    ReturnCode mvpdRingFunc(mvpdRingFuncOp       i_mvpdRingFuncOp,
                            MvpdRecord           i_record,
                            MvpdKeyword          i_keyword,
                            const Target<TARGET_TYPE_PROC_CHIP>&
                            i_fapiTarget,
                            const uint8_t        i_chipletId,
                            const uint8_t        i_ringId,
                            uint8_t*             i_pRingBuf,
                            uint32_t&            io_rRingBufsize);

} // extern "C"

} // namespace fapi2

#endif
