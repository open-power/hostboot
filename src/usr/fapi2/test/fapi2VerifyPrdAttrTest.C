/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/fapi2/test/fapi2VerifyPrdAttrTest.C $                 */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017,2018                        */
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
#include "diag/attn/attn.H"
#include <utils.H>


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


    // ==============================================================
    // PROCESSOR TARGET should be good
    // ==============================================================
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

    FAPI_INF("...verifyHwpPrdAssociation BaseDone: PLID:%08X", l_plid);


    // ==============================================================
    // Verify MCA target is good (we expect them)
    // ==============================================================
    TargetHandleList  l_mcaList;
    getChildAffinityTargets( l_mcaList, l_masterProc,
                             TARGETING::CLASS_UNIT,
                             TARGETING::TYPE_MCA );

    if (l_mcaList.size() >= 1)
    {
        FAPI_INF("...verifyHwpPrdAssociation MCA :%d",
                 l_mcaList.size());

        // Using masterProc target as FAPI core target for test
        Target<fapi2::TARGET_TYPE_CORE> fapi2_mcaTarget(l_mcaList[0]);
        // We have to pass a FAPI RC so make one up
        l_fapiRc = verifyPrd_get_fapi2_error();

        // Init the attribute so we know if it changes
        l_mcaList[0]->setAttr<TARGETING::ATTR_PRD_HWP_PLID>( 0x87654321 );

        // Create/commit elog associated with PRD PLID attribute
        fapi2::log_related_error( fapi2_mcaTarget, l_fapiRc );

        // Verify that PLID attribute changed
        l_plid = l_mcaList[0]->getAttr<TARGETING::ATTR_PRD_HWP_PLID>();

        if (0x87654321 == l_plid)
        {   // PLID did not change so routine failed somehow
            TS_FAIL(" verifyHwpPrdAssociation MCA No PLID change:%08X",
                     l_plid);
            l_rc = 1;
        }
        else
        {   // PLID was altered, so that is good
            TS_TRACE(" verifyHwpPrdAssociation GOOD on MCA");
        }

        FAPI_INF("...verifyHwpPrdAssociation MCA done: PLID %08X", l_plid);

    } // end if any MCAs


    // ==============================================================
    // Verify target we don't do anything with ... TYPE_EQ
    // ==============================================================
    TargetHandleList  l_eqList;
    getChildAffinityTargets( l_eqList, l_masterProc,
                             TARGETING::CLASS_UNIT,
                             TARGETING::TYPE_EQ );

    if (l_eqList.size() >= 1)
    {
        FAPI_INF("...verifyHwpPrdAssociation EQ :%d",
                 l_eqList.size());

        // Using masterProc target as FAPI core target for test
        Target<fapi2::TARGET_TYPE_CORE> fapi2_eqTarget(l_eqList[0]);
        // We have to pass a FAPI RC so make one up
        l_fapiRc = verifyPrd_get_fapi2_error();


        // We don't have an attribute for this target.  Hence,
        // we can't write/read this attribute, but I can at
        // least run thru the code to ensure it doesn't crash

        // Create/commit elog associated with PRD PLID attribute
        fapi2::log_related_error( fapi2_eqTarget, l_fapiRc );

        // If we make it here, we didn't crash with bad target
        TS_TRACE(" verifyHwpPrdAssociation GOOD on EQ (ignored)");

        FAPI_INF("...verifyHwpPrdAssociation EQ done");

    } // end if any EQ units


#if 0

/*  Bit of a hassle to try calling ATTN code here ...
    but would be nice to do final verification.

    fapi2Test.mk
      but this pulls in more and more of attn code

    EXTRAINCDIR += ${ROOTPATH}/src/usr/diag/attn/
    EXTRAINCDIR += ${ROOTPATH}/src/usr/diag/attn/common
    EXTRAINCDIR += ${ROOTPATH}/src/usr/diag/attn/ipl
    EXTRAINCDIR += ${ROOTPATH}/src/include/usr/diag/

    OBJS += attn.o attnsvc.o
*/

    // ==============================================================
    // We should have the PLID set on a PROC and MCA target by now
    // so let's see if ATTN code will clear them and return an elog.
    // ==============================================================

    errlHndl_t l_attnLog = ATTN::checkForIplAttentions();

    if (NULL != l_attnLog)
    {   // we got elog as expected
        TS_TRACE(" verifyHwpPrdAssociation chkIplAttns GOOD with ELOG");
    }
    else
    {   // Why did we not get ELOG?  Something wrong here
        TS_FAIL(" verifyHwpPrdAssociation chkIplAttns FAIL -no ELOG");
    }

    // ----------------------------------------------------------
    // All targets should have been cleared too ... check that
    // ----------------------------------------------------------
    // Verify that PROC target PLID attribute was cleared
    l_plid = l_masterProc->getAttr<TARGETING::ATTR_PRD_HWP_PLID>();

    if (0 != l_plid)
    {   // PLID should have been cleared
        TS_FAIL(" verifyHwpPrdAssociation PROC PLID not cleared:%08X",
                  l_plid);
        l_rc = 1;
    }
    else
    {   // PLID was altered, so that is good
        TS_TRACE(" verifyHwpPrdAssociation PROC PLID cleared");
    }


    // Verify that MCA target PLID attribute was cleared
    if (l_mcaList.size() >= 1)
    {
        // Verify that PLID attribute changed
        l_plid = l_mcaList[0]->getAttr<TARGETING::ATTR_PRD_HWP_PLID>();

        if (0 != l_plid)
        {   // PLID should have been cleared
            TS_FAIL(" verifyHwpPrdAssociation MCA PLID not cleared:%08X",
                    l_plid);
            l_rc = 1;
        }
        else
        {   // PLID was altered, so that is good
            TS_TRACE(" verifyHwpPrdAssociation MCA PLID cleared");
        }
    } // end if any MCAs to check PLIDs on
#endif

    // asdf tests  here
    FAPI_INF("verifyHwpPrdAssociation completed");

    return l_rc;
}


} // end namespace fapi2
