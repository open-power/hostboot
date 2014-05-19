/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/mvpd_accessors/getMBvpdRing.C $              */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013,2014              */
/*                                                                        */
/* Licensed under the Apache License, Version 2.0 (the "License");        */
/* you may not use this file except in compliance with the License.       */
/* You may obtain a copy of the License at                                */
/*                                                                        */
/*     http://www.apache.org/licenses/LICENSE-2.0                         */
/*                                                                        */
/* Unless required by applicable law or agreed to in writing, software    */
/* distributed under the License is distributed on an "AS IS" BASIS,      */
/* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or        */
/* implied. See the License for the specific language governing           */
/* permissions and limitations under the License.                         */
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
