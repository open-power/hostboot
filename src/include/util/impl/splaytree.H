/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/util/impl/splaytree.H $                           */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2016                        */
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
#ifndef __UTIL_IMPL_SPLAYTREE_H
#define __UTIL_IMPL_SPLAYTREE_H

/** @file splaytree.H
 *
 *  Implementation of the Splay-Tree algorithm, which is to be used for
 *  containers such as STL map.  This tree could likely be reused for set,
 *  multiset, multimap, etc., but is not currently written with support
 *  for those data structures.
 *
 *  The Splay-Tree algorithm is a standard binary-search-tree with one
 *  additional operation: splay.  Splay is a special sequence of rotations
 *  that move a node up to the root of the tree.  Since Splay-Trees are
 *  not constantly balanced like AVL or Red-Black trees, the splay operation
 *  balances the tree, roughly.  Since splaying is done on operations like
 *  "find" it has the effect of speeding up access to frequently utilized
 *  data because frequently accessed nodes are moved up near the root of the
 *  tree.
 *
 *  The operations on a standard BST are found in many algorithms books.  I
 *  used "Introduction to Algorithms, 2nd Ed." by Cormen, Leiserson, Rivest,
 *  and Stein.  The additional splay operation was first described in a 1985
 *  paper by Sleator and Tarjan, but explanation of it is readily available
 *  online.
 *
 *  Additional reference: http://en.wikipedia.org/wiki/Splay_tree
 *
 *  Splay-Tree was chosen over AVL or Red-Black for two reasons:
 *      1) Simplicity of implementation.
 *            - Insert and delete are non-trivial on a balanced tree due to
 *              needing to maintain balance.
 *      2) Performance of expected typical cases.
 *            - This paper (http://benpfaff.org/papers/libavl.pdf) suggests
 *              that Splay-Trees tend to perform better for any non-random
 *              work load.
 */

#include <stdint.h>
#include <util/algorithm.H>
#include <functional>
#include <new>
#include <stdint.h>
#include <utility>

namespace Util
{
    namespace __Util_SplayTree_Impl
    {
        /** @class NodeTraits
         *  Defines typedefs and constants needed for all nodes.
         */
        struct NodeTraits
        {
            public:
                    /** Direction used for accessing the 'child' links */
                typedef uint8_t DIRECTION;

                static const DIRECTION LEFT = 0;
                static const DIRECTION RIGHT = 1;
        };

        /** @class Node
         *  Stores the content for a SplayTree Node.
         *
         *  This is implemented as a template so that the data storage area
         *  can be of different length (to store the template type).  The
         *  SplayTree assumes all nodes it is operating on can just store a
         *  void* and it is up to the using container to cast/interpret the
         *  data storage area differently if needed.
         */
        template <typename T>
        struct Node : public NodeTraits
        {
            /** Default constructor.
             *
             *  Initializes the node-links and data storage area.
             */
            Node()
            {
                parent = child[LEFT] = child[RIGHT] = NULL;

                new (&data) T();
            };

            /** Default destructor.
             *
             *  Call destructor on the child object.
             */
            ~Node()
            {
            }


            /** Variadic copy constructor from a Node.
             *
             *  Initializes the node-links and copies the data storage area
             *  from the copied nodes.
             *
             */
            template <typename... Args> explicit Node(Args&&... args)
            {
               parent = child[LEFT] = child[RIGHT] = NULL;
               new (&data) T(std::forward<Args>(args)...);
            }

            /** Copy constructor from a Node.
             *
             *  Initializes the node-links and copies the data storage area
             *  from the copied node.
             *
             *  non-const form - needed for variadic arguments form above
             */
            explicit Node(Node<T>&r)
            {
                // Don't want to copy the links out of the other node because
                // they're from a different tree.
                parent = child[LEFT] = child[RIGHT] = NULL;

                new (&data) T(r.data);
            };

            /** Copy constructor from a Node.
             *
             *  Initializes the node-links and copies the data storage area
             *  from the copied node.
             */
            explicit Node(const Node<T>&r)
            {
                // Don't want to copy the links out of the other node because
                // they're from a different tree.
                parent = child[LEFT] = child[RIGHT] = NULL;

                new (&data) T(r.data);
            };

