/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/test/prdfsimServices.H $                    */
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

#ifndef _SimServices_H
#define _SimServices_H

#include <prdfMain.H>
#include <iipglobl.h>
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

    void setTestName(const char * i_testName) { iv_testName = i_testName; }

    void startSim();

    void endSim();

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
    void summarySig();
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
