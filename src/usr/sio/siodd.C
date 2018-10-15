/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/sio/siodd.C $                                         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2018                        */
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
#include <sio/sio.H>
#include "siodd.H"
#include <errl/errlmanager.H>
#include <errl/errlentry.H>
#include <trace/interface.H>
#include <sys/sync.h>
#include <devicefw/userif.H>
#include <lpc/lpcif.H>
#include <kernel/console.H>
#include <devicefw/driverif.H>
#include <initservice/bootconfigif.H>
#include <sys/time.h>
#include <hbotcompid.H>
#include <stdarg.h>
#include <targeting/common/target.H>
#include <lpc/lpc_reasoncodes.H>

#include <console/consoleif.H>

// Trace definition
trace_desc_t* g_trac_sio = NULL;
TRAC_INIT(&g_trac_sio, SIO_COMP_NAME, 2*KILOBYTE, TRACE::BUFFER_SLOW); //2K

/**
 * This function performs an SIO Read operation. It follows a pre-defined
 * prototype functions in order to be registered with the device-driver
 * framework.
 *
 * @param[in]   i_opTypeOperation type, see DeviceFW::OperationType in
 * driverif.H
 * @param[in]   i_targetSIO target
 * @param[in/out] io_buffer Read: Pointer to output data storage
 *                          Write: Pointer to input data storage
 * @param[in/out] io_buflen Input: size of io_buffer (in bytes)
 *                          Output: Read: Size of output data
 *                                  Write: Size of data written
 * @param[in]   i_accessTypeDeviceFW::AccessType enum (usrif.H)
 * @param[in]   i_args  This is an argument list for DD framework.
 * @return  errlHndl_t
 */
errlHndl_t SIORead(DeviceFW::OperationType i_opType,
                   TARGETING::Target* i_target,
                   void* io_buffer,
                   size_t& io_buflen,
                   int64_t i_accessType, va_list i_args)
{
    assert(i_target == TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL);
    errlHndl_t l_err = NULL;
    uint8_t l_dev = va_arg(i_args,uint64_t);
    uint8_t l_addr = va_arg(i_args,uint64_t);
    l_err = Singleton<SioDD>::instance().readSIO(i_target, l_dev, l_addr,
    static_cast<uint8_t*>(io_buffer));
    return l_err;
}

/**
 * This function performs an SIO Write operation. It follows a pre-defined
 * prototype functions in order to be registered with the device-driver
 * framework.
 *
 * param[in]   i_opType Operation type, see DeviceFW::OperationType in
 * driverif.H
 * @param[in]   i_targetSIO target
 * @param[in/out] io_buffer Read: Pointer to output data storage
 *                          Write: Pointer to input data storage
 * @param[in/out] io_buflen Input: size of io_buffer (in bytes)
 *                          Output: Read: Size of output data
 *                                  Write: Size of data written
 * @param[in]   i_accessTypeDeviceFW::AccessType enum (usrif.H)
 * @param[in]   i_args  This is an argument list for DD framework.
 * @return  errlHndl_t
 */
errlHndl_t SIOWrite(DeviceFW::OperationType i_opType,
                    TARGETING::Target* i_target,
                    void* io_buffer,
                    size_t& io_buflen,
                    int64_t i_accessType,
                    va_list i_args)
{
    assert(i_target == TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL);
    errlHndl_t l_err = NULL;
    uint8_t l_dev = va_arg(i_args,uint64_t);
    uint8_t l_addr = va_arg(i_args,uint64_t);
    l_err = Singleton<SioDD>::instance().writeSIO(i_target, l_dev, l_addr,
            static_cast<uint8_t*>(io_buffer));
    return l_err;
}

/**
 * This function performs an LPC to AHB read operation using superIO accesses.
 * It follows a pre-defined prototype functions in order to be registered
 * with the device-driver framework.
 *
 * @param[in]   i_opType Operation type, see DeviceFW::OperationType in
 * driverif.H
 * @param[in]   i_targetSIO target
 * @param[in/out] io_buffer Read: Pointer to output data storage
 *                          Write: Pointer to input data storage
 * @param[in/out] io_buflen Input: size of io_buffer (in bytes)
 *                          Output: Read: Size of output data
 *                                  Write: Size of data written
 * @param[in]   i_accessTypeDeviceFW::AccessType enum (usrif.H)
 * @param[in]   i_args  This is an argument list for DD framework.
 * @return  errlHndl_t
 */
