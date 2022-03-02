/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/fapi2/target.H $                              */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2022                        */
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
/// @file target.H
///
/// @brief Defines the platform target functions that needs to be
/// specialized for platform implementation.
///
/**
 * @file target.H
 * @brief platform specializations for fapi2 targets
 */

#ifndef __FAPI2_TARGET__
#define __FAPI2_TARGET__

#include <plat_target.H>
#include <stdio.h>
#include <stdint.h>
#include <vector>
#include <target_types.H>
#include <return_code_defs.H>
#include <fapi2_target.H>

#include <hwpf_fapi2_reasoncodes.H>

// HB platform support
#include <fapiPlatTrace.H>
#include <targeting/common/target.H>
#include <targeting/common/commontargeting.H>
#include <targeting/common/targetservice.H>
#include <targeting/common/utilFilter.H>
#include <targeting/common/predicates/predicatectm.H>
#include <targeting/common/predicates/predicateisfunctional.H>

//@TODO RTC:150675 get error info from getOtherEnd fails
//#include <errl/errlentry.H>
//#include <errl/errlmanager.H>

// Handy macro to get the Hostboot target from the fapi target
#define FAPI_TO_HBTARG(__fapi) (static_cast<TARGETING::Target*>(__fapi->get()))

namespace PLAT_TARGET
{
///
/// @brief         Helper function for specialized system target allows
///                for the constructor to call targetservice::getTopLevel
/// @param[in/out] io_handle Reference to TARGETING::Target to assign
///                iv_handle to.
/// @return void
///
void systemTargCtorHelperFunc(fapi2::plat_target_handle_t& io_handle);
}

namespace fapi2
{


///
/// @brief         Specialization for TARGET_TYPE_SYSTEM targets
///                for the constructor to call targetservice::getTopLevel
/// @param[in/out] io_handle Reference to TARGETING::Target to assign
///                iv_handle to.
/// @return void
///
/// @note          the default templated constructor is delegated to
////               constructors take in a plat_target_handle_t
///
template<>
inline Target<TARGET_TYPE_SYSTEM, MULTICAST_OR, plat_target_handle_t>
::Target(const plat_target_handle_t& v)
{
    PLAT_TARGET::systemTargCtorHelperFunc(iv_handle);
}

///
/// @brief Assignment Operator.
/// @tparam K The type of target on which this is called
/// @tparam V the type of the target's Value
/// @param[in] i_right Reference to Target to assign from.
/// @return Reference to 'this' Target
///
template<TargetType K, MulticastType M, typename V>
Target<K, M, V>& Target<K, M, V>::operator=(const Target& i_right)
{ iv_handle = i_right.iv_handle; return *this; }

///
/// @brief Equality Comparison Operator
/// @tparam K The type of target on which this is called
/// @tparam V the type of the target's Value
/// @param[in] i_right Reference to Target to compare.
/// @return bool. True if equal.
/// @note This platform uses handles for comparison as
/// target handles are statically defined so the order
/// is consistent.
///
template<TargetType K, MulticastType M, typename V>
bool Target<K, M, V>::operator==(const Target& i_right) const
{ return i_right.iv_handle == iv_handle; }

///
/// @brief Apply any platform specific static assertions to target construction
/// @tparam K the type of target to be constructed
/// @tparam M the multicast type of the target to be constructed
/// @tparam V the value type of the target to be constructed
///
template<TargetType K, MulticastType M, typename V>
static constexpr void plat_apply_target_limits(void)
{
}

/// @brief if iv_handle is a multicast target, update its multicast type to M
/// @tparam K the type of target
/// @tparam M the multicast type of the target
/// @tparam V the value type of the target
template<TargetType K, MulticastType M, typename V>
inline void Target<K, M, V>::mcUpdateHandle()
{
}

///
/// @brief Inquality Comparison Operator
/// @tparam K The type of target on which this is called
/// @tparam M The multicast type of target on which this is called
/// @tparam V the type of the target's Value
/// @param[in] i_right Reference to Target to compare.
/// @return bool. True if not equal.
/// @note This platform uses handles for comparison as
/// target handles are statically defined so the order
/// is consistent.
///
template<TargetType K, MulticastType M, typename V>
bool Target<K, M, V>::operator!=(const Target& i_right) const
{ return i_right.iv_handle != iv_handle; }

///
/// @brief Less Than Comparison Operator
/// @param[in] i_right Reference to Target to compare.
/// @return bool. True if less than i_right
/// @note This platform uses handles for comparison as
/// target handles are statically defined so the order
/// is consistent.
///
template<TargetType K, MulticastType M, typename V>
bool Target<K, M, V>::operator<(const Target& i_right) const
{
    return  iv_handle < i_right.iv_handle;
}

struct fapi2_targeting_type
{
    /* This structure associates a fapi2 TargetType with a Targeting type for
     * purposes of converting back and forth. */

