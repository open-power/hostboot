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

using namespace fapi2;

constexpr auto literal_0b00111001000000101111111111111 = 0b00111001000000101111111111111;
constexpr auto literal_0b00000000000000000000000000000 = 0b00000000000000000000000000000;
constexpr auto literal_0b11000110001010010000000000000 = 0b11000110001010010000000000000;
constexpr auto literal_0x000 = 0x000;
constexpr auto literal_0b00000 = 0b00000;

fapi2::ReturnCode p9_psi_scom(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& TGT0)
{
    fapi2::ReturnCode l_rc = 0;

    do
    {
        fapi2::buffer<uint64_t> l_scom_buffer;
        {
            l_rc = fapi2::getScom( TGT0, 0x5012903ull, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x5012903ull)");
                break;
            }

            l_scom_buffer.insert<uint64_t> (literal_0b00111001000000101111111111111, 0, 29, 18 );
            l_rc = fapi2::putScom(TGT0, 0x5012903ull, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x5012903ull)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x5012906ull, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x5012906ull)");
                break;
            }

            l_scom_buffer.insert<uint64_t> (literal_0b00000000000000000000000000000, 0, 29, 14 );
            l_rc = fapi2::putScom(TGT0, 0x5012906ull, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x5012906ull)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x5012907ull, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x5012907ull)");
                break;
            }

            l_scom_buffer.insert<uint64_t> (literal_0b11000110001010010000000000000, 0, 29, 14 );
            l_rc = fapi2::putScom(TGT0, 0x5012907ull, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x5012907ull)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x501290full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x501290full)");
                break;
            }

            l_scom_buffer.insert<uint64_t> (literal_0x000, 16, 12, 27 );
            l_scom_buffer.insert<uint64_t> (literal_0x000, 32, 12, 43 );
            l_scom_buffer.insert<uint64_t> (literal_0x000, 48, 5, 59 );
            l_scom_buffer.insert<uint64_t> (literal_0b00000, 16, 12, 27 );
            l_scom_buffer.insert<uint64_t> (literal_0b00000, 32, 12, 43 );
            l_scom_buffer.insert<uint64_t> (literal_0b00000, 48, 5, 59 );
            l_rc = fapi2::putScom(TGT0, 0x501290full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x501290full)");
                break;
            }
        }
    }
    while (0);

    return l_rc;
}
