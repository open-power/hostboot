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

#ifdef CONFIG_PLDM
#include <pldm/base/hb_bios_attrs.H>
#include <pldm/pldm_errl.H>
#include <targeting/common/mfgFlagAccessors.H>
#endif

#if (defined(CONFIG_PNORDD_IS_BMCMBOX) || defined(CONFIG_PNORDD_IS_IPMI))
#include <pnor/pnorif.H>
#endif

using namespace TARGETING;
using namespace ISTEP;

namespace ISTEP_06
{
#ifdef CONFIG_PLDM


/**
 * @brief Retrieve the TPM Required Policy from the BMC BIOS and set the system
 *        attribute ATTR_TPM_REQUIRED to the retrieved value, if no error occurred.
 *        If an error occurs retrieving the BMC BIOS, then the attribute is left as is.
 *
 * @param[in,out] io_string_table   See brief in file hb_bios_attrs.H.
 * @param[in,out] io_attr_table     See brief in file hb_bios_attrs.H.
 * @param[in]     i_systemTarget    The system target handle.
 *
 * @return Error if failed to retrieve the TPM Required Policy, otherwise nullptr on success
*/
errlHndl_t getAndSetTpmRequiredPolicyFromBmcBios( std::vector<uint8_t>& io_string_table,
                                                  std::vector<uint8_t>& io_attr_table,
                                                  TARGETING::TargetHandle_t i_systemTarget)
{
    // Create a variable to hold the retrieved TPM Required Policy value from the BMC BIOS
    // Default to TPM is required
    TARGETING::ATTR_TPM_REQUIRED_type l_tpmRequiredPolicy(1);

    // Get the TPM Required Policy from the BMC BIOS
    errlHndl_t l_errl = PLDM::getTpmRequiredPolicy(io_string_table, io_attr_table,
                                                   l_tpmRequiredPolicy);
    if ( unlikely(l_errl != nullptr) )
    {
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, ERR_MRK
                   "getAndSetTpmRequiredPolicyFromBmcBios(): An error occurred getting "
                   "the TPM Required Policy from the BMC BIOS. Leaving the system "
                   "attribute ATTR_TPM_REQUIRED at its current value %d.",
                   static_cast<uint16_t>(i_systemTarget->getAttr<ATTR_TPM_REQUIRED>()) );
    }
    else
    {
        // Set the system attribute ATTR_TPM_REQUIRED to the retrieved value
        i_systemTarget->setAttr<TARGETING::ATTR_TPM_REQUIRED>(l_tpmRequiredPolicy);
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, INFO_MRK
                   "getAndSetTpmRequiredPolicyFromBmcBios(): Succeeded in getting the BMC "
                   "BIOS TPM Required Policy value %d, and setting the attribute "
                   "ATTR_TPM_REQUIRED to %d for the system",
                    l_tpmRequiredPolicy,
                    static_cast<uint16_t>(i_systemTarget->getAttr<ATTR_TPM_REQUIRED>()) );
    }
    return l_errl;
}


