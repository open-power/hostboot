/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/targeting/common/utilFilter.H $               */
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
#ifndef __TARGETING_COMMON_UTIL_FILTER_H
#define __TARGETING_COMMON_UTIL_FILTER_H

/**
 *  @file targeting/common/utilFilter.H
 *
 *  @brief Targeting Filter utility functions
 */

#include <attributeenums.H>
#include <targeting/common/predicates/predicatebase.H>
#include <targeting/common/iterators/targetiterator.H>
#include <targeting/common/iterators/rangefilter.H>

namespace TARGETING
{

    /**
     * Enum of functional states for use with calls to getChip/ChipletResources
     */
    enum ResourceState
    {
        UTIL_FILTER_ALL,                     // All targets
        UTIL_FILTER_PRESENT,                 // Present at minimum
        UTIL_FILTER_FUNCTIONAL,              // Functional targets only
        UTIL_FILTER_PRESENT_NON_FUNCTIONAL,  //All present and non-fucntional
        UTIL_FILTER_NON_FUNCTIONAL           //All non-fucntional
    };


/**
 * @brief Populate the o_vector with target object pointers based on the
 *        requested class, type, and functional state.
 *
 * @parm[out] o_vector, reference of vector of target pointers.
 * @parm[in]  i_class,  the class of the targets to be obtained
 * @parm[in]  i_type,   the type of the targets to be obtained
 * @parm[in]  i_state,  Selection filter based on ResourceState enum,
 *                      designates all, present, or functional
 *
 * @return N/A
 */
void getClassResources( TARGETING::TargetHandleList & o_vector,
                        CLASS i_class, TYPE  i_type, ResourceState i_state );

/**
 * @brief Predicate function to sort by HUID
 *
 * @parm[in]  t1, Target 1 for HUID comparison against target 2
 * @parm[in]  t2, Target 2 for HUID comparison against target 1
 *
 * @return bool, true if t1 HUID < t2 HUID, false otherwise
 */
inline bool compareTargetHuid(TargetHandle_t t1, TargetHandle_t t2)
{
  return (t1->getAttr<ATTR_HUID>() < t2->getAttr<ATTR_HUID>());
}

/**
 * @brief Predicate function to sort by Affinity path (lexicographical order)
 *
 * @parm[in]  t1, Target 1 for AffinityPath comparison against target 2
 * @parm[in]  t2, Target 2 for AffinityPath comparison against target 1
 *
 * @return bool, true if t1 AffinityPath < t2 AffinityPath, false otherwise
 */
inline bool compareAffinity(TargetHandle_t t1, TargetHandle_t t2)
{
    EntityPath t1_Affinity = t1->getAttr<ATTR_AFFINITY_PATH>();
    EntityPath t2_Affinity = t2->getAttr<ATTR_AFFINITY_PATH>();
    return t1_Affinity < t2_Affinity;
}

/**
 * @brief Populate the o_vector with target chip pointers based on the
 *        requested type, and functional state.
 *
 * @parm[out] o_vector, reference of vector of target pointers.
 * @parm[in]  i_type, the type of the chip targets to be obtained
 * @parm[in]  i_state, Selection filter based on ResourceState enum
 *
 * @return N/A
 */
void getChipResources(TARGETING::TargetHandleList & o_vector,
                      TYPE i_type, ResourceState i_state );

/**
 * @brief Populate the o_vector with target enc pointers based on the
 *        requested type, and functional state.
 *
 * @parm[out] o_vector, reference of vector of target pointers.
 * @parm[in]  i_type, the type of the chip targets to be obtained
 * @parm[in]  i_state, Selection filter based on ResourceState enum
 *
 * @return N/A
 */
void getEncResources(TARGETING::TargetHandleList & o_vector,
                      TYPE i_type, ResourceState i_state );

/**
 * @brief Populate the o_vector with target chiplet pointers based on the
 *        requested type, and functional state.
 *
 * @parm[out] o_vector, reference of vector of target pointers.
 * @parm[in]  i_type, the type of the chiplet targets to be obtained
 * @parm[in]  i_state, Selection filter based on ResourceState enum
 *
 * @return N/A
 */
void getChipletResources(TARGETING::TargetHandleList & o_vector,
                      TYPE i_type, ResourceState i_state );


/**
 * @brief Populate the o_vector with target chip pointers based on the
 *        requested type, and functional state.
 *
 * @parm[out] o_vector, reference of vector of target pointers.
 * @parm[in]  i_type, the type of the chip targets to be obtained
 * @parm[in]  i_functional, set to true to return only functional targets
 *
 * @return N/A
 */
void getAllChips(TARGETING::TargetHandleList & o_vector,
                      TYPE i_type, bool i_functional = true );

/**
 * @brief Populate the output target handle list with ASIC target handles based
 *     on the requested type and functional state.
 *
 * @parm[out] o_asics      Reference to a vector holding target pointers
 * @parm[in]  i_asicType   The type of the ASIC targets to be obtained
 * @parm[in]  i_functional Set to true to return only functional targets
 *
 * @return N/A
 */
void getAllAsics(TARGETING::TargetHandleList& o_asics,
                 TYPE i_asicType,
                 bool i_functional = true);

/**
 * @brief Populate the o_vector with target chiplet pointers based on the
 *        requested type, and functional state.
 *
 * @parm[out] o_vector, reference of vector of target pointers.
 * @parm[in]  i_type, the type of the chiplet targets to be obtained
 * @parm[in]  i_functional, set to true to return only functional targets
 *
 * @return N/A
 */
void getAllChiplets(TARGETING::TargetHandleList & o_vector,
                      TYPE i_type, bool i_functional = true );

/**
 * @brief Populate the o_vector with chiplet target object pointers associated
 *        to the input chip
 *
 * @parm[out] o_vector, reference of vector of target pointers.
 * @parm[in]  i_chip, the chip target for retrieving its child chiplets
 * @parm[in]  i_type, the type of the chiplet targets to be obtained
 * @parm[in]  i_functional, set to true to return only functional targets
 *
 * @return N/A
 */
void getChildChiplets(TARGETING::TargetHandleList & o_vector,
               const Target * i_chip, TYPE i_type, bool i_functional = true );


/**
 * @brief Populate the o_vector with target object pointers which are
 *        affinity children of the input target and filters based on a
 *        functional state
 *
 * @parm[out] o_vector, reference of vector of target pointers.
 * @parm[in]  i_target, the target for retrieving affinity-parent targets
 * @parm[in]  i_class, the class of the target to be obtained
 * @parm[in]  i_type, the type of the target to be obtained
 * @parm[in]  i_functional, set to true to return only functional targets
 * @parm[in]  i_state, Selection filter based on ResourceState enum
 *
 * @return N/A
 */
void getChildAffinityTargetsByState ( TARGETING::TargetHandleList& o_vector,
           const Target * i_target, CLASS i_class, TYPE i_type,
           ResourceState i_state );

/**
 * @brief Given an input target, finds all the targets linked to it via a
 *   PERVASIVE_CHILD relationship and writes them to the output vector.
 *   The class, type, and resource state further filter the set of results.
 *
 * @parm[out] o_vector, reference to vector of target pointers
 * @parm[in]  i_target, source target to search from
 * @parm[in]  i_class, class of the targets to be obtained
 * @parm[in]  i_type, type of the targets to be obtained
 * @parm[in]  i_state, specifies state the target should be in
 *
 * @return N/A
 */
void getPervasiveChildTargetsByState (
          TARGETING::TargetHandleList& o_vector,
    const Target*                      i_target,
          CLASS                        i_class,
          TYPE                         i_type,
          ResourceState                i_state );

/**
 * @brief Populate the o_vector with target object pointers which are
 *        affinity children of the input target
 *
 * @parm[out] o_vector, reference of vector of target pointers.
 * @parm[in]  i_target, the target for retrieving affinity-child targets
 * @parm[in]  i_class, the class of the target to be obtained
 * @parm[in]  i_type, the type of the target to be obtained
 * @parm[in]  i_functional, set to true to return only functional targets
 *
 * @return N/A
 */
inline
void getChildAffinityTargets ( TARGETING::TargetHandleList& o_vector,
           const Target * i_target, CLASS i_class, TYPE i_type,
           bool i_functional = true )
{
    getChildAffinityTargetsByState(o_vector, i_target, i_class, i_type,
                                   i_functional ? UTIL_FILTER_FUNCTIONAL :
                                                  UTIL_FILTER_ALL);
}

/**
 * @brief Populate the o_vector with target object pointers which are
 *        affinity parents of the input target and filters based on a
 *        functional state
 *
 * @parm[out] o_vector, reference of vector of target pointers.
 * @parm[in]  i_target, the target for retrieving affinity-parent targets
 * @parm[in]  i_class, the class of the target to be obtained
 * @parm[in]  i_type, the type of the target to be obtained
 * @parm[in]  i_functional, set to true to return only functional targets
 * @parm[in]  i_state, Selection filter based on ResourceState enum
 *
 * @return N/A
 */
void getParentAffinityTargetsByState ( TARGETING::TargetHandleList& o_vector,
           const Target * i_target, CLASS i_class, TYPE i_type,
           ResourceState i_state );
/**
 * @brief Given an input target, finds all the targets linked to it via a
 *   PARENT_PERVASIVE relationship and writes them to the output vector.
 *   The class, type, and resource state further filter the set of results.
 *
 * @parm[out] o_vector, reference to vector of target pointers
 * @parm[in]  i_target, source target to search from
 * @parm[in]  i_class, class of the targets to be obtained
 * @parm[in]  i_type, type of the targets to be obtained
 * @parm[in]  i_state, specifies state the target should be in
 *
 * @return N/A
 */
void getParentPervasiveTargetsByState (
          TARGETING::TargetHandleList& o_vector,
    const Target*                      i_target,
          CLASS                        i_class,
          TYPE                         i_type,
          ResourceState                i_state);

/**
 * @brief Given an input target, finds all the targets linked to it via a
 *   OMIC_PARENT relationship and writes them to the output vector.
 *   The class, type, and resource state further filter the set of results.
 *   Note: It is expected that only 1 target will be added to the output
 *         vector for getParentOmicTargetsByState calls.
 *
 * @parm[out] o_vector, reference to vector of target pointers
 * @parm[in]  i_target, source target to search from
 * @parm[in]  i_class, class of the targets to be obtained
 * @parm[in]  i_type, type of the targets to be obtained
 * @parm[in]  i_state, specifies state the target should be in
 *
 * @return N/A
 */
void getParentOmicTargetsByState (
          TARGETING::TargetHandleList& o_vector,
    const Target*                      i_target,
          CLASS                        i_class,
          TYPE                         i_type,
          ResourceState                i_state);

/**
 * @brief Given an input target, finds all the targets linked to it via a
 *   OMI_CHILD relationship and writes them to the output vector.
 *   The class, type, and resource state further filter the set of results.
 *
 * @parm[out] o_vector, reference to vector of target pointers
 * @parm[in]  i_target, source target to search from
 * @parm[in]  i_class, class of the targets to be obtained
 * @parm[in]  i_type, type of the targets to be obtained
 * @parm[in]  i_state, specifies state the target should be in
 *
 * @return N/A
 */
void getChildOmiTargetsByState (
          TARGETING::TargetHandleList& o_vector,
    const Target*                      i_target,
          CLASS                        i_class,
          TYPE                         i_type,
          ResourceState                i_state);

/**
 * @brief Populate the o_vector with target object pointers which are
 *        affinity parents of the input target
 *
 * @parm[out] o_vector, reference of vector of target pointers.
 * @parm[in]  i_target, the target for retrieving affinity-parent targets
 * @parm[in]  i_class, the class of the target to be obtained
 * @parm[in]  i_type, the type of the target to be obtained
 * @parm[in]  i_functional, set to true to return only functional targets
 *
 * @return N/A
 */
inline
void getParentAffinityTargets ( TARGETING::TargetHandleList& o_vector,
           const Target * i_target, CLASS i_class, TYPE i_type,
           bool i_functional = true )
{
    getParentAffinityTargetsByState(o_vector, i_target, i_class, i_type,
                                    i_functional ? UTIL_FILTER_FUNCTIONAL :
                                                   UTIL_FILTER_ALL);
}

/**
 * @brief return the parent chip target of the specified input chiplet
 *
 * @parm[in]  i_pChiplet, chiplet target for retrieving the parent chip target
 *
 * @return Parent chip target pointer or NULL if error
 */
const Target * getParentChip( const Target * i_pChiplet );

/**
 * @brief return the parent target of the specified input unit
 *
 * @parm[in]  i_unit, unit target used for finding the parent target
 * @parm[in]  i_pType, type of the parent
 *
 * @return Parent target pointer or NULL if error
 */
Target * getParent( const Target * i_unit , TARGETING::TYPE &i_pType );

/**
 * @brief return the immediate parent target of the specified input child
 *
 * @parm[in]  i_child, unit target used for finding the parent target
 *
 * @return Parent target pointer or NULL if error
 */
Target * getImmediateParentByAffinity( const Target * i_child );

/**
 * @brief return the EX target of the specified input core chiplet
 *
 * @parm[in]  i_pCoreChiplet, core chiplet target for retrieving the
 *            EX target
 *
 * @return EX target pointer or NULL if error
 */
const Target * getExChiplet( const Target * i_pCoreChiplet );

/**
 * @brief return the Core target of the specified input EX chiplet
 *
 * @parm[in]  i_pExChiplet, EX chiplet target for retrieving the
 *            Core target
 *
 * @return Core target pointer or NULL if error
 */
const Target * getCoreChiplet( const Target * i_pExChiplet );

/**
 * @brief Return a list of all cards in a system
 *
 * @param[out] o_vector - Vector of the matching targets.
 * @param[in] i_cardType - The Targeting type.
 * @param[in] i_function - Return only Functional cards, default = true
 *
 * @return NONE
 */
void getAllCards( TARGETING::TargetHandleList & o_vector,
                  TYPE i_cardType,
                  bool i_functional = true );


/**
 * @brief Return a list of all cards in a system
 *
 * @param[out] o_vector - Vector of the matching targets.
 * @param[in] i_cardType - The Targeting type.
 * @param[in] i_function - Return only Functional cards, default = true
 *
 * @return NONE
 */

void getAllLogicalCards( TARGETING::TargetHandleList & o_vector,
                         TYPE i_cardType,
                         bool i_functional = true );

/**
 * @brief Returns the list of targets which is an immediate peer of the source
 * target provided by the user.
 *
 * @par Detailed Description:
 *
 * Two types of filter provided here as argument -
 * a.   i_pPeerFilter, constrain the search only to follow PEER_TARGET links for
 *      leaf targets (of the source target, inclusive) that meet the filter
 *      criteria. Omitting the filter crosses all leaf targets of the source
 *      (inclusive) that have PEER_TARGET attributes
 * b.   i_pResultFilter, constrains the result targets returned, such that after
 *      crossing a peer link, only the first target ['if any'] matching the
 *      filter criteria [(searching upwards in the chain of physical parent
 *      targets)] is returned. Omitting the filter has the side effect of
 *      returning the target immediately on the other end of a peer link
 *
 * Filter usage guidelines -
 * 1.   If source target given by the user suports PEER TARGET Attribute &
 *      i_pPeerFilter is also provided then a Target list will be prepared by
 *      going inwards from the source target including the source target.
 *      If the source target doesn't support PEER Target Attribute & filter is
 *      provided then list will be prepared by going inwards from the source
 *      target excluding the source target.
 * 2.   If i_pResultFilter is NULL, then a Peer Target list which includes all
 *      Peer Targets of the source target list mentioned above in step 1, will
 *      be prepared and returned to the user. If i_pResultFilter is not NULL,
 *      then the filter will applied on the parent chain of all peer target
 *      found from the step 1 list above (inclusive), that matches the criteria
 *
 * @param[out] o_peerTargets List of target handles that match the specified
 *             criteria. This will be cleared in case not already done.
 * @param[in] i_pSrcTarget Target from which to search for other targets
 * @param[in] i_pPeerFilter to be applied on the target & target leafs that
 *            has PEER Target Attribute, as provided by user.
 *            i_pPeerFilter Pointer to a predicate to be evaluated against each
 *            candidate target (as determined by the source target, type, and
 *            recursion level parameters).
 * @param[in] i_pResultFilter to be applied on self and the Parent chain of
 *            Peer Targets of the source target & target leaf provided by user
 *            or evaluated on the basis of the i_pPeerFilter given by user.
 *            i_pResultFilter Pointer to a predicate to be evaluated against
 *            each candidate target (as determined by the source target, type,
 *            and recursion level parameters).
 *
 * @return N/A
 */
void getPeerTargets(
          TARGETING::TargetHandleList& o_peerTargets,
    const Target*                      i_pSrcTarget,
    const PredicateBase*               i_pPeerFilter = NULL,
    const PredicateBase*               i_pResultFilter = NULL);

}

#endif // __TARGETING_COMMON_UTIL_H
