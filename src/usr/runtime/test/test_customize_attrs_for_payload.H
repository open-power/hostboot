/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/runtime/test/test_customize_attrs_for_payload.H $     */
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

#ifndef __TEST_CUST_ATTRS_FOR_PAYLOAD_H
#define __TEST_CUST_ATTRS_FOR_PAYLOAD_H

/**
 *  @file test_customize_attrs_for_payload.H
 *
 */

#include <cxxtest/TestSuite.H>

#include <targeting/common/target.H>
#include <targeting/common/targetservice.H>
#include <targeting/common/utilFilter.H>
#include <attributeenums.H>
#include <errl/errlmanager.H>
#include <runtime/customize_attrs_for_payload.H>
#include <runtime/rt_targeting.H>
#include <targeting/common/attributes.H>
#include <runtime/runtime_reasoncodes.H>
#include <map>

namespace RT_TARG
{
    // Need to use the non-memoized version for some parts of the test
    // to avoid cacheing results.  We don't want this prototype generally
    // exported so declaring it here
    errlHndl_t _getHbTarget(
        const rtChipId_t          i_rtTargetId,
              TARGETING::Target*& o_target);
};

class CustomizeAttrsForPayloadTest: public CxxTest::TestSuite
{
  public:

    CustomizeAttrsForPayloadTest() :
        iv_configForPhyp(false),
        iv_pSys(NULL)
    {
    }

    void testGetHbTargetCommon(void)
    {
        TS_TRACE( ENTER_MRK
            "testGetHbTargetCommon> start" );

        errlHndl_t pError = NULL;

        do {

        TARGETING::Target* pTarget = NULL;
        auto rtTargetId = RUNTIME::HBRT_HYP_ID_UNKNOWN;

        pError = RT_TARG::getHbTarget(
            rtTargetId,
            pTarget);
        if(pError==NULL)
        {
            TS_FAIL("testGetHbTargetCommon> call to getHbTarget did not "
                "return error as expected");
            break;
        }

        delete pError;
        pError=NULL;

        if(pTarget != NULL)
        {
            TS_FAIL("testGetHbTargetCommon> call to getHbTarget returned "
                "error but output is not NULL");
            break;
        }

        } while(0);

        if(pError)
        {
            errlCommit(pError,RUNTIME_COMP_ID);
        }

        TS_TRACE( EXIT_MRK
            "testGetHbTargetCommon> finish" );
    }

    void testGetRtTargetCommon(void)
    {
        TS_TRACE( ENTER_MRK
            "testGetRtTargetCommon> start" );

        errlHndl_t pError = NULL;

        do {

        TARGETING::Target* pProc = NULL;
        pError = TARGETING::targetService().queryMasterProcChipTargetHandle(
            pProc);
        if(pError)
        {
            TS_FAIL("testGetRtTargetCommon> failed to get master proc chip ");
            break;
        }

        TARGETING::PredicateCTM isaPhb(
            TARGETING::CLASS_UNIT, TARGETING::TYPE_PHB);

        TARGETING::TargetHandleList phbs;
        TARGETING::targetService().getAssociated(
            phbs,
            pProc,
            TARGETING::TargetService::CHILD,
            TARGETING::TargetService::ALL,
            &isaPhb);
        if(phbs.empty())
        {
            TS_FAIL("testGetRtTargetCommon> failed to get any phb unit ");
            break;
        }

        TARGETING::Target* pTarget = phbs[0];
        auto rtTargetId = RUNTIME::HBRT_HYP_ID_UNKNOWN;

        pError = RT_TARG::getRtTarget(
            pTarget,
            rtTargetId);
        if(pError==NULL)
        {
            TS_FAIL("testGetRtTargetCommon> call to getRtTarget did not "
                "return error as expected");
            break;
        }

        delete pError;
        pError=NULL;

        if(rtTargetId != RUNTIME::HBRT_HYP_ID_UNKNOWN)
        {
            TS_FAIL("testGetRtTargetCommon> call to getRtTarget returned "
                "error but did not return the unknown value");
            break;
        }

        } while(0);

        if(pError)
        {
            errlCommit(pError,RUNTIME_COMP_ID);
        }

        TS_TRACE( EXIT_MRK
            "testGetRtTargetCommon> finish" );
    }

