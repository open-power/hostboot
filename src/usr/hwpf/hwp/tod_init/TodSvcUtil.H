/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/tod_init/TodSvcUtil.H $                      */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013                   */
/*                                                                        */
/* p1                                                                     */
/*                                                                        */
/* Object Code Only (OCO) source materials                                */
/* Licensed Internal Code Source Materials                                */
/* IBM HostBoot Licensed Internal Code                                    */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* Origin: 30                                                             */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */

/**
 *  @file TodSvcUtil.H
 *
 *  @brief This file declares the various utility methods
 *
 *  HWP_IGNORE_VERSION_CHECK
 *
 */

#ifndef TODSVCUTIL_H
#define TODSVCUTIL_H

#include <errl/errlentry.H>
#include <ecmddatabuffer/ecmdDataBufferBase.H>

namespace TOD
{
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
     *      hwsvTodChipData structures that will be written in the file
     *      shared between HWSV and HDAT.
     *      Each hwsvTodChipData structure contains TOD chip register data
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
     *
     * @brief This method finds out the maximum number of cores that is
     *      possible per proc for fully configured system of this type
     *
     * @return Count of cores
     *      The method should succeed always
     */
     uint32_t  getMaxPossibleCoresPerProc();

    /**
     * @brief This method read the scom register
     *
     * @param[in] i_target  : target object
     * @param[in] i_address : SCOM register address
     *
     * @param[out] o_data   : content of the register if no error
     *
     * @return errlHndl_t   : NULL if ok. Otherwise, there is an error
     */
     errlHndl_t todGetScom(const TARGETING::Target * i_target,
                           const uint64_t i_address,
                           ecmdDataBufferBase & o_data);

    /**
     *
     * @brief This method will get the list of functional node target
     *      pointers for the supplied target that can be a node or system
     *      type.
     *
     * @par Detailed Description:
     *      If the input target is a system level target then target
     *      pointers for all the functional nodes in system will be
     *      collected.
     *      If the target sent is of node type then the method will simply
     *      push back the target that has been passed as argument, provided
     *      it is functional
     *
     * @param[in] i_pInputTarget
     *       Target sent as input to this method
     *
     * @param[out] o_functionalNodeTargetList
     *       List of functional node targets collected by the method
     * @return Error log handle to carry back status of request
     * @retval !NULL Indicates an error in collecting the node target.This
     *       can  happen if input target is neither of system/node
     *       type. In error case o_functionalNodeTargetList will be empty.
     * @retval NULL Indicates that there was no error in getting the targets.
     */
     errlHndl_t getFuncNodeTargetsOnSystem(const TARGETING::Target * i_target,
                     TARGETING::TargetHandleList& o_functionalNodeTargetList);

} //End of namespace TOD

#endif
