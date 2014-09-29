/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/utility_procedures/p8_inst_pm_state.C $      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014                             */
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
//$Id: p8_inst_pm_state.C,v 1.15 2014/08/05 18:26:15 jmcgill Exp $
//$Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/utils/p8_inst_pm_state.C,v $
//------------------------------------------------------------------------------
// *|
// *! (C) Copyright International Business Machines Corp. 2014
// *! All Rights Reserved -- Property of IBM
/*
 * @owner:  Michael Olsen       Email: cmolsen@us.ibm.com
 *
 * @file    p8_inst_pm_state.C
 * @brief   Calculates the instantaneous PM state (IPMS)
 * 
 */
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include "p8_inst_pm_state.H"
#include <p8_scom_addresses.H>
//#include <p8_scom_errors.H>  // PIB slave unit error codes


extern "C"
{


//------------------------------------------------------------------------------
// @proc_name  ex_determine_inst_pm_state()
//------------------------------------------------------------------------------
// @brief Determine the Instantaneous PM State (IPMS) from PCBS FSM, PMC SV and PM HIST.
//
// @param[in]  i_ex_target          the EX chiplet target
// @param[in]  i_pm_settle_usec     the time to give the PM system to stabilize [usec]
// @param[in]  i_pm_polls           the number of times to poll the PM states
// @param[out] o_inst_pm_state      the returned instantaneous pm state
//
// @return ReturnCode   FAPI_RC_SUCCESS, platform error or FFDC specified error
//
//------------------------------------------------------------------------------
fapi::ReturnCode  ex_determine_inst_pm_state( const fapi::Target &i_ex_target,
                                              uint32_t  i_pm_settle_usec,
                                              uint32_t  i_pm_polls,
                                              uint8_t   &o_inst_pm_state)
{
    fapi::ReturnCode    rc, rc_eco;     //fapi return code value
    uint32_t            rc_ecmd=0;      //ecmd return code value
    fapi::Target        l_parentTarget;

    ecmdDataBufferBase  data(64);
    ecmdDataBufferBase  dataETR(64);
    ecmdDataBufferBase  dataPORRR0(64), dataPORRR1(64);
    ecmdDataBufferBase  dataPIRR0(64),dataPIRR1(64),dataPIRR2(64),dataPIRR3(64);
    ecmdDataBufferBase  dataPMGP1(64);
    ecmdDataBufferBase  dataSTATUS(64),dataDEBUG0(64),dataDEBUG1(64),dataPMCLFIR(64);
    
    uint64_t            address=0x0;
    uint64_t            address_oha_status=0x0;
    uint8_t             ex_number=0xff;

    uint32_t            pcbs_fsm=0xff, pcbs_fsm_prev=0xff;
    uint32_t            trans_sv=0xff, trans_sv_etr=0xff;
    uint32_t            slw_chiplet_vec=0xff, slw_chiplet_vec_etr=0xff;
    uint32_t            pmhist_state=0xff;
    uint32_t            aiss_fsm=0xff;
    uint32_t            pmc_queue_state=0xff;

    uint32_t            iFsmPoll=0;
    uint64_t            fsm_poll_interval_nsec=0;
    
    bool                bPmcIsStuck=false;  // False until we determine PM state regs unstable
    bool                bGoodState=true;    // True until condition found deeming this False
    bool                bStateFound=false;  // False until we have found valid IPMS state
    
    FAPI_INF("Determining the Instantaneous PM State (IPMS)");

    o_inst_pm_state = INST_PM_STATE_UNDEFINED;

    do
    {
    
        // Get the parent chip to target non-EX registers
        rc = fapiGetParentChip( i_ex_target, l_parentTarget);
        if (rc)
        {
            FAPI_ERR("fapiGetParentChip failed w/rc = 0x%x", (uint32_t)rc);
            return rc;
        }

        // Get the core number
        rc = FAPI_ATTR_GET( ATTR_CHIP_UNIT_POS, &i_ex_target, ex_number);
        if (rc)
        {
            FAPI_ERR("fapiGetAttribute(ATTR_CHIP_UNIT_POS) failed w/rc = 0x%x", (uint32_t)rc);
            return rc;
        }

        FAPI_INF("  Processing core number = %d", ex_number);

        // Just in case the state machines are still moving or to accomodate FSM 
        //    transaction lags, let's monitor the ETR and PCBS for about 25ms.
        //

        // Extract the PCB-slave FSM state. (Initial snapshot)
        //
        address = EX_PCBS_FSM_MONITOR2_REG_0x100F0171;
        rc = fapiGetScom( i_ex_target, address, data);
        if (rc)
        {
            FAPI_ERR("fapiGetScom error (addr: 0x%08llX)", address);
            return rc;
        }
        rc_ecmd = data.extractToRight(&pcbs_fsm, 23, 7);
        if (rc_ecmd)
        {
            rc.setEcmdError(rc_ecmd);
            return rc;
        }
        pcbs_fsm_prev = pcbs_fsm;

        if (i_pm_polls == 0)  // Can't allow zero denominator.
            i_pm_polls = 1;
        fsm_poll_interval_nsec = i_pm_settle_usec * 1000 / i_pm_polls;
        
        // Start monitoring the PM states
        for (iFsmPoll=0; iFsmPoll<i_pm_polls; iFsmPoll++)
        {
            
            //FAPI_INF("\tiFsmPoll=%d",iFsmPoll);
            // Extract the PMC (PORRR0) start_vector.
            //
            address = PMC_PORRR0_REG_0x0006208E;
            rc = fapiGetScom( l_parentTarget, address, dataPORRR0);
            if (rc)
            {
                FAPI_ERR("fapiGetScom error (addr: 0x%08llX)", address);
                return rc;
            }
            rc_ecmd = dataPORRR0.extractToRight(&trans_sv, 8, 4);
            if (rc_ecmd)
            {
                rc.setEcmdError(rc_ecmd);
                return rc;
            }
        
            // Extract the SLW (PORRR1) chiplet vector
            //
            address = PMC_PORRR1_REG_0x0006208F;
            rc = fapiGetScom( l_parentTarget, address, dataPORRR1);
            if (rc)
            {
                FAPI_ERR("fapiGetScom error (addr: 0x%08llX)", address);
                return rc;
            }
            rc_ecmd = dataPORRR1.extractToRight(&slw_chiplet_vec, 0, 16);
            if (rc_ecmd)
            {
                rc.setEcmdError(rc_ecmd);
                return rc;
            }
            slw_chiplet_vec = slw_chiplet_vec<<16;
            
            // Delay before looking at PCBS FSM again and ETR.
            //
            rc = fapiDelay( fsm_poll_interval_nsec, 100000);
            if (rc)
            {
                FAPI_ERR("fapiDelay() error");
                return rc;
            }
                
            // Extract the start_vector and the chiplet vector from the ETR and
            //   double check against content of PMC's PORRR0 and PORRR1.
            //
            address = PORE_SLW_EXE_TRIGGER_0x00068009;
            rc = fapiGetScom( l_parentTarget, address, dataETR);
            if (rc)
            {
                FAPI_ERR("fapiGetScom error (addr: 0x%08llX)", address);
                return rc;
            }
            rc_ecmd = dataETR.extractToRight(&trans_sv_etr, 8, 4);
            if (rc_ecmd)
            {
                rc.setEcmdError(rc_ecmd);
                return rc;
            }
            rc_ecmd = dataETR.extractToRight(&slw_chiplet_vec_etr, 32, 16);
            if (rc_ecmd)
            {
                rc.setEcmdError(rc_ecmd);
                return rc;
            }
            slw_chiplet_vec_etr = slw_chiplet_vec_etr<<16;
            
            // Extract the PCB-slave FSM state.
            //
            address = EX_PCBS_FSM_MONITOR2_REG_0x100F0171;
            rc = fapiGetScom( i_ex_target, address, data);
            if (rc)
            {
                FAPI_ERR("fapiGetScom error (addr: 0x%08llX)", address);
                return rc;
            }
            rc_ecmd = data.extractToRight(&pcbs_fsm, 23, 7);
            if (rc_ecmd)
            {
                rc.setEcmdError(rc_ecmd);
                return rc;
            }

            // Compare now
            if ( pcbs_fsm!=pcbs_fsm_prev                                         ||
                 ( slw_chiplet_vec!=0                                              &&
                   ( (slw_chiplet_vec & ((uint32_t)0x80000000>>ex_number))           ||
                     (slw_chiplet_vec_etr & ((uint32_t)0x80000000>>ex_number)) )   &&
                   ( trans_sv!=trans_sv_etr || slw_chiplet_vec!=slw_chiplet_vec_etr ) ) )
            {
                FAPI_INF("  PORRR register, ETR or PCBS FSM seem to be unstable (@iFsmPoll=%d):",iFsmPoll);
                FAPI_INF("    Core:     0x%x", ex_number);
                FAPI_INF("    PORRR0:   0x%016llx",dataPORRR0.getDoubleWord(0));
                FAPI_INF("    PORRR1:   0x%016llx",dataPORRR1.getDoubleWord(0));
                FAPI_INF("    ETR:      0x%016llx",dataETR.getDoubleWord(0));
                FAPI_INF("    PCBS-FSM (prev): 0x%x",pcbs_fsm_prev);
                FAPI_INF("    PCBS-FSM (new):  0x%x",pcbs_fsm);
            }
            else if (iFsmPoll==(i_pm_polls-1))
            {
                FAPI_INF("  PORRR register, ETR or PCBS FSM seem stable at last poll (@iFsmPoll=%d):",iFsmPoll);
                FAPI_INF("    Core:     0x%x", ex_number);
                FAPI_INF("    PORRR0:   0x%016llx",dataPORRR0.getDoubleWord(0));
                FAPI_INF("    PORRR1:   0x%016llx",dataPORRR1.getDoubleWord(0));
                FAPI_INF("    ETR:      0x%016llx",dataETR.getDoubleWord(0));
                FAPI_INF("    PCBS-FSM (prev): 0x%x",pcbs_fsm_prev);
                FAPI_INF("    PCBS-FSM (new):  0x%x",pcbs_fsm);
            }
            
            pcbs_fsm_prev = pcbs_fsm;
            
        } // End of for(iFsmPoll) 
        // End of monitoring the PM states

        // Deal with any unstable situation up front, but only those that relate to the current EX chiplet
        // since the trans_sv can only be used to determine IPMS if it's related to the current EX chiplet.
        // (Note, we can have an unstable situation where the PMC is stuck but with a request from another
        //  EX chiplet. But we'll deal with that when that other EX chiplet is/was the current EX chiplet.)
        //
        bPmcIsStuck = false;
        if ( trans_sv!=trans_sv_etr && (slw_chiplet_vec & ((uint32_t)0x80000000>>ex_number)) )
        {
            // This strongly suggests that we're stuck in the PMC. I.e., the PMC
            // has arbitrated a request to the PORE but the PORE hasn't accepted
            // it. In such a case, the PORE's ETR content will contain the most
            // recently processed SV request but the PORRR0 will contain the new 
            // SV request. Note that the request, in principle, could be from the 
            // same chiplet. But there's no way the same chiplet would request 
            // the same idle transition which is why we only compare trans_svs.
            FAPI_INF("  PMC is stuck - Request has been arbitrated but PORE isn't processing it");
            bPmcIsStuck = true;
         }

        // Extract the PM HIST state.
        //
        address = EX_PMSTATEHISTPHYP_REG_0x100F0110;
        rc = fapiGetScom( i_ex_target, address, data);
        if (rc)
        {
            FAPI_ERR("fapiGetScom error (addr: 0x%08llX)", address);
            return rc;
        }
        rc_ecmd = data.extractToRight(&pmhist_state, 0, 3);
        if (rc_ecmd)
        {
            rc.setEcmdError(rc_ecmd);
            return rc;
        }
        
        // Extract the PMC Queue state from the PIRRx registers
        //
        address = PMC_PIRR0_REG_0x00062080 + ex_number/4;
        rc = fapiGetScom( l_parentTarget, address, data);
        if (rc)
        {
            FAPI_ERR("fapiGetScom error (addr: 0x%08llX)", address);
            return rc;
        }
        rc_ecmd = data.extractToRight(&pmc_queue_state, (ex_number-(ex_number/4)*4)*8, 8);
        if (rc_ecmd)
        {
            rc.setEcmdError(rc_ecmd);
            return rc;
        }
        

        // Now we can determine the IPMS state from one of the five cases following below
        //
        bStateFound = false;
        bGoodState = true;
        
        
        // ---------------------------------------------------------------------
        // 0. PMC-stuck window
        //
        //    IPMS = f(trans_sv)  if  "trans_sv != trans_sv_etr
        // ---------------------------------------------------------------------
        // Determine if this is the PMC-stuck window where the PMC has arbitrated
        // a request into the PORRR regs but, for whatever reason, the PORE has
        // not accepted the request and thus the trans_sv_etr contains the most
        // recently handled SV.
        // Even though impossible, lets just make sure there is no queued 
        // request.
        // Note that this state, from a chiplet PM perspective, is identical to 
        // a QUEUED state.
        if (bPmcIsStuck && (pmc_queue_state & 0x80)==0)
        {
            FAPI_INF("  trans_sv=0x%x and trans_sv_etr=0x%x : Using PORRR0 to determine IPMS", trans_sv, trans_sv_etr);
            
            bStateFound = true; // Will get set false of no state found. 
            switch (trans_sv)
            {
                case PORRR_SV_FS_ENTRY :
                    o_inst_pm_state = INST_PM_STATE_QUEUED_FS_ENTRY;
                    break;

                case PORRR_SV_DS_ENTRY :
                    o_inst_pm_state = INST_PM_STATE_QUEUED_DS_ENTRY;
                    break;

                case PORRR_SV_FS_EXIT :
                    o_inst_pm_state = INST_PM_STATE_QUEUED_FS_EXIT;
                    break;

                case PORRR_SV_DS_EXIT :
                    o_inst_pm_state = INST_PM_STATE_QUEUED_DS_EXIT;
                    break;

                case PORRR_SV_FW_ENTRY :
                    o_inst_pm_state = INST_PM_STATE_QUEUED_FW_ENTRY;
                    break;

                case PORRR_SV_DW_ENTRY :
                    o_inst_pm_state = INST_PM_STATE_QUEUED_DW_ENTRY;
                    break;

                case PORRR_SV_FW_EXIT :
                    o_inst_pm_state = INST_PM_STATE_QUEUED_FW_EXIT;
                    break;

                case PORRR_SV_DW_EXIT :
                    o_inst_pm_state = INST_PM_STATE_QUEUED_DW_EXIT;
                    break;

                default :
                    FAPI_ERR("trans_sv=0x%x is an unsupported value", trans_sv);
                    o_inst_pm_state = INST_PM_STATE_UNRESOLVED;
                    const uint64_t & PCBS_FSM = pcbs_fsm;
                    const uint64_t & PMHIST_STATE = pmhist_state;
                    const uint64_t & PMC_QUEUE_STATE = pmc_queue_state;
                    const uint64_t & TRANS_SV = trans_sv;
                    const uint64_t & TRANS_SV_ETR = trans_sv_etr;
                    const fapi::Target & EX_TARGET = i_ex_target;
                    FAPI_SET_HWP_ERROR(rc, RC_IPMS_UNSUPPORTED_SV_VALUE);
                    return rc;
            }
        }

        if (bStateFound || !bGoodState)
            break;

        
        // ---------------------------------------------------------------------
        // 1. OHA-entry window
        //
        //    IPMS = f(aiss_fsm)  if  (pcbs_fsm,pmhist_state) = (IDLE, RUN)
        // ---------------------------------------------------------------------
        // Determine if this is an OHA-entry window case, i.e. before the 
        // PCB-slave  has been pinged by the OHA. If so, #2, #3 and #4 below can 
        // be skipped as it's irrelevant whether the current ex chiplet is, or 
        // was, most recently processed by the SLW engine. Because in both cases
        // the chiplet will be in the RUN state and it will have an idling PCBS. 
        // We need to examine the OHA status reg using these decision rules:
        // - If OHA status is reachable and aiss_fsm==AISS_FSM_IDLE, then we're in RUN.
        // - If OHA status is reachable and aiss_fsm!=AISS_FSM_IDLE, then we're in OHA window.
        // - If OHA status is not reachable and PCB fence is up, then we're in OHA window. (I'm not sure about this one.)
        //
        if ( pcbs_fsm==PCBS_FSM_IDLE &&
             pmhist_state==PMHIST_STATE_RUN )
        {
            FAPI_INF("  pcbs_fsm=0x%x and pmhist_state=0x%x : Using AISS FSM to determine IPMS", pcbs_fsm, pmhist_state);
            
            // determine clock status of OHA region
            uint8_t oha_clk_status = 0x7;
            rc = fapiGetScom( i_ex_target, EX_CLK_STATUS_0x10030008, data);
            if (rc)
            {
                FAPI_ERR("fapiGetScom error (addr: 0x%08llX)", EX_CLK_STATUS_0x10030008);
                return rc;
            }
            rc_ecmd = data.extractToRight(&oha_clk_status, 0, 3);
            if (rc_ecmd)
            {
                rc.setEcmdError(rc_ecmd);
                return rc;
            }

            if (oha_clk_status)
            {
                o_inst_pm_state = INST_PM_STATE_UNDEFINED;
                bStateFound = true;
                break;
            }

            address_oha_status = EX_OHA_RO_STATUS_REG_0x1002000B;
            rc = fapiGetScom( i_ex_target, address_oha_status, data);
            // Reacting to this rc as follows..
            rc_eco = rc;
            
            if (rc_eco.ok())    // ECO region still accessible
            {
                rc_ecmd = data.extractToRight(&aiss_fsm, 13, 7);
                if (rc_ecmd)
                {
                    rc.setEcmdError(rc_ecmd);
                    return rc;
                }
                if (aiss_fsm==0)
                    o_inst_pm_state = INST_PM_STATE_RUN;
                else
                    o_inst_pm_state = INST_PM_STATE_RUN_OHA_ENTRY;
                bStateFound = true;
                break;
            }
            else  
            {                   // ECO region not accessible
                // Determine if the likely reason for the scom failure is that the PCB 
                // fence is up and that the reason behind this is that the OHA has
                // a hold on the PCB fence while in the OHA-window.
                // cmo-20140511: I have never ended up here yet. Maybe it isn't the OHA
                //               that controls the PCB fence, but rather the PCBS?
                address = EX_GP3_0x100F0012;
                rc = fapiGetScom( i_ex_target, address, data);
                if (rc)
                {
                    FAPI_ERR("fapiGetScom error (addr: 0x%08llX)", address);
                    return rc;
                }
                
                if (data.isBitSet(26))
                {                           // OHA-window
                    o_inst_pm_state = INST_PM_STATE_RUN_OHA_ENTRY;
                    bStateFound = true;
                    break;
                }
                else                        
                {                           // All other Scom error
                    o_inst_pm_state = INST_PM_STATE_UNDEFINED;
                    FAPI_ERR("fapiGetScom error (addr: 0x%08llX)", address_oha_status);
                    return rc_eco;
                }
            }
        }
        
        if (bStateFound || !bGoodState)
            break;
            
        
        // ---------------------------------------------------------------------------------
        // 2. Static state or Queued request for a chiplet that WAS NOT most recently processed.
        //
        //    IPMS = f(pmhist_state,pmc_queue_state)  if "ex_number NOT in slw_chiplet_vec"
        //                                            && "pending bit on" 
        // ---------------------------------------------------------------------------------
        // If the current ex chiplet IS/WAS NOT being processed by the SLW
        // engine's most recent idle assist, according to the PORRR0 SV, then we 
        // can determine its IPMS as follows:
        // 1) If pcbs_fsm==IDLE, then chiplet's state is static (except for the case #1
        //    above) and thus can be extracted from the PM HIST reg.
        // 2) If pcbs_fsm==0x2e (idle entry), this can only mean that it's a queued
        //    idle entry request which has already completed the OHA-window in case #1
        //    above and is now waiting for the PMC/SLW engine to complete their
        //    currently executing idle transition (for another chiplet).
        // 3) If pcbs_fsm=={0x50,0x51,0x57} (idle exit), this can only mean that it's a
        //    queued idle exit request and is now waiting for the PMC/SLW engine to
        //    complete their currently executing idle transition (for another chiplet).
        // 4) If pcbs_fsm==anything else, we don't know what this means and we give
        //    up.
        if ((slw_chiplet_vec & ((uint32_t)0x80000000>>ex_number))==0)
        {
            FAPI_INF("  This EX chiplet WAS NOT most recently processed by the SLW engine => Checking if STATIC or QUEUED state.");
            if ( pcbs_fsm == PCBS_FSM_IDLE )
            {
                FAPI_INF("  pcbs_fsm=0x%x : In a STATIC state : Using PM HIST to determine IPMS", pcbs_fsm);
                rc = ex_determine_ipms_from_pmhist( i_ex_target, pmhist_state, o_inst_pm_state, bGoodState);
                if (rc.ok())
                {
                    bStateFound = true;
                    break;
                }
                else
                {
                    FAPI_ERR("ex_determine_ipms_from_pmhist() failed w/rc=0x%08x", (uint32_t)rc);
                    return rc;
                }
            }
            else if ( pcbs_fsm == PCBS_FSM_ANY_IDLE_ENTRY  ||
                      pcbs_fsm == PCBS_FSM_ANY_SLEEP_EXIT  ||
                      pcbs_fsm == PCBS_FSM_ANY_WINKLE_EXIT ||
                      pcbs_fsm == PCBS_FSM_DEEP_WINKLE_EXIT )
            {
                FAPI_INF("  pcbs_fsm=0x%x : Checking if in a QUEUED_{ENTRY,EXIT} state : Using PMC PIRRx to determine IPMS", pcbs_fsm);
                rc = ex_determine_ipms_from_pirrx( i_ex_target, pcbs_fsm, pmc_queue_state, o_inst_pm_state, bGoodState);
                if (rc.ok())
                {
                    FAPI_INF("  Yes, this is a queued request");
                    bStateFound = true;
                    break;
                }
                else if (rc==fapi::RC_IPMS_PIRRX_NO_QUEUE_REQUEST)
                {
                    FAPI_INF("  No, this is NOT a queued request");
                    rc = fapi::FAPI_RC_SUCCESS;
                    bStateFound = false;
                }
                else
                {
                    FAPI_ERR("ex_determine_ipms_from_pirrx() failed w/rc=0x%08x", (uint32_t)rc);
                    return rc;
                }
            }
            else
            {
                FAPI_ERR("pcbs_fsm=0x%x in conjunction with pmc_queue_state=0x%x is an unsupported state", pcbs_fsm, pmc_queue_state);
                o_inst_pm_state = INST_PM_STATE_UNRESOLVED;
                const uint64_t & PCBS_FSM = pcbs_fsm;
                const uint64_t & PMHIST_STATE = pmhist_state;
                const uint64_t & PMC_QUEUE_STATE = pmc_queue_state;
                const fapi::Target & EX_TARGET = i_ex_target;
                FAPI_SET_HWP_ERROR(rc, RC_IPMS_SUSPICIOUS_PCBS_FSM);
                return rc;
            }
        }

        if (bStateFound || !bGoodState)
            break;
            
            
        // ---------------------------------------------------------------------
        // 3. Active (non-queued) request 
        //
        //    IPMS = f(pcbs_fsm,trans_sv)  if  "ex_number in slw_chiplet_vec"
        // ---------------------------------------------------------------------
        // OK, so the ex chiplet is, or was, being processed by the SLW engine's
        // current, or most recent, idle assist. The IPMS state can be deduced 
        // from the PCBS state in conjunction with the PMC's start_vector which
        // indicates the idle transition.
        if ((slw_chiplet_vec & ((uint32_t)0x80000000>>ex_number))!=0)
        {
            FAPI_INF("  This EX chiplet WAS MOST RECENTLY PROCESSED by the SLW engine => Checking PMC active events.");
                
            bStateFound = true; // Will get set false of no state found. 
            switch (pcbs_fsm)
            {
                case PCBS_FSM_IDLE:
                    FAPI_INF("  pcbs_fsm=0x%x : Using PM HIST to determine IPMS", pcbs_fsm);
                    rc = ex_determine_ipms_from_pmhist( i_ex_target, pmhist_state, o_inst_pm_state, bGoodState);
                    if (rc)
                    {
                        FAPI_ERR("ex_determine_ipms_from_pmhist() failed w/rc=0x%08x", (uint32_t)rc);
                        return rc;
                    }
                    break;
                
                case PCBS_FSM_ANY_IDLE_ENTRY:
                    FAPI_INF("  pcbs_fsm=0x%x : Using PMC SV to determine IPMS", pcbs_fsm);
                    if      (trans_sv == PORRR_SV_FS_ENTRY)
                        o_inst_pm_state = INST_PM_STATE_FS_ENTRY;
                    else if (trans_sv == PORRR_SV_DS_ENTRY)
                        o_inst_pm_state = INST_PM_STATE_DS_ENTRY;
                    else if (trans_sv == PORRR_SV_FW_ENTRY)
                        o_inst_pm_state = INST_PM_STATE_FW_ENTRY;
                    else if (trans_sv == PORRR_SV_DW_ENTRY)
                        o_inst_pm_state = INST_PM_STATE_DW_ENTRY;
                    else
                        bStateFound = false;             
                    break;
                
                case PCBS_FSM_ANY_SLEEP_EXIT:
                    FAPI_INF("  pcbs_fsm=0x%x : Using PMC SV to determine IPMS", pcbs_fsm);
                    if      (trans_sv == PORRR_SV_FS_EXIT)
                        o_inst_pm_state = INST_PM_STATE_FS_EXIT;
                    else if (trans_sv == PORRR_SV_DS_EXIT)
                        o_inst_pm_state = INST_PM_STATE_DS_EXIT;
                    else
                        bStateFound = false;
                    break;
                
                case PCBS_FSM_ANY_WINKLE_EXIT:
                    FAPI_INF("  pcbs_fsm=0x%x : Using PMC SV to determine IPMS", pcbs_fsm);
                    if      (trans_sv == PORRR_SV_FW_EXIT)
                        o_inst_pm_state = INST_PM_STATE_FW_EXIT;
                    else if (trans_sv == PORRR_SV_DW_EXIT)
                        o_inst_pm_state = INST_PM_STATE_DW_EXIT;
                    else
                        bStateFound = false;
                    break;
                
                case PCBS_FSM_DEEP_WINKLE_EXIT:
                    FAPI_INF("  pcbs_fsm=0x%x : Using PMC SV to determine IPMS", pcbs_fsm);
                    if (trans_sv == PORRR_SV_DW_EXIT)
                        o_inst_pm_state = INST_PM_STATE_DW_EXIT;
                    else
                        bStateFound = false;
                    break;
                
                default:
                    FAPI_INF("  pcbs_fsm=0x%x was not recognized",pcbs_fsm);
                    bGoodState = false;
                    break;
            }
            if (!bStateFound)
            {
                FAPI_INF("  No active event found");
            }
        }

        if (bStateFound || !bGoodState)
            break;


        // ----------------------------------------------------------------------------------
        // 4. Queued request for a chiplet that WAS most recently processed.
        //
        //    IPMS = f(pmhist_state,pmc_queue_state)  if "not an active request"
        //                                            && "ex_number is in slw_chiplet_vec"
        //                                            && "trans_sv doesn't agree w/pcbs_fsm"
        //                                            && "pending bit on" 
        // ----------------------------------------------------------------------------------
        // If the current ex chiplet IS/WAS being processed by the SLW
        // engine's most recent idle assist, according to the PORRR0 SV, then we 
        // can determine its IPMS as follows:
        // 1) If pcbs_fsm==IDLE, then chiplet's state is static (except for the case #1
        //    above) and thus can be extracted from the PM HIST reg.
        // 2) If pcbs_fsm==0x2e (idle entry), this can only mean that it's a queued
        //    idle ENTRY request (for the SAME chiplet that most recently EXITED
        //    an idle state) and which has already completed the OHA-window in case #1
        //    above. However, the ENTRY request has been caught by a xstop in the PCBS 
        //    before the request had a chance to be arbitrated into the PMC master and
        //    it is now sitting in the PMC queue.
        // 3) If pcbs_fsm=={0x50,0x51,0x57} (idle exit), this can only mean that it's a
        //    queued idle EXIT request(for the SAME chiplet that most recently ENTERED
        //    an idle state). However, the EXIT request has been caught by a xstop in
        //    the PCBS before the request had a chance to be arbitrated into the PMC 
        //    master and is now sitting in the PMC queue.
        // 4) If pcbs_fsm==anything else, we don't know what this means and we give
        //    up.
        // 
        // Note that if we're here in step $3, we have bGoodState==true and bStateFound==false. The
        // later means that step #3 failed because trans_sv and pscb_fsm disagree and that this is
        // therefore a possible queued request for the same chiplet that was most recently 
        // processed by the SLW engine.
        //
        if ( (slw_chiplet_vec & ((uint32_t)0x80000000>>ex_number))!=0 )
        {
            FAPI_INF("  This EX chiplet WAS most recently processed by the SLW engine, but it's NOT an active event => Checking PMC Queue.");
            if ( pcbs_fsm == PCBS_FSM_ANY_IDLE_ENTRY  ||
                 pcbs_fsm == PCBS_FSM_ANY_SLEEP_EXIT  ||
                 pcbs_fsm == PCBS_FSM_ANY_WINKLE_EXIT ||
                 pcbs_fsm == PCBS_FSM_DEEP_WINKLE_EXIT )
            {
                FAPI_INF("  pcbs_fsm=0x%x : Should be in a QUEUED_{ENTRY,EXIT} state : Using PMC PIRRx to determine IPMS", pcbs_fsm);
                rc = ex_determine_ipms_from_pirrx( i_ex_target, pcbs_fsm, pmc_queue_state, o_inst_pm_state, bGoodState);
                if (rc.ok())
                {
                    FAPI_INF("  Yes, this is a queued request");
                    bStateFound = true;
                    break;
                }
                else if (rc==fapi::RC_IPMS_PIRRX_NO_QUEUE_REQUEST)
                {
                    FAPI_INF("  No, this is NOT a queued request");
                    rc = fapi::FAPI_RC_SUCCESS;
                    bStateFound = false;
                }
                else
                {
                    FAPI_ERR("ex_determine_ipms_from_pirrx() failed w/rc=0x%08x", (uint32_t)rc);
                    return rc;
                }
            }
            else
            {
                FAPI_ERR("pcbs_fsm=0x%x in conjunction with pmc_queue_state=0x%x is an unsupported state", pcbs_fsm, pmc_queue_state);
                o_inst_pm_state = INST_PM_STATE_UNRESOLVED;
                const uint64_t & PCBS_FSM = pcbs_fsm;
                const uint64_t & PMHIST_STATE = pmhist_state;
                const uint64_t & PMC_QUEUE_STATE = pmc_queue_state;
                const fapi::Target & EX_TARGET = i_ex_target;
                FAPI_SET_HWP_ERROR(rc, RC_IPMS_SUSPICIOUS_PCBS_FSM);
                return rc;
            }
        }
        
        if (bStateFound || !bGoodState)
            break;


        // ----------------------------------------------------------------------------------
        // 5. PCBS active but request has not yet been queued.
        //
        //    IPMS = f(pmhist_state,pmgp3_state)  if "not an active event"
        //                                           && "not a static state"
        //                                           && "not a queued request"
        //
        //
        // In order to be here, at case #5, it has been determined that above that
        // - this is not in the OHA-window
        // - this is not an active event
        // - this is not a static state
        // - this is not a queued request
        // Thus, this is probably the INST_PM_STATE_PCBS_xyz state.
        //
        FAPI_INF("  This is probably the INST_PM_STATE_PCBS_xyz. Determine which of the five possible states it might be.");
        
        // Extract FAST/DEEP status from PM GP1
        //
        address = EX_PMGP1_0x100F0103;
        rc = fapiGetScom( l_parentTarget, address, dataPMGP1);
        if (rc)
        {
            FAPI_ERR("fapiGetScom error (addr: 0x%08llX)", address);
            return rc;
        }
        
        switch (pcbs_fsm)
        {
        
            case  PCBS_FSM_ANY_IDLE_ENTRY :
                o_inst_pm_state = INST_PM_STATE_PCBS_ANY_ENTRY;
                bStateFound = true;
                break;
            
            case  PCBS_FSM_ANY_SLEEP_EXIT :
                if (dataPMGP1.getDoubleWord(0)&((uint64_t)0x20000000)<<32)
                {
                    o_inst_pm_state = INST_PM_STATE_PCBS_DS_EXIT;
                }
                else
                {
                    o_inst_pm_state = INST_PM_STATE_PCBS_FS_EXIT;
                }
                bStateFound = true;
                break;
                
            case  PCBS_FSM_ANY_WINKLE_EXIT :
                if (dataPMGP1.getDoubleWord(0)&((uint64_t)0x04000000)<<32)
                {
                    o_inst_pm_state = INST_PM_STATE_PCBS_DW_EXIT;
                }
                else
                {
                    o_inst_pm_state = INST_PM_STATE_PCBS_FW_EXIT;
                }
                bStateFound = true;
                break;
                
            case  PCBS_FSM_DEEP_WINKLE_EXIT :
                o_inst_pm_state = INST_PM_STATE_PCBS_DW_EXIT;
                bStateFound = true;
                break;
        
            default:
                FAPI_ERR("pcbs_fsm=0x%x is unsupported for identification in this context.", pcbs_fsm);
                o_inst_pm_state = INST_PM_STATE_UNRESOLVED;
                bStateFound = false;
                break;
        
        }

   
    } while(0);


    if (!bGoodState)
    {
        address = PMC_PIRR0_REG_0x00062080;
        fapiGetScom( l_parentTarget, address, dataPIRR0);
        address = PMC_PIRR0_REG_0x00062081;
        fapiGetScom( l_parentTarget, address, dataPIRR1);
        address = PMC_PIRR0_REG_0x00062082;
        fapiGetScom( l_parentTarget, address, dataPIRR2);
        address = PMC_PIRR0_REG_0x00062083;
        fapiGetScom( l_parentTarget, address, dataPIRR3);
        address = PORE_SLW_STATUS_0x00068000;
        fapiGetScom( l_parentTarget, address, dataSTATUS);
        address = PORE_SLW_DBG0_0x0006800F;
        fapiGetScom( l_parentTarget, address, dataDEBUG0);
        address = PORE_SLW_DBG1_0x00068010;
        fapiGetScom( l_parentTarget, address, dataDEBUG1);
        address = PMC_LFIR_0x01010840;
        fapiGetScom( l_parentTarget, address, dataPMCLFIR);
        FAPI_ERR("Conflicting PM state values for core=0x%x:", ex_number);
        FAPI_ERR("  PORRR0 reg:          0x%016llx",dataPORRR0.getDoubleWord(0));
        FAPI_ERR("  PORRR1 reg:          0x%016llx",dataPORRR1.getDoubleWord(0));
        FAPI_ERR("  ETR reg:             0x%016llx",dataETR.getDoubleWord(0));
        FAPI_ERR("  PCBS_FSM (prev):     0x%x",pcbs_fsm_prev);
        FAPI_ERR("  PCBS_FSM (new):      0x%x",pcbs_fsm);
        FAPI_ERR("  PMHIST:              0x%x",pmhist_state);
        FAPI_ERR("  PMC_QUEUE_STATE:     0x%x",pmc_queue_state);
        FAPI_ERR("  IPMS_STATE:          0x%x", o_inst_pm_state);
        FAPI_ERR("  PIRR0 reg:           0x%016llx",dataPIRR0.getDoubleWord(0));
        FAPI_ERR("  PIRR1 reg:           0x%016llx",dataPIRR1.getDoubleWord(0));
        FAPI_ERR("  PIRR2 reg:           0x%016llx",dataPIRR2.getDoubleWord(0));
        FAPI_ERR("  PIRR3 reg:           0x%016llx",dataPIRR3.getDoubleWord(0));
        FAPI_ERR("  PORE STATUS reg:     0x%016llx",dataSTATUS.getDoubleWord(0));
        FAPI_ERR("  PORE DEBUG0 reg:     0x%016llx",dataDEBUG0.getDoubleWord(0));
        FAPI_ERR("  PORE DEBUG1 reg:     0x%016llx",dataDEBUG1.getDoubleWord(0));
        FAPI_ERR("  PMC_LFIR_0x01010840: 0x%016llx",dataPMCLFIR.getDoubleWord(0));
        const uint64_t & PORRR0_REG    = dataPORRR0.getDoubleWord(0);
        const uint64_t & PORRR1_REG    = dataPORRR1.getDoubleWord(0);
        const uint64_t & ETR_REG       = dataETR.getDoubleWord(0);
        const uint64_t & PCBS_FSM_PREV = pcbs_fsm_prev;
        const uint64_t & PCBS_FSM      = pcbs_fsm;
        const uint64_t & PMHIST_STATE  = pmhist_state;
        const uint64_t & PMC_QUEUE_STATE = pmc_queue_state;
        const uint64_t & IPMS_STATE    = o_inst_pm_state;
        const uint64_t & PIRR0_REG     = dataPIRR0.getDoubleWord(0);
        const uint64_t & PIRR1_REG     = dataPIRR1.getDoubleWord(0);
        const uint64_t & PIRR2_REG     = dataPIRR2.getDoubleWord(0);
        const uint64_t & PIRR3_REG     = dataPIRR3.getDoubleWord(0);
        const fapi::Target & EX_TARGET = i_ex_target;
        FAPI_SET_HWP_ERROR(rc, RC_IPMS_CONFLICTING_IDLE_STATES);
        o_inst_pm_state = INST_PM_STATE_UNRESOLVED;
        return rc;    
    }
    
    if (bStateFound)
    {
        FAPI_INF("\tp8_inst_pm_state() successful - Final IPMS state:  0x%x => %s", o_inst_pm_state, INST_PM_STATE_NAMES[o_inst_pm_state]);
    }
    else
    {
        address = PMC_PIRR0_REG_0x00062080;
        fapiGetScom( l_parentTarget, address, dataPIRR0);
        address = PMC_PIRR0_REG_0x00062081;
        fapiGetScom( l_parentTarget, address, dataPIRR1);
        address = PMC_PIRR0_REG_0x00062082;
        fapiGetScom( l_parentTarget, address, dataPIRR2);
        address = PMC_PIRR0_REG_0x00062083;
        fapiGetScom( l_parentTarget, address, dataPIRR3);
        address = PORE_SLW_STATUS_0x00068000;
        fapiGetScom( l_parentTarget, address, dataSTATUS);
        address = PORE_SLW_DBG0_0x0006800F;
        fapiGetScom( l_parentTarget, address, dataDEBUG0);
        address = PORE_SLW_DBG1_0x00068010;
        fapiGetScom( l_parentTarget, address, dataDEBUG1);
        address = PMC_LFIR_0x01010840;
        fapiGetScom( l_parentTarget, address, dataPMCLFIR);
        FAPI_ERR("p8_inst_pm_state() unsuccessful - Shouldn't be here - Could be a code error");
        FAPI_ERR("  PORRR0 reg:          0x%016llx",dataPORRR0.getDoubleWord(0));
        FAPI_ERR("  PORRR1 reg:          0x%016llx",dataPORRR1.getDoubleWord(0));
        FAPI_ERR("  ETR reg:             0x%016llx",dataETR.getDoubleWord(0));
        FAPI_ERR("  PCBS_FSM (prev):     0x%x",pcbs_fsm_prev);
        FAPI_ERR("  PCBS_FSM (new):      0x%x",pcbs_fsm);
        FAPI_ERR("  PMHIST:              0x%x",pmhist_state);
        FAPI_ERR("  PMC_QUEUE_STATE:     0x%x",pmc_queue_state);
        FAPI_ERR("  IPMS_STATE:          0x%x", o_inst_pm_state);
        FAPI_ERR("  PIRR0 reg:           0x%016llx",dataPIRR0.getDoubleWord(0));
        FAPI_ERR("  PIRR1 reg:           0x%016llx",dataPIRR1.getDoubleWord(0));
        FAPI_ERR("  PIRR2 reg:           0x%016llx",dataPIRR2.getDoubleWord(0));
        FAPI_ERR("  PIRR3 reg:           0x%016llx",dataPIRR3.getDoubleWord(0));
        FAPI_ERR("  PORE STATUS reg:     0x%016llx",dataSTATUS.getDoubleWord(0));
        FAPI_ERR("  PORE DEBUG0 reg:     0x%016llx",dataDEBUG0.getDoubleWord(0));
        FAPI_ERR("  PORE DEBUG1 reg:     0x%016llx",dataDEBUG1.getDoubleWord(0));
        FAPI_ERR("  PMC_LFIR_0x01010840: 0x%016llx",dataPMCLFIR.getDoubleWord(0));
        const uint64_t & PORRR0_REG    = dataPORRR0.getDoubleWord(0);
        const uint64_t & PORRR1_REG    = dataPORRR1.getDoubleWord(0);
        const uint64_t & ETR_REG       = dataETR.getDoubleWord(0);
        const uint64_t & PCBS_FSM_PREV = pcbs_fsm_prev;
        const uint64_t & PCBS_FSM      = pcbs_fsm;
        const uint64_t & PMHIST_STATE  = pmhist_state;
        const uint64_t & PMC_QUEUE_STATE = pmc_queue_state;
        const uint64_t & IPMS_STATE    = o_inst_pm_state;
        const uint64_t & PIRR0_REG     = dataPIRR0.getDoubleWord(0);
        const uint64_t & PIRR1_REG     = dataPIRR1.getDoubleWord(0);
        const uint64_t & PIRR2_REG     = dataPIRR2.getDoubleWord(0);
        const uint64_t & PIRR3_REG     = dataPIRR3.getDoubleWord(0);
        const fapi::Target & EX_TARGET = i_ex_target;
        FAPI_SET_HWP_ERROR(rc, RC_IPMS_STATE_NOT_FOUND_BUG);
        o_inst_pm_state = INST_PM_STATE_UNRESOLVED;
        return rc;
    }

    return rc;
}


//------------------------------------------------------------------------------
// @proc_name  ex_determine_ipms_from_pmhist()
//------------------------------------------------------------------------------
// @brief Determine the Instantaneous PM State (IPMS) strictly from the PM HIST register.
//
// @param[in]  i_ex_target'        the EX chiplet target
// @param[in]  i_pmhist_state'     the PM HIST state
// @param[out] o_inst_pm_state'    the returned instantaneous pm state 
// @param[out] o_bGoodState'       the returned IPMS state qualifier
//
// @return  ReturnCode  FAPI_RC_SUCCESS, platform error or FFDC specified error
//
//------------------------------------------------------------------------------
fapi::ReturnCode  ex_determine_ipms_from_pmhist(  const fapi::Target &i_ex_target,
                                                  uint32_t  i_pmhist_state, 
                                                  uint8_t   &o_inst_pm_state,
                                                  bool      &o_bGoodState )
{
    fapi::ReturnCode    rc;             //fapi return code value
    
    bool                bCodeBug=false;
                
    o_bGoodState = true;
    bCodeBug = false;
    
    switch (i_pmhist_state)
    {
        case PMHIST_STATE_RUN:
            o_inst_pm_state = INST_PM_STATE_RUN;
            break;
    
        case PMHIST_STATE_SPECIAL_WAKEUP:
            o_inst_pm_state = INST_PM_STATE_SPECIAL_WAKEUP;
            break;
    
        case PMHIST_STATE_NAP:
            o_inst_pm_state = INST_PM_STATE_NAP_STATIC;
            break;
    
        case PMHIST_STATE_LEGACY_SLEEP: // No hw support for this state in p8
            FAPI_ERR("pmhist_state = 0x%x = %s not supported. Check code.", 
                        i_pmhist_state, PMHIST_STATE_NAMES[i_pmhist_state]);
            o_inst_pm_state = INST_PM_STATE_UNRESOLVED;
            o_bGoodState = false;
            bCodeBug = true;
            break;
    
        case PMHIST_STATE_FAST_SLEEP:
            o_inst_pm_state = INST_PM_STATE_FS_STATIC;
            break;
    
        case PMHIST_STATE_DEEP_SLEEP:
            o_inst_pm_state = INST_PM_STATE_DS_STATIC;
            break;
    
        case PMHIST_STATE_FAST_WINKLE:
            o_inst_pm_state = INST_PM_STATE_FW_STATIC;
            break;
    
        case PMHIST_STATE_DEEP_WINKLE:
            o_inst_pm_state = INST_PM_STATE_DW_STATIC;
            break;
    
        default:
            FAPI_ERR("pmhist_state = 0x%x is impossible. Check code.", i_pmhist_state);
            o_inst_pm_state = INST_PM_STATE_UNRESOLVED;
            o_bGoodState = false;
            bCodeBug = true;
            break;
    }
    
    if (bCodeBug)
    {
        FAPI_ERR("bCodeBug==true should never happen. Check code.");
        const uint64_t & PMHIST_STATE = i_pmhist_state;
        const fapi::Target & EX_TARGET = i_ex_target;
        FAPI_SET_HWP_ERROR(rc, RC_IPMS_PMHIST_CODE_BUG);
        return rc;
    }
        
    return rc;
} // ex_determine_ipms_from_pmhist()


//------------------------------------------------------------------------------
// @proc_name  ex_determine_ipms_from_pirrx()
//------------------------------------------------------------------------------
// @brief Determine the Instantaneous PM State (IPMS) strictly from the PMC PIRRx registers.
//
// @param[in]  i_ex_target'        the EX chiplet target
// @param[out] o_inst_pm_state'    the returned instantaneous pm state 
// @param[out] o_bGoodState'       the returned IPMS state qualifier
//
// @return  ReturnCode  FAPI_RC_SUCCESS, platform error or FFDC specified error
//
//------------------------------------------------------------------------------
fapi::ReturnCode  ex_determine_ipms_from_pirrx( const fapi::Target &i_ex_target,
                                                uint32_t  i_pcbs_fsm,
                                                uint32_t  i_pmc_queue_state, 
                                                uint8_t   &o_inst_pm_state,
                                                bool      &o_bGoodState )
{
    fapi::ReturnCode    rc;             //fapi return code value
                
    o_bGoodState = true;
    
    if ( i_pmc_queue_state & PMC_QUEUE_PENDING_MASK )
    {
        switch (i_pmc_queue_state & PMC_QUEUE_OP_TYPE_SCOPE_MASK)
        {
            case PMC_QUEUE_FS_ENTRY :
                o_inst_pm_state = INST_PM_STATE_QUEUED_FS_ENTRY;
                break;
            
            case PMC_QUEUE_DS_ENTRY :
                o_inst_pm_state = INST_PM_STATE_QUEUED_DS_ENTRY;
                break;
            
            case PMC_QUEUE_FS_EXIT :
                o_inst_pm_state = INST_PM_STATE_QUEUED_FS_EXIT;
                break;
            
            case PMC_QUEUE_DS_EXIT :
                o_inst_pm_state = INST_PM_STATE_QUEUED_DS_EXIT;
                break;
            
            case PMC_QUEUE_FW_ENTRY :
                o_inst_pm_state = INST_PM_STATE_QUEUED_FW_ENTRY;
                break;
                
            case PMC_QUEUE_DW_ENTRY :
                o_inst_pm_state = INST_PM_STATE_QUEUED_DW_ENTRY;
                break;
                
            case PMC_QUEUE_FW_EXIT :
                o_inst_pm_state = INST_PM_STATE_QUEUED_FW_EXIT;
                break;
            
            case PMC_QUEUE_DW_EXIT :
                o_inst_pm_state = INST_PM_STATE_QUEUED_DW_EXIT;
                break;
            
            default :
                FAPI_ERR("There is an unsupported request on the PMC queue (pmc_queue_state=0x%x). Code bug.",
                          i_pmc_queue_state);
                o_inst_pm_state = INST_PM_STATE_UNRESOLVED;
                const uint64_t & PMC_QUEUE_STATE = i_pmc_queue_state;
                const fapi::Target & EX_TARGET = i_ex_target;
                FAPI_SET_HWP_ERROR(rc, RC_IPMS_PIRRX_UNSUPPORTED_IDLE_REQUEST);
                return rc;
        }
    }
    else
    {
        FAPI_ERR("\tThere is no queueing request for this chiplet.");
        o_inst_pm_state = INST_PM_STATE_UNRESOLVED;
        FAPI_SET_HWP_ERROR(rc, RC_IPMS_PIRRX_NO_QUEUE_REQUEST);
        return rc;
    }

    return rc;
} // ex_determine_ipms_from_pirrx()


} // extern "C"
