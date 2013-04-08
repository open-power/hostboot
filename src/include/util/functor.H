/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/util/functor.H $                                  */
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
#ifndef __UTIL_FUNCTOR_H
#define __UTIL_FUNCTOR_H

#include <builtins.h>

namespace Util
{
    template <typename _ARG, typename _RESULT>
    class unary_functor
    {
	public:
	    typedef _ARG argument_type;
	    typedef _RESULT result_type;

	public:
	    virtual ~unary_functor() {};
	    virtual result_type operator()(argument_type) = 0;
    };

    template <typename _ARG1, typename _ARG2, typename _RESULT>
    class binary_functor
    {
	public:
	    typedef _ARG1 first_argument_type;
	    typedef _ARG2 second_argument_type;
	    typedef _RESULT result_type;

	public:
	    virtual ~binary_functor() {};
	    virtual result_type operator()
		(first_argument_type, second_argument_type) = 0;
    };

    // Function pointer wrappers for functors.

    template <typename _ARG, typename _RESULT>
    class ptr_to_unary_function : public unary_functor<_ARG, _RESULT>
    {
	public:
	    typedef _RESULT(*function_type)(_ARG);

	private:
	    function_type function;

	public:
	    ptr_to_unary_function(function_type f) : function(f) {};


	    _RESULT operator()(_ARG t)
		{
		    return function(t);
		}
    };

    template <typename _ARG, typename _RESULT>
    ALWAYS_INLINE inline
    ptr_to_unary_function<_ARG, _RESULT> ptr_fun(_RESULT (*f)(_ARG))
    {
	return ptr_to_unary_function<_ARG,_RESULT>(f);
    }

#define PTR_FUN1_T(ARG_T, RESULT_T) \
	    ptr_to_unary_function<_ARG, _RESULT>


    template <typename _ARG, typename _RESULT, typename _CLASS>
    class mem_ptr_to_unary_function : public unary_functor<_ARG, _RESULT>
    {
	public:
	    typedef _CLASS member_type;
	    typedef _RESULT(member_type::*function_type)(_ARG);

	private:
	    member_type& object;
	    function_type function;

	public:
	    mem_ptr_to_unary_function(member_type& o, function_type f)
		: object(o), function(f) {};

	    _RESULT operator()(_ARG t)
	    {
		return (object.*function)(t);
	    }
    };

    template <typename _ARG, typename _RESULT, typename _CLASS>
    ALWAYS_INLINE inline
    mem_ptr_to_unary_function<_ARG, _RESULT, _CLASS>
    mem_ptr_fun(_CLASS& o, _RESULT (_CLASS::*f)(_ARG))
    {
	return mem_ptr_to_unary_function<_ARG,_RESULT,_CLASS>(o, f);
    }

#define MEM_PTR_FUN1_T(CLASS_T, ARG_T, RESULT_T) \
	    mem_ptr_to_unary_function<ARG_T, RESULT_T, CLASS_T>

};

#endif
