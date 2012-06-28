/*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/usr/pore/poreve/model/poreinterface.C $
 *
 *  IBM CONFIDENTIAL
 *
 *  COPYRIGHT International Business Machines Corp. 2012
 *
 *  p1
 *
 *  Object Code Only (OCO) source materials
 *  Licensed Internal Code Source Materials
 *  IBM HostBoot Licensed Internal Code
 *
 *  The source code for this program is not published or other-
 *  wise divested of its trade secrets, irrespective of what has
 *  been deposited with the U.S. Copyright Office.
 *
 *  Origin: 30
 *
 *  IBM_PROLOG_END_TAG
 */
// $Id: poreinterface.C,v 1.9 2012/06/18 13:56:57 bcbrock Exp $

/// \file poreinterface.C
/// \brief The PORE hardware interface class

#include "poreinterface.H"
#include "poremodel.H"

using namespace vsbe;


////////////////////////////////////////////////////////////////////////////
// PoreInterface
////////////////////////////////////////////////////////////////////////////


int
PoreInterface::restart()
{
    return iv_model->restart();
}


int
PoreInterface::run(const uint64_t i_instructions, uint64_t& o_ran)
{
    return iv_model->run(i_instructions, o_ran);
}


ModelError
PoreInterface::stop(const int i_stopCode)
{
    return iv_model->stop(i_stopCode);
}


ModelError
PoreInterface::modelError(const ModelError i_modelError)
{
    return iv_model->modelError(i_modelError);
}


void
PoreInterface::clearModelError()
{
    return iv_model->clearModelError();
}


ModelError
PoreInterface::clearHardwareErrors()
{
    return iv_model->clearHardwareErrors();
}


ModelError
PoreInterface::registerRead(const PoreRegisterOffset i_offset, 
                            uint64_t& o_data, 
                            const size_t i_size)
{
    return iv_model->registerRead(i_offset, o_data, i_size);
}


ModelError
PoreInterface::registerWrite(const PoreRegisterOffset i_offset, 
                             const uint64_t i_data, 
                             const size_t i_size)
{
    return iv_model->registerWrite(i_offset, i_data, i_size);
}


ModelError
PoreInterface::registerReadRaw(const PoreRegisterOffset i_offset, 
                               uint64_t& o_data, 
                               const size_t i_size)
{
    return iv_model->registerReadRaw(i_offset, o_data, i_size);
}


ModelError
PoreInterface::registerWriteRaw(const PoreRegisterOffset i_offset, 
                                const uint64_t i_data, 
                                const size_t i_size)
{
    return iv_model->registerWriteRaw(i_offset, i_data, i_size);
}


void
PoreInterface::enableHookInstruction(bool i_enable)
{
    iv_model->enableHookInstruction(i_enable);
}


void
PoreInterface::enableAddressHooks(bool i_enable)
{
    iv_model->enableAddressHooks(i_enable);
}


ModelError
PoreInterface::extractState(PoreState& o_state)
{
    return iv_model->extractState(o_state);
}


ModelError
PoreInterface::installState(const PoreState& i_state)
{
    return iv_model->installState(i_state);
}

ModelError
PoreInterface::forceBranch(const PoreAddress& i_address)
{
    return iv_model->forceBranch(i_address);
}


ModelError
PoreInterface::setPc(const PoreAddress& i_address)
{
    return iv_model->setPc(i_address);
}


ModelError
PoreInterface::setBreakpoint(const PoreAddress& i_address)
{
    return iv_model->setBreakpoint(i_address);
}


ModelError
PoreInterface::disableBreakpoint()
{
    return setBreakpoint(PORE_UNBREAKABLE_ADDRESS);
}


ModelError 
PoreInterface::enableTrap(const bool i_enable)
{
    return iv_model->enableTrap(i_enable);
}


int
PoreInterface::getStatus()
{
    return iv_model->getStatus();
}


ModelError
PoreInterface::getModelError()
{
    return iv_model->getModelError();
}


uint64_t
PoreInterface::getInstructions()
{
    return iv_model->getInstructions();
}


int
PoreInterface::getStopCode()
{
    return iv_model->getStopCode();
}


ModelError
PoreInterface::getmemInteger(const PoreAddress i_address,
                          uint64_t& o_data,
                          const size_t i_size)
{
    return iv_model->getmemInteger(i_address, o_data, i_size);
}


ModelError
PoreInterface::putmemInteger(const PoreAddress i_address,
                             uint64_t i_data,
                             const size_t i_size)
{
    return iv_model->putmemInteger(i_address, i_data, i_size);
}


PoreInterface::PoreInterface(PoreIbufId i_id) :
    d0(this, PORE_D0),
    d1(this, PORE_D1),
    a0(this, PORE_A0),
    a1(this, PORE_A1),
    p0(this, PORE_P0),
    p1(this, PORE_P1),
    ctr(this, PORE_CTR),
    emr(this, PORE_EMR),
    etr(this, PORE_ETR),
    sprg0(this, PORE_SPRG0),
    pc(this, PORE_PC),
    ifr(this, PORE_IFR),
    cia(this, PORE_CIA),
    iv_model(0)
{
    newModel(i_id);
}


PoreInterface::~PoreInterface()
{
    delete iv_model;
}


// The model is always restarted after creation to insure that the model is in
// the correct flush state.

void
PoreInterface::newModel(PoreIbufId i_id)
{
    delete iv_model;
    iv_model = PoreModel::create(i_id, this);
    iv_ibufId = i_id;
    iv_model->restart();
}

