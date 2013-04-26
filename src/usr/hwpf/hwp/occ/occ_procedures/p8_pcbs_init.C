/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/occ/occ_procedures/p8_pcbs_init.C $          */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013                   */
/*                                                                        */
/* p1                                                                     */
/*                                                                        */
/* Object Code Only (OCO) source materials                                */
/* Licensed Internal Code Source Materials                                */
/* IBM HostBoot Licensed Internal Code                                    */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* Origin: 30                                                             */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
// $Id: p8_pcbs_init.C,v 1.15 2013/04/12 01:31:59 stillgs Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/p8_pcbs_init.C,v $
//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
//------------------------------------------------------------------------------
// *! OWNER NAME: Ralf Maier         Email: ralf.maier@de.ibm.com
// *!
// *! General Description:
// *!
// *!   The purpose of this procedure is to establish the safe setting for PCBSLV
// *!   o set psafe value
// *!   o set PMIN clip/Pmax clip
// *!   o PMCR default values
// *!   o PMICR default values
// *!
// *!
// *! Procedure Prereq:
// *!   o System clocks are running
// *!
//------------------------------------------------------------------------------
/// \file p8_pcbs_init.C
/// \brief Establish the Pstate 0 frequency from VPD
///
///
///
/// \version --------------------------------------------------------------------------
/// \version 1.8  rmaier 12/07/12 Removed PFET delay value calculation from p8_pcbs_init_config since this is moved to p8_pfet_init.C
/// \version --------------------------------------------------------------------------
/// \version 1.7  rmaier 10/25/12 Removed PMGP1_REG Idle-Configuration since this function moved to p8_poreslw_init.C
/// \version --------------------------------------------------------------------------
/// \version 1.6  rmaier 10/12/12 Removed not needed scan0 writes to EX_PCBS_Pstate_Step_Target_Register EX_PCBS_OCC_Heartbeat_Reg
/// \version --------------------------------------------------------------------------
/// \version 1.5  rmaier 10/10/12 Changed value of EX_PCBS_Resonant_Clock_Control_Reg0_0x100F0165_scan0
/// \version --------------------------------------------------------------------------
/// \version 1.4  rmaier 10/08/12 Removed genBinStr and <string> function
/// \version --------------------------------------------------------------------------
/// \version 1.3  rmaier 10/04/12 Replacing genHex*Str function
/// \version --------------------------------------------------------------------------
/// \version 1.2  rmaier 09/20/12 Updated with new PCBS-addressing method
/// \version --------------------------------------------------------------------------
/// \version 1.1  rmaier 08/23/12 Renaming proc_ to p8_
/// \version --------------------------------------------------------------------------
/// \version 1.15 rmaier 08/15/12 Included review feedback Set7 (removed conditional compile statements )
/// \version --------------------------------------------------------------------------
/// \version 1.14 rmaier 08/03/12 Included review feedback Set4
/// \version --------------------------------------------------------------------------
/// \version 1.13 rmaier 08/02/12 Included review feedback Set4 partial
/// \version --------------------------------------------------------------------------
/// \version 1.12 rmaier 07/30/12 Included review feedback Set3 partial
/// \version --------------------------------------------------------------------------
/// \version 1.11 rmaier 07/23/12 Included review feedback Set2 partial
/// \version --------------------------------------------------------------------------
/// \version 1.10 rmaier 07/17/12 Included review feedback Set1
/// \version --------------------------------------------------------------------------
/// \version 1.7 rmaier 05/24/12 Included review feedback
/// \version --------------------------------------------------------------------------
/// \version 1.6 rmaier 03/27/12 Coded CONFIG mode
/// \version --------------------------------------------------------------------------
/// \version 1.5 rmaier 03/20/12 Coded INIT mode
/// \version --------------------------------------------------------------------------
/// \version 1.4 rmaier 03/13/12 Added modes-structure
/// \version --------------------------------------------------------------------------
/// \version 1.3 rmaier 01/11/12 Removed PFET values
/// \version --------------------------------------------------------------------------
/// \version 1.2 rmaier 12/05/11 Hardcoded valid chiplets ... need to be removed again fapiGetExistingChiplets  =>  fapiGetChildChiplets
/// \version --------------------------------------------------------------------------
/// \version 1.1 rmaier 11/30/11 eCMD 12.2 adaptions. fapiGetExistingChiplets  =>  fapiGetChildChiplets , Scan0 values set
/// \version --------------------------------------------------------------------------
/// \version 1.0 rmaier 10/17/11 Initial Version - RESET mode
/// \version ---------------------------------------------------------------------------
///
/// \todo   command order
/// \todo   next --  > initialize all pm_reg with scan-zero values upfront
/// \todo   Clear definition/doc of parms and attributes required  at the beginning.
/// \todo   GP3 Changes Winkle fence changes
/// \todo   Review
///
/// High-level procedure flow:
///
/// \verbatim
///
///  Procedure Prereq:
///  - completed istep procedure
///  - completed multicast setup
///
///
/// if PM_CONFIG {                                                                                                                              
///    PState translation                                                                                                                       
///          convert_safe_freq()                                                                                                                
///    Resonant Clocking settings (band definitions from frequency to Pstate)                                                                   
///          convert_resclk_freqs_to_pstates()                                                                                                  
///    PFET Sequencing Delays                                                                                                                   
///          convert_pfet_delays()                                                                                                              
///
/// else if PM_INIT {                                                                                                                           
///
///   set CPM_FILTER_ENABLE = 0                                   -- #110f0152, DPLL_CPM_PARM_REG[10] = 0                                       
///                                                               -- PMGP1_REG   WOX_OR 150f0105                                                
///
///   set PMCR[0:39]  = 0                                        --  PMCR default value adjustment                                              
///                                                              -- (Hardware flush 0 -> restore to 0 for reset case)                           
///                                                              -- #110f0159, PCBS_POWER_MANAGEMENT_CONTROL_REG                                
///
///               pm_spr_override_en must be set to write this reg!!                                                                            
///   set PMICR[0:47]  = 0                                       --  PMICR default value adjustment                                             
///                                                              -- (Hardware flush 0 -> restore to TBD for reset case)                         
///                                                              -- #110f0158, PCBS_POWER_MANAGEMENT_IDLE_CONTROL_REG                           
///
///
///
/// } else if PM_RESET {                                                                                                                        
///
///   loop over all valid chiplets {                                                                                                            
///
///       -- TODO check about                                                                                                                   
///       -- initialize all pm_reg with scan-zero values upfront                                                                                
///
///       //  Force safe mode                                                                                                                   
///       set force_safe_mode = 1                                 -- Force safe mode (uses Psafe Pstate setting)                                
///                                                               -- XXXX multicast PCBS_PM_PMGP1_REG_1[12] = 1///                              
///       //  psafe Pstate achived AND FSM-stable ?                                                                                             
///       if psafePstate achived AND FSM-stable {                 -- Check PCBS-PM state/status that Psafe (Pstate) as been achieved and        
///                                                               -- that FSM are in a stable state                                             
///                                                               -- PCBS_POWER_MANAGEMENT_STATUS_REG[33] safe_mode_active                      
///                                                               -- PCBS_POWER_MANAGEMENT_STATUS_REG[36] all_fsms_in_safe_state                
///       } elsif timeout {                                                                                                                     
///         --BAD RC: timeout - no PsafePstate or FSMs not stable                                                                               
///       }                                                                                                                                     
///
///       //  DPLL settings                                                                                                                     
///       set dpll_freq_override_enable = 1                       -- PCBS_PM_PMGP1_REG_1[10] = 1                                                
///                                                               -- only in override mode is a write to FREQ_CTRL_REG possible                 
///
///       set minPstate = min(Psafe,global actual pstate)         -- PCBS_OCC_Heartbeat_Reg[17..24]  Psafe                                      
///                                                               -- PCBS_POWER_MANAGEMENT_STATUS_REG[0..7] global actual pstate                
///       set dpll_min = fnom + minPstate(signed)                 -- FREQ_CTRL_REG[20..27]  pstate_dpll_fnom                                    
///
///
///       set dpll_fmin                                           -- FREQ_CTRL_REG[0..7]   scaninit: 00110010                                   
///       set dpll_fmax                                           -- FREQ_CTRL_REG[8..15]  scaninit: 00110010                                   
///
///       set pm_spr_override_en = 1                              -- Force OCC SPR Mode                                                         
///                                                               -- XXXX multicast PCBS_PM_PMGP1_REG_1[11] = 1                                 
///
///       set enable_Pstate_mode = 0                              -- PCBSPM_MODE_REG[0] ....multicast                                           
///
///       set enable_global_pstate_req = 0                        -- Force *global_en PState to off  to cease interrupts to PMC....multicast    
///                                                               -- PCBSPM_MODE_REG[2]                                                         
///
///                                                               -- Reset Pmin and Pmax to wide open...multicast                               
///       set Pmin_clip   =  -128                                 -- PCBS_Power_Management_Bounds_Reg[0..7]  0b10000000                         
///       set Pmax_clip   =   127                                 -- PCBS_Power_Management_Bounds_Reg[8..15] 0b01111111                         
///
///
///       //  Settings                                                                                                                          
///       set resclk_dis = 1                                      -- Chiplets resonant clocking (via PCBS) disabled                             
///                                                                  -- EH.TPCHIP.NET.PCBSLPREV.GP3_REG[22]                                     
///                                                               -- This is only ROX PCBS_Resonant_Clock_Control_Reg0[0]                       
///
///       set occ_heartbeat_enable = 0                            -- OCC Heartbeat disable                                                      
///                                                               -- PCBS_OCC_Heartbeat_Reg[8]                                                  
///
///       //  IVRM Setup                                                                                                                        
///       get the mrwb attribute ivrms_enabled                    -- If '0' Salerno, if '1' Venice                                              
///       if ivrms_enabled {                                                                                                                    
///           set ivrm_fsm_enable = 0                             -- PCBS_iVRM_Control_Status_Reg[0]                                            
///                                                               -- ivrm_fsm_enable have be '0' to enable bypass_b writes                      
///           set bypass_b mode = 0                                                                                                             
///                                    --ivrm_core_vdd_bypass_b   -- PCBS_iVRM_Control_Status_Reg[4]                                            
///                                    --ivrm_core_vcs_bypass_b   -- PCBS_iVRM_Control_Status_Reg[6]                                            
///                                    --ivrm_eco_vdd_bypass_b    -- PCBS_iVRM_Control_Status_Reg[8]                                            
///                                    --ivrm_eco_vcs_bypass_b    -- PCBS_iVRM_Control_Status_Reg[10]                                           
///       }                                                                                                                                     
///
///                                                               -- Undervolting values reset                                                  
///       set Kuv = 0                                             -- PCBS_UNDERVOLTING_REG[16..21]                                              
///                                                               -- Puv_min and Puv_max  to disable                                            
///       set Puv_min = -128                                      -- PCBS_UNDERVOLTING_REG[0..7]                                                
///       set Puv_max = -128                                      -- PCBS_UNDERVOLTING_REG[8..15]                                               
///
///       set enable_LPFT_function = 0                            -- Local Pstate Frequency Target mechanism disabled                           
///                                                               -- PCBS_Local_Pstate_Frequency_Target_Control_Register[20]                    
///
///       //  Issue reset to PCBS-PM                                                                                                            
///       set endp_reset_pm_only  = 1                             -- Issue reset to PCBS-PM                                                     
///                                                               -- PMGP1_REG[9]                                                               
///      -- unset off reset in the next cycle??                                                                                                 
///       set endp_reset_pm_only  = 0                             -- PMGP1_REG[9]                                                               
///
///   ] --end loop over all valid chiplets                                                                                                      
///
///   }   //end PM_RESET -mode                                                                                                                  
///
///
///  \endverbatim

