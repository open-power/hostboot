/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/pore/poreve/porevesrc/pore.C $                        */
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
// $Id: pore.C,v 1.18 2013/04/05 19:34:28 jeshua Exp $

/// \file pore.C
/// \brief The implementation of the PoreInterface for the PoreVe environment

#include "pore.H"

using namespace vsbe;


///////////////////////// Control Interface  /////////////////////////

ModelError
Pore::forceBranch(const char* i_symbol)
{
    ModelError me;
    HookError he;
    bool found;
    GlobalSymbolInfo info;

    he = HookManager::findGlobalSymbol(i_symbol, found, info);
    if (he || !found) {
        me = ME_ILLEGAL_FORCED_BRANCH;
    } else {
        me = PoreInterface::forceBranch(info.iv_address);
    }
    return me;
}


////////////////////  PoreInterface Methods  /////////////////////////

void
Pore::pibMaster(PibTransaction& io_transaction)
{
    ModelError me;

    if (iv_pib == 0) {
        me = ME_NO_BUS_MODEL;
        io_transaction.busError(me);
        FAPI_SET_HWP_ERROR(iv_fapiReturnCode, RC_POREVE_NO_PIB_MODEL);
    } else {
        iv_fapiReturnCode = iv_pib->operation(io_transaction);
        me = io_transaction.iv_modelError;
    }
    if (me != 0) {
    
        // If FAPI error, likely from platform, log it here.
        // Current interface doesn't return FAPI rc up to fapiPoreVe level.
        if (!iv_fapiReturnCode.ok())
        {
            FAPI_ERR("Pore::pibMaster() operation returns FAPI rc 0x%.8X",
                     static_cast<uint32_t>(iv_fapiReturnCode));
            fapiLogError( iv_fapiReturnCode, fapi::FAPI_ERRL_SEV_UNRECOVERABLE );
        }
    
        FAPI_ERR("\nPore::pibMaster() received ModelError %d\n"
                 "Transaction is a %s of address 0x%08x\n"
                 "Transaction data is 0x%016llx",
                 (int)me,
                 ((io_transaction.iv_mode == ACCESS_MODE_WRITE) ?
                  "write" : ((io_transaction.iv_mode == ACCESS_MODE_READ) ?
                             "read" : "fetch")),
                 io_transaction.iv_address,
                 io_transaction.iv_data);
        modelError(me);
    }
}
       
 
void
Pore::ociMaster(OciTransaction& io_transaction)
{
    ModelError me;

    if (iv_oci == 0) {
        me = ME_NO_BUS_MODEL;
        io_transaction.busError(me);
        FAPI_SET_HWP_ERROR(iv_fapiReturnCode, RC_POREVE_NO_OCI_MODEL);
    } else {
        iv_fapiReturnCode = iv_oci->operation(io_transaction);
        me = io_transaction.iv_modelError;
    }
    if (me != 0) {

        // If FAPI error, likely from platform, log it here.
        // Current interface doesn't return FAPI rc up to fapiPoreVe level.
        if (!iv_fapiReturnCode.ok())
        {
            FAPI_ERR("Pore::ociMaster() operation returns FAPI rc 0x%.8X",
                     static_cast<uint32_t>(iv_fapiReturnCode));
            fapiLogError( iv_fapiReturnCode, fapi::FAPI_ERRL_SEV_UNRECOVERABLE );
        }
    
        FAPI_ERR("\nPore::ociMaster() received ModelError %d\n"
                 "Transaction is a %s of address 0x%08x\n"
                 "Transaction data is 0x%016llx",
                 (int)me,
                 ((io_transaction.iv_mode == ACCESS_MODE_WRITE) ?
                  "write" : ((io_transaction.iv_mode == ACCESS_MODE_READ) ?
                             "read" : "fetch")),
                 io_transaction.iv_address,
                 io_transaction.iv_data);
        modelError(me);
    }
}


void
Pore::wait(const uint32_t i_count)
{
    uint64_t simCycles;
    uint64_t nsDelay;
    fapi::ReturnCode rc;
    ModelError me;

    nsDelay = (uint64_t)((i_count / PORE_FREQUENCY) * 1e9);
    simCycles = (uint64_t)
        (SIMULATOR_TICK_FREQUENCY * (i_count / PORE_FREQUENCY));
    nsDelay += 1;               // Always round up the real delay.
    iv_fapiReturnCode = fapiDelay(nsDelay, simCycles);

    if (iv_fapiReturnCode.ok()) {
        me = ME_SUCCESS;
    } else {
        me = ME_WAIT_FAILURE;
        // If FAPI error, likely from platform, log it here.
        // Current interface doesn't return FAPI rc up to fapiPoreVe level.
        FAPI_ERR("Pore::wait() operation returns FAPI rc 0x%.8X",
                 static_cast<uint32_t>(iv_fapiReturnCode));
        fapiLogError( iv_fapiReturnCode, fapi::FAPI_ERRL_SEV_UNRECOVERABLE );
    }
    if (me != 0) {
        modelError(me);
    }
}


