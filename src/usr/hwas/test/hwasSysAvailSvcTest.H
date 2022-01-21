/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwas/test/hwasSysAvailSvcTest.H $                     */
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
#ifndef _HWASSYSAVAILTEST_H
#define _HWASSYSAVAILTEST_H

/**
 *  @file hwasSysAvailTest.H
 *
 *  @brief Unit tests for HWAS System Availability Test.
 */

//******************************************************************************
// Includes
//******************************************************************************

// CXXTEST
#include <cxxtest/TestSuite.H>
#include <errl/errlmanager.H>
#include <targeting/common/targetservice.H>
#include <hwas/common/hwas_reasoncodes.H>
#include <hwas/common/hwasCommon.H>
#include <targeting/common/utilFilter.H>


using   namespace   TARGETING;

class HwasSysAvailTest: public CxxTest::TestSuite
{
public:

    enum    TargetState_t  {
        RESTORE         =   0,
        SET_NONFUNC     =   1,
    };


    /*
     *  @brief  Set all or most of the targets in the target list to
     *      i_state ==  SET_NONFUNC :   non-functional
     *      i_state ==  RESTORE     :   back to its' original state
     *  Stores the original State in i_origStates; it is assumed that this
     *  will be called first with SET_NONFUNC to fill in i_origStates.
     *  @param  i_state         - SET_NONFUNC or RESTORE
     *  @param  i_targetHList   -   TargetHandleList of targets to work on
     *  @param  i_origStates    -   array of HWasStates to store the original
     *                              state in.
     *  @param  l_keep          -   number of states to keep (i.e. leave alone)
     *                              when running SET_NONFUNC
     *
     **/

    void    setTargetStates( TargetState_t          i_state,
                             TargetHandleList     & i_targetHList,
                             TARGETING::HwasState   *i_origStates,
                             uint8_t                l_keep=0
                             )
    {

        TARGETING::HwasState    l_fakeState;

        for( uint8_t i = l_keep;
             i < i_targetHList.size();
             i++ )
        {
            TARGETING::Target * l_target  =   i_targetHList[i];

            if ( i_state  == SET_NONFUNC  )
            {
                //  set nonfunctional
                i_origStates[i] =
                    l_target->getAttr<TARGETING::ATTR_HWAS_STATE>();
                l_fakeState =   i_origStates[i];
                TS_TRACE( "setTargetStates: HwasState fakeState: "
                          "deconf=0x%x,PO=0x%x,pres=0x%x,func=0x%x,dumpf=0x%x",
                          l_fakeState.deconfiguredByEid,
                          l_fakeState.poweredOn,
                          l_fakeState.present,
                          l_fakeState.functional,
                          l_fakeState.dumpfunctional
                          );

                l_fakeState.functional  =   0 ;

                l_target->setAttr<TARGETING::ATTR_HWAS_STATE>(l_fakeState);
            }
            else
            {
                // Get fake HWAS state setting
                l_fakeState = l_target->getAttr<TARGETING::ATTR_HWAS_STATE>();

                // Restore to original state.
                l_target->setAttr<TARGETING::ATTR_HWAS_STATE>(i_origStates[i]);
            }
        }   //  endfor
    }

