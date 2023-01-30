#include "package_parser.hpp"

#include "common/utils.hpp"

#include <libpldm/firmware_update.h>
#include <libpldm/utils.h>

#include <xyz/openbmc_project/Common/error.hpp>

#include <iostream>
#include <memory>

namespace pldm
{

namespace fw_update
{

using InternalFailure =
    sdbusplus::xyz::openbmc_project::Common::Error::InternalFailure;

size_t PackageParser::parseFDIdentificationArea(
    DeviceIDRecordCount deviceIdRecCount, const std::vector<uint8_t>& pkgHdr,
    size_t offset)
{
    size_t pkgHdrRemainingSize = pkgHdr.size() - offset;

    while (deviceIdRecCount-- && (pkgHdrRemainingSize > 0))
    {
        pldm_firmware_device_id_record deviceIdRecHeader{};
        variable_field applicableComponents{};
        variable_field compImageSetVersionStr{};
        variable_field recordDescriptors{};
        variable_field fwDevicePkgData{};

        auto rc = decode_firmware_device_id_record(
            pkgHdr.data() + offset, pkgHdrRemainingSize,
            componentBitmapBitLength, &deviceIdRecHeader, &applicableComponents,
            &compImageSetVersionStr, &recordDescriptors, &fwDevicePkgData);
        if (rc)
        {
            std::cerr << "Decoding firmware device ID record failed, RC=" << rc
                      << "\n";
            throw InternalFailure();
        }

        Descriptors descriptors{};
        while (deviceIdRecHeader.descriptor_count-- &&
               (recordDescriptors.length > 0))
        {
            uint16_t descriptorType = 0;
            variable_field descriptorData{};

            rc = decode_descriptor_type_length_value(
                recordDescriptors.ptr, recordDescriptors.length,
                &descriptorType, &descriptorData);
            if (rc)
            {
                std::cerr
                    << "Decoding descriptor type, length and value failed, RC="
                    << rc << "\n";
                throw InternalFailure();
            }

            if (descriptorType != PLDM_FWUP_VENDOR_DEFINED)
            {
                descriptors.emplace(
                    descriptorType,
                    DescriptorData{descriptorData.ptr,
                                   descriptorData.ptr + descriptorData.length});
            }
            else
            {
                uint8_t descTitleStrType = 0;
                variable_field descTitleStr{};
                variable_field vendorDefinedDescData{};

                rc = decode_vendor_defined_descriptor_value(
                    descriptorData.ptr, descriptorData.length,
                    &descTitleStrType, &descTitleStr, &vendorDefinedDescData);
                if (rc)
                {
                    std::cerr << "Decoding Vendor-defined descriptor value "
                                 "failed, RC="
                              << rc << "\n";
                    throw InternalFailure();
                }

                descriptors.emplace(
                    descriptorType,
                    std::make_tuple(utils::toString(descTitleStr),
                                    VendorDefinedDescriptorData{
                                        vendorDefinedDescData.ptr,
                                        vendorDefinedDescData.ptr +
                                            vendorDefinedDescData.length}));
            }

            auto nextDescriptorOffset =
                sizeof(pldm_descriptor_tlv().descriptor_type) +
                sizeof(pldm_descriptor_tlv().descriptor_length) +
                descriptorData.length;
            recordDescriptors.ptr += nextDescriptorOffset;
            recordDescriptors.length -= nextDescriptorOffset;
        }

        DeviceUpdateOptionFlags deviceUpdateOptionFlags =
            deviceIdRecHeader.device_update_option_flags.value;

        ApplicableComponents componentsList;

        for (size_t varBitfieldIdx = 0;
             varBitfieldIdx < applicableComponents.length; varBitfieldIdx++)
        {
            std::bitset<8> entry{*(applicableComponents.ptr + varBitfieldIdx)};
            for (size_t idx = 0; idx < entry.size(); idx++)
            {
                if (entry[idx])
                {
                    componentsList.emplace_back(
                        idx + (varBitfieldIdx * entry.size()));
                }
            }
        }

        fwDeviceIDRecords.emplace_back(std::make_tuple(
            deviceUpdateOptionFlags, componentsList,
            utils::toString(compImageSetVersionStr), std::move(descriptors),
            FirmwareDevicePackageData{fwDevicePkgData.ptr,
                                      fwDevicePkgData.ptr +
                                          fwDevicePkgData.length}));
        offset += deviceIdRecHeader.record_length;
        pkgHdrRemainingSize -= deviceIdRecHeader.record_length;
    }

    return offset;
}

size_t PackageParser::parseCompImageInfoArea(ComponentImageCount compImageCount,
                                             const std::vector<uint8_t>& pkgHdr,
                                             size_t offset)
{
    size_t pkgHdrRemainingSize = pkgHdr.size() - offset;

    while (compImageCount-- && (pkgHdrRemainingSize > 0))
    {
        pldm_component_image_information compImageInfo{};
        variable_field compVersion{};

        auto rc = decode_pldm_comp_image_info(pkgHdr.data() + offset,
                                              pkgHdrRemainingSize,
                                              &compImageInfo, &compVersion);
        if (rc)
        {
            std::cerr << "Decoding component image information failed, RC="
                      << rc << "\n";
            throw InternalFailure();
        }

        CompClassification compClassification =
            compImageInfo.comp_classification;
        CompIdentifier compIdentifier = compImageInfo.comp_identifier;
        CompComparisonStamp compComparisonTime =
            compImageInfo.comp_comparison_stamp;
        CompOptions compOptions = compImageInfo.comp_options.value;
        ReqCompActivationMethod reqCompActivationMethod =
            compImageInfo.requested_comp_activation_method.value;
        CompLocationOffset compLocationOffset =
            compImageInfo.comp_location_offset;
        CompSize compSize = compImageInfo.comp_size;

        componentImageInfos.emplace_back(std::make_tuple(
            compClassification, compIdentifier, compComparisonTime, compOptions,
            reqCompActivationMethod, compLocationOffset, compSize,
            utils::toString(compVersion)));
        offset += sizeof(pldm_component_image_information) +
                  compImageInfo.comp_version_string_length;
        pkgHdrRemainingSize -= sizeof(pldm_component_image_information) +
                               compImageInfo.comp_version_string_length;
    }

    return offset;
}

void PackageParser::validatePkgTotalSize(uintmax_t pkgSize)
{
    uintmax_t calcPkgSize = pkgHeaderSize;
    for (const auto& componentImageInfo : componentImageInfos)
    {
        CompLocationOffset compLocOffset = std::get<static_cast<size_t>(
            ComponentImageInfoPos::CompLocationOffsetPos)>(componentImageInfo);
        CompSize compSize =
            std::get<static_cast<size_t>(ComponentImageInfoPos::CompSizePos)>(
                componentImageInfo);

        if (compLocOffset != calcPkgSize)
        {
            std::cerr << "Validating the component location offset failed, "
                         "COMP_VERSION="
                      << std::get<static_cast<size_t>(
                             ComponentImageInfoPos::CompVersionPos)>(
                             componentImageInfo)
                      << "\n";
            throw InternalFailure();
        }

        calcPkgSize += compSize;
    }

    if (calcPkgSize != pkgSize)
    {
        std::cerr
            << "Package size does not match calculated package size, PKG_SIZE="
            << pkgSize << " ,CALC_PKG_SIZE=" << calcPkgSize << "\n";
        throw InternalFailure();
    }
}

void PackageParserV1::parse(const std::vector<uint8_t>& pkgHdr,
                            uintmax_t pkgSize)
{
    if (pkgHeaderSize != pkgHdr.size())
    {
        std::cerr << "Package header size is invalid, PKG_HDR_SIZE="
                  << pkgHeaderSize << "\n";
        throw InternalFailure();
    }

    size_t offset = sizeof(pldm_package_header_information) + pkgVersion.size();
    if (offset + sizeof(DeviceIDRecordCount) >= pkgHeaderSize)
    {
        std::cerr << "Parsing package header failed, PKG_HDR_SIZE="
                  << pkgHeaderSize << "\n";
        throw InternalFailure();
    }

    auto deviceIdRecCount = static_cast<DeviceIDRecordCount>(pkgHdr[offset]);
    offset += sizeof(DeviceIDRecordCount);

    offset = parseFDIdentificationArea(deviceIdRecCount, pkgHdr, offset);
    if (deviceIdRecCount != fwDeviceIDRecords.size())
    {
        std::cerr
            << "DeviceIDRecordCount entries not found, DEVICE_ID_REC_COUNT="
            << deviceIdRecCount << "\n";
        throw InternalFailure();
    }
    if (offset + sizeof(ComponentImageCount) >= pkgHeaderSize)
    {
        std::cerr << "Parsing package header failed, PKG_HDR_SIZE="
                  << pkgHeaderSize << "\n";
        throw InternalFailure();
    }

    auto compImageCount = static_cast<ComponentImageCount>(
        le16toh(pkgHdr[offset] | (pkgHdr[offset + 1] << 8)));
    offset += sizeof(ComponentImageCount);

    offset = parseCompImageInfoArea(compImageCount, pkgHdr, offset);
    if (compImageCount != componentImageInfos.size())
    {
        std::cerr << "ComponentImageCount entries not found, COMP_IMAGE_COUNT="
                  << compImageCount << "\n";
        throw InternalFailure();
    }

    if (offset + sizeof(PackageHeaderChecksum) != pkgHeaderSize)
    {
        std::cerr << "Parsing package header failed, PKG_HDR_SIZE="
                  << pkgHeaderSize << "\n";
        throw InternalFailure();
    }

    auto calcChecksum = crc32(pkgHdr.data(), offset);
    auto checksum = static_cast<PackageHeaderChecksum>(
        le32toh(pkgHdr[offset] | (pkgHdr[offset + 1] << 8) |
                (pkgHdr[offset + 2] << 16) | (pkgHdr[offset + 3] << 24)));
    if (calcChecksum != checksum)
    {
        std::cerr << "Parsing package header failed, CALC_CHECKSUM="
                  << calcChecksum << ", PKG_HDR_CHECKSUM=" << checksum << "\n";
        throw InternalFailure();
    }

    validatePkgTotalSize(pkgSize);
}

std::unique_ptr<PackageParser> parsePkgHeader(std::vector<uint8_t>& pkgData)
{
    constexpr std::array<uint8_t, PLDM_FWUP_UUID_LENGTH> hdrIdentifierv1{
        0xF0, 0x18, 0x87, 0x8C, 0xCB, 0x7D, 0x49, 0x43,
        0x98, 0x00, 0xA0, 0x2F, 0x05, 0x9A, 0xCA, 0x02};
    constexpr uint8_t pkgHdrVersion1 = 0x01;

    pldm_package_header_information pkgHeader{};
    variable_field pkgVersion{};
    auto rc = decode_pldm_package_header_info(pkgData.data(), pkgData.size(),
                                              &pkgHeader, &pkgVersion);
    if (rc)
    {
        std::cerr << "Decoding PLDM package header information failed, RC="
                  << rc << "\n";
        return nullptr;
    }

    if (std::equal(pkgHeader.uuid, pkgHeader.uuid + PLDM_FWUP_UUID_LENGTH,
                   hdrIdentifierv1.begin(), hdrIdentifierv1.end()) &&
        (pkgHeader.package_header_format_version == pkgHdrVersion1))
    {
        PackageHeaderSize pkgHdrSize = pkgHeader.package_header_size;
        ComponentBitmapBitLength componentBitmapBitLength =
            pkgHeader.component_bitmap_bit_length;
        return std::make_unique<PackageParserV1>(
            pkgHdrSize, utils::toString(pkgVersion), componentBitmapBitLength);
    }

    return nullptr;
}

} // namespace fw_update

} // namespace pldm