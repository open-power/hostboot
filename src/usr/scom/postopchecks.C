/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/scom/postopchecks.C $                                 */
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
#include "postopchecks.H"

//=========================
// Workarounds
//  Each workaround needs to be added to the composite
//  PostOpChecks instance.
#include "DmiScomWorkaround.H"
#include "ibscom_retry.H"
//=========================

namespace SCOM
{

//--------------------------------------------------------------------------
PostOpChecks::PostOpChecks(
 std::initializer_list<std::shared_ptr<const PostOpRetryCheck>> i_retrychecks):
                                                  iv_retryChecks{i_retrychecks}
{
}

//------------------------------------------------------------------------
const PostOpChecks* PostOpChecks::theInstance()
{
    static const PostOpChecks* ls_instance =
                   new PostOpChecks{
                                      IbscomRetry::theInstance(),
                                      DmiScomWorkaround::theInstance()
                                   };

    return ls_instance;
}

//---------------------------------------------------------------------------
bool PostOpChecks::requestRetry(errlHndl_t i_errl,
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
    size_t l_workaroundCount = iv_retryChecks.size();

    for(size_t i = 0; i < l_workaroundCount; ++i)
    {
        const std::shared_ptr<const PostOpRetryCheck>&
                                            l_currentCheck = iv_retryChecks[i];
        if(l_currentCheck)
        {
            l_retval = l_currentCheck->requestRetry(i_errl,
                                                    i_retryCount,
                                                    i_opType,
                                                    i_target,
                                                    i_buffer,
                                                    i_buflen,
                                                    i_accessType,
                                                    i_addr
                                                   );
            if(l_retval)
            {
                break;
            }

        }
    }

    return l_retval;
}

//-----------------------------------------------------------------
uint64_t PostOpChecks::getRetryCount() const
{
    uint64_t l_retval{};
    const size_t l_workaroundCount = iv_retryChecks.size();

    for(size_t i = 0; i < l_workaroundCount; ++i)
    {
        const std::shared_ptr<const PostOpRetryCheck>&
                                            l_currentCheck = iv_retryChecks[i];
        if(l_currentCheck)
        {
            l_retval += l_currentCheck->getRetryCount();
        }
    }

    return l_retval;
}

//--------------------------------------------------------------------
void PostOpChecks::resetRetryCount() const
{
    const size_t l_workaroundCount = iv_retryChecks.size();

    for(size_t i = 0; i < l_workaroundCount; ++i)
    {
        const std::shared_ptr<const PostOpRetryCheck>&
                                            l_currentCheck = iv_retryChecks[i];
        if(l_currentCheck)
        {
           l_currentCheck->resetRetryCount();
        }
    }
}

} // End Namespace
