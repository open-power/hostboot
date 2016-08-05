/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/io/p9_io_xbus_dccal.H $    */
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
/// @file p9_io_xbus_dccal.H
/// @brief Run Dccal on the link.
///-----------------------------------------------------------------------------
/// *HWP HWP Owner        : Chris Steffen <cwsteffen@us.ibm.com>
/// *HWP HWP Backup Owner : Gary Peterson <garyp@us.ibm.com>
/// *HWP FW Owner         : Jamie Knight <rjknight@us.ibm.com>
/// *HWP Team             : IO
/// *HWP Level            : 3
/// *HWP Consumed by      : FSP:HB
///-----------------------------------------------------------------------------

#ifndef _P9_IO_XBUS_DCCAL_H
#define _P9_IO_XBUS_DCCAL_H

//-----------------------------------------------------------------------------
//  fapi2 Includes
//-----------------------------------------------------------------------------
#include <fapi2.H>


typedef fapi2::ReturnCode (*p9_io_xbus_dccal_FP_t)
( const fapi2::Target < fapi2::TARGET_TYPE_XBUS>&, const uint8_t& );

extern "C"
{

    /**
     * @brief A I/O EDI+ Procedure that runs Rx Dccal and Tx Z Impedance calibration
     * on every group of the EDI+ XBUS.
     * @param[in] i_target FAPI2 Target
     * @retval ReturnCode
     */
    fapi2::ReturnCode p9_io_xbus_dccal(
        const fapi2::Target < fapi2::TARGET_TYPE_XBUS >& i_target,
        const uint8_t&                                   i_group );

} // extern "C"

#endif // _P9_IO_XBUS_DCCAL_H
