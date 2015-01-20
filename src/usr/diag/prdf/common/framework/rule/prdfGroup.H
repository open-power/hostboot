/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/framework/rule/prdfGroup.H $         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2015                        */
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

#ifndef __PRDFGROUP_H
#define __PRDFGROUP_H

#include <iipErrorRegisterType.h>
#include <iipResetErrorRegister.h>
#include <map>
#include <utility> // for pair

#include <vector>
#include <prdfFilters.H>

namespace PRDF
{

// forward decls
class Resolution;
class ResolutionMap;
class SCAN_COMM_REGISTER_CLASS;
class ErrorRegister;
// end forward decls

typedef std::pair<ResetAndMaskErrorRegister::ResetRegisterVector,
                       ResetAndMaskErrorRegister::ResetRegisterVector>
        ResetAndMaskPair;

/*class ResetAndMaskPair
    : public std::pair<ResetAndMaskErrorRegister::ResetRegisterVector,
                       ResetAndMaskErrorRegister::ResetRegisterVector>
    {};*/

class Group : public ErrorRegisterType
{
    public:
        Group(Resolution & i_default)
                    : cv_nextBitForTranspose(64), cv_defaultRes(i_default) {};

        ~Group();

        int32_t Analyze(STEP_CODE_DATA_STRUCT &);

        void Add(SCAN_COMM_REGISTER_CLASS *,
                 const uint8_t *,
                 size_t,
                 Resolution &,
                 ResetAndMaskPair &,
                 uint16_t, // SCRID.
                 bool
                 ); // add standard action.

        void Add(SCAN_COMM_REGISTER_CLASS * i_reg,
                 Resolution & i_action,
                 ResetAndMaskPair &,
                 uint16_t i_scrID); // add default action.
        /**
         * @brief adds filter to the group.
         * @param   i_filter      filter to be added to the group.
         * @param   i_addFirst    true, if filter should act ahead of filter(s)
         *                      added previously to the group, false otherwise.
         * @note    In most cases, we use original filter first. It ensures
         *          transpose filters acts first on FIR data. However, if
         *          secondary filter is defined for the group, it assumes
         *          highest priority and should be added before any other
         *          filter. It's because it should be the first filter acting on
         *          FIR data.
         */
        void AddFilter( FilterClass * i_filter, bool i_addFirst = false );

        /**
         * No Filters applied by this Error Register - so undo is no-op
         */
        virtual bool FilterUndo(BitKey & i_bit_list) { return false; }

    protected:
        const BIT_STRING_CLASS & Read(ATTENTION_TYPE i_attn);
        BIT_LIST_CLASS Filter(const BIT_STRING_CLASS &);
        int32_t Lookup(STEP_CODE_DATA_STRUCT &, BIT_LIST_CLASS &);
        int32_t Reset(const BIT_LIST_CLASS &, STEP_CODE_DATA_STRUCT &);

        typedef std::vector<ErrorRegister *> RegisterList_t;
        typedef std::vector<FilterClass *> FilterList_t;

        typedef std::map<SCAN_COMM_REGISTER_CLASS *, ResolutionMap *> ResMaps_t;
        ResMaps_t cv_resMaps;
        RegisterList_t cv_errRegs;
        FilterList_t cv_filters;
        uint8_t cv_nextBitForTranspose;
        Resolution & cv_defaultRes;

};

} // end of namespace PRDF

#endif

