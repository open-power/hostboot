/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/pm/p10_pm_callout.H $     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017,2020                        */
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
///
/// @file    p10_pm_callout.H
/// @brief   generates a vector of dead cores in response to PM malfunction alert
/// @details In case of PM Malfunction Alert, when HBRT invokes PRD by setting a
//           bit in OCC LFIR, PRD calls this HWP. Procedure walks the bits of
//           OCC Flag2 register and generates a bit vector of cores considered
//           dead by PHYP. It also points to caller a location of FFDC which
//           needs to be committed to an error log. Procedure updates QCSR and
//           CCSR and also cleans up OCC Flag2 and some interrupt registers.
///
///
//----------------------------------------------------------------------------
// *HWP HWP Owner       : Greg Still <stillgs@us.ibm.com>
// *HWP FW Owner        : Prem S Jha <premjha2@in.ibm.com>
// *HWP Team            : PM
// *HWP Level           : 2
// *HWP Consumed by     : HB
//----------------------------------------------------------------------------

#ifndef __P10_PM_CALLOUT
#define __P10_PM_CALLOUT

//------------------------------------------------------------------------------
// Includes
// ------------------------------------------------------------------------------
#include <fapi2.H>

enum RasAction
{
    NO_CALLOUT           =   0,
    FW_CALLOUT           =   1,
    CORE_CALLOUT         =   2,
    PROC_CHIP_CALLOUT    =   3,
    MEMORY_CALLOUT       =   4,
};

typedef uint8_t errlver_t;

///@brief    models a sub-section of STOP Recovery summary.
///@note     caller of p10_pm_callout passes in an empty vector
///          however, HWP populates it with pointers to all
///          summary sub-section.
struct StopErrLogSectn
{
    uint8_t*            iv_pBufPtr;
    uint16_t            iv_bufSize;
    errlver_t           iv_subsec;
    StopErrLogSectn( uint8_t* i_bufPtr, uint16_t i_bufSize, errlver_t i_subSectn )
        : iv_pBufPtr( i_bufPtr ), iv_bufSize( i_bufSize ), iv_subsec( i_subSectn )
    { }

    StopErrLogSectn( )
        : iv_pBufPtr( NULL ),
          iv_bufSize( 0 ),
          iv_subsec(  0 )
    { }
};

// function pointer typedef definition for HWP call support
typedef fapi2::ReturnCode (*p10_pm_callout_FP_t) (
    void* i_pHomer,
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_procChipTgt,
    fapi2::buffer <uint32_t>& o_deadCores,
    std::vector < StopErrLogSectn >& o_ffdcList,
    RasAction&   o_rasAction );

extern "C"
{
    /// @brief      analyzes Phyp generated dead core vector for clean up and guard.
    /// @param[in]  i_pHomerBase        points to base of HOMER buffer.
    /// @param[in]  i_procChipTgt       fapi2 target for P10 chip.
    /// @param[out] o_deadCores         bit vector of dead cores which needs to be runtime deconfigured
    /// @param[out] o_ffdcList          points to a list of STOP FFDC summary sub-sections.
    /// @param[out] o_rasAction         RAS action specified for FW.
    /// @return     fapi2 return code.
    /// @note       caller is expected to pass an empty vector. HWP will
    ///             populate a vector with a list pointers to various parts of
    ///             STOP Recovery FFDC summary. Highest priority sub-section
    ///             is pushed to vector first followed by sub-section of lower
    ///             priority. Bit vector is left aligned. Bits to be considered
    ///             are bit0 to bit 31. If bit 0 is set, it means Core0 is
    ///             marked dead by Phyp.
    ///

    fapi2::ReturnCode p10_pm_callout(
        void* i_pHomerBase,
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_procChipTgt,
        fapi2::buffer <uint32_t>& o_deadCores,
        std::vector < StopErrLogSectn >& o_ffdcList,
        RasAction&   o_rasAction  );
}
#endif //__P10_PM_CALLOUT
