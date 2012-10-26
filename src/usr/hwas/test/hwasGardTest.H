/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwas/test/hwasGardTest.H $                            */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2011,2012              */
/*                                                                        */
/* p1                                                                     */
/*                                                                        */
/* Object Code Only (OCO) source materials                                */
/* Licensed Internal Code Source Materials                                */
/* IBM HostBoot Licensed Internal Code                                    */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* Origin: 30                                                             */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
#ifndef _HWASGARDTEST_H
#define _HWASGARDTEST_H

/**
 *  @file hwasGardTest.H
 *
 *  @brief Unit tests for HWAS Deconfigure and GARD functionality
 */

//******************************************************************************
// Includes
//******************************************************************************

// CXXTEST
#include <cxxtest/TestSuite.H>
#include <errl/errlmanager.H>
#include <targeting/common/targetservice.H>
#include <hwas/deconfigGard.H>
#include <hwas/common/hwas_reasoncodes.H>

class HwasGardTest: public CxxTest::TestSuite
{
public:

    /**
     *  @brief Test getting all Deconfigure Records
     */
    void testDeconfigure1()
    {
        TS_TRACE(INFO_MRK "testDeconfigure1: Started");
        
        errlHndl_t l_pErr = NULL;
        HWAS::DeconfigGard::DeconfigureRecords_t l_records;

        // Get all Deconfigure Records
        l_pErr = HWAS::theDeconfigGard().getDeconfigureRecords(NULL, l_records);
        
        if (l_pErr)
        {
            errlCommit(l_pErr,HWAS_COMP_ID);
            TS_FAIL("testDeconfigure1: Error from getDeconfigureRecords");
        }
        else
        {
            TS_TRACE(INFO_MRK "testDeconfigure1: Success. %d records",
                     l_records.size());
        }
    }
    
    /**
     *  @brief Test getting a Deconfigure Record for a specific Target
     */
    void testDeconfigure2()
    {
        TS_TRACE(INFO_MRK "testDeconfigure2: Started");
        
        errlHndl_t l_pErr = NULL;
        HWAS::DeconfigGard::DeconfigureRecords_t l_records;
        
        // Get the master processor chip
        TARGETING::Target* l_pTarget = NULL;
        TARGETING::targetService().masterProcChipTargetHandle(l_pTarget);
        TARGETING::EntityPath l_id =
            l_pTarget->getAttr<TARGETING::ATTR_PHYS_PATH>();

        // Get any Deconfigure Record for the chip
        l_pErr = HWAS::theDeconfigGard().getDeconfigureRecords(&l_id,
                                                               l_records);
        
        if (l_pErr)
        {
            errlCommit(l_pErr,HWAS_COMP_ID);
            TS_FAIL("testDeconfigure2: Error from getDeconfigureRecords");
        }
        else
        {
            if (l_records.size() > 1)
            {
                TS_FAIL("testDeconfigure2: More than 1 record (%d) for chip",
                        l_records.size());
            }
            else
            {
                TS_TRACE(INFO_MRK "testDeconfigure2: Success. %d records",
                         l_records.size());
            }
        }
    }

