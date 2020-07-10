/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/sbe/test/sbeupdatetest.H $                            */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2020                        */
/* [+] Google Inc.                                                        */
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
#ifndef __SBEUPDATETEST_H
#define __SBEUPDATETEST_H
/**
 *  @file sbeupdatetest.H
 *
 *  @brief Test cases for SBE Update code
 */
#include <sys/time.h>
#include <vector>
#include <cxxtest/TestSuite.H>
#include <errl/errlmanager.H>
#include <errl/errlentry.H>
#include <devicefw/driverif.H>
#include <vfs/vfs.H>
#include <targeting/common/utilFilter.H>
#include <sbe/sbeif.H>
#include <sbe/sbe_update.H>
#include <secureboot/service.H>


extern trace_desc_t* g_trac_sbe;

// Macros for unit testing
//#define TRACUCOMP(args...)  TRACFCOMP(args)
#define TRACUCOMP(args...)

const char SBE_LIBRARY_NAME[16]    = "libsbe.so";


using namespace SBE;


void getTargetList( TARGETING::TYPE i_targetType,
                    TARGETING::TargetHandleList & o_targetList,
                    bool i_functional ) // if true: return functional targets
{


    TARGETING::getAllChips(o_targetList,
                           i_targetType,
                           i_functional);

    if ( o_targetList.size() == 0 )
    {
        TRACFCOMP( g_trac_sbe,
                   INFO_MRK"getTargetList() - Found Zero (%d) Targets of "
                   "type 0x%X",
                   o_targetList.size(), i_targetType );
    }

    TRACDCOMP( g_trac_sbe,
               "getTargetList() - found %d Targets of type 0x%X",
               o_targetList.size(), i_targetType );

    return;
}

TARGETING::Target* getFunctionalTarget(TARGETING::TYPE i_targetType)
{
    TARGETING::Target * theTarget = NULL;
    TRACDCOMP( g_trac_sbe,
               "getFunctionalTarget() - Finding Target of Type 0x%0x",
               i_targetType );

    do {
        // Get the Processor targets
        TARGETING::TargetHandleList targetList;
        getTargetList( i_targetType, targetList, true );

        if( ( 0 == targetList.size() ) ||
            ( NULL == targetList[0] ) )
        {
            TRACFCOMP( g_trac_sbe, ERR_MRK"getFunctionalTarget() - Couldn't "
                       "find functional Target of Type 0x%0x (list.size=%d)",
                       i_targetType, targetList.size());
            continue;  // continue because have no valid targets
        }

        // List is of functional targets, so just return the first one
        theTarget = targetList[0];

    }while(0);

    TRACDCOMP( g_trac_sbe,
               "getFunctionalTarget() - Returning Target 0x%0x of Type 0x%0x",
               TARGETING::get_huid(theTarget), i_targetType );

    return theTarget;

}


errlHndl_t loadSbeModule(bool& o_loaded)
{
    errlHndl_t err = NULL;
    o_loaded = false;

    if(!VFS::module_is_loaded(SBE_LIBRARY_NAME))
    {
        err = VFS::module_load(SBE_LIBRARY_NAME);
        if(err)
        {
            // Don't use g_trac_sbe - libsbe might not be loaded
            TS_FAIL("loadSbeModule() - %s load failed", SBE_LIBRARY_NAME );

        }
        else
        {
            o_loaded = true;
        }
    }

    return err;
}

errlHndl_t unloadSbeModule()
{
    errlHndl_t err = NULL;

    err = VFS::module_unload(SBE_LIBRARY_NAME);
    if(err)
    {
        // Don't use g_trac_sbe - libsbe might be unloaded
        TS_FAIL("unloadSbeModule() - %s unload failed", SBE_LIBRARY_NAME );

        // No break or return - still try and unload other module
    }

    return err;
}


class SBEUpdateTest: public CxxTest::TestSuite
{
  public:

    /**
     * @brief This function will test __trimCoreMask
     */
    void  testTrimBitMask( void )
    {

        uint64_t fails = 0x0;
        uint64_t total = 0x0;

        do{

            TRACFCOMP( g_trac_sbe,
                       ENTER_MRK"testTrimBitMask()" );

            struct
            {
                uint32_t inMask;
                uint32_t maxBits;
                uint32_t outMask;
            } testData[] =
            {
                {0xFFFFFFFF, 10, 0x000003FF},
                {0xFFFFFFFF, 32, 0xFFFFFFFF},
                {0x0000FF00, 4,  0x00000F00},
                {0x0000FA30, 3,  0x00000230},
                {0x0000FF00, 8,  0x0000FF00},
                {0x0000FF50, 16, 0x0000FF50},
                {0x0000EC50, 4,  0x00000C50},
                {0x000000FF, 5,  0x0000001F},
                {0x000000FF, 8,  0x000000FF},
                {0x11111111, 5,  0x00011111},
                {0x55555555, 11, 0x00155555},
            };
            const uint32_t NUM_TESTS = sizeof(testData)/sizeof(testData[0]);

            uint32_t retMask = 0;

            for(uint32_t i=0; i < NUM_TESTS; i++)
            {
                retMask = trimBitMask(testData[i].inMask,
                                      testData[i].maxBits);
                total++;
                if(retMask != testData[i].outMask)
                {
                    fails++;
                    TRACFCOMP( g_trac_sbe, ERR_MRK"testTrimBitMask() - i=%d, "
                               "retMask=0x%.8X, expMask=0x%.8X",
                               i, retMask, testData[i].outMask);
                    TS_FAIL("testTrimBitMask() - Return data did not match "
                            "expected data.");
                }
            }

        }while(0);

        TRACFCOMP( g_trac_sbe,
                   EXIT_MRK"testTrimBitMask - %d/%d fails",
                   fails, total );
    }


