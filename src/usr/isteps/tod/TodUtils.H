/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/tod/TodUtils.H $                               */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2010,2019                        */
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
#ifndef __TOD_HOSTBOOT_H
#define __TOD_HOSTBOOT_H


#include <attributeenums.H>
#include <errl/errlentry.H>
#include <fapi2.H>
#include "TodTrace.H"
#include <util/utilmem.H>

//moved from mboxclientlib.H
/** @enum mboxTodTopologyAction
 *        Values used to determine whether to enable, disable or switch TOD
 *        topologies.
 */
enum mboxTodTopologyAction
{
    MBOX_DISABLE_TOPOLOGY        = 0,
    MBOX_ENABLE_TOPOLOGY         = 1,
    MBOX_SWITCH_TOPOLOGY         = 99
};  // end mboxTodTopologyAction

/** @enum mboxTopologyValue
 *        Values used to determine whether to enable, disable or switch TOD
 *        topologies.
 */
enum mboxTopologyValue
{
    MBOX_PRIMARY_TOPOLOGY        = 0,
    MBOX_SECONDARY_TOPOLOGY      = 1
};  // end mboxTopologyValue

/**
 * Retrieve the CLASS of the target, or return NA if the target is NULL
 */
#define GETCLASS(pTarget) (((pTarget) == nullptr) ? (TARGETING::CLASS_NA) : \
        ((pTarget)->getAttr<TARGETING::ATTR_CLASS>()))

/**
 *  * Retrieve the TYPE of the target, or return NA if the target is NULL
 *   */
#define GETTYPE(pTarget) (((pTarget) == nullptr) ? (TARGETING::TYPE_NA) : \
        ((pTarget)->getAttr<TARGETING::ATTR_TYPE>()))


namespace TOD
{

struct maxConfigParams
{
    uint8_t max_procchips_per_node; // This will contain the maximum proc
                                    // chips per Node available on the system
    uint8_t max_compute_nodes_per_sys; // This will contain max compute
                                       // nodes present in the system

    /**
    * @brief Copies the data from maxConfigParams structure into the buffer
    * @par  Detailed Description
    * Copies the data from maxConfigParams structure into the buffer
    *
    * @param[out] o_utilBuf
    * Output buffer in which the data from the structure will be copied
    * This buffer will be cleared and data will be written from beginning of
    * the stream. After the data is updated ,the buffer pointer will be
    * pointing to the end of the inserted data
    *
    * @return Error log handle indicating the status of the request
    *
    * @retval NULL  Successfully copied the data from maxConfigParams structure
    *                into the buffer
    * @retval !NULL Failed to copy the data from maxConfigParams structure
    *               into the buffer
    *
    * Error log handle points to a valid error log object whose
    * primary SRC reason code (pError->getSRC()->reasonCode()) indicates
    * the type of error.
    *
    *  @note It is up to the caller to change the severity of the
    *      returned error based on what it decides to do with it. By
    *      default any returned error created by this function will be a
    *      non-reported tracing event error log.
    *
    */

    errlHndl_t flatten(UtilMem& o_utilBuf )const ;


    /**
    * @brief Copies the data from the input buffer to the maxConfigParams
    * structure
    * @par  Detailed Description
    * Copies the data from the input buffer to the maxConfigParams
    * structure
    *
    * @param[in] i_utilBuf
    * Input buffer from  which the data will be copied to the structure
    * @note Input buffer must contain only the maxConfigParams info and
    * the buffer pointer must be pointing to index 0 of the buffer.
    * The call will not alter any error in the existing input stream
    *
    * @return Error log handle indicating the status of the request
    *
    * @retval NULL  Successfully copied the data from buffer into the
    *               maxConfigParams structure
    * @retval !NULL Failed to copy the data from buffer into the
    *               maxConfigParams structure
    *
    * Error log handle points to a valid error log object whose
    * primary SRC reason code (pError->getSRC()->reasonCode()) indicates
    * the type of error.
    *
    *  @note It is up to the caller to change the severity of the
    *      returned error based on what it decides to do with it. By
    *      default any returned error created by this function will be a
    *      non-reported tracing event error log.
    *
    *
    */

    errlHndl_t unflatten(const  UtilMem& i_utilBuf);


    /**
    * @brief Returns the Size of data which is held in the maxConfigParams
    * structure
    * @par  Detailed Description
    * Returns the size of data which is held in the maxConfigParams structure
    *
    *
    * @return
    * Returns the size of data which is held in the maxConfigParams structure
    */

    uint32_t flattenSize(void) const;
};

typedef maxConfigParams maxConfigParamsContainer;


errlHndl_t getMaxConfigParams(maxConfigParamsContainer& o_maxConfigParams);

#define GETHUID(pTarget) (((pTarget) == nullptr) ? (0) : \
        ((pTarget)->getAttr<TARGETING::ATTR_HUID>()))

//******************************************************************************
// isFunctional
//******************************************************************************

bool isFunctional(const TARGETING::Target* i_pTarget);


//moved from TodSvcUtil.C from open powervm p8
//******************************************************************************
// todGetScom
//******************************************************************************
errlHndl_t todGetScom(const TARGETING::Target * i_target,
                      const uint64_t i_address,
                      fapi2::variable_buffer & o_data);
}// end of namespace

#endif //end of .H file
