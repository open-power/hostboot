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


namespace DEVTREE
{


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
