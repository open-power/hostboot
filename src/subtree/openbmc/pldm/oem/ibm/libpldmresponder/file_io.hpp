#pragma once

#include "config.h"

#include "libpldm/base.h"
#include "oem/ibm/libpldm/file_io.h"
#include "oem/ibm/libpldm/host.h"

#include "common/utils.hpp"
#include "oem/ibm/requester/dbus_to_file_handler.hpp"
#include "oem_ibm_handler.hpp"
#include "pldmd/handler.hpp"
#include "requester/handler.hpp"

#include <fcntl.h>
#include <stdint.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#include <filesystem>
#include <iostream>
#include <vector>

namespace pldm
{
namespace responder
{
namespace dma
{

// The minimum data size of dma transfer in bytes
constexpr uint32_t minSize = 16;

constexpr size_t maxSize = DMA_MAXSIZE;

namespace fs = std::filesystem;

/**
 * @class DMA
 *
 * Expose API to initiate transfer of data by DMA
 *
 * This class only exposes the public API transferDataHost to transfer data
 * between BMC and host using DMA. This allows for mocking the transferDataHost
 * for unit testing purposes.
 */
class DMA
{
  public:
    /** @brief API to transfer data between BMC and host using DMA
     *
     * @param[in] path     - pathname of the file to transfer data from or to
     * @param[in] offset   - offset in the file
     * @param[in] length   - length of the data to transfer
     * @param[in] address  - DMA address on the host
     * @param[in] upstream - indicates direction of the transfer; true indicates
     *                       transfer to the host
     *
     * @return returns 0 on success, negative errno on failure
     */
    int transferDataHost(int fd, uint32_t offset, uint32_t length,
                         uint64_t address, bool upstream);

