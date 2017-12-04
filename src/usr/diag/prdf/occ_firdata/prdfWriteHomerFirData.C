/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/occ_firdata/prdfWriteHomerFirData.C $       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2017                        */
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

#include <homerData_common.h>

#include <prdfErrlUtil.H>
#include <prdfPlatServices.H>
#include <prdfTrace.H>
#include <prdfWriteHomerFirData.H>

#include <fsi/fsiif.H>
#include <pnor/pnorif.H>
#include <targeting/common/targetservice.H>

using namespace TARGETING;

namespace PRDF
{

using namespace PlatServices;

//------------------------------------------------------------------------------
// Register lists
//------------------------------------------------------------------------------


// TODO RTC 124849: Auto-generate this list from rule code.
// although HDCT plays a role
// currently have a mix from HDCT, P8->P9 manual conversion
// and some other chiplet attn regs


// For creating chiplet exist bit masks
typedef std::map<TrgtPos_t, uint32_t>            typeMaskMap_t;
typedef std::map<TARGETING::TYPE, typeMaskMap_t> typeMaxMap_t;

// For Creating list of registers
typedef std::vector<uint64_t> AddrList_t;
typedef std::map<RegType_t, AddrList_t> RegMap_t;
typedef std::map<TrgtType_t, RegMap_t> TrgtMap_t;


/**
 * @fn void initChipMasks( typeMaxMap_t & io_typeMap )
 *
 * @brief Fills in the SCOM addresses we need for all targets
 *          and for all register types.
 */
void initChipMasks( typeMaxMap_t & io_typeMap,
                    const HOMER_ChipType_t i_procType )
{
    // Creates and Inits the 'exist bit masks' we need
    // for each chiplet type.  The mask is a bit sensitive
    // field with each '1' bit indicating that chiplet
    // is present.
    io_typeMap[TYPE_CAPP][TrgtPos_t::MAX_CAPP_PER_PROC] = 0;
    io_typeMap[TYPE_XBUS][TrgtPos_t::MAX_XBUS_PER_PROC] = 0;
    io_typeMap[TYPE_OBUS][TrgtPos_t::MAX_OBUS_PER_PROC] = 0;
    io_typeMap[TYPE_PEC][TrgtPos_t::MAX_PEC_PER_PROC] = 0;
    io_typeMap[TYPE_PHB][TrgtPos_t::MAX_PHB_PER_PROC] = 0;
    io_typeMap[TYPE_EQ][TrgtPos_t::MAX_EQ_PER_PROC] = 0;
    io_typeMap[TYPE_EX][TrgtPos_t::MAX_EX_PER_PROC] = 0;
    io_typeMap[TYPE_CORE][TrgtPos_t::MAX_EC_PER_PROC] = 0;


    // A few types differ based on processor type
    if (HOMER_CHIP_CUMULUS == i_procType)
    {
        // TODO RTC 173614: for CUMULUS
        // Add when these targeting types are available
        // io_typeMap[TYPE_MC][TrgtPos_t::MAX_MC_PER_PROC] = 0;
        // io_typeMap[TYPE_MI][TrgtPos_t::MAX_MI_PER_PROC] = 0;
        // io_typeMap[TYPE_DMI][TrgtPos_t::MAX_DMI_PER_PROC] = 0;
    }
    else
    {
        // NIMBUS processor
        io_typeMap[TYPE_MCBIST][TrgtPos_t::MAX_MCBIST_PER_PROC] = 0;
        io_typeMap[TYPE_MCS][TrgtPos_t::MAX_MCS_PER_PROC] = 0;
        io_typeMap[TYPE_MCA][TrgtPos_t::MAX_MCA_PER_PROC] = 0;
    } // else NIMBUS


    return;
} // end createChipMasks


/**
 * @fn void getAddresses( TrgtMap_t & io_targMap )
 *
 * @brief Fills in the SCOM addresses we need for all targets
 *          and for all register types.
 */
void getAddresses( TrgtMap_t & io_targMap )
{
    io_targMap[TRGT_PROC][REG_GLBL] =
    {
        0x500F001C, // GLOBAL_CS_FIR
        0x500F001B, // GLOBAL_RE_FIR
        0x50040018, // GLOBAL_UNIT_CS_FIR

        // NOTE: The SPA/HOST_ATTN global/chiplet registers will not be captured
        //       because those attention types are not used for checkstop
        //       analysis.
    };

    io_targMap[TRGT_PHB][REG_FIR] =
    {
        0x04010C40, // PHBNFIR
        0x0D010840, // PCIFIR
        0x0D010908, // ETUFIR
    };

    io_targMap[TRGT_PHB][REG_REG] =
    {
        // c_err_rpt registers
        0x0D01084B, // PBAIB CERR Report Hold Reg
    };

    io_targMap[TRGT_CAPP][REG_FIR] =
    {
        0x02010800, // CXAFIR
    };

    io_targMap[TRGT_CAPP][REG_REG] =
    {
        // c_err_rpt registers
        0x0201080a, // Snoop Error Report Reg
        0x0201080b, // APC CERR Hold
        0x0201080c, // XPT Error Report
        0x0201080d, // TLBI Error Report
        0x0201080e, // Capp Error Status and Ctrl Reg
    };

    io_targMap[TRGT_XBUS][REG_FIR] =
    {
        0x06010c00, // IOXBFIR
        0x06011800, // IOELFIR
    };

    io_targMap[TRGT_XBUS][REG_REG] =
    {
        // c_err_rpt registers
        0x06011816, // PB ELL Link0 ErrStatus
        0x06011817, // PB ELL Link1 ErrStatus
    };

    io_targMap[TRGT_OBUS][REG_GLBL] =
    {
        0x09040000, // OB_CHIPLET_CS_FIR
        0x09040001, // OB_CHIPLET_RE_FIR
        0x09040018, // OB_CHIPLET_UCS_FIR
    };

    io_targMap[TRGT_OBUS][REG_FIR] =
    {
        0x0904000a, // OB LFIR
        0x09010800, // IOOLFIR
        0x09010C00, // IOOBFIR
        0x09011040, // OBPPEFIR
    };

    io_targMap[TRGT_OBUS][REG_REG] =
    {
        // Chiplet FIRs
        0x09040002, // OB_CHIPLET_FIR_MASK
        0x09040019, // OB_CHIPLET_UCS_FIR_MASK

        // PLL registers
        0x090F001E, // OBUS_CONFIG_REG
        0x090F001F, // OBUS_ERROR_REG

        // c_err_rpt registers
        0x09010816, // PB OLL Link0 ErrStatus
        0x09010817, // PB OLL Link1 ErrStatus
    };

    io_targMap[TRGT_PEC][REG_FIR] =
    {
        0x0D04000a, // PCI_LFIR
        0x0D010C00, // IOPCIFIR
    };

    io_targMap[TRGT_PEC][REG_REG] =
    {
        // PLL registers
        0x0D0F001E, // PCI_CONFIG_REG
        0x0D0F001F, // PCI_ERROR_REG
    };

    io_targMap[TRGT_MCS][REG_FIR] =
    {
        0x05010800, // MCIFIR
    };

    io_targMap[TRGT_MCS][REG_REG] =
    {
        // c_err_rpt registers
        0x0501081a, // MC Error Report 2
        0x0501081e, // MC Error Report 0
        0x0501081f, // MC Error Report 1

        // Memory config registers
        0x0501080a, // Primary MemCfg Reg
        0x0501080b, // MCFGPA
        0x0501080c, // MCFGPM
        0x0501080d, // MCFGPMA
    };

    io_targMap[TRGT_MCBIST][REG_GLBL] =
    {
        0x07040000, // MC_CHIPLET_CS_FIR
        0x07040001, // MC_CHIPLET_RE_FIR
        0x07040018, // MC_CHIPLET_UCS_FIR
    };

    io_targMap[TRGT_MCBIST][REG_FIR] =
    {
        0x0704000A, // MC_LFIR
        0x07012300, // MCBISTFIR
    };

    io_targMap[TRGT_MCA][REG_FIR] =
    {
        0x07010900, // MCACALFIR
        0x07010A00, // MCAECCFIR
        0x07011000, // DDRPHYFIR
    };

    io_targMap[TRGT_MCBIST][REG_REG] =
    {
        // Chiplet FIRs
        0x07040002, // MC_CHIPLET_FIR_MASK
        0x07040019, // MC_CHIPLET_UCS_FIR_MASK

        // PLL registers
        0x070F001E, // MC_CONFIG_REG
        0x070F001F, // MC_ERROR_REG

        // AUE/IAUE analysis
        0x0701236D, // MCB0_MBUER
        0x0701236E, // MCB0_MBAUER
        0x07012372, // MCB1_MBUER
        0x07012373, // MCB1_MBAUER
        0x07012377, // MCB2_MBUER
        0x07012378, // MCB2_MBAUER
        0x0701237C, // MCB3_MBUER
        0x0701237D, // MCB3_MBAUER
        0x070123D7, // MCBMCAT
    };

    io_targMap[TRGT_EQ][REG_GLBL] =
    {
        0x10040000, // EQ_CHIPLET_CS_FIR
        0x10040001, // EQ_CHIPLET_RE_FIR
    };

    io_targMap[TRGT_EQ][REG_FIR] =
    {
        0x1004000A, // EQ_LFIR
    };

    io_targMap[TRGT_EQ][REG_REG] =
    {
        // Chiplet FIRs
        0x10040002, // EQ_CHIPLET_FIR_MASK

        // PLL registers
        0x100F001E, // EQ_CONFIG_REG
        0x100F001F, // EQ_ERROR_REG
    };

    io_targMap[TRGT_PROC][REG_FIR] =
    {
        0x0104000a, // TP_LFIR
        0x01010800, // OCCFIR

        0x0204000a, // N0_LFIR
        0x02011080, // NXCQFIR
        0x02011100, // NXDMAENGFIR

        0x0304000a, // N1_LFIR
        0x03011000, // MCDFIR_0
        0x03011400, // MCDFIR_1
        0x03011800, // VASFIR

        0x0404000a, // N2_LFIR
        0x04011800, // PSIFIR

        0x0504000a, // N3_LFIR
        0x05011800, // PBWESTFIR
        0x05011C00, // PBCENTFIR
        0x05012000, // PBEASTFIR
        0x05012400, // PBPPEFIR
        0x05012840, // PBAFIR
        0x05012900, // PSIHBFIR
        0x05012940, // ENHCAFIR
        0x050129C0, // PBAMFIR
        0x05012C00, // NMMUCQFIR
        0x05012C40, // NMMUFIR
        0x05013030, // INTCQFIR
        0x05013400, // PBIOEFIR
        0x05013800, // PBIOOFIR

        0x0604000a, // XBUS_LFIR
        0x06010840, // XBPPEFIR
    };

    io_targMap[TRGT_PROC][REG_REG] =
    {
        // Global FIRs
        0x500F001A, // GLOBAL_SPA (FFDC only, in case there was a TI)

        // Chiplet FIRs
        0x01040000, // TP_CHIPLET_CS_FIR
        0x01040001, // TP_CHIPLET_RE_FIR
        0x01040002, // TP_CHIPLET_FIR_MASK

        0x02040000, // N0_CHIPLET_CS_FIR
        0x02040001, // N0_CHIPLET_RE_FIR
        0x02040002, // N0_CHIPLET_FIR_MASK
        0x02040018, // N0_CHIPLET_UCS_FIR
        0x02040019, // N0_CHIPLET_UCS_FIR_MASK

        0x03040000, // N1_CHIPLET_CS_FIR
        0x03040001, // N1_CHIPLET_RE_FIR
        0x03040002, // N1_CHIPLET_FIR_MASK
        0x03040018, // N1_CHIPLET_UCS_FIR
        0x03040019, // N1_CHIPLET_UCS_FIR_MASK

        0x04040000, // N2_CHIPLET_CS_FIR
        0x04040001, // N2_CHIPLET_RE_FIR
        0x04040002, // N2_CHIPLET_FIR_MASK
        0x04040018, // N2_CHIPLET_UCS_FIR
        0x04040019, // N2_CHIPLET_UCS_FIR_MASK

        0x05040000, // N3_CHIPLET_CS_FIR
        0x05040001, // N3_CHIPLET_RE_FIR
        0x05040002, // N3_CHIPLET_FIR_MASK
        0x05040018, // N3_CHIPLET_UCS_FIR
        0x05040019, // N3_CHIPLET_UCS_FIR_MASK

        0x06040000, // XB_CHIPLET_CS_FIR
        0x06040001, // XB_CHIPLET_RE_FIR
        0x06040002, // XB_CHIPLET_FIR_MASK
        0x06040018, // XB_CHIPLET_UCS_FIR
        0x06040019, // XB_CHIPLET_UCS_FIR_MASK

        // Chiplet FIRs
        0x0D040000, // PCI0_CHIPLET_CS_FIR
        0x0D040001, // PCI0_CHIPLET_RE_FIR
        0x0D040002, // PCI0_CHIPLET_FIR_MASK
        0x0E040000, // PCI1_CHIPLET_CS_FIR
        0x0E040001, // PCI1_CHIPLET_RE_FIR
        0x0E040002, // PCI1_CHIPLET_FIR_MASK
        0x0F040000, // PCI2_CHIPLET_CS_FIR
        0x0F040001, // PCI2_CHIPLET_RE_FIR
        0x0F040002, // PCI2_CHIPLET_FIR_MASK

        // Misc registers needed for PRD analysis
        0x05011C2E, // PBEXTFIR (does not raise attn, used for fabric sorting)
        0x05011C0A, // PB_CENT_MODE
        0x00040020, // TODWOF

        // PLL registers
        0x010F001E, // TP_CONFIG_REG
        0x010F001F, // TP_ERROR_REG
        0x060F001E, // XBUS_CONFIG_REG
        0x060F001F, // XBUS_ERROR_REG

        // c_err_rpt registers
        0x0101080a, // OCC Error Report Reg
        0x020110a1, // PB Error Report
        0x020110a2, // PB Pty Error Report
        0x02011057, // DMA CERR 0
        0x02011058, // DMA CERR 1
        0x05011c2c, // PB Cent CR ERROR
        0x0501284c, // PBA Err Report0
        0x0501284d, // PBA Err Report1
        0x0501284e, // PBA Err Report2
        0x05012C22, // PB Pty Error Report

        // TOD registers
        0x00040005, // TOD: Slave path ctrl reg
        0x00040006, // TOD: Internal path ctrl reg
        0x00040007, // TOD: primary/secondary config ctrl
        0x00040008, // TOD: PSS MSS Status Reg
        0x00040009, // TOD: Master Path Status Reg
        0x0004000E, // TOD: Master Path0 Step Steering
        0x0004000F, // TOD: Master Path1 Step Steering
        0x0004001D, // TOD: Trace dataset 1
        0x0004001E, // TOD: Trace dataset 2
        0x0004001F, // TOD: Trace dataset 3
        0x01020019, // OSC Error Hold
        0x0102001A, // OSC Error Mask
        0x0102001B, // OSC Error Mode
        0x00040024, // TOD:FSM Register
        0x00040027, // TOD: TX TType Ctrl reg
        0x00040029, // TOD: RX TType Ctrl reg
        0x00040030, // TOD: Error and Interrupts
        0x00040032, // TOD: C_Err_Rpt
        0x00040033, // TOD: Route Errors to Core/FIR
    };

    io_targMap[TRGT_EC][REG_GLBL] =
    {
        0x20040000, // EC_CHIPLET_CS_FIR
        0x20040001, // EC_CHIPLET_RE_FIR
        0x20040018, // EC_CHIPLET_UCS_FIR
    };

    io_targMap[TRGT_EC][REG_FIR] =
    {
        0x2004000A, // EC_LFIR
        0x20010A40, // COREFIR
    };

    io_targMap[TRGT_EC][REG_REG] =
    {
        // Chiplet FIRs
        0x20040002, // EC_CHIPLET_FIR_MASK
        0x20040019, // EC_CHIPLET_UCS_FIR_MASK

        // Local FIRs
        0x20010A48, // COREFIR_WOF (required for analysis)

        // PLL registers
        0x200F001E, // EC_CONFIG_REG
        0x200F001F, // EC_ERROR_REG

        // Misc
        0x20010A96, // HOMER_ENABLE
        0x20010A99, // SPEC_ATTN_REASON
        0x20010A9A, // SPEC_ATTN_REASON_MASK

        // c_err_rpt registers
        0x20010AB5, // SPR Core Error Report Hold Out Reg
        0x20010AB6, // PMU Error Report Hold Out Register
        0x20010AB7, // TFAC Error Report Hold Out Register
        0x20010AB8, // SPR Common Error Report Hold Out Register
        0x20010C00, // IFU Error Report Hold Out 0 Register
        0x20010C01, // IFU Error Report Hold Out 1 Register
        0x20010C02, // IFU Error Report Hold Out 2 Register
        0x20010C03, // IFU Error Report Hold Out 3 Register
        0x20010C40, // ISU error report hold_out register 0
        0x20010C41, // ISU error report hold_out register 1
        0x20010C42, // ISU error report hold_out register 2
        0x20010C43, // ISU error report hold_out register 3
        0x20010C44, // ISU error report hold_out register 4
        0x20010C45, // ISU error report hold_out register 5
        0x20010C80, // LSU error report hold_out register 0
        0x20010C81, // LSU error report hold_out register 1
        0x20010C82, // LSU error report hold_out register 2
        0x20010C83, // LSU error report hold_out register 3
        0x20010A51, // FIR/RECOV Error Report Hold Out Register
        0x20010A03, // Thread Control Error Report Hold Out Register
        0x200F0110, // PPM STOP_STATE_HIST_SRC_REG
    };

    io_targMap[TRGT_EX][REG_FIR] =
    {
        0x10010800, // L2FIR
        0x10011000, // NCUFIR
        0x10011800, // L3FIR
        0x10012000, // CMEFIR
    };

    io_targMap[TRGT_EX][REG_REG] =
    {
        // c_err_rpt registers
        0x10010812, // ERROR REPORT REGISTER0
        0x10010813, // ERROR REPORT REGISTER1
        0x1001100E, // NCU error rpt register
        0x1001180E, // L3 PRD Purge Register
        0x10011810, // L3 Error Report Reg 0
        0x10011817, // L3 Error Report Reg 1
        0x10011819, // L3 eDRAM RD Err Stat Reg0
        0x1001181A, // L3 eDRAM RD Err Stat Reg1
        0x1001181B, // L3 Edram Bank Fail
    };

/* TODO: RTC 177481
    // These are all Centaur addresses below
    // (Should match P8 except for global broadcast FIRs)
    io_targMap[TRGT_MEMBUF][REG_GLBL] =
    {
        0x500F001C, // GLOBAL_CS_FIR
        0x500F001B, // GLOBAL_RE_FIR
    };

    io_targMap[TRGT_MEMBUF][REG_FIR] =
    {
        0x0104000a, // TP_LFIR
        0x02010400, // DMIFIR
        0x02010800, // MBIFIR
        0x02011400, // MBSFIR
        0x02011440, // MBA0_MBSECCFIR
        0x02011480, // MBA1_MBSECCFIR
        0x020115c0, // SCACFIR
        0x02011600, // MBA0_MCBISTFIR
        0x02011700, // MBA1_MCBISTFIR
        0x0204000a, // NEST_LFIR
        0x0304000a, // MEM_LFIR
    };

    io_targMap[TRGT_MEMBUF][REG_REG] =
    {
        // Global FIRs
        0x500F001A, // GLOBAL_SPA (for FFDC only)

        // Chiplet FIRs
        0x01040000, // TP_CHIPLET_CS_FIR
        0x01040001, // TP_CHIPLET_RE_FIR
        0x01040002, // TP_CHIPLET_FIR_MASK
        0x02040000, // NEST_CHIPLET_CS_FIR
        0x02040001, // NEST_CHIPLET_RE_FIR
        0x02040002, // NEST_CHIPLET_FIR_MASK

        0x03040000, // MEM_CHIPLET_CS_FIR
        0x03040001, // MEM_CHIPLET_RE_FIR
        0x03040002, // MEM_CHIPLET_FIR_MASK
        0x03040004, // MEM_CHIPLET_SPA (for FFDC only)
        0x03040007, // MEM_CHIPLET_SPA_MASK (for FFDC only)

        // FIRs for FFDC only
        0x02010880, // NESTFBISTFIR
        0x0201141e, // MBSSECUREFIR

        // c_err_rpt and extra FFDC registers
        0x01030009, // TP_ERROR_STATUS
        0x0201080F, // MBIERPT
        0x0201140A, // MBSXCR
        0x0201140B, // MBA0_MBAXCR
        0x0201140C, // MBA1_MBAXCR
        0x02011413, // MBSCERR1
        0x02011416, // MBCELOG
        0x0201142C, // MBSCERR2
        0x02011466, // MBA0_MBSECCERRPT_0
        0x02011467, // MBA0_MBSECCERRPT_1
        0x020114A6, // MBA1_MBSECCERRPT_0
        0x020114A7, // MBA1_MBSECCERRPT_1
        0x020115D4, // SENSORCACHEERRPT
        0x0201168f, // MBA0_MBXERRSTAT
        0x0201178f, // MBA1_MBXERRSTAT
        0x02030009, // NEST_ERROR_STATUS
        0x03030009, // MEM_ERROR_STATUS
        0x020115D4, // SensorCache ERR report

        // ECC address registers (will be used in analysis).
        0x0201165f, // MBA0_MBSEVR
        0x02011660, // MBA0_MBNCER
        0x02011661, // MBA0_MBRCER
        0x02011662, // MBA0_MBMPER
        0x02011663, // MBA0_MBUER
        0x0201175f, // MBA1_MBSEVR
        0x02011760, // MBA1_MBNCER
        0x02011761, // MBA1_MBRCER
        0x02011762, // MBA1_MBMPER
        0x02011763, // MBA1_MBUER

        // Other ECC regs (won't be used in analysis, but could be useful FFDC)
        0x02011653, // MBA0_MBSEC0
        0x02011654, // MBA0_MBSEC1
        0x02011655, // MBA0_MBSTR
        0x02011656, // MBA0_MBSSYMEC0
        0x02011657, // MBA0_MBSSYMEC1
        0x02011658, // MBA0_MBSSYMEC2
        0x02011659, // MBA0_MBSSYMEC3
        0x0201165a, // MBA0_MBSSYMEC4
        0x0201165b, // MBA0_MBSSYMEC5
        0x0201165c, // MBA0_MBSSYMEC6
        0x0201165d, // MBA0_MBSSYMEC7
        0x0201165e, // MBA0_MBSSYMEC8
        0x02011753, // MBA1_MBSEC0
        0x02011754, // MBA1_MBSEC1
        0x02011755, // MBA1_MBSTR
        0x02011756, // MBA1_MBSSYMEC0
        0x02011757, // MBA1_MBSSYMEC1
        0x02011758, // MBA1_MBSSYMEC2
        0x02011759, // MBA1_MBSSYMEC3
        0x0201175a, // MBA1_MBSSYMEC4
        0x0201175b, // MBA1_MBSSYMEC5
        0x0201175c, // MBA1_MBSSYMEC6
        0x0201175d, // MBA1_MBSSYMEC7
        0x0201175e, // MBA1_MBSSYMEC8

        // Others from HDCT
        0x00010000, // EFUSE part0
        0x00010001, // EFUSE part1
        0x000F001A, // Int reg
    };

    io_targMap[TRGT_MBA][REG_FIR] =
    {
        0x03010600, // MBAFIR
        0x03010400, // MBACALFIR
    };

    io_targMap[TRGT_MBA][REG_REG] =
    {
        0x0301041B, // MBASECUREFIR
        0x03010611, // MBASPA (for FFDC only)
        0x03010614, // MBASPA_MASK (for FFDC only)

        0x0301041A, // MBA_ERR_REPORT
        0x030106E7, // MBA_MCBERRPTQ

        // Scrub registers (won't be used in analysis, but could be useful FFDC)
        0x0301060A, // MBMCT
        0x0301060C, // MBMSR
        0x0301060D, // MBMACA
        0x0301060E, // MBMEA
        0x0301060F, // MBASCTL
        0x03010610, // MBAECTL
    };

    io_targMap[TRGT_MBA][REG_IDFIR] =
    {
        0x800200900301143Fll, // MBADDRPHYFIR
    };

    io_targMap[TRGT_MBA][REG_IDREG] =
    {
        0x8000D0060301143Fll, // DDRPHY_APB_FIR_ERR0_P0
        0x8000D0070301143Fll, // DDRPHY_APB_FIR_ERR1_P0
        0x8001D0060301143Fll, // DDRPHY_APB_FIR_ERR0_P1
        0x8001D0070301143Fll, // DDRPHY_APB_FIR_ERR1_P1
    };
*/

    // EC level handling will be done with a
    // structure and separate register count field.

} // end getAddresses


//------------------------------------------------------------------------------

errlHndl_t getPnorInfo( HOMER_Data_t & o_data )
{
    #define FUNC "[PRDF::getPnorInfo] "

    errlHndl_t errl = NULL;

    //----------------------------------------------------------------------
    // Get the PNOR information.
    //----------------------------------------------------------------------
    do
    {
        PNOR::SectionInfo_t sectionInfo;
        errl = PNOR::getSectionInfo( PNOR::FIRDATA, sectionInfo );
        if ( NULL != errl )
        {
            PRDF_ERR( FUNC "getSectionInfo() failed" );
            break;
        }

        PNOR::PnorInfo_t pnorInfo;
        PNOR::getPnorInfo( pnorInfo );

        // Saving the flash workarounds in an attribute for when we
        // call getPnorInfo() in the runtime code.
        // Using sys target
        Target* sys = NULL;
        targetService().getTopLevelTarget( sys );
        assert(sys != NULL);

        sys->setAttr<ATTR_PNOR_FLASH_WORKAROUNDS>(pnorInfo.norWorkarounds);

        o_data.pnorInfo.pnorOffset      = sectionInfo.flashAddr;
        o_data.pnorInfo.pnorSize        = sectionInfo.size;
        o_data.pnorInfo.mmioOffset      = pnorInfo.mmioOffset;
        o_data.pnorInfo.norWorkarounds  = pnorInfo.norWorkarounds;
    }while(0);

    return errl;

    #undef FUNC
}

//------------------------------------------------------------------------------

/* Helper struct for chip information inserted into HOMER data section after the
 * header. There is basically an array of these after the initial HOMER section
 * (HOMER_Data_t).  The register info then follows.
 */
typedef struct __attribute__((packed))
{
    HOMER_Chip_t  hChipType;  /* Nimbus, Centaur, EC Level, etc...*/

    union
    {
        HOMER_ChipNimbus_t   hChipN;
        HOMER_ChipCumulus_t  hChipC;
        HOMER_ChipCentaur_t  hChipM;
    };

} HOMER_ChipInfo_t;

//------------------------------------------------------------------------------

errlHndl_t getHwConfig( std::vector<HOMER_ChipInfo_t> &io_chipInfVector,
                        const HwInitialized_t i_curHw )
{
    #define FUNC "[PRDF::getHwConfig] "

    errlHndl_t errl = NULL;

    do
    {
        //----------------------------------------------------------------------
        // Get hardware config information.
        //----------------------------------------------------------------------

        // Get the master PROC position.
        TARGETING::TargetHandle_t  masterProc = getMasterProc();
        PRDF_ASSERT( NULL != masterProc );

        // Should be able to build up at least one chip structure
        FSI::FsiLinkInfo_t  fsiInfo;
        HOMER_ChipInfo_t    l_chipItem;
        HOMER_ChipType_t    l_procModelType;

        l_procModelType = (MODEL_CUMULUS == getChipModel(masterProc)) ?
                           HOMER_CHIP_CUMULUS : HOMER_CHIP_NIMBUS;

        // Iterate the list of functional PROCs.
        TargetHandleList procList = getFunctionalTargetList( TYPE_PROC );
        for ( TargetHandleList::iterator procIt = procList.begin();
              procIt != procList.end(); ++procIt )
        {
            // Init chiplet masks
            memset( &(l_chipItem.hChipN), 0x00, sizeof(l_chipItem.hChipN) );

            // Determine which processor
            uint32_t procPos = getTargetPosition(*procIt);
            PRDF_ASSERT( procPos < MAX_PROC_PER_NODE );

            // Get the PROC FSI address.
            FSI::getFsiLinkInfo( *procIt, fsiInfo );

            // Fill in our HOMER chip info
            l_chipItem.hChipType = HOMER_getChip(l_procModelType);
            l_chipItem.hChipType.chipPos  = procPos;
            l_chipItem.hChipType.fsiBaseAddr = fsiInfo.baseAddr;

            // save EC level for the chip
            l_chipItem.hChipType.chipEcLevel = (*procIt)->getAttr<ATTR_EC>();

            // is this the MASTER processor ?
            l_chipItem.hChipN.isMaster = (*procIt == masterProc) ? 1 : 0;

            std::map<TARGETING::TYPE, typeMaskMap_t>::const_iterator  typePosIt;
            std::map<TrgtPos_t, uint32_t>::const_iterator    maskIt;

            typeMaxMap_t  l_typeMaxMap;

            // Init chiplet exist bit maps
            initChipMasks(l_typeMaxMap, l_procModelType);

            // Loop thru all chiplet types and fill in the
            // exist bit maps.
            for ( typePosIt=l_typeMaxMap.begin();
                  (typePosIt  != l_typeMaxMap.end());
                   typePosIt++ )
            {
                for ( maskIt=typePosIt->second.begin();
                      (maskIt != typePosIt->second.end());  maskIt++ )
                {
                    TargetHandleList chipletList = getConnected(*procIt,
                                                           typePosIt->first);

                    for ( TargetHandleList::iterator chipIt=chipletList.begin();
                                      chipIt != chipletList.end(); ++chipIt )
                    {
                        uint32_t chipPos = getTargetPosition( *chipIt );
                        PRDF_ASSERT( chipPos < maskIt->first );

                        // If right justified, it fits bit fields well
                        l_typeMaxMap[typePosIt->first][ maskIt->first] |=
                                   0x00000001 << (maskIt->first - chipPos - 1);

                    } // end for on chiplet list

                } // end for loop on mask

            } // end for loop on type

            // Need to move the 32 bit chiplet mask into the HOMER defined masks
            // (take all the processor ones to start)
            l_chipItem.hChipN.xbusMask =
                        l_typeMaxMap[TYPE_XBUS][TrgtPos_t::MAX_XBUS_PER_PROC];
            l_chipItem.hChipN.obusMask =
                        l_typeMaxMap[TYPE_OBUS][TrgtPos_t::MAX_OBUS_PER_PROC];
            l_chipItem.hChipN.ecMask   =
                        l_typeMaxMap[TYPE_CORE][TrgtPos_t::MAX_EC_PER_PROC];
            l_chipItem.hChipN.eqMask   =
                        l_typeMaxMap[TYPE_EQ][TrgtPos_t::MAX_EQ_PER_PROC];
            l_chipItem.hChipN.exMask   =
                        l_typeMaxMap[TYPE_EX][TrgtPos_t::MAX_EX_PER_PROC];

            l_chipItem.hChipN.cappMask =
                        l_typeMaxMap[TYPE_CAPP][TrgtPos_t::MAX_CAPP_PER_PROC];
            l_chipItem.hChipN.pecMask  =
                        l_typeMaxMap[TYPE_PEC][TrgtPos_t::MAX_PEC_PER_PROC];
            l_chipItem.hChipN.phbMask  =
                        l_typeMaxMap[TYPE_PHB][TrgtPos_t::MAX_PHB_PER_PROC];

            // Are we suppose to include memory ?
            if (ALL_PROC_MEM_MASTER_CORE == i_curHw || ALL_HARDWARE == i_curHw)
            {
                // We already have the MCBIST, MCS and MCA masks
                // so just save them now into HOMER defined masks..

                // Handle proc type
                if (HOMER_CHIP_NIMBUS == l_procModelType)
                {
                    l_chipItem.hChipN.mcbistMask =
                      l_typeMaxMap[TYPE_MCBIST][TrgtPos_t::MAX_MCBIST_PER_PROC];
                    l_chipItem.hChipN.mcsMask  =
                      l_typeMaxMap[TYPE_MCS][TrgtPos_t::MAX_MCS_PER_PROC];
                    l_chipItem.hChipN.mcaMask  =
                      l_typeMaxMap[TYPE_MCA][TrgtPos_t::MAX_MCA_PER_PROC];
                } // end nimbus proc
                else
                {   // Assuming CUMULUS here
                    // TODO RTC 173614: for CUMULUS
                    // Add when these targeting types are available
                    // l_chipItem.hChipC.mcMask  =
                    //   l_typeMaxMap[TYPE_MC][TrgtPos_t::MAX_MC_PER_PROC];
                    // l_chipItem.hChipC.miMask  =
                    //   l_typeMaxMap[TYPE_MI][TrgtPos_t::MAX_MI_PER_PROC];
                    // l_chipItem.hChipC.dmiMask =
                    //   l_typeMaxMap[TYPE_DMI][TrgtPos_t::MAX_DMI_PER_PROC];
                } // end cumulus proc

            } // if all hw or memory included

            // save the PROC info we collected
            io_chipInfVector.push_back(l_chipItem);

        } // for on processor chips


        // Are we suppose to include memory  -- then check Centaurs
        if (ALL_PROC_MEM_MASTER_CORE == i_curHw || ALL_HARDWARE == i_curHw)
        {
            // Iterate the connected MEMBUFs.
            TargetHandleList membList = getFunctionalTargetList( TYPE_MEMBUF );
            for ( TargetHandleList::iterator membIt = membList.begin();
                    membIt != membList.end(); ++membIt )
            {
                uint32_t membPos = getTargetPosition(*membIt);
                PRDF_ASSERT( membPos < MAX_MEMBUF_PER_NODE );

                // Get the MEMBUF FSI address.
                getFsiLinkInfo( *membIt, fsiInfo );

                // save EC level for the chip
                l_chipItem.hChipType.chipEcLevel=(*membIt)->getAttr<ATTR_EC>();

                // Fill in our HOMER chip info
                l_chipItem.hChipType = HOMER_getChip(HOMER_CHIP_CENTAUR);
                l_chipItem.hChipType.chipPos  = membPos;
                l_chipItem.hChipType.fsiBaseAddr = fsiInfo.baseAddr;

                // Init MBA chiplet masks
                uint32_t l_mbaMask = 0;
                memset( &(l_chipItem.hChipM),
                        0x00,
                        sizeof(l_chipItem.hChipM) );

                // Iterate the connected MBAs.
                TargetHandleList mbaList = getConnected(*membIt, TYPE_MBA );
                for ( TargetHandleList::iterator mbaIt = mbaList.begin();
                        mbaIt != mbaList.end(); ++mbaIt )
                {
                    uint32_t mbaPos = getTargetPosition(*mbaIt);
                    PRDF_ASSERT( mbaPos < MAX_MBA_PER_MEMBUF );

                    l_mbaMask |= 0x00000001 << (MAX_MBA_PER_MEMBUF - mbaPos -1);
                }

                // save the MBA chiplets in HOMER format
                l_chipItem.hChipM.mbaMask = l_mbaMask;

                // save the Centaur chip in our structure
                io_chipInfVector.push_back(l_chipItem);

            } // for on MEMBUF

        } // end if including memory -- centaur and mba


    } while (0);

    return errl;

    #undef FUNC
} // end getHwConfig

//------------------------------------------------------------------------------

/***************************************************/
/* Define EC level dependent registers here        */
/*   chipType         Target     RegType  EC level */
/*     Unused  - scomAddress                       */
/***************************************************/
static HOMER_ChipSpecAddr_t  s_ecDepProcRegisters[]
{
    { HOMER_CHIP_NIMBUS, TRGT_PROC, REG_FIR, 0x10,
      0, 0x0000000005011400ll }, // NPU0FIR DD1

    { HOMER_CHIP_NIMBUS, TRGT_PROC, REG_FIR, 0x10,
      0, 0x0000000005011440ll }, // NPU1FIR DD1

    { HOMER_CHIP_NIMBUS, TRGT_PROC, REG_FIR, 0x20,
      0, 0x0000000005013C00ll }, // NPU0FIR DD2

    { HOMER_CHIP_NIMBUS, TRGT_PROC, REG_FIR, 0x20,
      0, 0x0000000005013C40ll }, // NPU1FIR DD2

    { HOMER_CHIP_NIMBUS, TRGT_PROC, REG_FIR, 0x20,
      0, 0x000000005013C80ll },  // NPU2FIR DD2

    { HOMER_CHIP_NIMBUS, TRGT_PROC, REG_FIR, 0x21,
      0, 0x0000000005013C00ll }, // NPU0FIR DD2.1

    { HOMER_CHIP_NIMBUS, TRGT_PROC, REG_FIR, 0x21,
      0, 0x0000000005013C40ll }, // NPU1FIR DD2.1

    { HOMER_CHIP_NIMBUS, TRGT_PROC, REG_FIR, 0x21,
      0, 0x000000005013C80ll },  // NPU2FIR DD2.1

    { HOMER_CHIP_NIMBUS, TRGT_PROC, REG_FIR, 0x22,
      0, 0x0000000005013C00ll }, // NPU0FIR DD2.2

    { HOMER_CHIP_NIMBUS, TRGT_PROC, REG_FIR, 0x22,
      0, 0x0000000005013C40ll }, // NPU1FIR DD2.2

    { HOMER_CHIP_NIMBUS, TRGT_PROC, REG_FIR, 0x22,
      0, 0x000000005013C80ll }   // NPU2FIR DD2.2
};

//------------------------------------------------------------------------------
errlHndl_t  homerVerifySizeFits( const size_t i_maxSize,
                                 const size_t i_currentSize )
{
    errlHndl_t  l_errl = NULL;


    // Verify we haven't exceeded max size
    if ( i_currentSize > i_maxSize )
    {
        PRDF_ERR( "HOMER SIZE issue: curDataSize %d is greater than max "
                 "HOMER data %d", i_currentSize, i_maxSize );
        /*@
         * @errortype
         * @reasoncode PRDF_INVALID_CONFIG
         * @severity   ERRL_SEV_UNRECOVERABLE
         * @moduleid   PRDF_CS_FIRDATA_WRITE
         * @userdata1  Size needed
         * @userdata2  Size available
         * @devdesc    Invalid configuration in CS FIR Data handling.
         */
        l_errl = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                          PRDF_CS_FIRDATA_WRITE,
                                          PRDF_INVALID_CONFIG,
                                          i_currentSize,
                                          i_maxSize );
    } // end if too big of size

