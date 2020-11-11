/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/runtime/hdatservice.C $                               */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2020                        */
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
#include <trace/interface.H>
#include <errl/errlentry.H>
#include <runtime/runtime_reasoncodes.H>
#include <sys/mm.h>
#include <targeting/common/commontargeting.H>
#include <targeting/common/mfgFlagAccessors.H>
#include <initservice/initserviceif.H>
#include <runtime/runtime.H>
#include <attributeenums.H>
#include <vmmconst.h>
#include <util/align.H>
#include "hdatstructs.H"
#include "fakepayload.H"
#include <dump/dumpif.H>
#include "hdatservice.H"
#include "errlud_hdat.H"
#include <errl/errlmanager.H>
#include <targeting/attrrp.H>
#include <dump/dumpif.H>

//#define REAL_HDAT_TEST

trace_desc_t *g_trac_runtime = NULL;
TRAC_INIT(&g_trac_runtime, RUNTIME_COMP_NAME, KILOBYTE);

#define TRACUCOMP TRACDCOMP

namespace RUNTIME
{

/********************
 Local Constants used for sanity checks
 ********************/
const hdatHeaderExp_t MDT_HEADER = {
    0xD1F0,   //id
    "MS VPD", //name
    0x0024    //version
};

const hdatHeaderExp_t HBRT_DATA_HEADER = {
    0xD1F0,   //id
    "HBRT  ", //name
    0x0010    //version
};

const hdatHeaderExp_t IPLPARMS_SYSTEM_HEADER = {
    0xD1F0,   //id
    "IPLPMS", //name
    0x0058    //version
};

const hdatHeaderExp_t SPIRAH_HEADER = {
    0xD1F0,   //id
    "SPIRAH", //name
    0x0050    //version
};

const hdatHeaderExp_t SPIRAS_HEADER = {
    0xD1F0,   //id
    "SPIRAS", //name
    0x0050    //version
};

//big enough to hold all of PHYP
const uint64_t HDAT_MEM_SIZE = 128*MEGABYTE;

/********************
 Utility Functions
 ********************/

/**
 * @brief Verify that a block of memory falls inside a safe range
 * @param i_addr  Address to check
 * @param i_size  Number of bytes to check
 * @return Error if address seems wrong
 */
errlHndl_t hdatService::verify_hdat_address( const void* i_addr,
                                             size_t i_size )
{
    errlHndl_t errhdl = NULL;
    bool found = false;
    uint64_t l_end =  reinterpret_cast<uint64_t>(i_addr)
                       + i_size;

    // Make sure that the entire range is within the memory
    //  space that we allocated
    for(cmemRegionItr region = iv_mem_regions.begin();
        (region != iv_mem_regions.end()) && !found; ++region)
    {
        hdatMemRegion_t memR = *region;

        uint64_t l_range_end = reinterpret_cast<uint64_t>(memR.virt_addr)
                               +  memR.size;
        if ((i_addr >= memR.virt_addr) &&
            (l_end <= l_range_end))
        {
            found = true;
            break;
        }
    }

    if(!found)
    {
        TRACFCOMP( g_trac_runtime, "Invalid HDAT Address : i_addr=%p, i_size=0x%X", i_addr, i_size );
        for(cmemRegionItr region = iv_mem_regions.begin();
            (region != iv_mem_regions.end()) && !found; ++region)
        {
            hdatMemRegion_t memR = *region;
            TRACFCOMP( g_trac_runtime, "  Region : virt_addr=0x%X, size=0x%X",
                       memR.virt_addr, memR.size );
        }
        /*@
         * @errortype
         * @moduleid     RUNTIME::MOD_HDATSERVICE_VERIFY_HDAT_ADDRESS
         * @reasoncode   RUNTIME::RC_INVALID_ADDRESS
         * @userdata1    Start of address range under test
         * @userdata2    Size of address range under test
         * @devdesc      HDAT data block falls outside valid range
         */
        errhdl = new ERRORLOG::ErrlEntry(
                            ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                            RUNTIME::MOD_HDATSERVICE_VERIFY_HDAT_ADDRESS,
                            RUNTIME::RC_INVALID_ADDRESS,
                            reinterpret_cast<uint64_t>(i_addr),
                            reinterpret_cast<uint64_t>(i_size));
        errhdl->collectTrace(RUNTIME_COMP_NAME,KILOBYTE);

        // most likely this is a HB code bug
        errhdl->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                                    HWAS::SRCI_PRIORITY_HIGH);
        // but it could also be a FSP bug in setting up the HDAT data
        errhdl->addProcedureCallout(HWAS::EPUB_PRC_SP_CODE,
                                    HWAS::SRCI_PRIORITY_MED);
    }

    return errhdl;
}

errlHndl_t hdatService::check_header( const hdatHDIF_t* i_header,
                                      const hdatHeaderExp_t& i_exp )
{
    TRACUCOMP( g_trac_runtime, "check_header(%s)> %.4X : %.4X : %s", i_exp.name, i_header->hdatStructId, i_header->hdatVersion, i_header->hdatStructName );
    errlHndl_t errhdl = NULL;

    do
    {
        // Make sure the Tuple is pointing somewhere valid
        errhdl = verify_hdat_address( i_header,
                                      sizeof(hdatHDIF_t) );
        if( errhdl ) { break; }

        // Check version number but don't fail, this lets
        //  us handle minor changes more smoothly.  A major
        //  change should probably see a fail later on.
        if( i_header->hdatVersion != i_exp.version )
        {
            TRACFCOMP( g_trac_runtime, ERR_MRK "RUNTIME::check_header> Version not as expected for %s, continuing anyway. Act=%.4X, Exp=%.4X", i_exp.name, i_header->hdatVersion, i_exp.version );
        }

        // Check the ID, Version and Name
        if( (i_header->hdatStructId != i_exp.id)
            || memcmp(i_header->hdatStructName,i_exp.name,6) )
        {
            TRACFCOMP( g_trac_runtime, ERR_MRK "RUNTIME::check_header> HDAT Header data not as expected (id:version:name). Act=%.4X:%.4X:%s, Exp=%.4X:%.4X:%s", i_header->hdatStructId, i_header->hdatVersion, i_header->hdatStructName, i_exp.id, i_exp.version, i_exp.name );
            hdatHeaderExp_t actual;
            actual.id = i_header->hdatStructId;
            actual.version = i_header->hdatVersion;
            actual.name = i_header->hdatStructName;
            /*@
             * @errortype
             * @moduleid     RUNTIME::MOD_HDATSERVICE_CHECK_HEADER
             * @reasoncode   RUNTIME::RC_BAD_HDAT_HEADER
             * @userdata1[0:15]    Actual Header: id
             * @userdata1[16:31]   Actual Header: version
             * @userdata1[32:63]   Actual Header: name
             * @userdata2[0:15]    Expected Header: id
             * @userdata2[16:31]   Expected Header: version
             * @userdata2[32:63]   Expected Header: name
             * @devdesc      HDAT Header data not as expected
             */
            errhdl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                        RUNTIME::MOD_HDATSERVICE_CHECK_HEADER,
                                        RUNTIME::RC_BAD_HDAT_HEADER,
                                        actual.flatten(),
                                        i_exp.flatten());
            errhdl->addProcedureCallout( HWAS::EPUB_PRC_HB_CODE,
                                         HWAS::SRCI_PRIORITY_MED );
            errhdl->addProcedureCallout( HWAS::EPUB_PRC_SP_CODE,
                                         HWAS::SRCI_PRIORITY_MED );
            errhdl->collectTrace(RUNTIME_COMP_NAME,KILOBYTE);
            break;
        }
    } while(0);

    return errhdl;
}

errlHndl_t hdatService::check_tuple( const SectionId i_section,
                                     hdat5Tuple_t* i_tuple )
{
    errlHndl_t errhdl = NULL;

    do
    {
        // Make sure the Tuple is in valid memory
        errhdl = verify_hdat_address( i_tuple,
                                      sizeof(hdat5Tuple_t) );
        if( errhdl ) { break; }

        // Look for unallocated data
        if( (i_tuple->hdatAbsAddr == 0)
            || (i_tuple->hdatAllocCnt == 0)
            || (i_tuple->hdatAllocSize == 0) )
        {
            TRACFCOMP( g_trac_runtime, "check_tuple> Tuple for section %d is unallocated", i_section );
            /*@
             * @errortype
             * @moduleid     RUNTIME::MOD_HDATSERVICE_CHECK_TUPLE
             * @reasoncode   RUNTIME::RC_BAD_HDAT_TUPLE
             * @userdata1    Absolute address
             * @userdata2[0:31]   Allocated Count
             * @userdata2[32:63]   Allocated Size
             * @devdesc      Tuple is unallocated
             */
            errhdl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                         RUNTIME::MOD_HDATSERVICE_CHECK_TUPLE,
                                         RUNTIME::RC_BAD_HDAT_TUPLE,
                                         i_tuple->hdatAbsAddr,
                                         TWO_UINT32_TO_UINT64(
                                                      i_tuple->hdatAllocCnt,
                                                      i_tuple->hdatAllocSize));
            errhdl->addProcedureCallout( HWAS::EPUB_PRC_HB_CODE,
                                         HWAS::SRCI_PRIORITY_MED );
            errhdl->addProcedureCallout( HWAS::EPUB_PRC_SP_CODE,
                                         HWAS::SRCI_PRIORITY_MED );
            errhdl->collectTrace(RUNTIME_COMP_NAME,KILOBYTE);
            RUNTIME::UdTuple(i_tuple).addToLog(errhdl);
            break;
        }
    } while(0);

    return errhdl;
}


