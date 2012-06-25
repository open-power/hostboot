/*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/usr/hwpf/plat/fapiPlatAttrOverrideDirect.C $
 *
 *  IBM CONFIDENTIAL
 *
 *  COPYRIGHT International Business Machines Corp. 2012
 *
 *  p1
 *
 *  Object Code Only (OCO) source materials
 *  Licensed Internal Code Source Materials
 *  IBM HostBoot Licensed Internal Code
 *
 *  The source code for this program is not published or other-
 *  wise divested of its trade secrets, irrespective of what has
 *  been deposited with the U.S. Copyright Office.
 *
 *  Origin: 30
 *
 *  IBM_PROLOG_END_TAG
 */
/**
 *  @file fapiPlatAttrOverrideDirect.C
 *
 *  @brief Defines a PLAT function that applies a HWPF Attribute Override
 *         written directly into Hostboot memory from the Simics/VBU console
 */

//******************************************************************************
// Includes
//******************************************************************************
#include <util/singleton.H>
#include <hwpf/fapi/fapiAttributeOverride.H>

namespace fapi
{

//******************************************************************************
// Global Variables
//******************************************************************************
AttributeOverride g_attrOverride;

//******************************************************************************
// platAttrOverrideDirect
// Apply a HWPF Attribute Override written directly into Hostboot memory from
// the Simics/VBU console. This function is called by a Simics/VBU debug tool
//******************************************************************************
void platAttrOverrideDirect()
{
    // Apply the attribute override
    Singleton<fapi::AttributeOverrides>::instance().setOverride(g_attrOverride);
}

}
