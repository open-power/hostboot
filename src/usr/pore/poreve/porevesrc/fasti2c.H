/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/pore/poreve/porevesrc/fasti2c.H $                     */
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
#ifndef __VSBE_FASTI2C_H
#define __VSBE_FASTI2C_H

// $Id: fasti2c.H,v 1.7 2012/10/05 23:20:32 bcbrock Exp $

/// \file fasti2c.H
/// \brief The "fast-mode" I2C controllers and memory models used
/// to implement the OTPROM, PNOR and SEEPROM interfaces.

#include <fapi.H>

#include <stddef.h>
#include <stdint.h>

#include "bebits.H"
#include "bus.H"

namespace vsbe {

    class FastI2cController;
    class LpcController;
    class I2cMemory;

    /// \defgroup fasti2c_speeds Fast-Mode I2C Controller Speeds
    ///
    /// Note that all speeds are considered "legal", and the model does not
    /// interpret the speed setting.
    ///
    /// @{
    
    const int FASTI2C_SPEED_100K  = 0;
    const int FASTI2C_SPEED_400K  = 1;
    const int FASTI2C_SPEED_3400K = 2;
    const int FASTI2C_SPEED_50K   = 3;

    /// @}

    /// \defgroup fasti2c_offsets Fast-Mode I2C Controller Register Offsets (PIB) and limits
    ///
    /// The last two offsets are only valid on the LpcController model.
    /// @{

    const uint32_t FASTI2C_CONTROL_OFFSET  = 0x0;
    const uint32_t FASTI2C_RESET_OFFSET    = 0x1;
    const uint32_t FASTI2C_STATUS_OFFSET   = 0x2;
    const uint32_t FASTI2C_DATA_OFFSET     = 0x3;
    const size_t   FASTI2C_REGISTERS       = 0x4;

    const uint32_t LPCM_ECC_START_OFFSET   = 0x4;
    const uint32_t LPCM_ECC_STOP_OFFSET    = 0x5;
    const size_t   LPCM_REGISTERS          = 0x6;

    /// @}

    /// The maximum memory size supported by the LPC controller (64MB)
    const uint32_t LPC_MEMORY_MAX_SIZE = (1 << 26);


    // These register layouts are copied/modified from the PMX model. If they
    // need to be modified here then they will also need to be modified in the
    // PMX model.

    /// Fast-Mode I2C Controller Control Register Layout
    typedef union {

        uint64_t value;
        struct {
#ifdef _BIG_ENDIAN
            uint32_t high_order;
            uint32_t low_order;
#else
            uint32_t low_order;
            uint32_t high_order;
#endif // _BIG_ENDIAN
        } words;
        struct {
#ifdef _BIG_ENDIAN
            uint64_t with_start : 1;
            uint64_t with_address : 1;
            uint64_t read_continue : 1;
            uint64_t with_stop : 1;
            uint64_t data_length : 4;
            uint64_t device_address : 7;
            uint64_t read_not_write : 1;
            uint64_t speed : 2;
            uint64_t port_number : 5;
            uint64_t address_range : 3;
            uint64_t _reserved0 : 6;
            uint64_t data0 : 8;
            uint64_t data1 : 8;
            uint64_t data2 : 8;
            uint64_t data3 : 8;
#else
            uint64_t data3 : 8;
            uint64_t data2 : 8;
            uint64_t data1 : 8;
            uint64_t data0 : 8;
            uint64_t _reserved0 : 6;
            uint64_t address_range : 3;
            uint64_t port_number : 5;
            uint64_t speed : 2;
            uint64_t read_not_write : 1;
            uint64_t device_address : 7;
            uint64_t data_length : 4;
            uint64_t with_stop : 1;
            uint64_t read_continue : 1;
            uint64_t with_address : 1;
            uint64_t with_start : 1;
#endif // _BIG_ENDIAN
        } fields;
    } FastI2cControlRegister;


    /// Fast-Mode I2C Controller Reset Register Layout
    typedef union {

        uint64_t value;
        struct {
#ifdef _BIG_ENDIAN
            uint32_t high_order;
            uint32_t low_order;
#else
            uint32_t low_order;
            uint32_t high_order;
#endif // _BIG_ENDIAN
        } words;
        struct {
#ifdef _BIG_ENDIAN
            uint64_t value : 64;
#else
            uint64_t value : 64;
#endif // _BIG_ENDIAN
        } fields;
    } FastI2cResetRegister;


