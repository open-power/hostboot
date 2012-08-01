/*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/usr/hwpf/hwp/core_activate/proc_prep_master_winkle/proc_prep_master_winkle.C $
 *
 *  IBM CONFIDENTIAL
 *
 *  COPYRIGHT International Business Machines Corp. 2012
 *
 *  p1
 *
 *  Object Code Only (OCO) source materials
 *  Licensed Internal Code Source Materials
 *  IBM HostBoot Licensed Internal Code
 *
 *  The source code for this program is not published or other-
 *  wise divested of its trade secrets, irrespective of what has
 *  been deposited with the U.S. Copyright Office.
 *
 *  Origin: 30
 *
 *  IBM_PROLOG_END_TAG
 */
// -*- mode: C++; c-file-style: "linux";  -*-
// $Id: proc_prep_master_winkle.C,v 1.7 2012/08/01 18:58:38 jeshua Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/proc_prep_master_winkle.C,v $
//------------------------------------------------------------------------------
// *|
// *! (C) Copyright International Business Machines Corp. 2012
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
// *|
// *! TITLE       : proc_prep_master_winkle.C
// *! DESCRIPTION : Prepares for the master core to winkle
// *!
// *! OWNER NAME  : Jeshua Smith            Email: jeshua@us.ibm.com
// *!
// *! Overview:
// *!    Wait for SBE ready
// *!    Start SBE deadman timer
// *!    *Enter winkle*
// *!
// *!    Note: Hostboot should always run with useRealSBE = true
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include "proc_prep_master_winkle.H"

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------

extern "C"
{



//------------------------------------------------------------------------------
// function: proc_prep_master_winkle
//     Wait for SBE ready
//     Start SBE deadman timer
//     *Enter winkle*
//
// parameters: i_target  => chip target
// returns: FAPI_RC_SUCCESS if operation was successful, else error
//------------------------------------------------------------------------------
    fapi::ReturnCode proc_prep_master_winkle(const fapi::Target & i_target,
                                             bool useRealSBE = true)
    {
        // data buffer to hold register values
        ecmdDataBufferBase data(64);

        // return codes
        uint32_t rc_ecmd = 0;
        fapi::ReturnCode rc;

        // mark function entry
        FAPI_INF("Entry\n");

        do
        {

            // Wait for SBE ready
            // ie. SBE running, and istep num and substep num correct
            if( useRealSBE )
            {

//  $$$$$
//  $$$$$ mww need to set up action file to fill in the SBE regs
//  $$$$$       These scoms are not set to the right value.
//  $$$$$       In simics, we need an action file to set them up.
//  $$$$$
                FAPI_INF("mww read PORE_SBE_CONTROL_0x000E0001");
                rc = fapiGetScom(i_target, PORE_SBE_CONTROL_0x000E0001, data);
                if(!rc.ok())
                {
                    FAPI_ERR("Scom error reading SBE STATUS\n");
                    break;
                }

                // $$$$$    @todo HACK
                data.clearBit( 0 ) ;

                if( data.isBitSet( 0 ) )
                {
                    FAPI_ERR("SBE isn't running when it should be\n");
                    const fapi::Target & CHIP_IN_ERROR = i_target;
                    ecmdDataBufferBase & SBE_STATUS = data;
                    FAPI_SET_HWP_ERROR(rc, RC_PROC_PREP_MASTER_WINKLE_SBE_NOT_RUNNING);
                    break;
                }
            }

            FAPI_INF("mww read MBOX_SBEVITAL_0x0005001C");

            rc = fapiGetScom(i_target, MBOX_SBEVITAL_0x0005001C, data);
            if(!rc.ok())
            {
                FAPI_ERR("Scom error reading SBE VITAL\n");
                break;
            }


            uint32_t istep_num = 0;
            uint8_t substep_num = 0;
            rc_ecmd |= data.extractToRight(&istep_num,
                                           istep_num_bit_position,
                                           istep_num_bit_length);
            rc_ecmd |= data.extractToRight(&substep_num,
                                           substep_num_bit_position,
                                           substep_num_bit_length);
            if(rc_ecmd)
            {
                FAPI_ERR("Error (0x%x) setting up ecmdDataBufferBase", rc_ecmd);
                rc.setEcmdError(rc_ecmd);
                break;
            }

            //  $$  @todo HACK
            istep_num   =   0x0f01;
            substep_num =   0x01;

            if( istep_num != proc_sbe_trigger_winkle_istep_num )
            {
                FAPI_ERR("Expected istep num %llX but found %X\n",
                         proc_sbe_trigger_winkle_istep_num,
                         istep_num );
                const fapi::Target & CHIP_IN_ERROR = i_target;
                ecmdDataBufferBase & SBE_VITAL = data;
                FAPI_SET_HWP_ERROR(rc, RC_PROC_PREP_MASTER_WINKLE_BAD_ISTEP_NUM);
                break;
            }
            if( substep_num != substep_sbe_ready )
            {
                FAPI_ERR("Expected substep num %X but found %X\n",
                         substep_sbe_ready,
                         substep_num );
                const fapi::Target & CHIP_IN_ERROR = i_target;
                ecmdDataBufferBase & SBE_VITAL = data;
                FAPI_SET_HWP_ERROR(rc, RC_PROC_PREP_MASTER_WINKLE_BAD_SUBSTEP_NUM);
                break;
            }

            FAPI_INF("SBE is ready for master to enter winkle\n");

            //Start the deadman timer
            substep_num = substep_deadman_start;
            rc_ecmd |= data.insertFromRight(&substep_num,
                                            substep_num_bit_position,
                                            substep_num_bit_length);
            if(rc_ecmd)
            {
                FAPI_ERR("Error (0x%x) setting up ecmdDataBufferBase", rc_ecmd);
                rc.setEcmdError(rc_ecmd);
                break;
            }
            FAPI_INF("mww write MBOX_SBEVITAL_0x0005001C");
            rc = fapiPutScom(i_target, MBOX_SBEVITAL_0x0005001C, data);
            if(!rc.ok())
            {
                FAPI_ERR("Scom error updating SBE VITAL\n");
                break;
            }

            //Enter winlke
            FAPI_INF("HB should enter winkle now, FSP should execute proc_force_winkle now\n");

        } while (0);

        // mark function exit
        FAPI_INF("Exit");
        return rc;
    }

} // extern "C"
/* Local Variables: */
/* c-basic-offset: 4 */
/* End: */
