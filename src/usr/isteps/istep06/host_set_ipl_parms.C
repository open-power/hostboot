/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep06/host_set_ipl_parms.C $                 */
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

#include <stdint.h>
#include <trace/interface.H>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <isteps/hwpisteperror.H>
#include <isteps/istep_reasoncodes.H>
#include <initservice/isteps_trace.H>
#include <util/utilsemipersist.H>
#include <hwas/common/deconfigGard.H>
#include <arch/pvrformat.H>
#include <sys/mmio.h>
#include <console/consoleif.H>
#include <initservice/initserviceif.H>
#include <targeting/common/mfgFlagAccessors.H>

#ifdef CONFIG_PLDM
#include <isteps/bios_attr_accessors/bios_attr_parsers.H>
#include <pldm/base/hb_bios_attrs.H>
#include <pldm/pldm_errl.H>
#endif

#if (defined(CONFIG_PNORDD_IS_BMCMBOX) || defined(CONFIG_PNORDD_IS_IPMI))
#include <pnor/pnorif.H>
#endif

using namespace TARGETING;

namespace ISTEP_06
{
#ifdef CONFIG_PLDM
void parsePLDMBiosAttrs(ISTEP_ERROR::IStepError & io_stepError)
{
    using bios_attribute_parser = void(*)(std::vector<uint8_t>&,
                                        std::vector<uint8_t>&,
                                        ISTEP_ERROR::IStepError &);

    const std::vector<bios_attribute_parser> bios_attr_parsers
    {
        ISTEP::parse_hb_tpm_required,
        ISTEP::parse_hb_field_core_override,
        ISTEP::parse_hb_usb_policy,
        ISTEP::parse_hb_memory_mirror_mode,
        ISTEP::parse_hb_key_clear_request,
        ISTEP::parse_hb_number_huge_pages,
        ISTEP::parse_hb_huge_page_size,
        ISTEP::parse_hb_memory_region_size,
        ISTEP::parse_hb_mfg_flags,
        ISTEP::parse_hb_hyp_switch,
        ISTEP::parse_pvm_fw_boot_side
    };

    std::vector<uint8_t> bios_string_table, bios_attr_table;
    for(auto parser_fn : bios_attr_parsers)
    {
        // if parser_fn generates any errors it will attach them to
        // i_stepError if neccessary and commit the log itself.
        parser_fn(bios_string_table, bios_attr_table, io_stepError);
    }

    return;
}
#endif

void* host_set_ipl_parms( void *io_pArgs )
{
    ISTEP_ERROR::IStepError l_stepError;

    do{

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "host_set_ipl_parms entry" );

    // only run on non-FSP systems
    if( !INITSERVICE::spBaseServicesEnabled() )
    {
        // Read the semi persistent area
        Util::semiPersistData_t l_semiData;
        Util::readSemiPersistData(l_semiData);

        // If magic number set, then this is re-IPL,
        // so increment reboot count
        if(l_semiData.magic == Util::PERSIST_MAGIC)
        {
            l_semiData.reboot_cnt++;
        }
        // else magic number is not set, then this is a fresh IPL
        else
        {
            l_semiData.magic = Util::PERSIST_MAGIC;
            l_semiData.reboot_cnt = 0;
            //Intentionally don't change mfg_term_reboot
        }

        // Write updated data back out
        Util::writeSemiPersistData(l_semiData);

        // Informational only
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "host_set_ipl_parms "
            "l_semiData.magic=0x%X l_semiData.reboot_cnt=0x%X, l_semiData.mfg_term_reboot=0x%X",
            l_semiData.magic, l_semiData.reboot_cnt, l_semiData.mfg_term_reboot);

#ifdef CONFIG_PLDM
        const auto sys = TARGETING::UTIL::assertGetToplevelTarget();
        if(!sys->getAttr<ATTR_IS_MPIPL_HB>())
        {
            // All error logs that occur while parsing the PLDM bios attributes will be
            // committed within the function. If the error that occurs should TI the system,
            // then the parser should attached the errlog to the step error.
            parsePLDMBiosAttrs(l_stepError);
            if(!l_stepError.isNull())
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                         "host_set_ipl_parms: Error(s) occurred while parsing a PLDM BIOS Attribute that requires Hostboot to TI.");
                break;
            }
        }
        else
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                          "host_set_ipl_parms: MPIPL detected, using PLDM bios attrs values from previous boot");
        }

        // Force the update of the VPD ECC data if there is a mismatch, for BMC only
        bool l_forceEccUpdateFlag = true;
        sys->setAttr<TARGETING::ATTR_FORCE_ECC_UPDATE_ON_VALIDATION_ERROR>(l_forceEccUpdateFlag);

        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace, "host_set_ipl_parms: "
            "setting ATTR_FORCE_ECC_UPDATE_ON_VALIDATION_ERROR to %d, to force the "
            "update of the VPD ECC data for MVPDs if any VPD ECC data has a mismatch. ",
            sys->getAttr<TARGETING::ATTR_FORCE_ECC_UPDATE_ON_VALIDATION_ERROR>() );
