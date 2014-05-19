/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/test/prdsimSignatureParser.H $              */
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

#ifndef SimSignatureParser_H
#define SimSignatureParser_H

//--------------------------------------------------------------------
// Includes
//--------------------------------------------------------------------

#include <vector>
using std::vector;
#include <stdint.h>

#include <iipconst.h>

namespace PRDF
{

/**
 *  @brief Singleton to access the only prdfScomService
 */
//class SimSignatureParser;
//PRDF_DECLARE_SINGLETON(SimSignatureParser, theSimSignatureParser);

//--------------------------------------------------------------------
//  Forward References
//--------------------------------------------------------------------
class SimSignatureParser
{
public:
  SimSignatureParser() {};
  // default dtor is ok
  void Add(uint32_t i_chip, uint32_t i_sig);
  void Report(uint32_t i_chip, uint32_t i_sig);
  bool Summary();


  class Signature
  {
  public:
    Signature(uint32_t ichip = 0, uint32_t icode = 0) : chip(ichip), code(icode) {}
    PRDF::HUID chip;
    uint32_t code;
    bool operator!=(const Signature & rsig)
    { return (chip != rsig.chip)||(code != rsig.code); }

  };

private:  // functions

  const char * Description(const Signature & signature);

private:  // Data

  typedef vector<Signature> SignatureList;

  SignatureList expectedSigList;
  SignatureList actualSigList;
//  EnumMap & iv_EnumMap;
};

} // End namespace PRDF

#endif /* SimSignatureParser_H */
