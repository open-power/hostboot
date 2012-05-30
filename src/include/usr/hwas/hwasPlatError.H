/*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/include/usr/hwas/hwasPlatError.H $
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
#ifndef __HWAS_PLAT_ERROR_H
#define __HWAS_PLAT_ERROR_H

/**
* @file hwas/hwasPlatError.H
*
* @brief Adapts platform neutral error log requests to the platform
*/

//******************************************************************************
// Includes
//******************************************************************************

// Include the platform specific errlentry.H file and pick up the platform
// specific errlHndlt_t typedef. This is enough for common code to use pass
// errlHndl_t pointers around and check for NULL
#include <errl/errlmanager.H>

namespace HWAS
{

namespace COMMON
{
/**
* @brief Import the ::ERRORLOG namespace into the ::HWAS:COMMON
* namespace. This allows all the common hwas code to use the
* same namespacing yet directly invoke platform specific error log
* support. Since nothing else is declared in the namespace, there is
* no danger of a namespace collision.
*/
using namespace ::ERRORLOG;

} // End namespace COMMON

} // End namespace HWAS

#endif // __HWAS_PLAT_ERROR_H