    /**
      *  @brief Verify input resources are resource recovered and then restore
      *         them to original state
      *
      *  @return True if all passes, false otherwise
      */
    bool verifyRecoveredAndRestore(TargetHandleList &i_targetHList,
                                   TARGETING::HwasState *i_origStates)
    {
        bool rc = true;

        for (uint32_t i=0; i < i_targetHList.size(); i++)
        {
            TARGETING::HwasState l_hwasState =
                    i_targetHList[i]->getAttr<TARGETING::ATTR_HWAS_STATE>();
            TS_TRACE( "verifyRecoveredAndRestore: After Recovery - "
                      "HwasState fakeState: "
                      "deconf=0x%x,PO=0x%x,pres=0x%x,func=0x%x,dumpf=0x%x,"
                      "specdeconfig=0x%x",
                      l_hwasState.deconfiguredByEid,
                      l_hwasState.poweredOn,
                      l_hwasState.present,
                      l_hwasState.functional,
                      l_hwasState.dumpfunctional,
                      l_hwasState.specdeconfig
                      );

            // Verify resources were brought back to life by resource recovery
            if ((l_hwasState.deconfiguredByEid !=
                    DeconfigGard::CONFIGURED_BY_RESOURCE_RECOVERY) ||
                (l_hwasState.specdeconfig != 0) ||
                (l_hwasState.functional != 1))
            {
                TS_INFO( "verifyRecoveredAndRestore: After Recovery - "
                         "HwasState fakeState: "
                         "deconf=0x%x,PO=0x%x,pres=0x%x,func=0x%x,dumpf=0x%x,"
                         "specdeconfig=0x%x",
                         l_hwasState.deconfiguredByEid,
                         l_hwasState.poweredOn,
                         l_hwasState.present,
                         l_hwasState.functional,
                         l_hwasState.dumpfunctional,
                         l_hwasState.specdeconfig
                         );
                TS_FAIL("verifyRecoveredAndRestore: Incorrect resource "
                        "recovery hwas states on %.8X",
                        TARGETING::get_huid(i_targetHList[i]));
                rc = false;
            }

            // Restore old state
            i_targetHList[i]->setAttr<TARGETING::ATTR_HWAS_STATE>(i_origStates[i]);
        }

        // Verify that ATTR_PG isn't wrong anywhere
        for (TargetIterator target = targetService().begin();
             target != targetService().end();
             ++target)
        {
            ATTR_PG_type pg = 0;
            ATTR_PG_MVPD_type mvpd = 0;

            if( target->tryGetAttr<ATTR_PG>(pg)
                &&  target->tryGetAttr<ATTR_PG>(mvpd) )
            {
                if( pg != mvpd )
                {
                    TS_FAIL( "verifyRecoveredAndRestore: ATTR_PG is wrong for %.8X : PG=%.8X, PG_MVPD=%.8X",
                             get_huid(*target),
                             pg,
                             mvpd );
                    rc = false;
                }
            }
        }


        return rc;
    }

    /**
     *  @brief mark all cores nonfunctional and then call checkMinimumHardware()
     */
    void testCheckMinimumHardwareCore()
    {
        errlHndl_t  l_errl  =   NULL;
        TS_TRACE(INFO_MRK "testCheckMinimumHardwareCore");
        HWAS_INF("testCheckMinimumHardwareCore: Started");

        TargetHandleList l_cores;
        getAllChiplets(l_cores, TYPE_CORE, true );
        TS_TRACE( "testCheckMinimumHardwareCore: %d functional cores",
                  l_cores.size() );
        TARGETING::HwasState    l_origStates[ l_cores.size() ]  ;

        TS_TRACE( "testCheckMinimumHardwareCore: set cores nonfunctional");
        setTargetStates( SET_NONFUNC, l_cores, &l_origStates[0]  );

        // Save original Block Spec Deconfig value
        auto pNode = UTIL::getCurrentNodeTarget();
        TARGETING::ATTR_BLOCK_SPEC_DECONFIG_type l_orig_block_spec_deconfig =
            pNode->getAttr<ATTR_BLOCK_SPEC_DECONFIG>();

        // If original attribute value is non-zero, clear it
        if(l_orig_block_spec_deconfig != 0)
        {
            // Clear attribute to test that checkMinimumHardware() sets it
            pNode->setAttr<ATTR_BLOCK_SPEC_DECONFIG>(0);
        }

        TS_TRACE( "testCheckMinimumHardwareCore: check for minimum hardware" );
        l_errl  =   HWAS::checkMinimumHardware();
        if ( l_errl )
        {
            TARGETING::ATTR_BLOCK_SPEC_DECONFIG_type l_block_spec_deconfig =
                pNode->getAttr<ATTR_BLOCK_SPEC_DECONFIG>();
            if(l_block_spec_deconfig == 0)
            {
                TS_FAIL("testCheckMinimumHardwareCore: Expected non-zero value "
                        "for ATTR_BLOCK_SPEC_DECONFIG");
            }
            else
            {
                //  got an errorlog, no cores
                TS_TRACE( "testCheckMinimumHardwareCore: PASSED");
            }
            //  Commit the errorlog.
            errlCommit( l_errl, HWAS_COMP_ID );
        }
        else
        {
            //  no errorlog, bad news
            TS_FAIL( "testCheckMinimumHardwareCore:  FAILED, no errlog" );
        }

        TS_TRACE( "testCheckMinimumHardwareCore: restore original states");
        setTargetStates( RESTORE, l_cores, &(l_origStates[0])  );
        pNode->setAttr<ATTR_BLOCK_SPEC_DECONFIG>(l_orig_block_spec_deconfig);

    }


