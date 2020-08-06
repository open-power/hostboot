/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/util/impl/unique_ptr.H $                          */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2020                        */
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
#ifndef __UTIL_IMPL_UNIQUE_PTR_H
#define __UTIL_IMPL_UNIQUE_PTR_H

/**
 *
 * @file unique_ptr.H
 *
 * @brief Provides an implementation of the C++ standard library unique_ptr
 * template class.
 *
 */

#include <cstddef>
#include <utility>
#include <stdint.h>

namespace std
{
    /* According to the standard, the typedef "pointer" of a unique_ptr<T, Del>
     * is the type std::remove_reference<Del>::type::pointer if it exists, or
     * else T*. These functions are to accomplish that.
     *
     * This unique_ptr_pointer_type_helper is an overloaded function with two
     * alternatives: One has a return type of Deleter::pointer, and the other
     * has a return type of T*. The former will be eliminated from the overload
     * set by SFINAE ("[template] Substitution Failure Is Not An Error") if the
     * name Deleter::pointer is malformed, and so the expression
     * unique_ptr_pointer_type_helper(0) will have a return type of T*. If it is
     * not malformed, then the expression will have a return type of
     * Deleter::pointer (the call is not ambiguous because variadic functions
     * take lower precedence in overload resolution). So we take the decltype of
     * that expression to determine what type the "pointer" typedef should be.
     */
    template<typename T, typename Deleter>
    typename std::remove_reference<Deleter>::type::pointer __unique_ptr_pointer_type_helper(int);

    template<typename T, typename Deleter>
    T* __unique_ptr_pointer_type_helper(...);

    template<typename T, typename Deleter>
    struct unique_ptr_pointer_type
    {
        using type = decltype(__unique_ptr_pointer_type_helper<T, Deleter>(0));
    };

    template<typename T, typename Deleter>
    struct unique_ptr_pointer_type<T[], Deleter>
    {
        using type = T*;
    };

    template <typename T>
    struct default_delete
    {
        /* The default_delete struct has no instance data members, so it can be
         * used as a base class of unique_ptr<T, default_delete<T>> to trigger
         * Empty Base class Optimization and avoid wasting space. See the
         * comment below on __unique_ptr_funcptr_base for more info.
         */

        default_delete() = default;

        void operator()(T* ptr) const
            { delete(ptr);}

        template <typename U> void operator()(U* ptr) const
            { delete(ptr);}
    };

    template <typename T>
    struct default_delete<T[]>
    {
        using pointer = T*;

        default_delete() = default;

        void operator()(T* ptr) const
            { delete[](ptr);}

        template <typename U> void operator()(U* ptr) const
            { delete[](ptr);}
    };

    /* These __unique_ptr_funcptr_base and __unique_ptr_base_selector classes
     * are to help us decide the base class of unique_ptr<T>.
     *
     * Background:
     *
     * A straightforward implementation of unique_ptr would have two members:
     * one for the resource pointer, and one for the deleter. The size of
     * unique_ptr<T, Del> would be sizeof(T*) + sizeof(Del) + padding. Even if
     * Del is a class with no data members (i.e. it contains only member
     * functions, typedefs, etc. which take up no space per-instance;
     * std::default_delete is an example of such a class), its size is at least
     * 1 byte according to the standard, so unique_ptr instances would end up
     * being larger than a raw pointer, and we would like to avoid that waste of
     * space.
     *
     * Solution:
     *
     * To solve this, there is an optimization known as the "Empty Base class
     * Optimization" (EBO) which allows an empty class E, which would normally
     * be 1 byte large (not including added padding), to take up no space in an
     * instance of class T if E is used as a base class of T. Therefore, we
     * could save space by making unique_ptr<T, Del> inherit from Del. However,
     * the Del type is not required to be a class; it could be a function
     * pointer as well, which we can't inherit from.
     *
     * To handle the latter case, we create a class called
     * __unique_ptr_funcptr_base, which will be the base class of unique_ptr<T,
     * Del> if Del is a function pointer. __unique_ptr_funcptr_base just stores
     * a copy of the pointer to the function and invokes it whenever its
     * function-call operator is called.
     *
     * The __unique_ptr_base_selector class chooses between the class Deleter
     * and the class __unique_ptr_funcptr_base for the base class by
     * pattern-matching (see comments on the classes below).
     */

    template<typename T>
    struct __unique_ptr_funcptr_base
    {
        T deleter_function { };

    protected:

        __unique_ptr_funcptr_base() = default;
        __unique_ptr_funcptr_base(T t) : deleter_function(std::move(t)) { }

        template<typename K>
        void operator()(K value) const
        {
            if (value)
            {
                deleter_function(value);
            }
        }

