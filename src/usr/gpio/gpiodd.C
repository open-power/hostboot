/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/gpio/gpiodd.C $                                       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2020                        */
/* [+] Google Inc.                                                        */
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

#include <trace/interface.H>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <errl/errludtarget.H>
#include <errl/errludstring.H>
#include <targeting/common/targetservice.H>
#include <targeting/common/commontargeting.H>
#include <devicefw/driverif.H>
#include "gpiodd.H"
#include <gpio/gpioddreasoncodes.H>
#include <gpio/gpioif.H>
#include <config.h>

trace_desc_t * g_trac_gpio = NULL;
TRAC_INIT( & g_trac_gpio, GPIO_COMP_NAME, KILOBYTE );

using namespace DeviceFW;

namespace GPIO
{

enum
{
    // Asserting that a GPIO Port Extender will never have more than an 8-bit
    // address as these devices never have more than a handful of control
    // registers.
    GPIO_ADDR_SIZE = 1,
};

// Link to device driver interface
DEVICE_REGISTER_ROUTE( DeviceFW::WILDCARD,
                       DeviceFW::GPIO,
                       TARGETING::TYPE_MEMBUF,
                       gpioPerformOp);

DEVICE_REGISTER_ROUTE( DeviceFW::WILDCARD,
                       DeviceFW::GPIO,
                       TARGETING::TYPE_PROC,
                       gpioPerformOp);

errlHndl_t gpioPerformOp(DeviceFW::OperationType i_opType,
                         TARGETING::Target * i_target,
                         void * io_buffer,
                         size_t & i_buflen,
                         int64_t i_accessType,
                         va_list i_args)
{
    errlHndl_t err = NULL;
    gpioAddr_t gpioInfo;

    gpioInfo.deviceType = va_arg( i_args, uint64_t );
    gpioInfo.portAddr   = va_arg( i_args, uint64_t );

    TRACDCOMP(g_trac_gpio, ENTER_MRK"gpioPerformOp(): "
              "optype %d deviceType %d portAddr %d",
              i_opType, gpioInfo.deviceType, gpioInfo.portAddr);

    do
    {
        err = gpioReadAttributes (i_target, gpioInfo);
        if( err )
        {
            break;
        }

        char * path_str = gpioInfo.i2cMasterPath.toString();

        TARGETING::TargetService& ts = TARGETING::targetService();
        TARGETING::Target * i2c_master = ts.toTarget(gpioInfo.i2cMasterPath);

        if( i2c_master == NULL )
        {
            TRACFCOMP( g_trac_gpio,ERR_MRK"gpioPerformOp() - "
                       "I2C Target not found. Device type %d. entity path=%s",
                       gpioInfo.deviceType, path_str );
            /*@
             * @errortype
             * @reasoncode       GPIO_I2C_TARGET_NOT_FOUND
             * @severity         ERRORLOG::ERRL_SEV_UNRECOVERABLE
             * @moduleid         GPIO_PERFORM_OP
             * @userdata1        Device type
             * @userdata2        HUID of target
             * @devdesc          Invalid GPIO device type
             * @custdesc         A problem occurred during the IPL
             *                   of the system.
             */
            err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                          GPIO::GPIO_PERFORM_OP,
                                          GPIO::GPIO_I2C_TARGET_NOT_FOUND,
                                          gpioInfo.deviceType,
                                          TARGETING::get_huid(i_target),
                                          true /*Add HB SW Callout*/ );

            err->collectTrace( GPIO_COMP_NAME );
            ERRORLOG::ErrlUserDetailsString(path_str).addToLog(err);
            free(path_str);
            path_str=nullptr;
            break;
        }
        else
        {
            TRACDCOMP( g_trac_gpio,INFO_MRK"gpioPerformOp() - "
                       "I2C Target entity path=%s",
                       path_str );
        }
        free(path_str);
        path_str = nullptr;

        if( i_opType == DeviceFW::READ )
        {
            err = gpioRead(i2c_master,
                           io_buffer,
                           i_buflen,
                           gpioInfo);

            if( err )
            {
                break;
            }
        }
        else if (i_opType == DeviceFW::WRITE )
        {
            err = gpioWrite(i2c_master,
                            io_buffer,
                            i_buflen,
                            gpioInfo);

            if( err )
            {
                break;
            }
        }
        else
        {
            TRACFCOMP( g_trac_gpio,ERR_MRK"gpioPerformOp() - "
                       "Invalid OP type %d.",
                       i_opType );
            /*@
             * @errortype
             * @reasoncode       GPIO_INVALID_OP
             * @severity         ERRORLOG::ERRL_SEV_UNRECOVERABLE
             * @moduleid         GPIO_PERFORM_OP
             * @userdata1        OP type
             * @userdata2        HUID of target
             * @devdesc          Invalid GPIO device type
             * @custdesc         A problem occurred during the IPL
             *                   of the system.
             */
            err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                          GPIO::GPIO_PERFORM_OP,
                                          GPIO::GPIO_INVALID_OP,
                                          i_opType,
                                          TARGETING::get_huid(i_target),
                                          true /*Add HB SW Callout*/ );

            err->collectTrace( GPIO_COMP_NAME );
            break;
        }

    } while (0);

    return err;
}

errlHndl_t gpioRead( TARGETING::Target * i_target,
                     void * o_buffer,
                     size_t & io_buflen,
                     gpioAddr_t & i_gpioInfo)
{
    errlHndl_t err = NULL;

    // This i2c interface writes the gpio portAddr to the device
    // then reads the value of the port w/o a stop bit in between ops
    err = deviceOp( DeviceFW::READ,
                    i_target,
                    o_buffer,
                    io_buflen,
                    DEVICE_I2C_ADDRESS_OFFSET
                    ( i_gpioInfo.i2cPort,
                      i_gpioInfo.engine,
                      i_gpioInfo.i2cDeviceAddr,
                      GPIO_ADDR_SIZE,
                      reinterpret_cast<uint8_t*>(&(i_gpioInfo.portAddr)),
                      i_gpioInfo.i2cMuxBusSelector,
                      &(i_gpioInfo.i2cMuxPath)
                    )
                  );
    if(err)
    {
        err->collectTrace( GPIO_COMP_NAME );
    }

    return err;
}