errlHndl_t hdatService::get_standalone_section(
                                               SectionId i_section,
                                               uint64_t i_instance,
                                               uint64_t& o_dataAddr,
                                               size_t& o_dataSize )
{
    errlHndl_t errhdl = NULL;

    if( RUNTIME::MS_DUMP_SRC_TBL == i_section )
    {
        o_dataAddr = reinterpret_cast<uint64_t>(iv_mem_regions[1].virt_addr);
        o_dataSize = DUMP_TEST_SRC_MEM_SIZE;
    }
    else if( RUNTIME::MS_DUMP_DST_TBL == i_section )
    {
        o_dataAddr = reinterpret_cast<uint64_t>(iv_mem_regions[1].virt_addr)
                     + DUMP_TEST_SRC_MEM_SIZE;
        o_dataSize = DUMP_TEST_DST_MEM_SIZE;
    }
    else if( RUNTIME::MS_DUMP_RESULTS_TBL == i_section )
    {
        o_dataAddr = reinterpret_cast<uint64_t>(iv_mem_regions[1].virt_addr)
                     + DUMP_TEST_SRC_MEM_SIZE + DUMP_TEST_DST_MEM_SIZE;
        o_dataSize = DUMP_TEST_RESULTS_MEM_SIZE;
    }
    else
    {
        TRACFCOMP( g_trac_runtime, "get_standalone_section> Section %d not valid in standalone mode", i_section );
        /*@
         * @errortype
         * @moduleid     RUNTIME::MOD_HDATSERVICE_GET_STANDALONE_SECTION
         * @reasoncode   RUNTIME::RC_INVALID_STANDALONE
         * @userdata1    Section ID
         * @userdata2    Section Instance Number
         * @devdesc      Section is not valid in standalone mode
         */
        errhdl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                          RUNTIME::MOD_HDATSERVICE_GET_STANDALONE_SECTION,
                          RUNTIME::RC_INVALID_STANDALONE,
                          i_section,
                          i_instance,
                          true /*Add HB Software Callout*/);
        errhdl->collectTrace(RUNTIME_COMP_NAME,KILOBYTE);
    }

    return errhdl;
}

hdatService::hdatService(void)
:iv_spiraL(NULL)
,iv_spiraH(NULL)
,iv_spiraS(NULL)
,iv_useRelocatedPayload(false)
{
    for( uint8_t id = static_cast<uint8_t>(RUNTIME::FIRST_SECTION);
         id <= static_cast<uint8_t>(RUNTIME::LAST_SECTION);
         id++ )
    {
        iv_actuals[id] = ACTUAL_NOT_SET;
    }
}

hdatService::~hdatService(void)
{
    rediscoverHDAT();
}

errlHndl_t hdatService::mapRegion(uint64_t i_addr, size_t i_bytes,
                                  uint64_t &o_vaddr)
{
    errlHndl_t errhdl = NULL;

    do
    {
        hdatMemRegion_t l_mem;

        l_mem.phys_addr = i_addr;
        l_mem.size = i_bytes;

        // make sure that our numbers are page-aligned, required by mm call
        l_mem.phys_addr = ALIGN_PAGE_DOWN(l_mem.phys_addr); //round down
        l_mem.size = ALIGN_PAGE(l_mem.size) + (4*KILOBYTE); //round up

        l_mem.virt_addr = mm_block_map(reinterpret_cast<void*>(l_mem.phys_addr),
                                        l_mem.size );
        TRACFCOMP( g_trac_runtime, "mapRegion> Mapped in 0x%X-0x%X (%X ) @ %p", l_mem.phys_addr,
                   l_mem.phys_addr+l_mem.size, l_mem.size, l_mem.virt_addr);

        if (NULL == l_mem.virt_addr)
        {
            TRACFCOMP( g_trac_runtime, "Failure calling mm_block_map : virt_addr=%p",
                       l_mem.virt_addr );
            /*@
             * @errortype
             * @moduleid     RUNTIME::MOD_HDATSERVICE_MAPREGION
             * @reasoncode   RUNTIME::RC_CANNOT_MAP_MEMORY
             * @userdata1    Starting Address
             * @userdata2    Size
             * @devdesc      Error mapping in memory
             */
            errhdl = new ERRORLOG::ErrlEntry(
                                        ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                        RUNTIME::MOD_HDATSERVICE_MAPREGION,
                                        RUNTIME::RC_CANNOT_MAP_MEMORY,
                                        l_mem.phys_addr,
                                        l_mem.size,
                                        true /*Add HB Software Callout*/);
            errhdl->collectTrace(RUNTIME_COMP_NAME,KILOBYTE);
            break;
        }

        iv_mem_regions.push_back(l_mem);
        o_vaddr = reinterpret_cast<uint64_t>(l_mem.virt_addr);
        o_vaddr = o_vaddr + (i_addr-l_mem.phys_addr);
    }while(0);

    return errhdl;
}

errlHndl_t hdatService::getSpiraTupleVA(hdat5Tuple_t* i_tuple,
                                     uint64_t & o_vaddr)
{
    errlHndl_t errhdl = NULL;
    bool found = false;
    o_vaddr = 0x0;
    uint64_t l_phys_addr, l_size;

    //PHYP and Sapphire have different philsophies about how they
    //lay the HDAT memory out.  PHYP puts it all within a 128MB
    //area.  Sapphire puts the NACA in one area and then all of the
    //SPIRA data sections in another (way up in memory).  This
    //function checks to see if the requested region is already
    //mapped, and if not it will map it.
    //
    //It then returns the "base" virtual pointer for the requested
    //tuple

    //Note that if Sapphire/PHYP change how they do things this
    //code will break (and the various address checking is expected
    //to catch it)

    do
    {
        // Get the absolute address = tuple addr + HRMOR (payload base)
        l_phys_addr = i_tuple->hdatAbsAddr + iv_mem_regions[0].phys_addr;
        l_size = i_tuple->hdatActualCnt * i_tuple->hdatActualSize;

        TRACUCOMP( g_trac_runtime, "SPIRA Data ptr 0x%X, size 0x%X",
                   l_phys_addr, l_size);

        //Check to see if the requested data fully falls within
        //an existing mapping if so do nothing
        for(memRegionItr region = iv_mem_regions.begin();
            (region != iv_mem_regions.end()) && !found; ++region)
        {
            hdatMemRegion_t memR = *region;

            if ((l_phys_addr >= memR.phys_addr) &&
                ((l_phys_addr + l_size) < (memR.phys_addr + memR.size)))
            {
                found = true;
                o_vaddr = reinterpret_cast<uint64_t>(memR.virt_addr);
                o_vaddr = o_vaddr + (l_phys_addr-memR.phys_addr);
                break;
            }
        }

        //if not found, then map it in
        if(!found)
        {
            TRACFCOMP( g_trac_runtime, "SPIRA Data @ 0x%X not mapped, mapping",
                       l_phys_addr);
            errhdl = mapRegion(l_phys_addr, l_size, o_vaddr);
            if(errhdl)
            {
                break;
            }
        }
    }while(0);

    TRACUCOMP( g_trac_runtime, "SPIRA Data Base Data ptr 0x%X", o_vaddr);


    return errhdl;
}

