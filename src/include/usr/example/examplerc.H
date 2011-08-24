//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/include/usr/example/examplerc.H $
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
// This file is an example how you create a reason code to pass in an
// error log creation

#ifndef __EXAMPLE_RC_H
#define __EXAMPLE_RC_H

#include <hbotcompid.H>

// The definitions in this file is an example that shows how to define
// reason codes.  Each Host Boot component should have a service code
// file (<component>reasoncodes.H) that defines its module IDs and
// unique reason codes.
// See errlreasoncodes.H for example of this file for ERRL component.

// Below is an example of defining reason codes
enum myModuleId
{
    MY_MODULE_ID_1        = 0x00,
    //........
    MY_LAST_MODULE_ID     = 0xFF
};

// This enum definition should be in an .H file in your component area.
// MY_COMPONENT_ID is your component name defined in hbotcompid.H file
// included above.
enum myReasonCode
{
    MY_REASON_CODE_1                = MY_COMP_ID | 0x01,
    //........
    ERRL_LAST_REASON_CODE           = MY_COMP_ID | 0xFF
};

#endif
