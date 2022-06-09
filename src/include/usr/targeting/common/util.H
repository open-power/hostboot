/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/targeting/common/util.H $                     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2022                        */
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

#ifndef __TARGETING_COMMON_UTIL_H
#define __TARGETING_COMMON_UTIL_H

/**
 *  @file targeting/common/util.H
 *
 *  @brief Targeting utility functions
 */

#include <targeting/common/attributes.H>

#ifdef __HOSTBOOT_MODULE
#include <map>
#include <pnortargeting.H>
#include <errl/errlentry.H>
#include <targeting/common/targreasoncodes.H>
#endif

namespace TARGETING
{

class Target;
typedef  Target* TargetHandle_t;
typedef std::vector<TargetHandle_t> TargetHandleList;

/**
 *  @brief Macro which indicates whether to translate addresses or not
 *
 *  @par Detailed Description:
 *      If PPC platform (FSP or Hostboot), if 8 byte pointers then it's
 *      Hostboot, so don't translate.   If 4 byte pointers then it's FSP so
 *      translate.  If !PPC (x86 32 or 64 bit), then always translate
 *
 *  @note List of preprocessor macros defined can be determined by calling:
 *      ppc64-mcp6-gcc -dM -E - < /dev/null
 */
#ifdef __PPC__
#ifndef __HOSTBOOT_RUNTIME
#define TARG_ADDR_TRANSLATION_REQUIRED (sizeof(void*)==4)
#else
#define TARG_ADDR_TRANSLATION_REQUIRED (1)
#endif
#else
#define TARG_ADDR_TRANSLATION_REQUIRED (1)
#endif

namespace PLAT
{

/**
 *  @brief PLAT::PROPERTIES namespace contains constants that control platform
 *      specific behaviors
 */
namespace PROPERTIES
{
#if defined(__HOSTBOOT_RUNTIME) //HBRT only
    static const bool MULTINODE_AWARE = true;
#elif defined(__HOSTBOOT_MODULE) //HB IPL only
    static const bool MULTINODE_AWARE = false;
#else //FSP only
    static const bool MULTINODE_AWARE = true;
#endif

}

}

/**
 * @brief Checks to see if we are running in a hardware simulation
 *    environment, i.e. VPO/VBU  (not Simics)
 *
 * @return true if in VPO/VBU
 */
bool is_vpo( void );

/**
 * @brief  Safely fetch the HUID of a Target
 * @param[in]   Pointer to a Target
 * @return  HUID of Target, Zero if NULL, 0xFFFFFFFF if Sentinel
 */
uint32_t get_huid( const Target* i_target );

/**
 * @brief   Set HWAS Changed Mask to subscription mask
 * @param[in]   Pointer to a Target
 */
void update_hwas_changed_mask(Target * i_target);

/**
 * @brief   Set HWAS Changed Mask to specific bits in subscription mask
 * @param[in]   Pointer to a Target
 * @param[in]   bit mask of bits to set
 */
void update_hwas_changed_mask(Target * i_target, const uint64_t i_bits);

/**
 * @brief   Clear bit in HWAS Changed Mask
 * @param[in]   Pointer to a Target
 * @param[in]   bit to clear
 */
void clear_hwas_changed_bit(Target * i_target, const HWAS_CHANGED_BIT i_bit);

/*
 * brief   Checks if we are loading no payload (PAYLOAD_KIND_NONE)
 * @description  Looks at both ATTR_PAYLOAD_KIND
 *    to determine if we are really have no payload
 * @return  True if No payload will be loaded or started
 */
bool is_no_load( void );

/**
 * Order two processor targets by NODE_ID then CHIP_ID.
 * @param[in] First processor target
 * @param[in] Second processor target
 * @return true if first target < second target
 */
bool orderByNodeAndPosition(  Target* i_firstProc,
                              Target* i_secondProc);

/**
 * @brief   Checks if we want to be in FUSED mode or not.
 * @description  Fused mode is when 2 cores merge to produce
 *               a core with 8 threads versus 4 threaded cores.
 * @return  Non-zero if FUSED mode, 0 if non-FUSED mode
 */
uint8_t  is_fused_mode( );


/**
 * @brief Determine if the given dimm target is an NVDIMM
 *
 * @param[in] i_target : dimm target to check
 *
 * @return bool - True if the given target is an NVDIMM
 */
bool isNVDIMM( const TARGETING::Target * i_target );

/**
 * @brief Given a location code and a target type return a ptr to the
 *        TARGETING::target Hostboot has associated with this information
 *
 * @param[in] i_location_code : Byte vector containing location code info
 * @param[in] i_type : Target Type associated with this location code
 *
 * @return TARGETING::Target * that corresponds w/ the given location code and
 *         target type
 */
TARGETING::TargetHandle_t getTargetFromLocationCode(const std::vector<uint8_t>& i_location_code,
                                                    TARGETING::TYPE i_type);

/**
 * @brief Grab list of NVDIMMs under the processor
 *
 * @param[in] i_proc : processor under which to search for NVDIMMs
 *
 * @return List of DIMM targets that are NVDIMMs
 */
TARGETING::TargetHandleList getProcNVDIMMs( TARGETING::Target * i_proc );

// Shortened type name for convenience
typedef TARGETING::ATTR_PROC_FABRIC_TOPOLOGY_ID_type topoId_t;
typedef TARGETING::ATTR_PROC_FABRIC_TOPOLOGY_MODE_type topoMode_t;
typedef uint8_t groupId_t;
typedef uint8_t chipId_t;

/**
 * @brief bit definitions for 4-bit mode 0/1 topology ID
 */
typedef union
{
    struct // GGGC
    {
        uint8_t rsvd1:4; // 0:3
        uint8_t group:3; // 4:6
        uint8_t chip :1; // 7
    } mode0;
    struct // GGCC
    {
        uint8_t rsvd1:4; // 0:3
        uint8_t group:2; // 4:5
        uint8_t chip :2; // 6:7
    } mode1;
    topoId_t topoId;
}topologyIdBits_t;

/**
 * @brief Extract the fabric group and chip ID's from a 4-bit topology ID
 *
 * @param[in] i_topologyMode The topology mode.
 * @param[in] i_topologyId The topology ID (or effective topology ID)
 * @param[out] o_group The group number
 * @param[out] o_chip The chip number
 *
 */
void extractGroupAndChip(const topoId_t i_topologyId,
                         groupId_t& o_group,
                         chipId_t& o_chip);

#ifdef __HOSTBOOT_MODULE

const uint8_t CURRENT_HBD_PERSISTENT_VERSION = 0;

/**
 * @brief The structure to hold the metadata of an attribute: its
 *        size and persistency.
 */
typedef struct
{
    uint32_t attrSize;
    SECTION_TYPE attrPersistency; // Persistency takes the same values as the
                                  // targeting section types, so we can reuse
                                  // the section type enum here.
} __attribute__((packed)) attr_metadata_t;

/**
 * @brief The structure that holds the attribute ID in addition to
 *        its metadata.
 */
typedef struct
{
    uint32_t attrId;
    attr_metadata_t attrMetadata;
} __attribute__((packed)) section_metadata_t;

/**
 * @brief The structure represents the memory layout of the metadata section.
 *        The metadata section starts with the number of attributes included
 *        followed by each attribute's metadata as defined above.
 */
typedef struct
{
    uint32_t numAttrs;
    section_metadata_t attrMetadata[];
} __attribute__((packed)) section_metadata_mem_layout_t;

/**
 * @brief The structure that contains the metadata of an attribute
 *        and its value in memory. This structure is used to help
 *        map the memory contents of all RW attributes to data that
 *        Hostboot can manipulate.
 */
typedef struct
{
    attr_metadata_t metadata;
    uint8_t value[]; // The actual value of the attribute may be larger than
                      // uint8_t. However, this struct can be overlayed on top
                      // of memory and the address of this uint8_t will point
                      // to the start of the value of the attribute, whose true
                      // size we can fetch out of the metadata section.
} __attribute__((packed)) rw_attr_t;

/**
 * @brief This structure matches the exact layout of each RW attribute's
 *        data in memory. The memory layout of each RW attribute is
 *        attribute hash, HUID, attribute size, attribute persistency,
 *        attribute value.
 */
typedef struct
{
    uint32_t attrHash;
    uint32_t huid;
    rw_attr_t attrData;
} __attribute__((packed)) rw_attr_memory_layout_t;

/**
 * @brief This structure holds the metadata + value of a RW attribute.
 *        The usage of std::vector for the value of the attribute
 *        simplifies memory allocation and management.
 */
typedef struct
{
    attr_metadata_t metadata;
    std::vector<uint8_t>value;
} rw_attr_data_t;

/**
 * @brief This structure represents the memory layout of the whole
 *        RW attribute data section. The RW attribute data section
 *        consists of the hash over the data, the version of the data set,
 *        the size of the data in bytes, the number of attributes included,
 *        followed by the list of all included attributes/data.
 */
typedef struct
{
    uint32_t dataHash;
    uint8_t version;
    uint32_t dataSize;
    uint32_t numAttributes;
    rw_attr_memory_layout_t attrArray[];
}__attribute__((packed)) rw_attr_section_t;

// Note that map access is not thread-safe, so the below data types
// should be used in single-threaded environment or data access protection
// needs to be guaranteed.
// Map of attribute hash -> {size, persistency}
using attr_metadata_map = std::map<uint32_t, attr_metadata_t>;
// Map of attribute hash -> {size, persistency, value}
using rw_attr_data_map = std::map<uint32_t, rw_attr_data_t>;
// Map of HUID -> { hash -> {size, persistency, value} }
using huid_rw_attrs_map = std::map<uint32_t, rw_attr_data_map>;

/**
 * @brief Returns the pointer to the attribute metadata section of the passed
 *        targeting image.
 *
 * @param[in] i_targetingPtr the pointer to a valid targeting image
 * @param[out] o_metadataPtr the pointer to the start of the attribute
 *             metadata section. This pointer is nullified at the start
 *             of the function and will be nullptr if the section is not
 *             found.
 * @return nullptr on success; non-nullptr on error
 */
ERRORLOG::ErrlEntry* getAttrMetadataPtr(void* i_targetingPtr, section_metadata_mem_layout_t*& o_metadataPtr);

/**
 * @brief Parses the input attribute metadata section into a map of format
 *        attributeId : (size, persistency).
 *
 * @param[in] i_attrMetadataPtr the pointer to the beginning of the attribute
 *            metadata section.
 * @param[out] o_map the map of the format attributeId : (size, persistency)
 * @return nullptr on success; non-nullptr on error
 */
ERRORLOG::ErrlEntry* parseAttrMetadataSection(section_metadata_mem_layout_t const* i_attrMetadataPtr, attr_metadata_map& o_map);

/**
 * @brief Parses the input RW attribute data partition (HBD_RW) into a map of
 *        format HUID : (attribute ID : (size of attr, persistency of the attr, value of the attr)).
 *
 * @param[in] i_rwAttributePtr the pointer to a valid RW attribute data partition
 * @param[out] o_parsedData the parsed data in a format described above
 * @return nullptr on success; non-nullptr on error
 */
ERRORLOG::ErrlEntry* parseRWAttributeData(rw_attr_section_t const* i_rwAttributePtr,
                                          huid_rw_attrs_map& o_parsedData);

/**
 * @brief Returns the name of the attribute in string format
 *
 * @param[in] i_attrId the attribute ID to convert to string
 * @param[in] i_rwOnly whether to return the name of RW
 *            attribute only (nullptr will be returned for
 *            non-RW attributes)
 * @return The string name of the attribute
 */
const char* getAttrName(ATTRIBUTE_ID i_attrId, bool i_rwOnly = false);
#endif


} // TARGETING

#endif // __TARGETING_COMMON_UTIL_H
