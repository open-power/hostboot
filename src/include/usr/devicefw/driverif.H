/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/devicefw/driverif.H $                         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2016                        */
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
/** @file driverif.H
 *  @brief Provides the device driver interfaces for performing device access
 *         and enabling routing registration.
 *
 *  @note These interfaces should only be used by device drivers.  User code
 *        wanting to perform device operations should use userif.H instead.
 */
#ifndef __DEVICEFW_DRIVERIF
#define __DEVICEFW_DRIVERIF

#ifndef PARSER

#include <devicefw/userif.H>
#include <stdarg.h>
#include <builtins.h>
#include <targeting/common/targetservice.H>

#endif // not PARSER

namespace DeviceFW
{
    /** @enum AccessType_DriverOnly
     *  @brief Access types to be used internally by drivers for routing
     *         requests to other drivers.
     */
    enum AccessType_DriverOnly
    {
        XSCOM                   = LAST_ACCESS_TYPE,
        I2C,
        FSISCOM,
        IBSCOM,
        HOSTI2C,
        FSI_I2C,

        LAST_DRIVER_ACCESS_TYPE
    };

    /** @enum OperationType
     *  @brief Set of operations which can be registered for.
     */
    enum OperationType
    {
        READ = 0,
        WRITE,

        LAST_OP_TYPE,
        FIRST_OP_TYPE = READ

    };

    /** @enum DriverSpecial
     *  @brief Special Wildcard enum that can be used for drivers to do
     *         routing registrations.
     */
    enum DriverSpecial
    {
        WILDCARD = -1,
    };

#ifndef PARSER
    /** Construct the device addressing parameters for FSISCOM device ops.
     *  @param[in] i_address - FSISCOM address to operate on.
     */
    #define DEVICE_FSISCOM_ADDRESS(i_address) \
        DeviceFW::FSISCOM, static_cast<uint64_t>((i_address))

    /** Construct the device addressing parameters for XSCOM device ops.
     *  @param[in] i_address - XSCom address to operate on.
     */
    #define DEVICE_XSCOM_ADDRESS(i_address) \
        DeviceFW::XSCOM, static_cast<uint64_t>((i_address))

    /** Construct the device addressing parameters for IBSCOM (inband scom)
     *  device ops.
     *  @param[in] i_address - IBSCOM address to operate on.
     */
    #define DEVICE_IBSCOM_ADDRESS(i_address) \
        DeviceFW::IBSCOM, static_cast<uint64_t>((i_address))

    /**
     * @brief Macro that handles the I2C parameters
     */
    #define DEVICE_I2C_PARMS(port, engine, devAddr, offset_len, offset)\
        static_cast<uint64_t>( port ),\
        static_cast<uint64_t>( engine ),\
        static_cast<uint64_t>( devAddr ),\
        static_cast<uint64_t>( offset_len ),\
        static_cast<uint8_t*>( offset )

    /**
     * Construct the device addressing parameters for the I2C device ops.
     * @param[in] i_port - Which port to use from the I2C master.
     * @param[in] i_engine - Which I2C master engine to use.
     * @param[in] i_devAddr - The device address on a given engine/port.
     * @note '0' and 'NULL' added to line up with other DeviceFW::I2C
     */
    #define DEVICE_I2C_ADDRESS( i_port, i_engine, i_devAddr )\
        DeviceFW::I2C, DEVICE_I2C_PARMS(i_port, i_engine, i_devAddr, 0, NULL)

    /**
     * Construct the device addressing parameters for the I2C-offset device ops.
     * @param[in] i_port - Which port to use from the I2C master.
     * @param[in] i_engine - Which I2C master engine to use.
     * @param[in] i_devAddr - The device address on a given engine/port.
     * @param[in] i_offset_len - Length of offset (in bytes)
     * @param[in] i_offset - Offset into I2C device
     */
    #define DEVICE_I2C_ADDRESS_OFFSET( i_port, i_engine, i_devAddr, i_offset_len, i_offset)\
        DeviceFW::I2C,  DEVICE_I2C_PARMS(i_port, i_engine, i_devAddr, i_offset_len, i_offset)


