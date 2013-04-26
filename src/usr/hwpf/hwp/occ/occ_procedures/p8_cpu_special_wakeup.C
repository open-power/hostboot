/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/occ/occ_procedures/p8_cpu_special_wakeup.C $ */
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
// $Id: p8_cpu_special_wakeup.C,v 1.7 2013/04/16 12:14:14 pchatnah Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/p8_cpu_special_wakeup.C,v $
//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
//------------------------------------------------------------------------------
// *! OWNER NAME: Greg Still         Email: stillgs@us.ibm.com
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
//------------------------------------------------------------------------------


// ----------------------------------------------------------------------
// Includes
// ----------------------------------------------------------------------

#include "p8_pm.H"
#include "p8_cpu_special_wakeup.H"
#include <ecmdDataBufferBase.H>
//#include <ecmdClientCapi.H>
#include <fapi.H>


extern "C" {

using namespace fapi;


/// \param[in] i_target     EX Target
/// \param[in] i_operation  ENABLE, DISABLE, INIT
/// \param[in] entity       Entity bit to use (OCC, PHYP, FSP)

/// \retval PM_SUCCESS if something good happens,
/// \retval PM_PROCPM_SPCWKUP* otherwise
fapi::ReturnCode
p8_cpu_special_wakeup(  const fapi::Target& i_target,
                        PROC_SPCWKUP_OPS i_operation ,
                        PROC_SPCWKUP_ENTITY i_entity )

{
    fapi::ReturnCode    l_rc;
    uint32_t            e_rc = 0;
    ecmdDataBufferBase  data(64);
    ecmdDataBufferBase  polldata(64);
    //TODO RTC: 71328 - hack to indicate unused
    bool                __attribute__((unused)) error_flag = false;
    //TODO RTC: 71328 - needs to be const
    const char* PROC_SPCWKUP_ENTITY_NAMES[] = 
      {
	"HOST",
	"FSP",
	"OCC",
	"PHYP",
	"SPW_ALL"
      };        
    


    //TODO RTC: 71328 - needs to be const
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

    uint32_t            special_wakeup_timeout = 25;

    ///  Get an attribute that defines the special wake-up polling interval
    ///         (binary in milliseconds).
    uint32_t            special_wakeup_poll_interval = 5;

    uint32_t            pollcount = 0;
    uint32_t            count = 0;

    std::vector<fapi::Target>      l_chiplets;
    std::vector<Target>::iterator  itr;

    uint64_t            SP_WKUP_REG_ADDRS;

    //--------------------------------------------------------------------------
    // Read the counts of different ENTITY (FSP,OCC,PHYP) from the Attributes
    //--------------------------------------------------------------------------

    uint32_t            PHYP_SPWKUP_COUNT = 0;
    uint32_t            FSP_SPWKUP_COUNT  = 0;
    uint32_t            OCC_SPWKUP_COUNT  = 0;

    do
    {
    
        FAPI_INF("Executing p8_cpu_special_wakeup %s for %s ...",
                    PROC_SPCWKUP_OPS_NAMES[i_operation],
                    PROC_SPCWKUP_ENTITY_NAMES[i_entity]);
                    
        // Initialize the attributes to 0.
        if (i_operation == SPCWKUP_INIT)
        {
            FAPI_INF("Initializing ATTR_PM_SPWUP_FSP");
            l_rc = FAPI_ATTR_SET(ATTR_PM_SPWUP_FSP, &i_target, FSP_SPWKUP_COUNT);
            if (l_rc)
            {
                FAPI_ERR("fapiSetAttribute of ATTR_PM_SPWUP_FSP with l_rc = 0x%x", (uint32_t)l_rc);
            }

            FAPI_INF("Initializing ATTR_PM_SPWUP_OCC");
            l_rc = FAPI_ATTR_SET(ATTR_PM_SPWUP_OCC, &i_target, OCC_SPWKUP_COUNT);
            if (l_rc)
            {
                 FAPI_ERR("fapiSetAttribute of ATTR_PM_SPWUP_OCC with l_rc = 0x%x", (uint32_t)l_rc);
                break;
            }

            FAPI_INF("Initializing ATTR_PM_SPWUP_PHYP");
            l_rc = FAPI_ATTR_SET(ATTR_PM_SPWUP_PHYP, &i_target, PHYP_SPWKUP_COUNT);
            if (l_rc)
            {
                 FAPI_ERR("fapiSetAttribute of ATTR_PM_SPWUP_PHYP with l_rc = 0x%x", (uint32_t)l_rc);
                break;
            }

            // Leave the procedure
            break;
        }

        //--------------------------------------------------------------------------
        //           Checking the ENTITY who raised this OPERATION
        //--------------------------------------------------------------------------

        fapi::Target l_parentTarget;
        uint8_t attr_chip_unit_pos = 0;

        // Get the parent chip to target the registers
        l_rc = fapiGetParentChip(i_target, l_parentTarget);
        if (l_rc)
        {
            break;    // throw error
        }

        // Check whether system is checkstopped
        l_rc=fapiGetScom(l_parentTarget, PCBMS_INTERRUPT_TYPE_REG_0x000F001A, data);
        if( data.isBitSet( 2 ) )
        {
            FAPI_ERR( "This chip is xstopped, so ignoring the special wakeup request\n" );
            FAPI_SET_HWP_ERROR(l_rc, RC_PROCPM_CHKSTOP);
            break;
        }

        // Get the core number
        l_rc = FAPI_ATTR_GET(ATTR_CHIP_UNIT_POS, &i_target, attr_chip_unit_pos);
        if (l_rc)
        {
            FAPI_ERR("fapiGetAttribute of ATTR_CHIP_UNIT_POS with l_rc = 0x%x", (uint32_t)l_rc);
            break;
        }
        //    CORE_NUM = attr_chip_unit_pos;
        FAPI_DBG("Core number = %d", attr_chip_unit_pos);

        // Read the Attributes to know the Special_wake counts form each entities .
        // This should be different for different EX chiplets.
        l_rc = FAPI_ATTR_GET(ATTR_PM_SPWUP_FSP, &i_target, FSP_SPWKUP_COUNT);
        if (l_rc)
        {
             FAPI_ERR("fapiGetAttribute of ATTR_PM_SPWUP_FSP with l_rc = 0x%x", (uint32_t)l_rc);
            break;
        }

        l_rc = FAPI_ATTR_GET(ATTR_PM_SPWUP_OCC, &i_target, OCC_SPWKUP_COUNT );
        if (l_rc)
        {
             FAPI_ERR("fapiGetAttribute of ATTR_PM_SPWUP_FSP with l_rc = 0x%x", (uint32_t)l_rc);
            break;
        }

        l_rc = FAPI_ATTR_GET(ATTR_PM_SPWUP_PHYP,&i_target , PHYP_SPWKUP_COUNT );
        if (l_rc)
        {
             FAPI_ERR("fapiGetAttribute of ATTR_PM_SPWUP_FSP with l_rc = 0x%x", (uint32_t)l_rc);
            break;
        }

        /// Calculate the maximum number of polls until a timeout is thrown
        special_wakeup_max_polls = special_wakeup_timeout / special_wakeup_poll_interval;

        uint64_t EX_PMGP0_0x1X0F0100 =  EX_PMGP0_0x100F0100 +
                                        (attr_chip_unit_pos  * 0x01000000);

        // Process counts based on the calling entity
        if (i_entity == OCC)
        {
            count = OCC_SPWKUP_COUNT ;
            FAPI_INF("OCC count before = %d" , count);
            SP_WKUP_REG_ADDRS = PM_SPECIAL_WKUP_OCC_0x100F010C +
                                (attr_chip_unit_pos  * 0x01000000) ;
        }
        else if (i_entity == FSP)
        {
            count = FSP_SPWKUP_COUNT ;
            FAPI_INF("FSP count before = %d" , count);
            SP_WKUP_REG_ADDRS = PM_SPECIAL_WKUP_FSP_0x100F010B +
                                (attr_chip_unit_pos  * 0x01000000);
        }
        else if (i_entity == PHYP)
        {
            count = PHYP_SPWKUP_COUNT ;
            FAPI_INF("PHYP count before = %d" , count);
            SP_WKUP_REG_ADDRS = PM_SPECIAL_WKUP_PHYP_0x100F010D +
                                (attr_chip_unit_pos  * 0x01000000);
        }
        else
        {
            FAPI_ERR("Unknown entity passed to proc_special_wakeup. Entity %x ....", i_entity);
            //    I_ENTITY = i_entity;
            PROC_SPCWKUP_ENTITY & I_ENTITY = i_entity ;
            FAPI_SET_HWP_ERROR(l_rc, RC_PROCPM_SPCWKUP_CODE_BAD_ENTITY);
            break;
        }

        /////////////////////////////////////////////////////////////////////////////
        //           Checking the type of OPERATION and process the request
        /////////////////////////////////////////////////////////////////////////////

        l_rc=fapiGetScom(l_parentTarget, EX_PMGP0_0x1X0F0100, data);
        if(l_rc)
        {
            break;
        }

        if (i_operation == SPCWKUP_ENABLE)
        {
            FAPI_INF("Setting Special Wake-up  ...") ;

            //    FAPI_INF("Count value after the increment is  %x  ...", count);
            if (count == 0)
            {

                GETSCOM(i_target,  SP_WKUP_REG_ADDRS, data);

                e_rc  = data.flushTo0();
                e_rc |= data.setBit(0);
                E_RC_CHECK(e_rc, l_rc);

                PUTSCOM(i_target,  SP_WKUP_REG_ADDRS, data);

                // poll for the set completion
                pollcount = 0;
                e_rc=data.flushTo0();
                E_RC_CHECK(e_rc, l_rc);

                while (data.isBitClear(31) && pollcount < special_wakeup_max_polls)
                {
                    GETSCOM(l_parentTarget, EX_PMGP0_0x1X0F0100, data);
                    FAPI_DBG("  Loop get for PMGP0(31) to goto 1          => 0x%16llx", data.getDoubleWord(0));

                    fapiDelay(special_wakeup_poll_interval*1000, 1000000);
                    pollcount ++ ;

                }
                if (data.isBitClear(31))
                {
                    FAPI_ERR("Timed out in setting the CPU in Special wakeup    ... ");
                    FAPI_SET_HWP_ERROR(l_rc, RC_PROCPM_SPCWKUP_TIMEOUT);
                    break;
                }
                GETSCOM(l_parentTarget, EX_PMGP0_0x1X0F0100, data);
                FAPI_DBG("  Special Wake-up Done asserted (PMGP0(31)!! =>0x%16llx", data.getDoubleWord(0));

                GETSCOM(i_target, EX_OHA_RO_STATUS_REG_0x1002000B, data);
                FAPI_DBG("  Special Wake-up complete (OHA_RO_STATUS(1)!! => 0x%16llx", data.getDoubleWord(0));

                GETSCOM(l_parentTarget, SP_WKUP_REG_ADDRS , data);
                FAPI_DBG("  After set of SPWKUP_REG (0x%08llx) => 0x%16llx", SP_WKUP_REG_ADDRS, data.getDoubleWord(0));

            }
            count++ ;

        }
        else if (i_operation == SPCWKUP_DISABLE)
        {

            FAPI_INF("Clearing Special Wake-up...");

            if ( count == 1 )
            {
                GETSCOM(l_parentTarget, SP_WKUP_REG_ADDRS , data);
                FAPI_DBG("  Before clear of SPWKUP_REG (0x%08llx) => =>0x%16llx",  SP_WKUP_REG_ADDRS, data.getDoubleWord(0));

                e_rc=data.flushTo0();
                E_RC_CHECK(e_rc, l_rc);

                PUTSCOM(l_parentTarget, SP_WKUP_REG_ADDRS , data);
                FAPI_DBG("  After clear putscom of SPWKUP_REG (0x%08llx) => 0x%16llx", SP_WKUP_REG_ADDRS, data.getDoubleWord(0));

                // This puts an inherent delay in the propagation of the reset transition.
                GETSCOM(l_parentTarget, SP_WKUP_REG_ADDRS , data);
                FAPI_DBG("  After read (delay) of SPWKUP_REG (0x%08llx) 0x%16llx", SP_WKUP_REG_ADDRS, data.getDoubleWord(0));

                count -- ;
            }
            else if ( count > 1 )
            {
                FAPI_INF("Other processes having clear Special Wake-up pending.  Chiplet is still in Special Wake-up state.");
                count -- ;
            }
            else
            {
                FAPI_ERR("Illegal Special wake up operation : already Disabled on this platform  %x", i_entity);
                FAPI_ERR ("  FSP_COUNT = %d , OCC_COUNT = %d , PHYP_COUNT = %d ", FSP_SPWKUP_COUNT ,OCC_SPWKUP_COUNT ,PHYP_SPWKUP_COUNT);
                PROC_SPCWKUP_OPS & I_OPERATION = i_operation ;
                FAPI_SET_HWP_ERROR(l_rc, RC_PROCPM_SPCWKUP_CODE_BAD_OP);
                break;
            }

            GETSCOM(l_parentTarget, SP_WKUP_REG_ADDRS , data);
            FAPI_DBG("  After configuring  SPWKUP_REG value     =>0x%16llx", data.getDoubleWord(0));

        }
        else
        {
            FAPI_ERR("Please specify operation either ENABLE or DISABLE. Operation %x", i_operation );
            PROC_SPCWKUP_OPS & I_OPERATION = i_operation ;
            FAPI_SET_HWP_ERROR(l_rc, RC_PROCPM_SPCWKUP_CODE_BAD_OP);
            break;
        }

        /////////////////////////////////////////////////
        // Update the attributes
        /////////////////////////////////////////////////

        if ( i_entity == OCC )
        {
            OCC_SPWKUP_COUNT  = count ;
            l_rc = FAPI_ATTR_SET(ATTR_PM_SPWUP_OCC, &i_target, OCC_SPWKUP_COUNT );
            if (l_rc)
            {
                FAPI_ERR("fapiSetAttribute of ATTR_PM_SPWUP_OCC with l_rc = 0x%x", (uint32_t)l_rc);
                break;
            }
        }
        else if (i_entity == FSP)
        {
            FSP_SPWKUP_COUNT = count ;
            l_rc = FAPI_ATTR_SET(ATTR_PM_SPWUP_FSP, &i_target, FSP_SPWKUP_COUNT );
            if (l_rc)
            {
                FAPI_ERR("fapiSetAttribute of ATTR_PM_SPWUP_FSP with l_rc = 0x%x", (uint32_t)l_rc);
                break;
            }
        }
        else if (i_entity == PHYP)
        {
            PHYP_SPWKUP_COUNT = count;
            l_rc = FAPI_ATTR_SET(ATTR_PM_SPWUP_PHYP, &i_target, PHYP_SPWKUP_COUNT );
            if (l_rc)
            {
                FAPI_ERR("fapiSetAttribute of ATTR_PM_SPWUP_PHYP1 with l_rc = 0x%x", (uint32_t)l_rc);
                break;
            }
        }

        FAPI_INF ("  FSP_COUNT = %d , OCC_COUNT = %d , PHYP_COUNT = %d ", FSP_SPWKUP_COUNT ,OCC_SPWKUP_COUNT ,PHYP_SPWKUP_COUNT);
    } while (0);

    return l_rc ;
}


} //end extern C
