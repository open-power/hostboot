/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/arch/magic.H $                                    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020,2024                        */
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
#ifndef __KERNEL_MAGIC_H
#define __KERNEL_MAGIC_H

#include <arch/ppc.H>

/** @brief  This is a special assembler instruction that is a nop on
 *  regular hardware, but has special meaning to Simics.  Code that
 *  executes this instruction in Simics will cause a "hap," a
 *  Simics term.  If there is no hap handler registered, and magic
 *  breakpoints have not been enabled with
 *      simics> enable-magic-breakpoint
 *  then this instruction is also a nop in Simics.
 *
 *  If magic breakpoints are enabled, and there is no hap handler, then
 *  when Hostboot code executes this instruction in Simics, Simics will
 *  stop the simulation. (Prompt changes from running> to simics> )
 *
 *  If a hap is registered, then Simics will call the hap handler.  Hap
 *  handlers are written in Python, and the best place for them is
 *
 *     src/build/debug/simics-debug-framework.py
 *
 *  Sample code to register the hap handler:
 *        # arg contains the integer parameter n passed to MAGIC_INSTRUCTION(n)
 *        def magic_instruction_callback(user_arg, cpu, arg):
 *            # print to console works...
 *            print "Hit magic instruction ", arg
 *            # Or else stop the simulation...
 *            SIM_break_simulation( "Stopped at magic instruction" )
 *
 *        # Register the magic instruction callback.
 *        SIM_hap_add_callback( "Core_Magic_Instruction", magic_instruction_callback, None )
 *
 *        # Better to register the Hostboot range 7000-7999
 *        # so that PHYP and others won't be affected.
 *        SIM_hap_add_callback_range( "Core_Magic_Instruction", magic_instruction_callback, None, 7000, 7999 )
 *
 *  The argument n is an integer from 0..8191 which Simics passes to the hap
 *  handler in parameter 3, or "arg" in the sample code above.
 */
ALWAYS_INLINE
inline void MAGIC_INSTRUCTION(int _n)
{
    register int n = _n;
    isync();
    long register r3 asm("r3");
    asm volatile("rlwimi %1,%1,0,%2,%3"         \
        : "=r"(r3) : "i" (((n) >> 8) & 0x1f),   \
        "i" (((n) >> 4) & 0xf),                 \
        "i" ((((n) >> 0) & 0xf) | 16),          \
        "r"(r3));                               \
}

ALWAYS_INLINE
inline void MAGIC_INSTRUCTION_3(int _n, uint64_t* o_1, uint64_t* o_2, uint64_t* o_3)
{
    register int n = _n;
    isync();
    long register r3 asm("r3");
    long register r4 asm("r4");
    long register r5 asm("r5");
    asm volatile("rlwimi %3,%3,0,%4,%5"
                 : "=r"(r3), "=r"(r4), "=r"(r5)
                 : "i" (((n) >> 8) & 0x1f),
                   "i" (((n) >> 4) & 0xf),
                   "i" ((((n) >> 0) & 0xf) | 16),
                   "r"(r3));
    *o_1 = r3;
    *o_2 = r4;
    *o_3 = r5;
}

// Arguments to MAGIC_INSTRUCTION().
// To ensure they do not conflict with haps from other groups (PHYP
// for example), assign hap numbers in the range 7000..7999 (decimal).
// Presently, the hap handler for magic instruction is found in
// src/build/debug/simics-debug-framework.py
enum
{
    MAGIC_SIMICS_CORESTATESAVE = 10, // Indicate to the PHYP model of simics
                                     // that we are preparing to wake up a core
                                     // or thread.  This allows them to save
                                     // some state from the core doing the
                                     // wakeup to apply into the woken one.

    MAGIC_SIMICS_FUSEDCOREWAKE = 11, // Indicate to the PHYP model of simics
                                     // that we are waking up and expecting
                                     // CORES to become fused.

