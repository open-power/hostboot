/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/sbe/test/sbeupdatetest.H $                            */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013                   */
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
#ifndef __SBEUPDATETEST_H
#define __SBEUPDATETEST_H
/**
 *  @file sbeupdatetest.H
 *
 *  @brief Test cases for SBE Update code
 */
#include <sys/time.h>

#include <cxxtest/TestSuite.H>
#include <errl/errlmanager.H>
#include <errl/errlentry.H>
#include <devicefw/driverif.H>
#include <vfs/vfs.H>
#include <targeting/common/utilFilter.H>
#include <sbe/sbeif.H>
#include "../sbe_update.H"


extern trace_desc_t* g_trac_sbe;

// Macros for unit testing
//#define TRACUCOMP(args...)  TRACFCOMP(args)
#define TRACUCOMP(args...)

const char SBE_BUILD_WINK_NAME[30] = "libbuild_winkle_images.so";
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

    // This module is needed for certain HW procedure (like p8_xip_customize())
    if(!VFS::module_is_loaded(SBE_BUILD_WINK_NAME))
    {
        err = VFS::module_load(SBE_BUILD_WINK_NAME);
        if(err)
        {
            // Don't use g_trac_sbe - libsbe might not be loaded
            TS_FAIL("loadSbeModule() - %s load failed", SBE_BUILD_WINK_NAME);
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

    err = VFS::module_unload(SBE_BUILD_WINK_NAME);
    if(err)
    {
        // Don't use g_trac_sbe - libsbe might be unloaded
        TS_FAIL("unloadSbeModule() - %s unload failed", SBE_BUILD_WINK_NAME);
    }

    return err;
}


class SBEUpdateTest: public CxxTest::TestSuite
{
  public:

    /**
     * @brief This function will test __trimCoreMask
     */
    void testTrimBitMask( void )
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
                           "finding Proc SBE image for uid=0x%X, ec=0x%.2X"
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
            /*  Find a valid MemBuf                             */
            /****************************************************/
            theTarget = getFunctionalTarget(TARGETING::TYPE_MEMBUF);
            if(theTarget == NULL)
            {
                total++;
                fails++;
                TS_FAIL("testReadSbeFromPnor() - No Functional MemBuf Targets found!");
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
                           "finding MemBuf SBE image for uid=0x%X, ec=0x%.2X, "
                           "sbeImgPtr=%p, sbeImgSize=0x%x",
                           TARGETING::get_huid(theTarget),
                           theTarget->getAttr<TARGETING::ATTR_EC>(),
                           sbeImgPtr, sbeImgSize );
                TS_FAIL("testFindSbeInPnor() -failure finding SBE image!");
                errlCommit( err,
                            SBE_COMP_ID );

            }
            TRACDBIN(g_trac_sbe, "testFindSbeInPnor()-MEMBUF PNOR Version", &version, sizeof(version));
            TRACDBIN(g_trac_sbe, "testFindSbeInPnor()-MEMBUF PNOR Image", sbeImgPtr, 0x80);


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
        errlHndl_t err_cleanup = NULL;

        uint64_t fails = 0x0;
        uint64_t total = 0x0;
        sbeTargetState_t sbeState;

        do{

            /****************************************************/
            /* Get Functional Target and Load SBE Module        */
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

            err = createSbeImageVmmSpace();
            if(err)
            {
                total++;
                fails++;
                TS_FAIL("testSbeUpdateTarget() - Call to createSbeImageVmmSpace() failed");
                break;
            }


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
                      &sbeState.mvpdSbKeyword, sizeof(mvpdSbeVersion_t));
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
                sbeState.seeprom_side_to_update = EEPROM::SBE_BACKUP;
            }
            total++;

            err = performUpdateActions(sbeState);
            if(err)
            {
                fails++;
                TS_FAIL("testSbeUpdateTarget() - performUpdateActions() failed.");
                break;
            }


        }while(0);

        err_cleanup = cleanupSbeImageVmmSpace();
        if(err_cleanup)
        {
            total++;
            fails++;
            TS_FAIL("testSbeUpdateTarget() -Call to cleanupSbeImageVmmSpace() failed.");
            errlCommit( err_cleanup, SBE_COMP_ID );

        }

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
            sbeSeepromSide_t             i_cur;     // current_seeprom_side
            uint8_t                      i_flags;   // mvpdSbKeyword.flags

            // Expected Output
            sbeUpdateActions_t            o_update_actions;
            EEPROM::eeprom_chip_types_t   o_seeprom;
            uint8_t                       o_flags;   // mvpdSbKeyword.flags

        }  testData[] =
        {

            // case 0xE0: cur=temp, cur=dirty, alt=dirty
            // Arbitrarily set cur side to 0 (therefore perm set to 1)
            // - update alt=1
            // - make cur=perm
            // - re-IPL
            { 0xE0, SBE_SEEPROM0, 0x80,
              static_cast<sbeUpdateActions_t>(DO_UPDATE|IPL_RESTART),
              EEPROM::SBE_BACKUP, 0x40 },


            // case 0xC0: cur=temp, cur=dirty, alt=dirty
            // Arbitrarily set cur side to 1 (therefore perm set to 0)
            // - update alt=0
            // - make cur=perm
            // - re-IPL
            { 0xC0, SBE_SEEPROM1, 0x00,
              static_cast<sbeUpdateActions_t>(DO_UPDATE|IPL_RESTART),
              EEPROM::SBE_PRIMARY, 0x80 },

            // case 0xA0: cur=temp, cur=clean, alt=dirty
            // Arbitarily Set cur side to 1 (therefore perm set to 0)
            // - update alt=0
            // - make cur=perm
            // - Continue IPL
            { 0xA0, SBE_SEEPROM1, 0x00,
              static_cast<sbeUpdateActions_t>(DO_UPDATE),
              EEPROM::SBE_PRIMARY, 0x80 },

            // case 0x80: cur=temp, cur=clean, alt=clean
            // Arbitrarily set cur side to 1 (therefore perm set to 0)
            // - No updates
            // - Continue IPL
            { 0x80, SBE_SEEPROM1, 0x00,
              static_cast<sbeUpdateActions_t>(CLEAR_ACTIONS),
              EEPROM::LAST_CHIP_TYPE, 0x00 },

            // case 0x60: cur=perm, cur=dirty, alt=dirty
            // Arbitrarily set cur side to 0 (therefore perm set to 0)
            // - update alt=1
            // - re-IPL
            { 0x60, SBE_SEEPROM0, 0x00,
              static_cast<sbeUpdateActions_t>(DO_UPDATE|IPL_RESTART),
              EEPROM::SBE_BACKUP, 0x40 },

            // case 0x40: cur=perm, cur=dirty, alt=clean
            // This case asks FSP if we just re-IPLed, but assume we don't
            // get mbox msg back in sim so update and re-IPL on alt
            // Arbitrarily set cur side to 1 (therefore perm set to 1)
            // - update alt=0
            // - re-IPL
            { 0x40, SBE_SEEPROM1, 0x80,
              static_cast<sbeUpdateActions_t>(DO_UPDATE|IPL_RESTART),
              EEPROM::SBE_PRIMARY, 0x80 },

            // case 0x20: cur=perm, cur=clean, alt=dirty
            // Arbitrarily set cur side to 0 (therefore perm set to 0)
            // - update alt=1
            // - Continue IPL
            { 0x20, SBE_SEEPROM0, 0x00,
              static_cast<sbeUpdateActions_t>(DO_UPDATE),
              EEPROM::SBE_BACKUP, 0x00 },

            // case 0x00: cur=perm, cur=clean, alt=clean
            // Arbitrarily set cur side to 0 (therefore perm set to 0)
            // - No Updates
            // - Continue IPL
            // NOTE: this will test that right-most-bit is ignored:
            //  so techincally case 0x01, which should be = case 0x00
            { 0x01, SBE_SEEPROM0, 0x00,
              static_cast<sbeUpdateActions_t>(CLEAR_ACTIONS),
              EEPROM::LAST_CHIP_TYPE, 0x00 },

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
                TS_FAIL("testSbeUpdateTarget() - No Functional Targets found!");
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
                             ( ( testData[i].i_cur == SBE_SEEPROM0 )
                               ? SBE_SEEPROM1 : SBE_SEEPROM0 );

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
                    "Expected/Returned: update_actions=0x%.4X/0x%.4x, "
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
     * @brief Constructor
     */
    SBEUpdateTest() : CxxTest::TestSuite()
    {
        errlHndl_t err = NULL;
        uint64_t fails = 0x0;
        uint64_t total = 0x0;
        bool sbe_loaded = false;

        err = loadSbeModule(sbe_loaded);
        if(err)
        {
            total++;
            fails++;
            TS_FAIL("SBEUpdateTest() - Constuctor: failed to load modules");
            errlCommit( err, SBE_COMP_ID );
        }

    };


    /**
     * @brief Destructor
     */
    ~SBEUpdateTest()
    {
        errlHndl_t err = NULL;
        uint64_t fails = 0x0;
        uint64_t total = 0x0;

        err = unloadSbeModule();
        if(err)
        {
            total++;
            fails++;
            TS_FAIL("~SBEUpdateTest() - Destuctor: failed to load modules");
            errlCommit( err, SBE_COMP_ID );
        }

    };

};

#endif
