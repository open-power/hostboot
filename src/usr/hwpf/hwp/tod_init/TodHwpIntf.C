/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/tod_init/TodHwpIntf.C $                      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013,2014              */
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
 *
 *  HWP_IGNORE_VERSION_CHECK
 *
 */

//------------------------------------------------------------------------------
//Includes
//------------------------------------------------------------------------------
#include <fapiPlatHwpInvoker.H>
#include <tod_init/tod_init_reasoncodes.H>
#include "TodTrace.H"
#include "TodHwpIntf.H"
#include "TodControls.H"
#include "proc_tod_setup.H"
#include "proc_tod_save_config.H"
#include "proc_tod_init.H"

namespace TOD
{

errlHndl_t todSetupHwp(const proc_tod_setup_tod_sel i_topologyType)
{
    TOD_ENTER("todSetupHwp");

    errlHndl_t l_errHdl = NULL;

    do
    {
        //Get the MDMT
        TodProc* l_pMDMT =
            TodControls::getTheInstance().getMDMT(i_topologyType);
        if(NULL == l_pMDMT)
        {
            TOD_ERR("MDMT not found");
            /*@
             * @errortype
             * @reasoncode   TOD_NO_MASTER_PROC
             * @moduleid     TOD_SETUP_HWP
             * @devdesc      MDMT could not be found
             */
            l_errHdl = new ERRORLOG::ErrlEntry(
                               ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                               TOD_SETUP_HWP,
                               TOD_NO_MASTER_PROC,0,0);
            break;
        }

        FAPI_INVOKE_HWP(l_errHdl,
                        proc_tod_setup,
                        l_pMDMT->getTopologyNode(),
                        i_topologyType,
                        TOD_OSC_0);
        if(l_errHdl)
        {
          TOD_ERR("Error in call to proc_tod_setup. "
                   "Topology type 0x%.8X. "
                   "MDMT's HUID is 0x%.8X. "
                   "MDMT Master type : 0x%.8X. ",
                   i_topologyType,
                   l_pMDMT->getTarget()->getAttr<TARGETING::ATTR_HUID>(),
                   l_pMDMT->getMasterType());
          TOD_ERR("MDMT Bus RX 0x%.8X, Bus TX 0x%.8X.",
                   l_pMDMT->getBusIn(), l_pMDMT->getBusOut());
          break;
        }

        //Mark the MDMT role in ATTR.  Note the same chip
        //can be both primary/secondary.  Attr is volatile
        //init'ed to zero
        TARGETING::Target * l_proc =
                const_cast<TARGETING::Target*>(l_pMDMT->getTarget());
        uint8_t l_role = l_proc->getAttr<TARGETING::ATTR_TOD_ROLE>();
        if (TOD_PRIMARY == i_topologyType)
        {
            l_role |= TARGETING::TOD_ROLE_PRIMARY;
        }
        else //Secondary
        {
            l_role |= TARGETING::TOD_ROLE_SECONDARY;
        }
        l_proc->setAttr<TARGETING::ATTR_TOD_ROLE>(l_role);

    }while(0);

    TOD_EXIT("todSetupHwp. errHdl = %p", l_errHdl);

    return l_errHdl;
}

errlHndl_t todSaveRegsHwp(const proc_tod_setup_tod_sel i_topologyType)
{
    TOD_ENTER("todSaveRegsHwp");

    errlHndl_t l_errHdl = NULL;

    do
    {
        //Get the MDMT
        TodProc* l_pMDMT =
            TodControls::getTheInstance().getMDMT(i_topologyType);
        if(NULL == l_pMDMT)
        {
            TOD_ERR("MDMT not found");
            /*@
             * @errortype
             * @reasoncode   TOD_NO_MASTER_PROC
             * @moduleid     TOD_SAVEREGS_HWP
             * @devdesc      MDMT could not be found
             */
            l_errHdl = new ERRORLOG::ErrlEntry(
                               ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                               TOD_SAVEREGS_HWP,
                               TOD_NO_MASTER_PROC,0,0);
            break;
        }

        FAPI_INVOKE_HWP(l_errHdl,
                        proc_tod_save_config,
                        l_pMDMT->getTopologyNode());
        if(l_errHdl)
        {
          TOD_ERR("Error in call to proc_tod_save_config. "
                  "Topology type 0x%.8X. "
                  "MDMT's HUID is 0x%.8X. "
                  "MDMT Master type : 0x%.8X. ",
                  i_topologyType,
                  l_pMDMT->getTarget()->getAttr<TARGETING::ATTR_HUID>(),
                  l_pMDMT->getMasterType());
          TOD_ERR("MDMT Bus RX 0x%.8X, Bus TX 0x%.8X.",
                  l_pMDMT->getBusIn(), l_pMDMT->getBusOut());
          break;
        }
    }while(0);

    TOD_EXIT("todSaveRegsHwp. errHdl = %p", l_errHdl);

    return l_errHdl;
}

errlHndl_t todInitHwp(const proc_tod_setup_tod_sel i_topologyType)
{
    TOD_ENTER("todInitHwp");

    errlHndl_t l_errHdl = NULL;

    do
    {
        //Get the MDMT
        TodProc* l_pMDMT =
            TodControls::getTheInstance().getMDMT(i_topologyType);
        if(NULL == l_pMDMT)
        {
            TOD_ERR("MDMT not found");
            /*@
             * @errortype
             * @reasoncode   TOD_NO_MASTER_PROC
             * @moduleid     TOD_INIT_HWP
             * @devdesc      MDMT could not be found
             */
            l_errHdl = new ERRORLOG::ErrlEntry(
                               ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                               TOD_INIT_HWP,
                               TOD_NO_MASTER_PROC,0,0);
            break;
        }

        FAPI_INVOKE_HWP(l_errHdl,
                        proc_tod_init,
                        l_pMDMT->getTopologyNode());

        if(l_errHdl)
        {
          TOD_ERR("Error in call to proc_tod_init. "
                   "Topology type 0x%.8X. "
                   "MDMT's HUID is 0x%.8X. "
                   "MDMT Master type : 0x%.8X. ",
                   i_topologyType,
                   l_pMDMT->getTarget()->getAttr<TARGETING::ATTR_HUID>(),
                   l_pMDMT->getMasterType());
          TOD_ERR("MDMT Bus RX 0x%.8X, Bus TX 0x%.8X.",
                   l_pMDMT->getBusIn(), l_pMDMT->getBusOut());
          break;
        }
    }while(0);

    TOD_EXIT("todInitHwp. errHdl = %p", l_errHdl);

    return l_errHdl;
}

} //namespace TOD
