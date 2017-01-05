/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep18/tod_init.C $                           */
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

/**
 *  @file tod_init.C
 *
 *  HWP_IGNORE_VERSION_CHECK
 *
 */

/******************************************************************************/
// Includes
/******************************************************************************/

#include <trace/interface.H>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <targeting/common/targetservice.H>
#include <initservice/initserviceif.H>

#include    <isteps/hwpisteperror.H>
#include    <initservice/isteps_trace.H>

#include    <targeting/common/commontargeting.H>
#include    <targeting/common/util.H>
#include    <targeting/common/utilFilter.H>
#include    <targeting/common/target.H>

#include    <fapi2.H>
#include    <fapi2/plat_hwp_invoker.H>


#include <p9_tod_setup.H>
#include <p9_tod_init.H>

#include "TodTrace.H"
#include "tod_init.H"


namespace   ISTEP_18
{

void * call_tod_setup(void *dummy)
{
    errlHndl_t l_errl = NULL;

    TOD_ENTER("call_tod_setup");

    //Hack job to get things going while waiting for true
    //TOD support
    //@TODO RTC:149253 replace with full content
    if (!INITSERVICE::spBaseServicesEnabled())
    {
        //Initialize the iv_tod_node_data structure
        tod_topology_node l_tod_node;
        build_proc_topology(l_tod_node);

        FAPI_INVOKE_HWP( l_errl, p9_tod_setup,
                         &l_tod_node,
                         TOD_PRIMARY,
                         TOD_OSC_0 );

        if (l_errl)
        {
            TOD_ERR("todSetup() return errl handle %p", l_errl);
            errlCommit( l_errl, TOD_COMP_ID );
        }
        delete_proc_topology(l_tod_node);
    }

    return l_errl; // //@TODO RTC:149253 update later
}

void * call_tod_init(void *dummy)
{
    errlHndl_t l_errl = NULL;
    TOD_ENTER("call_init");


    // @TODO RTC:149253 - Replace below with full functionality
    if (!INITSERVICE::spBaseServicesEnabled())
    {
        TARGETING::Target* l_masterproc = nullptr;
        TARGETING::targetService().masterProcChipTargetHandle(l_masterproc);
        fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>
          l_fapi2_proc_target (l_masterproc);

        //Initialize the iv_tod_node_data structure
        tod_topology_node l_tod_node;
        build_proc_topology(l_tod_node);

        FAPI_INVOKE_HWP( l_errl, p9_tod_init,
                         &l_tod_node,
                         NULL);

        if (l_errl)
        {
            TOD_ERR("todInit() return errl handle %p", l_errl);
            errlCommit( l_errl, TOD_COMP_ID );
        }

        //Clear up TOD data
        delete_proc_topology(l_tod_node);
    }

    return l_errl; //@TODO RTC:149253 update later
}


void build_proc_topology(tod_topology_node &i_tod_node)
{

    // @TODO RTC:149253
    if (!INITSERVICE::spBaseServicesEnabled())
    {
        //Get top level target
        TARGETING::Target* pSys;
        TARGETING::targetService().getTopLevelTarget(pSys);

        //Create predicate to find Functional Procs
        TARGETING::PredicateCTM l_procFilter(TARGETING::CLASS_CHIP,
                                             TARGETING::TYPE_PROC);
        TARGETING::PredicateHwas l_funcPred;
        l_funcPred.functional(true);
        TARGETING::PredicatePostfixExpr l_funcProcPostfixExpr;
        l_funcProcPostfixExpr.push(&l_procFilter).push(&l_funcPred).And();

        //Get the procs in a list
        TARGETING::TargetHandleList l_procs;
        TARGETING::targetService().getAssociated(l_procs,
                                      pSys,
                                      TARGETING::TargetService::CHILD,
                                      TARGETING::TargetService::ALL,
                                      &l_funcProcPostfixExpr);

        TARGETING::Target* l_masterproc = nullptr;
        TARGETING::targetService().masterProcChipTargetHandle(l_masterproc);
        fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>* l_fapi2_proc_target =
              new fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>(l_masterproc);

        i_tod_node.i_target = l_fapi2_proc_target;
        i_tod_node.i_tod_master = true;
        i_tod_node.i_drawer_master = true;
        i_tod_node.i_bus_rx = NONE;
        i_tod_node.i_bus_tx = NONE;
        i_tod_node.i_children.clear();

        //Iterate through functional procs setting base TOD information
        for (auto l_proc : l_procs)
        {
            //Add children to TOD Structure of master proc
            if (l_proc != l_masterproc)
            {
                TOD_INF("Found non-master proc, adding to TOD topology");

                tod_topology_node * l_tod_proc = new tod_topology_node;

                fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>*
                      l_fapi2_proc_target=
                    new fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>(l_proc);

                l_tod_proc->i_target = l_fapi2_proc_target;
                l_tod_proc->i_tod_master = false;
                l_tod_proc->i_drawer_master = true;

                auto l_xbus_targets =
                    l_fapi2_proc_target->getChildren<fapi2::TARGET_TYPE_XBUS>();

                for (auto l_xbus : l_xbus_targets)
                {
                    if (l_xbus.isFunctional())
                    {
                        const TARGETING::Target * l_xTarget =
                                        static_cast<TARGETING::Target*>(l_xbus);
                        switch (l_xTarget->getAttr<TARGETING::ATTR_REL_POS>())
                        {
                            case 0 : l_tod_proc->i_bus_rx = XBUS0;
                                     l_tod_proc->i_bus_tx = XBUS0;
                                     TOD_DTRAC("XBUS 0 Functional");
                                     break;
                            case 1 : l_tod_proc->i_bus_rx = XBUS1;
                                     l_tod_proc->i_bus_tx = XBUS1;
                                     TOD_DTRAC("XBUS 1 Functional");
                                     break;
                            case 2 : l_tod_proc->i_bus_rx = XBUS2;
                                     l_tod_proc->i_bus_tx = XBUS2;
                                     TOD_DTRAC("XBUS 2 Functional");
                                     break;
                        }
                    }
                }

                //Child proc should have no children
                l_tod_proc->i_children.clear();

                //Add non-master proc as child of master proc in the
                // TOD topology
                i_tod_node.i_children.push_back(l_tod_proc);
            }
        }
    }

    return;
}

void delete_proc_topology(tod_topology_node &i_tod_node)
{
    if (i_tod_node.i_target != NULL)
    {
        delete i_tod_node.i_target;
        i_tod_node.i_target = NULL;
    }

    for (auto l_child_node : i_tod_node.i_children)
    {
        if (l_child_node->i_target != NULL)
        {
            delete l_child_node->i_target;
            l_child_node->i_target = NULL;
        }

        delete l_child_node;
    }
}

};   // end namespace
