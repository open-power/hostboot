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
    ALWAYS_INLINE    
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
    ALWAYS_INLINE
    mem_ptr_to_unary_function<_ARG, _RESULT, _CLASS> 
    mem_ptr_fun(_CLASS& o, _RESULT (_CLASS::*f)(_ARG))
    {
	return mem_ptr_to_unary_function<_ARG,_RESULT,_CLASS>(o, f);
    }

#define MEM_PTR_FUN1_T(CLASS_T, ARG_T, RESULT_T) \
	    mem_ptr_to_unary_function<ARG_T, RESULT_T, CLASS_T>

};

#endif
