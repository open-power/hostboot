/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/framework/resolution/prdfThresholdResolutions.H $ */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2003,2013              */
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

#ifndef PRDFTHRESHOLDRESOLUTIONS_H
#define PRDFTHRESHOLDRESOLUTIONS_H
/**
   @file prdfThresholdResolutions.H
   @brief MaskResolution, IntervalThresholdResolution, ResetThresholdResolution
*/


//--------------------------------------------------------------------
// Includes
//--------------------------------------------------------------------

#include <map>
#include <prdfErrorSignature.H>
#include <iipResolution.h>
#include <time.h>
#include <prdfTimer.H>

namespace PRDF
{

//--------------------------------------------------------------------
//  Forward References
//--------------------------------------------------------------------

/**
 Set mask Resolution
 @author Doug Gilbert
 @par
 @code
 @endcode
 */
class MaskResolution: public Resolution
{
  public:
    /**
     Constructor
     @param Maskid
     */
    MaskResolution(uint32_t maskId) : iv_maskId(maskId) {}

    /**
     Default Ctor - so it can be used in a vector
     */
    MaskResolution(void) : iv_maskId(0) {}

    /**
     Set MaskId into service data collector
     @pre None
     @post
     @return SUCCESS | non-zero
     @note Acts like Threshold Resolution with a threshold of one
     */
    virtual int32_t Resolve(STEP_CODE_DATA_STRUCT & error);

    virtual void ResetCount();          // wl01

    virtual int32_t GetCount();         // wl01

    /**
     operator ==
     */
    bool operator==(const MaskResolution &r) { return (iv_maskId == r.iv_maskId); } //dg02

  private:  // functions
  protected:  // Data
    uint32_t iv_maskId;

};

/**
 Set Mask on Threshold
 */
class ThresholdResolution : public MaskResolution
{
  public:

    enum TimeBase
    {
        ONE_SEC  = 1,
        ONE_MIN  = ONE_SEC  * 60,
        ONE_HOUR = ONE_MIN  * 60,
        ONE_DAY  = ONE_HOUR * 24,

        NONE = 0xffffffff,
    };

    struct ThresholdPolicy
    {
        // Currently we don't need threshold value more then 255. So using
        // uint8_t here to save space.
        uint8_t threshold;
        uint32_t interval;

        ThresholdPolicy( uint8_t l_threshold, uint32_t l_interval ) :
            threshold(l_threshold), interval(l_interval)
        {}

        ThresholdPolicy() :
            threshold(0), interval(0)
        {}

        bool operator==(ThresholdPolicy i_thr) const
        {
            return ( (threshold == i_thr.threshold) &&
                     (interval  == i_thr.interval) );
        }
    };

    /**
     Constructor
     @param maskid
     @param i_threshold
     @param i_interval
     */
    ThresholdResolution(uint32_t maskId, uint8_t i_threshold, uint32_t i_interval);

    /**
     default Ctor - so it can be used in a vector
     */
    ThresholdResolution(void);

    /**
     Constructor
     @param thresholdp Threshold policy.
     */
    ThresholdResolution(uint32_t maskId,
                        const ThresholdPolicy& thresholdp);

    /**
     Set MaskId into service data collector when a threshold as been reached
     @pre None
     @post Increment thresholdCount - Maskid is set in ServiceData when threshold is reached
     @return SUCCESS | non-zero
     @note In mfg mode the threshold is one
     */
    virtual int32_t Resolve(STEP_CODE_DATA_STRUCT & error);

    virtual void ResetCount();          // wl01

    virtual int32_t GetCount();         // wl01

    /**
     operator ==
     @note This should always return false in order for FlyWeight to always create unique objects
     */
    bool operator==(const ThresholdResolution &r) { return false; }

    /**
     *  Clear out all threshold policy objects
     */
    static void reset();

  public:  // Data

    static const ThresholdPolicy cv_fieldDefault;
    static const ThresholdPolicy cv_mnfgDefault;
    static const ThresholdPolicy cv_pllDefault;

  private: // Data

    // Though this is a pointer, we should never free it in destructor
    //We take its value from global flyweight which will be freed in prd uninitialise
    const ThresholdPolicy * iv_policy;
    uint32_t iv_count;
    Timer iv_endTime;

};

/**
 * @class ThresholdSigResolution
 *
 * Similar to the ThresholdResoultion, except it uses the current error
 * signature in the SDC to determine the 'maskid'.  This allows us to use one
 * ThresholdSigResolution class for each policy instead of one
 * ThresholdResolution for each error for each chip.
 */
class ThresholdSigResolution: public Resolution
{
    public:

        /** ctor(ThresholdPolicyEnum policy)
         *         Initializes the policy to the value specified.
         */
        ThresholdSigResolution( uint8_t i_threshold, uint32_t i_interval);

        /** ctor(ThresholdPolicy* policy)
         *         Initializes the policy to the policy specified.
         */
        ThresholdSigResolution(const ThresholdResolution::ThresholdPolicy& policy);

        /** default ctor
         *         Initialize the policy to "Default".
         */
        ThresholdSigResolution();

        /** default dtor
         *        Does nothing special.
         */
        virtual ~ThresholdSigResolution() {};

        /** Resolve
         *        Increments the error count based on the current signature.  If
         *        error count is over the policy limits, sets mask id and
         *        AT_THRESHOLD flag and then resets the error count.
         */
        virtual int32_t Resolve(STEP_CODE_DATA_STRUCT & error);

        /** operator==
         *        Compare two ThresholdSigResolutions by policies.
         */
        bool operator==(const ThresholdSigResolution &r)
        {
            return ( (r.iv_policy->threshold == iv_policy->threshold) &&
                     (r.iv_policy->interval  == iv_policy->interval) );
        }

        /** Flush
         *         Clear out all error counts recorded for all signatures.
         */
        virtual void Flush() { iv_thresholds.empty(); };

    private:

        // Stores a count/timer pair.
        typedef std::pair<uint32_t, Timer> ThresholdCountAndTimer;

        // Policy for this object.
        // Though this is a pointer, we should never free it in destructor
        // We take its value from global flyweight which will be freed in prd uninitialise
        const ThresholdResolution::ThresholdPolicy * iv_policy;

        // Map of ErrorSignatures->(Count,Timer).
        std::map<ErrorSignature, ThresholdCountAndTimer> iv_thresholds;

};

} // end namespace PRDF

#endif /* PRDFTHRESHOLDRESOLUTIONS_H */