/// HostBoot_IPL_Flow_v93_occ.odt

/// RESET
///
///-Force safe mode (uses Psafe Pstate setting) in EX chiplet (multicastable) (for safety) (with removal of MIN functions (design change))
///-Check PCBS-PM state/status that Psafe (Pstate) as been achieved and that FSM are in a stable state.
///   -If  timeout, indicate that restart of OCC is to not occur (means are TBD)
///   -Write DPLL Frequ Control Reg with the frequency (not PState!) that represents  the minimum of Psafe or Global Actual as seen in the PCBS.
///-Chiplets forced (via PCBS) into DPLL Override / PState disabled mode (whatever the above PState turned out to be)
///-The frequency value determined by Psafe/Vsafe is locked from changes by the PState mechanism.  This allows the PCBS to be re-initialized.
///-Force OCC SPR Mode  in EX chiplet (multicastable)
///-Force *global_en PState to off  to cease interrupts to PMC (Global, AutoOverride, Idle)  in EX chiplet (multicable)
///-Reset Pmin and Pmax to "wide open in EX chiplet (multicastable)
///-Chiplets resonant clocking (via PCBS) disabled
///-This allows the PCBS to be re-initialized blindly
///-It is debatable whether this is necessary as resonant clock can continue to operate while the OCC reset is being performed and while the chiplet is running at Psafe).
///-OCC Heartbeat disable
///-Will be enabled by OCCFW (not FAPI)
///-If Venice,  Chiplet IVRMs put into bypass mode and then disabled
///-This allows the initfiles and procedures to reload the Local PState and VDS Tables
///-Undervolting values reset:  Kuv to 0; Puv_min and Puv_max each set to -128 each (to disable)
///-Local Pstate Frequency Target mechanism disabled
///-OCCFW will enable it
///-Issue reset to PCBS-PM (dial endp_reset_pm_only)
///-DPLL Frequ Control Reg is NOT reset
///-(Scan only value would be (tentative) 1GHz)
///
///
/// CONFIG
///
///  PState translation
///       convert_safe_freq() - With ATTR_PM_SAFE_FREQUENCY (binary in MHz)
///          and ATTR_PM_PSTATE0_FREQUENCY (binary in Mhz) produce ATTR_PM_SAFE_PSTATE
///  Resonant Clocking settings (band definitions from frequency to Pstate)
///      convert_resclk_freqs_to_pstates() - Convert the following frequency
///      platform attributes (binary in MHz) to feature Pstate attributes.
///      The conversion uses ATTR_PM_PSTATE0_FREQUENCY.
///             Input platform attributes
///             ATTR_PM_RESONANT_CLOCK_FULL_CLOCK_SECTOR_BUFFER_FREQUENCY
///             ATTR_PM_RESONANT_CLOCK_LOW_BAND_LOWER_FREQUENCY
///             ATTR_PM_RESONANT_CLOCK_LOW_BAND_UPPER_FREQUENCY
///             ATTR_PM_RESONANT_CLOCK_HIGH_BAND_LOWER_FREQUENCY
///             ATTR_PM_RESONANT_CLOCK_HIGH_BAND_UPPER_FREQUENCY
///             output feature attributes
///             ATTR_PM_RESONANT_CLOCK_FULL_CSB_PSTATE
///             ATTR_PM_RESONANT_CLOCK_LFRLOW_PSTATE
///             ATTR_PM_RESONANT_CLOCK_LFRUPPER_PSTATE
///             ATTR_PM_RESONANT_CLOCK_HFRLOW_PSTATE
///             ATTR_PM_RESONANT_CLOCK_HFRHIGH_PSTATE
///  PFET Sequencing Delays
///         convert_pfet_delays() - Convert the following delays from platform
///         attributes (binary in nanoseconds) to PFET delay value feature attributes.
///         The conversion uses ATTR_PROC_NEST_FREQUENCY.
///             Input platform attributes
///             ATTR_PM_PFET_POWERUP_CORE_DELAY0
///             ATTR_PM_PFET_POWERUP_CORE_DELAY1
///             ATTR_PM_PFET_POWERUP_ECO_DELAY0
///             ATTR_PM_PFET_POWERUP_ECO_DELAY1
///             ATTR_PM_PFET_POWERDOWN_CORE_DELAY0
///             ATTR_PM_PFET_POWERDOWN_CORE_DELAY1
///             ATTR_PM_PFET_POWERDOWN_ECO_DELAY0
///             ATTR_PM_PFET_POWERDOWN_ECO_DELAY1
///             output feature attributes
///             ATTR_PM_PFET_POWERUP_CORE_DELAY0_VALUE
///             ATTR_PM_PFET_POWERUP_CORE_DELAY1_VALUE
///             ATTR_PM_PFET_POWERUP_CORE_SEQUENCE_DELAY_SELECT
///             ATTR_PM_PFET_POWERUP_ECO_DELAY0_VALUE
///             ATTR_PM_PFET_POWERUP_ECO_DELAY1_VALUE
///             ATTR_PM_PFET_POWERUP_ECO_SEQUENCE_DELAY_SELECT
///             ATTR_PM_PFET_POWERDOWN_CORE_DELAY0_VALUE
///             ATTR_PM_PFET_POWERDOWN_CORE_DELAY1_VALUE
///             ATTR_PM_PFET_POWERDOWN_CORE_SEQUENCE_DELAY_SELECT
///             ATTR_PM_PFET_POWERDOWN_ECO_DELAY0_VALUE
///             ATTR_PM_PFET_POWERDOWN_ECO_DELAY1_VALUE
///             ATTR_PM_PFET_POWERDOWN_ECO_SEQUENCE_DELAY_SELECT
/// INIT
///
/// -Resets DPLL_CPM_PARM_REG.cpm_filter_enable
///     -For reset case, disable all "global_en" bits in PMCR and PMICR;  this
///         keeps Global Pstate Request from occuring to the PMC until it has
///         been initialized.  OCCFW to be do this.
/// - PMICR default value adjustment (Hardware flush 0 -> restore to TBD for reset )
///     -How does policy influence the PMICR Pstate values?
///     -Base:  run at the turbo value fixed
///     -Enhancement:  run at the highest Pstate value on the chip. (needs power
///         projection to judge worth).
///     -latency enable
///     -Not planned at this time.
/// OLD-DOC - Sleep / Winkle -> Fast / Deep configuration
/// OLD-DOC - Restore to Deep Sleep and Deep Winkle upon reset
/// OLD-DOC - PMCR default value adjustment (Hardware flush 0 -> restore to 0 for
///     reset case) SCAN0
/// OLD-DOC     -For reset case, disable all “global_en” bits in PMCR and PMICR;
///                 this keeps Global Pstate Request from occuring to the PMC until
///                 it has been initialized.  OCCFW to be do this
/// OLD-DOC - PMICR default value adjustment (Hardware flush 0 -> restore to 0 for
///                 reset ) SCAN0



