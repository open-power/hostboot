/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/vpd/test/spdtest.H $                                  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2024                        */
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
#ifndef __SPDTEST_H
#define __SPDTEST_H

/**
 *  @file spdtest.H
 *
 *  @brief Test cases for SPD code
 */
#include <sys/time.h>

#include <cxxtest/TestSuite.H>
#include <cxxtest/TestInject.H>
#include <errl/errlmanager.H>
#include <errl/errlentry.H>
#include <devicefw/driverif.H>
#include <targeting/common/predicates/predicates.H>
#include <targeting/common/utilFilter.H>

#include <vpd/vpdreasoncodes.H>
#include <vpd/spdenums.H>
#include "../spdDDR3.H"
#include "../spdDDR4.H"
#include "../spdDDR4_DDIMM.H"
#include "../spdDDR5_DDIMM.H"
#include "../spd_planar.H"
#include "../spd.H"

#include <arch/magic.H>

extern trace_desc_t* g_trac_spd;

using namespace TARGETING;
using namespace ERRORLOG;
using namespace SPD;
using namespace std;
using namespace CxxTest;

void getDIMMTargets ( TargetHandleList & o_dimmList )
{
    // Get Dimm list.
    getAllLogicalCards( o_dimmList,
                        TARGETING::TYPE_DIMM );
    TRACDCOMP( g_trac_spd,
               "getDIMMTargets() - found %d DIMMs",
               o_dimmList.size() );
    return;
}

errlHndl_t getMemType( TARGETING::Target * i_target,
                 uint8_t & i_memType )
{
    errlHndl_t err = nullptr;
    size_t theSize = 0x1;
    err = deviceRead( i_target,
                      &i_memType,
                      theSize,
                      DEVICE_SPD_ADDRESS( SPD::BASIC_MEMORY_TYPE ) );

    return err;
}

class SPDTest: public CxxTest::TestSuite
{
  public:

   // Compile out this code because it uses data types from TestInject_defs.H
   //  and TestInject.C
   // Those data types are compiled out using this flag in those files, so this
   //  code must be compiled out also.

    /**
     * @brief This test ensures the correct CRC handling for the DDR5 End_User VPD
     */
    void testCRCforDDR5(void)
    {
#ifdef CONFIG_COMPILE_CXXTEST_HOOKS
        /*----------------------------------------------------------------------
          These testcases manipulate the End_User section of the vpd, in order
          to verify that its CRC is handled correctly.

          Expectations for the End_User section CRC handling:
            1. if CRC is zero, then checkCRC updates the section with good CRC
            2. if bad CRC is detected, then checkCRC bzero's the data and CRC
            3. A deviceWrite to the vpd also updates the CRC

            The Testcases verify these functions:
            1. detect bad CRC value
            2. repair bad CRC value
            3. detect bad VPD data
            4. repair bad VPD data
            5. CRC==0                    (new)
            6. keyword write updates CRC (new)

            TC1_FIRST_TIME_USE_ZERO_CRC
               a. write a zero CRC value, when the section has valid data
               b. call checkCRC with CHECK to ensure bad CRC is detected,
                   the bad CRC is fixed,
                   no error log is returned
            TC2_CORRUPTED_VPD_DATA
               a. write a keyword without updating the CRC
               b. call checkCRC with CHECK to ensure bad CRC is detected,
                   the entire section is bzero'd, which repairs the CRC
                   no error log is returned
            TC3_KEYWORD_WRITE_UPDATES_CRC
               a. call deviceWrite to write a keyword (which will update the CRC)
               b. call checkCRC with CHECK to ensure CRC is good,
                   no error log is returned
            TC4_CORRUPT_OTHER_CRC
               a. write a bad CRC value to a different section than End_User
               b. call checkCRC with CHECK to ensure the bad CRC is detected,
                   an error log is returned
               c. call checkCRC with FIX to ensure the bad CRC is detected,
                   the bad CRC is fixed,
                   no error log is returned
         *--------------------------------------------------------------------*/

        TRACFCOMP( g_trac_spd, ENTER_MRK"testCRCforDDR5" );

        TargetHandleList      l_dimmList{};
        crc_section_t         l_end_user(SPD_DDR5_DDIMM_USER_SECTION_START,
                                         SPD_DDR5_DDIMM_USER_SECTION_LENGTH);
        crc_section_t         l_other(512,128);
        vector<crc_section_t> l_sections;
        Target               *l_target   = nullptr;
        errlHndl_t            l_errl     = nullptr;
        const KeywordData    *l_keyword  = {nullptr};
        uint8_t               l_mem_type = 0x0;
        uint32_t              l_huid{};
        size_t                l_addr{};
        size_t                l_bytes{};
        uint8_t               l_buf[256]{0};

        getDIMMTargets(l_dimmList);

        for (auto l_dimm : l_dimmList)
        {
            l_errl = getMemType( l_dimm, l_mem_type );
            if (l_errl)
            {
                TS_FAIL("testCRCforDDR5 - failed to read memtype %x", get_huid(l_dimm));
                l_errl->setSev(ERRL_SEV_INFORMATIONAL);
                errlCommit(l_errl, CXXTEST_COMP_ID);
                continue;
            }
            if (l_mem_type == SPD::DDR5_TYPE)
            {
                l_target = l_dimm;
                break;
            }
        }
        if (!l_target)
        {
            TS_INFO("testCRCforDDR5 - No DDR5 DIMM target found");
            goto EXIT;
        }

        // add the End_User section to the l_sections
        l_sections.push_back(l_end_user);

        // Get SPD keyword EXPLORER_FW_VERSION info
        //  (use this keyword addr/len to test the update of the VPD data)
        l_errl = getKeywordEntry(SPD::EXPLORER_FW_VERSION,
                                 SPD::DDR5_TYPE,
                                 l_target,
                                 l_keyword);
        if (l_errl)
        {
            TS_FAIL("testCRCforDDR5: failed to get addr of EXPLORER_FW_VERSION 0x%x",
                    get_huid(l_target));
            l_errl->setSev(ERRL_SEV_INFORMATIONAL);
            errlCommit(l_errl, CXXTEST_COMP_ID);
            goto EXIT;
        }
        l_huid = get_huid(l_target);

        //----------------------------------------------------------------------
        // INIT the VPD so it contains some data, then the CRC is non-zero
        //----------------------------------------------------------------------
        TS_INFO("testCRCforDDR5: 0x%x init a keyword in End_User VPD", l_huid);
        l_buf[0] = getTB()%16; l_buf[1] = l_buf[0]+1; l_buf[2] = l_buf[0]+2;
        l_addr   = l_keyword->offset;
        l_bytes  = l_keyword->length;
        l_errl   = DeviceFW::deviceOp(DeviceFW::WRITE,  // write some VPD data
                                      l_target,
                                      &l_buf,
                                      l_bytes,
                                      DEVICE_EEPROM_ADDRESS(EEPROM::VPD_AUTO,
                                                            l_addr,
                                                            EEPROM::AUTOSELECT));
        if (l_errl)
        {
            TS_FAIL("testCRCforDDR5: failed writing initial VPD data on 0x%x",
                    l_huid);
            l_errl->setSev(ERRL_SEV_INFORMATIONAL);
            errlCommit(l_errl, CXXTEST_COMP_ID);
            goto EXIT;
        }
        // The VPD is now non-zero, with non-zero section CRC

        //----------------------------------------------------------------------
        // TC1_FIRST_TIME_USE_ZERO_CRC
        //----------------------------------------------------------------------
        TS_INFO("testCRCforDDR5: TC1_FIRST_TIME_USE_ZERO_CRC 0x%x", l_huid);
        l_end_user.crcActual = 0; // write zero to create bad CRC
        l_errl = updateCRC(l_target, EEPROM::VPD_AUTO, EEPROM::AUTOSELECT, l_end_user);
        if (l_errl)
        {
            TS_FAIL("testCRCforDDR5: TC1_FIRST_TIME_USE_ZERO_CRC "
                    "0x%x: zero CRC write failed",
                    l_huid);
            l_errl->setSev(ERRL_SEV_INFORMATIONAL);
            errlCommit(l_errl, CXXTEST_COMP_ID);
        }
        else
        {
            l_errl = SPD::checkCRC(l_target,   // call to detect bad CRC and repair
                                   SPD::CHECK,
                                   EEPROM::VPD_AUTO,
                                   EEPROM::AUTOSELECT,
                                   l_sections);
            if (l_errl)
            {
                // we do not expect an error log here
                TS_FAIL("testCRCforDDR5: TC1_FIRST_TIME_USE_ZERO_CRC "
                        "0x%x: error log is not expected",
                        l_huid);
                l_errl->setSev(ERRL_SEV_INFORMATIONAL);
                errlCommit(l_errl, CXXTEST_COMP_ID);
            }
        }

        //----------------------------------------------------------------------
        // TC2_CORRUPTED_VPD_DATA
        //----------------------------------------------------------------------
        TS_INFO("testCRCforDDR5: TC2_CORRUPTED_VPD_DATA 0x%x", l_huid);
        TS_INFO("testCRCforDDR5: TC2_CORRUPTED_VPD_DATA 0x%x "
                "write a keyword to End_User VPD to corrupt the CRC", l_huid);
        l_buf[0] = getTB()%16; l_buf[1] = l_buf[0]+1; l_buf[2] = l_buf[0]+2;
        l_errl  = DeviceFW::deviceOp(DeviceFW::WRITE,  // corrupt VPD
                                     l_target,
                                     &l_buf,
                                     l_bytes,
                                     DEVICE_EEPROM_ADDRESS(EEPROM::VPD_AUTO,
                                                           l_addr,
                                                           EEPROM::AUTOSELECT));
        if (l_errl)
        {
            TS_FAIL("testCRCforDDR5: TC2_CORRUPTED_VPD_DATA 0x%x: VPD write failed",
                    l_huid);
            l_errl->setSev(ERRL_SEV_INFORMATIONAL);
            errlCommit(l_errl, CXXTEST_COMP_ID);
        }
        else
        {
            l_errl = SPD::checkCRC(l_target,         // call to detect bad CRC,
                                   SPD::CHECK,       // section is bzeroed
                                   EEPROM::VPD_AUTO,
                                   EEPROM::AUTOSELECT,
                                   l_sections);
            if (l_errl)
            {
                TS_FAIL("testCRCforDDR5: TC2_CORRUPTED_VPD_DATA 0x%x: "
                        "error log is not expected",
                        l_huid);
                l_errl->setSev(ERRL_SEV_INFORMATIONAL);
                errlCommit(l_errl, CXXTEST_COMP_ID);
            }
        }
        //----------------------------------------------------------------------
        // TC2 just did a bzero of the section
        //   Write to the VPD so it is non-zero, and the CRC is non-zero
        //----------------------------------------------------------------------
        l_buf[0] = getTB()%16; l_buf[1] = l_buf[0]+1; l_buf[2] = l_buf[0]+2;
        l_addr   = l_keyword->offset;
        l_bytes  = l_keyword->length;
        l_errl   = DeviceFW::deviceOp(DeviceFW::WRITE,  // write some VPD data
                                      l_target,
                                      &l_buf,
                                      l_bytes,
                                      DEVICE_EEPROM_ADDRESS(EEPROM::VPD_AUTO,
                                                            l_addr,
                                                            EEPROM::AUTOSELECT));
        if (l_errl)
        {
            TS_FAIL("testCRCforDDR5: failed writing keyword VPD data on 0x%x",
                    l_huid);
            l_errl->setSev(ERRL_SEV_INFORMATIONAL);
            errlCommit(l_errl, CXXTEST_COMP_ID);
            goto EXIT;
        }
        // The keyword is now non-zero, with good section CRC

        //----------------------------------------------------------------------
        // TC3_KEYWORD_WRITE_UPDATES_CRC
        //----------------------------------------------------------------------
        TS_INFO("testCRCforDDR5: TC3_KEYWORD_WRITE_UPDATES_CRC 0x%x", l_huid);
        TS_INFO("testCRCforDDR5: TC3_KEYWORD_WRITE_UPDATES_CRC 0x%x "
                "write a keyword to End_User VPD, and expect CRC to be updated.", l_huid);
        l_buf[0] = getTB()%16; l_buf[1] = l_buf[0]+1; l_buf[2] = l_buf[0]+2;
        l_bytes = l_keyword->length;
        l_errl  = deviceWrite(l_target,
                              l_buf,
                              l_bytes,
                              DEVICE_SPD_ADDRESS(EXPLORER_FW_VERSION));
        if (l_errl)
        {
            TS_FAIL("testCRCforDDR5: TC3_KEYWORD_WRITE_UPDATES_CRC 0x%x: VPD write failed",
                    l_huid);
            l_errl->setSev(ERRL_SEV_INFORMATIONAL);
            errlCommit(l_errl, CXXTEST_COMP_ID);
        }
        else
        {
            l_errl = SPD::checkCRC(l_target,   // call to ensure good CRC
                                   SPD::CHECK,
                                   EEPROM::VPD_AUTO,
                                   EEPROM::AUTOSELECT,
                                   l_sections);
            if (l_errl)
            {
                TS_FAIL("testCRCforDDR5: TC3_KEYWORD_WRITE_UPDATES_CRC 0x%x: "
                        "error is not expected",
                        l_huid);
                l_errl->setSev(ERRL_SEV_INFORMATIONAL);
                errlCommit(l_errl, CXXTEST_COMP_ID);
            }
        }

        //----------------------------------------------------------------------
        // TC4_CORRUPT_OTHER_CRC
        //----------------------------------------------------------------------
        TS_INFO("testCRCforDDR5: TC4_CORRUPT_OTHER_CRC 0x%x", l_huid);
        l_sections.clear();            // empty the vector
        l_sections.push_back(l_other); // push on the "other" section
        l_other.crcActual = 0xCDBA;    // write bad CRC
        l_errl = updateCRC(l_target, EEPROM::VPD_AUTO, EEPROM::AUTOSELECT, l_other);
        if (l_errl)
        {
            TS_FAIL("testCRCforDDR5: TC4_CORRUPT_OTHER_CRC "
                    "0x%x: corrupt CRC write failed",
                    l_huid);
            l_errl->setSev(ERRL_SEV_INFORMATIONAL);
            errlCommit(l_errl, CXXTEST_COMP_ID);
        }
        else
        {
            l_errl = SPD::checkCRC(l_target,   // call to detect bad CRC
                                   SPD::CHECK,
                                   EEPROM::VPD_AUTO,
                                   EEPROM::AUTOSELECT,
                                   l_sections);
            if (l_errl)
            {
                l_errl->setSev(ERRL_SEV_INFORMATIONAL);
                errlCommit(l_errl, CXXTEST_COMP_ID);
            }
            else
            {
                // we expected an error log here
                TS_FAIL("testCRCforDDR5: TC4_CORRUPT_OTHER_CRC "
                        "0x%x: error log is expected",
                        l_huid);
            }
        }
        l_errl = SPD::checkCRC(l_target,   // call to fix the bad CRC
                               SPD::FIX,
                               EEPROM::VPD_AUTO,
                               EEPROM::AUTOSELECT,
                               l_sections);
        if (l_errl)
        {
            l_errl->setSev(ERRL_SEV_INFORMATIONAL);
            errlCommit(l_errl, CXXTEST_COMP_ID);
        }

      EXIT:
        TRACFCOMP( g_trac_spd, EXIT_MRK"testCRCforDDR5" );
#endif
        return;
    }

