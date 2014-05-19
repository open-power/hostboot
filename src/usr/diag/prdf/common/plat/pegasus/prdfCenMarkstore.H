/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/pegasus/prdfCenMarkstore.H $    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013,2014              */
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

#ifndef prdfCenMarkstore_H
#define prdfCenMarkstore_H

/** @file prdfCenMarkstore.H */

#include <prdfCenAddress.H>
#include <prdfCenConst.H>
#include <prdfCenSymbol.H>
#include <prdfTargetFwdRef.H>

//##############################################################################
//                           class CenMark
//##############################################################################

namespace PRDF
{

/**
 * @brief Container for a memory symbol and chip mark.
 * @note  When reading and writing markstore the symbol and chip marks are set
 *        or returned as a pair. This is a simple container to keep the two
 *        marks bundled.
 */
class CenMark
{
  public: // constructors

    /** @brief Default constructor */
    CenMark() :
        iv_symbolMark(), iv_chipMark()
    {}

    /** @brief Constructor from components */
    CenMark( const CenSymbol & i_symbolMark, const CenSymbol & i_chipMark ) :
        iv_symbolMark(i_symbolMark), iv_chipMark(i_chipMark)
    {}

  public: // functions

    /** @return A symbol representing the symbol mark. */
    CenSymbol getSM() const { return iv_symbolMark; }

    /** @return A symbol representing the chip mark. */
    CenSymbol getCM() const { return iv_chipMark; }

    /** @brief Sets the symbol mark to the given symbol. */
    void setSM( const CenSymbol & i_symbolMark )
    { iv_symbolMark = i_symbolMark; }

    /** @brief Sets the chip mark to the given symbol. */
    void setCM( const CenSymbol & i_chipMark ) { iv_chipMark = i_chipMark; }

    /** @brief Sets the symbol mark to an invalid symbol. */
    void clearSM() { iv_symbolMark = CenSymbol(); }

    /** @brief Sets the chip mark to an invalid symbol. */
    void clearCM() { iv_chipMark = CenSymbol(); }

  private: // instance variables

    CenSymbol iv_symbolMark;  ///< A symbol representing the symbol mark.
    CenSymbol iv_chipMark;    ///< A symbol representing the chip mark.

};

} // end namespace PRDF

#endif // prdfCenMarkstore_H

