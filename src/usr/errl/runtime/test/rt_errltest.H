/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/errl/runtime/test/rt_errltest.H $                     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2022                        */
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
#ifndef __RT_ERRLTEST_H
#define __RT_ERRLTEST_H

/**
 *  @file errltest.H
 *
 *  @brief Test case for Error Logging
*/

#include <cxxtest/TestSuite.H>
#include <errl/errlmanager.H>
#include <errl/errlentry.H>
#include <errl/errlreasoncodes.H>
#include <trace/trace.H>
#include <hbotcompid.H>

#include <errl/errludtarget.H>
#include <targeting/common/target.H>
#include <targeting/common/iterators/rangefilter.H>
#include <targeting/common/predicates/predicates.H>
#include <hwas/common/hwasCallout.H>
#include <hwas/common/deconfigGard.H>

#include "../../../trace/entry.H"

#define TEST_SEVERITY       ERRORLOG::ERRL_SEV_INFORMATIONAL


#define TEST_USR_8BIT_1    0x80
#define TEST_USR_8BIT_2    0x93

#define TEST_USR_16BIT_1    0x8000
#define TEST_USR_16BIT_2    0x9003

#define TEST_USR_32BIT_1     0x80000001
#define TEST_USR_32BIT_2     0x90000003

#define TEST_USR_64BIT_1    0x8000000000000001
#define TEST_USR_64BIT_2    0x9000000000000003



class RT_ErrlTest: public CxxTest::TestSuite
{
public:


    /**
     * @brief Test error log creation
     *  - Create an error log
     *  - Verify data of created log
     *  - Commit an error log
     *  - Delete an error log
     */
    void testErrl1(void)
    {
        ERRORLOG::ErrlUD * pffdc;

        // An example that shows how to use macros to stuff data into
        // the two 64-bit user data parameters in the error log.
        // l_userData1 = 16bit(0):l_bit8_1:l_bit8_2:l_32bit_1
        uint8_t l_8bit_1 = TEST_USR_8BIT_1;      // 0x80
        uint8_t l_8bit_2 = TEST_USR_8BIT_2;      // 0x93
        uint32_t l_32bit_1 = TEST_USR_32BIT_1;   // 0x80000001
        uint64_t l_userData1 =
          TWO_UINT32_TO_UINT64( TO_UINT32(TWO_UINT8_TO_UINT16(l_8bit_1, l_8bit_2)), l_32bit_1);
            // yields 0x0000809380000001


        // l_userData2 = l_16bit_1:l_16bit_2:l_32bit_2
        uint16_t l_16bit_1 = TEST_USR_16BIT_1;  // 0x8000
        uint16_t l_16bit_2 = TEST_USR_16BIT_2;  // 0x9003
        uint32_t l_32bit_2 = TEST_USR_32BIT_2;  // 0x90000003
        uint64_t l_userData2 = TWO_UINT16_ONE_UINT32_TO_UINT64(l_16bit_1, l_16bit_2, l_32bit_2);
            // yields 0x8000900390000003



        do
        {
            /*@
             * @errortype
             * @reasoncode  ERRORLOG::ERRL_TEST_REASON_CODE
             * @severity    ERRORLOG::ERRL_SEV_INFORMATIONAL
             * @moduleid    ERRORLOG::ERRL_RT_TEST_MOD_ID
             * @devdesc     Errl test. Error with non-decoded string
             *              and lots of trace buffers.
             * @custdesc    An internal firmware error occurred
             */

            // Create an error log
            errlHndl_t l_err = new ERRORLOG::ErrlEntry(
                                    ERRORLOG::ERRL_SEV_INFORMATIONAL,
                                    ERRORLOG::ERRL_RT_TEST_MOD_ID,
                                    ERRORLOG::ERRL_TEST_REASON_CODE,
                                    l_userData1,
                                    l_userData2);

            // These addFFDC() calls return a pointer to class ERRORLOG::ErrlFFDC
            // but errlffdc.H is not publicly includable to give me the definition
            // for it.  addFFDC() should return a Boolean indication of success.

            // really short user data
            const char * pch = "A";
            pffdc = l_err->addFFDC( DEVFW_COMP_ID, pch, strlen( pch ), 0, 0);
            if ( NULL == pffdc )
            {
                TS_FAIL("testErrl1: addFFDC() output NULL pointer");
                break;
            }

            // Append data to something already added.
            pch = " test-user-data-string";
            l_err->appendToFFDC( pffdc, pch, strlen(pch) );

            // Collect trace

            // Collect runtime trace and append to error log
            if( !l_err->collectTrace("DEVFW") )
            {
                TS_FAIL( "collectTrace(DEVFW) rets false." );
                break;
            }

            // Add null data.
            pffdc = l_err->addFFDC( ERRL_COMP_ID, NULL, 0,  9, 10 );
            if ( NULL != pffdc )
            {
                TS_FAIL("testErrl1: addFFDC() returned non null");
                break;
            }

            // Verify log data
            if (l_err->sev() != ERRORLOG::ERRL_SEV_INFORMATIONAL)
            {
                TS_FAIL("testErrl1: createErrlLog() returns incorrect severity!");
                break;
            }

            if (l_err->reasonCode() != ERRORLOG::ERRL_TEST_REASON_CODE)
            {
                TS_FAIL("testErrl1: createErrlLog() returns incorrect reason code!");
                break;
            }

            if (l_err->eventType() != ERRORLOG::ERRL_ETYPE_NOT_APPLICABLE)
            {
                TS_FAIL("testErrl1: createErrlLog() returns incorrect event type!");
                break;
            }

            if (l_err->subSys() != ERRORLOG::EPUB_FIRMWARE_SUBSYS )
            {
                TS_FAIL("testErrl1: createErrlLog() returns incorrect sub system!");
                break;
            }

            if (l_err->srcType() != ERRORLOG::SRC_ERR_INFO)
            {
                TS_FAIL("testErrl1: createErrlLog() returns incorrect SRC type!");
                break;
            }

            if (l_err->termState() != ERRORLOG::TERM_STATE_UNKNOWN)
            {
                TS_FAIL("testErrl1: termState() returns incorrect term state!");
                break;
            }



            // Commit error log with different component ID.
            errlCommit(l_err, CXXTEST_COMP_ID);

            // Make sure error log has been deleted by manager
            if (l_err != NULL)
            {
                TS_FAIL("testErrl1: commitErrLog() did not delete error!");
                break;
            }

        }
        while(0);
    }