errlHndl_t hdatService::loadHostData(void)
{
    errlHndl_t errhdl = NULL;
    uint64_t l_dummy = 0x0;

    do
    {
        //if already loaded (mapping present) just exit
        if(0 != iv_mem_regions.size())
        {
            break;
        }

        // Call this routine to make sure we check the MNFG flags
        TARGETING::ATTR_PAYLOAD_KIND_type payload_kind =
          TARGETING::PAYLOAD_KIND_NONE;
        bool is_phyp = TARGETING::is_phyp_load(&payload_kind);
        TRACFCOMP( g_trac_runtime,
                   "PAYLOAD_KIND = %d (is_phyp=%d)",
                   payload_kind, is_phyp );

        TARGETING::Target * sys = NULL;
        TARGETING::targetService().getTopLevelTarget( sys );
        assert(sys != NULL);

#ifdef REAL_HDAT_TEST
        // Manually load HDAT memory now
        TRACFCOMP( g_trac_runtime, "Forcing PHYP mode for testing" );
        MAGIC_INSTRUCTION(MAGIC_BREAK);
        payload_kind = TARGETING::PAYLOAD_KIND_PHYP;
#endif

        //If PHYP or Sapphire
        if( (TARGETING::PAYLOAD_KIND_PHYP == payload_kind ) ||
            (TARGETING::PAYLOAD_KIND_SAPPHIRE == payload_kind ))
        {
            // PHYP
            TARGETING::ATTR_PAYLOAD_BASE_type payload_base
              = sys->getAttr<TARGETING::ATTR_PAYLOAD_BASE>();

            uint64_t hdat_start = payload_base*MEGABYTE;
            uint64_t hdat_size = HDAT_MEM_SIZE;

            // OPAL relocates itself after boot. Hence get relocated payload
            // address. If relocated address not available then use normal
            // base address (as OPAL would have crashed during early init).
            if (iv_useRelocatedPayload == true &&
                TARGETING::PAYLOAD_KIND_SAPPHIRE == payload_kind)
            {
                uint64_t reloc_base;

                reloc_base = TARGETING::AttrRP::getHbDataRelocPayloadAddr();
                if (reloc_base != 0)
                {
                    hdat_start = reloc_base;
                    TRACFCOMP( g_trac_runtime, "Relocated payload base =%p", hdat_start);
                }
                else
                {
                    TRACFCOMP( g_trac_runtime, "No relocated payload base found, continuing on");
                }
            }

#ifdef REAL_HDAT_TEST
            hdat_start = 256*MEGABYTE;
#endif
            // make sure that our numbers are page-aligned, expected by
            // rest of hdatservice code
            assert(hdat_start == ALIGN_PAGE(hdat_start));
            assert (hdat_size == ALIGN_PAGE(hdat_size));

            errhdl = mapRegion(hdat_start, hdat_size, l_dummy);
        }
        else if( TARGETING::PAYLOAD_KIND_NONE == payload_kind )
        {
            // Standalone Test Image with no payload
            FakePayload::load();

            // Map in some arbitrary memory for the HostServices code to use
            TRACFCOMP( g_trac_runtime, "load_host_data> STANDALONE: Mapping in 0x%X-0x%X (%d MB)", VMM_ATTR_DATA_START_OFFSET,
                VMM_ATTR_DATA_START_OFFSET+VMM_ATTR_DATA_SIZE,
                VMM_ATTR_DATA_SIZE);

            errhdl = mapRegion(VMM_ATTR_DATA_START_OFFSET,
                               VMM_ATTR_DATA_SIZE, l_dummy);
            if(errhdl)
            {
                break;
            }

            // Map in some arbitrary memory for the DumpTest code to use
            TRACFCOMP( g_trac_runtime, "load_host_data> STANDALONE: Mapping in 0x%X-0x%X (%d MB)", DUMP_TEST_MEMORY_ADDR,
                DUMP_TEST_MEMORY_ADDR+DUMP_TEST_MEMORY_SIZE,
                DUMP_TEST_MEMORY_SIZE);

            errhdl = mapRegion(DUMP_TEST_MEMORY_ADDR,
                               DUMP_TEST_MEMORY_SIZE, l_dummy);
            if(errhdl)
            {
                break;
            }
        }
        else
        {
            TRACFCOMP( g_trac_runtime, "load_host_data> No host data to load for payload %d", payload_kind );
            break;
        }


    } while(0);

    return errhdl;
}

