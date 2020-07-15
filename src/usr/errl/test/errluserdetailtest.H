/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/errl/test/errluserdetailtest.H $                      */
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
#ifndef __TEST_ERRLUSERDETAILSTEST_H
#define __TEST_USERUSERDETAILSTEST_H

/**
 *  @file errluserdetailstest.H
 *
 *  @brief Test user data plugins for errorlog.
 *
 */

#include <stdio.h>
#include <cxxtest/TestSuite.H>
#include <errl/errlentry.H>
#include <errl/errluserdetails.H>
#include <errl/errlreasoncodes.H>
#include <errl/errlud.H>
#include <errl/errludstring.H>
#include <errl/errludbacktrace.H>
#include <errl/errludtarget.H>
#include <errl/errludlogregister.H>
#include <errl/errludcallout.H>
#include <errl/errludattribute.H>
#include <errl/hberrltypes.H>
#include <targeting/common/targetservice.H>
#include <targeting/common/iterators/rangefilter.H>
#include <targeting/common/predicates/predicates.H>
#include <targeting/common/util.H>
#include <hwas/common/deconfigGard.H>
#include <devicefw/driverif.H>

using   namespace   ERRORLOG;

class UtilErrlUsrDataTest: public CxxTest::TestSuite
{
public:

    // Note that errlUserDetailsTarget is tested in the targeting unit test


