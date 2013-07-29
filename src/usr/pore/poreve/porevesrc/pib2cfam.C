/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/pore/poreve/porevesrc/pib2cfam.C $                    */
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
// -*- mode: C++; c-file-style: "linux";  -*-
// $Id: pib2cfam.C,v 1.15 2013/06/24 14:51:53 jeshua Exp $

/// \file pib2cfam.C
/// \brief A simple PibSlave that maps a small range of PIB addresses to CFAM
///        addresses.

#include "pib2cfam.H"

using namespace vsbe;


////////////////////////////// Creators //////////////////////////////

Pib2Cfam::Pib2Cfam()
{
}


Pib2Cfam::~Pib2Cfam()
{
}


//////////////////////////// Manipulators ////////////////////////////

static uint32_t 
translateAddress(uint32_t address, fapi::Target* i_target)
{
    uint8_t fsi_gpreg_scom_access = 0;
    fapi::ReturnCode frc;

    frc = FAPI_ATTR_GET( ATTR_FSI_GP_REG_SCOM_ACCESS, i_target, fsi_gpreg_scom_access );
    if(!frc.ok()) {
        FAPI_ERR( "Unable to get ATTR_FSI_GP_REG_SCOM_ACCESS for target\n" );
//JDS TODO - create an actual fapi error
//      FAPI_SET_HWP_ERROR( frc, "Unable to get ATTR_FSI_GP_REG_SCOM_ACCESS for target\n" );
    }


    if( fsi_gpreg_scom_access ) {
        return (address - 0x00050000) + 0x2800;
    } else {
        return (address - 0x00050000) + 0x1000;
    }
}


fapi::ReturnCode
Pib2Cfam::operation(Transaction& io_transaction)
{
    fapi::ReturnCode rc;
    ModelError me;

    switch (io_transaction.iv_mode) {

    case ACCESS_MODE_READ:

        switch (io_transaction.iv_address) {
        case 0x00050006:
        case 0x00050007:
        case 0x00050012:
        case 0x00050013:
        case 0x00050014:
        case 0x00050015:
        case 0x00050016:
        case 0x00050017:
        case 0x00050018:
        case 0x00050019:
        case 0x0005001A:
        case 0x0005001B:
            rc = fapiGetCfamRegister(*iv_target, 
                                     translateAddress(io_transaction.iv_address, iv_target),
                                     *iv_dataBuffer);
            if (rc.ok()) {
                io_transaction.iv_data = 
                    ((uint64_t)iv_dataBuffer->getWord(0)) << 32;
                me = ME_SUCCESS;
            } else {
                me = ME_FAILURE;
            }
            break;
        default:
            me = ME_NOT_MAPPED_IN_MEMORY;
        }
        break;

    case ACCESS_MODE_WRITE:

        switch (io_transaction.iv_address) {

        case 0x00050006:
        case 0x00050007:
        case 0x00050012:
        case 0x00050013:
        case 0x00050014:
        case 0x00050015:
        case 0x00050016:
        case 0x00050017:
        case 0x00050018:
        case 0x0005001B:
            iv_dataBuffer->setWordLength(1);
            iv_dataBuffer->setWord(0, io_transaction.iv_data >> 32);
            rc = fapiPutCfamRegister(*iv_target, 
                                     translateAddress(io_transaction.iv_address, iv_target),
                                     *iv_dataBuffer);
            if (rc.ok()) {
                me = ME_SUCCESS;
            } else {
                me = ME_FAILURE;
            }
            break;

        case 0x00050019:
        case 0x0005001A:
                FAPI_SET_HWP_ERROR(rc, RC_POREVE_PIB2CFAM_ERROR);
                me = ME_BUS_SLAVE_PERMISSION_DENIED;
                break;

        default:
                FAPI_SET_HWP_ERROR(rc, RC_POREVE_PIB2CFAM_ERROR);
                me = ME_NOT_MAPPED_IN_MEMORY;
        }
        break;
        
    default:
            FAPI_SET_HWP_ERROR(rc, RC_POREVE_PIB2CFAM_ERROR);
            me = ME_BUS_SLAVE_PERMISSION_DENIED;
            break;
    }
    io_transaction.busError(me);
    return rc;
}
/* Local Variables: */
/* c-basic-offset: 4 */
/* End: */
