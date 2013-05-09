/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/attn/attnbits.C $                                */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2013              */
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
 * @file attnbits.C
 *
 * @brief HBATTN register addresses, bits of interest.
 */

#include "attnfwd.H"
#include "attnbits.H"

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

const uint64_t address = 0x1020013;

void getCheckbitsAssociations(
        const RegAssoc * & o_first,
        const RegAssoc * & o_last)
{
    static const RegAssoc first[] = {

        {CHECK_STOP, 0x8000000000000000ull},
        {RECOVERABLE, 0x4000000000000000ull},
        {SPECIAL, 0x2000000000000000ull},
        {HOST, 0x1000000000000000ull},
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

        {CHECK_STOP, 0x570f001c},
        {RECOVERABLE, 0x570f001b},
        {SPECIAL, 0x570f001a},
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

        {CHECK_STOP, 0xffffffffffffffffull},
        {RECOVERABLE, 0xffffffffffffffffull},
        {SPECIAL, 0xffffffffffffffffull},
    };

    static const RegAssoc * last = first +
        sizeof(first)/sizeof(*first);

    return getCheckbits(first, last, i_type, o_bits);
}
}

namespace MCI
{

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
}

namespace GP1
{

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
}
}