        /**
         * @brief This test reads all of the keywords for all of the
         *      DIMMs found.
         */
        void testSpdRead ( void )
        {
            errlHndl_t err = nullptr;
            uint64_t cmds = 0x0;
            uint64_t fails = 0x0;
            uint8_t * theData = nullptr;

            TRACFCOMP( g_trac_spd,
                       ENTER_MRK"testSpdRead() DIMM" );

            do
            {
                TARGETING::Target * theTarget = nullptr;

                // Get DIMM Targets
                TargetHandleList dimmList;
                getDIMMTargets( dimmList );

                if( ( 0 == dimmList.size() ) ||
                    ( nullptr == dimmList[0] ) )
                {
                    TRACFCOMP( g_trac_spd,
                               "testSpdRead - No DIMMs found!" );
                    break;
                }

                // Operate on first DIMM.
                theTarget = dimmList[0];
                size_t theSize = 0;
                bool writeable = false;
                uint32_t entry = 0x0;

                // Get the DDR revision
                uint8_t memType = 0x0;
                err = getMemType( theTarget,
                                  memType );
                if( err )
                {
                    fails++;
                    TS_FAIL("testSpdRead- Failure reading Basic memory type!" );
                    errlCommit( err,
                                VPD_COMP_ID );
                    break;
                }

                // Get the module type.
                modSpecTypes_t modType = NA;
                err = getModType(modType,
                                 theTarget,
                                 memType);
                if( err )
                {
                    fails++;
                    TS_FAIL("testSpdRead- Failure reading memory module type!");
                    errlCommit( err,
                                VPD_COMP_ID );
                    break;
                }


                for( uint64_t keyword = SPD::SPD_FIRST_NORM_KEYWORD;
                     keyword <= SPD::SPD_LAST_NORM_KEYWORD; keyword++ )
                {
                    cmds++;
                    writeable = false;
                    if( nullptr != theData )
                    {
                        free( theData );
                        theData = nullptr;
                    }

                    // Get the required size of the buffer
                    theSize = 0;
                    if( SPD::DDR4_TYPE == memType )
                    {
                        size_t dataSize = (modType == DDIMM)
                            ? (sizeof(ddr4DDIMMData)/sizeof(ddr4DDIMMData[0]))
                            : (sizeof(ddr4Data)/sizeof(ddr4Data[0]));

                        for( entry = 0;
                             entry < dataSize;
                             entry++ )
                        {
                            if (modType == DDIMM)
                            {
                                if( keyword == ddr4DDIMMData[entry].keyword )
                                {
                                    theSize = ddr4DDIMMData[entry].length;
                                    writeable = ddr4DDIMMData[entry].writable;
                                    break;
                                }
                            }
                            else
                            {
                                if( keyword == ddr4Data[entry].keyword )
                                {
                                    theSize = ddr4Data[entry].length;
                                    writeable = ddr4Data[entry].writable;
                                    break;
                                }
                            }
                        }
                    }

                    if( 0 == theSize )
                    {
                        // memType not supported or Keyword not supported on
                        // this memType
                        cmds--;
                        continue;
                    }

                    // Allocate the buffer
                    theData = static_cast<uint8_t*>(calloc( theSize,sizeof(uint8_t) ));

                    err = deviceRead( theTarget,
                                      theData,
                                      theSize,
                                      DEVICE_SPD_ADDRESS( keyword ) );

                    if( err )
                    {
                        fails++;
                        TS_FAIL( "testSpdRead - Failure on keyword: %04x",
                                 keyword );
                        errlCommit( err,
                                    VPD_COMP_ID );
                        continue;
                    }

                    // Read was successful, print out the data read
                    if (theSize == 1)
                    {
                        TRACFCOMP( g_trac_spd,
                                   "testSpdRead - kwd: 0x%04x, val: 0x%02x, size: 1",
                                   keyword, theData[0] );
                    }
                    else if (theSize == 2)
                    {
                        TRACFCOMP( g_trac_spd,
                                   "testSpdRead - kwd: 0x%04x, val: 0x%04x, size: 2",
                                   keyword,
                                   reinterpret_cast<uint16_t *>(theData)[0] );
                    }
                    else if (theSize == 3)
                    {
                        TRACFCOMP( g_trac_spd,
                                   "testSpdRead - kwd: 0x%04x, val: 0x%02x%02x%02x, size: %d",
                                   keyword, theData[0], theData[1], theData[2],
                                   theSize );
                    }
                    else
                    {
                        // For 4 bytes or larger, just print the first 4 bytes
                        TRACFCOMP( g_trac_spd,
                                   "testSpdRead - kwd: 0x%04x, val: 0x%08x, size: %d",
                                   keyword,
                                   reinterpret_cast<uint32_t *>(theData)[0],
                                   theSize );
                    }

                    if (writeable)
                    {
                        // Currently only the following two keywords are writeable
                        // other tests will explicitly do writes to validate these two
                        if ((keyword == SPD::DIMM_BAD_DQ_DATA) ||
                            (keyword == SPD::EXPLORER_FW_VERSION))
                        {
                            TS_INFO( "testspdRead - CONFIRMED PASS on keyword: %04x, "
                                     "NORM keyword table defines as WRITEABLE",
                                     keyword );
                        }
                        else
                        {
                            fails++;
                            TS_FAIL("testspdRead NORM keyword=%04x table defines as "
                                    "WRITEABLE but should only be READABLE", keyword);
                        }

                    }
                    else
                    {
                        // Keyword is -NOT- writeable, so attempt the write which should fail
                        err = deviceWrite( theTarget,
                                           theData,
                                           theSize,
                                           DEVICE_SPD_ADDRESS( keyword ) );
                        if (theData != nullptr)
                        {
                            free( theData );
                            theData = nullptr;
                        }
                        if (err == nullptr)
                        {
                            fails++;
                            TS_FAIL("testspdRead We should have failed writing "
                                    "to a READ ONLY keyword=0x%X", keyword);
                            break;
                        }
                        else
                        {
                            if ( ERRL_GETRC_SAFE(err) != VPD::VPD_KEYWORD_NOT_WRITABLE)
                            {
                                fails++;
                                TS_FAIL("testspdRead BAD RESULT - We DID -NOT- FAIL writing "
                                    "as expected to a READ ONLY keyword=0x%X RC=0x%X", keyword,
                                    ERRL_GETRC_SAFE(err));
                                break;
                            }
                            else
                            {
                                TS_INFO("testspdRead GOOD RESULT - We DID FAIL writing "
                                    "to a READ ONLY keyword=0x%X RC=0x%X", keyword,
                                    ERRL_GETRC_SAFE(err));
                                delete err;
                                err = nullptr;
                            }
                        }
                    }
                } // end for

                if( err )
                {
                    break;
                }
            } while( 0 );

            if( nullptr != theData )
            {
                free( theData );
                theData = nullptr;
            }

            if( cmds == 0 )
            {
                TRACFCOMP(g_trac_spd,
                          "testSpdRead - No tests ran, something is wrong..." );
            }

            TRACFCOMP( g_trac_spd,
                       "testSpdRead - %d/%d fails",
                       fails, cmds );
        }