            /** Copy constructor from a T.
             *
             *  Initializes the node-links and copies the data into the data
             *  storage area.
             */
            explicit Node(const T& v)
            {
                parent = child[LEFT] = child[RIGHT] = NULL;

                new (&data) T(v);
            };



            /** Access the data storage area as a T&. */
            T& data_T()
            {
                return data;
            };
            /** Access the data storage area as a const T&. */
            const T& data_T() const
            {
                return data;
            }

            // Allow the SplayTree to use our internals.
            friend class SplayTree;

            protected:
                /** Utility function to converts data-object to a Node.
                 *
                 *  This is safe assuming that the user of the Node does not
                 *  access anything outside of the data storage area.  This
                 *  is typically used in functions like "find" which need to
                 *  convert a pointer-to-data into a Node for searching the
                 *  tree.  Since the node-comparison functions only look at
                 *  the data storage area (ex. map key comparison), this is
                 *  a valid assumption.
                 *
                 *  The code here uses some messy casting to find the start
                 *  of a Node based on the address of its data storage area.
                 *  The optimizing compiler will turn this into a simple
                 *  pointer subtraction.
                 */
                static Node* convertToNode(T* data)
                {
                    Node<T>* unused = NULL;
                    const size_t offset =
                            reinterpret_cast<char*>(&unused->data) -
                            reinterpret_cast<char*>(unused);

                    return reinterpret_cast<Node*>(
                                reinterpret_cast<char*>(data) - offset);
                };

                /** Assignment operator
                 *  Default copy would work here but define to be explicit.
                 *
                 *  Only want to allow SplayTree to use this, because we're
                 *  going to copy pointers as well.
                 */
                Node& operator=(const Node<T>& r)
                {
                    parent = r.parent;
                    child[LEFT] = r.child[LEFT];
                    child[RIGHT] = r.child[RIGHT];

                    new (&data) T(r.data);

                    return *this;
                }


                // These members are mutable so that operations like find,
                // which are 'const' from an STL perspective, can still do
                // splays.  Since a splay does not change the content of the
                // container nor does it destroy any iterators, operations
                // that use it can still be considered "const" from the
                // perspective of an external caller.

                    /** Node-link to parent node. */
                mutable Node<T>* parent;
                    /** Node-link to children nodes. */
                mutable Node<T>* child[2];

                    /** Data storage area. */
                T data;
        };

            // Forward declaration of iterator types.
        class Iterator;
        class ConstIterator;
        class RIterator;
        class ConstRIterator;

        /** The SplayTree itself. */
        class SplayTree : public NodeTraits
        {
            public:
                    /** Typedef for our Node type, storing a void*. */
                typedef Node<const void*> node;
                    /** Functor typedef for comparing nodes. */
                typedef int(*comparator)(const SplayTree*,
                                         const node*,const node*);
                    /** Functor typedef for copying nodes. */
                typedef node*(*copier)(const node*);
                    /** Functor typedef for deleting nodes. */
                typedef void(*deleter)(node*);

                    /** Default constructor. */
                SplayTree(comparator comp, copier copy, deleter del);

                    /** Copy constructor.
                     *
                     *  This will copy the functor (addresses) from the copied
                     *  tree and duplicate all the contents of the tree.
                     */
                SplayTree(const SplayTree&);

                    /** Default destructor.
                     *
                     *  Calls the 'deleter' functor to clean up all the
                     *  contained nodes.
                     */
                ~SplayTree();

                    /** Assignment operator.
                     *
                     *  This has similar behavior as the copy-constructor.
                     *
                     *  This will copy the functor (addresses) from the copied
                     *  tree and duplicate all the contents of the tree.
                     */
                SplayTree& operator=(const SplayTree&);

                    /** Insert a node into the tree.
                     *
                     *  This function inserts a node into the correct location
                     *  in the tree.  This insert is done without ensuring that
                     *  the node doesn't already exist, so if the container
                     *  requires non-duplicate entries then some other
                     *  mechanism must be used to enforce this (ex. a find
                     *  first).
                     *
                     *  @param[in] n - The node to be inserted.
                     */
                void insert(node* n);

                    /** Insert a range of nodes into the tree.
                     *
                     *  This function iterates through all the nodes in the
                     *  range [n1, n2), copying and inserting every node in
                     *  the range.
                     *
                     *  @param[in] n1 - The beginning of the range.
                     *  @param[in] n2 - The end of the range.
                     */
                void insert_range(const node* n1, const node* n2);

