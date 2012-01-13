//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/pore/poreve/model/poremodel.C $
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
// $Id: poremodel.C,v 1.19 2011/11/11 00:50:35 bcbrock Exp $

/// \file poremodel.C
/// \brief The PORE hardware engine model and interface to the virtual
/// environment. 

#include "poremodel.H"

using namespace vsbe;


////////////////////////////////////////////////////////////////////////////
// PoreModel
////////////////////////////////////////////////////////////////////////////

/////////////// Common Creation/Control Interface ////////////////////

int 
PoreModel::restart()
{
    flushReset();
    iv_modelError = ME_SUCCESS;
    iv_instructions = 0;
    iv_stopCode = 0;
    return getStatus();
}


// run() refuses to do anything if the status shows a model error or an error
// halt. Otherwise the status is used to determine how to restart the machine
// if it is currently stopped. Then the model is stepped until the number of
// instructions has been executed or the status is non-0.  If a debug stop was
// requested this condition is recorded so that PORE_STATUS_DEBUG_STOP can be
// added back to the status at the end.

// Note: The system model or hooks may call modelError() to update the private
// iv_modelError field to record errors that are not otherwise visible to the
// PORE hardware model. This will cause the PORE_STATUS_MODEL_ERROR to be set
// and terminate the run loop.  However note that the instruction will
// complete on the PORE.

// Note: run(0, ran) simply has the effect of making a stopped machine
// runnable.

// Note: This method will need to be overridden/reimplemented in a derived
// class that controls actual PORE hardware or a simulation model.

int
PoreModel::run(const uint64_t i_instructions, uint64_t& o_ran)
{
    uint64_t n = i_instructions;
    uint64_t control;
    ModelError me = ME_SUCCESS;
    bool stepped;
    bool writeControl = false;
    int iv_status;

    do {
        
        o_ran = 0;
        iv_stopCode = 0;
        iv_status = getStatus();

        if (iv_status & (PORE_STATUS_ERROR_HALT | PORE_STATUS_MODEL_ERROR)) {
            break;
        }

        me = registerRead(PORE_CONTROL, control);
        if (me != 0) break;

        if (iv_status & PORE_STATUS_HARDWARE_STOP) {
            control &= ~BE64_BIT(0);
            writeControl = true;
        }
        if (iv_status & (PORE_STATUS_BREAKPOINT | PORE_STATUS_TRAP)) {
            control |= BE64_BIT(1);
            writeControl = true;
        }

        if (writeControl) {
            me = registerWrite(PORE_CONTROL, control);
        }
        if (me != 0) break;
    
        while (n--) {
            me = step(stepped);
            if ((me != 0) || !stepped) {
                break;
            }
            o_ran++;
            iv_instructions++;
            if (getModelError() != 0) {
                break;
            }
        }

    } while (0);

    if (me != 0) {
        modelError(me);
    }

    return getStatus();
}
   

ModelError
PoreModel::stop(const int i_stopCode)
{
    uint64_t control;
    ModelError me;

    do {
        me = iv_modelError;
        if (me) break;
        me = registerRead(PORE_CONTROL, control);
        if (me) break;
        me = registerWrite(PORE_CONTROL, control | BE64_BIT(0));
        if (me) break;
        if (i_stopCode != 0) {
            iv_stopCode = i_stopCode;
        }
    } while (0);

    return me;
}

ModelError
PoreModel::modelError(const ModelError i_modelError)
{
    if (i_modelError != 0) {
        iv_modelError = i_modelError;
    } 
    return i_modelError;
}


void
PoreModel::clearModelError()
{
    iv_modelError = ME_SUCCESS;
}


ModelError
PoreModel::clearHardwareErrors()
{
    ModelError me;

    me = registerWrite(PORE_DBG0, 0);
    if (me == 0) {
        me = registerWrite(PORE_DBG1, 0);
    }
    return me;
}


// Set the PC as specified, leaving the engine in the stopped state. By
// hardware specification, if the control register is written with the set_pc
// bit set, then the only action is to update the PC, which comes in as the
// low-order 48 bits of the CONTROL register.

ModelError
PoreModel::setPc(const PoreAddress& i_pc)
{
    do {

        if (iv_modelError != 0) break;
        stop(STOP_CODE_SET_PC);
        if (iv_modelError != 0) break;

        iv_modelError = 
            registerWrite(PORE_CONTROL, (uint64_t)i_pc | BE64_BIT(3));

    } while (0);
    return iv_modelError;
}


// The breakpoint address occupies the lower 48 bits of the control register.

ModelError
PoreModel::setBreakpoint(const PoreAddress& i_address)
{
    uint64_t control, address;
    ModelError me;

    do {

        me = registerRead(PORE_CONTROL, control);
        if (me != 0) break;

        address = i_address;
        control &= ~BE64_MASK(16, 63);
        control |= address;

        me = registerWrite(PORE_CONTROL, control);
        if (me != 0) break;

    } while (0);
    return me;
}


// Bit 11 of the PORE CONTROL register is the TRAP enable bit.