    /**
     * @brief Test a SPD Write
     */
    void testSpdWriteDQ ( void )
    {
        errlHndl_t err        = nullptr;
        uint8_t   *testData   = nullptr;
        uint8_t   *origData   = nullptr;
        uint8_t   *verifyData = nullptr;

        // 1. read the DIMM_BAD_DQ_DATA into an orig buffer to save for the restore
        // 2. write,read,verify test data
        // 3. write,read,verify the orig data

        TS_INFO("testSpdWriteDQ Entry");

        do
        {

        TARGETING::Target * theTarget = nullptr;

        // Get DIMM Targets
        TargetHandleList dimmList;
        getDIMMTargets( dimmList );

        TS_INFO( "testSpdWriteDQ dimmList.size()=%d", dimmList.size() );
        if( ( 0 == dimmList.size() ) ||
            ( nullptr == dimmList[0] ) )
        {
            TS_FAIL("testSpdWriteDQ - No DIMMs found! Why not?");
            break;
        }

        // Operate on first DIMM
        theTarget = dimmList[0];
        uint16_t theKeyword{};
        size_t   theSize{};
        size_t   theOffset{};

        // Get Memory Type
        uint8_t memType = 0x0;
        err = getMemType( theTarget, memType );
        if (err)
        {
            TS_FAIL( "testSpdWriteDQ - failed to read memtype" );
            errlCommit( err, VPD_COMP_ID );
            break;
        }

        if (memType == SPD::DDR5_TYPE)
        {
            TS_INFO( "testSpdWriteDQ - running DDR5_TYPE" );
        }
        else if ( SPD::DDR4_TYPE != memType )
        {
            TS_FAIL( "testSpdWriteDQ - Unsupported memory type: 0x%04X", memType );
            errlCommit( err, VPD_COMP_ID);
            break;
        }

        // Get the module type.
        modSpecTypes_t modType = NA;
        err = getModType(modType,
                         theTarget,
                         memType);
        if (err)
        {
            TS_FAIL("testSpdRead- Failure reading memory module type");
            errlCommit( err, VPD_COMP_ID );
            break;
        }

        auto l_keyword = DIMM_BAD_DQ_DATA;

        if (memType == SPD::DDR5_TYPE)
        {
            // DDR5 has a different keyword name
            l_keyword = DIMM_BAD_DQ_DATA_0;
        }

        const KeywordData *l_entry{nullptr};
        err = getKeywordEntry( l_keyword,
                               memType,
                               theTarget,
                               l_entry );
        if (err)
        {
            TS_FAIL("testSpdWriteDQ - getKeywordEntry error for DIMM_BAD_DQ_DATA");
            errlCommit(err, VPD_COMP_ID);
            break;
        }

        theKeyword = l_entry->keyword;
        theOffset  = l_entry->offset;
        theSize    = l_entry->length;

        if (0 == theSize)
        {
            // memType or Keyword not supported
            TS_INFO("testSpdWriteDQ memType or Keyword not supported");
            break;
        }

        // Allocate data buffers
        origData   = static_cast<uint8_t*>(calloc( theSize,sizeof(uint8_t) ));
        testData   = static_cast<uint8_t*>(calloc( theSize,sizeof(uint8_t) ));
        verifyData = static_cast<uint8_t*>(calloc( theSize,sizeof(uint8_t) ));

        //----------------------------------------------------------------------
        // 1. read,verify ORIGINAL data, EEPROM vs SPD
        //----------------------------------------------------------------------

        TS_INFO( "testSpdWriteDQ_TC1: Read the ORIG data via EEPROM ADDR" );
        err = DeviceFW::deviceOp( DeviceFW::READ,
                                  theTarget,
                                  origData,
                                  theSize,
                                  DEVICE_EEPROM_ADDRESS(EEPROM::VPD_AUTO,
                                                        theOffset,
                                                        EEPROM::HARDWARE));
        if (err)
        {
            TS_FAIL("testSpdWriteDQ_TC1: Error reading EEPROM ADDR DIMM BAD DQ ORIGINAL DATA");
            errlCommit( err, VPD_COMP_ID );
            break;
        }

        TRACFBIN( g_trac_spd, "DIMM BAD DQ ORIGINAL DATA read=",
                              origData, theSize );

        TS_INFO( "testSpdWriteDQ_TC1: Read the ORIG data via SPD ADDR" );
        memset(verifyData,0,theSize);
        err = deviceRead( theTarget,
                          verifyData,
                          theSize,
                          DEVICE_SPD_ADDRESS(theKeyword) );
        if (err)
        {
            TS_FAIL("testSpdWriteDQ_TC1: Error reading SPD ADDR DIMM BAD DQ ORIGINAL DATA");
            errlCommit( err, VPD_COMP_ID );
            break;
        }

        if (memcmp( origData, verifyData, theSize))
        {
            TS_FAIL( "testSpdWriteDQ_TC1: SPD ADDR DIMM BAD DQ ORIGINAL DATA mismatch" );
            TRACFBIN( g_trac_spd, "DIMM BAD DQ ORIG DATA: MISMATCH wrote=", origData, theSize );
            TRACFBIN( g_trac_spd, "DIMM BAD DQ ORIG DATA: MISMATCH read=", verifyData, theSize );
            break;
        }
        else
        {
            TS_INFO( "testSpdWriteDQ_TC1: SUCCESS - read SPD ADDR ORIG data" );
            TRACFBIN( g_trac_spd, "DIMM BAD DQ ORIGINAL DATA", origData, theSize );
        }

        //----------------------------------------------------------------------
        // 2. write,read,verify TEST data
        //----------------------------------------------------------------------

        for ( size_t x=0; x<theSize; x++ ) // fill buffer with TEST data
        {
            testData[x] = x;
        }
        TRACFBIN( g_trac_spd, "DIMM BAD DQ TEST DATA =", testData, theSize );

        TS_INFO( "testSpdWriteDQ_TC2: Write the TEST data via SPD ADDR");
        err = DeviceFW::deviceOp(DeviceFW::WRITE,
                                 theTarget,
                                 testData,
                                 theSize,
                                 DEVICE_SPD_ADDRESS(theKeyword));
        if (err)
        {
            TS_FAIL( "testSpdWriteDQ_TC2: Error writing SPD ADDR DIMM BAD DQ TEST DATA" );
            errlCommit( err, VPD_COMP_ID );
            break;
        }

        TS_INFO( "testSpdWriteDQ_TC2: Read the TEST data via SPD ADDR to check it" );
        memset(verifyData,0,theSize);
        err = deviceRead( theTarget,
                          verifyData,
                          theSize,
                          DEVICE_SPD_ADDRESS(theKeyword));
        if (err)
        {
            TS_FAIL( "testSpdWriteDQ_TC2: Error reading SPD ADDR DIMM BAD DQ TEST DATA" );
            errlCommit( err, VPD_COMP_ID );
            break;
        }

        if (memcmp( testData, verifyData, theSize))
        {
            TS_FAIL( "testSpdWriteDQ_TC2: SPD ADDR DIMM BAD DQ TEST DATA mismatch" );
            TRACFBIN( g_trac_spd, "DIMM BAD DQ TEST DATA: MISMATCH wrote=", testData, theSize );
            TRACFBIN( g_trac_spd, "DIMM BAD DQ TEST DATA: MISMATCH read=", verifyData, theSize );
            break;
        }

        TS_INFO( "testSpdWriteDQ_TC2: Read the TEST data via EEPROM ADDR to check it" );
        memset(verifyData,0,theSize);
        err = DeviceFW::deviceOp( DeviceFW::READ,
                                  theTarget,
                                  verifyData,
                                  theSize,
                                  DEVICE_EEPROM_ADDRESS(EEPROM::VPD_AUTO,
                                                        theOffset,
                                                        EEPROM::HARDWARE));
        if (err)
        {
            TS_FAIL("testSpdWriteDQ_TC2: Error reading EEPROM ADDR DIMM BAD DQ TEST DATA");
            errlCommit(err, VPD_COMP_ID);
            break;
        }

        if (memcmp( testData, verifyData, theSize))
        {
            TS_FAIL( "testSpdWriteDQ_TC2: EEPROM ADDR DIMM BAD DQ TEST DATA mismatch" );
            TRACFBIN( g_trac_spd, "DIMM BAD DQ TEST DATA: MISMATCH wrote=", testData, theSize );
            TRACFBIN( g_trac_spd, "DIMM BAD DQ TEST DATA: MISMATCH read=", verifyData, theSize );
            break;
        }
        else
        {
            TS_INFO( "testSpdWriteDQ_TC2: SUCCESS - write SPD ADDR TEST data" );
        }

        //----------------------------------------------------------------------
        // 3. write,read,verify ORIGINAL data
        //----------------------------------------------------------------------

        TS_INFO( "testSpdWriteDQ_TC3: Write DIMM BAD DQ ORIGINAL DATA to restore it" );
        err = DeviceFW::deviceOp(DeviceFW::WRITE,
                                 theTarget,
                                 origData,
                                 theSize,
                                 DEVICE_SPD_ADDRESS(theKeyword));
        if (err)
        {
            TS_FAIL("testSpdWriteDQ_TC3: Error restoring SPD ADDR DIMM BAD DQ "
                    "ORIGINAL DATA, VPD may be corrupted");
            errlCommit( err, VPD_COMP_ID );
            break;
        }

        TS_INFO( "testSpdWriteDQ_TC3: Read the ORIGINAL data via SPD ADDR to check it" );
        memset(verifyData,0,theSize);
        err = deviceRead(theTarget,
                         verifyData,
                         theSize,
                         DEVICE_SPD_ADDRESS(theKeyword));
        if (err)
        {
            TS_FAIL( "testSpdWriteDQ_TC3: Error reading SPD ADDR DIMM BAD DQ ORIGINAL DATA" );
            errlCommit( err, VPD_COMP_ID );
            break;
        }

        if (memcmp(origData, verifyData, theSize))
        {
            TS_FAIL( "testSpdWriteDQ_TC3: SPD ADDR DIMM BAD DQ ORIGINAL DATA mismatch" );
            TRACFBIN( g_trac_spd, "DIMM BAD DQ ORIGINAL DATA: MISMATCH wrote=", origData, theSize );
            TRACFBIN( g_trac_spd, "DIMM BAD DQ ORIGINAL DATA: MISMATCH read=", verifyData, theSize );
            break;
        }

        TS_INFO( "testSpdWriteDQ_TC3: Read the ORIGINAL data via EEPROM ADDR to check it" );
        memset(verifyData,0,theSize);
        err = DeviceFW::deviceOp(DeviceFW::READ,
                                 theTarget,
                                 verifyData,
                                 theSize,
                                 DEVICE_EEPROM_ADDRESS(EEPROM::VPD_AUTO,
                                                       theOffset,
                                                       EEPROM::HARDWARE));
        if (err)
        {
            TS_FAIL( "testSpdWriteDQ_TC3: Error reading EEPROM ADDR DIMM BAD DQ ORIGINAL DATA" );
            errlCommit( err, VPD_COMP_ID );
            break;
        }

        if (memcmp(origData, verifyData, theSize))
        {
            TS_FAIL( "testSpdWriteDQ_TC3: EEPROM ADDR DIMM BAD DQ ORIGINAL DATA mismatch" );
            TRACFBIN( g_trac_spd, "DIMM BAD DQ ORIGINAL DATA MISMATCH wrote=", origData, theSize );
            TRACFBIN( g_trac_spd, "DIMM BAD DQ ORIGINAL DATA MISMATCH read=", verifyData, theSize );
            break;
        }
        else
        {
            TS_INFO( "testSpdWriteDQ_TC3: SUCCESS - restore SPD ADDR ORIG data" );
        }

        } while( 0 );

        if (nullptr != origData)   {free(origData);}
        if (nullptr != testData)   {free(testData);}
        if (nullptr != verifyData) {free(verifyData);}

        TS_INFO("testSpdWriteDQ Exit");
    }

