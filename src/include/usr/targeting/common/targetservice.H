/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/targeting/common/targetservice.H $            */
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
#ifndef __TARGETING_COMMON_TARGETSERVICE_H
#define __TARGETING_COMMON_TARGETSERVICE_H

/**
 *  @file targeting/common/targetservice.H
 *
 *  @brief Interface for the target service
 *
 *  This header file contains the interface definition for the target service
 *  which is responsible for configuring and aggregating the pool of valid
 *  targets, and providing services to access targets based on various criteria
 */

//******************************************************************************
// Includes
//******************************************************************************

// STD
#include <stdint.h>
#include <stdlib.h>
#include <vector>

// This component
#include <targeting/common/attributes.H>
#include <attributetraits.H>
#include <targeting/common/iterators/iterators.H>
#include <targeting/common/predicates/predicates.H>
#include <targeting/adapters/types.H>
#include <targeting/common/error.H>
#include <pnortargeting.H>

//******************************************************************************
// Utility functions
//******************************************************************************
namespace TARGETING
{
    namespace UTIL
    {
        /**
         *  @brief Returns the top level physical target
         *
         *  Returns the top level (usually system) target. If there is no top
         *  level target, an assertion failure is triggered. Caller does not
         *  need to check for a nullptr top level target
         *
         *  @returns  The top level target, never nullptr.
         */
        Target* assertGetToplevelTarget();

        /**
         *  @brief Returns a bit string of the targets that match the given predicate
         *
         *  @param[in] i_targetList, list of targets to generate a bit string for
         *  @param[in] i_pPredicate, predicate used to determine if a bit should be
         *                           set for a target in the bit string.
         *
         *  @returns a uint32_t representing i_targetList as a bit string based off of
         *           i_pPredicate. The bits set will be based on the target's ATTR_CHIP_UNIT,
         *           ATTR_POSITION with the leftmost/MSB corresponding to CHIP_UNIT/POSITION 0
         */
        template<const ATTRIBUTE_ID A>
        uint32_t targetListToBitString(const TargetHandleList& i_targetList,
                                       const PredicateBase* i_pPredicate = nullptr)
         {
            uint32_t l_targetBitString = 0x00000000;

            do {

            if (i_targetList.empty())
            {
                break;
            }

            for (const auto l_target : i_targetList)
            {
                if ((!i_pPredicate) || (*i_pPredicate)(l_target))
                {
                    l_targetBitString |= (0x80000000 >> (l_target->getAttr<A>()));
                }
            }

            } while (0);

            return l_targetBitString;
        }

        /**
         *  @brief Displays the bit string of the targets under each Proc that match
         *         the given i_pPredicate
         *
         *  @param[in] i_pPredicate, predicate used to determine if a bit should be
         *                           set for a target in the bit string.
         */
        void displayProcChildrenBitmasks(const PredicateBase* const i_pPredicate);

    }; // namespace Util
};

//******************************************************************************
// Method to access the targeting service externally
//******************************************************************************

namespace TARGETING
{
    // Forward declaration of attribute resource provider class.
    class AttrRP;

    class TargetService;

    /*
     * @brief -  typedef for node Id
     */
    typedef uint8_t NODE_ID;

    /* Node 0 */
    static const NODE_ID NODE0 = 0x00;

    /* Invalid Node Id  - to initialize struct variable*/
    static const NODE_ID INVALID_NODE = 0xFF;

    /* Invalid Section Id - to initialize struct variable */
    static const uint8_t INVALID_SECTIONID  = 0xFF;

    /**
     *  @brief Struct specifying different parameters required for section data
     *  update on the sectionId/NodePtr.
     *
     *  Given a struct with the following elements required to point to a
     *  specific section in a given node and the dataPtr to be updated.
     *  Size of the data is always the Page size i.e. 4K
     *
     *  Struct element details -
     *  sectionId - Section Id
     *  nodeId  - Node Id
     *  pageNumber - PageNumber for the section.
     *  dataPtr - Data Ptr
     *  pNodeTarget - Node Targeting Ptr
     *
     */

    struct sectionRefData
    {
        sectionRefData() :
            sectionId(0x00),
            nodeId(INVALID_NODE),
            pageNumber(0),
            dataPtr(NULL),
            pNodeTarget(NULL)
        {
        }

        uint8_t  sectionId;
        uint8_t  nodeId;
        uint16_t  pageNumber;
        uint8_t* dataPtr;
        Target*  pNodeTarget;
    };


    /**
     *  @brief Returns a reference to the targeting service singleton
     *
     *  @return Reference to the targeting service
     */
    TARGETING::TargetService& targetService();

#ifdef __HOSTBOOT_MODULE
    /**
     *  @brief Maps a system target to its node target and node ID
    */
    struct SysToNode
    {
        Target*  pNodeTarget; ///< Node target handle (do not delete)
        Target*  pSysTarget;  ///< System target handle (do not delete)
        NODE_ID  nodeId;      ///< Ordinal ID of node

