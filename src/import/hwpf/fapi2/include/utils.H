/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/hwpf/fapi2/include/utils.H $                       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2022                        */
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
 * @file utils.H
 * @brief Defines common fapi2 utilities
 */

#ifndef FAPI2_UTILS_H_
#define FAPI2_UTILS_H_

#include <stdint.h>
#include <endian.h>
#include <return_code.H>
#include <target_types.H>
#include <plat_types.H>
#include <plat_utils.H>


namespace fapi2
{

///
/// @brief Endian swapping
/// @tparam T input type
/// @param[in,out] io_input integral input
/// @note https://stackoverflow.com/questions/105252/how-do-i-convert-between-big-endian-and-little-endian-values-in-c
/// This function does not take into account the system's endianness, but just does the endian swap
///
template < typename T >
void endian_swap(T& io_input)
{
    constexpr size_t MIN_BYTES = 2;
    static_assert(sizeof(T) >= MIN_BYTES, "Byte swapping requires at least 2 bytes of data");

    uint8_t* l_varArray = reinterpret_cast<uint8_t*>(&io_input);

    for(size_t i = 0; i < sizeof(io_input) / 2; i++)
    {
        const size_t BYTE_SWAP_INDEX = sizeof(io_input) - 1 - i;

        // Rolling our own swap as certain downstream libraries do not have std::swap enabled
        const auto l_temp = l_varArray[BYTE_SWAP_INDEX];
        l_varArray[BYTE_SWAP_INDEX] = l_varArray[i];
        l_varArray[i] = l_temp;
    }
}

struct uint8be_t
{
    uint8_t _value;
    inline uint8_t get() const
    {
        return _value;
    }
    inline void set(uint8_t value)
    {
        _value = value;
    }
};

///@brief For storing common types big-endian
struct uint16be_t
{
    uint16_t _value;
    inline uint16_t get() const
    {
        return be16toh(_value);
    }
    inline void set(uint16_t value)
    {
        _value = htobe16(value);
    }
};

struct uint32be_t
{
    uint32_t _value;
    inline uint32_t get() const
    {
        return be32toh(_value);
    }
    inline void set(uint32_t value)
    {
        _value = htobe32(value);
    }
};

struct uint64be_t
{
    uint64_t _value;
    inline uint64_t get() const
    {
        return be64toh(_value);
    }
    inline void set(uint64_t value)
    {
        _value = htobe64(value);
    }
};

/// @brief return true if the input value is nonzero and a power of two, else return false
constexpr bool is_power_of_two(const uint64_t i_value)
{
    return i_value && (!(i_value & (i_value - 1)));
}

/// @brief return a bit mask with a string of length 1 bits starting at start_bit
constexpr uint64_t bit_mask(const int start_bit, const int length)
{
    return (~0ULL >> (64 - length)) << (64 - start_bit - length);
}

///
/// @brief Macro to check for a given platform.
/// Platforms are expected to define a constant PLATFORM value in plat_utils.H
///
template <PlatformType i_type>
static inline constexpr bool is_platform()
{
    // This assertion makes sure that PLATFORM is a compile time constant
    static_assert(static_cast<int>(fapi2::PLATFORM) != 0xDEADBEEF, "");
    return fapi2::PLATFORM == i_type;
}

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))

#if !defined(__PPE__) && !defined(BOOTLOADER)
///
/// @brief Enable/Disable special wakeup on processor chip core(s)
///
/// Special Wakeup Enable must be done when a HWP is doing an operation that
/// requires core(s) to be awake (e.g. modifying the Hcode image). For
/// each Special Wakeup Enable call, there must be a subsequent Special Wakeup
/// Disable call.
///
/// This does not apply to SCOM operations, platforms must handle Special Wakeup
/// for SCOM operations internally.
///
/// If Special Wakeup is enabled, a core will not go to sleep (if already
/// sleeping, it is woken up). If Special Wakeup is disabled, if there are no
/// other active Enables, the core is allowed to sleep.
///
/// @note Implemented by platform code calling the cpu special wakeup HWP.
///       This is a FAPI2 function because each platform may do different things
///         Hostboot: Does nothing (cores cannot sleep while Hostboot running)
///         FSP: Uses an algorithm to decide when to disable special wakeup
///         Cronus: Does Special Wakeup enable/disable as requested
///
/// @param[in] i_target
///              TARGET_TYPE_PROC_CHIP: Enables/Disables Special Wakeup on all
///                cores (EX,EQ chiplets) of the specified chip target.
///              TARGET_TYPE_CORE: Enables/Disables Special Wakeup on the
///                specified core target (EX,EQ chiplets)
///              TARGET_TYPE_EX: Enables/Disables Special Wakeup on the
///                specified EX target.
///              TARGET_TYPE_EQ: Enables/Disables Special Wakeup on the
///                specified EQ target.
///
/// @param[in] i_enable true = enable. false = disable.
///
/// @return ReturnCode. FAPI2_RC_SUCCESS on success, else platform specified error.
///
///
template<TargetType T, MulticastType M, typename V>
inline ReturnCode specialWakeup(const Target<T, M, V>& i_target,
                                const bool i_enable)
{
    // enforce the allowed target types
    static_assert( ((T == fapi2::TARGET_TYPE_PROC_CHIP) ||
                    (T == fapi2::TARGET_TYPE_CORE)      ||
                    (T == fapi2::TARGET_TYPE_EX)        ||
                    (T == fapi2::TARGET_TYPE_EQ)),
                   "Invalid target type for this function");

    ReturnCode l_rc = platSpecialWakeup( i_target, i_enable );

    return l_rc;
}