    /**
     * Construct the device addressing parameters for locking the page
     * attribute of an I2C master target
     *
     * @param[in] i_port - Which port to use from the I2C master.
     * @param[in] i_engine - Which I2C master engine to use.
     * @param[in] i_shouldLock - bool to determine whether we are
     *                           attempting to lock or unlock the page.
     * @param[in] i_desired_page - The EEPROM page we want to switch to
     *                             iff a page switch is needed.
     * @param[in] i_lockMutex - bool to determine whether we actually
     *             want to lock the page mutex or not. This bool allows
     *             us to switch pages mid read without hitting a deadlock.
     */
#define DEVICE_I2C_CONTROL_PAGE_OP( i_port, i_engine, i_shouldLock, i_desired_page, i_lockMutex )\
            DeviceFW::I2C,\
            static_cast<uint64_t>(i_port),\
            static_cast<uint64_t>(i_engine),\
            0xffffffff,\
            static_cast<uint64_t>(i_shouldLock),\
            static_cast<uint64_t>(i_desiredPage),\
            static_cast<uint64_t>(i_lockMutex)


    /**
     * Construct the device addressing parameters for the Host I2C device ops.
     * @param[in] i_port - Which port to use from the I2C master.
     * @param[in] i_engine - Which I2C master engine to use.
     * @param[in] i_devAddr - The device address on a given engine/port.
     * @note '0' and 'NULL' added to line up with other DeviceFW::I2C
     */
    #define DEVICE_HOSTI2C_ADDRESS( i_port, i_engine, i_devAddr )\
        DeviceFW::HOSTI2C, DEVICE_I2C_PARMS(i_port, i_engine, i_devAddr, 0, NULL)

    /**
     * Construct the device addressing parameters for the Host I2C-offset device ops.
     * @param[in] i_port - Which port to use from the I2C master.
     * @param[in] i_engine - Which I2C master engine to use.
     * @param[in] i_devAddr - The device address on a given engine/port.
     * @param[in] i_offset_len - Length of offset (in bytes)
     * @param[in] i_offset - Offset into I2C device
     */
    #define DEVICE_HOSTI2C_ADDRESS_OFFSET( i_port, i_engine, i_devAddr, i_offset_len, i_offset)\
        DeviceFW::HOSTI2C, DEVICE_I2C_PARMS(i_port, i_engine, i_devAddr, i_offset_len, i_offset)

    /**
     * Construct the device addressing parameters for the FSI I2C device ops.
     * @param[in] i_port - Which port to use from the I2C master.
     * @param[in] i_engine - Which I2C master engine to use.
     * @param[in] i_devAddr - The device address on a given engine/port.
     * @note '0' and 'NULL' added to line up with other DeviceFW::I2C
     */
    #define DEVICE_FSI_I2C_ADDRESS( i_port, i_engine, i_devAddr )\
        DeviceFW::FSI_I2C, DEVICE_I2C_PARMS(i_port, i_engine, i_devAddr, 0, NULL)

    /**
     * Construct the device addressing parameters for the FSI I2C-offset device ops.
     * @param[in] i_port - Which port to use from the I2C master.
     * @param[in] i_engine - Which I2C master engine to use.
     * @param[in] i_devAddr - The device address on a given engine/port.
     * @param[in] i_offset_len - Length of offset (in bytes)
     * @param[in] i_offset - Offset into I2C device
     */
    #define DEVICE_FSI_I2C_ADDRESS_OFFSET( i_port, i_engine, i_devAddr, i_offset_len, i_offset)\
        DeviceFW::FSI_I2C, DEVICE_I2C_PARMS(i_port, i_engine, i_devAddr, i_offset_len, i_offset)


    /** @class InvalidParameterType
     *  @brief Unused type to cause compiler fails for invalid template types.
     *
     *  Forward Declaration of type that is never actually used anywhere.
     *
     *  Assists in making more developer friendly compiler fails when a
     *  template function is called for which there is no specialization and
     *  the default template function should never be used.  This is used for
     *  allowing function calls that take multiple enum types but still provide
     *  type-safety above a int-parameter.
     */
    class InvalidParameterType;

    /** @typedef deviceOp_t
     *  @brief Function prototype for registered device-driver operations.
     */
    typedef errlHndl_t(*deviceOp_t)(OperationType,
                                    TARGETING::Target*,
                                    void*, size_t&,
                                    int64_t, va_list);