/**
 * @brief Retrieve the Field Core Override (FCO) from the BMC BIOS and set the system's
 *        nodes attribute ATTR_FIELD_CORE_OVERRIDE to the retrieved value,
 *        if no error occurred. If an error occurs retrieving the BMC BIOS, then the
 *        attribute, for the individual NODE targets, is left as is.
 *
 * @note Changing the attribute ATTR_FIELD_CORE_OVERRIDE to all existing nodes and not
 *       just functional nodes because discover targets has not been run yet.
 *
 * @param[in,out] io_string_table   See brief in file hb_bios_attrs.H.
 * @param[in,out] io_attr_table     See brief in file hb_bios_attrs.H.
 * @param[in] i_systemTarget  The System's target to which the all NODE targets
 *                            will have their attribute ATTR_FIELD_CORE_OVERRIDE
 *                            set, if no error occurred retrieving the BMC BIOS value.
 *
 * @return Error if failed to retrieve the FCO, otherwise nullptr on success
*/
errlHndl_t getAndSetFieldCoreOverrideFromBmcBios( std::vector<uint8_t>& io_string_table,
                                                  std::vector<uint8_t>& io_attr_table,
                                                  TARGETING::TargetHandle_t i_systemTarget)
{
    // Create a variable to hold the retrieved FCO value from the BMC BIOS
    TARGETING::ATTR_FIELD_CORE_OVERRIDE_type l_fieldCoreOverride(0);

    // Get the FCO from the BMC BIOS
    errlHndl_t l_errl = PLDM::getFieldCoreOverride(io_string_table, io_attr_table,
                                                   l_fieldCoreOverride);
    if ( unlikely(l_errl != nullptr) )
    {
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, ERR_MRK
                   "getAndSetFieldCoreOverrideFromBmcBios(): An error occurred getting "
                   "the Field Core Override(FCO) from the BMC BIOS. Leaving the FCO for "
                   "the individual NODE targets as is." );
    }
    else
    {
        // Iterate over all of the nodes, not just functional, and set ALL the node's
        // attribute ATTR_FIELD_CORE_OVERRIDE to the retrieved BMC FCO BIOS value.
        // Setting all of the nodes and not just functional nodes, because discover
        // targets has not been run yet and therefore no functional targets have
        // been established.
        PredicateCTM predNode(CLASS_ENC, TYPE_NODE);
        PredicatePostfixExpr nodeCheckExpr;
        nodeCheckExpr.push(&predNode);

        TargetHandleList l_nodeTargetList;
        targetService().getAssociated(l_nodeTargetList, i_systemTarget,
                        TargetService::CHILD, TargetService::IMMEDIATE,
                        &nodeCheckExpr);

        for(const auto& l_nodeTarget : l_nodeTargetList)
        {
            l_nodeTarget->setAttr<ATTR_FIELD_CORE_OVERRIDE>(l_fieldCoreOverride);
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, INFO_MRK
                       "getAndSetFieldCoreOverrideFromBmcBios(): Succeeded in getting the BMC "
                       "BIOS Field Core Override(FCO) attribute %d, and setting the attribute "
                       "ATTR_FIELD_CORE_OVERRIDE to %d for NODE target 0x%0.8x",
                        l_fieldCoreOverride,
                        l_nodeTarget->getAttr<ATTR_FIELD_CORE_OVERRIDE>(),
                        get_huid(l_nodeTarget) );
        }
    }
    return l_errl;
}

/*
 * @brief Retrieve the USB Security State from the BMC BIOS and set the system
 *        attribute ATTR_USB_SECURITY to the retrieved value, if no error occurred.
 *        If an error occurs retrieving the BMC BIOS, then the attribute is left as is.
 *
 * @param[in,out] io_string_table   See brief in file hb_bios_attrs.H
 * @param[in,out] io_attr_table     See brief in file hb_bios_attrs.H
 * @param[in]     i_sys             System target handle
 *
 * @return Error if failed to retrieve the USB security state, otherwise nullptr
 */
errlHndl_t getAndSetUsbSecurityFromBmcBios(std::vector<uint8_t>& io_string_table,
                                           std::vector<uint8_t>& io_attr_table,
                                           TARGETING::TargetHandle_t i_sys)
{
    // Create a variable to hold the retrieved USB security value from the BMC BIOS
    TARGETING::ATTR_USB_SECURITY_type l_usbSecurity(0);

    // Get the USB Security from the BMC BIOS
    errlHndl_t l_errl = PLDM::getUsbSecurity(io_string_table, io_attr_table,
                                             l_usbSecurity);

    if (unlikely(l_errl != nullptr))
    {
        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace, ERR_MRK
                  "getAndSetUsbSecurityFromBmcBios(): An error occurred getting "
                  "USB Security State from the BMC BIOS. Leaving the system "
                  "attribute ATTR_USB_SECURITY at its current value %d",
                  i_sys->getAttr<ATTR_USB_SECURITY>());
    }
    else
    {
        // Set the system attribute ATTR_USB_SECURITY to the retrieved value
        i_sys->setAttr<ATTR_USB_SECURITY>(l_usbSecurity);
        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace, INFO_MRK
                  "getAndSetUsbSecurityFromBmcBios(): Succeeded in getting the BMC "
                  "BIOS USB Securirty State attribute %d and setting the attribute "
                  "ATTR_USB_SECURITY",
                  l_usbSecurity);
    }

    return l_errl;
}

