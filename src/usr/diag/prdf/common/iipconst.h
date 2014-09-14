/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/iipconst.h $                         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2014                        */
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
#include <targeting/common/attributes.H>

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
    typedef TARGETING::ATTR_HUID_type HUID;

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
  CLOCK_DOMAIN_IO       = 0x93,

  END_DOMAIN_ID
};

} // end namespace PRDF

#endif
