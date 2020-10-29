/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/i2c/i2c.H $                                   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2020                        */
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
#include <i2c/i2c_common.H>

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
 * @brief Miscellaneous enums for I2C
 */
enum
{
    PAGE_ZERO = 0x0,
    PAGE_ONE = 0x1,
    PAGE_UNKNOWN = 0x2,
    PAGE_ZERO_ADDR = 0x6C,
    PAGE_ONE_ADDR  = 0x6E,
};

/**
 * @brief Value of the rightmost (7th) bit of an I2C address, which on the
 *     wire indicates whether the operation is a read or a write
 */
enum I2C_OP_DIRECTION : uint8_t
{
    WRITE = 0x00, ///< Write operation
    READ  = 0x01, ///< Read operation
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

  return sysTarget->getAttr<TARGETING::ATTR_FREQ_PB_MHZ>();
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
  // BRD = ( ( LocalBus_MHZ) / i_bus_speed_khz ) - 1 ) / 4

  // Use tmp variable to convert everything to KHZ safely
  uint64_t tmp = i_local_bus_MHZ * 1000;

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
#define I2C_MAX_WAIT_TIME_NS (20 * NS_PER_MSEC)
#define I2C_TIMEOUT_COUNT(i_interval_ns) (I2C_MAX_WAIT_TIME_NS / i_interval_ns)

/**
 * @brief Only hard-coded bus speed defines (in KBits/sec)
 */
#define I2C_BUS_SPEED_FROM_MRW   0
#define I2C_BUS_SPEED_400KHZ     400
#define I2C_BUS_SPEED_1MHZ       1000

/**
 *  @brief Frequency conversions, assuming base unit of Hz
 */
enum FREQ_CONVERSION : size_t
{
    HZ_PER_KHZ  = 1000,
    KHZ_PER_MHZ = 1000,
    HZ_PER_MHZ  = KHZ_PER_MHZ * HZ_PER_KHZ,
};

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
 * @brief  I2C engine numbers
 */
const int FSI_ENGINE_A = 0;
const int HOST_ENGINE_B = 0;
const int HOST_ENGINE_C = 1;
const int HOST_ENGINE_D = 2;
const int HOST_ENGINE_E = 3;

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
        uint64_t waiting_for_i2c_busy : 1;
        uint64_t error_in : 1;
        uint64_t i2c_port_history_busy : 1;
        uint64_t scl_input_level : 1;
        uint64_t sda_input_level : 1;
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

// These defines allow standard logging of engine/port/deviceAddress information in traces
#define TRACE_I2C_ADDR_FMT " (e%d/p%d/devAddr=0x%X) "

#define TRACE_I2C_ADDR_ARGS(args) \
    args.engine, args.port, args.devAddr


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
 * @brief Analyzes an error handle object and
 *        performs an i2c reset if necessary
 *
 * @param[in] i_target - The target
 * @param[in] i_err - There error to analyze
 * @param[in] i_args - miscellaneous arguments
 *
 * @return void
 */
void i2cHandleError( TARGETING::Target * i_target,
                     errlHndl_t & i_err,
                     misc_args_t & i_args );



/**
 * @brief Performs the necessary operations and comparisons
 *        needed to decide what EEPROM page we are on and locks the appropriate
 *        page control mutexes
 * @param[in] i_opType - Operation Type - See DeviceFW::OperationType in
 *                        driverif.H
 * @param[in] i_target - The target to lock the page for.
 * @param[in] i_accessType - Access Type - See DeviceFW::AccessType in
 *                            userif.H
 * @param[in] i_desiredPage - The EEPROM page that will be switched to.
 * @param[in] i_lockMutex - True if we want to actually lock the mutex,
 *            False if we do not want to lock it.
 * @param[in] i_args - miscellaneous arguments
 *
 * @return errlHndl_t - NULL if successful, otherwise a pointer to an error log
 *
 */
errlHndl_t i2cPageSwitchOp( DeviceFW::OperationType i_opType,
                             TARGETING::Target * i_target,
                             int64_t i_accessType,
                             uint8_t i_desiredPage,
                             bool i_lockMutex,
                             misc_args_t & i_args );
/**
 * @brief Unlocks the page mutex for targets given page attribute
 *
 * @param[in] i_target - target to unlock the page for.
 * @param[in] i_args - miscellaneous arguments
 *
 * @return - True on success, False on failure.
 */
bool i2cPageUnlockOp( TARGETING::Target * i_target,
                            misc_args_t & i_args );



/**
 * @brief Sets the Host vs FSI switches if the user has not
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
*        NOTE: Handles the MUTEX used to avoid deadlocks.
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
 * @brief Does the real work of reading from the I2C device.
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
 * @brief Does the real work of writing to the I2C
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
 * @brief does the I2C setup of the Address/Command registers
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
 * @brief Gets the appropriate engine
 * mutex for a given target.
 *
 * @param[in] i_target - The target to get the mutex for.
 *
 * @param[in] i_args - Structure containing arguments needed to determine
 *                     the correct engine mutex.
 *
 * @param[in/out] i_engineLock - The engine mutex.
 *
 * @return bool - True if valid mutex is found, False otherwise.
 */
bool i2cGetEngineMutex( const TARGETING::Target * const i_target,
                        const misc_args_t &  i_args,
                              mutex_t *&     i_engineLock );


/**
 * @brief Gets the appropriate page mutex for the given i2c engine
 *
 * @param[in] i_target - The target to get the mutex for.
 * @param[in] i_args - Structure containing arguments needed to determine
 *                     the correct page mutex.
 * @param[in/out] i_pageLock - The page mutex.
 *
 * @return bool - True if valid mutex is found, False otherwise.
 */
bool i2cGetPageMutex( TARGETING::Target * i_target,
                      misc_args_t & i_args,
                      mutex_t *& i_pageLock );




/**
 * @brief Wait for the command to be complete or
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

/**
 * @brief This function translates the engine/port #'s from
 *        FSI I2C Mode to host I2C Mode
 *
 * @param[in/out] io_logical_engine - fsi engine number to be translated
 * @param[in/out] io_logical_port   - fsi port number to be translated
 *
 * @return void
 */
void setLogicalFsiEnginePort(size_t &io_logical_engine,
                                   size_t &io_logical_port);

/**
 * @brief This function handles adding hw callouts to error logs that may arise
 *        during communications over the I2C bus. Within the i2c code, it is
 *        preferable to use this function over adding hw callouts directly to
 *        make sure all paths are handled correctly.
 *
 * @param[in] i_err - error log to add callouts to. Must not be nullptr.
 * @param[in] i_target - I2C Master Target device. Must not be nullptr.
 * @param[in] i_args - miscellaneous args struct containing the port, engine,
 *            devAddr necessary to find associated I2c devices.
 *
 * @return void
 */
void addHwCalloutsI2c(errlHndl_t i_err,
                      TARGETING::Target * i_target,
                      const misc_args_t & i_args);


/**
 * @brief This function checks the 'Seeprom Update Lock" (aka SUL) bit in
 *        the input processor target's Security Switch Register and if
 *        enabled will choose a BASIC_RESET level versus the more complex
 *        FORCE_RESET_UNLOCK
 *
 * @param[in] i_target - Processor I2C Master Target
 *                       No-op if nullptr
 *                       No-op if not Processor Type
 *
 * @param[in] i_engine - I2C Engine off of the Processor I2C Master Target
 *                       No-op if engine does not equal 1
 *
 * @note - For all no-op conditions above, FORCE_RESET_UNLOCK will be returned
 *
 * @note - Any error logs will be handled internally
 *
 * @note - The sticky bit setting only matters for accessing the MVPD and
 *         SBE Seeproms, and thererfore will only change the reset level for
 *         engine == to 1.
 *
 * @return i2c_reset_level - Max Reset Level Allowed for This Target
 */
i2c_reset_level setResetLevelViaStickyBit(TARGETING::Target * i_target,
                                          uint8_t i_engine);


namespace SMBUS
{

/**
 *  @brief Calculates a packet error code (PEC) over the specified number of
 *      bytes at the specified address.
 *
 *  @par Detailed Description:
 *      Calculates a packet error code (PEC) over the specified number of bytes
 *      at the specified address.  Specifically, it applies a CRC-8 algorithm, a
 *      very common/simple CRC detailed @
 *      https://en.wikipedia.org/wiki/Computation_of_cyclic_redundancy_checks
 *
 *  @param[in] i_pData Pointer to the start of the data; must not be nullptr
 *  @param[in] i_size  Number of bytes to consider when computing the PEC
 *
 *  return uint8_t Computed PEC byte
 */
uint8_t calculatePec(
    const uint8_t* const i_pData,
    const size_t         i_size);

/**
 *  @brief Structure which tracks the Send Byte
 *      transaction to assist in calculating the PEC byte at the end (if
 *      applicable)
 */
struct SendByte
{
    // The following fields are known prior to the transaction:

