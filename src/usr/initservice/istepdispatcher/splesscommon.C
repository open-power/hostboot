/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/initservice/istepdispatcher/splesscommon.C $          */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2016                        */
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
/**
 *  @file splesscommon.C
 *
 *  Routines to access SPLESS Command and
 *  and SPLESS Status interfaces
 *
 *  Currently SPLess only supports the one command 0x00, this rewrite will
 *  allow support of other SPLess commands.
 *
 */

/******************************************************************************/
// Includes
/******************************************************************************/
#include    <stdint.h>
#include    <stdio.h>
#include    <string.h>
#include    <initservice/mboxRegs.H>
//  $$$$$$$ undefine this before checking in....
//#define SPLESS_DEBUG    1

#ifdef  SPLESS_DEBUG
    #include    <kernel/console.H>          // printk DEBUG
#endif

#include    <sys/mmio.h>                    //  mmio_scratch_read()
#include    <devicefw/userif.H>        //  deviceRead(), deviceWrite()
#include     <errl/errlentry.H>

#include    <targeting/common/attributes.H>        //  ISTEP_MODE attribute
#include    <targeting/common/targetservice.H>

#include    "splesscommon.H"
#include    <config.h>
#include    <initservice/bootconfigif.H>
#include    <errl/errlmanager.H>

// external reference
namespace   INITSERVICE
{
    extern trace_desc_t *g_trac_initsvc;
namespace   SPLESS
{

using namespace   TARGETING;

//  extern declarations for regs.

/**
 * @def g_SPLess_pMasterProcChip
 *
 *  pointer to master proc chip used for deviceRead deviceWrite
 */
TARGETING::Target* g_SPLess_pMasterProcChip =   NULL;


/******************************************************************************/
//  SPLESS support functions
/******************************************************************************/

/******************************************************************************/
//  SPLESS Command functions
/******************************************************************************/

void    readCmdSts( SPLessCmd   &io_rcmd )
{
    // Do this once and save it...
    if ( g_SPLess_pMasterProcChip  == NULL )
    {
        (void)TARGETING::targetService().masterProcChipTargetHandle(
                                                       g_SPLess_pMasterProcChip );
    }

#ifdef CONFIG_BMC_AST2400
    errlHndl_t err = NULL;
    INITSERVICE::BOOTCONFIG::istepControl_t istepCtl;
    memset (&istepCtl, 0x0, sizeof(istepCtl));
    err = INITSERVICE::BOOTCONFIG::readIstepControl(istepCtl);
    if(err)
    {
        TRACFCOMP( g_trac_initsvc, "Error reading SIO regs... blindly continuing" );
        errlCommit(err, INITSVC_COMP_ID);
    }
    else
    {
        io_rcmd.bytes[HDR] = istepCtl.istepControl;
        io_rcmd.bytes[STS] = istepCtl.istepStatus;
        io_rcmd.istep = istepCtl.istepMajorNumber;
        io_rcmd.substep = istepCtl.istepMinorNumber;
    }

#else
    // $$ save -io_rcmd.val64 = mmio_scratch_read(MMIO_SCRATCH_IPLSTEP_COMMAND);

    //  command reg is GMB2EC is mailbox scratchpad 3 { regs 0 - 3 }.
    size_t  op_size =   sizeof( uint64_t );
    uint64_t op = 0x0;
    DeviceFW::deviceRead(
              g_SPLess_pMasterProcChip,
              &(op),
              op_size,
              DEVICE_SCOM_ADDRESS( MBOX_SCRATCH_REG3 )  );

    io_rcmd.word = (op >>32);
#endif

#ifdef  SPLESS_DEBUG
    printk( "readCmd 0x%x\n", io_rcmd.word );
#endif
}


void    writeCmdSts( SPLessCmd    i_rcmd )
{
    // Do this once and save it...
    if ( g_SPLess_pMasterProcChip  == NULL )
    {
        (void)TARGETING::targetService().masterProcChipTargetHandle(
                                                       g_SPLess_pMasterProcChip );
    }

#ifdef CONFIG_BMC_AST2400
    errlHndl_t err = NULL;
    INITSERVICE::BOOTCONFIG::istepControl_t istepCtl;
    memset (&istepCtl, 0x0, sizeof(istepCtl));
    istepCtl.istepControl = i_rcmd.bytes[HDR];
    istepCtl.istepStatus  = i_rcmd.bytes[STS];
    TRACFCOMP( g_trac_initsvc, "Write istep control" );

    err = BOOTCONFIG::writeIstepControl(istepCtl);
    if(err)
    {
        TRACFCOMP( g_trac_initsvc, "Error writing SIO regs... blindly continuing" );
        errlCommit(err, INITSVC_COMP_ID);
    }

#else

    // save mmio_scratch_write( MMIO_SCRATCH_IPLSTEP_COMMAND, i_rcmd.val64 );

    //  command reg is GMB2EC is mailbox scratchpad 3 { regs 0 - 3 }.
    size_t  op_size =   sizeof( uint64_t );
    uint64_t op = (static_cast<uint64_t>(i_rcmd.word))<<32;
    DeviceFW::deviceWrite(
               g_SPLess_pMasterProcChip,
               &(op),
               op_size,
               DEVICE_SCOM_ADDRESS( MBOX_SCRATCH_REG3 )  );
#endif

#ifdef  SPLESS_DEBUG
    printk( "writeCmd 0x%x\n", i_rcmd.word );
#endif
}

};   // namespace
};   // end namespace    INITSERVICE

