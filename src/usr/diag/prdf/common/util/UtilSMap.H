/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/util/UtilSMap.H $                    */
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

/** @file UtilSMap.H
 *  An optimized implementation of the STL Map meant for small maps that do not
 *  need to be sorted.
 */

#ifndef __UTIL_UTILSMAP_H
#define __UTIL_UTILSMAP_H

#include <stddef.h>
#include <stdlib.h>

namespace PRDF
{

template <typename _First, typename _Second> class UtilSMap_Iterator;
template <typename _First, typename _Second> UtilSMap_Iterator<_First, _Second>
        operator+(UtilSMap_Iterator<_First,_Second>& l, size_t i);

template <typename _First, typename _Second>
class UtilSMap_Iterator
{
    protected:
        char * iv_position;
    public:
        UtilSMap_Iterator(char * i_position) : iv_position(i_position) {};

        bool operator==(const UtilSMap_Iterator & r)
                { return iv_position == r.iv_position; };

        bool operator!=(const UtilSMap_Iterator & r)
                { return iv_position != r.iv_position; };

        UtilSMap_Iterator<_First, _Second>& operator++();

        _First & first() { return *(_First *) iv_position; };
        _Second & second();

        friend UtilSMap_Iterator<_First, _Second>
            operator+<>(UtilSMap_Iterator<_First,_Second>& l,
                                      size_t i);
};

template <typename _First, typename _Second>
class UtilSMap
{
    public:
        typedef _First                                        key_type;
        typedef _Second                                        data_type;
        typedef size_t                                        size_type;
        typedef UtilSMap_Iterator<_First,_Second>        iterator;

    private:
        char * iv_memblock;
        size_type iv_size;
        size_type iv_blockCount;

    public:
        static const
            size_type cv_firstSize = 4 * (sizeof(_First) / 4 +
                                        (0 == (sizeof(_First) % 4) ? 0 :
                                            4 - (sizeof(_First) % 4)));
        static const
            size_type cv_secondSize = 4 * (sizeof(_Second) / 4 +
                                        (0 == (sizeof(_Second) % 4) ? 0 :
                                            4 - (sizeof(_Second) % 4)));

        static const
            size_type cv_blockSize = cv_firstSize + cv_secondSize;

    public:
        UtilSMap() : iv_memblock(NULL), iv_size(0), iv_blockCount(2) {};
        ~UtilSMap() { this->clear(); };

        inline size_type size() const { return iv_size;};
        inline bool empty() const { return 0 == iv_size;};
        inline iterator begin() const
            { return UtilSMap_Iterator<_First,_Second>(iv_memblock); };
        inline iterator end() const
            { return UtilSMap_Iterator<_First,_Second>(
                                &iv_memblock[iv_size * cv_blockSize]);
            };

        void clear()
            {
                if (NULL != iv_memblock) free(iv_memblock);
                iv_memblock = NULL;
                iv_size = 0;
                iv_blockCount = 2;
            };

        data_type * insert(const key_type & k, const data_type & v)
            {
                if (NULL == iv_memblock)
                {
                    iv_memblock = (char *) malloc(cv_blockSize * iv_blockCount);
                }
                if (iv_size == iv_blockCount)
                {
                    iv_blockCount <<= 1;
                    iv_memblock = (char *)
                            realloc(iv_memblock, cv_blockSize * iv_blockCount);
                }
                (*(key_type *)&iv_memblock[cv_blockSize * iv_size]) = k;
                data_type * l_rc = (data_type *)
                        &iv_memblock[cv_blockSize * iv_size + cv_firstSize];

                (*l_rc) = v;

                iv_size++;

                return l_rc;
            };
        data_type & operator[](const key_type & i)
            {
                data_type * l_rc = find(i);

                if (NULL == l_rc)
                    l_rc = insert(i, data_type());

                return *l_rc;
            };

    private:
        data_type * find(const key_type & k)
        {
            if (NULL == iv_memblock)
                return NULL;

            for (size_type i = 0; i < iv_size; i++)
                if ((*(key_type *)&iv_memblock[i * cv_blockSize]) == k)
                    return ((data_type *)
                            &iv_memblock[i * cv_blockSize + cv_firstSize]);

            return NULL;
        };
};

template <typename _First, typename _Second>
UtilSMap_Iterator<_First,_Second>&
    UtilSMap_Iterator<_First,_Second>::operator++()
        {
            iv_position =
                    &iv_position[UtilSMap<_First,_Second>::cv_blockSize];
            return *this;
        };
template <typename _First, typename _Second>
_Second& UtilSMap_Iterator<_First,_Second>::second()
        {
            return *(_Second *)
                        &iv_position[UtilSMap<_First, _Second>::cv_firstSize];
        };
template <typename _First, typename _Second>
UtilSMap_Iterator<_First,_Second>
    operator+(UtilSMap_Iterator<_First, _Second>& l, size_t i)
        {
            return UtilSMap_Iterator<_First,_Second>(&l.iv_position[
                                UtilSMap<_First,_Second>::cv_blockSize * i]);
        };

} // end namespace PRDF

#endif