    /// Fast-Mode I2C Controller Status Register Layout
    typedef union {

        uint64_t value;
        struct {
#ifdef _BIG_ENDIAN
            uint32_t high_order;
            uint32_t low_order;
#else
            uint32_t low_order;
            uint32_t high_order;
#endif // _BIG_ENDIAN
        } words;
        struct {
#ifdef _BIG_ENDIAN
            uint64_t pib_address_invalid : 1;
            uint64_t pib_write_invalid : 1;
            uint64_t pib_read_invalid : 1;
            uint64_t pib_address_parity_error : 1;
            uint64_t pib_parity_error : 1;
            uint64_t lb_parity_error : 1;
            uint64_t read_data : 32;
            uint64_t _reserved0 : 6;
            uint64_t i2c_macro_busy : 1;
            uint64_t i2c_invalid_command : 1;
            uint64_t i2c_parity_error : 1;
            uint64_t i2c_back_end_overrun_error : 1;
            uint64_t i2c_back_end_access_error : 1;
            uint64_t i2c_arbitration_lost : 1;
            uint64_t i2c_nack_received : 1;
            uint64_t i2c_data_request : 1;
            uint64_t i2c_command_complete : 1;
            uint64_t i2c_stop_error : 1;
            uint64_t i2c_port_busy : 1;
            uint64_t i2c_interface_busy : 1;
            uint64_t i2c_fifo_entry_count : 8;
#else
            uint64_t i2c_fifo_entry_count : 8;
            uint64_t i2c_interface_busy : 1;
            uint64_t i2c_port_busy : 1;
            uint64_t i2c_stop_error : 1;
            uint64_t i2c_command_complete : 1;
            uint64_t i2c_data_request : 1;
            uint64_t i2c_nack_received : 1;
            uint64_t i2c_arbitration_lost : 1;
            uint64_t i2c_back_end_access_error : 1;
            uint64_t i2c_back_end_overrun_error : 1;
            uint64_t i2c_parity_error : 1;
            uint64_t i2c_invalid_command : 1;
            uint64_t i2c_macro_busy : 1;
            uint64_t _reserved0 : 6;
            uint64_t read_data : 32;
            uint64_t lb_parity_error : 1;
            uint64_t pib_parity_error : 1;
            uint64_t pib_address_parity_error : 1;
            uint64_t pib_read_invalid : 1;
            uint64_t pib_write_invalid : 1;
            uint64_t pib_address_invalid : 1;
#endif // _BIG_ENDIAN
        } fields;
    } FastI2cStatusRegister;

};


////////////////////////////////////////////////////////////////////////////
// I2cMemory
////////////////////////////////////////////////////////////////////////////


/// An I2C memory model
///
/// The I2cMemory is a subclass of the Memory.  It adds a device address for
/// mapping onto an I2c bus, and also supports I2C memory operations such as
/// addressWrite() and dataRead().

class
vsbe::I2cMemory : public Memory
{

public:

    //////////////////////////////   Types  //////////////////////////////

    ////////////////////////////// Creators //////////////////////////////

    /// Create an I2c Memory
    I2cMemory();

    virtual ~I2cMemory();

    ///////////////////////////// Accessors //////////////////////////////

    //////////////////////////// Manipulators ////////////////////////////

    /// Configure the number of address bytes
    ///
    /// \param[in] i_addressBytes The number of address bytes (1-4) in a
    /// memory address for this devie.
    void
    configure(const uint8_t i_addressBytes);

    /// Perform an I2C address write to an attached device.
    ///
    /// \param[in] i_bytes The number of address bytes, which must match the
    /// configuration. 
    ///
    /// \param[in] i_address The memory address.
    ///
    /// \retval me ModelError return code
    ModelError 
    addressWrite(const size_t i_bytes, const uint32_t i_address);

    /// Perform an I2C data read from an attached device.
    ///
    /// \param[in] i_bytes The number of data bytes to read
    ///
    /// \param[out] o_data The data, right justified
    ///
    /// The read has a side effect of incrementing the address held in the
    /// device by \a i_bytes.
    ///
    /// \retval me ModelError return code
    ModelError 
    dataRead(const size_t i_bytes, uint64_t& o_data);

    /// Perform an I2C data write to an attached device.
    ///
    /// \param[in] i_bytes The number of data bytes to write
    ///
    /// \param[in] i_data The data, right justified
    ///
    /// The write has a side effect of incrementing the address held in the
    /// device by \a i_bytes.
    ///
    /// \retval me ModelError return code
    ModelError 
    dataWrite(const size_t i_bytes, const uint64_t i_data);


    ////////////////////////// Implementation ////////////////////////////

protected:

    /// The number of address bytes (1-4)
    uint8_t iv_addressBytes;

    /// The address register, auto-incremented on data reads and writes
    uint32_t iv_address;

    ///////////////////////////// Safety //////////////////////////////////

private:
    I2cMemory(const I2cMemory& i_rhs);
    I2cMemory& operator=(const I2cMemory& i_rhs);
};


