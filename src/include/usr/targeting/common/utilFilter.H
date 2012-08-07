/*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/include/usr/targeting/common/utilFilter.H $
 *
 *  IBM CONFIDENTIAL
 *
 *  COPYRIGHT International Business Machines Corp. 2012
 *
 *  p1
 *
 *  Object Code Only (OCO) source materials
 *  Licensed Internal Code Source Materials
 *  IBM HostBoot Licensed Internal Code
 *
 *  The source code for this program is not published or other-
 *  wise divested of its trade secrets, irrespective of what has
 *  been deposited with the U.S. Copyright Office.
 *
 *  Origin: 30
 *
 *  IBM_PROLOG_END_TAG
 */
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
 * @brief Populate the o_vector with chip target object pointers which is
 *        affinity child of the input chiplet
 *
 * @parm[out] o_vector, reference of vector of target pointers.
 * @parm[in]  i_chiplet, the chiplet target for retrieving affinity-child chip
 * @parm[in]  i_type, the type of the chip target to be obtained
 * @parm[in]  i_functional, set to true to return only functional targets
 *
 * @return N/A
 */
void getAffinityChips( TARGETING::TargetHandleList& o_vector,
           const Target * i_chiplet, TYPE i_type, bool i_functional = true );

/**
 * @brief return the parent chip target of the specified input chiplet
 *
 * @parm[in]  i_pChiplet, chiplet target for retrieving the parent chip target
 *
 * @return Parent chip target pointer or NULL if error
 */
const Target * getParentChip( const Target * i_pChiplet );


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


}

#endif // __TARGETING_COMMON_UTIL_H
