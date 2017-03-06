/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/utils/pos.C $   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017                             */
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

#include <fapi2.H>
#include <generic/memory/lib/utils/pos.H>

namespace mss
{

///
/// @brief Return a DIMM's position from a fapi2 target
/// @param[in] i_target a target representing the target in question
/// @return The position relative to the chip
///
template<>
posTraits<fapi2::TARGET_TYPE_DIMM>::pos_type
pos(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target)
{
    typedef posTraits<fapi2::TARGET_TYPE_DIMM> TT;

    // Proc 0 is DIMM 0-15, proc 2 is 64-79 - 64 is the stride between processors
    constexpr uint64_t DIMM_STRIDE_PER_PROC = 64;
    constexpr uint64_t TOTAL_DIMM = TT::MC_PER_MODULE * TT::MCS_PER_MC * TT::PORTS_PER_MCS * TT::DIMMS_PER_PORT;

    TT::pos_type l_pos = 0;

    // Using fapi2 rather than mss::find as this is pretty low level stuff.
    const auto l_proc_pos =
        mss::template pos(i_target.getParent<fapi2::TARGET_TYPE_MCA>().getParent<fapi2::TARGET_TYPE_PROC_CHIP>());

    if (FAPI_ATTR_GET(fapi2::ATTR_FAPI_POS, i_target, l_pos) != fapi2::FAPI2_RC_SUCCESS)
    {
        goto fapi_try_exit;
    }

    // To get the FAPI_POS to the equivilent of ATTR_POS, we need to normalize the fapi_pos value
    // to the processor (stride across which ever processor we're on) and then add in the delta
    // per processor as ATTR_POS isn't processor relative (delta is the total dimm on a processor)
    return ((l_pos - (l_proc_pos * DIMM_STRIDE_PER_PROC)) % TOTAL_DIMM) + (TOTAL_DIMM * l_proc_pos);

fapi_try_exit:
    // If we can't get our position, we're in other trouble
    FAPI_ERR("can't get our fapi position");
    fapi2::Assert(false);
    return 0;

}

}// mss
