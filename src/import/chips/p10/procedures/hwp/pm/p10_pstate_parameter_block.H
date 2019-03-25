/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/pm/p10_pstate_parameter_block.H $ */
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
/// @file  p10_pstate_parameter_block.H
/// @brief Definitons of paramater information used to process pstates
///
// *HWP HW Owner        : Greg Still <stillgs@us.ibm.com>
// *HWP FW Owner        : Prasad Bg Ranganath <prasadbgr@in.ibm.com>
// *HWP Team            : PM
// *HWP Level           : 1
// *HWP Consumed by     : HB,PGPE,CME,OCC

#ifndef __P10_PSTATE_PARAMETER_BLOCK_H__
#define __P10_PSTATE_PARAMETER_BLOCK_H__

#include <fapi2.H>
#include <pstates_occ.H>
#include <pstates_pgpe.H>

//Pstate SuperStructure
typedef struct
{
    /// Magic Number
    uint64_t iv_magic;

    // PGPE content
    GlobalPstateParmBlock_t iv_globalppb;

    //TBD
    // QME content
    //LocalPstateParmBlock iv_localppb;

    // OCC content
    OCCPstateParmBlock_t iv_occppb;

} PstateSuperStructure;

namespace pm_pstate_parameter_block
{


//PlatPmPPB Object definition
class PlatPmPPB
{
    public:
        //Constructor with Proc target as input
        PlatPmPPB ( const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP> i_target ) :
            iv_procChip (i_target), iv_pstates_enabled(0), iv_resclk_enabled(0),
            iv_vdm_enabled(0), iv_ivrm_enabled(0), iv_wof_enabled(0), iv_safe_voltage (0),
            iv_safe_frequency(0), iv_reference_frequency_mhz(0), iv_reference_frequency_khz(0),
            iv_frequency_step_khz(0), iv_proc_dpll_divider(0), iv_nest_freq_mhz(0),
            iv_wov_underv_enabled(0), iv_wov_overv_enabled(0)

        {
        }


    private:
        fapi2::Target< fapi2::TARGET_TYPE_PROC_CHIP > iv_procChip;  // processor chip target
        uint8_t                   iv_pstates_enabled;
        uint8_t                   iv_resclk_enabled;
        uint8_t                   iv_vdm_enabled;
        uint8_t                   iv_ivrm_enabled;
        uint8_t                   iv_wof_enabled;
        uint32_t                  iv_safe_voltage;    // System safe voltage
        uint32_t                  iv_safe_frequency;  // System safe frequency
        uint32_t                  iv_reference_frequency_mhz;  //System reference frequency
        uint32_t                  iv_reference_frequency_khz;  //System reference frequency
        uint32_t                  iv_frequency_step_khz;   // System step frequency
        uint32_t                  iv_proc_dpll_divider;   // proc dpll divider value
        uint32_t                  iv_nest_freq_mhz;       //Nest frequency
        uint8_t                   iv_wov_underv_enabled;
        uint8_t                   iv_wov_overv_enabled;
};

}

/// @typedef p10_pstate_parameter_block_FP_t
/// function pointer typedef definition for HWP call support
typedef fapi2::ReturnCode (*p10_pstate_parameter_block_FP_t) (
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>&,
    PstateSuperStructure*, uint8_t*, uint32_t&);


extern "C"
{

/// -------------------------------------------------------------------
/// @brief Populate Pstate super structure from VPD data
/// @param[in]    i_target          => Chip Target
/// @param[inout] *io_pss           => pointer to pstate superstructure
/// @param[out]   *o_buf            => wof table data
/// @param[inout] &io_size          => wof table data size
/// @return   FAPI2::SUCCESS
/// -------------------------------------------------------------------
    fapi2::ReturnCode
    p10_pstate_parameter_block( const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
                                PstateSuperStructure* io_pss, uint8_t* o_buf, uint32_t& io_size);

} // extern C


#endif  // __P10_PSTATE_PARAMETER_BLOCK_H__