ModelError
PoreModel::enableTrap(const bool i_enable)
{
    ModelError me;
    uint64_t control;

    me = registerRead(PORE_CONTROL, control);
    if (me == 0) {
        if (i_enable) {
            control |= BE64_BIT(11); 
        } else {
            control &= ~BE64_BIT(11);
        }
        me = registerWrite(PORE_CONTROL, control);
    }
    return me;
}


// Abstract status bits are set as documented.  If a ModelError is present the
// state is assumed to be corrupted so PORE_STATUS_MODEL_ERROR is the only
// status returned.

int
PoreModel::getStatus()
{

    ModelError me;
    uint64_t control, status, ibuf01, dbg1;
    int finalStatus;
    const unsigned PORE_OPCODE_WAIT = 1;
    const unsigned PORE_OPCODE_TRAP = 2;
    const unsigned PORE_STATE_ABR = 0xb; // PORE HW State machine state

    do {

        finalStatus = 0;
        me = iv_modelError;
        if (me != 0) break;

        me = registerRead(PORE_CONTROL, control);
        if (me != 0) break;
        me = registerRead(PORE_STATUS, status);
        if (me != 0) break;
        me = registerRead(PORE_IBUF_01, ibuf01);
        if (me != 0) break;
        me = registerRead(PORE_DBG1, dbg1);
        if (me != 0) break;

        // Status associated with the hardware stop condition

        if (control & BE64_BIT(0)) {

            finalStatus |= PORE_STATUS_HARDWARE_STOP;

            if ((BE64_GET_FIELD(ibuf01, 0, 6) == PORE_OPCODE_WAIT) &&
                (BE64_GET_FIELD(ibuf01, 8, 31) == 0)) {
                finalStatus |= PORE_STATUS_HALTED;
            }

            if (dbg1 & BE64_BIT(63)) {
                finalStatus |= PORE_STATUS_ERROR_HALT;
            }
        }

        // Status associated with the engine being in the ABR (Address
        // BReakpoint) state.  We need to disambiguate TRAP, BREAKPOINT, and
        // TRAP+BREAKPOINT. This is needlesssly complicated due to lack of
        // direct hardware status.

        if (BE64_GET_FIELD(status, 3, 6) == PORE_STATE_ABR) {
            
            if ((BE64_GET_FIELD(ibuf01, 0, 6) == PORE_OPCODE_TRAP) &&
                BE64_GET_FIELD(control, 11, 11)) {
                finalStatus |= PORE_STATUS_TRAP;
            }

            if (BE64_GET_FIELD(control, 16, 63) == 
                BE64_GET_FIELD(status, 16, 63)) {
                finalStatus |= PORE_STATUS_BREAKPOINT;
            } else {
                if (!(finalStatus & PORE_STATUS_TRAP)) {
                    finalStatus |= PORE_STATUS_BREAKPOINT;
                }
            }
        }
    } while (0);

    if (iv_stopCode != 0) {
        finalStatus |= PORE_STATUS_DEBUG_STOP;
    }

    if (me != 0) {
        modelError(me);
        finalStatus = PORE_STATUS_MODEL_ERROR;
    }

    return finalStatus;
}


ModelError
PoreModel::getModelError()
{
    return iv_modelError;
}


uint64_t
PoreModel::getInstructions()
{
    return iv_instructions;
}


int
PoreModel::getStopCode()
{
    return iv_stopCode;
}


////////////////////  PoreInterface Methods  /////////////////////////

// The interface methods are responsible for ensuring that any errors are
// captured in the iv_modelError member of the PoreModel.

void
PoreModel::pibMaster(PibTransaction& transaction)
{
    iv_interface->pibMaster(transaction);
}


void
PoreModel::ociMaster(OciTransaction& transaction)
{
    iv_interface->ociMaster(transaction);
}


void
PoreModel::wait(const uint32_t i_count) 
{
    iv_interface->wait(i_count);
}


void
PoreModel::hookInstruction(const PoreAddress& i_address, 
                           const uint32_t i_hook,
                           const uint64_t i_parameter) 
{
    iv_interface->hookInstruction(i_address, i_hook, i_parameter);
}


void
PoreModel::hookRead(const PoreAddress& i_address) 
{
    iv_interface->hookRead(i_address);
}


void
PoreModel::hookWrite(const PoreAddress& i_address) 
{
    iv_interface->hookWrite(i_address);
}


void
PoreModel::hookFetch(const PoreAddress& i_address) 
{
    iv_interface->hookFetch(i_address);
}


void
PoreModel::errorIntr(void)
{
    iv_interface->errorIntr();
}


void
PoreModel::fatalErrorIntr(void)
{
    iv_interface->fatalErrorIntr();
}


////////////////////////////// Creators //////////////////////////////

PoreModel::PoreModel(PoreIbufId i_id, PoreInterface *i_interface) :
    iv_ibufId(i_id),
    iv_modelError(ME_PORE_UNINITIALIZED),
    iv_instructions(0),
    iv_stopCode(0),
    iv_interface(i_interface)
{
}


PoreModel::~PoreModel()
{
}



        
