/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/common/include/scomt_regs.H $   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2021,2022                        */
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
#pragma once

#include <fapi2.H>

#ifndef __PPE_HCODE__
namespace scomt
{
#endif

// Using the notion of "forbidden" here instead of "allowed" since it allows us to have
// a mask of all-0 in the default case, optimizing out the check.
static const uint32_t FORBIDDEN_CHIP_P10DD1 =  0x00000001;
static const uint32_t FORBIDDEN_CHIP_P10DD2 =  0x00000002;
static const uint32_t FORBIDDEN_CHIP_ODYDD1 =  0x00000004;
static const uint32_t FORBIDDEN_CHIP_ODYDD2 =  0x00000008;
static const uint32_t FORBIDDEN_CHIP_P11TDD1 = 0x00000010;
static const uint32_t FORBIDDEN_CHIP_P11TDD2 = 0x00000020;
static const uint32_t FORBIDDEN_CHIP_P11SDD1 = 0x00000040;
static const uint32_t FORBIDDEN_CHIP_P11SDD2 = 0x00000080;

// Both this and forbiddenAccess() below only need to be declared
// somewhere on the Cronus platform; other platforms won't use it.
extern uint32_t current_chip;

// This is getting called when a forbidden field is accessed.
// It should be very loud and not return.
void forbiddenAccess(const uint32_t forbidden_mask);

template <uint64_t ADDRESS>
class ScomRegister : public fapi2::buffer<uint64_t>
{
    public:
        inline __attribute__((always_inline)) ScomRegister(fapi2::buffer<uint64_t> value = 0) : buffer(value) {}

        inline __attribute__((always_inline)) ScomRegister& operator=(const uint64_t value)
        {
            (*this)() = value;
            return *this;
        }

        inline __attribute__((always_inline)) ScomRegister& operator=(const fapi2::buffer<uint64_t> value)
        {
            (*this)() = value();
            return *this;
        }

        template < fapi2::TargetType K, fapi2::MulticastType M, typename V >
        inline __attribute__((always_inline)) fapi2::ReturnCode getScom(const fapi2::Target<K, M, V>& i_target)
        {
            return fapi2::getScom(i_target, ADDRESS, *this);
        }

        template < fapi2::TargetType K, fapi2::MulticastType M, typename V >
        inline __attribute__((always_inline)) fapi2::ReturnCode putScom(const fapi2::Target<K, M, V>& i_target) const
        {
            return fapi2::putScom(i_target, ADDRESS, *this);
        }
        static const uint64_t addr = ADDRESS;

    protected:
        template <uint32_t FORBIDDEN_MASK>
        inline __attribute__((always_inline)) void checkAvailability() const
        {
            if (fapi2::is_platform<fapi2::PLAT_CRONUS>() && (current_chip & FORBIDDEN_MASK))
            {
                forbiddenAccess(FORBIDDEN_MASK);
            }
        }

        template < fapi2::TargetType K, fapi2::MulticastType M, typename V >
        inline __attribute__((always_inline))
        fapi2::ReturnCode _putScom(const fapi2::Target<K, M, V>& i_target, uint64_t i_address) const
        {
            return fapi2::putScom(i_target, i_address, *this);
        }

        template < fapi2::TargetType K, fapi2::MulticastType M, typename V >
        inline __attribute__((always_inline))
        fapi2::ReturnCode _getScom(const fapi2::Target<K, M, V>& i_target, uint64_t i_address)
        {
            return fapi2::getScom(i_target, i_address, *this);
        }
};

template <uint32_t ADDRESS>
class CfamRegister : public fapi2::buffer<uint32_t>
{
    public:
        inline __attribute__((always_inline)) CfamRegister(fapi2::buffer<uint32_t> value = 0) : buffer(value) {}

        inline __attribute__((always_inline)) CfamRegister& operator=(const uint32_t value)
        {
            (*this)() = value;
            return *this;
        }

        inline __attribute__((always_inline)) CfamRegister& operator=(const fapi2::buffer<uint32_t> value)
        {
            (*this)() = value();
            return *this;
        }

        template < fapi2::TargetType K, fapi2::MulticastType M, typename V >
        inline __attribute__((always_inline)) fapi2::ReturnCode getCfam(const fapi2::Target<K, M, V>& i_target)
        {
            return fapi2::getCfamRegister(i_target, ADDRESS, *this);
        }

        template < fapi2::TargetType K, fapi2::MulticastType M, typename V >
        inline __attribute__((always_inline)) fapi2::ReturnCode putCfam(const fapi2::Target<K, M, V>& i_target) const
        {
            return fapi2::putCfamRegister(i_target, ADDRESS, *this);
        }
        static const uint32_t addr = ADDRESS;