/// \todo add to required proc ENUM requests
///

// -----------------------------------------------------------------------------
// Includes
// -----------------------------------------------------------------------------
#include "p8_pm.H"
#include "p8_pcbs_init.H"



extern "C" {

using namespace fapi;

// -----------------------------------------------------------------------------
// Constant definitions
// -----------------------------------------------------------------------------

// Macros to enhance readability yet provide for error handling
// Assume the error path is to break out of the current loop.  If nested loops
// are employed, the error_flag can be used to break out of the necessary
// levels.
//
// Set Double Word Scan0
#define SETDWSCAN0(_mi_target, _mi_address, _mi_buffer, _mi_reset_value){   \
    e_rc = data.setDoubleWord(0, _mi_reset_value);                          \
    if(e_rc)                                                                \
    {                                                                       \
        FAPI_ERR("Set DoubleWord failed. With rc = 0x%x", (uint32_t)e_rc);  \
        l_rc.setEcmdError(e_rc);                                            \
        error_flag=true;                                                    \
        break;                                                              \
    }                                                                       \
    FAPI_DBG("Scan0 equivalent reset of 0x%08llx to 0x%16llX",              \
                 _mi_address, _mi_reset_value);                             \
    l_rc = fapiPutScom(_mi_target, _mi_address, _mi_buffer);                \
    if(!l_rc.ok())                                                          \
    {                                                                       \
        FAPI_ERR("PutScom error to address 0x%08llx", _mi_address);         \
        error_flag=true;                                                    \
        break;                                                              \
    }                                                                       \
}

// Set Word Scan0
#define SETSCAN0(_mi_target, _mi_address, _mi_buffer, _mi_reset_value){     \
    e_rc = data.setWord(0, _mi_reset_value);                                \
    if(e_rc)                                                                \
    {                                                                       \
        FAPI_ERR("Set Word failed. With rc = 0x%x", (uint32_t)e_rc);        \
        l_rc.setEcmdError(e_rc);                                            \
        error_flag=true;                                                    \
        break;                                                              \
    }                                                                       \
    FAPI_DBG("Scan0 equivalent reset of 0x%08llx to 0x%08X",                \
                 _mi_address, _mi_reset_value);                             \
    l_rc = fapiPutScom(_mi_target, _mi_address, _mi_buffer);                \
    if(!l_rc.ok())                                                          \
    {                                                                       \
        FAPI_ERR("PutScom error to address 0x%08llx", _mi_address);         \
        error_flag=true;                                                    \
        break;                                                              \
    }                                                                       \
}

// PCBS EX address
#define EXADDR(_mi_address, _mi_ex){                                        \
     _mi_address + (_mi_ex * 0x01000000)                                    \
}


//------------------------------------------------------------------------------
//Start scan zero value
//------------------------------------------------------------------------------
/// \todo   Review scan0 values

