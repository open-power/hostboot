/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/mvpd_accessors/accessMBvpdL4BankDelete.C $   */
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
// $Id: accessMBvpdL4BankDelete.C,v 1.2 2013/11/21 17:17:59 whs Exp $
/**
 *  @file accessMBvpdL4BankDelete.C
 *
 *  @brief get the L4 Bank Delete data from MBvpd record VSPD keyword MX
 *
 */

#include    <stdint.h>

//  fapi support
#include    <fapi.H>
#include    <fapiUtil.H>
#include    <accessMBvpdL4BankDelete.H>

extern "C"
{
using   namespace   fapi;

fapi::ReturnCode accessMBvpdL4BankDelete(
                              const fapi::Target  &i_mbTarget,
                              uint32_t  & io_val,
                              const fapi::MBvpdL4BankDeleteMode i_mode )
{
    fapi::ReturnCode l_fapirc;
    uint16_t l_l4BankDelete = 0;
    uint32_t l_bufSize = sizeof(l_l4BankDelete);

    FAPI_DBG("accessMBvpdL4BankDelete: entry ");

    do {
        // check for get/set mode
        if (GET_L4_BANK_DELETE_MODE == i_mode) // retrieve value from vpd
        {
            // get vpd version from record VSPD keyword MX
            l_fapirc = fapiGetMBvpdField(fapi::MBVPD_RECORD_VSPD,
                                 fapi::MBVPD_KEYWORD_MX,
                                 i_mbTarget,
                                 reinterpret_cast<uint8_t *>(&l_l4BankDelete),
                                 l_bufSize);
            if (l_fapirc)
            {
                FAPI_ERR("accessMBvpdL4BankDelete: Read of MX keyword failed");
                break;  //  break out with fapirc
            }

            // Check that sufficient size was returned.
            if (l_bufSize < sizeof(l_l4BankDelete) )
            {
                FAPI_ERR("accessMBvpdL4BankDelete:"
                     " less keyword data returned than expected %d < %d",
                       l_bufSize, sizeof(l_l4BankDelete));
                const uint32_t & KEYWORD = sizeof(l_l4BankDelete);
                const uint32_t & RETURNED_SIZE = l_bufSize;
                FAPI_SET_HWP_ERROR(l_fapirc,RC_MBVPD_INSUFFICIENT_VPD_RETURNED);
                break;  //  break out with fapirc
            }
            // return value
            io_val = static_cast<uint32_t>(FAPI_BE16TOH(l_l4BankDelete));

            FAPI_DBG("accessMBvpdL4BankDelete: get L4 Bank Delete = 0x%08x",
                io_val);
        }
        else if (SET_L4_BANK_DELETE_MODE == i_mode) // update vpd value
        {

            uint16_t l_val = static_cast<uint16_t>(io_val);
            l_l4BankDelete = FAPI_HTOBE16(l_val);

            // update vpd record VSPD keyword MX
            l_fapirc = fapiSetMBvpdField(fapi::MBVPD_RECORD_VSPD,
                                 fapi::MBVPD_KEYWORD_MX,
                                 i_mbTarget,
                                 reinterpret_cast<uint8_t *>(&l_l4BankDelete),
                                 l_bufSize);
            if (l_fapirc)
            {
                FAPI_ERR("accessMBvpdL4BankDelete: Set of MX keyword failed");
                break;  //  break out with fapirc
            }

            FAPI_DBG("accessMBvpdL4BankDelete: set L4 Bank Delete = 0x%04x",
                l_l4BankDelete);

        }
        else  // unlikely invalid mode
        {
            FAPI_ERR("accessMBvpdL4BankDelete:"
                     " invalid mode = 0x%02x", i_mode);
            const uint32_t & MODE = i_mode;
            FAPI_SET_HWP_ERROR(l_fapirc,RC_MBVPD_INVALID_MODE_PARAMETER);
            break;  //  break out with fapirc
        }

    } while (0);

    FAPI_DBG("accessMBvpdL4BankDelete: exit rc=0x%08x)",
               static_cast<uint32_t>(l_fapirc));

    return  l_fapirc;
}

}   // extern "C"
