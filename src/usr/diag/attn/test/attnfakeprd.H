/*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/usr/diag/attn/test/attnfakeprd.H $
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
#ifndef __TEST_ATTNFAKEPRD_H
#define __TEST_ATTNFAKEPRD_H

/**
 * @file attnfakeprd.H
 *
 * @brief HBATTN fake PRD class definitions.
 */

#include "attntest.H"
#include "../attnprd.H"

namespace ATTN
{

/**
 * @brief FakePrd
 *
 * Basic PRD implementation that eventually clears every attention it
 * receives.
 */
class FakePrd : public PrdImpl
{
    public:

        /**
         * @brief ctor
         *
         * @param[in] i_system The system where attentions
         *                     should be cleared.
         */
        explicit FakePrd(FakeSystem & i_system);

        /**
         * @brief dtor
         */
        ~FakePrd() {}

        /**
         * @brief callPrd Simulate a call to PRD.
         *
         * Sleeps random intervals, to simulate PRD processing times.  Periodically
         * does not clear some attentions, to simulate real PRD behavior.
         *
         * @param[in] i_attentions List of attentions for PRD to analyze.
         *
         * @return errlHndl_t Error log.
         *
         * @retval[0] No error occurred.
         * @retval[!0] Unexpected error occurred.
         */
        errlHndl_t callPrd(const AttentionList & i_attentions);

    private:

        /**
         * @brief iv_system The system where attentions should
         *                  be cleared.
         */
        FakeSystem * iv_system;
};
}
#endif