    void testRemoveDuplicateTraces(void)
    {
        const size_t NUM_TRACE_ENTRIES = 5, NUM_COMPONENTS = 4;
        typedef std::vector<void*> pVoidVec_t;

        trace_desc_t* trac_testRmDupTrac1_trace = nullptr;
        TRAC_INIT(&trac_testRmDupTrac1_trace, "TEST_TRACE1", 2*KILOBYTE);

        trace_desc_t* trac_testRmDupTrac2_trace = nullptr;
        TRAC_INIT(&trac_testRmDupTrac2_trace, "TEST_TRACE2", 2*KILOBYTE);

        trace_desc_t* trac_testRmDupTrac3_trace = nullptr;
        TRAC_INIT(&trac_testRmDupTrac3_trace, "TEST_TRACE3", 2*KILOBYTE);

        trace_desc_t* trac_testRmDupTrac4_trace = nullptr;
        TRAC_INIT(&trac_testRmDupTrac4_trace, "TEST_TRACE4", 2*KILOBYTE);

        // Test Case 1: Collect traces five times from the same component and
        //              verify no duplicates remain.

        ErrlEntry* l_err1 = new ErrlEntry( ERRL_SEV_INFORMATIONAL,
                                           ERRL_USERDATA_TEST_MOD_ID,
                                           ERRL_TEST_DUPLICATE_TRACE,
                                           0x1234567890,
                                           0x9876543210 );
        // Write traces to comp 1
        for (size_t i = 0; i < NUM_TRACE_ENTRIES; ++i)
        {
            TRACFCOMP(trac_testRmDupTrac1_trace, "Trace %d.", (i+1));
        }

        for (size_t i = 0; i < 5; ++i)
        {
           l_err1->collectTrace("TEST_TRACE1");
        }

        l_err1->removeDuplicateTraces();

        pVoidVec_t traceUDSections_case1 =
            l_err1->getUDSections(FIPS_ERRL_COMP_ID, FIPS_ERRL_UDT_HB_TRACE);

        errlCommit(l_err1, CXXTEST_COMP_ID);

        // ErrlEntry::removeDuplicateTraces() should have removed all duplicates
        // and combined all trace UD sections into one section. If that isn't
        // case then this test case should fail.
        if(traceUDSections_case1.size() != 1)
        {
            TS_FAIL("The number of trace UD sections was != 1");
        }

        for(auto it = traceUDSections_case1.begin();
            it != traceUDSections_case1.end(); ++it)
        {
            TRACE::trace_buf_head_t* header =
                reinterpret_cast<TRACE::trace_buf_head_t*>((*it));

            if (header->te_count != NUM_TRACE_ENTRIES)
            {
                TS_FAIL("The number of trace entries was != NUM_TRACE_ENTRIES");
            }
        }

        // Test Case 2: Collect from several components and verify that none
        //              of the traces were removed.

        ErrlEntry* l_err2 = new ErrlEntry( ERRL_SEV_INFORMATIONAL,
                                           ERRL_USERDATA_TEST_MOD_ID,
                                           ERRL_TEST_DUPLICATE_TRACE,
                                           0x1234567890,
                                           0x9876543210 );

        // Write traces to comp 2
        for (size_t i = 0; i < NUM_TRACE_ENTRIES; ++i)
        {
            TRACFCOMP(trac_testRmDupTrac2_trace, "Trace %d.", (i+1));
        }

        // Write traces to comp 3
        for (size_t i = 0; i < NUM_TRACE_ENTRIES; ++i)
        {
            TRACFCOMP(trac_testRmDupTrac3_trace, "Trace %d.", (i+1));
        }

        // Write traces to comp 4
        for (size_t i = 0; i < NUM_TRACE_ENTRIES; ++i)
        {
            TRACFCOMP(trac_testRmDupTrac4_trace, "Trace %d.", (i+1));
        }


        // Collect the traces for each one once.
        l_err2->collectTrace("TEST_TRACE1");
        l_err2->collectTrace("TEST_TRACE2");
        l_err2->collectTrace("TEST_TRACE3");
        l_err2->collectTrace("TEST_TRACE4");

        l_err2->removeDuplicateTraces();

        // Get the trace UD sections
        pVoidVec_t traceUDSections_case2 =
            l_err2->getUDSections(FIPS_ERRL_COMP_ID, FIPS_ERRL_UDT_HB_TRACE);

        // Commit the error log
        errlCommit(l_err2, CXXTEST_COMP_ID);

        // Since the ErrlEntry::collectTrace() function creates a new UD section
        // on each call to it there should only be NUM_COMPONENTS trace UD
        // sections returned from ErrlEntry::getUDSections(). If that isn't the
        // case then something unexpected happened and this test case should
        // fail.
        if(traceUDSections_case2.size() != NUM_COMPONENTS)
        {
            TS_FAIL("The number of trace UD sections was !=  NUM_COMPONENTS.");
        }

        // If ErrlEntry::removeDuplicateTraces() worked then none of the trace
        // entries should be missing in any of the components.
        for(auto it = traceUDSections_case2.begin();
            it != traceUDSections_case2.end(); it++)
        {
            TRACE::trace_buf_head_t* header =
                reinterpret_cast<TRACE::trace_buf_head_t*>((*it));

            if (header->te_count != NUM_TRACE_ENTRIES)
            {
                TS_FAIL("The number of trace entries was != NUM_TRACE_ENTRIES");
            }
        }

        // Test Case 3: Collect from a component once, write a new trace to that
        //              component, and then collect from it several times.

        ErrlEntry* l_err3 = new ErrlEntry( ERRL_SEV_INFORMATIONAL,
                                           ERRL_USERDATA_TEST_MOD_ID,
                                           ERRL_TEST_DUPLICATE_TRACE,
                                           0x1234567890,
                                           0x9876543210 );

        l_err3->collectTrace("TEST_TRACE1");

        TRACFCOMP(trac_testRmDupTrac1_trace, "A New Trace.");

        for (size_t i = 0; i < 5; ++i)
        {
            l_err3->collectTrace("TEST_TRACE1");
        }

        l_err3->removeDuplicateTraces();

        pVoidVec_t traceUDSections_case3 =
            l_err3->getUDSections(FIPS_ERRL_COMP_ID, FIPS_ERRL_UDT_HB_TRACE);

        errlCommit(l_err3, CXXTEST_COMP_ID);

        // ErrlEntry::removeDuplicateTraces() should have removed all duplicates
        // and combined all trace UD sections into one section. If that isn't
        // case then this test case should fail.
        if(traceUDSections_case3.size() != 1)
        {
            TS_FAIL("The number of trace UD sections was != 1");
        }

        for(auto it = traceUDSections_case3.begin();
            it != traceUDSections_case3.end(); ++it)
        {
            TRACE::trace_buf_head_t* header =
                reinterpret_cast<TRACE::trace_buf_head_t*>((*it));

            if (header->te_count != (NUM_TRACE_ENTRIES + 1))
            {
                TS_FAIL("The number of trace entries was != 6");
            }
        }
    }


