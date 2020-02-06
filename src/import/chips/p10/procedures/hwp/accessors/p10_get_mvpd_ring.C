/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/accessors/p10_get_mvpd_ring.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2020                        */
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

#include    <p10_get_mvpd_ring.H>
#include    <p10_mvpd_ring_funcs.H>

extern "C"
{

    using   namespace   fapi2;

// getMvpdRing: Wrapper to call common function mvpdRingFunc
    fapi2::ReturnCode getMvpdRing( const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>
                                   & i_fapiTarget,
                                   fapi2::MvpdRecord   i_record,
                                   fapi2::MvpdKeyword  i_keyword,
                                   const uint32_t      i_chipletSel,
                                   const RingId_t      i_ringId,
                                   uint8_t*            o_pRingBuf,
                                   uint32_t&           io_rRingBufsize )
    {
        fapi2::ReturnCode        l_fapirc;

        FAPI_DBG("getMvpdRing: Called w/ringId=0x%x, chipletSel=0x%08x and bufsize=0x%x",
                 i_ringId,
                 i_chipletSel,
                 io_rRingBufsize  );

        // common get and set processing
        l_fapirc = mvpdRingFunc( i_fapiTarget,
                                 MVPD_RING_GET,
                                 i_record,
                                 i_keyword,
                                 i_chipletSel,
                                 i_ringId,
                                 o_pRingBuf,
                                 io_rRingBufsize );


        FAPI_DBG("getMvpdRing: Exit w/rc=0x%08x",
                 static_cast<uint32_t>(l_fapirc) );

        return  l_fapirc;
    }

} // Extern C
