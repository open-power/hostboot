/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/customize/p10_qme_customize.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2019                        */
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
//  @file p10_qme_customize.C
//
//  @brief Customizes QME ring section  for consumption by p10_hcode_image_build
//
//  *HWP Owner:         Mike Olsen <cmolsen@us.ibm.com>
//  *HWP Backup Owner:  Prem S Jha <premjha2@in.ibm.com>
//  *HWP Team:          Infrastructure
//  *HWP Level:         1
//  *HWP Consumed by:   HOSTBOOT, CRONUS
//

#include <p10_qme_customize.H>

extern "C"
{

    fapi2::ReturnCode p10_qme_customize ( uint8_t*   i_pBufQmeRing,
                                          CUSTOM_RING_OP     i_custOp,
                                          uint8_t*           o_pBufCustomRing  )
    {
        FAPI_IMP( ">> p10_qme_customize " );


        FAPI_IMP( "<< p10_qme_customize " );
        return fapi2::current_err;
    }


}
