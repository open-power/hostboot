//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/diag/prdf/iipconst.h $
//
//  IBM CONFIDENTIAL
//
//  COPYRIGHT International Business Machines Corp. 2012
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

#ifndef IIPCONST_H
#define IIPCONST_H

/**
 @file iipconst.h
 @brief Common iternal constants used by PRD
*/

/*--------------------------------------------------------------------*/
/*  Includes                                                          */
/*--------------------------------------------------------------------*/

#if !defined(PRDF_TYPES_H)
#include <prdf_types.h>
#endif

#include <target.H>

/*--------------------------------------------------------------------*/
/*  User Types                                                        */
/*--------------------------------------------------------------------*/

// Type Specification //////////////////////////////////////////////////
//
//  Purpose:  CHIP_ID_TYPE is used to identify a Chip instance.
//
// End Type Specification //////////////////////////////////////////////

typedef TARGETING::TargetHandle_t      CHIP_ID_TYPE;

/*--------------------------------------------------------------------*/
/*  Constants                                                         */
/*--------------------------------------------------------------------*/

#ifndef SUCCESS
#define SUCCESS 0
#endif

#ifndef FAIL
#define FAIL -1
#endif


/**
 *  @brief Enum specifying domain ids
 */
enum DOMAIN_ID
{
  UKNOWN_DOMAIN = 0,
  FABRIC_DOMAIN,
  EX_DOMAIN,
  MCS_DOMAIN,
  MEMBUF_DOMAIN,
  MBA_DOMAIN,
  CLOCK_DOMAIN_FAB,
  CLOCK_DOMAIN_MCS,
  CLOCK_DOMAIN_MEMBUF,

  END_DOMAIN_ID
};




#endif
