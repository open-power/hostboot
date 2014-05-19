/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/prdfGlobal_common.H $                */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2002,2014              */
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

#ifndef PRDF_GLOBAL_COMMON_H
#define PRDF_GLOBAL_COMMON_H

/**
 * @file  prdfGlobal_common.H
 * @brief PRD global code used by external components.
 *
 * This file contains the Processor Runtime
 * Diagnostics global variable and type declarations.
 */

/*--------------------------------------------------------------------*/
/*  Includes                                                          */
/*--------------------------------------------------------------------*/

#include <prdf_types.h>
#include <prdfErrlSmartPtr.H>

namespace PRDF
{
/*--------------------------------------------------------------------*/
/*  Forward References                                                */
/*--------------------------------------------------------------------*/

class System;
/*--------------------------------------------------------------------*/
/*  Global Variables                                                  */
/*--------------------------------------------------------------------*/

  extern System * systemPtr;
  extern ErrlSmartPtr g_prd_errlHndl;

} //End namespace PRDF

/*--------------------------------------------------------------------*/
/*  Errl macros common to both FSP and Hostboot                      */
/*--------------------------------------------------------------------*/

/**
 * @brief Convert any integer to uint64_t
 */
#define PRDF_GET_UINT64(x)    static_cast<uint64_t>(x)

/**
 * @brief store two uint32_t to uint64_t
 */
#define PRDF_GET_UINT64_FROM_UINT32(l_32, r_32) \
            ( (PRDF_GET_UINT64(l_32) << 32) | PRDF_GET_UINT64(r_32) )

#endif // PRDF_GLOBAL_COMMON_H
