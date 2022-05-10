/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/hwpf/fapi2/include/fapi2_target.H $                */
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
///
/// @file fapi2_target.H
/// @brief Common definitions for fapi2 targets
///

#ifndef __FAPI2_COMMON_TARGET__
#define __FAPI2_COMMON_TARGET__

#include <stdint.h>
#ifndef __PPE__
    #include <stdlib.h>
#endif // __PPE__
#include <vector>
#include <target_types.H>
#include <target_states.H>
#include <multicast_defs.H>
#include <plat_target.H>
#include <return_code_defs.H>

namespace fapi2
{

///
/// @brief Apply any platform specific static assertions to target construction
/// @tparam K the type of target to be constructed
/// @tparam M the multicast type of the target to be constructed
/// @tparam V the value type of the target to be constructed
///
template<TargetType K, MulticastType M, typename V>
static constexpr void plat_apply_target_limits(void);

///
/// @brief Class representing a FAPI2 Target
/// @tparam K the type (Kind) of target
/// @tparam M the type of multicast operation if it's a multicast target
/// @tparam V the type of the target's Value
/// @remark TargetLite targets are uint64_t, Targets
/// are uintptr_t (void*).
///
/// Assuming there are representations of a processor,
/// a membuf and a system here are some examples:
/// @code
/// #define PROCESSOR_CHIP_A 0xFFFF0000
/// #define MEMBUF_CHIP_B    0x0000FFFF
/// #define SYSTEM_C         0x0000AAAA
/// @endcode
///
/// * To define a target:
/// @code
/// fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP> A(PROCESSOR_CHIP_A);
/// fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> C(SYSTEM_C);
/// fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP> B(MEMBUF_CHIP_B);
/// @endcode
///
/// * Functions which take composite target types
/// @code
/// void takesProcOrMembuf(
/// const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP |
///                     fapi2::TARGET_TYPE_MEMBUF_CHIP>& V );
///
/// void takesAny(const fapi2::Target<fapi2::TARGET_TYPE_ALL>& V );
///
/// @endcode
///
/// * Traversing the target "tree"
/// @code
/// fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP> A(PROCESSOR_CHIP_A);
///
/// // Get A's parent
/// A.getParent<fapi2::TARGET_TYPE_SYSTEM>();
///
/// // Get the 0x53'd core
/// fapi2::getTarget<fapi2::TARGET_TYPE_CORE>(0x53);
///
/// // Get all *my* present/functional children which are cores
/// A.getChildren<fapi2::TARGET_TYPE_CORE>();
///
/// // Get all of the the cores relative to my base target
/// fapi2::getChildren<fapi2::TARGET_TYPE_CORE>();
/// @endcode
///
/// * Invalid casts
/// @code
/// // Can't cast to a specialized target
/// fapi2::Target<fapi2::TARGET_TYPE_NONE> D(MEMBUF_CHIP_B);
/// takesProcOrMembuf( D );
///
/// // Not one of the shared types
/// fapi2::Target<fapi2::TARGET_TYPE_ABUS_ENDPOINT> E;
/// takesProcOrMembuf( E );
/// @endcode
template<TargetType K, MulticastType M = MULTICAST_OR, typename V = plat_target_handle_t>
class Target
{
    public:

        ///
        /// @brief Delagate default constructor to constructor
        ///        that takes in a value as a param
        ///
        Target(): Target(V())
        {
            plat_apply_target_limits<K, M, V>();
        };

        ///
        /// @brief Create a Target, with a value
        /// @param[in] Value the value (i.e., specific element this
        /// target represents, or pointer)
        /// @note Platforms can mangle the value and K to get a
        /// single uint64_t in value which represents all the information
        /// they might need. value( K | V ), for example
        ///
        Target(const V& Value):
            iv_handle(Value)
        {
            plat_apply_target_limits<K, M, V>();
            // No multicast support for Hostboot Bootloader
#ifndef FAPI_PLAT_MULTICAST_NOT_SUPPORTED

            /* Iff this is a potential mcast target, update the handle.
             * We can't know the mcast op of the V handed in, so we have
             * to incur the cost of the update even if unnecessary.
             */
            if (K & TARGET_TYPE_MULTICAST)
            {
                mcUpdateHandle();
            }

#endif
        };

