/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/util/UtilSMap.H $                    */
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
        UtilSMap() : iv_memblock(nullptr), iv_size(0), iv_blockCount(2) {};
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
                if (nullptr != iv_memblock)
                {
                    for( size_type i = 0; i < iv_size; i++ )
                    {
                        ((key_type *)&iv_memblock[i])->~key_type();
                        ((data_type *)
                         &iv_memblock[i + cv_firstSize])->~data_type();
                    }
                    free(iv_memblock);
                }

                iv_memblock = nullptr;
                iv_size = 0;
                iv_blockCount = 2;
            };

        data_type * insert(const key_type & k, const data_type & v)
            {
                if (nullptr == iv_memblock)
                {
                    iv_memblock = (char *) malloc(cv_blockSize * iv_blockCount);
                }
                if (iv_size == iv_blockCount)
                {
                    iv_blockCount <<= 1;
                    iv_memblock = (char *)
                            realloc(iv_memblock, cv_blockSize * iv_blockCount);
                }

                new ((key_type *)&iv_memblock[cv_blockSize * iv_size])
                        (key_type) (k);

                data_type * l_rc = new ((data_type *)
                        &iv_memblock[cv_blockSize * iv_size + cv_firstSize])
                        (data_type) (v);

                iv_size++;

                return l_rc;
            };
        data_type & operator[](const key_type & i)
            {
                data_type * l_rc = find(i);

                if (nullptr == l_rc)
                    l_rc = insert(i, data_type());

                return *l_rc;
            };

         UtilSMap & operator = (const UtilSMap & i_rhs )
         {
            if( &i_rhs == this ) return *this;

            clear();
            iv_size = i_rhs.iv_size;
            iv_blockCount = i_rhs.iv_blockCount;

            if( nullptr != i_rhs.iv_memblock )
            {
                iv_memblock = (char *) malloc( cv_blockSize * iv_blockCount);
                for( size_type i = 0; i < iv_size; i++ )
                {
                    new ((key_type *)&iv_memblock[i])
                        (key_type)( i_rhs.iv_memblock[i] );

                    new ((data_type *) &iv_memblock[ i + cv_firstSize])
                        (data_type) (i_rhs.iv_memblock[ i + cv_firstSize]);
                }
            }
            return *this;
         };
         UtilSMap (const UtilSMap & i_rhs )
         {
            iv_size = i_rhs.iv_size;
            iv_blockCount = i_rhs.iv_blockCount;
            iv_memblock = nullptr;
            if( nullptr != i_rhs.iv_memblock )
            {
                iv_memblock = (char *) malloc( cv_blockSize * iv_blockCount);
                for( size_type i = 0; i < iv_size; i++ )
                {
                    new ((key_type *)&iv_memblock[i])
                        (key_type)( i_rhs.iv_memblock[i] );

                    new ((data_type *) &iv_memblock[ i + cv_firstSize])
                        (data_type) (i_rhs.iv_memblock[ i + cv_firstSize]);
                }
            }
         };

        data_type * find(const key_type & k)
        {
            if (nullptr == iv_memblock)
                return nullptr;

            for (size_type i = 0; i < iv_size; i++)
                if ((*(key_type *)&iv_memblock[i * cv_blockSize]) == k)
                    return ((data_type *)
                            &iv_memblock[i * cv_blockSize + cv_firstSize]);

            return nullptr;
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
