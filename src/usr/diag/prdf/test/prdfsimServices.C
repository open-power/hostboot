/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/test/prdfsimServices.C $                    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2020                        */
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

#include "prdfsimServices.H"
#include <prdfPlatServices.H>
#include <prdfMain.H>
#include <prdfTrace.H>
#include <prdfGlobal.H>
#include <algorithm>

#include "prdfsimUtil.H"
#include "prdsimSignatureParser.H"
#include "prdfsimScrDB.H"
#include "prdfsimHomRegisterAccess.H"
#include "prdfsimRasServices.H"

#include <targeting/common/targetservice.H>

namespace PRDF
{

    using namespace TARGETING;
    using namespace PlatServices;

    /**
     *  @brief Returns a reference to the SimServices singleton
     *
     *  @return Reference to the SimServices
     */
    SimServices& getSimServices()
    {
        return PRDF_GET_SINGLETON(theSimServices);
    }

    SimServices::SimServices()
    {
        reset();

        ServiceGeneratorClass & serviceGenerator =
            ServiceGeneratorClass::ThisServiceGenerator();
        serviceGenerator.Initialize();

        // overloading default prdfErrDataService
        // will be deleted in RasServices dtor
        SimErrDataService* l_SimErrDataService = new SimErrDataService();
        serviceGenerator.setErrDataService(*l_SimErrDataService);

        // overloading default Scom Accessor
        // will be deleted in prdfScomService dtor
        SimScomAccessor* l_SimScomAccessor = new SimScomAccessor();
        getScomService().setScomAccessor(*l_SimScomAccessor);

        PRDF_TRAC( "SimServices::SimServices()" );
    }

    SimServices::~SimServices()
    {
        //initTargeting();
        if(true == iv_reinitTarget)
        {
            iv_reinitTarget = false;
            setHwasState(iv_attnList[0].targetHndl, false);
            errlHndl_t l_pErr = nullptr;
            //l_pErr = PRDF::initialize();
            if (l_pErr)
            {
                PRDF_ERR( "prdfsimServices::~prdfsimServices(): PRDF::initialize returned error" );
                PRDF_COMMIT_ERRL(l_pErr, ERRL_ACTION_REPORT);
            }
        }

        iv_attnList.clear();

        if(nullptr != iv_ScrDB)
        {
            delete iv_ScrDB; iv_ScrDB = nullptr;
        }

        if(nullptr != iv_SimSignatureParser)
        {
            delete iv_SimSignatureParser; iv_SimSignatureParser = nullptr;
        }

        PRDF_TRAC( "SimServices::~SimServices()" );
    }

    void SimServices::reset()
    {
        iv_attnList.clear();

        if(nullptr != iv_ScrDB) delete iv_ScrDB;
        iv_ScrDB = new ScrDB();

        if(nullptr != iv_SimSignatureParser) delete iv_SimSignatureParser;
        iv_SimSignatureParser = new SimSignatureParser();

        //initTargeting();

        PRDF_TRAC( "SimServices::reset()" );
    }

    void SimServices::startSim()
    {
        PRDF_TRAC( "SimServices::startSim() Test: %s",
            (iv_testName ? iv_testName : "No Test Name specified"));

        errlHndl_t l_pErr = nullptr;
        l_pErr = PRDF::main(iv_attnList[0].attnType, iv_attnList);

        if (l_pErr)
        {
            PRDF_ERR( "SimServices::startSim(): PRDF::main returned error" );
            PRDF_COMMIT_ERRL(l_pErr, ERRL_ACTION_REPORT);
        }
        else
        {
            PRDF_INF( "SimServices::startSim(): PRDF::main completed with no error" );
        }
    }

    bool SimServices::endSim()
    {
        bool l_testStatus = false;
        l_testStatus = summarySig();
        PRDF_TRAC( "SimServices::endSim() Test: %s",
                    (iv_testName ? iv_testName : "No Test Name specified"));
        return l_testStatus;
    }

