/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/pegasus/prdfCenMbaDataBundle_rt.H $ */
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

#ifndef __prdfCenMbaDataBundle_rt_H
#define __prdfCenMbaDataBundle_rt_H

/** @file  prdfCenMbaDataBundle_rt.H
 *  @brief Contains the data bundle for a PRD Centaur MBA object (runtime only).
 */

namespace PRDF
{

/**
 * @brief The Centaur MBA data bundle.
 */
class CenMbaDataBundle : public CenMbaDataBundleCommon
{
  public: // functions

    /**
     * @brief Constructor.
     * @param i_mbaChip The MBA chip.
     */
    explicit CenMbaDataBundle( ExtensibleChip * i_mbaChip ) :
        CenMbaDataBundleCommon(i_mbaChip)
    {}

    /**
     * @brief Destructor.
     */
    ~CenMbaDataBundle() {}

  private: // functions

    CenMbaDataBundle( const CenMbaDataBundle & );
    const CenMbaDataBundle & operator=( const CenMbaDataBundle & );

};

} // end namespace PRDF

#endif // __prdfCenMbaDataBundle_rt_H

