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
        MfgThresholdMgr();
        ~MfgThresholdMgr();

        static MfgThresholdMgr * getInstance();

        uint16_t getThreshold(uint32_t i_thrName);
        ThresholdResolution::ThresholdPolicy* getThresholdP(uint32_t i_thrName);

        void reset();

        enum { INFINITE_LIMIT_THR = 0xffff };

    private:
        uint16_t getThresholdDefault(uint32_t i_thrName);
        void setupFile();

        FlyWeight<ThresholdResolution::ThresholdPolicy, 10> iv_thrs;

        PRDF_MFG_THRESHOLD_FILE_DECLARE(iv_file);
};

} // end namespace PRDF

#endif
