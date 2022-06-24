/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hdat/hdathostslcadata.C $                             */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2022                        */
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

#include <devicefw/userif.H>
#include <hdat/hdat.H>
#include <targeting/common/target.H>
#include "hdatutil.H"
#include "hdathostslcadata.H"
#include <sys/mm.h>
#include <sys/mmio.h>
#include <vpd/vpd_if.H>

#ifdef HDAT_DEBUG
#include <iostream>
#endif
#include <targeting/common/util.H>
#include <string.h>
#include <util/align.H>

using namespace TARGETING;
using namespace std;
using namespace VPD;

namespace HDAT
{

extern trace_desc_t *g_trac_hdat;


fru_id_rid_t g_fruIDRidMap[] =
{
    {0x0800 , "BP"},
    {0x1E00 , "EV"},
    {0x1C00 , "SV"},
    {0x1000 , "PF"},
    {0xD000 , "MS"},
    {0x3600 , "PI"},
    {0x0200 , "SP"},
    {0x3100 , "PS"},
    {0x3A00 , "AM"},
    {0x2900 , "CU"},
    {0x2800 , "CE"},
    {0x0300 , "OP"},
    {0x3900 , "RG"},
    {0xA100 , "SA"},
    {0xA200 , "EI"},
    {0xA300 , "EF"},
    {0x2A00 , "CS"},
    {0xD000 , "MS"},
    {0xA000 , "VV"},
    {0x1400 , "RI"},
    {0x4900 , "IP"}, // TPM
};


/**
 * @brief This helper routine returns VPD Collected status
 *
 * @pre None
 *
 * @post None
 *
 * @param i_Target   - input parameter - Target of parent FRU
 *
 * @return True  : VPD is collected
 *         False : VPD is not collected
 *
 * @retval HDAT_OTHER_COMP_ERROR
 */
bool getVPDCollectedStatus(TARGETING::Target *i_Target)
{
    bool l_vpdCollectedStatus = true;
    l_vpdCollectedStatus = i_Target->getAttr<ATTR_HWAS_STATE>().functional;

    return l_vpdCollectedStatus;
}

/**
 * @brief This routine adds a new SLCA entry for specified target
 *
 * @pre None
 *
 * @post None
 *
 * @param i_Target   - input parameter - Target for which slca entry
 *                                       is added
 *        i_frutype  - input parameter - FRU Type of the Target
 *        i_slcaParentIndex - input parameter - Index of parent FRU
 *        o_hdatslca - output parameter - Vector containing slca entries
 *                                        for DIMMs
 *
 * @return Index of Last SLCA entry added
 *
 * @retval HDAT_OTHER_COMP_ERROR
 */
uint16_t hdatAddSLCAEntry( TARGETING::Target *i_Target,
                           HDAT_FRUType_t i_frutype,
                           uint16_t i_slcaparentindex,
                           vector<HDAT_slcaEntry_t> &o_hdatslca )
{
    HDAT_ENTER();
    //Values for the SLCA's collected and installed fields
    #define HDAT_SLCA_COLLECTED      2
    #define HDAT_SLCA_NOT_COLLECTED  3
    #define HDAT_SLCA_NO_PD_INFO     1
    #define HDAT_SLCA_INSTALLED      2
    #define HDAT_SLCA_NOT_INSTALLED  3
    HDAT_slcaEntry_t l_hdatslcaentry;

    TARGETING::PldmEntityIdInfo pldmEntityId = {0};
    TARGETING::SystemPldmEntityIdInfo sypldmEntityId = {0};
    TARGETING::ChassisPldmEntityIdInfo chaspldmEntityId = {0};
    TARGETING::ConnectorPldmEntityIdInfo conPldmEntityId = {0};
    TARGETING::Target *l_pSystemTarget = UTIL::assertGetToplevelTarget();
    if(i_frutype == HDAT_SLCA_FRU_TYPE_SV ||
        i_frutype == HDAT_SLCA_FRU_TYPE_VV)
    {
        if(!(l_pSystemTarget->tryGetAttr<TARGETING::ATTR_SYSTEM_PLDM_ENTITY_ID_INFO>
                            (sypldmEntityId)))
        {
            HDAT_ERR("error reading PLDM_ENTITY_ID_INFO for SV or VV");
        }
        else
        {
            HDAT_DBG("fetched PLDM ENTITY ID for SYS");
            l_hdatslcaentry.pldm_entity_id.entityType =
                               sypldmEntityId.entityType;
            l_hdatslcaentry.pldm_entity_id.entityInstanceNumber =
                               sypldmEntityId.entityInstanceNumber;
            l_hdatslcaentry.pldm_entity_id.containerId =
                               sypldmEntityId.containerId;

        }
    }
    else if(i_frutype == HDAT_SLCA_FRU_TYPE_EV)
    {
        if(!(l_pSystemTarget->tryGetAttr<TARGETING::ATTR_CHASSIS_PLDM_ENTITY_ID_INFO>
                             (chaspldmEntityId)))
        {
            HDAT_ERR("error reading PLDM_ENTITY_ID_INFO for EV");
        }
        else
        {
            HDAT_DBG("fetched PLDM ENTITY ID for CHASSIS");
            l_hdatslcaentry.pldm_entity_id.entityType =
                                chaspldmEntityId.entityType;
            l_hdatslcaentry.pldm_entity_id.entityInstanceNumber =
                                chaspldmEntityId.entityInstanceNumber;
            l_hdatslcaentry.pldm_entity_id.containerId =
                                chaspldmEntityId.containerId;
        }
    }
    else if( (l_pSystemTarget->getAttr<
              TARGETING::ATTR_PLDM_CONNECTOR_PDRS_ENABLED>())
             &&
             ( (i_frutype == HDAT_SLCA_FRU_TYPE_DIMM) ||
               (i_frutype == HDAT_SLCA_FRU_TYPE_PROC)
             )
           )
    {
        conPldmEntityId =
        i_Target->getAttr<TARGETING::ATTR_CONNECTOR_PLDM_ENTITY_ID_INFO>();
        HDAT_DBG("fetched PLDM ENTITY ID for Connector");
        l_hdatslcaentry.pldm_entity_id.entityType =
                            conPldmEntityId.entityType;
        l_hdatslcaentry.pldm_entity_id.entityInstanceNumber =
                            conPldmEntityId.entityInstanceNumber;
        l_hdatslcaentry.pldm_entity_id.containerId =
                            conPldmEntityId.containerId;
    }
    else
    {
        if(!(i_Target->tryGetAttr<TARGETING::ATTR_PLDM_ENTITY_ID_INFO>
            (reinterpret_cast<TARGETING::ATTR_PLDM_ENTITY_ID_INFO_type&>
                        (pldmEntityId))))
        {
            HDAT_ERR("error reading PLDM_ENTITY_ID_INFO");
        }
        else
        {
            HDAT_DBG("fetched PLDM ENTITY ID");
            l_hdatslcaentry.pldm_entity_id.entityType =
                              pldmEntityId.entityType;
            l_hdatslcaentry.pldm_entity_id.entityInstanceNumber =
                              pldmEntityId.entityInstanceNumber;
            l_hdatslcaentry.pldm_entity_id.containerId =
                              pldmEntityId.containerId;
        }
    }

     HDAT_DBG("fetched PLDM ENTITY ID as 0x%x, 0x%x, 0x%x",
              l_hdatslcaentry.pldm_entity_id.entityType,
              l_hdatslcaentry.pldm_entity_id.entityInstanceNumber,
              l_hdatslcaentry.pldm_entity_id.containerId);

    l_hdatslcaentry.fru_index             = o_hdatslca.size();
    l_hdatslcaentry.fru_rid               = g_fruIDRidMap[i_frutype].fru_rid++;

    strncpy(l_hdatslcaentry.fru_id,
                            (const char *)g_fruIDRidMap[i_frutype].fru_id,
                                           sizeof(l_hdatslcaentry.fru_id));

    l_hdatslcaentry.parent_index = i_slcaparentindex;
    l_hdatslcaentry.first_child_rid       = 0xFFFF;
    l_hdatslcaentry.max_location_code_len = 64;

    memset(l_hdatslcaentry.location_code , 0 ,
                                         l_hdatslcaentry.max_location_code_len);

    hdatGetLocationCode(i_Target,i_frutype,
                                                 l_hdatslcaentry.location_code);
    uint32_t l_length = strlen(l_hdatslcaentry.location_code);
    l_hdatslcaentry.location_code[l_length]='\0';
    l_hdatslcaentry.actual_location_code_len = l_length + 1;

    l_hdatslcaentry.number_of_children      = 0x0;
    l_hdatslcaentry.first_child_index       = 0xFFFF;
    l_hdatslcaentry.first_redundant_index   = 0xFFFF;
    l_hdatslcaentry.number_redundant_copies = 0x0;
    l_hdatslcaentry.number_of_children_2B   = 0x0;
    l_hdatslcaentry.first_child_pldm_entity_id.entityType = 0xFFFF;
    l_hdatslcaentry.first_child_pldm_entity_id.entityInstanceNumber = 0xFFFF;
    l_hdatslcaentry.first_child_pldm_entity_id.containerId = 0xFFFF;

    l_hdatslcaentry.installed = HDAT_SLCA_INSTALLED;
    if(getVPDCollectedStatus(i_Target))
    {
        l_hdatslcaentry.collected = HDAT_SLCA_COLLECTED;
    }
    else
    {
        l_hdatslcaentry.collected = HDAT_SLCA_NOT_COLLECTED;
    }

    o_hdatslca.push_back(l_hdatslcaentry);

    if(i_frutype != HDAT_SLCA_FRU_TYPE_EV && i_frutype != HDAT_SLCA_FRU_TYPE_VV)
    {
        if(!i_Target->trySetAttr<TARGETING::ATTR_SLCA_INDEX>
                                                        (o_hdatslca.size() - 1))
        {
            HDAT_ERR("Error while setting SLCA_INDEX attribute for frutype: %d",
                                                                   i_frutype);
        }
        if(!i_Target->trySetAttr<TARGETING::ATTR_SLCA_RID>
                                                     (l_hdatslcaentry.fru_rid))
        {
            HDAT_ERR("Error while setting SLCA_RID attribute for frutype: %d",
                                                                   i_frutype);
        }
    }
    HDAT_DBG("Added SLCA Entry  FI : %s loc_code : %s",
                                              g_fruIDRidMap[i_frutype].fru_id,
                                              l_hdatslcaentry.location_code);
    HDAT_EXIT();
    return(o_hdatslca.size() - 1);
}

/**
 * @brief This routine adds Nodes and its children to SLCA table
 *
 * @pre None
 *
 * @post None
 *
 * @param i_Target   - input parameter - Target of Node FRU being added
 *        i_slcaParentIndex - input parameter - Index of parent FRU
 *        o_hdatslca - output parameter - Vector containing slca entries
 *
 * @return Number of DIMMs added
 *
 */
static void hdatAddNodeToSLCATable(TARGETING::Target *i_Target,
                                 uint16_t i_slcaParentIndex,
                         vector<HDAT_slcaEntry_t> &o_hdatslca)
{
    HDAT_ENTER();
    uint16_t l_slcaBPIndex = 0;
    char     l_nodeLocCode[64] = {0};
    uint16_t l_slcaEntryIndex = 0;

    TARGETING::Target *l_pSystemTarget = UTIL::assertGetToplevelTarget();

    l_slcaEntryIndex = hdatAddSLCAEntry(i_Target, HDAT_SLCA_FRU_TYPE_BP,
                                        i_slcaParentIndex,
                                        o_hdatslca);

    if((o_hdatslca[i_slcaParentIndex].first_child_index == 0xFFFF) &&
                                                         (l_slcaEntryIndex))
    {
        o_hdatslca[i_slcaParentIndex].first_child_index = l_slcaEntryIndex;

        o_hdatslca[i_slcaParentIndex].first_child_rid =
                                       o_hdatslca[l_slcaEntryIndex].fru_rid;

        o_hdatslca[i_slcaParentIndex].first_child_pldm_entity_id =
                                    o_hdatslca[l_slcaEntryIndex].pldm_entity_id;

        o_hdatslca[i_slcaParentIndex].number_of_children++;
        o_hdatslca[i_slcaParentIndex].number_of_children_2B++;

    }

    l_slcaBPIndex = l_slcaEntryIndex;
    hdatGetLocationCode(i_Target, HDAT_SLCA_FRU_TYPE_BP,
                                                          l_nodeLocCode);

    TARGETING::PredicateHwas l_predHwas;
    l_predHwas.present(true);

    TARGETING::PredicateCTM l_procFilter(TARGETING::CLASS_CHIP,
                                             TARGETING::TYPE_PROC);

    TARGETING::PredicateCTM l_memFilter(TARGETING::CLASS_CHIP,
                                             TARGETING::TYPE_MEMBUF);

    TARGETING::PredicateCTM l_pciFilter(TARGETING::CLASS_UNIT,
                                             TARGETING::TYPE_PCI);

    TARGETING::PredicateCTM l_psFilter(TARGETING::CLASS_UNIT,
                                             TARGETING::TYPE_PS);

    TARGETING::PredicateCTM l_vrmFilter(TARGETING::CLASS_UNIT,
                                             TARGETING::TYPE_VRM);

    TARGETING::PredicateCTM l_fanFilter(TARGETING::CLASS_UNIT,
                                             TARGETING::TYPE_FAN);

    TARGETING::PredicateCTM l_uartFilter(TARGETING::CLASS_UNIT,
                                             TARGETING::TYPE_UART);

    TARGETING::PredicateCTM l_usbFilter(TARGETING::CLASS_UNIT,
                                             TARGETING::TYPE_USB);

    TARGETING::PredicateCTM l_ethFilter(TARGETING::CLASS_UNIT,
                                             TARGETING::TYPE_ETH);

    TARGETING::PredicateCTM l_dimmFilter(TARGETING::CLASS_LOGICAL_CARD,
                                             TARGETING::TYPE_DIMM);

    TARGETING::PredicateCTM l_tpmFilter(TARGETING::CLASS_CHIP,
                                        TARGETING::TYPE_TPM);

    TARGETING::PredicatePostfixExpr l_presentChildren;
    TARGETING::PredicatePostfixExpr l_fullProcDimm;
    TARGETING::TargetHandleList l_childList;

    //TODO : RTC Story 311075
    //Need to refine the SLCA table filter
    if (!l_pSystemTarget->getAttr<
              TARGETING::ATTR_PLDM_CONNECTOR_PDRS_ENABLED>())
    {
        l_presentChildren.push(&l_procFilter).push(&l_memFilter).Or().
                     push(&l_pciFilter).Or().push(&l_psFilter).Or().
                     push(&l_fanFilter).Or().push(&l_uartFilter).Or().
                     push(&l_usbFilter).Or().push(&l_ethFilter).Or().
                     push(&l_vrmFilter).Or().push(&l_dimmFilter).Or().
                     push(&l_tpmFilter).Or().push(&l_predHwas).And();

         //Get all children of this node
         TARGETING::targetService().
                  getAssociated(l_childList, i_Target,
                          TARGETING::TargetService::CHILD,
                          TARGETING::TargetService::ALL, &l_presentChildren);
    }
    else
    {
        TARGETING::TargetHandleList l_fullProcDimmChildList;

        // Get the present list except for proc and dimm
        l_presentChildren.push(&l_memFilter).
                     push(&l_pciFilter).Or().push(&l_psFilter).Or().
                     push(&l_fanFilter).Or().push(&l_uartFilter).Or().
                     push(&l_usbFilter).Or().push(&l_ethFilter).Or().
                     push(&l_vrmFilter).Or().push(&l_tpmFilter).Or().
                     push(&l_predHwas).And();
        TARGETING::targetService().
                  getAssociated(l_childList, i_Target,
                          TARGETING::TargetService::CHILD,
                          TARGETING::TargetService::ALL, &l_presentChildren);

        // Get the full list of proc and dimm
        l_fullProcDimm.push(&l_procFilter).push(&l_dimmFilter).Or();
        TARGETING::targetService().
                  getAssociated(l_fullProcDimmChildList, i_Target,
                          TARGETING::TargetService::CHILD,
                          TARGETING::TargetService::ALL, &l_fullProcDimm);

        // Combine both the lists
        std::copy(l_fullProcDimmChildList.begin(),l_fullProcDimmChildList.end(),
                          std::back_inserter(l_childList));
    }

    for (TargetHandleList::const_iterator pTarget_it = l_childList.begin();
                pTarget_it != l_childList.end();
                ++pTarget_it)
    {
        TargetHandle_t l_childTarget  = *pTarget_it;
        TARGETING::ATTR_TYPE_type l_type;
        HDAT_FRUType_t l_hdatFRUType = HDAT_SLCA_FRU_TYPE_UNKNOWN;
        l_slcaEntryIndex = 0;

        if(l_childTarget->tryGetAttr<ATTR_TYPE>(l_type))
        {
            switch(l_type)
            {
                case TYPE_PROC:
                    l_hdatFRUType = HDAT_SLCA_FRU_TYPE_PROC;
                break;

                case TYPE_MEMBUF:
                {
                    ATTR_FRU_ID_type l_childFRUId;
                    ATTR_FRU_ID_type l_encFRUId;
                    TARGETING::TargetHandleList targetList;
                    targetList.clear();
                    getParentAffinityTargets(targetList,l_childTarget,
                               TARGETING::CLASS_ENC,TARGETING::TYPE_NODE);
                    if(!targetList.empty())
                    {
                        TARGETING::Target* l_pNodeTarget = targetList[0];
                        l_encFRUId = l_pNodeTarget->getAttr<ATTR_FRU_ID>();
                        l_childFRUId = l_childTarget->getAttr<ATTR_FRU_ID>();
                        if(l_encFRUId != l_childFRUId)
                        {
                            l_hdatFRUType = HDAT_SLCA_FRU_TYPE_RI;
                        }
                    }
                    else
                    {
                        //target list is empty for type membuf then FRU type
                        //would be set as HDAT_SLCA_FRU_TYPE_UNKNOWN
                        HDAT_ERR("Empty list returned while querying"
                                                  "for parents of membuf");
                    }
                }
                break;

                case TYPE_DIMM:
                    l_hdatFRUType = HDAT_SLCA_FRU_TYPE_DIMM;
                break;

                case TYPE_TPM:
                    l_hdatFRUType = HDAT_SLCA_FRU_TYPE_TPM;
                break;

                case TYPE_PCI:
                    l_hdatFRUType = HDAT_SLCA_FRU_TYPE_IOP;
                break;

                case TYPE_PS:
                    l_hdatFRUType = HDAT_SLCA_FRU_TYPE_PS;
                break;

                case TYPE_VRM:
                    l_hdatFRUType = HDAT_SLCA_FRU_TYPE_RG;
                break;

                case TYPE_FAN:
                    l_hdatFRUType = HDAT_SLCA_FRU_TYPE_AM;
                break;

                case TYPE_USB:
                    l_hdatFRUType = HDAT_SLCA_FRU_TYPE_CU;
                break;

                case TYPE_ETH:
                    l_hdatFRUType = HDAT_SLCA_FRU_TYPE_CE;
                break;

                case TYPE_UART:
                    l_hdatFRUType = HDAT_SLCA_FRU_TYPE_CS;
                break;

#ifdef BACKPLANE_EXTENSION_ENABLED
                case TYPE_BX:
                    l_hdatFRUType = HDAT_SLCA_FRU_TYPE_BX;
                    hdatAddNodeToSLCATable(l_childTarget, l_slcaBPIndex,
                                 o_hdatslca);
                break;
#endif

                default:
                    l_hdatFRUType = HDAT_SLCA_FRU_TYPE_UNKNOWN;
                    break;
            }

            if(l_hdatFRUType != HDAT_SLCA_FRU_TYPE_UNKNOWN)
            {
                HDAT_DBG("calling hdatAddSLCAEntry for fru type 0x%x",l_hdatFRUType);
                l_slcaEntryIndex = hdatAddSLCAEntry(l_childTarget,
                                                     l_hdatFRUType,
                                                     l_slcaBPIndex,
                                                     o_hdatslca);

                o_hdatslca[l_slcaBPIndex].number_of_children++;

                o_hdatslca[l_slcaBPIndex].number_of_children_2B++;

                if((o_hdatslca[l_slcaBPIndex].first_child_index == 0xFFFF) &&
                                                         (l_slcaEntryIndex))
                {
                    o_hdatslca[l_slcaBPIndex].first_child_index =
                                                           l_slcaEntryIndex;

                    o_hdatslca[l_slcaBPIndex].first_child_rid =
                                       o_hdatslca[l_slcaEntryIndex].fru_rid;

                    o_hdatslca[l_slcaBPIndex].first_child_pldm_entity_id =
                                    o_hdatslca[l_slcaEntryIndex].pldm_entity_id;
                }
            }
        }
        else
        {
            HDAT_ERR("Error reading ATTR_TYPE attribute");
        }
    }
    HDAT_EXIT();
}

/**
 * @brief This routine adds Service Processors  to SLCA table
 *
 * @pre None
 *
 * @post None
 *
 * @param i_Target   - input parameter - Target of SP FRU
 *        i_slcaParentIndex - input parameter - Index of parent FRU
 *        o_hdatslca - output parameter - Vector containing slca entries
 *                                        for Service Processors
 *
 * @return Number of Service Processor FRUs added
 *
 * @retval HDAT_OTHER_COMP_ERROR
 */
static void hdatAddSPToSLCATable(TARGETING::Target *i_Target,
                              uint16_t i_slcaParentIndex,
                      vector<HDAT_slcaEntry_t> &o_hdatslca)
{
    HDAT_ENTER();
    TARGETING::PredicateCTM l_spPredicate(TARGETING::CLASS_SP,
                                             TARGETING::TYPE_BMC,
                                             TARGETING::MODEL_AST2500);
    TARGETING::PredicateHwas l_predHwas;
    l_predHwas.present(true);

    TARGETING::PredicatePostfixExpr l_presentSP;
    l_presentSP.push(&l_spPredicate).push(&l_predHwas).And();

    //Get all Service processors in the system
    TARGETING::TargetRangeFilter* l_spFilter= new TARGETING::TargetRangeFilter(
                                        TARGETING::targetService().begin(),
                                        TARGETING::targetService().end(),
                                        &l_presentSP);

    // if the predicate is empty, then use old predicate
    if (!(*l_spFilter))
    {
       delete l_spFilter;

       TARGETING::PredicateCTM l_spPredicate(TARGETING::CLASS_CHIP,
                                             TARGETING::TYPE_SP,
                                             TARGETING::MODEL_BMC);

       TARGETING::PredicatePostfixExpr l_presentSP;
       l_presentSP.push(&l_spPredicate).push(&l_predHwas).And();

       l_spFilter = new TARGETING::TargetRangeFilter(
                                     TARGETING::targetService().begin(),
                                     TARGETING::targetService().end(),
                                     &l_presentSP);
    }

    for (;(*l_spFilter);++(*l_spFilter))
    {
        TARGETING::Target *l_spTarget = (*(*l_spFilter));

        hdatAddSLCAEntry(l_spTarget, HDAT_SLCA_FRU_TYPE_SP, i_slcaParentIndex,
                                                  o_hdatslca);

        o_hdatslca[i_slcaParentIndex].number_of_children++;
        o_hdatslca[i_slcaParentIndex].number_of_children_2B++;

        HDAT_DBG("Added Service Processor to SLCA");
    }

    delete l_spFilter;
    HDAT_EXIT();
}

/**
 * @brief This routine adds op-panel SLCA entry
 *
 * @pre None
 *
 * @post None
 *
 * @param i_Target   - input parameter - Target of panel FRU
 *        i_slcaParentIndex - input parameter - Index of parent FRU
 *        o_hdatslca - output parameter - Vector containing slca entries
 *
 * @return A null error log handle if successful, else the return code pointed
 *         to by errlHndl_t contains one of:
 *
 * @retval HDAT_OTHER_COMP_ERROR
 */
static void hdatAddOpPanelToSLCATable(TARGETING::Target *i_Target,
                                   uint16_t i_slcaParentIndex,
                                   vector<HDAT_slcaEntry_t> &o_hdatslca)
{
    HDAT_ENTER();
    TARGETING::PredicateCTM l_opPredicate(TARGETING::CLASS_UNIT,
                                             TARGETING::TYPE_PANEL);

    TARGETING::PredicateHwas l_predHwas;
    l_predHwas.present(true);

    TARGETING::PredicatePostfixExpr l_presentPanel;
    l_presentPanel.push(&l_opPredicate).push(&l_predHwas).And();

    //Get all op-panels in the system
    TARGETING::TargetRangeFilter l_opFilter(
                                        TARGETING::targetService().begin(),
                                        TARGETING::targetService().end(),
                                        &l_presentPanel);

    for (;l_opFilter;++l_opFilter)
    {
        TARGETING::Target *l_opTarget = (*l_opFilter);

        hdatAddSLCAEntry(l_opTarget, HDAT_SLCA_FRU_TYPE_OP, i_slcaParentIndex,
                                                  o_hdatslca);

        o_hdatslca[i_slcaParentIndex].number_of_children++;
        o_hdatslca[i_slcaParentIndex].number_of_children_2B++;

        HDAT_DBG("Added OpPanel to SLCA");
    }
    HDAT_EXIT();
}

/**
 * @brief This routine constructs SLCA table for all FRUs
 *
 * @pre None
 *
 * @post None
 *
 * @param o_hdatslcaentries - output parameter - Vector containing slca entries
 *
 * @return A null error log handle if successful, else the return code pointed
 *         to by errlHndl_t contains one of:
 *
 * @retval HDAT_OTHER_COMP_ERROR
 */
errlHndl_t hdatConstructslcaTable(std::vector<HDAT_slcaEntry_t>
                                                          &o_hdatslcaentries)
{
    HDAT_ENTER();
    TARGETING::Target *l_pSystemTarget = NULL;
    (void) TARGETING::targetService().getTopLevelTarget(l_pSystemTarget);

    if(l_pSystemTarget == NULL)
    {
        HDAT_ERR("Error in getting Top Level Target");
        assert(l_pSystemTarget != NULL);
    }
    uint16_t l_slcaVVIndex = hdatAddSLCAEntry(l_pSystemTarget,
                                              HDAT_SLCA_FRU_TYPE_VV,0,
                                              o_hdatslcaentries);

    uint16_t l_slcaSVIndex = hdatAddSLCAEntry(l_pSystemTarget,
                                            HDAT_SLCA_FRU_TYPE_SV,l_slcaVVIndex,
                                             o_hdatslcaentries);

    if((o_hdatslcaentries[0].first_child_index == 0xFFFF) &&
                                                         (l_slcaSVIndex))
    {
        o_hdatslcaentries[0].first_child_index = l_slcaSVIndex;

        o_hdatslcaentries[0].first_child_rid =
                                       o_hdatslcaentries[l_slcaSVIndex].fru_rid;

        o_hdatslcaentries[0].first_child_pldm_entity_id =
                             o_hdatslcaentries[l_slcaSVIndex].pldm_entity_id;

        o_hdatslcaentries[0].number_of_children++;
        o_hdatslcaentries[0].number_of_children_2B++;

    }

    TARGETING::PredicateCTM l_nodePredicate(TARGETING::CLASS_ENC,
                                             TARGETING::TYPE_NODE);
    TARGETING::PredicateHwas l_predHwas;
    l_predHwas.present(true);

    TARGETING::PredicatePostfixExpr l_presentNode;
    l_presentNode.push(&l_nodePredicate).push(&l_predHwas).And();

    //Get all Nodes
    TARGETING::TargetRangeFilter l_nodeFilter(
                                        TARGETING::targetService().begin(),
                                        TARGETING::targetService().end(),
                                        &l_presentNode);

    TARGETING::Target *l_nodeTarget = (*l_nodeFilter);
    if(l_nodeTarget != NULL)
    {
        //Add EV here and make SP, BP and OP as children of EV
        uint16_t l_slcaEVIndex = hdatAddSLCAEntry(l_pSystemTarget,
                                           HDAT_SLCA_FRU_TYPE_EV,l_slcaVVIndex,
                                           o_hdatslcaentries);

        o_hdatslcaentries[l_slcaEVIndex].first_child_index = 0xFFFF;
        o_hdatslcaentries[l_slcaEVIndex].first_child_rid   = 0xFFFF;
        o_hdatslcaentries[l_slcaEVIndex].first_child_pldm_entity_id.entityType =
                                                                         0xFFFF;
        o_hdatslcaentries[l_slcaEVIndex].first_child_pldm_entity_id.entityInstanceNumber = 0xFFFF;
        o_hdatslcaentries[l_slcaEVIndex].first_child_pldm_entity_id.containerId = 0xFFFF;

        o_hdatslcaentries[l_slcaVVIndex].number_of_children++;
        o_hdatslcaentries[l_slcaVVIndex].number_of_children_2B++;

        hdatAddNodeToSLCATable(l_nodeTarget, l_slcaEVIndex,
                                                    o_hdatslcaentries);

        //Add Service Processor FRUs to SLCA table
        hdatAddSPToSLCATable(l_nodeTarget,l_slcaEVIndex,
                                                          o_hdatslcaentries);

        //Add Op-Panel  FRUs to SLCA table
        hdatAddOpPanelToSLCATable(l_nodeTarget,l_slcaEVIndex,
                                                             o_hdatslcaentries);

    }
    else
    {
        HDAT_ERR("Error retrieving nodes. There must be alteast one node");
        assert(l_nodeTarget != NULL);
    }
    HDAT_EXIT();
    return NULL;

}

/**
 * @brief This routine sets SLCA structure header parameters
 *
 * @pre None
 *
 * @post None
 *
 * @param o_slcaStruct - output parameter - Structure containing SLCA header
 *        i_nrOfSLCAEntries - input parameter - Number of SLCA entries
 *
 * @return A null error log handle if successful, else the return code pointed
 *         to by errlHndl_t contains one of:
 *
 * @retval HDAT_OTHER_COMP_ERROR
 */
static errlHndl_t hdatSetSLCAStructHdrs(hdatSLCAStruct_t &o_slcaStruct,
                                       uint32_t i_nrOfSLCAEntries)
{
    HDAT_ENTER();
    errlHndl_t l_errlHndl = NULL;

    uint32_t l_hdatslcastructsize = i_nrOfSLCAEntries *
                                                sizeof(HDAT_slcaEntry_t);

    o_slcaStruct.hdatHdr.hdatStructId       = HDAT_HDIF_STRUCT_ID;
    o_slcaStruct.hdatHdr.hdatInstance       = 0;
    o_slcaStruct.hdatHdr.hdatVersion        = HDAT_SLCA_STRUCT_VERSION;
    o_slcaStruct.hdatHdr.hdatSize           = sizeof(hdatSLCAStruct_t) +
                                                        l_hdatslcastructsize;
    o_slcaStruct.hdatHdr.hdatHdrSize        = sizeof(hdatHDIF_t);
    o_slcaStruct.hdatHdr.hdatDataPtrOffset  = sizeof(hdatHDIF_t);
    o_slcaStruct.hdatHdr.hdatDataPtrCnt     = 1;
    o_slcaStruct.hdatHdr.hdatChildStrCnt    = 0;
    o_slcaStruct.hdatHdr.hdatChildStrOffset = 0;

    memcpy(o_slcaStruct.hdatHdr.hdatStructName, HDAT_SLCA_STRUCT_NAME,
                                sizeof(o_slcaStruct.hdatHdr.hdatStructName));

    o_slcaStruct.hdatSLCAIntData[0].hdatOffset =
                                sizeof(hdatHDIF_t)+ sizeof(hdatHDIFDataHdr_t)
                                + sizeof(o_slcaStruct.hdatPadding);

    o_slcaStruct.hdatSLCAIntData[0].hdatSize =
                             sizeof(hdatSLCAArrayHdr_t) + l_hdatslcastructsize;

    memset(o_slcaStruct.hdatPadding, 0 , sizeof(o_slcaStruct.hdatPadding));

    o_slcaStruct.hdatSLCAArrayHdr.hdatOffsetToSLCAArray =
                                            sizeof(hdatSLCAArrayHdr_t);

    o_slcaStruct.hdatSLCAArrayHdr.hdatActualNrEntries = i_nrOfSLCAEntries;

    o_slcaStruct.hdatSLCAArrayHdr.hdatSizeOfEntryAllotted =
                                            sizeof(HDAT_slcaEntry_t);

    o_slcaStruct.hdatSLCAArrayHdr.hdatActualSizeOfEntry =
                                            sizeof(HDAT_slcaEntry_t);

    HDAT_EXIT();
    return l_errlHndl;
}

/**
 * @brief This routine builds the SLCA structure as per HDAT specifications
 *
 * @pre None
 *
 * @post None
 *
 * @param i_msAddr - Mainstore address where SLCA structure is loaded
 *        o_hdatslcaCount - output parameter - Number of SLCA structures
 *        o_hdatslcaSize - output paramster - Size of SLCA created
 *
 * @return errlHndl_t - Error Handle
 *
 * @retval HDAT_OTHER_COMP_ERROR
 */
errlHndl_t hdatBuildSLCA(const HDAT::hdatMsAddr_t &i_msAddr,
                               uint32_t &o_hdatslcaCount,
                               uint32_t &o_hdatslcaSize)

{
    HDAT_ENTER();
    std::vector<HDAT_slcaEntry_t> l_hdatslcaentries;
    hdatSLCAStruct_t l_hdatslcastruct;
    errlHndl_t l_errl = NULL;

    hdatPopulateMTMAndSerialNumber();
    hdatConstructslcaTable(l_hdatslcaentries);

    uint32_t l_hdatslcastructsize = l_hdatslcaentries.size() *
                                                    sizeof(HDAT_slcaEntry_t);

    uint64_t l_base_addr = ((uint64_t) i_msAddr.hi << 32) | i_msAddr.lo;

    //Set SLCA Headers
    hdatSetSLCAStructHdrs(l_hdatslcastruct, l_hdatslcaentries.size());

    // Allocate space for SLCA Header
    void *l_virt_addr_hdr = mm_block_map(reinterpret_cast<void*>
                                               (ALIGN_PAGE_DOWN(l_base_addr)),
                                         (ALIGN_PAGE(sizeof(hdatSLCAStruct_t) +
                                            l_hdatslcastructsize) + PAGESIZE));
    l_virt_addr_hdr = reinterpret_cast<void *>(
                    reinterpret_cast<uint64_t>(l_virt_addr_hdr) +
                    (l_base_addr - ALIGN_PAGE_DOWN(l_base_addr)));

    HDAT_DBG("SLCA hdr addr 0x%016llX SLCA hdr size %d",
                   (uint64_t)l_virt_addr_hdr, sizeof(hdatSLCAStruct_t));

    memcpy(reinterpret_cast<hdatSLCAStruct_t *>(l_virt_addr_hdr),
                                 &l_hdatslcastruct, sizeof(hdatSLCAStruct_t));

    HDAT_slcaEntry_t *l_hdatSLCA = reinterpret_cast<HDAT_slcaEntry_t *>
                       ((uint64_t)l_virt_addr_hdr + sizeof(hdatSLCAStruct_t));

    HDAT_DBG("HDAT SLCA addr 0x%016llX SLCA struct size %d",
                  (uint64_t) l_base_addr, l_hdatslcastructsize);

    HDAT_DBG("HDAT SLCA addr 0x%016llX virtual addr 0x%016llX",
                  (uint64_t) l_hdatSLCA, (uint64_t)l_virt_addr_hdr);

    std::copy(l_hdatslcaentries.begin(), l_hdatslcaentries.end(), l_hdatSLCA);

    HDAT_DBG("HDAT:: Loaded SLCA structures: Size: 0x%X",
                                               sizeof(hdatSLCAStruct_t) +
                                               l_hdatslcastructsize);

    o_hdatslcaSize = sizeof(hdatSLCAStruct_t) + l_hdatslcastructsize;
    o_hdatslcaCount = 1;

    int rc = mm_block_unmap(l_virt_addr_hdr);

    if( rc != 0)
    {
        errlHndl_t l_errl = NULL;
        /*@
         * @errortype
         * @moduleid         HDAT::MOD_SLCA_DESTRUCTOR
         * @reasoncode       HDAT::RC_DEV_MAP_FAIL
         * @devdesc          Unmap a mapped region failed
         * @custdesc         Firmware encountered an internal error.
        */
        hdatBldErrLog(l_errl,
                MOD_PCIA_DESTRUCTOR,
                RC_DEV_MAP_FAIL,
                (uint32_t)((uint64_t)l_virt_addr_hdr >> 32),
                (uint32_t)((uint64_t)l_virt_addr_hdr),0,0,
                ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                HDAT_VERSION1, false);
    }

    HDAT_EXIT();
    return l_errl;
}

/**
 * @brief This routine copies the SLCA from a source address to a destination
 *        address
 *
 * @pre None
 *
 * @post None
 *
 * @param i_msAddrSource - input parameter - Source address of SLCA
 *        i_msAddrDest   - input parameter - Destination address of SLCA
 *        i_slcaSize     - input parameter - Size of SLCA to be copied
 *
 * @return None
 *
 * @retval HDAT_OTHER_COMP_ERROR
 */
void hdatMoveSLCA(const HDAT::hdatMsAddr_t &i_msAddrSource,
                   const HDAT::hdatMsAddr_t &i_msAddrDest,
                   uint32_t i_slcaSize)
{
    HDAT_ENTER();

    uint64_t l_base_addr_source = ((uint64_t) i_msAddrSource.hi << 32) |
                                                             i_msAddrSource.lo;
    uint64_t l_base_addr_dest   = ((uint64_t) i_msAddrDest.hi << 32) |
                                                             i_msAddrDest.lo;

    HDAT_DBG("Move SLCA from 0x%016llX to 0x%016llX with size  %d",
                  (uint64_t) l_base_addr_source, (uint64_t)l_base_addr_dest,
                                                 i_slcaSize);
    // Allocate space for SLCA
    void *l_virt_addr_source = mm_block_map(reinterpret_cast<void*>
                                          (ALIGN_PAGE_DOWN(l_base_addr_source)),
                                          (ALIGN_PAGE(i_slcaSize)+PAGESIZE));

    l_virt_addr_source = reinterpret_cast<void *>(
                    reinterpret_cast<uint64_t>(l_virt_addr_source) +
                    (l_base_addr_source - ALIGN_PAGE_DOWN(l_base_addr_source)));

    // Allocate space for SLCA
    void *l_virt_addr_dest = mm_block_map(reinterpret_cast<void*>
                                          (ALIGN_PAGE_DOWN(l_base_addr_dest)),
                                          (ALIGN_PAGE(i_slcaSize) + PAGESIZE));

    l_virt_addr_dest = reinterpret_cast<void *>(
                    reinterpret_cast<uint64_t>(l_virt_addr_dest) +
                    (l_base_addr_dest - ALIGN_PAGE_DOWN(l_base_addr_dest)));

    memcpy(l_virt_addr_dest , reinterpret_cast<void*>(l_virt_addr_source),
                                                                   i_slcaSize);

    mm_block_unmap(l_virt_addr_source);
    mm_block_unmap(l_virt_addr_dest);
    HDAT_EXIT();
}


}
