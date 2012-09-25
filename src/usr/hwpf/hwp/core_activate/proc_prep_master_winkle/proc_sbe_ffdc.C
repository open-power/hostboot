/*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/usr/hwpf/hwp/core_activate/proc_prep_master_winkle/proc_sbe_ffdc.C $
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
// $Id: proc_sbe_ffdc.C,v 1.4 2012/05/23 18:48:50 jeshua Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/proc_sbe_ffdc.C,v $
//------------------------------------------------------------------------------
// *|
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
// *|
// *! TITLE       : proc_sbe_ffdc.C
// *! DESCRIPTION : Log data for SBE fails (FAPI)
// *!
// *! OWNER NAME  : Jeshua Smith   Email: jeshua@us.ibm.com
// *! BACKUP NAME : Andreas Koenig Email: koenig@de.ibm.com
// *!
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------

#include "proc_sbe_ffdc.H"

extern "C" {

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// function: proc_sbe_ffdc
// parameters: i_target => proc chip target
// returns: FAPI_RC_SUCCESS if operation was successful, else error
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// FFDC Procedure
//------------------------------------------------------------------------------
    fapi::ReturnCode proc_sbe_ffdc(const fapi::Target& i_target,
                                   fapi::ReturnCode & o_rc)
{
    fapi::ReturnCode rc;
    ecmdDataBufferBase dataBuff(32);
    uint32_t data_32 = 0;
    uint64_t data_64 = 0;
    const uint16_t END_CFAMS = 0xFFFFull;
    const uint64_t END_SCOMS = 0xFFFFFFFFFFFFFFFFull;

    // mark HWP entry
    FAPI_IMP("proc_sbe_ffdc: Entering ...");

    uint16_t cfams [] =
    {
        FSI_STATUS_0x1007,
        FSI_GP3_0x2812   ,
        FSI_GP4_0x2813   ,
        FSI_GP5_0x2814   ,
        FSI_GP6_0x2815   ,
        FSI_GP7_0x2816   ,
        FSI_GP8_0x2817   ,
        FSI_GP3MIR_0x281B,
        END_CFAMS
    };

    int cfam_index = 0;
    do
    {
        //Collect SBE Cfams
        rc = fapiGetCfamRegister( i_target, cfams[cfam_index], dataBuff );
        if( rc )
        {
            break;
        }
        data_32 = dataBuff.getWord( 0 );
        // TODO. When the new way to collect register FFDC is introduced in Cronus,
        // this HWP will vanish and XML will be written to collect the data
        // RTC Issue 50362
        // fapi::ReturnCodeFfdc::addEIFfdc(o_rc, data_32);
        cfam_index++;
    } while (cfams[cfam_index] != END_CFAMS);

    if( !rc )
    {
        uint64_t scoms [] =
            {
                PORE_SBE_STATUS_0x000E0000            ,
                PORE_SBE_CONTROL_0x000E0001           ,
                PORE_SBE_RESET_0x000E0002             ,
                PORE_SBE_ERROR_MASK_0x000E0003        ,
                PORE_SBE_PRV_BASE_ADDRESS0_0x000E0004 ,
                PORE_SBE_PRV_BASE_ADDRESS1_0x000E0005 ,
                PORE_SBE_OCI_BASE_ADDRESS0_0x000E0006 ,
                PORE_SBE_OCI_BASE_ADDRESS1_0x000E0007 ,
                PORE_SBE_TABLE_BASE_ADDR_0x000E0008   ,
                PORE_SBE_EXE_TRIGGER_0x000E0009       ,
                PORE_SBE_SCRATCH0_0x000E000A          ,
                PORE_SBE_SCRATCH1_0x000E000B          ,
                PORE_SBE_SCRATCH2_0x000E000C          ,
                PORE_SBE_IBUF_01_0x000E000D           ,
                PORE_SBE_IBUF_2_0x000E000E            ,
                PORE_SBE_DBG0_0x000E000F              ,
                PORE_SBE_DBG1_0x000E0010              ,
                PORE_SBE_PC_STACK0_0x000E0011         ,
                PORE_SBE_PC_STACK1_0x000E0012         ,
                PORE_SBE_PC_STACK2_0x000E0013         ,
                PORE_SBE_ID_FLAGS_0x000E0014          ,
                PORE_SBE_DATA0_0x000E0015             ,
                PORE_SBE_MEMORY_RELOC_0x000E0016      ,
                PORE_SBE_I2C_E0_PARAM_0x000E0017      ,
                PORE_SBE_I2C_E1_PARAM_0x000E0018      ,
                PORE_SBE_I2C_E2_PARAM_0x000E0019      ,
                PIBMEM_STATUS_0x00088005              ,
                TP_CLK_STATUS_0x01030008              ,
                END_SCOMS
            };

        int scom_index = 0;
        do
        {
            //Collect SBE Scoms
            rc = fapiGetScom( i_target, scoms[scom_index], dataBuff );
            if( rc )
            {
                break;
            }
            data_64 = dataBuff.getDoubleWord( 0 );
            // TODO. When the new way to collect register FFDC is introduced in Cronus,
            // this HWP will vanish and XML will be written to collect the data
            // fapi::ReturnCodeFfdc::addEIFfdc(o_rc, data_64);

            scom_index++;
        } while (scoms[scom_index] != END_SCOMS);
    }

    FAPI_IMP("proc_sbe_ffdc: Exiting ...");
    return rc;
}

} //end extern C
/* Local Variables: */
/* c-basic-offset: 4 */
/* End: */