                    /** Remove a node from the tree.
                     *
                     *  This function assumes that the node is, in fact, in
                     *  the tree.  Undefined behavior may occur if it is not.
                     *
                     *  @param[in] n - The node to be removed.
                     */
                void remove(node* n);

                    /** Find the likely location of a node in the tree.
                     *
                     *  Searches the tree for a node like 'n'.  If it is found
                     *  the similar node is saved in hint.  If not found, then
                     *  a node who's child would have been 'n' is saved in
                     *  hint.
                     *
                     *  @param[in] n - The node to search for.
                     *  @param[out] hint - The node closest to 'n' in the tree.
                     *
                     *  @retval true - if an exact match of 'n' was found.
                     *  @retval false - if an exact match of 'n' was not found.
                     */
                bool find_hint(node* n, node*& hint) const;


                    /** Erase all nodes in the tree and deletes them. */
                void clear();

                    /** Swap one tree with another. */
                void swap(SplayTree&);

                    /** Insert a node, with a specific value, into the tree.
                     *
                     *  Searches the tree for a node containing 'v'.  If the
                     *  node is found, it is returned as 'n'.  If the node is
                     *  not found, a new node is creating containing 'v'.
                     *
                     *  @param[in] v - The value to insert into the tree.
                     *  @param[out] n - The node created, or already having, v.
                     *
                     *  @retval true - A new node was created.
                     *  @retval false - An existing node with 'v' was found.
                     */
                bool insert_by_value(const void** v, node*& n);

                    /** Remove a node, with a specific value, from the tree.
                     *
                     *  Searches the tree for a node containing 'v' and
                     *  removes it if found.  The number of nodes removed is
                     *  returned (0 or 1).
                     *
                     *  @param[in] v - The value to remove from the tree.
                     *  @return The number of nodes removed.
                     */
                size_t remove_by_value(const void** v);

                    /** Find the likely location of a node containing a value
                     *  in the tree.
                     *
                     *  See 'find_hint'.
                     *
                     *  @param[in] v - The value to search for.
                     *  @param[out] hint - The node closest to 'v' in the tree.
                     *
                     *  @return See 'find_hint'.
                     */
                bool find_hint_by_value(const void** v, node*& hint) const;

                    /** Find node containing a value in the tree.
                     *
                     *  Searches the tree for a node containing 'v' and
                     *  returns it if found.
                     *
                     *  @param[in] v - The value to search for.
                     *
                     *  @return The node if found or NULL.
                     */
                node* find_by_value(const void** v) const;

                    /** Find the node in the tree lower-bounding a value.
                     *
                     *  See STL documentation for what "lower_bound" means.
                     *
                     *  @param[in] v - The value to lower-bound.
                     *
                     *  @return The node lower-bounding or NULL.
                     */
                node* lower_bound_by_value(const void** v) const;

                    /** Find the node in the tree upper-bounding a value.
                     *
                     *  See STL documentation for what "upper_bound" means.
                     *
                     *  @param[in] v - The value to upper-bound.
                     *
                     *  @return The node upper-bounding or NULL.
                     */
                node* upper_bound_by_value(const void** v) const;

                    /** Determine if the tree is empty. */
                bool empty() const
                    { return (header_n()->data == 0); };
                    /** Determine the size (in nodes) of the tree. */
                size_t size() const
                    { return (header_n()->data); };

                    /** Get a pointer to the first node (smallest by value). */
                node* front()
                    { return header.child[LEFT]; };
                    /** Get a pointer to the first node (smallest by value). */
                const node* front() const
                    { return header.child[LEFT]; };

                    /** Get a pointer to the last node (largest by value). */
                node* back()
                    { return header.child[RIGHT]; };
                    /** Get a pointer to the last node (largest by value). */
                const node* back() const
                    { return header.child[RIGHT]; };

                    /** Get the iterator to the beginning of the tree. */
                Iterator begin();
                    /** Get the iterator to the beginning of the tree. */
                ConstIterator begin() const;
                    /** Get the iterator past the end of the tree. */
                Iterator end();
                    /** Get the iterator past the end of the tree. */
                ConstIterator end() const;

