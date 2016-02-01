/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwas/test/hwas1test.H $                               */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2016                        */
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
#ifndef __TESTTARGETING_H
#define __TESTTARGETING_H

/**
 *  @file testtargeting.H
 *
 *  @brief Unit tests for HWAS
 */

//******************************************************************************
// Includes
//******************************************************************************

// STD
#include <stdio.h>
#include <sys/time.h>

// CXXTEST
#include <cxxtest/TestSuite.H>
#include <errl/errlmanager.H>

#include <hwas/common/hwas.H>
#include <hwas/common/hwasCommon.H>
#include <targeting/common/commontargeting.H>
#include <targeting/common/utilFilter.H>


// Buffer with all good data (CUMULUS chip)
const uint16_t pgDataAllGood[HWAS::VPD_CP00_PG_DATA_ENTRIES] =
                     {(uint16_t)HWAS::VPD_CP00_PG_FSI_GOOD,
                      (uint16_t)HWAS::VPD_CP00_PG_PERVASIVE_GOOD,
                      (uint16_t)HWAS::VPD_CP00_PG_N0_GOOD,
                      (uint16_t)HWAS::VPD_CP00_PG_N1_GOOD,
                      (uint16_t)HWAS::VPD_CP00_PG_N2_GOOD,
                      (uint16_t)HWAS::VPD_CP00_PG_N3_GOOD,
                      (uint16_t)HWAS::VPD_CP00_PG_XBUS_GOOD,
                      (uint16_t)HWAS::VPD_CP00_PG_MCxx_GOOD,
                      (uint16_t)HWAS::VPD_CP00_PG_MCxx_GOOD,
                      (uint16_t)HWAS::VPD_CP00_PG_OBUS_GOOD,
                      (uint16_t)HWAS::VPD_CP00_PG_OBUS_GOOD,
                      (uint16_t)HWAS::VPD_CP00_PG_OBUS_GOOD,
                      (uint16_t)HWAS::VPD_CP00_PG_OBUS_GOOD,
                      (uint16_t)HWAS::VPD_CP00_PG_PCIx_GOOD[0],
                      (uint16_t)HWAS::VPD_CP00_PG_PCIx_GOOD[1],
                      (uint16_t)HWAS::VPD_CP00_PG_PCIx_GOOD[2],
                      (uint16_t)HWAS::VPD_CP00_PG_EPx_GOOD,
                      (uint16_t)HWAS::VPD_CP00_PG_EPx_GOOD,
                      (uint16_t)HWAS::VPD_CP00_PG_EPx_GOOD,
                      (uint16_t)HWAS::VPD_CP00_PG_EPx_GOOD,
                      (uint16_t)HWAS::VPD_CP00_PG_EPx_GOOD,
                      (uint16_t)HWAS::VPD_CP00_PG_EPx_GOOD,
                      (uint16_t)HWAS::VPD_CP00_PG_RESERVED_GOOD,
                      (uint16_t)HWAS::VPD_CP00_PG_RESERVED_GOOD,
                      (uint16_t)HWAS::VPD_CP00_PG_RESERVED_GOOD,
                      (uint16_t)HWAS::VPD_CP00_PG_RESERVED_GOOD,
                      (uint16_t)HWAS::VPD_CP00_PG_RESERVED_GOOD,
                      (uint16_t)HWAS::VPD_CP00_PG_RESERVED_GOOD,
                      (uint16_t)HWAS::VPD_CP00_PG_RESERVED_GOOD,
                      (uint16_t)HWAS::VPD_CP00_PG_RESERVED_GOOD,
                      (uint16_t)HWAS::VPD_CP00_PG_RESERVED_GOOD,
                      (uint16_t)HWAS::VPD_CP00_PG_RESERVED_GOOD,
                      (uint16_t)HWAS::VPD_CP00_PG_ECxx_GOOD,
                      (uint16_t)HWAS::VPD_CP00_PG_ECxx_GOOD,
                      (uint16_t)HWAS::VPD_CP00_PG_ECxx_GOOD,
                      (uint16_t)HWAS::VPD_CP00_PG_ECxx_GOOD,
                      (uint16_t)HWAS::VPD_CP00_PG_ECxx_GOOD,
                      (uint16_t)HWAS::VPD_CP00_PG_ECxx_GOOD,
                      (uint16_t)HWAS::VPD_CP00_PG_ECxx_GOOD,
                      (uint16_t)HWAS::VPD_CP00_PG_ECxx_GOOD,
                      (uint16_t)HWAS::VPD_CP00_PG_ECxx_GOOD,
                      (uint16_t)HWAS::VPD_CP00_PG_ECxx_GOOD,
                      (uint16_t)HWAS::VPD_CP00_PG_ECxx_GOOD,
                      (uint16_t)HWAS::VPD_CP00_PG_ECxx_GOOD,
                      (uint16_t)HWAS::VPD_CP00_PG_ECxx_GOOD,
                      (uint16_t)HWAS::VPD_CP00_PG_ECxx_GOOD,
                      (uint16_t)HWAS::VPD_CP00_PG_ECxx_GOOD,
                      (uint16_t)HWAS::VPD_CP00_PG_ECxx_GOOD,
                      (uint16_t)HWAS::VPD_CP00_PG_ECxx_GOOD,
                      (uint16_t)HWAS::VPD_CP00_PG_ECxx_GOOD,
                      (uint16_t)HWAS::VPD_CP00_PG_ECxx_GOOD,
                      (uint16_t)HWAS::VPD_CP00_PG_ECxx_GOOD,
                      (uint16_t)HWAS::VPD_CP00_PG_ECxx_GOOD,
                      (uint16_t)HWAS::VPD_CP00_PG_ECxx_GOOD,
                      (uint16_t)HWAS::VPD_CP00_PG_ECxx_GOOD,
                      (uint16_t)HWAS::VPD_CP00_PG_ECxx_GOOD,
                      (uint16_t)HWAS::VPD_CP00_PG_RESERVED_GOOD,
                      (uint16_t)HWAS::VPD_CP00_PG_RESERVED_GOOD,
                      (uint16_t)HWAS::VPD_CP00_PG_RESERVED_GOOD,
                      (uint16_t)HWAS::VPD_CP00_PG_RESERVED_GOOD,
                      (uint16_t)HWAS::VPD_CP00_PG_RESERVED_GOOD,
                      (uint16_t)HWAS::VPD_CP00_PG_RESERVED_GOOD,
                      (uint16_t)HWAS::VPD_CP00_PG_RESERVED_GOOD,
                      (uint16_t)HWAS::VPD_CP00_PG_RESERVED_GOOD};