    return(l_errl);

} // end routine  homerVerifySizeFits

//------------------------------------------------------------------------------

errlHndl_t writeData( uint8_t * i_hBuf, size_t i_hBufSize,
                      const HwInitialized_t i_curHw,
                      std::vector<HOMER_ChipInfo_t> &i_chipVector,
                      HOMER_Data_t  &io_homerData )
{
    #define FUNC "[PRDF::writeData] "

    errlHndl_t errl = NULL;
    TrgtMap_t  l_targMap;

    const size_t u32 = sizeof(uint32_t);
    const size_t u64 = sizeof(uint64_t);

    do
    {
        size_t sz_hBuf = 0;

        // Grab size of all the registers being collected
        size_t sz_data = sizeof(io_homerData);
        sz_hBuf += sz_data;

        // The HOMER_Data_t struct may have an uneven size. Add some padding to
        // ensure the subsequent HOMER_Chip_t structs are word aligned. */
        const size_t padding = (u32 - (sizeof(HOMER_Data_t) % u32)) % u32;
        sz_hBuf += padding;

        // Add register counts to the data.
        // initialize SCOM addresses for all targets & regs
        getAddresses(l_targMap);

        // loop thru targets to get register counts
        for ( auto & t : l_targMap )
        {
            // loop thru register types
            for ( auto & r : t.second )
            {
                // TODO RTC 173614:
                // For CUMULUS  Add memory targets

                // Want all proc chiplets but only include
                // memory when asked for
                if ( (ALL_PROC_MEM_MASTER_CORE == i_curHw) ||
                     (ALL_HARDWARE == i_curHw)             ||
                     ( (TRGT_MCBIST != t.first) &&
                       (TRGT_MCS != t.first)    &&
                       (TRGT_MCA != t.first)    &&
                       (TRGT_MEMBUF != t.first) &&
                       (TRGT_MBA != t.first)
                     )
                   )
                {
                    // save the number of regs for target/regType
                    io_homerData.regCounts[t.first][r.first] =
                      r.second.size();
                } // end if need this target included

            } // end for on regTypes

        } // end for on Targets


        // Setup EC level dependent register counts
        // (currently just proc has some)
        io_homerData.ecDepCounts =
                    sizeof(s_ecDepProcRegisters) / sizeof(HOMER_ChipSpecAddr_t);

        // Add everything to the buffer.
        uint32_t idx = 0;

        // Fill in the header & number of chips
        io_homerData.header = HOMER_FIR2;
        io_homerData.chipCount = i_chipVector.size();
        // Fill the input buffer with chipcount, regcount, pnor info
        memcpy( &i_hBuf[idx], &io_homerData,  sz_data   ); idx += sz_data;

        // Add the padding at the end of the HOMER_Data_t struct.
        idx += padding;

        // We want a list of chips next
        if (0 != io_homerData.chipCount)
        {
            // Roll thru the chips we have
            std::vector<HOMER_ChipInfo_t>::iterator  l_chipItr;
            uint32_t  l_chipTypeSize = sizeof(HOMER_Chip_t);

            for ( l_chipItr = i_chipVector.begin();
                  (l_chipItr < i_chipVector.end());
                  l_chipItr++ )
            {
                // Ensure we won't copy beyond space allowed
                sz_hBuf += l_chipTypeSize;
                errl = homerVerifySizeFits(i_hBufSize, sz_hBuf);
                if (NULL != errl) { break; }

                // place the CHIP information
                memcpy( &i_hBuf[idx], &(l_chipItr->hChipType),
                        l_chipTypeSize ); idx += l_chipTypeSize;

                // place the configured chiplet information
                if (HOMER_CHIP_CENTAUR != l_chipItr->hChipType.chipType)
                {
                    // Ensure we won't copy beyond space allowed
                    sz_hBuf += sizeof(HOMER_ChipNimbus_t);
                    errl = homerVerifySizeFits(i_hBufSize, sz_hBuf);
                    if (NULL != errl) { break; }

                    // Cumulus and Nimbus are the same size area
                    memcpy( &i_hBuf[idx], &(l_chipItr->hChipN),
                            sizeof(HOMER_ChipNimbus_t) );

                    idx += sizeof(HOMER_ChipNimbus_t);
                } // end if PROC (not-centaur)
                else
                {
                    // Ensure we won't copy beyond space allowed
                    sz_hBuf += sizeof(HOMER_ChipCentaur_t);
                    errl = homerVerifySizeFits(i_hBufSize, sz_hBuf);
                    if (NULL != errl) { break; }

                    // Centaur is smaller area than PROC chips
                    memcpy( &i_hBuf[idx], &(l_chipItr->hChipM),
                            sizeof(HOMER_ChipCentaur_t) );

                    idx += sizeof(HOMER_ChipCentaur_t);
                } // end else CENTAUR chip

            } // end for loop on chip vector

            // ensure size is ok before any other copy
            if (NULL != errl) { break; }

            // Verify registers will fit before copying them
            uint32_t  l_reg32Count = 0;
            uint32_t  l_reg64Count = 0;

            // Count number of 32 bit addresses first
            for ( uint32_t  l_regIdx = REG_FIRST;
                   (l_regIdx < REG_IDFIR); l_regIdx++ )
            {
                for ( uint32_t l_tgtIndex = TRGT_FIRST;
                       (l_tgtIndex < TRGT_MAX); l_tgtIndex++ )
                {
                    l_reg32Count +=io_homerData.regCounts[l_tgtIndex][l_regIdx];
                } // end for on target index
            } // end for on register index


            // Count number of 64 bit addresses now
            for ( uint32_t  l_regIdx = REG_IDFIR;
                   (l_regIdx < REG_MAX); l_regIdx++ )
            {
                for ( uint32_t l_tgtIndex = TRGT_FIRST;
                       (l_tgtIndex < TRGT_MAX); l_tgtIndex++ )
                {
                    l_reg64Count +=io_homerData.regCounts[l_tgtIndex][l_regIdx];
                } // end for on target index
            } // end for on register index

            // Calculate additional size we need from the counts.
            // We have 32 bit addrs, 64 bit addrs, then EC level structures.
            sz_hBuf +=(l_reg32Count             * sizeof(uint32_t)) +
                      (l_reg64Count             * sizeof(uint64_t)) +
                      (io_homerData.ecDepCounts * sizeof(HOMER_ChipSpecAddr_t));

            // ensure we fit in HOMER before doing register copies
            errl = homerVerifySizeFits(i_hBufSize, sz_hBuf);
            if (NULL != errl) { break; }

            // loop thru targets
            for ( auto & t : l_targMap )
            {
                // TODO RTC 173614: story for CUMULUS when we know the regs
                // for sure TRGT_MC TRGT_MI TRGT_DMI -- probably NOOP now
                if ( (ALL_PROC_MEM_MASTER_CORE == i_curHw) ||
                     (ALL_HARDWARE == i_curHw)             ||
                     ( (TRGT_MCBIST != t.first) &&
                       (TRGT_MCS != t.first)    &&
                       (TRGT_MCA != t.first)    &&
                       (TRGT_MEMBUF != t.first) &&
                       (TRGT_MBA != t.first)
                      )
                   )
                {
                    // loop thru register types
                    for ( auto & r : t.second )
                    {
                        // loop thru SCOM addresses for reg type
                        for ( auto &  rAddr : r.second )
                        {
                            if ( (REG_IDFIR == r.first) ||
                                 (REG_IDREG == r.first)
                               )
                            {
                                memcpy( &i_hBuf[idx],
                                        &rAddr,
                                        u64 );

                                idx += u64;
                            }
                            else
                            {
                                uint32_t  tempAddr = (uint32_t)rAddr;
                                memcpy( &i_hBuf[idx],
                                        &tempAddr,
                                        u32 );

                                idx += u32;
                            }

                        } // end for on register addresses

                    } // end for on regs

                } // end if we need this target

            } // end for on targets

            // Add EC Level dependencies at the end
            uint8_t  *l_ecDepSourceRegs = (uint8_t *)(&s_ecDepProcRegisters[0]);
            memcpy( &i_hBuf[idx], l_ecDepSourceRegs,
                                  sizeof(s_ecDepProcRegisters) );

        } // end if chipCount non-zero


    } while(0);

    return errl;

    #undef FUNC
}

