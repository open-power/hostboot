/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/hwpf/plat/fapiPlatAttrOverrideSync.H $        */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012                   */
/*                                                                        */
/* p1                                                                     */
/*                                                                        */
/* Object Code Only (OCO) source materials                                */
/* Licensed Internal Code Source Materials                                */
/* IBM HostBoot Licensed Internal Code                                    */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* Origin: 30                                                             */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
/**
 *  @file fapiPlatAttrOverrdieSync.H
 *
 *  @brief Defines the functions for Attribute Override and Sync
 */

#ifndef FAPIPLATATTROVERRIDESYNC_H_
#define FAPIPLATATTROVERRIDESYNC_H_

//******************************************************************************
// Includes
//******************************************************************************
#include <stdint.h>
#include <hwpf/fapi/fapiAttributeTank.H>

//******************************************************************************
// Interface
//******************************************************************************
namespace fapi
{

namespace attrOverrideSync
{

/**
 * @brief Monitors for incoming messages from the FSP. This must be called
 *        by a task specifically started to monitor for these messages
 */
void monitorForFspMessages();

/**
 * @brief Sends Attribute Overrides and Syncs to the FSP
 *
 * This is called at the end of an IStep. It:
 * - Clears the FSP Attribute Overrides
 * - Sends the Hostboot Attribute Overrides to the FSP
 * - Sends the Hostboot Attribute Syncs to the FSP
 */ 
void sendAttrOverridesAndSyncsToFsp();

/**
 * @brief This function returns the OverrideAttributeTank singleton. Other
 *        modules must call this rather than using Singleton<>
 */
AttributeTank & theOverrideAttrTank();

/**
 * @brief This function returns the SyncAttributeTank singleton. Other
 *        modules must call this rather than using Singleton<>
 */
AttributeTank & theSyncAttrTank();

} // namespace attrOverrideSync

} // namespace fapi

/**
 *  @brief Macro that is called on a FAPI_ATTR_GET that returns any Attribute
 *         Override
 */
#define FAPI_PLAT_GET_ATTR_OVERRIDE(ID, PTARGET, VAL) \
    fapi::getAttributeT(ID, PTARGET, fapi::attrOverrideSync::theOverrideAttrTank(), VAL)

/**
 *  @brief Macro that is called on a FAPI_ATTR_SET that clears any non-const
 *         Attribute Override and saves the Attribute to Sync
 */
#define FAPI_PLAT_ATTR_SET_ACTIONS(ID, PTARGET, VAL) \
    fapi::attrOverrideSync::theOverrideAttrTank().clearNonConstAttribute(ID, PTARGET), \
    fapi::setAttributeT(ID, PTARGET, fapi::attrOverrideSync::theSyncAttrTank(), VAL)

#endif // FAPIPLATATTROVERRIDESYNC_H_
