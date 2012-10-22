/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/kernel/terminate.C $                                      */
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

#include <kernel/hbdescriptor.H>
#include <kernel/hbterminatetypes.H>
#include <kernel/terminate.H>
#include <stdint.h>
#include <kernel/console.H>

#include <builtins.h>

extern "C" void p8_force_attn() NO_RETURN;


/* Instance of the TI Data Area */
HB_TI_DataArea kernel_TIDataArea;

/* Instance of the HB desriptor struct */
HB_Descriptor kernel_hbDescriptor = {&kernel_TIDataArea};

void terminateAndUpdateSaveArea(uint16_t i_type, uint16_t i_source, uint64_t *i_src, uint64_t
                                plid)
{

printk("Inside terminateandupdateSaveArea!!!!!!!!!!!!!!! \n");
  kernel_TIDataArea.type = i_type;
  kernel_TIDataArea.source = i_source;
  memcpy(i_src, kernel_TIDataArea.src, sizeof (kernel_TIDataArea.src));
  kernel_TIDataArea.plid = plid;
  

printk("Calling p8_force_attn!!! dying.... \n");
  // After the data is set up .. call the function that actually executes the TI.
  p8_force_attn();

}
