/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/hwpf/hwp/erepairAccessorHwpFuncs.H $          */
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
 *  @file erepairAccessorHwpFuncs.H
 *
 *  @brief FW Team Utility functions that accesses fabric and memory eRepair
 *  data.
 */

/*
 * Change Log ******************************************************************
 * Flag     Defect/Feature  User        Date        Description
 * ------   --------------  ----------  ----------- ----------------------------
 *                          bilicon     10/24/2012  Created.
 */

#ifndef EREPAIRACCESSORHWPFUNCS_H_
#define EREPAIRACCESSORHWPFUNCS_H_

#include <fapi.H>

// VPD Type to read-write
enum erepairVpdType
{
    EREPAIR_VPD_UNKNOWN = 0,
    EREPAIR_VPD_MNFG    = 1,
    EREPAIR_VPD_FIELD   = 2,
};

const uint8_t EREPAIR_MAX_CENTAUR_PER_MCS = 1;

typedef fapi::ReturnCode (*getLanes_t)(
                          const fapi::Target   &i_tgtHandle,
                          std::vector<uint8_t> &o_txFailLanes,
                          std::vector<uint8_t> &o_rxFailLanes);

typedef fapi::ReturnCode (*setLanes_t)(
                          const fapi::Target         &i_tgtHandle,
                          const std::vector<uint8_t> &i_txFailLanes,
                          const std::vector<uint8_t> &i_rxFailLanes);

/**
 * @brief FW Team Utility function that gets eRepair data from the VPD
 *
 * @param[in]   i_endp_target Reference to X-Bus or A-Bus or MCS Target
 * @param[out]  o_txFailLanes Reference to a Vector that will contain the fail
 *                            lanes read from the VPD for Drive side
 * @param[out]  o_rxFailLanes Reference to a Vector that will contain the fail
 *                            lanes read from the VPD for Receive side
 * @return ReturnCode
 *
 * TODO: i_endp_target        There will be future support for Centaur Target.
 *                            RTC Task 51234. Depends on RTC Story 44009
 */
fapi::ReturnCode erepairGetFailedLanes(const fapi::Target &i_endp_target,
                                       std::vector<uint8_t> &o_txFailLanes,
                                       std::vector<uint8_t> &o_rxFailLanes);

/**
 * @brief FW Team Utility function that gets eRepair data
 *
 * This is a wrapper function for the Accessor HWP which reads failed lane
 * numbers from the Field VPD
 *
 * @param[in]   i_endp_target Reference to X-Bus or A-Bus or MCS Target
 * @param[out]  o_txFailLanes Reference to a Vector that will contain the fail
 *                            lanes read from the Field VPD for Drive side
 * @param[out]  o_rxFailLanes Reference to a Vector that will contain the fail
 *                            lanes read from the Field VPD for Receive side
 * @return ReturnCode
 *
 * TODO: i_endp_target        There will be future support for Centaur Target.
 *                            RTC Task 51234. Depends on RTC Story 44009
 */
fapi::ReturnCode erepairGetFieldFailedLanes(const fapi::Target &i_endp_target,
                                            std::vector<uint8_t> &o_txFailLanes,
                                            std::vector<uint8_t> &o_rxFailLanes);

/**
 * @brief FW Team Utility function that gets eRepair data
 *
 * This is a wrapper function for the Accessor HWP which reads failed lane
 * numbers from the Manufacturing VPD
 *
 * @param[in]   i_endp_target Reference to X-Bus or A-Bus or MCS Target
 * @param[out]  o_txFailLanes Reference to a Vector that will contain the fail
 *                            lanes read from the Mnfg VPD for Drive side
 * @param[out]  o_rxFailLanes Reference to a Vector that will contain the fail
 *                            lanes read from the Mnfg VPD for Receive side
 * @return ReturnCode
 *
 * TODO: i_endp_target        There will be future support for Centaur Target.
 *                            RTC Task 51234. Depends on RTC Story 44009
 */
fapi::ReturnCode erepairGetMnfgFailedLanes(const fapi::Target &i_endp_target,
                                           std::vector<uint8_t> &o_txFailLanes,
                                           std::vector<uint8_t> &o_rxFailLanes);

