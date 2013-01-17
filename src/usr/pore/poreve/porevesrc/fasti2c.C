/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/pore/poreve/porevesrc/fasti2c.C $                     */
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
// $Id: fasti2c.C,v 1.11 2012/12/06 18:03:51 bcbrock Exp $

/// \file fasti2c.C
/// \brief The "fast-mode" I2C controllers and I2C memory models used
/// to implement the OTPROM, PNOR and SEEPROM interfaces.

#include "fasti2c.H"

/// Diagnostic aid for debugging fasti2c.C
#ifdef DEBUG_FASTI2C
#define BUG() \
    FAPI_ERR("\n>>> fasti2c:Bug trapped at %s:%d\n\n", \
             __FILE__, __LINE__)
#else
#define BUG()
#endif  // DEBUG_FASTI2C

using namespace vsbe;

////////////////////////////////////////////////////////////////////////////
// I2cMemory
////////////////////////////////////////////////////////////////////////////

I2cMemory::I2cMemory()
{
}


I2cMemory::~I2cMemory()
{
}


void
I2cMemory::configure(const uint8_t i_bytes)
{
    iv_addressBytes = i_bytes;
}


ModelError
I2cMemory::addressWrite(const size_t i_bytes, const uint32_t i_address)
{
    ModelError me;

    if (i_bytes != iv_addressBytes) {
        BUG();
        FAPI_ERR("I2cMemory::addressWrite() failed, "
                 "address has %zu bytes, device supports %zu-byte addresses",
                 i_bytes, iv_addressBytes);
        me = ME_I2CMEMORY_ILLEGAL_ADDRESS;
    } else {
        me = ME_SUCCESS;
        iv_address = i_address;
    }
    return me;
}


ModelError
I2cMemory::dataRead(const size_t i_bytes, uint64_t& o_data)
{
    ModelError me;

    me = read(iv_address, o_data, i_bytes);
    if (me == 0) {
        iv_address += i_bytes;
    }
    return me;
}


ModelError
I2cMemory::dataWrite(const size_t i_bytes, const uint64_t i_data)
{
    ModelError me;

    me = write(iv_address, i_data, i_bytes);
    if (me == 0) {
        iv_address += i_bytes;
    }
    return me;
}


////////////////////////////////////////////////////////////////////////////
// FastI2cController
////////////////////////////////////////////////////////////////////////////

FastI2cController::FastI2cController() :
    iv_devices(0),
    iv_state(IDLE)
{
        iv_status.value = 0;
}


// The destructor deletes the circular list of devices.

FastI2cController::~FastI2cController()
{
    I2cDevice *p, *next;

    if (iv_devices != 0) {
        for (p = iv_devices->next; p != iv_devices; p = next) {
            next = p->next;
            delete p;
        }
        delete iv_devices;
    }
}


ModelError
FastI2cController::attachMemory(I2cMemory* i_memory,
                                const unsigned i_port,
                                const unsigned i_deviceAddress)
{
    ModelError me = ME_SUCCESS;
    FastI2cControlRegister control; // Used to validate i_Port and i_deviceId
    I2cDevice* device = new I2cDevice;
    
    control.fields.port_number = i_port;
    control.fields.device_address = i_deviceAddress;
    if ((control.fields.port_number != i_port) ||
        (control.fields.device_address != i_deviceAddress)) {
        BUG();
        me = ME_INVALID_ARGUMENT;

    } else {

        device->iv_port = i_port;
        device->iv_deviceAddress = i_deviceAddress;
        device->iv_memory = i_memory;

        if (iv_devices == 0) {
            iv_devices = device;
            device->next = device;
        } else {

            if (findDevice(i_port, i_deviceAddress) != 0) {
                BUG();
                me = ME_DUPLICATE_CONFIGURATION;
            } else {
                device->next = iv_devices->next;
                iv_devices->next = device;
            }
        }
    }
    if (me != 0) {
        delete device;
    }
    return me;
}