                    /** Get the reverse iterator to the beginning. */
                RIterator rbegin();
                    /** Get the reverse iterator to the beginning. */
                ConstRIterator rbegin() const;
                    /** Get the reverse iterator past the end. */
                RIterator rend();
                    /** Get the reverse iterator past the end. */
                ConstRIterator rend() const;

                    // Allow the iterator classes to access our internal
                    // methods (successor / predecessor especially).
                friend class Iterator;
                friend class ConstIterator;
                friend class RIterator;
                friend class ConstRIterator;


            private:
                    /** Root of the tree.
                     *  Contains root of the tree and left-most / right-most
                     *  nodes.  Store size in data as a size_t with header_n().
                     */
                node header;

                    // Storage locations for the functors.
                comparator compare_functor;
                copier copy_functor;
                deleter delete_functor;

                    /** Utility function for mapping the Node<void*> to a
                     *  Node<size_t> for accessing tree size out of the
                     *  tree root-header. */
                Node<size_t>* header_n()
                        { return reinterpret_cast<Node<size_t>*>(&header); };
                    /** Utility function for mapping the Node<void*> to a
                     *  Node<size_t> for accessing tree size out of the
                     *  tree root-header. */
                const Node<size_t>* header_n() const
                        { return
                            reinterpret_cast<const Node<size_t>*>(&header); };

                    /** Iterate up to the top of a tree from a node. */
                node* topmost(node* n) const
                        { return n->parent ?
                                topmost(n->parent) : n; };
                    /** Iterate down to the left-most child of a subtree. */
                node* leftmost(node* n) const
                        { return n->child[LEFT] ?
                                leftmost(n->child[LEFT]) : n; };
                    /** Iterate down to the right-most child of a subtree. */
                node* rightmost(node* n) const
                        { return n->child[RIGHT] ?
                                rightmost(n->child[RIGHT]) : n; };

                    /** Determine the direction linking two nodes.
                     *
                     *  @param[in] p - The "parent" node of the link.
                     *  @param[in] c - The "child" node of a link.
                     *
                     *  @return The direction linking p -> c.
                     *  @retval LEFT - p->child[LEFT] == c
                     *  @retval RIGHT - p->child[LEFT] != c
                     */
                DIRECTION direction(node* p, node* c) const
                        { return (p->child[LEFT] == c) ? LEFT : RIGHT; };

                    /** Find the predecessor of a node within the tree.
                     *
                     *  This is the standard predecessor operation.
                     *
                     *  @return The predecessor or NULL if none exists.
                     */
                const node* predecessor(const node* n) const;
                    /** Find the successor of a node within the tree.
                     *
                     *  This is the standard successor operation.
                     *
                     *  @return The successor or NULL if none exists.
                     */
                const node* successor(const node* n) const;

                    /** Find the predecessor of a node within the tree. */
                node* predecessor(node* n) const
                        {
                            return const_cast<node*>(
                                        predecessor(
                                            const_cast<const node*>(n)));
                        };
                    /** Find the successor of a node within the tree. */
                node* successor(node* n) const
                        {
                            return const_cast<node*>(
                                        successor(
                                            const_cast<const node*>(n)));
                        };

                    /** Rotate a node "up" in a direction.
                     *
                     *  @param[in] n - The node to rotate.
                     *  @param[in] d - The direction to rotate.
                     *
                     *  If d is left, n->parent will become the left child of
                     *  n.  If d is right, n->parent will become the right
                     *  child of n.  The sub-trees of n and n->parent are
                     *  adjusted to make this a valid transformation.
                     */
                void rotate(node* n, DIRECTION d) const;

                    /** Splay a node to the root.
                     *
                     *  @param[in] n - The node to splay.
                     */
                void splay(node* n) const;

                    /** Perform an insert of a node onto a subtree.
                     *
                     *  @param[in] t - The subtree to insert the node onto.
                     *  @param[in] n - The node to insert.
                     *
                     *  This function assumes that t is an appropriate
                     *  place to insert n.  It adds n onto the left or right
                     *  child location in t, as appropriate by comparison.
                     */
                void __insert(node* t, node* n);
                    /** Perform a search of a node within a subtree.
                     *
                     *  @param[in,out] t - The subtree to find the node in.
                     *  @param[in] n - The node to find.
                     *
                     *  Searches the subtree for a node like 'n' or a node
                     *  where 'n' would belong as a direct child.  The subtree
                     *  is updated to be this node.  If an exact match is
                     *  found 'true' is returned.
                     *
                     *  @return bool of if an exact match of n is found.
                     */
                bool __find(node*& t, node* n) const;

        };