        SysToNode(
                  Target* const i_pNodeTarget,
                  Target* const i_pSysTarget,
                  const NODE_ID       i_nodeId)
                  : pNodeTarget(i_pNodeTarget),
                  pSysTarget(i_pSysTarget),
                  nodeId(i_nodeId)
        {
        }
    };

/**
 *  @brief Aliases related to system->node associations
 */
typedef std::vector< SysToNode >SysToNodeContainer;
typedef SysToNodeContainer::iterator SysToNodeContainerIt;
typedef SysToNodeContainer::const_iterator SysToNodeContainerConstIt;
#endif

/**
 *  @brief Sentinel representing the master processor chip target early in
 *      host boot prior to initialization of the target service.  Needed by the
 *      DD framework to bring PNOR device driver online.  Note this target
 *      cannot be used as input to any target service APIs.
 */
extern Target* const MASTER_PROCESSOR_CHIP_TARGET_SENTINEL;

/**
 *  @brief TargetService class
 *
 *  This class manages the set of possible targets and provides facility to
 *  access specific targets, based on given criteria
 */
class TargetService
{
    public:

        /**
         *  @brief Enum specifying the recursion depth for target searching
         *
         *  Indicates whether to return only IMMEDIATE children/parent of a
         *  target, or ALL children/parents of a target
         */
        enum RECURSION_LEVEL
        {
            IMMEDIATE = 0x01, ///< Return immediate children/parent of a target
            ALL       = 0x02, ///< Return all children/parents of a target
        };

        /**
         *  @brief Enum specifying the type of association between targets
         *
         *  Indicates what relationship the result target should have to the
         *  target in question
         */
        enum ASSOCIATION_TYPE
        {
            PARENT,             ///< The result target(s) should be parents by
                                ///< containment
            CHILD,              ///< The result target(s) should be children by
                                ///< containment
            PARENT_BY_AFFINITY, ///< The result target(s) should be the parents
                                ///< by hardware affinity
            CHILD_BY_AFFINITY,  ///< The result target(s) should be children by
                                ///< Hardware affinity.  For example the child
                                ///< of a memory controller channel target might
                                ///< be a DIMM target
            PERVASIVE_CHILD,    ///< The result target(s) should be units
                                ///< associated with a pervasive target
            PARENT_PERVASIVE,   ///< The result target should be a pervasive
                                ///< target
            OMI_CHILD,          ///< The result target(s) should be an OMI target
            OMIC_PARENT,        ///< The result target should be an OMIC target
            PAUC_CHILD,         ///< The result targets should be OMIC child
                                ///< targets associated with a PAUC parent
            PAUC_PARENT,        ///< The result target should be a PAUC target
            MAX_ASSOCIATION_TYPES, ///< Number of types, must always be last
        };

        /**
         *  @brief Construct the target service
         *
         *  Constructs the target service, but does not actually initialize the
         *  target pool
         *
         *  @post Target service instantiated, but target pool not initialized
         */
        TargetService();

        /**
         *  @brief Destroys the target service
         *
         *  Destroys the target service; it should never be run since it hides
         *  behind a singleton, but is included for completeness
         *
         *  @post Target service is destroyed, and all owned resources are
         *      reclaimed
         */
        ~TargetService();

        /**
         *  @brief Initializes the target service
         *
         *  @par Detailed Description:
         *  Initializes the target service, including determining maximum number
         *  of targets, setting up the target pool, etc. for each node in the
         *  system blueprint local to the subsystem. Should be called once PNOR
         *  is accessible and can be mapped
         *
         *  @param[in] i_maxNodes, max number of nodes to initialize within the
         *      targetservice.
         *
         *  @pre N/A
         *
         *  @post Target service initialized with all possible targets. User
         *      would need to call targetservice().initDefaultMasterNode to make
         *      targetservice fully initialized and ready to be used.
         */
        void init(const size_t i_maxNodes = 1);

        /**
         *  @brief Returns whether target service has initialized or not
         *
         *  @return bool indicating whether service has initialized or not
         *  @retval true Service has initialized and can be used
         *  @retval false Service has not initializated and should not be used
         *      (other than to run the initialization)
         */
        bool isInitialized() const
        {
            return iv_initialized;
        }

        /**
         *  @brief Map iterator types to common aliases
         */
        typedef TargetIterator         iterator;
        typedef ConstTargetIterator    const_iterator;
        typedef TargetRawIterator      rawiterator;
        typedef ConstTargetRawIterator const_rawiterator;

        /**
         *  @brief Return iterator which points to first target service target
         *      (or end() if none)
         *
         *  @return Iterator pointing to first target service target
         */
        iterator begin();

#ifdef __HOSTBOOT_RUNTIME
        /**
         *  @brief Return iterator which points to first target service target
         *      (or end() if none) for a specific node
         *
         *  @param[in] i_nodeId, node Id
         *
         *  @return Iterator pointing to first target service target for node
         */
        iterator begin(NODE_ID i_nodeId);
#endif

        /**
         *  @brief Return rawiterator which points to first target service
         *      target (or end() if none)
         *
         *  @return RawIterator pointing to first target service target
         */
        rawiterator raw_begin();

        /**
         *  @brief Return iterator to const which points to first target service
         *      target (or end() if none)
         *
         *  @return Iterator to const pointing to first target service target
         */
        const_iterator begin() const;

