/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/plat/cen/prdfCenChnlFailCache.H $           */
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
#include <map>
#include <targeting/common/targetservice.H>

#ifndef __prdfCenChnlFailCache_H
#define __prdfCenChnlFailCache_H

namespace PRDF
{

typedef std::map<TARGETING::TYPE, std::vector<uint64_t>> TargetScoms_t;

TargetScoms_t chnlFailScomList =
{
    {
        TARGETING::TYPE_MEMBUF,
        { // SCOMs
            0x500F001C, // GLOBAL_CS_FIR
            0x500F001B, // GLOBAL_RE_FIR
            0x500F001A, // GLOBAL_SPA_FIR
            0x01040000, // TP_CHIPLET_CS_FIR
            0x01040001, // TP_CHIPLET_RE_FIR
            0x01040002, // TP_CHIPLET_FIR_MASK
            0x0104000A, // TP_LFIR
            0x0104000D, // TP_LFIR_MASK
            0x01040010, // TP_LFIR_ACT0
            0x01040011, // TP_LFIR_ACT1
            0x02040000, // NEST_CHIPLET_CS_FIR
            0x02040001, // NEST_CHIPLET_RE_FIR
            0x02040002, // NEST_CHIPLET_FIR_MASK
            0x0204000A, // NEST_LFIR
            0x0204000D, // NEST_LFIR_MASK
            0x02040010, // NEST_LFIR_ACT0
            0x02040011, // NEST_LFIR_ACT1
            0x02010400, // DMIFIR
            0x02010403, // DMIFIR_MASK
            0x02010406, // DMIFIR_ACT0
            0x02010407, // DMIFIR_ACT1
            0x02010800, // MBIFIR
            0x02010803, // MBIFIR_MASK
            0x02010806, // MBIFIR_ACT0
            0x02010807, // MBIFIR_ACT1
            0x02011400, // MBSFIR
            0x02011403, // MBSFIR_MASK
            0x02011406, // MBSFIR_ACT0
            0x02011407, // MBSFIR_ACT1
            0x0201141e, // MBSSECUREFIR
            0x02011440, // MBSECCFIR_0
            0x02011443, // MBSECCFIR_0_MASK
            0x02011446, // MBSECCFIR_0_ACT0
            0x02011447, // MBSECCFIR_0_ACT1
            0x02011480, // MBSECCFIR_1
            0x02011483, // MBSECCFIR_1_MASK
            0x02011486, // MBSECCFIR_1_ACT0
            0x02011487, // MBSECCFIR_1_ACT1
            0x020115c0, // SCACFIR
            0x020115c3, // SCACFIR_MASK
            0x020115c6, // SCACFIR_ACT0
            0x020115c7, // SCACFIR_ACT1
            0x02011600, // MCBISTFIR_0
            0x02011603, // MCBISTFIR_0_MASK
            0x02011606, // MCBISTFIR_0_ACT0
            0x02011607, // MCBISTFIR_0_ACT1
            0x02011700, // MCBISTFIR_1
            0x02011703, // MCBISTFIR_1_MASK
            0x02011706, // MCBISTFIR_1_ACT0
            0x02011707, // MCBISTFIR_1_ACT1
            0x03040000, // MEM_CHIPLET_CS_FIR
            0x03040001, // MEM_CHIPLET_RE_FIR
            0x03040002, // MEM_CHIPLET_FIR_MASK
            0x03040004, // MEM_CHIPLET_SPA_FIR
            0x03040007, // MEM_CHIPLET_SPA_FIR_MASK
            0x0304000A, // MEM_LFIR
            0x0304000D, // MEM_LFIR_MASK
            0x03040010, // MEM_LFIR_ACT0
            0x03040011, // MEM_LFIR_ACT1
            0x01030009, // TP_ERROR_STATUS
            0x02030009, // NEST_ERROR_STATUS
            0x0201080F, // MBIERPT
            0x02011413, // MBSCERR1
            0x0201142C, // MBSCERR2
            0x02011466, // MBA0_MBSECCERRPT_0
            0x02011467, // MBA0_MBSECCERRPT_1
            0x020114A6, // MBA1_MBSECCERRPT_0
            0x020114A7, // MBA1_MBSECCERRPT_1
            0x0201168f, // MBA0_MBXERRSTAT
            0x0201178f, // MBA1_MBXERRSTAT
            0x020115D4, // SENSORCACHEERRPT
            0x03030009, // MEM_ERROR_STATUS
        }
    },
    {
        TARGETING::TYPE_MBA,
        {
            0x03010400, // MBACALFIR
            0x03010403, // MBACALFIR_MASK
            0x03010406, // MBACALFIR_ACT0
            0x03010407, // MBACALFIR_ACT1
            0x0301041b, // MBASECUREFIR
            0x03010600, // MBAFIR
            0x03010603, // MBAFIR_MASK
            0x03010606, // MBAFIR_ACT0
            0x03010607, // MBAFIR_ACT1
            0x03010611, // MBASPA
            0x03010614, // MBASPA_MASK
            0x0301041A, // MBA_ERR_REPORT
            0x030106E7, // MBA_MCBERRPTQ
            0x800200900301143F, // MBADDRPHYFIR
            0x800200930301143F, // MBADDRPHYFIR_MASK
            0x800200960301143F, // MBADDRPHYFIR_ACT0
            0x800200970301143F, // MBADDRPHYFIR_ACT1
            0x8000D0060301143F, // DDRPHY_APB_FIR_ERR0_P0
            0x8000D0070301143F, // DDRPHY_APB_FIR_ERR1_P0
            0x8001D0060301143F, // DDRPHY_APB_FIR_ERR0_P1
            0x8001D0070301143F, // DDRPHY_APB_FIR_ERR1_P1
        }
    }
};

} // namespace PRDF

#endif // __prdfCenChnlFailCache_H
