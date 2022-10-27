/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/targeting/attrTextOverride.H $                */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2023                        */
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
 *  @file attrTextOverride.H
 *
 *  @brief Defines functions to process attribute override data
 *         stored as ascii text in ATTR_TMP.
 */

#ifndef __ATTR_TEXT_OVERRIDE_H
#define __ATTR_TEXT_OVERRIDE_H

#include <errl/errlentry.H>
#include <targeting/common/attributeTank.H>

namespace TARGETING
{
    /**
     * TARG Attribute Text files are used to specify attribute overrides.
     *
     * These files contain :
     *  1) Target lines
     *     a) System Target line - associated attribute applies to
     *                              entire system
     *     b) Unit Target line - associated attribute applies only to
     *                            explicitly identified Unit
     *  2) Attribute Lines  (associated with the most recent target line)
     *
     * ---------------------------------------
     * The format of a System Target Line is :
     *
     *   target = <system string>
     *
     *      <system string>
     *          kx:sy[:]          note: x=0, y=0
     *
     *          Note : some additional obsolete forms have been
     *                  grandfathered in:
     *
     *          blank             note: interpreted as k0:s0
     *          kx:nz:sy[:]       note: x=0, y=0, z=0 or all
     *
     * ---------------------------------------
     * The format of a Unit Target Line is :
     *
     *   target =  <system string> || [:nz] ||
     *              :<chip type> || [.<chip unit type>] ||
     *              :<chip position> || [:<unit position>]
     *
     *       Examples:
     *         target = k0:s0:n0:ocmb:p04         // no optional fields
     *         target = k0:s0:n0:p10.iohs:p01:c2  // all optional fields
     *
     *          ---- OR ----
     *   target =  <chip type> || [.<chip unit type>] ||
     *              : <system string> || [:nz] ||
     *              :<chip position> || [:<unit position>]
     *
     *       Examples:
     *         target = ocmb:k0:n0:s0:p04         // no optional fields
     *         target = p10.iohs:k0:n0:s0:p01:c2  // all optional fields
     *
     *
     *      <system string> is defined above;  x=0, y=0
     *
     *      nz : optional node number term
     *             z may be :
     *             - single digit 0-9
     *             - comma separated list of digits 0-9
     *                -- 2 or more items in list
     *                -- no ordering dependencies
     *                e.g. 0,4
     *                e.g. 5,3,9
     *             - all
     *
     *      <chip type>
     *         definitions :
     *           src/usr/targeting/attroverride/attrTextToBinaryBlob.C
     *           AttrOverrideSyncConstants::CHIP_TYPE_TARG_STR_TO_TYPE
     *           e.g.  p9n, pu, dimm
     *
     *      <chip unit type>
     *         definitions :
     *           src/usr/targeting/attroverride/attrTextToBinaryBlob.C
     *           AttrOverrideSyncConstants::CHIP_UNIT_TYPE_TARG_STR_TO_TYPE
     *           e.g.  ex, mca, obus
     *
     *      <chip position>
     *         pw
     *            note : w may be :
     *             - single number 0 - 65,534
     *             - comma separated list of digits 0 - 65,534
     *                -- 2 or more items in list
     *                -- no ordering dependencies
     *                e.g. 0,4
     *                e.g. 5,3,9
     *             - all
     *
     *      <unit position>
     *         cv
     *            note : v may be :
     *             - single number 0 - 254
     *             - comma separated list of digits 0 - 254
     *                -- 2 or more items in list
     *                -- no ordering dependencies
     *                e.g. 0,4
     *                e.g. 5,3,9
     *             - all
     *
     *
     * ---------------------------------------
     * The format of an Attribute Line is:
     *
     *   <FAPI-ATTR-ID-STR>[<ARRAY-DIMS>] [<ATTR-TYPE>] <ATTR-VAL> [CONST]
     *
     *     <FAPI-ATTR-ID-STR>
     *       The FAPI Attr ID string for the attribute.
     *       defined in obj/genfiles/attributeenums.H
     *
     *     <ARRAY-DIMS>
     *       The array dimension (if any) within the attribute for this value
     *
     *     <ATTR-TYPE>
     *       The type of the attribute, uint8/16/32/64 and the array dimensions
     *       if any, this is optional
     *
     *     <ATTR-VAL>
     *       Attribute value, literal or enumerator
     *
     *     CONST
     *       If the attribute override is constant
     *
     * ---------------------------------------
     * Example:
     *   CLEAR
     *   # This is a comment
     *   target = k0:s0
     *   ATTR_SCRATCH_UINT8_1 u8 0x12
     *   ATTR_SCRATCH_UINT32_1 u32 0x12345678
     *   ATTR_SCRATCH_UINT64_1 u64 0x8000000000000001 CONST
     *
     *   target = k0:s0:n0:ocmb.mp:p00:c0
     *   ATTR_MEM_EFF_DIMM_TYPE[0] u8[2] 0x04 CONST
     *   ATTR_MEM_EFF_DIMM_TYPE[1] u8[2] 0x00 CONST
     *
     *   target = k0:s0:nall:p10:pall
     *   ATTR_VOLTAGE_EXT_VDD_BIAS_ULTRATURBO -5 CONST
     *
     *   target = k0:s0:n0:ocmb:p04
     *   ATTR_FREQ_OMI_MHZ 0x00006400 CONST
     *
     *   target = k0:s0:n0,6,9:ocmb.mp:p06:c1
     *   ATTR_SPPE_TARGET_STATE 0x02 CONST
     *
     */


    /**
     * Enum returned when determining target types
     */
    enum TargetTypeRc
    {
        TARGET_TYPE_RC_SYSTEM,
        TARGET_TYPE_RC_NODE,
        TARGET_TYPE_RC_CHIP,
        TARGET_TYPE_RC_ERROR,
        TARGET_TYPE_RC_NONE
    };

    /**
     * Structure for target's identification
     *
     * node         Target Node Number
     * targetPos    Target Position (chip position)
     * unitPos      Target Unit Position
     */
    struct target_label
    {
        uint8_t node;
        uint16_t targetPos;
        uint8_t unitPos;
        target_label():node(AttributeTank::ATTR_NODE_NA),
                       targetPos(AttributeTank::ATTR_POS_NA),
                       unitPos(AttributeTank::ATTR_UNIT_POS_NA){}
    };

    /**
     * @brief This function parses the attribute override text data from the
     *        ATTR_TMP and sets them in the corresponding attribute tank
     *
     * @param[in] i_sectionInfo   PNOR::SectionInfo_t to look for overrides
     *
     * @return errlHndl_t         Error log handle.
     */
    errlHndl_t attrTextOverride( const PNOR::SectionInfo_t &i_sectionInfo );

} // namespace TARGETING


/**
 * Struct used to hold attribute data from generated file
 * targAttrOverrideData.H
 */
struct AttributeData
{
    const char* iv_name;
    uint32_t iv_attrId;
    size_t iv_attrElemSizeBytes;
    size_t iv_dims[4];
};

/**
 * Struct used to hold attribute data
 */
struct AttributeEnum
{
    const char* iv_name;
    uint64_t iv_value;
};

#endif
