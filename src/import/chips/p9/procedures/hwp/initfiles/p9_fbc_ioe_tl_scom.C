/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/initfiles/p9_fbc_ioe_tl_scom.C $      */
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
#include "p9_fbc_ioe_tl_scom.H"
#include <stdint.h>
#include <stddef.h>
#include <fapi2.H>
#include <attribute_ids.H>
#include <target_types.H>
#include <fapi2_attribute_service.H>
using namespace fapi2;

#define ATTR_FREQ_PB_ATTRIBUTE_VALUE_10    10
#define ATTR_FREQ_PB_ATTRIBUTE_VALUE_11    11
#define ATTR_FREQ_PB_ATTRIBUTE_VALUE_12    12
#define ATTR_FREQ_X_ATTRIBUTE_VALUE_10    10
#define ATTR_FREQ_X_ATTRIBUTE_VALUE_11    11
#define ATTR_FREQ_X_ATTRIBUTE_VALUE_12    12
#define ATTR_FREQ_X_ATTRIBUTE_VALUE_13    13
#define ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_ATTRIBUTE_VALUE_0    0
#define LITERAL_PB_IOE_SCOM_FP01_CMD_EXP_TIME_0x1    0x1
#define LITERAL_PB_IOE_SCOM_FP0_LL_CREDIT_HI_LIMIT_0x20    0x20
#define LITERAL_PB_IOE_SCOM_FP0_LL_CREDIT_LO_LIMIT_0b0001100    0b0001100
#define LITERAL_PB_IOE_SCOM_FP0_LL_CREDIT_LO_LIMIT_0b0001101    0b0001101
#define LITERAL_PB_IOE_SCOM_FP0_LL_CREDIT_LO_LIMIT_0b0001110    0b0001110
#define LITERAL_PB_IOE_SCOM_FP0_LL_CREDIT_LO_LIMIT_0b0001111    0b0001111
#define LITERAL_PB_IOE_SCOM_FP0_LL_CREDIT_LO_LIMIT_0b0010000    0b0010000
#define LITERAL_PB_IOE_SCOM_FP0_LL_CREDIT_LO_LIMIT_0b0010001    0b0010001
#define LITERAL_PB_IOE_SCOM_FP0_LL_CREDIT_LO_LIMIT_1    1
#define LITERAL_PB_IOE_SCOM_FP1_LL_CREDIT_HI_LIMIT_0x20    0x20
#define LITERAL_PB_IOE_SCOM_FP1_LL_CREDIT_LO_LIMIT_0b0001100    0b0001100
#define LITERAL_PB_IOE_SCOM_FP1_LL_CREDIT_LO_LIMIT_0b0001101    0b0001101
#define LITERAL_PB_IOE_SCOM_FP1_LL_CREDIT_LO_LIMIT_0b0001110    0b0001110
#define LITERAL_PB_IOE_SCOM_FP1_LL_CREDIT_LO_LIMIT_0b0001111    0b0001111
#define LITERAL_PB_IOE_SCOM_FP1_LL_CREDIT_LO_LIMIT_0b0010000    0b0010000
#define LITERAL_PB_IOE_SCOM_FP1_LL_CREDIT_LO_LIMIT_0b0010001    0b0010001
#define LITERAL_PB_IOE_SCOM_FP1_LL_CREDIT_LO_LIMIT_1    1
#define LITERAL_PB_IOE_SCOM_FP23_CMD_EXP_TIME_0x1    0x1
#define LITERAL_PB_IOE_SCOM_FP2_LL_CREDIT_HI_LIMIT_0x20    0x20
#define LITERAL_PB_IOE_SCOM_FP2_LL_CREDIT_LO_LIMIT_0b0001100    0b0001100
#define LITERAL_PB_IOE_SCOM_FP2_LL_CREDIT_LO_LIMIT_0b0001101    0b0001101
#define LITERAL_PB_IOE_SCOM_FP2_LL_CREDIT_LO_LIMIT_0b0001110    0b0001110
#define LITERAL_PB_IOE_SCOM_FP2_LL_CREDIT_LO_LIMIT_0b0001111    0b0001111
#define LITERAL_PB_IOE_SCOM_FP2_LL_CREDIT_LO_LIMIT_0b0010000    0b0010000
#define LITERAL_PB_IOE_SCOM_FP2_LL_CREDIT_LO_LIMIT_0b0010001    0b0010001
#define LITERAL_PB_IOE_SCOM_FP2_LL_CREDIT_LO_LIMIT_1    1
#define LITERAL_PB_IOE_SCOM_FP3_LL_CREDIT_HI_LIMIT_0x20    0x20
#define LITERAL_PB_IOE_SCOM_FP3_LL_CREDIT_LO_LIMIT_0b0001100    0b0001100
#define LITERAL_PB_IOE_SCOM_FP3_LL_CREDIT_LO_LIMIT_0b0001101    0b0001101
#define LITERAL_PB_IOE_SCOM_FP3_LL_CREDIT_LO_LIMIT_0b0001110    0b0001110
#define LITERAL_PB_IOE_SCOM_FP3_LL_CREDIT_LO_LIMIT_0b0001111    0b0001111
#define LITERAL_PB_IOE_SCOM_FP3_LL_CREDIT_LO_LIMIT_0b0010000    0b0010000
#define LITERAL_PB_IOE_SCOM_FP3_LL_CREDIT_LO_LIMIT_0b0010001    0b0010001
#define LITERAL_PB_IOE_SCOM_FP3_LL_CREDIT_LO_LIMIT_1    1
#define LITERAL_PB_IOE_SCOM_FP45_CMD_EXP_TIME_0x1    0x1
#define LITERAL_PB_IOE_SCOM_FP4_LL_CREDIT_HI_LIMIT_0x20    0x20
#define LITERAL_PB_IOE_SCOM_FP4_LL_CREDIT_LO_LIMIT_0b0001100    0b0001100
#define LITERAL_PB_IOE_SCOM_FP4_LL_CREDIT_LO_LIMIT_0b0001101    0b0001101
#define LITERAL_PB_IOE_SCOM_FP4_LL_CREDIT_LO_LIMIT_0b0001110    0b0001110
#define LITERAL_PB_IOE_SCOM_FP4_LL_CREDIT_LO_LIMIT_0b0001111    0b0001111
#define LITERAL_PB_IOE_SCOM_FP4_LL_CREDIT_LO_LIMIT_0b0010000    0b0010000
#define LITERAL_PB_IOE_SCOM_FP4_LL_CREDIT_LO_LIMIT_0b0010001    0b0010001
#define LITERAL_PB_IOE_SCOM_FP4_LL_CREDIT_LO_LIMIT_1    1
#define LITERAL_PB_IOE_SCOM_FP5_LL_CREDIT_HI_LIMIT_0x20    0x20
#define LITERAL_PB_IOE_SCOM_FP5_LL_CREDIT_LO_LIMIT_0b0001100    0b0001100
#define LITERAL_PB_IOE_SCOM_FP5_LL_CREDIT_LO_LIMIT_0b0001101    0b0001101
#define LITERAL_PB_IOE_SCOM_FP5_LL_CREDIT_LO_LIMIT_0b0001110    0b0001110
#define LITERAL_PB_IOE_SCOM_FP5_LL_CREDIT_LO_LIMIT_0b0001111    0b0001111
#define LITERAL_PB_IOE_SCOM_FP5_LL_CREDIT_LO_LIMIT_0b0010000    0b0010000
#define LITERAL_PB_IOE_SCOM_FP5_LL_CREDIT_LO_LIMIT_0b0010001    0b0010001
#define LITERAL_PB_IOE_SCOM_FP5_LL_CREDIT_LO_LIMIT_1    1
#define LITERAL_PB_IOE_SCOM_LINK00_HI_TRACE_CFG_0b0101    0b0101
#define LITERAL_PB_IOE_SCOM_LINK00_LO_TRACE_CFG_0b0101    0b0101
#define LITERAL_PB_IOE_SCOM_LINK02_HI_TRACE_CFG_0b0101    0b0101
#define LITERAL_PB_IOE_SCOM_LINK02_LO_TRACE_CFG_0b0101    0b0101
#define LITERAL_PB_IOE_SCOM_LINK04_HI_TRACE_CFG_0b0101    0b0101
#define LITERAL_PB_IOE_SCOM_LINK04_LO_TRACE_CFG_0b0101    0b0101
#define LITERAL_PB_IOE_SCOM_PB_CFG_IOE01_IS_LOGICAL_PAIR_ON    0x1
#define LITERAL_PB_IOE_SCOM_PB_CFG_IOE23_IS_LOGICAL_PAIR_ON    0x1
#define LITERAL_PB_IOE_SCOM_PB_CFG_IOE45_IS_LOGICAL_PAIR_ON    0x1
#define LITERAL_PB_IOE_SCOM_PB_CFG_LINK01_DIB_VC_LIMIT_0x1F    0x1F
#define LITERAL_PB_IOE_SCOM_PB_CFG_LINK0_DOB_LIMIT_0x40    0x40
#define LITERAL_PB_IOE_SCOM_PB_CFG_LINK0_DOB_VC0_LIMIT_0x3C    0x3C
#define LITERAL_PB_IOE_SCOM_PB_CFG_LINK0_DOB_VC1_LIMIT_0x3C    0x3C
#define LITERAL_PB_IOE_SCOM_PB_CFG_LINK23_DIB_VC_LIMIT_0x1F    0x1F
#define LITERAL_PB_IOE_SCOM_PB_CFG_LINK2_DOB_LIMIT_0x40    0x40
#define LITERAL_PB_IOE_SCOM_PB_CFG_LINK2_DOB_VC0_LIMIT_0x3C    0x3C
#define LITERAL_PB_IOE_SCOM_PB_CFG_LINK2_DOB_VC1_LIMIT_0x3C    0x3C
#define LITERAL_PB_IOE_SCOM_PB_CFG_LINK45_DIB_VC_LIMIT_0x1F    0x1F
#define LITERAL_PB_IOE_SCOM_PB_CFG_LINK4_DOB_LIMIT_0x40    0x40
#define LITERAL_PB_IOE_SCOM_PB_CFG_LINK4_DOB_VC0_LIMIT_0x3C    0x3C
#define LITERAL_PB_IOE_SCOM_PB_CFG_LINK4_DOB_VC1_LIMIT_0x3C    0x3C
#define LITERAL_PB_IOE_SCOM_PB_IOE_FIR_MASK_REG_0xFFFFFFFFFFFFFFFF    0xFFFFFFFFFFFFFFFF