/*
 * @brief Retrieve the Mirror Memory State from the BMC BIOS and set the system
 *        attribute ATTR_PAYLOAD_IN_MIRROR_MEM to the retrieved value, if no error occurred.
 *        If an error occurs retrieving the BMC BIOS, then the attribute is left as is.
 *
 * @param[in,out] io_string_table  See brief in file hb_bios_attrs.H
 * @param[in,out] io_attr_table    See brief in file hb_bios_attrs.H
 * @param[in]     i_sys            System target handle
 *
 * @return Error if failed to retrieve the mirror memory value, otherwise nullptr
 */
errlHndl_t getAndSetMirrorMemoryFromBmcBios(std::vector<uint8_t>& io_string_table,
                                            std::vector<uint8_t>& io_attr_table,
                                            TARGETING::TargetHandle_t i_sys)
{
    // Create a variable to hold the retrieved Mirror Memory value from the BMC BIOS
    TARGETING::ATTR_PAYLOAD_IN_MIRROR_MEM_type l_mirrorMemory(0);

    // Get the Mirror Memory from the BMC BIOS
    errlHndl_t l_errl = PLDM::getMirrorMemory(io_string_table, io_attr_table,
                                              l_mirrorMemory);

    if (unlikely(l_errl != nullptr))
    {
        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace, ERR_MRK
                  "getAndSetMirrorMemoryFromBmcBios(): An error occurred getting "
                  "Mirror Memory value from the BMC BIOS. Leaving the system "
                  "attribute ATTR_PAYLOAD_IN_MIRROR_MEM at its current value %d",
                  i_sys->getAttr<ATTR_PAYLOAD_IN_MIRROR_MEM>());
    }
    else
    {
        // Set the system attribute ATTR_PAYLOAD_IN_MIRROR_MEM to the retrieved value
        i_sys->setAttr<ATTR_PAYLOAD_IN_MIRROR_MEM>(l_mirrorMemory);
        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace, INFO_MRK
                  "getAndSetMirrorMemoryFromBmcBios(): Succeeded in getting the BMC "
                  "BIOS Mirror Memory value %d and setting the attribute "
                  "ATTR_PAYLOAD_IN_MIRROR_MEM",
                  l_mirrorMemory);
    }
    return l_errl;
}

/*
 * @brief Retrieve the Key Clear Request from the BMC BIOS and set the all the nodes'
 *        attribute ATTR_KEY_CLEAR_REQUEST to the retrieved value, if no error occurred.
 *        If an error occurs retrieving the BMC BIOS attribute, then the hostboot attribute
 *        is set to KEY_CLEAR_REQUEST_NONE.
 *
 * @param[in,out] io_string_table   See brief in file hb_bios_attrs.H
 * @param[in,out] io_attr_table     See brief in file hb_bios_attrs.H
 *
 * @return Error if failed to retrieve the Key Clear Request, otherwise nullptr
 */
