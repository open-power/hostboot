/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/prdf_types.h $                       */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2002,2012              */
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

#ifndef PRDF_TYPES_H
#define PRDF_TYPES_H

#include <stdint.h>

#undef NULL
#define NULL 0

#define BIT_LIST_CLASS prdfBitKey
#define BIT_STRING_CLASS prdfBitString
#define BIT_STRING_ADDRESS_CLASS prdfBitStringOffset
#define BIT_STRING_BUFFER_CLASS prdfBitStringBuffer
#define ResolutionMap prdfResolutionMap
#define FILTER_PRIORITY_CLASS prdfFilterPriority
#define FILTER_CLASS prdfFilter

#endif /* prdf_types_h */
