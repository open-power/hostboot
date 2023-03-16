/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/i2cr/i2cr.H $                                         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2023                        */
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
#ifndef __I2CR_H
#define __I2CR_H

/** @file  i2cr.H
 *  @brief Provides the interfaces to perform an I2CR Odyssey SCOM/CFAM R/W
 */

namespace I2CR
{

constexpr uint32_t  I2CR_CONFIG_REG           = 0x00030000;
constexpr uint32_t  I2CR_STATUS_REG           = 0x00030001;
constexpr uint32_t  I2CR_ERROR_REG            = 0x00030002;
constexpr uint32_t  I2CR_FIRST_ERROR_LOG_REG  = 0x00030004;

constexpr uint64_t  ALL_64_ONES    = 0xFFFFFFFFFFFFFFFFULL;
constexpr uint64_t  ALL_32_ONES    = 0xFFFFFFFF;
constexpr uint8_t   I2CR_SUCCESS   = 0;
constexpr uint8_t   I2CR_ERROR     = 1;

struct i2cr_config_reg_t
{
    uint64_t base_addr:7;             //0:6
    uint64_t hw_version:4;            //7:10
    uint64_t counter:10;              //11:20
    uint64_t i2cr_port_en:1;          //21
    uint64_t i2cr_port_reset:1;       //22
    uint64_t i2cr_err_state_en:1;     //23
    uint64_t i2cr_timeout_en:1;       //24
    uint64_t i2cr_error_state:1;      //25
    uint64_t i2cr_ret_ones_disable:1; //26
    uint64_t i2cr_parity_check_en:1;  //27
    uint64_t i2cr_switch_errcode:1;   //28
    uint64_t i2cr_23bit_addr_dis:1;   //29
    uint64_t i2cr_switch_errcode1:1;  //30
    uint64_t unused:1;                //31
    uint64_t reserved:32;             //32:63
} PACKED;

struct i2cr_status_reg_t
{
    uint64_t inprogress:1;      //0
    uint64_t noack:1;           //1
    uint64_t anyerror:1;        //2
    uint64_t read_not_write:1;  //3
    uint64_t address:24;        //4:27
    uint64_t piberr:3;          //28:30
    uint64_t securityblocked:1; //31
    uint64_t reserved:32;       //32:63
} PACKED;

struct i2cr_error_reg_t
{
    uint64_t piberr:3;          //0:2
    uint64_t obsolete:1;        //3
    uint64_t internalparity:1;  //4
    uint64_t badreset:1;        //5
    uint64_t badaddress:1;      //6
    uint64_t badwrite:1;        //7
    uint64_t badread:1;         //8
    uint64_t addrparity:1;      //9
    uint64_t dataparity:1;      //10
    uint64_t timeout:1;         //11
    uint64_t abortwrite:1;      //12
    uint64_t abort:1;           //13
    uint64_t internal_any:1;    //14
    uint64_t internal_badaddress:1; //15
    uint64_t internal_badread:1; //16
    uint64_t internal_badwrite:1; //17
    uint64_t responder_parity:1; //18
    uint64_t security:1;         //19
    uint64_t timeout_error:1;    //20
    uint64_t reserved1:43;       //21:63
} PACKED;

struct i2cr_first_error_log_reg_t
{
    uint64_t first_err_bits:21;  //0:20
    uint64_t tied0_3:3;          //21:23
    uint64_t read_not_write:1;   //24
    uint64_t tied0_2:7;          //25:31
    uint64_t scom_addr:32;       //32:63
} PACKED;


/**
 * @brief Performs an I2CR Odyssey SCOM/CFAM(FSI)  operation
 * This function performs an Scom Read/Write operation. It follows
 * pre-defined prototype functions in order to be registered with the
 * device-driver framework.
 *
 * @param[in]   i_opType        Operation type, see DeviceFW::OperationType
 *                              in driverif.H
 * @param[in]   i_target        i2cr Odyssey Scom target
 * @param[in/out] io_buffer     Read: pointer to output data storage
 *                              Write: pointer to data to be written
 * @param[in/out] io_buflen     Input: size of io_buffer (in bytes)
 *                              Output: Read: size of output data
 *                                      Write: size of data written
 * @param[in]   i_accessType    Select from DeviceFW::AccessType enum
 *                              (deviceif.H)
 * @param[in]   i_address       This is an argument list for DD framework.
 *                              In this function, there's only one argument,
 *                              which is the Scom address value.
 *
 * @return  errlHndl_t
 */
errlHndl_t i2crPerformOp(DeviceFW::OperationType i_opType,
                         TARGETING::Target* i_target,
                         void* io_buffer,
                         size_t& io_buflen,
                         int64_t i_accessType,
                         va_list i_address);

}; // End namespace

#endif
