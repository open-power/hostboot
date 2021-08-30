/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/util/impl/stlmap.H $                              */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2021                        */
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
#ifndef __UTIL_IMPL_STLMAP_H
#define __UTIL_IMPL_STLMAP_H

/** @file stlmap.H
 *  Implementation details of the std::map class.
 *
 *  See <map> (or your favorite STL reference) for documentation on most of
 *  the functions.
 *
 *  This class is implemented as a wrapper around a Splay-Tree found
 *  in util/impl/splaytree.H.
 */

#include <util/impl/splaytree.H>
#include <utility>
#include <util/traits/remove_const.H>
#include <algorithm>
#include <initializer_list>
#include <assert.h>


#ifndef __UTIL_SPLAYTREE_NS
#define __UTIL_SPLAYTREE_NS ::Util::__Util_SplayTree_Impl
#endif

namespace Util
{
    namespace __Util_StlMap_Impl
    {
        // Forward definition of the Map template class.
        template <typename Key, typename T, typename Compare> class Map;

        /** Template class to form a redirection from the Splay-Tree
         *  iterators and the required STL constructs.
         *
         *  The map iterators are bidirectional.
         */
        template <typename T, typename Itr>
        struct GenericIterator : protected Itr
        {
            // Standard typedefs.
            typedef T           value_type;
            typedef ptrdiff_t   difference_type;
            typedef T*          pointer;
            typedef T&          reference;
            typedef const T&    const_reference;

            // Allow Map and other GenericIterators to be friends.
            template <typename S, typename Itr2>
                    friend class GenericIterator;
            template <typename Key, typename S, typename Compare>
                    friend class Map;

            /** Default copy constructor */
            GenericIterator() : Itr() {};

            /** Copy Constructor
             *
             * Allows copy from any iterator type to another, but pointing to
             * the same node in the map.
             */
            template <typename Itr2>
            GenericIterator(const GenericIterator<T,Itr2>& r) :
                Itr((Itr2&) r) {}

            /** Prefix Increment */
            GenericIterator<T, Itr>& operator++()
            {
                Itr::increment();
                return *this;
            }
            /** Postfix Increment */
            GenericIterator<T, Itr> operator++(int)
            {
                GenericIterator<T, Itr> t = *this;
                Itr::increment();
                return t;
            }
            /** Prefix Decrement */
            GenericIterator<T, Itr>& operator--()
            {
                Itr::decrement();
                return *this;
            }
            /** Postfix Decrement */
            GenericIterator<T, Itr> operator--(int)
            {
                GenericIterator<T, Itr> t = *this;
                Itr::decrement();
                return t;
            }

            /** Dereference Operators */
            reference operator*()
            {
                return reinterpret_cast<__UTIL_SPLAYTREE_NS::Node<T>*>(
                            const_cast<__UTIL_SPLAYTREE_NS::Node<const void*>*>(
                                (Itr::getNode())))->data_T();
            }
            const_reference operator*() const
            {
                return reinterpret_cast<__UTIL_SPLAYTREE_NS::Node<T>*>(
                            const_cast<__UTIL_SPLAYTREE_NS::Node<const void*>*>(
                                (Itr::getNode())))->data_T();
            }
            /** Pointer Operator */
            pointer operator->()
            {
                return &reinterpret_cast<__UTIL_SPLAYTREE_NS::Node<T>*>(
                            const_cast<__UTIL_SPLAYTREE_NS::Node<const void*>*>(
                                (Itr::getNode())))->data_T();
            }
            pointer operator->() const
            {
                return &reinterpret_cast<__UTIL_SPLAYTREE_NS::Node<T>*>(
                            const_cast<__UTIL_SPLAYTREE_NS::Node<const void*>*>(
                                (Itr::getNode())))->data_T();
            }

            /** Equality Comparison operator */
            bool operator==(const GenericIterator<T,Itr>& r) const
            {
                return Itr::operator==(r);
            }
            /** Non-equality Comparison operator */
            bool operator!=(const GenericIterator<T,Itr>& r) const
            {
                return Itr::operator!=(r);
            }