void
Pore::hookInstruction(const PoreAddress& i_address, 
                      const uint32_t i_hook,
                      const uint64_t i_parameter)
{
    ModelError me;

    iv_fapiReturnCode = 
        HookManager::runInstructionHook(i_address, i_hook, i_parameter,
                                        *this, *iv_target);
    if (iv_fapiReturnCode.ok()) {
        me = ME_SUCCESS;
    } else {
        me = ME_HOOK_INSTRUCTION_ERROR;
        // If FAPI error, likely from platform, log it here.
        // Current interface doesn't return FAPI rc up to fapiPoreVe level.
        FAPI_ERR("Pore::hookInstruction() operation returns FAPI rc 0x%.8X",
                 static_cast<uint32_t>(iv_fapiReturnCode));
        fapiLogError( iv_fapiReturnCode, fapi::FAPI_ERRL_SEV_UNRECOVERABLE );
    }
    if (me != 0) {
        modelError(me);
    }
}


void
Pore::hookRead(const PoreAddress& i_address)
{
    ModelError me;

    iv_fapiReturnCode = 
        HookManager::runReadHooks(i_address, *this, *iv_target);
    if (iv_fapiReturnCode.ok()) {
        me = ME_SUCCESS;
    } else {
        me = ME_HOOK_READ_ERROR;
        // If FAPI error, likely from platform, log it here.
        // Current interface doesn't return FAPI rc up to fapiPoreVe level.
        FAPI_ERR("Pore::hookRead() operation returns FAPI rc 0x%.8X",
                 static_cast<uint32_t>(iv_fapiReturnCode));
        fapiLogError( iv_fapiReturnCode, fapi::FAPI_ERRL_SEV_UNRECOVERABLE );
    }
    if (me != 0) {
        modelError(me);
    }
}


void
Pore::hookWrite(const PoreAddress& i_address)
{
    ModelError me;

    iv_fapiReturnCode = 
        HookManager::runWriteHooks(i_address, *this, *iv_target);
    if (iv_fapiReturnCode.ok()) {
        me = ME_SUCCESS;
    } else {
        me = ME_HOOK_WRITE_ERROR;
        // If FAPI error, likely from platform, log it here.
        // Current interface doesn't return FAPI rc up to fapiPoreVe level.
        FAPI_ERR("Pore::hookWrite() operation returns FAPI rc 0x%.8X",
                 static_cast<uint32_t>(iv_fapiReturnCode));
        fapiLogError( iv_fapiReturnCode, fapi::FAPI_ERRL_SEV_UNRECOVERABLE );
    }
    if (me != 0) {
        modelError(me);
    }
}


void
Pore::hookFetch(const PoreAddress& i_address)
{
    ModelError me;

    iv_fapiReturnCode = 
        HookManager::runFetchHooks(i_address, *this, *iv_target);
    if (iv_fapiReturnCode.ok()) {
        me = ME_SUCCESS;
    } else {
        me = ME_HOOK_FETCH_ERROR;
        // If FAPI error, likely from platform, log it here.
        // Current interface doesn't return FAPI rc up to fapiPoreVe level.
        FAPI_ERR("Pore::hookFetch() operation returns FAPI rc 0x%.8X",
                 static_cast<uint32_t>(iv_fapiReturnCode));
        fapiLogError( iv_fapiReturnCode, fapi::FAPI_ERRL_SEV_UNRECOVERABLE );
    }
    if (me != 0) {
        modelError(me);
    }
}


////////////////////////  PibSlave Methods ////////////////////////////

// All offsets are known to be legal.  PIB offsets are converted to OCI
// offsets used in the register read/write methods.

fapi::ReturnCode
Pore::operation(Transaction& io_transaction)
{
    ModelError me;
    fapi::ReturnCode rc;

    switch (io_transaction.iv_mode) {

    case ACCESS_MODE_READ:
        me = registerRead((PoreRegisterOffset)(io_transaction.iv_offset * 8),
                          io_transaction.iv_data);
        break;

    case ACCESS_MODE_WRITE:
        me = registerWrite((PoreRegisterOffset)(io_transaction.iv_offset * 8), 
                           io_transaction.iv_data);
        break;

    default:
        me = ME_BUS_SLAVE_PERMISSION_DENIED;
        break;
    }

    if (me) {
        FAPI_SET_HWP_ERROR(rc, RC_POREVE_PORE_OPERATION_ERROR);
    }
    io_transaction.busError(me);
    return rc;
}


////////////////////////////// Creators //////////////////////////////

Pore::Pore(PoreIbufId i_id) :
    PoreInterface(i_id),
    iv_pib(0),
    iv_oci(0),
    iv_dumpDone(false)
{
}