    // 7000-7999 are defined by Hostboot
    MAGIC_SHUTDOWN            =  7006, // KernelMisc::shutdown() called.
    MAGIC_BREAK               =  7007, // hard-code a breakpoint
    MAGIC_RANDOM              =  7008, // generate random number
    MAGIC_MEMORYLEAK_FUNCTION =  7009, // A memory was function called.
    MAGIC_FAKEPAYLOAD_ENTER   =  7010, // Entered the fake payload.
    MAGIC_SIMICS_CHECK        =  7011, // Check if system is running on simics
    MAGIC_LOAD_PAYLOAD        =  7012, // load payload from flash
    MAGIC_IS_QME_ENABLED      =  7013, // Check if QME is enabled in the SIMICS
                                       // model
    MAGIC_HB_DUMP             =  7014, // Create a hostboot dump
    MAGIC_BREAK_ON_TSFAIL     =  7017, // Breakpoint in error cases if
                                       //  env var HB_BREAK_ON_TSFAIL
    MAGIC_BREAK_ON_ERROR      =  7018, // Breakpoint in error cases if
                                       //  env var HB_BREAK_ON_ERROR
    MAGIC_GET_SBE_TRACES      =  7019, // Collect SBE traces
    MAGIC_PRINT_ISTEP         =  7020, // Print istep to simics console
    MAGIC_PRINT_TWO_REGS      =  7021, // Print 2 numbers passed in
    MAGIC_SET_LOG_LEVEL       =  7022, // Set log level for given component

    MAGIC_SETUP_THREADS       =  7025, // Manually set thread regs pre-enable
    MAGIC_ATTR_WRITE          =  7026, // Write attribute value in hostboot
    MAGIC_CHECK_DCE_ENABLED   =  7027, // Check whether DCE should be enabled
    MAGIC_DCE_LOAD_PAGE       =  7028, // Load a page from the active DCE script

    MAGIC_CONTINUOUS_TRACE    =  7055, // extract mixed trace buffer
    MAGIC_GCOV_MODULE_UNLOAD  =  7056, // extract gcov info
    MAGIC_SAVE_ATTR_VALUE     =  7057, // record attribute value
    MAGIC_CHECK_FEATURE       =  7058, // check for feature enablement
    MAGIC_SAVE_PEL            =  7060, // save a single PEL
    MAGIC_GET_CI_RUN_LEVEL    =  7061, // extract HB CI Run Level

    MAGIC_CHECK_BONITO_CONFIG =  7777, // check if MACHINE=bonito is set in the ENV

    // 8000-8999 are defined by the Simics CEC team
    MAGIC_SIMICS_FSP_WAIT      =  8001, // Notify we are/aren't waiting for FSP
                                        //   1=waiting, 2=done waiting
    MAGIC_SIMICS_SHUTDOWN      =  8006, // Notify we shut down with an error
    MAGIC_SIMICS_ISTEP         =  8020, // Log istep, same parms as 7020
    MAGIC_SIMICS_EXIT_CACHE_CONTAINED = 8021, // Exiting cache contained mode
};

/**
 * @brief Stop simics execution
 */
#define MAGIC_INST_BREAK() \
    asm volatile("mr 4, %0" :: "r" (1) : "4"); \
    MAGIC_INSTRUCTION(MAGIC_BREAK); \

/**
 * @brief     Ask the simulation to record (part of) the value of an attribute.
 * @param[in] HUID         HUID of target
 * @param[in] ATTR_ID      Attribute ID
 * @param[in] ATTR_SIZE    Total size of attribute in bytes
 * @param[in] BYTE_OFFSET  Offset, in bytes, of the given 8-byte chunk of the attribute value
 * @param[in] BYTES        8-byte chunk of the attribute value
 */
#define MAGIC_INST_SAVE_ATTR_VALUE(HUID, ATTR_ID, ATTR_SIZE, BYTE_OFFSET, BYTES) \
    asm volatile("mr 4, %0; mr 5, %1; mr 6, %2; mr 7, %3; mr 8, %4;"    \
                 :: "r" (HUID), "r" (ATTR_ID), "r" (ATTR_SIZE), "r" (BYTE_OFFSET), "r" (BYTES) \
                 : "4", "5", "6", "7", "8");                            \
    MAGIC_INSTRUCTION(MAGIC_SAVE_ATTR_VALUE);                           \

