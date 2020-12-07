/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/util/memoize.H $                                  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2020                        */
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

#ifndef __UTIL_MEMOIZE_H
#define __UTIL_MEMOIZE_H

#include <map>

namespace Util
{

namespace Memoize
{

/**
 *  @brief Wraps a function (which accepts an input/output parameter pair and
 *      returns a result) with a memoizer
 *
 *  @par Detailed Description:
 *      This template wraps a candidate function with a memoizer, a facility
 *      which caches the result for every unique input.  If an input arrives
 *      that already has a cached result, the result is returned without the
 *      overhead of calling the function, thereby increasing performance.
 *      See warning section for caveats.
 *
 *  @warning: Must only be used if:
 *      - Called only in single-threaded context (cache is not mutex protected)
 *      - All possible inputs are guaranteed to be unique
 *      - For a given input, the result is always the same
 *
 *  @tparam InputType  The memoized function's input type
 *  @tparam OutputType The memoized function's output type
 *  @param[in] i_fn Function pointer referencing the function to memoize
 *  @param[in] i_in Input to the memoized function
 *  @param[out] o_out Output of the memoized function.  The memoizer does not
 *      alter the output on failure; Caller should default the value as
 *      appropriate to anticipate that case.
 *  @return Value indicating success or failure
 *  @retval NULL Result was already computed for the given input and was
 *      returned in the output parameter -otherwise- real function returned
 *      a value that was cached and returned in the output parameter
 *  @retval !NULL Call to memoized function failed.  Result was not cached and
 *      the output value remains unchanged
 *  @note: Could be improved to return a lambda function and use
 *      std::function in place of function pointers if std::function was
 *      implemented
 */
template < class ReturnType, class InputType , class OutputType >
ReturnType memoize(
    ReturnType (*i_fn)(InputType,OutputType&),
    InputType    i_in,
    OutputType&  o_out)
{
    decltype(i_fn(i_in, o_out)) r_value {};

    do {

    // If the result of the input is already cached, return it
    static std::map< InputType, OutputType> cache;
    if(cache.count(i_in))
    {
        o_out = cache[i_in];
        break;
    }

    // Otherwise call the real function and assuming no error, cache the result
    // and return it
    OutputType out;
    r_value = i_fn(i_in,out);
    if(!r_value)
    {
        cache[i_in] = out;
        o_out = out;
    }

    } while(0);

    return r_value;
}

}; // End namespace Memoize

}; // End namespace Util

#endif