    fapi2::TargetType fapi2Type;
    TARGETING::TYPE targetingType;
};

namespace impl
{

// Size of the array below
constexpr size_t NUM_FAPI_TARGETING_TYPES = 25;

// Declaration of the array holding the associations between fapi2 target
// types and Targeting types.
extern const std::array<fapi2_targeting_type, NUM_FAPI_TARGETING_TYPES>
    fapi2ToTargetingTypes;

}

///
/// @brief This function takes in a FAPI2 Type and returns the corresponding
///         TARGETING::Target type
///
/// @param[in] i_fapi2Type
///
/// @returns TARGETTING::Type equivelent to fapi2 type
inline TARGETING::TYPE convertFapi2TypeToTargeting(const fapi2::TargetType i_T)
{
    using namespace impl;

    TARGETING::TYPE o_targetingType = TARGETING::TYPE_NA;

    // Muticast targets are always of type PROC
    if(i_T & TARGET_TYPE_MULTICAST)
    {
        o_targetingType = TARGETING::TYPE_PROC;
    }
    else
    {

        const auto conversion = std::find_if(std::cbegin(fapi2ToTargetingTypes),
                                             std::cend(fapi2ToTargetingTypes),
                                             [i_T](const auto a)
                                             {
                                                 return a.fapi2Type == i_T;
                                             });

        if (conversion != std::cend(fapi2ToTargetingTypes))
        {
            o_targetingType = conversion->targetingType;
        }
        else
        {
            FAPI_ERR("convertFapi2TypeToTargeting:: Chiplet type not supported 0x%.16llX!",
                     i_T);
            assert(false);
        }
    }

    return o_targetingType;
}

///
/// @brief This function takes in a TARGETING Type and returns the corresponding
///         FAPI::Target type
///
/// @param[in] i_fapi2Type
///
/// @returns TARGETTING::Type equivelent to fapi2 type
inline fapi2::TargetType convertTargetingTypeToFapi2(const TARGETING::TYPE i_T)
{
    using namespace impl;

    fapi2::TargetType o_targetingType = fapi2::TARGET_TYPE_NONE;

    const auto conversion = std::find_if(std::cbegin(fapi2ToTargetingTypes),
                                         std::cend(fapi2ToTargetingTypes),
                                         [i_T](const auto a)
                                         {
                                             return a.targetingType == i_T;
                                         });

    if (conversion != std::cend(fapi2ToTargetingTypes))
    {
        o_targetingType = conversion->fapi2Type;
    }
    else
    {
        o_targetingType = fapi2::TARGET_TYPE_NONE;
    }

    return o_targetingType;
}

namespace impl {

/// @brief     Helper function for isProperParent(TargetType, TargetType)
///
/// @param[in] i_child     The child type in question
/// @param[in] i_parent    The parent type
/// @param[in] i_begin     Iterator pointing to the beginning of the parent/child
///                        relationship table
/// @param[in] i_it        Iterator pointing to the current entry being check in the
///                        parent/child relationship table
/// @param[in] i_begin     Iterator pointing to the end of the parent/child
///                        relationship table
/// @return                Whether or not i_child is a child of i_parent
template<typename It>
constexpr bool isProperParent(const TargetType i_child,
                              const TargetType i_parent,
                              const It i_begin,
                              const It i_it,
                              const It i_end)
{
    /* Target A is a PROPER parent of target B if and only if:
     * 1) A is an IMMEDIATE parent of B, OR
     * 2) A is a PROPER parent of B's PARENT.
     * A child can have multiple parents as is the case with, for example, EQ
     * targets having both PROC_CHIP and PERV parents.
     */

    bool l_isParent = false;

    if (i_it != i_end)
    {
        // If this rule applies to the child type, then check the two cases
        // for parenthood listed above.
        if (i_it->children & i_child)
        {
            if (// Condition (1) above,
                (i_it->parent & i_parent)

                // OR condition (2) above.
                // Don't stop if this returns false because a child can have
                // multiple parents.
                || isProperParent(i_it->parent, i_parent, i_begin, i_begin, i_end))
            {
                l_isParent = true;
            }
        }

        // If we already found the answer, stop. Otherwise, recur and check the
        // next parent/child relationship record.
        l_isParent = l_isParent
                  || isProperParent(i_child, i_parent, i_begin, i_it + 1, i_end);
    }

    return l_isParent;
}

///
/// @brief This function determines whether or not instances of a given target
///        type can be children of instances of another target type.
///
/// @param[in] i_child     The child type in question
/// @param[in] i_parent    The parent type
///
/// @returns   Whether or not i_child is a child of i_parent
constexpr bool isProperParent(const TargetType i_child,
                              const TargetType i_parent)
{
    struct
    {
        // This struct holds a list of TargetTypes (stored as a bitmask of
        // logically-ORed TargetType values) that are children of a given parent
        // TargetType.

        TargetType children;
        TargetType parent;
    }

    // This array describes the directed acyclic graph of relationships between
    // instances of parent and child types. The first column is the child type(s)
    // and the second is the parent type.
    // A child can have multiple parents, as is the case for e.g. the EQ target
    // having both PROC_CHIP and PERV parents; and of course a parent may have
    // multiple children. Many-to-one relationships should be represented by
    // bitwise-OR'ing the child types together in the first field.
    const parentInfo[] =
    {
        {   TARGET_TYPE_PROC_CHIP , TARGET_TYPE_SYSTEM    },

        {   TARGET_TYPE_EQ
          | TARGET_TYPE_PERV
          | TARGET_TYPE_NMMU
          | TARGET_TYPE_PEC
          | TARGET_TYPE_PAUC
          | TARGET_TYPE_MC        , TARGET_TYPE_PROC_CHIP },

        {   TARGET_TYPE_MI
          | TARGET_TYPE_OMIC      , TARGET_TYPE_MC        },
        {   TARGET_TYPE_MCC       , TARGET_TYPE_MI        },
        {   TARGET_TYPE_OMI       , TARGET_TYPE_MCC       },
        {   TARGET_TYPE_OCMB_CHIP , TARGET_TYPE_OMI       },
        {   TARGET_TYPE_PMIC
          | TARGET_TYPE_MEM_PORT
          | TARGET_TYPE_GENERICI2CSLAVE
          | TARGET_TYPE_MDS_CTLR  , TARGET_TYPE_OCMB_CHIP },
        {   TARGET_TYPE_DIMM      , TARGET_TYPE_MEM_PORT  },
        {   TARGET_TYPE_FC        , TARGET_TYPE_EQ        },
        {   TARGET_TYPE_IOHS
          | TARGET_TYPE_OMIC
          | TARGET_TYPE_PAU       , TARGET_TYPE_PAUC      },
        {   TARGET_TYPE_PHB       , TARGET_TYPE_PEC       },
        {   TARGET_TYPE_CORE      , TARGET_TYPE_FC        },

        {   TARGET_TYPE_NMMU
          | TARGET_TYPE_EQ
          | TARGET_TYPE_CORE
          | TARGET_TYPE_PEC
          | TARGET_TYPE_PHB
          | TARGET_TYPE_PAUC
          | TARGET_TYPE_IOHS
          | TARGET_TYPE_PAU
          | TARGET_TYPE_MC
          | TARGET_TYPE_MI
          | TARGET_TYPE_MCC
          | TARGET_TYPE_OMIC
          | TARGET_TYPE_OMI       , TARGET_TYPE_PERV },
        {   TARGET_TYPE_IOLINK    , TARGET_TYPE_IOHS     },

        // OMI has a logical relationship with the OMIC that it is a member of
        {   TARGET_TYPE_OMI       , TARGET_TYPE_OMIC },

        /* These target types are to support legacy P9 code */
        {   TARGET_TYPE_DIMM      , TARGET_TYPE_MBA },
        {   TARGET_TYPE_MBA       , TARGET_TYPE_MEMBUF_CHIP },
    };

    return isProperParent(i_child,
                          i_parent,
                          std::cbegin(parentInfo),
                          std::cbegin(parentInfo),
                          std::cend(parentInfo));
}

}

///
/// @brief Get this target's immediate parent
/// @tparam T_SELF The type of target on which this is called
/// @tparam K_PARENT The desired type of the parent target
/// @tparam V the type of the target's Value
/// @return Target<T> a target representing the parent
///
template<TargetType T_SELF, MulticastType M, typename V>
template<TargetType K_PARENT>
inline Target<K_PARENT, M, V> Target<T_SELF, M, V>::getParent(void) const
{

    FAPI_DBG(ENTER_MRK "getParent. Type of parent 0x%08x", K_PARENT);

    static_assert(impl::isProperParent(T_SELF, K_PARENT),
                  "improper parent of fapi2::Target");

    TARGETING::TargetHandleList l_parentList;
    TARGETING::TYPE requiredPType =
        fapi2::convertFapi2TypeToTargeting(K_PARENT);

    // Targets with multicast
    if ((T_SELF & TARGET_TYPE_MULTICAST) != 0)
    {
        // When performing multicast getParent on a multicast CORE
        // match with an EQ target or a an EQ target with multicast.
        if ( ( (K_PARENT == fapi2::TARGET_TYPE_EQ)  ||
               (K_PARENT == (fapi2::TARGET_TYPE_EQ | fapi2::TARGET_TYPE_MULTICAST)) ) &&
             (T_SELF == (fapi2::TARGET_TYPE_CORE | fapi2::TARGET_TYPE_MULTICAST)) )
        {
                TARGETING::getParentAffinityTargetsByState(
                    l_parentList,
                    FAPI_TO_HBTARG(this),
                    TARGETING::CLASS_NA,
                    requiredPType,
                    TARGETING::UTIL_FILTER_ALL);
        }
        else
        {
            TARGETING::Target* l_target = FAPI_TO_HBTARG(this);
            assert(l_target != nullptr, "platform target handle is nullptr");
            TARGETING::TYPE requiredCType =
                l_target->getAttr<TARGETING::ATTR_TYPE>();
            if (requiredPType == TARGETING::TYPE_PROC)
            {
                // When performing multicast getParent on target proc looking
                // for parent proc.
                if (requiredCType == TARGETING::TYPE_PROC)
                {
                    l_parentList.push_back(this->get());
                }
                else
                {
                    // cover any multicast child (ie TYPE_CORE) to parent proc
                    TARGETING::getParentAffinityTargetsByState(
                        l_parentList,
                        l_target,
                        TARGETING::CLASS_NA,
                        requiredPType,
                        TARGETING::UTIL_FILTER_ALL);
                }
            }
        } // if ( ( (K_PARENT == fapi2::TARGET_TYPE_EQ) ... else ...
    }
    else
    {
        if(K_PARENT == fapi2::TARGET_TYPE_PERV)
        {
            TARGETING::getParentPervasiveTargetsByState(
                l_parentList,
                FAPI_TO_HBTARG(this),
                TARGETING::CLASS_NA,
                requiredPType,
                TARGETING::UTIL_FILTER_ALL);
        }
        else if(K_PARENT == fapi2::TARGET_TYPE_OMIC)
        {
            TARGETING::getParentOmicTargetsByState(
                l_parentList,
                FAPI_TO_HBTARG(this),
                TARGETING::CLASS_NA,
                requiredPType,
                TARGETING::UTIL_FILTER_ALL);
        }
        else if ((K_PARENT == fapi2::TARGET_TYPE_PAUC)
                && (T_SELF == fapi2::TARGET_TYPE_OMIC))
        {
            TARGETING::getParentPaucTargetsByState(
                l_parentList,
                FAPI_TO_HBTARG(this),
                TARGETING::CLASS_NA,
                requiredPType,
                TARGETING::UTIL_FILTER_ALL);
        }
        else
        {
            TARGETING::getParentAffinityTargetsByState(
                l_parentList,
                FAPI_TO_HBTARG(this),
                TARGETING::CLASS_NA,
                requiredPType,
                TARGETING::UTIL_FILTER_ALL);
        }
    } // if ((T_SELF & TARGET_TYPE_MULTICAST) != 0) ... else ...
    assert(l_parentList.size() == 1, "Found %d parents of the same type. Target HUID %x isMulticast %d,\
        looking for parents of type %x", l_parentList.size(), TARGETING::get_huid(this->get()),
        (((T_SELF & TARGET_TYPE_MULTICAST)==0)?0:1), requiredPType);

    TARGETING::Target * l_parentTarget = l_parentList[0];

    assert(l_parentTarget != nullptr,
        "No parent of type %x was found for the target of type %x, Found required parent plat type to be %x",
        K_PARENT, T_SELF, requiredPType);

    Target<K_PARENT, M, V> outTarget(l_parentTarget);

    FAPI_DBG(EXIT_MRK "getParent");
    return outTarget;
}


///
/// @brief Get this target's children
/// @tparam T_SELF The type of target on which this is called
/// @tparam K_CHILD The desired type of child target
/// @tparam V the type of the target's Value
/// @param[in] i_state The desired TargetState of the children
/// @return std::vector<Target<T> > a vector of present/functional
/// children
/// @warning The children of FC's (cores) are expected to be returned
/// in order. That is, core 0 is std::vector[0].
///
template<TargetType T_SELF, MulticastType M, typename V>
template<TargetType K_CHILD>
inline std::vector<Target<K_CHILD, M, V> >
    Target<T_SELF, M, V>::getChildren(const TargetState i_state) const
{
    FAPI_DBG(ENTER_MRK "getChildren. Type 0x%08x State:0x%08x", K_CHILD, i_state);

    // first check if multicast, if it is not multicast then it will evaluate isProperParent
    static_assert((T_SELF & TARGET_TYPE_MULTICAST) || (impl::isProperParent(K_CHILD, T_SELF)),
        "improper unicast child of fapi2::Target, isProperParent failed");
    // next check if it is multicast, then if multicast verify same by upcast K_CHILD
    static_assert(!(T_SELF & TARGET_TYPE_MULTICAST) || (T_SELF == (K_CHILD | TARGET_TYPE_MULTICAST)),
        "improper multicast usage of fapi2::Target, check multicast invocation");
    // next check if it is multicast, then if multicast verify requested K_CHILD is proper type
    static_assert(!(T_SELF & TARGET_TYPE_MULTICAST) || (K_CHILD & TARGET_TYPE_MULTICASTABLE) != 0,
        "improper multicast usage of fapi2::Target, check multicastable invocation");

    std::vector<Target<K_CHILD, M, V>> l_children;
    // Get the platform target type of the current fapi2::target
    TARGETING::TYPE l_type = fapi2::convertFapi2TypeToTargeting(K_CHILD);
    TARGETING::TargetHandleList l_childList;

    bool l_functional = (i_state & fapi2::TARGET_STATE_FUNCTIONAL)? true:false;
    if (T_SELF & TARGET_TYPE_MULTICAST)
    {
        assert(l_functional, "multicast getChildren must be functional, present use case not implemented yet");
        plat_target_handle_t l_handle = this->get();
        l_childList = getMulticastChildren(l_handle, l_type);
    }
    else
    {
        // There is translation required to go from the binary functional
        //  representation of fapi2::TargetState to the trinary state that
        //  we have inside of Hostboot.  For chiplet/subunits, the ekb
        //  code expects TARGET_STATE_PRESENT to represent the architectural
        //  limits of the chip, meaning that we need to include parts marked
        //  as bad in PG.  Since those are marked non-present in TARGETING
        //  we will use the ALL (aka. blueprint) value.  However, for top-level
        //  targets (chips, dimms), PRESENT should represent what is physically
        //  installed.

        TARGETING::ResourceState l_state = l_functional
          ? TARGETING::UTIL_FILTER_FUNCTIONAL
          : TARGETING::UTIL_FILTER_ALL;

        // For any top-level target, we will use PRESENT for !functional
        if( !l_functional &&
            ( (K_CHILD == fapi2::TARGET_TYPE_DIMM)
              || (K_CHILD == fapi2::TARGET_TYPE_PROC_CHIP)
              || (K_CHILD == fapi2::TARGET_TYPE_PMIC)
              || (K_CHILD == fapi2::TARGET_TYPE_GENERICI2CSLAVE)
              || (K_CHILD == fapi2::TARGET_TYPE_OCMB_CHIP) ) )
        {
            l_state = TARGETING::UTIL_FILTER_PRESENT;
        }

        // PERV targets use a special interface
        if(T_SELF == fapi2::TARGET_TYPE_PERV)
        {
            TARGETING::getPervasiveChildTargetsByState(l_childList,
                        FAPI_TO_HBTARG(this),
                        TARGETING::CLASS_NA,
                        l_type,
                        l_state);
        }
        else if(T_SELF == fapi2::TARGET_TYPE_OMIC)
        {
            TARGETING::getChildOmiTargetsByState(l_childList,
                            FAPI_TO_HBTARG(this),
                            TARGETING::CLASS_NA,
                            l_type,
                            l_state);
        }
        else if((T_SELF == fapi2::TARGET_TYPE_PAUC)
                && (K_CHILD == fapi2::TARGET_TYPE_OMIC))
        {
            TARGETING::getChildPaucTargetsByState(l_childList,
                            FAPI_TO_HBTARG(this),
                            TARGETING::CLASS_NA,
                            l_type,
                            l_state);
        }
        // All chiplets need to use ALL so that we report the architectural
        //  limits, versus what PG might say
        else
        {
            TARGETING::getChildAffinityTargetsByState(l_childList,
                            FAPI_TO_HBTARG(this),
                            TARGETING::CLASS_NA,
                            l_type,
                            l_state);
        }
    }
    FAPI_DBG("getChildren: l_functional 0x%.8X, l_type = 0x%.8X, ChipUnitId 0x%.8X",
            l_functional, l_type, TARGETING::get_huid(this->get()));
    FAPI_DBG("getChildren: l_childList size %d", l_childList.size());

    // Return fapi2::Targets to the caller
    for (TARGETING::TargetHandleList::const_iterator
            chipletIter = l_childList.begin();
            chipletIter != l_childList.end();
            ++chipletIter)
    {
        fapi2::Target<K_CHILD, M, V> l_target(*chipletIter);
        l_children.push_back(l_target);
    }
    return l_children;
}

///
/// @brief Get this target's children, filtered
/// @tparam T The type of the parent
/// @tparam T_SELF The type of target on which this is called
/// @tparam V the type of the target's Value
/// @param[in] i_filter The desired chiplet filter
/// @param[in] i_state The desired TargetState of the children
/// @return std::vector<Target<T> > a vector of present/functional
/// children
///
template<TargetType T_SELF, MulticastType M, typename V>
template< TargetType T>
inline std::vector<Target<T, M, V> >
    Target<T_SELF, M, V>::getChildren(const TargetFilter i_filter,
                              const TargetState i_state) const
{
    std::vector<Target<T, M, V>> l_children;

    l_children = this->getChildren<T>(i_state);

    FAPI_DBG("getChildrenFilter: Tgt=0x%.8X, i_filter=0x%.16X,"
             "T_SELF-Type=0x%.8X, T-Type=0x%.8X, sizeA=%d",
             TARGETING::get_huid(this->get()), i_filter,
             T_SELF, T, l_children.size());

    // Limit to getting Pervasive children from proc_chip parent for now
    //@TODO RTC:155755 to track possible additional support
    static_assert(((T == fapi2::TARGET_TYPE_PERV) &&
                   (T_SELF == fapi2::TARGET_TYPE_PROC_CHIP)),
                   "fapi2::getChildren-Filter only supports getting fapi2::TARGET_TYPE_PERV children on a fapi2::TARGET_TYPE_PROC_CHIP");

    for ( auto childIter =  l_children.begin();
               childIter != l_children.end();
               // ++childIter incremented below
        )
    {
        const TARGETING::Target * l_platTarget =
                         static_cast<const TARGETING::Target*>(childIter->get());
        uint8_t  l_chiplet_num = 0;
        uint64_t l_bitMask = 0x0;

        // ATTR_CHIP_UNIT represents the Pervasive Chiplet numbering and is
        // needed to create the l_bitMask to use against i_filter
        if(!l_platTarget->tryGetAttr<TARGETING::ATTR_CHIP_UNIT>(l_chiplet_num))
        {
            FAPI_ERR("ERROR: getChildrenFilter: Can not read CHIP_UNIT attribute"
                     "Keeping Target 0x%lx for 0x%x", l_platTarget, T);
            l_bitMask = 0xFFFFFFFFFFFFFFFF;
        }
        else
        {
            l_bitMask = 0x8000000000000000 >> l_chiplet_num;
        }

        if (i_filter & l_bitMask) // keep child
        {
          FAPI_DBG("getChildrenFilter: keep child=0x%.8X, type=0x%.8X, l_bitMask=0x%.16X, num=0x%.2X",
                   TARGETING::get_huid(l_platTarget), childIter->getType(), l_bitMask, l_chiplet_num );

          ++childIter;
        }
        else // remove child
        {
          childIter = l_children.erase(childIter); // this increments childIter

          FAPI_DBG("getChildrenFilter: removed child=0x%.8X, type=0x%.8X, l_bitMask=0x%.16X, num=0x%.2X",
                   TARGETING::get_huid(l_platTarget), childIter->getType(), l_bitMask, l_chiplet_num );
        }
    }

    // Return filtered fapi2::Targets to the caller
    return l_children;
}

///
/// @brief Get the target at the other end of a bus
/// @tparam T The type of the target on the other end
/// @param[out] o_target A target representing the thing on the other end
/// @param[in] i_state The desired TargetState of the other end
/// @return FAPI2_RC_SUCCESS if OK, platforms will return a non-success
/// ReturnCode in the event of failure
/// @note o_target is only valid if return is FAPI2_RC_SUCCESS
///
template<TargetType T_SELF, MulticastType M, typename V>
template<TargetType T>
inline fapi2::ReturnCodes
Target<T_SELF, M, V>::getOtherEnd(fapi2::Target<T, M, V>& o_target,
                          const TargetState i_state) const
{
    ReturnCodes l_rc;
//     errlHndl_t l_errl = nullptr;
    TARGETING::TargetHandleList l_peerTargetList;
    TARGETING::CLASS targetClass = TARGETING::CLASS_NA;

    // Only supporting these relationships:
    //  IOHS <-> IOHS
    //  IOLINK <-> IOLINK

    static_assert( T_SELF==T, "both ends must be of same fapi2::TARGET_TYPE");
    static_assert ( (T_SELF==fapi2::TARGET_TYPE_IOHS) || (T_SELF==fapi2::TARGET_TYPE_IOLINK),
                    "Only targets of type IOHS or IOLINK are supported");

    // for the supported types above, only one option supported
    targetClass = TARGETING::CLASS_UNIT;

    TARGETING::PredicateCTM l_peerFilter(targetClass,
                                         fapi2::convertFapi2TypeToTargeting(T));

    if(i_state == TARGET_STATE_FUNCTIONAL)
    {
        TARGETING::PredicateIsFunctional l_funcFilter;
        TARGETING::PredicatePostfixExpr l_funcAndpeerFilter;
        l_funcAndpeerFilter.push(&l_peerFilter).push(&l_funcFilter).And();
        getPeerTargets( l_peerTargetList,    // list of targets on other end
        FAPI_TO_HBTARG(this),//To this target
        nullptr, // Don't need to filter peers
        &l_funcAndpeerFilter);//filter results to be the right class & state
    }
    else if(i_state == TARGET_STATE_PRESENT)
    {
        TARGETING::PredicatePostfixExpr l_presAndpeerFilter;
        l_presAndpeerFilter.push(&l_peerFilter);

        getPeerTargets( l_peerTargetList,   // list of targets on other end
        FAPI_TO_HBTARG(this), //to this target
        nullptr,                               //No need to filter peers
        &l_presAndpeerFilter);//filter results to be the right class & state
    }

    fapi2::Target<T, M, V> fapi2_peerTarget(nullptr);

    if(l_peerTargetList.size() == 0)
    {
        l_rc = FAPI2_RC_FALSE;
        //@TODO RTC:150675 get error info from getOtherEnd fails
#if 0
        /*@
        * @errortype          ERRORLOG::ERRL_SEV_UNRECOVERABLE
        * @moduleid           fapi2::MOD_FAPI2_PLAT_GET_OTHER_END
        * @reasoncode         fapi2::RC_FOUND_NO_PEERS
        * @userdata1[0:31]    Unused
        * @userdata1[32:63]   Unused
        * @userdata2          Unused
        * @devdesc            Unable to resolve other end of bus
        */
        l_errl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                      fapi2::MOD_FAPI2_PLAT_GET_OTHER_END,
                                      fapi2::RC_FOUND_NO_PEERS,
                                      nullptr,
                                      nullptr,
                                      true/*SW Error*/);
        // Add the error log pointer as data to the ReturnCode
        addErrlPtrToReturnCode(l_rc, l_errl);
#endif
    }
    else if(l_peerTargetList.size() > 1)
    {
        l_rc = FAPI2_RC_FALSE;
        //@TODO RTC:150675 get error info from getOtherEnd fails
#if 0
        /*@
        * @errortype          ERRORLOG::ERRL_SEV_UNRECOVERABLE
        * @moduleid           fapi2::MOD_FAPI2_PLAT_GET_OTHER_END
        * @reasoncode         fapi2::RC_FOUND_TOO_MANY_PEERS
        * @userdata1[0:31]    Unused
        * @userdata1[32:63]   Unused
        * @userdata2          Unused
        * @devdesc            Unable to resolve other end of bus
        */
        l_errl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                      fapi2::MOD_FAPI2_PLAT_GET_OTHER_END,
                                      fapi2::RC_FOUND_TOO_MANY_PEERS,
                                      nullptr,
                                      nullptr,
                                      true/*SW Error*/);
        // Add the error log pointer as data to the ReturnCode
        addErrlPtrToReturnCode(l_rc, l_err);
#endif
    }
    else
    {
        l_rc = FAPI2_RC_SUCCESS;
        fapi2_peerTarget = fapi2::Target<T>(l_peerTargetList[0]);
    }
    o_target = fapi2_peerTarget;

    return l_rc;
}



