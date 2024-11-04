#pragma once

#include "libpldm/platform.h"
#include "libpldm/pldm.h"

#include "terminus.hpp"
#include "terminus_manager.hpp"

#include <vector>

namespace pldm
{

namespace platform_mc
{

/**
 * @brief PlatformManager
 *
 * PlatformManager class manages the actions outlined in the platform spec.
 */
class PlatformManager
{
  public:
    PlatformManager() = delete;
    PlatformManager(const PlatformManager&) = delete;
    PlatformManager(PlatformManager&&) = delete;
    PlatformManager& operator=(const PlatformManager&) = delete;
    PlatformManager& operator=(PlatformManager&&) = delete;
    ~PlatformManager() = default;

    explicit PlatformManager(TerminusManager& terminusManager,
                             TerminiMapper& termini) :
        terminusManager(terminusManager), termini(termini)
    {}

    /** @brief Initialize terminus which supports PLDM Type 2
     *
     *  @return coroutine return_value - PLDM completion code
     */
    exec::task<int> initTerminus();

    /** @brief Helper to get the supported event messages and set event receiver
     *
     *  @param[in] tid - Destination TID
     *  @return coroutine return_value - PLDM completion code
     */
    exec::task<int> configEventReceiver(pldm_tid_t tid);

  private:
    /** @brief Fetch all PDRs from terminus.
     *
     *  @param[in] terminus - The terminus object to store fetched PDRs
     *  @return coroutine return_value - PLDM completion code
     */
    exec::task<int> getPDRs(std::shared_ptr<Terminus> terminus);

    /** @brief Fetch PDR from terminus
     *
     *  @param[in] tid - Destination TID
     *  @param[in] recordHndl - Record handle
     *  @param[in] dataTransferHndl - Data transfer handle
     *  @param[in] transferOpFlag - Transfer Operation Flag
     *  @param[in] requstCnt - Request Count of data
     *  @param[in] recordChgNum - Record change number
     *  @param[out] nextRecordHndl - Next record handle
     *  @param[out] nextDataTransferHndl - Next data transfer handle
     *  @param[out] transferFlag - Transfer flag
     *  @param[out] responseCnt - Response count of record data
     *  @param[out] recordData - Returned record data
     *  @param[out] transferCrc - CRC value when record data is last part of PDR
     *  @return coroutine return_value - PLDM completion code
     */
    exec::task<int>
        getPDR(const pldm_tid_t tid, const uint32_t recordHndl,
               const uint32_t dataTransferHndl, const uint8_t transferOpFlag,
               const uint16_t requestCnt, const uint16_t recordChgNum,
               uint32_t& nextRecordHndl, uint32_t& nextDataTransferHndl,
               uint8_t& transferFlag, uint16_t& responseCnt,
               std::vector<uint8_t>& recordData, uint8_t& transferCrc);

    /** @brief get PDR repository information.
     *
     *  @param[in] tid - Destination TID
     *  @param[out] repositoryState - the state of repository
     *  @param[out] recordCount - number of records
     *  @param[out] repositorySize - repository size
     *  @param[out] largestRecordSize - largest record size
     * *
     *  @return coroutine return_value - PLDM completion code
     */
    exec::task<int> getPDRRepositoryInfo(
        const pldm_tid_t tid, uint8_t& repositoryState, uint32_t& recordCount,
        uint32_t& repositorySize, uint32_t& largestRecordSize);

    /** @brief Send setEventReceiver command to destination EID.
     *
     *  @param[in] tid - Destination TID
     *  @param[in] eventMessageGlobalEnable - Enable/disable event message
     *             generation from the terminus
     *  @param[in] eventReceiverEid - The EID of eventReceiver that terminus
     *             should send event message to
     *  @param[in] protocolType - Provided in the request to help the responder
     *             verify that the content of the eventReceiverAddressInfo field
     *  @param[in] heartbeatTimer - Amount of time in seconds after each
     *             elapsing of which the terminus shall emit a heartbeat event.
     *  @return coroutine return_value - PLDM completion code
     */
    exec::task<int> setEventReceiver(
        pldm_tid_t tid,
        pldm_event_message_global_enable eventMessageGlobalEnable,
        pldm_transport_protocol_type protocolType, uint16_t heartbeatTimer);

    /** @brief  send eventMessageBufferSize
     *  @param[in] tid - Destination TID
     *  @param[in] receiverMaxBufferSize
     *  @param[out] terminusBufferSize
     *  @return coroutine return_value - PLDM completion code
     */
    exec::task<int> eventMessageBufferSize(pldm_tid_t tid,
                                           uint16_t receiverMaxBufferSize,
                                           uint16_t& terminusBufferSize);

    /** @brief  send eventMessageSupported
     *  @param[in] tid - Destination TID
     *  @param[in] formatVersion - version of the event format
     *  @param[out] synchronyConfiguration - messaging style most recently
     *              configured via the setEventReceiver command
     *  @param[out] synchronyConfigurationSupported - event messaging styles
     *              supported by the terminus
     *  @param[out] numerEventClassReturned - number of eventClass enumerated
     *              bytes
     *  @param[out] eventClass - vector of eventClass the device can generate
     *  @return coroutine return_value - PLDM completion code
     */
    exec::task<int> eventMessageSupported(
        pldm_tid_t tid, uint8_t formatVersion, uint8_t& synchronyConfiguration,
        bitfield8_t& synchronyConfigurationSupported,
        uint8_t& numerEventClassReturned, std::vector<uint8_t>& eventClass);

    /** reference of TerminusManager for sending PLDM request to terminus*/
    TerminusManager& terminusManager;

    /** @brief Managed termini list */
    TerminiMapper& termini;
};
} // namespace platform_mc
} // namespace pldm
