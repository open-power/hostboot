/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/scom/centaurScomCache.C $                             */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2018                        */
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
 *  @file src/usr/scom/centaurScomCache.C
 *
 *  @brief Implementation for Centaur SCOM register cache
 */

//******************************************************************************
// Includes
//******************************************************************************

#include <assert.h>
#include <devicefw/driverif.H>
#include <trace/interface.H>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <errl/errludtarget.H>
#include <targeting/common/utilFilter.H>
#include <scom/scomreasoncodes.H>

#include <scom/centaurScomCache.H>
#include "scom.H"
#include "errlud_cache.H"

namespace SECUREBOOT
{

namespace CENTAUR_SECURITY
{

const bool ADD_HI_PRI_HB_SW_CALLOUT=true;
const bool NO_HB_SW_CALLOUT=false;

ScomCache::ScomCache()
    : iv_pScomRegDefs(_initScomRegDefs()),
      iv_cacheEnabled(false)
{
    // Sort SCOM register defintion records by register address so that we
    // can look up a given register using std::lower_bound in O(log n)
    // algorithmic complexity and then jump to same index within local
    // Centaur SCOM cache to find the current value, yielding overall
    // algorithmic complexity of O(log n) for lookup of any given Centaur's
    // cached SCOM register
    std::sort(
        iv_pScomRegDefs->begin(),
        iv_pScomRegDefs->end(),
        [](const ScomRegDef& i_lhs,const ScomRegDef &i_rhs)
        {
            return (i_lhs.addr<i_rhs.addr);
        });

    _enforceScomRegDefUniqueness();

    _validateScomRegDefs();

    _optimizeScomRegDefs();
}

ScomCache::~ScomCache()
{
    delete iv_pScomRegDefs;
    iv_pScomRegDefs=nullptr;
}

void ScomCache::_enforceScomRegDefUniqueness() const
{
    // Assumes the register definitions are already sorted
    auto scomRegDefDupStartItr =
        std::unique(iv_pScomRegDefs->begin(), iv_pScomRegDefs->end(),
        [](const ScomRegDef& i_lhs, const ScomRegDef& i_rhs)
        {
            return (i_lhs.addr==i_rhs.addr);
        }
    );

    auto scomRegDefDupItr = scomRegDefDupStartItr;
    while(scomRegDefDupItr != iv_pScomRegDefs->end())
    {
        TRACFCOMP(g_trac_scom,ERR_MRK
            "Found duplicate SCOM register definition for address 0x%016llX",
            scomRegDefDupItr->addr);
        ++scomRegDefDupItr;
    }

    assert(scomRegDefDupStartItr == iv_pScomRegDefs->end(),
        "BUG! Duplicate Centaur SCOM register "
        "definitions found");
}

void ScomCache::_validateScomRegDefs() const
{
    for(const auto& scomRegDef : *iv_pScomRegDefs)
    {
        assert(scomRegDef.addr != 0,"BUG! Centaur SCOM register definition "
            "address is 0");

        // Index fixup should happen later; starts out as DEFAULT_BASE_INDEX
        assert(scomRegDef.baseIndex == ScomRegDef::DEFAULT_BASE_INDEX,
            "Centaur SCOM register "
            "definition has non DEFAULT_BASE_INDEX baseIndex for "
            "register address 0x%016llX.",
            scomRegDef.addr);

        if(scomRegDef.hasBaseAddr())
        {
            assert(!(scomRegDef.isWandReg && scomRegDef.isWorReg),
                "BUG! Centaur SCOM register definition should only have "
                "one of isWandReg or isWorReg set. Actual isWandReg = %d, "
                "isWorReg = %d for "
                "register address 0x%016llX.",
                scomRegDef.isWandReg,scomRegDef.isWorReg,scomRegDef.addr);
            assert(scomRegDef.baseAddr != ScomRegDef::DEFAULT_BASE_ADDR,
                "BUG! Centaur SCOM register "
                "definition should have a base register, but it is "
                "DEFAULT_BASE_ADDR "
                "for register address 0x%016llX.",scomRegDef.addr);
            assert(   scomRegDef.expectedHwInitValue
                   == ScomRegDef::DEFAULT_EXPECTED_HW_INIT_VALUE,
                "BUG! Centaur SCOM "
                "register definition having base address should have an "
                "expected HW init value of DEFAULT_EXPECTED_HW_INIT_VALUE but "
                "it is 0x%016llX for address 0x%016llX.",
                scomRegDef.expectedHwInitValue,scomRegDef.addr);
            assert(!scomRegDef.mask,
                "BUG! Centaur SCOM register "
                "definition having base address should have a mask of "
                "all 0b0's, but it is 0x%016llX for address 0x%016llX.",
                scomRegDef.mask,scomRegDef.addr);
        }
        else
        {
            assert(!scomRegDef.baseAddr, "BUG! Centaur SCOM register "
                "definition should not have a base register, but it's "
                "0x%016llX for address 0x%016llX.",
                scomRegDef.baseAddr,scomRegDef.addr);
            assert(scomRegDef.mask, "BUG! Centaur SCOM register "
                "definition should have a mask of !0 "
                "but it is 0 for address 0x%016llX.",
                scomRegDef.addr);
        }
    }
}

void ScomCache::_optimizeScomRegDefs()
{
    for(auto scomRegDefItr=iv_pScomRegDefs->begin();
        scomRegDefItr != iv_pScomRegDefs->end();
        ++scomRegDefItr)
    {
        if(scomRegDefItr->hasBaseAddr())
        {
            ScomRegDef regToFind(scomRegDefItr->baseAddr);
            auto scomBaseRegDefItr=std::lower_bound(
                iv_pScomRegDefs->begin(),
                iv_pScomRegDefs->end(),
                regToFind,
                [](const ScomRegDef& i_lhs, const ScomRegDef& i_rhs)
                {
                    return (i_lhs.addr<i_rhs.addr);
                }
                  );
            assert(   (scomBaseRegDefItr!=iv_pScomRegDefs->end())
                   && (scomBaseRegDefItr->addr==scomRegDefItr->baseAddr),
                "BUG! Could not find base register 0x%016llX for register "
                "0x%016llX.",scomRegDefItr->baseAddr,scomRegDefItr->addr);
            scomRegDefItr->baseIndex=scomBaseRegDefItr-iv_pScomRegDefs->begin();
        }
        else
        {
            scomRegDefItr->baseIndex=scomRegDefItr-iv_pScomRegDefs->begin();
        }
    }
}

void ScomCache::init() const
{
    destroy();

    std::vector<uint64_t> registerCache(iv_pScomRegDefs->size(),0);
    auto registerCacheItr = registerCache.begin();
    for (const auto& scomRegDef : *iv_pScomRegDefs)
    {
        if(!scomRegDef.hasBaseAddr())
        {
            (*registerCacheItr) = scomRegDef.expectedHwInitValue;
        }
        ++registerCacheItr;
    }

    // Find functional Centaurs
    TARGETING::TargetHandleList centaurTargets;
    (void)getAllChips(centaurTargets, TARGETING::TYPE_MEMBUF);

    for(auto& pCentaur : centaurTargets)
    {
        if(   pCentaur->getAttr<TARGETING::ATTR_MODEL>()
           != TARGETING::MODEL_CENTAUR)
        {
            continue;
        }

        const std::vector<uint64_t>* pCache
            =_getCachePtr(pCentaur);
        assert(pCache==nullptr,"BUG! Centaur cache detected prior to init");

        // Clone the initialized cache into each Centaur target and transfer
        // memory ownership
        pCache = new std::vector<uint64_t>(registerCache);
        _setCachePtr(pCentaur,pCache);
        pCache=nullptr;
    }
}

void ScomCache::destroy() const
{
    // Grab all blueprint Centaurs in case a Centaur got deconfigured after
    // Hostboot configured its cache
    TARGETING::TargetHandleList centaurTargets;
    (void)getAllChips(centaurTargets, TARGETING::TYPE_MEMBUF, false);

    for(auto& pCentaur : centaurTargets)
    {
        if(   pCentaur->getAttr<TARGETING::ATTR_MODEL>()
           != TARGETING::MODEL_CENTAUR)
        {
            continue;
        }

        std::vector<uint64_t>* pCache = _getCachePtr(pCentaur);
        if(pCache)
        {
            delete pCache;
            pCache = nullptr;
            _setCachePtr(pCentaur,pCache);
        }
    }
}

errlHndl_t ScomCache::write(
          TARGETING::Target* const i_pMembuf,
    const uint64_t                 i_addr,
    const uint64_t                 i_value) const
{
    TRACDCOMP(g_trac_scom,INFO_MRK
        "ScomCache::write: register 0x%016llX, value 0x%016llX, HUID 0x%08X",
        i_addr,i_value,TARGETING::get_huid(i_pMembuf));

    errlHndl_t pError=nullptr;

    do {

    if(i_pMembuf==nullptr)
    {
        TRACFCOMP(g_trac_scom,ERR_MRK
            "BUG! API usage error! Caller passed a nullptr target");

        /*@
         * @errortype
         * @moduleid   SCOM::SCOM_WRITE_CENTAUR_CACHE
         * @reasoncode SCOM::SCOM_BAD_TARGET
         * @devdesc    Caller passed a nullptr target when attempting to
         *     write the SCOM cache
         * @custdesc   Secure Boot failure
         */
        pError = new ERRORLOG::ErrlEntry(
            ERRORLOG::ERRL_SEV_UNRECOVERABLE,
            SCOM::SCOM_WRITE_CENTAUR_CACHE,
            SCOM::SCOM_BAD_TARGET,
            0,
            0,
            ADD_HI_PRI_HB_SW_CALLOUT);

        break;
    }

    if(   cacheEnabled()
       && (   i_pMembuf->getAttr<TARGETING::ATTR_MODEL>()
           == TARGETING::MODEL_CENTAUR) )
    {
        // This is logically still the input
        TARGETING::Target* const i_pCentaur = i_pMembuf;

        std::vector<uint64_t>* const pCache = _getCachePtr(i_pCentaur);
        if(pCache==nullptr)
        {
            TRACFCOMP(g_trac_scom,ERR_MRK
                "BUG! Sequence error! Cache for Centaur with HUID "
                "0x%08X is not properly initialized",
                TARGETING::get_huid(i_pCentaur));

            /*@
             * @errortype
             * @moduleid   SCOM::SCOM_WRITE_CENTAUR_CACHE
             * @reasoncode SCOM::SCOM_CACHE_SEQ_ERROR
             * @userdata1  HUID of Centaur whose cache was not initialized
             * @devdesc    Caller attempted to write a Centaur cache that
             *     is not initialized.
             * @custdesc   Secure Boot failure
             */
            pError = new ERRORLOG::ErrlEntry(
                ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                SCOM::SCOM_WRITE_CENTAUR_CACHE,
                SCOM::SCOM_CACHE_SEQ_ERROR,
                TARGETING::get_huid(i_pCentaur),
                0,
                ADD_HI_PRI_HB_SW_CALLOUT);

            break;
        }

        ssize_t index=ScomRegDef::DEFAULT_BASE_INDEX;
        ScomRegDef regToFind(i_addr);
        auto scomRegDefItr=std::lower_bound(
            iv_pScomRegDefs->begin(),
            iv_pScomRegDefs->end(),
            regToFind,
            [](const ScomRegDef& i_lhs, const ScomRegDef& i_rhs)
            {
                return (i_lhs.addr<i_rhs.addr);
            } );
        if(   (scomRegDefItr!=iv_pScomRegDefs->end())
           && (scomRegDefItr->addr==i_addr))
        {
            index=scomRegDefItr->baseIndex;

            if(scomRegDefItr->isWandReg)
            {
                (*pCache)[index] &= i_value;
            }
            else if(scomRegDefItr->isWorReg)
            {
                (*pCache)[index] |= i_value;
            }
            else
            {
                (*pCache)[index] = i_value;
            }
        }
        // else ...
        // Not a cacheable register = noop
    }

    } while(0);

    if(pError)
    {
        // Collect interesting traces
        pError->collectTrace(SCOM_COMP_NAME);
        pError->collectTrace(SECURE_COMP_NAME);
    }

    return pError;
}

errlHndl_t ScomCache::read(
          TARGETING::Target* i_pMembuf,
    const uint64_t           i_addr,
          bool&              o_cacheHit,
          uint64_t&          o_value) const
{
    TRACDCOMP(g_trac_scom,INFO_MRK
        "ScomCache::read: register 0x%016llX, HUID 0x%08X",
        i_addr,TARGETING::get_huid(i_pMembuf));

    errlHndl_t pError=nullptr;
    auto cacheHit = false;

    do {

    if(i_pMembuf==nullptr)
    {
        TRACFCOMP(g_trac_scom,ERR_MRK
            "BUG! API usage error! Caller passed a nullptr target");

        /*@
         * @errortype
         * @moduleid   SCOM::SCOM_READ_CENTAUR_CACHE
         * @reasoncode SCOM::SCOM_BAD_TARGET
         * @devdesc    Caller passed a nullptr target when attempting to
         *     read the SCOM cache
         * @custdesc   Secure Boot failure
         */
        pError = new ERRORLOG::ErrlEntry(
            ERRORLOG::ERRL_SEV_UNRECOVERABLE,
            SCOM::SCOM_READ_CENTAUR_CACHE,
            SCOM::SCOM_BAD_TARGET,
            0,
            0,
            ADD_HI_PRI_HB_SW_CALLOUT);

        break;
    }

    if(   cacheEnabled()
       && (   i_pMembuf->getAttr<TARGETING::ATTR_MODEL>()
           == TARGETING::MODEL_CENTAUR) )
    {
        // This is logically still the input
        TARGETING::Target* const i_pCentaur = i_pMembuf;

        std::vector<uint64_t>* const pCache = _getCachePtr(i_pCentaur);
        if(pCache==nullptr)
        {
            TRACFCOMP(g_trac_scom,ERR_MRK
                "BUG! Sequence error! Cache for Centaur with HUID "
                "0x%08X is not properly initialized",
                TARGETING::get_huid(i_pCentaur));

            /*@
             * @errortype
             * @moduleid   SCOM::SCOM_READ_CENTAUR_CACHE
             * @reasoncode SCOM::SCOM_CACHE_SEQ_ERROR
             * @userdata1  HUID of Centaur whose cache was not initialized
             * @devdesc    Caller attempted to read a Centaur cache that
             *     is not initialized.
             * @custdesc   Secure Boot failure
             */
            pError = new ERRORLOG::ErrlEntry(
                ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                SCOM::SCOM_READ_CENTAUR_CACHE,
                SCOM::SCOM_CACHE_SEQ_ERROR,
                TARGETING::get_huid(i_pCentaur),
                0,
                ADD_HI_PRI_HB_SW_CALLOUT);

            break;
        }

        ScomRegDef regToFind(i_addr);
        auto scomRegDefItr=std::lower_bound(
            iv_pScomRegDefs->begin(),
            iv_pScomRegDefs->end(),
            regToFind,
            [](const ScomRegDef& i_lhs, const ScomRegDef& i_rhs)
            {
                return (i_lhs.addr<i_rhs.addr);
            } );
        if(   (scomRegDefItr!=iv_pScomRegDefs->end())
           && (scomRegDefItr->addr==i_addr) )
        {
            if(!scomRegDefItr->hasBaseAddr())
            {
                o_value = (*pCache)[scomRegDefItr->baseIndex];
                cacheHit = true;
            }
            // else ...
            // Attempt to read WAND/WOR register is not allowed;
            // Force a cache miss and let SCOM code handle
            // getting an error on the HW read
        }
        // else ...
        // No cache entry for this address
    }
    // else ...
    // Cache not applicable

    } while(0);

    o_cacheHit=cacheHit;
    if(!o_cacheHit)
    {
        o_value=0;
    }

    if(pError)
    {
        // Collect interesting traces
        pError->collectTrace(SCOM_COMP_NAME);
        pError->collectTrace(SECURE_COMP_NAME);
    }

    return pError;
}

errlHndl_t ScomCache::verify() const
{
    errlHndl_t pError=nullptr;

    do {

    if(cacheEnabled())
    {
        TRACFCOMP(g_trac_scom,ERR_MRK
            "BUG! Sequence error! Cannot verify cache when it's enabled");

        /*@
         * @errortype
         * @moduleid   SCOM::SCOM_VERIFY_CENTAUR_CACHE
         * @reasoncode SCOM::SCOM_BAD_CACHE_VERIFY_SEQ
         * @devdesc    Centaurs' SCOM cache cannot be verified when caching
         *     is enabled
         * @custdesc   Secure Boot failure
         */
        pError = new ERRORLOG::ErrlEntry(
            ERRORLOG::ERRL_SEV_UNRECOVERABLE,
            SCOM::SCOM_VERIFY_CENTAUR_CACHE,
            SCOM::SCOM_BAD_CACHE_VERIFY_SEQ,
            0,
            0,
            ADD_HI_PRI_HB_SW_CALLOUT);

        break;
    }

    TRACFCOMP(g_trac_scom,INFO_MRK
        "Verifying Centaur SCOM caches against hardware");

    TARGETING::TargetHandleList centaurTargets;
    (void)getAllChips(centaurTargets, TARGETING::TYPE_MEMBUF);

    for(auto& pCentaur : centaurTargets)
    {
        if(   pCentaur->getAttr<TARGETING::ATTR_MODEL>()
           != TARGETING::MODEL_CENTAUR)
        {
            continue;
        }

        std::vector<uint64_t>* const pCache = _getCachePtr(pCentaur);
        if(pCache==nullptr)
        {
            TRACFCOMP(g_trac_scom,ERR_MRK
                "BUG! Sequence error! Cache for Centaur with HUID "
                "0x%08X is not properly initialized",
                TARGETING::get_huid(pCentaur));

            /*@
             * @errortype
             * @moduleid   SCOM::SCOM_VERIFY_CENTAUR_CACHE
             * @reasoncode SCOM::SCOM_CACHE_SEQ_ERROR
             * @userdata1  HUID of Centaur whose cache was not initialized
             * @devdesc    Caller attempted to read a Centaur cache that
             *     is not initialized.
             * @custdesc   Secure Boot failure
             */
            pError = new ERRORLOG::ErrlEntry(
                ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                SCOM::SCOM_VERIFY_CENTAUR_CACHE,
                SCOM::SCOM_CACHE_SEQ_ERROR,
                TARGETING::get_huid(pCentaur),
                0,
                ADD_HI_PRI_HB_SW_CALLOUT);

            break;
        }

        TRACFCOMP(g_trac_scom,INFO_MRK
            "Verifying Centaur SCOM cache for HUID=0x%08X",
            TARGETING::get_huid(pCentaur));

        size_t index=0;
        for(const auto& scomRegDef : *iv_pScomRegDefs)
        {
            if(!scomRegDef.hasBaseAddr())
            {
                uint64_t actualValue = 0;
                const size_t expSize = sizeof(actualValue);
                auto reqSize = expSize;
                pError = deviceRead(pCentaur,
                                    &actualValue,
                                    reqSize,
                                    DEVICE_SCOM_ADDRESS(
                                        scomRegDef.addr));
                if(pError)
                {
                    TRACFCOMP(g_trac_scom,ERR_MRK
                        "ScomCache::verify: SCOM deviceRead call failed for "
                        "Target HUID 0x%08X and address 0x%016llX. "
                        TRACE_ERR_FMT,
                        TARGETING::get_huid(pCentaur),
                        scomRegDef.addr,
                        TRACE_ERR_ARGS(pError));

                    // save the PLID from the error before committing
                    const auto plid = pError->plid();
                    ERRORLOG::errlCommit(pError, SCOM_COMP_ID);

                    /*@
                     * @errortype
                     * @reasoncode SCOM::SCOM_SENSITIVE_REG_READ_FAIL
                     * @moduleid   SCOM::SCOM_VERIFY_CENTAUR_CACHE
                     * @userdata1  HUID of offending Centaur
                     * @userdata2  SCOM address
                     * @devdesc    Failed attempting to read current value of
                     *     sensitive Centaur SCOM register after locking down
                     *     the Centaur.  The Centaur will be deconfigured in
                     *     order to maintain system security.
                     * @custdesc   Secure Boot failure
                     */
                    pError = new ERRORLOG::ErrlEntry(
                        ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                        SCOM::SCOM_VERIFY_CENTAUR_CACHE,
                        SCOM::SCOM_SENSITIVE_REG_READ_FAIL,
                        TARGETING::get_huid(pCentaur),
                        scomRegDef.addr,
                        NO_HB_SW_CALLOUT);

                    // Link to the original PLID
                    pError->plid(plid);

                    // Most likely a hardware problem
                    pError->addHwCallout(
                        pCentaur,
                        HWAS::SRCI_PRIORITY_HIGH,
                        HWAS::DELAYED_DECONFIG,
                        HWAS::GARD_NULL);

                    // Next most likely a software issue
                    pError->addProcedureCallout(
                        HWAS::EPUB_PRC_HB_CODE,
                        HWAS::SRCI_PRIORITY_MED);

                    break;
                }
                else
                {
                    assert(reqSize==expSize,"ScomCache::verify: SCOM "
                        "deviceRead didn't return expected data size "
                        "of %d (it was %d)",
                        expSize,reqSize);
                    const auto expectedValue = (*pCache)[index];
                    if(   (expectedValue & scomRegDef.mask)
                       != (actualValue   & scomRegDef.mask) )
                    {
                        TRACFCOMP(g_trac_scom,ERR_MRK
                            "For Centaur with HUID of 0x%08X, found "
                            "discrepancy between expected and actual "
                            "security sensitive SCOM register values.",
                            TARGETING::get_huid(pCentaur));
                        TRACFCOMP(g_trac_scom,ERR_MRK
                            "    Register: 0x%016llX, "
                            "Expected value (masked): 0x%016llX, "
                            "Actual value (masked): 0x%016llX, ",
                            scomRegDef.addr,
                            expectedValue & scomRegDef.mask,
                            actualValue & scomRegDef.mask);
                        TRACFCOMP(g_trac_scom,ERR_MRK
                            "    Unmasked cache value: 0x%016llX, "
                            "Unmasked register value: 0x%016llX, "
                            "Mask: 0x%016llX.",
                            expectedValue,
                            actualValue,
                            scomRegDef.mask);

                        /*@
                         * @errortype
                         * @reasoncode SCOM::SCOM_CACHE_VERIFY_FAILURE
                         * @moduleid   SCOM::SCOM_VERIFY_CENTAUR_CACHE
                         * @userdata1  HUID of Centaur being verified
                         * @userdata2  SCOM address registering the mismatch
                         * @devdesc    Secure Boot detected an unexpected
                         *     discrepancy between the expected and actual
                         *     values of a security sensitive Centaur SCOM
                         *     register after locking down the Centaur.  The
                         *     Centaur will be deconfigured in order to
                         *     maintain system security.
                         * @custdesc   Secure Boot failure
                         */

                        // Most likely a software bug
                        pError = new ERRORLOG::ErrlEntry(
                            ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                            SCOM::SCOM_VERIFY_CENTAUR_CACHE,
                            SCOM::SCOM_CACHE_VERIFY_FAILURE,
                            TARGETING::get_huid(pCentaur),
                            scomRegDef.addr,
                            ADD_HI_PRI_HB_SW_CALLOUT);

                        UdCentaurCacheMismatch ffdc(
                            scomRegDef.addr,
                            expectedValue,
                            actualValue,
                            scomRegDef.mask);
                        ffdc.addToLog(pError);

                        // Next most likely a hardware issue
                        pError->addHwCallout(
                            pCentaur,
                            HWAS::SRCI_PRIORITY_MED,
                            HWAS::DELAYED_DECONFIG,
                            HWAS::GARD_NULL);

                        break;
                    }
                }
            }
            // else ...
            // Not a meaningful register to cache verify, no-op it

            ++index;
        }

        if(pError)
        {
            // Log the target information
            ERRORLOG::ErrlUserDetailsTarget(pCentaur).
                addToLog(pError);

            // Collect interesting traces
            pError->collectTrace(SCOM_COMP_NAME);
            pError->collectTrace(SECURE_COMP_NAME);

            // Commit it
            ERRORLOG::errlCommit(pError,SCOM_COMP_ID);
        }
    }

    } while(0);

    if(pError)
    {
        // Collect interesting traces
        pError->collectTrace(SCOM_COMP_NAME);
        pError->collectTrace(SECURE_COMP_NAME);
    }

    return pError;
}

void ScomCache::dump(void) const
{
    errlHndl_t pError=nullptr;

    do {

    if(cacheEnabled())
    {
        TRACFCOMP(g_trac_scom,INFO_MRK
            "**WARNING** Centaur SCOM cache dump HW reads being pulled "
            "from cache instead of actual hardware");
    }

    TARGETING::TargetHandleList centaurTargets;
    (void)getAllChips(centaurTargets, TARGETING::TYPE_MEMBUF);

    for(auto& pCentaur : centaurTargets)
    {
        if(   pCentaur->getAttr<TARGETING::ATTR_MODEL>()
           != TARGETING::MODEL_CENTAUR)
        {
            continue;
        }

        std::vector<uint64_t>* const pCache = _getCachePtr(pCentaur);
        if(pCache)
        {
            TRACFCOMP(g_trac_scom,INFO_MRK
                "Dumping Centaur cache for: HUID=0x%08X",
                TARGETING::get_huid(pCentaur));

            size_t index=0;
            for(const auto& scomRegDef : *iv_pScomRegDefs)
            {
                if(!scomRegDef.hasBaseAddr())
                {
                    uint64_t actualValue = 0;
                    const size_t expSize = sizeof(actualValue);
                    auto reqSize = expSize;
                    pError = deviceRead(pCentaur,
                                        &actualValue,
                                        reqSize,
                                        DEVICE_SCOM_ADDRESS(
                                            scomRegDef.addr));
                    if(pError)
                    {
                        TRACFCOMP(g_trac_scom,ERR_MRK
                            "ScomCache::dump: SCOM deviceRead call failed for "
                            "Target HUID 0x%08X and address 0x%016llX. "
                            TRACE_ERR_FMT "Ignoring and continuing on.",
                            TARGETING::get_huid(pCentaur),
                            scomRegDef.addr,
                            TRACE_ERR_ARGS(pError));

                        pError->collectTrace(SCOM_COMP_NAME);
                        pError->collectTrace(SECURE_COMP_NAME);

                        errlCommit(pError,SCOM_COMP_ID);
                    }
                    else
                    {
                        assert(reqSize==expSize,"ScomCache::verify: SCOM "
                            "deviceRead didn't return expected data size "
                            "of %d (it was %d)",
                            expSize,reqSize);
                        const auto expectedValue = (*pCache)[index];
                        const auto expectedValueMasked =
                            expectedValue & scomRegDef.mask;
                        const auto actualValueMasked =
                            actualValue & scomRegDef.mask;

                        // Split trace for readability
                        TRACFCOMP(g_trac_scom,INFO_MRK
                            "Register: 0x%016llX, "
                            "Expected value (masked): 0x%016llX, "
                            "Actual value (masked): 0x%016llX%s, ",
                            scomRegDef.addr,
                            expectedValueMasked,
                            actualValueMasked,
                            (   expectedValueMasked
                             == actualValueMasked) ? "" : " (MISMATCH!)");
                        TRACFCOMP(g_trac_scom,INFO_MRK
                            "    Unmasked cache value: 0x%016llX, "
                            "Unmasked register value: 0x%016llX, "
                            "Mask: 0x%016llX.",
                            expectedValue,
                            actualValue,
                            scomRegDef.mask);
                    }
                }
                // else ...
                // Not a meaningful register to dump

                ++index;
            }
        }
        else // No cache entry for this Centaur
        {
            TRACFCOMP(g_trac_scom,INFO_MRK
                "Warning: No cache for Centaur with HUID of 0x%08X.",
                TARGETING::get_huid(pCentaur));
        }
    }

    } while(0);
}

bool ScomCache::cacheEnabled() const
{
    return iv_cacheEnabled;
}

void ScomCache::enableCache()
{
    TRACFCOMP(g_trac_scom,INFO_MRK
        "Enabling Centaur SCOM cache");
    iv_cacheEnabled=true;
}

void ScomCache::disableCache()
{
    TRACFCOMP(g_trac_scom,INFO_MRK
        "Disabling Centaur SCOM cache");
    iv_cacheEnabled=false;
}

ScomCache& ScomCache::getInstance()
{
    return Singleton<ScomCache>::instance();
}

} // end CENTAUR_SECURITY namespace

} // end SECUREBOOT namespace