///
/// @brief Determine whether the target is functional or not
/// @return true if the target is functional, false otherwise
///
template< TargetType T_SELF, MulticastType M, typename V >
inline bool Target< T_SELF, M, V >::isFunctional(void) const
{
    TARGETING::PredicateIsFunctional l_functional;
    return l_functional(FAPI_TO_HBTARG(this));
}


///
/// @brief Return the string interpretation of this target
/// @tparam T The type of the target
/// @param[in] i_target Target<T>
/// @param[in/out] io_buffer buffer to write in to
/// @param[in] i_bsize size of the buffer
/// @return void
/// @post The contents of the buffer is replaced with the string
/// representation of the target
///
template< TargetType T, MulticastType M, typename V >
inline void toString(const Target<T, M, V>& i_target, char* io_buffer, size_t i_bsize)
{
    TARGETING::ATTR_FAPI_NAME_type l_nameString = {0};
    const TARGETING::Target * l_platTarget =
                          static_cast<const TARGETING::Target*>(i_target.get());

    if( nullptr == l_platTarget )
    {
        snprintf(io_buffer,i_bsize,"null_target");
    }
    else if(!l_platTarget->tryGetAttr<TARGETING::ATTR_FAPI_NAME>(l_nameString))
    {
      FAPI_ERR("ERROR: Can not read FAPI_NAME attribute");
      snprintf(io_buffer, i_bsize, "Target 0x%lx/0x%x", l_platTarget, T);
    }
    else
    {
      size_t needed_buffer_size = strlen((const char*)l_nameString) + 1;

      // Is i_buffer large enough for the entire string + null
      if (i_bsize < needed_buffer_size)
      {
        FAPI_INF("Should use a larger buffer size (%d instead of %d) for %s",
                  needed_buffer_size, i_bsize, l_nameString);
        memcpy(io_buffer, l_nameString, i_bsize);
        if (i_bsize > 0)
        {
          io_buffer[i_bsize-1] = '\0';
        }
      }
      else
      {
        // copy full attribute string + null character
        memcpy(io_buffer, l_nameString, needed_buffer_size);
      }
    }
}

