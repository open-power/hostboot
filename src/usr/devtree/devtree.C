/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/devtree/devtree.C $                                   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2020                        */
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
 *  @file devtree.C
 *
 *  @brief Implementation of DEVTREE sync
 */

#include <trace/interface.H>
#include <errl/errlentry.H>
#include <pnor/pnorif.H>

// Devtree
#include <devtree/devtree.H>
#include <devtree/devtreereasoncodes.H>
#include <libfdt.h>

// Targ
#include <targeting/common/targetservice.H>
#include <targeting/attrrp.H>
#include <targeting/targplatutil.H>

// Attribute id and attribute info map
#include <targRwAttrIdToName.H>

using namespace TARGETING;

// Trace definition
trace_desc_t* g_trac_devtree = nullptr;
TRAC_INIT(&g_trac_devtree, DEVTREE_COMP_NAME, 2*KILOBYTE, TRACE::BUFFER_SLOW);

namespace DEVTREE
{


// The start offset in the libfdt code is incremented before it
// is used, so -1 will actually start at offset 0 = sys level
static constexpr int DTREE_START_OFFSET = -1;

// Name of the property in devtree that matches hostboot PHYS_PATH attr
static constexpr const char* const PHYS_BIN_PROPERTY = "ATTR_PHYS_BIN_PATH";


/**
 * @brief Function to process libfdt errors
 *
 * @param[in]   i_rc        libfdt return code
 * @param[in]   i_huid      target huid
 *
 */
void handleDtreeError(const int i_rc,
                      const uint32_t i_huid,
                      const char* i_name)
{
    errlHndl_t l_err = nullptr;
    bool l_genError = true;

    switch (i_rc)
    {
        case -FDT_ERR_NOSPACE:
            // If len is not equal to the property's current length
            TRACFCOMP( g_trac_devtree, ERR_MRK
                       "FDT_ERR_NOSPACE HUID 0x%08X ATTR %s",
                       i_huid, i_name);
            break;
        case -FDT_ERR_NOTFOUND:
            // No node or property matching the criterion exists in the tree
            // Not all targets have a node in the devtree
            l_genError = false;
            break;
        case -FDT_ERR_BADOFFSET:
            // Nodeoffset does not refer to a BEGIN_NODE tag
            TRACFCOMP( g_trac_devtree, ERR_MRK
                       "FDT_ERR_BADOFFSET HUID 0x%08X ATTR %s",
                       i_huid, i_name);
            break;
        case -FDT_ERR_BADMAGIC:
            TRACFCOMP( g_trac_devtree, ERR_MRK
                       "FDT_ERR_BADMAGIC HUID 0x%08X ATTR %s",
                       i_huid, i_name);
            break;
        case -FDT_ERR_BADVERSION:
            TRACFCOMP( g_trac_devtree, ERR_MRK
                       "FDT_ERR_BADVERSION HUID 0x%08X ATTR %s",
                       i_huid, i_name);
            break;
        case -FDT_ERR_BADSTATE:
            TRACFCOMP( g_trac_devtree, ERR_MRK
                       "FDT_ERR_BADSTATE HUID 0x%08X ATTR %s",
                       i_huid, i_name);
            break;
        case -FDT_ERR_BADSTRUCTURE:
            TRACFCOMP( g_trac_devtree, ERR_MRK
                       "FDT_ERR_BADSTRUCTURE HUID 0x%08X ATTR %s",
                       i_huid, i_name);
            break;
        case -FDT_ERR_TRUNCATED:
            TRACFCOMP( g_trac_devtree, ERR_MRK
                       "FDT_ERR_TRUNCATED HUID 0x%08X ATTR %s",
                       i_huid, i_name);
            break;
        default:
            TRACFCOMP( g_trac_devtree, ERR_MRK
                       "UNKNOWN libfdt ERROR %d for HUID 0x%08X ATTR %s",
                       i_rc, i_huid, i_name);
            break;
    }

    if (l_genError)
    {
        /*@
            * @errortype
            * @moduleid     HANDLE_DEVTREE_ERRORS
            * @reasoncode   LIBFDT_ERROR_RC
            * @userdata1    Return Code
            * @userdata2    HUID
            * @devdesc      Devtree libfdt operation returned error
            * @custdesc     A problem occurred during the IPL
            *               of the system.
            */
        l_err = new ERRORLOG::ErrlEntry(
                ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                HANDLE_DEVTREE_ERRORS,
                LIBFDT_ERROR_RC,
                i_rc,
                i_huid,
                ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);

        ERRORLOG::errlCommit(l_err, DEVTREE_COMP_ID);
    }
}


/**
 * @brief Function to get attribute name from attribute ID map
 *        Map is found in obj/genfiles/targRwAttrIdToName.H
 *        Only includes writeable attributes
 *
 * @param[in]   i_attrId    Attribute ID
 *
 * @return  const char*     Name
 */
const char* getAttrInfo(const ATTRIBUTE_ID i_attrId)
{
    const char* ret = nullptr;

    if (g_attrIdToNameMap.count(i_attrId) > 0)
    {
        ret = g_attrIdToNameMap.at(i_attrId);
    }

    return ret;
}


#ifdef CONFIG_DEVTREE_DEBUG
//-----------------------------------------------------------------------------
/**
 * @brief Debug function to read devtree data and compare to targeting data
 *        Prints attributes that do not match between Targeting and Devtree
 *
 * @param[in]   i_fdt       Flattened device tree pointer
 * @param[in]   i_offset    Devtree node offset
 * @param[in]   i_name      Attribute name
 * @param[in]   i_huid      Target HUID
 * @param[in]   i_size      Size of attribute value
 * @param[in]   i_tData     Target attribute data value
 *
 * @return  const char*     Name
 */
void debugReadCmpData(const void* i_fdt,
                      const int i_offset,
                      const ATTRIBUTE_ID i_id,
                      const char* i_name,
                      const uint32_t i_huid,
                      const uint32_t i_size,
                      const uint8_t* i_tData)
{
    errlHndl_t l_err = nullptr;

    do
    {
        // Read the devtree property data
        const void * l_pData = nullptr;
        int l_len = 0;
        int* l_pLen = &l_len;

        // returns pointer to data inside fdt blob
        l_pData = fdt_getprop(i_fdt, i_offset, i_name, l_pLen);

        // length returned is error code if < 0
        if (l_pData == nullptr) // getprop failed
        {
            if (l_pLen != nullptr) // length is valid
            {
                if (l_len < 0) // error code
                {
                    handleDtreeError(l_len, i_huid, i_name);
                    break;
                }
            }
            TRACFCOMP(g_trac_devtree, ERR_MRK "debugReadCmpData "
                "No data or error code from fdt_getprop()");
            break;
        }

        // above check will catch the error codes from fdt_getprop call,
        // this check will catch mismatched size of a valid
        // targeting/devtree attribute
        if (static_cast<int>(i_size) != l_len)
        {
            TRACFCOMP( g_trac_devtree, ERR_MRK "debugReadCmpData "
                       "targ/devtree size mismatch for %s: tSize %d dSize %d",
                       i_name, i_size, l_len);
            /*@
                * @errortype
                * @moduleid     DEBUG_READ_CMP_DATA
                * @reasoncode   TARGET_DTREE_SIZE_MISMATCH
                * @userdata1[00:31]    HUID
                * @userdata1[32:63]    Attribute ID
                * @userdata2[00:31]    Target attribute size
                * @userdata2[32:63]    Devtree attribute size
                * @devdesc      Error reading devtree data
                * @custdesc     A problem occurred during the IPL
                *               of the system.
                */
            l_err = new ERRORLOG::ErrlEntry(
                    ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                    DEBUG_READ_CMP_DATA,
                    TARGET_DTREE_SIZE_MISMATCH,
                    TWO_UINT32_TO_UINT64(i_huid,i_id),
                    TWO_UINT32_TO_UINT64(i_size,l_len),
                    ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);

            ERRORLOG::errlCommit(l_err, DEVTREE_COMP_ID);
            break;
        }

        // Have valid data, do the compare
        bool l_mismatch = false;
        uint32_t l_tPrint = 0;
        uint32_t l_dPrint = 0;
        const uint8_t* l_dData = static_cast<const uint8_t*>(l_pData);

        for (uint32_t l_byte = 0; l_byte < i_size; l_byte++)
        {
            if (i_tData[l_byte] != l_dData[l_byte])
            {
                l_mismatch = true;
            }
            l_tPrint |= i_tData[l_byte] << (i_size - (l_byte + 1));
            l_dPrint |= l_dData[l_byte] << (i_size - (l_byte + 1));
        }

        if (l_mismatch)
        {
            TRACFCOMP(g_trac_devtree,
                    "0x%08X %s tData 0x%08X dData 0x%08X",
                    i_huid, i_name, l_tPrint, l_dPrint);
        }

    } while(0);
}
// End debug only

//-----------------------------------------------------------------------------
#endif


/**
 * @brief Function to sync targeting attributes to devtree
 */
void devtreeSyncAttrs()
{
    TRACFCOMP(g_trac_devtree, ENTER_MRK"DEVTREE::devtreeSyncAttrs");

    errlHndl_t l_err = nullptr;

    do
    {
        // Get a pointer to the flattened device tree in the pnor
        PNOR::SectionInfo_t l_devtreeInfo;

        l_err = PNOR::getSectionInfo(PNOR::DEVTREE, l_devtreeInfo);
        if(l_err)
        {
            TRACFCOMP( g_trac_devtree, ERR_MRK
                       "devtreeSyncAttrs(): Error loading DEVTREE PNOR");
            ERRORLOG::errlCommit(l_err, DEVTREE_COMP_ID);
            break;
        }

        void* l_fdt = reinterpret_cast<void *>(l_devtreeInfo.vaddr);


        // Get the sys target
        Target* l_sys = UTIL::assertGetToplevelTarget();

        // Get list of all other targets
        TargetHandleList l_targetList;
        targetService().getAssociated( l_targetList, l_sys,
                                       TargetService::CHILD,
                                       TargetService::ALL, nullptr);
        // Add sys target to the list
        l_targetList.push_back(l_sys);


        // Loop on every attribute of every target
        for (const auto l_target: l_targetList)
        {
            const uint32_t l_targetHuid = get_huid(l_target);

            // Target PHYS_PATH used as key to find associated node in devtree
            EntityPath l_physPath =
                            l_target->getAttr<TARGETING::ATTR_PHYS_PATH>();
            EntityPath* l_pPhysPath = &l_physPath;

            // Get the devtree node offset, if < 0 indicates an error and the
            // returned value is the error code, handle and go to next target
            int l_dtreeNodeOffset =
                    fdt_node_offset_by_prop_value(
                                        l_fdt,
                                        DTREE_START_OFFSET,
                                        PHYS_BIN_PROPERTY,
                                        static_cast<const void*>(l_pPhysPath),
                                        sizeof(*l_pPhysPath));
            if (l_dtreeNodeOffset < 0)
            {
                handleDtreeError(l_dtreeNodeOffset,
                                 l_targetHuid,
                                 PHYS_BIN_PROPERTY);
                continue;
            }

            // Get a pointer to attribute id array
            const ATTRIBUTE_ID* const l_pAttrId =
                                    TARG_TO_PLAT_PTR(l_target->iv_pAttrNames);
            const ATTRIBUTE_ID* const l_pAttrEnd =
                                    l_pAttrId + l_target->iv_attrs;

            // Iterate over each attribute ID for the target
            for (const ATTRIBUTE_ID* l_attributeId = l_pAttrId;
                l_attributeId != l_pAttrEnd;
                ++l_attributeId)
            {
                // Get attribute name from generated map file
                // The map only includes writeable attributes
                // so if the attribute name was not found continue on
                const char* l_attrName = getAttrInfo(*l_attributeId);
                if (l_attrName == nullptr)
                {
                    TRACDCOMP( g_trac_devtree,
                               "No attribute name found for id 0x%.8x",
                               *l_attributeId);
                    continue;
                }

                // Look up the attr size
                uint32_t l_attrSize = attrSizeLookup(*l_attributeId);

                // Attr size check
                if(l_attrSize == 0)
                {
                    TRACFCOMP( g_trac_devtree, ERR_MRK "devtreeSyncAttrs() "
                               "Size = 0 for "
                               "attribute ID 0x%.8x, target HUID 0x%08X",
                               *l_attributeId,
                               l_targetHuid );

                    /*@
                        * @errortype
                        * @moduleid     DEVTREE_SYNC_ATTRS
                        * @reasoncode   TARGET_ATTR_ZERO_SIZE
                        * @userdata1    HUID
                        * @userdata2    Attribute ID
                        * @devdesc      Invalid attribute size of 0
                        * @custdesc     A problem occurred during the IPL
                        *               of the system.
                        */
                    l_err = new ERRORLOG::ErrlEntry(
                            ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                            DEVTREE_SYNC_ATTRS,
                            TARGET_ATTR_ZERO_SIZE,
                            l_targetHuid,
                            (*l_attributeId),
                            ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);

                    ERRORLOG::errlCommit(l_err, DEVTREE_COMP_ID);

                    // Continue with this target's next attribute
                    continue;
                }

                // Target attr data storage
                uint8_t l_attrData[l_attrSize] = {};

                // Get the target attribute data
                // Note: directly calling Target's private _tryGetAttr function,
                // the public function is a template function that cannot be
                // called with a variable attribute ID
                if (!l_target->_tryGetAttr(*l_attributeId,
                                           l_attrSize,
                                           l_attrData))
                {
                    TRACFCOMP(g_trac_devtree, ERR_MRK "devtreeSyncAttrs() "
                        "Can't get attribute data for ID 0x%.8x HUID 0x%08X",
                        *l_attributeId, l_targetHuid);

                    /*@
                        * @errortype
                        * @moduleid     DEVTREE_SYNC_ATTRS
                        * @reasoncode   GET_TARGET_ATTR_FAILED
                        * @userdata1    HUID
                        * @userdata2    Attribute ID
                        * @devdesc      Error reading targeting attribute
                        * @custdesc     A problem occurred during the IPL
                        *               of the system.
                        */
                    l_err = new ERRORLOG::ErrlEntry(
                            ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                            DEVTREE_SYNC_ATTRS,
                            GET_TARGET_ATTR_FAILED,
                            l_targetHuid,
                            (*l_attributeId),
                            ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);

                    ERRORLOG::errlCommit(l_err, DEVTREE_COMP_ID);

                    continue;
                }


    #ifdef CONFIG_DEVTREE_DEBUG
                //-------------------------------------------------------------
                // Debug only read and compare targ to devtree data
                debugReadCmpData(l_fdt,l_dtreeNodeOffset,(*l_attributeId),
                                 l_attrName,l_targetHuid,l_attrSize,l_attrData);
                //-------------------------------------------------------------
    #endif


                // If we get here we found writeable target attribute and data
                // that may exist in the devtree, attempt to write the devtree.
                // If rc < 0 the attribute does not exist in the devtree
                // or there was an error, handle error and go to next attribute
                int l_rc =
                    fdt_setprop_inplace(l_fdt,
                                        l_dtreeNodeOffset,
                                        l_attrName,
                                        static_cast<const void*>(l_attrData),
                                        l_attrSize);
                if (l_rc < 0)
                {
                    handleDtreeError(l_rc, l_targetHuid, l_attrName);
                    continue;
                }

            } // end attribute loop

        } // end target loop

        // Flush devtree updates out to pnor
        l_err = PNOR::flush( l_devtreeInfo.id );
        if (l_err)
        {
            TRACFCOMP(g_trac_devtree, ERR_MRK
                      "Error flushing DEVTREE data to PNOR");
            ERRORLOG::errlCommit(l_err, DEVTREE_COMP_ID);
            break;
        }

    } while(0);  // end do loop

    TRACFCOMP(g_trac_devtree, EXIT_MRK"DEVTREE::devtreeSyncAttrs");
} // devtreeSyncAttrs()


} // end namespace