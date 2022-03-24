/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/targeting/common/predicates/predicatelogic.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2022                             */
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

#ifndef PREDICATE_LOGIC_H
#define PREDICATE_LOGIC_H

/* @brief
 *
 * Implementation of logical operators for HWAS predicates. This utility
 * makes reading and writing HWAS predicates easier. For example:
 *
 *  checkExpr.push(&predChip).push(&predDimm).Or().push(&predEnc).Or()
 *           .push(&predMux).Not().And();
 *
 * becomes
 *
 *  checkExpr <<= (predChip || predDimm || predEnc) && !predMux
 *
 * and
 *
 *  l_presentChildren.push(&l_procFilter).push(&l_memFilter).Or().
 *                    push(&l_pciFilter).Or().push(&l_psFilter).Or().
 *                    push(&l_fanFilter).Or().push(&l_uartFilter).Or().
 *                    push(&l_usbFilter).Or().push(&l_ethFilter).Or().
 *                    push(&l_vrmFilter).Or().push(&l_dimmFilter).Or().
 *                    push(&l_predHwas).And();
 *
 * becomes
 *
 *  l_presentChildren <<= ((l_procFilter || l_memFilter || l_pciFilter || l_psFilter || l_fanFilter
 *                          || l_uartFilter || l_usbFilter || l_ethFilter || l_vrmFilter || l_dimmFilter)
 *                         && l_predHwas)
 *
 * This transformation is done completely at compile-time; the compiler reduces
 * the operator-based form to the same code as the explicit function call style.
 *
 * To use the operators, add a
 *
 *  using namespace TARGETING::PREDICATE_LOGIC_OPERATORS;
 *
 * statement to the scope you're working in.
 */

// This library is only available in non-FSPBUILD configurations. If someone
// wants to go through the pain of adding this file their source control, be my
// guest.
#ifndef CONFIG_FSP_BUILD

#include <builtins.h>
#include "predicatepostfixexpr.H"

namespace TARGETING
{

namespace PREDICATE_LOGIC_OPERATORS
{

namespace PREDICATE_LOGIC_OPERATORS_IMPL
{

/* @brief gcompile
 *
 * Invoke the "compile" member function on the argument if it's a
 * PredicateLogicX type, or push it onto the stack if it's a PredicateBase
 * type. The "compile" functions will assemble the logical tree into postfix
 * expression form. These global function overloads let us use logical operators
 * on the base predicate types (e.g. X && Y where X and Y are predicates
 * inheriting from PredicateBase) and also on the results of logical operations
 * (e.g. (X && Y) && Z).
 */

template<typename T>
inline ALWAYS_INLINE auto gcompile(const T& i_logic, PredicatePostfixExpr& o_pfe) -> decltype(i_logic.compile(o_pfe))
{
    return i_logic.compile(o_pfe);
}

inline ALWAYS_INLINE void gcompile(const PredicateBase& i_pred, PredicatePostfixExpr& o_pfe)
{
    o_pfe.push(&i_pred);
}

/* These classes represent logical operations on HWAS predicates. A chain of
 * logical operators (e.g. A && B && C) essentially builds up a tree of these
 * structures (i.e. PredicateLogicAnd(PredicateLogicAnd(A, B), C)) which is then
 * used to call the actual functions on the PredicatePostfixExpr
 * (i.e. pfe.push(A).push(B).And().push(C).And()) */

template<typename Lhs, typename Rhs>
struct PredicateLogicAnd
{
    PredicateLogicAnd(const Lhs& i_lhs, const Rhs& i_rhs) : iv_lhs(i_lhs), iv_rhs(i_rhs) { }

    /* @brief Compile the current HWAS predicate into a PredicatePostfixExpr
     *
     * @param[out] o_pfe  The PredicatePostfixExpr to compile the expression into
     */
    void compile(PredicatePostfixExpr& o_pfe) const ALWAYS_INLINE
    {
        gcompile(iv_lhs, o_pfe);
        gcompile(iv_rhs, o_pfe);
        o_pfe.And();
    }

    const Lhs& iv_lhs;
    const Rhs& iv_rhs;
};

template<typename Lhs, typename Rhs>
struct PredicateLogicOr
{
    PredicateLogicOr(const Lhs& i_lhs, const Rhs& i_rhs) : iv_lhs(i_lhs), iv_rhs(i_rhs) { }

    void compile(PredicatePostfixExpr& o_pfe) const ALWAYS_INLINE
    {
        gcompile(iv_lhs, o_pfe);
        gcompile(iv_rhs, o_pfe);
        o_pfe.Or();
    }

    const Lhs& iv_lhs;
    const Rhs& iv_rhs;
};

template<typename Op>
struct PredicateLogicNot
{
    PredicateLogicNot(const Op& i_op) : iv_op(i_op) { }

    void compile(PredicatePostfixExpr& o_pfe) const ALWAYS_INLINE
    {
        gcompile(iv_op, o_pfe);
        o_pfe.Not();
    }

    const Op& iv_op;
};

/* These are helpers to make sure that our operators only work with the types
 * they're meant to work with, rather than with every type. Using them anywhere
 * in the signature of a function will ensure that the given types are predicate
 * types (i.e. either PredicateLogicX structs or PredicateBase derivatives). */

template<typename T, typename Unused = decltype(gcompile(std::declval<T>(), std::declval<PredicatePostfixExpr&>()))>
struct is_predicate_type
{
    static constexpr bool value = true;
};

template<typename T, typename T2>
using both_are_predicate_types = typename std::enable_if<is_predicate_type<T>::value && is_predicate_type<T2>::value, void>::type;

/* These logical operator overloads just construct instances of the relevant
 * PredicateLogicX structures. The "Unused" template parameter is present to
 * ensure that the overload is only viable for predicate types, rather than all
 * types; otherwise these overloads would let you take any values of any types
 * and AND/OR/NOT them and it would compile, which we don't want. */

template<typename Lhs, typename Rhs, typename Unused = both_are_predicate_types<Lhs, Rhs>>
inline ALWAYS_INLINE PredicateLogicAnd<Lhs, Rhs>
operator&&(const Lhs& i_lhs, const Rhs& i_rhs)
{
    return { i_lhs, i_rhs };
}

template<typename Lhs, typename Rhs, typename Unused = both_are_predicate_types<Lhs, Rhs>>
inline ALWAYS_INLINE PredicateLogicOr<Lhs, Rhs>
operator||(const Lhs& i_lhs, const Rhs& i_rhs)
{
    return { i_lhs, i_rhs };
}

template<typename Op, typename Unused = is_predicate_type<Op>>
inline ALWAYS_INLINE PredicateLogicNot<Op>
operator!(const Op& i_op)
{
    return { i_op };
}

template<typename Op>
inline ALWAYS_INLINE void operator<<=(PredicatePostfixExpr& o_pfe, Op&& i_logic)
{
    i_logic.compile(o_pfe);
}

}

// Pull the operators into this user-facing namespace.
using PREDICATE_LOGIC_OPERATORS_IMPL::operator&&;
using PREDICATE_LOGIC_OPERATORS_IMPL::operator||;
using PREDICATE_LOGIC_OPERATORS_IMPL::operator!;
using PREDICATE_LOGIC_OPERATORS_IMPL::operator<<=;

}

}

#endif // #ifndef CONFIG_FSP_BUILD
#endif // #ifndef PREDICATE_LOGIC_H
