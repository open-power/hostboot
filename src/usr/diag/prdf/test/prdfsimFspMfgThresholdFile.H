/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/test/prdfsimFspMfgThresholdFile.H $         */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2009,2013              */
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

#ifndef __PRDF_SimFspMfgThresholdFile_H
#define __PRDF_SimFspMfgThresholdFile_H

#include <prdfMfgThresholdFile.H>

namespace PRDF
{

class SimFspMfgThresholdFile : public MfgThresholdFile
{
    public:

        /**
         *  @brief constructor
        */
        SimFspMfgThresholdFile() {};

        /**
         *  @brief destructor
        */
        virtual ~SimFspMfgThresholdFile() {};

        /**
         * @brief serialize threshold data into data buffer
         * @param[in/out] o_buffer - data buffer
         * @param[in] i_sizeOfBuf - size of buffer
         */
        void packThresholdDataIntoBuffer(uint8_t* & o_buffer,
                                         uint32_t i_sizeOfBuf);

        void overrideThreshold();

    private:

};


} // end namespace PRDF

#endif
