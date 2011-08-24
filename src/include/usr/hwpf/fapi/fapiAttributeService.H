//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/include/usr/hwpf/fapi/fapiAttributeService.H $
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
/**
 *  @file fapiAttributeService.H
 *
 *  @brief Defines the FAPI_ATTR_GET and FAPI_ATTR_SET macros that a user calls
 *         to get/set attributes and a check function that the macros use to
 *         verify correct usage
 */

/*
 * Change Log ******************************************************************
 * Flag     Defect/Feature  User        Date        Description
 * ------   --------------  ----------  ----------- ----------------------------
 *                          mjjones     06/06/2011  Created.
 *                          mjjones     06/22/2011  Major updates
 */

#ifndef FAPIATTRIBUTESERVICE_H_
#define FAPIATTRIBUTESERVICE_H_
#include <stdint.h>
#include <fapiAttributeIds.H>
#include <fapiPlatAttributeService.H>

/**
 * @brief Macros called by user to get/set attributes
 *
 * @note The user must use these macros rather than any AttributeService
 *       functions.
 *
 * Code must have a pointer to a Target and an attribute ID (from XML file):
 *   fapi::ReturnCode l_rc;
 *   fapi::Target * l_pTarget = ????;
 *   AttributeId l_id = ????;
 *
 * To get a copy of a string attribute
 *   char * l_pString = NULL;
 *   l_rc = FAPI_ATTR_GET(l_id, l_pTarget, l_pString);
 *   delete[] l_pString; // When finished with the attribute
 *
 * To set a string attribute
 *   l_rc = FAPI_ATTR_SET(l_id, l_pTarget, "string-literal");
 *   l_rc = FAPI_ATTR_SET(l_id, l_pTarget, l_pString);
 *
 * To get a copy of an integer attribute and set the attribute
 *   uint64_t l_val = 0;
 *   l_rc = FAPI_ATTR_GET(l_id, l_pTarget, l_val);
 *   l_rc = FAPI_ATTR_SET(l_id, l_pTarget, l_val);
 *
 * To get a copy of an integer array attribute and set the attribute
 *   uint32_t l_pVal[4] = {0};
 *   l_rc = FAPI_ATTR_GET(l_id, l_pTarget, l_pVal);
 *   l_rc = FAPI_ATTR_SET(l_id, l_pTarget, l_pVal);
 *
 * The first part of these macros is a call to checkIdType that will cause a
 * compile failure if the ID or VAL parameters are incorrect.
 *
 * The second part of these macros calls a macro named <ID>_GET/SETMACRO. This
 * macro is defined by PLAT and must do the work of getting/setting the
 * attribute.
 */
#define FAPI_ATTR_GET(ID, PTARGET, VAL) \
    (fapi::AttributeCheck::checkIdType<fapi::ID##_Type>(fapi::ID, VAL), \
     ID##_GETMACRO(ID, PTARGET, VAL))
#define FAPI_ATTR_SET(ID, PTARGET, VAL) \
    (fapi::AttributeCheck::checkIdType<fapi::ID##_Type>(fapi::ID, VAL), \
     ID##_SETMACRO(ID, PTARGET, VAL))

namespace fapi
{

namespace AttributeCheck
{

/**
 * @brief Check the ID and VAL
 *
 * This is called by FAPI_ATTR_GET/SET to check at compile time that the ID and
 * VAL macro parameters are correct. If the ID is not an AttributeId or the VAL
 * is not the type specified in the attribute XML file then no function will be
 * found.
 */
template<typename T> void checkIdType(AttributeId, T &) {}

}

}

#endif // FAPIATTRIBUTESERVICE_H_
