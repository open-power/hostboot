/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/runtime/test/hdatservicetest.H $                      */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012                   */
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
#ifndef __TEST_HDATSERVICETEST_H
#define __TEST_HDATSERVICETEST_H

/**
 *  @file runtimetest.H
 *
 */

#include <cxxtest/TestSuite.H>

#include <arch/ppc.H> //for MAGIC
#include <errl/errlmanager.H>
#include <runtime/runtime.H>
#include <targeting/common/commontargeting.H>
#include <attributeenums.H>
#include "../hdatstructs.H"

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

                if( (model == TARGETING::MODEL_MURANO)
                    && !((pvr & 0x00FF0000) == 0x004B0000) )
                {
                    TS_FAIL("testHdat> PVR model != 4B for Murano");
                }
                else if( (model == TARGETING::MODEL_VENICE)
                         && !((pvr & 0x00FF0000) == 0x004D0000) )
                {
                    TS_FAIL("testHdat> PVR model != 4D for Venice");
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



        // Verify the HostServices Node Data
        uint64_t node_data_addr = 0;
        size_t node_data_size = 0;
        errhdl = RUNTIME::get_host_data_section(
                                    RUNTIME::HSVC_NODE_DATA,
                                    0,
                                    node_data_addr,
                                    node_data_size );
        if( errhdl
            && ((payload_kind == TARGETING::PAYLOAD_KIND_PHYP) 
                || (payload_kind == TARGETING::PAYLOAD_KIND_NONE)) )
        {
            TS_FAIL("testHdat> Error trying to locate HSVC_NODE_DATA");
            errlCommit(errhdl,RUNTIME_COMP_ID);
        }
        else if( !errhdl
                 && (payload_kind != TARGETING::PAYLOAD_KIND_PHYP) 
                 && (payload_kind != TARGETING::PAYLOAD_KIND_NONE) )
        {
            TS_FAIL("testHdat> Did not get expected error trying to locate HSVC_NODE_DATA for non-PHYP/Standalone Payload");
        }
        else if( (node_data_addr == 0)
                 && (payload_kind != TARGETING::PAYLOAD_KIND_PHYP) 
                 && (payload_kind != TARGETING::PAYLOAD_KIND_NONE) )
        {
            TS_FAIL("testHdat> NULL or zero size returned for get_host_data_section(HSVC_NODE_DATA)");
        }
        else if( (node_data_size == 0)
                 || (node_data_size == RUNTIME::DATA_SIZE_UNKNOWN) )
        {
            TS_FAIL("testHdat> Size of HSVC_NODE_DATA is unexpected");
        }
        if( errhdl )
        {
            delete errhdl;
        }


        // Verify the HostServices System Data
        uint64_t sys_data_addr = 0;
        size_t sys_data_size = 0;
        errhdl = RUNTIME::get_host_data_section(
                                    RUNTIME::HSVC_SYSTEM_DATA,
                                    0,
                                    sys_data_addr,
                                    sys_data_size );
        if( errhdl
            && ((payload_kind == TARGETING::PAYLOAD_KIND_PHYP) 
                || (payload_kind == TARGETING::PAYLOAD_KIND_NONE)) )
        {
            TS_FAIL("testHdat> Error trying to locate HSVC_SYSTEM_DATA");
            errlCommit(errhdl,RUNTIME_COMP_ID);
        }
        else if( !errhdl
                 && (payload_kind != TARGETING::PAYLOAD_KIND_PHYP) 
                 && (payload_kind != TARGETING::PAYLOAD_KIND_NONE) )
        {
            TS_FAIL("testHdat> Did not get expected error trying to locate HSVC_SYSTEM_DATA for non-PHYP/Standalone Payload");
        }
        else if( ((sys_data_addr == 0) || (sys_data_size == 0))
                 && (payload_kind != TARGETING::PAYLOAD_KIND_PHYP) 
                 && (payload_kind != TARGETING::PAYLOAD_KIND_NONE) )
        {
            TS_FAIL("testHdat> NULL or zero size returned for get_host_data_section(HSVC_SYSTEM_DATA)");
        }
        else if( (sys_data_size == 0)
                 || (sys_data_size == RUNTIME::DATA_SIZE_UNKNOWN) )
        {
            TS_FAIL("testHdat> Size of HSVC_SYSTEM_DATA is unexpected");
        }
        if( errhdl )
        {
            delete errhdl;
        }

        // Verify the Dump Tables
        uint64_t dump_addr = 0;
        size_t dump_size = 0;
        errhdl = RUNTIME::get_host_data_section(
                                    RUNTIME::MS_DUMP_SRC_TBL,
                                    0,
                                    dump_addr,
                                    dump_size );
        if( errhdl && (payload_kind == TARGETING::PAYLOAD_KIND_PHYP) )
        {
            if( errhdl )
            {
                TS_FAIL("testHdat> Error trying to locate MS_DUMP_SRC_TBL");
                errlCommit(errhdl,RUNTIME_COMP_ID);
            }
            else if( dump_addr == 0 )
            {
                TS_FAIL("testHdat> NULL returned for get_host_data_section(MS_DUMP_SRC_TBL)");
            }
            else if( dump_size < 16 ) //1 entry is 16 bytes
            {
                TRACFCOMP( g_trac_runtime, "testHdat> dump_size=%d", dump_size );
                TS_FAIL("testHdat> Size of MS_DUMP_SRC_TBL data too small");
            }
        }
        else
        {
            if( !errhdl )
            {
                TS_FAIL("testHdat> Did not get expected error trying to locate MS_DUMP_SRC_TBL for non-PHYP Payload");
            }
            else
            {
                delete errhdl;
            }
        }

        errhdl = RUNTIME::get_host_data_section(
                                    RUNTIME::MS_DUMP_DST_TBL,
                                    0,
                                    dump_addr,
                                    dump_size );
        if( errhdl && (payload_kind == TARGETING::PAYLOAD_KIND_PHYP) )
        {
            if( errhdl )
            {
                TS_FAIL("testHdat> Error trying to locate MS_DUMP_DST_TBL");
                errlCommit(errhdl,RUNTIME_COMP_ID);
            }
            else if( dump_addr == 0 )
            {
                TS_FAIL("testHdat> NULL returned for get_host_data_section(MS_DUMP_DST_TBL)");
            }
            else if( dump_size < 16 ) //1 entry is 16 bytes
            {
                TRACFCOMP( g_trac_runtime, "testHdat> dump_size=%d", dump_size );
                TS_FAIL("testHdat> Size of MS_DUMP_DST_TBL data too small");
            }
        }
        else
        {
            if( !errhdl )
            {
                TS_FAIL("testHdat> Did not get expected error trying to locate MS_DUMP_DST_TBL for non-PHYP Payload");
            }
            else
            {
                delete errhdl;
            }
        }

        errhdl = RUNTIME::get_host_data_section(
                                    RUNTIME::MS_DUMP_RESULTS_TBL,
                                    0,
                                    dump_addr,
                                    dump_size );
        if( errhdl && (payload_kind == TARGETING::PAYLOAD_KIND_PHYP) )
        {
            if( errhdl )
            {
                TS_FAIL("testHdat> Error trying to locate MS_DUMP_RESULTS_TBL");
                errlCommit(errhdl,RUNTIME_COMP_ID);
            }
            else if( dump_addr == 0 )
            {
                TS_FAIL("testHdat> NULL returned for get_host_data_section(MS_DUMP_RESULTS_TBL)");
            }
            else if( dump_size < 16 ) //1 entry is 16 bytes
            {
                TRACFCOMP( g_trac_runtime, "testHdat> dump_size=%d", dump_size );
                TS_FAIL("testHdat> Size of MS_DUMP_RESULTS_TBL data too small");
            }
        }
        else
        {
            if( !errhdl )
            {
                TS_FAIL("testHdat> Did not get expected error trying to locate MS_DUMP_RESULTS_TBL for non-PHYP Payload");
            }
            else
            {
                delete errhdl;
            }
        }


        TRACFCOMP( g_trac_runtime, "testHdat> finish" );
    }

};


#endif

