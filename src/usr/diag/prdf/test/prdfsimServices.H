/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/test/prdfsimServices.H $                    */
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

#ifndef _SimServices_H
#define _SimServices_H

#include <prdfMain.H>
#include <prdfGlobal.H>
#include "prdfsimScrDB.H"

namespace PRDF
{

class ScrDB;
class SimSignatureParser;

class SimServices;
SimServices& getSimServices();

class SimServices
{

  public:

    SimServices();
    ~SimServices();

    void reset();

    void setTestName(const char * i_testName);

    void startSim();

    bool endSim();

    void addAttnEntry(const char * i_epath, PRDF::ATTENTION_VALUE_TYPE i_attnType);

    // ScrDB functions begin ---------------------------
    void writeScr(const char * i_epath,
                    uint64_t i_address,
                    uint64_t i_data);
    void expectScr(const char * i_epath,
                    uint64_t i_address,
                    uint64_t i_data);
    void processCmd(TARGETING::TargetHandle_t i_ptargetHandle,
                    BIT_STRING_CLASS & bs,
                    uint64_t registerId,
                    ScrDB::SimOp i_op);
    // ScrDB functions end ------------------------------

    // SimSignatureParser functions begin ------------
    //void AddSig(TARGETING::EntityPath & i_path, uint32_t i_sig);
    void addSig(const char * i_epath, uint32_t i_sig);
    void reportSig(uint32_t i_chip, uint32_t i_sig);
    bool summarySig();
    // SimSignatureParser functions end --------------

    /**
     * @brief   Inialize and restore Targeting model functional states
     */
    void initTargeting();

    /**
     * @brief         set i_target functional state
     * @param[in,out] i_target - target handle to set functional state
     * @param[in]     i_functional - functional state
     */
    void setHwasState(TARGETING::TargetHandle_t i_target, bool i_functional);

  protected:


  private:

    const char * iv_testName;
    PRDF::AttnList iv_attnList;
    ScrDB * iv_ScrDB;
    SimSignatureParser * iv_SimSignatureParser;
    bool iv_reinitTarget;

};

/**
 *  @brief Singleton to access the only SimServices
 */
class SimServices;
PRDF_DECLARE_SINGLETON(SimServices, theSimServices);

} // End namespace PRDF

#endif /* _SimServices_H */
