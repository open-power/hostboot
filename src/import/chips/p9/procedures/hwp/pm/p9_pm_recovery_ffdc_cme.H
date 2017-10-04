/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/pm/p9_pm_recovery_ffdc_cme.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2017                        */
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
#ifndef __PM_RECOVERY_FFDC_BASE_
#define __PM_RECOVERY_FFDC_BASE_

///
/// @file   p9_pm_recovery_ffdc_cme.H
/// @brief  Models CME platform for the FFDC collection of PM complex
///
/// *HWP HWP Owner:      Greg Still <stillgs@us.ibm.com>
/// *HWP FW Owner:       Prem S Jha <premjha2@in.ibm.com>
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

    class PlatCme : public PlatPmComplex
    {
            public:
            /// @brief  constructor
            PlatCme( const fapi2::Target< fapi2::TARGET_TYPE_PROC_CHIP > i_procChipTgt );

            /// @brief  destructor
            virtual ~PlatCme() { };

            /// @brief      collects FFDC pertaining to all functional CMEs in the chip.
            /// @param[in]  i_pHomerBuf     points to base of P9 HOMER.
            //  @return     fapi2 return code.
            fapi2::ReturnCode collectFfdc( void* i_pHomerBuf );

        private:
            /// @brief      collects trace info from a given CME SRAM buffer.
            /// @param[in]  i_pHomerBuf     points to location of HOMER meant for CME Trace info.
            /// @param[in]  i_exTgt         fapi2 target for ex
            fapi2::ReturnCode  collectTrace( uint8_t * i_pHomerBuf,
                                             const fapi2::Target< fapi2::TARGET_TYPE_EX > & i_exTgt );

            /// @brief      collects  global variables from a given CME's SRAM.
            /// @param[in]  i_pHomerBuf     points to location of HOMER meant for CME's global variable
            /// @param[in]  i_exTgt         fapi2 target for ex
            fapi2::ReturnCode  collectGlobals( uint8_t * i_pHomerBuf,
                                               const fapi2::Target< fapi2::TARGET_TYPE_EX > & i_exTgt );

            /// @brief      collects internal register info for a given CME
            /// @param[in]  i_pHomerBuf     points to location of HOMER meant for CME's internal register.
            /// @param[in]  i_exTgt         fapi2 target for ex
            fapi2::ReturnCode  collectInternalReg( uint8_t * i_pHomerBuf,
                                                   const fapi2::Target< fapi2::TARGET_TYPE_EX > &  i_exTgt );

            /// @brief      collects CME Image Header info from CME SRAM buffer.
            /// @param[in]  i_pHomerBuf     points to location of HOMER meant for CME's header.
            /// @param[in]  i_exTgt         fapi2 target for ex
            fapi2::ReturnCode  collectImageHeader( uint8_t * i_pHomerBuf,
                                                   const fapi2::Target< fapi2::TARGET_TYPE_EX > & i_exTgt );

            /// @brief updates the CME FFDC Header
            ///@param[in]   i_pHomerBuf     points to a location in HOMER meant for CME FFDC Header
            ///@param[in]   i_cmePos        position of CME instance
            ///param[in]    i_ffdcValid     bit vector summarizing FFDC validity
            ///@param[in]   i_haltCondition hlat state of CME
            ///@return      fapi2 return code.
            ///@note        refer to PPE Spec for details on halt state.

            fapi2::ReturnCode updateCmeFfdcHeader( uint8_t * i_pHomerBuf, uint8_t i_cmePos,
                                                   uint8_t i_ffdcValid, uint8_t i_haltCondition );
    };

extern "C"
{
    typedef fapi2::ReturnCode( *p9_pm_recovery_ffdc_cme_FP_t )
            ( const fapi2::Target< fapi2::TARGET_TYPE_PROC_CHIP > & i_procChipTgt,
              void * i_cmeFfdcBuf );
}

} //namespace p9_stop_recov_ffdc ends

#endif //__PM_RECOVERY_FFDC_BASE_
