/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/targeting/common/util.H $                     */
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

#ifndef __TARGETING_COMMON_UTIL_H
#define __TARGETING_COMMON_UTIL_H

/**
 *  @file targeting/common/util.H
 *
 *  @brief Targeting utility functions
 */

#include <targeting/common/attributes.H>

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
} // TARGETING

#endif // __TARGETING_COMMON_UTIL_H
