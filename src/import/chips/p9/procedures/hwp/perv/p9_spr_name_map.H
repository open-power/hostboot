/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/perv/p9_spr_name_map.H $   */
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
//-----------------------------------------------------------------------------------
///
/// @file p9_spr_name_map.H
/// @brief Utility to map SPR name to SPR number
///
//-----------------------------------------------------------------------------------
// *HWP HWP Owner        : Liu Yang Fan <shliuyf@cn.ibm.com>
// *HWP HWP Backup Owner : Gou Peng Fei <shgoupf@cn.ibm.com>
// *HWP FW Owner         : Thi Tran <thi@us.ibm.com>
// *HWP Team             : Perv
// *HWP Level            : 2
// *HWP Consumed by      : None (Cronus test only)
//-----------------------------------------------------------------------------------

#ifndef _P9_SPR_NAME_MAP_H_
#define _P9_SPR_NAME_MAP_H_

//-----------------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------------
#include <stdint.h>
#include <string>
#include <map>

// Read-Write mode flag for each SPR register
const unsigned char FLAG_READ_ONLY  = 0x1;
const unsigned char FLAG_WRITE_ONLY = 0x2;
const unsigned char FLAG_READ_WRITE = 0x3;

//-----------------------------------------------------------------------------------
// Structure definitions
//-----------------------------------------------------------------------------------
enum Enum_ShareType
{
    SPR_PER_CORE,
    SPR_PER_LPAR_PT,
    SPR_PER_LPAR_VT,
    SPR_PER_PT,
    SPR_PER_VT,
    SPR_SHARED,
    SPR_PARTIAL_SHARED,
    SPR_SHARE_NA          // unknown, or dependent on certain conditions
};

typedef struct
{
    int number;
    std::string spy_name;
    // 0x1: read-only; 0x2: write-only; 0x3 read-write
    unsigned char flag;
    Enum_ShareType share_type;
    uint8_t bit_length;
} SPRMapEntry;

//-----------------------------------------------------------------------------------
// Global variable definitions
//-----------------------------------------------------------------------------------
extern std::map<std::string, SPRMapEntry> SPR_MAP;
extern bool spr_map_initialized;
typedef std::map<std::string, SPRMapEntry>::iterator SPR_MAP_IT;

