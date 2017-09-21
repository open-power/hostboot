/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/fapi2/subroutine_executor.H $                 */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2017                        */
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
///
/// @file subroutine_executor.H
///
/// @brief Defines the PLAT Subroutine Executor Macro.
///
/// The PLAT Subroutine Executor macro is called by
/// FAPI_CALL_SUBROUTINE when a hardware procedure has
/// a subroutine is needed, typicaly a chipop function.
///
/// Example implementation of plat code

#ifndef SUBROUTINEEXECUTOR_H_
#define SUBROUTINEEXECUTOR_H_

#include <fapi2_subroutine_executor.H>
#include <errl/errlmanager.H>
#include <string.h>
#include <stdarg.h>
#include <sbeio/sbeioif.H>
#include <plat_trace.H>
#include <secureboot/service.H>
#include <plat_hw_access.H>

/**
* @brief Given a hwp name, and its parameters, serialize the parmeters and pass the serialized
*        data to the SBE via a FIFO chipop
* @param[in]  i_hwpName  String representing the name of the hwp to be called
* @param[in]  i_Target   TARGETING::Target which op is being called on
* @param[in]  types      Any variable length of arguments, which along with target should get passed
*                        in as parameters to the given HWP
* @return errlHndl_t Error log handle on failure.
*/
template<class... Types>
errlHndl_t requestHwpViaSbe(const char * i_hwpName, TARGETING::Target * i_target, Types... types)
{
    errlHndl_t l_errl = nullptr;

    //Determine argument byte size
    size_t l_sizeOfArgInBytes =0;
    using expander = int[];
    (void) expander{ 0, (l_sizeOfArgInBytes+=sizeof(types), 0)... };

    //Set up the buffer which will be passed to chip op send function
    uint8_t l_buffer[l_sizeOfArgInBytes];
    uint8_t* l_bufferPtr = &l_buffer[0];
    memset(l_bufferPtr, 0, l_sizeOfArgInBytes);

    // Serialize the arguments into the buffer
    (void) expander{ 0, ((memcpy(l_bufferPtr,&types,sizeof(types)),l_bufferPtr+=sizeof(types)), 0)... };

    //Call the chip op send function to request the SBE to call the HWP
    l_errl = SBEIO::sendSecureHwpRequest(i_target, l_bufferPtr, l_sizeOfArgInBytes, i_hwpName);

    return l_errl;
}


//Macros that return the 1st argument
#define _GET_1ST_ARG(N, ...) N

/**
 * @brief Subroutine Executor macro example code - Platforms will need to
 *        implement as needed for their enviroment.
 *
 * This macro calls a PLAT macro which will do any platform specific work to
 * execute the Subroutine (e.g. dlopening a shared library)
 */
#define FAPI_PLAT_CALL_SUBROUTINE(RC, FUNC, _args...) \
{ \
    do \
    { \
        errlHndl_t l_errl = nullptr; \
        /* Read the FUNC as a string and pass it to the conversion method \
        to determine what hwp we need to request */ \
        const char* l_function = #FUNC; \
        /*Read the target argument, which is the first argument in the list */ \
        TARGETING::Target* l_target = \
        reinterpret_cast<TARGETING::Target*>(_GET_1ST_ARG(_args).get()); \
        /*Check if secureboot is enabled and if the target exists on the master proc*/ \
        bool isSecure = SECUREBOOT::enabled(); \
        bool isMaster = false; \
        l_errl = isOnMasterProc(l_target, isMaster); \
        if(l_errl) \
        { \
            FAPI_INF("subroutine_executor: Failed trying to determine is target was on master chip"); \
            RC.setPlatDataPtr(reinterpret_cast<void *> (l_errl)); \
            break; \
        } \
        /*Run hwp on host if targ is on master, we are not in securemode*/ \
        if(isMaster || !isSecure) \
        { \
            FAPI_INF("subroutine_executor: isSecure = %d   isMaster = %d .. executing hwp %s on host", \
                      isSecure, isMaster, l_function); \
            RC = FUNC(_args); \
        } \
        /*Otherwise request the HWP via chipop to the SBE*/ \
        else \
        { \
            FAPI_INF("subroutine_executor: isSecure = %d   isMaster = %d .. executing hwp %s on host", \
                    isSecure, isMaster, l_function); \
            l_errl =  requestHwpViaSbe(l_function, l_target, _args); \
            /*For now until SBE support comes fallback to running on host if chipop fails*/ \
            if(l_errl) \
            { \
                /*Commit the error as informational and attempt hwp */ \
                l_errl->setSev(ERRORLOG::ERRL_SEV_INFORMATIONAL); \
                errlCommit(l_errl, SBEIO_COMP_ID); \
                RC = FUNC(_args);\
            } \
        } \
    } while(0); \
}

#endif