/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/htmgt/htmgt_memthrottles.C $                          */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2015                        */
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
#include "htmgt_memthrottles.H"
#include "htmgt_utility.H"
#include <htmgt/htmgt_reasoncodes.H>
#include <errl/errlmanager.H>
#include <targeting/common/commontargeting.H>
#include <targeting/common/utilFilter.H>
#include <targeting/common/attributes.H>
#include <targeting/common/targetservice.H>
#include <fapi.H>
#include <fapiPlatHwpInvoker.H>
#include <mss_bulk_pwr_throttles.H>
#include <mss_util_to_throttle.H>


using namespace TARGETING;



//for unit testing
//#define TRACUCOMP(args...)  TMGT_INF(args)
#define TRACUCOMP(args...)

namespace HTMGT
{

/**
 * Helper function to run the hardware procedure to calculate the
 * throttle attributes for the Over Temp condition.
 * flow = htmgtCalcMemThrottle_OT
 *
 * @param[in] i_mbas - list of functional MBAs
 * @param[in] i_utilization - Minimum utilization value required
 * @param[in] i_nSafeModeMBA - the safe mode MBA throttle numerator
 */
void memPowerThrottleOT(TargetHandleList & i_mbas,
                        const uint32_t i_nSafeModeMBA,
                        const uint8_t i_utilization)
{
    TargetHandleList::iterator mba;
    bool useSafeMode = false;
    bool throttleError = false;
    uint32_t nUtilBased = 0;
    uint32_t mbaHuid = 0;
    Target* sys = NULL;

    TMGT_INF(ENTER_MRK" memPowerThrottleOT");

    targetService().getTopLevelTarget(sys);
    assert(sys != NULL);

    for (mba=i_mbas.begin(); mba!=i_mbas.end(); ++mba)
    {
        mbaHuid = (*mba)->getAttr<ATTR_HUID>();
        useSafeMode = true;
        nUtilBased = 0;

        if (i_utilization != 0)
        {
            //Run a hardware procedure to calculate the lowest
            //possible throttle setting based on the minimum
            //utilization percentage.
            errlHndl_t err = NULL;
            const fapi::Target fapiTarget(fapi::TARGET_TYPE_MBA_CHIPLET,
                                          const_cast<Target*>(*mba));

            //Set this so the procedure can use it
            (*mba)->setAttr<ATTR_MSS_DATABUS_UTIL_PER_MBA>(i_utilization);

            FAPI_INVOKE_HWP(err, mss_util_to_throttle, fapiTarget);

            if (err)
            {
                //Ignore the error and just use safe
                //mode as the lowest throttle
                TMGT_ERR("memPowerThrottleOT: Failed call to "
                         "mss_util_to_throttle on MBA 0x%X",
                         mbaHuid);

                delete err;
                err = NULL;
            }
            else
            {
                //get the procedure output
                nUtilBased = (*mba)->getAttr<ATTR_MSS_UTIL_N_PER_MBA>();

                if (0 != nUtilBased)
                {
                    useSafeMode = false;
                }
                else
                {
                    TMGT_ERR("memPowerThrottleOT: mss_util_to_throttle"
                             " calculated a numerator of 0, MBA 0x%X",
                             mbaHuid);

                    if (!throttleError)
                    {
                        throttleError = true;

                        /*@
                         * @errortype
                         * @reasoncode       HTMGT_RC_OT_THROTTLE_INVALID_N
                         * @severity         ERRL_SEV_UNRECOVERABLE
                         * @moduleid         HTMGT_MOD_MEMTHROTTLE
                         * @userdata1        MBA HUID
                         * @devdesc          Overtemp Throttle HW procedure
                         *                   calculated an invalid numerator
                         *                   value.
                         */
                        err = new ERRORLOG::ErrlEntry(
                                           ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                           HTMGT_MOD_MEMTHROTTLE,
                                           HTMGT_RC_OT_THROTTLE_INVALID_N,
                                           mbaHuid, 0, true);
                        err->collectTrace(HTMGT_COMP_NAME);
                        errlCommit(err, HTMGT_COMP_ID);
                    }
                }
            }
        }


        if (useSafeMode)
        {
            nUtilBased = i_nSafeModeMBA;

            TMGT_INF("memPowerThrottleOT: MBA 0x%X must use safemode"
                     " numerator", mbaHuid);
        }

        TMGT_INF("memPowerThrottleOT: MBA 0x%X: N Util OT = 0x%X",
                 mbaHuid, nUtilBased);

        (*mba)->setAttr<ATTR_OT_MIN_N_PER_MBA>(nUtilBased);
    }


}





/**
 * Helper function to run the mss_bulk_pwr_throttles and
 * mss_util_to_throttle to calculate memory throttling
 * numerator values.
 *
 * @param[in] i_mba - the MBA
 * @param[in] i_wattTarget - the power target for the MBA
 * @param[in] i_utilization - the utilization desired
 * @param[out] o_useSafeMode - will be set to true if safe mode
 *                             values should be used
 * @param[out] o_nMBA -  set to the N_PER_MBA  numerator value
 *                  (don't use if safemode=true)
 * @param[out] o_nChip - set to the N_PER_CHIP numerator value
 *                  (don't use if safemode=true)
 */
void doMBAThrottleCalc(TargetHandle_t i_mba,
                       const uint32_t i_wattTarget,
                       const uint8_t i_utilization,
                       bool & o_useSafeMode,
                       uint32_t & o_nMBA,
                       uint32_t & o_nChip)
{
    errlHndl_t err = NULL;

    o_useSafeMode = false;
    o_nMBA = 0;
    o_nChip = 0;

    //Set the values the procedures need
    i_mba->setAttr<ATTR_MSS_MEM_WATT_TARGET>(i_wattTarget);
    i_mba->setAttr<ATTR_MSS_DATABUS_UTIL_PER_MBA>(i_utilization);

    const fapi::Target fapiTarget(fapi::TARGET_TYPE_MBA_CHIPLET,
                                  i_mba);

    FAPI_INVOKE_HWP(err, mss_bulk_pwr_throttles, fapiTarget);

    if (err)
    {
        TMGT_ERR("doMBAThrottleCalc: Failed call to mss_bulk_pwr_throttles"
                 " on MBA 0x%X",
                 i_mba->getAttr<ATTR_HUID>());
    }
    else
    {
        //Get the procedure outputs
        o_nMBA  = i_mba->getAttr<ATTR_MSS_MEM_THROTTLE_NUMERATOR_PER_MBA>();
        o_nChip = i_mba->getAttr<ATTR_MSS_MEM_THROTTLE_NUMERATOR_PER_CHIP>();

        //Make sure neither are 0
        if ((0 == o_nMBA) || (0 == o_nChip))
        {
            TMGT_ERR("doMBAThrottleCalc: mss_bulk_pwr_throttles calculated a"
                     " numerator value of 0: nMBA = %d, nChip = %d, MBA 0x%X",
                     o_nMBA, o_nChip, i_mba->getAttr<ATTR_HUID>());

            /*@
             * @errortype
             * @reasoncode       HTMGT_RC_THROTTLE_INVALID_N
             * @severity         ERRL_SEV_UNRECOVERABLE
             * @moduleid         HTMGT_MOD_MEMTHROTTLE
             * @userdata1        MBA HUID
             * @userdata2[0:31]  MBA numerator
             * @userdata2[32:63] Chip numerator
             * @devdesc          Throttle HW procedure calculated
             *                   an invalid numerator value.
             */
            uint64_t data = ((uint64_t)o_nMBA << 32) | o_nChip;
            err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                          HTMGT_MOD_MEMTHROTTLE,
                                          HTMGT_RC_THROTTLE_INVALID_N,
                                          i_mba->getAttr<ATTR_HUID>(),
                                          data, true);
        }
        else if (i_utilization != 0)
        {
            //Make sure the calculated throttles meet the min
            //utilization, if provided.

            FAPI_INVOKE_HWP(err, mss_util_to_throttle, fapiTarget);

            if (err)
            {
                TMGT_ERR("doMBAThrottleCalc: Failed call to "
                         "mss_util_to_throttle on MBA 0x%X",
                         i_mba->getAttr<ATTR_HUID>());
            }
            else
            {
                //Get the value the procedure wrote
                uint32_t nUtilMBA = i_mba->getAttr<ATTR_MSS_UTIL_N_PER_MBA>();

                TRACUCOMP("doMBAThrottleCalc: mss_util_to_throttle"
                          " calculated N = %d",
                          nUtilMBA);

                //If mss_bulk_pwr_throttles calculated a value
                //that doesn't meet the minimum requested utilization,
                //then we have a problem.
                if (nUtilMBA > o_nMBA)
                {
                    TMGT_ERR("doMBAThrottleCalc: MSS_UTIL_N_PER_MBA 0x%X "
                             "> MSS_MEM_THROTTLE_N_PER_MBA 0x%X on MBA 0x%X",
                             nUtilMBA, o_nMBA,
                             i_mba->getAttr<ATTR_HUID>());

                    /*@
                     * @errortype
                     * @reasoncode       HTMGT_RC_THROTTLE_UTIL_ERROR
                     * @severity         ERRL_SEV_UNRECOVERABLE
                     * @moduleid         HTMGT_MOD_MEMTHROTTLE
                     * @userdata1        MBA HUID
                     * @userdata2[0:31]  util based N
                     * @userdata2[32:63] calculated N
                     * @devdesc          Throttle numerator calculated
                     *                   doesn't meet min utilization
                     */
                    uint64_t data = ((uint64_t)nUtilMBA << 32) | o_nMBA;
                    err = new ERRORLOG::ErrlEntry(
                                           ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                           HTMGT_MOD_MEMTHROTTLE,
                                           HTMGT_RC_THROTTLE_UTIL_ERROR,
                                           i_mba->getAttr<ATTR_HUID>(),
                                           data, true);
                }
            }
        }
    }

