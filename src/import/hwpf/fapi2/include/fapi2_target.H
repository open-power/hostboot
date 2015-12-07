/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: hwpf/fapi2/include/fapi2_target.H $                           */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* EKB Project                                                            */
/*                                                                        */
/* COPYRIGHT 2015                                                         */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
///
/// @file fapi2_target.H
/// @brief Common definitions for fapi2 targets
///

#ifndef __FAPI2_COMMON_TARGET__
#define __FAPI2_COMMON_TARGET__

#include <stdint.h>
#include <stdlib.h>
#include <vector>
#include <target_types.H>
#include <target_states.H>
#include <plat_target.H>

namespace fapi2
{

///
/// @brief Class representing a FAPI2 Target
/// @tparam K the type (Kind) of target
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
template<TargetType K, typename V = plat_target_handle_t>
class Target
{
    public:

        ///
        /// @brief Create a Target, with a value
        /// @param[in] Value the value (i.e., specific element this
        /// target represents, or pointer)
        /// @note Platforms can mangle the value and K to get a
        /// single uint64_t in value which represents all the information
        /// they might need. value( K | V ), for example
        ///
        Target(V Value = 0):
            iv_handle(Value)
        {}

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
        inline Target<T> getParent(void) const;

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
        /// @tparam T The type of the parent
        /// @param[in] i_state The desired TargetState of the children
        /// @return std::vector<Target<T> > a vector of present/functional
        /// children
        /// @warning The children of EX's (cores) are expected to be returned
        /// in order. That is, core 0 is std::vector[0].
        ///
        template< TargetType T>
        inline std::vector<Target<T> >
        getChildren(const TargetState i_state = TARGET_STATE_FUNCTIONAL) const;

        ///
        /// @brief Get this target's children, filtered
        /// @tparam T The type of the parent
        /// @param[in], i_filter The desired chiplet filter
        /// @param[in] i_state The desired TargetState of the children
        /// @return std::vector<Target<T> > a vector of present/functional
        /// children
        ///
        template< TargetType T>
        inline std::vector<Target<T> >
        getChildren(const TargetFilter i_filter,
                    const TargetState i_state = TARGET_STATE_FUNCTIONAL) const;

        ///
        /// @brief Get the target at the other end of a bus - dimm included
        /// @tparam T The type of the parent
        /// @param[in] i_state The desired TargetState of the children
        /// @return Target<T> a target representing the thing on the other end
        /// @note Can be easily changed to a vector if needed
        ///
        template<TargetType T>
        inline Target<T>
        getOtherEnd(const TargetState i_state = TARGET_STATE_FUNCTIONAL) const;

        ///
        /// @brief Copy from a Target<O> to a Target<K>
        /// @tparam O the target type of the other
        ///
        template<TargetType O>
        inline Target( const Target<O>& Other ):
            Target<K, V>(Other.get())
        {
            // In case of recursion depth failure, use -ftemplate-depth=
            static_assert( (K & O) != 0,
                           "unable to cast Target, no shared types");

            static_assert( bitCount<K>::count >= bitCount<O>::count,
                           "unable to cast to specialized Target");
        }

    private:
        // Don't use enums here as it makes it hard to assign
        // in the platform target cast constructor.
        static const TargetType iv_type = K;
        V iv_handle;

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
/// @param[in] i_target Target<T>
/// @param[in] i_buffer buffer to write in to
/// @param[in] i_bsize size of the buffer
/// @return void
/// @post The contents of the buffer is replaced with the string
/// representation of the target
///
template< TargetType T >
inline void toString(const Target<T>& i_target, char* i_buffer, size_t i_bsize);

///
/// @brief Return the string interpretation of this target
/// @tparam T The type of the target
/// @tparam B The type of the buffer
/// @param[in] i_target A pointer to the Target<T>
/// @param[in] i_buffer buffer to write in to
/// @param[in] i_bsize  size of the buffer
/// @return void
/// @post The contents of the buffer is replaced with the string
/// representation of the target
///
template< TargetType T >
inline void toString(const Target<T>* i_target, char* i_buffer, size_t i_bsize);

///
/// @brief Get an enumerated target of a specific type
/// @tparam T The type of the target
/// @param[in] Ordinal representing the ordinal number of
/// the desired target
/// @return Target<T> the target requested
///
template<TargetType T>
inline Target<T> getTarget(uint64_t Ordinal);

// Why has the been removed? For starters, the API name
// is probably wrong as it's already been confused with
// Target::getChildren(). And if I'm going to change it
// I really want to see if we need it. I'm still not
// clear on whether we're alloing this traversal or not.
#if 0
///
/// @brief Get the base target's children
/// @tparam T The type of the target
/// @return std::vector<Target<T> > a vector of present/functional
/// children
///
template<TargetType T>
inline std::vector<Target<T> > getChildren()
{
    // For testing
    return {Target<T>(), Target<T>()};
}
#endif

///
/// @brief Return the string interpretation of this target
/// @tparam T The type of the target
/// @tparam B The type of the buffer
/// @param[in] i_target Target<T>
/// @param[in] i_buffer buffer
/// @return void
/// @post The contents of the buffer is replaced with the string
/// representation of the target
///
template<TargetType T, typename B>
inline void toString(const Target<T>& i_target, B& i_buffer);

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
