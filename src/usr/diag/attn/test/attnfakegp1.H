/*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/usr/diag/attn/test/attnfakegp1.H $
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
#ifndef __TEST_ATTNFAKEGP1_H
#define __TEST_ATTNFAKEGP1_H

/**
 * @file attnfakegp1.H
 *
 * @brief HBATTN fake Gp1 register class definitions.
 */

#include "attnfakeelement.H"

namespace ATTN
{

/**
 * @brief FakeGp1 Fake GP1 class definition.
 *
 * Attach logic to MCI FIR register modifications.
 */
class FakeGp1 : public FakeReg
{
    public:

        /**
         * @brief dtor
         */
        ~FakeGp1() {}

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
         * Fake implemenation of gp1.  Turns bits on in GP1 when
         * MCI firs report attentions.
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
};
}
#endif
