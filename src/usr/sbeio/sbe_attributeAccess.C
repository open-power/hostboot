/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/sbeio/sbe_attributeAccess.C $                         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2023                             */
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
/**
* @file  sbe_attributeAccess.C
* @brief Contains the Attribute Messages for SBE FIFO chipop
*
*/

#include <fapi2.H>
#include <plat_hwp_invoker.H>
#include <trace/interface.H>
#include <errl/errlmanager.H>
#include <sbeio/sbeioif.H>
#include <sbeio/sbe_utils.H>
#include "sbe_fifodd.H"
#include <sbeio/sbeioreasoncodes.H>
#include <targeting/common/targetservice.H>
#include <ody_generate_sbe_attribute_data.H>
#include <ody_analyze_sbe_attr_response.H>

extern trace_desc_t* g_trac_sbeio;

#define SBE_TRACD(printf_string,args...) \
TRACDCOMP(g_trac_sbeio,"AttributeAccess: " printf_string,##args)

#define SBE_TRACF(printf_string,args...) \
TRACFCOMP(g_trac_sbeio,"AttributeAccess: " printf_string,##args)


namespace SBEIO
{

    // @TODO JIRA PFHB-258 These chipops are reliant on an SBE provided interface to generate, add, and interpret
    //                     attribute data to/from the SBE.

    /**
    * @brief @TODO JIRA PFHB-258
    *
    * @param[in] i_chipTarget The chip you would like to perform the chipop on
    *                       NOTE: HB should only be sending this to non-boot procs or Odyssey chips
    *
    * @return errlHndl_t Error log handle on failure.
    *
    */
    errlHndl_t sendAttrDumpRequest(TARGETING::Target * i_chipTarget)
    {
        errlHndl_t errl = nullptr;

        do
        {
            // Make sure the target is one of the supported types.
            errl = sbeioInterfaceChecks(i_chipTarget,
                                        SbeFifo::SBE_FIFO_CLASS_ATTRIBUTE_MESSAGES,
                                        SbeFifo::SBE_FIFO_CMD_ATTRIBUTE_DUMP);
            if(errl)
            {
                break;
            }
            SBE_TRACF(EXIT_MRK "Skipping unimplemented chipop sendAttrDumpRequest");


        }while(0);

        SBE_TRACD(EXIT_MRK "sendAttrDumpRequest");
        return errl;
    };

    /**
    * @brief @TODO JIRA PFHB-258
    *
    * @param[in] i_chipTarget The chip you would like to perform the chipop on
    *                       NOTE: HB should only be sending this to non-boot procs or Odyssey chips
    *
    * @return errlHndl_t Error log handle on failure.
    *
    */
    errlHndl_t sendAttrListRequest(TARGETING::Target * i_chipTarget)
    {
        errlHndl_t errl = nullptr;

        do
        {
            // Make sure the target is one of the supported types.
            errl = sbeioInterfaceChecks(i_chipTarget,
                                        SbeFifo::SBE_FIFO_CLASS_ATTRIBUTE_MESSAGES,
                                        SbeFifo::SBE_FIFO_CMD_ATTRIBUTE_LIST);
            if(errl)
            {
                break;
            }
            SBE_TRACF(EXIT_MRK "Skipping unimplemented chipop sendAttrListRequest");


        }while(0);

        SBE_TRACD(EXIT_MRK "sendAttrListRequest");
        return errl;
    };

    /**
    * @brief @TODO JIRA PFHB-258
    *
    * @param[in] i_chipTarget The chip you would like to perform the chipop on
    *                       NOTE: HB should only be sending this to non-boot procs or Odyssey chips
    *
    * @return errlHndl_t Error log handle on failure.
    *
    */
    errlHndl_t sendAttrUpdateRequest(TARGETING::Target * i_chipTarget)
    {
        errlHndl_t errl = nullptr;
        SbeFifo::fifoAttrUpdateRequest* l_request = new SbeFifo::fifoAttrUpdateRequest;
        SbeFifo::fifoAttrUpdateResponse* l_response = new SbeFifo::fifoAttrUpdateResponse;

        do
        {
            // Make sure the target is one of the supported types.
            errl = sbeioInterfaceChecks(i_chipTarget,
                                        SbeFifo::SBE_FIFO_CLASS_ATTRIBUTE_MESSAGES,
                                        SbeFifo::SBE_FIFO_CMD_ATTRIBUTE_UPDATE);
            if(errl)
            {
                break;
            }

            l_request->wordCnt = 2 + (ODY_GENERATE_ATTR_DATA_SIZE / 4); // Two words for bookkeeping + the size of the attribute blob in words

            // Generate the binary blob of the attributes to send to SPPE
            fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>l_fapiOcmb(i_chipTarget);
            FAPI_INVOKE_HWP(errl,
                            ody_generate_sbe_attribute_data,
                            l_fapiOcmb,
                            l_request->AttrUpdateRequest,
                            sizeof(l_request->AttrUpdateRequest));
            if(errl)
            {
                SBE_TRACF(ERR_MRK"sendAttrUpdateRequest: ody_generate_sbe_attribute_data failed");
                break;
            }

            errl = SbeFifo::getTheInstance().performFifoChipOp(i_chipTarget,
                                                               reinterpret_cast<uint32_t*>(l_request),
                                                               reinterpret_cast<uint32_t*>(l_response),
                                                               sizeof(SbeFifo::fifoAttrUpdateResponse));
            if(errl)
            {
                SBE_TRACF(ERR_MRK"sendAttrUpdateRequest: attribute push failed");
                break;
            }

            std::vector<sbeutil::AttrError_t>l_attrErrors;
            FAPI_INVOKE_HWP(errl,
                            ody_analyze_sbe_attr_response,
                            l_fapiOcmb,
                            l_response->AttrUpdateResponse,
                            sizeof(l_response->AttrUpdateResponse),
                            l_attrErrors);
            // TODO JIRA: PFHB-439 Process the returned l_attrErrors vector
            if(errl)
            {
                SBE_TRACF(ERR_MRK"sendAttrUpdateRequest: error returned from ody_analyze_sbe_attr_response");
                break;
            }

        }while(0);
        delete l_request;
        delete l_response;

        SBE_TRACD(EXIT_MRK "sendAttrUpdateRequest");
        return errl;
    };
} //end namespace SBEIO

