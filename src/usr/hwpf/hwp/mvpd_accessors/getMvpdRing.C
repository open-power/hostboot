 /*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/usr/hwpf/hwp/getMvpdRing.C $
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
// $Id: getMvpdRing.C,v 1.1 2012/07/19 22:00:40 mjjones Exp $
/**
 *  @file getMvpdRing.C
 *
 *  @brief fetch repair rings from MVPD  records
 *
 */

#include    <stdint.h>

//  fapi support
#include    <fapi.H>

#include    <getMvpdRing.H>
#include    <mvpdRingFuncs.H>

extern "C"
{
using   namespace   fapi;

// getMvpdRing: Wrapper to call common function mvpdRingFunc
fapi::ReturnCode getMvpdRing( fapi::MvpdRecord i_record,
                              fapi::MvpdKeyword i_keyword, 
                              const fapi::Target &i_fapiTarget,
                              const uint8_t       i_chipletId,
                              const uint8_t       i_ringId,
                              uint8_t             *i_pRingBuf,
                              uint32_t            &io_rRingBufsize)
{
    fapi::ReturnCode        l_fapirc;

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
