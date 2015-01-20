/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/tod_init/proc_tod_setup//proc_tod_check_osc.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015                             */
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
// $Id: proc_tod_check_osc.H,v 1.1 2014/12/11 17:01:53 jklazyns Exp $
//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2012
// *! All Rights Reserved -- Property of IBM
// *! ***  ***
// *!
// *! TITLE : proc_tod_check_osc.H
// *!
// *! DESCRIPTION : Header for proc_tod_check_osc.C
// *!
// *! OWNER NAME  : Nick Klazynski  Email: jklazyns@us.ibm.com
// *! BACKUP NAME :                 Email:
// *!
// *! ADDITIONAL COMMENTS :
// *!
//------------------------------------------------------------------------------

#ifndef PROC_TOD_CHECK_OSC_H_
#define PROC_TOD_CHECK_OSC_H_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <fapi.H>
#include "proc_tod_utils.H"

//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Structure definitions
//------------------------------------------------------------------------------

// function pointer typedef definition for HWP call support
typedef fapi::ReturnCode (*proc_tod_check_osc_FP_t) (const fapi::Target*,
        proc_tod_setup_osc_sel*);

//------------------------------------------------------------------------------
// Function prototypes
//------------------------------------------------------------------------------

extern "C"
{

/**
 * @brief Checks oscillator validality for a given target
 *
 * @param[in]  i_target   FAPI target which will have its oscillator
 *                        validity checked
 *
 * @param[out] o_osc_stat Oscillator(s) which passed the validity check
 *
 * @return FAPI_RC_SUCCESS if the oscillators were successfully tested
 *         (o_osc_stat will have the check's result)
 *         else FAPI or ECMD error is sent through
 */
fapi::ReturnCode proc_tod_check_osc(const fapi::Target* i_target,
        proc_tod_setup_osc_sel* o_osc_stat);

} // extern "C"

#endif // PROC_TOD_CHECK_OSC_H_
