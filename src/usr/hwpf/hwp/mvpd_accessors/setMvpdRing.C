 /*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/usr/hwpf/hwp/setMvpdRing.C $
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
 *  @file setMvpdRing.C
 *
 *  @brief update rings in MVPD records
 *
 */

#include    <stdint.h>

//  fapi support
#include    <fapi.H>

#include    <setMvpdRing.H>
#include    <mvpdRingFuncs.H>

extern "C"
{
using   namespace   fapi;

// setMvpdRing: Wrapper to call common function mvpdRingFunc
fapi::ReturnCode setMvpdRing( fapi::MvpdRecord i_record,
                                fapi::MvpdKeyword i_keyword,
                                const fapi::Target &i_fapiTarget,
                                const uint8_t       i_chipletId,
                                const uint8_t       i_ringId,
                                uint8_t             *i_pRingBuf,
                                uint32_t            i_rRingBufsize)
{
    fapi::ReturnCode        l_fapirc;

    FAPI_DBG("setMvpdRing: entry ringId=0x%x, chipletId=0x%x, size=0x%x ",
             i_ringId,
             i_chipletId,
             i_rRingBufsize  );

    // common get and set processing
    l_fapirc = mvpdRingFunc(MVPD_RING_SET,
                            i_record,
                            i_keyword,
                            i_fapiTarget,
                            i_chipletId,
                            i_ringId,
                            i_pRingBuf,
                            i_rRingBufsize); //in and out for common code.
                                             //in only for set. 

    FAPI_DBG("setMvpdRing: exit rc=0x%x",
               static_cast<uint32_t>(l_fapirc) );

    return  l_fapirc;
}

}   // extern "C"