    /**
     * @brief This function will test the calculation of ECC sizes
     */
    void  testSetECCSize( void )
    {

        uint64_t fails = 0x0;
        uint64_t total = 0x0;

        do{

            TRACFCOMP( g_trac_sbe,
                       ENTER_MRK"testSetECCSize()" );

            struct
            {
                uint8_t  optionalParms;
                size_t   inSize;
                uint64_t inOffset;
                uint64_t inBoundary;
                size_t   outEccSize;
            } testData[] =
            {
                {0, 0x0000E380, 0x00000000, 0x00010000, 0x0000FFF0},
                {0, 0x0000E388, 0x00000000, 0x00010000, 0x0000FFF9},
                {0, 0x0000E390, 0x00000000, 0x00010000, 0x00010002},
                {0, 0x0001C710, 0x00000000, 0x00010000, 0x0001FFF2},
                {0, 0x0001C718, 0x00000000, 0x00010000, 0x0001FFFB},
                {1, 0x00014710, 0x00009000, 0x00010000, 0x00016FF2},
                {1, 0x00014718, 0x00009000, 0x00010000, 0x00016FFB},
                {2, 0x0001C718, 0x00000000, 0x00020000, 0x0001FFFB},
                {2, 0x0001C720, 0x00000000, 0x00020000, 0x00020009},
                {2, 0x00018718, 0x00004800, 0x00020000, 0x0001B7FB},
                {2, 0x00018720, 0x00004800, 0x00020000, 0x0001B809},
            };
            const uint32_t NUM_TESTS = sizeof(testData)/sizeof(testData[0]);

            size_t retEccSize = 0;

            for(uint32_t i=0; i < NUM_TESTS; i++)
            {
                switch(testData[i].optionalParms)
                {
                    case 1:
                        retEccSize = setECCSize(testData[i].inSize,
                                                testData[i].inOffset);
                    break;

                    case 2:
                        retEccSize = setECCSize(testData[i].inSize,
                                                testData[i].inOffset,
                                                testData[i].inBoundary);
                    break;

                    default:
                        retEccSize = setECCSize(testData[i].inSize);
                    break;
                }
                total++;
                if(retEccSize != testData[i].outEccSize)
                {
                    fails++;
                    TRACFCOMP( g_trac_sbe, ERR_MRK"testSetECCSize() - i=%d, "
                               "retEccSize=0x%.8X, expEccSize=0x%.8X",
                               i, retEccSize, testData[i].outEccSize);
                    TS_FAIL("testSetECCSize() - Return size did not match "
                            "expected size.");
                }
            }

        }while(0);

        TRACFCOMP( g_trac_sbe,
                   EXIT_MRK"testSetECCSize - %d/%d fails",
                   fails, total );
    }