    if (err)
    {
        err->collectTrace(HTMGT_COMP_NAME);
        errlCommit(err, HTMGT_COMP_ID);
        o_useSafeMode = true;
    }

}


/**
 * Helper function to run the hardware procedures to calculate the
 * throttle attributes used for redundant power.
 * flow = htmgtCalcMemThrottle_redundantPwr
 *
 * @param[in] i_mbas - the list of functional MBAs
 * @param[in] i_nSafeModeMBA - the safe mode MBA throttle numerator
 * @param[in] i_nSafeModeChip - the safe mode MBA throttle numerator
 * @param[in] i_utilization - Minimum utilization value required
 * @param[in] i_efficiency - the regulator efficiency
 */
void memPowerThrottleRedPower(TargetHandleList & i_mbas,
                              const uint32_t i_nSafeModeMBA,
                              const uint32_t i_nSafeModeChip,
                              const uint8_t i_utilization,
                              const uint8_t i_efficiency)
{
    Target* sys = NULL;
    TargetHandleList::iterator mba;
    uint16_t power = 0;
    uint32_t wattTarget = 0;
    uint32_t nChip = 0;
    uint32_t nMBA = 0;
    bool useSafeMode = false;

    targetService().getTopLevelTarget(sys);
    assert(sys != NULL);

    //Get the max N+1 power allocated to memory
    power = sys->getAttr<ATTR_OPEN_POWER_N_PLUS_ONE_MAX_MEM_POWER_WATTS>();
    power *= 100; //centiWatts

    //Account for the regulator efficiency, if supplied
    if (i_efficiency != 0)
    {
        power *= i_efficiency;
    }

    //Find the Watt target for each MBA
    if (i_mbas.size())
    {
        wattTarget = power / i_mbas.size();
    }

    TMGT_INF("memPowerThrottleRedPower: power = %d, wattTarget = %d",
             power, wattTarget);

    for (mba=i_mbas.begin(); mba!=i_mbas.end(); ++mba)
    {
        useSafeMode = false;
        nMBA = nChip = 0;

        //Run the calculations
        doMBAThrottleCalc(*mba, wattTarget, i_utilization,
                          useSafeMode, nMBA, nChip);

        if (useSafeMode)
        {
            nMBA = i_nSafeModeMBA;
            nChip  = i_nSafeModeChip;
            TMGT_INF("memPowerThrottleRedPower: MBA 0x%X using safemode "
                     "numerator",
                     (*mba)->getAttr<ATTR_HUID>());
        }

        //Set the attributes we'll send to OCC later
        TMGT_INF("memPowerThrottleRedPower: MBA 0x%X:  N_PER_MBA = 0x%X, "
                 "N_PER_CHIP = 0x%X",
                 (*mba)->getAttr<ATTR_HUID>(), nMBA, nChip);

        (*mba)->setAttr<ATTR_N_PLUS_ONE_N_PER_MBA>(nMBA);
        (*mba)->setAttr<ATTR_N_PLUS_ONE_N_PER_CHIP>(nChip);

    }


}