// Modeling notes:
//
// o Writing the RESET register clears the STATUS register if bit 0 is set,
// however we require that writes to the RESET register only occur when the
// state machine is idle.
//
// o  Our models ignore the I2C Speed
//
// o  Transactions complete in 0 time and polling always succeeds on the first
//    read of the status register.  This is done to simplify the PORE
//    engine model.
//
// o  Only the following types of control register actions are modeled:
//
//    *  Set address : with_start; with_address; !with_continue; with_stop;
//                     RNW == 1; Data_length == [4, 8]; 
//                     Address length != 0; Address provided
//                     Setting the address also fetches data and increments
//                     the address stored in memory
//
//    *  Data Read   : with_start; with_address; !with_continue; with_stop;
//                     RNW == 1; Data_length == [4, 8]; 
//                      Address length == 0; No address provided
//                     This operation fetches data and increments the address
//                     stored in memory.
//
//    *  Data write  : with_start; with_address; !with_continue; with_stop;
//                     RNW == 0; Data_length == 8
//                     Addrress length != 0; Address provided
//
// o  The memory models hold the last address written and implement the
//    address auto-increment after every read or write
//
// o  Redundant reads of the STATUS register are allowed
//
// o  PORE only allows 4/8 byte reads and 8 byte writes.

fapi::ReturnCode
FastI2cController::operation(Transaction& io_transaction)
{
    ModelError me;
    fapi::ReturnCode rc;

    if (0) {
        if (io_transaction.iv_mode == ACCESS_MODE_WRITE) {
            FAPI_DBG("FASTI2C : write : offset = %u, data = 0x%016llx\n",
                     io_transaction.iv_offset, 
                     io_transaction.iv_data);
        } else {
            FAPI_DBG("FASTI2C : read : offset = %u\n",
                     io_transaction.iv_offset);        
        }
    }

    switch (io_transaction.iv_offset) {

    case FASTI2C_RESET_OFFSET:

        if (iv_state != IDLE) {
            BUG();
            me = ME_FASTI2C_SEQUENCE_ERROR;
        } else if (io_transaction.iv_data & BE64_BIT(0)) {
            iv_status.value = 0;
            me = ME_SUCCESS;
        } else {
            me = ME_SUCCESS;
        }
        break;


    case FASTI2C_CONTROL_OFFSET:

        if (io_transaction.iv_mode != ACCESS_MODE_WRITE) {
            BUG();
            me = ME_WRITE_ONLY_REGISTER;
            break;
        }
        
        iv_control.value = io_transaction.iv_data;

        if (!iv_control.fields.with_start   ||
            !iv_control.fields.with_address ||
            iv_control.fields.read_continue ||
            !iv_control.fields.with_stop) {
            BUG();
            me = ME_FASTI2C_CONTROL_ERROR;
            break;
        }

        if (iv_control.fields.read_not_write == 0) {

            // A WRITE command is only allowed in the WRITE_COMMAND_EXPECTED
            // state.

            if (iv_state != WRITE_COMMAND_EXPECTED) {
                BUG();
                me = ME_FASTI2C_SEQUENCE_ERROR;
            }
                
            if ((iv_control.fields.address_range == 0) ||
                (iv_control.fields.data_length != 8)) {
                BUG();
                me = ME_FASTI2C_CONTROL_ERROR;
                break;
            }

            me = addressWrite();
            if (me) break;
            me = initialDataWrite();
            if (me) break;
            me = finalDataWrite(iv_data);
            if (me) break;

            iv_state = DATA_WRITE_ONGOING;
            break;

        } else {
            
            // A READ command is only expected in the IDLE state

            if (iv_state != IDLE) {
                BUG();
                me = ME_FASTI2C_SEQUENCE_ERROR;
                break;
            }
                
            if ((iv_control.fields.data_length != 4) &&
                (iv_control.fields.data_length != 8)) {
                BUG();
                me = ME_FASTI2C_CONTROL_ERROR;
                break;
            }

            if (iv_control.fields.address_range != 0) {
                me = addressWrite();
                if (me) break;
                iv_state = ADDRESS_WRITE_ONGOING;
            }

            me = dataRead();
            if (me) break;

            iv_state = DATA_READ_ONGOING;
            break;
        }

    case FASTI2C_STATUS_OFFSET:

        if (io_transaction.iv_mode != ACCESS_MODE_READ) {
            BUG();
            me = ME_READ_ONLY_REGISTER;

        } else {

            switch (iv_state) {

            case ADDRESS_WRITE_ONGOING:
            case DATA_WRITE_ONGOING:
                iv_status.value = 0;
                iv_status.fields.i2c_command_complete = 1;
                io_transaction.iv_data = iv_status.value;
                iv_state = IDLE;
                me = ME_SUCCESS;
                break;

            case DATA_READ_ONGOING:
                iv_status.value = 0;
                iv_status.fields.i2c_command_complete = 1;
                iv_status.fields.i2c_fifo_entry_count = 
                    iv_control.fields.data_length;
                io_transaction.iv_data = iv_status.value;
                iv_state = DATA_AVAILABLE;
                me = ME_SUCCESS;
                break;

            case IDLE:
                io_transaction.iv_data = iv_status.value;
                me = ME_SUCCESS;
                break;
                
            default:
                BUG();
                me = ME_FASTI2C_SEQUENCE_ERROR;
                break;
            }
        }
        break;


    case FASTI2C_DATA_OFFSET:

        if ((io_transaction.iv_mode == ACCESS_MODE_READ) ||
            (io_transaction.iv_mode == ACCESS_MODE_EXECUTE)) {

            // DATA reads must follow a command and status poll

            switch (iv_state) {

            case DATA_AVAILABLE:
                io_transaction.iv_data = iv_fifo;
                iv_state = IDLE;
                me = ME_SUCCESS;
                break;

            default:
                BUG();
                me = ME_FASTI2C_SEQUENCE_ERROR;
                break;
            }

        } else {

            // DATA writes must occur in the idle state, and be followed by a
            // command and data poll.

            if (iv_state == IDLE) {

                iv_data = io_transaction.iv_data;
                iv_state = WRITE_COMMAND_EXPECTED;
                me = ME_SUCCESS;

            } else {

                BUG();
                me = ME_FASTI2C_SEQUENCE_ERROR;
            }
        }
        break;


    default:
        BUG();
        me = ME_ILLEGAL_REGISTER_OFFSET;
        break;
    }

    if (me != 0) {
        iv_state = ERROR;
        FAPI_SET_HWP_ERROR(rc, RC_POREVE_FASTI2C_ERROR);
    }
    io_transaction.busError(me);
    return rc;
}


