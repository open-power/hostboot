/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/xscom/xscom.H $                                       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2016                        */
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
#ifndef __XSCOM_H
#define __XSCOM_H

/** @file xscom.H
 *  @brief Provides the interfaces to perform XSCom
 */

#include <stdint.h>
#include <limits.h>

/**
 *  @brief  The (fixed) base address value for master proc
 */
constexpr uint64_t MASTER_PROC_XSCOM_BASE_ADDR = 0x000603FC00000000;

/**
 *  @brief  Static offsets into other chips
 */
constexpr uint64_t  MMIO_OFFSET_PER_CHIP  = (4*TERABYTE);
constexpr uint64_t  MMIO_OFFSET_PER_GROUP = (32*TERABYTE);

/**
 *  @brief  Type definition for XSCom address and Base
 */
typedef uint32_t XSComAddress_t;
typedef uint64_t XSComBase_t;

namespace XSCOM
{

 enum CpuType
 {
    CurThreadCpu,
    TargetCpu
 };


struct XscomAddrType_t
{
  uint32_t addr;
  CpuType target_type;
};

#define     XSCOM_BUFFER_SIZE   8   // 8 bytes


/**
 * @brief Performs an XSCom access operation
 * This function performs an XSCom access operation. It follows a pre-defined
 * prototype functions in order to be registered with the device-driver
 * framework.
 *
 * @param[in]   i_opType        Operation type, see DeviceFW::OperationType
 *                              in driverif.H
 * @param[in]   i_target        XSCom target
 * @param[in/out] io_buffer      Read: Pointer to output data storage
 *                              Write: Pointer to input data storage
 * @param[in/out] io_buflen     Input: size of io_buffer (in bytes)
 *                              Output:
 *                                  Read: Size of output data
 *                                  Write: Size of data written
 * @param[in]   i_accessType    DeviceFW::AccessType enum (usrif.H)
 * @param[in]   i_args          This is an argument list for DD framework.
 *                              In this function, there's only one argument,
 *                              which is the MMIO XSCom address
 * @return  errlHndl_t
 */
errlHndl_t xscomPerformOp(DeviceFW::OperationType i_opType,
                          TARGETING::Target* i_target,
                          void* io_buffer,
                          size_t& io_buflen,
                          int64_t i_accessType,
                          va_list i_args);

/**
 *  @brief  Abstracts HMER register of a POWER9 chip
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
};

/**
 *  @brief  This class contains necessary information to build an XSCOM
 *  address for a POWER9 chip.
 */
class XSComP9Address
{
  public:
    /**
     * @brief Constructor of XSComP9Address class
     *
     * @param[in]   i_addr          PCB address of the register being accessed
     *
     * @return  None
     */
    ALWAYS_INLINE inline XSComP9Address(const XSComAddress_t i_addr);

    /**
     * @brief Conversion operator
     */
    ALWAYS_INLINE inline operator uint64_t() const;

    /**
     * @brief Return the address' 64-bit full offset
     *
     * @return  uint64_t
     */
    ALWAYS_INLINE inline uint64_t offset(void) const;

  private:
    /**
      * @brief   Disabled copy constructor and assignment operator
      */
    XSComP9Address(const XSComP9Address& i_right);
    XSComP9Address& operator=(const XSComP9Address& right);

    // Layout of XSCOM address parts
    union
    {
        uint64_t mMmioAddress;          // mMmio address
        struct
        {
            uint64_t mReserved1:8;      // Not currently used (0:7)
            uint64_t mBaseAddrHi:7;     // Base address [8:14] (8:14)
            uint64_t mGroupId:4;        // Group where target resides (15:18)
            uint64_t mChipId:3;         // Targeted chip ID (19:21)
            uint64_t mBaseAddrLo:8;     // Base address [22:29] (22:29)
            uint64_t mSComAddr:31;      // PIB Address (30:60)
            uint64_t mAlign:3;          // Align (61:63)
        } mAddressParts;
    };

}; // End XSComP9Address class

//-----------------------------------------------------------------------
// In-line functions
//-----------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
XSComP9Address::XSComP9Address(const XSComAddress_t i_addr)
:mMmioAddress(0)
{
    // Relative address of Group 0, chip 0
    // The chip's groupId and chip id will be taken into account
    // when calculating its XSCOM base address
    mAddressParts.mSComAddr = i_addr;
}

////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
XSComP9Address::operator uint64_t() const
{
    return mMmioAddress;
}

////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
uint64_t XSComP9Address::offset(void) const
{
    return (mMmioAddress / sizeof(uint64_t));
}

};

#endif
