/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/mnfgtools/prdfMfgThresholdMgr.H $    */
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

#ifndef __PRDF_PRDFMFGTHRESHOLDMGR_H
#define __PRDF_PRDFMFGTHRESHOLDMGR_H

#ifdef __HOSTBOOT_MODULE
  #ifndef INT_MAX
    #define INT_MAX 0xFFFFFFFF // FIXME: defined here for now
  #endif
#else
  #include <limits>
#endif

#include <stdint.h>
#include <limits.h>                //  for INT_MAX
#include <prdfMfgThresholdFile.H>
#include <prdfThresholdResolutions.H>
#include <prdfFlyWeight.H>

namespace PRDF
{

class MfgThresholdMgr
{
    public:

        /**
         *  @brief constructor
        */
        MfgThresholdMgr();

        /**
         *  @brief destructor
        */
        virtual ~MfgThresholdMgr();

        /**
         * @brief get MfgThresholdMgr singleton
         *
         * @return MfgThresholdMgr singleton
         */
        static MfgThresholdMgr * getInstance();

        /**
         * @brief get threshold value from name
         * @param[in] i_thrName - threshold name
         *
         * @return corresponding threshold value
         */
        uint16_t getThreshold(uint32_t i_thrName);

        /**
         * @brief get threshold policy from name
         * @param[in] i_thrName - threshold name
         *
         * @return threshold policy
         */
        ThresholdResolution::ThresholdPolicy* getThresholdP(uint32_t i_thrName);

        /**
         *  @brief reset/clean up MfgThresholdMgr
        */
        void reset();

        /**
         * @brief get MfgThresholdFile
         *
         * @return MfgThresholdFile pointer
         */
        inline MfgThresholdFile * getMfgThresholdFile() { return iv_file; };


        /**
         *  @brief Infinite threshold enum
        */
        enum { INFINITE_LIMIT_THR = 0xffff };

    private:

        /**
         * @brief get default threshold value from name
         * @param[in] i_thrName - threshold name
         *
         * @return corresponding threshold value
         */
        uint16_t getThresholdDefault(uint32_t i_thrName);

        /**
         *  @brief set up MfgThresholdFile
        */
        virtual void setupFile();

        FlyWeight<ThresholdResolution::ThresholdPolicy, 10> iv_thrs;

        MfgThresholdFile * iv_file;
};

} // end namespace PRDF

#endif
