/*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/usr/diag/attn/test/attncomp.H $
 *
 *  IBM CONFIDENTIAL
 *
 *  COPYRIGHT International Business Machines Corp. 2012
 *
 *  p1
 *
 *  Object Code Only (OCO) source materials
 *  Licensed Internal Code Source Materials
 *  IBM HostBoot Licensed Internal Code
 *
 *  The source code for this program is not published or other-
 *  wise divested of its trade secrets, irrespective of what has
 *  been deposited with the U.S. Copyright Office.
 *
 *  Origin: 30
 *
 *  IBM_PROLOG_END_TAG
 */
#ifndef __TEST_ATTNCOMP_H
#define __TEST_ATTNCOMP_H

/**
 * @file attncomp.H
 *
 * @brief HBATTN test lib comparison functors.
 */

#include "attntest.H"

namespace ATTN
{

/**
 * @brief AttnDataSwo Less than comparison functor for PRDF::AttnData structs.
 */
class AttnDataSwo
{
    public:

        /**
         * @brief operator() Less than comparison for PRDF::AttnData structs.
         *
         * @param[in] i_l One of two PRDF::AttnData structs to be compared.
         * @param[in] i_r One of two PRDF::AttnData structs to be compared.
         *
         * @return bool Comparison result.
         *
         * @retval[true] i_l < i_r;
         * @retval[false] i_r < i_l;
         */
        bool operator()(
                const PRDF::AttnData & i_l,
                const PRDF::AttnData & i_r) const
        {
            return compare(i_l,  i_r) < 0;
        }
};

/**
 * @brief AttnDataEq Equality comparison predicate for PRDF::AttnData structs.
 */
class AttnDataEq
{
    public:

        /**
         * @brief operator() Equality comparison for PRDF::AttnData structs.
         *
         * @param[in] i_r One of two PRDF::AttnData structs to be compared.
         *
         * @return bool Comparison result.
         *
         * @retval[true] i_l == i_r;
         * @retval[false] i_l != i_r;
         */
        bool operator()(
                const PRDF::AttnData & i_r) const
        {
            return compare(iv_d,  i_r) == 0;
        }

        /**
         * @brief ctor
         *
         * @param[in] i_l One of two PRDF::AttnData structs to be compared.
         */
        explicit AttnDataEq(const PRDF::AttnData & i_l) :
            iv_d(i_l) {}

    private:

        /**
         * @brief iv_d
         *
         * One of two PRDF::AttnData structs to be compared.
         */
        const PRDF::AttnData & iv_d;
};
}
#endif