errlHndl_t gpioWrite ( TARGETING::Target * i_target,
                     void * i_buffer,
                     size_t i_buflen,
                     gpioAddr_t & i_gpioInfo)
{
    errlHndl_t err = NULL;

    size_t cmdlen = GPIO_ADDR_SIZE + i_buflen;
    uint8_t cmd[cmdlen];
    cmd[0] = i_gpioInfo.portAddr;
    memcpy(&(cmd[GPIO_ADDR_SIZE]), i_buffer, i_buflen);

    err = deviceOp( DeviceFW::WRITE,
                    i_target,
                    &cmd,
                    cmdlen,
                    DEVICE_I2C_ADDRESS
                    ( i_gpioInfo.i2cPort,
                      i_gpioInfo.engine,
                      i_gpioInfo.i2cDeviceAddr,
                      i_gpioInfo.i2cMuxBusSelector,
                      &(i_gpioInfo.i2cMuxPath)
                    )
                  );
    if(err)
    {
        err->collectTrace( GPIO_COMP_NAME );
    }

    return err;
}


errlHndl_t gpioReadAttributes ( TARGETING::Target * i_target,
                                gpioAddr_t & io_gpioInfo)
{
    errlHndl_t err = NULL;

    bool attrReadErr = false;

#ifndef CONFIG_FSP_BUILD
    TARGETING::GpioInfo gpioData;
#endif
    TARGETING::GpioInfoPhysPres gpioDataPhysPres;

    switch(io_gpioInfo.deviceType)
    {
#ifndef CONFIG_FSP_BUILD
        case PCA95X_GPIO:
            if( !( i_target->
                   tryGetAttr<TARGETING::ATTR_GPIO_INFO>( gpioData ) ) )
            {
                attrReadErr = true;
            }
            else
            {
                io_gpioInfo.i2cMasterPath = gpioData.i2cMasterPath;
                io_gpioInfo.engine        = gpioData.engine;
                io_gpioInfo.i2cPort       = gpioData.port;
                io_gpioInfo.i2cDeviceAddr = gpioData.devAddr;
                io_gpioInfo.i2cMuxBusSelector = gpioData.i2cMuxBusSelector;
                io_gpioInfo.i2cMuxPath    = gpioData.i2cMuxPath;
            }
            break;
#endif
        case PCA9551_GPIO_PHYS_PRES:

            if( !( i_target->
                   tryGetAttr<TARGETING::ATTR_GPIO_INFO_PHYS_PRES>(gpioDataPhysPres)))
            {
                attrReadErr = true;
            }
            else
            {
                io_gpioInfo.i2cMasterPath = gpioDataPhysPres.i2cMasterPath;
                io_gpioInfo.engine        = gpioDataPhysPres.engine;
                io_gpioInfo.i2cPort       = gpioDataPhysPres.port;
                io_gpioInfo.i2cDeviceAddr = gpioDataPhysPres.devAddr;
                io_gpioInfo.i2cMuxBusSelector = gpioDataPhysPres.i2cMuxBusSelector;
                io_gpioInfo.i2cMuxPath    = gpioDataPhysPres.i2cMuxPath;
            }
            break;

        default:

            TRACFCOMP( g_trac_gpio,ERR_MRK"gpioReadAttributes() - "
                       "Invalid device type (%d) to read attributes from!",
                       io_gpioInfo.deviceType );
            /*@
             * @errortype
             * @reasoncode       GPIO_INVALID_DEVICE_TYPE
             * @severity         ERRORLOG::ERRL_SEV_UNRECOVERABLE
             * @moduleid         GPIO_READATTRIBUTES
             * @userdata1        Device type
             * @userdata2        HUID of target
             * @devdesc          Invalid GPIO device type
             * @custdesc         A problem occurred during the IPL
             *                   of the system.
             */
            err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                          GPIO::GPIO_READATTRIBUTES,
                                          GPIO::GPIO_INVALID_DEVICE_TYPE,
                                          io_gpioInfo.deviceType,
                                          TARGETING::get_huid(i_target),
                                          true /*Add HB SW Callout*/ );

            err->collectTrace( GPIO_COMP_NAME );

            break;
    }

    if(attrReadErr)
    {
        TRACFCOMP( g_trac_gpio,
                   ERR_MRK"gpioReadAttributes() - ERROR reading "
                   "attributes for device type %d!",
                   io_gpioInfo.deviceType );

        /*@
         * @errortype
         * @reasoncode       GPIO_ATTR_INFO_NOT_FOUND
         * @severity         ERRORLOG::ERRL_SEV_UNRECOVERABLE
         * @moduleid         GPIO_READATTRIBUTES
         * @userdata1        HUID of target
         * @userdata2        GPIO device type
         * @devdesc          GPIO device attribute was not found
         * @custdesc         A problem occurred during the IPL
         *                   of the system.
         */
        err = new ERRORLOG::ErrlEntry(
                                      ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                      GPIO::GPIO_READATTRIBUTES,
                                      GPIO::GPIO_ATTR_INFO_NOT_FOUND,
                                      TARGETING::get_huid(i_target),
                                      io_gpioInfo.deviceType,
                                      true /*Add HB SW Callout*/);


        err->collectTrace( GPIO_COMP_NAME );
    }

    return err;
}

}; // end namespace GPIO

