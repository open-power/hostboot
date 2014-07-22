/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/mvpd_accessors/setMvpdRing.C $               */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2014                        */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
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
// $Id: setMvpdRing.C,v 1.2 2014/06/27 19:24:02 thi Exp $
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
