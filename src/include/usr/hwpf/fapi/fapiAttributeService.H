/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/hwpf/fapi/fapiAttributeService.H $            */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2011,2014              */
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
// $Id: fapiAttributeService.H,v 1.12 2013/10/15 13:11:08 dcrowell Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/hwpf/working/fapi/fapiAttributeService.H,v $

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
 *                          mjjones     09/06/2011  Remove support for strings
 *                          mjjones     09/22/2011  Fixed example
 *                          mjjones     10/13/2011  Added fapiGetInitFileAttr
 *                          camvanng    10/20/2011  Changed i_pTarget to "const"
 *                                                  ptr
 *                          mjjones     04/10/2012  Support for privileged atts
 *                          mjjones     06/07/2012  Add attr override support
 *                          mjjones     03/13/2013  Move attr override code to plat
 */

#ifndef FAPIATTRIBUTESERVICE_H_
#define FAPIATTRIBUTESERVICE_H_
#include <stdint.h>
#include <fapiAttributeIds.H>
#include <fapiPlatAttributeService.H>

/**
 * @brief Macros called by user to get/set attributes
 *
 * Code must have a pointer to a Target and an attribute ID (from XML file):
 *   fapi::ReturnCode l_rc;
 *   fapi::Target * l_pTarget = ????;
 *
 * To get a copy of an integer attribute and set the attribute
 *   uint64_t l_val = 0;
 *   l_rc = FAPI_ATTR_GET(<ID>, l_pTarget, l_val);
 *   l_rc = FAPI_ATTR_SET(<ID>, l_pTarget, l_val);
 *
 * To get a copy of an integer array attribute and set the attribute
 *   uint32_t l_pVal[4] = {0};
 *   l_rc = FAPI_ATTR_GET(<ID>, l_pTarget, l_pVal);
 *   l_rc = FAPI_ATTR_SET(<ID>, l_pTarget, l_pVal);
 *
 * A priveleged attribute is one that a HWP should not generally access,
 * examples include ATTR_NAME and ATTR_EC, where usage can lead to a non
 * data-driven design. A privileged attribute can be accessed with
 * FAPI_ATTR_GET_PRIVILEGED and FAPI_ATTR_SET_PRIVILEGED
 * 
 * The non-PRIVILEGED macros first call a template function (compiler will
 * optimize out) that will cause a compile failure if the attribute is
 * privileged, they then call a PRIVILEGED macro to get/set the attribute
 *
 * The PRIVILEGED macros call a template function (compiler will optimize out)
 * that will cause a compile failure if the ID is not valid or VAL is not the
 * correct type.
 */
#define FAPI_ATTR_GET(ID, PTARGET, VAL) \
    (fapi::fapiFailIfPrivileged<fapi::ID##_Privileged>(), \
     fapi::fapiCheckIdType<fapi::ID##_Type>(fapi::ID, VAL), \
     ID##_GETMACRO(ID, PTARGET, VAL))

#define FAPI_ATTR_SET(ID, PTARGET, VAL) \
    (fapi::fapiFailIfPrivileged<fapi::ID##_Privileged>(), \
     fapi::fapiCheckIdType<fapi::ID##_Type>(fapi::ID, VAL), \
     ID##_SETMACRO(ID, PTARGET, VAL))

#define FAPI_ATTR_GET_PRIVILEGED(ID, PTARGET, VAL) \
    (fapi::fapiCheckIdType<fapi::ID##_Type>(fapi::ID, VAL), \
     ID##_GETMACRO(ID, PTARGET, VAL))

#define FAPI_ATTR_SET_PRIVILEGED(ID, PTARGET, VAL) \
    (fapi::fapiCheckIdType<fapi::ID##_Type>(fapi::ID, VAL), \
     ID##_SETMACRO(ID, PTARGET, VAL))

namespace fapi
{

/**
 * @brief Get an InitFile attribute
 *
 * This function gets a copy of an attribute. In the case of an array attribute,
 * The value in the specified index is retrieved. This should be used by the
 * InitFile HWP only, that HWP processes a binary InitFile and therefore needs
 * to read a variable ID of a variable data type. Standard HWPs should use the
 * FAPI_ATTR_GET macro which automatically checks the type for correct usage.
 *
 * If there are ever attributes with more than 4 dimensions then this function
 * will need to be updated.
 *
 * @param[in]  i_id          AttributeID
 * @param[in]  i_pTarget     Pointer to fapi::Target (can be NULL for system)
 * @param[out] o_val         Reference to uint64_t where attribute value is set
 * @param[in]  i_arrayIndex1 If array attribute then index1
 * @param[in]  i_arrayIndex2 If at least 2D array attribute then index2
 * @param[in]  i_arrayIndex3 If at least 3D array attribute then index3
 * @param[in]  i_arrayIndex4 If at least 4D array attribute then index4
 *
 * @return ReturnCode. Zero if success
 */
ReturnCode fapiGetInitFileAttr(const AttributeId i_id,
                               const Target * i_pTarget,
                               uint64_t & o_val,
                               const uint32_t i_arrayIndex1 = 0,
                               const uint32_t i_arrayIndex2 = 0,
                               const uint32_t i_arrayIndex3 = 0,
                               const uint32_t i_arrayIndex4 = 0);

/**
 * @brief Check the ID and TYPE
 *
 * This is called by FAPI code to check at compile time that a FAPI attribute
 * access is using the correct data type and a valid AttributeId
 */
template<typename T> inline void fapiCheckIdType(AttributeId, T &) {}

/**
 * @brief Fail if attribute privileged
 *
 * This is called by FAPI code to check at compile time that a standard FAPI
 * attribute access (FAPI_ATTR_GET) is not accessing a privileged attribute
 */
class ErrorAccessingPrivilegedAttribute;
template<const bool PRIVILEGED> void fapiFailIfPrivileged()
{
    ErrorAccessingPrivilegedAttribute();
}
template <> inline void fapiFailIfPrivileged<false>() {}

}

#endif // FAPIATTRIBUTESERVICE_H_
