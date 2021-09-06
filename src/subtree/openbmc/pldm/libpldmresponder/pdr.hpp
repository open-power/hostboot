#pragma once

#include "common/utils.hpp"
#include "libpldmresponder/pdr_utils.hpp"

#include <stdint.h>

namespace pldm
{

namespace responder
{

namespace pdr
{

constexpr uint8_t BmcMctpEid = 8;
constexpr uint8_t BmcPldmTerminusHandle = 1;
constexpr uint8_t BmcTerminusId = 1;

/** @brief Build (if not built already) and retrieve PDR by the PDR types
 *
 *  @param[in] dir - directory housing platform specific PDR JSON files
 *  @param[in] pdrType - the type of PDRs
 *
 *  @return Repo - Instance of pdr::Repo
 */
void getRepoByType(const pldm::responder::pdr_utils::Repo& inRepo,
                   pldm::responder::pdr_utils::Repo& outRepo,
                   pldm::responder::pdr_utils::Type pdrType);

/** @brief Get the record of PDR by the record handle
 *
 *  @param[in] pdrRepo - pdr::RepoInterface
 *  @param[in] recordHandle - The recordHandle value for the PDR to be
 * retrieved.
 *  @param[out] pdrEntry - PDR entry structure reference
 *
 *  @return pldm_pdr_record - Instance of pdr::RepoInterface
 */
const pldm_pdr_record*
    getRecordByHandle(const pldm::responder::pdr_utils::RepoInterface& pdrRepo,
                      pldm::responder::pdr_utils::RecordHandle recordHandle,
                      pldm::responder::pdr_utils::PdrEntry& pdrEntry);

} // namespace pdr
} // namespace responder
} // namespace pldm
