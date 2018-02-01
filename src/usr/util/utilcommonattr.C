/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/util/utilcommonattr.C $                               */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017,2018                        */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* Licensed under the Apache License, Version 2.0 (the "License");        */
/* you may not use this file except in compliance with the License.       */
/* You may obtain a copy of the License at                                */
/*                                                                        */
/*     http://www.apache.org/licenses/LICENSE-2.0                         */
/*                                                                        */
/* Unless required by applicable law or agreed to in writing, software    */
/* distributed under the License is distributed on an "AS IS" BASIS,      */
/* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or        */
/* implied. See the License for the specific language governing           */
/* permissions and limitations under the License.                         */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
#include <util/utilcommonattr.H>

#include "utilbase.H"
#include <util/util_reasoncodes.H>
#include <errl/errlmanager.H>

#include <p9_frequency_buckets.H>
namespace Util
{

errlHndl_t getObusPllBucket(TARGETING::Target * i_chipTarget,
                            uint8_t &o_bucket_val,
                            const uint8_t i_index)
{
    errlHndl_t l_errl = nullptr;

    // Get the corresponding FREQ_O_MHZ frequency number
    TARGETING::ATTR_FREQ_O_MHZ_type l_freq_array;
    assert(i_chipTarget->
        tryGetAttr<TARGETING::ATTR_FREQ_O_MHZ>(l_freq_array),
        "getPllBucket() failed to get ATTR_FREQ_O_MHZ");

    // Get the frequency list from the chip
    const uint32_t *l_freqList = nullptr;

    TARGETING::ATTR_MODEL_type l_chipModel =
        i_chipTarget->getAttr<TARGETING::ATTR_MODEL>();

    TARGETING::ATTR_EC_type l_chipECLevel =
        i_chipTarget->getAttr<TARGETING::ATTR_EC>();

    if(l_chipModel == TARGETING::MODEL_NIMBUS)
    {
        switch (l_chipECLevel)
        {
            case 0x10:
                l_freqList = OBUS_PLL_FREQ_LIST_P9N_10;
                break;
            case 0x20:
                l_freqList = OBUS_PLL_FREQ_LIST_P9N_20;
                break;
            case 0x21:
                l_freqList = OBUS_PLL_FREQ_LIST_P9N_21;
                break;
            case 0x22:
                l_freqList = OBUS_PLL_FREQ_LIST_P9N_22;
                break;
            default:
                TRACFCOMP(g_util_trace, "Unknown EC level 0x%x for NIMBUS",
                    l_chipECLevel);
                break;
        }
    }
    else if(l_chipModel == TARGETING::MODEL_CUMULUS)
    {
        if(l_chipECLevel == 0x10)
        {
            l_freqList = OBUS_PLL_FREQ_LIST_P9C_10;
        }
        else
        {
            TRACFCOMP(g_util_trace, "Unknown EC level 0x%x for CUMULUS",
                l_chipECLevel);
        }
    }
    //else
    //{
       // fall-through, will be caught by l_freqList nullptr check
    //}

    if(l_freqList != nullptr)
    {
        // Look up the frequency from the frequency list
        uint8_t i = 0;
        for (i = 0; i < OBUS_PLL_FREQ_BUCKETS; i++)
        {
            if(l_freqList[i] == l_freq_array[i_index])
            {
                o_bucket_val = i + 1; // bucket is "1" based
                break;
            }
        }

        // make an error if we did not find a matching frequency
        if(i == OBUS_PLL_FREQ_BUCKETS)
        {
            TRACFCOMP(g_util_trace, ERR_MRK
                "getObusPllBucket: Unable to find matching frequency of %d",
                l_freq_array[i_index])
            /*@
             * @errortype
             * @moduleid          UTIL_MOD_GET_OBUS_PLL_BUCKET
             * @reasoncode        UTIL_ERC_NO_MATCHING_FREQ
             * @userdata1         HB Target HUID
             * @userdata2         Input frequency
             * @devdesc           No matching frequency for PLL bucket
             * @custdesc          Firmware Error
             */
            l_errl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                         UTIL_MOD_GET_OBUS_PLL_BUCKET,
                         UTIL_ERC_NO_MATCHING_FREQ,
                         TARGETING::get_huid(i_chipTarget),
                         l_freq_array[i_index]);
        }
    }
    else // l_freqList equals nullptr
    {
        TRACFCOMP(g_util_trace,
            ERR_MRK"getObusPllBucket: Unable to find frequency list" \
            " for model 0x%.8x, chip level 0x%x", l_chipModel, l_chipECLevel);

        /*@
         * @errortype
         * @moduleid          UTIL_MOD_GET_OBUS_PLL_BUCKET
         * @reasoncode        UTIL_ERC_NO_FREQ_LIST
         * @userdata1         HB Target HUID
         * @userdata1[0:31]   Chip model
         * @userdata2[32:63]  Chip EC level
         * @devdesc           Unable to find frequency list
         * @custdesc          Firmware Error
         */
        l_errl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                     UTIL_MOD_GET_OBUS_PLL_BUCKET,
                     UTIL_ERC_NO_FREQ_LIST,
                     TARGETING::get_huid(i_chipTarget),
                     TWO_UINT32_TO_UINT64(
                     l_chipModel,
                     l_chipECLevel)
                 );
    }

    return l_errl;
}

}
