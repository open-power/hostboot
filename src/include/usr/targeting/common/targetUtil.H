/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/targeting/common/targetUtil.H $               */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2019                        */
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
 *  @file
 *
 *  @brief Defines templates methods that require the use of the
 *         class Target and struct Attribute.  Having the methods
 *         in this file helps with circular dependencies issue.
 */

#ifndef __TARGETING_COMMON_TARGET_UTIL_H
#define __TARGETING_COMMON_TARGET_UTIL_H

#include <stdint.h>                         // int16_t, uint8_t
#include <attributeenums.H>                 // TARGETING::ATTRIBUTE_ID
#include <targeting/common/target.H>        // Target
#include <targeting/common/attributeTank.H> // AttributeTank::Attribute

#ifndef STANDALONE_COMPILE

namespace TARGETING
{
/**
 *  @brief Returns the target handle's attribute associated with the given
 *         simple type attribute ID.
 *
 *  @param[in]  i_target The target to retrieve the attribute data from
 *  @param[out] o_attribute The attribute data, for the given attribute ID,
 *                          if found
 *
 *  @pre i_target must be a valid target
 *
 *  @return Attribute data for given attribute ID, if found, else
 *          outgoing attribute will not touched
 *
 *  @retval true is successful in locating the attribute ID, false otherwise
 */
template<const ATTRIBUTE_ID A>
bool makeAttribute(TargetHandle_t             i_target,
                   AttributeTank::Attribute&  o_attribute)
{
    // Set up the return value to true ... hoping for the best
    bool retVal(true);

    do
    {
        // Some needed variables and their defaults
        uint16_t l_positon(TARGETING::AttributeTank::ATTR_POS_NA);
        uint8_t  l_unitPositon(AttributeTank::ATTR_UNIT_POS_NA),
                 l_node(AttributeTank::ATTR_NODE_NA);

        // Get the target's position data
        i_target->getAttrTankTargetPosData(l_positon, l_unitPositon, l_node);

        // Get the target's type and the target's attribute data
        auto l_targetType = i_target->getAttrTankTargetType();
        auto l_attributeData = i_target->getAttr<A>();

        // Populate the outgoing Attribute with the data retrieved above
        o_attribute.setId(A);
        o_attribute.setTargetType(l_targetType);
        o_attribute.setPosition(l_positon);
        o_attribute.setUnitPosition(l_unitPositon);
        o_attribute.setNode(l_node);
        o_attribute.setValue(&l_attributeData, sizeof(l_attributeData));
    } while (0);

    return retVal;
}; // end makeAttribute

/**
 *  @brief Returns the target handle's attribute associated with the given
 *         complex type attribute ID.
 *
 *  @param[in]  i_target The target to retrieve the attribute data from
 *  @param[out] o_attribute The attribute data, for the given attribute ID,
 *                          if found
 *
 *  @pre i_target must be a valid target
 *
 *  @return Attribute data for given attribute ID, if found, else
 *          outgoing attribute will not touched
 *
 *  @retval true is successful in locating the attribute ID, false otherwise
 */
template<const ATTRIBUTE_ID A>
bool makeAttributeStdArr(TargetHandle_t             i_target,
                         AttributeTank::Attribute&  o_attribute)
{
    // Set up the return value to true ... hoping for the best
    bool retVal(true);

    // Variable to hold the complex type, when found
    typename AttributeTraits<A>::TypeStdArr l_attributeValue;

    do
    {
        // Some needed variables and their defaults
        uint16_t l_positon(TARGETING::AttributeTank::ATTR_POS_NA);
        uint8_t  l_unitPositon(AttributeTank::ATTR_UNIT_POS_NA),
                 l_node(AttributeTank::ATTR_NODE_NA);

        // Get the target's position data
        i_target->getAttrTankTargetPosData(l_positon, l_unitPositon, l_node);

        // Get the target's type and the target's attribute data
        auto l_targetType = i_target->getAttrTankTargetType();
        bool l_found = i_target->tryGetAttr<A>(l_attributeValue);
        if (!l_found)
        {
            retVal = false;
            break;
        }

        // Populate the outgoing Attribute with the data retrieved above
        o_attribute.setId(A);
        o_attribute.setTargetType(l_targetType);
        o_attribute.setPosition(l_positon);
        o_attribute.setUnitPosition(l_unitPositon);
        o_attribute.setNode(l_node);
        o_attribute.setValue(&l_attributeValue, sizeof(l_attributeValue));
    } while (0);

    return retVal;
}; // end makeAttributeStdArr

}; // end namespace TARGETING

#endif  // end STANDALONE_COMPILE

#endif  // end __TARGETING_COMMON_TARGET_UTIL_H
