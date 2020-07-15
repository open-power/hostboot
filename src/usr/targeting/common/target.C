/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/targeting/common/target.C $                           */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2020                        */
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
#include <algorithm>

// This component
#include <targeting/common/attributes.H>
#include <targeting/attrrp.H>
#include <targeting/common/util.H>
#include <targeting/common/trace.H>
#include <targeting/common/predicates/predicateattrval.H>
#include <targeting/common/utilFilter.H>
#include <targeting/common/attributeTank.H>

namespace TARGETING
{

#define TARG_NAMESPACE "TARGETING::"
#define TARG_CLASS "Target::"

//P9 number of MC/CORE units contained per level
//Both happen to be the same, so use one constant
#define P9_UNIT_PER_LEVEL 2

// Static function pointer variable allocation
pCallbackFuncPtr Target::cv_pCallbackFuncPtr = NULL;

//******************************************************************************
// Target::~Target
//******************************************************************************

Target::~Target()
{
    #define TARG_FN "~Target()"

    #undef TARG_FN
}

//******************************************************************************
// Target::_tryGetAttrUnsafe
//******************************************************************************
bool Target::_tryGetAttrUnsafe(
    const ATTRIBUTE_ID i_attr,
    const uint32_t     i_size,
          void* const  io_pAttrData) const
{
    #define TARG_FN "_tryGetAttr()"

    bool l_found = false;

    // Very fast check if there are any overrides at all
    if (unlikely(cv_overrideTank.attributesExist()))
    {
        // Check if there are any overrides for this attr ID
        if (cv_overrideTank.attributeExists(i_attr))
        {
            // Check if attribute exists for the target
            void * l_pAttr = NULL;
            _getAttrPtr(i_attr, l_pAttr);
            if (l_pAttr)
            {
                // Find if there is an attribute override for this target
                uint32_t l_type = getAttrTankTargetType();
                uint16_t l_pos = 0;
                uint8_t l_unitPos = 0;
                uint8_t l_node = 0;
                getAttrTankTargetPosData(l_pos, l_unitPos, l_node);

                TRACFCOMP(g_trac_targeting, "Checking for override for ID: 0x%08x, "
                          "TargType: 0x%08x, Pos/Upos/Node: 0x%08x",
                          i_attr, l_type,
                          (static_cast<uint32_t>(l_pos) << 16) +
                          (static_cast<uint32_t>(l_unitPos) << 8) + l_node);

                l_found = cv_overrideTank.getAttribute(i_attr, l_type,
                    l_pos, l_unitPos, l_node, io_pAttrData);

                if (l_found)
                {
                    TRACFCOMP(g_trac_targeting, "Returning Override for ID: 0x%08x",
                              i_attr);
                }
            }
        }
    }

    if (!l_found)
    {
        // No attribute override, get the real attribute
        void* l_pAttrData = NULL;
        (void) _getAttrPtr(i_attr, l_pAttrData);
        if (l_pAttrData)
        {
            memcpy(io_pAttrData, l_pAttrData, i_size);
            l_found = true;
        }
    }

    return l_found;

    #undef TARG_FN
}

//******************************************************************************
// Target::_tryGetAttrUnsafe
//******************************************************************************
bool Target::_tryGetAttrUnsafe(
    const ATTRIBUTE_ID i_attr,
    const uint32_t     i_size,
    AttrRP*            i_attrRP,
    ATTRIBUTE_ID*      i_pAttrId,
    AbstractPointer<void>* i_ppAttrAddr,
    void* const        io_pAttrData) const
{
    #define TARG_FN "_tryGetAttrUnsafe()"

    bool l_found = false;

    void* l_pAttrData = NULL;
    _getAttrPtr(i_attr, i_attrRP, i_pAttrId, i_ppAttrAddr, l_pAttrData);
    if (l_pAttrData)
    {
        memcpy(io_pAttrData, l_pAttrData, i_size);
        l_found = true;
    }

    return l_found;

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

#ifdef __HOSTBOOT_RUNTIME
    // Get AttrRP pointer
    AttrRP *l_attrRP = &TARG_GET_SINGLETON(theAttrRP);
    // Get the node ID associated with the input target
    NODE_ID l_nodeId = NODE0;
    l_attrRP->getNodeId(this, l_nodeId);
    bool isSysTarget = ((this->getAttr<ATTR_CLASS>() == CLASS_SYS) &&
                        (this->getAttr<ATTR_TYPE>() == TYPE_SYS))
                     ? true : false;
#endif

    // Figure out if effort should be expended figuring out the target's type/
    // position in order to clear any non-const attribute overrides and/or to
    // store the attribute for syncing to Cronus

    bool l_clearAnyNonConstOverride = false;

    // Very fast check if there are any overrides at all for this Attr ID
    if (unlikely(cv_overrideTank.attributesExist()))
    {
        // Check if there are any overrides for this attr ID
        if (cv_overrideTank.attributeExists(i_attr))
        {
            l_clearAnyNonConstOverride = true;
        }
    }

    bool l_syncAttribute = AttributeTank::syncEnabled();

    if (unlikely(l_clearAnyNonConstOverride || l_syncAttribute))
    {
        // Check if attribute exists for the target
        void * l_pAttr = NULL;
        _getAttrPtr(i_attr, l_pAttr);
        if (l_pAttr)
        {
            uint32_t l_type = getAttrTankTargetType();
            uint16_t l_pos = 0;
            uint8_t l_unitPos = 0;
            uint8_t l_node = 0;
            getAttrTankTargetPosData(l_pos, l_unitPos, l_node);

            if (l_clearAnyNonConstOverride)
            {
                // Clear any non const override for this attribute because the
                // attribute is being written
                cv_overrideTank.clearNonConstAttribute(i_attr, l_type, l_pos,
                    l_unitPos, l_node);
            }

            if (l_syncAttribute)
            {
                // Write the attribute to the SyncAttributeTank to sync to Cronus
                cv_syncTank.setAttribute(i_attr, l_type, l_pos, l_unitPos, l_node,
                    0, i_size, i_pAttrData);
            }
        }
    }

    // Set the real attribute
    void* l_pAttrData = NULL;
    (void) _getAttrPtr(i_attr, l_pAttrData);
    if (l_pAttrData)
    {
        memcpy(l_pAttrData, i_pAttrData, i_size);
#ifdef __HOSTBOOT_RUNTIME
        if(isSysTarget)
        {
            uint8_t l_nodeCount = l_attrRP->getNodeCount();

            for(NODE_ID l_nodeX = NODE0;
                l_nodeX < l_nodeCount;
                ++l_nodeX)
            {
                if(l_nodeX == l_nodeId)
                {
                    // Already set attribute for this node, so continue to next
                    continue;
                }

                // Walk through targets
                for(TargetIterator pIt = targetService().begin(l_nodeX);
                    pIt != TARGETING::targetService().end();
                    ++pIt)
                {
                    // Check for system target
                    if(((*pIt)->getAttr<ATTR_CLASS>() == CLASS_SYS) &&
                       ((*pIt)->getAttr<ATTR_TYPE>() == TYPE_SYS))
                    {
                        // Get pointer to the attribute being set
                        void* l_pAttrDataNodeX = NULL;
                        (*pIt)->_getAttrPtr(i_attr, l_pAttrDataNodeX);
                        if (l_pAttrData)
                        {
                            // Set the attribute for this node
                            memcpy(l_pAttrDataNodeX, i_pAttrData, i_size);
                        }

                        break;
                    }
                }
            }
        }
#endif
        if( unlikely(cv_pCallbackFuncPtr != NULL) )
        {
            cv_pCallbackFuncPtr(this, i_attr, i_size, i_pAttrData);
        }
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
            TARG_GET_SINGLETON(TARGETING::theAttrRP).translateAddr(pAttrId,
                static_cast<const Target*>(this)));
        ppAttrAddr = static_cast<AbstractPointer<void>*>(
            TARG_GET_SINGLETON(TARGETING::theAttrRP).translateAddr(ppAttrAddr,
                static_cast<const Target*>(this)));
    }

