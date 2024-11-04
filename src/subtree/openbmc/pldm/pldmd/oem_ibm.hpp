#pragma once

#include "../oem/ibm/host-bmc/host_lamp_test.hpp"
#include "../oem/ibm/libpldmresponder/file_io.hpp"
#include "../oem/ibm/libpldmresponder/fru_oem_ibm.hpp"
#include "../oem/ibm/libpldmresponder/oem_ibm_handler.hpp"
#include "../oem/ibm/libpldmresponder/utils.hpp"
#include "common/utils.hpp"
#include "dbus_impl_requester.hpp"
#include "host-bmc/dbus_to_event_handler.hpp"
#include "invoker.hpp"
#include "libpldmresponder/base.hpp"
#include "libpldmresponder/fru.hpp"
#include "requester/request.hpp"

#include <libpldm/pdr.h>

namespace pldm
{
namespace oem_ibm
{

using namespace pldm::state_sensor;
using namespace pldm::dbus_api;

/**
 * @class OemIBM
 *
 * @brief class for creating all the OEM IBM handlers
 *
 *  Only in case of OEM_IBM this class object will be instantiated
 */
class OemIBM
{
  public:
    OemIBM() = delete;
    OemIBM(const Pdr&) = delete;
    OemIBM& operator=(const OemIBM&) = delete;
    OemIBM(OemIBM&&) = delete;
    OemIBM& operator=(OemIBM&&) = delete;

  public:
    /** Constructs OemIBM object
     *
     * @param[in] dBusIntf - D-Bus handler
     * @param[in] mctp_fd - fd of MCTP communications socket
     * @param[in] mctp_eid - MCTP EID of remote host firmware
     * @param[in] repo - pointer to BMC's primary PDR repo
     * @param[in] instanceIdDb - pointer to an InstanceIdDb object
     * @param[in] event - sd_event handler
     * @param[in] invoker - invoker handler
     * @param[in] hostPDRHandler - hostPDRHandler handler
     * @param[in] platformHandler - platformHandler handler
     * @param[in] fruHandler - fruHandler handler
     * @param[in] baseHandler - baseHandler handler
     * @param[in] reqHandler - reqHandler handler
     */
    explicit OemIBM(
        const pldm::utils::DBusHandler* dBusIntf, int mctp_fd, uint8_t mctp_eid,
        pldm_pdr* repo, pldm::InstanceIdDb& instanceIdDb,
        sdeventplus::Event& event, responder::Invoker& invoker,
        HostPDRHandler* hostPDRHandler,
        responder::platform::Handler* platformHandler,
        responder::fru::Handler* fruHandler,
        responder::base::Handler* baseHandler,
        pldm::requester::Handler<pldm::requester::Request>* reqHandler) :
        dBusIntf(dBusIntf), mctp_fd(mctp_fd), mctp_eid(mctp_eid), repo(repo),
        instanceIdDb(instanceIdDb), event(event), invoker(invoker),
        reqHandler(reqHandler)
    {
        createOemFruHandler();
        fruHandler->setOemFruHandler(oemFruHandler.get());

        createOemIbmFruHandler();
        oemIbmFruHandler->setIBMFruHandler(fruHandler);

        createCodeUpdate();
        createSlotHandler();
        createOemPlatformHandler();
        createOemIbmUtilsHandler();
        codeUpdate->setOemPlatformHandler(oemPlatformHandler.get());
        hostPDRHandler->setOemPlatformHandler(oemPlatformHandler.get());
        hostPDRHandler->setOemUtilsHandler(oemUtilsHandler.get());
        platformHandler->setOemPlatformHandler(oemPlatformHandler.get());
        baseHandler->setOemPlatformHandler(oemPlatformHandler.get());
        slotHandler->setOemPlatformHandler(oemPlatformHandler.get());

        createOemIbmPlatformHandler();
        oemIbmPlatformHandler->setPlatformHandler(platformHandler);

        createHostLampTestHandler();

        registerHandler();
    }

  private:
    /** @brief Method for creating codeUpdate handler */
    void createCodeUpdate()
    {
        codeUpdate = std::make_unique<pldm::responder::CodeUpdate>(dBusIntf);
        codeUpdate->clearDirPath(LID_STAGING_DIR);
    }

