/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/pm/p9_check_idle_stop_done.H $ */
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
#ifndef __CHECK_IDLE_STOP_H_
#define __CHECK_IDLE_STOP_H_


///
/// @file   p9_check_idle_stop_done.H
/// @brief  HWP interface that collects relevant PM complex info in case of activate core failure.
///
/// *HWP HWP Owner:      Greg Still <stillgs@us.ibm.com>
/// *HWP FW Owner:       Prem S Jha <premjha2@in.ibm.com>
/// *HWP Team:           PM
/// *HWP Level:          2
/// *HWP Consumed by:    Hostboot:Phyp
//

//--------------------------------------------------------------------------
// Includes
//--------------------------------------------------------------------------
#include <fapi2.H>
#include <stdint.h>

typedef fapi2::ReturnCode( *p9_check_idle_stop_done_FP_t )( fapi2::Target< fapi2::TARGET_TYPE_CORE >& i_coreTgt );

extern "C"
{

    namespace p9_check_idle_stop
    {

/// @brief  analyzes state of PM complex and returns its status
/// @param[in] i_exTgt     fapi2 target for a core
/// @return fapi2 retuirn code.

    fapi2::ReturnCode p9_check_idle_stop_done( fapi2::Target< fapi2::TARGET_TYPE_CORE >& i_coreTgt );

    } //namespace p9_check_idle_stop ends

} // extern C
#endif //__CHECK_IDLE_STOP_H_
