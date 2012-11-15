/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/prdfTOD.H $                     */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2010,2012              */
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

#ifndef PRDFTOD_H
#define PRDFTOD_H


/** @struct PrdfTodFaultData
 *  TOD Fault isolation information from a chip.
 */
struct PrdfTodFaultData
{
    TARGETING::TargetHandle_t source_chipHandle;
    bool phyp_fault;
    bool topo_fault[2];                  // 0 is active, 1 is backup
    bool topo_fault_clock[2];
    TARGETING::TargetHandle_t topo_fault_chip[2];
};

int32_t prdfTorrent_TodCaptureRegisters(STEP_CODE_DATA_STRUCT & i_stepcode);
int32_t prdfTorrent_TodCleanUpErrors(STEP_CODE_DATA_STRUCT & i_stepcode);
int32_t prdfTorrent_TodCollectFaultDataSys(vector<PrdfTodFaultData> & o_faults,
                                      STEP_CODE_DATA_STRUCT & i_stepcode);
int32_t prdfTorrent_TodCollectFaultDataChip(PrdfExtensibleChip * i_chip,
                                       vector<PrdfTodFaultData> & o_faults,
                                       STEP_CODE_DATA_STRUCT & i_stepcode);


int32_t prdfP7_TodCaptureRegisters(STEP_CODE_DATA_STRUCT & i_stepcode);
int32_t prdfP7_TodCleanUpErrors(STEP_CODE_DATA_STRUCT & i_stepcode);
int32_t prdfP7_TodCollectFaultDataSys(vector<PrdfTodFaultData> & o_faults,
                                      STEP_CODE_DATA_STRUCT & i_stepcode);
int32_t prdfP7_TodCollectFaultDataChip(PrdfExtensibleChip * i_chip,
                                       vector<PrdfTodFaultData> & o_faults,
                                       STEP_CODE_DATA_STRUCT & i_stepcode);

#endif //PRDFTOD_H