errlHndl_t ahbSioReadDD(DeviceFW::OperationType i_opType,
                          TARGETING::Target* i_target,
                          void* io_buffer,
                          size_t& io_buflen,
                          int64_t i_accessType,
                          va_list i_args)
{
    assert(i_target == TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL);
    errlHndl_t l_err = NULL;
    uint32_t l_reg = va_arg(i_args,uint64_t);
    l_err = Singleton<SioDD>::instance().ahbSioRead(i_target, l_reg,
            static_cast<uint32_t*>(io_buffer));
    return l_err;
}

/**
 * This function performs an LPC to AHB read operation using superIO accesses.
 * It follows a pre-defined prototype functions in order to be registered
 * with the device-driver framework.
 *
 * @param[in]   i_opType Operation type, see DeviceFW::OperationType in
 * driverif.H
 * @param[in]   i_targetSIO target
 * @param[in/out] io_buffer Read: Pointer to output data storage
 *                          Write: Pointer to input data storage
 * @param[in/out] io_buflen Input: size of io_buffer (in bytes)
 *                          Output: Read: Size of output data
 *                                  Write: Size of data written
 * @param[in]   i_accessTypeDeviceFW::AccessType enum (usrif.H)
 * @param[in]   i_args  This is an argument list for DD framework.
 * @return  errlHndl_t
 */
errlHndl_t ahbSioWriteDD(DeviceFW::OperationType i_opType,
                         TARGETING::Target* i_target,
                         void* io_buffer,
                         size_t& io_buflen,
                         int64_t i_accessType,
                         va_list i_args)
{
    assert(i_target == TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL);
    errlHndl_t l_err = NULL;
    uint32_t l_reg = va_arg(i_args,uint64_t);
    l_err = Singleton<SioDD>::instance().ahbSioWrite(i_target, l_reg,
            static_cast<uint32_t*>(io_buffer));
    return l_err;
}

// Register SIO access functions to DD framework
DEVICE_REGISTER_ROUTE( DeviceFW::READ,
                       DeviceFW::SIO,
                       TARGETING::TYPE_PROC,
                       SIORead );
DEVICE_REGISTER_ROUTE( DeviceFW::WRITE,
                       DeviceFW::SIO,
                       TARGETING::TYPE_PROC,
                       SIOWrite );

// Register AHB_SIO access functions to DD framework
DEVICE_REGISTER_ROUTE( DeviceFW::READ,
                       DeviceFW::AHB_SIO,
                       TARGETING::TYPE_PROC,
                       ahbSioReadDD );
DEVICE_REGISTER_ROUTE( DeviceFW::WRITE,
                       DeviceFW::AHB_SIO,
                       TARGETING::TYPE_PROC,
                       ahbSioWriteDD );

errlHndl_t SIO::isAvailable(bool& available)
{
    uint8_t l_byte = SIO::SIO_PASSWORD_REG;
    size_t l_len = sizeof(uint8_t);
    errlHndl_t l_err = NULL;

    l_err = deviceWrite(TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL,
                        &l_byte, l_len,
                        DEVICE_LPC_ADDRESS(LPC::TRANS_IO, SIO::SIO_ADDR_REG_2E));

    if (l_err)
    {
        /* FIXME: The implementation assumes that any error indicates that the
         * SIO device is not available. This, generally, is a terribe
         * assumption. We should instead look for the specific failure, which
         * is a LPC SYNC No Response (and this is what we see in skiboot).
         * Currently there are open questions about the hardware behaviour as
         * observed by hostboot: We see an OPBM Error Acknowledge state when we
         * try to access an absent SIO device, but no error state is present in
         * the LPCHC status register.
         *
         * We retain the interface of returning an errlHndl_t to future-proof
         * the code. The caller should commit the errl if it is valid.
         */
        TRACFCOMP(g_trac_sio,
                  "Received error during SIO availability test, assuming "
                  "absent. Reason code: 0x%x, user data: [0x%8x, 0x%8x]",
                  l_err->reasonCode(), l_err->getUserData1(),
                  l_err->getUserData2());
        available = false;
        delete l_err;
        l_err = NULL;
    }
    else
    {
        available = true;
    }

    return l_err;
}

