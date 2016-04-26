/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/initfiles/p9_npu_scom.C $             */
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
#include "p9_npu_scom.H"
#include <stdint.h>
#include <stddef.h>
#include <fapi2.H>

using namespace fapi2;

constexpr auto literal_2 = 2;
constexpr auto literal_3 = 3;
constexpr auto literal_1 = 1;
constexpr auto literal_0 = 0;
constexpr auto literal_0x0 = 0x0;
constexpr auto literal_0x1111111111111111 = 0x1111111111111111;
constexpr auto literal_0x0000000000000000 = 0x0000000000000000;

fapi2::ReturnCode p9_npu_scom(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& TGT0,
                              const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>& TGT1)
{
    fapi2::ReturnCode l_rc = 0;

    do
    {
        fapi2::buffer<uint64_t> l_scom_buffer;
        fapi2::ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE_Type l_TGT0_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE;
        l_rc = FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE, TGT0, l_TGT0_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE);

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: FAPI_ATTR_GET (ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE)");
            break;
        }

        {
            l_rc = fapi2::getScom( TGT0, 0x5011000ull, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x5011000ull)");
                break;
            }

            {
                l_scom_buffer.insert<uint64_t> (((((l_TGT0_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE[literal_0] == literal_2)
                                                   || (l_TGT0_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE[literal_1] == literal_2))
                                                  || (l_TGT0_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE[literal_2] == literal_2))
                                                 || (l_TGT0_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE[literal_3] == literal_2)), 38, 1, 63 );
            }

            l_rc = fapi2::putScom(TGT0, 0x5011000ull, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x5011000ull)");
                break;
            }
        }

        fapi2::ATTR_PROC_EPS_READ_CYCLES_Type l_TGT1_ATTR_PROC_EPS_READ_CYCLES;
        l_rc = FAPI_ATTR_GET(fapi2::ATTR_PROC_EPS_READ_CYCLES, TGT1, l_TGT1_ATTR_PROC_EPS_READ_CYCLES);

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: FAPI_ATTR_GET (ATTR_PROC_EPS_READ_CYCLES)");
            break;
        }

        fapi2::ATTR_PROC_EPS_WRITE_CYCLES_Type l_TGT1_ATTR_PROC_EPS_WRITE_CYCLES;
        l_rc = FAPI_ATTR_GET(fapi2::ATTR_PROC_EPS_WRITE_CYCLES, TGT1, l_TGT1_ATTR_PROC_EPS_WRITE_CYCLES);

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: FAPI_ATTR_GET (ATTR_PROC_EPS_WRITE_CYCLES)");
            break;
        }

        {
            l_rc = fapi2::getScom( TGT0, 0x5011002ull, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x5011002ull)");
                break;
            }

            {
                l_scom_buffer.insert<uint64_t> (l_TGT1_ATTR_PROC_EPS_READ_CYCLES[literal_0], 28, 12, 52 );
            }

            {
                l_scom_buffer.insert<uint64_t> (l_TGT1_ATTR_PROC_EPS_READ_CYCLES[literal_1], 40, 12, 52 );
            }

            {
                l_scom_buffer.insert<uint64_t> (l_TGT1_ATTR_PROC_EPS_READ_CYCLES[literal_2], 52, 12, 52 );
            }

            {
                l_scom_buffer.insert<uint64_t> (literal_0x0, 0, 4, 60 );
            }

            {
                l_scom_buffer.insert<uint64_t> (l_TGT1_ATTR_PROC_EPS_WRITE_CYCLES[literal_0], 4, 12, 52 );
            }

            {
                l_scom_buffer.insert<uint64_t> (l_TGT1_ATTR_PROC_EPS_WRITE_CYCLES[literal_1], 16, 12, 52 );
            }

            l_rc = fapi2::putScom(TGT0, 0x5011002ull, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x5011002ull)");
                break;
            }
        }

        {
            l_rc = fapi2::getScom( TGT0, 0x5011008ull, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x5011008ull)");
                break;
            }

            {
                l_scom_buffer.insert<uint64_t> (((((l_TGT0_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE[literal_0] == literal_2)
                                                   || (l_TGT0_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE[literal_1] == literal_2))
                                                  || (l_TGT0_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE[literal_2] == literal_2))
                                                 || (l_TGT0_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE[literal_3] == literal_2)), 51, 1, 63 );
            }

            l_rc = fapi2::putScom(TGT0, 0x5011008ull, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x5011008ull)");
                break;
            }
        }

        {
            l_rc = fapi2::getScom( TGT0, 0x5011403ull, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x5011403ull)");
                break;
            }

            {
                l_scom_buffer.insert<uint64_t> (literal_0x1111111111111111, 0, 64, 0 );
            }

            l_rc = fapi2::putScom(TGT0, 0x5011403ull, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x5011403ull)");
                break;
            }
        }

        {
            l_rc = fapi2::getScom( TGT0, 0x5011406ull, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x5011406ull)");
                break;
            }

            {
                l_scom_buffer.insert<uint64_t> (literal_0x0000000000000000, 0, 64, 0 );
            }

            l_rc = fapi2::putScom(TGT0, 0x5011406ull, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x5011406ull)");
                break;
            }
        }

        {
            l_rc = fapi2::getScom( TGT0, 0x5011407ull, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x5011407ull)");
                break;
            }

            {
                l_scom_buffer.insert<uint64_t> (literal_0x0000000000000000, 0, 64, 0 );
            }

            l_rc = fapi2::putScom(TGT0, 0x5011407ull, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x5011407ull)");
                break;
            }
        }

        {
            l_rc = fapi2::getScom( TGT0, 0x5011446ull, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x5011446ull)");
                break;
            }

            {
                l_scom_buffer.insert<uint64_t> (literal_0x0000000000000000, 0, 64, 0 );
            }

            l_rc = fapi2::putScom(TGT0, 0x5011446ull, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x5011446ull)");
                break;
            }
        }

        {
            l_rc = fapi2::getScom( TGT0, 0x5011447ull, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x5011447ull)");
                break;
            }

            {
                l_scom_buffer.insert<uint64_t> (literal_0x0000000000000000, 0, 64, 0 );
            }

            l_rc = fapi2::putScom(TGT0, 0x5011447ull, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x5011447ull)");
                break;
            }
        }
    }
    while (0);

    return l_rc;
}
