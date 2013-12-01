/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/pore/poreve/porevesrc/hookmanager.H $                 */
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
#ifndef __VSBE_HOOKMANAGER_H
#define __VSBE_HOOKMANAGER_H

// $Id: hookmanager.H,v 1.17 2013/02/05 16:14:38 bcbrock Exp $

/// \file hookmanager.H
/// \brief A portable symbol table and hook execution facility
///
/// Although the concept of a HookManager is generic, this implementation is
/// specific to the FAPI PoreVe environment.
///
/// A hook is a C/C++ subroutine called during execution of the PoreVe.  A
/// hook is either associated with a HOOKI instruction, or with a particular
/// PORE effective address.  Address-based hooks are either read, write or
/// fetch hooks, and may have either been installed interactively (e.g., by a
/// debugger or hand-written code) or extracted from a source file.  We make a
/// distinction because extracted hooks are indexed via static tables created
/// by processing an assembler source file, whereas interactive hooks are
/// inserted individually.  Extracted hooks are assumed to be characterized by
/// permanent static data structures and can not be deleted.  Interactive
/// hooks can be created and deleted at will.
///
/// \todo Once the HBI use of the HookManager is finalized, it may be
/// necessary to split this into 2 classes, one for HBI and another for Cronus
/// verisons of PoreVe.
///
/// \todo Figure out if there is a way to make this more generic without having
/// to use a template.

#include <stdarg.h>
#include <stdint.h>

#include <list>
#include <map>
#include <utility>
#include <vector>

#include <fapi.H>

#include "poremodel.H"

namespace vsbe {

    struct HookTable;
    struct ExtractedHook;
    struct Hook;
    struct GlobalSymbolInfo;
    class HookManager;
    class HookInitializer;
    class PoreAddress;
    class PoreAddressComparison;
    class CharPointerComparison;
    class Pore;

    /// An "OK" return code for use by hook routines
    extern fapi::ReturnCode hookOk;

    /// \enum HookType
    ///
    /// The type of a hook. See the comments for the file hookmanager.H.
    enum HookType {
        HOOK_INSTRUCTION,
        HOOK_READ_INTERACTIVE,
        HOOK_WRITE_INTERACTIVE,
        HOOK_FETCH_INTERACTIVE,
        HOOK_READ_EXTRACTED,
        HOOK_WRITE_EXTRACTED,
        HOOK_FETCH_EXTRACTED
    };

    /// The type of a HOOK instruction hook
    ///
    /// \param[in] i_address The effective address of the HOOK instruction
    ///
    /// \param[in] i_hook The low-order 24 bits of the HOOK instruction
    ///
    /// \param[in] i_Parameter A 64-bit parameter for the hook
    ///
    /// \param[in,out] io_pore The Pore model, to allow the hook to examine or
    /// modify the state of the PORE.
    ///
    /// \param[in] i_target A reference to the FAPI Target currently
    /// associated with the virtual PORE.
    typedef fapi::ReturnCode 
    (*HookInstructionHook)(const PoreAddress& i_address,
                           const uint32_t i_hook,
                           const uint64_t i_parameter,
                           Pore& io_pore,
                           const fapi::Target& i_target);

    /// The type of an address-based hook
    ///
    /// \param[in] i_address The effective address associated with the hook
    ///
    /// \param[in] i_type The type of the address-based hook
    ///
    /// \param[in,out] io_pore A reference to the Pore model, to allow the
    /// hook to examine or modify the state of the PORE.
    ///
    /// \param[in] i_target A reference to the FAPI Target currently
    /// associated with the virtual PORE.
    typedef fapi::ReturnCode 
    (*AddressBasedHook)(const PoreAddress& i_address,
                        const HookType i_type,
                        Pore& io_pore,
                        const fapi::Target& i_target);