    // The remote device's address which starts the transaction;
    // RW bit will be 0
    uint8_t writeAddr;

    // Data byte to send
    uint8_t dataByte;

    // PEC byte
    uint8_t pec;

    // Size of message to send, excluding address byte, including PEC byte if
    // applicable
    size_t messageSize;

    /**
     *  @brief Constructor
     *
     *  @param[in] i_address Address of the remote device
     *  @param[in] i_pDataByte Pointer to byte to send.  Must not be nullptr.
     *  @param[in] i_usePec Whether to suffix transaction with PEC byte or not
     */
    SendByte(      uint8_t i_address,
             const void*   i_pDataByte,
                   bool    i_usePec);
} PACKED;

/**
 *  @brief Structure which tracks the Write Byte or Write Word
 *      transaction to assist in calculating the PEC byte at the end (if
 *      applicable)
 */
struct WriteByteOrWord
{
    // The following fields are known prior to the transaction:

    // The remote device's address which starts the transaction;
    // RW bit will be 0
    uint8_t writeAddr;

    // The PMBUS command code to send as part of the write
    uint8_t commandCode;

    // Data bytes the originator intends to send.
    // 1 for Write byte
    // 2 for Write word
    // One more byte is added in case there is a PEC byte.
    uint8_t dataBytes[sizeof(uint16_t)+sizeof(uint8_t)];

