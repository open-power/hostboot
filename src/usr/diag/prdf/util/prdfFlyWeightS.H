/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/util/prdfFlyWeightS.H $                     */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2007,2012              */
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

#ifndef __PRDF_PRDFFLYWEIGHTS_H
#define __PRDF_PRDFFLYWEIGHTS_H

#include <stdint.h>
#include <vector>

template<class T, uint32_t S>
class FlyWeightS
{
    public:

        FlyWeightS() : iv_rowSize(2), iv_colSize(S), iv_nextPos(NULL),
                       iv_size(0)
                { iv_rows.reserve(iv_rowSize); iv_heaps.reserve(iv_rowSize); };

        ~FlyWeightS() { this->clear(); };

        void clear();

        T & get(const T & key);

        //void print();

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

#endif