errlHndl_t hdatService::getHostDataSection( SectionId i_section,
                                            uint64_t i_instance,
                                            uint64_t& o_dataAddr,
                                            size_t& o_dataSize)
{
    errlHndl_t errhdl = NULL;
    TRACFCOMP( g_trac_runtime, ENTER_MRK"getHostDataSection> i_section=%d, i_instance=%d", i_section, i_instance );

    do
    {
        // Force the answer to zero in case of failure
        o_dataAddr = 0;

        //Always force a load (mapping)
        errhdl = loadHostData();
        if(errhdl)
        {
            break;
        }

        //Store record size for later
        size_t record_size = 0;

        TARGETING::Target * sys = NULL;
        TARGETING::targetService().getTopLevelTarget( sys );
        assert(sys != NULL);

        // Figure out what kind of payload we have
        TARGETING::PAYLOAD_KIND payload_kind
          = sys->getAttr<TARGETING::ATTR_PAYLOAD_KIND>();

#ifdef REAL_HDAT_TEST
        TRACFCOMP( g_trac_runtime, "Forcing PHYP mode for testing" );
        payload_kind = TARGETING::PAYLOAD_KIND_PHYP;
#endif

        hdat5Tuple_t* tuple = nullptr;

        if( TARGETING::PAYLOAD_KIND_NONE == payload_kind )
        {
            errhdl = get_standalone_section( i_section,
                                             i_instance,
                                             o_dataAddr,
                                             o_dataSize );
            // we're all done
            break;
        }
        //If payload is not (PHYP or Sapphire)
        else if( !((TARGETING::PAYLOAD_KIND_PHYP == payload_kind ) ||
            (TARGETING::PAYLOAD_KIND_SAPPHIRE == payload_kind )))
        {
            TRACFCOMP( g_trac_runtime, "getHostDataSection> There is no host data for PAYLOAD_KIND=%d", payload_kind );
            /*@
             * @errortype
             * @moduleid     RUNTIME::MOD_HDATSERVICE_GETHOSTDATASECTION
             * @reasoncode   RUNTIME::RC_INVALID_PAYLOAD_KIND
             * @userdata1    ATTR_PAYLOAD_KIND
             * @userdata2    Requested Section
             * @devdesc      There is no host data for specified kind of payload
             */
            errhdl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                              RUNTIME::MOD_HDATSERVICE_GETHOSTDATASECTION,
                              RUNTIME::RC_INVALID_PAYLOAD_KIND,
                              payload_kind,
                              i_section,
                              true /*Add HB Software Callout*/);
            errhdl->collectTrace(RUNTIME_COMP_NAME,KILOBYTE);
            break;
        }

        // Go fetch the relative zero address that PHYP uses
        // This is always the first entry in the vector
        uint64_t payload_base =
          reinterpret_cast<uint64_t>(iv_mem_regions[0].virt_addr);

        // Setup the SPIRA pointers
        errhdl = findSpira();
        if( errhdl ) { break; }

        // NACA
        if( RUNTIME::NACA == i_section )
        {
            o_dataAddr = reinterpret_cast<uint64_t>(payload_base);
            o_dataAddr += HDAT_NACA_OFFSET;
            o_dataSize = sizeof(hdatNaca_t);
        }
        // SPIRA-H
        else if( (RUNTIME::SPIRA_H == i_section) && iv_spiraH )
        {
            o_dataAddr = reinterpret_cast<uint64_t>(iv_spiraH);
            if( iv_spiraH )
            {
                o_dataSize = iv_spiraH->hdatHDIF.hdatSize;
            }
            else
            {
                o_dataSize = 0;
            }
        }
        // SPIRA-S
        else if( (RUNTIME::SPIRA_S == i_section) && iv_spiraS )
        {
            o_dataAddr = reinterpret_cast<uint64_t>(iv_spiraS);
            if( iv_spiraS )
            {
                o_dataSize = iv_spiraS->hdatHDIF.hdatSize;
            }
            else
            {
                o_dataSize = 0;
            }
        }
        // Legacy SPIRA
        else if( (RUNTIME::SPIRA_L == i_section) && iv_spiraL )
        {
            o_dataAddr = reinterpret_cast<uint64_t>(iv_spiraL);
            if( iv_spiraL )
            {
                o_dataSize = iv_spiraL->hdatHDIF.hdatSize;
            }
            else
            {
                o_dataSize = 0;
            }
        }
        else if (RUNTIME::RESERVED_MEM == i_section)
        {
            hdatMsReservedMemArrayHeader_t* reservedMemArrayHeader = nullptr;
            errhdl = getResvMemArrHdr(reservedMemArrayHeader);
            if( errhdl ) { break; }

            // get the total number of entries per node in the hostboot
            // reserved memory area, since we are using the instance num
            // as an index into the reserved mem array, make sure
            // the passed in instance is within the array boundary
            uint64_t l_maxArrayIndex =
                reservedMemArrayHeader->arrayEntryCount -1;
            if( i_instance > l_maxArrayIndex )
            {
                TRACFCOMP( g_trac_runtime, "Instance %d exceeds max reserved mem entry index %d",
                          i_instance, l_maxArrayIndex );
                /*@
                 * @errortype
                 * @moduleid     RUNTIME::MOD_HDATSERVICE_GETHOSTDATASECTION
                 * @reasoncode   RUNTIME::RC_INVALID_RHB_INSTANCE
                 * @userdata1    Requested instance (reserved mem array index)
                 * @userdata2    maximum array index allowed
                 * @devdesc      Invalid instance requested for Reserved
                 *               Hostboot Memory section
                 * @custdesc     Firmware error during boot
                 */
                errhdl = new ERRORLOG::ErrlEntry(
                                ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                RUNTIME::MOD_HDATSERVICE_GETHOSTDATASECTION,
                                RUNTIME::RC_INVALID_RHB_INSTANCE,
                                i_instance,
                                l_maxArrayIndex,
                                true /*Add HB Software Callout*/);
                errhdl->collectTrace(RUNTIME_COMP_NAME,KILOBYTE);
                break;
            }

            //Array Header addr
            o_dataAddr = reinterpret_cast<uint64_t>(
                reinterpret_cast<uint64_t>(reservedMemArrayHeader) +
                reservedMemArrayHeader->offsetToArray +
                (i_instance * reservedMemArrayHeader->entrySize));
            //Array Header size
            o_dataSize = reservedMemArrayHeader->entrySize;
        }
        // HB Runtime Data
        else if ( (RUNTIME::HBRT        == i_section) ||
                  (RUNTIME::HBRT_DATA   == i_section) )
        {
            // Data section requires drilling to dataBlob
            bool l_needBlob = (RUNTIME::HBRT_DATA == i_section);

            // Find the right tuple and verify it makes sense
            errhdl = getAndCheckTuple(i_section, tuple);
            if( errhdl ) { break; }
            TRACUCOMP(g_trac_runtime, "HBRT_DATA tuple=%p", tuple);

            uint64_t base_addr;
            errhdl = getSpiraTupleVA(tuple, base_addr);
            if( errhdl ) { break; }

            hdatHDIF_t* hbrt_header =
              reinterpret_cast<hdatHDIF_t*>(base_addr);
            TRACUCOMP( g_trac_runtime, "hbrt_header=%p", hbrt_header );

            // Check the headers and version info
            errhdl = check_header( hbrt_header,
                                   HBRT_DATA_HEADER );
            if( errhdl ) { break; }

            hdatHDIFDataHdr_t* hbrt_data_header =
              reinterpret_cast<hdatHDIFDataHdr_t*>
              (hbrt_header->hdatDataPtrOffset + base_addr);

            TRACUCOMP( g_trac_runtime, "hbrt_data_header=%p", hbrt_data_header );
            // Make sure the Data Header is pointing somewhere valid
            errhdl = verify_hdat_address( (hbrt_data_header + i_instance),
                                          sizeof(hdatHDIFDataHdr_t) );
            if( errhdl ) { break; }

            o_dataAddr = hbrt_data_header[i_instance].hdatOffset + base_addr;
            o_dataSize = hbrt_data_header[i_instance].hdatSize;

            if (l_needBlob)
            {
                // For accessing pointer to various RT data
                hdatHBRT_t* l_hbrtPtr =
                    reinterpret_cast<hdatHBRT_t *>(o_dataAddr);
                o_dataAddr = l_hbrtPtr->hdatDataBlob.hdatOffset + base_addr;
                o_dataSize = l_hbrtPtr->hdatDataBlob.hdatSize;
            } // end if getting dataBlob
        }

        // IPL Parameters : System Parameters
        else if( RUNTIME::IPLPARMS_SYSTEM == i_section )
        {
            // Find the right tuple and verify it makes sense
            errhdl = getAndCheckTuple(i_section, tuple);
            if( errhdl ) { break; }
            TRACUCOMP( g_trac_runtime, "IPLPARMS_SYSTEM tuple=%p", tuple );

            uint64_t base_addr;
            errhdl = getSpiraTupleVA(tuple, base_addr);
            if( errhdl ) { break; }

            hdatHDIF_t* ipl_parms = reinterpret_cast<hdatHDIF_t*>
              (base_addr);
            TRACUCOMP( g_trac_runtime, "ipl_parms=%p", ipl_parms );

            // Check the headers and version info
            errhdl = check_header( ipl_parms,
                                   IPLPARMS_SYSTEM_HEADER );
            if( errhdl ) { break; }

            hdatHDIFDataHdr_t* internal_data_ptrs =
              reinterpret_cast<hdatHDIFDataHdr_t*>
              (ipl_parms->hdatDataPtrOffset + base_addr);
            TRACUCOMP( g_trac_runtime, "internal_data_ptrs=%p", internal_data_ptrs );
            // Make sure the Header is pointing somewhere valid
            errhdl = verify_hdat_address( internal_data_ptrs,
                                          sizeof(hdatHDIFDataHdr_t) );
            if( errhdl ) { break; }

            //System Parms are index 0
            o_dataAddr = internal_data_ptrs[0].hdatOffset + base_addr;
            o_dataSize = internal_data_ptrs[0].hdatSize;
        }
        else if( RUNTIME::NODE_TPM_RELATED == i_section )
        {
            // Find the right tuple and verify it makes sense
            errhdl = getAndCheckTuple(i_section, tuple);
            if( errhdl ) { break; }
            TRACUCOMP( g_trac_runtime, "NODE_TPM_DATA tuple=%p", tuple );

            uint64_t base_addr = 0;
            errhdl = getSpiraTupleVA(tuple, base_addr);
            if( errhdl ) { break; }

            TRACUCOMP( g_trac_runtime, "tpm_data=%p", base_addr );

            // set the base address and size for the section
            record_size = tuple->hdatAllocSize;
            o_dataSize = record_size;
            o_dataAddr = base_addr + i_instance * o_dataSize;
        }
        else if( RUNTIME::PCRD == i_section )
        {
            // Find the right tuple and verify it makes sense
            errhdl = getAndCheckTuple(i_section, tuple);
            if( errhdl ) { break; }
            TRACUCOMP( g_trac_runtime, "PCRD_DATA tuple=%p", tuple );

            uint64_t base_addr = 0;
            errhdl = getSpiraTupleVA(tuple, base_addr);
            if( errhdl )
            {
                break;
            }

            TRACUCOMP( g_trac_runtime, "pcrd_data=%p", base_addr );

            record_size = tuple->hdatAllocSize;
            o_dataSize = record_size;
            o_dataAddr = base_addr + i_instance * o_dataSize;
        }
        // MS DUMP Source Table - MDST
        else if( RUNTIME::MS_DUMP_SRC_TBL == i_section )
        {
            //For security we can't trust the FSP's payload attribute
            //  on MPIPLs for the dump tables.
            //@todo: RTC:59171

            // Find the right tuple and verify it makes sense
            errhdl = getAndCheckTuple(i_section, tuple);
            if( errhdl ) { break; }
            TRACUCOMP( g_trac_runtime, "MS_DUMP_SRC_TBL tuple=%p", tuple );

            //Note - there is no header for the MDST
            o_dataSize = tuple->hdatActualCnt * tuple->hdatActualSize;
            record_size = tuple->hdatActualSize;
            errhdl = getSpiraTupleVA(tuple, o_dataAddr);
            if( errhdl ) { break; }
       }
        // MS DUMP Destination Table - MDDT
        else if( RUNTIME::MS_DUMP_DST_TBL == i_section )
        {
            //For security we can't trust the FSP's payload attribute
            //  on MPIPLs for the dump tables.
            //@todo: RTC:59171

            // Find the right tuple and verify it makes sense
            errhdl = getAndCheckTuple(i_section, tuple);
            if( errhdl ) { break; }
            TRACUCOMP( g_trac_runtime, "MS_DUMP_DST_TBL tuple=%p", tuple );


            //Note - there is no header for the MDDT
            o_dataSize = tuple->hdatActualCnt * tuple->hdatActualSize;
            record_size = tuple->hdatActualSize;
            errhdl = getSpiraTupleVA(tuple, o_dataAddr);
            if( errhdl ) { break; }
        }
        // MS DUMP Results Table - MDRT
        else if( RUNTIME::MS_DUMP_RESULTS_TBL == i_section )
        {
            //For security we can't trust the FSP's payload attribute
            //  on MPIPLs for the dump tables.
            //@todo: RTC:59171

            // Find the right tuple and verify it makes sense
            errhdl = getAndCheckTuple(i_section, tuple);
            if( errhdl ) { break; }
            TRACUCOMP( g_trac_runtime, "MS_DUMP_RESULTS_TBL tuple=%p", tuple );

            //Note - there is no header for the MDRT
            //return the total allocated size since it is empty at first
            o_dataSize = tuple->hdatAllocSize * tuple->hdatAllocCnt;
            record_size = tuple->hdatAllocSize;
            errhdl = getSpiraTupleVA(tuple, o_dataAddr);
            if( errhdl ) { break; }

        }
        // Processor Dump Area table
        else if( RUNTIME::PROC_DUMP_AREA_TBL == i_section )
        {
            // Find the right tuple and verify it makes sense
            errhdl = getAndCheckTuple(i_section, tuple);
            if( errhdl ) { break; }
            TRACUCOMP( g_trac_runtime, "PROCESSOR_DUMP_AREA_TBL tuple=%p", tuple );

            //Note - there is no header for the Processor dump area table
            //return the total allocated size since it is empty at first
            o_dataSize = tuple->hdatAllocSize * tuple->hdatAllocCnt;
            record_size = tuple->hdatAllocSize;
            errhdl = getSpiraTupleVA(tuple, o_dataAddr);
            if( errhdl ) { break; }
        }
        else if( RUNTIME::HRMOR_STASH == i_section )
        {
            //Look up the tuple that this section is located in
            errhdl = getAndCheckTuple(i_section, tuple);
            if( errhdl) {break; }

            TRACUCOMP( g_trac_runtime, "HRMOR_STASH tuple=%p", tuple );
            uint64_t base_addr = 0;
            //Find the virtual address of the tuple we found
            errhdl = getSpiraTupleVA(tuple, base_addr);
            if( errhdl ) { break; }

            //Set up the MDT(memory description tree) header
            //(see hdatstructs.H and 11.2.1 MS Area Structure)
            hdatHDIF_t* mdt_header =
            reinterpret_cast<hdatHDIF_t*>(base_addr);

            // Check the headers and version info
            errhdl = check_header( mdt_header,
                                   MDT_HEADER );
            if( errhdl ) { break; }

            //Array of ptrs to different subsections of the MDT
            hdatHDIFDataHdr_t* mdt_data_ptrs =
              reinterpret_cast<hdatHDIFDataHdr_t*>
              (mdt_header->hdatDataPtrOffset + base_addr);

            //ensure the memory range we are passing out is valid hdat address space
            errhdl = verify_hdat_address(mdt_data_ptrs,
                            mdt_header->hdatDataPtrCnt * sizeof(hdatHDIFDataHdr_t) );
            if( errhdl ) { break; }

            //The address passed out will point to where hostboot can store an
            //address that PHYP can look up to figure out where to write the HRMOR
            //when it changes
            o_dataAddr = mdt_data_ptrs[MDT_MAINSTORE_ADDR_SECTION].hdatOffset +            // offset to ms addr section
                                       base_addr +                                         // base of hdat
                                       MDT_MAINSTORE_ADDR_SECTION_HYP_HB_COMM_ADDR_OFFSET; // 0x1C

            o_dataSize = MDT_MAINSTORE_ADDR_SECTION_HYP_HB_COMM_ADDR_SIZE; // 8 bytes

        }
        // SPIRA-H CPU Controls
        else if ( RUNTIME::CPU_CTRL == i_section )
        {
            // Find the right tuple and verify it makes sense
            errhdl = getAndCheckTuple(i_section, tuple);
            if( errhdl )
            {
                break;
            }
            TRACDCOMP( g_trac_runtime, "CPU_CTRL tuple=%p", tuple );

            uint64_t base_addr = 0;
            errhdl = getSpiraTupleVA(tuple, base_addr);
            if( errhdl )
            {
                break;
            }

            TRACDCOMP( g_trac_runtime, "cpu_ctrl_data=%p", base_addr );

            // set the base address and size for the section
            record_size = tuple->hdatActualSize;
            o_dataSize = record_size;
            o_dataAddr = base_addr;
        }
        // Not sure how we could get here...
        else
        {
            TRACFCOMP( g_trac_runtime, "getHostDataSection> Unknown section %d", i_section );
            /*@
             * @errortype
             * @moduleid     RUNTIME::MOD_HDATSERVICE_GETHOSTDATASECTION
             * @reasoncode   RUNTIME::RC_INVALID_SECTION
             * @userdata1    Section Id
             * @userdata2    <unused>
             * @devdesc      Unknown section requested
             */
            errhdl = new ERRORLOG::ErrlEntry(
                           ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                           RUNTIME::MOD_HDATSERVICE_GETHOSTDATASECTION,
                           RUNTIME::RC_INVALID_SECTION,
                           i_section,
                           0,
                           true /*Add HB Software Callout*/);
            errhdl->collectTrace(RUNTIME_COMP_NAME,KILOBYTE);
            break;
        }

        // Make sure the range we return is pointing somewhere valid
        errhdl = verify_hdat_address( reinterpret_cast<void*>(o_dataAddr),
                                      o_dataSize );
        if( errhdl ) { break; }

        // Override the data size value if we've got a stored actual
        if( iv_actuals[i_section] != ACTUAL_NOT_SET )
        {
            TRACFCOMP( g_trac_runtime, "getHostDataSection> Data size overridden from %d->%d", o_dataSize, iv_actuals[i_section] );
            o_dataSize = iv_actuals[i_section] * record_size;
        }
    } while(0);

    TRACFCOMP( g_trac_runtime, EXIT_MRK"getHostDataSection> o_dataAddr=0x%X, o_dataSize=%d", o_dataAddr, o_dataSize );

    return errhdl;
}