//function to unlock superIO password register
errlHndl_t SioDD::unlock_SIO(TARGETING::Target* i_target)
{
    uint8_t l_byte = SIO::SIO_PASSWORD_REG;
    size_t l_len = sizeof(uint8_t);
    errlHndl_t l_err = NULL;
    int again = 1;

    do
    {
    // Unlock the SIO registers (write 0xA5 password to offset 0x2E two times)
    l_err = deviceWrite(i_target, &l_byte, l_len,
                        DEVICE_LPC_ADDRESS(LPC::TRANS_IO,
                                           SIO::SIO_ADDR_REG_2E));
    } while(!l_err && again--);

    return l_err;
}

//SioDD constructor
SioDD::SioDD(TARGETING::Target* i_target)
{
    assert(i_target == TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL);
    mutex_init(&iv_sio_mutex);
    iv_prev_dev = 0x00;

    errlHndl_t err = unlock_SIO(i_target);
    bool failed = (err != NULL);
    delete err;

    /* Unlocked very early, so make some noise if we fail */
    if (failed)
    {
        printk("SuperIO unlock failed! Expect future errors\n");
    }
}

//SioDD destructor
SioDD::~SioDD()
{
    mutex_destroy(&iv_sio_mutex);
}

//internal write function
errlHndl_t SioDD::_writeSIO(TARGETING::Target* i_target,
        uint8_t i_reg, uint8_t* i_data)
{
    errlHndl_t l_err = NULL;
    do
    {
        size_t l_len = sizeof(uint8_t);
        l_err = deviceWrite(i_target,
                            &i_reg,
                            l_len,
                            DEVICE_LPC_ADDRESS(LPC::TRANS_IO, SIO::SIO_ADDR_REG_2E));
        if(l_err) { break; }
        l_err = deviceWrite(i_target,
                            i_data,
                            l_len,
                            DEVICE_LPC_ADDRESS(LPC::TRANS_IO, SIO::SIO_DATA_REG_2F));
    } while(0);
    return l_err;
}

//internal read function
errlHndl_t SioDD::_readSIO(TARGETING::Target* i_target,
                        uint8_t i_reg, uint8_t*  o_byte)
{
    errlHndl_t l_err = NULL;
    size_t l_len = sizeof(uint8_t);
    do
    {
        l_err =  deviceWrite(i_target,
                             &i_reg,
                             l_len,
                             DEVICE_LPC_ADDRESS(LPC::TRANS_IO, SIO::SIO_ADDR_REG_2E));
        if(l_err) { break; }
        l_err =  deviceRead(i_target,
                            o_byte,
                            l_len,
                            DEVICE_LPC_ADDRESS(LPC::TRANS_IO, SIO::SIO_DATA_REG_2F));
    } while(0);
    return l_err;
}

//function to change logical device in SIO
errlHndl_t SioDD::changeDevice(TARGETING::Target* i_target, uint8_t i_dev)
{
    return _writeSIO(i_target, SIO::SIO_DEVICE_SELECT_REG, &i_dev);
}

//function to read from SIO register
errlHndl_t SioDD::readSIO(TARGETING::Target* i_target, uint8_t i_dev,
                             uint8_t i_reg, uint8_t* o_byte)
{
    mutex_lock(&iv_sio_mutex);
    errlHndl_t l_err = NULL;

    if(iv_prev_dev!=i_dev)
    {
        l_err = changeDevice(i_target, i_dev);
        if(!l_err)
        {
            iv_prev_dev = i_dev;
            l_err = _readSIO(i_target, i_reg, o_byte);
        }
    }
    else
    {
        l_err = _readSIO(i_target, i_reg, o_byte);
    }
    mutex_unlock(&iv_sio_mutex);
    return l_err;
}


