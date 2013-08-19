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
    // Set up Ud instance variables
    iv_CompId = RUNTIME_COMP_ID;
    iv_Version = 1;
    iv_SubSection = RUNTIME_UDT_NACA;

    //***** Memory Layout *****
    // 8 bytes  : Physical Address
    // 8 bytes  : Virtual Address
    // XX bytes : NACA data

    uint64_t phys_addr = mm_virt_to_phys(reinterpret_cast<void*>(i_naca));
    if( 0 == phys_addr )
    {
        uint64_t* l_pBuf64 = reinterpret_cast<uint64_t *>(
                                       reallocUsrBuf(sizeof(uint64_t)*2));
        l_pBuf64[0] = phys_addr;
        l_pBuf64[1] = 0;
        return;
    }

    char * l_pBuf = reinterpret_cast<char *>(
                          reallocUsrBuf(sizeof(hdatNaca_t)
                                        +sizeof(uint64_t)*2));
    memcpy(l_pBuf, &phys_addr, sizeof(uint64_t));
    l_pBuf += sizeof(uint64_t);
    memcpy(l_pBuf, &i_naca, sizeof(uint64_t));
    l_pBuf += sizeof(uint64_t);
    memcpy(l_pBuf, i_naca, sizeof(hdatNaca_t));
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
    // Set up Ud instance variables
    iv_CompId = RUNTIME_COMP_ID;
    iv_Version = 1;
    iv_SubSection = RUNTIME_UDT_SPIRA;

    //***** Memory Layout *****
    // 8 bytes  : Physical Address
    // 8 bytes  : Virtual Address
    // XX bytes : SPIRA data

    uint64_t phys_addr = mm_virt_to_phys(reinterpret_cast<void*>(i_spira));
    if( 0 == phys_addr )
    {
        uint64_t* l_pBuf64 = reinterpret_cast<uint64_t *>(
                                       reallocUsrBuf(sizeof(uint64_t)*2));
        l_pBuf64[0] = phys_addr;
        l_pBuf64[1] = 0;
        return;
    }

    char * l_pBuf = reinterpret_cast<char *>(
                          reallocUsrBuf(sizeof(hdatSpira_t)
                                        +sizeof(uint64_t)*2));
    memcpy(l_pBuf, &phys_addr, sizeof(uint64_t));
    l_pBuf += sizeof(uint64_t);
    memcpy(l_pBuf, &i_spira, sizeof(uint64_t));
    l_pBuf += sizeof(uint64_t);
    memcpy(l_pBuf, i_spira, sizeof(hdatSpira_t));
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
    // Set up Ud instance variables
    iv_CompId = RUNTIME_COMP_ID;
    iv_Version = 1;
    iv_SubSection = RUNTIME_UDT_TUPLE;

    //***** Memory Layout *****
    // 8 bytes  : Physical Address
    // 8 bytes  : Virtual Address
    // XX bytes : Tuple data

    uint64_t phys_addr = mm_virt_to_phys(reinterpret_cast<void*>(i_tuple));
    if( 0 == phys_addr )
    {
        uint64_t* l_pBuf64 = reinterpret_cast<uint64_t *>(
                                       reallocUsrBuf(sizeof(uint64_t)*2));
        l_pBuf64[0] = phys_addr;
        l_pBuf64[1] = 0;
        return;
    }

    char * l_pBuf = reinterpret_cast<char *>(
                          reallocUsrBuf(sizeof(hdat5Tuple_t)
                                        +sizeof(uint64_t)*2));
    memcpy(l_pBuf, &phys_addr, sizeof(uint64_t));
    l_pBuf += sizeof(uint64_t);
    memcpy(l_pBuf, &i_tuple, sizeof(uint64_t));
    l_pBuf += sizeof(uint64_t);
    memcpy(l_pBuf, i_tuple, sizeof(hdat5Tuple_t));
}

//------------------------------------------------------------------------------
UdTuple::~UdTuple()
{

}


}

