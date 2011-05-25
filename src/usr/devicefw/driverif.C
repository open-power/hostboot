/** @file driverif.C
 *  Implement the template specializations of functions from driverif.H.
 */
#include <devicefw/driverif.H>
#include <util/singleton.H>

#include "associator.H"

namespace DeviceFW
{
    template <> 
    void deviceRegisterRoute<>(OperationType i_opType,
                              AccessType i_accessType,
                              TargetType_t i_targetType,
                              deviceOp_t i_regRoute)
    {
        Singleton<Associator>::instance().registerRoute(
                static_cast<int64_t>(i_opType),
                static_cast<int64_t>(i_accessType),
                static_cast<int64_t>(i_targetType),
                i_regRoute);
    }

    template <> 
    void deviceRegisterRoute<>(OperationType i_opType,
                              AccessType_DriverOnly i_accessType,
                              TargetType_t i_targetType,
                              deviceOp_t i_regRoute) 
    {
        Singleton<Associator>::instance().registerRoute(
                static_cast<int64_t>(i_opType),
                static_cast<int64_t>(i_accessType),
                static_cast<int64_t>(i_targetType),
                i_regRoute);
    }

    template <> 
    void deviceRegisterRoute<>(OperationType i_opType,
                              AccessType i_accessType,
                              DriverSpecial i_targetType,
                              deviceOp_t i_regRoute) 
    {
        Singleton<Associator>::instance().registerRoute(
                static_cast<int64_t>(i_opType),
                static_cast<int64_t>(i_accessType),
                static_cast<int64_t>(i_targetType),
                i_regRoute);
    }

    template <> 
    void deviceRegisterRoute<>(OperationType i_opType,
                              AccessType_DriverOnly i_accessType,
                              DriverSpecial i_targetType,
                              deviceOp_t i_regRoute) 
    {
        Singleton<Associator>::instance().registerRoute(
                static_cast<int64_t>(i_opType),
                static_cast<int64_t>(i_accessType),
                static_cast<int64_t>(i_targetType),
                i_regRoute);
    }

    template <> 
    void deviceRegisterRoute<>(DriverSpecial i_opType,
                              AccessType i_accessType,
                              TargetType_t i_targetType,
                              deviceOp_t i_regRoute) 
    {
        Singleton<Associator>::instance().registerRoute(
                static_cast<int64_t>(i_opType),
                static_cast<int64_t>(i_accessType),
                static_cast<int64_t>(i_targetType),
                i_regRoute);
    }

    template <> 
    void deviceRegisterRoute<>(DriverSpecial i_opType,
                              AccessType_DriverOnly i_accessType,
                              TargetType_t i_targetType,
                              deviceOp_t i_regRoute) 
    {
        Singleton<Associator>::instance().registerRoute(
                static_cast<int64_t>(i_opType),
                static_cast<int64_t>(i_accessType),
                static_cast<int64_t>(i_targetType),
                i_regRoute);
    }

    template <> 
    void deviceRegisterRoute<>(DriverSpecial i_opType,
                              AccessType i_accessType,
                              DriverSpecial i_targetType,
                              deviceOp_t i_regRoute) 
    {
        Singleton<Associator>::instance().registerRoute(
                static_cast<int64_t>(i_opType),
                static_cast<int64_t>(i_accessType),
                static_cast<int64_t>(i_targetType),
                i_regRoute);
    }

    template <> 
    void deviceRegisterRoute<>(DriverSpecial i_opType,
                              AccessType_DriverOnly i_accessType,
                              DriverSpecial i_targetType,
                              deviceOp_t i_regRoute) 
    {
        Singleton<Associator>::instance().registerRoute(
                static_cast<int64_t>(i_opType),
                static_cast<int64_t>(i_accessType),
                static_cast<int64_t>(i_targetType),
                i_regRoute);
    }

    // deviceOp:
    //          OpType - OperationType only.
    //          TargType - TargetType only.
    //          AccType - AccessType, AccessType_DriverOnly (no WILDCARD).
    template <> 
    errlHndl_t deviceOp<>(OperationType i_opType,
                          TargetHandle_t i_target,
                          void* io_buffer, size_t& io_buflen,
                          AccessType i_accessType, ...)
    {
        va_list args;
        errlHndl_t errl;

        va_start(args, i_accessType);

        errl = Singleton<Associator>::instance().performOp(
                i_opType, i_target, io_buffer, io_buflen,
                i_accessType, args);

        va_end(args);
        return errl;
    }

    template <> 
    errlHndl_t deviceOp<>(OperationType i_opType,
                          TargetHandle_t i_target,
                          void* io_buffer, size_t& io_buflen,
                          AccessType_DriverOnly i_accessType, ...)
    {
        va_list args;
        errlHndl_t errl;

        va_start(args, i_accessType);

        errl = Singleton<Associator>::instance().performOp(
                i_opType, i_target, io_buffer, io_buflen,
                i_accessType, args);

        va_end(args);
        return errl;
    }

};
