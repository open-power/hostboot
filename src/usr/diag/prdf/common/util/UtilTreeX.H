/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/util/UtilTreeX.H $                   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2004,2014              */
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

#ifndef __UTIL_UTILTREEX_H
#define __UTIL_UTILTREEX_H

#include "UtilTree.H"

namespace PRDF
{

template <class _T>
class UtilTreeX
{
    public:
        UtilTreeX();
        UtilTreeX(const UtilTreeX<_T> &);

        void insert(_T &);
        void remove(_T &);
        bool find(_T &);
        const _T & peek();
        void empty() { cv_tree.empty(); };

        void printTree()
            {
                cv_tree.printTree();
            };

    private:
        UtilTree cv_tree;

        class treeXComparator : public UtilTree::comparator
        {
            public:
                virtual int operator() (void * _a, void * _b) const
                    {
                        _T * a;
                        _T * b;

                        a = static_cast<_T *>(_a);
                        b = static_cast<_T *>(_b);

                        return (*a < *b ? -1 : (*a == *b ? 0 : 1));
                    }
        };

        class treeXCleanup : public UtilTree::cleanup
        {
            public:
                virtual void operator() (void * _a) const
                    {
                        _T * a = static_cast<_T *>(_a);
                        delete a;
                    };
        };

        class treeXCopier : public UtilTree::copier
        {
            public:
                virtual void * operator() (void * _a) const
                {
                    _T * a = static_cast<_T *>(_a);
                    return (void *) new _T(*a);
                };
        };

        treeXComparator cv_compare;
        treeXCleanup cv_clean;
        treeXCopier cv_copy;

    public:
        class iterator
        {
            private:
                UtilTree::iterator _pos;
            public:
                iterator(UtilTree::iterator i) { _pos = i; };
                iterator & operator++()
                    { ++_pos; return *this; };
                iterator & operator--()
                    { --_pos; return *this; };
                bool operator==(const iterator& i) const
                    { return _pos == i._pos; };
                bool operator!=(const iterator& i) const
                    { return _pos != i._pos; };
                _T operator*()
                    {
                        _T * a = static_cast<_T *>(*_pos);
                        if (NULL == a)
                            return _T();
                        return *a;
                    };
        };
        iterator end() const { return iterator(cv_tree.end()); };
        iterator begin() const { return iterator(cv_tree.begin()); };
};

template <class _T>
UtilTreeX<_T>::UtilTreeX()
{
    cv_tree.setComparator(&cv_compare);
    cv_tree.setCleanup(&cv_clean);
    cv_tree.setCopier(&cv_copy);
};

template <class _T>
UtilTreeX<_T>::UtilTreeX(const UtilTreeX<_T> & i_copy)
{
    cv_tree = i_copy.cv_tree;
    cv_tree.setComparator(&cv_compare);
    cv_tree.setCleanup(&cv_clean);
    cv_tree.setCopier(&cv_copy);
};


template <class _T>
void UtilTreeX<_T>::insert(_T & i)
{
    cv_tree.insert((void *)new _T(i));
};

template <class _T>
void UtilTreeX<_T>::remove(_T & i)
{
    cv_tree.remove((void *)&i);
};

template <class _T>
bool UtilTreeX<_T>::find(_T & i)
{
    return (NULL != cv_tree.find((void *)&i));
};

template <class _T>
const _T & UtilTreeX<_T>::peek()
{
    static const _T l = _T();
    void * tmp = cv_tree.peek();
    if (NULL == tmp)
        return l;
    return *static_cast<const _T *>(tmp);
};

} // end namespace PRDF

#endif

