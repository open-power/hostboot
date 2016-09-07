/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/nest/p9_mpipl_chip_cleanup.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016                             */
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
//------------------------------------------------------------------------------
//
//  (C) Copyright International Business Machines Corp. 2012
//  All Rights Reserved -- Property of IBM
//  *** IBM Confidential ***
//
///  TITLE       : p9_mpipl_chip_cleanup.H
///  DESCRIPTION : To enable MCD recovery
///
///  HWP HWP OWNER: Joshua Hannan            Email: jlhannan@us.ibm.com
///  HWP FW Owner: Thi N Tran                Email: thi@us.ibm.com
///  HWP Team: NEST
///  HWP Level: 2
///  HWP Consumed by: FSP/HB
//
//------------------------------------------------------------------------------

#ifndef _P9_MPIPL_CHIP_CLEANUP_H_
#define _P9_MPIPL_CHIP_CLEANUP_H_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <fapi2.H>

//------------------------------------------------------------------------------
// Structure Definition(s)
//------------------------------------------------------------------------------

// function pointer typedef definition for HWP call support
typedef fapi2::ReturnCode (*p9_mpipl_chip_cleanup_FP_t) (fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& );

extern "C"
{
    ///  @brief To enable MCD recovery

    ///  @param[in] 'i_target' Reference to processor chip target

    ///  @return FAPI_RC_SUCCESS if the mpipl_chip_cleanup completes successfully
    fapi2::ReturnCode p9_mpipl_chip_cleanup(fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target);
} //extern "C"

#endif