        /**
         *  @brief Return rawiterator to const which points to first target
         *      service target (or end() if none)
         *
         *  @return RawIterator to const pointing to first target service target
         */
        const_rawiterator raw_begin() const;

        /**
         *  @brief Return iterator which points to the "past the end of the
         *      list" target maintained by the target service
         *
         *  @return Iterator pointing to the "past the end of the list" target
         *      maintained by the target service
         */
        iterator end();

        /**
         *  @brief Return rawiterator which points to the "past the end of the
         *      list" target maintained by the target service
         *
         *  @return RawIterator pointing to the "past the end of the list"
         *      target maintained by the target service
         */
        rawiterator raw_end();

        /**
         *  @brief Return iterator to const which points to the "past the end of
         *      the list" target maintained by the target service
         *
         *  @return Iterator to const pointing to the "past the end of the list"
         *      target maintained by the target service
         */
        const_iterator end() const;

        /**
         *  @brief Return rawiterator to const which points to the "past the end
         *      of the list" target maintained by the target service
         *
         *  @return RawIterator to const pointing to the "past the end of the
         *      list" target maintained by the target service
         */
        const_rawiterator raw_end() const;

        /**
         *  @brief Allow iterator access to the target service's target store
         */
        friend class _TargetIterator<Target*>;
        friend class _TargetIterator<const Target*>;

        /**
         *  @brief Allow rawiterator access to the target service's target store
         */
        friend class _TargetRawIterator<Target*>;
        friend class _TargetRawIterator<const Target*>;

        /**
         *  @brief Return the value of iv_processorModel
         *
         *  @return ATTR_MODEL_type the model type of the master processor
         */
        ATTR_MODEL_type getProcessorModel(void);

        /**
         *  @brief Returns the top level physical target
         *
         *  Returns the top level (usually system) target.  Caller must check
         *  for a NULL top level target
         *
         *  @param[out] o_targetHandle Top level target handle
         *
         *  @pre N/A
         *
         *  @post The returned handle is NULL if a top level target doesn't
         *      exist or service not initialized, otherwise it references a
         *      valid top level target
         */
        void getTopLevelTarget(
            Target*& o_targetHandle) const;

        /**
         *  @brief Returns whether specified entity path corresponds to a real
         *      target
         *
         *  Consults the specified entity path and searches through all
         *  available targets to find a matching entity path attribute.  If it
         *  finds a match, then the associated target exists, otherwise it does
         *  not exist
         *
         *  @param[in] i_entityPath Entity path to verify for existence
         *  @param[out] o_exists Whether the entity path corresponds to a
         *      target
         *
         *  @pre N/A
         *
         *  @post "true" returned to caller if specified entity path exists,
         *      "false" if not or service not initialized
         */
        void exists(
            const EntityPath& i_entityPath,
                  bool&       o_exists) const;

        /**
         *  @brief Returns a target handle which has an associated entity path
         *      matching the specified entity path
         *
         *  Returns a target handle which has an associated entity path
         *  matching the specified entity path.  Caller must check the
         *  returned handle for NULL.
         *
         *  @param[in] i_entityPath Entity path for which to find the matching
         *      target handle
         *
         *  @note toTarget implements a pre-check for an already
         *      existing cached result to improve performance.
         *      The memoize utility will check its cache and if
         *      a value already exists for the key (in this case
         *      the EntityPath) memoize will return the already
         *      looked up target.  If the memoize cache does not
         *      contain a match, then a subsequent call will be
         *      made to _memoizeTarget to indirectly call _toTarget
         *      (indirection needed to map memoize call invocation).
         *      _toTarget may be an expensive lookup, searching the
         *      full target model.
         *
         *  @post NULL returned to caller if no match was found or service
         *      not initialized, otherwise a valid handle returned
         *
         *  @return Target handle
         *
         *  @retval NULL No target match found
         *  @retval !NULL Handle to the corresponding target
         */
        Target* toTarget(
            const EntityPath& i_entityPath) const;

        /**
         *  @brief returns the count for the number of possible targets found
         *         of type i_targetType for the current system config
         *
         *  @param[in] i_targetType, the target TYPE to count
         *
         *  @note getMaxNumTargets implements a pre-check for an
         *        already existing cached result to improve performance.
         *        The memoize utility will check its cache and if
         *        a value already exists for the key (in this case
         *        the target TYPE) memoize will return the already
         *        calculated number of targets. If the memoize cache
         *        does not contain a match, then a subsequent call
         *        will be made to _memoizeTargetCount to count the
         *        targets. _memoizeTargetCount may be an expensive
         *        lookup, searching the full target model.
         *
         *  @returns count of all possible i_targetType targets on the system
         */
        size_t getMaxNumTargets(TYPE i_targetType);