    void testGetRtAndHbTargetPhyp(void)
    {
        TS_TRACE( ENTER_MRK
            "testGetRtAndHbTargetPhyp> start" );
        validateGetRtAndHbTarget(true);
        TS_TRACE( EXIT_MRK
            "testGetRtAndHbTargetPhyp> finish" );
    }

    void testGetRtAndHbTargetNonPhyp(void)
    {
        TS_TRACE( ENTER_MRK
            "testGetRtAndHbTargetNonPhyp> start" );
        validateGetRtAndHbTarget(false);
        TS_TRACE( EXIT_MRK
            "testGetRtAndHbTargetNonPhyp> finish" );
    }

  private:

    void validateGetRtAndHbTarget(const bool i_configForPhyp)
    {
        TS_TRACE( ENTER_MRK
            "validateGetRtAndHbTarget> start (i_configForPhyp = %d)",
            i_configForPhyp );

        errlHndl_t pError = NULL;

        do {

        pError = overrideState(i_configForPhyp);
        if(pError)
        {
            TS_FAIL("validateGetRtAndHbTarget> failed to set "
                "ATTR_HBRT_HYP_IDs");
            break;
        }

        do {

        std::map< RT_TARG::rtChipId_t,size_t > uniqueRtTargetIds;

        const size_t FOUND_ONE_ID = 1;

        const TARGETING::TYPE targetingTargetTypes[] =
            {TARGETING::TYPE_CORE, TARGETING::TYPE_PROC,
             TARGETING::TYPE_MEMBUF};

        auto failed = false;
        for(TARGETING::TYPE targetingTargetType : targetingTargetTypes)
        {
            failed = true;
            TARGETING::TargetHandleList targets;
            TARGETING::getChildAffinityTargetsByState(
                targets,
                iv_pSys,
                TARGETING::CLASS_NA,
                targetingTargetType,
                TARGETING::UTIL_FILTER_ALL);
            if(targets.empty())
            {
                TS_TRACE("validateGetRtAndHbTarget> No targeting targets of "
                    "type 0x%08X found in the blueprint, skipping.",
                    targetingTargetType);
                failed = false;
                continue;
            }

            for(TARGETING::TargetHandleList::const_iterator pIt =
                    targets.begin();
                pIt != targets.end();
                ++pIt)
            {
                failed = true;
                TARGETING::Target* pTarget = (*pIt);

                auto rtTargetId = RUNTIME::HBRT_HYP_ID_UNKNOWN;
                pError = RT_TARG::getRtTarget(
                    pTarget,
                    rtTargetId);
                if(pError!=NULL)
                {
                    TS_FAIL("validateGetRtAndHbTarget> Failed call to "
                        "getRtTarget for targeting target with HUID of 0x%08X",
                        TARGETING::get_huid(pTarget));
                    break;
                }

                if(rtTargetId == RUNTIME::HBRT_HYP_ID_UNKNOWN)
                {
                    TS_FAIL("validateGetRtAndHbTarget> call to getRtTarget "
                        "returned unchanged runtime target ID");
                    break;
                }

                // Every runtime target ID better be unique.  Exception: for
                // PHyp payloads which operate on fused cores, there can be
                // at most 2 cores having same ID
                auto alreadyPresent = uniqueRtTargetIds.count(rtTargetId);
                if(alreadyPresent)
                {
                    if(   (i_configForPhyp)
                       && (targetingTargetType==TARGETING::TYPE_CORE)
                       && (uniqueRtTargetIds[rtTargetId] <= FOUND_ONE_ID))
                    {
                        uniqueRtTargetIds[rtTargetId]++;
                    }
                    else
                    {
                        TS_FAIL("Already saw runtime target ID of 0x%016llX",
                            rtTargetId);
                        break;
                    }
                }
                else
                {
                    uniqueRtTargetIds[rtTargetId]=FOUND_ONE_ID;
                }

                auto actualRtTargetId =
                    pTarget->getAttr<TARGETING::ATTR_HBRT_HYP_ID>();
                if(actualRtTargetId != rtTargetId)
                {
                    TS_FAIL("validateGetRtAndHbTarget> call to getRtTarget "
                        "returned runtime target ID of 0x%016llX which does "
                        "not match the targeting target's (HUID 0x%08x) "
                        "ATTR_HBRT_HYP_ID attribute value of 0x%016llX",
                        actualRtTargetId,TARGETING::get_huid(pTarget),
                        rtTargetId);
                    break;
                }

                // Call to other interface should return original target.
                TARGETING::Target* pActualTarget = NULL;
                // Need to bypass memoize to ensure results are not cached
                pError = RT_TARG::_getHbTarget(
                    actualRtTargetId,
                    pActualTarget);
                if(pError!=NULL)
                {
                    TS_FAIL("validateGetRtAndHbTarget> Failed call to "
                        "_getHbTarget for runtime target ID of 0x%016llX",
                        actualRtTargetId);
                    break;
                }

                if(pActualTarget == NULL)
                {
                    TS_FAIL("validateGetRtAndHbTarget> Call to "
                        "_getHbTarget returned NULL target for runtime target "
                        "ID of 0x%016llX",
                        actualRtTargetId);
                    break;
                }

                if(pActualTarget != pTarget)
                {
                    // Since Phyp deals with fused cores, and all cores per
                    // EX have the same ID, it's possible to get a different
                    // target back than the original target.  If that is the
                    // case, verify each core resolves to the same EX parent
                    auto realError = true;
                    if(   (i_configForPhyp)
                       && (targetingTargetType==TARGETING::TYPE_CORE))
                    {
                        auto exType = TARGETING::TYPE_EX;

                        const TARGETING::Target* pOrigEx =
                            TARGETING::getParent(pTarget,exType);
                        assert(pOrigEx != NULL);
                        const TARGETING::Target* pActualEx =
                            TARGETING::getParent(pActualTarget,exType);
                        assert(pActualEx != NULL);

                        if(pOrigEx == pActualEx)
                        {
                            TS_TRACE("Returned target (HUID 0x%08X) different "
                                "from original target (HUID 0x%08X), but this "
                                "is expected for PHyp payloads when all cores "
                                "under an ex have same ID",
                                TARGETING::get_huid(pActualTarget),
                                TARGETING::get_huid(pTarget));
                            realError = false;
                        }
                    }

                    if(realError)
                    {
                        TS_FAIL("validateGetRtAndHbTarget> _getHbTarget "
                            "returned successfully for runtime target ID of "
                            "0x%016llX but returned targeting target (HUID of "
                            "0x%08X) was not the original (HUID of 0x%08X)",
                            actualRtTargetId,get_huid(pActualTarget),
                            get_huid(pTarget));
                        break;
                    }
                }

                failed = false;
            }

            if(pError || failed)
            {
                break;
            }

            failed = false;
        }

        if(pError || failed)
        {
            break;
        }

        } while(0);

        restoreState(pError);

        } while(0);

        if(pError)
        {
            errlCommit(pError,RUNTIME_COMP_ID);
        }

        TS_TRACE( EXIT_MRK
            "validateGetRtAndHbTarget> finish" );
    }

