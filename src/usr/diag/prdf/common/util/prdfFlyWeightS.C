/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/util/prdfFlyWeightS.C $              */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2020                        */
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

#include <prdfFlyWeightS.H>
#include <algorithm>
#include <prdfHeapBucketSize.H>
#include <prdfTrace.H>
#include <prdfAssert.h>

namespace PRDF
{
//---------------------------------------------------------------------
// Member Function Specifications
//---------------------------------------------------------------------

template <typename T, uint32_t S>
void FlyWeightS<T,S>::clear()
{
    for (NeutralV::iterator i = iv_heaps.begin();
         i != iv_heaps.end();
         ++i)
    {
        delete [] static_cast<HeapType>(*i);
    }
    iv_heaps.clear();

    for (NeutralV::iterator i = iv_rows.begin();
         i != iv_rows.end();
         ++i)
    {
        delete static_cast<RowType*>(*i);
    }
    iv_rows.clear();

    iv_size = 0;
    iv_nextPos = nullptr;
    iv_rowSize = 2;
    iv_colSize = S;
}

template <typename T, uint32_t S>
T & FlyWeightS<T,S>::get(const T & key)
{
    HintType l_hint;
    T * l_val = find(key,l_hint);
    return (nullptr == l_val ? *insert(key,l_hint) : *l_val);
}

template <typename T, uint32_t S>
T * FlyWeightS<T,S>::find(const T & key, HintType & o_hint)
{
    T * l_rc = nullptr;

    // Check for empty case.
    if (nullptr == iv_nextPos)
    {
        return nullptr;
    }

    // Search rows for possible entry.
    NeutralV::iterator rowBegin = iv_rows.begin(),
                       rowEnd = iv_rows.end() - 1;

    while (rowBegin != rowEnd)
    {
        size_t l_d = std::distance(rowBegin, rowEnd);
        l_d /= 2;  l_d += 1; // now it is the mid-point.

        if (key >=
            *static_cast<T *>(*static_cast<RowType *>(rowBegin[l_d])->begin()))
        {
            rowBegin += l_d;
        }
        else
        {
            rowEnd = rowBegin;
            rowEnd += (l_d - 1);
        }
    }
    o_hint.row = rowEnd;

    // Search column for possible entry.
    NeutralV * l_row = static_cast<NeutralV*>(*o_hint.row);
    NeutralV::iterator colBegin = l_row->begin(),
                       colEnd = l_row->end() - 1;

    while (colBegin != colEnd)
    {
        size_t l_d = std::distance(colBegin, colEnd);
        l_d /= 2;  l_d += 1; // now it is the mid-point.

        if (key >=
            *static_cast<T *>(colBegin[l_d]))
        {
            colBegin += l_d;
        }
        else
        {
            colEnd = colBegin;
            colEnd += (l_d - 1);
        }
    }
    o_hint.col = colBegin;

    // Check if we found one.
    if (key == *static_cast<T *>(*o_hint.col))
        l_rc = static_cast<T *>(*o_hint.col);

    // Hint is now pointing to the cell either containing the key or
    // immediately preceding where this key would go... unless it is the
    // first item in the column.

    return l_rc;
};

template <typename T, uint32_t S>
T * FlyWeightS<T,S>::insert(const T & key, HintType & i_hint)
{
    // Check for new array.
    if (nullptr == iv_nextPos)
    {
        HeapType p = this->getHeap();
        (*p) = key;

        NeutralV::iterator l_row = iv_rows.begin();
        this->insertRow(l_row, p);

        return p;
    }

    // Otherwise, hint contains the position immediately preceding
    // where this key should go... unless it is the first item in the column.

    // Assign into heap, get pointer to position.
    HeapType p = this->getHeap();
    (*p) = key;

    // Check if current row has enough room.
    if (static_cast<NeutralV *>(*i_hint.row)->size() < iv_colSize)
    {
        if (*static_cast<T *>(*i_hint.col) < key)
            i_hint.col++;
        static_cast<NeutralV *>(*i_hint.row)->insert(i_hint.col, p);
    }
    else // not enough room.
    {
        T * l_nextElement = nullptr;
        // Should it go on next list?
        if (*static_cast<T *>(static_cast<NeutralV *>(*i_hint.row)->back())
                < key)
        {
            l_nextElement = p;
        }
        else
        {
            l_nextElement =
                static_cast<T *>(static_cast<NeutralV *>(*i_hint.row)->back());
            static_cast<NeutralV *>(*i_hint.row)->pop_back();

            if (*static_cast<T *>(*i_hint.col) < key)
                i_hint.col++;
            static_cast<NeutralV *>(*i_hint.row)->insert(i_hint.col, p);
        }

        i_hint.row++;
        if (i_hint.row == iv_rows.end())
            this->insertRow(i_hint.row, l_nextElement);
        else if (static_cast<NeutralV *>(*i_hint.row)->size() < iv_colSize)
            static_cast<NeutralV *>(*i_hint.row)->insert(
                static_cast<NeutralV *>(*i_hint.row)->begin(), l_nextElement);
        else
            this->insertRow(i_hint.row, l_nextElement);

    }

    return p;
};

template <typename T, uint32_t S>
T * FlyWeightS<T,S>::getHeap()
{
    iv_size++;

    if (nullptr == iv_nextPos)
    {
        iv_nextPos = new T[RoundBucketSize<T,S>::value];
        if( nullptr == iv_nextPos )
        {
            PRDF_ERR("Can not allocate memory on heap");
            PRDF_ASSERT( nullptr != iv_nextPos );
        }
        iv_heaps.push_back(iv_nextPos);
    }

    T * l_rc = iv_nextPos;

    iv_nextPos++;
    if ((static_cast<T*>(*(iv_heaps.end()-1)) + RoundBucketSize<T,S>::value) == iv_nextPos)
    {
        iv_nextPos = new T[RoundBucketSize<T,S>::value];
        if( nullptr == iv_nextPos )
        {
            PRDF_ERR("Can not allocate memory on heap");
            PRDF_ASSERT( nullptr != iv_nextPos );
        }
        iv_heaps.push_back(iv_nextPos);
    }

    return l_rc;
};

template <typename T, uint32_t S>
void FlyWeightS<T,S>::insertRow(FlyWeightS<T,S>::NeutralV::iterator & io_pos,
                                HeapType p)
{
    io_pos = iv_rows.insert(io_pos, new RowType);
    //static_cast<NeutralV *>(*io_pos)->reserve(iv_colSize);
    static_cast<NeutralV *>(*io_pos)->push_back(p);

    if (iv_rows.size() > iv_rowSize)
        this->increaseSize();
};

template <typename T, uint32_t S>
void FlyWeightS<T,S>::increaseSize()
{
    iv_rowSize *= 2;
    iv_colSize += S;

    // Resize columns.
    /*
    for (NeutralV::iterator i = iv_rows.begin();
         i != iv_rows.end();
         i++)
    {
        static_cast<NeutralV *>(*i)->reserve(iv_colSize);
    }*/

    // Merge columns.
    for (NeutralV::iterator i = iv_rows.begin();
         i != iv_rows.end();
         i++)
    {
        if (*i == nullptr)
            continue;

        bool l_merged = false;
        NeutralV::iterator i_next = i;

        do
        {
            l_merged = false;
            i_next++;

            while ( (iv_rows.end() != i_next) && (nullptr == *i_next) )
                    i_next++;

            if (i_next == iv_rows.end())
                continue;

            // If (I0 + I1 < previousCol), merge.
            if ((iv_colSize - S) >= (static_cast<NeutralV *>(*i)->size() +
                                     static_cast<NeutralV *>(*i_next)->size()))
            {
                static_cast<NeutralV *>(*i)->insert(
                    static_cast<NeutralV *>(*i)->end(),
                    static_cast<NeutralV *>(*i_next)->begin(),
                    static_cast<NeutralV *>(*i_next)->end());

                delete static_cast<NeutralV *>(*i_next);
                *i_next = nullptr;

                l_merged = true;
            }
        } while(l_merged);
    }

    iv_rows.erase(std::remove(iv_rows.begin(), iv_rows.end(), (void *) nullptr),
                  iv_rows.end());

};

#ifdef FLYWEIGHT_PROFILING

template < class T , uint32_t S >
void FlyWeightS<T,S>::printStats(void)
{
  PRDF_DTRAC( "no. of elements %d  Flyweight size %d",
            iv_heaps.size()*S,(iv_heaps.size() * sizeof(T) * S) );
}
#endif

/*
template <typename T, uint32_t S>
void FlyWeightS<T,S>::print()
{
    std::cout << "Size = " << iv_size << std::endl;
    for (NeutralV::iterator i = iv_rows.begin();
         i != iv_rows.end();
         i++)
    {
        for (NeutralV::iterator j = static_cast<NeutralV *>(*i)->begin();
             j != static_cast<NeutralV *>(*i)->end();
             j++)
        {
            std::cout << *static_cast<T *>(*j) << " ";
        }
        std::cout << std::endl;
    }

}
*/
} //End namespace PRDF