    /// \enum HookError
    ///
    /// These error conditions are recognized both while the hook manager is
    /// being initialized, and at run time.  The last error code generated is
    /// stored in the iv_error field of the HookManager.
    enum HookError {
        HOOK_OK = 0,
        /// File name collision between hooked files
        HOOK_FILE_NAME_COLLISION = 1,
        /// Multiply defined symbol
        HOOK_MULTIPLY_DEFINED_SYMBOL = 2,
        /// A HookTable for a file is missing, suggesting hooks are out of
        /// sync with the hooked sources
        HOOK_TABLE_MISSING = 3,
        /// Hook index too large, suggesting hooks are out of sync with the
        /// hooked sources
        HOOK_INDEX_FAILURE = 4,
        /// An attempt was made to map more than one hook to a static hook
        /// index. 
        HOOK_STATIC_COLLISION = 5,
        /// Deprecated: An instruction hook was called for but not found
        HOOK_INSTRUCTION_NOT_FOUND = 6,
        /// An illegal HookType was specified for an API
        HOOK_ILLEGAL_TYPE = 7,
        /// Memory allocation failure for a new interactive hook
        HOOK_MEMORY_ALLOCATION_FAILED = 8,
        /// A request to delete a specific interactive hook failed
        HOOK_INTERACTIVE_DELETE_FAILED = 9,
        /// There is a bug in the HookManager
        HOOK_BUG = 10,
    };

    /// \defgroup hookmanager_report_options HookManager Report Options
    ///
    /// By default, the HookManager::report() method prints all elements of
    /// the report. An OR-combination of these flags can also be supplied as
    /// the argument to explicitly specify that individual sections of the
    /// report be printed.
    /// 
    /// @{

    /// Print the hooked address map
    const int HM_REPORT_HOOKED_ADDRESS_MAP = 0x1;

    /// Print the hook tables
    const int HM_REPORT_HOOK_TABLES = 0x2;

    /// Print the instruction hook map
    const int HM_REPORT_INSTRUCTION_HOOK_MAP = 0x4;

    /// Print the global symbol map
    const int HM_REPORT_GLOBAL_SYMBOL_MAP = 0x8;

    /// @}
};


////////////////////////////////////////////////////////////////////////////
// HookTable
////////////////////////////////////////////////////////////////////////////

/// A table of AddressBasedHook function pointers associated with a source
/// file.
///
/// These structures are created by the \e hook_extractor script as it
/// processes the input to the assembler.  Therefore the size of the \a
/// iv_hooks table is constant and known at compile time.  To save space the
/// name of the file is not included here - instead the file name is the map
/// key.

struct 
vsbe::HookTable {

    /// The number of hooks defined for the file
    size_t iv_entries;

    /// The table of addresses of the hook routines
    AddressBasedHook *iv_hooks;
};
    

////////////////////////////////////////////////////////////////////////////
// ExtractedHook
////////////////////////////////////////////////////////////////////////////

/// An index record for a hook extracted from a source file

struct
vsbe::ExtractedHook {

    /// The file name of the hooked source file
    const char* iv_file;

    /// The index of the hook within the file
    size_t iv_index;
};


////////////////////////////////////////////////////////////////////////////
// Hook
////////////////////////////////////////////////////////////////////////////

/// A reference to a hook associated with a particular PORE address
///
/// The hook architecture allows multiple hooks to be associated with a single
/// address. This situation could arise both by design and also by accident
/// depending for example on conditional compilation or macro expansion.  To
/// support all of read, write and fetch hooks as well as static
/// initialization of extracted hooks, this structure holds a generic hook
/// pointer and a \a type field that indicates whether to interpret the
/// pointer as a pointer to an ExtractedHook, or a direct pointer to an
/// AddressBasedHook. 

struct 
vsbe::Hook {

    /// The type of hook; See the enumeration HookType
    HookType iv_type;

    /// Either an AddressBasedHook or a pointer to an ExtractedHook, depending
    /// on the HookType
    void* iv_hook;

    /// List linkage
    struct Hook* iv_next;
};


