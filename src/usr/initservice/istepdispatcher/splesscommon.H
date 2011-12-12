//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/initservice/istepdispatcher/splesscommon.H $
//
//  IBM CONFIDENTIAL
//
//  COPYRIGHT International Business Machines Corp. 2011
//
//  p1
//
//  Object Code Only (OCO) source materials
//  Licensed Internal Code Source Materials
//  IBM HostBoot Licensed Internal Code
//
//  The source code for this program is not published or other-
//  wise divested of its trade secrets, irrespective of what has
//  been deposited with the U.S. Copyright Office.
//
//  Origin: 30
//
//  IBM_PROLOG_END

#ifndef __ISTEPDISP_SPLESS_COMMON_H
#define __ISTEPDISP_SPLESS_COMMON_H
/**
 *  @file splesscommon.H
 *
 *  Prototypes for routines to access SPLESS Command and
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

//  undefine this before checking in....
// #define SPLESS_DEBUG    1

#ifdef  SPLESS_DEBUG
    #include    <kernel/console.H>                 // printk DEBUG
#endif

#include    <sys/mmio.h>                    //  mmio_scratch_read()


// external reference
namespace   INITSERVICE
{
    extern trace_desc_t *g_trac_initsvc;
}   // end namespace    INITSERVICE


/******************************************************************************/
//  SPLESS Command and Status Prototypes
/******************************************************************************/

/**
 * @namespace   SPLESSCMD
 *
 * Contains functions to manipulate the SPLESS Command Register
 *
 */
namespace   SPLESS
{

/**
 * @note    Since ISTEP_MODE attribute is nonvolatile (persists across boots),
 *          we must have a way to turn the attribute both ON and OFF - we
 *          cannot depend on the FSP to do it since we may not have a FSP.
 */
const   uint64_t    ISTEP_MODE_ON_SIGNATURE     =   0x4057b0074057b007;
const   uint64_t    ISTEP_MODE_OFF_SIGNATURE    =   0x700b7504700b7504;

/**
 * @enum
 *  SPLess Task return codes
 *
 * task return codes for SPless single step
 * @note    future errors will be passed from task_create() and task_exec()
 *          and should be documented in errno.h
 *
 */
enum    {
    SPLESS_TASKRC_INVALID_ISTEP     =   -3,     // invalid istep or substep
    SPLESS_TASKRC_LAUNCH_FAIL       =   -4,     // failed to launch the task
    SPLESS_TASKRC_RETURNED_ERRLOG   =   -5,     // istep returned an errorlog
    SPLESS_TASKRC_TERMINATED        =   -6,     // terminated the polling loop

