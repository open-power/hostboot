#pragma once

#include "libpldm/platform.h"

#include "pldmd/dbus_impl_requester.hpp"
#include "requester/handler.hpp"

#include <filesystem>
#include <fstream>
#include <map>

namespace pldm
{
namespace requester
{
namespace oem_ibm
{

/** @class DbusToFileHandler
 *  @brief This class can process resource dump parameters and send PLDM
 *         new file available cmd to the hypervisor. This class can be used
 *         as a pldm requester in oem-ibm path.
 */
class DbusToFileHandler
{
  public:
    DbusToFileHandler(const DbusToFileHandler&) = delete;
    DbusToFileHandler(DbusToFileHandler&&) = delete;
    DbusToFileHandler& operator=(const DbusToFileHandler&) = delete;
    DbusToFileHandler& operator=(DbusToFileHandler&&) = delete;
    ~DbusToFileHandler() = default;

    /** @brief Constructor
     *  @param[in] mctp_fd - fd of MCTP communications socket
     *  @param[in] mctp_eid - MCTP EID of host firmware
     *  @param[in] requester - pointer to a Requester object
     *  @param[in] resDumpCurrentObjPath - resource dump current object path
     *  @param[in] handler - PLDM request handler
     */
    DbusToFileHandler(
        int mctp_fd, uint8_t mctp_eid, dbus_api::Requester* requester,
        sdbusplus::message::object_path resDumpCurrentObjPath,
        pldm::requester::Handler<pldm::requester::Request>* handler);

    /** @brief Process the new resource dump request
     *  @param[in] vspString - vsp string
     *  @param[in] resDumpReqPass - resource dump password
     */
    void processNewResourceDump(const std::string& vspString,
                                const std::string& resDumpReqPass);

    /** @brief Process the new CSR file available
     *  @param[in] csr - CSR string
     *  @param[in] fileHandle - file Handle for  new file request
     */
    void newCsrFileAvailable(const std::string& csr,
                             const std::string fileHandle);

  private:
    /** @brief Send the new file available command request to hypervisor
     *  @param[in] fileSize - size of the file
     */
    void sendNewFileAvailableCmd(uint64_t fileSize);

    /** @brief Send the new file available command request to hypervisor
     *  @param[in] fileSize - size of the file
     *  @param[in] fileHandle - file handle
     *  @param[in] type - file type
     */
    void newFileAvailableSendToHost(const uint32_t fileSize,
                                    const uint32_t fileHandle,
                                    const uint16_t type);

    /** @brief report failure that a resource dump has failed
     */
    void reportResourceDumpFailure();

    /** @brief fd of MCTP communications socket */
    int mctp_fd;

    /** @brief MCTP EID of host firmware */
    uint8_t mctp_eid;

    /** @brief Pointer to a Requester object, primarily used to access API to
     *  obtain PLDM instance id.
     */
    dbus_api::Requester* requester;

    /** @brief Hold the current resource dump object path */
    sdbusplus::message::object_path resDumpCurrentObjPath;

    /** @brief PLDM request handler */
    pldm::requester::Handler<pldm::requester::Request>* handler;
};

} // namespace oem_ibm
} // namespace requester
} // namespace pldm
