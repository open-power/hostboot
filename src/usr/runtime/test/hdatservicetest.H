/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/runtime/test/hdatservicetest.H $                      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2021                        */
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

/*
 * To test with a custom HDAT do the following:
 *   #define REAL_HDAT_TEST in hdatservicetest.H
 *   #define REAL_HDAT_TEST in hdatservice.C
 *   When MAGIC_BREAK hits run this in simics:
 *      system_cmp0.phys_mem.load-file hdat.bin 0x10000000
 *
 *   Note that there will be DumpTest failures.
 */
//#define REAL_HDAT_TEST

extern trace_desc_t* g_trac_runtime;

class HdatServiceTest: public CxxTest::TestSuite
{
  public:
    void testHdat(void)
    {
        TRACFCOMP( g_trac_runtime, "testHdat> start" );
        errlHndl_t errhdl = NULL;

        // Figure out if we expect to have this data or not
        TARGETING::Target * sys = NULL;
        TARGETING::targetService().getTopLevelTarget( sys );
        assert(sys != NULL);
        TARGETING::ATTR_PAYLOAD_KIND_type payload_kind =
          sys->getAttr<TARGETING::ATTR_PAYLOAD_KIND>();

#ifdef REAL_HDAT_TEST
        payload_kind = TARGETING::PAYLOAD_KIND_PHYP;
#endif

        // Verify something in the system parms
        uint64_t sys_parms_addr = 0;
        size_t sys_parms_size = 0;
        errhdl = RUNTIME::get_host_data_section(
                                    RUNTIME::IPLPARMS_SYSTEM,
                                    0,
                                    sys_parms_addr,
                                    sys_parms_size );
        if( payload_kind == TARGETING::PAYLOAD_KIND_PHYP )
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
            if( !errhdl )
            {
                TS_FAIL("testHdat> Did not get expected error trying to locate IPLPARMS_SYSTEM for non-PHYP Payload");
            }
            else
            {
                delete errhdl;
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
                 && (payload_kind != TARGETING::PAYLOAD_KIND_NONE) )
        {
            TS_FAIL("testHdat> Did not get expected error trying to locate MS_DUMP_SRC_TBL for non-PHYP/Standalone Payload");
        }
        else if( ((dump_addr == 0) || (dump_size < 16))
                 && (payload_kind != TARGETING::PAYLOAD_KIND_PHYP) 
                 && (payload_kind != TARGETING::PAYLOAD_KIND_NONE) )
        {
            TS_FAIL("testHdat> NULL or zero size returned for get_host_data_section(MS_DUMP_SRC_TBL)");
        }
        else if( (dump_size <16)
                 || (dump_size == RUNTIME::DATA_SIZE_UNKNOWN) )
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
                || (payload_kind == TARGETING::PAYLOAD_KIND_NONE)) )
        {
            TS_FAIL("testHdat> Error trying to locate MS_DUMP_DST_TBL");
            errlCommit(errhdl,RUNTIME_COMP_ID);
        }
        else if( !errhdl
                 && (payload_kind != TARGETING::PAYLOAD_KIND_PHYP) 
                 && (payload_kind != TARGETING::PAYLOAD_KIND_NONE) )
        {
            TS_FAIL("testHdat> Did not get expected error trying to locate MS_DUMP_DST_TBL for non-PHYP/Standalone Payload");
        }
        else if( ((dump_addr == 0) || (dump_size < 16))
                 && (payload_kind != TARGETING::PAYLOAD_KIND_PHYP) 
                 && (payload_kind != TARGETING::PAYLOAD_KIND_NONE) )
        {
            TS_FAIL("testHdat> NULL or zero size returned for get_host_data_section(MS_DUMP_DST_TBL)");
        }
        else if( (dump_size <16)
                 || (dump_size == RUNTIME::DATA_SIZE_UNKNOWN) )
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
                || (payload_kind == TARGETING::PAYLOAD_KIND_NONE)) )
        {
            TS_FAIL("testHdat> Error trying to locate MS_DUMP_SRC_TBL");
            errlCommit(errhdl,RUNTIME_COMP_ID);
        }
        else if( !errhdl
                 && (payload_kind != TARGETING::PAYLOAD_KIND_PHYP) 
                 && (payload_kind != TARGETING::PAYLOAD_KIND_NONE) )
        {
            TS_FAIL("testHdat> Did not get expected error trying to locate MS_DUMP_RESULTS_TBL for non-PHYP/Standalone Payload");
        }
        else if( ((dump_addr == 0) || (dump_size < 16))
                 && (payload_kind != TARGETING::PAYLOAD_KIND_PHYP) 
                 && (payload_kind != TARGETING::PAYLOAD_KIND_NONE) )
        {
            TS_FAIL("testHdat> NULL or zero size returned for get_host_data_section(MS_DUMP_RESULTS_TBL)");
        }
        else if( (dump_size <16)
                 || (dump_size == RUNTIME::DATA_SIZE_UNKNOWN) )
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
#ifdef REAL_HDAT_TEST
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
            TS_FAIL("testSpira> NULL returned for get_host_data_section(SPIRA_L)");
        }
        else if( (spiral_size == 0)
                 || (spiral_size == RUNTIME::DATA_SIZE_UNKNOWN) )
        {
            TS_FAIL("testSpira> Size of SPIRA_L data too small");
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
        else if( spiras_addr == 0 )
        {
            TS_FAIL("testSpira> NULL returned for get_host_data_section(SPIRA_S)");
        }
        else if( (spiras_size == 0)
                 || (spiras_size == RUNTIME::DATA_SIZE_UNKNOWN) )
        {
            TS_FAIL("testSpira> Size of SPIRA-S data too small");
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
        else if( spirah_addr == 0 )
        {
            TS_FAIL("testSpira> NULL returned for get_host_data_section(SPIRA_H)");
        }
        else if( (spirah_size == 0)
                 || (spirah_size == RUNTIME::DATA_SIZE_UNKNOWN) )
        {
            TS_FAIL("testSpira> Size of SPIRA_H data too small");
        }

        errhdl = new ERRORLOG::ErrlEntry(
                            ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                            RUNTIME::MOD_HDATSERVICE_VERIFY_HDAT_ADDRESS,
                            RUNTIME::RC_BAD_HDAT_HEADER,
                            0,0 );
        add_host_data_ffdc(RUNTIME::HSVC_NODE_DATA,errhdl);
        add_host_data_ffdc(RUNTIME::HSVC_SYSTEM_DATA,errhdl);
        add_host_data_ffdc(RUNTIME::NACA,errhdl);
        add_host_data_ffdc(RUNTIME::SPIRA_L,errhdl);
        add_host_data_ffdc(RUNTIME::SPIRA_S,errhdl);
        add_host_data_ffdc(RUNTIME::SPIRA_H,errhdl);
        errlCommit(errhdl,RUNTIME_COMP_ID);


        TRACFCOMP( g_trac_runtime, "testSpira> finish" );
#endif
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

