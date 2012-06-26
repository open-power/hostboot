/*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/usr/errl/test/errluserdetailtest.H $
 *
 *  IBM CONFIDENTIAL
 *
 *  COPYRIGHT International Business Machines Corp. 2011-2012
 *
 *  p1
 *
 *  Object Code Only (OCO) source materials
 *  Licensed Internal Code Source Materials
 *  IBM HostBoot Licensed Internal Code
 *
 *  The source code for this program is not published or other-
 *  wise divested of its trade secrets, irrespective of what has
 *  been deposited with the U.S. Copyright Office.
 *
 *  Origin: 30
 *
 *  IBM_PROLOG_END_TAG
 */
#ifndef __TEST_ERRLUSERDETAILSTEST_H
#define __TEST_USERUSERDETAILSTEST_H

/**
 *  @file errluserdetailstest.H
 *
 *  @brief Test user data plugins for errorlog.
 *
 */

#include <cxxtest/TestSuite.H>
#include <errl/errlentry.H>
#include <errl/errluserdetails.H>
#include <errl/errlreasoncodes.H>
#include <errl/errludstring.H>
#include <errl/errludbacktrace.H>
#include <errl/errludtarget.H>
#include <errl/errludlogregister.H>
#include <errl/errludcallout.H>
#include <errludattribute.H>
#include <targeting/common/targetservice.H>
#include <targeting/common/iterators/rangefilter.H>
#include <targeting/common/predicates/predicates.H>
#include <targeting/common/util.H>

#include <devicefw/driverif.H>

using   namespace   ERRORLOG;

class UtilErrlUsrDataTest: public CxxTest::TestSuite
{
public:

    // Note that errlUserDetailsTarget is tested in the targeting unit test

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
        * @moduleid HBERRL_USERDATA_TEST_MOD_ID
        * @reasoncode HBERRL_TEST_STRING_UD
        * @userdata1 Test data 1
        * @userdata2 Test data 2
        * @devdesc  User Details unit test - create string user detail data
        */
        errl = new ErrlEntry(
                ERRL_SEV_INFORMATIONAL,
                HBERRL_USERDATA_TEST_MOD_ID,
                HBERRL_TEST_STRING_UD,
                0x1234567890,                   //  user1
                0x9876543210 );                 //  user2

        // Create a test string and add it to the error log as user detail data
        const char * l_pString = "This is a test string";
        ErrlUserDetailsString(l_pString).addToLog(errl);

        // create more and make sure that they get merged into 1 sub-section
        ErrlUserDetailsString("String test - string 2").addToLog(errl);

        ErrlUserDetailsString stringUD("String test - string 3");
        stringUD.addToLog(errl);

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
        * @moduleid HBERRL_USERDATA_TEST_MOD_ID
        * @reasoncode HBERRL_TEST_ATTRIBUTE_UD
        * @userdata1 Test data 1
        * @userdata2 Test data 2
        * @devdesc  User Details unit test - create string user detail data
        */
        errl = new ErrlEntry(
                ERRL_SEV_INFORMATIONAL,
                HBERRL_USERDATA_TEST_MOD_ID,
                HBERRL_TEST_ATTRIBUTE_UD,
                0x0001002300450067,
                0x008900AB00CD00EF);

        using namespace TARGETING;

        // find a proc target
        PredicateCTM procChipFilter(CLASS_CHIP,TYPE_PROC);
        TargetRangeFilter pProc(
            targetService().begin(), targetService().end(),
            &procChipFilter);

        // find a membuf target
        PredicateCTM membufChipFilter(CLASS_CHIP,TYPE_MEMBUF);
        TargetRangeFilter pMembuf(
            targetService().begin(), targetService().end(),
            &membufChipFilter);

        // find a dimm target
        PredicateCTM dimmChipFilter(CLASS_NA,TYPE_DIMM);
        TargetRangeFilter pDimm(
            targetService().begin(), targetService().end(),
            &dimmChipFilter);

        const Target* c_target;
        c_target = *pProc;
        TS_TRACE( "testAttribute pProc %p", c_target);
        ErrlUserDetailsTarget(c_target).addToLog(errl);
        ErrlUserDetailsTarget(
            TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL).addToLog(errl);

        // all attributes
        ErrlUserDetailsAttribute(c_target).addToLog(errl);

        // HUID repeated for each addToLog()
        ErrlUserDetailsAttribute(c_target,ATTR_EC).addToLog(errl);
        ErrlUserDetailsAttribute(c_target,ATTR_CHIP_ID).addToLog(errl);

        // 1 HUID only
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

