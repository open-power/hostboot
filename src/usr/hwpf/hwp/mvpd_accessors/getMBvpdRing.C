/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/mvpd_accessors/getMBvpdRing.C $              */
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
// $Id: getMBvpdRing.C,v 1.1 2013/10/09 20:52:37 mjjones Exp $
/**
 *  @file getMBvpdRing.C
 *
 *  @brief function to fetch repair rings from MBVPD  records
 *
 */

#include    <stdint.h>
#include    <fapi.H> //  fapi support
#include    <getMBvpdRing.H>
#include    <mvpdRingFuncs.H>

extern "C"
{
using   namespace   fapi;

// getMBvpdRing: Wrapper to call common function mbvpdRingFunc
fapi::ReturnCode getMBvpdRing(fapi::MBvpdRecord   i_record,
                              fapi::MBvpdKeyword  i_keyword,
                              const fapi::Target &i_fapiTarget,
                              const uint8_t       i_chipletId,
                              const uint8_t       i_ringId,
                              uint8_t             *i_pRingBuf,
                              uint32_t            &io_rRingBufsize)
{
    fapi::ReturnCode  l_fapirc;

    FAPI_INF("getMBvpdRing: entry ringId=0x%x, chipletId=0x%x, size=0x%x",
             i_ringId, i_chipletId, io_rRingBufsize );

    // Pass the parameters into mbvpdRingFunc
    l_fapirc = mbvpdRingFunc(MBVPD_RING_GET,
                            i_record,
                            i_keyword,
                            i_fapiTarget,
                            i_chipletId,
                            i_ringId,
                            i_pRingBuf,
                            io_rRingBufsize );

    FAPI_INF("getMBvpdRing: exit rc=0x%x", static_cast<uint32_t>(l_fapirc));

    return  l_fapirc;
}

}   // extern "C"
