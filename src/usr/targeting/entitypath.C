//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/targeting/entitypath.C $
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
 *  @file entitypath.C
 *
 *  @brief Implementation of the EntityPath class
 */

//******************************************************************************
// Includes
//******************************************************************************

// STD
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <trace/interface.H>

// This component
#include <targeting/target.H>
#include <targeting/targetservice.H>
#include "trace.H"

namespace TARGETING
{

#define TARG_NAMESPACE "TARGETING::"
#define TARG_CLASS "EntityPath::"
#define TARG_LOC TARG_NAMESPACE TARG_CLASS TARG_FN ": "

extern trace_desc_t* g_trac_targeting;

//******************************************************************************
// EntityPath::EntityPath (Path Type Constructor)
//******************************************************************************

EntityPath::EntityPath(
    const PATH_TYPE i_pathType)
    : iv_type(i_pathType), iv_size(0)
{
    #define TARG_FN "EntityPath(...)"

    memset(&iv_pathElement[0], 0x00, sizeof(iv_pathElement));

    #undef TARG_FN
}

//******************************************************************************
// EntityPath::EntityPath (Full Constructor)
//******************************************************************************

EntityPath::EntityPath()
    : iv_type(PATH_NA), iv_size(0)
{
    #define TARG_FN "EntityPath()"

    memset(&iv_pathElement[0], 0x00, sizeof(iv_pathElement));

    #undef TARG_FN
}

//******************************************************************************
// EntityPath::~EntityPath
//******************************************************************************

EntityPath::~EntityPath()
{
    #define TARG_FN "~EntityPath()"

    #undef TARG_FN
}

//******************************************************************************
// EntityPath::removeLast
//******************************************************************************

EntityPath& EntityPath::removeLast()
{
    #define TARG_FN "removeLast()"

    assert(size() >= 1, TARG_LOC "EntityPath empty (size = %d); cannot remove "
           "any path elements", size());
    
    iv_pathElement[size() - 1].type = TYPE_NA;
    iv_pathElement[size() - 1].instance = 0;
    --iv_size;
    return *this;

    #undef TARG_FN
}

//******************************************************************************
// EntityPath::copyRemoveLast
//******************************************************************************

EntityPath EntityPath::copyRemoveLast() const
{
    #define TARG_FN "copyRemoveLast()"

    EntityPath l_newPath = *this;
    l_newPath.removeLast();
    return l_newPath;

    #undef TARG_FN
}

//******************************************************************************
// EntityPath::addLast
//******************************************************************************

EntityPath& EntityPath::addLast(
    const TYPE    i_type,
    const uint8_t i_instance)
{
    #define TARG_FN "addLast(...)"

    assert(size() < MAX_PATH_ELEMENTS, TARG_LOC "Entity path cannot "
           "store any more path elements with size %d", size());

    iv_pathElement[size()].type = i_type;
    iv_pathElement[size()].instance = i_instance;
    ++iv_size;
    return *this;

    #undef TARG_FN
}

//******************************************************************************
// EntityPath::copyAddLast
//******************************************************************************

EntityPath EntityPath::copyAddLast(
    const TYPE    i_type,
    const uint8_t i_instance) const
{
    #define TARG_FN "copyAddLast(...)"

    EntityPath l_newPath = *this;
    l_newPath.addLast(i_type,i_instance);
    return l_newPath;

    #undef TARG_FN
}

//******************************************************************************
// EntityPath::operator->
//******************************************************************************

Target* EntityPath::operator->(void)
{
    #define TARG_FN "operator->()"

    return theTargetService::instance().toTarget(*this);

    #undef TARG_FN
}

//******************************************************************************
// EntityPath::operator==
//******************************************************************************

bool EntityPath::operator==(
    const EntityPath &i_rhs) const
{
    #define TARG_FN "operator==(...)"

    return (   (i_rhs.iv_type == iv_type)
            && (i_rhs.iv_size == iv_size)
            && (memcmp(&iv_pathElement[0],
                       &i_rhs.iv_pathElement[0],
                       (sizeof(iv_pathElement[0])*iv_size)) == 0));

    #undef TARG_FN
}

//******************************************************************************
// EntityPath::equals
//******************************************************************************

bool EntityPath::equals(
    const EntityPath& i_rhs,
    const uint32_t    i_size) const
{
    #define TARG_FN "equals(...)"

    assert(i_size <= MAX_PATH_ELEMENTS, TARG_LOC "Caller specified invalid "
           "entity path size of %d which is greater than MAX_PATH_ELEMENTS of "
           "%d",i_size,MAX_PATH_ELEMENTS);

    return (   (i_rhs.iv_type == iv_type)
            && (i_size <= i_rhs.size())
            && (i_size <= size())
            && (memcmp(&iv_pathElement[0],
                       &i_rhs.iv_pathElement[0],
                       (sizeof(iv_pathElement[0])*i_size)) == 0));

    #undef TARG_FN
}

//******************************************************************************
// EntityPath::operator[]
//******************************************************************************

const EntityPath::PathElement& EntityPath::operator[](
    const uint32_t i_index) const
{
    #define TARG_FN "operator[](...)"

    assert(i_index < size(), TARG_LOC "Caller specified invalid entity path "
           "subscript of %d when size is only %d",i_index,size());
    
    return iv_pathElement[i_index];

    #undef TARG_FN
}

//******************************************************************************
// EntityPath::pathElementOfType
//******************************************************************************

const EntityPath::PathElement EntityPath::pathElementOfType(
    const TYPE i_type) const
{
    #define TARG_FN "pathElementOfType(...)"

    for( uint32_t x = 0; x < iv_size; x++ )
    {
        if( i_type == iv_pathElement[x].type )
        {
            return iv_pathElement[x];
        }
    }    

    PathElement na_path = { TYPE_NA, 0 };
    return na_path;

    #undef TARG_FN
}

//******************************************************************************
// EntityPath::size
//******************************************************************************

uint32_t EntityPath::size() const
{
    #define TARG_FN "size()"

    return iv_size;

    #undef TARG_FN
}

//******************************************************************************
// EntityPath::setType
//******************************************************************************

void EntityPath::setType(
    const PATH_TYPE i_pathType)
{
    #define TARG_FN "setType(...)"

    iv_type = i_pathType;

    #undef TARG_FN
}

//******************************************************************************
// EntityPath::type
//******************************************************************************

EntityPath::PATH_TYPE EntityPath::type() const
{
    #define TARG_FN "type()"

    return iv_type;

    #undef TARG_FN
}

//******************************************************************************
// EntityPath::pathTypeAsString (DEBUG)
//******************************************************************************

const char* EntityPath::pathTypeAsString() const
{
    #define TARG_FN "pathTypeAsString()"

    switch (iv_type)
    {
        case PATH_DEVICE:
            return "Device";
        case PATH_AFFINITY:
            return "Logical";
        case PATH_PHYSICAL:
            return "Physical";
        case PATH_POWER:
            return "Power";
        default:
            return "Unknown entity path type";
    }

    #undef TARG_FN
}

//******************************************************************************
// EntityPath::pathElementTypeAsString (DEBUG)
//******************************************************************************

const char* EntityPath::pathElementTypeAsString(
    const TYPE i_type) const
{
    #define TARG_FN "pathElementTypeAsString(...)"

    switch (i_type)
    {
        case TYPE_PROC:
            return "Proc";
        case TYPE_NODE:
            return "Node";
        case TYPE_CORE:
            return "Core";
        case TYPE_L2:
            return "L2";
        case TYPE_MCS:
            return "MCS";
        case TYPE_MBA:
            return "MBA";
        case TYPE_MEM_PORT:
            return "MemPort";
        case TYPE_L3:
            return "L3";
        case TYPE_PERVASIVE:
            return "Pervasive";
        case TYPE_MEMBUF:
            return "Membuf";
        case TYPE_DMI:
            return "DMI";
        case TYPE_POWERBUS:
            return "Powerbus";
        case TYPE_SCM:
            return "SCM";
        case TYPE_SYS:
            return "Sys";
        case TYPE_DCM:
            return "DCM";
        case TYPE_EX:
            return "EX";
        case TYPE_PCI:
            return "PCI";
//        case TYPE_FSI_LINK:
//            return "FSI-link";
//        case TYPE_CFAM:
//            return "CFAM";
//        case TYPE_ENGINE:
//            return "Engine";
        default:
            return "Unknown path type";
    }

    #undef TARG_FN
}

//******************************************************************************
// EntityPath::pathEngineInstanceAsString (DEBUG)
//******************************************************************************

const char* EntityPath::pathEngineInstanceAsString(
    const ENGINE_TYPE i_engine) const
{
    #define TARG_FN "pathEngineInstanceAsString(...)"

    switch (i_engine)
    {
//        case ENGINE_IIC:
//            return "IIC";
//        case ENGINE_SCOM:
//            return "SCOM";
        default:
            return "Unknown engine type";
    }

    #undef TARG_FN
}

//******************************************************************************
// EntityPath::dump (DEBUG)
//******************************************************************************

void EntityPath::dump() const
{
    #define TARG_FN "dump()"

    char  l_pBuf[200];
    char* l_pCursor = l_pBuf;
    l_pCursor+=sprintf(l_pCursor,"%s:",pathTypeAsString());
    for(uint32_t i=0; i<size(); ++i)
    {
        l_pCursor+=sprintf(l_pCursor,"/%s%d",
            pathElementTypeAsString(operator[](i).type),
            operator[](i).instance);
    }

    TRACFBIN(g_trac_targeting,
             "EntityPath",
             l_pBuf,
             l_pCursor-l_pBuf);

    #undef TARG_FN
}

#undef TARG_CLASS

#undef TARG_NAMESPACE

} // End namespace TARGETING