    protected:
        template <uint32_t FORBIDDEN_MASK>
        inline __attribute__((always_inline)) void checkAvailability() const
        {
            if (fapi2::is_platform<fapi2::PLAT_CRONUS>() && (current_chip & FORBIDDEN_MASK))
            {
                forbiddenAccess(FORBIDDEN_MASK);
            }
        }

        template < fapi2::TargetType K, fapi2::MulticastType M, typename V >
        inline __attribute__((always_inline))
        fapi2::ReturnCode _putScom(const fapi2::Target<K, M, V>& i_target, uint64_t i_address) const
        {
            fapi2::buffer<uint64_t> l_buf = ((uint64_t) * this) << 32;
            return fapi2::putScom(i_target, i_address, l_buf);
        }

        template < fapi2::TargetType K, fapi2::MulticastType M, typename V >
        inline __attribute__((always_inline))
        fapi2::ReturnCode _getScom(const fapi2::Target<K, M, V>& i_target, uint64_t i_address)
        {
            fapi2::buffer<uint64_t> l_buf;
            fapi2::ReturnCode rc = fapi2::getScom(i_target, i_address, l_buf);
            *this = l_buf >> 32;
            return rc;
        }
};

#ifndef __PPE_HCODE__
}
#endif

#ifdef __PPE_HCODE__
    #define _SCOMT_OPEN_NAMESPACE(name)
    #define _SCOMT_CLOSE_NAMESPACE
#else
    #define _SCOMT_OPEN_NAMESPACE(name) namespace scomt { namespace name {
    #define _SCOMT_CLOSE_NAMESPACE }}
#endif

#define _SCOMT_REGISTER_BEGIN(name)                                     \
    name(const fapi2::buffer<uint64_t> &value) : ScomRegister(value) {} \
    name(const uint64_t value = 0) : ScomRegister(value) {}             \
    using ScomRegister::operator=;

#define _SCOMT_CFAM_REGISTER_BEGIN(name)                                \
    name(const fapi2::buffer<uint32_t> &value) : CfamRegister(value) {} \
    name(const uint32_t value = 0) : CfamRegister(value) {}             \
    using CfamRegister::operator=;

#define _SCOMT_BOOL_FIELD(type, name, bit) _SCOMT_EC_BOOL_FIELD(type, name, bit, 0)
#define _SCOMT_EC_BOOL_FIELD(type, name, bit, forbidden)                \
    bool get_##name(void) const {                                       \
        checkAvailability<forbidden>();                                 \
        return getBit<bit>();                                           \
    }                                                                   \
    type &set_##name(const bool value) {                                \
        checkAvailability<forbidden>();                                 \
        writeBit<bit>(value);                                           \
        return *this;                                                   \
    }

#define _SCOMT_INT_FIELD(type, name, bit, len) _SCOMT_EC_INT_FIELD(type, name, bit, len, 0)
#define _SCOMT_EC_INT_FIELD(type, name, bit, len, forbidden)            \
    uint64_t get_##name(void) const {                                   \
        checkAvailability<forbidden>();                                 \
        return getBits<bit, len>();                                     \
    }                                                                   \
    type &set_##name(const uint64_t value) {                            \
        checkAvailability<forbidden>();                                 \
        insertFromRight<bit, len>(value);                               \
        return *this;                                                   \
    }

#define _SCOMT_EXTRA_PUTSCOM(name, address)                             \
    template < fapi2::TargetType K, fapi2::MulticastType M, typename V > \
    inline __attribute__((always_inline))                               \
    fapi2::ReturnCode name(const fapi2::Target<K, M, V> &i_target) const \
    {                                                                   \
        return _putScom(i_target, address);                             \
    }

#define _SCOMT_EXTRA_GETSCOM(name, address)                             \
    template < fapi2::TargetType K, fapi2::MulticastType M, typename V > \
    inline __attribute__((always_inline))                               \
    fapi2::ReturnCode name(const fapi2::Target<K, M, V> &i_target)      \
    {                                                                   \
        return _getScom(i_target, address);                             \
    }

#define _SCOMT_EXTRA_PUTCFAM(name, address)                             \
    template < fapi2::TargetType K, fapi2::MulticastType M, typename V > \
    inline __attribute__((always_inline))                               \
    fapi2::ReturnCode name(const fapi2::Target<K, M, V> &i_target) const \
    {                                                                   \
        return fapi2::putCfamRegister(i_target, address, *this);        \
    }

#define _SCOMT_EXTRA_GETCFAM(name, address)                             \
    template < fapi2::TargetType K, fapi2::MulticastType M, typename V > \
    inline __attribute__((always_inline))                               \
    fapi2::ReturnCode name(const fapi2::Target<K, M, V> &i_target)      \
    {                                                                   \
        return fapi2::getCfamRegister(i_target, address, *this);        \
    }
