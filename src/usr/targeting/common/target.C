//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/targeting/target.C $
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

    // Iterate through all the target's attribute IDs
    for (uint32_t i = 0; i < iv_attrs; ++i)
    {
        // Point to the ith attribute ID.  If it matches the requested attribute
        // ID,
        // look up the attribute's address
        if (*(pAttrId+i) == i_attr)
        {
            // Locate the corresponding attribute address
            l_pAttr = TARG_TO_PLAT_PTR(*(ppAttrAddr+i));

            // Only translate addresses on platforms where addresses are 4 bytes
            // wide (FSP).  The compiler should perform dead code elimination of
            // this path on platforms with 8 byte wide addresses (Hostboot), 
            // since the "if" check can be statically computed at compile time.
            if(TARG_ADDR_TRANSLATION_REQUIRED)
            {
                l_pAttr =
                    TARG_GET_SINGLETON(TARGETING::theAttrRP).translateAddr(
                        l_pAttr);
            }

            break;
        }
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

char * Target::targetFFDC( uint32_t & o_size ) const
{
    #define TARG_FN "targetFFDC(...)"

    char l_buff[128];
    char *l_pFFDC = NULL;
    char *l_ptr   = NULL;
    void *l_ptr1  = NULL;
    uint32_t l_len;

    o_size = sprintf( l_buff, "Class = 0x%X, Type = 0x%X, Model = 0x%X",
                       getAttr<ATTR_CLASS>(),
                       getAttr<ATTR_TYPE>(),
                       getAttr<ATTR_MODEL>() );

    l_pFFDC = static_cast<char*>( malloc( ++o_size ) );
    memcpy( l_pFFDC, l_buff, o_size );

    l_ptr = getAttr<ATTR_PHYS_PATH>().toString();
    if (l_ptr)
    {
         l_len = strlen( l_ptr ) + 1;
         l_ptr1 = realloc( l_pFFDC, o_size + l_len );
         l_pFFDC = static_cast<char*>( l_ptr1 );
         memcpy( l_pFFDC + o_size, l_ptr, l_len );
         o_size += l_len;
         free( l_ptr );
    }

    EntityPath l_entityPath;
    if( tryGetAttr<ATTR_AFFINITY_PATH>(l_entityPath) )
    {
        l_ptr = l_entityPath.toString();
        if (l_ptr)
        {
            l_len = strlen( l_ptr ) + 1;
            l_ptr1 = realloc( l_pFFDC, o_size + l_len );
            l_pFFDC = static_cast<char*>( l_ptr1 );
            memcpy( l_pFFDC + o_size, l_ptr, l_len );
            o_size += l_len;
            free( l_ptr );
        }
    }

    return l_pFFDC;

    #undef TARG_FN
}

#undef TARG_CLASS

#undef TARG_NAMESPACE

} // End namespace TARGETING
