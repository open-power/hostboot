/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/targeting/common/predicates/predicateattrtanktargetpos.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2015                        */
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
/**
 *  @file targeting/common/predicates/predicateattrtanktargetpos.H
 *
 *  @brief Interface and implementation for a predicate which filters a target
 *      based on whether it matches a given node, pos, and unit pos
 */

#ifndef __TARGETING_COMMON_PREDICATEATTRTANKTARGETPOS_H
#define __TARGETING_COMMON_PREDICATEATTRTANKTARGETPOS_H

//******************************************************************************
// Includes
//******************************************************************************

// STD

// Other Host Boot Components

// Targeting Component
#include <targeting/common/target.H>
#include <targeting/common/attributes.H>
#include <targeting/common/predicates/predicatebase.H>
#include <targeting/common/trace.H>

//******************************************************************************
// Interface and implementation
//******************************************************************************

namespace TARGETING
{

#define TARG_NAMESPACE "TARGETING::"
#define TARG_CLASS "PredicateAttrTankTargetPos::"

class Target;

/**
 *  @brief Templated predicate class which filters a target based on whether
 *         it matches a given node, pos, and unit pos
 *
 *  ** It is important to know what this predicate is being applied to.
 *     The getAttrTankTargetPosData() call in the operator() overloader will
 *     assert if the target is compatible.
 */

class PredicateAttrTankTargetPos : public PredicateBase
{
    public:

        /**
         *  @brief Constructor which configures the predicate to filter targets
         *         on whether it matches the input node, pos, and unit pos
         *
         *  @param[in] i_pos        Attribute tank position
         *  @param[in] i_unitPos    Attribute tank unit position
         *  @param[in] i_node       Attribute tank node position
         *
         */
        PredicateAttrTankTargetPos(
            const uint16_t i_pos,
            const uint8_t  i_unitPos,
            const uint8_t  i_node
            )
            :  iv_pos(i_pos), iv_unitPos(i_unitPos), iv_node(i_node) {}

        /**
         *  @brief Destroys the attribute tank target pos predicate
         */
        virtual ~PredicateAttrTankTargetPos(){}

        /**
         *  @brief Returns whether target mathces the specified node, pos, and
         *         unitPos.
         *
         *  @par Detailed Description: if a wild card was specified in the
         *       constructor (i.e. ATTR_NODE_NA) then the target matches the
         *       corresponding position.
         *
         *  @param[in] i_pTarget
         *      Target handle pointing to the target to compare to.  Must
         *      not be NULL.
         *
         *  @return bool indicating whether the target matches or not
         */
        virtual bool operator()(const Target* i_pTarget) const
        {
            uint16_t l_pos;
            uint8_t  l_unitPos;
            uint8_t  l_node;
            i_pTarget->getAttrTankTargetPosData(l_pos, l_unitPos, l_node);

            // Check if target position matches that
            if ( (iv_pos != AttributeTank::ATTR_POS_NA) && (iv_pos != l_pos) )
            {
                return false;
            }
            if ( (iv_unitPos != AttributeTank::ATTR_UNIT_POS_NA) &&
                 (iv_unitPos != l_unitPos) )
            {
                return false;
            }
            if ( (iv_node != AttributeTank::ATTR_NODE_NA) &&
                 (iv_node != l_node) )
            {
                return false;
            }
            return true;
        }

    private:

        // Position info to compare with that of a target
        uint16_t iv_pos;
        uint8_t  iv_unitPos;
        uint8_t  iv_node;

        TARG_DISABLE_COPY_AND_ASSIGNMENT_OPERATORS(PredicateAttrTankTargetPos);
};

#undef TARG_CLASS
#undef TARG_NAMESPACE

} // End namespace TARGETING

#endif // __TARGETING_COMMON_PREDICATEATTRTANKTARGETPOS_H