////////////////////////////////////////////////////////////////////////////
// GlobalSymbolInfo
////////////////////////////////////////////////////////////////////////////

/// Global Symbol Information
///
/// Global symbols are mapped by name.  This structure includes the symbol
/// address as a PoreAddress plus type information.

struct 
vsbe::GlobalSymbolInfo {

    /// The symbol address
    PoreAddress iv_address;

    /// The symbol type
    ///
    /// Symbol types are the character codes reported by \e nm:
    ///
    /// - \c B Global BSS (uninitialized data)
    /// - \c C Global common (uninitialized data)
    /// - \c D Global initialized data
    /// - \c T Global text (code)
    /// - \c R Global read only data
    char iv_type;
};


namespace vsbe {
    /// An STL list of <const char *, const GlobalSymbolInfo*> pairs
    ///
    /// This structure is defined for use in calls to
    /// HookManager::globalSymbolList().
    typedef std::list< std::pair<const char*, const GlobalSymbolInfo*> > 
    GlobalSymbolList;
}


////////////////////////////////////////////////////////////////////////////
// PoreAddressComparison
////////////////////////////////////////////////////////////////////////////

/// PoreAddress comparison class
///
/// This class defines the comparison operator for STL containers using a
/// PoreAddress as the key.  

class
vsbe::PoreAddressComparison {

public:

    PoreAddressComparison() {}

    ~PoreAddressComparison() {}

    /// Compare PoreAddress*
    ///
    /// \param[in] i_lhs Left hand side object
    ///
    /// \param[in] i_rhs Right hand side object
    ///
    /// \retval rc This is a simple lexicographic order on the segment and
    /// offset.
    bool operator() (PoreAddress const& i_lhs,
                     PoreAddress const& i_rhs) const; 


    ///////////////////////////// Safety //////////////////////////////////

private:
    // STL requires a copy operator
    PoreAddressComparison& operator=(const PoreAddressComparison& rhs);
};


////////////////////////////////////////////////////////////////////////////
// CharPointerComparison
////////////////////////////////////////////////////////////////////////////

/// char* comparison class
///
/// This class defines the comparison operator for STL containers using a
/// char* as the key.  

class
vsbe::CharPointerComparison {

public:

    CharPointerComparison() {}

    ~CharPointerComparison() {}

    /// Compare CharPointer*
    ///
    /// \param[in] i_lhs Left hand side object
    ///
    /// \param[in] i_rhs Right hand side object
    ///
    /// \retval rc This is a simply strcmp(ilhs, irhs) < 0
    bool operator() (char const* i_lhs,
                     char const* i_rhs) const; 


    ///////////////////////////// Safety //////////////////////////////////

private:
    // STL requires a copy operator
    CharPointerComparison& operator=(const CharPointerComparison& rhs);
};


////////////////////////////////////////////////////////////////////////////
// HookManager
////////////////////////////////////////////////////////////////////////////

/// A singleton class for managing code hooks for PORE VE
///
/// The hook manager is a portable C++ implementation of a symbol table for
/// hook functions, hooked instructions and global symbols.  Only one
/// HookManager exists at any time.  All methods are static and internally
/// reference a singleton instance of a HookManager.  The HookManager supports
/// two main types of hooks:
///
/// - Pre-defined hooks associated with the PORE HOOKI instruction.  The HOOKI
/// instruction encodes an unsigned integer index of a hook routine to execute
/// at that point, and also includes an uninterpreted 64-bit parameter. The
/// mapping of hook indices to hook routines will likely be done
/// statically. The HOOK instruction is otherwise a NOP.
///
/// - Address-based hooks are hooks that are attached to data loads and stores
/// or instruction fetches.  These hooks are normally attached by a scripting
/// discipline that processes the input of the assembler to extract the hooks
/// into a separate build and load path.  Debugging environments can also add
/// and delete hooks at run time.
///
/// The symbol table architecure and layout were designed to simplify the
/// mapping and reduce space for the case that hooks are required during a
/// space-constrained HBI procedure.  Most symbol table data are defined as
/// constants in the shared objects that initialize the hooks, and should
/// never need to be copied.
///
/// The HookManager maintains 4 maps:
///
/// - A map that maps predefined hook indices encoded in HOOKI instructions to
/// the routines that implement the hook.  This map is created by calls of
/// registerInstructionHook().
///
/// - A map that maps a source file name to a HookTable, that is table of
/// function pointers to the routines that implement the hooks. This map is
/// created by calls of registerHookTable().
///
/// - A map that maps a 48-bit \e effective PORE address to a list of Hook
/// objects that identify the hook(s) associated with a PORE address. This map
/// is created by calls of registerHook().
///
/// - A map that maps a PORE global symbol name to a pair <address, type>.
/// This map is created by calls of registerGlobalSymbol().

