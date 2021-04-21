/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istepHelperFuncs.C $                           */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2021                        */
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
 *  @file istepHelperFuncs.C
 *
 *  Contains miscellaneous helper functions used by istep functions
 */

#include    "istepHelperFuncs.H"
#include    <stdint.h>

#include    <trace/interface.H>
#include    <errl/errlentry.H>
#include    <errl/errlmanager.H>
#include    <isteps/hwpisteperror.H>
#include    <errl/errludtarget.H>
#include    <errl/errlmanager.H>

#include    <initservice/isteps_trace.H>

//  targeting support
#include    <targeting/common/commontargeting.H>
#include    <targeting/common/utilFilter.H>
#include    <targeting/targplatutil.H>
#include    <attributetraits.H>
#include    <config.h>
#include    <util/align.H>
#include    <util/algorithm.H>

#include    <pnor/pnorif.H>
#include    <pnor/pnor_const.H>


using namespace ISTEP;
using namespace ISTEP_ERROR;
using namespace TARGETING;
using namespace ERRORLOG;

//
//  Helper function to set _EFF_CONFIG attributes for HWPs
//
void set_eff_config_attrs_helper( const EFF_CONFIG_ATTRIBUTES_BASE i_base,
                                  bool & o_post_dram_inits_found)
{
    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "set_eff_config_attrs_helper: setting _EFF_CONFIG attributes "
               "enter: i_base=%d", i_base);

    o_post_dram_inits_found = false;

    // Local Variables ('pdi_' means 'post dram init')
    uint32_t pdi_ddr4_vddr_slope=0;
    uint32_t pdi_ddr4_vddr_intercept=0;
    uint32_t pdi_ddr4_vddr_max_limit=0;
    uint32_t pdi_vpp_slope=0;
    uint32_t pdi_vpp_intercept=0;

    uint32_t eff_conf_ddr4_vddr_slope=0;
    uint32_t eff_conf_ddr4_vddr_intercept=0;
    uint32_t eff_conf_ddr4_vddr_max_limit=0;
    uint32_t eff_conf_vpp_slope=0;
    uint32_t eff_conf_vpp_intercept=0;

    // Check input base
    assert( ( i_base == DEFAULT ) || (i_base == POST_DRAM_INIT ),
            "set_eff_config_attrs_helper: Invalid i_base passed in: %d",
            i_base);

    // Get Node Target
    TARGETING::Target* sysTgt = nullptr;
    TARGETING::targetService().getTopLevelTarget(sysTgt);
    assert(sysTgt != nullptr,"set_eff_config_attrs_helper: "
                        "System target was NULL.");

    TARGETING::TargetHandleList l_nodeList;

    TARGETING::PredicateCTM isaNode(TARGETING::CLASS_ENC,
                                    TARGETING::TYPE_NODE);

    TARGETING::targetService().getAssociated(
                                   l_nodeList,
                                   sysTgt,
                                   TARGETING::TargetService::CHILD,
                                   TARGETING::TargetService::IMMEDIATE,
                                   &isaNode);

    // Node list should only have 1 tgt
    assert ( l_nodeList.size() == 1,
             "System target returned multiple or zero nodes ");
    TARGETING::Target* nodeTgt=l_nodeList[0];



    // Look for POST_DRAM_INIT Attributes if requested
    if ( i_base == POST_DRAM_INIT )
    {
        // POST_DRAM_INIT DDR4 VDDR
        pdi_ddr4_vddr_slope =
                 nodeTgt->getAttr<
                 TARGETING::ATTR_MSS_VOLT_DDR4_VDDR_SLOPE_POST_DRAM_INIT>();

        pdi_ddr4_vddr_intercept =
                 nodeTgt->getAttr<
                 TARGETING::ATTR_MSS_VOLT_DDR4_VDDR_INTERCEPT_POST_DRAM_INIT>();

        pdi_ddr4_vddr_max_limit =
                 nodeTgt->getAttr<
                 TARGETING::ATTR_MRW_DDR4_VDDR_MAX_LIMIT_POST_DRAM_INIT>();


        // POST_DRAM_INIT VPP
        pdi_vpp_slope =
                 nodeTgt->getAttr<
                 TARGETING::ATTR_MSS_VOLT_VPP_SLOPE_POST_DRAM_INIT>();

        pdi_vpp_intercept =
                 nodeTgt->getAttr<
                 TARGETING::ATTR_MSS_VOLT_VPP_INTERCEPT_POST_DRAM_INIT>();
    }
    o_post_dram_inits_found = ( pdi_ddr4_vddr_slope || pdi_ddr4_vddr_intercept ||
                                pdi_ddr4_vddr_max_limit ||
                                pdi_vpp_slope || pdi_vpp_intercept )
                              ? true : false;

    // -----------------------------------
    // EFF CONFIG: DDR4 VDDR
    if ( o_post_dram_inits_found == false )
    {
        // Use default system value
        eff_conf_ddr4_vddr_slope =
                 sysTgt->getAttr<TARGETING::ATTR_MSS_VOLT_DDR4_VDDR_SLOPE>();

        eff_conf_ddr4_vddr_intercept =
                 sysTgt->getAttr<
                         TARGETING::ATTR_MSS_VOLT_DDR4_VDDR_INTERCEPT>();

        eff_conf_ddr4_vddr_max_limit =
                 sysTgt->getAttr<
                    TARGETING::ATTR_MRW_DDR4_VDDR_MAX_LIMIT>();
    }
    else
    {
        // Use POST_DRAM INIT value
        eff_conf_ddr4_vddr_slope     = pdi_ddr4_vddr_slope;
        eff_conf_ddr4_vddr_intercept = pdi_ddr4_vddr_intercept;
        eff_conf_ddr4_vddr_max_limit = pdi_ddr4_vddr_max_limit;
    }
    nodeTgt->setAttr<TARGETING::ATTR_MSS_VOLT_DDR4_VDDR_SLOPE_EFF_CONFIG>\
             (eff_conf_ddr4_vddr_slope);

    nodeTgt->setAttr<TARGETING::ATTR_MSS_VOLT_DDR4_VDDR_INTERCEPT_EFF_CONFIG>\
             (eff_conf_ddr4_vddr_intercept);

    nodeTgt->setAttr<TARGETING::ATTR_MRW_DDR4_VDDR_MAX_LIMIT_EFF_CONFIG>\
             (eff_conf_ddr4_vddr_max_limit);

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,"set_eff_config_attrs_helper: "
               "DDR4 _EFF_CONFIG(%d, %d): slope=%d, intercept=%d, max_limit=%d",
               i_base, o_post_dram_inits_found,
               eff_conf_ddr4_vddr_slope,
               eff_conf_ddr4_vddr_intercept,
               eff_conf_ddr4_vddr_max_limit);

    // -----------------------------------
    // EFF CONFIG: VPP
    if ( o_post_dram_inits_found == false )
    {
        // Use default system value
        eff_conf_vpp_slope =
                 sysTgt->getAttr<TARGETING::ATTR_MSS_VOLT_VPP_SLOPE>();

        eff_conf_vpp_intercept =
                 sysTgt->getAttr<
                         TARGETING::ATTR_MSS_VOLT_VPP_INTERCEPT>();
    }
    else
    {
        // Use POST_DRAM INIT value
        eff_conf_vpp_slope     = pdi_vpp_slope;
        eff_conf_vpp_intercept = pdi_vpp_intercept;
    }
    nodeTgt->setAttr<TARGETING::ATTR_MSS_VOLT_VPP_SLOPE_EFF_CONFIG>\
             (eff_conf_vpp_slope);

    nodeTgt->setAttr<TARGETING::ATTR_MSS_VOLT_VPP_INTERCEPT_EFF_CONFIG>\
             (eff_conf_vpp_intercept);

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,"set_eff_config_attrs_helper: "
               "VPP _EFF_CONFIG(%d, %d): slope=%d, intercept=%d",
               i_base, o_post_dram_inits_found,
               eff_conf_vpp_slope,
               eff_conf_vpp_intercept);


    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "set_eff_config_attrs_helper: setting _EFF_CONFIG "
               "attributes exit");

}