//function to write to SIO register
errlHndl_t SioDD::writeSIO(TARGETING::Target* i_target,
                        uint8_t i_dev, uint8_t i_reg, uint8_t* i_data)
{
    mutex_lock(&iv_sio_mutex);
    errlHndl_t l_err = NULL;
    if(iv_prev_dev!=i_dev)
    {
        l_err = changeDevice(i_target, i_dev);
        if(!l_err)
        {
            iv_prev_dev = i_dev;
            l_err = _writeSIO(i_target, i_reg, i_data);
        }
    }
    else
    {
        l_err = _writeSIO(i_target, i_reg, i_data);
    }
    mutex_unlock(&iv_sio_mutex);
    return l_err;
}

//function to translate address from LPC to AHB space
errlHndl_t SioDD::_ahbSioAddrPrep(TARGETING::Target* i_target,
                        uint32_t i_addr)
{
    errlHndl_t l_err = NULL;
    uint8_t l_dev = SIO::iLPC2AHB;
    uint8_t l_data;
    do
    {
        //select device 0x0D
        l_err = changeDevice(i_target, l_dev);
        if(l_err) { break; }

        //write to f0-f3
        for (size_t i = sizeof(i_addr); i>0; i--)
        {
            l_data = i_addr>>((i-1)*8);
            l_err = _writeSIO(i_target, (0xF3-(i-1)), &l_data);
            if( l_err ) { break; }
        }

        //byte length
        l_data = SIO::SIO_iLPC2AHB_LENGTH;
        l_err = _writeSIO(i_target, 0xF8, &l_data);
        if( l_err ) { break; }
    }
    while(0);
    return l_err;
}

errlHndl_t SioDD::_ahbSioRead(TARGETING::Target* i_target,
                        uint32_t i_reg, uint32_t* o_data)
{
    errlHndl_t l_err = NULL;
    uint8_t tmp_data = 0;
    do
    {
        l_err = _ahbSioAddrPrep(i_target, i_reg);
        if( l_err ) { break; }

        //trigger operation by reading from 0xFE
        l_err = _readSIO(i_target, 0xFE, &tmp_data);
        if( l_err ) { break; }
        uint8_t* ptr8 = (uint8_t*)(o_data);
        for( size_t i=0; i<sizeof(uint32_t); i++ )
        {
            l_err = _readSIO(i_target, 0xF4+i, &ptr8[i]);
            if(l_err) { break; }
        }
    }
    while(0);
    return l_err;
}

errlHndl_t SioDD::_ahbSioWrite(TARGETING::Target* i_target,
                        uint32_t i_reg, uint32_t* i_val)
{
    errlHndl_t l_err = NULL;
    uint8_t l_data;
    do
    {
        l_err = _ahbSioAddrPrep(i_target, i_reg);
        if( l_err ) { break; }

        uint8_t* ptr8 = reinterpret_cast<uint8_t*>(i_val);
        for (size_t i = 0; i<sizeof(uint32_t); i++)
        {
            l_err = _writeSIO(i_target, (0xF4+i), &ptr8[i]);
            if( l_err ) { break; }
        }
        //trigger operation by writing to 0xFE
        l_data = 0xCF;
        l_err = _writeSIO(i_target, 0xFE, &l_data);
        if( l_err ) { break; }
    }
    while(0);
    return l_err;
}

//function to perform AHB to SIO read
errlHndl_t SioDD::ahbSioRead(TARGETING::Target* i_target,
                        uint32_t i_reg, uint32_t* o_data)
{
    mutex_lock(&iv_sio_mutex);
    errlHndl_t l_err = NULL;
    l_err = _ahbSioRead(i_target, i_reg, o_data);
    mutex_unlock(&iv_sio_mutex);
    return l_err;
}

//function to perform AHB to SIO write
errlHndl_t SioDD::ahbSioWrite(TARGETING::Target* i_target,
                        uint32_t i_reg, uint32_t* i_val)
{
    mutex_lock(&iv_sio_mutex);
    errlHndl_t l_err = NULL;
    l_err = _ahbSioWrite(i_target, i_reg, i_val);
    mutex_unlock(&iv_sio_mutex);
    return l_err;
}