    /** @brief Method for creating slot handler */
    void createSlotHandler()
    {
        slotHandler =
            std::make_unique<pldm::responder::SlotHandler>(event, repo);
    }

    /** @brief Method for creating oemPlatformHandler
     *
     *  This method also assigns the oemPlatformHandler to the below
     *  different handlers.
     */
    void createOemPlatformHandler()
    {
        oemPlatformHandler = std::make_unique<oem_ibm_platform::Handler>(
            dBusIntf, codeUpdate.get(), slotHandler.get(), mctp_fd, mctp_eid,
            instanceIdDb, event, reqHandler);
    }

    /** @brief Method for creating oemIbmPlatformHandler */
    void createOemIbmPlatformHandler()
    {
        oemIbmPlatformHandler =
            dynamic_cast<pldm::responder::oem_ibm_platform::Handler*>(
                oemPlatformHandler.get());
    }

    /** @brief Method for creating oemFruHandler */
    void createOemFruHandler()
    {
        oemFruHandler = std::make_unique<responder::oem_ibm_fru::Handler>(repo);
    }

    /** @brief Method for creating oemIbmUtilsHandler */
    void createOemIbmUtilsHandler()
    {
        oemUtilsHandler =
            std::make_unique<responder::oem_ibm_utils::Handler>(dBusIntf);
    }

    /** @brief Method for creating oemIbmFruHandler */
    void createOemIbmFruHandler()
    {
        oemIbmFruHandler = dynamic_cast<pldm::responder::oem_ibm_fru::Handler*>(
            oemFruHandler.get());
    }

    void createHostLampTestHandler()
    {
        auto& bus = pldm::utils::DBusHandler::getBus();
        hostLampTest = std::make_unique<pldm::led::HostLampTest>(
            bus, "/xyz/openbmc_project/led/groups/host_lamp_test", mctp_eid,
            instanceIdDb, repo, reqHandler);
    }

    /** @brief Method for registering PLDM OEM handler */
    void registerHandler()
    {
        invoker.registerHandler(
            PLDM_OEM, std::make_unique<pldm::responder::oem_ibm::Handler>(
                          oemPlatformHandler.get(), mctp_fd, mctp_eid,
                          &instanceIdDb, reqHandler));
    }

  private:
    /** @brief D-Bus handler */
    const pldm::utils::DBusHandler* dBusIntf;

    /** @brief fd of MCTP communications socket */
    int mctp_fd;

    /** @brief MCTP EID of remote host firmware */
    uint8_t mctp_eid;

    /** @brief pointer to BMC's primary PDR repo */
    pldm_pdr* repo;

    /** @brief reference to an Instance ID database object, used to obtain PLDM
     * instance IDs
     */
    pldm::InstanceIdDb& instanceIdDb;

    /** @brief reference of main event loop of pldmd, primarily used to schedule
     *  work
     */
    sdeventplus::Event& event;

    /** @brief Object to the invoker class*/
    responder::Invoker& invoker;

    /** @brief pointer to the requester class*/
    requester::Handler<requester::Request>* reqHandler;

    /** @brief pointer to the oem_ibm_handler class*/
    std::unique_ptr<responder::oem_platform::Handler> oemPlatformHandler{};

    /** @brief pointer to the oem_ibm_fru class*/
    std::unique_ptr<responder::oem_fru::Handler> oemFruHandler{};

    /** @brief pointer to the CodeUpdate class*/
    std::unique_ptr<pldm::responder::CodeUpdate> codeUpdate{};

    /** @brief pointer to the SlotHanlder class*/
    std::unique_ptr<pldm::responder::SlotHandler> slotHandler{};

    /** @brief oem IBM Platform handler*/
    pldm::responder::oem_ibm_platform::Handler* oemIbmPlatformHandler = nullptr;

    /** @brief oem IBM Fru handler*/
    pldm::responder::oem_ibm_fru::Handler* oemIbmFruHandler = nullptr;

    std::unique_ptr<pldm::led::HostLampTest> hostLampTest;

    /** @brief oem IBM Utils handler*/
    std::unique_ptr<responder::oem_utils::Handler> oemUtilsHandler;
};

} // namespace oem_ibm
} // namespace pldm
