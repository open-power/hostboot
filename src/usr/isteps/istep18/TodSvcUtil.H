/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep18/TodSvcUtil.H $                         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2017                        */
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
#ifndef  TODSVCUTIL_H
#define  TODSVCUTIL_H

/**
 *  @file TodSvcUtil.H
 *
 *  @brief Provides definition of functions that are of common use across TOD
 *  todService
 */

//Targeting includes
#include <targeting/common/target.H>
#include <p9_tod_setup.H>
#include <string.h>
#include "TodUtils.H"

namespace TOD
{

typedef std::vector<TARGETING::ATTR_HUID_type>
        TodEndPointContainer;

namespace TodSvcUtil{

    /**
     * @brief  This method  should be called to do a callout on input TOD end
     *      point target on processor.
     *
     * @par Detailed Description:
     *      The method will do the followin
     *
     *      HW callout
     *              Target        |  Priority |  Deconfig | Gard
     *          TOD end point on
     *          Processor             High         Yes       Yes
     *
     *          Tod end point on
     *           OSC                  Low          Yes       Yes
     *
     *     Procedure callout
     *          EPUB_PRC_TOD_CLOCK_ERR  Low
     *
     * @param[in] i_pTodEndPoint, Input TOD end point target for calling out.
     *      point target connects.
     *
     * @param[inout] io_errHdl
     *      On input this parameter will be either NULL or pointing to
     *      an existing error handle.
     *      On output this parameter will either have a newly created handle
     *      assigned to it ( If input parameter was NULL ) or a new SRC will be
     *      appened to existing error handle ( If the input was not NULL )
     * @return NA
     */
    void  calloutTodEndPoint( const TARGETING::Target* i_pTodEndPoint,
            errlHndl_t& io_errHdl);

    /**
     * @brief  Method to create an errlHndl_t object for
     *      TOD_INVALID_CONFIG error
     *
     * @par Detailed Description:
     *      This will be logged if during the course of TOD operation an
     *      anomaly was found with the topology configuration or
     *      its related data.
     *
     * @param[in] i_config
     *      The problematic configuration Primary/Secondary
     *
     * @param[out] io_errHdl
     *      On input this parameter will be either NULL or pointing to
     *      an existing error handle.
     *      On output this parameter will either have a newly created handle
     *      assigned to it ( If input parameter was NULL ) or a new SRC will be
     *      appened to existing error handle ( If the input was not NULL )
     * @return NA
     */
    void logInvalidTodConfig(const uint32_t i_config,
            errlHndl_t& io_errHdl);

    /**
     * @brief Method to create an errlHndl_t object for
     *      TOD_UNSUPPORTED_ORDINALID
     *
     * @par Detailed Description:
     *      The ordinal Id's of TOD procs should fall within the range of 0
     *      <= Ordinal Id < getMaxProcsOnSystem.
     *      getMaxProcsOnSystem defines static count of the array of
     *      TodChipData structures that will be written in the file
     *      shared between TOD and HDAT.
     *      Each TodChipData structure contains TOD chip register data
     *      for a specific chip.
     *      This error will be logged if at any point of time because of
     *      changes in system configuration the no. of proc chips becomes
     *      equal to or more than getMaxProcsOnSystem, and corresponding
     *      support still does not exist in TOD code and HDAT
     *
     * @param[in] i_ordId
     *      The ordinal Id that was found to be unsupported
     *
     * @param[out] io_errHdl
     *      On input this parameter will be either NULL or pointing to
     *      an existing error handle.
     *      On output this parameter will either have a newly created handle
     *      assigned to it ( If input parameter was NULL ) or a new SRC will be
     *      appened to existing error handle ( If the input was not NULL )
     * @return NA
     *
     */
    void logUnsupportedOrdinalId(const uint32_t i_ordId,
            errlHndl_t& io_errHdl);

    /**
     *
     * @brief This method finds out the maximum number of proc chips that are
     *      possible on fully configured system of this type
     *
     * @return Count of procs
     *      The method should succeed always
     */
    uint32_t  getMaxProcsOnSystem();

    /**
     * @brief Return the topology type as string
     *
     * @param[in] i_topoloyType, The  topology type for which its string
     *      equivalent needs to be returned.
     *
     * @return String equivalent of the topology type passed as input.
     *      Method will assert if unsupported topology type is passed as input.
     */

     char const * topologyTypeToString (
            const p9_tod_setup_tod_sel i_topologyType);

    errlHndl_t getFuncNodeTargetsOnSystem(
            TARGETING::ConstTargetHandle_t i_nodeOrSysTarget,
            TARGETING::TargetHandleList& o_nodeList,
            const bool i_skipFuncCheck);

}//End of namespace TodSvcUtil

}//End of namespace TOD

#endif
