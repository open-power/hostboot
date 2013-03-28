/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/targeting/common/target.C $                           */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2011,2013              */
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
/**
 *  @file targeting/common/target.C
 *
 *  @brief Implementation of the Target class which provide APIs to read and
 *      write attributes from various attribute sections
 */

//******************************************************************************
// Includes
//******************************************************************************

// STD
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// This component
#include <targeting/common/attributes.H>
#include <targeting/attrrp.H>
#include <targeting/common/util.H>
#include <targeting/common/trace.H>
#include <targeting/common/predicates/predicateattrval.H>

namespace TARGETING
{

#define TARG_NAMESPACE "TARGETING::"
#define TARG_CLASS "Target::"

//******************************************************************************
// Target::~Target
//******************************************************************************

Target::~Target()
{
    #define TARG_FN "~Target()"

    #undef TARG_FN
}

//******************************************************************************
// Target::_tryGetAttr
//******************************************************************************

bool Target::_tryGetAttr(
    const ATTRIBUTE_ID i_attr,
    const uint32_t     i_size,
          void* const  io_pAttrData) const
{
    #define TARG_FN "_tryGetAttr()"

    void* l_pAttrData = NULL;
    (void) _getAttrPtr(i_attr, l_pAttrData);
    if (l_pAttrData)
    {
        memcpy(io_pAttrData, l_pAttrData, i_size);
    }
    return (l_pAttrData != NULL);

    #undef TARG_FN
}

//******************************************************************************
// Target::_trySetAttr
//******************************************************************************

bool Target::_trySetAttr(
    const ATTRIBUTE_ID i_attr,
    const uint32_t     i_size,
    const void* const  i_pAttrData) const
{
    #define TARG_FN "_trySetAttr()"

    void* l_pAttrData = NULL;
    (void) _getAttrPtr(i_attr, l_pAttrData);
    if (l_pAttrData)
    {
        memcpy(l_pAttrData, i_pAttrData, i_size);
    }
    return (l_pAttrData != NULL);

    #undef TARG_FN
}

//******************************************************************************
// Target::_getAttrPtr
//******************************************************************************

void Target::_getAttrPtr(
    const ATTRIBUTE_ID i_attr,
          void*&       o_pAttr) const
{
    #define TARG_FN "_getAttrPtr()"

    void* l_pAttr = NULL;

    // Transform platform neutral pointers into platform specific pointers, and
    // optimize processing by not having to do the conversion in the loop below
    // (it's guaranteed that attribute metadata will be in the same contiguous
    // VMM region)
    ATTRIBUTE_ID* pAttrId = TARG_TO_PLAT_PTR(iv_pAttrNames);
    AbstractPointer<void>* ppAttrAddr = TARG_TO_PLAT_PTR(iv_pAttrValues);

    // Only translate addresses on platforms where addresses are 4 bytes wide
    // (FSP). The compiler should perform dead code elimination of this path on
    // platforms with 8 byte wide addresses (Hostboot), since the "if" check can
    // be statically computed at compile time.
    if(TARG_ADDR_TRANSLATION_REQUIRED)
    {
        pAttrId = static_cast<ATTRIBUTE_ID*>(
            TARG_GET_SINGLETON(TARGETING::theAttrRP).translateAddr(pAttrId));
        ppAttrAddr = static_cast<AbstractPointer<void>*>(
            TARG_GET_SINGLETON(TARGETING::theAttrRP).translateAddr(ppAttrAddr));
    }

    if ((pAttrId != NULL) && (ppAttrAddr != NULL))
    {   // only check for the attribute if we got a valid address from
        // the translateAddr function

        // Iterate through all the target's attribute IDs
        for (uint32_t i = 0; i < iv_attrs; ++i)
        {
            // Point to the ith attribute ID.  If it matches the requested
            // attribute ID,
            // look up the attribute's address
            if (*(pAttrId+i) == i_attr)
            {
                // Locate the corresponding attribute address
                l_pAttr = TARG_TO_PLAT_PTR(*(ppAttrAddr+i));

                // Only translate addresses on platforms where addresses are
                // 4 byte wide (FSP).  The compiler should perform dead code
                // elimination this path on platforms with 8 byte wide
                // addresses (Hostboot), since the "if" check can be statically
                // computed at compile time.
                if(TARG_ADDR_TRANSLATION_REQUIRED)
                {
                    l_pAttr =
                        TARG_GET_SINGLETON(TARGETING::theAttrRP).translateAddr(
                            l_pAttr);
                }

                break;
            }
        } // for
    }
    o_pAttr = l_pAttr;

    #undef TARG_FN
}

//******************************************************************************
// Target::_getHbMutexAttr
//******************************************************************************

mutex_t* Target::_getHbMutexAttr(
    const ATTRIBUTE_ID i_attribute) const
{
    #define TARG_FN "_getHbMutexAttr()"

    void* l_pAttr = NULL;
    (void)_getAttrPtr(i_attribute,l_pAttr);

    //@TODO Remove assert once release has stablized
    TARG_ASSERT(l_pAttr,"TARGETING::Target::_getHbMutexAttr<%d>: _getAttrPtr "
           "returned NULL",i_attribute);

    return static_cast<mutex_t*>(l_pAttr);

    #undef TARG_FN
}

//******************************************************************************
// Target::_tryGetHbMutexAttr
//******************************************************************************

bool Target::_tryGetHbMutexAttr(
    const ATTRIBUTE_ID i_attribute,
          mutex_t*&    o_pMutex) const
{
    #define TARG_FN "_tryGetHbMutexAttr()"

    void* l_pAttr = NULL;
    (void)_getAttrPtr(i_attribute,l_pAttr);
    o_pMutex = static_cast<mutex_t*>(l_pAttr);
    return (l_pAttr != NULL);

    #undef TARG_FN
}

//******************************************************************************
// Target::Target
//******************************************************************************

Target::Target()
{
    #define TARG_FN "Target()"

    // Note there is no intialization of a target, since it's mapped to memory
    // directly.

    #undef TARG_FN
}

//******************************************************************************
// Target::targetFFDC()
//******************************************************************************

uint8_t * Target::targetFFDC( uint32_t & o_size ) const
{
    #define TARG_FN "targetFFDC(...)"

    AttributeTraits<ATTR_HUID>::Type  attrHuid  = getAttr<ATTR_HUID>();
    AttributeTraits<ATTR_CLASS>::Type attrClass = getAttr<ATTR_CLASS>();
    AttributeTraits<ATTR_TYPE>::Type  attrType  = getAttr<ATTR_TYPE>();
    AttributeTraits<ATTR_MODEL>::Type attrModel = getAttr<ATTR_MODEL>();
    uint32_t headerSize = sizeof(attrHuid) +
                            sizeof(attrClass) + sizeof(attrType) +
                            sizeof(attrModel);

    uint32_t attrEnum = ATTR_NA;

    uint8_t pathPhysSize = 0;
    AttributeTraits<ATTR_PHYS_PATH>::Type pathPhys;
    if( tryGetAttr<ATTR_PHYS_PATH>(pathPhys) ) {
        // entityPath is PATH_TYPE:4, NumberOfElements:4, [Element, Instance#]
        pathPhysSize = sizeof(uint8_t) + (sizeof(pathPhys[0]) * pathPhys.size());
    }

    uint8_t pathAffSize = 0;
    AttributeTraits<ATTR_AFFINITY_PATH>::Type pathAff;
    if( tryGetAttr<ATTR_AFFINITY_PATH>(pathAff) ) {
        // entityPath is PATH_TYPE:4, NumberOfElements:4, [Element, Instance#]
        pathAffSize = sizeof(uint8_t) + (sizeof(pathAff[0]) * pathAff.size());
    }

    uint8_t *pFFDC;

    // If there is a physical path or affinity path, the serialization code
    // below prefixes an attribute type ahead of the actual structure, so need
    // to compensate for the size of that attribute type, when applicable
    pFFDC = static_cast<uint8_t*>(
        malloc(  headerSize
               + pathPhysSize
               + sizeof(attrEnum)
               + pathAffSize
               + sizeof(attrEnum)));

    // we'll send down HUID CLASS TYPE and MODEL
    uint32_t bSize = 0; // size of data in the buffer
    memcpy(pFFDC + bSize, &attrHuid, sizeof(attrHuid) );
    bSize += sizeof(attrHuid);
    memcpy(pFFDC + bSize, &attrClass, sizeof(attrClass) );
    bSize += sizeof(attrClass);
    memcpy(pFFDC + bSize, &attrType, sizeof(attrType) );
    bSize += sizeof(attrType);
    memcpy(pFFDC + bSize, &attrModel, sizeof(attrModel) );
    bSize += sizeof(attrModel);

    if( pathPhysSize > 0)
    {
        attrEnum = ATTR_PHYS_PATH;
        memcpy(pFFDC + bSize, &attrEnum, sizeof(attrEnum));
        bSize += sizeof(attrEnum);
        memcpy(pFFDC + bSize, &pathPhys, pathPhysSize);
        bSize += pathPhysSize;
    }
    else
    {
        // write 0x00 indicating no PHYS_PATH
        attrEnum = 0x00;
        memcpy(pFFDC + bSize, &attrEnum, sizeof(attrEnum));
        bSize += sizeof(attrEnum);
    }

    if( pathAffSize > 0)
    {
        attrEnum = ATTR_AFFINITY_PATH;
        memcpy(pFFDC + bSize, &attrEnum, sizeof(attrEnum));
        bSize += sizeof(attrEnum);
        memcpy(pFFDC + bSize, &pathAff, pathAffSize);
        bSize += pathAffSize;
    }
    else
    {
        // write 0x00 indicating no AFFINITY_PATH
        attrEnum = 0x00;
        memcpy(pFFDC + bSize, &attrEnum, sizeof(attrEnum));
        bSize += sizeof(attrEnum);
    }

    o_size = bSize;
    return pFFDC;

    #undef TARG_FN
}

//******************************************************************************
// Target::getTargetFromHuid()
//******************************************************************************

Target* Target::getTargetFromHuid(
    const ATTR_HUID_type i_huid) const
{
    #define TARG_FN "getTargetFromHuid"
    Target* l_pTarget = NULL;
    
    TARGETING::PredicateAttrVal<TARGETING::ATTR_HUID> huidMatches(i_huid);

    TARGETING::TargetRangeFilter targetsWithMatchingHuid(
        TARGETING::targetService().begin(),
        TARGETING::targetService().end(),
        &huidMatches);
    if(targetsWithMatchingHuid)
    {
        // Exactly one target will match the HUID, if any
        l_pTarget = *targetsWithMatchingHuid;
    }

    return l_pTarget;
    #undef TARG_FN
}

#undef TARG_CLASS

#undef TARG_NAMESPACE

} // End namespace TARGETING
