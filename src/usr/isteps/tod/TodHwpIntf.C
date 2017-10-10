/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/tod/TodHwpIntf.C $                             */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2017                        */
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
 *  @file TodHwpIntf.C
 *
 *  @brief Implementation of TOD Hardware Procedure interfaces
 */

//------------------------------------------------------------------------------
//Includes
//------------------------------------------------------------------------------
#include <fapi2/target.H>
#include "TodTrace.H"
#include "TodControls.H"
#include "TodUtils.H"
#include "TodProc.H"
#include "TodHwpIntf.H"
#include "TodSvcUtil.H"
#include <devicefw/userif.H>

//HWPF
#include <plat_hwp_invoker.H>
#include <p9_tod_setup.H>
#include <p9_tod_save_config.H>
#include <p9_tod_init.H>
#include <isteps/tod_init_reasoncodes.H>

namespace TOD

{

errlHndl_t todSetupHwp(const p9_tod_setup_tod_sel i_topologyType)
{
    TOD_ENTER();

    errlHndl_t l_errHdl = NULL;

    do
    {
        //Get the MDMT
        TodProc* l_pMDMT =
             TOD::getMDMT(i_topologyType);

        p9_tod_setup_osc_sel l_selectedOsc = TOD_OSC_0;
        TOD_INF("For topology 0x%08X  Passing OSC 0x%08X  to "
             " p9_tod_setup ",i_topologyType,l_selectedOsc);

        //Invoke the HWP by passing the topology tree (rooted at MDMT)
        FAPI_INVOKE_HWP(l_errHdl,
                p9_tod_setup,
                l_pMDMT->getTopologyNode(),
                i_topologyType,
                l_selectedOsc);
        if(l_errHdl)
        {
            TOD_ERR("Error in call to p9_tod_setup. "
                    "Topology type 0x%.8X. "
                    "MDMT's HUID is 0x%.8X. "
                    "MDMT Master type : 0x%.8X. "
                    "MDMT Bus RX 0x%.8X, Bus TX 0x%.8X.",
                    i_topologyType,
                    l_pMDMT->getTarget()->getAttr<TARGETING::ATTR_HUID>(),
                    l_pMDMT->getMasterType(),
                    l_pMDMT->getBusIn(), l_pMDMT->getBusOut());

            break;
        }
    }while(0);

    TOD_EXIT();

    return l_errHdl;
}


errlHndl_t todSaveRegsHwp(const p9_tod_setup_tod_sel i_topologyType)
{
    TOD_ENTER();

    errlHndl_t l_errHdl = NULL;
    do
    {
        //Get the MDMT
        TodProc* l_pMDMT =
            TOD::getMDMT(i_topologyType);
        if(NULL == l_pMDMT)
        {
            TOD_ERR("MDMT not found for topology type 0x%.8X",
                     i_topologyType);
            /*@
             * @errortype
             * @moduleid     TOD_SAVEREGS_HWP
             * @reasoncode   TOD_NO_VALID_MDMT_FOUND
             * @userdata1    Topology type (primary/secondary)
             * @devdesc      MDMT could not be found
             * @custdesc     Host failed to boot because there was a problem
             *               configuring Time Of Day on the Host processors
             */
            const bool hbSwError = true;
            l_errHdl = new ERRORLOG::ErrlEntry(
                           ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                           TOD_SAVEREGS_HWP,
                           TOD_NO_VALID_MDMT_FOUND,
                           i_topologyType,
                           hbSwError);
            break;
        }

        //Invoke the HWP by passing the topology tree (rooted at MDMT)
        FAPI_INVOKE_HWP(l_errHdl,
                p9_tod_save_config,
                l_pMDMT->getTopologyNode());
        if(l_errHdl)
        {
            TOD_ERR("Error in call to p9_tod_save_config. "
                    "Topology type 0x%.8X. "
                    "MDMT's HUID is 0x%.8X. "
                    "MDMT Master type : 0x%.8X. "
                    "MDMT Bus RX 0x%.8X, Bus TX 0x%.8X.",
                    i_topologyType,
                    l_pMDMT->getTarget()->getAttr<TARGETING::ATTR_HUID>(),
                    l_pMDMT->getMasterType(),
                    l_pMDMT->getBusIn(), l_pMDMT->getBusOut());

            break;
        }
    }while(0);

    TOD_EXIT();
    return l_errHdl;
}

//*****************************************************************************
//todInitHwp
//*****************************************************************************
errlHndl_t todInitHwp()
{
    TOD_ENTER();
    errlHndl_t l_errHdl = NULL;
    do
    {

        //Get the MDMT
        TodProc* l_pMDMT =
            TOD::getMDMT(TOD_PRIMARY);

        if( NULL == l_pMDMT )
        {
            TOD_ERR("Valid MDMT not found in the primary TOD topology");
            /*@
             * @errortype
             * @moduleid     TOD_INIT_HWP
             * @reasoncode   TOD_NO_VALID_MDMT_FOUND
             * @userdata1    EMOD_TOD_INIT_HWP
             * @userdata2    PRIMARY topology type
             * @devdesc      No MDMT present on the system
             * @custdesc     Host failed to boot because there was a problem
             *               configuring Time Of Day on the Host processors
             */
            const bool hbSwError = true;
            l_errHdl = new ERRORLOG::ErrlEntry(
                           ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                           TOD_INIT_HWP,
                           TOD_NO_VALID_MDMT_FOUND,
                           EMOD_TOD_INIT_HWP,
                           TOD_PRIMARY,
                           hbSwError);
            break;
        }

        TARGETING::Target* l_failingTodProc = NULL;
        fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>
            l_fapiFailingProcTarget(l_failingTodProc);

        //Invoke the HWP by passing the reference to the topology
        FAPI_INVOKE_HWP(l_errHdl,
                p9_tod_init,
                l_pMDMT->getTopologyNode(),
                &l_fapiFailingProcTarget);

        if(l_errHdl)
        {
            TOD_ERR("Error in call to p9_tod_init. "
                    "MDMT's HUID is 0x%.8X. "
                    "MDMT Master type : 0x%.8X. ",
                    GETHUID(l_pMDMT->getTarget()),
                    l_pMDMT->getMasterType());

            l_failingTodProc = reinterpret_cast<TARGETING::Target*>(
                    l_fapiFailingProcTarget.get());

            break;
        }
        else
        {
            TOD_INF("Successfully completed  p9_tod_init. "
                    "MDMT's HUID is 0x%.8X. "
                    "MDMT Master type : 0x%.8X. ",
                    GETHUID(l_pMDMT->getTarget()),
                    l_pMDMT->getMasterType());
        }

    }while(0);

    TOD_EXIT();
    return l_errHdl;
}//todInitHwp

}