/**
 * Helper function to run the hardware procedures to calculate the
 * throttle attributes used for oversubscription.
 * flow = htmgtCalcMemThrottle_oversub
 *
 * @param[in] i_mbas - the list of functional MBAs
 * @param[in] i_nSafeModeMBA - the safe mode MBA throttle numerator
 * @param[in] i_nSafeModeChip - the safe mode MBA throttle numerator
 * @param[in] i_utilization - Minimum utilization value required
 * @param[in] i_efficiency - the regulator efficiency
 */
void memPowerThrottleOverSub(TargetHandleList & i_mbas,
                             const uint32_t i_nSafeModeMBA,
                             const uint32_t i_nSafeModeChip,
                             const uint8_t i_utilization,
                             const uint8_t i_efficiency)
{
    Target* sys = NULL;
    TargetHandleList::iterator mba;
    uint16_t power = 0;
    uint32_t wattTarget = 0;
    uint32_t nChip = 0;
    uint32_t nMBA = 0;
    bool useSafeMode = false;

    targetService().getTopLevelTarget(sys);
    assert(sys != NULL);

    //Get the max power allocated to memory
    power = sys->getAttr<ATTR_OPEN_POWER_N_MAX_MEM_POWER_WATTS>();
    power *= 100; //centiWatts

    //Account for the regulator efficiency, if supplied
    if (i_efficiency != 0)
    {
        power *= i_efficiency;
    }

    //Find the Watt target for each MBA
    if (i_mbas.size())
    {
        wattTarget = power / i_mbas.size();
    }

    TMGT_INF("memPowerThrottleOverSub: power = %d, wattTarget = %d",
             power, wattTarget);

    for (mba=i_mbas.begin(); mba!=i_mbas.end(); ++mba)
    {
        useSafeMode = false;
        nMBA = nChip = 0;

        //Run the calculations
        doMBAThrottleCalc(*mba, wattTarget, i_utilization,
                          useSafeMode, nMBA, nChip);

        if (useSafeMode)
        {
            nMBA = i_nSafeModeMBA;
            nChip  = i_nSafeModeChip;
            TMGT_INF("memPowerThrottleOverSub: MBA 0x%X using safemode "
                     "numerator",
                     (*mba)->getAttr<ATTR_HUID>());
        }

        //Set the attributes we'll send to OCC later
        TMGT_INF("memPowerThrottleOverSub: MBA 0x%X:  N_PER_MBA = 0x%X, "
                 "N_PER_CHIP = 0x%X",
                 (*mba)->getAttr<ATTR_HUID>(), nMBA, nChip);

        (*mba)->setAttr<ATTR_OVERSUB_N_PER_MBA>(nMBA);
        (*mba)->setAttr<ATTR_OVERSUB_N_PER_CHIP>(nChip);

    }

}



