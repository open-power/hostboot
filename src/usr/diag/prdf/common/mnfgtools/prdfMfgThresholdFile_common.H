/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/mnfgtools/prdfMfgThresholdFile_common.H $ */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013                   */
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

#ifndef __PRDFMFGTHRESHOLDFILECOMMON
#define __PRDFMFGTHRESHOLDFILECOMMON

#include <stdint.h>
#include <map>

#ifdef __HOSTBOOT_MODULE

  // FIXME: RTC 73204 was opened to add support for these in hostboot. They will
  //        need to be removed once the issue has been resolved.
  #ifndef htonl
    #define htonl(foo) (foo)
  #endif

  #ifndef ntohl
    #define ntohl(foo) (foo)
  #endif

#else

  #include <netinet/in.h>

#endif


namespace PRDF
{

class MfgThresholdFileCommon
{
    public:

        /**
         *  @brief Structure of threshold to sync
        */
        struct SyncThreshold_t
        {
            uint32_t hash;
            uint8_t  value;
            SyncThreshold_t()
            {
                hash  = 0;
                value = 0;
            }
        }__attribute__ ((packed));

        /**
         *  @brief threshold map
        */
        typedef std::map<uint32_t, uint8_t> Threshold_t;

        /**
         *  @brief constructor
        */
        MfgThresholdFileCommon() {};

        /**
         *  @brief destructor
        */
        virtual ~MfgThresholdFileCommon() {};

        /**
         *  @brief configure MfgThresholdFile
        */
        virtual void setup() = 0;

        /**
         * @brief get threshold value from name
         * @param[in] i_thrName - threshold name
         *
         * @return corresponding threshold value
         */
        int getThreshold(uint32_t i_thrName);

        /**
         * @brief set threshold name/value
         * @param[in] i_thrName - threshold name
         * @param[in] i_value - threshold value
         */
        void setThreshold(uint32_t i_thrName, uint8_t i_value);

        /**
         * @brief clear all thresholds
         *
         */
        void clearThresholds();

        /**
         * @brief get number of thresholds
         *
         * @return number of predefined thresholds
         */
        inline uint32_t getThresholdSize()
        {
            return iv_thresholds.size() * sizeof(SyncThreshold_t);
        }

        /**
         * @brief serialize threshold data into data buffer
         * @param[in/out] o_buffer - data buffer
         * @param[in] i_sizeOfBuf - size of buffer
         */
        virtual void packThresholdDataIntoBuffer(
                                        uint8_t* & o_buffer,
                                        uint32_t i_sizeOfBuf) = 0;

        /**
         * @brief deserialize data buffer into threshold data
         * @param[in/out] o_buffer - data buffer
         * @param[in] i_sizeOfBuf - size of buffer
         */
        virtual void unpackThresholdDataFromBuffer(
                                        uint8_t* & o_buffer,
                                        uint32_t i_sizeOfBuf);

    protected:

        Threshold_t iv_thresholds;

};

} // end namespace PRDF

#endif