    /**
     *  @brief Test Deconfiguring a Target, getting the Deconfigure Record and
     *         clearing the Deconfigure Record
     */
    void testDeconfigure3()
    {
        TS_TRACE(INFO_MRK "testDeconfigure3: Started");
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
        
        errlHndl_t l_pErr = NULL;
        HWAS::DeconfigGard::DeconfigureRecords_t l_records;
        
        // Get the master processor chip
        TARGETING::Target* l_pTarget = NULL;
        TARGETING::targetService().masterProcChipTargetHandle(l_pTarget);
        TARGETING::EntityPath l_id =
            l_pTarget->getAttr<TARGETING::ATTR_PHYS_PATH>();

        do
        {
            // Get any existing Deconfigure Record for the chip
            l_pErr = HWAS::theDeconfigGard().getDeconfigureRecords(&l_id,
                                                                   l_records);
            
            if (l_pErr)
            {
                TS_FAIL("testDeconfigure3: Error from getDeconfigureRecords");
                break;
            }
            
            if (l_records.size() != 0)
            {
                TS_TRACE(INFO_MRK "testDeconfigure3: Chip has existing Deconfigure Record, skipping test");
                break;
            }
            
            // Get the original HWAS_STATE of the chip
            TARGETING::HwasState l_origState =
                l_pTarget->getAttr<TARGETING::ATTR_HWAS_STATE>();
 
            // Deconfigure the chip. Production code will pass a valid PLID
            l_pErr = HWAS::theDeconfigGard().deconfigureTarget(*l_pTarget, 0);
        
            if (l_pErr)
            {
                TS_FAIL("testDeconfigure3: Error from deconfigureTarget");
                break;
            }

            // Get the new HWAS_STATE of the chip
            TARGETING::HwasState l_state =
                l_pTarget->getAttr<TARGETING::ATTR_HWAS_STATE>();
                
            if (l_state.functional)
            {
                TS_FAIL("testDeconfigure3: Chip functional after deconfigure");
                // intentionally continue
            }
            
            // Get the Deconfigure Record for the chip
            l_pErr = HWAS::theDeconfigGard().getDeconfigureRecords(&l_id,
                                                                   l_records);
            
            if (l_pErr)
            {
                TS_FAIL("testDeconfigure3: Error from getDeconfigureRecords (2)");
                break;
            }
            
            if (l_records.size() != 1)
            {
                TS_FAIL("testDeconfigure3: %d records for chip, expected 1",
                        l_records.size());
                break;
            }
            
            // Reset the HWAS_STATE of the chip
            l_pTarget->setAttr<TARGETING::ATTR_HWAS_STATE>(l_origState);
            
            // Clear the Deconfigure Record
            HWAS::theDeconfigGard()._clearDeconfigureRecords(&l_id);
            
            // Get the Deconfigure Record for the chip
            l_records.clear();
            
            l_pErr = HWAS::theDeconfigGard().getDeconfigureRecords(&l_id,
                                                                   l_records);
            
            if (l_pErr)
            {
                TS_FAIL("testDeconfigure3: Error from getDeconfigureRecords (3)");
                break;
            }
            
            if (l_records.size() != 0)
            {
                TS_FAIL("testDeconfigure3: %d records for chip, expected 0",
                        l_records.size());
                break;
            }
            
            TS_TRACE(INFO_MRK "testDeconfigure3: Success");
        }
        while (0);
        
        if (l_pErr)
        {
            errlCommit(l_pErr,HWAS_COMP_ID);
        }
#endif
    }
    
    /**
     *  @brief Test Deconfiguring a Target multiple times
     */
    void testDeconfigure4()
    {
        TS_TRACE(INFO_MRK "testDeconfigure4: Started");
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
        
        errlHndl_t l_pErr = NULL;
        HWAS::DeconfigGard::DeconfigureRecords_t l_records;
        
        // Get the master processor chip
        TARGETING::Target* l_pTarget = NULL;
        TARGETING::targetService().masterProcChipTargetHandle(l_pTarget);
        TARGETING::EntityPath l_id =
            l_pTarget->getAttr<TARGETING::ATTR_PHYS_PATH>();

        do
        {
            // Get any existing Deconfigure Record for the chip
            l_pErr = HWAS::theDeconfigGard().getDeconfigureRecords(&l_id,
                                                                   l_records);
            
            if (l_pErr)
            {
                TS_FAIL("testDeconfigure4: Error from getDeconfigureRecords");
                break;
            }
            
            if (l_records.size() != 0)
            {
                TS_TRACE(INFO_MRK "testDeconfigure4: Chip has existing Deconfigure Record, skipping test");
                break;
            }
            
            // Get the current HWAS_STATE of the chip
            TARGETING::HwasState l_origState =
                l_pTarget->getAttr<TARGETING::ATTR_HWAS_STATE>();
 
            // Deconfigure the chip. Production code will pass a valid PLID
            l_pErr = HWAS::theDeconfigGard().deconfigureTarget(*l_pTarget, 0);
        
            if (l_pErr)
            {
                TS_FAIL("testDeconfigure4: Error from deconfigureTarget");
                break;
            }
            
            // Deconfigure the chip again
            l_pErr = HWAS::theDeconfigGard().deconfigureTarget(*l_pTarget, 0);
        
            if (l_pErr)
            {
                TS_FAIL("testDeconfigure4: Error from deconfigureTarget (2)");
                break;
            }
            
            // Get the new HWAS_STATE of the chip
            TARGETING::HwasState l_state =
                l_pTarget->getAttr<TARGETING::ATTR_HWAS_STATE>();
                
            if (l_state.functional)
            {
                TS_FAIL("testDeconfigure4: Chip functional after deconfigure");
                // intentionally continue
            }
            
            // Get the Deconfigure Record for the chip
            l_pErr = HWAS::theDeconfigGard().getDeconfigureRecords(&l_id,
                                                                   l_records);
            
            if (l_pErr)
            {
                TS_FAIL("testDeconfigure4: Error from getDeconfigureRecords (2)");
                break;
            }
            
            // The second Deconfigure should not have created a new record
            if (l_records.size() != 1)
            {
                TS_FAIL("testDeconfigure4: %d records for chip, expected 1",
                        l_records.size());
                break;
            }
            
            // Reset the HWAS_STATE of the chip
            l_pTarget->setAttr<TARGETING::ATTR_HWAS_STATE>(l_origState);
            
            // Clear the Deconfigure Record
            HWAS::theDeconfigGard()._clearDeconfigureRecords(&l_id);
            
            TS_TRACE(INFO_MRK "testDeconfigure4: Success");
        }
        while (0);
        
        if (l_pErr)
        {
            errlCommit(l_pErr,HWAS_COMP_ID);
        }
#endif
    }