        ///
        /// @brief Assignment Operator.
        /// @param[in] i_right Reference to Target to assign from.
        /// @return Reference to 'this' Target
        ///
        Target& operator=(const Target& i_right);

        ///
        /// @brief Equality Comparison Operator
        /// @param[in] i_right Reference to Target to compare.
        /// @return bool. True if equal.
        /// @note Platforms need to define this so that the physical
        /// targets are determined to be equivilent rather than just the handles
        ///
        bool operator==(const Target& i_right) const;

        ///
        /// @brief Inquality Comparison Operator
        /// @param[in] i_right Reference to Target to compare.
        /// @return bool. True if not equal.
        /// @note Platforms need to define this so that the physical
        /// targets are determined to be equivilent rather than just the handles
        ///
        bool operator!=(const Target& i_right) const;

        ///
        /// @brief Less Than Comparison Operator
        /// @param[in] i_right Reference to Target to compare.
        /// @return bool. True if less than i_right.
        /// @note Platforms need to define this so that the physical
        /// targets are determined to be less than rather than just the handles
        ///
        bool operator<(const Target& i_right) const;

        ///
        /// @brief Get the handle.
        /// @return V The target's handle, or value
        ///
        V get(void) const
        {
            return iv_handle;
        }

        ///
        /// @brief Get the handle as a V
        /// @return V The target's handle, or value
        ///
        inline operator V() const
        {
            return iv_handle;
        }

        ///
        /// @brief Get a target's value
        /// @return V The target's handle, or value
        ///
        inline V& operator()(void)
        {
            return iv_handle;
        }

        ///
        /// @brief Get the target type
        /// @return The type of target represented by this target
        ///
        inline TargetType getType(void) const
        {
            return iv_type;
        }

        ///
        /// @brief Get this target's immediate parent
        /// @tparam T The type of the parent
        /// @return Target<T> a target representing the parent
        ///
        template< TargetType T >
        inline Target<T, M, V> getParent(void) const;

        ///
        /// @brief Is this target a chip?
        /// @return Return true if this target is a chip, false otherwise
        ///
        inline constexpr bool isChip(void) const
        {
            return (isChip(K));
        }

        ///
        /// @brief Static function check if a Target type value is that of
        ///        a chip. It will return false for compound types that
        ///        include non-chip Target type bits
        ///
        /// @param[in] i_type  The value of the Target type.
        /// @return Return true if this type is of a chip, false otherwise
        ///
        static inline bool isChip(const TargetType i_type)
        {
            bool l_retVal = false;

            // Target type must have only chip type bits set
            if ( ((i_type & TARGET_TYPE_CHIPS) != 0) &&
                 ((i_type & ~TARGET_TYPE_CHIPS) == 0) )
            {
                l_retVal = true;
            }

            return l_retVal;
        }

        ///
        /// @brief Is this target a chiplet?
        /// @return Return true if this target is a chiplet, false otherwise
        ///
        inline constexpr bool isChiplet(void) const
        {
            return (isChiplet(K));
        }

        ///
        /// @brief Static function check if a Target type value is that of
        ///        a chiplet. It will return false for compound types that
        ///        include non-chiplet Target type bits
        ///
        /// @param[in] i_type  The value of the Target type.
        /// @return Return true if this type is of a chiplet, false otherwise
        ///
        static inline bool isChiplet(const TargetType i_type)
        {
            bool l_retVal = false;

            // Target type must have only chiplet type bits set
            if ( ((i_type & TARGET_TYPE_CHIPLETS) != 0) &&
                 ((i_type & ~TARGET_TYPE_CHIPLETS) == 0) )
            {
                l_retVal = true;
            }

            return l_retVal;
        }

