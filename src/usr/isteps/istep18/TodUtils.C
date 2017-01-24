/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep18/TodUtils.C $                           */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2017                        */
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

// Includes
// /***********************************************************************/

#include "TodAssert.H"
#include "TodUtils.H"
#include <devicefw/userif.H>
#include <isteps/tod_init_reasoncodes.H>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>

namespace TOD

{

//******************************************************************************
// isFunctional
//******************************************************************************

bool isFunctional(const TARGETING::Target* i_pTarget)
{
    //--------------------------------------------------------------------------
    // Local Variables
    //--------------------------------------------------------------------------

    errlHndl_t l_errl = NULL;
    bool l_isFunctional = false;

    //--------------------------------------------------------------------------
    // Code
    //--------------------------------------------------------------------------

    if(i_pTarget)
    {
        // For now return true if state is FUNCTIONAL else false.
        // There are total 4 HWAS functional states can exist:
        // NON FUNCTIONAL,FUNCTIONAL,CM FUNCTIONAL and DUMP FUNCTIONAL.
        // In-order to consider CM & DUMP FUNCTIONAL states we need to check
        // whether system is in CM/DUMP mode. Since the CM/DUMP mode support
        // is not available, we'll continue using FUNCTIONAL state only.
        // Later we need to check for appropriate mode and state.
        // @TODO via RTC: 69925
        l_isFunctional =
            i_pTarget->getAttr<TARGETING::ATTR_HWAS_STATE>().functional;
    }
    else
    {
        // If i_pTarget is NULL then create an error log
        TOD_ERR("Input Target handle is null");

        //Create error
        /*@
         * @errortype
         * @moduleid     TOD_FUNCTIONAL_TARGET
         * @reasoncode   TOD_INVALID_TARGET
         * @devdesc      NULL Target is supplied as an input
         * @custdesc     Service Processor Firmware encountered an internal
         *               error
         */
        l_errl = new ERRORLOG::ErrlEntry(
                     ERRORLOG::ERRL_SEV_INFORMATIONAL,
                     TOD_FUNCTIONAL_TARGET,
                     TOD_INVALID_TARGET);

        errlCommit(l_errl, TOD_COMP_ID);
    }

    return l_isFunctional;
}



//******************************************************************************
//todGetScom()
//******************************************************************************
errlHndl_t todGetScom(const TARGETING::Target * i_target,
                      const uint64_t i_address,
                      fapi2::variable_buffer & o_data)
{
    errlHndl_t l_err = NULL;

    // Perform SCOM read
    uint64_t l_data = 0;
    size_t l_size = sizeof(uint64_t);

    l_err = deviceRead((TARGETING::Target *)i_target,
                       &l_data,
                       l_size,
                       DEVICE_SCOM_ADDRESS(i_address));

    return l_err;
}


/*****************************************************************************/
// getMaxConfigParams
/*****************************************************************************/
errlHndl_t getMaxConfigParams(
                 maxConfigParamsContainer& o_maxConfigParams)
{
    TOD_ENTER("getMaxConfigParams");
    errlHndl_t l_err = NULL;

    do
    {
        //Get the top level (system) target  handle
        TARGETING::Target* l_pTopLevel = NULL;
        (void)TARGETING::targetService().getTopLevelTarget(l_pTopLevel);

        // Assert on failure getting system target
        if(NULL == l_pTopLevel)
        {
            TOD_ERR_ASSERT("NULL top level target found");
            break;

        }
        // Top level target successfully retrieved. Now get attributes

        o_maxConfigParams.max_procchips_per_node = l_pTopLevel->getAttr
                        < TARGETING::ATTR_MAX_PROC_CHIPS_PER_NODE > ();

        o_maxConfigParams.max_exs_per_procchip = l_pTopLevel->getAttr
                        < TARGETING::ATTR_MAX_EXS_PER_PROC_CHIP > ();

        o_maxConfigParams.max_dimms_per_mbaport = l_pTopLevel->getAttr
                        < TARGETING::ATTR_MAX_DIMMS_PER_MBA_PORT > ();

        o_maxConfigParams.max_mbaports_per_mba = l_pTopLevel->getAttr
                        < TARGETING::ATTR_MAX_MBA_PORTS_PER_MBA > ();

        o_maxConfigParams.max_mbas_per_membuf = l_pTopLevel->getAttr
                        < TARGETING::ATTR_MAX_MBAS_PER_MEMBUF_CHIP > ();

        o_maxConfigParams.max_chiplets_per_proc = l_pTopLevel->getAttr
                        < TARGETING::ATTR_MAX_CHIPLETS_PER_PROC > ();

        o_maxConfigParams.max_mcs_per_sys = l_pTopLevel->getAttr
                        < TARGETING::ATTR_MAX_MCS_PER_SYSTEM > ();

    } while(0);

    TOD_EXIT();

    return l_err;
}

}//end of TOD namespace