// List all the SPR registers(name, number, spy_name, flag)
// Reference <P9 SPR List.xls> on the P9 care bringup wiki
// Note:
// when ram is enabled, the hardware forces HV=1 PR=0
// current spy names are got from <P9 SPR List.xls>
// For the SPY names, <??T> should be replaced with thread ID, <??C> should be
// replaced with core ID.
#define LIST_SPR_REG(_op_)\
    _op_(XER      ,1   , N/A                                              ,FLAG_READ_WRITE ,SPR_PER_PT         ,64)\
    _op_(DSCR_RU  ,3   , N/A                                              ,FLAG_READ_WRITE ,SPR_PER_PT         ,25)\
    _op_(LR       ,8   , ECP.IFU.T<??T>_LR                                ,FLAG_READ_WRITE ,SPR_PER_PT         ,64)\
    _op_(CTR      ,9   , ECP.IFU.T<??T>_CTR                               ,FLAG_READ_WRITE ,SPR_PER_PT         ,64)\
    _op_(UAMR     ,13  , N/A                                              ,FLAG_READ_WRITE ,SPR_PER_PT         ,64)\
    _op_(DSCR     ,17  , ECP.LS.LSPRQX_DSCR<??T>                          ,FLAG_READ_WRITE ,SPR_PER_PT         ,25)\
    _op_(DSISR    ,18  , ECP.LS.T<??T>_DSISR                              ,FLAG_READ_WRITE ,SPR_PER_PT         ,32)\
    _op_(DAR      ,19  , ECP.LS.T<??T>_DAR                                ,FLAG_READ_WRITE ,SPR_PER_PT         ,64)\
    _op_(DEC      ,22  , EXP.EC.CC.PCC<??C>.V<??T>_DEC                    ,FLAG_READ_WRITE ,SPR_PER_PT         ,32)\
    _op_(SDR1     ,25  , ECP.LS.V<??T>_SDR1_MASTER                        ,FLAG_READ_WRITE ,SPR_PER_VT         ,64)\
    _op_(SRR0     ,26  , ECP.IFU.T<??T>_SRR0                              ,FLAG_READ_WRITE ,SPR_PER_LPAR_VT    ,64)\
    _op_(SRR1     ,27  , ECP.SD.T<??T>_SRR1                               ,FLAG_READ_WRITE ,SPR_PER_PT         ,64)\
    _op_(CFAR     ,28  , ECP.IFU.T<??T>_CFAR                              ,FLAG_READ_WRITE ,SPR_PER_PT         ,64)\
    _op_(AMR      ,29  , ECP.LS.T<??T>_AMR_MASTER                         ,FLAG_READ_WRITE ,SPR_PER_PT         ,64)\
    _op_(PIDR     ,48  , ECP.LS.T<??T>_PID_MASTER                         ,FLAG_READ_WRITE ,SPR_PER_PT         ,32)\
    _op_(IAMR     ,61  , ECP.LS.T<??T>_IAMR_MASTER                        ,FLAG_READ_WRITE ,SPR_PER_PT         ,32)\
    _op_(TFHAR    ,128 , ECP.IFU.T<??T>_TFHAR                             ,FLAG_READ_WRITE ,SPR_PER_PT         ,64)\
    _op_(TFIAR    ,129 , ECP.IFU.T<??T>_TFIAR                             ,FLAG_READ_WRITE ,SPR_PER_PT         ,64)\
    _op_(TEXASR   ,130 , ECP.SD.T<??T>_TEXASR                             ,FLAG_READ_WRITE ,SPR_PER_PT         ,64)\
    _op_(TEXASRU  ,131 , ECP.SD.T<??T>_TEXASR                             ,FLAG_READ_WRITE ,SPR_PER_PT         ,32)\
    _op_(CTRL_RU  ,136 , EXP.EC.CC.PCC<??C>.COMMON.SPR_COMMON.CTRL        ,FLAG_READ_ONLY  ,SPR_PER_PT         ,32)\
    _op_(TIDR     ,144 , ECP.LS.T<??T>_TIDR                               ,FLAG_READ_WRITE ,SPR_SHARED         ,64)\
    _op_(CTRL     ,152 , EXP.EC.CC.PCC<??C>.COMMON.SPR_COMMON.CTRL        ,FLAG_WRITE_ONLY ,SPR_PER_PT         ,32)\
    _op_(FSCR     ,153 , ECP.SD.T<??T>_FSCR                               ,FLAG_READ_WRITE ,SPR_PER_PT         ,64)\
    _op_(UAMOR    ,157 , ECP.LS.T<??T>_UAMOR                              ,FLAG_READ_WRITE ,SPR_PER_PT         ,64)\
    _op_(GSR      ,158 , N/A                                              ,FLAG_READ_WRITE ,SPR_SHARE_NA       ,64)\
    _op_(PSPB     ,159 , ECP.PC.PMU.SPR_CORE.V<??T>_PSPB                  ,FLAG_READ_WRITE ,SPR_PER_PT         ,32)\
    _op_(DPDES    ,176 , EXP.EC.CC.PCC<??C>.COMMON.SPR_COMMON.DPDES       ,FLAG_READ_WRITE ,SPR_PER_CORE       ,8 )\
    _op_(DAWR0    ,180 , ECP.LS.T<??T>_DAWR_MASTER                        ,FLAG_READ_WRITE ,SPR_PER_PT         ,64)\
    _op_(RPR      ,186 , ECP.IFU.RPR                                      ,FLAG_READ_WRITE ,SPR_PER_CORE       ,64)\
    _op_(CIABR    ,187 , ECP.IFU.T<??T>_CIABR                             ,FLAG_READ_WRITE ,SPR_PER_PT         ,64)\
    _op_(DAWRX0   ,188 , ECP.LS.T<??T>_DAWRX_MASTER                       ,FLAG_READ_WRITE ,SPR_PER_PT         ,32)\
    _op_(HFSCR    ,190 , ECP.SD.T<??T>_HFSCR                              ,FLAG_READ_WRITE ,SPR_PER_PT         ,64)\
    _op_(VRSAVE   ,256 , ECP.SD.T<??T>_VRSAVE                             ,FLAG_READ_WRITE ,SPR_PER_PT         ,32)\
    _op_(SPRG3_RU ,259 , ECP.PC.T<??T>_SPRG3                              ,FLAG_READ_ONLY  ,SPR_PER_PT         ,64)\
    _op_(TB       ,268 , EXP.EC.CC.PCC<??C>.L<??T>_TB                     ,FLAG_READ_ONLY  ,SPR_PER_LPAR_VT    ,64)\
    _op_(TBU_RU   ,269 , EXP.EC.CC.PCC<??C>.L<??T>_TBU                    ,FLAG_READ_ONLY  ,SPR_PER_LPAR_VT    ,32)\
    _op_(SPRG0    ,272 , ECP.PC.T<??T>_SPRG0                              ,FLAG_READ_WRITE ,SPR_PER_PT         ,64)\
    _op_(SPRG1    ,273 , ECP.PC.T<??T>_SPRG1                              ,FLAG_READ_WRITE ,SPR_PER_PT         ,64)\
    _op_(SPRG2    ,274 , ECP.PC.T<??T>_SPRG2                              ,FLAG_READ_WRITE ,SPR_PER_PT         ,64)\
    _op_(SPRG3    ,275 , ECP.PC.T<??T>_SPRG3                              ,FLAG_READ_WRITE ,SPR_PER_PT         ,64)\
    _op_(SPRC     ,276 , EXP.EC.CC.PCC<??C>.COMMON.SPR_COMMON.SPRC<??T>   ,FLAG_READ_WRITE ,SPR_PER_VT         ,64)\
    _op_(SPRD     ,277 , N/A                                              ,FLAG_READ_WRITE ,SPR_SHARE_NA       ,64)\
    _op_(CIR      ,283 , ECP.PC.PMU.SPR_CORE.CIR                          ,FLAG_READ_ONLY  ,SPR_SHARED         ,32)\
    _op_(TBL      ,284 , EXP.EC.CC.PCC<??C>.L<??T>_TBL                    ,FLAG_WRITE_ONLY ,SPR_PER_LPAR_VT    ,32)\
    _op_(TBU      ,285 , EXP.EC.CC.PCC<??C>.L<??T>_TBU                    ,FLAG_WRITE_ONLY ,SPR_PER_LPAR_VT    ,32)\
    _op_(TBU40    ,286 , EXP.EC.CC.PCC<??C>.L<??T>_TBU40                  ,FLAG_WRITE_ONLY ,SPR_PER_LPAR_VT    ,64)\
    _op_(PVR      ,287 , ECP.PC.PMU.SPR_CORE.PVR                          ,FLAG_READ_ONLY  ,SPR_SHARED         ,32)\
    _op_(HSPRG0   ,304 , ECP.PC.T<??T>_HSPRG0                             ,FLAG_READ_WRITE ,SPR_PER_PT         ,64)\
    _op_(HSPRG1   ,305 , ECP.PC.T<??T>_HSPRG1                             ,FLAG_READ_WRITE ,SPR_PER_PT         ,64)\
    _op_(HDSISR   ,306 , ECP.LS.T<??T>_HDSISR                             ,FLAG_READ_WRITE ,SPR_PER_PT         ,32)\
    _op_(HDAR     ,307 , ECP.LS.T<??T>_HDAR                               ,FLAG_READ_WRITE ,SPR_PER_PT         ,64)\
    _op_(SPURR    ,308 , EXP.EC.CC.PCC<??C>.V<??T>_SPURR                  ,FLAG_READ_WRITE ,SPR_PER_VT         ,64)\
    _op_(PURR     ,309 , EXP.EC.CC.PCC<??C>.V<??T>_PURR                   ,FLAG_READ_WRITE ,SPR_PER_VT         ,64)\
    _op_(HDEC     ,310 , EXP.EC.CC.PCC<??C>.L<??T>_HDEC                   ,FLAG_READ_WRITE ,SPR_PER_LPAR_VT    ,32)\
    _op_(HRMOR    ,313 , ECP.LS.HRMOR                                     ,FLAG_READ_WRITE ,SPR_SHARED         ,64)\
    _op_(HSRR0    ,314 , ECP.IFU.T<??T>_HSRR0                             ,FLAG_READ_WRITE ,SPR_PER_PT         ,64)\
    _op_(HSRR1    ,315 , ECP.SD.T<??T>_HSRR1                              ,FLAG_READ_WRITE ,SPR_PER_PT         ,64)\
    _op_(TFMR     ,317 , EXP.EC.CC.PCC<??C>.COMMON.TFC.T<??T>_TFMR        ,FLAG_READ_WRITE ,SPR_PARTIAL_SHARED ,64)\
    _op_(LPCR     ,318 , ECP.LS.T<??T>_LPCR_MASTER                        ,FLAG_READ_WRITE ,SPR_PER_PT         ,64)\
    _op_(LPIDR    ,319 , ECP.LS.T<??T>_LPIDR_MASTER                       ,FLAG_READ_WRITE ,SPR_PER_LPAR_PT    ,64)\
    _op_(HMER     ,336 , EXP.EC.CC.PCC<??C>.COMMON.SPR_COMMON.V<??T>_HMER ,FLAG_READ_WRITE ,SPR_PER_VT         ,64)\
    _op_(HMEER    ,337 , EXP.EC.CC.PCC<??C>.COMMON.SPR_COMMON.HMEER       ,FLAG_READ_WRITE ,SPR_SHARED         ,64)\
    _op_(PCR      ,338 , ECP.IFU.T<??T>_PCR                               ,FLAG_READ_WRITE ,SPR_PER_LPAR_PT    ,64)\
    _op_(HEIR     ,339 , ECP.SD.T<??T>_HEIR                               ,FLAG_READ_WRITE ,SPR_PER_PT         ,32)\
    _op_(AMOR     ,349 , ECP.LS.AMOR<??T>                                 ,FLAG_READ_WRITE ,SPR_PER_LPAR_PT    ,64)\
    _op_(TIR      ,446 , ECP.PC.PMU.SPR_CORE.TIR                          ,FLAG_READ_ONLY  ,SPR_PER_PT         ,8 )\
    _op_(PTCR     ,464 , ECP.LS.PTCR                                      ,FLAG_READ_WRITE ,SPR_PER_CORE       ,64)\
    _op_(USPRG0   ,496 , N/A                                              ,FLAG_READ_WRITE ,SPR_PER_PT         ,64)\
    _op_(USPRG1   ,497 , N/A                                              ,FLAG_READ_WRITE ,SPR_PER_PT         ,64)\
    _op_(UDAR     ,499 , ECP.LS.T<??T>_UDAR                               ,FLAG_READ_WRITE ,SPR_PER_PT         ,64)\
    _op_(SEIDR    ,504 , ECP.LS.T<??T>_SEIDR                              ,FLAG_READ_WRITE ,SPR_PER_PT         ,64)\
    _op_(URMOR    ,505 , ECP.LS.URMOR                                     ,FLAG_READ_WRITE ,SPR_PER_PT         ,64)\
    _op_(USRR0    ,506 , ECP.IFU.T<??T>_USRR0                             ,FLAG_READ_WRITE ,SPR_PER_PT         ,64)\
    _op_(USRR1    ,507 , N/A                                              ,FLAG_READ_WRITE ,SPR_PER_PT         ,64)\
    _op_(UEIR     ,509 , N/A                                              ,FLAG_READ_WRITE ,SPR_PER_PT         ,32)\
    _op_(ACMCR    ,510 , N/A                                              ,FLAG_READ_WRITE ,SPR_PER_PT         ,32)\
    _op_(SEIDBAR  ,511 , ECP.LS.SEIDBAR                                   ,FLAG_READ_WRITE ,SPR_PER_PT         ,64)\
    _op_(SIER_RU  ,768 , ECP.PC.T<??T>_SIER                               ,FLAG_READ_ONLY  ,SPR_PER_PT         ,64)\
    _op_(MMCR2_RU ,769 , ECP.PC.T<??T>_MMCR2                              ,FLAG_READ_ONLY  ,SPR_PER_PT         ,64)\
    _op_(MMCRA_RU ,770 , ECP.PC.T<??T>_MMCRA                              ,FLAG_READ_ONLY  ,SPR_PER_PT         ,64)\
    _op_(PMC1_RU  ,771 , ECP.PC.T<??T>_PMC1                               ,FLAG_READ_ONLY  ,SPR_PER_PT         ,32)\
    _op_(PMC2_RU  ,772 , ECP.PC.T<??T>_PMC2                               ,FLAG_READ_ONLY  ,SPR_PER_PT         ,32)\
    _op_(PMC3_RU  ,773 , ECP.PC.T<??T>_PMC3                               ,FLAG_READ_ONLY  ,SPR_PER_PT         ,32)\
    _op_(PMC4_RU  ,774 , ECP.PC.T<??T>_PMC4                               ,FLAG_READ_ONLY  ,SPR_PER_PT         ,32)\
    _op_(PMC5_RU  ,775 , ECP.PC.T<??T>_PMC5                               ,FLAG_READ_ONLY  ,SPR_PER_PT         ,32)\
    _op_(PMC6_RU  ,776 , ECP.PC.T<??T>_PMC6                               ,FLAG_READ_ONLY  ,SPR_PER_PT         ,32)\
    _op_(MMCR0_RU ,779 , ECP.PC.T<??T>_MMCR0                              ,FLAG_READ_ONLY  ,SPR_PER_PT         ,32)\
    _op_(SIAR_RU  ,780 , ECP.IFU.T<??T>_SIAR                              ,FLAG_READ_ONLY  ,SPR_PER_PT         ,64)\
    _op_(SDAR_RU  ,781 , ECP.LS.T<??T>_SDAR                               ,FLAG_READ_ONLY  ,SPR_PER_PT         ,64)\
    _op_(MMCR1_RU ,782 , ECP.PC.T<??T>_MMCR1                              ,FLAG_READ_ONLY  ,SPR_PER_PT         ,32)\
    _op_(SIER     ,784 , ECP.PC.T<??T>_SIER                               ,FLAG_READ_WRITE ,SPR_PER_PT         ,64)\
    _op_(MMCR2    ,785 , ECP.PC.T<??T>_MMCR2                              ,FLAG_READ_WRITE ,SPR_PER_PT         ,64)\
    _op_(MMCRA    ,786 , ECP.PC.T<??T>_MMCRA                              ,FLAG_READ_WRITE ,SPR_PER_PT         ,64)\
    _op_(PMC1     ,787 , ECP.PC.T<??T>_PMC1                               ,FLAG_READ_WRITE ,SPR_PER_PT         ,32)\
    _op_(PMC2     ,788 , ECP.PC.T<??T>_PMC2                               ,FLAG_READ_WRITE ,SPR_PER_PT         ,32)\
    _op_(PMC3     ,789 , ECP.PC.T<??T>_PMC3                               ,FLAG_READ_WRITE ,SPR_PER_PT         ,32)\
    _op_(PMC4     ,790 , ECP.PC.T<??T>_PMC4                               ,FLAG_READ_WRITE ,SPR_PER_PT         ,32)\
    _op_(PMC5     ,791 , ECP.PC.T<??T>_PMC5                               ,FLAG_READ_WRITE ,SPR_PER_PT         ,32)\
    _op_(PMC6     ,792 , ECP.PC.T<??T>_PMC6                               ,FLAG_READ_WRITE ,SPR_PER_PT         ,32)\
    _op_(MMCR0    ,795 , ECP.PC.T<??T>_MMCR0                              ,FLAG_READ_WRITE ,SPR_PER_PT         ,32)\
    _op_(SIAR     ,796 , ECP.IFU.T<??T>_SIAR                              ,FLAG_READ_WRITE ,SPR_PER_PT         ,64)\
    _op_(SDAR     ,797 , ECP.LS.T<??T>_SDAR                               ,FLAG_READ_WRITE ,SPR_PER_PT         ,64)\
    _op_(MMCR1    ,798 , ECP.PC.T<??T>_MMCR1                              ,FLAG_READ_WRITE ,SPR_PER_PT         ,32)\
    _op_(IMC      ,799 , N/A                                              ,FLAG_READ_WRITE ,SPR_SHARED         ,64)\
    _op_(BESCRS   ,800 , ECP.SD.T<??T>_BESCR                              ,FLAG_READ_WRITE ,SPR_PER_PT         ,64)\
    _op_(BESCRSU  ,801 , ECP.SD.T<??T>_BESCR                              ,FLAG_READ_WRITE ,SPR_PER_PT         ,32)\
    _op_(BESCRR   ,802 , ECP.SD.T<??T>_BESCR                              ,FLAG_READ_WRITE ,SPR_PER_PT         ,64)\
    _op_(BESCRRU  ,803 , ECP.SD.T<??T>_BESCR                              ,FLAG_READ_WRITE ,SPR_PER_PT         ,32)\
    _op_(EBBHR    ,804 , ECP.IFU.T<??T>_EBBHR                             ,FLAG_READ_WRITE ,SPR_PER_PT         ,64)\
    _op_(EBBRR    ,805 , ECP.IFU.T<??T>_EBBRR                             ,FLAG_READ_WRITE ,SPR_PER_PT         ,64)\
    _op_(BESCR    ,806 , ECP.SD.T<??T>_BESCR                              ,FLAG_READ_WRITE ,SPR_PER_PT         ,64)\
    _op_(LMRR     ,813 , ECP.LS.T<??T>_LMRR                               ,FLAG_READ_WRITE ,SPR_PER_PT         ,64)\
    _op_(LMSER    ,814 , ECP.LS.T<??T>_LMSER                              ,FLAG_READ_WRITE ,SPR_PER_PT         ,64)\
    _op_(TAR      ,815 , ECP.IFU.T<??T>_TAR                               ,FLAG_READ_WRITE ,SPR_PER_PT         ,64)\
    _op_(ASDR     ,816 , ECP.LS.T<??T>_ASDR                               ,FLAG_READ_WRITE ,SPR_PER_PT         ,64)\
    _op_(PSSCR_SU ,823 , EXP.EC.CC.PCC<??C>.PMC.V<??T>_PSSCR              ,FLAG_READ_WRITE ,SPR_PER_PT         ,64)\
    _op_(IC       ,848 , ECP.PC.T<??T>_IC                                 ,FLAG_READ_WRITE ,SPR_PER_PT         ,64)\
    _op_(VTB      ,849 , EXP.EC.CC.PCC<??C>.L<??T>_VTB                    ,FLAG_READ_WRITE ,SPR_PER_LPAR_VT    ,64)\
    _op_(LDBAR    ,850 , ECP.PC.IMA.L<??T>_LDBAR                          ,FLAG_READ_WRITE ,SPR_PER_LPAR_VT    ,64)\
    _op_(MMCRC    ,851 , ECP.PC.PMU.PMUC.MMCRC                            ,FLAG_READ_WRITE ,SPR_SHARED         ,32)\
    _op_(PMSR     ,853 , EXP.EC.CC.PCC<??C>.COMMON.POW.PMSR               ,FLAG_READ_ONLY  ,SPR_SHARED         ,32)\
    _op_(PMMAR    ,854 , EXP.EC.CC.PCC<??C>.COMMON.POW.PMMAR              ,FLAG_READ_WRITE ,SPR_SHARED         ,64)\
    _op_(PSSCR    ,855 , EXP.EC.CC.PCC<??C>.PMC.V<??T>_PSSCR              ,FLAG_READ_WRITE ,SPR_PER_VT         ,64)\
    _op_(L2QOSR   ,861 , ECP.PC.PC_NW.L<??T>_PMMAR                        ,FLAG_WRITE_ONLY ,SPR_PER_CORE       ,64)\
    _op_(WORC     ,863 , N/A                                              ,FLAG_READ_WRITE ,SPR_SHARED         ,2 )\
    _op_(TRIG0    ,880 , N/A                                              ,FLAG_WRITE_ONLY ,SPR_PER_PT         ,64)\
    _op_(TRIG1    ,881 , N/A                                              ,FLAG_WRITE_ONLY ,SPR_PER_PT         ,64)\
    _op_(TRIG2    ,882 , N/A                                              ,FLAG_WRITE_ONLY ,SPR_PER_PT         ,64)\
    _op_(PMCR     ,884 , EXP.EC.CC.PCC<??C>.COMMON.POW.PMCR               ,FLAG_READ_WRITE ,SPR_PER_CORE       ,64)\
    _op_(RWMR     ,885 , EXP.EC.CC.PCC<??C>.TFDP.TFP.RWMR                 ,FLAG_READ_WRITE ,SPR_SHARED         ,64)\
    _op_(WORT     ,895 , ECP.IFU.T<??T>_WORT                              ,FLAG_READ_WRITE ,SPR_PER_PT         ,18)\
    _op_(PPR      ,896 , ECP.SD.T<??T>_PPR                                ,FLAG_READ_WRITE ,SPR_PER_PT         ,64)\
    _op_(PPR32    ,898 , N/A                                              ,FLAG_READ_WRITE ,SPR_PER_PT         ,32)\
    _op_(TSCR     ,921 , ECP.SD.TSCR                                      ,FLAG_READ_WRITE ,SPR_SHARED         ,32)\
    _op_(TTR      ,922 , ECP.SD.TTR                                       ,FLAG_READ_WRITE ,SPR_SHARED         ,64)\
    _op_(TRACE    ,1006, N/A                                              ,FLAG_WRITE_ONLY ,SPR_SHARED         ,64)\
    _op_(HID      ,1008, ECP.PC.THRCTL.TCTLCOM.HID                        ,FLAG_READ_WRITE ,SPR_SHARED         ,64)\
    _op_(PIR      ,1023, ECP.PC.PMU.SPR_CORE.PIR                          ,FLAG_READ_ONLY  ,SPR_PER_VT         ,32)\
    _op_(NIA      ,2000, ECP.IFU.T<??T>_NIA                               ,FLAG_READ_WRITE ,SPR_PER_PT         ,64)\
    _op_(MSR      ,2001, ECP.SD.T<??T>_MSR                                ,FLAG_READ_WRITE ,SPR_PER_PT         ,64)\
    _op_(CR       ,2002, N/A                                              ,FLAG_READ_WRITE ,SPR_PER_PT         ,32)\
    _op_(FPSCR    ,2003, N/A                                              ,FLAG_READ_WRITE ,SPR_PER_PT         ,64)