        /**
         * @brief Test a SPD Write EXPLORER_FW_VERSION
         */
        void testSpdWriteFW ( void )
        {
            errlHndl_t err = nullptr;
            uint64_t cmds = 0x0;
            uint64_t fails = 0x0;
            uint8_t * testData = nullptr;
            uint8_t * origData = nullptr;
            uint8_t * verifyData = nullptr;

            TS_INFO("testSpdWriteFW Entry");

            do
            {
                TARGETING::Target * theTarget = nullptr;

                // Get DIMM Targets
                TargetHandleList dimmList;
                getDIMMTargets( dimmList );

                TS_INFO( "testSpdWriteFW dimmList.size()=%d", dimmList.size() );
                if( ( 0 == dimmList.size() ) ||
                    ( nullptr == dimmList[0] ) )
                {
                    TS_FAIL("testSpdWriteFW - No DIMMs found! Why not?");
                    break;
                }

                // Operate on first DIMM
                cmds++;
                theTarget = dimmList[0];
                size_t theSize = 0;

                // Get Memory Type
                uint8_t memType = 0x0;
                err = getMemType( theTarget,
                                  memType );

                if( err )
                {
                    fails++;
                    TS_FAIL( "testSpdWriteFW - failed to read memtype!" );
                    errlCommit( err,
                                VPD_COMP_ID );
                    break;
                }

                // Get the module type.
                modSpecTypes_t modType = NA;
                err = getModType(modType,
                                 theTarget,
                                 memType);
                if( err )
                {
                    fails++;
                    TS_FAIL("testSpdWriteFW- Failure reading memory module type!");
                    errlCommit( err,
                                VPD_COMP_ID );
                    break;
                }

                // Get the size
                if( SPD::DDR4_TYPE == memType )
                {
                    size_t dataSize = (modType == DDIMM)
                        ? (sizeof(ddr4DDIMMData)/sizeof(ddr4DDIMMData[0]))
                        : (sizeof(ddr4Data)/sizeof(ddr4Data[0]));

                    for( uint32_t entry = 0;
                         entry < dataSize;
                         entry++ )
                    {
                        if (modType == DDIMM)
                        {
                            if( SPD::EXPLORER_FW_VERSION == ddr4DDIMMData[entry].keyword )
                            {
                                theSize = ddr4DDIMMData[entry].length;
                                break;
                            }
                        }
                        else
                        {
                            if( SPD::EXPLORER_FW_VERSION == ddr4Data[entry].keyword )
                            {
                                theSize = ddr4Data[entry].length;
                                break;
                            }
                        }
                    }
                }
                else if(SPD::DDR5_TYPE == memType)
                {
                    size_t dataSize = sizeof(ddr5DDIMMData)/sizeof(ddr5DDIMMData[0]);

                    for(uint32_t entry = 0; entry < dataSize; entry++)
                    {
                        // DDR5 VPD also contains the EXPLORER_FW_VERSION keyword, so
                        // use it here for DDR5 testing.
                        if(SPD::EXPLORER_FW_VERSION == ddr5DDIMMData[entry].keyword)
                        {
                            theSize = ddr5DDIMMData[entry].length;
                            break;
                        }
                    }
                }
                else
                {
                    fails++;
                    TS_FAIL( "testSpdWriteFW - Unsupported memory type: 0x%04x", memType );
                    errlCommit( err, VPD_COMP_ID);
                    break;
                }

                if( 0 == theSize )
                {
                    // memType or Keyword not supported
                    TS_INFO("testSpdWriteFW memType Keyword not supported, but we tried...");
                    cmds++;
                    break;
                }

                // Allocate data buffer
                origData = static_cast<uint8_t*>(calloc( theSize,sizeof(uint8_t) ));

                // Read the data out first
                err = deviceRead( theTarget,
                                  origData,
                                  theSize,
                                  DEVICE_SPD_ADDRESS( EXPLORER_FW_VERSION ) );
                TRACFBIN( g_trac_spd, "testSpdWriteFW ORIGINAL EXPLORER_FW_VERSION read=",
                            origData, theSize );

                if( err )
                {
                    fails++;
                    TS_FAIL( "testSpdWriteFW - failed to read ORIGINAL EXPLORER_FW_VERSION!" );
                    errlCommit( err,
                                VPD_COMP_ID );
                    break;
                }

                // fill it up with some dummy data
                testData = static_cast<uint8_t*>(calloc( theSize,sizeof(uint8_t) ));
                for( size_t x=0; x<theSize; x++ )
                {
                    testData[x] = x;
                }

                // Write the test data in
                err = deviceWrite( theTarget,
                                   testData,
                                   theSize,
                                   DEVICE_SPD_ADDRESS( EXPLORER_FW_VERSION ) );

                if( err )
                {
                    fails++;
                    TS_FAIL( "testSpdWriteFW - Error writing data to EXPLORER_FW_VERSION" );
                    break;
                }

                // Read the data out again to check it
                verifyData = static_cast<uint8_t*>(calloc( theSize,sizeof(uint8_t) ));
                err = deviceRead( theTarget,
                                  verifyData,
                                  theSize,
                                  DEVICE_SPD_ADDRESS( EXPLORER_FW_VERSION ) );
                TRACFBIN( g_trac_spd, "testSpdWriteFW TEST DATA EXPLORER_FW_VERSION data read=",
                            verifyData, theSize );

                if( err )
                {
                    fails++;
                    TS_FAIL( "testSpdWriteFW - failed to read TEST DATA for EXPLORER_FW_VERSION!" );
                    errlCommit( err,
                                VPD_COMP_ID );
                    break;
                }

                if( memcmp( testData, verifyData, theSize ) )
                {
                    fails++;
                    TS_FAIL( "testSpdWriteFW - PROBLEM DIMM EXPLORER_FW_VERSION "
                             "data does not match what we wrote!" );
                    TRACFBIN( g_trac_spd, "PROBLEM EXPLORER_FW_VERSION MISMATCH wrote=",
                                testData, theSize );
                    TRACFBIN( g_trac_spd, "PROBLEM EXPLORER_FW_VERSION MISMATCH read=",
                                verifyData, theSize );
                }
                else
                {
                    TS_INFO( "testSpdWriteFW - CONFIRMED DIMM EXPLORER_FW_VERSION "
                             "data written successfully!" );
                    TRACFBIN( g_trac_spd, "CONFIRMED EXPLORER_FW_VERSION wrote=",
                                testData, theSize );
                    TRACFBIN( g_trac_spd, "CONFIRMED EXPLORER_FW_VERSION read=",
                                verifyData, theSize );
                }

                // put the original data back to be a good citizen
                err = deviceWrite( theTarget,
                                   origData,
                                   theSize,
                                   DEVICE_SPD_ADDRESS( EXPLORER_FW_VERSION ) );
                TS_INFO( "testSpdWriteFW - deviceWrite Restoring ORIGINAL "
                         "DIMM EXPLORER_FW_VERSION" );

                if( err )
                {
                    fails++;
                    TS_FAIL( "testSpdWriteFW - Error writing original data back to "
                             "DIMM EXPLORER_FW_VERSION data, things may be corrupted!");
                    break;
                }
                else
                {
                    TS_INFO("testSpdWriteFW - Successfully restored original "
                            "DIMM EXPLORER_FW_VERSION theSize=0x%X", theSize);
                }


            } while( 0 );

            if( nullptr != testData )
            {
                free( testData );
                testData = nullptr;
            }

            if( nullptr != origData )
            {
                free( origData );
                origData = nullptr;
            }

            if( nullptr != verifyData )
            {
                free( verifyData );
                verifyData = nullptr;
            }

            if( cmds == 0 )
            {
                TS_FAIL("testSpdWriteFW - No tests ran, something is wrong...");
            }

            TS_INFO("testSpdWriteFW Exit - %d/%d fails", fails, cmds);
        }

