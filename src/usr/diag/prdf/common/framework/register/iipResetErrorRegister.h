/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/framework/register/iipResetErrorRegister.h $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2020                        */
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

#ifndef iipResetErrorRegister_h
#define iipResetErrorRegister_h

/**
 @file iipResetErrorRegister.h
 @brief ResetErrorRegister declaration
*/

// Class Description *************************************************
//
//  Name:  ResetErrorRegister
//  Base class: ErrorRegisterMask
//
//  Description: Reset the error register after analysis by turning off
//               the bits in the SCR that were used for the analysis
//  Usage: Initialization
//   ScanCommRegisterChip scr1(...), scr2(...);
//   ResolutionMap rm(...);
//     *** Reset SCR same as One used to read error reg ***
//   ErrorRegister * er = new ResetErrorRegister(scr1,rm);
//
//     *** Reset SCR different from one used to read error reg ***
//   ErrorRegister * er1 = new ResetErrorRegister(scr1,rm,scr2);
//
//     *** Using a Filter ****
//  FilterClass * f =  new PriorityFilter(...);
//  ErrorRegister * er = new ResetErrorRegister(scr1,rm,f);
//  ErrorRegister *er1 = new ResetErrorRegister(scr1,rm,scr2,f);
//
//  Regular usage same as ErrorRegister
//
//  RESET:
//     if scr2 is not given then turn off bits in scr1 specified by bit_list
//             and scr1.Write();
//     if scr2 then copy bitlist from scr1 to scr2 then set off bits
//                  in scr2 specified by bit_list  then scr2.Write();
//
// End Class Description *********************************************
//--------------------------------------------------------------------
// Includes
//--------------------------------------------------------------------

#ifndef iipErrorRegisterMask_h
#include <iipErrorRegisterMask.h>
#endif

#include <vector>
#include <prdfResetOperators.H>

namespace PRDF
{

//--------------------------------------------------------------------
//  Forward References
//--------------------------------------------------------------------

class ResetErrorRegister : public ErrorRegisterMask
{
public:
  /**
   Constructor
   <ul>
   <br><b>Parameter:   </b> Scan comm register associated with the error register
   <br><b>Parameter:   </b> ResolutionMap
   <br><b>Parameter:   </b> Optional filter
   <br><b>Parameter:   </b> Optional scrId - to use in the error signature
   <br><b>Notes:       </b> If no scrId is provided than the address of the scan comm register is used
   </ul><br>
   */
  ResetErrorRegister(SCAN_COMM_REGISTER_CLASS & r, ResolutionMap & rm, FILTER_CLASS * f = nullptr, uint16_t scrID = 0x0fff, SCAN_COMM_REGISTER_CLASS & maskScr = *((SCAN_COMM_REGISTER_CLASS *) nullptr));

  /**
   Constructor
   <ul>
   <br><b>Parameter:   </b> Scan comm register associated with the error register
   <br><b>Parameter:   </b> ResolutionMap
   <br><b>Parameter:   </b> scrId - used in the error signature
   <br><b>Notes:       </b> If no scrId is provided than the address of the scan comm register is used
   </ul><br>
   */
  ResetErrorRegister(SCAN_COMM_REGISTER_CLASS & r, ResolutionMap & rm, uint16_t scrID, SCAN_COMM_REGISTER_CLASS & maskScr = *((SCAN_COMM_REGISTER_CLASS *) nullptr));

  /**
   Constructor - Where scan comm register to read is different from the scan comm register to write to reset
   <ul>
   <br><b>Parameter:   </b> Scan comm register associated with the error register
   <br><b>Parameter:   </b> ResolutionMap
   <br><b>Parameter:   </b> Scan comm register to write to reset the error
   <br><b>Parameter:   </b> Optional filter
   <br><b>Parameter:   </b> Optional scrId - to use in the error signature
   <br><b>Notes:       </b> If no scrId is provided than the address of the scan comm register is used
   </ul><br>
   */
  ResetErrorRegister(SCAN_COMM_REGISTER_CLASS & r, ResolutionMap & rm, SCAN_COMM_REGISTER_CLASS & reset, FILTER_CLASS * f = nullptr, uint16_t scrID = 0x0fff);

  /**
   Constructor - Where scan comm register to read is different from the scan comm register to write to reset
   <ul>
   <br><b>Parameter:   </b> Scan comm register associated with the error register
   <br><b>Parameter:   </b> ResolutionMap
   <br><b>Parameter:   </b> Scan comm register to write to reset the error
   <br><b>Parameter:   </b> scrId - to use in the error signature
   <br><b>Notes:       </b> If no scrId is provided than the address of the scan comm register is used
   </ul><br>
   */
  ResetErrorRegister(SCAN_COMM_REGISTER_CLASS & r, ResolutionMap & rm, SCAN_COMM_REGISTER_CLASS & reset, uint16_t scrID);

  // Function Specification ********************************************
  //
  // Purpose:      Destruction
  // Parameters:   None.
  // Returns:      No value returned
  // Requirements: None.
  // Promises:     None.
  // Exceptions:   None.
  // Concurrency:  Reentrant
  // Notes:        Compiler default is sufficient
  //
  // End Function Specification ****************************************
  //~ResetErrorRegister();

protected:  // functions

