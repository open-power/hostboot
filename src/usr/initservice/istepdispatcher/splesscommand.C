//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/initservice/istepdispatcher/splesscommand.C $
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
 *  @file splesscommand.C
 *
 *  Collection of routines to read/write the spless command reg
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

namespace   SPLESSCMD
{


void    read( bool      &io_rgobit,
              uint16_t  &io_ristep,
              uint16_t  &io_rsubstep )
{
    InternalCommand l_cmd;

    l_cmd.val64 = mmio_scratch_read(MMIO_SCRATCH_IPLSTEP_COMMAND);

    io_rgobit   = l_cmd.f.gobit;
    io_ristep   = l_cmd.f.istep;
    io_rsubstep = l_cmd.f.substep;

}


void    write( const bool       i_gobit,
               const uint16_t   i_istep,
               const uint16_t   i_substep   )
{
    InternalCommand l_cmd;

    //  copy into union
    l_cmd.f.gobit    =   i_gobit;
    l_cmd.f.istep    =   i_istep;
    l_cmd.f.substep  =   i_substep;

    mmio_scratch_write( MMIO_SCRATCH_IPLSTEP_COMMAND, l_cmd.val64 );

}


void    getgobit( bool &o_rgobit )
{
    uint16_t    l_istep     =   0;
    uint16_t    l_substep   =   0;

    //  re-use above call...
    read( o_rgobit,
          l_istep,
          l_substep   );

}


void    setgobit( const bool  i_gobit )
{
    InternalCommand l_cmd;

    l_cmd.val64 =   mmio_scratch_read( MMIO_SCRATCH_IPLSTEP_COMMAND);

    l_cmd.f.gobit  =   i_gobit;

    mmio_scratch_write( MMIO_SCRATCH_IPLSTEP_COMMAND, l_cmd.val64 );

}

}   //  namespace