        /* This cast operator is used by the get_deleter() function of
         * unique_ptr when the latter tries to cast itself into a Deleter.
         */
        explicit operator T&() { return deleter_function; }
    };

    // __unique_ptr_base_selector<Deleter> will alias its "type" to Deleter if
    // Deleter is a class, or else to __unique_ptr_funcptr_base<Deleter> if Deleter
    // is a function pointer.
    template<typename Deleter>
    struct __unique_ptr_base_selector
    {
        // This definition will be used when Deleter is a normal class type
        // (i.e. not a function pointer).

        using type = Deleter;
    };

    template<typename Ret, typename... Args>
    struct __unique_ptr_base_selector<Ret(*)(Args...)>
    {
        // This definition will be used when Deleter is a function pointer.
        using type = __unique_ptr_funcptr_base<Ret(*)(Args...)>;
    };

    template <typename T, typename Deleter = std::default_delete<T>>
    class unique_ptr : protected __unique_ptr_base_selector<Deleter>::type
    {
        public:
            using pointer = typename unique_ptr_pointer_type<T, Deleter>::type;
            using element_type = T;

            // This can be any callable type (i.e. a function pointer, or a
            // class with an operator()).
            using deleter_type = Deleter;

            // We need the base class of unique_ptr to always be a class,
            // whereas Deleter could be a class OR a function pointer type.
            // So __unique_ptr_base_selector<Deleter>::type will be either
            // (1) Deleter, if Deleter is a struct, or
            // (2) __unique_ptr_funcptr_base, if Deleter is a function
            // pointer. This is to facilitate EBO (see comment above
            // __unique_ptr_funcptr_base). This typedef is then used in the
            // get_deleter member function below.
            using __base = typename __unique_ptr_base_selector<Deleter>::type;

            /*
             * @brief Constructs an empty unique_ptr.
             */
            constexpr unique_ptr() :
                __base(), iv_ptr(nullptr) {}

            /*
             * @brief Constructs an empty unique_ptr.
             *
             * @param[in] nullptr_t  Tag to construct an empty unique_ptr.
             */
            constexpr unique_ptr(nullptr_t) :
                __base(), iv_ptr(nullptr) {}

            /*
             * @brief Constructs a unique_ptr taking ownership of the given
             * resource.
             *
             * @param[in] p  Pointer to own.
             */
            explicit unique_ptr(pointer p) :
                __base(), iv_ptr(p) {}

            /* @brief Copy-constructor, deleted.
             */
            unique_ptr(const unique_ptr& r) = delete;

            /*
             * @brief Constructs a unique_ptr taking ownership of the given
             * resource and the given deleter.
             *
             * @param[in] p    Pointer to own.
             * @param[in] del  Deleter to free the resource.
             */
            unique_ptr(pointer p, Deleter&& del) :
                __base { std::forward<Deleter>(del) }, iv_ptr(p) {}

            /*
             * @brief Constructs a unique_ptr taking ownership of the given
             * resource and the given deleter.
             *
             * @param[in] p    Pointer to own.
             * @param[in] del  Deleter to free the resource.
             */
            unique_ptr(pointer p, const Deleter& del) :
                __base { std::forward<Deleter>(del) }, iv_ptr(p) {}

            /*
             * @brief Move-constructor, takes ownership from the given
             * rvalue-reference to unique_ptr.
             *
             * @param[in] u    unique_ptr to take ownership from.
             */
            template< typename U, typename E>
            unique_ptr(unique_ptr<U,E>&& u) :
                __base(static_cast<__base&&>(u)), iv_ptr(u.release()) {}

            /* @brief Destructor. Frees owned resource, if any.
            */
            ~unique_ptr()
            {
                if (iv_ptr)
                {
                    get_deleter()(iv_ptr);
                    iv_ptr = nullptr;
                }
            }

            /* @brief Copy-assignment operator. Deleted. */
            unique_ptr& operator=(const unique_ptr& r) = delete;

            /* @brief Move-assignment operator. Takes ownership of a resource
             * from a given unique_ptr instance.
             *
             * @param[in] r   The unique_ptr to take ownership from.
             */
            template<typename U, typename E> unique_ptr&
            operator=(unique_ptr<U,E>&& r)
            {
                reset(r.release());
                get_deleter() = std::move(r.get_deleter());
                return *this;
            }

            /* @brief Assignment operator for nullptr. Cleans up owned resources
             * and clears pointer. */
            unique_ptr& operator=(nullptr_t)
            {
                reset(nullptr);
                return *this;
            }

