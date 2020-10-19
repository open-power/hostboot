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

// libpldm
#include <openbmc/pldm/libpldm/pdr.h>
#include <openbmc/pldm/libpldm/platform.h>

// hostboot pldm
#include <pldm/extended/hb_pdrs.H>
#include <pldm/extended/pdr_manager.H>

// targeting
#include <targeting/common/target.H>
#include <targeting/common/predicates/predicatehwas.H>
#include <targeting/common/predicates/predicatectm.H>
#include <targeting/common/predicates/predicatepostfixexpr.H>
#include <targeting/common/iterators/rangefilter.H>
#include <targeting/common/targetservice.H>

class PldmPdrTestSuite : public CxxTest::TestSuite
{
public:
    void test_addHbPdrs()
    {
        TS_INFO("enter test_addHbPdrs");

        using repo_ptr = std::unique_ptr<pldm_pdr, decltype(&pldm_pdr_destroy)>;
        const repo_ptr repo { pldm_pdr_init(), pldm_pdr_destroy };

        PLDM::addHostbootPdrs(repo.get());

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

    void test_fruRecordSetIdLookup()
    {
        using namespace PLDM;
        using namespace TARGETING;

        TS_INFO("enter test_fruRecordSetIdLookup");

        PdrManager pdrmgr;

        pdrmgr.addLocalPdrs();

        const auto dimm_rsids = pdrmgr.findFruRecordSetIdsByType(ENTITY_TYPE_DIMM);

        TargetHandleList dimm_targets;

        { // collect a list of all the present DIMM targets in the system
            PredicateHwas l_predPres;
            l_predPres.present(true);
            PredicateCTM l_CtmFilter(CLASS_LOGICAL_CARD, TYPE_DIMM);
            PredicatePostfixExpr l_present;
            l_present.push(&l_CtmFilter).push(&l_predPres).And();
            TargetRangeFilter l_presTargetList(targetService().begin(),
                                               targetService().end(),
                                               &l_present);
            for ( ; l_presTargetList; ++l_presTargetList)
            {
                dimm_targets.push_back(*l_presTargetList);
            }
        }


        if (dimm_rsids.size() != dimm_targets.size())
        {
            TS_FAIL("test_fruRecordSetIdLookup: findFruRecordSetIdsByType(ENTITY_TYPE_DIMM) "
                    "returned %d RSIDs, expected %d",
                    static_cast<int>(dimm_rsids.size()),
                    static_cast<int>(dimm_targets.size()));
        }

        TS_INFO("exit test_fruRecordSetIdLookup");
    }
};

#endif
