/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/pore/poreve/porevesrc/hookmanager.C $                 */
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
// $Id: hookmanager.C,v 1.15 2012/12/06 18:03:51 bcbrock Exp $

/// \file hookmanager.C
/// \brief A portable symbol table and hook execution facility

#include <stdio.h>
#include <string.h>

#include "hookmanager.H"

using namespace vsbe;
using namespace fapi;

#ifndef ULL
/// The printf() checker for 64-bit GCC throws a warning if a uint64_t is
/// printed as %llx - I have no idea why, but by casting them to (unsigned
/// long long) the warning goes away.
#define ULL(x) ((unsigned long long)(x))
#endif

fapi::ReturnCode vsbe::hookOk;

HookManager* HookManager::s_instance = 0;


////////////////////////////////////////////////////////////////////////////
// PoreAddressComparison
////////////////////////////////////////////////////////////////////////////

bool
PoreAddressComparison::operator()(PoreAddress const& i_lhs, 
                                  PoreAddress const& i_rhs) const
{
    return 
        (i_lhs.iv_memorySpace < i_rhs.iv_memorySpace) || 
        (i_lhs.iv_offset  < i_rhs.iv_offset);
}


////////////////////////////////////////////////////////////////////////////
// CharPointerComparison
////////////////////////////////////////////////////////////////////////////

bool
CharPointerComparison::operator()(char const* i_lhs, 
                                  char const* i_rhs) const
{
    return strcmp(i_lhs, i_rhs) < 0;
}


////////////////////////////////////////////////////////////////////////////
// HookManager
////////////////////////////////////////////////////////////////////////////

////////////////////////////// Creators //////////////////////////////

HookManager::HookManager() :
    iv_error(HOOK_OK)
{
}


HookManager::~HookManager()
{
}


///////////////////////////// Accessors //////////////////////////////

fapi::ReturnCode
HookManager::runInstructionHook(const PoreAddress& i_address,
                                const uint32_t i_hook,
                                const uint64_t i_parameter,
                                Pore& io_pore,
                                const fapi::Target& i_target)
{
    InstructionHookMap::iterator ihmi;
    fapi::ReturnCode rc;

    ihmi = instance()->iv_instructionHookMap.find(i_hook);
    if (ihmi == instance()->iv_instructionHookMap.end()) {
        rc = FAPI_RC_SUCCESS;
    } else {
        rc = (ihmi->second)(i_address, i_hook, i_parameter, io_pore, i_target);
    }
    return rc;
}


fapi::ReturnCode
HookManager::runReadHooks(const PoreAddress& i_address,
                          Pore& io_pore,
                          const fapi::Target& i_target)
                          
{
    return instance()->runHooks(HOOK_READ_INTERACTIVE, HOOK_READ_EXTRACTED,
                                i_address, io_pore, i_target);
}


fapi::ReturnCode
HookManager::runWriteHooks(const PoreAddress& i_address,
                           Pore& io_pore,
                           const fapi::Target& i_target)
{
    return instance()->runHooks(HOOK_WRITE_INTERACTIVE, HOOK_WRITE_EXTRACTED,
                                i_address, io_pore, i_target);
}


fapi::ReturnCode
HookManager::runFetchHooks(const PoreAddress& i_address,
                           Pore& io_pore,
                           const fapi::Target& i_target)
{
    return instance()->runHooks(HOOK_FETCH_INTERACTIVE, HOOK_FETCH_EXTRACTED,
                                i_address, io_pore, i_target);
}


HookError
HookManager::findGlobalSymbol(const char* i_symbol,
                              bool& o_found,
                              GlobalSymbolInfo& io_info)
{
    GlobalSymbolMap::iterator gsmi;

    o_found = false;
    if (!instance()->iv_error) {
        gsmi = instance()->iv_globalSymbolMap.find(i_symbol);
        if (gsmi != instance()->iv_globalSymbolMap.end()) {
            o_found = true;
            io_info = *(gsmi->second);
        }
    }
    return instance()->iv_error;
}


HookError
HookManager::globalSymbolList(GlobalSymbolList& io_symbols, const char* i_types)
{
    GlobalSymbolMap::iterator gsmi;

    if (!instance()->iv_error) {
        for (gsmi = instance()->iv_globalSymbolMap.begin();
             gsmi != instance()->iv_globalSymbolMap.end();
             gsmi++) {

            if ((i_types == 0) || 
                (strchr(i_types, gsmi->second->iv_type) != 0)) {
                io_symbols.push_back(*gsmi);
            }
        }
    }
    return instance()->iv_error;
}


