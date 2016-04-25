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

using namespace fapi2;

constexpr auto literal_0xFFFFFFFFFFFFFFFF = 0xFFFFFFFFFFFFFFFF;

fapi2::ReturnCode p9_fbc_ioo_dl_scom(const fapi2::Target<fapi2::TARGET_TYPE_OBUS>& TGT0)
{
    fapi2::ReturnCode l_rc = 0;

    do
    {
        fapi2::buffer<uint64_t> l_scom_buffer;
        fapi2::ATTR_OPTICS_CONFIG_MODE_Type l_TGT0_ATTR_OPTICS_CONFIG_MODE;
        l_rc = FAPI_ATTR_GET(fapi2::ATTR_OPTICS_CONFIG_MODE, TGT0, l_TGT0_ATTR_OPTICS_CONFIG_MODE);

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: FAPI_ATTR_GET (ATTR_OPTICS_CONFIG_MODE)");
            break;
        }

        auto l_def_OBUS_FBC_ENABLED = (l_TGT0_ATTR_OPTICS_CONFIG_MODE == ENUM_ATTR_OPTICS_CONFIG_MODE_SMP);
        {
            l_rc = fapi2::getScom( TGT0, 0x9010800ull, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x9010800ull)");
                break;
            }

            {
                if (l_def_OBUS_FBC_ENABLED)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0xFFFFFFFFFFFFFFFF, 0, 64, 0 );
                }
            }

            l_rc = fapi2::putScom(TGT0, 0x9010800ull, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x9010800ull)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x901080aull, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x901080aull)");
                break;
            }

            {
                if (l_def_OBUS_FBC_ENABLED)
                {
                    constexpr auto l_scom_buffer_ON = 0x1;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ON, 0, 1, 63 );
                }
            }

            l_rc = fapi2::putScom(TGT0, 0x901080aull, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x901080aull)");
                break;
            }
        }
    }
    while (0);

    return l_rc;
}
