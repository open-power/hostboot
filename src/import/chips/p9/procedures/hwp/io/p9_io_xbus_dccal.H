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

typedef fapi2::Target<fapi2::TARGET_TYPE_XBUS> XBUS_TGT;


enum XbusDccalMode : uint8_t
{
    Noop            = 0x00, // Runs nothing, can be used for dry runs
    TxZcalRunBus    = 0x01, // Runs Tx Zcal on a per bus basis
    TxZcalSetGrp    = 0x02, // Sets Tx Zcal Group Settings based on the bus results
    RxDccalStartGrp = 0x03, // Starts Rx Dccal on a per group basis
    RxDccalCheckGrp = 0x04  // Checks/polls Rx Dccal on a per group basis
};

typedef fapi2::ReturnCode (*p9_io_xbus_dccal_FP_t)( const XbusDccalMode, const XBUS_TGT, const uint8_t );

extern "C"
{

    /**
     * @brief A I/O EDI+ Procedure that runs Rx Dccal and Tx Z Impedance calibration
     * on every group of the EDI+ XBUS.
     * @param[in] i_mode  XbusDccalMode -- selects what operation to perform
     * @param[in] i_tgt   FAPI2 Target
     * @param[in] i_grp   Clock Group
     * @retval ReturnCode
     */
    fapi2::ReturnCode p9_io_xbus_dccal(
        const XbusDccalMode i_mode,
        const XBUS_TGT      i_tgt ,
        const uint8_t       i_grp );

} // extern "C"

#endif // _P9_IO_XBUS_DCCAL_H
