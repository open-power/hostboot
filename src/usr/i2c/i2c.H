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
#include <errl/errltypes.H>

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
 * The clock divisors are found by using a 600Mhz local bus, using the
 * equation that was given in the I2C Master Spec.
 *
 */
#define I2C_MAX_BUS_SPEED           400
#define I2C_CLOCK_DIVISOR_100KHZ    1499    // 0x5DB
#define I2C_CLOCK_DIVISOR_400KHZ    374     // 0x176

/**
 * @brief I2C Master Base Addresses
 */
#define I2C_MASTER0_BASE    0x00
#define I2C_MASTER1_BASE    0x20
#define I2C_MASTER2_BASE    0x40

/**
* @brief I2C FIFO register definition
*       Address 0x00
*/
union fiforeg
{
    uint64_t value;
    uint8_t bytes[8];
    struct
    {
        uint64_t byte_0 : 8;
        uint64_t byte_1 : 8;
        uint64_t byte_2 : 8;
        uint64_t byte_3 : 8;
        uint64_t byte_4 : 8;
        uint64_t byte_5 : 8;
        uint64_t byte_6 : 8;
        uint64_t byte_7 : 8;
    } PACKED;
} fifo_reg_t;

/**
 * @brief I2C Command register definition.
 *      Address 0x01
 */
union cmdreg
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
} command_reg_t;

/**
 * @brief I2C Mode register definition
 *      Address 0x02
 */
union modereg
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
} mode_reg_t;

/**
 * @brief Watermark register definition
 *      Address 0x03
 */
union watermarkreg
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
} watermark_reg_t;

/**
 * @brief Interrupt Mask register definition
 *      Address 0x04
 */
union intmaskreg
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
} interrupt_mask_reg_t;

/**
 * @brief Interrupt Condition register definition
 *      Address 0x05
 */
union intcondreg
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
} interrupt_cond_reg_t;

/**
 * @brief Interrupt register definition
 *      Address 0x06
 */
union interruptreg
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
} interrupt_reg_t;

/**
 * @brief Status register definition
 *      Address 0x07
 */
union statusreg
{
    uint64_t value;
    struct
    {
        uint64_t invalid_cmd : 1;
        uint64_t lbus_parity_error : 1;
        uint64_t backend_overrun_error : 1;
        uint64_t backend_access_error : 1;
        uint64_t arbitration_lost_error : 1;
        uint64_t nack_received_error : 1;
        uint64_t data_request : 1;
        uint64_t command_complete : 1;
        uint64_t stop_error : 1;
        uint64_t upper_threshold : 7;
        uint64_t any_i2_interrupt : 1;
        uint64_t reserved0 : 2;
        uint64_t i2c_port_history_busy : 1;
        uint64_t scl_input_level : 1;
        uint64_t sda_inupt_level : 1;
        uint64_t i2c_port_busy : 1;
        uint64_t i2c_interface_busy : 1;
        uint64_t fifo_entry_count : 8;
        uint64_t padding : 32;
    } PACKED;
} status_reg_t;

/**
 * @brief Extended Status register definition
 *      Address 0x08
 */
union extstatusreg
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
} extended_status_reg_t;

/**
 * @brief Residual Front/Back end length register definition
 *      Address 0x09
 */
union residuallengthreg
{
    uint64_t value;
    struct
    {
        uint64_t front_end_length : 16;
        uint64_t back_end_length : 16;
        uint64_t padding : 32;
    } PACKED;
} residual_length_reg_t;

/**
 * @brief Port Busy register definition
 *      Address 0x0A
 */
union portbusyreg
{
    uint64_t value;
    struct
    {
        uint64_t port0_busy : 1;
        uint64_t port1_busy : 1;
        uint64_t port2_busy : 1;
        uint64_t port3_busy : 1;
        uint64_t port4_busy : 1;
        uint64_t port5_busy : 1;
        uint64_t port6_busy : 1;
        uint64_t port7_busy : 1;
        uint64_t port8_busy : 1;
        uint64_t port9_busy : 1;
        uint64_t port10_busy : 1;
        uint64_t port11_busy : 1;
        uint64_t port12_busy : 1;
        uint64_t port13_busy : 1;
        uint64_t port14_busy : 1;
        uint64_t port15_busy : 1;
        uint64_t port16_busy : 1;
        uint64_t port17_busy : 1;
        uint64_t port18_busy : 1;
        uint64_t port19_busy : 1;
        uint64_t port20_busy : 1;
        uint64_t port21_busy : 1;
        uint64_t port22_busy : 1;
        uint64_t port23_busy : 1;
        uint64_t port24_busy : 1;
        uint64_t port25_busy : 1;
        uint64_t port26_busy : 1;
        uint64_t port27_busy : 1;
        uint64_t port28_busy : 1;
        uint64_t port29_busy : 1;
        uint64_t port30_busy : 1;
        uint64_t port31_busy : 1;
        uint64_t padding : 32;
    } PACKED;
} port_busy_reg_t;


/**
*
* @brief Perform an I2C access operation.  It follows a pre-defined
*       prototype function in order to be registered with the device
*       driver framework.
*
* @param[in] i_opType - Operation Type - See DeviceFW::OperationType in
*       driververif.H
*
* @param[in] i_target - I2C Target device
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
*       framework.  In this function there is only one argument, which
*       is the I2C Address that is needed for bits 8:14 of the I2C
*       Command register.
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
 * @param[in] i_target - The device target to read from.
 *
 * @param[in] i_addr - The I2C address to use for the read.
 *
 * @param[out] o_buffer - The buffer to place the retrieved data.
 *
 * @param[in] i_size - The size of the data to read and place in the
 *      buffer.
 *
 * @return errlHndl_t - NULL if successful, otherwise a pointer to
 *      the error log.
 */
errlHndl_t i2cRead ( TARGETING::Target * i_target,
                     uint64_t i_addr,
                     void * o_buffer,
                     size_t & i_size );

/**
 * @brief This function will do the real work of writinging to the I2C
 *      device.
 *
 * @param[in] i_target - The device target to write to.
 *
 * @param[in] i_addr - The I2C address to use for the write.
 *
 * @param[in] i_buffer - The buffer containing the data to be written
 *      to the target device.
 *
 * @param[in/out] i_size - INPUT: The size of the data to write to the
 *      target device.   OUTPUT: The size of the data buffer written.
 *
 * @return errlHndl_t - NULL if successful, otherwise a pointer to
 *      the error log.

 */
errlHndl_t i2cWrite ( TARGETING::Target * i_target,
                      uint64_t i_addr,
                      void * i_buffer,
                      size_t & io_size );

/**
 * @brief This function will do the I2C setup of the Address/Command registers
 *      before issuing the 'go' on the I2C bus.
 *
 * @param[in] i_target - The target device.
 *
 * @param[in] i_addr - The I2C address to use for the operation.
 *
 * @param[in] i_size - The size of the data that will be read/written.
 *
 * @param[in] i_withStop - Whether or not to set the with_stop bit in the
 *      I2C Command register.
 *
 * @param[in] i_readNotWrite - true if doing a read operation, false if
 *      doing a write operation.
 *
 * @return errlHndl_t - NULL if successful, otherwise a pointer to
 *      the error log.
 */
errlHndl_t i2cSetup ( TARGETING::Target * i_target,
                      uint64_t i_addr,
                      size_t & i_size,
                      bool i_withStop,
                      bool i_readNotWrite );

}; // end I2C namespace

#endif  // __I2C_H
