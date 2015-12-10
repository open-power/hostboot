/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/fapi2/plat_hwp_invoker.C $                            */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2016                        */
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
/// @file plat_hwp_invoker.C
///
/// @brief Implements the platform functions that access attributes for FAPI2
///


#include <plat_hwp_invoker.H>
#include <return_code.H>

//******************************************************************************
// Implementation
//******************************************************************************

namespace fapi2
{

  //@todo RTC:124673
    /**
    * @brief Converts a fapi::ReturnCode to a HostBoot PLAT error log
    */
    errlHndl_t fapiRcToErrl(ReturnCode & io_rc,
                            ERRORLOG::errlSeverity_t i_sev)
    {
        errlHndl_t errl = NULL;
        return errl;
    }
}
//end fapi2