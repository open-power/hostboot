/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/targeting/targetservicestart.C $                      */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2013              */
/*                                                                        */
/* p1                                                                     */
/*                                                                        */
/* Object Code Only (OCO) source materials                                */
/* Licensed Internal Code Source Materials                                */
/* IBM HostBoot Licensed Internal Code                                    */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* Origin: 30                                                             */
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

