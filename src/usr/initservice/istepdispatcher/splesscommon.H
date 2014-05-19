/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/initservice/istepdispatcher/splesscommon.H $          */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2011,2014              */
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

#include    <sys/mmio.h>                    //  mmio_scratch_read()
#include    <devicefw/userif.H>        //  deviceRead(), deviceWrite()

#include    <targeting/common/attributes.H>        //  ISTEP_MODE attribute
#include    <targeting/common/targetservice.H>


/******************************************************************************/
//  SPLESS Command and Status Prototypes
/******************************************************************************/

/**
 * @namespace   SPLESS
 *
 * Contains functions to manipulate the SPLESS Command Register
 *
 */
namespace   SPLESS
{

const   uint32_t    MBOX_SCRATCH_REG0               =   0x00050038;
const   uint32_t    MBOX_SCRATCH_REG1               =   0x00050039;
const   uint32_t    MBOX_SCRATCH_REG2               =   0x0005003a;
const   uint32_t    MBOX_SCRATCH_REG3               =   0x0005003b;


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
    SPLESS_TASKRC_FAIL_LOADMODULE   =   -7,     // failed to load module

    SPLESS_INVALID_COMMAND          =   10,     // invalid command from user console
    SPLESS_AT_BREAK_POINT           =   11,     // at breakpoint
    SPLESS_NOT_AT_BREAK_POINT       =   12,     // resume command w/o breakpoint
    SPLESS_SHUTTING_DOWN            =   13,     // shutdown command issued
    SPLESS_SENDRCV_FAILED           =   14,     // could not send cmd to IstepDisp
    SPLESS_TASKRC_INVALID_RECV_TYPE =   15,     // received wrong message type
    SPLESS_TRACE_BUFFERS_CLEARED    =   16,     // trace buffers cleared
};


/**
 * @note    SPLess commands, and masks for the status.
 *
 */
//const   uint8_t     SPLESS_SINGLE_ISTEP_CMD         =   0x00;
//const   uint8_t     SPLESS_RESUME_ISTEP_CMD         =   0x01;
//const   uint8_t     SPLESS_CLEAR_TRACE_CMD          =   0x02;
//const   uint8_t     SPLESS_SHUTDOWN_CMD             =   0x03;
//const   uint64_t    SPLESS_SINGLE_STEP_STS_MASK     =   0x00000000ffffffff;

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
    uint8_t         readbit:1;
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
    uint64_t            val64;
    struct
    {
        uint32_t        hi32;
        uint32_t        lo32;
    } __attribute__((packed));
    struct
    {
        CommandHdr      hdr;
        uint8_t         istep;
        uint8_t         substep;
        uint32_t        reserved2;
    }   __attribute__((packed));

    //  init struct to 0
    SPLessCmd() : val64(0) {};
} ;


/**
 * @brief   Read the command register and return a filled-in SPLessCmd struct
 *
 *  @param[in,out] io_rcmd  -   reference to a SPLessCmd struct
 *
 *  @return none
 */
void    readCmd( SPLessCmd   &io_rcmd );


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
void    writeCmd( SPLessCmd    &io_rcmd );



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
    uint64_t            val64;
    struct
    {
        uint32_t        hi32;
        uint32_t        lo32;
    }   __attribute((packed));
    struct      {
        StatusHdr       hdr;
        uint8_t         istep;
        uint8_t         substep;
        uint32_t        istepStatus;
    }   __attribute__((packed));

    //  init struct to 0
    SPLessSts()    : val64(0)  {};
}   ;


/**
 * @brief   Read the SPLess Status reg and return a filled in struct.
 *
 * @param[in,out]   io_rsts -   ref SPLessSts struct
 *
 * @return  none.
 */
void    readSts(   SPLessSts   &io_rsts );


/**
 * @brief   Write a filled in SPLessSts struct to the SPLess Status Reg
 *
 * @param[in,out]   io_rsts
 *
 * @return  none
 */
void    writeSts(  SPLessSts   &io_rsts );


}   // namespace


#endif
