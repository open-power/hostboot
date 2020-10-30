/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/io/p9a_io_omi_prbs.H $     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2020                        */
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
/// @file p9a_io_omi_prbs.H
/// @brief Drives PRBS on the OMI Link.
///-----------------------------------------------------------------------------
/// *HWP HWP Owner        : Chris Steffen <cwsteffen@us.ibm.com>
/// *HWP HWP Backup Owner : Gary Peterson <garyp@us.ibm.com>
/// *HWP FW Owner         : Jamie Knight <rjknight@us.ibm.com>
/// *HWP Team             : IO
/// *HWP Level            : 3
/// *HWP Consumed by      : FSP:HB
///-----------------------------------------------------------------------------

#ifndef _P9A_IO_OMI_PRBS_H
#define _P9A_IO_OMI_PRBS_H

//-----------------------------------------------------------------------------
//  fapi2 Includes
//-----------------------------------------------------------------------------
#include <fapi2.H>

typedef fapi2::Target<fapi2::TARGET_TYPE_OMIC> OMIC_TGT;


typedef fapi2::ReturnCode (*p9a_io_omi_prbs_FP_t)( const OMIC_TGT, const bool );

extern "C"
{

    /**
     * @brief A I/O OMI Procedure that drives PRBS on an OMI Link.
     * @param[in] i_tgt          FAPI2 Target
     * @param[in] i_on           True = Enable PRBS, False = Disable PRBS
     * @retval ReturnCode
     */
    fapi2::ReturnCode p9a_io_omi_prbs(const OMIC_TGT i_tgt, const bool i_on);

} // extern "C"

#endif // _P9A_IO_OMI_PRBS_H
