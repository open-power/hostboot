/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/initfiles/p9_fbc_ioo_tl_scom.C $      */
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
#include "p9_fbc_ioo_tl_scom.H"
#include <stdint.h>
#include <stddef.h>
#include <fapi2.H>
#include <attribute_ids.H>
#include <target_types.H>
#include <fapi2_attribute_service.H>
using namespace fapi2;

#define ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_ATTRIBUTE_VALUE_0    0
#define ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_ATTRIBUTE_VALUE_0    0
#define LITERAL_PB_IOO_SCOM_LINK00_HI_TRACE_CFG_0b0101    0b0101
#define LITERAL_PB_IOO_SCOM_LINK00_LO_TRACE_CFG_0b0101    0b0101
#define LITERAL_PB_IOO_SCOM_LINK02_HI_TRACE_CFG_0b0101    0b0101
#define LITERAL_PB_IOO_SCOM_LINK02_LO_TRACE_CFG_0b0101    0b0101
#define LITERAL_PB_IOO_SCOM_LINK04_HI_TRACE_CFG_0b0101    0b0101
#define LITERAL_PB_IOO_SCOM_LINK04_LO_TRACE_CFG_0b0101    0b0101
#define LITERAL_PB_IOO_SCOM_LINK06_HI_TRACE_CFG_0b0101    0b0101
#define LITERAL_PB_IOO_SCOM_LINK06_LO_TRACE_CFG_0b0101    0b0101
#define LITERAL_PB_IOO_SCOM_PB_CFG_IOO01_IS_LOGICAL_PAIR_ON    0x1
#define LITERAL_PB_IOO_SCOM_PB_CFG_IOO23_IS_LOGICAL_PAIR_ON    0x1
#define LITERAL_PB_IOO_SCOM_PB_CFG_IOO45_IS_LOGICAL_PAIR_ON    0x1
#define LITERAL_PB_IOO_SCOM_PB_CFG_IOO67_IS_LOGICAL_PAIR_ON    0x1
#define LITERAL_PB_IOO_SCOM_PB_IOO_FIR_MASK_REG_0xFFFFFFFFFFFFFFFF    0xFFFFFFFFFFFFFFFF

