/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/util/UtilTree.H $                    */
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

#ifndef __UTIL_UTILTREE_H
#define __UTIL_UTILTREE_H

#include <stdint.h>
#include <stddef.h>

#include <functional>

#include <iostream>

namespace PRDF
{

namespace UtilTreeSTD
{
    template <class _A, class _B>
        class unary_operator : public std::unary_function<_A,_B>
        {
            public:
                virtual _B operator() (_A) const { return _B(); };
        };

    template <class _A, class _B, class _C>
        class binary_operator : public std::binary_function<_A,_B,_C>
        {
            public:
                virtual _C operator() (_A,_B) const { return _C(); };
        };
};

class UtilTree
{
    public:
        UtilTree();
        UtilTree(const UtilTree &);
        virtual ~UtilTree();

        void insert(void *);
        void remove(void *);
        void * find(void *) const;
        void * peek() const;
        void empty();

        // temp...
        void printTree();

        typedef UtilTreeSTD::binary_operator<void *, void *, int>
                    comparator;
        typedef UtilTreeSTD::unary_operator<void *, void>
                    cleanup;
        typedef UtilTreeSTD::unary_operator<void *, void *>
                    copier;

        void setComparator(comparator * i) { comp = i; };
        void setCleanup(cleanup * i) { clean = i; };
        void setCopier(copier * i) { copy = i; };

    protected:
        class defaultComparator : public comparator
        {
            public:
                virtual int operator()(void * _a, void * _b) const
                    {  return (_a < _b ? -1 : (_a == _b ? 0 : 1)); };
        };

        class defaultCleanup : public cleanup
        {
            public:
                virtual void operator()(void * _a) const { return; };
        };

        class defaultCopier : public copier
        {
            public:
                virtual void * operator()(void * _a) const { return _a; };
        };

        class Node;
        class Node
        {
            public:
                Node * left;
                Node * right;
                Node * parent;
                bool color; // false = black, true = red.
                static const bool BLACK = false;
                static const bool RED = true;
                void * value;

                // Null pointers, set to red.
                Node(void * v) :
                    left(NULL), right(NULL), parent(NULL), color(true),
                    value(v) {};
        };

        Node * root;
        comparator * comp;
        cleanup * clean;
        copier * copy;

    private:
        static defaultComparator defComparator;
        static defaultCleanup defCleanup;
        static defaultCopier defCopy;

        void cleanTree(Node *);
        Node * find(void *, Node *) const;
        void insert(void *, Node *&);
        void balance_i(Node *);

        void copyNode(Node *, Node * const, Node *);

        void printTree(int d, Node *t)
            {
                if (NULL == t) return;
                printTree(d+1, t->left);
                for (int i = 0; i < d; i++)
                    std::cout << "\t";
                std::cout << (t->color ? "R" : "B") << *(int *)t->value << std::endl;
                printTree(d+1, t->right);
            };

    public:
        class iterator
        {
            public:
                iterator() : _cur(NULL), _tree(NULL) {};
                iterator(const UtilTree * const t)
                        : _cur(NULL), _tree(t) {};
                iterator(Node * i, const UtilTree * const t)
                        : _cur(i), _tree(t) {};
                iterator & operator++();
                iterator & operator--();
                void * operator*() { return _cur->value; };

                bool operator==(const iterator& i) const
                        { return _cur == i._cur; };
                bool operator!=(const iterator& i) const
                        { return _cur != i._cur; };

                iterator & operator=(const iterator& i)
                        { _cur = i._cur; _tree = i._tree; return *this;};

            private:
                Node * _cur;
                const UtilTree * _tree;
        };

        iterator end() const { return iterator(this); };
        iterator begin() const;
};

} // end namespace PRDF

#endif

