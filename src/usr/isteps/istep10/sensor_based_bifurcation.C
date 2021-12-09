/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep10/sensor_based_bifurcation.C $           */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2022                        */
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
/******************************************************************************/
// Includes
/******************************************************************************/
#include <stdint.h>
// FIXME RTC: 210975
//#include <fapi2/target.H>
#include <targeting/targplatutil.H>

#include <trace/interface.H>
#include <initservice/taskargs.H>
#include <errl/errlentry.H>
#include <isteps/hwpisteperror.H>
#include <errl/errludtarget.H>
#include <initservice/isteps_trace.H>
#include <initservice/initserviceif.H>



namespace   ISTEP_10
{

errlHndl_t _queryIopsToBifurcateAndPhbsToDisable(
    TARGETING::ConstTargetHandle_t const       i_pecTarget,
    bool&                                      o_iopBifurcate,
    TARGETING::ATTR_PROC_PCIE_PHB_ACTIVE_type& o_disabledPhbsMask)
{
    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
        ENTER_MRK "_queryIopsToBifurcateAndPhbsToDisable: PEC target "
        "HUID = 0x%08X.", i_pecTarget ?
            i_pecTarget->getAttr<TARGETING::ATTR_HUID>() : 0);

    errlHndl_t pError = NULL;
    o_iopBifurcate = false;
    o_disabledPhbsMask = 0;

    // In order to match the original template, I keep the do-while
    // which is unnecessary.
    do {
        TARGETING::ATTR_PEC_PCIE_LANE_MASK_BIFURCATED_type laneMaskBifurcated = {0};
        assert(i_pecTarget->tryGetAttr<
               TARGETING::ATTR_PEC_PCIE_LANE_MASK_BIFURCATED>(
               laneMaskBifurcated),"Failed to get "
               "ATTR_PEC_PCIE_LANE_MASK_BIFURCATED attribute");
        if (laneMaskBifurcated[0] || laneMaskBifurcated[1] || laneMaskBifurcated[2]
            || laneMaskBifurcated[3]) {

            #if 0 // @TODO RTC 250046: provide PLDM replacement, if any
            TARGETING::Target* sys = nullptr;
            TARGETING::targetService().getTopLevelTarget(sys);
            assert(sys != nullptr);
            uint32_t sensorNum = TARGETING::UTIL::getSensorNumber(sys,
                                    TARGETING::SENSOR_NAME_PCI_BIFURCATED);

            if (sensorNum != 0xFF)
            {
                SENSOR::getSensorReadingData bifurcatedData;
                SENSOR::SensorBase bifurcatedSensor(
                                  TARGETING::SENSOR_NAME_BIFURCATED, sys);
                pError = bifurcatedSensor.readSensorData(bifurcatedData);
                if (NULL == pError) {
                    if ((bifurcatedData.event_status & 0x02) == 0x02) {
                        o_iopBifurcate = true;
                    }
                }
                else
                {
                    errlCommit(pError, ISTEP_COMP_ID);
                }
            }
            #endif
        }
    // Extension point to return bifurcated IOPs and PHBs to disable.
    // Assuming no extensions are added, the function returns no IOPs to
    // bifurcate and no PHBs to disable

    // If implemented, this function should only return error on software code
    // bug.  Any other condition should result in IOPs not being bifurcated and
    // host taking care of that condition.

    } while(0);

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
        EXIT_MRK "_queryIopsToBifurcateAndPhbsToDisable: EID = 0x%08X, "
        "PLID = 0x%08X, RC = 0x%08X.",
        ERRL_GETEID_SAFE(pError),ERRL_GETPLID_SAFE(pError),
        ERRL_GETRC_SAFE(pError));

    return pError;
}

};
