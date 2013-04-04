/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/hwpf/hwp/erepairSetMnfgFailedLanesHwp.H $     */
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
/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/**
 *  @file erepairSetMnfgFailedLanesHwp.H
 *
 *  @brief FW Team HWP that accesses the fail lanes of Fabric and Memory buses.
 */

/*
 * Change Log ******************************************************************
 * Flag     Defect/Feature  User        Date        Description
 * ------   --------------  ----------  ----------- ----------------------------
 *                          bilicon     10-Jan-2013 Created.
 */

#ifndef EREPAIRSETMNFGFAILEDLANESHWP_H_
#define EREPAIRSETMNFGFAILEDLANESHWP_H_

#include <fapi.H>
#include <erepairConsts.H>


typedef fapi::ReturnCode (*erepairSetMnfgFailedLanesHwp_FP_t)(
                          const fapi::Target   &i_tgtHandle,
                          std::vector<uint8_t> &i_txFailLanes,
                          std::vector<uint8_t> &i_rxFailLanes);

extern "C"
{

/**
 * @brief FW Team HWP that writes the eRepair fail lanes to the Mnfg VPD.
 *        The fail lanes will be written to either the P8 MVPD or the
 *        Centaur FRU VPD depending on the passed target type.
 *
 * @param[in] i_tgtHandle   Reference to X-Bus or A-Bus or MCS or memBuf Target
 * @param[in] i_txFailLanes Reference to a vector that has the Tx side
 *                          (of i_tgtHandle) fail lane numbers that need
 *                          to be written to the VPD
 * @param[in] i_rxFailLanes Reference to a vector that has the Rx side
 *                          (of i_tgtHandle) fail lane numbers that need
 *                          to be written to the VPD
 *
 * @return ReturnCode
 */

fapi::ReturnCode erepairSetMnfgFailedLanesHwp(
                                     const fapi::Target         &i_tgtHandle,
                                     const std::vector<uint8_t> &i_txFailLanes,
                                     const std::vector<uint8_t> &i_rxFailLanes);

}// end of extern C

#endif