void
HookManager::report(const int i_options)
{
    InstructionHookMap::iterator ihmi;
    HookedAddressMap::iterator hami;
    HookedFileMap::iterator hfmi;
    GlobalSymbolMap::iterator gsmi;
    Hook* hook;
    const HookTable* table;
    size_t entry;
    char type;
    ExtractedHook* exHook;
    
    if (i_options != 0) {

        FAPI_INF("");
        FAPI_INF("------------------------------------------------------");
        FAPI_INF("-- HookManager @ %p", instance());
        FAPI_INF("------------------------------------------------------");

        if (i_options & HM_REPORT_HOOKED_ADDRESS_MAP) {

            FAPI_INF("");
            FAPI_INF("--- Hooked Address Map : %zu unique addresses ---",
                     instance()->iv_hookedAddressMap.size());
            FAPI_INF("");

            for (hami = instance()->iv_hookedAddressMap.begin();
                 hami != instance()->iv_hookedAddressMap.end();
                 hami++) {

                for (hook = hami->second; hook != 0; hook = hook->iv_next) {
                    switch (hook->iv_type) {

                    case HOOK_READ_INTERACTIVE:
                    case HOOK_WRITE_INTERACTIVE:
                    case HOOK_FETCH_INTERACTIVE:
                        switch (hook->iv_type) {
                        case HOOK_READ_INTERACTIVE:  type = 'r'; break;
                        case HOOK_WRITE_INTERACTIVE: type = 'w'; break;
                        case HOOK_FETCH_INTERACTIVE: type = 'x'; break;
                        default: type = '?'; break; // For GCC -Wall
                        }
                        FAPI_INF("%04x:%08x %c %p", 
                                 hami->first.iv_memorySpace, 
                                 hami->first.iv_offset,
                                 type, hook->iv_hook);
                        break;

                    case HOOK_READ_EXTRACTED:
                    case HOOK_WRITE_EXTRACTED:
                    case HOOK_FETCH_EXTRACTED:
                        switch (hook->iv_type) {
                        case HOOK_READ_EXTRACTED:  type = 'r'; break;
                        case HOOK_WRITE_EXTRACTED: type = 'w'; break;
                        case HOOK_FETCH_EXTRACTED: type = 'x'; break;
                        default: type = '?'; break; // For GCC -Wall
                        }
                        exHook = (ExtractedHook*)(hook->iv_hook);
                        FAPI_INF("%04x:%08x %8zu %s", 
                                 hami->first.iv_memorySpace, hami->first.iv_offset,
                                 exHook->iv_index, exHook->iv_file);
                        break;

                    default: break; // For GCC -Wall
                    }
                }
            }
        }

        if (i_options & HM_REPORT_HOOK_TABLES) {

            FAPI_INF("");
            FAPI_INF("--- Hook Tables : %zu hooked files---",
                     instance()->iv_hookedFileMap.size());    

            for (hfmi = instance()->iv_hookedFileMap.begin();
                 hfmi != instance()->iv_hookedFileMap.end();
                 hfmi++) {

                FAPI_INF("");
                FAPI_INF("%s", hfmi->first);

                table = hfmi->second;
                for (entry = 0; entry < table->iv_entries; entry++) {
                    FAPI_INF("%8zu %p", 
                             entry, table->iv_hooks[entry]);
                }
            }
        }

        if (i_options & HM_REPORT_INSTRUCTION_HOOK_MAP) {

            FAPI_INF("");
            FAPI_INF("--- Instruction Hook Map ---");
            FAPI_INF("");

            for (ihmi = instance()->iv_instructionHookMap.begin();
                 ihmi != instance()->iv_instructionHookMap.end();
                 ihmi++) {

                FAPI_INF("%06x %p", 
                         ihmi->first, ihmi->second);
            }
        }

        if (i_options & HM_REPORT_GLOBAL_SYMBOL_MAP) {

            FAPI_INF("");
            FAPI_INF("--- Global Symbol Map ---");
            FAPI_INF("");

            for (gsmi = instance()->iv_globalSymbolMap.begin();
                 gsmi != instance()->iv_globalSymbolMap.end();
                 gsmi++) {

                FAPI_INF("%04x:%08x %c %s", 
                         gsmi->second->iv_address.iv_memorySpace, 
                         gsmi->second->iv_address.iv_offset,
                         gsmi->second->iv_type,
                         gsmi->first);
            }
        }

        FAPI_INF("");
        FAPI_INF("------------------------------------------------------");
        FAPI_INF("");
    }
}


