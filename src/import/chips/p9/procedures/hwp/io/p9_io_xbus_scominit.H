/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/io/p9_io_xbus_scominit.H $ */
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
/// @file p9_io_xbus_scominit.H
/// @brief Invoke XBUS initfile (FAPI)
///
//----------------------------------------------------------------------------
// *HWP HWP Owner       : Chris Steffen <cwsteffen@us.ibm.com>
// *HWP HWP Backup Owner: Gary Peterson <garyp@us.ibm.com>
// *HWP FW Owner        : Sumit Kumar <sumit_kumar@in.ibm.com>
// *HWP Team            : IO
// *HWP Level           : 2
// *HWP Consumed by     : FSP:HB
//----------------------------------------------------------------------------


#ifndef P9_IO_XBUS_SCOMINIT_H_
#define P9_IO_XBUS_SCOMINIT_H_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <fapi2.H>

//------------------------------------------------------------------------------
// Structure definitions
//------------------------------------------------------------------------------

// function pointer typedef definition for HWP call support
typedef fapi2::ReturnCode (*p9_io_xbus_scominit_FP_t)
(const fapi2::Target<fapi2::TARGET_TYPE_XBUS>& i_target,
 const fapi2::Target<fapi2::TARGET_TYPE_XBUS>& i_connected_target,
 const uint8_t i_group);

extern "C" {

//------------------------------------------------------------------------------
// Function prototypes
//------------------------------------------------------------------------------

    /**
     * @brief HWP that calls the XBUS SCOM initfiles
     *
     * Should be called for all valid/connected XBUS endpoints
     *
     * @param[in] i_target           Reference to XBUS chiplet target
     *            i_connected_target Reference to connected XBUS chiplet target
     *                                    - p9.xbus.g0.scom.initfile
     *                                    - p9.xbus.g1.scom.initfile
     *            i_group            Reference to XBUS group-0/1
     *
     * @return FAPI2_RC_SUCCESS on success, error otherwise
     */
    fapi2::ReturnCode p9_io_xbus_scominit(
        const fapi2::Target<fapi2::TARGET_TYPE_XBUS>& i_target,
        const fapi2::Target<fapi2::TARGET_TYPE_XBUS>& i_connected_target,
        const uint8_t i_group);


} // extern "C"

#endif // P9_IO_XBUS_SCOMINIT_H_
