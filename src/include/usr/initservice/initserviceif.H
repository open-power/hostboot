//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/include/usr/initservice/initserviceif.H $
//
//  IBM CONFIDENTIAL
//
//  COPYRIGHT International Business Machines Corp. 2011
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
#ifndef __INITSERVICE_INITSERVICEIF_H
#define __INITSERVICE_INITSERVICEIF_H

#include <vmmconst.h>

namespace INITSERVICE
{

/**
 * @brief Register a block/range of vitual memory to be handled during a
 *        shutdown.
 *
 * @param[in] i_vaddr - Base virtual address
 * @param[in] i_size - Size of virtual memory from base address
 * @param[in] i_priority - Order to handle given block(0-Lowest Priority)
 *
 * @return Nothing
 */
void registerBlock(void* i_vaddr, uint64_t i_size, BlockPriority i_priority);

}

#endif