    // How many data bytes (excluding PEC) the originator intends to send
    uint8_t byteCount;

    // Size of message to send, excluding address byte, including PEC byte if
    // applicable
    size_t messageSize;

    /**
     *  @brief Constructor
     *
     *  @param[in] i_address Address of the remote device
     *  @param[in] i_commandCode PMBUS command code to execute
     *  @param[in] i_byteCount Number of data bytes to send (1 or 2)
     *  @param[in] i_pDataBytes Pointer to byte stream to send.  Must not be
     *      nullptr
     *  @param[in] i_usePec Whether to suffix transaction with PEC byte or not
     */
    WriteByteOrWord(      uint8_t i_address,
                          uint8_t i_commandCode,
                          uint8_t i_byteCount,
                    const void*   i_pDataBytes,
                          bool    i_usePec);
} PACKED;

/**
 *  @brief Structure which tracks the block write transaction to assist in
 *     calculating the PEC byte at the end
 */
struct BlockWrite
{
    // The following fields are known prior to the transaction:

    // The remote device's address which starts the transaction;
    // RW bit will be 0
    uint8_t writeAddr;

    // The PMBUS command code to send as part of the write
    uint8_t commandCode;

    // How many data bytes (excluding PEC) the originator intends to send
    uint8_t byteCount;

