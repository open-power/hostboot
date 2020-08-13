/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hdat/hdatiplparms.H $                                 */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2020                        */
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

#ifndef HDATIPLPARMS_H
#define HDATIPLPARMS_H

/**
 *  @file hdatiplparms.H
 *
 *  @brief This file contains the class definition for the IPL parms object
 *         constructed with data obtained from the registry and iplp component.
 *
 */

// Change Log *****************************************************************/
//
// End Change Log *************************************************************/

/*----------------------------------------------------------------------------*/
/* Includes                                                                   */
/*----------------------------------------------------------------------------*/
#include <stdint.h>              // standard types
#include <errl/errlentry.H>
#include <hdat/hdat_reasoncodes.H>
#include "hdatutil.H"
#include <hdat/hdat.H>

namespace HDAT
{

/*----------------------------------------------------------------------------*/
/* Typedefs                                                                   */
/*----------------------------------------------------------------------------*/

const uint16_t HDAT_IPL_PARAMS_VERSION    = 0x71; // Second P9 version
const char HDAT_IPLP_STRUCT_NAME[7] = "IPLPMS";


/** @enum hdatDataPtrs
 *        Constants for the internal data pointers that are added to the base
 *        class
 */
enum hdatIplDataPtrs
{
  HDAT_IPL_SYS   = 0,
  HDAT_IPL_PARMS,
  HDAT_IPL_TIME, 
  HDAT_IPL_PVT, 
  HDAT_IPL_DUMP, 
  HDAT_IPL_HMC,
  HDAT_IPL_CUOD,
  HDAT_IPL_MANF,
  HDAT_IPL_PORT_CODES,
  HDAT_IPL_FEATURE_FLAGS,
  HDAT_IPL_LAST
};

/** @brief Structure definition for system model and feature code
 */
struct hdatSysParms_t
{
    uint32_t hdatSysModel;
    uint32_t hdatProcFeatCode;
    uint32_t hdatEffectivePvr;
    uint32_t hdatSysType;
    uint8_t  hdatReserved3[8];         // Reserved
    uint32_t hdatABCBusSpeed;          // Speed in MHz
    uint32_t hdatWXYZBusSpeed;         // Speed in MHz
    uint32_t hdatSystemECOMode;        // System ECO Mode set by the user
    uint32_t hdatSystemAttributes;     // System supports multiple TPMDs
    uint32_t hdatMemoryScrubbing;      // Memory Scrubbing
    uint16_t hdatCurrentSPPLValue;     // The Current SPPL Value
    uint8_t  hdatReserved2;            // Reserved
    uint8_t  usePoreSleep;             // Use PORE Sleep
    uint32_t hdatReserved1;            // Reserved
    uint8_t  vTpmEnabled;              // vTPM Enabled
    uint8_t  hdatHwPageTbl;            // Hardware Page Table
    uint16_t  hdatDispWheel;           // Hypervisor Dispatch Wheel
    uint32_t hdatNestFreq;             // Nest Clock Frequency in MHz
    uint8_t  hdatSplitCoreMode;        // Split Core Mode
    uint8_t  hdatReserved4;            // Reserved
    uint16_t hdatReserved5;            // Reserved
    uint8_t  hdatSystemVendorName[64]; // System Vendor Name
    uint16_t hdatSysSecuritySetting;   // System Security Settings
    uint16_t hdatTpmConfBits;          // TPM Configuration Bits
    uint16_t hdatTpmDrawer;            // TPMs/Drawer
    uint16_t hdatHwKeyHashSize;        // Size of HW Keys' Hash
    uint8_t  hdatHwKeyHashValue[64];   // Hardware Keys Hash Value
    char     hdatSystemFamily[64];     // System Family/Vendor Name
    char     hdatSystemType[64];       // System Type/Vendor Type
} __attribute__ ((packed));

/** @brief Structure definition for Other IPL Attributes within hdatIPLParams_t
 *  */
struct hdatOtherIPLAttributes_t
{
    uint32_t hdatReserved1 : 1;        // Reserved
    uint32_t hdatCreDefPartition : 1;  // Create Default Parititon
    uint32_t hdatCTAState : 1;         // Click To Accept State
    uint32_t hdatDisVirtIOConn : 1;    // Disable Virtual IO Connectivity
    uint32_t hdatResetPCINOs : 1;      // Reset PCI Numbers
    uint32_t hdatClrPhypNvram : 1;     // Clear PHYP NVRAM
    uint32_t hdatMDCLogPartVPD : 1;    // Preserve MDC Logical Paritition VPD
    uint32_t hdatCECCMCapable : 1;     // CEC Concurrent Maintanance Capable
    uint32_t hdati5OSEnable : 1;       // i5/OS enable
    uint32_t hdatSELFlagsValid : 1;    // SEL Flags Valid
    uint32_t hdatDelSELFromHyp : 1;    // Delete SELs originated from PHYP/OPAL
    uint32_t hdatDelSELFromHB : 1;     // Delete SELs originated from Hostboot
    uint32_t hdatDelSELFromBMC : 1;    // Delete SELs originated from BMC
    uint32_t hdatReserved2 : 15;       // Reserved
    uint32_t hdatServiceIndMode : 2;   // Platform Service Indicator Mode
    uint32_t hdatDefPartitionType : 2; // Default Partition Type
}__attribute__ ((packed));

/** @brief Structure definition for IPL Parameters
 *  */
struct hdatIPLParams_t
{
    uint8_t  hdatReserved1;            // Reserved
    uint8_t  hdatIPLDestination;       // Hypervisor IPL Destination
    uint8_t  hdatIPLSide;              // Platform IPL Side
    uint8_t  hdatIPLSpeed;             // Platform IPL Speed for Current IPL
    uint16_t hdatCECIPLAttributes;     // CEC IPL Attributes
    uint8_t  hdatIPLMajorType;         // CEC IPL Major Type
    uint8_t  hdatIPLMinorType;         // CEC IPL Minor Type
    uint8_t  hdatOSIPLMode;            // Operating System IPL Mode
    uint8_t  hdatKeyLockPosition;      // Key Lock Position
    uint8_t  hdatLMBSize;              // Logical Memory Block Size
    uint8_t  hdatReserved2;            // Reserved
    uint32_t hdatMaxHSLConns;          // Max number of HSL Opticonnect
                                       //                         connections
    hdatOtherIPLAttributes_t hdatOIA;  // Other IPL Attributes
    uint16_t hdatHugePageMemCount;     // Huge Page Memory Count
    uint8_t  hdatHugePageMemSize;      // Huge Page Memory Size
    uint8_t  hdatNumVlanSwitches;      // Number of VLAN Switches
    uint32_t hdatReserved3;            // Reserved
    uint32_t hdatEnlargedIOCap;        // Enlarged IO Capacity
}__attribute__ ((packed));


/** @brief Structure definition for IPL Time Data
 *  */
struct hdatIplTimeData_t
{
    uint32_t hdatReserved1;            // Reserved
    uint32_t hdatReserved2;            // Reserved
    uint32_t hdatReserved3;            // Reserved
    union {uint32_t hdatRTCValidFlags; // Real Time Clock and Delta Valid Flags
           uint32_t hdatReserved4  :27,
                    hdatFSPTimeRef : 1,
                    hdatHYPSetTOD  : 1,
                    hdatReserved5  : 1,
                    hdatCumRTCDeltaValid : 1,
                    hdatIPLStartRTCValid : 1;};
    uint64_t hdatCumulativeRTCDelta;   // Cumulative RTC Delta
    uint32_t hdatReserved6;            // Reserved
    uint32_t hdatReserved7;            // Reserved
} __attribute__ ((packed));

/** @brief Structure definition for service processor private IPL type
 */
struct hdatIplSpPvt_t
{
    uint32_t  hdatIplType;
} __attribute__ ((packed));


/** @brief Structure definition for dump information
 */
struct hdatDump_t
{
    union
    {
        uint16_t hdatFlags;                // word view unioned with bit view
        struct
        {
            uint16_t hdatRptPending    : 1;    // 1 = A dump exists and is
                                               //        waiting to be extracted
            uint16_t hdatHdwDumpExists : 1;    // 1 = Hardware dump exists
            uint16_t hdatMemDumpExists : 1;    // 1 = Memory dump exists
            uint16_t hdatHdwDumpErrs   : 1;    // 1 = Errors occurred during
                                               //       hardware dump collection
            uint16_t hdatMemDumpErrs   : 1;    // 1 = Errors occurred during
                                              //        memory dump collection
            uint16_t hdatHdwDumpReq    : 1;    // 1 = Hardware dump requested
            uint16_t hdatMemDumpReq    : 1;    // 1 = Memory dump requested
            uint16_t hdatUserReq       : 1;    // 1 = User requested the dump
            uint16_t hdatErrReq        : 1;    // 1 = Hardware or software
                                               //        error caused the dump
            uint16_t hdatReserved1     : 7;    // Reserved for future use
        } PACKED;
    };
    uint8_t  hdatReserved2;
    uint8_t  hdatHypDumpPolicy;
    uint32_t hdatDumpId;
    uint8_t  hdatReserved3[8];
    uint64_t hdatActPlatformDumpSize;
    uint32_t hdatMaxHdwSize;
    uint32_t hdatActHdwSize;
    uint32_t hdatMaxSpSize;
    uint32_t hdatPlid;
} __attribute__ ((packed));


/** @brief Structure definition for hardware management console information
 */
struct hdatHmc_t
{
    uint8_t hdatHmcFlags;
    uint8_t hdatReserved1[3];
} __attribute__ ((packed));

const uint8_t HDAT_HMC_MANAGED = 0x80;


/** @brief Structure definition for capacity upgrade on demand information
 */
struct hdatCuod_t
{
    uint8_t hdatCuodFlags;
    uint8_t hdatReserved1[3];
} __attribute__ ((packed));


const uint32_t HDAT_POWER_LOST = 0x80;
const uint32_t HDAT_POWER_OFF = 0x40;


const uint32_t HDAT_MNFG_MAX_CELLS = 0x04;

/** @brief Structure definition for manufacturing mode information
 */
struct hdatManf_t
{
    uint32_t hdatPolicyFlags[HDAT_MNFG_MAX_CELLS]; // 4 cells of mfg mode data
} __attribute__ ((packed));


/** @brief Structure definition for SP serial port information
 */
const uint32_t hdatMaxPorts = 2;  // maximum number of serial ports

struct hdatPortCodes_t
{
    char     hdatLocCode[80];   // serial port location code
    uint16_t hdatResourceId;    // serial port resource id
    uint16_t hdatCallHome  : 1, // 1 = designated as the "Call Home" port
             hdatReserved1 : 15;// Reserved for future use
} __attribute__ ((packed));

#define MAX_FEATURE_FLAGS 64     // Maximum number of feature flags
#define NUM_RISK_LEVELS 6  // 0, 1, 2, 3, 4, 5
#define NUM_OF_DD_LVLS  3  // DD2.0/2.1, 2.2, 2.3
#define NUM_FF_FLAGS    18

enum HDAT_FEATURE_FLAG_VERSION : uint32_t
{
    V1 = 0x00000001
};

const uint8_t HDAT_PROC_NIMBUS_DD_20 = 0x20;
const uint8_t HDAT_PROC_NIMBUS_DD_21 = 0x21;
const uint8_t HDAT_PROC_NIMBUS_DD_22 = 0x22;
const uint8_t HDAT_PROC_NIMBUS_DD_23 = 0x23;
const uint8_t HDAT_NIMBUS_DD_20_21_IDX = 0;
const uint8_t HDAT_NIMBUS_DD_22_IDX = 1;
const uint8_t HDAT_NIMBUS_DD_23_IDX = 2;

struct hdatIplpFeatureFlagSetting_t
{
    char     hdatIplpFeatureFlagString[64]; // Feature flag null terminated string
    uint64_t hdatIplpFeatureFlagSetting;    // bit0 indicates IPL time setting.
}__attribute__ ((packed));

// Agreed strings and settings of different feature flags
// based on risk level and DD levels.

const hdatIplpFeatureFlagSetting_t hdatIplpFeatureFlagSettingsArray[NUM_RISK_LEVELS][NUM_OF_DD_LVLS][NUM_FF_FLAGS]=
{
//RISK 0 (AIX/Linux/IBMi)
{
// Risk Level 0 , compat mode, nimbus DD2.0 / nimbus DD2.1 
{
{"tm-suspend-mode",                                 0x0000000000000000},
{"inst-spec-barrier-ori31,31,0",                    0x8000000000000000},
{"fw-bcctrl-serialized",                            0x0000000000000000},
{"inst-l1d-flush-ori30,30,0",                       0x0000000000000000},
{"inst-l1d-flush-trig2",                            0x0000000000000000},
{"fw-l1d-thread-split",                             0x8000000000000000},
{"fw-branch-hints-honored",                         0x8000000000000000},
{"inst-thread-reconfig-control-trig0-1",            0x0000000000000000},
{"fw-count-cache-disabled",                         0x8000000000000000},
{"fw-ltptr-serialized",                             0x0000000000000000},
{"fw-count-cache-flush-bcctr2,0,0",                 0x0000000000000000},
{"speculation-policy-favor-security",               0x8000000000000000},
{"user-mode-branch-speculation",                    0x8000000000000000},
{"needs-l1d-flush-msr-hv-1-to-0",                   0x8000000000000000},
{"needs-l1d-flush-msr-pr-0-to-1",                   0x8000000000000000},
{"needs-spec-barrier-for-bound-checks",             0x8000000000000000},
{"needs-pmu-restricted",                            0x0000000000000000},
{"needs-count-cache-flush-on-context-switch",       0x0000000000000000}},

// Risk Level 0 , compat mode , nimbus DD 2.2
{
{"tm-suspend-mode",                                 0x8000000000000000},
{"inst-spec-barrier-ori31,31,0",                    0x8000000000000000},
{"fw-bcctrl-serialized",                            0x0000000000000000},
{"inst-l1d-flush-ori30,30,0",                       0x0000000000000000},
{"inst-l1d-flush-trig2",                            0x8000000000000000},
{"fw-l1d-thread-split",                             0x8000000000000000},
{"fw-branch-hints-honored",                         0x8000000000000000},
{"inst-thread-reconfig-control-trig0-1",            0x0000000000000000},
{"fw-count-cache-disabled",                         0x8000000000000000},
{"fw-ltptr-serialized",                             0x0000000000000000},
{"fw-count-cache-flush-bcctr2,0,0",                 0x0000000000000000},
{"speculation-policy-favor-security",               0x8000000000000000},
{"user-mode-branch-speculation",                    0x0000000000000000},
{"needs-l1d-flush-msr-hv-1-to-0",                   0x8000000000000000},
{"needs-l1d-flush-msr-pr-0-to-1",                   0x8000000000000000},
{"needs-spec-barrier-for-bound-checks",             0x8000000000000000},
{"needs-pmu-restricted",                            0x0000000000000000},
{"needs-count-cache-flush-on-context-switch",       0x0000000000000000}},

// Risk Level 0 , compat mode , nimbus DD 2.3
{
{"tm-suspend-mode",                                 0x8000000000000000},
{"inst-spec-barrier-ori31,31,0",                    0x8000000000000000},
{"fw-bcctrl-serialized",                            0x0000000000000000},
{"inst-l1d-flush-ori30,30,0",                       0x0000000000000000},
{"inst-l1d-flush-trig2",                            0x8000000000000000},
{"fw-l1d-thread-split",                             0x8000000000000000},
{"fw-branch-hints-honored",                         0x8000000000000000},
{"inst-thread-reconfig-control-trig0-1",            0x0000000000000000},
{"fw-count-cache-disabled",                         0x8000000000000000},
{"fw-ltptr-serialized",                             0x0000000000000000},
{"fw-count-cache-flush-bcctr2,0,0",                 0x0000000000000000},
{"speculation-policy-favor-security",               0x8000000000000000},
{"user-mode-branch-speculation",                    0x0000000000000000},
{"needs-l1d-flush-msr-hv-1-to-0",                   0x8000000000000000},
{"needs-l1d-flush-msr-pr-0-to-1",                   0x8000000000000000},
{"needs-spec-barrier-for-bound-checks",             0x8000000000000000},
{"needs-pmu-restricted",                            0x0000000000000000},
{"needs-count-cache-flush-on-context-switch",       0x0000000000000000}},
// End of Risk Level 0
},

//RISK 1 (AIX/Linux)
{
// Risk Level 1 , compat mode , nimbus DD 2.0 / nimbus DD 2.1
{
{"tm-suspend-mode",                                 0x0000000000000000},
{"inst-spec-barrier-ori31,31,0",                    0x8000000000000000},
{"fw-bcctrl-serialized",                            0x8000000000000000},
{"inst-l1d-flush-ori30,30,0",                       0x0000000000000000},
{"inst-l1d-flush-trig2",                            0x0000000000000000},
{"fw-l1d-thread-split",                             0x8000000000000000},
{"fw-branch-hints-honored",                         0x8000000000000000},
{"inst-thread-reconfig-control-trig0-1",            0x0000000000000000},
{"fw-count-cache-disabled",                         0x0000000000000000},
{"fw-ltptr-serialized",                             0x0000000000000000},
{"fw-count-cache-flush-bcctr2,0,0",                 0x0000000000000000},
{"speculation-policy-favor-security",               0x8000000000000000},
{"user-mode-branch-speculation",                    0x0000000000000000},
{"needs-l1d-flush-msr-hv-1-to-0",                   0x8000000000000000},
{"needs-l1d-flush-msr-pr-0-to-1",                   0x8000000000000000},
{"needs-spec-barrier-for-bound-checks",             0x8000000000000000},
{"needs-pmu-restricted",                            0x0000000000000000},
{"needs-count-cache-flush-on-context-switch",       0x0000000000000000}},

// Risk Level 1 , compat mode , nimbus DD 2.2
{
{"tm-suspend-mode",                                 0x8000000000000000},
{"inst-spec-barrier-ori31,31,0",                    0x8000000000000000},
{"fw-bcctrl-serialized",                            0x8000000000000000},
{"inst-l1d-flush-ori30,30,0",                       0x0000000000000000},
{"inst-l1d-flush-trig2",                            0x8000000000000000},
{"fw-l1d-thread-split",                             0x8000000000000000},
{"fw-branch-hints-honored",                         0x8000000000000000},
{"inst-thread-reconfig-control-trig0-1",            0x0000000000000000},
{"fw-count-cache-disabled",                         0x0000000000000000},
{"fw-ltptr-serialized",                             0x0000000000000000},
{"fw-count-cache-flush-bcctr2,0,0",                 0x0000000000000000},
{"speculation-policy-favor-security",               0x8000000000000000},
{"user-mode-branch-speculation",                    0x8000000000000000},
{"needs-l1d-flush-msr-hv-1-to-0",                   0x8000000000000000},
{"needs-l1d-flush-msr-pr-0-to-1",                   0x8000000000000000},
{"needs-spec-barrier-for-bound-checks",             0x8000000000000000},
{"needs-pmu-restricted",                            0x0000000000000000},
{"needs-count-cache-flush-on-context-switch",       0x0000000000000000}},
// Risk Level 1 , compat mode , nimbus DD 2.3
{
{"tm-suspend-mode",                                 0x8000000000000000},
{"inst-spec-barrier-ori31,31,0",                    0x8000000000000000},
{"fw-bcctrl-serialized",                            0x8000000000000000},
{"inst-l1d-flush-ori30,30,0",                       0x0000000000000000},
{"inst-l1d-flush-trig2",                            0x8000000000000000},
{"fw-l1d-thread-split",                             0x8000000000000000},
{"fw-branch-hints-honored",                         0x8000000000000000},
{"inst-thread-reconfig-control-trig0-1",            0x0000000000000000},
{"fw-count-cache-disabled",                         0x0000000000000000},
{"fw-ltptr-serialized",                             0x0000000000000000},
{"fw-count-cache-flush-bcctr2,0,0",                 0x0000000000000000},
{"speculation-policy-favor-security",               0x8000000000000000},
{"user-mode-branch-speculation",                    0x8000000000000000},
{"needs-l1d-flush-msr-hv-1-to-0",                   0x8000000000000000},
{"needs-l1d-flush-msr-pr-0-to-1",                   0x8000000000000000},
{"needs-spec-barrier-for-bound-checks",             0x8000000000000000},
{"needs-pmu-restricted",                            0x0000000000000000},
{"needs-count-cache-flush-on-context-switch",       0x0000000000000000}},
// End of Risk Level 1
},

//RISK 2 (No Security)
{
// Risk Level 2 , compat mode , nimbus DD 2.0 / nimbus DD 2.1
{
{"tm-suspend-mode",                                 0x0000000000000000},
{"inst-spec-barrier-ori31,31,0",                    0x0000000000000000},
{"fw-bcctrl-serialized",                            0x0000000000000000},
{"inst-l1d-flush-ori30,30,0",                       0x0000000000000000},
{"inst-l1d-flush-trig2",                            0x0000000000000000},
{"fw-l1d-thread-split",                             0x0000000000000000},
{"fw-branch-hints-honored",                         0x0000000000000000},
{"inst-thread-reconfig-control-trig0-1",            0x0000000000000000},
{"fw-count-cache-disabled",                         0x0000000000000000},
{"fw-ltptr-serialized",                             0x0000000000000000},
{"fw-count-cache-flush-bcctr2,0,0",                 0x0000000000000000},
{"speculation-policy-favor-security",               0x0000000000000000},
{"user-mode-branch-speculation",                    0x0000000000000000},
{"needs-l1d-flush-msr-hv-1-to-0",                   0x0000000000000000},
{"needs-l1d-flush-msr-pr-0-to-1",                   0x0000000000000000},
{"needs-spec-barrier-for-bound-checks",             0x0000000000000000},
{"needs-pmu-restricted",                            0x0000000000000000},
{"needs-count-cache-flush-on-context-switch",       0x0000000000000000}},

// Risk Level 2 , compat mode , nimbus DD 2.2
{
{"tm-suspend-mode",                                 0x8000000000000000},
{"inst-spec-barrier-ori31,31,0",                    0x0000000000000000},
{"fw-bcctrl-serialized",                            0x0000000000000000},
{"inst-l1d-flush-ori30,30,0",                       0x0000000000000000},
{"inst-l1d-flush-trig2",                            0x0000000000000000},
{"fw-l1d-thread-split",                             0x0000000000000000},
{"fw-branch-hints-honored",                         0x0000000000000000},
{"inst-thread-reconfig-control-trig0-1",            0x0000000000000000},
{"fw-count-cache-disabled",                         0x0000000000000000},
{"fw-ltptr-serialized",                             0x0000000000000000},
{"fw-count-cache-flush-bcctr2,0,0",                 0x0000000000000000},
{"speculation-policy-favor-security",               0x0000000000000000},
{"user-mode-branch-speculation",                    0x0000000000000000},
{"needs-l1d-flush-msr-hv-1-to-0",                   0x0000000000000000},
{"needs-l1d-flush-msr-pr-0-to-1",                   0x0000000000000000},
{"needs-spec-barrier-for-bound-checks",             0x0000000000000000},
{"needs-pmu-restricted",                            0x0000000000000000},
{"needs-count-cache-flush-on-context-switch",       0x0000000000000000}},

// Risk Level 2 , compat mode , nimbus DD 2.3
{
{"tm-suspend-mode",                                 0x8000000000000000},
{"inst-spec-barrier-ori31,31,0",                    0x0000000000000000},
{"fw-bcctrl-serialized",                            0x0000000000000000},
{"inst-l1d-flush-ori30,30,0",                       0x0000000000000000},
{"inst-l1d-flush-trig2",                            0x0000000000000000},
{"fw-l1d-thread-split",                             0x0000000000000000},
{"fw-branch-hints-honored",                         0x0000000000000000},
{"inst-thread-reconfig-control-trig0-1",            0x0000000000000000},
{"fw-count-cache-disabled",                         0x0000000000000000},
{"fw-ltptr-serialized",                             0x0000000000000000},
{"fw-count-cache-flush-bcctr2,0,0",                 0x0000000000000000},
{"speculation-policy-favor-security",               0x0000000000000000},
{"user-mode-branch-speculation",                    0x0000000000000000},
{"needs-l1d-flush-msr-hv-1-to-0",                   0x0000000000000000},
{"needs-l1d-flush-msr-pr-0-to-1",                   0x0000000000000000},
{"needs-spec-barrier-for-bound-checks",             0x0000000000000000},
{"needs-pmu-restricted",                            0x0000000000000000},
{"needs-count-cache-flush-on-context-switch",       0x0000000000000000}},
// End of Risk Level 2
},


//Risk levels 3 is being skipped as of now. Add values if needed infuture.
//RISK3 
{
// Risk Level3 2.0 / nimbus DD 2.1
{},

// Risk Level 3 nimbus DD2.2
{},

// Risk Level 3 nimbus DD2.3
{},
// End of Risk Level 3 
},


//RISK 4
{
// Risk Level 4 , native mode , nimbus DD 2.0 / nimbus DD 2.1
{},

// Risk Level 4 , native mode , nimbus DD 2.2
{},

// Risk Level 4 , native mode , nimbus DD 2.3
{
{"tm-suspend-mode",                                 0x8000000000000000},
{"inst-spec-barrier-ori31,31,0",                    0x8000000000000000},
{"fw-bcctrl-serialized",                            0x0000000000000000},
{"inst-l1d-flush-ori30,30,0",                       0x0000000000000000},
{"inst-l1d-flush-trig2",                            0x8000000000000000},
{"fw-l1d-thread-split",                             0x8000000000000000},
{"fw-branch-hints-honored",                         0x0000000000000000},
{"inst-thread-reconfig-control-trig0-1",            0x0000000000000000},
{"fw-count-cache-disabled",                         0x0000000000000000},
{"fw-ltptr-serialized",                             0x0000000000000000},
{"fw-count-cache-flush-bcctr2,0,0",                 0x8000000000000000},
{"speculation-policy-favor-security",               0x8000000000000000},
{"user-mode-branch-speculation",                    0x0000000000000000},
{"needs-l1d-flush-msr-hv-1-to-0",                   0x8000000000000000},
{"needs-l1d-flush-msr-pr-0-to-1",                   0x8000000000000000},
{"needs-spec-barrier-for-bound-checks",             0x8000000000000000},
{"needs-pmu-restricted",                            0x0000000000000000},
{"needs-count-cache-flush-on-context-switch",       0x8000000000000000}},
// End of Risk Level 4
},


//RISK 5
{
// Risk Level 5 , native mode , nimbus DD 2.0 / nimbus DD 2.1
{},

// Risk Level 5 , native mode , nimbus DD 2.2
{},

// Risk Level 5 , native mode , nimbus DD 2.3
{
{"tm-suspend-mode",                                 0x8000000000000000},
{"inst-spec-barrier-ori31,31,0",                    0x0000000000000000},
{"fw-bcctrl-serialized",                            0x0000000000000000},
{"inst-l1d-flush-ori30,30,0",                       0x0000000000000000},
{"inst-l1d-flush-trig2",                            0x0000000000000000},
{"fw-l1d-thread-split",                             0x0000000000000000},
{"fw-branch-hints-honored",                         0x0000000000000000},
{"inst-thread-reconfig-control-trig0-1",            0x0000000000000000},
{"fw-count-cache-disabled",                         0x0000000000000000},
{"fw-ltptr-serialized",                             0x0000000000000000},
{"fw-count-cache-flush-bcctr2,0,0",                 0x0000000000000000},
{"speculation-policy-favor-security",               0x0000000000000000},
{"user-mode-branch-speculation",                    0x0000000000000000},
{"needs-l1d-flush-msr-hv-1-to-0",                   0x0000000000000000},
{"needs-l1d-flush-msr-pr-0-to-1",                   0x0000000000000000},
{"needs-spec-barrier-for-bound-checks",             0x0000000000000000},
{"needs-pmu-restricted",                            0x0000000000000000},
{"needs-count-cache-flush-on-context-switch",       0x0000000000000000}},
// End of Risk Level 5
},

};

#define HDAT_CHIP_TYPE_MURANO                      "MURANO"
#define HDAT_CHIP_TYPE_VENICE                      "VENICE"
#define HDAT_CHIP_TYPE_NIMBUS                      "NIMBUS"
#define HDAT_CHIP_TYPE_CUMULUS                     "CUMULUS"

#define HDAT_SYSTEM_TYPE_BASE_FIRENZE              0x30000000
#define HDAT_SYSTEM_TYPE_PLUS_FIRENZE              0x30000001
#define HDAT_SYSTEM_TYPE_MISC_OPENPOWER            0x00150000

#define HDAT_FIRMWARE_SIDE_TEMPORARY               0x11

#define HDAT_KEYLOCK_MANUAL                        0x02
#define HDAT_KEYLOCK_NORMAL                        0x04

#define HDAT_MULT_TPMDS                            0x80000000
#define HDAT_SMM_ENABLED                           0x40000000
#define HDAT_CRYPTO_DISABLED_BIT                   0x20000000
#define HDAT_RISK_LEVEL_ELEVATED                   0x10000000       
#define HDAT_MPIPL_SUPPORTED                       0x04000000

#define HDAT_ECO_ENABLED                           0x80000000
#define HDAT_ECO_CAPABLE                           0x40000000

#define HDAT_TURBO_CORE_MODE_PART_SIZE_128         0x0080
#define HDAT_NONTURBO_EIGHT_CORE_PART_SIZE_32      0x0020
#define HDAT_NONTURBO_EIGHT_CORE_PART_SIZE_256     0x8020
#define HDAT_NONTURBO_SIX_CORE_PART_SIZE_24        0x0018
#define HDAT_NONTURBO_SIX_CORE_PART_SIZE_256       0x8018


#define HDAT_MFG_FLAGS_CELL_0                      0x00000000
#define HDAT_MFG_FLAGS_CELL_1                      0x00020000
#define HDAT_MFG_FLAGS_CELL_2                      0x00040000
#define HDAT_MFG_FLAGS_CELL_3                      0x00080000

#define HDAT_MFG_FLAG_AVP_ENABLED                  0x00000100
#define HDAT_MFG_FLAG_HDAT_AVP_ENABLED             0x00000010
#define HDAT_MNFG_FLAG_SRC_TERM                    0x00000200
#define HDAT_MNFG_IPL_MEM_CE_CHECKING_ACTIVE       0x00000008
#define HDAT_MNFG_FAST_BKG_SCRUB_ACTIVE            0x00000080
#define HDAT_MNFG_TEST_DRAM_REPAIRS                0x00000200
#define HDAT_MNFG_DISABLE_DRAM_REPAIRS             0x00000008
#define HDAT_MNFG_ENABLE_EXHAUSTIVE_PATTERN_TEST   0x00000001
#define HDAT_MNFG_ENABLE_STANDARD_PATTERN_TEST     0x00000002
#define HDAT_MNFG_ENABLE_MIN_PATTERN_TEST          0x00000004
#define HDAT_MNFG_DISABLE_FABRIC_ERPAIR            0x00000010
#define HDAT_MNFG_DISABLE_MEMORY_ERPAIR            0x00000020
#define HDAT_MNFG_FABRIC_DEPLOY_LANE_SPARES        0x00000200
#define HDAT_MNFG_DMI_DEPLOY_LANE_SPARES           0x00000100
#define HDAT_MNFG_PSI_DIAGNOSTIC                   0x00000001
#define HDAT_MNFG_FSP_UPDATE_SBE_IMAGE             0x00000004
#define HDAT_MNFG_UPDATE_BOTH_SIDES_OF_SBE         0x00000008

enum hdatIPLParamsDataPtrs
{
  HDAT_IPL_PARAMS_SYS_PARAMS    = 0,
  HDAT_IPL_PARAMS_IPL_PARAMS    = 1,
  HDAT_IPL_PARAMS_TIME_DATA     = 2,
  HDAT_IPL_PARAMS_SPPL_PARAMS   = 3,
  HDAT_IPL_PARAMS_PDUMP_DATA    = 4,
  HDAT_IPL_PARAMS_HMC_CONNS     = 5,
  HDAT_IPL_PARAMS_CUOD_DATA     = 6,
  HDAT_IPL_PARAMS_MFG_DATA      = 7,
  HDAT_IPL_PARAMS_SERIAL_PORTS  = 8,
  HDAT_IPL_PARAMS_FEATURE_FLAGS = 9,
  HDAT_IPL_PARAMS_DA_CNT        = 10,
  HDAT_IPL_PARAMS_DA_LAST       = 11
};

struct hdatIPLParameters_t{
       /** Object Instance Data
         *
         * @li iv_sysParms     - system model/feature code
         * @li iv_iplParms     - IPL parameter information
         * @li iv_iplTime      - IPL time information
         * @li iv_pvt          - SP private IPL information
         * @li iv_dump         - dump information
         * @li iv_hmc          - hardware management console information
         * @li iv_cuod         - Capacity upgrade on demand information
         * @li iv_manf         - manufacturing flags
         * @li iv_portArrayHdr - serial port array header
         * @li iv_ports        - serial port location codes and resource ids
         * @li iv_featureFlagArrayHdr - feature flag array header
         * @li iv_featureFlagSettings - feature flag settings
         * @li iv_featureFlagArrSize - feature flag array size
         */
        hdatHDIF_t             hdatHdr;
        hdatHDIFDataHdr_t      hdatIPLParamsIntData[HDAT_IPL_PARAMS_DA_LAST];
        hdatSysParms_t         iv_sysParms;
        hdatIPLParams_t        iv_iplParms;
        hdatIplTimeData_t      iv_iplTime;
        hdatIplSpPvt_t         iv_pvt;
        hdatDump_t             iv_dump;
        hdatHmc_t              iv_hmc;
        hdatCuod_t             iv_cuod;
        hdatManf_t             iv_manf;
        hdatHDIFDataArray_t    iv_portArrayHdr;
        hdatPortCodes_t        iv_ports[hdatMaxPorts];
        hdatHDIFVersionedDataArray_t    iv_featureFlagArrayHdr;
        hdatIplpFeatureFlagSetting_t    iv_featureFlagSettings[MAX_FEATURE_FLAGS];
        uint32_t               iv_featureFlagArrSize;
};

/*----------------------------------------------------------------------------*/
/* C++ class definition                                                       */
/*----------------------------------------------------------------------------*/

/** Begin Class Description
 *
 * @brief  The HdatIplParms class is used to construct the IPL Parameters
 *         hypervisor data area.
 *
 * Description: This class defines a specialized object.  It is not intended
 *              that any component can create an object of this type.
 *              In particular, the object is built only by the hdat component.
 *
 *              The real purpose of the object is to create the IPL parameters
 *              data structure as defined by the PHYP Initialization
 *              architecture.  This data structure is eventually copied to
 *              main memory.  The class is not defined to be a general purpose
 *              interface for building this object by anyone other than the
 *              hdat process.
 *
 * Thread safety:  An HdatIplParms object is not thread safe.  That is, a
 *                 single object cannot be shared and used concurrently by
 *                 multiple threads at the same time.  An object can be used by
 *                 multiple threads if the threads serialize access.  And of
 *                 course, each thread can use its own object with no concerns
 *                 about what other threads are doing.
 *
 * Signal handler usage: This class is not intended to be used in a signal
 *                        handler and nothing has been done to try and make
 *                        it safe to use in a signal handler.
 *
 * End Class Description
 */
class HdatIplParms
{
    public:

/*
         * @brief Construct an HdatIplParms object.
         *
         *       This is the constructor for the HdatIplParms object.
         *
         *       If you are constructing this object on the heap by using new,
         *       then you must check the pointer returned from new to see if
         *       it is null.
         *       If it is null, new failed to allocate storage and the
         *       constructor was not called.  If it is not null, then you must
         *       check o_errlHndl to see if the constructor ran successfully.
         *       If o_errlHndl indicates an error was reported by the
         *       constructor, new has already allocated heap storage and the
         *       object must be deleted in order to free the heap storage.
         *
         * @pre None
         *
         * @post An HdatIplParms object has been constructed.
         *       Heap storage has been allocated.
         *
         * @param o_errlHndl - output parameter - If any errors occur, the
         *                                        HdatIplParms object is NOT
         *                                        constructed and errors are
         *                                        returned in this parameter
         * @param i_msAddr   - input parameter - The main memory address that
         *                                       the service processor subsystem
         *                                       structure will be DMA'd to.
         *
         * @return A null error log handle if successful, else the return
         *         code pointed  to by o_errlHndl contains one of:
         *
         * @retval HDAT_REGISTRY_ERROR
         */
        HdatIplParms(errlHndl_t &o_errlHndl,
                        const HDAT::hdatMsAddr_t &i_msAddr);


        /**
         * @brief HdatIplParms object destructor
         *
         *        This is the destructor for an HdatIplParms object.
         *        Any heap storage allocated for the object is dallocated.
         *
         * @pre No preconditions exist
         *
         * @post The HdatIplParms object has been destroyed and can
         *       no longer be used.
         *
         */
        ~HdatIplParms();

         /**
          * @brief Load IPL Paramsters to Mainstore
          *
          * @pre None
          *
          * @post None
          *
          * @param o_size - output parameter - Size of IPL Parameters structure
          *        o_count - output parameter - Number of IPL Parameters
          *                                     structures
          *
          * @return None
          *
          * @retval HDAT_OTHER_COMP_ERROR
          */

          errlHndl_t hdatLoadIplParams(uint32_t &o_size,uint32_t &o_count);
    private:

        void hdatGetSystemParamters(void);

        void hdatGetIplParmsData(void);

        HDAT::hdatMsAddr_t     iv_msAddr;

        hdatIPLParameters_t *iv_hdatIPLParams;


}; // end of HdatIplParms class

}
#endif // HDATIPLPARMS_H