class 
vsbe::HookManager {

public:
    
    //////////////////////////////   Types  //////////////////////////////

    /// A map of HOOKI instruction indices to a HookInstructionHook
    ///
    /// This map is created by calls of registerInstructionHook().  The
    /// application that provides the semantics of each HOOKI instruction
    /// index will make these calls.  The map is used by the
    /// runInstructionHook() API to locate the entry point associated with a
    /// HOOKI index.
    typedef std::map<uint32_t, HookInstructionHook> InstructionHookMap;

    /// A map of file names to hook routine tables
    ///
    /// This mapping is created by the *.hook.cc file that is generated by the
    /// hook_extractor script for each file of assembler source code.  Each
    /// one of the *.hook.cc files maps the source code file name to a table
    /// of entry points of the hooks extracted from that file.  The
    /// hook_indexer script references these tables to map hooked PORE
    /// addresses to the entry point that implements the hook.
    typedef std::map<const char*, const HookTable*> HookedFileMap;

    /// A map of PORE addresses to lists of hooks
    ///
    /// This map is created by the registerHook() API.  For extracted hooks,
    /// these calls are made from the *.hooks.cc file created by the
    /// hook_indexer from the symbol table of the final link image.  The
    /// registerHook() API can also be called dynamically by advanced
    /// applications like the PDBG debugger for PORE programs.  This map is
    /// referenced by the runHooks() API.
    ///
    /// \note The comparison operator being used here is '<' on the uint64_t
    /// form of the PoreAddress.
    typedef std::map<const PoreAddress, Hook*> HookedAddressMap;

    /// A map of global symbol names to their parameters
    ///
    /// This map is created by calls of registerGlobalSymbol(), called from
    /// the *.hooks.cc file created by the hook_indexer script.  This mapping
    /// allows the allows the application to find global symbol addresses
    /// using the findGlobalSymbol() API.
    typedef std::map<const char*, const GlobalSymbolInfo*,
                     CharPointerComparison> GlobalSymbolMap;

    ////////////////////////////// Creators //////////////////////////////

    HookManager();

    virtual ~HookManager();

    /// Delete the singleton instance of the HookManager
    ///
    /// This method is required to support the case that multiple runs of the
    /// PoreVe with different hooks need to be made in the same process. Along
    /// with destroying the HookManager object, all hook DLLs will also need
    /// to be unloaded to ensure that another run of the PoreVe will
    /// succeed. The application can use the HookManager::dlopen() API rather
    /// than the standard dlopen() to allow the HookManager to take care
    /// of unloading the DLLs when the HookManager is destroyed.
    static void destroy() {
        if (s_instance != 0) {
            delete s_instance;
            s_instance = 0;
        }
    }


    ///////////////////////////// Accessors //////////////////////////////

    /// Access the singleton instance
    ///
    /// This is a standard design pattern: If the static singleton instance of
    /// the class already exists, return it.  Otherwise create it first.
    static HookManager* instance() {
        if (s_instance == 0) {
            s_instance = new HookManager();
        }
        return s_instance;
    }

    /// Run a hook assigned to a HOOKI instruction encoding
    ///
    /// \param[in] i_address The effective address of the HOOKI instruction.
    ///
    /// \param[in] i_hook The index of the hook to run, taken from the
    /// low-order 24 bits of the HOOKI instruction.
    ///
    /// \param[in] i_parameter A 64-bit parameter for the hook.
    ///
    /// \param[in,out] io_pore A reference to the Pore object, to allow hooks
    /// to examine or alter the PORE state.
    ///
    /// \param[in] i_target A reference to the FAPI Target currently
    /// associated with the virtual PORE.
    ///
    /// \retval rc If there is a hook routine associated with the hook index
    /// \a i_hook, then this is the FAPI return code returned by the hook,
    /// otherwise an "ok" (0) FAPI return code.  There is no requirememt that
    /// a hook routine be present in the Hookmanager for any instruction hook
    /// index.
    static fapi::ReturnCode
    runInstructionHook(const PoreAddress& i_address,
                       const uint32_t i_hook, 
                       const uint64_t i_parameter,
                       Pore& io_pore,
                       const fapi::Target& i_target);

    /// Run any hooks associated with a data read of an effective address
    ///
    /// \param[in] i_address The effective address of the data read
    ///
    /// \param[in,out] io_pore A reference to the Pore object, to allow hooks
    /// to examine or alter the PORE state.
    ///
    /// \param[in] i_target A reference to the FAPI Target currently
    /// associated with the virtual PORE.
    ///
    /// If supported by the environment this method will be called before
    /// every data read to run any hooks associated with reading the address.
    ///
    /// \retval rc The FAPI return code returned by the first (if any)
    /// hook routine to return a non-OK code, otherwise an OK return code.
    static fapi::ReturnCode
    runReadHooks(const PoreAddress& i_address, 
                 Pore& io_pore,
                 const fapi::Target& i_target);
    
    /// Run any hooks associated with a data write of an effective address
    ///
    /// \param[in] i_address The effective address of the data write
    ///
    /// \param[in,out] io_pore A pointer to the Pore object, to allow hooks to
    /// examine or alter the PORE state.
    ///
    /// \param[in] i_target A reference to the FAPI Target currently
    /// associated with the virtual PORE.
    ///
    /// \retval rc The FAPI return code returned by the first (if any)
    /// hook routine to return a non-OK code, otherwise an OK return code.
    static fapi::ReturnCode
    runWriteHooks(const PoreAddress& i_address, 
                  Pore& io_pore,
                  const fapi::Target& i_target);
    
    /// Run any hooks associated with an instruction fetch of an effective
    /// address
    ///
    /// \param[in] i_address The effective address of the instruction fetch
    ///
    /// \param[in,out] io_pore A pointer to the Pore object, to allow hooks to
    /// examine or alter the PORE state.
    ///
    /// \param[in] i_target A reference to the FAPI Target currently
    /// associated with the virtual PORE.
    ///
    /// If supported by the environment this method will be called before
    /// every instruction fetch to run any hooks associated with executing the
    /// address.
    ///
    /// \retval rc The FAPI return code returned by the first (if any)
    /// hook routine to return a non-OK code, otherwise an OK return code.
    static fapi::ReturnCode
    runFetchHooks(const PoreAddress& i_address, 
                  Pore& io_pore,
                  const fapi::Target& i_target);

    /// Find a global symbol in the HookManager symbol table
    ///
    /// \param[in] i_symbol The global symbol name to search for
    ///
    /// \param[out] o_found Indicates whether the symbol was found
    ///
    /// \param[in,out] io_info If the symbol is was found, this
    /// reference is modified to contain the symbol information, otherwise the
    /// reference is not modified.
    ///
    /// \retval rc HookManager sticky error status; This method fails
    /// immediately if HookManager error status is set at entry.  To clear the
    /// error status use clearError().
    static HookError
    findGlobalSymbol(const char* i_symbol, 
                     bool& o_found, 
                     GlobalSymbolInfo& io_info);

    /// Update a list of GlobalSymbolInfo based on the current state
    ///
    /// \param[in,out] io_symbols This is a reference to an instance of
    /// GlobalSymbolList, an STL list of <const char*, const GlobalSymbolInfo*>
    /// pairs.
    ///
    /// \param[in] i_types This optional parameter is a 0-terminated character
    /// string containing 0 or more character codes of symbol types.  Only
    /// symbols whose type code is an element of the string are appended to \a
    /// io_symbols. If \a i_types is 0 (or defaulted) then all global symbols
    /// are returned. It probably doesn't make sense to call
    /// globalSymbolList() with \a i_types as "" since this call would have no
    /// effect.
    ///
    /// This routine takes a reference to a GlobalSymbolList, and operates by
    /// appending (using the STL list push_back() method) a pair consisting of
    /// the symbol name string and a pointer to a GlobalSymbolInfo structure
    /// for each global symbol currently stored in the Global Symbol Table
    /// that matches the symbol type filter.  Type filtering is described with
    /// the \a i_types argument. Global symbols are appended to \a io_symbols
    /// in the lexicographic order defined by strcmp() < 0 on the character
    /// string symbol names (i.e., they come back sorted by name).
    ///
    /// globalSymbolList() only appends to the list passed as the \a
    /// io_symbols reference. Use the STL list clear() method to clear the
    /// list if necessary prior to calling globalSymbolList().
    ///
    /// \retval rc HookManager sticky error status; This method fails
    /// immediately if HookManager error status is set at entry.  To clear the
    /// error status use clearError().
    static HookError
    globalSymbolList(GlobalSymbolList& io_symbols, const char* i_types = 0);

    /// Report the HookManager state to the FAPI_INF() stream
    ///
    /// \param[in] i_options Options are selected as an OR-combination of the
    /// options documented as \ref hookmanager_report_options.  By default all
    /// elements of the report are printed.
    ///
    /// \retval 0 Success
    static void
    report(const int i_options = -1);

    //////////////////////////// Manipulators ////////////////////////////

    /// Dynmaic load of a hook DLL with internal registration
    ///
    /// \param[in] i_fileName The name of a (putative) hook DLL
    ///
    /// \param[in] i_flags Flags to dlopen()
    ///
    /// This method uses dlopen to open a putative hook DLL.  If successful,
    /// then the DLL 'handle' is recorded by the HookManager.  This allows the
    /// HookManager to dlclose() the DLL when the HookManager object is
    /// destroyed.  This method is required to support the case that multiple
    /// runs of the PoreVe with different hooks need to be made in the same
    /// process.
    ///
    /// \returns The 'handle' returned by dlopen().
    static void* 
    dlopen(const char* i_fileName, int i_flags);

    /// Register a HOOKI instruction hook with the HookManager
    ///
    /// \param[in] i_index The hook index as it will be stored in the HOOKI
    /// instruction. 
    ///
    /// \param[in] i_hookRoutine The hook routine
    ///
    /// It is considered an immediate fatal error (HOOK_STATIC_COLLISION) if
    /// an attempt is made to map a single index to different hooks.  Although
    /// the HookManager could be easily modified to support multiple static
    /// hooks for a single index if required, the current thinking is that
    /// this more likely represents an error in assigning hook indices rather
    /// than a useful feature.
    ///
    /// \retval rc HookManager sticky error status; This method fails
    /// immediately if HookManager error status is set.  To clear the error
    /// status use clearError().
    static HookError
    registerInstructionHook(const uint32_t i_index, 
                            HookInstructionHook i_hookRoutine);

    /// Register a hook table with the hook manager
    ///
    /// \param[in] i_file The file name associated with the HookTable.  This
    /// string is assumed to be a permanent static allocation and is not
    /// copied or storage managed by the HookManager.
    ///
    /// \param[in] i_table A pointer to a HookTable structure.  This structure
    /// is assumed to be a permanent static allocation and is not copied or
    /// storage managed by the HookManager.
    ///
    /// The table is mapped by the hook manager based on the file name stored
    /// in the table. It is considered an immediate fatal error
    /// (HOOK_FILE_NAME_COLLISION) if a file name collision is detected.
    ///
    /// \retval rc HookManager sticky error status; This method fails
    /// immediately if HookManager error status is set.  To clear the error
    /// status use clearError().
    static HookError
    registerHookTable(const char* i_file, 
                      const HookTable* i_table);

    /// Register an extracted Hook structure with the hook manager
    ///
    /// \param[in] i_address The effective address of a hooked
    /// instruction.
    ///
    /// \param[in,out] io_hook An initialized Hook structure.
    ///
    /// This method is used directly by code generated from an extraction
    /// script to install a hook for an address, due to the fact that
    /// extracted hooks are initialized from preconstructed static objects.
    /// This is also used as an internal method by addInteractiveHook().
    ///
    /// If more than one hook is associated with an address, later hooks are
    /// added at the end of the list of hooks.  When the hooks are run they
    /// are run in list order.
    ///
    /// \retval rc HookManager sticky error status; This method fails
    /// immediately if HookManager error status is set.  To clear the error
    /// status use clearError().
    static HookError
    registerHook(const PoreAddress& i_address, 
                 Hook* io_hook); 

    /// Register a global symbol with the hook manager
    ///
    /// \param[in] i_symbol The symbol name. This string is assumed to be a
    /// permanent static allocation and is not copied or storage managed by
    /// the HookManager.
    ///
    /// \param[in] i_info Information about the symbol. This structure is
    /// assumed to be a permanent static allocation and is not copied or
    /// storage managed by the HookManager.
    ///
    /// For simplicity, it is considered an immediate fatal error
    /// (HOOK_MULTIPLY_DEFINED_SYMBOL) to hook a symbol more than once.  If we
    /// need to provide similarly-named symbols in different address spaces
    /// then we'll need to revisit the implementation.
    ///
    /// \retval rc HookManager sticky error status; This method fails
    /// immediately if HookManager error status is set.  To clear the error
    /// status use clearError().
    static HookError
    registerGlobalSymbol(const char* i_symbol, 
                         const GlobalSymbolInfo* i_info);

    /// Add an interactive hook to a PoreAddress
    ///
    /// \param[in] i_address The effective address of the hooked
    /// instruction or data.
    ///
    /// \param[in] i_type The hook type, which must be one of the *INTERACTIVE
    /// types.
    ///
    /// \param[in] i_hookRoutine The AddressBasedHook that implements the hook.
    ///
    /// Create and install an interactive hook of \a i_type for an effective
    /// PORE address.  If more than one hook is associated with an address,
    /// later hooks are added at the end of the list of hooks.  When the hooks
    /// are run they are run in list order.
    ///
    /// \retval rc A non-zero return value indicates any error that occurred.
    /// This method fails immediately if HookManager error status is set at
    /// entry.  To clear the error status use clearError().
    static HookError
    addInteractiveHook(const PoreAddress& i_address,
                       const HookType i_type,
                       const AddressBasedHook i_hookRoutine);

    /// Delete interactive hooks of a given type from a PoreAddress
    ///
    /// \param[in] i_address The effective address of the hooked
    /// instruction or data.
    ///
    /// \param[in] i_type The hook type, which must be one of the *INTERACTIVE
    /// types.
    ///
    /// \param[in] i_hookRoutine The AddressBasedHook that implements the
    /// hook, or a default value of 0 which means to delete all interactive
    /// hooks of the given type from the address.
    ///
    /// By default, delete all interactive hooks of \a i_type from an
    /// effective PORE address.  If \a i_hook is not 0, then all occurrences
    /// of only that particular hook are deleted.
    ///
    /// \retval rc A non-zero return value indicates any error that occurred.
    /// This method fails immediately if HookManager error status is set at
    /// entry.  To clear the error status use clearError().
    static HookError
    deleteInteractiveHooks(const PoreAddress& i_address,
                           const HookType i_type,
                           const AddressBasedHook i_hookRoutine = 0);

    /// Clear the HookManager error status
    ///
    /// The HookManager has 'sticky' error status - new operations on the
    /// HookManager will fail if the error status is non-zero.  This method
    /// clears the error status.
    static void
    clearError();

    ////////////////////////// Implementation ////////////////////////////

    /// The last HookError encountered
    ///
    /// Many of the HookError conditions arise during load-time
    /// initialization, when there's really no recourse for trapping or
    /// handling them. Instead, if the iv_error is non-0 then all load-time
    /// HookManager APIs return immediately, allowing some diagnosis (of the
    /// first error) after initialization.  The interactive methods set and
    /// return \a iv_error with the final return code but do not block further
    /// operations.
    HookError iv_error;

    // NB: s_instance must be public for the Simics workaround

    /// The singleton instance of the HookManager
    static HookManager* s_instance;

protected:

    /// The vector of DLL handles
    std::vector<void*> iv_dllHandles;

    /// The instruction hook map
    InstructionHookMap iv_instructionHookMap;

    /// The hooked file map
    HookedFileMap iv_hookedFileMap;

    /// The hooked address map
    ///
    /// The HookManager system maintains an invariant that if an entry in this
    /// map exists, then the list of hooks associated with that address is not
    /// empty (i.e., the pointer is not 0).
    HookedAddressMap iv_hookedAddressMap;

    /// The global symbol map
    GlobalSymbolMap iv_globalSymbolMap;

    /// Run a specific type of hook
    ///
    /// \param[in] i_interactiveType One of the *INTERACTIVE HookType.
    ///
    /// \param[in] i_extractedType The *EXTRACTED counterpart of the
    /// interactive type.
    ///
    /// \param[in] i_address The current effective address.
    ///
    /// \param[in,out] io_pore The Pore model, to allow the hook to examine or
    /// modify the state of the PORE.
    ///
    /// \param[in] i_target A reference to the FAPI Target currently
    /// associated with the virtual PORE.
    ///
    /// This is a helper method for runReadHooks(), runWriteHooks() and
    /// runFetchHooks() that actually does the search and execution, given an
    /// interactive and extracted hook type to search.
    ///
    /// \retval rc The FAPI return code returned by the first (if any)
    /// hook routine to return a non-OK code, otherwise an OK return code.
    fapi::ReturnCode
    runHooks(const HookType i_interactiveType,
             const HookType i_extractedType,
             const PoreAddress& i_address,
             Pore& io_pore,
             const fapi::Target& i_target);


    ///////////////////////////// Safety //////////////////////////////////

private:
    HookManager(const HookManager& i_rhs);
    HookManager& operator=(const HookManager& i_rhs);
};


////////////////////////////////////////////////////////////////////////////
// HookInitializer
////////////////////////////////////////////////////////////////////////////

/// A dummy class used to initialize the HookManager
///
/// Initialization of the HookManager depends on the ability of C++ to run
/// object constructors at load time.  Each hook file and indexing file
/// contains an initialization function that installs information into the
/// symbol table.  Each hook file also creates an instance of the
/// HookInitializer whose sole purpose is to run the initialization function
/// in its constructor at load time.

class 
vsbe::HookInitializer {

public:

    //////////////////////////////   Types  //////////////////////////////

    /// The type of a HookManager initializer function
    typedef void (*HookManagerInitializer)();

    ////////////////////////////// Creators //////////////////////////////

    /// Create an HookInitializer
    ///
    /// \param[in] i_function The function to call during construction of the
    /// otherwise empty object.
    HookInitializer(HookManagerInitializer i_function);

    ~HookInitializer();

    ///////////////////////////// Safety //////////////////////////////////

private:
    HookInitializer(const HookInitializer& rhs);
    HookInitializer& operator=(const HookInitializer& rhs);
};


#endif  // __VSBE_HOOKMANAGER_H