    /**
     * @brief Test error log parameter settings
     */
    void testErrl2(void)
    {
        // An example that shows how to use macros to stuff data into
        // the two 64-bit user data parameters in the error log.
        // l_userData1 = l_bit32_1:l_bit32_2
        uint32_t l_32bit_1 = TEST_USR_32BIT_1;
        uint32_t l_32bit_2 = TEST_USR_32BIT_2;
        uint64_t l_userData1 = TWO_UINT32_TO_UINT64(l_32bit_1, l_32bit_2);

        // l_userData2 = 24bit(0):l_8bit_1:16bit(0):l_16bit_1
        uint8_t l_8bit_1 = TEST_USR_8BIT_1;
        uint16_t l_16bit_1 = TEST_USR_16BIT_1;
        uint64_t l_userData2 =
                TWO_UINT32_TO_UINT64(TO_UINT32(l_8bit_1), TO_UINT32(l_16bit_1));

        // Create an error log
        errlHndl_t l_err = new ERRORLOG::ErrlEntry(
                                ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                ERRORLOG::ERRL_RT_TEST_MOD_ID,
                                ERRORLOG::ERRL_TEST_REASON_CODE,
                                l_userData1,
                                l_userData2);

        // Set and verify log data
        l_err->setSev(ERRORLOG::ERRL_SEV_UNKNOWN);
        l_err->setEventType(ERRORLOG::ERRL_ETYPE_CAPACITY_UPGRADE);
        l_err->setSubSys(ERRORLOG::EPUB_UNKNOWN);
        l_err->setSrcType(ERRORLOG::SRC_ERR_INFO);
        l_err->setTermState(ERRORLOG::TERM_STATE_NO_FLAGS);

        if (l_err->sev() != ERRORLOG::ERRL_SEV_UNKNOWN)
        {
            TS_FAIL("testErrl2: setSev() fails!");
        }
        else if (l_err->eventType() != ERRORLOG::ERRL_ETYPE_CAPACITY_UPGRADE)
        {
            TS_FAIL("testErrl2: setEventType() fails!");
        }
        else if (l_err->subSys() != ERRORLOG::EPUB_UNKNOWN)
        {
            TS_FAIL("testErrl2: setSubSys() fails!");
        }
        else if (l_err->srcType() != ERRORLOG::SRC_ERR_INFO)
        {
            TS_FAIL("testErrl2: setSrcType() fails!");
        }
        else if (l_err->termState() != ERRORLOG::TERM_STATE_NO_FLAGS)
        {
             TS_FAIL("testErrl2: setTermState() fails!");
        }

        // Delete the log
        delete l_err;
        l_err = NULL;
    }

