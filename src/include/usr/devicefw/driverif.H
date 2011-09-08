//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/include/usr/devicefw/driverif.H $
//
//  IBM CONFIDENTIAL
//
//  COPYRIGHT International Business Machines Corp. 2011
//
//  p1
//
//  Object Code Only (OCO) source materials
//  Licensed Internal Code Source Materials
//  IBM HostBoot Licensed Internal Code
//
//  The source code for this program is not published or other-
//  wise divested of its trade secrets, irrespective of what has
//  been deposited with the U.S. Copyright Office.
//
//  Origin: 30
//
//  IBM_PROLOG_END
/** @file driverif.H
 *  @brief Provides the device driver interfaces for performing device access
 *         and enabling routing registration.
 *
 *  @note These interfaces should only be used by device drivers.  User code
 *        wanting to perform device operations should use userif.H instead.
 */
#ifndef __DEVICEFW_DRIVERIF
#define __DEVICEFW_DRIVERIF

#include <devicefw/userif.H>
#include <stdarg.h>
#include <builtins.h>
#include <targeting/targetservice.H>

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

        LAST_DRIVER_ACCESS_TYPE
    };

    /** @enum OperationType
     *  @brief Set of operations which can be registered for.
     */
    enum OperationType
    {
        READ = 0,
        WRITE,

        LAST_OP_TYPE

    };

    /** @enum DriverSpecial
     *  @brief Special Wildcard enum that can be used for drivers to do
     *         routing registrations.
     */
    enum DriverSpecial
    {
        WILDCARD = -1,
    };

    /** Construct the device addressing parameters for XSCOM device ops.
     *  @param[in] i_address - XSCom address to operate on.
     */
    #define DEVICE_XSCOM_ADDRESS(i_address) \
        DeviceFW::XSCOM, static_cast<uint64_t>((i_address))

    /**
     * Construct the device addressing parameters for the I2C device ops.
     */
    #define DEVICE_I2C_ADDRESS( i_address )\
        DeviceFW::I2C, static_cast<uint64_t>(( i_address ))

    /** Construct the device addressing parameters for FSI device ops.
     *  @param[in] i_address - FSI address to operate on.
     */
    #define DEVICE_FSI_ADDRESS(i_address) \
        DeviceFW::FSI, static_cast<uint64_t>((i_address))


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
        return InvalidParameterType(); // Cause a compile fail if not one of
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

};

#endif
