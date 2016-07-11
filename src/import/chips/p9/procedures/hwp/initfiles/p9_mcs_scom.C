/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/initfiles/p9_mcs_scom.C $             */
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
#include "p9_mcs_scom.H"
#include <stdint.h>
#include <stddef.h>
#include <fapi2.H>

using namespace fapi2;

constexpr auto literal_0b0111 = 0b0111;

fapi2::ReturnCode p9_mcs_scom(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& TGT0)
{
    fapi2::ReturnCode l_rc = 0;

    do
    {
        fapi2::buffer<uint64_t> l_scom_buffer;
        {
            l_rc = fapi2::getScom( TGT0, 0x5010810ull, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x5010810ull)");
                break;
            }

            {
                l_scom_buffer.insert<uint64_t> (literal_0b0111, 46, 4, 60 );
            }

            l_rc = fapi2::putScom(TGT0, 0x5010810ull, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x5010810ull)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x5010812ull, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x5010812ull)");
                break;
            }

            {
                constexpr auto l_MC01_PBI01_SCOMFIR_MCMODE1_DISABLE_FP_M_BIT_ON = 0x1;
                l_scom_buffer.insert<uint64_t> (l_MC01_PBI01_SCOMFIR_MCMODE1_DISABLE_FP_M_BIT_ON, 10, 1, 63 );
            }

            l_rc = fapi2::putScom(TGT0, 0x5010812ull, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x5010812ull)");
                break;
            }
        }
    }
    while (0);

    return l_rc;
}
