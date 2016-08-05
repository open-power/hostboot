/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/initfiles/p9_mc_scan.C $   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016                             */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* Licensed under the Apache License, Version 2.0 (the "License");        */
/* you may not use this file except in compliance with the License.       */
/* You may obtain a copy of the License at                                */
/*                                                                        */
/*     http://www.apache.org/licenses/LICENSE-2.0                         */
/*                                                                        */
/* Unless required by applicable law or agreed to in writing, software    */
/* distributed under the License is distributed on an "AS IS" BASIS,      */
/* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or        */
/* implied. See the License for the specific language governing           */
/* permissions and limitations under the License.                         */
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
