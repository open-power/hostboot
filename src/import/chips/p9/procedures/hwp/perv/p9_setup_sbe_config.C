/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/perv/p9_setup_sbe_config.C $          */
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
/// @file  p9_setup_sbe_config.C
///
/// @brief proc setup sbe config
//------------------------------------------------------------------------------
// *HWP HW Owner        : Anusha Reddy Rangareddygari <anusrang@in.ibm.com>
// *HWP HW Backup Owner : Srinivas V Naga <srinivan@in.ibm.com>
// *HWP FW Owner        : Brian Silver <bsilver@us.ibm.com>
// *HWP Team            : Perv
// *HWP Level           : 2
// *HWP Consumed by     : SBE
//------------------------------------------------------------------------------


//## auto_generated
#include "p9_setup_sbe_config.H"

#include <p9_perv_scom_addresses.H>

enum P9_SETUP_SBE_CONFIG_Private_Constants
{
    ATTR_EQ_GARD_STARTBIT = 0,
    ATTR_EQ_GARD_LENGTH = 6,
    ATTR_EC_GARD_STARTBIT = 8,
    ATTR_EC_GARD_LENGTH = 24,
    ATTR_I2C_BUS_DIV_REF_STARTBIT = 0,
    ATTR_I2C_BUS_DIV_REF_LENGTH = 16,
    ATTR_BOOT_FLAGS_STARTBIT = 0,
    ATTR_BOOT_FLAGS_LENGTH = 32,
    ATTR_PROC_FABRIC_GROUP_ID_STARTBIT = 26,
    ATTR_PROC_FABRIC_GROUP_ID_LENGTH = 3,
    ATTR_PROC_FABRIC_CHIP_ID_STARTBIT = 29,
    ATTR_PROC_FABRIC_CHIP_ID_LENGTH = 3,
    ATTR_BOOT_FREQ_MULT_STARTBIT = 0,
    ATTR_BOOT_FREQ_MULT_LENGTH = 16,
    ATTR_NEST_PLL_BUCKET_STARTBIT = 24,
    ATTR_NEST_PLL_BUCKET_LENGTH = 8

};