    /**
     * @brief This function will test the injection and the removal of
     *         ECC from what is stored in a buffer
     */
    void  testInjectRemoveECC( void )
    {

        uint64_t fails = 0x0;
        uint64_t total = 0x0;
        int memcmpRtn;
        PNOR::ECC::eccStatus rtnEccStatus;

        const uint64_t boundary = 0x800;
        size_t noEccBufferSz = 0x2000;
        uint8_t noEccBuffer1[noEccBufferSz];
        uint8_t noEccBuffer2[noEccBufferSz];
        size_t eccBuffer1Sz = setECCSize(noEccBufferSz, 0, boundary);
        size_t ecc2Sz1 = setECCSize(0x400, 0, boundary);
        size_t ecc2Sz2 = setECCSize(0x400, ecc2Sz1, boundary);
        size_t ecc2Sz3 = setECCSize(0x1800, ecc2Sz1 + ecc2Sz2, boundary);
        size_t eccBuffer2Sz = ecc2Sz1 + ecc2Sz2 + ecc2Sz3;
        uint8_t eccBuffer1[eccBuffer1Sz];
        uint8_t eccBuffer2[eccBuffer2Sz];

        // Fill the noEccBuffer1 buffer with test data
        for(uint16_t i = 0;
            i < noEccBufferSz;
            i+=2)
        {
            uint16_t* pNoEccBuffer1 = (uint16_t*)(&noEccBuffer1[i]);
            *pNoEccBuffer1 = i / 2;
        }

        do{

            TRACFCOMP( g_trac_sbe,
                       ENTER_MRK"testInjectRemoveECC()" );

            // Verify expected sizes
            total++;
            if (eccBuffer1Sz != eccBuffer2Sz)
            {
                fails++;
                TRACFCOMP( g_trac_sbe, ERR_MRK"testInjectRemoveECC() - "
                           "expected ECC buffer sizes are not equal, "
                           "eccBuffer1Sz=0x%.8X, eccBuffer2Sz=0x%.8X",
                           eccBuffer1Sz, eccBuffer2Sz);
                TS_FAIL("testInjectRemoveECC() - Expected ECC buffer "
                        "sizes are not equal.");
            }

            // Inject ECC on noEccBuffer1 in one call
            injectECC(noEccBuffer1,
                      noEccBufferSz,
                      0,
                      boundary,
                      eccBuffer1);
            for(uint16_t i = 1;
                i <= noEccBufferSz / boundary;
                i++)
            {
                // Test each boundary
                total++;
                for(uint16_t j = (boundary % 9);
                    j > 0;
                    j--)
                {
                    // Check each pad byte
                    uint16_t index = (boundary * i) - j;
                    if (eccBuffer1[index] != '\0')
                    {
                        fails++;
                        TRACFCOMP( g_trac_sbe, ERR_MRK"testInjectRemoveECC() - "
                               "inject ECC, failed check of boundary padding "
                               "eccBuffer1[0x%.8X]=0x%.2X",
                               index, eccBuffer1[index]);
                        TS_FAIL("testInjectRemoveECC() - Inject ECC, failed "
                                "check of boundary padding.");
                        break; // Only fail once per boundary
                    }
                }
            }

            // Inject ECC on noEccBuffer1 in multiple calls
            total++;
            injectECC(&noEccBuffer1[0],
                      0x400,
                      0,
                      boundary,
                      &eccBuffer2[0]);

            injectECC(&noEccBuffer1[0x400],
                      0x400,
                      ecc2Sz1,
                      boundary,
                      &eccBuffer2[ecc2Sz1]);

            injectECC(&noEccBuffer1[0x800],
                      0x1800,
                      ecc2Sz1 + ecc2Sz2,
                      boundary,
                      &eccBuffer2[ecc2Sz1 + ecc2Sz2]);

            for(uint16_t i = 0;
                i < eccBuffer1Sz;
                i++)
            {
                if (eccBuffer1[i] != eccBuffer2[i])
                {
                    fails++;
                    TRACFCOMP( g_trac_sbe, ERR_MRK"testInjectRemoveECC() - inject "
                               "ECC, eccBuffer1[0x%.8X]=0x%.2X does not match "
                               "eccBuffer2[0x%.8X]=0x%.2X with cmpSz=0x%.8X",
                               i, eccBuffer1[i], i, eccBuffer2[i],
                               eccBuffer1Sz);
                    TS_FAIL("testInjectRemoveECC() - Inject ECC, buffers with ECC "
                            "do not match each other.");
                    break;
                }
            }

            // Remove ECC in one call
            total++;
            rtnEccStatus = removeECC(eccBuffer1,
                                     noEccBuffer2,
                                     noEccBufferSz,
                                     0,
                                     boundary);

            if (rtnEccStatus == PNOR::ECC::UNCORRECTABLE)
            {
                fails++;
                TRACFCOMP( g_trac_sbe, ERR_MRK"testInjectRemoveECC() - remove "
                           "ECC (one call) rtnEccStatus=0x%.8X",
                           rtnEccStatus);
                TS_FAIL("testInjectRemoveECC() - Remove ECC (one call) "
                        "returned uncorrectable status.");
                break;
            }

            memcmpRtn = memcmp(noEccBuffer1,
                               noEccBuffer2,
                               noEccBufferSz);
            if (memcmpRtn != 0)
            {
                fails++;
                TRACFCOMP( g_trac_sbe, ERR_MRK"testInjectRemoveECC() - remove "
                           "ECC (one call) memcmpRtn=0x%.8X",
                           rtnEccStatus);
                TS_FAIL("testInjectRemoveECC() - Remove ECC (one call) buffer "
                        "does not match original buffer.");
            }

            // Remove ECC in multiple calls
            total++;
            rtnEccStatus = removeECC(&eccBuffer1[0],
                                     &noEccBuffer2[0],
                                     0x600,
                                     0,
                                     boundary);
            size_t removeSz1 = setECCSize(0x600, 0, boundary);

            if (rtnEccStatus == PNOR::ECC::UNCORRECTABLE)
            {
                fails++;
                TRACFCOMP( g_trac_sbe, ERR_MRK"testInjectRemoveECC() - remove "
                           "ECC (call 1 of multiple calls) rtnEccStatus=0x%.8X",
                           rtnEccStatus);
                TS_FAIL("testInjectRemoveECC() - Remove ECC (call 1 of "
                        "multiple calls) returned uncorrectable status.");
                break;
            }

            total++;
            rtnEccStatus = removeECC(&eccBuffer1[removeSz1],
                                     &noEccBuffer2[0x600],
                                     0x600,
                                     removeSz1,
                                     boundary);
            size_t removeSz2 = setECCSize(0x600, removeSz1, boundary);

            if (rtnEccStatus == PNOR::ECC::UNCORRECTABLE)
            {
                fails++;
                TRACFCOMP( g_trac_sbe, ERR_MRK"testInjectRemoveECC() - remove "
                           "ECC (call 2 of multiple calls) rtnEccStatus=0x%.8X",
                           rtnEccStatus);
                TS_FAIL("testInjectRemoveECC() - Remove ECC (call 2 of "
                        "multiple calls) returned uncorrectable status.");
                break;
            }

            total++;
            rtnEccStatus = removeECC(&eccBuffer1[removeSz1 + removeSz2],
                                     &noEccBuffer2[0xC00],
                                     0x1400,
                                     removeSz1 + removeSz2,
                                     boundary);

            if (rtnEccStatus == PNOR::ECC::UNCORRECTABLE)
            {
                fails++;
                TRACFCOMP( g_trac_sbe, ERR_MRK"testInjectRemoveECC() - remove "
                           "ECC (call 3 of multiple calls) rtnEccStatus=0x%.8X",
                           rtnEccStatus);
                TS_FAIL("testInjectRemoveECC() - Remove ECC (call 3 of "
                        "multiple calls) returned uncorrectable status.");
                break;
            }

            int memcmpRtn = memcmp(noEccBuffer1,
                                   noEccBuffer2,
                                   noEccBufferSz);
            if (memcmpRtn != 0)
            {
                fails++;
                TRACFCOMP( g_trac_sbe, ERR_MRK"testInjectRemoveECC() - remove "
                           "ECC (multiple calls) memcmpRtn=0x%.8X",
                           rtnEccStatus);
                TS_FAIL("testInjectRemoveECC() - Remove ECC (multiple calls) "
                        "buffer does not match original buffer.");
            }

        }while(0);

        TRACFCOMP( g_trac_sbe,
                   EXIT_MRK"testInjectRemoveECC - %d/%d fails",
                   fails, total );
    }


