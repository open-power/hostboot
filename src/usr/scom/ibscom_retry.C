/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/scom/ibscom_retry.C $                                 */
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
#include "ibscom_retry.H"
#include <ibscom/ibscomreasoncodes.H>

namespace SCOM
{

//----------------------------------------------------------------------------
std::shared_ptr<const PostOpRetryCheck> IbscomRetry::theInstance()
{
    static std::shared_ptr<const PostOpRetryCheck>
                                        ls_instance(new IbscomRetry);

    return ls_instance;
}

//---------------------------------------------------------------------------
bool IbscomRetry::requestRetry(errlHndl_t i_errl,
                               uint32_t i_retryCount,
                               DeviceFW::OperationType i_opType,
                               TARGETING::Target* i_target,
                               void* i_buffer,
                               size_t i_buflen,
                               int64_t i_accessType,
                               uint64_t i_addr
                              ) const
{
    bool l_retval{false};

    do
    {
        if(i_retryCount > 0)
        {
            break;
        }
        else if(nullptr == i_errl)
        {
            break;
        }

        if(IBSCOM::IBSCOM_RETRY_DUE_TO_ERROR == i_errl->reasonCode())
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

} //End Namespace
