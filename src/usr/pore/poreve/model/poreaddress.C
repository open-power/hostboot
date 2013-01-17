/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/pore/poreve/model/poreaddress.C $                     */
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
// $Id: poreaddress.C,v 1.1 2011/06/08 13:12:50 bcbrock Exp $

/// \file poreaddress.C
/// \brief A simple abstract PORE address that separates the memory space from
/// the offset.

#include "poreaddress.H"

using namespace vsbe;

////////////////////////////////////////////////////////////////////////////
// PoreAddress
////////////////////////////////////////////////////////////////////////////

PoreAddress::PoreAddress()
{
}


PoreAddress::PoreAddress(uint16_t i_memorySpace, uint32_t i_offset) : 
    iv_offset(i_offset),
    iv_memorySpace(i_memorySpace)
{
}


PoreAddress::PoreAddress(uint64_t i_address) : 
    iv_offset(i_address & 0xffffffff),
    iv_memorySpace((i_address >> 32) & 0xffff)
{
}


PoreAddress::~PoreAddress()
{
}


PoreAddress::operator uint64_t () const
{
    return ((uint64_t)iv_memorySpace << 32) | iv_offset;
}


PoreAddress&
PoreAddress::setFromPibAddress(uint32_t i_pibAddress)
{
    uint64_t address = i_pibAddress;
    
    iv_memorySpace = (address >> 16) &  0xffff;
    iv_offset = (address & 0xffff) << 3;

    return *this;
}

