#pragma once

#include "libpldmresponder/oem_handler.hpp"

#include <cstdint>
#include <string>
#include <vector>

namespace pldm
{
namespace responder
{
namespace utils
{

/** @brief Setup UNIX socket
 *  This function creates listening socket in non-blocking mode and allows only
 *  one socket connection. returns accepted socket after accepting connection
 *  from peer.
 *
 *  @param[in] socketInterface - unix socket path
 *  @return   on success returns accepted socket fd
 *            on failure returns -1
 */
int setupUnixSocket(const std::string& socketInterface);

/** @brief Write data on UNIX socket
 *  This function writes given data to a non-blocking socket.
 *  Irrespective of block size, this function make sure of writing given data
 *  on unix socket.
 *
 *  @param[in] sock - unix socket
 *  @param[in] buf -  data buffer
 *  @param[in] blockSize - size of data to write
 *  @return   on success returns  0
 *            on failure returns -1

 */
int writeToUnixSocket(const int sock, const char* buf,
                      const uint64_t blockSize);

/** @brief checks if given FRU is IBM specific
 *
 *  @param[in] objPath - FRU object path
 *
 *  @return bool - true if IBM specific FRU
 */
bool checkIfIBMFru(const std::string& objPath);

/** @brief finds the ports under an adapter
 *
 *  @param[in] adapterObjPath - D-Bus object path for the adapter
 *
 *  @return std::vector<std::string> - port object paths
 */
std::vector<std::string> findPortObjects(const std::string& adapterObjPath);

} // namespace utils

namespace oem_ibm_utils
{

class Handler : public oem_utils::Handler
{
  public:
    Handler(const pldm::utils::DBusHandler* dBusIntf) :
        oem_utils::Handler(dBusIntf), dBusIntf(dBusIntf)
    {}

    /** @brief Collecting core count data and setting to Dbus properties
     *
     *  @param[in] associations - the data of entity association
     *  @param[in] entityMaps - the mapping of entity to DBus string
     *
     */
    virtual int
        setCoreCount(const pldm::utils::EntityAssociations& associations,
                     const pldm::utils::EntityMaps entityMaps);

    virtual ~Handler() = default;

  protected:
    const pldm::utils::DBusHandler* dBusIntf;
};

} // namespace oem_ibm_utils
} // namespace responder
} // namespace pldm
