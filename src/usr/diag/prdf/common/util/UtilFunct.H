/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/util/UtilFunct.H $                   */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2005,2013              */
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

/** @file UtilFunct.H
 * Utility template classes for doing functional-style programming across
 * iterators.
 */
#ifndef __UTIL_UTILFUNCT_H
#define __UTIL_UTILFUNCT_H

#include <functional>

namespace PRDF
{

namespace Util
{
    /**
     * @class unary_input
     * Functor that will read a value from a stream; useful for "generate"
     * algorithms such as std::generate_n.
     */
    template <typename Type,
              typename Stream>
    struct unary_input :
        public std::unary_function<void, Type>
    {
        Stream & stream;

        /**
         * @fn unary_input(Stream & i)
         * Constructor
         *
         * @param i : The stream to read from.
         */
        unary_input(Stream & i) : stream(i) {};

        /**
         * @fn operator()
         * Read instance of 'Type' from stream.
         *
         * Overloaded () operator to implement the functor-style behavior.
         */
        Type operator() ()
        {
            Type t;
            stream >> t;
            return t;
        };

    };

    /**
     * @class unary_compose
     * Functor that will compose two functors as in: 'f(g(x))'.
     *
     * This template is an SGI extension to the STL, not currently in the C++
     * standard.  Since it is currently an extension, define it in our Util
     * namespace for portability.
     *
     * Note: This is a clean implementation of the template, not a copy of the
     * SGI code, based on the SGI::STL documentation.
     */
    template <typename Unary1,
              typename Unary2>
    struct unary_compose :
        public std::unary_function<typename Unary2::argument_type,
                                   typename Unary1::result_type>
    {
        Unary1 u1;
        Unary2 u2;

        /**
         * @fn unary_compose(Unary1 & i1, Unary2 & i2)
         * Constructor
         *
         * @param i1 : f functor in f(g(x)).
         * @param i2 : g functor in f(g(x)).
         */
        unary_compose(const Unary1 & i1,
                      const Unary2 & i2) : u1(i1), u2(i2) {};

        /**
         * @fn operator()
         * Execute f(g(x)).
         *
         * Overloaded () operator to implement the functor-style behavior.
         */
        typename Unary1::result_type
        operator() (typename Unary2::argument_type x)
        {
            return u1(u2(x));
        };

    };

    /**
     * @fn unary_compose
     * Utility template function to automatically create a composition functor.
     */
    template <typename Unary1,
              typename Unary2>
    inline
    unary_compose<Unary1, Unary2> compose1(const Unary1 & i1,
                                           const Unary2 & i2)
    {
        return unary_compose<Unary1, Unary2>(i1, i2);
    };

    /**
     * @class unary_null.
     * Functor that will do nothing.
     *
     * Useful in combination with compose for dropping a return from another
     * functor.
     */
    template <typename Type>
    struct unary_null :
        public std::unary_function<Type, void>
    {
        unary_null() {};
        void operator() (Type i) {};
    };

};

} // end namespace PRDF

#endif

