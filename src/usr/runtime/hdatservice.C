/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/runtime/hdatservice.C $                               */
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
#include <trace/interface.H>
#include <errl/errlentry.H>
#include <runtime/runtime_reasoncodes.H>
#include <runtime/runtime.H>
#include <sys/mm.h>
#include <targeting/common/commontargeting.H>
#include <attributeenums.H>
#include <vmmconst.h>
#include <util/align.H>
#include "hdatstructs.H"

extern trace_desc_t* g_trac_runtime;

#define TRACUCOMP TRACDCOMP


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

//big enough to hold all of PHYP
const uint64_t HDAT_MEM_SIZE = 128*MEGABYTE; 

/********************
 Utility Functions
 ********************/

/**
 * @brief Verify that a block of memory falls inside a safe range
 * @param i_base  Payload base address
 * @param i_addr  Address to check
 * @param i_size  Number of bytes to check
 * @return Error if address seems wrong
 */
errlHndl_t verify_hdat_address( uint64_t i_base,
                                uint64_t i_addr,
                                size_t i_size )
{
    errlHndl_t errhdl = NULL;

    // Make sure that the entire range is within the memory
    //  space that we allocated
    if( (i_addr < i_base)
        || ((i_addr+i_size) > (i_base+HDAT_MEM_SIZE)) )
    {
        TRACFCOMP( g_trac_runtime, "Invalid HDAT Address : i_base=0x%X, i_addr=0x%X, i_size=0x%X", i_base, i_addr, i_size );
        /*@
         * @errortype
         * @moduleid     RUNTIME::MOD_HDATSERVICE_VERIFY_HDAT_ADDRESS
         * @reasoncode   RUNTIME::RC_INVALID_ADDRESS
         * @userdata1[0:31]   Start of address range under test
         * @userdata1[32:63]  Size of address range under test
         * @userdata2[0:31]   Payload base address
         * @userdata2[32:63]  Size of mapped HDAT section
         * @devdesc      HDAT data block falls outside valid range
         */
        errhdl = new ERRORLOG::ErrlEntry(
                            ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                            RUNTIME::MOD_HDATSERVICE_VERIFY_HDAT_ADDRESS,
                            RUNTIME::RC_INVALID_ADDRESS,
                            TWO_UINT32_TO_UINT64(i_addr,i_size),
                            TWO_UINT32_TO_UINT64(i_base,HDAT_MEM_SIZE) );
        errhdl->collectTrace("RUNTIME",1024);
    }

    return errhdl;
}
// Handy overloading to avoid messy casts by the caller
errlHndl_t verify_hdat_address( uint64_t i_base,
                                void* i_addr,
                                size_t i_size )
{
    return verify_hdat_address( i_base,
                                reinterpret_cast<uint64_t>(i_addr),
                                i_size );
}

/**
 * @brief Verify the header portion of an HDAT section
 * @param i_base  Payload base address
 * @param i_header  Actual header data
 * @param i_exp  Expected header data
 * @return Error on mismatch
 */
errlHndl_t check_header( uint64_t i_base,
                         hdatHDIF_t* i_header,
                         const hdatHeaderExp_t& i_exp )
{
    TRACUCOMP( g_trac_runtime, "check_header(%s)> %.4X : %.4X : %s", i_exp.name, i_header->hdatStructId, i_header->hdatVersion, i_header->hdatStructName );
    errlHndl_t errhdl = NULL;

    do
    {
        // Make sure the Tuple is pointing somewhere valid
        errhdl = verify_hdat_address( i_base,
                                      i_header,
                                      sizeof(hdatHDIF_t) );
        if( errhdl ) { break; }

        // Check the ID, Version and Name
        if( (i_header->hdatStructId != i_exp.id)
            && (i_header->hdatVersion != i_exp.version) 
            && !memcmp(i_header->hdatStructName,i_exp.name,6) )
        {
            TRACFCOMP( g_trac_runtime, ERR_MRK "RUNTIME::check_header> HDAT Header data not as expected (id:version:name). Act=%.4X:%.4X:%s, Exp=%.4X:%.4X :%s", i_header->hdatStructId, i_header->hdatVersion, i_header->hdatStructName, i_exp.id, i_exp.version, i_exp.name );
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
            errhdl->collectTrace("RUNTIME",1024);
            break;
        }
    } while(0);

    return errhdl;
}

