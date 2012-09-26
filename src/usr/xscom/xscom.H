/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/xscom/xscom.H $                                       */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2011,2012              */
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
#ifndef __XSCOM_H
#define __XSCOM_H

/** @file xscom.H
 *  @brief Provides the interfaces to perform XSCom
 */

#include <stdint.h>
#include <limits.h>

/**
 *  @brief  Max number of retries if XSCOM fails with certain errors
 */
#define MAX_XSCOM_RETRY     1

/**
 *  @brief  The (fixed) base address value for master proc
 */
//@todo - Verify this value for HW
#define MASTER_PROC_XSCOM_BASE_ADDR     0x0003FC0000000000

/**
 *  @brief  Type definition for XSCom address and Chip ID
 */
typedef uint32_t XSComAddress_t;
typedef uint16_t XSComChipId_t;
typedef uint16_t XSComNodeId_t;
typedef uint64_t XSComBase_t;

namespace XSCOM
{

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
 *  @brief  Abstracts HMER register of a P8 (Murano/Venice) chip
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

    /**
     * @brief XSCom status values
     */
    enum XSComStatus
    {
        XSCOM_GOOD = 0,
        XSCOM_BLOCKED = 1,
        XSCOM_OFFLINE = 2,
        XSCOM_PARTIAL = 3,
        XSCOM_BAD_ADDRESS = 4,
        XSCOM_CLOCK_ERROR = 5,
        XSCOM_PARITY_ERROR = 6,
        XSCOM_TIMEOUT= 7,
    };

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
 *  address for a P8/Salerno chip.
 */
class XSComP8Address
{
  public:
    /**
     * @brief Constructor of XSComP8Address class
     *
     * @param[in]   i_addr          PCB address of the register being accessed
     *
     * @return  None
     */
     ALWAYS_INLINE inline XSComP8Address(const XSComAddress_t i_addr);

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
    XSComP8Address(const XSComP8Address& i_right);
    XSComP8Address& operator=(const XSComP8Address& right);

    // Layout of XSCOM address parts
    union
    {
        uint64_t mMmioAddress;          // mMmio address
        struct
        {
            uint64_t mReserved1:18;     // Not currently used (0:17)
            uint64_t mBaseAddress:5;    // Base address (18:22)
            uint64_t mNodeId:3;         // Node where target resides (23:25)
            uint64_t mChipId:3;         // Targeted chip ID (26:28)
            uint64_t mSComAddrHi:27;    // PCB Address High (29:55)
            uint64_t mCacheLine:1;      // Cached line (56)
            uint64_t mSComAddrLo:4;     // PCB Address low (57:60)
            uint64_t mAlign:3;          // Align (61:63)
        } mAddressParts;
    };

}; // End XSComP8Address class

//-----------------------------------------------------------------------
// In-line functions
//-----------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
XSComP8Address::XSComP8Address(const XSComAddress_t i_addr)
:mMmioAddress(0)
{
    // Relative address of Node 0, chip 0
    // The chip's nodeId and chip id will be taken into account
    // when calculating its XSCOM base address
    mAddressParts.mSComAddrHi = i_addr >> 4; // Get 27-bits
    mAddressParts.mSComAddrLo = i_addr;      // Get 4 bits
}

////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
XSComP8Address::operator uint64_t() const
{
    return mMmioAddress;
}

////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
uint64_t XSComP8Address::offset(void) const
{
    return (mMmioAddress / sizeof(uint64_t));
}

};

#endif
