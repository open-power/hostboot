/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/utility_procedures/p8_cpu_special_wakeup.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2014                   */
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
// $Id: p8_cpu_special_wakeup.C,v 1.20 2014/04/07 20:40:45 stillgs Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/p8_cpu_special_wakeup.C,v $
//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
//------------------------------------------------------------------------------
// *! OWNER NAME: Greg Still         Email: stillgs@us.ibm.com
// *!
// *! To build - buildfapiprcd -e "../../xml/error_info/proc_cpu_special_wakeup_errors.xml,../../xml/error_info/p8_slw_registers.xml" p8_cpu_special_wakeup.C
// *!
/// \file p8_cpu_special_wakeup.C
/// \brief Put targeted EX chiplets into special wake-up
///
///  add to required proc ENUM requests
///
/// High-level procedure flow:
/// \verbatim
///
///     Based on "entity" parameter (OCC, FSP, PHYP), write the
///     appropriate Special Wakeup bit (different address)
///
///     Poll for SPECIAL WAKEUP DONE
///     Polling timeouts need to account for the following (future version):
///         1) All the chiplets are not in a Deep Idle state and will awaken in
///         < 1us (eg no PORE assistance needed)
///
///         2) All the chiplets are not in a Deep Sleep or less (run of nap) in
///         which case all can be in special wake-up in ~5ms state
///
///         3) Some chiplets are in Deep Sleep and some are in Deep Winkle
///         which case there is a serialization of the two exits (5ms (Sleep)
///         and 10ms (Winkle).
///
///     Thus, do a progressive poll (in a future version).
///         Wait 1us
///         poll
///         if done, exit
///         pollcount=0
///         do
///             wait 5ms
///             poll
///             if done, exit
///             pollcount++
///         while pollcount<5  (eg 25ms)
///         flag timout error ///     Timeouts on polling are progressive
///
///
///  Procedure Prereq:
///     - System clocks are running
/// \endverbatim
///
///
//------------------------------------------------------------------------------


// ----------------------------------------------------------------------
// Includes
// ----------------------------------------------------------------------

#include "p8_pm.H"
#include "p8_cpu_special_wakeup.H"
#include "p8_pcb_scom_errors.H"