class HWAS1test: public CxxTest::TestSuite
{
public:


    /**
     * @brief   Write to all the attributes and then read them back.
     */
    void    testHWASReadWrite()
    {
        using namespace TARGETING;

        TARGETING::HwasState    l_orgHwasState, l_hwasState;
        TARGETING::TargetIterator l_pTarget;

        TS_TRACE( "testHWASReadWrite entry" );

        //  write a pattern to all HWAS attributes and then read them back
        for(    l_pTarget = TARGETING::targetService().begin();
                l_pTarget != TARGETING::targetService().end();
                ++l_pTarget
                )
        {
            //  save original state
            l_orgHwasState  =   l_pTarget->getAttr<ATTR_HWAS_STATE>();

            //  modify state
            l_hwasState     =   l_pTarget->getAttr<ATTR_HWAS_STATE>();
            l_hwasState.deconfiguredByEid     =   0x12345678;
            l_hwasState.poweredOn             =   true;
            l_hwasState.present               =   true;
            l_hwasState.functional            =   true;

            //  Now write the modified value back to Targeting.
            l_pTarget->setAttr<ATTR_HWAS_STATE>( l_hwasState );

            // fetch and test new values
            if ( l_pTarget->getAttr<ATTR_HWAS_STATE>().deconfiguredByEid
                                != 0x12345678 )
            {
                TS_FAIL( " deconfiguredByEid = 0x%x, should be 0x12345678",
                        l_pTarget->getAttr<ATTR_HWAS_STATE>().
                                deconfiguredByEid );
            }

            if ( l_pTarget->getAttr<ATTR_HWAS_STATE>().poweredOn != true )
            {
                TS_FAIL( "poweredOn = 0x%x, should be true",
                        l_pTarget->getAttr<ATTR_HWAS_STATE>().poweredOn );
            }

            if ( l_pTarget->getAttr<ATTR_HWAS_STATE>().present != true )
            {
                TS_FAIL( " present   = 0x%x should be true",
                        l_pTarget->getAttr<ATTR_HWAS_STATE>().present   );
            }

            if ( l_pTarget->getAttr<ATTR_HWAS_STATE>().functional != true )
            {
                TS_FAIL( " functional = 0x%x, should be true",
                        l_pTarget->getAttr<ATTR_HWAS_STATE>().functional );
            }

            //
            //  Now write the original value back.
            //
            l_pTarget->setAttr<ATTR_HWAS_STATE>( l_orgHwasState );

            // check that it got written back correctly
            if ( l_pTarget->getAttr<ATTR_HWAS_STATE>().poweredOn
                    != l_orgHwasState.poweredOn )
            {
                TS_FAIL( "poweredOn = 0x%x, not restored",
                        l_pTarget->getAttr<ATTR_HWAS_STATE>().poweredOn );
            }

            if ( l_pTarget->getAttr<ATTR_HWAS_STATE>().present
                    != l_orgHwasState.present )
            {
                TS_FAIL( " present   = 0x%x, not restored",
                        l_pTarget->getAttr<ATTR_HWAS_STATE>().present   );
            }

            if ( l_pTarget->getAttr<ATTR_HWAS_STATE>().functional
                    != l_orgHwasState.functional )
            {
                TS_FAIL( " functional = 0x%x, not restored",
                        l_pTarget->getAttr<ATTR_HWAS_STATE>().functional );
            }

        }

        TS_TRACE( "testHWASReadWrite exit" );
    }

    /**
     * @brief   test platReadIDEC
     */
    void testHWASplatReadIDEC()
    {
        using namespace TARGETING;

        TS_TRACE( "testHWASplatReadIDEC entry" );

        // call platReadIDEC with target that doesn't have an ID/EC
        errlHndl_t l_errl;

        Target* pSys;
        targetService().getTopLevelTarget(pSys);

        l_errl = HWAS::platReadIDEC(pSys);

        if (l_errl)
        {
            // error log is expected case, delete it
            delete l_errl;
        }
        else
        {
            TS_FAIL("testHWASplatReadIDEC>"
                    "No error from platReadIDEC(pSys).");
        }

        TS_TRACE( "testHWASplatReadIDEC exit" );
    }

    /**
     * @brief   test platReadPartialGood
     */
    void testHWASplatReadPartialGood()
    {
        using namespace TARGETING;

        TS_TRACE( "testHWASplatReadPartialGood entry" );

        // call platReadPartialGood with target that isn't in the VPD
        errlHndl_t l_errl;

        Target* pSys;
        targetService().getTopLevelTarget(pSys);
        uint8_t pgData[HWAS::VPD_CP00_PG_DATA_LENGTH];

        l_errl = HWAS::platReadPartialGood(pSys, pgData);

        if (l_errl)
        {
            // error log is expected case, delete it
            delete l_errl;
        }
        else
        {
            TS_FAIL("testHWASplatReadPartialGood>"
                    "No error from platReadPartialGood(pSys).");
        }

        TS_TRACE( "testHWASplatReadPartialGood exit" );
    }