errlHndl_t loadHcodeImage(char *& o_rHcodeAddr, bool &o_loadSuccess)
{
    errlHndl_t l_errl = nullptr;
    PNOR::SectionInfo_t l_info;

    o_loadSuccess = false;
    do
    {

#ifdef CONFIG_SECUREBOOT
        l_errl = loadSecureSection(PNOR::HCODE);
        if (l_errl)
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                       ERR_MRK"loadHcodeImage() - Error from "
                       "loadSecureSection(PNOR::HCODE)");

            //No need to commit error here, it gets handled later
            //just break out to escape this function
            break;
        }
        o_loadSuccess = true;
#endif

        // Get HCODE/WINK PNOR section info from PNOR RP
        l_errl = PNOR::getSectionInfo( PNOR::HCODE, l_info );
        if( l_errl )
        {
            //No need to commit error here, it gets handled later
            //just break out to escape this function
            break;
        }

        o_rHcodeAddr = reinterpret_cast<char*>(l_info.vaddr);

        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   "HCODE addr = 0x%p ",
                   o_rHcodeAddr);

    } while ( 0 );

    return  l_errl;
}

//
//  Helper functions to capture and log errors
//  @note I have no idea how to succinctly create a single function for a
//        null target, a valid target and target list.  I could have shoved
//        a single target into a target list and then call the target list
//        over loaded function but that seem heavy handed and I did not want
//        all that overhead for one target, so I settled for two functions with
//        practically duplicated code ... sigh ... head hung low.
//
void captureError(errlHndl_t               &io_err,
                  ISTEP_ERROR::IStepError  &io_stepError,
                  compId_t                  i_componentId,
                  const TARGETING::Target  *i_target)
{
    if ( io_err )
    {
        if ( i_target )
        {
            // Capture the target data in the error log
            ERRORLOG::ErrlUserDetailsTarget(i_target).addToLog(io_err);
        }

        // Create IStep error log and cross reference error that occurred
        io_stepError.addErrorDetails(io_err);

        // Commit error. Log should be deleted and set to NULL in errlCommit.
        errlCommit( io_err, i_componentId );
    } // end if ( i_err )
}

