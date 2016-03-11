/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/perv/p9_spr_name_map.H $              */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* EKB Project                                                            */
/*                                                                        */
/* COPYRIGHT 2016                                                         */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
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
#include <map>
#include <fapi2.H>

// Read-Write mode flag for each SPR register
const unsigned char FLAG_READ_ONLY  = 0x1;
const unsigned char FLAG_WRITE_ONLY = 0x2;
const unsigned char FLAG_READ_WRITE = 0x3;

//-----------------------------------------------------------------------------------
// Structure definitions
//-----------------------------------------------------------------------------------
typedef struct
{
    int number;
    std::string spy_name;
    // 0x1: read-only; 0x2: write-only; 0x3 read-write
    unsigned char flag;
} SPRMapEntry;


// List all the SPR registers(name, number, spy_name, flag)
// Reference <P9 SPR List.xls> on the P9 care bringup wiki
// Note:
// when ram is enabled, the hardware forces HV=1 PR=0
// current spy names are got from <P9 SPR List.xls>
#define LIST_SPR_REG(_op_)\
    _op_(XER      ,1   , Reserved ,FLAG_READ_WRITE)\
    _op_(DSCR_RU  ,3   , Reserved ,FLAG_READ_WRITE)\
    _op_(LR       ,8   , Reserved ,FLAG_READ_WRITE)\
    _op_(CTR      ,9   , Reserved ,FLAG_READ_WRITE)\
    _op_(UAMR     ,13  , Reserved ,FLAG_READ_WRITE)\
    _op_(DSCR     ,17  , Reserved ,FLAG_READ_WRITE)\
    _op_(DSISR    ,18  , Reserved ,FLAG_READ_WRITE)\
    _op_(DAR      ,19  , Reserved ,FLAG_READ_WRITE)\
    _op_(DEC      ,22  , V_DEC    ,FLAG_READ_WRITE)\
    _op_(SDR1     ,25  , Reserved ,FLAG_READ_WRITE)\
    _op_(SRR0     ,26  , Reserved ,FLAG_READ_WRITE)\
    _op_(SRR1     ,27  , Reserved ,FLAG_READ_WRITE)\
    _op_(CFAR     ,28  , Reserved ,FLAG_READ_WRITE)\
    _op_(AMR      ,29  , Reserved ,FLAG_READ_WRITE)\
    _op_(PIDR     ,48  , Reserved ,FLAG_READ_WRITE)\
    _op_(IAMR     ,61  , Reserved ,FLAG_READ_WRITE)\
    _op_(TFHAR    ,128 , Reserved ,FLAG_READ_WRITE)\
    _op_(TFIAR    ,129 , Reserved ,FLAG_READ_WRITE)\
    _op_(TEXASR   ,130 , Reserved ,FLAG_READ_WRITE)\
    _op_(TEXASRU  ,131 , Reserved ,FLAG_READ_WRITE)\
    _op_(CTRL_RU  ,136 , CTRL     ,FLAG_READ_ONLY )\
    _op_(TIDR     ,144 , CTRL     ,FLAG_READ_WRITE)\
    _op_(CTRL     ,152 , Reserved ,FLAG_WRITE_ONLY)\
    _op_(FSCR     ,153 , Reserved ,FLAG_READ_WRITE)\
    _op_(UAMOR    ,157 , Reserved ,FLAG_READ_WRITE)\
    _op_(GSR      ,158 , Reserved ,FLAG_READ_WRITE)\
    _op_(PSPB     ,159 , V_PSPB   ,FLAG_READ_WRITE)\
    _op_(DPDES    ,176 , DPDES    ,FLAG_READ_WRITE)\
    _op_(DAWR0    ,180 , Reserved ,FLAG_READ_WRITE)\
    _op_(RPR      ,186 , Reserved ,FLAG_READ_WRITE)\
    _op_(CIABR    ,187 , Reserved ,FLAG_READ_WRITE)\
    _op_(DAWRX0   ,188 , Reserved ,FLAG_READ_WRITE)\
    _op_(HFSCR    ,190 , Reserved ,FLAG_READ_WRITE)\
    _op_(VRSAVE   ,256 , Reserved ,FLAG_READ_WRITE)\
    _op_(SPRG3_RU ,259 , T_SPRG3  ,FLAG_READ_ONLY )\
    _op_(TB       ,268 , L_TB     ,FLAG_READ_ONLY )\
    _op_(TBU_RU   ,269 , L_TBU    ,FLAG_READ_ONLY )\
    _op_(SPRG0    ,272 , T_SPRG0  ,FLAG_READ_WRITE)\
    _op_(SPRG1    ,273 , T_SPRG1  ,FLAG_READ_WRITE)\
    _op_(SPRG2    ,274 , T_SPRG2  ,FLAG_READ_WRITE)\
    _op_(SPRG3    ,275 , T_SPRG3  ,FLAG_READ_WRITE)\
    _op_(SPRC     ,276 , Reserved ,FLAG_READ_WRITE)\
    _op_(SPRD     ,277 , Reserved ,FLAG_READ_WRITE)\
    _op_(CIR      ,283 , CIR      ,FLAG_READ_ONLY )\
    _op_(TBL      ,284 , V_TBL    ,FLAG_WRITE_ONLY)\
    _op_(TBLU     ,285 , L_TBU    ,FLAG_WRITE_ONLY)\
    _op_(TBU40    ,286 , L_TBU40  ,FLAG_WRITE_ONLY)\
    _op_(PVR      ,287 , PVR      ,FLAG_READ_ONLY )\
    _op_(HSPRG0   ,304 , T_HSPRG0 ,FLAG_READ_WRITE)\
    _op_(HSPRG1   ,305 , T_HSPRG1 ,FLAG_READ_WRITE)\
    _op_(HDSISR   ,306 , Reserved ,FLAG_READ_WRITE)\
    _op_(HDAR     ,307 , Reserved ,FLAG_READ_WRITE)\
    _op_(SPURR    ,308 , V_SPURR  ,FLAG_READ_WRITE)\
    _op_(PURR     ,309 , V_PURR   ,FLAG_READ_WRITE)\
    _op_(HDEC     ,310 , L_HDEC   ,FLAG_READ_WRITE)\
    _op_(RMOR     ,312 , Reserved ,FLAG_READ_WRITE)\
    _op_(HRMOR    ,313 , Reserved ,FLAG_READ_WRITE)\
    _op_(HSRR0    ,314 , Reserved ,FLAG_READ_WRITE)\
    _op_(HSRR1    ,315 , Reserved ,FLAG_READ_WRITE)\
    _op_(TFMR     ,317 , V_TFMR   ,FLAG_READ_WRITE)\
    _op_(LPCR     ,318 , Reserved ,FLAG_READ_WRITE)\
    _op_(LPIDR    ,319 , Reserved ,FLAG_READ_WRITE)\
    _op_(HMER     ,336 , V_HMER   ,FLAG_READ_WRITE)\
    _op_(HMEER    ,337 , HMEER    ,FLAG_READ_WRITE)\
    _op_(PCR      ,338 , L_PCR    ,FLAG_READ_WRITE)\
    _op_(HEIR     ,339 , Reserved ,FLAG_READ_WRITE)\
    _op_(AMOR     ,349 , Reserved ,FLAG_READ_WRITE)\
    _op_(TIR      ,446 , TIR      ,FLAG_READ_ONLY )\
    _op_(PTCR     ,464 , Reserved ,FLAG_READ_WRITE)\
    _op_(USPRG0   ,496 , Reserved ,FLAG_READ_WRITE)\
    _op_(USPRG1   ,497 , Reserved ,FLAG_READ_WRITE)\
    _op_(UDAR     ,499 , Reserved ,FLAG_READ_WRITE)\
    _op_(SEIDR    ,504 , Reserved ,FLAG_READ_WRITE)\
    _op_(URMOR    ,505 , Reserved ,FLAG_READ_WRITE)\
    _op_(USRR0    ,506 , Reserved ,FLAG_READ_WRITE)\
    _op_(USRR1    ,507 , Reserved ,FLAG_READ_WRITE)\
    _op_(UEIR     ,509 , Reserved ,FLAG_READ_WRITE)\
    _op_(ACMCR    ,510 , Reserved ,FLAG_READ_WRITE)\
    _op_(SEIDBAR  ,511 , Reserved ,FLAG_READ_WRITE)\
    _op_(SIER_RU  ,768 , Reserved ,FLAG_READ_ONLY )\
    _op_(MMCR2_RU ,769 , Reserved ,FLAG_READ_ONLY )\
    _op_(MMCRA_RU ,770 , Reserved ,FLAG_READ_ONLY )\
    _op_(PMC1_RU  ,771 , Reserved ,FLAG_READ_ONLY )\
    _op_(PMC2_RU  ,772 , Reserved ,FLAG_READ_ONLY )\
    _op_(PMC3_RU  ,773 , Reserved ,FLAG_READ_ONLY )\
    _op_(PMC4_RU  ,774 , Reserved ,FLAG_READ_ONLY )\
    _op_(PMC5_RU  ,775 , Reserved ,FLAG_READ_ONLY )\
    _op_(PMC6_RU  ,776 , Reserved ,FLAG_READ_ONLY )\
    _op_(MMCR0_RU ,779 , Reserved ,FLAG_READ_ONLY )\
    _op_(SIAR_RU  ,780 , Reserved ,FLAG_READ_ONLY )\
    _op_(SDAR_RU  ,781 , Reserved ,FLAG_READ_ONLY )\
    _op_(MMCR1_RU ,782 , Reserved ,FLAG_READ_ONLY )\
    _op_(SIER     ,784 , T_SIER   ,FLAG_READ_WRITE)\
    _op_(MMCR2    ,785 , T_MMCR2  ,FLAG_READ_WRITE)\
    _op_(MMCRA    ,786 , T_MMCRA  ,FLAG_READ_WRITE)\
    _op_(PMC1     ,787 , T_PMC1   ,FLAG_READ_WRITE)\
    _op_(PMC2     ,788 , T_PMC2   ,FLAG_READ_WRITE)\
    _op_(PMC3     ,789 , T_PMC3   ,FLAG_READ_WRITE)\
    _op_(PMC4     ,790 , T_PMC4   ,FLAG_READ_WRITE)\
    _op_(PMC5     ,791 , T_PMC5   ,FLAG_READ_WRITE)\
    _op_(PMC6     ,792 , T_PMC6   ,FLAG_READ_WRITE)\
    _op_(MMCR0    ,795 , T_MMCR0  ,FLAG_READ_WRITE)\
    _op_(SIAR     ,796 , Reserved ,FLAG_READ_WRITE)\
    _op_(SDAR     ,797 , Reserved ,FLAG_READ_WRITE)\
    _op_(MMCR1    ,798 , T_MMCR1  ,FLAG_READ_WRITE)\
    _op_(IMC      ,799 , Reserved ,FLAG_READ_WRITE)\
    _op_(BESCRS   ,800 , Reserved ,FLAG_READ_WRITE)\
    _op_(BESCRSU  ,801 , Reserved ,FLAG_READ_WRITE)\
    _op_(BESCRR   ,802 , Reserved ,FLAG_READ_WRITE)\
    _op_(BESCRRU  ,803 , Reserved ,FLAG_READ_WRITE)\
    _op_(EBBHR    ,804 , Reserved ,FLAG_READ_WRITE)\
    _op_(EBBRR    ,805 , Reserved ,FLAG_READ_WRITE)\
    _op_(BESCR    ,806 , Reserved ,FLAG_READ_WRITE)\
    _op_(LMRR     ,813 , Reserved ,FLAG_READ_WRITE)\
    _op_(LMSER    ,814 , Reserved ,FLAG_READ_WRITE)\
    _op_(TAR      ,815 , Reserved ,FLAG_READ_WRITE)\
    _op_(ASDR     ,816 , Reserved ,FLAG_READ_WRITE)\
    _op_(PSSCR_SU ,823 , Reserved ,FLAG_READ_WRITE)\
    _op_(IC       ,848 , T_IC     ,FLAG_READ_WRITE)\
    _op_(VTB      ,849 , L_VTB    ,FLAG_READ_WRITE)\
    _op_(LDBAR    ,850 , L_LDBAR  ,FLAG_READ_WRITE)\
    _op_(MMCRC    ,851 , MMCRC    ,FLAG_READ_WRITE)\
    _op_(PMSR     ,853 , PMSR     ,FLAG_READ_ONLY )\
    _op_(PMMAR    ,854 , PMMAR    ,FLAG_READ_WRITE)\
    _op_(PSSCR    ,855 , V_PSSCR  ,FLAG_READ_WRITE)\
    _op_(L2QOSR   ,861 , L_PMMAR  ,FLAG_WRITE_ONLY)\
    _op_(WORC     ,863 , Reserved ,FLAG_READ_WRITE)\
    _op_(TRIG0    ,880 , Reserved ,FLAG_WRITE_ONLY)\
    _op_(TRIG1    ,881 , Reserved ,FLAG_WRITE_ONLY)\
    _op_(TRIG2    ,882 , Reserved ,FLAG_WRITE_ONLY)\
    _op_(PMCR     ,884 , PMCR     ,FLAG_READ_WRITE)\
    _op_(RWMR     ,885 , PWMR     ,FLAG_READ_WRITE)\
    _op_(WORT     ,895 , Reserved ,FLAG_READ_WRITE)\
    _op_(PPR      ,896 , Reserved ,FLAG_READ_WRITE)\
    _op_(PPR32    ,898 , Reserved ,FLAG_READ_WRITE)\
    _op_(TSCR     ,921 , Reserved ,FLAG_READ_WRITE)\
    _op_(TTR      ,922 , Reserved ,FLAG_READ_WRITE)\
    _op_(TRACE    ,1006, TRACE    ,FLAG_WRITE_ONLY)\
    _op_(HID      ,1008, HID      ,FLAG_READ_WRITE)\
    _op_(PIR      ,1023, PIR      ,FLAG_WRITE_ONLY)

#define DO_SPR_MAP(in_name, in_number, in_spy_name, in_flag)\
    SPRMapEntry entry##in_name; \
    entry##in_name.number = in_number; \
    entry##in_name.spy_name = #in_spy_name; \
    entry##in_name.flag = in_flag; \
    spr_map[#in_name] = entry##in_name;

//-----------------------------------------------------------------------------------
//function pointer typedef definition for HWP call support
typedef fapi2::ReturnCode (*p9_spr_name_map_FP_t) (const std::string i_name, const bool i_write, uint32_t& o_number);


extern "C" {
//-----------------------------------------------------------------------------------
// Function prototype
//-----------------------------------------------------------------------------------
/// @brief Initial the map between SPR name and SPR number
/// @return FAPI_RC_SUCCESS if the mapping completes successfully
//
    fapi2::ReturnCode p9_spr_name_map_init();


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
/// @return FAPI_RC_SUCCESS if the mapping completes successfully
//
    fapi2::ReturnCode p9_spr_name_map(const std::string i_name,
                                      const bool i_write,
                                      uint32_t& o_number);
} //extern"C"

#endif //_P9_SPR_NAME_MAP_H_