errlHndl_t getAndSetKeyClearRequestFromBmcBios(std::vector<uint8_t>& io_string_table,
                                               std::vector<uint8_t>& io_attr_table)
{
    // Create a variable to hold the retrieved Key Clear Request value from the BMC BIOS
    TARGETING::ATTR_KEY_CLEAR_REQUEST_type l_keyClearRequest = TARGETING::KEY_CLEAR_REQUEST_INVALID;

    // Get the Key Clear Request from the BMC BIOS
    errlHndl_t l_errl = PLDM::getKeyClearRequest(io_string_table, io_attr_table,
                                                 l_keyClearRequest);

    if (unlikely(l_errl != nullptr) || l_keyClearRequest == TARGETING::KEY_CLEAR_REQUEST_INVALID)
    {
        // if there was an error reading the BIOS attr or the KEY_CLEAR_REQUEST returned is
        // INVALID, then default to seting all nodes to KEY_CLEAR_REQUEST_NONE
        l_keyClearRequest = KEY_CLEAR_REQUEST_NONE;
        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace, ERR_MRK
                  "getAndSetKeyClearRequestFromBmcBios(): An error occurred getting "
                  "Key Clear Request from the BMC BIOS. Defaulting all node "
                  "attributes to KEY_CLEAR_REQUEST_NONE (0x%X)",
                  l_keyClearRequest);
    }
    else
    {
        // Set the node attribute ATTR_KEY_CLEAR_REQUEST to the retrieved value
        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace, INFO_MRK
                  "getAndSetKeyClearRequestFromBmcBios(): Succeeded in getting the BMC "
                  "BIOS Key Clear Request 0x%X",
                  l_keyClearRequest);
    }

    // Iterate over all of the nodes, not just functional, and set ALL the node's
    // attribute ATTR_KEY_CLEAR_REQUEST to l_keyClearRequest.
    // Setting all of the nodes and not just functional nodes, because discover
    // targets has not been run yet and therefore no functional targets have
    // been established.
    TargetHandleList l_nodeTargetList;
    getEncResources(l_nodeTargetList, TARGETING::TYPE_NODE, TARGETING::UTIL_FILTER_ALL);

    for(const auto& l_nodeTarget : l_nodeTargetList)
    {
        l_nodeTarget->setAttr<ATTR_KEY_CLEAR_REQUEST>(l_keyClearRequest);
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, INFO_MRK
                   "getAndSetKeyClearRequestFromBmcBios(): setting the Hostboot attribute "
                   "ATTR_KEY_CLEAR_REQUEST to 0x%X for NODE target 0x%0.8x",
                    l_keyClearRequest,
                    get_huid(l_nodeTarget) );
    }

    return l_errl;
}

