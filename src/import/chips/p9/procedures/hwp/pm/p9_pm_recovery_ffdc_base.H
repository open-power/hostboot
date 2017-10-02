/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/pm/p9_pm_recovery_ffdc_base.H $ */
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
#ifndef __P9_PM_RECOVERY_FFDC_BASE_
#define __P9_PM_RECOVERY_FFDC_BASE_


///
/// @file   p9_pm_recovery_ffdc_base.H
/// @brief  Models generic platform for the FFDC collection of PM complex
///
/// *HWP HWP Owner:      Greg Still <stillgs@us.ibm.com>
/// *HWP FW Owner:       Prem S Jha <premjha2@in.ibm.com>
/// *HWP Team:           PM
/// *HWP Level:          2
/// *HWP Consumed by:    Hostboot:Phyp
//
// *INDENT-OFF*
//--------------------------------------------------------------------------
// Includes
//--------------------------------------------------------------------------
#include <fapi2.H>
#include <stdint.h>
#include <p9_pm_recovery_ffdc_defines.H>
#include <p9_ppe_utils.H>

namespace p9_stop_recov_ffdc
{

    class PlatPmComplex
    {
        public:
            /// @brief  constructor
            /// @param[in]  i_procChipTgt       fapi2 target for P9 chip
            /// @param[in]  i_plat              platform id
            /// @param[in]  i_imageHdrBaseAddr  sram address of start of image header
            /// @param[in]  i_traceBufBaseAddr  sram address of start of trace buffer
            /// @param[in]  i_globalBaseAddr    sram address of start of global variables
            PlatPmComplex( const fapi2::Target< fapi2::TARGET_TYPE_PROC_CHIP >
                                    i_procChipTgt,
                           PmComplexPlatId i_plat = PLAT_NONE,
                           uint32_t i_imageHdrBaseAddr = 0,
                           uint32_t i_traceBufBaseAddr = 0,
                           uint32_t i_globalBaseAddr = 0 );

            /// @brief  destructor
            virtual ~PlatPmComplex() { };

            /// @brief      Initializes the PM FFDC Section Header in HOMER
            /// @param[in]  i_pHomerBuf  pointer to base of P9 HOMER.
            //  @return     fapi2 return code
            virtual fapi2::ReturnCode init ( void* i_pHomerBuf );

            /// @brief      Collects specified FFDC to PM FFDC section of HOMER
            /// @param[in]  i_pHomerBuf  points to base of P9 HOMER.
            /// @param[in]  i_ffdcType   indicates the content type to collect
            //  @return     fapi2 return code.
            virtual fapi2::ReturnCode collectFfdc( void*   i_pHomerBuf,
                                                   uint8_t i_ffdcType = ALL );

            /// @brief returns proc chip target associated with platform
            fapi2::Target< fapi2::TARGET_TYPE_PROC_CHIP > getProcChip() const { return iv_procChip; }

            /// @brief      collects FFDC pertaining to a given target.
            /// @param[in]  i_pBuf          points to base of FFDC buffer.
            /// @param[in]  i_dataType      indicates the content type to collect
            /// @param[in]  i_exTgt         ex target
            /// @param[in]  o_ffdcLength    length of FFDC in bytes
            /// @return     fapi2 return code.
            /// @note       function intends to copy FFDC pertaining to CME and SGPE to
            ///             an error log.
            virtual fapi2::ReturnCode collectPartialFfdc( void * i_pBuf, FfdcDataType i_dataType,
                                                          fapi2::Target<fapi2::TARGET_TYPE_EX >& i_exTgt,
                                                          uint32_t & o_ffdcLength );

            /// @brief      collects FFDC pertaining to a given target.
            /// @param[in]  i_pBuf          points to base of FFDC buffer.
            /// @param[in]  i_dataType      indicates the content type to collect
            /// @param[in]  o_ffdcLength    length of FFDC in bytes
            /// @return     fapi2 return code.
            /// @note       function intends to copy FFDC pertaining to CME and SGPE to
            ///             an error log.
            virtual fapi2::ReturnCode collectPartialFfdc( void * i_pBuf, FfdcDataType i_dataType,
                                                          uint32_t & o_ffdcLength );

            /// @brief  sets start address of platform's trace buffer.
            void setTraceBufAddr (uint32_t i_addr)
            { iv_traceBufBaseAddress = i_addr; }

            ///@brief returns instance id.
            PmComplexPlatId getPlatId() { return iv_plat ; }

        protected:

           ///@brief sets the validity of a section in the PmFfdcHeader
           ///@param[in]    i_pHomerBuf Base address of PM FFDC in HOMER
           ///@param[in]    i_pmFfdcSectionState See PmFfdcSectionState
           ///@param[in]    i_valid true:  sets the section valid
           ///                      false: sets the section invalid
           ///@return      N.A.
           void setPmFfdcSectionValid ( void*    i_pHomerBuf,
                                        uint16_t i_pmFfdcSectionState,
                                        bool     i_valid = true );

            ///@brief reads the PPE Halt State from XSR, w/o halting the PPE
            ///@param[in]  i_xirBaseAddress XCR SCOM Address of the PPE
            ///@param[in]  i_pHomerOffset   PPE section base address in HOMER
            ///@return  fapi2 return code
            fapi2::ReturnCode readPpeHaltState (
                      const uint64_t i_xirBaseAddress,
                      const uint8_t* i_pHomerOffset );

            ///@brief collects PPE State (XIRs, SPRs, GPRs) to a loc in HOMER
            ///@param[in] i_xirBaseAddress XCR SCOM Address of the PPE
            ///@param[in] i_pHomerOffset   PPE section base address in HOMER
            ///@param[in] i_mode           PPE_DUMP_MODE, defaults to HALT
            ///@return  fapi2 return code
            fapi2::ReturnCode collectPpeState (
                   const uint64_t i_xirBaseAddress,
                   const uint8_t* i_pHomerOffset,
                   const PPE_DUMP_MODE i_mode = FORCE_HALT );