        /**
         *  @brief Returns the master processor chip target handle
         *
         *  Returns the master processor chip target handle.  On systems
         *  without an alternate master, it returns a handle to the only master,
         *  if found (NULL otherwise).  On systems with multiple potential
         *  masters, it returns a target handle to the acting master (NULL
         *  otherwise).  If targeting information is not yet accessible (very
         *  early in the host boot IPL), the returned target handle will be a
         *  sentinel value representing the master (whichever it may be)
         *
         *  @param[out] o_masterProcChipTarget Target handle referring to the
         *      current master processor chip (the one connected to PNOR)
         *  @param[in]  i_pNodeTarget
         *      Handle to the node target to search for the acting master
         *      processor.  If NULL, HB will search whatever node it's
         *      running on, and FSP will search the physical drawer containing
         *      the lowest ordered fabric node ID.         *
         *  @param[in] i_onlyFunctional
         *      Specifies whether to limit the search to only functional chips.
         *      If true, will only return a functional chip.  If false, which
         *      is the default, the functional state of the chips are not
         *      checked.
         *
         *  @pre Target Service must be initialized
         *
         *  @post Master processor chip target returned or NULL is returned if
         *  targetservice is not yet initialized or user passed an invalid node
         *  target to get the master proc handle
         */
        void masterProcChipTargetHandle(
            Target*& o_masterProcChipTargetHandle,
            const Target*  i_pNodeTarget = NULL,
            const bool     i_onlyFunctional = false) const;

        /**
         *  @brief Returns the master processor chip target handle
         *
         *  Returns the master processor chip target handle for the given (or
         *  defaulted) node.  On nodes without an alternate master,
         *  it returns a handle to the only master, if found (NULL otherwise).
         *  On nodes with multiple potential
         *  masters, it returns a target handle to the acting master (NULL
         *  otherwise).  If targeting information is not yet accessible (very
         *  early in the host boot IPL), the returned target handle will be a
         *  sentinel value representing the master (whichever it may be)
         *
         *  @param[out] o_masterProcChipTarget
         *      Target handle of acting master processor chip for the given
         *      node (the one connected to PNOR)
         *  @param[in] i_pNodeTarget
         *      Target handle of node to search.  If NULL, HB will search
         *      whatver node it's running on, andFSP will search the physical
         *      drawer containing the lowest orderd fabric node ID
         *  @param[in] i_onlyFunctional
         *      Specifies whether to limit the search to only functional chips.
         *      If true, will only return a functional chip.  If false, which
         *      is the default, the functional state of the chips are not
         *      checked.
         *
         *  @pre Target Service must be initialized
         *
         *  @post Master processor chip target returned or a dummy value
         *      representing the acting master processor chip if the targeting
         *      information is not yet initialized
         *
         *  @return Error log handle indicating the status of the request
         *
         *  @retval NULL  Success, Master Proc handle is returned to the user
         *  @retval !NULL Failure, Failed to find the Master Proc Handle & NULL
         *      is returned to user
         */
        errlHndl_t queryMasterProcChipTargetHandle(
                  Target*& o_masterProcChipTargetHandle,
            const Target*  i_pNodeTarget = NULL,
            const bool     i_onlyFunctional = false) const;

        /**
         *  @brief Returns whether the specified entity path attribute exists
         *      for a specified target, and if so, the value of that attribute
         *
         *  Returns whether the specified entity path attribute exists for a
         *  specified target, and if so, the value of that attribute.  If the
         *  target doesn't exist, or the attribute doesn't correspond to an
         *  entity path attribute, or the entity path attribute doesn't exist
         *  for the target, then the routine returns false and the entity path
         *  value is invalid.
         *
         *  @param[in] i_attr Entity path attribute to read
         *  @param[in] i_pTarget Target handle to read the attribute from
         *  @param[out] o_entityPath Value of the target's associated entity
         *      path value
         *
         *  @pre N/A
         *
         *  @post See "return"
         *
         *  @return bool indicating whether the specified attribute exists
         *      for the specified target and whether the returned entity path
         *      value is valid
         *
         *  @retval true Specified attribute exists, entity path is valid
         *  @retval false Specified attribute does not exist, entity path is
         *      invalid
         */
        bool tryGetPath(
                  ATTRIBUTE_ID i_attr,
            const Target*      i_pTarget,
                  EntityPath&  o_entityPath) const;

        /**
         *  @brief Returns handles to targets associated to the specified
         *      target in a specific way, in depth first order
         *
         *  Returns handles to targets associated to the specified target,
         *  as indicated by an association type.  Based on the specified
         *  recursion level, the routine will determine the immediate
         *  associations, or all possible associations.  For example, if caller
         *  supplies a processor chip target and asks for its children targets,
         *  the routine will return the next set of targets in the physical
         *  hierarchy.  Conversely if the caller asks for ALL children targets
         *  for said source target, the routine will return all targets
         *  contained within the processor chip.  All targets will be returned
         *  in depth first order.
         *
         *  @param[out] o_list List of target handles that match the specified
         *      criteria.  Caller's list will be cleared initially.
         *  @param[in] i_pTarget Target from which to search for other targets.
         *      Must not be NULL.
         *  @param[in] i_type Type of association linking the specified target
         *      to candidate result targets
         *  @param[in] i_recursionLevel Whether to return candidate targets
         *      immediately associated to the specified target or recursively
         *      associated to it.
         *  @param[in] i_pPredicate Pointer to a predicate to be evaluated
         *      against each candidate target (as determined by the source
         *      target, type, and recursion level parameters).  If the predicate
         *      returns true, the target will be added to the result list.  A
         *      value of NULL acts as a predicate that always returns true.
         *
         *  @pre N/A
         *
         *  @post Caller's list cleared; list of target handles matching the
         *      specified criteria returned
         */
         void getAssociated(
                  TargetHandleList& o_list,
            const Target* const     i_pTarget,
            const ASSOCIATION_TYPE  i_type = CHILD,
            const RECURSION_LEVEL   i_recursionLevel = IMMEDIATE,
            const PredicateBase*    i_pPredicate = NULL) const;