////////////////////////////////////////////////////////////////////////////
// I2cDevice
////////////////////////////////////////////////////////////////////////////

namespace vsbe {

/// A simple I2C device/bus model
///
/// This simple device/bus model is used by the FastI2cController to model the
/// atachment of multiple I2cMemory to the physical busses (ports) controlled
/// by each controller.  Normally only 1 or two devices are attached to each
/// controller so it's easiest to model all devices under control of a
/// controller as a single list.

typedef struct I2cDevice {

    /// The controller port number - associated with a physical I2C bus
    unsigned iv_port;

    /// The device address of the device on the bus
    unsigned iv_deviceAddress;

    /// The I2cMemory 
    I2cMemory* iv_memory;

    /// The next I2cdevice in the list of devices
    struct I2cDevice* next;

} I2cDevice;

};    

////////////////////////////////////////////////////////////////////////////
// FastI2cController
////////////////////////////////////////////////////////////////////////////


/// A model of a "fast-mode" I2C Controller
///
/// The PORE engine only uses the new "fast-mode" protocol to communicate with
/// "I2C Controllers" that implement the physical memory interfaces for SBE
/// memories. These controllers may be either real I2C controllers (like for
/// SEEPROM) or pseudo-I2C-controllers like the PNOR and OTPROM controllers.
/// The "fast-mode" is a new subset of the full I2C controller interface that
/// only uses 4 registers.  This model only models fast-mode accesses, and
/// only in the precise way that PORE engines use fast-mode controllers for
/// memory fetches, loads and stores.  It will return errors for use of the
/// legacy mode registers or otherwise legal sequences that are simply not
/// modeled.
///
/// Each controller manages a number of "ports".  Each port is a physical I2C
/// bus, and devices attached to each port (bus) must have unique device IDs.
/// We model the devices attached to a port independently.  Each controller
/// maintains a list of I2cDevice mapped to its ports.  The underlying
/// devices are currently all of the I2cMemory class.

