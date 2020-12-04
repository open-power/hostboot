/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/errl/test/errltest.H $                                */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2020                        */
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
#include <targeting/namedtarget.H>
#include <targeting/common/iterators/rangefilter.H>
#include <targeting/common/predicates/predicates.H>
#include <hwas/common/hwasCallout.H>
#include <hwas/common/deconfigGard.H>
#include <targeting/common/utilFilter.H>

#include "../../trace/entry.H"
#include "../errlentry_consts.H"

#define TEST_SEVERITY       ERRORLOG::ERRL_SEV_INFORMATIONAL


#define TEST_USR_8BIT_1    0x80
#define TEST_USR_8BIT_2    0x93

#define TEST_USR_16BIT_1    0x8000
#define TEST_USR_16BIT_2    0x9003

#define TEST_USR_32BIT_1     0x80000001
#define TEST_USR_32BIT_2     0x90000003

#define TEST_USR_64BIT_1    0x8000000000000001
#define TEST_USR_64BIT_2    0x9000000000000003


namespace ERRORLOG
{

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

    /**
     * @brief Test ECIDs in callouts
     */
    void testErrl6(void)
    {
        TS_TRACE( "test testErrl6");
#if 1
        //  all run in parallel, during the time that a target is non-
        //  functional due to this test, another test may be running that
        //  might be adversly affected.
        //  tests are left in the code so that a developer can enable them
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

            TS_TRACE( "test callout pEx %p", l_target);
            ERRORLOG::ErrlUserDetailsTarget(l_target).addToLog(errl);

            //HW callout with Membuf target, after ECID has been read.
            // ECID should be present
            errl->addHwCallout(*pMembuf,
                   HWAS::SRCI_PRIORITY_HIGH,
                   HWAS::NO_DECONFIG,
                   HWAS::GARD_NULL);
            uint64_t l_ecid[2];
            (*pMembuf)->tryGetAttr<TARGETING::ATTR_ECID>(l_ecid);
            bool correctECID = containsEcidData(errl,l_ecid);
            if(!correctECID)
            {
                TS_FAIL("testErrl6: ECID value incorrect from target %p",
                       (*pMembuf));
                break;
            }

            errlCommit(errl, CXXTEST_COMP_ID);
            errl = new ERRORLOG::ErrlEntry(
                            ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                            ERRORLOG::ERRL_TEST_MOD_ID,
                            ERRORLOG::ERRL_TEST_REASON_CODE);


            //Hw callout with non-proc and non-membuf target before
            // ECID has been read. ECID should be present for parent target.
            // We have to find the parent target, and get the ecid value
            // before calling the containsEcidData() checker function.
            const TARGETING::Target* l_parentTarget = getParentChip(l_target);
            (l_parentTarget)->tryGetAttr<TARGETING::ATTR_ECID>(l_ecid);

            errl->addHwCallout(l_target,
                   HWAS::SRCI_PRIORITY_HIGH,
                   HWAS::NO_DECONFIG,
                   HWAS::GARD_NULL);
            correctECID = containsEcidData(errl,l_ecid);
            if(!correctECID)
            {
                TS_FAIL("testErrl6: ECID value incorrect from target %p",
                       (l_target));
                break;
            }

            errlCommit(errl,CXXTEST_COMP_ID);

            TS_TRACE("testErrl6 done");
        }
        while(0);
#endif
    }
    bool containsEcidData(errlHndl_t &i_errl, uint64_t* i_ecidOrig)
    {
        TS_TRACE("containsEcidData errlogId 0x%.8x",i_errl->eid());
        bool l_dataMatching = false;
        uint32_t* l_ecid_data = NULL;

        // look thru the errlog for any Attribute UserDetail sections
        //  to find the ecid data, check that it matches the
        //  expected value and return true or false.
        for(std::vector<ERRORLOG::ErrlUD*>::const_iterator
                it = i_errl->iv_SectionVector.begin();
                it != i_errl->iv_SectionVector.end();
                it++ )
        {
            l_ecid_data = (uint32_t *)((*it)->iv_pData);

            //look for an ATTR_ECID section
            if((ERRL_COMP_ID     == (*it)->iv_header.iv_compId) &&
               (1                == (*it)->iv_header.iv_ver) &&
               (ERRORLOG::ERRL_UDT_ATTRIBUTE == (*it)->iv_header.iv_sst) &&
               (TARGETING::ATTR_ECID         == l_ecid_data[0])
              )
            {
                uint64_t l_ecidCompare[2] = {l_ecid_data[1],l_ecid_data[3]};
                l_ecidCompare[0] = (l_ecidCompare[0] << 32) | l_ecid_data[2];
                l_ecidCompare[1] = (l_ecidCompare[1] << 32) | l_ecid_data[4];
                if((l_ecidCompare[0] == i_ecidOrig[0]) &&
                   (l_ecidCompare[1] == i_ecidOrig[1]))
                {
                    l_dataMatching = true;
                    break;
                }
            }
        }

        TS_TRACE("containsEcidData");
        return l_dataMatching;
    }

   /**
     * @brief Test CORE callout
     */
    void testErrl7(void)
    {
        TS_TRACE( "test testErrl7");
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
            // find a core unit that we can play with
            TARGETING::Target * pSys;
            TARGETING::targetService().getTopLevelTarget(pSys);

            TARGETING::PredicateCTM predCore(TARGETING::CLASS_UNIT,
                                           TARGETING::TYPE_CORE);
            TARGETING::PredicateHwas predFunctional;
            predFunctional.poweredOn(true).present(true).functional(true);
            TARGETING::PredicatePostfixExpr checkExpr;
            checkExpr.push(&predCore).push(&predFunctional).And();

            TARGETING::TargetHandleList l_coreList;
            TARGETING::targetService().getAssociated( l_coreList, pSys,
                TARGETING::TargetService::CHILD, TARGETING::TargetService::ALL,
                &checkExpr );

            if (l_coreList.empty())
            {
                TS_FAIL("test callout: empty l_coreList");
                break;
            }

            TARGETING::TargetHandle_t l_target = *l_coreList.begin();

            // Create an error log
            errlHndl_t errl = new ERRORLOG::ErrlEntry(
                                    ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                    ERRORLOG::ERRL_TEST_MOD_ID,
                                    ERRORLOG::ERRL_TEST_REASON_CODE);

            // test the different callout types
            TS_TRACE( "test callout l_core %p", l_target);
            ERRORLOG::ErrlUserDetailsTarget(l_target).addToLog(errl);

            errl->addHwCallout(l_target,
                    HWAS::SRCI_PRIORITY_HIGH,
                    HWAS::DECONFIG,
                    HWAS::GARD_User_Manual);

            errlCommit(errl, CXXTEST_COMP_ID);

            TS_TRACE("testErrl7 done");
        }
        while(0);