        /**
         *  @brief Dump the target service for debug only
         *
         *  @post Output written to buffer
         */
        void dump() const;

#ifndef __HOSTBOOT_RUNTIME

        /**
         *  @brief This func changes the readOnly section of the targeting data
         *         to be writeable, allowing hostboot to update attributes that
         *         are read-only. After attributes are updated the user should
         *         toggle back to making the section readOnly
         *
         *  This top level interface calls the lower level attribute resource
         *  provider interface to modify R/W permissions on the VMM pages it has
         *  mapped for each of the different sections of the targeting data. This
         *  function specifically provides a way to toggle the ability to write to
         *  the readOnly pages of the targeting data.
         *
         *  @param[in] i_allowWrites If TRUE will change R/W permissions of readOnly
         *                           targeting data to be writable
         *                           If FALSE will change R/W permissions of readOnly
         *                           targeting data to be readOnly
         *
         *  @pre AttrRp must be initialized
         *
         *  @post R/W permissions of the readOnly section of the targeting data will
         *        be modified depending on boolean parameter.
         *
         *  @return Error handle holding any errors accrued during execution
         */
        errlHndl_t modifyReadOnlyPagePermissions(bool i_allowWrites);

        /**
         *  @brief Updates the targeting/attribute section data with the
         *  specified vector parameters.
         *
         *  This is the top level interface, would basically call the lower
         *  level attribute resource provider interface. The lower level
         *  interface would fetch each vector element and update each section
         *  with corresponding data from the offset specified.
         *
         *  @param[in] i_pages, vector of sectionRefData struct
         *
         *  @pre N/A
         *
         *  @post See "return"
         *
         *  @return bool indicates whether the write to section data is
         *  successful or not.
         *
         *  @retval true Section Data update successful
         *  @retval false Section Data update failed.
         */
        bool writeSectionData(const std::vector<sectionRefData>& i_pages);

        /**
         *  @brief Fill up the vector with  the targeting/attribute section
         *  data specified in the sectionId parameter.
         *
         *  This is the top level interface, would basically call the lower
         *  level attribute resource provider interface. The lower level
         *  interface would fetch section data as per the sectionId specified
         *  and push to vector reference.
         *
         *  @param[out] o_pages, vector of sectionRefData struct
         *  @param[in] i_sectionId, section type
         *  @param[in] i_nodeId, node Id
         *
         *  @pre N/A
         *
         *  @post See "return"
         *
         *  @return void would fill up the vectore references with complete
         *  section data in pages.
         *
         */

        void readSectionData(std::vector<sectionRefData>& o_pages,
                const SECTION_TYPE i_sectionId,
                const NODE_ID i_nodeId = NODE0);
#endif

        /**
         *  @brief Get the Next initialized node in the Target Service
         *   This is to support the iterator
         *
         *  It takes the present node id as input and computes the next
         *  incremental caller-visible node available in the system and
         *  return it to the user
         *
         *  @param[in] i_nodeId, present node Id
         *
         *  @return returns uint8_t as next node
         *
         *  @retval success case, Node Id, returns the next incremental
         *  initialized caller-visible node available
         *  @retval, Failure case, invalid node, if the present node is the
         *  last initialized caller-visible node available in incremental
         *  order or user passed an invalid nodeId
         */
        NODE_ID getNextInitializedNode(const NODE_ID i_node) const;

        /**
         *  @brief Get the Next caller-visible Target Handle in incremental
         *  order. This is to support the iterator.
         *
         *  It is take a target handle as input and compute the next incremental
         *  available caller-visible target handle in the system and return it
         *  to the user.
         *
         *  @param[in] i_pTarget, non-NULL Target Handle
         *
         *  @return Target Handle
         *
         *  @retval Target*, returns the next incremental caller-visible
         *   Target Handle
         *  @retval NULL, if the target handle passed is the last visible
         *  target handle available in incremental order in the target service.
         */
        Target* getNextTarget(const Target* i_pTarget) const;

        /**
         *  @brief Sets the isMasterNode Attribute to the Node Target handle
         *  Passed and takes care of syncing master node's system target handle
         *  with non-master system target handles.
         *
         *  @par Detailed Description
         *  It takes the node target handle as input which is required to set as
         *  master node and sets the isMasterNode Attribute associated to true
         *  and also unset the isMasterNode associated with all current master
         *  node target handle. Along with this it also takes care of syncing
         *  master node's system target attributes with non-master node system
         *  target's attribute in the system.
         *
         *  @param[in] i_pTarget, Non-Null Node Target handle
         *
         *  @return error handle is return
         *  @retval Success case, NULL is returned means the master node set and
         *  sync is successful
         *  @return, Failure case, !NULL error handle is returned means the
         *  master node couldn't be set as desired.
         */
        errlHndl_t setMasterNode(const Target* i_pTarget);

