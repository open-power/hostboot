/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/lib/p10_avsbus_scom.H $   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019                             */
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
///
/// @file  p10_avsbus_scom.H
/// @brief Specific elements for AVSBus access via SCOM
///
// *HW Owner    : Greg Still <stillgs@us.ibm.com>
// *FW Owner    : Prasad BG Ranganath <prasadbgr@in.ibm.com>
// *Team        : PM
// *Consumed by : HB
// *Level       : 2
///

//TBD
//#include <p9_misc_scom_addresses.H>
//#include <p10_scom_proc_0.H>
#include <p10_scom_proc.H>

#ifndef __P10_AVSBUS_SCOM_H__
#define __P10_AVSBUS_SCOM_H__

namespace p10avslib
{
using namespace scomt::proc;
#define OCB_OISR0       TP_TPCHIP_OCC_OCI_OCB_OISR0_ROX
#define OCB_OISR0_CLR   TP_TPCHIP_OCC_OCI_OCB_OISR0_WOX_CLEAR
#define OCB_OISR0_OR    TP_TPCHIP_OCC_OCI_OCB_OISR0_WOX_OR
#define OCB_OIMR0       TP_TPCHIP_OCC_OCI_OCB_OIMR0_RW
#define OCB_OIMR0_CLR   TP_TPCHIP_OCC_OCI_OCB_OIMR0_WO_CLEAR
#define OCB_OIMR0_OR    TP_TPCHIP_OCC_OCI_OCB_OIMR0_WO_OR
#define OCB_OITR0       TP_TPCHIP_OCC_OCI_OCB_OITR0_RW
#define OCB_OITR0_CLR   TP_TPCHIP_OCC_OCI_OCB_OITR0_WO_CLEAR
#define OCB_OITR0_OR    TP_TPCHIP_OCC_OCI_OCB_OITR0_WO_OR
#define OCB_OIEPR0      TP_TPCHIP_OCC_OCI_OCB_OIEPR0_RW
#define OCB_OIEPR0_CLR  TP_TPCHIP_OCC_OCI_OCB_OIEPR0_WO_CLEAR
#define OCB_OIEPR0_OR   TP_TPCHIP_OCC_OCI_OCB_OIEPR0_WO_OR
#define OCB_OISR1       TP_TPCHIP_OCC_OCI_OCB_OISR1_ROX
#define OCB_OISR1_CLR   TP_TPCHIP_OCC_OCI_OCB_OISR1_WOX_CLEAR
#define OCB_OISR1_OR    TP_TPCHIP_OCC_OCI_OCB_OISR1_WOX_OR
#define OCB_OIMR1       TP_TPCHIP_OCC_OCI_OCB_OIMR1_RW
#define OCB_OIMR1_CLR   TP_TPCHIP_OCC_OCI_OCB_OIMR1_WO_CLEAR
#define OCB_OIMR1_OR    TP_TPCHIP_OCC_OCI_OCB_OIMR1_WO_OR
#define OCB_OITR1       TP_TPCHIP_OCC_OCI_OCB_OITR1_RW
#define OCB_OITR1_CLR   TP_TPCHIP_OCC_OCI_OCB_OITR1_WO_CLEAR
#define OCB_OITR1_OR    TP_TPCHIP_OCC_OCI_OCB_OITR1_WO_OR
#define OCB_OIEPR1      TP_TPCHIP_OCC_OCI_OCB_OIEPR1_RW
#define OCB_OIEPR1_CLR  TP_TPCHIP_OCC_OCI_OCB_OIEPR1_WO_CLEAR
#define OCB_OIEPR1_OR   TP_TPCHIP_OCC_OCI_OCB_OIEPR1_WO_OR

/// Need SCOM SBE, HB, PHYP or OPAL accesses

#define OCB_O2SCTRLF0A  TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF0
#define OCB_O2SCTRLS0A  TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS0
#define OCB_O2SCTRL10A  TP_TPCHIP_OCC_OCI_OCB_O2SCTRL10
#define OCB_O2SCTRL20A  TP_TPCHIP_OCC_OCI_OCB_O2SCTRL20
#define OCB_O2SST0A     TP_TPCHIP_OCC_OCI_OCB_O2SST0A
#define OCB_O2SCMD0A    TP_TPCHIP_OCC_OCI_OCB_O2SCMD0A
#define OCB_O2SWD0A     TP_TPCHIP_OCC_OCI_OCB_O2SWD0A
#define OCB_O2SRD0A     TP_TPCHIP_OCC_OCI_OCB_O2SRD0A
#define OCB_O2SST0B     TP_TPCHIP_OCC_OCI_OCB_O2SST0B
#define OCB_O2SCMD0B    TP_TPCHIP_OCC_OCI_OCB_O2SCMD0B
#define OCB_O2SWD0B     TP_TPCHIP_OCC_OCI_OCB_O2SWD0B
#define OCB_O2SRD0B     TP_TPCHIP_OCC_OCI_OCB_O2SRD0B
#define OCB_O2SCTRLF1A  TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF1
#define OCB_O2SCTRLS1A  TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS1
#define OCB_O2SCTRL11A  TP_TPCHIP_OCC_OCI_OCB_O2SCTRL11
#define OCB_O2SCTRL21A  TP_TPCHIP_OCC_OCI_OCB_O2SCTRL21
#define OCB_O2SST1A     TP_TPCHIP_OCC_OCI_OCB_O2SST1A
#define OCB_O2SCMD1A    TP_TPCHIP_OCC_OCI_OCB_O2SCMD1A
#define OCB_O2SWD1A     TP_TPCHIP_OCC_OCI_OCB_O2SWD1A
#define OCB_O2SRD1A     TP_TPCHIP_OCC_OCI_OCB_O2SRD1A
#define OCB_O2SST1B     TP_TPCHIP_OCC_OCI_OCB_O2SST1B
#define OCB_O2SST2A     TP_TPCHIP_OCC_OCI_OCB_O2SST2A
#define OCB_O2SST2B     TP_TPCHIP_OCC_OCI_OCB_O2SST2B
#define OCB_O2SCMD1B    TP_TPCHIP_OCC_OCI_OCB_O2SCMD1B
#define OCB_O2SCMD2A    TP_TPCHIP_OCC_OCI_OCB_O2SCMD2A
#define OCB_O2SCMD2B    TP_TPCHIP_OCC_OCI_OCB_O2SCMD2B
#define OCB_O2SWD1B     TP_TPCHIP_OCC_OCI_OCB_O2SWD1B
#define OCB_O2SWD2A     TP_TPCHIP_OCC_OCI_OCB_O2SWD2A
#define OCB_O2SWD2B     TP_TPCHIP_OCC_OCI_OCB_O2SWD2B
#define OCB_O2SRD1B     TP_TPCHIP_OCC_OCI_OCB_O2SRD1B
#define OCB_O2SRD2A     TP_TPCHIP_OCC_OCI_OCB_O2SRD2A
#define OCB_O2SRD2B     TP_TPCHIP_OCC_OCI_OCB_O2SRD2B
#define OCB_O2SCTRLF2A  TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF2
#define OCB_O2SCTRLS2A  TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS2
#define OCB_O2SCTRL12A  TP_TPCHIP_OCC_OCI_OCB_O2SCTRL12
#define OCB_O2SCTRL22A  TP_TPCHIP_OCC_OCI_OCB_O2SCTRL22



// O2S Control Frame Registers
const uint32_t OCB_O2SCTRLF[3] =
{
    OCB_O2SCTRLF0A, //6c700
    //OCB_O2SCTRLF0B,  //6c710
    OCB_O2SCTRLF1A,  //6c720
    //OCB_O2SCTRLF1B //6c730
    OCB_O2SCTRLF2A //6c740
};

// O2S Control Status Registers
const uint32_t OCB_O2SCTRLS[3] =
{
    OCB_O2SCTRLS0A,  //6c701
    //OCB_O2SCTRLS0B,
    OCB_O2SCTRLS1A,  //6c721
    //OCB_O2SCTRLS1B
    OCB_O2SCTRLS2A,  //6c741
};

// O2S Control 1 Registers
const uint32_t OCB_O2SCTRL1[3] =
{
    OCB_O2SCTRL10A, //6c702
//   OCB_O2SCTRL10B,
    OCB_O2SCTRL11A,  //6c722
    // OCB_O2SCTRL11B
    OCB_O2SCTRL12A  //6c742
};

// O2S Control 2 Registers
const uint32_t OCB_O2SCTRL2[3] =
{
    OCB_O2SCTRL20A,   //6c703
    //OCB_O2SCTRL20B,
    OCB_O2SCTRL21A,   //6c723
    //OCB_O2SCTRL21B
    OCB_O2SCTRL22A,    //6c743
};

// O2S Status Registers
const uint32_t OCB_O2SST[3][2] =
{
    OCB_O2SST0A, //6c706
    OCB_O2SST0B,  //6c716
    OCB_O2SST1A, //6c726
    OCB_O2SST1B,  //6c736
    OCB_O2SST2A, //6c746
    OCB_O2SST2B  //6c756
};

// O2S Command Registers
const uint32_t OCB_O2SCMD[3][2] =
{
    OCB_O2SCMD0A,   //6c707
    OCB_O2SCMD0B,  //6c717
    OCB_O2SCMD1A,  //6c727
    OCB_O2SCMD1B, //6c737
    OCB_O2SCMD2A,  //6c747
    OCB_O2SCMD2B  //6c757
};

// O2S Write Data Registers
const uint32_t OCB_O2SWD[3][2] =
{
    OCB_O2SWD0A,  //6c708
    OCB_O2SWD0B,  //6c718
    OCB_O2SWD1A,  //6c728
    OCB_O2SWD1B,  //6c738
    OCB_O2SWD2A,  //6c748
    OCB_O2SWD2B   //6c758
};

// O2S Read Data Registers
const uint32_t OCB_O2SRD[3][2] =
{
    OCB_O2SRD0A,  //6c709
    OCB_O2SRD0B,  //6c719
    OCB_O2SRD1A,  //6c729
    OCB_O2SRD1B,  //6c739
    OCB_O2SRD2A,  //6c749
    OCB_O2SRD2B   //6c759
};

} //end of p10avslib namespace
#endif  // __P10_AVSBUS_SCOM_H__