#endif
    }
        /**
     *  @brief Test No Gard on Informational error logs
     */
    void testdeconfigNoGardInformational()
    {
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

            TARGETING::PredicateCTM predEx(TARGETING::CLASS_UNIT, TARGETING::TYPE_EX);
            TARGETING::PredicateHwas predFunctional;
            predFunctional.poweredOn(true).present(true).functional(true);
            TARGETING::PredicatePostfixExpr checkExpr;
            checkExpr.push(&predEx).push(&predFunctional).And();
            TARGETING::TargetHandleList pExList;
            TARGETING::targetService().getAssociated( pExList, pSys,
                TARGETING::TargetService::CHILD, TARGETING::TargetService::ALL, &checkExpr );

            if (pExList.empty())
            {
                TS_FAIL("testdeconfigNoGardInformational: empty pExList");
                break;
            }

            errlHndl_t errl = NULL;
            HWAS::DeconfigGard::DeconfigureRecords_t l_deconfigRecords;
            HWAS::DeconfigGard::GardRecords_t l_gardRecords;
            HWAS::DeconfigGard::DeconfigureRecords_t l_deconfigRecordsAfter;
            HWAS::DeconfigGard::GardRecords_t l_gardRecordsAfter;

            // make sure there aren't any existing deconfigure or gard records
            errl = HWAS::theDeconfigGard()._getDeconfigureRecords(NULL,
                    l_deconfigRecords);
            if (errl)
            {
                TS_FAIL("testdeconfigNoGardInformational: Error from "
                    "_getDeconfigureRecords");
                errlCommit(errl,HWAS_COMP_ID);
                break;
            }
            if (l_deconfigRecords.size() != 0)
            {
                TS_INFO("testdeconfigNoGardInformational: %d existing "
                    "Deconfigure Records, skipping test",
                    l_deconfigRecords.size());
                break;
            }

            errl = HWAS::theDeconfigGard().getGardRecords(
                    NULL, l_gardRecords);
            if (errl)
            {
                TS_FAIL("testdeconfigNoGardInformational: Error from "
                    "getGardRecords");
                errlCommit(errl,HWAS_COMP_ID);
                break;
            }
            if (l_gardRecords.size() != 0)
            {
                TS_INFO("testdeconfigNoGardInformational: %d existing "
                    "GARD Records, skipping test", l_gardRecords.size());
                break;
            }

            errl = new ERRORLOG::ErrlEntry(
                                    ERRORLOG::ERRL_SEV_INFORMATIONAL,
                                    ERRORLOG::ERRL_TEST_MOD_ID,
                                    ERRORLOG::ERRL_TEST_REASON_CODE);


            // Part callout using deconfig/GARD parameters
            errl->addHwCallout(
                pExList[0],
                HWAS::SRCI_PRIORITY_LOW,
                HWAS::DECONFIG,
                HWAS::GARD_Fatal);

            errlCommit(errl, CXXTEST_COMP_ID);

            // Flush out errorlogs so we make sure deconfigs/gards are logged
            // before we check for them
            ERRORLOG::ErrlManager::callFlushErrorLogs();

            // Check gard and deconfigs - should be none.
            errlHndl_t gard_errl = NULL;

            gard_errl = HWAS::theDeconfigGard()._getDeconfigureRecords(NULL,
                        l_deconfigRecordsAfter);

            if (gard_errl)
            {
                TS_FAIL("testdeconfigNoGardInformational: Error from "
                    "_getDeconfigureRecords - post deconfigs");
                errlCommit(errl,HWAS_COMP_ID);
                break;
            }
            if (l_deconfigRecordsAfter.size() != l_deconfigRecords.size())
            {
                TS_INFO("testdeconfigNoGardInformational: %d "
                    "Deconfigure Records, expecting none. TEST FAILED",
                    l_deconfigRecordsAfter.size());
                TS_FAIL("testdeconfigNoGardInformational: Deconfig records "
                    "present, expecting none.");
                break;
            }

            gard_errl = HWAS::theDeconfigGard().getGardRecords(
                    NULL, l_gardRecordsAfter);

            if (gard_errl)
            {
                TS_FAIL("testdeconfigNoGardInformational: Error from "
                    "getGardRecords - post deconfigs");
                errlCommit(errl,HWAS_COMP_ID);
                break;
            }
            if (l_gardRecords.size() != l_gardRecordsAfter.size())
            {
                TS_INFO("testdeconfigNoGardInformational: %d GARD Records "
                    "present, expecting none. TEST FAILED",
                    l_gardRecordsAfter.size());
                TS_FAIL("testdeconfigNoGardInformational: GARD records "
                    "present, expecting none.");
                break;
            }
        }while(0);