    /**
     *  @brief mark all dimms nonfunctional and then call checkMinimumHardware()
     */
    void testCheckMinimumHardwareDimm()
    {
        errlHndl_t  l_errl  =   NULL;
        TS_TRACE(INFO_MRK "testCheckMinimumHardwareDimm");
        HWAS_INF("testCheckMinimumHardwareDimm: Started");

        //  check for functional dimms
        TargetHandleList l_dimms;
        getAllLogicalCards(l_dimms, TYPE_DIMM, true );
        TS_TRACE( "testCheckMinimumHardwareDimm: %d functional dimms",
                  l_dimms.size() );

        TARGETING::HwasState    l_origStates[ l_dimms.size() ]  ;

        setTargetStates( SET_NONFUNC, l_dimms, &(l_origStates[0])  );

        // Save original Block Spec Deconfig value
        auto pNode = UTIL::getCurrentNodeTarget();
        TARGETING::ATTR_BLOCK_SPEC_DECONFIG_type l_orig_block_spec_deconfig =
            pNode->getAttr<ATTR_BLOCK_SPEC_DECONFIG>();

        // If original attribute value is non-zero, clear it
        if(l_orig_block_spec_deconfig != 0)
        {
            // Clear attribute to test that checkMinimumHardware() sets it
            pNode->setAttr<ATTR_BLOCK_SPEC_DECONFIG>(0);
        }

        TS_TRACE( "testCheckMinimumHardwareDimm: check for minimum hardware" );
        l_errl  =   HWAS::checkMinimumHardware();
        if ( l_errl )
        {
            TARGETING::ATTR_BLOCK_SPEC_DECONFIG_type l_block_spec_deconfig
                = pNode->getAttr<ATTR_BLOCK_SPEC_DECONFIG>();
            if(l_block_spec_deconfig == 0)
            {
                TS_FAIL("testCheckMinimumHardwareDimm: Expected non-zero value "
                        "for ATTR_BLOCK_SPEC_DECONFIG");
            }
            else
            {
                //  got an errorlog, no dimms
                TS_TRACE( "testCheckMinimumHardwareDimm: PASSED");
            }
            //  Commit the errorlog.
            errlCommit( l_errl, HWAS_COMP_ID );
        }
        else
        {
            //  no errorlog, bad news
            TS_FAIL( "testCheckMinimumHardwareDimm:  FAILED, no errlog" );
        }

        setTargetStates( RESTORE, l_dimms, &(l_origStates[0])  );
        pNode->setAttr<ATTR_BLOCK_SPEC_DECONFIG>(l_orig_block_spec_deconfig);

    }


    /**
     *  @brief mark all cores AND dimms nonfunctional and
     *      then call checkMinimumHardware()
     *  Test should fail and we should have 2 errorlogs with a common plid.
     */
    void testCheckMinimumHardwareBoth()
    {
        errlHndl_t  l_errl  =   NULL;
        TS_TRACE(INFO_MRK "testCheckMinimumHardwareBoth");
        HWAS_INF("testCheckMinimumHardwareBoth: Started");

        //  set all cores nonfunctional
        TargetHandleList l_cores;
        getAllChiplets(l_cores, TYPE_CORE, true );
        TS_TRACE( "testCheckMinimumHardwareBoth: %d functional cores",
                  l_cores.size() );
        TARGETING::HwasState    l_origCoreStates[ l_cores.size() ]  ;
        TS_TRACE( "testCheckMinimumHardwareBoth: set cores nonfunctional");
        setTargetStates( SET_NONFUNC, l_cores, &l_origCoreStates[0]  );

        //  set all dimms nonfunctional
        TargetHandleList l_dimms;
        getAllLogicalCards(l_dimms, TYPE_DIMM, true );
        TS_TRACE( "testCheckMinimumHardwareBoth: %d functional dimms",
                  l_dimms.size() );
        TARGETING::HwasState    l_origDimmStates[ l_dimms.size() ]  ;
        TS_TRACE( "testCheckMinimumHardwareBoth: set dimms nonfunctional");
        setTargetStates( SET_NONFUNC, l_dimms, &(l_origDimmStates[0])  );

        // Save original Block Spec Deconfig value
        auto pNode = UTIL::getCurrentNodeTarget();
        TARGETING::ATTR_BLOCK_SPEC_DECONFIG_type l_orig_block_spec_deconfig =
            pNode->getAttr<ATTR_BLOCK_SPEC_DECONFIG>();

        // If original attribute value is non-zero, clear it
        if(l_orig_block_spec_deconfig != 0)
        {
            // Clear attribute to test that checkMinimumHardware() sets it
            pNode->setAttr<ATTR_BLOCK_SPEC_DECONFIG>(0);
        }

        TS_TRACE( "testCheckMinimumHardwareBoth: check for minimum hardware" );
        l_errl  =   HWAS::checkMinimumHardware();
        if ( l_errl )
        {
            TARGETING::ATTR_BLOCK_SPEC_DECONFIG_type l_block_spec_deconfig
                = pNode->getAttr<ATTR_BLOCK_SPEC_DECONFIG>();
            if(l_block_spec_deconfig == 0)
            {
                TS_FAIL("testCheckMinimumHardwareBoth: Expected non-zero value "
                        "for ATTR_BLOCK_SPEC_DECONFIG");
            }
            else
            {
                //  got an errorlog, this is good.
                //  There should be 2 errorlogs with a common plid.
                TS_TRACE( "testCheckMinimumHardwareBoth: PASSED");
            }
            //  Commit the errorlog.
            errlCommit( l_errl, HWAS_COMP_ID );
        }
        else
        {
            //  no errorlog, bad news
            TS_FAIL( "testCheckMinimumHardwareBoth:  FAILED, no errorlog." );
        }

        //  restore everything to normal.
        setTargetStates( RESTORE, l_cores, &(l_origCoreStates[0])  );
        setTargetStates( RESTORE, l_dimms, &(l_origDimmStates[0])  );
        pNode->setAttr<ATTR_BLOCK_SPEC_DECONFIG>(l_orig_block_spec_deconfig);

    }