fapi2::ReturnCode p9_fbc_ioe_tl_scom(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& TGT0,
                                     const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>& TGT1)
{
    fapi2::ReturnCode l_rc = 0;

    do
    {
        ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_Type iv_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG;
        l_rc = FAPI_ATTR_GET(ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG, TGT0, iv_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG);

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: FAPI_ATTR_GET (iv_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG)");
            break;
        }

        auto iv_def_X0_ENABLED = (iv_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[0] !=
                                  ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_ATTRIBUTE_VALUE_0);
        fapi2::buffer<uint64_t> PB_IOE_SCOM_PB_CFG_IOE01_IS_LOGICAL_PAIR_scom0;
        l_rc = fapi2::getScom( TGT0, 0x5013423ull, PB_IOE_SCOM_PB_CFG_IOE01_IS_LOGICAL_PAIR_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x5013423)");
            break;
        }

        if (iv_def_X0_ENABLED)
        {
            PB_IOE_SCOM_PB_CFG_IOE01_IS_LOGICAL_PAIR_scom0.insert<uint64_t> (LITERAL_PB_IOE_SCOM_PB_CFG_IOE01_IS_LOGICAL_PAIR_ON, 0,
                    1, 63 );
        }

        fapi2::buffer<uint64_t> PB_IOE_SCOM_FP01_CMD_EXP_TIME_scom0;
        l_rc = fapi2::getScom( TGT0, 0x501340aull, PB_IOE_SCOM_FP01_CMD_EXP_TIME_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x501340a)");
            break;
        }

        if (iv_def_X0_ENABLED)
        {
            PB_IOE_SCOM_FP01_CMD_EXP_TIME_scom0.insert<uint64_t> (LITERAL_PB_IOE_SCOM_FP01_CMD_EXP_TIME_0x1, 22, 2, 62 );
        }

        if (iv_def_X0_ENABLED)
        {
            PB_IOE_SCOM_FP01_CMD_EXP_TIME_scom0.insert<uint64_t> (LITERAL_PB_IOE_SCOM_FP0_LL_CREDIT_HI_LIMIT_0x20, 12, 8, 56 );
        }

        ATTR_FREQ_PB_Type iv_TGT1_ATTR_FREQ_PB;
        ATTR_FREQ_X_Type iv_TGT1_ATTR_FREQ_X;
        l_rc = FAPI_ATTR_GET(ATTR_FREQ_PB, TGT1, iv_TGT1_ATTR_FREQ_PB);

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: FAPI_ATTR_GET (iv_TGT1_ATTR_FREQ_PB)");
            break;
        }

        l_rc = FAPI_ATTR_GET(ATTR_FREQ_X, TGT1, iv_TGT1_ATTR_FREQ_X);

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: FAPI_ATTR_GET (iv_TGT1_ATTR_FREQ_X)");
            break;
        }

        auto iv_def_X_RATIO_12_10 = ((ATTR_FREQ_X_ATTRIBUTE_VALUE_10 * iv_TGT1_ATTR_FREQ_X) >=
                                     (ATTR_FREQ_PB_ATTRIBUTE_VALUE_12 * iv_TGT1_ATTR_FREQ_PB));
        auto iv_def_X_RATIO_11_10 = ((ATTR_FREQ_X_ATTRIBUTE_VALUE_10 * iv_TGT1_ATTR_FREQ_X) >=
                                     (ATTR_FREQ_PB_ATTRIBUTE_VALUE_11 * iv_TGT1_ATTR_FREQ_PB));
        auto iv_def_X_RATIO_10_10 = ((ATTR_FREQ_X_ATTRIBUTE_VALUE_10 * iv_TGT1_ATTR_FREQ_X) >=
                                     (ATTR_FREQ_PB_ATTRIBUTE_VALUE_10 * iv_TGT1_ATTR_FREQ_PB));
        auto iv_def_X_RATIO_10_11 = ((ATTR_FREQ_X_ATTRIBUTE_VALUE_11 * iv_TGT1_ATTR_FREQ_X) >=
                                     (ATTR_FREQ_PB_ATTRIBUTE_VALUE_10 * iv_TGT1_ATTR_FREQ_PB));
        auto iv_def_X_RATIO_10_12 = ((ATTR_FREQ_X_ATTRIBUTE_VALUE_12 * iv_TGT1_ATTR_FREQ_X) >=
                                     (ATTR_FREQ_PB_ATTRIBUTE_VALUE_10 * iv_TGT1_ATTR_FREQ_PB));
        auto iv_def_X_RATIO_10_13 = ((ATTR_FREQ_X_ATTRIBUTE_VALUE_13 * iv_TGT1_ATTR_FREQ_X) >=
                                     (ATTR_FREQ_PB_ATTRIBUTE_VALUE_10 * iv_TGT1_ATTR_FREQ_PB));

        if ((iv_def_X0_ENABLED && (iv_def_X_RATIO_12_10 == LITERAL_PB_IOE_SCOM_FP0_LL_CREDIT_LO_LIMIT_1)))
        {
            PB_IOE_SCOM_FP01_CMD_EXP_TIME_scom0.insert<uint64_t> (LITERAL_PB_IOE_SCOM_FP0_LL_CREDIT_LO_LIMIT_0b0010001, 4, 8, 56 );
        }
        else if ((iv_def_X0_ENABLED && (iv_def_X_RATIO_11_10 == LITERAL_PB_IOE_SCOM_FP0_LL_CREDIT_LO_LIMIT_1)))
        {
            PB_IOE_SCOM_FP01_CMD_EXP_TIME_scom0.insert<uint64_t> (LITERAL_PB_IOE_SCOM_FP0_LL_CREDIT_LO_LIMIT_0b0010000, 4, 8, 56 );
        }
        else if ((iv_def_X0_ENABLED && (iv_def_X_RATIO_10_10 == LITERAL_PB_IOE_SCOM_FP0_LL_CREDIT_LO_LIMIT_1)))
        {
            PB_IOE_SCOM_FP01_CMD_EXP_TIME_scom0.insert<uint64_t> (LITERAL_PB_IOE_SCOM_FP0_LL_CREDIT_LO_LIMIT_0b0001111, 4, 8, 56 );
        }
        else if ((iv_def_X0_ENABLED && (iv_def_X_RATIO_10_11 == LITERAL_PB_IOE_SCOM_FP0_LL_CREDIT_LO_LIMIT_1)))
        {
            PB_IOE_SCOM_FP01_CMD_EXP_TIME_scom0.insert<uint64_t> (LITERAL_PB_IOE_SCOM_FP0_LL_CREDIT_LO_LIMIT_0b0001110, 4, 8, 56 );
        }
        else if ((iv_def_X0_ENABLED && (iv_def_X_RATIO_10_12 == LITERAL_PB_IOE_SCOM_FP0_LL_CREDIT_LO_LIMIT_1)))
        {
            PB_IOE_SCOM_FP01_CMD_EXP_TIME_scom0.insert<uint64_t> (LITERAL_PB_IOE_SCOM_FP0_LL_CREDIT_LO_LIMIT_0b0001101, 4, 8, 56 );
        }
        else if ((iv_def_X0_ENABLED && (iv_def_X_RATIO_10_13 == LITERAL_PB_IOE_SCOM_FP0_LL_CREDIT_LO_LIMIT_1)))
        {
            PB_IOE_SCOM_FP01_CMD_EXP_TIME_scom0.insert<uint64_t> (LITERAL_PB_IOE_SCOM_FP0_LL_CREDIT_LO_LIMIT_0b0001100, 4, 8, 56 );
        }

        if (iv_def_X0_ENABLED)
        {
            PB_IOE_SCOM_FP01_CMD_EXP_TIME_scom0.insert<uint64_t> (LITERAL_PB_IOE_SCOM_FP1_LL_CREDIT_HI_LIMIT_0x20, 44, 8, 56 );
        }

        if ((iv_def_X0_ENABLED && (iv_def_X_RATIO_12_10 == LITERAL_PB_IOE_SCOM_FP1_LL_CREDIT_LO_LIMIT_1)))
        {
            PB_IOE_SCOM_FP01_CMD_EXP_TIME_scom0.insert<uint64_t> (LITERAL_PB_IOE_SCOM_FP1_LL_CREDIT_LO_LIMIT_0b0010001, 36, 8, 56 );
        }
        else if ((iv_def_X0_ENABLED && (iv_def_X_RATIO_11_10 == LITERAL_PB_IOE_SCOM_FP1_LL_CREDIT_LO_LIMIT_1)))
        {
            PB_IOE_SCOM_FP01_CMD_EXP_TIME_scom0.insert<uint64_t> (LITERAL_PB_IOE_SCOM_FP1_LL_CREDIT_LO_LIMIT_0b0010000, 36, 8, 56 );
        }
        else if ((iv_def_X0_ENABLED && (iv_def_X_RATIO_10_10 == LITERAL_PB_IOE_SCOM_FP1_LL_CREDIT_LO_LIMIT_1)))
        {
            PB_IOE_SCOM_FP01_CMD_EXP_TIME_scom0.insert<uint64_t> (LITERAL_PB_IOE_SCOM_FP1_LL_CREDIT_LO_LIMIT_0b0001111, 36, 8, 56 );
        }
        else if ((iv_def_X0_ENABLED && (iv_def_X_RATIO_10_11 == LITERAL_PB_IOE_SCOM_FP1_LL_CREDIT_LO_LIMIT_1)))
        {
            PB_IOE_SCOM_FP01_CMD_EXP_TIME_scom0.insert<uint64_t> (LITERAL_PB_IOE_SCOM_FP1_LL_CREDIT_LO_LIMIT_0b0001110, 36, 8, 56 );
        }
        else if ((iv_def_X0_ENABLED && (iv_def_X_RATIO_10_12 == LITERAL_PB_IOE_SCOM_FP1_LL_CREDIT_LO_LIMIT_1)))
        {
            PB_IOE_SCOM_FP01_CMD_EXP_TIME_scom0.insert<uint64_t> (LITERAL_PB_IOE_SCOM_FP1_LL_CREDIT_LO_LIMIT_0b0001101, 36, 8, 56 );
        }
        else if ((iv_def_X0_ENABLED && (iv_def_X_RATIO_10_13 == LITERAL_PB_IOE_SCOM_FP1_LL_CREDIT_LO_LIMIT_1)))
        {
            PB_IOE_SCOM_FP01_CMD_EXP_TIME_scom0.insert<uint64_t> (LITERAL_PB_IOE_SCOM_FP1_LL_CREDIT_LO_LIMIT_0b0001100, 36, 8, 56 );
        }

        fapi2::buffer<uint64_t> PB_IOE_SCOM_PB_CFG_LINK01_DIB_VC_LIMIT_scom0;
        l_rc = fapi2::getScom( TGT0, 0x5013410ull, PB_IOE_SCOM_PB_CFG_LINK01_DIB_VC_LIMIT_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x5013410)");
            break;
        }

        if (iv_def_X0_ENABLED)
        {
            PB_IOE_SCOM_PB_CFG_LINK01_DIB_VC_LIMIT_scom0.insert<uint64_t> (LITERAL_PB_IOE_SCOM_PB_CFG_LINK01_DIB_VC_LIMIT_0x1F, 24,
                    5, 59 );
        }

        if (iv_def_X0_ENABLED)
        {
            PB_IOE_SCOM_PB_CFG_LINK01_DIB_VC_LIMIT_scom0.insert<uint64_t> (LITERAL_PB_IOE_SCOM_PB_CFG_LINK0_DOB_LIMIT_0x40, 1, 7,
                    57 );
            PB_IOE_SCOM_PB_CFG_LINK01_DIB_VC_LIMIT_scom0.insert<uint64_t> (LITERAL_PB_IOE_SCOM_PB_CFG_LINK0_DOB_LIMIT_0x40, 33, 7,
                    57 );
        }

        if (iv_def_X0_ENABLED)
        {
            PB_IOE_SCOM_PB_CFG_LINK01_DIB_VC_LIMIT_scom0.insert<uint64_t> (LITERAL_PB_IOE_SCOM_PB_CFG_LINK0_DOB_VC0_LIMIT_0x3C, 9,
                    7, 57 );
            PB_IOE_SCOM_PB_CFG_LINK01_DIB_VC_LIMIT_scom0.insert<uint64_t> (LITERAL_PB_IOE_SCOM_PB_CFG_LINK0_DOB_VC0_LIMIT_0x3C, 41,
                    7, 57 );
        }

        if (iv_def_X0_ENABLED)
        {
            PB_IOE_SCOM_PB_CFG_LINK01_DIB_VC_LIMIT_scom0.insert<uint64_t> (LITERAL_PB_IOE_SCOM_PB_CFG_LINK0_DOB_VC1_LIMIT_0x3C, 17,
                    7, 57 );
            PB_IOE_SCOM_PB_CFG_LINK01_DIB_VC_LIMIT_scom0.insert<uint64_t> (LITERAL_PB_IOE_SCOM_PB_CFG_LINK0_DOB_VC1_LIMIT_0x3C, 49,
                    7, 57 );
        }

        fapi2::buffer<uint64_t> PB_IOE_SCOM_LINK00_HI_TRACE_CFG_scom0;
        l_rc = fapi2::getScom( TGT0, 0x5013424ull, PB_IOE_SCOM_LINK00_HI_TRACE_CFG_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x5013424)");
            break;
        }

        if (iv_def_X0_ENABLED)
        {
            PB_IOE_SCOM_LINK00_HI_TRACE_CFG_scom0.insert<uint64_t> (LITERAL_PB_IOE_SCOM_LINK00_HI_TRACE_CFG_0b0101, 0, 4, 60 );
            PB_IOE_SCOM_LINK00_HI_TRACE_CFG_scom0.insert<uint64_t> (LITERAL_PB_IOE_SCOM_LINK00_HI_TRACE_CFG_0b0101, 8, 4, 60 );
        }

        if (iv_def_X0_ENABLED)
        {
            PB_IOE_SCOM_LINK00_HI_TRACE_CFG_scom0.insert<uint64_t> (LITERAL_PB_IOE_SCOM_LINK00_LO_TRACE_CFG_0b0101, 4, 4, 60 );
            PB_IOE_SCOM_LINK00_HI_TRACE_CFG_scom0.insert<uint64_t> (LITERAL_PB_IOE_SCOM_LINK00_LO_TRACE_CFG_0b0101, 12, 4, 60 );
        }

        auto iv_def_X1_ENABLED = (iv_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[1] !=
                                  ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_ATTRIBUTE_VALUE_0);

        if (iv_def_X1_ENABLED)
        {
            PB_IOE_SCOM_PB_CFG_IOE01_IS_LOGICAL_PAIR_scom0.insert<uint64_t> (LITERAL_PB_IOE_SCOM_PB_CFG_IOE23_IS_LOGICAL_PAIR_ON, 1,
                    1, 63 );
        }

        fapi2::buffer<uint64_t> PB_IOE_SCOM_FP23_CMD_EXP_TIME_scom0;
        l_rc = fapi2::getScom( TGT0, 0x501340bull, PB_IOE_SCOM_FP23_CMD_EXP_TIME_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x501340b)");
            break;
        }

        if (iv_def_X1_ENABLED)
        {
            PB_IOE_SCOM_FP23_CMD_EXP_TIME_scom0.insert<uint64_t> (LITERAL_PB_IOE_SCOM_FP23_CMD_EXP_TIME_0x1, 22, 2, 62 );
        }

        if (iv_def_X1_ENABLED)
        {
            PB_IOE_SCOM_FP23_CMD_EXP_TIME_scom0.insert<uint64_t> (LITERAL_PB_IOE_SCOM_FP2_LL_CREDIT_HI_LIMIT_0x20, 12, 8, 56 );
        }

        if ((iv_def_X1_ENABLED && (iv_def_X_RATIO_12_10 == LITERAL_PB_IOE_SCOM_FP2_LL_CREDIT_LO_LIMIT_1)))
        {
            PB_IOE_SCOM_FP23_CMD_EXP_TIME_scom0.insert<uint64_t> (LITERAL_PB_IOE_SCOM_FP2_LL_CREDIT_LO_LIMIT_0b0010001, 4, 8, 56 );
        }
        else if ((iv_def_X1_ENABLED && (iv_def_X_RATIO_11_10 == LITERAL_PB_IOE_SCOM_FP2_LL_CREDIT_LO_LIMIT_1)))
        {
            PB_IOE_SCOM_FP23_CMD_EXP_TIME_scom0.insert<uint64_t> (LITERAL_PB_IOE_SCOM_FP2_LL_CREDIT_LO_LIMIT_0b0010000, 4, 8, 56 );
        }
        else if ((iv_def_X1_ENABLED && (iv_def_X_RATIO_10_10 == LITERAL_PB_IOE_SCOM_FP2_LL_CREDIT_LO_LIMIT_1)))
        {
            PB_IOE_SCOM_FP23_CMD_EXP_TIME_scom0.insert<uint64_t> (LITERAL_PB_IOE_SCOM_FP2_LL_CREDIT_LO_LIMIT_0b0001111, 4, 8, 56 );
        }
        else if ((iv_def_X1_ENABLED && (iv_def_X_RATIO_10_11 == LITERAL_PB_IOE_SCOM_FP2_LL_CREDIT_LO_LIMIT_1)))
        {
            PB_IOE_SCOM_FP23_CMD_EXP_TIME_scom0.insert<uint64_t> (LITERAL_PB_IOE_SCOM_FP2_LL_CREDIT_LO_LIMIT_0b0001110, 4, 8, 56 );
        }
        else if ((iv_def_X1_ENABLED && (iv_def_X_RATIO_10_12 == LITERAL_PB_IOE_SCOM_FP2_LL_CREDIT_LO_LIMIT_1)))
        {
            PB_IOE_SCOM_FP23_CMD_EXP_TIME_scom0.insert<uint64_t> (LITERAL_PB_IOE_SCOM_FP2_LL_CREDIT_LO_LIMIT_0b0001101, 4, 8, 56 );
        }
        else if ((iv_def_X1_ENABLED && (iv_def_X_RATIO_10_13 == LITERAL_PB_IOE_SCOM_FP2_LL_CREDIT_LO_LIMIT_1)))
        {
            PB_IOE_SCOM_FP23_CMD_EXP_TIME_scom0.insert<uint64_t> (LITERAL_PB_IOE_SCOM_FP2_LL_CREDIT_LO_LIMIT_0b0001100, 4, 8, 56 );
        }

        if (iv_def_X1_ENABLED)
        {
            PB_IOE_SCOM_FP23_CMD_EXP_TIME_scom0.insert<uint64_t> (LITERAL_PB_IOE_SCOM_FP3_LL_CREDIT_HI_LIMIT_0x20, 44, 8, 56 );
        }

        if ((iv_def_X1_ENABLED && (iv_def_X_RATIO_12_10 == LITERAL_PB_IOE_SCOM_FP3_LL_CREDIT_LO_LIMIT_1)))
        {
            PB_IOE_SCOM_FP23_CMD_EXP_TIME_scom0.insert<uint64_t> (LITERAL_PB_IOE_SCOM_FP3_LL_CREDIT_LO_LIMIT_0b0010001, 36, 8, 56 );
        }
        else if ((iv_def_X1_ENABLED && (iv_def_X_RATIO_11_10 == LITERAL_PB_IOE_SCOM_FP3_LL_CREDIT_LO_LIMIT_1)))
        {
            PB_IOE_SCOM_FP23_CMD_EXP_TIME_scom0.insert<uint64_t> (LITERAL_PB_IOE_SCOM_FP3_LL_CREDIT_LO_LIMIT_0b0010000, 36, 8, 56 );
        }
        else if ((iv_def_X1_ENABLED && (iv_def_X_RATIO_10_10 == LITERAL_PB_IOE_SCOM_FP3_LL_CREDIT_LO_LIMIT_1)))
        {
            PB_IOE_SCOM_FP23_CMD_EXP_TIME_scom0.insert<uint64_t> (LITERAL_PB_IOE_SCOM_FP3_LL_CREDIT_LO_LIMIT_0b0001111, 36, 8, 56 );
        }
        else if ((iv_def_X1_ENABLED && (iv_def_X_RATIO_10_11 == LITERAL_PB_IOE_SCOM_FP3_LL_CREDIT_LO_LIMIT_1)))
        {
            PB_IOE_SCOM_FP23_CMD_EXP_TIME_scom0.insert<uint64_t> (LITERAL_PB_IOE_SCOM_FP3_LL_CREDIT_LO_LIMIT_0b0001110, 36, 8, 56 );
        }
        else if ((iv_def_X1_ENABLED && (iv_def_X_RATIO_10_12 == LITERAL_PB_IOE_SCOM_FP3_LL_CREDIT_LO_LIMIT_1)))
        {
            PB_IOE_SCOM_FP23_CMD_EXP_TIME_scom0.insert<uint64_t> (LITERAL_PB_IOE_SCOM_FP3_LL_CREDIT_LO_LIMIT_0b0001101, 36, 8, 56 );
        }
        else if ((iv_def_X1_ENABLED && (iv_def_X_RATIO_10_13 == LITERAL_PB_IOE_SCOM_FP3_LL_CREDIT_LO_LIMIT_1)))
        {
            PB_IOE_SCOM_FP23_CMD_EXP_TIME_scom0.insert<uint64_t> (LITERAL_PB_IOE_SCOM_FP3_LL_CREDIT_LO_LIMIT_0b0001100, 36, 8, 56 );
        }

        fapi2::buffer<uint64_t> PB_IOE_SCOM_PB_CFG_LINK23_DIB_VC_LIMIT_scom0;
        l_rc = fapi2::getScom( TGT0, 0x5013411ull, PB_IOE_SCOM_PB_CFG_LINK23_DIB_VC_LIMIT_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x5013411)");
            break;
        }

        if (iv_def_X1_ENABLED)
        {
            PB_IOE_SCOM_PB_CFG_LINK23_DIB_VC_LIMIT_scom0.insert<uint64_t> (LITERAL_PB_IOE_SCOM_PB_CFG_LINK23_DIB_VC_LIMIT_0x1F, 24,
                    5, 59 );
        }

        if (iv_def_X1_ENABLED)
        {
            PB_IOE_SCOM_PB_CFG_LINK23_DIB_VC_LIMIT_scom0.insert<uint64_t> (LITERAL_PB_IOE_SCOM_PB_CFG_LINK2_DOB_LIMIT_0x40, 1, 7,
                    57 );
            PB_IOE_SCOM_PB_CFG_LINK23_DIB_VC_LIMIT_scom0.insert<uint64_t> (LITERAL_PB_IOE_SCOM_PB_CFG_LINK2_DOB_LIMIT_0x40, 33, 7,
                    57 );
        }

        if (iv_def_X1_ENABLED)
        {
            PB_IOE_SCOM_PB_CFG_LINK23_DIB_VC_LIMIT_scom0.insert<uint64_t> (LITERAL_PB_IOE_SCOM_PB_CFG_LINK2_DOB_VC0_LIMIT_0x3C, 9,
                    7, 57 );
            PB_IOE_SCOM_PB_CFG_LINK23_DIB_VC_LIMIT_scom0.insert<uint64_t> (LITERAL_PB_IOE_SCOM_PB_CFG_LINK2_DOB_VC0_LIMIT_0x3C, 41,
                    7, 57 );
        }

        if (iv_def_X1_ENABLED)
        {
            PB_IOE_SCOM_PB_CFG_LINK23_DIB_VC_LIMIT_scom0.insert<uint64_t> (LITERAL_PB_IOE_SCOM_PB_CFG_LINK2_DOB_VC1_LIMIT_0x3C, 17,
                    7, 57 );
            PB_IOE_SCOM_PB_CFG_LINK23_DIB_VC_LIMIT_scom0.insert<uint64_t> (LITERAL_PB_IOE_SCOM_PB_CFG_LINK2_DOB_VC1_LIMIT_0x3C, 49,
                    7, 57 );
        }

        if ((( ! iv_def_X0_ENABLED) && iv_def_X1_ENABLED))
        {
            PB_IOE_SCOM_LINK00_HI_TRACE_CFG_scom0.insert<uint64_t> (LITERAL_PB_IOE_SCOM_LINK02_HI_TRACE_CFG_0b0101, 16, 4, 60 );
            PB_IOE_SCOM_LINK00_HI_TRACE_CFG_scom0.insert<uint64_t> (LITERAL_PB_IOE_SCOM_LINK02_HI_TRACE_CFG_0b0101, 24, 4, 60 );
        }

        if ((( ! iv_def_X0_ENABLED) && iv_def_X1_ENABLED))
        {
            PB_IOE_SCOM_LINK00_HI_TRACE_CFG_scom0.insert<uint64_t> (LITERAL_PB_IOE_SCOM_LINK02_LO_TRACE_CFG_0b0101, 20, 4, 60 );
            PB_IOE_SCOM_LINK00_HI_TRACE_CFG_scom0.insert<uint64_t> (LITERAL_PB_IOE_SCOM_LINK02_LO_TRACE_CFG_0b0101, 28, 4, 60 );
        }

        auto iv_def_X2_ENABLED = (iv_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[2] !=
                                  ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_ATTRIBUTE_VALUE_0);

        if (iv_def_X2_ENABLED)
        {
            PB_IOE_SCOM_PB_CFG_IOE01_IS_LOGICAL_PAIR_scom0.insert<uint64_t> (LITERAL_PB_IOE_SCOM_PB_CFG_IOE45_IS_LOGICAL_PAIR_ON, 2,
                    1, 63 );
        }

        fapi2::buffer<uint64_t> PB_IOE_SCOM_FP45_CMD_EXP_TIME_scom0;
        l_rc = fapi2::getScom( TGT0, 0x501340cull, PB_IOE_SCOM_FP45_CMD_EXP_TIME_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x501340c)");
            break;
        }

        if (iv_def_X2_ENABLED)
        {
            PB_IOE_SCOM_FP45_CMD_EXP_TIME_scom0.insert<uint64_t> (LITERAL_PB_IOE_SCOM_FP45_CMD_EXP_TIME_0x1, 22, 2, 62 );
        }

        if (iv_def_X2_ENABLED)
        {
            PB_IOE_SCOM_FP45_CMD_EXP_TIME_scom0.insert<uint64_t> (LITERAL_PB_IOE_SCOM_FP4_LL_CREDIT_HI_LIMIT_0x20, 12, 8, 56 );
        }

        if ((iv_def_X2_ENABLED && (iv_def_X_RATIO_12_10 == LITERAL_PB_IOE_SCOM_FP4_LL_CREDIT_LO_LIMIT_1)))
        {
            PB_IOE_SCOM_FP45_CMD_EXP_TIME_scom0.insert<uint64_t> (LITERAL_PB_IOE_SCOM_FP4_LL_CREDIT_LO_LIMIT_0b0010001, 4, 8, 56 );
        }
        else if ((iv_def_X2_ENABLED && (iv_def_X_RATIO_11_10 == LITERAL_PB_IOE_SCOM_FP4_LL_CREDIT_LO_LIMIT_1)))
        {
            PB_IOE_SCOM_FP45_CMD_EXP_TIME_scom0.insert<uint64_t> (LITERAL_PB_IOE_SCOM_FP4_LL_CREDIT_LO_LIMIT_0b0010000, 4, 8, 56 );
        }
        else if ((iv_def_X2_ENABLED && (iv_def_X_RATIO_10_10 == LITERAL_PB_IOE_SCOM_FP4_LL_CREDIT_LO_LIMIT_1)))
        {
            PB_IOE_SCOM_FP45_CMD_EXP_TIME_scom0.insert<uint64_t> (LITERAL_PB_IOE_SCOM_FP4_LL_CREDIT_LO_LIMIT_0b0001111, 4, 8, 56 );
        }
        else if ((iv_def_X2_ENABLED && (iv_def_X_RATIO_10_11 == LITERAL_PB_IOE_SCOM_FP4_LL_CREDIT_LO_LIMIT_1)))
        {
            PB_IOE_SCOM_FP45_CMD_EXP_TIME_scom0.insert<uint64_t> (LITERAL_PB_IOE_SCOM_FP4_LL_CREDIT_LO_LIMIT_0b0001110, 4, 8, 56 );
        }
        else if ((iv_def_X2_ENABLED && (iv_def_X_RATIO_10_12 == LITERAL_PB_IOE_SCOM_FP4_LL_CREDIT_LO_LIMIT_1)))
        {
            PB_IOE_SCOM_FP45_CMD_EXP_TIME_scom0.insert<uint64_t> (LITERAL_PB_IOE_SCOM_FP4_LL_CREDIT_LO_LIMIT_0b0001101, 4, 8, 56 );
        }
        else if ((iv_def_X2_ENABLED && (iv_def_X_RATIO_10_13 == LITERAL_PB_IOE_SCOM_FP4_LL_CREDIT_LO_LIMIT_1)))
        {
            PB_IOE_SCOM_FP45_CMD_EXP_TIME_scom0.insert<uint64_t> (LITERAL_PB_IOE_SCOM_FP4_LL_CREDIT_LO_LIMIT_0b0001100, 4, 8, 56 );
        }

        if (iv_def_X2_ENABLED)
        {
            PB_IOE_SCOM_FP45_CMD_EXP_TIME_scom0.insert<uint64_t> (LITERAL_PB_IOE_SCOM_FP5_LL_CREDIT_HI_LIMIT_0x20, 44, 8, 56 );
        }

        if ((iv_def_X2_ENABLED && (iv_def_X_RATIO_12_10 == LITERAL_PB_IOE_SCOM_FP5_LL_CREDIT_LO_LIMIT_1)))
        {
            PB_IOE_SCOM_FP45_CMD_EXP_TIME_scom0.insert<uint64_t> (LITERAL_PB_IOE_SCOM_FP5_LL_CREDIT_LO_LIMIT_0b0010001, 36, 8, 56 );
        }
        else if ((iv_def_X2_ENABLED && (iv_def_X_RATIO_11_10 == LITERAL_PB_IOE_SCOM_FP5_LL_CREDIT_LO_LIMIT_1)))
        {
            PB_IOE_SCOM_FP45_CMD_EXP_TIME_scom0.insert<uint64_t> (LITERAL_PB_IOE_SCOM_FP5_LL_CREDIT_LO_LIMIT_0b0010000, 36, 8, 56 );
        }
        else if ((iv_def_X2_ENABLED && (iv_def_X_RATIO_10_10 == LITERAL_PB_IOE_SCOM_FP5_LL_CREDIT_LO_LIMIT_1)))
        {
            PB_IOE_SCOM_FP45_CMD_EXP_TIME_scom0.insert<uint64_t> (LITERAL_PB_IOE_SCOM_FP5_LL_CREDIT_LO_LIMIT_0b0001111, 36, 8, 56 );
        }
        else if ((iv_def_X2_ENABLED && (iv_def_X_RATIO_10_11 == LITERAL_PB_IOE_SCOM_FP5_LL_CREDIT_LO_LIMIT_1)))
        {
            PB_IOE_SCOM_FP45_CMD_EXP_TIME_scom0.insert<uint64_t> (LITERAL_PB_IOE_SCOM_FP5_LL_CREDIT_LO_LIMIT_0b0001110, 36, 8, 56 );
        }
        else if ((iv_def_X2_ENABLED && (iv_def_X_RATIO_10_12 == LITERAL_PB_IOE_SCOM_FP5_LL_CREDIT_LO_LIMIT_1)))
        {
            PB_IOE_SCOM_FP45_CMD_EXP_TIME_scom0.insert<uint64_t> (LITERAL_PB_IOE_SCOM_FP5_LL_CREDIT_LO_LIMIT_0b0001101, 36, 8, 56 );
        }
        else if ((iv_def_X2_ENABLED && (iv_def_X_RATIO_10_13 == LITERAL_PB_IOE_SCOM_FP5_LL_CREDIT_LO_LIMIT_1)))
        {
            PB_IOE_SCOM_FP45_CMD_EXP_TIME_scom0.insert<uint64_t> (LITERAL_PB_IOE_SCOM_FP5_LL_CREDIT_LO_LIMIT_0b0001100, 36, 8, 56 );
        }

        fapi2::buffer<uint64_t> PB_IOE_SCOM_PB_CFG_LINK45_DIB_VC_LIMIT_scom0;
        l_rc = fapi2::getScom( TGT0, 0x5013412ull, PB_IOE_SCOM_PB_CFG_LINK45_DIB_VC_LIMIT_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x5013412)");
            break;
        }

        if (iv_def_X2_ENABLED)
        {
            PB_IOE_SCOM_PB_CFG_LINK45_DIB_VC_LIMIT_scom0.insert<uint64_t> (LITERAL_PB_IOE_SCOM_PB_CFG_LINK45_DIB_VC_LIMIT_0x1F, 24,
                    5, 59 );
        }

        if (iv_def_X2_ENABLED)
        {
            PB_IOE_SCOM_PB_CFG_LINK45_DIB_VC_LIMIT_scom0.insert<uint64_t> (LITERAL_PB_IOE_SCOM_PB_CFG_LINK4_DOB_LIMIT_0x40, 1, 7,
                    57 );
            PB_IOE_SCOM_PB_CFG_LINK45_DIB_VC_LIMIT_scom0.insert<uint64_t> (LITERAL_PB_IOE_SCOM_PB_CFG_LINK4_DOB_LIMIT_0x40, 33, 7,
                    57 );
        }

        if (iv_def_X2_ENABLED)
        {
            PB_IOE_SCOM_PB_CFG_LINK45_DIB_VC_LIMIT_scom0.insert<uint64_t> (LITERAL_PB_IOE_SCOM_PB_CFG_LINK4_DOB_VC0_LIMIT_0x3C, 9,
                    7, 57 );
            PB_IOE_SCOM_PB_CFG_LINK45_DIB_VC_LIMIT_scom0.insert<uint64_t> (LITERAL_PB_IOE_SCOM_PB_CFG_LINK4_DOB_VC0_LIMIT_0x3C, 41,
                    7, 57 );
        }

        if (iv_def_X2_ENABLED)
        {
            PB_IOE_SCOM_PB_CFG_LINK45_DIB_VC_LIMIT_scom0.insert<uint64_t> (LITERAL_PB_IOE_SCOM_PB_CFG_LINK4_DOB_VC1_LIMIT_0x3C, 17,
                    7, 57 );
            PB_IOE_SCOM_PB_CFG_LINK45_DIB_VC_LIMIT_scom0.insert<uint64_t> (LITERAL_PB_IOE_SCOM_PB_CFG_LINK4_DOB_VC1_LIMIT_0x3C, 49,
                    7, 57 );
        }

        if (((( ! iv_def_X0_ENABLED) && ( ! iv_def_X1_ENABLED)) && iv_def_X2_ENABLED))
        {
            PB_IOE_SCOM_LINK00_HI_TRACE_CFG_scom0.insert<uint64_t> (LITERAL_PB_IOE_SCOM_LINK04_HI_TRACE_CFG_0b0101, 32, 4, 60 );
            PB_IOE_SCOM_LINK00_HI_TRACE_CFG_scom0.insert<uint64_t> (LITERAL_PB_IOE_SCOM_LINK04_HI_TRACE_CFG_0b0101, 40, 4, 60 );
        }

        if (((( ! iv_def_X0_ENABLED) && ( ! iv_def_X1_ENABLED)) && iv_def_X2_ENABLED))
        {
            PB_IOE_SCOM_LINK00_HI_TRACE_CFG_scom0.insert<uint64_t> (LITERAL_PB_IOE_SCOM_LINK04_LO_TRACE_CFG_0b0101, 36, 4, 60 );
            PB_IOE_SCOM_LINK00_HI_TRACE_CFG_scom0.insert<uint64_t> (LITERAL_PB_IOE_SCOM_LINK04_LO_TRACE_CFG_0b0101, 44, 4, 60 );
        }

        fapi2::buffer<uint64_t> PB_IOE_SCOM_PB_IOE_FIR_MASK_REG_scom0;
        l_rc = fapi2::getScom( TGT0, 0x5013403ull, PB_IOE_SCOM_PB_IOE_FIR_MASK_REG_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x5013403)");
            break;
        }

        if (((iv_def_X0_ENABLED || iv_def_X1_ENABLED) || iv_def_X2_ENABLED))
        {
            PB_IOE_SCOM_PB_IOE_FIR_MASK_REG_scom0.insert<uint64_t> (LITERAL_PB_IOE_SCOM_PB_IOE_FIR_MASK_REG_0xFFFFFFFFFFFFFFFF, 0,
                    64, 0 );
        }


        l_rc = fapi2::putScom( TGT0, 0x5013403ull, PB_IOE_SCOM_PB_IOE_FIR_MASK_REG_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x5013403)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x501340aull, PB_IOE_SCOM_FP01_CMD_EXP_TIME_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x501340a)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x501340bull, PB_IOE_SCOM_FP23_CMD_EXP_TIME_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x501340b)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x501340cull, PB_IOE_SCOM_FP45_CMD_EXP_TIME_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x501340c)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x5013410ull, PB_IOE_SCOM_PB_CFG_LINK01_DIB_VC_LIMIT_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x5013410)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x5013411ull, PB_IOE_SCOM_PB_CFG_LINK23_DIB_VC_LIMIT_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x5013411)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x5013412ull, PB_IOE_SCOM_PB_CFG_LINK45_DIB_VC_LIMIT_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x5013412)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x5013423ull, PB_IOE_SCOM_PB_CFG_IOE01_IS_LOGICAL_PAIR_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x5013423)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x5013424ull, PB_IOE_SCOM_LINK00_HI_TRACE_CFG_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x5013424)");
            break;
        }

    }
    while(0);

    return l_rc;
}

