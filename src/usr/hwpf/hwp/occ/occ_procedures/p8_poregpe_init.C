/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/occ/occ_procedures/p8_poregpe_init.C $       */
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

// $Id: p8_poregpe_init.C,v 1.5 2013/09/25 22:36:40 stillgs Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/p8_poregpe_init.C,v $
//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
//------------------------------------------------------------------------------
// *! OWNER NAME: Greg Still         Email: stillgs@us.ibm.com
// *!
/// \file p8_poregpe_init.C
/// \brief Configure or reset the targeted GPE0 and/or GPE1
///
///
/// \todo add to required proc ENUM requests
///
/// High-level procedure flow:
/// \verbatim
///
///     Check for valid parameters
///     if PM_CONFIG {
///        Do nothing (done by OCC programs)
///     } else if PM_RESET {
///         for each GPE,
///             set and then reset bit 0 in the GPEx_RESET_REGISTER
///
///     }
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
#include "p8_poregpe_init.H"

#ifdef FAPIECMD
extern "C" {
#endif


using namespace fapi;

// ----------------------------------------------------------------------
// Constant definitions
// ----------------------------------------------------------------------

// ----------------------------------------------------------------------
// Global variables
// ----------------------------------------------------------------------

// ----------------------------------------------------------------------
// Function prototypes
// ----------------------------------------------------------------------

fapi::ReturnCode poregpe_reset(const Target& i_target, const uint32_t engine);

// ----------------------------------------------------------------------
// Function definitions
// ----------------------------------------------------------------------


/// \param[in] i_target Chip target
/// \param[in] mode     Control mode for the procedure
///                     (PM_CONFIG, PM_INIT, PM_RESET)
/// \param[in] engine   Targeted engine:  GPE0, GPE1, GPEALL

/// \retval FAPI_RC_SUCCESS
/// \retval ERROR defined in xml
fapi::ReturnCode
p8_poregpe_init(const Target& i_target, uint32_t mode, uint32_t engine)
{
    fapi::ReturnCode    l_rc;

    do
    {
        FAPI_INF("Executing p8_poregpe_init in mode %x for engine %x....",
                  mode, engine);

        if (!(engine == GPE0 || engine == GPE1 || engine == GPEALL) )
        {

            FAPI_ERR("Unknown engine passed to p8_poregpe_init. Engine %x ....",
                  engine);
            const fapi::Target & CHIP = i_target;
            const uint32_t & IENGINE = engine;
            FAPI_SET_HWP_ERROR(l_rc, RC_PROCPM_GPE_BAD_ENGINE);
            break;
        }

        /// -------------------------------
        /// Configuration:  perform translation of any Platform Attributes into
        /// Feature Attributes that are applied during Initalization
        if (mode == PM_CONFIG)
        {
          FAPI_INF("PORE-GPE configuration...");
          FAPI_INF("---> None is defined...done by OCC firmware");
        }

        /// -------------------------------
        /// Initialization:  perform order or dynamic operations to initialize
        /// the GPEs using necessary Platform or Feature attributes.
        else if (mode == PM_INIT)
        {
          FAPI_INF("PORE-GPE initialization...");
          FAPI_INF("---> None is defined...done by OCC firmware");
        }

        /// -------------------------------
        /// Reset:  perform reset of GPE engines so that they can reconfigured
        /// and reinitialized
        else if (mode == PM_RESET)
        {
            // GPE0
            if (engine == GPE0 || engine == GPEALL)
            {
                l_rc = poregpe_reset(i_target, GPE0);
                if (!l_rc.ok())
                {
                    break;
                }
            }

            if (engine == GPE1 || engine == GPEALL)
            {
                l_rc = poregpe_reset(i_target, GPE1);
                if (!l_rc.ok())
                {
                    break;
                }
            }

        }

        /// -------------------------------
        /// Unsupported Mode

        else
        {
            FAPI_ERR("Unknown mode passed to p8_poregpe_init. Mode %x ....", mode);
            const fapi::Target & CHIP = i_target;
            uint32_t & IMODE = mode;
            FAPI_SET_HWP_ERROR(l_rc, RC_PROCPM_GPE_CODE_BAD_MODE);
        }
    } while(0);

    return l_rc;
}

//------------------------------------------------------------------------------
// PORE GPE Reset Function
//------------------------------------------------------------------------------
fapi::ReturnCode
poregpe_reset(const Target& i_target, const uint32_t engine)
{
    fapi::ReturnCode    l_rc;
    uint32_t            e_rc = 0;
    ecmdDataBufferBase  data(64);
    ecmdDataBufferBase  polldata(64);
    const uint32_t      max_polls = 8;
    uint32_t            poll_count;
    bool                wait_state_detected;
    bool                poll_loop_error = false;
    uint64_t            control_reg;
    uint64_t            reset_reg;
    uint64_t            status_reg;



    FAPI_INF("PORE-GPE reset...Engine: %x", engine);

    do
    {
        // Set the address offset values based on which engine is being operated
        // on
        if (engine == GPE0)
        {
            control_reg = PORE_GPE0_CONTROL_0x00060001;
            reset_reg   = PORE_GPE0_RESET_0x00060002;
            status_reg  = PORE_GPE0_STATUS_0x00060000;
        }
        else if (engine == GPE1)
        {
            control_reg = PORE_GPE1_CONTROL_0x00060021;
            reset_reg   = PORE_GPE1_RESET_0x00060022;
            status_reg  = PORE_GPE1_STATUS_0x00060020;
        }
        else
        {
            FAPI_ERR("Invalid engine parm passed to poregpe_reset");
            const fapi::Target & CHIP = i_target;
            const uint32_t & IENGINE = engine;
            FAPI_SET_HWP_ERROR(l_rc, RC_PROCPM_GPE_BAD_ENGINE);
            break;
        }

        //  Reset the GPEsusing the Reset Register bits 0 and 1.
        //  Note:  This resets ALL registers (including debug registers) with
        //  the exception of Error Mask

        // set PORE run bit to stop
        l_rc=fapiGetScom(i_target, control_reg, data);
        if(!l_rc.ok())
        {
           FAPI_ERR("Scom error reading PORE_GPE%x_CONTROL_%08llx", engine, control_reg);
           break;
        }

        e_rc=data.setBit(0);
        if (e_rc)
        {
            FAPI_ERR("Error (0x%x) setting up ecmdDataBufferBase", e_rc);
            l_rc.setEcmdError(e_rc);
            break;
        }

        l_rc=fapiPutScom(i_target, control_reg, data);
        if(!l_rc.ok())
        {
            FAPI_ERR("Scom error writing PORE_GPE%x_CONTROL_%08llx", engine, control_reg);
            break;
        }

        // Reset PORE (state machines and PIBMS_DBG registers) and PIB2OCI
        // interface write Reset_Register(0:1) with 0b11 to trigger the reset.
        // Check that these are cleared to 0 to validate the reset occured.
        e_rc |= data.flushTo0();
        e_rc |= data.setBit(0, 2);
        if (e_rc)
        {
            FAPI_ERR("Error (0x%x) setting up ecmdDataBufferBase", e_rc);
            l_rc.setEcmdError(e_rc);
            break;
        }

        FAPI_DBG("PORE-GPE%x Reset value: 0x%16llX", engine, data.getDoubleWord(0));

        l_rc=fapiPutScom(i_target, reset_reg, data);
        if(!l_rc.ok())
        {
            FAPI_ERR("Scom error writing PORE_GPE%x_CONTROL", engine);
            break;
        }

        // poll until PORE has returned to WAIT state 3:6=0b0001
        wait_state_detected = false;
        for (poll_count=0; poll_count<max_polls; poll_count++)
        {
            l_rc=fapiGetScom(i_target, status_reg, polldata);
            if(l_rc)
            {
                FAPI_ERR("Scom error reading PORE_GPE%x_STATUS", engine);
                poll_loop_error = true;
                break;
            }

            if(polldata.isBitClear(3, 3) && polldata.isBitSet(6))
            {
               wait_state_detected = true;
               break;
            }
            else
            {
              fapiDelay(1000, 10);
            }
        }
        // Break if a FAPI error occured in the polling loop
        if (poll_loop_error)
        {
             break;
        }

        if(!wait_state_detected)
        {
          FAPI_ERR("GPE%x reset failed ", engine);
          const fapi::Target & CHIP = i_target;
          uint32_t           & POLLCOUNT = poll_count;
          const uint32_t     & MAXPOLLS = max_polls;
          const uint32_t     & IENGINE = engine;
          FAPI_SET_HWP_ERROR(l_rc, RC_PROCPM_GPE_RESET_TIMEOUT);
        }

    } while(0);

    return l_rc;
}

#ifdef FAPIECMD
} //end extern C
#endif
