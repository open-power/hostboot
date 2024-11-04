// SPDX-License-Identifier: Apache-2.0 OR GPL-2.0-or-later
#ifndef LIBPLDM_SRC_API_H
#define LIBPLDM_SRC_API_H

#include <libpldm/base.h>

#include <assert.h>
#include <errno.h>

/**
 * @brief Translate a negative errno value to a PLDM completion code
 *
 * Existing stable APIs often return errors in the form of PLDM completion
 * codes, which confuses the problems of the protocol with the problems of
 * the implementation. We're shifting to using negative errno values to signal
 * implementation errors. However, for existing stable APIs, provide a means to
 * translate between the two.
 *
 * @param[in] err - The negative errno to translate to a completion code
 *
 * @return An equivalent PLDM completion code for @p err
 */
static inline enum pldm_completion_codes pldm_xlate_errno(int err)
{
	enum pldm_completion_codes rc;

	assert(err < 0);
	switch (err) {
	case -EINVAL:
		rc = PLDM_ERROR_INVALID_DATA;
		break;
	case -ENOMSG:
		rc = PLDM_ERROR_INVALID_PLDM_TYPE;
		break;
	case -EBADMSG:
	case -EOVERFLOW:
		rc = PLDM_ERROR_INVALID_LENGTH;
		break;
	default:
		assert(false);
		rc = PLDM_ERROR;
		break;
	}

	assert(rc > 0);
	return rc;
}

#endif
