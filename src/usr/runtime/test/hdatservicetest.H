/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/runtime/test/hdatservicetest.H $                      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2023                        */
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
#ifndef __TEST_HDATSERVICETEST_H
#define __TEST_HDATSERVICETEST_H

/**
 *  @file runtimetest.H
 *
 */

#include <cxxtest/TestSuite.H>

#include <arch/ppc.H> //for MAGIC
#include <errl/errlmanager.H>
#include <targeting/common/commontargeting.H>
#include <runtime/runtime.H>
#include <attributeenums.H>
#include "../hdatstructs.H"
#include "../errlud_hdat.H"
#include <runtime/runtime_reasoncodes.H>
#include <vfs/vfs.H>

extern trace_desc_t* g_trac_runtime;

class HdatServiceTest: public CxxTest::TestSuite
{
  public:
    void testHdat(void)
    {
        TRACFCOMP( g_trac_runtime, "testHdat> start" );
        errlHndl_t errhdl = NULL;

        // Figure out if we expect to have this data or not
        TARGETING::Target * sys = TARGETING::UTIL::assertGetToplevelTarget();
        TARGETING::ATTR_PAYLOAD_KIND_type payload_kind = sys->getAttr<TARGETING::ATTR_PAYLOAD_KIND>();

        // @TODO JIRA PFHB-15 Remove this if statement and force PHYP for Bonito simics as well.
        if (sys->getAttr<TARGETING::ATTR_IS_STANDALONE>())
        {
            // Force payload kind to be PHYP for the test. There are some areas of code where the kind remains NONE for
            // standalone. However, for this test we want to exercise the PHYP payload kind path.
            payload_kind =  TARGETING::PAYLOAD_KIND_PHYP;
        }

        // Verify something in the system parms
        uint64_t sys_parms_addr = 0;
        size_t sys_parms_size = 0;
        errhdl = RUNTIME::get_host_data_section(
                                    RUNTIME::IPLPARMS_SYSTEM,
                                    0,
                                    sys_parms_addr,
                                    sys_parms_size );
        if ( payload_kind == TARGETING::PAYLOAD_KIND_PHYP)
        {
            if( errhdl  )
            {
                TS_FAIL("testHdat> Error trying to locate IPLPARMS_SYSTEM");
                errlCommit(errhdl,RUNTIME_COMP_ID);
            }
            else if( sys_parms_addr == 0 )
            {
                TS_FAIL("testHdat> NULL returned for get_host_data_section(IPLPARMS_SYSTEM)");
            }
            else if( (sys_parms_size < sizeof(hdatSysParms_t))
                    || (sys_parms_size == RUNTIME::DATA_SIZE_UNKNOWN) )
            {
                TS_FAIL("testHdat> Size of IPLPARMS_SYSTEM data too small");
            }
            else
            {
                hdatSysParms_t* sys_parms = reinterpret_cast<hdatSysParms_t*>(sys_parms_addr);

                uint32_t pvr = sys_parms->hdatEffectivePvr;
                TRACFCOMP( g_trac_runtime, "PVR=%.8X", pvr );

                TARGETING::Target* procmaster = NULL;
                TARGETING::targetService().masterProcChipTargetHandle( procmaster );
                assert( procmaster != NULL );
                TARGETING::ATTR_MODEL_type model =
                    procmaster->getAttr<TARGETING::ATTR_MODEL>();

                if( (model == TARGETING::MODEL_POWER10)
                        && !((pvr & 0x00FF0000) == 0x00800000) )
                {
                    TS_FAIL("testHdat> PVR model %.8X != 80 for P10",pvr);
                }
            }
        }
        else
        {
            if (!errhdl)
            {
                TS_FAIL("testHdat> Did not get expected error trying to locate IPLPARMS_SYSTEM for non-PHYP Payload");
            }
            else
            {
                delete errhdl;
                errhdl = nullptr;
            }
        }

        // Verify the Dump Tables
        uint64_t dump_addr = 0;
        size_t dump_size = 0;
        errhdl = RUNTIME::get_host_data_section(
                                    RUNTIME::MS_DUMP_SRC_TBL,
                                    0,
                                    dump_addr,
                                    dump_size );

        if( errhdl
            && ((payload_kind == TARGETING::PAYLOAD_KIND_PHYP)
               || (payload_kind == TARGETING::PAYLOAD_KIND_NONE)))
        {
            TS_FAIL("testHdat> Error trying to locate MS_DUMP_SRC_TBL");
            errlCommit(errhdl,RUNTIME_COMP_ID);
        }
        else if( !errhdl
            && (payload_kind != TARGETING::PAYLOAD_KIND_PHYP)
            && (payload_kind != TARGETING::PAYLOAD_KIND_NONE))
        {
            TS_FAIL("testHdat> Did not get expected error trying to locate MS_DUMP_SRC_TBL for non-PHYP/Standalone Payload");
        }
        else if( ((dump_addr == 0) || (dump_size < 16))
            && (payload_kind != TARGETING::PAYLOAD_KIND_PHYP)
            && (payload_kind != TARGETING::PAYLOAD_KIND_NONE))
        {
            TS_FAIL("testHdat> NULL or zero size returned for get_host_data_section(MS_DUMP_SRC_TBL)");
        }
        else if( (dump_size <16)
                 || (dump_size == RUNTIME::DATA_SIZE_UNKNOWN))
        {
            TS_FAIL("testHdat> Size of MS_DUMP_SRC_TBL is unexpected");
        }
        if( errhdl )
        {
            delete errhdl;
        }

        errhdl = RUNTIME::get_host_data_section(
                                    RUNTIME::MS_DUMP_DST_TBL,
                                    0,
                                    dump_addr,
                                    dump_size );
        if( errhdl
            && ((payload_kind == TARGETING::PAYLOAD_KIND_PHYP)
            || (payload_kind == TARGETING::PAYLOAD_KIND_NONE)))
        {
            TS_FAIL("testHdat> Error trying to locate MS_DUMP_DST_TBL");
            errlCommit(errhdl,RUNTIME_COMP_ID);
        }
        else if( !errhdl
                 && (payload_kind != TARGETING::PAYLOAD_KIND_PHYP)
                 && (payload_kind != TARGETING::PAYLOAD_KIND_NONE))
        {
            TS_FAIL("testHdat> Did not get expected error trying to locate MS_DUMP_DST_TBL for non-PHYP/Standalone Payload");
        }
        else if( ((dump_addr == 0) || (dump_size < 16))
                 && (payload_kind != TARGETING::PAYLOAD_KIND_PHYP)
                 && (payload_kind != TARGETING::PAYLOAD_KIND_NONE))
        {
            TS_FAIL("testHdat> NULL or zero size returned for get_host_data_section(MS_DUMP_DST_TBL)");
        }
        else if( (dump_size <16)
                 || (dump_size == RUNTIME::DATA_SIZE_UNKNOWN))
        {
            TS_FAIL("testHdat> Size of MS_DUMP_DST_TBL is unexpected");
        }
        if( errhdl )
        {
            delete errhdl;
        }

        errhdl = RUNTIME::get_host_data_section(
                                    RUNTIME::MS_DUMP_RESULTS_TBL,
                                    0,
                                    dump_addr,
                                    dump_size );

        if( errhdl
            && ((payload_kind == TARGETING::PAYLOAD_KIND_PHYP)
            || (payload_kind == TARGETING::PAYLOAD_KIND_NONE)))
        {
            TS_FAIL("testHdat> Error trying to locate MS_DUMP_SRC_TBL");
            errlCommit(errhdl,RUNTIME_COMP_ID);
        }
        else if( !errhdl
                 && (payload_kind != TARGETING::PAYLOAD_KIND_PHYP)
                 && (payload_kind != TARGETING::PAYLOAD_KIND_NONE))
        {
            TS_FAIL("testHdat> Did not get expected error trying to locate MS_DUMP_RESULTS_TBL for non-PHYP/Standalone Payload");
        }
        else if( ((dump_addr == 0) || (dump_size < 16))
                 && (payload_kind != TARGETING::PAYLOAD_KIND_PHYP)
                 && (payload_kind != TARGETING::PAYLOAD_KIND_NONE))
        {
            TS_FAIL("testHdat> NULL or zero size returned for get_host_data_section(MS_DUMP_RESULTS_TBL)");
        }
        else if( (dump_size <16)
                 || (dump_size == RUNTIME::DATA_SIZE_UNKNOWN))
        {
            TS_FAIL("testHdat> Size of MS_DUMP_RESULTS_TBL is unexpected");
        }
        if( errhdl )
        {
            delete errhdl;
        }

        TRACFCOMP( g_trac_runtime, "testHdat> finish" );
    }

