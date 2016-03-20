/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/sbe/p9_get_sbe_msg_register.C $       */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* EKB Project                                                            */
/*                                                                        */
/* COPYRIGHT 2016                                                         */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
/// @file  p9_get_sbe_msg_register.C
///
/// @brief Returns the SBE message register
//------------------------------------------------------------------------------
// *HWP HW Owner        : Santosh Puranik <santosh.puranik@in.ibm.com>
// *HWP FW Owner        : Dhruvaraj Subhash Chandran <dhruvaraj@in.ibm.com>
// *HWP Team            : SBE
// *HWP Level           : 2
// *HWP Consumed by     : SE, Hostboot, Cronus
//------------------------------------------------------------------------------


#include "p9_get_sbe_msg_register.H"
#include "p9_perv_scom_addresses.H"

fapi2::ReturnCode p9_get_sbe_msg_register(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_chip,
        sbeMsgReg_t& o_sbeReg)
{
    fapi2::buffer<uint32_t> l_reg;

    FAPI_DBG("Entering ...");

    FAPI_TRY(fapi2::getCfamRegister(i_chip, PERV_SB_MSG_FSI, l_reg));

    o_sbeReg.reg = l_reg;

    FAPI_DBG("Exiting ...");

fapi_try_exit:
    return fapi2::current_err;
}