        /**
         *  @brief this gives the information whether a system target is
         *  master-node's system target or non-master-node's system target
         *
         *  It is takes system target handle as input and checks whether the
         *  system target is from master-node target tree or non-master node
         *  target tree.
         *
         *  @param[in] i_pTarget, Non-Null System Target handle
         *
         *  @return true, means the system target passed is a non-master node's
         *  system target.
         *  @return false, means the system target passed is a master node's
         *  system target.
         */
        bool isNonMasterNodeSystemTarget(const Target* i_pTarget) const;

        /*
         *  @brief give the total number of nodes in the targeting service
         *  for which node level binaries have been initialized .
         *
         *  @return total number of nodes in the targeting model initiailized.
         */
        uint8_t getNumInitializedNodes() const;

        /**
         *  @brief set the default Master Node and release the intialize flag
         *  for targetservice
         *
         *  @par Detailed Description:
         *  Searches for previous instance of master node, else sets the default
         *  node (i.e. first initialized node) as master node. And then releases
         *  the initialized flag of targetservice, Intializing targetservice
         *  fully
         *
         *  @pre targetservice().init() should have been called before this.
         *
         *  @post Target service is fully initialized along with a default
         *  master node.
         */

        void initDefaultMasterNode();

        /**
         *  @brief Returns the Node Target handle of the Master node in the
         *  system.
         *
         *  @par Detailed Description:
         *  Returns the Node Target handle of the Master node in the system.
         *  Caller must check for NULL Target handle
         *
         *  @param[out] o_masterNodeTarget node target handle of the master node
         *  in the system
         *
         *  @pre TargetService must be initialized.
         *
         *  @post Returns the node target handle of the master node. User
         *  will always get a valid target else targetservice will assert.
         *
         *  @return void
         */
        void getMasterNodeTarget(Target*& o_masterNodeTarget) const;

        /**
         *  @brief Returns Array of Targets from Targeting Image.
         *
         *  @par Detailed Description:
         *  Returns a pointer to the Array of Targets found in the Targeting
         *  Image as provided by the Attribute Data.
         *
         *  @param[in] i_attrData pointer to attribute data
         *
         *  @param[in] i_nodeId, node ID for the targeting image
         *
         *  @param[in] i_attrRP pointer to attribute resource provider
         *
         *  @param[out] o_maxTargets maximum targets in image
         *
         *  @pre TargetService must be initialized.
         *
         *  @post Returns pointer to Array of Targets from Targeting Image.
         *
         *  @return Target*
         */
        Target* getTargetArray(void *i_attrData,
                               NODE_ID i_nodeId,
                               AttrRP *i_attrRP,
                               uint32_t &o_maxTargets);

        /**
         *  @brief Returns Target Attribute information.
         *
         *  @par Detailed Description:
         *  Returns the Target Attribute information for the specified
         *  target and resource provider.
         *
         *  @param[in] i_target pointer to target
         *
         *  @param[in] i_attrRP pointer to attribute resource provider
         *
         *  @param[out] o_pAttrId pointer to array of attribute IDs
         *
         *  @param[out] o_ppAttrAddr pointer to array of attribute addresses
         *
         *  @pre TargetService must be initialized.
         *
         *  @post Returns the Target Attribute information for the specified
         *  target and resource provider.
         *
         *  @return Number of attributes in the arrays
         */
        uint32_t getTargetAttributes(Target*i_target,
                                     AttrRP *i_attrRP,
                                     ATTRIBUTE_ID* &o_pAttrId,
                                     AbstractPointer<void>* &o_ppAttrAddr);
        /**
         *  @brief Update the address that PEER_TARGET points to for a given target
         *
         *  @par Detailed Description:
         *  The PEER_TARGET attribute is a pointer to a target's peer. The location
         *  of the target changes when we transition from Hostboot<->HBRT. After
         *  transitioning to runtime, or if we perform an MPIPL this function needs
         *  to be run on all targets in order to insure any target with a PEER_TARGET
         *  attribute gets the PEER_TARGET's pointer looked up again and set to the
         *  new value.
         *
         *  @param[in] i_pTarget pointer to target to update PEER_TARGET attr for
         *
         *  @pre TargetService must be initialized.
         *
         *  @post If the target passed in has a PEER_TARGET , its value will be updated
         *
         *  @return TRUE if target was updated , FALSE if PEER_TARGET was not updated
         */
        bool updatePeerTarget( const Target* i_pTarget);

#ifdef __HOSTBOOT_MODULE
        /**
         *  @brief Reset all hostboot mutex attributes on a given target
         *
         *  @par Detailed Description:
         *  Take in target and check each of its attributes to see if they are
         *  of type hbmutex. If we find a mutex attribute we will run mutex_init
         *  on it to reset it.
         *
         *  @param[in] i_pTarget pointer to target to reset mutex attrs on
         *
         *  @pre TargetService must be initialized.
         *       AttrRp must be initialized
         *
         *  @post All hb mutex attributes on given target have been reset
         *
         *  @return number of mutex attributes reset
         */
        uint32_t resetMutexAttributes( const Target* i_pTarget);

