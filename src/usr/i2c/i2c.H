/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/i2c/i2c.H $                                           */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2011,2014              */
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
#ifndef __I2C_H
#define __I2C_H

/**
 * @file i2c.H
 *
 * @brief Provides the interfaces for the i2c device driver
 *
 */

// ----------------------------------------------
// Includes
// ----------------------------------------------
#include <errl/errlentry.H>

namespace I2C
{

/**
 * @brief FIFO size (width) in bytes.  This dictates how many bytes
 *       we can read/write in one FIFO access.
 */
#define I2C_FIFO_SIZE 4

/**
 * @brief FIFO capacity in bytes.  This dictates the maximum number
 *      of bytes that the FIFO can hold.
 */
#define I2C_MAX_FIFO_CAPACITY 8

/**
 * @brief I2C Clock setting values
 *
 * The clock divisors are found by using a 500Mhz local bus, using the
 * equation that was given in the I2C Master Spec.
 *
 */
#define I2C_MAX_BUS_SPEED           1024    // 1MHZ
#define I2C_CLOCK_DIVISOR_100KHZ    312     // 0x138
#define I2C_CLOCK_DIVISOR_400KHZ    78      // 0x4E
#define I2C_CLOCK_DIVISOR_1MHZ      31      // 0x1F
/**
 * @brief I2C Clock delay polling values
 *
 * The first macro returns an interval to sleep, based on the clock speed.
 * The macro and values were determined by examples provided from the prism
 * hardware team.
 *
 * Poll interval = clock divisor / 37
 *      @100KHz = 40uS
 *      @400KHz = 10uS
 *
 * Poll count = 5000 / Poll interval
 *      @100KHz = 125
 *      @400KHz = 500
 */
#define I2C_TIMEOUT_INTERVAL( i_clockSpeed ) ( (i_clockSpeed / 37) +1 )
#define I2C_TIMEOUT_COUNT( i_interval ) ( 5000 / i_interval )

/**
 * @brief I2C Master Base Addresses
 *
 * These addresses will not be needed once there is some solution in
 * the attribute code that can be queried to get the chip base
 * addresses.
 */
#define I2C_MASTER_BASE_ADDR   0xA0000

/**
 * @brief I2C Master Offset Addresses
 */
#define I2C_MASTER0_OFFSET    0x00
#define I2C_MASTER1_OFFSET    0x20
#define I2C_MASTER2_OFFSET    0x40

/**
 * @brief I2C Master Addresses
 */
#define I2C_MASTER0_ADDR (I2C_MASTER_BASE_ADDR | I2C_MASTER0_OFFSET)
#define I2C_MASTER1_ADDR (I2C_MASTER_BASE_ADDR | I2C_MASTER1_OFFSET)
#define I2C_MASTER2_ADDR (I2C_MASTER_BASE_ADDR | I2C_MASTER2_OFFSET)

/**
 * @brief I2C Master register structure and address definition
 */
struct i2c_addrs_t
{
    uint64_t fifo;
    uint64_t command;
    uint64_t mode;
    uint64_t intmask;       // Not Currently used
    uint64_t interrupt;
    uint64_t status;
    uint64_t reset;
};

/**
 * @brief Structure used to pass important variables between functions
 */
struct misc_args_t
{
    uint8_t  port;
    uint8_t  engine;
    uint64_t devAddr;
    bool     skip_mode_setup;
    bool     with_stop;
    bool     read_not_write;
    uint64_t bus_speed;          // in kbits/sec (ie 400KHz)
    uint16_t bit_rate_divisor;   // uint16_t to match size in mode register
    uint64_t timeout_interval;
    uint64_t timeout_count;
};

/**
 * @brief Different ways of setting the I2C Bus Speed
 */
enum i2c_bus_setting_mode_t
{
    READ_I2C_BUS_ATTRIBUTES,
    SET_I2C_BUS_400KHZ,
    SET_I2C_BUS_1MHZ,
    LAST_BUS_SETTING_MODE_TYPE
};



// -----------------------------------------------------------------------
// NOTE: Addressing listed below is from the PIB I2C Master Addressing
//      scheme from the I2C Master specification.  Only the Legacy
//      registers are being implemented.
// -----------------------------------------------------------------------

/**
* @brief I2C FIFO register definition
*       Address 0x04
*/
union fifo_reg_t
{
    uint64_t value;
    struct
    {
        uint64_t byte_0 : 8;
        uint64_t padding : 56;
    } PACKED;
};

/**
 * @brief I2C Command register definition
 *      Address 0x05
 */
union command_reg_t
{
    uint64_t value;
    struct
    {
        uint64_t with_start : 1;
        uint64_t with_addr : 1;
        uint64_t read_continue : 1; // Not Supported at this time
        uint64_t with_stop : 1;
        uint64_t reserved : 4;
        uint64_t device_addr : 7;
        uint64_t read_not_write : 1;
        uint64_t length_b : 16;
        uint64_t padding : 32;
    } PACKED;
};

/**
 * @brief I2C Mode register definition
 *      Address 0x06
 */
union mode_reg_t
{
    uint64_t value;
    struct
    {
        uint64_t bit_rate_div : 16;
        uint64_t port_num : 6;
        uint64_t reserved : 6;
        uint64_t enhanced_mode : 1;
        uint64_t diag_mode : 1;
        uint64_t pacing_allow_mode : 1;
        uint64_t wrap_mode : 1;
        uint64_t padding : 32;
    } PACKED;
};

/**
 * @brief Watermark register definition
 *      Address 0x07
 */
union watermark_reg_t
{
    uint64_t value;
    struct
    {
        uint64_t reserved0 : 16;
        uint64_t high : 4;
        uint64_t reserved1 : 4;
        uint64_t low : 4;
        uint64_t reserved2 : 4;
        uint64_t padding : 32;
    } PACKED;
};

/**
 * @brief Interrupt Mask register definition
 *      Address 0x08
 */
union interrupt_mask_reg_t
{
    uint64_t value;
    struct
    {
        uint64_t reserved0 : 16;
        uint64_t invalid_cmd : 1;
        uint64_t lbus_parity_error : 1;
        uint64_t backend_overrun_error : 1;
        uint64_t backend_access_error : 1;
        uint64_t arbitration_lost_error : 1;
        uint64_t nack_received_error : 1;
        uint64_t data_request : 1;
        uint64_t command_complete : 1;
        uint64_t stop_error : 1;
        uint64_t i2c_busy : 1;
        uint64_t not_i2c_busy : 1;
        uint64_t reserved1 : 1;
        uint64_t scl_eq_1 : 1;
        uint64_t scl_eq_0 : 1;
        uint64_t sda_eq_1 : 1;
        uint64_t sda_eq_0 : 1;
        uint64_t padding : 32;
    } PACKED;
};

/**
 * @brief Interrupt Condition register definition
 *      Address 0x09
 */
union interrupt_cond_reg_t
{
    uint64_t value;
    struct
    {
        uint64_t reserved0 : 16;
        uint64_t invalid_cmd : 1;
        uint64_t lbus_parity_error : 1;
        uint64_t backend_overrun_error : 1;
        uint64_t backend_access_error : 1;
        uint64_t arbitration_lost_error : 1;
        uint64_t nack_received_error : 1;
        uint64_t data_request : 1;
        uint64_t command_complete : 1;
        uint64_t stop_error : 1;
        uint64_t i2c_busy : 1;
        uint64_t not_i2c_busy : 1;
        uint64_t reserved1 : 1;
        uint64_t scl_eq_1 : 1;
        uint64_t scl_eq_0 : 1;
        uint64_t sda_eq_1 : 1;
        uint64_t sda_eq_0 : 1;
        uint64_t padding : 32;
    } PACKED;
};

/**
 * @brief Interrupt register definition
 *      Address 0x0A
 */
union interrupt_reg_t
{
    uint64_t value;
    struct
    {
        uint64_t reserved0 : 16;
        uint64_t invalid_cmd : 1;
        uint64_t lbus_parity_error : 1;
        uint64_t backend_overrun_error : 1;
        uint64_t backend_access_error : 1;
        uint64_t arbitration_lost_error : 1;
        uint64_t nack_received_error : 1;
        uint64_t data_request : 1;
        uint64_t command_complete : 1;
        uint64_t stop_error : 1;
        uint64_t i2c_busy : 1;
        uint64_t not_i2c_busy : 1;
        uint64_t reserved1 : 1;
        uint64_t scl_eq_1 : 1;
        uint64_t scl_eq_0 : 1;
        uint64_t sda_eq_1 : 1;
        uint64_t sda_eq_0 : 1;
        uint64_t padding: 32;
    } PACKED;
};

/**
 * @brief Status register definition
 *      Address 0x0B
 */
union status_reg_t
{
    uint64_t value;
    struct
    {
        uint64_t invalid_cmd : 1;
        uint64_t lbus_parity_error : 1;
        uint64_t backend_overrun_error : 1;
        uint64_t backend_access_error : 1;
        uint64_t arbitration_lost_error : 1;
        uint64_t nack_received : 1;
        uint64_t data_request : 1;
        uint64_t command_complete : 1;
        uint64_t stop_error : 1;
        uint64_t upper_threshold : 7;
        uint64_t any_i2c_interrupt : 1;
        uint64_t reserved0 : 2;
        uint64_t i2c_port_history_busy : 1;
        uint64_t scl_input_level : 1;
        uint64_t sda_inupt_level : 1;
        uint64_t i2c_port_busy : 1;
        uint64_t i2c_interface_busy : 1;
        uint64_t fifo_entry_count : 8;
        uint64_t padding : 32;
    } PACKED;
};

/**
 * @brief Extended Status register definition
 *      Address 0x0C
 */
union extended_status_reg_t
{
    uint64_t value;
    struct
    {
        uint64_t fifo_size : 8;
        uint64_t reserved0 : 3;
        uint64_t msm_current_state : 5;
        uint64_t scl_in_syn : 1;
        uint64_t sda_in_syn : 1;
        uint64_t s_scl : 1;
        uint64_t s_sda : 1;
        uint64_t m_scl : 1;
        uint64_t m_sda : 1;
        uint64_t high_water : 1;
        uint64_t low_water : 1;
        uint64_t i2c_busy : 1;
        uint64_t self_busy : 1;
        uint64_t reserved1 : 1;
        uint64_t i2c_version : 5;
        uint64_t padding : 32;
    } PACKED;
};

/**
 * @brief Residual Front/Back end length register definition
 *      Address 0x0D
 */
union residual_length_reg_t
{
    uint64_t value;
    struct
    {
        uint64_t front_end_length : 16;
        uint64_t back_end_length : 16;
        uint64_t padding : 32;
    } PACKED;
};



/**
*
* @brief Perform an I2C access operation.  It follows a pre-defined
*       prototype function in order to be registered with the device
*       driver framework.
*
* @param[in] i_opType - Operation Type - See DeviceFW::OperationType in
*       driververif.H
*
* @param[in] i_target - I2C Master Target device
*
* @param [in/out] io_buffer
*       INPUT: Pointer to the data that will be  written to the target
*           device.
*       OUTPUT: Pointer to the data that was read from the target device.
*
* @param [in/out] io_buflen
*       INPUT: Length of the buffer to be written to target device.
*       OUTPUT: Length of buffer that was written, or length of buffer
*           to be read from target device.
*
* @param [in] i_accessType - Access Type - See DeviceFW::AccessType in
*       usrif.H
*
* @param [in] i_args - This is an argument list for the device driver
*       framework.  This list of arguments consists of the I2C Master
*       engine, which port from the I2C master to use, and the slave's
*       device address.
*
* @return errlHndl_t - NULL if successful, otherwise a pointer to the
*       error log.
*
*/
errlHndl_t i2cPerformOp( DeviceFW::OperationType i_opType,
                         TARGETING::Target * i_target,
                         void * io_buffer,
                         size_t & io_buflen,
                         int64_t i_accessType,
                         va_list i_args );

/**
 * @brief This function will do the real work of reading from the I2C
 *      device.
 *
 * @param[in] i_target - The I2C master to source the read to the slave.
 *
 * @param[out] o_buffer - The buffer to place the retrieved data.
 *
 * @param[in] i_buflen - The size of the data to read and place in the
 *      buffer.
 *
 * @param[in] i_args - Structure containing arguments needed for a command
 *  transaction.
 *
 * @return errlHndl_t - NULL if successful, otherwise a pointer to
 *      the error log.
 */
errlHndl_t i2cRead ( TARGETING::Target * i_target,
                     void * o_buffer,
                     size_t & i_buflen,
                     misc_args_t & i_args);

/**
 * @brief This function will do the real work of writinging to the I2C
 *      device.
 *
 * @param[in] i_target - The I2C master to source the write to the slave.
 *
 * @param[in] i_buffer - The buffer containing the data to be written
 *      to the target device.
 *
 * @param[in/out] io_buflen - INPUT: The size of the data to write to the
 *      target device.   OUTPUT: The size of the data buffer written.
 *
 * @param[in] i_args - Structure containing arguments needed for a command
 *  transaction.
 *
 * @return errlHndl_t - NULL if successful, otherwise a pointer to
 *      the error log.

 */
errlHndl_t i2cWrite ( TARGETING::Target * i_target,
                      void * i_buffer,
                      size_t & io_buflen,
                      misc_args_t & i_args);

/**
 * @brief This function will do the I2C setup of the Address/Command registers
 *      before issuing the 'go' on the I2C bus.
 *
 * @param[in] i_target - The I2C master.
 *
 * @param[in] i_buflen - The size of the data that will be read/written.
 *
 * @param[in] i_args - Structure containing arguments needed for a command
 *  transaction.
 *
 * @return errlHndl_t - NULL if successful, otherwise a pointer to
 *      the error log.
 */
errlHndl_t i2cSetup ( TARGETING::Target * i_target,
                      size_t & i_buflen,
                      misc_args_t & i_args);

/**
 * @brief This function will wait for the command to be complete or
 *      timeout waiting before returning.
 *
 * @param[in] i_target - The I2C master target.
 *
 * @param[in] i_args - Structure containing arguments needed for a command
 *  transaction.
 *
 * @return errlHndl_t - NULL if successful, otherwise a pointer to
 *      the error log.
 */
errlHndl_t i2cWaitForCmdComp ( TARGETING::Target * i_target,
                               misc_args_t & i_args);

/**
 * @brief This function will read the I2C Master engine status register
 *      and perform all required steps after reading it.
 *
 * @param[in] i_target - The I2C master target.
 *
 * @param[in] i_args - Structure containing arguments needed for a command
 *      transaction.
 *
 * @param[out] o_statusReg - The value of the status register read.
 *
 * @return errlHndl_t - NULL if successful, otherwise a pointer to
 *      the error log.
 */
errlHndl_t i2cReadStatusReg ( TARGETING::Target * i_target,
                              misc_args_t & i_args,
                              status_reg_t & o_statusReg );

/**
 * @brief This function will check for errors in the status register
 *      value that is read out.
 *
 * @param[in] i_target - The I2C master target.
 *
 * @param[in] i_args - Structure containing arguments needed for a command
 *      transaction.
 *
 * @param[in] i_statusVal - The value of the Status Register.
 *
 * @return errlHndl_t - NULL if successful, otherwise a pointer to
 *      the error log.
 */
errlHndl_t i2cCheckForErrors ( TARGETING::Target * i_target,
                               misc_args_t & i_args,
                               status_reg_t i_statusVal );

/**
 * @brief This function will read the status register and not return
 *      until there is room in the FIFO for data to be written.  An
 *      error will be returned if it times out waiting for space in
 *      the FIFO.
 *
 * @param[in] i_target - The I2C master target.
 *
 * @param[in] i_args - Structure containing arguments needed for a command
 *      transaction.
 *
 * @return errHndl_t - NULL if successful, otherwise a pointer to
 *      the error log.
 */
errlHndl_t i2cWaitForFifoSpace ( TARGETING::Target * i_target,
                                 misc_args_t & i_args);

/**
 * @brief This function will reset the I2C Master engine specified
 *      by the args.  It will also then initiate a Stop cmd to the
 *      slave device.
 *
 * @param[in] i_target - The I2C master target.
 *
 * @param[in] i_args - Structure containing arguments needed for a command
 *      transaction.
 *
 * @return errHndl_t - NULL if successful, otherwise a pointer to
 *      the error log.
 */
errlHndl_t i2cReset ( TARGETING::Target * i_target,
                      misc_args_t & i_args );

/**
 * @brief This function will send the Stop command to the slave device
 *      defined by the args passed in.
 *
 * @param[in] i_target - The I2C master target.
 *
 * @param[in] i_args - Structure containing arguments needed for a command
 *      transaction.
 *
 * @return errHndl_t - NULL if successful, otherwise a pointer to
 *      the error log.
 */
errlHndl_t i2cSendSlaveStop ( TARGETING::Target * i_target,
                              misc_args_t & i_args );

/**
 * @brief This function will read the interrupt register and return the
 *      value.
 *
 * @param[in] i_target - The I2C master target.
 *
 * @param[in] i_args - Structure containing arguments needed for a command
 *      transaction.
 *
 * @param[out] o_intRegValue - The value of the Interrupt register that
 *      was read.
 *
 * @return errHndl_t - NULL if successful, otherwise a pointer to
 *      the error log.
 */
errlHndl_t i2cGetInterrupts ( TARGETING::Target * i_target,
                              misc_args_t & i_args,
                              uint64_t & o_intRegValue );

/**
 * @brief This function calculates the different variables related to the
 *        I2C Bus Speed that are used in the other functions
 *
 * @param[in] i_target - The I2C master target.
 *
 * @param[in] i_mode - States how bus setting will be determined
 *
 * @param[in/out] io_args - Structure containing arguments needed for a command
 *      transaction. Clock arguments set in this function.
 *
 * @return errHndl_t - NULL if successful, otherwise a pointer to
 *      the error log.
 */
errlHndl_t i2cSetBusVariables ( TARGETING::Target * i_target,
                                i2c_bus_setting_mode_t i_mode,
                                misc_args_t & io_args );


}; // end I2C namespace

#endif  // __I2C_H