errlHndl_t getAndSetPLDMBiosAttrs()
{
    errlHndl_t errl = nullptr;

    do {

    std::vector<uint8_t> bios_string_table;
    std::vector<uint8_t> bios_attr_table;
    const auto sys = TARGETING::UTIL::assertGetToplevelTarget();

    // Retrieve the Field Core Override value from the BMC bios and set all of
    // the NODE target's attribute ATTR_FIELD_CORE_OVERRIDE to that value.
    errl = getAndSetFieldCoreOverrideFromBmcBios(bios_string_table, bios_attr_table, sys);
    if(errl)
    {
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "getAndSetPLDMBiosAttrs: "
                   "getAndSetFieldCoreOverrideFromBmcBios failed to get and then set the FCO" );
        errlCommit( errl, ISTEP_COMP_ID );
    }

    // =================================================================
    // HUGE_PAGE_COUNT
    // =================================================================
    ATTR_HUGE_PAGE_COUNT_type huge_page_count = 0;
    const size_t DEFAULT_HUGE_PAGE_COUNT = 0;

    errl = PLDM::getHugePageCount(bios_string_table,
                                  bios_attr_table,
                                  huge_page_count);
    if(errl)
    {
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "getAndSetPLDMBiosAttrs: "
                "An error occurred getting Huge Page Count from the BMC, using default 0x%X",
                DEFAULT_HUGE_PAGE_COUNT );

        // Set count to default, commit the error and continue
        huge_page_count = DEFAULT_HUGE_PAGE_COUNT;
        errlCommit( errl, ISTEP_COMP_ID );
    }

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
            "getAndSetPLDMBiosAttrs: Set ATTR_HUGE_PAGE_COUNT = 0x%X",
            huge_page_count );
    sys->setAttr<ATTR_HUGE_PAGE_COUNT>(huge_page_count);

    // =================================================================
    // HUGE_PAGE_SIZE
    // =================================================================
    ATTR_HUGE_PAGE_SIZE_type huge_page_size = 0;
    // HDAT spec: 0 = 16GB
    const size_t DEFAULT_HUGE_PAGE_SIZE = 0;

    errl = PLDM::getHugePageSize(bios_string_table,
            bios_attr_table,
            huge_page_size);
    if(errl)
    {
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "getAndSetPLDMBiosAttrs: An error occurred getting Huge Page Size from the BMC, using default 0x%X",
                DEFAULT_HUGE_PAGE_SIZE );

        // Set size to default, commit the error and continue
        huge_page_size = DEFAULT_HUGE_PAGE_SIZE;
        errlCommit( errl, ISTEP_COMP_ID );
    }

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
            "getAndSetPLDMBiosAttrs: Set ATTR_HUGE_PAGE_SIZE = 0x%X",
            huge_page_size );
    sys->setAttr<ATTR_HUGE_PAGE_SIZE>(huge_page_size);


    // =================================================================
    // LMB_SIZE
    // =================================================================
    ATTR_LMB_SIZE_type lmb_size = 0;

    errl = PLDM::getLmbSize(bios_string_table,
            bios_attr_table,
            lmb_size);
    if(errl)
    {
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   "getAndSetPLDMBiosAttrs: An error occurred getting LMB Size from the BMC, using default 0x%X",
                   PLDM::LMB_SIZE_ENCODE_256MB );

        // Set size to default, commit the error and continue
        lmb_size = PLDM::LMB_SIZE_ENCODE_256MB;
        errlCommit( errl, ISTEP_COMP_ID );
    }

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
            "getAndSetPLDMBiosAttrs: Set ATTR_LMB_SIZE = 0x%X",
            lmb_size );
    sys->setAttr<ATTR_LMB_SIZE>(lmb_size);

    // =================================================================
    // ATTR_MFG_FLAGS
    // =================================================================
    ATTR_MFG_FLAGS_typeStdArr mfg_flags = {0};
    const ATTR_MFG_FLAGS_typeStdArr DEFAULT_MFG_FLAGS = {0};

    errl = PLDM::getMfgFlags(bios_string_table,
            bios_attr_table,
            mfg_flags);
    if(errl)
    {
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "getAndSetPLDMBiosAttrs: An error occurred getting Mfg Flags from the BMC, using default 0" );

        // Set flags to default, commit the error and continue
        mfg_flags = DEFAULT_MFG_FLAGS;
        errlCommit( errl, ISTEP_COMP_ID );
    }

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
            "getAndSetPLDMBiosAttrs: Set ATTR_MFG_FLAGS = 0x%X 0x%X 0x%X 0x%X",
            mfg_flags[0], mfg_flags[1], mfg_flags[2], mfg_flags[3] );
    TARGETING::setAllMfgFlags(mfg_flags);


    // =================================================================
    // PAYLOAD_KIND
    // =================================================================
    ATTR_PAYLOAD_KIND_type payload_kind = PAYLOAD_KIND_UNKNOWN;

    errl = PLDM::getHypervisorMode(bios_string_table,
            bios_attr_table,
            payload_kind);

    // If we get an error, or are returned a payload_kind
    // that is not PHYP or SAPPHIRE then we do not know
    // what payload to pick. We cannot assume the payload
    // kind as booting for the incorrect hypervisor could
    // result in loss of data in NVRAM that was generated
    // by the hypervisor on previous boots.
    if(errl)
    {
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "getAndSetPLDMBiosAttrs: An error occurred getting Hypervisor Mode from the BMC" );
        break;
    }

    if(payload_kind != PAYLOAD_KIND_PHYP &&
            payload_kind != PAYLOAD_KIND_SAPPHIRE)
    {
        /*@
         * @errortype
         * @severity   ERRL_SEV_UNRECOVERABLE
         * @moduleid   MOD_SET_IPL_PARMS
         * @reasoncode RC_INVALID_PAYLOAD_KIND
         * @userdata1  Payload Kind that BMC returned
         * @userdata2  unused
         * @devdesc    Software problem, bad data from BMC
         * @custdesc   A software error occurred during system boot
         */
        errl = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                MOD_SET_IPL_PARMS,
                RC_INVALID_PAYLOAD_KIND,
                payload_kind,
                0,
                ErrlEntry::NO_SW_CALLOUT);
        PLDM::addBmcErrorCallouts(errl);
        break;
    }

    sys->setAttr<ATTR_PAYLOAD_KIND>(payload_kind);

    // =================================================================
    // HYPERVISOR_IPL_SIDE
    // =================================================================
    TARGETING::ATTR_HYPERVISOR_IPL_SIDE_type bootside = HYPERVISOR_IPL_SIDE_UNKNOWN;

    errl = PLDM::getBootside(bios_string_table, bios_attr_table, bootside);

    if (errl != nullptr)
    {
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "getAndSetPLDMBiosAttrs: An error occurred getting bootside from the BMC" );
        break;
    }

    if ((bootside != HYPERVISOR_IPL_SIDE_PERM) && (bootside != HYPERVISOR_IPL_SIDE_TEMP))
    {
        /*@
         * @errortype
         * @severity   ERRL_SEV_UNRECOVERABLE
         * @moduleid   MOD_SET_IPL_PARMS
         * @reasoncode RC_INVALID_BOOTSIDE
         * @userdata1  Bootside that BMC returned
         * @userdata2  unused
         * @devdesc    Software problem, bad data from BMC
         * @custdesc   A software error occurred during system boot
         */
        errl = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                MOD_SET_IPL_PARMS,
                RC_INVALID_BOOTSIDE,
                bootside,
                0,
                ErrlEntry::NO_SW_CALLOUT);
        PLDM::addBmcErrorCallouts(errl);
        break;
    }

    sys->setAttr<TARGETING::ATTR_HYPERVISOR_IPL_SIDE>(bootside);

    // Retrieve the Usb Security value from the BMC bios and set the
    // system attribute ATTR_USB_SECURITY to that value.
    errl = getAndSetUsbSecurityFromBmcBios(bios_string_table, bios_attr_table, sys);
    if (errl)
    {
        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace, "getAndSetPLDMBiosAttrs: "
              "getAndSetUsbSecurityFromBmcBios failed to get and then set the security state");
        errlCommit(errl, ISTEP_COMP_ID);
    }

    // Retrieve the Mirror Memory value from the BMC bios and set the
    // system attribute ATTR_PAYLOAD_IN_MIRROR_MEM to that value.
    errl = getAndSetMirrorMemoryFromBmcBios(bios_string_table, bios_attr_table, sys);
    if (errl)
    {
        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace, "getAndSetPLDMBiosAttrs : "
              "getAndSetMirrorMemoryFromBmcBios failed to get and then set the memory mirror value");
        errlCommit(errl, ISTEP_COMP_ID);
    }

        // Retrieve the TPM Required Policy value from the BMC BIOS and set the
        // system attribute ATTR_TPM_REQUIRED to that value.
        errl = getAndSetTpmRequiredPolicyFromBmcBios(bios_string_table, bios_attr_table, sys);
        if (errl)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace, "getAndSetPLDMBiosAttrs : "
                  "getAndSetTpmRequiredPolicyFromBmcBios failed to get and then set "
                  "the TPM Required policy value");
            errlCommit(errl, ISTEP_COMP_ID);
        }

    TARGETING::ATTR_SECURE_VERSION_LOCKIN_POLICY_type l_lockinPolicy = false;
    errl = PLDM::getSecVerLockinEnabled(bios_string_table, bios_attr_table, l_lockinPolicy);
    if(errl)
    {
        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace, "getAndSetPLDMBiosAttrs: could not get the secureboot version lockin policy from BMC");
        errlCommit(errl, ISTEP_COMP_ID);
        l_lockinPolicy = false;
    }
    sys->setAttr<TARGETING::ATTR_SECURE_VERSION_LOCKIN_POLICY>(l_lockinPolicy);

    // Retrieve the Key Clear Request value from the BMC bios and set all the
    // node attributes ATTR_KEY_CLEAR_REQUEST to that value.
    errl = getAndSetKeyClearRequestFromBmcBios(bios_string_table, bios_attr_table);
    if (errl)
    {
        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace, "getAndSetPLDMBiosAttrs: "
                  "getAndSetKeyClearRequestFromBmcBios failed to get and then set the Key Clear Request");
        errlCommit(errl, ISTEP_COMP_ID);
    }

    }while(0);

    return errl;
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
        errlHndl_t l_pldm_err; // needed for scope compilation
        const auto sys = TARGETING::UTIL::assertGetToplevelTarget();
        if(!sys->getAttr<ATTR_IS_MPIPL_HB>())
        {
            l_pldm_err = getAndSetPLDMBiosAttrs();
            if(l_pldm_err)
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                          "host_set_ipl_parms: error occurred getting/setting PLDM bios attrs");
                l_pldm_err->collectTrace("ISTEPS_TRACE",256);
                l_stepError.addErrorDetails( l_pldm_err );
                errlCommit( l_pldm_err, ISTEP_COMP_ID );
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
