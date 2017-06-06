/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/io/p9_io_common.H $        */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2017                        */
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
/// @file p9_io_common.H
/// @brief IO Common Functions.
///----------------------------------------------------------------------------
/// *HWP HWP Owner        : Chris Steffen <cwsteffen@us.ibm.com>
/// *HWP HWP Backup Owner : Gary Peterson <garyp@us.ibm.com>
/// *HWP FW Owner         : Jamie Knight <rjknight@us.ibm.com>
/// *HWP Team             : IO
/// *HWP Level            : 3
/// *HWP Consumed by      : FSP:HB
///----------------------------------------------------------------------------
///
/// @verbatim
/// IO Common Functions.
///
/// @endverbatim
///----------------------------------------------------------------------------

#ifndef P9_IO_COMMON_H_
#define P9_IO_COMMON_H_

//* *****************************
//* Defines
//* *****************************
//-----------------------------------------------------------------------------
//  FAPI Includes
//-----------------------------------------------------------------------------
#include <fapi2.H>

typedef fapi2::Target<fapi2::TARGET_TYPE_XBUS> XBUS_TGT;
typedef fapi2::Target<fapi2::TARGET_TYPE_DMI> DMI_PROC_TGT;
typedef fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP> DMI_CN_TGT;

extern "C"
{

    /**
     * @brief Shorten timers if we are running in simulation
     *        a right aligned value.
     * @param[in] i_tgt     FAPI2 Target
     * @param[in] i_grp     Clock group
     * @return Field Data
     */
    fapi2::ReturnCode p9_io_xbus_shorten_timers(
        const XBUS_TGT& i_tgt,
        const uint8_t  i_grp );

    /**
     * @brief Shorten timers if we are running in simulation
     *        a right aligned value.
     * @param[in] i_tgt     FAPI2 Target
     * @return Field Data
     */
    fapi2::ReturnCode p9_io_dmi_proc_shorten_timers(const DMI_PROC_TGT& i_tgt);

}    /**
     * @brief Shorten timers if we are running in simulation
     *        a right aligned value.
     * @param[in] i_tgt     FAPI2 Target
     * @return Field Data
     */
fapi2::ReturnCode p9_io_dmi_cn_shorten_timers(const DMI_CN_TGT& i_tgt);


#endif /* P9_IO_COMMON_H_ */
