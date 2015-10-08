/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/perv/p9_setup_sbe_config.C $          */
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
//------------------------------------------------------------------------------
/// @file  p9_setup_sbe_config.C
///
/// @brief proc setup sbe config
//------------------------------------------------------------------------------
// *HWP HW Owner        : Anusha Reddy Rangareddygari <anusrang@in.ibm.com>
// *HWP HW Backup Owner : Srinivas V Naga <srinivan@in.ibm.com>
// *HWP FW Owner        : sunil kumar <skumar8j@in.ibm.com>
// *HWP Team            : Perv
// *HWP Level           : 2
// *HWP Consumed by     : SE
//------------------------------------------------------------------------------

#include "p9_setup_sbe_config.H"

#include "p9_perv_scom_addresses.H"

enum P9_SETUP_SBE_CONFIG_Private_Constants
{
    ATTR_EQ_GARD_STARTBIT = 0,
    ATTR_EQ_GARD_LENGTH = 8,
    ATTR_EC_GARD_STARTBIT = 8,
    ATTR_EC_GARD_LENGTH = 24,
    ATTR_I2C_BUS_DIV_REF_STARTBIT = 0,
    ATTR_I2C_BUS_DIV_REF_LENGTH = 16,
    ATTR_BOOT_FLAGS_STARTBIT = 0,
    ATTR_BOOT_FLAGS_LENGTH = 26,
    ATTR_NODE_POS_STARTBIT = 26,
    ATTR_NODE_POS_LENGTH = 3,
    ATTR_CHIP_POS_STARTBIT = 29,
    ATTR_CHIP_POS_LENGTH = 3,
    ATTR_BOOT_FREQ_STARTBIT = 0,
    ATTR_BOOT_FREQ_LENGTH = 16,
    ATTR_NEST_PLL_BUCKET_STARTBIT = 24,
    ATTR_NEST_PLL_BUCKET_LENGTH = 8,
    ATTR_VCS_BOOT_VOLTAGE_STARTBIT = 0,
    ATTR_VCS_BOOT_VOLTAGE_LENGTH = 16,
    ATTR_VDD_BOOT_VOLTAGE_STARTBIT = 16,
    ATTR_VDD_BOOT_VOLTAGE_LENGTH = 16

};



