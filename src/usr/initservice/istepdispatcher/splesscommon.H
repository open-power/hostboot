/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/initservice/istepdispatcher/splesscommon.H $          */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2016                        */
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

namespace   INITSERVICE
{
/**
 * @namespace   SPLESS
 *
 * Contains functions to manipulate the SPLESS Command Register
 *
 */
namespace   SPLESS
{

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
    SPLESS_TASKRC_TERMINATED        =    1,     // SPless task no longer active
    SPLESS_ISTEP_FAIL               =    2,     // ISTEP failed -- look for PLID
    SPLESS_AT_BREAK_POINT           =   11,     // at breakpoint
    SPLESS_NOT_AT_BREAK_POINT       =   12,     // resume command w/o breakpoint
    SPLESS_TRACE_BUFFERS_CLEARED    =   16,     // trace buffers cleared
};

/**
 * @enum
 *  List out the fields of the SPLessCmd structureSPLess Task return codes
 *
 */
enum    {

    HDR                             =    0,
    STS                             =    1,
    MAJOR                           =    2,
    MINOR                           =    3,
};


/**
 * @note    SPLess commands, and masks for the status.
 *
 */

/**
 * @struct  CommandStsHdr
 *
 * Command Status Header for all SPless commands.  1 byte long.
 * Bit numbers are in ppc notation, where bit 0 is the most significant bit.
 *  Ready bit, bit 0:
 *      = 1 when IStep Dispatcher is ready to run individual ISteps
 *      = 0 if IStep Dispatcher is not ready:
 *          - System has not loaded the IStep Dispatcher yet
 *  Go Bit : bit 1 (ppc notation, msbit)
 *      - set to 1 by the user to start the IStep
 *      - cleared to 0 by HostBoot
 * Running bit, bit 2 (ppc notation, msbit):
 *      = 1  when IStep is running
 *      = 0   when IStep is finished
 * Status: bits 4:7
 *      Return code from executing the istep command
 *
 *
 */
struct  CommandHdr
{
    bool            readybit:1;
    bool            gobit:1;
    bool            runningbit:1;
    uint8_t         key:5;

}   __attribute__((packed));


/**
 * @union   SPLessCmd
 *
 *  3 byte "template" struct for the SPLess command.
 *  This will be read in and used to extract the header info, then "cast"
 *  to the correct command.
 */
union   SPLessCmd
{
    uint32_t           word;
    uint8_t            bytes[4];
    struct
    {
        CommandHdr      cmd;
        uint8_t         sts;
        uint8_t         istep;
        uint8_t         substep;
    }   __attribute__((packed));

    //  init struct to 0
    SPLessCmd() :word(0x0) {};
} ;


/**
 * @brief   Read the command register and return a filled-in SPLessCmd struct
 *
 *  @param[in,out] io_rcmd  -   reference to a SPLessCmd struct
 *
 *  @return none
 */
void    readCmdSts( SPLessCmd   &io_rcmd );


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
void    writeCmdSts( SPLessCmd    i_rcmd );

};   // namespace
};


#endif
