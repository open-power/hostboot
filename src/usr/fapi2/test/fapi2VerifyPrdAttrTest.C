/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/fapi2/test/fapi2VerifyPrdAttrTest.C $                 */
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
#include <fapi2.H>
#include <error_info.H>
#include <plat_hwp_invoker.H>
#include <errl/errlreasoncodes.H>
#include <targeting/common/targetservice.H>
#include <rcSupport.H>
#include <attributeenums.H>
#include "fapi2TestUtils.H"
#include <utils.H>

// NOTE: This testcase does run successfully
//       when enabling fapi test library.
//
//       However, log_related_error(..) has to have
//       a prototype defined for this to compile..
//       That will eventually be true when
//       the EKB changes show up in utils.H
#if 1
namespace fapi2
{
void log_related_error(
    const Target<TARGET_TYPE_ALL>& i_target,
    fapi2::ReturnCode& io_rc,
    const fapi2::errlSeverity_t i_sev = fapi2::FAPI2_ERRL_SEV_UNRECOVERABLE,
    const bool i_unitTestError = false );
}
#else
#include <utils.H>
#endif



// Used to generate a FAPI RC -- don't care how or why
fapi2::ReturnCode verifyPrd_get_fapi2_error(void)
{
    FAPI_INF("Enter verifyPrd_get_fapi2_error...");
    // You can assign directly to the buffer:
    const uint32_t buf[] = {0x01, 0x02, 0x03, 0xDEADBEEF};
    fapi2::variable_buffer other_bits(buf, 4, 128);
    uint32_t val;

    FAPI_TRY( other_bits.extract(val, 0, 130) );

fapi_try_exit:
    FAPI_INF("Exiting verifyPrd_get_fapi2_error...");

    // should return FAPI2_RC_INVALID_PARAMETER
    return fapi2::current_err;
}


namespace fapi2
{
uint32_t verifyHwpPrdAssociaton()
{
    uint32_t   l_rc   = 0;
    uint32_t   l_plid = 0;
    ReturnCode l_fapiRc;

    FAPI_INF("verifyHwpPrdAssociation running");
    // get a target for this test
    TARGETING::Target * l_masterProc;
    TARGETING::targetService().masterProcChipTargetHandle(l_masterProc);

    // Using masterProc target as FAPI core target for test
    Target<fapi2::TARGET_TYPE_CORE> fapi2_coreTarget(l_masterProc);
    // We have to pass a FAPI RC so make one up
    l_fapiRc = verifyPrd_get_fapi2_error();

    // Init the attribute so we know if it changes
    l_masterProc->setAttr<TARGETING::ATTR_PRD_HWP_PLID>( 0x12345678 );

    // Create/commit elog associated with PRD PLID attribute
    fapi2::log_related_error( fapi2_coreTarget, l_fapiRc );

    // Verify that PLID attribute changed
    l_plid = l_masterProc->getAttr<TARGETING::ATTR_PRD_HWP_PLID>();

    if (0x12345678 == l_plid)
    {   // PLID did not change so routine failed somehow
        TS_FAIL(" verifyHwpPrdAssociation No PLID change:%08X", l_plid);
        l_rc = 1;
    }
    else
    {   // PLID was altered, so that is good
        TS_TRACE(" verifyHwpPrdAssociation GOOD on CORE");
    }

    FAPI_INF("...verifyHwpPrdAssociation completed: PLID:%08X", l_plid);

    return l_rc;
}


} // end namespace fapi2
