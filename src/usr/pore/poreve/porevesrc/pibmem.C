/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/pore/poreve/porevesrc/pibmem.C $                      */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2013              */
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
// $Id: pibmem.C,v 1.3 2012/12/06 18:03:51 bcbrock Exp $

/// \file pibmem.C
/// \brief A model of the P8 "PIB-attached Memory"

#include "pibmem.H"

using namespace vsbe;

#ifndef VERBOSE
#define VERBOSE 0
#endif

////////////////////////////// Creators //////////////////////////////

Pibmem::Pibmem(const size_t i_memorySize) :
        iv_memorySize(i_memorySize)
{
        reset();
}


Pibmem::~Pibmem()
{
}


//////////////////////////// Manipulators ////////////////////////////


// Model direct and indirect access to memory and control registers.  Note
// that by specification, post inc/dec takes place even if the indirect access
// takes an error.

fapi::ReturnCode
Pibmem::operation(Transaction& io_transaction)
{
    fapi::ReturnCode rc;

    // The transaction is initially marked as successful, but may later pick
    // up PIB error codes.

    io_transaction.busError(ME_SUCCESS);


    // Split on direct vs. indirect accesses

    if (io_transaction.iv_offset < PIBMEM_CONTROL_BASE) {

        // These are simple direct PIB read/write of memory
 
        rc = memoryOperation(io_transaction, true);

        if (VERBOSE) {
            FAPI_DBG("PIBMEM : Direct to 0x%08x, %s 0x%016llx", 
                     io_transaction.iv_offset, 
                     ((io_transaction.iv_mode == ACCESS_MODE_WRITE) ?
                      "Write" : ((io_transaction.iv_mode == ACCESS_MODE_READ) ?
                                 "Read" : "Execute")),
                     io_transaction.iv_data);
        }

    } else {

        switch (io_transaction.iv_mode) {

        case ACCESS_MODE_READ:
        case ACCESS_MODE_EXECUTE:

            // Register reads and indirect memory reads

            switch (io_transaction.iv_offset) {

            case PIBMEM_CONTROL:
                io_transaction.iv_data = iv_control.value;
                break;

            case PIBMEM_ADDRESS:
                io_transaction.iv_data = iv_address.value;
                break;

            case PIBMEM_STATUS:
                io_transaction.iv_data = iv_status.value;
                break;

            case PIBMEM_RESET:
                io_transaction.iv_data = iv_reset.value;
                break;

            case PIBMEM_REPAIR:
                io_transaction.iv_data = iv_repair;
                break;

            case PIBMEM_DATA:
                rc = memoryOperation(io_transaction, false);
                break;

            case PIBMEM_DATA_INC:
                if (iv_control.fields.auto_pre_increment) {
                    incrAddress(1);
                }
                rc = memoryOperation(io_transaction, false);
                if (!iv_control.fields.auto_pre_increment) {
                    incrAddress(1);
                }                            
                break;

            case PIBMEM_DATA_DEC:
                if (!iv_control.fields.auto_post_decrement) {
                    incrAddress(-1);
                }
                rc = memoryOperation(io_transaction, false);
                if (iv_control.fields.auto_post_decrement) {
                    incrAddress(-1);
                }
                break;

            default:
                FAPI_ERR("PIBMEM: Can't read register at offset 0x%08x\n",
                         io_transaction.iv_offset);
                FAPI_SET_HWP_ERROR(rc, RC_POREVE_PIBMEM_CONTROL_ERROR);
                break;
            }

            break;

        case ACCESS_MODE_WRITE:

            // Register writes and indirect memory writes

            switch (io_transaction.iv_offset) {

            case PIBMEM_CONTROL:
                iv_control.value = 
                    io_transaction.iv_data & PIBMEM_CONTROL_DEFINED;
                break;

            case PIBMEM_ADDRESS:
                iv_address.value = 
                    io_transaction.iv_data & PIBMEM_ADDRESS_DEFINED;
                break;

            case PIBMEM_RESET:
                iv_reset.value = 
                    io_transaction.iv_data & PIBMEM_RESET_DEFINED;
                if (iv_reset.fields.reset_code == PIBMEM_RESET_CODE) {
                    reset();
                }
                break;

            case PIBMEM_REPAIR:
                // Behavior of this register is beyond the scope of the model
                iv_repair = io_transaction.iv_data;
                break;

            case PIBMEM_DATA:
                rc = memoryOperation(io_transaction, false);
                break;

            case PIBMEM_DATA_INC:
                if (iv_control.fields.auto_pre_increment) {
                    incrAddress(1);
                }
                rc = memoryOperation(io_transaction, false);
                if (!iv_control.fields.auto_pre_increment) {
                    incrAddress(1);
                }                            
                break;

            case PIBMEM_DATA_DEC:
                if (!iv_control.fields.auto_post_decrement) {
                    incrAddress(-1);
                }
                rc = memoryOperation(io_transaction, false);
                if (iv_control.fields.auto_post_decrement) {
                    incrAddress(-1);
                }
                break;

            default:
                FAPI_ERR("PIBMEM: Can't write register at offset 0x%08x\n",
                         io_transaction.iv_offset);
                FAPI_SET_HWP_ERROR(rc, RC_POREVE_PIBMEM_CONTROL_ERROR);
                break;
            }

            break;

        default:
            FAPI_ERR("PIBMEM: Transaction mode is illegal - %d\n", 
                     io_transaction.iv_mode);
            FAPI_SET_HWP_ERROR(rc, RC_POREVE_PIBMEM_CONTROL_ERROR);
            break;
        }
        
        if (VERBOSE) {
            FAPI_DBG("PIBMEM : Indirect to 0x%08x, %s 0x%016llx", 
                     io_transaction.iv_offset, 
                     ((io_transaction.iv_mode == ACCESS_MODE_WRITE) ?
                      "Write" : ((io_transaction.iv_mode == ACCESS_MODE_READ) ?
                                 "Read" : "Execute")),
                     io_transaction.iv_data);
        }

    }

    return rc;
}


