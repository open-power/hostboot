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
/* begin_generated_IBM_copyright_prolog                            */
/*                                                                 */
/* This is an automatically generated copyright prolog.            */
/* After initializing,  DO NOT MODIFY OR MOVE                      */ 
/* --------------------------------------------------------------- */
/* IBM Confidential                                                */
/*                                                                 */
/* Licensed Internal Code Source Materials                         */
/*                                                                 */
/* (C)Copyright IBM Corp.  2014, 2014                              */
/*                                                                 */
/* The Source code for this program is not published  or otherwise */
/* divested of its trade secrets,  irrespective of what has been   */
/* deposited with the U.S. Copyright Office.                       */
/*  -------------------------------------------------------------- */
/*                                                                 */
/* end_generated_IBM_copyright_prolog                              */
// $Id: p8_pcbs_init.C,v 1.6 2012/10/12 15:33:19 rmaier Exp $
// $Source: /afs/awd.austin.ibm.com/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/p8_pcbs_init.C,v $
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
///
///
///
///
///
/// \todo   command order 
/// \todo   next --  > initialize all pm_reg with scan-zero values upfront
/// \todo   Clear definition/doc of parms and attributes required  at the beginning.
/// \todo   GP3 Changes Winkle fence changes
/// \todo   Review
///
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
///     if PM_CONFIG {
///                       PState translation
///                             convert_safe_freq()  
///                       Resonant Clocking settings (band definitions from frequency to Pstate)
///                             convert_resclk_freqs_to_pstates()
///                       PFET Sequencing Delays
///                             convert_pfet_delays()
///
///     else if PM_INIT {
///
///                       set CPM_FILTER_ENABLE = 0                                   -- #110f0152, DPLL_CPM_PARM_REG[10] = 0
///                                                                                   -- PMGP1_REG   WOX_OR 150f0105
///                       ATTR_PM_SLEEP_ENTRY (Assisted or Hardware)                  bit0  0=assisted 
///                       ATTR_PM_SLEEP_EXIT (Assisted or Hardware)                   bit1  0=assisted
///                       ATTR_PM_SLEEP_TYPE (Deep or Fast)                           bit2  0=fast
///                       ATTR_PM_WINKLE_ENTRY (Assisted or Hardware)                 bit3
///                       ATTR_PM_WINKLE_EXIT (Assisted or Hardware)                  bit4
///                       ATTR_PM_WINKLE_TYPE  (Deep or Fast)                         bit5
///
///                       set PMCR[0:39]  = 0                                        --  PMCR default value adjustment
///                                                                                  -- (Hardware flush 0 -> restore to 0 for reset case)
///                                                                                  -- #110f0159, PCBS_POWER_MANAGEMENT_CONTROL_REG
///
///                                   pm_spr_override_en must be set to write this reg!!
///                       set PMICR[0:47]  = 0                                       --  PMICR default value adjustment
///                                                                                  -- (Hardware flush 0 -> restore to TBD for reset case)
///                                                                                  -- #110f0158, PCBS_POWER_MANAGEMENT_IDLE_CONTROL_REG
///
///
///
///     } else if PM_RESET {
///
///                       loop over all valid chiplets {
///
///                           -- TODO check about 
///                           -- initialize all pm_reg with scan-zero values upfront
///
///                           //  Force safe mode
///                           set force_safe_mode = 1                                 -- Force safe mode (uses Psafe Pstate setting)
///                                                                                   -- XXXX multicast PCBS_PM_PMGP1_REG_1[12] = 1///
///                           //  psafe Pstate achived AND FSM-stable ?
///                           if psafePstate achived AND FSM-stable {                 -- Check PCBS-PM state/status that Psafe (Pstate) as been achieved and
///                                                                                   -- that FSM are in a stable state
///                                                                                   -- PCBS_POWER_MANAGEMENT_STATUS_REG[33] safe_mode_active
///                                                                                   -- PCBS_POWER_MANAGEMENT_STATUS_REG[36] all_fsms_in_safe_state
///                           } elsif timeout {
///                             --BAD RC: timeout - no PsafePstate or FSMs not stable
///                           }
///
///                           //  DPLL settings
///                           set dpll_freq_override_enable = 1                       -- PCBS_PM_PMGP1_REG_1[10] = 1
///                                                                                   -- only in override mode is a write to FREQ_CTRL_REG possible
///
///                           set minPstate = min(Psafe,global actual pstate)         -- PCBS_OCC_Heartbeat_Reg[17..24]  Psafe
///                                                                                   -- PCBS_POWER_MANAGEMENT_STATUS_REG[0..7] global actual pstate
///                           set dpll_min = fnom + minPstate(signed)                 -- FREQ_CTRL_REG[20..27]  pstate_dpll_fnom
///
///
///                           set dpll_fmin                                           -- FREQ_CTRL_REG[0..7]   scaninit: 00110010
///                           set dpll_fmax                                           -- FREQ_CTRL_REG[8..15]  scaninit: 00110010
///
///                           set pm_spr_override_en = 1                              -- Force OCC SPR Mode
///                                                                                   -- XXXX multicast PCBS_PM_PMGP1_REG_1[11] = 1
///
///                           set enable_Pstate_mode = 0                              -- PCBSPM_MODE_REG[0] ....multicast
///
///                           set enable_global_pstate_req = 0                        -- Force *global_en PState to off  to cease interrupts to PMC....multicast
///                                                                                   -- PCBSPM_MODE_REG[2]
///
///                                                                                   -- Reset Pmin and Pmax to wide open...multicast
///                           set Pmin_clip   =  -128                                 -- PCBS_Power_Management_Bounds_Reg[0..7]  0b10000000
///                           set Pmax_clip   =   127                                 -- PCBS_Power_Management_Bounds_Reg[8..15] 0b01111111
///
///
///                           //  Settings
///                           set resclk_dis = 1                                      -- Chiplets resonant clocking (via PCBS) disabled
///                                                                             	     -- EH.TPCHIP.NET.PCBSLPREV.GP3_REG[22]
///                                                                                   -- This is only ROX PCBS_Resonant_Clock_Control_Reg0[0]
///
///                           set occ_heartbeat_enable = 0                            -- OCC Heartbeat disable
///                                                                                   -- PCBS_OCC_Heartbeat_Reg[8]
///
///                           //  IVRM Setup
///                           get the mrwb attribute ivrms_enabled                    -- If '0' Salerno, if '1' Venice
///                           if ivrms_enabled {
///                               set ivrm_fsm_enable = 0                             -- PCBS_iVRM_Control_Status_Reg[0]
///                                                                                   -- ivrm_fsm_enable have be '0' to enable bypass_b writes
///                               set bypass_b mode = 0
///                                                        --ivrm_core_vdd_bypass_b   -- PCBS_iVRM_Control_Status_Reg[4]
///                                                        --ivrm_core_vcs_bypass_b   -- PCBS_iVRM_Control_Status_Reg[6]
///                                                        --ivrm_eco_vdd_bypass_b    -- PCBS_iVRM_Control_Status_Reg[8]
///                                                        --ivrm_eco_vcs_bypass_b    -- PCBS_iVRM_Control_Status_Reg[10]
///                           }
///
///                                                                                   -- Undervolting values reset
///                           set Kuv = 0                                             -- PCBS_UNDERVOLTING_REG[16..21]
///                                                                                   -- Puv_min and Puv_max  to disable
///                           set Puv_min = -128                                      -- PCBS_UNDERVOLTING_REG[0..7]
///                           set Puv_max = -128                                      -- PCBS_UNDERVOLTING_REG[8..15]
///
///                           set enable_LPFT_function = 0                            -- Local Pstate Frequency Target mechanism disabled
///                                                                                   -- PCBS_Local_Pstate_Frequency_Target_Control_Register[20]
///
///                           //  Issue reset to PCBS-PM
///                           set endp_reset_pm_only  = 1                             -- Issue reset to PCBS-PM
///                                                                                   -- PMGP1_REG[9]
///                          -- unset off reset in the next cycle??
///                           set endp_reset_pm_only  = 0                             -- PMGP1_REG[9]
///
///                       ] --end loop over all valid chiplets
///
///       }   //end PM_RESET -mode
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
///             PState translation
///                  convert_safe_freq() - With ATTR_PM_SAFE_FREQUENCY (binary in MHz) and ATTR_PM_PSTATE0_FREQUENCY (binary in Mhz) produce ATTR_PM_SAFE_PSTATE
///             Resonant Clocking settings (band definitions from frequency to Pstate) 
///                  convert_resclk_freqs_to_pstates() - Convert the following frequency platform attributes (binary in MHz) to feature Pstate attributes.  The conversion uses ATTR_PM_PSTATE0_FREQUENCY.
///                        Input platform attributes
///                        ATTR_PM_RESONANT_CLOCK_FULL_CLOCK_SECTOR_BUFFER_FREQUENCY
///                        ATTR_PM_RESONANT_CLOCK_LOW_BAND_LOWER_FREQUENCY
///                        ATTR_PM_RESONANT_CLOCK_LOW_BAND_UPPER_FREQUENCY
///                        ATTR_PM_RESONANT_CLOCK_HIGH_BAND_LOWER_FREQUENCY
///                        ATTR_PM_RESONANT_CLOCK_HIGH_BAND_UPPER_FREQUENCY
///                        output feature attributes
///                        ATTR_PM_RESONANT_CLOCK_FULL_CSB_PSTATE
///                        ATTR_PM_RESONANT_CLOCK_LFRLOW_PSTATE
///                        ATTR_PM_RESONANT_CLOCK_LFRUPPER_PSTATE
///                        ATTR_PM_RESONANT_CLOCK_HFRLOW_PSTATE
///                        ATTR_PM_RESONANT_CLOCK_HFRHIGH_PSTATE
///             PFET Sequencing Delays
///                  convert_pfet_delays() - Convert the following delays from platform attributes (binary in nanoseconds) to PFET delay value feature attributes.  The conversion uses ATTR_PROC_NEST_FREQUENCY.
///                        Input platform attributes
///                        ATTR_PM_PFET_POWERUP_CORE_DELAY0
///                        ATTR_PM_PFET_POWERUP_CORE_DELAY1
///                        ATTR_PM_PFET_POWERUP_ECO_DELAY0
///                        ATTR_PM_PFET_POWERUP_ECO_DELAY1
///                        ATTR_PM_PFET_POWERDOWN_CORE_DELAY0
///                        ATTR_PM_PFET_POWERDOWN_CORE_DELAY1
///                        ATTR_PM_PFET_POWERDOWN_ECO_DELAY0
///                        ATTR_PM_PFET_POWERDOWN_ECO_DELAY1
///                        output feature attributes
///                        ATTR_PM_PFET_POWERUP_CORE_DELAY0_VALUE
///                        ATTR_PM_PFET_POWERUP_CORE_DELAY1_VALUE
///                        ATTR_PM_PFET_POWERUP_CORE_SEQUENCE_DELAY_SELECT
///                        ATTR_PM_PFET_POWERUP_ECO_DELAY0_VALUE
///                        ATTR_PM_PFET_POWERUP_ECO_DELAY1_VALUE
///                        ATTR_PM_PFET_POWERUP_ECO_SEQUENCE_DELAY_SELECT
///                        ATTR_PM_PFET_POWERDOWN_CORE_DELAY0_VALUE
///                        ATTR_PM_PFET_POWERDOWN_CORE_DELAY1_VALUE
///                        ATTR_PM_PFET_POWERDOWN_CORE_SEQUENCE_DELAY_SELECT
///                        ATTR_PM_PFET_POWERDOWN_ECO_DELAY0_VALUE
///                        ATTR_PM_PFET_POWERDOWN_ECO_DELAY1_VALUE
///                        ATTR_PM_PFET_POWERDOWN_ECO_SEQUENCE_DELAY_SELECT
///
///
///
/// INIT
///
/// -Resets DPLL_CPM_PARM_REG.cpm_filter_enable
///
/// - Sleep configuration
///     -ATTR_PM_SLEEP_TYPE (Deep or Fast)
///     -ATTR_PM_SLEEP_ENTRY (Assisted or Hardware) - depends on di/dt charateristics of the system (Assisted if power off serialization is needed, Hardware if the system can handle the unrelated powering off between cores.  Hardware decreases entry latency )
///     -ATTR_PM_SLEEP_EXIT (Assisted or Hardware) - set to Assisted (for both Fast and Deep).  Fast for di/dt management; Deep as this necessary for restore.  Setting to Hardware is a test mode for Fast only.
/// - Winkle configuration
///     -ATTR_PM_WINKLE_TYPE  (Deep or Fast)
///     -ATTR_PM_WINKLE_ENTRY (Assisted or Hardware)
///     -ATTR_PM_WINKLE_EXIT (Assisted or Hardware) - set to Assisted (for both Fast and Deep).  Fast for di/dt management; Deep as this necessary for restore.  Setting to Hardware is a test mode for Fast only.
/// - PMCR default value adjustment (Hardware flush 0 -> restore to 0 for reset case)
///     -For reset case, disable all "global_en" bits in PMCR and PMICR;  this keeps Global Pstate Request from occuring to the PMC until it has been initialized.  OCCFW to be do this.
/// - PMICR default value adjustment (Hardware flush 0 -> restore to TBD for reset )  
///     -How does policy influence the PMICR Pstate values?
///     -Base:  run at the turbo value fixed
///     -Enhancement:  run at the highest Pstate value on the chip. (needs power projection to judge worth).
///     -latency enable
///     -Not planned at this time.
/// OLD-DOC - Sleep / Winkle -> Fast / Deep configuration
/// OLD-DOC - Restore to Deep Sleep and Deep Winkle upon reset
/// OLD-DOC - PMCR default value adjustment (Hardware flush 0 -> restore to 0 for reset case) SCAN0
/// OLD-DOC     -For reset case, disable all “global_en” bits in PMCR and PMICR;  this keeps Global Pstate Request from occuring to the PMC until it has been initialized.  OCCFW to be do this
/// OLD-DOC - PMICR default value adjustment (Hardware flush 0 -> restore to 0 for reset ) SCAN0



/// \todo add to required proc ENUM requests
///

// ----------------------------------------------------------------------
// Includes
// ----------------------------------------------------------------------
#include <fapi.H>
#include "p8_scom_addresses.H"
#include "p8_pcbs_init.H"
#include "p8_pm.H"

//----------------------------------------------------------------------
//  eCMD Includes
//----------------------------------------------------------------------
#include <ecmdDataBufferBase.H>