#endif
    }

    /* @TODO RTC 245390: Update for P10 DD 1.0 */
#if 0
    // Add a check to indicate that Nimbus DD1.0 is NOT supported
    // and prevent a boot
    PVR_t l_pvr( mmio_pvr_read() & 0xFFFFFFFF );
    if( l_pvr.isNimbusDD1() )
    {
#ifdef CONFIG_CONSOLE
        CONSOLE::displayf(CONSOLE::DEFAULT, ISTEP_COMP_NAME,
                          "P9N (Nimbus) DD1.0 is not supported in this driver");
        CONSOLE::displayf(CONSOLE::DEFAULT, ISTEP_COMP_NAME,
                          "Please update the system's processor modules");
#endif


        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   "DD1.0 is NOT SUPPORTED anymore. "
                   "Please upgrade proc modules");
        /*@
         * @errortype
         * @moduleid     ISTEP::MOD_SET_IPL_PARMS
         * @reasoncode   ISTEP::RC_P9N_DD1_NOT_SUPPORTED
         * @userdata1    PVR of master proc
         * @devdesc      P9N (Nimbus) DD1.x is not supported
         *               in this firmware driver.  Please update
         *               your module or use a different driver
         * @custdesc     A problem occurred during the IPL
         *               of the system.
         */
        uint64_t l_dummy = 0x0;
        l_err = new ERRORLOG::ErrlEntry(
                                        ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                        ISTEP::MOD_SET_IPL_PARMS,
                                        ISTEP::RC_P9N_DD1_NOT_SUPPORTED,
                                        l_pvr.word,
                                        l_dummy);
        // Create IStep error log and cross ref error that occurred
        l_stepError.addErrorDetails( l_err );
        errlCommit( l_err, ISTEP_COMP_ID );
    }
#endif

#if (defined(CONFIG_PNORDD_IS_BMCMBOX) || defined(CONFIG_PNORDD_IS_IPMI))
    // Add a check to indicate the BMC does not support HIOMAP pnor-ipmi access
    // and the BMC firmware should be updated
    errlHndl_t l_pnor_err; // needed for scope compilation
    PNOR::hiomapMode l_mode = PNOR::getPnorAccessMode();
    if( l_mode != PNOR::PNOR_IPMI )
    {
#ifdef CONFIG_CONSOLE
        CONSOLE::displayf(CONSOLE::DEFAULT, ISTEP_COMP_NAME,
            "HIOMAP PNOR-IPMI not enabled, BMC firmware needs to be updated.");
#endif

        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
            "HIOMAP PNOR-IPMI not enabled, BMC firmware needs to be updated.");

#ifdef CONFIG_PNORDD_IS_BMCMBOX
        bool l_IS_BMCMBOX = true;
#else
        bool l_IS_BMCMBOX = false;
#endif

#ifdef CONFIG_PNORDD_IS_IPMI
        bool l_IS_IPMI = true;
#else
        bool l_IS_IPMI = false;
#endif

        /*@
         * @errortype
         * @moduleid     ISTEP::MOD_SET_IPL_PARMS
         * @reasoncode   ISTEP::RC_PNOR_IPMI_NOT_ENABLED
         * @userdata1    HIOMAP Mode
         * @userdata2[0-31]  CONFIG_PNORDD_IS_BMCMBOX
         * @userdata2[32:63] CONFIG_PNORDD_IS_IPMI
         * @devdesc      PNOR-IPMI not enabled, BMC firmware needs to be updated
         * @custdesc     Check BMC firmware version and update
         */
        l_pnor_err = new ERRORLOG::ErrlEntry(
                                        ERRORLOG::ERRL_SEV_PREDICTIVE,
                                        ISTEP::MOD_SET_IPL_PARMS,
                                        ISTEP::RC_PNOR_IPMI_NOT_ENABLED,
                                        l_mode,
                                        TWO_UINT32_TO_UINT64(
                                            l_IS_BMCMBOX,
                                            l_IS_IPMI));

        l_pnor_err->addProcedureCallout(HWAS::EPUB_PRC_SP_CODE,
                                   HWAS::SRCI_PRIORITY_HIGH);

        l_pnor_err->collectTrace(PNOR_COMP_NAME);
        l_pnor_err->collectTrace("ISTEPS_TRACE",256);

        // Create IStep error log and cross ref error that occurred
        l_stepError.addErrorDetails( l_pnor_err );
        errlCommit( l_pnor_err, ISTEP_COMP_ID );
    }
#endif

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "host_set_ipl_parms exit" );

    }while(0);

    return l_stepError.getErrorHandle();
}

};
