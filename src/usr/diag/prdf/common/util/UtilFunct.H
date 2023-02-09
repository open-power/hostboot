/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/util/UtilFunct.H $                   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2005,2023                        */
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
};

} // end namespace PRDF

#endif