CONST_UINT64_T( PMGP0_REG_0x100F0100_scan0                              ,  ULL(0x8030010C21000000) );
CONST_UINT64_T( PMGP1_REG_0x100F0103_scan0                              ,  ULL(0x6C00000000000000) );
CONST_UINT64_T( EX_PFVddCntlStat_REG_0x100F0106_scan0                   ,  ULL(0x0A00000000000000) );
CONST_UINT64_T( EX_PFVcsCntlStat_REG_0x100F010E_scan0                   ,  ULL(0xFFF0FFF080800000) );     //1000 0000 1000 000
CONST_UINT64_T( EX_PMErrMask_REG_0x100F010A_scan0                       ,  ULL(0x00000000));
CONST_UINT64_T( EX_PMSpcWkupFSP_REG_0x100F010B_scan0                    ,  ULL(0x00000000));
CONST_UINT64_T( EX_PMSpcWkupOCC_REG_0x100F010C_scan0                    ,  ULL(0x00000000));    // This is different than the hardware
CONST_UINT64_T( EX_PMSpcWkupPHYP_REG_0x100F010D_scan0                   ,  ULL(0x00000000));
CONST_UINT64_T( EX_CorePFPUDly_REG_0x100F012C_scan0                     ,  ULL(0x00000000));
CONST_UINT64_T( EX_CorePFPDDly_REG_0x100F012D_scan0                     ,  ULL(0x00000000));
CONST_UINT64_T( EX_CorePFVRET_REG_0x100F0130_scan0                      ,  ULL(0x00000000));
CONST_UINT64_T( EX_ECOPFPUDly_REG_0x100F014C_scan0                      ,  ULL(0x00000000));
CONST_UINT64_T( EX_ECOPFPDDly_REG_0x100F014D_scan0                      ,  ULL(0x00000000));
CONST_UINT64_T( EX_ECOPFVRET_REG_0x100F0150_scan0                       ,  ULL(0x00000000));
CONST_UINT64_T( EX_FREQCNTL_0x100F0151_scan0                            ,  ULL(0x32320000));   // "0011 0010 0011 0010 000000000000" ;
CONST_UINT64_T( EX_DPLL_CPM_PARM_REG_0x100F0152_scan0                   ,  ULL(0x00000200));   // "0000 0000 0000 0000 0000 0010 0000000" ;
CONST_UINT64_T( EX_PCBS_iVRM_Control_Status_Reg_0x100F0154_scan0        ,  ULL(0x00000000));
CONST_UINT64_T( EX_PCBS_iVRM_Value_Setting_Reg_0x100F0155_scan0         ,  ULL(0x00000000));
CONST_UINT64_T( EX_PCBSPM_MODE_REG_0x100F0156_scan0                     ,  ULL(0x01000000));    //"0000 0001 0000 0000 00" ;
CONST_UINT64_T( EX_PCBS_Power_Management_Control_Reg_0x100F0159_scan0   ,  ULL(0x00000000)) ;
CONST_UINT64_T( EX_PCBS_PMC_VF_CTRL_REG_0x100F015A_scan0                ,  ULL(0x00000000));
CONST_UINT64_T( EX_PCBS_UNDERVOLTING_REG_0x100F015B_scan0               ,  ULL(0x00000000));
CONST_UINT64_T( EX_PCBS_Pstate_Index_Bound_Reg_0x100F015C_scan0         ,  ULL(0x00000000));
CONST_UINT64_T( EX_PCBS_Power_Management_Bounds_Reg_0x100F015D_scan0    ,  ULL(0x807F0000));
CONST_UINT64_T( EX_PCBS_PSTATE_TABLE_CTRL_REG_0x100F015E_scan0          ,  ULL(0x00000000)) ;
CONST_UINT64_T( EX_PCBS_Pstate_Step_Target_Register_0x100F0160_scan0    ,  ULL(0x00000000)) ;
CONST_UINT64_T( EX_PCBS_iVRM_VID_Control_Reg0_0x100F0162_scan0          ,  ULL(0x00000000));
CONST_UINT64_T( EX_PCBS_iVRM_VID_Control_Reg1_0x100F0163_scan0          ,  ULL(0x00000000));
CONST_UINT64_T( EX_PCBS_OCC_Heartbeat_Reg_0x100F0164_scan0              ,  ULL(0x00000000));
CONST_UINT64_T( EX_PCBS_Resonant_Clock_Control_Reg0_0x100F0165_scan0    ,  ULL(0x4000000000000000)) ; //"0100 00000000000000000000000000000000000000" ;
CONST_UINT64_T( EX_PCBS_Resonant_Clock_Control_Reg1_0x100F0166_scan0    ,  ULL(0x00000000));
CONST_UINT64_T( EX_PCBS_Local_Pstate_Frequency_Target_Control_Register_0x100F0168_scan0 , ULL(0x00000000));

    // End scan zero value


// ----------------------------------------------------------------------
// Global variables
// ----------------------------------------------------------------------

// ----------------------------------------------------------------------
// Function prototypes
// ----------------------------------------------------------------------

// Reset function
fapi::ReturnCode
p8_pcbs_init_reset  (  const fapi::Target& i_target,
                       struct_pcbs_val_init_type& pcbs_val_init);
// Config function
fapi::ReturnCode
p8_pcbs_init_config (  const fapi::Target&  i_target);

// Init function
fapi::ReturnCode
p8_pcbs_init_init  (  const fapi::Target& i_target);

// SCAN0 function
fapi::ReturnCode
p8_pcbs_init_scan0(const Target &i_target, uint8_t i_ex_number);

// ----------------------------------------------------------------------
// Function definitions
// ----------------------------------------------------------------------

// ----------------------------------------------------------------------
/**
 * p8_pcbs_init calls the underlying routine based on mode parameter
 *
 * @param[in] i_target Chip target
 * @param[in] mode     Control mode for the procedure
 *                     PM_INIT, PM_CONFIG, PM_RESET
 *
 * @retval ECMD_SUCCESS
 * @retval ERROR defined in xml
 */
fapi::ReturnCode
p8_pcbs_init( const Target& i_target, uint32_t i_mode)
{
    fapi::ReturnCode l_rc;

    //Declare parms struct
    struct_pcbs_val_init_type  pcbs_val_init;

    FAPI_INF("Executing p8_pcbs_init in mode %x", i_mode);

    do
    {

        if ( i_mode == PM_CONFIG )
        {
            l_rc=p8_pcbs_init_config(i_target);
            if (l_rc)
            {
              FAPI_ERR("p8_pcbs_init_config failed. With l_rc = 0x%x", (uint32_t)l_rc);
              break;
            }

        }
        else if ( i_mode == PM_INIT )
        {

            l_rc=p8_pcbs_init_init(i_target);
            if (l_rc)
            {
              FAPI_ERR("p8_pcbs_init_init failed. With l_rc = 0x%x", (uint32_t)l_rc);
              break;
            }
        }
        else if ( i_mode == PM_RESET )
        {
            // ----------------------------------------------------------------------
            // Assign default values
            // ----------------------------------------------------------------------

            /// \todo CHECK: Review those defaults
            pcbs_val_init.MAX_PSAFE_FSM_LOOPS  =   20; // PMSR poll attempts
            pcbs_val_init.MAX_DELAY =   1000000;       // in ns; 1ms
            pcbs_val_init.MAX_SIM_CYCLES =   1000;
            pcbs_val_init.GLOBAL_ACTUAL_PSTATE = -128; // Global Actual PSTATE
            pcbs_val_init.MIN_PSTATE = -128 ;          // Default
            pcbs_val_init.FNOM = 128;                  // Default
            pcbs_val_init.DPLL_FMIN = 50;              // \WHAT?
            pcbs_val_init.DPLL_FMAX = 50;              // \WHAT?
            pcbs_val_init.PMIN_CLIP = -128 ;           // Default
            pcbs_val_init.PMAX_CLIP =  127 ;           // Default
            pcbs_val_init.KUV = 0;                     // Default
            pcbs_val_init.ivrms_enabled = 1 ;

       //            l_rc = FAPI_ATTR_GET(   ATTR_PM_IVRMS_ENABLED,
       //                                    &i_target,
       //                                    pcbs_val_init.ivrms_enabled);
            if (l_rc)
            {
                FAPI_ERR("fapiGetAttribute of ATTR_PM_IVRMS_ENABLED with rc = 0x%x", (uint32_t)l_rc);
                break;
            }

//             l_rc = FAPI_ATTR_GET(   ATTR_PM_SAFE_PSTATE,
//                                     &i_target,
//                                     pcbs_val_init.PSAFE);
            if (l_rc)
            {
                FAPI_ERR("fapiGetAttribute of ATTR_PM_SAFE_PSTATE with rc = 0x%x", (uint32_t)l_rc);
                break;
            }

//             l_rc = FAPI_ATTR_GET(   ATTR_PM_PSTATE_UNDERVOLTING_MINIMUM,
//                                     &i_target,
//                                     pcbs_val_init.PUV_MIN);
           if (l_rc)
            {
                FAPI_ERR("fapiGetAttribute of ATTR_PM_PSTATE_UNDERVOLTING_MINIMUM with rc = 0x%x", (uint32_t)l_rc);
                break;
            }

 //            l_rc = FAPI_ATTR_GET(   ATTR_PM_PSTATE_UNDERVOLTING_MAXIMUM,
//                                     &i_target,
//                                     pcbs_val_init.PUV_MAX);
            if (l_rc)
            {
                FAPI_ERR("fapiGetAttribute of ATTR_PM_PSTATE_UNDERVOLTING_MAXIMUM with rc = 0x%x", (uint32_t)l_rc);
                break;
            }

            l_rc = p8_pcbs_init_reset( i_target, pcbs_val_init);
            if (l_rc)
            {
                FAPI_ERR("p8_pcbs_init_reset failed. With l_rc = 0x%x", (uint32_t)l_rc);
                break;
            }
        }
        else
        {
            FAPI_ERR("Unknown mode passed to p8_pcbs_init. Mode %x ....", i_mode);
            //TODO RTC: 71328 - unused variable const uint64_t& MODE = (uint32_t)i_mode;
            FAPI_SET_HWP_ERROR(l_rc, RC_PROC_PCBS_CODE_BAD_MODE);
        }
    } while(0);
    FAPI_INF("Exiting p8_pcbs_init ...");

    return l_rc;

}


