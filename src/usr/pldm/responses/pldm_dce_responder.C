/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/pldm/responses/pldm_dce_responder.C $                 */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2021,2022                        */
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

/* @file  pldm_dce_responder.C
 *
 * @brief Contains definitions for Hostboot's Dynamic Code Exceution (DCE)
 * facilities. See src/build/tools/dce/README.md for details.
 */

// PLDM
#include <pldm/pldm_response.H> // send_cc_only_response
#include <pldm/requests/pldm_fileio_requests.H>
#include <pldm/responses/pldm_monitor_control_responders.H>

// DCE (Dynamic Code Execution)
#include <secureboot/service.H>
#include <console/consoleif.H>
#include <kernel/console.H>
#include <sys/mm.h>
#include <arch/ppc.H>
#include <sys/task.h>


using namespace ERRORLOG;
using namespace TARGETING;

namespace PLDM
{

// DCE isn't supported at runtime yet.
#ifndef __HOSTBOOT_RUNTIME

namespace DCE
{

// These constants must match with the DCE preplib.py tool
// Search for @DEP_ON_BL_TO_HB_SIZE
const uint64_t RELOC_TYPE_DESCRIPTOR = 1;
const uint64_t RELOC_TYPE_ADDR64 = 2;

/* @brief Each relocation has three elements, a type, offset, and value.
 */
struct reloc
{
    uint64_t reloc_type;
    uint64_t reloc_offset;
    uint64_t reloc_value;
};

/* @brief The description of the beginning of the code LID file.
 */
struct lid_header
{
    uint64_t entrypoint_offset;
    uint64_t toc_offset;
    uint64_t env_offset;

    uint64_t num_relocs;
    reloc relocs[1];

