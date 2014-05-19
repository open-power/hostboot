/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/targeting/common/predicates/predicatepostfixexpr.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2011,2014              */
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

#ifndef __TARGETING_COMMON_PREDICATEPOSTFIXEXPR_H
#define __TARGETING_COMMON_PREDICATEPOSTFIXEXPR_H

/**
 *  @file targeting/common/predicatepostfixexpr.H
 *
 *  @brief Interface for predicate which allows callers to chain multiple other
 *      predicates together in complex logical expressions, and then evaluate
 *      them against a target
 */

//******************************************************************************
// Includes
//******************************************************************************

// STD
#include <vector>

// Other Host Boot Components

// Targeting Component
#include <targeting/common/predicates/predicatebase.H>

//******************************************************************************
// Macros
//******************************************************************************

#undef TARG_NAMESPACE
#undef TARG_CLASS
#undef TARG_FN

//******************************************************************************
// Interface
//******************************************************************************

namespace TARGETING
{

#define TARG_NAMESPACE "TARGETING::"
#define TARG_CLASS "PredicatePostfixExpr::"

class Target;

/**
 *  @brief Predicate which can compute aribtrarily complex logical expressions
 *      of other predicates using postfix notation
 */
class PredicatePostfixExpr : public PredicateBase
{
    public:

        /**
         *  @brief Create empty postfix predicate expression which will always
         *      evaluate true if not otherwise modified.  Any updates to the
         *      expression completely replace the initial "always true"
         *      behavior.
         */
        PredicatePostfixExpr();

        /**
         *  @brief Destroy a postfix predicate expression
         *
         *  @note: Nothing extra to do here since object does not own the
         *      predicates
         */
        virtual ~PredicatePostfixExpr();

        /**
         *  @brief Updates the postfix predicate expression by pushing the given
         *      predicate onto the expression stack
         *
         *  @param[in] i_pPredicate Pointer to existing concrete predicate.
         *      Passing a NULL predicate is not allowed (results in assert)
         *
         *  @verbatim
         *      Example:
         *
         *      Stack before calling push(&P2): P1
         *      Stack after calling push(&P2):  P1 P2
         *  @endverbatim
         *
         *  @return Reference to the same predicate expression, for chaining
         */
        PredicatePostfixExpr& push(
            const PredicateBase* i_pPredicate);

        /**
         *  @brief Updates the postfix predicate expression by pushing the
         *      logical "AND" operation onto the expression stack.
         *
         *  @verbatim
         *      Example:
         *
         *      Stack before calling And(): P1 P2
         *      Stack after calling And():  P1 P2 AND
         *      Stack after evaluation:     (P1 && P2)
         *  @endverbatim
         *
         *  @return Reference to the same predicate expression, for chaining
         */
        PredicatePostfixExpr& And();

        /**
         *  @brief Updates the postfix predicate expression by pushing the
         *      logical "NOT" operation onto the expression stack.
         *
         *  @verbatim
         *      Example:
         *
         *      Stack before calling Not(): P1
         *      Stack after calling Not():  P1 NOT
         *      Stack after evaluation:     (!P1)
         *  @endverbatim
         *
         *  @return Reference to the same predicate expression, for chaining
         */
        PredicatePostfixExpr& Not();

        /**
         *  @brief Updates the postfix predicate expression by pushing the
         *      logical "OR" operation onto the expression stack.
         *
         *  @verbatim
         *      Example:
         *
         *      Stack before calling Or(): P1 P2
         *      Stack after calling Or():  P1 P2 OR
         *      Stack after evaluation:    (P1 || P2)
         *  @endverbatim
         *
         *  @return Reference to the same predicate expression for chaining
         */
        PredicatePostfixExpr& Or();

        /**
         *  @brief Returns whether the given target matches the criteria
         *      specified by the postfix predicate expression
         *
         *  @par Detailed Description:
         *      Returns whether the given target matches the criteria
         *      specified by the postfix predicate expression.  The routine
         *      sequentially evaluates a predicate against the supplied target
         *      or applies a logical operation to one or more prior predicate
         *      evaluations using a postfix algorithm.  Routine will assert
         *      if postfix expression is not formatted properly, final result
         *      stack does not have exactly one result, target is NULL, or
         *      invalid logical operator was requested.  See PredicateBase class
         *      for parameter/return description.
         *
         *  @verbatim
         *      Example:
         *
         *      PredicatePostfixExpr l_expr;
         *      l_expr.push(&P1).push(&P2).Or().push(&P3).And().Not();
         *
         *      Equivalent infix expression: !((P1 || P2) && P3)
         *      Assume predicate results of: P1 = 0, P2 = 1, P3 = 0
         *      Expression stack prior to evaluation: P1 P2 OR P3 AND NOT
         *      Evaluation step 1: 1 P3 AND NOT (evaluated P1 P2 OR)
         *      Evaluation step 2: 0 NOT (evaluated 1 P3 AND)
         *      Evaluation step 3: 1 (evaluated 0 NOT; final result)
         *  @endverbatim
         *
         *  @param[in] i_pTarget
         *      Handle of the target to evaluate the expression against
         *
         *  @return bool indicating whether the expression is true or no
         */
        virtual bool operator()(
            const Target* i_pTarget) const;

    private:

        static const uint64_t ALREADY_EVALUATED_UPPER_BOUND = 1;

        bool alreadyEvaluated(const uint64_t i_stackItem) const
        {
            return(i_stackItem <= ALREADY_EVALUATED_UPPER_BOUND);
        }

        /**
         *  @brief Enumeration describing the type of logical operator to
         *      apply to one or more previous predicate evaluations
         */
        enum LogicalOperator
        {
            EVAL, ///< Special logical operator - evaluate a predicate
            AND,  ///< Logically AND the result of the preceding two evaluations
            OR,   ///< Logically OR the result of the preceding two evaluations
            NOT,  ///< Logically negate the result of the preceding evaluation
        };

        /**
         *  @brief Structure describing one unit of the postfix predicate
         *      expression under evaluation
         */
        struct Operation
        {
            LogicalOperator      logicalOp;  ///< Logical operator to
                                             ///< apply to result stack
            const PredicateBase* pPredicate; ///< Predicate to evaluate,
                                             ///< if logicalOp == EVAL
        };

        std::vector<Operation> iv_ops; ///< Expression operations to perform

        TARG_DISABLE_COPY_AND_ASSIGNMENT_OPERATORS(PredicatePostfixExpr);
};

#undef TARG_CLASS
#undef TARG_NAMESPACE

} // End namespace TARGETING

#endif // __TARGETING_COMMON_PREDICATEPOSTFIXEXPR_H
