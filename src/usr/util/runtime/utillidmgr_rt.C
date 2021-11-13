/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/util/runtime/utillidmgr_rt.C $                        */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2021                        */
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
#include <stdio.h>
#include <algorithm>

/***
 * This class provides access to external data 'LIDs' at runtime.  The data
 * can only exist in three places:
 * - Inside HBRT reserved memory = iv_isLidInHbResvMem=true
 *   - Data was placed into memory by Hostboot during the IPL.  It is
 *     retrieved with the get_reserved_mem() call to the Host.  This is
 *     used primarily for OpenPOWER systems.
 * - Inside the HBRT code load itself = iv_isLidInVFS=true
 *   - Data is stored as a module inside the code image itself.
 * - Fetched from the service processor = other options false
 *   - Data is retrieved with lid_load() call to the Host.
 */

#include <util/utillidmgr.H>
#include <util/util_reasoncodes.H>
#include <errl/errlmanager.H>
#include <vfs/vfs.H>
#include <runtime/interface.h>
#include <initservice/initserviceif.H>
#include <secureboot/containerheader.H>
#include <trace/interface.H>
#include "../utilbase.H"
#include <util/utillidpnor.H>
#include <pnor/pnor_reasoncodes.H>
#include <targeting/common/mfgFlagAccessors.H>

extern trace_desc_t* g_trac_hbrt;

UtilLidMgr::UtilLidMgr(uint32_t i_lidId,
                       errlHndl_t* o_errlog)
:
    iv_lidBuffer(nullptr), iv_lidSize(0),
    iv_isLidInVFS(false), iv_isLidInHbResvMem(false)
{
    errlHndl_t l_err = nullptr;
    iv_spBaseServicesEnabled = INITSERVICE::spBaseServicesEnabled();
    l_err = updateLid(i_lidId);
    if (l_err)
    {
        UTIL_FT(ERR_MRK"UtilLidMgr::UtilLidMgr() cstor failed to update Lid (0x%X)",
                i_lidId);
        if( o_errlog )
        {
            *o_errlog = l_err;
        }
        else
        {
            errlCommit(l_err,UTIL_COMP_ID);
        }
        // Set to invalid lid id and allow to continue
        iv_lidId = Util::INVALID_LIDID;
    }
}

UtilLidMgr::~UtilLidMgr()
{
    errlHndl_t l_err = nullptr;

    l_err = cleanup();
    if(l_err)
    {
        //cleanup errors are extermely rare
        ERRORLOG::errlCommit( l_err, UTIL_COMP_ID );
    }
}

errlHndl_t UtilLidMgr::setLidId(uint32_t i_lidId)
{
    errlHndl_t l_err = nullptr;

    do {
    //must call cleanup before updateLid
    l_err = cleanup();
    if (l_err)
    {
        break;
    }

    l_err = updateLid(i_lidId);
    if (l_err)
    {
        break;
    }
    } while(0);

    return l_err;
}

errlHndl_t UtilLidMgr::getLidSize(size_t& o_lidSize)
{
    errlHndl_t l_err = loadLid();
    o_lidSize = iv_lidSize;

    return l_err;
}

errlHndl_t UtilLidMgr::getLid(void* i_dest, size_t i_destSize,
                              uint32_t* o_lidSize)
{
    errlHndl_t l_err = loadLid();

    if (iv_lidBuffer != nullptr)
    {
        memcpy(i_dest, iv_lidBuffer, std::min(i_destSize, iv_lidSize));
    }

    return l_err;
}

errlHndl_t UtilLidMgr::getStoredLidImage(void*& o_pLidImage,
                                         size_t& o_lidImageSize)
{
    errlHndl_t l_err = nullptr;

    if((nullptr == iv_lidBuffer) || (0 == iv_lidSize))
    {
        l_err = loadLid();
    }

    if(l_err)
    {
        o_lidImageSize = 0;
        o_pLidImage = nullptr;
    }
    else
    {
        o_lidImageSize = iv_lidSize;
        o_pLidImage = iv_lidBuffer;
    }

    return l_err;
}

errlHndl_t UtilLidMgr::releaseLidImage(void)
{
    // we already figured out where the data is, remember that
    bool l_inVFS = iv_isLidInVFS;
    bool l_inHbResvMem = iv_isLidInHbResvMem;

    errlHndl_t l_err = cleanup();

    // restore the presence info
    iv_isLidInVFS = l_inVFS;
    iv_isLidInHbResvMem = l_inHbResvMem;

    return l_err;
}