    // data follows
} PACKED;

/* @brief Description of a 64-bit PowerPC function descriptor.
 */
struct ppc_function_thunk_t
{
    uint64_t nip;
    uint64_t toc;
    uint64_t env;
} PACKED;

/* @brief Perform dynamic ELF relocations.
 *
 * @param[in] header  Pointer to the LID data.
 * @return            Pointer to the beginning of the ELF.
 */
uint8_t* perform_relocs(lid_header* const header)
{
    const uint64_t num_relocs = header->num_relocs;
    reloc* const relocs = header->relocs;

    uint8_t* const data = reinterpret_cast<uint8_t*>(&relocs[num_relocs]);

    for (uint64_t i = 0; i < num_relocs; ++i)
    {
        uint8_t* const dest_addr = data + relocs[i].reloc_offset;
        uint8_t* const src = data + relocs[i].reloc_value;

        switch (relocs[i].reloc_type)
        {
        case RELOC_TYPE_DESCRIPTOR:
            CONSOLE::displayf(CONSOLE::DEFAULT, NULL, "DCE: Performing descriptor relocation at %p from %p",
                              dest_addr,
                              src);

            memcpy(dest_addr, src, sizeof(ppc_function_thunk_t));
            break;
        case RELOC_TYPE_ADDR64:
            CONSOLE::displayf(CONSOLE::DEFAULT, NULL, "DCE: Performing addr64 relocation at %p from %p",
                              dest_addr,
                              src);

            *reinterpret_cast<uint8_t**>(dest_addr) = src;
            break;
        default:
            CONSOLE::displayf(CONSOLE::DEFAULT, NULL, "DCE: UNKNOWN RELOCATION TYPE %d", relocs[i].reloc_type);
            break;
        }
    }

    return data;
}

/* @brief The task that actually calls into the DCE binary.
 *
 * @param[in] func_ptr  The function to call.
 * @return              Nullptr.
 */
void* dce_execute_task(void* func_ptr)
{
    CONSOLE::displayf(CONSOLE::DEFAULT, NULL, " > DCE task: Invoking function");

    const auto ret = reinterpret_cast<uint64_t(*)()>(func_ptr)();

    CONSOLE::displayf(CONSOLE::DEFAULT, NULL, " > DCE task: function returned %d", ret);

    return nullptr;
}

/* @brief Search for a string in another string.
 *
 * @param[in] needle     The string to search for
 * @param[in] haystack   The string to search in
 * @return               Pointer to occurrence of needle in haystack, or nullptr.
 */
static const char* strstr(const char* const needle, const char* haystack)
{
    auto needle_len = strlen(needle);

    while (*haystack)
    {
        if (strncmp(needle, haystack, needle_len) == 0)
        {
            return haystack;
        }

        ++haystack;
    }

    return nullptr;
}

/* @brief Print the most recent task crash data from the kernel's printk buffer.
 */
void print_last_printk_crash()
{
    const char* last_exception = nullptr, * exception = kernel_printk_buffer;

    while ((exception = strstr("exception", exception + 1)))
    {
        last_exception = exception;
    }

    if (last_exception)
    {
        CONSOLE::displayf(CONSOLE::DEFAULT, NULL, "%s", last_exception);
    }
}

/* @brief Task function to handle a DCE request.
 */
void* handleInvokeDceRequest_task(void*)
{
    const uint32_t DCE_LID_NUMBER = 0xdcec0de;

    CONSOLE::displayf(CONSOLE::DEFAULT, NULL, "DCE: Fetching code...");

    task_detach();

    std::vector<uint8_t> lid_contents(PAGE_SIZE);

    errlHndl_t errl = nullptr;

    do
    {

    /* Read the entire DCE LID from the BMC */

    uint32_t offset = 0;

    while (true)
    {
        uint32_t bytes_read = 4096;

        CONSOLE::displayf(CONSOLE::DEFAULT, NULL, " - DCE: Fetching %d bytes at offset %d", bytes_read, offset);

        errl = getLidFileFromOffset(DCE_LID_NUMBER,
                                    offset,
                                    bytes_read,
                                    lid_contents.data() + offset);

        if (errl)
        {
            CONSOLE::displayf(CONSOLE::DEFAULT, NULL,
                              "DCE: Failed to read LID from BMC: "
                              TRACE_ERR_FMT,
                              TRACE_ERR_ARGS(errl));
            break;
        }

        offset += bytes_read;

        if (bytes_read < PAGE_SIZE)
        {
            break;
        }

        lid_contents.resize(lid_contents.size() + PAGE_SIZE); // allocate space for another page
    }

    if (errl)
    {
        break;
    }

    /* Set it up to call */

    CONSOLE::displayf(CONSOLE::DEFAULT, NULL, "   - DCE: Finished reading code, got %d bytes", offset);

    const auto header = reinterpret_cast<lid_header*>(lid_contents.data());

    CONSOLE::displayf(CONSOLE::DEFAULT, NULL, " - DCE: Performing relocations");

    uint8_t* const elf = perform_relocs(header);

    CONSOLE::displayf(CONSOLE::DEFAULT, NULL, " - DCE: Setting code permissions");

    mm_set_permission(lid_contents.data(), lid_contents.size(), EXECUTABLE);

    CONSOLE::displayf(CONSOLE::DEFAULT, NULL, " - DCE: Flushing data cache");

    mm_icache_invalidate(lid_contents.data(), lid_contents.size() / 8);

    CONSOLE::displayf(CONSOLE::DEFAULT, NULL, "   - DCE: Done flushing");

    const uint64_t physaddr = mm_virt_to_phys(lid_contents.data());

    CONSOLE::displayf(CONSOLE::DEFAULT, NULL, " - DCE: Phys addr is %p", physaddr);

    // Create a fake function descriptor that we can call through a function pointer.
    ppc_function_thunk_t func_ptr =
    {
        .nip = (uint64_t)(elf + header->entrypoint_offset),
        .toc = (uint64_t)(elf + header->toc_offset),
        .env = (uint64_t)(elf + header->env_offset),
    };

    CONSOLE::displayf(CONSOLE::DEFAULT, NULL, " - DCE: Invoking code (.data() = %p, nip = %p, toc = %p, stackaddr = %p, elf = %p)",
                      lid_contents.data(), func_ptr.nip, func_ptr.toc, &func_ptr, elf);

    // Create a new task so that if the DCE code crashes, we can continue.
    const auto tid = task_create(dce_execute_task, &func_ptr);

    int status = 0;
    task_wait_tid(tid, &status, nullptr);

    if (status == TASK_STATUS_EXITED_CLEAN)
    {
        CONSOLE::displayf(CONSOLE::DEFAULT, NULL, " - DCE: Code finished");
    }
    else
    {
        CONSOLE::displayf(CONSOLE::DEFAULT, NULL, " - DCE: Code crashed! Latest exception from printk buffer:");

        print_last_printk_crash();
    }

    CONSOLE::displayf(CONSOLE::DEFAULT, NULL, " - DCE: Setting permissions back to WRITABLE");

    mm_set_permission(lid_contents.data(), lid_contents.size(), WRITABLE);

    CONSOLE::displayf(CONSOLE::DEFAULT, NULL, "DCE: Finished");

    } while (0);

    delete errl;
    errl = nullptr;

    return nullptr;
}

}

#endif

errlHndl_t handleInvokeDceRequest(const state_effecter_callback_args& i_args)
{
    CONSOLE::displayf(CONSOLE::DEFAULT, NULL, "DCE: Responding to PLDM request");
    send_cc_only_response(i_args.i_msgQ, i_args.i_msg, PLDM_SUCCESS);

#ifndef __HOSTBOOT_RUNTIME
    if (SECUREBOOT::enabled() == false)
    { // DCE should not be enabled in secure mode.
        // Create a task so that we don't block the whole PLDM stack.
        task_create(DCE::handleInvokeDceRequest_task, nullptr);
    }
#endif

    return nullptr;
}

}
