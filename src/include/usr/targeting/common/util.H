/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/targeting/common/util.H $                     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2015                        */
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
#ifdef __HOSTBOOT_MODULE
    static const bool MULTINODE_AWARE = false;
#else
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

/**
 * @brief   Checks if we are loading a PHYP payload
 * @description  Looks at both ATTR_PAYLOAD_KIND and the MNFG flags
 *    to determine if we are really loading and starting PHYP
 * @param[out]   Current value of PAYLOAD_KIND
 * @return  True if PHYP will be loaded and started
 */
bool is_phyp_load( ATTR_PAYLOAD_KIND_type* o_type = NULL );

/**
 * @brief  Utility function to determine if Sapphire is the payload
 *
 * @description  If the payload kind is Sapphire returns true.  Does
 *    not matter if it is Sapphire with FSP or standalone
 *
 * @return bool  True when loadding sapphire
 */
bool is_sapphire_load(void);

/**
 * @brief  Utility function to determine if an AVP is the payload
 *         Note the actual payload could be something else -- this
 *         is based solely on MFG flags
 *
 * @description  If MFG AVP mode flags are set then returns true
 *      Does not matter what the actual payload is
 *
 * @return bool  True when in AVP mode
 */
bool is_avp_load(void);

/**
 * @brief Utility function to obtain the highest known address in the system
 */
uint64_t get_top_mem_addr(void);

/**
 * @brief Utility function to obtain the lowest known address in the system
 */
uint64_t get_bottom_mem_addr(void);

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

}

#endif // __TARGETING_COMMON_UTIL_H
