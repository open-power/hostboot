/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: $                                                             */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2014                        */
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
/**
 * @file array.C
 * @brief fapi2 arrays
 */

#include <stdint.h>
#include <array.H>

namespace fapi2
{
    /// @brief Create an array
    array::array(const uint32_t i_size, element_type* i_data):
        iv_size(i_size),
        iv_data(i_data)
    {
        assert(iv_size <= size_limit);
        if (iv_data == nullptr)
        {
            iv_data = new element_type[iv_size]();
            iv_size |= delete_bit;
        }
        // If the caller passed in a pointer, leave it be. Don't
        // initialize it or anything. That will allow a placement
        // operation where generic memory can use fapi2::array
        // methods without much overhead.
    }

    /// @brief Destroy an array
    array::~array(void)
    {
        if ((iv_size & delete_bit) != 0)
        {
            delete[] iv_data;
        }
    }

    /// @brief operator[]
    array::element_type& array::operator[](const uint32_t i_index)
    {
        assert(i_index < size());
        return iv_data[i_index];
    }

    /// @brief operator=()
    array& array::operator=(const array& i_other)
    {
        // Check to make sure it'll fit.
        assert(i_other.size() <= size());

        // Our new size will be the other's size.
        // Save of whether we should delete our iv_data ...
        uint64_t l_our_delete_state = iv_size | delete_bit;

        // ... our new size is the size (minus the delete state) of i_other
        iv_size = i_other.size();

        // ... do the copy ...
        memcpy(iv_data, i_other.iv_data, iv_size * sizeof(element_type));

        // ... and record our old delete state.
        iv_size |= l_our_delete_state;

        return *this;
    }

    /// @brief move operator=()
    array& array::operator=(array&& i_other)
    {
        iv_size = i_other.iv_size;

        // Make sure to clear the delete bit in the other. We
        // don't want our memory to be deleted.
        i_other.iv_size = i_other.size();

        iv_data = std::move(i_other.iv_data);
        return *this;
    }

    /// @brief operator==()
    bool array::operator==(const array& i_other)
    {
        // If they're not the same size, they're not the same
        if (size() != i_other.size())
        {
            return false;
        }

        // If they're the same size and point to the same memory, they're the same.
        if (iv_data == i_other.iv_data)
        {
            return true;
        }

        auto oitr = i_other.begin();
        auto iter = begin();

        for(; iter != end(); ++iter, ++oitr)
        {
            if (*iter != *oitr)
            {
                return false;
            }
        }

        return true;
    }
}