    /**
     * @brief This function will test SBE Update's ability
     *        to find SBE images in PNOR
     */

    void testFindSbeInPnor ( void )
    {
        errlHndl_t err = NULL;
        uint64_t fails = 0x0;
        uint64_t total = 0x0;

        TARGETING::Target* theTarget = NULL;
        void* sbeImgPtr = NULL;
        size_t sbeImgSize = 0;
        sbe_image_version_t version;

        do{

            TRACFCOMP( g_trac_sbe,
                       ENTER_MRK"testFindSbeInPnor()" );

            /****************************************************/
            /* Find a valid Processor                           */
            /****************************************************/
            theTarget = getFunctionalTarget(TARGETING::TYPE_PROC);
            if(theTarget == NULL)
            {
                total++;
                fails++;
                TS_FAIL("testReadSbeFromPnor() - No Functional Proc Targets found!");
                break;
            }

            total++;
            err = findSBEInPnor(theTarget,
                                sbeImgPtr,
                                sbeImgSize,
                                &version);

            if(err || (sbeImgPtr == NULL) || (sbeImgSize == 0) )
            {
                fails++;
                TRACFCOMP( g_trac_sbe, ERR_MRK"testFindSbeInPnor() - failure "
                           "finding Proc SBE image for uid=0x%X, ec=0x%.2X "
                           "sbeImgPtr=%p, sbeImgSize=0x%x",
                           TARGETING::get_huid(theTarget),
                           theTarget->getAttr<TARGETING::ATTR_EC>(),
                           sbeImgPtr, sbeImgSize );
                TS_FAIL("testFindSbeInPnor() -failure finding SBE image!");
                errlCommit( err,
                            SBE_COMP_ID );

            }
            TRACDBIN(g_trac_sbe, "testFindSbeInPnor()-Proc PNOR Version", &version, sizeof(version));
            TRACDBIN(g_trac_sbe, "testFindSbeInPnor()-Proc PNOR Image", sbeImgPtr, 0x80);


            /****************************************************/
            /* Verify invalid target Type is not found          */
            /****************************************************/
            // test with system target -- safe that this target is configured
            TARGETING::TargetService & tS = TARGETING::targetService();
            tS.getTopLevelTarget( theTarget );
            if(theTarget == NULL)
            {
                total++;
                fails++;
                TS_FAIL("testFindSbeInPnor() - System target Not Found!");
                break;
            }

            total++;
            err = findSBEInPnor(theTarget,
                                sbeImgPtr,
                                sbeImgSize);

            if(err)
            {
                TRACFCOMP( g_trac_sbe, "testFindSbeInPnor() - Did not "
                           "find system-target SBE image as expected: "
                           "uid=0x%X, err=0x%X",
                           TARGETING::get_huid(theTarget),
                           err->reasonCode() );
                delete err;
                err = NULL;
            }
            else
            {
                fails++;
                TRACFCOMP( g_trac_sbe, ERR_MRK"testFindSbeInPnor() - Fail "
                           " expected when searching for invalid target "
                           "(Xbus): uid=0x%X, ec=0x%.2X",
                           TARGETING::get_huid(theTarget),
                           theTarget->getAttr<TARGETING::ATTR_EC>() );

                TS_FAIL("testFindSbeInPnor() - Fail expected when searching for invalid EC level!");
                errlCommit( err,
                            SBE_COMP_ID );
            }

            TRACFCOMP( g_trac_sbe,
                       EXIT_MRK"testFindSbeInPnor - %d/%d fails",
                       fails, total );

        }while(0);

    }

    /**
     * @brief This function will run through the functions used to collect
     *        SBE information on a single target, determine if that target
     *        needs to be updated, and perform the update.
     */

