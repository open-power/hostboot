/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/targeting/common/target.C $                           */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2023                        */
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

        // Walk the PHYS_PATH from top (sys) down element by element and set o_node, o_pos, and o_unitPos accordingly.
        for (uint32_t i = 0; i < l_physPath.size(); i++)
        {
            // Grab the path element
            const EntityPath::PathElement & l_element = l_physPath[i];

            // Check the type this element is
            switch(l_element.type)
            {
                case(TYPE_NODE):
                case(TYPE_CONTROL_NODE):
                {
                    // Element was a node, instance is the position value for the node.
                    // ex. /sys-0/node-1/.../
                    // instance == 1
                    o_node = l_element.instance;
                    break;
                }
                case(TYPE_PROC):
                case(TYPE_MEMBUF):
                case(TYPE_DIMM):
                case(TYPE_BMC):
                case(TYPE_OCMB_CHIP):
                case(TYPE_PMIC):
                case(TYPE_GENERIC_I2C_DEVICE):
                case(TYPE_FSP):
                case(TYPE_PNOR):
                case(TYPE_APSS):
                case(TYPE_DPSS):
                case(TYPE_TPM):
                case(TYPE_TEMP_SENSOR):
                case(TYPE_POWER_IC):
                case(TYPE_MDS_CTLR):
                {
                    // Element was a CHIP, instance is the position value for the chip
                    // ex. /sys-0/node-1/proc-2/.../
                    // instance == 2
                    // o_pos refers to the parent chip's position. In the above example some arbitrary child unit of a
                    // proc is being looked up.
                    o_pos = l_element.instance;
                    break;
                }
                case(TYPE_MC):
                case(TYPE_EQ):
                case(TYPE_CAPP):
                case(TYPE_PERV):
                case(TYPE_PEC):
                case(TYPE_PHB):
                case(TYPE_OMI):
                case(TYPE_SMPGROUP):
                case(TYPE_MCC):
                case(TYPE_OMIC):
                case(TYPE_MEM_PORT):
                case(TYPE_NMMU):
                case(TYPE_PAU):
                case(TYPE_IOHS):
                case(TYPE_PAUC):
                case(TYPE_CORE):
                case(TYPE_MI):
                case(TYPE_FC):
                case(TYPE_NX):
                case(TYPE_OCC):
                {
                    // Element was a UNIT. In this case, the attribute CHIP_UNIT has the correct position value.
                    // processMrw.pl is responsible for calculating the right unit position so take that.
                    void * l_pUnitPos = NULL;
                    _getAttrPtr(ATTR_CHIP_UNIT, l_pUnitPos);
                    if (l_pUnitPos)
                    {
                        AttributeTraits<ATTR_CHIP_UNIT>::Type & l_unitPos =
                            *(reinterpret_cast<AttributeTraits<ATTR_CHIP_UNIT>::Type *>(l_pUnitPos));

                        o_unitPos = l_unitPos;
                    }
                    break;
                }
                case(TYPE_SYS):
                {
                    o_pos = AttributeTank::ATTR_POS_NA;
                    o_unitPos = AttributeTank::ATTR_UNIT_POS_NA;
                    o_node = AttributeTank::ATTR_NODE_NA;
                    break;
                }
                case(TYPE_XBUS):
                case(TYPE_ABUS):
                case(TYPE_OBUS):
                case(TYPE_OBUS_BRICK):
                case(TYPE_L2):
                case(TYPE_L3):
                case(TYPE_L4):
                case(TYPE_NPU):
                case(TYPE_PCI):
                case(TYPE_OSC):
                case(TYPE_TODCLK):
                case(TYPE_OSCPCICLK):
                case(TYPE_REFCLKENDPT):
                case(TYPE_PORE):
                case(TYPE_PCIESWITCH):
                case(TYPE_MFREFCLKENDPT):
                case(TYPE_SP):
                case(TYPE_UART):
                case(TYPE_PS):
                case(TYPE_FAN):
                case(TYPE_VRM):
                case(TYPE_USB):
                case(TYPE_ETH):
                case(TYPE_PANEL):
                case(TYPE_FLASH):
                case(TYPE_SEEPROM):
                case(TYPE_TMP):
                case(TYPE_GPIO_EXPANDER):
                case(TYPE_POWER_SEQUENCER):
                case(TYPE_RTC):
                case(TYPE_FANCTLR):
                case(TYPE_MFREFCLK):
                case(TYPE_I2C_MUX):
                case(TYPE_FSI):
                case(TYPE_PSI):
                case(TYPE_SBE):
                case(TYPE_PPE):
                case(TYPE_MCS):
                case(TYPE_MCA):
                case(TYPE_DMI):
                case(TYPE_MBA):
                case(TYPE_MCBIST):
                case(TYPE_EX):
                case(TYPE_OSCREFCLK):
                case(TYPE_PCICLKENDPT):
                case(TYPE_SYSREFCLKENDPT):
                case(TYPE_LPCREFCLKENDPT):
                case(TYPE_NA):
                case(TYPE_TEST_FAIL):
                case(TYPE_DCM):
                case(TYPE_LAST_IN_RANGE):
                case(TYPE_INVALID):
                {
                    // not supported. Assert to follow below.
                    TRACFCOMP(g_trac_targeting, "getAttrTankTargetPosData(): Unsupported unit type found 0x%X",
                              l_element.type);
                    break;
                }
            } // end switch(l_element.type)
        } // end for

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
                case(TARGETING::CLASS_INVALID):
                    targAssert(GET_ATTR_TANK_TARGET_POS_DATA, ATTR_CLASS);
            } // end swtich(l_class)
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
