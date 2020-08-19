/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/rule/prdfRuleChip.C $                */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2020                        */
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

#include <prdfMfgThresholdMgr.H>

#ifndef __HOSTBOOT_MODULE
  #include <utilreg.H> // for UtilReg
  #include <prdfSdcFileControl.H> //for SyncAnalysis
#endif

#include <prdfGlobal.H> // for SystemPtr.
#include <prdfErrlUtil.H>

#include <prdfRuleChip.H>
#include <prdfPluginMap.H>
#include <prdrCommon.H> // for enums.
#include <prdfScanFacility.H> // for ScanFacility
#include <iipResolutionFactory.h> // for ResolutionFactory
#include <iipCaptureData.h> // for CaptureData
#include <iipServiceDataCollector.h> // for ServiceDataCollector
#include <prdfErrorSignature.H> // for ErrorSignature
#include <prdfPfa5Data.h> // for errl user data flags.
#include <iipSystem.h> // for System
#include <prdfRasServices.H>

namespace PRDF
{


RuleChip::RuleChip( const char * i_fileName ,
                    TARGETING::TargetHandle_t i_pTargetHandle,
                    ScanFacility & i_scanFactory,
                    ResolutionFactory & i_reslFactory,
                    errlHndl_t & o_errl )
    : ExtensibleChip( i_pTargetHandle ),cv_dataBundle( nullptr )
{
    iv_pRuleData = nullptr;
    if( nullptr != systemPtr )
    {
        TARGETING::TYPE  l_type  =
                        PlatServices::getTargetType( i_pTargetHandle );
        iv_pRuleData = systemPtr->getChipMetaData( l_type,i_fileName,
                                        i_scanFactory,i_reslFactory,o_errl );

    }

    init();

}

//------------------------------------------------------------------------------

void RuleChip::init( )
{
    PRDF_DEFINE_CHIP_SCOPE( this );
    // Call initialize plugin.
    ExtensibleChipFunction * l_init = getExtensibleFunction("Initialize", true);
    if (nullptr != l_init)
    {
        (*l_init)( this,PluginDef::bindParm<void*>(nullptr) );
    }

};

//------------------------------------------------------------------------------

RuleChip::~RuleChip()
{
    if (nullptr != cv_dataBundle)
    {
        delete cv_dataBundle;
    }
};

//------------------------------------------------------------------------------

int32_t RuleChip::Analyze( STEP_CODE_DATA_STRUCT & i_serviceData,
                            ATTENTION_TYPE i_attnType )
{
    //this pointer is retained in stack just for the scope of this function
    PRDF_DEFINE_CHIP_SCOPE( this );
    int32_t l_rc = SUCCESS;
    ServiceDataCollector & i_sdc = *(i_serviceData.service_data);
    ErrorSignature & l_errSig = *(i_sdc.GetErrorSignature());

    // Set the secondary attention type. This must be done before calling
    // Analyze() on iv_pRuleData.
    i_sdc.setSecondaryAttnType( i_attnType );

    // Set Signature Chip Id.
    l_errSig.setChipId( GetId() );

    l_rc = iv_pRuleData->Analyze( i_serviceData );

    return l_rc;
};

//------------------------------------------------------------------------------

ExtensibleChipFunction *
    RuleChip::getExtensibleFunction( const char * i_func, bool i_expectNull )
{
    //this pointer is retained in stack just for the scope of this function
    PRDF_DEFINE_CHIP_SCOPE( this );
    ExtensibleChipFunction * l_ptr = nullptr ;
    l_ptr = iv_pRuleData->getExtensibleFunction( i_func , i_expectNull );
    return l_ptr ;
}

//------------------------------------------------------------------------------

SCAN_COMM_REGISTER_CLASS * RuleChip::getRegister(const char * i_reg,
                                                     bool i_expectNull)
{
    //this pointer is retained in stack just for the scope of this function
    PRDF_DEFINE_CHIP_SCOPE( this );
    SCAN_COMM_REGISTER_CLASS * l_ptr = iv_pRuleData->getRegister( i_reg,
                                                            i_expectNull,this );
    return l_ptr ;
}


//------------------------------------------------------------------------------
int32_t RuleChip::CaptureErrorData( CaptureData & io_cap,int i_group )
{
    //this pointer is retained in stack just for the scope of this function
   PRDF_DEFINE_CHIP_SCOPE( this );
   return  iv_pRuleData->CaptureErrorData( io_cap ,i_group );
}

//------------------------------------------------------------------------------

uint32_t RuleChip::getSignatureOffset()
{
    //this pointer is retained in stack just for the scope of this function
    PRDF_DEFINE_CHIP_SCOPE( this );
    return iv_pRuleData->getSignatureOffset();
}

} // end namespace PRDF

