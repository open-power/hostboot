/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/test/prdfsimServices.C $                    */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012                   */
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

#include "prdfsimServices.H"
#include <prdfPlatServices.H>
#include <prdfMain.H>
#include <prdfTrace.H>
#include <iipglobl.h>

#include "prdfsimUtil.H"
#include "prdsimSignatureParser.H"
#include "prdfsimScrDB.H"
#include "prdfsimHomRegisterAccess.H"
#include "prdfsim_ras_services.H"

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
            errlHndl_t l_pErr = NULL;
            //l_pErr = PRDF::initialize();
            if (l_pErr)
            {
                PRDF_ERR( "prdfsimServices::~prdfsimServices(): PRDF::initialize returned error" );
                PRDF_COMMIT_ERRL(l_pErr, ERRL_ACTION_REPORT);
            }
        }

        iv_attnList.clear();

        if(NULL != iv_ScrDB)
        {
            delete iv_ScrDB; iv_ScrDB = NULL;
        }

        if(NULL != iv_SimSignatureParser)
        {
            delete iv_SimSignatureParser; iv_SimSignatureParser = NULL;
        }

        PRDF_TRAC( "SimServices::~SimServices()" );
    }

    void SimServices::reset()
    {
        iv_attnList.clear();

        if(NULL != iv_ScrDB) delete iv_ScrDB;
        iv_ScrDB = new ScrDB();

        if(NULL != iv_SimSignatureParser) delete iv_SimSignatureParser;
        iv_SimSignatureParser = new SimSignatureParser();

        //initTargeting();

        PRDF_TRAC( "SimServices::reset()" );
    }

    void SimServices::startSim()
    {
        PRDF_TRAC( "SimServices::startSim() Test: %s",
            (iv_testName ? iv_testName : "No Test Name specified"));

        errlHndl_t l_pErr = NULL;
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

    void SimServices::endSim()
    {
        summarySig();
        PRDF_TRAC( "SimServices::endSim() Test: %s",
                    (iv_testName ? iv_testName : "No Test Name specified"));
    }

    void SimServices::addAttnEntry(const char * i_epath,
                                       ATTENTION_VALUE_TYPE i_attnType)
    {
        AttnData l_attnEntry;
        l_attnEntry.targetHndl = string2Target(i_epath);
        l_attnEntry.attnType = i_attnType;
        iv_attnList.push_back(l_attnEntry);

        // If the target in sim is not functional,
        // set to functional and destroy the PRD config
        // so new one can be built
        if(false == isFunctional(l_attnEntry.targetHndl))
        {
            iv_reinitTarget = true;
            setHwasState(l_attnEntry.targetHndl, true);
            errlHndl_t l_pErr = NULL;
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
        BIT_STRING_CLASS l_bs(64, l_cpuWord);
        l_bs.SetFieldJustify(0, 32, (i_data >> 32) & 0xFFFFFFFF);
        l_bs.SetFieldJustify(32, 32, (i_data & 0xFFFFFFFF));

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
        BIT_STRING_CLASS l_bs(64, l_cpuWord);
        l_bs.SetFieldJustify(0, 32, (i_data >> 32) & 0xFFFFFFFF);
        l_bs.SetFieldJustify(32, 32, (i_data & 0xFFFFFFFF));

        iv_ScrDB->processCmd(l_ptargetHandle,
                             l_bs,
                             i_address,
                             ScrDB::EXPECT);
    }

    void SimServices::processCmd(TARGETING::TargetHandle_t i_ptargetHandle,
                                     BIT_STRING_CLASS & bs,
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

    void SimServices::summarySig()
    {
        iv_SimSignatureParser->Summary();
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
