/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/kernel/terminate.C $                                      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2020                        */
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

#include <kernel/hbdescriptor.H>
#include <kernel/hbterminatetypes.H>
#include <kernel/terminate.H>
#include <sys/sync.h>
#include <sys/mmio.h>
#include <arch/ppc.H>
#include <arch/magic.H>
#ifndef BOOTLOADER
#include <stdint.h>
#include <kernel/console.H>
#include <kernel/ipc.H>

#include <builtins.h>
#include <kernel/kernel_reasoncodes.H>
#endif // BOOTLOADER

extern "C" void p9_force_attn() NO_RETURN;

#ifndef BOOTLOADER
mutex_t g_kernelMutex;

/* Instance of the TI Data Area */
HB_TI_DataArea kernel_TIDataArea = {};

/* Instance of the HB descriptor struct */
HB_Descriptor kernel_hbDescriptor =
{
    &kernel_TIDataArea,
    &KernelIpc::ipc_data_area,
    0
};
#endif // BOOTLOADER


void terminateExecuteTI()
{
    // Trigger a hostboot dump in Simics
    MAGIC_INSTRUCTION(MAGIC_HB_DUMP);

    // Save off the location of the TI area before terminating.
    setTiAreaScratchReg();

    // Call the function that actually executes the TI code.
    p9_force_attn();
}

void initKernelTIMutex()
{
#ifndef BOOTLOADER
    mutex_init(&g_kernelMutex);
#endif
}

#ifndef BOOTLOADER
void termWriteEid(hb_terminate_source i_source, uint32_t i_eid)
{
    kernel_TIDataArea.tiAreaValid = 0x1;
    kernel_TIDataArea.command = DEFAULT_COMMAND;
    kernel_TIDataArea.hardwareDumpType = SW_DUMP;
    kernel_TIDataArea.type = TI_WITH_EID;
    kernel_TIDataArea.source = i_source;
    kernel_TIDataArea.eid = i_eid;
}
#endif // BOOTLOADER

void termWriteSRC(hb_terminate_source i_source, uint16_t i_reasoncode,
                  uint64_t i_failAddr, uint32_t i_error_data, bool i_forceWrite)
{
#ifndef BOOTLOADER
    mutex_lock(&g_kernelMutex);
#endif
    // If this is the first TI on the system or if i_forceWrite is true, then
    // overwrite the HB TI area with the given info. Unless i_forceWrite is
    // true, all subsequent TI codes will NOT overwrite the original TI
    // information.
    if(kernel_TIDataArea.src.reasoncode == NO_TI_ERROR || i_forceWrite)
    {
        kernel_TIDataArea.tiAreaValid = 0x1;
        kernel_TIDataArea.command = DEFAULT_COMMAND;
        kernel_TIDataArea.hardwareDumpType = SW_DUMP;
        // Update the TI structure with the type of TI, who called,
        // and extra error data (if applicable, otherwise 0)
        kernel_TIDataArea.type = TI_WITH_SRC;
        kernel_TIDataArea.source = i_source;
        kernel_TIDataArea.error_data = i_error_data;

        // Update TID data area with the SRC info we have avail
        kernel_TIDataArea.src.ID = 0xBC;
        kernel_TIDataArea.src.subsystem = 0x8A;
        kernel_TIDataArea.src.reasoncode = i_reasoncode;
        kernel_TIDataArea.src.moduleID = 0;
        kernel_TIDataArea.src.iType = TI_WITH_SRC;
        kernel_TIDataArea.src.iSource = i_source;

        // Update User Data with address of fail location
        kernel_TIDataArea.src.word6 = i_failAddr;
    }

#ifndef BOOTLOADER
    mutex_unlock(&g_kernelMutex);
#endif
}

void termModifySRC(uint8_t i_moduleID, uint32_t i_word7, uint32_t i_word8)
{
    // Update module ID
    kernel_TIDataArea.src.moduleID = i_moduleID;

    // Update User Data with anything supplied for word7 or word8
    kernel_TIDataArea.src.word7 = i_word7;
    kernel_TIDataArea.src.word8 = i_word8;
}

#ifndef BOOTLOADER
void termSetHbDump(void)
{
    // Set indicator flag for doing HB dump
    kernel_TIDataArea.hbDumpFlag = 1;

    return;
}

void termSetIstep(uint32_t i_istep)
{
    // Set istep into progress code word of the SRC
    kernel_TIDataArea.src.SRCword4 = i_istep;
    return;
}

#endif // BOOTLOADER

void setTiAreaScratchReg()
{
    // Save off the TI Area so that SBE can fetch it from the scratch reg
    uint64_t l_tiAreaAddr = reinterpret_cast<uint64_t>(&kernel_TIDataArea);
    // HB TI pointer is relative to HRMOR, so need to OR HRMOR in
    l_tiAreaAddr |= getHRMOR();
    writeScratchReg(MMIO_SCRATCH_TI_AREA_LOCATION, l_tiAreaAddr);
}


//  SRC parser comments for early boot TI failures
/*@
 *  @errortype
 *  @moduleid       KERNEL::MOD_KERNEL_INVALID
 *  @reasoncode     KERNEL::RC_EARLY_BOOT_FAIL
 *  @userdata1      <unused>
 *  @userdata2      <unused>
 *  @devdesc        Unknown TI from Hostboot
 *  @custdesc       Firmware boot failure
 */
