/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/htmgt/htmgt.H $                               */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014                             */
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

#ifndef HTMGT_H
#define HTMGT_H


#include <targeting/common/commontargeting.H>


namespace HTMGT
{

    /**
     * @brief Move the OCCs into active state or on a failure leave the system
     *        in safe mode.
     *
     * @details  After all of the OCCs are loaded and started, HB/HBRT will
     *           call this interface to notify HTMGT of the operation status.
     *           Normally called by HB during the IPL, but can also happen
     *           at runtime, when the OCCs get reset/reloaded.
     *           On success status, the OCCs will be moved to active state.
     *           If the load/start failed, or the OCCs do not go active,
     *           an unrecoverable error will be committed and the system
     *           will remain in safe mode.
     *
     * @param[in]  i_startCompleted   true is OCC load and start was successful
     * @param[in]  i_failedOccTarget  OCC target of the failed OCC (only used
     *                                if i_startCompleted was set to false)
     */
    void processOccStartStatus(const bool i_startCompleted,
                               TARGETING::Target * i_failedOccTarget = NULL);



    /**
     * @brief Notify HTMGT that an OCC has an error to report
     *
     * @details  When an OCC has encountered an error that it wants to
     *           be reported, this interface will be called to trigger
     *           HTMGT to collect and commit the error.
     *
     * @param[in]  i_occTarget  OCC target reporting the error
     */
    void processOccError(TARGETING::Target * i_occTarget);



    /**
     * @brief Notify HTMGT that an OCC has failed and needs to be reset
     *
     * @details  When BMC detects an OCC failure that requires a reset,
     *           this interface will be called to trigger the OCC reset.
     *           HTMGT maintains a reset count and if there are additional
     *           resets available, the OCCs get reset/reloaded.
     *           If the recovery attempts have been exhauseted or the OCC
     *           fails to go active, an unrecoverable error will be logged
     *           and the system will remain in safe mode.
     *
     * @param[in]  i_failedOccTarget  OCC target of the failed OCC
     */
    void processOccReset(TARGETING::Target * i_failedOccTarget);

}

#endif // HTMGT_H
