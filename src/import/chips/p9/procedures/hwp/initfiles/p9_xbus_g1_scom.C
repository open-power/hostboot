/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/initfiles/p9_xbus_g1_scom.C $         */
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
#include "p9_xbus_g1_scom.H"
#include <stdint.h>
#include <stddef.h>
#include <fapi2.H>

using namespace fapi2;

constexpr auto literal_0 = 0;
constexpr auto literal_1 = 1;
constexpr auto literal_0b0000 = 0b0000;
constexpr auto literal_0b0110 = 0b0110;
constexpr auto literal_0b00000 = 0b00000;
constexpr auto literal_0b01111 = 0b01111;
constexpr auto literal_0b01100 = 0b01100;
constexpr auto literal_0b1011 = 0b1011;
constexpr auto literal_0b0000000 = 0b0000000;
constexpr auto literal_0b0000011 = 0b0000011;
constexpr auto literal_0b000000 = 0b000000;
constexpr auto literal_0b100111 = 0b100111;
constexpr auto literal_0b000001 = 0b000001;
constexpr auto literal_0b1010 = 0b1010;
constexpr auto literal_0b11 = 0b11;
constexpr auto literal_0b0010000 = 0b0010000;
constexpr auto literal_0b00001 = 0b00001;
constexpr auto literal_0b0010001 = 0b0010001;
constexpr auto literal_0b0000000000000000 = 0b0000000000000000;
constexpr auto literal_0b01111111 = 0b01111111;
constexpr auto literal_0b00 = 0b00;
constexpr auto literal_0b01 = 0b01;

