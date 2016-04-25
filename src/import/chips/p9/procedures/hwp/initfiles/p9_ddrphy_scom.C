/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/initfiles/p9_ddrphy_scom.C $          */
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
#include "p9_ddrphy_scom.H"
#include <stdint.h>
#include <stddef.h>
#include <fapi2.H>

using namespace fapi2;

constexpr auto literal_0x0120 = 0x0120;
constexpr auto literal_0x6000 = 0x6000;
constexpr auto literal_0x4000 = 0x4000;
constexpr auto literal_0x7F7F = 0x7F7F;
constexpr auto literal_0xFFFF = 0xFFFF;
constexpr auto literal_0x5000 = 0x5000;
constexpr auto literal_0x4040 = 0x4040;
constexpr auto literal_0xE058 = 0xE058;
constexpr auto literal_0x4770 = 0x4770;

fapi2::ReturnCode p9_ddrphy_scom(const fapi2::Target<fapi2::TARGET_TYPE_MCA>& TGT0)
{
    fapi2::ReturnCode l_rc = 0;

    do
    {
        fapi2::buffer<uint64_t> l_scom_buffer;
        {
            l_rc = fapi2::getScom( TGT0, 0x800000030701103full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x800000030701103full)");
                break;
            }

            {
                if (( true ))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x0120, 48, 16, 48 );
                }
            }

            l_rc = fapi2::putScom(TGT0, 0x800000030701103full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x800000030701103full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x800000740701103full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x800000740701103full)");
                break;
            }

            {
                if (( true ))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x6000, 49, 7, 49 );
                }
            }

            l_rc = fapi2::putScom(TGT0, 0x800000740701103full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x800000740701103full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x800000750701103full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x800000750701103full)");
                break;
            }

            {
                if (( true ))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x4000, 48, 12, 48 );
                }
            }

            l_rc = fapi2::putScom(TGT0, 0x800000750701103full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x800000750701103full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x800000780701103full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x800000780701103full)");
                break;
            }

            {
                if (( true ))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x7F7F, 48, 16, 48 );
                }
            }

            l_rc = fapi2::putScom(TGT0, 0x800000780701103full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x800000780701103full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x800004030701103full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x800004030701103full)");
                break;
            }

            {
                if (( true ))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x0120, 48, 16, 48 );
                }
            }

            l_rc = fapi2::putScom(TGT0, 0x800004030701103full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x800004030701103full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x800004740701103full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x800004740701103full)");
                break;
            }

            {
                if (( true ))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x6000, 49, 7, 49 );
                }
            }

            l_rc = fapi2::putScom(TGT0, 0x800004740701103full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x800004740701103full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x800004750701103full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x800004750701103full)");
                break;
            }

            {
                if (( true ))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x4000, 48, 12, 48 );
                }
            }

            l_rc = fapi2::putScom(TGT0, 0x800004750701103full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x800004750701103full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x800004780701103full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x800004780701103full)");
                break;
            }

            {
                if (( true ))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x7F7F, 48, 16, 48 );
                }
            }

            l_rc = fapi2::putScom(TGT0, 0x800004780701103full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x800004780701103full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x800008030701103full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x800008030701103full)");
                break;
            }

            {
                if (( true ))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x0120, 48, 16, 48 );
                }
            }

            l_rc = fapi2::putScom(TGT0, 0x800008030701103full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x800008030701103full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x800008740701103full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x800008740701103full)");
                break;
            }

            {
                if (( true ))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x6000, 49, 7, 49 );
                }
            }

            l_rc = fapi2::putScom(TGT0, 0x800008740701103full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x800008740701103full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x800008750701103full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x800008750701103full)");
                break;
            }

            {
                if (( true ))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x4000, 48, 12, 48 );
                }
            }

            l_rc = fapi2::putScom(TGT0, 0x800008750701103full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x800008750701103full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x800008780701103full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x800008780701103full)");
                break;
            }

            {
                if (( true ))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x7F7F, 48, 16, 48 );
                }
            }

            l_rc = fapi2::putScom(TGT0, 0x800008780701103full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x800008780701103full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x80000c030701103full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x80000c030701103full)");
                break;
            }

            {
                if (( true ))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x0120, 48, 16, 48 );
                }
            }

            l_rc = fapi2::putScom(TGT0, 0x80000c030701103full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x80000c030701103full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x80000c740701103full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x80000c740701103full)");
                break;
            }

            {
                if (( true ))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x6000, 49, 7, 49 );
                }
            }

            l_rc = fapi2::putScom(TGT0, 0x80000c740701103full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x80000c740701103full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x80000c750701103full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x80000c750701103full)");
                break;
            }

            {
                if (( true ))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x4000, 48, 12, 48 );
                }
            }

            l_rc = fapi2::putScom(TGT0, 0x80000c750701103full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x80000c750701103full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x80000c780701103full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x80000c780701103full)");
                break;
            }

            {
                if (( true ))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x7F7F, 48, 16, 48 );
                }
            }

            l_rc = fapi2::putScom(TGT0, 0x80000c780701103full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x80000c780701103full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x800010030701103full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x800010030701103full)");
                break;
            }

            {
                if (( true ))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x0120, 48, 16, 48 );
                }
            }

            l_rc = fapi2::putScom(TGT0, 0x800010030701103full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x800010030701103full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x800010740701103full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x800010740701103full)");
                break;
            }

            {
                if (( true ))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x6000, 49, 7, 49 );
                }
            }

            l_rc = fapi2::putScom(TGT0, 0x800010740701103full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x800010740701103full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x800010750701103full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x800010750701103full)");
                break;
            }

            {
                if (( true ))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x4000, 48, 12, 48 );
                }
            }

            l_rc = fapi2::putScom(TGT0, 0x800010750701103full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x800010750701103full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x800010780701103full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x800010780701103full)");
                break;
            }

            {
                if (( true ))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x7F7F, 48, 16, 48 );
                }
            }

            l_rc = fapi2::putScom(TGT0, 0x800010780701103full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x800010780701103full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x800040000701103full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x800040000701103full)");
                break;
            }

            {
                if (( true ))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0xFFFF, 48, 16, 48 );
                }
            }

            l_rc = fapi2::putScom(TGT0, 0x800040000701103full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x800040000701103full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x800044000701103full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x800044000701103full)");
                break;
            }

            {
                if (( true ))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0xFFFF, 48, 16, 48 );
                }
            }

            l_rc = fapi2::putScom(TGT0, 0x800044000701103full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x800044000701103full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x800044010701103full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x800044010701103full)");
                break;
            }

            {
                if (( true ))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x5000, 48, 16, 48 );
                }
            }

            l_rc = fapi2::putScom(TGT0, 0x800044010701103full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x800044010701103full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x800044050701103full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x800044050701103full)");
                break;
            }

            {
                if (( true ))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x4040, 48, 16, 48 );
                }
            }

            l_rc = fapi2::putScom(TGT0, 0x800044050701103full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x800044050701103full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x800044070701103full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x800044070701103full)");
                break;
            }

            {
                if (( true ))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x4040, 48, 16, 48 );
                }
            }

            l_rc = fapi2::putScom(TGT0, 0x800044070701103full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x800044070701103full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x800048000701103full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x800048000701103full)");
                break;
            }

            {
                if (( true ))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0xFFFF, 48, 16, 48 );
                }
            }

            l_rc = fapi2::putScom(TGT0, 0x800048000701103full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x800048000701103full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x80004c000701103full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x80004c000701103full)");
                break;
            }

            {
                if (( true ))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0xFFFF, 48, 16, 48 );
                }
            }

            l_rc = fapi2::putScom(TGT0, 0x80004c000701103full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x80004c000701103full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x800080310701103full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x800080310701103full)");
                break;
            }

            {
                if (( true ))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0xE058, 48, 16, 48 );
                }
            }

            l_rc = fapi2::putScom(TGT0, 0x800080310701103full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x800080310701103full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x800080330701103full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x800080330701103full)");
                break;
            }

            {
                if (( true ))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x6000, 48, 16, 48 );
                }
            }

            l_rc = fapi2::putScom(TGT0, 0x800080330701103full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x800080330701103full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x800084310701103full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x800084310701103full)");
                break;
            }

            {
                if (( true ))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0xE058, 48, 16, 48 );
                }
            }

            l_rc = fapi2::putScom(TGT0, 0x800084310701103full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x800084310701103full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x800084330701103full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x800084330701103full)");
                break;
            }

            {
                if (( true ))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x6000, 48, 16, 48 );
                }
            }

            l_rc = fapi2::putScom(TGT0, 0x800084330701103full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x800084330701103full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x8000c4140701103full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x8000c4140701103full)");
                break;
            }

            {
                if (( true ))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x4770, 48, 16, 48 );
                }
            }

            l_rc = fapi2::putScom(TGT0, 0x8000c4140701103full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x8000c4140701103full)");
                break;
            }
        }
    }
    while (0);

    return l_rc;
}