        /**
         * @brief Test a SPD Write to a value that is less than 1 byte
         *
         * Note - There are no writable keywords that fit this criteria
         *   so this test is disabled by default.  To enable, modify the
         *   table in spdDDR3.H to make something writable.
         */
        void _testSpdWriteSmall ( void )
        {
#ifndef __HOSTBOOT_RUNTIME
            errlHndl_t err = nullptr;
            uint64_t cmds = 0x0;
            uint64_t fails = 0x0;
            uint8_t* testData = nullptr;
            uint8_t* origData = nullptr;

            TRACFCOMP( g_trac_spd,
                       ENTER_MRK"testSpdWriteSmall()" );

            do
            {
                TARGETING::Target * theTarget = nullptr;

                // Get DIMM Targets
                TargetHandleList dimmList;
                getDIMMTargets( dimmList );

                if( ( 0 == dimmList.size() ) ||
                    ( nullptr == dimmList[0] ) )
                {
                    TRACFCOMP( g_trac_spd,
                               "testSpdWriteSmall - No DIMMs found!" );
                    break;
                }

                // Operate on first DIMM
                cmds++;
                theTarget = dimmList[0];

                // Get Memory Type
                uint8_t memType = 0x0;
                err = getMemType( theTarget,
                                  memType );
                if( err )
                {
                    fails++;
                    TS_FAIL( "testSpdWriteSmall - failed to read memtype!" );
                    errlCommit( err,
                                VPD_COMP_ID );
                    break;
                }

                // Get the size
                size_t theSize = 0;
                uint16_t theKeyword = INVALID_SPD_KEYWORD;
                if( SPD::DDR3_TYPE == memType )
                {
                    for( uint32_t entry = 0;
                         entry < (sizeof(ddr3Data)/sizeof(ddr3Data[0]));
                         entry++ )
                    {
                        if( ddr3Data[entry].writable
                            && ddr3Data[entry].bitMask )
                        {
                            theSize = ddr3Data[entry].length;
                            theKeyword = ddr3Data[entry].keyword;
                            TRACFCOMP( g_trac_spd,
                                       "testSpdWriteSmall - Using DDR3 keyword 0x%04x",
                                       theKeyword );
                            break;
                        }
                    }
                }
                else if( SPD::DDR4_TYPE == memType )
                {
                    for( uint32_t entry = 0;
                         entry < (sizeof(ddr4Data)/sizeof(ddr4Data[0]));
                         entry++ )
                    {
                        if( ddr4Data[entry].writable
                            && ddr4Data[entry].bitMask )
                        {
                            theSize = ddr4Data[entry].length;
                            theKeyword = ddr4Data[entry].keyword;
                            TRACFCOMP( g_trac_spd,
                                       "testSpdWriteSmall - Using DDR4 keyword 0x%04x",
                                       theKeyword );
                            break;
                        }
                    }
                }
                else
                {
                    fails++;
                    TRACFCOMP( g_trac_spd,
                               "testSpdWriteSmall - memory type: 0x%04x",
                               memType );
                    TS_FAIL( "testSpdWriteSmall - Unsupported Memory Type!" );
                    errlCommit( err,
                                VPD_COMP_ID );
                    break;
                }

                cmds++;
                if( theKeyword == INVALID_SPD_KEYWORD )
                {
                    fails++;
                    TS_FAIL( "testSpdWriteSmall - Could not find a keyword to work with!" );
                    break;
                }

                // Read the data out
                cmds++;
                origData = new uint8_t[theSize];
                err = deviceRead( theTarget,
                                  origData,
                                  theSize,
                                  DEVICE_SPD_ADDRESS( theKeyword ) );
                if( err )
                {
                    fails++;
                    TS_FAIL( "testSpdWriteSmall - failed to read keyword!" );
                    errlCommit( err,
                                VPD_COMP_ID );
                    break;
                }

                // fill test array up with some dummy data
                testData = new uint8_t[theSize];
                for( size_t x=0; x<theSize; x++ )
                {
                    testData[x] = 0x55;
                }

                // Write the test data
                cmds++;
                err = deviceWrite( theTarget,
                                   testData,
                                   theSize,
                                   DEVICE_SPD_ADDRESS( theKeyword ) );
                if( !err )
                {
                    fails++;
                    TS_FAIL( "testSpdWriteSmall - Did not get expected error writing data" );

                    // Put the original data back to be a good citizen
                    cmds++;
                    err = deviceWrite( theTarget,
                                       origData,
                                       theSize,
                                       DEVICE_SPD_ADDRESS( theKeyword ) );
                    if( err )
                    {
                        fails++;
                        TS_FAIL( "testSpdWriteSmall - Error writing original data back" );
                    }

                    break;
                }
                else
                {
                    cmds++;
                    if( err->reasonCode() != VPD::VPD_UNSUPPORTED_WRITE )
                    {
                        fails++;
                        TRACFCOMP( g_trac_spd,
                                   "testSpdWriteSmall - RC from write = 0x%04x",
                                   err->reasonCode() );
                        TS_FAIL( "testSpdWriteSmall - Did not get VPD_UNSUPPORTED_WRITE error writing data" );
                    }

                    delete err;
                }

            } while( 0 );

            if( nullptr != testData )
            {
                delete[] testData;
                testData = nullptr;
            }

            if( nullptr != origData )
            {
                delete[] origData;
                origData = nullptr;
            }

            if( cmds == 0 )
            {
                TS_FAIL( "testSpdWriteSmall - No tests ran, something is wrong..." );
            }

            TRACFCOMP( g_trac_spd,
                       "testSpdWriteSmall - %d/%d fails",
                       fails, cmds );
#endif  // #ifndef __HOSTBOOT_RUNTIME
        }
        /**
         * @brief Test an invalid Keyword to a DIMM target.
         */
        void testSpdInvalidKeyword ( void )
        {
            errlHndl_t err = nullptr;
            uint64_t cmds = 0x0;
            uint64_t fails = 0x0;

            TRACFCOMP( g_trac_spd,
                       ENTER_MRK"testSpdInvalidKeyword()" );

            do
            {
                TARGETING::Target * theTarget = nullptr;

                // Get DIMM Targets
                TargetHandleList dimmList;
                getDIMMTargets( dimmList );

                if( ( 0 == dimmList.size() ) ||
                    ( nullptr == dimmList[0] ) )
                {
                    TRACFCOMP( g_trac_spd,
                               "testSpdInvalidKeyword - No DIMMs found!" );
                    break;
                }

                // Test on first DIMM only.
                theTarget = dimmList[0];
                uint8_t * theData = nullptr;
                size_t theSize = 0x0;

                cmds++;
                err = deviceRead( theTarget,
                                  theData,
                                  theSize,
                                  DEVICE_SPD_ADDRESS( SPD::INVALID_SPD_KEYWORD ) );

                if( nullptr == err )
                {
                    fails++;
                    TS_FAIL( "testSpdInvalidKeyword - No error returned!" );
                    break;
                }
                else
                {
                    delete err;
                    err = nullptr;
                }
            } while( 0 );

            TRACFCOMP( g_trac_spd,
                       "testSpdInvalidKeyword - %d/%d fails",
                       fails, cmds );
        }

