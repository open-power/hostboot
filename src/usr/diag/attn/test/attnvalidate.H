/*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/usr/diag/attn/test/attnvalidate.H $
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
#ifndef __TEST_ATTNVALIDATE_H
#define __TEST_ATTNVALIDATE_H

/**
 * @file attnvalidate.H
 *
 * @brief HBATTN fake system validation class definitions.
 */

#include "attnfakeelement.H"

namespace ATTN
{

/**
 * @brief Validator
 *
 * Fake system validation class definition.
 *
 * Monitors attention state changes and ipoll mask
 * changes.
 *
 * Accumulates attentions injected on the system and
 * tracks attention mask -> clear -> unmask lifeccyle.
 */
class Validator : public FakeReg, public FakeSource
{
    public:

        /**
         * @brief ctor
         */
        Validator() {};

        /**
         * @brief dtor
         */
        ~Validator() {}

        /**
         * @brief install
         *
         * Register this object with the provided system for
         * the appropriate callbacks.
         *
         * @param[in] i_system The system in which to register callbacks.
         */
        void install(FakeSystem & i_sys);

        /**
         * @brief processPutReg Process modified register content.
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
         * @param[in] i_sys System that modified register content.
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
         * @param[in] i_sys System that modified register content.
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
         * @brief empty
         *
         * Indicates whether or not all attentions successfully
         * completed the mask -> clear -> unmask lifecycle.
         *
         * @return[true] All lifecycles completed.
         * @return[false] One or more lifecycles incomplete.
         */
        bool empty() const;

        /**
         * @brief dump
         *
         * Dump the list of attentions with incomplete lifecycles.
         */
        void dump() const;

    private:

        /**
         * @brief processUnmask
         *
         * Unmask specific handling for ipoll mask register changes.
         *
         * @param[in] i_data The attention type that was unmasked.
         */
        void processUnmask(const PRDF::AttnData & i_data);

        /**
         * @brief processMask
         *
         * Mask specific handling for ipoll mask register changes.
         *
         * @param[in] i_data The attention type that was masked.
         */
        void processMask(const PRDF::AttnData & i_data);

        /**
         * @brief Attention lifecycle enumeration.
         */
        enum
        {
            MASK = 1,
            UNMASK,
            CLEAR,
            DONE,
        };

        /**
         * @brief Properties
         *
         * Adds an additional attribute to an AttnData struct.
         */
        struct Properties : public PRDF::AttnData
        {
            /**
             * @brief next The expected next state for this attention
             *         in the mask -> clear -> unmask lifecycle.
             */
            uint64_t next;
        };

        /**
         * @brief Attnetion type status association list.
         */
        std::vector<Properties> iv_properties;
};
}
#endif
