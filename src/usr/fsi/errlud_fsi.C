/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/fsi/errlud_fsi.C $                                    */
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
 *  @file errlud_fsi.C
 *
 *  @brief Implementation of classes to log FSI FFDC
 */
#include "errlud_fsi.H"
#include <fsi/fsi_reasoncodes.H>
#include <string.h>
#include "fsidd.H"

namespace FSI
{

//------------------------------------------------------------------------------
//  Presence
//------------------------------------------------------------------------------
UdPresence::UdPresence( TARGETING::Target* i_target )
{
    // Set up Ud instance variables
    iv_CompId = FSI_COMP_ID;
    iv_Version = 1;
    iv_SubSection = FSI_UDT_PRESENCE;

    FsiDD& fsidd = Singleton<FsiDD>::instance();
    FsiDD::FsiChipInfo_t l_chip_info = fsidd.getFsiInfo(i_target);
    uint64_t l_slaveIndex = fsidd.getSlaveEnableIndex(l_chip_info.master,
                                                      l_chip_info.type);

    //***** Memory Layout *****
    // 4 bytes  : Slave HUID
    // 4 bytes  : Master HUID
    // 1 byte   : FSI_MASTER_TYPE
    // 1 byte   : port
    // 1 byte   : cascade
    // 2 bytes  : flags
    // 4 bytes  : linkid (node+proc+type+port)
    // 2 bytes  : Size of iv_slaves[]
    // 8 bytes  : slave enable Index
    // X bytes  : iv_slaves[]

    char * l_pBuf = reinterpret_cast<char *>(
                          reallocUsrBuf(sizeof(uint32_t)*2
                                        +sizeof(uint8_t)*3
                                        +sizeof(uint16_t)
                                        +sizeof(uint32_t)
                                        +sizeof(uint16_t)
                                        +sizeof(uint64_t)
                                        +sizeof(fsidd.iv_slaves)));
    uint32_t tmp32 = 0;
    uint16_t tmp16 = 0;
    uint8_t tmp8 = 0;

    tmp32 = TARGETING::get_huid(l_chip_info.slave);
    memcpy(l_pBuf, &tmp32, sizeof(tmp32));
    l_pBuf += sizeof(tmp32);

    tmp32 = TARGETING::get_huid(l_chip_info.master);
    memcpy(l_pBuf, &tmp32, sizeof(tmp32));
    l_pBuf += sizeof(tmp32);

    tmp8 = l_chip_info.type;
    memcpy(l_pBuf, &tmp8, sizeof(tmp8));
    l_pBuf += sizeof(tmp8);

    tmp8 = l_chip_info.port;
    memcpy(l_pBuf, &tmp8, sizeof(tmp8));
    l_pBuf += sizeof(tmp8);

    tmp8 = l_chip_info.cascade;
    memcpy(l_pBuf, &tmp8, sizeof(tmp8));
    l_pBuf += sizeof(tmp8);

    tmp16 = l_chip_info.flags;
    memcpy(l_pBuf, &tmp16, sizeof(tmp16));
    l_pBuf += sizeof(tmp16);

    tmp32 = l_chip_info.linkid.id;
    memcpy(l_pBuf, &tmp32, sizeof(tmp32));
    l_pBuf += sizeof(tmp32);

    tmp16 = sizeof(fsidd.iv_slaves);
    memcpy(l_pBuf, &tmp16, sizeof(tmp16));
    l_pBuf += sizeof(tmp16);

    memcpy(l_pBuf, &l_slaveIndex, sizeof(l_slaveIndex));
    l_pBuf += sizeof(l_slaveIndex);

    memcpy(l_pBuf, fsidd.iv_slaves, sizeof(fsidd.iv_slaves));
    l_pBuf += sizeof(fsidd.iv_slaves);
}

//------------------------------------------------------------------------------
UdPresence::~UdPresence()
{

}


//------------------------------------------------------------------------------
//  Operation
//------------------------------------------------------------------------------
UdOperation::UdOperation( TARGETING::Target* i_target,
                          uint64_t i_address,
                          bool i_readNotWrite )
{
    // Set up Ud instance variables
    iv_CompId = FSI_COMP_ID;
    iv_Version = 1;
    iv_SubSection = FSI_UDT_OPERATION;

    //***** Memory Layout *****
    // 4 bytes  : Target HUID
    // 8 bytes  : FSI Address
    // 1 byte   : 1=read, 0=write

    char * l_pBuf = reinterpret_cast<char *>(
                          reallocUsrBuf(sizeof(uint32_t)
                                        +sizeof(uint64_t)
                                        +sizeof(uint8_t)
                                        ));

    uint32_t tmp32 = TARGETING::get_huid(i_target);
    memcpy(l_pBuf, &tmp32, sizeof(tmp32));
    l_pBuf += sizeof(tmp32);

    memcpy(l_pBuf, &i_address, sizeof(i_address));
    l_pBuf += sizeof(i_address);

    uint8_t tmp8 = i_readNotWrite;
    memcpy(l_pBuf, &tmp8, sizeof(tmp8));
    l_pBuf += sizeof(tmp8);
}

//------------------------------------------------------------------------------
UdOperation::~UdOperation()
{

}



}
