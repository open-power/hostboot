/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/framework/rule/prdfGroup.H $         */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2004,2012              */
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

#ifndef __PRDFGROUP_H
#define __PRDFGROUP_H

#include <iipErrorRegisterType.h>
#include <iipResetErrorRegister.h>
#include <map>
#include <utility> // for pair

#include <vector>
#include <prdfFilters.H>

// forward decls
class Resolution;
class ResolutionMap;
class SCAN_COMM_REGISTER_CLASS;
class ErrorRegister;
// end forward decls

typedef std::pair<ResetAndMaskErrorRegister::ResetRegisterVector,
                       ResetAndMaskErrorRegister::ResetRegisterVector>
        PrdfResetAndMaskPair;

/*class PrdfResetAndMaskPair
    : public std::pair<ResetAndMaskErrorRegister::ResetRegisterVector,
                       ResetAndMaskErrorRegister::ResetRegisterVector>
    {};*/

class PrdfGroup : public ErrorRegisterType
{
    public:
        PrdfGroup(Resolution & i_default)
                    : cv_nextBitForTranspose(64), cv_defaultRes(i_default) {};

        ~PrdfGroup();

        int32_t Analyze(STEP_CODE_DATA_STRUCT &);

        void Add(SCAN_COMM_REGISTER_CLASS *,
                 const uint8_t *,
                 size_t,
                 Resolution &,
                 PrdfResetAndMaskPair &,
                 uint16_t, // SCRID.
                 bool
                 ); // add standard action.

        void Add(SCAN_COMM_REGISTER_CLASS * i_reg,
                 Resolution & i_action,
                 PrdfResetAndMaskPair &,
                 uint16_t i_scrID); // add default action.

        void AddFilter(prdfFilter * i_filter);

        /**
         * No Filters applied by this Error Register - so undo is no-op
         */
        virtual bool FilterUndo(prdfBitKey & i_bit_list) { return false; }

    protected:
        const BIT_STRING_CLASS & Read(ATTENTION_TYPE i_attn);
        BIT_LIST_CLASS Filter(const BIT_STRING_CLASS &);
        int32_t Lookup(STEP_CODE_DATA_STRUCT &, BIT_LIST_CLASS &);
        int32_t Reset(const BIT_LIST_CLASS &, STEP_CODE_DATA_STRUCT &);

        typedef std::vector<ErrorRegister *> RegisterList_t;
        typedef std::vector<prdfFilter *> FilterList_t;

        typedef std::map<SCAN_COMM_REGISTER_CLASS *, ResolutionMap *> ResMaps_t;
        ResMaps_t cv_resMaps;
        RegisterList_t cv_errRegs;
        FilterList_t cv_filters;
        uint8_t cv_nextBitForTranspose;
        Resolution & cv_defaultRes;

};


#endif

// Change Log *********************************************************
//
//  Flag Reason   Vers Date     Coder    Description
//  ---- -------- ---- -------- -------- -------------------------------
//       F494911  f310 03/04/05 iawillia Initial File Creation
//         F510901  f300 07/15/05 iawillia Add support for resets/masks.
//         D520844  f300 09/14/05 iawillia Add destructor to free memory.
//         D515833  f300 09/19/05 iawillia Use VMap instead of Map.
//         F544848  f300 04/03/06 iawillia Add multi-bit support.
//         F557408  f310 06/16/06 iawillia Add single-bit filter support.
// End Change Log *****************************************************