Pore::~Pore()
{
}


////////////////////  Interface Extensions  /////////////////////////

void
Pore::configure(fapi::Target* i_target, Bus* i_pib, Bus* i_oci,
                ecmdDataBufferBase* i_dataBuffer,
                uint32_t i_base, uint64_t i_size, int i_permissions)
{
    iv_target = i_target;
    iv_pib = i_pib;
    iv_oci = i_oci;
    iv_dumpDone = false;
    PibSlave::configure(i_target, i_dataBuffer,
                        i_base, i_size, i_permissions);
}


fapi::ReturnCode
Pore::getFapiReturnCode()
{
    return iv_fapiReturnCode;
}


// The programmer-visible registers that are supported by PoreInterface (the
// first set in the dump) are obtained directly from the interface, since the
// interface already formats them correctly.  The remaining registers are
// obtained from a state extraction.

void
Pore::dump()
{
    PoreState state;
    // Need 3 regs since evaluation order is not guaranteed
    uint64_t reg0, reg1, reg2;

    // NB : "Bugs" in eCMD FAPI_* implementation do not allow format strings
    // to be variables.
#define SEPARATOR "--------------------------------------------------------"

    extractState(state);

    FAPI_ERR(SEPARATOR);
    FAPI_ERR("Target %s", iv_target->toEcmdString());
    FAPI_ERR("PORE dump after %llu instructions.", 
             getInstructions());
    FAPI_ERR(SEPARATOR);
    FAPI_ERR("       PC : %04x.%08x",
             (uint32_t)(pc >> 32) & 0xffff, (uint32_t)pc);
    FAPI_ERR("       D0 : %016llx      D1 : %016llx",
             (uint64_t)d0, (uint64_t)d1);
    FAPI_ERR("       A0 : %04x.%08x         A1 : %04x.%08x",
             (uint32_t)(a0 >> 32), (uint32_t)a0,
             (uint32_t)(a1 >> 32), (uint32_t)a1);
    FAPI_ERR("       P0 : %02x                    P1 : %02x",
             (uint8_t)p0, (uint8_t)p1);
    FAPI_ERR("      CTR : %06x               ETR : %08x.%08x",
             (uint32_t)ctr, 
             (uint32_t)(etr >> 32), (uint32_t)etr);
    FAPI_ERR("    SPRG0 : %08x             IFR : %016llx",
             (uint32_t)sprg0, (uint64_t)ifr);             
    FAPI_ERR(SEPARATOR);
    FAPI_ERR("     IBUF : %08x %08x%08x",
             (uint32_t)((state.get(PORE_IBUF_01, reg0), reg0) >> 32),
             (uint32_t)(state.get(PORE_IBUF_01, reg1), reg1),
             (uint32_t)((state.get(PORE_IBUF_2, reg2), reg2) >> 32));
    FAPI_ERR("   STACK0 : %016llx",
             (state.get(PORE_PC_STACK0, reg0), reg0));
    FAPI_ERR("   STACK1 : %016llx",
             (state.get(PORE_PC_STACK1, reg0), reg0));
    FAPI_ERR("   STACK2 : %016llx",
             (state.get(PORE_PC_STACK2, reg0), reg0));
    FAPI_ERR(SEPARATOR);
    FAPI_ERR("  CONTROL : %016llx  STATUS : %016llx",
             (state.get(PORE_CONTROL, reg0), reg0),
             (state.get(PORE_STATUS, reg1), reg1));
    FAPI_ERR("     DBG0 : %016llx    DBG1 : %016llx",
             (state.get(PORE_DBG0, reg0), reg0),
             (state.get(PORE_DBG1, reg1), reg1));
    FAPI_ERR(SEPARATOR);
    FAPI_ERR("     TBAR : %04x.%08x        EMR : %016llx",
             (uint32_t)((state.get(PORE_TABLE_BASE_ADDR, reg0), reg0) >> 32),
             (uint32_t)(state.get(PORE_TABLE_BASE_ADDR, reg1), reg1),
             (uint64_t)emr);
    FAPI_ERR("      MRR : %01x.%08x          I2C0 : %016llx",
             (uint32_t)((state.get(PORE_MEM_RELOC, reg0), reg0) >> 32),
             (uint32_t)(state.get(PORE_MEM_RELOC, reg1), reg1),
             (state.get(PORE_I2C_E0_PARAM, reg2), reg2));
    FAPI_ERR("     I2C1 : %016llx    I2C2 : %016llx",
             (state.get(PORE_I2C_E1_PARAM, reg0), reg0),
             (state.get(PORE_I2C_E2_PARAM, reg1), reg1));
    FAPI_ERR(SEPARATOR);

#undef SEPARATOR
    iv_dumpDone = true;
}

// Calls the dump() routine if iv_dumpDone is false

void
Pore::dumpOnce()
{
  if (!iv_dumpDone) {
    dump();
  }
}

        
