/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/i2c/i2c.H $                                           */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2015                        */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
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
#include <sys/time.h>
#include "i2c_common.H"

namespace I2C
{

/**
 * @brief Different Reset level to perform an i2c reset
 */
enum i2c_reset_level
{
    BASIC_RESET,
    FORCE_UNLOCK_RESET,
};


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
 * @brief Inline function used to set global g_I2C_NEST_FREQ_MHZ
 */
ALWAYS_INLINE inline uint64_t i2cGetNestFreq()
{
  TARGETING::TargetService& tS = TARGETING::targetService();
  TARGETING::Target * sysTarget = NULL;
  tS.getTopLevelTarget( sysTarget );

  return sysTarget->getAttr<TARGETING::ATTR_NEST_FREQ_MHZ>();
};
static uint64_t g_I2C_NEST_FREQ_MHZ = i2cGetNestFreq();


/**
 * @brief Inline function used to calculate Bit Rate Divisor setting
 *        based on I2C Bus Speed and Nest Frequency
 *
 * @param [in] i_bus_speed_khz  Bus Speed in KHz
 * @param [in] i_local_bus_MHZ  Local Bus that feeds I2C Master's clock
 *
 * @return Bit Rate Divisor value
 */
ALWAYS_INLINE inline uint16_t i2cGetBitRateDivisor(uint64_t i_bus_speed_khz,
                                                   uint64_t i_local_bus_MHZ)
{
  // BRD = ( ( ( LocalBus_MHZ / 16 ) / i_bus_speed_khz ) - 1 ) / 4

  // Use tmp variable to convert everything to KHZ safely
  uint64_t tmp = ( i_local_bus_MHZ / 16 ) * 1000;

  return ( ( ( tmp / i_bus_speed_khz ) - 1 ) / 4 );
}

/**
 * @brief I2C Polling Interval based on bus speed; set to 1/10th of expected
 *        duration
 *
 * NOTE: I2C Bus Speed in KBits/sec, so multiple by 8
 *       since Device Driver works on a byte-level
 *
 * @param [in] i_bus_speed_khz Bus Speed in KHz
 *
 * @return Polling Interval in nanoseconds
 */
ALWAYS_INLINE inline uint64_t i2cGetPollingInterval(uint64_t i_bus_speed_khz )
{
  // Polling Interval = 8 * (1/bus+speed) * (1/10) -> converted to ns
  return ( ( 8 * NS_PER_SEC ) / ( 10 * i_bus_speed_khz * 1000 ) );

};

/**
 * @brief Determine I2C Timeout Count based on I2C_MAX_WAIT_TIME_NS and
 *         I2C Polling Interval (in ns)
 */
#define I2C_MAX_WAIT_TIME_NS 5 * NS_PER_MSEC
#define I2C_TIMEOUT_COUNT(i_interval_ns) (I2C_MAX_WAIT_TIME_NS / i_interval_ns)

/**
 * @brief Only hard-coded bus speed defines (in KBits/sec)
 */
#define I2C_BUS_SPEED_FROM_MRW   0
#define I2C_BUS_SPEED_400KHZ     400
#define I2C_BUS_SPEED_1MHZ       1000


// -----------------------------------------------------------------------
// NOTE: Host I2C is using the PIB I2C Master 'legacy' registers, which
//       are analogous to the FSI I2C register space.
// -----------------------------------------------------------------------

/**
 * @brief I2C Master Base Addresses
 */
#define I2C_HOST_MASTER_BASE_ADDR   0xA0004
#define I2C_FSI_MASTER_BASE_ADDR    0x01800

/**
 * @brief I2C Register Offsets
 */
enum i2c_reg_offset_t
{
    I2C_REG_FIFO        = 0,
    I2C_REG_COMMAND     = 1,
    I2C_REG_MODE        = 2,
    I2C_REG_INTMASK     = 4,
    I2C_REG_INTERRUPT   = 6,
    I2C_REG_STATUS      = 7,
    I2C_REG_RESET       = 7,
    I2C_REG_RESET_ERRORS= 8,
    I2C_REG_SET_SCL     = 9,
    I2C_REG_RESET_SCL   = 11,
    I2C_REG_SET_SDA     = 12,
    I2C_REG_RESET_SDA   = 13,

};

/**
* @brief I2C FIFO register definition
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
 * @brief Utility Function to capture error log user data consisting of
          the I2C Master Status Register and the I2C Master Target HUID
 */
uint64_t I2C_SET_USER_DATA_1 ( status_reg_t status_reg,
                               TARGETING::Target * tgt);

/**
 * @brief Utility Function to capture error log user data consisting of
          the I2C variables relating to the I2C Master
 */
uint64_t I2C_SET_USER_DATA_2 ( misc_args_t args);


/**
*
* @brief Perform an I2C access operation.  It follows a pre-defined
*       prototype function in order to be registered with the device
*       driver framework.
*
* @param[in] i_opType - Operation Type - See DeviceFW::OperationType in
*       driverif.H
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
*       userif.H
*
* @param [in] i_args - This is an argument list for the device driver
*       framework.  This list of arguments is documented in driverif.H.
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
*
* @brief Perform a Host-based I2C access operation.  It follows a pre-defined
*       prototype function in order to be registered with the device
*       driver framework.
*
* @param[in] i_opType - Operation Type - See DeviceFW::OperationType in
*       driverif.H
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
*       userif.H
*
* @param [in] i_args - This is an argument list for the device driver
*       framework.  This list of arguments is documented in driverif.H.
*
* @return errlHndl_t - NULL if successful, otherwise a pointer to the
*       error log.
*
*/
errlHndl_t host_i2cPerformOp( DeviceFW::OperationType i_opType,
                         TARGETING::Target * i_target,
                         void * io_buffer,
                         size_t & io_buflen,
                         int64_t i_accessType,
                         va_list i_args );

/**
*
* @brief Perform a FSI-based I2C access operation.  It follows a pre-defined
*       prototype function in order to be registered with the device
*       driver framework.
*
* @param[in] i_opType - Operation Type - See DeviceFW::OperationType in
*       driverif.H
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
*       userif.H
*
* @param [in] i_args - This is an argument list for the device driver
*       framework.  This list of arguments is documented in driverif.H.
*
* @return errlHndl_t - NULL if successful, otherwise a pointer to the
*       error log.
*
*/
errlHndl_t fsi_i2cPerformOp( DeviceFW::OperationType i_opType,
                         TARGETING::Target * i_target,
                         void * io_buffer,
                         size_t & io_buflen,
                         int64_t i_accessType,
                         va_list i_args );

/**
 * @brief This function sets the Host vs FSI switches if the user has not
 *  already.
 *
 * param[in] i_target - The target device
 *
 * @param[in/out] io_args - The argument object to set the switches for
 *
 * @return void
 */
void i2cSetSwitches( TARGETING::Target * i_target,
                     misc_args_t & io_args);

/**
*
* @brief Performs the actual I2C operation.
*        NOTE:  This function handles the MUTEX used to avoid deadlocks.
*
* @param[in] i_opType - Operation Type - See DeviceFW::OperationType in
*       driverif.H
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
*       userif.H
*
* @param[in] i_args - Structure containing arguments needed for a command
 *  transaction.
*
* @return errlHndl_t - NULL if successful, otherwise a pointer to the
*       error log.
*
*/
errlHndl_t i2cCommonOp( DeviceFW::OperationType i_opType,
                         TARGETING::Target * i_target,
                         void * io_buffer,
                         size_t & io_buflen,
                         int64_t i_accessType,
                         misc_args_t & i_args );


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
 * @brief This function gets the appropriate engine mutex for a given target.
 *
 * @param[in] i_target - The target to get the mutex for.
 *
 * @param[in] i_args - Structure containing arguments needed to determine
 *                     the correct engine mutex.
 *
 * @param[in/out] i_engineLock - The mutex.
 *
 * @return bool - True if valid mutex is found, False otherwise.
 */
bool i2cGetEngineMutex( TARGETING::Target * i_target,
                        misc_args_t & i_args,
                        mutex_t *& i_engineLock );

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
 * @brief This function manually sends a stop signal
 *
 * @param[in] i_target - The i2c Target
 *
 * @param[in] i_args - Structure containing argumets needed for a command
 *          transaction
 *
 * @return errHndl_t - NULL if successful, otherwise a pointer to the error
 *                      log.
 */
errlHndl_t i2cSendStopSignal(TARGETING::Target * i_target,
                             misc_args_t & i_args);

/**
 * @brief This function will reset the I2C Master engine specified
 *      by the args.  It will also end the sequence by initiating a Stop
 *      cmd to all ports on the engine that have a slave device.
 *
 * @param[in] i_target - The I2C master target.
 *
 * @param[in] i_args - Structure containing arguments needed for a command
 *      transaction.
 *
 * @param[in] i_reset_level - level of reset to use.
 *
 * @return errHndl_t - NULL if successful, otherwise a pointer to
 *      the error log.
 */
errlHndl_t i2cReset ( TARGETING::Target * i_target,
                      misc_args_t & i_args,
                      i2c_reset_level i_reset_level = BASIC_RESET );

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
 * @param[in] i_speed -  Speed for the I2C Bus (in KBits/sec)
 *                       NOTE: A value of 0 means that the speed will be
 *                       determined by I2C attributes set via the MRW
 *                       Useful Defines:
 *                       -- I2C_BUS_SPEED_FROM MRW   0
 *                       -- I2C_BUS_SPEED_400KHZ     400
 *                       -- I2C_BUS_SPEED_1MHZ       1000
 *
 * @param[in/out] io_args - Structure containing arguments needed for a command
 *      transaction. Clock arguments set in this function.
 *
 * @return errHndl_t - NULL if successful, otherwise a pointer to
 *      the error log.
 */
errlHndl_t i2cSetBusVariables ( TARGETING::Target * i_target,
                                uint64_t i_speed,
                                misc_args_t & io_args );

/**
 * @brief This function handles all I2C-related Register operations.
 *        Host (via scom)  and FSI operations use different size regisers
 *        and this function converts all data to 64 bits.
 *
 * @param[in] i_opType - Operation Type - See DeviceFW::OperationType in
 *       driververif.H
 *
 * @param[in] i_target - I2C Master Target device
 *
 * @param [in/out] io_buffer_64
 *       INPUT: Pointer to 64 bits of data to be  written to the target
 *       OUTPUT: Pointer to the 64 bits of data that was read from the target
 *
 * @param[in] i_reg - The I2C register of the operation
 *
 * @param[in/out] i_args - Structure containing arguments needed for a command
 *      transaction.
 *
 * @return errHndl_t - NULL if successful, otherwise a pointer to
 *      the error log.
 */
errlHndl_t i2cRegisterOp ( DeviceFW::OperationType i_opType,
                           TARGETING::Target * i_target,
                           uint64_t * io_data_64,
                           i2c_reg_offset_t i_reg,
                           misc_args_t & i_args );



}; // end I2C namespace

#endif  // __I2C_H
