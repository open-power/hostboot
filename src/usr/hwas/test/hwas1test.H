/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwas/test/hwas1test.H $                               */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2017                        */
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
                      (uint16_t)HWAS::VPD_CP00_PG_XBUS_GOOD_CUMULUS,
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

        TS_INFO( "testHWASReadWrite entry" );

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

        TS_INFO( "testHWASReadWrite exit" );
    }

    /**
     * @brief   test platReadIDEC
     */
    void testHWASplatReadIDEC()
    {
        using namespace TARGETING;

        TS_INFO( "testHWASplatReadIDEC entry" );

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

        TS_INFO( "testHWASplatReadIDEC exit" );
    }

    /**
     * @brief   test platReadPartialGood
     */
    void testHWASplatReadPartialGood()
    {
        using namespace TARGETING;

        TS_INFO( "testHWASplatReadPartialGood entry" );

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

        TS_INFO( "testHWASplatReadPartialGood exit" );
    }

    /**
     * @brief   test isChipFunctional
     */
    void testHWASisChipFunctional()
    {
        using namespace HWAS;
        using namespace TARGETING;

        TS_INFO( "testHWASisChipFunctional entry" );

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
                            ? (uint16_t)(VPD_CP00_PG_XBUS_GOOD_NIMBUS |
                                         VPD_CP00_PG_XBUS_IOX[0])
                            : (uint16_t)VPD_CP00_PG_XBUS_GOOD_CUMULUS;
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

            TS_INFO( "testHWASisChipFunctional: chip is functional");
            if (!isChipFunctional(pTarget, pgData))
            {
                TS_FAIL("testHWASisChipFunctional>"
                        "functional = 0x%x, should be true.",
                        isChipFunctional(pTarget, pgData));
            }

            TS_INFO( "testHWASisChipFunctional: partial good all bad");
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

            TS_INFO( "testHWASisChipFunctional: FSI is not functional");
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

            TS_INFO( "testHWASisChipFunctional: PRV is not functional");
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

            TS_INFO( "testHWASisChipFunctional: N0 is not functional");
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

            TS_INFO( "testHWASisChipFunctional: N1 is not functional");
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

            TS_INFO( "testHWASisChipFunctional: N2 is not functional");
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

            TS_INFO( "testHWASisChipFunctional: N3 is not functional");
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

            TS_INFO( "testHWASisChipFunctional: XBUS is not functional");
            for (l_mask = 0x8000;
                 l_mask > 0;
                 l_mask >>= 1)
            {
                // NOTE: Xbus doesn't have matched pairs anymore
                //       individual Xbus units (0x0400, 0x0200, and 0x0100)
                //       can be bad and chip is still functional.  Any
                //       other bit being incorrect should cause full chip
                //       deconfig
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

                if (((uint16_t)(VPD_CP00_PG_XBUS_PG_MASK)) & l_mask)
                {
                    //Chip should be functional
                    if (!isChipFunctional(pTarget, pgData))
                    {
                        TS_FAIL("testHWASisChipFunctional>"
                            "functional = 0x%x, should be true, "
                            "XBUS = 0x%04x, mask = 0x%04x.",
                            isChipFunctional(pTarget, pgData),
                            pgData[VPD_CP00_PG_XBUS_INDEX],
                            l_mask);
                    }
                }
                else
                {
                    //Chip should be non functional
                    if (isChipFunctional(pTarget, pgData))
                    {
                        TS_FAIL("testHWASisChipFunctional>"
                            "functional = 0x%x, should be false, "
                            "XBUS = 0x%04x, mask = 0x%04x.",
                            isChipFunctional(pTarget, pgData),
                            pgData[VPD_CP00_PG_XBUS_INDEX],
                            l_mask);
                    }
                }

                // Restore the "all good" data
                pgData[VPD_CP00_PG_XBUS_INDEX] = l_xbus;
            }
        }

        TS_INFO( "testHWASisChipFunctional exit" );
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

        TS_INFO( "testHWASisDescFunctional() entry");

        for (TargetHandleList::const_iterator pTarget_it = pCheckPres.begin();
             pTarget_it != pCheckPres.end();
             ++pTarget_it
            )
        {
            TargetHandle_t pTarget = *pTarget_it;
            ATTR_MODEL_type l_model = pTarget->getAttr<ATTR_MODEL>();
            uint16_t l_xbus = (MODEL_NIMBUS == l_model)
                            ? (uint16_t)(VPD_CP00_PG_XBUS_GOOD_NIMBUS |
                                         VPD_CP00_PG_XBUS_IOX[0])
                            : (uint16_t)VPD_CP00_PG_XBUS_GOOD_CUMULUS;
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
                uint8_t core_idx;

                TS_INFO("testHWASisDescFunctional: descendant functional - "
                        "attr type 0x%04X, chip unit %d", l_type, l_chipUnit);
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
                    bool skipFailCheck = false;
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
                            skipFailCheck = true;
                            break;
                    }

                    if (!skipFailCheck)
                    {
                        TS_FAIL("testHWASisDescFunctional>"
                            "functional = 0x%x, should be false, "
                            "type = %s, chip unit = %d%s.",
                            isDescFunctional(pDesc, pgData),
                            l_type_str,
                            l_chipUnit,
                            l_pgData);
                    }
                }

                switch(l_type)
                {
                    case TYPE_XBUS:
                        TS_INFO( "testHWASisDescFunctional: "
                                  "XBUS%d is not functional", l_chipUnit);
                        pgData[VPD_CP00_PG_XBUS_INDEX] |=
                            (uint16_t)VPD_CP00_PG_XBUS_IOX[l_chipUnit];

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
                        TS_INFO( "testHWASisDescFunctional: "
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
                        TS_INFO( "testHWASisDescFunctional: "
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
                    case TYPE_PHB:
                      {
                        TS_INFO( "testHWASisDescFunctional: "
                                  "PCI%d is not functional for PHB target",
                                  l_chipUnit);
                        //First get Parent PEC target as there are no PG bits
                        //  for PHB
                        TargetHandleList pParentPECList;
                        getParentAffinityTargetsByState(pParentPECList, pDesc,
                                     CLASS_UNIT, TYPE_PEC, UTIL_FILTER_PRESENT);
                        HWAS_ASSERT((pParentPECList.size() == 1),
                            "testHWASisDescFunctional(): pParentPECList != 1");
                        Target *l_parentPEC = pParentPECList[0];

                        //Check if parent PEC's PG Data marks it good
                        ATTR_CHIP_UNIT_type l_indexPCI =
                                l_parentPEC->getAttr<ATTR_CHIP_UNIT>();

                        for (l_mask = 0x8000;
                             l_mask > 0;
                             l_mask >>= 1)
                        {
                            if (pgData[VPD_CP00_PG_PCI0_INDEX + l_indexPCI] &
                                l_mask)
                            {
                                // Turn off a bit that should be on
                                pgData[VPD_CP00_PG_PCI0_INDEX + l_indexPCI] &=
                                    ~l_mask;
                            }
                            else
                            {
                                // Turn on a bit that should be off
                                pgData[VPD_CP00_PG_PCI0_INDEX + l_indexPCI] |=
                                    l_mask;
                            }

                            if (isDescFunctional(pDesc, pgData))
                            {
                                TS_FAIL("testHWASisDescFunctional>"
                                        "functional = 0x%x, should be false, "
                                        "PCI%d = 0x%04x, mask = 0x%04x",
                                        isDescFunctional(pDesc, pgData),
                                        l_indexPCI,
                                        pgData[VPD_CP00_PG_PCI0_INDEX
                                               + l_indexPCI],
                                        l_mask);
                            }
                           // Restore the "all good" data
                           pgData[VPD_CP00_PG_PCI0_INDEX + l_indexPCI] =
                                (uint16_t)VPD_CP00_PG_PCIx_GOOD[l_indexPCI];
                        }
                        break;
                      }
                    case TYPE_EQ:
                        TS_INFO( "testHWASisDescFunctional: "
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

                        //////////////////////////////////////
                        // make children bad to check rollup
                        //////////////////////////////////////

                        // mark bad EX children
                        TS_INFO("testHWASisDescFunctional>"
                            "Mark EQ%d's EX chiplets bad", l_chipUnit);

                        // Choosing a single failure for each EX out of
                        // multiple possibilities

                        // Mark l3x, l2x, and/or refrx bad (x = 0 or 1)

                        // 1st EX bad: mark refr0 as bad
                        pgData[VPD_CP00_PG_EP0_INDEX + l_chipUnit] |=
                            0x0008;

                        // 2nd EX bad: mark L21 as bad too
                        pgData[VPD_CP00_PG_EP0_INDEX + l_chipUnit] |=
                            0x0040;

                        if (isDescFunctional(pDesc, pgData))
                        {
                            TS_FAIL("testHWASisDescFunctional>"
                                    "functional = 0x%x, should be false. "
                                    "EQ/EP%d = 0x%04x (expected 0x%04X), "
                                    "EX children were marked bad ",
                                    isDescFunctional(pDesc, pgData),
                                    l_chipUnit,
                                    pgData[VPD_CP00_PG_EP0_INDEX
                                           + l_chipUnit],
                                    VPD_CP00_PG_EPx_GOOD);
                        }

                        // Restore the "all good" data
                        pgData[VPD_CP00_PG_EP0_INDEX + l_chipUnit] =
                                (uint16_t)VPD_CP00_PG_EPx_GOOD;

                        // now try bad CORE rollup
                        core_idx = (uint8_t)l_chipUnit * 4;
                        TS_INFO("testHWASisDescFunctional>"
                            "Now try marking EQ%d cores EC%d - EC%d bad",
                            l_chipUnit, core_idx, core_idx+3);
                        for (int i = 0; i < 4; i++)
                        {
                            pgData[VPD_CP00_PG_EC00_INDEX + core_idx + i] |=
                                ~VPD_CP00_PG_ECxx_GOOD;
                        }
                        if (isDescFunctional(pDesc, pgData))
                        {
                            TS_FAIL("testHWASisDescFunctional>"
                                "EQ/EP%d functional = 0x%x, should be false. "
                                "All 4 EC children were marked bad",
                                l_chipUnit,
                                isDescFunctional(pDesc, pgData));
                        }
                        // Restore the "all good" core data
                        for (int i = 0; i < 4; i++)
                        {
                            pgData[VPD_CP00_PG_EC00_INDEX + core_idx + i] =
                                VPD_CP00_PG_ECxx_GOOD;
                        }

                        break;

                    case TYPE_EX:
                        TS_INFO( "testHWASisDescFunctional: "
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

                        // Now mark its 2 EC cores as bad and check for rollup
                        core_idx = (uint8_t)l_chipUnit * 2;
                        TS_INFO("testHWASisDescFunctional>"
                            "Now try marking EX%d cores EC%d and EC%d bad",
                            l_chipUnit, core_idx, core_idx+1);
                        for (int i = 0; i < 2; i++)
                        {
                            pgData[VPD_CP00_PG_EC00_INDEX + core_idx + i] |=
                                ~VPD_CP00_PG_ECxx_GOOD;
                        }
                        if (isDescFunctional(pDesc, pgData))
                        {
                            TS_FAIL("testHWASisDescFunctional>"
                                "EX%d functional = 0x%x, should be false. "
                                "All 2 EC children were marked bad",
                                l_chipUnit,
                                isDescFunctional(pDesc, pgData));
                        }
                        // Restore the "all good" core data
                        for (int i = 0; i < 2; i++)
                        {
                            pgData[VPD_CP00_PG_EC00_INDEX + core_idx + i] =
                                VPD_CP00_PG_ECxx_GOOD;
                        }

                        break;

                    case TYPE_CORE:
                        TS_INFO( "testHWASisDescFunctional: "
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
                        TS_INFO( "testHWASisDescFunctional: "
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

                        // TEST WITH BAD MAGIC PORT
                        pgData[VPD_CP00_PG_MCxx_INDEX[l_chipUnit * 2]] |=
                            VPD_CP00_PG_MCA_MAGIC_PORT_MASK;


                        if (isDescFunctional(pDesc, pgData))
                        {
                            TS_FAIL("testHWASisDescFunctional>"
                                    "functional = 0x%x, should be false, "
                                    "MC%s for MCBIST%d = 0x%04x, "
                                    "mask = 0x%04x - BAD MAGIC PORT.",
                                    isDescFunctional(pDesc, pgData),
                                    l_chipUnit ? "01" : "23",
                                    l_chipUnit,
                                    pgData[VPD_CP00_PG_MCxx_INDEX
                                               [l_chipUnit * 2]],
                                    VPD_CP00_PG_MCA_MAGIC_PORT_MASK);
                        }

                        pgData[VPD_CP00_PG_MCxx_INDEX[l_chipUnit * 2]] &=
                            ~VPD_CP00_PG_MCA_MAGIC_PORT_MASK;

                        break;

                    case TYPE_MCS:
                        TS_INFO( "testHWASisDescFunctional: "
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

                        // TEST WITH BAD MAGIC PORT (MCA0 or MCA4)
                        pgData[VPD_CP00_PG_MCxx_INDEX[l_chipUnit]] |=
                            VPD_CP00_PG_MCA_MAGIC_PORT_MASK;

                        if (isDescFunctional(pDesc, pgData))
                        {
                            TS_FAIL("testHWASisDescFunctional>"
                                    "functional = 0x%x, should be false, "
                                    "MC%s for MCS%d = 0x%04x, "
                                    "mask = 0x%04x - BAD MAGIC PORT.",
                                    isDescFunctional(pDesc, pgData),
                                    l_chipUnit ? "01" : "23",
                                    l_chipUnit,
                                    pgData[VPD_CP00_PG_MCxx_INDEX[l_chipUnit]],
                                    VPD_CP00_PG_MCA_MAGIC_PORT_MASK);
                        }

                        pgData[VPD_CP00_PG_MCxx_INDEX[l_chipUnit]] &=
                            ~VPD_CP00_PG_MCA_MAGIC_PORT_MASK;

                        break;

                    case TYPE_MCA:
                        TS_INFO( "testHWASisDescFunctional: "
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

                        // Try bad MCA Port setting for MCA2/3 & MCA6/7
                        if ( VPD_CP00_PG_MCxx_IOMyy[l_chipUnit / 2] !=
                             VPD_CP00_PG_MCA_MAGIC_PORT_MASK )
                        {
                            pgData[VPD_CP00_PG_MCxx_INDEX[l_chipUnit / 2]] |=
                                VPD_CP00_PG_MCA_MAGIC_PORT_MASK;

                            if (isDescFunctional(pDesc, pgData))
                            {
                                TS_FAIL("testHWASisDescFunctional>"
                                        "functional = 0x%x, should be false, "
                                        "MC%s for MCA%d = 0x%04x "
                                        "mask = 0x%04x - BAD MAGIC PORT.",
                                        isDescFunctional(pDesc, pgData),
                                        (l_chipUnit < 4) ? "01" : "23",
                                        l_chipUnit,
                                        pgData[VPD_CP00_PG_MCxx_INDEX
                                                   [l_chipUnit / 2]],
                                        VPD_CP00_PG_MCA_MAGIC_PORT_MASK);
                            }

                            pgData[VPD_CP00_PG_MCxx_INDEX[l_chipUnit / 2]] &=
                                ~VPD_CP00_PG_MCA_MAGIC_PORT_MASK;
                        }

                        break;

                    case TYPE_OBUS_BRICK:
                        TS_INFO( "testHWASisDescFunctional: "
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

                        TS_INFO( "testHWASisDescFunctional: "
                                  "PERV is not functional");

                        if (pgData[l_chipUnit] &
                            (uint16_t)VPD_CP00_PG_xxx_VITAL)
                        {
                            // Ignore chiplet lines where VITAL is "1"
                            continue;
                        }
                        else
                        {
                            // Turn on VITAL bit that should be off / good
                            pgData[l_chipUnit] |=
                                (uint16_t)VPD_CP00_PG_xxx_VITAL;
                        }

                        if (isDescFunctional(pDesc, pgData))
                        {
                            TS_FAIL("testHWASisDescFunctional>"
                                    "functional = 0x%x, should be false, "
                                    "PERV(%d) = 0x%04x.",
                                    isDescFunctional(pDesc, pgData),
                                    l_chipUnit,
                                    pgData[l_chipUnit]);
                        }

                        // Restore the "all good" data
                        pgData[l_chipUnit] &= ~VPD_CP00_PG_xxx_VITAL;

                        break;

                    default:
                        break;
                }
            } // for pDesc_it
        } // for pTarget_it

        TS_INFO( "testHWASisDescFunctional exit" );
    }

    /**
     * @brief   test restrictECunits
     */
    void testHWASrestrictECunits()
    {
        using namespace HWAS;
        using namespace TARGETING;

#if 0 //Cannot actually run this because it might change state
        errlHndl_t errl = NULL;

        // list of procs and data
        procRestrict_t l_procEntry;
        std::vector <procRestrict_t> l_procRestrictList;

        // Get list of present targets with type PROC
        TargetHandleList pCheckPres;
        getAllChips( pCheckPres, TYPE_PROC, true );

        for (TargetHandleList::const_iterator pTarget_it = pCheckPres.begin();
             pTarget_it != pCheckPres.end();
             ++pTarget_it
            )
        {
            TargetHandle_t pTarget = *pTarget_it;

            // create data for each proc
            l_procEntry.target = pTarget;
            l_procEntry.group = 0;
            l_procEntry.procs = 1;
            l_procEntry.maxECs = UINT32_MAX;

            l_procPRList.push_back(l_procEntry);
        } // for pTarget_it

        // Call restrictECunits
        errl = restrictECunits(l_procRestrictList, false, 0);
        if (errl != NULL)
        {   // restrict EC units failed
            TS_FAIL("testHWASrestrictECunits> - restrict EC units failed");
        }
#endif

        // Instead verify that we ended up with exactly the right number
        //  enabled cores that we expect for our NIMBUS standalone config
        TargetHandleList l_funcProcs;
        getAllChips( l_funcProcs, TYPE_PROC, true );
        for( const auto& l_proc : l_funcProcs )
        {
            TargetHandleList l_funcCores;
            getChildChiplets( l_funcCores, l_proc, TYPE_CORE, true );

            // Currently we have 4 ECs configured in the PG record
            const size_t l_numCores = 4;
            if( l_funcCores.size() != l_numCores )
            {
                TS_FAIL("testHWASrestrictECunits> Expected %d cores, but saw %d",
                        l_numCores, l_funcCores.size() );
            }
        }

        TS_INFO( "testHWASrestrictECunits exit" );

    }

    /**
     * @brief   test pervStates
     */
    void testHWASpervStates()
    {
        using namespace HWAS;
        using namespace TARGETING;

        TS_INFO( "testHWASpervStates entry" );

        // find top level target
        Target * pSys;
        targetService().getTopLevelTarget(pSys);

        PredicateCTM predChip(CLASS_CHIP);
        PredicateCTM predPerv(CLASS_UNIT, TYPE_PERV);
        PredicatePostfixExpr checkExpr;
        checkExpr.push(&predChip).Or().push(&predPerv).Or();

        TargetHandleList pPervList;
        // get list of all PERV targets
        targetService().getAssociated( pPervList, pSys,
                TargetService::CHILD,
                TargetService::ALL,
                &predPerv );
        // sort the list by ATTR_HUID to ensure that we
        //  start at the same place each time
        std::sort(pPervList.begin(), pPervList.end(),
                compareTargetHuid);
        do
        {
            if (pPervList.empty())
            {
                TS_FAIL("testHWASpervStates: empty pPervList");
                break;
            }
            // Iterate through all PERV chiplets
            for (TargetHandleList::const_iterator
                 l_pervIter = pPervList.begin();
                 l_pervIter != pPervList.end();
                 ++l_pervIter)
            {
                Target * l_target = *l_pervIter;

                // The chip unit number of the perv target
                // is the index into the PG data
                ATTR_CHIP_UNIT_type chip_unit =
                  l_target->getAttr<ATTR_CHIP_UNIT>();

                // get the HW State of the target
                HwasState hwasState = l_target->getAttr<ATTR_HWAS_STATE>();

                // get parent target and the HW state
                const Target * l_ptarget;
                l_ptarget = getParentChip(l_target);
                HwasState phwasState = l_ptarget->getAttr<ATTR_HWAS_STATE>();

                if (phwasState.present == true)
                {
                    if (hwasState.present == false)
                    {
                        TS_FAIL("testHWASpervStates: PERV[%d] HUID: %.8X - is NOT Present",
                             chip_unit,
                            l_target->getAttr<ATTR_HUID>());
                        break;
                    }
                    HWAS_DBG("PERV[%d]: HUID: %.8X - %spresent, %sfunctional",
                        chip_unit,
                        l_target->getAttr<ATTR_HUID>(),
                        hwasState.present ? "" : "NOT ",
                        hwasState.functional ? "" : "NOT ");
                }
                else
                {
                    if (hwasState.present == true)
                    {
                        TS_FAIL("testHWASpervStates: PERV[%d] HUID: %.8X - is Present and Parent is NOT",
                             chip_unit,
                            l_target->getAttr<ATTR_HUID>());
                        break;
                    }
                    HWAS_DBG("PERV[%d]: HUID: %.8X - %spresent, %sfunctional",
                        chip_unit,
                        l_target->getAttr<ATTR_HUID>(),
                        hwasState.present ? "" : "NOT ",
                        hwasState.functional ? "" : "NOT ");
                }
            }
        } while(0);

        TS_INFO( "testHWASpervStates exit" );
    }

    /**
     * @brief   test platReadLx
     */
    void testHWASplatReadLx()
    {
        using namespace TARGETING;

        TS_INFO( "testHWASplatReadLx entry" );

        // call platReadLx with target that isn't in the VPD
        errlHndl_t l_errl = nullptr;

        // Get system target
        Target* pSys;
        targetService().getTopLevelTarget(pSys);

        // Get processor targets
        TARGETING::TargetHandleList l_procList;
        getAllChips(l_procList, TYPE_PROC);

        // Get children of first processor target
        TargetHandleList l_childList;
        getChildChiplets(l_childList, *(l_procList.begin()), TYPE_NA, false);

        uint8_t lxData[HWAS::VPD_CRP0_LX_HDR_DATA_LENGTH];

        // Try using system target which does not have a chip unit attribute
        l_errl = HWAS::platReadLx(pSys, lxData);

        // Check that an error log is returned
        if (l_errl)
        {
            // error log is expected case, delete it
            delete l_errl;
            l_errl = nullptr;
        }
        else
        {
            TS_FAIL("testHWASplatReadLx> No error from platReadLx(pSys).");
        }

        // Find a target that has a large chip unit and use that target
        for( const auto & l_child_target: l_childList )
        {
            uint8_t l_chip_unit;
            if (l_child_target->
                tryGetAttr<TARGETING::ATTR_CHIP_UNIT>(l_chip_unit))
            {
                // Check if chip unit attribute is large enough
                if(l_chip_unit >= HWAS::VPD_CRP0_LX_MAX_X)
                {
                    // Try using target which has larger than expected chip unit
                    l_errl = HWAS::platReadLx(l_child_target, lxData);

                    // Check that an error log is returned
                    if (l_errl)
                    {
                        // error log is expected case, delete it
                        delete l_errl;
                        l_errl = nullptr;
                    }
                    else
                    {
                        TS_FAIL("testHWASplatReadLx> No error from "
                                "platReadLx(l_child_target 0x%8X).",
                                l_child_target->getAttr<ATTR_HUID>());
                    }

                    break;
                }
            }
        }

        TS_INFO( "testHWASplatReadLx exit" );
    }
};

#endif //
