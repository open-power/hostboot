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
#include <errl/hberrltypes.H>
#include <sbeio/sbeioif.H>
#include <sbeio/sbe_utils.H>
#include "sbe_fifodd.H"
#include <sbeio/sbeioreasoncodes.H>
#include <targeting/common/targetservice.H>
#include <ody_generate_sbe_attribute_data.H>
#include <ody_analyze_sbe_attr_response.H>
#include <ody_apply_sbe_attribute_data.H>

extern trace_desc_t* g_trac_sbeio;

#define SBE_TRACD(printf_string,args...) \
TRACDCOMP(g_trac_sbeio,"AttributeAccess: " printf_string,##args)

#define SBE_TRACF(printf_string,args...) \
TRACFCOMP(g_trac_sbeio,"AttributeAccess: " printf_string,##args)

constexpr bool PUSH = 1;
constexpr bool PULL = 0;

using namespace errl_util;

namespace SBEIO
{
    /**
     * @brief This function creates an informational error log and populates it
     *        with all of the mismatched attributes, as dictated by the input
     *        attribute error vector. Only one informational log is created;
     *        all of the mismatched attributes are added into the same log as
     *        FFDC fields. This function is a no-op if the vector is empty.
     * @note  The created error log gets committed within the function.
     *
     * @param[in] i_errors The vector of detected attribute mismatches.
     * @param[in] i_ocmb The Odyssey OCMB target.
     * @param[in] i_push whether an attribute push (1) or pull (0) was performed.
     */
    void processSbeAttrErrorsArray(const std::vector<sbeutil::AttrError_t>& i_errors,
                                   const TARGETING::Target* i_ocmb,
                                   bool i_push)
    {
        if(i_errors.size() != 0)
        {
            /*@
             * @errortype
             * @moduleid         SBEIO_PROCESS_ATTR_ARRAY
             * @reasoncode       SBEIO_ATTR_MISMATCH_DETECTED
             * @userdata1        The HUID of the Odyssey chip
             * @userdata2[0:31]  The size of the attribute error array
             * @userdata2[32:63] Whether the operation was an attribute push (1) or pull (0)
             * @devdesc          SPPE responded with an array of mismatches to Host's attribute
             *                   sync request. See the FFDC field for mismatches.
             * @custdesc         Informational event.
             */
            errlHndl_t l_errl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_INFORMATIONAL,
                                                        SBEIO_PROCESS_ATTR_ARRAY,
                                                        SBEIO_ATTR_MISMATCH_DETECTED,
                                                        TARGETING::get_huid(i_ocmb),
                                                        SrcUserData(bits{0,31}, i_errors.size(),
                                                                    bits{32,63}, i_push),
                                                        ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
            for(const auto l_error : i_errors)
            {
                char buff[256] = {};
                snprintf(buff, sizeof(buff),
                         "FAPI Target Type: 0x%lx; ATTR_CHIP_UNIT_POS: 0x%x; Attr ID 0x%x; SBE RC: 0x%x",
                         l_error.iv_targetType, l_error.iv_instance, l_error.iv_attrId, l_error.iv_rc);
                SBE_TRACF(WARN_MRK"Attribute sync error detected: %s", buff);
                ERRORLOG::ErrlUserDetailsString(buff).addToLog(l_errl);
            }
            l_errl->collectTrace(SBEIO_COMP_NAME);
            l_errl->collectTrace(FAPI2_COMP_NAME);
            errlCommit(l_errl, SBEIO_COMP_ID);
        }
    }

    /**
    * @brief This function sends a chip-op to SPPE to fetch a binary blob of the
    *        attributes common between SPPE and Hostboot and applies the results
    *        to the attributes on Hostboot side.
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
        SbeFifo::fifoAttrListRequest* l_request = new SbeFifo::fifoAttrListRequest;
        SbeFifo::fifoAttrListResponse* l_response = new SbeFifo::fifoAttrListResponse;

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

            l_request->wordCnt = 2; // Leave the list of attributes blank so that SPPE returns all of the attributes

            errl = SbeFifo::getTheInstance().performFifoChipOp(i_chipTarget,
                                                               reinterpret_cast<uint32_t*>(l_request),
                                                               reinterpret_cast<uint32_t*>(l_response),
                                                               sizeof(SbeFifo::fifoAttrListResponse));
            if(errl)
            {
                SBE_TRACF(ERR_MRK"sendAttrListRequest: could not send attr list request to SPPE");
                break;
            }

            fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>l_fapiOcmb(i_chipTarget);
            std::vector<sbeutil::AttrError_t>l_sbeErrors;
            FAPI_INVOKE_HWP(errl,
                            ody_apply_sbe_attribute_data,
                            l_fapiOcmb,
                            l_response->AttrListResponse,
                            sizeof(l_response->AttrListResponse),
                            l_sbeErrors);
            processSbeAttrErrorsArray(l_sbeErrors, i_chipTarget, PULL);
            if(errl)
            {
                SBE_TRACF(ERR_MRK"sendAttrListRequest: could not parse attr blob from SPPE");
                break;
            }


        }while(0);
        delete l_request;
        delete l_response;

        SBE_TRACD(EXIT_MRK "sendAttrListRequest");
        return errl;
    }

    /**
    * @brief This function generates a binary blob of attributes common between SPPE
    *        and Hostboot and sends the blob to SPPE via a chip-op.
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
            processSbeAttrErrorsArray(l_attrErrors, i_chipTarget, PUSH);
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
    }
} //end namespace SBEIO

