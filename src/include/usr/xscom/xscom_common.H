/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/xscom/xscom_common.H $                        */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020                             */
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
#ifndef __XSCOM_COMMON_H
#define __XSCOM_COMMON_H

/** @file xscom_common.H
 *  @brief Provides data structures and interfaces common between HBBL and HB
 */

#include <stdint.h>
#include <builtins.h>

/**
 *  @brief  Type definition for XSCom address and Base
 */
typedef uint32_t XSComAddress_t;
typedef uint64_t XSComBase_t;

namespace XSCOM
{
    /**
     *  @brief  Abstracts HMER register of a POWER10 chip
     */
    class HMER
    {
    public:

        /**
        * @brief Constructor
        */
        ALWAYS_INLINE inline HMER()
        {
            mRegister = 0;
        }

        /**
        * @brief Constructor that takes in a value
        */
        explicit ALWAYS_INLINE inline HMER(uint64_t val)
        {
            mRegister = val;
        }

        /**
        * @brief Conversion operator
        */
        ALWAYS_INLINE inline operator uint64_t() const
        {
            return mRegister;
        }

        /**
        * @brief Operator=
        */
        ALWAYS_INLINE inline uint64_t operator = (uint64_t val)
        {
            return mRegister = val;
        }


        // Layout of HMER register parts
        union
        {
            uint64_t mRegister;
            struct
            {
                uint64_t :8;
                uint64_t mXSComFail:1;
                uint64_t mXSComDone:1;
                uint64_t :11;
                uint64_t mXSComStatus:3;
                uint64_t :40;
            };
        };
    }; // class HMER

    /**
     *  @brief  This class contains necessary information to build an XSCOM
     *  address for a POWER10 chip.
     */
    class XSComP10Address
    {
     public:
        /**
         * @brief Constructor of XSComP10Address class
         *
         * @param[in]   i_addr PCB address of the register being accessed
         *
         * @return None
         */
        ALWAYS_INLINE inline XSComP10Address(const XSComAddress_t i_addr);

        /**
         * @brief Conversion operator
         */
        ALWAYS_INLINE inline operator uint64_t() const;

        /**
         * @brief Return the address' 64-bit full offset
         *
         * @return uint64_t
         */
        ALWAYS_INLINE inline uint64_t offset(void) const;

    private:
        /**
         * @brief Disabled copy constructor and assignment operator
         */
        XSComP10Address(const XSComP10Address& i_right);
        XSComP10Address& operator=(const XSComP10Address& right);

        // Layout of XSCOM address parts
        union
        {
            uint64_t mMmioAddress;         // mMmio address
            struct
            {
                uint64_t mReserved1:8;     // Not currently used (0:7)
                uint64_t mBaseAddrHi:7;    // Base address [8:14] (8:14)
                uint64_t mGroupId:4;       // Group where target resides (15:18)
                uint64_t mChipId:3;        // Targeted chip ID (19:21)
                uint64_t mBaseAddrLo:8;    // Base address [22:29] (22:29)
                uint64_t mSComAddr:31;     // PIB Address (30:60)
                uint64_t mAlign:3;         // Align (61:63)
            } mAddressParts;
        };

    }; // class XSComP10Address

    //-----------------------------------------------------------------------
    // In-line functions
    //-----------------------------------------------------------------------

    ////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////
    XSComP10Address::XSComP10Address(const XSComAddress_t i_addr)
                     :mMmioAddress(0)
    {
        // Relative address of Group 0, chip 0
        // The chip's groupId and chip id will be taken into account
        // when calculating its XSCOM base address
        mAddressParts.mSComAddr = i_addr;
    }

    ////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////
    XSComP10Address::operator uint64_t() const
    {
        return mMmioAddress;
    }

    ////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////
    uint64_t XSComP10Address::offset(void) const
    {
        return (mMmioAddress / sizeof(uint64_t));
    }

}; // namespace XSCOM

#endif
