/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/runtime/hdatservice.C $                               */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2014              */
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
#include <trace/interface.H>
#include <errl/errlentry.H>
#include <runtime/runtime_reasoncodes.H>
#include <sys/mm.h>
#include <targeting/common/commontargeting.H>
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

//#define REAL_HDAT_TEST

extern trace_desc_t* g_trac_runtime;

#define TRACUCOMP TRACDCOMP

namespace RUNTIME
{

/********************
 Local Constants used for sanity checks
 ********************/
const hdatHeaderExp_t HSVC_NODE_DATA_HEADER = {
    0xD1F0,   // id
    "HS KID", // name
    0x0010    //version
};

const hdatHeaderExp_t HSVC_DATA_HEADER = {
    0xD1F0,   //id
    "HOSTSR", //name
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
    0x0040    //version
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
errlHndl_t hdatService::verify_hdat_address( void* i_addr,
                                             size_t i_size )
{
    errlHndl_t errhdl = NULL;
    bool found = false;
    uint64_t l_end =  reinterpret_cast<uint64_t>(i_addr)
                       + i_size;

    // Make sure that the entire range is within the memory
    //  space that we allocated
    for(memRegionItr region = iv_mem_regions.begin();
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
        for(memRegionItr region = iv_mem_regions.begin();
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

errlHndl_t hdatService::check_header( hdatHDIF_t* i_header,
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

errlHndl_t hdatService::check_tuple( const RUNTIME::SectionId i_section,
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
                                               RUNTIME::SectionId i_section,
                                               uint64_t i_instance,
                                               uint64_t& o_dataAddr,
                                               size_t& o_dataSize )
{
    errlHndl_t errhdl = NULL;

    if( RUNTIME::HSVC_SYSTEM_DATA == i_section )
    {
        o_dataAddr = reinterpret_cast<uint64_t>(iv_mem_regions[0].virt_addr);
        o_dataSize = HSVC_TEST_SYSDATA_SIZE;
    }
    else if( RUNTIME::HSVC_NODE_DATA == i_section )
    {
        o_dataAddr = reinterpret_cast<uint64_t>(iv_mem_regions[0].virt_addr)
                     + HSVC_TEST_SYSDATA_SIZE;
        o_dataSize = HSVC_TEST_NODEDATA_SIZE;
    }
    else if( RUNTIME::MS_DUMP_SRC_TBL == i_section )
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
{
    for( RUNTIME::SectionId id = RUNTIME::FIRST_SECTION;
         id <= RUNTIME::LAST_SECTION;
         id = (RUNTIME::SectionId)(id+1) )
    {
        iv_actuals[id] = ACTUAL_NOT_SET;
    }
}

hdatService::~hdatService(void)
{
    for(memRegionItr region = iv_mem_regions.begin();
        (region != iv_mem_regions.end()); ++region)
    {
         mm_block_unmap((*region).virt_addr);
    }

    iv_mem_regions.clear();
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

        //If PHYP or Sapphire w/SP Base Services
        if( (TARGETING::PAYLOAD_KIND_PHYP == payload_kind ) ||
            ((TARGETING::PAYLOAD_KIND_SAPPHIRE == payload_kind ) &&
             INITSERVICE::spBaseServicesEnabled()))
        {
            // PHYP
            TARGETING::ATTR_PAYLOAD_BASE_type payload_base
              = sys->getAttr<TARGETING::ATTR_PAYLOAD_BASE>();

            uint64_t hdat_start = payload_base*MEGABYTE;
            uint64_t hdat_size = HDAT_MEM_SIZE;

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
            TRACFCOMP( g_trac_runtime, "load_host_data> STANDALONE: Mapping in 0x%X-0x%X (%d MB)", HSVC_TEST_MEMORY_ADDR,
                HSVC_TEST_MEMORY_ADDR+HSVC_TEST_MEMORY_SIZE,
                HSVC_TEST_MEMORY_SIZE);

            errhdl = mapRegion(HSVC_TEST_MEMORY_ADDR,
                               HSVC_TEST_MEMORY_SIZE, l_dummy);
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
                                            size_t& o_dataSize )
{
    errlHndl_t errhdl = NULL;
    TRACFCOMP( g_trac_runtime, "RUNTIME::getHostDataSection( i_section=%d, i_instance=%d )", i_section, i_instance );

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
        TARGETING::ATTR_PAYLOAD_KIND_type payload_kind
          = sys->getAttr<TARGETING::ATTR_PAYLOAD_KIND>();

#ifdef REAL_HDAT_TEST
        TRACFCOMP( g_trac_runtime, "Forcing PHYP mode for testing" );
        payload_kind = TARGETING::PAYLOAD_KIND_PHYP;
#endif

        if( TARGETING::PAYLOAD_KIND_NONE == payload_kind )
        {
            errhdl = get_standalone_section( i_section,
                                             i_instance,
                                             o_dataAddr,
                                             o_dataSize );
            // we're all done
            break;
        }
        //If payload is not (PHYP or Sapphire w/SP Base Services )
        else if( !((TARGETING::PAYLOAD_KIND_PHYP == payload_kind ) ||
            ((TARGETING::PAYLOAD_KIND_SAPPHIRE == payload_kind ) &&
             INITSERVICE::spBaseServicesEnabled())))
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
        // Host Services System Data
        else if( RUNTIME::HSVC_SYSTEM_DATA == i_section )
        {

            // Find the right tuple and verify it makes sense
            hdat5Tuple_t* tuple = NULL;
            if( iv_spiraS )
            {
                tuple = &(iv_spiraS->hdatDataArea[SPIRAS_HSVC_DATA]);
            }
            else if( unlikely(iv_spiraL != NULL) )
            {
                tuple = &(iv_spiraL->hdatDataArea[SPIRAL_HSVC_DATA]);
            }
            TRACUCOMP( g_trac_runtime, "HSVC_SYSTEM_DATA tuple=%p", tuple );
            errhdl = check_tuple( i_section,
                                  tuple );
            if( errhdl ) { break; }

            uint64_t base_addr;
            errhdl = getSpiraTupleVA(tuple, base_addr);
            if( errhdl ) { break; }

            hdatHDIF_t* hsvc_header =
              reinterpret_cast<hdatHDIF_t*>(base_addr);
            TRACUCOMP( g_trac_runtime, "hsvc_header=%p", hsvc_header );

            // Check the headers and version info
            errhdl = check_header( hsvc_header,
                                   HSVC_DATA_HEADER );
            if( errhdl ) { break; }

            hdatHDIFDataHdr_t* sys_header =
              reinterpret_cast<hdatHDIFDataHdr_t*>
              (hsvc_header->hdatDataPtrOffset + base_addr);
            TRACUCOMP( g_trac_runtime, "sys_header=%p", sys_header );
            // Make sure the Data Header is pointing somewhere valid
            errhdl = verify_hdat_address( sys_header,
                                          sizeof(hdatHDIFDataHdr_t) );
            if( errhdl ) { break; }

            o_dataAddr = sys_header->hdatOffset + base_addr;
            o_dataSize = sys_header->hdatSize;
        }
        // Host Services Node Data
        else if( RUNTIME::HSVC_NODE_DATA == i_section )
        {
            // Find the right tuple and verify it makes sense
            hdat5Tuple_t* tuple = NULL;
            if( iv_spiraS )
            {
                tuple = &(iv_spiraS->hdatDataArea[SPIRAS_HSVC_DATA]);
            }
            else if( unlikely(iv_spiraL != NULL) )
            {
                tuple = &(iv_spiraL->hdatDataArea[SPIRAL_HSVC_DATA]);
            }
            TRACUCOMP( g_trac_runtime, "HSVC_NODE_DATA tuple=%p", tuple );
            errhdl = check_tuple( i_section,
                                  tuple );
            if( errhdl ) { break; }


            uint64_t base_addr;
            errhdl = getSpiraTupleVA(tuple, base_addr);
            if( errhdl ) { break; }

            hdatHDIF_t* hsvc_header =
              reinterpret_cast<hdatHDIF_t*>(base_addr);
            TRACUCOMP( g_trac_runtime, "hsvc_header=%p", hsvc_header );

            // Check the headers and version info
            errhdl = check_header( hsvc_header,
                                   HSVC_DATA_HEADER );
            if( errhdl ) { break; }

            hdatHDIFChildHdr_t* node_header =
              reinterpret_cast<hdatHDIFChildHdr_t*>
              (hsvc_header->hdatChildStrOffset + base_addr);
            TRACUCOMP( g_trac_runtime, "node_headers=%p", node_header );
            // Make sure the Child Header is pointing somewhere valid
            errhdl = verify_hdat_address( node_header,
                                          sizeof(hdatHDIFChildHdr_t) );
            if( errhdl ) { break; }

            hdatHDIF_t* node_data_headers =
              reinterpret_cast<hdatHDIF_t*>
              (node_header->hdatOffset + base_addr);
            // Make sure the headers are all in a valid range
            errhdl = verify_hdat_address( node_data_headers,
                             sizeof(hdatHDIF_t)*(node_header->hdatCnt) );
            if( errhdl ) { break; }

            // Loop around all instances because the data
            //   could be sparsely populated
            TRACUCOMP( g_trac_runtime, "nodecount=%d", node_header->hdatCnt );
            bool foundit = false;
            uint32_t found_instances = 0;
            for( uint8_t index = 0; index < node_header->hdatCnt; index++ )
            {
                TRACUCOMP( g_trac_runtime, "index=%d", index );
                // Check the headers and version info
                errhdl = check_header( &(node_data_headers[index]),
                                       HSVC_NODE_DATA_HEADER );
                if( errhdl ) { break; }

                uint64_t node_base_addr =
                  reinterpret_cast<uint64_t>(&(node_data_headers[index]));

                TRACUCOMP( g_trac_runtime, "%d> hdatInstance=%d", index, node_data_headers[index].hdatInstance );
                if( node_data_headers[index].hdatInstance != i_instance )
                {
                    found_instances |=
                      (0x80000000 >> node_data_headers[index].hdatInstance);
                    continue;
                }
                foundit = true;

                hdatHDIFDataHdr_t* local_node_header =
                  reinterpret_cast<hdatHDIFDataHdr_t*>
                  (node_data_headers[index].hdatDataPtrOffset + node_base_addr);
                TRACUCOMP( g_trac_runtime, "local_node_header=%p", local_node_header );
                // Make sure the header is pointing somewhere valid
                errhdl = verify_hdat_address( local_node_header,
                                              sizeof(hdatHDIFDataHdr_t) );
                if( errhdl ) { break; }

                o_dataAddr = local_node_header->hdatOffset + node_base_addr;
                o_dataSize = local_node_header->hdatSize;

                break; // found it, stop the loop
            }
            if( errhdl ) { break; }

            // Make sure we found something
            if( !foundit )
            {
                TRACFCOMP( g_trac_runtime, "getHostDataSection> HSVC_NODE_DATA instance %d of section %d is unallocated", i_instance, i_section );
                // Go get the physical address we mapped in
                uint64_t phys_addr =
                  mm_virt_to_phys(reinterpret_cast<void*>(node_data_headers));

                /*@
                 * @errortype
                 * @moduleid     RUNTIME::MOD_HDATSERVICE_GETHOSTDATASECTION
                 * @reasoncode   RUNTIME::RC_NO_HSVC_NODE_DATA_FOUND
                 * @userdata1    Mainstore address of node_data_headers
                 * @userdata2[0:31]    Requested Instance
                 * @userdata2[32:63]   Bitmask of discovered instances
                 * @devdesc      Requested instance of HSVC_NODE_DATA is
                 *               unallocated
                 */
                errhdl = new ERRORLOG::ErrlEntry(
                                  ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                  RUNTIME::MOD_HDATSERVICE_GETHOSTDATASECTION,
                                  RUNTIME::RC_NO_HSVC_NODE_DATA_FOUND,
                                  phys_addr,
                                  TWO_UINT32_TO_UINT64(i_instance,
                                                       found_instances));
                errhdl->addProcedureCallout( HWAS::EPUB_PRC_HB_CODE,
                                             HWAS::SRCI_PRIORITY_MED );
                errhdl->addProcedureCallout( HWAS::EPUB_PRC_SP_CODE,
                                             HWAS::SRCI_PRIORITY_MED );
                errhdl->collectTrace(RUNTIME_COMP_NAME,KILOBYTE);
                break;
            }

        }
        // IPL Parameters : System Parameters
        else if( RUNTIME::IPLPARMS_SYSTEM == i_section )
        {
            // Find the right tuple and verify it makes sense
            hdat5Tuple_t* tuple = NULL;
            if( iv_spiraS )
            {
                tuple = &(iv_spiraS->hdatDataArea[SPIRAS_IPL_PARMS]);
            }
            else if( unlikely(iv_spiraL != NULL) )
            {
                tuple = &(iv_spiraL->hdatDataArea[SPIRAL_IPL_PARMS]);
            }
            TRACUCOMP( g_trac_runtime, "IPLPARMS_SYSTEM tuple=%p", tuple );
            errhdl = check_tuple( i_section,
                                  tuple );
            if( errhdl ) { break; }

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
        // MS DUMP Source Table - MDST
        else if( RUNTIME::MS_DUMP_SRC_TBL == i_section )
        {
            //For security we can't trust the FSP's payload attribute
            //  on MPIPLs for the dump tables.
            //@todo: RTC:59171

            // Find the right tuple and verify it makes sense
            hdat5Tuple_t* tuple = NULL;
            if( iv_spiraS )
            {
                tuple = &(iv_spiraS->hdatDataArea[SPIRAH_MS_DUMP_SRC_TBL]);
            }
            else if( unlikely(iv_spiraL != NULL) )
            {
                tuple = &(iv_spiraL->hdatDataArea[SPIRAL_MS_DUMP_SRC_TBL]);
            }
            TRACUCOMP( g_trac_runtime, "MS_DUMP_SRC_TBL tuple=%p", tuple );
            errhdl = check_tuple( i_section,
                                  tuple );
            if( errhdl ) { break; }

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
            hdat5Tuple_t* tuple = NULL;
            if( iv_spiraS )
            {
                tuple = &(iv_spiraS->hdatDataArea[SPIRAH_MS_DUMP_DST_TBL]);
            }
            else if( unlikely(iv_spiraL != NULL) )
            {
                tuple = &(iv_spiraL->hdatDataArea[SPIRAL_MS_DUMP_DST_TBL]);
            }
            TRACUCOMP( g_trac_runtime, "MS_DUMP_DST_TBL tuple=%p", tuple );
            errhdl = check_tuple( i_section,
                                  tuple );
            if( errhdl ) { break; }

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
            hdat5Tuple_t* tuple = NULL;
            if( iv_spiraS )
            {
                tuple = &(iv_spiraS->hdatDataArea[SPIRAH_MS_DUMP_RSLT_TBL]);
            }
            else if( unlikely(iv_spiraL != NULL) )
            {
                tuple = &(iv_spiraL->hdatDataArea[SPIRAL_MS_DUMP_RSLT_TBL]);
            }
            TRACUCOMP( g_trac_runtime, "MS_DUMP_RESULTS_TBL tuple=%p", tuple );
            errhdl = check_tuple( i_section,
                                  tuple );
            if( errhdl ) { break; }

            //Note - there is no header for the MDRT
            //return the total allocated size since it is empty at first
            o_dataSize = tuple->hdatAllocSize * tuple->hdatAllocCnt;
            record_size = tuple->hdatAllocSize;
            errhdl = getSpiraTupleVA(tuple, o_dataAddr);
            if( errhdl ) { break; }

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

    TRACFCOMP( g_trac_runtime, "getHostDataSection> o_dataAddr=0x%X, o_dataSize=%d", o_dataAddr, o_dataSize );

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
            TARGETING::ATTR_PAYLOAD_KIND_type payload_kind
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
                           RUNTIME::RC_BAD_NACA,
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

    if( errhdl_s ) { delete errhdl_s; }
    if( errhdl_l ) { delete errhdl_l; }

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
        TARGETING::ATTR_PAYLOAD_KIND_type payload_kind
          = sys->getAttr<TARGETING::ATTR_PAYLOAD_KIND>();

        if( TARGETING::PAYLOAD_KIND_NONE == payload_kind )
        {
            // we're all done -- don't need to do anything
            break;
        }
        //If payload is not (PHYP or Sapphire w/SP Base Services)
        else if( !((TARGETING::PAYLOAD_KIND_PHYP == payload_kind ) ||
            ((TARGETING::PAYLOAD_KIND_SAPPHIRE == payload_kind ) &&
             INITSERVICE::spBaseServicesEnabled())))
        {
            TRACFCOMP( g_trac_runtime, "get_host_data_section> There is no host data for PAYLOAD_KIND=%d", payload_kind );
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
            if( iv_spiraS )
            {
                tuple = &(iv_spiraS->hdatDataArea[SPIRAH_MS_DUMP_RSLT_TBL]);
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
            TRACFCOMP( g_trac_runtime, "get_host_data_section> Unknown section %d", i_section );
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
    errlHndl_t errlog = NULL;

    if( RUNTIME::NACA == i_section )
    {
        errlog = getHostDataSection( NACA, 0, addr, size );
        if( errlog )
        {
            delete errlog;
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
        }
        else if( (addr != 0) && (size != 0) )
        {
            hdatSpira_t* spira = reinterpret_cast<hdatSpira_t*>(addr);
            RUNTIME::UdSpira(spira).addToLog(io_errlog);
        }
        return;
    }
    else if( RUNTIME::HSVC_SYSTEM_DATA == i_section )
    {
        // grab the SPIRA data
        if( iv_spiraL) { addFFDC( SPIRA_L, io_errlog ); }
        if( iv_spiraH) { addFFDC( SPIRA_H, io_errlog ); }
        if( iv_spiraS) { addFFDC( SPIRA_S, io_errlog ); }

        // grab the Tuple it is part of
        hdat5Tuple_t* tuple = NULL;
        if( iv_spiraS )
        {
            tuple = &(iv_spiraS->hdatDataArea[SPIRAS_HSVC_DATA]);
        }
        else if( unlikely(iv_spiraL != NULL) )
        {
            tuple = &(iv_spiraL->hdatDataArea[SPIRAL_HSVC_DATA]);
        }
        if( tuple ) { RUNTIME::UdTuple(tuple).addToLog(io_errlog); }
    }
    else if( RUNTIME::HSVC_NODE_DATA == i_section )
    {
        // grab the SPIRA data
        if( iv_spiraL) { addFFDC( SPIRA_L, io_errlog ); }
        if( iv_spiraH) { addFFDC( SPIRA_H, io_errlog ); }
        if( iv_spiraS) { addFFDC( SPIRA_S, io_errlog ); }

        // grab the Tuple it is part of
        hdat5Tuple_t* tuple = NULL;
        if( iv_spiraS )
        {
            tuple = &(iv_spiraS->hdatDataArea[SPIRAS_HSVC_DATA]);
        }
        else if( unlikely(iv_spiraL != NULL) )
        {
            tuple = &(iv_spiraL->hdatDataArea[SPIRAL_HSVC_DATA]);
        }
        if( tuple ) { RUNTIME::UdTuple(tuple).addToLog(io_errlog); }
    }
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
                                  size_t& o_dataSize )
{
    return Singleton<hdatService>::instance().
      getHostDataSection(i_section,i_instance, o_dataAddr, o_dataSize);
}

void saveActualCount( RUNTIME::SectionId i_id,
                      uint16_t i_count )
{
    Singleton<hdatService>::instance().saveActualCount(i_id,i_count);
}

errlHndl_t writeActualCount( RUNTIME::SectionId i_id )
{
    return Singleton<hdatService>::instance().writeActualCount(i_id);
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

};

/********************
 Private/Protected Methods
 ********************/

