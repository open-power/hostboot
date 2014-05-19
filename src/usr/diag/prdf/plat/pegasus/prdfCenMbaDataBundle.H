/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/plat/pegasus/prdfCenMbaDataBundle.H $       */
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

#ifndef PRDF_CEN_MBA_DATABUNDLE_H
#define PRDF_CEN_MBA_DATABUNDLE_H

/** @file  prdfCenMbaDataBundle.H
 *  @brief Contains the data bundle for a PRD Centaur MBA object.
 */

#include <prdfCenMbaDataBundle_common.H>

#include <diag/mdia/mdia.H>
#include <prdfCenMbaIplCeStats.H>

//------------------------------------------------------------------------------

namespace PRDF
{

/**
 * @brief Centaur MBA data bundle.
 */
class CenMbaDataBundle : public CenMbaDataBundleCommon
{
  public: // functions

    /**
     * @brief Constructor.
     * @param i_mbaChip The MBA chip.
     */
    explicit CenMbaDataBundle( ExtensibleChip * i_mbaChip ) :
        CenMbaDataBundleCommon(i_mbaChip), iv_sendCmdCompleteMsg(false),
        iv_cmdCompleteMsgData(), iv_iplCeStats(NULL)
    {}

    /**
     * @brief Destructor.
     */
    ~CenMbaDataBundle()
    {
        delete iv_iplCeStats; iv_iplCeStats = NULL;
    }

    /** @return The IPL CE statistics object. */
    CenMbaIplCeStats * getIplCeStats()
    {
        if ( NULL == iv_iplCeStats )
        {
            iv_iplCeStats = new CenMbaIplCeStats( iv_mbaChip );
        }

        return iv_iplCeStats;
    }

  private: // functions

    CenMbaDataBundle( const CenMbaDataBundle & );
    const CenMbaDataBundle & operator=( const CenMbaDataBundle & );

  public: // instance variables

    /** TRUE if a maintenance command complete message needs to be sent in the
     *  post analysis plugin, FALSE otherwise. */
    bool iv_sendCmdCompleteMsg;

    /**
     * Maintenance command message to send.
     */
    MDIA::MaintCommandEventType iv_cmdCompleteMsgData;

  private: // instance variables

    CenMbaIplCeStats * iv_iplCeStats; ///< MNFG IPL CE statistics object

};

//------------------------------------------------------------------------------

/**
 * @brief  Wrapper function for the CenMbaDataBundle.
 * @param  i_mbaChip The MBA chip.
 * @return This MBA's data bundle.
 */
inline CenMbaDataBundle * getMbaDataBundle( ExtensibleChip * i_mbaChip )
{
    return static_cast<CenMbaDataBundle *>(i_mbaChip->getDataBundle());
}

} // end namespace PRDF

#endif // PRDF_CEN_MBA_DATABUNDLE_H

