/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/prdfGlobal_common.H $                */
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
