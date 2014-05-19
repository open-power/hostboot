/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/devicefw/driverif.C $                                 */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2011,2014              */
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
/** @file driverif.C
 *  Implement the template specializations of functions from driverif.H.
 */
#include <devicefw/driverif.H>
#include <util/singleton.H>
#include <errl/errlmanager.H>

#include "associator.H"

namespace DeviceFW
{
    /** @brief Wrapper function to call singleton instance for registerRoute.
     *
     *  This is defined as an extern "C" function so that it can be aliased
     *  by the template type-safe implementations of deviceRegisterRoute().
     *  This causes the compiler to generate just a single copy of the code.
     */
    extern "C" 
    void DeviceFW_deviceRegisterRoute(int64_t i_opType,
                                      int64_t i_accessType,
                                      int64_t i_targetType,
                                      deviceOp_t i_regRoute)
    {
        errlHndl_t errhdl =
          Singleton<Associator>::instance().registerRoute(i_opType,
                                                          i_accessType,
                                                          i_targetType,
                                                          i_regRoute);
        if( errhdl )
        {
            errlCommit(errhdl,DEVFW_COMP_ID);
        }
    }

    // deviceRegisterRoute:
    //          OpType - OperationType or WILDCARD
    //          TargType - TargetType or WILDCARD
    //          AccType - AccessType, AccessType_DriverOnly (no WILDCARD).

    template <> 
    void deviceRegisterRoute<>(OperationType i_opType,
                               AccessType i_accessType,
                               TARGETING::TYPE i_targetType,
                               deviceOp_t i_regRoute)
        __attribute__((alias("DeviceFW_deviceRegisterRoute")));

    template <> 
    void deviceRegisterRoute<>(OperationType i_opType,
                               AccessType_DriverOnly i_accessType,
                               TARGETING::TYPE i_targetType,
                               deviceOp_t i_regRoute) 
        __attribute__((alias("DeviceFW_deviceRegisterRoute")));

    template <> 
    void deviceRegisterRoute<>(OperationType i_opType,
                               AccessType i_accessType,
                               DriverSpecial i_targetType,
                               deviceOp_t i_regRoute)
        __attribute__((alias("DeviceFW_deviceRegisterRoute")));

    template <> 
    void deviceRegisterRoute<>(OperationType i_opType,
                               AccessType_DriverOnly i_accessType,
                               DriverSpecial i_targetType,
                               deviceOp_t i_regRoute) 
        __attribute__((alias("DeviceFW_deviceRegisterRoute")));

    template <> 
    void deviceRegisterRoute<>(DriverSpecial i_opType,
                              AccessType i_accessType,
                              TARGETING::TYPE i_targetType,
                              deviceOp_t i_regRoute)
        __attribute__((alias("DeviceFW_deviceRegisterRoute")));

    template <> 
    void deviceRegisterRoute<>(DriverSpecial i_opType,
                               AccessType_DriverOnly i_accessType,
                               TARGETING::TYPE i_targetType,
                               deviceOp_t i_regRoute)
        __attribute__((alias("DeviceFW_deviceRegisterRoute")));

    template <> 
    void deviceRegisterRoute<>(DriverSpecial i_opType,
                               AccessType i_accessType,
                               DriverSpecial i_targetType,
                               deviceOp_t i_regRoute)
        __attribute__((alias("DeviceFW_deviceRegisterRoute")));    

    template <> 
    void deviceRegisterRoute<>(DriverSpecial i_opType,
                               AccessType_DriverOnly i_accessType,
                               DriverSpecial i_targetType,
                               deviceOp_t i_regRoute)
        __attribute__((alias("DeviceFW_deviceRegisterRoute")));

    /** @brief Wrapper function to call singleton instance for performOp.
     *
     *  This is defined as an extern "C" function so that it can be aliased
     *  by the template type-safe implementations of deviceOp().
     *  This causes the compiler to generate just a single copy of the code.
     */
    extern "C"
    errlHndl_t DeviceFW_deviceOp(OperationType i_opType,
                                 TARGETING::Target* i_target,
                                 void* io_buffer, size_t& io_buflen,
                                 int64_t i_accessType, ...)
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

    // deviceOp:
    //          OpType - OperationType only.
    //          TargType - TargetType only.
    //          AccType - AccessType, AccessType_DriverOnly (no WILDCARD).
    template <> 
    errlHndl_t deviceOp<>(OperationType i_opType,
                          TARGETING::Target* i_target,
                          void* io_buffer, size_t& io_buflen,
                          AccessType i_accessType, ...)
        __attribute__((alias("DeviceFW_deviceOp")));

    template <> 
    errlHndl_t deviceOp<>(OperationType i_opType,
                          TARGETING::Target* i_target,
                          void* io_buffer, size_t& io_buflen,
                          AccessType_DriverOnly i_accessType, ...)
        __attribute__((alias("DeviceFW_deviceOp")));        

    /** @brief Wrapper function to call singleton instance for performOp.
     *
     *  This is defined as an extern "C" function so that it can be aliased
     *  by the template type-safe implementations of deviceOpValist().
     *  This causes the compiler to generate just a single copy of the code.
     */
    extern "C"
    errlHndl_t DeviceFW_deviceOpValist(OperationType i_opType,
                                 TARGETING::Target* i_target,
                                 void* io_buffer, size_t& io_buflen,
                                 int64_t i_accessType, va_list i_args)
    {
        errlHndl_t errl;

        errl = Singleton<Associator>::instance().performOp(
                i_opType, i_target, io_buffer, io_buflen,
                i_accessType, i_args);

        return errl;
    }

    // deviceOpValist:
    //          OpType - OperationType only.
    //          TargType - TargetType only.
    //          AccType - AccessType, AccessType_DriverOnly (no WILDCARD).
    //          args - va_list of parameters
    template <> 
    errlHndl_t deviceOpValist<>(OperationType i_opType,
                          TARGETING::Target* i_target,
                          void* io_buffer, size_t& io_buflen,
                          AccessType i_accessType, va_list i_args)
        __attribute__((alias("DeviceFW_deviceOpValist")));

    template <> 
    errlHndl_t deviceOpValist<>(OperationType i_opType,
                          TARGETING::Target* i_target,
                          void* io_buffer, size_t& io_buflen,
                          AccessType_DriverOnly i_accessType, va_list i_args)
        __attribute__((alias("DeviceFW_deviceOpValist")));        

};
