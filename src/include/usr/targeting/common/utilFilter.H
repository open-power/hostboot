/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/targeting/common/utilFilter.H $               */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2013              */
/*                                                                        */
/* p1                                                                     */
/*                                                                        */
/* Object Code Only (OCO) source materials                                */
/* Licensed Internal Code Source Materials                                */
/* IBM HostBoot Licensed Internal Code                                    */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* Origin: 30                                                             */
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
        UTIL_FILTER_ALL,        // All targets
        UTIL_FILTER_PRESENT,    // Present at minimum
        UTIL_FILTER_FUNCTIONAL  // Functional targets only
    };


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
void getChildAffinityTargets ( TARGETING::TargetHandleList& o_vector,
           const Target * i_target, CLASS i_class, TYPE i_type, 
           bool i_functional = true );

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
void getParentAffinityTargets ( TARGETING::TargetHandleList& o_vector,
           const Target * i_target, CLASS i_class, TYPE i_type, 
           bool i_functional = true );

/**
 * @brief return the parent chip target of the specified input chiplet
 *
 * @parm[in]  i_pChiplet, chiplet target for retrieving the parent chip target
 *
 * @return Parent chip target pointer or NULL if error
 */
const Target * getParentChip( const Target * i_pChiplet );

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