fapi2::ReturnCode p9_setup_sbe_config(const
                                      fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target_chip)
{
    fapi2::buffer<uint32_t> l_read_scratch_reg = 0;
    fapi2::buffer<uint32_t> l_read_scratch8 = 0;
    fapi2::buffer<uint8_t> l_read_1 = 0;
    fapi2::buffer<uint8_t> l_read_2 = 0;
    fapi2::buffer<uint8_t> l_read_3 = 0;
    fapi2::buffer<uint16_t> l_read_4 = 0;
    fapi2::buffer<uint32_t> l_read_5 = 0;
    fapi2::buffer<uint32_t> l_read_6 = 0;
    const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;
    FAPI_INF("Entering ...");

    FAPI_DBG("Read Scratch8 for validity of Scratch register");
    //Getting SCRATCH_REGISTER_8 register value
    FAPI_TRY(fapi2::getCfamRegister(i_target_chip, PERV_SCRATCH_REGISTER_8_FSI,
                                    l_read_scratch8)); //l_read_scratch8 = CFAM.SCRATCH_REGISTER_8

    //set_scratch1_reg
    {

        FAPI_DBG("Read Scratch_reg1");
        //Getting SCRATCH_REGISTER_1 register value
        FAPI_TRY(fapi2::getCfamRegister(i_target_chip, PERV_SCRATCH_REGISTER_1_FSI,
                                        l_read_scratch_reg)); //l_read_scratch_reg = CFAM.SCRATCH_REGISTER_1

        FAPI_DBG("Reading ATTR_EQ_GARD, ATTR_EC_GARD");
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_EQ_GARD, i_target_chip, l_read_1));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_EC_GARD, i_target_chip, l_read_5));

        l_read_1.extractToRight< 0, ATTR_EQ_GARD_LENGTH >(l_read_2);
        l_read_5.extractToRight< 0, ATTR_EC_GARD_LENGTH >(l_read_6);

        l_read_scratch_reg.insertFromRight< ATTR_EQ_GARD_STARTBIT, ATTR_EQ_GARD_LENGTH >(l_read_2);
        l_read_scratch_reg.insertFromRight< ATTR_EC_GARD_STARTBIT, ATTR_EC_GARD_LENGTH >(l_read_6);

        FAPI_DBG("Setting up value of Scratch_reg1");
        //Setting SCRATCH_REGISTER_1 register value
        //CFAM.SCRATCH_REGISTER_1 = l_read_scratch_reg
        FAPI_TRY(fapi2::putCfamRegister(i_target_chip, PERV_SCRATCH_REGISTER_1_FSI,
                                        l_read_scratch_reg));

        l_read_scratch8.setBit<0>();
    }
    //set_scratch2_reg
    {
        FAPI_DBG("Reading Scratch_reg2");
        //Getting SCRATCH_REGISTER_2 register value
        FAPI_TRY(fapi2::getCfamRegister(i_target_chip, PERV_SCRATCH_REGISTER_2_FSI,
                                        l_read_scratch_reg)); //l_read_scratch_reg = CFAM.SCRATCH_REGISTER_2

        FAPI_DBG("Reading ATTR_I2C_BUS_DIV_REF");
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_I2C_BUS_DIV_REF, i_target_chip, l_read_4));

        l_read_scratch_reg.insertFromRight< ATTR_I2C_BUS_DIV_REF_STARTBIT, ATTR_I2C_BUS_DIV_REF_LENGTH >(l_read_4);

        FAPI_DBG("Setting up value of Scratch_reg2");
        //Setting SCRATCH_REGISTER_2 register value
        //CFAM.SCRATCH_REGISTER_2 = l_read_scratch_reg
        FAPI_TRY(fapi2::putCfamRegister(i_target_chip, PERV_SCRATCH_REGISTER_2_FSI,
                                        l_read_scratch_reg));

        l_read_scratch8.setBit<1>();
    }
    //set_scratch3_reg
    {
        FAPI_DBG("Reading Scratch_reg3");
        //Getting SCRATCH_REGISTER_3 register value
        FAPI_TRY(fapi2::getCfamRegister(i_target_chip, PERV_SCRATCH_REGISTER_3_FSI,
                                        l_read_scratch_reg)); //l_read_scratch_reg = CFAM.SCRATCH_REGISTER_3

        FAPI_DBG("Reading the BOOT_FLAGS");
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_BOOT_FLAGS, FAPI_SYSTEM, l_read_5));

        l_read_scratch_reg.insertFromRight< ATTR_BOOT_FLAGS_STARTBIT, ATTR_BOOT_FLAGS_LENGTH >(l_read_5);

        FAPI_DBG("Setting up value of Scratch_reg3");
        //Setting SCRATCH_REGISTER_3 register value
        //CFAM.SCRATCH_REGISTER_3 = l_read_scratch_reg
        FAPI_TRY(fapi2::putCfamRegister(i_target_chip, PERV_SCRATCH_REGISTER_3_FSI,
                                        l_read_scratch_reg));

        l_read_scratch8.setBit<2>();
    }
    //set_scratch4_reg
    {
        FAPI_DBG("Reading Scratch_reg4");
        //Getting SCRATCH_REGISTER_4 register value
        FAPI_TRY(fapi2::getCfamRegister(i_target_chip, PERV_SCRATCH_REGISTER_4_FSI,
                                        l_read_scratch_reg)); //l_read_scratch_reg = CFAM.SCRATCH_REGISTER_4

        FAPI_DBG("Reading ATTR_BOOT_FREQ_MULT, ATTR_NEST_PLL_BUCKET");
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_BOOT_FREQ_MULT, i_target_chip, l_read_4));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_NEST_PLL_BUCKET, FAPI_SYSTEM, l_read_1));

        l_read_scratch_reg.insertFromRight< ATTR_BOOT_FREQ_MULT_STARTBIT, ATTR_BOOT_FREQ_MULT_LENGTH >(l_read_4);
        l_read_scratch_reg.insertFromRight< ATTR_NEST_PLL_BUCKET_STARTBIT, ATTR_NEST_PLL_BUCKET_LENGTH >(l_read_1);

        FAPI_DBG("Setting up value of Scratch_reg4");
        //Setting SCRATCH_REGISTER_4 register value
        //CFAM.SCRATCH_REGISTER_4 = l_read_scratch_reg
        FAPI_TRY(fapi2::putCfamRegister(i_target_chip, PERV_SCRATCH_REGISTER_4_FSI,
                                        l_read_scratch_reg));

        l_read_scratch8.setBit<3>();
    }
    //set_scratch5_reg
    {
        FAPI_DBG("Reading Scratch_reg5");
        //Getting SCRATCH_REGISTER_5 register value
        FAPI_TRY(fapi2::getCfamRegister(i_target_chip, PERV_SCRATCH_REGISTER_5_FSI,
                                        l_read_scratch_reg)); //l_read_scratch_reg = CFAM.SCRATCH_REGISTER_5

        FAPI_DBG("Reading the control flags : SYSTEM_IPL_PHASE, RISK_LEVEL, SYS_FORCE_ALL_CORES");
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_SYSTEM_IPL_PHASE, FAPI_SYSTEM, l_read_1));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_RISK_LEVEL, FAPI_SYSTEM, l_read_2));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_SYS_FORCE_ALL_CORES, FAPI_SYSTEM,
                               l_read_3));

        l_read_scratch_reg.writeBit<0>(l_read_1.getBit<7>());
        l_read_scratch_reg.writeBit<1>(l_read_3.getBit<7>());
        l_read_scratch_reg.writeBit<2>(l_read_2.getBit<7>());

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_DISABLE_HBBL_VECTORS, FAPI_SYSTEM,
                               l_read_1));

        l_read_scratch_reg.writeBit<3>(l_read_1.getBit<7>());

        FAPI_DBG("Setting up value of Scratch_reg5");
        //Setting SCRATCH_REGISTER_5 register value
        //CFAM.SCRATCH_REGISTER_5 = l_read_scratch_reg
        FAPI_TRY(fapi2::putCfamRegister(i_target_chip, PERV_SCRATCH_REGISTER_5_FSI,
                                        l_read_scratch_reg));

        l_read_scratch8.setBit<4>();
    }
    //set_scratch6_reg
    {
        FAPI_DBG("Reading Scratch_reg6");
        //Getting SCRATCH_REGISTER_6 register value
        FAPI_TRY(fapi2::getCfamRegister(i_target_chip, PERV_SCRATCH_REGISTER_6_FSI,
                                        l_read_scratch_reg)); //l_read_scratch_reg = CFAM.SCRATCH_REGISTER_6

        FAPI_DBG("Reading attribute for Hostboot slave bit");
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_SBE_MASTER_CHIP, i_target_chip,
                               l_read_1));

        l_read_scratch_reg.writeBit<24>(l_read_1.getBit<7>());

        FAPI_DBG("Reading ATTR_PROC_FABRIC_GROUP and CHIP_ID");
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_GROUP_ID, i_target_chip,
                               l_read_1));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_CHIP_ID, i_target_chip,
                               l_read_2));

        l_read_scratch_reg.insertFromRight< ATTR_PROC_FABRIC_GROUP_ID_STARTBIT, ATTR_PROC_FABRIC_GROUP_ID_LENGTH >(l_read_1);
        l_read_scratch_reg.insertFromRight< ATTR_PROC_FABRIC_CHIP_ID_STARTBIT, ATTR_PROC_FABRIC_CHIP_ID_LENGTH >(l_read_2);

        FAPI_DBG("Setting up value of Scratch_reg6");
        //Setting SCRATCH_REGISTER_6 register value
        //CFAM.SCRATCH_REGISTER_6 = l_read_scratch_reg
        FAPI_TRY(fapi2::putCfamRegister(i_target_chip, PERV_SCRATCH_REGISTER_6_FSI,
                                        l_read_scratch_reg));

        l_read_scratch8.setBit<5>();
    }
    FAPI_DBG("Setting Scratch8 for validity of Scratch register");
    //Setting SCRATCH_REGISTER_8 register value
    //CFAM.SCRATCH_REGISTER_8 = l_read_scratch8
    FAPI_TRY(fapi2::putCfamRegister(i_target_chip, PERV_SCRATCH_REGISTER_8_FSI,
                                    l_read_scratch8));

    FAPI_INF("Exiting ...");

fapi_try_exit:
    return fapi2::current_err;

}