        c_target = *pMembuf;
        TS_TRACE( "testAttribute pMembuf %p", c_target);
        ErrlUserDetailsTarget(c_target).addToLog(errl);

        // all attributes
        ErrlUserDetailsAttribute(c_target).addToLog(errl);

        // one HUID then each attribute
        ErrlUserDetailsAttribute pMembufEUDA(c_target,ATTR_CHIP_ID);
        pMembufEUDA.addData(ATTR_EC);
        pMembufEUDA.addData(ATTR_CHIP_ID);
        pMembufEUDA.addData(ATTR_MSS_VOLT);
        pMembufEUDA.addData(ATTR_MSS_FREQ);

        // skipped - not there
        pMembufEUDA.addData(ATTR_SCRATCH_UINT8_1);

        // skipped - write only
        pMembufEUDA.addData(ATTR_DUMMY_WO);

        // skipped - read only
        pMembufEUDA.addData(ATTR_CLASS);

        // done - write it out
        pMembufEUDA.addToLog(errl);

        c_target = *pDimm;
        TS_TRACE( "testAttribute pDimm %p", c_target);
        ErrlUserDetailsTarget(c_target).addToLog(errl);

        // all attributes
        ErrlUserDetailsAttribute(c_target).addToLog(errl);

        // one HUID then each attribute
        ErrlUserDetailsAttribute pDimmEUDA(c_target,ATTR_CHIP_ID);
        pDimmEUDA.addData(ATTR_EC);
        pDimmEUDA.addData(ATTR_CHIP_ID);
        pDimmEUDA.addData(ATTR_MSS_VOLT);
        pDimmEUDA.addData(ATTR_MSS_FREQ);

        // skipped - not there
        pDimmEUDA.addData(ATTR_SCRATCH_UINT8_1);

        // skipped - write only
        pDimmEUDA.addData(ATTR_DUMMY_WO);

        // skipped - read only
        pDimmEUDA.addData(ATTR_CLASS);

        // done - write it out
        pDimmEUDA.addToLog(errl);

#if 1
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
        * @moduleid HBERRL_USERDATA_TEST_MOD_ID
        * @reasoncode HBERRL_TEST_LOGREGISTER_UD
        * @userdata1 Test data 1
        * @userdata2 Test data 2
        * @devdesc User Details unit test - create log register user detail data
        */
        errl = new ERRORLOG::ErrlEntry(
                ERRORLOG::ERRL_SEV_INFORMATIONAL,
                HBERRL_USERDATA_TEST_MOD_ID,
                HBERRL_TEST_LOGREGISTER_UD,
                0x008900AB00CD00EF,                   //  user1
                0x0001002300450067 );                 //  user2

        using namespace TARGETING;
        ErrlUserDetailsString("LogRegister test").addToLog(errl);

        // find a proc target
        PredicateCTM procChipFilter(CLASS_CHIP,TYPE_PROC);
        TargetRangeFilter pProc(
            targetService().begin(), targetService().end(),
            &procChipFilter);

        // find a membuf target
        PredicateCTM membufChipFilter(CLASS_CHIP,TYPE_MEMBUF);
        TargetRangeFilter pMembuf(
            targetService().begin(), targetService().end(),
            &membufChipFilter);

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
        ErrlUserDetailsTarget(c_target).addToLog(errl);

        // 1-shot way first - each will have HUID before register data
        ErrlUserDetailsLogRegister(c_target,
                    DEVICE_SCOM_ADDRESS(0x000F000Full)).addToLog(errl);
        ErrlUserDetailsLogRegister(c_target,
                    DEVICE_MVPD_ADDRESS(3,0)).addToLog(errl);
        // error:
        ErrlUserDetailsLogRegister(c_target,
                    DEVICE_FSI_ADDRESS(0x01028)).addToLog(errl);
        // can't do this - use the addData methodology for driverif.H addresses
        //ErrlUserDetailsLogRegister(c_target,
                    //DEVICE_FSISCOM_ADDRESS(0x000F000Full)).addToLog(errl);

