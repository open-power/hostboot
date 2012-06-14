/*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/usr/diag/mdia/test/mdiafakecm.H $
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
#ifndef __TEST_MDIAFAKECM_H
#define __TEST_MDIAFAKECM_H

#include "../mdiamonitor.H"

namespace MDIA
{
/**
 * @brief FakeCommandMonitor class that does not support polling.
 *        Used to test processing a maintenance command timeout.
 */
class FakeCommandMonitor : public CommandMonitor
{
    public:

        /**
         * @brief ctor
         */
        FakeCommandMonitor(){}

        /**
         * @brief dtor
         */
        ~FakeCommandMonitor(){}

    private:

        /**
         * @brief threadMain
         *
         * main thread function. Does not send fake events to the
         * StateMachine
         *
         * @param[in] i_sm state machine provided for callback
         */
        void threadMain(StateMachine & i_sm);
};
}
#endif