class 
vsbe::FastI2cController : public PibSlave
{
    
public:

    //////////////////////////////   Types  //////////////////////////////

    /// \enum FastI2cState
    ///
    /// The state of the controller.  Sequences of register operations are
    /// only allowed in a prescribed sequence, depending on the state of the
    /// controller. The ERROR state represents a bug in the model and is
    /// non-recoverable.
    enum FastI2cState {
        ERROR,
        IDLE,
        ADDRESS_WRITE_ONGOING,
        DATA_READ_ONGOING,
        DATA_AVAILABLE,
        WRITE_COMMAND_EXPECTED,
        DATA_WRITE_ONGOING
    };

    ////////////////////////////// Creators //////////////////////////////

    FastI2cController();

    virtual ~FastI2cController();

    ///////////////////////////// Accessors //////////////////////////////

    //////////////////////////// Manipulators ////////////////////////////

    /// Attach a memory model to the controller
    ///
    /// \param[in] i_memory A configured I2cMemory
    ///
    /// \param[in] i_port The port (bus) number the memory is attached to
    ///
    /// \param[in] i_deviceAddress The device ID of the memory device on the bus
    ///
    /// \retval me Either 0 for success, ME_INVALID_ARGUMENT or
    /// ME_AMBIGUOUS_CONFIGURATION.
    ModelError
    attachMemory(I2cMemory* i_memory, 
                 const unsigned i_port, 
                 const unsigned i_deviceAddress);

    /// Handle a PIB transaction
    ///
    /// \param[in,out] io_transaction An abstract PIB transaction
    ///
    /// The FastI2cController is an indirect memory. In general several PIB
    /// transactions are required to fetch a single doubleword of code or data
    /// from the memory.
    ///
    /// \retval rc Either an "OK" return code for success, or a code
    /// describing the error.
    virtual fapi::ReturnCode
    operation(Transaction& io_transaction);

    ////////////////////////// Implementation ////////////////////////////

protected:

    /// Find a device in the list of devices attached to this controller
    ///
    /// \param[in] i_port The port number to search
    ///
    /// \param[in] i_deviceAddress The device address to search
    ///
    /// \retval device A pointer to the device if found, otherwise 0.
    I2cDevice* findDevice(const unsigned i_port, 
                          const unsigned i_deviceAddress);

    /// Extract the I2C address from the CONTROL register
    ///
    /// \param[in] i_control The FastI2cControl register
    ///
    /// \retval address The indirect I2C address, taken from bytes 4-7 of the
    /// control register depending on how many address bytes are indicated in
    /// the control.
    uint32_t getI2cAddress(const FastI2cControlRegister i_control);

    /// Perform an I2C address write to an attached device.
    ///
    /// \retval me A ModelError return code in the event of errors, otherwise
    /// 0.
    ModelError addressWrite();

    /// Perform an I2C data read from an attached device.
    ///
    /// \retval me A ModelError return code in the event of errors, otherwise
    /// 0.
    ModelError dataRead();

    /// Begin an I2C data write an attached device.
    ///
    /// \retval me A ModelError return code in the event of errors, otherwise
    /// 0.
    ModelError initialDataWrite();

    /// Finalize an I2C data write an attached device.
    ///
    /// \param[in] i_data The final bytes of a data write, left justtified.
    ///
    /// \retval me A ModelError return code in the event of errors, otherwise
    /// 0.
    ModelError finalDataWrite(const uint64_t i_data);

    /// A list of I2cDevice, each of which is assigned to a controler port and
    /// maintains a unique device ID for that port.
    I2cDevice* iv_devices;

    /// The abstract state of the controller
    FastI2cState iv_state;

    /// The last value written to the control register
    FastI2cControlRegister iv_control;

    /// The last value generated in the status register
    FastI2cStatusRegister iv_status;

    /// The last value written to the data register
    uint64_t iv_data;

    /// The data FIFO.  Data is left-justified in this register.
    uint64_t iv_fifo;


    ///////////////////////////// Safety //////////////////////////////////

private:
    FastI2cController(const FastI2cController& i_rhs);
    FastI2cController& operator=(const FastI2cController& i_rhs);
};



////////////////////////////////////////////////////////////////////////////
// LpcController
////////////////////////////////////////////////////////////////////////////

/// Simplified model of the LPC controller as a fast-mode I2C controller
///
/// The LPC controller appears as a pseudo-FastI2cController with a couple of
/// extra specializations.  
///
/// - The fast-mode I2C controller specification is extended with two extra
/// registers : The ECC start and stop addresses. We do not model ECC in our
/// model, therefore this model only allows accesses that fall within the ECC
/// window.  The SBE will never address outside of the ECC window.

class
vsbe::LpcController : public FastI2cController
{

public:

    //////////////////////////////   Types  //////////////////////////////

    ////////////////////////////// Creators //////////////////////////////

    LpcController();

    virtual ~LpcController();

    ///////////////////////////// Accessors //////////////////////////////

    //////////////////////////// Manipulators ////////////////////////////

    /// Handle a PIB transaction
    ///
    /// \param[in,out] io_transaction An abstract PIB transaction
    ///
    /// The LpcController is an indirect memory. In general several PIB
    /// transactions are required to fetch a single doubleword of code or data
    /// from the memory.  The LpcController passes all transactions through to
    /// the underlying FastI2cController except for reads/writes to the ECC
    /// control registers.  We require that any change to the ECC bounds be
    /// made while the controller is in its IDLE state.
    ///
    /// \retval rc Either an "OK" return code for success, or a code
    /// describing the error.
    virtual fapi::ReturnCode
    operation(Transaction& io_transaction);

    ////////////////////////// Implementation ////////////////////////////

protected:

    /// The ECC start address register
    uint64_t iv_eccStart;

    /// The ECC stop address register
    uint64_t iv_eccStop;
};


#endif  // __VSBE_FASTI2C_H
