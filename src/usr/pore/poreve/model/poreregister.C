/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/pore/poreve/model/poreregister.C $                    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2014              */
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
// $Id: poreregister.C,v 1.5 2011/08/03 17:59:00 bcbrock Exp $

/// \file poreregister.C
/// \brief The PoreRegister and PoreRegisterWritable classes

#include "poreinterface.H"

using namespace vsbe;


////////////////////////////////////////////////////////////////////////////
// PoreRegister
////////////////////////////////////////////////////////////////////////////

////////////////////////////// Creators //////////////////////////////

PoreRegister::PoreRegister(PoreInterface* i_interface, 
                           const PoreRegisterEncoding i_encoding) :
    iv_interface(i_interface),
    iv_encoding(i_encoding)
{
}


PoreRegister::~PoreRegister()
{
}


uint64_t 
PoreRegister::read() const
{
    uint64_t data;
    ModelError me;
    PoreRegisterOffset offset = PORE_REGISTER_MAP[iv_encoding];

    switch (iv_encoding) {

    case PORE_D0:
    case PORE_D1:
    case PORE_A0:
    case PORE_A1:
    case PORE_EMR:
    case PORE_ETR:
    case PORE_IFR:

        // These are read as 64-bit registers in the model

        me = iv_interface->registerRead(offset, data);
        break;

    case PORE_P0:
    case PORE_P1:
    case PORE_CTR:
    case PORE_SPRG0:

        // These registers are <= 32 bits and stored right-justified in the
        // high-order 32 bits of the 64-bit registers.  In every case the
        // hardware specification specifies that unused bits on the left read
        // as 0.

        me = iv_interface->registerRead(offset, data);
        data >>= 32;
        break;

    case PORE_PC:

        // The PC is read as the low-order 48 bits of the status register.

        me = iv_interface->registerRead(offset, data);
        data &= 0xffffffffffffull;
        break;

    case PORE_CIA:

        // The CIA is obtained from the high-order 48 bits of the DBG1
        // register. 

        me = iv_interface->registerRead(offset, data);
        data >>= 16;
        break;

    default:
        me = ME_BUG;
        break;
    }
    if (me != 0) {
        iv_interface->modelError(me);
    }
    return data;
}


PoreRegister::operator uint64_t () const
{
    return read();
}


////////////////////////////////////////////////////////////////////////////
// PoreRegisterWritable
////////////////////////////////////////////////////////////////////////////

PoreRegisterWritable::
PoreRegisterWritable(PoreInterface* i_interface, 
                     const PoreRegisterEncoding i_encoding) :
    PoreRegister(i_interface, i_encoding)
{
}


PoreRegisterWritable::~PoreRegisterWritable()
{
}


uint64_t    
PoreRegisterWritable::write(const uint64_t i_data)
{
    ModelError me;
    PoreRegisterOffset offset = PORE_REGISTER_MAP[iv_encoding];

    switch (iv_encoding) {

    case PORE_D0:
    case PORE_D1:

        // These are written as 64-bit registers in the model

        me = iv_interface->registerWrite(offset, i_data);
        break;

    case PORE_A0:
    case PORE_A1:

        // The programmer-writable portion of A0 and A1 are the low-order
        // 46 bits.

        me = iv_interface->registerWrite(offset, i_data & 0x3fffffffffffull);
        break;

    case PORE_P0:
    case PORE_P1:

        // The programmer-visible portion is bits 25:31, the remainder is
        // undefined.

        me = iv_interface->registerWrite(offset, (i_data & 0x7f) << 32);
        break;

    case PORE_CTR:

        // The programmer-visible portion is bits 8:31, the remainder is
        // undefined. 

        me = iv_interface->registerWrite(offset, (i_data & 0xffffff) << 32);
        break;

    case PORE_EMR:

        // The programmer-visible portion is bits 0:20

        me = iv_interface->registerWrite(offset,
                                         i_data & 0xfffff80000000000ull);
        break;

    case PORE_SPRG0:

        // These register moves the low-order 32 bits of the data to the
        // high-order bits of the target.

        me = iv_interface->registerWrite(offset, (i_data & 0xffffffff) << 32);
        break;

    case PORE_IFR:

        // Only bits 48:55 of the IFR (the ALU flags) are writable.

        me = iv_interface->registerWrite(offset, i_data & 0xff00ull);
        break;

    case PORE_ETR:

        // Only the low-order 32 bits are writable
        
        me = iv_interface->registerWrite(PORE_EXE_TRIGGER_HI, i_data, 4);
        break;

    default:
        me = ME_BUG;
        break;
    }
    if (me != 0) {
        iv_interface->modelError(me);
    }
    return i_data;
}


uint64_t 
PoreRegisterWritable::operator=(const uint64_t& i_data)
{
    return write(i_data);
}


////////////////////////////////////////////////////////////////////////////
// PoreDataBuffer
////////////////////////////////////////////////////////////////////////////

PoreDataBuffer::PoreDataBuffer(PoreInterface* i_interface, 
                               const PoreRegisterEncoding i_encoding) :
    PoreRegisterWritable(i_interface, i_encoding)
{
}


PoreDataBuffer::~PoreDataBuffer()
{
}


bool
PoreDataBuffer::isBitSet(const uint32_t i_bit)
{
    return (read() & BE64_BIT(i_bit)) != 0;
}


bool
PoreDataBuffer::isBitClear(const uint32_t i_bit)
{
    return (read() & BE64_BIT(i_bit)) == 0;
}


uint64_t 
PoreDataBuffer::extractToRight(const uint32_t i_start,
                               const uint32_t i_len)
{
    return BE64_GET_FIELD(read(), i_start, (i_start + i_len - 1));
}


// This needs to be replicated here for obscure C++ reasons
uint64_t 
PoreDataBuffer::operator=(const uint64_t& i_data)
{
    return write(i_data);
}


uint64_t 
PoreDataBuffer::setBit(const uint32_t i_bit)
{
    return write(read() | BE64_BIT(i_bit));
}


uint64_t 
PoreDataBuffer::clearBit(const uint32_t i_bit)
{
    return write(read() & ~BE64_BIT(i_bit));
}
    
uint64_t 
PoreDataBuffer::insertFromRight(const uint64_t i_data,
                                const uint32_t i_start,
                                const uint32_t i_len)
{
    return write(BE64_SET_FIELD(read(), i_start, (i_start + i_len - 1), 
                                i_data));
}