/**
 * @brief Locates the proper SPIRA structure and sets instance vars
 */
errlHndl_t hdatService::findSpira( void )
{
    errlHndl_t errhdl = NULL;
    errlHndl_t errhdl_s = NULL; //SPIRA-S error
    errlHndl_t errhdl_l = NULL; //Legacy SPIRA error

    do {
        // Only do this once
        if( iv_spiraL || iv_spiraH || iv_spiraS )
        {
            break;
        }

        // Go fetch the relative zero address that PHYP uses
        // This is always the first entry in the vector
        uint64_t payload_base =
          reinterpret_cast<uint64_t>(iv_mem_regions[0].virt_addr);

        // Everything starts at the NACA
        //   The NACA is part of the platform dependent LID which
        //   is loaded at relative memory address 0x0
        hdatNaca_t* naca = reinterpret_cast<hdatNaca_t*>
          (HDAT_NACA_OFFSET + payload_base);
        TRACFCOMP( g_trac_runtime, "NACA=%.X->%p", HDAT_NACA_OFFSET, naca );

        // Do some sanity checks on the NACA
        if( naca->nacaPhypPciaSupport != 1 )
        {
            TRACFCOMP( g_trac_runtime, "findSpira> nacaPhypPciaSupport=%.8X", naca->nacaPhypPciaSupport );

            // Figure out what kind of payload we have
            TARGETING::Target * sys = NULL;
            TARGETING::targetService().getTopLevelTarget( sys );
            TARGETING::PAYLOAD_KIND payload_kind
              = sys->getAttr<TARGETING::ATTR_PAYLOAD_KIND>();

            // Go get the physical address we mapped in
            uint64_t phys_addr =
              mm_virt_to_phys(reinterpret_cast<void*>(naca));

            /*@
             * @errortype
             * @moduleid     RUNTIME::MOD_HDATSERVICE_FINDSPIRA
             * @reasoncode   RUNTIME::RC_BAD_NACA
             * @userdata1    Mainstore address of NACA
             * @userdata2[0:31]    Payload Base Address
             * @userdata2[32:63]   Payload Kind
             * @devdesc      NACA data doesn't seem right
             */
            errhdl = new ERRORLOG::ErrlEntry(
                            ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                            RUNTIME::MOD_HDATSERVICE_FINDSPIRA,
                            RUNTIME::RC_BAD_NACA,
                            reinterpret_cast<uint64_t>(phys_addr),
                            TWO_UINT32_TO_UINT64(payload_base,
                                                 payload_kind));
            errhdl->addProcedureCallout( HWAS::EPUB_PRC_HB_CODE,
                                         HWAS::SRCI_PRIORITY_MED );
            errhdl->addProcedureCallout( HWAS::EPUB_PRC_SP_CODE,
                                         HWAS::SRCI_PRIORITY_MED );
            errhdl->collectTrace(RUNTIME_COMP_NAME,KILOBYTE);
            RUNTIME::UdNaca(naca).addToLog(errhdl);
            break;
        }


        // Are we using the SPIRA-H/S or Legacy format
        if( naca->spiraH != 0 )
        {
            // pointer is also relative to PHYP's zero
            iv_spiraH = reinterpret_cast<hdatSpira_t*>
              (naca->spiraH + payload_base);
            TRACFCOMP( g_trac_runtime, "SPIRA-H=%X->%p", naca->spiraH, iv_spiraH );

            // Check the headers and version info
            errhdl = check_header( &(iv_spiraH->hdatHDIF),
                                   SPIRAH_HEADER );
            if( errhdl )
            {
                RUNTIME::UdNaca(naca).addToLog(errhdl);
                break;
            }

            // SPIRA-S is at the beginning of the Host Data Area Tuple
            uint64_t tuple_addr = reinterpret_cast<uint64_t>
              (&(iv_spiraH->hdatDataArea[SPIRAH_HOST_DATA_AREAS]));
            TRACUCOMP( g_trac_runtime, "SPIRA-S tuple offset=%.8X", tuple_addr );
            // need to offset from virtual zero
            //tuple_addr += payload_base;
            hdat5Tuple_t* tuple = reinterpret_cast<hdat5Tuple_t*>(tuple_addr);
            TRACUCOMP( g_trac_runtime, "SPIRA-S tuple=%p", tuple );

            errlHndl_t errhdl_s = check_tuple( SPIRA_S,
                                               tuple );
            if( errhdl_s )
            {
                TRACFCOMP( g_trac_runtime, "SPIRA-S is invalid, will try legacy SPIRA" );
                RUNTIME::UdNaca(naca).addToLog(errhdl_s);
                iv_spiraS = NULL;
            }
            else
            {
                uint64_t tmp_addr = 0;
                errhdl_s = getSpiraTupleVA( tuple, tmp_addr );
                if( errhdl_s )
                {
                    TRACFCOMP( g_trac_runtime, "Couldn't map SPIRA-S, will try legacy SPIRA" );
                    iv_spiraS = NULL;
                }
                else
                {
                    iv_spiraS = reinterpret_cast<hdatSpira_t*>(tmp_addr);
                    TRACFCOMP( g_trac_runtime, "SPIRA-S=%p", iv_spiraS );

                    // Check the headers and version info
                    errhdl_s = check_header( &(iv_spiraS->hdatHDIF),
                                             SPIRAS_HEADER );
                    if( errhdl_s )
                    {
                        TRACFCOMP( g_trac_runtime, "SPIRA-S is invalid, will try legacy SPIRA" );
                        RUNTIME::UdNaca(naca).addToLog(errhdl_s);
                        RUNTIME::UdSpira(iv_spiraS).addToLog(errhdl_s);
                        iv_spiraS = NULL;
                    }
                }
            }
        }

        //Legacy SPIRA
        // pointer is also relative to PHYP's zero
        iv_spiraL = reinterpret_cast<hdatSpira_t*>
          (naca->spiraOld + payload_base);
        TRACFCOMP( g_trac_runtime, "Legacy SPIRA=%X->%p", naca->spiraOld, iv_spiraL );

        // Make sure the SPIRA is valid
        errhdl_l = verify_hdat_address( iv_spiraL,
                                        sizeof(hdatSpira_t) );
        if( errhdl_l )
        {
            TRACFCOMP( g_trac_runtime, "Legacy Spira is at a wacky offset!!! %.16X", naca->spiraOld );
            iv_spiraL = NULL;
            RUNTIME::UdNaca(naca).addToLog(errhdl_l);
        }
        else
        {
            // Look for a filled in HEAP section to see if FSP is using the
            //  new or old format
            // (Note: this is the logic PHYP is using)
            hdat5Tuple_t* heap_tuple = &(iv_spiraL->hdatDataArea[SPIRAL_HEAP]);
            TRACUCOMP( g_trac_runtime, "HEAP tuple=%p", heap_tuple );
            if( heap_tuple->hdatActualSize == 0 )
            {
                TRACFCOMP( g_trac_runtime, "Legacy SPIRA is not filled in, using SPIRA-H/S" );
                iv_spiraL = NULL;
            }
            else
            {
                TRACFCOMP( g_trac_runtime, "Legacy SPIRA is filled in so we'll use it" );
                iv_spiraS = NULL;
            }
        }

        // Make sure we have a good SPIRA somewhere
        if( (iv_spiraL == NULL) && (iv_spiraS == NULL) )
        {
            TRACFCOMP( g_trac_runtime, "Could not find a valid SPIRA of any type" );
            /*@
             * @errortype
             * @moduleid     RUNTIME::MOD_HDATSERVICE_FINDSPIRA
             * @reasoncode   RUNTIME::RC_NO_SPIRA
             * @userdata1[0:31]    RC for Legacy SPIRA fail
             * @userdata1[32:64]   EID for Legacy SPIRA fail
             * @userdata2[0:31]    RC for SPIRA-S fail
             * @userdata2[32:64]   EID for SPIRA-S fail
             * @devdesc      Could not find a valid SPIRA of any type
             */
            errhdl = new ERRORLOG::ErrlEntry(
                           ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                           RUNTIME::MOD_HDATSERVICE_FINDSPIRA,
                           RUNTIME::RC_NO_SPIRA,
                           TWO_UINT32_TO_UINT64(ERRL_GETRC_SAFE(errhdl_l),
                                                ERRL_GETEID_SAFE(errhdl_l)),
                           TWO_UINT32_TO_UINT64(ERRL_GETRC_SAFE(errhdl_s),
                                                ERRL_GETEID_SAFE(errhdl_s)));
            errhdl->addProcedureCallout( HWAS::EPUB_PRC_HB_CODE,
                                         HWAS::SRCI_PRIORITY_MED );
            errhdl->addProcedureCallout( HWAS::EPUB_PRC_SP_CODE,
                                         HWAS::SRCI_PRIORITY_MED );
            errhdl->collectTrace(RUNTIME_COMP_NAME,KILOBYTE);

            // commit the errors related to each SPIRA
            if( errhdl_s )
            {
                errhdl_s->plid(errhdl->plid());
                errlCommit(errhdl_s,RUNTIME_COMP_ID);
            }
            if( errhdl_l )
            {
                errhdl_l->plid(errhdl->plid());
                errlCommit(errhdl_l,RUNTIME_COMP_ID);
            }

            // return the summary log
            break;
        }
    } while(0);

    if( errhdl_s ) { delete errhdl_s; errhdl_s = nullptr;}
    if( errhdl_l ) { delete errhdl_l; errhdl_l = nullptr; }

    return errhdl;
}

