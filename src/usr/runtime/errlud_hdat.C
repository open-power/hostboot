/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/runtime/errlud_hdat.C $                               */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013                   */
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
/**
 *  @file errlud_hdat.C
 *
 *  @brief Implementation of classes to log and parse various HDAT structures
 */
#include "errlud_hdat.H"
#include <runtime/runtime_reasoncodes.H>
#include <string.h>
#include "hdatstructs.H"
#include <sys/mm.h>

namespace RUNTIME
{

//------------------------------------------------------------------------------
//  NACA
//------------------------------------------------------------------------------
UdNaca::UdNaca(hdatNaca_t* i_naca)
{
    if( 0 == mm_virt_to_phys(reinterpret_cast<void*>(i_naca)) )
    {
        return;
    }

    char * l_pBuf = reinterpret_cast<char *>(
                          reallocUsrBuf(sizeof(hdatNaca_t)));
    memcpy(l_pBuf, i_naca, sizeof(hdatNaca_t));
    
    // Set up Ud instance variables
    iv_CompId = RUNTIME_COMP_ID;
    iv_Version = 1;
    iv_SubSection = RUNTIME_UDT_NACA;
}

//------------------------------------------------------------------------------
UdNaca::~UdNaca()
{

}


//------------------------------------------------------------------------------
//  SPIRA
//------------------------------------------------------------------------------
UdSpira::UdSpira(hdatSpira_t* i_spira)
{
    if( 0 == mm_virt_to_phys(reinterpret_cast<void*>(i_spira)) )
    {
        return;
    }

    char * l_pBuf = reinterpret_cast<char *>(
                          reallocUsrBuf(sizeof(hdatSpira_t)));
    memcpy(l_pBuf, i_spira, sizeof(hdatSpira_t));
    
    // Set up Ud instance variables
    iv_CompId = RUNTIME_COMP_ID;
    iv_Version = 1;
    iv_SubSection = RUNTIME_UDT_SPIRA;
}

//------------------------------------------------------------------------------
UdSpira::~UdSpira()
{

}


//------------------------------------------------------------------------------
//  Tuple
//------------------------------------------------------------------------------
UdTuple::UdTuple(hdat5Tuple_t* i_tuple)
{
    if( 0 == mm_virt_to_phys(reinterpret_cast<void*>(i_tuple)) )
    {
        return;
    }

    char * l_pBuf = reinterpret_cast<char *>(
                          reallocUsrBuf(sizeof(hdat5Tuple_t)));
    memcpy(l_pBuf, i_tuple, sizeof(hdat5Tuple_t));
    
    // Set up Ud instance variables
    iv_CompId = RUNTIME_COMP_ID;
    iv_Version = 1;
    iv_SubSection = RUNTIME_UDT_TUPLE;
}

//------------------------------------------------------------------------------
UdTuple::~UdTuple()
{

}


}

