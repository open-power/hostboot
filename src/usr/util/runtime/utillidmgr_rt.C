/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/util/runtime/utillidmgr_rt.C $                        */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013                   */
/*                                                                        */
/* p1                                                                     */
/*                                                                        */
/* Object Code Only (OCO) source materials                                */
/* Licensed Internal Code Source Materials                                */
/* IBM HostBoot Licensed Internal Code                                    */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* Origin: 30                                                             */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
#include <stdio.h>
#include <algorithm>

#include <util/utillidmgr.H>
#include <util/util_reasoncodes.H>
#include <errl/errlmanager.H>
#include <vfs/vfs.H>
#include <runtime/interface.h>

UtilLidMgr::UtilLidMgr(uint32_t i_lidId) :
    iv_isPnor(false), iv_lidBuffer(NULL), iv_lidSize(0)
{
    updateLid(i_lidId);
}

UtilLidMgr::~UtilLidMgr()
{
    errlHndl_t l_err = NULL;

    l_err = cleanup();
    if(l_err)
    {
        //cleanup errors are extermely rare
        ERRORLOG::errlCommit( l_err, UTIL_COMP_ID );
    }
}

errlHndl_t UtilLidMgr::setLidId(uint32_t i_lidId)
{
    errlHndl_t l_err = NULL;

    //must call cleanup before updateLid
    l_err = cleanup();

    updateLid(i_lidId);

    return l_err;
}

errlHndl_t UtilLidMgr::getLidSize(size_t& o_lidSize)
{
    errlHndl_t l_err = loadLid();
    o_lidSize = iv_lidSize;

    return l_err;
}

errlHndl_t UtilLidMgr::getLid(void* i_dest, size_t i_destSize)
{
    errlHndl_t l_err = loadLid();

    if (iv_lidBuffer != NULL)
    {
        memcpy(i_dest, iv_lidBuffer, std::min(i_destSize, iv_lidSize));
    }

    return l_err;
}

errlHndl_t UtilLidMgr::loadLid()
{
    // Check if it is already loaded.
    if (NULL != iv_lidBuffer) return NULL;

    const char* l_addr = NULL;
    size_t l_size = 0;
    errlHndl_t l_errl = VFS::module_address(iv_lidFileName, l_addr, l_size);

    if (l_errl)
    {
        delete l_errl;
        int rc =
            g_hostInterfaces->lid_load(iv_lidId, &iv_lidBuffer, &iv_lidSize);

        if (0 != rc)
        {
            /*@
             * @errortype       ERRL_SEV_INFORMATIONAL
             * @moduleid        Util::UTIL_LIDMGR_RT
             * @reasoncode      Util::UTIL_LIDMGR_RC_FAIL
             * @userdata1       Return code from lid_load call.
             * @devdesc         Unable to load LID via host interface.
             */
            l_errl = new ERRORLOG::ErrlEntry(
                ERRORLOG::ERRL_SEV_INFORMATIONAL,
                Util::UTIL_LIDMGR_RT,
                Util::UTIL_LIDMGR_RC_FAIL,
                rc);
        }
    }
    else
    {
        iv_isPnor = true;
        iv_lidBuffer = const_cast<void*>(reinterpret_cast<const void*>(l_addr));
        iv_lidSize = l_size;
    }

    return l_errl;
}

errlHndl_t UtilLidMgr::cleanup()
{
    if ((!iv_isPnor) && (NULL != iv_lidBuffer))
    {
        g_hostInterfaces->lid_unload(iv_lidBuffer);
    }
    iv_lidBuffer = NULL;

    iv_lidSize = 0;
    iv_isPnor = false;
    return NULL;
}

void UtilLidMgr::updateLid(uint32_t i_lidId)
{
    iv_lidId = i_lidId;

    //if it's in PNOR, it's not technically lid, so use a slightly
    //different extension.
    sprintf(iv_lidFileName, "%x.lidbin", iv_lidId);

    return;
}
