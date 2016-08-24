/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/attn/common/attnprd.C $                          */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2016                        */
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
 * @file attnprd.C
 *
 * @brief HBATTN PRD wrapper class definitions.
 */

#include "ipl/attnsvc.H"
#include "common/attnprd.H"
#include "common/attnops.H"
#include "common/attnlist.H"
#include "common/attntrace.H"
#include "common/attntarget.H"
#include "common/attnproc.H"
#include "common/attnmem.H"
#include <util/singleton.H>
#include <errl/errlmanager.H>

// Custom compile configs
#include <config.h>

#if !defined(__HOSTBOOT_RUNTIME) && defined(CONFIG_ENABLE_CHECKSTOP_ANALYSIS)
  #include <prdf/prdfMain_ipl.H>
#endif

using namespace std;
using namespace PRDF;
using namespace TARGETING;
using namespace Util;

namespace ATTN
{

void PrdImpl::installPrd()
{
    getPrdWrapper().setImpl(*this);
}

errlHndl_t PrdImpl::callPrd(const AttentionList & i_attentions)
{
    // forward call to the real PRD

    errlHndl_t err = NULL;

    // convert attention list to PRD type

    AttnList attnList;

    i_attentions.getAttnList(attnList);

    if(!attnList.empty())
    {
        // AttentionLists keep themselves sorted by attention type
        // with higher priority attentions
        // appearing before those with lower priority, where the
        // priority is defined by the ATTENTION_VALUE_TYPE enum.
        //
        // When an AttentionList is converted to an AttnList
        // the order is preserved.  In this way, the PRD
        // requirement that the highest priority attention
        // appear first in the argument list is satisfied.

        // Checkstop can only be handled in next IPL session. Call
        // separate function to handle CS.
        #if !defined(__HOSTBOOT_RUNTIME) && \
            defined(CONFIG_ENABLE_CHECKSTOP_ANALYSIS)
        if( MACHINE_CHECK == attnList.front().attnType )
        {
            err = PRDF::analyzeCheckStop(attnList.front().attnType, attnList);
        }
        else
        #endif
        {
            err = PRDF::main(attnList.front().attnType, attnList);

            // For the initial NIMBUS chip, there is a HW issue
            // which requires us to clear the "Combined Global
            // interrupt register" on recoverable errors.
            // This also affects Checkstop/Special Attns, but
            // the FSP handles those and already clears the reg.
            // The issue does not apply to host/unit cs attns.
            uint8_t l_ecLevel = 0;
            AttnList::iterator  l_attnIter = attnList.begin();

            // Shouldn't be mixing NIMBUS with CUMULUS,etc...
            // so probably don't need to repeat this call per chip.
            bool l_isNimbus = ( (*l_attnIter).targetHndl->
                                  getAttr<ATTR_MODEL>() == MODEL_NIMBUS );

            // Iterate thru all chips in case PRD handled
            // a chip other than the first one.
            while(l_attnIter != attnList.end())
            {
                l_ecLevel = (*l_attnIter).targetHndl->getAttr<ATTR_EC>();


                if ( (RECOVERABLE == (*l_attnIter).attnType) &&
                     (true == l_isNimbus) && (l_ecLevel < 0x11)
                   )
                {
                    errlHndl_t l_scomErr = NULL;
                    uint64_t   l_clrAllBits = 0;

                    l_scomErr = putScom( (*l_attnIter).targetHndl,
                                         PIB_INTR_TYPE_REG,
                                         l_clrAllBits
                                       );

                    if (NULL != l_scomErr)
                    {
                        ATTN_ERR("Clear PibIntrReg failed, HUID:0X%08X",
                                  get_huid( (*l_attnIter).targetHndl) );
                        errlCommit(l_scomErr, ATTN_COMP_ID);
                    } // failed to clear PIB intr reg

                } // if recoverable attn

                ++l_attnIter;

            } // end while looping thru attn list

        } // end else NOT checkstop

    } // if attn list is not empty

    return err;
}

PrdWrapper & getPrdWrapper()
{
    // prd wrapper singleton access
    return Singleton<PrdWrapper>::instance();
}

PrdWrapper::PrdWrapper()
    : iv_impl(&Singleton<PrdImpl>::instance())
{
    // default call the real PRD
}

errlHndl_t PrdWrapper::callPrd(const AttentionList & i_attentions)
{
    // forward call to the installed PRD implementation.

    ATTN_DBG("call PRD with %d using: %p", i_attentions.size(), iv_impl);

    return iv_impl->callPrd(i_attentions);
}

ProcOps & getProcOps()
{
    return Singleton<ProcOps>::instance();
}

MemOps & getMemOps()
{
    return Singleton<MemOps>::instance();
}

int64_t Attention::compare(const Attention & i_rhs) const
{
    return ATTN::compare(iv_data, i_rhs.iv_data);
}

int64_t compare(const AttnData & i_l, const AttnData & i_r)
{
    if(i_l.attnType < i_r.attnType)
    {
        return -1;
    }

    if(i_r.attnType < i_l.attnType)
    {
        return 1;
    }

    if(i_l.targetHndl < i_r.targetHndl)
    {
        return -1;
    }

    if(i_r.targetHndl < i_l.targetHndl)
    {
        return 1;
    }

    return 0;
}
}
