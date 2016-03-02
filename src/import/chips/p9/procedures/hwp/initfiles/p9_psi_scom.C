/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/initfiles/p9_psi_scom.C $             */
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
#include "p9_psi_scom.H"
#include <stdint.h>
#include <stddef.h>
#include <fapi2.H>
#include <attribute_ids.H>
#include <target_types.H>
#include <fapi2_attribute_service.H>
using namespace fapi2;

#define LITERAL_BRIDGE_PSIHB_PSIHB_ERROR_MASK_REG_0b00000    0b00000
#define LITERAL_BRIDGE_PSIHB_PSIHB_ERROR_MASK_REG_0x000    0x000
#define LITERAL_BRIDGE_PSIHB_PSIHB_FIR_ACTION0_REG_0x0000000000000000    0x0000000000000000
#define LITERAL_BRIDGE_PSIHB_PSIHB_FIR_ACTION1_REG_0xC629000000000000    0xC629000000000000
#define LITERAL_BRIDGE_PSIHB_PSIHB_FIR_MASK_REG_0x3902FFF800000000    0x3902FFF800000000

fapi2::ReturnCode p9_psi_scom(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& TGT0)
{
    fapi2::ReturnCode l_rc = 0;

    do
    {
        fapi2::buffer<uint64_t> BRIDGE_PSIHB_PSIHB_ERROR_MASK_REG_scom0;
        l_rc = fapi2::getScom( TGT0, 0x501290full, BRIDGE_PSIHB_PSIHB_ERROR_MASK_REG_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x501290f)");
            break;
        }

        BRIDGE_PSIHB_PSIHB_ERROR_MASK_REG_scom0.insert<uint64_t> (LITERAL_BRIDGE_PSIHB_PSIHB_ERROR_MASK_REG_0x000, 0, 16, 48 );
        BRIDGE_PSIHB_PSIHB_ERROR_MASK_REG_scom0.insert<uint64_t> (LITERAL_BRIDGE_PSIHB_PSIHB_ERROR_MASK_REG_0x000, 16, 12, 36 );
        BRIDGE_PSIHB_PSIHB_ERROR_MASK_REG_scom0.insert<uint64_t> (LITERAL_BRIDGE_PSIHB_PSIHB_ERROR_MASK_REG_0x000, 0, 4, 32 );
        BRIDGE_PSIHB_PSIHB_ERROR_MASK_REG_scom0.insert<uint64_t> (LITERAL_BRIDGE_PSIHB_PSIHB_ERROR_MASK_REG_0x000, 32, 12, 20 );
        BRIDGE_PSIHB_PSIHB_ERROR_MASK_REG_scom0.insert<uint64_t> (LITERAL_BRIDGE_PSIHB_PSIHB_ERROR_MASK_REG_0x000, 0, 4, 16 );
        BRIDGE_PSIHB_PSIHB_ERROR_MASK_REG_scom0.insert<uint64_t> (LITERAL_BRIDGE_PSIHB_PSIHB_ERROR_MASK_REG_0x000, 48, 5, 11 );
        BRIDGE_PSIHB_PSIHB_ERROR_MASK_REG_scom0.insert<uint64_t> (LITERAL_BRIDGE_PSIHB_PSIHB_ERROR_MASK_REG_0b00000, 0, 16,
                48 );
        BRIDGE_PSIHB_PSIHB_ERROR_MASK_REG_scom0.insert<uint64_t> (LITERAL_BRIDGE_PSIHB_PSIHB_ERROR_MASK_REG_0b00000, 16, 12,
                36 );
        BRIDGE_PSIHB_PSIHB_ERROR_MASK_REG_scom0.insert<uint64_t> (LITERAL_BRIDGE_PSIHB_PSIHB_ERROR_MASK_REG_0b00000, 0, 4, 32 );
        BRIDGE_PSIHB_PSIHB_ERROR_MASK_REG_scom0.insert<uint64_t> (LITERAL_BRIDGE_PSIHB_PSIHB_ERROR_MASK_REG_0b00000, 32, 12,
                20 );
        BRIDGE_PSIHB_PSIHB_ERROR_MASK_REG_scom0.insert<uint64_t> (LITERAL_BRIDGE_PSIHB_PSIHB_ERROR_MASK_REG_0b00000, 0, 4, 16 );
        BRIDGE_PSIHB_PSIHB_ERROR_MASK_REG_scom0.insert<uint64_t> (LITERAL_BRIDGE_PSIHB_PSIHB_ERROR_MASK_REG_0b00000, 48, 5,
                11 );

        fapi2::buffer<uint64_t> BRIDGE_PSIHB_PSIHB_FIR_ACTION0_REG_scom0;
        l_rc = fapi2::getScom( TGT0, 0x5012906ull, BRIDGE_PSIHB_PSIHB_FIR_ACTION0_REG_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x5012906)");
            break;
        }

        BRIDGE_PSIHB_PSIHB_FIR_ACTION0_REG_scom0.insert<uint64_t>
        (LITERAL_BRIDGE_PSIHB_PSIHB_FIR_ACTION0_REG_0x0000000000000000, 0, 29, 35 );
        BRIDGE_PSIHB_PSIHB_FIR_ACTION0_REG_scom0.insert<uint64_t>
        (LITERAL_BRIDGE_PSIHB_PSIHB_FIR_ACTION0_REG_0x0000000000000000, 0, 21, 14 );

        fapi2::buffer<uint64_t> BRIDGE_PSIHB_PSIHB_FIR_ACTION1_REG_scom0;
        l_rc = fapi2::getScom( TGT0, 0x5012907ull, BRIDGE_PSIHB_PSIHB_FIR_ACTION1_REG_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x5012907)");
            break;
        }

        BRIDGE_PSIHB_PSIHB_FIR_ACTION1_REG_scom0.insert<uint64_t>
        (LITERAL_BRIDGE_PSIHB_PSIHB_FIR_ACTION1_REG_0xC629000000000000, 0, 29, 35 );
        BRIDGE_PSIHB_PSIHB_FIR_ACTION1_REG_scom0.insert<uint64_t>
        (LITERAL_BRIDGE_PSIHB_PSIHB_FIR_ACTION1_REG_0xC629000000000000, 0, 21, 14 );

        fapi2::buffer<uint64_t> BRIDGE_PSIHB_PSIHB_FIR_MASK_REG_scom0;
        l_rc = fapi2::getScom( TGT0, 0x5012903ull, BRIDGE_PSIHB_PSIHB_FIR_MASK_REG_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x5012903)");
            break;
        }

        BRIDGE_PSIHB_PSIHB_FIR_MASK_REG_scom0.insert<uint64_t> (LITERAL_BRIDGE_PSIHB_PSIHB_FIR_MASK_REG_0x3902FFF800000000, 0,
                29, 35 );
        BRIDGE_PSIHB_PSIHB_FIR_MASK_REG_scom0.insert<uint64_t> (LITERAL_BRIDGE_PSIHB_PSIHB_FIR_MASK_REG_0x3902FFF800000000, 0,
                17, 18 );


        l_rc = fapi2::putScom( TGT0, 0x5012903ull, BRIDGE_PSIHB_PSIHB_FIR_MASK_REG_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x5012903)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x5012906ull, BRIDGE_PSIHB_PSIHB_FIR_ACTION0_REG_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x5012906)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x5012907ull, BRIDGE_PSIHB_PSIHB_FIR_ACTION1_REG_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x5012907)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x501290full, BRIDGE_PSIHB_PSIHB_ERROR_MASK_REG_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x501290f)");
            break;
        }

    }
    while(0);

    return l_rc;
}