#define DO_SPR_MAP(in_name, in_number, in_spy_name, in_flag, in_share_type, in_bit_length)\
    SPRMapEntry entry##in_name; \
    entry##in_name.number = in_number; \
    entry##in_name.spy_name = #in_spy_name; \
    entry##in_name.flag = in_flag; \
    entry##in_name.share_type = in_share_type; \
    entry##in_name.bit_length = in_bit_length; \
    SPR_MAP[#in_name] = entry##in_name;


extern "C" {
//-----------------------------------------------------------------------------------
// Function prototype
//-----------------------------------------------------------------------------------
/// @brief Initial the map between SPR name and SPR number
/// @return TRUE if the mapping completes successfully
//
    bool p9_spr_name_map_init();

//-----------------------------------------------------------------------------------
/// @brief Check read-write mode for a SPR register access
/// @param[in] i_reg_flag => read-write mode of the SPR register
/// @param[in] i_write  => indicate write/read SPR
/// @return TRUE if the check completes successfully
//
    bool p9_spr_name_map_check_flag(unsigned char i_reg_flag, bool i_write);

//-----------------------------------------------------------------------------------
/// @brief Map SPR name to SPR number
/// @param[in] i_name   => SPR name
/// @param[in] i_write  => indicate write/read SPR
/// @param[out] o_number => SPR number
/// @return TRUE if the getting completes successfully
//
    bool p9_spr_name_map(const std::string i_name,
                         const bool i_write,
                         uint32_t& o_number);

//-----------------------------------------------------------------------------------
/// @brief Get share type of SPR
/// @param[in] i_name        => SPR name
/// @param[out] o_share_type => share type
/// @return TRUE if the getting completes successfully
//
    bool p9_get_share_type(const std::string i_name,
                           Enum_ShareType& o_share_type);

//-----------------------------------------------------------------------------------
/// @brief Get bit length of SPR
/// @param[in] i_name        => SPR name
/// @param[out] o_bit_length => bit length
/// @return TRUE if the getting completes successfully
//
    bool p9_get_bit_length(const std::string i_name,
                           uint8_t& o_bit_length);

//-----------------------------------------------------------------------------------
/// @brief Get SPR map entry
/// @param[in] i_name        => SPR name
/// @param[out] o_spr_entry  => SPR map entry
/// @return TRUE if the getting completes successfully
//
    bool p9_get_spr_entry(const std::string i_name,
                          SPRMapEntry& o_spr_entry);

} //extern"C"

#endif //_P9_SPR_NAME_MAP_H_