#if 1
// TODO RTC 173623:  Remove when done with initial testing
// Traces the information built into the vector
void dumpInfoVector( std::vector<HOMER_ChipInfo_t> &i_chipVector )
{
    PRDF_ERR("HOMER: Number of elements:%d", i_chipVector.size() );
    std::vector<HOMER_ChipInfo_t>::iterator  l_chipItr;

    for ( l_chipItr = i_chipVector.begin();
          (l_chipItr < i_chipVector.end());
          l_chipItr++ )
    {
        PRDF_ERR("HOMER: ChipPosition:%d", l_chipItr->hChipType.chipPos);
        PRDF_ERR("HOMER: EC Level:%X", l_chipItr->hChipType.chipEcLevel);
        PRDF_ERR("HOMER: FSI Addr:%X", l_chipItr->hChipType.fsiBaseAddr);

        switch (l_chipItr->hChipType.chipType)
        {
            case HOMER_CHIP_NIMBUS:
                PRDF_ERR("HOMER: NIMBUS chip");

                PRDF_ERR(" isMaster:%X", l_chipItr->hChipN.isMaster );
                PRDF_ERR(" xbusMask:%X", l_chipItr->hChipN.xbusMask );
                PRDF_ERR(" obusMask:%X", l_chipItr->hChipN.obusMask );
                PRDF_ERR(" ecMask:%X", l_chipItr->hChipN.ecMask );
                PRDF_ERR(" eqMask:%X", l_chipItr->hChipN.eqMask );
                PRDF_ERR(" exMask:%X", l_chipItr->hChipN.exMask );
                PRDF_ERR(" mcbistMask:%X", l_chipItr->hChipN.mcbistMask );
                PRDF_ERR(" mcsMask:%X", l_chipItr->hChipN.mcsMask );
                PRDF_ERR(" mcaMask:%X", l_chipItr->hChipN.mcaMask );
                PRDF_ERR(" cappMask:%X", l_chipItr->hChipN.cappMask );
                PRDF_ERR(" pecMask:%X", l_chipItr->hChipN.pecMask );
                PRDF_ERR(" phbMask:%X", l_chipItr->hChipN.phbMask );
                break;

            case HOMER_CHIP_CUMULUS:
                PRDF_ERR("HOMER: CUMULUS chip");

                PRDF_ERR(" isMaster:%X", l_chipItr->hChipC.isMaster );
                PRDF_ERR(" xbusMask:%X", l_chipItr->hChipC.xbusMask );
                PRDF_ERR(" obusMask:%X", l_chipItr->hChipC.obusMask );
                PRDF_ERR(" ecMask:%X", l_chipItr->hChipC.ecMask );
                PRDF_ERR(" eqMask:%X", l_chipItr->hChipC.eqMask );
                PRDF_ERR(" exMask:%X", l_chipItr->hChipC.exMask );
                PRDF_ERR(" mcMask:%X", l_chipItr->hChipC.mcMask );
                PRDF_ERR(" miMask:%X", l_chipItr->hChipC.miMask );
                PRDF_ERR(" dmiMask:%X", l_chipItr->hChipC.dmiMask );
                PRDF_ERR(" cappMask:%X", l_chipItr->hChipC.cappMask );
                PRDF_ERR(" pecMask:%X", l_chipItr->hChipC.pecMask );
                PRDF_ERR(" phbMask:%X", l_chipItr->hChipC.phbMask );
                break;

            case HOMER_CHIP_CENTAUR:
                PRDF_ERR("HOMER: CENTAUR chip");

                PRDF_ERR(" mbaMask:%X", l_chipItr->hChipM.mbaMask );
                break;

            default:
                PRDF_ERR("HOMER: Unknown Chip:%d",
                          l_chipItr->hChipType.chipType );
                break;

        } // end switch

    } // end for printing out things

} // end dumpInfoVector
#endif // 1 for temporary debug