    /**
     *  @brief Test getting all GARD Records
     */
    void testGard1()
    {
        TS_TRACE(INFO_MRK "testGard1: Started");
        
        errlHndl_t l_pErr = NULL;
        HWAS::DeconfigGard::GardRecords_t l_records;

        l_pErr = HWAS::theDeconfigGard().getGardRecords(0, l_records);
        
        if (l_pErr)
        {
            errlCommit(l_pErr,HWAS_COMP_ID);
            TS_FAIL("testGard1: Error from getGardRecords");
        }
        else
        {
            TS_TRACE(INFO_MRK "testGard1: Success. %d records",
                     l_records.size());
        }
    }
    
    /**
     *  @brief Test getting GARD Records with a bad record ID).
     */
    void testGard2()
    {
        TS_TRACE(INFO_MRK "testGard2: Started");
        
        errlHndl_t l_pErr = NULL;
        HWAS::DeconfigGard::GardRecords_t l_records;

        l_pErr = HWAS::theDeconfigGard().getGardRecords(0x12345678, l_records);
        
        if (l_pErr)
        {
            errlCommit(l_pErr,HWAS_COMP_ID);
            TS_FAIL("testGard2: Error from getGardRecords");
        }
        else
        {
            if (l_records.size())
            {
                TS_FAIL("testGard2: %d records found for bad ID",
                        l_records.size());
            }
            else
            {
                TS_TRACE(INFO_MRK "testGard2: Success");
            }
        }
    }
    
    /**
     *  @brief Test getting GARD Records for a specific target
     */
    void testGard3()
    {
        TS_TRACE(INFO_MRK "testGard3: Started");
        
        errlHndl_t l_pErr = NULL;
        HWAS::DeconfigGard::GardRecords_t l_records;
        
        // Get the master processor chip
        TARGETING::Target* l_pTarget = NULL;
        TARGETING::targetService().masterProcChipTargetHandle(l_pTarget);
        TARGETING::EntityPath l_id =
            l_pTarget->getAttr<TARGETING::ATTR_PHYS_PATH>();
        

        // Get all GARD Records for the Target
        l_pErr = HWAS::theDeconfigGard().getGardRecords(l_id, l_records);
        
        if (l_pErr)
        {
            errlCommit(l_pErr,HWAS_COMP_ID);
            TS_FAIL("testGard3: Error from getGardRecords");
        }
        else
        {
            TS_TRACE(INFO_MRK "testGard3: Success. %d records",
                     l_records.size());
        }
    }