//------------------------------------------------------------------------------
/**
 * Transform Platform Attribute for  PCBS to Feature Attributes
 *
 * @param[in] i_target Chip target
 *
 * @retval ECMD_SUCCESS
 * @retval ERROR defined in xml
 */
fapi::ReturnCode
p8_pcbs_init_config(const Target& i_target)
{
  fapi::ReturnCode l_rc;

  /// Function moved in p8_pfet_int.C
  /// FAPI_DBG("*************************************");
  /// FAPI_INF("p8_pcbs_init_config beginning ...");
  /// FAPI_DBG("*************************************");
  ///

  return l_rc;

} //end CONFIG

//------------------------------------------------------------------------------
/**
 * Initialize the PCBS-PM macro for all functional and enabled EX chiplets
 *
 * @param[in] i_target Chip target
 *
 * @retval ECMD_SUCCESS
 * @retval ERROR defined in xml
 */
fapi::ReturnCode
p8_pcbs_init_init(const Target& i_target)
{
    fapi::ReturnCode                l_rc;
    uint32_t                        e_rc;              // eCmd returncode

    ecmdDataBufferBase              data(64);
    ecmdDataBufferBase              mask(64);

    // Variables
    std::vector<fapi::Target>       l_exChiplets;
    fapi::TargetState               l_state = TARGET_STATE_FUNCTIONAL;
    uint8_t                         l_functional = 0;
    uint8_t                         l_ex_number = 0;
    uint64_t                        address;
    //TODO RTC: 71328 - hack to indicate unused
    bool                            __attribute__((unused)) error_flag = false;

    FAPI_INF("p8_pcbs_init_init beginning for target %s ...", i_target.toEcmdString());

    do
    {
        l_rc = fapiGetChildChiplets(i_target,
                                    fapi::TARGET_TYPE_EX_CHIPLET,
                                    l_exChiplets,
                                    l_state);
        if (l_rc)
        {
            FAPI_ERR("fapiGetChildChiplets with rc = 0x%x", (uint32_t)l_rc);
            break;
        }

        FAPI_DBG("chiplet vector size => %u", l_exChiplets.size());

        // For each chiplet in the functional list
        for (uint8_t c=0; c< l_exChiplets.size(); c++)
        {
            FAPI_DBG("\tLoop Variable %d ",c);

            l_rc = FAPI_ATTR_GET(ATTR_FUNCTIONAL, &l_exChiplets[c], l_functional);
            if (l_rc)
            {
                FAPI_ERR("fapiGetAttribute of ATTR_FUNCTIONAL with rc = 0x%x", (uint32_t)l_rc);
                break;
            }


            if (!l_functional)
            {
                FAPI_DBG("Core number = %d  is not functional", c);
                // Iterate
                continue;
            }

            // The ex is functional let's build the SCOM address
            l_rc = FAPI_ATTR_GET(ATTR_CHIP_UNIT_POS, &l_exChiplets[c], l_ex_number);
            if (l_rc)
            {
                FAPI_ERR("No functional chiplets exist");
                FAPI_ERR("fapiGetAttribute of ATTR_CHIP_UNIT_POS with rc = 0x%x", (uint32_t)l_rc);
                break;
            }

            FAPI_DBG("Core number = %d", l_ex_number);
         
            // Set DPLL Lock Replacement value (15:23) = 2 (eg bit 22 = 1)          
            FAPI_INF ("Set DPLL Lock Replacement value of EX_DPLL_CPM_PARM_REG_0x1*0F0152 ");

            address =  EX_DPLL_CPM_PARM_REG_0x100F0152 + 
                        (l_ex_number * 0x01000000);
            GETSCOM(i_target, address, data);
            
            e_rc  = data.setBit(22);
            E_RC_CHECK(e_rc, l_rc);

            PUTSCOM(i_target, address, data);
            
            //  ******************************************************************
            //  - Enable DPLL Lock Replacement mode
            //  ******************************************************************
            FAPI_INF("Set DPLL Lock Replacement mode");

            address = EX_PCBSPM_MODE_REG_0x100F0156 +
                                (l_ex_number * 0x01000000);

            GETSCOM(i_target, address, data );

            e_rc |= data.setBit(7);            
            E_RC_CHECK(e_rc, l_rc);

            PUTSCOM(i_target, address, data );
            
            //  ******************************************************************
            //  - Power Management Control Reg
            //  ******************************************************************
            FAPI_INF("Clear Power Management Control Reg");
            
            // This can only be done if PMGP1(11) (pm_spr_override_en) is set
            e_rc = data.setBit(10);
            E_RC_CHECK(e_rc, l_rc);

            address =  EX_PMGP1_OR_0x100F0105 + (l_ex_number * 0x01000000);
            PUTSCOM(i_target, address, data);


            // Clear buffer
            e_rc = data.flushTo0();
            E_RC_CHECK(e_rc, l_rc);

            address =  EX_PCBS_Power_Management_Control_Reg_0x100F0159 +
                                (l_ex_number * 0x01000000);
            PUTSCOM(i_target, address, data);

            //  ******************************************************************
            //  - Power Management Idle Control Reg
            //  ******************************************************************
            FAPI_INF("Clear Power Management Idle Control Reg");
          
            // Clear buffer
            e_rc = data.flushTo0();
            E_RC_CHECK(e_rc, l_rc);

            address =  EX_PCBS_Power_Management_Idle_Control_Reg_0x100F0158 +
                                (l_ex_number * 0x01000000);
            PUTSCOM(i_target, address, data);

            FAPI_INF ("PMCR default value adjustment (Hardware flush 0) of EX_PCBS_Power_Management_Idle_Control_Reg_0x1*0F0158 " );


        }  //END FOR
        if (!l_rc.ok() )
        {
            break;
        }
    } while(0);

    return l_rc;

}  //end INIT


//------------------------------------------------------------------------------
/**
 * Initialize the PCBS-PM macro for all functional and enabled EX chiplets
 *
 * @param[in] i_target Chip target
 * @param[in] mode     Control mode for the procedure
 *                     PM_INIT, PM_CONFIG, PM_RESET
 *
 * @retval ECMD_SUCCESS
 * @retval ERROR defined in xml
 */