/**
 * @brief Verify basic characteristics of a HDAT Tuple structure
 * @param i_base  Payload base address
 * @param i_section  Section name being verified
 * @param i_tuple  Tuple to check
 * @return Error if Tuple is unallocated
 */
errlHndl_t check_tuple( uint64_t i_base,
                        const RUNTIME::SectionId i_section,
                        hdat5Tuple_t* i_tuple )
{
    errlHndl_t errhdl = NULL;

    do
    {
        // Make sure the Tuple is in valid memory
        errhdl = verify_hdat_address( i_base,
                                      i_tuple,
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
            errhdl->collectTrace("RUNTIME",1024);
            break;
        }
    } while(0);

    return errhdl;
}


/**
 * @brief Retrieve hardcoded section addresses for standalone mode
 *
 * This is here to allow us to manually generate attribute data for
 *  the HostServices code without requiring a full FipS/PHYP boot.
 *
 * @param[in] i_section  Chunk of data to find
 * @param[in] i_instance  Instance of section when there are multiple entries
 * @param[out] o_dataAddr  Physical memory address of data
 * @param[out] o_dataSize  Size of data in bytes, 0 on error, DATA_SIZE_UNKNOWN if unknown
 *
 * @return errlHndl_t  NULL on success
 */
errlHndl_t get_standalone_section( RUNTIME::SectionId i_section,
                                   uint64_t i_instance,
                                   uint64_t& o_dataAddr,
                                   size_t& o_dataSize )
{
    errlHndl_t errhdl = NULL;

    if( RUNTIME::HSVC_SYSTEM_DATA == i_section )
    {
        o_dataAddr = HSVC_TEST_MEMORY_ADDR;
        o_dataSize = 512*KILOBYTE;
    }
    else if( RUNTIME::HSVC_NODE_DATA == i_section )
    {
        o_dataAddr = HSVC_TEST_MEMORY_ADDR + 512*KILOBYTE;
        o_dataSize = HSVC_TEST_MEMORY_SIZE - 512*KILOBYTE;
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
                                         i_instance);
        errhdl->collectTrace("RUNTIME",1024);
    }

    return errhdl;
}


/********************
 Public Methods
 ********************/

/**
 * @brief  Add the host data mainstore location to VMM
 */
