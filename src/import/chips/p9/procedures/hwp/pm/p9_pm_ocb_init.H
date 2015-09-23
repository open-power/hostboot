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
// *HWP Level: 1
// *HWP Consumed by: FSP:HS

#ifndef _P9_PM_OCB_INIT_H_
#define _P9_PM_OCB_INIT_H_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------

#include <p9_pm.H>
#include <fapi2.H>
#if 0
    //Need to verify correct scom addresses are indeed provided in this header.
    #include <misc_scom_addresses.H>
#endif

//------------------------------------------------------------------------------
// Constants definitions
//------------------------------------------------------------------------------
namespace p9ocb
{
/// @enum P9_OCB_CHAN_NUM
enum P9_OCB_CHAN_NUM
{
    OCB_CHAN0 = 0x00,           ///< OCB  Channel 0
    OCB_CHAN1 = 0x01,           ///< OCB  Channel 1
    OCB_CHAN2 = 0x02,           ///< OCB  Channel 2
    OCB_CHAN3 = 0x03            ///< OCB  Channel 3
};

/// @enum P9_OCB_CHAN_TYPE
enum P9_OCB_CHAN_TYPE
{
    OCB_TYPE_NULL,              ///< Do nothing
    OCB_TYPE_LIN,               ///< Linear w/o address incrementation
    OCB_TYPE_LINSTR,            ///< Linear with address incrementation
    OCB_TYPE_LINWIN,            ///< Linear window mode
    OCB_TYPE_CIRC,              ///< Circular mode
    OCB_TYPE_PUSHQ,             ///< Circular Push Queue
    OCB_TYPE_PULLQ              ///< Circular Pull Queue
};

/// @enum P9_OCB_CHAN_REG
enum P9_OCB_CHAN_REG
{
    OCB_UPD_PIB_REG,            ///< Update PIB Register
    OCB_UPD_PIB_OCI_REG         ///< Update OCI Register
};

/// @enum P9_OCB_CHAN_OUFLOW
enum P9_OCB_CHAN_OUFLOW
{
    OCB_Q_OUFLOW_NULL,          ///< Do nothing
    OCB_Q_OUFLOW_EN,            ///< Overflow/Underflow Enable
    OCB_Q_OUFLOW_DIS            ///< Overflow/Underflow Disable
};

/// @enum P9_OCB_ITPTYPE
enum P9_OCB_ITPTYPE
{
    OCB_Q_ITPTYPE_NULL,         ///< Overflow/Underflow Disable
    OCB_Q_ITPTYPE_FULL,         ///< Interrupt on Full
    OCB_Q_ITPTYPE_NOTFULL,      ///< Interrupt on Not Full
    OCB_Q_ITPTYPE_EMPTY,        ///< Interrupt on Empty
    OCB_Q_ITPTYPE_NOTEMPTY      ///< Interrupt on Not Empty
};
} // END OF NAMESPACE p9ocb

// channel register arrrays
#if 0
const uint64_t OCBARn[4]       = {OCB0_ADDRESS_0x0006B010,
                                  OCB1_ADDRESS_0x0006B030,
                                  OCB2_ADDRESS_0x0006B050,
                                  OCB3_ADDRESS_0x0006B070
                                 };

const uint64_t OCBCSRn[4]      = {OCB0_STATUS_CONTROL_0x0006B011,
                                  OCB1_STATUS_CONTROL_0x0006B031,
                                  OCB2_STATUS_CONTROL_0x0006B051,
                                  OCB3_STATUS_CONTROL_0x0006B071
                                 };

const uint64_t OCBCSRn_AND[4]  = {OCB0_STATUS_CONTROL_AND_0x0006B012,
                                  OCB1_STATUS_CONTROL_AND_0x0006B032,
                                  OCB2_STATUS_CONTROL_AND_0x0006B052,
                                  OCB3_STATUS_CONTROL_AND_0x0006B072
                                 };

const uint64_t OCBCSRn_OR[4]   = {OCB0_STATUS_CONTROL_OR_0x0006B013,
                                  OCB1_STATUS_CONTROL_OR_0x0006B033,
                                  OCB2_STATUS_CONTROL_OR_0x0006B053,
                                  OCB3_STATUS_CONTROL_OR_0x0006B073
                                 };

const uint64_t OCBESRn[4]      = {OCB0_ERROR_STATUS_0x0006B014,
                                  OCB1_ERROR_STATUS_0x0006B034,
                                  OCB2_ERROR_STATUS_0x0006B054,
                                  OCB3_ERROR_STATUS_0x0006B074
                                 };