///
/// @brief Return the string interpretation of this target
/// @tparam T The type of the target
/// @param[in] A pointer to the Target<T>
/// @param[in/out] io_buffer buffer to write in to
/// @param[in] i_bsize size of the buffer
/// @return void
/// @post The contents of the buffer is replaced with the string
/// representation of the target
///
template< TargetType T, MulticastType M, typename V >
inline void toString(const Target<T, M, V> *i_target, char* io_buffer, size_t i_bsize)
{
    toString(*i_target, io_buffer, i_bsize);
}
///
/// @brief Get a target from its Type and instance info
/// @tparam T The type of the target to return
/// @tparam V type of the targets value
/// @param[in] i_type   - Type of target to find
/// @param[in] instance - instance of the target to find
///
/// @return Target<T>* pointer to a target of type T
///
/// NOTE: Function caller owns the object returned.
///
#ifdef FAPI2_ENABLE_PLATFORM_GET_TARGET
template<TargetType T, MulticastType M=MULTICAST_OR,
    typename V=fapi2::plat_target_handle_t>
inline Target<T, M, V>* getTarget(TargetType i_type, uint8_t instance)
{

    Target<T, M, V> * l_target = nullptr;

    TARGETING::TYPE l_type = convertFapi2TypeToTargeting(i_type);

    // get a list of all the targets
    TARGETING::TargetService& l_targetService = TARGETING::targetService();
    TARGETING::TargetRangeFilter l_targets(l_targetService.begin(),
                                 l_targetService.end());

    // create a check for the desired target type
    TARGETING::PredicateCTM l_typePredicate;

    l_typePredicate.setType(l_type);

    // create a check for the FAPI_POS of a target
    TARGETING::PredicateAttrVal<TARGETING::ATTR_FAPI_POS>
                               l_fapiPosAttr(instance);

    TARGETING::PredicatePostfixExpr l_Query;

    // look for the type and instance
    l_Query.push(&l_typePredicate).push(&l_fapiPosAttr).And();

    l_targets.setPredicate(&l_Query);

    // reset l_targets to contain only the targets matching our predicates
    l_targets.reset();

    TARGETING::Target * l_t = nullptr;

    uint32_t l_count = 0;
    for(; l_targets; ++l_targets, ++l_count)
    {
        l_t = *l_targets;
    }

    // we should not find more than one target
    assert(!(l_count > 1));

    if(l_count == 1)
    {
        l_target = new fapi2::Target<T, M, V>(l_t);
    }

    return l_target;

}
#endif
/// @tparam T The type of the target
/// @param[in] Ordinal representing the ordinal number of
/// the desired target
/// @return Target<T> the target requested
///
template<TargetType T, MulticastType M, typename V>
inline Target<T, M, V> getTarget(uint64_t i_ordinal_id )
{
    uint16_t  l_fapi_pos = 0;
    TARGETING::Target * l_platTarget = nullptr;

    // get the top-level target
    TARGETING::Target * l_pSys;
    TARGETING::targetService().getTopLevelTarget(l_pSys);
    TARGETING::PredicateCTM l_tPred(TARGETING::CLASS_NA,
           fapi2::convertFapi2TypeToTargeting(T));

    // get a list of all targets of type T
    TARGETING::TargetHandleList l_TargetList;
    TARGETING::targetService().getAssociated( l_TargetList, l_pSys,
           TARGETING::TargetService::CHILD,
           TARGETING::TargetService::ALL,
           &l_tPred);

    if (!l_TargetList.empty())
    {
        FAPI_DBG("getTarget: Ordinal: %.8X", i_ordinal_id );

        // Iterate through all targets and find out matching
        // FAPI_POS target
        for( auto & l_target_elem : l_TargetList)
        {
            l_fapi_pos = l_target_elem->getAttr<TARGETING::ATTR_FAPI_POS>();
            if (l_fapi_pos == i_ordinal_id )
            {
                l_platTarget = l_target_elem;

                FAPI_DBG("getTarget() - FAPI_POS: (%.8X) HUID: (%.8X)",
                      l_fapi_pos,
                      TARGETING::get_huid(l_target_elem));
                break;
            }
        }
    }

    // Target list is empty or Target of Ordinal not Found
    if (l_platTarget == nullptr)
    {
        FAPI_ERR("getTarget(): empty TargetList of T or Target of Ordinal not Found");
        assert(false);
    }

    // Create a fapi2 target & return
    Target<T, M, V> l_fapi2_target(l_platTarget);
    return l_fapi2_target;
}