// Find the device in the circular device list and spin the device to the
// front of the list if found.

I2cDevice*
FastI2cController::findDevice(const unsigned i_port, 
                              const unsigned i_deviceAddress)
{
    I2cDevice* p;

    p = iv_devices;
    if (p != 0) {
        do {
            if ((p->iv_port == i_port) && 
                (p->iv_deviceAddress == i_deviceAddress)) {
                iv_devices = p;
                break;
            }
            if (p == iv_devices) {
                p = 0;
                break;
            }
        } while(1);
    }
    return p;
}


uint32_t
FastI2cController::getI2cAddress(const FastI2cControlRegister i_control)
{
    size_t addressBytes = i_control.fields.address_range;

    return i_control.words.low_order >> ((4 - addressBytes) * 8);
}
                

// The address is left-justified in the low-order 32 bits of the control
// register. 

ModelError
FastI2cController::addressWrite()
{
    ModelError me;
    unsigned port = iv_control.fields.port_number;
    unsigned deviceAddress = iv_control.fields.device_address;
    size_t addressBytes = iv_control.fields.address_range;
    I2cDevice* p;

    p = findDevice(port, deviceAddress);
    if (p == 0) {
        BUG();
        me = ME_NOT_MAPPED_ON_FASTI2C_CONTROLLER;
    } else {
        me = p->iv_memory->addressWrite(addressBytes,
                                        getI2cAddress(iv_control));
    }
    return me;
}


ModelError
FastI2cController::dataRead()
{
    ModelError me;
    unsigned port = iv_control.fields.port_number;
    unsigned deviceAddress = iv_control.fields.device_address;
    size_t dataBytes = iv_control.fields.data_length;
    uint64_t data;
    I2cDevice* p;

    p = findDevice(port, deviceAddress);
    if (p == 0) {
        BUG();
        me = ME_NOT_MAPPED_ON_FASTI2C_CONTROLLER;
    } else {
        me = p->iv_memory->dataRead(dataBytes, data);
        iv_fifo = data << (64 - (dataBytes * 8));
    }
    return me;
}


