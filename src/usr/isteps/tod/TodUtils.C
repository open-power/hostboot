/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/tod/TodUtils.C $                               */
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

    errlHndl_t l_errl = nullptr;
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
        // If i_pTarget is nullptr then create an error log
        TOD_ERR("Input Target handle is nullptr");

        //Create error
        /*@
         * @errortype
         * @moduleid     TOD_FUNCTIONAL_TARGET
         * @reasoncode   TOD_INVALID_TARGET
         * @devdesc      nullptr Target is supplied as an input
         * @custdesc     Hostboot Firmware encountered an internal
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
    errlHndl_t l_err = nullptr;

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
    errlHndl_t l_err = nullptr;

    do
    {
        //Get the top level (system) target  handle
        TARGETING::Target* l_pTopLevel = nullptr;
        (void)TARGETING::targetService().getTopLevelTarget(l_pTopLevel);

        // Assert on failure getting system target
        if(nullptr == l_pTopLevel)
        {
            TOD_ERR_ASSERT(false, "NULL top level target found");
            break;

        }
        // Top level target successfully retrieved. Now get attributes

        o_maxConfigParams.max_procchips_per_node = l_pTopLevel->getAttr
                        < TARGETING::ATTR_MAX_PROC_CHIPS_PER_NODE > ();

        o_maxConfigParams.max_compute_nodes_per_sys = l_pTopLevel->getAttr
                        < TARGETING::ATTR_MAX_COMPUTE_NODES_PER_SYSTEM > ();

    } while(0);

    TOD_EXIT("getMaxConfigParams");

    return l_err;
}

}//end of TOD namespace

