/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/pm/p10_hcode_image_build.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2019                        */
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

///
/// @file   p10_hcode_image_build.C
/// @brief  Implements HWP that builds the Hcode image in HOMER.
///
// *HWP HWP Owner:      Greg Still <stillgs@us.ibm.com>
// *HWP FW Owner:       Prem S Jha <premjha2@in.ibm.com>
// *HWP Team:           PM
// *HWP Level:          1
// *HWP Consumed by:    HB: HBRT

// *INDENT-OFF*

//--------------------------------------------------------------------------
// Includes
//--------------------------------------------------------------------------
#include <map>
#include <p10_hcode_image_build.H>

extern "C"
{

//--------------------------------------------------------------------------------------------------------

fapi2::ReturnCode p10_hcode_image_build(    CONST_FAPI2_PROC& i_procTgt,
                                            void* const     i_pImageIn,
                                            void*           i_pHomerImage,
                                            void* const     i_pRingOverride,
                                            SysPhase_t      i_phase,
                                            ImageType_t     i_imgType,
                                            void* const     i_pBuf1,
                                            const uint32_t  i_sizeBuf1,
                                            void* const     i_pBuf2,
                                            const uint32_t  i_sizeBuf2,
                                            void* const     i_pBuf3,
                                            const uint32_t  i_sizeBuf3,
                                            void* const     i_pBuf4,
                                            const uint32_t  i_sizeBuf4 )


{
    FAPI_IMP(">> p10_hcode_image_build ");


//fapi_try_exit:
    FAPI_IMP("<< p10_hcode_image_build" );
    return fapi2::current_err;
}

}// extern "C"

// *INDENT-ON*
