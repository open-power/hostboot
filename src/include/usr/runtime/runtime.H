/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/runtime/runtime.H $                           */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2013              */
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
    HSVC_NODE_DATA,       //< HostServices Node Attributes
    HSVC_SYSTEM_DATA,     //< HostServices System Attributes
    IPLPARMS_SYSTEM,      //< IPL Parms
    MS_DUMP_SRC_TBL,      //< MDST: Memory Dump Source Table
    MS_DUMP_DST_TBL,      //< MDDT: Memory Dump Destination Table
    MS_DUMP_RESULTS_TBL,  //< MDRT: Memory Dump Results Table
    SPIRA_S,              //< SPIRA-S
    SPIRA_H,              //< SPIRA-H
    SPIRA_L,              //< Legacy SPIRA
    NACA,                 //< NACA
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
 * @brief  Update the actual count of section.  Only supported for
 *         memory dump results table
 *
 * @param[in] i_section  Chunk of data to find
 * @param[out] i_count   Actual countPhysical memory address of data
 *
 * @return errlHndl_t  NULL on success
 */
errlHndl_t update_host_data_section_actual( SectionId i_section,
                                            uint16_t i_count );

/**
 * @brief This function updates the actual count for the MDRT
 * May be called at anytime, but the actual value is updated
 * to the SPIRA during populate_attributes
 *
 */
void update_MDRT_Count(uint16_t i_count);

/**
 * @brief This function writes the stored count for the MDRT
 * out to the SPIRA
 *
 * @return  errlHndl_t
 */
errlHndl_t write_MDRT_Count(void);

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

}

#endif 