    /**
     * @test testString - Capture a String in an error log
     */
    void testString(void)
    {
        errlHndl_t errl = NULL;

        TS_TRACE( "testString errorlog user detail data");
        /*@
        * @errortype
        * @severity ERRORLOG_SEV_INFORMATIONAL
        * @moduleid ERRL_USERDATA_TEST_MOD_ID
        * @reasoncode ERRL_TEST_STRING_UD
        * @userdata1 Test data 1
        * @userdata2 Test data 2
        * @devdesc  User Details unit test - create string user detail data.
        * @custdesc A problem occurred during the IPL of the system.
        */
        errl = new ErrlEntry(
                ERRL_SEV_INFORMATIONAL,
                ERRL_USERDATA_TEST_MOD_ID,
                ERRL_TEST_STRING_UD,
                0x1234567890,                   //  user1
                0x9876543210 );                 //  user2

        // Create a test string and add it to the error log as user detail data
        const char * l_pString = "This is a test string";
        ErrlUserDetailsString(l_pString).addToLog(errl);

        // create more and make sure that they get merged into 1 sub-section
        ErrlUserDetailsString("String test - string 2").addToLog(errl);

        ErrlUserDetailsString stringUD("String test - string 3");
        stringUD.addToLog(errl);

        // Add a little test for making strings on the fly
        {
            const int test_data = 0xfeedface;
            const char* format = "msg_respond() i/o error (transmit) 0x%x";
            const size_t output_size = strlen(format) + (sizeof(int) * 2) + 1;
            char output[output_size];
            snprintf(output, output_size, format, test_data);

            // Add msg_respond rc
            ERRORLOG::ErrlUserDetailsString(output).addToLog(errl);
        }

        // shove a lot of traces here, so that we test the truncate in the
        // write to PNOR
        errl->collectTrace("TARG", 1024);
        errl->collectTrace("TARG", 48);
        errl->collectTrace("TARG", 1024);
        errl->collectTrace("TARG", 48);
        errl->collectTrace("TARG", 1024);
        errl->collectTrace("TARG", 48);
        errl->collectTrace("TARG", 1024);
        errl->collectTrace("TARG", 48);
        errl->collectTrace("TARG", 1024);
        errl->collectTrace("TARG", 48);

        // commit the errorlog
        errlCommit(errl, CXXTEST_COMP_ID);
    }