    /**
     *  @brief Test creating a GARD Record, getting the GARD Record and
     *         clearing the GARD Record
     */
    void testGard4()
    {
        TS_TRACE(INFO_MRK "testGard4: Started");
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
        
        errlHndl_t l_pErr = NULL;
        HWAS::DeconfigGard::GardRecords_t l_records;
        
        // Get the master processor chip
        TARGETING::Target* l_pTarget = NULL;
        TARGETING::targetService().masterProcChipTargetHandle(l_pTarget);
        TARGETING::EntityPath l_id =
            l_pTarget->getAttr<TARGETING::ATTR_PHYS_PATH>();

        do
        {
            // Get any existing GARD Records for the chip
            l_pErr = HWAS::theDeconfigGard().getGardRecords(l_id, l_records);
            
            if (l_pErr)
            {
                TS_FAIL("testGard4: Error from getGardRecords");
                break;
            }
            
            if (l_records.size() != 0)
            {
                TS_TRACE(INFO_MRK "testGard4: Chip has %d existing Gard Records, skipping test",
                         l_records.size());
                break;
            }
            
            // Create a GARD Record for the chip. Production code will pass a
            // valid PLID
            l_pErr = HWAS::theDeconfigGard().
                createGardRecord(*l_pTarget, 0,
                                 HWAS::GARD_Predictive);
        
            if (l_pErr)
            {
                TS_FAIL("testGard4: Error from createGardRecord");
                break;
            }

            // Get the GARD Records for the chip
            l_pErr = HWAS::theDeconfigGard().getGardRecords(l_id, l_records);
            
            if (l_pErr)
            {
                TS_FAIL("testGard4: Error from getGardRecords (2)");
                break;
            }
            
            if (l_records.size() != 1)
            {
                TS_FAIL("testGard4: %d records for chip, expected 1",
                        l_records.size());
                break;
            }
            
            if (l_records[0].iv_errorType !=
                HWAS::GARD_Predictive)
            {
                TS_FAIL("testGard4: Record errorType %d, expected predictive",
                        l_records[0].iv_errorType);
                break;
            }
            
            // Clear the GARD Records for the chip
            l_pErr = HWAS::theDeconfigGard().clearGardRecords(l_id);
            
            if (l_pErr)
            {
                TS_FAIL("testGard4: Error from clearGardRecords");
                break;
            }
            
            // Get the GARD Records for the chip
            l_records.clear();
            
            l_pErr = HWAS::theDeconfigGard().getGardRecords(l_id, l_records);
            
            if (l_pErr)
            {
                TS_FAIL("testGard4: Error from getGardRecords (3)");
                break;
            }
            
            if (l_records.size() != 0)
            {
                TS_FAIL("testGard4: %d records for chip, expected 0",
                        l_records.size());
                break;
            }
            
            TS_TRACE(INFO_MRK "testGard4: Success");
        }
        while (0);
                
        if (l_pErr)
        {
            errlCommit(l_pErr,HWAS_COMP_ID);
        }
#endif
    }
    
