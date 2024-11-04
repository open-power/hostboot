#include "common/utils.hpp"
#include "libpldmresponder/oem_handler.hpp"

#include <libpldm/pdr.h>

#include <nlohmann/json.hpp>
#include <phosphor-logging/lg2.hpp>

#include <filesystem>
#include <fstream>
#include <map>
#include <string>
#include <vector>

PHOSPHOR_LOG2_USING;

namespace pldm
{
namespace hostbmc
{
namespace utils
{

/** @brief Vector a entity name to pldm_entity from entity association tree
 *  @param[in]  entityAssoc    - Vector of associated pldm entities
 *  @param[in]  entityTree     - entity association tree
 *  @param[out] objPathMap     - maps an object path to pldm_entity from the
 *                               BMC's entity association tree
 *  @return
 */
void updateEntityAssociation(
    const pldm::utils::EntityAssociations& entityAssoc,
    pldm_entity_association_tree* entityTree,
    pldm::utils::ObjectPathMaps& objPathMap, pldm::utils::EntityMaps entityMaps,
    pldm::responder::oem_platform::Handler* oemPlatformHandler);

/** @brief Parsing entity to DBus string mapping from json file
 *
 *  @param[in]  filePath - JSON file path for parsing
 *
 *  @return returns the entity to DBus string mapping object
 */
pldm::utils::EntityMaps parseEntityMap(const fs::path& filePath);

} // namespace utils
} // namespace hostbmc
} // namespace pldm