fapi2::ReturnCode p9_fbc_ioo_tl_scom(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& TGT0)
{
    fapi2::ReturnCode l_rc = 0;

    do
    {
        ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_Type iv_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG;
        ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_Type iv_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG;
        l_rc = FAPI_ATTR_GET(ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG, TGT0, iv_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG);

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: FAPI_ATTR_GET (iv_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG)");
            break;
        }

        l_rc = FAPI_ATTR_GET(ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG, TGT0, iv_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG);

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: FAPI_ATTR_GET (iv_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG)");
            break;
        }

        auto iv_def_OBUS0_FBC_ENABLED = ((iv_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[3] !=
                                          ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_ATTRIBUTE_VALUE_0)
                                         || (iv_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[0] != ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_ATTRIBUTE_VALUE_0));
        fapi2::buffer<uint64_t> PB_IOO_SCOM_PB_CFG_IOO01_IS_LOGICAL_PAIR_scom0;
        l_rc = fapi2::getScom( TGT0, 0x5013823ull, PB_IOO_SCOM_PB_CFG_IOO01_IS_LOGICAL_PAIR_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x5013823)");
            break;
        }

        if (iv_def_OBUS0_FBC_ENABLED)
        {
            PB_IOO_SCOM_PB_CFG_IOO01_IS_LOGICAL_PAIR_scom0.insert<uint64_t> (LITERAL_PB_IOO_SCOM_PB_CFG_IOO01_IS_LOGICAL_PAIR_ON, 0,
                    1, 63 );
        }

        fapi2::buffer<uint64_t> PB_IOO_SCOM_LINK00_HI_TRACE_CFG_scom0;
        l_rc = fapi2::getScom( TGT0, 0x5013824ull, PB_IOO_SCOM_LINK00_HI_TRACE_CFG_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x5013824)");
            break;
        }

        if (iv_def_OBUS0_FBC_ENABLED)
        {
            PB_IOO_SCOM_LINK00_HI_TRACE_CFG_scom0.insert<uint64_t> (LITERAL_PB_IOO_SCOM_LINK00_HI_TRACE_CFG_0b0101, 0, 4, 60 );
            PB_IOO_SCOM_LINK00_HI_TRACE_CFG_scom0.insert<uint64_t> (LITERAL_PB_IOO_SCOM_LINK00_HI_TRACE_CFG_0b0101, 8, 4, 60 );
        }

        if (iv_def_OBUS0_FBC_ENABLED)
        {
            PB_IOO_SCOM_LINK00_HI_TRACE_CFG_scom0.insert<uint64_t> (LITERAL_PB_IOO_SCOM_LINK00_LO_TRACE_CFG_0b0101, 4, 4, 60 );
            PB_IOO_SCOM_LINK00_HI_TRACE_CFG_scom0.insert<uint64_t> (LITERAL_PB_IOO_SCOM_LINK00_LO_TRACE_CFG_0b0101, 12, 4, 60 );
        }

        auto iv_def_OBUS1_FBC_ENABLED = ((iv_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[4] !=
                                          ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_ATTRIBUTE_VALUE_0)
                                         || (iv_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[1] != ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_ATTRIBUTE_VALUE_0));

        if (iv_def_OBUS1_FBC_ENABLED)
        {
            PB_IOO_SCOM_PB_CFG_IOO01_IS_LOGICAL_PAIR_scom0.insert<uint64_t> (LITERAL_PB_IOO_SCOM_PB_CFG_IOO23_IS_LOGICAL_PAIR_ON, 1,
                    1, 63 );
        }

        if ((( ! iv_def_OBUS0_FBC_ENABLED) && iv_def_OBUS1_FBC_ENABLED))
        {
            PB_IOO_SCOM_LINK00_HI_TRACE_CFG_scom0.insert<uint64_t> (LITERAL_PB_IOO_SCOM_LINK02_HI_TRACE_CFG_0b0101, 16, 4, 60 );
            PB_IOO_SCOM_LINK00_HI_TRACE_CFG_scom0.insert<uint64_t> (LITERAL_PB_IOO_SCOM_LINK02_HI_TRACE_CFG_0b0101, 24, 4, 60 );
        }

        if ((( ! iv_def_OBUS0_FBC_ENABLED) && iv_def_OBUS1_FBC_ENABLED))
        {
            PB_IOO_SCOM_LINK00_HI_TRACE_CFG_scom0.insert<uint64_t> (LITERAL_PB_IOO_SCOM_LINK02_LO_TRACE_CFG_0b0101, 20, 4, 60 );
            PB_IOO_SCOM_LINK00_HI_TRACE_CFG_scom0.insert<uint64_t> (LITERAL_PB_IOO_SCOM_LINK02_LO_TRACE_CFG_0b0101, 28, 4, 60 );
        }

        auto iv_def_OBUS2_FBC_ENABLED = ((iv_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[5] !=
                                          ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_ATTRIBUTE_VALUE_0)
                                         || (iv_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[2] != ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_ATTRIBUTE_VALUE_0));

        if (iv_def_OBUS2_FBC_ENABLED)
        {
            PB_IOO_SCOM_PB_CFG_IOO01_IS_LOGICAL_PAIR_scom0.insert<uint64_t> (LITERAL_PB_IOO_SCOM_PB_CFG_IOO45_IS_LOGICAL_PAIR_ON, 2,
                    1, 63 );
        }

        if (((( ! iv_def_OBUS0_FBC_ENABLED) && ( ! iv_def_OBUS1_FBC_ENABLED)) && iv_def_OBUS2_FBC_ENABLED))
        {
            PB_IOO_SCOM_LINK00_HI_TRACE_CFG_scom0.insert<uint64_t> (LITERAL_PB_IOO_SCOM_LINK04_HI_TRACE_CFG_0b0101, 32, 4, 60 );
            PB_IOO_SCOM_LINK00_HI_TRACE_CFG_scom0.insert<uint64_t> (LITERAL_PB_IOO_SCOM_LINK04_HI_TRACE_CFG_0b0101, 40, 4, 60 );
        }

        if (((( ! iv_def_OBUS0_FBC_ENABLED) && ( ! iv_def_OBUS1_FBC_ENABLED)) && iv_def_OBUS2_FBC_ENABLED))
        {
            PB_IOO_SCOM_LINK00_HI_TRACE_CFG_scom0.insert<uint64_t> (LITERAL_PB_IOO_SCOM_LINK04_LO_TRACE_CFG_0b0101, 36, 4, 60 );
            PB_IOO_SCOM_LINK00_HI_TRACE_CFG_scom0.insert<uint64_t> (LITERAL_PB_IOO_SCOM_LINK04_LO_TRACE_CFG_0b0101, 44, 4, 60 );
        }

        auto iv_def_OBUS3_FBC_ENABLED = ((iv_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[6] !=
                                          ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_ATTRIBUTE_VALUE_0)
                                         || (iv_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[3] != ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_ATTRIBUTE_VALUE_0));

        if (iv_def_OBUS3_FBC_ENABLED)
        {
            PB_IOO_SCOM_PB_CFG_IOO01_IS_LOGICAL_PAIR_scom0.insert<uint64_t> (LITERAL_PB_IOO_SCOM_PB_CFG_IOO67_IS_LOGICAL_PAIR_ON, 3,
                    1, 63 );
        }

        if ((((( ! iv_def_OBUS0_FBC_ENABLED) && ( ! iv_def_OBUS1_FBC_ENABLED)) && ( ! iv_def_OBUS2_FBC_ENABLED))
             && iv_def_OBUS3_FBC_ENABLED))
        {
            PB_IOO_SCOM_LINK00_HI_TRACE_CFG_scom0.insert<uint64_t> (LITERAL_PB_IOO_SCOM_LINK06_HI_TRACE_CFG_0b0101, 48, 4, 60 );
            PB_IOO_SCOM_LINK00_HI_TRACE_CFG_scom0.insert<uint64_t> (LITERAL_PB_IOO_SCOM_LINK06_HI_TRACE_CFG_0b0101, 56, 4, 60 );
        }

        if ((((( ! iv_def_OBUS0_FBC_ENABLED) && ( ! iv_def_OBUS1_FBC_ENABLED)) && ( ! iv_def_OBUS2_FBC_ENABLED))
             && iv_def_OBUS3_FBC_ENABLED))
        {
            PB_IOO_SCOM_LINK00_HI_TRACE_CFG_scom0.insert<uint64_t> (LITERAL_PB_IOO_SCOM_LINK06_LO_TRACE_CFG_0b0101, 52, 4, 60 );
            PB_IOO_SCOM_LINK00_HI_TRACE_CFG_scom0.insert<uint64_t> (LITERAL_PB_IOO_SCOM_LINK06_LO_TRACE_CFG_0b0101, 60, 4, 60 );
        }

        fapi2::buffer<uint64_t> PB_IOO_SCOM_PB_IOO_FIR_MASK_REG_scom0;
        l_rc = fapi2::getScom( TGT0, 0x5013803ull, PB_IOO_SCOM_PB_IOO_FIR_MASK_REG_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x5013803)");
            break;
        }

        if ((((iv_def_OBUS0_FBC_ENABLED || iv_def_OBUS1_FBC_ENABLED) || iv_def_OBUS2_FBC_ENABLED) || iv_def_OBUS3_FBC_ENABLED))
        {
            PB_IOO_SCOM_PB_IOO_FIR_MASK_REG_scom0.insert<uint64_t> (LITERAL_PB_IOO_SCOM_PB_IOO_FIR_MASK_REG_0xFFFFFFFFFFFFFFFF, 0,
                    64, 0 );
        }


        l_rc = fapi2::putScom( TGT0, 0x5013803ull, PB_IOO_SCOM_PB_IOO_FIR_MASK_REG_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x5013803)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x5013823ull, PB_IOO_SCOM_PB_CFG_IOO01_IS_LOGICAL_PAIR_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x5013823)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x5013824ull, PB_IOO_SCOM_LINK00_HI_TRACE_CFG_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x5013824)");
            break;
        }

    }
    while(0);

    return l_rc;
}