errlHndl_t hdatService::updateHostProcDumpActual( SectionId i_section,
                                                  uint32_t threadRegSize,
                                                  uint8_t threadRegVersion)
{
    errlHndl_t errhdl = nullptr;
    TRACFCOMP( g_trac_runtime,
               "RUNTIME::updateHostProcDumpActual ( i_section=%d )", i_section);

    do
    {
        uint64_t l_hostDataAddr = 0;
        uint64_t l_hostDataSize = 0;
        DUMP::procDumpAreaEntry *procDumpTable = nullptr;

        // Get proc dump area ntuple address
        errhdl = getHostDataSection(i_section, 0,
                                    l_hostDataAddr, l_hostDataSize);
        if (errhdl)
        {
            TRACFCOMP( g_trac_runtime, "updateHostProcDumpActual> Failed to "
                       "get host data section (i_section=%d )", i_section);
            break;
        }

        procDumpTable = reinterpret_cast<DUMP::procDumpAreaEntry *>(l_hostDataAddr);
        procDumpTable->threadRegSize    = threadRegSize;
        procDumpTable->threadRegVersion = threadRegVersion;
    } while(0);

    return errhdl;
}

errlHndl_t hdatService::updateHostDataSectionActual( SectionId i_section,
                                                     uint16_t i_count )
{
    errlHndl_t errhdl = NULL;
    TRACFCOMP( g_trac_runtime, "RUNTIME::updateHostDataSectionActual( i_section=%d )", i_section);

    do
    {
        //Always force a load (mapping)
        errhdl = loadHostData();
        if(errhdl)
        {
            break;
        }

        TARGETING::Target * sys = NULL;
        TARGETING::targetService().getTopLevelTarget( sys );
        assert(sys != NULL);

        // Figure out what kind of payload we have
        TARGETING::PAYLOAD_KIND payload_kind
          = sys->getAttr<TARGETING::ATTR_PAYLOAD_KIND>();

        if( TARGETING::PAYLOAD_KIND_NONE == payload_kind )
        {
            // we're all done -- don't need to do anything
            break;
        }
        //If payload is not (PHYP or Sapphire)
        else if( !((TARGETING::PAYLOAD_KIND_PHYP == payload_kind ) ||
                   (TARGETING::PAYLOAD_KIND_SAPPHIRE == payload_kind )))
        {
            TRACFCOMP( g_trac_runtime, "updateHostDataSectionActual> There is no host data for PAYLOAD_KIND=%d", payload_kind );
            /*@
             * @errortype
             * @moduleid     RUNTIME::MOD_HDATSERVICE_UPDATE_SECTION_ACTUAL
             * @reasoncode   RUNTIME::RC_INVALID_PAYLOAD_KIND
             * @userdata1    ATTR_PAYLOAD_KIND
             * @userdata2    Requested Section
             * @devdesc      There is no host data for specified kind of payload
             */
            errhdl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                              RUNTIME::MOD_HDATSERVICE_UPDATE_SECTION_ACTUAL,
                              RUNTIME::RC_INVALID_PAYLOAD_KIND,
                              payload_kind,
                              i_section,
                              true /*Add HB Software Callout*/);
            errhdl->collectTrace(RUNTIME_COMP_NAME,KILOBYTE);
            break;
        }

        // Setup the SPIRA pointers
        errhdl = findSpira();
        if( errhdl ) { break; }


        // MS DUMP Results Table - MDRT
        if( RUNTIME::MS_DUMP_RESULTS_TBL == i_section )
        {
            //For security we can't trust the FSP's payload attribute
            //  on MPIPLs for the dump tables.
            //@todo: RTC:59171

            // Find the right tuple and verify it makes sense
            hdat5Tuple_t* tuple = NULL;
            if( iv_spiraH )
            {
                tuple = &(iv_spiraH->hdatDataArea[SPIRAH_MS_DUMP_RSLT_TBL]);
            }
            else if( unlikely(iv_spiraL != NULL) )
            {
                tuple = &(iv_spiraL->hdatDataArea[SPIRAL_MS_DUMP_RSLT_TBL]);
            }
            TRACFCOMP( g_trac_runtime, "MS_DUMP_RESULTS_TBL tuple=%p, count=%x", tuple, i_count);
            errhdl = check_tuple( i_section,
                                  tuple );
            if( errhdl ) { break; }

            tuple->hdatActualCnt = i_count;
        }
        // Not sure how we could get here...
        else
        {
            TRACFCOMP( g_trac_runtime, "updateHostDataSectionActual> Unknown section %d", i_section );
            /*@
             * @errortype
             * @moduleid     RUNTIME::MOD_HDATSERVICE_UPDATE_SECTION_ACTUAL
             * @reasoncode   RUNTIME::RC_INVALID_SECTION
             * @userdata1    Section Id
             * @userdata2    <unused>
             * @devdesc      Unknown section requested
             */
            errhdl = new ERRORLOG::ErrlEntry(
                           ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                           RUNTIME::MOD_HDATSERVICE_UPDATE_SECTION_ACTUAL,
                           RUNTIME::RC_INVALID_SECTION,
                           i_section,
                           0,
                           true /*Add HB Software Callout*/);
            errhdl->collectTrace(RUNTIME_COMP_NAME,KILOBYTE);
            break;
        }

        if( errhdl ) { break; }

    } while(0);

    return errhdl;
}

/**
 * @brief  Retrieve and log FFDC data relevant to a given section of
 *         host data memory
 */
