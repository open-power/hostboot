/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/test/prdsimSignatureParser.H $              */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012                   */
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
  void Summary();


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
