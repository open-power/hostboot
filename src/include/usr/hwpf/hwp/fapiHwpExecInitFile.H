//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/include/usr/hwpf/hwp/fapiTestHwp.H $
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
 *  @file fapiHwpExecInitFile.H
 *
 *  @brief Defines for Hardware Procedure initfile execution
 */

/*
 * Change Log ******************************************************************
 * Flag     Defect/Feature  User        Date        Description
 * ------   --------------  ----------  ----------- ----------------------------
 *                          camvanng    09/29/2011  Created.
 *
 */

#ifndef FAPIHWPEXECINITFILE_H_
#define FAPIHWPEXECINITFILE_H_

#include <fapi.H>

// HWPs are defined as C functions because platforms may wish to package them
// in linux shared libraries which are DL-Opened
extern "C"
{

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
    PUSH_MASK  = 0x000000C0,
    OP_MASK    = 0x000000FF
};

/**
 * @brief Enumeration of Type Mask
 */
enum IfTypeMask
{
    IF_LIT_TYPE        = 0x4000,
    IF_VAR_TYPE        = 0x8000,
    IF_NUM_TYPE        = 0xC000,
    IF_TYPE_MASK       = 0xC000,
};

/**
 * @brief Enumeration of Attribute types 
 */
enum IfAttrType
{
    SYM_ATTR_UINT8_TYPE = 0x00,
    SYM_ATTR_UINT32_TYPE = 0x01,
    SYM_ATTR_UINT64_TYPE = 0x02,
    SYM_ATTR_UINT8_ARRAY_TYPE = 0x03,
    SYM_ATTR_UINT32_ARRAY_TYPE = 0x04,
    SYM_ATTR_UINT64_ARRAY_TYPE = 0x05,
};



/**
* @brief HWP to execute an initfile.
*
* @param[in] i_chip Reference to target chip
* @param[in] i_file filename of binary initfile 
*
* @return ReturnCode
*/
fapi::ReturnCode hwpExecInitFile(const fapi::Target & i_chip, const char * i_file);

} // extern "C"

#endif // FAPIHWPEXECINITFILE_H_