        /**
         * @brief Test an invalid size for an SPD read.
         */
        void testSpdInvalidSize ( void )
        {
            errlHndl_t err = nullptr;
            uint64_t cmds = 0x0;
            uint64_t fails = 0x0;

            TRACFCOMP( g_trac_spd,
                       ENTER_MRK"testSpdInvalidSize()" );

            do
            {
                TARGETING::Target * theTarget = nullptr;

                // Get DIMM Targets
                TargetHandleList dimmList;
                getDIMMTargets( dimmList );

                if( ( 0 == dimmList.size() ) ||
                    ( nullptr == dimmList[0] ) )
                {
                    TRACFCOMP( g_trac_spd,
                               "testSpdInvalidSize - No DIMMs found!" );
                    break;
                }

                // Test on first DIMM only.
                theTarget = dimmList[0];
                //If theData is nullptr, deviceRead will return the size
                // need to give this an arbitrary size so test is still valid
                uint8_t * theData = static_cast<uint8_t*>(calloc( 1,sizeof(uint8_t) ));
                size_t theSize = 0x0;   // Invalid size of 0x0

                cmds++;
                err = deviceRead( theTarget,
                                  theData,
                                  theSize,
                                  DEVICE_SPD_ADDRESS( SPD::SPD_FIRST_NORM_KEYWORD ) );

                // clean up the data
                if( nullptr != theData )
                {
                    free( theData );
                    theData = nullptr;
                }
                if( nullptr == err )
                {
                    fails++;
                    TS_FAIL( "testSpdInvalidSize - No error for invalid size!" );
                    break;
                }
                else
                {
                    delete err;
                    err = nullptr;
                }
            } while( 0 );

            TRACFCOMP( g_trac_spd,
                       "testSpdInvalidSize - %d/%d fails",
                       fails, cmds );
        }

        /**
         */
        void testSpdInvalidWrite ( void )
        {
#ifndef __HOSTBOOT_RUNTIME
            errlHndl_t err = nullptr;
            uint64_t cmds = 0x0;
            uint64_t fails = 0x0;

            TRACFCOMP( g_trac_spd,
                       ENTER_MRK"testSpdInvalidWrite()" );

            do
            {
                TARGETING::Target * theTarget = nullptr;

                // Get DIMM Targets
                TargetHandleList dimmList;
                getDIMMTargets( dimmList );

                if( ( 0 == dimmList.size() ) ||
                    ( nullptr == dimmList[0] ) )
                {
                    TRACFCOMP( g_trac_spd,
                               "testSpdInvalidSize - No DIMMs found!" );
                    break;
                }

                // Test on first DIMM only.
                theTarget = dimmList[0];
                size_t theSize = 0x10;
                uint8_t * theData = static_cast<uint8_t*>(calloc( theSize,sizeof(uint8_t) ));

                cmds++;
                // This fails since SPD_FIRST_NORM_KEYWORD is not writable
                err = deviceWrite( theTarget,
                                   theData,
                                   theSize,
                                   DEVICE_SPD_ADDRESS( SPD::SPD_FIRST_NORM_KEYWORD ) );

                // clean up the data
                if( nullptr != theData )
                {
                    free( theData );
                    theData = nullptr;
                }

                if( nullptr == err )
                {
                    fails++;
                    TS_FAIL( "No failure for Invalid Write attempt to "
                             "SPD_FIRST_NORM_KEYWORD" );
                    break;
                }
                else
                {
                    delete err;
                    err = nullptr;
                }
            } while( 0 );

            TRACFCOMP( g_trac_spd,
                       "testSpdInvalidWrite - %d/%d fails",
                       fails, cmds );
#endif  // #ifndef __HOSTBOOT_RUNTIME
        }

        /**
         * @brief This test will test reading the Module specific keywords.
         */
        void testspdModSpecKwds( void )
        {
            errlHndl_t err = nullptr;
            uint64_t cmds = 0x0;
            uint64_t fails = 0x0;
            uint8_t memType = 0x0;
            uint8_t * theData = nullptr;

            TRACFCOMP( g_trac_spd,
                       ENTER_MRK"testspdModSpecKwds()" );

            do
            {
                TARGETING::Target * theTarget = nullptr;

                // Get DIMM Targets
                TargetHandleList dimmList;
                getDIMMTargets( dimmList );

                if( ( 0 == dimmList.size() ) ||
                    ( nullptr == dimmList[0] ) )
                {
                    TRACFCOMP( g_trac_spd,
                               "testspdModSpecKwds - No DIMMs found!" );
                    break;
                }

                // Operate on first DIMM.
                theTarget = dimmList[0];
                size_t theSize = 0;
                bool writeable = false;
                uint32_t entry = 0x0;

                // Get the DDR revision
                size_t tmpSize = 0x1;
                TS_INFO("testspdModSpecKwds WORKING on FIRST DIMM HUID=0x%X",
                        TARGETING::get_huid(theTarget));
                err = deviceRead( theTarget,
                                  &memType,
                                  tmpSize,
                                  DEVICE_SPD_ADDRESS( SPD::BASIC_MEMORY_TYPE ) );

                if( err )
                {
                    fails++;
                    TS_FAIL( "testspdModSpecKwds- Failure reading Basic "
                             "memory type!" );
                    errlCommit( err,
                                VPD_COMP_ID );
                    break;
                }

                // Get the module type.
                modSpecTypes_t modType = NA;
                err = getModType(modType,
                                 theTarget,
                                 memType);
                if( err )
                {
                    fails++;
                    TS_FAIL("testSpdRead- Failure reading memory module type!");
                    errlCommit( err,
                                VPD_COMP_ID );
                    break;
                }

                // The real Keyword read testing
                for( uint64_t keyword = SPD::SPD_FIRST_MOD_SPEC;
                     keyword <= SPD::SPD_LAST_MOD_SPEC; keyword++ )
                {
                    cmds++;
                    // Keep track of writeable to check later
                    writeable = false;
                    if( nullptr != theData )
                    {
                        free( theData );
                        theData = nullptr;
                    }

                    // Get the required size of the buffer
                    theSize = 0;
                    KeywordData kwdData;
                    if( SPD::DDR4_TYPE == memType )
                    {
                        size_t dataSize = (modType == DDIMM)
                            ? (sizeof(ddr4DDIMMData)/sizeof(ddr4DDIMMData[0]))
                            : (sizeof(ddr4Data)/sizeof(ddr4Data[0]));

                        for( entry = 0;
                             entry < dataSize;
                             entry++ )
                        {
                            if (modType == DDIMM)
                            {
                                if( keyword == ddr4DDIMMData[entry].keyword )
                                {
                                    kwdData = ddr4DDIMMData[entry];
                                    theSize = ddr4DDIMMData[entry].length;
                                    writeable = ddr4DDIMMData[entry].writable;
                                    break;
                                }
                            }
                            else
                            {
                                if( keyword == ddr4Data[entry].keyword )
                                {
                                    kwdData = ddr4Data[entry];
                                    theSize = ddr4Data[entry].length;
                                    writeable = ddr4Data[entry].writable;
                                    break;
                                }
                            }
                        }
                    }

                    if( 0 == theSize )
                    {
                        // memType not supported or Keyword not supported on
                        // this memType
                        cmds--;
                        continue;
                    }

                    // Check that the module type supports this keyword
                    TS_INFO("SPD Error traces MAY follow!!!  "
                               "Not all module specific keywords will be "
                               "valid for all types of modules.  IGNORE!!" );
                    err = checkModSpecificKeyword( kwdData,
                                                   memType,
                                                   theTarget );
                    if( err )
                    {
                        // This keyword isn't supported with this module type
                        cmds--;
                        delete err;
                        err = nullptr;
                        continue;
                    }

                    // Allocate the buffer
                    theData = static_cast<uint8_t*>(calloc( theSize,sizeof(uint8_t) ));
                    err = deviceRead( theTarget,
                                      theData,
                                      theSize,
                                      DEVICE_SPD_ADDRESS( keyword ) );

                    if( err )
                    {
                        fails++;
                        TS_FAIL( "testspdModSpecKwds - Failure on keyword: %04x",
                                 keyword );
                        errlCommit( err,
                                    VPD_COMP_ID );
                        continue;
                    }

                    // Read was successful, print out the data read
                    if (theSize == 1)
                    {
                        TRACFCOMP( g_trac_spd,
                                   "testspdModSpecKwds - kwd: 0x%04x, val: 0x%02x, size: 1",
                                   keyword, theData[0] );
                    }
                    else if (theSize == 2)
                    {
                        TRACFCOMP( g_trac_spd,
                                   "testspdModSpecKwds - kwd: 0x%04x, val: 0x%04x, size: 2",
                                   keyword,
                                   reinterpret_cast<uint16_t *>(theData)[0] );
                    }
                    else if (theSize == 3)
                    {
                        TRACFCOMP( g_trac_spd,
                                   "testspdModSpecKwds - kwd: 0x%04x, val: 0x%02x%02x%02x, size: %d",
                                   keyword, theData[0], theData[1], theData[2],
                                   theSize );
                    }
                    else
                    {
                        // For 4 bytes or larger, just print the first 4 bytes
                        TRACFCOMP( g_trac_spd,
                                   "testspdModSpecKwds - kwd: 0x%04x, val: 0x%08x, size: %d",
                                   keyword,
                                   reinterpret_cast<uint32_t *>(theData)[0],
                                   theSize );
                    }

                    if( nullptr != theData )
                    {
                        free( theData );
                        theData = nullptr;
                    }
                    // At this time only ONE MOD SPEC Keyword is WRITEABLE
                    // so fail if keyword is something not expected as WRITEABLE
                    if (writeable)
                    {
                        if (keyword != SPD::EXPLORER_FW_VERSION)
                        {
                            fails++;
                            TS_FAIL("testspdModSpecKwds MOD SPEC keyword=%04x table defines "
                                    "as WRITEABLE but should only be READABLE", keyword);
                        }
                    }
                }
            } while( 0 );

            if( nullptr != theData )
            {
                free( theData );
                theData = nullptr;
            }

            TRACFCOMP( g_trac_spd,
                       "testspdModSpecKwds - %d/%d fails",
                       fails, cmds );
        }


