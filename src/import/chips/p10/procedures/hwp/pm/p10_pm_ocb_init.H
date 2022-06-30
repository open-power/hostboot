/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/pm/p10_pm_ocb_init.H $    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2023                        */
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
/// @file  p10_pm_ocb_init.H
/// @brief Setup and configure OCB channels
///
// *HWP Backup HWP Owner: Greg Still <stillgs@us.ibm.com>
// *HWP FW Owner        : Amit Tendolkar <amit.tendolkar@in.ibm.com>
// *HWP Team: PM
// *HWP Level: 3
// *HWP Consumed by: SBE:HS

#ifndef _PM_OCB_INIT_H_
#define _PM_OCB_INIT_H_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------

#include <p10_pm.H>
#include <fapi2.H>

//------------------------------------------------------------------------------
// Constants definitions
//------------------------------------------------------------------------------
namespace ocb
{
/// @enum PM_OCB_CHAN_NUM
enum PM_OCB_CHAN_NUM
{
    OCB_CHAN0 = 0x00,           ///< OCB  Channel 0
    OCB_CHAN1 = 0x01,           ///< OCB  Channel 1
    OCB_CHAN2 = 0x02,           ///< OCB  Channel 2
    OCB_CHAN3 = 0x03            ///< OCB  Channel 3
};

/// @enum PM_OCB_CHAN_TYPE
enum PM_OCB_CHAN_TYPE
{
    OCB_TYPE_NULL,              ///< Do nothing
    OCB_TYPE_LIN,               ///< Linear w/o address incrementation
    OCB_TYPE_LINSTR,            ///< Linear with address incrementation
    OCB_TYPE_LINWIN,            ///< Linear window mode
    OCB_TYPE_CIRC,              ///< Circular mode
    OCB_TYPE_PUSHQ,             ///< Circular Push Queue
    OCB_TYPE_PULLQ,             ///< Circular Pull Queue
    OCB_TYPE_MAX_TYPES          ///<
};

#define PM_OCB_CHAN_TYPE_STR { \
        "NULL",     \
        "LIN",      \
        "LINSTR",   \
        "LINWIN",   \
        "CIRC",     \
        "PUSHQ",    \
        "PULLQ"     \
    }

/// @enum PM_OCB_CHAN_REG
enum PM_OCB_CHAN_REG
{
    OCB_UPD_PIB_REG,            ///< Update PIB Register
    OCB_UPD_PIB_OCI_REG         ///< Update OCI Register
};

/// @enum PM_OCB_CHAN_OUFLOW
enum PM_OCB_CHAN_OUFLOW
{
    OCB_Q_OUFLOW_NULL,          ///< Do nothing
    OCB_Q_OUFLOW_EN,            ///< Overflow/Underflow Enable
    OCB_Q_OUFLOW_DIS            ///< Overflow/Underflow Disable
};

/// @enum PM_OCB_ITPTYPE
enum PM_OCB_ITPTYPE
{
    OCB_Q_ITPTYPE_NULL,         ///< Overflow/Underflow Disable
    OCB_Q_ITPTYPE_FULL,         ///< Interrupt on Full
    OCB_Q_ITPTYPE_NOTFULL,      ///< Interrupt on Not Full
    OCB_Q_ITPTYPE_EMPTY,        ///< Interrupt on Empty
    OCB_Q_ITPTYPE_NOTEMPTY      ///< Interrupt on Not Empty
};
} // END OF NAMESPACE p9ocb

typedef fapi2::ReturnCode (*p10_pm_ocb_init_FP_t) (
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>&,
    const pm::PM_FLOW_MODE,
    const ocb::PM_OCB_CHAN_NUM,
    const ocb::PM_OCB_CHAN_TYPE,
    const uint32_t,
    const uint8_t,
    const ocb::PM_OCB_CHAN_OUFLOW,
    const ocb::PM_OCB_ITPTYPE);

extern "C"
{
//------------------------------------------------------------------------------
// Function prototype
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
///
/// @brief Configure OCB Channels based on mode and parameters passed
///
/// @param [in]   i_target         Chip Target
///
/// @param [in]   i_mode           Mode of operation from enum PM_FLOW_MODE.
///                                PM_HALT/PM_START/PM_SETUP_ALL
///
/// @param [in]   i_ocb_chan       Channel to setup from enum PM_OCB_CHAN_NUM.
///                                OCB_CHAN0 : OCB  Channel 0
///                                OCB_CHAN1 : OCB  Channel 1
///                                OCB_CHAN2 : OCB  Channel 2
///                                OCB_CHAN3 : OCB  Channel 3
///
/// @param [in]   i_ocb_type       Type of channel from PM_OCB_CHAN_TYPE.
///                                OCB_TYPE_LIN:Linear w/o address increment
///                                OCB_TYPE_LINSTR:Linear with address increment
///                                OCB_TYPE_CIRC:Circular mode
///                                OCB_TYPE_PUSHQ:Circular Push Queue
///                                OCB_TYPE_PULLQ:Circular Pull Queue
///
/// @param [in]   i_ocb_bar        32-bit channel base address(29 bits + "000")
///
/// @param [in]   i_ocb_q_len      0-31 length of push or pull queue in
///                                (queue_length + 1) * 8B
///
/// @param [in]   i_ocb_ouflow_en  Channel flow control from PM_OCB_CHAN_OUFLOW
///                                OCB_Q_OUFLOW_EN:Overflow/Underflow Enable
///                                OCB_Q_OUFLOW_DIS:Overflow/Underflow Disable
///
/// @param [in]   i_ocb_itp_type   Channel interrupt control from PM_OCB_ITPTYPE
///                                OCB_Q_ITPTYPE_FULL:Interrupt on Full
///                                OCB_Q_ITPTYPE_NOTFULL:Interrupt on Not Full
///                                OCB_Q_ITPTYPE_EMPTY:Interrupt on Empty
///                                OCB_Q_ITPTYPE_NOTEMPTY:Interrupt on Not Empty
///
/// @return FAPI2_RC_SUCCESS if success, else error code.
///
    fapi2::ReturnCode p10_pm_ocb_init(
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
        const pm::PM_FLOW_MODE          i_mode,
        const ocb::PM_OCB_CHAN_NUM      i_ocb_chan,
        const ocb::PM_OCB_CHAN_TYPE     i_ocb_type,
        const uint32_t                  i_ocb_bar,
        const uint8_t                   i_ocb_q_len,
        const ocb::PM_OCB_CHAN_OUFLOW   i_ocb_ouflow_en,
        const ocb::PM_OCB_ITPTYPE       i_ocb_itp_type);
} // extern "C"

#endif // _P9_PM_OCB_INIT_H_