        ///
        /// @brief Get this target's children
        /// @tparam T The type of the children
        /// @param[in] i_state The desired TargetState of the children
        /// @return std::vector<Target<T,V>> a vector of present/functional
        /// children
        /// @warning The children of EX's (cores) are expected to be returned
        /// in order. That is, core 0 is std::vector[0].
        ///
        template< TargetType T>
        inline std::vector<Target<T, M, V> >
        getChildren(const TargetState i_state = TARGET_STATE_FUNCTIONAL) const;

        ///
        /// @brief Get this target's children, filtered
        /// @tparam T The type of the children
        /// @param[in] i_filter The desired chiplet filter
        /// @param[in] i_state The desired TargetState of the children
        /// @return std::vector<Target<T,V>> a vector of present/functional
        /// children
        ///
        template< TargetType T>
        inline std::vector<Target<T, M, V> >
        getChildren(const TargetFilter i_filter,
                    const TargetState i_state = TARGET_STATE_FUNCTIONAL) const;

        ///
        /// @brief Convert this target into a type that is a subset of K, with type checking
        /// @tparam T The type of the expected output target
        /// @param[out] o_target The converted target will be stored here
        /// @return FAPI2_RC_SUCCESS if the target was compatible
        ///         FAPI2_RC_INVALID_PARAMETER if not
        ///
        /// This method is supposed to be a way out of composite target hell.
        /// If a HWP must accept a wide variety of potential targets, most target
        /// transformations (like getParent, getChildren, getChipletNumber, ...) will
        /// not work because the template type includes too many different types and the
        /// result of those operations is not clearly defined.
        ///
        /// The idea is that the HWP will eventually be able to narrow down the set of
        /// allowed types for its target depending on the code path it's taking, such as
        /// "must be a PROC_CHIP" or "must be a chiplet target". It can then call this
        /// method to transform the template type into the expected type (which may still
        /// be composite). The method will fail if the target's _actual_ type (only known
        /// to platform code) does not fit into the requested type.
        ///
        template< TargetType T>
        inline ReturnCodes
        reduceType(Target<T, M, V>& o_target) const;

        // No multicast support for Hostboot Bootloader
#ifndef FAPI_PLAT_MULTICAST_NOT_SUPPORTED
        ///
        /// @brief Get a multicast target for a given chip
        /// @tparam T The type of target to return; TARGET_TYPE_MULTICAST is added automatically
        /// @tparam O The type of multicast read operation for the target; defaults to OR
        /// @param[in] i_group The abstract multicast group the target should point to
        /// @return The multicast target
        ///
        /// This method is only applicable to chip-level targets.
        /// If the requested multicast group cannot be mapped to an available HW multicast
        /// group, a platform specific error will be thrown.
        ///
        template< TargetType T, MulticastType O = MULTICAST_OR >
        inline Target < T | TARGET_TYPE_MULTICAST, O, V >
        getMulticast(const MulticastGroup i_group) const;

        ///
        /// @brief Get a multicast core target for a given chip
        /// @tparam O The type of multicast read operation for the target; defaults to OR
        /// @param[in] i_group The abstract multicast group (selecting EQs) the target should point to
        /// @param[in] i_cores Which cores inside the selected EQ should be targeted
        /// @return The multicast target
        ///
        /// This method is only applicable to chip-level targets.
        /// If the requested multicast group cannot be mapped to an available HW multicast
        /// group, a platform specific error will be thrown.
        ///
        template< MulticastType O = MULTICAST_OR >
        inline Target < TARGET_TYPE_CORE | TARGET_TYPE_MULTICAST, O, V >
        getMulticast(const MulticastGroup i_group, const MulticastCoreSelect i_cores) const;
#endif

        ///
        /// @brief Get the target at the other end of a bus
        /// @tparam T The type of the target on the other end
        /// @param[out] o_target A target representing the thing on the other end
        /// @param[in] i_state The desired TargetState of the other end
        /// @return FAPI2_RC_SUCCESS if OK, platforms will return a non-success
        /// ReturnCode in the event of failure
        /// @note o_target is only valid if return is FAPI2_RC_SUCCESS
        ///

