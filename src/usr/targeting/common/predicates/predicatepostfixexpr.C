/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/targeting/common/predicates/predicatepostfixexpr.C $  */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2011,2013              */
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

/**
 *  @file targeting/common/predicates/predicatepostfixexpr.C
 *
 *  @brief Implementation for predicate which allows callers to chain multiple
 *      other predicates together in complex logical expressions, and then
 *      evaluate them against a target
 */

//******************************************************************************
// Includes
//******************************************************************************

// STD

// Other Host Boot Components
#include <targeting/adapters/assertadapter.H>

// Targeting Component
#include <targeting/common/predicates/predicates.H>
#include <targeting/common/trace.H>

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

//******************************************************************************
// PredicatePostfixExpr::PredicatePostfixExpr
//******************************************************************************

PredicatePostfixExpr::PredicatePostfixExpr()
{
}

//******************************************************************************
// PredicatePostfixExpr::~PredicatePostfixExpr
//******************************************************************************

PredicatePostfixExpr::~PredicatePostfixExpr()
{
}

//******************************************************************************
// PredicatePostfixExpr::push
//******************************************************************************

PredicatePostfixExpr& PredicatePostfixExpr::push(
    const PredicateBase* const i_pPredicate)
{
    #define TARG_FN "push(...)"

    TARG_ASSERT(i_pPredicate != NULL,
           TARG_LOC "Caller supplied a NULL predicate");
    Operation l_op = {EVAL,i_pPredicate};
    iv_ops.push_back(l_op);
    return *this;

    #undef TARG_FN
}

//******************************************************************************
// PredicatePostfixExpr::And
//******************************************************************************

PredicatePostfixExpr& PredicatePostfixExpr::And()
{   
    #define TARG_FN "And()"

    Operation l_op = {AND,NULL};
    iv_ops.push_back(l_op);
    return *this;

    #undef TARG_FN
}

//******************************************************************************
// PredicatePostfixExpr::Not
//******************************************************************************

PredicatePostfixExpr& PredicatePostfixExpr::Not()
{
    #define TARG_FN "Not()"

    Operation l_op = {NOT,NULL};
    iv_ops.push_back(l_op);
    return *this;

    #undef TARG_FN
}

//******************************************************************************
// PredicatePostfixExpr::Or
//******************************************************************************

PredicatePostfixExpr& PredicatePostfixExpr::Or()
{
    #define TARG_FN "Or()"

    Operation l_op = {OR,NULL};
    iv_ops.push_back(l_op);
    return *this;

    #undef TARG_FN
}

//******************************************************************************
// PredicatePostfixExpr::operator()
//******************************************************************************

bool PredicatePostfixExpr::operator()(
    const Target* const i_pTarget) const 
{
    #define TARG_FN "operator()(...)"
   
    TARG_ASSERT(i_pTarget != NULL,
           TARG_LOC "Caller supplied a NULL target");
  
    std::vector<bool> l_stack;
    bool l_result = false;

    for (std::vector<Operation>::const_iterator
            opsIter = iv_ops.begin();
            opsIter != iv_ops.end();
            ++opsIter)
    {
        switch((*opsIter).logicalOp)
        {
            case EVAL:
                l_stack.push_back((*(*opsIter).pPredicate)(i_pTarget));
                break;
            case AND:
                TARG_ASSERT(l_stack.size() >= 2,
                       TARG_LOC "Stack for AND must be >=2 but is %d",
                       l_stack.size());              
                l_result = l_stack.back();
                l_stack.pop_back();
                l_stack.back() = (l_stack.back() & l_result);
                break;
            case OR:
               TARG_ASSERT(l_stack.size() >= 2,
                       TARG_LOC "Stack for OR must be >= 2 but is %d",
                       l_stack.size());    
                l_result = l_stack.back();
                l_stack.pop_back();
                l_stack.back() = (l_stack.back() | l_result);
                break;
            case NOT:
                TARG_ASSERT(l_stack.size() >= 1,
                       TARG_LOC "Stack for NOT must be >= 1 but is %d",
                       l_stack.size());
                l_stack.back() = !l_stack.back();
                break;
           default:
                TARG_ASSERT(0,
                       TARG_LOC "Attempted to evaluate unsupported "
                       "logical operation %d",
                       (*opsIter).logicalOp);
                break;
        }
    }

    // If no predicates and we haven't asserted (no misformatting), element 
    // should be returned
    if(l_stack.size() == 0) 
    {
        l_result = true;
    }
    else
    {
        TARG_ASSERT(l_stack.size() == 1,
               TARG_LOC "Postfix expression created incorrectly. Stack "
               "size should be 1 but is %d",
               l_stack.size());

        l_result = l_stack.front();
    }

    return l_result;

    #undef TARG_FN
}

#undef TARG_CLASS
#undef TARG_NAMESPACE

} // End namespace TARGETING