    /**
     * @brief   test isChipFunctional
     */
    void testHWASisChipFunctional()
    {
        using namespace HWAS;
        using namespace TARGETING;

        TS_TRACE( "testHWASisChipFunctional entry" );

        // Get list of all targets with type PROC
        TargetHandleList allProcs;
        getAllChips( allProcs, TYPE_PROC, false );

        for (TargetHandleList::const_iterator pTarget_it = allProcs.begin();
             pTarget_it != allProcs.end();
             ++pTarget_it
            )
        {
            TargetHandle_t pTarget = *pTarget_it;
            ATTR_MODEL_type l_model = pTarget->getAttr<ATTR_MODEL>();
            uint16_t l_xbus = (MODEL_NIMBUS == l_model)
                            ? (uint16_t)(VPD_CP00_PG_XBUS_GOOD |
                                         VPD_CP00_PG_XBUS_IOX_PAIR[0])
                            : (uint16_t)VPD_CP00_PG_XBUS_GOOD;
            uint16_t l_obus12 = (MODEL_NIMBUS == l_model)
                              ? (uint16_t)VPD_CP00_PG_RESERVED_GOOD
                              : (uint16_t)VPD_CP00_PG_OBUS_GOOD;
            uint16_t pgData[VPD_CP00_PG_DATA_ENTRIES];
            memcpy(pgData,
                   pgDataAllGood,
                   VPD_CP00_PG_DATA_LENGTH);
            pgData[VPD_CP00_PG_XBUS_INDEX] = l_xbus;
            pgData[VPD_CP00_PG_OB0_INDEX + 1] =  l_obus12;
            pgData[VPD_CP00_PG_OB0_INDEX + 2] =  l_obus12;
            uint16_t l_mask = 0x8000;

            TS_TRACE( "testHWASisChipFunctional: chip is functional");
            if (!isChipFunctional(pTarget, pgData))
            {
                TS_FAIL("testHWASisChipFunctional>"
                        "functional = 0x%x, should be true.",
                        isChipFunctional(pTarget, pgData));
            }

            TS_TRACE( "testHWASisChipFunctional: partial good all bad");
            pgData[VPD_CP00_PG_N1_INDEX] |= VPD_CP00_PG_N1_PG_MASK;
            pgData[VPD_CP00_PG_N3_INDEX] |= VPD_CP00_PG_N3_PG_MASK;
            pgData[VPD_CP00_PG_XBUS_INDEX] |= VPD_CP00_PG_XBUS_PG_MASK;

            if (!isChipFunctional(pTarget, pgData))
            {
                TS_FAIL("testHWASisChipFunctional>"
                        "functional = 0x%x, should be true.",
                        isChipFunctional(pTarget, pgData));
            }

            pgData[VPD_CP00_PG_N1_INDEX] &= ~VPD_CP00_PG_N1_PG_MASK;
            pgData[VPD_CP00_PG_N3_INDEX] &= ~VPD_CP00_PG_N3_PG_MASK;
            pgData[VPD_CP00_PG_XBUS_INDEX] = l_xbus;

            TS_TRACE( "testHWASisChipFunctional: FSI is not functional");
            for (l_mask = 0x8000;
                 l_mask > 0;
                 l_mask >>= 1)
            {
                if (pgData[VPD_CP00_PG_FSI_INDEX] & l_mask)
                {
                    // Turn off a bit that should be on
                    pgData[VPD_CP00_PG_FSI_INDEX] &= ~l_mask;
                }
                else
                {
                    // Turn on a bit that should be off
                    pgData[VPD_CP00_PG_FSI_INDEX] |= l_mask;
                }

                if (isChipFunctional(pTarget, pgData))
                {
                    TS_FAIL("testHWASisChipFunctional>"
                            "functional = 0x%x, should be false, "
                            "FSI = 0x%04x, mask = 0x%04x.",
                            isChipFunctional(pTarget, pgData),
                            pgData[VPD_CP00_PG_FSI_INDEX],
                            l_mask);
                }

                // Restore the "all good" data
                pgData[VPD_CP00_PG_FSI_INDEX] =
                    (uint16_t)VPD_CP00_PG_FSI_GOOD;
            }

            TS_TRACE( "testHWASisChipFunctional: PRV is not functional");
            for (l_mask = 0x8000;
                 l_mask > 0;
                 l_mask >>= 1)
            {
                if (pgData[VPD_CP00_PG_PERVASIVE_INDEX] & l_mask)
                {
                    // Turn off a bit that should be on
                    pgData[VPD_CP00_PG_PERVASIVE_INDEX] &= ~l_mask;
                }
                else
                {
                    // Turn on a bit that should be off
                    pgData[VPD_CP00_PG_PERVASIVE_INDEX] |= l_mask;
                }

                if (isChipFunctional(pTarget, pgData))
                {
                    TS_FAIL("testHWASisChipFunctional>"
                            "functional = 0x%x, should be false, "
                            "PRV = 0x%04x, mask = 0x%04x.",
                            isChipFunctional(pTarget, pgData),
                            pgData[VPD_CP00_PG_PERVASIVE_INDEX],
                            l_mask);
                }

                // Restore the "all good" data
                pgData[VPD_CP00_PG_PERVASIVE_INDEX] =
                    (uint16_t)VPD_CP00_PG_PERVASIVE_GOOD;
            }

            TS_TRACE( "testHWASisChipFunctional: N0 is not functional");
            for (l_mask = 0x8000;
                 l_mask > 0;
                 l_mask >>= 1)
            {
                if (pgData[VPD_CP00_PG_N0_INDEX] & l_mask)
                {
                    // Turn off a bit that should be on
                    pgData[VPD_CP00_PG_N0_INDEX] &= ~l_mask;
                }
                else
                {
                    // Turn on a bit that should be off
                    pgData[VPD_CP00_PG_N0_INDEX] |= l_mask;
                }

                if (isChipFunctional(pTarget, pgData))
                {
                    TS_FAIL("testHWASisChipFunctional>"
                            "functional = 0x%x, should be false, "
                            "N0 = 0x%04x, mask = 0x%04x.",
                            isChipFunctional(pTarget, pgData),
                            pgData[VPD_CP00_PG_N0_INDEX],
                            l_mask);
                }

                // Restore the "all good" data
                pgData[VPD_CP00_PG_N0_INDEX] =
                    (uint16_t)VPD_CP00_PG_N0_GOOD;
            }

            TS_TRACE( "testHWASisChipFunctional: N1 is not functional");
            for (l_mask = 0x8000;
                 l_mask > 0;
                 l_mask >>= 1)
            {
                if ((uint16_t)VPD_CP00_PG_N1_PG_MASK & l_mask)
                {
                     // Ignore partial good region
                     continue;
                }
                else
                if (pgData[VPD_CP00_PG_N1_INDEX] & l_mask)
                {
                    // Turn off a bit that should be on
                    pgData[VPD_CP00_PG_N1_INDEX] &= ~l_mask;
                }
                else
                {
                    // Turn on a bit that should be off
                    pgData[VPD_CP00_PG_N1_INDEX] |= l_mask;
                }

                if (isChipFunctional(pTarget, pgData))
                {
                    TS_FAIL("testHWASisChipFunctional>"
                            "functional = 0x%x, should be false, "
                            "N1 = 0x%04x, mask = 0x%04x.",
                            isChipFunctional(pTarget, pgData),
                            pgData[VPD_CP00_PG_N1_INDEX],
                            l_mask);
                }

                // Restore the "all good" data
                pgData[VPD_CP00_PG_N1_INDEX] =
                    (uint16_t)VPD_CP00_PG_N1_GOOD;
            }

            TS_TRACE( "testHWASisChipFunctional: N2 is not functional");
            for (l_mask = 0x8000;
                 l_mask > 0;
                 l_mask >>= 1)
            {
                if (pgData[VPD_CP00_PG_N2_INDEX] & l_mask)
                {
                    // Turn off a bit that should be on
                    pgData[VPD_CP00_PG_N2_INDEX] &= ~l_mask;
                }
                else
                {
                    // Turn on a bit that should be off
                    pgData[VPD_CP00_PG_N2_INDEX] |= l_mask;
                }

                if (isChipFunctional(pTarget, pgData))
                {
                    TS_FAIL("testHWASisChipFunctional>"
                            "functional = 0x%x, should be false, "
                            "N2 = 0x%04x, mask = 0x%04x.",
                            isChipFunctional(pTarget, pgData),
                            pgData[VPD_CP00_PG_N2_INDEX],
                            l_mask);
                }

                // Restore the "all good" data
                pgData[VPD_CP00_PG_N2_INDEX] =
                    (uint16_t)VPD_CP00_PG_N2_GOOD;
            }

            TS_TRACE( "testHWASisChipFunctional: N3 is not functional");
            for (l_mask = 0x8000;
                 l_mask > 0;
                 l_mask >>= 1)
            {
                if ((uint16_t)VPD_CP00_PG_N3_PG_MASK & l_mask)
                {
                     // Ignore partial good region
                     continue;
                }
                else
                if (pgData[VPD_CP00_PG_N3_INDEX] & l_mask)
                {
                    // Turn off a bit that should be on
                    pgData[VPD_CP00_PG_N3_INDEX] &= ~l_mask;
                }
                else
                {
                    // Turn on a bit that should be off
                    pgData[VPD_CP00_PG_N3_INDEX] |= l_mask;
                }

                if (isChipFunctional(pTarget, pgData))
                {
                    TS_FAIL("testHWASisChipFunctional>"
                            "functional = 0x%x, should be false, "
                            "N3 = 0x%04x, mask = 0x%04x.",
                            isChipFunctional(pTarget, pgData),
                            pgData[VPD_CP00_PG_N3_INDEX],
                            l_mask);
                }

                // Restore the "all good" data
                pgData[VPD_CP00_PG_N3_INDEX] =
                    (uint16_t)VPD_CP00_PG_N3_GOOD;
            }

            TS_TRACE( "testHWASisChipFunctional: XBUS is not functional");
            for (l_mask = 0x8000;
                 l_mask > 0;
                 l_mask >>= 1)
            {
                // NOTE: Single bits of XBUS matched pairs will be turned
                //       on or off individually while going through loop,
                //       thus creating and testing mismatched pairs.
                if (pgData[VPD_CP00_PG_XBUS_INDEX] & l_mask)
                {
                    // Turn off a bit that should be on
                    pgData[VPD_CP00_PG_XBUS_INDEX] &= ~l_mask;
                }
                else
                {
                    // Turn on a bit that should be off
                    pgData[VPD_CP00_PG_XBUS_INDEX] |= l_mask;
                }

                if (isChipFunctional(pTarget, pgData))
                {
                    TS_FAIL("testHWASisChipFunctional>"
                            "functional = 0x%x, should be false, "
                            "XBUS = 0x%04x, mask = 0x%04x.",
                            isChipFunctional(pTarget, pgData),
                            pgData[VPD_CP00_PG_XBUS_INDEX],
                            l_mask);
                }

                // Restore the "all good" data
                pgData[VPD_CP00_PG_XBUS_INDEX] = l_xbus;
            }
        }

        TS_TRACE( "testHWASisChipFunctional exit" );
    }