#endif
    }

   /**
     * @brief Guarantee TARGET_TO_SUBSYS_TABLE is in order
     */
    void testErrl_subsysOrder(void)
    {
        // TARGET_TO_SUBSYS_TABLE must be sorted by type, this
        //  test ensures that is true
        TARGETING::TYPE l_lastType = TARGET_TO_SUBSYS_TABLE[0].xType;
        for( size_t i = 1; //start on 2nd entry
             i < (sizeof(TARGET_TO_SUBSYS_TABLE)/
                  sizeof(TARGET_TO_SUBSYS_TABLE[0]));
             i++ )
        {
            if( TARGET_TO_SUBSYS_TABLE[i].xType < l_lastType )
            {
                TS_FAIL( "testErrl_subsysOrder> %d is out of order",
                         TARGET_TO_SUBSYS_TABLE[i].xType );
            }
            l_lastType = TARGET_TO_SUBSYS_TABLE[i].xType;
        }
    }


    /**
     * @brief Guarantee non-visible logs do not post callouts
     */
    void testErrl_hidecallouts(void)
    {
        // Find a non-master core that is currently functional
        TARGETING::TargetHandleList l_cores;
        TARGETING::getAllChiplets( l_cores, TARGETING::TYPE_CORE, true );
        TARGETING::Target* l_victim = nullptr;
        const TARGETING::Target* l_master = TARGETING::getMasterCore();
        for( auto c : l_cores )
        {
            if( c != l_master )
            {
                l_victim = c;
                break;
            }
        }
        if( l_victim == nullptr )
        {
            TS_FAIL( "Could not find a non-master core" );
            return;
        }

        // Create an informational log
        errlHndl_t l_err = nullptr;
        l_err = new ERRORLOG::ErrlEntry(
                                        ERRORLOG::ERRL_SEV_INFORMATIONAL,
                                        ERRORLOG::ERRL_TEST_MOD_ID,
                                        ERRORLOG::ERRL_TEST_REASON_CODE,
                                        0x494E464F, //INFO
                                        0 );
        // Add a callout with deconfig and gard
        l_err->addHwCallout( l_victim,
                             HWAS::SRCI_PRIORITY_HIGH,
                             HWAS::DECONFIG,
                             HWAS::GARD_Fatal );
        // Commit the log
        errlCommit(l_err,CXXTEST_COMP_ID);

        // Verify that the target wasn't actually deconfigured
        TARGETING::ATTR_HWAS_STATE_type l_state =
          l_victim->getAttr<TARGETING::ATTR_HWAS_STATE>();
        if( !l_state.functional )
        {
            TS_FAIL( "Info log incorrectly caused deconfig" );
        }


        // Create a recovered log
        l_err = new ERRORLOG::ErrlEntry(
                                        ERRORLOG::ERRL_SEV_RECOVERED,
                                        ERRORLOG::ERRL_TEST_MOD_ID,
                                        ERRORLOG::ERRL_TEST_REASON_CODE,
                                        0x52454300, //REC
                                        0 );
        // Add a callout with deconfig and gard
        l_err->addHwCallout( l_victim,
                             HWAS::SRCI_PRIORITY_HIGH,
                             HWAS::DECONFIG,
                             HWAS::GARD_Fatal );
        // Commit the log
        errlCommit(l_err,CXXTEST_COMP_ID);

        // Verify that the target wasn't actually deconfigured
        l_state =
          l_victim->getAttr<TARGETING::ATTR_HWAS_STATE>();
        if( !l_state.functional )
        {
            TS_FAIL( "Recovered log incorrectly caused deconfig" );
        }
    }

    /**
     * @brief Verify subsystem mapping
     *
     * Simple test for now that targets test for defects in this area
     * Can be expanded on later if time permits
     */
    void testErrl_verifySubsystem(void)
    {
        errlHndl_t l_err = nullptr;
        l_err = new ERRORLOG::ErrlEntry(
                                        ERRORLOG::ERRL_SEV_INFORMATIONAL,
                                        ERRORLOG::ERRL_TEST_MOD_ID,
                                        ERRORLOG::ERRL_TEST_REASON_CODE,
                                        0x494E464F, //INFO
                                        0);
        // Simple test for now to verify correct subsys comes back
        // for MC target type
        epubSubSystem_t l_subsys = l_err->getSubSystem(TARGETING::TYPE_MC);
        if(l_subsys != EPUB_MEMORY_SUBSYS)
        {
            TS_FAIL( "Incorrect subsystem type returned for TYPE_MC" );
        }
        else
        {
            TS_INFO( "Correct subsystem type returned for TYPE_MC!" );
        }

        l_subsys = l_err->getSubSystem(TARGETING::TYPE_SMPGROUP);
        if(l_subsys != EPUB_CEC_HDW_SUBSYS)
        {
            TS_FAIL( "Incorrect subsystem type returned for TYPE_SMPGROUP" );
        }
        else
        {
            TS_INFO( "Correct subsystem type returned for TYPE_SMPGROUP!" );
        }
        // Delete the log
        delete l_err;
        l_err = NULL;
    }

    /**
     *  @brief Verify subsystem is known for every target type
     */
    void testErrl_verifySubsystem_known(void)
    {
        std::map<TARGETING::ATTR_TYPE_type, int> mTypesTried;
        errlHndl_t l_err = nullptr;
        epubSubSystem_t l_subsys = EPUB_MISC_UNKNOWN;
        l_err = new ERRORLOG::ErrlEntry(
                                        ERRORLOG::ERRL_SEV_INFORMATIONAL,
                                        ERRORLOG::ERRL_TEST_MOD_ID,
                                        ERRORLOG::ERRL_TEST_REASON_CODE,
                                        0x494E464F, //INFO
                                        0);


        // cycle through all the targets
        TARGETING::TargetService& l_targetService = TARGETING::targetService();
        for (TARGETING::TargetIterator l_pTarget = l_targetService.begin();
             l_pTarget != l_targetService.end();
             ++l_pTarget)
        {
            TARGETING::ATTR_TYPE_type type = l_pTarget->getAttr<TARGETING::ATTR_TYPE>();
            // skip types that have been checked already
            if (mTypesTried.count(type) == 0)
            {
                l_subsys = l_err->getSubSystem(type);
                if(l_subsys == EPUB_MISC_UNKNOWN)
                {
                    TS_FAIL( "testErrl_verifySubsystem_known: "
                        "Unknown subsystem for type 0x%02X, target huid: 0x%08X",
                        type, TARGETING::get_huid(*l_pTarget) );
                }
                else
                {
                    TS_INFO( "testErrl_verifySubsystem_known: "
                        "Type 0x%02X -> subsystem 0x%02X", type, l_subsys );
                }
                mTypesTried[type] = 1;
            }
        }

        // out of bounds check (should be unknown)
        l_subsys = l_err->getSubSystem(TARGETING::TYPE_LAST_IN_RANGE);
        if (l_subsys != EPUB_MISC_UNKNOWN)
        {
            TS_FAIL( "testErrl_verifySubsystem_known: "
                "TYPE_LAST_IN_RANGE 0x%02X -> subsystem 0x%02X",
                TARGETING::TYPE_LAST_IN_RANGE, l_subsys );
        }
        else
        {
            TS_INFO( "testErrl_verifySubsystem_known: "
                "TYPE_LAST_IN_RANGE 0x%02X -> subsystem EPUB_MISC_UNKNOWN",
                TARGETING::TYPE_LAST_IN_RANGE );
        }

        // Delete the log
        delete l_err;
        l_err = NULL;
    }



};
}

#endif

