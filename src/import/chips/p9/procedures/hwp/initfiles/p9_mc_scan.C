/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/initfiles/p9_mc_scan.C $              */
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
#include "p9_mc_scan.H"
#include <stdint.h>
#include <stddef.h>
#include <fapi2.H>

using namespace fapi2;

constexpr auto literal_0b000000 = 0b000000;

fapi2::ReturnCode p9_mc_scan(const fapi2::Target<fapi2::TARGET_TYPE_MCBIST>& TGT0)
{
    fapi2::ReturnCode l_rc = 0;

    do
    {
        {
            fapi2::variable_buffer l_MC01_PORT0_ATCL_CL_CLSCOM_MCPERF0_PREFETCH_LIMIT(6);
            l_MC01_PORT0_ATCL_CL_CLSCOM_MCPERF0_PREFETCH_LIMIT.insertFromRight<uint64_t>(literal_0b000000, 0, 6);
            l_rc = fapi2::putSpy(TGT0, "MC01.PORT0.ATCL.CL.CLSCOM.MCPERF0_PREFETCH_LIMIT",
                                 l_MC01_PORT0_ATCL_CL_CLSCOM_MCPERF0_PREFETCH_LIMIT);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putSpy (MC01.PORT0.ATCL.CL.CLSCOM.MCPERF0_PREFETCH_LIMIT)");
                break;
            }
        }
        {
            fapi2::variable_buffer l_MC01_PORT1_ATCL_CL_CLSCOM_MCPERF0_PREFETCH_LIMIT(6);
            l_MC01_PORT1_ATCL_CL_CLSCOM_MCPERF0_PREFETCH_LIMIT.insertFromRight<uint64_t>(literal_0b000000, 0, 6);
            l_rc = fapi2::putSpy(TGT0, "MC01.PORT1.ATCL.CL.CLSCOM.MCPERF0_PREFETCH_LIMIT",
                                 l_MC01_PORT1_ATCL_CL_CLSCOM_MCPERF0_PREFETCH_LIMIT);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putSpy (MC01.PORT1.ATCL.CL.CLSCOM.MCPERF0_PREFETCH_LIMIT)");
                break;
            }
        }
        {
            fapi2::variable_buffer l_MC01_PORT2_ATCL_CL_CLSCOM_MCPERF0_PREFETCH_LIMIT(6);
            l_MC01_PORT2_ATCL_CL_CLSCOM_MCPERF0_PREFETCH_LIMIT.insertFromRight<uint64_t>(literal_0b000000, 0, 6);
            l_rc = fapi2::putSpy(TGT0, "MC01.PORT2.ATCL.CL.CLSCOM.MCPERF0_PREFETCH_LIMIT",
                                 l_MC01_PORT2_ATCL_CL_CLSCOM_MCPERF0_PREFETCH_LIMIT);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putSpy (MC01.PORT2.ATCL.CL.CLSCOM.MCPERF0_PREFETCH_LIMIT)");
                break;
            }
        }
        {
            fapi2::variable_buffer l_MC01_PORT3_ATCL_CL_CLSCOM_MCPERF0_PREFETCH_LIMIT(6);
            l_MC01_PORT3_ATCL_CL_CLSCOM_MCPERF0_PREFETCH_LIMIT.insertFromRight<uint64_t>(literal_0b000000, 0, 6);
            l_rc = fapi2::putSpy(TGT0, "MC01.PORT3.ATCL.CL.CLSCOM.MCPERF0_PREFETCH_LIMIT",
                                 l_MC01_PORT3_ATCL_CL_CLSCOM_MCPERF0_PREFETCH_LIMIT);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putSpy (MC01.PORT3.ATCL.CL.CLSCOM.MCPERF0_PREFETCH_LIMIT)");
                break;
            }
        }
    }
    while (0);

    return l_rc;
}
