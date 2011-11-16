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
 */

/******************************************************************************/
// Includes
/******************************************************************************/
#include    <stdint.h>
#include    <stdio.h>
#include    <string.h>

/******************************************************************************/
// Globals/Constants
/******************************************************************************/
/**
 * @note    Since ISTEP_MODE attribute is nonvolitile (persists across boots),
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
 * @todo    overload these later to get command and seq fields
 *
 */
namespace   SPLESSCMD
{

/**
 * @union   InternalCommand
 *
 * define the fields within the 64-bit Command Register
 *

 * Bit numbers are in ppc notation, where bit 0 is the most significant bit.
 *      Go Bit : bit 0 (ppc notation, msbit)
 *          - set to 1 by the user to start the IStep
 *          - cleared to 0 by HostBoot
 *      Reserved: bit 1: always 0
 *      Sequence #: bits 2-7
 *      Command Number: bits 8:15 - always 0 (for now)
 *      Reserved: bits 16:31
 *      Reserved: bits 32:39 - always 0
 *      IStep Number: bits 40:47
 *      Substep Number: bits 48:63gobit:
 *
 */
union   InternalCommand
{
    uint64_t    val64;
    struct
    {
        bool            gobit:1;
        uint8_t         reserved0:1;
        uint8_t         seqnum:6;
        uint8_t         cmdnum;

        uint16_t        reserved2;

        uint16_t        reserved3:2;
        uint16_t        istep:14;

        uint16_t        substep;
    }   f   PACKED;

    //  init struct to 0
    InternalCommand() : val64(0) {};
} ;


/**
 * @brief   Read the command register and return the necessary fields.
 *
 *  @param[in,out] io_rgobit    - ref to a gobit var that will be filled in
 *                                  on return
 *  @param[in,out] io_ristep    - ref to a istep var that will be filled in
 *                                  on return
 *  @param[in,out] io_rsubstep  - ref to a substep var that will be filled
 *                                  in on return
 *
 *  @return pointer to errorlog
 *  @retval NULL if success, filled-in errorlog if failure
 *
 */
void    read( bool      &io_rgobit,
              uint16_t  &io_ristep,
              uint16_t  &io_rsubstep );


/**
    * @brief   Write all the necessary fields to the command reg.
    *
    *  Normally the user writes the command reg; this is only used to
    *  init the command reg at the beginning
    *
    *  @param[in] i_gobit   -   gobit value to write
    *  @param[in] i_istep   -   istep value to write
    *  @param[in] i_substep -   substep value to write
    *
    *  @return errorlog pointer
    *  @retval  NULL if success, filled-in errorlog if failure
    *
    */
void    write( const    bool        i_gobit,
               const    uint16_t    i_istep,
               const    uint16_t    i_substep );


/**
 * @brief   Read the gobit from the command register
 *
 * @param   o_rgobit    -   ref to a gobit var that will be filled in
 *                          on return.
 *
 *  @return errorlog pointer
 *  @retval NULL if success, filled-in errorlog on failure
 */
void    getgobit( bool &o_rgobit );


/**
 * @brief   Write the gobit to the command register
 *
 * @param   i_gobit    -   gobit value to be written
 *
 *  @return pointer to errlog
 *  @retval NULL if success, filled-in errorlog on failure
 */
void    setgobit( const bool    i_gobit ) ;

}   //  namespace


/******************************************************************************/
//  SPLESS Status  Prototypes
/******************************************************************************/

/**
 * @namespace   SPLESSSTS
 *
 * Contains functions to manipulate the SPLESS Status Register
 * @todo    overload these to get seq # later
 *
 */
namespace   SPLESSSTS
{

/**
 * @union   InternalStatus
 *
 * define the fields within the 64-bit status register
 *  Running bit, bit 0 (ppc notation, msbit):
 *      = 1  when IStep is running
 *      = 0   when IStep is finished
 *  Ready bit, bit 1:
 *      = 1 when IStep Dispatcher is ready to run individual ISteps
 *      = 0 if IStep Dispatcher is not ready:
 *          - System has not loaded the IStep Dispatcher yet
 *          - IStep Mode Flag   =   0
 *  Sequence # : bits 2-7 - echoes the sequence number in the associated
 *      command frame.
 *  IStep Running, bits 8:15 - the IStep number that is currently running.
 *  Sub-step Running, bits 16:31 - the substep that is currently running.
 *  Task Status, bits 32:47 -  the status that IStep Dispatcher returns when
 *      trying to run the task.  For example:
 *      -EINVAL IStep number is invalid
 *      -ENOENT, -ENOEXEC   (return code from kernel)  IStep could not
 *          be launched as a task or as a function within a task
 *  IStep Status, bits 48:63 - status returned from the IStep.
 *
 */
union   InternalStatus  {
    uint64_t    val64;
    struct      {
        bool            runningbit:1;       //  |
        bool            readybit:1;         //  |
        uint8_t         seqnum:6;           //  |
        uint8_t         istep;              //  |   16 bits
        uint16_t        substep;            // 16 bits
        uint16_t        taskStatus;         // 16 bits
        uint16_t        istepStatus;        // 16 bits
    }   f   PACKED;

    //  init struct to 0
    InternalStatus()    : val64(0)  {};
}   ;



/**
 * @brief   Read the SPLess Status SCOM Reg and return all its fields
 *
 * @param[in,out]   io_rrunningbit  -   ref to runningbit var, to be
 *                                    filled in on return
 * @param[in,out]   io_rreadybit    -   ref to readybit var, to be filled in
 *                                     on return
 * @param[in,out]   io_ristep       -   ref to istep var, to be filled in on
 *                                    return
 * @param[in,out]   io_rsubstep     -   ref to substep var, to be filled in
 *                                     on return
 * @param[in,out]   io_rtaskStatus  -   ref to taskStatus var, to be filled
 *                                    in on return
 * @param[in,out]   io_ristepStatus -   ref to istepStatus var, to be filled
 *                                    in on return
 *
 * @return  none.
 */
void    read( bool      &io_rrunningbit,
              bool      &io_rreadybit,
              uint16_t  &io_ristep,
              uint16_t  &io_rsubstep,
              uint16_t  &io_rtaskStatus,
              uint16_t  &io_ristepStatus );

/**
 * @brief   write
 *
 * Read the SPLess Status SCOM Reg and return all its fields
 *
 * @param[in]   i_runningbit  -   runningbit val to write
 * @param[in]   i_readybit    -   readybit val to write
 * @param[in]   i_istep       -   istep val to write
 * @param[in]   i_substep     -   substep val to write
 * @param[in]   i_taskStatus  -   taskStatus val to write
 * @param[in]   i_istepStatus -   istepStatus val to write
 *
 * @return  none
 */
void    write( const bool       i_runningbit,
               const bool       i_readybit,
               const uint16_t   i_istep,
               const uint16_t   i_substep,
               const uint16_t   i_taskStatus,
               const uint16_t   i_istepStatus );

}   // namespace

#endif
