/*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/usr/diag/attn/attnops.H $
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
#ifndef __ATTN_ATTNOPS_H
#define __ATTN_ATTNOPS_H

/**
 * @file attnops.H
 *
 * @brief HBATTN Attention and AttentionOps definitions.
 */

#include "attnfwd.H"

namespace ATTN
{

/**
 * @brief AttentionOps Interface specification.
 *
 * For types that implement mask, unmask and query operations.
 */
class AttentionOps
{
    public:

        /**
         * @brief mask Mask this attention.
         *
         * @param[in] i_data the attention to be masked.
         *
         * @return errlHndl_t Error log.
         *
         * @retval[0] No error.
         * @retval[!0] Unexpected error occurred.
         */
        virtual errlHndl_t mask(const PRDF::AttnData & i_data) = 0;

        /**
         * @brief unmask Unmask this attention.
         *
         * @param[in] i_data the attention to be unmasked.
         *
         * @return errlHndl_t Error log.
         *
         * @retval[0] No error.
         * @retval[!0] Unexpected error occurred.
         */
        virtual errlHndl_t unmask(const PRDF::AttnData & i_data) = 0;

        /**
         * @brief query Test to see if this attention is active.
         *
         * @param[in] i_data the attention to be queried.
         * @param[out] o_active true if attention is active.
         *
         * @return errlHndl_t Error log.
         *
         * @retval[0] No error.
         * @retval[!0] Unexpected error occurred.
         */
        virtual errlHndl_t query(const PRDF::AttnData & i_data,
                bool & o_active) = 0;

        /**
         * @brief dtor
         */
        virtual ~AttentionOps() {}

        /**
         * @brief AttnOpsTest Provide access to unit test.
         */
        friend class AttnOpsTest;
};

/**
 * @brief Attention Operation router.
 *
 * Routes Attention mask, unmask and query operations
 * to the correct handler.
 */
class Attention
{
    public:

        /**
         * @brief mask Mask this attention.
         *
         * @retval[0] No error.
         * @retval[!0] Unexpected error occurred.
         */
        errlHndl_t mask() const
        {
            return iv_ops->mask(iv_data);
        }

        /**
         * @brief unmask Unmask this attention.
         *
         * @retval[0] No error.
         * @retval[!0] Unexpected error occurred.
         */
        errlHndl_t unmask() const
        {
            return iv_ops->unmask(iv_data);
        }

        /**
         * @brief query Test to see if this attention is active.
         *
         * @param[out] o_active true if attention is active.
         *
         * @retval[0] No error.
         * @retval[!0] Unexpected error occurred.
         */
        errlHndl_t query(bool & o_active) const
        {
            return iv_ops->query(iv_data, o_active);
        }

        /**
         * @brief getData Convert this attention to PRDF::AttnData.
         *
         * @param[out] o_data Converted attention.
         */
        void getData(PRDF::AttnData & o_data) const
        {
            o_data = iv_data;
        }

        /**
         * @brief compare Compare two attentions.
         *
         * @param[in] i_rhs The other attention.
         *
         * @retval[-1] This attention is less than the other attention.
         * @retval[1] This attention is greather than the other attention.
         * @retval[0] This attention is equivalent to the other attention.
         */
        int64_t compare(const Attention & i_rhs) const;

        /**
         * @brief ctor
         *
         * @param[in] i_data The PRDF::AttnData representation of the attention.
         * @param[in] i_ops The AttentionOps instance to which operations
         *                  should be routed.
         */
        Attention(const PRDF::AttnData & i_data,
                AttentionOps * i_ops)
            : iv_data(i_data), iv_ops(i_ops) {}

    private:

        /**
         * @brief iv_data The PRDF::AttnData representation of the attention.
         */
        PRDF::AttnData iv_data;

        /**
         * @brief iv_ops The AttentionOps instance to which operations
         *               should be routed.
         */
        AttentionOps * iv_ops;

        /**
         * @brief AttnOpsTest Provide access to unit test.
         */
        friend class ::AttnOpsTest;
};

/**
 * @brief operator< Test two attentions for less than.
 *
 * @param[in] i_lhs The left hand side of the comparison.
 * @param[in] i_rhs The right hand side of the comparison.
 *
 * @retval[true] i_lhs is less than i_rhs.
 * @retval[false] i_lhs is not less than i_rhs.
 */
inline bool operator<(const Attention & i_lhs, const Attention & i_rhs)
{
    return i_lhs.compare(i_rhs) < 0;
}
}
#endif