//------------------------------------------------------------------------------

errlHndl_t writeHomerFirData( uint8_t * i_hBuf, size_t i_hBufSize,
                              const HwInitialized_t i_curHw )
{
    #define FUNC "[PRDF::writeHomerFirData] "

    errlHndl_t errl = NULL;

    do
    {
        HOMER_Data_t  l_homerData = HOMER_getData(); // Initializes data

        // Set flag indicating if IPL or runtime situation.
        l_homerData.iplState = (ALL_HARDWARE == i_curHw)
                          ? FIRDATA_STATE_RUNTIME : FIRDATA_STATE_IPL;

        // Get the PNOR information
        errl = getPnorInfo( l_homerData );
        if ( NULL != errl )
        {
            PRDF_ERR( FUNC "getPnorInfo() failed" );
            break;
        }

        // Hardware present gets pushed into this vector
        // (one element per chip)
        std::vector<HOMER_ChipInfo_t> l_chipInfVector;

        // Get the hardware configuration
        errl = getHwConfig( l_chipInfVector, i_curHw );

#if 1
        // TODO RTC 173623:  Remove when done with initial testing
        dumpInfoVector(l_chipInfVector);
#endif

        if ( NULL != errl )
        {
            PRDF_ERR( FUNC "getHwConfig() failed" );
            break;
        }

        // Write the HOMER data
        errl = writeData( i_hBuf, i_hBufSize, i_curHw,
                          l_chipInfVector, l_homerData );

        if ( NULL != errl )
        {
            PRDF_ERR( FUNC "writeData() failed" );
            break;
        }

    } while (0);

    if ( NULL != errl )
    {
        errl->collectTrace( PRDF_COMP_NAME, 512 );
    }

    return errl;

    #undef FUNC

}

}; // end namespace PRDF