errlHndl_t UtilLidMgr::loadLid()
{
    if (nullptr != iv_lidBuffer) return nullptr;
    UTIL_FT("UtilLidMgr::loadLid");

    const char* l_addr = nullptr;
    size_t l_size = 0;
    errlHndl_t l_errl = nullptr;
    char* l_rsvd_mem_label = nullptr;
    TARGETING::ATTR_PAYLOAD_KIND_type l_payload =
      TARGETING::PAYLOAD_KIND_UNKNOWN;

    do
    {
        if(iv_isLidInHbResvMem)
        {
            // PHYP uses the lid number
            if( TARGETING::is_phyp_load(&l_payload) )
            {
                l_rsvd_mem_label = new char[9];
                sprintf( l_rsvd_mem_label, "%.8X", iv_lidId );
            }
            // OPAL uses the partition names
            else
            {
                const auto pnorSectionId = Util::getLidPnorSection(
                                           static_cast<Util::LidId>(iv_lidId));
                if( pnorSectionId == PNOR::INVALID_SECTION )
                {
                    UTIL_FT("UtilLidMgr::loadLid - No PNOR section for lid %.8X",
                            iv_lidId);
                    iv_lidSize = 0;
                    break;
                }

                const char* tmpstr = PNOR::SectionIdToString(pnorSectionId);
                if( tmpstr == nullptr )
                {
                    UTIL_FT("UtilLidMgr::loadLid - No string for section %d",
                            pnorSectionId);
                    iv_lidSize = 0;
                    break;
                }

                l_rsvd_mem_label = new char[strlen(tmpstr)+1];
                sprintf( l_rsvd_mem_label, "%s", tmpstr );
            }

            UTIL_FT("UtilLidMgr::loadLid> iv_isLidInHbResvMem=true, section=%s",
                    l_rsvd_mem_label);
            iv_lidBuffer = reinterpret_cast<void*>(g_hostInterfaces->
                get_reserved_mem(l_rsvd_mem_label,0));

            // If nullptr returned, set size to 0 to indicate we could not find
            // the lid in HB resv memory
            if (iv_lidBuffer == nullptr)
            {
                UTIL_FT("UtilLidMgr::loadLid - resv mem section %s not found",
                        l_rsvd_mem_label);
                iv_lidSize = 0;
                break;
            }
            else
            {
                UTIL_FT("UtilLidMgr::loadLid - resv mem section found");

                // Build a container header object to parse protected size
                SECUREBOOT::ContainerHeader l_conHdr;
                l_errl = l_conHdr.setHeader(iv_lidBuffer);
                if (l_errl)
                {
                    UTIL_FT(ERR_MRK"UtilLidMgr::loadLid - setheader failed");
                    break;
                }

                UTIL_FT("UtilLidMgr::loadLid - resv mem section has secure header");
                if (l_conHdr.sb_flags()->sw_hash)
                {
                    // Size of lid has to be size of unprotected data. So we
                    // need to take out header and hash table sizes
                    iv_lidSize = l_conHdr.totalContainerSize() - PAGESIZE -
                        l_conHdr.payloadTextSize();
                    iv_lidBuffer = static_cast<uint8_t*>(iv_lidBuffer) +
                                   PAGESIZE + l_conHdr.payloadTextSize();
                }
                else
                {
                    iv_lidSize = l_conHdr.payloadTextSize();
                    // Increment by page size to not expose secure header
                    iv_lidBuffer = static_cast<uint8_t*>(iv_lidBuffer) +
                                   PAGESIZE;
                }
            }
        }
        else if(iv_isLidInVFS)
        {
            UTIL_FT("UtilLidMgr::loadLid> iv_isLidInVFS=true");
            l_errl = VFS::module_address(iv_lidFileName, l_addr, l_size);
            if (l_errl)
            {
                break;
            }
            iv_lidBuffer = const_cast<void*>(reinterpret_cast<const void*>
                    (l_addr));
            iv_lidSize = l_size;
        }
        else if( g_hostInterfaces->lid_load )
        {
            UTIL_FT("UtilLidMgr::loadLid> Calling lid_load(0x%.8X)", iv_lidId);
            int rc = g_hostInterfaces->lid_load(iv_lidId, &iv_lidBuffer,
                    &iv_lidSize);
            if (0 != rc)
            {
                /*@
                 * @errortype
                 * @moduleid        Util::UTIL_LIDMGR_RT
                 * @reasoncode      Util::UTIL_LIDMGR_RC_FAIL
                 * @userdata1       Return code from lid_load call.
                 * @userdata2       Lid number
                 * @devdesc         Unable to load LID via host interface.
                 */
                l_errl = new ERRORLOG::ErrlEntry(
                    ERRORLOG::ERRL_SEV_PREDICTIVE,
                    Util::UTIL_LIDMGR_RT,
                    Util::UTIL_LIDMGR_RC_FAIL,
                    rc,
                    iv_lidId,
                    ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
                break;
            }
            UTIL_FT("UtilLidMgr::loadLid> size=%d, ptr=%p",
                    iv_lidSize, iv_lidBuffer);
        }

    } while (0);

    // Could not find the lid anywhere
    if( (l_errl == nullptr) && (iv_lidSize == 0) )
    {
        /*@
         * @errortype
         * @moduleid         Util::UTIL_LIDMGR_RT
         * @reasoncode       Util::UTIL_LIDMGR_NOT_FOUND
         * @userdata1        Lid number
         * @userdata2[00:07] Lid is in reserved memory
         * @userdata2[08:15] Lid is in VFS
         * @userdata2[16:23] lid_load interface is available
         * @userdata2[24:31] PAYLOAD_KIND
         * @devdesc          Unable to find Lid.
         */
        l_errl = new ERRORLOG::ErrlEntry(
                       ERRORLOG::ERRL_SEV_PREDICTIVE,
                       Util::UTIL_LIDMGR_RT,
                       Util::UTIL_LIDMGR_NOT_FOUND,
                       iv_lidId,
                       TWO_UINT32_TO_UINT64( FOUR_UINT8_TO_UINT32
                           ( iv_isLidInHbResvMem,
                             iv_isLidInVFS,
                             (g_hostInterfaces->lid_load==nullptr) ? 0 : 1,
                             l_payload ),
                           0 ),
                       ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
    }

    if( l_rsvd_mem_label )
    {
        delete[] l_rsvd_mem_label;
    }

    return l_errl;
}

errlHndl_t UtilLidMgr::cleanup()
{
    errlHndl_t l_err = nullptr;
    if ((!iv_isLidInVFS) && (nullptr != iv_lidBuffer) &&
         !iv_isLidInHbResvMem)
    {
        int l_rc = g_hostInterfaces->lid_unload(iv_lidBuffer);
        if (l_rc)
        {
            /*@
             * @errortype
             * @moduleid        Util::UTIL_LIDMGR_RT
             * @reasoncode      Util::UTIL_LIDMGR_UNLOAD_RC_FAIL
             * @userdata1       Return code from lid_unload call.
             * @devdesc         Unable to unload LID via host interface.
             */
            l_err = new ERRORLOG::ErrlEntry(
                        ERRORLOG::ERRL_SEV_PREDICTIVE,
                        Util::UTIL_LIDMGR_RT,
                        Util::UTIL_LIDMGR_UNLOAD_RC_FAIL,
                        l_rc);
        }
    }

    iv_lidBuffer   = nullptr;
    iv_lidSize     = 0;
    iv_isLidInVFS  = false;
    iv_isLidInHbResvMem = false;
    return l_err;
}

errlHndl_t UtilLidMgr::updateLid(uint32_t i_lidId)
{
    UTIL_FT("UtilLidMgr::updateLid - i_lidId=0x%.8X", i_lidId);
    iv_lidId = i_lidId;
    errlHndl_t l_err = nullptr;

    do {

    // First check if lid is already in hostboot reserved memory
    // In securemode the lid is pre-verified
    iv_isLidInHbResvMem = lidInHbResvMem(iv_lidId);
    if (iv_isLidInHbResvMem)
    {
        UTIL_FT("UtilLidMgr::updateLid - lid in Hb Resv Mem");
    }

    // Also check if it is part of our image
    sprintf(iv_lidFileName, "%x.lidbin", iv_lidId);
    iv_isLidInVFS  = VFS::module_exists(iv_lidFileName);
    if (iv_isLidInVFS)
    {
        UTIL_FT("UtilLidMgr::updateLid - lid in VFS");
    }

    } while (0);

    return l_err;
}

const uint32_t * UtilLidMgr::getLidList(size_t * o_num)
{
    TRACFCOMP(g_trac_hbrt, ENTER_MRK" get_lid_list");
    static uint32_t lidlist[] =
    {
        Util::OCC_LIDID,
        Util::OCC_CONTAINER_LIDID,
        Util::WOF_LIDID,
        Util::WOF_CONTAINER_LIDID,
        Util::P10_HCODE_LIDID,
        Util::HCODE_CONTAINER_LIDID,
        Util::HWREFIMG_RINGOVD_LIDID,
        Util::TARGETING_BINARY_LIDID,
    };
    *o_num = sizeof(lidlist)/sizeof(lidlist[0]);
    TRACFCOMP(g_trac_hbrt, EXIT_MRK" get_lid_list");
    return lidlist;
}

bool UtilLidMgr::lidInHbResvMem(const uint32_t i_lidId) const
{
    // No lids are stored in hb reserved memory as of now
    return false;
}

//------------------------------------------------------------------------

struct registerLidMgr
{
    registerLidMgr()
    {
        runtimeInterfaces_t * rt_intf = getRuntimeInterfaces();
        rt_intf->get_lid_list = &UtilLidMgr::getLidList;
    }
};

registerLidMgr g_registerLidMgr;
