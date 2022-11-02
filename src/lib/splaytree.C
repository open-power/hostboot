/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/lib/splaytree.C $                                         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2022                        */
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

#include <util/impl/splaytree.H>
#include <builtins.h>

/** @file splaytree.C
 *  Implementation of the Util::__Util_SplayTree_Impl::SplayTree class.
 */

namespace Util
{
    namespace __Util_SplayTree_Impl
    {

        SplayTree::SplayTree(SplayTree::comparator comp,
                             SplayTree::copier copy,
                             SplayTree::deleter del) :
            compare_functor(comp),
            copy_functor(copy),
            delete_functor(del)
        {
        }

        SplayTree::SplayTree(const SplayTree& t)
        {
            (*this) = t;
        }

        SplayTree::~SplayTree()
        {
            this->clear();
        }

        SplayTree& SplayTree::operator=(const SplayTree& t)
        {
            this->clear();

            compare_functor = t.compare_functor;
            copy_functor = t.copy_functor;
            delete_functor = t.delete_functor;

            insert_range(t.front(), NULL);
            if (likely(NULL != header.child[LEFT]))
            {
                splay(header.child[LEFT]);
            }

            return *this;
        }

        void SplayTree::insert(node* n)
        {
            if (unlikely(header.parent == NULL))  // First element.
            {
                header.parent = header.child[LEFT] = header.child[RIGHT] = n;
                n->parent = n->child[LEFT] = n->child[RIGHT] = NULL;
            }
            else // Not first element.
            {
                // Find place to insert node and insert it.
                node* insert_location = header.parent;
                __find(insert_location, n);
                __insert(insert_location, n);

                // Fix up header nodes.
                header.child[LEFT] = leftmost(header.child[LEFT]);
                header.child[RIGHT] = rightmost(header.child[RIGHT]);

                // Splay new node.
                splay(n);
            }

            // Increment size count.
            (header_n()->data)++;
        }

        void SplayTree::insert_range(const node* n1, const node* n2)
        {
            while(n1 != n2)
            {
                insert(copy_functor(n1));
                n1 = successor(n1);
            }
        }

        void SplayTree::remove(node* n)
        {
            // Fix up left-most and right-most node pointers if deleting
            // them.  We'll fix up the root in the node removal itself.
            if (unlikely(header.child[LEFT] == n))
            {
                header.child[LEFT] = successor(n);
            }
            if (unlikely(header.child[RIGHT] == n))
            {
                header.child[RIGHT] = predecessor(n);
            }

            // Decrement size count.
            (header_n()->data)--;

            // Find node to splice out of the tree.
            //    If n has one or no child, splice itself out, otherwise the
            //    successor.
            node* y = ((!n->child[LEFT]) || (!n->child[RIGHT])) ?
                            n : successor(n);

            // Find the subtree of y and link it with y's parent.
            node* x = y->child[LEFT] ? y->child[LEFT] : y->child[RIGHT];
            if (likely(NULL != x))
            {
                x->parent = y->parent;
            }
            if (unlikely(!y->parent))
            {
                // Fix root.
                header.parent = x;
            }
            else
            {
                y->parent->child[direction(y->parent, y)] = x;
            }

            // Replace n with y.
            if (likely(y != n))
            {
                y->parent = n->parent;
                if (y->parent)
                {
                    y->parent->child[direction(y->parent, n)] = y;
                }
                else
                {
                    // Removing root, so update header.
                    header.parent = y;
                }

                y->child[LEFT] = n->child[LEFT];
                if (y->child[LEFT])
                {
                    y->child[LEFT]->parent = y;
                }

                y->child[RIGHT] = n->child[RIGHT];
                if (y->child[RIGHT])
                {
                    y->child[RIGHT]->parent = y;
                }

                // Splay y up to the root.
                splay(y);
            }
        }

        bool SplayTree::find_hint(node* n, node*& hint) const
        {
            if (unlikely(NULL == header.parent))
            {
                return false;
            }

            hint = header.parent;

            bool found = __find(hint, n);

/*          DO NOT SPLAY HERE
 *          It increases the probability of hitting an
 *          issue when multi-threaded.
 *          @TODO JIRA PFHB-297 Temporary fix, while a more permanent
 *          fix is being developed.
 *
 *          Splay hint up the tree to make future searches quicker.
 *          if (likely(NULL != hint))
 *          {
 *             splay(hint);
 *          }
 */
            return found;
        }

        void SplayTree::clear()
        {
            node* n = front();
            while(n)
            {
                node* temp = n;
                n = successor(n);
                remove(temp);
                delete_functor(temp);
            }
        }

        void SplayTree::swap(SplayTree& tree)
        {
            node temp(header);
            header = tree.header;
            tree.header = temp;
        }

        bool SplayTree::insert_by_value(const void** v, node*& n)
        {
            n = find_by_value(v);

            if (unlikely(NULL != n))
            {
                return false;
            }
            else
            {
                n = copy_functor(node::convertToNode(v));
                insert(n);
                return true;
            }
        }

        size_t SplayTree::remove_by_value(const void** v)
        {
            if (unlikely(NULL == header.parent))
            {
                return 0;
            }

            node* v_node = header.parent;
            if (likely(__find(v_node, node::convertToNode(v))))
            {
                remove(v_node);
                delete_functor(v_node);
                return 1;
            }
            return 0;
        }

        bool SplayTree::find_hint_by_value(const void** v, node*& hint) const
        {
            return find_hint(node::convertToNode(v), hint);
        }