//////////////////////////// Manipulators ////////////////////////////

HookError
HookManager::registerInstructionHook(const uint32_t i_index, 
                                     HookInstructionHook i_hookRoutine)
{
    InstructionHookMap::iterator ihmi;

    if (!instance()->iv_error) {

        ihmi = instance()->iv_instructionHookMap.find(i_index);
        if (ihmi == instance()->iv_instructionHookMap.end()) {

            instance()->iv_instructionHookMap[i_index] = i_hookRoutine;

        } else {
            if (ihmi->second != i_hookRoutine) {
                FAPI_ERR("%s : Static hook collision for index : %u",
                         __FUNCTION__, i_index);
                instance()->iv_error = HOOK_STATIC_COLLISION;
            }
        }
    }
    return instance()->iv_error;
}


HookError
HookManager::registerHookTable(const char* i_file, 
                               const HookTable* i_table)
{
    if (!instance()->iv_error) {

        if (instance()->iv_hookedFileMap.find(i_file) != 
            instance()->iv_hookedFileMap.end()) {

            FAPI_ERR("%s : File name collision : %s",
                     __FUNCTION__, i_file);
            instance()->iv_error = HOOK_FILE_NAME_COLLISION;
        } else {
            instance()->iv_hookedFileMap[i_file] = i_table;
        }
    }
    return instance()->iv_error;
}


HookError
HookManager::registerHook(const PoreAddress& i_address, 
                          Hook* io_hook)
{
    HookedAddressMap::iterator hami;
    Hook* hook;

    if (!instance()->iv_error) {

        hami = instance()->iv_hookedAddressMap.find(i_address);
        if (hami != instance()->iv_hookedAddressMap.end()) {
            for (hook = hami->second; 
                 hook->iv_next != 0; 
                 hook = hook->iv_next);
            hook->iv_next = io_hook;
        } else {
            instance()->iv_hookedAddressMap[i_address] = io_hook;
        }
        io_hook->iv_next = 0;
    }
    return instance()->iv_error;
}


HookError
HookManager::registerGlobalSymbol(const char* i_symbol, 
                                  const GlobalSymbolInfo* i_info)
{
    if (!instance()->iv_error) {

        if (instance()->iv_globalSymbolMap.find(i_symbol) != 
            instance()->iv_globalSymbolMap.end()) {

            FAPI_ERR("%s : Multiply defined symbol : %s",
                     __FUNCTION__, i_symbol);
            instance()->iv_error = HOOK_MULTIPLY_DEFINED_SYMBOL;
        } else {
            instance()->iv_globalSymbolMap[i_symbol] = i_info;
        }
    }
    return instance()->iv_error;
}


HookError
HookManager::addInteractiveHook(const PoreAddress& i_address,
                                const HookType i_type,
                                const AddressBasedHook i_hookRoutine)
{
    Hook* hook = new Hook();
    HookError rc;
    
    instance()->iv_error = HOOK_OK;
    if (hook == 0) {
        rc = HOOK_MEMORY_ALLOCATION_FAILED;
    } else {
        switch (i_type) {
        case HOOK_READ_INTERACTIVE:
        case HOOK_WRITE_INTERACTIVE:
        case HOOK_FETCH_INTERACTIVE:
            rc = HOOK_OK;
            hook->iv_type = i_type;
            hook->iv_hook = (void*)i_hookRoutine;
            registerHook(i_address, hook);
            break;
        default:
            delete hook;
            rc = HOOK_ILLEGAL_TYPE;
        }
    }
    instance()->iv_error = rc;
    return rc;
}


