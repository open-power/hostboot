/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/pldm/extended/test/test_pldm_pdr.H $                  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020,2023                        */
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
#include <openbmc/pldm/libpldm/include/libpldm/pdr.h>
#include <openbmc/pldm/libpldm/include/libpldm/platform.h>

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

        PLDM::PdrManager pdrmgr;

        addHostbootPdrs(pdrmgr);

        if (pdrmgr.pdrCount() == 0)
        {
            TS_FAIL("test_addHbPdrs: No PDRs added");
        }

        TS_INFO("exit test_addHbPdrs");
    }

    void test_fruRecordSetIdLookup()
    {
        using namespace PLDM;
        using namespace TARGETING;

        TS_INFO("enter test_fruRecordSetIdLookup");

        PLDM::PdrManager pdrmgr;
        addHostbootPdrs(pdrmgr);

        const auto dimm_rsids = pdrmgr.findFruRecordSetIdsByType(ENTITY_TYPE_DIMM);

        TargetHandleList ocmb_targets;

        { // collect a list of all the present OCMB targets in the system
            PredicateHwas l_predPres;
            l_predPres.present(true);
            PredicateCTM l_CtmFilter(CLASS_NA, TYPE_OCMB_CHIP);
            PredicatePostfixExpr l_present;
            l_present.push(&l_CtmFilter).push(&l_predPres).And();
            TargetRangeFilter l_presTargetList(targetService().begin(),
                                               targetService().end(),
                                               &l_present);
            for ( ; l_presTargetList; ++l_presTargetList)
            {
                ocmb_targets.push_back(*l_presTargetList);
            }
        }

        // We expect the number of DIMM FRU Record Sets to be the
        // number of OCMBs in the system. For Explorer, there's one
        // DIMM per OCMB = one DIMM per FRU; for Odyssey, there's two
        // DIMMs per OCMB = two DIMMs per FRU. The code should handle
        // either case and create only one FRU RSID per OCMB.
        if (dimm_rsids.size() != ocmb_targets.size())
        {
            TS_FAIL("test_fruRecordSetIdLookup: findFruRecordSetIdsByType(ENTITY_TYPE_DIMM) "
                    "returned %d RSIDs, expected %d (one per OCMB)",
                    static_cast<int>(dimm_rsids.size()),
                    static_cast<int>(ocmb_targets.size()));
        }

        TS_INFO("exit test_fruRecordSetIdLookup");
    }
};

#endif