    void testSpira( void )
    {
        // @TODO JIRA PFHB-15 Remove this if statement.
        if ( ! TARGETING::UTIL::assertGetToplevelTarget()->getAttr<TARGETING::ATTR_IS_STANDALONE>())
        {
            return;
        }
        TRACFCOMP( g_trac_runtime, "testSpira> start" );
        errlHndl_t errhdl = NULL;

        uint64_t naca_addr = 0;
        size_t naca_size = 0;
        errhdl = RUNTIME::get_host_data_section(
                                    RUNTIME::NACA,
                                    0,
                                    naca_addr,
                                    naca_size );
        if( errhdl  )
        {
            TS_FAIL("testSpira> Error trying to locate NACA");
            errlCommit(errhdl,RUNTIME_COMP_ID);
        }
        else if( naca_addr == 0 )
        {
            TS_FAIL("testSpira> NULL returned for get_host_data_section(NACA)");
        }
        else if( (naca_size == 0)
                 || (naca_size == RUNTIME::DATA_SIZE_UNKNOWN) )
        {
            TS_FAIL("testSpira> Size of NACA data too small");
        }


        bool found_spira_l = false, found_spira_s = false, found_spira_h = false;
        uint64_t spiral_addr = 0;
        size_t spiral_size = 0;
        errhdl = RUNTIME::get_host_data_section(
                                    RUNTIME::SPIRA_L,
                                    0,
                                    spiral_addr,
                                    spiral_size );
        if( errhdl  )
        {
            TS_FAIL("testSpira> Error trying to locate SPIRA_L");
            errlCommit(errhdl,RUNTIME_COMP_ID);
        }
        else if( spiral_addr == 0 )
        {
            TS_INFO("testSpira> NULL returned for get_host_data_section(SPIRA_L). Will check SPIRA H/S");
        }
        else if( (spiral_size == 0)
                 || (spiral_size == RUNTIME::DATA_SIZE_UNKNOWN) )
        {
            TS_FAIL("testSpira> Size of SPIRA_L data too small");
        }
        else
        {
            found_spira_l = true;
        }


        uint64_t spiras_addr = 0;
        size_t spiras_size = 0;
        errhdl = RUNTIME::get_host_data_section(
                                    RUNTIME::SPIRA_S,
                                    0,
                                    spiras_addr,
                                    spiras_size );
        if( errhdl  )
        {
            TS_FAIL("testSpira> Error trying to locate SPIRA_S");
            errlCommit(errhdl,RUNTIME_COMP_ID);
        }
        else if( spiras_addr == 0  && !found_spira_l)
        {
            TS_FAIL("testSpira> NULL returned for get_host_data_section(SPIRA_S) and could not find Legacy SPIRA either!");
        }
        else if( (spiras_size == 0)
                 || (spiras_size == RUNTIME::DATA_SIZE_UNKNOWN) )
        {
            TS_FAIL("testSpira> Size of SPIRA-S data too small");
        }
        else
        {
            found_spira_s = true;
        }

        uint64_t spirah_addr = 0;
        size_t spirah_size = 0;
        errhdl = RUNTIME::get_host_data_section(
                                    RUNTIME::SPIRA_H,
                                    0,
                                    spirah_addr,
                                    spirah_size );
        if( errhdl  )
        {
            TS_FAIL("testSpira> Error trying to locate SPIRA_H");
            errlCommit(errhdl,RUNTIME_COMP_ID);
        }
        else if(spirah_addr == 0)
        {
            if ( found_spira_s )
            {
                TS_FAIL("testSpira> NULL returned for get_host_data_section(SPIRA_H)");
            }
            // A later check will handle the case where the Legacy SPIRA was found and used instead of SPIRA H/S.
            // So, do nothing and leave this if/else if logic.
        }
        else if( (spirah_size == 0)
                 || (spirah_size == RUNTIME::DATA_SIZE_UNKNOWN) )
        {
            TS_FAIL("testSpira> Size of SPIRA_H data too small");
        }
        else
        {
            found_spira_h = true;
        }

        // Make sure either Legacy SPIRA or SPIRA H/S were found during the test.
        if (!found_spira_l && !found_spira_s && !found_spira_h)
        {
            TS_FAIL("testSpira> Did not find any SPIRAs!");
        }
        // Ensure that SPIRA S and H were found together. Need both.
        if ((found_spira_s && !found_spira_h)
             || (!found_spira_s && found_spira_h))
        {
            TS_FAIL("testSpira> Only 1 of SPIRA H/S was found. The other was not. Found S = %d, Found H = %d",
                    found_spira_s,
                    found_spira_h);
        }

        errhdl = new ERRORLOG::ErrlEntry(
                            ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                            RUNTIME::MOD_HDATSERVICE_VERIFY_HDAT_ADDRESS,
                            RUNTIME::RC_BAD_HDAT_HEADER,
                            0,0 );
        RUNTIME::add_host_data_ffdc(RUNTIME::NACA,errhdl);
        RUNTIME::add_host_data_ffdc(RUNTIME::SPIRA_L,errhdl);
        RUNTIME::add_host_data_ffdc(RUNTIME::SPIRA_S,errhdl);
        RUNTIME::add_host_data_ffdc(RUNTIME::SPIRA_H,errhdl);
        errlCommit(errhdl,RUNTIME_COMP_ID);


        TRACFCOMP( g_trac_runtime, "testSpira> finish" );
    }

    // Handle the case where we are running the testcases before the
    //  libruntime.so module has been loaded
    bool iv_loaded_libruntime;

    HdatServiceTest()
      : CxxTest::TestSuite(), iv_loaded_libruntime(false)
    {
        // Need to load up the runtime module if it isn't already loaded
        if (  !VFS::module_is_loaded( "libruntime.so" ) )
        {
            errlHndl_t errhdl = VFS::module_load( "libruntime.so" );
            if ( errhdl )
            {
                TS_FAIL("HdatServiceTest> Failed to load libruntime.so");
                errlCommit(errhdl,RUNTIME_COMP_ID);
            }
            else
            {
                iv_loaded_libruntime = true;
            }
        }
    }

    ~HdatServiceTest()
    {
        if( iv_loaded_libruntime )
        {
            errlHndl_t errhdl = VFS::module_unload( "libruntime.so" );
            if ( errhdl )
            {
                TS_FAIL("HdatServiceTest> Failed to unload libruntime.so");
                errlCommit(errhdl,RUNTIME_COMP_ID);
            }
        }
    }

};


#endif

