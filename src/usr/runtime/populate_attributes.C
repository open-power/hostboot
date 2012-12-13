/*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/usr/runtime/populate_attributes.C $
 *
 *  IBM CONFIDENTIAL
 *
 *  COPYRIGHT International Business Machines Corp. 2012
 *
 *  p1
 *
 *  Object Code Only (OCO) source materials
 *  Licensed Internal Code Source Materials
 *  IBM HostBoot Licensed Internal Code
 *
 *  The source code for this program is not published or other-
 *  wise divested of its trade secrets, irrespective of what has
 *  been deposited with the U.S. Copyright Office.
 *
 *  Origin: 30
 *
 *  IBM_PROLOG_END_TAG
 */

/**
 *  @file populate_attributes.C
 *
 *  @brief Populate attributes for runtime HostServices code
 */

#include <trace/interface.H>
#include <errl/errlentry.H>
#include <fapi.H>
#include <fapiAttributeIds.H>
#include <targeting/common/target.H>
#include <targeting/common/targetservice.H>
#include <targeting/common/utilFilter.H>
#include <runtime/runtime_reasoncodes.H>
#include <runtime/runtime.H>
#include "common/hsvc_attribute_structs.H"
//#include <arch/ppc.H> //for MAGIC_INSTRUCTION

trace_desc_t *g_trac_runtime = NULL;
TRAC_INIT(&g_trac_runtime, "RUNTIME", KILOBYTE);

/**
 * @brief Read a FAPI attribute and stick it into mainstore
 */