fapi2::ReturnCode p9_xbus_g1_scom(const fapi2::Target<fapi2::TARGET_TYPE_XBUS>& TGT0,
                                  const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>& TGT1)
{
    fapi2::ReturnCode l_rc = 0;

    do
    {
        fapi2::buffer<uint64_t> l_scom_buffer;
        fapi2::ATTR_IS_SIMULATION_Type l_TGT1_ATTR_IS_SIMULATION;
        l_rc = FAPI_ATTR_GET(fapi2::ATTR_IS_SIMULATION, TGT1, l_TGT1_ATTR_IS_SIMULATION);

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: FAPI_ATTR_GET (ATTR_IS_SIMULATION)");
            break;
        }

        auto l_def_IS_HW = (l_TGT1_ATTR_IS_SIMULATION == literal_0);
        auto l_def_IS_SIM = (l_TGT1_ATTR_IS_SIMULATION == literal_1);
        {
            l_rc = fapi2::getScom( TGT0, 0x8000002006010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8000002006010c3full)");
                break;
            }

            {
                if (l_def_IS_HW)
                {
                    constexpr auto l_scom_buffer_OFF = 0x0;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_OFF, 53, 1, 63 );
                }
                else if (l_def_IS_SIM)
                {
                    constexpr auto l_scom_buffer_ON = 0x1;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ON, 53, 1, 63 );
                }
            }

            {
                constexpr auto l_scom_buffer_OFF = 0x0;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_OFF, 54, 1, 63 );
            }

            {
                constexpr auto l_scom_buffer_OFF = 0x0;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_OFF, 55, 1, 63 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8000002006010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8000002006010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8000002106010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8000002106010c3full)");
                break;
            }

            {
                if (l_def_IS_HW)
                {
                    constexpr auto l_scom_buffer_OFF = 0x0;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_OFF, 53, 1, 63 );
                }
                else if (l_def_IS_SIM)
                {
                    constexpr auto l_scom_buffer_ON = 0x1;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ON, 53, 1, 63 );
                }
            }

            {
                constexpr auto l_scom_buffer_OFF = 0x0;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_OFF, 54, 1, 63 );
            }

            {
                constexpr auto l_scom_buffer_OFF = 0x0;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_OFF, 55, 1, 63 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8000002106010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8000002106010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8000002206010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8000002206010c3full)");
                break;
            }

            {
                if (l_def_IS_HW)
                {
                    constexpr auto l_scom_buffer_OFF = 0x0;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_OFF, 53, 1, 63 );
                }
                else if (l_def_IS_SIM)
                {
                    constexpr auto l_scom_buffer_ON = 0x1;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ON, 53, 1, 63 );
                }
            }

            {
                constexpr auto l_scom_buffer_OFF = 0x0;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_OFF, 54, 1, 63 );
            }

            {
                constexpr auto l_scom_buffer_OFF = 0x0;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_OFF, 55, 1, 63 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8000002206010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8000002206010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8000002306010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8000002306010c3full)");
                break;
            }

            {
                if (l_def_IS_HW)
                {
                    constexpr auto l_scom_buffer_OFF = 0x0;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_OFF, 53, 1, 63 );
                }
                else if (l_def_IS_SIM)
                {
                    constexpr auto l_scom_buffer_ON = 0x1;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ON, 53, 1, 63 );
                }
            }

            {
                constexpr auto l_scom_buffer_OFF = 0x0;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_OFF, 54, 1, 63 );
            }

            {
                constexpr auto l_scom_buffer_OFF = 0x0;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_OFF, 55, 1, 63 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8000002306010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8000002306010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8000002406010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8000002406010c3full)");
                break;
            }

            {
                if (l_def_IS_HW)
                {
                    constexpr auto l_scom_buffer_OFF = 0x0;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_OFF, 53, 1, 63 );
                }
                else if (l_def_IS_SIM)
                {
                    constexpr auto l_scom_buffer_ON = 0x1;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ON, 53, 1, 63 );
                }
            }

            {
                constexpr auto l_scom_buffer_OFF = 0x0;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_OFF, 54, 1, 63 );
            }

            {
                constexpr auto l_scom_buffer_OFF = 0x0;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_OFF, 55, 1, 63 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8000002406010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8000002406010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8000002506010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8000002506010c3full)");
                break;
            }

            {
                if (l_def_IS_HW)
                {
                    constexpr auto l_scom_buffer_OFF = 0x0;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_OFF, 53, 1, 63 );
                }
                else if (l_def_IS_SIM)
                {
                    constexpr auto l_scom_buffer_ON = 0x1;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ON, 53, 1, 63 );
                }
            }

            {
                constexpr auto l_scom_buffer_OFF = 0x0;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_OFF, 54, 1, 63 );
            }

            {
                constexpr auto l_scom_buffer_OFF = 0x0;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_OFF, 55, 1, 63 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8000002506010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8000002506010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8000002606010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8000002606010c3full)");
                break;
            }

            {
                if (l_def_IS_HW)
                {
                    constexpr auto l_scom_buffer_OFF = 0x0;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_OFF, 53, 1, 63 );
                }
                else if (l_def_IS_SIM)
                {
                    constexpr auto l_scom_buffer_ON = 0x1;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ON, 53, 1, 63 );
                }
            }

            {
                constexpr auto l_scom_buffer_OFF = 0x0;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_OFF, 54, 1, 63 );
            }

            {
                constexpr auto l_scom_buffer_OFF = 0x0;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_OFF, 55, 1, 63 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8000002606010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8000002606010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8000002706010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8000002706010c3full)");
                break;
            }

            {
                if (l_def_IS_HW)
                {
                    constexpr auto l_scom_buffer_OFF = 0x0;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_OFF, 53, 1, 63 );
                }
                else if (l_def_IS_SIM)
                {
                    constexpr auto l_scom_buffer_ON = 0x1;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ON, 53, 1, 63 );
                }
            }

            {
                constexpr auto l_scom_buffer_OFF = 0x0;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_OFF, 54, 1, 63 );
            }

            {
                constexpr auto l_scom_buffer_OFF = 0x0;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_OFF, 55, 1, 63 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8000002706010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8000002706010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8000002806010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8000002806010c3full)");
                break;
            }

            {
                if (l_def_IS_HW)
                {
                    constexpr auto l_scom_buffer_OFF = 0x0;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_OFF, 53, 1, 63 );
                }
                else if (l_def_IS_SIM)
                {
                    constexpr auto l_scom_buffer_ON = 0x1;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ON, 53, 1, 63 );
                }
            }

            {
                constexpr auto l_scom_buffer_OFF = 0x0;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_OFF, 54, 1, 63 );
            }

            {
                constexpr auto l_scom_buffer_OFF = 0x0;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_OFF, 55, 1, 63 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8000002806010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8000002806010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8000002906010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8000002906010c3full)");
                break;
            }

            {
                if (l_def_IS_HW)
                {
                    constexpr auto l_scom_buffer_OFF = 0x0;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_OFF, 53, 1, 63 );
                }
                else if (l_def_IS_SIM)
                {
                    constexpr auto l_scom_buffer_ON = 0x1;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ON, 53, 1, 63 );
                }
            }

            {
                constexpr auto l_scom_buffer_OFF = 0x0;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_OFF, 54, 1, 63 );
            }

            {
                constexpr auto l_scom_buffer_OFF = 0x0;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_OFF, 55, 1, 63 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8000002906010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8000002906010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8000002a06010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8000002a06010c3full)");
                break;
            }

            {
                if (l_def_IS_HW)
                {
                    constexpr auto l_scom_buffer_OFF = 0x0;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_OFF, 53, 1, 63 );
                }
                else if (l_def_IS_SIM)
                {
                    constexpr auto l_scom_buffer_ON = 0x1;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ON, 53, 1, 63 );
                }
            }

            {
                constexpr auto l_scom_buffer_OFF = 0x0;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_OFF, 54, 1, 63 );
            }

            {
                constexpr auto l_scom_buffer_OFF = 0x0;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_OFF, 55, 1, 63 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8000002a06010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8000002a06010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8000002b06010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8000002b06010c3full)");
                break;
            }

            {
                if (l_def_IS_HW)
                {
                    constexpr auto l_scom_buffer_OFF = 0x0;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_OFF, 53, 1, 63 );
                }
                else if (l_def_IS_SIM)
                {
                    constexpr auto l_scom_buffer_ON = 0x1;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ON, 53, 1, 63 );
                }
            }

            {
                constexpr auto l_scom_buffer_OFF = 0x0;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_OFF, 54, 1, 63 );
            }

            {
                constexpr auto l_scom_buffer_OFF = 0x0;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_OFF, 55, 1, 63 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8000002b06010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8000002b06010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8000002c06010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8000002c06010c3full)");
                break;
            }

            {
                if (l_def_IS_HW)
                {
                    constexpr auto l_scom_buffer_OFF = 0x0;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_OFF, 53, 1, 63 );
                }
                else if (l_def_IS_SIM)
                {
                    constexpr auto l_scom_buffer_ON = 0x1;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ON, 53, 1, 63 );
                }
            }

            {
                constexpr auto l_scom_buffer_OFF = 0x0;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_OFF, 54, 1, 63 );
            }

            {
                constexpr auto l_scom_buffer_OFF = 0x0;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_OFF, 55, 1, 63 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8000002c06010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8000002c06010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8000002d06010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8000002d06010c3full)");
                break;
            }

            {
                if (l_def_IS_HW)
                {
                    constexpr auto l_scom_buffer_OFF = 0x0;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_OFF, 53, 1, 63 );
                }
                else if (l_def_IS_SIM)
                {
                    constexpr auto l_scom_buffer_ON = 0x1;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ON, 53, 1, 63 );
                }
            }

            {
                constexpr auto l_scom_buffer_OFF = 0x0;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_OFF, 54, 1, 63 );
            }

            {
                constexpr auto l_scom_buffer_OFF = 0x0;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_OFF, 55, 1, 63 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8000002d06010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8000002d06010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8000002e06010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8000002e06010c3full)");
                break;
            }

            {
                if (l_def_IS_HW)
                {
                    constexpr auto l_scom_buffer_OFF = 0x0;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_OFF, 53, 1, 63 );
                }
                else if (l_def_IS_SIM)
                {
                    constexpr auto l_scom_buffer_ON = 0x1;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ON, 53, 1, 63 );
                }
            }

            {
                constexpr auto l_scom_buffer_OFF = 0x0;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_OFF, 54, 1, 63 );
            }

            {
                constexpr auto l_scom_buffer_OFF = 0x0;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_OFF, 55, 1, 63 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8000002e06010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8000002e06010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8000002f06010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8000002f06010c3full)");
                break;
            }

            {
                if (l_def_IS_HW)
                {
                    constexpr auto l_scom_buffer_OFF = 0x0;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_OFF, 53, 1, 63 );
                }
                else if (l_def_IS_SIM)
                {
                    constexpr auto l_scom_buffer_ON = 0x1;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ON, 53, 1, 63 );
                }
            }

            {
                constexpr auto l_scom_buffer_OFF = 0x0;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_OFF, 54, 1, 63 );
            }

            {
                constexpr auto l_scom_buffer_OFF = 0x0;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_OFF, 55, 1, 63 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8000002f06010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8000002f06010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8000003006010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8000003006010c3full)");
                break;
            }

            {
                if (l_def_IS_HW)
                {
                    constexpr auto l_scom_buffer_OFF = 0x0;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_OFF, 53, 1, 63 );
                }
                else if (l_def_IS_SIM)
                {
                    constexpr auto l_scom_buffer_ON = 0x1;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ON, 53, 1, 63 );
                }
            }

            {
                constexpr auto l_scom_buffer_OFF = 0x0;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_OFF, 54, 1, 63 );
            }

            {
                constexpr auto l_scom_buffer_OFF = 0x0;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_OFF, 55, 1, 63 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8000003006010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8000003006010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8000003106010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8000003106010c3full)");
                break;
            }

            {
                if (l_def_IS_HW)
                {
                    constexpr auto l_scom_buffer_OFF = 0x0;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_OFF, 53, 1, 63 );
                }
                else if (l_def_IS_SIM)
                {
                    constexpr auto l_scom_buffer_ON = 0x1;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ON, 53, 1, 63 );
                }
            }

            {
                constexpr auto l_scom_buffer_OFF = 0x0;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_OFF, 54, 1, 63 );
            }

            {
                constexpr auto l_scom_buffer_OFF = 0x0;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_OFF, 55, 1, 63 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8000003106010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8000003106010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8000082006010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8000082006010c3full)");
                break;
            }

            {
                constexpr auto l_scom_buffer_OFF = 0x0;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_OFF, 54, 1, 63 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8000082006010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8000082006010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8000082106010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8000082106010c3full)");
                break;
            }

            {
                constexpr auto l_scom_buffer_OFF = 0x0;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_OFF, 54, 1, 63 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8000082106010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8000082106010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8000082206010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8000082206010c3full)");
                break;
            }

            {
                constexpr auto l_scom_buffer_OFF = 0x0;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_OFF, 54, 1, 63 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8000082206010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8000082206010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8000082306010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8000082306010c3full)");
                break;
            }

            {
                constexpr auto l_scom_buffer_OFF = 0x0;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_OFF, 54, 1, 63 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8000082306010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8000082306010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8000082406010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8000082406010c3full)");
                break;
            }

            {
                constexpr auto l_scom_buffer_OFF = 0x0;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_OFF, 54, 1, 63 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8000082406010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8000082406010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8000082506010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8000082506010c3full)");
                break;
            }

            {
                constexpr auto l_scom_buffer_OFF = 0x0;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_OFF, 54, 1, 63 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8000082506010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8000082506010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8000082606010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8000082606010c3full)");
                break;
            }

            {
                constexpr auto l_scom_buffer_OFF = 0x0;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_OFF, 54, 1, 63 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8000082606010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8000082606010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8000082706010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8000082706010c3full)");
                break;
            }

            {
                constexpr auto l_scom_buffer_OFF = 0x0;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_OFF, 54, 1, 63 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8000082706010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8000082706010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8000082806010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8000082806010c3full)");
                break;
            }

            {
                constexpr auto l_scom_buffer_OFF = 0x0;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_OFF, 54, 1, 63 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8000082806010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8000082806010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8000082906010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8000082906010c3full)");
                break;
            }

            {
                constexpr auto l_scom_buffer_OFF = 0x0;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_OFF, 54, 1, 63 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8000082906010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8000082906010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8000082a06010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8000082a06010c3full)");
                break;
            }

            {
                constexpr auto l_scom_buffer_OFF = 0x0;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_OFF, 54, 1, 63 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8000082a06010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8000082a06010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8000082b06010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8000082b06010c3full)");
                break;
            }

            {
                constexpr auto l_scom_buffer_OFF = 0x0;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_OFF, 54, 1, 63 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8000082b06010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8000082b06010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8000082c06010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8000082c06010c3full)");
                break;
            }

            {
                constexpr auto l_scom_buffer_OFF = 0x0;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_OFF, 54, 1, 63 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8000082c06010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8000082c06010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8000082d06010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8000082d06010c3full)");
                break;
            }

            {
                constexpr auto l_scom_buffer_OFF = 0x0;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_OFF, 54, 1, 63 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8000082d06010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8000082d06010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8000082e06010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8000082e06010c3full)");
                break;
            }

            {
                constexpr auto l_scom_buffer_OFF = 0x0;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_OFF, 54, 1, 63 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8000082e06010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8000082e06010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8000082f06010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8000082f06010c3full)");
                break;
            }

            {
                constexpr auto l_scom_buffer_OFF = 0x0;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_OFF, 54, 1, 63 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8000082f06010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8000082f06010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8000083006010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8000083006010c3full)");
                break;
            }

            {
                constexpr auto l_scom_buffer_OFF = 0x0;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_OFF, 54, 1, 63 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8000083006010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8000083006010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8000083106010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8000083106010c3full)");
                break;
            }

            {
                constexpr auto l_scom_buffer_ON = 0x1;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_ON, 54, 1, 63 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8000083106010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8000083106010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8000282006010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8000282006010c3full)");
                break;
            }

            {
                if (l_def_IS_HW)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0000, 48, 4, 60 );
                }
                else if (l_def_IS_SIM)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0110, 48, 4, 60 );
                }
            }

            {
                if (l_def_IS_HW)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b00000, 52, 5, 59 );
                }
                else if (l_def_IS_SIM)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b01111, 52, 5, 59 );
                }
            }

            {
                if (l_def_IS_HW)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b00000, 57, 5, 59 );
                }
                else if (l_def_IS_SIM)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b01111, 57, 5, 59 );
                }
            }

            l_rc = fapi2::putScom(TGT0, 0x8000282006010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8000282006010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8000282106010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8000282106010c3full)");
                break;
            }

            {
                if (l_def_IS_HW)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0000, 48, 4, 60 );
                }
                else if (l_def_IS_SIM)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0110, 48, 4, 60 );
                }
            }

            {
                if (l_def_IS_HW)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b00000, 52, 5, 59 );
                }
                else if (l_def_IS_SIM)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b01111, 52, 5, 59 );
                }
            }

            {
                if (l_def_IS_HW)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b00000, 57, 5, 59 );
                }
                else if (l_def_IS_SIM)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b01111, 57, 5, 59 );
                }
            }

            l_rc = fapi2::putScom(TGT0, 0x8000282106010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8000282106010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8000282206010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8000282206010c3full)");
                break;
            }

            {
                if (l_def_IS_HW)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0000, 48, 4, 60 );
                }
                else if (l_def_IS_SIM)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0110, 48, 4, 60 );
                }
            }

            {
                if (l_def_IS_HW)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b00000, 52, 5, 59 );
                }
                else if (l_def_IS_SIM)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b01111, 52, 5, 59 );
                }
            }

            {
                if (l_def_IS_HW)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b00000, 57, 5, 59 );
                }
                else if (l_def_IS_SIM)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b01111, 57, 5, 59 );
                }
            }

            l_rc = fapi2::putScom(TGT0, 0x8000282206010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8000282206010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8000282306010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8000282306010c3full)");
                break;
            }

            {
                if (l_def_IS_HW)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0000, 48, 4, 60 );
                }
                else if (l_def_IS_SIM)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0110, 48, 4, 60 );
                }
            }

            {
                if (l_def_IS_HW)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b00000, 52, 5, 59 );
                }
                else if (l_def_IS_SIM)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b01111, 52, 5, 59 );
                }
            }

            {
                if (l_def_IS_HW)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b00000, 57, 5, 59 );
                }
                else if (l_def_IS_SIM)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b01111, 57, 5, 59 );
                }
            }

            l_rc = fapi2::putScom(TGT0, 0x8000282306010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8000282306010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8000282406010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8000282406010c3full)");
                break;
            }

            {
                if (l_def_IS_HW)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0000, 48, 4, 60 );
                }
                else if (l_def_IS_SIM)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0110, 48, 4, 60 );
                }
            }

            {
                if (l_def_IS_HW)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b00000, 52, 5, 59 );
                }
                else if (l_def_IS_SIM)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b01111, 52, 5, 59 );
                }
            }

            {
                if (l_def_IS_HW)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b00000, 57, 5, 59 );
                }
                else if (l_def_IS_SIM)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b01111, 57, 5, 59 );
                }
            }

            l_rc = fapi2::putScom(TGT0, 0x8000282406010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8000282406010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8000282506010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8000282506010c3full)");
                break;
            }

            {
                if (l_def_IS_HW)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0000, 48, 4, 60 );
                }
                else if (l_def_IS_SIM)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0110, 48, 4, 60 );
                }
            }

            {
                if (l_def_IS_HW)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b00000, 52, 5, 59 );
                }
                else if (l_def_IS_SIM)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b01111, 52, 5, 59 );
                }
            }

            {
                if (l_def_IS_HW)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b00000, 57, 5, 59 );
                }
                else if (l_def_IS_SIM)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b01111, 57, 5, 59 );
                }
            }

            l_rc = fapi2::putScom(TGT0, 0x8000282506010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8000282506010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8000282606010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8000282606010c3full)");
                break;
            }

            {
                if (l_def_IS_HW)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0000, 48, 4, 60 );
                }
                else if (l_def_IS_SIM)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0110, 48, 4, 60 );
                }
            }

            {
                if (l_def_IS_HW)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b00000, 52, 5, 59 );
                }
                else if (l_def_IS_SIM)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b01111, 52, 5, 59 );
                }
            }

            {
                if (l_def_IS_HW)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b00000, 57, 5, 59 );
                }
                else if (l_def_IS_SIM)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b01111, 57, 5, 59 );
                }
            }

            l_rc = fapi2::putScom(TGT0, 0x8000282606010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8000282606010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8000282706010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8000282706010c3full)");
                break;
            }

            {
                if (l_def_IS_HW)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0000, 48, 4, 60 );
                }
                else if (l_def_IS_SIM)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0110, 48, 4, 60 );
                }
            }

            {
                if (l_def_IS_HW)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b00000, 52, 5, 59 );
                }
                else if (l_def_IS_SIM)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b01111, 52, 5, 59 );
                }
            }

            {
                if (l_def_IS_HW)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b00000, 57, 5, 59 );
                }
                else if (l_def_IS_SIM)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b01111, 57, 5, 59 );
                }
            }

            l_rc = fapi2::putScom(TGT0, 0x8000282706010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8000282706010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8000282806010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8000282806010c3full)");
                break;
            }

            {
                if (l_def_IS_HW)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0000, 48, 4, 60 );
                }
                else if (l_def_IS_SIM)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0110, 48, 4, 60 );
                }
            }

            {
                if (l_def_IS_HW)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b00000, 52, 5, 59 );
                }
                else if (l_def_IS_SIM)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b01111, 52, 5, 59 );
                }
            }

            {
                if (l_def_IS_HW)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b00000, 57, 5, 59 );
                }
                else if (l_def_IS_SIM)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b01111, 57, 5, 59 );
                }
            }

            l_rc = fapi2::putScom(TGT0, 0x8000282806010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8000282806010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8000282906010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8000282906010c3full)");
                break;
            }

            {
                if (l_def_IS_HW)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0000, 48, 4, 60 );
                }
                else if (l_def_IS_SIM)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0110, 48, 4, 60 );
                }
            }

            {
                if (l_def_IS_HW)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b00000, 52, 5, 59 );
                }
                else if (l_def_IS_SIM)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b01111, 52, 5, 59 );
                }
            }

            {
                if (l_def_IS_HW)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b00000, 57, 5, 59 );
                }
                else if (l_def_IS_SIM)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b01111, 57, 5, 59 );
                }
            }

            l_rc = fapi2::putScom(TGT0, 0x8000282906010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8000282906010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8000282a06010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8000282a06010c3full)");
                break;
            }

            {
                if (l_def_IS_HW)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0000, 48, 4, 60 );
                }
                else if (l_def_IS_SIM)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0110, 48, 4, 60 );
                }
            }

            {
                if (l_def_IS_HW)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b00000, 52, 5, 59 );
                }
                else if (l_def_IS_SIM)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b01111, 52, 5, 59 );
                }
            }

            {
                if (l_def_IS_HW)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b00000, 57, 5, 59 );
                }
                else if (l_def_IS_SIM)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b01111, 57, 5, 59 );
                }
            }

            l_rc = fapi2::putScom(TGT0, 0x8000282a06010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8000282a06010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8000282b06010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8000282b06010c3full)");
                break;
            }

            {
                if (l_def_IS_HW)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0000, 48, 4, 60 );
                }
                else if (l_def_IS_SIM)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0110, 48, 4, 60 );
                }
            }

            {
                if (l_def_IS_HW)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b00000, 52, 5, 59 );
                }
                else if (l_def_IS_SIM)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b01111, 52, 5, 59 );
                }
            }

            {
                if (l_def_IS_HW)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b00000, 57, 5, 59 );
                }
                else if (l_def_IS_SIM)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b01111, 57, 5, 59 );
                }
            }

            l_rc = fapi2::putScom(TGT0, 0x8000282b06010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8000282b06010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8000282c06010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8000282c06010c3full)");
                break;
            }

            {
                if (l_def_IS_HW)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0000, 48, 4, 60 );
                }
                else if (l_def_IS_SIM)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0110, 48, 4, 60 );
                }
            }

            {
                if (l_def_IS_HW)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b00000, 52, 5, 59 );
                }
                else if (l_def_IS_SIM)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b01111, 52, 5, 59 );
                }
            }

            {
                if (l_def_IS_HW)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b00000, 57, 5, 59 );
                }
                else if (l_def_IS_SIM)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b01111, 57, 5, 59 );
                }
            }

            l_rc = fapi2::putScom(TGT0, 0x8000282c06010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8000282c06010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8000282d06010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8000282d06010c3full)");
                break;
            }

            {
                if (l_def_IS_HW)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0000, 48, 4, 60 );
                }
                else if (l_def_IS_SIM)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0110, 48, 4, 60 );
                }
            }

            {
                if (l_def_IS_HW)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b00000, 52, 5, 59 );
                }
                else if (l_def_IS_SIM)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b01111, 52, 5, 59 );
                }
            }

            {
                if (l_def_IS_HW)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b00000, 57, 5, 59 );
                }
                else if (l_def_IS_SIM)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b01111, 57, 5, 59 );
                }
            }

            l_rc = fapi2::putScom(TGT0, 0x8000282d06010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8000282d06010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8000282e06010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8000282e06010c3full)");
                break;
            }

            {
                if (l_def_IS_HW)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0000, 48, 4, 60 );
                }
                else if (l_def_IS_SIM)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0110, 48, 4, 60 );
                }
            }

            {
                if (l_def_IS_HW)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b00000, 52, 5, 59 );
                }
                else if (l_def_IS_SIM)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b01111, 52, 5, 59 );
                }
            }

            {
                if (l_def_IS_HW)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b00000, 57, 5, 59 );
                }
                else if (l_def_IS_SIM)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b01111, 57, 5, 59 );
                }
            }

            l_rc = fapi2::putScom(TGT0, 0x8000282e06010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8000282e06010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8000282f06010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8000282f06010c3full)");
                break;
            }

            {
                if (l_def_IS_HW)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0000, 48, 4, 60 );
                }
                else if (l_def_IS_SIM)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0110, 48, 4, 60 );
                }
            }

            {
                if (l_def_IS_HW)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b00000, 52, 5, 59 );
                }
                else if (l_def_IS_SIM)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b01111, 52, 5, 59 );
                }
            }

            {
                if (l_def_IS_HW)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b00000, 57, 5, 59 );
                }
                else if (l_def_IS_SIM)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b01111, 57, 5, 59 );
                }
            }

            l_rc = fapi2::putScom(TGT0, 0x8000282f06010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8000282f06010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8000283006010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8000283006010c3full)");
                break;
            }

            {
                if (l_def_IS_HW)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0000, 48, 4, 60 );
                }
                else if (l_def_IS_SIM)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0110, 48, 4, 60 );
                }
            }

            {
                if (l_def_IS_HW)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b00000, 52, 5, 59 );
                }
                else if (l_def_IS_SIM)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b01111, 52, 5, 59 );
                }
            }

            {
                if (l_def_IS_HW)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b00000, 57, 5, 59 );
                }
                else if (l_def_IS_SIM)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b01111, 57, 5, 59 );
                }
            }

            l_rc = fapi2::putScom(TGT0, 0x8000283006010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8000283006010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8000283106010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8000283106010c3full)");
                break;
            }

            {
                if (l_def_IS_HW)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0000, 48, 4, 60 );
                }
                else if (l_def_IS_SIM)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0110, 48, 4, 60 );
                }
            }

            {
                if (l_def_IS_HW)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b00000, 52, 5, 59 );
                }
                else if (l_def_IS_SIM)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b01111, 52, 5, 59 );
                }
            }

            {
                if (l_def_IS_HW)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b00000, 57, 5, 59 );
                }
                else if (l_def_IS_SIM)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b01111, 57, 5, 59 );
                }
            }

            l_rc = fapi2::putScom(TGT0, 0x8000283106010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8000283106010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8000302006010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8000302006010c3full)");
                break;
            }

            {
                if (l_def_IS_HW)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b00000, 48, 5, 59 );
                }
                else if (l_def_IS_SIM)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b01100, 48, 5, 59 );
                }
            }

            {
                if (l_def_IS_HW)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0000, 53, 4, 60 );
                }
                else if (l_def_IS_SIM)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b1011, 53, 4, 60 );
                }
            }

            l_rc = fapi2::putScom(TGT0, 0x8000302006010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8000302006010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8000302106010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8000302106010c3full)");
                break;
            }

            {
                if (l_def_IS_HW)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b00000, 48, 5, 59 );
                }
                else if (l_def_IS_SIM)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b01100, 48, 5, 59 );
                }
            }

            {
                if (l_def_IS_HW)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0000, 53, 4, 60 );
                }
                else if (l_def_IS_SIM)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b1011, 53, 4, 60 );
                }
            }

            l_rc = fapi2::putScom(TGT0, 0x8000302106010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8000302106010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8000302206010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8000302206010c3full)");
                break;
            }

            {
                if (l_def_IS_HW)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b00000, 48, 5, 59 );
                }
                else if (l_def_IS_SIM)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b01100, 48, 5, 59 );
                }
            }

            {
                if (l_def_IS_HW)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0000, 53, 4, 60 );
                }
                else if (l_def_IS_SIM)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b1011, 53, 4, 60 );
                }
            }

            l_rc = fapi2::putScom(TGT0, 0x8000302206010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8000302206010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8000302306010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8000302306010c3full)");
                break;
            }

            {
                if (l_def_IS_HW)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b00000, 48, 5, 59 );
                }
                else if (l_def_IS_SIM)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b01100, 48, 5, 59 );
                }
            }

            {
                if (l_def_IS_HW)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0000, 53, 4, 60 );
                }
                else if (l_def_IS_SIM)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b1011, 53, 4, 60 );
                }
            }

            l_rc = fapi2::putScom(TGT0, 0x8000302306010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8000302306010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8000302406010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8000302406010c3full)");
                break;
            }

            {
                if (l_def_IS_HW)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b00000, 48, 5, 59 );
                }
                else if (l_def_IS_SIM)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b01100, 48, 5, 59 );
                }
            }

            {
                if (l_def_IS_HW)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0000, 53, 4, 60 );
                }
                else if (l_def_IS_SIM)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b1011, 53, 4, 60 );
                }
            }

            l_rc = fapi2::putScom(TGT0, 0x8000302406010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8000302406010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8000302506010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8000302506010c3full)");
                break;
            }

            {
                if (l_def_IS_HW)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b00000, 48, 5, 59 );
                }
                else if (l_def_IS_SIM)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b01100, 48, 5, 59 );
                }
            }

            {
                if (l_def_IS_HW)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0000, 53, 4, 60 );
                }
                else if (l_def_IS_SIM)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b1011, 53, 4, 60 );
                }
            }

            l_rc = fapi2::putScom(TGT0, 0x8000302506010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8000302506010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8000302606010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8000302606010c3full)");
                break;
            }

            {
                if (l_def_IS_HW)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b00000, 48, 5, 59 );
                }
                else if (l_def_IS_SIM)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b01100, 48, 5, 59 );
                }
            }

            {
                if (l_def_IS_HW)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0000, 53, 4, 60 );
                }
                else if (l_def_IS_SIM)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b1011, 53, 4, 60 );
                }
            }

            l_rc = fapi2::putScom(TGT0, 0x8000302606010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8000302606010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8000302706010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8000302706010c3full)");
                break;
            }

            {
                if (l_def_IS_HW)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b00000, 48, 5, 59 );
                }
                else if (l_def_IS_SIM)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b01100, 48, 5, 59 );
                }
            }

            {
                if (l_def_IS_HW)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0000, 53, 4, 60 );
                }
                else if (l_def_IS_SIM)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b1011, 53, 4, 60 );
                }
            }

            l_rc = fapi2::putScom(TGT0, 0x8000302706010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8000302706010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8000302806010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8000302806010c3full)");
                break;
            }

            {
                if (l_def_IS_HW)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b00000, 48, 5, 59 );
                }
                else if (l_def_IS_SIM)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b01100, 48, 5, 59 );
                }
            }

            {
                if (l_def_IS_HW)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0000, 53, 4, 60 );
                }
                else if (l_def_IS_SIM)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b1011, 53, 4, 60 );
                }
            }

            l_rc = fapi2::putScom(TGT0, 0x8000302806010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8000302806010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8000302906010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8000302906010c3full)");
                break;
            }

            {
                if (l_def_IS_HW)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b00000, 48, 5, 59 );
                }
                else if (l_def_IS_SIM)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b01100, 48, 5, 59 );
                }
            }

            {
                if (l_def_IS_HW)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0000, 53, 4, 60 );
                }
                else if (l_def_IS_SIM)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b1011, 53, 4, 60 );
                }
            }

            l_rc = fapi2::putScom(TGT0, 0x8000302906010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8000302906010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8000302a06010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8000302a06010c3full)");
                break;
            }

            {
                if (l_def_IS_HW)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b00000, 48, 5, 59 );
                }
                else if (l_def_IS_SIM)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b01100, 48, 5, 59 );
                }
            }

            {
                if (l_def_IS_HW)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0000, 53, 4, 60 );
                }
                else if (l_def_IS_SIM)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b1011, 53, 4, 60 );
                }
            }

            l_rc = fapi2::putScom(TGT0, 0x8000302a06010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8000302a06010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8000302b06010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8000302b06010c3full)");
                break;
            }

            {
                if (l_def_IS_HW)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b00000, 48, 5, 59 );
                }
                else if (l_def_IS_SIM)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b01100, 48, 5, 59 );
                }
            }

            {
                if (l_def_IS_HW)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0000, 53, 4, 60 );
                }
                else if (l_def_IS_SIM)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b1011, 53, 4, 60 );
                }
            }

            l_rc = fapi2::putScom(TGT0, 0x8000302b06010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8000302b06010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8000302c06010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8000302c06010c3full)");
                break;
            }

            {
                if (l_def_IS_HW)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b00000, 48, 5, 59 );
                }
                else if (l_def_IS_SIM)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b01100, 48, 5, 59 );
                }
            }

            {
                if (l_def_IS_HW)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0000, 53, 4, 60 );
                }
                else if (l_def_IS_SIM)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b1011, 53, 4, 60 );
                }
            }

            l_rc = fapi2::putScom(TGT0, 0x8000302c06010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8000302c06010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8000302d06010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8000302d06010c3full)");
                break;
            }

            {
                if (l_def_IS_HW)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b00000, 48, 5, 59 );
                }
                else if (l_def_IS_SIM)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b01100, 48, 5, 59 );
                }
            }

            {
                if (l_def_IS_HW)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0000, 53, 4, 60 );
                }
                else if (l_def_IS_SIM)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b1011, 53, 4, 60 );
                }
            }

            l_rc = fapi2::putScom(TGT0, 0x8000302d06010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8000302d06010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8000302e06010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8000302e06010c3full)");
                break;
            }

            {
                if (l_def_IS_HW)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b00000, 48, 5, 59 );
                }
                else if (l_def_IS_SIM)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b01100, 48, 5, 59 );
                }
            }

            {
                if (l_def_IS_HW)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0000, 53, 4, 60 );
                }
                else if (l_def_IS_SIM)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b1011, 53, 4, 60 );
                }
            }

            l_rc = fapi2::putScom(TGT0, 0x8000302e06010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8000302e06010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8000302f06010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8000302f06010c3full)");
                break;
            }

            {
                if (l_def_IS_HW)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b00000, 48, 5, 59 );
                }
                else if (l_def_IS_SIM)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b01100, 48, 5, 59 );
                }
            }

            {
                if (l_def_IS_HW)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0000, 53, 4, 60 );
                }
                else if (l_def_IS_SIM)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b1011, 53, 4, 60 );
                }
            }

            l_rc = fapi2::putScom(TGT0, 0x8000302f06010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8000302f06010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8000303006010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8000303006010c3full)");
                break;
            }

            {
                if (l_def_IS_HW)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b00000, 48, 5, 59 );
                }
                else if (l_def_IS_SIM)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b01100, 48, 5, 59 );
                }
            }

            {
                if (l_def_IS_HW)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0000, 53, 4, 60 );
                }
                else if (l_def_IS_SIM)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b1011, 53, 4, 60 );
                }
            }

            l_rc = fapi2::putScom(TGT0, 0x8000303006010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8000303006010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8000303106010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8000303106010c3full)");
                break;
            }

            {
                if (l_def_IS_HW)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b00000, 48, 5, 59 );
                }
                else if (l_def_IS_SIM)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b01100, 48, 5, 59 );
                }
            }

            {
                if (l_def_IS_HW)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0000, 53, 4, 60 );
                }
                else if (l_def_IS_SIM)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b1011, 53, 4, 60 );
                }
            }

            l_rc = fapi2::putScom(TGT0, 0x8000303106010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8000303106010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8000c02006010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8000c02006010c3full)");
                break;
            }

            {
                if (l_def_IS_HW)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0000000, 48, 7, 57 );
                }
                else if (l_def_IS_SIM)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0000011, 48, 7, 57 );
                }
            }

            {
                if (l_def_IS_HW)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b000000, 55, 6, 58 );
                }
                else if (l_def_IS_SIM)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b100111, 55, 6, 58 );
                }
            }

            l_rc = fapi2::putScom(TGT0, 0x8000c02006010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8000c02006010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8000c02106010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8000c02106010c3full)");
                break;
            }

            {
                if (l_def_IS_HW)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0000000, 48, 7, 57 );
                }
                else if (l_def_IS_SIM)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0000011, 48, 7, 57 );
                }
            }

            {
                if (l_def_IS_HW)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b000000, 55, 6, 58 );
                }
                else if (l_def_IS_SIM)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b100111, 55, 6, 58 );
                }
            }

            l_rc = fapi2::putScom(TGT0, 0x8000c02106010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8000c02106010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8000c02206010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8000c02206010c3full)");
                break;
            }

            {
                if (l_def_IS_HW)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0000000, 48, 7, 57 );
                }
                else if (l_def_IS_SIM)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0000011, 48, 7, 57 );
                }
            }

            {
                if (l_def_IS_HW)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b000000, 55, 6, 58 );
                }
                else if (l_def_IS_SIM)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b100111, 55, 6, 58 );
                }
            }

            l_rc = fapi2::putScom(TGT0, 0x8000c02206010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8000c02206010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8000c02306010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8000c02306010c3full)");
                break;
            }

            {
                if (l_def_IS_HW)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0000000, 48, 7, 57 );
                }
                else if (l_def_IS_SIM)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0000011, 48, 7, 57 );
                }
            }

            {
                if (l_def_IS_HW)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b000000, 55, 6, 58 );
                }
                else if (l_def_IS_SIM)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b100111, 55, 6, 58 );
                }
            }

            l_rc = fapi2::putScom(TGT0, 0x8000c02306010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8000c02306010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8000c02406010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8000c02406010c3full)");
                break;
            }

            {
                if (l_def_IS_HW)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0000000, 48, 7, 57 );
                }
                else if (l_def_IS_SIM)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0000011, 48, 7, 57 );
                }
            }

            {
                if (l_def_IS_HW)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b000000, 55, 6, 58 );
                }
                else if (l_def_IS_SIM)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b100111, 55, 6, 58 );
                }
            }

            l_rc = fapi2::putScom(TGT0, 0x8000c02406010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8000c02406010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8000c02506010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8000c02506010c3full)");
                break;
            }

            {
                if (l_def_IS_HW)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0000000, 48, 7, 57 );
                }
                else if (l_def_IS_SIM)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0000011, 48, 7, 57 );
                }
            }

            {
                if (l_def_IS_HW)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b000000, 55, 6, 58 );
                }
                else if (l_def_IS_SIM)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b100111, 55, 6, 58 );
                }
            }

            l_rc = fapi2::putScom(TGT0, 0x8000c02506010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8000c02506010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8000c02606010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8000c02606010c3full)");
                break;
            }

            {
                if (l_def_IS_HW)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0000000, 48, 7, 57 );
                }
                else if (l_def_IS_SIM)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0000011, 48, 7, 57 );
                }
            }

            {
                if (l_def_IS_HW)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b000000, 55, 6, 58 );
                }
                else if (l_def_IS_SIM)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b100111, 55, 6, 58 );
                }
            }

            l_rc = fapi2::putScom(TGT0, 0x8000c02606010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8000c02606010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8000c02706010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8000c02706010c3full)");
                break;
            }

            {
                if (l_def_IS_HW)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0000000, 48, 7, 57 );
                }
                else if (l_def_IS_SIM)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0000011, 48, 7, 57 );
                }
            }

            {
                if (l_def_IS_HW)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b000000, 55, 6, 58 );
                }
                else if (l_def_IS_SIM)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b100111, 55, 6, 58 );
                }
            }

            l_rc = fapi2::putScom(TGT0, 0x8000c02706010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8000c02706010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8000c02806010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8000c02806010c3full)");
                break;
            }

            {
                if (l_def_IS_HW)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0000000, 48, 7, 57 );
                }
                else if (l_def_IS_SIM)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0000011, 48, 7, 57 );
                }
            }

            {
                if (l_def_IS_HW)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b000000, 55, 6, 58 );
                }
                else if (l_def_IS_SIM)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b100111, 55, 6, 58 );
                }
            }

            l_rc = fapi2::putScom(TGT0, 0x8000c02806010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8000c02806010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8000c02906010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8000c02906010c3full)");
                break;
            }

            {
                if (l_def_IS_HW)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0000000, 48, 7, 57 );
                }
                else if (l_def_IS_SIM)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0000011, 48, 7, 57 );
                }
            }

            {
                if (l_def_IS_HW)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b000000, 55, 6, 58 );
                }
                else if (l_def_IS_SIM)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b100111, 55, 6, 58 );
                }
            }

            l_rc = fapi2::putScom(TGT0, 0x8000c02906010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8000c02906010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8000c02a06010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8000c02a06010c3full)");
                break;
            }

            {
                if (l_def_IS_HW)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0000000, 48, 7, 57 );
                }
                else if (l_def_IS_SIM)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0000011, 48, 7, 57 );
                }
            }

            {
                if (l_def_IS_HW)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b000000, 55, 6, 58 );
                }
                else if (l_def_IS_SIM)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b100111, 55, 6, 58 );
                }
            }

            l_rc = fapi2::putScom(TGT0, 0x8000c02a06010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8000c02a06010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8000c02b06010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8000c02b06010c3full)");
                break;
            }

            {
                if (l_def_IS_HW)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0000000, 48, 7, 57 );
                }
                else if (l_def_IS_SIM)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0000011, 48, 7, 57 );
                }
            }

            {
                if (l_def_IS_HW)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b000000, 55, 6, 58 );
                }
                else if (l_def_IS_SIM)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b100111, 55, 6, 58 );
                }
            }

            l_rc = fapi2::putScom(TGT0, 0x8000c02b06010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8000c02b06010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8000c02c06010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8000c02c06010c3full)");
                break;
            }

            {
                if (l_def_IS_HW)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0000000, 48, 7, 57 );
                }
                else if (l_def_IS_SIM)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0000011, 48, 7, 57 );
                }
            }

            {
                if (l_def_IS_HW)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b000000, 55, 6, 58 );
                }
                else if (l_def_IS_SIM)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b100111, 55, 6, 58 );
                }
            }

            l_rc = fapi2::putScom(TGT0, 0x8000c02c06010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8000c02c06010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8000c02d06010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8000c02d06010c3full)");
                break;
            }

            {
                if (l_def_IS_HW)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0000000, 48, 7, 57 );
                }
                else if (l_def_IS_SIM)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0000011, 48, 7, 57 );
                }
            }

            {
                if (l_def_IS_HW)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b000000, 55, 6, 58 );
                }
                else if (l_def_IS_SIM)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b100111, 55, 6, 58 );
                }
            }

            l_rc = fapi2::putScom(TGT0, 0x8000c02d06010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8000c02d06010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8000c02e06010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8000c02e06010c3full)");
                break;
            }

            {
                if (l_def_IS_HW)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0000000, 48, 7, 57 );
                }
                else if (l_def_IS_SIM)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0000011, 48, 7, 57 );
                }
            }

            {
                if (l_def_IS_HW)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b000000, 55, 6, 58 );
                }
                else if (l_def_IS_SIM)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b100111, 55, 6, 58 );
                }
            }

            l_rc = fapi2::putScom(TGT0, 0x8000c02e06010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8000c02e06010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8000c02f06010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8000c02f06010c3full)");
                break;
            }

            {
                if (l_def_IS_HW)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0000000, 48, 7, 57 );
                }
                else if (l_def_IS_SIM)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0000011, 48, 7, 57 );
                }
            }

            {
                if (l_def_IS_HW)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b000000, 55, 6, 58 );
                }
                else if (l_def_IS_SIM)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b100111, 55, 6, 58 );
                }
            }

            l_rc = fapi2::putScom(TGT0, 0x8000c02f06010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8000c02f06010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8000c03006010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8000c03006010c3full)");
                break;
            }

            {
                if (l_def_IS_HW)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0000000, 48, 7, 57 );
                }
                else if (l_def_IS_SIM)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0000011, 48, 7, 57 );
                }
            }

            {
                if (l_def_IS_HW)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b000000, 55, 6, 58 );
                }
                else if (l_def_IS_SIM)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b100111, 55, 6, 58 );
                }
            }

            l_rc = fapi2::putScom(TGT0, 0x8000c03006010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8000c03006010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8000c03106010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8000c03106010c3full)");
                break;
            }

            {
                if (l_def_IS_HW)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0000000, 48, 7, 57 );
                }
                else if (l_def_IS_SIM)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0000011, 48, 7, 57 );
                }
            }

            {
                if (l_def_IS_HW)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b000000, 55, 6, 58 );
                }
                else if (l_def_IS_SIM)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b100111, 55, 6, 58 );
                }
            }

            l_rc = fapi2::putScom(TGT0, 0x8000c03106010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8000c03106010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8002202006010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8002202006010c3full)");
                break;
            }

            {
                constexpr auto l_scom_buffer_OFF = 0x0;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_OFF, 48, 1, 63 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8002202006010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8002202006010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8002202106010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8002202106010c3full)");
                break;
            }

            {
                constexpr auto l_scom_buffer_OFF = 0x0;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_OFF, 48, 1, 63 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8002202106010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8002202106010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8002202206010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8002202206010c3full)");
                break;
            }

            {
                constexpr auto l_scom_buffer_OFF = 0x0;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_OFF, 48, 1, 63 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8002202206010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8002202206010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8002202306010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8002202306010c3full)");
                break;
            }

            {
                constexpr auto l_scom_buffer_OFF = 0x0;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_OFF, 48, 1, 63 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8002202306010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8002202306010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8002202406010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8002202406010c3full)");
                break;
            }

            {
                constexpr auto l_scom_buffer_OFF = 0x0;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_OFF, 48, 1, 63 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8002202406010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8002202406010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8002202506010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8002202506010c3full)");
                break;
            }

            {
                constexpr auto l_scom_buffer_OFF = 0x0;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_OFF, 48, 1, 63 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8002202506010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8002202506010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8002202606010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8002202606010c3full)");
                break;
            }

            {
                constexpr auto l_scom_buffer_OFF = 0x0;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_OFF, 48, 1, 63 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8002202606010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8002202606010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8002202706010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8002202706010c3full)");
                break;
            }

            {
                constexpr auto l_scom_buffer_OFF = 0x0;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_OFF, 48, 1, 63 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8002202706010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8002202706010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8002202806010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8002202806010c3full)");
                break;
            }

            {
                constexpr auto l_scom_buffer_OFF = 0x0;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_OFF, 48, 1, 63 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8002202806010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8002202806010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8002202906010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8002202906010c3full)");
                break;
            }

            {
                constexpr auto l_scom_buffer_OFF = 0x0;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_OFF, 48, 1, 63 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8002202906010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8002202906010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8002202a06010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8002202a06010c3full)");
                break;
            }

            {
                constexpr auto l_scom_buffer_OFF = 0x0;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_OFF, 48, 1, 63 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8002202a06010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8002202a06010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8002202b06010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8002202b06010c3full)");
                break;
            }

            {
                constexpr auto l_scom_buffer_OFF = 0x0;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_OFF, 48, 1, 63 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8002202b06010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8002202b06010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8002202c06010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8002202c06010c3full)");
                break;
            }

            {
                constexpr auto l_scom_buffer_OFF = 0x0;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_OFF, 48, 1, 63 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8002202c06010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8002202c06010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8002202d06010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8002202d06010c3full)");
                break;
            }

            {
                constexpr auto l_scom_buffer_OFF = 0x0;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_OFF, 48, 1, 63 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8002202d06010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8002202d06010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8002202e06010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8002202e06010c3full)");
                break;
            }

            {
                constexpr auto l_scom_buffer_OFF = 0x0;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_OFF, 48, 1, 63 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8002202e06010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8002202e06010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8002202f06010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8002202f06010c3full)");
                break;
            }

            {
                constexpr auto l_scom_buffer_OFF = 0x0;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_OFF, 48, 1, 63 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8002202f06010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8002202f06010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8002203006010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8002203006010c3full)");
                break;
            }

            {
                constexpr auto l_scom_buffer_OFF = 0x0;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_OFF, 48, 1, 63 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8002203006010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8002203006010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8002203106010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8002203106010c3full)");
                break;
            }

            {
                constexpr auto l_scom_buffer_ON = 0x1;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_ON, 48, 1, 63 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8002203106010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8002203106010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8002c02006010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8002c02006010c3full)");
                break;
            }

            {
                constexpr auto l_scom_buffer_PATTERN_24_A_0_15 = 0x1000;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_PATTERN_24_A_0_15, 48, 16, 48 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8002c02006010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8002c02006010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8002c02106010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8002c02106010c3full)");
                break;
            }

            {
                constexpr auto l_scom_buffer_PATTERN_24_B_0_15 = 0xf03e;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_PATTERN_24_B_0_15, 48, 16, 48 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8002c02106010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8002c02106010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8002c02206010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8002c02206010c3full)");
                break;
            }

            {
                constexpr auto l_scom_buffer_PATTERN_24_C_0_15 = 0x7bc;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_PATTERN_24_C_0_15, 48, 16, 48 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8002c02206010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8002c02206010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8002c02306010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8002c02306010c3full)");
                break;
            }

            {
                constexpr auto l_scom_buffer_PATTERN_24_D_0_15 = 0x7c7;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_PATTERN_24_D_0_15, 48, 16, 48 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8002c02306010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8002c02306010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8002c02406010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8002c02406010c3full)");
                break;
            }

            {
                constexpr auto l_scom_buffer_PATTERN_24_E_0_15 = 0x3ef;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_PATTERN_24_E_0_15, 48, 16, 48 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8002c02406010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8002c02406010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8002c02506010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8002c02506010c3full)");
                break;
            }

            {
                constexpr auto l_scom_buffer_PATTERN_24_F_0_15 = 0x1f0f;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_PATTERN_24_F_0_15, 48, 16, 48 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8002c02506010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8002c02506010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8002c02606010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8002c02606010c3full)");
                break;
            }

            {
                constexpr auto l_scom_buffer_PATTERN_24_G_0_15 = 0x1800;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_PATTERN_24_G_0_15, 48, 16, 48 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8002c02606010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8002c02606010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8002c02706010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8002c02706010c3full)");
                break;
            }

            {
                constexpr auto l_scom_buffer_PATTERN_24_H_0_15 = 0x9c00;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_PATTERN_24_H_0_15, 48, 16, 48 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8002c02706010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8002c02706010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8002c02806010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8002c02806010c3full)");
                break;
            }

            {
                constexpr auto l_scom_buffer_PATTERN_24_A_0_15 = 0x1000;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_PATTERN_24_A_0_15, 48, 16, 48 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8002c02806010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8002c02806010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8002c02906010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8002c02906010c3full)");
                break;
            }

            {
                constexpr auto l_scom_buffer_PATTERN_24_H_0_15 = 0x9c00;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_PATTERN_24_H_0_15, 48, 16, 48 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8002c02906010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8002c02906010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8002c02a06010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8002c02a06010c3full)");
                break;
            }

            {
                constexpr auto l_scom_buffer_PATTERN_24_G_0_15 = 0x1800;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_PATTERN_24_G_0_15, 48, 16, 48 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8002c02a06010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8002c02a06010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8002c02b06010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8002c02b06010c3full)");
                break;
            }

            {
                constexpr auto l_scom_buffer_PATTERN_24_F_0_15 = 0x1f0f;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_PATTERN_24_F_0_15, 48, 16, 48 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8002c02b06010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8002c02b06010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8002c02c06010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8002c02c06010c3full)");
                break;
            }

            {
                constexpr auto l_scom_buffer_PATTERN_24_E_0_15 = 0x3ef;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_PATTERN_24_E_0_15, 48, 16, 48 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8002c02c06010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8002c02c06010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8002c02d06010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8002c02d06010c3full)");
                break;
            }

            {
                constexpr auto l_scom_buffer_PATTERN_24_D_0_15 = 0x7c7;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_PATTERN_24_D_0_15, 48, 16, 48 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8002c02d06010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8002c02d06010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8002c02e06010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8002c02e06010c3full)");
                break;
            }

            {
                constexpr auto l_scom_buffer_PATTERN_24_C_0_15 = 0x7bc;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_PATTERN_24_C_0_15, 48, 16, 48 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8002c02e06010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8002c02e06010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8002c02f06010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8002c02f06010c3full)");
                break;
            }

            {
                constexpr auto l_scom_buffer_PATTERN_24_B_0_15 = 0xf03e;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_PATTERN_24_B_0_15, 48, 16, 48 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8002c02f06010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8002c02f06010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8002c03006010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8002c03006010c3full)");
                break;
            }

            {
                constexpr auto l_scom_buffer_PATTERN_24_A_0_15 = 0x1000;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_PATTERN_24_A_0_15, 48, 16, 48 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8002c03006010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8002c03006010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8002c82006010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8002c82006010c3full)");
                break;
            }

            {
                constexpr auto l_scom_buffer_PATTERN_24_A_16_22 = 0x42;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_PATTERN_24_A_16_22, 48, 7, 57 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8002c82006010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8002c82006010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8002c82106010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8002c82106010c3full)");
                break;
            }

            {
                constexpr auto l_scom_buffer_PATTERN_24_B_16_22 = 0x3e;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_PATTERN_24_B_16_22, 48, 7, 57 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8002c82106010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8002c82106010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8002c82206010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8002c82206010c3full)");
                break;
            }

            {
                constexpr auto l_scom_buffer_PATTERN_24_C_12_ACGH_16_22 = 0x0;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_PATTERN_24_C_12_ACGH_16_22, 48, 7, 57 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8002c82206010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8002c82206010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8002c82306010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8002c82306010c3full)");
                break;
            }

            {
                constexpr auto l_scom_buffer_PATTERN_24_D_16_22 = 0x60;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_PATTERN_24_D_16_22, 48, 7, 57 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8002c82306010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8002c82306010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8002c82406010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8002c82406010c3full)");
                break;
            }

            {
                constexpr auto l_scom_buffer_PATTERN_24_EF_16_22 = 0x40;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_PATTERN_24_EF_16_22, 48, 7, 57 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8002c82406010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8002c82406010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8002c82506010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8002c82506010c3full)");
                break;
            }

            {
                constexpr auto l_scom_buffer_PATTERN_24_EF_16_22 = 0x40;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_PATTERN_24_EF_16_22, 48, 7, 57 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8002c82506010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8002c82506010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8002c82606010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8002c82606010c3full)");
                break;
            }

            {
                constexpr auto l_scom_buffer_PATTERN_24_GH_16_22 = 0x3;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_PATTERN_24_GH_16_22, 48, 7, 57 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8002c82606010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8002c82606010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8002c82706010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8002c82706010c3full)");
                break;
            }

            {
                constexpr auto l_scom_buffer_PATTERN_24_GH_16_22 = 0x3;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_PATTERN_24_GH_16_22, 48, 7, 57 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8002c82706010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8002c82706010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8002c82806010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8002c82806010c3full)");
                break;
            }

            {
                constexpr auto l_scom_buffer_PATTERN_24_A_16_22 = 0x42;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_PATTERN_24_A_16_22, 48, 7, 57 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8002c82806010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8002c82806010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8002c82906010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8002c82906010c3full)");
                break;
            }

            {
                constexpr auto l_scom_buffer_PATTERN_24_GH_16_22 = 0x3;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_PATTERN_24_GH_16_22, 48, 7, 57 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8002c82906010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8002c82906010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8002c82a06010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8002c82a06010c3full)");
                break;
            }

            {
                constexpr auto l_scom_buffer_PATTERN_24_GH_16_22 = 0x3;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_PATTERN_24_GH_16_22, 48, 7, 57 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8002c82a06010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8002c82a06010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8002c82b06010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8002c82b06010c3full)");
                break;
            }

            {
                constexpr auto l_scom_buffer_PATTERN_24_EF_16_22 = 0x40;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_PATTERN_24_EF_16_22, 48, 7, 57 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8002c82b06010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8002c82b06010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8002c82c06010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8002c82c06010c3full)");
                break;
            }

            {
                constexpr auto l_scom_buffer_PATTERN_24_EF_16_22 = 0x40;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_PATTERN_24_EF_16_22, 48, 7, 57 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8002c82c06010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8002c82c06010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8002c82d06010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8002c82d06010c3full)");
                break;
            }

            {
                constexpr auto l_scom_buffer_PATTERN_24_D_16_22 = 0x60;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_PATTERN_24_D_16_22, 48, 7, 57 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8002c82d06010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8002c82d06010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8002c82e06010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8002c82e06010c3full)");
                break;
            }

            {
                constexpr auto l_scom_buffer_PATTERN_24_C_12_ACGH_16_22 = 0x0;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_PATTERN_24_C_12_ACGH_16_22, 48, 7, 57 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8002c82e06010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8002c82e06010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8002c82f06010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8002c82f06010c3full)");
                break;
            }

            {
                constexpr auto l_scom_buffer_PATTERN_24_B_16_22 = 0x3e;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_PATTERN_24_B_16_22, 48, 7, 57 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8002c82f06010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8002c82f06010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8002c83006010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8002c83006010c3full)");
                break;
            }

            {
                constexpr auto l_scom_buffer_PATTERN_24_A_16_22 = 0x42;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_PATTERN_24_A_16_22, 48, 7, 57 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8002c83006010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8002c83006010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8004042006010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8004042006010c3full)");
                break;
            }

            {
                constexpr auto l_scom_buffer_ENABLED = 0x0;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_ENABLED, 48, 1, 63 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8004042006010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8004042006010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8004042106010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8004042106010c3full)");
                break;
            }

            {
                constexpr auto l_scom_buffer_ENABLED = 0x0;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_ENABLED, 48, 1, 63 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8004042106010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8004042106010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8004042206010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8004042206010c3full)");
                break;
            }

            {
                constexpr auto l_scom_buffer_ENABLED = 0x0;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_ENABLED, 48, 1, 63 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8004042206010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8004042206010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8004042306010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8004042306010c3full)");
                break;
            }

            {
                constexpr auto l_scom_buffer_ENABLED = 0x0;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_ENABLED, 48, 1, 63 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8004042306010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8004042306010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8004042406010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8004042406010c3full)");
                break;
            }

            {
                constexpr auto l_scom_buffer_ENABLED = 0x0;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_ENABLED, 48, 1, 63 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8004042406010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8004042406010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8004042506010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8004042506010c3full)");
                break;
            }

            {
                constexpr auto l_scom_buffer_ENABLED = 0x0;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_ENABLED, 48, 1, 63 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8004042506010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8004042506010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8004042606010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8004042606010c3full)");
                break;
            }

            {
                constexpr auto l_scom_buffer_ENABLED = 0x0;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_ENABLED, 48, 1, 63 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8004042606010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8004042606010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8004042706010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8004042706010c3full)");
                break;
            }

            {
                constexpr auto l_scom_buffer_ENABLED = 0x0;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_ENABLED, 48, 1, 63 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8004042706010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8004042706010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8004042806010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8004042806010c3full)");
                break;
            }

            {
                constexpr auto l_scom_buffer_ENABLED = 0x0;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_ENABLED, 48, 1, 63 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8004042806010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8004042806010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8004042906010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8004042906010c3full)");
                break;
            }

            {
                constexpr auto l_scom_buffer_ENABLED = 0x0;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_ENABLED, 48, 1, 63 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8004042906010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8004042906010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8004042a06010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8004042a06010c3full)");
                break;
            }

            {
                constexpr auto l_scom_buffer_ENABLED = 0x0;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_ENABLED, 48, 1, 63 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8004042a06010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8004042a06010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8004042b06010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8004042b06010c3full)");
                break;
            }

            {
                constexpr auto l_scom_buffer_ENABLED = 0x0;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_ENABLED, 48, 1, 63 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8004042b06010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8004042b06010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8004042c06010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8004042c06010c3full)");
                break;
            }

            {
                constexpr auto l_scom_buffer_ENABLED = 0x0;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_ENABLED, 48, 1, 63 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8004042c06010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8004042c06010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8004042d06010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8004042d06010c3full)");
                break;
            }

            {
                constexpr auto l_scom_buffer_ENABLED = 0x0;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_ENABLED, 48, 1, 63 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8004042d06010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8004042d06010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8004042e06010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8004042e06010c3full)");
                break;
            }

            {
                constexpr auto l_scom_buffer_ENABLED = 0x0;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_ENABLED, 48, 1, 63 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8004042e06010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8004042e06010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8004042f06010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8004042f06010c3full)");
                break;
            }

            {
                constexpr auto l_scom_buffer_ENABLED = 0x0;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_ENABLED, 48, 1, 63 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8004042f06010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8004042f06010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8004043006010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8004043006010c3full)");
                break;
            }

            {
                constexpr auto l_scom_buffer_ENABLED = 0x0;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_ENABLED, 48, 1, 63 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8004043006010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8004043006010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x80040c2006010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x80040c2006010c3full)");
                break;
            }

            {
                constexpr auto l_scom_buffer_ON = 0x1;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_ON, 62, 1, 63 );
            }

            l_rc = fapi2::putScom(TGT0, 0x80040c2006010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x80040c2006010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x80040c2106010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x80040c2106010c3full)");
                break;
            }

            {
                constexpr auto l_scom_buffer_ON = 0x1;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_ON, 62, 1, 63 );
            }

            l_rc = fapi2::putScom(TGT0, 0x80040c2106010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x80040c2106010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x80040c2206010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x80040c2206010c3full)");
                break;
            }

            {
                constexpr auto l_scom_buffer_ON = 0x1;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_ON, 62, 1, 63 );
            }

            l_rc = fapi2::putScom(TGT0, 0x80040c2206010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x80040c2206010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x80040c2306010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x80040c2306010c3full)");
                break;
            }

            {
                constexpr auto l_scom_buffer_ON = 0x1;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_ON, 62, 1, 63 );
            }

            l_rc = fapi2::putScom(TGT0, 0x80040c2306010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x80040c2306010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x80040c2406010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x80040c2406010c3full)");
                break;
            }

            {
                constexpr auto l_scom_buffer_ON = 0x1;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_ON, 62, 1, 63 );
            }

            l_rc = fapi2::putScom(TGT0, 0x80040c2406010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x80040c2406010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x80040c2506010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x80040c2506010c3full)");
                break;
            }

            {
                constexpr auto l_scom_buffer_ON = 0x1;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_ON, 62, 1, 63 );
            }

            l_rc = fapi2::putScom(TGT0, 0x80040c2506010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x80040c2506010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x80040c2606010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x80040c2606010c3full)");
                break;
            }

            {
                constexpr auto l_scom_buffer_ON = 0x1;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_ON, 62, 1, 63 );
            }

            l_rc = fapi2::putScom(TGT0, 0x80040c2606010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x80040c2606010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x80040c2706010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x80040c2706010c3full)");
                break;
            }

            {
                constexpr auto l_scom_buffer_ON = 0x1;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_ON, 62, 1, 63 );
            }

            l_rc = fapi2::putScom(TGT0, 0x80040c2706010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x80040c2706010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x80040c2806010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x80040c2806010c3full)");
                break;
            }

            {
                constexpr auto l_scom_buffer_ON = 0x1;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_ON, 62, 1, 63 );
            }

            l_rc = fapi2::putScom(TGT0, 0x80040c2806010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x80040c2806010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x80040c2906010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x80040c2906010c3full)");
                break;
            }

            {
                constexpr auto l_scom_buffer_ON = 0x1;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_ON, 62, 1, 63 );
            }

            l_rc = fapi2::putScom(TGT0, 0x80040c2906010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x80040c2906010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x80040c2a06010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x80040c2a06010c3full)");
                break;
            }

            {
                constexpr auto l_scom_buffer_ON = 0x1;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_ON, 62, 1, 63 );
            }

            l_rc = fapi2::putScom(TGT0, 0x80040c2a06010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x80040c2a06010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x80040c2b06010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x80040c2b06010c3full)");
                break;
            }

            {
                constexpr auto l_scom_buffer_ON = 0x1;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_ON, 62, 1, 63 );
            }

            l_rc = fapi2::putScom(TGT0, 0x80040c2b06010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x80040c2b06010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x80040c2c06010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x80040c2c06010c3full)");
                break;
            }

            {
                constexpr auto l_scom_buffer_ON = 0x1;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_ON, 62, 1, 63 );
            }

            l_rc = fapi2::putScom(TGT0, 0x80040c2c06010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x80040c2c06010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x80040c2d06010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x80040c2d06010c3full)");
                break;
            }

            {
                constexpr auto l_scom_buffer_ON = 0x1;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_ON, 62, 1, 63 );
            }

            l_rc = fapi2::putScom(TGT0, 0x80040c2d06010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x80040c2d06010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x80040c2e06010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x80040c2e06010c3full)");
                break;
            }

            {
                constexpr auto l_scom_buffer_ON = 0x1;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_ON, 62, 1, 63 );
            }

            l_rc = fapi2::putScom(TGT0, 0x80040c2e06010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x80040c2e06010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x80040c2f06010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x80040c2f06010c3full)");
                break;
            }

            {
                constexpr auto l_scom_buffer_ON = 0x1;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_ON, 62, 1, 63 );
            }

            l_rc = fapi2::putScom(TGT0, 0x80040c2f06010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x80040c2f06010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x80040c3006010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x80040c3006010c3full)");
                break;
            }

            {
                constexpr auto l_scom_buffer_ON = 0x1;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_ON, 62, 1, 63 );
            }

            l_rc = fapi2::putScom(TGT0, 0x80040c3006010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x80040c3006010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x80043c2006010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x80043c2006010c3full)");
                break;
            }

            {
                constexpr auto l_scom_buffer_PATTERN_TX_AB_HALF_A_0_15 = 0x0;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_PATTERN_TX_AB_HALF_A_0_15, 48, 16, 48 );
            }

            l_rc = fapi2::putScom(TGT0, 0x80043c2006010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x80043c2006010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x80043c2106010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x80043c2106010c3full)");
                break;
            }

            {
                constexpr auto l_scom_buffer_PATTERN_TX_AB_HALF_A_0_15 = 0x0;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_PATTERN_TX_AB_HALF_A_0_15, 48, 16, 48 );
            }

            l_rc = fapi2::putScom(TGT0, 0x80043c2106010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x80043c2106010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x80043c2206010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x80043c2206010c3full)");
                break;
            }

            {
                constexpr auto l_scom_buffer_PATTERN_TX_C_0_15 = 0x1e;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_PATTERN_TX_C_0_15, 48, 16, 48 );
            }

            l_rc = fapi2::putScom(TGT0, 0x80043c2206010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x80043c2206010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x80043c2306010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x80043c2306010c3full)");
                break;
            }

            {
                constexpr auto l_scom_buffer_PATTERN_TX_D_0_15 = 0x1f;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_PATTERN_TX_D_0_15, 48, 16, 48 );
            }

            l_rc = fapi2::putScom(TGT0, 0x80043c2306010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x80043c2306010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x80043c2406010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x80043c2406010c3full)");
                break;
            }

            {
                constexpr auto l_scom_buffer_PATTERN_TX_E_HALF_B_0_15 = 0xf;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_PATTERN_TX_E_HALF_B_0_15, 48, 16, 48 );
            }

            l_rc = fapi2::putScom(TGT0, 0x80043c2406010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x80043c2406010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x80043c2506010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x80043c2506010c3full)");
                break;
            }

            {
                constexpr auto l_scom_buffer_PATTERN_TX_F_0_15 = 0x7c;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_PATTERN_TX_F_0_15, 48, 16, 48 );
            }

            l_rc = fapi2::putScom(TGT0, 0x80043c2506010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x80043c2506010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x80043c2606010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x80043c2606010c3full)");
                break;
            }

            {
                constexpr auto l_scom_buffer_PATTERN_TX_G_0_15 = 0xc63;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_PATTERN_TX_G_0_15, 48, 16, 48 );
            }

            l_rc = fapi2::putScom(TGT0, 0x80043c2606010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x80043c2606010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x80043c2706010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x80043c2706010c3full)");
                break;
            }

            {
                constexpr auto l_scom_buffer_PATTERN_TX_H_0_15 = 0xe73;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_PATTERN_TX_H_0_15, 48, 16, 48 );
            }

            l_rc = fapi2::putScom(TGT0, 0x80043c2706010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x80043c2706010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x80043c2806010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x80043c2806010c3full)");
                break;
            }

            {
                constexpr auto l_scom_buffer_PATTERN_TX_AB_HALF_A_0_15 = 0x0;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_PATTERN_TX_AB_HALF_A_0_15, 48, 16, 48 );
            }

            l_rc = fapi2::putScom(TGT0, 0x80043c2806010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x80043c2806010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x80043c2906010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x80043c2906010c3full)");
                break;
            }

            {
                constexpr auto l_scom_buffer_PATTERN_TX_H_0_15 = 0xe73;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_PATTERN_TX_H_0_15, 48, 16, 48 );
            }

            l_rc = fapi2::putScom(TGT0, 0x80043c2906010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x80043c2906010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x80043c2a06010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x80043c2a06010c3full)");
                break;
            }

            {
                constexpr auto l_scom_buffer_PATTERN_TX_G_0_15 = 0xc63;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_PATTERN_TX_G_0_15, 48, 16, 48 );
            }

            l_rc = fapi2::putScom(TGT0, 0x80043c2a06010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x80043c2a06010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x80043c2b06010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x80043c2b06010c3full)");
                break;
            }

            {
                constexpr auto l_scom_buffer_PATTERN_TX_F_0_15 = 0x7c;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_PATTERN_TX_F_0_15, 48, 16, 48 );
            }

            l_rc = fapi2::putScom(TGT0, 0x80043c2b06010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x80043c2b06010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x80043c2c06010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x80043c2c06010c3full)");
                break;
            }

            {
                constexpr auto l_scom_buffer_PATTERN_TX_E_HALF_B_0_15 = 0xf;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_PATTERN_TX_E_HALF_B_0_15, 48, 16, 48 );
            }

            l_rc = fapi2::putScom(TGT0, 0x80043c2c06010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x80043c2c06010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x80043c2d06010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x80043c2d06010c3full)");
                break;
            }

            {
                constexpr auto l_scom_buffer_PATTERN_TX_D_0_15 = 0x1f;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_PATTERN_TX_D_0_15, 48, 16, 48 );
            }

            l_rc = fapi2::putScom(TGT0, 0x80043c2d06010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x80043c2d06010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x80043c2e06010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x80043c2e06010c3full)");
                break;
            }

            {
                constexpr auto l_scom_buffer_PATTERN_TX_C_0_15 = 0x1e;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_PATTERN_TX_C_0_15, 48, 16, 48 );
            }

            l_rc = fapi2::putScom(TGT0, 0x80043c2e06010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x80043c2e06010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x80043c2f06010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x80043c2f06010c3full)");
                break;
            }

            {
                constexpr auto l_scom_buffer_PATTERN_TX_AB_HALF_A_0_15 = 0x0;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_PATTERN_TX_AB_HALF_A_0_15, 48, 16, 48 );
            }

            l_rc = fapi2::putScom(TGT0, 0x80043c2f06010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x80043c2f06010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x80043c3006010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x80043c3006010c3full)");
                break;
            }

            {
                constexpr auto l_scom_buffer_PATTERN_TX_AB_HALF_A_0_15 = 0x0;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_PATTERN_TX_AB_HALF_A_0_15, 48, 16, 48 );
            }

            l_rc = fapi2::putScom(TGT0, 0x80043c3006010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x80043c3006010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8004442006010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8004442006010c3full)");
                break;
            }

            {
                constexpr auto l_scom_buffer_PATTERN_TX_A_16_22 = 0x1;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_PATTERN_TX_A_16_22, 48, 7, 57 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8004442006010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8004442006010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8004442106010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8004442106010c3full)");
                break;
            }

            {
                constexpr auto l_scom_buffer_PATTERN_TX_B_16_22 = 0x7c;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_PATTERN_TX_B_16_22, 48, 7, 57 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8004442106010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8004442106010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8004442206010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8004442206010c3full)");
                break;
            }

            {
                constexpr auto l_scom_buffer_PATTERN_TX_C_16_22 = 0x7b;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_PATTERN_TX_C_16_22, 48, 7, 57 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8004442206010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8004442206010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8004442306010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8004442306010c3full)");
                break;
            }

            {
                constexpr auto l_scom_buffer_PATTERN_TX_DG_16_22 = 0xc;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_PATTERN_TX_DG_16_22, 48, 7, 57 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8004442306010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8004442306010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8004442406010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8004442406010c3full)");
                break;
            }

            {
                constexpr auto l_scom_buffer_PATTERN_TX_E_16_22 = 0x5e;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_PATTERN_TX_E_16_22, 48, 7, 57 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8004442406010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8004442406010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8004442506010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8004442506010c3full)");
                break;
            }

            {
                constexpr auto l_scom_buffer_PATTERN_TX_F_HALF_A_16_22 = 0x10;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_PATTERN_TX_F_HALF_A_16_22, 48, 7, 57 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8004442506010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8004442506010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8004442606010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8004442606010c3full)");
                break;
            }

            {
                constexpr auto l_scom_buffer_PATTERN_TX_DG_16_22 = 0xc;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_PATTERN_TX_DG_16_22, 48, 7, 57 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8004442606010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8004442606010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8004442706010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8004442706010c3full)");
                break;
            }

            {
                constexpr auto l_scom_buffer_PATTERN_TX_H_HALF_B_16_22 = 0x4e;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_PATTERN_TX_H_HALF_B_16_22, 48, 7, 57 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8004442706010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8004442706010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8004442806010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8004442806010c3full)");
                break;
            }

            {
                constexpr auto l_scom_buffer_PATTERN_TX_A_16_22 = 0x1;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_PATTERN_TX_A_16_22, 48, 7, 57 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8004442806010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8004442806010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8004442906010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8004442906010c3full)");
                break;
            }

            {
                constexpr auto l_scom_buffer_PATTERN_TX_H_HALF_B_16_22 = 0x4e;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_PATTERN_TX_H_HALF_B_16_22, 48, 7, 57 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8004442906010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8004442906010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8004442a06010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8004442a06010c3full)");
                break;
            }

            {
                constexpr auto l_scom_buffer_PATTERN_TX_DG_16_22 = 0xc;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_PATTERN_TX_DG_16_22, 48, 7, 57 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8004442a06010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8004442a06010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8004442b06010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8004442b06010c3full)");
                break;
            }

            {
                constexpr auto l_scom_buffer_PATTERN_TX_F_HALF_A_16_22 = 0x10;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_PATTERN_TX_F_HALF_A_16_22, 48, 7, 57 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8004442b06010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8004442b06010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8004442c06010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8004442c06010c3full)");
                break;
            }

            {
                constexpr auto l_scom_buffer_PATTERN_TX_E_16_22 = 0x5e;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_PATTERN_TX_E_16_22, 48, 7, 57 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8004442c06010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8004442c06010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8004442d06010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8004442d06010c3full)");
                break;
            }

            {
                constexpr auto l_scom_buffer_PATTERN_TX_DG_16_22 = 0xc;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_PATTERN_TX_DG_16_22, 48, 7, 57 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8004442d06010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8004442d06010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8004442e06010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8004442e06010c3full)");
                break;
            }

            {
                constexpr auto l_scom_buffer_PATTERN_TX_C_16_22 = 0x7b;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_PATTERN_TX_C_16_22, 48, 7, 57 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8004442e06010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8004442e06010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8004442f06010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8004442f06010c3full)");
                break;
            }

            {
                constexpr auto l_scom_buffer_PATTERN_TX_B_16_22 = 0x7c;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_PATTERN_TX_B_16_22, 48, 7, 57 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8004442f06010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8004442f06010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8004443006010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8004443006010c3full)");
                break;
            }

            {
                constexpr auto l_scom_buffer_PATTERN_TX_A_16_22 = 0x1;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_PATTERN_TX_A_16_22, 48, 7, 57 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8004443006010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8004443006010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8008082006010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8008082006010c3full)");
                break;
            }

            {
                l_scom_buffer.insert<uint64_t> (literal_0b000001, 48, 6, 58 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8008082006010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8008082006010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8008102006010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8008102006010c3full)");
                break;
            }

            {
                constexpr auto l_scom_buffer_OFF = 0x0;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_OFF, 48, 1, 63 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8008102006010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8008102006010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8008302006010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8008302006010c3full)");
                break;
            }

            {
                constexpr auto l_scom_buffer_TAP5 = 0x5;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_TAP5, 51, 3, 61 );
            }

            {
                constexpr auto l_scom_buffer_TAP1 = 0x1;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_TAP1, 54, 2, 62 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8008302006010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8008302006010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8008402006010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8008402006010c3full)");
                break;
            }

            {
                l_scom_buffer.insert<uint64_t> (literal_0b1010, 60, 4, 60 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8008402006010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8008402006010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8008c02006010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8008c02006010c3full)");
                break;
            }

            {
                constexpr auto l_scom_buffer_OFF = 0x0;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_OFF, 55, 1, 63 );
            }

            {
                constexpr auto l_scom_buffer_OFF = 0x0;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_OFF, 56, 1, 63 );
            }

            {
                l_scom_buffer.insert<uint64_t> (literal_0b11, 57, 2, 62 );
            }

            {
                constexpr auto l_scom_buffer_ON = 0x1;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_ON, 59, 1, 63 );
            }

            {
                constexpr auto l_scom_buffer_ON = 0x1;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_ON, 60, 1, 63 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8008c02006010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8008c02006010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8009802006010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8009802006010c3full)");
                break;
            }

            {
                l_scom_buffer.insert<uint64_t> (literal_0b0000000, 49, 7, 57 );
            }

            {
                l_scom_buffer.insert<uint64_t> (literal_0b0010000, 57, 7, 57 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8009802006010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8009802006010c3full)");
                break;
            }
        }
        fapi2::ATTR_IO_XBUS_MASTER_MODE_Type l_TGT0_ATTR_IO_XBUS_MASTER_MODE;
        l_rc = FAPI_ATTR_GET(fapi2::ATTR_IO_XBUS_MASTER_MODE, TGT0, l_TGT0_ATTR_IO_XBUS_MASTER_MODE);

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: FAPI_ATTR_GET (ATTR_IO_XBUS_MASTER_MODE)");
            break;
        }

        auto l_def_is_master = (l_TGT0_ATTR_IO_XBUS_MASTER_MODE == literal_1);
        {
            l_rc = fapi2::getScom( TGT0, 0x8009902006010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8009902006010c3full)");
                break;
            }

            {
                if (l_def_is_master)
                {
                    constexpr auto l_scom_buffer_MASTER = 0x1;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_MASTER, 48, 1, 63 );
                }
            }

            {
                constexpr auto l_scom_buffer_ON = 0x1;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_ON, 58, 1, 63 );
            }

            {
                constexpr auto l_scom_buffer_FENCED = 0x1;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_FENCED, 57, 1, 63 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8009902006010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8009902006010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8009982006010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8009982006010c3full)");
                break;
            }

            {
                l_scom_buffer.insert<uint64_t> (literal_0b00001, 48, 5, 59 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8009982006010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8009982006010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8009a02006010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8009a02006010c3full)");
                break;
            }

            {
                l_scom_buffer.insert<uint64_t> (literal_0b1011, 48, 4, 60 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8009a02006010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8009a02006010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8009b82006010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8009b82006010c3full)");
                break;
            }

            {
                l_scom_buffer.insert<uint64_t> (literal_0b0010001, 48, 7, 57 );
            }

            {
                l_scom_buffer.insert<uint64_t> (literal_0b0010001, 55, 7, 57 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8009b82006010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8009b82006010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8009e02006010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8009e02006010c3full)");
                break;
            }

            {
                l_scom_buffer.insert<uint64_t> (literal_0b0000000000000000, 48, 16, 48 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8009e02006010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8009e02006010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8009e82006010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8009e82006010c3full)");
                break;
            }

            {
                l_scom_buffer.insert<uint64_t> (literal_0b01111111, 48, 8, 56 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8009e82006010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8009e82006010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x800a802006010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x800a802006010c3full)");
                break;
            }

            {
                constexpr auto l_scom_buffer_ON = 0x1;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_ON, 50, 1, 63 );
            }

            l_rc = fapi2::putScom(TGT0, 0x800a802006010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x800a802006010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x800b802006010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x800b802006010c3full)");
                break;
            }

            {
                constexpr auto l_scom_buffer_OFF = 0x0;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_OFF, 60, 1, 63 );
            }

            l_rc = fapi2::putScom(TGT0, 0x800b802006010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x800b802006010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x800c042006010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x800c042006010c3full)");
                break;
            }

            {
                if (l_def_IS_HW)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b00, 56, 2, 62 );
                }
                else if (l_def_IS_SIM)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b01, 56, 2, 62 );
                }
            }

            l_rc = fapi2::putScom(TGT0, 0x800c042006010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x800c042006010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x800c0c2006010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x800c0c2006010c3full)");
                break;
            }

            {
                l_scom_buffer.insert<uint64_t> (literal_0b000001, 48, 6, 58 );
            }

            l_rc = fapi2::putScom(TGT0, 0x800c0c2006010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x800c0c2006010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x800c142006010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x800c142006010c3full)");
                break;
            }

            {
                constexpr auto l_scom_buffer_OFF = 0x0;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_OFF, 48, 1, 63 );
            }

            {
                constexpr auto l_scom_buffer_ON = 0x1;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_ON, 59, 1, 63 );
            }

            {
                l_scom_buffer.insert<uint64_t> (literal_0b00001, 53, 5, 59 );
            }

            l_rc = fapi2::putScom(TGT0, 0x800c142006010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x800c142006010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x800c1c2006010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x800c1c2006010c3full)");
                break;
            }

            {
                l_scom_buffer.insert<uint64_t> (literal_0b0010001, 56, 7, 57 );
            }

            l_rc = fapi2::putScom(TGT0, 0x800c1c2006010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x800c1c2006010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x800c242006010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x800c242006010c3full)");
                break;
            }

            {
                constexpr auto l_scom_buffer_DRV_0S = 0x0;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_DRV_0S, 48, 2, 62 );
            }

            l_rc = fapi2::putScom(TGT0, 0x800c242006010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x800c242006010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x800c842006010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x800c842006010c3full)");
                break;
            }

            {
                l_scom_buffer.insert<uint64_t> (literal_0b0000000, 49, 7, 57 );
            }

            {
                l_scom_buffer.insert<uint64_t> (literal_0b0010000, 57, 7, 57 );
            }

            l_rc = fapi2::putScom(TGT0, 0x800c842006010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x800c842006010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x800c8c2006010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x800c8c2006010c3full)");
                break;
            }

            {
                constexpr auto l_scom_buffer_TAP5 = 0x5;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_TAP5, 55, 3, 61 );
            }

            {
                constexpr auto l_scom_buffer_TAP1 = 0x1;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_TAP1, 58, 2, 62 );
            }

            l_rc = fapi2::putScom(TGT0, 0x800c8c2006010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x800c8c2006010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x800cec2006010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x800cec2006010c3full)");
                break;
            }

            {
                l_scom_buffer.insert<uint64_t> (literal_0b0000000000000000, 48, 16, 48 );
            }

            l_rc = fapi2::putScom(TGT0, 0x800cec2006010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x800cec2006010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x800cf42006010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x800cf42006010c3full)");
                break;
            }

            {
                l_scom_buffer.insert<uint64_t> (literal_0b01111111, 48, 8, 56 );
            }

            l_rc = fapi2::putScom(TGT0, 0x800cf42006010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x800cf42006010c3full)");
                break;
            }
        }
    }
    while (0);

    return l_rc;
}
