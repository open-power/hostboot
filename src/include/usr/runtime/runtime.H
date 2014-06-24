/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/runtime/runtime.H $                           */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2014              */
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

#ifndef __RUNTIME_H
#define __RUNTIME_H

#include <stdint.h>
#include <builtins.h>
#include <errl/errlentry.H>

namespace RUNTIME
{

/**
 * @brief Populate attributes in mainstore for HostServices
 *
 * @return errlHndl_t  NULL on success
 */
errlHndl_t populate_attributes( void );

/**
 * @brief Populate node attributes in mainstore for HostServices
 *
 * @return errlHndl_t NULL on Success
 */
errlHndl_t populate_node_attributes( uint64_t i_nodeNum );

/**
 * @brief  Add the host data mainstore location to VMM
 *
 * @description  If running with the standard PHYP payload this function
 *    will map all supported HDAT sections into the VMM to allow access
 *    from user space.  When running in standalone (no payload) mode,
 *    some reserved memory will be mapped in for testcases.  If AVPs are
 *    enabled, no memory will be mapped and the PAYLOAD_KIND attribute
 *    will be set appropriately.
 *
 * @return errlHndl_t  NULL on success
 */
errlHndl_t load_host_data( void );

/**
 * HDAT Sections
 */
enum SectionId
{
    FIRST_SECTION,        //< Placeholder for arrays
    HSVC_NODE_DATA = FIRST_SECTION, //< HostServices Node Attributes
    HSVC_SYSTEM_DATA,     //< HostServices System Attributes
    IPLPARMS_SYSTEM,      //< IPL Parms
    MS_DUMP_SRC_TBL,      //< MDST: Memory Dump Source Table
    MS_DUMP_DST_TBL,      //< MDDT: Memory Dump Destination Table
    MS_DUMP_RESULTS_TBL,  //< MDRT: Memory Dump Results Table
    SPIRA_S,              //< SPIRA-S
    SPIRA_H,              //< SPIRA-H
    SPIRA_L,              //< Legacy SPIRA
    NACA,                 //< NACA
    LAST_SECTION = NACA   //< Placeholder for arrays
};

/**
 * @brief  Get a pointer to the beginning of a particular section of
 *         the host data memory.
 *
 * @description  The returned pointer will not include any header hdat header
 *     information.  
 *
 * @param[in] i_section  Chunk of data to find
 * @param[in] i_instance  Instance of section when there are multiple entries
 * @param[out] o_dataAddr  Physical memory address of data
 * @param[out] o_dataSize  Size of data in bytes, 0 on error, DATA_SIZE_UNKNOWN if unknown
 *
 * @return errlHndl_t  NULL on success
 */
errlHndl_t get_host_data_section( SectionId i_section,
                                  uint64_t i_instance,
                                  uint64_t& o_dataAddr,
                                  size_t& o_dataSize );
const size_t DATA_SIZE_UNKNOWN = 0xFFFFFFFFFFFFFFFF;

/**
 * @brief  Store the actual count of a section in local memory.  
 *
 * @param[in] i_section  Chunk of data to update
 * @param[in] i_count   Actual number of entries
 *
 */
void saveActualCount( RUNTIME::SectionId i_id,
                      uint16_t i_count );

/**
 * @brief  Write the stored actual count to SPIRA
 *
 * @param[in] i_section  Chunk of data to update
 *
 * @return errlHndl_t  NULL on success
 */
errlHndl_t writeActualCount( RUNTIME::SectionId i_id );

/*
 * @brief  Retrieve and log FFDC data relevant to a given section of
 *         host data memory
 *
 * @param[in] i_section  Relevant section
 * @param[inout] io_errlog  Log to append FFDC to
 *
 * @return errlHndl_t  NULL on success
 */
void add_host_data_ffdc( SectionId i_section,
                         errlHndl_t& io_errlog );

/*
 * @brief Set the PAYLOAD_BASE attribute
 * @param[in] i_payloadAddress in MEGABYTES
 */
void setPayloadBaseAddress(uint64_t i_payloadAddress);

}

#endif 