    void SimServices::addAttnEntry(const char * i_epath,
                                       ATTENTION_VALUE_TYPE i_attnType)
    {
        AttnData l_attnEntry( string2Target(i_epath), i_attnType );
        iv_attnList.insert( std::lower_bound( iv_attnList.begin(),
                                              iv_attnList.end(), l_attnEntry ),
                                              l_attnEntry );

        // If the target in sim is not functional,
        // set to functional and destroy the PRD config
        // so new one can be built
        if(false == isFunctional(l_attnEntry.targetHndl))
        {
            iv_reinitTarget = true;
            setHwasState(l_attnEntry.targetHndl, true);
            errlHndl_t l_pErr = nullptr;
            //l_pErr = PRDF::initialize();
            if (l_pErr)
            {
                PRDF_ERR( "prdfsimServices::addAttnEntry(): PRDF::initialize returned error" );
                PRDF_COMMIT_ERRL(l_pErr, ERRL_ACTION_REPORT);
            }
        }
    }

    void SimServices::writeScr(const char * i_epath,
                                   uint64_t i_address,
                                   uint64_t i_data)
    {
        TARGETING::Target* l_ptargetHandle = string2Target(i_epath);
        CPU_WORD l_cpuWord[(64)/(sizeof(CPU_WORD)*8)] = {0};
        BitString l_bs(64, l_cpuWord);
        l_bs.setFieldJustify(0, 32, (i_data >> 32) & 0xFFFFFFFF);
        l_bs.setFieldJustify(32, 32, (i_data & 0xFFFFFFFF));

        iv_ScrDB->processCmd(l_ptargetHandle,
                             l_bs,
                             i_address,
                             ScrDB::WRITE);
    }

    void SimServices::expectScr(const char * i_epath,
                                    uint64_t i_address,
                                    uint64_t i_data)
    {
        TARGETING::Target* l_ptargetHandle = string2Target(i_epath);
        CPU_WORD l_cpuWord[(64)/(sizeof(CPU_WORD)*8)] = {0};
        BitString l_bs(64, l_cpuWord);
        l_bs.setFieldJustify(0, 32, (i_data >> 32) & 0xFFFFFFFF);
        l_bs.setFieldJustify(32, 32, (i_data & 0xFFFFFFFF));

        iv_ScrDB->processCmd(l_ptargetHandle,
                             l_bs,
                             i_address,
                             ScrDB::EXPECT);
    }

    void SimServices::processCmd(TARGETING::TargetHandle_t i_ptargetHandle,
                                     BitString & bs,
                                     uint64_t registerId,
                                     ScrDB::SimOp i_op)
    {
        iv_ScrDB->processCmd(i_ptargetHandle,
                             bs,
                             registerId,
                             i_op);
    }

    void SimServices::addSig(const char * i_epath, uint32_t i_sig)
    {
        TARGETING::Target* l_ptargetHandle = string2Target(i_epath);
        uint32_t i_chip = getHuid(l_ptargetHandle);
        iv_SimSignatureParser->Add(i_chip, i_sig);
    }

    void SimServices::reportSig(uint32_t i_chip, uint32_t i_sig)
    {
        iv_SimSignatureParser->Report(i_chip, i_sig);
    }

    bool SimServices::summarySig()
    {
        return iv_SimSignatureParser->Summary();
    }

    void SimServices::setTestName(const char * i_testName)
    {
        reset();
        iv_testName = i_testName;
    }

    void SimServices::initTargeting()
    {
        //targetService().init();
        TargetService& l_targetService = targetService();
        TargetIterator l_pIt;
        for( l_pIt = l_targetService.begin(); l_pIt != l_targetService.end(); l_pIt++)
        {
            setHwasState(*l_pIt, true);
        }
    }

    void SimServices::setHwasState(TARGETING::TargetHandle_t i_target, bool i_functional)
    {
        HwasState hwasState     = i_target->getAttr<ATTR_HWAS_STATE>();
        PRDF_TRAC("[setHwasState] i_target=0x%08x, func: %d, new func: %d",
                  getHuid(i_target), hwasState.functional, i_functional);

        //hwasState.poweredOn     = true;
        //hwasState.present       = true;
        hwasState.functional    = i_functional;
        i_target->setAttr<ATTR_HWAS_STATE>( hwasState );
    }

} // End namespace PRDF