    /**
     * @brief Test callouts
     */
    void testErrl3(void)
    {
        TS_TRACE( "test testErrl3");
        do
        {
            // find some fc units that we can play with
            TARGETING::Target * pSys;
            TARGETING::targetService().getTopLevelTarget(pSys);

            TARGETING::PredicateCTM predFc(TARGETING::CLASS_UNIT,
                                                TARGETING::TYPE_FC);
            TARGETING::PredicateHwas predFunctional;
            predFunctional.poweredOn(true).present(true).functional(true);
            TARGETING::PredicatePostfixExpr checkExpr;
            checkExpr.push(&predFc).push(&predFunctional).And();
            TARGETING::TargetHandleList pFcList;
            TARGETING::targetService().getAssociated( pFcList, pSys,
                TARGETING::TargetService::CHILD, TARGETING::TargetService::ALL,
                &checkExpr );

            if (pFcList.empty())
            {
                TS_FAIL("testErrl3: empty pFcList");
                break;
            }
            TARGETING::TargetHandle_t pTarget = *pFcList.begin();

            // Create an error log
            errlHndl_t errl = new ERRORLOG::ErrlEntry(
                                    ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                    ERRORLOG::ERRL_RT_TEST_MOD_ID,
                                    ERRORLOG::ERRL_TEST_REASON_CODE);

            // test the different callout types
            TS_TRACE("test callout target %.8X", TARGETING::get_huid(pTarget));
            ERRORLOG::ErrlUserDetailsTarget(pTarget).addToLog(errl);

            errl->addHwCallout(pTarget,
                    HWAS::SRCI_PRIORITY_LOW,
                    HWAS::DELAYED_DECONFIG,
                    HWAS::GARD_Fatal);

            errl->addHwCallout(pTarget,
                    HWAS::SRCI_PRIORITY_MED,
                    HWAS::DELAYED_DECONFIG,
                    HWAS::GARD_NULL);

            errl->addHwCallout(pTarget,
                    HWAS::SRCI_PRIORITY_MED,
                    HWAS::DECONFIG,
                    HWAS::GARD_NULL);

            errl->addHwCallout(TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL,
                    HWAS::SRCI_PRIORITY_LOW,
                    HWAS::NO_DECONFIG,
                    HWAS::GARD_PHYP);

            errl->addHwCallout(TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL,
                    HWAS::SRCI_PRIORITY_MED,
                    HWAS::DELAYED_DECONFIG,
                    HWAS::GARD_NULL);

            errl->addProcedureCallout(
                    HWAS::EPUB_PRC_MEMORY_PLUGGING_ERROR,
                    HWAS::SRCI_PRIORITY_HIGH);

            errl->addClockCallout(
                pFcList[0],
                HWAS::TODCLK_TYPE,
                HWAS::SRCI_PRIORITY_MED);

            // Clock callout using deconfig/GARD parameters
            errl->addClockCallout(
                pFcList[0],
                HWAS::TODCLK_TYPE,
                HWAS::SRCI_PRIORITY_HIGH,
                HWAS::DECONFIG,
                HWAS::GARD_Fatal);

            if (pFcList.size() > 1)
            {
                errl->addBusCallout(
                    pFcList[0],
                    pFcList[1],
                    HWAS::A_BUS_TYPE,
                    HWAS::SRCI_PRIORITY_LOW);
            }

            errlCommit(errl, CXXTEST_COMP_ID);

            TS_TRACE( "testErrl3 done");

        }
        while(0);
    }
};

#endif