///
/// @brief Log an error.
///
/// @param[in,out] io_rc Reference to ReturnCode (Any references to data and error
///            target are removed and rc value is set to success after
///            function ends.)
/// @param[in] i_sev Fapi error log severity defaulted to unrecoverable
/// @param[in] i_unitTestError - flag to log error which does not cause a unit
///                              test to fail.
///
/// @note This function is called from the ffdc collection classes and no longer
/// needs to be called directly.
/// @note Implemented by platform code
///
void logError(
    fapi2::ReturnCode& io_rc,
    fapi2::errlSeverity_t i_sev = fapi2::FAPI2_ERRL_SEV_UNRECOVERABLE,
    bool i_unitTestError = false );

///
/// @brief Create a platform error log
///
///  This function will create a platform error log from the passed in
///  return code value and will populate the iv_platDataPtr of the return code
///  with a pointer to the newly created log.
///
/// @param[in,out] io_rc - Reference to ReturnCode
///
/// @param[in] i_sev Fapi error log severity defaulted to unrecoverable
//
//
/// @note Implemented by platform code
///
void createPlatLog(
    fapi2::ReturnCode& io_rc,
    fapi2::errlSeverity_t i_sev = fapi2::FAPI2_ERRL_SEV_UNRECOVERABLE
);

///
/// @brief delete platform data ptr - free platform data from the
//                                    passed in RC.
///
void deletePlatformDataPointer(fapi2::ReturnCode& io_rc);

///
/// @brief Associate an error to PRD PLID
///
/// @param[in] i_target Reference to target
/// @param[in,out] io_rc Reference to ReturnCode
/// @param[in] i_sev Fapi error log severity defaulted to unrecoverable
/// @param[in] i_unitTestError - flag to log error which does not cause a unit
///                              test to fail.
///
/// @note Implemented by platform code
///
void log_related_error(
    const Target<TARGET_TYPE_ALL>& i_target,
    fapi2::ReturnCode& io_rc,
    const fapi2::errlSeverity_t i_sev = fapi2::FAPI2_ERRL_SEV_UNRECOVERABLE,
    const bool i_unitTestError = false );

#endif // __PPE__

///
/// @brief Delay this thread. Hostboot will use the nanoseconds parameter
/// and make a syscall to nanosleep. While in the syscall, the hostboot
/// kernel will continue to consume CPU cycles as it looks for a runnable
/// task.  When the delay time expires, the task becomes runnable and will soon
/// return from the syscall.  Callers of delay() in the hostboot environment
/// will likely have to know the mHz clock speed they are running on and
/// compute a non-zero value for i_nanoSeconds.
///
/// On the FSP, it was sometimes acceptable to just provide zero for the
/// sleep delay time, causing the task to yield its time slice. By the
/// time the calling task could run again, it was pretty certain enough
/// host cycles had past.  This is probably not acceptable in
/// the hostboot environment. Callers should calculate and provide a
/// sleep value in nanoseconds relative to host clock speed.
///
/// On FSP when VBU is the target, then the i_simCycles parameter will be
/// used instead.  The FSP needs to use the simdispatcher client/server
/// API and issue a command to the awan to advance the simulation the
/// specified number of cycles.
///
/// @param[in] i_nanoSeconds    nanoseconds to sleep
/// @param[in] i_simCycles      count of Awan cycles to advance
/// @param[in] i_fixed          Determination, for DFT, if this time is
///                             fixed or not. Defaults to non-fixed
///
/// @return ReturnCode. Zero on success, else platform specified error.
///
ReturnCode delay(uint64_t i_nanoSeconds, uint64_t i_simCycles,
                 bool i_fixed = false);

///
/// @brief Assert a condition, and halt
///
/// @param[in] i_expression a boolean representing the assertion
///
void Assert(bool i_expression);
};

#endif // FAPI2_UTILS_H_