       /**
        *  @brief Returns container which maps each system target to the ordinal
        *      ID/target of node associated with it.
        *
        *  @par Detailed Description:
        *      Returns container which maps each system target to the ordinal
        *      ID/target of node associated with it.  Each node in PNOR
        *      contains one copy of the system target, but targeting usually
        *      only exposes one copy of it to applets and services.
        *      This facility provides convenient access to the
        *      list of those normally hidden system targets, and their
        *      corresponding node targets.  Optionally, it also reports on
        *      control nodes.
        *
        *  @param[in] i_anyNodeType
        *      When false (default), only look up compute nodes.  When true,
        *      look up any node type (compute + control nodes).
        *
        *  @return Container which maps each system target to the ordinal
        *          ID/target of node associated with it
        */
        SysToNodeContainer getSysToNodeAssociations(const bool i_anyNodeType);
#endif

    private:

        /**
         *  @brief Structure, Node information specific
         */
        struct NodeSpecificInfo
        {

            NodeSpecificInfo() :
                nodeId(INVALID_NODE),
                initialized(false),
                isMasterNode(false),
                targets(NULL),
                maxTargets(0),
                pPnor(NULL)
            {
            }

            NODE_ID     nodeId;       ///< Node Id for the binary file
            bool        initialized;  ///< Is service initialized or not
            bool        isMasterNode; ///< Is this the master node
            Target      (*targets)[]; ///< Pointer to array of target objects
            uint32_t    maxTargets;   ///< Maximum # target objects in the array
            const void* pPnor;        ///< Pointer to the PNOR targeting section
        };

        /**
         *  @brief Node Specific information container
         */
        typedef std::vector< NodeSpecificInfo > NodeData_t;

        /**
         *  @brief Returns the first Target from the first initialized node
         *  from the pool of targets.
         *
         *  @param[out] o_firstTargetPtr First Target handle
         *
         *  @pre Target service must be initialized
         *
         *  @post Target Service returns the first Target from the first
         *  initialized node.
         *
         *  @returns void
         */
        void _getFirstTargetForIterators (Target*& o_firstTargetPtr) const;

#ifdef __HOSTBOOT_RUNTIME
        /**
         *  @brief Returns the first Target from the node's pool of targets if
         *  node is initialized.
         *
         *  @param[out] o_firstTargetPtr First Target handle or nullptr
         *
         *  @param[in] i_nodeId, node Id
         *
         *  @pre Target service must be initialized
         *
         *  @post Target Service returns the first Target from the node if node
         *  is initialized.
         *
         *  @returns void
         */
        void _getFirstTargetForIterators (Target*& o_firstTargetPtr,
                                          NODE_ID i_nodeId) const;
#endif

#if defined (__HOSTBOOT_MODULE) && !defined (__HOSTBOOT_RUNTIME)
       /**
        *  @brief Returns the master processor chip target
        *
        *  @param[out] o_masterProcChipTargetHandle - The master proc chip
        *       target handle or nullptr
        *
        *  @param[in] i_onlyFunctional - only functional procs be considered
        *
        *  @pre Target service must be initialized
        *
        *  @post Target Service returns the master proc target handle
        */
        void _getMasterProcChipTargetHandle(
                                  Target*& o_masterProcChipTargetHandle,
                                  bool i_onlyFunctional) const;
#endif

        /**
         *  @brief Configures the pool of targets
         *
         *  This function computes the maximum number of targets possible based
         *  on the PNOR (or override) image, and updates the target service to
         *  point to the start of the target array, wherever it may reside
         *
         *  @param[in] i_nodeContainer, struct to contain all node
         *  specific information of the type NodeSpecificInfo. May refer to
         *  structure definition
         *
         *  @param[in] i_attrRP, attribute resource provider to use if address
         *  translation is required. Defaults to NULL, ie, AttrRP Singleton.
         *
         *  @pre Target service must not be initialized
         *
         *  @post Target service target pool configured for access
         */
        void _configureTargetPool(NodeSpecificInfo& i_nodeContainer,
                                  AttrRP *i_attrRP = NULL);

        /**
         *  @brief Computes the maximum number of targets, caches the value
         *      and returns it to the caller
         *
         *  Computes the maximum number of targets possible based on the PNOR
         *  (or override) image and returns it to the caller
         *
         *  @param[in/out] io_nodeContainer, struct to contain all node
         *  specific information of the type NodeSpecificInfo. May refer to
         *  structure definition
         *
         *  @param[in] i_attrRP, attribute resource provider to use if address
         *  translation is required. Defaults to NULL, ie, AttrRP Singleton.
         *
         *  @pre Target service must not already be initialized
         *
         *  @post Target service updated with maximum target count in
         *  nodeContainer.
         *
         */
        void _maxTargets(NodeSpecificInfo & io_nodeContainer,
                         AttrRP *i_attrRP = NULL);


