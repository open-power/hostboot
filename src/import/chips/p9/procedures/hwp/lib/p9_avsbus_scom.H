/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/lib/p9_avsbus_scom.H $     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016                             */
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
/// @file  p9_avsbus_scom.H
/// @brief Specific elements for AVSBus access via SCOM
///
// *HW Owner    : Sudheendra K Srivathsa <sudheendraks@in.ibm.com>
// *FW Owner    : Sangeetha T S <sangeet2@in.ibm.com>
// *Team        : PM
// *Consumed by : HB
// *Level       : 2
///

#include <p9_misc_scom_addresses.H>

#ifndef __P9_AVSBUS_SCOM_H__
#define __P9_AVSBUS_SCOM_H__

namespace p9avslib
{
//#define OCB_OCI_BASE  PU_OCB_OCI_OCI_BASE
#define OCB_OISR0       PU_OCB_OCI_OISR0_SCOM
#define OCB_OISR0_CLR   PU_OCB_OCI_OISR0_SCOM1
#define OCB_OISR0_OR    PU_OCB_OCI_OISR0_SCOM2
#define OCB_OIMR0       PU_OCB_OCI_OIMR0_SCOM
#define OCB_OIMR0_CLR   PU_OCB_OCI_OIMR0_SCOM1
#define OCB_OIMR0_OR    PU_OCB_OCI_OIMR0_SCOM2
#define OCB_OITR0       PU_OCB_OCI_OITR0_SCOM
#define OCB_OITR0_CLR   PU_OCB_OCI_OITR0_SCOM1
#define OCB_OITR0_OR    PU_OCB_OCI_OITR0_SCOM2
#define OCB_OIEPR0      PU_OCB_OCI_OIEPR0_SCOM
#define OCB_OIEPR0_CLR  PU_OCB_OCI_OIEPR0_SCOM1
#define OCB_OIEPR0_OR   PU_OCB_OCI_OIEPR0_SCOM2
#define OCB_OISR1       PU_OCB_OCI_OISR1_SCOM
#define OCB_OISR1_CLR   PU_OCB_OCI_OISR1_SCOM1
#define OCB_OISR1_OR    PU_OCB_OCI_OISR1_SCOM2
#define OCB_OIMR1       PU_OCB_OCI_OIMR1_SCOM
#define OCB_OIMR1_CLR   PU_OCB_OCI_OIMR1_SCOM1
#define OCB_OIMR1_OR    PU_OCB_OCI_OIMR1_SCOM2
#define OCB_OITR1       PU_OCB_OCI_OITR1_SCOM
#define OCB_OITR1_CLR   PU_OCB_OCI_OITR1_SCOM1
#define OCB_OITR1_OR    PU_OCB_OCI_OITR1_SCOM2
#define OCB_OIEPR1      PU_OCB_OCI_OIEPR1_SCOM
#define OCB_OIEPR1_CLR  PU_OCB_OCI_OIEPR1_SCOM1
#define OCB_OIEPR1_OR   PU_OCB_OCI_OIEPR1_SCOM2

/// Need SCOM SBE, HB, PHYP or OPAL accesses

#define OCB_O2SCTRLF0A  PU_OCB_OCI_O2SCTRLF0A_SCOM
#define OCB_O2SCTRLS0A  PU_OCB_OCI_O2SCTRLS0A_SCOM
#define OCB_O2SCTRL10A  PU_OCB_OCI_O2SCTRL10A_SCOM
#define OCB_O2SCTRL20A  PU_OCB_OCI_O2SCTRL20A_SCOM
#define OCB_O2SST0A     PU_OCB_OCI_O2SST0A_SCOM
#define OCB_O2SCMD0A    PU_OCB_OCI_O2SCMD0A_SCOM
#define OCB_O2SWD0A     PU_OCB_OCI_O2SWD0A_SCOM
#define OCB_O2SRD0A     PU_OCB_OCI_O2SRD0A_SCOM
#define OCB_O2SCTRLF0B  PU_OCB_OCI_O2SCTRLF0B_SCOM
#define OCB_O2SCTRLS0B  PU_OCB_OCI_O2SCTRLS0B_SCOM
#define OCB_O2SCTRL10B  PU_OCB_OCI_O2SCTRL10B_SCOM
#define OCB_O2SCTRL20B  PU_OCB_OCI_O2SCTRL20B_SCOM
#define OCB_O2SST0B     PU_OCB_OCI_O2SST0B_SCOM
#define OCB_O2SCMD0B    PU_OCB_OCI_O2SCMD0B_SCOM
#define OCB_O2SWD0B     PU_OCB_OCI_O2SWD0B_SCOM
#define OCB_O2SRD0B     PU_OCB_OCI_O2SRD0B_SCOM
#define OCB_O2SCTRLF1A  PU_OCB_OCI_O2SCTRLF1A_SCOM
#define OCB_O2SCTRLS1A  PU_OCB_OCI_O2SCTRLS1A_SCOM
#define OCB_O2SCTRL11A  PU_OCB_OCI_O2SCTRL11A_SCOM
#define OCB_O2SCTRL21A  PU_OCB_OCI_O2SCTRL21A_SCOM
#define OCB_O2SST1A     PU_OCB_OCI_O2SST1A_SCOM
#define OCB_O2SCMD1A    PU_OCB_OCI_O2SCMD1A_SCOM
#define OCB_O2SWD1A     PU_OCB_OCI_O2SWD1A_SCOM
#define OCB_O2SRD1A     PU_OCB_OCI_O2SRD1A_SCOM
#define OCB_O2SCTRLF1B  PU_OCB_OCI_O2SCTRLF1B_SCOM
#define OCB_O2SCTRLS1B  PU_OCB_OCI_O2SCTRLS1B_SCOM
#define OCB_O2SCTRL11B  PU_OCB_OCI_O2SCTRL11B_SCOM
#define OCB_O2SCTRL21B  PU_OCB_OCI_O2SCTRL21B_SCOM
#define OCB_O2SST1B     PU_OCB_OCI_O2SST1B_SCOM
#define OCB_O2SCMD1B    PU_OCB_OCI_O2SCMD1B_SCOM
#define OCB_O2SWD1B     PU_OCB_OCI_O2SWD1B_SCOM
#define OCB_O2SRD1B     PU_OCB_OCI_O2SRD1B_SCOM


//#define OCB_O2SRD1B

// O2S Control Frame Registers
const uint32_t OCB_O2SCTRLF[2][2] =
{
    OCB_O2SCTRLF0A,
    OCB_O2SCTRLF0B,
    OCB_O2SCTRLF1A,
    OCB_O2SCTRLF1B
};

// O2S Control Status Registers
const uint32_t OCB_O2SCTRLS[2][2] =
{
    OCB_O2SCTRLS0A,
    OCB_O2SCTRLS0B,
    OCB_O2SCTRLS1A,
    OCB_O2SCTRLS1B
};

// O2S Control 1 Registers
const uint32_t OCB_O2SCTRL1[2][2] =
{
    OCB_O2SCTRL10A,
    OCB_O2SCTRL10B,
    OCB_O2SCTRL11A,
    OCB_O2SCTRL11B
};

// O2S Control 2 Registers
const uint32_t OCB_O2SCTRL2[2][2] =
{
    OCB_O2SCTRL20A,
    OCB_O2SCTRL20B,
    OCB_O2SCTRL21A,
    OCB_O2SCTRL21B
};

// O2S Status Registers
const uint32_t OCB_O2SST[2][2] =
{
    OCB_O2SST0A,
    OCB_O2SST0B,
    OCB_O2SST1A,
    OCB_O2SST1B
};

// O2S Command Registers
const uint32_t OCB_O2SCMD[2][2] =
{
    OCB_O2SCMD0A,
    OCB_O2SCMD0B,
    OCB_O2SCMD1A,
    OCB_O2SCMD1B
};

// O2S Write Data Registers
const uint32_t OCB_O2SWD[2][2] =
{
    OCB_O2SWD0A,
    OCB_O2SWD0B,
    OCB_O2SWD1A,
    OCB_O2SWD1B
};

// O2S Read Data Registers
const uint32_t OCB_O2SRD[2][2] =
{
    OCB_O2SRD0A,
    OCB_O2SRD0B,
    OCB_O2SRD1A,
    OCB_O2SRD1B
};

} //end of p9avslib namespace
#endif  // __P9_AVSBUS_SCOM_H__
