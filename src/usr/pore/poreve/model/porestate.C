//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/pore/poreve/model/porestate.C $
//
//  IBM CONFIDENTIAL
//
//  COPYRIGHT International Business Machines Corp. 2012
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
// $Id: porestate.C,v 1.2 2011/10/13 10:04:32 haver Exp $

/// \file porestate.C
/// \brief A structure defining the state of a PORE engine for
/// checkpoint/restart purposes.

#include "porestate.H"
#include <string.h>

using namespace vsbe;


PoreState::PoreState()
{
	// Ensure that reserved/free space is always 0 such that we
	// can do memcmp.
	memset(state, 0, sizeof(state));
}


PoreState::~PoreState()
{
}


ModelError
PoreState::get(const PoreRegisterOffset i_offset, uint64_t& o_reg) const
{
    ModelError me;
    int i;

    if ((i_offset >= SIZEOF_PORE_STATE) || ((i_offset % 8) != 0)) {
        me = ME_PORE_STATE_ERROR;
    } else {

        me = ME_SUCCESS;
        o_reg = 0;
        for (i = 0; i < 8; i++) {
            o_reg <<= 8;
            o_reg |= state[i_offset + i];
        }
    }

    return me;
}
        
    
ModelError
PoreState::put(const PoreRegisterOffset i_offset, const uint64_t i_reg)
{
    ModelError me;
    int i;
    uint64_t reg;

    if ((i_offset >= SIZEOF_PORE_STATE) || ((i_offset % 8) != 0)) {
        me = ME_PORE_STATE_ERROR;
    } else {

        me = ME_SUCCESS;
        reg = i_reg;
        for (i = 7; i >= 0; i--) {
            state[i_offset + i] = (reg & 0xff);
            reg >>= 8;
        }
    }

    return me;
}
        
    

