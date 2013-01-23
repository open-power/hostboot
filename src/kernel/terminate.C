/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/kernel/terminate.C $                                      */
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

#include <kernel/hbdescriptor.H>
#include <kernel/hbterminatetypes.H>
#include <kernel/terminate.H>
#include <stdint.h>
#include <kernel/console.H>

#include <builtins.h>
#include <kernel/kernel_reasoncodes.H>

extern "C" void p8_force_attn() NO_RETURN;


/* Instance of the TI Data Area */
HB_TI_DataArea kernel_TIDataArea;

/* Instance of the HB desriptor struct */
HB_Descriptor kernel_hbDescriptor = {&kernel_TIDataArea};



void terminateExecuteTI()
{
    // Call the function that actually executes the TI code.
    p8_force_attn();
}

void termWritePlid(uint16_t i_source, uint64_t plid)
{
    kernel_TIDataArea.type = TI_WITH_PLID;
    kernel_TIDataArea.source = i_source;
    kernel_TIDataArea.plid = plid;
}

void termWriteSRC(uint16_t i_source, uint16_t i_reasoncode,uint64_t i_failAddr)
{
    // Update the TI structure with the type of TI and who called.
    kernel_TIDataArea.type = TI_WITH_SRC;
    kernel_TIDataArea.source = i_source;

    // Update TID data area with the SRC info we have avail
    kernel_TIDataArea.src.ID = 0xBC;
    kernel_TIDataArea.src.subsystem = 0x11;
    kernel_TIDataArea.src.reasoncode = i_reasoncode;
    kernel_TIDataArea.src.moduleID = 0;
    kernel_TIDataArea.src.iType = TI_WITH_SRC;

    // Update User Data with address of fail location
    kernel_TIDataArea.src.word6 = i_failAddr;
}
