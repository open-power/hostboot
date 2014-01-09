/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/vpd/errlud_vpd.C $                                    */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2014                   */
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
 *  @file errlud_vpd.C
 *
 *  @brief Implementation of classes to log VPD FFDC
 */
#include "errlud_vpd.H"
#include "ipvpd.H"
#include <vpd/vpdreasoncodes.H>
#include <string.h>

namespace VPD
{

//------------------------------------------------------------------------------
//  VPD
//------------------------------------------------------------------------------
UdVpdParms::UdVpdParms( TARGETING::Target * i_target,
                        uint64_t i_buflen,
                        uint64_t i_record,
                        uint64_t i_keyword,
                        bool read_notWrite  )

{
    // Set up Ud instance variables
    iv_CompId =VPD_COMP_ID;
    iv_Version = 1;
    iv_SubSection = VPD_UDT_PARAMETERS;

    //***** Memory Layout *****
    // 1 byte   : Read / Not-Write
    // 4 bytes  : Target HUID
    // 8 bytes  : Length of In/Out Buffer
    // 8 bytes  : Record
    // 8 bytes  : Keyword

    char * l_pBuf = reinterpret_cast<char *>(
                          reallocUsrBuf(sizeof(uint8_t)
                                        +sizeof(uint32_t)
                                        +sizeof(uint64_t)*3));
    uint32_t tmp64 = 0;
    uint16_t tmp32 = 0;
    uint8_t tmp8 = 0;

    tmp8 = read_notWrite;
    memcpy(l_pBuf, &tmp8, sizeof(tmp8));
    l_pBuf += sizeof(tmp8);

    tmp32 = TARGETING::get_huid(i_target);
    memcpy(l_pBuf, &tmp32, sizeof(tmp32));
    l_pBuf += sizeof(tmp32);

    tmp64 = i_buflen;
    memcpy(l_pBuf, &tmp64, sizeof(tmp64));
    l_pBuf += sizeof(tmp64);

    tmp64 = i_record;
    memcpy(l_pBuf, &tmp64, sizeof(tmp64));
    l_pBuf += sizeof(tmp64);

    tmp64 = i_keyword;
    memcpy(l_pBuf, &tmp64, sizeof(tmp64));
    l_pBuf += sizeof(tmp64);

}

//------------------------------------------------------------------------------
UdVpdParms::~UdVpdParms()
{

}


}