extern "C" {

using namespace fapi;


/// \param[in] i_ex_target  EX Target
/// \param[in] i_operation  ENABLE, DISABLE, INIT
/// \param[in] entity       Entity bit to use (OCC, PHYP, FSP)

/// \retval PM_SUCCESS if something good happens,
/// \retval PM_PROCPM_SPCWKUP* otherwise
fapi::ReturnCode
p8_cpu_special_wakeup(  const fapi::Target& i_ex_target,
                        PROC_SPCWKUP_OPS i_operation ,
                        PROC_SPCWKUP_ENTITY i_entity )

{
    fapi::ReturnCode    rc;
    fapi::ReturnCode    oha_rc;
    uint32_t            e_rc = 0;
    ecmdDataBufferBase  data(64);
    ecmdDataBufferBase  fsi_data(64);
    ecmdDataBufferBase  polldata(64);

    fapi::Target        l_parentTarget;
    uint8_t             attr_chip_unit_pos = 0;

    const char* PROC_SPCWKUP_ENTITY_NAMES[] =
    {
        "HOST",
        "FSP",
        "OCC",
        "PHYP",
        "SPW_ALL"
    };

    const char* PROC_SPCWKUP_OPS_NAMES[] =
    {
        "DISABLE",
        "ENABLE",
        "INIT"
    };

    uint32_t            special_wakeup_max_polls;

    /// Time (binary in milliseconds) for the first poll check (running/nap
    ///     case.
    ///    uint32_t special_wakeup_quick_poll_time = 1;

    ///  Get an attribute that defines the maximum special wake-up polling
    ///         timing (binary in milliseconds).
    ///  Increased timeout to 200ms - 6/10/13

    uint32_t            special_wakeup_timeout = 200;

    ///  Get an attribute that defines the special wake-up polling interval
    ///         (binary in milliseconds).
    uint32_t            special_wakeup_poll_interval = 5;

    uint32_t            pollcount = 0;
    uint32_t            count = 0;

    std::vector<fapi::Target>      l_chiplets;
    std::vector<Target>::iterator  itr;

    uint8_t             oha_spwkup_flag = 0;
    uint8_t             ignore_xstop_flag = 0;
    bool                poll_during_xstop_flag = false;
    bool                xstop_flag = false;

    uint32_t            idle_state;

    //--------------------------------------------------------------------------
    // Read the counts of different ENTITY (FSP,OCC,PHYP) from the Attributes
    //--------------------------------------------------------------------------

    uint32_t            phyp_spwkup_count = 0;
    uint32_t            fsp_spwkup_count  = 0;
    uint32_t            occ_spwkup_count  = 0;

    uint64_t            spwkup_address  = 0;
    uint64_t            history_address  = 0;

    // detect AISS capaiblity
    uint8_t             chipHasAISSSWUP = 0;

    do
    {

        FAPI_INF("Executing p8_cpu_special_wakeup %s for %s ...",
                    PROC_SPCWKUP_OPS_NAMES[i_operation],
                    PROC_SPCWKUP_ENTITY_NAMES[i_entity]);

        // Initialize the attributes to 0.
        if (i_operation == SPCWKUP_INIT)
        {
            FAPI_INF("Processing target %s", i_ex_target.toEcmdString());
            FAPI_INF("Initializing ATTR_PM_SPWUP_FSP");
            rc = FAPI_ATTR_SET(ATTR_PM_SPWUP_FSP, &i_ex_target, fsp_spwkup_count);
            if (rc)
            {
                FAPI_ERR("fapiSetAttribute of ATTR_PM_SPWUP_FSP with rc = 0x%x", (uint32_t)rc);
                break ;
            }

            FAPI_INF("Initializing ATTR_PM_SPWUP_OCC");
            rc = FAPI_ATTR_SET(ATTR_PM_SPWUP_OCC, &i_ex_target, occ_spwkup_count);
            if (rc)
            {
                FAPI_ERR("fapiSetAttribute of ATTR_PM_SPWUP_OCC with rc = 0x%x", (uint32_t)rc);
                break;
            }

            FAPI_INF("Initializing ATTR_PM_SPWUP_PHYP");
            rc = FAPI_ATTR_SET(ATTR_PM_SPWUP_PHYP, &i_ex_target, phyp_spwkup_count);
            if (rc)
            {
                FAPI_ERR("fapiSetAttribute of ATTR_PM_SPWUP_PHYP with rc = 0x%x", (uint32_t)rc);
                break;
            }

            FAPI_INF("Initializing ATTR_PM_SPWUP_OHA_FLAG");
            rc = FAPI_ATTR_SET(ATTR_PM_SPWUP_OHA_FLAG, &i_ex_target, oha_spwkup_flag);
            if (rc)
            {
                FAPI_ERR("fapiSetAttribute of ATTR_PM_SPWUP_OHA_FLAG with rc = 0x%x", (uint32_t)rc);
                break;
            }

            FAPI_INF("Initializing ATTR_PM_SPWUP_IGNORE_XSTOP_FLAG");
            rc = FAPI_ATTR_SET(ATTR_PM_SPWUP_IGNORE_XSTOP_FLAG, &i_ex_target, ignore_xstop_flag);
            if (rc)
            {
                FAPI_ERR("fapiSetAttribute of ATTR_PM_SPWUP_IGNORE_XSTOP_FLAG with rc = 0x%x", (uint32_t)rc);
                break ;
            }

            // Leave the procedure
            break;
        }

        //--------------------------------------------------------------------------
        //           Checking the ENTITY who raised this OPERATION
        //--------------------------------------------------------------------------

        // Get the parent chip to target the registers
        rc = fapiGetParentChip(i_ex_target, l_parentTarget);
        if (rc)
        {
            break;    // throw error
        }

        // Get the core number
        rc = FAPI_ATTR_GET(ATTR_CHIP_UNIT_POS, &i_ex_target, attr_chip_unit_pos);
        if (rc)
        {
            FAPI_ERR("fapiGetAttribute of ATTR_CHIP_UNIT_POS with rc = 0x%x", (uint32_t)rc);
            break;
        }

        FAPI_DBG("Core number = %d", attr_chip_unit_pos);

        // Read the Attributes to know the Special_wake counts from each entity
        // This should be different for different EX chiplets.
        rc = FAPI_ATTR_GET(ATTR_PM_SPWUP_FSP, &i_ex_target, fsp_spwkup_count);
        if (rc)
        {
            FAPI_ERR("fapiGetAttribute of ATTR_PM_SPWUP_FSP with rc = 0x%x", (uint32_t)rc);
            break;
        }

        rc = FAPI_ATTR_GET(ATTR_PM_SPWUP_OCC, &i_ex_target, occ_spwkup_count );
        if (rc)
        {
            FAPI_ERR("fapiGetAttribute of ATTR_PM_SPWUP_OCC with rc = 0x%x", (uint32_t)rc);
            break;
        }

        rc = FAPI_ATTR_GET(ATTR_PM_SPWUP_PHYP,&i_ex_target , phyp_spwkup_count );
        if (rc)
        {
            FAPI_ERR("fapiGetAttribute of ATTR_PM_SPWUP_PHYP with rc = 0x%x", (uint32_t)rc);
            break;
        }

        /// Calculate the maximum number of polls until a timeout is thrown
        special_wakeup_max_polls = special_wakeup_timeout / special_wakeup_poll_interval;

        // Process counts based on the calling entity
        if (i_entity == OCC)
        {
            count = occ_spwkup_count ;
            FAPI_INF("OCC count before = %d" , count);
            spwkup_address = PM_SPECIAL_WKUP_OCC_0x100F010C;
            history_address = EX_PMSTATEHISTOCC_REG_0x100F0112;
        }
        else if (i_entity == FSP)
        {
            count = fsp_spwkup_count ;
            FAPI_INF("FSP count before = %d" , count);
            spwkup_address = PM_SPECIAL_WKUP_FSP_0x100F010B;
            history_address = EX_PMSTATEHISTFSP_REG_0x100F0111;
        }
        else if (i_entity == PHYP)
        {
            count = phyp_spwkup_count ;
            FAPI_INF("PHYP count before = %d" , count);
            spwkup_address = PM_SPECIAL_WKUP_PHYP_0x100F010D;
            history_address = EX_PMSTATEHISTPHYP_REG_0x100F0110;
        }
        else
        {
            FAPI_ERR("Unknown entity passed to proc_special_wakeup. Entity %x ....", i_entity);
            //    I_ENTITY = i_entity;
            PROC_SPCWKUP_ENTITY & I_ENTITY = i_entity ;
            FAPI_SET_HWP_ERROR(rc, RC_PROCPM_SPCWKUP_CODE_BAD_ENTITY);
            break;
        }

        /////////////////////////////////////////////////////////////////////////////
        //           Checking the type of OPERATION and process the request
        /////////////////////////////////////////////////////////////////////////////

        rc=fapiGetScom(i_ex_target, EX_PMGP0_0x100F0100, data);
        if(rc)
        {
            break;
        }

        if (i_operation == SPCWKUP_ENABLE)
        {

            // If the OHA flag is set, then any subsequent calls to the this
            // procedure must return a "good" response or else an infinite
            // loop results for any calling algorithm that first sets
            // special wake-up, does a SCOM, and then clears special
            // wake-up.
            rc = FAPI_ATTR_GET(   ATTR_PM_SPWUP_OHA_FLAG,
                                    &i_ex_target,
                                    oha_spwkup_flag);
            if (rc)
            {
                FAPI_ERR("fapiGetAttribute of ATTR_PM_SPWUP_OHA_FLAG with rc = 0x%x", (uint32_t)rc);
                break;
            }

            if (oha_spwkup_flag)
            {
                 FAPI_INF("OHA special wakeup flag is set so returning with good response to break recursion.  Counts are NOT updated.");
                // This is a purposeful mid-procedure return
                return rc;
            }

            // Determine if xstop checking should be ignored base on a caller
            // set attribute.
            //
            // This is used during MPIPL clean-up to a core to clear FIRs that
            // will eventually clear the xstop condition.  However, to do so
            // needs the xstop check to not keep the special wake-up operation
            // from happening.
            rc = FAPI_ATTR_GET(   ATTR_PM_SPWUP_IGNORE_XSTOP_FLAG,
                                    &i_ex_target,
                                    ignore_xstop_flag);
            if (rc)
            {
                FAPI_ERR("fapiGetAttribute of ATTR_PM_SPWUP_IGNORE_XSTOP_FLAG with rc = 0x%x", (uint32_t)rc);
                break ;
            }

            FAPI_INF("Ignore XSTOP:  %s", (ignore_xstop_flag ? "YES" : "NO"));

            // Read system checkstop indicator
            GETSCOM(rc, l_parentTarget, PCBMS_INTERRUPT_TYPE_REG_0x000F001A, data);

            if( data.isBitSet( 2 ) )
            {
                FAPI_INF( "Checkstop present" );
                xstop_flag = true;
            }

            // Error out if system is checkstopped and not told to ignore it
            if (!ignore_xstop_flag && xstop_flag)
            {
                FAPI_ERR( "This chip is xstopped and the attribute ATTR_PM_SPWUP_IGNORE_XSTOP_FLAG is NOT set" );
                const uint64_t& PCBSINTRTYPE = data.getDoubleWord(0);
                const uint8_t & ATTRIGNOREXSTOP = ignore_xstop_flag;
                const fapi::Target & EX_TARGET = i_ex_target;
                FAPI_SET_HWP_ERROR(rc, RC_PROCPM_CHKSTOP);
                break;
            }

            // Proceed
            FAPI_INF("Setting Special Wake-up  ...") ;

            if (count == 0)
            {

                GETSCOM(rc, i_ex_target, spwkup_address, data);

                e_rc  = data.flushTo0();
                e_rc |= data.setBit(0);
                E_RC_CHECK(e_rc, rc);

                PUTSCOM(rc, i_ex_target, spwkup_address, data);

                // Determine whether to poll for completion of Special wake-up.
                // Running and Nap - can alsways be polled as these are not
                //      dependent on an xstop condition.
                // Sleep and Winkle - poll oonly if not in an xstop condition

                // read PM History
                GETSCOM(rc, i_ex_target, EX_PMSTATEHISTPERF_REG_0x100F0113, data );

                e_rc |= data.extractToRight(&idle_state,  0, 3);
                E_RC_CHECK(e_rc, rc);

                // 0b000: Run
                // 0b001: Special Wakeup
                // 0b010: Nap
                // 0b011: Legacy Sleep
                // 0b100: Fast Sleep
                // 0b101: Deep Sleep
                // 0b110: Fast Winkle
                // 0b111: Deep Winkle
                switch(idle_state)
                {

                    case      0x0   :       // Running                                           
                    case      0x2   :       // Nap
                        poll_during_xstop_flag = true;
                        break;

                    case      0x1   :       // Special Wakeup
                    case      0x4   :       // Fast Sleep
                    case      0x5   :       // Deep Sleep
                    case      0x6   :       // Fast Winkle
                    case      0x7   :       // Fast Winkle
                        poll_during_xstop_flag = false;
                        break;

                    default
                           :
                        FAPI_ERR("Invalid Idle State in PMHISTORY: 0x%X ", idle_state);
                        const fapi::Target & EX_IN_ERROR = i_ex_target;
                        const uint64_t & PMHIST = data.getDoubleWord(0);
                        FAPI_SET_HWP_ERROR(rc, RC_PROCPM_SPCWKUP_INVALID_PMHISTORY);
                }
                if (!rc.ok())
                {
                    break;
                }

                // Poll for completion if conditions are right
                if ( (!xstop_flag) || (xstop_flag && poll_during_xstop_flag) )
                {
                    // poll for the set completion
                    pollcount = 0;
                    e_rc=data.flushTo0();
                    E_RC_CHECK(e_rc, rc);

                    while (data.isBitClear(31) && pollcount < special_wakeup_max_polls)
                    {
                        GETSCOM(rc, i_ex_target, EX_PMGP0_0x100F0100, data);
                        FAPI_DBG("  Loop get for PMGP0(31) to goto 1          => 0x%016llx", data.getDoubleWord(0));

                        rc = fapiDelay(special_wakeup_poll_interval*1000, 1000000);
                        if (rc)
                        {
                            break;
                        }
                        pollcount ++ ;
                    }
                    if (!rc.ok())
                    {
                        break;
                    }


                    rc = FAPI_ATTR_GET(ATTR_CHIP_EC_FEATURE_AISS_SPECIAL_WAKEUP,
                                   &i_ex_target,
                                   chipHasAISSSWUP);
                    if (rc)
                    {
                             FAPI_ERR("Error querying Chip EC feature: "
                                 "ATTR_CHIP_EC_FEATURE_PCBS_ERR_RESET");
                        break;
                    }

                    FAPI_INF("AISS Special Wake-up fix is %sbeing performed",
                             (chipHasAISSSWUP ? "NOT " : ""));


                    if (!chipHasAISSSWUP)
                    {
                        // Workaround for HW255321 start here
                        // at timeout time:
                        //  - check for existing external interrupts or malf alerts pending :     PMGP0 bit52
                        //     AND if OHA is in the AISS-FSM-state  P7_SEQ_WAIT_INT_PENDING EX_OHA_RO_STATUS_REG_0x1002000B
                        // If yes - then OHA hangs
                        // To leave this FSM state:
                        //   -  Set  Bit 9  of  OHA_ARCH_IDLE_STATE_REG(  RESET_IDLE_STATE_SEQUENCER).  EX_OHA_ARCH_IDLE_STATE_REG_RWx10020011
                        // This resets the idle sequencer and  force OHA into the DO_NOTHING_STATE ...should be completed in the next cycle
                        //
                        // Continue further down and check special_wakeup completion by checking bit31 of EX_PMGP0_0x100F0100
                        // If set then is OHA awake else error


                        GETSCOM(rc, i_ex_target, EX_PMGP0_0x100F0100, data);

                        if (data.isBitClear(31) && data.isBitSet(52) )
                        {
                            FAPI_DBG("Timed out setting Special wakeup with regular wake-up available, the logical OR of external interrupt and malfunction alert   ... ");
                            FAPI_DBG("Checking for Hang-Situation in AISS-FSM-State P7_SEQ_WAIT_INT_PENDING ... ");
                            FAPI_DBG("Special Wake-up Done NOT asserted (PMGP0(31,52)!! =>0x%016llx", data.getDoubleWord(0));

                            oha_spwkup_flag = 1;

                            rc = FAPI_ATTR_SET(ATTR_PM_SPWUP_OHA_FLAG, &i_ex_target, oha_spwkup_flag);
                            if (rc)
                            {
                                FAPI_ERR("fapiSetAttribute of ATTR_PM_SPWUP_OHA_FLAG with rc = 0x%x", (uint32_t)rc);
                                break;
                            }
                            FAPI_INF("Set OHA special wakeup flag");

                            // Check now if OHA is in the AISS-FSM-state  P7_SEQ_WAIT_INT_PENDING  EX_OHA_RO_STATUS_REG_0x1002000B  (bit 13-19) 0b0011100
                            GETSCOM(rc, i_ex_target, EX_OHA_RO_STATUS_REG_0x1002000B, data);

                            FAPI_DBG("\tCURRENT_AISS_FSM_STATE_VECTOR  (OHA_RO_STATUS(13:19) => 0x%016llx", data.getDoubleWord(0));

                            if (data.isBitClear(13) &&      // 0
                                data.isBitClear(14) &&      // 0
                                data.isBitSet(15)   &&      // 1
                                data.isBitSet(16)   &&      // 1
                                data.isBitSet(17)   &&      // 1
                                data.isBitClear(18) &&      // 0
                                data.isBitClear(19) )       // 0
                            {
                                FAPI_DBG("OHA hanging in AISS-FSM-state P7_SEQ_WAIT_INT_PENDING (0b11100) (OHA_RO_STATUS_REG(13:19) => 0x%016llx", data.getDoubleWord(0));
                                FAPI_DBG("Start reset of IDLE STATE SEQUENCER: Set OHA_ARCH_IDLE_STATE_REG(9)");

                                GETSCOM(rc, i_ex_target, EX_OHA_ARCH_IDLE_STATE_REG_RWx10020011, data);
                                FAPI_DBG("\tEX_OHA_ARCH_IDLE_STATE_REG_RWx10020011 : 0x%016llx", data.getDoubleWord(0));

                                //Set RESET_IDLE_STATE_SEQUENCER  ... Bit 9 of OHA_ARCH_IDLE_STATE_REG
                                e_rc=data.setBit(9);
                                E_RC_CHECK(e_rc, rc);

                                PUTSCOM(rc, i_ex_target, EX_OHA_ARCH_IDLE_STATE_REG_RWx10020011, data);

                                // This resets the idle sequencer and force OHA into the
                                // DO_NOTHING_STATE ... should be completed in the next
                                // cycle since special wakeup is still asserted, OHA should
                                // not leave the DO_NOTHING_STATE

                                // Check again for AISS-FSM-state  P7_SEQ_WAIT_INT_PENDING  EX_OHA_RO_STATUS_REG_0x1002000B  (bit 13-19) 0b11100
                                GETSCOM(rc, i_ex_target, EX_OHA_RO_STATUS_REG_0x1002000B, data);
                                FAPI_DBG("\tCURRENT_AISS_FSM_STATE_VECTOR  (OHA_RO_STATUS(13:19) => 0x%016llx", data.getDoubleWord(0));

                                // We're done accessing the OHA so clear the flag
                                oha_spwkup_flag = 0;
                                rc = FAPI_ATTR_SET(ATTR_PM_SPWUP_OHA_FLAG, &i_ex_target, oha_spwkup_flag);
                                if (rc)
                                {
                                    FAPI_ERR("fapiSetAttribute to clear ATTR_PM_SPWUP_OHA_FLAG with rc = 0x%x", (uint32_t)rc);
                                    // This is a purposeful mid-procedure return
                                    return rc;
                                }
                                FAPI_INF("Cleared OHA special wakeup flag");
                            }
                        }

                        // Check again if special_wakeup completed
                        GETSCOM(rc, i_ex_target, EX_PMGP0_0x100F0100, data);

                    }    // Workaround for HW255321 ends here

                    if (data.isBitClear(31))
                    {
                        FAPI_ERR("Timed out in setting the CPU in Special wakeup    ... ");

                        GETSCOM(rc, i_ex_target, EX_PMGP0_0x100F0100, data);
                        FAPI_DBG("Special Wake-up Done NOT asserted (PMGP0(31)!! =>0x%016llx", data.getDoubleWord(0));
                        const uint64_t& PMGP0 =  data.getDoubleWord(0);

                        // The following are put in the procedure (vs the XML) to capture
                        // for Cronus debug

                        GETSCOM(rc, i_ex_target, spwkup_address , data);
                        FAPI_DBG("  After set of SPWKUP_REG (0x%08llx) => 0x%016llx", spwkup_address, data.getDoubleWord(0));
                        const uint64_t& SP_WKUP_REG_ADDRESS = spwkup_address;
                        const uint64_t& SP_WKUP_REG_VALUE =  data.getDoubleWord(0);

                        GETSCOM(rc, i_ex_target, history_address , data);
                        FAPI_DBG("  History addreess (0x%08llx) => 0x%016llx", history_address, data.getDoubleWord(0));
                        const uint64_t& HISTORY_ADDRESS = history_address;
                        const uint64_t& HISTORY_VALUE =  data.getDoubleWord(0);

                        const uint64_t& POLLCOUNT =  (uint64_t)pollcount;
                        const uint64_t& EX =  (uint64_t)attr_chip_unit_pos;
                        const uint64_t& ENTITY =  (uint64_t)i_entity;
                        PROC_SPCWKUP_OPS& I_OPERATION = i_operation ;

                        const fapi::Target & EX_IN_ERROR = i_ex_target;
                        const fapi::Target & CHIP = l_parentTarget;

                        FAPI_SET_HWP_ERROR(rc, RC_PROCPM_SPCWKUP_TIMEOUT);
                        break;

                    }
                    else
                    {
                        count++ ;
                        FAPI_INF("Special wakeup done is set.  SUCCESS!  ... ");
                    }
                }  // Done checking
                else
                {
                    FAPI_INF("Special wakeup with a checkstop active was attempted to a chiplet in an idle state that cannot succeed");
                    const fapi::Target & EX_TARGET = i_ex_target;
                    FAPI_SET_HWP_ERROR(rc, RC_PROCPM_SPCWKUP_SLW_IN_CHKSTOP);
                    break;
                }
            }
            // Count > 0
            else
            {
                // Check that we really are in special wakeup.
                // If not, the counts are messed up
                GETSCOM(rc, i_ex_target, EX_PMGP0_0x100F0100, data);
                if (data.isBitSet(31))
                {
                    count++ ;
                }
                else
                {
                    FAPI_ERR("Enabling special wakeup failed.");
                    FAPI_ERR("--> Reason is that %s COUNT > 0 but PMGP0(31) is not set", PROC_SPCWKUP_ENTITY_NAMES[i_entity]);
                    FAPI_ERR("  FSP_COUNT = %d , OCC_COUNT = %d , PHYP_COUNT = %d ", fsp_spwkup_count ,occ_spwkup_count ,phyp_spwkup_count);
                    const fapi::Target & EX_TARGET = i_ex_target;
                    const uint64_t & PMGP0 = data.getDoubleWord(0);
                    const uint32_t & ENTITY_COUNT = count;
                    const PROC_SPCWKUP_ENTITY & I_ENTITY = i_entity ;
                    FAPI_SET_HWP_ERROR( rc, RC_PROCPM_SPCWKUP_NOT_SET);
                    break;
                }
            }
        }
        else if (i_operation == SPCWKUP_DISABLE)
        {

            FAPI_INF("Clearing Special Wake-up...");

            // If the OHA flag is set, then any subsequent calls to the this
            // procedure must return a "good" response or elso an infinite
            // loop results for any calling algorithm that first sets
            // special wake-up, does a SCOM, and then clears special
            // wake-up.

            rc = FAPI_ATTR_GET(ATTR_PM_SPWUP_OHA_FLAG, &i_ex_target, oha_spwkup_flag);
            if (rc)
            {
                FAPI_ERR("fapiGetAttribute of ATTR_PM_SPWUP_OHA_FLAG with rc = 0x%x", (uint32_t)rc);
                break;
            }

            if (oha_spwkup_flag)
            {
                 FAPI_INF("OHA special wakeup flag is set so returning with good response to break recursion.  Counts are NOT updated.");
                // This is a purposeful mid-procedure return
                return rc;
            }


            if ( count == 1 )
            {
                GETSCOM(rc, i_ex_target, spwkup_address , data);
                FAPI_DBG("  Before clear of SPWKUP_REG (0x%08llx) => =>0x%016llx",  spwkup_address, data.getDoubleWord(0));

                e_rc=data.flushTo0();
                E_RC_CHECK(e_rc, rc);

                PUTSCOM(rc, i_ex_target, spwkup_address , data);
                FAPI_DBG("  After clear putscom of SPWKUP_REG (0x%08llx) => 0x%016llx", spwkup_address, data.getDoubleWord(0));

                // This puts an inherent delay in the propagation of the reset transition.
                GETSCOM(rc, i_ex_target, spwkup_address , data);
                FAPI_DBG("  After read (delay) of SPWKUP_REG (0x%08llx) 0x%016llx", spwkup_address, data.getDoubleWord(0));

                count -- ;
            }
            else if ( count > 1 )
            {
                FAPI_INF("Other processes have clear Special Wake-up pending.  Chiplet is still in Special Wake-up state.");
                count -- ;
            }
            else // Equal 0
            {

                // Check that we really are NOT in special wakeup.
                // If not, clear that platform bit.  This can occur in Cronus startup
                GETSCOM(rc, i_ex_target, spwkup_address , data);
                FAPI_DBG("  Checking of SPWKUP_REG disable (0x%08llx) => =>0x%016llx",  spwkup_address, data.getDoubleWord(0));

                if (data.isBitSet(0))
                {
                    e_rc=data.flushTo0();
                    E_RC_CHECK(e_rc, rc);

                    PUTSCOM(rc, i_ex_target, spwkup_address , data);
                    FAPI_DBG("  Clearing SPWKUP_REG (0x%08llx) => 0x%016llx", spwkup_address, data.getDoubleWord(0));

                    // This puts an inherent delay in the propagation of the reset transition.
                    GETSCOM(rc, i_ex_target, spwkup_address , data);
                    FAPI_DBG("  After read (delay) of SPWKUP_REG (0x%08llx) 0x%016llx", spwkup_address, data.getDoubleWord(0));
                }
            }

            GETSCOM(rc, i_ex_target, spwkup_address , data);
            FAPI_DBG("  After configuring  SPWKUP_REG value     =>0x%016llx", data.getDoubleWord(0));

        }
        else if (i_operation == SPCWKUP_FORCE_DEASSERT)
        {

            GETSCOM(rc, i_ex_target, spwkup_address , data);
            FAPI_DBG("  Before clear of SPWKUP_REG (0x%08llx) => =>0x%016llx",  spwkup_address, data.getDoubleWord(0));

            e_rc=data.flushTo0();
            E_RC_CHECK(e_rc, rc);

            PUTSCOM(rc, i_ex_target, spwkup_address , data);
            FAPI_DBG("  After clear putscom of SPWKUP_REG (0x%08llx) => 0x%016llx", spwkup_address, data.getDoubleWord(0));

            // This puts an inherent delay in the propagation of the reset transition.
            GETSCOM(rc, i_ex_target, spwkup_address , data);
            FAPI_DBG("  After read (delay) of SPWKUP_REG (0x%08llx) 0x%016llx", spwkup_address, data.getDoubleWord(0));

            count = 0;
        }
        else
        {
            FAPI_ERR("ENABLE, DISABLE or INIT must be specified. Operation %x", i_operation );
            PROC_SPCWKUP_OPS & I_OPERATION = i_operation ;
            FAPI_SET_HWP_ERROR(rc, RC_PROCPM_SPCWKUP_CODE_BAD_OP);
            break;
        }

        /////////////////////////////////////////////////
        // Update the attributes
        /////////////////////////////////////////////////

        if ( i_entity == OCC )
        {
            occ_spwkup_count  = count ;
            rc = FAPI_ATTR_SET(ATTR_PM_SPWUP_OCC, &i_ex_target, occ_spwkup_count );
            if (rc)
            {
                FAPI_ERR("fapiSetAttribute of ATTR_PM_SPWUP_OCC with rc = 0x%x", (uint32_t)rc);
                break;
            }
        }
        else if (i_entity == FSP)
        {
            fsp_spwkup_count = count ;
            rc = FAPI_ATTR_SET(ATTR_PM_SPWUP_FSP, &i_ex_target, fsp_spwkup_count );
            if (rc)
            {
                FAPI_ERR("fapiSetAttribute of ATTR_PM_SPWUP_FSP with rc = 0x%x", (uint32_t)rc);
                break;
            }
        }
        else if (i_entity == PHYP)
        {
            phyp_spwkup_count = count;
            rc = FAPI_ATTR_SET(ATTR_PM_SPWUP_PHYP, &i_ex_target, phyp_spwkup_count );
            if (rc)
            {
                FAPI_ERR("fapiSetAttribute of ATTR_PM_SPWUP_PHYP with rc = 0x%x", (uint32_t)rc);
                break;
            }
        }

        FAPI_INF ("  FSP_COUNT = %d , OCC_COUNT = %d , PHYP_COUNT = %d ", fsp_spwkup_count ,occ_spwkup_count ,phyp_spwkup_count);


    } while (0);

    // Clean up the OHA flag as it should not be set out of this exit (normal
    // and error) path.  Note:  there is ia mid-procedure return above.
    oha_rc = FAPI_ATTR_GET(ATTR_PM_SPWUP_OHA_FLAG, &i_ex_target, oha_spwkup_flag);
    if (oha_rc)
    {
        FAPI_ERR("fapiGetAttribute of ATTR_PM_SPWUP_OHA_FLAG with rc = 0x%x", (uint32_t)oha_rc);
    }
    else
    {
        if (oha_spwkup_flag)
        {
            oha_spwkup_flag = 0;

            oha_rc = FAPI_ATTR_SET(ATTR_PM_SPWUP_OHA_FLAG, &i_ex_target, oha_spwkup_flag);
            if (oha_rc)
            {
                FAPI_ERR("fapiSetAttribute of ATTR_PM_SPWUP_OHA_FLAG with rc = 0x%x", (uint32_t)oha_rc);
            }

            FAPI_ERR("Clearing OHA flag attribute upon procedure exit.  This is NOT expected");
            PROC_SPCWKUP_OPS& I_OPERATION = i_operation ;
            const uint64_t& EX =  (uint64_t)attr_chip_unit_pos;
            const uint64_t& ENTITY =  (uint64_t)i_entity;
            const uint64_t& PHYP_SPCWKUP_COUNT = (uint64_t)phyp_spwkup_count;
            const uint64_t& FSP_SPCWKUP_COUNT  = (uint64_t)fsp_spwkup_count;
            const uint64_t& OCC_SPCWKUP_COUNT  = (uint64_t)occ_spwkup_count;
            FAPI_SET_HWP_ERROR(oha_rc, RC_PROCPM_SPCWKUP_OHA_FLAG_SET_ON_EXIT);
        }
    }

    // Exit with the proper return code.  rc has priority over oha_rc as it indicates
    // the first failure.
    if (!rc.ok())
    {
        return rc ;
    }
    else if (!oha_rc.ok())
    {
        return oha_rc ;
    }
    else
    {
        return rc;
    }
}


} //end extern C