  /**
   Reset the error register and set mask bit if sdc is at threshold
   <ul>
   <br><b>Parameters:  </b> BitList
   <br><b>Returns:     </b> return code
   <br><b>Requirements:</b> Filter()
   <br><b>Promises:    </b> bitStringMask bit(s) set if error.service_data->IsAtThreshold()
                            Hardware modified
   <br><b>Exceptions:  </b> None
   <br><b>Notes:       </b> Zeros written to hardware
   </ul><br>
   */
  virtual int32_t Reset(const BIT_LIST_CLASS & bit_list, STEP_CODE_DATA_STRUCT & error);

private: // functions

  /** Copy prohibited */
  ResetErrorRegister(const ResetErrorRegister & er);
  /** Assignment prohibited */
  ResetErrorRegister & operator=(const ResetErrorRegister & er);

private:  // Data

  SCAN_COMM_REGISTER_CLASS * resetScr;

};


inline
ResetErrorRegister::ResetErrorRegister(SCAN_COMM_REGISTER_CLASS & r,
                                       ResolutionMap & rm,
                                       FILTER_CLASS * f,
                                       uint16_t scrId,
                                       SCAN_COMM_REGISTER_CLASS & maskScr)
: ErrorRegisterMask(r,rm,f,scrId,maskScr), resetScr(&r)
{}

inline
ResetErrorRegister::ResetErrorRegister(SCAN_COMM_REGISTER_CLASS & r,
                                       ResolutionMap & rm,
                                       SCAN_COMM_REGISTER_CLASS & reset,
                                       FILTER_CLASS * f,
                                       uint16_t scrId)
: ErrorRegisterMask(r,rm,f,scrId), resetScr(&reset)
{}

inline
ResetErrorRegister::ResetErrorRegister(SCAN_COMM_REGISTER_CLASS & r,
                                       ResolutionMap & rm,
                                       uint16_t scrId,
                                       SCAN_COMM_REGISTER_CLASS & maskScr)
: ErrorRegisterMask(r,rm,scrId,maskScr), resetScr(&r)
{}

inline
ResetErrorRegister::ResetErrorRegister(SCAN_COMM_REGISTER_CLASS & r,
                                       ResolutionMap & rm,
                                       SCAN_COMM_REGISTER_CLASS & reset,
                                       uint16_t scrId)
: ErrorRegisterMask(r,rm,scrId), resetScr(&reset)
{}


/**
 * @class ResetAndMaskErrorRegister
 * ErrorRegister to reset and mask errors.
 *
 * Similar to ResetErrorRegister, but adds mask capability and multiple
 * reset/mask registers.
 *
 * Will do masking if isAtThreshold().
 */
class ResetAndMaskErrorRegister : public ErrorRegisterMask
{
    public:
        /**
         * @struct ResetRegisterStruct
         * Stores information required to do reset/mask.
         */
        struct ResetRegisterStruct
        {
            RegisterResetOperator * op;
            SCAN_COMM_REGISTER_CLASS * read;
            SCAN_COMM_REGISTER_CLASS * write;

            bool operator<(const ResetRegisterStruct & rhs) const
            {
                if (this->op != rhs.op)
                    return (this->op < rhs.op);
                else if (this->read != rhs.read)
                    return (this->read < rhs.read);
                else
                    return (this->write < rhs.write);
            };

            bool operator==(const ResetRegisterStruct & rhs) const
            {
                return (this->op == rhs.op) &&
                       (this->read == rhs.read) &&
                       (this->write == rhs.write);
            };
        };

        typedef std::vector<ResetRegisterStruct> ResetRegisterVector;

    public:
        /**
         * Constructor
         * @param r : Register for error isolation.
         * @param rm : Resolution map for error.
         * @param f : Register filter.
         * @param scrId : ScanComm register ID.
         */
        ResetAndMaskErrorRegister(SCAN_COMM_REGISTER_CLASS & r,
                                  ResolutionMap & rm,
                                  FILTER_CLASS * f = nullptr,
                                  uint16_t scrId = 0x0fff)
            : ErrorRegisterMask(r, rm, f, scrId), cv_resets(), cv_masks() {};

        /**
         * Constructor
         * @param r : Register for error isolation.
         * @param rm : Resolution map for error.
         * @param scrId : ScanComm register ID.
         */
        ResetAndMaskErrorRegister(SCAN_COMM_REGISTER_CLASS & r,
                                  ResolutionMap & rm,
                                  uint16_t scrId = 0x0fff)
            : ErrorRegisterMask(r, rm, scrId), cv_resets(), cv_masks() {};

        /**
         * Add additional reset register to list.
         */
        void addReset(ResetRegisterStruct i_reset)
                { cv_resets.push_back(i_reset); };

        /**
         * Add additional mask register to list.
         */
        void addMask(ResetRegisterStruct i_mask)
                { cv_masks.push_back(i_mask); };

    protected:
        /**
         * Reset/Mask error after error isolation.
         *
         * @param bl : bit list of errors detected.
         * @param sdc : current STEP_CODE.
         */
        virtual int32_t Reset(const BIT_LIST_CLASS & bl,
                              STEP_CODE_DATA_STRUCT & sdc);

    private:
        // prohibit copy, assignment.
        ResetAndMaskErrorRegister(const ResetAndMaskErrorRegister &);
        ResetAndMaskErrorRegister& operator=(const ResetAndMaskErrorRegister&);

    private:

        /**
         * List of resets.
         */
        ResetRegisterVector cv_resets;
        /**
         * List of masks.
         */
        ResetRegisterVector cv_masks;
};

} // end namespace PRDF

#endif /* iipResetErrorRegister_h */
