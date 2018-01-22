/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/pm/p9_pm_callout.C $       */
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
///
/// @file    p9_pm_callout.C
/// @brief   generates a vector of dead cores in response to PM malfunction alert
/// @details In case of PM Malfunction Alert, HBRT invokes PRD by setting a
///           bit in OCC LFIR.As a part of FIR bit response, PRD calls this HWP.
///           Procedure walks the bits of OCC Flag2 register and generates a bit
///           vector of cores considered dead by PHYP. It also points towards
///           a location of FFDC which needs to be committed to an error log.
///           Procedure updates QCSR and CCSR and also cleans up OCC Flag2
///           and some interrupt registers.
///
//----------------------------------------------------------------------------
// *HWP HWP Owner       : Greg Still <stillgs@us.ibm.com>
// *HWP FW Owner        : Prem S Jha <premjha2@in.ibm.com>
// *HWP Team            : PM
// *HWP Level           : 1
// *HWP Consumed by     : HB
//----------------------------------------------------------------------------
#include <p9_pm_callout.H>
#include <p9_hcd_memmap_base.H>
#include <p9_pm_recovery_ffdc_defines.H>

extern "C"
{
    fapi2::ReturnCode p9_pm_callout(
        void* i_pHomerBase,
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_procTgt,
        fapi2::buffer <uint32_t>& o_deadCores,
        std::vector < StopErrLogSectn >& o_ffdcList,
        RasAction&   i_rasAction  )
    {
        using namespace p9_stop_recov_ffdc;
        FAPI_IMP(">> p9_pm_callout" );

        FAPI_IMP("<< p9_pm_callout" );
        return fapi2::FAPI2_RC_SUCCESS;
    }

//--------------------------------------------------------------------------------------------------------

}//extern "C"
