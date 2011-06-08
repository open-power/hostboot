
/**
 *  @file target.C
 *
 *  @brief Implementation of the Target class
 */

//******************************************************************************
// Includes
//******************************************************************************

// STD
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// This component
#include <targeting/target.H>
#include "trace.H"

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
    for (uint32_t i = 0; i < iv_attrs; ++i)
    {
        if ((*iv_pAttrNames)[i] == i_attr)
        {
            l_pAttr = (*iv_pAttrValues)[i];
        }
    }
    o_pAttr = l_pAttr;

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

#undef TARG_CLASS

#undef TARG_NAMESPACE

} // End namespace TARGETING
