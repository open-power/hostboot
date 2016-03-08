/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/framework/prdfFileRegisterAccess.H $        */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016                             */
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

#ifndef PRDFFILEREGISTERACCESS_H
#define PRDFFILEREGISTERACCESS_H
/**
 * @file prdfFileRegisterAccess.H
 * @brief Provide access to scom registers via the File
*/


//--------------------------------------------------------------------
// Includes
//--------------------------------------------------------------------

#include <prdfHomRegisterAccess.H>


//--------------------------------------------------------------------
//  Forward References
//--------------------------------------------------------------------

namespace PRDF
{

class FileScomAccessor : public ScomAccessor
{
  public:

    /**
     * @brief ctor
     */
    FileScomAccessor() {};

    /**
     * @brief dtor
     */
    virtual ~FileScomAccessor() {};

    /**
     * Access the scom register using file.
     * @param i_target Target to access the register
     * @param BIT_STRING_CLASS - holds data read or to write
     * @param register address
     * @param [READ|WRITE]
     * @returns NULL if success, valid error handle otherwise
     * @pre bs.Length() must be size of register data to read/write
     */
    virtual errlHndl_t Access(TARGETING::TargetHandle_t i_target,
                            BIT_STRING_CLASS & bs,
                            uint64_t registerId,
                            MopRegisterAccess::Operation operation) const;
};

} // End namespace PRDF

#endif /* PRDFFILEREGISTERACCESS_H */