// For addresses < 4 bytes, the first slug of data occupies the remainder of
// the low-order word of the control register.  Any remaining bytes come in on
// the next transaction targeting the data register.  This code assumes 8-byte
// only data writes.

ModelError
FastI2cController::initialDataWrite()
{
    unsigned addressBytes = iv_control.fields.address_range;

    if (addressBytes < 4) {
        iv_fifo = 
            BE64_GET_FIELD(iv_control.words.low_order, 
                           32 + (addressBytes * 8), 
                           63) << 
            ((4 - addressBytes) * 8);
    }
    return ME_SUCCESS;
}


// Assume 8-byte only write transactions

ModelError
FastI2cController::finalDataWrite(const uint64_t i_data)
{
    ModelError me;
    unsigned port = iv_control.fields.port_number;
    unsigned deviceAddress = iv_control.fields.device_address;
    size_t addressBytes = iv_control.fields.address_range;
    I2cDevice* p;

    iv_fifo =
        BE64_SET_FIELD(iv_fifo, addressBytes * 8, 63,
                       BE64_GET_FIELD(i_data, 0, 
                                      ((8 - addressBytes) * 8)) - 1);

    p = findDevice(port, deviceAddress);
    if (p == 0) {
        BUG();
        me = ME_NOT_MAPPED_ON_FASTI2C_CONTROLLER;
    } else {
        me = p->iv_memory->dataWrite(8, iv_fifo);
    }
    return me;
}


////////////////////////////////////////////////////////////////////////////
// LpcController
////////////////////////////////////////////////////////////////////////////

LpcController::LpcController() :
    iv_eccStart(0),
    iv_eccStop(LPC_MEMORY_MAX_SIZE)
{
}


LpcController::~LpcController()
{
}


fapi::ReturnCode
LpcController::operation(Transaction& io_transaction)
{
    ModelError me = ME_SUCCESS;
    fapi::ReturnCode rc;
    bool handledBySuperclass = false;
    FastI2cControlRegister control;
    uint32_t address;

    switch (io_transaction.iv_offset) {

    case LPCM_ECC_START_OFFSET:

        if (iv_state != IDLE) {
            BUG();
            me = ME_FASTI2C_SEQUENCE_ERROR;

        } else if (io_transaction.iv_mode == ACCESS_MODE_READ) {
            io_transaction.iv_data = iv_eccStart;
            me = ME_SUCCESS;

        } else if (io_transaction.iv_mode == ACCESS_MODE_WRITE) {
            iv_eccStart = io_transaction.iv_data;
            me = ME_SUCCESS;

        } else {
            BUG();
            me = ME_BUS_SLAVE_PERMISSION_DENIED;
        }
        break;

    case LPCM_ECC_STOP_OFFSET:

        if (iv_state != IDLE) {
            BUG();
            me = ME_FASTI2C_SEQUENCE_ERROR;

        } else if (io_transaction.iv_mode == ACCESS_MODE_READ) {
            io_transaction.iv_data = iv_eccStop;
            me = ME_SUCCESS;

        } else if (io_transaction.iv_mode == ACCESS_MODE_WRITE) {
            iv_eccStop = io_transaction.iv_data;
            me = ME_SUCCESS;

        } else {
            BUG();
            me = ME_BUS_SLAVE_PERMISSION_DENIED;
        }
        break;

    default:

        if ((io_transaction.iv_offset == FASTI2C_CONTROL_OFFSET) &&
            (io_transaction.iv_mode == ACCESS_MODE_WRITE)) {

            control.value = io_transaction.iv_data;
            address = getI2cAddress(control);
            if ((address < iv_eccStart) || (address >= iv_eccStop)) {
                BUG();
                me = ME_LPC_ILLEGAL_ADDRESS;

            } else {

                handledBySuperclass = true;
                rc = FastI2cController::operation(io_transaction);
            }
        } else {

            handledBySuperclass = true;
            rc = FastI2cController::operation(io_transaction);
        }
        break;
    }
    if (!handledBySuperclass) {
        if (me != 0) {
            FAPI_SET_HWP_ERROR(rc, RC_POREVE_LPC_ERROR);
        }
        io_transaction.busError(me);
    }
    return rc;
}
    
        

        
    

    
        
    
    