    void testSbeUpdateTarget ( void )
    {

        errlHndl_t err = NULL;

        uint64_t fails = 0x0;
        uint64_t total = 0x0;
        sbeTargetState_t sbeState;

        do{

            /****************************************************/
            /* Get Functional Target and Create VMM Space       */
            /****************************************************/
            TARGETING::Target * theTarget =
                                getFunctionalTarget(TARGETING::TYPE_PROC);
            if(theTarget == NULL)
            {
                total++;
                fails++;
                TS_FAIL("testSbeUpdateTarget() - No Functional Targets found!");
                break;
            }

            TRACFCOMP( g_trac_sbe,
                       ENTER_MRK"testSbeUpdateTarget()" );

            uint8_t local_ec = theTarget->getAttr<TARGETING::ATTR_EC>();

            /****************************************************/
            /* Get SBE Info State                               */
            /****************************************************/
            // Clear struct
            memset(&sbeState, 0, sizeof(sbeState));

            // Must set struct's target field
            sbeState.target = theTarget;

            // set bad ec just for comparison to local_ec later
            sbeState.ec = 0xFF;

            total++;
            err = getSbeInfoState(sbeState);
            if(err)
            {
                fails++;
                TS_FAIL("testSbeUpdateTarget() - call getSbeInfoState() failed.");
                break;
            }


            /****************************************************/
            /* Compare/Display SBE Version Information          */
            /****************************************************/

            // Quick EC check
            if (local_ec != sbeState.ec)
            {
                fails++;
                TS_FAIL("testSbeUpdateTarget() - Bad ec check: local=0x%X, other=0x%X", local_ec, sbeState);
                break;
            }

            // Display sbeState
            TRACUCOMP( g_trac_sbe,
                       "testSbeUpdateTarget() Info For Target 0x%X ec=0x%X "
                       "cur=0x%X alt=0x%X, ECC_fail 0/1=%d/%d, isMaster=%d "
                       "Custom Image Size=0x%X, CRC=0x%X",
                       TARGETING::get_huid(sbeState.target), sbeState.ec,
                       sbeState.cur_seeprom_side, sbeState.alt_seeprom_side,
                       sbeState.seeprom_0_ver_ECC_fail,
                       sbeState.seeprom_1_ver_ECC_fail,
                       sbeState.target_is_master,
                       sbeState.customizedImage_size,
                       sbeState.customizedImage_crc);

            TRACDBIN( g_trac_sbe, "testSbeUpdateTarget()-pnorVersion",
                      &sbeState.pnorVersion, sizeof(sbe_image_version_t));
            TRACDBIN( g_trac_sbe, "testSbeUpdateTarget()-mvpdSbKeyword",
                      &sbeState.mvpdSbKeyword, sizeof(mvpdSbKeyword_t));
            TRACDBIN( g_trac_sbe, "testSbeUpdateTarget()-seeprom_0_ver",
                      &sbeState.seeprom_0_ver,
                      sizeof(sbeSeepromVersionInfo_t));
            TRACDBIN( g_trac_sbe, "testSbeUpdateTarget()-seeprom_1_ver",
                      &sbeState.seeprom_1_ver,
                      sizeof(sbeSeepromVersionInfo_t));



            /****************************************************/
            /* Get Target Update Actions                        */
            /****************************************************/

            total++;
            err = getTargetUpdateActions(sbeState);
            if(err)
            {
                fails++;
                TS_FAIL("testSbeUpdateTarget() - getTargetUpdateActions() failed");
                break;
            }


            /****************************************************/
            /* Update SBE Backup                                */
            /****************************************************/
            // force backup to SEEPROM 1 just in case
            if ( !(sbeState.update_actions & DO_UPDATE ) )
            {
                sbeState.update_actions =
                    static_cast<sbeUpdateActions_t>
                         (DO_UPDATE|UPDATE_MVPD|UPDATE_SBE),

                sbeState.seeprom_side_to_update = EEPROM::SBE_BACKUP;

                sbeState.new_readBack_check = true;
            }
            total++;

            err = performUpdateActions(sbeState);
            if(err)
            {
                fails++;
                TS_FAIL("testSbeUpdateTarget() - performUpdateActions() failed.");
                break;
            }

            // Make sure MVPD and SBE were updated
            if ( ! ( ( sbeState.update_actions & MVPD_UPDATE_COMPLETE ) &&
                     ( sbeState.update_actions & SBE_UPDATE_COMPLETE  ) ) )
            {
                TRACFCOMP( g_trac_sbe, ERR_MRK"testSbeUpdateTarget(): "
                           "'COMPLETE' actions were not found: 0x%.8X",
                           sbeState.update_actions);
                fails++;
                TS_FAIL("testSbeUpdateTarget() - performUpdateActions() did not complete actions");
                break;
            }

            total++;
            SHA512_t hash = {0};
            uint8_t secure_version=0;
            err = getSecuritySettingsFromSbeImage(sbeState.target,
                                                  EEPROM::SBE_BACKUP,
                                                  SBE_SEEPROM_INVALID,
                                                  hash,
                                                  secure_version);

            if(err)
            {
                fails++;
                TS_FAIL("testSbeUpdateTarget() - getSecuritySettingsFromSbeImage() failed.");
                break;
            }

            // Make sure that the HW Key Hash returned is the system hash
            SHA512_t sys_hash = {0};
            SECUREBOOT::getHwKeyHash(sys_hash);
            if ( memcmp(hash, sys_hash, sizeof(SHA512_t)) != 0 )
            {
                TRACFCOMP( g_trac_sbe, ERR_MRK"testSbeUpdateTarget(): "
                           "HW Key Hashes do not match!");
                fails++;
                TS_FAIL("testSbeUpdateTarget() - getHwKeyHashFromSbeImage() did not return system hash");

                TRACFBIN( g_trac_sbe, "testSbeUpdateTarget() hash",
                          hash, sizeof(SHA512_t));
                TRACFBIN( g_trac_sbe, "testSbeUpdateTarget() sys_hash",
                          sys_hash, sizeof(SHA512_t));

                break;
            }

        }while(0);

        TRACFCOMP( g_trac_sbe,
                   EXIT_MRK"testSbeUpdateTarget() - %d/%d fails",
                   fails, total );
    }

