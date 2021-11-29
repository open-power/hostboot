/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/sys/misc.h $                                      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2021                        */
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
#ifndef __SYS_MISC_H
#define __SYS_MISC_H

#include <stdint.h>

/**
 *  @enum   p8SystemConsts
 *
 *  system-wide constants:
 *  - please add as necessary
 *
 */

enum    p8SystemConsts
{
    /// max possible processors in a P8 system
    P8_MAX_PROCS        =   8,
    /// max EX (cores available in a processor )
    P8_MAX_EX_PER_PROC  =   16,

};

enum    p9SystemConsts
{
    /// max possible processors in a P9 system
    P9_MAX_PROCS        =   8,
    /// max EC (cores available in a processor )
    P9_MAX_EC_PER_PROC  =   24,

};

enum    p10SystemConsts
{
    /// max possible processors in a P10 system
    P10_MAX_PROCS        =   8,
    /// max EC (cores available in a processor )
    P10_MAX_EC_PER_PROC  =   32,

};

/**
 * @enum ShutdownStatus
 *
 * Shutdown values for shutdown command.
 */

enum ShutdownStatus
{
    SHUTDOWN_STATUS_GOOD                = 0x01230000,
    SHUTDOWN_STATUS_UT_FAILED           = 0x01230001,
    SHUTDOWN_STATUS_ISTEP_FAILED        = 0x01230002,
    SHUTDOWN_STATUS_EXTINITSVC_FAILED   = 0x01230003,
    SHUTDOWN_STATUS_INITSVC_FAILED      = 0x01230004,
    SHUTDOWN_STATUS_PLDM_REQUEST_FAILED = 0x01230005,
    SHUTDOWN_STATUS_PLDM_RESET_DETECTED = 0x01230006,
};

/**
 * @enum WinkleScopes
 *
 * Scope of the winkle operation.
 */
enum WinkleScope
{
    WINKLE_SCOPE_MASTER = 0x0,
    WINKLE_SCOPE_ALL = 0x1,
};



/**
 * HOMER layout offsets
 * see: HOMER_Image_Layout.odt
 */
/** Offset from HOMER to OCC Image */
#define HOMER_OFFSET_TO_OCC_IMG (0*KILOBYTE)
/** Offset from HOMER to OCC Host Data Area */
#define HOMER_OFFSET_TO_OCC_HOST_DATA (976*KILOBYTE)
/** Offset from HOMER to HCODE Image */
#define HOMER_HCODE_IMG_OFFSET (1*MEGABYTE)
/** STOP Image Max ouput size */
#define HOMER_MAX_HCODE_IMG_SIZE_IN_MB 1