    /**
     *  @brief mark all dimms (except 1) nonfunctional and
     *      then call checkMinimumHardware()
     *  Test should pass.
     */
    void testCheckMinimumHardwareOneDimm()
    {
        errlHndl_t  l_errl  =   NULL;
        TS_TRACE(INFO_MRK "testCheckMinimumHardwareOneDimm");
        HWAS_INF("testCheckMinimumHardwareOneDimm: Started");

        //  check for functional dimms
        TargetHandleList l_dimms;
        getAllLogicalCards(l_dimms, TYPE_DIMM, true );
        TS_TRACE( "testCheckMinimumHardwareOneDimm: %d functional dimms",
                  l_dimms.size() );

        TARGETING::HwasState    l_origStates[ l_dimms.size() ]  ;

        setTargetStates( SET_NONFUNC, l_dimms, &(l_origStates[0]), 1  );

        // Save original Block Spec Deconfig value
        auto pNode = UTIL::getCurrentNodeTarget();
        TARGETING::ATTR_BLOCK_SPEC_DECONFIG_type l_orig_block_spec_deconfig =
            pNode->getAttr<ATTR_BLOCK_SPEC_DECONFIG>();

        // If original attribute value is non-zero, clear it
        if(l_orig_block_spec_deconfig != 0)
        {
            // Clear attribute, test that checkMinimumHardware() does NOT set it
            pNode->setAttr<ATTR_BLOCK_SPEC_DECONFIG>(0);
        }

        TS_TRACE( "testCheckMinimumHardwareOneDimm: "
                  "check for minimum hardware" );
        l_errl  =   HWAS::checkMinimumHardware();
        if ( l_errl )
        {
            //  got an errorlog, bad news
            TS_FAIL( "testCheckMinimumHardwareOneDimm:  FAILED " );
            errlCommit( l_errl, HWAS_COMP_ID );
        }
        else
        {
            TARGETING::ATTR_BLOCK_SPEC_DECONFIG_type l_block_spec_deconfig
                = pNode->getAttr<ATTR_BLOCK_SPEC_DECONFIG>();
            if(l_block_spec_deconfig != 0)
            {
                TS_FAIL("testCheckMinimumHardwareOneDimm: Expected zero value "
                        "for ATTR_BLOCK_SPEC_DECONFIG, not %d",
                        l_block_spec_deconfig);
            }
            else
            {
                //  No errorlog, this is good.
                TS_TRACE( "testCheckMinimumHardwareOneDimm: PASSED");
            }
        }

        setTargetStates( RESTORE, l_dimms, &(l_origStates[0]), 1  );
        pNode->setAttr<ATTR_BLOCK_SPEC_DECONFIG>(l_orig_block_spec_deconfig);

    }