fapi2::ReturnCode p9_setup_sbe_config(const
                                      fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target_chip)
{
    fapi2::buffer<uint32_t> l_read_scratch_reg = 0;
    fapi2::buffer<uint32_t> l_read_scratch8 = 0;
    uint8_t l_read_1 = 0;
    uint8_t l_read_2 = 0;
    uint32_t l_read_3 = 0;
    uint32_t l_read_4 = 0;
    uint32_t l_read_5 = 0;

    FAPI_DBG("Entering ...");

    //Getting SCRATCH_REGISTER_8 register value
    FAPI_TRY(fapi2::getCfamRegister(i_target_chip, PERV_SCRATCH_REGISTER_8_FSI,
                                    l_read_scratch8));
    //Getting SCRATCH_REGISTER_1 register value
    FAPI_TRY(fapi2::getCfamRegister(i_target_chip, PERV_SCRATCH_REGISTER_1_FSI,
                                    l_read_scratch_reg));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_EQ_GARD, i_target_chip, l_read_1));

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_EC_GARD, i_target_chip, l_read_5));

    l_read_scratch_reg.insertFromRight< ATTR_EQ_GARD_STARTBIT, ATTR_EQ_GARD_LENGTH >(l_read_1);
    l_read_scratch_reg.insertFromRight< ATTR_EC_GARD_STARTBIT, ATTR_EC_GARD_LENGTH >(l_read_5);

    //Putting the Attribute values into SCRATCH_REGISTER_1 register
    FAPI_TRY(fapi2::putCfamRegister(i_target_chip, PERV_SCRATCH_REGISTER_1_FSI,
                                    l_read_scratch_reg));


    //setting bit 0 of SCRATCH_REGISTER_8
    l_read_scratch8.setBit<0>();


    //Getting SCRATCH_REGISTER_2 register value
    FAPI_TRY(fapi2::getCfamRegister(i_target_chip, PERV_SCRATCH_REGISTER_2_FSI,
                                    l_read_scratch_reg));

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_I2C_BUS_DIV_REF, i_target_chip, l_read_3));

    l_read_scratch_reg.insertFromRight< ATTR_I2C_BUS_DIV_REF_STARTBIT, ATTR_I2C_BUS_DIV_REF_LENGTH >(l_read_3);

    //Putting the Attribute value into SCRATCH_REGISTER_2 register
    FAPI_TRY(fapi2::putCfamRegister(i_target_chip, PERV_SCRATCH_REGISTER_2_FSI,
                                    l_read_scratch_reg));


    //setting bit 1 of SCRATCH_REGISTER_8
    l_read_scratch8.setBit<1>();


    //Getting SCRATCH_REGISTER_3 register value
    FAPI_TRY(fapi2::getCfamRegister(i_target_chip, PERV_SCRATCH_REGISTER_3_FSI,
                                    l_read_scratch_reg));

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_BOOT_FLAGS, i_target_chip, l_read_5));

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_NODE_POS, i_target_chip, l_read_1));

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_POS, i_target_chip, l_read_2));

    l_read_scratch_reg.insertFromRight< ATTR_BOOT_FLAGS_STARTBIT, ATTR_BOOT_FLAGS_LENGTH >(l_read_5);
    l_read_scratch_reg.insertFromRight< ATTR_NODE_POS_STARTBIT, ATTR_NODE_POS_LENGTH >(l_read_1);
    l_read_scratch_reg.insertFromRight< ATTR_CHIP_POS_STARTBIT, ATTR_CHIP_POS_LENGTH >(l_read_2);

    //Putting the Attribute values into SCRATCH_REGISTER_3 register
    FAPI_TRY(fapi2::putCfamRegister(i_target_chip, PERV_SCRATCH_REGISTER_3_FSI,
                                    l_read_scratch_reg));


    //setting bit 2 of SCRATCH_REGISTER_8
    l_read_scratch8.setBit<2>();


    //Getting SCRATCH_REGISTER_4 register value
    FAPI_TRY(fapi2::getCfamRegister(i_target_chip, PERV_SCRATCH_REGISTER_4_FSI,
                                    l_read_scratch_reg));

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_BOOT_FREQ, i_target_chip, l_read_3));

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_NEST_PLL_BUCKET, i_target_chip, l_read_1));

    l_read_scratch_reg.insertFromRight< ATTR_BOOT_FREQ_STARTBIT, ATTR_BOOT_FREQ_LENGTH >(l_read_3);
    l_read_scratch_reg.insertFromRight< ATTR_NEST_PLL_BUCKET_STARTBIT, ATTR_NEST_PLL_BUCKET_LENGTH >(l_read_1);

    //Putting the Attribute values into SCRATCH_REGISTER_4 register
    FAPI_TRY(fapi2::putCfamRegister(i_target_chip, PERV_SCRATCH_REGISTER_4_FSI,
                                    l_read_scratch_reg));


    //setting bit 3 of SCRATCH_REGISTER_8
    l_read_scratch8.setBit<3>();

    //Getting SCRATCH_REGISTER_5 register value
    FAPI_TRY(fapi2::getCfamRegister(i_target_chip, PERV_SCRATCH_REGISTER_5_FSI,
                                    l_read_scratch_reg));

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_VCS_BOOT_VOLTAGE, i_target_chip, l_read_3));

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_VDD_BOOT_VOLTAGE, i_target_chip, l_read_4));

    l_read_scratch_reg.insertFromRight< ATTR_VCS_BOOT_VOLTAGE_STARTBIT, ATTR_VCS_BOOT_VOLTAGE_LENGTH >(l_read_3);
    l_read_scratch_reg.insertFromRight< ATTR_VDD_BOOT_VOLTAGE_STARTBIT, ATTR_VDD_BOOT_VOLTAGE_LENGTH >(l_read_4);


    //Putting the Attribute values into SCRATCH_REGISTER_5 register
    FAPI_TRY(fapi2::putCfamRegister(i_target_chip, PERV_SCRATCH_REGISTER_5_FSI,
                                    l_read_scratch_reg));



    //setting bit 4 of SCRATCH_REGISTER_8
    l_read_scratch8.setBit<4>();


    FAPI_TRY(fapi2::putCfamRegister(i_target_chip, PERV_SCRATCH_REGISTER_8_FSI,
                                    l_read_scratch8));


    FAPI_DBG("Exiting ...");

fapi_try_exit:
    return fapi2::current_err;

}

