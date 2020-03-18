/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/pldm/extended/test/test_pldm_pdr.H $                  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020                             */
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

#ifndef __TEST_PLDM_PDR_EXTENDED
#define __TEST_PLDM_PDR_EXTENDED

#include <memory>

#include <cxxtest/TestSuite.H>

#include <pldm/extended/hb_pdrs.H>

#include "../../extern/pdr.h"
#include "../../extern/platform.h"

class PldmPdrTestSuite : public CxxTest::TestSuite
{
public:
    void test_addHbPdrs()
    {
        TS_INFO("enter test_addHbPdrs");

        using repo_ptr = std::unique_ptr<pldm_pdr, decltype(&pldm_pdr_destroy)>;
        const repo_ptr repo { pldm_pdr_init(), pldm_pdr_destroy };

        // Just use terminus 0, doesn't matter for the test
        const int terminus_id = 0;

        PLDM::addHostbootPdrs(repo.get(), terminus_id);

        const pldm_pdr_types pdrTypes[] =
        {
            PLDM_PDR_ENTITY_ASSOCIATION,
            PLDM_PDR_FRU_RECORD_SET
        };

        for (const auto pdrType : pdrTypes)
        {
            uint32_t pdrSize = 0;
            uint8_t* pdrData = nullptr;

            if (!pldm_pdr_find_record_by_type(repo.get(),
                                              pdrType,
                                              nullptr,
                                              &pdrData,
                                              &pdrSize))
            {
                TS_FAIL("test_addHbPdrs: no records of type %d", pdrType);
            }
        }

        TS_INFO("exit test_addHbPdrs");
    }
};

#endif
