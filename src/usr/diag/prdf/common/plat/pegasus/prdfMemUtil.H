/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/pegasus/prdfMemUtil.H $         */
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

#ifndef prdfMemUtil_H
#define prdfMemUtil_H

/** @file  prdfMemUtil.H
 *  @brief General utility functions for the memory subsystem.
 */

#include <iipconst.h>

namespace PRDF
{

class ExtensibleChip;
struct STEP_CODE_DATA_STRUCT;

namespace MemUtil
{

//#ifdef __HOSTBOOT_MODULE

/**
 * @brief  Clears bits in the MCIFIR that are triggered by centaur attentions
 *         that are reported to the host.
 * @param  i_memChip Any memory chip (MCS, MEMBUF, MBS, MBA, DIMM, etc.).
 * @param  i_sc      The step code data struct.
 * @return Non-SUCCESS for internal errors, SUCCESS otherwise.
 */
int32_t clearHostAttns( ExtensibleChip * i_memChip,
                        STEP_CODE_DATA_STRUCT & i_sc );

//#endif // __HOSTBOOT_MODULE

} // end namespace MemUtil
} // end namespace PRDF

#endif // prdfMemUtil_H
