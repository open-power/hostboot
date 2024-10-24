/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/scom/ScomParityErrorWorkaround.C $                    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2024                             */
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
#include "ScomParityErrorWorkaround.H"

#include "targeting/common/targetservice.H"
#include "usr/scom/scomreasoncodes.H"
#include "usr/xscom/piberror_common.H"

namespace SCOM
{

//---------------------------------------------------------------------------
bool ScomParityErrorWorkaround::requestRetry(errlHndl_t i_errl,
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
        //we only need one retry at most.
        if (i_retryCount > 0)
        {
            break;
        }

        if (i_target == nullptr)
        {
            break;
        }
        if (i_errl == nullptr)
        {
            break;
        }

        // check to make sure we have proc target
        if (i_target != TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL &&
            i_target->getAttr<TARGETING::ATTR_TYPE>() != TARGETING::TYPE_PROC)
        {
            break;
        }

        // Match Address Formats 0x01060000-0x0106FFFF
        if ((i_addr & 0xFFFF0000) != 0x01060000)
        {
            break;
        }

        // check if error is correct type
        for (auto data : i_errl->getUDSections(SCOM_COMP_ID, SCOM::SCOM_UDT_PIB))
        {
            // We get the raw data from the userdetails section, which in
            // this case is the pib_err itself so just check it.
            uint8_t l_tmpRc = *reinterpret_cast<uint8_t *>(data);
            PIB::PibError l_rc = static_cast<PIB::PibError>(l_tmpRc);
            if (l_rc == PIB::PIB_PARITY_ERROR)
            {
                l_retval = true;
                break;
            }
        }
    }
    while(0);

    if (l_retval)
    {
        incRetryCount();
    }

    return l_retval;
}

//----------------------------------------------------------------------------
std::shared_ptr<const PostOpRetryCheck> ScomParityErrorWorkaround::theInstance()
{
    static std::shared_ptr<const PostOpRetryCheck>
                                      ls_instance(new ScomParityErrorWorkaround);

    return ls_instance;
}

} //End Namespace