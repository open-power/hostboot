/*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/include/usr/errl/errludcallout.H $
 *
 *  IBM CONFIDENTIAL
 *
 *  COPYRIGHT International Business Machines Corp. 2012
 *
 *  p1
 *
 *  Object Code Only (OCO) source materials
 *  Licensed Internal Code Source Materials
 *  IBM HostBoot Licensed Internal Code
 *
 *  The source code for this program is not published or other-
 *  wise divested of its trade secrets, irrespective of what has
 *  been deposited with the U.S. Copyright Office.
 *
 *  Origin: 30
 *
 *  IBM_PROLOG_END_TAG
 */
#ifndef ERRL_UDCALLOU_H
#define ERRL_UDCALLOU_H

/**
 *  @file errludcallout.H
 *
 *  Defines the following classes:
 *
 *  ErrlUserDetailsCallout: Adds register FFDC to an error log as
 *                                  user detail data
 *  ErrlUserDetailsParserCallout: Parses register FFDC user detail in
 *                                  an error log
*/

#include <errl/errluserdetails.H>

#ifndef PARSER

// Forward reference
namespace TARGETING
{
    class Target;
}

#include <hwas/common/hwasCallout.H>

namespace ERRORLOG
{

/**
 * @class ErrlUserDetailsCallout
 *
 * Adds Callout FFDC to an error log as user detail data
 */
class ErrlUserDetailsCallout : public ErrlUserDetails
{
public:

    /**
     *  @brief Construct a hardware callout user detail
     *
     *  @param[in]  i_pTargetData    The hardware target data
     *  @param[in]  i_targetDataLength    length of i_pTargetData
     *  @param[in]  i_priority      Priority of the callout
     *  @param [in] i_deconfigState Enum indicating whether the failing part
     *               should be deconfigured.
     *  @param [in] i_gardErrorType to indicate what type of failure occured
     *
     *  @return void
     */
    ErrlUserDetailsCallout(
                        const void *i_pTargetData,
                        uint32_t i_targetDataLength,
                        const HWAS::callOutPriority i_priority,
                        const HWAS::DeconfigEnum i_deconfigState,
                        const HWAS::GARD_ErrorType i_gardErrorType);

    /**
     *  @brief Add a procedure ( software ) callout
     *  Adds the given service procedure to the list
     *  of callouts for the log
     *
     *  @param[in]  i_procedure     Procedure identifier.
     *  @param[in]  i_priority      Priority of the callout
     *
     *  @return void
     */
    ErrlUserDetailsCallout(const HWAS::epubProcedureID i_procedure,
                        const HWAS::callOutPriority i_priority);
    /**
     *  @brief Destructor
     */
    virtual ~ErrlUserDetailsCallout() { };

private:
    // Disabled
    ErrlUserDetailsCallout(const ErrlUserDetailsCallout &);
    ErrlUserDetailsCallout & operator=(const ErrlUserDetailsCallout &);

};

}

#else // (if PARSER defined)

namespace ERRORLOG
{

/**
 * @class ErrlUserDetailsCallout
 *
 * Parses Callout user detail in an error log
*/
class ErrlUserDetailsParserCallout : public ErrlUserDetailsParser
{
public:
    /**
     *  @brief Constructor
     */
    ErrlUserDetailsParserCallout() {}

    /**
     *  @brief Destructor
     */
    virtual ~ErrlUserDetailsParserCallout() {}

    /**
     *  @brief Parses callout user detail data from an error log
     *
     *  @param  i_version Version of the data
     *  @param  i_parse   ErrlUsrParser object for outputting information
     *  @param  i_pBuffer Pointer to buffer containing detail data
     *  @param  i_buflen  Length of the buffer
     */
    virtual void parse(errlver_t i_version,
                       ErrlUsrParser & i_parser,
                       void * i_pBuffer,
                       const uint32_t i_buflen) const
    {
        // TODO fix when parser fixed
        // RTC 41707
    }

private:
    // Disabled
    ErrlUserDetailsParserCallout(const ErrlUserDetailsParserCallout &);
    ErrlUserDetailsParserCallout & operator=(
        const ErrlUserDetailsParserCallout &);
};

}

#endif

#endif

