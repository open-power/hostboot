/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/util/impl/shared_ptr.H $                          */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015                             */
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
#ifndef __UTIL_IMPL_SHARED_PTR_H
#define __UTIL_IMPL_SHARED_PTR_H

#include <cstddef>
#include <utility>
#include <stdint.h>

namespace std
{
    namespace __impl
    {
        class shared_ptr_count
        {
            public:
                shared_ptr_count() : count(1) {};
                ~shared_ptr_count() = default;

                void increment() { __sync_add_and_fetch(&count, 1); };
                bool decrement()
                    { return 0 == __sync_add_and_fetch(&count, -1); };
                size_t use_count() { return count; };

            private:
                size_t count;
        };
    }

    template <typename T>
    class shared_ptr
    {
        public:
            typedef T element_type;

            constexpr shared_ptr() :
                count(nullptr), pointer(nullptr), owner(nullptr) {};
            constexpr shared_ptr(nullptr_t) :
                count(nullptr), pointer(nullptr), owner(nullptr) {};

            template<typename U> explicit shared_ptr(U* ptr)
            {
                _setup(ptr);
            }

            template<typename U> shared_ptr(const shared_ptr<U>& r, T* ptr)
                { _copy(r); pointer = ptr; }

            shared_ptr(const shared_ptr& r) { _copy(r); }
            template<typename U> shared_ptr(const shared_ptr<U>& r)
                { _copy(r); }

            shared_ptr(shared_ptr&& r) { _swap(std::move(r)); }
            template<typename U> shared_ptr(shared_ptr<U>&& r)
                { _swap(std::move(r)); }

            ~shared_ptr() { _cleanup(); }

            shared_ptr& operator=(const shared_ptr& r)
            {
                _cleanup();
                _copy(r);

                return *this;
            }
            template<typename U> shared_ptr& operator=(const shared_ptr<U>& r)
            {
                _cleanup();
                _copy(r);

                return *this;
            }

            shared_ptr& operator=(shared_ptr&& r)
            {
                _cleanup();
                _swap(std::move(r));

                return *this;
            }
            template<typename U> shared_ptr& operator=(shared_ptr<U>&& r)
            {
                _cleanup();
                _swap(std::move(r));

                return *this;
            }

            void reset() { _cleanup(); }
            template<typename U> void reset(U* ptr) { _cleanup(); _setup(ptr); }

            void swap(shared_ptr& r)
            {
                T* tmp0 = r.owner;
                T* tmp1 = r.pointer;
                __impl::shared_ptr_count* tmp2 = r.count;
                r.owner = owner;
                r.pointer = pointer;
                r.count = count;
                owner = tmp0;
                pointer = tmp1;
                count = tmp2;
            }

            T* get() const { return pointer; }

            T& operator*() const { return *pointer; }
            T* operator->() const { return pointer; }

            long use_count() const
            {
                if (count) return count->use_count();
                return 0;
            }
            bool unique() const { return use_count() == 1; }

            explicit operator bool() const { return nullptr != get(); }

            template<typename U>
            bool owner_before(const shared_ptr<U>& other) const
            {
                return (owner < other.owner);
            }

            template <typename U> friend class shared_ptr;

        private:
            __impl::shared_ptr_count* count;
            T* pointer;
            T* owner;

            template<typename U> void _setup(U* ptr)
            {
                owner = pointer = static_cast<T*>(ptr);
                if (pointer)
                {
                    count = new __impl::shared_ptr_count();
                }
                else
                {
                    count = nullptr;
                }
            }

            void _cleanup()
            {
                if (!count) return;

                if (count->decrement())
                {
                    delete count;
                    count = nullptr;
                    delete owner;
                    owner = nullptr;
                    pointer = nullptr;
                }
            }

            template<typename U> void _copy(const shared_ptr<U>& r)
            {
                if (r.count) r.count->increment();
                count = r.count;
                owner = static_cast<T*>(r.owner);
                pointer = static_cast<T*>(r.pointer);
            }

            template<typename U> void _swap(shared_ptr<U>&& r)
            {
                count = r.count;
                owner = r.owner;
                pointer = r.pointer;
                r.count = nullptr;
                r.owner = nullptr;
                r.pointer = nullptr;
            }
    };

    template <typename T, typename... Args>
    shared_ptr<T> make_shared( Args&&... args)
    {
        return shared_ptr<T>(new T(std::forward<Args>(args)...));
    }

    template <typename T, typename U>
    shared_ptr<T> static_pointer_cast(const shared_ptr<U>& r)
    {
        return shared_ptr<T>(r,
            static_cast<typename shared_ptr<T>::element_type*>(r.get()));
    }

    template <typename T, typename U>
    shared_ptr<T> dynamic_pointer_cast(const shared_ptr<U>& r)
    {
        return shared_ptr<T>(r,
            dynamic_cast<typename shared_ptr<T>::element_type*>(r.get()));
    }

    template <typename T, typename U>
    shared_ptr<T> const_pointer_cast(const shared_ptr<U>& r)
    {
        return shared_ptr<T>(r,
            const_cast<typename shared_ptr<T>::element_type*>(r.get()));
    }

    template <typename T>
    void swap(shared_ptr<T>& l, shared_ptr<T>& r) { return l.swap(r); }
}

#endif
