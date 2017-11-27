/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/pm/p9_pm_recovery_ffdc_occ.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2018                        */
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
#ifndef __PM_RECOVERY_FFDC_OCC_
#define __PM_RECOVERY_FFDC_OCC_

///
/// @file   p9_pm_recovery_ffdc_occ.H
/// @brief  Models OCC platform for the FFDC collection of PM complex
///
/// *HWP HWP Owner:      Greg Still <stillgs@us.ibm.com>
/// *HWP FW Owner:       Amit Tendolkar <amit.tendolkar@in.ibm.com>
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

    class PlatOcc : public PlatPmComplex
    {
            public:
            /// @brief  constructor
            PlatOcc ( const fapi2::Target <fapi2::TARGET_TYPE_PROC_CHIP>
                      i_procChipTgt );

            /// @brief  destructor
            virtual ~PlatOcc() { };

            /// @brief      Initializes the OCC FFDC Sub-Sections in HOMER with default header
            /// @param[in]  i_pHomerBuf  points to base of P9 HOMER.
            ///  @return    fapi2 return code
            fapi2::ReturnCode init ( void* i_pHomerBuf );

            /// @brief      collects FFDC of the OCC 405, GPE0 and GPE1.
            /// @param[in]  i_pHomerBuf  points to base of P9 HOMER.
            /// @param[in]  i_ffdcType   indicates the content type to collect
            /// @return     fapi2 return code.
            fapi2::ReturnCode collectFfdc ( void*   i_pHomerBuf,
                                            uint8_t i_ffdcType = ALL );

            /// @brief      generates summary of FFDC pertaining to a given platform.
            /// @param[in]  i_pHomer    points to Homer base.
            /// @return     fapi2 return code
            fapi2::ReturnCode generateSummary( void * i_pHomer );

        private:
            /// @brief      collects trace info from a known region OCC SRAM
            /// @param[in]  i_pHomerBuf     location in HOMER to write at
            /// @param[in]  i_occSramRegion See OccFfdcValidStatus,
            ///                             Indicates OCC SRAM Region to read
            /// @return     fapi2 return code.
            fapi2::ReturnCode  collectTrace( uint8_t* i_pHomerBuf,
                                             uint8_t  i_occSramRegion );

            /// @brief      reads OCC SRAM to find out the region extent and
            ///             then collects info from that region
            /// @param[in]  i_pHomerBuf     location in HOMER to write at
            /// @param[in]  i_occSramRegion See OccFfdcValidStatus.
            ///                             Indicates OCC SRAM Region to read
            /// @return     fapi2 return code.
            fapi2::ReturnCode readSramRegion ( uint8_t* i_pHomerBuf,
                                               uint8_t i_occSramRegion );

            /// @brief updates the OCC FFDC Header
            /// @param[in]   i_pHomerBuf points to a location in HOMER meant for
            ///                          OCC FFDC Header
            ///@param[in]   i_ffdcValid  Indicates what fields in OCC FFDC are
            ///                          valid. See OccFfdcValidStatus
            ///@return      fapi2 return code.
            fapi2::ReturnCode updateOccFfdcHeader ( uint8_t* i_pHomerBuf,
                                                    uint16_t  i_ffdcValid );

            /// @brief      collects register info for a given OCC
            /// @param[in]  i_pHomerBuf     points to location of HOMER meant for OCC internal register.
            ///@return      fapi2 return code.
            fapi2::ReturnCode  collectOccReg( uint8_t * i_pHomerBuf);

            ///@brief initializes a list of register for generation of FFDC summary.
            void initRegList();
        private:
            std::vector<uint32_t> iv_occSummaryReg;
    };

    //---------------------------------------------------------------------------------------------

    // function pointer typedef definition for HWP call support
    typedef fapi2::ReturnCode( *p9_pm_recovery_ffdc_occ_FP_t )
            ( const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP> & i_procChipTgt,
              void* i_occFfdcBuf );
extern "C"
{
    // -----------------------------------------------------------------------------
    // Function prototypes
    // -----------------------------------------------------------------------------
    ///
    /// @brief Populates the OCC FFDC section with FFDC collected from OCC GPE0 and GPE1.
    ///
    /// @param[in] i_procChipTarget Proc Chip target
    /// @param[in] i_pHomerImage    Pointer to the base of the chip HOMER region
    ///
    /// @return FAPI2_RC_SUCCESS on success or error return code
    ///
        fapi2::ReturnCode p9_pm_recovery_ffdc_occ
        ( const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_procChipTarget,
          void* i_pHomerImage );

}

} //namespace p9_stop_recov_ffdc ends

#endif //__PM_RECOVERY_FFDC_OCC_
