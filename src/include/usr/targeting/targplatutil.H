/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/targeting/targplatutil.H $                    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013,2014              */
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

#ifndef TARGPLATUTIL_H
#define TARGPLATUTIL_H

/**
 *  @file targeting/targplatutil.H
 *
 *  @brief Provides interface for general platform specific utilities
 *      and constants to support core functions.
 */

//******************************************************************************
// Includes
//******************************************************************************

// STD
#include <vector>

// OTHER
#include <errl/errlentry.H>

// TARG
#include <targeting/common/targreasoncodes.H>
#include <targeting/common/trace.H>
#include <targeting/common/target.H>

namespace TARGETING
{

namespace UTIL
{

/**
 *  @brief Creates a standard error log of tracing type
 *
 *  @par Detailed Description:
 *      Creates a standard error log of tracing type if it does not already
 *      exist, otherwise appends new SRC to the existing one.  In both cases,
 *      the return code is updated to equal that of the reason code.
 *
 *  @param[in] i_modId
 *      Module ID of the function that is attempting to create the error
 *      (see obj/ppc/hbfw/fsp/targeting/common/targreasoncodes.H
 *      and src/hbfw/fsp/targeting/targplatreasoncodes.H)
 *
 *  @param[in] i_reasonCode
 *      Reason code of the function that is attempting to create the error
 *      (see obj/ppc/hbfw/fsp/targeting/common/targreasoncodes.H
 *      and src/hbfw/fsp/targeting/targplatreasoncodes.H)
 *
 *  @param[in] i_userData1
 *      Caller defined user data word 0
 *
 *  @param[in] i_userData2
 *      Caller defined user data word 1
 *
 *  @param[in] i_userData3
 *      Caller defined user data word 2
 *
 *  @param[in] i_userData4
 *      Caller defined user data word 3
 *
 *  @param[out] io_pError
 *      On input: If NULL, function will ceate a new tracing error, else it
 *          will append new SRC to existing error
 *      On output: Handle will be updated to reflect the created or updated
 *          error log (never NULL)
 *
 *  @return Not applicate / void
 */
void createTracingError(
    const uint8_t     i_modId,
    const uint16_t    i_reasonCode,
    const uint32_t    i_userData1,
    const uint32_t    i_userData2,
    const uint32_t    i_userData3,
    const uint32_t    i_userData4,
          errlHndl_t& io_pError);

/**
 *  @brief Sets the IS_MASTER_NODE attribute in the node target which is going
 *  to be the Master Node and unsets the IS_MASTER_NODE attribute in current
 *  master node target. Internally Syncs the New Master Node's System Target
 *  attributes to other non-master System Target's attribute.
 *
 *  @par Detailed Description:
 *  It takes to be master node target handle as input, Finds the current
 *  master node handle, compares the two, if not equal then Simply sets/unsets
 *  the IS_MASTER_NODE Attr to the tobeMasterNode and currMasterNode Target
 *  respectively. Also Syncs all the System Target Attributes of the Master node
 *  to other system target attributes of the non-master node. If both the
 *  targets are equal it simply returns success.
 *
 *  @param[in] i_pToBeMasterNodeTarget, Non-Null to be Master Node Target handle
 *      note that TYPE must be "NODE" (not control node)
 *
 *  @return error handle indicating whether resuest was successful or not
 *
 *  @retval error handle is null in successful scenario i.e. Master node's
 *  IS_MASTER_NODE attribute is Set and system targets synced-up.
 *  @retval error handle is not null, couldn't set the master node attribute
 *  or system target sync failed.
 *      Error log handle points to a valid error log object whose primary
 *      SRC reason code (pError->getSRC()->reasonCode()) may be set to one of,
 *      but not limited to, the following:
 *          TARG_RC_INVALID_NODE: Invalid Node Target
 */
inline errlHndl_t setMasterNode(Target* i_pToBeMasterNodeTarget)
{
    return NULL;
}

/**
 *  @brief Sets the IS_MASTER_NODE attribute in the node target passed
 *
 *  @par Detailed Description:
 *  This method should be used when targetService itself is not initiliazed yet
 *  This simply takes the node target handle of the node which is requird to be
 *  set as master node, sets the IS_MASTER_NODE Attribute field and returns.
 *  This method doesn't try to find out the current master node or any other
 *  sync related stuff.
 *
 *  @param[in] i_pToBeMasterNodeTarget, Non-Null to be Master Node Target handle
 *      note that TYPE must be "NODE" (not control node)
 *
 *  @return error handle indicating whether request was successful or not
 *
 *  @retval error handle is null in successful scenario i.e. Master node's
 *  IS_MASTER_NODE attribute is Set.
 *  @retval error handle is not null, couldn't set the master node attribute
 *      Error log handle points to a valid error log object whose primary
 *      SRC reason code (pError->getSRC()->reasonCode()) may be set to one of,
 *      but not limited to, the following:
 *          TARG_RC_INVALID_NODE: Invalid Node Target
 */
inline errlHndl_t setDefaultMasterNodeWithoutSync(
    Target* i_pToBeMasterNodeTarget)
{
    return NULL;
}

/* @brief - returns whether a given target is a master node target or not
 *
 * @par Detailed Description:
 * Takes a target and checks whether it is a master node target. If yes returns
 * true to the user else false
 *
 * @param[in] i_pTarget - Non-Null node Target handle(class=enc, type=node)
 *
 * @return boolean indicating whether request was successful or not
 * @retval, Returns true if the passed target is a master node target
 * @retval, Returns false if the passed target is not a master node target.
 */
inline bool isThisMasterNodeTarget(const Target* const i_pTarget)
{
    return true;
}

/* @brief - Syncs the master system target's attribute with non-master system
 * targets.
 *
 * @par Detailed Description:
 * Takes a master system target as input, internally find all the non-master
 * system target and syncs the master system target's attribute over others.
 *
 * @param[in] i_pMasterSysTarget - Non-Null Master System Target
 *
 * @return error handle indicating whether request was successful or not
 * @retval, NULL if it could sync all non-master system targets with the
 * master system target.
 * @retval, !NULL if the sync is failed.
 *      Error log handle points to a valid error log object whose primary
 *      SRC reason code (pError->getSRC()->reasonCode()) may be set to one of,
 *      but not limited to, the following:
 *          TARG_RC_MASTER_SYS_SYNC_FAILED: System Target Sync failed
 */
inline errlHndl_t SyncMasterSystemTarget(const Target* const i_pMasterSysTarget)
{
    return NULL;
}

/* @brief - Tells whether the system target passed is non-master node
 * system target
 *
 * @par Detailed Description:
 * Takes non-null system target as input and tells whether it is a non-master
 * node system target or master node system target
 *
 * @param[in] i_pSysTarget - Non-Null System Target
 *
 * @return boolean indicating whether the request was successful
 * @retval, Returns true if system target is non-master node system target
 * @retval, Returns false if system target is master node system target
 */
inline bool isNonMasterNodeSystemTarget(const Target* const i_pSysTarget)
{
    return false;
}

/**
 * @brief Returns the Node Target handle of the Master node in the
 * system.
 *
 * @par Detailed Description:
 * Returns the Node Target handle of the Master node in the system.
 * Caller must check for NULL Target handle
 *
 * @param[out] o_masterNodeTarget node target handle of the master node
 * in the system
 *
 * @return void
 */
void getMasterNodeTarget(Target*& o_masterNodeTarget);

/**
 *  @brief Returns whether Hostboot subsystem is capable of selecting a node to
 *      act as a master node, whose system target is synchronized to other nodes
 *
 *  @param[out] o_masterNodeCapable
 *      Indicates whether subsystem (Hostboot) is capable of selecting a node to
 *      act as a master node, whose system target is synchronized to other
 *      nodes.  NOTE: When called in Hostboot, always returns false
 */
inline void subsystemIsMasterNodeCapable(bool& o_masterNodeCapable)
{
    o_masterNodeCapable = false;
}

} // End namespace TARGETING::UTIL

} // End namespace TARGETING

#endif // TARGPLATUTIL_H
