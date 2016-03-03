/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/initfiles/p9_fbc_ioo_dl_scom.C $      */
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
#include "p9_fbc_ioo_dl_scom.H"
#include <stdint.h>
#include <stddef.h>
#include <fapi2.H>
#include <attribute_ids.H>
#include <target_types.H>
#include <fapi2_attribute_service.H>
using namespace fapi2;

#define ATTR_OPTICS_CONFIG_MODE_ATTRIBUTE_VALUE_ENUM_ATTR_OPTICS_CONFIG_MODE_SMP    ENUM_ATTR_OPTICS_CONFIG_MODE_SMP
#define LITERAL_PB_IOO_LL0_CONFIG_LINK_PAIR_ON    0x1
#define LITERAL_PB_IOO_LL0_PB_IOOL_FIR_REG_0xFFFFFFFFFFFFFFFF    0xFFFFFFFFFFFFFFFF

fapi2::ReturnCode p9_fbc_ioo_dl_scom(const fapi2::Target<fapi2::TARGET_TYPE_OBUS>& TGT0)
{
    fapi2::ReturnCode l_rc = 0;

    do
    {
        ATTR_OPTICS_CONFIG_MODE_Type iv_TGT0_ATTR_OPTICS_CONFIG_MODE;
        l_rc = FAPI_ATTR_GET(ATTR_OPTICS_CONFIG_MODE, TGT0, iv_TGT0_ATTR_OPTICS_CONFIG_MODE);

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: FAPI_ATTR_GET (iv_TGT0_ATTR_OPTICS_CONFIG_MODE)");
            break;
        }

        auto iv_def_OBUS_FBC_ENABLED = (iv_TGT0_ATTR_OPTICS_CONFIG_MODE ==
                                        ATTR_OPTICS_CONFIG_MODE_ATTRIBUTE_VALUE_ENUM_ATTR_OPTICS_CONFIG_MODE_SMP);
        fapi2::buffer<uint64_t> PB_IOO_LL0_CONFIG_LINK_PAIR_scom0;
        l_rc = fapi2::getScom( TGT0, 0x901080aull, PB_IOO_LL0_CONFIG_LINK_PAIR_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x901080a)");
            break;
        }

        if (iv_def_OBUS_FBC_ENABLED)
        {
            PB_IOO_LL0_CONFIG_LINK_PAIR_scom0.insert<uint64_t> (LITERAL_PB_IOO_LL0_CONFIG_LINK_PAIR_ON, 0, 1, 63 );
        }

        fapi2::buffer<uint64_t> PB_IOO_LL0_PB_IOOL_FIR_REG_scom0;
        l_rc = fapi2::getScom( TGT0, 0x9010800ull, PB_IOO_LL0_PB_IOOL_FIR_REG_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x9010800)");
            break;
        }

        if (iv_def_OBUS_FBC_ENABLED)
        {
            PB_IOO_LL0_PB_IOOL_FIR_REG_scom0.insert<uint64_t> (LITERAL_PB_IOO_LL0_PB_IOOL_FIR_REG_0xFFFFFFFFFFFFFFFF, 0, 64, 0 );
        }


        l_rc = fapi2::putScom( TGT0, 0x9010800ull, PB_IOO_LL0_PB_IOOL_FIR_REG_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x9010800)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x901080aull, PB_IOO_LL0_CONFIG_LINK_PAIR_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x901080a)");
            break;
        }

    }
    while(0);

    return l_rc;
}

