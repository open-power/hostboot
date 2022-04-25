/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/errl/errludcallout.C $                                */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2022                        */
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
/**
 *  @file errludcallout.C
 *
 *  @brief Implementation of ErrlUserDetailsCallout
 */
#include <sys/task.h>
#include <errl/errludcallout.H>
#include <errl/errlreasoncodes.H>
#include <targeting/common/targetservice.H>
#include <targeting/common/util.H>
#include <targeting/common/trace.H>
#include <util/crc32.H>

namespace ERRORLOG
{

extern TARGETING::TARG_TD_t g_trac_errl;

//------------------------------------------------------------------------------
// Clock callout
ErrlUserDetailsCallout::ErrlUserDetailsCallout(
        const void *i_pTargetData,
        uint32_t i_targetDataLength,
        const HWAS::clockTypeEnum i_clockType,
        const HWAS::callOutPriority i_priority,
        const HWAS::DeconfigEnum i_deconfigState,
        const HWAS::GARD_ErrorType i_gardErrorType)
{
    TRACDCOMP(g_trac_errl, "ClockCallout entry");

    // Set up ErrlUserDetails instance variables
    iv_CompId = ERRL_COMP_ID;
    iv_Version = ERRL_UDT_CALLOUT_BASE_VER;
    iv_SubSection = ERRL_UDT_CALLOUT;

    uint32_t pDataLength = sizeof(HWAS::callout_ud_t) + i_targetDataLength;
    HWAS::callout_ud_t *pData;
    pData = reinterpret_cast<HWAS::callout_ud_t *>
                (reallocUsrBuf(pDataLength));
    pData->type = HWAS::CLOCK_CALLOUT;
    pData->flag = HWAS::FLAG_NONE;
    pData->clockType = i_clockType;
    pData->priority = i_priority;
    pData->clkDeconfigState = i_deconfigState;
    pData->clkGardErrorType = i_gardErrorType;
    memcpy(pData + 1, i_pTargetData, i_targetDataLength);

    iv_UDCalloutHash = Util::crc32_calc(pData, pDataLength);

    TRACDCOMP(g_trac_errl, "ClockCallout exit; pDataLength %d", pDataLength);

} // Clock callout

//------------------------------------------------------------------------------
// VRM callout
/*
ErrlUserDetailsCallout::ErrlUserDetailsCallout(
        const voltage_type i_vrmType,
        const void *i_pTargetData,
        uint32_t i_targetDataLength,
        const HWAS::partTypeEnum i_partType,
        const HWAS::callOutPriority i_priority,
        const HWAS::DeconfigEnum i_deconfigState,
        const HWAS::GARD_ErrorType i_gardErrorType)
{
    // TODO: add stuff
}*/

//------------------------------------------------------------------------------
// Part callout
ErrlUserDetailsCallout::ErrlUserDetailsCallout(
        const void *i_pTargetData,
        uint32_t i_targetDataLength,
        const HWAS::partTypeEnum i_partType,
        const HWAS::callOutPriority i_priority,
        const HWAS::DeconfigEnum i_deconfigState,
        const HWAS::GARD_ErrorType i_gardErrorType)
{
    TRACDCOMP(g_trac_errl, "PartCallout entry");

    // Set up ErrlUserDetails instance variables
    iv_CompId = ERRL_COMP_ID;
    iv_Version = ERRL_UDT_CALLOUT_BASE_VER;
    iv_SubSection = ERRL_UDT_CALLOUT;

    uint32_t pDataLength = sizeof(HWAS::callout_ud_t) + i_targetDataLength;
    HWAS::callout_ud_t *pData;
    pData = reinterpret_cast<HWAS::callout_ud_t *>
                (reallocUsrBuf(pDataLength));
    pData->type = HWAS::PART_CALLOUT;
    pData->flag = HWAS::FLAG_NONE;
    pData->partType = i_partType;
    pData->priority = i_priority;
    pData->partDeconfigState = i_deconfigState;
    pData->partGardErrorType = i_gardErrorType;
    memcpy(pData + 1, i_pTargetData, i_targetDataLength);

    iv_UDCalloutHash = Util::crc32_calc(pData, pDataLength);

    TRACDCOMP(g_trac_errl, "PartCallout exit; pDataLength %d", pDataLength);

} // Part callout


//------------------------------------------------------------------------------
// Bus callout
ErrlUserDetailsCallout::ErrlUserDetailsCallout(
        const void *i_pTarget1Data,
        uint32_t i_target1DataLength,
        const void *i_pTarget2Data,
        uint32_t i_target2DataLength,
        const HWAS::busTypeEnum i_busType,
        const HWAS::callOutPriority i_priority,
        const HWAS::CalloutFlag_t i_flag)
{
    TRACDCOMP(g_trac_errl, "BusCallout entry");

    // Set up ErrlUserDetails instance variables
    iv_CompId = ERRL_COMP_ID;
    iv_Version = ERRL_UDT_CALLOUT_BASE_VER;
    iv_SubSection = ERRL_UDT_CALLOUT;

    uint32_t pDataLength = sizeof(HWAS::callout_ud_t) +
                           i_target1DataLength + i_target2DataLength;
    HWAS::callout_ud_t *pData;
    pData = reinterpret_cast<HWAS::callout_ud_t *>
                (reallocUsrBuf(pDataLength));
    pData->type = HWAS::BUS_CALLOUT;
    pData->flag = i_flag;
    pData->busType = i_busType;
    pData->priority = i_priority;
    char * l_ptr = (char *)(++pData);
    memcpy(l_ptr, i_pTarget1Data, i_target1DataLength);
    memcpy(l_ptr + i_target1DataLength, i_pTarget2Data, i_target2DataLength);

    iv_UDCalloutHash = Util::crc32_calc(pData, pDataLength);

    TRACDCOMP(g_trac_errl, "BusCallout exit; pDataLength %d", pDataLength);

} // Bus callout

//------------------------------------------------------------------------------
// Hardware callout
ErrlUserDetailsCallout::ErrlUserDetailsCallout(
        const void *i_pTargetData,
        uint32_t i_targetDataLength,
        const HWAS::callOutPriority i_priority,
        const HWAS::DeconfigEnum i_deconfigState,
        const HWAS::GARD_ErrorType i_gardErrorType)
{
    TRACDCOMP(g_trac_errl, "HWCallout entry");

    // Set up ErrlUserDetails instance variables
    iv_CompId = ERRL_COMP_ID;
    iv_Version = ERRL_UDT_CALLOUT_BASE_VER;
    iv_SubSection = ERRL_UDT_CALLOUT;

    //iv_merge = false; // use the default of false

    uint32_t pDataLength = sizeof(HWAS::callout_ud_t) + i_targetDataLength;
    HWAS::callout_ud_t *pData;
    pData = reinterpret_cast<HWAS::callout_ud_t *>
                (reallocUsrBuf(pDataLength));
    pData->type = HWAS::HW_CALLOUT;
    pData->flag = HWAS::FLAG_NONE;
    pData->priority = i_priority;
#ifndef __HOSTBOOT_RUNTIME
    pData->cpuid = task_getcpuid();
#else
    pData->cpuid = (uint32_t)(-1);
#endif
    pData->deconfigState = i_deconfigState;
    pData->gardErrorType = i_gardErrorType;
    memcpy(pData + 1, i_pTargetData, i_targetDataLength);

    iv_UDCalloutHash = Util::crc32_calc(pData, pDataLength);

    TRACDCOMP(g_trac_errl, "HWCallout exit; pDataLength %d", pDataLength);

} // Hardware callout


//------------------------------------------------------------------------------
// Procedure callout
ErrlUserDetailsCallout::ErrlUserDetailsCallout(
        const HWAS::epubProcedureID i_procedure,
        const HWAS::callOutPriority i_priority)
{
    TRACDCOMP(g_trac_errl, "Procedure Callout");

    // Set up ErrlUserDetails instance variables
    iv_CompId = ERRL_COMP_ID;
    iv_Version = ERRL_UDT_CALLOUT_BASE_VER;
    iv_SubSection = ERRL_UDT_CALLOUT;

    //iv_merge = false; // use the default of false

    HWAS::callout_ud_t *pData;
    pData = reinterpret_cast<HWAS::callout_ud_t *>
                (reallocUsrBuf(sizeof(HWAS::callout_ud_t)));

    pData->type = HWAS::PROCEDURE_CALLOUT;
    pData->flag = HWAS::FLAG_NONE;
    pData->procedure = i_procedure;
    pData->priority = i_priority;

    iv_UDCalloutHash = Util::crc32_calc(pData, sizeof(HWAS::callout_ud_t));

    TRACDCOMP(g_trac_errl, "Procedure Callout exit");

} // Procedure callout

//------------------------------------------------------------------------------
// Sensor callout
ErrlUserDetailsCallout::ErrlUserDetailsCallout(const uint32_t i_sensorID,
                                        const HWAS::sensorTypeEnum i_sensorType,
                                        const HWAS::callOutPriority i_priority)
{
    TRACDCOMP(g_trac_errl, "Sensor Callout");

    // Set up ErrlUserDetails instance variables
    iv_CompId = ERRL_COMP_ID;
    iv_Version = ERRL_UDT_CALLOUT_BASE_VER;
    iv_SubSection = ERRL_UDT_CALLOUT;

    HWAS::callout_ud_t *pData;
    pData = reinterpret_cast<HWAS::callout_ud_t *>
                (reallocUsrBuf(sizeof(HWAS::callout_ud_t)));

    pData->type = HWAS::SENSOR_CALLOUT;
    pData->flag = HWAS::FLAG_NONE;
    pData->priority = i_priority;
    pData->sensorId = i_sensorID;
    pData->sensorType = i_sensorType;

    iv_UDCalloutHash = Util::crc32_calc(pData, sizeof(HWAS::callout_ud_t));

    TRACDCOMP(g_trac_errl, "Sensor Callout exit");
} // Sensor callout

//------------------------------------------------------------------------------
// I2c Device Callout
ErrlUserDetailsCallout::ErrlUserDetailsCallout(
                        const void *i_pTargData,
                        const uint32_t i_targDataLen,
                        const uint8_t i_engine,
                        const uint8_t i_port,
                        const uint8_t i_address,
                        const HWAS::callOutPriority i_priority)
{
    TRACDCOMP(g_trac_errl, "I2c Device Callout");

    assert(i_pTargData != nullptr, "Bug! I2c Device Callout added with null i2c master target");

    // Set up ErrUserDetails instance variables
    iv_CompId = ERRL_COMP_ID;
    iv_Version = ERRL_UDT_CALLOUT_BASE_VER;
    iv_SubSection = ERRL_UDT_CALLOUT;

    uint32_t pDataLength = sizeof(HWAS::callout_ud_t) + i_targDataLen;
    HWAS::callout_ud_t *pData = reinterpret_cast<HWAS::callout_ud_t *>
                                                   (reallocUsrBuf(pDataLength));

    pData->type = HWAS::I2C_DEVICE_CALLOUT;
    pData->flag = HWAS::FLAG_NONE;
    pData->engine = i_engine;
    pData->port = i_port;
    pData->address = i_address;
    pData->priority = i_priority;

    memcpy(pData + 1, i_pTargData, i_targDataLen);

    iv_UDCalloutHash = Util::crc32_calc(pData, pDataLength);

    TRACDCOMP(g_trac_errl, "I2c Device Callout exit");
} // I2c Device Callout

uint32_t ErrlUserDetailsCallout::getUDCalloutHash() const
{
    return iv_UDCalloutHash;
}

} // namespace ERRORRLOG

