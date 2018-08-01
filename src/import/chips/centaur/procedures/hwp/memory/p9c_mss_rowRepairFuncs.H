/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/centaur/procedures/hwp/memory/p9c_mss_rowRepairFuncs.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018                             */
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
#ifndef __P9C_MSS_ROWREPAIRFUNCS__
#define __P9C_MSS_ROWREPAIRFUNCS__

#include <fapi2.H>

extern "C"
{

    ///
    /// @brief Check if sPPR (soft post package row repair) is supported on the
    //         system.
    /// @param[in]  i_target A DIMM target on the system
    //  @param[out] o_spprSupported True or false whether sPPR is supported
    /// @return FAPI2_RC_SUCCESS if no internal function failed
    ///
    fapi2::ReturnCode is_sPPR_supported(
        const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        bool& o_spprSupported );

}

#endif
