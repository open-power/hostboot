/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/rule/prdfGroup.C $                   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2020                        */
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

#include <prdfGroup.H>

#include <algorithm>

#include <iipResetErrorRegister.h>
#include <iipServiceDataCollector.h>
#include <prdfBitString.H>
#include <prdfMain.H>
#include <prdfResolutionMap.H>

namespace PRDF
{

Group::~Group()
{
    RegisterList_t::const_iterator l_errRegsEnd = cv_errRegs.end();
    for (RegisterList_t::const_iterator i = cv_errRegs.begin();
         i != l_errRegsEnd;
         ++i)
    {
        delete *i;
    }

    ResMaps_t::const_iterator l_resMapsEnd = cv_resMaps.end();
    for (ResMaps_t::const_iterator i = cv_resMaps.begin();
         i != l_resMapsEnd;
         ++i)
    {
        delete (ResolutionMap *)(*i).second;
    }

    // Delete filters.
    FilterList_t::const_iterator l_filterEnd = cv_filters.end();
    for (FilterList_t::const_iterator i = cv_filters.begin();
         i != l_filterEnd;
         ++i)
    {
        delete (*i);
    }
}

int32_t Group::Analyze(STEP_CODE_DATA_STRUCT & i_step)
{
    int32_t l_rc = -1;
    ServiceDataCollector l_backupStep(*i_step.service_data);
    int32_t l_tmpRC = SUCCESS;

    RegisterList_t::const_iterator l_errRegsEnd = cv_errRegs.end();
    for (RegisterList_t::const_iterator i = cv_errRegs.begin();
         (i != l_errRegsEnd) && (l_rc != SUCCESS);
         ++i)
    {
        bool l_secErr = i_step.service_data->isSecondaryErrFound();
        (*i_step.service_data) = l_backupStep;

        if( l_secErr )
        {
           i_step.service_data->setSecondaryErrFlag();
        }

        l_tmpRC = (*i)->Analyze(i_step);

        if (PRD_SCAN_COMM_REGISTER_ZERO != l_tmpRC)
        {
            l_rc = l_tmpRC;
        }
    }
    if ( PRD_SCAN_COMM_REGISTER_ZERO == l_tmpRC )
    {
        l_rc = l_tmpRC;
    }

    if (0 == cv_errRegs.size())
        l_rc = cv_defaultRes.Resolve(i_step);

    return l_rc;
};

void Group::Add(SCAN_COMM_REGISTER_CLASS * i_reg,
                    const uint8_t * i_bits,
                    size_t i_bitSize,
                    Resolution & i_action,
                    ResetAndMaskPair & i_resets,
                    uint16_t i_scrID,
                    bool i_reqTranspose)
{
    FilterClass * l_transposeFilter = nullptr;
    uint8_t l_bits[1] = { '\0' };
    ResolutionMap * l_res = cv_resMaps[i_reg];

    if (nullptr == l_res)
    {
        l_res = cv_resMaps[i_reg] = new ResolutionMap(1, cv_defaultRes);
        ResetAndMaskErrorRegister * l_errReg =
                new ResetAndMaskErrorRegister(*i_reg, *l_res, i_scrID);
        cv_errRegs.push_back(l_errReg);

        // Sort reset and mask lists.
        std::sort(i_resets.first.begin(), i_resets.first.end());
        std::sort(i_resets.second.begin(), i_resets.second.end());

        // Remove duplicate resets and masks.
        i_resets.first.erase(
                std::unique(i_resets.first.begin(), i_resets.first.end()),
                i_resets.first.end());
        i_resets.second.erase(
                std::unique(i_resets.second.begin(), i_resets.second.end()),
                i_resets.second.end());

        // Add resets.
        std::for_each(i_resets.first.begin(), i_resets.first.end(),
                      std::bind1st(
                          std::mem_fun(&ResetAndMaskErrorRegister::addReset),
                          l_errReg)
                      );

        // Add masks.
        std::for_each(i_resets.second.begin(), i_resets.second.end(),
                      std::bind1st(
                          std::mem_fun(&ResetAndMaskErrorRegister::addMask),
                          l_errReg)
                      );
    }

    // This action requires a transpose filter (multiple bits &'d)
    if (i_reqTranspose)
    {
        // Create key and transposition filter.  Add to filter list.
        BitKey l_tmpKey(i_bits, i_bitSize);
        l_transposeFilter = new FilterTranspose(l_tmpKey,
                                                    cv_nextBitForTranspose);
        cv_filters.push_back(l_transposeFilter);

        // Update bit string pointers/values.
        l_bits[0] = cv_nextBitForTranspose++;
        i_bits = l_bits;
        i_bitSize = 1;

        // Check for existing transposition filter, create link as needed.
        if (nullptr != l_res->getFilter())
        {
            l_transposeFilter = new FilterLink(*l_res->getFilter(),
                                               *l_transposeFilter);  // pw01
            cv_filters.push_back(l_transposeFilter);
        }

        // Assign transpose filter.
        l_res->setFilter(l_transposeFilter);
    }

    // Add action to resolution.
    l_res->Add(i_bits, i_bitSize, &i_action);
};

void Group::Add(SCAN_COMM_REGISTER_CLASS * i_reg,
                    Resolution & i_action,
                    ResetAndMaskPair & i_resets,
                    uint16_t i_scrID)
{
    ResolutionMap * l_res = cv_resMaps[i_reg];

    if (nullptr == l_res)
    {
        l_res = cv_resMaps[i_reg] = new ResolutionMap(1, cv_defaultRes);
        ResetAndMaskErrorRegister * l_errReg =
                new ResetAndMaskErrorRegister(*i_reg, *l_res, i_scrID);
        cv_errRegs.push_back(l_errReg);

        // Sort reset and mask lists.
        std::sort(i_resets.first.begin(), i_resets.first.end());
        std::sort(i_resets.second.begin(), i_resets.second.end());

        // Remove duplicate resets and masks.
        i_resets.first.erase(
                std::unique(i_resets.first.begin(), i_resets.first.end()),
                i_resets.first.end());
        i_resets.second.erase(
                std::unique(i_resets.second.begin(), i_resets.second.end()),
                i_resets.second.end());

        // Add resets.
        std::for_each(i_resets.first.begin(), i_resets.first.end(),
                      std::bind1st(
                          std::mem_fun(&ResetAndMaskErrorRegister::addReset),
                          l_errReg)
                      );

        // Add masks.
        std::for_each(i_resets.second.begin(), i_resets.second.end(),
                      std::bind1st(
                          std::mem_fun(&ResetAndMaskErrorRegister::addMask),
                          l_errReg)
                      );
    }

    l_res->ReplaceDefaultWith(i_action);

};

void Group::AddFilter(FilterClass * i_filter, bool i_addFirst )
{
    // Add to filter list, for deallocation later.
    cv_filters.push_back(i_filter);

    // Iterate through all resolution maps.
    for(ResMaps_t::const_iterator i = cv_resMaps.begin();
        i != cv_resMaps.end();
        i++)
    {
        // Get old filter.
        FilterClass * l_bitFilter =
                ((ResolutionMap *)(*i).second)->getFilter();

        // Need new filter link?
        if (nullptr != l_bitFilter)
        {
            if( i_addFirst )
            {
                l_bitFilter = new FilterLink( *i_filter, *l_bitFilter );
            }
            else
            {
                l_bitFilter = new FilterLink( *l_bitFilter, *i_filter );
            }

            // Add to filter list, for deallocation later.
            cv_filters.push_back(l_bitFilter);
        }
        else
        {
            l_bitFilter = i_filter;
        }

        // Assign filter to resolution map.
        ((ResolutionMap *)(*i).second)->setFilter(l_bitFilter);
    }
}



const BitString & Group::Read(ATTENTION_TYPE i_attn)
{
    static BitStringBuffer a(64);
    return a;
};

BIT_LIST_CLASS Group::Filter(const BitString & i)
{
    return BIT_LIST_CLASS();
};

int32_t Group::Lookup(STEP_CODE_DATA_STRUCT & i_step, BIT_LIST_CLASS & b)
{
    return -1;
};

int32_t Group::Reset(const BIT_LIST_CLASS & b, STEP_CODE_DATA_STRUCT & i_step)
{
    return -1;
};

} // end namespace PRDF

