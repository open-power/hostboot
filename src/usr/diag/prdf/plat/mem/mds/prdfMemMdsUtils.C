/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/plat/mem/mds/prdfMemMdsUtils.C $            */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2021                             */
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

#include <prdfMemMdsUtils.H>

#include <prdfErrlUtil.H>
#include <prdfMain_common.H>
#include <prdf_service_codes.H>

#include <devicefw/userif.H>

using namespace TARGETING;

namespace PRDF
{

using namespace PlatServices;

namespace MDS
{

//------------------------------------------------------------------------------

template<>
uint32_t readMdsCtlr<TYPE_MDS_CTLR>( TargetHandle_t i_mdsCtlr, uint32_t i_addr,
                                     uint32_t & o_data )
{
    #define PRDF_FUNC "[readMdsCtlr] "

    PRDF_ASSERT( nullptr != i_mdsCtlr );
    PRDF_ASSERT( TYPE_MDS_CTLR == getTargetType(i_mdsCtlr) );

    uint32_t o_rc = SUCCESS;

    o_data = 0;

    // Buffer length must be 4 bytes
    size_t bufLen = sizeof(uint32_t);
    void * buf = malloc(bufLen);

    errlHndl_t errl = nullptr;

    errl = DeviceFW::deviceRead( i_mdsCtlr, buf, bufLen,
                                 DEVICE_SCOM_ADDRESS(i_addr) );
    if ( nullptr != errl )
    {
        PRDF_ERR( PRDF_FUNC "deviceRead() failed on i_mdsCtlr=0x%08x "
                  "i_addr=0x%016llx", getHuid(i_mdsCtlr), i_addr );

        o_rc = PRD_SCANCOM_FAILURE;
        PRDF_ADD_SW_ERR(errl, o_rc, PRDF_HOM_SCOM, __LINE__);

        bool l_isAbort = false;
        PRDF_ABORTING(l_isAbort);
        if (!l_isAbort)
        {
            PRDF_SET_ERRL_SEV(errl, ERRL_SEV_INFORMATIONAL);
            PRDF_COMMIT_ERRL(errl, ERRL_ACTION_HIDDEN);
        }
        else
        {
            delete errl;
            errl = nullptr;
        }
    }
    else
    {
        o_data = *reinterpret_cast<uint32_t*>(buf);
    }

    free(buf);
    buf = nullptr;

    return o_rc;

    #undef PRDF_FUNC
}

template<>
uint32_t readMdsCtlr<TYPE_OCMB_CHIP>( TargetHandle_t i_ocmb, uint32_t i_addr,
                                      uint32_t & o_data )
{
    PRDF_ASSERT( nullptr != i_ocmb );
    PRDF_ASSERT( TYPE_OCMB_CHIP == getTargetType(i_ocmb) );

    TargetHandle_t mdsCtlr = getConnectedChild( i_ocmb, TYPE_MDS_CTLR, 0 );

    return readMdsCtlr<TYPE_MDS_CTLR>(mdsCtlr, i_addr, o_data);
}

//------------------------------------------------------------------------------

template<>
uint32_t writeMdsCtlr<TYPE_MDS_CTLR>( TargetHandle_t i_mdsCtlr, uint32_t i_addr,
                                      uint32_t i_data )
{
    #define PRDF_FUNC "[writeMdsCtlr] "

    PRDF_ASSERT( nullptr != i_mdsCtlr );
    PRDF_ASSERT( TYPE_MDS_CTLR == getTargetType(i_mdsCtlr) );

    uint32_t o_rc = SUCCESS;

    // Buffer length must be 4 bytes
    size_t bufLen = sizeof(uint32_t);

    errlHndl_t errl = nullptr;

    errl = DeviceFW::deviceWrite( i_mdsCtlr, &i_data, bufLen,
                                  DEVICE_SCOM_ADDRESS(i_addr) );
    if ( nullptr != errl )
    {
        PRDF_ERR( PRDF_FUNC "deviceWrite() failed on i_mdsCtlr=0x%08x "
                  "i_addr=0x%016llx", getHuid(i_mdsCtlr), i_addr );

        o_rc = PRD_SCANCOM_FAILURE;
        PRDF_ADD_SW_ERR(errl, o_rc, PRDF_HOM_SCOM, __LINE__);

        bool l_isAbort = false;
        PRDF_ABORTING(l_isAbort);
        if (!l_isAbort)
        {
            PRDF_SET_ERRL_SEV(errl, ERRL_SEV_INFORMATIONAL);
            PRDF_COMMIT_ERRL(errl, ERRL_ACTION_HIDDEN);
        }
        else
        {
            delete errl;
            errl = nullptr;
        }
    }

    return o_rc;

    #undef PRDF_FUNC
}

template<>
uint32_t writeMdsCtlr<TYPE_OCMB_CHIP>( TargetHandle_t i_ocmb, uint32_t i_addr,
                                      uint32_t i_data )
{
    PRDF_ASSERT( nullptr != i_ocmb );
    PRDF_ASSERT( TYPE_OCMB_CHIP == getTargetType(i_ocmb) );

    TargetHandle_t mdsCtlr = getConnectedChild( i_ocmb, TYPE_MDS_CTLR, 0 );

    return writeMdsCtlr<TYPE_MDS_CTLR>(mdsCtlr, i_addr, i_data);
}

//------------------------------------------------------------------------------

uint32_t clearMediaErrLogs( ExtensibleChip * i_ocmb )
{
    #define PRDF_FUNC "[clearMediaErrLogs] "

    PRDF_ASSERT( nullptr != i_ocmb );
    PRDF_ASSERT( TYPE_OCMB_CHIP == i_ocmb->getType() );

    uint32_t o_rc = SUCCESS;

    // Enable mode change registers F1RCCX, F1RCDX, F1RCEX, and F1RCFX to
    // 0xAB, 0xCD, 0x89, and 0xEF respectively. These registers start at address
    // 0x0001001B
    uint32_t savedData = 0;
    o_rc = readMdsCtlr<TYPE_OCMB_CHIP>( i_ocmb->getTrgt(), 0x0001001B,
                                        savedData );
    if ( SUCCESS != o_rc )
    {
        PRDF_ERR( PRDF_FUNC "readMdsCtlr(0x%08x, 0x0001001B) failed.",
                  i_ocmb->getHuid() );
    }

    uint32_t enableModeChange = 0xABCD89EF;
    o_rc = writeMdsCtlr<TYPE_OCMB_CHIP>( i_ocmb->getTrgt(), 0x0001001B,
                                         enableModeChange );
    if ( SUCCESS != o_rc )
    {
        PRDF_ERR( PRDF_FUNC "writeMdsCtlr(0x%08x, 0x0001001B) failed.",
                  i_ocmb->getHuid() );
    }

    // Set the media error log clear bit (bit 7 starting at address 0x00202600)
    uint32_t data = 0;
    o_rc = readMdsCtlr<TYPE_OCMB_CHIP>( i_ocmb->getTrgt(), 0x00202600,
                                        data );
    if ( SUCCESS != o_rc )
    {
        PRDF_ERR( PRDF_FUNC "readMdsCtlr(0x%08x, 0x0001001B) failed.",
                  i_ocmb->getHuid() );
    }

    data |= 0x01000000;
    o_rc = writeMdsCtlr<TYPE_OCMB_CHIP>( i_ocmb->getTrgt(), 0x00202600,
                                         data );
    if ( SUCCESS != o_rc )
    {
        PRDF_ERR( PRDF_FUNC "writeMdsCtlr(0x%08x, 0x0001001B) failed.",
                  i_ocmb->getHuid() );
    }


    // Set the mode change registers back to what they were set to before, just
    // in case.
    o_rc = writeMdsCtlr<TYPE_OCMB_CHIP>( i_ocmb->getTrgt(), 0x0001001B,
                                         savedData );
    if ( SUCCESS != o_rc )
    {
        PRDF_ERR( PRDF_FUNC "writeMdsCtlr(0x%08x, 0x0001001B) failed.",
                  i_ocmb->getHuid() );
    }

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

// This enum defines the types of interface errors to be read from the media
// controller for the below __getErrorCount function. The value of each type is
// the address that needs to be read from.
enum interfaceErr: uint32_t
{
    SINGLE_BIT = 0x000C0013,
    DOUBLE_BIT = 0x000C0016,
    POISON     = 0x000C0019,
};

uint32_t __getInterfaceErrCount( TargetHandle_t i_mdsCtlr, uint32_t i_addr,
                                 uint8_t & o_errCount )
{
    #define PRDF_FUNC "[__getInterfaceErrCount] "

    PRDF_ASSERT( nullptr != i_mdsCtlr );
    PRDF_ASSERT( TYPE_MDS_CTLR == getTargetType(i_mdsCtlr) );

    uint32_t o_rc = SUCCESS;

    // The error counts we are interested in reading are defined in the first
    // byte of the data, the first bit being the counter reset bit, and the
    // remaining 7 bits being the counter itself.
    uint32_t data = 0;
    o_errCount = 0;

    o_rc = readMdsCtlr<TYPE_MDS_CTLR>( i_mdsCtlr, i_addr, data );
    if ( SUCCESS != o_rc )
    {
        PRDF_ERR( PRDF_FUNC "readMdsCtlr(0x%08x, 0x%08x) failed.",
                  getHuid(i_mdsCtlr), i_addr );
    }
    else
    {
        o_errCount = (data >> 24) & 0x7f;
    }

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

template<>
uint32_t getSingleBitCount<TYPE_MDS_CTLR>( TargetHandle_t i_mdsCtlr,
                                           uint8_t & o_singleBitCount )
{
    PRDF_ASSERT( nullptr != i_mdsCtlr );
    PRDF_ASSERT( TYPE_MDS_CTLR == getTargetType(i_mdsCtlr) );

    // The single bit error counter is located in control word FCRC4x (8 bits)
    // on the media controller which begins at address 0x000C0013.
    o_singleBitCount = 0;

    return __getInterfaceErrCount( i_mdsCtlr, interfaceErr::SINGLE_BIT,
                                   o_singleBitCount );
}

template<>
uint32_t getSingleBitCount<TYPE_OCMB_CHIP>( TargetHandle_t i_ocmb,
                                            uint8_t & o_singleBitCount )
{
    PRDF_ASSERT( nullptr != i_ocmb );
    PRDF_ASSERT( TYPE_OCMB_CHIP == getTargetType(i_ocmb) );

    TargetHandle_t mdsCtlr = getConnectedChild( i_ocmb, TYPE_MDS_CTLR, 0 );

    return getSingleBitCount<TYPE_MDS_CTLR>( mdsCtlr, o_singleBitCount );
}

//------------------------------------------------------------------------------

template<>
uint32_t getDoubleBitCount<TYPE_MDS_CTLR>( TargetHandle_t i_mdsCtlr,
                                           uint8_t & o_doubleBitCount )
{
    PRDF_ASSERT( nullptr != i_mdsCtlr );
    PRDF_ASSERT( TYPE_MDS_CTLR == getTargetType(i_mdsCtlr) );

    // The double bit error counter is located in control word FCRC7x (8 bits)
    // on the media controller which begins at address 0x000C0016.
    o_doubleBitCount = 0;

    return __getInterfaceErrCount( i_mdsCtlr, interfaceErr::DOUBLE_BIT,
                                   o_doubleBitCount );
}

template<>
uint32_t getDoubleBitCount<TYPE_OCMB_CHIP>( TargetHandle_t i_ocmb,
                                            uint8_t & o_doubleBitCount )
{
    PRDF_ASSERT( nullptr != i_ocmb );
    PRDF_ASSERT( TYPE_OCMB_CHIP == getTargetType(i_ocmb) );

    TargetHandle_t mdsCtlr = getConnectedChild( i_ocmb, TYPE_MDS_CTLR, 0 );

    return getDoubleBitCount<TYPE_MDS_CTLR>( mdsCtlr, o_doubleBitCount );
}

//------------------------------------------------------------------------------

template<>
uint32_t getPoisonCount<TYPE_MDS_CTLR>( TargetHandle_t i_mdsCtlr,
                                        uint8_t & o_poisonCount )
{
    PRDF_ASSERT( nullptr != i_mdsCtlr );
    PRDF_ASSERT( TYPE_MDS_CTLR == getTargetType(i_mdsCtlr) );

    // The poison counter is located in control word FCRCAx (8 bits) on the
    // media controller which begins at address 0x000C0019.
    o_poisonCount = 0;

    return __getInterfaceErrCount( i_mdsCtlr, interfaceErr::POISON,
                                   o_poisonCount );
}

template<>
uint32_t getPoisonCount<TYPE_OCMB_CHIP>( TargetHandle_t i_ocmb,
                                         uint8_t & o_poisonCount )
{
    PRDF_ASSERT( nullptr != i_ocmb );
    PRDF_ASSERT( TYPE_OCMB_CHIP == getTargetType(i_ocmb) );

    TargetHandle_t mdsCtlr = getConnectedChild( i_ocmb, TYPE_MDS_CTLR, 0 );

    return getPoisonCount<TYPE_MDS_CTLR>( mdsCtlr, o_poisonCount );
}

//------------------------------------------------------------------------------

} // end namespace MDS

} // end namespace PRDF