    /**
     * @test testAttribute - Capture a String in an error log
     */
    void testAttribute(void)
    {
        errlHndl_t errl = NULL;

        TS_TRACE( "testAttribute errorlog user detail data and merge");
        /*@
        * @errortype
        * @severity ERRORLOG_SEV_INFORMATIONAL
        * @moduleid ERRL_USERDATA_TEST_MOD_ID
        * @reasoncode ERRL_TEST_ATTRIBUTE_UD
        * @userdata1 Test data 1
        * @userdata2 Test data 2
        * @devdesc  User Details unit test - create string user detail data.
        * @custdesc A problem occurred during the IPL of the system.
        */
        errl = new ErrlEntry(
                ERRL_SEV_INFORMATIONAL,
                ERRL_USERDATA_TEST_MOD_ID,
                ERRL_TEST_ATTRIBUTE_UD,
                0x0001002300450067,
                0x008900AB00CD00EF);

        using namespace TARGETING;

        // find a proc target
        PredicateCTM procChipFilter(CLASS_CHIP,TYPE_PROC);
        TargetRangeFilter pProc(
            targetService().begin(), targetService().end(),
            &procChipFilter);

        // find a OCMB target
        PredicateCTM ocmbChipFilter(CLASS_CHIP,TYPE_OCMB_CHIP);
        TargetRangeFilter pOcmb(
            targetService().begin(), targetService().end(),
            &ocmbChipFilter);

        // find a dimm target
        PredicateCTM dimmChipFilter(CLASS_NA,TYPE_DIMM);
        TargetRangeFilter pDimm(
            targetService().begin(), targetService().end(),
            &dimmChipFilter);

        const Target* c_target;
        c_target = *pProc;
        TS_TRACE( "testAttribute pProc %p", c_target);
        ErrlUserDetailsTarget(c_target).addToLog(errl);

        // all attributes
        ErrlUserDetailsAttribute(c_target).addToLog(errl);

        // HUID repeated for each addToLog()
        ErrlUserDetailsTarget(c_target).addToLog(errl);
        ErrlUserDetailsAttribute(c_target,ATTR_EC).addToLog(errl);
        ErrlUserDetailsAttribute(c_target,ATTR_CHIP_ID).addToLog(errl);

        // 1 HUID only
        ErrlUserDetailsTarget(c_target).addToLog(errl);
        ErrlUserDetailsAttribute(c_target,ATTR_HUID).addToLog(errl);

        // HUID only - not there
        ErrlUserDetailsAttribute(c_target,ATTR_SCRATCH_UINT8_1).addToLog(errl);

        // HUID only - write only
        ErrlUserDetailsAttribute(c_target,ATTR_DUMMY_WO).addToLog(errl);

        // HUID only - read only
        ErrlUserDetailsAttribute(c_target,ATTR_CLASS).addToLog(errl);

        //
        // one HUID then each attribute
        ErrlUserDetailsAttribute pProcEUDA(c_target,ATTR_CHIP_ID);
        pProcEUDA.addData(ATTR_EC);
        pProcEUDA.addData(ATTR_CHIP_ID);

        // skipped - not there
        pProcEUDA.addData(ATTR_SCRATCH_UINT8_1);

        // skipped - write only
        pProcEUDA.addData(ATTR_DUMMY_WO);

        // skipped - read only
        pProcEUDA.addData(ATTR_CLASS);

        // done - write it out
        pProcEUDA.addToLog(errl);


        if(*pOcmb != NULL)
        {
            c_target = *pOcmb;
            TS_TRACE( "testAttribute pOcmb %p", c_target);
            ErrlUserDetailsTarget(c_target).addToLog(errl);

            // all attributes
            ErrlUserDetailsAttribute(c_target).addToLog(errl);

            // one HUID then each attribute
            ErrlUserDetailsAttribute pOcmbEUDA(c_target,ATTR_CHIP_ID);
            pOcmbEUDA.addData(ATTR_EC);
            pOcmbEUDA.addData(ATTR_CHIP_ID);
            pOcmbEUDA.addData(ATTR_MSS_OCMB_EXP_BOOT_CONFIG_SERDES_FREQUENCY);

            // skipped - not there
            pOcmbEUDA.addData(ATTR_SCRATCH_UINT8_1);

            // skipped - write only
            pOcmbEUDA.addData(ATTR_DUMMY_WO);

            // skipped - read only
            pOcmbEUDA.addData(ATTR_CLASS);

            // done - write it out
            pOcmbEUDA.addToLog(errl);
        }

        if(*pDimm != NULL)
        {
            c_target = *pDimm;
            TS_TRACE( "testAttribute pDimm %p", c_target);
            ErrlUserDetailsTarget(c_target).addToLog(errl);

            // all attributes
            ErrlUserDetailsAttribute(c_target).addToLog(errl);

            // one HUID then each attribute
            ErrlUserDetailsAttribute pDimmEUDA(c_target,ATTR_CHIP_ID);
            pDimmEUDA.addData(ATTR_EC);
            pDimmEUDA.addData(ATTR_CHIP_ID);
            pDimmEUDA.addData(ATTR_POS_ON_MEM_PORT);

            // skipped - not there
            pDimmEUDA.addData(ATTR_SCRATCH_UINT8_1);

            // skipped - write only
            pDimmEUDA.addData(ATTR_DUMMY_WO);

            // skipped - read only
            pDimmEUDA.addData(ATTR_CLASS);

            // done - write it out
            pDimmEUDA.addToLog(errl);
        }
#if 0
        // extended test
        uint32_t i = 0;
        for (TargetIterator target = targetService().begin();
            (i < 10) && (target != targetService().end());
            ++i, ++target)
        {
            TS_TRACE( "testAttribute %p", *target);
            const Target* c_target = *target;
            ErrlUserDetailsTarget(c_target).addToLog(errl);
            ErrlUserDetailsAttribute(c_target).addToLog(errl);
        }
#endif

        // commit the errorlog
        errlCommit(errl, CXXTEST_COMP_ID);
        TS_TRACE( "testAttribute done");
    } // testAttribute