    // Data bytes the originator intends to send.  Max 255.  One more byte is
    // added in case there is a PEC byte
    uint8_t dataBytes[UINT8_MAX+sizeof(uint8_t)];

    // Size of message to send, excluding address byte, including PEC byte if
    // applicable
    size_t messageSize;

    /**
     *  @brief Constructor
     *
     *  @param[in] i_address Address of the remote device
     *  @param[in] i_commandCode PMBUS command code to execute
     *  @param[in] i_byteCount Number of data bytes to send
     *  @param[in] i_pDataBytes Pointer to byte stream to send.  Must not be
     *      nullptr
     *  @param[in] i_usePec Whether to suffix transaction with PEC byte or not
     */
    BlockWrite(      uint8_t i_address,
                     uint8_t i_commandCode,
                     uint8_t i_byteCount,
               const void*   i_pDataBytes,
                     bool    i_usePec);

} PACKED;

/**
 *  @brief Structure which tracks the read byte|word transaction to assist in
 *     calculating the PEC byte at the end
 */
struct ReadByteOrWord
{
    // The following fields are known prior to the transaction:

    // The remote device's address which starts the transaction;
    // RW bit will be 0
    uint8_t writeAddr;

    // The PMBUS command code to send as part of the write
    uint8_t commandCode;

    // The remote device's address (sent after repeated start);
    // RW bit will be 1
    uint8_t readAddr;

    // The following fields are filled in during the transaction:

    // Data bytes (1 if read byte, 2 if read word) returned by the remote device
    uint8_t dataBytes[sizeof(uint16_t)];

    // PEC byte returned by the remote device (if supported)
    uint8_t pec;

    // # data byte requested (1 or 2)
    uint8_t byteCount;

    /**
     *  @brief Constructor
     *
     *  @param[in] i_address Address of the remote device
     *  @param[in] i_commandCode PMBUS command code to execute
     *  @param[in] i_byteCount Number of bytes to read (1 or 2)
     */
    ReadByteOrWord(uint8_t i_address,
                   uint8_t i_commandCode,
                   uint8_t i_byteCount)
      : writeAddr(i_address),
        commandCode(i_commandCode),
        readAddr(i_address | I2C_OP_DIRECTION::READ),
        pec(0),
        byteCount(i_byteCount)
    {
        assert(((byteCount==1) || (byteCount==2)),
            "Invalid byte count %d for read byte or read word", byteCount);
        memset(dataBytes,0x00,sizeof(dataBytes));
    }

} PACKED;

/**
 *  @brief Structure which tracks the block read transaction to assist in
 *     calculating the PEC byte at the end
 */
struct BlockRead
{
    // The following fields are known prior to the transaction:

    // The remote device's address which starts the transaction;
    // RW bit will be 0
    uint8_t writeAddr;

    // The PMBUS command code to send as part of the write
    uint8_t commandCode;

    // The remote device's address (sent after repeated start);
    // RW bit will be 1
    uint8_t readAddr;

    // The following fields are filled in during the transaction:

    // How many data bytes (excluding PEC) the remote device intends
    // to return.
    uint8_t blockCount;

    // Data bytes (blockCount of them) returned by the remote device
    uint8_t dataBytes[UINT8_MAX];

    // PEC byte returned by the remote device (if supported)
    uint8_t pec;

    /**
     *  @brief Constructor
     *
     *  @param[in] i_address Address of the remote device
     *  @param[in] i_commandCode PMBUS command code to execute
     */
    BlockRead(const uint8_t i_address,
              const uint8_t i_commandCode)
      : writeAddr(i_address),
        commandCode(i_commandCode),
        readAddr(i_address | I2C_OP_DIRECTION::READ),
        blockCount(0),
        pec(0)
    {
        memset(dataBytes,0x00,sizeof(dataBytes));
    }

} PACKED;

} // End SMBUS namespace

}; // end I2C namespace

#endif  // __I2C_H