        template<TargetType T>
        inline fapi2::ReturnCodes
        getOtherEnd(Target<T, M, V>& o_target, const TargetState i_state = TARGET_STATE_FUNCTIONAL) const;

        ///
        /// @brief Is the target functional?
        /// @return true if target is functional, false if non-functional
        ///
        inline bool
        isFunctional(void) const;

        ///
        /// @brief Returns the chiplet number associated with the Target
        /// @return The chiplet number for the Target. 0 is returned if the
        /// Target does not have a chiplet number (for ex, the PROC_CHIP Target)
        /// @note For logical targets such as the EX, the chiplet number of
        /// their immediate parent chiplet is returned. For multicast targets
        /// getChipletNumber() is not supported.
        ///
        inline uint8_t
        getChipletNumber(void) const;


        // No multicast support for Hostboot Bootloader
#ifndef FAPI_PLAT_MULTICAST_NOT_SUPPORTED
        ///
        /// @brief Returns the core select vector associated with a Core target
        /// @return The core select value for the target. For unicast core targets
        /// the return value will have exactly one bit set. For multicast core
        /// targets it will have between one and four bits set.
        ///
        inline MulticastCoreSelect
        getCoreSelect(void) const
        {
            static_assert(K & TARGET_TYPE_CORE, "getCoreSelect is only applicable to TARGET_TYPE_CORE targets");
            return _getCoreSelect();
        }
#endif

        ///
        /// @brief Copy from a Target<O, MO> to a Target<K, M>
        /// @tparam O the target type of the other
        /// @tparam MO the multicast type of the other
        ///
        template<TargetType O, MulticastType MO>
        inline Target( const Target<O, MO, V>& Other ):
            iv_handle(Other.get())
        {
            plat_apply_target_limits<K, M, V>();

            // In case of recursion depth failure, use -ftemplate-depth=
            static_assert( (K & O) != 0,
                           "unable to cast Target, no shared types");

            static_assert( bitCount<K>::count >= bitCount<O>::count,
                           "unable to cast to specialized Target");

            // No multicast support for Hostboot Bootloader
#ifndef FAPI_PLAT_MULTICAST_NOT_SUPPORTED

            // Only need to update the handle if we're coming from a target that's already MULTICAST
            if ((O & TARGET_TYPE_MULTICAST) && (MO != M))
            {
                mcUpdateHandle();
            }

#endif
        }

    private:
        // Don't use enums here as it makes it hard to assign
        // in the platform target cast constructor.
        static const TargetType iv_type = K;
        V iv_handle;

        // No multicast support for Hostboot Bootloader
#ifndef FAPI_PLAT_MULTICAST_NOT_SUPPORTED
        /// @brief if iv_handle is a multicast target, update its multicast type to M
        inline void mcUpdateHandle(void);

        /// @brief Internal implementation of getCoreSelect, filtered for CORE targets
        inline MulticastCoreSelect _getCoreSelect(void) const;
#endif

        ///
        /// @brief Static checks for getParent.
        ///        Platform implementations are expected to call this.
        /// @tparam T The type of the parent
        ///
        template< TargetType T >
        inline void check_getParent(void) const
        {
            // It's forbidden to strip multicast from a target below PROC_CHIP level:
            // Since a multicast might end up expanding to more than one unicast target,
            // users are required to use getChildren if they want to map back to unicast.
            static_assert(!(((K ^ T) & TARGET_TYPE_MULTICAST) && ((T & TARGET_TYPE_CHIPLETS) != TARGET_TYPE_NONE)),
                          "Parent target for a multicast target must also be multicast or PROC_CHIP");
            static_assert((T & TARGET_TYPE_MULTICAST) == 0 || (T & TARGET_TYPE_MULTICASTABLE) != 0,
                          "Requested target type for multicast parents must be part of TARGET_TYPE_MULTICASTABLE");
        }

        ///
        /// @brief Static compile time checks for getChildren.
        ///        Platform implementations are expected to call this.
        /// @tparam T The type of the children
        ///
        template< TargetType T>
        inline void check_getChildren() const
        {
            // valid children for multicast targets are the same with multicast stripped
            static_assert(!((K & TARGET_TYPE_MULTICAST) &&
                            (K != (T | TARGET_TYPE_MULTICAST))),
                          "improper child of fapi2::TARGET_TYPE_MULTICAST");
        }

