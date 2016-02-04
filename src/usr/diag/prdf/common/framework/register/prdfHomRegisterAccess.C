/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/framework/register/prdfHomRegisterAccess.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2016                        */
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
#define prdfHomRegisterAccess_C

#include <prdfHomRegisterAccess.H>
#include <prdf_service_codes.H>
#include <iipbits.h>
#include <prdfMain.H>
#include <prdfPlatServices.H>
#include <prdfGlobal.H>
#include <prdfErrlUtil.H>
#include <prdfTrace.H>

#undef prdfHomRegisterAccess_C


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
    iv_ScomAccessor(NULL)
{
    PRDF_DTRAC("ScomService() initializing default iv_ScomAccessor");
    iv_ScomAccessor = new ScomAccessor();
}

ScomService::~ScomService()
{
    if(NULL != iv_ScomAccessor)
    {
        PRDF_DTRAC("~ScomService() deleting iv_ScomAccessor");
        delete iv_ScomAccessor;
        iv_ScomAccessor = NULL;
    }
}

void ScomService::setScomAccessor(ScomAccessor & i_ScomAccessor)
{
    PRDF_DTRAC("ScomService::setScomAccessor() setting new scom accessor");

    if(NULL != iv_ScomAccessor)
    {
        PRDF_TRAC("ScomService::setScomAccessor() deleting old iv_ScomAccessor");
        delete iv_ScomAccessor;
        iv_ScomAccessor = NULL;
    }

    iv_ScomAccessor = &i_ScomAccessor;
}

uint32_t ScomService::Access(TargetHandle_t i_target,
                             BIT_STRING_CLASS & bs,
                             uint64_t registerId,
                             MopRegisterAccess::Operation operation) const
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
                                BIT_STRING_CLASS & bs,
                                uint64_t registerId,
                                MopRegisterAccess::Operation operation) const
{
    PRDF_DENTER("ScomAccessor::Access()");

    uint32_t rc = SUCCESS;

    if(i_target != NULL)
    {
        switch (operation)
        {
            case MopRegisterAccess::WRITE:
            {
                rc = PRDF::PlatServices::putScom(i_target, bs, registerId);

                #ifndef __HOSTBOOT_MODULE

/* TODO RTC 136050
                if( NULL != errH ) break;

                // If register is in a EX chiplet, need to update PORE image.
                // The PORE update is necessary to avoid losing the FIR MASK
                // after the Core exits the sleep-winkle state.
                if( TYPE_EX == PlatServices::getTargetType(i_target) )
                {
                    // In SLW image we only have space for 32 registers and
                    // that space is not exclusive to PRD.
                    // Though we can write to Mask directly or using AND
                    // register but when we mask a FIR bit for Predictive
                    // callout, we always use OR register.
                    // So we will only consider OR register here as it will
                    // simplify our logic and  will also help to meet SLW
                    // image size requirement.
                    // Using OR register only also enables us to use SCOM_OR
                    // operation in underlying platform API which further
                    // helps to reduce size of SLW Image.
                    uint32_t l_exMaskReg[5] = {
                                        0x1004000f,   // EX_LOCAL_FIR_MASK_OR
                                        0x10013105,   // EX_CORE_FIR_MASK_OR
                                        0x10012805,   // EX_L2CERRS_FIR_MASK_OR
                                        0x10010805,   // EX_L3CERRS_FIR_MASK_OR
                                        0x10010c05 }; // EX_NCSCOMS_FIR_MASK_OR

                    for(uint32_t l_count = 0; l_count < 5; l_count++)
                    {
                        if( l_exMaskReg[l_count]  == registerId )
                        {
                            int32_t l_rc = SUCCESS;
                            l_rc = PlatServices::updateExScomToSlwImage(
                                                        i_target,
                                                        registerId,
                                                        buffer,
                                                        P8_PORE_SCOM_OR_APPEND);
                            if( SUCCESS != l_rc )
                            {
                                PRDF_ERR("[ScomAccessor::Access()] Error in"
                                         " updateExScomToSlwImage.");
                            }
                            break;
                        }
                    }
                }
*/

                #endif // End of, not __HOSTBOOT_MODULE

                break;
            }

            case MopRegisterAccess::READ:
                bs.Pattern(0x00000000); // clear all bits

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
