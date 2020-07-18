/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/pm/p10_check_proc_config.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020                             */
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
#ifndef __CHECK_PROC_CONFIG_
#define __CHECK_PROC_CONFIG_


///
/// @file   p10_check_proc_config.H
/// @brief  describes interface for a HWP that generates a bit vector corresponding to P10 chip config.
///
/// *HWP HWP Owner:      Greg Still <stillgs@us.ibm.com>
/// *HWP FW Owner:       Sumit Kumar <sumit_kumar@in.ibm.com>
/// *HWP Team:           PM
/// *HWP Level:          3
/// *HWP Consumed by:    Hostboot:Phyp
///
/// EKB-Mirror-To: hostboot
//

//--------------------------------------------------------------------------
// Includes
//--------------------------------------------------------------------------
#include <fapi2.H>
#include <stdint.h>
#include <map>


extern "C"
{
    typedef  const fapi2::Target< fapi2::TARGET_TYPE_PROC_CHIP > CONST_FAPI2_PROC;

//------------------------------------------------------------------------------

/// @brief    Checks for availability of chiplets and updates bit vector.
/// @param[in]   i_procTgt        fapi2 target for processor chip.
/// @param[in]   i_pHomerImage    pointer to the beginning of the HOMER image buffer
/// @return   fapi2 return code
//
    fapi2::ReturnCode p10_check_proc_config( CONST_FAPI2_PROC& i_procTgt, void* i_pHomerImage );

//------------------------------------------------------------------------------

    typedef fapi2::ReturnCode( *p10_check_proc_config_FP_t ) ( CONST_FAPI2_PROC& i_procTgt,
            void* i_pHomerImage );

} // extern C

#ifndef __HOSTBOOT_MODULE
    extern     std::map< fapi2::TargetType, std::string > g_targetTypeMap;
#endif

/// @brief   checks proc configuration for a given chiplet type
/// @param[in]      i_procTgt          fapi2 target for processor chip.
/// @param[in]      i_type             target type
/// @param[inout]   io_configVector  fapi2 buffer
/// @param[in]      i_chipletStartPos  start position for given chiplet type in  config vector
/// @return   fapi2 return code
//
template< fapi2::TargetType K >
fapi2::ReturnCode checkChiplet( CONST_FAPI2_PROC& i_procTgt, fapi2::TargetType  i_type,
                                uint64_t& io_configVector, uint8_t i_chipletStartPos )
{
    auto l_childVector =
        i_procTgt.getChildren < K > ( fapi2::TARGET_STATE_PRESENT );

    uint64_t l_tempVector = 0;

    for( auto itv : l_childVector )
    {
        uint8_t l_chipletPos = 0;
        FAPI_TRY( FAPI_ATTR_GET( fapi2::ATTR_CHIP_UNIT_POS, itv, l_chipletPos ),
                  "Failed to get chiplet position " );

        if( itv.isFunctional() )
        {
            l_tempVector = 0x8000000000000000ull;
            uint8_t l_configPos = i_chipletStartPos + l_chipletPos;

            io_configVector |= (l_tempVector >> l_configPos);

#ifndef __HOSTBOOT_MODULE

            FAPI_INF( "Chiplet Type %s", g_targetTypeMap[i_type].c_str() );

#endif

            FAPI_INF( "Chiplet Pos 0x%08x Bit Pos 0x%02x UAV 0x%016lx",
                      l_chipletPos, l_configPos, io_configVector );
        }
    }

fapi_try_exit:

    return fapi2::current_err;
}

#endif //__CHECK_PROC_CONFIG_
