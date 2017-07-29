/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/io/p9_io_obus_linktrain.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017                             */
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
/// @file p9_io_obus_linktrain.H
/// @brief I/O Link Training on the Abus Links.
///
///-----------------------------------------------------------------------------
/// *HWP HWP Owner        : Chris Steffen <cwsteffen@us.ibm.com>
/// *HWP HWP Backup Owner : Gary Peterson <garyp@us.ibm.com>
/// *HWP FW Owner         : Jamie Knight <rjknight@us.ibm.com>
/// *HWP Team             : IO
/// *HWP Level            : 3
/// *HWP Consumed by      : FSP:HB
///-----------------------------------------------------------------------------
#ifndef _P9_IO_OBUS_TRAIN_H
#define _P9_IO_OBUS_TRAIN_H

//-----------------------------------------------------------------------------
//  System Header Include
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
//  fapi2 Includes
//-----------------------------------------------------------------------------
#include <fapi2.H>

typedef fapi2::Target<fapi2::TARGET_TYPE_OBUS> OBUS_TGT;
typedef fapi2::ReturnCode (*p9_io_obus_linktrain_FP_t)(const OBUS_TGT&);

extern "C"
{

    /**
     * @brief A HWP that runs once on every link of the ABUS(OBUS PHY).
     * @param[in] i_tgt  Reference to the Target
     * @retval    ReturnCode
     */
    fapi2::ReturnCode p9_io_obus_linktrain(const OBUS_TGT& i_tgt);

} // extern "C"

#endif // _P9_IO_OBUS_TRAIN_H