///
/// @brief Returns the chiplet number associated with the Target
/// @return The chiplet number for the Target. 0 is returned if the
/// Target does not have a chiplet number (for ex, the PROC_CHIP Target)
/// @note For logical targets such as the FC, the chiplet number of
/// their immediate parent chiplet is returned
///
template< TargetType T_SELF, MulticastType M, typename V >
inline uint8_t Target< T_SELF, M, V >::getChipletNumber(void) const
{
    const TARGETING::Target * l_pTarget =
        FAPI_TO_HBTARG(this);
    uint8_t  l_chiplet_id = 0;
    if(!l_pTarget->tryGetAttr<TARGETING::ATTR_CHIPLET_ID>(l_chiplet_id))
    {
        FAPI_ERR("ERROR: getChipletNumber: Can not read CHIPLET_ID attribute");
    }
    return l_chiplet_id;
}


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
template<TargetType K, MulticastType M, typename V>
template< TargetType T>
inline ReturnCodes
Target<K, M, V>::reduceType(Target<T, M, V>& o_target) const
{
    // call the builtin checker first
    check_reduceType<T>();

    // Hostboot's targets are never composite so all we need to do is to confirm
    // that the desired type matches the type we really are
    TARGETING::Target* l_hbTarget = FAPI_TO_HBTARG(this);
    TARGETING::TYPE l_type = fapi2::convertFapi2TypeToTargeting(T);
    if( l_type != l_hbTarget->getAttr<TARGETING::ATTR_TYPE>() )
    {
        FAPI_ERR("reduceType(): Cannot reduce to %X for target %.8X",
                 l_type, TARGETING::get_huid(l_hbTarget));
        return FAPI2_RC_INVALID_PARAMETER;
    }

    // seed the target to complete the transformation
    o_target = Target < T, M, V > (this->get());
    return FAPI2_RC_SUCCESS;
}

