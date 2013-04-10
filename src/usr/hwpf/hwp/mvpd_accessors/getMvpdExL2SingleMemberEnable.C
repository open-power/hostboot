/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/mvpd_accessors/getMvpdExL2SingleMemberEnable.C $ */
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
// $Id: getMvpdExL2SingleMemberEnable.C,v 1.1 2013/04/10 22:02:33 mjjones Exp $
/**
 *  @file getMvpdExL2SingleMemberEnable.C
 *
 *  @brief MVPD Accessor for providing the ATTR_EX_L2_SINGLE_MEMBER_ENABLE
 *         attribute
 */

/*
 * Change Log ******************************************************************
 * Flag     Defect/Feature  User        Date        Description
 * ------   --------------  ----------  ----------- ----------------------------
 *                          mjjones     04/10/2013  Created.
 */

#include <getMvpdExL2SingleMemberEnable.H>

extern "C"
{

fapi::ReturnCode getMvpdExL2SingleMemberEnable(
    const fapi::Target & i_procTarget,
    uint32_t & o_val)
{
    /**
     *  @brief Structure of the LWP4 record, IN keyword MVPD field
     *         for the retrieval of the Single Member Enable data
     *
     *  This could move to a common header file if multiple VPD Accessors need
     *  to get data from the LWP4 record, IN keyword MVPD field
     */
    struct MVPD_LWP4_IN
    {
        uint8_t iv_reserved0;
        uint8_t iv_reserved1;
        uint8_t iv_singleMemberEnable0_7;
        uint8_t iv_singleMemberEnable8_15;
    };

    fapi::ReturnCode l_rc;
    uint8_t * l_pField = NULL;
    uint32_t l_fieldSize = 0;

    FAPI_INF("getMvpdExL2SingleMemberEnable: entry");

    // Call fapiGetMvpdField with a NULL pointer to get the field size
    l_rc = fapiGetMvpdField(fapi::MVPD_RECORD_LWP4,
                            fapi::MVPD_KEYWORD_IN,
                            i_procTarget,
                            l_pField,
                            l_fieldSize);

    if (l_rc)
    {
        FAPI_ERR("getMvpdExL2SingleMemberEnable: Error getting MVPD field size");
    }
    else
    {
        if (l_fieldSize < sizeof(MVPD_LWP4_IN))
        {
            FAPI_ERR("getMvpdExL2SingleMemberEnable: MVPD field too small (%d)",
                     l_fieldSize);
            uint32_t & FIELD_SIZE = l_fieldSize;
            FAPI_SET_HWP_ERROR(l_rc,
                RC_MVPD_EX_L2_SINGLE_MEMBER_ENABLE_BAD_FIELD_SIZE);
        }
        else
        {
            // Allocate memory and call fapiGetMvpdField to get the field
            l_pField = new uint8_t[l_fieldSize];

            l_rc = fapiGetMvpdField(fapi::MVPD_RECORD_LWP4,
                                    fapi::MVPD_KEYWORD_IN,
                                    i_procTarget,
                                    l_pField,
                                    l_fieldSize);

            if (l_rc)
            {
                FAPI_ERR(
                    "getMvpdExL2SingleMemberEnable: Error getting MVPD field");
            }
            else
            {
                MVPD_LWP4_IN * l_pData =
                    reinterpret_cast<MVPD_LWP4_IN *>(l_pField);

                o_val = l_pData->iv_singleMemberEnable0_7;
                o_val <<= 8;
                o_val += l_pData->iv_singleMemberEnable8_15;

                FAPI_INF("getMvpdExL2SingleMemberEnable: 0x%08x", o_val);
            }

            delete [] l_pField;
        }
    }

    return l_rc;
}

}
