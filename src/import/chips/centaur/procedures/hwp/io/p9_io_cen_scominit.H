/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/centaur/procedures/hwp/io/p9_io_cen_scominit.H $ */
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
///
/// @file p9_io_cen_scominit.H
/// @brief Invoke CEN initfile (FAPI)
///
///----------------------------------------------------------------------------
/// *HWP HWP Owner       : Chris Steffen <cwsteffen@us.ibm.com>
/// *HWP HWP Backup Owner: Gary Peterson <garyp@us.ibm.com>
/// *HWP FW Owner        : Jamie Knight <rjknight@us.ibm.com>
/// *HWP Team            : IO
/// *HWP Level           : 1
/// *HWP Consumed by     : FSP:HB
///----------------------------------------------------------------------------
#ifndef P9_IO_CEN_SCOMINIT_H_
#define P9_IO_CEN_SCOMINIT_H_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <fapi2.H>

//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Structure definitions
//------------------------------------------------------------------------------
typedef fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP> CEN_TGT;

// function pointer typedef definition for HWP call support
typedef fapi2::ReturnCode (*p9_io_cen_scominit_FP_t)(const CEN_TGT&);

extern "C" {

//------------------------------------------------------------------------------
// Function prototypes
//------------------------------------------------------------------------------

    /**
     * @brief HWP that calls the Centaur SCOM initfiles
     *
     * Should be called for all valid/connected OBUS endpoints
     *
     * @param[in] i_tgt           Reference to CEN chiplet target
     *                                    - p9.cen.scom.initfile
     *
     * @return FAPI2_RC_SUCCESS on success, error otherwise
     */
    fapi2::ReturnCode p9_io_cen_scominit(const CEN_TGT& i_tgt);


} // extern "C"

#endif // P9_IO_CEN_SCOMINIT_H_
