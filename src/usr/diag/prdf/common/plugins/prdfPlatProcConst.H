/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plugins/prdfPlatProcConst.H $        */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015                             */
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

#ifndef __prdfPlatProcConst_H
#define __prdfPlatProcConst_H

/**
 * @file  prdfPlatProcConst.H
 * @brief Defines platform specific constants for the processor.
 */
namespace PRDF
{

namespace TOD
{

//NOTE: Position at which strings representing names of TOD control registers
//are placed in regStatList cannot be changed independently. Position of string
//in the array must match value of corresponding enum member e.g. value
//of MPCR is zero, therefore, TOD_MPCR can only be placed at regStatList[0]

// following enum represents all the tod control and status registers which
// need to be read and restored during data parity errors.

enum Register
{
    MPCR            = 0,
    PCRP0           = 1,
    PCRP1           = 2,
    SCRP0           = 3,
    SCRP1           = 4,
    SPCR            = 5,
    IPCR            = 6,
    PSMSCR          = 7,
    LAST_TOD_REG    = 8,
};

/**
 * @brief summarizes error analysis for a TOD topology.
 */
enum
{
    NO_TOD_ERROR                 = 0,
    MASTER_PATH_ERROR            = 1,
    INTERNAL_PATH_ERROR          = 2,
    SLAVE_PATH_NETWORK_ERROR     = 3,
    UNKNOWN_TOD_ERROR            = 4,
    LAST_TOD_ERROR               = 5,
};

/**
 * @brief TOD error analysis data to be added to special user section of e-log.
 */
struct TodErrorSummary
{
#if __BYTE_ORDER == __LITTLE_ENDIAN

    uint32_t reserved               :13;
    uint32_t backUpTopologyMastPath :2; //master path for backup topology
    uint32_t activeTopologyMastPath :2; // master path for active topology
    uint32_t backUpTopologySummary  :3; // backup topology error status
    uint32_t activeTopologySummary  :3; // active topology error status
    uint32_t todOscCnt              :4; // functional TOD OSC count in system
    uint32_t activeTopology         :1; // Topology acting as Active
    uint32_t topologyResetRequested :1; // topology reset request status
    uint32_t topologySwitchByPhyp   :1; // topology switch event detected
    uint32_t phypDetectedTodError   :1; // TOD error detected by Phyp
    uint32_t hardwareSwitchFlip     :1; // Master Path Failover by Hw

#else

    uint32_t hardwareSwitchFlip     :1; // Master Path Failover by Hw
    uint32_t phypDetectedTodError   :1; // TOD error detected by Phyp
    uint32_t topologySwitchByPhyp   :1; // topology switch event detected
    uint32_t topologyResetRequested :1; // topology reset request status
    uint32_t activeTopology         :1; // Topology acting as Active
    uint32_t todOscCnt              :4; // functional TOD OSC count in system
    uint32_t activeTopologySummary  :3; // active topology error status
    uint32_t backUpTopologySummary  :3; // backup topology error status
    uint32_t activeTopologyMastPath :2; // master path for active topology
    uint32_t backUpTopologyMastPath :2; //master path for backup topology
    uint32_t reserved               :13;

#endif
    uint32_t activeMdmt;       // HUID of active mdmt
    uint32_t backUpMdmt;       // HUID of backup MDMT

    TodErrorSummary():
        activeMdmt(0),
        backUpMdmt(0)
    {};

};


}//end namespace TOD

} // end namespace PRDF

#endif // __prdfPlatProcConst_H