            ///@brief collects FFDC from CME/OCC SRAM
            ///@param[in]   i_chipletTarget     fapi2 target for EX or Proc
            ///@param[in]   i_pSramData         points to HOMER location containing SRAM contents
            ///@param[in]   i_dataType          type of FFDC data
            ///@param[in]   i_sramLength        length of SRAM FFDC in bytes
            ///@return  fapi2 return code
            fapi2::ReturnCode collectSramInfo( const fapi2::Target< fapi2::TARGET_TYPE_EX >& i_exTgt,
                                               uint8_t * i_pSramData,
                                               FfdcDataType i_dataType,
                                               uint32_t i_sramLength );

            fapi2::ReturnCode collectSramInfo( const fapi2::Target< fapi2::TARGET_TYPE_PROC_CHIP > & i_procChip,
                                               uint8_t * i_pSramData,
                                               FfdcDataType i_dataType,
                                               uint32_t i_sramLength );


            ///@brief  updates parts of PPE FFDC Header common for all platforms.
            ///param[in]    i_pFfdcHdr      points to the PPE FFDC header
            ///param[in]    i_sectionsValid bit vector summarizing FFDC validity
            fapi2::ReturnCode updatePpeFfdcHeader( PpeFfdcHeader * i_pFfdcHdr,
                                                   uint16_t i_sectionsValid );

            ///@brief  update header for the FIR FFDC section
            ///param[in]    i_pFfdcHdr      pointer to FIR FFDC header in HOMER
            ///param[in]    i_pos           chiplet position
            ///param[in]    i_ffdcValid     true if valid, false otherwise
            ///@return  fapi2 return code
            fapi2::ReturnCode updateFirFfdcHeader( uint8_t* i_pFfdcHdr,
                                                   uint8_t  i_pos,
                                                   bool     i_ffdcValid);


            ///@brief  Collects register data
            ///param[in]    i_chipletTarget Chip/chilpet target
            ///param[out]   o_pHomerBuf     Homer base address to fill register
            //                              data
            // param[in]    i_ffdcId        Hwp ffdc id to know register
            //                              collection type
            ///@return  fapi2 return code
            template<fapi2::TargetType T>
            fapi2::ReturnCode collectRegisterData( const fapi2::Target<T>& i_chipletTarget,
                                                   uint8_t* o_pHomerBuf,
                                                   fapi2::HwpFfdcId i_ffdcId);
            #ifndef __HOSTBOOT_MODULE
            ///@brief to debug FFDC contents collected from SRAM.
            ///param[in]    i_pSram     points to location of SRAM info in HOMER.
            ///param[in]    i_len       length of info.
            ///@return  fapi2 return code
            fapi2::ReturnCode debugSramInfo( uint8_t * i_pSram, uint32_t i_len );
            #endif

        private:
            fapi2::Target< fapi2::TARGET_TYPE_PROC_CHIP > iv_procChip;  // processor chip target
            uint32_t iv_imageHeaderBaseAddress;     // base address of platform's image header
            uint32_t iv_traceBufBaseAddress;        // base address of platforms's trace buffer
            uint32_t iv_globalBaseAddress;          // base address of platform's global variables
            PmComplexPlatId iv_plat;
    };

    //---------------------------------------------------------------------------------------------

    template<fapi2::TargetType T>
    fapi2::ReturnCode PlatPmComplex::collectRegisterData (
                      const fapi2::Target<T>& i_chipletTarget,
                      uint8_t *o_pHomerBuf,
                      fapi2::HwpFfdcId i_ffdcId )
    {
        FAPI_DBG(">> collectRegisterData");
        std::vector<uint32_t> l_cfamAddresses;
        std::vector<uint64_t> l_scomAddresses;
        uint32_t l_ffdcRegReadSize = 0;
        uint32_t l_offset = 0;
        fapi2::ScomReader<T> l_scomReader(i_chipletTarget);

        fapi2::getAddressData(i_ffdcId, l_scomAddresses, l_cfamAddresses, l_ffdcRegReadSize);

        FAPI_TRY((fapi2::collectRegisterAndAddressData<uint64_t,
                    fapi2::ScomReader<T> >(l_scomAddresses, l_scomReader,
                                        l_offset, o_pHomerBuf)),
                   "Failed in collectRegisterAndAddressData");

    fapi_try_exit:
        FAPI_DBG("<< collectRegisterData");
        return fapi2::current_err;
    };

    //---------------------------------------------------------------------------------------------

    // function pointer typedef definition for HWP call support
    typedef fapi2::ReturnCode (*p9_pm_recovery_ffdc_base_FP_t)
            ( const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>&,
              const void* );

    extern "C"
    {
    // -----------------------------------------------------------------------------
    // Function prototypes
    // -----------------------------------------------------------------------------
    ///
    /// @brief Initializes the PM FFDC section in HOMER with default headers and
    ///        other FFDC to be collection before the PM Reset Flow
    ///
    /// @param[in] i_procChipTarget Proc Chip target
    /// @param[in] i_pHomerImage    Pointer to the base of the chip HOMER region
    ///
    /// @return FAPI2_RC_SUCCESS on success or error return code
    ///
        fapi2::ReturnCode p9_pm_recovery_ffdc_base
        ( const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_procChipTarget,
          void* i_pHomerImage );
    }

} //namespace p9_stop_recov_ffdc ends

#endif //__P9_PM_RECOVERY_FFDC_BASE_