    SPLESS_INVALID_COMMAND          =   10,    // invalid command from user console
};

/**
 * @note declare global regs to implement SPLess.
 *  These replace the SCOM regs that are accessed by mmio; the reason we
 *  are changing this is that there is no support at present for read/writing
 *  SCOM in the Debug Framework.
 *  This will have to be modified again when we get to Secure Boot
 *
 *  @todo An review issue came up about when and how these are updated -
 *  While hostboot is running in SIMICS or VBU, the user console (i.e. a
 *  perl script, see src/build/vpo/hb_istep) will stop the instruction clock,
 *  write a command to g_SPLess_Command_Reg, and then restart the clock.
 *
 *  Q1) In non-VPO mode (real FSP) are we always going to stop instructions
 *      to the processor to modify these variables?
 *  A:  Yes, at this writing.  If this changes, we should revisit this
 *      implementation.
 *
 *  Q1a) Do these memory locations need to be accessed atomically (i.e. using
 *      __sync_add_and_fetch() and/or isync()/sync() )?
 *  A:  No, not at this writing.
 *
 *  Q2) When we stop instructions to the processor is the instruction pipeline
 *      and load/store queues flushed?
 *
 *  A:  No.  The stop commands used in the simulator user console should
 *      quiesce the processor; this should guarantee that there are no
 *      outstanding loads or stores.
 */
extern  uint64_t    g_SPLess_Command_Reg;
extern  uint64_t    g_SPLess_Status_Reg;
extern  uint64_t    g_SPLess_IStepMode_Reg;

/**
 * @note    SPLess commands, and masks for the status.  Currently we only
 *  support one command through the SPLess interface.
 *
 */
const   uint8_t     SPLESS_SINGLE_ISTEP_CMD         =   0x00;
const   uint64_t    SPLESS_SINGLE_STEP_STS_MASK     =   0x00000000ffffffff;

/**
 * @brief   init ISTEP_MODE attribute
 *
 *  @return nothing
 *
 */
inline  void initIStepMode( )
{
    using namespace TARGETING;
    uint64_t    l_readData      =   0;
    Target      *l_pTopLevel    =   NULL;
    TargetService& l_targetService = targetService();

    (void) l_targetService.getTopLevelTarget(l_pTopLevel);
    if (l_pTopLevel == NULL)
    {
        TRACFCOMP( INITSERVICE::g_trac_initsvc, "Top level handle was NULL" );
        // drop through, default of attribute is is false
    }
    else
    {
        // got a pointer to Targeting, complete setting the flag
        // $$ save l_readData  =   mmio_scratch_read( MMIO_SCRATCH_IPLSTEP_CONFIG );
        l_readData  =   g_SPLess_IStepMode_Reg;

#ifdef  SPLESS_DEBUG
        printk( "IStepMode Reg  = 0x%p, 0x%lx\n",   &g_SPLess_IStepMode_Reg, l_readData );
        printk( "Status Reg     = 0x%p\n",          &g_SPLess_Status_Reg );
        printk( "Command Reg    = 0x%p\n",          &g_SPLess_Command_Reg );
#endif
        TRACDCOMP( INITSERVICE::g_trac_initsvc,
                "IStepMode Reg = 0x%llx",
                l_readData );

        // check for IStep Mode signature(s)
        if ( l_readData == ISTEP_MODE_ON_SIGNATURE )
        {
            l_pTopLevel->setAttr<ATTR_ISTEP_MODE> (true );

            TRACDCOMP( INITSERVICE::g_trac_initsvc,
                    "ISTEP_MODE attribute set to TRUE." );
        }
        else if ( l_readData == ISTEP_MODE_OFF_SIGNATURE )
        {
            l_pTopLevel->setAttr<ATTR_ISTEP_MODE> ( false );

            TRACDCOMP( INITSERVICE::g_trac_initsvc,
                    "ISTEP_MODE attribute set to FALSE." );
        }
        else
        {
            TRACFCOMP( INITSERVICE::g_trac_initsvc,
                    "unknown ISTEP_MODE signature: 0x%llx",
                    l_readData );
        }
    }

}

/**
 * @struct  CommandHdr
 *
 * Command Header for all SPless commands.  2 bytes long.
 * Bit numbers are in ppc notation, where bit 0 is the most significant bit.
 *      Go Bit : bit 0 (ppc notation, msbit)
 *          - set to 1 by the user to start the IStep
 *          - cleared to 0 by HostBoot
 *      Reserved: bit 1: always 0
 *      Sequence #: bits 2-7
 *      Command Number: bits 8:15
 *
 *
 */
struct  CommandHdr
{
    bool            gobit:1;
    uint8_t         reserved0:1;
    uint8_t         seqnum:6;
    uint8_t         cmdnum;

}   __attribute__((packed));


/**
 * @union   SPLessCmd
 *
 *  64-bit "template" struct for the SPLess command.
 *  This will be read in and used to extract the header info, then "cast"
 *  to the correct command.
 */
union   SPLessCmd
{
    uint64_t    val64;
    struct
    {
        CommandHdr      hdr;
        uint16_t        reserved1;
        uint32_t        reserved2;
    }   __attribute__((packed));

    //  init struct to 0
    SPLessCmd() : val64(0) {};
} ;


/**
 * @union   SPLessSingleIStepCmd
 *
 * Implement Command 0x00,  run Istep/Substep
 *
 * Send IStep and SubStep number(s) to run.
 *
 */
union   SPLessSingleIStepCmd
{
    uint64_t    val64;
    struct
    {
        CommandHdr      hdr;
        uint8_t         istep;
        uint8_t         substep;
        uint32_t        reserved;
    }   __attribute__((packed));

    SPLessSingleIStepCmd() : val64(0)  {};


