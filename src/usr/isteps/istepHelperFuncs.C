/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istepHelperFuncs.C $                           */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015                             */
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
#include    "istepHelperFuncs.H"
#include    <stdint.h>

#include    <trace/interface.H>
#include    <errl/errlentry.H>

#include    <isteps/hwpisteperror.H>
#include    <errl/errludtarget.H>

#include    <initservice/isteps_trace.H>

//  targeting support
#include    <targeting/common/commontargeting.H>
#include    <targeting/common/utilFilter.H>
#include    <attributetraits.H>
#include    <config.h>
#include    <util/align.H>
#include    <util/algorithm.H>

//
//  Helper function to set _EFF_CONFIG attributes for HWPs
//
void set_eff_config_attrs_helper( const EFF_CONFIG_ATTRIBUTES_BASE i_base,
                                  bool & o_post_dram_inits_found)
{
    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "set_eff_config_attrs_helper: setting _EFF_CONFIG attributes "
               "enter: i_base=%d", i_base);
/* @TODO: RTC:133830 Uncomment this once the attribute support is in place
    o_post_dram_inits_found = false;

    // Local Variables ('pdi_' means 'post dram init')
    uint32_t pdi_ddr3_vddr_slope=0;
    uint32_t pdi_ddr3_vddr_intercept=0;
    uint32_t pdi_ddr3_vddr_max_limit=0;
    uint32_t pdi_ddr4_vddr_slope=0;
    uint32_t pdi_ddr4_vddr_intercept=0;
    uint32_t pdi_ddr4_vddr_max_limit=0;
    uint32_t pdi_vpp_slope=0;
    uint32_t pdi_vpp_intercept=0;

    uint32_t eff_conf_ddr3_vddr_slope=0;
    uint32_t eff_conf_ddr3_vddr_intercept=0;
    uint32_t eff_conf_ddr3_vddr_max_limit=0;
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
    TARGETING::Target* sysTgt = NULL;
    TARGETING::targetService().getTopLevelTarget(sysTgt);
    assert(sysTgt != NULL,"set_eff_config_attrs_helper: "
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
        // POST_DRAM_INIT DDR3 VDDR
        pdi_ddr3_vddr_slope =
                 nodeTgt->getAttr<
                 TARGETING::ATTR_MSS_VOLT_DDR3_VDDR_SLOPE_POST_DRAM_INIT>();

        pdi_ddr3_vddr_intercept =
                 nodeTgt->getAttr<
                 TARGETING::ATTR_MSS_VOLT_DDR3_VDDR_INTERCEPT_POST_DRAM_INIT>();

        pdi_ddr3_vddr_max_limit =
                 nodeTgt->getAttr<
                 TARGETING::ATTR_MRW_DDR3_VDDR_MAX_LIMIT_POST_DRAM_INIT>();

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
    o_post_dram_inits_found = ( pdi_ddr3_vddr_slope || pdi_ddr3_vddr_intercept ||
                                pdi_ddr3_vddr_max_limit ||
                                pdi_ddr4_vddr_slope || pdi_ddr4_vddr_intercept ||
                                pdi_ddr4_vddr_max_limit ||
                                pdi_vpp_slope || pdi_vpp_intercept )
                              ? true : false;

    // -----------------------------------
    // EFF CONFIG: DDR3 VDDR
    if ( o_post_dram_inits_found == false )
    {
        // Use default system values
        eff_conf_ddr3_vddr_slope =
                 sysTgt->getAttr<TARGETING::ATTR_MSS_VOLT_DDR3_VDDR_SLOPE>();

        eff_conf_ddr3_vddr_intercept =
                 sysTgt->getAttr<
                         TARGETING::ATTR_MSS_VOLT_DDR3_VDDR_INTERCEPT>();

        eff_conf_ddr3_vddr_max_limit =
                 sysTgt->getAttr<
                    TARGETING::ATTR_MRW_DDR3_VDDR_MAX_LIMIT>();
    }
    else
    {
        // Use POST_DRAM INIT values
        eff_conf_ddr3_vddr_slope     = pdi_ddr3_vddr_slope;
        eff_conf_ddr3_vddr_intercept = pdi_ddr3_vddr_intercept;
        eff_conf_ddr3_vddr_max_limit = pdi_ddr3_vddr_max_limit;
    }

    nodeTgt->setAttr<TARGETING::ATTR_MSS_VOLT_DDR3_VDDR_SLOPE_EFF_CONFIG>\
             (eff_conf_ddr3_vddr_slope);

    nodeTgt->setAttr<TARGETING::ATTR_MSS_VOLT_DDR3_VDDR_INTERCEPT_EFF_CONFIG>\
             (eff_conf_ddr3_vddr_intercept);

    nodeTgt->setAttr<TARGETING::ATTR_MRW_DDR3_VDDR_MAX_LIMIT_EFF_CONFIG>\
             (eff_conf_ddr3_vddr_max_limit);

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,"set_eff_config_attrs_helper: "
               "DDR3 _EFF_CONFIG(%d, %d): slope=%d, intercept=%d, max_limit=%d",
               i_base, o_post_dram_inits_found,
               eff_conf_ddr3_vddr_slope,
               eff_conf_ddr3_vddr_intercept,
               eff_conf_ddr3_vddr_max_limit);


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
*/
}