    /**
     *  @brief Speculative gard all cores and verify they are recovered
     */
    void testVerifyResourceRecovery()
    {
        do
        {
            errlHndl_t l_errl = NULL;
            TS_TRACE(INFO_MRK "testVerifyResourceRecovery");
            HWAS_INF("testVerifyResourceRecovery: Started");

            TargetHandleList l_cores;
            getAllChiplets(l_cores, TYPE_CORE, true );
            TS_INFO( "testVerifyResourceRecovery: %d functional cores",
                     l_cores.size() );

            // Keep track of original hwas states
            TARGETING::HwasState l_origStates[ l_cores.size() ]  ;
            TS_INFO("testVerifyResourceRecovery: Create predictive gard record"
                    " for all cores");

            for (uint32_t i=0; i < l_cores.size(); i++)
            {
                TARGETING::HwasState l_hwasState =
                                    l_cores[i]->getAttr<TARGETING::ATTR_HWAS_STATE>();
                l_origStates[i] = l_hwasState;
                TS_TRACE( "testVerifyResourceRecovery: HwasState fakeState: "
                          "deconf=0x%x,PO=0x%x,pres=0x%x,func=0x%x,dumpf=0x%x,"
                          "specdeconfig=0x%x",
                          l_hwasState.deconfiguredByEid,
                          l_hwasState.poweredOn,
                          l_hwasState.present,
                          l_hwasState.functional,
                          l_hwasState.dumpfunctional,
                          l_hwasState.specdeconfig
                          );

                // Create a GARD record for all cores
                l_errl = theDeconfigGard().platCreateGardRecord(l_cores[i],
                                                                0xF00 + i,
                                                                GARD_Predictive);
                if (l_errl)
                {
                    TS_FAIL("testVerifyResourceRecovery: Error from "
                            "platCreateGardRecord");
                    break;
                }
            }
            if (l_errl)
            {
                errlCommit( l_errl, HWAS_COMP_ID );
                break;
            }

            TS_INFO("testVerifyResourceRecovery: Enable spec deconfig");

            // Ensure gard will execute speculative deconfig
            auto pNode = UTIL::getCurrentNodeTarget();
            pNode->setAttr<ATTR_BLOCK_SPEC_DECONFIG>(0);

            // Apply gard records and run resource recovery
            l_errl = theDeconfigGard().deconfigureTargetsFromGardRecordsForIpl();
            if ( l_errl )
            {
                TS_FAIL("testVerifyResourceRecovery: Error from "
                        "deconfigureTargetsFromGardRecordsForIpl");
                errlCommit( l_errl, HWAS_COMP_ID );
                break;
            }

            Target* l_pMasterProc = nullptr;
            targetService().queryMasterProcChipTargetHandle(l_pMasterProc);
            TargetHandleList l_cores2;
            getNonEcoCores(l_cores2, l_pMasterProc);
            TS_INFO("testVerifyResourceRecovery: corelist=%d",l_cores2.size());
            for( auto acore : l_cores2 )
            {
                TS_INFO("%.8X",get_huid(acore));
            }


            // Verify all cores have been "Recovered" and then restore
            // old hwas state
            if (!verifyRecoveredAndRestore(l_cores,l_origStates))
            {
                // TS_FAIL logged in function so just exit out
                TS_INFO("testVerifyResourceRecovery: Verify failed");
                break;
            }

            // Verify spec deconfig is disabled (since it's already been
            // run).
            if (pNode->getAttr<ATTR_BLOCK_SPEC_DECONFIG>() != 1)
            {
                TS_FAIL("testVerifyResourceRecovery: Spec deconfig is not "
                        "disabled");
                break;
            }

            // Call the deconfigure interface again and verify even without
            // spec deconfig enabled, that hwas states are still updated properly
            l_errl = theDeconfigGard().deconfigureTargetsFromGardRecordsForIpl();
            if ( l_errl )
            {
                TS_FAIL("testVerifyResourceRecovery: Error from "
                        "deconfigureTargetsFromGardRecordsForIpl");
                errlCommit( l_errl, HWAS_COMP_ID );
                break;
            }

            // Verify cores are functional and resource recovered
            if (!verifyRecoveredAndRestore(l_cores,l_origStates))
            {
                // TS_FAIL logged in function so just exit out
                HWAS_INF("testVerifyResourceRecovery: Verify phase 2 failed");
                break;
            }
            else
            {
                HWAS_INF("testVerifyResourceRecovery: PASSED");
                TS_TRACE("testVerifyResourceRecovery: PASSED");
            }

            // Reset to 0
            pNode->setAttr<ATTR_BLOCK_SPEC_DECONFIG>(0);

            // Clear all gard records
            for (uint32_t i=0; i < l_cores.size(); i++)
            {
                theDeconfigGard().clearGardRecords(l_cores[i]);
            }
        } while(0);
    }

};  // end class


#endif