    /**
     * @brief This function will call decisionTreeForUpdates() and make
              sure the correct update action is returned for a specific
              situation.
     */
    void testSbeDecisionTree ( void )
    {

        uint64_t fails = 0x0;
        uint64_t total = 0x0;

        sbeTargetState_t sbeState;

        struct
        {
            // Inputs
            uint8_t                      i_situation;
            SBE::sbeSeepromSide_t        i_cur;     // current_seeprom_side
            uint8_t                      i_flags;   // mvpdSbKeyword.flags

            // Expected Output
            sbeUpdateActions_t            o_update_actions;
            EEPROM::EEPROM_ROLE           o_seeprom;
            uint8_t                       o_flags;   // mvpdSbKeyword.flags

        }  testData[] =
        {
#ifdef CONFIG_SBE_UPDATE_SEQUENTIAL
            // case 0xE0: cur=temp, cur=dirty, alt=dirty
            // Arbitrarily set cur side to 0 (therefore perm set to 1)
            // - update alt=1
            // - make cur=perm
            // - re-IPL
            { 0xE0, SBE::SBE_SEEPROM0, 0x80,
              static_cast<sbeUpdateActions_t>
                     (DO_UPDATE|IPL_RESTART|UPDATE_MVPD|UPDATE_SBE),
              EEPROM::SBE_BACKUP, 0x40 },

            // case 0xC0: cur=temp, cur=dirty, alt=dirty
            // Arbitrarily set cur side to 1 (therefore perm set to 0)
            // - update alt=0
            // - make cur=perm
            // - re-IPL
            { 0xC0, SBE::SBE_SEEPROM1, 0x00,
              static_cast<sbeUpdateActions_t>
                     (DO_UPDATE|IPL_RESTART|UPDATE_MVPD|UPDATE_SBE),
              EEPROM::SBE_PRIMARY, 0x80 },

            // case 0xA0: cur=temp, cur=clean, alt=dirty
            // Arbitrarily Set cur side to 1 (therefore perm set to 0)
            // - update alt=0
            // - make cur=perm
            // - Continue IPL
            { 0xA0, SBE::SBE_SEEPROM1, 0x00,
              static_cast<sbeUpdateActions_t>
                     (DO_UPDATE|UPDATE_MVPD|UPDATE_SBE),
              EEPROM::SBE_PRIMARY, 0x80 },

            // case 0x80: cur=temp, cur=clean, alt=clean
            // Arbitrarily set cur side to 1 (therefore perm set to 0)
            // - No updates
            // - Continue IPL
            { 0x80, SBE::SBE_SEEPROM1, 0x00,
              static_cast<sbeUpdateActions_t>(CLEAR_ACTIONS),
              EEPROM::LAST_CHIP_TYPE, 0x00 },

            // case 0x60: cur=perm, cur=dirty, alt=dirty
            // Arbitrarily set cur side to 0 (therefore perm set to 0)
            // - update alt=1
            // - re-IPL
            { 0x60, SBE::SBE_SEEPROM0, 0x00,
              static_cast<sbeUpdateActions_t>
                     (DO_UPDATE|IPL_RESTART|UPDATE_MVPD|UPDATE_SBE),
              EEPROM::SBE_BACKUP, 0x40 },

            // case 0x40: cur=perm, cur=dirty, alt=clean
            // This case asks FSP if we just re-IPLed, but assume we don't
            // get mbox msg back in sim so update and re-IPL on alt
            // Arbitrarily set cur side to 1 (therefore perm set to 1)
            // - update alt=0
            // - re-IPL
            { 0x40, SBE::SBE_SEEPROM1, 0x80,
              static_cast<sbeUpdateActions_t>
                     (DO_UPDATE|IPL_RESTART|UPDATE_MVPD|UPDATE_SBE),
              EEPROM::SBE_PRIMARY, 0x80 },

            // Repeat previous case to make sure global variables are used
            // correctly to save MBOX value
            { 0x40, SBE::SBE_SEEPROM1, 0x80,
              static_cast<sbeUpdateActions_t>
                     (DO_UPDATE|IPL_RESTART|UPDATE_MVPD|UPDATE_SBE),
              EEPROM::SBE_PRIMARY, 0x80 },

            // case 0x20: cur=perm, cur=clean, alt=dirty
            // Arbitrarily set cur side to 0 (therefore perm set to 0)
            // - update alt=1
            // - Continue IPL
            { 0x20, SBE::SBE_SEEPROM0, 0x00,
              static_cast<sbeUpdateActions_t>(DO_UPDATE|UPDATE_SBE),
              EEPROM::SBE_BACKUP, 0x00 },

            // case 0x00: cur=perm, cur=clean, alt=clean
            // Arbitrarily set cur side to 0 (therefore perm set to 0)
            // - No Updates
            // - Continue IPL
            // NOTE: this will test that right-most-bit is ignored:
            //  so techincally case 0x01, which should be = case 0x00
            { 0x01, SBE::SBE_SEEPROM0, 0x00,
              static_cast<sbeUpdateActions_t>(CLEAR_ACTIONS),
              EEPROM::LAST_CHIP_TYPE, 0x00 },
#endif // SBE_UPDATE_SEQUENTIAL
        };

        const uint32_t NUM_CMDS = sizeof(testData)/sizeof(testData[0]);


        do{

            TRACFCOMP( g_trac_sbe,
                       ENTER_MRK"testSbeDecisionTree()" );

            // Get and Set a target for sbeState
            TARGETING::Target * theTarget =
                                getFunctionalTarget(TARGETING::TYPE_PROC);
            if(theTarget == NULL)
            {
                total++;
                fails++;
                TS_FAIL("testSbeDecisionTree() - No Functional Targets found!");
                break;
            }
            sbeState.target = theTarget;

            // Loop through each situation
            for( uint32_t i = 0; i < NUM_CMDS; i++ )
            {

                sbeState.update_actions   = CLEAR_ACTIONS;

                /****************************************************/
                /* Set Input Values                                 */
                /****************************************************/
                sbeState.cur_seeprom_side = testData[i].i_cur;

                sbeState.alt_seeprom_side =
                             ( ( testData[i].i_cur == SBE::SBE_SEEPROM0 )
                               ? SBE::SBE_SEEPROM1 : SBE::SBE_SEEPROM0 );

                sbeState.mvpdSbKeyword.flags = testData[i].i_flags;


                /****************************************************/
                /* Get Target Update Actions                        */
                /****************************************************/

                total++;
                SBE::decisionTreeForUpdates(sbeState,
                                            testData[i].i_situation);


                /****************************************************/
                /* Check Output Values                              */
                /****************************************************/
                if (( testData[i].o_update_actions != sbeState.update_actions )
                     ||
                    ( testData[i].o_seeprom != sbeState.seeprom_side_to_update )
                     ||
                    ( testData[i].o_flags != sbeState.mvpdSbKeyword.flags )
                   )
                {
                    fails++;

                    TRACFCOMP( g_trac_sbe, ERR_MRK"testSbeDecisionTree() - "
                    "Fail! Unexpected results for situation=0x%.2X (i=%d): "
                    "Inputs: cur=%d, flags=0x%.2X",
                    testData[i].i_situation, i,
                    testData[i].i_cur, testData[i].i_flags);

                    TRACFCOMP( g_trac_sbe, ERR_MRK"testSbeDecisionTree() - "
                    "Expected/Returned: update_actions=0x%.4X/0x%.4X, "
                    "update seeprom=%d/%d, flags=0x%.2X/0x%.2X",
                    testData[i].o_update_actions, sbeState.update_actions,
                    testData[i].o_seeprom, sbeState.seeprom_side_to_update,
                    testData[i].o_flags, sbeState.mvpdSbKeyword.flags);

                    TS_FAIL("testSbeDecisionTree() - Fail! Unexpected results for pass %d, situation=0x%.2X", i, testData[i].i_situation);

                    // Don't break - complete the remaining tests
                }

           } // end of for-loop

        }while(0);

        TRACFCOMP( g_trac_sbe, EXIT_MRK
                   EXIT_MRK"testSbeDecisionTree() - %d/%d fails",
                   fails, total );
    }