            protected:
                /** Copy constructor from a SplayTree::Iterator.
                 *
                 *  This is protected because only the Map itself should be
                 *  doing this.
                 */
                GenericIterator(Itr r) : Itr(r) {};
        };

        /** Forward iterator version of GenericIterator. */
        template <typename T>
        struct Iterator :
            public GenericIterator<T, __UTIL_SPLAYTREE_NS::Iterator>

        {
            typedef GenericIterator<T, __UTIL_SPLAYTREE_NS::Iterator>
                        iterator;

            typedef typename iterator::value_type        value_type;
            typedef typename iterator::difference_type   difference_type;
            typedef typename iterator::pointer           pointer;
            typedef typename iterator::reference         reference;

            Iterator() : iterator() {};
            Iterator(iterator r) : iterator(r) {};

            template <typename Key, typename S, typename Compare>
                    friend class Map;

            protected:
                Iterator(__UTIL_SPLAYTREE_NS::Iterator r) :
                    iterator(r) {};

        };

        /** Constant Forward iterator version of GenericIterator */
        template <typename T>
        struct ConstIterator :
            public GenericIterator<T, __UTIL_SPLAYTREE_NS::ConstIterator>
        {
            typedef GenericIterator<T, __UTIL_SPLAYTREE_NS::ConstIterator>
                        iterator;

            typedef typename iterator::value_type        value_type;
            typedef typename iterator::difference_type   difference_type;
            typedef typename iterator::pointer           pointer;
            typedef typename iterator::reference         reference;

            ConstIterator() : iterator() {};
            ConstIterator(iterator r) : iterator(r) {};
            /** Copy constructor from a non-constant iterator */
            ConstIterator(const Iterator<T>& r) : iterator(r) {};

            template <typename Key, typename S, typename Compare>
                    friend class Map;

            protected:
                ConstIterator(__UTIL_SPLAYTREE_NS::ConstIterator r) :
                    iterator(r) {};
        };

        /** Reverse iterator version of GenericIterator */
        template <typename T>
        struct RIterator :
            public GenericIterator<T, __UTIL_SPLAYTREE_NS::RIterator>
        {
            typedef GenericIterator<T, __UTIL_SPLAYTREE_NS::RIterator>
                        iterator;

            typedef typename iterator::value_type        value_type;
            typedef typename iterator::difference_type   difference_type;
            typedef typename iterator::pointer           pointer;
            typedef typename iterator::reference         reference;

            RIterator() : iterator() {};
            RIterator(iterator r) : iterator(r) {};

            template <typename Key, typename S, typename Compare>
                    friend class Map;

            protected:
                RIterator(__UTIL_SPLAYTREE_NS::RIterator r) :
                    iterator(r) {};
        };

        /** Constant Reverse iterator version of GenericIterator */
        template <typename T>
        struct ConstRIterator :
            public GenericIterator<const T, __UTIL_SPLAYTREE_NS::ConstRIterator>
        {
            typedef GenericIterator<const T,
                                    __UTIL_SPLAYTREE_NS::ConstRIterator>
                        iterator;

            typedef typename iterator::value_type        value_type;
            typedef typename iterator::difference_type   difference_type;
            typedef typename iterator::pointer           pointer;
            typedef typename iterator::reference         reference;

            ConstRIterator() : iterator() {};
            ConstRIterator(iterator r) : iterator(r) {};
            /** Copy constructor from a non-constant iterator */
            ConstRIterator(const RIterator<T>& r) : iterator(r) {};

            template <typename Key, typename S, typename Compare>
                    friend class Map;

            protected:
                ConstRIterator(__UTIL_SPLAYTREE_NS::ConstRIterator r) :
                    iterator(r) {};
        };