    /**
     * @brief   test isDescFunctional
     */
    void testHWASisDescFunctional()
    {
        using namespace HWAS;
        using namespace TARGETING;

        // Get list of present targets with type PROC
        TargetHandleList pCheckPres;
        getAllChips( pCheckPres, TYPE_PROC, true );

        for (TargetHandleList::const_iterator pTarget_it = pCheckPres.begin();
             pTarget_it != pCheckPres.end();
             ++pTarget_it
            )
        {
            TargetHandle_t pTarget = *pTarget_it;
            ATTR_MODEL_type l_model = pTarget->getAttr<ATTR_MODEL>();
            uint16_t l_xbus = (MODEL_NIMBUS == l_model)
                            ? (uint16_t)(VPD_CP00_PG_XBUS_GOOD |
                                         VPD_CP00_PG_XBUS_IOX_PAIR[0])
                            : (uint16_t)VPD_CP00_PG_XBUS_GOOD;
            uint16_t l_obus12 = (MODEL_NIMBUS == l_model)
                              ? (uint16_t)VPD_CP00_PG_RESERVED_GOOD
                              : (uint16_t)VPD_CP00_PG_OBUS_GOOD;
            uint16_t pgData[VPD_CP00_PG_DATA_ENTRIES];
            memcpy(pgData,
                   pgDataAllGood,
                   VPD_CP00_PG_DATA_LENGTH);
            pgData[VPD_CP00_PG_XBUS_INDEX] = l_xbus;
            pgData[VPD_CP00_PG_OB0_INDEX + 1] =  l_obus12;
            pgData[VPD_CP00_PG_OB0_INDEX + 2] =  l_obus12;
            uint16_t l_mask = 0x8000;
            uint32_t l_index = VPD_CP00_PG_PERVASIVE_INDEX;

            TargetHandleList pDescList;
            targetService().getAssociated( pDescList, pTarget,
                TargetService::CHILD, TargetService::ALL);
            for (TargetHandleList::const_iterator pDesc_it = pDescList.begin();
                    pDesc_it != pDescList.end();
                    ++pDesc_it)
            {
                TargetHandle_t pDesc = *pDesc_it;
                ATTR_TYPE_type l_type = pDesc->getAttr<ATTR_TYPE>();
                ATTR_CHIP_UNIT_type l_chipUnit =
                    pDesc->getAttr<ATTR_CHIP_UNIT>();
                char l_type_str[9];
                char l_pgData[] = "";

                TS_TRACE( "testHWASisDescFunctional: descendant functional");
                if (!isDescFunctional(pDesc, pgData))
                {
                    switch(l_type)
                    {
                        case TYPE_CORE:
                            sprintf(l_type_str, "CORE");
                            sprintf(l_pgData, ", pgData = 0x%04x",
                                pgData[VPD_CP00_PG_EC00_INDEX + l_chipUnit]);
                            break;

                        case TYPE_MCS:
                            sprintf(l_type_str, "MCS");
                            sprintf(l_pgData, ", pgData = 0x%04x",
                                pgData[VPD_CP00_PG_MCxx_INDEX[l_chipUnit]]);
                            break;

                        case TYPE_XBUS:
                            if(MODEL_NIMBUS == l_model)
                            {
                                // XBUS is not fully functional on Nimbus
                                continue;
                            }

                            sprintf(l_type_str, "XBUS");
                            sprintf(l_pgData, ", pgData = 0x%04x",
                                pgData[VPD_CP00_PG_XBUS_INDEX]);
                            break;

                        case TYPE_NX:
                            sprintf(l_type_str, "NX");
                            sprintf(l_pgData, ", pgData = 0x%04x",
                                pgData[VPD_CP00_PG_N0_INDEX + l_chipUnit]);
                            break;

                        case TYPE_FSI:
                            sprintf(l_type_str, "FSI");
                            sprintf(l_pgData, ", pgData = 0x%04x",
                                pgData[VPD_CP00_PG_FSI_INDEX]);
                            break;

                        case TYPE_EQ:
                            sprintf(l_type_str, "EQ");
                            sprintf(l_pgData, ", pgData = 0x%04x",
                                pgData[VPD_CP00_PG_EP0_INDEX + l_chipUnit]);
                            break;

                        case TYPE_OBUS:
                            if((MODEL_NIMBUS == l_model) &&
                               ((1 == l_chipUnit) || (2 == l_chipUnit)))
                            {
                                // OBUS1 & OBUS2 are not functional on Nimbus
                                continue;
                            }

                            sprintf(l_type_str, "OBUS");
                            sprintf(l_pgData, ", pgData = 0x%04x",
                                pgData[VPD_CP00_PG_OB0_INDEX + l_chipUnit]);
                            break;

                        case TYPE_PERV:
                            sprintf(l_type_str, "PERV");
                            sprintf(l_pgData, ", pgData = 0x%04x",
                                pgData[VPD_CP00_PG_PERVASIVE_INDEX]);
                            break;

                        case TYPE_PEC:
                            sprintf(l_type_str, "PEC");
                            sprintf(l_pgData, ", pgData = 0x%04x",
                                pgData[VPD_CP00_PG_PCI0_INDEX + l_chipUnit]);
                            break;

                        default:
                            sprintf(l_type_str, "%08x", l_type);
                            break;
                    }

                    TS_FAIL("testHWASisDescFunctional>"
                            "functional = 0x%x, should be true, "
                            "type = %s, chip unit = %d%s.",
                            isDescFunctional(pDesc, pgData),
                            l_type_str,
                            l_chipUnit,
                            l_pgData);
                }
                else
                if(MODEL_NIMBUS == l_model)
                {
                    // Nimbus has special cases for XBUS, OBUS1, and OBUS2.
                    // These should show up as not functional, so fail if they
                    // come back as functional.
                    switch(l_type)
                    {
                        case TYPE_XBUS:
                            if((1 == l_chipUnit) || (2 == l_chipUnit))
                            {
                                // XBUS1 & XBUS2 should be functional on Nimbus
                                continue;
                            }

                            sprintf(l_type_str, "XBUS");
                            sprintf(l_pgData, ", pgData = 0x%04x",
                                pgData[VPD_CP00_PG_XBUS_INDEX]);
                            break;

                        case TYPE_OBUS:
                            if((0 == l_chipUnit) || (3 == l_chipUnit))
                            {
                                // OBUS0 & OBUS3 should be functional on Nimbus
                                continue;
                            }

                            sprintf(l_type_str, "OBUS");
                            sprintf(l_pgData, ", pgData = 0x%04x",
                                pgData[VPD_CP00_PG_OB0_INDEX + l_chipUnit]);
                            break;

                        default:
                            // Most types should be functional on Nimbus
                            continue;
                            break;
                    }

                    TS_FAIL("testHWASisDescFunctional>"
                            "functional = 0x%x, should be false, "
                            "type = %s, chip unit = %d%s.",
                            isDescFunctional(pDesc, pgData),
                            l_type_str,
                            l_chipUnit,
                            l_pgData);
                }

                switch(l_type)
                {
                    case TYPE_XBUS:
                        TS_TRACE( "testHWASisDescFunctional: "
                                  "XBUS%d is not functional", l_chipUnit);
                        pgData[VPD_CP00_PG_XBUS_INDEX] |=
                            (uint16_t)VPD_CP00_PG_XBUS_IOX_PAIR[l_chipUnit];

                        if (isDescFunctional(pDesc, pgData))
                        {
                            TS_FAIL("testHWASisDescFunctional>"
                                    "functional = 0x%x, should be false, "
                                    "XBUS%d = 0x%04x.",
                                    isDescFunctional(pDesc, pgData),
                                    l_chipUnit,
                                    pgData[VPD_CP00_PG_XBUS_INDEX]);
                        }

                        pgData[VPD_CP00_PG_XBUS_INDEX] = l_xbus;
                        break;

                    case TYPE_OBUS:
                        TS_TRACE( "testHWASisDescFunctional: "
                                  "OBUS%d is not functional", l_chipUnit);
                        pgData[VPD_CP00_PG_N1_INDEX] |=
                            (uint16_t)VPD_CP00_PG_N1_PBIOO0;

                        if (isDescFunctional(pDesc, pgData))
                        {
                            TS_FAIL("testHWASisDescFunctional>"
                                    "functional = 0x%x, should be false, "
                                    "N1 for OBUS%d = 0x%04x.",
                                    isDescFunctional(pDesc, pgData),
                                    l_chipUnit,
                                    pgData[VPD_CP00_PG_N1_INDEX]);
                        }

                        if ((1 == l_chipUnit) || (2 == l_chipUnit))
                        {
                            pgData[VPD_CP00_PG_N1_INDEX] =
                                (uint16_t)VPD_CP00_PG_N1_GOOD |
                                (uint16_t)VPD_CP00_PG_N1_PBIOO1;

                            if (isDescFunctional(pDesc, pgData))
                            {
                                TS_FAIL("testHWASisDescFunctional>"
                                        "functional = 0x%x, should be false, "
                                        "N1 for OBUS%d = 0x%04x.",
                                        isDescFunctional(pDesc, pgData),
                                        l_chipUnit,
                                        pgData[VPD_CP00_PG_N1_INDEX]);
                            }
                        }

                        pgData[VPD_CP00_PG_N1_INDEX] =
                            (uint16_t)VPD_CP00_PG_N1_GOOD;

                        for (l_mask = 0x8000;
                             l_mask > 0;
                             l_mask >>= 1)
                        {
                            if (pgData[VPD_CP00_PG_OB0_INDEX + l_chipUnit] &
                                l_mask)
                            {
                                // Turn off a bit that should be on
                                pgData[VPD_CP00_PG_OB0_INDEX + l_chipUnit] &=
                                    ~l_mask;
                            }
                            else
                            {
                                // Turn on a bit that should be off
                                pgData[VPD_CP00_PG_OB0_INDEX + l_chipUnit] |=
                                    l_mask;
                            }

                            if (isDescFunctional(pDesc, pgData))
                            {
                                TS_FAIL("testHWASisDescFunctional>"
                                        "functional = 0x%x, should be false, "
                                        "OBUS%d = 0x%04x, mask = 0x%04x.",
                                        isDescFunctional(pDesc, pgData),
                                        l_chipUnit,
                                        pgData[VPD_CP00_PG_OB0_INDEX
                                               + l_chipUnit],
                                        l_mask);
                            }

                            // Restore the "all good" data
                            pgData[VPD_CP00_PG_OB0_INDEX + l_chipUnit]
                                = ((1 == l_chipUnit) || (2 == l_chipUnit))
                                ? l_obus12
                                : (uint16_t)VPD_CP00_PG_OBUS_GOOD;
                        }
                        break;

                    case TYPE_PEC:
                        TS_TRACE( "testHWASisDescFunctional: "
                                  "PCI%d is not functional", l_chipUnit);
                        for (l_mask = 0x8000;
                             l_mask > 0;
                             l_mask >>= 1)
                        {
                            if (pgData[VPD_CP00_PG_PCI0_INDEX + l_chipUnit] &
                                l_mask)
                            {
                                // Turn off a bit that should be on
                                pgData[VPD_CP00_PG_PCI0_INDEX + l_chipUnit] &=
                                    ~l_mask;
                            }
                            else
                            {
                                // Turn on a bit that should be off
                                pgData[VPD_CP00_PG_PCI0_INDEX + l_chipUnit] |=
                                    l_mask;
                            }

                            if (isDescFunctional(pDesc, pgData))
                            {
                                TS_FAIL("testHWASisDescFunctional>"
                                        "functional = 0x%x, should be false, "
                                        "PCI%d = 0x%04x, mask = 0x%04x.",
                                        isDescFunctional(pDesc, pgData),
                                        l_chipUnit,
                                        pgData[VPD_CP00_PG_PCI0_INDEX
                                               + l_chipUnit],
                                        l_mask);
                            }

                            // Restore the "all good" data
                            pgData[VPD_CP00_PG_PCI0_INDEX + l_chipUnit] =
                                (uint16_t)VPD_CP00_PG_PCIx_GOOD[l_chipUnit];
                        }
                        break;

                    case TYPE_EQ:
                        TS_TRACE( "testHWASisDescFunctional: "
                                  "EQ%d is not functional", l_chipUnit);
                        for (l_mask = 0x8000;
                             l_mask > 0;
                             l_mask >>= 1)
                        {
                            // NOTE: Single bits of L2 / L3 matched pairs will
                            //       be turned on or off individually while
                            //       going through loop, thus creating and
                            //       testing mismatched pairs.
                            if (pgData[VPD_CP00_PG_EP0_INDEX + l_chipUnit] &
                                l_mask)
                            {
                                // Turn off a bit that should be on
                                pgData[VPD_CP00_PG_EP0_INDEX + l_chipUnit] &=
                                    ~l_mask;
                            }
                            else
                            {
                                // Turn on a bit that should be off
                                pgData[VPD_CP00_PG_EP0_INDEX + l_chipUnit] |=
                                    l_mask;
                            }

                            if (isDescFunctional(pDesc, pgData))
                            {
                                TS_FAIL("testHWASisDescFunctional>"
                                        "functional = 0x%x, should be false, "
                                        "EQ/EP%d = 0x%04x, mask = 0x%04x.",
                                        isDescFunctional(pDesc, pgData),
                                        l_chipUnit,
                                        pgData[VPD_CP00_PG_EP0_INDEX
                                               + l_chipUnit],
                                        l_mask);
                            }

                            // Restore the "all good" data
                            pgData[VPD_CP00_PG_EP0_INDEX + l_chipUnit] =
                                (uint16_t)VPD_CP00_PG_EPx_GOOD;
                        }
                        break;

                    case TYPE_EX:
                        TS_TRACE( "testHWASisDescFunctional: "
                                  "EX%d is not functional", l_chipUnit);
                        pgData[VPD_CP00_PG_EP0_INDEX + (l_chipUnit / 2)] |=
                            (uint16_t)VPD_CP00_PG_EPx_L3L2REFR[l_chipUnit % 2];

                        if (isDescFunctional(pDesc, pgData))
                        {
                            TS_FAIL("testHWASisDescFunctional>"
                                    "functional = 0x%x, should be false, "
                                    "EX%d / EP%d = 0x%04x.",
                                    isDescFunctional(pDesc, pgData),
                                    l_chipUnit, (l_chipUnit / 2),
                                    pgData[VPD_CP00_PG_EP0_INDEX
                                           + (l_chipUnit / 2)]);
                        }

                        pgData[VPD_CP00_PG_EP0_INDEX + (l_chipUnit / 2)] =
                            (uint16_t)VPD_CP00_PG_EPx_GOOD;
                        break;

                    case TYPE_CORE:
                        TS_TRACE( "testHWASisDescFunctional: "
                                  "CORE%d is not functional", l_chipUnit);
                        for (l_mask = 0x8000;
                             l_mask > 0;
                             l_mask >>= 1)
                        {
                            if (pgData[VPD_CP00_PG_EC00_INDEX + l_chipUnit] &
                                l_mask)
                            {
                                // Turn off a bit that should be on
                                pgData[VPD_CP00_PG_EC00_INDEX + l_chipUnit] &=
                                    ~l_mask;
                            }
                            else
                            {
                                // Turn on a bit that should be off
                                pgData[VPD_CP00_PG_EC00_INDEX + l_chipUnit] |=
                                    l_mask;
                            }

                            if (isDescFunctional(pDesc, pgData))
                            {
                                TS_FAIL("testHWASisDescFunctional>"
                                        "functional = 0x%x, should be false, "
                                        "CORE%d = 0x%04x, mask = 0x%04x.",
                                        isDescFunctional(pDesc, pgData),
                                        l_chipUnit,
                                        pgData[VPD_CP00_PG_EC00_INDEX
                                               + l_chipUnit],
                                        l_mask);
                            }

                            // Restore the "all good" data
                            pgData[VPD_CP00_PG_EC00_INDEX + l_chipUnit] =
                                VPD_CP00_PG_ECxx_GOOD;
                        }
                        break;

                    case TYPE_MCBIST:
                        TS_TRACE( "testHWASisDescFunctional: "
                                  "MCBIST%d is not functional", l_chipUnit);
                        if (l_chipUnit)
                        {
                            pgData[VPD_CP00_PG_N1_INDEX] |=
                                (uint16_t)VPD_CP00_PG_N1_MCS23;
                        }
                        else
                        {
                            pgData[VPD_CP00_PG_N3_INDEX] |=
                                (uint16_t)VPD_CP00_PG_N3_MCS01;
                        }

                        if (isDescFunctional(pDesc, pgData))
                        {
                            TS_FAIL("testHWASisDescFunctional>"
                                    "functional = 0x%x, should be false, "
                                    "N1/N3 for MCBIST%d = 0x%04x.",
                                    isDescFunctional(pDesc, pgData),
                                    l_chipUnit,
                                    l_chipUnit ? pgData[VPD_CP00_PG_N1_INDEX]
                                               : pgData[VPD_CP00_PG_N3_INDEX]);
                        }

                        if (l_chipUnit)
                        {
                            pgData[VPD_CP00_PG_N1_INDEX] =
                                (uint16_t)VPD_CP00_PG_N1_GOOD;
                        }
                        else
                        {
                            pgData[VPD_CP00_PG_N3_INDEX] =
                                (uint16_t)VPD_CP00_PG_N3_GOOD;
                        }

                        for (l_mask = 0x8000;
                             l_mask > 0;
                             l_mask >>= 1)
                        {
                            if ((uint16_t)VPD_CP00_PG_MCxx_PG_MASK & l_mask)
                            {
                                 // Ignore partial good region
                                 continue;
                            }
                            else
                            if (pgData[VPD_CP00_PG_MCxx_INDEX[l_chipUnit * 2]]
                                & l_mask)
                            {
                                // Turn off a bit that should be on
                                pgData[VPD_CP00_PG_MCxx_INDEX[l_chipUnit * 2]]
                                    &= ~l_mask;
                            }
                            else
                            {
                                // Turn on a bit that should be off
                                pgData[VPD_CP00_PG_MCxx_INDEX[l_chipUnit * 2]]
                                    |= l_mask;
                            }

                            if (isDescFunctional(pDesc, pgData))
                            {
                                TS_FAIL("testHWASisDescFunctional>"
                                        "functional = 0x%x, should be false, "
                                        "MC%s for MCBIST%d = 0x%04x, "
                                        "mask = 0x%04x.",
                                        isDescFunctional(pDesc, pgData),
                                        l_chipUnit ? "01" : "23",
                                        l_chipUnit,
                                        pgData[VPD_CP00_PG_MCxx_INDEX
                                                   [l_chipUnit * 2]],
                                        l_mask);
                            }

                            // Restore the "all good" data
                            pgData[VPD_CP00_PG_MCxx_INDEX[l_chipUnit * 2]] =
                                (uint16_t)VPD_CP00_PG_MCxx_GOOD;
                        }
                        break;

                    case TYPE_MCS:
                        TS_TRACE( "testHWASisDescFunctional: "
                                  "MCS%d is not functional", l_chipUnit);
                        if (l_chipUnit >= 2)
                        {
                            pgData[VPD_CP00_PG_N1_INDEX] |=
                                (uint16_t)VPD_CP00_PG_N1_MCS23;
                        }
                        else
                        {
                            pgData[VPD_CP00_PG_N3_INDEX] |=
                                (uint16_t)VPD_CP00_PG_N3_MCS01;
                        }

                        if (isDescFunctional(pDesc, pgData))
                        {
                            TS_FAIL("testHWASisDescFunctional>"
                                    "functional = 0x%x, should be false, "
                                    "N1/N3 for MCS%d = 0x%04x.",
                                    isDescFunctional(pDesc, pgData),
                                    l_chipUnit,
                                    (l_chipUnit >= 2)
                                        ? pgData[VPD_CP00_PG_N1_INDEX]
                                        : pgData[VPD_CP00_PG_N3_INDEX]);
                        }

                        if (l_chipUnit >= 2)
                        {
                            pgData[VPD_CP00_PG_N1_INDEX] =
                                (uint16_t)VPD_CP00_PG_N1_GOOD;
                        }
                        else
                        {
                            pgData[VPD_CP00_PG_N3_INDEX] =
                                (uint16_t)VPD_CP00_PG_N3_GOOD;
                        }

                        for (l_mask = 0x8000;
                             l_mask > 0;
                             l_mask >>= 1)
                        {
                            if ((uint16_t)(VPD_CP00_PG_MCxx_PG_MASK &
                                ~VPD_CP00_PG_MCxx_IOMyy[l_chipUnit]) & l_mask)
                            {
                                 // Ignore partial good region
                                 continue;
                            }
                            else
                            if (pgData[VPD_CP00_PG_MCxx_INDEX[l_chipUnit]] &
                                l_mask)
                            {
                                // Turn off a bit that should be on
                                pgData[VPD_CP00_PG_MCxx_INDEX[l_chipUnit]] &=
                                    ~l_mask;
                            }
                            else
                            {
                                // Turn on a bit that should be off
                                pgData[VPD_CP00_PG_MCxx_INDEX[l_chipUnit]] |=
                                    l_mask;
                            }

                            if (isDescFunctional(pDesc, pgData))
                            {
                                TS_FAIL("testHWASisDescFunctional>"
                                        "functional = 0x%x, should be false, "
                                        "MC%s for MCS%d = 0x%04x, "
                                        "mask = 0x%04x.",
                                        isDescFunctional(pDesc, pgData),
                                        (l_chipUnit < 2) ? "01" : "23",
                                        l_chipUnit,
                                        pgData[VPD_CP00_PG_MCxx_INDEX
                                                   [l_chipUnit]],
                                        l_mask);
                            }

                            // Restore the "all good" data
                            pgData[VPD_CP00_PG_MCxx_INDEX[l_chipUnit]] =
                                (uint16_t)VPD_CP00_PG_MCxx_GOOD;
                        }
                        break;

                    case TYPE_MCA:
                        TS_TRACE( "testHWASisDescFunctional: "
                                  "MCA%d is not functional", l_chipUnit);
                        pgData[VPD_CP00_PG_MCxx_INDEX[l_chipUnit / 2]] |=
                            (uint16_t)VPD_CP00_PG_MCxx_IOMyy[l_chipUnit / 2];

                        if (isDescFunctional(pDesc, pgData))
                        {
                            TS_FAIL("testHWASisDescFunctional>"
                                    "functional = 0x%x, should be false, "
                                    "MC%s for MCA%d = 0x%04x.",
                                    isDescFunctional(pDesc, pgData),
                                    (l_chipUnit < 4) ? "01" : "23",
                                    l_chipUnit,
                                    pgData[VPD_CP00_PG_MCxx_INDEX
                                               [l_chipUnit / 2]]);
                        }

                        pgData[VPD_CP00_PG_MCxx_INDEX[l_chipUnit / 2]] =
                            (uint16_t)VPD_CP00_PG_MCxx_GOOD;
                        break;

                    case TYPE_NV:
                        TS_TRACE( "testHWASisDescFunctional: "
                                  "NV is not functional");
                        pgData[VPD_CP00_PG_N3_INDEX] |=
                            (uint16_t)VPD_CP00_PG_N3_NPU;

                        if (isDescFunctional(pDesc, pgData))
                        {
                            TS_FAIL("testHWASisDescFunctional>"
                                    "functional = 0x%x, should be false, "
                                    "NV = 0x%04x.",
                                    isDescFunctional(pDesc, pgData),
                                    pgData[VPD_CP00_PG_N3_INDEX]);
                        }

                        pgData[VPD_CP00_PG_N3_INDEX] =
                            (uint16_t)VPD_CP00_PG_N3_GOOD;
                        break;

                    case TYPE_PERV:
                        TS_TRACE( "testHWASisDescFunctional: "
                                  "PERV is not functional");
                        for (l_index = VPD_CP00_PG_PERVASIVE_INDEX;
                             l_index < VPD_CP00_PG_DATA_ENTRIES;
                             l_index++)
                        {
                            if (pgData[l_index] &
                                (uint16_t)VPD_CP00_PG_xxx_PERV)
                            {
                                // Ignore chiplet lines where PERV is "1"
                                continue;
                            }
                            else
                            {
                                // Turn on PERV bit that should be off / good
                                pgData[l_index] |=
                                    (uint16_t)VPD_CP00_PG_xxx_PERV;
                            }

                            if (isDescFunctional(pDesc, pgData))
                            {
                                TS_FAIL("testHWASisDescFunctional>"
                                        "functional = 0x%x, should be false, "
                                        "PERV(%d) = 0x%04x.",
                                        isDescFunctional(pDesc, pgData),
                                        l_index,
                                        pgData[l_index]);
                            }

                            // Restore the "all good" data
                            pgData[l_index] &= ~VPD_CP00_PG_xxx_PERV;
                        }
                        break;

                    default:
                        break;
                }
            } // for pDesc_it
        } // for pTarget_it

        TS_TRACE( "testHWASisDescFunctional exit" );
    }

