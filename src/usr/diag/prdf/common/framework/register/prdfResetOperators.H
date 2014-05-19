/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/framework/register/prdfResetOperators.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2005,2014              */
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

/**
 * @file prdfResetOperators.H
 * Operator classes for enacting different reset and mask policies on a
 * register set.
 *
 * Defines RegisterResetOperator base class and a number of derived types.
 */

#ifndef __PRDFRESETOPERATORS_H
#define __PRDFRESETOPERATORS_H

#include <prdfBitKey.H>
#include <iipscr.h>
#include <iipconst.h>

namespace PRDF
{

/**
 * @class RegisterResetOperator
 * Interface class for reset operators.  (pure virtual)
 *
 * Provides a single interface, the reset "operator".  These operators are used
 * to enact specific reset or mask policies onto a register read/write pair.
 */
class RegisterResetOperator
{
    public:
        virtual ~RegisterResetOperator() { }  // zs01

        /**
         * Reset Operator
         *
         * @param bl : Bit list of registers to reset.
         * @param sdc : The current STEP_CODE information.
         * @param readReg : The ScanCOMM register to read bits from.
         * @param writeReg : The ScanCOMM register to update with reset/mask.
         */
        virtual
        int32_t Reset(const BIT_LIST_CLASS & bl,
                      STEP_CODE_DATA_STRUCT & sdc,
                      SCAN_COMM_REGISTER_CLASS * readReg,
                      SCAN_COMM_REGISTER_CLASS * writeReg) const = 0;
};

/**
 * @enum ResetOperatorBehaviors
 * Useful enum for defining operator templates which behave only slightly
 * different between masking and reseting.
 *
 * By using these enum types as parameters to the template (a bool) it makes
 * the template instantiation more understandable.
 */
enum ResetOperatorBehaviors
    {
        RESETOPERATOR_MASK = true,
        RESETOPERATOR_RESET = false
    };

/**
 * @fn getStaticResetOperator
 * Returns a pointer to a static reset operator of requested type.
 *
 * Example usage:
 *         getStaticResetOperator<OrOperator<RESETOPERATOR_MASK> >() will return
 *         a pointer to an Or-type operator which does masking (sets bits).
 */
template <class T>
T * getStaticResetOperator() { static T l_op; return &l_op; };

/**
 * @class OrOperator
 * Implements the 'or' behavior of a reset/mask operator.
 *
 * Template parameter determines if reset or mask.
 *
 * Behavior:
 *         Reset -
 *                 Read old bits.
 *                 Remove "reset" bits.
 *                 Write result.
 *         Mask -
 *                 Write "mask" bits.
 */
template <bool> class OrOperator;
// Typedefs for easier instantiation.
typedef OrOperator<RESETOPERATOR_MASK> OrMaskOperator;
typedef OrOperator<RESETOPERATOR_RESET> OrResetOperator;

// Class definition
template <bool Type>
class OrOperator : public RegisterResetOperator
{
    int32_t Reset(const BIT_LIST_CLASS & bl,
                      STEP_CODE_DATA_STRUCT & sdc,
                      SCAN_COMM_REGISTER_CLASS * readReg,
                      SCAN_COMM_REGISTER_CLASS * writeReg) const
    {
        int32_t rc = SUCCESS;

        uint32_t bl_length = bl.size();

        if(bl_length != 0) // Check for bits to reset
        {
            writeReg->clearAllBits();

            if (RESETOPERATOR_RESET == Type)
            {
                // Make sure this register was read.  (TODO: is this needed?)
                readReg->Read();

                if(readReg != writeReg)  // read different than write, move bits.
                {
                    writeReg->SetBitString(readReg->GetBitString());
                }
            }
            uint32_t i;
            for(i = 0; i < bl_length; ++i)  // Turn off all bits specified
            {
                if (RESETOPERATOR_MASK == Type)
                    writeReg->SetBit(bl.getListValue(i));
                else
                    writeReg->ClearBit(bl.getListValue(i));
            }
            rc = writeReg->Write();    // Write hardware
        }
        return rc;
    }
};

/**
 * @class AndOperator
 * Implements the 'and' behavior of a reset/mask operator.
 *
 * Template parameter determines if reset or mask.
 *
 * Behavior:
 *         Reset -
 *                Write not of bits.
 *         Mask -
 *                 Read mask register.
 *                 Set bits.
 *                 Write mask register.
 */
template <bool> class AndOperator;
// Typedefs for easier instantiation.
typedef AndOperator<RESETOPERATOR_MASK> AndMaskOperator;
typedef AndOperator<RESETOPERATOR_RESET> AndResetOperator;

// Class definition
template <bool Type>
class AndOperator : public RegisterResetOperator
{
    int32_t Reset(const BIT_LIST_CLASS & bl,
                      STEP_CODE_DATA_STRUCT & sdc,
                      SCAN_COMM_REGISTER_CLASS * readReg,
                      SCAN_COMM_REGISTER_CLASS * writeReg) const
    {
        int32_t rc = SUCCESS;
        uint32_t bl_length = bl.size();

        if (RESETOPERATOR_RESET == Type)
        {
            if(bl_length != 0) // Check for bits to reset
            {
                BIT_STRING_BUFFER_CLASS bs(writeReg->GetBitLength());
                bs.Pattern(0xffffffff, 32); // set all to 1's.

                uint32_t i;
                for(i = 0; i < bl_length; ++i)  // Turn off all bits specified
                {
                    bs.Clear(bl.getListValue(i));
                }
                writeReg->SetBitString(&bs); // Copy bit-string to register.
                rc = writeReg->Write();    // Write hardware
            }
        }
        else // RESETOPERATOR_MASK
        {
            // Make sure this register was read.  (TODO: is this needed?)
            readReg->Read();

            if(readReg != writeReg)  // read different than write, move bits.
            {
                writeReg->SetBitString(readReg->GetBitString());
            }
            for(uint32_t i = 0; i < bl_length; ++i)
            {
                writeReg->SetBit(bl.getListValue(i));
            }

            rc = writeReg->Write();
        }
        return rc;
    }
};


/**
 * @class XorOperator
 * Implements the 'xor' behavior of a reset/mask operator.
 *
 * Template parameter determines if reset or mask.
 *
 * Behavior:
 *         Reset - Write bit.
 *         Mask -  Clear bit.
 */
template <bool> class XorOperator;
// Typedefs for easier instantiation.
typedef XorOperator<RESETOPERATOR_MASK> XorMaskOperator;
typedef XorOperator<RESETOPERATOR_RESET> XorResetOperator;

// Class definition
template <bool Type>
class XorOperator : public RegisterResetOperator
{
    int32_t Reset(const BIT_LIST_CLASS & bl,
                      STEP_CODE_DATA_STRUCT & sdc,
                      SCAN_COMM_REGISTER_CLASS * readReg,
                      SCAN_COMM_REGISTER_CLASS * writeReg) const
    {
        int32_t rc = SUCCESS;
        uint32_t bl_length = bl.size();

        if (RESETOPERATOR_RESET == Type)
        {
            writeReg->clearAllBits();

            for (uint32_t i = 0; i < bl_length; ++i)
                writeReg->SetBit(bl.getListValue(i));

            rc = writeReg->Write();
        }
        else // RESETOPERATOR_MASK
        {
            // Make sure this register was read.  (TODO: is this needed?)
            readReg->Read();

            if(readReg != writeReg)  // read different than write, move bits.
            {
                writeReg->SetBitString(readReg->GetBitString());
            }
            for(uint32_t i = 0; i < bl_length; ++i)
            {
                writeReg->ClearBit(bl.getListValue(i));
            }

            rc = writeReg->Write();

        }
        return rc;
    }
};

/**
 * @class NotOperator
 * Implements the 'not' behavior of a reset/mask operator.
 *
 * Template parameter determines if reset or mask.
 *
 * Behavior:
 *         Reset - Clears all bits.
 *         Mask  - Sets all bits.
 */
template <bool> class NotOperator;
// Typedefs for easier instantiation.
typedef NotOperator<RESETOPERATOR_MASK> NotMaskOperator;
typedef NotOperator<RESETOPERATOR_RESET> NotResetOperator;

// Class definition
template <bool Type>
class NotOperator : public RegisterResetOperator
{
    int32_t Reset(const BIT_LIST_CLASS & bl,
                      STEP_CODE_DATA_STRUCT & sdc,
                      SCAN_COMM_REGISTER_CLASS * readReg,
                      SCAN_COMM_REGISTER_CLASS * writeReg) const
    {
        int32_t rc = SUCCESS;

        if (RESETOPERATOR_RESET == Type)
        {
            writeReg->clearAllBits();
            rc = writeReg->Write();    // Write hardware
        }
        else // RESETOPERATOR_MASK
        {
            BIT_STRING_BUFFER_CLASS bs(writeReg->GetBitLength());
            bs.Pattern(0xffffffff, 32); // set all to 1's.
            writeReg->SetBitString(&bs); // Copy bit-string to register.
            rc = writeReg->Write();    // Write hardware
        }
        return rc;
    }
};

} // end namespace PRDF

#endif