/**
 * @brief FW Team Utility function that sets eRepair data in the VPD
 *
 * @param[in]   i_endp_target Reference to X-Bus or A-Bus or MCS Target
 * @param[in]   i_txFailLanes Vector that will contain the fail lane
 *                            to be written to VPD for Drive side
 * @param[in]   i_rxFailLanes Vector that will contain the fail lanes
 *                            to be written to VPD for Receive side
 *
 * @return ReturnCode
 */
fapi::ReturnCode erepairSetFailedLanes(
                                     const fapi::Target &i_endp_target,
                                     const std::vector<uint8_t> &i_txFailLanes,
                                     const std::vector<uint8_t> &i_rxFailLanes);

/**
 * @brief FW Team Utility function that sets eRepair data in Field VPD
 *
 * This is a wrapper function for the Accessor HWP which write failed lane
 * numbers in the Field VPD
 *
 * @param[in]   i_endp_target Reference to X-Bus or A-Bus or MCS Target
 * @param[in]   i_txFailLanes Vector that will contain the fail lane
 *                            to be written to Field VPD for Drive side
 * @param[in]   i_rxFailLanes Vector that will contain the fail lanes
 *                            to be written to Field VPD for Receive side
 *
 * @return ReturnCode
 */
fapi::ReturnCode erepairSetFieldFailedLanes(
                                     const fapi::Target &i_endp_target,
                                     const std::vector<uint8_t> &i_txFailLanes,
                                     const std::vector<uint8_t> &i_rxFailLanes);

/**
 * @brief FW Team Utility function that sets eRepair data in Manufacturing VPD
 *
 * This is a wrapper function for the Accessor HWP which write failed lane
 * numbers in the Manufacturing VPD
 *
 * @param[in]   i_endp_target Reference to X-Bus or A-Bus or MCS Target
 * @param[in]   i_txFailLanes Vector that will contain the fail lane
 *                            to be written to Mnfg VPD for Drive side
 * @param[in]   i_rxFailLanes Vector that will contain the fail lanes
 *                            to be written to Mnfg VPD for Receive side
 *
 * @return ReturnCode
 */
fapi::ReturnCode erepairSetMnfgFailedLanes(
                                      const fapi::Target &i_endp_target,
                                      const std::vector<uint8_t> &i_txFailLanes,
                                      const std::vector<uint8_t> &i_rxFailLanes);

/**
 * @brief Function which retrieves the lanes that need to be restored for the
 *        given end point targets
 *
 * This function is called by the iStep dispatcher during the Restore Repair
 * iStep for Fabric buses and DMI buses. The caller need to make sure that the
 * first two arguments of this function need to be end point targets of a
 * Fabric bus or DMI bus.
 * It calls the wrapper functions of Accessor HWP to read the fail lane data
 * recorded in the VPD on both the ends and verifies that there are matching
 * records on both the ends. If matching fail lanes are not found, the
 * corresponding fail lane data is invalidated using the wrapper Accessor HWP
 * that writes data to the VPD.
 *
 * @param [in]   i_endp1_target      Reference to X-Bus or A-Bus or MCS Target
 * @param [out]  o_endp1_txFaillanes Reference to vector that will have the
 *                                   fail lane numbers that need to be restored
 *                                   for the Tx side of the target passed
 *                                   as first param
 * @param [out]  o_endp1_rxFaillanes Reference to vector that will have the
 *                                   fail lane numbers that need to be restored
 *                                   for the Rx side of the target passed
 *                                   as first param
 * @param [in]   i_endp2_target      Reference to X-Bus or A-Bus or MCS Target
 * @param [out]  o_endp2_txFaillanes Reference to vector that will have the
 *                                   fail lane numbers that need to be restored
 *                                   for the Tx side of the target passed
 *                                   as fourth param
 * @param [out]  o_endp2_rxFaillanes Reference to vector that will have the
 *                                   fail lane numbers that need to be restored
 *                                   for the Rx side of the target passed
 *                                   as fourth param
 *
 * @return ReturnCode
 *
 */

fapi::ReturnCode erepairGetRestoreLanes(const fapi::Target &i_endp1_target,
                                     std::vector<uint8_t> &o_endp1_txFaillanes,
                                     std::vector<uint8_t> &o_endp1_rxFaillanes,
                                     const fapi::Target   &i_endp2_target,
                                     std::vector<uint8_t> &o_endp2_txFaillanes,
                                     std::vector<uint8_t> &o_endp2_rxFaillanes);

#endif
