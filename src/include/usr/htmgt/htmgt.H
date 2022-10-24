/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/htmgt/htmgt.H $                               */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2022                        */
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

// Each P10 procesor can have 16 DDIMMs (each attached via an OMI channel)
// Each DDIMM has 1 EXPLORER OCMB chip
// Each EXPLORER OCMB chip has 1 port
// Each port has 2 slots for DDR4 DIMMs
const uint8_t HTMGT_MAX_PORT_PER_OCMB_CHIP = 1;
const uint8_t HTMGT_MAX_SLOT_PER_OCMB_PORT = 2;
const uint8_t HTMGT_NUM_DTS_PER_OCMB = 2;
const uint8_t HTMGT_NUM_DTS_PER_OCMB_ODYSSEY = 4;
const uint8_t HTMGT_MAX_DIMM_PER_OCMB_CHIP =
HTMGT_MAX_SLOT_PER_OCMB_PORT * HTMGT_MAX_PORT_PER_OCMB_CHIP;


namespace HTMGT
{
    const uint32_t OCC_RSP_SRAM_ADDR   = 0xFFFFE000;

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
     * @param[in]  i_proc  Processor target of the OCC reporting the error
     */
    void processOccError(TARGETING::Target * i_proc);



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
     * @param[in]  i_proc  Proc target containing the failed OCC
     */
    void processOccReset(TARGETING::Target * i_proc);



    /**
     * @brief Change the OCC state
     *
     * @details  This is a blocking call that will change the OCC state.
     *           The OCCs will only actuate (update processor frequency/
     *           voltages) when in Active state.  The OCC will only be
     *           monitoring/observing when in Observation state.
     *
     * @note     When the OCCs are initially started, the state will default
     *           to Active.  If the state is changed to Observation, that
     *           state will be retained until the next IPL. (If the OCC would
     *           get reset, it would return to the last requested state)
     *
     *
     * @param[in]  i_occActivation  set to TRUE to move OCC to Active state
     *                              or FALSE to move OCC to Observation state
     *
     * @returns  NULL on success, or an error handle if the state did not
     *           change.
     */
    errlHndl_t enableOccActuation(bool i_occActivation);



    /**
     * @brief Send a pass-through command to HTMGT
     *
     * @details  This is a blocking call that will send a command
     *           to HTMGT.
     *
     * @note     The maximum response data returned will be 4096 bytes
     *
     * @param[in]    i_cmdLength  number of bytes in pass-thru command data
     * @param[in]   *i_cmdData    pointer to pass-thru command data
     * @param[out]   o_rspLength  number of bytes returned in o_rspData
     * @param[out]  *o_rspData    pointer to a 4096 byte buffer that will
     *                            contain the response data from the command
     *
     * @returns  NULL on success, or an error handle if the state did not
     *           change.
     */
    errlHndl_t passThruCommand(uint16_t   i_cmdLength,
                               uint8_t *  i_cmdData,
                               uint16_t & o_rspLength,
                               uint8_t *  o_rspData);

    /**
     * @brief Check if specified OCC is active/running
     *
     * @note  Used by PLDM code if BMC asks for OCC sensor status
     *
     * @param[in]  i_proc  Proc target
     *
     * @returns true if running, else false
     */
    bool isOccRunning(TARGETING::Target * i_proc);
}

#endif // HTMGT_H
