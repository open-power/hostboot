/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/targeting/test/testattrrules.H $                      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2021,2022                        */
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
#ifndef __TEST_ATTRRULES_H
#define __TEST_ATTRRULES_H

/**
 *  @file targeting/test/testattrrules.H
 *
 *  @brief Test any assumptions we might have about attribute/target
 *         metadata.
 */

//******************************************************************************
// Includes
//******************************************************************************

// CXX TEST
#include <cxxtest/TestSuite.H>

#include <attributeenums.H>
#include <attributetraits.H>

#include <targeting/common/commontargeting.H>
#include <targeting/common/trace.H>
#include <targeting/targplatutil.H>
#include <targeting/targplatutil.H>

using namespace TARGETING;

class AttributeRulesTest: public CxxTest::TestSuite
{
public:
  /**
   *  @test Look for system attributes that are nonvolatile and writable
   *        to ensure that we don't accidentally create a situation where
   *        HB node instances are generating inconsistent data.
   */
  void test_findInvalidSystemAttributes(void)
  {
      static const char * P3_PERSISTENCY = "p3";
      TS_INFO(ENTER_MRK"findInvalidSystemAttributes");

      // list of known exceptions that are okay
      std::vector<ATTRIBUTE_ID> IGNORELIST {
          ATTR_SMF_CONFIG, //bad?
          ATTR_DYNAMIC_INIT_MODE_VEC, //investigate, currently never set?
          ATTR_FREQ_SYSTEM_CORE_CEILING_MHZ, //investigate
          ATTR_PHYS_PRES_REIPL, //investigate, seems wrong
          ATTR_POUND_V_STATIC_DATA_ENABLE, //investigate, could be mismatched since check is by proc
          ATTR_PLCK_IPL_ATTR_OVERRIDES_EXIST, //investigate
          ATTR_BOOT_FLAGS, //investigate,could be mismatched
          ATTR_FREQ_SYSTEM_CORE_FLOOR_MHZ, //investigate,set per node
          ATTR_PM_HALT_FFDC_ENABLE, //currently unused
          ATTR_MSS_INTERLEAVE_ENABLE, //investigate, written by HWSV but not sure why

          ATTR_ORDINAL_ID, //wrong,fix in flight

          ATTR_NEST_PLL_BUCKET, //deprecated
          ATTR_FREQ_X_MHZ, //deprecated
          ATTR_SMF_MEM_AMT_REQUESTED, //deprecated
          ATTR_FREQ_PB_MHZ, //deprecated
          ATTR_MSS_VOLT_DDR4_VDDR_INTERCEPT_POST_DRAM_INIT, //deprecated
          ATTR_MRW_DDR4_VDDR_MAX_LIMIT_POST_DRAM_INIT, //deprecated
          ATTR_MSS_VOLT_DDR4_VDDR_SLOPE_POST_DRAM_INIT, //deprecated
          ATTR_MNFG_FLAGS, //deprecated

          ATTR_PROC_FABRIC_TOPOLOGY_MODE, //make this readonly except on SBE
          ATTR_NO_XSCOM_ENFORCEMENT, //why is this writable?
          ATTR_CONTAINED_LOAD_PATH, //why is this writable?
          ATTR_IS_SIMULATION, //why is this writable?
          ATTR_CONTAINED_IPL_TYPE, //why is this writable?
          ATTR_OMI_X4_DEGRADE_ACTION, //why is this writable?
          ATTR_RUNN_MODE, //why is this writable?
          ATTR_SECURITY_ENABLE, //why is this writable?
          ATTR_SBE_SELECT_EX_POLICY, //why is this writable?
          ATTR_PROC_FABRIC_BROADCAST_MODE, //why is this writable?
          ATTR_DISABLE_HBBL_VECTORS, //why is this writable?
          ATTR_ALLOW_ATTR_OVERRIDES, //why is this writable?

          ATTR_FREQ_PAU_MHZ, //ok,written by HWP based on common data

          ATTR_HOSTSVC_PLID, //ok,written by HBRT

          ATTR_HB_SETTINGS, //ok,written by HWSV
          ATTR_MFG_FLAGS, //ok,written by HWSV
          ATTR_SECURE_VERSION_LOCKIN_POLICY, //ok,set by HWSV
          ATTR_PROC_FABRIC_PRESENT_GROUPS, //ok,set by HWSV
          ATTR_CDM_POLICIES, //ok,written by HWSV
          ATTR_PAYLOAD_IN_MIRROR_MEM, //ok,set by HWSV
          ATTR_EFFECTIVE_EC, //ok,set by HWSV
          ATTR_KEY_CLEAR_REQUEST, //ok,set by HWSV
          ATTR_PAYLOAD_KIND, //ok,written by HWSV
          ATTR_WOF_TABLE_LID_NUMBER, //ok,written by HWSV
          ATTR_TPM_REQUIRED, //ok,written by HWSV

          ATTR_HWAS_STATE_CHANGED_FLAG, //unused on system target (part of base)
          ATTR_TEST_NEGATIVE_FCN, //ok,test
          ATTR_ISTEP_MODE, //ok, usage bug if out of sync
          ATTR_PM_MALF_ALERT_ENABLE, //ok,forced to zero in all instances
          ATTR_MRW_HW_MIRRORING_ENABLE, //ok,written by all instances
          ATTR_FUSED_CORE_MODE_HB, //ok,unique data per instance
          ATTR_PROC_FABRIC_TOPOLOGY_ID_TABLE, //ok,explicitly synced between instances
          ATTR_PROC_LCO_MODE_DISABLE, //ok, set by HWSV or BIOS ATTR
          ATTR_PROC_FAVOR_AGGRESSIVE_PREFETCH, //ok, set by HWSV or BIOS ATTR

          ATTR_FW_RELEASE_VERSION, //ok,BMC only
          ATTR_RAW_MTM, //ok,BMC only
#ifdef CONFIG_INCLUDE_XML_OPENPOWER
          ATTR_SYSTEM_BRAND_NAME, //ok,BMC only
          ATTR_SYS_CLOCK_DECONFIG_STATE, //ok,BMC only
#endif
      };

      auto systarg = TARGETING::UTIL::assertGetToplevelTarget();
      const auto& l_attrMetaData =
        TARGETING::UTIL::getMapMetadataForAllAttributes();

      // array of attr ids
      const ATTRIBUTE_ID* const l_pAttrId = TARG_TO_PLAT_PTR(systarg->iv_pAttrNames);
      const ATTRIBUTE_ID* const end = &l_pAttrId[systarg->iv_attrs];

      std::vector<uint8_t> l_attrData;

      // Iterate each attribute ID and dump it, along with its value, out to the simulator
      for (const ATTRIBUTE_ID* l_attributeId = l_pAttrId;
           l_attributeId != end;
           ++l_attributeId)
      {
          auto l_attrIt = l_attrMetaData.find(*l_attributeId);

          if (l_attrIt == l_attrMetaData.end())
          {
              TS_FAIL("findInvalidSystemAttributes> Can't find entry for attribute, ID 0x%08x", *l_attributeId);
              continue;
          }

          if( l_attributeId )
          {
              TS_INFO("%.08X> size=%d, readWriteable=%d, persistency=%s",
                      *l_attributeId,
                      l_attrIt->second.size,
                      l_attrIt->second.readWriteable,
                      l_attrIt->second.persistency ? l_attrIt->second.persistency : "null");
          }
          else
          {
              TS_FAIL("null attribute??");
              continue;
          }


          if( (l_attrIt->second.readWriteable == true)  //writeable
              && l_attrIt->second.persistency
              && !strcmp(l_attrIt->second.persistency,P3_PERSISTENCY) )  //nonvolatile
          {
              //ignore these
              if( IGNORELIST.end() == std::find(IGNORELIST.begin(),
                                                IGNORELIST.end(),
                                                *l_attributeId) )
              {
                  TS_FAIL("findInvalidSystemAttributes> ID 0x%08x is system-scope, writable, and persistent!", *l_attributeId);
              }
          }
      }

      TS_INFO(EXIT_MRK"findInvalidSystemAttributes");
  };

};

#endif