    /**
     * @test testLogRegister - Capture a register in an error log
     */
    void testLogRegister(void)
    {
        errlHndl_t errl = NULL;

        TS_TRACE( "testLogRegister errorlog user detail data");
        /*@
        * @errortype
        * @severity ERRORLOG_SEV_INFORMATIONAL
        * @moduleid ERRL_USERDATA_TEST_MOD_ID
        * @reasoncode ERRL_TEST_LOGREGISTER_UD
        * @userdata1 Test data 1
        * @userdata2 Test data 2
        * @devdesc User Details unit test
        *          - create log register user detail data.
        * @custdesc A problem occurred during the IPL of the system.
        */
        errl = new ERRORLOG::ErrlEntry(
                ERRORLOG::ERRL_SEV_INFORMATIONAL,
                ERRL_USERDATA_TEST_MOD_ID,
                ERRL_TEST_LOGREGISTER_UD,
                0x008900AB00CD00EF,                   //  user1
                0x0001002300450067 );                 //  user2

        using namespace TARGETING;
        ErrlUserDetailsString("LogRegister test").addToLog(errl);

        // find a proc target
        PredicateCTM procChipFilter(CLASS_CHIP,TYPE_PROC);
        TargetRangeFilter pProc(
            targetService().begin(), targetService().end(),
            &procChipFilter);

        // find a dimm target
        PredicateCTM dimmChipFilter(CLASS_NA,TYPE_DIMM);
        TargetRangeFilter pDimm(
            targetService().begin(), targetService().end(),
            &dimmChipFilter);

        Target* c_target;

        // first do a test w/ the special MASTER SENTINAL constant
        c_target = MASTER_PROCESSOR_CHIP_TARGET_SENTINEL;
        ErrlUserDetailsTarget(c_target).addToLog(errl);
        {
            ErrlUserDetailsLogRegister eudlr(c_target);
            eudlr.addData(DEVICE_XSCOM_ADDRESS(0x000F000Full));
            eudlr.addData(DEVICE_SCOM_ADDRESS(0x000F000Full));
            eudlr.addToLog(errl);
        }

        c_target = *pProc;
        ErrlUserDetailsTarget(c_target, "Target: pProc").addToLog(errl);

        // 1-shot way first - each will have HUID before register data
        ErrlUserDetailsLogRegister(c_target,
                    DEVICE_SCOM_ADDRESS(0x000F000Full)).addToLog(errl);
        ErrlUserDetailsLogRegister(c_target,
                    DEVICE_MVPD_ADDRESS(3,0)).addToLog(errl);
        // error: This causes a sticky error in the 'hardware'
        //ErrlUserDetailsLogRegister(c_target,
        //            DEVICE_FSI_ADDRESS(0x01028)).addToLog(errl);

        // more efficient - HUID then each register
        {
            ErrlUserDetailsLogRegister eudlr(c_target);
            eudlr.addData(DEVICE_SCOM_ADDRESS(0x000F000Full));
            eudlr.addData(DEVICE_MVPD_ADDRESS(3,0));
            // error: This causes a sticky error in the 'hardware'
            //eudlr.addData(DEVICE_FSI_ADDRESS(0x1028));
            //TODO RTC: 123019 I2CM changes for P9
            //Need to uncomment this when this work is complete
//          eudlr.addData(DEVICE_I2C_ADDRESS(0,0,0xAC));
//          eudlr.addData(DEVICE_EEPROM_ADDRESS(0x0,0x0));
            eudlr.addToLog(errl);
        }

        // do the read first, then capture the data
        //  this mirrors the previous set of LogRegister calls at the
        //  top of this function, so the results should match..
        ErrlUserDetailsTarget(c_target).addToLog(errl);
        errlHndl_t errl_deviceRead;

        uint64_t reg1_data = 0;
        size_t reg1_size = sizeof(reg1_data);
        errl_deviceRead = DeviceFW::deviceRead(c_target,
                        &reg1_data, reg1_size,
                        DEVICE_SCOM_ADDRESS(0x000F000Full));

        if (errl_deviceRead != NULL)
        {
            TS_TRACE( "testLogRegister deviceRead return errl; deleting;");
            delete errl_deviceRead;
            reg1_size = 0;
        }
        ErrlUserDetailsLogRegister(c_target, &reg1_data, reg1_size,
                DEVICE_SCOM_ADDRESS(0x000F000Full)).addToLog(errl);
        uint64_t reg2_data = 0;
        size_t reg2_size = sizeof(reg2_data);
        errl_deviceRead = DeviceFW::deviceRead(c_target,
                                               &reg2_data, reg2_size,
                                               DEVICE_MVPD_ADDRESS(3,0));

        if (errl_deviceRead != NULL)
        {
            TS_TRACE( "testLogRegister deviceRead return errl; deleting;");
            delete errl_deviceRead;
            reg2_size = 0;
        }
        ErrlUserDetailsLogRegister(c_target, &reg2_data, reg2_size,
                                   DEVICE_MVPD_ADDRESS(3,0)).addToLog(errl);

        // error: This causes a sticky error in the 'hardware'
        uint32_t reg3_data = 0;
        size_t reg3_size = sizeof(reg3_data);
        /*
        errl_deviceRead = DeviceFW::deviceRead(c_target,
                        &reg3_data, reg3_size,
                        DEVICE_FSI_ADDRESS(0x1028));

        if (errl_deviceRead != NULL)
        {
            TS_TRACE( "testLogRegister deviceRead return errl; deleting;");
            delete errl_deviceRead;
            reg3_size = 0;
        }
        else
        {   // we expect an error here
            TS_TRACE( "testLogRegister deviceRead DIDN'T return errl!");
        }
        ErrlUserDetailsLogRegister(c_target, &reg3_data, reg3_size,
                DEVICE_FSI_ADDRESS(0x1028)).addToLog(errl);
        */

        // more efficient - HUID then each register
        {
            ErrlUserDetailsLogRegister eudlr(c_target);
            eudlr.addDataBuffer(&reg1_data, reg1_size,
                    DEVICE_SCOM_ADDRESS(0x000F000Full));
            eudlr.addDataBuffer(&reg2_data, reg2_size,
                    DEVICE_MVPD_ADDRESS(3,0));
             eudlr.addDataBuffer(&reg3_data, reg3_size,
                     DEVICE_FSI_ADDRESS(0x01028));
            eudlr.addToLog(errl);
        }

        // send some that aren't logged:
      //TODO RTC: 123019 I2CM changes for P9
      //Need to uncomment this when this work is complete
//         ErrlUserDetailsLogRegister(c_target,
//                 DEVICE_PRESENT_ADDRESS()).addToLog(errl);
        ErrlUserDetailsLogRegister(c_target,
                DEVICE_PNOR_ADDRESS(0, 0)).addToLog(errl);
        ErrlUserDetailsLogRegister(c_target,
                DEVICE_MBOX_ADDRESS(0)).addToLog(errl);


        if(*pDimm != NULL)
        {
            c_target = *pDimm;
            ErrlUserDetailsTarget(c_target, "Target: pDimm").addToLog(errl);

            // HUID then each register
            {
                ErrlUserDetailsLogRegister eudlr(c_target);
                eudlr.addData(DEVICE_SPD_ADDRESS(0));
                eudlr.addData(DEVICE_FSI_ADDRESS(0x01028));
                eudlr.addData(DEVICE_SCOM_ADDRESS(0x000F000Full));
                eudlr.addToLog(errl);
            }

            {
                ErrlUserDetailsLogRegister eudlr(c_target);
                eudlr.addData(DEVICE_FSISCOM_ADDRESS(0x01028));
                eudlr.addData(DEVICE_XSCOM_ADDRESS(0x000F000Full));
                eudlr.addToLog(errl);
            }

            // commit the errorlog
            errlCommit(errl, CXXTEST_COMP_ID);
            TS_TRACE( "testLogRegister errorlog user detail data - complete");
        }
    } // testLogRegister

};

#endif
