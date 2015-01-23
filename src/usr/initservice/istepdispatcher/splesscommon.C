/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/initservice/istepdispatcher/splesscommon.C $          */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2015                        */
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
// #define SPLESS_DEBUG    1

#ifdef  SPLESS_DEBUG
    #include    <kernel/console.H>          // printk DEBUG
#endif

#include    <sys/mmio.h>                    //  mmio_scratch_read()
#include    <devicefw/userif.H>        //  deviceRead(), deviceWrite()

#include    <targeting/common/attributes.H>        //  ISTEP_MODE attribute
#include    <targeting/common/targetservice.H>

#include    "splesscommon.H"


// external reference
namespace   INITSERVICE
{
    extern trace_desc_t *g_trac_initsvc;
}   // end namespace    INITSERVICE



namespace   SPLESS
{

using namespace   TARGETING;

//  extern declarations for regs.
extern  uint64_t    g_SPLess_Command_Reg;
extern  uint64_t    g_SPLess_Status_Reg;


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

void    readCmd( SPLessCmd   &io_rcmd )
{
    // Do this once and save it...
    if ( g_SPLess_pMasterProcChip  == NULL )
    {
        (void)TARGETING::targetService().masterProcChipTargetHandle(
                                                       g_SPLess_pMasterProcChip );
    }

    // $$ save - mem io_rcmd.val64   =   g_SPLess_Command_Reg;
    // $$ save -io_rcmd.val64 = mmio_scratch_read(MMIO_SCRATCH_IPLSTEP_COMMAND);

    //  command reg is GMB2EC is mailbox scratchpad 3 { regs 0 - 3 }.
    size_t  op_size =   sizeof( uint64_t );
    DeviceFW::deviceRead(
              g_SPLess_pMasterProcChip,
              &(io_rcmd.val64),
              op_size,
              DEVICE_SCOM_ADDRESS( MBOX_SCRATCH_REG3 )  );

#ifdef  SPLESS_DEBUG
    printk( "readCmd hi 0x%x\n", io_rcmd.hi32 );
    printk( "readCmd lo 0x%x\n", io_rcmd.lo32 );
#endif
}


void    writeCmd( SPLessCmd    &io_rcmd )
{
    // Do this once and save it...
    if ( g_SPLess_pMasterProcChip  == NULL )
    {
        (void)TARGETING::targetService().masterProcChipTargetHandle(
                                                       g_SPLess_pMasterProcChip );
    }

    // save - mem g_SPLess_Command_Reg    =   io_rcmd.val64;
    // save mmio_scratch_write( MMIO_SCRATCH_IPLSTEP_COMMAND, io_rcmd.val64 );

    //  command reg is GMB2EC is mailbox scratchpad 3 { regs 0 - 3 }.
    size_t  op_size =   sizeof( uint64_t );
    DeviceFW::deviceWrite(
               g_SPLess_pMasterProcChip,
               &(io_rcmd.val64),
               op_size,
               DEVICE_SCOM_ADDRESS( MBOX_SCRATCH_REG3 )  );

#ifdef  SPLESS_DEBUG
    printk( "writeCmd hi 0x%x\n", io_rcmd.hi32 );
    printk( "writeCmd lo 0x%x\n", io_rcmd.lo32 );
#endif
}


/******************************************************************************/
//  SPLESS Status
/******************************************************************************/

void    readSts(   SPLessSts   &io_rsts )
{
    // Do this once and save it...
    if ( g_SPLess_pMasterProcChip  == NULL )
    {
        (void)TARGETING::targetService().masterProcChipTargetHandle(
                                                       g_SPLess_pMasterProcChip );
    }

    // $$ save - mem io_rsts.val64   =   g_SPLess_Status_Reg;
    // $$ io_rsts.val64 = mmio_scratch_read(MMIO_SCRATCH_IPLSTEP_STATUS);

    // status reg (Hi 32) is now GMB2E8 is mailbox scratchpad 2  {regs 0 - 3 }
    size_t  op_size =   sizeof( uint64_t );
    DeviceFW::deviceRead(
              g_SPLess_pMasterProcChip,
              &(io_rsts.val64),
              op_size,
              DEVICE_SCOM_ADDRESS( MBOX_SCRATCH_REG2 )  );
    // status reg lo is GMB2E4 - mailbox scratchpad 1  { regs 0 -3 }
    uint64_t    swap    =   0;
    DeviceFW::deviceRead(
              g_SPLess_pMasterProcChip,
              &(swap),
              op_size,
              DEVICE_SCOM_ADDRESS( MBOX_SCRATCH_REG1 )  );
    io_rsts.lo32    =
        static_cast<uint32_t>( ((swap >> 32) & 0x00000000ffffffff) );

#ifdef  SPLESS_DEBUG
    printk( "readSts hi 0x%x\n", io_rsts.hi32 );
    printk( "readSts lo 0x%x\n", io_rsts.lo32 );
#endif
}


void    writeSts(  SPLessSts   &io_rsts )
{
    // Do this once and save it...
    if ( g_SPLess_pMasterProcChip  == NULL )
    {
        (void)TARGETING::targetService().masterProcChipTargetHandle(
                                                       g_SPLess_pMasterProcChip );
    }

    size_t  op_size =   sizeof( uint64_t );

    //  Write Status reg first
    // status reg lo is GMB2E4 - mailbox scratchpad 1  { regs 0 -3 }
    uint64_t    swap    =
        ((static_cast<uint64_t>(io_rsts.lo32) << 32 ) & 0xffffffff00000000) ;
    DeviceFW::deviceWrite(
              g_SPLess_pMasterProcChip,
              &(swap),
              op_size,
              DEVICE_SCOM_ADDRESS( MBOX_SCRATCH_REG1 )  );

    // $$ save - mem g_SPLess_Status_Reg =   io_rsts.val64;
    // $$ save mmio_scratch_write( MMIO_SCRATCH_IPLSTEP_STATUS, io_rsts.val64 );
    DeviceFW::deviceWrite(
              g_SPLess_pMasterProcChip,
              &(io_rsts.val64),
              op_size,
              DEVICE_SCOM_ADDRESS( MBOX_SCRATCH_REG2 )  );

#ifdef  SPLESS_DEBUG
    printk( "writeSts hi 0x%x\n", io_rsts.hi32 );
    printk( "writeSts lo 0x%x\n", io_rsts.lo32 );
#endif
}

}   // namespace

