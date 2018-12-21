/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/hwas/common/vpdConstants.H $                  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018                             */
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

#ifndef VPD_CONSTANTS_H
#define VPD_CONSTANTS_H

namespace HWAS
{

// constants the platReadPartialGood will use for looking at the VPD data
const uint32_t VPD_CP00_PG_DATA_LENGTH      = 128;
const uint32_t VPD_CP00_PG_HDR_LENGTH       = 1;
const uint32_t VPD_CP00_PG_DATA_ENTRIES     = VPD_CP00_PG_DATA_LENGTH / 2;

// components of the partial good vector
// * = region does not exist in Nimbus
// + = partial good region
// '0' = region is good (NOTE: opposite of P8 where '1' represented good)
// '1' = region is bad or does not exist

const uint32_t VPD_CP00_PG_FSI_INDEX        = 0;
// all good - 4:FSI0, 5:FSI1, 6:FSIa
const uint32_t VPD_CP00_PG_FSI_GOOD         = 0xF1FF;

const uint32_t VPD_CP00_PG_PERVASIVE_INDEX  = 1;
// all good - 3:VITAL, 4:PRV, 5:NET, 6:PIB, 7:OCC, 8:ANPERV, 14:PLLNEST
const uint32_t VPD_CP00_PG_PERVASIVE_GOOD   = 0xE07D;

const uint32_t VPD_CP00_PG_N0_INDEX         = 2;
// all good - 3:VITAL, 4:PRV, 5:NX, 6:CXA0, 7:PBIOE0, 8:PBIOE1, 9:PBIOE2
const uint32_t VPD_CP00_PG_N0_GOOD          = 0xE03F;

const uint32_t VPD_CP00_PG_N1_INDEX         = 3;
// all good - 3:VITAL, 4:PRV, 5:MCD, 6:VA, 7:PBIOO0+, 8:PBIOO1+, 9:MCS23+
const uint32_t VPD_CP00_PG_N1_GOOD          = 0xE03F;
const uint32_t VPD_CP00_PG_N1_PG_MASK       = 0x01C0;
const uint32_t VPD_CP00_PG_N1_PBIOO0        = 0x0100;
const uint32_t VPD_CP00_PG_N1_PBIOO1        = 0x0080;
const uint32_t VPD_CP00_PG_N1_MCS23         = 0x0040;

const uint32_t VPD_CP00_PG_N2_INDEX         = 4;
// all good - 3:VITAL, 4:PRV, 5:CXA1, 6:PCIS0, 7:PCIS1, 8:PCIS2, 9:IOPSI
const uint32_t VPD_CP00_PG_N2_GOOD          = 0xE03F;

const uint32_t VPD_CP00_PG_N3_INDEX         = 5;
// all good - 3:VITAL, 4:PRV, 5:PB, 6:BR, 7:NPU+, 8:MM, 9:INT, 10:MCS01+
const uint32_t VPD_CP00_PG_N3_GOOD          = 0xE01F;
const uint32_t VPD_CP00_PG_N3_PG_MASK       = 0x0120;
const uint32_t VPD_CP00_PG_N3_NPU           = 0x0100;
const uint32_t VPD_CP00_PG_N3_MCS01         = 0x0020;

const uint32_t VPD_CP00_PG_XBUS_INDEX       = 6;
// all good - 3:VITAL, 4:PRV, 5:IOX0*, 6:IOX1, 7:IOX2, 8:IOPPE
//            9:PBIOX0*+, 10:PBIOX1+, 11:PBIOX2+, 14:PLLIOX
// Nimbus doesn't physically have PBIOX0 and IOX0.  IOX0 is
// taken care of by xbus links, need to handle PBIOX0 as part of
// the full chiplet good, so full good is E40D instead of E44D
// Currently, there are two versions of the MVPD PG keyword:
// 0xE44D == XBUS0 bad
// 0xE45D and 0xE55D == XBUS 0,2 bad
// Spec indicates that both iox (second nibble) and pbiox
// (third nibble) are bad for sforza and monza type modules.
// We support generically the following cases:
// 0xE50D --> xbus chiplet good
// 0xE40D --> xbus chiplet good
// and rely solely on the pbiox as the Xbus target indicator
// (0x0040, 0x0020, 0x0010) for all types of chips.
const uint32_t VPD_CP00_PG_XBUS_GOOD_NIMBUS = 0xE40D;
const uint32_t VPD_CP00_PG_XBUS_GOOD_CUMULUS= 0xE00D;
const uint32_t VPD_CP00_PG_XBUS_PG_MASK     = 0x00170;
const uint32_t VPD_CP00_PG_XBUS_IOX[3] = {0x0040, 0x0020, 0x0010};

const uint32_t VPD_CP00_PG_MC01_INDEX       = 7;
const uint32_t VPD_CP00_PG_MC23_INDEX       = 8;
const uint32_t VPD_CP00_PG_MCxx_INDEX[4]    = {VPD_CP00_PG_MC01_INDEX,
                                               VPD_CP00_PG_MC01_INDEX,
                                               VPD_CP00_PG_MC23_INDEX,
                                               VPD_CP00_PG_MC23_INDEX}; // by MCS
// Nimbus:
// all good - 3:VITAL, 4:PRV, 5:MC01, 6:IOM01+, 7:IOM23+, 14:PLLMEM
// all good - 3:VITAL, 4:PRV, 5:MC23, 6:IOM45+, 7:IOM67+, 14:PLLMEM
// Cumulus:
// all good - 3:VITAL, 4:PRV, 5:MC01, 6:IOM01, 7:IOM01PPE, 14:PLLMEM
// all good - 3:VITAL, 4:PRV, 5:MC23, 6:IOM23, 7:IOM23PPE, 14:PLLMEM
const uint32_t VPD_CP00_PG_MCxx_GOOD        = 0xE0FD;
const uint32_t VPD_CP00_PG_MCxx_PG_MASK     = 0x0300; // Nimbus only
// iom0 and iom4 need to be good for zqcal to work on any
// of the MCAs on that side
const uint32_t VPD_CP00_PG_MCA_MAGIC_PORT_MASK = 0x0200;
const uint32_t VPD_CP00_PG_MCxx_IOMyy[4]    = {0x0200, 0x0100, 0x0200, 0x0100};

const uint32_t VPD_CP00_PG_OB0_INDEX        = 9;
const uint32_t VPD_CP00_PG_OB3_INDEX        = 12;
// all good - 3:VITAL, 4:PRV, 5:PLIOOAx, 6:IOOx, 14:PLLIOO; x=0, 1*, 2*, 3
const uint32_t VPD_CP00_PG_OBUS_GOOD        = 0xE1FD;

const uint32_t VPD_CP00_PG_PCI0_INDEX       = 13;
// all good - 3:VITAL, 4:PRV, 5:PCI00, 6:IOPCI0, 14:PLLPCI0
// all good - 3:VITAL, 4:PRV, 5:PCI11, 6:PCI12, 7:IOPCI1, 14:PLLPCI1
// all good - 3:VITAL, 4:PRV, 5:PCI23, 6:PCI24, 7:PCI25, 8:IOPCI2, 14:PLLPCI2
const uint32_t VPD_CP00_PG_PCIx_GOOD[3]     = {0xE1FD, 0xE0FD, 0xE07D};

const uint32_t VPD_CP00_PG_EP0_INDEX        = 16;
const uint32_t VPD_CP00_PG_EP5_INDEX        = 21;
// all good - 3:VITAL, 4:PRV, 5:EQPB, 6:L30+, 7:L31+,
//            8:L20+, 9:L21+, 10:AN, 11:PBLEQ, 12:REFR0, 13:REFR1, 14:DPLL
const uint32_t VPD_CP00_PG_EPx_GOOD         = 0xE001;
const uint32_t VPD_CP00_PG_EPx_PG_MASK      = 0x03CC;
const uint32_t VPD_CP00_PG_EPx_L3L2REFR[2]  = {0x0288, 0x0144};

const uint32_t VPD_CP00_PG_EC00_INDEX       = 32;
// all good - 3:VITAL, 4:PRV, 5:C00, 6:C01
const uint32_t VPD_CP00_PG_ECxx_GOOD        = 0xE1FF;
const uint32_t VPD_CP00_PG_ECxx_MAX_ENTRIES = 24;

const uint32_t VPD_CP00_PG_MAX_USED_INDEX   = 55;
const uint32_t VPD_CP00_PG_xxx_VITAL        = 0x1000;
const uint32_t VPD_CP00_PG_xxx_PERV         = 0x0800;
const uint32_t VPD_CP00_PG_RESERVED_GOOD    = 0xFFFF;

// constants the platReadPR will use for looking at the VPD data
const uint32_t VPD_VINI_PR_DATA_LENGTH      = 8; //@deprecrated

// constants the platReadLx will use for looking at the VPD data
const uint32_t VPD_CRP0_LX_HDR_DATA_LENGTH  = 256;

const uint32_t VPD_CRP0_LX_FREQ_INDEP_INDEX = 8;
const uint32_t VPD_CRP0_LX_PORT_DISABLED    = 0;

const uint8_t  VPD_CRP0_LX_MIN_X            = 1;
const uint8_t  VPD_CRP0_LX_MAX_X            = 8;

// constants for the error log parser for partial good issues
const uint8_t MODEL_PG_DATA_ENTRIES = 2;

}

#endif