fapi::ReturnCode
p8_pcbs_init_reset(const Target &i_target, struct_pcbs_val_init_type &pcbs_val_init)
{
    fapi::ReturnCode            l_rc;
    uint32_t                    e_rc;           // ecmd returncode

    ecmdDataBufferBase          data(64);
    ecmdDataBufferBase          mask(64);


    // Variables
    std::vector<fapi::Target>   l_exChiplets;
    fapi::TargetState           l_state = TARGET_STATE_FUNCTIONAL;
    uint8_t                     l_functional = 0;
    uint8_t                     l_ex_number = 0;
    uint64_t                    address;
    //TODO RTC: 71328 - hack to indicate unused
    bool                        __attribute__((unused)) error_flag = false;
    uint32_t                    loopcount = 0; // number of times PCBS-PMSR has been checked

    FAPI_INF("p8_pcbs_init_reset beginning for target %s ...", i_target.toEcmdString());
    do
    {
        l_rc = fapiGetChildChiplets(i_target,
                                    fapi::TARGET_TYPE_EX_CHIPLET,
                                    l_exChiplets,
                                    l_state);
        if (l_rc)
        {
            FAPI_ERR("fapiGetChildChiplets with rc = 0x%x", (uint32_t)l_rc);
            break;
        }

        FAPI_DBG("Chiplet vector size => %u", l_exChiplets.size());

        // For each chiplet
        for (uint8_t c=0; c< l_exChiplets.size(); c++)
        {
            FAPI_DBG("\tLoop Variable %d ",c);

            l_rc = FAPI_ATTR_GET(ATTR_FUNCTIONAL, &l_exChiplets[c], l_functional);
            if (l_rc)
            {
              FAPI_ERR("fapiGetAttribute of ATTR_FUNCTIONAL with rc = 0x%x", (uint32_t)l_rc);
              break;
            }

            if (!l_functional)
            {
                FAPI_DBG("Core number = %d  is not functional", c);
                // Iterate
                continue;
            }

            // The ex is functional let's build the SCOM address
            l_rc = FAPI_ATTR_GET(ATTR_CHIP_UNIT_POS, &l_exChiplets[c], l_ex_number);
            if (l_rc)
            {
                FAPI_ERR("fapiGetAttribute of ATTR_CHIP_UNIT_POS with rc = 0x%x", (uint32_t)l_rc);
                break;
            }

            FAPI_DBG("\tCore number = %d", l_ex_number);

            //  ******************************************************************
            //  Set the regs back to scan0 state -  NO... NOT HERE!
            //  ******************************************************************

            l_rc = p8_pcbs_init_scan0(i_target, l_ex_number);
            if (l_rc)
            {
                FAPI_ERR(" p8_pcbs_init_scan0 failed. With l_rc = 0x%x", (uint32_t)l_rc);
                error_flag = true;
                break;
            }


            //  ******************************************************************
            //  Force safe mode if Pstates are enabled.
            //  ******************************************************************
            //  - set PCBS_PM_PMGP1_REG_1
            //              [12] force_safe_mode = 1
            //  ******************************************************************

            address = EX_PCBSPM_MODE_REG_0x100F0156 +
                                (l_ex_number * 0x01000000);
            GETSCOM(i_target, address, data);
            FAPI_DBG("\tPCBS_MODE_REG value 0x%16llX", data.getDoubleWord(0));
            
            if (data.isBitSet(0))  // Pstates enabled
            {

                FAPI_INF("Pstate enabled - Force safe mode");

                // Using Write OR to just set bit12
                // Clear buffer
                e_rc = data.flushTo0();
                E_RC_CHECK(e_rc, l_rc);

                e_rc = data.setBit(12);    // force_safe_mode = 1
                E_RC_CHECK(e_rc, l_rc);

                address =  EX_PMGP1_OR_0x100F0105 +
                                (l_ex_number * 0x01000000);;
                PUTSCOM(i_target, address, data);

                FAPI_INF("Forced Safe Mode");

                //  ******************************************************************
                //  psafe Pstate achived AND FSM-stable ?
                //  ******************************************************************
                //  ******************************************************************
                //  - PCBS_POWER_MANAGEMENT_STATUS_REG[33] safe_mode_active
                //  - PCBS_POWER_MANAGEMENT_STATUS_REG[36] all_fsms_in_safe_state
                //
                //  ******************************************************************
                FAPI_INF("Psafe Pstate and FSM-stable?");

                loopcount = 0;

                address =  EX_PCBS_POWER_MANAGEMENT_STATUS_REG_0x100F0153 +
                                    (l_ex_number * 0x01000000);
                GETSCOM(i_target, address, data);

                // loop until  (safe_mode_active AND all_fsms_in_safe_state)
                while( data.isBitClear( 33 ) || data.isBitClear( 36 )  )
                {
                    FAPI_DBG("\t loopcount => %d ",loopcount  );
                    // OR timeout .... set to 20 loops
                    if( ++loopcount > pcbs_val_init.MAX_PSAFE_FSM_LOOPS )
                    {
                        FAPI_ERR("Gave up waiting for Psafe Pstate and FSM-stable!" );
                        ///TODO RTC: 71328 - unused variable const uint64_t& LOOPCOUNT = (uint32_t)loopcount;
                        ///TODO RTC: 71328 - unused variable const uint64_t& PMSR = data.getDoubleWord(0);
                        FAPI_SET_HWP_ERROR(l_rc, RC_PROC_PCBS_CODE_SAFE_FSM_TIMEOUT);
//                        error_flag = true;
                        break;
                    }

                    FAPI_DBG("Read of PCBS_POWER_MANAGEMENT_STATUS_REG_0x1*0F0153 content :  %016llX",
                                    data.getDoubleWord(0));

                    FAPI_DBG("Is Psafe Pstate and FSM-stable ? ");
                    FAPI_DBG("\t Wait DELAY: %d  ", pcbs_val_init.MAX_DELAY);
                    FAPI_DBG("\t Wait SimCycles: %d  ", pcbs_val_init.MAX_SIM_CYCLES);

                    l_rc =  fapiDelay(pcbs_val_init.MAX_DELAY, pcbs_val_init.MAX_SIM_CYCLES);
                    if (l_rc)
                    {
                        FAPI_ERR("fapiDelay(MAX_DELAY, MAX_SIM_CYCLES) failed. With rc = 0x%x", (uint32_t)l_rc);
//                        error_flag = true;
                        break;
                    }

                    // Read PMSR again
                    GETSCOM(i_target, address, data);

                }
                // if error, break the outer loop
                if (!l_rc.ok())
                {
                    break;
                }

                FAPI_INF("Psafe Pstate and FSM-stable is reached ...");
            }

            //  ******************************************************************
            //  DPLL settings
            //  ******************************************************************
            //  ******************************************************************
            //  - enable dpll override
            //     - PCBS_PM_PMGP1_REG_1[10]  dpll_freq_override_enable
            //
            // \bug the following are removed as the pstate protocol would have
            // produced Psave anyway.  To mode frequency without voltage context
            // is not correct.
            //  - get Psafe and global actual pstate
            //  - calculate minPstate
            //  - calculate dpll_fmin  = fnom + minPstate
            //  - set dpll_fmin
            //  - set dpll_fmax
            //  ******************************************************************

            FAPI_INF("Hold the DPLL to the value that the last Pstate represents");

            // Write calculated values to FREQ_CTRL_REG
            address = EX_FREQCNTL_0x100F0151 + (l_ex_number * 0x01000000);
            GETSCOM(i_target, address, data);

            FAPI_DBG(" Pre write content of FREQ_CTRL_REG_0x1*0F0151 :  %016llX",
                            data.getDoubleWord(0));

            // Clear the DPLL bias;  did not clear other fields
            e_rc = data.clearBit(18, 4);
            E_RC_CHECK(e_rc, l_rc);

            PUTSCOM(i_target, address, data);

            // Lock the DPLL in via the override mode.  Note:  this DOES
            // allow for continued CPM enablement
            e_rc |= data.flushTo0();
            e_rc |= data.setBit(10);     // dpll_freq_override_enable
            E_RC_CHECK(e_rc, l_rc);

            address = EX_PMGP1_OR_0x100F0105 + (l_ex_number * 0x01000000);
            PUTSCOM(i_target, address, data);

            //  ******************************************************************
            //  - Disable Pstate mode
            //  - disable Pstate requests
            //  ******************************************************************
            FAPI_INF("Disable Pstate mode and disable Pstate requests");

            address = EX_PCBSPM_MODE_REG_0x100F0156 +
                                (l_ex_number * 0x01000000);

            GETSCOM(i_target, address, data );

            e_rc |= data.clearBit(0);       //Disable Pstate mode
            e_rc |= data.clearBit(2);       //Disable Pstate requests
            E_RC_CHECK(e_rc, l_rc);

            PUTSCOM(i_target, address, data );

            FAPI_INF("Disabled Pstate mode");

            //  ******************************************************************
            //   OCC SPR Mode
            //  ******************************************************************
            //  ******************************************************************
            //  - set PCBS_PM_PMGP1_REG_1
            //              [11] PM_SPR_OVERRIDE_EN = 1
            //  ******************************************************************
            FAPI_INF("Force PM_SPR_OVERRIDE");

            // Using Write OR to set bit11
            // Clear buffer
            e_rc  = data.flushTo0();
            e_rc |= data.setBit(11);    // Force OCC SPR Mode = 1
            E_RC_CHECK(e_rc, l_rc);

            address =  EX_PMGP1_OR_0x100F0105 + (l_ex_number * 0x01000000);
            PUTSCOM(i_target, address, data );

            FAPI_INF("Forced OCC SPR Mode");

            //  ******************************************************************
            //  - Clear Power Management Idle Control bits that allow Pstate
            //      requensts to occur
            //  - Can occur as SPR override is set
            //  ******************************************************************
            FAPI_INF("Disabling Global Pstate Request bits ");

            address =  EX_PCBS_Power_Management_Idle_Control_Reg_0x100F0158 +
                                (l_ex_number * 0x01000000);
            GETSCOM(i_target, address, data );

            e_rc |= data.clearBit(8);       // Disable Nap Pstate Enable
            e_rc |= data.clearBit(24);      // Disable Sleep Pstate Enable
            e_rc |= data.clearBit(40);      // Disable Winkle Pstate Enable
            E_RC_CHECK(e_rc, l_rc);

            PUTSCOM(i_target, address, data );

            // Auto overrides
            address =  EX_PCBS_Power_Management_Control_Reg_0x100F0159 +
                                (l_ex_number * 0x01000000);
            GETSCOM(i_target, address, data );

            e_rc |= data.clearBit(16);      // Disable Auto Override 0
            e_rc |= data.clearBit(17);      // Disable Auto Override 1
            E_RC_CHECK(e_rc, l_rc);

            PUTSCOM(i_target, address, data );

            FAPI_INF("Disabled Global Pstate Requests");

            //  ******************************************************************
            //  - Reset Pmin and Pmax
            //  ******************************************************************
            FAPI_INF("Reset Pmin and Pmax");

            // Clear data buffer
            e_rc |= data.flushTo0();
            e_rc |= data.setByte(0, pcbs_val_init.PMIN_CLIP); //Pmin_clip   =  -128
            e_rc |= data.setByte(1, pcbs_val_init.PMAX_CLIP); //Pmax_clip   =   127
            E_RC_CHECK(e_rc, l_rc);

            address = EX_PCBS_Power_Management_Bounds_Reg_0x100F015D +
                                (l_ex_number * 0x01000000);
            PUTSCOM(i_target, address, data );

            FAPI_DBG("Pmin/Pmax written to PCBS_Power_Management_Bounds_Reg :  %016llX",
                            data.getDoubleWord(0));
            FAPI_INF("\t Pmin_clip => %d and Pmax_clip  => %d ",
                            pcbs_val_init.PMIN_CLIP,
                            pcbs_val_init.PMAX_CLIP);

            //  ******************************************************************
            //  Disable RESCLK
            //  ******************************************************************
            FAPI_INF("Settings about RESCLK");

            ///  \todo : Is there more to things than this.
            // Using Write OR to just set bit22
            // Clear buffer
            e_rc = data.flushTo0();
            e_rc = data.setBit(22);     //disable RESCLK
            E_RC_CHECK(e_rc, l_rc);

            address = EX_GP3_OR_0x100F0014 + (l_ex_number * 0x01000000);
            PUTSCOM(i_target, address, data);

            FAPI_INF ("Disabled RESCLK, set bit 22 of GP3_REG_0_RWXx1*0F0012 " );

            //  ******************************************************************
            //  Disable OCC Heartbeat
            //  ******************************************************************
            address = EX_PCBS_OCC_Heartbeat_Reg_0x100F0164 +
                                (l_ex_number * 0x01000000);
            GETSCOM(i_target, address, data);

            FAPI_DBG(" Pre write content of PCBS_OCC_HEARTBEAT_REG_0x1*0F0164  :  %016llX",
                            data.getDoubleWord(0));

            e_rc = data.clearBit(8);     //OCC Heartbeat disable
            E_RC_CHECK(e_rc, l_rc);

            PUTSCOM(i_target, address, data);

            FAPI_INF ("OCC Heartbeat disabled, cleared bit 8 of PCBS_OCC_HEARTBEAT_REG_0x1*0F0164" );

            //  ******************************************************************
            //  IVRM Disable
            //  ******************************************************************
            //  ******************************************************************
            //  - disable ivrms
            //  - set bypass mode
            //  ******************************************************************
            // \todo DOES THIS WORK IF THE IVRMS ARE ACTIVE AND IN REGULATION????
            FAPI_INF("Disable IVRMs");

            if (pcbs_val_init.ivrms_enabled)
            {
                address =  EX_PCBS_iVRM_Control_Status_Reg_0x100F0154 +
                                (l_ex_number * 0x01000000);
                GETSCOM(i_target, address, data);
                FAPI_DBG(" Pre write content of PCBS_iVRM_Control_Status_Reg_0x1*0F0154  :  %016llX",
                                data.getDoubleWord(0));

                e_rc  = data.clearBit(0);      // disable ivrms
                e_rc |= data.clearBit(4);      // ivrm_core_vdd_bypass_b
                e_rc |= data.clearBit(6);      // ivrm_core_vcs_bypass_b
                e_rc |= data.clearBit(8);      // ivrm_eco_vdd_bypass_b
                e_rc |= data.clearBit(10);     // ivrm_eco_vcs_bypass_b
                E_RC_CHECK(e_rc, l_rc);

                PUTSCOM(i_target, address, data);
                // Write twice since  ivrm_fsm_enable have to be 0 to enable the set the bypass modes
                PUTSCOM(i_target, address, data);

                FAPI_INF ("iVRMs disabled and in bypass-mode" );
            }

            //  ******************************************************************
            //  Disable undervolting
            //  ******************************************************************
            address =  EX_PCBS_UNDERVOLTING_REG_0x100F015B +
                                (l_ex_number * 0x01000000);
            GETSCOM(i_target, address, data);

            FAPI_DBG(" Pre write content of PCBS_UNDERVOLTING_REG_0x1*0F015B  :  %016llX",
                            data.getDoubleWord(0));

            e_rc |= data.setByte(0, pcbs_val_init.PUV_MIN);  //Puv_min   =  -128
            e_rc |= data.setByte(1, pcbs_val_init.PUV_MAX);  //Puv_max   =  -128
            e_rc |= data.setByte(2, pcbs_val_init.KUV);      //Kuv       =  0
            E_RC_CHECK(e_rc, l_rc);

            PUTSCOM(i_target, address, data);



            FAPI_DBG("\t PUV_MIN => %d ", pcbs_val_init.PUV_MIN );
            FAPI_DBG("\t PUV_MAX => %d ", pcbs_val_init.PUV_MAX );
            FAPI_DBG("\t KUV     => %d ", pcbs_val_init.KUV );

            FAPI_INF ("Undervolting values reset done" );

            //  ******************************************************************
            //  Disable Local Pstate Frequency Target mechanism
            //  ******************************************************************
            address =  EX_PCBS_Local_Pstate_Frequency_Target_Control_Register_0x100F0168
                            + (l_ex_number * 0x01000000);
            GETSCOM(i_target, address, data);

            e_rc |= data.clearBit(20);
            E_RC_CHECK(e_rc, l_rc);

            PUTSCOM(i_target, address, data);


            FAPI_INF ("Local Pstate Frequency Target mechanism disabled" );
        } // Chiplet loop
    } while(0);

    if (l_rc.ok())
    {
        FAPI_INF("Reset complete  ....");
    }

    return l_rc;
}   // end RESET