HookError
HookManager::deleteInteractiveHooks(const PoreAddress& i_address,
                                    const HookType i_type,
                                    const AddressBasedHook i_hookRoutine)
{
    HookedAddressMap::iterator hami;
    Hook **last, *hook, *next;
    HookError rc;
    bool deleted = false;
    
    switch (i_type) {
    case HOOK_READ_INTERACTIVE:
    case HOOK_WRITE_INTERACTIVE:
    case HOOK_FETCH_INTERACTIVE:
        
        hami = instance()->iv_hookedAddressMap.find(i_address);
        if (hami != instance()->iv_hookedAddressMap.end()) {
            for (last = &(hami->second), hook = hami->second; 
                 hook != 0;
                 hook = next) {
                next = hook->iv_next;
                if ((hook->iv_type == i_type) && 
                    ((i_hookRoutine == 0) || 
                     (hook->iv_hook) == i_hookRoutine)) {
                    delete hook;
                    deleted = true;
                    *last = next;
                } else {
                    last = &(hook->iv_next);
                }
            }
        }
        if ((i_hookRoutine == 0) || deleted) {
            if (hami->second == 0) {
                instance()->iv_hookedAddressMap.erase(hami);
            }
            rc = HOOK_OK;
        } else {
            rc = HOOK_INTERACTIVE_DELETE_FAILED;
        }
        break;

    default:
        rc = HOOK_ILLEGAL_TYPE;
    }
    instance()->iv_error = rc;
    return rc;
}


void
HookManager::clearError()
{
    instance()->iv_error = HOOK_OK;
}


////////////////////////// Implementation ////////////////////////////

// This routine checks to see if the i_address is mapped in the table, and if
// so, looks for a hook of the indicated type associated with that address.
// It is possible that the search may beningnly fail even though the address is
// mapped, e.g. we may be looking for a read hook but the hook mapped to the
// address is a write hook. We may want to consider a more efficient structure
// (multi-key map?) to avoid this.

fapi::ReturnCode
HookManager::runHooks(const HookType i_interactiveType,
                      const HookType i_extractedType,
                      const PoreAddress& i_address,
                      Pore& io_pore,
                      const fapi::Target& i_target)
{
    HookedAddressMap::iterator hami;
    Hook* hook;
    ExtractedHook *exHook;
    HookedFileMap::iterator hfmi;
    const HookTable* table;
    fapi::ReturnCode rc;

    hami = instance()->iv_hookedAddressMap.find(i_address);
    if (hami != instance()->iv_hookedAddressMap.end()) {

        for (hook = hami->second;
             (hook != 0) && rc.ok();
             hook = hook->iv_next) {

            if (hook->iv_type == i_interactiveType) {

                rc = ((AddressBasedHook)(hook->iv_hook))(i_address,
                                                         i_interactiveType,
                                                         io_pore,
                                                         i_target);

            } else if (hook->iv_type == i_extractedType) {

                exHook = (ExtractedHook*)(hook->iv_hook);
                hfmi = instance()->iv_hookedFileMap.find(exHook->iv_file);
                if (hfmi == instance()->iv_hookedFileMap.end()) {

                    FAPI_ERR("%s : Address %04x:%08x is hooked from "
                             "file '%s', but no HookTable can be found "
                             "for the file.",
                             __FUNCTION__, 
                             i_address.iv_memorySpace, 
                             i_address.iv_offset,
                             exHook->iv_file);
                    instance()->iv_error = HOOK_TABLE_MISSING;
                    FAPI_SET_HWP_ERROR(rc, RC_POREVE_HOOKMANAGER_INCONSISTENCY);

                } else {

                    table = hfmi->second;
                    if (exHook->iv_index > table->iv_entries) {

                        FAPI_ERR("%s : Address %04x:%08x is hooked from "
                                 "file '%s' at index %zu, "
                                 "but the index exceeds "
                                 "the number of hooks indexed for the "
                                 "file (%zu).",
                                 __FUNCTION__, 
                                 i_address.iv_memorySpace, 
                                 i_address.iv_offset,
                                 hfmi->first, exHook->iv_index,
                                 table->iv_entries);
                        instance()->iv_error = HOOK_INDEX_FAILURE;
                        FAPI_SET_HWP_ERROR(rc, 
                                            RC_POREVE_HOOKMANAGER_INCONSISTENCY);

                    } else {

                        rc = 
                            (table->iv_hooks[exHook->iv_index])
                            (i_address, i_extractedType, io_pore, i_target);
                    }
                }
            }
            if (!rc.ok()) break;
        }
    }
    return rc;
}
                      

////////////////////////////////////////////////////////////////////////////
// HookInitializer
////////////////////////////////////////////////////////////////////////////

HookInitializer::HookInitializer(HookManagerInitializer i_function)
{
    i_function();
}


HookInitializer::~HookInitializer()
{
}

