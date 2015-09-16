/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/ipl/hwp/p9_pm_ocb_init.H $                */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* EKB Project                                                            */
/*                                                                        */
/* COPYRIGHT 2015                                                         */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
///
/// @file  p9_pm_ocb_init.H
/// @brief Setup and configure OCB channels
///
// *HWP HWP Owner: Amit Kumar <akumar3@us.ibm.com>
// *HWP FW Owner: Sangeetha T S <sangeet2@in.ibm.com>
// *HWP Team: PM
// *HWP Level: 2
// *HWP Consumed by: FSP:HS

#ifndef _P9_PM_OCB_INIT_H_
#define _P9_PM_OCB_INIT_H_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------

#include <p9_pm.H>
#include <fapi2.H>
#include <p9_misc_scom_addresses.H>

//------------------------------------------------------------------------------
// Constants definitions
//------------------------------------------------------------------------------
namespace p9ocb
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
    OCB_TYPE_PULLQ              ///< Circular Pull Queue
};

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

typedef fapi2::ReturnCode (*p9_pm_ocb_init_FP_t) (
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>&,
    const p9pm::PM_FLOW_MODE,
    const p9ocb::PM_OCB_CHAN_NUM,
    const p9ocb::PM_OCB_CHAN_TYPE,
    const uint32_t,
    const uint8_t,
    const p9ocb::PM_OCB_CHAN_OUFLOW,
    const p9ocb::PM_OCB_ITPTYPE);

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
///                                PM_RESET/PM_INIT/PM_SETUP_ALL
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
    fapi2::ReturnCode p9_pm_ocb_init(
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
        const p9pm::PM_FLOW_MODE      i_mode,
        const p9ocb::PM_OCB_CHAN_NUM     i_ocb_chan,
        const p9ocb::PM_OCB_CHAN_TYPE    i_ocb_type,
        const uint32_t                   i_ocb_bar,
        const uint8_t                    i_ocb_q_len,
        const p9ocb::PM_OCB_CHAN_OUFLOW  i_ocb_ouflow_en,
        const p9ocb::PM_OCB_ITPTYPE      i_ocb_itp_type);
} // extern "C"

#endif // _P9_PM_OCB_INIT_H_