        ///
        /// @brief Static compile time checks for reduceType.
        ///        Platform implementations are expected to call this.
        /// @tparam T The requested new type
        ///
        template< TargetType T>
        inline void check_reduceType() const
        {
            // just a placeholder for now
        }

        // No multicast support for Hostboot Bootloader
#ifndef FAPI_PLAT_MULTICAST_NOT_SUPPORTED
        ///
        /// @brief Static checks for getMulticast(). Platforms are expected to call this.
        /// @tparam T The type of target to return; TARGET_TYPE_MULTICAST is added automatically
        /// @tparam O The type of multicast read operation for the target; defaults to OR
        ///
        template< TargetType T, MulticastType O >
        inline void check_getMulticast() const
        {
            // C++ does not allow partial specialization of class member functions (please prove me wrong!),
            // so we need to use this static assertion instead. On the upside, the error message is much clearer ;)
            static_assert((K & TARGET_TYPE_MULTICAST_CHIP) != 0,
                          "Parent target must be part of TARGET_TYPE_MULTICAST_CHIP");
            static_assert((T & TARGET_TYPE_MULTICASTABLE) != 0,
                          "Requested target type must be part of TARGET_TYPE_MULTICASTABLE");
            static_assert(bitCount<T>::count == 1,
                          "Requested target type must be a single type, TARGET_TYPE_MULTICAST will be added automatically");
        }
#endif

