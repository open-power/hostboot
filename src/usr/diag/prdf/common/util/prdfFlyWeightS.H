/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/util/prdfFlyWeightS.H $              */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2007,2020                        */
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

#ifndef __PRDF_PRDFFLYWEIGHTS_H
#define __PRDF_PRDFFLYWEIGHTS_H

#include <stdint.h>
#include <vector>
#include <prdfGlobal.H>

namespace PRDF
{
template<class T, uint32_t S>
class FlyWeightS
{
    public:

        FlyWeightS() : iv_rowSize(2), iv_colSize(S), iv_nextPos(nullptr),
                       iv_size(0)
                { iv_rows.reserve(iv_rowSize); iv_heaps.reserve(iv_rowSize); };

        ~FlyWeightS() { this->clear(); };

        void clear();

        T & get(const T & key);

        //void print();
#ifdef FLYWEIGHT_PROFILING
        /**
         * @brief   prints the memory occupied by objects in flyweight.
         */

        void printStats();

#endif

    private:

        typedef std::vector<void *> NeutralV;
        typedef std::vector<void *> RowType;
        typedef T* ColType;
        typedef T* HeapType;

        typedef struct { NeutralV::iterator row; NeutralV::iterator col;}
                HintType;

        size_t iv_rowSize;
        size_t iv_colSize;
        NeutralV iv_rows;
        NeutralV iv_heaps;
        HeapType iv_nextPos;

        size_t iv_size;

    private:

        T * find(const T & key, HintType & o_hint);
        T * insert(const T & key, HintType & i_hint);
        T * getHeap();
        void insertRow(NeutralV::iterator & io_pos, HeapType p);

        void increaseSize();
};
} //End namespace PRDF
#endif
