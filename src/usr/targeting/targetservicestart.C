/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/targeting/targetservicestart.C $                      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2014              */
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
 *  @file targeting/targetservicestart.C
 *
 *  @brief Hostboot entry point for target service
 */

//******************************************************************************
// Includes
//******************************************************************************

// STD
#include <stdio.h>
#include <stdlib.h>

// Other components
#include <sys/task.h>
#include <targeting/common/trace.H>
#include <targeting/adapters/assertadapter.H>
#include <initservice/taskargs.H>

// This component
#include <targeting/common/targetservice.H>
#include <targeting/attrrp.H>

// Others
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <devicefw/userif.H>

//******************************************************************************
// targetService
//******************************************************************************

namespace TARGETING
{

#define TARG_NAMESPACE "TARGETING::"

#define TARG_LOC TARG_NAMESPACE TARG_CLASS TARG_FN ": "

//******************************************************************************
// _start
//******************************************************************************

#define TARG_CLASS ""

/*
 * @brief Initialize any attributes that need to be set early on
 */
static void initializeAttributes(TargetService& i_targetService);

/**
 *  @brief Entry point for initialization service to initialize the targeting
 *      code
 * 
 *  @param[in] io_pError
 *      Error log handle; returns NULL on success, !NULL otherwise
 *
 *  @note: Link register is configured to automatically invoke task_end() when
 *      this routine returns
 */
static void initTargeting(errlHndl_t& io_pError)
{
    #define TARG_FN "initTargeting(errlHndl_t& io_pError)"

    TARG_ENTER();

    AttrRP::init(io_pError);

    if (io_pError == NULL)
    {
        TargetService& l_targetService = targetService();
        (void)l_targetService.init();

        initializeAttributes(l_targetService);

        // call ErrlManager function - tell him that TARG is ready!
        ERRORLOG::ErrlManager::errlResourceReady(ERRORLOG::TARG);
    }

    TARG_EXIT();

#undef TARG_FN
}

/**
 *  @brief Create _start entry point using task entry macro and vector to 
 *      initTargeting function
 */
TASK_ENTRY_MACRO(initTargeting);



/*
 * @brief Initialize any attributes that need to be set early on
 */
static void initializeAttributes(TargetService& i_targetService)
{
    #define TARG_FN "initializeAttributes()...)"
    TARG_ENTER();

    bool l_isMpipl = false;
    Target* l_pTopLevel = NULL;

    i_targetService.getTopLevelTarget(l_pTopLevel);
    if(l_pTopLevel)
    {
        Target* l_pMasterProcChip = NULL;
        i_targetService.masterProcChipTargetHandle(l_pMasterProcChip);

        if(l_pMasterProcChip)
        {
            // Master uses xscom by default, needs to be set before
            // doing any other scom accesses
            ScomSwitches l_switches =
              l_pMasterProcChip->getAttr<ATTR_SCOM_SWITCHES>();
            l_switches.useXscom = 1;
            l_switches.useFsiScom = 0;
            l_pMasterProcChip->setAttr<ATTR_SCOM_SWITCHES>(l_switches);

            errlHndl_t l_errl = NULL;
            size_t l_size = sizeof(uint64_t);
            uint64_t l_data;

            // Scratch register 2 is defined as 0x00050039.. accessing
            // directly to avoid confusion as the Literals set have
            // 0x00050039 mapped to MBOX_SCRATCH1 which is confusing.
            l_errl = DeviceFW::deviceRead(l_pMasterProcChip,
                                          &(l_data),
                                          l_size,
                                          DEVICE_SCOM_ADDRESS(0x00050039));

            if(l_errl)
            {
                TARG_INF("Read of scratch register failed");
                errlCommit(l_errl,TARG_COMP_ID);
            }
            else
            {
                // bit 0 on indicates MPIPL
                if(l_data & 0x8000000000000000ull)
                {
                    l_isMpipl = true;
                }
            }
        }


        if(l_isMpipl)
        {
            l_pTopLevel->setAttr<ATTR_IS_MPIPL_HB>(1);
        }
        else
        {
            l_pTopLevel->setAttr<ATTR_IS_MPIPL_HB>(0);
        }
    }
    else // top level is NULL - never expected
    {
        TARG_INF("Top level target is NULL");
    }

    TARG_EXIT();
    #undef TARG_FN
}

#undef TARG_CLASS

#undef TARG_NAMESPACE

} // End namespace TARGETING

