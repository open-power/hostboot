//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/initservice/istepdispatcher/splessstatus.C $
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
/**
 *  @file splessstatus.C
 *
 *  Routines to read and write spless status reg
 *
 */

/******************************************************************************/
// Includes
/******************************************************************************/
#include    <stdint.h>
#include    <stdio.h>
#include    <string.h>

#include    <errl/errlentry.H>          //  errlHndl_t
#include    <sys/mmio.h>                //  mmio_scratch_read/write

#include    "splesscommon.H"

/******************************************************************************/
// Globals/Constants
/******************************************************************************/

/******************************************************************************/
// Typedef/Enumerations
/******************************************************************************/


void    SPLESSSTS::read( bool       &io_rrunningbit,
                         bool       &io_rreadybit,
                         uint16_t   &io_ristep,
                         uint16_t   &io_rsubstep,
                         uint16_t   &io_rtaskStatus,
                         uint16_t   &io_ristepStatus )
{
    InternalStatus l_sts;

    l_sts.val64 = mmio_scratch_read(MMIO_SCRATCH_IPLSTEP_STATUS);

    //  read was good
    io_rrunningbit = l_sts.f.runningbit;
    io_rreadybit = l_sts.f.readybit;
    io_ristep = l_sts.f.istep;
    io_rsubstep = l_sts.f.substep;
    io_rtaskStatus = l_sts.f.taskStatus;
    io_ristepStatus = l_sts.f.istepStatus;

}


void    SPLESSSTS::write( const bool        i_runningbit,
                          const bool        i_readybit,
                          const uint16_t    i_istep,
                          const uint16_t    i_substep,
                          const uint16_t    i_taskStatus,
                          const uint16_t    i_istepStatus  )
{
    InternalStatus  l_sts;

    //  copy in all the values
    l_sts.f.runningbit   =   i_runningbit;
    l_sts.f.readybit     =   i_readybit;
    l_sts.f.istep        =   i_istep;
    l_sts.f.substep      =   i_substep;
    l_sts.f.taskStatus   =   i_taskStatus;
    l_sts.f.istepStatus  =   i_istepStatus;

    mmio_scratch_write( MMIO_SCRATCH_IPLSTEP_STATUS, l_sts.val64 );

}