        /**
         * @brief This test will ensure that the DDR3 lookup table is in a sorted
         *      order, according to the keyword enumeration, to enable the search
         *      algorithm to work correctly.
         */
        void testspdDDR3TableOrder ( void )
        {
            uint64_t prevKeyword = 0x0;
            uint64_t fails = 0x0;

            TRACFCOMP( g_trac_spd, ENTER_MRK"testspdDDR3TableOrder()" );

            for( uint32_t entry = 0;
                 entry < (sizeof(ddr3Data)/sizeof(ddr3Data[0]));
                 entry++ )
            {
                if( !(ddr3Data[entry].keyword >= prevKeyword) )
                {
                    fails++;
                    TS_FAIL( "testspdDDR3TableOrder - DDR3 table out of order! Cur kwd: "
                             "0x%04X, Pre kwd: 0x%04X",
                             ddr3Data[entry].keyword,
                             prevKeyword );
                }
                prevKeyword = ddr3Data[entry].keyword;
            }

            TRACFCOMP( g_trac_spd,
                       EXIT_MRK"testspdDDR3TableOrder() - fails: %d",
                       fails );
        }

        /**
         * @brief This test will ensure that the DDR4 lookup table is in a
         *        sorted order, according to the keyword enumeration, to enable
         *        the search algorithm to work correctly.
         */
        void testspdDDR4TableOrder ( void )
        {
            uint64_t prevKeyword = 0x0;
            uint64_t fails = 0x0;

            TRACFCOMP( g_trac_spd, ENTER_MRK"testspdDDR4TableOrder()" );

            for( uint32_t entry = 0;
                 entry < (sizeof(ddr4Data)/sizeof(ddr4Data[0]));
                 entry++ )
            {
                if( !(ddr4Data[entry].keyword >= prevKeyword) )
                {
                    fails++;
                    TS_FAIL( "testspdDDR4TableOrder - DDR4 table out of order! Cur kwd: "
                             "0x%04X, Pre kwd: 0x%04X",
                             ddr4Data[entry].keyword,
                             prevKeyword );
                }
                prevKeyword = ddr4Data[entry].keyword;
            }

            TRACFCOMP( g_trac_spd,
                       EXIT_MRK"testspdDDR4TableOrder() - fails: %d",
                       fails );
        }

        /**
         * @brief This test will ensure that the Planar lookup table is in a
         *        sorted order, according to the keyword enumeration, to enable
         *        the search algorithm to work correctly.
         */
        void testspdPlanarTableOrder ( void )
        {
            uint64_t prevKeyword = 0x0;
            uint64_t fails = 0x0;

            TRACFCOMP( g_trac_spd, ENTER_MRK"testspdPlanarTableOrder()" );

            for( uint32_t entry = 0;
                 entry < (sizeof(planarEepromData)/sizeof(planarEepromData[0]));
                 entry++ )
            {
                if( !(planarEepromData[entry].keyword >= prevKeyword) )
                {
                    fails++;
                    TS_FAIL( "testspdPlanarTableOrder - Planar table out of order! Cur kwd: "
                             "0x%04X, Pre kwd: 0x%04X",
                             planarEepromData[entry].keyword,
                             prevKeyword );
                }
                prevKeyword = planarEepromData[entry].keyword;
            }

            TRACFCOMP( g_trac_spd,
                       EXIT_MRK"testspdPlanarTableOrder() - fails: %d",
                       fails );
        }

        /**
         * @brief This test reads all of the keywords for all of the
         *      DIMMs found using the generic VPD driver interface.
         */
        void testSpdReadGeneric ( void )
        {
            errlHndl_t err = nullptr;
            uint64_t cmds = 0x0;
            uint64_t fails = 0x0;
            uint8_t * theData = nullptr;

            TRACFCOMP( g_trac_spd,
                       ENTER_MRK"testSpdReadGeneric() DIMM" );

            do
            {
                TARGETING::Target * theTarget = nullptr;

                // Get DIMM Targets
                TargetHandleList dimmList;
                getDIMMTargets( dimmList );

                if( ( 0 == dimmList.size() ) ||
                    ( nullptr == dimmList[0] ) )
                {
                    TRACFCOMP( g_trac_spd,
                               "testSpdReadGeneric - No DIMMs found!" );
                    break;
                }

                // Operate on first DIMM.
                theTarget = dimmList[0];
                size_t theSize = 0;
                bool writeable = false;
                uint32_t entry = 0x0;

                // Get the DDR revision
                uint8_t memType = 0x0;
                err = getMemType( theTarget,
                                  memType );
                if( err )
                {
                    fails++;
                    TS_FAIL("testSpdReadGeneric- Failure reading Basic memory type!" );
                    errlCommit( err,
                                VPD_COMP_ID );
                    break;
                }

                // Get the module type.
                modSpecTypes_t modType = NA;
                err = getModType(modType,
                                 theTarget,
                                 memType);
                if( err )
                {
                    fails++;
                    TS_FAIL("testSpdReadGeneric- Failure reading memory module type!");
                    errlCommit( err,
                                VPD_COMP_ID );
                    break;
                }


                for( uint64_t keyword = SPD::SPD_FIRST_NORM_KEYWORD;
                     keyword <= SPD::SPD_LAST_NORM_KEYWORD; keyword++ )
                {
                    cmds++;
                    writeable = false;
                    if( nullptr != theData )
                    {
                        free( theData );
                        theData = nullptr;
                    }

                    // Get the required size of the buffer
                    theSize = 0;
                    if( SPD::DDR4_TYPE == memType )
                    {
                        size_t dataSize = (modType == DDIMM)
                            ? (sizeof(ddr4DDIMMData)/sizeof(ddr4DDIMMData[0]))
                            : (sizeof(ddr4Data)/sizeof(ddr4Data[0]));

                        for( entry = 0;
                             entry < dataSize;
                             entry++ )
                        {
                            if (modType == DDIMM)
                            {
                                if( keyword == ddr4DDIMMData[entry].keyword )
                                {
                                    theSize = ddr4DDIMMData[entry].length;
                                    writeable = ddr4DDIMMData[entry].writable;
                                    break;
                                }
                            }
                            else
                            {
                                if( keyword == ddr4Data[entry].keyword )
                                {
                                    theSize = ddr4Data[entry].length;
                                    writeable = ddr4Data[entry].writable;
                                    break;
                                }
                            }
                        }
                    }

                    if( 0 == theSize )
                    {
                        // memType not supported or Keyword not supported on
                        // this memType
                        cmds--;
                        continue;
                    }

                    // Allocate the buffer
                    theData = static_cast<uint8_t*>(calloc( theSize,sizeof(uint8_t) ));

                    err = deviceRead( theTarget,
                                      theData,
                                      theSize,
                                      DEVICE_VPD_ADDRESS( SPD::NO_RECORD, keyword ) );

                    if( err )
                    {
                        fails++;
                        TS_FAIL( "testSpdReadGeneric - Failure on keyword: %04x",
                                 keyword );
                        errlCommit( err,
                                    VPD_COMP_ID );
                        continue;
                    }

                    // Read was successful, print out the data read
                    if (theSize == 1)
                    {
                        TRACFCOMP( g_trac_spd,
                                   "testSpdReadGeneric - kwd: 0x%04x, val: 0x%02x, size: 1",
                                   keyword, theData[0] );
                    }
                    else if (theSize == 2)
                    {
                        TRACFCOMP( g_trac_spd,
                                   "testSpdReadGeneric - kwd: 0x%04x, val: 0x%04x, size: 2",
                                   keyword,
                                   reinterpret_cast<uint16_t *>(theData)[0] );
                    }
                    else if (theSize == 3)
                    {
                        TRACFCOMP( g_trac_spd,
                                   "testSpdReadGeneric - kwd: 0x%04x, val: 0x%02x%02x%02x, size: %d",
                                   keyword, theData[0], theData[1], theData[2],
                                   theSize );
                    }
                    else
                    {
                        // For 4 bytes or larger, just print the first 4 bytes
                        TRACFCOMP( g_trac_spd,
                                   "testSpdReadGeneric - kwd: 0x%04x, val: 0x%08x, size: %d",
                                   keyword,
                                   reinterpret_cast<uint32_t *>(theData)[0],
                                   theSize );
                    }

                    if (writeable)
                    {
                        // Currently only the following two keywords are writeable
                        // other tests will explicitly do writes to validate these two
                        if ((keyword == SPD::DIMM_BAD_DQ_DATA) ||
                            (keyword == SPD::EXPLORER_FW_VERSION))
                        {
                            TS_INFO( "testSpdReadGeneric - CONFIRMED PASS on keyword: %04x, "
                                     "NORM keyword table defines as WRITEABLE",
                                     keyword );
                        }
                        else
                        {
                            fails++;
                            TS_FAIL("testSpdReadGeneric NORM keyword=%04x table defines as "
                                    "WRITEABLE but should only be READABLE", keyword);
                        }

                    }
                    else
                    {
                        // Keyword is -NOT- writeable, so attempt the write which should fail
                        err = deviceWrite( theTarget,
                                           theData,
                                           theSize,
                                           DEVICE_VPD_ADDRESS( SPD::NO_RECORD, keyword ) );
                        if (theData != nullptr)
                        {
                            free(theData);
                            theData = nullptr;
                        }
                        if (err == nullptr)
                        {
                            fails++;
                            TS_FAIL("testSpdReadGeneric We should have failed writing "
                                    "to a READ ONLY keyword=0x%X", keyword);
                            break;
                        }
                        else
                        {
                            if ( ERRL_GETRC_SAFE(err) != VPD::VPD_KEYWORD_NOT_WRITABLE)
                            {
                                fails++;
                                TS_FAIL("testSpdReadGeneric BAD RESULT - We DID -NOT- FAIL writing "
                                    "as expected to a READ ONLY keyword=0x%X RC=0x%X", keyword,
                                    ERRL_GETRC_SAFE(err));
                                break;
                            }
                            else
                            {
                                TS_INFO("testSpdReadGeneric GOOD RESULT - We DID FAIL writing "
                                    "to a READ ONLY keyword=0x%X RC=0x%X", keyword,
                                    ERRL_GETRC_SAFE(err));
                                delete err;
                                err = nullptr;
                            }
                        }
                    }
                } // end for

                if( err )
                {
                    break;
                }
            } while( 0 );

            if( nullptr != theData )
            {
                free( theData );
                theData = nullptr;
            }

            if( cmds == 0 )
            {
                TRACFCOMP(g_trac_spd,
                          "testSpdReadGeneric - No tests ran, something is wrong..." );
            }

            TRACFCOMP( g_trac_spd,
                       "testSpdReadGeneric - %d/%d fails",
                       fails, cmds );
        }

