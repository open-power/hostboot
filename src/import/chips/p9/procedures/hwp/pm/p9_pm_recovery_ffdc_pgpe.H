/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/pm/p9_pm_recovery_ffdc_pgpe.H $ */
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
#ifndef __PM_RECOVERY_FFDC_PGPE_
#define __PM_RECOVERY_FFDC_PGPE_

///
/// @file   p9_pm_recovery_ffdc_pgpe.H
/// @brief  Models PGPE platform for the FFDC collection of PM complex
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

    class PlatPgpe : public PlatPmComplex
    {
            public:
            /// @brief  constructor
            PlatPgpe( const fapi2::Target< fapi2::TARGET_TYPE_PROC_CHIP > i_procChipTgt );

            /// @brief  destructor
            virtual ~PlatPgpe() { };

            /// @brief      collects FFDC pertaining to all functional PGPEs in the chip.
            /// @param[in]  i_pHomerBuf     points to base of P9 HOMER.
            /// @return     fapi2 return code.
            fapi2::ReturnCode collectFfdc( void* i_pHomerBuf );

        private:
            /// @brief      collects trace info from PGPE's SRAM buffer.
            /// @param[in]  i_pHomerBuf     points to location of HOMER meant for PGPE Trace info.
            /// @return     fapi2 return code.
            fapi2::ReturnCode  collectTrace( uint8_t * i_pHomerBuf );

            /// @brief      collects  global variables from PGPE's's SRAM.
            /// @param[in]  i_pHomerBuf     points to location of HOMER meant for PGPE's global variable
            /// @return     fapi2 return code.
            fapi2::ReturnCode  collectGlobals( uint8_t * i_pHomerBuf );

            /// @brief      collects PGPE state
            /// @param[in]  i_pHomerBuf     points to location of HOMER meant for PGPE's state.
            /// @return     fapi2 return code.
            fapi2::ReturnCode  collectPgpeState( uint8_t * i_pHomerBuf );

            /// @brief      collects internal register info for a PGPE
            /// @param[in]  i_pHomerBuf     points to location of HOMER meant for PGPE internal register.
            /// @return     fapi2 return code.
            fapi2::ReturnCode  collectInternalReg( uint8_t * i_pHomerBuf );

            /// @brief      collects PGPE Image Header info from PGPE SRAM buffer.
            /// @param[in]  i_pHomerBuf     points to location of HOMER meant for PGPE's header.
            /// @return     fapi2 return code.
            fapi2::ReturnCode  collectImageHeader( uint8_t * i_pHomerBuf );

            /// @brief updates the PGPE FFDC Header
            ///@param[in]   i_pHomerBuf     points to a location in HOMER meant for PGPE FFDC Header
            ///@param[in]   i_ffdcValid     true if FFDC is valid, false otherwise
            ///@param[in]   i_haltCondition hlat state of PGPE
            ///@return      fapi2 return code.
            ///@note        refer to PPE Spec for details on halt state.

            fapi2::ReturnCode updatePgpeFfdcHeader( uint8_t * i_pHomerBuf,
                                                   bool i_ffdcValid, uint8_t i_haltCondition );

            ///@brief returns type of platform
            PmComplexPlatId getPlatType() { return iv_plat; }

        private:
            PmComplexPlatId iv_plat;
    };

extern "C"
{
    typedef fapi2::ReturnCode( *p9_pm_recovery_ffdc_pgpe_FP_t )
            ( const fapi2::Target< fapi2::TARGET_TYPE_PROC_CHIP > & i_procChipTgt,
              void * i_pgpeFfdcBuf );
}

} //namespace p9_stop_recov_ffdc ends

#endif //__PM_RECOVERY_FFDC_PGPE_