        /** Iterator class for SplayTree.
         *
         *  Acts as a STL iterator.
         */
        class Iterator
        {
            public:
                /** Default constructor. */
                Iterator(SplayTree* t = NULL,
                         SplayTree::node* n = NULL) :
                    tree(t), node(n) {};

                /** Increment the iterator (like ++iterator). */
                void increment();
                /** Decrement the iterator (like --iterator). */
                void decrement();

                /** Compare two iterators for equality. */
                bool operator==(const Iterator& r) const
                {
                    return (tree == r.tree) && (node == r.node);
                }
                /** Compare two iterators for non-equality. */
                bool operator!=(const Iterator& r) const
                {
                    return !((*this)==r);
                }

                friend class ConstIterator;

            protected:
                /** Get the node pointed to by this iterator. */
                SplayTree::node* getNode() const { return node; }

            private:
                SplayTree* tree;
                    // Typically node points to a node within the tree, but
                    // the value NULL is special and indicates the STL "end()".
                SplayTree::node* node;

            // Standard copy constructor / destructors may be used.
        };

        /** Iterator class for SplayTree.
         *
         *  Acts as a STL const_iterator.
         */
        class ConstIterator
        {
            public:
                /** Default constructor. */
                ConstIterator(const SplayTree* t = NULL,
                              const SplayTree::node* n = NULL) :
                    tree(t), node(n) {};
                /** Conversion constructor from Iterator. */
                ConstIterator(Iterator& r) :
                    tree(r.tree), node(r.node) {};

                /** Increment the iterator (like ++iterator). */
                void increment();
                /** Decrement the iterator (like --iterator). */
                void decrement();

                /** Compare two iterators for equality. */
                bool operator==(const ConstIterator& r) const
                {
                    return (tree == r.tree) && (node == r.node);
                }
                /** Compare two iterators for non-equality. */
                bool operator!=(const ConstIterator& r) const
                {
                    return !((*this)==r);
                }

                // We get comparison with Iterator for free due to
                // conversion constructor.

            protected:
                /** Get the node pointed to by this iterator. */
                const SplayTree::node* getNode() const { return node; }

            private:
                const SplayTree* tree;
                    // Typically node points to a node within the tree, but
                    // the value NULL is special and indicates the STL "end()".
                const SplayTree::node* node;

            // Standard copy constructor / destructors may be used.
        };

        /** Iterator class for SplayTree.
         *
         *  Acts as a STL reverse_iterator.
         *
         *  Same as iterator except with increment/decrement reversed.
         */
        class RIterator : public Iterator
        {
            public:
                RIterator(SplayTree* t = NULL,
                          SplayTree::node* n = NULL) :
                    Iterator(t, n) {};

                void increment() { Iterator::decrement(); };
                void decrement() { Iterator::increment(); };
        };

        /** Iterator class for SplayTree.
         *
         *  Acts as a STL const_reverse_iterator.
         *
         *  Same as const_iterator except with increment/decrement reversed.
         */
        class ConstRIterator : public ConstIterator
        {
            public:
                ConstRIterator(const SplayTree* t = NULL,
                               const SplayTree::node* n = NULL) :
                        ConstIterator(t, n) {};

                void increment() { ConstIterator::decrement(); };
                void decrement() { ConstIterator::increment(); };
        };

            // Inline implementations of iterator / const_iterator functions.
        inline Iterator SplayTree::begin()
            { return Iterator(this, front()); };
        inline ConstIterator SplayTree::begin() const
            { return ConstIterator(this, front()); };
        inline Iterator SplayTree::end()
            { return Iterator(this, NULL); };
        inline ConstIterator SplayTree::end() const
            { return ConstIterator(this, NULL); };

            // Inline implementations of reverse iterator / const_iterator fns.
        inline RIterator SplayTree::rbegin()
            { return RIterator(this, back()); };
        inline ConstRIterator SplayTree::rbegin() const
            { return ConstRIterator(this, back()); };
        inline RIterator SplayTree::rend()
            { return RIterator(this, NULL); };
        inline ConstRIterator SplayTree::rend() const
            { return ConstRIterator(this, NULL); };



    };
};

#endif