        //@NEBA
        /**
         *  @brief Returns handles targets associated to the specified target in
         *      a specific way as indicated by the input parameters.  Returns
         *      results in depth first order.
         *
         *  Returns handles to targets associated to the specified target,
         *  as indicated by an association type.  Based on the specified
         *  recursion level, the routine will determine the immediate
         *  associations, or all possible associations.  For example, if caller
         *  supplies a processor chip target and asks for its children targets,
         *  the routine will return the next set of targets in the physical
         *  hierarchy.  Conversely if the caller asks for ALL children targets
         *  for said source target, the routine will return all targets
         *  contained within the processor chip.  All searching is performed as
         *  a depth first search.  This routine will not clear the caller's
         *  input list when returning results.
         *
         *  @param[out] o_list List of target handles that match the specified
         *      criteria, not cleared by this function.
         *  @param[in] i_pSourceTarget Target from which to search for other
         *      targets.  Must not be NULL.  Function presumes caller has
         *      already screened out NULL targets.
         *  @param[in] i_type Type of association linking the specified target
         *      to candidate result targets
         *  @param[in] i_recursionLevel Whether to return candidate targets
         *      immediately associated to the specified target or recursively
         *      associated to it.
         *  @param[in] i_pPredicate Pointer to a predicate to be evaluated
         *      against each candidate target (as determined by the source
         *      target, type, and recursion level parameters).  If the predicate
         *      returns true, the target will be added to the result list.  A
         *      value of NULL acts as a predicate that always returns true.
         *
         *  @pre Input target must not be NULL
         *
         *  @post List of target handles matching the specified criteria
         *      added to end of caller's list
         */
        void _getAssociationsViaDfs(
                  TargetHandleList&    o_list,
            const Target* const        i_pSourceTarget,
            const ASSOCIATION_TYPE     i_type,
            const RECURSION_LEVEL      i_recursionLevel,
            const PredicateBase* const i_pPredicate) const;

        /**
         *  @brief Computes and stores the Top Level Target into iv_pSys
         *
         *  this should only be called to the exclusion of threads that might
         *   try to read or write iv_pSys.
         *
         *  @param NONE
         *
         *  @pre Target service must already be 'initialized'
         *
         *  @post Target service iv_pSys initialized with top TYPE_SYS
         *  target.
         *
         */
        void _setTopLevelTarget();

        /**
         *  @brief Set the instance variable iv_processorModel to be the value of
         *         attribute ATTR_MODEL of the master processor
         */
        void _setProcessorModel(void);

        /**
         *  @brief Returns a target handle which has an associated entity path
         *      matching the specified entity path
         *
         *  Returns a target handle which has an associated entity path
         *  matching the specified entity path.  Caller must check the
         *  returned handle for nullptr.
         *
         *  @param[in] i_entityPath Entity path for which to find the matching
         *      target handle
         *
         *  @pre N/A
         *
         *  @post nullptr returned to caller if no match was found or service
         *      not initialized, otherwise a valid handle returned
         *
         *  @return Target handle
         *
         *  @retval nullptr No target match found
         *  @retval !nullptr Handle to the corresponding target
         */
        Target* _toTarget(
            const EntityPath& i_entityPath) const;

        /**
         *  @brief Returns a target handle which has an associated entity path
         *      matching the specified entity path
         *
         *  Returns a target handle which has an associated entity path
         *  matching the specified entity path.  Caller must check the
         *  returned handle for nullptr.
         *
         *  This internal call is needed to match the semantics of the
         *  memoize call invocation.
         *
         *  @param[in] i_entityPath Entity path for which to find the matching
         *      target handle
         *  @param[out] o_target Target handle, nullptr if no match or
         *      service not initialized, otherwise a valid handle
         *
         *  @pre N/A
         *
         *  @post o_target nullptr if no match was found or service
         *      not initialized, otherwise a valid handle returned
         *
         *  @return int, indicates success or failure
         *  @retval zero success, non-zero failure
         */
        static int _memoizeTarget(EntityPath, Target*& o_target);

        /**
         *  @brief gets all the possible targets associated with a target
         *         TYPE, counts them, and returns the value calculated
         *
         *  @note This internal call is needed to match the semantics of the
         *        memoize call invocation.
         *
         *  @param[in]  i_targetType the TYPE of target to count
         *
         *  @param[out] o_count the number of targets of i_targetType
         *                      possible in the current system config
         *
         *  @return int, indicates success or failure
         *  @retval zero success, non-zero failure
         */
        static int _memoizeTargetCount( TYPE i_targetType, size_t & o_count);

        // Instance variables
        bool        iv_initialized; ///< Is service initialized or not
        Target      * iv_pSys;      // Top Level Target
        ATTR_MODEL_type iv_processorModel; // Model of the master processor

        NodeData_t iv_nodeData;

        // Disable copy constructor / assignment operator

        TargetService(
            const TargetService& i_right);

        TargetService& operator=(
            const TargetService& i_right);
};

/**
 *  @brief Singleton to access the only TargetService; deemphasized
 *      intentionally
 */
class TargetService;

TARG_DECLARE_SINGLETON(TARGETING::TargetService,theTargetService);

} // End namespace TARGETING

#endif // __TARGETING_COMMON_TARGETSERVICE_H
