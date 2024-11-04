#pragma once

#include "config.h"

#include "libpldm/platform.h"
#include "libpldm/pldm.h"

#include "requester/handler.hpp"
#include "requester/mctp_endpoint_discovery.hpp"
#include "terminus.hpp"

#include <limits>
#include <map>
#include <memory>
#include <optional>
#include <queue>
#include <utility>
#include <vector>

namespace pldm
{

enum class SupportedTransportLayer
{
    MCTP
};

namespace platform_mc
{

/** @brief Size of TID Pool in pldmd */
constexpr size_t tidPoolSize = std::numeric_limits<pldm_tid_t>::max() + 1;
/** @brief Type definition for Requester request handler */
using RequesterHandler = requester::Handler<requester::Request>;
/** @brief Type definition for Terminus handler mapper */
using TerminiMapper = std::map<pldm_tid_t, std::shared_ptr<Terminus>>;

class Manager;
/**
 * @brief TerminusManager
 *
 * TerminusManager class to discover and initialize PLDM terminus.
 */
class TerminusManager
{
  public:
    TerminusManager() = delete;
    TerminusManager(const TerminusManager&) = delete;
    TerminusManager(TerminusManager&&) = delete;
    TerminusManager& operator=(const TerminusManager&) = delete;
    TerminusManager& operator=(TerminusManager&&) = delete;
    virtual ~TerminusManager() = default;

    explicit TerminusManager(
        sdeventplus::Event& /* event */, RequesterHandler& handler,
        pldm::InstanceIdDb& instanceIdDb, TerminiMapper& termini,
        Manager* manager, mctp_eid_t localEid) :
        handler(handler), instanceIdDb(instanceIdDb), termini(termini),
        tidPool(tidPoolSize, false), manager(manager), localEid(localEid)
    {
        // DSP0240 v1.1.0 table-8, special value: 0,0xFF = reserved
        tidPool[0] = true;
        tidPool[PLDM_TID_RESERVED] = true;
    }

    /** @brief start a coroutine to discover terminus
     *
     *  @param[in] mctpInfos - list information of the MCTP endpoints
     */
    void discoverMctpTerminus(const MctpInfos& mctpInfos);

    /** @brief remove MCTP endpoints
     *
     *  @param[in] mctpInfos - list information of the MCTP endpoints
     */
    void removeMctpTerminus(const MctpInfos& mctpInfos);

    /** @brief Send request PLDM message to tid. The function will return when
     *         received the response message from terminus. The function will
     *         auto get the instanceID from libmctp and update to request
     *         message.
     *
     *  @param[in] tid - Destination TID
     *  @param[in] request - request PLDM message
     *  @param[out] responseMsg - response PLDM message
     *  @param[out] responseLen - length of response PLDM message
     *  @return coroutine return_value - PLDM completion code
     */
    exec::task<int> sendRecvPldmMsg(pldm_tid_t tid, Request& request,
                                    const pldm_msg** responseMsg,
                                    size_t* responseLen);

    /** @brief Send request PLDM message to eid. The function will
     *         return when received the response message from terminus.
     *
     *  @param[in] eid - Destination EID
     *  @param[in] request - request PLDM message
     *  @param[out] responseMsg - response PLDM message
     *  @param[out] responseLen - length of response PLDM message
     *  @return coroutine return_value - PLDM completion code
     */
    virtual exec::task<int> sendRecvPldmMsgOverMctp(
        mctp_eid_t eid, Request& request, const pldm_msg** responseMsg,
        size_t* responseLen);

    /** @brief member functions to map/unmap tid
     */
    std::optional<MctpInfo> toMctpInfo(const pldm_tid_t& tid);

    /** @brief Member functions to response the TID of specific MCTP interface
     *
     *  @param[in] mctpInfos - list information of the MCTP endpoints
     *
     *  @return tid - Terminus tid
     */
    std::optional<pldm_tid_t> toTid(const MctpInfo& mctpInfo) const;

    /** @brief Member functions to find the TID for MCTP interface. Response the
     *         Terminus TID when mctpInfo is already in the data base. Response
     *         new tid from pool when mctpInfo is new.
     *
     *  @param[in] mctpInfos - list information of the MCTP endpoints
     *
     *  @return tid - Terminus tid
     */
    std::optional<pldm_tid_t> mapTid(const MctpInfo& mctpInfo);

