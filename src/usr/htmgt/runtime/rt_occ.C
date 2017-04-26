/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/htmgt/runtime/rt_occ.C $                              */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2017                        */
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
#include    <runtime/interface.h>
#include    <util/utillidmgr.H>
#include    <htmgt/htmgt.H>
#include    "../htmgt_utility.H"
#include    <targeting/common/commontargeting.H>
#include    <runtime/rt_targeting.H>


using namespace TARGETING;


namespace HTMGT
{

    //------------------------------------------------------------------------

    void process_occ_error (uint64_t i_chipId)
    {
#ifdef CONFIG_HTMGT
        TARGETING::Target* l_reportingOccTarget = NULL;
        errlHndl_t err = RT_TARG::getHbTarget(i_chipId,l_reportingOccTarget);
        if (err)
        {
            TMGT_ERR ("process_occ_error: getHbTarget"
                      " failed at %d chipId", i_chipId);
            errlCommit (err, HWPF_COMP_ID);
        }
        else
        {
            HTMGT::processOccError(l_reportingOccTarget);
        }
#else
        TMGT_ERR("Unexpected call to process_occ_error(%d)"
                 " when HTMGT is not enabled", i_chipId);
#endif
    }

    //------------------------------------------------------------------------

    void process_occ_reset (uint64_t i_chipId)
    {
#ifdef CONFIG_HTMGT
        TARGETING::Target* l_failedOccTarget = NULL;
        errlHndl_t err = RT_TARG::getHbTarget(i_chipId,l_failedOccTarget);
        if (err)
        {
            TMGT_ERR ("process_occ_reset: getHbTarget"
                      " failed at %d chipId", i_chipId);
            errlCommit (err, HWPF_COMP_ID);
        }
        else
        {
            HTMGT::processOccReset(l_failedOccTarget);
        }
#else
        TMGT_ERR("Unexpected call to process_occ_reset(%d)"
                 " when HTMGT is not enabled", i_chipId);
#endif
    }

    //------------------------------------------------------------------------

    int enable_occ_actuation (int i_occ_activation)
    {
        int rc = 0;
#ifdef CONFIG_HTMGT
        errlHndl_t err = HTMGT::enableOccActuation(0 != i_occ_activation);
        if (err)
        {
            rc = err->reasonCode();
            if (0 == rc)
            {
                // If there was a failure, be sure to return non-zero status
                rc = -1;
            }
            TMGT_ERR ("enable_occ_actuation: OCC state change"
                      " failed with rc=0x%04X (actuate=%d)",
                      err->reasonCode(), i_occ_activation);
            errlCommit (err, HWPF_COMP_ID);
        }
#else
        rc = -1;
        TMGT_ERR("Unexpected call to enable_occ_actuation(%d)"
                 " when HTMGT is not enabled", i_occ_activation);
#endif
        return rc;
    }

    //------------------------------------------------------------------------

    int htmgt_pass_thru (uint16_t   i_cmdLength,
                             uint8_t *  i_cmdData,
                             uint16_t * o_rspLength,
                             uint8_t *  o_rspData)
    {
        int rc = 0;
#ifdef CONFIG_HTMGT
        errlHndl_t err = HTMGT::passThruCommand(i_cmdLength, i_cmdData,
                                                *o_rspLength, o_rspData);
        if (err)
        {
            rc = err->reasonCode();
            if (0 == rc)
            {
                // If there was a failure, be sure to return non-zero status
                rc = -1;
            }
            if ((i_cmdLength > 0) && (NULL != i_cmdData))
            {
                TMGT_ERR ("htmgt_pass_thru: command 0x%02X"
                          " (%d bytes) failed with rc=0x%04X",
                          i_cmdData[0], i_cmdLength, err->reasonCode());
            }
            errlCommit (err, HWPF_COMP_ID);
        }
#else
        o_rspLength = 0;
#endif
        return rc;
    }

    //------------------------------------------------------------------------

    struct registerOcc
    {
        registerOcc()
        {
            runtimeInterfaces_t * rt_intf = getRuntimeInterfaces();
            rt_intf->get_lid_list = &UtilLidMgr::getLidList;
            rt_intf->process_occ_error  = &process_occ_error;
            rt_intf->process_occ_reset  = &process_occ_reset;
            rt_intf->enable_occ_actuation  = &enable_occ_actuation;
            rt_intf->mfg_htmgt_pass_thru = &htmgt_pass_thru;
        }
    };

    registerOcc g_registerOcc;
}