    /**
     * @brief This function will call preReIplCheck() and make sure that
              all the targets are ready for the Re-Ipl Request
     */
    void testSbePreReIplCheck ( void )
    {


        TRACFCOMP( g_trac_sbe,
                   ENTER_MRK"testSbePreReIplCheck");

        uint64_t fails = 0x0;
        uint64_t total = 0x0;
        errlHndl_t err = NULL;

        std::vector<sbeTargetState_t> sbeStates_vector;
        sbeTargetState_t sbeState;

        struct
        {
            // Inputs
            sbeUpdateActions_t      i_update_actions;
            uint8_t                 i_flags;   // mvpdSbKeyword.flags

            // Expected Output
            sbeUpdateActions_t      o_update_actions;
            uint8_t                 o_flags;   // mvpdSbKeyword.flags

        }  testData[] =
        {

            // Update already done -- Flags match
            { static_cast<sbeUpdateActions_t>(MVPD_UPDATE_COMPLETE), 0x00,
              static_cast<sbeUpdateActions_t>(MVPD_UPDATE_COMPLETE), 0x00},

            // Update already done -- Flags don't match A
            { static_cast<sbeUpdateActions_t>(MVPD_UPDATE_COMPLETE), 0x80,
              static_cast<sbeUpdateActions_t>(MVPD_UPDATE_COMPLETE), 0x80},

            // Update already done -- Flags don't match B
            { static_cast<sbeUpdateActions_t>(MVPD_UPDATE_COMPLETE), 0x40,
              static_cast<sbeUpdateActions_t>(MVPD_UPDATE_COMPLETE), 0x40},

            // Update Not Done -- Flags match 0
            { static_cast<sbeUpdateActions_t>(CLEAR_ACTIONS), 0x00,
              static_cast<sbeUpdateActions_t>(CLEAR_ACTIONS), 0x00},

            // Update Not Done -- Flags match 1
            // AND testing that other actions aren't being lost
            { static_cast<sbeUpdateActions_t>(DO_UPDATE), 0xC0,
              static_cast<sbeUpdateActions_t>(DO_UPDATE), 0xC0},

            // Update Note Done -- Flags don't match A
            { static_cast<sbeUpdateActions_t>(CLEAR_ACTIONS), 0x80,
              static_cast<sbeUpdateActions_t>(MVPD_UPDATE_COMPLETE), 0xC0},

            // Update Note Done -- Flags don't match B
            { static_cast<sbeUpdateActions_t>(CLEAR_ACTIONS), 0x40,
              static_cast<sbeUpdateActions_t>(MVPD_UPDATE_COMPLETE), 0x00},



        };

        const uint32_t NUM_CMDS = sizeof(testData)/sizeof(testData[0]);

        do{


            /****************************************************/
            /* Get Functional Target and Create VMM Space       */
            /****************************************************/
            TARGETING::Target * theTarget =
                                getFunctionalTarget(TARGETING::TYPE_PROC);
            if(theTarget == NULL)
            {
                total++;
                fails++;
                TS_FAIL("testSbePreReIplCheck() - No Functional Targets found!");
                break;
            }

            /****************************************************/
            /* Create vector of sbeStates for testing           */
            /****************************************************/
            for (uint8_t i = 0; i < NUM_CMDS ; i++)
            {
                // Setup Test Data
                sbeState.mvpdSbKeyword.flags = testData[i].i_flags;
                sbeState.update_actions = testData[i].i_update_actions;

                // Put the same target into each sbeState
                sbeState.target = theTarget;

                // Push this sbeState onto the vector
                sbeStates_vector.push_back(sbeState);
            }


            /****************************************************/
            /* Call preReIplCheck()                             */
            /****************************************************/
            total++;
            err = preReIplCheck(sbeStates_vector);
            if(err)
            {
                fails++;
                TS_FAIL("testSbePreReIplCheck() - preReIplCheck() failed");
                break;
            }

            /****************************************************/
            /* Check Ouput Values                               */
            /****************************************************/
            for (uint8_t i = 0; i < NUM_CMDS ; i++)
            {
                if (( testData[i].o_update_actions !=
                                  sbeStates_vector[i].update_actions )
                     ||
                    ( testData[i].o_flags !=
                                  sbeStates_vector[i].mvpdSbKeyword.flags )
                   )
                {
                    fails++;

                    TRACFCOMP( g_trac_sbe, ERR_MRK"testSbePreReIplCheck() - "
                    "Fail! Unexpected results (i=%d): Input/Expected/Returned "
                    "flags=0x%.2X/0x%.2X/0x%.2X, update_actions=0x%.4X/0x%.4x"
                    "/0x%.4X", i, testData[i].i_flags, testData[i].o_flags,
                    sbeStates_vector[i].mvpdSbKeyword.flags,
                    testData[i].i_update_actions,
                    testData[i].o_update_actions,
                    sbeStates_vector[i].update_actions);

                    TS_FAIL("testSbePreReIplCheck() - Fail! Unexpected results for pass %d", i);

                    // Don't break - complete the remaining tests
                }
            }

        }while(0);

        TRACFCOMP( g_trac_sbe, EXIT_MRK
                   EXIT_MRK"testSbePreReIplCheck() - %d/%d fails",
                   fails, total );
    }




    /**
     * @brief Constructor
     */
    SBEUpdateTest() : CxxTest::TestSuite()
    {
        errlHndl_t err = nullptr;
        bool sbe_loaded = false;

        err = loadSbeModule(sbe_loaded);
        if(err)
        {
            TS_FAIL("SBEUpdateTest() - Constuctor: failed to load modules");
            errlCommit( err, SBE_COMP_ID );
        }

        err = createSbeImageVmmSpace();
        if(err)
        {
            TS_FAIL("SBEUpdateTest() - Constructor: Call to createSbeImageVmmSpace() failed");
            errlCommit( err, SBE_COMP_ID );
        }

    };


    /**
     * @brief Destructor
     */
    ~SBEUpdateTest()
    {
        errlHndl_t err = nullptr;

        err = cleanupSbeImageVmmSpace();
        if(err)
        {
            TS_FAIL("~SBEUpdateTest() - Destructor: Call to cleanupSbeImageVmmSpace() failed.");
            errlCommit( err, SBE_COMP_ID );
        }

        err = unloadSbeModule();
        if(err)
        {
            TS_FAIL("~SBEUpdateTest() - Destructor: failed to load modules");
            errlCommit( err, SBE_COMP_ID );
        }

    };

};

#endif