void calcMemThrottles()
{
    Target* sys = NULL;
    TargetHandleList mbas;

    targetService().getTopLevelTarget(sys);
    assert(sys != NULL);

    uint32_t nSafeModeMBA =
        sys->getAttr<ATTR_MRW_SAFEMODE_MEM_THROTTLE_NUMERATOR_PER_MBA>();

    uint32_t nSafeModeChip =
        sys->getAttr<ATTR_MRW_SAFEMODE_MEM_THROTTLE_NUMERATOR_PER_CHIP>();

    uint8_t utilization =
        sys->getAttr<ATTR_OPEN_POWER_MIN_MEM_UTILIZATION_THROTTLING>();

    uint8_t efficiency =
        sys->getAttr<ATTR_OPEN_POWER_REGULATOR_EFFICIENCY_FACTOR>();

    TMGT_INF("calcMemThrottles: Using nSafeModeMBA=0x%X, nSafeModeChip=0x%X",
             nSafeModeMBA, nSafeModeChip);

    TMGT_INF("calcMemThrottles: Using utilization=0x%X, efficiency=0x%X",
             utilization, efficiency);


    //Get all functional MBAs
    getAllChiplets(mbas, TYPE_MBA, true);

    //Calculate Throttle settings for Over Temperature
    memPowerThrottleOT(mbas, nSafeModeMBA, utilization);

    //Calculate Throttle settings for Redundant Power
    memPowerThrottleRedPower(mbas, nSafeModeMBA, nSafeModeChip,
                             utilization, efficiency);

    //Calculate Throttle settings for Oversubscription
    memPowerThrottleOverSub(mbas, nSafeModeMBA, nSafeModeChip,
                            utilization, efficiency);

}
}  // End namespace
