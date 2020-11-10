/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/sbeio/runtime/rt_sbescom.C $                          */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2020                        */
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
 *  @file rt_sbescom.C
 *  @brief Runtime SBE Scom support for ocmb channel failure handling
 */
#include <devicefw/driverif.H>
#include <trace/interface.H>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>

#include <scom/scomif.H>
#include <scom/runtime/rt_scomif.H>
#include <targeting/common/utilFilter.H>

#include <plat/mem/prdfMemChnlFailCache.H> // chnlFailScomList

#include <map>

extern trace_desc_t* g_trac_sbeio;

namespace SBESCOM
{
// This map is used to cache a bulk read of SCOM values that we expect PRD
// to ask for.  A map of translated SCOM addresses and values is mapped to
// the parent chip target.
static std::map<TARGETING::Target *, std::map<uint64_t, uint64_t>> g_scomCache;


/**
 * @brief Mark the ocmb target as useSbeScom
 * @param[in] OCMB target
 */
static void markUseSbeScom(TARGETING::TargetHandle_t i_ocmb)
{
    TARGETING::ScomSwitches l_switches = {0};
    if (i_ocmb->tryGetAttr<TARGETING::ATTR_SCOM_SWITCHES>(l_switches))
    {
        TRACFCOMP(g_trac_sbeio,
              "markUseSbeScom: switching to use SBESCOM on OCMB 0x%.8X",
              TARGETING::get_huid(i_ocmb));

        l_switches.useSbeScom = 1;
        l_switches.useInbandScom = 0;

        // Mark target
        i_ocmb->setAttr<TARGETING::ATTR_SCOM_SWITCHES>(l_switches);
    }
}


/**
 * @brief OMI channel has checkstopped.  Mark it bad and switch to FSP/SBE access.
 *
 * @param[in]     i_target    ocmb target
 * @return  None
 */
void switchToSbeScomAccess(TARGETING::TargetHandle_t i_ocmb)
{
    TRACFCOMP(g_trac_sbeio,ENTER_MRK"switchToSbeScomAccess : 0x%.8X OCMB",
              TARGETING::get_huid(i_ocmb));
    errlHndl_t l_err = NULL;

    // switch to sbe scom since inband path does not work anymore
    markUseSbeScom(i_ocmb);

    std::map<uint64_t, uint64_t> l_newmap;

    // Cache SCOMs that PRD will request.  chnlFailScomList is a map of
    // target types (OCMB_CHIP, etc) and the associated SCOMs for them.
    // chnlFailScomList is maintained by PRD and defined in
    // prdfMemChnlFailCache.H.
    for (auto& l_typeScoms: PRDF::chnlFailScomList)
    {
        // Only OCMB will be cached
        if (l_typeScoms.first == TARGETING::TYPE_OCMB_CHIP)
        {
            std::vector<uint64_t> l_scomVals;

            l_scomVals.clear();
            l_err = FSISCOM::sendMultiScomReadToFsp(i_ocmb,
                                                    l_typeScoms.second,
                                                    l_scomVals);
            if (l_err)
            {
                TRACFCOMP(g_trac_sbeio,ERR_MRK
                          "There was an error caching the SCOMs "
                          "for huid(0x%llX)", get_huid(i_ocmb));
                errlCommit(l_err, RUNTIME_COMP_ID);
                continue;
            }

            // Combine the requested SCOM addrs with the returned values in
            // a local map, insert into cache keyed by target.  Don't save
            // SCOMs with a returned value of 0xDEADBEEF.
            for (size_t i = 0;i < l_typeScoms.second.size();++i)
            {
                uint64_t l_relAddr     = 0; // relative SCOM address
                l_relAddr = l_typeScoms.second[i];

                if (l_scomVals[i] != 0xDEADBEEF)
                {
                    l_newmap[l_relAddr] = l_scomVals[i];
                }
            } // for SCOM address list
        } // if TYPE_OCMB_CHIP
    } // for chnlFailScomList

    // Copy local map into cache for later use.
    g_scomCache[i_ocmb] = l_newmap;

    TRACFCOMP(g_trac_sbeio,EXIT_MRK"switchToSbeScomAccess");
}


/**
 * @brief Complete the SCOM operation through SBE.
 *
 * @param[in]     i_opType    Operation type, see driverif.H
 * @param[in]     i_ocmb      SCOM OCMB target
 * @param[in/out] io_buffer   Read: Pointer to output data storage
 *                            Write: Pointer to input data storage
 * @param[in/out] io_buflen   Input: size of io_buffer (in bytes)
 *                            Output: Read:  Size of output data
 *                                    Write: Size of data written
 * @param[in]   i_accessType  Access type
 * @param[in]   i_args        This is an argument list for DD framework.
 *                            In this function, there's only one argument,
 *                            which is the SCOM address
 * @return  errlHndl_t
 */
errlHndl_t sbeScomPerformOp(DeviceFW::OperationType i_opType,
                            TARGETING::TargetHandle_t i_ocmb,
                            void* io_buffer,
                            size_t& io_buflen,
                            int64_t i_accessType,
                            va_list i_args)
{
    TRACDCOMP(g_trac_sbeio,ENTER_MRK"sbeScomPerformOp");
    errlHndl_t l_err  = nullptr;
    uint64_t   l_addr = va_arg(i_args,uint64_t);

    l_err = SCOM::scomOpSanityCheck(i_opType,
                                    i_ocmb,
                                    io_buffer,
                                    io_buflen,
                                    l_addr,
                                    sizeof(uint64_t));

    if (l_err)
    {
        // Trace here - sanity check does not know scom type
        TRACFCOMP(g_trac_sbeio,"Runtime SBE Scom sanity check failed on %.8X",
            get_huid(i_ocmb));
    }
    else
    {
        bool found = false;
        auto targ = g_scomCache.find(i_ocmb); // find target, returns map of
                                              // SCOM addresses and values

        if (i_opType == DeviceFW::READ && targ != g_scomCache.end())
        {
            auto scomVal = targ->second.find(l_addr); // find SCOM address

            if (scomVal != targ->second.end())
            {
                // If we found the SCOM in the cache, then erase it from the
                // cache and return the value.
                found = true;
                uint64_t *val = static_cast<uint64_t *>(io_buffer);
                *val = scomVal->second;
                io_buflen = sizeof(uint64_t);
                targ->second.erase(scomVal);
            }
        }

        if (i_opType == DeviceFW::WRITE || found == false)
        {
            // routes from FSP to SBE scom
            l_err = FSISCOM::sendScomOpToFsp(i_opType, i_ocmb, l_addr, io_buffer);
        }
    }

    TRACDCOMP(g_trac_sbeio,EXIT_MRK"sbeScomPerformOp");

    return l_err;
}

// Direct OCMB SBE SCOM calls through this interface at runtime.
// This is an alternate route for when a OMI channel checkstop has
// occurred, and PHYP cannot service the operation.
DEVICE_REGISTER_ROUTE(DeviceFW::WILDCARD,
                      DeviceFW::SBESCOM,
                      TARGETING::TYPE_OCMB_CHIP,
                      sbeScomPerformOp);

}; // end namespace SBESCOM