        SplayTree::node* SplayTree::find_by_value(const void** v) const
        {
            node* n = NULL;
            if (find_hint_by_value(v, n))
            {
                return n;
            }
            else
            {
                return NULL;
            }
        }

        SplayTree::node* SplayTree::lower_bound_by_value(const void** v) const
        {
            node* n = NULL;
            node* v_n = node::convertToNode(v);

            if (find_hint(v_n, n) || (NULL == n))
            {
                return n;
            }
            else
            {
                if (-1 == compare_functor(this, n, v_n))
                {
                    return successor(n);
                }
                else
                {
                    return n;
                }
            }
        }

        SplayTree::node* SplayTree::upper_bound_by_value(const void** v) const
        {
            node* n = NULL;
            node* v_n = node::convertToNode(v);

            if (find_hint(v_n, n))
            {
                return successor(n);
            }
            else if (NULL == n)
            {
                return NULL;
            }
            else
            {
                if (-1 == compare_functor(this, n, v_n))
                {
                    return successor(n);
                }
                else
                {
                    return n;
                }
            }
        }


        const SplayTree::node* SplayTree::predecessor(const node* n) const
        {
            // If left child, predecessor is just the largest of the left
            // subtree.
            if (likely(NULL != n->child[LEFT]))
            {
                return rightmost(n->child[LEFT]);
            }

            // Else, need to work up the tree to find predecessor.
            const node* y = n->parent;
            while ((NULL != y) && (n == y->child[LEFT]))
            {
                n = y;
                y = y->parent;
            }

            return y;
        }

        const SplayTree::node* SplayTree::successor(const node* n) const
        {
            // If right child, predecessor is just the smallest of the right
            // subtree.
            if (likely(NULL != n->child[RIGHT]))
            {
                return leftmost(n->child[RIGHT]);
            }

            // Else, need to work up the tree to find successor.
            const node* y = n->parent;
            while ((NULL != y) && (n == y->child[RIGHT]))
            {
                n = y;
                y = y->parent;
            }

            return y;
        }

        void SplayTree::rotate(node* n, DIRECTION d) const
        {
            // Get parent node.
            node* p = n->parent;

            // Link n's d-subtree into p.
            p->child[!d] = n->child[d];
            if (likely(NULL != n->child[d]))
            {
                n->child[d]->parent = p;
            }

            // Link p's parent to n.
            n->parent = p->parent;
            if (unlikely(!p->parent))
            {
                header.parent = n;
            }
            else
            {
                p->parent->child[direction(p->parent, p)] = n;
            }

            // Put p onto d-subtree of n.
            p->parent = n;
            n->child[d] = p;

        }

        void SplayTree::splay(node* n) const
        {
            // There are three splay operations.  "zig", "zig-zig" and
            // "zig-zag" based on the shape of the links between child, parent
            // and grand-parent.

            if (unlikely(!n->parent)) // This is the root node already.
            {
                return;
            }

            if (unlikely(!n->parent->parent)) // "zig" since no grand-parent.
            {
                // Rotate n into parent's location.
                rotate(n, !direction(n->parent, n));
            }
            else if (direction(n->parent, n) ==
                     direction(n->parent->parent, n->parent)) // "zig-zig"
            {
                // Rotate parent into grand-parent first, then rotate
                // n into parent.
                rotate(n->parent, !direction(n->parent->parent, n->parent));
                rotate(n, !direction(n->parent, n));

                // Continue splay.
                splay(n);
            }
            else // "zig-zag"
            {
                // Rotate n into parent, then n into grand-parent.
                rotate(n, !direction(n->parent, n));
                    // Note: grand-parent is now parent due to first rotate.
                rotate(n, !direction(n->parent, n));

                // Continue splay.
                splay(n);
            }
        }


        void SplayTree::__insert(node* t, node* n)
        {
            node*& child = (0 > (*compare_functor)(this, n, t)) ?
                                    t->child[LEFT] : t->child[RIGHT];

            if (likely(NULL == child)) // Assumption is the subtree hint is
                                       // correct, so this should be NULL.
            {
                // Link node into "child" slot.
                child = n;
                n->parent = t;
            }
            else
            {
                // Subtree hint was wrong, recurse tree.
                __insert(n, child);
            }
        }

        bool SplayTree::__find(node*& t, node* n) const
        {
            int compare = (*compare_functor)(this, n, t);

            if (unlikely(compare == 0)) // Node matches, return true.
            {
                return true;
            }

            node* child = (0 > compare) ? t->child[LEFT] : t->child[RIGHT];

            if (unlikely(NULL == child)) // No more children, no match.
            {
                return false;
            }
            else // Recurse to child.
            {
                t = child;
                return __find(t, n);
            }
        }

        void Iterator::increment()
        {
            if (NULL == node)
            {
                node = tree->front(); // This causes "begin() == ++end()" but
                                      // is necessary so that --rend() becomes
                                      // a reverse iterator to begin().
            }
            else
            {
                node = tree->successor(node);
            }
        };

        void Iterator::decrement()
        {
            if (NULL == node)
            {
                node = tree->back();
            }
            else
            {
                node = tree->predecessor(node);
            }
        }

        void ConstIterator::increment()
        {
            if (NULL == node)
            {
                node = tree->front(); // This causes "begin() == ++end()" but
                                      // is necessary so that --rend() becomes
                                      // a reverse iterator to begin().
            }
            else
            {
                node = tree->successor(node);
            }
        }

        void ConstIterator::decrement()
        {
            if (NULL == node)
            {
                node = tree->back();
            }
            else
            {
                node = tree->predecessor(node);
            }
        }


    };
};