/**
 * @brief  Specify the type of SBE traces to collect
 */
enum magicGetSbeTraceType
{
    MAGIC_GET_P10_SBE_TRACES = 14,
    MAGIC_GET_ODY_SBE_TRACES = 15,
};

/**
 * @brief Collect SBE traces via external debug commands
 * @param[in]  Processor number
 * @param[in]  SBE Return Code
 * @param[in]  magicGetSbeTraceType to collect
 */
#define MAGIC_INST_GET_SBE_TRACES(_procnum,_rc,_type) \
    asm volatile("mr 4, %0; mr 5, %1; mr 6, %2" :: \
                 "r" (_procnum), "r" (_rc) , "r" (_type) : "4", "5", "6"); \
    MAGIC_INSTRUCTION(MAGIC_GET_SBE_TRACES);

/**
 * @brief Display istep numbers on the simics console
 * @param[in]  Major istep number
 * @param[in]  Minor istep number
 */
#define MAGIC_INST_PRINT_ISTEP(_major,_minor) \
    asm volatile("mr 4, %0; mr 5, %1" :: \
                 "r" (_major), "r" (_minor) : "4", "5"); \
    MAGIC_INSTRUCTION(MAGIC_PRINT_ISTEP); \
    MAGIC_INSTRUCTION(MAGIC_SIMICS_ISTEP); \

/**
 * @brief Display 2 numbers on the simics console
 * @param[in]  First number (uint64_t)
 * @param[in]  Second number (uint64_t)
 */
#define MAGIC_INST_PRINT_2_REGS(_first, _second) \
    asm volatile("mr 4, %0; mr 5, %1" :: \
                 "r" (_first), "r" (_second) : "4", "5"); \
    MAGIC_INSTRUCTION(MAGIC_PRINT_TWO_REGS); \

inline bool magic_check_dce_enabled()
{
    long register r3 asm("r3") = 0;
    MAGIC_INSTRUCTION(MAGIC_CHECK_DCE_ENABLED);
    return r3;
}

/**
 * @brief Notify simics that we are waiting for a FSP message
 */
#define MAGIC_WAITING_FOR_FSP() \
    asm volatile("mr 4, %0" :: "r" (1) : "4"); \
    MAGIC_INSTRUCTION(MAGIC_SIMICS_FSP_WAIT); \

/**
 * @brief Notify simics that we are done waiting for a FSP message
 */
#define MAGIC_DONE_WAITING_FOR_FSP() \
    asm volatile("mr 4, %0" :: "r" (2) : "4"); \
    MAGIC_INSTRUCTION(MAGIC_SIMICS_FSP_WAIT); \

/**
 * @brief set the log level for a given component
 * @param[in]  _componentId Enum of simics comp ids
 * @param[in]  _logLevel desired log level
 */
#define MAGIC_INST_SET_LOG_LEVEL(_componentId, _logLevel) \
    asm volatile("mr 4, %0; mr 5, %1" :: \
                 "r" (_componentId), "r" (_logLevel) : \
                 "4", "5"); \
    MAGIC_INSTRUCTION(MAGIC_SET_LOG_LEVEL); \

/**
 * @brief Save a PEL to a file
 * @param[in]  Physical memory address of a PEL (uint64_t)
 * @param[in]  Size of PEL in bytes (uint64_t)
 * @param[in]  ID of PEL (uint64_t)
 */
#define MAGIC_INST_SAVE_PEL(_addr, _size, _id) \
    asm volatile("mr 4, %0; mr 5, %1; mr 6, %2;" :: \
                 "r" (_addr), "r" (_size), "r" (_id) : "4", "5", "6"); \
    MAGIC_INSTRUCTION(MAGIC_SAVE_PEL); \


// Simics components that we can raise log levels for
// It is important to keep these lined up with
// simics-debug-framework.py
constexpr uint8_t PIB_PSU              = 0;
constexpr uint8_t SBE_INT_BO           = 1;

