/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/sbeio/sbe_telemetry.C $                               */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2023                             */
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
/**
* @file  sbe_telemetry.C
* @brief Contains the Telemetry Messages for SBE FIFO thermal sensor and
*        DQA Polling Control.
*
*/

#include <chipids.H>
#include <trace/interface.H>
#include <errl/errlmanager.H>
#include <sbeio/sbeioif.H>
#include <sbeio/sbe_utils.H>
#include "sbe_fifodd.H"
#include <sbeio/sbeioreasoncodes.H>
#include <targeting/common/targetservice.H>
#include <fapi2.H>


extern trace_desc_t* g_trac_sbeio;

#define SBE_TRACD(printf_string,args...) \
TRACDCOMP(g_trac_sbeio,"Telemetry: " printf_string,##args)

#define SBE_TRACF(printf_string,args...) \
TRACFCOMP(g_trac_sbeio,"Telemetry: " printf_string,##args)

using namespace TARGETING;

extern "C"
fapi2::ReturnCode ody_chipop_tsns_dqs_period (
            const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
            const uint32_t i_tsns_period_ms,
            const uint8_t i_dqs_period)
{
    fapi2::ReturnCode rc;

    errlHndl_t l_errl = SBEIO::sendExecHWPRequestForThermalSensorPolling(
                            i_target.get(),
                            i_tsns_period_ms,
                            i_dqs_period);
    if(l_errl)
    {
        SBE_TRACF(ERR_MRK"ody_chipop_tsns_dqs_period: Chip op to SBE 0x%x failed", get_huid(i_target.get()));
        addErrlPtrToReturnCode(rc, l_errl);
    }

    return rc;
}

namespace SBEIO
{
    /**
     * @brief Send the request to SBE to enable thermal sensor polling and DQA tracking.
     *        This request is sent via the chip op AC-02.
     *
     * @param[in] i_chipTarget The Odyssey chip to perform the chipop on
     * @param[in] i_interval   The thermal sensor polling interval in MS
     * @param[in] i_dqa        The DQA tracking interval
     *
     * @return errlHndl_t Error log handle on failure.
     */
    errlHndl_t sendExecHWPRequestForThermalSensorPolling(TARGETING::Target * i_chipTarget,
                                                         uint32_t i_interval,
                                                         uint8_t i_dqa)
    {
        errlHndl_t errl = nullptr;

        do
        {
            // Make sure the target is one of the supported types.
            errl = sbeioInterfaceChecks(i_chipTarget,
                                        SbeFifo::SBE_FIFO_CLASS_TELEMETRY_COMMANDS,
                                        SbeFifo::SBE_FIFO_CMD_THERMAL_SENSOR_AND_DQA_POLLING);
            if(errl)
            {
                break;
            }

            // Make sure the target is Odyssey
            errl = sbeioOdysseyCheck(i_chipTarget,
                                     SbeFifo::SBE_FIFO_CLASS_TELEMETRY_COMMANDS,
                                     SbeFifo::SBE_FIFO_CMD_THERMAL_SENSOR_AND_DQA_POLLING);
            if(errl)
            {
                break;
            }

            // set up FIFO request message
            SbeFifo::fifoExecuteControlThermalSensorRequest l_fifoRequest;
            SbeFifo::fifoStandardResponse l_fifoResponse;
            l_fifoRequest.interval      = i_interval;
            l_fifoRequest.dqa           = i_dqa;

            SBE_TRACF( "sendExecHWPRequestForThermalSensorPolling: "
                       "target=%.8X, hwpClass=%X, hwpNumber=%X interval=%X dqa=%X",
                       TARGETING::get_huid(i_chipTarget),
                       l_fifoRequest.commandClass,
                       l_fifoRequest.command,
                       l_fifoRequest.interval, l_fifoRequest.dqa );

            // Send the HWP request
            errl = SbeFifo::getTheInstance().performFifoChipOp(
                                i_chipTarget,
                                reinterpret_cast<uint32_t*>(&l_fifoRequest),
                                reinterpret_cast<uint32_t*>(&l_fifoResponse),
                                sizeof(SbeFifo::fifoStandardResponse));
            if(errl)
            {
                SBE_TRACF( "sendExecHWPRequestForThermalSensorPolling: ERROR from HWP!");
                break;
            }

        } while(0);

        return errl;
    } // end endExecHWPRequestForThermalSensorPolling

} //end namespace SBEIO

