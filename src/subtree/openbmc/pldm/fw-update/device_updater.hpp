#pragma once

#include "common/types.hpp"
#include "requester/handler.hpp"
#include "requester/request.hpp"

#include <sdeventplus/event.hpp>
#include <sdeventplus/source/event.hpp>

#include <fstream>

namespace pldm
{

namespace fw_update
{

class UpdateManager;

/** @class DeviceUpdater
 *
 *  DeviceUpdater orchestrates the firmware update of the firmware device and
 *  updates the UpdateManager about the status once it is complete.
 */
class DeviceUpdater
{
  public:
    DeviceUpdater() = delete;
    DeviceUpdater(const DeviceUpdater&) = delete;
    DeviceUpdater(DeviceUpdater&&) = default;
    DeviceUpdater& operator=(const DeviceUpdater&) = delete;
    DeviceUpdater& operator=(DeviceUpdater&&) = default;
    ~DeviceUpdater() = default;

    /** @brief Constructor
     *
     *  @param[in] eid - Endpoint ID of the firmware device
     *  @param[in] package - File stream for firmware update package
     *  @param[in] fwDeviceIDRecord - FirmwareDeviceIDRecord in the fw update
     *                                package that matches this firmware device
     *  @param[in] compImageInfos - Component image information for all the
     *                              components in the fw update package
     *  @param[in] compInfo - Component info for the components in this FD
     *                        derived from GetFirmwareParameters response
     *  @param[in] maxTransferSize - Maximum size in bytes of the variable
     *                               payload allowed to be requested by the FD
     *  @param[in] updateManager - To update the status of fw update of the
     *                             device
     */
    explicit DeviceUpdater(mctp_eid_t eid, std::ifstream& package,
                           const FirmwareDeviceIDRecord& fwDeviceIDRecord,
                           const ComponentImageInfos& compImageInfos,
                           const ComponentInfo& compInfo,
                           uint32_t maxTransferSize,
                           UpdateManager* updateManager) :
        eid(eid),
        package(package), fwDeviceIDRecord(fwDeviceIDRecord),
        compImageInfos(compImageInfos), compInfo(compInfo),
        maxTransferSize(maxTransferSize), updateManager(updateManager)
    {}

    /** @brief Start the firmware update flow for the FD
     *
     *  To start the update flow RequestUpdate command is sent to the FD.
     *
     */
    void startFwUpdateFlow();

    /** @brief Handler for RequestUpdate command response
     *
     *  The response of the RequestUpdate is processed and if the response
     *  is success, send PassComponentTable request to FD.
     *
     *  @param[in] eid - Remote MCTP endpoint
     *  @param[in] response - PLDM response message
     *  @param[in] respMsgLen - Response message length
     */
    void requestUpdate(mctp_eid_t eid, const pldm_msg* response,
                       size_t respMsgLen);

    /** @brief Handler for PassComponentTable command response
     *
     *  The response of the PassComponentTable is processed. If the response
     *  indicates component can be updated, continue with either a) or b).
     *
     *  a. Send PassComponentTable request for the next component if
     *     applicable
     *  b. UpdateComponent command to request updating a specific
     *     firmware component
     *
     *  If the response indicates component may be updateable, continue
     *  based on the policy in DeviceUpdateOptionFlags.
     *
     *  @param[in] eid - Remote MCTP endpoint
     *  @param[in] response - PLDM response message
     *  @param[in] respMsgLen - Response message length
     */
    void passCompTable(mctp_eid_t eid, const pldm_msg* response,
                       size_t respMsgLen);

    /** @brief Handler for UpdateComponent command response
     *
     *  The response of the UpdateComponent is processed and will wait for
     *  FD to request the firmware data.
     *
     *  @param[in] eid - Remote MCTP endpoint
     *  @param[in] response - PLDM response message
     *  @param[in] respMsgLen - Response message length
     */
    void updateComponent(mctp_eid_t eid, const pldm_msg* response,
                         size_t respMsgLen);

    /** @brief Handler for RequestFirmwareData request
     *
     *  @param[in] request - Request message
     *  @param[in] payload_length - Request message payload length
     *  @return Response - PLDM Response message
     */
    Response requestFwData(const pldm_msg* request, size_t payloadLength);

    /** @brief Handler for TransferComplete request
     *
     *  @param[in] request - Request message
     *  @param[in] payload_length - Request message payload length
     *  @return Response - PLDM Response message
     */
    Response transferComplete(const pldm_msg* request, size_t payloadLength);

    /** @brief Handler for VerifyComplete request
     *
     *  @param[in] request - Request message
     *  @param[in] payload_length - Request message payload length
     *  @return Response - PLDM Response message
     */
    Response verifyComplete(const pldm_msg* request, size_t payloadLength);

    /** @brief Handler for ApplyComplete request
     *
     *  @param[in] request - Request message
     *  @param[in] payload_length - Request message payload length
     *  @return Response - PLDM Response message
     */
    Response applyComplete(const pldm_msg* request, size_t payloadLength);

    /** @brief Handler for ActivateFirmware command response
     *
     *  The response of the ActivateFirmware is processed and will update the
     *  UpdateManager with the completion of the firmware update.
     *
     *  @param[in] eid - Remote MCTP endpoint
     *  @param[in] response - PLDM response message
     *  @param[in] respMsgLen - Response message length
     */
    void activateFirmware(mctp_eid_t eid, const pldm_msg* response,
                          size_t respMsgLen);

  private:
    /** @brief Send PassComponentTable command request
     *
     *  @param[in] compOffset - component offset in compImageInfos
     */
    void sendPassCompTableRequest(size_t offset);

    /** @brief Send UpdateComponent command request
     *
     *  @param[in] compOffset - component offset in compImageInfos
     */
    void sendUpdateComponentRequest(size_t offset);

    /** @brief Send ActivateFirmware command request */
    void sendActivateFirmwareRequest();

    /** @brief Endpoint ID of the firmware device */
    mctp_eid_t eid;

    /** @brief File stream for firmware update package */
    std::ifstream& package;

    /** @brief FirmwareDeviceIDRecord in the fw update package that matches this
     *         firmware device
     */
    const FirmwareDeviceIDRecord& fwDeviceIDRecord;

    /** @brief Component image information for all the components in the fw
     *         update package
     */
    const ComponentImageInfos& compImageInfos;

    /** @brief Component info for the components in this FD derived from
     *         GetFirmwareParameters response
     */
    const ComponentInfo& compInfo;

    /** @brief Maximum size in bytes of the variable payload to be requested by
     *         the FD via RequestFirmwareData command
     */
    uint32_t maxTransferSize;

    /** @brief To update the status of fw update of the FD */
    UpdateManager* updateManager;

    /** @brief Component index is used to track the current component being
     *         updated if multiple components are applicable for the FD.
     *         It is also used to keep track of the next component in
     *         PassComponentTable
     */
    size_t componentIndex = 0;

    /** @brief To send a PLDM request after the current command handling */
    std::unique_ptr<sdeventplus::source::Defer> pldmRequest;
};

} // namespace fw_update

} // namespace pldm