    /** @brief API to transfer data on to unix socket from host using DMA
     *
     * @param[in] path     - pathname of the file to transfer data from or to
     * @param[in] length   - length of the data to transfer
     * @param[in] address  - DMA address on the host
     *
     * @return returns 0 on success, negative errno on failure
     */
    int transferHostDataToSocket(int fd, uint32_t length, uint64_t address);
};

/** @brief Transfer the data between BMC and host using DMA.
 *
 *  There is a max size for each DMA operation, transferAll API abstracts this
 *  and the requested length is broken down into multiple DMA operations if the
 *  length exceed max size.
 *
 * @tparam[in] T - DMA interface type
 * @param[in] intf - interface passed to invoke DMA transfer
 * @param[in] command  - PLDM command
 * @param[in] path     - pathname of the file to transfer data from or to
 * @param[in] offset   - offset in the file
 * @param[in] length   - length of the data to transfer
 * @param[in] address  - DMA address on the host
 * @param[in] upstream - indicates direction of the transfer; true indicates
 *                       transfer to the host
 * @param[in] instanceId - Message's instance id
 * @return PLDM response message
 */

template <class DMAInterface>
Response transferAll(DMAInterface* intf, uint8_t command, fs::path& path,
                     uint32_t offset, uint32_t length, uint64_t address,
                     bool upstream, uint8_t instanceId)
{
    uint32_t origLength = length;
    Response response(sizeof(pldm_msg_hdr) + PLDM_RW_FILE_MEM_RESP_BYTES, 0);
    auto responsePtr = reinterpret_cast<pldm_msg*>(response.data());

    int flags{};
    if (upstream)
    {
        flags = O_RDONLY;
    }
    else if (fs::exists(path))
    {
        flags = O_RDWR;
    }
    else
    {
        flags = O_WRONLY;
    }
    int file = open(path.string().c_str(), flags);
    if (file == -1)
    {
        std::cerr << "File does not exist, path = " << path.string() << "\n";
        encode_rw_file_memory_resp(instanceId, command, PLDM_ERROR, 0,
                                   responsePtr);
        return response;
    }
    pldm::utils::CustomFD fd(file);

    while (length > dma::maxSize)
    {
        auto rc = intf->transferDataHost(fd(), offset, dma::maxSize, address,
                                         upstream);
        if (rc < 0)
        {
            encode_rw_file_memory_resp(instanceId, command, PLDM_ERROR, 0,
                                       responsePtr);
            return response;
        }

        offset += dma::maxSize;
        length -= dma::maxSize;
        address += dma::maxSize;
    }

    auto rc = intf->transferDataHost(fd(), offset, length, address, upstream);
    if (rc < 0)
    {
        encode_rw_file_memory_resp(instanceId, command, PLDM_ERROR, 0,
                                   responsePtr);
        return response;
    }

    encode_rw_file_memory_resp(instanceId, command, PLDM_SUCCESS, origLength,
                               responsePtr);
    return response;
}

} // namespace dma

namespace oem_ibm
{
static constexpr auto dumpObjPath = "/xyz/openbmc_project/dump/resource/entry/";
static constexpr auto resDumpEntry = "com.ibm.Dump.Entry.Resource";

static constexpr auto certObjPath = "/xyz/openbmc_project/certs/ca/";
static constexpr auto certAuthority =
    "xyz.openbmc_project.PLDM.Provider.Certs.Authority.CSR";
class Handler : public CmdHandler
{
  public:
    Handler(oem_platform::Handler* oemPlatformHandler, int hostSockFd,
            uint8_t hostEid, dbus_api::Requester* dbusImplReqester,
            pldm::requester::Handler<pldm::requester::Request>* handler) :
        oemPlatformHandler(oemPlatformHandler),
        hostSockFd(hostSockFd), hostEid(hostEid),
        dbusImplReqester(dbusImplReqester), handler(handler)
    {
        handlers.emplace(PLDM_READ_FILE_INTO_MEMORY,
                         [this](const pldm_msg* request, size_t payloadLength) {
                             return this->readFileIntoMemory(request,
                                                             payloadLength);
                         });
        handlers.emplace(PLDM_WRITE_FILE_FROM_MEMORY,
                         [this](const pldm_msg* request, size_t payloadLength) {
                             return this->writeFileFromMemory(request,
                                                              payloadLength);
                         });
        handlers.emplace(PLDM_WRITE_FILE_BY_TYPE_FROM_MEMORY,
                         [this](const pldm_msg* request, size_t payloadLength) {
                             return this->writeFileByTypeFromMemory(
                                 request, payloadLength);
                         });
        handlers.emplace(PLDM_READ_FILE_BY_TYPE_INTO_MEMORY,
                         [this](const pldm_msg* request, size_t payloadLength) {
                             return this->readFileByTypeIntoMemory(
                                 request, payloadLength);
                         });
        handlers.emplace(PLDM_READ_FILE_BY_TYPE, [this](const pldm_msg* request,
                                                        size_t payloadLength) {
            return this->readFileByType(request, payloadLength);
        });
        handlers.emplace(PLDM_WRITE_FILE_BY_TYPE,
                         [this](const pldm_msg* request, size_t payloadLength) {
                             return this->writeFileByType(request,
                                                          payloadLength);
                         });
        handlers.emplace(PLDM_GET_FILE_TABLE,
                         [this](const pldm_msg* request, size_t payloadLength) {
                             return this->getFileTable(request, payloadLength);
                         });
        handlers.emplace(PLDM_READ_FILE,
                         [this](const pldm_msg* request, size_t payloadLength) {
                             return this->readFile(request, payloadLength);
                         });
        handlers.emplace(PLDM_WRITE_FILE,
                         [this](const pldm_msg* request, size_t payloadLength) {
                             return this->writeFile(request, payloadLength);
                         });
        handlers.emplace(PLDM_FILE_ACK,
                         [this](const pldm_msg* request, size_t payloadLength) {
                             return this->fileAck(request, payloadLength);
                         });
        handlers.emplace(PLDM_HOST_GET_ALERT_STATUS,
                         [this](const pldm_msg* request, size_t payloadLength) {
                             return this->getAlertStatus(request,
                                                         payloadLength);
                         });
        handlers.emplace(PLDM_NEW_FILE_AVAILABLE,
                         [this](const pldm_msg* request, size_t payloadLength) {
                             return this->newFileAvailable(request,
                                                           payloadLength);
                         });

        resDumpMatcher = std::make_unique<sdbusplus::bus::match::match>(
            pldm::utils::DBusHandler::getBus(),
            sdbusplus::bus::match::rules::interfacesAdded() +
                sdbusplus::bus::match::rules::argNpath(0, dumpObjPath),
            [this, hostSockFd, hostEid, dbusImplReqester,
             handler](sdbusplus::message::message& msg) {
                std::map<
                    std::string,
                    std::map<std::string, std::variant<std::string, uint32_t>>>
                    interfaces;
                sdbusplus::message::object_path path;
                msg.read(path, interfaces);
                std::string vspstring;
                std::string password;

                for (auto& interface : interfaces)
                {
                    if (interface.first == resDumpEntry)
                    {
                        for (const auto& property : interface.second)
                        {
                            if (property.first == "VSPString")
                            {
                                vspstring =
                                    std::get<std::string>(property.second);
                            }
                            else if (property.first == "Password")
                            {
                                password =
                                    std::get<std::string>(property.second);
                            }
                        }
                        dbusToFileHandlers
                            .emplace_back(
                                std::make_unique<pldm::requester::oem_ibm::
                                                     DbusToFileHandler>(
                                    hostSockFd, hostEid, dbusImplReqester, path,
                                    handler))
                            ->processNewResourceDump(vspstring, password);
                        break;
                    }
                }
            });
        vmiCertMatcher = std::make_unique<sdbusplus::bus::match::match>(
            pldm::utils::DBusHandler::getBus(),
            sdbusplus::bus::match::rules::interfacesAdded() +
                sdbusplus::bus::match::rules::argNpath(0, certObjPath),
            [this, hostSockFd, hostEid, dbusImplReqester,
             handler](sdbusplus::message::message& msg) {
                std::map<
                    std::string,
                    std::map<std::string, std::variant<std::string, uint32_t>>>
                    interfaces;
                sdbusplus::message::object_path path;
                msg.read(path, interfaces);
                std::string csr;

                for (auto& interface : interfaces)
                {
                    if (interface.first == certAuthority)
                    {
                        for (const auto& property : interface.second)
                        {
                            if (property.first == "CSR")
                            {
                                csr = std::get<std::string>(property.second);
                                auto fileHandle =
                                    sdbusplus::message::object_path(path)
                                        .filename();

                                dbusToFileHandlers
                                    .emplace_back(std::make_unique<
                                                  pldm::requester::oem_ibm::
                                                      DbusToFileHandler>(
                                        hostSockFd, hostEid, dbusImplReqester,
                                        path, handler))
                                    ->newCsrFileAvailable(csr, fileHandle);
                                break;
                            }
                        }
                        break;
                    }
                }
            });
    }

