/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/kernel/hbdescriptor.H $                           */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2013              */
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

/** @file hbdescriptor.H
 *  @brief Defines hostboot data area
 */

#ifndef __KERNEL_HBDESCRIPTOR_H
#define __KERNEL_HBDESCRIPTOR_H

#include <stdint.h>

struct HB_TI_DataArea;

namespace KernelIpc { struct ipc_data_area_t; };

struct HB_Descriptor
{
     HB_TI_DataArea *TI_DataAreaPtr;  // ptr to the TI data area structure
     KernelIpc::ipc_data_area_t *IPC_DataAreaPtr; // ptr to the IPC data area
     uint64_t kernelMemoryState;
};

#endif /* __KERNEL_HBDESCRIPTOR_H */