    /**
     *  @brief Test creating a GARD Record for a Target multiple times
     */
    void testGard5()
    {
        TS_TRACE(INFO_MRK "testGard5: Started");
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
        
        errlHndl_t l_pErr = NULL;
        HWAS::DeconfigGard::GardRecords_t l_records;
        
        // Get the master processor chip
        TARGETING::Target* l_pTarget = NULL;
        TARGETING::targetService().masterProcChipTargetHandle(l_pTarget);
        TARGETING::EntityPath l_id =
            l_pTarget->getAttr<TARGETING::ATTR_PHYS_PATH>();

        do
        {
            // Get any existing GARD Records for the chip
            l_pErr = HWAS::theDeconfigGard().getGardRecords(l_id, l_records);
            
            if (l_pErr)
            {
                TS_FAIL("testGard5: Error from getGardRecords");
                break;
            }
            
            if (l_records.size() != 0)
            {
                TS_TRACE(INFO_MRK "testGard5: Chip has %d existing Gard Records, skipping test",
                         l_records.size());
                break;
            }
            
            // Create a GARD Record for the chip. Production code will pass a
            // valid PLID
            l_pErr = HWAS::theDeconfigGard().
                createGardRecord(*l_pTarget, 0,
                                 HWAS::GARD_Predictive);
        
            if (l_pErr)
            {
                TS_FAIL("testGard5: Error from createGardRecord");
                break;
            }
            
            // Create another GARD Record for the chip
            l_pErr = HWAS::theDeconfigGard().
                createGardRecord(*l_pTarget, 0,
                                 HWAS::GARD_Fatal);
        
            if (l_pErr)
            {
                TS_FAIL("testGard5: Error from createGardRecord (2)");
                break;
            }

            // Get the GARD Records for the chip
            l_pErr = HWAS::theDeconfigGard().getGardRecords(l_id, l_records);
            
            if (l_pErr)
            {
                TS_FAIL("testGard5: Error from getGardRecords (2)");
                break;
            }
            
            if (l_records.size() != 2)
            {
                TS_FAIL("testGard5: %d records for chip, expected 2",
                        l_records.size());
                break;
            }
            
            // Clear the GARD Records for the chip
            l_pErr = HWAS::theDeconfigGard().clearGardRecords(l_id);
            
            if (l_pErr)
            {
                TS_FAIL("testGard5: Error from clearGardRecords");
                break;
            }
            
            // Get the GARD Records for the chip
            l_records.clear();
            
            l_pErr = HWAS::theDeconfigGard().getGardRecords(l_id, l_records);
            
            if (l_pErr)
            {
                TS_FAIL("testGard5: Error from getGardRecords (3)");
                break;
            }
            
            if (l_records.size() != 0)
            {
                TS_FAIL("testGard5: %d records for chip, expected 0",
                        l_records.size());
                break;
            }
            
            TS_TRACE(INFO_MRK "testGard5: Success");
        }
        while (0);
                
        if (l_pErr)
        {
            errlCommit(l_pErr,HWAS_COMP_ID);
        }
#endif
    }
    
    /**
     *  @brief Test getting and clearing GARD Records by recordID
     */
    void testGard6()
    {
        TS_TRACE(INFO_MRK "testGard6: Started");
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
        
        errlHndl_t l_pErr = NULL;
        HWAS::DeconfigGard::GardRecords_t l_records;
        
        // Get the master processor chip
        TARGETING::Target* l_pTarget = NULL;
        TARGETING::targetService().masterProcChipTargetHandle(l_pTarget);
        TARGETING::EntityPath l_id =
            l_pTarget->getAttr<TARGETING::ATTR_PHYS_PATH>();
        
        do
        {
            // Get any existing GARD Records for the chip
            l_pErr = HWAS::theDeconfigGard().getGardRecords(l_id, l_records);
            
            if (l_pErr)
            {
                TS_FAIL("testGard6: Error from getGardRecords");
                break;
            }
            
            if (l_records.size() != 0)
            {
                TS_TRACE(INFO_MRK "testGard6: Chip has %d existing Gard Records, skipping test",
                         l_records.size());
                break;
            }
            
            // Create a GARD Record for the chip. Production code will pass a
            // valid PLID
            l_pErr = HWAS::theDeconfigGard().
                createGardRecord(*l_pTarget, 0,
                                 HWAS::GARD_Predictive);
        
            if (l_pErr)
            {
                TS_FAIL("testGard6: Error from createGardRecord");
                break;
            }
            
            // Create another GARD Record for the chip
            l_pErr = HWAS::theDeconfigGard().
                createGardRecord(*l_pTarget, 0,
                                 HWAS::GARD_Fatal);
        
            if (l_pErr)
            {
                TS_FAIL("testGard6: Error from createGardRecord (2)");
                break;
            }

            // Get the GARD Records for the chip
            l_pErr = HWAS::theDeconfigGard().getGardRecords(l_id, l_records);
            
            if (l_pErr)
            {
                TS_FAIL("testGard6: Error from getGardRecords (2)");
                break;
            }
            
            if (l_records.size() != 2)
            {
                TS_FAIL("testGard6: %d records for chip, expected 2",
                        l_records.size());
                break;
            }
            
            // Get the first GARD Record for the chip by Record ID
            uint32_t l_recordID = l_records[0].iv_recordId;
            l_records.clear();
            
            l_pErr = HWAS::theDeconfigGard().getGardRecords(l_recordID,
                                                            l_records);
            
            if (l_pErr)
            {
                TS_FAIL("testGard6: Error from getGardRecords (3)");
                break;
            }
            
            if (l_records.size() != 1)
            {
                TS_FAIL("testGard6: %d records for chip, expected 1",
                        l_records.size());
                break;
            }
            
            // Clear the first GARD Record for the chip by Record ID
            l_pErr = HWAS::theDeconfigGard().clearGardRecords(l_recordID);
            
            if (l_pErr)
            {
                TS_FAIL("testGard6: Error from clearGardRecords");
                break;
            }
            
            // Get the GARD Records for the chip
            l_records.clear();
            
            l_pErr = HWAS::theDeconfigGard().getGardRecords(l_id, l_records);
            
            if (l_pErr)
            {
                TS_FAIL("testGard6: Error from getGardRecords (4)");
                break;
            }
            
            if (l_records.size() != 1)
            {
                TS_FAIL("testGard6: %d records for chip, expected 1 (2)",
                        l_records.size());
                break;
            }
            
            // Clear the GARD Records for the chip
            l_pErr = HWAS::theDeconfigGard().clearGardRecords(l_id);
            
            if (l_pErr)
            {
                TS_FAIL("testGard6: Error from clearGardRecords");
                break;
            }
            
            TS_TRACE(INFO_MRK "testGard6: Success");
        }
        while (0);
                
        if (l_pErr)
        {
            errlCommit(l_pErr,HWAS_COMP_ID);
        }
#endif
    }
    
