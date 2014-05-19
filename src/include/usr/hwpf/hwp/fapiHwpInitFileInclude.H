/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/hwpf/hwp/fapiHwpInitFileInclude.H $           */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2011,2014              */
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
 *  @file fapiHwpInitFileInclude.H
 *
 *  @brief Common defines for Hardware Procedure initfile execution
 */

/*
 * Change Log ******************************************************************
 * Flag     Defect/Feature  User        Date        Description
 * ------   --------------  ----------  ----------- ----------------------------
 *                          andrewg     11/09/2011  Created.
 *                          camvanng    11/16/2011  Support for system & target
 *                                                  attributes
 *                          camvanng    05/07/2012  Support for associated
 *                                                  target attributes
 *                          camvanng    06/15/2012  Ability to do bitwise OR and
 *                                                  AND operations
 */

#ifndef FAPIHWPINITFILEINCLUDE_H_
#define FAPIHWPINITFILEINCLUDE_H_

/**
 * @brief Enumeration of RPN ops 
 */
enum IfRpnOp
{
    AND        = 0x00000001,
    OR         = 0x00000002,
    NOT        = 0x00000003,
    EQ         = 0x00000004,
    NE         = 0x00000005,
    GT         = 0x00000006,
    GE         = 0x00000007,
    LT         = 0x00000008,
    LE         = 0x00000009,
    PLUS       = 0x0000000A,
    MINUS      = 0x0000000B,
    MULT       = 0x0000000C,
    DIVIDE     = 0x0000000D,
    MOD        = 0x0000000E,
    LIST       = 0x0000000F,
    SHIFTLEFT  = 0x00000010,
    SHIFTRIGHT = 0x00000011,
    FALSE_OP   = 0x00000012,
    TRUE_OP    = 0x00000013,
    BITWISEAND = 0x00000014,
    BITWISEOR  = 0x00000015,
    LAST_OP    = 0x00000016,
    PUSH_MASK  = 0x000000C0,
    OP_MASK    = 0x000000FF
};

/**
 * @brief Enumeration of Type Mask
 */
enum IfTypeMask
{
    IF_NUM_TYPE            = 0x4000,
    IF_ATTR_TYPE           = 0x8000,
    IF_SYS_ATTR_TYPE       = 0xA000,
    IF_ASSOC_TGT_ATTR_TYPE = 0xC000,
    IF_TYPE_MASK           = 0xE000,
};

// Id mask
const uint16_t IF_ID_MASK = static_cast<uint16_t>(~IF_TYPE_MASK);

// Only support up to 4 dimensions for an array
const uint8_t MAX_ATTRIBUTE_ARRAY_DIMENSION = 4;

// Used for array size parsing
const uint8_t ATTR_DIMENSION_MASK = 0xF0;

// Most significant nibble in 1 byte attribute type will indicate array dimension
const uint8_t ATTR_DIMENSION_SIZE_MULT = 0x10;

/**
 * @brief Enumeration of Attribute types
 *
 * Note that the most significant nibble is used to determine dimension size
 * by the procedure executing the initfile.  
 */
enum IfAttrType
{
    SYM_ATTR_UINT8_TYPE = 0x00,
    SYM_ATTR_UINT8_ARRAY1_TYPE = 0x11,
    SYM_ATTR_UINT8_ARRAY2_TYPE = 0x22,
    SYM_ATTR_UINT8_ARRAY3_TYPE = 0x33,
    SYM_ATTR_UINT8_ARRAY4_TYPE = 0x44,
    SYM_ATTR_UINT32_TYPE = 0x05,
    SYM_ATTR_UINT32_ARRAY1_TYPE = 0x16,
    SYM_ATTR_UINT32_ARRAY2_TYPE = 0x27,
    SYM_ATTR_UINT32_ARRAY3_TYPE = 0x38,
    SYM_ATTR_UINT32_ARRAY4_TYPE = 0x49,
    SYM_ATTR_UINT64_TYPE = 0x0A,
    SYM_ATTR_UINT64_ARRAY1_TYPE = 0x1B,
    SYM_ATTR_UINT64_ARRAY2_TYPE = 0x2C,
    SYM_ATTR_UINT64_ARRAY3_TYPE = 0x3D,
    SYM_ATTR_UINT64_ARRAY4_TYPE = 0x4E,
};




#endif /* FAPIHWPINITFILEINCLUDE_H_ */

