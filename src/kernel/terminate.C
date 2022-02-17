/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/kernel/terminate.C $                                      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2022                        */
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
#include <sys/misc.h>
#include <arch/ppc.H>
#include <arch/magic.H>
#ifndef BOOTLOADER
#include <initservice/initserviceif.H>
#include <hbfw_term_rc.H>
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
void termWriteStatus(hb_terminate_source i_source,
                     uint64_t i_status,
                     uint64_t i_failAddr,
                     uint32_t i_error_info,
                     bool i_forceWrite)
{

    // If the shutdown was not called with a Good shutdown status
    // then we know we are shutting down due to error.  We need to
    // figure out if the error provided is an EID or reasoncode
    // and write it appropriately.
    // Hostboot EIDs always start with 0x9 (32-bit)
    static const uint64_t EID_MASK = 0x0000000090000000;

    if (i_status != SHUTDOWN_STATUS_GOOD)
    {
        if ((i_status & 0x00000000F0000000) == EID_MASK)
        {
            termWriteEid(i_source, i_status);
        }
        else
        {
            termWriteSRC(i_source, i_status, i_failAddr, i_error_info, i_forceWrite);
        }
    }
}
#endif

#ifndef BOOTLOADER
void termWriteEid(hb_terminate_source i_source, uint32_t i_eid)
{
    kernel_TIDataArea.tiAreaValid = 0x1;
    kernel_TIDataArea.command = DEFAULT_COMMAND;
    kernel_TIDataArea.hardwareDumpType = SW_DUMP;
    kernel_TIDataArea.type = TI_WITH_EID;
    kernel_TIDataArea.source = i_source;
    kernel_TIDataArea.eid = i_eid;

    // If we're terminating with an EID, generating another error log for the TI
    // would be redundant.
    kernel_TIDataArea.hbNotVisibleFlag = 1;
}

#ifndef CONFIG_FSP_BUILD
/** @brief Structure that associates SRC codes with whether or not the TI should
 * ask for a hostboot dump, and whether it should ask for a visible error to be
 * created.
 */
struct srcDumpAndLogPolicy
{
    uint32_t reasoncode = 0;
    bool hbDumpFlag = false;
    bool hbNotVisibleFlag = false;

    bool operator==(const uint32_t rc) const {
        return reasoncode == rc;
    }
};

constexpr bool HB_DUMP_ENABLED = true;
constexpr bool HB_DUMP_DISABLED = false;
constexpr bool PEL_NOT_VISIBLE = true;
constexpr bool PEL_VISIBLE = false;

// Table of SRCs that deviate from the default dump/errorlog policy.
const srcDumpAndLogPolicy special_src_policies[] =
{
    { HBFW::INITSERVICE::SHUTDOWN_REQUESTED_BY_FSP,          HB_DUMP_DISABLED, PEL_NOT_VISIBLE },
    { HBFW::SECUREBOOT::RC_PHYS_PRES_WINDOW_OPENED_SHUTDOWN, HB_DUMP_DISABLED, PEL_NOT_VISIBLE },
    { HBFW::INITSERVICE::SHUTDOWN_MFG_TERM,                  HB_DUMP_DISABLED, PEL_VISIBLE },
    { HBFW::INITSERVICE::SHUTDOWN_KEY_TRANSITION,            HB_DUMP_DISABLED, PEL_VISIBLE },
};

/** @brief Write the hbDumpFlag and hbNotVisibleFlag in the TI area based on an SRC.
 */
void termWriteDumpFlags(uint16_t i_reasoncode)
{
    using std::begin; using std::end;
    const auto rule = std::find(begin(special_src_policies), end(special_src_policies), i_reasoncode);

    if (rule != end(special_src_policies))
    {
        kernel_TIDataArea.hbDumpFlag = rule->hbDumpFlag;
        kernel_TIDataArea.hbNotVisibleFlag = rule->hbNotVisibleFlag;
    }
    else
    {
        kernel_TIDataArea.hbDumpFlag = 1;
        kernel_TIDataArea.hbNotVisibleFlag = 0;
    }
}
#endif // CONFIG_FSP_BUILD
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

#ifndef BOOTLOADER
#ifndef CONFIG_FSP_BUILD
        {
            termWriteDumpFlags(i_reasoncode);
        }
#endif
#endif
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


//  SPECIAL RESERVED RC_EARLY_BOOT_FAIL
//  openbmc/openpower-hw-diags/attn/ti_handler.cpp handleHbTi
//
//  See SW542371 as sample for surface symptoms, etc.
//
//  commit 561a8a1338a6dd7110c5203893c7fa1f70eee1dc
//
//  Reserve default SRC (BC801B99) to be used for TI discovery issues
//
//  There are some cases where the SP won't be able to read a valid
//  SRC from Hostboot's TI area.  For example, Hostboot could have
//  died horribly and been unable to modify memory, or there could
//  be issues reading mainstore itself.  This SRC will be used by
//  the attention handling code as a placeholder for any case where
//  a real SRC is not available.


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