        ///
        /// @brief Static checks for getChipletNumber. Platforms are expected to call this.
        ///
        inline void check_getChipletNumber(void) const
        {
            static_assert((K & TARGET_TYPE_MULTICAST) == 0, "getChipletNumber is not supported for multicast targets");
        }
};

// EX threads map to CORE threads:
// t0 / t2 / t4 / t6 fused = t0 / t1 / t2 / t3 normal (c0)
// t1 / t3 / t5 / t7 fused = t0 / t1 / t2 / t3 normal (c1)
// So when splitting the EX, we need to map from EX threads
// to CORE threads.

///
/// @brief Given a normal core thread id, translate this to
/// a fused core thread id. (normal to fused)
/// @param[in] i_ordinal   the ordinal number of the normal core this thread belongs to
/// @param[in] i_thread_id a normal core thread id - 0, ..., 3
/// @return the fused core thread id
///
inline uint8_t thread_id_n2f(const uint8_t i_ordinal, const uint8_t i_thread_id)
{
    return (i_thread_id << 1) | i_ordinal;
}

///
/// @brief Given a fused core thread id, translate this to
/// a normal core thread id. (fused to normal)
/// @param[in] i_thread_id a fused core thread id - 0, ..., 7
/// @return the normal core thread id
///
inline uint8_t thread_id_f2n(const uint8_t i_thread_id)
{
    return i_thread_id >> 1;
}

///
/// @brief Given a normal core thread id, translate this to a
/// normal core bitset.
/// @param[in] i_thread_id a normal core thread id - 0, ..., 3
/// @return the normal core bitset
/// @note to got from a fused core id to a normal core bitset,
/// translate from a fused core thread id first.
///
inline uint8_t thread_id2bitset(const uint8_t i_thread_id)
{
    // 0xff means "set all bits"
    static const uint8_t all_threads  = 0xff;
    static const uint8_t all_normal_threads_bitset = 0x0f;

    if (i_thread_id == all_threads)
    {
        return all_normal_threads_bitset;
    }

    // A thread_id is really just bit index.
    return (1 << (4 - i_thread_id - 1));
}

///
/// @brief Given a bitset of normal core thread ids, translate this to
/// a bit mask of fused core thread id. (normal to fused)
/// @param[in] i_ordinal the ordinal number of the normal core this thread belongs to
/// @param[in] i_threads a normal core thread bitset - b0000, ..., b1111
/// @return the corresponding fused core bitset
///
inline uint8_t thread_bitset_n2f(const uint8_t i_ordinal, const uint8_t i_threads)
{
    // Since we only have 4 bits I think this is better than a shift-type solution
    // for interleaving bits
    static uint8_t core_map[] =
    {
        0b00000000, // b0000
        0b00000010, // b0001
        0b00001000, // b0010
        0b00001010, // b0011
        0b00100000, // b0100
        0b00100010, // b0101
        0b00101000, // b0110
        0b00101010, // b0111
        0b10000000, // b1000
        0b10000010, // b1001
        0b10001000, // b1010
        0b10001010, // b1011
        0b10100000, // b1100
        0b10100010, // b1101
        0b10101000, // b1110
        0b10101010, // b1111
    };

    return core_map[i_threads] >> i_ordinal;
}

///
/// @brief Given a fused core thread bitset, translate this to
/// a normal core thread bitset. (fused to normal)
/// @param[in] i_ordinal the ordinal number of the normal core this thread belongs to
/// @param[in] i_threads a fused core thread bitset - b00000000, ..., b11111111
/// @return the corresponding normal core bitset
///
inline uint8_t thread_bitset_f2n(const uint8_t i_ordinal, const uint8_t i_threads)
{
    uint8_t normal_set = 0;

    // core 0 is the left-most bit in the pair
    uint8_t pair_mask = (i_ordinal == 0) ? 0x2 : 0x1;

    // For each bit which can be set in the normal core bit_set ...
    for( auto i = 0; i <= 3; ++i )
    {
        // ... grab the two fused bits which represent it ...
        // ... and mask off the bit in the pair which represents this normal core ...
        // (the << 1 shifts the masks over as we walk the pairs of bits)
        uint8_t bits = (((3 << (i << 1)) & i_threads) & (pair_mask << (i << 1)));

        // ... if either bit is set, set the corresponding bit in
        // the normal core bitset.
        normal_set |= (bits != 0) << i;
    }

    return normal_set;
}

///
/// @brief Return the string interpretation of this target
/// @tparam T The type of the target
/// @param[in] i_target Target<T,V>
/// @param[in] i_buffer buffer to write in to
/// @param[in] i_bsize size of the buffer
/// @return void
/// @post The contents of the buffer is replaced with the string
/// representation of the target
///
template< TargetType T, MulticastType M, typename V >
inline void toString(const Target<T, M, V>& i_target, char* i_buffer, size_t i_bsize);

///
/// @brief Return the string interpretation of this target
/// @tparam T The type of the target
/// @tparam B The type of the buffer
/// @param[in] i_target A pointer to the Target<T,V>
/// @param[in] i_buffer buffer to write in to
/// @param[in] i_bsize  size of the buffer
/// @return void
/// @post The contents of the buffer is replaced with the string
/// representation of the target
///
template< TargetType T, MulticastType M, typename V >
inline void toString(const Target<T, M, V>* i_target, char* i_buffer, size_t i_bsize);

///
/// @brief Get an enumerated target of a specific type
/// @tparam T The type of the target
/// @param[in] Ordinal representing the ordinal number of
/// the desired target
/// @return Target<T> the target requested
///
template<TargetType T, MulticastType M = MULTICAST_OR, typename V = plat_target_handle_t>
inline Target<T, M, V> getTarget(uint64_t Ordinal);

///
/// @brief Return the string interpretation of this target
/// @tparam T The type of the target
/// @tparam B The type of the buffer
/// @param[in] i_target Target<T,V>
/// @param[in] i_buffer buffer
/// @return void
/// @post The contents of the buffer is replaced with the string
/// representation of the target
///
template<TargetType T, MulticastType M, typename V, typename B>
inline void toString(const Target<T, M, V>& i_target, B& i_buffer);

///
/// @brief Check if the target is of a type, or in a type subset.
/// @tparam K the TargetType to check
/// @tparam T TargetType or TargetType composite to check against
/// @return True, iff K is a proper T
///
template< TargetType K, TargetType T >
inline constexpr bool is_same(void)
{
    return (K & T) != 0;
}

}

#endif