    SPLessSingleIStepCmd( const SPLessCmd &i_cmd )
    :   val64(i_cmd.val64)  { };

private:
    // disable assignment constructor
    SPLessSingleIStepCmd& operator=(const SPLessSingleIStepCmd& i_right);

} ;


/**
 * @brief   Read the command register and return a filled-in SPLessCmd struct
 *
 *  @param[in,out] io_rcmd  -   reference to a SPLessCmd struct
 *
 *  @return none
 */
inline  void    readCmd( SPLessCmd   &io_rcmd )
{

    // $$ save io_rcmd.val64 = mmio_scratch_read(MMIO_SCRATCH_IPLSTEP_COMMAND);
    io_rcmd.val64   =   g_SPLess_Command_Reg;
#ifdef  SPLESS_DEBUG
    printk( "readCmd 0x%lx\n", g_SPLess_Command_Reg );
#endif
}


/**
    * @brief   Write a filled-in command struct to the command reg.
    *
    *  Normally the user writes the command reg; this is only used to
    *  init the command reg at the beginning
    *
    *  @param[in] i_rcmd    -   reference to a filled-in SPLessCmd reg
    *
    *  @return none
    */
inline  void    writeCmd( SPLessCmd    &io_rcmd )
{

    // $$ save mmio_scratch_write( MMIO_SCRATCH_IPLSTEP_COMMAND, io_rcmd.val64 );
    g_SPLess_Command_Reg    =   io_rcmd.val64;
#ifdef  SPLESS_DEBUG
    printk( "writeCmd 0x%lx\n", g_SPLess_Command_Reg );
#endif
}



/******************************************************************************/
//  SPLESS Status  Prototypes
/******************************************************************************/

/**
 * @struct  StatusHdr
 *
 * header for the Status Reg returned by all SPLess Commands.
 *
 * Bit numbers are in ppc notation, where bit 0 is the most significant bit.
 *  *  Running bit, bit 0 (ppc notation, msbit):
 *      = 1  when IStep is running
 *      = 0   when IStep is finished
 *  Ready bit, bit 1:
 *      = 1 when IStep Dispatcher is ready to run individual ISteps
 *      = 0 if IStep Dispatcher is not ready:
 *          - System has not loaded the IStep Dispatcher yet
 *          - IStep Mode Flag   =   0
 *  Sequence # : bits 2-7 - echoes the sequence number in the associated
 *      command frame.
 *  Status :    returned status for the command, from IStepDisp.
 *  For example:
 *      -EINVAL IStep number is invalid
 *      -ENOENT, -ENOEXEC   (return code from kernel)  IStep could not
 *          be launched as a task or as a function within a task
 */
struct  StatusHdr
{
    bool            runningbit:1;
    bool            readybit:1;
    uint8_t         seqnum:6;
    int8_t          status;

}   __attribute__((packed));

/**
 * @union   SPLessSts
 *
 *  Send HostBoot Status to the user console
 *
 */
union   SPLessSts  {
    uint64_t    val64;
    struct      {
        StatusHdr       hdr;
        uint16_t        reserved1;
        uint32_t        reserved2;
    }   __attribute__((packed));

    //  init struct to 0
    SPLessSts()    : val64(0)  {};
}   ;


/**
 * @union   SPLessSts0x00
 *
 *  Return  Status from IStep/Substep
 *
 */
union   SPLessSingleIStepSts  {
    uint64_t    val64;
    struct      {
        StatusHdr       hdr;
        uint8_t         istep;
        uint8_t         substep;
        uint32_t        istepStatus;
    }   __attribute__((packed));

    SPLessSingleIStepSts() :   val64(0)    {};
}   ;


/**
 * @brief   Read the SPLess Status reg and return a filled in struct.
 *
 * @param[in,out]   io_rsts -   ref SPLessSts struct
 *
 * @return  none.
 */
inline  void    readSts(   SPLessSts   &io_rsts )
{

    // $$ save io_rsts.val64 = mmio_scratch_read(MMIO_SCRATCH_IPLSTEP_STATUS);
    io_rsts.val64   =   g_SPLess_Status_Reg;
#ifdef  SPLESS_DEBUG
    printk( "readSts 0x%lx\n", g_SPLess_Status_Reg );
#endif
}

/**
 * @brief   Write a filled in SPLessSts struct to the SPLess Status Reg
 *
 * @param[in,out]   io_rsts
 *
 * @return  none
 */
inline  void    writeSts(  SPLessSts   &io_rsts )
{
    // $$ save mmio_scratch_write( MMIO_SCRATCH_IPLSTEP_STATUS, io_rsts.val64 );
    g_SPLess_Status_Reg =   io_rsts.val64;
#ifdef  SPLESS_DEBUG
    printk( "writeSts 0x%lx\n", g_SPLess_Status_Reg );
#endif
}

}   // namespace


#endif
