/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/runtime/common/hsvc_attribute_structs.H $             */
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
#ifndef __RUNTIME_HSVC_ATTRIBUTE_STRUCTS_H
#define __RUNTIME_HSVC_ATTRIBUTE_STRUCTS_H

/**
 *  @file attribute_structs.H
 *
 *  @brief Shared structures with the HostServices code
 */
struct hsvc_proc_header_t {
    uint64_t procid; //=NNNCCC
    uint64_t offset; //offset to attribute header relative to start of node_data
    uint64_t numAttr; //number of populated attributes
    static const uint64_t NO_PROC = 0xFFFFFFFFFFFFFFFF;
};

struct hsvc_ex_header_t {
    uint64_t parent_procid; //=NNNCCC
    uint64_t chiplet; //physical ex number (0..15)
    uint64_t offset; //offset to attribute header relative to start of node_data
    uint64_t numAttr; //number of populated attributes
    static const uint64_t NO_PROC = 0xFFFFFFFFFFFFFFFF;
    static const uint64_t NO_CHIPLET = 0xFFFFFFFFFFFFFFFF;
};

struct hsvc_attr_header_t {
    uint64_t id; // attribute id
    uint64_t sizeBytes; // size of attribute data
    uint64_t offset; // offset to attribute data relative to start of node_data/sys_data
    static const uint64_t NO_ATTRIBUTE = 0x0;
};

// This is the data that will be in the 'System Attribute Data'
//  section of HDAT
struct hsvc_system_data_t
{
    uint64_t nodePresent; //bitstring of populated nodes, bit0=node0, etc
    uint64_t numAttr; //number of populated attributes
    uint64_t offset; //offset to attribute headers relative to start of system_data
    //blob of data...
};

// This is the data that will be in the 'Node Attribute Data'
//  section of HDAT, there will be 1 of these per physical
//  drawer/book/octant/blade
struct hsvc_node_data_t
{
    uint64_t procOffset; //offset to proc headers relative to start of node_data
    uint64_t exOffset; //offset to ex headers relative to start of node_data
    uint64_t numTargets; //number of proc+ex targets present in this node
    //blob of data...
};

// Custom Attribute IDs
//  Note: Standard fapi::AttributeId are only 32-bits so we can use the top
//        32-bits of the 64-bit value for our own numbers
static const uint64_t HSVC_HUID        = 0xFF000001FFFFFFFF;
static const uint64_t HSVC_PHYS_PATH   = 0xFF000002FFFFFFFF;
static const uint64_t HSVC_ECMD_STRING = 0xFF000003FFFFFFFF;
static const uint64_t HSVC_IBSCOM_BASE = 0xFF000004FFFFFFFF;
static const uint64_t HSVC_PLID        = 0xFF000005FFFFFFFF;

#endif
