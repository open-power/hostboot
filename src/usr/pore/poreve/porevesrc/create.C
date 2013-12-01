/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/pore/poreve/porevesrc/create.C $                      */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2013              */
/*                                                                        */
/* p1                                                                     */
/*                                                                        */
/* Object Code Only (OCO) source materials                                */
/* Licensed Internal Code Source Materials                                */
/* IBM HostBoot Licensed Internal Code                                    */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* Origin: 30                                                             */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
// $Id: create.C,v 1.4 2013/11/27 19:57:47 thi Exp $
/// \file create.C
/// \brief The create method for PoreVe
///
/// The PoreVe class declares a static create() method that allows link-time
/// selection of a normal vs. debug version of PoreVe.  This is similar to the
/// same idea used to make a link-time selection of the Pore hardware model
/// (PMX vs. BOE).  This create() method is linked into the poreve.so.  The
/// create() method for PoreVeDbg is defined in dbg.C

#include "poreve.H"

using namespace vsbe;

PoreVe*
PoreVe::create(const PoreIbufId i_id, 
               const fapi::Target i_masterTarget,
               const void* i_arg)
{
    return new PoreVe(i_id, i_masterTarget);
}