extern "C" {



using namespace fapi;

// ----------------------------------------------------------------------
// Constant definitions
// ----------------------------------------------------------------------
// Address definition for chiplet EX01 with base address 0x10000000
//       Example: getscom pu.ex 10000001 -c3   ---> scom address 0x13000001
// CONST_UINT64_T( GP3_REG_0x100F0012                             , ULL(0x100F0012) );
// CONST_UINT64_T( FREQ_CTRL_REG_0x100F0151                       , ULL(0x100F0151) );
// CONST_UINT64_T( PCBS_POWER_MANAGEMENT_STATUS_REG_0x100F0153    , ULL(0x100F0153) );
// CONST_UINT64_T( PCBS_iVRM_Control_Status_Reg_0x100F0154        , ULL(0x100F0154) );
// CONST_UINT64_T( PCBSPM_MODE_REG_0x100F0156                     , ULL(0x100F0156) );
// CONST_UINT64_T( PCBS_UNDERVOLTING_REG_0x100F015B               , ULL(0x100F015B) );
// CONST_UINT64_T( PCBS_Power_Management_Bounds_Reg_0x100F015D    , ULL(0x100F015D) );
// CONST_UINT64_T( PCBS_OCC_Heartbeat_Reg_0x100F0164              , ULL(0x100F0164) );
// CONST_UINT64_T( PCBS_Resonant_Clock_Control_Reg0_0x100F0165    , ULL(0x100F0165) );
// CONST_UINT64_T( PCBS_Local_Pstate_Frequency_Target_Control_Register_0x100F0168     , ULL(0x100F0168) );

// CONST_UINT64_T( EX_GP3_0x100F0012                                          , ULL(0x100F0012) );
// CONST_UINT64_T( EX_GP3_AND_0x100F0013                                         , ULL(0x100F0013) );
// CONST_UINT64_T( EX_GP3_OR_0x100F0014                                          , ULL(0x100F0014) );
// CONST_UINT64_T( EX_PMGP0_0x100F0100                                        , ULL(0x100F0100) );
// CONST_UINT64_T( EX_PMGP0_AND_0x100F0101                                       , ULL(0x100F0101) );
// CONST_UINT64_T( EX_PMGP0_OR_0x100F0102                                        , ULL(0x100F0102) );

 //------------------------------------------------------------------------------
 //Start scan zero value
 //------------------------------------------------------------------------------
/// \todo   Review scan0 values 
 
      CONST_UINT64_T( PMGP0_REG_0x100F0100_scan0                          ,  ULL(0x8030010C21000000) );
      CONST_UINT64_T( PMGP1_REG_0x100F0103_scan0                          ,  ULL(0x6C00000000000000) );
      CONST_UINT64_T( EX_PFVddCntlStat_REG_0x100F0106_scan0                  ,  ULL(0x0A00000000000000) );
      CONST_UINT64_T( EX_PFVcsCntlStat_REG_0x100F010E_scan0                  ,  ULL(0xFFF0FFF080800000) );     //1000 0000 1000 000
      CONST_UINT64_T( EX_PMErrMask_REG_0x100F010A_scan0                      ,  ULL(0x00000000));
      CONST_UINT64_T( EX_PMSpcWkupFSP_REG_0x100F010B_scan0                   ,  ULL(0x00000000));
      CONST_UINT64_T( EX_PMSpcWkupOCC_REG_0x100F010C_scan0                      ,  ULL(0x80000000));    //1
      CONST_UINT64_T( EX_PMSpcWkupPHYP_REG_0x100F010D_scan0                  ,  ULL(0x00000000));
      CONST_UINT64_T( EX_CorePFPUDly_REG_0x100F012C_scan0                    ,  ULL(0x00000000));
      CONST_UINT64_T( EX_CorePFPDDly_REG_0x100F012D_scan0                    ,  ULL(0x00000000));
      CONST_UINT64_T( EX_CorePFVRET_REG_0x100F0130_scan0                     ,  ULL(0x00000000));
      CONST_UINT64_T( EX_ECOPFPUDly_REG_0x100F014C_scan0                     ,  ULL(0x00000000));
      CONST_UINT64_T( EX_ECOPFPDDly_REG_0x100F014D_scan0                     ,  ULL(0x00000000));
      CONST_UINT64_T( EX_ECOPFVRET_REG_0x100F0150_scan0                      ,  ULL(0x00000000));
      CONST_UINT64_T( EX_FREQCNTL_0x100F0151_scan0                       ,  ULL(0x32320000));    // "0011 0010 0011 0010 000000000000" ;
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

 //End scan zero value







// ----------------------------------------------------------------------
// Global variables
// ----------------------------------------------------------------------

//fapi::ReturnCode rc;

//uint32_t   SIM_CYCLE_POLL_DELAY = 200000;          // simulation cycle delay between status register polls
//uint32_t   MAX_POLL_ATTEMPTS    = 5;               // maximum number of status poll attempts to make before giving up


// ----------------------------------------------------------------------
// Function prototypes
// ----------------------------------------------------------------------

//ReturnCode p8_pcbs_init_core(Target  &i_target, uint64_t mode, struct_pcbs_val_init_type pcbs_val_init);
//ReturnCode pgp_initializeMulticast( Target &i_target, bool VERBOSE );

fapi::ReturnCode delay( uint64_t i_nanoSeconds, uint64_t i_simCycles );

/// \todo : PSAFE, PUV_MIN, PUV_MAX - Attributes defined as unint8 but should be int8
typedef struct {
  uint8_t  ivrms_enabled;         // ATTR_IVRMS_ENABLED
  uint8_t   PSAFE;                 // ATTR_SAFE_PSTATE PSAFE 
  uint8_t   PUV_MIN;                // ATTR_PSTATE_UNDERVOLTING_MINIMUM
  uint8_t   PUV_MAX;                // ATTR_PSTATE_UNDERVOLTING_MAXIMUM 
  uint32_t MAX_PSAFE_FSM_LOOPS;   //                            max number of times PCBS-PMSR has been checked
  uint32_t MAX_DELAY;             //                            max number of Delay
  uint32_t MAX_SIM_CYCLES;        //                            max number of SimCycles (will be used when FSP is target)
  int8_t   GLOBAL_ACTUAL_PSTATE;   //                           Global Actual PSTATE
  int8_t   MIN_PSTATE;             // 
  int8_t   FNOM;                   // 
  uint8_t  DPLL_FMIN;               // 
  uint8_t  DPLL_FMAX;               // 
  int8_t   PMIN_CLIP;              //
  int8_t   PMAX_CLIP;              //
  uint8_t  KUV;                    //
} struct_pcbs_val_init_type;


// ----------------------------------------------------------------------
// Function definitions
// ----------------------------------------------------------------------

// Reset function   
fapi::ReturnCode p8_pcbs_init_reset  (const fapi::Target& i_target, uint32_t i_mode, struct_pcbs_val_init_type pcbs_val_init);
// Config function
fapi::ReturnCode p8_pcbs_init_config (const fapi::Target&  i_target) ;
// INIT 
fapi::ReturnCode  p8_pcbs_init_init  (const fapi::Target& i_target) ; 





// ----------------------------------------------------------------------
// p8_pcbs_init wrapper to fetch the attributes and pass it on to p8_pcbs_init_core
// ----------------------------------------------------------------------
//ReturnCode  p8_pcbs_init( Target &i_target, std::list<uint32_t> &args )
fapi::ReturnCode  p8_pcbs_init(
      const Target& i_target,  
      uint32_t i_mode)
{
  fapi::ReturnCode rc;


  
  //Declare parms struct 
  struct_pcbs_val_init_type  pcbs_val_init;
  
  
  FAPI_DBG("");
  FAPI_DBG("*************************************");
  FAPI_INF("Executing p8_pcbs_init");
  FAPI_DBG("*************************************");
  FAPI_DBG("");
  
  FAPI_INF("\t MODE: %d  ", i_mode);
 
 
  
  
  if ( i_mode == PM_CONFIG ) {
    FAPI_DBG("*************************************");
    FAPI_INF("MODE:  CONFIG , Calling: p8_pcbs_init_config ");
    FAPI_DBG("*************************************");
  
    rc=p8_pcbs_init_config(i_target);
    if (rc) {
      FAPI_ERR(" p8_pcbs_init_config failed. With rc = 0x%x", (uint32_t)rc); return rc;  
    }                  
    
  } else if ( i_mode == PM_INIT )  { 
    FAPI_DBG("*************************************");
    FAPI_INF("MODE:  INIT , Calling: p8_pcbs_init_init");
    FAPI_DBG("*************************************");    

    rc=p8_pcbs_init_init(i_target);
    if (rc) {
      FAPI_ERR(" p8_pcbs_init_init failed. With rc = 0x%x", (uint32_t)rc); return rc;  
    }          
    
  } else if ( i_mode == PM_RESET )  {
    FAPI_DBG("*************************************");
    FAPI_INF("MODE:  RESET");
    FAPI_DBG("*************************************");


    
    //  ******************************************************************

 
    
    //Assign values to parms in struct
    // should come from MRWB 
    //    pcbs_val_init.ivrms_enabled = 1;              // ATTR_PM_IVRMS_ENABLED     VENICE or SALERNO
    //    pcbs_val_init.PSAFE = -128 ;                  // ATTR_PM_SAFE_PSTATE PSAFE
    //    pcbs_val_init.PUV_MIN = -128 ;                // ATTR_PM_PSTATE_UNDERVOLTING_MINIMUM
    //    pcbs_val_init.PUV_MAX = -128 ;                // ATTR_PM_PSTATE_UNDERVOLTING_MAXIMUM
      
        

    rc = FAPI_ATTR_GET(ATTR_PM_IVRMS_ENABLED,               &i_target, pcbs_val_init.ivrms_enabled);   if (rc) return rc;       //VENICE or SALERNO
    rc = FAPI_ATTR_GET(ATTR_PM_SAFE_PSTATE,                 &i_target, pcbs_val_init.PSAFE);           if (rc) return rc;
    rc = FAPI_ATTR_GET(ATTR_PM_PSTATE_UNDERVOLTING_MINIMUM, &i_target, pcbs_val_init.PUV_MIN);         if (rc) return rc;
    rc = FAPI_ATTR_GET(ATTR_PM_PSTATE_UNDERVOLTING_MAXIMUM, &i_target, pcbs_val_init.PUV_MAX);         if (rc) return rc;
    
     
    
    
    
    // ----------------------------------------------------------------------
    // Assign default values 
    // ----------------------------------------------------------------------
    
    /// \todo CHECK: Review those defaults
    pcbs_val_init.MAX_PSAFE_FSM_LOOPS  =   20;    // max number of times PCBS-PMSR has been checked
    pcbs_val_init.MAX_DELAY =   1000000; 
    pcbs_val_init.MAX_SIM_CYCLES =   1000;
    pcbs_val_init.GLOBAL_ACTUAL_PSTATE = -128 ;   // Global Actual PSTATE  default
    pcbs_val_init.MIN_PSTATE = -128 ;             // Default
    pcbs_val_init.FNOM = 128;                     // Default
    pcbs_val_init.DPLL_FMIN = 50;                 // 
    pcbs_val_init.DPLL_FMAX = 50;                 // Default
    pcbs_val_init.PMIN_CLIP = -128 ;              // Default
    pcbs_val_init.PMAX_CLIP =  127 ;              // Default
    pcbs_val_init.KUV = 0;                        // Default
    
    //  ******************************************************************
    
    
     

    
    FAPI_DBG("*************************************");
    FAPI_INF("Calling: p8_pcbs_init_reset");
    FAPI_DBG("*************************************");
    rc = p8_pcbs_init_reset( i_target, i_mode,  pcbs_val_init);
    
    if (rc) {
      FAPI_ERR(" p8_pcbs_init_reset failed. With rc = 0x%x", (uint32_t)rc); return rc;  
    }              
    
    
  } else {
    FAPI_DBG("*************************************");
    FAPI_ERR("Unknown mode passed to p8_pcbs_init. Mode %x ....\n", i_mode);
    FAPI_SET_HWP_ERROR(rc, RC_PROC_PCBS_CODE_BAD_MODE);
    FAPI_DBG("*************************************");
    
  }; 
  

 
FAPI_INF("\t MODE: %d  ", i_mode);  
  
  return rc; 
  
}  



uint8_t convert_delay_to_value (uint32_t i_delay, uint32_t i_attr_proc_nest_frequency)
{
  uint8_t   pfet_delay_value;
  float     dly; 
  //attr_proc_nest_frequency [MHz]
  //delay [ns]
  //pfet_delay_value = 15 - log2( i_delay * i_attr_proc_nest_frequency/1000);
  // since log2 function is not available, this is done manual
  //pfet_delay_value = 15 - log2( dly );
  dly = ( i_delay * i_attr_proc_nest_frequency/1000);
  
  if     (dly <= 1.4 )                                          {  pfet_delay_value = 15 - 0 ;   } 
  else if    ( ( 1.4    < dly ) &&  ( dly <= 2.8 )    )         {  pfet_delay_value = 15 - 1 ;   }
  else if    ( ( 2.8    < dly ) &&  ( dly <= 5.6 )    )         {  pfet_delay_value = 15 - 2 ;   }
  else if    ( ( 5.6    < dly ) &&  ( dly <= 11.5 )   )         {  pfet_delay_value = 15 - 3 ;   }
  else if    ( ( 11.5   < dly ) &&  ( dly <= 23 )     )         {  pfet_delay_value = 15 - 4 ;   }
  else if    ( ( 23     < dly ) &&  ( dly <= 46 )     )         {  pfet_delay_value = 15 - 5 ;   }
  else if    ( ( 46     < dly ) &&  ( dly <= 92 )     )         {  pfet_delay_value = 15 - 6 ;   }
  else if    ( ( 92     < dly ) &&  ( dly <= 182 )    )         {  pfet_delay_value = 15 - 7 ;   }
  else if    ( ( 182    < dly ) &&  ( dly <= 364 )    )         {  pfet_delay_value = 15 - 8 ;   }
  else if    ( ( 364    < dly ) &&  ( dly <= 728 )    )         {  pfet_delay_value = 15 - 9 ;   }
  else if    ( ( 728    < dly ) &&  ( dly <= 1456 )   )         {  pfet_delay_value = 15 - 10 ;  }
  else if    ( ( 1456   < dly ) &&  ( dly <= 2912 )   )         {  pfet_delay_value = 15 - 11 ;  }
  else if    ( ( 2912   < dly ) &&  ( dly <= 5824 )   )         {  pfet_delay_value = 15 - 12 ;  }
  else if    ( ( 5824   < dly ) &&  ( dly <= 11648 )  )         {  pfet_delay_value = 15 - 13 ;  }
  else if    ( ( 11648  < dly ) &&  ( dly <= 23296 )  )         {  pfet_delay_value = 15 - 14 ;  }
  else if                                  ( 23296   < dly  )   {  pfet_delay_value = 15 - 15 ;  }
  else                                                          {  pfet_delay_value = 15 - 15 ;  } ;    
  
  
  
  
  return (pfet_delay_value);
}


// Transform Platform Attribute for  PCBS to Feature Attributes
fapi::ReturnCode
p8_pcbs_init_config(const Target& i_target) 
{
  fapi::ReturnCode rc;

  ///             PState translation
  ///                  convert_safe_freq() - With ATTR_PM_SAFE_FREQUENCY (binary in MHz) and ATTR_PM_PSTATE0_FREQUENCY (binary in Mhz) produce ATTR_PM_SAFE_PSTATE
  ///             Resonant Clocking settings (band definitions from frequency to Pstate) 
  ///                  convert_resclk_freqs_to_pstates() - Convert the following frequency platform attributes (binary in MHz) to feature Pstate attributes.  The conversion uses ATTR_PM_PSTATE0_FREQUENCY.
  ///                        Input platform attributes
  ///                        ATTR_PM_RESONANT_CLOCK_FULL_CLOCK_SECTOR_BUFFER_FREQUENCY
  ///                        ATTR_PM_RESONANT_CLOCK_LOW_BAND_LOWER_FREQUENCY
  ///                        ATTR_PM_RESONANT_CLOCK_LOW_BAND_UPPER_FREQUENCY
  ///                        ATTR_PM_RESONANT_CLOCK_HIGH_BAND_LOWER_FREQUENCY
  ///                        ATTR_PM_RESONANT_CLOCK_HIGH_BAND_UPPER_FREQUENCY
  ///                        output feature attributes
  ///                        ATTR_PM_RESONANT_CLOCK_FULL_CSB_PSTATE
  ///                        ATTR_PM_RESONANT_CLOCK_LFRLOW_PSTATE
  ///                        ATTR_PM_RESONANT_CLOCK_LFRUPPER_PSTATE
  ///                        ATTR_PM_RESONANT_CLOCK_HFRLOW_PSTATE
  ///                        ATTR_PM_RESONANT_CLOCK_HFRHIGH_PSTATE
  ///             PFET Sequencing Delays
  ///                  convert_pfet_delays() - Convert the following delays from platform attributes (binary in nanoseconds) to PFET delay value feature attributes.  The conversion uses ATTR_PROC_NEST_FREQUENCY.
  ///                        Input platform attributes
  ///                        ATTR_PM_PFET_POWERUP_CORE_DELAY0
  ///                        ATTR_PM_PFET_POWERUP_CORE_DELAY1
  ///                        ATTR_PM_PFET_POWERUP_ECO_DELAY0
  ///                        ATTR_PM_PFET_POWERUP_ECO_DELAY1
  ///                        ATTR_PM_PFET_POWERDOWN_CORE_DELAY0
  ///                        ATTR_PM_PFET_POWERDOWN_CORE_DELAY1
  ///                        ATTR_PM_PFET_POWERDOWN_ECO_DELAY0
  ///                        ATTR_PM_PFET_POWERDOWN_ECO_DELAY1
  ///                        output feature attributes
  ///                        ATTR_PM_PFET_POWERUP_CORE_DELAY0_VALUE
  ///                        ATTR_PM_PFET_POWERUP_CORE_DELAY1_VALUE
  ///                        ATTR_PM_PFET_POWERUP_CORE_SEQUENCE_DELAY_SELECT
  ///                        ATTR_PM_PFET_POWERUP_ECO_DELAY0_VALUE
  ///                        ATTR_PM_PFET_POWERUP_ECO_DELAY1_VALUE
  ///                        ATTR_PM_PFET_POWERUP_ECO_SEQUENCE_DELAY_SELECT
  ///                        ATTR_PM_PFET_POWERDOWN_CORE_DELAY0_VALUE
  ///                        ATTR_PM_PFET_POWERDOWN_CORE_DELAY1_VALUE
  ///                        ATTR_PM_PFET_POWERDOWN_CORE_SEQUENCE_DELAY_SELECT
  ///                        ATTR_PM_PFET_POWERDOWN_ECO_DELAY0_VALUE
  ///                        ATTR_PM_PFET_POWERDOWN_ECO_DELAY1_VALUE
  ///                        ATTR_PM_PFET_POWERDOWN_ECO_SEQUENCE_DELAY_SELECT
  
  //  ******************************************************************
  //  attributes variables
  uint32_t attr_proc_refclk_frequency ;
  //uint32_t attr_pm_pstate0_frequency;
  //uint8_t  attr_pm_safe_pstate;
  //uint32_t attr_pm_safe_frequency;
  
  uint32_t  attr_pm_pfet_powerup_core_delay0;
  uint32_t  attr_pm_pfet_powerup_core_delay1;
  uint32_t  attr_pm_pfet_powerdown_core_delay0;
  uint32_t  attr_pm_pfet_powerdown_core_delay1;
  uint32_t  attr_pm_pfet_powerup_eco_delay0;
  uint32_t  attr_pm_pfet_powerup_eco_delay1;
  uint32_t  attr_pm_pfet_powerdown_eco_delay0;
  uint32_t  attr_pm_pfet_powerdown_eco_delay1;
  
  uint8_t   attr_pm_pfet_powerup_core_delay0_value;
  uint8_t   attr_pm_pfet_powerup_core_delay1_value;
  uint32_t  attr_pm_pfet_powerup_core_sequence_delay_select; 
  uint8_t   attr_pm_pfet_powerdown_core_delay0_value;
  uint8_t   attr_pm_pfet_powerdown_core_delay1_value;
  uint32_t  attr_pm_pfet_powerdown_core_sequence_delay_select; 
  uint8_t   attr_pm_pfet_powerup_eco_delay0_value;
  uint8_t   attr_pm_pfet_powerup_eco_delay1_value;
  uint32_t  attr_pm_pfet_powerup_eco_sequence_delay_select; 
  uint8_t   attr_pm_pfet_powerdown_eco_delay0_value;
  uint8_t   attr_pm_pfet_powerdown_eco_delay1_value;
  uint32_t  attr_pm_pfet_powerdown_eco_sequence_delay_select; 
  

      
      //  ******************************************************************
      //  Get Attributes for pFET Delay      
      //  ******************************************************************     
          //  ******************************************************************
          //  set defaults  if not available        
          ///  \todo    refclk ATTR_PROC_REFCLK_FREQUENCY OR  ATTR_PROC_NEST_FREQUENCY       ????
            attr_proc_refclk_frequency  = 225;
          //  attr_pm_pfet_powerup_core_delay0            = 100;
          //  attr_pm_pfet_powerup_core_delay1            = 100;
          //  attr_pm_pfet_powerdown_core_delay0          = 100;
          //  attr_pm_pfet_powerdown_core_delay1          = 100;
          //  attr_pm_pfet_powerup_eco_delay0             = 100;
          //  attr_pm_pfet_powerup_eco_delay1             = 100;
          //  attr_pm_pfet_powerdown_eco_delay0           = 100;
          //  attr_pm_pfet_powerdown_eco_delay1           = 100;
   
      
          
 
          /// ---------------------------------------------------------- 
                     rc = FAPI_ATTR_GET(ATTR_PM_PFET_POWERUP_CORE_DELAY0, &i_target, attr_pm_pfet_powerup_core_delay0); 
                     if (rc) { FAPI_ERR("fapiGetAttribute of ATTR_PM_PFET_POWERUP_CORE_DELAY0 with rc = 0x%x", (uint32_t)rc);  return rc; }
          
          /// ---------------------------------------------------------- 
                     rc = FAPI_ATTR_GET(ATTR_PM_PFET_POWERUP_CORE_DELAY1, &i_target, attr_pm_pfet_powerup_core_delay1); 
                     if (rc) { FAPI_ERR("fapiGetAttribute of ATTR_PM_PFET_POWERUP_CORE_DELAY1 with rc = 0x%x", (uint32_t)rc);  return rc; }
          
          /// ---------------------------------------------------------- 
                     rc = FAPI_ATTR_GET(ATTR_PM_PFET_POWERDOWN_CORE_DELAY0, &i_target, attr_pm_pfet_powerdown_core_delay0); 
                     if (rc) { FAPI_ERR("fapiGetAttribute of ATTR_PM_PFET_POWERDOWN_CORE_DELAY0 with rc = 0x%x", (uint32_t)rc);  return rc; }
          
          /// ---------------------------------------------------------- 
                     rc = FAPI_ATTR_GET(ATTR_PM_PFET_POWERDOWN_CORE_DELAY1, &i_target, attr_pm_pfet_powerdown_core_delay1); 
                     if (rc) { FAPI_ERR("fapiGetAttribute of ATTR_PM_PFET_POWERDOWN_CORE_DELAY1 with rc = 0x%x", (uint32_t)rc);  return rc; }
          
          /// ---------------------------------------------------------- 
                     rc = FAPI_ATTR_GET(ATTR_PM_PFET_POWERUP_ECO_DELAY0, &i_target, attr_pm_pfet_powerup_eco_delay0); 
                     if (rc) { FAPI_ERR("fapiGetAttribute of ATTR_PM_PFET_POWERUP_ECO_DELAY0 with rc = 0x%x", (uint32_t)rc);  return rc; }
          
          /// ---------------------------------------------------------- 
                     rc = FAPI_ATTR_GET(ATTR_PM_PFET_POWERUP_ECO_DELAY1, &i_target, attr_pm_pfet_powerup_eco_delay1); 
                     if (rc) { FAPI_ERR("fapiGetAttribute of ATTR_PM_PFET_POWERUP_ECO_DELAY1 with rc = 0x%x", (uint32_t)rc);  return rc; }
          
          /// ---------------------------------------------------------- 
                     rc = FAPI_ATTR_GET(ATTR_PM_PFET_POWERDOWN_ECO_DELAY0, &i_target, attr_pm_pfet_powerdown_eco_delay0); 
                     if (rc) { FAPI_ERR("fapiGetAttribute of ATTR_PM_PFET_POWERDOWN_ECO_DELAY0 with rc = 0x%x", (uint32_t)rc);  return rc; }
          
          /// ---------------------------------------------------------- 
                     rc = FAPI_ATTR_GET(ATTR_PM_PFET_POWERDOWN_ECO_DELAY1, &i_target, attr_pm_pfet_powerdown_eco_delay1); 
                     if (rc) { FAPI_ERR("fapiGetAttribute of ATTR_PM_PFET_POWERDOWN_ECO_DELAY1 with rc = 0x%x", (uint32_t)rc);  return rc; }
      
      

 
        
        //  ******************************************************************
        //  Calculates Delay values out of pFET Delays      
        //  ******************************************************************            
        FAPI_DBG("*************************************");
        FAPI_DBG("Calculates Delay values out of pFET Delays");
        FAPI_DBG("*************************************");  
        FAPI_DBG("*************************************");
        FAPI_DBG("Calculate:");
        FAPI_DBG("        ATTR_PM_PFET_POWERUP_CORE_DELAY0_VALUE");
        FAPI_DBG("        ATTR_PM_PFET_POWERUP_CORE_DELAY1_VALUE");
        FAPI_DBG("        ATTR_PM_PFET_POWERUP_ECO_DELAY0_VALUE");
        FAPI_DBG("        ATTR_PM_PFET_POWERUP_ECO_DELAY1_VALUE");
        FAPI_DBG("        ATTR_PM_PFET_POWERDOWN_CORE_DELAY0_VALUE");
        FAPI_DBG("        ATTR_PM_PFET_POWERDOWN_CORE_DELAY1_VALUE");
        FAPI_DBG("        ATTR_PM_PFET_POWERDOWN_ECO_DELAY0_VALUE");
        FAPI_DBG("        ATTR_PM_PFET_POWERDOWN_ECO_DELAY1_VALUE");
        FAPI_DBG("using:");
        FAPI_DBG("        ATTR_PM_PFET_POWERUP_CORE_DELAY0");
        FAPI_DBG("        ATTR_PM_PFET_POWERUP_CORE_DELAY1");
        FAPI_DBG("        ATTR_PM_PFET_POWERUP_ECO_DELAY0");
        FAPI_DBG("        ATTR_PM_PFET_POWERUP_ECO_DELAY1");
        FAPI_DBG("        ATTR_PM_PFET_POWERDOWN_CORE_DELAY0");
        FAPI_DBG("        ATTR_PM_PFET_POWERDOWN_CORE_DELAY1");
        FAPI_DBG("        ATTR_PM_PFET_POWERDOWN_ECO_DELAY0");
        FAPI_DBG("        ATTR_PM_PFET_POWERDOWN_ECO_DELAY1");
        FAPI_DBG("**************************************************************************");          
        FAPI_DBG("        Set  ATTR_PM_PFET_POWERUP_CORE_SEQUENCE_DELAY_SELECT    to 0 (choosing always pfetdelay0 )");
        FAPI_DBG("        Set  ATTR_PM_PFET_POWERDOWN_CORE_SEQUENCE_DELAY_SELECT  to 0 (choosing always pfetdelay0 )");
        FAPI_DBG("        Set  ATTR_PM_PFET_POWERUP_ECO_SEQUENCE_DELAY_SELECT     to 0 (choosing always pfetdelay0 )");
        FAPI_DBG("        Set  ATTR_PM_PFET_POWERDOWN_ECO_SEQUENCE_DELAY_SELECT   to 0 (choosing always pfetdelay0 )");            
        FAPI_DBG("**************************************************************************");        

 
    
        
        //value = 15 - log2(delay * refclk);
        attr_pm_pfet_powerup_core_delay0_value          = convert_delay_to_value(attr_pm_pfet_powerup_core_delay0,      attr_proc_refclk_frequency);
        attr_pm_pfet_powerup_core_delay1_value          = convert_delay_to_value(attr_pm_pfet_powerup_core_delay1,      attr_proc_refclk_frequency);     
        attr_pm_pfet_powerdown_core_delay0_value        = convert_delay_to_value(attr_pm_pfet_powerdown_core_delay0 ,   attr_proc_refclk_frequency);
        attr_pm_pfet_powerdown_core_delay1_value        = convert_delay_to_value(attr_pm_pfet_powerdown_core_delay1 ,   attr_proc_refclk_frequency);        
        attr_pm_pfet_powerup_eco_delay0_value           = convert_delay_to_value(attr_pm_pfet_powerup_eco_delay0 ,      attr_proc_refclk_frequency);
        attr_pm_pfet_powerup_eco_delay1_value           = convert_delay_to_value(attr_pm_pfet_powerup_eco_delay1 ,      attr_proc_refclk_frequency);
        attr_pm_pfet_powerdown_eco_delay0_value         = convert_delay_to_value(attr_pm_pfet_powerdown_eco_delay0 ,    attr_proc_refclk_frequency);
        attr_pm_pfet_powerdown_eco_delay1_value         = convert_delay_to_value(attr_pm_pfet_powerdown_eco_delay1 ,    attr_proc_refclk_frequency);
        
        attr_pm_pfet_powerup_core_sequence_delay_select         = 0;  // Choosing always delay0
        attr_pm_pfet_powerdown_core_sequence_delay_select       = 0; 
        attr_pm_pfet_powerup_eco_sequence_delay_select          = 0; 
        attr_pm_pfet_powerdown_eco_sequence_delay_select        = 0;        
        
       
       
       
       
       
          FAPI_DBG("*************************************");
          FAPI_DBG("attr_pm_pfet_powerup_core_delay0_value              :  %X", attr_pm_pfet_powerup_core_delay0_value);
          FAPI_DBG("attr_pm_pfet_powerup_core_delay1_value              :  %X", attr_pm_pfet_powerup_core_delay1_value);
          FAPI_DBG("attr_pm_pfet_powerup_core_sequence_delay_select     :  %X", attr_pm_pfet_powerup_core_sequence_delay_select); 
          FAPI_DBG("attr_pm_pfet_powerdown_core_delay0_value            :  %X", attr_pm_pfet_powerdown_core_delay0_value);
          FAPI_DBG("attr_pm_pfet_powerdown_core_delay1_value            :  %X", attr_pm_pfet_powerdown_core_delay1_value);
          FAPI_DBG("attr_pm_pfet_powerdown_core_sequence_delay_select   :  %X", attr_pm_pfet_powerdown_core_sequence_delay_select); 
          FAPI_DBG("attr_pm_pfet_powerup_eco_delay0_value               :  %X", attr_pm_pfet_powerup_eco_delay0_value);
          FAPI_DBG("attr_pm_pfet_powerup_eco_delay1_value               :  %X", attr_pm_pfet_powerup_eco_delay1_value);
          FAPI_DBG("attr_pm_pfet_powerup_eco_sequence_delay_select      :  %X", attr_pm_pfet_powerup_eco_sequence_delay_select); 
          FAPI_DBG("attr_pm_pfet_powerdown_eco_delay0_value             :  %X", attr_pm_pfet_powerdown_eco_delay0_value);
          FAPI_DBG("attr_pm_pfet_powerdown_eco_delay1_value             :  %X", attr_pm_pfet_powerdown_eco_delay1_value);
          FAPI_DBG("attr_pm_pfet_powerdown_eco_sequence_delay_select    :  %X", attr_pm_pfet_powerdown_eco_sequence_delay_select);        
          FAPI_DBG("*************************************");
          
                   
        
        //  ******************************************************************
        //  Set Attributes for PFET delays      
        //  ******************************************************************                  
        
      
      /// \todo DOUBLE Check ... Shouldn't the DELAY_SELECT -values be only readable??? read above and not written here???
      /// \todo ATTR_PM_PFET_POWERUP/DOWN_CORE/ECO_DELAY0/1_VALUE   are defined in the spreadsheet as not writeable ????
            /// ---------------------------------------------------------- 
            /*            rc = FAPI_ATTR_SET(ATTR_PM_PFET_POWERUP_CORE_DELAY0_VALUE, &i_target, attr_pm_pfet_powerup_core_delay0_value); 
            if (rc) { FAPI_ERR("fapiGetAttribute of ATTR_PM_PFET_POWERUP_CORE_DELAY0_VALUE with rc = 0x%x", (uint8_t)rc);  return rc; }
            
            /// ---------------------------------------------------------- 
            rc = FAPI_ATTR_SET(ATTR_PM_PFET_POWERUP_CORE_DELAY1_VALUE, &i_target, attr_pm_pfet_powerup_core_delay1_value); 
            if (rc) { FAPI_ERR("fapiGetAttribute of ATTR_PM_PFET_POWERUP_CORE_DELAY1_VALUE with rc = 0x%x", (uint8_t)rc);  return rc; }
            
            /// ---------------------------------------------------------- 
            rc = FAPI_ATTR_SET(ATTR_PM_PFET_POWERUP_CORE_SEQUENCE_DELAY_SELECT, &i_target, attr_pm_pfet_powerup_core_sequence_delay_select); 
            if (rc) { FAPI_ERR("fapiGetAttribute of ATTR_PM_PFET_POWERUP_CORE_SEQUENCE_DELAY_SELECT with rc = 0x%x", (uint32_t)rc);  return rc; }
            
            /// ---------------------------------------------------------- 
            rc = FAPI_ATTR_SET(ATTR_PM_PFET_POWERDOWN_CORE_DELAY0_VALUE, &i_target, attr_pm_pfet_powerdown_core_delay0_value); 
            if (rc) { FAPI_ERR("fapiGetAttribute of ATTR_PM_PFET_POWERDOWN_CORE_DELAY0_VALUE with rc = 0x%x", (uint8_t)rc);  return rc; }
            
            /// ---------------------------------------------------------- 
            rc = FAPI_ATTR_SET(ATTR_PM_PFET_POWERDOWN_CORE_DELAY1_VALUE, &i_target, attr_pm_pfet_powerdown_core_delay1_value); 
            if (rc) { FAPI_ERR("fapiGetAttribute of ATTR_PM_PFET_POWERDOWN_CORE_DELAY1_VALUE with rc = 0x%x", (uint8_t)rc);  return rc; }

            /// ---------------------------------------------------------- 
            rc = FAPI_ATTR_SET(ATTR_PM_PFET_POWERDOWN_CORE_SEQUENCE_DELAY_SELECT, &i_target, attr_pm_pfet_powerdown_core_sequence_delay_select); 
            if (rc) { FAPI_ERR("fapiGetAttribute of ATTR_PM_PFET_POWERDOWN_CORE_SEQUENCE_DELAY_SELECT with rc = 0x%x", (uint32_t)rc);  return rc; }

            /// ---------------------------------------------------------- 
            rc = FAPI_ATTR_SET(ATTR_PM_PFET_POWERUP_ECO_DELAY0_VALUE, &i_target, attr_pm_pfet_powerup_eco_delay0_value); 
            if (rc) { FAPI_ERR("fapiGetAttribute of ATTR_PM_PFET_POWERUP_ECO_DELAY0_VALUE with rc = 0x%x", (uint8_t)rc);  return rc; }
            
            /// ---------------------------------------------------------- 
            rc = FAPI_ATTR_SET(ATTR_PM_PFET_POWERUP_ECO_DELAY1_VALUE, &i_target, attr_pm_pfet_powerup_eco_delay1_value); 
            if (rc) { FAPI_ERR("fapiGetAttribute of ATTR_PM_PFET_POWERUP_ECO_DELAY1_VALUE with rc = 0x%x", (uint8_t)rc);  return rc; }
    
            /// ---------------------------------------------------------- 
            rc = FAPI_ATTR_SET(ATTR_PM_PFET_POWERUP_ECO_SEQUENCE_DELAY_SELECT, &i_target, attr_pm_pfet_powerup_eco_sequence_delay_select); 
            if (rc) { FAPI_ERR("fapiGetAttribute of ATTR_PM_PFET_POWERUP_ECO_SEQUENCE_DELAY_SELECT with rc = 0x%x", (uint32_t)rc);  return rc; }
    
            /// ---------------------------------------------------------- 
            rc = FAPI_ATTR_SET(ATTR_PM_PFET_POWERDOWN_ECO_DELAY0_VALUE, &i_target, attr_pm_pfet_powerdown_eco_delay0_value); 
            if (rc) { FAPI_ERR("fapiGetAttribute of ATTR_PM_PFET_POWERDOWN_ECO_DELAY0_VALUE with rc = 0x%x", (uint8_t)rc);  return rc; }
            
            /// ---------------------------------------------------------- 
            rc = FAPI_ATTR_SET(ATTR_PM_PFET_POWERDOWN_ECO_DELAY1_VALUE, &i_target, attr_pm_pfet_powerdown_eco_delay1_value); 
            if (rc) { FAPI_ERR("fapiGetAttribute of ATTR_PM_PFET_POWERDOWN_ECO_DELAY1_VALUE with rc = 0x%x", (uint8_t)rc);  return rc; }

            /// ---------------------------------------------------------- 
            rc = FAPI_ATTR_SET(ATTR_PM_PFET_POWERDOWN_ECO_SEQUENCE_DELAY_SELECT, &i_target, attr_pm_pfet_powerdown_eco_sequence_delay_select); 
            if (rc) { FAPI_ERR("fapiGetAttribute of ATTR_PM_PFET_POWERDOWN_ECO_SEQUENCE_DELAY_SELECT with rc = 0x%x", (uint32_t)rc);  return rc; }
   */     
         
  
  
  
  
  
  return rc;
  
} //end CONFIG


fapi::ReturnCode
p8_pcbs_init_init(const Target& i_target) 
{
  fapi::ReturnCode rc;
  
  
  uint32_t l_rc;              // local returncode
  
  ecmdDataBufferBase data(64);
  ecmdDataBufferBase mask(64);
  

  // Variables
  std::vector<fapi::Target>      l_exChiplets;   
  fapi::TargetState              l_state = TARGET_STATE_FUNCTIONAL;    // TARGET_STATE_PRESENT or TARGET_STATE_FUNCTIONAL. It just depends on what you want to do.
  
  uint8_t                        l_functional = 0;
  uint8_t                        l_ex_number = 0;
   
  
  
  uint8_t   pm_sleep_type;  
  uint8_t   pm_sleep_entry ;  
  uint8_t   pm_sleep_exit ;  
  uint8_t   pm_winkle_type  ;  
  uint8_t   pm_winkle_entry ;  
  uint8_t   pm_winkle_exit ;  

  
 
    
  //  ******************************************************************
  //  Getting Attributes
  //  ******************************************************************     
      //    pm_sleep_entry      = 0;  //0=assisted, 1=HW
      //    pm_sleep_exit       = 0;  //0=assisted, 1=HW
      //    pm_sleep_type       = 1;  //0=fast, 1=deep
/// \todo missing attributes
         pm_winkle_entry     = 0;  
          pm_winkle_exit      = 0;  
     //     pm_winkle_type      = 1;  
          
             
    
          rc = FAPI_ATTR_GET(ATTR_PM_SLEEP_TYPE,   &i_target, pm_sleep_type);
          if (rc) { FAPI_ERR("fapiGetAttribute of ATTR_PM_SLEEP_TYPE with rc = 0x%x", (uint32_t)rc);  return rc; }       
          rc = FAPI_ATTR_GET(ATTR_PM_SLEEP_ENTRY,  &i_target, pm_sleep_entry);
          if (rc) { FAPI_ERR("fapiGetAttribute of ATTR_PM_SLEEP_ENTRY with rc = 0x%x", (uint32_t)rc);  return rc; }
          rc = FAPI_ATTR_GET(ATTR_PM_SLEEP_EXIT,   &i_target, pm_sleep_exit);
          if (rc) { FAPI_ERR("fapiGetAttribute of ATTR_PM_SLEEP_EXIT with rc = 0x%x", (uint32_t)rc);  return rc; }
          rc = FAPI_ATTR_GET(ATTR_PM_WINKLE_TYPE,  &i_target, pm_winkle_type);
          if (rc) { FAPI_ERR("fapiGetAttribute of ATTR_PM_WINKLE_TYPE with rc = 0x%x", (uint32_t)rc);  return rc; }
//          rc = FAPI_ATTR_GET("ATTR_PM_WINKLE_ENTRY", &i_target,(unit8_t) pm_winkle_entry);
//          if (rc) { FAPI_ERR("fapiGetAttribute of ATTR_PM_WINKLE_ENTRY with rc = 0x%x", (uint32_t)rc);  return rc; }
//          rc = FAPI_ATTR_GET("ATTR_PM_WINKLE_EXIT",  &i_target,(unit8_t) pm_winkle_exit);
//          if (rc) { FAPI_ERR("fapiGetAttribute of ATTR_PM_WINKLE_EXIT with rc = 0x%x", (uint32_t)rc);  return rc; }
    
 
 
 

 
 
 
 
 
 
 rc = fapiGetChildChiplets(i_target, fapi::TARGET_TYPE_EX_CHIPLET, l_exChiplets, l_state); if (rc) return rc;
 FAPI_DBG("  chiplet vector size          => %u", l_exChiplets.size());
 
 
 
 
 
 // For each chiplet
 
 for (uint8_t c=0; c< l_exChiplets.size(); c++) {
   FAPI_DBG("********* ******************* *********");     
   FAPI_DBG("\t Loop Variable %d ",c);
   FAPI_DBG("********* ******************* *********");
   
   rc = FAPI_ATTR_GET(ATTR_FUNCTIONAL, &l_exChiplets[c], l_functional);
   if (rc) 
   {
     FAPI_ERR("fapiGetAttribute of ATTR_FUNCTIONAL with rc = 0x%x", (uint32_t)rc);  
     return rc; 
   } else  
   {
     if (l_functional)
     {
       // The ex is functional let's build the SCOM address 
       rc = FAPI_ATTR_GET(ATTR_CHIP_UNIT_POS, &l_exChiplets[c], l_ex_number);
       if (rc) 
       {
         FAPI_ERR("No functional chiplets exist");  
         FAPI_ERR("fapiGetAttribute of ATTR_CHIP_UNIT_POS with rc = 0x%x", (uint32_t)rc);  
         return rc; 
       }             
       else 
       {
         
         FAPI_DBG("Core number = %d", l_ex_number);
        
        //  ******************************************************************
        //  
        //  ******************************************************************     

              FAPI_DBG("**************************** *********");
              FAPI_INF("Reset CPM_FILTER_ENABLE");
              FAPI_DBG("**************************** *********");
              
              // if debug mode read before
              //if (VERBOSE) {
              //  rc = fapiGetScom(i_target, EX_DPLL_CPM_PARM_REG_0x100F0152 + (l_ex_number * 0x01000000) , data); if (l_rc) return rc;
              //  FAPI_DBG(" Pre write content of EX_DPLL_CPM_PARM_REG_0x1*0F0152 , Loop: %d :  %016llX", c, data.getDoubleWord(0) );
              //}       
              
              // Clear buffer
              l_rc = data.flushTo0();
              if (l_rc) { FAPI_ERR("Bit operation failed. With rc = 0x%x", (uint32_t)l_rc);  rc.setEcmdError(l_rc); return rc;    }
                                                    
              
              rc = fapiPutScom(i_target, EX_DPLL_CPM_PARM_REG_0x100F0152 + (l_ex_number * 0x01000000), data );
              if (rc) { FAPI_ERR("fapiGetScom Content of EX_DPLL_CPM_PARM_REG_0x1*0F0152, Loop: %d  failed. With rc = 0x%x", c, (uint32_t)rc);  return rc;    }
              
              // if debug mode read back
              //if (VERBOSE) {
              //  rc = fapiGetScom(i_target, EX_DPLL_CPM_PARM_REG_0x100F0152 + (l_ex_number * 0x01000000) , data); if (l_rc) return rc;
              //  FAPI_DBG(" Post write content of EX_DPLL_CPM_PARM_REG_0x1*0F0152 , Loop: %d :  %016llX", c, data.getDoubleWord(0) );
              //}
              FAPI_INF ("Reset CPM_FILTER_ENABLE, clear bit 0 of EX_DPLL_CPM_PARM_REG_0x1*0F0152 " );
              
              
              
              
              //  ******************************************************************
              //      - set PMGP1_REG
              //  ******************************************************************
              
              FAPI_INF("\t-----------------------------------------------------");
              FAPI_INF("\tPMGP1_REG Configuration                  ");
              FAPI_INF("\t-----------------------------------------------------");  
              FAPI_INF("\t  pm_sleep_entry          => %d ", pm_sleep_entry );
              FAPI_INF("\t  pm_sleep_exit           => %d ", pm_sleep_exit  );
              FAPI_INF("\t  pm_sleep_type           => %d ", pm_sleep_type  ); 
              FAPI_INF("\t  pm_winkle_entry         => %d ", pm_winkle_entry  ); 
              FAPI_INF("\t  pm_winkle_exit          => %d ", pm_winkle_exit  ); 
              FAPI_INF("\t  pm_winkle_type          => %d ", pm_winkle_type  ); 
              FAPI_INF("\t                                   "                     );
              FAPI_INF("\t                                   "                     );
              FAPI_INF("\t-----------------------------------------------------");     
              
              
              FAPI_DBG("*************************************");
              FAPI_INF("Write to register PMGP1_REG  ");
              FAPI_DBG("*************************************");
              
              
              // if debug mode read before
              //if (VERBOSE) {
              //  rc = fapiGetScom(i_target, EX_PMGP1_REG_0_RWXx100F0103 + (l_ex_number * 0x01000000) , data); if (l_rc) return rc;
              //  FAPI_DBG(" Pre write content of EX_PMGP1_REG_0_RWXx1*0F0103 , Loop: %d :  %016llX", c, data.getDoubleWord(0) );
              //}        
          
              if (pm_sleep_entry) {
                l_rc = data.flushTo0();
                l_rc |= data.setBit(0);
                if (l_rc) { FAPI_ERR("Bit operation failed. With rc = 0x%x", (uint32_t)l_rc);  rc.setEcmdError(l_rc); return rc;    }
                rc = fapiPutScom(i_target, EX_PMGP1_REG_0_WORx100F0105 + (l_ex_number * 0x01000000) , data); 
                if (rc) { FAPI_ERR("fapiPutScom(EX_PMGP1_REG_0_WORx100F0105) failed. With rc = 0x%x", (uint32_t)rc);  return rc;    }   
              }  else  {
                l_rc = data.flushTo1();
                l_rc |= data.clearBit(0);
                if (l_rc) { FAPI_ERR("Bit operation failed. With rc = 0x%x", (uint32_t)l_rc);  rc.setEcmdError(l_rc); return rc;    }
                rc = fapiPutScom(i_target, EX_PMGP1_REG_0_WANDx100F0104 + (l_ex_number * 0x01000000) , data);    
                if (rc) { FAPI_ERR("fapiPutScom(EX_PMGP1_REG_0_WANDx100F0104) failed. With rc = 0x%x", (uint32_t)rc);  return rc;    }   
              };
              
              if (pm_sleep_exit) {
                l_rc = data.flushTo0();
                l_rc |= data.setBit(1);
                if (l_rc) { FAPI_ERR("Bit operation failed. With rc = 0x%x", (uint32_t)l_rc);  rc.setEcmdError(l_rc); return rc;    }
                rc = fapiPutScom(i_target, EX_PMGP1_REG_0_WORx100F0105 + (l_ex_number * 0x01000000) , data); 
                if (rc) { FAPI_ERR("fapiPutScom(EX_PMGP1_REG_0_WORx100F0105) failed. With rc = 0x%x", (uint32_t)rc);  return rc;    }   
              }  else  {
                l_rc = data.flushTo1();
                l_rc |= data.clearBit(1);
                if (l_rc) { FAPI_ERR("Bit operation failed. With rc = 0x%x", (uint32_t)l_rc);  rc.setEcmdError(l_rc); return rc;    }
                rc = fapiPutScom(i_target, EX_PMGP1_REG_0_WANDx100F0104 + (l_ex_number * 0x01000000) , data);   
                if (rc) { FAPI_ERR("fapiPutScom(EX_PMGP1_REG_0_WORx100F0105) failed. With rc = 0x%x", (uint32_t)rc);  return rc;    }   
              };
              
              if (pm_sleep_type) {
                l_rc = data.flushTo0();
                l_rc |= data.setBit(2);
                if (l_rc) { FAPI_ERR("Bit operation failed. With rc = 0x%x", (uint32_t)l_rc);  rc.setEcmdError(l_rc); return rc;    }
                rc = fapiPutScom(i_target, EX_PMGP1_REG_0_WORx100F0105 + (l_ex_number * 0x01000000) , data); 
                if (rc) { FAPI_ERR("fapiPutScom(EX_PMGP1_REG_0_WORx100F0105) failed. With rc = 0x%x", (uint32_t)rc);  return rc;    }   
              }  else  {
                l_rc = data.flushTo1();
                l_rc |= data.clearBit(2);
                if (l_rc) { FAPI_ERR("Bit operation failed. With rc = 0x%x", (uint32_t)l_rc);  rc.setEcmdError(l_rc); return rc;    }
                rc = fapiPutScom(i_target, EX_PMGP1_REG_0_WANDx100F0104 + (l_ex_number * 0x01000000) , data); 
                if (rc) { FAPI_ERR("fapiPutScom(EX_PMGP1_REG_0_WORx100F0105) failed. With rc = 0x%x", (uint32_t)rc);  return rc;    }   
              };
              
              if (pm_winkle_entry) {
                l_rc = data.flushTo0();
                l_rc |= data.setBit(3);
                if (l_rc) { FAPI_ERR("Bit operation failed. With rc = 0x%x", (uint32_t)l_rc);  rc.setEcmdError(l_rc); return rc;    }
                rc = fapiPutScom(i_target, EX_PMGP1_REG_0_WORx100F0105 + (l_ex_number * 0x01000000) , data); 
                if (rc) { FAPI_ERR("fapiPutScom(EX_PMGP1_REG_0_WORx100F0105) failed. With rc = 0x%x", (uint32_t)rc);  return rc;    }   
              }  else  {
                l_rc = data.flushTo1();
                l_rc |= data.clearBit(3);
                if (l_rc) { FAPI_ERR("Bit operation failed. With rc = 0x%x", (uint32_t)l_rc);  rc.setEcmdError(l_rc); return rc;    }
                rc = fapiPutScom(i_target, EX_PMGP1_REG_0_WANDx100F0104 + (l_ex_number * 0x01000000) , data);               
                if (rc) { FAPI_ERR("fapiPutScom(EX_PMGP1_REG_0_WORx100F0105) failed. With rc = 0x%x", (uint32_t)rc);  return rc;    }   
              };
              
              if (pm_winkle_exit) {
                l_rc = data.flushTo0();
                l_rc |= data.setBit(4);
                if (l_rc) { FAPI_ERR("Bit operation failed. With rc = 0x%x", (uint32_t)l_rc);  rc.setEcmdError(l_rc); return rc;    }
                rc = fapiPutScom(i_target, EX_PMGP1_REG_0_WORx100F0105 + (l_ex_number * 0x01000000) , data); 
                if (rc) { FAPI_ERR("fapiPutScom(EX_PMGP1_REG_0_WORx100F0105) failed. With rc = 0x%x", (uint32_t)rc);  return rc;    }   
              }  else  {
                l_rc = data.flushTo1();
                l_rc |= data.clearBit(4);
                if (l_rc) { FAPI_ERR("Bit operation failed. With rc = 0x%x", (uint32_t)l_rc);  rc.setEcmdError(l_rc); return rc;    }
                rc = fapiPutScom(i_target, EX_PMGP1_REG_0_WANDx100F0104 + (l_ex_number * 0x01000000) , data);               
                if (rc) { FAPI_ERR("fapiPutScom(EX_PMGP1_REG_0_WORx100F0105) failed. With rc = 0x%x", (uint32_t)rc);  return rc;    }   
              };
              
              if (pm_winkle_type) {
                l_rc = data.flushTo0();
                l_rc |= data.setBit(5);
                if (l_rc) { FAPI_ERR("Bit operation failed. With rc = 0x%x", (uint32_t)l_rc);  rc.setEcmdError(l_rc); return rc;    }
                rc = fapiPutScom(i_target, EX_PMGP1_REG_0_WORx100F0105 + (l_ex_number * 0x01000000) , data);
                if (rc) { FAPI_ERR("fapiPutScom(EX_PMGP1_REG_0_WORx100F0105) failed. With rc = 0x%x", (uint32_t)rc);  return rc;    }   
              }  else  {
                l_rc = data.flushTo1();
                l_rc |= data.clearBit(5);
                if (l_rc) { FAPI_ERR("Bit operation failed. With rc = 0x%x", (uint32_t)l_rc);  rc.setEcmdError(l_rc); return rc;    }
                rc = fapiPutScom(i_target, EX_PMGP1_REG_0_WANDx100F0104 + (l_ex_number * 0x01000000) , data); 
                if (rc) { FAPI_ERR("fapiPutScom(EX_PMGP1_REG_0_WORx100F0105) failed. With rc = 0x%x", (uint32_t)rc);  return rc;    }   
              };
              
              
              
              
              // if debug mode read back
              //if (VERBOSE) {
              //  rc = fapiGetScom(i_target, EX_PMGP1_REG_0_RWXx100F0103 + (l_ex_number * 0x01000000) , data); if (l_rc) return rc;
              //  FAPI_DBG(" Post write content of EX_PMGP1_REG_0_RWXx1*0F0103 , Loop: %d :  %016llX", c, data.getDoubleWord(0) );
              //}
              
              
              
              
              
              
              FAPI_DBG("*************************************");
              FAPI_INF("Write to Power_Management_Control_Reg ");
              FAPI_DBG("*************************************");
              
              // if debug mode read before
              //if (VERBOSE) {
              //  rc = fapiGetScom(i_target, EX_PCBS_Power_Management_Control_Reg_0x100F0159 + (l_ex_number * 0x01000000) , data); if (l_rc) return rc;
              //  FAPI_DBG(" Pre write content of EX_PCBS_Power_Management_Control_Reg_0x1*0F0159 , Loop: %d :  %s", c, data.getDoubleWord(0) );
              //}       
              
              // Clear buffer
              l_rc = data.flushTo0();
              if (l_rc) { FAPI_ERR("Bit operation failed. With rc = 0x%x", (uint32_t)l_rc);  rc.setEcmdError(l_rc); return rc;    }
                                                      
              rc = fapiPutScom(i_target, EX_PCBS_Power_Management_Control_Reg_0x100F0159 + (l_ex_number * 0x01000000), data );
              if (rc) { FAPI_ERR("fapiGetScom Content of EX_PCBS_Power_Management_Control_Reg_0x1*0F0159, Loop: %d  failed. With rc = 0x%x", c, (uint32_t)rc);  return rc;    }
              
              // if debug mode read back
              //if (VERBOSE) {
              //  rc = fapiGetScom(i_target, EX_PCBS_Power_Management_Control_Reg_0x100F0159 + (l_ex_number * 0x01000000) , data); if (l_rc) return rc;
              //  FAPI_DBG(" Post write content of EX_PCBS_Power_Management_Control_Reg_0x1*0F0159 , Loop: %d :  %s", c, data.getDoubleWord(0) );
              //}
              FAPI_INF ("PMCR default value adjustment (Hardware flush 0) of EX_PCBS_Power_Management_Control_Reg_0x1*0F0159 " );       
              
              
              
              
              FAPI_DBG("*************************************");
              FAPI_INF("Write to Power_Management_Idle_Control_Reg ");
              FAPI_DBG("*************************************");
              
              // if debug mode read before
              //if (VERBOSE) {
              //  rc = fapiGetScom(i_target, EX_PCBS_Power_Management_Idle_Control_Reg_0x100F0158 + (l_ex_number * 0x01000000) , data); if (l_rc) return rc;
              //  FAPI_DBG(" Pre write content of EX_PCBS_Power_Management_Idle_Control_Reg_0x1*0F0158 , Loop: %d :  %s", c, data.getDoubleWord(0) );
              //}       
              
              // Clear buffer
              l_rc = data.flushTo0();
              if (l_rc) { FAPI_ERR("Bit operation failed. With rc = 0x%x", (uint32_t)l_rc);  rc.setEcmdError(l_rc); return rc;    }
              
              
              rc = fapiPutScom(i_target, EX_PCBS_Power_Management_Idle_Control_Reg_0x100F0158 + (l_ex_number * 0x01000000), data );
              if (rc) { FAPI_ERR("fapiGetScom Content of EX_PCBS_Power_Management_Idle_Control_Reg_0x1*0F0158, Loop: %d  failed. With rc = 0x%x", c,  (uint32_t)rc);  return rc;    }
              
              // if debug mode read back
              //if (VERBOSE) {
              //  rc = fapiGetScom(i_target, EX_PCBS_Power_Management_Idle_Control_Reg_0x100F0158 + (l_ex_number * 0x01000000) , data); if (l_rc) return rc;
              //  FAPI_DBG(" Post write content of EX_PCBS_Power_Management_Idle_Control_Reg_0x1*0F0158 , Loop: %d :  %s", c, data.getDoubleWord(0) );
              //}
              
              FAPI_INF ("PMCR default value adjustment (Hardware flush 0) of EX_PCBS_Power_Management_Idle_Control_Reg_0x1*0F0158 " );       
              
              
                    
                    
       } //ELSE IF functional and ATTR_CHIP_UNIT_POS
     }  else  
     {
       // EX is not functional
       FAPI_DBG("Core number = %d  is not functional", c);
     }  //IF functional    
   }//ELSE IF ATTR_FUNCTIONAL 
   
 }  //END FOR
  
  return rc;
 
}  //end INIT


ReturnCode
p8_pcbs_init_reset(const Target &i_target,  uint32_t i_mode, struct_pcbs_val_init_type pcbs_val_init)
{
    fapi::ReturnCode rc;
    uint32_t l_rc;              // local returncode

    ecmdDataBufferBase data(64);
    ecmdDataBufferBase mask(64);


    // Variables
    std::vector<fapi::Target>      l_exChiplets;   
    fapi::TargetState              l_state = TARGET_STATE_FUNCTIONAL;    // TARGET_STATE_PRESENT or TARGET_STATE_FUNCTIONAL. It just depends on what you want to do.
    
    uint8_t                        l_functional = 0;
    uint8_t                        l_ex_number = 0;
    
    uint32_t loopcount            =    0;    // number of times PCBS-PMSR has been checked
    
    const uint32_t SCANZERO             = 1;            // enable scan-zero loading upfront
    
    
    //  ******************************************************************
    //  Code starts here
    //  ******************************************************************
    
    rc = fapiGetChildChiplets(i_target, fapi::TARGET_TYPE_EX_CHIPLET, l_exChiplets, l_state); if (rc) return rc;
    FAPI_DBG("  chiplet vector size          => %u", l_exChiplets.size());

                                                     
        

    // For each chiplet
    for (uint8_t c=0; c< l_exChiplets.size(); c++) {
      FAPI_DBG("********* ******************* *********");     
      FAPI_DBG("\t Loop Variable %d ",c);
      FAPI_DBG("********* ******************* *********");
      
      rc = FAPI_ATTR_GET(ATTR_FUNCTIONAL, &l_exChiplets[c], l_functional);
      if (rc) 
      {
        FAPI_ERR("fapiGetAttribute of ATTR_FUNCTIONAL with rc = 0x%x", (uint32_t)rc);  
        return rc; 
      } else  
      {
        if (l_functional)
        {
          // The ex is functional let's build the SCOM address 
          rc = FAPI_ATTR_GET(ATTR_CHIP_UNIT_POS, &l_exChiplets[c], l_ex_number);
          if (rc) 
          {
            FAPI_ERR("No functional chiplets exist");  
            FAPI_ERR("fapiGetAttribute of ATTR_CHIP_UNIT_POS with rc = 0x%x", (uint32_t)rc);  
            return rc; 
          }             
          else 
          {
            
            FAPI_DBG("Core number = %d", l_ex_number);
            


            if (SCANZERO) { 
                //  ******************************************************************
                //  initialize all pm_reg with scan-zero values upfront
                //  ******************************************************************
                FAPI_DBG("***********************************************");
                FAPI_INF(" Set all PCBSLV_PM registers to the scan0 value");
                FAPI_DBG("***********************************************");
                
                
                /// \todo   Review if scan0 values can/should be applied
                //l_rc = data.setDoubleWord(0, PMGP0_REG_0x100F0100_scan0);           
                //if (l_rc) { FAPI_ERR("Bit operation failed. With rc = 0x%x", (uint32_t)rc);  rc.setEcmdError(l_rc); return rc;    }
                //rc = fapiPutScom(i_target, EX_PMGP0_0x100F0100 + (l_ex_number * 0x01000000), data );
                //if (l_rc) { FAPI_ERR("fapiGetScom(PMGP0_REG_0_RWXx1*0F0100) failed. With rc = 0x%x", (uint32_t)rc);  return rc;    }             

                // Set in Multicast section above
                //l_rc = data.setDoubleWord(0, PMGP1_REG_0x100F0103_scan0);           
                //if (l_rc) { FAPI_ERR("Bit operation failed. With rc = 0x%x", (uint32_t)rc);  rc.setEcmdError(l_rc); return rc;    }
                //rc = fapiPutScom(i_target, EX_PMGP1_REG_0_RWXx100F0103 + (l_ex_number * 0x01000000), data );
                //if (l_rc) { FAPI_ERR("fapiGetScom(PMGP1_REG_0_RWXx1*0F0103) failed. With rc = 0x%x", (uint32_t)rc);  return rc;    }  
                
                l_rc = data.setDoubleWord(0, EX_PFVddCntlStat_REG_0x100F0106_scan0);
                if (l_rc) { FAPI_ERR("Bit operation failed. With rc = 0x%x", (uint32_t)l_rc);  rc.setEcmdError(l_rc); return rc;    }
                rc = fapiPutScom(i_target, EX_PFVddCntlStat_REG_0x100F0106 + (l_ex_number * 0x01000000), data );
                if (rc) { FAPI_ERR("fapiGetScom(PFVddCntlStat_REG_0x1*0F0106) failed. With rc = 0x%x", (uint32_t)rc);  return rc;    }     
                
                l_rc = data.setDoubleWord(0, EX_PFVcsCntlStat_REG_0x100F010E_scan0);
                if (l_rc) { FAPI_ERR("Bit operation failed. With rc = 0x%x", (uint32_t)l_rc);  rc.setEcmdError(l_rc); return rc;    }
                rc = fapiPutScom(i_target, EX_PFVcsCntlStat_REG_0x100F010E + (l_ex_number * 0x01000000), data );
                if (rc) { FAPI_ERR("fapiGetScom(PFVcsCntlStat_REG_0x1*0F010E) failed. With rc = 0x%x", (uint32_t)rc);  return rc;    }     
                              
                l_rc = data.setDoubleWord(0, EX_PCBS_Resonant_Clock_Control_Reg0_0x100F0165_scan0);
                if (l_rc) { FAPI_ERR("Bit operation failed. With rc = 0x%x", (uint32_t)l_rc);  rc.setEcmdError(l_rc); return rc;    }
                rc = fapiPutScom(i_target, EX_PCBS_Resonant_Clock_Control_Reg0_0x100F0165 + (l_ex_number * 0x01000000), data );
                if (rc) { FAPI_ERR("fapiGetScom(PCBS_Resonant_Clock_Control_Reg0_0x1*0F0165) failed. With rc = 0x%x", (uint32_t)rc);  return rc;    }   
                
                // Clear buffer
                l_rc = data.flushTo0(); 
                if (l_rc) { FAPI_ERR("Bit operation failed. With rc = 0x%x", (uint32_t)l_rc);  rc.setEcmdError(l_rc); return rc;    }
                
                l_rc = data.setWord(0, EX_PMErrMask_REG_0x100F010A_scan0);
                if (l_rc) { FAPI_ERR("Bit operation failed. With rc = 0x%x", (uint32_t)l_rc);  rc.setEcmdError(l_rc); return rc;    }
                rc = fapiPutScom(i_target, EX_PMErrMask_REG_0x100F010A + (l_ex_number * 0x01000000), data );
                if (rc) { FAPI_ERR("fapiGetScom(PMErrMask_REG_0x1*0F010A) failed. With rc = 0x%x", (uint32_t)rc);  return rc;    }             
                
                l_rc = data.setWord(0, EX_PMSpcWkupFSP_REG_0x100F010B_scan0);
                if (l_rc) { FAPI_ERR("Bit operation failed. With rc = 0x%x", (uint32_t)l_rc);  rc.setEcmdError(l_rc); return rc;    }
                rc = fapiPutScom(i_target, EX_PMSpcWkupFSP_REG_0x100F010B + (l_ex_number * 0x01000000), data );
                if (rc) { FAPI_ERR("fapiGetScom(EX_PMSpcWkupFSP_REG_0x100F010B) failed. With rc = 0x%x", (uint32_t)rc);  return rc;    }
                
                l_rc = data.setWord(0, EX_PMSpcWkupOCC_REG_0x100F010C_scan0);
                if (l_rc) { FAPI_ERR("Bit operation failed. With rc = 0x%x", (uint32_t)l_rc);  rc.setEcmdError(l_rc); return rc;    }
                rc = fapiPutScom(i_target, EX_PMSpcWkupOCC_REG_0x100F010C + (l_ex_number * 0x01000000), data );
                if (rc) { FAPI_ERR("fapiGetScom(PMSpcWkupOCC_REG_0x1*0F010C) failed. With rc = 0x%x", (uint32_t)rc);  return rc;    }             
                
                l_rc = data.setWord(0, EX_PMSpcWkupPHYP_REG_0x100F010D_scan0);
                if (l_rc) { FAPI_ERR("Bit operation failed. With rc = 0x%x", (uint32_t)l_rc);  rc.setEcmdError(l_rc); return rc;    }
                rc = fapiPutScom(i_target, EX_PMSpcWkupPHYP_REG_0x100F010D + (l_ex_number * 0x01000000), data );
                if (rc) { FAPI_ERR("fapiGetScom(PMSpcWkupPHYP_REG_0x1*0F010D) failed. With rc = 0x%x", (uint32_t)rc);  return rc;    }             
                
                

                l_rc = data.setWord(0, EX_CorePFPUDly_REG_0x100F012C_scan0);
                if (l_rc) { FAPI_ERR("Bit operation failed. With rc = 0x%x", (uint32_t)l_rc);  rc.setEcmdError(l_rc); return rc;    }
                rc = fapiPutScom(i_target, EX_CorePFPUDly_REG_0x100F012C + (l_ex_number * 0x01000000), data );
                if (rc) { FAPI_ERR("fapiGetScom(CorePFPUDly_REG_0x1*0F012C) failed. With rc = 0x%x", (uint32_t)rc);  return rc;    }                        

                l_rc = data.setWord(0, EX_CorePFPDDly_REG_0x100F012D_scan0);
                if (l_rc) { FAPI_ERR("Bit operation failed. With rc = 0x%x", (uint32_t)l_rc);  rc.setEcmdError(l_rc); return rc;    }
                rc = fapiPutScom(i_target, EX_CorePFPDDly_REG_0x100F012D + (l_ex_number * 0x01000000), data );
                if (rc) { FAPI_ERR("fapiGetScom(CorePFPDDly_REG_0x1*0F012D) failed. With rc = 0x%x", (uint32_t)rc);  return rc;    }                        

                l_rc = data.setWord(0, EX_CorePFVRET_REG_0x100F0130_scan0);
                if (l_rc) { FAPI_ERR("Bit operation failed. With rc = 0x%x", (uint32_t)l_rc);  rc.setEcmdError(l_rc); return rc;    }
                rc = fapiPutScom(i_target, EX_CorePFVRET_REG_0x100F0130 + (l_ex_number * 0x01000000), data );
                if (rc) { FAPI_ERR("fapiGetScom(CorePFVRET_REG_0x1*0F0130) failed. With rc = 0x%x", (uint32_t)rc);  return rc;    }                        


                
                l_rc = data.setWord(0, EX_ECOPFPUDly_REG_0x100F014C_scan0);
                if (l_rc) { FAPI_ERR("Bit operation failed. With rc = 0x%x", (uint32_t)l_rc);  rc.setEcmdError(l_rc); return rc;    }
                rc = fapiPutScom(i_target, EX_ECOPFPUDly_REG_0x100F014C + (l_ex_number * 0x01000000), data );
                if (rc) { FAPI_ERR("fapiGetScom(ECOPFPUDly_REG_0x1*0F014C) failed. With rc = 0x%x", (uint32_t)rc);  return rc;    }   
                
                l_rc = data.setWord(0, EX_ECOPFPDDly_REG_0x100F014D_scan0);
                if (l_rc) { FAPI_ERR("Bit operation failed. With rc = 0x%x", (uint32_t)l_rc);  rc.setEcmdError(l_rc); return rc;    }
                rc = fapiPutScom(i_target, EX_ECOPFPDDly_REG_0x100F014D + (l_ex_number * 0x01000000), data );
                if (rc) { FAPI_ERR("fapiGetScom(ECOPFPDDly_REG_0x1*0F014D) failed. With rc = 0x%x", (uint32_t)rc);  return rc;    }   
                
                l_rc = data.setWord(0, EX_ECOPFVRET_REG_0x100F0150_scan0);
                if (l_rc) { FAPI_ERR("Bit operation failed. With rc = 0x%x", (uint32_t)l_rc);  rc.setEcmdError(l_rc); return rc;    }
                rc = fapiPutScom(i_target, EX_ECOPFVRET_REG_0x100F0150 + (l_ex_number * 0x01000000), data );
                if (rc) { FAPI_ERR("fapiGetScom(ECOPFVRET_REG_0x1*0F0150) failed. With rc = 0x%x", (uint32_t)rc);  return rc;    }   
                
                
                l_rc = data.setWord(0, EX_FREQCNTL_0x100F0151_scan0);
                if (l_rc) { FAPI_ERR("Bit operation failed. With rc = 0x%x", (uint32_t)l_rc);  rc.setEcmdError(l_rc); return rc;    }
                rc = fapiPutScom(i_target, EX_FREQCNTL_0x100F0151 + (l_ex_number * 0x01000000), data );
                if (rc) { FAPI_ERR("fapiGetScom(FREQ_CTRL_REG_0x1*0F0151) failed. With rc = 0x%x", (uint32_t)rc);  return rc;    }   
                
                l_rc = data.setWord(0, EX_DPLL_CPM_PARM_REG_0x100F0152_scan0);
                if (l_rc) { FAPI_ERR("Bit operation failed. With rc = 0x%x", (uint32_t)l_rc);  rc.setEcmdError(l_rc); return rc;    }
                rc = fapiPutScom(i_target, EX_DPLL_CPM_PARM_REG_0x100F0152 + (l_ex_number * 0x01000000), data );
                if (rc) { FAPI_ERR("fapiGetScom(DPLL_CPM_PARM_REG_0x1*0F0152) failed. With rc = 0x%x", (uint32_t)rc);  return rc;    }   
                
                l_rc = data.setWord(0, EX_PCBS_iVRM_Control_Status_Reg_0x100F0154_scan0);
                if (l_rc) { FAPI_ERR("Bit operation failed. With rc = 0x%x", (uint32_t)l_rc);  rc.setEcmdError(l_rc); return rc;    }
                rc = fapiPutScom(i_target, EX_PCBS_iVRM_Control_Status_Reg_0x100F0154 + (l_ex_number * 0x01000000), data );
                if (rc) { FAPI_ERR("fapiGetScom(PCBS_iVRM_Control_Status_Reg_0x1*0F0154) failed. With rc = 0x%x", (uint32_t)rc);  return rc;    }   
                
                l_rc = data.setWord(0, EX_PCBS_iVRM_Value_Setting_Reg_0x100F0155_scan0);
                if (l_rc) { FAPI_ERR("Bit operation failed. With rc = 0x%x", (uint32_t)l_rc);  rc.setEcmdError(l_rc); return rc;    }
                rc = fapiPutScom(i_target, EX_PCBS_iVRM_Value_Setting_Reg_0x100F0155 + (l_ex_number * 0x01000000), data );
                if (rc) { FAPI_ERR("fapiGetScom(PCBS_iVRM_Value_Setting_Reg_0x1*0F0155) failed. With rc = 0x%x", (uint32_t)rc);  return rc;    }   
                
                // Scan0 values set per multicast
                // l_rc = data.setWord(0, EX_PCBSPM_MODE_REG_0x100F0156_scan0);
                // if (l_rc) { FAPI_ERR("Bit operation failed. With rc = 0x%x", (uint32_t)rc);  rc.setEcmdError(l_rc); return rc;    }
                // rc = fapiPutScom(i_target, EX_PCBSPM_MODE_REG_0x100F0156 + (l_ex_number * 0x01000000), data );
                // if (l_rc) { FAPI_ERR("fapiGetScom(PCBSPM_MODE_REG_0x1*0F0156) failed. With rc = 0x%x", (uint32_t)rc);  return rc;    }   
                
                l_rc = data.setWord(0, EX_PCBS_Power_Management_Control_Reg_0x100F0159_scan0);
                if (l_rc) { FAPI_ERR("Bit operation failed. With rc = 0x%x", (uint32_t)l_rc);  rc.setEcmdError(l_rc); return rc;    }
                rc = fapiPutScom(i_target, EX_PCBS_Power_Management_Control_Reg_0x100F0159 + (l_ex_number * 0x01000000), data );
                if (rc) { FAPI_ERR("fapiGetScom(PCBS_Power_Management_Control_Reg_0x1*0F0159) failed. With rc = 0x%x", (uint32_t)rc);  return rc;    }   
                
                l_rc = data.setWord(0, EX_PCBS_PMC_VF_CTRL_REG_0x100F015A_scan0);
                if (l_rc) { FAPI_ERR("Bit operation failed. With rc = 0x%x", (uint32_t)l_rc);  rc.setEcmdError(l_rc); return rc;    }
                rc = fapiPutScom(i_target, EX_PCBS_PMC_VF_CTRL_REG_0x100F015A + (l_ex_number * 0x01000000), data );
                if (rc) { FAPI_ERR("fapiGetScom(PCBS_PMC_VF_CTRL_REG_0x1*0F015A) failed. With rc = 0x%x", (uint32_t)rc);  return rc;    }   
                
                l_rc = data.setWord(0, EX_PCBS_UNDERVOLTING_REG_0x100F015B_scan0);
                if (l_rc) { FAPI_ERR("Bit operation failed. With rc = 0x%x", (uint32_t)l_rc);  rc.setEcmdError(l_rc); return rc;    }
                rc = fapiPutScom(i_target, EX_PCBS_UNDERVOLTING_REG_0x100F015B + (l_ex_number * 0x01000000), data );
                if (rc) { FAPI_ERR("fapiGetScom(PCBS_UNDERVOLTING_REG_0x1*0F015B) failed. With rc = 0x%x", (uint32_t)rc);  return rc;    }   
                
                l_rc = data.setWord(0, EX_PCBS_Pstate_Index_Bound_Reg_0x100F015C_scan0);
                if (l_rc) { FAPI_ERR("Bit operation failed. With rc = 0x%x", (uint32_t)l_rc);  rc.setEcmdError(l_rc); return rc;    }
                rc = fapiPutScom(i_target, EX_PCBS_Pstate_Index_Bound_Reg_0x100F015C + (l_ex_number * 0x01000000), data );
                if (rc) { FAPI_ERR("fapiGetScom(EX_PCBS_Pstate_Index_Bound_Reg_0x100F015C) failed. With rc = 0x%x", (uint32_t)rc);  return rc;    }
                
                // Scan0 values set per multicast
                //l_rc = data.setWord(0, EX_PCBS_Power_Management_Bounds_Reg_0x100F015D_scan0);
                //if (l_rc) { FAPI_ERR("Bit operation failed. With rc = 0x%x", (uint32_t)rc);  rc.setEcmdError(l_rc); return rc;    }
                //rc = fapiPutScom(i_target,  EX_PCBS_Power_Management_Bounds_Reg_0x100F015D + (l_ex_number * 0x01000000), data );
                //if (l_rc) { FAPI_ERR("fapiGetScom(PCBS_Power_Management_Bounds_Reg_0x1*0F015D) failed. With rc = 0x%x", (uint32_t)rc);  return rc;    }   
                
                l_rc = data.setWord(0, EX_PCBS_PSTATE_TABLE_CTRL_REG_0x100F015E_scan0);
                if (l_rc) { FAPI_ERR("Bit operation failed. With rc = 0x%x", (uint32_t)l_rc);  rc.setEcmdError(l_rc); return rc;    }
                rc = fapiPutScom(i_target, EX_PCBS_PSTATE_TABLE_CTRL_REG_0x100F015E + (l_ex_number * 0x01000000), data );
                if (rc) { FAPI_ERR("fapiGetScom(PCBS_PSTATE_TABLE_CTRL_REG_0x1*0F015E) failed. With rc = 0x%x", (uint32_t)rc);  return rc;    }   
                
                //l_rc = data.setWord(0, EX_PCBS_Pstate_Step_Target_Register_0x100F0160_scan0);
                //if (l_rc) { FAPI_ERR("Bit operation failed. With rc = 0x%x", (uint32_t)l_rc);  rc.setEcmdError(l_rc); return rc;    }
                //rc = fapiPutScom(i_target, EX_PCBS_Pstate_Step_Target_Register_0x100F0160 + (l_ex_number * 0x01000000), data );
                //if (rc) { FAPI_ERR("fapiGetScom(PCBS_Pstate_Step_Target_Register_0x1*0F0160) failed. With rc = 0x%x", (uint32_t)rc);  return rc;    }
                
                l_rc = data.setWord(0, EX_PCBS_iVRM_VID_Control_Reg0_0x100F0162_scan0);
                if (l_rc) { FAPI_ERR("Bit operation failed. With rc = 0x%x", (uint32_t)l_rc);  rc.setEcmdError(l_rc); return rc;    }
                rc = fapiPutScom(i_target, EX_PCBS_iVRM_VID_Control_Reg0_0x100F0162 + (l_ex_number * 0x01000000), data );
                if (rc) { FAPI_ERR("fapiGetScom(PCBS_iVRM_VID_Control_Reg0_0x1*0F0162) failed. With rc = 0x%x", (uint32_t)rc);  return rc;    }   
                
                l_rc = data.setWord(0, EX_PCBS_iVRM_VID_Control_Reg1_0x100F0163_scan0);
                if (l_rc) { FAPI_ERR("Bit operation failed. With rc = 0x%x", (uint32_t)l_rc);  rc.setEcmdError(l_rc); return rc;    }
                rc = fapiPutScom(i_target, EX_PCBS_iVRM_VID_Control_Reg1_0x100F0163 + (l_ex_number * 0x01000000), data );
                if (rc) { FAPI_ERR("fapiGetScom(PCBS_iVRM_VID_Control_Reg1_0x1*0F0163) failed. With rc = 0x%x", (uint32_t)rc);  return rc;    }   
                
                //l_rc = data.setWord(0, EX_PCBS_OCC_Heartbeat_Reg_0x100F0164_scan0);
                //if (l_rc) { FAPI_ERR("Bit operation failed. With rc = 0x%x", (uint32_t)l_rc);  rc.setEcmdError(l_rc); return rc;    }
                //rc = fapiPutScom(i_target, EX_PCBS_OCC_Heartbeat_Reg_0x100F0164 + (l_ex_number * 0x01000000), data );
                //if (rc) { FAPI_ERR("fapiGetScom(PCBS_OCC_Heartbeat_Reg_0x1*0F0164) failed. With rc = 0x%x", (uint32_t)rc);  return rc;    }
  
                l_rc = data.setWord(0, EX_PCBS_Resonant_Clock_Control_Reg1_0x100F0166_scan0);
                if (l_rc) { FAPI_ERR("Bit operation failed. With rc = 0x%x", (uint32_t)l_rc);  rc.setEcmdError(l_rc); return rc;    }
                rc = fapiPutScom(i_target, EX_PCBS_Resonant_Clock_Control_Reg1_0x100F0166 + (l_ex_number * 0x01000000), data );
                if (rc) { FAPI_ERR("fapiGetScom(PCBS_Resonant_Clock_Control_Reg1_0x1*0F0166) failed. With rc = 0x%x", (uint32_t)rc);  return rc;    }   
                
                /// \todo  Regcheck error check at latest model 
                //              l_rc = data.setWord(0, EX_PCBS_Local_Pstate_Frequency_Target_Control_Register_0x100F0168_scan0);
                //              if (l_rc) { FAPI_ERR("Bit operation failed. With rc = 0x%x", (uint32_t)rc);  rc.setEcmdError(l_rc); return rc;    }
                //              rc = fapiPutScom(i_target, EX_PCBS_Local_Pstate_Frequency_Target_Control_Register_0x100F0168 + (l_ex_number * 0x01000000), data );
                //              if (l_rc) { FAPI_ERR("fapiGetScom(PCBS_Local_Pstate_Frequency_Target_Control_Register_0x1*0F0168) failed. With rc = 0x%x", (uint32_t)rc);  return rc;    }   
                
            
            
            }  
                                  
                //  ******************************************************************
                //  Force safe mode
                //  ******************************************************************
                //  ******************************************************************
                //  - set PCBS_PM_PMGP1_REG_1
                //              [12] force_safe_mode = 1
                //      
                //  ******************************************************************
                
                FAPI_DBG("********* ******************* *********");
                FAPI_INF("Force safe mode");
                FAPI_DBG("********* ******************* *********");
                
                // Using Write OR to just set bit11 and bit12
                // Clear buffer          
                l_rc = data.flushTo0();  
                if (l_rc) { FAPI_ERR("Bit operation failed. With rc = 0x%x", (uint32_t)l_rc);  rc.setEcmdError(l_rc); return rc;    }
                
                // set scan0 value
                // scan0: 6C00  content after iStep: 4800
                // bit2: 0: Vret (fast sleep)
                //       1: Voff (deep sleep)
                // bit5: 0: Vret (fast winkle)
                //       1: Voff (deep winkle)
                /// \todo   Review if scan0 values can/should be applied 
                //l_rc = data.setDoubleWord(0, PMGP1_REG_0x100F0103_scan0);           
                //if (l_rc) { FAPI_ERR("Bit operation failed."); return rc; }
                
                l_rc = data.setBit(12);    //force_safe_mode = 1          
                if (l_rc) { FAPI_ERR("Bit operation failed. With rc = 0x%x", (uint32_t)l_rc);  rc.setEcmdError(l_rc); return rc;    }
                
                // simaet( "on" );        
                rc = fapiPutScom(i_target, EX_WRITE_ALL_EX_PMGP1_REG_0_WORx690F0105, data );
                if (rc) {  FAPI_ERR("fapiPutScom multicast (EX_WRITE_ALL_EX_PMGP1_REG_0_WORx690F0105) failed. With rc = 0x%x", (uint32_t)rc);  return rc;    }
                
                //if (VERBOSE) { 
                //  FAPI_DBG("********* ******************* *********");
                //  FAPI_DBG("Multicasted to EX_WRITE_ALL_EX_PMGP1_REG_0_WORx690F0105  :  %s",  data.getDoubleWord(0));
                //  FAPI_DBG("********* ******************* *********");
                //}
                
                
                // manual debug       
                // getscom p8 -k0 -n0 -s0 -p00 130F0103  -ixl
                // returns the expected values0x4818000000000000
                
                //rc = fapiGetScom(i_target, 0x130F0103, data); if (l_rc) return rc;
                //FAPI_DBG("XXXXXX Content of 0x130F0103 is :  %s", data.getDoubleWord(0));                            
                
                
                // if debug mode read back
                //if (VERBOSE) {                      
                //    if (chiplets_valid[c] == 1) {
                //      rc = fapiGetScom(i_target, EX_PMGP1_REG_0_RWXx100F0103  + (l_ex_number * 0x01000000), data); if (l_rc) return rc;
                //      FAPI_DBG("Content of PMGP1_REG_0_RWXx1*0F0103 is :  %s  ,  Loop: %d ", data.getDoubleWord(0) , c); 
                //      
                //      //rc = fapiGetScom(i_target, 0x130F0103, data); if (l_rc) return rc;
                //      //FAPI_DBG(" XXX2 Content of 0x130F0103 is :  %s", data.getDoubleWord(0));                            
                //    }                          
                // }
                
                FAPI_INF("Forced Safe Mode"); 
                

                //  ******************************************************************
                //  psafe Pstate achived AND FSM-stable ?
                //  ******************************************************************
                //  ******************************************************************
                //  - PCBS_POWER_MANAGEMENT_STATUS_REG[33] safe_mode_active
                //  - PCBS_POWER_MANAGEMENT_STATUS_REG[36] all_fsms_in_safe_state
                //
                //  ******************************************************************
                FAPI_DBG("**************************** *********");
                FAPI_INF("Psafe Pstate and FSM-stable?");
                FAPI_DBG("**************************** *********");

                loopcount = 0;
                rc = fapiGetScom( i_target,EX_PCBS_POWER_MANAGEMENT_STATUS_REG_0x100F0153 + (l_ex_number * 0x01000000) , data );
                if (rc) { FAPI_ERR("fapiGetScom(PCBS_POWER_MANAGEMENT_STATUS_REG_0x1*0F0153) failed. With rc = 0x%x", (uint32_t)rc);  return rc;    }

                while( data.isBitClear( 33 ) || data.isBitClear( 36 )  ) {   // loop until  (safe_mode_active AND all_fsms_in_safe_state)
                    FAPI_DBG("\t loopcount => %d ",loopcount  );
                                        
                    if( ++loopcount > pcbs_val_init.MAX_PSAFE_FSM_LOOPS )                     // OR timeout .... set to 20 loops
                        {
                          FAPI_ERR( "Gave up waiting for Psafe Pstate and FSM-stable!\n" );
                          FAPI_SET_HWP_ERROR(rc, RC_PROC_PCBS_CODE_SAFE_FSM_TIMEOUT);
                          return rc;
                        }
                        
                    
                  //  FAPI_DBG("Read of PCBS_POWER_MANAGEMENT_STATUS_REG_0x1*0F0153 content :  %016llX", data.getDoubleWord(0));
                  //    FAPI_DBG("Read of PCBS_POWER_MANAGEMENT_STATUS_REG_0x1*0F0153 content bit 33 :  %s", data.genBinStr(33,1).c_str());
                  //    FAPI_DBG("Read of PCBS_POWER_MANAGEMENT_STATUS_REG_0x1*0F0153 content bit 36 :  %s", data.genBinStr(36,1).c_str());
                                    
                    FAPI_INF("Is Psafe Pstate and FSM-stable ? \n");
                    FAPI_DBG("\t Wait DELAY: %d  ", pcbs_val_init.MAX_DELAY);
                    FAPI_DBG("\t Wait SimCycles: %d  ", pcbs_val_init.MAX_SIM_CYCLES);
                    
                /// \todo    once available .. right now no delay
                /// \todo    fapiDelay( post_flush_cyc_dly, post_flush_timedly );  // delay for each cycle

                    rc =  fapiDelay(pcbs_val_init.MAX_DELAY, pcbs_val_init.MAX_SIM_CYCLES);
                    if (rc) { FAPI_ERR("fapi::delay(MAX_DELAY, MAX_SIM_CYCLES) failed. With rc = 0x%x", (uint32_t)rc);  return rc;    }
                    

                    rc = fapiGetScom( i_target,EX_PCBS_POWER_MANAGEMENT_STATUS_REG_0x100F0153 + (l_ex_number * 0x01000000) , data );
                    if (rc) { FAPI_ERR("fapiGetScom(PCBS_POWER_MANAGEMENT_STATUS_REG_0x1*0F0153) failed. With rc = 0x%x", (uint32_t)rc);  return rc;    }

                }

                FAPI_INF("Psafe Pstate and FSM-stable is reached ...\n");



                //  ******************************************************************
                //  DPLL settings
                //  ******************************************************************
                //  ******************************************************************
                //  - enable dpll override
                //  	- PCBS_PM_PMGP1_REG_1[10]  dpll_freq_override_enable
                //  - get Psafe and global actual pstate
                //  - calculate minPstate
                //  - calculate dpll_fmin  = fnom + minPstate
                //  - set dpll_fmin
                //  - set dpll_fmax
                //  ******************************************************************
                FAPI_DBG("**************************** *********");
                FAPI_INF("DPLL settings");
                FAPI_DBG("**************************** *********");

                    //rc = fapiGetScom( i_target,PMGP1_REG_0_WORx100F00105 + (l_ex_number * 0x01000000) , data );
                    //if (l_rc) { FAPI_ERR("fapiGetScom(PMGP1_REG_0_WORx100F00105) failed. With rc = 0x%x", (uint32_t)rc);  return rc;    }

                //if (VERBOSE) {
                //  rc = fapiGetScom(i_target, EX_PMGP1_REG_0_RWXx100F0103  + (l_ex_number * 0x01000000), data); if (l_rc) return rc;
                //  FAPI_DBG(" Pre Write to PMGP1_REG_0_RWXx1*0F0103 :  %016llX", data.getDoubleWord(0));
                //}
                
                l_rc = data.flushTo0();
                if (l_rc) { FAPI_ERR("Bit operation failed. With rc = 0x%x", (uint32_t)l_rc);  rc.setEcmdError(l_rc); return rc;    }

                l_rc = data.setBit(10);     //dpll_freq_override_enable
                if (l_rc) { FAPI_ERR("Bit operation failed. With rc = 0x%x", (uint32_t)l_rc);  rc.setEcmdError(l_rc); return rc;    }

                rc = fapiPutScom(i_target, EX_PMGP1_REG_0_WORx100F0105  + (l_ex_number * 0x01000000), data );
                if (rc) { FAPI_ERR("fapiGetScom(PMGP1_REG_0_WORx1*0F0105) failed. With rc = 0x%x", (uint32_t)rc);  return rc;    }

                // if debug mode read back
                //if (VERBOSE) {
                //  rc = fapiGetScom(i_target, EX_PMGP1_REG_0_RWXx100F0103  + (l_ex_number * 0x01000000), data); if (l_rc) return rc;
                //  FAPI_DBG(" Post Write content of PMGP1_REG_0_RWXx1*0F0103 : %016llX", data.getDoubleWord(0));
                //}
                

                FAPI_DBG("*************************************");
                FAPI_INF(" Start calculation of DPLL fmin ....");
                FAPI_DBG("*************************************");


                //get PSAFE and GLOBAL ACTUAL PSTATE   EX_PCBS_OCC_Heartbeat_Reg_0x100F0164
                
                FAPI_INF("DPLL fmin = %d , DPLL fmax = %d set", pcbs_val_init.DPLL_FMIN, pcbs_val_init.DPLL_FMAX);
                
                
                rc = fapiGetScom( i_target,EX_PCBS_OCC_Heartbeat_Reg_0x100F0164 + (l_ex_number * 0x01000000) , data );
                if (rc) { FAPI_ERR("fapiGetScom(PCBS_OCC_HEARTBEAT_REG_0x1*0F0164) failed. With rc = 0x%x", (uint32_t)rc);  return rc;    }
                
                FAPI_DBG("Read Psafe [17..24] of PCBS_OCC_HEARTBEAT_REG_0x1*0F0164 content :  %016llX", data.getDoubleWord(0));
                
                  
                  
                l_rc = data.shiftLeft(17);          //  Psafe is bit 17..24
                if (l_rc) { FAPI_ERR("Bit operation failed. With rc = 0x%x", (uint32_t)l_rc);  rc.setEcmdError(l_rc); return rc;    }
                
                // assign Psafe to variable
                pcbs_val_init.PSAFE = data.getByte(0);      //
                if (l_rc) { FAPI_ERR("Bit operation failed. With rc = 0x%x", (uint32_t)l_rc);  rc.setEcmdError(l_rc); return rc;    }
                
                rc = fapiGetScom( i_target,EX_PCBS_POWER_MANAGEMENT_STATUS_REG_0x100F0153 + (l_ex_number * 0x01000000) , data );
                if (rc) { FAPI_ERR("fapiGetScom(PCBS_POWER_MANAGEMENT_STATUS_REG) failed. With rc = 0x%x", (uint32_t)rc);  return rc;    }

                
                FAPI_DBG("Read GLOBAL_ACTUAL_PSTATE [0..7] of PCBS_POWER_MANAGEMENT_STATUS_REG_0x1*0F0153 content :  %016llX", data.getDoubleWord(0));
                
                
                // assign GLOBAL_ACTUAL_PSTATE to variable
                pcbs_val_init.GLOBAL_ACTUAL_PSTATE = data.getByte(0);      //  GLOBAL_ACTUAL_PSTATE  is sbit 0..7
                if (l_rc) { FAPI_ERR("Bit operation failed. With rc = 0x%x", (uint32_t)l_rc);  rc.setEcmdError(l_rc); return rc;    }

                FAPI_INF("\t PSAFE => %d ", pcbs_val_init.PSAFE );
                FAPI_INF("\t GLOBAL_ACTUAL_PSTATE => %d ", pcbs_val_init.GLOBAL_ACTUAL_PSTATE );



                // set the min_pstate to the smaller of Psafe and global actual pstate
                // minPstate = min(Psafe,global actual pstate)
                pcbs_val_init.MIN_PSTATE =   pcbs_val_init.PSAFE < pcbs_val_init.GLOBAL_ACTUAL_PSTATE  ?  pcbs_val_init.PSAFE : pcbs_val_init.GLOBAL_ACTUAL_PSTATE ;

                //if (VERBOSE) {
                      FAPI_DBG("\t PSAFE => %d ", pcbs_val_init.PSAFE );
                      FAPI_DBG("\t GLOBAL_ACTUAL_PSTATE => %d ", pcbs_val_init.GLOBAL_ACTUAL_PSTATE );
                      FAPI_DBG("\t => MIN_PSTATE => %x ", pcbs_val_init.MIN_PSTATE );
                //}

                //set dpll_fmin = fnom + minPstate(signed)
                ///  \todo double check dpll_fmin  not dpll_min
                pcbs_val_init.DPLL_FMIN =  pcbs_val_init.FNOM +  pcbs_val_init.MIN_PSTATE ;

                //if (VERBOSE) {
                  FAPI_DBG("\t DPLL_FMIN = FNOM + MIN_PSTATE " );
                  FAPI_DBG("\t DPLL_FMIN => %d ", pcbs_val_init.DPLL_FMIN );
                //}
                
                FAPI_DBG("*************************************");
                FAPI_INF(" End calculation of DPLL fmin ....");
                FAPI_DBG("*************************************");
                
                
                // Write calculated values to FREQ_CTRL_REG
                rc = fapiGetScom( i_target,EX_FREQCNTL_0x100F0151 + (l_ex_number * 0x01000000) , data );
                if (rc) { FAPI_ERR("fapiGetScom(FREQ_CTRL_REG) failed. With rc = 0x%x", (uint32_t)rc);  return rc;    }
                
                //if (VERBOSE) { 
                  FAPI_DBG(" Pre write content of FREQ_CTRL_REG_0x1*0F0151 :  %016llX", data.getDoubleWord(0));
                //}
                
                // Clear buffer
                l_rc = data.flushTo0(); 
                l_rc |= data.setByte(0, pcbs_val_init.DPLL_FMIN);
                l_rc |= data.setByte(1, pcbs_val_init.DPLL_FMAX);
                if (l_rc) { FAPI_ERR("Bit operation failed. With rc = 0x%x", (uint32_t)l_rc);  rc.setEcmdError(l_rc); return rc;    }

                rc = fapiPutScom(i_target, EX_FREQCNTL_0x100F0151  + (l_ex_number * 0x01000000), data );
                if (rc) { FAPI_ERR("fapiGetScom(FREQ_CTRL_REG) failed. With rc = 0x%x", (uint32_t)rc);  return rc;    }

                // if debug mode read back
                //if (VERBOSE) {
                //  rc = fapiGetScom(i_target, EX_FREQCNTL_0x100F0151  + (l_ex_number * 0x01000000), data); if (l_rc) return rc;
                //  FAPI_DBG(" Post write content of FREQ_CTRL_REG_0x1*0F0151  :  %016llX", data.getDoubleWord(0));
                //}

                FAPI_INF("DPLL fmin = %d , DPLL fmax = %d set", pcbs_val_init.DPLL_FMIN, pcbs_val_init.DPLL_FMAX);



                
                
                //  ******************************************************************
                //   OCC SPR Mode
                //  ******************************************************************
                //  ******************************************************************
                //  - set PCBS_PM_PMGP1_REG_1
                //              [11] PM_SPR_OVERRIDE_EN = 1
                //      
                //  ******************************************************************
                
                FAPI_DBG("********* ******************* *********");
                FAPI_INF("Force PM_SPR_OVERRIDE");
                FAPI_DBG("********* ******************* *********");
                
                // Using Write OR to just set bit11 and bit12
                // Clear buffer          
                l_rc = data.flushTo0();  
                if (l_rc) { FAPI_ERR("Bit operation failed. With rc = 0x%x", (uint32_t)l_rc);  rc.setEcmdError(l_rc); return rc;    }
                
                // set scan0 value
                // scan0: 6C00  content after iStep: 4800
                // bit2: 0: Vret (fast sleep)
                //       1: Voff (deep sleep)
                // bit5: 0: Vret (fast winkle)
                //       1: Voff (deep winkle)
                /// \todo   Review if scan0 values can/should be applied 
                //l_rc = data.setDoubleWord(0, PMGP1_REG_0x100F0103_scan0);           
                //if (l_rc) { FAPI_ERR("Bit operation failed."); return rc; }
                
                l_rc = data.setBit(11);    //Force OCC SPR Mode = 1        
                if (l_rc) { FAPI_ERR("Bit operation failed. With rc = 0x%x", (uint32_t)l_rc);  rc.setEcmdError(l_rc); return rc;    }
                
                // simaet( "on" );        
                rc = fapiPutScom(i_target, EX_WRITE_ALL_EX_PMGP1_REG_0_WORx690F0105, data );
                if (rc) { FAPI_ERR("fapiPutScom multicast (EX_WRITE_ALL_EX_PMGP1_REG_0_WORx690F0105) failed. With rc = 0x%x", (uint32_t)rc);  return rc;    }                   
              
                
                //if (VERBOSE) { 
                  FAPI_DBG("********* ******************* *********");
                  FAPI_DBG("Multicasted to EX_WRITE_ALL_EX_PMGP1_REG_0_WORx690F0105  :  %016llX",  data.getDoubleWord(0));
                  FAPI_DBG("********* ******************* *********");
                //}
                
                
                // manual debug       
                // getscom p8 -k0 -n0 -s0 -p00 130F0103  -ixl
                // returns the expected values0x4818000000000000
                
                //rc = fapiGetScom(i_target, 0x130F0103, data); if (l_rc) return rc;
                //FAPI_DBG("XXXXXX Content of 0x130F0103 is :  %016llX", data.getDoubleWord(0));                            
                
                
                // if debug mode read back
                //if (VERBOSE) {                      
                //  if (chiplets_valid[c] == 1) {
                //    rc = fapiGetScom(i_target, EX_PMGP1_REG_0_RWXx100F0103  + (l_ex_number * 0x01000000), data); if (l_rc) return rc;
                //    FAPI_DBG("Content of PMGP1_REG_0_RWXx1*0F0103 is :  %s  ,  Loop: %016llX ", data.getDoubleWord(0) , c); 
                //    
                //    //rc = fapiGetScom(i_target, 0x130F0103, data); if (l_rc) return rc;
                //    //FAPI_DBG(" XXX2 Content of 0x130F0103 is :  %016llX", data.getDoubleWord(0));                            
                //  }                          
                //}
                
                FAPI_INF("Forced  OCC SPR Mode");                    
                
                
                
                
                //  ******************************************************************
                //  - Disable Pstate mode
                //  - disable Pstate requests
                //  ******************************************************************
                FAPI_DBG("********* ******************* *********");
                FAPI_INF("Disable Pstate mode and disable Pstate requests");
                FAPI_DBG("********* ******************* *********");
                
                //EX_PCBSPM_MODE_REG_0x100F0156_scan0
                /// \todo DoubleCheck: No OR-write available, using scan0 values as base and clearing bit 0 and bit 2
                l_rc = data.setWord(0, EX_PCBSPM_MODE_REG_0x100F0156_scan0);
                if (l_rc) { FAPI_ERR("Bit operation failed. With rc = 0x%x", (uint32_t)l_rc);  rc.setEcmdError(l_rc); return rc;    }
                l_rc = data.clearBit(0);       //Disable Pstate mode 
                if (l_rc) { FAPI_ERR("Bit operation failed. With rc = 0x%x", (uint32_t)l_rc);  rc.setEcmdError(l_rc); return rc;    }
                l_rc = data.clearBit(2);       //Disable Pstate requests
                if (l_rc) { FAPI_ERR("Bit operation failed. With rc = 0x%x", (uint32_t)l_rc);  rc.setEcmdError(l_rc); return rc;    }
                
                
                
                rc = fapiPutScom(i_target, EX_WRITE_ALL_PCBSPM_MODE_REG_0x690F0156, data );
                if (rc) { FAPI_ERR("fapiGetScom(EX_WRITE_ALL_PCBSPM_MODE_REG_0x690F0156) failed. With rc = 0x%x", (uint32_t)rc);  return rc;    }
                
                FAPI_DBG("Multicasted to EX_WRITE_ALL_PCBSPM_MODE_REG_0x690F0156 is :  %016llX", data.getDoubleWord(0));
                
                // if debug mode read back
                //if (VERBOSE) {                    
                //    if (chiplets_valid[c] == 1) {            
                //      rc = fapiGetScom(i_target, EX_PCBSPM_MODE_REG_0x100F0156  + (l_ex_number * 0x01000000), data); if (l_rc) return rc;
                //      FAPI_DBG(" Content of PCBSPM_MODE_REG_0x1*0F0156  :  %016llX", data.getDoubleWord(0));
                //    }                          
                //}
                FAPI_INF("Disabled Pstate mode");
                
                // simaet( "off" );          
                
                //  ******************************************************************
                //  - Reset Pmin and Pmax
                //  ******************************************************************          
                FAPI_DBG("********* ******************* *********");
                FAPI_INF("Reset Pmin and Pmax");
                FAPI_DBG("********* ******************* *********");
                // Clear data buffer
                l_rc = data.flushTo0();
                if (l_rc) { FAPI_ERR("Bit operation failed. With rc = 0x%x", (uint32_t)l_rc);  rc.setEcmdError(l_rc); return rc;    }
                
                // Set scan0 values
                l_rc = data.setWord(0, EX_PCBS_Power_Management_Bounds_Reg_0x100F015D_scan0);
                if (l_rc) { FAPI_ERR("Bit operation failed. With rc = 0x%x", (uint32_t)l_rc);  rc.setEcmdError(l_rc); return rc;    }
                //
                l_rc = data.setByte(0, pcbs_val_init.PMIN_CLIP);   //Pmin_clip   =  -128
                if (l_rc) { FAPI_ERR("Bit operation failed. With rc = 0x%x", (uint32_t)l_rc);  rc.setEcmdError(l_rc); return rc;    }
                l_rc = data.setByte(1, pcbs_val_init.PMAX_CLIP);   //Pmax_clip   =   127
                if (l_rc) { FAPI_ERR("Bit operation failed. With rc = 0x%x", (uint32_t)l_rc);  rc.setEcmdError(l_rc); return rc;    }
                
                rc = fapiPutScom(i_target, EX_WRITE_ALL_PCBS_Power_Management_Bounds_Reg_0x690F015D, data );
                if (rc) { FAPI_ERR("fapiGetScom(PCBS_Power_Management_Bounds_Reg) failed. With rc = 0x%x", (uint32_t)rc);  return rc;    }
                FAPI_DBG("Multicasted to PCBS_Power_Management_Bounds_Reg is :  %016llX", data.getDoubleWord(0));               
                
                // if debug mode read back
                //if (VERBOSE) {
                //    if (chiplets_valid[c] == 1) {            
                //      rc = fapiGetScom(i_target, EX_PCBS_Power_Management_Bounds_Reg_0x100F015D  + (l_ex_number * 0x01000000) , data); if (l_rc) return rc;
                //      FAPI_DBG("Content of PCBS_Power_Management_Bounds_Reg_0x1*0F015D :  %016llX", data.getDoubleWord(0));
                //    }                          
                //}
                FAPI_INF("\t Pmin_clip => %d and Pmax_clip  => %d ",pcbs_val_init.PMIN_CLIP,pcbs_val_init.PMAX_CLIP);
                
                
                
                
                

                //  ******************************************************************
                //  Settings
                //  ******************************************************************
                //  ******************************************************************
    
                //  - disable RESCLK
                //  - OCC Heartbeat disable
                //  ******************************************************************
                FAPI_DBG("**************************** *********");
                FAPI_INF("Settings about RESCLK");
                FAPI_DBG("**************************** *********");

                // if debug mode read before
                //if (VERBOSE) {
                //  rc = fapiGetScom(i_target, EX_GP3_0x100F0012 + (l_ex_number * 0x01000000) , data); if (l_rc) return rc;
                //  FAPI_DBG(" Pre write content of GP3_REG_0_RWXx1*0F0012 , Loop: %d :  %016llX", c, data.getDoubleWord(0) );
                //}       
  
                ///  \todo : Double Check:  Bit modifications in GP3... anything to take care here??
                // Using Write OR to just set bit22
                // Clear buffer
                l_rc = data.flushTo0();
                if (l_rc) { FAPI_ERR("Bit operation failed. With rc = 0x%x", (uint32_t)l_rc);  rc.setEcmdError(l_rc); return rc;    }

                l_rc = data.setBit(22);     //disable RESCLK
                if (l_rc) { FAPI_ERR("Bit operation failed. With rc = 0x%x", (uint32_t)l_rc);  rc.setEcmdError(l_rc); return rc;    }


                rc = fapiPutScom(i_target, EX_GP3_OR_0x100F0014 + (l_ex_number * 0x01000000), data );
                if (rc) { FAPI_ERR("fapiGetScom Content of GP3_REG_0_WORx1*0F0014, Loop: %d  failed. With rc = 0x%x", c,  (uint32_t)rc);  return rc;    }

                // if debug mode read back
                //if (VERBOSE) {
                //  rc = fapiGetScom(i_target, EX_GP3_0x100F0012 + (l_ex_number * 0x01000000) , data); if (l_rc) return rc;
                //  FAPI_DBG(" Post write content of GP3_REG_0_RWXx1*0F0012 , Loop: %d :  %016llX", c, data.getDoubleWord(0) );
                //}
                FAPI_INF ("Disabled RESCLK, set bit 22 of GP3_REG_0_RWXx1*0F0012 " );



                //OCC Heartbeat disable
                rc = fapiGetScom( i_target, EX_PCBS_OCC_Heartbeat_Reg_0x100F0164 + (l_ex_number * 0x01000000) , data );
                if (rc) { FAPI_ERR("fapiGetScom(PCBS_OCC_HEARTBEAT_REG) failed. With rc = 0x%x", (uint32_t)rc);  return rc;    }
                
                //if (VERBOSE) {
                  FAPI_DBG(" Pre write content of PCBS_OCC_HEARTBEAT_REG_0x1*0F0164  :  %016llX", data.getDoubleWord(0));
                //}    
                
                l_rc = data.clearBit(8);     //OCC Heartbeat disable
                if (l_rc) { FAPI_ERR("Bit operation failed. With rc = 0x%x", (uint32_t)l_rc);  rc.setEcmdError(l_rc); return rc;    }
                
                

                rc = fapiPutScom(i_target,  EX_PCBS_OCC_Heartbeat_Reg_0x100F0164  + (l_ex_number * 0x01000000), data );
                if (rc) { FAPI_ERR("fapiGetScom(PCBS_OCC_HEARTBEAT_REG) failed. With rc = 0x%x", (uint32_t)rc);  return rc;    }

                // if debug mode read back
                //if (VERBOSE) {
                //  rc = fapiGetScom(i_target, EX_PCBS_OCC_Heartbeat_Reg_0x100F0164  + (l_ex_number * 0x01000000), data); if (l_rc) return rc;
                //  FAPI_DBG(" Post write content of PCBS_OCC_HEARTBEAT_REG_0x1*0F0164  :  %016llX", data.getDoubleWord(0));
                //}
                FAPI_INF ("OCC Heartbeat disabled, cleared bit 8 of PCBS_OCC_HEARTBEAT_REG_0x1*0F0164" );




                //  ******************************************************************
                //  IVRM Setup
                //  ******************************************************************
                //  ******************************************************************
                //  - if Venice ( ivrms_enabled)
                //  	- disable ivrms
                //  	- set bypass mode
                //  - reset undervolting values
                //  - disable LPFT
                //  ******************************************************************
                FAPI_DBG("**************************** *********");
                FAPI_INF("IVRM Setup");
                FAPI_DBG("**************************** *********");

                if (pcbs_val_init.ivrms_enabled)  {    // If Venice

                      //
                      rc = fapiGetScom( i_target, EX_PCBS_iVRM_Control_Status_Reg_0x100F0154 + (l_ex_number * 0x01000000) , data );
                      if (rc) { FAPI_ERR("fapiGetScom(PCBS_iVRM_Control_Status_Reg) failed. With rc = 0x%x", (uint32_t)rc);  return rc;    }
                      //if (VERBOSE) {
                        FAPI_DBG(" Pre write content of PCBS_iVRM_Control_Status_Reg_0x1*0F0154  :  %016llX", data.getDoubleWord(0));
                      //}
                      
                      l_rc = data.clearBit(0);      //disable ivrms
                      if (l_rc) { FAPI_ERR("Bit operation failed. With rc = 0x%x", (uint32_t)l_rc);  rc.setEcmdError(l_rc); return rc;    }
                      l_rc = data.clearBit(4);      //ivrm_core_vdd_bypass_b
                      if (l_rc) { FAPI_ERR("Bit operation failed. With rc = 0x%x", (uint32_t)l_rc);  rc.setEcmdError(l_rc); return rc;    }
                      l_rc = data.clearBit(6);      //ivrm_core_vcs_bypass_b
                      if (l_rc) { FAPI_ERR("Bit operation failed. With rc = 0x%x", (uint32_t)l_rc);  rc.setEcmdError(l_rc); return rc;    }
                      l_rc = data.clearBit(8);      //ivrm_eco_vdd_bypass_b
                      if (l_rc) { FAPI_ERR("Bit operation failed. With rc = 0x%x", (uint32_t)l_rc);  rc.setEcmdError(l_rc); return rc;    }
                      l_rc = data.clearBit(10);     //ivrm_eco_vcs_bypass_b
                      if (l_rc) { FAPI_ERR("Bit operation failed. With rc = 0x%x", (uint32_t)l_rc);  rc.setEcmdError(l_rc); return rc;    }


                      rc = fapiPutScom(i_target, EX_PCBS_iVRM_Control_Status_Reg_0x100F0154   + (l_ex_number * 0x01000000), data );
                      if (rc) { FAPI_ERR("fapiGetScom(PCBS_iVRM_Control_Status_Reg) failed. With rc = 0x%x", (uint32_t)rc);  return rc;    }
                      // Write twice since  ivrm_fsm_enable have to be 0 to enable the set the bypass modes
                      rc = fapiPutScom(i_target, EX_PCBS_iVRM_Control_Status_Reg_0x100F0154   + (l_ex_number * 0x01000000), data );
                      if (rc) { FAPI_ERR("fapiGetScom(PCBS_iVRM_Control_Status_Reg) failed. With rc = 0x%x", (uint32_t)rc);  return rc;    }

                      // if debug mode read back
                      //if (VERBOSE) {
                      //  rc = fapiGetScom(i_target, EX_PCBS_iVRM_Control_Status_Reg_0x100F0154  + (l_ex_number * 0x01000000), data); if (l_rc) return rc;
                      //  FAPI_DBG(" Post write content of PCBS_iVRM_Control_Status_Reg_0x1*0F0154  :  %016llX", data.getDoubleWord(0));
                      //}
                      FAPI_INF ("This is Venice: iVRMs disabled and in bypass-mode" );


                };



                //
                rc = fapiGetScom( i_target, EX_PCBS_UNDERVOLTING_REG_0x100F015B + (l_ex_number * 0x01000000) , data );
                if (rc) { FAPI_ERR("fapiGetScom(PCBS_UNDERVOLTING_REG) failed. With rc = 0x%x", (uint32_t)rc);  return rc;    }
                    // debug: data.flushTo1();
                //if (VERBOSE) {
                  FAPI_DBG(" Pre write content of PCBS_UNDERVOLTING_REG_0x1*0F015B  :  %016llX", data.getDoubleWord(0));
                //}
                ///  \todo : Double check this bit settings  
                l_rc = data.setByte(2, pcbs_val_init.KUV);       //Kuv       =  0
                if (l_rc) { FAPI_ERR("Bit operation failed. With rc = 0x%x", (uint32_t)l_rc);  rc.setEcmdError(l_rc); return rc;    }
                l_rc = data.shiftLeft(2);          //Kuv is 6bit
                if (l_rc) { FAPI_ERR("Bit operation failed. With rc = 0x%x", (uint32_t)l_rc);  rc.setEcmdError(l_rc); return rc;    }
                l_rc = data.setByte(0, pcbs_val_init.PUV_MIN);   //Puv_min   =  -128
                if (l_rc) { FAPI_ERR("Bit operation failed. With rc = 0x%x", (uint32_t)l_rc);  rc.setEcmdError(l_rc); return rc;    }
                l_rc = data.setByte(1, pcbs_val_init.PUV_MAX);   //Puv_max   =  -128
                if (l_rc) { FAPI_ERR("Bit operation failed. With rc = 0x%x", (uint32_t)l_rc);  rc.setEcmdError(l_rc); return rc;    }

                rc = fapiPutScom(i_target, EX_PCBS_UNDERVOLTING_REG_0x100F015B   + (l_ex_number * 0x01000000), data );
                if (rc) { FAPI_ERR("fapiGetScom(PCBS_UNDERVOLTING_REG) failed. With rc = 0x%x", (uint32_t)rc);  return rc;    }

                // if debug mode read back
                //if (VERBOSE) {                    
                  FAPI_DBG("\t PUV_MIN => %d ", pcbs_val_init.PUV_MIN );
                  FAPI_DBG("\t PUV_MAX => %d ", pcbs_val_init.PUV_MAX );
                  FAPI_DBG("\t KUV => %d ", pcbs_val_init.KUV );                 
                  
                  //rc = fapiGetScom(i_target, EX_PCBS_UNDERVOLTING_REG_0x100F015B  + (l_ex_number * 0x01000000), data); if (l_rc) return rc;
                  //FAPI_DBG(" Post write content of PCBS_UNDERVOLTING_REG_0x1*0F015B  :  %016llX", data.getDoubleWord(0));
                //}
                FAPI_INF ("Undervolting values reset done" );

                ///  \todo : Debug Register access problems PCBS_LPFT_Control_Register_Reg0  . Already fixed in TPC-LIB chiplevel 8053
                ///  \todo : Uncomment the following lines
                //
                //              rc = fapiGetScom( i_target, EX_PCBS_Local_Pstate_Frequency_Target_Control_Register_0x100F0168 + (l_ex_number * 0x01000000) , data );
                //              if (l_rc) { FAPI_ERR("fapiGetScom(PCBS_LPFT_Control_Register_Reg0) failed. With rc = 0x%x", (uint32_t)rc);  return rc;    }

                //              data.clearBit(20);     //Local Pstate Frequency Target mechanism disabled

                //              rc = fapiPutScom(i_target,  EX_PCBS_Local_Pstate_Frequency_Target_Control_Register_0x100F0168  + (l_ex_number * 0x01000000), data );
                //              if (l_rc) { FAPI_ERR("fapiPutScom(PCBS_LPFT_Control_Register_Reg0) failed. With rc = 0x%x", (uint32_t)rc);  return rc;    }

                              // if debug mode read back
                //              if (VERBOSE) {
                //                 rc = fapiGetScom(i_target, EX_PCBS_Local_Pstate_Frequency_Target_Control_Register_0x100F0168  + (l_ex_number * 0x01000000), data); if (l_rc) return rc;
                //                 FAPI_DBG(" Content of EX_PCBS_Local_Pstate_Frequency_Target_Control_Register_0x100F0168  :  %016llX", data.getDoubleWord(0));
                //              }
                //              FAPI_INF ("Local Pstate Frequency Target mechanism disabled" );


                //  ******************************************************************
                //  Issue reset to PCBS-PM
                //  ******************************************************************
                FAPI_DBG("**************************** *********");
                FAPI_INF("Reset PCBS-PM");
                FAPI_DBG("**************************** *********");

                //
                //rc = fapiGetScom( i_target,PMGP1_REG_0x100F00103 + (l_ex_number * 0x01000000) , data ); if (l_rc) return rc;
                //if (l_rc) { FAPI_ERR("fapiGetScom(PMGP1_REG_0x100F00103) failed."); return rc; }
                /// \todo : Double Check:  Is that the right way to set and unset the reset or keep the reset longer and then unset it at the end ?              
                //if (VERBOSE) {
                //  rc = fapiGetScom(i_target, EX_PMGP1_REG_0_RWXx100F0103  + (l_ex_number * 0x01000000), data); if (l_rc) return rc;
                //  FAPI_DBG(" Pre write content of PMGP1_REG_0_RWXx1*0F0103  :  %016llX", data.getDoubleWord(0));
                //}
                
                l_rc = data.flushTo0();
                if (l_rc) { FAPI_ERR("Bit operation failed. With rc = 0x%x", (uint32_t)l_rc);  rc.setEcmdError(l_rc); return rc;    }

                l_rc = data.setBit(9);     //endp_reset_pm_only  = 1
                if (l_rc) { FAPI_ERR("Bit operation failed. With rc = 0x%x", (uint32_t)l_rc);  rc.setEcmdError(l_rc); return rc;    }

                rc = fapiPutScom(i_target, EX_PMGP1_REG_0_WORx100F0105  + (l_ex_number * 0x01000000), data );
                if (rc) { FAPI_ERR("fapiGetScom(PMGP1_REG_0_WORx1*0F0105) failed. With rc = 0x%x", (uint32_t)rc);  return rc;    }
                /// \todo : Double check if RESET is effective
                // if debug mode read back
                //if (VERBOSE) {
                //  rc = fapiGetScom(i_target, EX_PMGP1_REG_0_RWXx100F0103  + (l_ex_number * 0x01000000), data); if (l_rc) return rc;
                //  FAPI_DBG(" Post (set reset) write content of PMGP1_REG_0_RWXx1*0F0103  :  %016llX", data.getDoubleWord(0));
                //}
                FAPI_INF("Set reset to PCBS-PM");

                l_rc = data.flushTo1();
                if (l_rc) { FAPI_ERR("Bit operation failed. With rc = 0x%x", (uint32_t)l_rc);  rc.setEcmdError(l_rc); return rc;    }

                l_rc = data.clearBit(9);   //endp_reset_pm_only  = 0
                if (l_rc) { FAPI_ERR("Bit operation failed. With rc = 0x%x", (uint32_t)l_rc);  rc.setEcmdError(l_rc); return rc;    }

                rc = fapiPutScom(i_target, EX_PMGP1_REG_0_WANDx100F0104  + (l_ex_number * 0x01000000), data );
                if (rc) { FAPI_ERR("fapiGetScom(EX_PMGP1_REG_0_WANDx100F0104) failed. With rc = 0x%x", (uint32_t)l_rc);  return rc;    }

                // if debug mode read back
                //if (VERBOSE) {
                //  rc = fapiGetScom(i_target, EX_PMGP1_REG_0_RWXx100F0103  + (l_ex_number * 0x01000000), data); if (l_rc) return rc;
                //  FAPI_DBG(" Post (unset reset) content of EX_PMGP1_REG_0_RWXx100F0103  :  %016llX", data.getDoubleWord(0));
                //}
                FAPI_INF("Unset reset to PCBS-PM");


                
                
    
                
          } //ELSE IF functional and ATTR_CHIP_UNIT_POS
        }  else  
        {
          // EX is not functional
          FAPI_DBG("Core number = %d  is not functional", c);
        }  //IF functional    
      }//ELSE IF ATTR_FUNCTIONAL 
          
    }  //END FOR





 



   FAPI_INF("");
   FAPI_INF("Executing p8_pcbs_init  ....\n");


  return rc;
}   // end RESET








} //end extern C

