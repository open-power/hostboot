/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/accessors/p9_get_mvpd_ring.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2017                        */
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
//
//  @file p9_get_mvpd_ring.C
//
//  @brief fetch repair rings from MVPD  records
//
//  *HWP HWP Owner: Mike Olsen <cmolsen@us.ibm.com>
//  *HWP HWP Backup Owner: Sumit Kumar <sumit_kumar@in.ibm.com>
//  *HWP Team: Infrastructure
//  *HWP Level: 3
//  *HWP Consumed by: HOSTBOOT, CRONUS
//
//

#include    <stdint.h>

// fapi2 support
#include    <fapi2.H>

#include    <p9_get_mvpd_ring.H>
#include    <p9_mvpd_ring_funcs.H>

extern "C"
{

    using   namespace   fapi2;

// getMvpdRing: Wrapper to call common function mvpdRingFunc
    fapi2::ReturnCode getMvpdRing( const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>
                                   & i_fapiTarget,
                                   fapi2::MvpdRecord   i_record,
                                   fapi2::MvpdKeyword  i_keyword,
                                   const uint8_t       i_chipletId,
                                   const uint8_t       i_evenOdd,
                                   const RingId_t      i_ringId,
                                   uint8_t*            o_pRingBuf,
                                   uint32_t&           io_rRingBufsize )
    {
        fapi2::ReturnCode        l_fapirc;

        FAPI_DBG("getMvpdRing: Called w/ringId=0x%x, chipletId=0x%x, evenOdd=0x%x, size=0x%x",
                 i_ringId,
                 i_chipletId,
                 i_evenOdd,
                 io_rRingBufsize  );

        // common get and set processing
        l_fapirc = mvpdRingFunc( i_fapiTarget,
                                 MVPD_RING_GET,
                                 i_record,
                                 i_keyword,
                                 i_chipletId,
                                 i_evenOdd,
                                 i_ringId,
                                 o_pRingBuf,
                                 io_rRingBufsize );


        FAPI_DBG("getMvpdRing: exit rc=0x%x",
                 static_cast<uint32_t>(l_fapirc) );

        return  l_fapirc;
    }

} // Extern C