            /* @brief Relinquishes ownership of resource to caller. Does NOT
             * clean up owned resource.
             *
             * @return pointer   Owning pointer to resource.
             */
            pointer release()
            {
                pointer l_ptr = iv_ptr;
                iv_ptr = nullptr;
                return l_ptr;
            }

            /* @brief Cleans up owned resource, if any, and takes ownership of
             * new resource.
             *
             * @param[in] i_ptr   Pointer to new resource to claim ownership of.
             */
            void reset(pointer i_ptr)
            {
                pointer l_ptr = iv_ptr;
                iv_ptr = i_ptr;
                if(l_ptr != nullptr)
                {
                    get_deleter()(l_ptr);
                }
            }

            /* @brief Swap resources with other pointer.
             *
             * @param[in] other   unique_ptr to swap resources with.
             */
            void swap(unique_ptr& other)
            {
                swap(iv_ptr, other.iv_ptr);
                swap(get_deleter(), other.get_deleter());
            }

            /* @brief Get non-owning pointer to resource.
             */
            pointer get() const
            {return iv_ptr;}

            /* @brief Get a reference to the deleter for this instance.
             *
             * We can cast a unique_ptr into a Deleter either one of two ways,
             * depending on what kind of type Deleter is:
             * 1) When Deleter is a class, it is used as our base class via
             *    unique_ptr_base_selector (see comments above for more info),
             *    so the cast is trivial.
             * 2) When Deleter is not a class, then our base class is
             *    __unique_ptr_funcptr_base<Deleter>, which has a conversion
             *    operator to Deleter, so the cast takes that path.
             *
             * @return Deleter&   Reference to deleter for this instance.
             */
            Deleter& get_deleter()
            {return static_cast<Deleter&>(*this);}

            /* @brief Get a reference to the deleter for this (const) instance.
             */
            const Deleter& get_deleter() const
            {return static_cast<Deleter&>(*this);}

            /* @brief Null-test for this instance.
             *
             * @return bool   True if this instance points to a resource,
             *                false otherwise.
             */
            explicit operator bool() const { return nullptr != get(); }

            /* @brief Dereference operator. The behavior is undefined if this
             * instance does not point to a resource (i.e. if get() returns
             * nullptr).
             *
             * @return T&   Reference to owned resource.
             */
            template<typename X=T>
            X& operator*() const
            { return *iv_ptr; }

            /* @brief Member access operator.
             *
             * @return T*   Non-owning pointer to owned resource.
             */
            pointer operator->() const { return iv_ptr; }

            /* @brief Equality test for unique_ptr.
             *
             * @return bool   True if this instance points to the same pointer
             * as the right-hand side, false otherwise.
             */
            bool operator==(const unique_ptr &r) const
            {
                return (iv_ptr == r.iv_ptr);
            }

            /* @brief Inequality test for unique_ptr.
             *
             * @return bool   False if this instance points to the same pointer
             * as the right-hand side, true otherwise.
             */
            bool operator!=(const unique_ptr &r) const
            {
                return (iv_ptr != r.iv_ptr);
            }

            /* @brief Index operator for unique_ptr<T[]>.
             *
             * operator[] is not callable on a unique_ptr to non-array types.
             *
             * @param[in] i   Index into the array
             * @return        Value of T::operator[](i)
             */
            template<typename Index, typename X = T>
            typename enable_if<is_array<X>::value, decltype(declval<X>()[declval<Index>()])>::type
            operator[](const Index i)
            {
                return iv_ptr[i];
            }

            template <typename U, typename D> friend class unique_ptr;

        private:
            pointer iv_ptr;
    };

    /* @brief Equality test for unique_ptr and nullptr.
     *
     * @return bool   True if this instance points to null.
     */
    template<typename T, typename Del>
    bool operator==(nullptr_t, const unique_ptr<T, Del>& r)
    { return r == nullptr; }

    /* @brief Inequality test for unique_ptr and nullptr.
     *
     * @return bool   False if this instance points to null.
     */
    template<typename T, typename Del>
    bool operator!=(nullptr_t, const unique_ptr<T, Del>& r)
    { return r != nullptr; }

    /* @brief Creates an instance of unique_ptr<T, default_delete<T>> where the
     * T instance is constructed from the given arguments.
     *
     * @param[in] args...      Parameters to the T constructor
     * @return unique_ptr<T>   Pointer instance
     */
    template <typename T, typename... Args>
    unique_ptr<T> make_unique( Args&&... args)
    {
        return unique_ptr<T>(new T(std::forward<Args>(args)...));
    }

    /* @brief Overload of std::swap for unique_ptr<T, Del>
     */
    template <typename T, typename Del>
    void swap(unique_ptr<T, Del>& l, unique_ptr<T, Del>& r) {
        return l.swap(r);
    }
}

#endif