    /** @brief Member functions to store the mctp info and tid to terminus info
     *         list.
     *
     *  @param[in] mctpInfos - list information of the MCTP endpoints
     *  @param[in] tid - Destination TID
     *
     *  @return tid - Terminus tid
     */
    std::optional<pldm_tid_t>
        storeTerminusInfo(const MctpInfo& mctpInfo, pldm_tid_t tid);

    /** @brief Member functions to remove the TID from the transportLayer and
     *         mctpInfo table
     *
     *  @param[in] tid - Destination TID
     *
     *  @return true/false - True when tid in the table otherwise return false
     */
    bool unmapTid(const pldm_tid_t& tid);

    /** @brief getter of local EID
     *
     *  @return uint8_t - local EID
     */
    mctp_eid_t getLocalEid()
    {
        return localEid;
    }

  private:
    /** @brief Find the terminus object pointer in termini list.
     *
     *  @param[in] mctpInfos - list information of the MCTP endpoints
     */
    TerminiMapper::iterator findTerminusPtr(const MctpInfo& mctpInfo);

    /** @brief The coroutine task execute by discoverMctpTerminus()
     *
     *  @return coroutine return_value - PLDM completion code
     */
    exec::task<int> discoverMctpTerminusTask();

    /** @brief Initialize terminus and then instantiate terminus object to keeps
     *         the data fetched from terminus
     *
     *  @param[in] mctpInfo - information of the MCTP endpoints
     *  @return coroutine return_value - PLDM completion code
     */
    exec::task<int> initMctpTerminus(const MctpInfo& mctpInfo);

    /** @brief Send getTID PLDM command to destination EID and then return the
     *         value of tid in reference parameter.
     *
     *  @param[in] eid - Destination EID
     *  @param[out] tid - Terminus TID
     *  @return coroutine return_value - PLDM completion code
     */
    exec::task<int> getTidOverMctp(mctp_eid_t eid, pldm_tid_t* tid);

    /** @brief Send setTID command to destination EID.
     *
     *  @param[in] eid - Destination EID
     *  @param[in] tid - Destination TID
     *  @return coroutine return_value - PLDM completion code
     */
    exec::task<int> setTidOverMctp(mctp_eid_t eid, pldm_tid_t tid);

    /** @brief Send getPLDMTypes command to destination TID and then return the
     *         value of supportedTypes in reference parameter.
     *
     *  @param[in] tid - Destination TID
     *  @param[out] supportedTypes - Supported Types returned from terminus
     *  @return coroutine return_value - PLDM completion code
     */
    exec::task<int> getPLDMTypes(pldm_tid_t tid, uint64_t& supportedTypes);

    /** @brief Send getPLDMCommands command to destination TID and then return
     *         the value of supportedCommands in reference parameter.
     *
     *  @param[in] tid - Destination TID
     *  @param[in] type - PLDM Type
     *  @param[in] supportedCmds - Supported commands returned from terminus
     *                             for specific type
     *  @return coroutine return_value - PLDM completion code
     */
    exec::task<int> getPLDMCommands(pldm_tid_t tid, uint8_t type,
                                    bitfield8_t* supportedCmds);

    /** @brief Reference to a Handler object that manages the request/response
     *         logic.
     */
    RequesterHandler& handler;

    /** @brief Reference to the instanceID data base from libpldm */
    pldm::InstanceIdDb& instanceIdDb;

    /** @brief Managed termini list */
    TerminiMapper& termini;

    /** @brief tables for maintaining assigned TID */
    std::vector<bool> tidPool;

    /** @brief Store the supported transport layers of specific TID */
    std::map<pldm_tid_t, SupportedTransportLayer> transportLayerTable;

    /** @brief Store the supported MCTP interface info of specific TID */
    std::map<pldm_tid_t, MctpInfo> mctpInfoTable;

    /** @brief A queue of MctpInfos to be discovered **/
    std::queue<MctpInfos> queuedMctpInfos{};

    /** @brief coroutine handle of discoverTerminusTask */
    std::optional<std::pair<exec::async_scope, std::optional<int>>>
        discoverMctpTerminusTaskHandle{};

    /** @brief A Manager interface for calling the hook functions **/
    Manager* manager;

    /** @brief local EID */
    mctp_eid_t localEid;
};
} // namespace platform_mc
} // namespace pldm