////////////////////////// Implementation  //////////////////////////////////


// Note the differences in the error return codes for the error cases.  Asking
// for memory that does not exist in the hardware gives a normal return with a
// PIB 'address error' status code.  If the access was indirect then the
// PCB_PACKET_ERROR code is returned. Asking for memory that has not been
// mapped by the application yields a model error and a FAPI error.

fapi::ReturnCode 
Pibmem::memoryOperation(Transaction& io_transaction, 
                        const bool i_direct)
{
    fapi::ReturnCode rc;
    uint32_t saveAddress, saveOffset;

    if (i_direct) {
        if (io_transaction.iv_offset >= iv_memorySize) {

            iv_status.fields.addr_invalid = 1;
            if (io_transaction.iv_mode == ACCESS_MODE_WRITE) {
                iv_status.fields.write_invalid = 1;
            } else {
                iv_status.fields.read_invalid = 1;
            }
            ((PibTransaction&)io_transaction).iv_pcbReturnCode = 
                PCB_ADDRESS_ERROR;

        } else {

            rc = PibMemory::operation(io_transaction);

            if (rc) {
                FAPI_ERR("The previous error was from a direct "
                         "PIBMEM operation to the indicated address");
            }
        }

    } else {

        if (io_transaction.iv_offset >= iv_memorySize) {
        
            iv_status.fields.bad_array_address = 1;
            ((PibTransaction&)io_transaction).iv_pcbReturnCode = 
                PCB_PACKET_ERROR;
        } else {

            saveAddress = io_transaction.iv_address;
            saveOffset = io_transaction.iv_offset;

            io_transaction.iv_address = iv_address.fields.address_pointer;
            io_transaction.iv_offset = iv_address.fields.address_pointer;

            rc = PibMemory::operation(io_transaction);

            io_transaction.iv_address = saveAddress;
            io_transaction.iv_offset = saveOffset;

            if (rc) {
                FAPI_ERR("The previous error was from a PIBMEM operation "
                         "targeting the indicated address, issued "
                         "indirectly through the PIBMEM control "
                         "register 0x%08x",
                         saveAddress);
            }
        }
    }

    return rc;
}


void
Pibmem::incrAddress(const int i_incr)
{
    iv_address.fields.address_pointer = 
        iv_address.fields.address_pointer + i_incr;
}


void
Pibmem::reset() {
        iv_control.value = 0;
        iv_address.value = 0;
        iv_status.value = 0;
        iv_reset.value = 0;
        iv_data = 0;
        iv_dataInc = 0;
        iv_dataDec = 0;
        iv_repair = 0;

        // The reset state (and subsequent status reads) show the FSM idle
        // state

        iv_status.fields.fsm_present_state = PIBMEM_FSM_IDLE;
}

/* Local Variables: */
/* c-basic-offset: 4 */
/* End: */
