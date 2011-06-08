
#ifndef TARG_ATTRIBUTESTRINGS_H
#define TARG_ATTRIBUTESTRINGS_H

/**
 *  @file attributestrings.H
 *
 *  @brief Attribute string conversion routines.  This file will be auto
 *      generated in the future
 */

//******************************************************************************
// Includes
//******************************************************************************

// STD
#include <stdint.h>
#include <stdlib.h>

namespace TARGETING
{

/**
 *  @brief Class used to clarify compiler error when caller attempts to
 *      stringify an unsupported attribute
 */
class InvalidAttributeForStringification;

/**
 *  @brief Return attribute as a string
 *
 *  @param[in] i_attrValue Value of the attribute
 *
 *  @return String which decodes the attribute value
 */
template<const ATTRIBUTE_ID A>
const char* attrToString(
    typename AttributeTraits<A>::Type const& i_attrValue)
{
    return InvalidAttributeForStringification(); //"Cannot stringify attr";
}

/**
 *  @brief See attrToString<const ATTRIBUTE_ID A>
 */
template<>
const char* attrToString<ATTR_CLASS>(
    AttributeTraits<ATTR_CLASS>::Type const& i_attrValue);

/**
 *  @brief See attrToString<const ATTRIBUTE_ID A>
 */
template<>
const char* attrToString<ATTR_TYPE>(
    AttributeTraits<ATTR_TYPE>::Type const& i_attrValue);

/**
 *  @brief See attrToString<const ATTRIBUTE_ID A>
 */
template<>
const char* attrToString<ATTR_MODEL>(
    AttributeTraits<ATTR_MODEL>::Type const& i_attrValue);

} // End namespace TARGETING

#endif // TARG_ATTRIBUTESTRINGS_H