    if ((pAttrId != NULL) && (ppAttrAddr != NULL))
    {   // only check for the attribute if we got a valid address from
        // the translateAddr function

        // Search for the attribute ID.
        ATTRIBUTE_ID* ptr = std::lower_bound(pAttrId, pAttrId+iv_attrs, i_attr);
        if ((ptr != pAttrId+iv_attrs) && (*ptr == i_attr))
        {
            // Locate the corresponding attribute address
            l_pAttr =
                TARG_TO_PLAT_PTR(*(ppAttrAddr+std::distance(pAttrId,ptr)));

            // Only translate addresses on platforms where addresses are
            // 4 byte wide (FSP).  The compiler should perform dead code
            // elimination this path on platforms with 8 byte wide
            // addresses (Hostboot), since the "if" check can be statically
            // computed at compile time.
            if(TARG_ADDR_TRANSLATION_REQUIRED)
            {
                l_pAttr =
                    TARG_GET_SINGLETON(TARGETING::theAttrRP).translateAddr(
                            l_pAttr, static_cast<const Target*>(this));
            }
        }
    }
    o_pAttr = l_pAttr;

    #undef TARG_FN
}

//******************************************************************************
// Target::_getAttrPtr
//******************************************************************************

void Target::_getAttrPtr(
            ATTRIBUTE_ID  i_attr,
            AttrRP*       i_attrRP,
            ATTRIBUTE_ID* i_pAttrId,
            AbstractPointer<void>* i_ppAttrAddr,
            void*&        o_pAttr) const
{

    #define TARG_FN "_getAttrPtr()"

    void* l_pAttr = NULL;

    // Search for the attribute ID.
    ATTRIBUTE_ID* ptr = std::lower_bound(i_pAttrId,
                                         i_pAttrId + iv_attrs,
                                         i_attr);
    if ((ptr != i_pAttrId + iv_attrs) && (*ptr == i_attr))
    {
        // Locate the corresponding attribute address
        l_pAttr =
            TARG_TO_PLAT_PTR(*(i_ppAttrAddr + std::distance(i_pAttrId, ptr)));

        // Only translate addresses on platforms where addresses are
        // 4 byte wide (FSP).  The compiler should perform dead code
        // elimination this path on platforms with 8 byte wide
        // addresses (Hostboot), since the "if" check can be statically
        // computed at compile time.
        if(TARG_ADDR_TRANSLATION_REQUIRED)
        {
            l_pAttr =
                i_attrRP->translateAddr(l_pAttr,
                                        static_cast<const Target*>(this));
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

    if (unlikely(l_pAttr == NULL))
    {
        targAssert(GET_HB_MUTEX_ATTR, i_attribute);
    }

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

    // Note there is no initialization of a target, since it's mapped to memory
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
    const ATTR_HUID_type i_huid)
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

//******************************************************************************
// Target::getAttrTankTargetType()
//******************************************************************************
uint32_t Target::getAttrTankTargetType() const
{
    // In a Targeting Attribute Tank, the Target Type is ATTR_TYPE
    AttributeTraits<ATTR_TYPE>::Type l_type = TYPE_NA;
    void * l_pAttr = NULL;
    _getAttrPtr(ATTR_TYPE, l_pAttr);
    if (l_pAttr)
    {
        l_type = *(reinterpret_cast<AttributeTraits<ATTR_TYPE>::Type *>(
            l_pAttr));
    }
    return l_type;
}

//******************************************************************************
// Target::getAttrTankTargetPosData()
//******************************************************************************
void Target::getAttrTankTargetPosData(uint16_t & o_pos,
                                      uint8_t & o_unitPos,
                                      uint8_t & o_node) const
{
    o_pos = AttributeTank::ATTR_POS_NA;
    o_unitPos = AttributeTank::ATTR_UNIT_POS_NA;
    o_node = AttributeTank::ATTR_NODE_NA;

    // Pos, UnitPos and Node are figured out from the PHYS_PATH
    void * l_pAttr = NULL;
    _getAttrPtr(ATTR_PHYS_PATH, l_pAttr);
    if (l_pAttr)
    {
        AttributeTraits<ATTR_PHYS_PATH>::Type & l_physPath =
            *(reinterpret_cast<AttributeTraits<ATTR_PHYS_PATH>::Type *>(
                l_pAttr));

        for (uint32_t i = 0; i < l_physPath.size(); i++)
        {
            const EntityPath::PathElement & l_element = l_physPath[i];

            if (l_element.type == TYPE_NODE)
            {
                o_node = l_element.instance;
            }
            else if ((l_element.type == TYPE_PROC) ||
                     (l_element.type == TYPE_MEMBUF) ||
                     (l_element.type == TYPE_DIMM) ||
                     (l_element.type == TYPE_OCMB_CHIP) ||
                     (l_element.type == TYPE_PMIC))
            {
                o_pos = l_element.instance;
            }
            else if ((l_element.type == TYPE_L4) ||
                     (l_element.type == TYPE_MBA) ||
                     (l_element.type == TYPE_MC) ||
                     (l_element.type == TYPE_XBUS) ||
                     (l_element.type == TYPE_ABUS) ||
                     (l_element.type == TYPE_EQ) ||
                     (l_element.type == TYPE_MCBIST) ||
                     (l_element.type == TYPE_CAPP) ||
                     (l_element.type == TYPE_OBUS) ||
                     (l_element.type == TYPE_OBUS_BRICK) ||
                     (l_element.type == TYPE_SBE) ||
                     (l_element.type == TYPE_PPE) ||
                     (l_element.type == TYPE_PERV) ||
                     (l_element.type == TYPE_PEC) ||
                     (l_element.type == TYPE_PHB) ||
                     (l_element.type == TYPE_OMI) ||
                     (l_element.type == TYPE_MCC) ||
                     (l_element.type == TYPE_OMIC) ||
                     (l_element.type == TYPE_MEM_PORT) ||
                     (l_element.type == TYPE_NMMU) ||
                     (l_element.type == TYPE_PAU) ||
                     (l_element.type == TYPE_IOHS) ||
                     (l_element.type == TYPE_PAUC))
            {
                o_unitPos = l_element.instance;
            }
            //Factor in that MCS and MCAs numbering is relative
            //to their parent.  Thus MCA 1 behind MCS1 behind MCBIST 1
            //is pos 7.  Below is the physical path showing containment:
            // Physical:/Sys0/Node0/Proc0/MCBIST0/MCS0/MCA0 --> unitPos = 0
            // Physical:/Sys0/Node0/Proc0/MCBIST0/MCS0/MCA1 --> unitPos = 1
            // Physical:/Sys0/Node0/Proc0/MCBIST0/MCS1/MCA0 --> unitPos = 2
            // Physical:/Sys0/Node0/Proc0/MCBIST0/MCS1/MCA1 --> unitPos = 3
            // Physical:/Sys0/Node0/Proc0/MCBIST1/MCS0/MCA0 --> unitPos = 4
            // etc
            //
            // physical:sys-0/node-0/proc-1/eq-1/ex-1/core-0 --> unitPos = 4
            // physical:sys-0/node-0/proc-1/eq-1/ex-1/core-1 --> unitPos = 5
            // physical:sys-0/node-0/proc-1/eq-2/ex-0/core-0 --> unitPos = 6
            // physical:sys-0/node-0/proc-1/eq-2/ex-0/core-1 --> unitPos = 7

            //Note that this ALSO applies to EX/EC units relative to their
            //quad.  So for now the magical number is "2" for everything
            //TODO RTC 160598 -- find a better way to do this
            else if ((l_element.type == TYPE_EX) ||
                     (l_element.type == TYPE_CORE) ||
                     (l_element.type == TYPE_MCS) ||
                     (l_element.type == TYPE_MCA) ||
                     (l_element.type == TYPE_MI)  ||
                     (l_element.type == TYPE_DMI))
            {
                //previous o_unitPos was MCBIST/MCS or EQ/EX.
                // Multiply by 2 and add in instance number
                o_unitPos = (o_unitPos*P9_UNIT_PER_LEVEL) + l_element.instance;
            }
        }

        // Check that the correct values are returned
        _getAttrPtr(ATTR_CLASS, l_pAttr);
        if (l_pAttr)
        {
            AttributeTraits<ATTR_CLASS>::Type & l_class =
                *(reinterpret_cast<AttributeTraits<ATTR_CLASS>::Type *>(
                    l_pAttr));
            switch( l_class )
            {
                    // Expects no position info
                case(TARGETING::CLASS_SYS):
                    if ((o_pos != AttributeTank::ATTR_POS_NA) ||
                        (o_unitPos != AttributeTank::ATTR_UNIT_POS_NA) ||
                        (o_node != AttributeTank::ATTR_NODE_NA))
                    {
                        targAssert(GET_ATTR_TANK_TARGET_POS_DATA, l_class);
                    }
                    break;

                    // Expects valid position+node
                case(TARGETING::CLASS_CHIP):
                case(TARGETING::CLASS_CARD):
                case(TARGETING::CLASS_LOGICAL_CARD):
                case(TARGETING::CLASS_DEV):
                case(TARGETING::CLASS_BATTERY):
                case(TARGETING::CLASS_LED):
                case(TARGETING::CLASS_SP):
                case(TARGETING::CLASS_ASIC):
                    if ((o_pos == AttributeTank::ATTR_POS_NA) ||
                        (o_unitPos != AttributeTank::ATTR_UNIT_POS_NA) ||
                        (o_node == AttributeTank::ATTR_NODE_NA))
                    {
                        targAssert(GET_ATTR_TANK_TARGET_POS_DATA, l_class);
                    }
                    break;

                    // Expects valid position+node+unit
                case(TARGETING::CLASS_UNIT):
                    if ((o_pos == AttributeTank::ATTR_POS_NA) ||
                        (o_unitPos == AttributeTank::ATTR_UNIT_POS_NA) ||
                        (o_node == AttributeTank::ATTR_NODE_NA))
                    {
                        TRACFCOMP(g_trac_targeting,"o_pos[%d], o_unitPos[%d] o_node[%d]", o_pos, o_unitPos, o_node);
                        targAssert(GET_ATTR_TANK_TARGET_POS_DATA, l_class);
                    }
                    break;

                    // Expects valid node
                case(TARGETING::CLASS_ENC):
                    if ((o_pos != AttributeTank::ATTR_POS_NA) ||
                        (o_unitPos != AttributeTank::ATTR_UNIT_POS_NA) ||
                        (o_node == AttributeTank::ATTR_NODE_NA))
                    {
                        targAssert(GET_ATTR_TANK_TARGET_POS_DATA, l_class);
                    }
                    break;

                    // Fail on nonsense values
                case(TARGETING::CLASS_NA):
                case(TARGETING::CLASS_MAX):
                    targAssert(GET_ATTR_TANK_TARGET_POS_DATA, ATTR_CLASS);
            }
        }
        else
        {
            targAssert(GET_ATTR_TANK_TARGET_POS_DATA_ATTR, ATTR_CLASS);
        }
    }
    else
    {
        targAssert(GET_ATTR_TANK_TARGET_POS_DATA_ATTR, ATTR_PHYS_PATH);
    }
}

//******************************************************************************
// Target::targAssert()
//******************************************************************************
void Target::targAssert(TargAssertReason i_reason,
                        uint32_t i_ffdc)
{
    switch (i_reason)
    {
    case SET_ATTR:
        TARG_ASSERT(false,
            "TARGETING::Target::setAttr<0x%7x>: trySetAttr returned false",
            i_ffdc);
        break;
    case SET_ATTR_FROM_STD_ARR:
        TARG_ASSERT(false,
            "TARGETING::Target::setAttrFromStdArr<0x%7x>: setAttrFromStdArr "
            "returned false",
            i_ffdc);
        break;
    case GET_ATTR:
        TARG_ASSERT(false,
            "TARGETING::Target::getAttr<0x%7x>: tryGetAttr returned false",
            i_ffdc);
        break;
    case GET_ATTR_AS_STRING:
        TARG_ASSERT(false,
            "TARGETING::Target::getAttrAsString<0x%7x>: tryGetAttr returned false",
            i_ffdc);
        break;
    case GET_ATTR_AS_STD_ARRAY:
        TARG_ASSERT(false,
            "TARGETING::Target::getAttrAsStdArray<0x%7x>: getAttrAsStdArray returned"
            " false",
            i_ffdc);
        break;
    case GET_HB_MUTEX_ATTR:
        TARG_ASSERT(false,
            "TARGETING::Target::_getHbMutexAttr<0x%7x>: _getAttrPtr returned NULL",
            i_ffdc);
        break;
    case GET_ATTR_TANK_TARGET_POS_DATA:
        TARG_ASSERT(false,
            "TARGETING::Target::getAttrTankTargetPosData: "
            "Error decoding class 0x%x", i_ffdc);
        break;
    case GET_ATTR_TANK_TARGET_POS_DATA_ATTR:
        TARG_ASSERT(false,
            "TARGETING::Target::getAttrTankTargetPosData: "
            "Error getting attr<0x%7x>)", i_ffdc);
        break;
    default:
        TARG_ASSERT(false,
            "TARGETING function asserted for unknown reason (0x%x)",
            i_ffdc);
    }
}

//******************************************************************************
// Target::installWriteAttributeCallback
//******************************************************************************
bool Target::installWriteAttributeCallback(
    TARGETING::pCallbackFuncPtr & i_callBackFunc)
{
    #define TARG_FN "installWriteAttributeCallback"
    TARG_ENTER();

    return __sync_bool_compare_and_swap(&cv_pCallbackFuncPtr,
                                        NULL, i_callBackFunc);
    TARG_EXIT();
    #undef TARG_FN
}

//******************************************************************************
// Target::uninstallWriteAttributeCallback
//******************************************************************************
bool Target::uninstallWriteAttributeCallback()
{
    #define TARG_FN "uninstallWriteAttributeCallback"
    TARG_ENTER();

    __sync_synchronize();
    cv_pCallbackFuncPtr = NULL;
    __sync_synchronize();
    return true;

    TARG_EXIT();
    #undef TARG_FN
}


//******************************************************************************
// Attribute Tanks
//******************************************************************************
AttributeTank Target::cv_overrideTank;
AttributeTank Target::cv_syncTank;

#undef TARG_CLASS

#undef TARG_NAMESPACE

} // End namespace TARGETING
