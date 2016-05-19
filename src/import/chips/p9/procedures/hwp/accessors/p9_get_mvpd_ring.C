/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/accessors/p9_get_mvpd_ring.C $        */
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
// $Id: p9_get_mvpd_ring.C,v 1.1 2012/07/19 22:00:40 mjjones Exp $
/**
 *  @file p9_get_mvpd_ring.C
 *
 *  @brief fetch repair rings from MVPD  records
 *
 */

#include    <stdint.h>

//  fapi2 support
#include    <fapi2.H>

#include    <p9_get_mvpd_ring.H>
#include    <p9_mvpd_ring_funcs.H>

extern "C"
{
    using   namespace   fapi2;

// getMvpdRing: Wrapper to call common function mvpdRingFunc
    fapi2::ReturnCode getMvpdRing( fapi2::MvpdRecord   i_record,
                                   fapi2::MvpdKeyword  i_keyword,
                                   const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>
                                   & i_fapiTarget,
                                   const uint8_t       i_chipletId,
                                   const uint8_t       i_ringId,
                                   uint8_t*             i_pRingBuf,
                                   uint32_t&            io_rRingBufsize)
    {
        fapi2::ReturnCode        l_fapirc;

        FAPI_DBG("getMvpdRing: entry ringId=0x%x, chipletId=0x%x, size=0x%x ",
                 i_ringId,
                 i_chipletId,
                 io_rRingBufsize  );

        // common get and set processing
        l_fapirc = mvpdRingFunc(MVPD_RING_GET,
                                i_record,
                                i_keyword,
                                i_fapiTarget,
                                i_chipletId,
                                i_ringId,
                                i_pRingBuf,
                                io_rRingBufsize);


        FAPI_DBG("getMvpdRing: exit rc=0x%x",
                 static_cast<uint32_t>(l_fapirc) );

        return  l_fapirc;
    }

}   // extern "C"
