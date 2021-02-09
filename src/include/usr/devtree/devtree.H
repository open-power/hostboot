/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/devtree/devtree.H $                           */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2021                        */
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
#ifndef __DEVTREE_H
#define __DEVTREE_H

/** @file devtree.H
 *  @brief Provides the interfaces to sync the device tree
 */

namespace TARGETING
{
class Target;
};

namespace DEVTREE
{

// The start offset in the libfdt code is incremented before it
// is used, so -1 will actually start at offset 0 = sys level
static constexpr int DTREE_START_OFFSET = -1;

// Name of the property in devtree that matches hostboot PHYS_PATH attr
static constexpr const char* PHYS_BIN_PROPERTY = "ATTR_PHYS_BIN_PATH";

// @brief A structure to associate Target pointers with their devtree nodes.
struct devtree_cache_pair
{
    TARGETING::Target* target = nullptr;
    int devtree_node_offset = 0;
};

/**
 * @brief Build a cache mapping Target pointers to devtree nodes.
 *
 * @param[in] i_fdt  Device tree handle
 * @return           Cache, sorted by target pointer.
 */
std::vector<devtree_cache_pair> devtree_cache_targets(void* const i_fdt);

/**
 * @brief Look up an item in the given device tree Target/node cache.
 *
 * @param[in] i_cache   The cache
 * @param[in] i_target  The target to look up
 * @return              The device tree node, if found, or -FDT_ERR_NOTFOUND otherwise.
 */
int devtree_cache_lookup(const std::vector<devtree_cache_pair>& i_cache,
                         TARGETING::Target* const i_target);

/**
 * @brief Function to sync targeting attributes to devtree
 *        This function does not return an error log.  This is because
 *        it is a friend function inside target.H, which does not know
 *        what an error log is.  Error logs must be committed before return.
 * @return  True if any errors were encountered
 */
bool devtreeSyncAttrs( void )
#ifdef CONFIG_DEVTREE
;
#else
{return false;};
#endif

/**
 * @brief Check if any new targets have showed up, if so force a devtree
 *        sync so that the BMC has an accurate idea of present/functional
 *        parts..
 */
void syncIfChanged()
#ifdef CONFIG_DEVTREE
;
#else
{};
#endif


}; // end namespace

#endif
