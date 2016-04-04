/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/initfiles/p9_xbus_g0_scom.C $         */
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
#include "p9_xbus_g0_scom.H"
#include <stdint.h>
#include <stddef.h>
#include <fapi2.H>

using namespace fapi2;

constexpr auto literal_0 = 0;
constexpr auto literal_1 = 1;
constexpr auto literal_0b0000 = 0b0000;
constexpr auto literal_0b0110 = 0b0110;
constexpr auto literal_0b00000 = 0b00000;
constexpr auto literal_0b01100 = 0b01100;
constexpr auto literal_0b0000000 = 0b0000000;
constexpr auto literal_0b0000011 = 0b0000011;
constexpr auto literal_0b000000 = 0b000000;
constexpr auto literal_0b00001 = 0b00001;
constexpr auto literal_0b0010001 = 0b0010001;
constexpr auto literal_0b0000000000000000 = 0b0000000000000000;
constexpr auto literal_0b01111111 = 0b01111111;
constexpr auto literal_0b00 = 0b00;
constexpr auto literal_0b01 = 0b01;

fapi2::ReturnCode p9_xbus_g0_scom(const fapi2::Target<fapi2::TARGET_TYPE_XBUS>& TGT0,
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
            l_rc = fapi2::getScom( TGT0, 0x8000000006010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8000000006010c3full)");
                break;
            }

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

            l_rc = fapi2::putScom(TGT0, 0x8000000006010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8000000006010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8000000106010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8000000106010c3full)");
                break;
            }

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

            l_rc = fapi2::putScom(TGT0, 0x8000000106010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8000000106010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8000000206010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8000000206010c3full)");
                break;
            }

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

            l_rc = fapi2::putScom(TGT0, 0x8000000206010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8000000206010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8000000306010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8000000306010c3full)");
                break;
            }

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

            l_rc = fapi2::putScom(TGT0, 0x8000000306010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8000000306010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8000000406010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8000000406010c3full)");
                break;
            }

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

            l_rc = fapi2::putScom(TGT0, 0x8000000406010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8000000406010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8000000506010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8000000506010c3full)");
                break;
            }

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

            l_rc = fapi2::putScom(TGT0, 0x8000000506010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8000000506010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8000000606010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8000000606010c3full)");
                break;
            }

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

            l_rc = fapi2::putScom(TGT0, 0x8000000606010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8000000606010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8000000706010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8000000706010c3full)");
                break;
            }

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

            l_rc = fapi2::putScom(TGT0, 0x8000000706010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8000000706010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8000000806010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8000000806010c3full)");
                break;
            }

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

            l_rc = fapi2::putScom(TGT0, 0x8000000806010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8000000806010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8000000906010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8000000906010c3full)");
                break;
            }

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

            l_rc = fapi2::putScom(TGT0, 0x8000000906010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8000000906010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8000000a06010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8000000a06010c3full)");
                break;
            }

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

            l_rc = fapi2::putScom(TGT0, 0x8000000a06010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8000000a06010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8000000b06010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8000000b06010c3full)");
                break;
            }

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

            l_rc = fapi2::putScom(TGT0, 0x8000000b06010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8000000b06010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8000000c06010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8000000c06010c3full)");
                break;
            }

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

            l_rc = fapi2::putScom(TGT0, 0x8000000c06010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8000000c06010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8000000d06010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8000000d06010c3full)");
                break;
            }

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

            l_rc = fapi2::putScom(TGT0, 0x8000000d06010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8000000d06010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8000000e06010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8000000e06010c3full)");
                break;
            }

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

            l_rc = fapi2::putScom(TGT0, 0x8000000e06010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8000000e06010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8000000f06010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8000000f06010c3full)");
                break;
            }

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

            l_rc = fapi2::putScom(TGT0, 0x8000000f06010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8000000f06010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8000001006010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8000001006010c3full)");
                break;
            }

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

            l_rc = fapi2::putScom(TGT0, 0x8000001006010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8000001006010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8000001106010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8000001106010c3full)");
                break;
            }

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

            l_rc = fapi2::putScom(TGT0, 0x8000001106010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8000001106010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8000080006010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8000080006010c3full)");
                break;
            }

            constexpr auto l_scom_buffer_OFF = 0x0;
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_OFF, 54, 1, 63 );
            l_rc = fapi2::putScom(TGT0, 0x8000080006010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8000080006010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8000080106010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8000080106010c3full)");
                break;
            }

            constexpr auto l_scom_buffer_OFF = 0x0;
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_OFF, 54, 1, 63 );
            l_rc = fapi2::putScom(TGT0, 0x8000080106010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8000080106010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8000080206010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8000080206010c3full)");
                break;
            }

            constexpr auto l_scom_buffer_OFF = 0x0;
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_OFF, 54, 1, 63 );
            l_rc = fapi2::putScom(TGT0, 0x8000080206010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8000080206010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8000080306010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8000080306010c3full)");
                break;
            }

            constexpr auto l_scom_buffer_OFF = 0x0;
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_OFF, 54, 1, 63 );
            l_rc = fapi2::putScom(TGT0, 0x8000080306010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8000080306010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8000080406010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8000080406010c3full)");
                break;
            }

            constexpr auto l_scom_buffer_OFF = 0x0;
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_OFF, 54, 1, 63 );
            l_rc = fapi2::putScom(TGT0, 0x8000080406010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8000080406010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8000080506010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8000080506010c3full)");
                break;
            }

            constexpr auto l_scom_buffer_OFF = 0x0;
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_OFF, 54, 1, 63 );
            l_rc = fapi2::putScom(TGT0, 0x8000080506010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8000080506010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8000080606010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8000080606010c3full)");
                break;
            }

            constexpr auto l_scom_buffer_OFF = 0x0;
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_OFF, 54, 1, 63 );
            l_rc = fapi2::putScom(TGT0, 0x8000080606010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8000080606010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8000080706010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8000080706010c3full)");
                break;
            }

            constexpr auto l_scom_buffer_OFF = 0x0;
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_OFF, 54, 1, 63 );
            l_rc = fapi2::putScom(TGT0, 0x8000080706010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8000080706010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8000080806010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8000080806010c3full)");
                break;
            }

            constexpr auto l_scom_buffer_OFF = 0x0;
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_OFF, 54, 1, 63 );
            l_rc = fapi2::putScom(TGT0, 0x8000080806010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8000080806010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8000080906010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8000080906010c3full)");
                break;
            }

            constexpr auto l_scom_buffer_OFF = 0x0;
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_OFF, 54, 1, 63 );
            l_rc = fapi2::putScom(TGT0, 0x8000080906010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8000080906010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8000080a06010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8000080a06010c3full)");
                break;
            }

            constexpr auto l_scom_buffer_OFF = 0x0;
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_OFF, 54, 1, 63 );
            l_rc = fapi2::putScom(TGT0, 0x8000080a06010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8000080a06010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8000080b06010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8000080b06010c3full)");
                break;
            }

            constexpr auto l_scom_buffer_OFF = 0x0;
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_OFF, 54, 1, 63 );
            l_rc = fapi2::putScom(TGT0, 0x8000080b06010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8000080b06010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8000080c06010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8000080c06010c3full)");
                break;
            }

            constexpr auto l_scom_buffer_OFF = 0x0;
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_OFF, 54, 1, 63 );
            l_rc = fapi2::putScom(TGT0, 0x8000080c06010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8000080c06010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8000080d06010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8000080d06010c3full)");
                break;
            }

            constexpr auto l_scom_buffer_OFF = 0x0;
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_OFF, 54, 1, 63 );
            l_rc = fapi2::putScom(TGT0, 0x8000080d06010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8000080d06010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8000080e06010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8000080e06010c3full)");
                break;
            }

            constexpr auto l_scom_buffer_OFF = 0x0;
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_OFF, 54, 1, 63 );
            l_rc = fapi2::putScom(TGT0, 0x8000080e06010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8000080e06010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8000080f06010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8000080f06010c3full)");
                break;
            }

            constexpr auto l_scom_buffer_OFF = 0x0;
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_OFF, 54, 1, 63 );
            l_rc = fapi2::putScom(TGT0, 0x8000080f06010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8000080f06010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8000081006010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8000081006010c3full)");
                break;
            }

            constexpr auto l_scom_buffer_OFF = 0x0;
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_OFF, 54, 1, 63 );
            l_rc = fapi2::putScom(TGT0, 0x8000081006010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8000081006010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8000081106010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8000081106010c3full)");
                break;
            }

            constexpr auto l_scom_buffer_ON = 0x1;
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_ON, 54, 1, 63 );
            l_rc = fapi2::putScom(TGT0, 0x8000081106010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8000081106010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8000280006010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8000280006010c3full)");
                break;
            }

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<uint64_t> (literal_0b0000, 48, 4, 60 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<uint64_t> (literal_0b0110, 48, 4, 60 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8000280006010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8000280006010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8000280106010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8000280106010c3full)");
                break;
            }

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<uint64_t> (literal_0b0000, 48, 4, 60 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<uint64_t> (literal_0b0110, 48, 4, 60 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8000280106010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8000280106010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8000280206010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8000280206010c3full)");
                break;
            }

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<uint64_t> (literal_0b0000, 48, 4, 60 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<uint64_t> (literal_0b0110, 48, 4, 60 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8000280206010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8000280206010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8000280306010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8000280306010c3full)");
                break;
            }

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<uint64_t> (literal_0b0000, 48, 4, 60 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<uint64_t> (literal_0b0110, 48, 4, 60 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8000280306010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8000280306010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8000280406010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8000280406010c3full)");
                break;
            }

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<uint64_t> (literal_0b0000, 48, 4, 60 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<uint64_t> (literal_0b0110, 48, 4, 60 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8000280406010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8000280406010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8000280506010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8000280506010c3full)");
                break;
            }

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<uint64_t> (literal_0b0000, 48, 4, 60 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<uint64_t> (literal_0b0110, 48, 4, 60 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8000280506010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8000280506010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8000280606010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8000280606010c3full)");
                break;
            }

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<uint64_t> (literal_0b0000, 48, 4, 60 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<uint64_t> (literal_0b0110, 48, 4, 60 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8000280606010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8000280606010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8000280706010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8000280706010c3full)");
                break;
            }

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<uint64_t> (literal_0b0000, 48, 4, 60 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<uint64_t> (literal_0b0110, 48, 4, 60 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8000280706010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8000280706010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8000280806010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8000280806010c3full)");
                break;
            }

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<uint64_t> (literal_0b0000, 48, 4, 60 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<uint64_t> (literal_0b0110, 48, 4, 60 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8000280806010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8000280806010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8000280906010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8000280906010c3full)");
                break;
            }

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<uint64_t> (literal_0b0000, 48, 4, 60 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<uint64_t> (literal_0b0110, 48, 4, 60 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8000280906010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8000280906010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8000280a06010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8000280a06010c3full)");
                break;
            }

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<uint64_t> (literal_0b0000, 48, 4, 60 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<uint64_t> (literal_0b0110, 48, 4, 60 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8000280a06010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8000280a06010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8000280b06010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8000280b06010c3full)");
                break;
            }

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<uint64_t> (literal_0b0000, 48, 4, 60 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<uint64_t> (literal_0b0110, 48, 4, 60 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8000280b06010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8000280b06010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8000280c06010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8000280c06010c3full)");
                break;
            }

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<uint64_t> (literal_0b0000, 48, 4, 60 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<uint64_t> (literal_0b0110, 48, 4, 60 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8000280c06010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8000280c06010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8000280d06010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8000280d06010c3full)");
                break;
            }

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<uint64_t> (literal_0b0000, 48, 4, 60 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<uint64_t> (literal_0b0110, 48, 4, 60 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8000280d06010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8000280d06010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8000280e06010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8000280e06010c3full)");
                break;
            }

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<uint64_t> (literal_0b0000, 48, 4, 60 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<uint64_t> (literal_0b0110, 48, 4, 60 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8000280e06010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8000280e06010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8000280f06010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8000280f06010c3full)");
                break;
            }

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<uint64_t> (literal_0b0000, 48, 4, 60 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<uint64_t> (literal_0b0110, 48, 4, 60 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8000280f06010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8000280f06010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8000281006010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8000281006010c3full)");
                break;
            }

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<uint64_t> (literal_0b0000, 48, 4, 60 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<uint64_t> (literal_0b0110, 48, 4, 60 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8000281006010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8000281006010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8000281106010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8000281106010c3full)");
                break;
            }

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<uint64_t> (literal_0b0000, 48, 4, 60 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<uint64_t> (literal_0b0110, 48, 4, 60 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8000281106010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8000281106010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8000300006010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8000300006010c3full)");
                break;
            }

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<uint64_t> (literal_0b00000, 48, 5, 59 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<uint64_t> (literal_0b01100, 48, 5, 59 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8000300006010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8000300006010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8000300106010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8000300106010c3full)");
                break;
            }

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<uint64_t> (literal_0b00000, 48, 5, 59 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<uint64_t> (literal_0b01100, 48, 5, 59 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8000300106010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8000300106010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8000300206010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8000300206010c3full)");
                break;
            }

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<uint64_t> (literal_0b00000, 48, 5, 59 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<uint64_t> (literal_0b01100, 48, 5, 59 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8000300206010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8000300206010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8000300306010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8000300306010c3full)");
                break;
            }

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<uint64_t> (literal_0b00000, 48, 5, 59 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<uint64_t> (literal_0b01100, 48, 5, 59 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8000300306010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8000300306010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8000300406010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8000300406010c3full)");
                break;
            }

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<uint64_t> (literal_0b00000, 48, 5, 59 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<uint64_t> (literal_0b01100, 48, 5, 59 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8000300406010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8000300406010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8000300506010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8000300506010c3full)");
                break;
            }

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<uint64_t> (literal_0b00000, 48, 5, 59 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<uint64_t> (literal_0b01100, 48, 5, 59 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8000300506010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8000300506010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8000300606010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8000300606010c3full)");
                break;
            }

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<uint64_t> (literal_0b00000, 48, 5, 59 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<uint64_t> (literal_0b01100, 48, 5, 59 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8000300606010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8000300606010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8000300706010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8000300706010c3full)");
                break;
            }

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<uint64_t> (literal_0b00000, 48, 5, 59 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<uint64_t> (literal_0b01100, 48, 5, 59 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8000300706010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8000300706010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8000300806010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8000300806010c3full)");
                break;
            }

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<uint64_t> (literal_0b00000, 48, 5, 59 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<uint64_t> (literal_0b01100, 48, 5, 59 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8000300806010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8000300806010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8000300906010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8000300906010c3full)");
                break;
            }

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<uint64_t> (literal_0b00000, 48, 5, 59 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<uint64_t> (literal_0b01100, 48, 5, 59 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8000300906010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8000300906010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8000300a06010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8000300a06010c3full)");
                break;
            }

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<uint64_t> (literal_0b00000, 48, 5, 59 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<uint64_t> (literal_0b01100, 48, 5, 59 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8000300a06010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8000300a06010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8000300b06010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8000300b06010c3full)");
                break;
            }

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<uint64_t> (literal_0b00000, 48, 5, 59 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<uint64_t> (literal_0b01100, 48, 5, 59 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8000300b06010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8000300b06010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8000300c06010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8000300c06010c3full)");
                break;
            }

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<uint64_t> (literal_0b00000, 48, 5, 59 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<uint64_t> (literal_0b01100, 48, 5, 59 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8000300c06010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8000300c06010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8000300d06010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8000300d06010c3full)");
                break;
            }

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<uint64_t> (literal_0b00000, 48, 5, 59 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<uint64_t> (literal_0b01100, 48, 5, 59 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8000300d06010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8000300d06010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8000300e06010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8000300e06010c3full)");
                break;
            }

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<uint64_t> (literal_0b00000, 48, 5, 59 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<uint64_t> (literal_0b01100, 48, 5, 59 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8000300e06010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8000300e06010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8000300f06010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8000300f06010c3full)");
                break;
            }

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<uint64_t> (literal_0b00000, 48, 5, 59 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<uint64_t> (literal_0b01100, 48, 5, 59 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8000300f06010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8000300f06010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8000301006010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8000301006010c3full)");
                break;
            }

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<uint64_t> (literal_0b00000, 48, 5, 59 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<uint64_t> (literal_0b01100, 48, 5, 59 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8000301006010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8000301006010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8000301106010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8000301106010c3full)");
                break;
            }

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<uint64_t> (literal_0b00000, 48, 5, 59 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<uint64_t> (literal_0b01100, 48, 5, 59 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8000301106010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8000301106010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8000c00006010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8000c00006010c3full)");
                break;
            }

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<uint64_t> (literal_0b0000000, 48, 7, 57 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<uint64_t> (literal_0b0000011, 48, 7, 57 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8000c00006010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8000c00006010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8000c00106010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8000c00106010c3full)");
                break;
            }

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<uint64_t> (literal_0b0000000, 48, 7, 57 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<uint64_t> (literal_0b0000011, 48, 7, 57 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8000c00106010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8000c00106010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8000c00206010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8000c00206010c3full)");
                break;
            }

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<uint64_t> (literal_0b0000000, 48, 7, 57 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<uint64_t> (literal_0b0000011, 48, 7, 57 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8000c00206010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8000c00206010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8000c00306010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8000c00306010c3full)");
                break;
            }

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<uint64_t> (literal_0b0000000, 48, 7, 57 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<uint64_t> (literal_0b0000011, 48, 7, 57 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8000c00306010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8000c00306010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8000c00406010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8000c00406010c3full)");
                break;
            }

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<uint64_t> (literal_0b0000000, 48, 7, 57 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<uint64_t> (literal_0b0000011, 48, 7, 57 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8000c00406010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8000c00406010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8000c00506010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8000c00506010c3full)");
                break;
            }

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<uint64_t> (literal_0b0000000, 48, 7, 57 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<uint64_t> (literal_0b0000011, 48, 7, 57 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8000c00506010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8000c00506010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8000c00606010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8000c00606010c3full)");
                break;
            }

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<uint64_t> (literal_0b0000000, 48, 7, 57 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<uint64_t> (literal_0b0000011, 48, 7, 57 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8000c00606010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8000c00606010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8000c00706010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8000c00706010c3full)");
                break;
            }

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<uint64_t> (literal_0b0000000, 48, 7, 57 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<uint64_t> (literal_0b0000011, 48, 7, 57 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8000c00706010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8000c00706010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8000c00806010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8000c00806010c3full)");
                break;
            }

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<uint64_t> (literal_0b0000000, 48, 7, 57 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<uint64_t> (literal_0b0000011, 48, 7, 57 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8000c00806010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8000c00806010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8000c00906010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8000c00906010c3full)");
                break;
            }

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<uint64_t> (literal_0b0000000, 48, 7, 57 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<uint64_t> (literal_0b0000011, 48, 7, 57 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8000c00906010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8000c00906010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8000c00a06010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8000c00a06010c3full)");
                break;
            }

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<uint64_t> (literal_0b0000000, 48, 7, 57 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<uint64_t> (literal_0b0000011, 48, 7, 57 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8000c00a06010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8000c00a06010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8000c00b06010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8000c00b06010c3full)");
                break;
            }

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<uint64_t> (literal_0b0000000, 48, 7, 57 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<uint64_t> (literal_0b0000011, 48, 7, 57 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8000c00b06010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8000c00b06010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8000c00c06010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8000c00c06010c3full)");
                break;
            }

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<uint64_t> (literal_0b0000000, 48, 7, 57 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<uint64_t> (literal_0b0000011, 48, 7, 57 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8000c00c06010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8000c00c06010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8000c00d06010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8000c00d06010c3full)");
                break;
            }

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<uint64_t> (literal_0b0000000, 48, 7, 57 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<uint64_t> (literal_0b0000011, 48, 7, 57 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8000c00d06010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8000c00d06010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8000c00e06010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8000c00e06010c3full)");
                break;
            }

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<uint64_t> (literal_0b0000000, 48, 7, 57 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<uint64_t> (literal_0b0000011, 48, 7, 57 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8000c00e06010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8000c00e06010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8000c00f06010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8000c00f06010c3full)");
                break;
            }

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<uint64_t> (literal_0b0000000, 48, 7, 57 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<uint64_t> (literal_0b0000011, 48, 7, 57 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8000c00f06010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8000c00f06010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8000c01006010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8000c01006010c3full)");
                break;
            }

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<uint64_t> (literal_0b0000000, 48, 7, 57 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<uint64_t> (literal_0b0000011, 48, 7, 57 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8000c01006010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8000c01006010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8000c01106010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8000c01106010c3full)");
                break;
            }

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<uint64_t> (literal_0b0000000, 48, 7, 57 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<uint64_t> (literal_0b0000011, 48, 7, 57 );
            }

            l_rc = fapi2::putScom(TGT0, 0x8000c01106010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8000c01106010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8002200006010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8002200006010c3full)");
                break;
            }

            constexpr auto l_scom_buffer_OFF = 0x0;
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_OFF, 48, 1, 63 );
            l_rc = fapi2::putScom(TGT0, 0x8002200006010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8002200006010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8002200106010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8002200106010c3full)");
                break;
            }

            constexpr auto l_scom_buffer_OFF = 0x0;
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_OFF, 48, 1, 63 );
            l_rc = fapi2::putScom(TGT0, 0x8002200106010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8002200106010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8002200206010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8002200206010c3full)");
                break;
            }

            constexpr auto l_scom_buffer_OFF = 0x0;
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_OFF, 48, 1, 63 );
            l_rc = fapi2::putScom(TGT0, 0x8002200206010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8002200206010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8002200306010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8002200306010c3full)");
                break;
            }

            constexpr auto l_scom_buffer_OFF = 0x0;
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_OFF, 48, 1, 63 );
            l_rc = fapi2::putScom(TGT0, 0x8002200306010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8002200306010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8002200406010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8002200406010c3full)");
                break;
            }

            constexpr auto l_scom_buffer_OFF = 0x0;
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_OFF, 48, 1, 63 );
            l_rc = fapi2::putScom(TGT0, 0x8002200406010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8002200406010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8002200506010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8002200506010c3full)");
                break;
            }

            constexpr auto l_scom_buffer_OFF = 0x0;
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_OFF, 48, 1, 63 );
            l_rc = fapi2::putScom(TGT0, 0x8002200506010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8002200506010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8002200606010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8002200606010c3full)");
                break;
            }

            constexpr auto l_scom_buffer_OFF = 0x0;
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_OFF, 48, 1, 63 );
            l_rc = fapi2::putScom(TGT0, 0x8002200606010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8002200606010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8002200706010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8002200706010c3full)");
                break;
            }

            constexpr auto l_scom_buffer_OFF = 0x0;
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_OFF, 48, 1, 63 );
            l_rc = fapi2::putScom(TGT0, 0x8002200706010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8002200706010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8002200806010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8002200806010c3full)");
                break;
            }

            constexpr auto l_scom_buffer_OFF = 0x0;
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_OFF, 48, 1, 63 );
            l_rc = fapi2::putScom(TGT0, 0x8002200806010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8002200806010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8002200906010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8002200906010c3full)");
                break;
            }

            constexpr auto l_scom_buffer_OFF = 0x0;
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_OFF, 48, 1, 63 );
            l_rc = fapi2::putScom(TGT0, 0x8002200906010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8002200906010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8002200a06010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8002200a06010c3full)");
                break;
            }

            constexpr auto l_scom_buffer_OFF = 0x0;
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_OFF, 48, 1, 63 );
            l_rc = fapi2::putScom(TGT0, 0x8002200a06010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8002200a06010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8002200b06010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8002200b06010c3full)");
                break;
            }

            constexpr auto l_scom_buffer_OFF = 0x0;
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_OFF, 48, 1, 63 );
            l_rc = fapi2::putScom(TGT0, 0x8002200b06010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8002200b06010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8002200c06010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8002200c06010c3full)");
                break;
            }

            constexpr auto l_scom_buffer_OFF = 0x0;
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_OFF, 48, 1, 63 );
            l_rc = fapi2::putScom(TGT0, 0x8002200c06010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8002200c06010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8002200d06010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8002200d06010c3full)");
                break;
            }

            constexpr auto l_scom_buffer_OFF = 0x0;
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_OFF, 48, 1, 63 );
            l_rc = fapi2::putScom(TGT0, 0x8002200d06010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8002200d06010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8002200e06010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8002200e06010c3full)");
                break;
            }

            constexpr auto l_scom_buffer_OFF = 0x0;
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_OFF, 48, 1, 63 );
            l_rc = fapi2::putScom(TGT0, 0x8002200e06010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8002200e06010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8002200f06010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8002200f06010c3full)");
                break;
            }

            constexpr auto l_scom_buffer_OFF = 0x0;
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_OFF, 48, 1, 63 );
            l_rc = fapi2::putScom(TGT0, 0x8002200f06010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8002200f06010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8002201006010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8002201006010c3full)");
                break;
            }

            constexpr auto l_scom_buffer_OFF = 0x0;
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_OFF, 48, 1, 63 );
            l_rc = fapi2::putScom(TGT0, 0x8002201006010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8002201006010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8002201106010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8002201106010c3full)");
                break;
            }

            constexpr auto l_scom_buffer_ON = 0x1;
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_ON, 48, 1, 63 );
            l_rc = fapi2::putScom(TGT0, 0x8002201106010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8002201106010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8002c00006010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8002c00006010c3full)");
                break;
            }

            constexpr auto l_scom_buffer_PATTERN_24_A_0_15 = 0x1000;
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_PATTERN_24_A_0_15, 48, 16, 48 );
            l_rc = fapi2::putScom(TGT0, 0x8002c00006010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8002c00006010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8002c00106010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8002c00106010c3full)");
                break;
            }

            constexpr auto l_scom_buffer_PATTERN_24_B_0_15 = 0xf03e;
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_PATTERN_24_B_0_15, 48, 16, 48 );
            l_rc = fapi2::putScom(TGT0, 0x8002c00106010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8002c00106010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8002c00206010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8002c00206010c3full)");
                break;
            }

            constexpr auto l_scom_buffer_PATTERN_24_C_0_15 = 0x7bc;
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_PATTERN_24_C_0_15, 48, 16, 48 );
            l_rc = fapi2::putScom(TGT0, 0x8002c00206010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8002c00206010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8002c00306010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8002c00306010c3full)");
                break;
            }

            constexpr auto l_scom_buffer_PATTERN_24_D_0_15 = 0x7c7;
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_PATTERN_24_D_0_15, 48, 16, 48 );
            l_rc = fapi2::putScom(TGT0, 0x8002c00306010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8002c00306010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8002c00406010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8002c00406010c3full)");
                break;
            }

            constexpr auto l_scom_buffer_PATTERN_24_E_0_15 = 0x3ef;
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_PATTERN_24_E_0_15, 48, 16, 48 );
            l_rc = fapi2::putScom(TGT0, 0x8002c00406010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8002c00406010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8002c00506010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8002c00506010c3full)");
                break;
            }

            constexpr auto l_scom_buffer_PATTERN_24_F_0_15 = 0x1f0f;
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_PATTERN_24_F_0_15, 48, 16, 48 );
            l_rc = fapi2::putScom(TGT0, 0x8002c00506010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8002c00506010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8002c00606010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8002c00606010c3full)");
                break;
            }

            constexpr auto l_scom_buffer_PATTERN_24_G_0_15 = 0x1800;
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_PATTERN_24_G_0_15, 48, 16, 48 );
            l_rc = fapi2::putScom(TGT0, 0x8002c00606010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8002c00606010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8002c00706010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8002c00706010c3full)");
                break;
            }

            constexpr auto l_scom_buffer_PATTERN_24_H_0_15 = 0x9c00;
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_PATTERN_24_H_0_15, 48, 16, 48 );
            l_rc = fapi2::putScom(TGT0, 0x8002c00706010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8002c00706010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8002c00806010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8002c00806010c3full)");
                break;
            }

            constexpr auto l_scom_buffer_PATTERN_24_A_0_15 = 0x1000;
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_PATTERN_24_A_0_15, 48, 16, 48 );
            l_rc = fapi2::putScom(TGT0, 0x8002c00806010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8002c00806010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8002c00906010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8002c00906010c3full)");
                break;
            }

            constexpr auto l_scom_buffer_PATTERN_24_H_0_15 = 0x9c00;
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_PATTERN_24_H_0_15, 48, 16, 48 );
            l_rc = fapi2::putScom(TGT0, 0x8002c00906010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8002c00906010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8002c00a06010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8002c00a06010c3full)");
                break;
            }

            constexpr auto l_scom_buffer_PATTERN_24_G_0_15 = 0x1800;
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_PATTERN_24_G_0_15, 48, 16, 48 );
            l_rc = fapi2::putScom(TGT0, 0x8002c00a06010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8002c00a06010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8002c00b06010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8002c00b06010c3full)");
                break;
            }

            constexpr auto l_scom_buffer_PATTERN_24_F_0_15 = 0x1f0f;
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_PATTERN_24_F_0_15, 48, 16, 48 );
            l_rc = fapi2::putScom(TGT0, 0x8002c00b06010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8002c00b06010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8002c00c06010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8002c00c06010c3full)");
                break;
            }

            constexpr auto l_scom_buffer_PATTERN_24_E_0_15 = 0x3ef;
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_PATTERN_24_E_0_15, 48, 16, 48 );
            l_rc = fapi2::putScom(TGT0, 0x8002c00c06010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8002c00c06010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8002c00d06010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8002c00d06010c3full)");
                break;
            }

            constexpr auto l_scom_buffer_PATTERN_24_D_0_15 = 0x7c7;
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_PATTERN_24_D_0_15, 48, 16, 48 );
            l_rc = fapi2::putScom(TGT0, 0x8002c00d06010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8002c00d06010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8002c00e06010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8002c00e06010c3full)");
                break;
            }

            constexpr auto l_scom_buffer_PATTERN_24_C_0_15 = 0x7bc;
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_PATTERN_24_C_0_15, 48, 16, 48 );
            l_rc = fapi2::putScom(TGT0, 0x8002c00e06010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8002c00e06010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8002c00f06010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8002c00f06010c3full)");
                break;
            }

            constexpr auto l_scom_buffer_PATTERN_24_B_0_15 = 0xf03e;
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_PATTERN_24_B_0_15, 48, 16, 48 );
            l_rc = fapi2::putScom(TGT0, 0x8002c00f06010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8002c00f06010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8002c01006010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8002c01006010c3full)");
                break;
            }

            constexpr auto l_scom_buffer_PATTERN_24_A_0_15 = 0x1000;
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_PATTERN_24_A_0_15, 48, 16, 48 );
            l_rc = fapi2::putScom(TGT0, 0x8002c01006010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8002c01006010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8002c80006010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8002c80006010c3full)");
                break;
            }

            constexpr auto l_scom_buffer_PATTERN_24_A_16_22 = 0x42;
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_PATTERN_24_A_16_22, 48, 7, 57 );
            l_rc = fapi2::putScom(TGT0, 0x8002c80006010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8002c80006010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8002c80106010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8002c80106010c3full)");
                break;
            }

            constexpr auto l_scom_buffer_PATTERN_24_B_16_22 = 0x3e;
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_PATTERN_24_B_16_22, 48, 7, 57 );
            l_rc = fapi2::putScom(TGT0, 0x8002c80106010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8002c80106010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8002c80206010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8002c80206010c3full)");
                break;
            }

            constexpr auto l_scom_buffer_PATTERN_24_C_12_ACGH_16_22 = 0x0;
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_PATTERN_24_C_12_ACGH_16_22, 48, 7, 57 );
            l_rc = fapi2::putScom(TGT0, 0x8002c80206010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8002c80206010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8002c80306010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8002c80306010c3full)");
                break;
            }

            constexpr auto l_scom_buffer_PATTERN_24_D_16_22 = 0x60;
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_PATTERN_24_D_16_22, 48, 7, 57 );
            l_rc = fapi2::putScom(TGT0, 0x8002c80306010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8002c80306010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8002c80406010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8002c80406010c3full)");
                break;
            }

            constexpr auto l_scom_buffer_PATTERN_24_EF_16_22 = 0x40;
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_PATTERN_24_EF_16_22, 48, 7, 57 );
            l_rc = fapi2::putScom(TGT0, 0x8002c80406010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8002c80406010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8002c80506010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8002c80506010c3full)");
                break;
            }

            constexpr auto l_scom_buffer_PATTERN_24_EF_16_22 = 0x40;
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_PATTERN_24_EF_16_22, 48, 7, 57 );
            l_rc = fapi2::putScom(TGT0, 0x8002c80506010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8002c80506010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8002c80606010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8002c80606010c3full)");
                break;
            }

            constexpr auto l_scom_buffer_PATTERN_24_GH_16_22 = 0x3;
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_PATTERN_24_GH_16_22, 48, 7, 57 );
            l_rc = fapi2::putScom(TGT0, 0x8002c80606010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8002c80606010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8002c80706010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8002c80706010c3full)");
                break;
            }

            constexpr auto l_scom_buffer_PATTERN_24_GH_16_22 = 0x3;
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_PATTERN_24_GH_16_22, 48, 7, 57 );
            l_rc = fapi2::putScom(TGT0, 0x8002c80706010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8002c80706010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8002c80806010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8002c80806010c3full)");
                break;
            }

            constexpr auto l_scom_buffer_PATTERN_24_A_16_22 = 0x42;
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_PATTERN_24_A_16_22, 48, 7, 57 );
            l_rc = fapi2::putScom(TGT0, 0x8002c80806010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8002c80806010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8002c80906010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8002c80906010c3full)");
                break;
            }

            constexpr auto l_scom_buffer_PATTERN_24_GH_16_22 = 0x3;
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_PATTERN_24_GH_16_22, 48, 7, 57 );
            l_rc = fapi2::putScom(TGT0, 0x8002c80906010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8002c80906010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8002c80a06010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8002c80a06010c3full)");
                break;
            }

            constexpr auto l_scom_buffer_PATTERN_24_GH_16_22 = 0x3;
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_PATTERN_24_GH_16_22, 48, 7, 57 );
            l_rc = fapi2::putScom(TGT0, 0x8002c80a06010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8002c80a06010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8002c80b06010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8002c80b06010c3full)");
                break;
            }

            constexpr auto l_scom_buffer_PATTERN_24_EF_16_22 = 0x40;
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_PATTERN_24_EF_16_22, 48, 7, 57 );
            l_rc = fapi2::putScom(TGT0, 0x8002c80b06010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8002c80b06010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8002c80c06010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8002c80c06010c3full)");
                break;
            }

            constexpr auto l_scom_buffer_PATTERN_24_EF_16_22 = 0x40;
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_PATTERN_24_EF_16_22, 48, 7, 57 );
            l_rc = fapi2::putScom(TGT0, 0x8002c80c06010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8002c80c06010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8002c80d06010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8002c80d06010c3full)");
                break;
            }

            constexpr auto l_scom_buffer_PATTERN_24_D_16_22 = 0x60;
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_PATTERN_24_D_16_22, 48, 7, 57 );
            l_rc = fapi2::putScom(TGT0, 0x8002c80d06010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8002c80d06010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8002c80e06010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8002c80e06010c3full)");
                break;
            }

            constexpr auto l_scom_buffer_PATTERN_24_C_12_ACGH_16_22 = 0x0;
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_PATTERN_24_C_12_ACGH_16_22, 48, 7, 57 );
            l_rc = fapi2::putScom(TGT0, 0x8002c80e06010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8002c80e06010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8002c80f06010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8002c80f06010c3full)");
                break;
            }

            constexpr auto l_scom_buffer_PATTERN_24_B_16_22 = 0x3e;
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_PATTERN_24_B_16_22, 48, 7, 57 );
            l_rc = fapi2::putScom(TGT0, 0x8002c80f06010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8002c80f06010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8002c81006010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8002c81006010c3full)");
                break;
            }

            constexpr auto l_scom_buffer_PATTERN_24_A_16_22 = 0x42;
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_PATTERN_24_A_16_22, 48, 7, 57 );
            l_rc = fapi2::putScom(TGT0, 0x8002c81006010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8002c81006010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8004040006010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8004040006010c3full)");
                break;
            }

            constexpr auto l_scom_buffer_ENABLED = 0x0;
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_ENABLED, 48, 1, 63 );
            l_rc = fapi2::putScom(TGT0, 0x8004040006010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8004040006010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8004040106010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8004040106010c3full)");
                break;
            }

            constexpr auto l_scom_buffer_ENABLED = 0x0;
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_ENABLED, 48, 1, 63 );
            l_rc = fapi2::putScom(TGT0, 0x8004040106010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8004040106010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8004040206010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8004040206010c3full)");
                break;
            }

            constexpr auto l_scom_buffer_ENABLED = 0x0;
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_ENABLED, 48, 1, 63 );
            l_rc = fapi2::putScom(TGT0, 0x8004040206010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8004040206010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8004040306010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8004040306010c3full)");
                break;
            }

            constexpr auto l_scom_buffer_ENABLED = 0x0;
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_ENABLED, 48, 1, 63 );
            l_rc = fapi2::putScom(TGT0, 0x8004040306010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8004040306010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8004040406010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8004040406010c3full)");
                break;
            }

            constexpr auto l_scom_buffer_ENABLED = 0x0;
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_ENABLED, 48, 1, 63 );
            l_rc = fapi2::putScom(TGT0, 0x8004040406010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8004040406010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8004040506010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8004040506010c3full)");
                break;
            }

            constexpr auto l_scom_buffer_ENABLED = 0x0;
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_ENABLED, 48, 1, 63 );
            l_rc = fapi2::putScom(TGT0, 0x8004040506010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8004040506010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8004040606010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8004040606010c3full)");
                break;
            }

            constexpr auto l_scom_buffer_ENABLED = 0x0;
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_ENABLED, 48, 1, 63 );
            l_rc = fapi2::putScom(TGT0, 0x8004040606010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8004040606010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8004040706010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8004040706010c3full)");
                break;
            }

            constexpr auto l_scom_buffer_ENABLED = 0x0;
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_ENABLED, 48, 1, 63 );
            l_rc = fapi2::putScom(TGT0, 0x8004040706010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8004040706010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8004040806010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8004040806010c3full)");
                break;
            }

            constexpr auto l_scom_buffer_ENABLED = 0x0;
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_ENABLED, 48, 1, 63 );
            l_rc = fapi2::putScom(TGT0, 0x8004040806010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8004040806010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8004040906010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8004040906010c3full)");
                break;
            }

            constexpr auto l_scom_buffer_ENABLED = 0x0;
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_ENABLED, 48, 1, 63 );
            l_rc = fapi2::putScom(TGT0, 0x8004040906010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8004040906010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8004040a06010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8004040a06010c3full)");
                break;
            }

            constexpr auto l_scom_buffer_ENABLED = 0x0;
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_ENABLED, 48, 1, 63 );
            l_rc = fapi2::putScom(TGT0, 0x8004040a06010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8004040a06010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8004040b06010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8004040b06010c3full)");
                break;
            }

            constexpr auto l_scom_buffer_ENABLED = 0x0;
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_ENABLED, 48, 1, 63 );
            l_rc = fapi2::putScom(TGT0, 0x8004040b06010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8004040b06010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8004040c06010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8004040c06010c3full)");
                break;
            }

            constexpr auto l_scom_buffer_ENABLED = 0x0;
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_ENABLED, 48, 1, 63 );
            l_rc = fapi2::putScom(TGT0, 0x8004040c06010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8004040c06010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8004040d06010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8004040d06010c3full)");
                break;
            }

            constexpr auto l_scom_buffer_ENABLED = 0x0;
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_ENABLED, 48, 1, 63 );
            l_rc = fapi2::putScom(TGT0, 0x8004040d06010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8004040d06010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8004040e06010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8004040e06010c3full)");
                break;
            }

            constexpr auto l_scom_buffer_ENABLED = 0x0;
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_ENABLED, 48, 1, 63 );
            l_rc = fapi2::putScom(TGT0, 0x8004040e06010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8004040e06010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8004040f06010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8004040f06010c3full)");
                break;
            }

            constexpr auto l_scom_buffer_ENABLED = 0x0;
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_ENABLED, 48, 1, 63 );
            l_rc = fapi2::putScom(TGT0, 0x8004040f06010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8004040f06010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8004041006010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8004041006010c3full)");
                break;
            }

            constexpr auto l_scom_buffer_ENABLED = 0x0;
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_ENABLED, 48, 1, 63 );
            l_rc = fapi2::putScom(TGT0, 0x8004041006010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8004041006010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x80040c0006010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x80040c0006010c3full)");
                break;
            }

            constexpr auto l_scom_buffer_ON = 0x1;
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_ON, 62, 1, 63 );
            l_rc = fapi2::putScom(TGT0, 0x80040c0006010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x80040c0006010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x80040c0106010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x80040c0106010c3full)");
                break;
            }

            constexpr auto l_scom_buffer_ON = 0x1;
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_ON, 62, 1, 63 );
            l_rc = fapi2::putScom(TGT0, 0x80040c0106010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x80040c0106010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x80040c0206010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x80040c0206010c3full)");
                break;
            }

            constexpr auto l_scom_buffer_ON = 0x1;
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_ON, 62, 1, 63 );
            l_rc = fapi2::putScom(TGT0, 0x80040c0206010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x80040c0206010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x80040c0306010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x80040c0306010c3full)");
                break;
            }

            constexpr auto l_scom_buffer_ON = 0x1;
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_ON, 62, 1, 63 );
            l_rc = fapi2::putScom(TGT0, 0x80040c0306010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x80040c0306010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x80040c0406010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x80040c0406010c3full)");
                break;
            }

            constexpr auto l_scom_buffer_ON = 0x1;
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_ON, 62, 1, 63 );
            l_rc = fapi2::putScom(TGT0, 0x80040c0406010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x80040c0406010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x80040c0506010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x80040c0506010c3full)");
                break;
            }

            constexpr auto l_scom_buffer_ON = 0x1;
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_ON, 62, 1, 63 );
            l_rc = fapi2::putScom(TGT0, 0x80040c0506010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x80040c0506010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x80040c0606010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x80040c0606010c3full)");
                break;
            }

            constexpr auto l_scom_buffer_ON = 0x1;
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_ON, 62, 1, 63 );
            l_rc = fapi2::putScom(TGT0, 0x80040c0606010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x80040c0606010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x80040c0706010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x80040c0706010c3full)");
                break;
            }

            constexpr auto l_scom_buffer_ON = 0x1;
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_ON, 62, 1, 63 );
            l_rc = fapi2::putScom(TGT0, 0x80040c0706010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x80040c0706010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x80040c0806010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x80040c0806010c3full)");
                break;
            }

            constexpr auto l_scom_buffer_ON = 0x1;
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_ON, 62, 1, 63 );
            l_rc = fapi2::putScom(TGT0, 0x80040c0806010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x80040c0806010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x80040c0906010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x80040c0906010c3full)");
                break;
            }

            constexpr auto l_scom_buffer_ON = 0x1;
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_ON, 62, 1, 63 );
            l_rc = fapi2::putScom(TGT0, 0x80040c0906010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x80040c0906010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x80040c0a06010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x80040c0a06010c3full)");
                break;
            }

            constexpr auto l_scom_buffer_ON = 0x1;
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_ON, 62, 1, 63 );
            l_rc = fapi2::putScom(TGT0, 0x80040c0a06010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x80040c0a06010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x80040c0b06010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x80040c0b06010c3full)");
                break;
            }

            constexpr auto l_scom_buffer_ON = 0x1;
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_ON, 62, 1, 63 );
            l_rc = fapi2::putScom(TGT0, 0x80040c0b06010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x80040c0b06010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x80040c0c06010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x80040c0c06010c3full)");
                break;
            }

            constexpr auto l_scom_buffer_ON = 0x1;
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_ON, 62, 1, 63 );
            l_rc = fapi2::putScom(TGT0, 0x80040c0c06010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x80040c0c06010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x80040c0d06010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x80040c0d06010c3full)");
                break;
            }

            constexpr auto l_scom_buffer_ON = 0x1;
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_ON, 62, 1, 63 );
            l_rc = fapi2::putScom(TGT0, 0x80040c0d06010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x80040c0d06010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x80040c0e06010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x80040c0e06010c3full)");
                break;
            }

            constexpr auto l_scom_buffer_ON = 0x1;
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_ON, 62, 1, 63 );
            l_rc = fapi2::putScom(TGT0, 0x80040c0e06010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x80040c0e06010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x80040c0f06010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x80040c0f06010c3full)");
                break;
            }

            constexpr auto l_scom_buffer_ON = 0x1;
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_ON, 62, 1, 63 );
            l_rc = fapi2::putScom(TGT0, 0x80040c0f06010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x80040c0f06010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x80040c1006010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x80040c1006010c3full)");
                break;
            }

            constexpr auto l_scom_buffer_ON = 0x1;
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_ON, 62, 1, 63 );
            l_rc = fapi2::putScom(TGT0, 0x80040c1006010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x80040c1006010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x80043c0006010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x80043c0006010c3full)");
                break;
            }

            constexpr auto l_scom_buffer_PATTERN_TX_AB_HALF_A_0_15 = 0x0;
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_PATTERN_TX_AB_HALF_A_0_15, 48, 16, 48 );
            l_rc = fapi2::putScom(TGT0, 0x80043c0006010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x80043c0006010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x80043c0106010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x80043c0106010c3full)");
                break;
            }

            constexpr auto l_scom_buffer_PATTERN_TX_AB_HALF_A_0_15 = 0x0;
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_PATTERN_TX_AB_HALF_A_0_15, 48, 16, 48 );
            l_rc = fapi2::putScom(TGT0, 0x80043c0106010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x80043c0106010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x80043c0206010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x80043c0206010c3full)");
                break;
            }

            constexpr auto l_scom_buffer_PATTERN_TX_C_0_15 = 0x1e;
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_PATTERN_TX_C_0_15, 48, 16, 48 );
            l_rc = fapi2::putScom(TGT0, 0x80043c0206010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x80043c0206010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x80043c0306010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x80043c0306010c3full)");
                break;
            }

            constexpr auto l_scom_buffer_PATTERN_TX_D_0_15 = 0x1f;
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_PATTERN_TX_D_0_15, 48, 16, 48 );
            l_rc = fapi2::putScom(TGT0, 0x80043c0306010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x80043c0306010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x80043c0406010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x80043c0406010c3full)");
                break;
            }

            constexpr auto l_scom_buffer_PATTERN_TX_E_HALF_B_0_15 = 0xf;
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_PATTERN_TX_E_HALF_B_0_15, 48, 16, 48 );
            l_rc = fapi2::putScom(TGT0, 0x80043c0406010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x80043c0406010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x80043c0506010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x80043c0506010c3full)");
                break;
            }

            constexpr auto l_scom_buffer_PATTERN_TX_F_0_15 = 0x7c;
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_PATTERN_TX_F_0_15, 48, 16, 48 );
            l_rc = fapi2::putScom(TGT0, 0x80043c0506010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x80043c0506010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x80043c0606010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x80043c0606010c3full)");
                break;
            }

            constexpr auto l_scom_buffer_PATTERN_TX_G_0_15 = 0xc63;
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_PATTERN_TX_G_0_15, 48, 16, 48 );
            l_rc = fapi2::putScom(TGT0, 0x80043c0606010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x80043c0606010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x80043c0706010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x80043c0706010c3full)");
                break;
            }

            constexpr auto l_scom_buffer_PATTERN_TX_H_0_15 = 0xe73;
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_PATTERN_TX_H_0_15, 48, 16, 48 );
            l_rc = fapi2::putScom(TGT0, 0x80043c0706010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x80043c0706010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x80043c0806010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x80043c0806010c3full)");
                break;
            }

            constexpr auto l_scom_buffer_PATTERN_TX_AB_HALF_A_0_15 = 0x0;
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_PATTERN_TX_AB_HALF_A_0_15, 48, 16, 48 );
            l_rc = fapi2::putScom(TGT0, 0x80043c0806010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x80043c0806010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x80043c0906010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x80043c0906010c3full)");
                break;
            }

            constexpr auto l_scom_buffer_PATTERN_TX_H_0_15 = 0xe73;
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_PATTERN_TX_H_0_15, 48, 16, 48 );
            l_rc = fapi2::putScom(TGT0, 0x80043c0906010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x80043c0906010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x80043c0a06010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x80043c0a06010c3full)");
                break;
            }

            constexpr auto l_scom_buffer_PATTERN_TX_G_0_15 = 0xc63;
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_PATTERN_TX_G_0_15, 48, 16, 48 );
            l_rc = fapi2::putScom(TGT0, 0x80043c0a06010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x80043c0a06010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x80043c0b06010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x80043c0b06010c3full)");
                break;
            }

            constexpr auto l_scom_buffer_PATTERN_TX_F_0_15 = 0x7c;
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_PATTERN_TX_F_0_15, 48, 16, 48 );
            l_rc = fapi2::putScom(TGT0, 0x80043c0b06010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x80043c0b06010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x80043c0c06010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x80043c0c06010c3full)");
                break;
            }

            constexpr auto l_scom_buffer_PATTERN_TX_E_HALF_B_0_15 = 0xf;
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_PATTERN_TX_E_HALF_B_0_15, 48, 16, 48 );
            l_rc = fapi2::putScom(TGT0, 0x80043c0c06010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x80043c0c06010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x80043c0d06010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x80043c0d06010c3full)");
                break;
            }

            constexpr auto l_scom_buffer_PATTERN_TX_D_0_15 = 0x1f;
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_PATTERN_TX_D_0_15, 48, 16, 48 );
            l_rc = fapi2::putScom(TGT0, 0x80043c0d06010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x80043c0d06010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x80043c0e06010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x80043c0e06010c3full)");
                break;
            }

            constexpr auto l_scom_buffer_PATTERN_TX_C_0_15 = 0x1e;
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_PATTERN_TX_C_0_15, 48, 16, 48 );
            l_rc = fapi2::putScom(TGT0, 0x80043c0e06010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x80043c0e06010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x80043c0f06010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x80043c0f06010c3full)");
                break;
            }

            constexpr auto l_scom_buffer_PATTERN_TX_AB_HALF_A_0_15 = 0x0;
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_PATTERN_TX_AB_HALF_A_0_15, 48, 16, 48 );
            l_rc = fapi2::putScom(TGT0, 0x80043c0f06010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x80043c0f06010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x80043c1006010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x80043c1006010c3full)");
                break;
            }

            constexpr auto l_scom_buffer_PATTERN_TX_AB_HALF_A_0_15 = 0x0;
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_PATTERN_TX_AB_HALF_A_0_15, 48, 16, 48 );
            l_rc = fapi2::putScom(TGT0, 0x80043c1006010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x80043c1006010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8004440006010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8004440006010c3full)");
                break;
            }

            constexpr auto l_scom_buffer_PATTERN_TX_A_16_22 = 0x1;
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_PATTERN_TX_A_16_22, 48, 7, 57 );
            l_rc = fapi2::putScom(TGT0, 0x8004440006010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8004440006010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8004440106010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8004440106010c3full)");
                break;
            }

            constexpr auto l_scom_buffer_PATTERN_TX_B_16_22 = 0x7c;
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_PATTERN_TX_B_16_22, 48, 7, 57 );
            l_rc = fapi2::putScom(TGT0, 0x8004440106010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8004440106010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8004440206010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8004440206010c3full)");
                break;
            }

            constexpr auto l_scom_buffer_PATTERN_TX_C_16_22 = 0x7b;
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_PATTERN_TX_C_16_22, 48, 7, 57 );
            l_rc = fapi2::putScom(TGT0, 0x8004440206010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8004440206010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8004440306010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8004440306010c3full)");
                break;
            }

            constexpr auto l_scom_buffer_PATTERN_TX_DG_16_22 = 0xc;
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_PATTERN_TX_DG_16_22, 48, 7, 57 );
            l_rc = fapi2::putScom(TGT0, 0x8004440306010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8004440306010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8004440406010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8004440406010c3full)");
                break;
            }

            constexpr auto l_scom_buffer_PATTERN_TX_E_16_22 = 0x5e;
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_PATTERN_TX_E_16_22, 48, 7, 57 );
            l_rc = fapi2::putScom(TGT0, 0x8004440406010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8004440406010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8004440506010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8004440506010c3full)");
                break;
            }

            constexpr auto l_scom_buffer_PATTERN_TX_F_HALF_A_16_22 = 0x10;
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_PATTERN_TX_F_HALF_A_16_22, 48, 7, 57 );
            l_rc = fapi2::putScom(TGT0, 0x8004440506010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8004440506010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8004440606010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8004440606010c3full)");
                break;
            }

            constexpr auto l_scom_buffer_PATTERN_TX_DG_16_22 = 0xc;
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_PATTERN_TX_DG_16_22, 48, 7, 57 );
            l_rc = fapi2::putScom(TGT0, 0x8004440606010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8004440606010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8004440706010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8004440706010c3full)");
                break;
            }

            constexpr auto l_scom_buffer_PATTERN_TX_H_HALF_B_16_22 = 0x4e;
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_PATTERN_TX_H_HALF_B_16_22, 48, 7, 57 );
            l_rc = fapi2::putScom(TGT0, 0x8004440706010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8004440706010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8004440806010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8004440806010c3full)");
                break;
            }

            constexpr auto l_scom_buffer_PATTERN_TX_A_16_22 = 0x1;
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_PATTERN_TX_A_16_22, 48, 7, 57 );
            l_rc = fapi2::putScom(TGT0, 0x8004440806010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8004440806010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8004440906010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8004440906010c3full)");
                break;
            }

            constexpr auto l_scom_buffer_PATTERN_TX_H_HALF_B_16_22 = 0x4e;
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_PATTERN_TX_H_HALF_B_16_22, 48, 7, 57 );
            l_rc = fapi2::putScom(TGT0, 0x8004440906010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8004440906010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8004440a06010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8004440a06010c3full)");
                break;
            }

            constexpr auto l_scom_buffer_PATTERN_TX_DG_16_22 = 0xc;
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_PATTERN_TX_DG_16_22, 48, 7, 57 );
            l_rc = fapi2::putScom(TGT0, 0x8004440a06010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8004440a06010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8004440b06010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8004440b06010c3full)");
                break;
            }

            constexpr auto l_scom_buffer_PATTERN_TX_F_HALF_A_16_22 = 0x10;
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_PATTERN_TX_F_HALF_A_16_22, 48, 7, 57 );
            l_rc = fapi2::putScom(TGT0, 0x8004440b06010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8004440b06010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8004440c06010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8004440c06010c3full)");
                break;
            }

            constexpr auto l_scom_buffer_PATTERN_TX_E_16_22 = 0x5e;
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_PATTERN_TX_E_16_22, 48, 7, 57 );
            l_rc = fapi2::putScom(TGT0, 0x8004440c06010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8004440c06010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8004440d06010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8004440d06010c3full)");
                break;
            }

            constexpr auto l_scom_buffer_PATTERN_TX_DG_16_22 = 0xc;
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_PATTERN_TX_DG_16_22, 48, 7, 57 );
            l_rc = fapi2::putScom(TGT0, 0x8004440d06010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8004440d06010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8004440e06010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8004440e06010c3full)");
                break;
            }

            constexpr auto l_scom_buffer_PATTERN_TX_C_16_22 = 0x7b;
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_PATTERN_TX_C_16_22, 48, 7, 57 );
            l_rc = fapi2::putScom(TGT0, 0x8004440e06010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8004440e06010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8004440f06010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8004440f06010c3full)");
                break;
            }

            constexpr auto l_scom_buffer_PATTERN_TX_B_16_22 = 0x7c;
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_PATTERN_TX_B_16_22, 48, 7, 57 );
            l_rc = fapi2::putScom(TGT0, 0x8004440f06010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8004440f06010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8004441006010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8004441006010c3full)");
                break;
            }

            constexpr auto l_scom_buffer_PATTERN_TX_A_16_22 = 0x1;
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_PATTERN_TX_A_16_22, 48, 7, 57 );
            l_rc = fapi2::putScom(TGT0, 0x8004441006010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8004441006010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8008080006010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8008080006010c3full)");
                break;
            }

            l_scom_buffer.insert<uint64_t> (literal_0b000000, 48, 6, 58 );
            l_rc = fapi2::putScom(TGT0, 0x8008080006010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8008080006010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8008100006010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8008100006010c3full)");
                break;
            }

            constexpr auto l_scom_buffer_OFF = 0x0;
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_OFF, 48, 1, 63 );
            l_rc = fapi2::putScom(TGT0, 0x8008100006010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8008100006010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8008c00006010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8008c00006010c3full)");
                break;
            }

            constexpr auto l_scom_buffer_OFF = 0x0;
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_OFF, 55, 1, 63 );
            l_rc = fapi2::putScom(TGT0, 0x8008c00006010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8008c00006010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8009800006010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8009800006010c3full)");
                break;
            }

            l_scom_buffer.insert<uint64_t> (literal_0b0000000, 49, 7, 57 );
            l_rc = fapi2::putScom(TGT0, 0x8009800006010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8009800006010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8009900006010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8009900006010c3full)");
                break;
            }

            constexpr auto l_scom_buffer_ON = 0x1;
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_ON, 58, 1, 63 );
            l_rc = fapi2::putScom(TGT0, 0x8009900006010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8009900006010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8009980006010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8009980006010c3full)");
                break;
            }

            l_scom_buffer.insert<uint64_t> (literal_0b00001, 48, 5, 59 );
            l_rc = fapi2::putScom(TGT0, 0x8009980006010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8009980006010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8009b80006010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8009b80006010c3full)");
                break;
            }

            l_scom_buffer.insert<uint64_t> (literal_0b0010001, 48, 7, 57 );
            l_rc = fapi2::putScom(TGT0, 0x8009b80006010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8009b80006010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8009e00006010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8009e00006010c3full)");
                break;
            }

            l_scom_buffer.insert<uint64_t> (literal_0b0000000000000000, 48, 16, 48 );
            l_rc = fapi2::putScom(TGT0, 0x8009e00006010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8009e00006010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8009e80006010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8009e80006010c3full)");
                break;
            }

            l_scom_buffer.insert<uint64_t> (literal_0b01111111, 48, 8, 56 );
            l_rc = fapi2::putScom(TGT0, 0x8009e80006010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8009e80006010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x800b800006010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x800b800006010c3full)");
                break;
            }

            constexpr auto l_scom_buffer_OFF = 0x0;
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_OFF, 60, 1, 63 );
            l_rc = fapi2::putScom(TGT0, 0x800b800006010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x800b800006010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x800c040006010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x800c040006010c3full)");
                break;
            }

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<uint64_t> (literal_0b00, 56, 2, 62 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<uint64_t> (literal_0b01, 56, 2, 62 );
            }

            l_rc = fapi2::putScom(TGT0, 0x800c040006010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x800c040006010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x800c0c0006010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x800c0c0006010c3full)");
                break;
            }

            l_scom_buffer.insert<uint64_t> (literal_0b000000, 48, 6, 58 );
            l_rc = fapi2::putScom(TGT0, 0x800c0c0006010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x800c0c0006010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x800c140006010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x800c140006010c3full)");
                break;
            }

            constexpr auto l_scom_buffer_OFF = 0x0;
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_OFF, 48, 1, 63 );
            l_rc = fapi2::putScom(TGT0, 0x800c140006010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x800c140006010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x800c1c0006010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x800c1c0006010c3full)");
                break;
            }

            l_scom_buffer.insert<uint64_t> (literal_0b0010001, 56, 7, 57 );
            l_rc = fapi2::putScom(TGT0, 0x800c1c0006010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x800c1c0006010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x800c240006010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x800c240006010c3full)");
                break;
            }

            constexpr auto l_scom_buffer_DRV_0S = 0x0;
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_DRV_0S, 48, 2, 62 );
            l_rc = fapi2::putScom(TGT0, 0x800c240006010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x800c240006010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x800c840006010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x800c840006010c3full)");
                break;
            }

            l_scom_buffer.insert<uint64_t> (literal_0b0000000, 49, 7, 57 );
            l_rc = fapi2::putScom(TGT0, 0x800c840006010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x800c840006010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x800cec0006010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x800cec0006010c3full)");
                break;
            }

            l_scom_buffer.insert<uint64_t> (literal_0b0000000000000000, 48, 16, 48 );
            l_rc = fapi2::putScom(TGT0, 0x800cec0006010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x800cec0006010c3full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x800cf40006010c3full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x800cf40006010c3full)");
                break;
            }

            l_scom_buffer.insert<uint64_t> (literal_0b01111111, 48, 8, 56 );
            l_rc = fapi2::putScom(TGT0, 0x800cf40006010c3full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x800cf40006010c3full)");
                break;
            }
        }
    }
    while (0);

    return l_rc;
}
