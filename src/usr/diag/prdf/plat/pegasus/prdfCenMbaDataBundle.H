/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/plat/pegasus/prdfCenMbaDataBundle.H $       */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2013              */
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

#ifndef PRDF_CEN_MBA_DATABUNDLE_H
#define PRDF_CEN_MBA_DATABUNDLE_H

/** @file  prdfCenMbaDataBundle.H
 *  @brief Contains the data bundle for a PRD Centaur MBA object.
 */

#include <prdfCenMbaDataBundle_common.H>

//------------------------------------------------------------------------------

namespace PRDF
{

/**
 * @brief The P7 Centaur MBA data bundle.
 */
class CenMbaDataBundle : public CenMbaDataBundleCommon
{
  public: // functions

    /**
     * @brief Constructor.
     * @param i_mbaChip The MBA chip.
     */
    explicit CenMbaDataBundle( ExtensibleChip * i_mbaChip ) :
        CenMbaDataBundleCommon( i_mbaChip ), iv_sendCmdCompleteMsg(false)
    {
    }

    /**
     * @brief Destructor.
     */
    ~CenMbaDataBundle()
    {
    }

  private: // functions

    CenMbaDataBundle( const CenMbaDataBundle & );
    const CenMbaDataBundle & operator=( const CenMbaDataBundle & );

  public: // instance variables

    /** TRUE if a maintenance command complete message needs to be sent in the
     *  post analysis plugin, FALSE otherwise. */
    bool iv_sendCmdCompleteMsg;

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

