/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/iipconst.h $                         */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2002,2013              */
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

#ifndef IIPCONST_H
#define IIPCONST_H

/**
 @file iipconst.h
 @brief Common iternal constants used by PRD
*/

/*--------------------------------------------------------------------*/
/*  Includes                                                          */
/*--------------------------------------------------------------------*/
#include <prdf_types.h>

// FIXME: RTC: 51689 will address this issue
// Need these attribute header files in x86.nfp
#ifndef CONTEXT_x86_nfp
  #include <targeting/common/attributes.H>
#endif

/*--------------------------------------------------------------------*/
/*  User Types                                                        */
/*--------------------------------------------------------------------*/

// Type Specification //////////////////////////////////////////////////
//
//  Purpose:  TARGETING::TargetHandle_t is used to identify a Chip instance.
//
// End Type Specification //////////////////////////////////////////////

namespace PRDF
{
    // FIXME: RTC: 51689 will address this issue
    #ifndef CONTEXT_x86_nfp
    typedef TARGETING::ATTR_HUID_type HUID;
    #else
    typedef uint32_t HUID;
    #endif

    // FIXME: RTC: 62867 will resolve this
    enum { INVALID_HUID = 0 };

/*--------------------------------------------------------------------*/
/*  Constants                                                         */
/*--------------------------------------------------------------------*/

#ifndef SUCCESS
#define SUCCESS 0
#endif

#ifndef FAIL
#define FAIL -1
#endif

enum DOMAIN_ID
{
  UKNOWN_DOMAIN = 0,

  FABRIC_DOMAIN = 0x71,
  EX_DOMAIN     = 0x72,
  MCS_DOMAIN    = 0x73,
  MEMBUF_DOMAIN = 0x74,
  MBA_DOMAIN    = 0x75,
  XBUS_DOMAIN   = 0x76,
  ABUS_DOMAIN   = 0x77,

  CLOCK_DOMAIN_FAB      = 0x90,
  CLOCK_DOMAIN_MCS      = 0x91,
  CLOCK_DOMAIN_MEMBUF   = 0x92,

  END_DOMAIN_ID
};

} // end namespace PRDF

#endif
