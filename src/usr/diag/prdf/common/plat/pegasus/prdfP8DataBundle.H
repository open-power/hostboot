/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/pegasus/prdfP8DataBundle.H $    */
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

#ifndef __prdfP8DataBundle_H
#define __prdfP8DataBundle_H

/** @file  prdfP8DataBundle.H
 *  @brief Contains the data bundle for a P8 MCS object.
 */

#include <iipSystem.h>
#include <prdfExtensibleChip.H>
#include <prdfGlobal.H>
#include <prdfPlatServices.H>
//#include <prdfTrace.H>

namespace PRDF
{

/**
 * @brief The P8 data bundle.
 */
class P8DataBundle : public DataBundle
{
  public: // functions

      /*
       * @brief  Proc PLL chiplet types
       */
      enum ChipletType
      {
          ABUS,
          EX,
          PB,
      };

      /*
       * @brief  Proc PLL Error Reg data structure
       */
      struct PllErrReg
      {
          ExtensibleChip * chip;
          ChipletType type;
          SCAN_COMM_REGISTER_CLASS * errReg;
          SCAN_COMM_REGISTER_CLASS * configReg;
          PllErrReg() : chip(NULL), errReg(NULL), configReg(NULL) {}
      };

      typedef std::vector<PllErrReg>  ProcPllErrRegList;
      typedef ProcPllErrRegList::iterator ProcPllErrRegListIter;


    /**
     * @brief Constructor.
     * @param i_chip The P8 chip.
     */
    explicit P8DataBundle( ExtensibleChip * i_chip )
    {}

    /**
     * @brief Destructor.
     */
    ~P8DataBundle() {}

    /**
     * @brief get a list of Proc PLL Error reg data
     * @return returns a list of Proc PLL Error reg data
     */
    ProcPllErrRegList & getProcPllErrRegList()
    {
        return iv_procPllErrRegList;
    }

  private: // functions

    P8DataBundle( const P8DataBundle & );
    const P8DataBundle & operator=( const P8DataBundle & );

  private: // instance variables

    ProcPllErrRegList iv_procPllErrRegList;

};

//------------------------------------------------------------------------------

/**
 * @brief  Wrapper function for the P8DataBundle.
 * @param  i_chip The P8 chip.
 * @return This P8's data bundle.
 */
inline P8DataBundle * getDataBundle( ExtensibleChip * i_chip )
{
    return static_cast<P8DataBundle *>(i_chip->getDataBundle());
}

} // end namespace PRDF

#endif // __prdfP8DataBundle_H

