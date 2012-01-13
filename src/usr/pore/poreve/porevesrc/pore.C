//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/pore/poreve/porevesrc/pore.C $
//
//  IBM CONFIDENTIAL
//
//  COPYRIGHT International Business Machines Corp. 2012
//
//  p1
//
//  Object Code Only (OCO) source materials
//  Licensed Internal Code Source Materials
//  IBM HostBoot Licensed Internal Code
//
//  The source code for this program is not published or other-
//  wise divested of its trade secrets, irrespective of what has
//  been deposited with the U.S. Copyright Office.
//
//  Origin: 30
//
//  IBM_PROLOG_END
// $Id: pore.C,v 1.13 2011/11/17 19:05:22 jeshua Exp $

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

/// \bug We need a FAPI return code for an illegaly configured model

void
Pore::pibMaster(PibTransaction& io_transaction)
{
    ModelError me;

    if (iv_pib == 0) {
        me = ME_NO_BUS_MODEL;
        io_transaction.busError(me);
        iv_fapiReturnCode = 1; /// \bug Need a return code
    } else {
        iv_fapiReturnCode = iv_pib->operation(io_transaction);
        me = io_transaction.iv_modelError;
    }
    if (me != 0) {
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
        iv_fapiReturnCode = 1; /// \bug Need a return code
    } else {
        iv_fapiReturnCode = iv_oci->operation(io_transaction);
        me = io_transaction.iv_modelError;
    }
    if (me != 0) {
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

    nsDelay = (uint64_t)((i_count * 1e9) / PORE_FREQUENCY);

    simCycles = (uint64_t)
        (SIMULATOR_TICK_FREQUENCY * (i_count / PORE_FREQUENCY));
    nsDelay += 1;               // Always round up the real delay.
    iv_fapiReturnCode = fapiDelay(nsDelay, simCycles);

    if (iv_fapiReturnCode == 0) {
        me = ME_SUCCESS;
    } else {
        me = ME_WAIT_FAILURE;
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
        rc = 1;                 /// \bug Fix this
    }
    io_transaction.busError(me);
    return rc;
}


////////////////////////////// Creators //////////////////////////////

Pore::Pore(PoreIbufId i_id) :
    PoreInterface(i_id),
    iv_pib(0),
    iv_oci(0),
    iv_target(NULL)
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
    PibSlave::configure(i_target, i_dataBuffer,
                        i_base, i_size, i_permissions);
}


fapi::ReturnCode
Pore::getFapiReturnCode()
{
    return iv_fapiReturnCode;
}

        
