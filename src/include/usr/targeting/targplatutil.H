/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/targeting/targplatutil.H $                    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2022                        */
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
#include <targeting/common/targetservice.H>
#include <targeting/common/utilFilter.H>
#include <mapattrmetadata.H>

namespace TARGETING
{

namespace UTIL
{

/* @brief Structure of OCC sensor IDs.
 */
union occ_sensor_id_t
{
    uint32_t encoded = 0;
    struct
    {
        uint8_t sensor_type;
        uint8_t reserved;
        uint16_t entity_id;
    } PACKED;

    enum sensor_type_t : uint8_t
    {
        SENSOR_TYPE_CORE = 0xC0,
        SENSOR_TYPE_DIMM = 0xD0,
        SENSOR_TYPE_PROC = 0xE0,
        SENSOR_TYPE_VRM  = 0xE1,
        SENSOR_TYPE_NODE = 0xF0,
        SENSOR_TYPE_UNKNOWN = 0xFF
    };
} PACKED;

/**
 * @brief Dumps to simics the values of each attribute on the target
 *        with the given HUID, or else iterates all targets in the
 *        system and dumps the value of each of their attributes when a
 *        HUID is not supplied.
 *
 * @param[in] i_huid    The HUID of the target to dump attributes for
 *                      (default all targets)
 */
void dumpHBAttrs(uint32_t i_huid = 0);

/* @brief tryGetAttributes<Attrs...>
 *
 *        This is a utility template that iterates a list of attribute IDs,
 *        attempts to read each one of them off of a given Target, and if the
 *        read succeeds, invokes a callback on the value. This lets us read a
 *        number of attributes without having to copy and paste a bunch of code
 *        over and over. The types of the values of the attributes can be
 *        heterogeneous; the only requirement is that the given functor be able
 *        to accept an argument of the appropriate types.
 *
 * Example:
 *
 * tryGetAttributes<ATTR_HUID,
 *                  ATTR_CLASS,
 *                  ATTR_FAPI_POS>::get(target,
 *                                      [](const ATTRIBUTE_ID id,
 *                                         const auto& value)
 *                                      { printk("attr %0x08x = 0x%08x",
 *                                               id, value);
 *                                      });
 *
 */

template<ATTRIBUTE_ID... Attrs>
struct tryGetAttributes;

template<ATTRIBUTE_ID Attr, ATTRIBUTE_ID... Attrs>
struct tryGetAttributes<Attr, Attrs...>
{
    /* @brief get
     *
     *        Reads one or more attributes off of i_target and invokes i_callback
     *        on the values. This is the recursive case.
     *
     * @param[in] i_target    The target to read attributes from
     * @param[in] i_callback  The callback to invoke per attribute value
     */
    template<typename Functor>
    static void get(Target* const i_target, Functor&& i_callback)
    {
        // This function gets called when we have one or more attributes left to
        // read. We read the attribute, call the callback if necessary, and then
        // recur.

        typename AttributeTraits<Attr>::Type attrvalue { };

        if (i_target->tryGetAttr<Attr>(attrvalue))
        {
            i_callback(Attr, attrvalue);
        }

        tryGetAttributes<Attrs...>::get(i_target, std::forward<Functor>(i_callback));
    }
};

template<>
struct tryGetAttributes<>
{
    /* @brief get
     *
     *        Base case of recursion for tryGetAttributes<...>::get
     *
     * @param[in] i_target    The target to read attributes from
     * @param[in] i_callback  The callback to invoke per attribute value
     */
    template<typename Functor>
    static void get(Target* const i_target, Functor&& i_callback)
    {
        // This is the base case of the recursion, no more attributes to read.
    }
};

/* @brief Recursively search a target and its parents for the first occurrence
 *        of an attribute and retrieve its value.
 *
 * @param[in] i_target Target to search
 * @param[in] o_value  Location to store the attribute value.
 * @return    bool     True if the attribute was found, false otherwise.
 * @note o_value is not modified if the attribute is not found.
 */
template<ATTRIBUTE_ID Attr>
bool tryGetAttributeInHierarchy(Target* const i_target,
                                typename AttributeTraits<Attr>::Type& o_value)
{
    if (!i_target)
    {
        return false;
    }

    return i_target->tryGetAttr<Attr>(o_value)
        || tryGetAttributeInHierarchy<Attr>(getImmediateParentByAffinity(i_target), o_value);
}

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
 *  This method should be used when targetService itself is not initialized yet
 *  This simply takes the node target handle of the node which is required to be
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

/* @brief - returns whether the current node is the master node
 *
 * @par Detailed Description:
 * Checks whether the current node is the master node. If yes, returns
 * true to the user, else false.  Master node is not determined until
 * istep 18.9, so this function will return true before then except
 * in the case of a MPIPL (second pass).
 *
 * @return boolean indicating whether request was successful or not
 * @retval, Returns true if the current node is the master node
 * @retval, Returns false if the current node is not the master node
 */
bool isCurrentMasterNode();

#ifndef __HOSTBOOT_RUNTIME
/* @brief - returns the Target of the current Node
 *
 * @par Detailed Description:
 * Hostboot only runs on one node at a time and this interface returns
 * the target of this node.
 *
 * NOTE: Assert if more or less than 1 node is found in targeting information.
 * NOTE: Assert if Node Target is nullptr.
 *
 * @return Pointer to Target of current Node
 */
Target* getCurrentNodeTarget(void);

/* @brief - returns the physical Node Id of the current Node
 *
 * @par Detailed Description:
 * Hostboot only runs on one node at a time and this interface returns
 * the Node Id of this node as defined in its entity path.
 *
 * NOTE: Assert if more or less than 1 node is found in targeting information.
 * NOTE: Assert if Node Target is nullptr.
 *
 * @return unit8_t indicating the Node Id of the current Node
 */
uint8_t getCurrentNodePhysId(void);

/* @brief - returns the physical Node Id of the primary Node
 *
 * @par Detailed Description:
 * Hostboot only runs on one node at a time and this interface returns
 * the Node Id of the primary node as defined in its entity path.
 *
 * NOTE: Assert if more or less than 1 node is found in targeting information.
 *
 * @return int indicating the Node Id of the primary Node
 */
int getPrimaryNodeNumber(void);

#endif

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
 * @brief Returns the Node Target handle of the Master node in the
 * system. Asserts if the master node target is null.
 *
 * @return The master node target. Guaranteed not to be null.
 */
Target* assertGetMasterNodeTarget();

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

/**
 * Return the sensor ID for a given target and sensor name
 *
 * @param[in] i_pTarget - pointer to the Target which sensor is associated
 * @param[in] i_name - the name of the sensor (unused)
 *
 * @return    IPMI Sensor number when IPMI is enabled or HUID if IPMI is not
 *            enabled.
 *
 */
uint32_t getSensorNumber( const Target* i_pTarget,
                          TARGETING::SENSOR_NAME i_name );
/**
 * Return the target for a given sensor number
 *
 * @param[in] i_sensorNumber - Sensor number associated with an
 *                             unknown target
 * @param[in] i_occ          - OCC target providing the context for the sensor
 *                             ID. This is necessary because different
 *                             instances of some sensor types (e.g. CORE
 *                             sensors) may have the same numerical ID and only
 *                             be differentiable in reference to the target they
 *                             are associated with.
 *
 * @return    Target associated with the passed in sensor number, or nullptr
 *            if a matching target can't be found.
 *
 */
TARGETING::Target * getSensorTarget( uint32_t i_sensorNumber,
                                     TARGETING::Target* i_occ);

/**
 * @brief   check_proc0_memory_config   Check memory config for proc0
 *
 *  Loops through all processors gathering topology ID information for
 *  each one and determining which is proc0 based on having the smallest
 *  topology ID.
 *
 *  Checks that proc0 has associated functional dimms.  If it does not have any
 *  functional dimms behind it, look for a proc that does have functional dimms
 *  and swap IDs for these processors.
 *
 *  Loops through all processors again making sure that the effective topology
 *  IDs are the desired IDs.  If the IDs are not as desired, update the
 *  effective ID attributes and flag that an SBE Update is needed.
 *
 *  If SBE Update is needed, sync all attributes to the FSP and perform update.
 *
 * @return errlHndl_t       valid errlHndl_t handle if there was an error
 *                          nullptr if no errors;
 */
errlHndl_t check_proc0_memory_config();

/**
 * @brief Single entry point to access attribute metadata map
 * @return reference to metadata
 */
const AttrMetadataMapper& getMapMetadataForAllAttributes();

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

} // End namespace TARGETING::UTIL

} // End namespace TARGETING

#endif // TARGPLATUTIL_H
