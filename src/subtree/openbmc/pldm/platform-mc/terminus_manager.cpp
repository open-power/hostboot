#include "terminus_manager.hpp"

#include "manager.hpp"

#include <phosphor-logging/lg2.hpp>

PHOSPHOR_LOG2_USING;

namespace pldm
{
namespace platform_mc
{

std::optional<MctpInfo> TerminusManager::toMctpInfo(const pldm_tid_t& tid)
{
    if (tid == PLDM_TID_UNASSIGNED || tid == PLDM_TID_RESERVED)
    {
        return std::nullopt;
    }

    if ((!this->transportLayerTable.contains(tid)) ||
        (this->transportLayerTable[tid] != SupportedTransportLayer::MCTP))
    {
        return std::nullopt;
    }

    auto mctpInfoIt = mctpInfoTable.find(tid);
    if (mctpInfoIt == mctpInfoTable.end())
    {
        return std::nullopt;
    }

    return mctpInfoIt->second;
}

std::optional<pldm_tid_t> TerminusManager::toTid(const MctpInfo& mctpInfo) const
{
    if (!pldm::utils::isValidEID(std::get<0>(mctpInfo)))
    {
        return std::nullopt;
    }

    auto mctpInfoTableIt = std::find_if(
        mctpInfoTable.begin(), mctpInfoTable.end(), [&mctpInfo](auto& v) {
            return (std::get<0>(v.second) == std::get<0>(mctpInfo)) &&
                   (std::get<3>(v.second) == std::get<3>(mctpInfo));
        });
    if (mctpInfoTableIt == mctpInfoTable.end())
    {
        return std::nullopt;
    }
    return mctpInfoTableIt->first;
}

std::optional<pldm_tid_t>
    TerminusManager::storeTerminusInfo(const MctpInfo& mctpInfo, pldm_tid_t tid)
{
    if (tid == PLDM_TID_UNASSIGNED || tid == PLDM_TID_RESERVED)
    {
        return std::nullopt;
    }

    if (!pldm::utils::isValidEID(std::get<0>(mctpInfo)))
    {
        return std::nullopt;
    }

    if (tidPool[tid])
    {
        return std::nullopt;
    }

    tidPool[tid] = true;
    transportLayerTable[tid] = SupportedTransportLayer::MCTP;
    mctpInfoTable[tid] = mctpInfo;

    return tid;
}

std::optional<pldm_tid_t> TerminusManager::mapTid(const MctpInfo& mctpInfo)
{
    if (!pldm::utils::isValidEID(std::get<0>(mctpInfo)))
    {
        return std::nullopt;
    }

    auto mctpInfoTableIt = std::find_if(
        mctpInfoTable.begin(), mctpInfoTable.end(), [&mctpInfo](auto& v) {
            return (std::get<0>(v.second) == std::get<0>(mctpInfo)) &&
                   (std::get<3>(v.second) == std::get<3>(mctpInfo));
        });
    if (mctpInfoTableIt != mctpInfoTable.end())
    {
        return mctpInfoTableIt->first;
    }

    auto tidPoolIt = std::find(tidPool.begin(), tidPool.end(), false);
    if (tidPoolIt == tidPool.end())
    {
        return std::nullopt;
    }

    pldm_tid_t tid = std::distance(tidPool.begin(), tidPoolIt);
    return storeTerminusInfo(mctpInfo, tid);
}

bool TerminusManager::unmapTid(const pldm_tid_t& tid)
{
    if (tid == PLDM_TID_UNASSIGNED || tid == PLDM_TID_RESERVED)
    {
        return false;
    }
    tidPool[tid] = false;

    if (transportLayerTable.contains(tid))
    {
        transportLayerTable.erase(tid);
    }

    if (mctpInfoTable.contains(tid))
    {
        mctpInfoTable.erase(tid);
    }

    return true;
}

void TerminusManager::discoverMctpTerminus(const MctpInfos& mctpInfos)
{
    queuedMctpInfos.emplace(mctpInfos);
    if (discoverMctpTerminusTaskHandle.has_value())
    {
        auto& [scope, rcOpt] = *discoverMctpTerminusTaskHandle;
        if (!rcOpt.has_value())
        {
            return;
        }
        stdexec::sync_wait(scope.on_empty());
        discoverMctpTerminusTaskHandle.reset();
    }
    auto& [scope, rcOpt] = discoverMctpTerminusTaskHandle.emplace();
    scope.spawn(discoverMctpTerminusTask() |
                    stdexec::then([&](int rc) { rcOpt.emplace(rc); }),
                exec::default_task_context<void>(exec::inline_scheduler{}));
}

TerminiMapper::iterator
    TerminusManager::findTerminusPtr(const MctpInfo& mctpInfo)
{
    auto foundIter = std::find_if(
        termini.begin(), termini.end(), [&](const auto& terminusPair) {
            auto terminusMctpInfo = toMctpInfo(terminusPair.first);
            return (terminusMctpInfo &&
                    (std::get<0>(terminusMctpInfo.value()) ==
                     std::get<0>(mctpInfo)) &&
                    (std::get<3>(terminusMctpInfo.value()) ==
                     std::get<3>(mctpInfo)));
        });

    return foundIter;
}

exec::task<int> TerminusManager::discoverMctpTerminusTask()
{
    std::vector<pldm_tid_t> addedTids;
    while (!queuedMctpInfos.empty())
    {
        if (manager)
        {
            co_await manager->beforeDiscoverTerminus();
        }

        const MctpInfos& mctpInfos = queuedMctpInfos.front();
        for (const auto& mctpInfo : mctpInfos)
        {
            auto it = findTerminusPtr(mctpInfo);
            if (it == termini.end())
            {
                co_await initMctpTerminus(mctpInfo);
            }

            /* Get TID of initialized terminus */
            auto tid = toTid(mctpInfo);
            if (!tid)
            {
                co_return PLDM_ERROR;
            }
            addedTids.push_back(tid.value());
        }

        if (manager)
        {
            co_await manager->afterDiscoverTerminus();
            for (const auto& tid : addedTids)
            {
                manager->startSensorPolling(tid);
            }
        }

        queuedMctpInfos.pop();
    }

    co_return PLDM_SUCCESS;
}

void TerminusManager::removeMctpTerminus(const MctpInfos& mctpInfos)
{
    // remove terminus
    for (const auto& mctpInfo : mctpInfos)
    {
        auto it = findTerminusPtr(mctpInfo);
        if (it == termini.end())
        {
            continue;
        }

        if (manager)
        {
            manager->stopSensorPolling(it->second->getTid());
        }

        unmapTid(it->first);
        termini.erase(it);
    }
}

exec::task<int> TerminusManager::initMctpTerminus(const MctpInfo& mctpInfo)
{
    mctp_eid_t eid = std::get<0>(mctpInfo);
    pldm_tid_t tid = 0;
    bool isMapped = false;
    auto rc = co_await getTidOverMctp(eid, &tid);
    if (rc != PLDM_SUCCESS)
    {
        lg2::error("Failed to Get Terminus ID, error {ERROR}.", "ERROR", rc);
        co_return PLDM_ERROR;
    }

    if (tid == PLDM_TID_RESERVED)
    {
        lg2::error("Terminus responses the reserved {TID}.", "TID", tid);
        co_return PLDM_ERROR;
    }

    /* Terminus already has TID */
    if (tid != PLDM_TID_UNASSIGNED)
    {
        /* TID is used by one discovered terminus */
        auto it = termini.find(tid);
        if (it != termini.end())
        {
            auto terminusMctpInfo = toMctpInfo(it->first);
            /* The discovered terminus has the same MCTP Info */
            if (terminusMctpInfo &&
                (std::get<0>(terminusMctpInfo.value()) ==
                 std::get<0>(mctpInfo)) &&
                (std::get<3>(terminusMctpInfo.value()) ==
                 std::get<3>(mctpInfo)))
            {
                co_return PLDM_SUCCESS;
            }
            else
            {
                /* ToDo:
                 * Maybe the terminus supports multiple medium interfaces
                 * Or the TID is used by other terminus.
                 * Check the UUID to confirm.
                 */
                isMapped = false;
            }
        }
        /* Use the terminus TID for mapping */
        else
        {
            auto mappedTid = storeTerminusInfo(mctpInfo, tid);
            if (!mappedTid)
            {
                lg2::error("Failed to store Terminus Info for terminus {TID}.",
                           "TID", tid);
                co_return PLDM_ERROR;
            }
            isMapped = true;
        }
    }

    if (!isMapped)
    {
        // Assigning a tid. If it has been mapped, mapTid()
        // returns the tid assigned before.
        auto mappedTid = mapTid(mctpInfo);
        if (!mappedTid)
        {
            lg2::error("Failed to store Terminus Info for terminus {TID}.",
                       "TID", tid);
            co_return PLDM_ERROR;
        }

        tid = mappedTid.value();
        rc = co_await setTidOverMctp(eid, tid);
        if (rc != PLDM_SUCCESS)
        {
            lg2::error("Failed to Set terminus TID, error{ERROR}.", "ERROR",
                       rc);
            unmapTid(tid);
            co_return rc;
        }

        if (rc != PLDM_SUCCESS && rc != PLDM_ERROR_UNSUPPORTED_PLDM_CMD)
        {
            lg2::error("Terminus {TID} does not support SetTID command.", "TID",
                       tid);
            unmapTid(tid);
            co_return rc;
        }

        if (termini.contains(tid))
        {
            // the terminus has been discovered before
            co_return PLDM_SUCCESS;
        }
    }
    /* Discovery the mapped terminus */
    uint64_t supportedTypes = 0;
    rc = co_await getPLDMTypes(tid, supportedTypes);
    if (rc)
    {
        lg2::error("Failed to Get PLDM Types for terminus {TID}, error {ERROR}",
                   "TID", tid, "ERROR", rc);
        unmapTid(tid);
        co_return PLDM_ERROR;
    }

    try
    {
        termini[tid] = std::make_shared<Terminus>(tid, supportedTypes);
    }
    catch (const sdbusplus::exception_t& e)
    {
        lg2::error("Failed to create terminus manager for terminus {TID}",
                   "TID", tid);
        unmapTid(tid);
        co_return PLDM_ERROR;
    }

    uint8_t type = PLDM_BASE;
    auto size = PLDM_MAX_TYPES * (PLDM_MAX_CMDS_PER_TYPE / 8);
    std::vector<uint8_t> pldmCmds(size);
    while ((type < PLDM_MAX_TYPES))
    {
        if (!termini[tid]->doesSupportType(type))
        {
            type++;
            continue;
        }
        std::vector<bitfield8_t> cmds(PLDM_MAX_CMDS_PER_TYPE / 8);
        auto rc = co_await getPLDMCommands(tid, type, cmds.data());
        if (rc)
        {
            lg2::error(
                "Failed to Get PLDM Commands for terminus {TID}, error {ERROR}",
                "TID", tid, "ERROR", rc);
        }

        for (size_t i = 0; i < cmds.size(); i++)
        {
            auto idx = type * (PLDM_MAX_CMDS_PER_TYPE / 8) + i;
            if (idx >= pldmCmds.size())
            {
                lg2::error(
                    "Calculated index {IDX} out of bounds for pldmCmds, type {TYPE}, command index {CMD_IDX}",
                    "IDX", idx, "TYPE", type, "CMD_IDX", i);
                continue;
            }
            pldmCmds[idx] = cmds[i].byte;
        }
        type++;
    }
    termini[tid]->setSupportedCommands(pldmCmds);

    co_return PLDM_SUCCESS;
}

exec::task<int> TerminusManager::sendRecvPldmMsgOverMctp(
    mctp_eid_t eid, Request& request, const pldm_msg** responseMsg,
    size_t* responseLen)
{
    int rc = 0;
    try
    {
        std::tie(rc, *responseMsg, *responseLen) =
            co_await handler.sendRecvMsg(eid, std::move(request));
    }
    catch (const sdbusplus::exception_t& e)
    {
        lg2::error(
            "Send and Receive PLDM message over MCTP throw error - {ERROR}.",
            "ERROR", e);
        co_return PLDM_ERROR;
    }
    catch (const int& e)
    {
        lg2::error(
            "Send and Receive PLDM message over MCTP throw int error - {ERROR}.",
            "ERROR", e);
        co_return PLDM_ERROR;
    }

    co_return rc;
}

exec::task<int> TerminusManager::getTidOverMctp(mctp_eid_t eid, pldm_tid_t* tid)
{
    auto instanceId = instanceIdDb.next(eid);
    Request request(sizeof(pldm_msg_hdr));
    auto requestMsg = reinterpret_cast<pldm_msg*>(request.data());
    auto rc = encode_get_tid_req(instanceId, requestMsg);
    if (rc)
    {
        instanceIdDb.free(eid, instanceId);
        lg2::error(
            "Failed to encode request GetTID for endpoint ID {EID}, error {RC} ",
            "EID", eid, "RC", rc);
        co_return rc;
    }

    const pldm_msg* responseMsg = nullptr;
    size_t responseLen = 0;
    rc = co_await sendRecvPldmMsgOverMctp(eid, request, &responseMsg,
                                          &responseLen);
    if (rc)
    {
        lg2::error("Failed to send GetTID for Endpoint {EID}, error {RC}",
                   "EID", eid, "RC", rc);
        co_return rc;
    }

    uint8_t completionCode = 0;
    rc = decode_get_tid_resp(responseMsg, responseLen, &completionCode, tid);
    if (rc)
    {
        lg2::error(
            "Failed to decode response GetTID for Endpoint ID {EID}, error {RC} ",
            "EID", eid, "RC", rc);
        co_return rc;
    }

    if (completionCode != PLDM_SUCCESS)
    {
        lg2::error("Error : GetTID for Endpoint ID {EID}, complete code {CC}.",
                   "EID", eid, "CC", completionCode);
        co_return rc;
    }

    co_return completionCode;
}

exec::task<int> TerminusManager::setTidOverMctp(mctp_eid_t eid, pldm_tid_t tid)
{
    auto instanceId = instanceIdDb.next(eid);
    Request request(sizeof(pldm_msg_hdr) + sizeof(pldm_set_tid_req));
    auto requestMsg = reinterpret_cast<pldm_msg*>(request.data());
    auto rc = encode_set_tid_req(instanceId, tid, requestMsg);
    if (rc)
    {
        instanceIdDb.free(eid, instanceId);
        lg2::error(
            "Failed to encode request SetTID for endpoint ID {EID}, error {RC} ",
            "EID", eid, "RC", rc);
        co_return rc;
    }

    const pldm_msg* responseMsg = nullptr;
    size_t responseLen = 0;
    rc = co_await sendRecvPldmMsgOverMctp(eid, request, &responseMsg,
                                          &responseLen);
    if (rc)
    {
        lg2::error("Failed to send SetTID for Endpoint {EID}, error {RC}",
                   "EID", eid, "RC", rc);
        co_return rc;
    }

    if (responseMsg == NULL || responseLen != PLDM_SET_TID_RESP_BYTES)
    {
        lg2::error(
            "Failed to decode response SetTID for Endpoint ID {EID}, error {RC} ",
            "EID", eid, "RC", rc);
        co_return PLDM_ERROR_INVALID_LENGTH;
    }

    co_return responseMsg->payload[0];
}

exec::task<int>
    TerminusManager::getPLDMTypes(pldm_tid_t tid, uint64_t& supportedTypes)
{
    Request request(sizeof(pldm_msg_hdr));
    auto requestMsg = reinterpret_cast<pldm_msg*>(request.data());
    auto rc = encode_get_types_req(0, requestMsg);
    if (rc)
    {
        lg2::error(
            "Failed to encode request getPLDMTypes for terminus ID {TID}, error {RC} ",
            "TID", tid, "RC", rc);
        co_return rc;
    }

    const pldm_msg* responseMsg = nullptr;
    size_t responseLen = 0;

    rc = co_await sendRecvPldmMsg(tid, request, &responseMsg, &responseLen);
    if (rc)
    {
        lg2::error("Failed to send GetPLDMTypes for terminus {TID}, error {RC}",
                   "TID", tid, "RC", rc);
        co_return rc;
    }

    uint8_t completionCode = 0;
    bitfield8_t* types = reinterpret_cast<bitfield8_t*>(&supportedTypes);
    rc =
        decode_get_types_resp(responseMsg, responseLen, &completionCode, types);
    if (rc)
    {
        lg2::error(
            "Failed to decode response GetPLDMTypes for terminus ID {TID}, error {RC} ",
            "TID", tid, "RC", rc);
        co_return rc;
    }

    if (completionCode != PLDM_SUCCESS)
    {
        lg2::error(
            "Error : GetPLDMTypes for terminus ID {TID}, complete code {CC}.",
            "TID", tid, "CC", completionCode);
        co_return rc;
    }
    co_return completionCode;
}

exec::task<int> TerminusManager::getPLDMCommands(pldm_tid_t tid, uint8_t type,
                                                 bitfield8_t* supportedCmds)
{
    Request request(sizeof(pldm_msg_hdr) + PLDM_GET_COMMANDS_REQ_BYTES);
    auto requestMsg = reinterpret_cast<pldm_msg*>(request.data());
    ver32_t version{0xFF, 0xFF, 0xFF, 0xFF};

    auto rc = encode_get_commands_req(0, type, version, requestMsg);
    if (rc)
    {
        lg2::error(
            "Failed to encode request GetPLDMCommands for terminus ID {TID}, error {RC} ",
            "TID", tid, "RC", rc);
        co_return rc;
    }

    const pldm_msg* responseMsg = nullptr;
    size_t responseLen = 0;

    rc = co_await sendRecvPldmMsg(tid, request, &responseMsg, &responseLen);
    if (rc)
    {
        lg2::error(
            "Failed to send GetPLDMCommands message for terminus {TID}, error {RC}",
            "TID", tid, "RC", rc);
        co_return rc;
    }

    /* Process response */
    uint8_t completionCode = 0;
    rc = decode_get_commands_resp(responseMsg, responseLen, &completionCode,
                                  supportedCmds);
    if (rc)
    {
        lg2::error(
            "Failed to decode response GetPLDMCommands for terminus ID {TID}, error {RC} ",
            "TID", tid, "RC", rc);
        co_return rc;
    }

    if (completionCode != PLDM_SUCCESS)
    {
        lg2::error(
            "Error : GetPLDMCommands for terminus ID {TID}, complete code {CC}.",
            "TID", tid, "CC", completionCode);
        co_return rc;
    }

    co_return completionCode;
}

exec::task<int> TerminusManager::sendRecvPldmMsg(
    pldm_tid_t tid, Request& request, const pldm_msg** responseMsg,
    size_t* responseLen)
{
    /**
     * Size of tidPool is `std::numeric_limits<pldm_tid_t>::max() + 1`
     * tidPool[i] always exist
     */
    if (!tidPool[tid])
    {
        co_return PLDM_ERROR_NOT_READY;
    }

    if (!transportLayerTable.contains(tid))
    {
        co_return PLDM_ERROR_NOT_READY;
    }

    if (transportLayerTable[tid] != SupportedTransportLayer::MCTP)
    {
        co_return PLDM_ERROR_NOT_READY;
    }

    auto mctpInfo = toMctpInfo(tid);
    if (!mctpInfo.has_value())
    {
        co_return PLDM_ERROR_NOT_READY;
    }

    auto eid = std::get<0>(mctpInfo.value());
    auto requestMsg = reinterpret_cast<pldm_msg*>(request.data());
    requestMsg->hdr.instance_id = instanceIdDb.next(eid);
    auto rc = co_await sendRecvPldmMsgOverMctp(eid, request, responseMsg,
                                               responseLen);

    co_return rc;
}

} // namespace platform_mc
} // namespace pldm
