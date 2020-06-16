#include "fru.hpp"

#include "libpldm/utils.h"

#include "utils.hpp"

#include <systemd/sd-journal.h>

#include <sdbusplus/bus.hpp>

#include <iostream>
#include <set>

namespace pldm
{

namespace responder
{

FruImpl::FruImpl(const std::string& configPath, pldm_pdr* pdrRepo,
                 pldm_entity_association_tree* entityTree) :
    pdrRepo(pdrRepo),
    entityTree(entityTree)
{
    fru_parser::FruParser handle(configPath);

    fru_parser::DBusLookupInfo dbusInfo;
    // Read the all the inventory D-Bus objects
    auto& bus = pldm::utils::DBusHandler::getBus();
    dbus::ObjectValueTree objects;

    try
    {
        dbusInfo = handle.inventoryLookup();
        auto method = bus.new_method_call(
            std::get<0>(dbusInfo).c_str(), std::get<1>(dbusInfo).c_str(),
            "org.freedesktop.DBus.ObjectManager", "GetManagedObjects");
        auto reply = bus.call(method);
        reply.read(objects);
    }
    catch (const std::exception& e)
    {
        std::cerr << "Look up of inventory objects failed and PLDM FRU table "
                     "creation failed";
        return;
    }

    auto itemIntfsLookup = std::get<2>(dbusInfo);

    for (const auto& object : objects)
    {
        const auto& interfaces = object.second;

        for (const auto& interface : interfaces)
        {
            if (itemIntfsLookup.find(interface.first) != itemIntfsLookup.end())
            {
                // An exception will be thrown by getRecordInfo, if the item
                // D-Bus interface name specified in FRU_Master.json does
                // not have corresponding config jsons
                try
                {
                    pldm_entity entity{};
                    entity.entity_type = handle.getEntityType(interface.first);
                    pldm_entity_node* parent = nullptr;
                    auto parentObj = pldm::utils::findParent(object.first.str);
                    // To add a FRU to the entity association tree, we need to
                    // determine if the FRU has a parent (D-Bus object). For eg
                    // /system/backplane's parent is /system. /system has no
                    // parent. Some D-Bus pathnames might just be namespaces
                    // (not D-Bus objects), so we need to iterate upwards until
                    // a parent is found, or we reach the root ("/").
                    // Parents are always added first before children in the
                    // entity association tree. We're relying on the fact that
                    // the std::map containing object paths from the
                    // GetManagedObjects call will have a sorted pathname list.
                    do
                    {
                        auto iter = objToEntityNode.find(parentObj);
                        if (iter != objToEntityNode.end())
                        {
                            parent = iter->second;
                            break;
                        }
                        parentObj = pldm::utils::findParent(parentObj);
                    } while (parentObj != "/");

                    auto node = pldm_entity_association_tree_add(
                        entityTree, &entity, parent,
                        PLDM_ENTITY_ASSOCIAION_PHYSICAL);
                    objToEntityNode[object.first.str] = node;

                    auto recordInfos = handle.getRecordInfo(interface.first);
                    populateRecords(interfaces, recordInfos, entity);
                    break;
                }
                catch (const std::exception& e)
                {
                    std::cout << "Config JSONs missing for the item "
                                 "interface type, interface = "
                              << interface.first << "\n";
                    break;
                }
            }
        }
    }

    pldm_entity_association_pdr_add(entityTree, pdrRepo, false);

    if (table.size())
    {
        padBytes = utils::getNumPadBytes(table.size());
        table.resize(table.size() + padBytes, 0);

        // Calculate the checksum
        checksum = crc32(table.data(), table.size());
    }
}

void FruImpl::populateRecords(
    const pldm::responder::dbus::InterfaceMap& interfaces,
    const fru_parser::FruRecordInfos& recordInfos, const pldm_entity& entity)
{
    // recordSetIdentifier for the FRU will be set when the first record gets
    // added for the FRU
    uint16_t recordSetIdentifier = 0;
    auto numRecsCount = numRecs;

    for (auto const& [recType, encType, fieldInfos] : recordInfos)
    {
        std::vector<uint8_t> tlvs;
        uint8_t numFRUFields = 0;
        for (auto const& [intf, prop, propType, fieldTypeNum] : fieldInfos)
        {
            try
            {
                auto propValue = interfaces.at(intf).at(prop);
                if (propType == "bytearray")
                {
                    auto byteArray = std::get<std::vector<uint8_t>>(propValue);
                    if (!byteArray.size())
                    {
                        continue;
                    }

                    numFRUFields++;
                    tlvs.emplace_back(fieldTypeNum);
                    tlvs.emplace_back(byteArray.size());
                    std::move(std::begin(byteArray), std::end(byteArray),
                              std::back_inserter(tlvs));
                }
                else if (propType == "string")
                {
                    auto str = std::get<std::string>(propValue);
                    if (!str.size())
                    {
                        continue;
                    }

                    numFRUFields++;
                    tlvs.emplace_back(fieldTypeNum);
                    tlvs.emplace_back(str.size());
                    std::move(std::begin(str), std::end(str),
                              std::back_inserter(tlvs));
                }
            }
            catch (const std::out_of_range& e)
            {
                continue;
            }
        }

        if (tlvs.size())
        {
            if (numRecs == numRecsCount)
            {
                recordSetIdentifier = nextRSI();
                pldm_pdr_add_fru_record_set(
                    pdrRepo, 0, recordSetIdentifier, entity.entity_type,
                    entity.entity_instance_num, entity.entity_container_id);
            }
            auto curSize = table.size();
            table.resize(curSize + recHeaderSize + tlvs.size());
            encode_fru_record(table.data(), table.size(), &curSize,
                              recordSetIdentifier, recType, numFRUFields,
                              encType, tlvs.data(), tlvs.size());
            numRecs++;
        }
    }
}

void FruImpl::getFRUTable(Response& response)
{
    auto hdrSize = response.size();

    response.resize(hdrSize + table.size() + sizeof(checksum), 0);
    std::copy(table.begin(), table.end(), response.begin() + hdrSize);

    // Copy the checksum to response data
    auto iter = response.begin() + hdrSize + table.size();
    std::copy_n(reinterpret_cast<const uint8_t*>(&checksum), sizeof(checksum),
                iter);
}

namespace fru
{

Response Handler::getFRURecordTableMetadata(const pldm_msg* request,
                                            size_t /*payloadLength*/)
{
    constexpr uint8_t major = 0x01;
    constexpr uint8_t minor = 0x00;
    constexpr uint32_t maxSize = 0xFFFFFFFF;

    Response response(sizeof(pldm_msg_hdr) +
                          PLDM_GET_FRU_RECORD_TABLE_METADATA_RESP_BYTES,
                      0);
    auto responsePtr = reinterpret_cast<pldm_msg*>(response.data());

    auto rc = encode_get_fru_record_table_metadata_resp(
        request->hdr.instance_id, PLDM_SUCCESS, major, minor, maxSize,
        impl.size(), impl.numRSI(), impl.numRecords(), impl.checkSum(),
        responsePtr);
    if (rc != PLDM_SUCCESS)
    {
        return ccOnlyResponse(request, rc);
    }

    return response;
}

Response Handler::getFRURecordTable(const pldm_msg* request,
                                    size_t payloadLength)
{
    if (payloadLength != PLDM_GET_FRU_RECORD_TABLE_REQ_BYTES)
    {
        return ccOnlyResponse(request, PLDM_ERROR_INVALID_LENGTH);
    }

    Response response(
        sizeof(pldm_msg_hdr) + PLDM_GET_FRU_RECORD_TABLE_MIN_RESP_BYTES, 0);
    auto responsePtr = reinterpret_cast<pldm_msg*>(response.data());

    auto rc =
        encode_get_fru_record_table_resp(request->hdr.instance_id, PLDM_SUCCESS,
                                         0, PLDM_START_AND_END, responsePtr);
    if (rc != PLDM_SUCCESS)
    {
        return ccOnlyResponse(request, rc);
    }

    impl.getFRUTable(response);

    return response;
}

} // namespace fru

} // namespace responder

} // namespace pldm
