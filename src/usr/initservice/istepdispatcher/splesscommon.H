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


/**
 * @note    Since ISTEP_MODE attribute is nonvolatile (persists across boots),
 *          we must have a way to turn the attribute both ON and OFF - we
 *          cannot depend on the FSP to do it since we may not have a FSP.
 */
const   uint64_t    ISTEP_MODE_ON_SIGNATURE     =   0x4057b0074057b007;
const   uint64_t    ISTEP_MODE_OFF_SIGNATURE    =   0x700b7504700b7504;

/******************************************************************************/
//  SPLESS Command Prototypes
/******************************************************************************/

/**
 * @namespace   SPLESSCMD
 *
 * Contains functions to manipulate the SPLESS Command Register
 *
 */
namespace   SPLESS
{

const   uint8_t     SPLESS_SINGLE_ISTEP_CMD         =   0x00;
const   uint64_t    SPLESS_SINGLE_STEP_STS_MASK     =   0x00000000ffffffff;


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

    io_rcmd.val64 = mmio_scratch_read(MMIO_SCRATCH_IPLSTEP_COMMAND);
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

    mmio_scratch_write( MMIO_SCRATCH_IPLSTEP_COMMAND, io_rcmd.val64 );
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

    io_rsts.val64 = mmio_scratch_read(MMIO_SCRATCH_IPLSTEP_STATUS);
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
    mmio_scratch_write( MMIO_SCRATCH_IPLSTEP_STATUS, io_rsts.val64 );

}

}   // namespace


#endif