#ifdef __cplusplus
extern "C"
{
#endif

#ifdef __HIDDEN_SYSCALL_SHUTDOWN
/** @fn shutdown()
 *  @brief Shutdown all CPUs (hardware threads)
 *  @param[in] i_status         The status code to post
 *  @param[in] i_payload_base   The base address (target HRMOR) of the payload.
 *  @param[in] i_payload_entry  The offset from base address of the payload
 *                              entry-point.
 *  @param[in] i_payload_data   Data pointer fo the payload.
 *  @param[in[ i_masterHBInstance  Hostboot instance number. for multinode
 *  @param[in] i_error_info     Additional error data to be added to TI data
 */
extern "C" void shutdown(uint64_t i_status,
                         uint64_t i_payload_base,
                         uint64_t i_payload_entry,
                         uint64_t i_payload_data,
                         uint64_t i_masterHBInstance,
                         uint32_t i_error_info);
#endif

/** @enum ProcessorCoreType
 *  @brief Enumeration of the different supported processor cores.
 */
enum ProcessorCoreType
{
    CORE_POWER10,

    CORE_UNKNOWN,
};

/**
 * Strings for ProcessorCoreType
 *   declared in misc.C
 */
extern const char* ProcessorCoreTypeStrings[CORE_UNKNOWN+1];

/** @fn cpu_core_type()
 *  @brief Determine the procesore core type.
 *
 *  @return ProcessorCoreType - Value from enumeration for this core.
 */
ProcessorCoreType cpu_core_type();

/** @fn cpu_dd_level()
 *  @brief Determine the processor DD level.
 *
 *  @return 1 byte DD level as <major nibble, minor nibble>.
 */
uint8_t cpu_dd_level();

/** @fn cpu_thread_count()
 *  @brief Get the number of available threads per cpu for this proctype
 *  @return # of threads per cpu
 */
size_t cpu_thread_count();

/** @fn cpu_start_core
 *  @brief Have the kernel start a new core.
 *
 *  @param[in] pir - PIR value of the first thread on the core.
 *  @param[in] i_threads - Bitstring of threads to enable (left-justified).
 *
 *  @note The kernel will start all threads on the requested core even
 *        though the callee only requests with a single PIR value.
 *
 *  @return 0 or -(errno) on failure.
 *
 *  @retval -ENXIO - The core ID was outside of the range the kernel is
 *                   prepared to support.
 */
int cpu_start_core(uint64_t pir,uint64_t i_threads);

/**
 * @enum CpuSprNames
 *
 * Names for SPR registers for cpu_spr_value().
 */
enum CpuSprNames
{
    CPU_SPR_MSR,
    CPU_SPR_LPCR,
    CPU_SPR_HRMOR,
    CPU_SPR_HID,
};

/**
 * @enum CpuSprNames
 *
 * Values for SPR registers for cpu_spr_value().
 */
enum CpuSprValues
{
    CPU_SPR_HID_EN_ATTN = 3,
};

/** @fn cpu_spr_value
 *  @brief Reads the kernel-desired value for an SPR.
 *
 *  This is used, for instance, in building a sleep-winkle image.
 *
 *  @return The desired value of the SPR register.
 */
uint64_t cpu_spr_value(CpuSprNames spr);


/** @fn cpu_hrmor_nodal_base
 *  @brief Provides the hrmor nodal base address
 *
 *  This is used, for instance, when determining multi-node
 *  memory mirroring address calculations
 *
 *  @return The hrmor nodal base address
 */
uint64_t cpu_hrmor_nodal_base();

/** @fn cpu_spr_set
 *  @brief Writes an SPR.
 *
 *  @return rc: true = success,  false = unsupported SPR.
 */
uint64_t cpu_spr_set(CpuSprNames spr, uint64_t newValue );

/** @fn cpu_master_winkle
 *  @brief Winkle the master core so runtime SLW image can be applied.
 *
 *  This requires that the master core is the only one executing instructions.
 *  Will execute the winkle instruction on all running threads and return when
 *  an IPI is receieved on the master thread of the core.
 *
 *  @param[in] i_fusedCores - Fused cores if true,  Regular cores if false
 *
 *  @retval 0 - Success
 *  @retval -EDEADLK - Cores other than the master are already running.
 *
 *  @note This function will migrate the task to the master thread and in the
 *        process will unset any task affinity.  See task_affinity_unpin().
 */
int cpu_master_winkle(bool  i_fusedCores);

/** @fn cpu_all_winkle
 *  @brief Winkle all the threads.
 *
 *  This is used in multi-node systems to quiesce all the cores in a drawer
 *  prior to the fabric being stitched together.
 *
 *  @retval 0 - Success
 *
 *  @note This function will migrate the task to the master thread and in the
 *        process will unset any task affinity.  See task_affinity_unpin().
 */
int cpu_all_winkle();

/** @fn cpu_wakeup_core
 *  @brief Have the kernel wakeup a core that was previously started.
 *
 *  @param[in] pir - PIR value of the first thread on the core.
 *  @param[in] i_threads - Bitstring of threads to enable (left-justified).
 *
 *  @note The kernel will wakeup all threads on the requested core even
 *        though the callee only requests with a single PIR value.
 *
 *  @return 0 or -(errno) on failure.
 *
 *  @retval -ENXIO - The core ID was outside of the range the kernel is
 *                   prepared to support.
 */
int cpu_wakeup_core(uint64_t pir,uint64_t i_threads);

/** @fn cpu_crit_assert
 *  @brief Forces a Terminate Immediate after a crit-assert is issued
 *  @param[in] i_failAddr - value in the linkRegister of the address
 *           of where the fail ocured.
 *
 *  @return none
 */
void cpu_crit_assert(uint64_t i_failAddr);

/** @fn set_mchk_data
 *  @brief Tells the kernel how to force a checkstop for unrecoverable
 *         machine checks
 *  @param[in] i_xstopAddr - XSCOM MMIO address of FIR to write
 *  @param[in] i_xstopData - Data to write into FIR to trigger xstop
 *
 *  @return none
 */
void set_mchk_data(uint64_t i_xstopAddr, uint64_t i_xstopData);

/** @fn set_topology_mode
 *  @brief Tells the kernel what topology mode the system is in.
 *         0 == Mode 0; GGGC where G = Group (3 bits) and C = Chip (1 bit). In this mode the chip bit isn't used and
 *                      group=chip. That is to say that group bits correspond to the proc chip number. This mode is
 *                      for single node systems such as Rainier and Everest.
 *         1 == Mode 1; GGCC 2 bits group and 2 bits chip. Confusingly, this mode is referred to as chip=node but the
 *                      group bits actually determine the node and the chip bits are used for the proc chip number.
 *
 *  @param[in]  i_topologyMode   The topology mode setting for this system.
 */
void set_topology_mode(uint8_t i_topologyMode);

#ifdef __cplusplus
}
#endif

#endif
