/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/hwpf/hwp/erepairFailLaneGetHwp.H $            */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012                   */
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
 *  @file erepairGetFailedLanesHwp.H
 *
 *  @brief FW Team HWP that accesses the fail lanes of Fabric and Memory buses.
 */

/*
 * Change Log ******************************************************************
 * Flag     Defect/Feature  User        Date        Description
 * ------   --------------  ----------  ----------- ----------------------------
 *                          bilicon     09/14/2012  Created.
 */

#ifndef EREPAIRGETFAILEDLANESHWP_H_
#define EREPAIRGETFAILEDLANESHWP_H_

#include <fapi.H>
#include <erepairConsts.H>

extern "C"
{

/**
 * @brief FW Team HWP that retrieves the eRepair fail lanes.
 *        It retrieves the eRepair data from the P8 MVPD and the Centaur FRU
 *        VPD. It then parses the eRepair data to determine the fail lane
 *        numbers on the sub-interfaces (Tx and Rx) of the passed bus target.
 *        Only Field eRepair data reading is currently supported.
 *        Manufacturing eRepair data reading is not supported yet.
 *
 * @param[in] i_tgtHandle   Reference to X-Bus or A-Bus or MCS or Target
 * @param[o]  o_txFailLanes Reference to a vector that will hold eRepair fail
 *                          lane numbers of the Tx sub-interface.
 * @param[o]  o_rxFailLanes Reference to a vector that will hold eRepair fail
 *                          lane numbers of the Rx sub-interface.
 *
 * @return ReturnCode
 *
 * TODO: i_tgtHandle        There will be future support for Centaur Target.
 *                          RTC Task 51234. Depends on RTC Story 44009
 */
fapi::ReturnCode erepairGetFailedLanesHwp(const fapi::Target   &i_tgtHandle,
                                          std::vector<uint8_t> &o_txFailLanes,
                                          std::vector<uint8_t> &o_rxFailLanes);

}// end of extern C

#endif