    /** @brief Handler for readFileIntoMemory command
     *
     *  @param[in] request - pointer to PLDM request payload
     *  @param[in] payloadLength - length of the message
     *
     *  @return PLDM response message
     */
    Response readFileIntoMemory(const pldm_msg* request, size_t payloadLength);

    /** @brief Handler for writeFileIntoMemory command
     *
     *  @param[in] request - pointer to PLDM request payload
     *  @param[in] payloadLength - length of the message
     *
     *  @return PLDM response message
     */
    Response writeFileFromMemory(const pldm_msg* request, size_t payloadLength);

    /** @brief Handler for writeFileByTypeFromMemory command
     *
     *  @param[in] request - pointer to PLDM request payload
     *  @param[in] payloadLength - length of the message
     *
     *  @return PLDM response message
     */

    Response writeFileByTypeFromMemory(const pldm_msg* request,
                                       size_t payloadLength);

    /** @brief Handler for readFileByTypeIntoMemory command
     *
     *  @param[in] request - pointer to PLDM request payload
     *  @param[in] payloadLength - length of the message
     *
     *  @return PLDM response message
     */
    Response readFileByTypeIntoMemory(const pldm_msg* request,
                                      size_t payloadLength);

    /** @brief Handler for writeFileByType command
     *
     *  @param[in] request - pointer to PLDM request payload
     *  @param[in] payloadLength - length of the message
     *
     *  @return PLDM response message
     */
    Response readFileByType(const pldm_msg* request, size_t payloadLength);

    Response writeFileByType(const pldm_msg* request, size_t payloadLength);

    /** @brief Handler for GetFileTable command
     *
     *  @param[in] request - pointer to PLDM request payload
     *  @param[in] payloadLength - length of the message payload
     *
     *  @return PLDM response message
     */
    Response getFileTable(const pldm_msg* request, size_t payloadLength);

    /** @brief Handler for readFile command
     *
     *  @param[in] request - PLDM request msg
     *  @param[in] payloadLength - length of the message payload
     *
     *  @return PLDM response message
     */
    Response readFile(const pldm_msg* request, size_t payloadLength);

    /** @brief Handler for writeFile command
     *
     *  @param[in] request - PLDM request msg
     *  @param[in] payloadLength - length of the message payload
     *
     *  @return PLDM response message
     */
    Response writeFile(const pldm_msg* request, size_t payloadLength);

    Response fileAck(const pldm_msg* request, size_t payloadLength);

    /** @brief Handler for getAlertStatus command
     *
     *  @param[in] request - PLDM request msg
     *  @param[in] payloadLength - length of the message payload
     *
     *  @return PLDM response message
     */
    Response getAlertStatus(const pldm_msg* request, size_t payloadLength);

    /** @brief Handler for newFileAvailable command
     *
     *  @param[in] request - PLDM request msg
     *  @param[in] payloadLength - length of the message payload
     *
     *  @return PLDM response message
     */
    Response newFileAvailable(const pldm_msg* request, size_t payloadLength);

  private:
    oem_platform::Handler* oemPlatformHandler;
    int hostSockFd;
    uint8_t hostEid;
    dbus_api::Requester* dbusImplReqester;
    using DBusInterfaceAdded = std::vector<std::pair<
        std::string,
        std::vector<std::pair<std::string, std::variant<std::string>>>>>;
    std::unique_ptr<pldm::requester::oem_ibm::DbusToFileHandler>
        dbusToFileHandler; //!< pointer to send request to Host
    std::unique_ptr<sdbusplus::bus::match::match>
        resDumpMatcher; //!< Pointer to capture the interface added signal
                        //!< for new resource dump
    std::unique_ptr<sdbusplus::bus::match::match>
        vmiCertMatcher; //!< Pointer to capture the interface added signal
                        //!< for new csr string
    /** @brief PLDM request handler */
    pldm::requester::Handler<pldm::requester::Request>* handler;
    std::vector<std::unique_ptr<pldm::requester::oem_ibm::DbusToFileHandler>>
        dbusToFileHandlers;
};

} // namespace oem_ibm
} // namespace responder
} // namespace pldm