errlHndl_t RUNTIME::load_host_data( void )
{
    errlHndl_t errhdl = NULL;

    do
    {
        TARGETING::Target * sys = NULL;
        TARGETING::targetService().getTopLevelTarget( sys );
        assert(sys != NULL);

        TARGETING::ATTR_PAYLOAD_KIND_type payload_kind
          = sys->getAttr<TARGETING::ATTR_PAYLOAD_KIND>();
        
        if( TARGETING::PAYLOAD_KIND_PHYP == payload_kind )
        {
            // PHYP
            TARGETING::ATTR_PAYLOAD_BASE_type payload_base
              = sys->getAttr<TARGETING::ATTR_PAYLOAD_BASE>();

            uint64_t hdat_start = payload_base*MEGABYTE;
            uint64_t hdat_size = HDAT_MEM_SIZE;

            // make sure that our numbers are page-aligned, required by mm call
            hdat_start = ALIGN_PAGE_DOWN(hdat_start); //round down
            hdat_size = ALIGN_PAGE(hdat_size); //round up

            TRACFCOMP( g_trac_runtime, "load_host_data> PHYP: Mapping in 0x%X-0x%X (%d MB)", hdat_start, hdat_start+hdat_size, hdat_size );
            int rc = mm_linear_map( reinterpret_cast<void*>(hdat_start),
                                    hdat_size );
            if (rc != 0)
            {
                TRACFCOMP( g_trac_runtime, "Failure calling mm_linear_map : rc=%d", rc );
                /*@
                 * @errortype
                 * @moduleid     RUNTIME::MOD_HDATSERVICE_LOAD_HOST_DATA
                 * @reasoncode   RUNTIME::RC_CANNOT_MAP_MEMORY
                 * @userdata1    Starting Address
                 * @userdata2    Size
                 * @devdesc      Error mapping in memory
                 */
                errhdl = new ERRORLOG::ErrlEntry(
                                   ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                   RUNTIME::MOD_HDATSERVICE_LOAD_HOST_DATA,
                                   RUNTIME::RC_CANNOT_MAP_MEMORY,
                                   hdat_start,
                                   hdat_size );
                errhdl->collectTrace("RUNTIME",1024);
                break;
            }        
        }
        else if( TARGETING::PAYLOAD_KIND_NONE == payload_kind )
        {
            // Standalone Test Image with no payload

            // Ensure that there really is no payload being loaded
            TARGETING::ATTR_PAYLOAD_BASE_type payload_base
              = sys->getAttr<TARGETING::ATTR_PAYLOAD_BASE>();
            if( payload_base != 0 )
            {
                TRACFCOMP( g_trac_runtime, "load_host_data> Non-zero PAYLOAD_BASE (0x%X) for PAYLOAD_KIND==NONE", payload_base );
                /*@
                 * @errortype
                 * @moduleid     RUNTIME::MOD_HDATSERVICE_LOAD_HOST_DATA
                 * @reasoncode   RUNTIME::RC_WRONG_PAYLOAD_ATTRS
                 * @userdata1    PAYLOAD_BASE
                 * @userdata2    PAYLOAD_KIND
                 * @devdesc      Nonzero PAYLOAD_BASE for standalone
                 *               PAYLOAD_KIND
                 */
                errhdl = new ERRORLOG::ErrlEntry(
                                   ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                   RUNTIME::MOD_HDATSERVICE_LOAD_HOST_DATA,
                                   RUNTIME::RC_WRONG_PAYLOAD_ATTRS,
                                   payload_base,
                                   payload_kind );
                errhdl->collectTrace("RUNTIME",1024);
                break;
            }

            // Map in some arbitrary memory for the HostServices code to use
            TRACFCOMP( g_trac_runtime, "load_host_data> STANDALONE: Mapping in 0x%X-0x%X (%d MB)", HSVC_TEST_MEMORY_ADDR, HSVC_TEST_MEMORY_ADDR+HSVC_TEST_MEMORY_SIZE, HSVC_TEST_MEMORY_SIZE );
            int rc = mm_linear_map(
                        reinterpret_cast<void*>(HSVC_TEST_MEMORY_ADDR),
                        HSVC_TEST_MEMORY_SIZE );
            if (rc != 0)
            {
                TRACFCOMP( g_trac_runtime, "Failure calling mm_linear_map : rc=%d", rc );
                /*@
                 * @errortype
                 * @moduleid     RUNTIME::MOD_HDATSERVICE_LOAD_HOST_DATA
                 * @reasoncode   RUNTIME::RC_CANNOT_MAP_MEMORY2
                 * @userdata1    Starting Address
                 * @userdata2    Size
                 * @devdesc      Error mapping in standalone memory
                 */
                errhdl = new ERRORLOG::ErrlEntry(
                                   ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                   RUNTIME::MOD_HDATSERVICE_LOAD_HOST_DATA,
                                   RUNTIME::RC_CANNOT_MAP_MEMORY2,
                                   HSVC_TEST_MEMORY_ADDR,
                                   HSVC_TEST_MEMORY_SIZE );
                errhdl->collectTrace("RUNTIME",1024);
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

/**
 * @brief  Get a pointer to the beginning of a particular section of
 *         the host data memory.
 */
errlHndl_t RUNTIME::get_host_data_section( SectionId i_section,
                                           uint64_t i_instance,
                                           uint64_t& o_dataAddr,
                                           size_t& o_dataSize )
{
    errlHndl_t errhdl = NULL;
    TRACFCOMP( g_trac_runtime, "RUNTIME::get_host_data_section( i_section=%d, i_instance=%d )", i_section, i_instance );

    do
    {
        // Force the answer to zero in case of failure
        o_dataAddr = 0;

        TARGETING::Target * sys = NULL;
        TARGETING::targetService().getTopLevelTarget( sys );
        assert(sys != NULL);

        // Figure out what kind of payload we have
        TARGETING::ATTR_PAYLOAD_KIND_type payload_kind
          = sys->getAttr<TARGETING::ATTR_PAYLOAD_KIND>();

        if( TARGETING::PAYLOAD_KIND_NONE == payload_kind )
        {
            errhdl = get_standalone_section( i_section,
                                             i_instance,
                                             o_dataAddr,
                                             o_dataSize );
            // we're all done
            break;
        }
        else if( TARGETING::PAYLOAD_KIND_PHYP != payload_kind )
        {
            TRACFCOMP( g_trac_runtime, "get_host_data_section> There is no host data for PAYLOAD_KIND=%d", payload_kind );
            /*@
             * @errortype
             * @moduleid     RUNTIME::MOD_HDATSERVICE_GET_HOST_DATA_SECTION
             * @reasoncode   RUNTIME::RC_INVALID_PAYLOAD_KIND
             * @userdata1    ATTR_PAYLOAD_KIND
             * @userdata2    Requested Section
             * @devdesc      There is no host data for specified kind of payload
             */
            errhdl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                              RUNTIME::MOD_HDATSERVICE_GET_HOST_DATA_SECTION,
                              RUNTIME::RC_INVALID_PAYLOAD_KIND,
                              payload_kind,
                              i_section);
            errhdl->collectTrace("RUNTIME",1024);
            break;
        }

        // Go fetch the relative zero address that PHYP uses
        TARGETING::ATTR_PAYLOAD_BASE_type payload_base
          = sys->getAttr<TARGETING::ATTR_PAYLOAD_BASE>();
        payload_base = payload_base*MEGABYTE;

        // Everything starts at the NACA
        //   The NACA is part of the platform dependent LID which
        //   is loaded at relative memory address 0x0
        hdatNaca_t* naca = reinterpret_cast<hdatNaca_t*>
          (HDAT_NACA_OFFSET + payload_base);
        TRACFCOMP( g_trac_runtime, "NACA=%p", naca );

        // Do some sanity checks on the NACA
        if( naca->nacaPhypPciaSupport != 1 )
        {
            TRACFCOMP( g_trac_runtime, "get_host_data_section> nacaPhypPciaSupport=%.8X", naca->nacaPhypPciaSupport );
            /*@
             * @errortype
             * @moduleid     RUNTIME::MOD_HDATSERVICE_GET_HOST_DATA_SECTION
             * @reasoncode   RUNTIME::RC_BAD_NACA
             * @userdata1    Mainstore address of NACA
             * @userdata2[0:31]    Payload Base Address
             * @userdata2[32:63]   Payload Kind
             * @devdesc      NACA data doesn't seem right
             */
            errhdl = new ERRORLOG::ErrlEntry(
                            ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                            RUNTIME::MOD_HDATSERVICE_GET_HOST_DATA_SECTION,
                            RUNTIME::RC_BAD_NACA,
                            reinterpret_cast<uint64_t>(naca),
                            TWO_UINT32_TO_UINT64(payload_base,
                                                 payload_kind));
            errhdl->collectTrace("RUNTIME",1024);
            //@todo-log NACA data
            break;
        }


        // The SPIRA pointer is also relative to PHYP's zero
        hdatSpira_t* spira = reinterpret_cast<hdatSpira_t*>
          (naca->spira + payload_base);
        TRACFCOMP( g_trac_runtime, "SPIRA=%p", spira );
        // Make sure the SPIRA is valid
        errhdl = verify_hdat_address( payload_base,
                                      spira,
                                      sizeof(hdatSpira_t) );
        if( errhdl )
        {
            TRACFCOMP( g_trac_runtime, "Spira is at a wacky offset!!! %.16X", naca->spira );
            //@todo-log NACA data RTC:53139
            break;
        }

        // Host Services System Data
        if( RUNTIME::HSVC_SYSTEM_DATA == i_section )
        {
            // Find the right tuple and verify it makes sense
            hdat5Tuple_t* tuple = &(spira->hdatDataArea[HSVC_DATA]);
            TRACUCOMP( g_trac_runtime, "HSVC_SYSTEM_DATA tuple=%p", tuple );
            errhdl = check_tuple( payload_base,
                                  i_section,
                                  tuple );
            if( errhdl ) { break; }

            uint64_t base_addr = tuple->hdatAbsAddr + payload_base;
            hdatHDIF_t* hsvc_header =
              reinterpret_cast<hdatHDIF_t*>(base_addr);
            TRACUCOMP( g_trac_runtime, "hsvc_header=%p", hsvc_header );

            // Check the headers and version info
            errhdl = check_header( payload_base,
                                   hsvc_header,
                                   HSVC_DATA_HEADER );
            if( errhdl ) { break; }

            hdatHDIFDataHdr_t* sys_header =
              reinterpret_cast<hdatHDIFDataHdr_t*>
              (hsvc_header->hdatDataPtrOffset + base_addr);
            TRACUCOMP( g_trac_runtime, "sys_header=%p", sys_header );
            // Make sure the Data Header is pointing somewhere valid
            errhdl = verify_hdat_address( payload_base,
                                          sys_header,
                                          sizeof(hdatHDIFDataHdr_t) );
            if( errhdl ) { break; }

            o_dataAddr = sys_header->hdatOffset + base_addr;
            o_dataSize = sys_header->hdatSize;
        }
        // Host Services Node Data
        else if( RUNTIME::HSVC_NODE_DATA == i_section )
        {
            // Find the right tuple and verify it makes sense
            hdat5Tuple_t* tuple = &(spira->hdatDataArea[HSVC_DATA]);
            TRACUCOMP( g_trac_runtime, "HSVC_NODE_DATA tuple=%p", tuple );
            errhdl = check_tuple( payload_base,
                                  i_section,
                                  tuple );
            if( errhdl ) { break; }

            uint64_t base_addr = tuple->hdatAbsAddr + payload_base;
            hdatHDIF_t* hsvc_header =
              reinterpret_cast<hdatHDIF_t*>(base_addr);
            TRACUCOMP( g_trac_runtime, "hsvc_header=%p", hsvc_header );

            // Check the headers and version info
            errhdl = check_header( payload_base,
                                   hsvc_header,
                                   HSVC_DATA_HEADER );
            if( errhdl ) { break; }

            hdatHDIFChildHdr_t* node_header =
              reinterpret_cast<hdatHDIFChildHdr_t*>
              (hsvc_header->hdatChildStrOffset + base_addr);
            TRACUCOMP( g_trac_runtime, "node_headers=%p", node_header );
            // Make sure the Child Header is pointing somewhere valid
            errhdl = verify_hdat_address( payload_base,
                                          node_header,
                                          sizeof(hdatHDIFChildHdr_t) );
            if( errhdl ) { break; }

            hdatHDIF_t* node_data_headers =
              reinterpret_cast<hdatHDIF_t*>
              (node_header->hdatOffset + base_addr);
            // Make sure the headers are all in a valid range
            errhdl = verify_hdat_address( payload_base,
                             node_data_headers,
                             sizeof(hdatHDIF_t)*(node_header->hdatCnt) );
            if( errhdl ) { break; }

            // Loop around all instances because the data could be sparsely populated
            TRACUCOMP( g_trac_runtime, "nodecount=%d", node_header->hdatCnt );
            bool foundit = false;
            uint32_t found_instances = 0;
            for( uint8_t index = 0; index < node_header->hdatCnt; index++ )
            {
                TRACUCOMP( g_trac_runtime, "index=%d", index );
                // Check the headers and version info
                errhdl = check_header( payload_base,
                                       &(node_data_headers[index]),
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
                errhdl = verify_hdat_address( payload_base,
                                              local_node_header,
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
                TRACFCOMP( g_trac_runtime, "get_host_data_section> HSVC_NODE_DATA instance %d of section %d is unallocated", i_instance, i_section );
                /*@
                 * @errortype
                 * @moduleid     RUNTIME::MOD_HDATSERVICE_GET_HOST_DATA_SECTION
                 * @reasoncode   RUNTIME::RC_NO_HSVC_NODE_DATA_FOUND
                 * @userdata1    Mainstore address of node_data_headers
                 * @userdata2[0:31]    Requested Instance
                 * @userdata2[32:63]   Bitmask of discovered instances
                 * @devdesc      Requested instance of HSVC_NODE_DATA is
                 *               unallocated
                 */
                errhdl = new ERRORLOG::ErrlEntry(
                                  ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                  RUNTIME::MOD_HDATSERVICE_GET_HOST_DATA_SECTION,
                                  RUNTIME::RC_NO_HSVC_NODE_DATA_FOUND,
                                  reinterpret_cast<uint64_t>(node_data_headers),
                                  TWO_UINT32_TO_UINT64(i_instance,
                                                       found_instances));
                errhdl->collectTrace("RUNTIME",1024);
                break;
            }

        }
        // IPL Parameters : System Parameters
        else if( RUNTIME::IPLPARMS_SYSTEM == i_section )
        {
            // Find the right tuple and verify it makes sense
            hdat5Tuple_t* tuple = &(spira->hdatDataArea[HDAT_IPL_PARMS]);
            TRACUCOMP( g_trac_runtime, "IPLPARMS_SYSTEM tuple=%p", tuple );
            errhdl = check_tuple( payload_base,
                                  i_section,
                                  tuple );
            if( errhdl ) { break; }

            uint64_t base_addr = tuple->hdatAbsAddr + payload_base;
            hdatHDIF_t* ipl_parms = reinterpret_cast<hdatHDIF_t*>
              (base_addr);
            TRACUCOMP( g_trac_runtime, "ipl_parms=%p", ipl_parms );

            // Check the headers and version info
            errhdl = check_header( payload_base,
                                   ipl_parms,
                                   IPLPARMS_SYSTEM_HEADER );
            if( errhdl ) { break; }

            hdatHDIFDataHdr_t* internal_data_ptrs =
              reinterpret_cast<hdatHDIFDataHdr_t*>
              (ipl_parms->hdatDataPtrOffset + base_addr);
            TRACUCOMP( g_trac_runtime, "internal_data_ptrs=%p", internal_data_ptrs );
            // Make sure the Header is pointing somewhere valid
            errhdl = verify_hdat_address( payload_base,
                                          internal_data_ptrs,
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
            hdat5Tuple_t* tuple = &(spira->hdatDataArea[HDAT_MS_DUMP_SRC_TBL]);
            TRACUCOMP( g_trac_runtime, "MS_DUMP_SRC_TBL tuple=%p", tuple );
            errhdl = check_tuple( payload_base,
                                  i_section,
                                  tuple );
            if( errhdl ) { break; }

            //Note - there is no header for the MDST
            o_dataAddr = tuple->hdatAbsAddr + payload_base;
            o_dataSize = tuple->hdatActualCnt * tuple->hdatActualSize;
        }
        // MS DUMP Destination Table - MDDT
        else if( RUNTIME::MS_DUMP_DST_TBL == i_section )
        {
            //For security we can't trust the FSP's payload attribute
            //  on MPIPLs for the dump tables.
            //@todo: RTC:59171

            // Find the right tuple and verify it makes sense
            hdat5Tuple_t* tuple = &(spira->hdatDataArea[HDAT_MS_DUMP_DST_TBL]);
            TRACUCOMP( g_trac_runtime, "MS_DUMP_DST_TBL tuple=%p", tuple );
            errhdl = check_tuple( payload_base,
                                  i_section,
                                  tuple );
            if( errhdl ) { break; }

            //Note - there is no header for the MDDT
            o_dataAddr = tuple->hdatAbsAddr + payload_base;
            o_dataSize = tuple->hdatActualCnt * tuple->hdatActualSize;
        }
        // MS DUMP Results Table - MDRT
        else if( RUNTIME::MS_DUMP_RESULTS_TBL == i_section )
        {
            //For security we can't trust the FSP's payload attribute
            //  on MPIPLs for the dump tables.
            //@todo: RTC:59171

            // Find the right tuple and verify it makes sense
            hdat5Tuple_t* tuple = &(spira->hdatDataArea[HDAT_MS_DUMP_RSLT_TBL]);
            TRACUCOMP( g_trac_runtime, "MS_DUMP_RESULTS_TBL tuple=%p", tuple );
            errhdl = check_tuple( payload_base,
                                  i_section,
                                  tuple );
            if( errhdl ) { break; }

            //Note - there is no header for the MDRT
            o_dataAddr = tuple->hdatAbsAddr + payload_base;
            //return the total allocated size since it is empty at first
            o_dataSize = tuple->hdatAllocSize * tuple->hdatAllocSize;
        }
        // Not sure how we could get here...
        else
        {
            TRACFCOMP( g_trac_runtime, "get_host_data_section> Unknown section %d", i_section );
            /*@
             * @errortype
             * @moduleid     RUNTIME::MOD_HDATSERVICE_GET_HOST_DATA_SECTION
             * @reasoncode   RUNTIME::RC_INVALID_SECTION
             * @userdata1    Section Id
             * @userdata2    <unused>
             * @devdesc      Unknown section requested
             */
            errhdl = new ERRORLOG::ErrlEntry(
                           ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                           RUNTIME::MOD_HDATSERVICE_GET_HOST_DATA_SECTION,
                           RUNTIME::RC_INVALID_SECTION,
                           i_section,
                           0);
            errhdl->collectTrace("RUNTIME",1024);
            break;
        }

        // Make sure the range we return is pointing somewhere valid
        errhdl = verify_hdat_address( payload_base,
                                      o_dataAddr,
                                      o_dataSize );
        if( errhdl ) { break; }

    } while(0);

    TRACFCOMP( g_trac_runtime, "get_host_data_section> o_dataAddr=0x%X, o_dataSize=%d", o_dataAddr, o_dataSize );

    return errhdl;
}


/********************
 Private/Protected Methods
 ********************/

