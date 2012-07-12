/*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/usr/diag/attn/test/attnfakemcs.H $
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
#ifndef __TEST_ATTNFAKEMCS_H
#define __TEST_ATTNFAKEMCS_H

/**
 * @file attnfakemcs.H
 *
 * @brief HBATTN fake MCS class definitions.
 */

#include "attnfakeelement.H"

namespace ATTN
{

/**
 * @brief FakeMcs Fake MCS class definition.
 *
 * Attach logic to MCI FIR register modifications, and membuf
 * local fir attentions.
 */
class FakeMcs : public FakeReg, public FakeSource
{
    public:

        /**
         * @brief ctor
         *
         * @param[in] i_type The type of the membuf local
         *     FIR to be monitored.
         */
        explicit FakeMcs(PRDF::ATTENTION_VALUE_TYPE i_type);

        /**
         * @brief dtor
         */
        ~FakeMcs() {}

        /**
         * @brief install
         *
         * Register this object with the provided system for
         * the appropriate callbacks.
         *
         * @param[in] i_system The system in which to register callbacks.
         */
        void install(FakeSystem & i_system);

    private:

        /**
         * @brief processPutReg Process modified register content.
         *
         * Fake implemenation of MCS.  Turns on MCS bits when attentions
         * are present.
         *
         * @param[in] i_sys System that modified register content.
         * @param[in] i_target Target whose registers were modified.
         * @param[in] i_address Address of register that was modified.
         * @param[in] i_new Register content after modification.
         * @param[in] i_old Register content before modification.
         *
         * @retval[0] No error occurred.
         * @retval[!0] Unexpected error occurred.
         */
        errlHndl_t processPutReg(
                FakeSystem & i_sys,
                TARGETING::TargetHandle_t i_target,
                uint64_t i_address,
                uint64_t i_new,
                uint64_t i_old);

        /**
         * @brief processPutAttention Process injected attention.
         *
         * Fake implemenation of membuf local Firs.  Sets the MCI Fir.
         *
         * @param[in] i_sys System on which attention was injected.
         * @param[in] i_attn Attention that was injected.
         * @param[in] i_count number of attentions currently present.
         *
         * @retval[0] No error occurred.
         * @retval[!0] Unexpected error occurred.
         */
        errlHndl_t processPutAttention(
                FakeSystem & i_sys,
                const PRDF::AttnData & i_attn,
                uint64_t i_count);

        /**
         * @brief processClearAttention Process cleared attention.
         *
         * Fake implemenation of membuf local Firs.  Clears the MCI Fir.
         * when appropriate.
         *
         * @param[in] i_sys System on which attention was cleared.
         * @param[in] i_attn Attention that was cleared.
         * @param[in] i_count number of attentions currently present.
         *
         * @retval[0] No error occurred.
         * @retval[!0] Unexpected error occurred.
         */
        errlHndl_t processClearAttention(
                FakeSystem & i_sys,
                const PRDF::AttnData & i_attn,
                uint64_t i_count);

        /**
         * @brief iv_type The attention type associated with this element.
         */
        PRDF::ATTENTION_VALUE_TYPE iv_type;

        /**
         * @brief iv_writebits Filter for type.
         */
        uint64_t iv_writebits;
};
}
#endif