    /**
     * @brief   test restrictECunits
     */
    void testHWASrestrictECunits()
    {
        using namespace HWAS;
        using namespace TARGETING;

        errlHndl_t errl = NULL;

        // list of procs and data that we'll need to look at the PR keyword
        procRestrict_t l_procEntry;
        std::vector <procRestrict_t> l_procPRList;

        // Get list of present targets with type PROC
        TargetHandleList pCheckPres;
        getAllChips( pCheckPres, TYPE_PROC, true );

        for (TargetHandleList::const_iterator pTarget_it = pCheckPres.begin();
             pTarget_it != pCheckPres.end();
             ++pTarget_it
            )
        {
            TargetHandle_t pTarget = *pTarget_it;

            // read the PR keywords that we need, so that if
            //  we have errors, we can handle them as approprite.
            uint8_t prData[VPD_VINI_PR_DATA_LENGTH/sizeof(uint8_t)];
            bzero(prData, sizeof(prData));
            errl = platReadPR(pTarget, prData);
            if (errl != NULL)
            {   // read of PR keyword failed
                TS_FAIL("testHWASrestrictECunits>"
                        "pTarget %.8X - read PR failed - bad",
                        pTarget->getAttr<ATTR_HUID>());
            }
            else
            {
                // save info so that we can
                //  process the PR keyword after this loop
                l_procEntry.target = pTarget;
                l_procEntry.group = pTarget->getAttr<ATTR_FRU_ID>();
                l_procEntry.procs = (prData[7] & VPD_VINI_PR_B7_MASK) + 1;
                l_procEntry.maxECs = l_procEntry.procs *
                    (prData[2] & VPD_VINI_PR_B2_MASK) >> VPD_VINI_PR_B2_SHIFT;
                l_procPRList.push_back(l_procEntry);

                if (l_procEntry.maxECs == 0)
                {
                    // this is PROBABLY bad PR, so YELL...
                    TS_FAIL("testHWASrestrictECunits>"
                            "pTarget %.8X - PR VPD says 0 CORES",
                            pTarget->getAttr<ATTR_HUID>());
                }
            }
        } // for pTarget_it

        // Call restrictECunits
        errl = restrictECunits(l_procPRList, false, 0);
        if (errl != NULL)
        {   // restrict EC units failed
            TS_FAIL("testHWASrestrictECunits> - restrict EC units failed");
        }

        TS_TRACE( "testHWASrestrictECunits exit" );
    }

};

#endif //
