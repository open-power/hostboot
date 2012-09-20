/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/util/UtilMapX.H $                           */
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

#ifndef __UTIL_UTILMAPX_H
#define __UTIL_UTILMAPX_H

#include "UtilTree.H"
#include <algorithm>

template <class _A, class _B>
class UtilMapX
{
    public:
        UtilMapX();
        UtilMapX(const UtilMapX<_A,_B> &);


        void insert(const _A &, const _B &);
        void insert(const std::pair<_A,_B> &);
        void remove(const _A &);
        bool find(const _A &);
        const std::pair<_A,_B>& peek();
        void empty() { cv_tree.empty(); };
        _B & operator[] (const _A &);

    private:
        UtilTree cv_tree;

        class mapXComparator : public UtilTree::comparator
        {
            public:
                virtual int operator() (void * _a, void * _b) const
                {
                    std::pair<_A,_B>* a;
                    std::pair<_A,_B>* b;

                    a = static_cast<std::pair<_A,_B>*>(_a);
                    b = static_cast<std::pair<_A,_B>*>(_b);

                    return (a->first < b->first ? -1 :
                                (a->first == b->first ? 0 : 1));
                };
        };

        class mapXCleanup : public UtilTree::cleanup
        {
            public:
                virtual void operator() (void * _a) const
                {
                    std::pair<_A,_B>* a = static_cast<std::pair<_A,_B>*>(_a);
                    delete a;
                };
        };

        class mapXCopier : public UtilTree::copier
        {
            public:
                virtual void * operator() (void * _a) const
                {
                    std::pair<_A,_B>* a = static_cast<std::pair<_A,_B>*>(_a);
                    return (void *) new std::pair<_A,_B>(*a);
                };
        };

        mapXComparator cv_compare;
        mapXCleanup cv_clean;
        mapXCopier cv_copy;

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
                std::pair<_A, _B> operator*()
                    {
                        std::pair<_A, _B> * a =
                            static_cast<std::pair<_A, _B> *>(*_pos);
                        if (NULL == a)
                            return std::pair<_A, _B>();
                        return *a;
                    };
        };
        iterator end() const { return iterator(cv_tree.end()); };
        iterator begin() const { return iterator(cv_tree.begin()); };

};

template <class _A, class _B>
UtilMapX<_A,_B>::UtilMapX()
{
    cv_tree.setComparator(&cv_compare);
    cv_tree.setCleanup(&cv_clean);
    cv_tree.setCopier(&cv_copy);
};

template <class _A, class _B>
UtilMapX<_A,_B>::UtilMapX(const UtilMapX<_A,_B> & i_copy)
{
    cv_tree = i_copy.cv_tree;
    cv_tree.setComparator(&cv_compare);
    cv_tree.setCleanup(&cv_clean);
    cv_tree.setCopier(&cv_copy);
};

template <class _A, class _B>
void UtilMapX<_A,_B>::insert(const _A & a, const _B & b)
{
    cv_tree.insert(new std::pair<_A,_B>(a,b));
};

template <class _A, class _B>
void UtilMapX<_A,_B>::insert(const std::pair<_A,_B> & i)
{
    cv_tree.insert(new std::pair<_A,_B>(i));
};

template <class _A, class _B>
void UtilMapX<_A,_B>::remove(const _A & a)
{
    std::pair<_A,_B> p(a,_B());
    cv_tree.remove(&p);
};

template <class _A, class _B>
bool UtilMapX<_A,_B>::find(const _A & a)
{
    std::pair<_A,_B> p(a,_B());
    return (NULL != cv_tree.find(&p));
};

template <class _A, class _B>
const std::pair<_A,_B> & UtilMapX<_A,_B>::peek()
{
    void * tmp = cv_tree.peek();
    if (NULL == tmp)
    {
        static const std::pair<_A,_B> l;
        return l;
    }
    return *static_cast<const std::pair<_A,_B> *>(tmp);
};

template <class _A, class _B>
_B & UtilMapX<_A, _B>::operator[] (const _A & a)
{
    std::pair<_A,_B> p(a,_B());
    std::pair<_A, _B> * l_node =
        static_cast<std::pair<_A, _B> *>(cv_tree.find(&p));

    if (NULL == l_node)
    {
        this->insert(p);
        l_node = static_cast<std::pair<_A, _B> *>(cv_tree.find(&p));
    }

    return l_node->second;
};

#endif

// Change Log *********************************************************
//
//  Flag Reason   Vers Date     Coder    Description
//  ---- -------- ---- -------- -------- -------------------------------
//       F494911  f310 03/04/05 iawillia Initial File Creation
//
// End Change Log *****************************************************
