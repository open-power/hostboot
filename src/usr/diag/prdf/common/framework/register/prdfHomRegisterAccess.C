/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/framework/register/prdfHomRegisterAccess.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2021                        */
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
  @file prdfHomRegisterAccess.C
  @brief definition of HomRegisterAccess
*/
//----------------------------------------------------------------------
//  Includes
//----------------------------------------------------------------------

#include <prdfHomRegisterAccess.H>
#include <prdf_service_codes.H>
#include <prdfBitString.H>
#include <prdfMain.H>
#include <prdfPlatServices.H>
#include <prdfGlobal.H>
#include <prdfErrlUtil.H>
#include <prdfTrace.H>

#ifdef __HOSTBOOT_RUNTIME
#include <pm_common_ext.H>
#include <p10_stop_api.H>
#endif

using namespace TARGETING;

namespace PRDF
{

//----------------------------------------------------------------------
//  User Types
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//  Constants
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//  Macros
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//  Internal Function Prototypes
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//  Global Variables
//----------------------------------------------------------------------

//------------------------------------------------------------------------------
// Member Function Specifications
//------------------------------------------------------------------------------

ScomService& getScomService()
{
    return PRDF_GET_SINGLETON(theScomService);
}

ScomService::ScomService() :
    iv_ScomAccessor(nullptr)
{
    PRDF_DTRAC("ScomService() initializing default iv_ScomAccessor");
    iv_ScomAccessor = new ScomAccessor();
}

ScomService::~ScomService()
{
    if(nullptr != iv_ScomAccessor)
    {
        PRDF_DTRAC("~ScomService() deleting iv_ScomAccessor");
        delete iv_ScomAccessor;
        iv_ScomAccessor = nullptr;
    }
}

void ScomService::setScomAccessor(ScomAccessor & i_ScomAccessor)
{
    PRDF_DTRAC("ScomService::setScomAccessor() setting new scom accessor");

    if(nullptr != iv_ScomAccessor)
    {
        PRDF_TRAC("ScomService::setScomAccessor() deleting old iv_ScomAccessor");
        delete iv_ScomAccessor;
        iv_ScomAccessor = nullptr;
    }

    iv_ScomAccessor = &i_ScomAccessor;
}

uint32_t ScomService::Access(TargetHandle_t i_target,
                             BitString & bs,
                             uint64_t registerId,
                             RegisterAccess::Operation operation) const
{
    PRDF_DENTER("ScomService::Access()");
    uint32_t rc = SUCCESS;

    rc = iv_ScomAccessor->Access( i_target,
                                  bs,
                                  registerId,
                                  operation);

    PRDF_DEXIT("ScomService::Access(): rc=%d", rc);

    return rc;
}


uint32_t ScomAccessor::Access(TargetHandle_t i_target,
                                BitString & bs,
                                uint64_t registerId,
                                RegisterAccess::Operation operation) const
{
    PRDF_DENTER("ScomAccessor::Access()");

    uint32_t rc = SUCCESS;

    if(i_target != nullptr)
    {
        switch (operation)
        {
            case RegisterAccess::WRITE:
            {
                rc = PRDF::PlatServices::putScom(i_target, bs, registerId);

                #ifdef __HOSTBOOT_RUNTIME
                using namespace stopImageSection;

                static const std::vector<std::pair<uint32_t,uint32_t>> masks =
                {
                    {0x20018605, PROC_STOP_SECTION_CACHE},//EQ_L3_FIR_MASK_OR
                    {0x20018645, PROC_STOP_SECTION_CACHE},//EQ_NCU_FIR_MASK_OR
                    {0x20028005, PROC_STOP_SECTION_CORE },//EQ_L2_FIR_MASK_OR
                    {0x20028445, PROC_STOP_SECTION_CORE },//EQ_CORE_FIR_MASK_OR
                };

                // If this register updated the mask on a cache or core FIR,
                // then update the value in the HCODE image.
                for (const auto& mask : masks)
                {
                    if (registerId != mask.first) continue; // skip this reg

                    uint64_t scomVal =
                        (((uint64_t)bs.getFieldJustify(0, 32)) << 32) |
                         ((uint64_t)bs.getFieldJustify(32, 32));

                    errlHndl_t errl = RTPM::hcode_update(mask.second,
                                                PROC_STOP_SCOM_OR_APPEND,
                                                i_target, registerId, scomVal);
                    if (nullptr != errl)
                    {
                        PRDF_ERR("[ScomAccessor::Access()] hcode_update error");
                        PRDF_COMMIT_ERRL(errl, ERRL_ACTION_REPORT);
                    }

                    break; // done searching
                }
                #endif

                break;
            }

            case RegisterAccess::READ:
                bs.clearAll(); // clear all bits

                rc = PRDF::PlatServices::getScom(i_target, bs, registerId);

                break;

            default:
                PRDF_ERR("ScomAccessor::Access() unsuppported scom op: 0x%08X",
                          operation);
                break;

        } // end switch operation

    }
    else // Invalid target
    {
        rc = PRD_SCANCOM_FAILURE;
    }

    PRDF_DEXIT("ScomAccessor::Access()");

    return rc;
}

} // End namespace PRDF
