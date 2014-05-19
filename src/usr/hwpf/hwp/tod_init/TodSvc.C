/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/tod_init/TodSvc.C $                          */
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
 *  @file TodSvc.C
 *
 *  @brief Implements the TodSvc class that provides the Time Of Day service
 *
 *  HWP_IGNORE_VERSION_CHECK
 *
 */

#include <p8_scom_addresses.H>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <tod_init/tod_init_reasoncodes.H>
#include "TodTopologyManager.H"
#include "TodTrace.H"
#include "TodSvcUtil.H"
#include "TodHwpIntf.H"
#include "TodControls.H"
#include "TodSvc.H"
#include "proc_tod_utils.H"

namespace TOD
{

TodSvc & TodSvc::getTheInstance()
{
    return Singleton<TodSvc>::instance();
}

//******************************************************************************
//TodSvc::todSetup
//******************************************************************************
errlHndl_t TodSvc::todSetup()
{
    TOD_ENTER("todSetup");

    errlHndl_t l_errHdl = NULL;
    bool l_isTodRunning = false;
    TodTopologyManager l_primary(TOD_PRIMARY);
    TodControls & l_Tod = TodControls::getTheInstance();

    do
    {
        l_errHdl = l_Tod.isTodRunning(l_isTodRunning);
        if ( l_errHdl )
        {
            TOD_INF("Call to isTodRunning failed , cannot create topology");
            break;
        }

        if ( l_isTodRunning )
        {
            TOD_ERR("Cannot create TOD topology while the Chip TOD logic"
                    "is running ");
            /*@
             * @errortype
             * @reasoncode   TOD_INVALID_ACTION
             * @moduleid     TOD_SETUP
             * @userdata1    ChipTOD logic HW state , 1=running , zero otherwise
             * @devdesc      Error: can not create TOD topology when TOD
             *               HW is running
             */
            l_errHdl = new ERRORLOG::ErrlEntry(
                               ERRORLOG::ERRL_SEV_INFORMATIONAL,
                               TOD_SETUP,
                               TOD_INVALID_ACTION,
                               l_isTodRunning ? 1 : 0, 0);
            break;
        }

        l_Tod.destroy(TOD_PRIMARY);
        l_Tod.destroy(TOD_SECONDARY);

        //We're going to setup TOD for this IPL
        //1) Build a set of datastructures to setup creation of the TOD
        //topologies.
        l_errHdl = l_Tod.buildTodDrawers(TOD_PRIMARY);
        if(l_errHdl)
        {
            TOD_ERR("TOD setup failure: failed to build TOD drawers "
                     "for primary topology.");
            break;
        }

        //2) Ask the topology manager to setup the primary topology
        l_errHdl = l_primary.create();
        if(l_errHdl)
        {
            TOD_ERR("TOD setup failure: failed to create primary topology.");
            break;
        }
        l_primary.dumpTopology();

        //3) Call hardware procedures to configure the TOD hardware logic for
        //the primary topology and to fill up the TOD regs.
        l_errHdl = todSetupHwp(TOD_PRIMARY);
        if(l_errHdl)
        {
            TOD_ERR("TOD setup failure: primary topology setup HWP.");
            break;
        }
        l_errHdl = todSaveRegsHwp(TOD_PRIMARY);
        if(l_errHdl)
        {
            TOD_ERR("TOD setup failure: primary topology register save HWP.");
            break;
        }

        //Primary successfully configured
        l_Tod.setConfigStatus(TOD_PRIMARY,true);

        //Build datastructures for secondary topology
        l_errHdl = l_Tod.buildTodDrawers(TOD_SECONDARY);
        if(l_errHdl)
        {
            TOD_ERR("TOD setup failure: failed to build TOD drawers "
                     "for secondary topology.");
            //Report the error as informational - loss of redundancy,
            //but no loss of TOD function.
            errlCommit( l_errHdl, TOD_COMP_ID );
            break;
        }

        //4) Ask the topology manager to setup the secondary topology
        TodTopologyManager l_secondary(TOD_SECONDARY);
        l_errHdl = l_secondary.create();
        if(l_errHdl)
        {
            TOD_ERR("TOD setup failure: failed to create secondary topology.");
            //Report the error as informational - loss of redundancy,
            //but no loss of TOD function.
            errlCommit( l_errHdl, TOD_COMP_ID );
            break;
        }
        l_secondary.dumpTopology();

        //5) Call hardware procedures to configure the TOD hardware logic for
        //the secondary topology and to fill up the TOD regs.
        l_errHdl = todSetupHwp(TOD_SECONDARY);
        if(l_errHdl)
        {
            TOD_ERR("TOD setup failure: secondary topology setup HWP.");
            //Report the error as informational - loss of redundancy,
            //but no loss of TOD function.
            errlCommit( l_errHdl, TOD_COMP_ID );
            break;
        }

        //Secondary successfully configured
        l_Tod.setConfigStatus(TOD_SECONDARY,true);

        //Need to call this again if the secondary topology got set up,
        //that would have updated more regs.
        l_errHdl = todSaveRegsHwp(TOD_PRIMARY);
        if(l_errHdl)
        {
            TOD_ERR("TOD setup failure: primary topology register save HWP.");
            break;
        }

        //Done with TOD setup
    }while(0);

    if((NULL == l_errHdl) &&
       (false ==  l_isTodRunning ))
    {
        l_primary.dumpTodRegs();

        //If we are then atleast Primary or both configurations were
        //successfully setup. If both were successfuly setup then we can use
        //writeTodProcData for either of them else we should call
        //writeTodProcData for only primary.
        //Ultimately it should be good enough to call the method for Primary
        l_errHdl = l_Tod.writeTodProcData(TOD_PRIMARY);
        if(l_errHdl)
        {
            TOD_ERR("TOD setup failure:Failed to write topology register data"
            " to the file.");
        }
    }

    TOD_EXIT("todSetup. errHdl = %p", l_errHdl);

    return l_errHdl;
}

//******************************************************************************
//TodSvc::todInit
//******************************************************************************
errlHndl_t TodSvc::todInit()
{
    return todInitHwp(TOD_PRIMARY);
}

//******************************************************************************
//TodSvc::readTod
//******************************************************************************
errlHndl_t TodSvc::readTod(uint64_t& o_todValue) const
{
    TOD_ENTER("readTod");

    errlHndl_t l_errHdl = NULL;

    do
    {
        //Get the MDMT
        TodProc* l_pMDMT =
            TodControls::getTheInstance().getMDMT(TOD_PRIMARY);
        if(NULL == l_pMDMT)
        {
            TOD_ERR("MDMT not found");
            /*@
             * @errortype
             * @reasoncode   TOD_NO_MASTER_PROC
             * @moduleid     TOD_READ
             * @devdesc      MDMT could not be found
             */
            l_errHdl = new ERRORLOG::ErrlEntry(
                               ERRORLOG::ERRL_SEV_INFORMATIONAL,
                               TOD_READ,
                               TOD_NO_MASTER_PROC);
            break;
        }

        //SCOM the TOD value reg
        ecmdDataBufferBase o_todValueBuf(64);
        l_errHdl = todGetScom(l_pMDMT->getTarget(),
                              TOD_VALUE_REG_00040020,
                              o_todValueBuf);
        if(l_errHdl)
        {
            TOD_ERR("TOD read error: failed to SCOM TOD value register "
                     "address 0x%.16llX on MDMT 0x%.8X.",
                     TOD_VALUE_REG_00040020,
                     l_pMDMT->getTarget()->getAttr<TARGETING::ATTR_HUID>());
            break;
        }
        o_todValue = o_todValueBuf.getDoubleWord(0);

        TOD_INF("TOD value : 0x%.16llx", o_todValue );

    }while(0);

    TOD_EXIT("readTod. errHdl = %p", l_errHdl);

    return l_errHdl;
}

//******************************************************************************
//TodSvc::TodSvc
//******************************************************************************
TodSvc::TodSvc()
{
    TOD_ENTER("TodSvc constructor");

    TOD_EXIT("TodSvc constructor");
}

//******************************************************************************
//TodSvc::~TodSvc
//******************************************************************************
TodSvc::~TodSvc()
{
    TOD_ENTER("TodSvc destructor");

    //Free up held memory
    TodControls::getTheInstance().destroy(TOD_PRIMARY);
    TodControls::getTheInstance().destroy(TOD_SECONDARY);

    TOD_EXIT("TodSvc destructor");
}

} //namespace TOD
