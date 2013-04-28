/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/tod_init/TodHwpIntf.H $                      */
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
#ifndef TODHWPINTF_H
#define TODHWPINTF_H

/**
 *  @file TodHwpIntf.H
 *
 *  @brief TOD Hardware Procedure interfaces
 *
 *  HWP_IGNORE_VERSION_CHECK
 *
 */

#include <errl/errlentry.H>
#include "proc_tod_utils.H"

namespace TOD
{

/**
 *  @brief Invokes the TOD setup hardware procedure
 *
 *  @par Detailed Description:
 *      We pass in the TOD topology to the HWP. The HWP traverses the
 *      the topology and writes various TOD registers with TOD specific
 *      information. It also computes TOD delays and writes appropriate regs.
 *
 *  @param[in] i_topologyType
 *      Topology type : primary/secondary
 *
 *  @return Error log handle indicating the status of the request
 *  @retval NULL  HWP executed succesfully
 *  @retval !NULL HWP failure
 *
 *     Error log handle points to a valid error log object whose primary
 *     SRC reason code (pError->getSRC()->reasonCode()) indicates the type
 *     of error.
 *
 *  @note It is up to the caller to change the severity of the
 *      returned error based on what it decides to do with it. By default
 *      any returned error created by this function will be a non-reported
 *      tracing event error log.
 */
errlHndl_t todSetupHwp(const proc_tod_setup_tod_sel i_topologyType);

/**
 *  @brief Invokes the TOD registry read HWP.
 *
 *  @par Detailed Description:
 *      We pass in the TOD topology to the HWP. The HWP traverses the
 *      topology and fills up, for each TOD proc datastructure, an output
 *      field which corresponds to the TOD registers for that proc. The HWP
 *      gets the register content by scomming the register.
 *      Check proc_tod_utils.H : proc_tod_setup_conf_regs for the list of regs.
 *
 *  @param[in] i_topologyType
 *      Topology type : primary/secondary
 *
 *  @return Error log handle indicating the status of the request
 *  @retval NULL  HWP executed succesfully
 *  @retval !NULL HWP failure
 *
 *     Error log handle points to a valid error log object whose primary
 *     SRC reason code (pError->getSRC()->reasonCode()) indicates the type
 *     of error.
 *
 *  @note It is up to the caller to change the severity of the
 *      returned error based on what it decides to do with it. By default
 *      any returned error created by this function will be a non-reported
 *      tracing event error log.
 */
errlHndl_t todSaveRegsHwp(const proc_tod_setup_tod_sel i_topologyType);

/**
 *  @brief Invokes the TOD init HWP.
 *
 *  @param[in] i_topologyType
 *      Topology type : primary/secondary
 *
 *  @return Error log handle indicating the status of the request
 *  @retval NULL  HWP executed succesfully
 *  @retval !NULL HWP failure
 *
 *     Error log handle points to a valid error log object whose primary
 *     SRC reason code (pError->getSRC()->reasonCode()) indicates the type
 *     of error.
 *
 *  @note It is up to the caller to change the severity of the
 *      returned error based on what it decides to do with it. By default
 *      any returned error created by this function will be a non-reported
 *      tracing event error log.
 */
errlHndl_t todInitHwp(const proc_tod_setup_tod_sel i_topologyType);

} //namespace TOD

#endif //TODHWPINTF_H
