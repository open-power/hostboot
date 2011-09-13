//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/include/usr/targeting/attributestrings.H $
//
//  IBM CONFIDENTIAL
//
//  COPYRIGHT International Business Machines Corp. 2011
//
//  p1
//
//  Object Code Only (OCO) source materials
//  Licensed Internal Code Source Materials
//  IBM HostBoot Licensed Internal Code
//
//  The source code for this program is not published or other-
//  wise divested of its trade secrets, irrespective of what has
//  been deposited with the U.S. Copyright Office.
//
//  Origin: 30
//
//  IBM_PROLOG_END

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