constexpr uint8_t ENABLE_OUTPUT  = 1;
constexpr uint8_t DISABLE_OUTPUT = 0;

constexpr uint8_t LOG_LEVEL_OFF  = 0;
constexpr uint8_t LOG_LEVEL_LOW  = 1;
constexpr uint8_t LOG_LEVEL_MED  = 2;
constexpr uint8_t LOG_LEVEL_HIGH = 3;
constexpr uint8_t LOG_LEVEL_MAX  = 4;


/**
 * @brief Setup all threads with good default
 *        register values to allow them to run when enabled.
 * @param[in] _smfEnabled Whether SMF is enabled or not
 */
#define MAGIC_INST_SETUP_THREADS(_smfEnabled) \
    asm volatile("mr 4, %0" :: \
                 "r" (_smfEnabled) : \
                 "4"); \
    MAGIC_INSTRUCTION(MAGIC_SETUP_THREADS); \

/**
 * @brief A magic instruction to fetch attribute write data from the debug framework
 *
 * @param[in] _byteToWrite the data to write to console
 */
inline bool MAGIC_INST_GET_ATTR_WRITE(uint32_t& o_attrid,
                                      uint32_t& o_huid,
                                      uint32_t& o_attrsize,
                                      uint64_t& o_attrval)
{
    uint64_t attrid_and_huid = 0, attrsize = 0;
    MAGIC_INSTRUCTION_3(MAGIC_ATTR_WRITE, &attrid_and_huid, &attrsize, &o_attrval);

    o_attrid = attrid_and_huid >> 32;
    o_huid = attrid_and_huid & 0xFFFFFFFFu;
    o_attrsize = attrsize;

    return o_attrid != 0;
}

inline uint64_t magic_dce_load_page(const uint64_t phys_page, const uint64_t offset)
{
    long register r3 asm("r3") = 0;
    asm volatile("mr 4, %0" ::
                 "r" (phys_page) :
                 "4");
    asm volatile("mr 5, %0" ::
                 "r" (offset) :
                 "5");
    MAGIC_INSTRUCTION(MAGIC_DCE_LOAD_PAGE);
    asm volatile("" ::: "memory"); // the previous magic instruction writes memory
    return r3;
}

/**
 * @brief Check if a specific feature is enabled
 * @param[in] _feature  Specific feature/workaround to check
 */
#define MAGIC_INST_CHECK_FEATURE(_feature) magic_check_feature(_feature)
inline bool magic_check_feature(long _feature)
{
    long register r3 asm("r3") = 0;
    asm volatile("mr 4, %0" ::
                 "r" (_feature) :
                 "4");
    MAGIC_INSTRUCTION(MAGIC_CHECK_FEATURE);
    return r3;
}
// List of features that we can check
constexpr uint8_t MAGIC_FEATURE__MULTIPROC     = 1;
constexpr uint8_t MAGIC_FEATURE__IGNORESMPFAIL = 2;
constexpr uint8_t MAGIC_FEATURE__IGNORETODFAIL = 3;
constexpr uint8_t MAGIC_FEATURE__USEOLDSPI_DEPRECATED = 4;
constexpr uint8_t MAGIC_FEATURE__SKIPOCC       = 5;
constexpr uint8_t MAGIC_FEATURE__ODYSECURITY   = 6;

/**
 * @brief Check if a running Bonito machine
 */
#define MAGIC_IS_BONITO() magic_check_bonito()
inline bool magic_check_bonito()
{
    long register r3 asm("r3") = 0;
    asm volatile("mr 4, %0" ::
                 "r" (1):
                 "4");
    MAGIC_INSTRUCTION(MAGIC_CHECK_BONITO_CONFIG);
    return r3;
}

/**
 * @brief   Get CI Run Level
 * @return  run level
 */
#define MAGIC_INST_GET_CI_RUN_LEVEL() magic_get_ci_run_level()
inline int magic_get_ci_run_level()
{
    long register r3 asm("r3") = 0;
    MAGIC_INSTRUCTION(MAGIC_GET_CI_RUN_LEVEL);
    return r3;
}

#endif //__KERNEL_MAGIC_H
