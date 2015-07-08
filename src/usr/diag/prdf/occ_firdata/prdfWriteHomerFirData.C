/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/occ_firdata/prdfWriteHomerFirData.C $       */
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

#include <homerData_common.h>

#include <prdfErrlUtil.H>
#include <prdfPlatServices.H>
#include <prdfTrace.H>

#include <fsi/fsiif.H>
#include <pnor/pnorif.H>

using namespace TARGETING;

namespace PRDF
{

using namespace PlatServices;

//------------------------------------------------------------------------------
// Register lists
//------------------------------------------------------------------------------

// TODO RTC 124849: Auto-generate this list from rule code.

static uint32_t proc_glbl[] =
{
    0x570F001C, // GLOBAL_CS_FIR
    0x570F001B, // GLOBAL_RE_FIR
};

static uint32_t proc_fir[] =
{
    0x01010800, // OCCFIR
    0x01010840, // PMCFIR
    0x01010c00, // PBAMFIR
    0x0104000a, // TP_LFIR
    0x02010840, // PBAFIR
    0x02010900, // PSIHBFIR
    0x02010940, // ENHCAFIR
    0x02010980, // EHHCAFIR
    0x020109c0, // ICPFIR
    0x02010c00, // PBWESTFIR
    0x02010c40, // PBCENTFIR
    0x02010c80, // PBEASTFIR
    0x02011A00, // IOMCFIR_0
    0x02011E00, // IOMCFIR_1
    0x02012000, // PCINESTFIR_0
    0x02012400, // PCINESTFIR_1
    0x02012800, // PCINESTFIR_2
    0x02013000, // NXCXAFIR
    0x02013080, // NXCQFIR
    0x02013100, // NXDMAENGFIR
    0x02013400, // MCDFIR
    0x0204000a, // PB_LFIR
    0x04010c00, // PBENFIR
    0x04011000, // IOXFIR_0
    0x04011400, // IOXFIR_1
    0x04011800, // IOXFIR_3
    0x04011C00, // IOXFIR_2
    0x0404000a, // XBUS_LFIR
    0x08010800, // PBESFIR
    0x08010c00, // IOAFIR
    0x0804000a, // ABUS_LFIR
    0x09010800, // PBFFIR
    0x09011400, // IOPCIFIR_0
    0x09011840, // IOPCIFIR_1
    0x0904000a, // PCIE_LFIR
};

static uint32_t proc_reg[] =
{
    // Global FIRs
    0x570F001A, // GLOBAL_SPA (for FFDC only)
    //0x51040001, // GLOBALUNITXSTPFIR (not even accessible during IPL)

    // For ATTN
    0x01020013, // IPOLL reg
    0x02000001, // GP1 reg

    // Chiplet FIRs
    0x01040000, // TP_CHIPLET_CS_FIR
    0x01040001, // TP_CHIPLET_RE_FIR
    0x01040002, // TP_CHIPLET_FIR_MASK
    0x01040004, // TP_CHIPLET_SPA (for FFDC only)
    0x01040007, // TP_CHIPLET_SPA_MASK (for FFDC only)
    0x02040000, // PB_CHIPLET_CS_FIR
    0x02040001, // PB_CHIPLET_RE_FIR
    0x02040002, // PB_CHIPLET_FIR_MASK
    0x02040004, // PB_CHIPLET_SPA (for FFDC only)
    0x02040007, // PB_CHIPLET_SPA_MASK (for FFDC only)
    0x04040000, // XBUS_CHIPLET_CS_FIR
    0x04040001, // XBUS_CHIPLET_RE_FIR
    0x04040002, // XBUS_CHIPLET_FIR_MASK
    0x08040000, // ABUS_CHIPLET_CS_FIR
    0x08040001, // ABUS_CHIPLET_RE_FIR
    0x08040002, // ABUS_CHIPLET_FIR_MASK
    0x09040000, // PCIE_CHIPLET_CS_FIR
    0x09040001, // PCIE_CHIPLET_RE_FIR
    0x09040002, // PCIE_CHIPLET_FIR_MASK
    0x09040004, // PCIE_CHIPLET_SPA (for FFDC only)
    0x09040007, // PCIE_CHIPLET_SPA_MASK (for FFDC only)

    // FIRs for FFDC only
    0x02010c6e, // PBEXTFIR
    0x020130c0, // NXASFIR
    0x020130c3, // NXASFIR_MASK
    0x04012400, // PSIXBUSFIR
    0x09012000, // PCICLOCKFIR_0
    0x09012400, // PCICLOCKFIR_1
    0x09012800, // PCICLOCKFIR_2

    // PLL registers
    0x00050019, // PCIE_OSC_SWITCH
    0x01020019, // OSCERR

    // TOD registers
    0x00040000, // TOD_MPCR
    0x00040001, // TOD_PCRP0
    0x00040002, // TOD_PCRP1
    0x00040003, // TOD_SCRP0
    0x00040004, // TOD_SCRP1
    0x00040005, // TOD_SPCR
    0x00040006, // TOD_IPCR
    0x00040007, // TOD_PSMSCR
    0x00040008, // TOD_STATUSREGISTER
    0x00040009, // TOD_MPSR
    0x0004000A, // TOD_SPSR
    0x00040010, // TOD_CCR
    0x0004001D, // TOD_TRACEDATA_SET_1
    0x0004001E, // TOD_TRACEDATA_SET_2
    0x0004001F, // TOD_TRACEDATA_SET_3
    0x00040024, // TOD_FSM
    0x00040027, // TOD_TX_TTYPE
    0x00040029, // TOD_RX_TTYPE
    0x00040030, // TOD_ERRORREGISTER
    0x00040032, // TOD_ERRORMASK
    0x00040033, // TOD_ERRORACTION

    // c_err_rpt and extra FFDC registers
    0x00062002, // PMC_PSTATE_MONITOR_AND_CTRL_REG
    0x00062008, // GLOBAL_ACTUAL_VOLTAGE_REG
    0x00062046, // PMC_SPIV_STATUS_REG
    0x00062056, // PMC_O2S_STATUS_REG
    0x00062058, // PMC_O2S_WDATA_REG
    0x00062059, // PMC_O2S_RDATA_REG
    0x0101080A, // OCCFIR_ERROR_REPORT
    0x0201084C, // PBAFIR_ERROR_REPORT_0
    0x0201084D, // PBAFIR_ERROR_REPORT_1
    0x0201084E, // PBAFIR_ERROR_REPORT_2
    0x02010c6c, // PB_CENT_CR_ERROR
    0x0201201C, // PCINESTFIR0_ERROR_REPORT_0
    0x0201201D, // PCINESTFIR0_ERROR_REPORT_1
    0x0201201E, // PCINESTFIR0_ERROR_REPORT_2
    0x0201241C, // PCINESTFIR1_ERROR_REPORT_0
    0x0201241D, // PCINESTFIR1_ERROR_REPORT_1
    0x0201241E, // PCINESTFIR1_ERROR_REPORT_2
    0x0201281C, // PCINESTFIR2_ERROR_REPORT_0
    0x0201281D, // PCINESTFIR2_ERROR_REPORT_1
    0x0201281E, // PCINESTFIR2_ERROR_REPORT_2
    0x0201300A, // NXCXAFIR_SNP_ERROR_REPORT
    0x0201300B, // NXCXAFIR_APC1_ERROR_REPORT
    0x0201300C, // NXCXAFIR_XPT_ERROR_REPORT
    0x0201300D, // NXCXAFIR_TLBI_ERROR_REPORT
    0x02013057, // NXDMAENG_ERROR_REPORT_0
    0x02013058, // NXDMAENG_ERROR_REPORT_1
    0x020130A2, // NXCQFIR_ERROR_REPORT_0
    0x020130A3, // NXCQFIR_ERROR_REPORT_1
    0x020130EB, // NXASFIR_IN_ERROR_HOLD_REPORT
    0x020130FF, // NXASFIR_ERROR_HOLD_REPORT
    //0x0201314E, // NXASFIR_EG_ERROR_HOLD_REPORT (Murano DD1.0 only)
    0x0201314F, // NXASFIR_CE_HOLD_REPORT
    0x02013419, // MCDFIR_ERROR_REPORT
    0x020F001E, // PB_CONFIG_REG
    0x020F001F, // PB_ERROR_REG
    0x080F001E, // ABUS_CONFIG_REG
    0x080F001F, // ABUS_ERROR_REG
    0x0901083A, // PBFIR_IOF0_ERROR_REPORT
    0x0901083B, // PBFIR_IOF1_ERROR_REPORT
    0x0901200A, // PCI_ETU_RESET_0
    0x0901240A, // PCI_ETU_RESET_1
    0x0901280A, // PCI_ETU_RESET_2
    0x090F001E, // PCI_CONFIG_REG
    0x090F001F, // PCI_ERROR_REG
};

static uint32_t ex_glbl[] =
{
    0x10040000, // EX_CHIPLET_CS_FIR
    0x10040001, // EX_CHIPLET_RE_FIR
};

static uint32_t ex_fir[] =
{
    0x10010800, // L3FIR
    0x10010c00, // NCUFIR
    0x10012800, // L2FIR
    0x1004000a, // EX_LFIR
};

static uint32_t ex_reg[] =
{
    // Chiplet FIRs
    0x10040002, // EX_CHIPLET_FIR_MASK
    0x10040004, // EX_CHIPLET_SPA (for FFDC only)

    // The COREFIR needs to be captured differently because recoverable errors
    // are reported through the WOF, not the FIR.
    0x10013100, // COREFIR
    0x10013103, // COREFIR_MASK
    0x10013106, // COREFIR_ACT0
    0x10013107, // COREFIR_ACT1
    0x10013108, // COREFIR_WOF

    // FIRs for FFDC only
    0x10013007, // SPATTN_0
    0x10013017, // SPATTN_1
    0x10013027, // SPATTN_2
    0x10013037, // SPATTN_3
    0x10013047, // SPATTN_4
    0x10013057, // SPATTN_5
    0x10013067, // SPATTN_6
    0x10013077, // SPATTN_7

    // c_err_rpt and extra FFDC registers
    0x10010810, // L3FIR_RD0_ERROR_REPORT
    0x10010817, // L3FIR_RD1_ERROR_REPORT
    0x10010C0C, // NCUFIR_ERROR_REPORT
    0x10012815, // L2FIR_ERROR_REPORT_0
    0x10012816, // L2FIR_ERROR_REPORT_1
    0x1001300D, // PCNE_REG0_HOLD_OUT
    0x1001301D, // PCNE_REG1_HOLD_OUT
    0x1001302D, // PCNE_REG2_HOLD_OUT
    0x1001303D, // PCNE_REG3_HOLD_OUT
    0x1001304D, // PCNE_REG4_HOLD_OUT
    0x1001305D, // PCNE_REG5_HOLD_OUT
    0x1001306D, // PCNE_REG6_HOLD_OUT
    0x1001307D, // PCNE_REG7_HOLD_OUT
    0x1001329B, // COREHMEER
    0x100132A9, // PCNW_REG0_HOLD_OUT
    0x100132AA, // PCNW_REG1_HOLD_OUT
    0x100132CB, // PCS_REG0_HOLD_OUT
    0x100132D5, // PCS_REG1_HOLD_OUT
    0x10013300, // FXU_REG0_HOLD_OUT
    0x10013301, // FXU_REG1_HOLD_OUT
    0x10013302, // FXU_REG2_HOLD_OUT
    0x10013303, // FXU_REG3_HOLD_OUT
    0x10013304, // FXU_REG4_HOLD_OUT
    0x10013340, // ISU_REG0_ISU_HOLD_OUT
    0x10013341, // ISU_REG1_ISU_HOLD_OUT
    0x10013342, // ISU_REG2_ISU_HOLD_OUT
    0x10013343, // ISU_REG3_ISU_HOLD_OUT
    0x10013344, // ISU_REG4_ISU_HOLD_OUT
    0x10013345, // ISU_REG5_ISU_HOLD_OUT
    0x10013346, // ISU_REG6_ISU_HOLD_OUT
    0x10013347, // ISU_REG7_ISU_HOLD_OUT
    0x10013348, // ISU_REG8_ISU_HOLD_OUT_ERRPT
    0x10013349, // ISU_REG9_ISU_HOLD_OUT
    0x10013381, // IFU_REG0_HOLD_OUT
    0x10013382, // IFU_REG1_HOLD_OUT
    0x10013383, // IFU_REG2_HOLD_OUT
    0x10013384, // IFU_REG3_HOLD_OUT
    0x10013385, // IFU_REG4_HOLD_OUT
    0x100133C0, // LSU_REG0_HOLD_OUT
    0x100133C1, // LSU_REG1_HOLD_OUT
    0x100133C2, // LSU_REG2_HOLD_OUT
    0x100133C3, // LSU_REG3_HOLD_OUT
    0x100133C4, // LSU_REG4_HOLD_OUT
    0x100133C5, // LSU_REG5_HOLD_OUT
    0x100133C6, // LSU_REG6_HOLD_OUT
    0x100133C7, // LSU_REG7_HOLD_OUT
    0x100133C8, // LSU_REG8_HOLD_OUT
    0x100133C9, // LSU_REG9_HOLD_OUT
    0x100133CA, // LSU_REG10_HOLD_OUT
    0x100133CB, // LSU_REG11_HOLD_OUT
    0x100133CC, // LSU_REG12_HOLD_OUT
    0x100133CD, // LSU_REG13_HOLD_OUT
    0x100133CE, // LSU_REG14_HOLD_OUT
    0x100133CF, // LSU_REG15_HOLD_OUT
    0x100F001E, // EX_CONFIG_REG
    0x100F001F, // EX_ERROR_REG
    0x100F0151, // EX_FREQ_CTRL_REG
    0x100F0153, // EX_POWER_MGMT_STATUS_REG
    0x100F0159, // EX_POWER_MGMT_CTRL_REG
    0x100F0161, // EX_DPLL_STATUS_REG
};

static uint32_t mcs_fir[] =
{
    0x02011840, // MCIFIR
};

static uint32_t mcs_reg[] =
{
    // WOF register explicitly needed for analysis
    0x02011848, // MCIFIR_WOF

    // c_err_rpt and extra FFDC registers
    0x0201181E, // MCERPT0
    0x0201184E, // MCIERPT0
    0x02011800, // MCFGP
    0x0201181C, // MCHWFM
};

static uint32_t memb_glbl[] =
{
    0x570F001C, // GLOBAL_CS_FIR
    0x570F001B, // GLOBAL_RE_FIR
};

static uint32_t memb_fir[] =
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

static uint32_t memb_reg[] =
{
    // Global FIRs
    0x570F001A, // GLOBAL_SPA (for FFDC only)

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

    // Other ECC registers (won't be used in analysis, but could be useful FFDC)
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
};

static uint32_t mba_fir[] =
{
    0x03010600, // MBAFIR
    0x03010400, // MBACALFIR
};

static uint32_t mba_reg[] =
{
    0x0301041b, // MBASECUREFIR
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

static uint64_t mba_id_fir[] =
{
    0x800200900301143Fll, // MBADDRPHYFIR
};

static uint64_t mba_id_reg[] =
{
    0x8000D0060301143Fll, // DDRPHY_APB_FIR_ERR0_P0
    0x8000D0070301143Fll, // DDRPHY_APB_FIR_ERR1_P0
    0x8001D0060301143Fll, // DDRPHY_APB_FIR_ERR0_P1
    0x8001D0070301143Fll, // DDRPHY_APB_FIR_ERR1_P1
};

//------------------------------------------------------------------------------

errlHndl_t getHwConfig( HOMER_Data_t & o_data )
{
    #define FUNC "[PRDF::getHwConfig] "

    errlHndl_t errl = NULL;

    o_data = HOMER_getData(); // Initializes data.

    do
    {
        //----------------------------------------------------------------------
        // Get the PNOR information.
        //----------------------------------------------------------------------

        PNOR::SectionInfo_t sectionInfo;
        errl = PNOR::getSectionInfo( PNOR::FIRDATA, sectionInfo );
        if ( NULL != errl )
        {
            PRDF_ERR( FUNC "getSectionInfo() failed" );
            break;
        }

        PNOR::PnorInfo_t pnorInfo;
        PNOR::getPnorInfo( pnorInfo );

        o_data.pnorInfo.pnorOffset      = sectionInfo.flashAddr;
        o_data.pnorInfo.pnorSize        = sectionInfo.size;
        o_data.pnorInfo.mmioOffset      = pnorInfo.mmioOffset;
        o_data.pnorInfo.norWorkarounds  = pnorInfo.norWorkarounds;

        //----------------------------------------------------------------------
        // Get hardware config information.
        //----------------------------------------------------------------------

        // Get the master PROC position.
        TargetHandle_t masterProc = getMasterProc();
        if ( NULL == masterProc )
        {
            PRDF_ERR( FUNC "master PROC is NULL" );

            /*@
             * @errortype
             * @reasoncode PRDF_NULL_VALUE_RETURNED
             * @severity   ERRL_SEV_UNRECOVERABLE
             * @moduleid   PRDF_CS_FIRDATA_WRITE
             * @userdata1  0
             * @userdata2  0
             * @devdesc    NULL system target.
             */
            errl = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                            PRDF_CS_FIRDATA_WRITE,
                                            PRDF_NULL_VALUE_RETURNED, 0, 0 );
            break;
        }

        o_data.masterProc = getTargetPosition( masterProc );

        // Iterate the list functional PROCs.
        TargetHandleList procList = getFunctionalTargetList( TYPE_PROC );
        for ( TargetHandleList::iterator procIt = procList.begin();
              procIt != procList.end(); ++procIt )
        {
            uint32_t procPos = getTargetPosition(*procIt);
            PRDF_ASSERT( procPos < MAX_PROC_PER_NODE );

            o_data.procMask |= 0x80 >> procPos;

            // Get the PROC FSI address.
            FSI::FsiLinkInfo_t fsiInfo;
            FSI::getFsiLinkInfo( *procIt, fsiInfo );
            o_data.procFsiBaseAddr[procPos] = fsiInfo.baseAddr;

            // Iterate the connected EXs.
            TargetHandleList exList = getConnected( *procIt, TYPE_EX );
            for ( TargetHandleList::iterator exIt = exList.begin();
                  exIt != exList.end(); ++exIt )
            {
                uint32_t exPos = getTargetPosition( *exIt );
                PRDF_ASSERT( exPos < MAX_EX_PER_PROC );

                o_data.exMasks[procPos] |= 0x8000 >> exPos;
            }

            // Iterate the connected MCSs.
            TargetHandleList mcsList = getConnected( *procIt, TYPE_MCS );
            for ( TargetHandleList::iterator mcsIt = mcsList.begin();
                  mcsIt != mcsList.end(); ++mcsIt )
            {
                uint32_t mcsPos = getTargetPosition( *mcsIt );
                PRDF_ASSERT( mcsPos < MAX_MCS_PER_PROC );

                o_data.mcsMasks[procPos] |= 0x80 >> mcsPos;
            }

            // Iterate the connected MEMBUFs.
            TargetHandleList membList = getConnected( *procIt, TYPE_MEMBUF );
            for ( TargetHandleList::iterator membIt = membList.begin();
                  membIt != membList.end(); ++membIt )
            {
                uint32_t membPos = getTargetPosition(*membIt);
                PRDF_ASSERT( membPos < MAX_MEMB_PER_PROC );

                o_data.membMasks[procPos] |= 0x80 >> membPos;

                // Get the MEMBUF FSI address.
                getFsiLinkInfo( *membIt, fsiInfo );
                o_data.membFsiBaseAddr[procPos][membPos] = fsiInfo.baseAddr;

                // Iterate the connected MBAs.
                TargetHandleList mbaList = getConnected( *membIt, TYPE_MBA );
                for ( TargetHandleList::iterator mbaIt = mbaList.begin();
                      mbaIt != mbaList.end(); ++mbaIt )
                {
                    uint32_t mbaPos = getTargetPosition(*mbaIt);
                    uint32_t shift = membPos * MAX_MBA_PER_MEMBUF + mbaPos;
                    PRDF_ASSERT( shift < MAX_MBA_PER_PROC );

                    o_data.mbaMasks[procPos] |= 0x8000 >> shift;
                }
            }
        }

    } while (0);

    return errl;

    #undef FUNC
}

//------------------------------------------------------------------------------

errlHndl_t writeHomerFirData( uint8_t * i_hBuf, size_t i_hBufSize )
{
    #define FUNC "[PRDF::writeHomerFirData] "

    errlHndl_t errl = NULL;

    do
    {
        // Get the hardware configuration.
        HOMER_Data_t data;
        errl = getHwConfig( data );
        if ( NULL != errl )
        {
            PRDF_ERR( FUNC "getHwConfig() failed" );
            break;
        }

        // Get the ultimate buffer size.
        size_t s[MAX_TRGTS][MAX_REGS];
        memset( s, 0x00, sizeof(s) );

        size_t sz_hBuf = 0;

        size_t sz_data = sizeof(data);       sz_hBuf += sz_data;
        s[PROC][GLBL]  = sizeof(proc_glbl);  sz_hBuf += s[PROC][GLBL];
        s[PROC][FIR]   = sizeof(proc_fir);   sz_hBuf += s[PROC][FIR];
        s[PROC][REG]   = sizeof(proc_reg);   sz_hBuf += s[PROC][REG];
        s[EX][GLBL]    = sizeof(ex_glbl);    sz_hBuf += s[EX][GLBL];
        s[EX][FIR]     = sizeof(ex_fir);     sz_hBuf += s[EX][FIR];
        s[EX][REG]     = sizeof(ex_reg);     sz_hBuf += s[EX][REG];
        s[MCS][FIR]    = sizeof(mcs_fir);    sz_hBuf += s[MCS][FIR];
        s[MCS][REG]    = sizeof(mcs_reg);    sz_hBuf += s[MCS][REG];
        s[MEMB][GLBL]  = sizeof(memb_glbl);  sz_hBuf += s[MEMB][GLBL];
        s[MEMB][FIR]   = sizeof(memb_fir);   sz_hBuf += s[MEMB][FIR];
        s[MEMB][REG]   = sizeof(memb_reg);   sz_hBuf += s[MEMB][REG];
        s[MBA][FIR]    = sizeof(mba_fir);    sz_hBuf += s[MBA][FIR];
        s[MBA][REG]    = sizeof(mba_reg);    sz_hBuf += s[MBA][REG];
        s[MBA][IDFIR]  = sizeof(mba_id_fir); sz_hBuf += s[MBA][IDFIR];
        s[MBA][IDREG]  = sizeof(mba_id_reg); sz_hBuf += s[MBA][IDREG];

        // Verify data will fit in HOMER.
        if ( i_hBufSize < sz_hBuf )
        {
            PRDF_ERR( FUNC "Required data size %d is greater that available "
                      "HOMER data %d", sz_hBuf, i_hBufSize );
            /*@
             * @errortype
             * @reasoncode PRDF_INVALID_CONFIG
             * @severity   ERRL_SEV_UNRECOVERABLE
             * @moduleid   PRDF_CS_FIRDATA_WRITE
             * @userdata1  Size needed
             * @userdata2  Size available
             * @devdesc    Invalid configuration in CS FIR Data handling.
             */
            errl = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                            PRDF_CS_FIRDATA_WRITE,
                                            PRDF_INVALID_CONFIG,
                                            sz_hBuf,
                                            i_hBufSize );
            break;
        }

        // Add register counts to the data.
        const size_t u32 = sizeof(uint32_t);
        const size_t u64 = sizeof(uint64_t);

        for ( uint32_t c = FIRST_TRGT; c < MAX_TRGTS; c++ )
        {
            data.counts[c][GLBL]  = s[c][GLBL]  / u32;
            data.counts[c][FIR]   = s[c][FIR]   / u32;
            data.counts[c][REG]   = s[c][REG]   / u32;
            data.counts[c][IDFIR] = s[c][IDFIR] / u64;
            data.counts[c][IDREG] = s[c][IDREG] / u64;
        }

        // Add everything to the buffer.
        uint32_t idx = 0;

        memcpy( &i_hBuf[idx], &data,      sz_data       ); idx += sz_data;
        memcpy( &i_hBuf[idx], proc_glbl,  s[PROC][GLBL] ); idx += s[PROC][GLBL];
        memcpy( &i_hBuf[idx], proc_fir,   s[PROC][FIR]  ); idx += s[PROC][FIR];
        memcpy( &i_hBuf[idx], proc_reg,   s[PROC][REG]  ); idx += s[PROC][REG];
        memcpy( &i_hBuf[idx], ex_glbl,    s[EX][GLBL]   ); idx += s[EX][GLBL];
        memcpy( &i_hBuf[idx], ex_fir,     s[EX][FIR]    ); idx += s[EX][FIR];
        memcpy( &i_hBuf[idx], ex_reg,     s[EX][REG]    ); idx += s[EX][REG];
        memcpy( &i_hBuf[idx], mcs_fir,    s[MCS][FIR]   ); idx += s[MCS][FIR];
        memcpy( &i_hBuf[idx], mcs_reg,    s[MCS][REG]   ); idx += s[MCS][REG];
        memcpy( &i_hBuf[idx], memb_glbl,  s[MEMB][GLBL] ); idx += s[MEMB][GLBL];
        memcpy( &i_hBuf[idx], memb_fir,   s[MEMB][FIR]  ); idx += s[MEMB][FIR];
        memcpy( &i_hBuf[idx], memb_reg,   s[MEMB][REG]  ); idx += s[MEMB][REG];
        memcpy( &i_hBuf[idx], mba_fir,    s[MBA][FIR]   ); idx += s[MBA][FIR];
        memcpy( &i_hBuf[idx], mba_reg,    s[MBA][REG]   ); idx += s[MBA][REG];
        memcpy( &i_hBuf[idx], mba_id_fir, s[MBA][IDFIR] ); idx += s[MBA][IDFIR];
        memcpy( &i_hBuf[idx], mba_id_reg, s[MBA][IDREG] ); idx += s[MBA][IDREG];

    } while (0);

    if ( NULL != errl )
    {
        errl->collectTrace( PRDF_COMP_NAME, 512 );
    }

    return errl;

    #undef FUNC
}

}; // end namespace PRDF

