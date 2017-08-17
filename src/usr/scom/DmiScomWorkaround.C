/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/scom/DmiScomWorkaround.C $                            */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017                             */
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
#include "DmiScomWorkaround.H"

#include <devicefw/driverif.H>
#include <targeting/common/targetservice.H>
#include <targeting/common/utilFilter.H>
#include <trace/interface.H>
#include <util/misc.H>

#include <algorithm>

extern trace_desc_t* g_trac_scom;

#define SCOM_DMI_WA_TRACD(printf_string,args...) \
    TRACDCOMP(g_trac_scom,"DmiScomWorkaround::" printf_string,##args)

namespace SCOM
{

uint64_t DmiScomWorkaround::cv_model_cumulus = 0;

//---------------------------------------------------------------------------
bool DmiScomWorkaround::requestRetry(errlHndl_t i_errl,
                                     uint32_t i_retryCount,
                                     DeviceFW::OperationType i_opType,
                                     TARGETING::Target* i_target,
                                     void* i_buffer,
                                     size_t i_buflen,
                                     int64_t i_accessType,
                                     uint64_t i_addr
                                     ) const
{
    constexpr uint64_t MODEL_UNINITIALIZED=0x00;
    constexpr uint64_t MODEL_IS_CUMULUS=0x01;
    constexpr uint64_t MODEL_IS_NOT_CUMULUS=0x02;

    bool l_retval{false};

    do
    {
        uint64_t l_model_cumulus = __sync_fetch_and_add(&cv_model_cumulus, 0);

        // useCachedProcModel is a dependency injection seam that
        // allows us to obtain the processor model with every call
        // to support unit testing with mocked targets. In non-test
        // code useCachedProcModel always returns true and the
        // Processor model is cached for performance optimization.
        if(useCachedProcModel())
        {
            //If the model is not cumulus then the workaround is not applicable
            if(MODEL_IS_NOT_CUMULUS ==
                                      (MODEL_IS_NOT_CUMULUS & l_model_cumulus))
            {
                break;
            }
        }

        //The workaround is only valid for READ operations
        if(DeviceFW::READ != i_opType)
        {
            break;
        }

        //we only need one retry at most.
        if(i_retryCount > 0)
        {
            break;
        }

        if(nullptr == i_target)
        {
            break;
        }

        //Get the target type. We are only concerned with processor
        //targets.
        TARGETING::ATTR_TYPE_type l_type = TARGETING::TYPE_NA;
        if(not getTargetType(i_target, l_type))
        {
            break;
        }

        if(TARGETING::TYPE_PROC != l_type)
        {
            break;
        }

        //The workaround is only applicable to CUMULUS models.
        //If the model has not yet been determined, then discover
        //the model in order to avoid future processing when running on a
        //non-cumulus model. This code block is run only until the
        //processor model is discovered, after which the check at the
        //beginning of the method tests for the correct model.
        if(MODEL_UNINITIALIZED == l_model_cumulus || !useCachedProcModel())
        {
            TARGETING::ATTR_MODEL_type l_model;
            if(getTargetModel(i_target, l_model))
            {
                const char* model_name = "Unknown";

                if(TARGETING::MODEL_CUMULUS != l_model)
                {
                    if(useCachedProcModel())
                    {
                        //Cache model for a quick check at the start
                        //of the routine.
                        __sync_fetch_and_or(&cv_model_cumulus,
                                                        MODEL_IS_NOT_CUMULUS);
                    }

                    if(TARGETING::MODEL_NIMBUS == l_model)
                    {
                       model_name = "NIMBUS";
                    }

                    SCOM_DMI_WA_TRACD("requestRetry: "
                                       "%s System Detected!",
                                        model_name
                                     );

                    break;
                }
                else
                {
                    if(useCachedProcModel())
                    {
                        //Cache model for a quick check at the start
                        //of the routine.
                        __sync_fetch_and_or(&cv_model_cumulus,
                                                            MODEL_IS_CUMULUS);
                    }

                    model_name = "CUMULUS";

                    SCOM_DMI_WA_TRACD("requestRetry: "
                                       "%s System Detected!",
                                        model_name
                                     );
                }
            }
        }

        //we'll check the EC Level every time in case
        //a system is encountered with different EC Levels
        uint8_t l_ecLevel{};
        if(getTargetECLevel(i_target, l_ecLevel))
        {
            if(0x0 != l_ecLevel && 0x10 != l_ecLevel)
            {
                break;
            }
        }

        // Match Address Formats 0x050108[23ab][3-a]
        //                       0x030108[23ab][3-a]
        //
        // Step 1: Check that the prefix matches 0x050108XX or 0x030108XX
        // Step 2: Check that the last nibble of the address in [0x3,0xa]
        // Step 3: Check that the 3rd bit of nibble 2 is not set and the
        //         2nd bit is set.
        //                      2 - 0010
        //                      3 - 0011
        //                      a - 1010
        //                      b - 1011
        if(
             (((0xFFFFFF00 & i_addr) == 0x05010800) ||
                                      ((0xFFFFFF00 & i_addr) == 0x03010800)) &&
             (((0x0000000F & i_addr) >= 0x00000003) &&
                                      ((0x0000000F & i_addr) <= 0x0000000a)) &&
             (((0x00000040 | 0x00000020) & i_addr) == 0x00000020)
          )
        {
            l_retval = true;
        }
    }
    while(0);

    if(l_retval)
    {
        incRetryCount();
    }

    return l_retval;
}

//----------------------------------------------------------------------------
std::shared_ptr<const PostOpRetryCheck> DmiScomWorkaround::theInstance()
{
    static std::shared_ptr<const PostOpRetryCheck>
                                      ls_instance(new DmiScomWorkaround);

    return ls_instance;
}

//----------------------------------------------------------------------------
bool DmiScomWorkaround::getTargetType(TARGETING::Target* i_target,
                                            TARGETING::TYPE& o_type) const
{
    bool l_retval{false};

    if(nullptr != i_target)
    {
        if(TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL == i_target)
        {
            o_type = TARGETING::TYPE_PROC;
            l_retval = true;
        }
        else if(i_target->tryGetAttr<TARGETING::ATTR_TYPE>(o_type))
        {
            l_retval = true;
        }
    }

    return l_retval;
}

//----------------------------------------------------------------------------
bool DmiScomWorkaround::getTargetModel(TARGETING::Target* i_target,
                                             TARGETING::MODEL& o_model) const
{
    bool l_retval{false};
    TARGETING::MODEL l_model = TARGETING::MODEL_NA;
    TARGETING::TYPE l_type = TARGETING::TYPE_NA;

    if(nullptr != i_target &&
                TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL != i_target)
    {
        if(getTargetType(i_target, l_type))
        {
            if(TARGETING::TYPE_PROC == l_type)
            {
                if(i_target->tryGetAttr<TARGETING::ATTR_MODEL>(l_model))
                {
                    o_model = l_model;
                    l_retval = true;
                }
            }
        }
    }

    return l_retval;
}

//---------------------------------------------------------------------------
bool DmiScomWorkaround::getTargetECLevel(TARGETING::Target* i_target,
                                         uint8_t& o_ecLevel) const
{
    bool l_retval{false};
    uint8_t l_ecLevel{0};

    if(nullptr != i_target &&
                TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL != i_target)
    {
        TARGETING::TYPE l_type = TARGETING::TYPE_NA;

        if(getTargetType(i_target, l_type))
        {
            if(TARGETING::TYPE_PROC == l_type)
            {
                if(i_target->tryGetAttr<TARGETING::ATTR_EC>(l_ecLevel))
                {
                    o_ecLevel = l_ecLevel;
                    l_retval = true;
                }
            }
        }
    }

    return l_retval;
}

} //End Namespace
