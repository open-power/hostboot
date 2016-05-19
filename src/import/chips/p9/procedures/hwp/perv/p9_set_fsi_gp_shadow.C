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
//## auto_generated
#include "p9_const_common.H"

#include <p9_perv_scom_addresses.H>


fapi2::ReturnCode p9_set_fsi_gp_shadow(const
                                       fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target_chip)
{
    fapi2::buffer<uint32_t> l_read_attr = 0;
    FAPI_INF("Entering ...");

    FAPI_DBG("Reading ATTR_ROOT_CTRL0_SHADOW");
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_ROOT_CTRL0_SHADOW, i_target_chip,
                           l_read_attr));

    FAPI_DBG("Setting ROOT_CTRL0_COPY Reg");
    //Setting ROOT_CTRL0_COPY register value
    //CFAM.ROOT_CTRL0_COPY = l_read_attr
    FAPI_TRY(fapi2::putCfamRegister(i_target_chip, PERV_ROOT_CTRL0_COPY_FSI,
                                    l_read_attr));

    FAPI_DBG("Reading ATTR_ROOT_CTRL1_SHADOW");
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_ROOT_CTRL1_SHADOW, i_target_chip,
                           l_read_attr));

    FAPI_DBG("Setting ROOT_CTRL1_COPY Reg");
    //Setting ROOT_CTRL1_COPY register value
    //CFAM.ROOT_CTRL1_COPY = l_read_attr
    FAPI_TRY(fapi2::putCfamRegister(i_target_chip, PERV_ROOT_CTRL1_COPY_FSI,
                                    l_read_attr));

    FAPI_DBG("Reading ATTR_ROOT_CTRL2_SHADOW");
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_ROOT_CTRL2_SHADOW, i_target_chip,
                           l_read_attr));

    FAPI_DBG("Setting ROOT_CTRL2_COPY Reg");
    //Setting ROOT_CTRL2_COPY register value
    //CFAM.ROOT_CTRL2_COPY = l_read_attr
    FAPI_TRY(fapi2::putCfamRegister(i_target_chip, PERV_ROOT_CTRL2_COPY_FSI,
                                    l_read_attr));

    FAPI_DBG("Reading ATTR_ROOT_CTRL3_SHADOW");
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_ROOT_CTRL3_SHADOW, i_target_chip,
                           l_read_attr));

    FAPI_DBG("Setting ROOT_CTRL3_COPY Reg");
    //Setting ROOT_CTRL3_COPY register value
    //CFAM.ROOT_CTRL3_COPY = l_read_attr
    FAPI_TRY(fapi2::putCfamRegister(i_target_chip, PERV_ROOT_CTRL3_COPY_FSI,
                                    l_read_attr));

    FAPI_DBG("Reading ATTR_ROOT_CTRL4_SHADOW");
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_ROOT_CTRL4_SHADOW, i_target_chip,
                           l_read_attr));

    FAPI_DBG("Setting ROOT_CTRL4_COPY Reg");
    //Setting ROOT_CTRL4_COPY register value
    //CFAM.ROOT_CTRL4_COPY = l_read_attr
    FAPI_TRY(fapi2::putCfamRegister(i_target_chip, PERV_ROOT_CTRL4_COPY_FSI,
                                    l_read_attr));

    FAPI_DBG("Reading ATTR_ROOT_CTRL5_SHADOW");
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_ROOT_CTRL5_SHADOW, i_target_chip,
                           l_read_attr));

    FAPI_DBG("Setting ROOT_CTRL5_COPY Reg");
    //Setting ROOT_CTRL5_COPY register value
    //CFAM.ROOT_CTRL5_COPY = l_read_attr
    FAPI_TRY(fapi2::putCfamRegister(i_target_chip, PERV_ROOT_CTRL5_COPY_FSI,
                                    l_read_attr));

    FAPI_DBG("Reading ATTR_ROOT_CTRL6_SHADOW");
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_ROOT_CTRL6_SHADOW, i_target_chip,
                           l_read_attr));

    FAPI_DBG("Setting ROOT_CTRL6_COPY Reg");
    //Setting ROOT_CTRL6_COPY register value
    //CFAM.ROOT_CTRL6_COPY = l_read_attr
    FAPI_TRY(fapi2::putCfamRegister(i_target_chip, PERV_ROOT_CTRL6_COPY_FSI,
                                    l_read_attr));

    FAPI_DBG("Reading ATTR_ROOT_CTRL7_SHADOW");
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_ROOT_CTRL7_SHADOW, i_target_chip,
                           l_read_attr));

    FAPI_DBG("Setting ROOT_CTRL7_COPY Reg");
    //Setting ROOT_CTRL7_COPY register value
    //CFAM.ROOT_CTRL7_COPY = l_read_attr
    FAPI_TRY(fapi2::putCfamRegister(i_target_chip, PERV_ROOT_CTRL7_COPY_FSI,
                                    l_read_attr));

    FAPI_DBG("Reading ATTR_ROOT_CTRL8_SHADOW");
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_ROOT_CTRL8_SHADOW, i_target_chip,
                           l_read_attr));

    FAPI_DBG("Setting ROOT_CTRL8_COPY Reg");
    //Setting ROOT_CTRL8_COPY register value
    //CFAM.ROOT_CTRL8_COPY = l_read_attr
    FAPI_TRY(fapi2::putCfamRegister(i_target_chip, PERV_ROOT_CTRL8_COPY_FSI,
                                    l_read_attr));

    FAPI_DBG("Reading ATTR_PERV_CTRL0_SHADOW");
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PERV_CTRL0_SHADOW, i_target_chip,
                           l_read_attr));

    FAPI_DBG("Setting PERV_CTRL0_COPY Reg");
    //Setting PERV_CTRL0_COPY register value
    //CFAM.PERV_CTRL0_COPY = l_read_attr
    FAPI_TRY(fapi2::putCfamRegister(i_target_chip, PERV_PERV_CTRL0_COPY_FSI,
                                    l_read_attr));

    FAPI_DBG("Reading ATTR_PERV_CTRL1_SHADOW");
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PERV_CTRL1_SHADOW, i_target_chip,
                           l_read_attr));

    FAPI_DBG("Setting PERV_CTRL1_COPY Reg");
    //Setting PERV_CTRL1_COPY register value
    //CFAM.PERV_CTRL1_COPY = l_read_attr
    FAPI_TRY(fapi2::putCfamRegister(i_target_chip, PERV_PERV_CTRL1_COPY_FSI,
                                    l_read_attr));

    FAPI_INF("Exiting ...");

fapi_try_exit:
    return fapi2::current_err;

}