        /**
         * @brief Test a SPD Write EXPLORER_FW_VERSION using Generic VPD.
         */
        void testSpdWriteFWGeneric ( void )
        {
            errlHndl_t err = nullptr;
            uint64_t cmds = 0x0;
            uint64_t fails = 0x0;
            uint8_t * testData = nullptr;
            uint8_t * origData = nullptr;
            uint8_t * verifyData = nullptr;

            TS_INFO("testSpdWriteFWGeneric Entry");

            do
            {
                TARGETING::Target * theTarget = nullptr;

                // Get DIMM Targets
                TargetHandleList dimmList;
                getDIMMTargets( dimmList );

                TS_INFO( "testSpdWriteFWGeneric dimmList.size()=%d", dimmList.size() );
                if( ( 0 == dimmList.size() ) ||
                    ( nullptr == dimmList[0] ) )
                {
                    TS_FAIL("testSpdWriteFWGeneric - No DIMMs found! Why not?");
                    break;
                }

                // Operate on first DIMM
                cmds++;
                theTarget = dimmList[0];
                size_t theSize = 0;

                // Get Memory Type
                uint8_t memType = 0x0;
                err = getMemType( theTarget,
                                  memType );

                if( err )
                {
                    fails++;
                    TS_FAIL( "testSpdWriteFWGeneric - failed to read memtype!" );
                    errlCommit( err,
                                VPD_COMP_ID );
                    break;
                }

                // Get the module type.
                modSpecTypes_t modType = NA;
                err = getModType(modType,
                                 theTarget,
                                 memType);
                if( err )
                {
                    fails++;
                    TS_FAIL("testSpdWriteFWGeneric- Failure reading memory module type!");
                    errlCommit( err,
                                VPD_COMP_ID );
                    break;
                }

                // Get the size
                if( SPD::DDR4_TYPE == memType )
                {
                    size_t dataSize = (modType == DDIMM)
                        ? (sizeof(ddr4DDIMMData)/sizeof(ddr4DDIMMData[0]))
                        : (sizeof(ddr4Data)/sizeof(ddr4Data[0]));

                    for( uint32_t entry = 0;
                         entry < dataSize;
                         entry++ )
                    {
                        if (modType == DDIMM)
                        {
                            if( SPD::EXPLORER_FW_VERSION == ddr4DDIMMData[entry].keyword )
                            {
                                theSize = ddr4DDIMMData[entry].length;
                                break;
                            }
                        }
                        else
                        {
                            if( SPD::EXPLORER_FW_VERSION == ddr4Data[entry].keyword )
                            {
                                theSize = ddr4Data[entry].length;
                                break;
                            }
                        }
                    }
                }
                else if(SPD::DDR5_TYPE == memType)
                {
                    size_t dataSize = sizeof(ddr5DDIMMData)/sizeof(ddr5DDIMMData[0]);

                    for(uint32_t entry = 0; entry < dataSize; entry++)
                    {
                        // DDR5 VPD also contains the EXPLORER_FW_VERSION keyword, so
                        // use it here for DDR5 testing.
                        if(SPD::EXPLORER_FW_VERSION == ddr5DDIMMData[entry].keyword)
                        {
                            theSize = ddr5DDIMMData[entry].length;
                            break;
                        }
                    }
                }
                else
                {
                    fails++;
                    TS_FAIL( "testSpdWriteFWGeneric - Unsupported memory type: 0x%04x", memType );
                    errlCommit( err, VPD_COMP_ID);
                    break;
                }

                if( 0 == theSize )
                {
                    // memType or Keyword not supported
                    TS_INFO("testSpdWriteFWGeneric memType Keyword not supported, but we tried...");
                    cmds++;
                    break;
                }

                // Allocate data buffer
                origData = static_cast<uint8_t*>(calloc( theSize,sizeof(uint8_t) ));

                // Read the data out first
                err = deviceRead( theTarget,
                                  origData,
                                  theSize,
                                  DEVICE_VPD_ADDRESS( SPD::NO_RECORD, EXPLORER_FW_VERSION ) );
                TRACFBIN( g_trac_spd, "testSpdWriteFWGeneric ORIGINAL EXPLORER_FW_VERSION read=",
                            origData, theSize );

                if( err )
                {
                    fails++;
                    TS_FAIL( "testSpdWriteFWGeneric - failed to read ORIGINAL EXPLORER_FW_VERSION!" );
                    errlCommit( err,
                                VPD_COMP_ID );
                    break;
                }

                // fill it up with some dummy data
                testData = static_cast<uint8_t*>(calloc( theSize,sizeof(uint8_t) ));
                for( size_t x=0; x<theSize; x++ )
                {
                    testData[x] = x;
                }

                // Write the test data in
                err = deviceWrite( theTarget,
                                   testData,
                                   theSize,
                                   DEVICE_VPD_ADDRESS( SPD::NO_RECORD, EXPLORER_FW_VERSION ) );

                if( err )
                {
                    fails++;
                    TS_FAIL( "testSpdWriteFWGeneric - Error writing data to EXPLORER_FW_VERSION" );
                    break;
                }

                // Read the data out again to check it
                verifyData = static_cast<uint8_t*>(calloc( theSize,sizeof(uint8_t) ));
                err = deviceRead( theTarget,
                                  verifyData,
                                  theSize,
                                  DEVICE_VPD_ADDRESS( SPD::NO_RECORD, EXPLORER_FW_VERSION ) );
                TRACFBIN( g_trac_spd, "testSpdWriteFWGeneric TEST DATA EXPLORER_FW_VERSION data read=",
                            verifyData, theSize );

                if( err )
                {
                    fails++;
                    TS_FAIL( "testSpdWriteFWGeneric - failed to read TEST DATA for EXPLORER_FW_VERSION!" );
                    errlCommit( err,
                                VPD_COMP_ID );
                    break;
                }

                if( memcmp( testData, verifyData, theSize ) )
                {
                    fails++;
                    TS_FAIL( "testSpdWriteFWGeneric - PROBLEM DIMM EXPLORER_FW_VERSION "
                             "data does not match what we wrote!" );
                    TRACFBIN( g_trac_spd, "PROBLEM EXPLORER_FW_VERSION MISMATCH wrote=",
                                testData, theSize );
                    TRACFBIN( g_trac_spd, "PROBLEM EXPLORER_FW_VERSION MISMATCH read=",
                                verifyData, theSize );
                }
                else
                {
                    TS_INFO( "testSpdWriteFWGeneric - CONFIRMED DIMM EXPLORER_FW_VERSION "
                             "data written successfully!" );
                    TRACFBIN( g_trac_spd, "CONFIRMED EXPLORER_FW_VERSION wrote=",
                                testData, theSize );
                    TRACFBIN( g_trac_spd, "CONFIRMED EXPLORER_FW_VERSION read=",
                                verifyData, theSize );
                }

                // put the original data back to be a good citizen
                err = deviceWrite( theTarget,
                                   origData,
                                   theSize,
                                   DEVICE_VPD_ADDRESS( SPD::NO_RECORD, EXPLORER_FW_VERSION ) );
                TS_INFO( "testSpdWriteFWGeneric - deviceWrite Restoring ORIGINAL "
                         "DIMM EXPLORER_FW_VERSION" );

                if( err )
                {
                    fails++;
                    TS_FAIL( "testSpdWriteFWGeneric - Error writing original data back to "
                             "DIMM EXPLORER_FW_VERSION data, things may be corrupted!");
                    break;
                }
                else
                {
                    TS_INFO("testSpdWriteFWGeneric - Successfully restored original "
                            "DIMM EXPLORER_FW_VERSION theSize=0x%X", theSize);
                }


            } while( 0 );

            if( nullptr != testData )
            {
                free(testData);
                testData = nullptr;
            }

            if( nullptr != origData )
            {
                free(origData);
                origData = nullptr;
            }

            if( nullptr != verifyData )
            {
                free(verifyData);
                verifyData = nullptr;
            }

            if( cmds == 0 )
            {
                TS_FAIL("testSpdWriteFWGeneric - No tests ran, something is wrong...");
            }

            TS_INFO("testSpdWriteFWGeneric Exit - %d/%d fails", fails, cmds);
        }

};

#endif