///
/// @brief Get a multicast target for a given chip
/// @tparam T The type of target to return; TARGET_TYPE_MULTICAST is added
///           automatically
/// @tparam O The type of multicast read operation for the target;
///         defaults to OR
/// @param[in] i_group The abstract multicast group the target should point to
/// @return The multicast target
///
template< TargetType K, MulticastType M, typename V>
template< TargetType T, MulticastType O >
inline Target<T | TARGET_TYPE_MULTICAST, O, V>
Target<K, M, V>::getMulticast(const MulticastGroup i_group) const
{
    static_assert((K == TARGET_TYPE_PROC_CHIP), "Parent target must be the proc chip");
    static_assert((T & TARGET_TYPE_MULTICASTABLE) != 0,
                  "Requested target type must be part of TARGET_TYPE_MULTICASTABLE");
    static_assert(bitCount<T>::count == 1,
                  "Requested target type must be a single type, TARGET_TYPE_MULTICAST will be added automatically");
    // The "internal" multicast target is the target on which getMulticast is
    // called (a PROC_CHIP target). The multicast operation will always execute
    // against the proc.
    plat_target_handle_t l_target(this->iv_handle,
            true, // multicast
            i_group,
            O); // Multicast op
    return l_target;
}

///
/// @brief Get a multicast core target for a given chip
/// @tparam O The type of multicast read operation for the target;
///           defaults to OR
/// @param[in] i_group The abstract multicast group (selecting EQs) the target
///                    should point to
/// @param[in] i_cores Which cores inside the selected EQ should be targeted
/// @return The multicast target
///
template< TargetType K, MulticastType M, typename V>
template< MulticastType O >
inline Target<TARGET_TYPE_CORE | TARGET_TYPE_MULTICAST, O, V>
Target<K, M, V>::getMulticast(const MulticastGroup i_group, const MulticastCoreSelect i_cores) const
{
    static_assert((K == TARGET_TYPE_PROC_CHIP), "Parent target must be the proc chip");

    // The "internal" multicast target is the target on which getMulticast is
    // called (a PROC_CHIP target). The multicast operation will always execute
    // against the proc.
    plat_target_handle_t l_target(this->iv_handle,
                                  true, // multicast
                                  i_group,
                                  O, // Multicast op
                                  i_cores);

    return l_target;
}

///
/// @brief Get the multicast core select value for a given target
///
/// @Tparam K the type (Kind) of target
/// @Tparam M the type of multicast operation if it's a multicast target
/// @Tparam V the type of the target's value
///
/// @return the multicast core select value for the target
///
template<TargetType K, MulticastType M, typename V>
inline MulticastCoreSelect
Target<K, M, V>::_getCoreSelect(void) const
{
    return this->iv_handle.getCoreSelect();
}

} // End namespace fapi2

#endif // End __FAPI2_TARGET__
