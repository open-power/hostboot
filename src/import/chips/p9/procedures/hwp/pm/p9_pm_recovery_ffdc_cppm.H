/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/pm/p9_pm_recovery_ffdc_cppm.H $ */
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
#ifndef __PM_RECOVERY_FFDC_CPPM_
#define __PM_RECOVERY_FFDC_CPPM_

///
/// @file   p9_pm_recovery_ffdc_cppm.H
/// @brief  CPPM FFDC collection of PM complex
///
/// *HWP HWP Owner:      Greg Still <stillgs@us.ibm.com>
/// *HWP FW Owner:       Prasad Bg Ranganath <prasadbgr@in.ibm.com>
/// *HWP Team:           PM
/// *HWP Level:          2
/// *HWP Consumed by:    Hostboot
//
// *INDENT-OFF*
//--------------------------------------------------------------------------
// Includes
//--------------------------------------------------------------------------
#include <fapi2.H>
#include <stdint.h>
#include <p9_pm_recovery_ffdc_base.H>

namespace p9_stop_recov_ffdc
{

    class CppmRegs : public PlatPmComplex
    {
            public:
            /// @brief  constructor
            CppmRegs(const fapi2::Target< fapi2::TARGET_TYPE_PROC_CHIP > i_procChipTgt );

            /// @brief  destructor
            virtual ~CppmRegs () { };

            /// @brief      collects Register FFDC pertaining to all functional cores in the chip.
            /// @param[in]  i_pHomerBuf     points to base of P9 HOMER.
            //  @return     fapi2 return code.
            fapi2::ReturnCode collectRegFfdc( void* i_pHomerBuf );

        private:
            /// @brief updates the CPPM FFDC Header
            ///@param[in]   i_pHomerBuf     points to a location in HOMER meant for CPPM Header
            ///@param[in]   i_CppmInstance  CPPM instance
            ///@return      fapi2 return code.

            fapi2::ReturnCode updateCppmFfdcHeader( uint8_t * i_pHomerBuf, 
                                                    const uint8_t i_cppmInstance,
                                                    const uint8_t i_ffdcValid);
            /// @brief updates the QUAD FFDC Header
            ///@param[in]   i_pHomerBuf     points to a location in HOMER meant for CPPM Header
            ///@param[in]   i_quadInstance  Quad instance
            ///@return      fapi2 return code.

            fapi2::ReturnCode updateQuadFfdcHeader( uint8_t * i_pHomerBuf, 
                                                    const uint8_t i_quadInstance,
                                                    const uint8_t i_ffdcValid);
    };

extern "C"
{
    typedef fapi2::ReturnCode( *p9_pm_recovery_ffdc_cppm_FP_t )
            ( const fapi2::Target< fapi2::TARGET_TYPE_PROC_CHIP > & i_procChipTgt,
              void * i_cppmFfdcBuf );
}

} //namespace p9_stop_recov_ffdc ends

#endif //PM_RECOVERY_FFDC_CPPM