    /**
     *  @brief Register a device driver routing function with the framework.
     *
     *  @param[in] i_opType - Enumeration specifying the operation this
     *                        driver performs. (Read, Write, Wildcard)
     *  @param[in] i_accessType - Enumeration specifying the access type this
     *                            driver performs. (SCOM, XSCOM, PNOR, etc.)
     *  @param[in] i_targetType - Enumeration specifying the target type this
     *                            driver performs. (Proc, MC, Wildcard, etc.)
     *  @param[in] i_regRoute - The function being registered.
     *
     *  This function call be called to register a device driver routing
     *  function with the framework.  If it is desired to always register a
     *  device driver when the module associated with that driver is loaded,
     *  the DEVICE_REGISTER_ROUTE macro can be used.
     *
     *  <PRE>
     *  Example usage:
     *          // High-level address manipulation routing function.
     *          deviceRegisterRoute(WILDCARD,
     *                              SCOM,
     *                              TYPE_CORE,
     *                              &scomAdjustCoreAddresses);
     *
     *          // Low-level (internal) XSCOM read operation.
     *          deviceRegisterRoute(READ,
     *                              XSCOM,
     *                              TYPE_PROC,
     *                              &xscomPerformRead);
     *  </PRE>
     *
     * @note Valid OpType are OperatorType enum or WILDCARD.
     * @note Valid TargType are TargetType enum or WILDCARD.
     * @note Valid AccType are AccessType or AccessType_DriverOnly; WILDCARD is
     *       not permitted.
     *
     * @note Any unsupported enumeration type will result in a compile error
     *       referencing a InvalidParameterType class.
     */
    template <typename OpType, typename AccType, typename TargType>
    void deviceRegisterRoute(OpType i_opType,
                             AccType i_accessType,
                             TargType i_targetType,
                             deviceOp_t i_regRoute)
    {
        InvalidParameterType(); // Cause a compile fail if not one of
                                       // the explicit template specializations.
    }

        /** Assistance macro for stringification. */
    #define __DEVICE_REGISTER_ROUTE_XYZ(X,Y,Z) X##Y##Z
        /** Assistance macro for stringification. */
    #define __DEVICE_REGISTER_ROUTE_MAKENAME(X,Y,Z) \
                    __DEVICE_REGISTER_ROUTE_XYZ(X,Y,Z)

