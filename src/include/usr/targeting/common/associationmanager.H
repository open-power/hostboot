/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/targeting/common/associationmanager.H $       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018                             */
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
#ifndef ASSOCIATIONMANAGER_H
#define ASSOCIATIONMANAGER_H

#include <targeting/common/error.H>
#include <targeting/common/target.H>
#include <targeting/common/targetservice.H>

namespace TARGETING
{

class AssociationManager
{
    public:

    /**
     *  @brief Links system targets to node targets via associations, and vice
     *       versa
     *
     *  @par Detailed Description:
     *      Links system targets to node targets via associations, and vice
     *      versa.  Should be called any time targeting is brought up, as well
     *      as whenever the master system target changes.  Any existing
     *      associations between system and node targets (any variety) are
     *      first discarded.  Should only be attempted when other targeting
     *      operations are quiesced (i.e. exclusive mode).
     *
     *  @return Error log handle indicating the status of the request
     *
     *  @retval nullptr Relinked node and system targets with associations
     *  @retval !nullptr Failed to relink the node and system targets with
     *      associations.
     *
     *      Error log handle points to a valid error log object whose
     *      primary SRC reason code (pError->getSRC()->reasonCode())
     *      indicates the type of error.  This API may return one
     *      of the following "special" reason codes:
     *          N/A
     *
     *  @note It is up to the caller to change the severity of the
     *      returned error based on what it decides to do with it.  By
     *      default any returned error created by this function will
     *      be a non-reported tracing event error log.
     */
    static errlHndl_t reconnectSyAndNodeTargets();

    private:

    /**
     *  @brief Clears assocations of requested type from a system or node target
     *
     *  @par Detailed Description:
     *      For the specified target and association type, clears all
     *      association links that are configured.  Used to clear association
     *      entries in preparation for cross linking nodes to the master system
     *      target (and vice versa).  Relies on association data being
     *      copy-on-write memory mapped.   Any input error will assert, as this
     *      is designed to be used in a well controlled way as a helper
     *      function.  All other errors will return error log handles.
     *
     *  @param[in] i_assocType
     *      Type of association link to clear from input target (supports parent
     *      by containment and parent by affinity for node input targets, and
     *      child by affinity and child by containment for system input
     *      targets).  Asserts if unsupported association type/target combo
     *      specified.
     *  @param[in] i_pSourceSysOrNodeTarget
     *      Pointer to target to clear the associations from.  Must not be
     *      nullptr (asserts in that case).  Must be a node (any variety) or
     *      system target.
     *
     *  @return Error log handle indicating the status of the request
     *
     *  @retval nullptr Cleared the associations from the source target
     *  @retval !nullptr Failed to clear the associations from the source target
     *
     *      Error log handle points to a valid error log object whose
     *      primary SRC reason code (pError->getSRC()->reasonCode())
     *      indicates the type of error.  This API may return one
     *      of the following "special" reason codes:
     *          N/A
     *
     *  @note It is up to the caller to change the severity of the
     *      returned error based on what it decides to do with it.  By
     *      default any returned error created by this function will
     *      be a non-reported tracing event error log.
     *
     *  @pre Should only be called by reconnectSysAndNodeTargets function
     *  @pre Assumes changed memory area is in a copy-on-write memory mapping
     */
    static errlHndl_t _clearAssocsOfTypeFromSysOrNodeTarget(
        const TargetService::ASSOCIATION_TYPE i_assocType,
              Target* const                   i_pSourceSysOrNodeTarget);

    /**
     *  @brief Adds an association of a given type to a source target, pointing
     *      to a given destination target
     *
     *  @par Detailed Description:
     *      Adds an association of a given type to a source target, pointing to
     *      a given destination target.  A common pointer to the destination
     *      target is registered in the association list of the given type, for
     *      the given source target.  Only node and system targets can be linked
     *      in this fashion, and source/destination must be different types.
     *      Any input error will assert, as this is designed to be used in a
     *      well controlled way as a helper function.  All other errors will
     *      return error log handles.
     *
     *  @param[in] i_assocType
     *      Type of association link to add to input target (supports parent by
     *      containment and parent by affinity for node input targets, and child
     *      by affinity and child by containment for system input targets).
     *      Asserts if unsupported association type/target combo specified.
     *  @param[in] i_pSourceSysOrNodeTarget
     *      Pointer to target to add the associations to.  Must not be nullptr
     *      (asserts in that case).  Must be a node (any variety) or system
     *      target. If node target, the i_pDestTarget must refer to a system
     *      target. If system target, the i_pDestTarget must refer to a node
     *      target.
     *  @param[in] i_pDestSysOrNodeTarget
     *      Pointer to target to be linked to.  Must not be nullptr
     *      (asserts in that case).  Must be a node (any variety) or system
     *      target.  If node target, the source target must refer to a system
     *      target.  If system target, the source target must refer to a node
     *      target.
     *
     *  @return Error log handle indicating the status of the request
     *
     *  @retval nullptr Added the association to the source target (points to
     *      destination target)
     *  @retval !nullptr Failed to add the association
     *
     *      Error log handle points to a valid error log object whose
     *      primary SRC reason code (pError->getSRC()->reasonCode())
     *      indicates the type of error.  This API may return one
     *      of the following "special" reason codes:
     *          N/A
     *
     *  @note It is up to the caller to change the severity of the
     *      returned error based on what it decides to do with it.  By
     *      default any returned error created by this function will
     *      be a non-reported tracing event error log.
     *
     *  @pre Should only be called by reconnectSysAndNodeTargets function
     *  @pre Assumes changed memory area is in a copy-on-write memory mapping
     */
    static errlHndl_t _addAssocToSysOrNodeTarget(
        const TargetService::ASSOCIATION_TYPE i_assocType,
              Target* const                   i_pSourceSysOrNodeTarget,
        const Target* const                   i_pDestSysOrNodeTarget);

    // Disable copy constructor
    AssociationManager(const AssociationManager& i_other);

    // Disable assignment operator
    AssociationManager& operator=(const AssociationManager& i_other);

    // Disable CTOR
    AssociationManager();

    // Disable DTOR
    ~AssociationManager();
};

} //End namespace TARGETING
#endif //ASSOCIATIONMANAGER_H