void hdatService::addFFDC( SectionId i_section,
                           errlHndl_t& io_errlog )
{
    uint64_t addr = 0;
    uint64_t size = 0;
    errlHndl_t errlog = nullptr;

    if( RUNTIME::NACA == i_section )
    {
        errlog = getHostDataSection( NACA, 0, addr, size );
        if( errlog )
        {
            delete errlog;
            errlog = nullptr;
        }
        else if( (addr != 0) && (size != 0) )
        {
            hdatNaca_t* naca = reinterpret_cast<hdatNaca_t*>(addr);
            RUNTIME::UdNaca(naca).addToLog(io_errlog);
        }
        return;
    }
    else if( (RUNTIME::SPIRA_L == i_section)
             || (RUNTIME::SPIRA_S == i_section)
             || (RUNTIME::SPIRA_H == i_section) )
    {
        // grab the NACA first
        addFFDC( NACA, io_errlog );

        errlog = getHostDataSection( i_section, 0, addr, size );
        if( errlog )
        {
            delete errlog;
            errlog = nullptr;
        }
        else if( (addr != 0) && (size != 0) )
        {
            hdatSpira_t* spira = reinterpret_cast<hdatSpira_t*>(addr);
            RUNTIME::UdSpira(spira).addToLog(io_errlog);
        }
        return;
    }
    else if( RUNTIME::HSVC_SYSTEM_DATA == i_section ||
             RUNTIME::HSVC_NODE_DATA == i_section )
    {
        // grab the SPIRA data
        if( iv_spiraL) { addFFDC( SPIRA_L, io_errlog ); }
        if( iv_spiraH) { addFFDC( SPIRA_H, io_errlog ); }
        if( iv_spiraS) { addFFDC( SPIRA_S, io_errlog ); }

        // grab the Tuple it is part of
        hdat5Tuple_t* tuple = nullptr;
        errlog = getAndCheckTuple(i_section, tuple);
        if( errlog )
        {
            delete errlog;
            errlog = nullptr;
        }
        else if( tuple )
        {
            UdTuple(tuple).addToLog(io_errlog);
        }
    }
}

/*
 * @brief Clear out any cached data and rediscover the location
 *        of the HDAT memory
 */
void hdatService::rediscoverHDAT( void )
{
    // Clear out the pointers we cached
    iv_spiraS = NULL;
    iv_spiraL = NULL;
    iv_spiraH = NULL;

    // Clear out our cache of memory regions
    for(memRegionItr region = iv_mem_regions.begin();
        (region != iv_mem_regions.end()); ++region)
    {
         mm_block_unmap((*region).virt_addr);
    }
    iv_mem_regions.clear();
}

/*
 * @brief Get the number of instances in an HDAT section
 */
errlHndl_t hdatService::getInstanceCount(const SectionId i_section,
                                         uint64_t& o_count)
{
    errlHndl_t errhdl = nullptr;
    o_count = 0;

    do {

    // Instance count is not provided the same way for each section
    switch(i_section)
    {
        case RUNTIME::PCRD:
        case RUNTIME::NODE_TPM_RELATED:
        {
            hdat5Tuple_t* tuple = nullptr;
            errhdl = getAndCheckTuple(i_section, tuple);
            if( errhdl )
            {
                break;
            }
            o_count = tuple->hdatActualCnt;
            break;
        }
        case RUNTIME::RESERVED_MEM:
        {
            hdatMsReservedMemArrayHeader_t* reservedMemArrayHeader = nullptr;
            errhdl = getResvMemArrHdr(reservedMemArrayHeader);
            if( errhdl )
            {
                break;
            }
            o_count = reservedMemArrayHeader->arrayEntryCount;
            break;
        }
        default:
            TRACFCOMP( g_trac_runtime, ERR_MRK"getInstanceCount> section %d has no concept of instances",
                       i_section );
            /*@
             * @errortype
             * @moduleid     RUNTIME::MOD_HDATSERVICE_GETINSTANCECOUNT
             * @reasoncode   RUNTIME::RC_INSTANCES_UNSUPPORTED
             * @userdata1    Section Id
             * @userdata2    <unused>
             * @devdesc      Unsupported section requested
             * @custdesc     Unexpected boot firmware error.
             */
            errhdl = new ERRORLOG::ErrlEntry(
                           ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                           RUNTIME::MOD_HDATSERVICE_GETINSTANCECOUNT,
                           RUNTIME::RC_INSTANCES_UNSUPPORTED,
                           i_section,
                           0,
                           true /*Add HB Software Callout*/);
            errhdl->collectTrace(RUNTIME_COMP_NAME,KILOBYTE);;
            break;
    }

    } while (0);

    return errhdl;
}

/*
 * @brief Get the tuple associated with a section and check it's valid
 */
errlHndl_t hdatService::getAndCheckTuple(const SectionId i_section,
                                         hdat5Tuple_t*& o_tuple)
{
    errlHndl_t errhdl = nullptr;
    o_tuple = nullptr;

    do
    {
        hdatSpiraSDataAreas l_spiraS = SPIRAS_INVALID;
        hdatSpiraLegacyDataAreas l_spiraL = SPIRAL_INVALID;
        hdatSpiraHDataAreas l_spiraH = SPIRAH_INVALID;

        switch(i_section)
        {
        case RUNTIME::RESERVED_MEM:
            l_spiraS = SPIRAS_MDT;
            l_spiraL = SPIRAL_MDT;
            break;
        case RUNTIME::HBRT:
        case RUNTIME::HBRT_DATA:
            l_spiraS = SPIRAS_HBRT_DATA;
            l_spiraL = SPIRAL_HBRT_DATA;
            break;
        case RUNTIME::IPLPARMS_SYSTEM:
            l_spiraS = SPIRAS_IPL_PARMS;
            l_spiraL = SPIRAL_IPL_PARMS;
            break;
        case RUNTIME::NODE_TPM_RELATED:
            l_spiraS = SPIRAS_TPM_DATA;
            l_spiraL = SPIRAL_TPM_DATA;
            break;
        case RUNTIME::PCRD:
            l_spiraS = SPIRAS_PCRD;
            l_spiraL = SPIRAL_PCRD;
            break;
        case RUNTIME::MS_DUMP_SRC_TBL:
            l_spiraH = SPIRAH_MS_DUMP_SRC_TBL;
            l_spiraL = SPIRAL_MS_DUMP_SRC_TBL;
            break;
        case RUNTIME::MS_DUMP_DST_TBL:
            l_spiraH = SPIRAH_MS_DUMP_DST_TBL;
            l_spiraL = SPIRAL_MS_DUMP_DST_TBL;
            break;
        case RUNTIME::MS_DUMP_RESULTS_TBL:
            l_spiraH = SPIRAH_MS_DUMP_RSLT_TBL;
            l_spiraL = SPIRAL_MS_DUMP_RSLT_TBL;
            break;
        case RUNTIME::PROC_DUMP_AREA_TBL:
            l_spiraH = SPIRAH_PROC_DUMP_TBL;
            l_spiraL = SPIRAL_INVALID;
            break;
        case RUNTIME::HSVC_SYSTEM_DATA:
        case RUNTIME::HSVC_NODE_DATA:
            l_spiraS = SPIRAS_HSVC_DATA;
            l_spiraL = SPIRAL_HSVC_DATA;
            break;
        case RUNTIME::HRMOR_STASH:
            l_spiraS = SPIRAS_MDT;
            l_spiraL = SPIRAL_MDT;
            break;
        case RUNTIME::CPU_CTRL:
            l_spiraH = SPIRAH_CPU_CTRL;
            l_spiraL = SPIRAL_CPU_CTRL;
            break;
        default:
            TRACFCOMP(g_trac_runtime, ERR_MRK"getAndCheckTuple> section %d not supported",
                      i_section );
            /*@
             * @errortype
             * @moduleid     RUNTIME::MOD_HDATSERVICE_GETANDCHECKTUPLE
             * @reasoncode   RUNTIME::RC_GETTUPLE_UNSUPPORTED
             * @userdata1    Section Id
             * @userdata2    <unused>
             * @devdesc      Unsupported section requested
             * @custdesc     Unexpected boot firmware error.
             */
            errhdl = new ERRORLOG::ErrlEntry(
                           ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                           RUNTIME::MOD_HDATSERVICE_GETANDCHECKTUPLE,
                           RUNTIME::RC_GETTUPLE_UNSUPPORTED,
                           i_section,
                           0,
                           true /*Add HB Software Callout*/);
            errhdl->collectTrace(RUNTIME_COMP_NAME,KILOBYTE);;
            break;
        }

        if( iv_spiraS && l_spiraS != SPIRAS_INVALID )
        {
            o_tuple = &(iv_spiraS->hdatDataArea[l_spiraS]);
        }
        else if( iv_spiraH && l_spiraH != SPIRAH_INVALID )
        {
            o_tuple = &(iv_spiraH->hdatDataArea[l_spiraH]);
        }
        else if( unlikely(iv_spiraL != nullptr && l_spiraL != SPIRAL_INVALID) )
        {
            o_tuple = &(iv_spiraL->hdatDataArea[l_spiraL]);
        }
        errhdl = check_tuple( i_section, o_tuple );
        if( errhdl )
        {
            break;
        }

    } while (0);

    return errhdl;
}