        /** Template class to form a redirection from the Splay-Tree
         *  to required STL constructs for an std::map.
         */
        template <typename Key, typename T, typename Compare>
        class Map
        {
            public:
                // Standard STL types.
                typedef Key                             key_type;
                typedef T                               data_type;
                typedef std::pair<const Key, T>         value_type;
                typedef Compare                         key_compare;
                typedef T*                              pointer;
                typedef T&                              reference;
                typedef const T&                        const_reference;
                typedef size_t                          size_type;
                typedef ptrdiff_t                       difference_type;

                typedef Iterator<value_type>            iterator;
                typedef ConstIterator<value_type>       const_iterator;
                typedef RIterator<value_type>           reverse_iterator;
                typedef ConstRIterator<value_type>      const_reverse_iterator;

            protected:
                // Internal types for code read-ability.
                typedef Map<Key, T, Compare>                    _Self;
                typedef std::pair<Key, T>                       _value_type;
                typedef __UTIL_SPLAYTREE_NS::Node<_value_type>  _Node;
                typedef __UTIL_SPLAYTREE_NS::SplayTree          _Tree;
                typedef __UTIL_SPLAYTREE_NS::Iterator           _TreeItr;
                typedef __UTIL_SPLAYTREE_NS::ConstIterator      _TreeCItr;

                _Tree           iv_tree; //!< Storage container.
                key_compare     iv_comp; //!< Compare functor.

            public:
                /** Default Constructor
                 *
                 *  Takes the comparison function which is defaulted in
                 *  std::map.
                 */
                explicit Map(const key_compare& c) :
                        iv_tree(&_Self::comparator,
                                &_Self::copier,
                                &_Self::deleter),
                        iv_comp(c)
                    {};
                /** Copy constructor */
                Map(const Map<Key,T,Compare>& x) :
                    iv_tree(x.iv_tree), iv_comp(x.iv_comp) {};

                iterator begin()
                        { return iv_tree.begin(); }
                const_iterator begin() const
                        { return iv_tree.begin(); }

                iterator end()
                        { return iv_tree.end(); }
                const_iterator end() const
                        { return iv_tree.end(); }

                reverse_iterator rbegin()
                        { return iv_tree.rbegin(); }
                const_reverse_iterator rbegin() const
                        { return iv_tree.rbegin(); }

                reverse_iterator rend()
                        { return iv_tree.rend(); }
                const_reverse_iterator rend() const
                        { return iv_tree.rend(); }

                bool empty() const
                        { return iv_tree.empty(); }
                size_type size() const
                        { return iv_tree.size(); }

                T& operator[] (const key_type& k)
                {
                    std::pair<iterator,bool> result = insert(value_type(k,T()));
                    return (result.first)->second;
                }

                T& at(const key_type& k)
                {
                    auto result = lower_bound(k);
                    crit_assert(result != end());
                    return (*result).second;
                }

                const T& at(const key_type& k) const
                {
                    const auto result = lower_bound(k);
                    crit_assert(result != end());
                    return (*result).second;
                }

                template <class... Args>
                std::pair <iterator,bool> emplace ( Args&&... args )
                {
                    _Node *p = new _Node(std::forward<Args>(args)...);

                    _Tree::node * hint_node = nullptr;

                    bool rc = iv_tree.find_hint((_Tree::node*)p, hint_node);
                    if (!rc)
                    {
                        // node not found, so insert new one
                        iv_tree.insert((_Tree::node*)p);
                        return make_pair(iterator(_TreeItr(&iv_tree, (_Tree::node*)p)), true);
                    }
                    else
                    {
                        // node already exists, delete new one
                        delete p;
                        return make_pair(iterator(_TreeItr(&iv_tree, (_Tree::node*)hint_node)), false);
                    }
                }

                std::pair<iterator,bool> insert(const value_type& x)
                {
                    _Tree::node* n = NULL;

                    bool rc = iv_tree.insert_by_value(makeSplayTreeValue(x), n);

                    return make_pair(iterator(_TreeItr(&iv_tree, n)), rc);

                }