        // more efficient - HUID then each register
        {
            ErrlUserDetailsLogRegister eudlr(c_target);
            eudlr.addData(DEVICE_SCOM_ADDRESS(0x000F000Full));
            eudlr.addData(DEVICE_MVPD_ADDRESS(3,0));
            // error:
            eudlr.addData(DEVICE_FSI_ADDRESS(0x01028));
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

        uint64_t reg3_data = 0;
        size_t reg3_size = sizeof(reg3_data);
        errl_deviceRead = DeviceFW::deviceRead(c_target,
                        &reg3_data, reg3_size,
                        DEVICE_FSI_ADDRESS(0x01028));

        if (errl_deviceRead != NULL)
        {
            TS_TRACE( "testLogRegister deviceRead return errl; deleting;");
            delete errl_deviceRead;
            reg3_size = 0;
        }
        else
        {   // we expect an error here
            TS_TRACE( "testLogRegister deviceRead DIDNT return errl!");
        }
        ErrlUserDetailsLogRegister(c_target, &reg3_data, reg3_size,
                DEVICE_FSI_ADDRESS(0x01028)).addToLog(errl);

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
        ErrlUserDetailsLogRegister(c_target,
                DEVICE_PRESENT_ADDRESS()).addToLog(errl);
        ErrlUserDetailsLogRegister(c_target,
                DEVICE_PNOR_ADDRESS(0, 0)).addToLog(errl);
        ErrlUserDetailsLogRegister(c_target,
                DEVICE_MBOX_ADDRESS(0)).addToLog(errl);

        c_target = *pMembuf;
        ErrlUserDetailsTarget(c_target).addToLog(errl);

        // HUID then each register
        {
            ErrlUserDetailsLogRegister eudlr(c_target);
            eudlr.addData(DEVICE_FSI_ADDRESS(0x01028));
            eudlr.addData(DEVICE_SCOM_ADDRESS(0x000F000Full));
            eudlr.addToLog(errl);
        }

        c_target = *pDimm;
        ErrlUserDetailsTarget(c_target).addToLog(errl);

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
            eudlr.addData(DEVICE_I2C_ADDRESS(0,0,0x50));
            eudlr.addData(DEVICE_EEPROM_ADDRESS(0x1111,0));
            eudlr.addToLog(errl);
        }

        // commit the errorlog
        errlCommit(errl, CXXTEST_COMP_ID);
        TS_TRACE( "testLogRegister errorlog user detail data - complete");
    } // testLogRegister

    /**
     * @test testCallout - Capture a callout
     */
    void testCallout(void)
    {
        errlHndl_t errl = NULL;

        TS_TRACE( "testCallout errorlog user detail data");
        /*@
        * @errortype
        * @severity ERRORLOG_SEV_INFORMATIONAL
        * @moduleid HBERRL_USERDATA_TEST_MOD_ID
        * @reasoncode HBERRL_TEST_CALLOUT_UD
        * @userdata1 Test data 1
        * @userdata2 Test data 2
        * @devdesc User Details unit test - create callout user detail data
        */
        errl = new ERRORLOG::ErrlEntry(
                ERRORLOG::ERRL_SEV_INFORMATIONAL,
                HBERRL_USERDATA_TEST_MOD_ID,
                HBERRL_TEST_CALLOUT_UD,
                0x0001002300450067,                   //  user1
                0x008900AB00CD00EF );                 //  user2

        using namespace TARGETING;
        ErrlUserDetailsString("Callout test").addToLog(errl);

        // first test with Master
        ErrlUserDetailsCallout(
                    &HWAS::TARGET_IS_SENTINEL,
                    sizeof(HWAS::TARGET_IS_SENTINEL),
                    HWAS::SRCI_PRIORITY_LOW,
                    HWAS::DECONFIG,
                    HWAS::GARD_PoreError).addToLog(errl);

        ErrlUserDetailsCallout(
                    &HWAS::TARGET_IS_SENTINEL,
                    sizeof(HWAS::TARGET_IS_SENTINEL),
                    HWAS::SRCI_PRIORITY_MED,
                    HWAS::DECONFIG,
                    HWAS::GARD_NULL).addToLog(errl);

        // find a proc target
        PredicateCTM procChipFilter(CLASS_CHIP,TYPE_PROC);
        TargetRangeFilter pProc(
            targetService().begin(), targetService().end(),
            &procChipFilter);
        TARGETING::EntityPath ep;
        ep = pProc->getAttr<TARGETING::ATTR_PHYS_PATH>();

        ErrlUserDetailsCallout(
                    &ep,
                    sizeof(ep),
                    HWAS::SRCI_PRIORITY_LOW,
                    HWAS::DECONFIG,
                    HWAS::GARD_Fatal).addToLog(errl);

        ErrlUserDetailsCallout(
                    HWAS::EPUB_PRC_MEMORY_UE,
                    HWAS::SRCI_PRIORITY_HIGH).addToLog(errl);

        // commit the errorlog
        errlCommit(errl, CXXTEST_COMP_ID);
        TS_TRACE( "testCallout done");

    } // testCallout

};

#endif

