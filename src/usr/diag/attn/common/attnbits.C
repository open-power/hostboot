/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/attn/common/attnbits.C $                         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2021                        */
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
 * @file attnbits.C
 *
 * @brief HBATTN register addresses, bits of interest.
 */

#include "common/attnfwd.H"
#include "common/attnbits.H"

using namespace PRDF;
using namespace std;

namespace ATTN
{

/**
 * @brief RegAssoc Associate register data with a key.
 *
 * Typically used to associate an attention type or MCS position
 * with register addresses or masks.
 */
struct RegAssoc
{
    uint64_t key;

    uint64_t data;
};

bool getCheckbits(
        const RegAssoc * i_first,
        const RegAssoc * i_last,
        uint64_t i_key,
        uint64_t & o_bits)
{
    while(i_first != i_last)
    {
        if(i_first->key == i_key)
        {
            o_bits = i_first->data;
            break;
        }

        ++i_first;
    }

    return i_first != i_last;
}

void forEach(
        const RegAssoc * i_first,
        const RegAssoc * i_last,
        uint64_t i_scomData,
        void * i_data,
        void (*i_func)(uint64_t, void *))
{
    while(i_first != i_last)
    {
        if(i_first->data & i_scomData)
        {
            (*i_func)(i_first->key, i_data);
        }

        ++i_first;
    }
}

namespace IPOLL
{

const uint64_t address = IPOLL_MASK_REG;

// NOTE: This reg should get flushed to zeroes.
//       Hence, the 'routing to host' and
//       'routing to FSP' should be enabled.
//      (along with all interrupt types to FSP)
//  ---------------------------------------------

void getCheckbitsAssociations(
        const RegAssoc * & o_first,
        const RegAssoc * & o_last)
{
    static const RegAssoc first[] = {

        {CHECK_STOP,  IPOLL_CHECK_STOP},
        {RECOVERABLE, IPOLL_RECOVERABLE},
        {SPECIAL,     IPOLL_SPECIAL},
        {UNIT_CS,     IPOLL_UNIT_CS},
        {HOST_ATTN,   IPOLL_HOST_ATTN},
    };

    static const RegAssoc * last = first +
        sizeof(first)/sizeof(*first);

    o_first = first;
    o_last = last;
}

bool getCheckbits(
        uint64_t i_type,
        uint64_t & o_bits)
{
    const RegAssoc * first, * last;

    getCheckbitsAssociations(first, last);

    return getCheckbits(first, last, i_type, o_bits);
}

void forEach(
        uint64_t i_scomData,
        void * i_data,
        void (*i_func)(uint64_t, void *))
{
    const RegAssoc * first, * last;

    getCheckbitsAssociations(first, last);

    forEach(first, last, i_scomData, i_data, i_func);
}
}

namespace GFIR
{

bool getAddress(
        uint64_t i_type,
        uint64_t & o_address)
{
    static const RegAssoc first[] = {

        {CHECK_STOP,  0x570F001C},
        {RECOVERABLE, 0x570F001B},
        {SPECIAL,     0x570F001A},
        {UNIT_CS,     0x570F002A},
        {HOST_ATTN,   0x570F002B},
    };

    static const RegAssoc * last = first +
        sizeof(first)/sizeof(*first);

    return getCheckbits(first, last, i_type, o_address);
}

bool getCheckbits(
        uint64_t i_type,
        uint64_t & o_bits)
{
    static const RegAssoc first[] = {

        {CHECK_STOP,  0xffffffffffffffffull},
        {RECOVERABLE, 0xffffffffffffffffull},
        {SPECIAL,     0x0000000000000000ull},
        {UNIT_CS,     0xffffffffffffffffull},
        {HOST_ATTN,   0xffffffffffffffffull},
    };

    static const RegAssoc * last = first +
        sizeof(first)/sizeof(*first);

    return getCheckbits(first, last, i_type, o_bits);
}
}

namespace MC
{
// First MC chiplet in broadcast read
const uint64_t firstChiplet = 0x0100000000000000ull;

// Number of MC chiplets
const uint64_t numChiplets  = 2;
}


// @TODO RTC: 180469
// Remove MCI  address space and then update all the CXX testing
namespace MCI
{
// Not valid / used for now on P9
const uint64_t address = 0x2011840;

void getCheckbitsAssociations(
        const RegAssoc * & o_first,
        const RegAssoc * & o_last)
{
    static const RegAssoc first[] = {

        {RECOVERABLE, 0x0009000000000000ull},
        {SPECIAL,     0x0000C00000000000ull},
    };

    static const RegAssoc * last = first +
        sizeof(first)/sizeof(*first);

    o_first = first;
    o_last = last;
}

bool getCheckbits(
        uint64_t i_type,
        uint64_t & o_bits)
{
    const RegAssoc * first, * last;

    getCheckbitsAssociations(first, last);

    return getCheckbits(first, last, i_type, o_bits);
}

void forEach(
        uint64_t i_scomData,
        void * i_data,
        void (*i_func)(uint64_t, void *))
{
    const RegAssoc * first, * last;

    getCheckbitsAssociations(first, last);

    forEach(first, last, i_scomData, i_data, i_func);
}
} // end MCI space



// @TODO RTC: 180469
// Remove MCI  address space and then update all the CXX testing
namespace GP1
{
// Not valid / used for now on P9
const uint64_t address = 0x2000001ull;

void getCheckbitsAssociations(
        const RegAssoc * & o_first,
        const RegAssoc * & o_last)
{
    static const RegAssoc first[] = {
        {0, 0x0100000000000000ull},
        {1, 0x0080000000000000ull},
        {2, 0x0040000000000000ull},
        {3, 0x0020000000000000ull},
        {4, 0x0010000000000000ull},
        {5, 0x0008000000000000ull},
        {6, 0x0004000000000000ull},
        {7, 0x0002000000000000ull},
    };

    static const RegAssoc * last = first +
        sizeof(first)/sizeof(*first);

    o_first = first;
    o_last = last;
}

bool getCheckbits(
        uint64_t i_pos,
        uint64_t & o_bits)
{
    const RegAssoc * first, * last;

    getCheckbitsAssociations(first, last);

    return getCheckbits(first, last, i_pos, o_bits);
}

void forEach(
        uint64_t i_scomData,
        void * i_data,
        void (*i_func)(uint64_t, void *))
{
    const RegAssoc * first, * last;

    getCheckbitsAssociations(first, last);

    forEach(first, last, i_scomData, i_data, i_func);
}
}  // end GP1 space


}
