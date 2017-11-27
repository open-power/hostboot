/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/pm/p9_pm_recovery_ffdc_cppm.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017,2018                        */
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

            /// @brief      Initializes the Quad and CPPM FFDC Sub-Sections in HOMER with default headers
            /// @param[in]  i_pHomerBuf  points to base of P9 HOMER.
            ///  @return    fapi2 return code
            fapi2::ReturnCode init ( void* i_pHomerBuf );

            /// @brief      collects FFDC pertaining to all functional cores in the chip.
            /// @param[in]  i_pHomerBuf     points to base of P9 HOMER.
            /// @param[in]  i_ffdcType      indicates the content type to collect
            //  @return     fapi2 return code.
            fapi2::ReturnCode collectFfdc ( void*    i_pHomerBuf,
                                            uint8_t  i_ffdcType = ALL );

            /// @brief      generates summary of FFDC pertaining to a given platform.
            /// @param[in]  i_pHomer    points to Homer base.
            /// @return     fapi2 return code
            fapi2::ReturnCode generateSummary( void * i_pHomer );
        private:

            ///@brief initializes a list of register for generation of FFDC summary.
            void initRegList();

            /// @brief updates the CPPM FFDC Header
            ///@param[in]   i_pHomerBuf     points to a location in HOMER meant for CPPM Header
            ///@param[in]   i_CppmInstance  CPPM instance
            ///@param[in]   i_ffdcValid     non-zero indicates the CPPM FFDC is valid
            ///@return      fapi2 return code.

            fapi2::ReturnCode updateCppmFfdcHeader( uint8_t * i_pHomerBuf,
                                                    const uint8_t i_cppmInstance,
                                                    const uint16_t i_ffdcValid);
            /// @brief updates the QUAD FFDC Header
            ///@param[in]   i_pHomerBuf     points to a location in HOMER meant for Quad Header
            ///@param[in]   i_quadInstance  Quad instance
            ///@param[in]   i_ffdcValid     non-zero indicates the Quad FFDC is valid
            ///@return      fapi2 return code.

            fapi2::ReturnCode updateQuadFfdcHeader( uint8_t * i_pHomerBuf,
                                                    const uint8_t i_quadInstance,
                                                    const uint16_t i_ffdcValid);
        private:
            std::vector<uint32_t> iv_cppmSummaryReg;
    };

    //---------------------------------------------------------------------------------------------
    // function pointer typedef definition for HWP call support
    typedef fapi2::ReturnCode( *p9_pm_recovery_ffdc_cppm_FP_t )
            ( const fapi2::Target< fapi2::TARGET_TYPE_PROC_CHIP > & i_procChipTgt,
              void * i_cppmFfdcBuf );
extern "C"
{
    // -----------------------------------------------------------------------------
    // Function prototypes
    // -----------------------------------------------------------------------------
    ///
    /// @brief Populates the PM FFDC section with FFDC collected from CPPM
    ///
    /// @param[in] i_procChipTarget Proc Chip target
    /// @param[in] i_pHomerImage    Pointer to the base of the chip HOMER region
    ///
    /// @return FAPI2_RC_SUCCESS on success or error return code
    ///
        fapi2::ReturnCode p9_pm_recovery_ffdc_cppm
        ( const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_procChipTarget,
          void* i_pHomerImage );
}

} //namespace p9_stop_recov_ffdc ends

#endif //PM_RECOVERY_FFDC_CPPM
