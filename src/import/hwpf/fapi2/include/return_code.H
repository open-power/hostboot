/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: hwpf/fapi2/include/return_code.H $                            */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* EKB Project                                                            */
/*                                                                        */
/* COPYRIGHT 2012,2016                                                    */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
/**
 * @file return_code.H
 * @brief definitions for fapi2 return codes
 */

#ifndef __FAPI2_RETURN_CODE__
#define __FAPI2_RETURN_CODE__

#include <stdint.h>

#ifndef FAPI2_NO_FFDC
    #include <ffdc.H>
#endif

namespace fapi2
{
///
/// @brief Class representing a FAPI2 ReturnCode
///
// Remove the inheritance relationship with FirstFailureData if
// the platform doesn't support FFDC.
#ifdef FAPI2_NO_FFDC
class ReturnCode
#else
class ReturnCode : public FirstFailureData<ReturnCode>
#endif
{
    public:

        ///
        /// @brief Constructor.
        /// @param[in] i_rc the rc to set
        ///
        ReturnCode(const uint64_t i_rc = FAPI2_RC_SUCCESS):
            iv_rc(i_rc)
        {};

        ///
        /// @brief integral type conversion function. Returns the error code
        /// @return The error code
        ///
        inline operator uint64_t() const
        {
            return iv_rc;
        }

        ///
        /// @brief Returns true iff iv_rc != SUCCESS
        /// @return true or false
        ///
        inline operator bool() const
        {
            return iv_rc != FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Assignement operator
        ///
#ifdef DOXYGEN
        inline ReturnCode& operator=(const uint64_t& rhs);
        inline ReturnCode& operator=(const ReturnCodes& rhs);
#endif

        inline bool operator==(const uint64_t& rhs) const
        {
            return rhs == iv_rc;
        }

        inline bool operator==(const ReturnCodes& rhs) const
        {
            return rhs == iv_rc;
        }

        inline bool operator!=(const uint64_t& rhs) const
        {
            return rhs != iv_rc;
        }

        inline bool operator!=(const ReturnCodes& rhs) const
        {
            return rhs != iv_rc;
        }

        ///
        /// @brief Enumeration of return code creators
        ///
        enum returnCodeCreator
        {
            CREATOR_FAPI = 1,
            CREATOR_PLAT = 2,
            CREATOR_HWP = 3,
        };

        ///
        /// @brief Gets the creator of the return code
        /// @return ReturnCodeCreator
        ///
        inline returnCodeCreator getCreator(void) const
        {
            returnCodeCreator l_creator = CREATOR_HWP;

            if (iv_rc & FAPI2_RC_FAPI2_MASK)
            {
                l_creator = CREATOR_FAPI;
            }
            else if (iv_rc & FAPI2_RC_PLAT_MASK)
            {
                l_creator = CREATOR_PLAT;
            }

            return l_creator;
        }

    private:
        uint64_t iv_rc;
};

/// This implementation assumes no exception handling and leverages thread-local
/// storage. For platforms without thread support, a global variable will
/// suffice for the error state.


extern thread_local uint64_t pib_error_mask;     /// the pib mask
extern thread_local uint64_t operational_state;  /// the operational mode
#ifndef PLAT_NO_THREAD_LOCAL_STORAGE
    extern thread_local ReturnCode current_err;      /// the current error state
#else
    extern ReturnCode current_err;
#endif

}

#endif
