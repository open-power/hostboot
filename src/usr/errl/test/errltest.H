/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/errl/test/errltest.H $                                */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2014                        */
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
#ifndef __ERRLTEST_H
#define __ERRLTEST_H

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

#include "../../trace/entry.H"

#define TEST_SEVERITY       ERRORLOG::ERRL_SEV_INFORMATIONAL


#define TEST_USR_8BIT_1    0x80
#define TEST_USR_8BIT_2    0x93

#define TEST_USR_16BIT_1    0x8000
#define TEST_USR_16BIT_2    0x9003

#define TEST_USR_32BIT_1     0x80000001
#define TEST_USR_32BIT_2     0x90000003

#define TEST_USR_64BIT_1    0x8000000000000001
#define TEST_USR_64BIT_2    0x9000000000000003



class ErrlTest: public CxxTest::TestSuite
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
        bool fOK;
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
             * @moduleid    ERRORLOG::ERRL_TEST_MOD_ID
             * @devdesc     Errl test. Error with non-decoded string
             *              and lots of trace buffers.
             */

            // Create an error log
            errlHndl_t l_err = new ERRORLOG::ErrlEntry(
                                    ERRORLOG::ERRL_SEV_INFORMATIONAL,
                                    ERRORLOG::ERRL_TEST_MOD_ID,
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
            fOK = l_err->collectTrace(  "INITSVC" );
            if( !fOK )
            {
                TS_FAIL( "collectTrace(INITSVC) rets false." );
                break;
            }

            // Assuming trace buffers are 0x800 in size, and you're going
            // after a trace buffer that has wrapped, then a size almost as
            // big as the buffer will exercise the wrapping code in
            // trace::getBuffer()
            fOK = l_err->collectTrace(  "XSCOM" , 0x7D0 );
            if( !fOK )
            {
                TS_FAIL( "collectTrace(XSCOM) rets false." );
                break;
            }

            fOK = l_err->collectTrace(  "UNKNOWN"  );
            if( fOK )
            {
                TS_FAIL( "collectTrace(UNKNOWN) rets true" );
                break;
            }

            fOK = l_err->collectTrace("TARG",
                                      sizeof(TRACE::trace_buf_head_t)-2);
            if( fOK )
            {
                // expect an error, buffer not big enough
                TS_FAIL( "collectTrace(TARG,38) rets true" );
                break;
            }

            fOK = l_err->collectTrace("TARG",
                                      sizeof(TRACE::trace_buf_head_t));
            if( !fOK )
            {
                // Buffer is big enough for the header only. It is
                // supposed to work, although not terribly useful.
                TS_FAIL( "collectTrace(TARG,40) rets false" );
                break;
            }

            // sizeof( trace_buf_head_t ) + n bytes such that a single trace
            // entry cannot fit into.
            uint64_t l_cb = sizeof(TRACE::trace_buf_head_t) +
                            (sizeof(TRACE::trace_bin_entry_t)/2);
            fOK = l_err->collectTrace( "TARG", l_cb );
            if( !fOK )
            {
                // cb is big enough for the header only, but no
                // room for any entries.
                TS_FAIL( "collectTrace(TARG,l_cb) rets false", l_cb );
                break;
            }

            // Normal buffer sizes are 0x800 (2048), so passing
            // something bigger is not expected to be an error.
            fOK = l_err->collectTrace(  "TARG" , 4003 );
            if( !fOK )
            {
                TS_FAIL( "collectTrace(TARG,4003) rets false" );
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
                                ERRORLOG::ERRL_TEST_MOD_ID,
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
#if 1
        // these tests deconfigure and gard targets. and even tho they
        //  restore their state after the tests, since the cxxtests are
        //  all run in parallel, during the time that a target is non-
        //  functional due to this test, another test may be running that
        //  might be adversly affected.
        // tests are left in the code so that a developer can enable them
        //  to test these specific functions - just keep in mind that there
        //  could be side effects in other cxxtests.
        TS_TRACE( " - SKIPPING -- other tests could be adversly affected");
#else
        do
        {
            // find some ex units that we can play with
            TARGETING::Target * pSys;
            TARGETING::targetService().getTopLevelTarget(pSys);

            TARGETING::PredicateCTM predEx(TARGETING::CLASS_UNIT,
                                                TARGETING::TYPE_EX);
            TARGETING::PredicateHwas predFunctional;
            predFunctional.poweredOn(true).present(true).functional(true);
            TARGETING::PredicatePostfixExpr checkExpr;
            checkExpr.push(&predEx).push(&predFunctional).And();
            TARGETING::TargetHandleList pExList;
            TARGETING::targetService().getAssociated( pExList, pSys,
                TARGETING::TargetService::CHILD, TARGETING::TargetService::ALL,
                &checkExpr );

            if (pExList.empty())
            {
                TS_FAIL("testErrl3: empty pExList");
                break;
            }
            TARGETING::TargetHandle_t pTarget = *pExList.begin();

            errlHndl_t gard_errl = NULL;
            HWAS::DeconfigGard::DeconfigureRecords_t l_deconfigRecords;
            HWAS::DeconfigGard::GardRecords_t l_gardRecords;
            uint32_t deconfigCount = 0;
            uint32_t gardCount = 0;

            // make sure there aren't any existing deconfigure or gard records
            gard_errl = HWAS::theDeconfigGard()._getDeconfigureRecords(NULL,
                    l_deconfigRecords);
            if (gard_errl)
            {
                TS_FAIL("testErrl3: Error from _getDeconfigureRecords");
                errlCommit(gard_errl,HWAS_COMP_ID);
                break;
            }
            if (l_deconfigRecords.size() != 0)
            {
                TS_TRACE("testErrl3: %d existing Deconfigure Records, "
                            "skipping test", l_deconfigRecords.size());
                break;
            }

            gard_errl = HWAS::theDeconfigGard().getGardRecords(
                    NULL, l_gardRecords);
            if (gard_errl)
            {
                TS_FAIL("testErrl3: Error from getGardRecords");
                errlCommit(gard_errl,HWAS_COMP_ID);
                break;
            }
            if (l_gardRecords.size() != 0)
            {
                TS_TRACE("testErrl3: %d existing GARD Records, "
                            "skipping test", l_gardRecords.size());
                break;
            }

            // Create an error log
            errlHndl_t errl = new ERRORLOG::ErrlEntry(
                                    ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                    ERRORLOG::ERRL_TEST_MOD_ID,
                                    ERRORLOG::ERRL_TEST_REASON_CODE);

            // test the different callout types
            TS_TRACE("test callout target %.8X", TARGETING::get_huid(pTarget));
            ERRORLOG::ErrlUserDetailsTarget(pTarget).addToLog(errl);

            errl->addHwCallout(pTarget,
                    HWAS::SRCI_PRIORITY_LOW,
                    HWAS::DELAYED_DECONFIG,
                    HWAS::GARD_Fatal);
            deconfigCount++;
            gardCount++;

            errlCommit(errl, CXXTEST_COMP_ID);
            errl = new ERRORLOG::ErrlEntry(
                                    ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                    ERRORLOG::ERRL_TEST_MOD_ID,
                                    ERRORLOG::ERRL_TEST_REASON_CODE);

            errl->addHwCallout(pTarget,
                    HWAS::SRCI_PRIORITY_MED,
                    HWAS::DELAYED_DECONFIG,
                    HWAS::GARD_NULL);

            errlCommit(errl, CXXTEST_COMP_ID);
            errl = new ERRORLOG::ErrlEntry(
                                    ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                    ERRORLOG::ERRL_TEST_MOD_ID,
                                    ERRORLOG::ERRL_TEST_REASON_CODE);

            errl->addHwCallout(TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL,
                    HWAS::SRCI_PRIORITY_LOW,
                    HWAS::NO_DECONFIG,
                    HWAS::GARD_PHYP);
            gardCount++;

            errlCommit(errl, CXXTEST_COMP_ID);
            errl = new ERRORLOG::ErrlEntry(
                                    ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                    ERRORLOG::ERRL_TEST_MOD_ID,
                                    ERRORLOG::ERRL_TEST_REASON_CODE);

            errl->addHwCallout(TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL,
                    HWAS::SRCI_PRIORITY_MED,
                    HWAS::DELAYED_DECONFIG,
                    HWAS::GARD_NULL);
            deconfigCount++;

            errlCommit(errl, CXXTEST_COMP_ID);

            errl = new ERRORLOG::ErrlEntry(
                                    ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                    ERRORLOG::ERRL_TEST_MOD_ID,
                                    ERRORLOG::ERRL_TEST_REASON_CODE);

            errl->addProcedureCallout(
                    HWAS::EPUB_PRC_MEMORY_PLUGGING_ERROR,
                    HWAS::SRCI_PRIORITY_HIGH);

            errlCommit(errl, CXXTEST_COMP_ID);


            errl = new ERRORLOG::ErrlEntry(
                                    ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                    ERRORLOG::ERRL_TEST_MOD_ID,
                                    ERRORLOG::ERRL_TEST_REASON_CODE);

            errl->addClockCallout(
                pExList[0],
                HWAS::TODCLK_TYPE,
                HWAS::SRCI_PRIORITY_MED);

            // Clock callout using deconfig/GARD parameters
            errl->addClockCallout(
                pExList[0],
                HWAS::TODCLK_TYPE,
                HWAS::SRCI_PRIORITY_HIGH,
                HWAS::NO_DECONFIG,
                HWAS::GARD_NULL);

            // Part callout using deconfig/GARD parameters
            errl->addPartCallout(
                pExList[0],
                HWAS::PNOR_PART_TYPE,
                HWAS::SRCI_PRIORITY_HIGH,
                HWAS::NO_DECONFIG,
                HWAS::GARD_NULL);


            if (pExList.size() > 1)
            {
                errl->addBusCallout(
                    pExList[0],
                    pExList[1],
                    HWAS::A_BUS_TYPE,
                    HWAS::SRCI_PRIORITY_LOW);
            }

            errlCommit(errl, CXXTEST_COMP_ID);

            // confirm there are the correct number of deconfig and gard records
            gard_errl = HWAS::theDeconfigGard().getGardRecords(
                    NULL, l_gardRecords);
            if (gard_errl)
            {
                TS_FAIL("testCallout: Error from getGardRecords");
                errlCommit(gard_errl,HWAS_COMP_ID);
            }
            else if (l_gardRecords.size() != gardCount)
            {
                TS_TRACE("testCallout: %d GARD Records, expected %d",
                            l_gardRecords.size(), gardCount);
            }

            gard_errl = HWAS::theDeconfigGard()._getDeconfigureRecords(NULL,
                    l_deconfigRecords);
            if (gard_errl)
            {
                TS_FAIL("testCallout: Error from _getDeconfigureRecords");
                errlCommit(gard_errl,HWAS_COMP_ID);
            }
            else if (l_deconfigRecords.size() != deconfigCount)
            {
                TS_FAIL("testCallout: %d Deconfigure Records, expected %d",
                            l_deconfigRecords.size(), deconfigCount);
            }

            // delete these deconfigure and gard records
            HWAS::theDeconfigGard().clearDeconfigureRecords(NULL);
            gard_errl = HWAS::theDeconfigGard().clearGardRecords(NULL);
            if (gard_errl)
            {
                errlCommit(gard_errl,HWAS_COMP_ID);
                TS_FAIL("testCallout: Error from clearGardRecords");
            }
            TS_TRACE( "testErrl3 done");

        }
        while(0);
#endif
    }

    /**
     * @brief Test callouts
     */
    void testErrl4(void)
    {
        TS_TRACE( "test testErrl4");
#if 1
        // these tests deconfigure and gard targets. and even tho they
        //  restore their state after the tests, since the cxxtests are
        //  all run in parallel, during the time that a target is non-
        //  functional due to this test, another test may be running that
        //  might be adversly affected.
        // tests are left in the code so that a developer can enable them
        //  to test these specific functions - just keep in mind that there
        //  could be side effects in other cxxtests.
        TS_TRACE( " - SKIPPING -- other tests could be adversly affected");
#else
        do
        {
            // find a ex unit that we can play with
            TARGETING::Target * pSys;
            TARGETING::targetService().getTopLevelTarget(pSys);

            TARGETING::PredicateCTM predEx(TARGETING::CLASS_UNIT,
                                            TARGETING::TYPE_EX);
            TARGETING::PredicateHwas predFunctional;
            predFunctional.poweredOn(true).present(true).functional(true);
            TARGETING::PredicatePostfixExpr checkExpr;
            checkExpr.push(&predEx).push(&predFunctional).And();

            TARGETING::TargetHandleList pExList;
            TARGETING::targetService().getAssociated( pExList, pSys,
                TARGETING::TargetService::CHILD, TARGETING::TargetService::ALL,
                &checkExpr );

            if (pExList.empty())
            {
                TS_FAIL("test callout: empty pExList");
                break;
            }

            TARGETING::TargetHandle_t l_target = *pExList.begin();

            TARGETING::PredicateCTM l_L4s(TARGETING::CLASS_UNIT,
                                          TARGETING::TYPE_L4);

            TARGETING::TargetRangeFilter pL4(
                    TARGETING::targetService().begin(),
                    TARGETING::targetService().end(),
                    &l_L4s);

            // Create an error log
            errlHndl_t errl = new ERRORLOG::ErrlEntry(
                                    ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                    ERRORLOG::ERRL_TEST_MOD_ID,
                                    ERRORLOG::ERRL_TEST_REASON_CODE);

            // test the different callout types
            TS_TRACE( "test callout pEx %p", l_target);
            ERRORLOG::ErrlUserDetailsTarget(l_target).addToLog(errl);

            errl->addHwCallout(*pL4,
                    HWAS::SRCI_PRIORITY_HIGH,
                    HWAS::DECONFIG,
                    HWAS::GARD_NULL);

            // make this one high too - should end up with B120 src
            // as the first high priority callout is mem subsys
            errl->addHwCallout( l_target,
                    HWAS::SRCI_PRIORITY_HIGH,
                    HWAS::DECONFIG,
                    HWAS::GARD_NULL);

            errl->addProcedureCallout(
                    HWAS::EPUB_PRC_HB_CODE,
                    HWAS::SRCI_PRIORITY_HIGH);

            errlCommit(errl, CXXTEST_COMP_ID);

            TS_TRACE( "testErrl4 done");

        }
        while(0);
#endif
    }

    /**
     * @brief Test callouts
     */
    void testErrlr5(void)
    {
        TS_TRACE( "test testErrl5");
#if 1
        // these tests deconfigure and gard targets. and even tho they
        //  restore their state after the tests, since the cxxtests are
        //  all run in parallel, during the time that a target is non-
        //  functional due to this test, another test may be running that
        //  might be adversly affected.
        // tests are left in the code so that a developer can enable them
        //  to test these specific functions - just keep in mind that there
        //  could be side effects in other cxxtests.
        TS_TRACE( " - SKIPPING -- other tests could be adversly affected");
#else
        do
        {
            // find a ex unit that we can play with
            TARGETING::Target * pSys;
            TARGETING::targetService().getTopLevelTarget(pSys);

            TARGETING::PredicateCTM predEx(TARGETING::CLASS_UNIT,
                                            TARGETING::TYPE_EX);
            TARGETING::PredicateHwas predFunctional;
            predFunctional.poweredOn(true).present(true).functional(true);
            TARGETING::PredicatePostfixExpr checkExpr;
            checkExpr.push(&predEx).push(&predFunctional).And();

            TARGETING::TargetHandleList pExList;
            TARGETING::targetService().getAssociated( pExList, pSys,
                TARGETING::TargetService::CHILD, TARGETING::TargetService::ALL,
                &checkExpr );

            if (pExList.empty())
            {
                TS_FAIL("test callout: empty pExList");
                break;
            }

            TARGETING::TargetHandle_t l_target = *pExList.begin();

            // find a membuf target
            TARGETING::PredicateCTM membufChipFilter(
                    TARGETING::CLASS_CHIP,TARGETING::TYPE_MEMBUF);
            TARGETING::TargetRangeFilter pMembuf(
                    TARGETING::targetService().begin(),
                    TARGETING::targetService().end(),
                    &membufChipFilter);

            // Create an error log
            errlHndl_t errl = new ERRORLOG::ErrlEntry(
                                    ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                    ERRORLOG::ERRL_TEST_MOD_ID,
                                    ERRORLOG::ERRL_TEST_REASON_CODE);

            // test the different callout types
            TS_TRACE( "test callout pEx %p", l_target);
            ERRORLOG::ErrlUserDetailsTarget(l_target).addToLog(errl);

            errl->addHwCallout(*pMembuf,
                    HWAS::SRCI_PRIORITY_HIGH,
                    HWAS::DECONFIG,
                    HWAS::GARD_NULL);

            errl->addHwCallout(TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL,
                    HWAS::SRCI_PRIORITY_LOW,
                    HWAS::DECONFIG,
                    HWAS::GARD_NULL);

            errl->addProcedureCallout(
                    HWAS::EPUB_PRC_MEMORY_PLUGGING_ERROR,
                    HWAS::SRCI_PRIORITY_MED );

            errlCommit(errl, CXXTEST_COMP_ID);

            TS_TRACE( "testErrl5 done");

        }
        while(0);
#endif
    }

};

#endif