    /**
     *  @brief Test getting and clearing all GARD Records
     */
    void testGard7()
    {
        TS_TRACE(INFO_MRK "testGard7: Started");
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
        
        errlHndl_t l_pErr = NULL;
        HWAS::DeconfigGard::GardRecords_t l_records;
        
        // Get the master processor chip
        TARGETING::Target* l_pTarget = NULL;
        TARGETING::targetService().masterProcChipTargetHandle(l_pTarget);
        TARGETING::EntityPath l_id =
            l_pTarget->getAttr<TARGETING::ATTR_PHYS_PATH>();

        do
        {
            // Get all existing GARD Records
            l_pErr = HWAS::theDeconfigGard().getGardRecords(0, l_records);
            
            if (l_pErr)
            {
                TS_FAIL("testGard7: Error from getGardRecords");
                break;
            }
            
            if (l_records.size() != 0)
            {
                TS_TRACE(INFO_MRK "testGard7: %d existing Gard Records, skipping test",
                         l_records.size());
                break;
            }
            
            // Create a GARD Record for the chip. Production code will pass a
            // valid PLID
            l_pErr = HWAS::theDeconfigGard().
                createGardRecord(*l_pTarget, 0,
                                 HWAS::GARD_Predictive);
        
            if (l_pErr)
            {
                TS_FAIL("testGard7: Error from createGardRecord");
                break;
            }
            
            // Create another GARD Record for the chip
            l_pErr = HWAS::theDeconfigGard().
                createGardRecord(*l_pTarget, 0,
                                 HWAS::GARD_Fatal);
        
            if (l_pErr)
            {
                TS_FAIL("testGard7: Error from createGardRecord (2)");
                break;
            }

            // Clear all GARD Records
            l_pErr = HWAS::theDeconfigGard().clearGardRecords(0);
            
            if (l_pErr)
            {
                TS_FAIL("testGard7: Error from clearGardRecords");
                break;
            }
            
            // Get the GARD Records
            l_records.clear();
            
            l_pErr = HWAS::theDeconfigGard().getGardRecords(0, l_records);
            
            if (l_pErr)
            {
                TS_FAIL("testGard7: Error from getGardRecords (2)");
                break;
            }
            
            if (l_records.size() != 0)
            {
                TS_FAIL("testGard7: %d records for chip, expected 0",
                        l_records.size());
                break;
            }
            
            TS_TRACE(INFO_MRK "testGard7: Success");
        }
        while (0);
                
        if (l_pErr)
        {
            errlCommit(l_pErr,HWAS_COMP_ID);
        }
#endif
    }
};

#endif
