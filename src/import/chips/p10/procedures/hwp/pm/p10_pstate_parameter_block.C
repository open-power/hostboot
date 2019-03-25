/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/pm/p10_pstate_parameter_block.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019                             */
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
/// @file  p10_pstate_parameter_block.C
/// @brief Setup Pstate super structure for PGPE/CME HCode
///
/// *HWP HW Owner        : Greg Still <stillgs@us.ibm.com>
/// *HWP FW Owner        : Prasad Bg Ranganath <prasadbgr@in.ibm.com>
/// *HWP Team            : PM
/// *HWP Level           : 1
/// *HWP Consumed by     : HB,PGPE,CME,OCC
///
/// @verbatim
/// Procedure Summary:
///   - Read VPD and attributes to create the Pstate Parameter Block(s) (one each for PGPE,OCC and CMEs).
/// @endverbatim

// *INDENT-OFF*
//
// ----------------------------------------------------------------------
// Includes
// ----------------------------------------------------------------------
#include <fapi2.H>
#include <p10_pstate_parameter_block.H>

using namespace pm_pstate_parameter_block;

///////////////////////////////////////////////////////////
////////     p10_pstate_parameter_block
///////////////////////////////////////////////////////////
fapi2::ReturnCode
p10_pstate_parameter_block( const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
                           PstateSuperStructure* io_pss,
                           uint8_t* o_buf,
                           uint32_t& io_size)
{
    FAPI_DBG("> p10_pstate_parameter_block");

    do
    {
        //Instantiate pstate object
        PlatPmPPB l_pmPPB(i_target);
    }
    while(0);

    FAPI_DBG("< p10_pstate_parameter_block");
    return fapi2::current_err;
}
// END OF PSTATE PARAMETER BLOCK function


// *INDENT-ON*