                void insert(std::initializer_list<value_type> list)
                {
                     insert(list.begin(), list.end());
                }

                iterator insert(iterator hint, const value_type& x)
                {
                    // I don't anticipate much performance improvement with
                    // the splay tree to add the extra code to honor the hint.
                    // To keep the code smaller, we're going to ignore it.

                    return insert(x).first;
                }

                void insert(iterator first,
                            iterator last)
                {
                    iv_tree.insert_range(first.getNode(), last.getNode());
                }

                void insert(const_iterator first,
                            const_iterator last)
                {
                    iv_tree.insert_range(first.getNode(), last.getNode());
                }

                template <typename InputIterator>
                void insert(InputIterator first, InputIterator last)
                {
                    while(first != last)
                    {
                        insert(*first);
                        ++first;
                    }
                }

                void erase(iterator position)
                {
                    iv_tree.remove(position.getNode());
                    delete reinterpret_cast<_Node*>(position.getNode());
                }

                size_type erase (const key_type& k)
                {
                    return iv_tree.remove_by_value(makeSplayTreeValue(k));
                }

                void erase(iterator first, iterator last)
                {
                    while(first != last)
                    {
                        erase(first++);
                    }
                }

                void swap(Map<Key, T, Compare>& r)
                {
                    iv_tree.swap(r.iv_tree);
                    std::swap(iv_comp, r.iv_comp);
                }

                void clear()
                        { iv_tree.clear(); }

                key_compare key_comp() const
                        { return iv_comp; }

                iterator find(const key_type& k)
                {

                    return iterator(
                        _TreeItr(&iv_tree,
                                 iv_tree.find_by_value(makeSplayTreeValue(k))
                        )
                    );
                }

                const_iterator find(const key_type& k) const
                {
                    return const_iterator(
                        _TreeCItr(&iv_tree,
                                 iv_tree.find_by_value(makeSplayTreeValue(k))
                        )
                    );
                }

                size_type count(const key_type& k) const
                {
                    _Tree::node* unused = NULL;

                    if (iv_tree.find_hint_by_value(makeSplayTreeValue(k),
                                                   unused))
                    {
                        return 1;
                    }
                    else
                    {
                        return 0;
                    }
                }

                iterator lower_bound(const key_type& k)
                {
                    return iterator(
                        _TreeItr(&iv_tree,
                                 iv_tree.lower_bound_by_value(
                                    makeSplayTreeValue(k)
                                 )
                        )
                    );
                }

                const_iterator lower_bound(const key_type& k) const
                {
                    return const_iterator(
                        _TreeCItr(&iv_tree,
                                 iv_tree.lower_bound_by_value(
                                    makeSplayTreeValue(k)
                                 )
                        )
                    );
                }

                iterator upper_bound(const key_type& k)
                {
                    return iterator(
                        _TreeItr(&iv_tree,
                                 iv_tree.lower_bound_by_value(
                                    makeSplayTreeValue(k)
                                 )
                        )
                    );
                }

                const_iterator upper_bound(const key_type& k) const
                {
                    return const_iterator(
                        _TreeCItr(&iv_tree,
                                 iv_tree.lower_bound_by_value(
                                    makeSplayTreeValue(k)
                                 )
                        )
                    );
                }

                std::pair<iterator,iterator>
                equal_range( const key_type& k)
                {
                    return make_pair(lower_bound(k),upper_bound(k));
                }

                std::pair<const_iterator, const_iterator>
                equal_range( const key_type& k) const
                {
                    return make_pair(lower_bound(k),upper_bound(k));
                }

            private:

                /**
                 * Utility function to convert a key to a SplayTree "value".
                 *
                 * This is safe assuming that the comparison function never
                 * uses anything outside of the key.  Since map's compare only
                 * based on the key, this is a valid assumption.
                 *
                 * The code is pretty messy here due to all the casting but
                 * what it does is:
                 *     (pair<key,value>*)(&k - (distance pair<key,value> to
                 *                              pair<key,value>.first))
                 *
                 * As in, it finds the pointer to the beginning key-value pair
                 * based on the address of just the key.
                 */
                const void** makeSplayTreeValue(const key_type& k) const
                {
                    typename Util::Traits::remove_const<key_type*>::type key =
                        const_cast<typename
                            Util::Traits::remove_const<key_type*>::type>(&k);

                    value_type* unused = NULL;
                    const size_t offset =
                            reinterpret_cast<const char*>(&unused->first) -
                            reinterpret_cast<const char*>(unused);

                    return reinterpret_cast<const void**>(
                            reinterpret_cast<char*>(key) - offset);
                }

                /**
                 * Utility function to convert a pair<key,value> into a
                 * SplayTree "value".
                 *
                 * This is a fairly straight-forward cast since no address
                 * translation is necessary.
                 */
                const void** makeSplayTreeValue(const value_type& x) const
                {
                    return reinterpret_cast<const void**>(
                                const_cast<value_type*>(&x));
                }

                /**
                 * Compare two key's using the map's compare function.
                 *
                 * @param[in] k1 - First key to compare.
                 * @param[in] k2 - Second key to compare.
                 *
                 * @return A strcmp-style integer (-1, 0, 1) with the
                 *         comparison results.
                 */
                int compare(const key_type& k1, const key_type& k2) const
                {
                    if (iv_comp(k1,k2))
                    {
                        return -1;
                    }
                    else if (iv_comp(k2,k1))
                    {
                        return 1;
                    }
                    else
                    {
                        return 0;
                    }
                }

                /**
                 * Functor to compare two SplayTree nodes using the comparison
                 * function for this tree.
                 *
                 * This will call this->compare(n1.key, n2,key) to get the
                 * result.
                 *
                 * @param[in] t - The address of the SplayTree (&iv_tree),
                 *                which can be used to find "this".
                 * @param[in] n1 - The first node to compare.
                 * @param[in] n2 - The second node to compare.
                 *
                 * @return See compare.
                 *
                 * This function involves some messy casting:
                 *    - The 't' is the address of this->iv_tree.  Using t,
                 *      this function must find "this", so that it can call
                 *      this->compare(...).
                 *
                 *    - The 'n1' and 'n2' parameters are SplayTree nodes,
                 *      which must be converted to our node types, and then
                 *      the keys are retrieved from the nodes to call the
                 *      comparison function.
                 *
                 */
                static int comparator(const _Tree* t,
                                      const _Tree::node* n1,
                                      const _Tree::node* n2)
                {
                    const _Self* unused = NULL;
                    const size_t offset =
                            reinterpret_cast<const char*>(&unused->iv_tree) -
                            reinterpret_cast<const char*>(unused);

                    return reinterpret_cast<const _Self*>(
                                reinterpret_cast<const char*>(t) - offset)->
                        compare(
                            reinterpret_cast<const _Node*>(n1)->data_T().first,
                            reinterpret_cast<const _Node*>(n2)->data_T().first);
                }

                /**
                 * Functor to copy a SplayTree node into a newly created node.
                 *
                 * This function must cast the SplayTree node into our node
                 * type, call the copy constructor, and then return a cast-back
                 * to SplayTree node.
                 *
                 * The result is similar to 'return new _Node(n)'.
                 *
                 * @param[in] n - The node to be copied.
                 *
                 * @return A pointer to a newly created node, being a copy of
                 *         the parameter 'n'.
                 */
                static _Tree::node* copier(const _Tree::node* n)
                {
                    return reinterpret_cast<_Tree::node*>(new _Node(
                                *reinterpret_cast<const _Node*>(n)));
                }

                /**
                 * Functor to delete a SplayTree node.
                 *
                 * This function must cast the SplayTree node into our node
                 * type and delete it.
                 *
                 * @param[in] n - The node to be deleted.
                 */
                static void deleter(_Tree::node* n)
                {
                    delete reinterpret_cast<_Node*>(n);
                }

        };


    };
};
#endif