    /**
     *  @brief Create a static constructed registration of a device driver
     *         function when a module is loaded.
     *
     *  Parameters are the same as DeviceFW::deviceRegisterRoute, except the
     *  route function should be passed by name as opposed to pointer.
     *
     *  If the route function is in a namespace, then this definition must
     *  also be placed into that namespace.
     */
    #define DEVICE_REGISTER_ROUTE(i_opType, i_accessType, \
                                  i_targetType, i_regRoute) \
        class __DEVICE_REGISTER_ROUTE_MAKENAME(DeviceRouteRegistrator_, \
                                               i_regRoute, __LINE__) \
        { \
            public: \
                __DEVICE_REGISTER_ROUTE_MAKENAME(DeviceRouteRegistrator_, \
                                                 i_regRoute, __LINE__)() \
                { \
                    DeviceFW::deviceRegisterRoute(i_opType, i_accessType, \
                                                  i_targetType, &i_regRoute); \
                } \
        }; \
        __DEVICE_REGISTER_ROUTE_MAKENAME(DeviceRouteRegistrator_, \
                                         i_regRoute, __LINE__) \
            __DEVICE_REGISTER_ROUTE_MAKENAME(DeviceRouteRegistrator_instance_, \
                                             i_regRoute, __LINE__);

    /**
     *  @brief Perform a device operation by routing through the framework and
     *         calling the appropriate registered operation.
     *
     *  @param[in] i_opType - Operation request (READ vs WRITE).
     *  @param[in] i_target - Target to perform operation on.
     *  @param[in,out] io_buffer - Data buffer for operation.
     *  @param[in,out] io_buflen - Length of buffer / result size.
     *  @param[in] i_accessType - Type of hardware access method to perform.
     *
     *  This function has similar behavior as the user-visible deviceRead and
     *  deviceWrite functions and is meant as a method for device drivers to
     *  perform accesses which may be only visible to internal drivers.
     */
    template <typename AccType>
    errlHndl_t deviceOp(OperationType i_opType,
                        TARGETING::Target* i_target,
                        void* io_buffer, size_t& io_buflen,
                        AccType i_accessType, ...)
    {
        return InvalidParameterType(); // Cause a compile fail if not one of
                                       // the explicit template specializations.
    }

    /**
     *  @brief Perform a device operation by routing through the framework and
     *         calling the appropriate registered operation.
     *
     *  @param[in] i_opType - Operation request (READ vs WRITE).
     *  @param[in] i_target - Target to perform operation on.
     *  @param[in,out] io_buffer - Data buffer for operation.
     *  @param[in,out] io_buflen - Length of buffer / result size.
     *  @param[in] i_accessType - Type of hardware access method to perform.
     *  @param[in] i_args - va_list of parameters for device operation.
     *
     *  This function has similar behavior as the user-visible deviceRead and
     *  deviceWrite functions and is meant as a method for device drivers to
     *  perform accesses which may be only visible to internal drivers.
     */
    template <typename AccType>
    errlHndl_t deviceOpValist(OperationType i_opType,
                        TARGETING::Target* i_target,
                        void* io_buffer, size_t& io_buflen,
                        AccType i_accessType, va_list i_args)
    {
        return InvalidParameterType(); // Cause a compile fail if not one of
                                       // the explicit template specializations.
    }

    // --- Below are template specializations to aid in type-safety. ---

    // deviceRegisterRoute:
    //          OpType - OperationType or WILDCARD
    //          TargType - TargetType or WILDCARD
    //          AccType - AccessType, AccessType_DriverOnly (no WILDCARD).

    template <>
    void deviceRegisterRoute<>(OperationType i_opType,
                               AccessType i_accessType,
                               TARGETING::TYPE i_targetType,
                               deviceOp_t i_regRoute);
    template <>
    void deviceRegisterRoute<>(OperationType i_opType,
                               AccessType_DriverOnly i_accessType,
                               TARGETING::TYPE i_targetType,
                               deviceOp_t i_regRoute);
    template <>
    void deviceRegisterRoute<>(OperationType i_opType,
                               AccessType i_accessType,
                               DriverSpecial i_targetType,
                               deviceOp_t i_regRoute);
    template <>
    void deviceRegisterRoute<>(OperationType i_opType,
                               AccessType_DriverOnly i_accessType,
                               DriverSpecial i_targetType,
                               deviceOp_t i_regRoute);
    template <>
    void deviceRegisterRoute<>(DriverSpecial i_opType,
                               AccessType i_accessType,
                               TARGETING::TYPE i_targetType,
                               deviceOp_t i_regRoute);
    template <>
    void deviceRegisterRoute<>(DriverSpecial i_opType,
                               AccessType_DriverOnly i_accessType,
                               TARGETING::TYPE i_targetType,
                               deviceOp_t i_regRoute);
    template <>
    void deviceRegisterRoute<>(DriverSpecial i_opType,
                               AccessType i_accessType,
                               DriverSpecial i_targetType,
                               deviceOp_t i_regRoute);
    template <>
    void deviceRegisterRoute<>(DriverSpecial i_opType,
                               AccessType_DriverOnly i_accessType,
                               DriverSpecial i_targetType,
                               deviceOp_t i_regRoute);

    // deviceOp:
    //          OpType - OperationType only.
    //          TargType - TargetType only.
    //          AccType - AccessType, AccessType_DriverOnly (no WILDCARD).
    template <>
    errlHndl_t deviceOp<>(OperationType i_opType,
                          TARGETING::Target* i_target,
                          void* io_buffer, size_t& io_buflen,
                          AccessType i_accessType, ...);
    template <>
    errlHndl_t deviceOp<>(OperationType i_opType,
                          TARGETING::Target* i_target,
                          void* io_buffer, size_t& io_buflen,
                          AccessType_DriverOnly i_accessType, ...);

    // deviceOpValist:
    //          OpType - OperationType only.
    //          TargType - TargetType only.
    //          AccType - AccessType, AccessType_DriverOnly (no WILDCARD).
    //          args - va_list of parameters
    template <>
    errlHndl_t deviceOpValist<>(OperationType i_opType,
                          TARGETING::Target* i_target,
                          void* io_buffer, size_t& io_buflen,
                          AccessType i_accessType, va_list i_args);
    template <>
    errlHndl_t deviceOpValist<>(OperationType i_opType,
                          TARGETING::Target* i_target,
                          void* io_buffer, size_t& io_buflen,
                          AccessType_DriverOnly i_accessType, va_list i_args);
#endif // not PARSER
};

#endif