#define HSVC_LOAD_ATTR(__fid) \
    fapi::__fid##_Type result_##__fid; \
    _rc = FAPI_ATTR_GET( __fid, _target, result_##__fid ); \
    if( _rc ) { \
        TRACFCOMP( g_trac_runtime, "Error reading 0x%X, rc=0x%X", fapi::__fid, _rc ); \
        _failed_attribute = fapi::__fid; \
        break; \
    } \
    TRACDCOMP( g_trac_runtime, "> %d: 0x%x=%X @ %p", *_num_attr, fapi::__fid, result_##__fid, _output_ptr ); \
    _cur_header = &(_all_headers[(*_num_attr)]); \
    _cur_header->id = fapi::__fid; \
    _cur_header->sizeBytes = sizeof(fapi::__fid##_Type); \
    _cur_header->offset = (_output_ptr - _beginning); \
    memcpy( _output_ptr, &result_##__fid, sizeof(fapi::__fid##_Type) ); \
    _output_ptr += sizeof(fapi::__fid##_Type); \
    (*_num_attr)++;

/**
 * @brief Read a Privileged FAPI attribute and stick it into mainstore
 */
#define HSVC_LOAD_ATTR_P(__fid) \
    fapi::__fid##_Type result_##__fid; \
    _rc = FAPI_ATTR_GET_PRIVILEGED( __fid, _target, result_##__fid ); \
    if( _rc ) { \
        TRACFCOMP( g_trac_runtime, "Error reading 0x%X, rc=0x%X", fapi::__fid, _rc ); \
        _failed_attribute = fapi::__fid; \
        break; \
    } \
    TRACDCOMP( g_trac_runtime, "> %d: 0x%x=%X @ %p", *_num_attr, fapi::__fid, result_##__fid, _output_ptr ); \
    _cur_header = &(_all_headers[(*_num_attr)]); \
    _cur_header->id = fapi::__fid; \
    _cur_header->sizeBytes = sizeof(fapi::__fid##_Type); \
    _cur_header->offset = (_output_ptr - _beginning); \
    memcpy( _output_ptr, &result_##__fid, sizeof(fapi::__fid##_Type) ); \
    _output_ptr += sizeof(fapi::__fid##_Type); \
    (*_num_attr)++;

/**
 * @brief Read the HUID attribute from targeting and stick it into mainstore
 */
#define ADD_HUID(__targ) \
    _huid_temp = TARGETING::get_huid(__targ); \
    TRACDCOMP( g_trac_runtime, "> HUID=%.8X @ %p", _huid_temp, _output_ptr ); \
    _cur_header = &(_all_headers[(*_num_attr)]); \
    _cur_header->id = HSVC_HUID; \
    _cur_header->sizeBytes = sizeof(uint32_t); \
    _cur_header->offset = (_output_ptr - _beginning); \
    memcpy( _output_ptr, &_huid_temp, sizeof(uint32_t) ); \
    _output_ptr += sizeof(uint32_t); \
    (*_num_attr)++;

/**
 * @brief Read the PHYS_PATH attribute from targeting and stick it into mainstore
 */
#define ADD_PHYS_PATH(__targ) \
   { TARGETING::AttributeTraits<TARGETING::ATTR_PHYS_PATH>::Type pathPhys; \
    _rc = !(__targ->tryGetAttr<TARGETING::ATTR_PHYS_PATH>(pathPhys)); \
    _cur_header = &(_all_headers[(*_num_attr)]); \
    _cur_header->id = HSVC_PHYS_PATH; \
    _cur_header->sizeBytes = sizeof(uint8_t) + (sizeof(pathPhys[0]) * pathPhys.size()); \
    _cur_header->offset = (_output_ptr - _beginning); \
    memcpy( _output_ptr, &pathPhys,  _cur_header->sizeBytes ); \
    _output_ptr +=  _cur_header->sizeBytes; \
    (*_num_attr)++; }

/**
 * @brief Read the PHYS_PATH attribute from targeting and stick it into mainstore
 */
#define ADD_ECMD_STRING() \
   { const char* estring = _target->toEcmdString(); \
    _cur_header = &(_all_headers[(*_num_attr)]); \
    _cur_header->id = HSVC_ECMD_STRING; \
    _cur_header->sizeBytes = fapi::MAX_ECMD_STRING_LEN; \
    _cur_header->offset = (_output_ptr - _beginning); \
    memcpy( _output_ptr, estring,  _cur_header->sizeBytes ); \
    _output_ptr +=  _cur_header->sizeBytes; \
    (*_num_attr)++; }

//void Target::toString(char (&o_ecmdString)[MAX_ECMD_STRING_LEN]) const

/**
 * @brief Insert a terminator into the attribute list
 */
#define EMPTY_ATTRIBUTE \
    _cur_header = &(_all_headers[(*_num_attr)]); \
    _cur_header->id = hsvc_attr_header_t::NO_ATTRIBUTE; \
    _cur_header->sizeBytes = 0; \
    _cur_header->offset = 0;


namespace RUNTIME
{

// This is the data that will be in the 'System Attribute Data'
//  section of HDAT
struct system_data_t
{
    enum {
        MAX_ATTRIBUTES = 20
    };

    // header data that HostServices uses
    hsvc_system_data_t hsvc;

    // actual data content
    hsvc_attr_header_t attrHeaders[MAX_ATTRIBUTES];
    char attributes[MAX_ATTRIBUTES*sizeof(uint32_t)];
};

// This is the data that will be in the 'Node Attribute Data'
//  section of HDAT, there will be 1 of these per physical
//  drawer/book/octant/blade
struct node_data_t
{
    enum {
        MAX_PROCS = 8,
        MAX_PROCS_RSV = 16, //leave space for double
        MAX_EX_PER_PROC = 16,
        MAX_EX_RSV = MAX_PROCS_RSV*MAX_EX_PER_PROC,
        NUM_PROC_ATTRIBUTES = 125,
        NUM_EX_ATTRIBUTES = 10,
        MAX_ATTRIBUTES = MAX_PROCS_RSV*NUM_PROC_ATTRIBUTES +
                         MAX_PROCS_RSV*MAX_EX_PER_PROC*NUM_EX_ATTRIBUTES
    };

    // header data that HostServices uses
    hsvc_node_data_t hsvc;

    // actual data content
    hsvc_proc_header_t procs[MAX_PROCS_RSV];
    hsvc_ex_header_t ex[MAX_PROCS_RSV*MAX_EX_PER_PROC];
    hsvc_attr_header_t procAttrHeaders[MAX_PROCS_RSV][NUM_PROC_ATTRIBUTES];
    hsvc_attr_header_t exAttrHeaders[MAX_PROCS_RSV*MAX_EX_PER_PROC][NUM_EX_ATTRIBUTES];
    char attributes[MAX_ATTRIBUTES*sizeof(uint32_t)];
};


/**
 * @brief Populate system attributes for HostServices
 */
errlHndl_t populate_system_attributes( void )
{
    errlHndl_t errhdl = NULL;

    // These variables are used by the HSVC_LOAD_ATTR macros directly
    uint64_t _failed_attribute = 0; //attribute we failed on
    int _rc = 0; //result from FAPI_ATTR_GET

    do {
        TRACDCOMP( g_trac_runtime, "-SYSTEM-" );

        // find our memory range and fill it with some junk data
        uint64_t sys_data_addr = 0;
        uint64_t sys_data_size = 0;
        errhdl = RUNTIME::get_host_data_section(RUNTIME::HSVC_SYSTEM_DATA,
                                                0,
                                                sys_data_addr,
                                                sys_data_size );
        if( errhdl )
        {
            TRACFCOMP( g_trac_runtime, "Could not find a space for the system data" );
            break;
        }
        if( (sys_data_addr == 0) || (sys_data_size == 0) )
        {
            TRACFCOMP( g_trac_runtime, "Invalid memory values for HSVC_SYSTEM_DATA" );
            /*@
             * @errortype
             * @reasoncode       RUNTIME::RC_INVALID_SECTION
             * @moduleid         RUNTIME::MOD_RUNTIME_POP_SYS_ATTR
             * @userdata1        Returned address: sys_data_addr
             * @userdata2        Returned size: sys_data_size
             * @devdesc          Invalid memory values for HSVC_SYSTEM_DATA
             */
            errhdl = new ERRORLOG::ErrlEntry(
                                          ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                          RUNTIME::MOD_RUNTIME_POP_SYS_ATTR,
                                          RUNTIME::RC_INVALID_SECTION,
                                          sys_data_addr,
                                          sys_data_size );
            break;
        }
        system_data_t* sys_data = reinterpret_cast<system_data_t*>(sys_data_addr);
        memset( sys_data, 'A', sizeof(system_data_t) );
        //@fixme - Should test that we aren't going out of bounds

        // These variables are used by the HSVC_LOAD_ATTR macros directly
        uint64_t* _num_attr = NULL; //pointer to numAttr in struct
        char* _output_ptr = NULL; //next memory location to copy attr data into
        char* _beginning = NULL; //position zero for offset calculation
        hsvc_attr_header_t* _all_headers = NULL; //array of attribute headers
        fapi::Target* _target = NULL; //target for FAPI_ATTR_GET
        hsvc_attr_header_t* _cur_header = NULL; //temp variable
        uint32_t _huid_temp = 0; //temp variable

        // Prepare the vars for the HSVC_LOAD_ATTR macros
        _beginning = reinterpret_cast<char*>(sys_data);
        _output_ptr = sys_data->attributes;
        _all_headers = sys_data->attrHeaders;
        _num_attr = &(sys_data->hsvc.numAttr);
        _target = NULL; //system queries use NULL target

        // Grab a system object to work with
        TARGETING::Target* sys = NULL;
        TARGETING::targetService().getTopLevelTarget(sys);

        // Fill in the metadata
        sys_data->hsvc.offset =
          reinterpret_cast<uint64_t>(sys_data->attrHeaders)
          - reinterpret_cast<uint64_t>(sys_data);
        sys_data->hsvc.nodePresent = 0x8000000000000000;
        sys_data->hsvc.numAttr = 0;

        // Fill up the attributes
        ADD_HUID( sys ); // for debug
        ADD_PHYS_PATH( sys );
        // Use a generated file for the list of attributes to load
        #include "common/hsvc_sysdata.C"

        // Add an empty attribute header to signal the end
        EMPTY_ATTRIBUTE;

        TRACFCOMP( g_trac_runtime, "populate_system_attributes> numAttr=%d", sys_data->hsvc.numAttr );

        // Make sure we don't overrun our space
        assert( *_num_attr < system_data_t::MAX_ATTRIBUTES );

        TRACFCOMP( g_trac_runtime, "Run: system_cmp0.memory_ln4->image.save attributes.sys.bin 0x%X %d", sys_data,  sizeof(system_data_t) );

        //@todo - Walk through attribute headers to look for duplicates?
    } while(0);

    // Handle any errors from FAPI_ATTR_GET
    if( _rc )
    {
        /*@
         * @errortype
         * @reasoncode       RUNTIME::RC_ATTR_GET_FAIL
         * @moduleid         RUNTIME::MOD_RUNTIME_POP_SYS_ATTR
         * @userdata1        Return code from FAPI_ATTR_GET
         * @userdata2        FAPI Attribute Id that failed
         * @devdesc          Error retrieving FAPI attribute
         */
        errhdl = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                          RUNTIME::MOD_RUNTIME_POP_SYS_ATTR,
                                          RUNTIME::RC_ATTR_GET_FAIL,
                                          _rc,
                                          _failed_attribute );

    }

    return errhdl;
}

/**
 * @brief Populate node attributes for HostServices
 */
errlHndl_t populate_node_attributes( uint64_t i_nodeNum )
{
    errlHndl_t errhdl = NULL;

    // These variables are used by the HSVC_LOAD_ATTR macros directly
    uint64_t _failed_attribute = 0; //attribute we failed on
    int _rc = 0; //result from FAPI_ATTR_GET

    do {
        TRACDCOMP( g_trac_runtime, "-NODE-" );

        // allocate memory and fill it with some junk data
        uint64_t node_data_addr = 0;
        size_t node_data_size = 0;
        errhdl = RUNTIME::get_host_data_section(
                                    RUNTIME::HSVC_NODE_DATA,
                                    0,
                                    node_data_addr,
                                    node_data_size );
        if( errhdl )
        {
            TRACFCOMP( g_trac_runtime, "Could not find a space for the node data" );
            break;
        }
        if( (node_data_addr == 0) || (node_data_size == 0) )
        {
            TRACFCOMP( g_trac_runtime, "Invalid memory values for HSVC_NODE_DATA" );
            /*@
             * @errortype
             * @reasoncode       RUNTIME::RC_INVALID_SECTION
             * @moduleid         RUNTIME::MOD_RUNTIME_POP_NODE_ATTR
             * @userdata1        Returned address: node_data_addr
             * @userdata2        Returned size: node_data_size
             * @devdesc          Invalid memory values for HSVC_NODE_DATA
             */
            errhdl = new ERRORLOG::ErrlEntry(
                                          ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                          RUNTIME::MOD_RUNTIME_POP_NODE_ATTR,
                                          RUNTIME::RC_INVALID_SECTION,
                                          node_data_addr,
                                          node_data_size );
            break;
        }
        node_data_t* node_data = reinterpret_cast<node_data_t*>(node_data_addr);
        memset( node_data, 'A', sizeof(node_data) );
        //@fixme - Should test that we aren't going out of bounds

        // These variables are used by the HSVC_LOAD_ATTR macros directly
        uint64_t* _num_attr = NULL; //pointer to numAttr in struct
        char* _output_ptr = NULL; //next memory location to copy attr data into
        char* _beginning = NULL; //position zero for offset calculation
        hsvc_attr_header_t* _all_headers = NULL; //array of attribute headers
        fapi::Target* _target = NULL; //target for FAPI_ATTR_GET
        hsvc_attr_header_t* _cur_header = NULL; //temp variable
        uint32_t _huid_temp = 0; //temp variable

        // Prepare the vars for the HSVC_LOAD_ATTR macros
        _beginning = reinterpret_cast<char*>(node_data);
        _output_ptr = node_data->attributes;

        // indices for ex_header and proc_header
        size_t next_proc = 0;
        size_t next_ex = 0;

        // Fill in the metadata
        node_data->hsvc.numTargets = 0;
        node_data->hsvc.procOffset =
          reinterpret_cast<uint64_t>(node_data->procs)
          - reinterpret_cast<uint64_t>(node_data);

        // Get the list of processors
        TARGETING::TargetHandleList all_procs;
        TARGETING::getAllChips( all_procs, TARGETING::TYPE_PROC, false );

        // Loop around all of the proc chips
        for( size_t p = 0; p < all_procs.size(); p++ )
        {
            // Cast to a FAPI type of target.
            fapi::Target fapi_proc( fapi::TARGET_TYPE_PROC_CHIP,
                         reinterpret_cast<void *>
                         (const_cast<TARGETING::Target*>(all_procs[p])) );

            // Compute the processor id to match what HDAT uses
            uint64_t node_id =
              all_procs[p]->getAttr<TARGETING::ATTR_FABRIC_NODE_ID>();
            uint64_t chip_id =
              all_procs[p]->getAttr<TARGETING::ATTR_FABRIC_CHIP_ID>();
            uint32_t procid = (node_id << 3) | (chip_id); //NNNCCC
            TRACDCOMP( g_trac_runtime, "PROC:%d (%.8X)", procid, TARGETING::get_huid(all_procs[p]) );

            // Fill in the metadata
            node_data->procs[p].procid = procid;
            node_data->procs[p].offset =
              reinterpret_cast<uint64_t>(&(node_data->procAttrHeaders[p][0]))
              - reinterpret_cast<uint64_t>(node_data);
            node_data->procs[p].numAttr = 0;
            (node_data->hsvc.numTargets)++;

            // Prepare the variables for the HSVC_LOAD_ATTR calls
            _all_headers = &(node_data->procAttrHeaders[p][0]);
            _num_attr = &(node_data->procs[p].numAttr);
            _target = &fapi_proc;

            // Fill up the attributes
            ADD_HUID( (all_procs[p]) ); // for debug
            ADD_PHYS_PATH( (all_procs[p]) );
            ADD_ECMD_STRING();
            HSVC_LOAD_ATTR_P( ATTR_EC ); 
            HSVC_LOAD_ATTR_P( ATTR_NAME );

            // Use a generated file for the list of attributes to load
            #include "common/hsvc_procdata.C"

            // Add an empty attribute header to signal the end
            EMPTY_ATTRIBUTE;

            TRACFCOMP( g_trac_runtime, "populate_node_attributes> PROC:%d (%.8X) : numAttr=%d", procid, TARGETING::get_huid(all_procs[p]), node_data->procs[p].numAttr );
            
            // Make sure we don't overrun our space
            assert( *_num_attr < node_data_t::NUM_PROC_ATTRIBUTES );

            // Loop around all of the EX chiplets for this proc
            TARGETING::TargetHandleList all_ex;
            TARGETING::getChildChiplets( all_ex, all_procs[p],
                                         TARGETING::TYPE_EX, false );
            for( size_t e = 0; e < all_ex.size(); e++ )
            {
                uint32_t chiplet =
                  all_ex[e]->getAttr<TARGETING::ATTR_CHIP_UNIT>();
                TRACDCOMP( g_trac_runtime, "EX:p%d c%d(%.8X)", procid, chiplet, get_huid(all_ex[e]) );

                // Fill in the metadata
                (node_data->hsvc.numTargets)++;
                node_data->ex[next_ex].parent_procid = procid;
                node_data->ex[next_ex].chiplet = chiplet;
                node_data->ex[next_ex].offset =
                  reinterpret_cast<uint64_t>(
                         &(node_data->exAttrHeaders[next_ex][0]))
                  - reinterpret_cast<uint64_t>(node_data);
                node_data->hsvc.exOffset =
                  reinterpret_cast<uint64_t>(node_data->ex)
                  - reinterpret_cast<uint64_t>(node_data);
                node_data->ex[next_ex].numAttr = 0;

                // Cast to a FAPI type of target.
                fapi::Target fapi_ex( fapi::TARGET_TYPE_EX_CHIPLET,
                                      reinterpret_cast<void *>
                                      (const_cast<TARGETING::Target*>(all_ex[e])) );

                // Prepare the variables for the HSVC_LOAD_ATTR calls
                _all_headers = &(node_data->exAttrHeaders[next_ex][0]);
                _num_attr = &(node_data->ex[next_ex].numAttr);
                _target = &fapi_ex;

                // Fill up the attributes
                ADD_HUID( (all_ex[e]) ); // for debug
                ADD_PHYS_PATH( (all_ex[e]) );
                ADD_ECMD_STRING();
                // Use a generated file for the list of attributes to load
                #include "common/hsvc_exdata.C"

                // Add an empty attribute header to signal the end
                EMPTY_ATTRIBUTE;

                TRACFCOMP( g_trac_runtime, "populate_node_attributes> EX:p%d c%d(%.8X) : numAttr=%d", procid, chiplet, get_huid(all_ex[e]), node_data->ex[next_ex].numAttr );

                // Make sure we don't overrun our space
                assert( *_num_attr < node_data_t::NUM_EX_ATTRIBUTES );

                next_ex++;
            }

            next_proc++;
        }

        // Add an empty Proc marker at the end
        node_data->procs[next_proc].procid = hsvc_proc_header_t::NO_PROC;
        node_data->procs[next_proc].offset = 0;
        node_data->procs[next_proc].numAttr = 0;
        (node_data->hsvc.numTargets)++;

        // Add an empty EX marker at the end
        node_data->ex[next_ex].parent_procid = hsvc_ex_header_t::NO_PROC;
        node_data->ex[next_ex].chiplet = hsvc_ex_header_t::NO_CHIPLET;
        node_data->ex[next_ex].numAttr = 0;

        TRACFCOMP( g_trac_runtime, "Run: system_cmp0.memory_ln4->image.save attributes.node.bin 0x%X %d", node_data,  sizeof(node_data_t) );
    } while(0);

    // Handle any errors from FAPI_ATTR_GET
    if( _rc )
    {
        /*@
         * @errortype
         * @reasoncode       RUNTIME::RC_ATTR_GET_FAIL
         * @moduleid         RUNTIME::MOD_RUNTIME_POP_NODE_ATTR
         * @userdata1        Return code from FAPI_ATTR_GET
         * @userdata2        FAPI Attribute Id that failed
         * @devdesc          Error retrieving FAPI attribute
         */
        errhdl = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                          RUNTIME::MOD_RUNTIME_POP_NODE_ATTR,
                                          RUNTIME::RC_ATTR_GET_FAIL,
                                          _rc,
                                          _failed_attribute );

    }

    return errhdl;
}

/**
 * @brief Populate attributes for HostServices
 */
errlHndl_t populate_attributes( void )
{
    errlHndl_t errhdl = NULL;

    do {
        TRACFCOMP( g_trac_runtime, "Running populate_attributes" );

        // Map the Host Data into the VMM
        errhdl = RUNTIME::load_host_data();
        if( errhdl )
        {
            break;
        }

        errhdl = populate_system_attributes();
        if( errhdl )
        {
            break;
        }

        // Loop through all nodes
        for( TARGETING::TargetService::iterator it = TARGETING::targetService().begin();
             it != TARGETING::targetService().end(); ++it )
        {
            if( (*it)->getAttr<TARGETING::ATTR_TYPE>() == TARGETING::TYPE_NODE )
            {
                //@todo: RTC:50866 : Need an attribute for node position
                errhdl = populate_node_attributes(0);
                if( errhdl )
                {
                    break;
                }
            }
        }

    } while(0);

    return errhdl;
}

} //namespace RUNTIME