void captureError(errlHndl_t                        &io_err,
                  ISTEP_ERROR::IStepError           &io_stepError,
                  compId_t                           i_componentId,
                  const TARGETING::TargetHandleList &i_targetList)
{
    if ( io_err )
    {
        // iterate thru the input targets, if any, and capture user details of the target
        for (const auto & l_target: i_targetList)
        {
            // Capture the target data in the error log
            ERRORLOG::ErrlUserDetailsTarget(l_target).addToLog(io_err);
        }

        // Create IStep error log and cross reference error that occurred
        io_stepError.addErrorDetails(io_err);

        // Commit error. Log should be deleted and set to NULL in errlCommit.
        errlCommit( io_err, i_componentId );
    } // end if ( i_err )
}

// Helper function to capture OMI errors and check if update will resolve
void captureErrorOcmbUpdateCheck(errlHndl_t               &io_err,
                                 ISTEP_ERROR::IStepError  &io_stepError,
                                 compId_t                  i_componentId,
                                 const TARGETING::Target*  i_target)
{
    // Get a handle to the System target
    TargetHandle_t l_systemTarget = UTIL::assertGetToplevelTarget();
    TargetHandle_t l_nodeTarget = UTIL::getCurrentNodeTarget();

    bool runNormalErrorCapture = true;
    do {
        if (l_systemTarget->getAttr<ATTR_IS_MPIPL_HB>())
        {
            // just do regular captureError call
            break;
        }

        TARGETING::ATTR_OCMB_FW_UPDATE_STATUS_type l_updStatus =
            l_nodeTarget->getAttr<ATTR_OCMB_FW_UPDATE_STATUS>();

        if ( !l_updStatus.updateRequired)
        {
            // no OCMB update needed, so just capture the error
            break;
        }

        /////////////////////////////
        // OCMB update is needed
        /////////////////////////////
        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                "captureErrorOcmbUpdateCheck: "
                "ATTR_OCMB_FW_UPDATE_STATUS: updateRequired = %d, "
                "updateI2c = %d, i2cUpdateAttepted = %d, hardFailure = %d",
                l_updStatus.updateRequired, l_updStatus.updateI2c,
                l_updStatus.i2cUpdateAttempted, l_updStatus.hardFailure);

        // Has an I2C update been tried yet?
        if (l_updStatus.i2cUpdateAttempted)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                "captureErrorOcmbUpdateCheck: "
                "ATTR_OCMB_FW_UPDATE_STATUS set to hardFailure");
            l_updStatus.hardFailure = 1;
            l_nodeTarget->setAttr<ATTR_OCMB_FW_UPDATE_STATUS>(l_updStatus);

            // do normal error capture
            break;
        }

        // Has I2C update been set?
        if ( !l_updStatus.updateI2c )
        {
            // try to update OCMBs via I2C
            l_updStatus.updateI2c = 1;
            l_nodeTarget->setAttr<ATTR_OCMB_FW_UPDATE_STATUS>(l_updStatus);

            // trigger reconfig loop
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                  "captureErrorOcmbUpdateCheck: OMI failure EID: 0x%.8X "
                  "Requesting reboot to do OCMB update ...",
                  io_err?io_err->eid():0);
            auto l_reconfigAttr =
                l_systemTarget->getAttr<ATTR_RECONFIGURE_LOOP>();
            l_reconfigAttr |= RECONFIGURE_LOOP_OCMB_FW_UPDATE;
            l_systemTarget->setAttr<ATTR_RECONFIGURE_LOOP>(l_reconfigAttr);

            // commit error as recovered
            // to prevent any deconfig or gard actions
            if (io_err)
            {
                if ( i_target)
                {
                    // Capture the target data in the error log
                    ERRORLOG::ErrlUserDetailsTarget(i_target).addToLog(io_err);
                }
                io_err->setSev(ERRORLOG::ERRL_SEV_RECOVERED);
                errlCommit( io_err, i_componentId );
            }
            // skip normal error capture
            runNormalErrorCapture = false;
            break;
        }
        else
        {
            // Can go down this path in multithread case where previous
            // thread set the updateI2c and triggered reconfig loop.

            // updateI2c is set but has not run update yet
            // commit error as recovered
            // to prevent any deconfig or gard actions
            if (io_err)
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                    "captureErrorOcmbUpdateCheck: OMI failure EID: 0x%.8X, "
                    "I2C OCMB update already requested", io_err->eid());
                if ( i_target)
                {
                    // Capture the target data in the error log
                    ERRORLOG::ErrlUserDetailsTarget(i_target).addToLog(io_err);
                }
                io_err->setSev(ERRORLOG::ERRL_SEV_RECOVERED);
                errlCommit( io_err, i_componentId );
            }
            // skip normal error capture
            runNormalErrorCapture = false;
            break;
        }

    } while (0);

    if (runNormalErrorCapture)
    {
        captureError(io_err, io_stepError, i_componentId, i_target);
    }
}