const uint64_t OCBSLBRn[3]     = {OCB0_PULL_BASE_0x0006A200,
                                  OCB1_PULL_BASE_0x0006A210,
                                  OCB2_PULL_BASE_0x0006A220,
                                  OCB3_PULL_BASE_0x0006A220
                                 };

const uint64_t OCBSHBRn[3]     = {OCB0_PULL_STATUS_CONTROL_0x0006A201,
                                  OCB1_PULL_STATUS_CONTROL_0x0006A211,
                                  OCB2_PULL_STATUS_CONTROL_0x0006A221,
                                  OCB3_PULL_STATUS_CONTROL_0x0006A221
                                 };

const uint64_t OCBSLCSn[3]     = {OCB0_PUSH_BASE_0x0006A203,
                                  OCB1_PUSH_BASE_0x0006A213,
                                  OCB2_PUSH_BASE_0x0006A223,
                                  OCB3_PUSH_BASE_0x0006A223
                                 };

const uint64_t OCBSHCSn[3]     = {OCB0_PUSH_STATUS_CONTROL_0x0006A204,
                                  OCB1_PUSH_STATUS_CONTROL_0x0006A214,
                                  OCB2_PUSH_STATUS_CONTROL_0x0006A224,
                                  OCB3_PUSH_STATUS_CONTROL_0x0006A224
                                 };

const uint64_t OCBSESn[3]      = {OCB0_STREAM_ERR_STATUS_0x0006A206,
                                  OCB1_STREAM_ERR_STATUS_0x0006A216,
                                  OCB2_STREAM_ERR_STATUS_0x0006A226,
                                  OCB3_STREAM_ERR_STATUS_0x0006A226
                                 };

// linear window write control
const uint64_t OCBLWCRn[3]     = {OCB0_LIN_WINDOW_CONTROL_0x0006A208,
                                  OCB1_LIN_WINDOW_CONTROL_0x0006A218,
                                  OCB2_LIN_WINDOW_CONTROL_0x0006A228,
                                  OCB3_LIN_WINDOW_CONTROL_0x0006A228
                                 };
// linear window write base
const uint64_t OCBLWSBRn[3]    = {OCB0_LIN_WINDOW_BASE_0x0006A20C,
                                  OCB1_LIN_WINDOW_BASE_0x0006A21C,
                                  OCB2_LIN_WINDOW_BASE_0x0006A22C,
                                  OCB3_LIN_WINDOW_BASE_0x0006A22C
                                 };
#endif

typedef fapi2::ReturnCode (*p9_pm_ocb_init_FP_t) (
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>&,
    const p9pm::PM_FLOW_MODE,
    const p9ocb::P9_OCB_CHAN_NUM,
    const p9ocb::P9_OCB_CHAN_TYPE,
    const uint32_t,
    const uint8_t,
    const p9ocb::P9_OCB_CHAN_OUFLOW,
    const p9ocb::P9_OCB_ITPTYPE);

extern "C"
{
//------------------------------------------------------------------------------
// Function prototype
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
///
/// @brief Configure OCB Channels based on mode and parameters passed
///
/// @param [in]   i_target          Chip Target
/// @param [in]   i_mode            PM_RESET, PM_INIT, or PM_SETUP
/// @param [in]   i_ocb_chan        select channel 0-3 to set up
/// @param [in]   i_ocb_type        0=indirect  1=linear stream  2=circular push
///                                 3=circular pull
/// @param [in]   i_ocb_bar         32-bit channel base address(29 bits + "000")
/// @param [in]   i_ocb_q_len       0-31 length of push or pull queue in
///                                 (queue_length + 1) * 8B
/// @param [in]   i_ocb_ouflow_en   0=disabled 1=enabled
/// @param [in]   i_ocb_itp_type    0=full  1=not full  2=empty  3=not empty
///
/// @return FAPI2_RC_SUCCESS if success, else error code.
///
    fapi2::ReturnCode p9_pm_ocb_init(
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
        const p9pm::PM_FLOW_MODE         i_mode,
        const p9ocb::P9_OCB_CHAN_NUM     i_ocb_chan,
        const p9ocb::P9_OCB_CHAN_TYPE    i_ocb_type,
        const uint32_t                   i_ocb_bar,
        const uint8_t                    i_ocb_q_len,
        const p9ocb::P9_OCB_CHAN_OUFLOW  i_ocb_ouflow_en,
        const p9ocb::P9_OCB_ITPTYPE      i_ocb_itp_type);
} // extern "C"

#endif // _P9_PM_OCB_INIT_H_

