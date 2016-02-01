/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/perv/p9_set_fsi_gp_shadow.C $         */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* EKB Project                                                            */
/*                                                                        */
/* COPYRIGHT 2015,2016                                                    */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
//------------------------------------------------------------------------------
/// @file  p9_set_fsi_gp_shadow.C
///
/// @brief --IPL step 0.8 proc_prep_ipl
//------------------------------------------------------------------------------
// *HWP HW Owner        : Anusha Reddy Rangareddygari <anusrang@in.ibm.com>
// *HWP HW Backup Owner : Srinivas V Naga <srinivan@in.ibm.com>
// *HWP FW Owner        : Brian Silver <bsilver@us.ibm.com>
// *HWP Team            : Perv
// *HWP Level           : 2
// *HWP Consumed by     : SBE
//------------------------------------------------------------------------------


//## auto_generated
#include "p9_set_fsi_gp_shadow.H"

#include "p9_perv_scom_addresses.H"


fapi2::ReturnCode p9_set_fsi_gp_shadow(const
                                       fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target_chip)
{
    FAPI_DBG("Entering ...");

    FAPI_INF("Setting flush values for root_ctrl_copy and perv_ctrl_copy registers");
    //Setting ROOT_CTRL0_COPY register value
    //CFAM.ROOT_CTRL0_COPY = p9SetFsiGpShadow::ROOT_CTRL0_FLUSHVALUE
    FAPI_TRY(fapi2::putCfamRegister(i_target_chip, PERV_ROOT_CTRL0_COPY_FSI,
                                    p9SetFsiGpShadow::ROOT_CTRL0_FLUSHVALUE));

    //Setting ROOT_CTRL1_COPY register value
    //CFAM.ROOT_CTRL1_COPY = p9SetFsiGpShadow::ROOT_CTRL1_FLUSHVALUE
    FAPI_TRY(fapi2::putCfamRegister(i_target_chip, PERV_ROOT_CTRL1_COPY_FSI,
                                    p9SetFsiGpShadow::ROOT_CTRL1_FLUSHVALUE));

    //Setting ROOT_CTRL2_COPY register value
    //CFAM.ROOT_CTRL2_COPY = p9SetFsiGpShadow::ROOT_CTRL2_FLUSHVALUE
    FAPI_TRY(fapi2::putCfamRegister(i_target_chip, PERV_ROOT_CTRL2_COPY_FSI,
                                    p9SetFsiGpShadow::ROOT_CTRL2_FLUSHVALUE));

    //Setting ROOT_CTRL3_COPY register value
    //CFAM.ROOT_CTRL3_COPY = p9SetFsiGpShadow::ROOT_CTRL3_FLUSHVALUE
    FAPI_TRY(fapi2::putCfamRegister(i_target_chip, PERV_ROOT_CTRL3_COPY_FSI,
                                    p9SetFsiGpShadow::ROOT_CTRL3_FLUSHVALUE));

    //Setting ROOT_CTRL4_COPY register value
    //CFAM.ROOT_CTRL4_COPY = p9SetFsiGpShadow::ROOT_CTRL4_FLUSHVALUE
    FAPI_TRY(fapi2::putCfamRegister(i_target_chip, PERV_ROOT_CTRL4_COPY_FSI,
                                    p9SetFsiGpShadow::ROOT_CTRL4_FLUSHVALUE));

    //Setting ROOT_CTRL5_COPY register value
    //CFAM.ROOT_CTRL5_COPY = p9SetFsiGpShadow::ROOT_CTRL5_FLUSHVALUE
    FAPI_TRY(fapi2::putCfamRegister(i_target_chip, PERV_ROOT_CTRL5_COPY_FSI,
                                    p9SetFsiGpShadow::ROOT_CTRL5_FLUSHVALUE));

    //Setting ROOT_CTRL6_COPY register value
    //CFAM.ROOT_CTRL6_COPY = p9SetFsiGpShadow::ROOT_CTRL6_FLUSHVALUE
    FAPI_TRY(fapi2::putCfamRegister(i_target_chip, PERV_ROOT_CTRL6_COPY_FSI,
                                    p9SetFsiGpShadow::ROOT_CTRL6_FLUSHVALUE));

    //Setting ROOT_CTRL7_COPY register value
    //CFAM.ROOT_CTRL7_COPY = p9SetFsiGpShadow::ROOT_CTRL7_FLUSHVALUE
    FAPI_TRY(fapi2::putCfamRegister(i_target_chip, PERV_ROOT_CTRL7_COPY_FSI,
                                    p9SetFsiGpShadow::ROOT_CTRL7_FLUSHVALUE));

    //Setting ROOT_CTRL8_COPY register value
    //CFAM.ROOT_CTRL8_COPY = p9SetFsiGpShadow::ROOT_CTRL8_FLUSHVALUE
    FAPI_TRY(fapi2::putCfamRegister(i_target_chip, PERV_ROOT_CTRL8_COPY_FSI,
                                    p9SetFsiGpShadow::ROOT_CTRL8_FLUSHVALUE));

    //Setting PERV_CTRL0_COPY register value
    //CFAM.PERV_CTRL0_COPY = p9SetFsiGpShadow::PERV_CTRL0_FLUSHVALUE
    FAPI_TRY(fapi2::putCfamRegister(i_target_chip, PERV_PERV_CTRL0_COPY_FSI,
                                    p9SetFsiGpShadow::PERV_CTRL0_FLUSHVALUE));

    //Setting PERV_CTRL1_COPY register value
    //CFAM.PERV_CTRL1_COPY = p9SetFsiGpShadow::PERV_CTRL1_FLUSHVALUE
    FAPI_TRY(fapi2::putCfamRegister(i_target_chip, PERV_PERV_CTRL1_COPY_FSI,
                                    p9SetFsiGpShadow::PERV_CTRL1_FLUSHVALUE));

    FAPI_DBG("Exiting ...");

fapi_try_exit:
    return fapi2::current_err;

}