//------------------------------------------------------------------------------
/**
 * Set the PCBS-PM macro register back to the scan0 state for those that need
 * a known state for OCC firmware
 *
 * @param[in] i_target Chip target
 * @param[in] i_ex_number    EX chiplet number used to create correct addresses
 *
 * @retval ECMD_SUCCESS
 * @retval ERROR defined in xml
 */
fapi::ReturnCode
p8_pcbs_init_scan0(const Target &i_target, uint8_t i_ex_number)
{
    fapi::ReturnCode            l_rc;
    uint32_t                    e_rc;           // ecmd returncode
    ecmdDataBufferBase          data(64);
    uint64_t                    address;
    uint64_t                    reset_doubleword;
    uint32_t                    reset_word;
    ///TODO RTC: 71328 - hack to indicate unused
    bool                        __attribute__((unused)) error_flag = false;

    do
    {
        //  ******************************************************************
        //  initialize all pm_reg with scan-zero values upfront
        //  *****************************************************************
        FAPI_INF("Put selective PCBSLV_PM registers to the scan0 value that are touched by OCC firmware");

        // Register NOT reset
        //  EX_PMGP0_REG_0x100F0100 not reset as this control EX fencing
        //  EX_PMGP1_REG_0_RWXx100F0103 not reset as idle configuration is done
        //      by p8_poreslw_init
        //  EX_PFVddCntlStat_REG_0x100F0106 not reset has this would disrupt
        //      VDD to operational chiplets.
        //  EX_PFVddCntlStat_REG_0x100F010E not reset has this would disrupt
        //      VCS to operational chiplets
        //  EX_FREQCNTL_0x100F0151not reset has this would disrupt the frequency
        //      of operational chiplets
        //  EX_DPLL_CPM_PARM_REG_0x100F0152 not reset has this has DPLL control
        //      bits that could/would disrupt operational chiplets
        //  EX_PCBSPM_MODE_REG_0x100F0156 not reset as this register has DPLL
        //      control bits could/would disrupt operational chiplets
        //  EX_PCBS_Power_Management_Control_Reg_0x100F0159 not reset as this
        //      as this register only applies if the OCC is in control of PState
        //      and, upon reset, the OCC FW is designed to recover from ANY
        //      PState.  If PHYP is in control of PStates, this register must
        //      remain intact.
        //  EX_PCBS_OCC_Heartbeat_Reg_0x100F0164 not reset as this is reset fully
        //      by register accesses
        
        //----
        address =  EX_PCBS_Resonant_Clock_Control_Reg0_0x100F0165
                    + (i_ex_number * 0x01000000);
        reset_doubleword = EX_PCBS_Resonant_Clock_Control_Reg0_0x100F0165_scan0;
        SETDWSCAN0(i_target, address, data, reset_doubleword );

        //----
        address =  EX_PMErrMask_REG_0x100F010A
                    + (i_ex_number * 0x01000000);
        reset_word = EX_PMErrMask_REG_0x100F010A_scan0;
        SETSCAN0(i_target, address, data, reset_word );

        // OCC does not mess with the PFET delays so these are left in tact.

        //  This can only be done IF the IVRM is previously  disabled.
        address =  EX_PCBS_iVRM_Control_Status_Reg_0x100F0154
                    + (i_ex_number * 0x01000000);
        reset_word = EX_PCBS_iVRM_Control_Status_Reg_0x100F0154_scan0;
        SETSCAN0(i_target, address, data, reset_word );

        //----
        address =  EX_PCBS_iVRM_Value_Setting_Reg_0x100F0155
                    + (i_ex_number * 0x01000000);
        reset_word = EX_PCBS_iVRM_Value_Setting_Reg_0x100F0155_scan0;
        SETSCAN0(i_target, address, data, reset_word );

        //----
        address =  EX_PCBS_PMC_VF_CTRL_REG_0x100F015A
                    + (i_ex_number * 0x01000000);
        reset_word = EX_PCBS_PMC_VF_CTRL_REG_0x100F015A_scan0;
        SETSCAN0(i_target, address, data, reset_word );

        //----
        address =  EX_PCBS_Pstate_Index_Bound_Reg_0x100F015C
                    + (i_ex_number * 0x01000000);
        reset_word = EX_PCBS_Pstate_Index_Bound_Reg_0x100F015C_scan0;
        SETSCAN0(i_target, address, data, reset_word );

        //----
        address =  EX_PCBS_PSTATE_TABLE_CTRL_REG_0x100F015E
                    + (i_ex_number * 0x01000000);
        reset_word = EX_PCBS_PSTATE_TABLE_CTRL_REG_0x100F015E_scan0;
        SETSCAN0(i_target, address, data, reset_word );

        //----
        address =  EX_PCBS_iVRM_VID_Control_Reg0_0x100F0162
                    + (i_ex_number * 0x01000000);
        reset_word = EX_PCBS_iVRM_VID_Control_Reg0_0x100F0162_scan0;
        SETSCAN0(i_target, address, data, reset_word );

        //----
        address =  EX_PCBS_iVRM_VID_Control_Reg1_0x100F0163
                    + (i_ex_number * 0x01000000);
        reset_word = EX_PCBS_iVRM_VID_Control_Reg1_0x100F0163_scan0;
        SETSCAN0(i_target, address, data, reset_word );

        //----
        address =  EX_PCBS_Resonant_Clock_Control_Reg1_0x100F0166
                    + (i_ex_number * 0x01000000);
        reset_word = EX_PCBS_Resonant_Clock_Control_Reg1_0x100F0166_scan0;
        SETSCAN0(i_target, address, data, reset_word );

        /// \todo  Regcheck error check at latest model
        // address =  EX_PCBS_Local_Pstate_Frequency_Target_Control_Register_0x100F0168
        //          + (i_ex_number * 0x01000000);
        // reset_word = EX_PCBS_Local_Pstate_Frequency_Target_Control_Register_0x100F0168_scan0;
        // SETSCAN0(i_target, address, data, reset_word );
    } while(0);
    return l_rc;
}

} //end extern C

/*
*************** Do not edit this area ***************
This section is automatically updated by CVS when you check in this file.
Be sure to create CVS comments when you commit so that they can be included here.

$Log: p8_pcbs_init.C,v $
Revision 1.15  2013/04/12 01:31:59  stillgs

Added DPLL replacement enablement and value setting per hardware PManIrr testing

Revision 1.14  2013/04/01 04:18:13  stillgs

Remove Psafe calculation as this caused Grub crash;  format clean-up for RAS review readiness

Revision 1.13  2013/03/15 09:14:27  pchatnah
fixing jeshuas error handling suggestion

Revision 1.12  2013/03/13 12:51:51  pchatnah
fixing some debug codes

Revision 1.11  2013/02/27 03:50:00  stillgs
Clean up for the reset process.  Removed some old code for cleanliness.

Revision 1.10  2013/01/25 12:43:05  pchatnah
commenting out flusing DPLL_LOCK_TIMER_REPLACEMENT_VALUE to 0




*/