errlHndl_t hdatService::clearHostDataSection(const RUNTIME::SectionId i_section)
{
    TRACFCOMP(g_trac_runtime, ENTER_MRK"clearHostDataSection> section = %d",
              i_section);

    errlHndl_t l_elog = nullptr;

    do {

    //Always force a load (mapping)
    l_elog = loadHostData();
    if(l_elog)
    {
        break;
    }

    // Setup the SPIRA pointers
    l_elog = findSpira();
    if(l_elog)
    {
        break;
    }

    uint64_t l_count = 0;
    l_elog = getInstanceCount(i_section, l_count);
    if(l_elog)
    {
        break;
    }

    // Clear each instance of a host data section
    for (uint64_t instance = 0; instance < l_count; ++instance)
    {
        // Call getHostDataSection with clear flag set
        uint64_t l_hostDataAddr = 0;
        uint64_t l_hostDataSize = 0;
        l_elog = getHostDataSection(i_section,
                                    instance,
                                    l_hostDataAddr,
                                    l_hostDataSize);
        if(l_elog)
        {
            break;
        }

        assert(l_hostDataAddr>0, "Clear address 0x%X is <= 0", l_hostDataAddr);
        assert(l_hostDataSize>0, "Clear size 0x%X is <= 0", l_hostDataSize);

        // Sections differ in how they should be "cleared" or invalidated
        switch (i_section)
        {
            case RUNTIME::RESERVED_MEM:
            {
                // Set Reserved Memory Type to Invalid
                memset(reinterpret_cast<void*>(l_hostDataAddr),
                       HDAT::RHB_TYPE_INVALID,
                       sizeof(HDAT::hdatMsVpdRhbAddrRangeType));
                // Clear rest of entries in range with zero
                memset(reinterpret_cast<void*>(l_hostDataAddr +
                                       sizeof(HDAT::hdatMsVpdRhbAddrRangeType)),
                       0,
                       l_hostDataSize - sizeof(HDAT::hdatMsVpdRhbAddrRangeType));
                break;
            }
            default:
            {
                // Clear entire range with zero
                memset(reinterpret_cast<void*>(l_hostDataAddr),
                       0,
                       l_hostDataSize);
                break;
            }
        }
    }
    // If for loop broke with error
    if(l_elog)
    {
        break;
    }

    } while(0);

    return l_elog;
}

errlHndl_t hdatService::getResvMemArrHdr(hdatMsReservedMemArrayHeader_t*&
                                         o_resvMemArrHdr)
{
    errlHndl_t errhdl = nullptr;
    hdat5Tuple_t* tuple = nullptr;
    uint64_t base_addr = 0;

    do {
        // Find the right tuple and verify it makes sense
        errhdl = getAndCheckTuple(RUNTIME::RESERVED_MEM, tuple);
        if( errhdl ) { break; }
        TRACUCOMP(g_trac_runtime, "getNumResvMemEntries: MDT_DATA tuple=%p", tuple);

        errhdl = getSpiraTupleVA(tuple, base_addr);
        if( errhdl ) { break; }

        hdatHDIF_t* mdt_header =
          reinterpret_cast<hdatHDIF_t*>(base_addr);
        TRACUCOMP( g_trac_runtime, "getNumResvMemEntries: mdt_header=%p", mdt_header );

        // Check the headers and version info
        errhdl = check_header( mdt_header,
                               MDT_HEADER );
        if( errhdl ) { break; }

        hdatHDIFDataHdr_t* mdt_data_header =
          reinterpret_cast<hdatHDIFDataHdr_t*>
          (mdt_header->hdatDataPtrOffset + base_addr);

        errhdl = verify_hdat_address(mdt_data_header,
                                     mdt_header->hdatDataPtrCnt * sizeof(hdatHDIFDataHdr_t) );
        if( errhdl ) { break; }

        uint64_t resvMemHdatAddr = mdt_data_header[MDT_RESERVED_HB_MEM_SECTION].hdatOffset + base_addr;

        o_resvMemArrHdr = reinterpret_cast<hdatMsReservedMemArrayHeader_t *>(resvMemHdatAddr);
        assert(o_resvMemArrHdr != nullptr, "Reserved Memory Array Header is a nullptr");
    } while (0);

    return errhdl;
}

/********************
 Public Methods
 ********************/

/**
 * @brief  Add the host data mainstore locations to VMM
 */
errlHndl_t load_host_data( void )
{
    return Singleton<hdatService>::instance().loadHostData();
}


/**
 * @brief  Get a pointer to the beginning of a particular section of
 *         the host data memory.
 */
errlHndl_t get_host_data_section( SectionId i_section,
                                  uint64_t i_instance,
                                  uint64_t& o_dataAddr,
                                  size_t& o_dataSize)
{
    return Singleton<hdatService>::instance().
      getHostDataSection(i_section,i_instance, o_dataAddr, o_dataSize);
}

void saveActualCount( SectionId i_id,
                      uint16_t i_count )
{
    Singleton<hdatService>::instance().saveActualCount(i_id,i_count);
}

errlHndl_t writeActualCount( SectionId i_id )
{
    return Singleton<hdatService>::instance().writeActualCount(i_id);
}

errlHndl_t updateHostProcDumpActual( SectionId i_section,
                                     uint32_t threadRegSize,
                                     uint8_t threadRegVersion)
{
    return Singleton<hdatService>::instance().updateHostProcDumpActual(i_section,
                                                   threadRegSize, threadRegVersion);
}

void useRelocatedPayloadAddr(bool val)
{
    return Singleton<hdatService>::instance().useRelocatedPayloadAddr(val);
}

/**
 * @brief  Retrieve and log FFDC data relevant to a given section of
 *         host data memory
 */
void add_host_data_ffdc( SectionId i_section,
                         errlHndl_t& io_errlog )
{
    return Singleton<hdatService>::instance().addFFDC(i_section,io_errlog);
}

void rediscover_hdat( void )
{
    Singleton<hdatService>::instance().rediscoverHDAT();
}

errlHndl_t get_instance_count(const SectionId i_section,
                              uint64_t& o_count )
{
    return Singleton<hdatService>::instance().getInstanceCount(i_section,
                                                               o_count);
}

errlHndl_t clear_host_data_section(const RUNTIME::SectionId i_section)
{
    return Singleton<hdatService>::instance().clearHostDataSection(i_section);
}


void findHdatLocation(const uint64_t i_payloadBase_va,
                      uint64_t& o_hdat_offset,
                      size_t& o_hdat_size)
{
    TRACFCOMP( g_trac_runtime, ENTER_MRK"findHdatLocation> i_payloadBase_va = 0x%.16llX", i_payloadBase_va);

    do {

        // Everything starts at the NACA
        //   The NACA is part of the platform dependent LID which
        //   is loaded at relative memory address 0x0
        const hdatNaca_t* naca = reinterpret_cast<const hdatNaca_t*>
          (HDAT_NACA_OFFSET + i_payloadBase_va);
        TRACFCOMP( g_trac_runtime, "findHdatLocation> NACA=0x%.X->0x%p", HDAT_NACA_OFFSET, naca );

        // Find SpiraH information in NACA
        const hdatSpira_t* spiraH = reinterpret_cast<const hdatSpira_t*>
          (naca->spiraH + i_payloadBase_va);
        TRACFCOMP( g_trac_runtime, "findHdatLocation> SPIRA-H=0x%X->0x%p", naca->spiraH, spiraH );

        // SPIRA-S is at the beginning of the Host Data Area Tuple of SpiraH
        const hdat5Tuple_t* tuple = reinterpret_cast<const hdat5Tuple_t*>
          (&(spiraH->hdatDataArea[SPIRAH_HOST_DATA_AREAS]));
        TRACFCOMP( g_trac_runtime, "findHdatLocation> SPIRA-S tuple at 0x%p: "
                   "hdatAbsAddr=0x%X, hdatAllocCnt=0x%X, hdatAllocSize=0x%X",
                   tuple, tuple->hdatAbsAddr, tuple->hdatAllocCnt,
                   tuple->hdatAllocSize  );

        o_hdat_offset = tuple->hdatAbsAddr;
        o_hdat_size = tuple->hdatAllocCnt * tuple->hdatAllocSize;

    } while (0);

    TRACFCOMP( g_trac_runtime, EXIT_MRK"findHdatLocation> "
               "o_hdat_offset = 0x%X, o_hdat_size=0x%X",
               o_hdat_offset, o_hdat_size);
}


};

void hdatMsVpdRhbAddrRange_t::set(const HDAT::hdatMsVpdRhbAddrRangeType i_type,
                                  const uint16_t i_rangeId,
                                  const uint64_t i_startAddr,
                                  const uint64_t i_size,
                                  const char* i_label,
                                  const HDAT::hdatRhbPermType i_permission)
{
    assert(i_label != nullptr, "Null label for hdatMsVpdRhbAddrRange_t");

    hdatRhbRngType = i_type;
    hdatRhbRngId = i_rangeId;
    hdatRhbAddrRngStrAddr = i_startAddr;
    hdatRhbAddrRngEndAddr = (i_startAddr + i_size - 1);
    hdatRhbLabelSize = strlen(i_label) + 1;
    memset(hdatRhbLabelString, 0, hdatRhbLabelSize);
    memcpy(hdatRhbLabelString, i_label, hdatRhbLabelSize);
    hdatRhbPermission = i_permission;
}

/********************
 Private/Protected Methods
 ********************/

