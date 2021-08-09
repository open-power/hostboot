/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/runtime/rt_main.C $                                       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2021                        */
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

/**
 * @file rt_main.C
 * @brief Entry point for HBRT initialization
 */

#include <builtins.h>
#include <limits.h>
#include <runtime/interface.h>
#include <util/singleton.H>
#include <stdio.h>
#include <util/align.H>

// Address of the first writable page, initialized by the linker.
extern void* data_load_address;
// Forward declaration to vfs code.
void vfs_module_init();

// Version string
extern char hbi_ImageId;


/** @fn _main
 *
 *  @brief Entry point called from Sapphire to initialize RT image.
 *
 *  @param[in] intf - Runtime interfaces structure from Sapphire.
 *  @param[in] base - Memory address of the start of the RT image.
 *
 *  @return - runtimeInterfaces_t* - Pointer to RT image's interfaces.
 *
 *  This function is required to be in the .text.intvects section so that
 *  it is placed into the first page (4k) of the image.  When HB IPL
 *  loads the RT image for CxxTest execution it will only mark the first
 *  page executable.  The remainder is marked execute via callbacks from
 *  within _main.
 */
extern "C"
{
    runtimeInterfaces_t* _main(hostInterfaces_t*, uint64_t base)
        SYMB_SECTION(".text.intvects");
}

/** @fn rt_start
 *
 *  @brief Remainder of RT image initializion.
 *
 *  After _main marks pages executable we can leave the first page of the
 *  image.  This function performs the bulk of the initialization:
 *
 *      1) Call C++ constructors for this image.
 *      2) Load all modules in the image.
 *
 *  @param[in] intf - Runtime interfaces structure from Sapphire.
 */
runtimeInterfaces_t* rt_start(hostInterfaces_t*) NEVER_INLINE;


/** @fn rt_version_fixup
 *
 *  @brief Make any adjustments needed to handle old versions
 */
void rt_version_fixup( void )
{
    uint64_t hostver = g_hostInterfaces->interfaceVersion;
    if( HOSTBOOT_RUNTIME_INTERFACE_VERSION == hostver )
    {
        return; //nothing to do, we match
    }

    char verstring[100];
    sprintf( verstring,
             "HRBT Ver=%X, HostVer=%X\n",
             HOSTBOOT_RUNTIME_INTERFACE_VERSION,
             hostver );
    (g_hostInterfaces->puts)(verstring);
}

/** Call C++ constructors present in this image. */
void rt_cppBootstrap();

runtimeInterfaces_t* _main(hostInterfaces_t* intf, uint64_t base)
{
    // Ensure remainder of image has text pages marked execute.
    for (uint64_t i = base;
         i < ALIGN_PAGE_DOWN((uint64_t)&data_load_address);
         i += PAGESIZE)
    {
        if (NULL != intf->set_page_execute)
        {
            (intf->set_page_execute)(reinterpret_cast<void*>(i));
        }
    }

    // Tail-recurse to real entry point.
    return rt_start(intf);
}

runtimeInterfaces_t* rt_start(hostInterfaces_t* intf)
{
    (intf->puts)("Starting Hostboot Runtime Services....\n");
    (intf->puts)(&hbi_ImageId);
    (intf->puts)("\n");

    // Save a pointer to interfaces from Sapphire.
    g_hostInterfaces = intf;

    // Call C++ constructors.
    rt_cppBootstrap();

    // Initialize runtime interfaces.
    runtimeInterfaces_t* rtInterfaces = getRuntimeInterfaces();
    rtInterfaces->interfaceVersion = HOSTBOOT_RUNTIME_INTERFACE_VERSION;

    // Initialize all modules.
    vfs_module_init();

    // Call rtPost functions
    postInitCalls_t* rtPost = getPostInitCalls();

    // Call InitRsvdTraceBufService
    // NOTE: This function has pre-req of vfs_module_init() for using
    //   hb_get_rt_rsvd_mem(). Due to pre-req of rtPost->callInitErrlManager()
    //   committing ERRL is moved to callCommitRsvdTraceBufErrl().
    rtPost->callInitRsvdTraceBufService();

    // apply temp overrides
    rtPost->callApplyTempOverrides();

#ifdef CONFIG_MCTP
    // initialize MCTP
    rtPost->callInitMctp();
#endif

#ifdef CONFIG_PLDM
    // initialize PLDM
    rtPost->callInitPldm();
#endif

#ifdef CONFIG_FILE_XFER_VIA_PLDM
    // We only support PNOR access if PLDM PNOR IO is available
    rtPost->callInitPnor();
#endif

    // Make sure errlmanager is ready
    rtPost->callInitErrlManager();

    // Call commitRsvdTraceBufErrl
    // NOTE: This function has pre-req of rtPost->callInitErrlManager()
    //   for committing ERRL, which was created in InitRsvdTraceBufService().
    rtPost->callCommitRsvdTraceBufErrl();

    // check for possible missed in-flight messages/interrupts
    rtPost->callClearPendingSbeMsgs();

    // callLoadAndStartPMComplex is no-op on OPAL systems
    rtPost->callLoadAndStartPMComplex();

    // check for possible missed in-flight messages/interrupts
    if (rtPost->callClearPendingOccMsgs != nullptr )
    {
        // vector ptr has been initted, use it
        rtPost->callClearPendingOccMsgs();
    }
    else
    {
        // (HTMGT not compiled in by default)
    }

    // do any version mismatch fixups
    rt_version_fixup();

    (intf->puts)("rt_start complete....\n");

    // Return our interface pointer structure.
    return rtInterfaces;
}

void rt_cppBootstrap()
{
    // Call default constructors for any static objects.
    extern void (*ctor_start_address)();
    extern void (*ctor_end_address)();
    void(**ctors)() = &ctor_start_address;
    while(ctors != &ctor_end_address)
    {
        (*ctors)();
        ctors++;
    }
}

hostInterfaces_t* g_hostInterfaces = NULL;

runtimeInterfaces_t* getRuntimeInterfaces()
{
    return &Singleton<runtimeInterfaces_t>::instance();
}

postInitCalls_t* getPostInitCalls()
{
    return &Singleton<postInitCalls_t>::instance();
}

