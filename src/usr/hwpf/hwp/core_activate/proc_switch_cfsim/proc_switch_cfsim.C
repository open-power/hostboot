/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/core_activate/proc_switch_cfsim/proc_switch_cfsim.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2014                        */
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
// -*- mode: C++; c-file-style: "linux";  -*-
// $Id: proc_switch_cfsim.C,v 1.7 2012/05/03 10:41:46 rkoester Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/proc_switch_cfsim.C,v $
//------------------------------------------------------------------------------
// *|
// *! (C) Copyright International Business Machines Corp. 2012
// *! All Rights Reserved -- Property of IBM
// *! ***  ***
// *|
// *! TITLE       : proc_switch_cfsim.C
// *! DESCRIPTION : Configure the PLLs
// *!
// *! OWNER NAME  : Ralph C. Koester         Email: rkoester@de.ibm.com
// *! Backup      : Todd A. Venton           Email: venton@us.ibm.com
// *!
// *!
// *! General Description:
// *!
// *!   The purpose of this procedure is to reset fences in CFAM
// *!
// *!   via the mailbox register of the PIB
// *!
// *!   set the sbetrigger reg via SCOM write
// *|
// *! Procedure Prereq : none
// *!
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include "proc_switch_cfsim.H"


//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------

extern "C"
{



//------------------------------------------------------------------------------
// function: utility subroutine to manipulate GP4 of CFAM via MBOX
// parameters: io_data       => Input data buffer
//             i_reset       => Input parameter (RESET)
// returns: FAPI_RC_SUCCESS if operation was successful, else error
//------------------------------------------------------------------------------
fapi::ReturnCode proc_reset_fence(ecmdDataBufferBase & io_data, bool i_RESET)
{

    fapi::ReturnCode rc;
    uint32_t rc_ecmd = 0;

    FAPI_DBG("proc_reset_fence: Start");

    // mark function entry
    FAPI_INF("Entry, RESET=%s\n\n" ,
             i_RESET? "true":"false");

    do
    {

       if(i_RESET==true){
         // manipulate external buffer
         rc_ecmd |= io_data.clearBit(3,3);
       }
       if (rc_ecmd)
       {
           FAPI_ERR("proc_reset_fence: Error 0x%x setting up data buffer to RESET all fences",
                 rc_ecmd);
           rc.setEcmdError(rc_ecmd);
           break;
       }

    } while(0);

    FAPI_DBG("proc_reset_fence: End");

    return rc;
}

//------------------------------------------------------------------------------
// function: utility subroutine to manipulate GP4 of CFAM via MBOX
// parameters: io_data            => Input data buffer
//             i_reset_opb_switch => Input parameter (RESET_OPB_SWITCH)
// returns: FAPI_RC_SUCCESS if operation was successful, else error
//------------------------------------------------------------------------------
fapi::ReturnCode proc_reset_opb( ecmdDataBufferBase & io_data,
                                 bool i_RESET_OPB_SWITCH)
{

    fapi::ReturnCode rc;
    uint32_t rc_ecmd = 0;

    FAPI_DBG("proc_reset_opb: Start");

    // mark function entry
    FAPI_INF("Entry, RESET_OPB_SWITCH=%s\n\n" ,
             i_RESET_OPB_SWITCH? "true":"false");


    do
    {

       if(i_RESET_OPB_SWITCH==true){
         // manipulate external buffer
         rc_ecmd |= io_data.setBit(1);
       }
       if (rc_ecmd)
       {
           FAPI_ERR("proc_reset_opb: Error 0x%x setting up data buffer to RESET both  OPB switches",
                    rc_ecmd);
           rc.setEcmdError(rc_ecmd);
           break;
       }

    } while(0);

    FAPI_DBG("proc_reset_opb: End");

    return rc;
}


//------------------------------------------------------------------------------
// function: utility subroutine to manipulate GP4 of CFAM via MBOX
// // parameters: io_data       => Input data buffer
//                i_fence_fsi0  => Input parameter (FENCE_FSI0)
// returns: FAPI_RC_SUCCESS if operation was successful, else error
//------------------------------------------------------------------------------
fapi::ReturnCode proc_fence_fsi0( ecmdDataBufferBase & io_data,
                                  bool i_FENCE_FSI0)
{


    fapi::ReturnCode rc;
    uint32_t rc_ecmd = 0;

    FAPI_DBG("proc_fence_fsi0: Start");

    // mark function entry
    FAPI_INF("Entry, FENCE_FSI0=%s\n\n" ,
             i_FENCE_FSI0? "true":"false");


    do
    {

       if(i_FENCE_FSI0==true){
         // manipulate external buffer
         rc_ecmd |= io_data.setBit(3);
       }
       if (rc_ecmd)
       {
           FAPI_ERR("proc_fence_fsi0: Error 0x%x setting up data buffer to bring-up the fence for FSI0 port",
                    rc_ecmd);
           rc.setEcmdError(rc_ecmd);
           break;
    }

    } while(0);

    FAPI_DBG("proc_fence_fsi0: End");

    return rc;
}


//------------------------------------------------------------------------------
// function: utility subroutine to manipulate GP4 of CFAM via MBOX
// parameters: io_data         => Input data buffer
//             i_fence_pib_nh  => Input parameter (FENCE_PIB_NH)
// returns: FAPI_RC_SUCCESS if operation was successful, else error
//------------------------------------------------------------------------------
fapi::ReturnCode proc_pib_nh( ecmdDataBufferBase & io_data,
                              bool i_FENCE_PIB_NH)
{

    fapi::ReturnCode rc;
    uint32_t rc_ecmd = 0;

    FAPI_DBG("proc_pib_nh: Start");

    // mark function entry
    FAPI_INF("Entry, FENCE_PIB_NH=%s\n\n" ,
             i_FENCE_PIB_NH? "true":"false");


    do
    {

       if(i_FENCE_PIB_NH==true){
         // manipulate external buffer
         rc_ecmd |= io_data.setBit(4);
       }
       if (rc_ecmd)
       {
           FAPI_ERR("proc_pib_nh: Error 0x%x setting up data buffer to bring-up the fence for the none HOST PIB port",
                    rc_ecmd);
           rc.setEcmdError(rc_ecmd);
           break;
    }

    } while(0);

    FAPI_DBG("proc_pib_nh: End");

    return rc;
}


//------------------------------------------------------------------------------
// function: utility subroutine to manipulate GP4 of CFAM via MBOX
// parameters: io_data        => Input data buffer
//             i_fence_pib_h  => Input parameter (FENCE_PIB_H)
// returns: FAPI_RC_SUCCESS if operation was successful, else error
//------------------------------------------------------------------------------
fapi::ReturnCode proc_pib_h( ecmdDataBufferBase & io_data,
                             bool i_FENCE_PIB_H)
{


    fapi::ReturnCode rc;
    uint32_t rc_ecmd = 0;

    FAPI_DBG("proc_pib_h: Start");

    // mark function entry
    FAPI_INF("Entry, FENCE_PIB_H=%s\n\n" ,
             i_FENCE_PIB_H? "true":"false");


    do
    {

       if(i_FENCE_PIB_H==true){
         // manipulate external buffer
         rc_ecmd |= io_data.setBit(5);
         FAPI_DBG("data set bit done");
       }
       if (rc_ecmd)
       {
           FAPI_ERR("proc_pib_h: Error 0x%x setting up data buffer to bring-up the fence for the HOST PIB port",
                    rc_ecmd);
           rc.setEcmdError(rc_ecmd);
           break;
       }

    } while(0);

    FAPI_DBG("proc_pib_h: End");

    return rc;
}

//------------------------------------------------------------------------------
// function: utility subroutine to manipulate GP4 of CFAM via MBOX
// parameters: io_data       => Input data buffer
//             i_fence_fsi1  => Input parameter (FENCE_FSI1)
// returns: FAPI_RC_SUCCESS if operation was successful, else error
//------------------------------------------------------------------------------
fapi::ReturnCode proc_fence_fsi1( ecmdDataBufferBase & io_data,
                                  bool i_FENCE_FSI1)
{

    // return codes
    uint32_t rc_ecmd = 0;
    fapi::ReturnCode rc;


    FAPI_DBG("proc_fence_fsi1: Start");

    // mark function entry
    FAPI_INF("Entry, FENCE_FSI1=%s\n\n" ,
             i_FENCE_FSI1? "true":"false");

    do
    {

       if(i_FENCE_FSI1==true){
         // manipulate external buffer
         rc_ecmd |= io_data.setBit(6);
       }
       if (rc_ecmd)
       {
           FAPI_ERR("proc_fence_fsi1: Error 0x%x setting up data buffer to bring-up the fence for the FSI-1 port",
                    rc_ecmd);
           rc.setEcmdError(rc_ecmd);
           break;
       }

    } while(0);

    FAPI_DBG("proc_fence_fsi1: End");

    return rc;
}

//------------------------------------------------------------------------------
// function: utility subroutine to manipulate GP4 of CFAM via MBOX
// parameters: io_data          => Input data buffer
//             i_fence_pib_sw1  => Input parameter (FENCE_PIB_SW1)
// returns: FAPI_RC_SUCCESS if operation was successful, else error
//------------------------------------------------------------------------------
fapi::ReturnCode proc_pib_sw1( ecmdDataBufferBase & io_data ,
                               bool i_FENCE_PIB_SW1)
{

    fapi::ReturnCode rc;
    uint32_t rc_ecmd = 0;

    FAPI_DBG("proc_pib_sw1: Start");

    // mark function entry
    FAPI_INF("Entry, FENCE_PIB_SW1=%s\n\n" ,
             i_FENCE_PIB_SW1? "true":"false");

//  // temporary for debug only
//  if (i_FENCE_PIB_SW1==true) { FAPI_DBG(" Debug only, print: FENCE_PIB_SW1==true ");}
//  else { FAPI_DBG(" Debug only, print: FENCE_PIB_SW1==false ") ; }


    do
    {

       if(i_FENCE_PIB_SW1==true){
         // manipulate external buffer
         rc_ecmd |= io_data.setBit(7);
       }
       if (rc_ecmd)
       {
           FAPI_ERR("proc_pib_sw1: Error 0x%x setting up data buffer to bring-up the PIB_SW1 fence",
                    rc_ecmd);
           rc.setEcmdError(rc_ecmd);
           break;
       }

    } while(0);

    FAPI_DBG("proc_pib_sw1: End");

    return rc;
}
//------------------------------------------------------------------------------
// Hardware Procedure
//------------------------------------------------------------------------------
fapi::ReturnCode proc_switch_cfsim(const fapi::Target& i_target,
                                   bool RESET,
                                   bool RESET_OPB_SWITCH,
                                   bool FENCE_FSI0,
                                   bool FENCE_PIB_NH,
                                   bool FENCE_PIB_H,
                                   bool FENCE_FSI1,
                                   bool FENCE_PIB_SW1)
{
    fapi::ReturnCode rc;
    ecmdDataBufferBase manipulate(64);

    // mark HWP entry
    FAPI_INF("proc_switch_cfsim: Entering ...");

    do
    {
       rc = fapiGetScom(i_target, MBOX_FSIGP4_0x00050013, manipulate);
       if (rc)
       {
            FAPI_ERR("proc_switch_cfsim: fapiGetScom error (MBOX_FSIGP4_0x00050013)");
            break;
       }

        // start manipulation based on parsed inputs

        FAPI_DBG("Starting manipulating the fences ...");

        rc = proc_reset_fence(
             manipulate,
             RESET);
             if (rc)
             {
                break;
             }

        rc = proc_reset_opb(
             manipulate,
             RESET_OPB_SWITCH);
             if (rc)
             {
                break;
             }

        rc = proc_fence_fsi0(
             manipulate,
             FENCE_FSI0);
             if (rc)
             {
                break;
             }

        rc = proc_pib_nh(
             manipulate,
             FENCE_PIB_NH);
             if (rc)
             {
                break;
             }

        rc = proc_pib_h(
             manipulate,
             FENCE_PIB_H);
             if (rc)
             {
                break;
             }

        rc = proc_fence_fsi1(
             manipulate,
             FENCE_FSI1);
             if (rc)
             {
                break;
             }

        rc = proc_pib_sw1(
             manipulate,
             FENCE_PIB_SW1);
             if (rc)
             {
                break;
             }

        FAPI_DBG("proc_switch_cfsim: manipulating the fences done.");


       rc = fapiPutScom(i_target, MBOX_FSIGP4_0x00050013, manipulate);
       if (rc)
       {
            FAPI_ERR("proc_switch_cfsim: fapiPutScom error (MBOX_FSIGP4_0x00050013)");
            break;
       }



    } while (0); // end do

        // mark function exit
        FAPI_INF("proc_switch_cfsim: Exiting ...");
        return rc;
}  // end FAPI procedure proc_switch_cfsim

} // extern "C"
/* Local Variables: */
/* c-basic-offset: 4 */
/* End: */
