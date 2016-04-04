/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/initfiles/p9_fbc_ioe_dl_scom.C $      */
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
#include "p9_fbc_ioe_dl_scom.H"
#include <stdint.h>
#include <stddef.h>
#include <fapi2.H>

using namespace fapi2;

constexpr auto literal_0xFFFFFFFFFFFFFFFF = 0xFFFFFFFFFFFFFFFF;
constexpr auto literal_0xE00 = 0xE00;
constexpr auto literal_0b11 = 0b11;

fapi2::ReturnCode p9_fbc_ioe_dl_scom(const fapi2::Target<fapi2::TARGET_TYPE_XBUS>& TGT0)
{
    fapi2::ReturnCode l_rc = 0;

    do
    {
        fapi2::buffer<uint64_t> l_scom_buffer;
        {
            l_rc = fapi2::getScom( TGT0, 0x6011803ull, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x6011803ull)");
                break;
            }

            l_scom_buffer.insert<uint64_t> (literal_0xFFFFFFFFFFFFFFFF, 0, 64, 0 );
            l_rc = fapi2::putScom(TGT0, 0x6011803ull, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x6011803ull)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x601180aull, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x601180aull)");
                break;
            }

            constexpr auto l_scom_buffer_ON = 0x1;
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_ON, 0, 1, 63 );
            l_rc = fapi2::putScom(TGT0, 0x601180aull, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x601180aull)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x6011818ull, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x6011818ull)");
                break;
            }

            l_scom_buffer.insert<uint64_t> (literal_0xE00, 8, 3, 61 );
            l_rc = fapi2::putScom(TGT0, 0x6011818ull, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x6011818ull)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x6011819ull, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x6011819ull)");
                break;
            }

            l_scom_buffer.insert<uint64_t> (literal_0b11, 8, 2, 62 );
            l_rc = fapi2::putScom(TGT0, 0x6011819ull, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x6011819ull)");
                break;
            }
        }
    }
    while (0);

    return l_rc;
}