    bool iv_configForPhyp;
    TARGETING::Target* iv_pSys;

    errlHndl_t overrideState(const bool i_configForPhyp)
    {
        errlHndl_t pError = NULL;

        do {

        TARGETING::Target* pSys = NULL;
        TARGETING::targetService().getTopLevelTarget(pSys);
        assert(pSys)
        iv_pSys = pSys;
        iv_configForPhyp = TARGETING::is_phyp_load();

        pError = RUNTIME::configureHbrtHypIds(i_configForPhyp);
        if(pError)
        {
            TS_FAIL("overrideState> failed to configure ATTR_HBRT_HYP_IDs. "
                "i_configForPhyp = %d",i_configForPhyp);
            break;
        }

        } while(0);

        return pError;
    }

    void restoreState(errlHndl_t& io_pError)
    {
        iv_pSys = NULL;
        errlHndl_t pError = RUNTIME::configureHbrtHypIds(iv_configForPhyp);
        if(pError)
        {
            TS_FAIL("restoreState> failed to reconfigure ATTR_HBRT_HYP_IDs. "
                "iv_configForPhyp = %d",iv_configForPhyp);
            if(!io_pError)
            {
                io_pError=pError;
                pError = NULL;
            }
            else
            {
                errlCommit(pError,RUNTIME_COMP_ID);
            }
        }
    }

};

#endif

