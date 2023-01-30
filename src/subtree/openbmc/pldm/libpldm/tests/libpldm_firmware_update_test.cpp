#include <endian.h>

#include <algorithm>
#include <array>
#include <bitset>
#include <cstdint>
#include <cstring>
#include <string>
#include <string_view>
#include <vector>

#include "libpldm/base.h"
#include "libpldm/firmware_update.h"
#include "pldm_types.h"
#include "utils.h"

#include <gtest/gtest.h>

constexpr auto hdrSize = sizeof(pldm_msg_hdr);

TEST(DecodePackageHeaderInfo, goodPath)
{
    // Package header identifier for Version 1.0.x
    constexpr std::array<uint8_t, PLDM_FWUP_UUID_LENGTH> uuid{
        0xf0, 0x18, 0x87, 0x8c, 0xcb, 0x7d, 0x49, 0x43,
        0x98, 0x00, 0xa0, 0x2F, 0x05, 0x9a, 0xca, 0x02};
    // Package header version for DSP0267 version 1.0.x
    constexpr uint8_t pkgHeaderFormatRevision = 0x01;
    // Random PackageHeaderSize
    constexpr uint16_t pkgHeaderSize = 303;
    // PackageReleaseDateTime - "25/12/2021 00:00:00"
    std::array<uint8_t, PLDM_TIMESTAMP104_SIZE> package_release_date_time{
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x19, 0x0c, 0xe5, 0x07, 0x00};
    constexpr uint16_t componentBitmapBitLength = 8;
    // PackageVersionString
    constexpr std::string_view packageVersionStr{"OpenBMCv1.0"};
    constexpr size_t packagerHeaderSize =
        sizeof(pldm_package_header_information) + packageVersionStr.size();

    constexpr std::array<uint8_t, packagerHeaderSize> packagerHeaderInfo{
        0xf0, 0x18, 0x87, 0x8c, 0xcb, 0x7d, 0x49, 0x43, 0x98, 0x00, 0xa0, 0x2F,
        0x05, 0x9a, 0xca, 0x02, 0x01, 0x2f, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x19, 0x0c, 0xe5, 0x07, 0x00, 0x08, 0x00, 0x01, 0x0b,
        0x4f, 0x70, 0x65, 0x6e, 0x42, 0x4d, 0x43, 0x76, 0x31, 0x2e, 0x30};
    pldm_package_header_information pkgHeader{};
    variable_field packageVersion{};

    auto rc = decode_pldm_package_header_info(packagerHeaderInfo.data(),
                                              packagerHeaderInfo.size(),
                                              &pkgHeader, &packageVersion);

    EXPECT_EQ(rc, PLDM_SUCCESS);
    EXPECT_EQ(true,
              std::equal(pkgHeader.uuid, pkgHeader.uuid + PLDM_FWUP_UUID_LENGTH,
                         uuid.begin(), uuid.end()));
    EXPECT_EQ(pkgHeader.package_header_format_version, pkgHeaderFormatRevision);
    EXPECT_EQ(pkgHeader.package_header_size, pkgHeaderSize);
    EXPECT_EQ(true, std::equal(pkgHeader.package_release_date_time,
                               pkgHeader.package_release_date_time +
                                   PLDM_TIMESTAMP104_SIZE,
                               package_release_date_time.begin(),
                               package_release_date_time.end()));
    EXPECT_EQ(pkgHeader.component_bitmap_bit_length, componentBitmapBitLength);
    EXPECT_EQ(pkgHeader.package_version_string_type, PLDM_STR_TYPE_ASCII);
    EXPECT_EQ(pkgHeader.package_version_string_length,
              packageVersionStr.size());
    std::string packageVersionString(
        reinterpret_cast<const char*>(packageVersion.ptr),
        packageVersion.length);
    EXPECT_EQ(packageVersionString, packageVersionStr);
}

TEST(DecodePackageHeaderInfo, errorPaths)
{
    int rc = 0;
    constexpr std::string_view packageVersionStr{"OpenBMCv1.0"};
    constexpr size_t packagerHeaderSize =
        sizeof(pldm_package_header_information) + packageVersionStr.size();

    // Invalid Package Version String Type - 0x06
    constexpr std::array<uint8_t, packagerHeaderSize>
        invalidPackagerHeaderInfo1{
            0xf0, 0x18, 0x87, 0x8c, 0xcb, 0x7d, 0x49, 0x43, 0x98, 0x00,
            0xa0, 0x2F, 0x05, 0x9a, 0xca, 0x02, 0x02, 0x2f, 0x01, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x19, 0x0c, 0xe5,
            0x07, 0x00, 0x08, 0x00, 0x06, 0x0b, 0x4f, 0x70, 0x65, 0x6e,
            0x42, 0x4d, 0x43, 0x76, 0x31, 0x2e, 0x30};

    pldm_package_header_information packageHeader{};
    variable_field packageVersion{};

    rc = decode_pldm_package_header_info(nullptr,
                                         invalidPackagerHeaderInfo1.size(),
                                         &packageHeader, &packageVersion);
    EXPECT_EQ(rc, PLDM_ERROR_INVALID_DATA);

    rc = decode_pldm_package_header_info(invalidPackagerHeaderInfo1.data(),
                                         invalidPackagerHeaderInfo1.size(),
                                         nullptr, &packageVersion);
    EXPECT_EQ(rc, PLDM_ERROR_INVALID_DATA);

    rc = decode_pldm_package_header_info(invalidPackagerHeaderInfo1.data(),
                                         invalidPackagerHeaderInfo1.size(),
                                         &packageHeader, nullptr);
    EXPECT_EQ(rc, PLDM_ERROR_INVALID_DATA);

    rc = decode_pldm_package_header_info(
        invalidPackagerHeaderInfo1.data(),
        sizeof(pldm_package_header_information) - 1, &packageHeader,
        &packageVersion);
    EXPECT_EQ(rc, PLDM_ERROR_INVALID_LENGTH);

    rc = decode_pldm_package_header_info(invalidPackagerHeaderInfo1.data(),
                                         invalidPackagerHeaderInfo1.size(),
                                         &packageHeader, &packageVersion);
    EXPECT_EQ(rc, PLDM_ERROR_INVALID_DATA);

    // Invalid Package Version String Length - 0x00
    constexpr std::array<uint8_t, packagerHeaderSize>
        invalidPackagerHeaderInfo2{
            0xf0, 0x18, 0x87, 0x8c, 0xcb, 0x7d, 0x49, 0x43, 0x98, 0x00,
            0xa0, 0x2F, 0x05, 0x9a, 0xca, 0x02, 0x02, 0x2f, 0x01, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x19, 0x0c, 0xe5,
            0x07, 0x00, 0x08, 0x00, 0x01, 0x00, 0x4f, 0x70, 0x65, 0x6e,
            0x42, 0x4d, 0x43, 0x76, 0x31, 0x2e, 0x30};
    rc = decode_pldm_package_header_info(invalidPackagerHeaderInfo2.data(),
                                         invalidPackagerHeaderInfo2.size(),
                                         &packageHeader, &packageVersion);
    EXPECT_EQ(rc, PLDM_ERROR_INVALID_DATA);

    // Package version string length less than in the header information
    constexpr std::array<uint8_t, packagerHeaderSize - 1>
        invalidPackagerHeaderInfo3{
            0xf0, 0x18, 0x87, 0x8c, 0xcb, 0x7d, 0x49, 0x43, 0x98, 0x00,
            0xa0, 0x2F, 0x05, 0x9a, 0xca, 0x02, 0x02, 0x2f, 0x01, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x19, 0x0c, 0xe5,
            0x07, 0x00, 0x08, 0x00, 0x01, 0x0b, 0x4f, 0x70, 0x65, 0x6e,
            0x42, 0x4d, 0x43, 0x76, 0x31, 0x2e};
    rc = decode_pldm_package_header_info(invalidPackagerHeaderInfo3.data(),
                                         invalidPackagerHeaderInfo3.size(),
                                         &packageHeader, &packageVersion);
    EXPECT_EQ(rc, PLDM_ERROR_INVALID_LENGTH);

    // ComponentBitmapBitLength not a multiple of 8
    constexpr std::array<uint8_t, packagerHeaderSize>
        invalidPackagerHeaderInfo4{
            0xf0, 0x18, 0x87, 0x8c, 0xcb, 0x7d, 0x49, 0x43, 0x98, 0x00,
            0xa0, 0x2F, 0x05, 0x9a, 0xca, 0x02, 0x02, 0x2f, 0x01, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x19, 0x0c, 0xe5,
            0x07, 0x00, 0x09, 0x00, 0x01, 0x0b, 0x4f, 0x70, 0x65, 0x6e,
            0x42, 0x4d, 0x43, 0x76, 0x31, 0x2e, 0x30};
    rc = decode_pldm_package_header_info(invalidPackagerHeaderInfo4.data(),
                                         invalidPackagerHeaderInfo4.size(),
                                         &packageHeader, &packageVersion);
    EXPECT_EQ(rc, PLDM_ERROR_INVALID_DATA);
}

TEST(DecodeFirmwareDeviceIdRecord, goodPath)
{
    constexpr uint8_t descriptorCount = 1;
    // Continue component updates after failure
    constexpr std::bitset<32> deviceUpdateFlag{1};
    constexpr uint16_t componentBitmapBitLength = 16;
    // Applicable Components - 1,2,5,8,9
    std::vector<std::bitset<8>> applicableComponentsBitfield{0x93, 0x01};
    // ComponentImageSetVersionString
    constexpr std::string_view imageSetVersionStr{"VersionString1"};
    // Initial descriptor - UUID
    constexpr std::array<uint8_t, PLDM_FWUP_UUID_LENGTH> uuid{
        0x12, 0x44, 0xd2, 0x64, 0x8d, 0x7d, 0x47, 0x18,
        0xa0, 0x30, 0xfc, 0x8a, 0x56, 0x58, 0x7d, 0x5b};
    constexpr uint16_t fwDevicePkgDataLen = 2;
    // FirmwareDevicePackageData
    constexpr std::array<uint8_t, fwDevicePkgDataLen> fwDevicePkgData{0xab,
                                                                      0xcd};
    // Size of the firmware device ID record
    constexpr uint16_t recordLen =
        sizeof(pldm_firmware_device_id_record) +
        (componentBitmapBitLength / PLDM_FWUP_COMPONENT_BITMAP_MULTIPLE) +
        imageSetVersionStr.size() + sizeof(pldm_descriptor_tlv) - 1 +
        uuid.size() + fwDevicePkgData.size();
    // Firmware device ID record
    constexpr std::array<uint8_t, recordLen> record{
        0x31, 0x00, 0x01, 0x01, 0x00, 0x00, 0x00, 0x01, 0x0e, 0x02,
        0x00, 0x93, 0x01, 0x56, 0x65, 0x72, 0x73, 0x69, 0x6f, 0x6e,
        0x53, 0x74, 0x72, 0x69, 0x6e, 0x67, 0x31, 0x02, 0x00, 0x10,
        0x00, 0x12, 0x44, 0xd2, 0x64, 0x8d, 0x7d, 0x47, 0x18, 0xa0,
        0x30, 0xfc, 0x8a, 0x56, 0x58, 0x7d, 0x5b, 0xab, 0xcd};

    pldm_firmware_device_id_record deviceIdRecHeader{};
    variable_field applicableComponents{};
    variable_field outCompImageSetVersionStr{};
    variable_field recordDescriptors{};
    variable_field outFwDevicePkgData{};

    auto rc = decode_firmware_device_id_record(
        record.data(), record.size(), componentBitmapBitLength,
        &deviceIdRecHeader, &applicableComponents, &outCompImageSetVersionStr,
        &recordDescriptors, &outFwDevicePkgData);

    EXPECT_EQ(rc, PLDM_SUCCESS);
    EXPECT_EQ(deviceIdRecHeader.record_length, recordLen);
    EXPECT_EQ(deviceIdRecHeader.descriptor_count, descriptorCount);
    EXPECT_EQ(deviceIdRecHeader.device_update_option_flags.value,
              deviceUpdateFlag);
    EXPECT_EQ(deviceIdRecHeader.comp_image_set_version_string_type,
              PLDM_STR_TYPE_ASCII);
    EXPECT_EQ(deviceIdRecHeader.comp_image_set_version_string_length,
              imageSetVersionStr.size());
    EXPECT_EQ(deviceIdRecHeader.fw_device_pkg_data_length, fwDevicePkgDataLen);

    EXPECT_EQ(applicableComponents.length, applicableComponentsBitfield.size());
    EXPECT_EQ(true,
              std::equal(applicableComponents.ptr,
                         applicableComponents.ptr + applicableComponents.length,
                         applicableComponentsBitfield.begin(),
                         applicableComponentsBitfield.end()));

    EXPECT_EQ(outCompImageSetVersionStr.length, imageSetVersionStr.size());
    std::string compImageSetVersionStr(
        reinterpret_cast<const char*>(outCompImageSetVersionStr.ptr),
        outCompImageSetVersionStr.length);
    EXPECT_EQ(compImageSetVersionStr, imageSetVersionStr);

    uint16_t descriptorType = 0;
    uint16_t descriptorLen = 0;
    variable_field descriptorData{};
    // DescriptorCount is 1, so decode_descriptor_type_length_value called once
    rc = decode_descriptor_type_length_value(recordDescriptors.ptr,
                                             recordDescriptors.length,
                                             &descriptorType, &descriptorData);
    EXPECT_EQ(rc, PLDM_SUCCESS);
    EXPECT_EQ(recordDescriptors.length, sizeof(descriptorType) +
                                            sizeof(descriptorLen) +
                                            descriptorData.length);
    EXPECT_EQ(descriptorType, PLDM_FWUP_UUID);
    EXPECT_EQ(descriptorData.length, PLDM_FWUP_UUID_LENGTH);
    EXPECT_EQ(true, std::equal(descriptorData.ptr,
                               descriptorData.ptr + descriptorData.length,
                               uuid.begin(), uuid.end()));

    EXPECT_EQ(outFwDevicePkgData.length, fwDevicePkgData.size());
    EXPECT_EQ(true,
              std::equal(outFwDevicePkgData.ptr,
                         outFwDevicePkgData.ptr + outFwDevicePkgData.length,
                         fwDevicePkgData.begin(), fwDevicePkgData.end()));
}

TEST(DecodeFirmwareDeviceIdRecord, goodPathNofwDevicePkgData)
{
    constexpr uint8_t descriptorCount = 1;
    // Continue component updates after failure
    constexpr std::bitset<32> deviceUpdateFlag{1};
    constexpr uint16_t componentBitmapBitLength = 8;
    // Applicable Components - 1,2
    std::vector<std::bitset<8>> applicableComponentsBitfield{0x03};
    // ComponentImageSetVersionString
    constexpr std::string_view imageSetVersionStr{"VersionString1"};
    // Initial descriptor - UUID
    constexpr std::array<uint8_t, PLDM_FWUP_UUID_LENGTH> uuid{
        0x12, 0x44, 0xd2, 0x64, 0x8d, 0x7d, 0x47, 0x18,
        0xa0, 0x30, 0xfc, 0x8a, 0x56, 0x58, 0x7d, 0x5b};
    constexpr uint16_t fwDevicePkgDataLen = 0;

    // Size of the firmware device ID record
    constexpr uint16_t recordLen =
        sizeof(pldm_firmware_device_id_record) +
        (componentBitmapBitLength / PLDM_FWUP_COMPONENT_BITMAP_MULTIPLE) +
        imageSetVersionStr.size() +
        sizeof(pldm_descriptor_tlv().descriptor_type) +
        sizeof(pldm_descriptor_tlv().descriptor_length) + uuid.size() +
        fwDevicePkgDataLen;
    // Firmware device ID record
    constexpr std::array<uint8_t, recordLen> record{
        0x2e, 0x00, 0x01, 0x01, 0x00, 0x00, 0x00, 0x01, 0x0e, 0x00, 0x00, 0x03,
        0x56, 0x65, 0x72, 0x73, 0x69, 0x6f, 0x6e, 0x53, 0x74, 0x72, 0x69, 0x6e,
        0x67, 0x31, 0x02, 0x00, 0x10, 0x00, 0x12, 0x44, 0xd2, 0x64, 0x8d, 0x7d,
        0x47, 0x18, 0xa0, 0x30, 0xfc, 0x8a, 0x56, 0x58, 0x7d, 0x5b};

    pldm_firmware_device_id_record deviceIdRecHeader{};
    variable_field applicableComponents{};
    variable_field outCompImageSetVersionStr{};
    variable_field recordDescriptors{};
    variable_field outFwDevicePkgData{};

    auto rc = decode_firmware_device_id_record(
        record.data(), record.size(), componentBitmapBitLength,
        &deviceIdRecHeader, &applicableComponents, &outCompImageSetVersionStr,
        &recordDescriptors, &outFwDevicePkgData);

    EXPECT_EQ(rc, PLDM_SUCCESS);
    EXPECT_EQ(deviceIdRecHeader.record_length, recordLen);
    EXPECT_EQ(deviceIdRecHeader.descriptor_count, descriptorCount);
    EXPECT_EQ(deviceIdRecHeader.device_update_option_flags.value,
              deviceUpdateFlag);
    EXPECT_EQ(deviceIdRecHeader.comp_image_set_version_string_type,
              PLDM_STR_TYPE_ASCII);
    EXPECT_EQ(deviceIdRecHeader.comp_image_set_version_string_length,
              imageSetVersionStr.size());
    EXPECT_EQ(deviceIdRecHeader.fw_device_pkg_data_length, 0);

    EXPECT_EQ(applicableComponents.length, applicableComponentsBitfield.size());
    EXPECT_EQ(true,
              std::equal(applicableComponents.ptr,
                         applicableComponents.ptr + applicableComponents.length,
                         applicableComponentsBitfield.begin(),
                         applicableComponentsBitfield.end()));

    EXPECT_EQ(outCompImageSetVersionStr.length, imageSetVersionStr.size());
    std::string compImageSetVersionStr(
        reinterpret_cast<const char*>(outCompImageSetVersionStr.ptr),
        outCompImageSetVersionStr.length);
    EXPECT_EQ(compImageSetVersionStr, imageSetVersionStr);

    uint16_t descriptorType = 0;
    uint16_t descriptorLen = 0;
    variable_field descriptorData{};
    // DescriptorCount is 1, so decode_descriptor_type_length_value called once
    rc = decode_descriptor_type_length_value(recordDescriptors.ptr,
                                             recordDescriptors.length,
                                             &descriptorType, &descriptorData);
    EXPECT_EQ(rc, PLDM_SUCCESS);
    EXPECT_EQ(recordDescriptors.length, sizeof(descriptorType) +
                                            sizeof(descriptorLen) +
                                            descriptorData.length);
    EXPECT_EQ(descriptorType, PLDM_FWUP_UUID);
    EXPECT_EQ(descriptorData.length, PLDM_FWUP_UUID_LENGTH);
    EXPECT_EQ(true, std::equal(descriptorData.ptr,
                               descriptorData.ptr + descriptorData.length,
                               uuid.begin(), uuid.end()));

    EXPECT_EQ(outFwDevicePkgData.ptr, nullptr);
    EXPECT_EQ(outFwDevicePkgData.length, 0);
}

TEST(DecodeFirmwareDeviceIdRecord, ErrorPaths)
{
    constexpr uint16_t componentBitmapBitLength = 8;
    // Invalid ComponentImageSetVersionStringType
    constexpr std::array<uint8_t, 11> invalidRecord1{
        0x0b, 0x00, 0x01, 0x01, 0x00, 0x00, 0x00, 0x06, 0x0e, 0x00, 0x00};

    int rc = 0;
    pldm_firmware_device_id_record deviceIdRecHeader{};
    variable_field applicableComponents{};
    variable_field outCompImageSetVersionStr{};
    variable_field recordDescriptors{};
    variable_field outFwDevicePkgData{};

    rc = decode_firmware_device_id_record(
        nullptr, invalidRecord1.size(), componentBitmapBitLength,
        &deviceIdRecHeader, &applicableComponents, &outCompImageSetVersionStr,
        &recordDescriptors, &outFwDevicePkgData);
    EXPECT_EQ(rc, PLDM_ERROR_INVALID_DATA);

    rc = decode_firmware_device_id_record(
        invalidRecord1.data(), invalidRecord1.size(), componentBitmapBitLength,
        nullptr, &applicableComponents, &outCompImageSetVersionStr,
        &recordDescriptors, &outFwDevicePkgData);
    EXPECT_EQ(rc, PLDM_ERROR_INVALID_DATA);

    rc = decode_firmware_device_id_record(
        invalidRecord1.data(), invalidRecord1.size(), componentBitmapBitLength,
        &deviceIdRecHeader, nullptr, &outCompImageSetVersionStr,
        &recordDescriptors, &outFwDevicePkgData);
    EXPECT_EQ(rc, PLDM_ERROR_INVALID_DATA);

    rc = decode_firmware_device_id_record(
        invalidRecord1.data(), invalidRecord1.size(), componentBitmapBitLength,
        &deviceIdRecHeader, &applicableComponents, nullptr, &recordDescriptors,
        &outFwDevicePkgData);
    EXPECT_EQ(rc, PLDM_ERROR_INVALID_DATA);

    rc = decode_firmware_device_id_record(
        invalidRecord1.data(), invalidRecord1.size(), componentBitmapBitLength,
        &deviceIdRecHeader, &applicableComponents, &outCompImageSetVersionStr,
        nullptr, &outFwDevicePkgData);
    EXPECT_EQ(rc, PLDM_ERROR_INVALID_DATA);

    rc = decode_firmware_device_id_record(
        invalidRecord1.data(), invalidRecord1.size(), componentBitmapBitLength,
        &deviceIdRecHeader, &applicableComponents, &outCompImageSetVersionStr,
        &recordDescriptors, nullptr);
    EXPECT_EQ(rc, PLDM_ERROR_INVALID_DATA);

    rc = decode_firmware_device_id_record(
        invalidRecord1.data(), invalidRecord1.size() - 1,
        componentBitmapBitLength, &deviceIdRecHeader, &applicableComponents,
        &outCompImageSetVersionStr, &recordDescriptors, &outFwDevicePkgData);
    EXPECT_EQ(rc, PLDM_ERROR_INVALID_LENGTH);

    rc = decode_firmware_device_id_record(
        invalidRecord1.data(), invalidRecord1.size(),
        componentBitmapBitLength + 1, &deviceIdRecHeader, &applicableComponents,
        &outCompImageSetVersionStr, &recordDescriptors, &outFwDevicePkgData);
    EXPECT_EQ(rc, PLDM_ERROR_INVALID_DATA);

    rc = decode_firmware_device_id_record(
        invalidRecord1.data(), invalidRecord1.size(), componentBitmapBitLength,
        &deviceIdRecHeader, &applicableComponents, &outCompImageSetVersionStr,
        &recordDescriptors, &outFwDevicePkgData);
    EXPECT_EQ(rc, PLDM_ERROR_INVALID_DATA);

    // Invalid ComponentImageSetVersionStringLength
    constexpr std::array<uint8_t, 11> invalidRecord2{
        0x0b, 0x00, 0x01, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00};
    rc = decode_firmware_device_id_record(
        invalidRecord2.data(), invalidRecord2.size(), componentBitmapBitLength,
        &deviceIdRecHeader, &applicableComponents, &outCompImageSetVersionStr,
        &recordDescriptors, &outFwDevicePkgData);
    EXPECT_EQ(rc, PLDM_ERROR_INVALID_DATA);

    // invalidRecord3 size is less than RecordLength
    constexpr std::array<uint8_t, 11> invalidRecord3{
        0x2e, 0x00, 0x01, 0x01, 0x00, 0x00, 0x00, 0x01, 0x0e, 0x00, 0x00};
    rc = decode_firmware_device_id_record(
        invalidRecord3.data(), invalidRecord3.size(), componentBitmapBitLength,
        &deviceIdRecHeader, &applicableComponents, &outCompImageSetVersionStr,
        &recordDescriptors, &outFwDevicePkgData);
    EXPECT_EQ(rc, PLDM_ERROR_INVALID_LENGTH);

    // RecordLength is less than the calculated RecordLength
    constexpr std::array<uint8_t, 11> invalidRecord4{
        0x15, 0x00, 0x01, 0x01, 0x00, 0x00, 0x00, 0x01, 0x0e, 0x02, 0x00};
    rc = decode_firmware_device_id_record(
        invalidRecord4.data(), invalidRecord4.size(), componentBitmapBitLength,
        &deviceIdRecHeader, &applicableComponents, &outCompImageSetVersionStr,
        &recordDescriptors, &outFwDevicePkgData);
    EXPECT_EQ(rc, PLDM_ERROR_INVALID_LENGTH);
}

TEST(DecodeDescriptors, goodPath3Descriptors)
{
    // In the descriptor data there are 3 descriptor entries
    // 1) IANA enterprise ID
    constexpr std::array<uint8_t, PLDM_FWUP_IANA_ENTERPRISE_ID_LENGTH> iana{
        0x0a, 0x0b, 0x0c, 0xd};
    // 2) UUID
    constexpr std::array<uint8_t, PLDM_FWUP_UUID_LENGTH> uuid{
        0x12, 0x44, 0xd2, 0x64, 0x8d, 0x7d, 0x47, 0x18,
        0xa0, 0x30, 0xfc, 0x8a, 0x56, 0x58, 0x7d, 0x5b};
    // 3) Vendor Defined
    constexpr std::string_view vendorTitle{"OpenBMC"};
    constexpr size_t vendorDescriptorLen = 2;
    constexpr std::array<uint8_t, vendorDescriptorLen> vendorDescriptorData{
        0x01, 0x02};

    constexpr size_t vendorDefinedDescriptorLen =
        sizeof(pldm_vendor_defined_descriptor_title_data()
                   .vendor_defined_descriptor_title_str_type) +
        sizeof(pldm_vendor_defined_descriptor_title_data()
                   .vendor_defined_descriptor_title_str_len) +
        vendorTitle.size() + vendorDescriptorData.size();

    constexpr size_t descriptorsLength =
        3 * (sizeof(pldm_descriptor_tlv().descriptor_type) +
             sizeof(pldm_descriptor_tlv().descriptor_length)) +
        iana.size() + uuid.size() + vendorDefinedDescriptorLen;

    constexpr std::array<uint8_t, descriptorsLength> descriptors{
        0x01, 0x00, 0x04, 0x00, 0x0a, 0x0b, 0x0c, 0x0d, 0x02, 0x00, 0x10,
        0x00, 0x12, 0x44, 0xd2, 0x64, 0x8d, 0x7d, 0x47, 0x18, 0xa0, 0x30,
        0xfc, 0x8a, 0x56, 0x58, 0x7d, 0x5b, 0xFF, 0xFF, 0x0B, 0x00, 0x01,
        0x07, 0x4f, 0x70, 0x65, 0x6e, 0x42, 0x4d, 0x43, 0x01, 0x02};

    size_t descriptorCount = 1;
    size_t descriptorsRemainingLength = descriptorsLength;
    int rc = 0;

    while (descriptorsRemainingLength && (descriptorCount <= 3))
    {
        uint16_t descriptorType = 0;
        uint16_t descriptorLen = 0;
        variable_field descriptorData{};

        rc = decode_descriptor_type_length_value(
            descriptors.data() + descriptorsLength - descriptorsRemainingLength,
            descriptorsRemainingLength, &descriptorType, &descriptorData);
        EXPECT_EQ(rc, PLDM_SUCCESS);

        if (descriptorCount == 1)
        {
            EXPECT_EQ(descriptorType, PLDM_FWUP_IANA_ENTERPRISE_ID);
            EXPECT_EQ(descriptorData.length,
                      PLDM_FWUP_IANA_ENTERPRISE_ID_LENGTH);
            EXPECT_EQ(true,
                      std::equal(descriptorData.ptr,
                                 descriptorData.ptr + descriptorData.length,
                                 iana.begin(), iana.end()));
        }
        else if (descriptorCount == 2)
        {
            EXPECT_EQ(descriptorType, PLDM_FWUP_UUID);
            EXPECT_EQ(descriptorData.length, PLDM_FWUP_UUID_LENGTH);
            EXPECT_EQ(true,
                      std::equal(descriptorData.ptr,
                                 descriptorData.ptr + descriptorData.length,
                                 uuid.begin(), uuid.end()));
        }
        else if (descriptorCount == 3)
        {
            EXPECT_EQ(descriptorType, PLDM_FWUP_VENDOR_DEFINED);
            EXPECT_EQ(descriptorData.length, vendorDefinedDescriptorLen);

            uint8_t descriptorTitleStrType = 0;
            variable_field descriptorTitleStr{};
            variable_field vendorDefinedDescriptorData{};

            rc = decode_vendor_defined_descriptor_value(
                descriptorData.ptr, descriptorData.length,
                &descriptorTitleStrType, &descriptorTitleStr,
                &vendorDefinedDescriptorData);
            EXPECT_EQ(rc, PLDM_SUCCESS);

            EXPECT_EQ(descriptorTitleStrType, PLDM_STR_TYPE_ASCII);
            EXPECT_EQ(descriptorTitleStr.length, vendorTitle.size());
            std::string vendorTitleStr(
                reinterpret_cast<const char*>(descriptorTitleStr.ptr),
                descriptorTitleStr.length);
            EXPECT_EQ(vendorTitleStr, vendorTitle);

            EXPECT_EQ(vendorDefinedDescriptorData.length,
                      vendorDescriptorData.size());
            EXPECT_EQ(true, std::equal(vendorDefinedDescriptorData.ptr,
                                       vendorDefinedDescriptorData.ptr +
                                           vendorDefinedDescriptorData.length,
                                       vendorDescriptorData.begin(),
                                       vendorDescriptorData.end()));
        }

        descriptorsRemainingLength -= sizeof(descriptorType) +
                                      sizeof(descriptorLen) +
                                      descriptorData.length;
        descriptorCount++;
    }
}

TEST(DecodeDescriptors, errorPathDecodeDescriptorTLV)
{
    int rc = 0;
    // IANA Enterprise ID descriptor length incorrect
    constexpr std::array<uint8_t, 7> invalidIANADescriptor1{
        0x01, 0x00, 0x03, 0x00, 0x0a, 0x0b, 0x0c};
    uint16_t descriptorType = 0;
    variable_field descriptorData{};

    rc = decode_descriptor_type_length_value(nullptr,
                                             invalidIANADescriptor1.size(),
                                             &descriptorType, &descriptorData);
    EXPECT_EQ(rc, PLDM_ERROR_INVALID_DATA);

    rc = decode_descriptor_type_length_value(invalidIANADescriptor1.data(),
                                             invalidIANADescriptor1.size(),
                                             nullptr, &descriptorData);
    EXPECT_EQ(rc, PLDM_ERROR_INVALID_DATA);

    rc = decode_descriptor_type_length_value(invalidIANADescriptor1.data(),
                                             invalidIANADescriptor1.size(),
                                             &descriptorType, nullptr);
    EXPECT_EQ(rc, PLDM_ERROR_INVALID_DATA);

    rc = decode_descriptor_type_length_value(
        invalidIANADescriptor1.data(), PLDM_FWUP_DEVICE_DESCRIPTOR_MIN_LEN - 1,
        &descriptorType, &descriptorData);
    EXPECT_EQ(rc, PLDM_ERROR_INVALID_LENGTH);

    rc = decode_descriptor_type_length_value(invalidIANADescriptor1.data(),
                                             invalidIANADescriptor1.size(),
                                             &descriptorType, &descriptorData);
    EXPECT_EQ(rc, PLDM_ERROR_INVALID_LENGTH);

    // IANA Enterprise ID descriptor data less than length
    std::array<uint8_t, 7> invalidIANADescriptor2{0x01, 0x00, 0x04, 0x00,
                                                  0x0a, 0x0b, 0x0c};
    rc = decode_descriptor_type_length_value(invalidIANADescriptor2.data(),
                                             invalidIANADescriptor2.size(),
                                             &descriptorType, &descriptorData);
    EXPECT_EQ(rc, PLDM_ERROR_INVALID_LENGTH);
}

TEST(DecodeDescriptors, errorPathVendorDefinedDescriptor)
{
    int rc = 0;
    // VendorDefinedDescriptorTitleStringType is invalid
    constexpr std::array<uint8_t, 9> invalidVendorDescriptor1{
        0x06, 0x07, 0x4f, 0x70, 0x65, 0x6e, 0x42, 0x4d, 0x43};
    uint8_t descriptorStringType = 0;
    variable_field descriptorTitleStr{};
    variable_field vendorDefinedDescriptorData{};

    rc = decode_vendor_defined_descriptor_value(
        nullptr, invalidVendorDescriptor1.size(), &descriptorStringType,
        &descriptorTitleStr, &vendorDefinedDescriptorData);
    EXPECT_EQ(rc, PLDM_ERROR_INVALID_DATA);

    rc = decode_vendor_defined_descriptor_value(
        invalidVendorDescriptor1.data(), invalidVendorDescriptor1.size(),
        &descriptorStringType, &descriptorTitleStr,
        &vendorDefinedDescriptorData);
    EXPECT_EQ(rc, PLDM_ERROR_INVALID_DATA);

    rc = decode_vendor_defined_descriptor_value(
        invalidVendorDescriptor1.data(), invalidVendorDescriptor1.size(),
        nullptr, &descriptorTitleStr, &vendorDefinedDescriptorData);
    EXPECT_EQ(rc, PLDM_ERROR_INVALID_DATA);

    rc = decode_vendor_defined_descriptor_value(
        invalidVendorDescriptor1.data(), invalidVendorDescriptor1.size(),
        &descriptorStringType, nullptr, &vendorDefinedDescriptorData);
    EXPECT_EQ(rc, PLDM_ERROR_INVALID_DATA);

    rc = decode_vendor_defined_descriptor_value(
        invalidVendorDescriptor1.data(), invalidVendorDescriptor1.size(),
        &descriptorStringType, &descriptorTitleStr, nullptr);
    EXPECT_EQ(rc, PLDM_ERROR_INVALID_DATA);

    rc = decode_vendor_defined_descriptor_value(
        invalidVendorDescriptor1.data(),
        sizeof(pldm_vendor_defined_descriptor_title_data) - 1,
        &descriptorStringType, &descriptorTitleStr,
        &vendorDefinedDescriptorData);
    EXPECT_EQ(rc, PLDM_ERROR_INVALID_LENGTH);

    rc = decode_vendor_defined_descriptor_value(
        invalidVendorDescriptor1.data(), invalidVendorDescriptor1.size(),
        &descriptorStringType, &descriptorTitleStr,
        &vendorDefinedDescriptorData);
    EXPECT_EQ(rc, PLDM_ERROR_INVALID_DATA);

    // VendorDefinedDescriptorTitleStringLength is 0
    std::array<uint8_t, 9> invalidVendorDescriptor2{
        0x01, 0x00, 0x4f, 0x70, 0x65, 0x6e, 0x42, 0x4d, 0x43};
    rc = decode_vendor_defined_descriptor_value(
        invalidVendorDescriptor2.data(), invalidVendorDescriptor2.size(),
        &descriptorStringType, &descriptorTitleStr,
        &vendorDefinedDescriptorData);
    EXPECT_EQ(rc, PLDM_ERROR_INVALID_DATA);

    // VendorDefinedDescriptorData not present in the data
    std::array<uint8_t, 9> invalidVendorDescriptor3{
        0x01, 0x07, 0x4f, 0x70, 0x65, 0x6e, 0x42, 0x4d, 0x43};
    rc = decode_vendor_defined_descriptor_value(
        invalidVendorDescriptor3.data(), invalidVendorDescriptor3.size(),
        &descriptorStringType, &descriptorTitleStr,
        &vendorDefinedDescriptorData);
    EXPECT_EQ(rc, PLDM_ERROR_INVALID_LENGTH);
}

TEST(DecodeComponentImageInfo, goodPath)
{
    // Firmware
    constexpr uint16_t compClassification = 16;
    constexpr uint16_t compIdentifier = 300;
    constexpr uint32_t compComparisonStamp = 0xFFFFFFFF;
    // Force update
    constexpr std::bitset<16> compOptions{1};
    // System reboot[Bit position 3] & Medium-specific reset[Bit position 2]
    constexpr std::bitset<16> reqCompActivationMethod{0x0c};
    // Random ComponentLocationOffset
    constexpr uint32_t compLocOffset = 357;
    // Random ComponentSize
    constexpr uint32_t compSize = 27;
    // ComponentVersionString
    constexpr std::string_view compVersionStr{"VersionString1"};
    constexpr size_t compImageInfoSize =
        sizeof(pldm_component_image_information) + compVersionStr.size();

    constexpr std::array<uint8_t, compImageInfoSize> compImageInfo{
        0x10, 0x00, 0x2c, 0x01, 0xff, 0xff, 0xff, 0xff, 0x01, 0x00, 0x0c, 0x00,
        0x65, 0x01, 0x00, 0x00, 0x1b, 0x00, 0x00, 0x00, 0x01, 0x0e, 0x56, 0x65,
        0x72, 0x73, 0x69, 0x6f, 0x6e, 0x53, 0x74, 0x72, 0x69, 0x6e, 0x67, 0x31};
    pldm_component_image_information outCompImageInfo{};
    variable_field outCompVersionStr{};

    auto rc =
        decode_pldm_comp_image_info(compImageInfo.data(), compImageInfo.size(),
                                    &outCompImageInfo, &outCompVersionStr);

    EXPECT_EQ(rc, PLDM_SUCCESS);
    EXPECT_EQ(outCompImageInfo.comp_classification, compClassification);
    EXPECT_EQ(outCompImageInfo.comp_identifier, compIdentifier);
    EXPECT_EQ(outCompImageInfo.comp_comparison_stamp, compComparisonStamp);
    EXPECT_EQ(outCompImageInfo.comp_options.value, compOptions);
    EXPECT_EQ(outCompImageInfo.requested_comp_activation_method.value,
              reqCompActivationMethod);
    EXPECT_EQ(outCompImageInfo.comp_location_offset, compLocOffset);
    EXPECT_EQ(outCompImageInfo.comp_size, compSize);
    EXPECT_EQ(outCompImageInfo.comp_version_string_type, PLDM_STR_TYPE_ASCII);
    EXPECT_EQ(outCompImageInfo.comp_version_string_length,
              compVersionStr.size());

    EXPECT_EQ(outCompVersionStr.length,
              outCompImageInfo.comp_version_string_length);
    std::string componentVersionString(
        reinterpret_cast<const char*>(outCompVersionStr.ptr),
        outCompVersionStr.length);
    EXPECT_EQ(componentVersionString, compVersionStr);
}

TEST(DecodeComponentImageInfo, errorPaths)
{
    int rc = 0;
    // ComponentVersionString
    constexpr std::string_view compVersionStr{"VersionString1"};
    constexpr size_t compImageInfoSize =
        sizeof(pldm_component_image_information) + compVersionStr.size();
    // Invalid ComponentVersionStringType - 0x06
    constexpr std::array<uint8_t, compImageInfoSize> invalidCompImageInfo1{
        0x10, 0x00, 0x2c, 0x01, 0xff, 0xff, 0xff, 0xff, 0x01, 0x00, 0x0c, 0x00,
        0x65, 0x01, 0x00, 0x00, 0x1b, 0x00, 0x00, 0x00, 0x06, 0x0e, 0x56, 0x65,
        0x72, 0x73, 0x69, 0x6f, 0x6e, 0x53, 0x74, 0x72, 0x69, 0x6e, 0x67, 0x31};
    pldm_component_image_information outCompImageInfo{};
    variable_field outCompVersionStr{};

    rc = decode_pldm_comp_image_info(nullptr, invalidCompImageInfo1.size(),
                                     &outCompImageInfo, &outCompVersionStr);
    EXPECT_EQ(rc, PLDM_ERROR_INVALID_DATA);

    rc = decode_pldm_comp_image_info(invalidCompImageInfo1.data(),
                                     invalidCompImageInfo1.size(), nullptr,
                                     &outCompVersionStr);
    EXPECT_EQ(rc, PLDM_ERROR_INVALID_DATA);

    rc = decode_pldm_comp_image_info(invalidCompImageInfo1.data(),
                                     invalidCompImageInfo1.size(),
                                     &outCompImageInfo, nullptr);
    EXPECT_EQ(rc, PLDM_ERROR_INVALID_DATA);

    rc = decode_pldm_comp_image_info(invalidCompImageInfo1.data(),
                                     sizeof(pldm_component_image_information) -
                                         1,
                                     &outCompImageInfo, &outCompVersionStr);
    EXPECT_EQ(rc, PLDM_ERROR_INVALID_LENGTH);

    rc = decode_pldm_comp_image_info(invalidCompImageInfo1.data(),
                                     invalidCompImageInfo1.size(),
                                     &outCompImageInfo, &outCompVersionStr);
    EXPECT_EQ(rc, PLDM_ERROR_INVALID_DATA);

    // Invalid ComponentVersionStringLength - 0x00
    constexpr std::array<uint8_t, compImageInfoSize> invalidCompImageInfo2{
        0x10, 0x00, 0x2c, 0x01, 0xff, 0xff, 0xff, 0xff, 0x01, 0x00, 0x0c, 0x00,
        0x65, 0x01, 0x00, 0x00, 0x1b, 0x00, 0x00, 0x00, 0x01, 0x00, 0x56, 0x65,
        0x72, 0x73, 0x69, 0x6f, 0x6e, 0x53, 0x74, 0x72, 0x69, 0x6e, 0x67, 0x31};
    rc = decode_pldm_comp_image_info(invalidCompImageInfo2.data(),
                                     invalidCompImageInfo2.size(),
                                     &outCompImageInfo, &outCompVersionStr);
    EXPECT_EQ(rc, PLDM_ERROR_INVALID_DATA);

    // Use Component Comparison Stamp is not set, but ComponentComparisonStamp
    // is not 0xFFFFFFFF
    constexpr std::array<uint8_t, compImageInfoSize> invalidCompImageInfo3{
        0x10, 0x00, 0x2c, 0x01, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x0c, 0x00,
        0x65, 0x01, 0x00, 0x00, 0x1b, 0x00, 0x00, 0x00, 0x01, 0x0e, 0x56, 0x65,
        0x72, 0x73, 0x69, 0x6f, 0x6e, 0x53, 0x74, 0x72, 0x69, 0x6e, 0x67, 0x31};

    rc = decode_pldm_comp_image_info(invalidCompImageInfo3.data(),
                                     invalidCompImageInfo3.size() - 1,
                                     &outCompImageInfo, &outCompVersionStr);
    EXPECT_EQ(rc, PLDM_ERROR_INVALID_LENGTH);

    rc = decode_pldm_comp_image_info(invalidCompImageInfo3.data(),
                                     invalidCompImageInfo3.size(),
                                     &outCompImageInfo, &outCompVersionStr);
    EXPECT_EQ(rc, PLDM_ERROR_INVALID_DATA);

    // Invalid ComponentLocationOffset - 0
    constexpr std::array<uint8_t, compImageInfoSize> invalidCompImageInfo4{
        0x10, 0x00, 0x2c, 0x01, 0xff, 0xff, 0xff, 0xff, 0x01, 0x00, 0x0c, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x1b, 0x00, 0x00, 0x00, 0x01, 0x0e, 0x56, 0x65,
        0x72, 0x73, 0x69, 0x6f, 0x6e, 0x53, 0x74, 0x72, 0x69, 0x6e, 0x67, 0x31};
    rc = decode_pldm_comp_image_info(invalidCompImageInfo4.data(),
                                     invalidCompImageInfo4.size(),
                                     &outCompImageInfo, &outCompVersionStr);
    EXPECT_EQ(rc, PLDM_ERROR_INVALID_DATA);

    // Invalid ComponentSize - 0
    constexpr std::array<uint8_t, compImageInfoSize> invalidCompImageInfo5{
        0x10, 0x00, 0x2c, 0x01, 0xff, 0xff, 0xff, 0xff, 0x01, 0x00, 0x0c, 0x00,
        0x65, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x0e, 0x56, 0x65,
        0x72, 0x73, 0x69, 0x6f, 0x6e, 0x53, 0x74, 0x72, 0x69, 0x6e, 0x67, 0x31};
    rc = decode_pldm_comp_image_info(invalidCompImageInfo5.data(),
                                     invalidCompImageInfo5.size(),
                                     &outCompImageInfo, &outCompVersionStr);
    EXPECT_EQ(rc, PLDM_ERROR_INVALID_DATA);
}

TEST(QueryDeviceIdentifiers, goodPathEncodeRequest)
{
    std::array<uint8_t, sizeof(pldm_msg_hdr)> requestMsg{};
    auto requestPtr = reinterpret_cast<pldm_msg*>(requestMsg.data());

    uint8_t instanceId = 0x01;

    auto rc = encode_query_device_identifiers_req(
        instanceId, PLDM_QUERY_DEVICE_IDENTIFIERS_REQ_BYTES, requestPtr);
    EXPECT_EQ(rc, PLDM_SUCCESS);
    EXPECT_EQ(requestPtr->hdr.request, PLDM_REQUEST);
    EXPECT_EQ(requestPtr->hdr.instance_id, instanceId);
    EXPECT_EQ(requestPtr->hdr.type, PLDM_FWUP);
    EXPECT_EQ(requestPtr->hdr.command, PLDM_QUERY_DEVICE_IDENTIFIERS);
}

TEST(QueryDeviceIdentifiers, goodPathDecodeResponse)
{
    // descriptorDataLen is not fixed here taking it as 6
    constexpr uint8_t descriptorDataLen = 6;
    std::array<uint8_t, hdrSize +
                            sizeof(struct pldm_query_device_identifiers_resp) +
                            descriptorDataLen>
        responseMsg{};
    auto inResp = reinterpret_cast<struct pldm_query_device_identifiers_resp*>(
        responseMsg.data() + hdrSize);

    inResp->completion_code = PLDM_SUCCESS;
    inResp->device_identifiers_len = htole32(descriptorDataLen);
    inResp->descriptor_count = 1;

    // filling descriptor data
    std::fill_n(responseMsg.data() + hdrSize +
                    sizeof(struct pldm_query_device_identifiers_resp),
                descriptorDataLen, 0xFF);

    auto response = reinterpret_cast<pldm_msg*>(responseMsg.data());
    uint8_t completionCode = PLDM_SUCCESS;
    uint32_t deviceIdentifiersLen = 0;
    uint8_t descriptorCount = 0;
    uint8_t* outDescriptorData = nullptr;

    auto rc = decode_query_device_identifiers_resp(
        response, responseMsg.size() - hdrSize, &completionCode,
        &deviceIdentifiersLen, &descriptorCount, &outDescriptorData);

    EXPECT_EQ(rc, PLDM_SUCCESS);
    EXPECT_EQ(completionCode, PLDM_SUCCESS);
    EXPECT_EQ(deviceIdentifiersLen, inResp->device_identifiers_len);
    EXPECT_EQ(descriptorCount, inResp->descriptor_count);
    EXPECT_EQ(true,
              std::equal(outDescriptorData,
                         outDescriptorData + deviceIdentifiersLen,
                         responseMsg.begin() + hdrSize +
                             sizeof(struct pldm_query_device_identifiers_resp),
                         responseMsg.end()));
}

TEST(GetFirmwareParameters, goodPathEncodeRequest)
{
    std::array<uint8_t, sizeof(pldm_msg_hdr)> requestMsg{};
    auto requestPtr = reinterpret_cast<pldm_msg*>(requestMsg.data());
    uint8_t instanceId = 0x01;

    auto rc = encode_get_firmware_parameters_req(
        instanceId, PLDM_GET_FIRMWARE_PARAMETERS_REQ_BYTES, requestPtr);
    EXPECT_EQ(rc, PLDM_SUCCESS);
    EXPECT_EQ(requestPtr->hdr.request, PLDM_REQUEST);
    EXPECT_EQ(requestPtr->hdr.instance_id, instanceId);
    EXPECT_EQ(requestPtr->hdr.type, PLDM_FWUP);
    EXPECT_EQ(requestPtr->hdr.command, PLDM_GET_FIRMWARE_PARAMETERS);
}

TEST(GetFirmwareParameters, decodeResponse)
{
    // CapabilitiesDuringUpdate of the firmware device
    // Firmware device downgrade restrictions [Bit position 8] &
    // Firmware Device Partial Updates [Bit position 3]
    constexpr std::bitset<32> fdCapabilities{0x00000104};
    constexpr uint16_t compCount = 1;
    constexpr std::string_view activeCompImageSetVersion{"VersionString1"};
    constexpr std::string_view pendingCompImageSetVersion{"VersionString2"};

    // constexpr uint16_t compClassification = 16;
    // constexpr uint16_t compIdentifier = 300;
    // constexpr uint8_t compClassificationIndex = 20;
    // constexpr uint32_t activeCompComparisonStamp = 0xABCDEFAB;
    // constexpr std::array<uint8_t, 8> activeComponentReleaseData = {
    //     0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08};
    // constexpr uint32_t pendingCompComparisonStamp = 0x12345678;
    // constexpr std::array<uint8_t, 8> pendingComponentReleaseData = {
    //     0x08, 0x07, 0x06, 0x05, 0x04, 0x03, 0x02, 0x01};
    constexpr std::string_view activeCompVersion{"VersionString3"};
    constexpr std::string_view pendingCompVersion{"VersionString4"};

    constexpr size_t compParamTableSize =
        sizeof(pldm_component_parameter_entry) + activeCompVersion.size() +
        pendingCompVersion.size();

    constexpr std::array<uint8_t, compParamTableSize> compParamTable{
        0x10, 0x00, 0x2c, 0x01, 0x14, 0xAB, 0xEF, 0xCD, 0xAB, 0x01, 0x0e, 0x01,
        0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x78, 0x56, 0x34, 0x12, 0x01,
        0x0e, 0x08, 0x07, 0x06, 0x05, 0x04, 0x03, 0x02, 0x01, 0x12, 0x00, 0x02,
        0x00, 0x00, 0x00, 0x56, 0x65, 0x72, 0x73, 0x69, 0x6f, 0x6e, 0x53, 0x74,
        0x72, 0x69, 0x6e, 0x67, 0x33, 0x56, 0x65, 0x72, 0x73, 0x69, 0x6f, 0x6e,
        0x53, 0x74, 0x72, 0x69, 0x6e, 0x67, 0x34};

    constexpr size_t getFwParamsPayloadLen =
        sizeof(pldm_get_firmware_parameters_resp) +
        activeCompImageSetVersion.size() + pendingCompImageSetVersion.size() +
        compParamTableSize;

    constexpr std::array<uint8_t, hdrSize + getFwParamsPayloadLen>
        getFwParamsResponse{
            0x00, 0x00, 0x00, 0x00, 0x04, 0x01, 0x00, 0x00, 0x01, 0x00, 0x01,
            0x0e, 0x01, 0x0e, 0x56, 0x65, 0x72, 0x73, 0x69, 0x6f, 0x6e, 0x53,
            0x74, 0x72, 0x69, 0x6e, 0x67, 0x31, 0x56, 0x65, 0x72, 0x73, 0x69,
            0x6f, 0x6e, 0x53, 0x74, 0x72, 0x69, 0x6e, 0x67, 0x32, 0x10, 0x00,
            0x2c, 0x01, 0x14, 0xAB, 0xEF, 0xCD, 0xAB, 0x01, 0x0e, 0x01, 0x02,
            0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x78, 0x56, 0x34, 0x12, 0x01,
            0x0e, 0x08, 0x07, 0x06, 0x05, 0x04, 0x03, 0x02, 0x01, 0x12, 0x00,
            0x02, 0x00, 0x00, 0x00, 0x56, 0x65, 0x72, 0x73, 0x69, 0x6f, 0x6e,
            0x53, 0x74, 0x72, 0x69, 0x6e, 0x67, 0x33, 0x56, 0x65, 0x72, 0x73,
            0x69, 0x6f, 0x6e, 0x53, 0x74, 0x72, 0x69, 0x6e, 0x67, 0x34};

    auto responseMsg =
        reinterpret_cast<const pldm_msg*>(getFwParamsResponse.data());
    pldm_get_firmware_parameters_resp outResp{};
    variable_field outActiveCompImageSetVersion{};
    variable_field outPendingCompImageSetVersion{};
    variable_field outCompParameterTable{};

    auto rc = decode_get_firmware_parameters_resp(
        responseMsg, getFwParamsPayloadLen, &outResp,
        &outActiveCompImageSetVersion, &outPendingCompImageSetVersion,
        &outCompParameterTable);

    EXPECT_EQ(rc, PLDM_SUCCESS);
    EXPECT_EQ(outResp.completion_code, PLDM_SUCCESS);
    EXPECT_EQ(outResp.capabilities_during_update.value, fdCapabilities);
    EXPECT_EQ(outResp.comp_count, compCount);
    EXPECT_EQ(outResp.active_comp_image_set_ver_str_type, PLDM_STR_TYPE_ASCII);
    EXPECT_EQ(outResp.active_comp_image_set_ver_str_len,
              activeCompImageSetVersion.size());
    EXPECT_EQ(outResp.pending_comp_image_set_ver_str_type, PLDM_STR_TYPE_ASCII);
    EXPECT_EQ(outResp.pending_comp_image_set_ver_str_len,
              pendingCompImageSetVersion.size());
    std::string activeCompImageSetVersionStr(
        reinterpret_cast<const char*>(outActiveCompImageSetVersion.ptr),
        outActiveCompImageSetVersion.length);
    EXPECT_EQ(activeCompImageSetVersionStr, activeCompImageSetVersion);
    std::string pendingCompImageSetVersionStr(
        reinterpret_cast<const char*>(outPendingCompImageSetVersion.ptr),
        outPendingCompImageSetVersion.length);
    EXPECT_EQ(pendingCompImageSetVersionStr, pendingCompImageSetVersion);
    EXPECT_EQ(outCompParameterTable.length, compParamTableSize);
    EXPECT_EQ(true, std::equal(outCompParameterTable.ptr,
                               outCompParameterTable.ptr +
                                   outCompParameterTable.length,
                               compParamTable.begin(), compParamTable.end()));
}

TEST(GetFirmwareParameters, decodeResponseZeroCompCount)
{
    // CapabilitiesDuringUpdate of the firmware device
    // FD Host Functionality during Firmware Update [Bit position 2] &
    // Component Update Failure Retry Capability [Bit position 1]
    constexpr std::bitset<32> fdCapabilities{0x06};
    constexpr uint16_t compCount = 0;
    constexpr std::string_view activeCompImageSetVersion{"VersionString1"};
    constexpr std::string_view pendingCompImageSetVersion{"VersionString2"};

    constexpr size_t getFwParamsPayloadLen =
        sizeof(pldm_get_firmware_parameters_resp) +
        activeCompImageSetVersion.size() + pendingCompImageSetVersion.size();

    constexpr std::array<uint8_t, hdrSize + getFwParamsPayloadLen>
        getFwParamsResponse{
            0x00, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
            0x0e, 0x01, 0x0e, 0x56, 0x65, 0x72, 0x73, 0x69, 0x6f, 0x6e, 0x53,
            0x74, 0x72, 0x69, 0x6e, 0x67, 0x31, 0x56, 0x65, 0x72, 0x73, 0x69,
            0x6f, 0x6e, 0x53, 0x74, 0x72, 0x69, 0x6e, 0x67, 0x32};

    auto responseMsg =
        reinterpret_cast<const pldm_msg*>(getFwParamsResponse.data());
    pldm_get_firmware_parameters_resp outResp{};
    variable_field outActiveCompImageSetVersion{};
    variable_field outPendingCompImageSetVersion{};
    variable_field outCompParameterTable{};

    auto rc = decode_get_firmware_parameters_resp(
        responseMsg, getFwParamsPayloadLen, &outResp,
        &outActiveCompImageSetVersion, &outPendingCompImageSetVersion,
        &outCompParameterTable);

    EXPECT_EQ(rc, PLDM_SUCCESS);
    EXPECT_EQ(outResp.completion_code, PLDM_SUCCESS);
    EXPECT_EQ(outResp.capabilities_during_update.value, fdCapabilities);
    EXPECT_EQ(outResp.comp_count, compCount);
    EXPECT_EQ(outResp.active_comp_image_set_ver_str_type, PLDM_STR_TYPE_ASCII);
    EXPECT_EQ(outResp.active_comp_image_set_ver_str_len,
              activeCompImageSetVersion.size());
    EXPECT_EQ(outResp.pending_comp_image_set_ver_str_type, PLDM_STR_TYPE_ASCII);
    EXPECT_EQ(outResp.pending_comp_image_set_ver_str_len,
              pendingCompImageSetVersion.size());
    std::string activeCompImageSetVersionStr(
        reinterpret_cast<const char*>(outActiveCompImageSetVersion.ptr),
        outActiveCompImageSetVersion.length);
    EXPECT_EQ(activeCompImageSetVersionStr, activeCompImageSetVersion);
    std::string pendingCompImageSetVersionStr(
        reinterpret_cast<const char*>(outPendingCompImageSetVersion.ptr),
        outPendingCompImageSetVersion.length);
    EXPECT_EQ(pendingCompImageSetVersionStr, pendingCompImageSetVersion);
    EXPECT_EQ(outCompParameterTable.ptr, nullptr);
    EXPECT_EQ(outCompParameterTable.length, 0);
}

TEST(GetFirmwareParameters,
     decodeResponseNoPendingCompImageVersionStrZeroCompCount)
{
    // CapabilitiesDuringUpdate of the firmware device
    // FD Host Functionality during Firmware Update [Bit position 2] &
    // Component Update Failure Retry Capability [Bit position 1]
    constexpr std::bitset<32> fdCapabilities{0x06};
    constexpr uint16_t compCount = 0;
    constexpr std::string_view activeCompImageSetVersion{"VersionString"};

    constexpr size_t getFwParamsPayloadLen =
        sizeof(pldm_get_firmware_parameters_resp) +
        activeCompImageSetVersion.size();

    constexpr std::array<uint8_t, hdrSize + getFwParamsPayloadLen>
        getFwParamsResponse{0x00, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00,
                            0x00, 0x00, 0x00, 0x01, 0x0d, 0x00, 0x00,
                            0x56, 0x65, 0x72, 0x73, 0x69, 0x6f, 0x6e,
                            0x53, 0x74, 0x72, 0x69, 0x6e, 0x67};

    auto responseMsg =
        reinterpret_cast<const pldm_msg*>(getFwParamsResponse.data());
    pldm_get_firmware_parameters_resp outResp{};
    variable_field outActiveCompImageSetVersion{};
    variable_field outPendingCompImageSetVersion{};
    variable_field outCompParameterTable{};

    auto rc = decode_get_firmware_parameters_resp(
        responseMsg, getFwParamsPayloadLen, &outResp,
        &outActiveCompImageSetVersion, &outPendingCompImageSetVersion,
        &outCompParameterTable);

    EXPECT_EQ(rc, PLDM_SUCCESS);
    EXPECT_EQ(outResp.completion_code, PLDM_SUCCESS);
    EXPECT_EQ(outResp.capabilities_during_update.value, fdCapabilities);
    EXPECT_EQ(outResp.comp_count, compCount);
    EXPECT_EQ(outResp.active_comp_image_set_ver_str_type, PLDM_STR_TYPE_ASCII);
    EXPECT_EQ(outResp.active_comp_image_set_ver_str_len,
              activeCompImageSetVersion.size());
    EXPECT_EQ(outResp.pending_comp_image_set_ver_str_type,
              PLDM_STR_TYPE_UNKNOWN);
    EXPECT_EQ(outResp.pending_comp_image_set_ver_str_len, 0);
    std::string activeCompImageSetVersionStr(
        reinterpret_cast<const char*>(outActiveCompImageSetVersion.ptr),
        outActiveCompImageSetVersion.length);
    EXPECT_EQ(activeCompImageSetVersionStr, activeCompImageSetVersion);
    EXPECT_EQ(outPendingCompImageSetVersion.ptr, nullptr);
    EXPECT_EQ(outPendingCompImageSetVersion.length, 0);
    EXPECT_EQ(outCompParameterTable.ptr, nullptr);
    EXPECT_EQ(outCompParameterTable.length, 0);
}

TEST(GetFirmwareParameters, decodeResponseErrorCompletionCode)
{
    constexpr std::array<uint8_t, hdrSize + sizeof(uint8_t)>
        getFwParamsResponse{0x00, 0x00, 0x00, 0x01};

    auto responseMsg =
        reinterpret_cast<const pldm_msg*>(getFwParamsResponse.data());
    pldm_get_firmware_parameters_resp outResp{};
    variable_field outActiveCompImageSetVersion{};
    variable_field outPendingCompImageSetVersion{};
    variable_field outCompParameterTable{};

    auto rc = decode_get_firmware_parameters_resp(
        responseMsg, getFwParamsResponse.size(), &outResp,
        &outActiveCompImageSetVersion, &outPendingCompImageSetVersion,
        &outCompParameterTable);

    EXPECT_EQ(rc, PLDM_SUCCESS);
    EXPECT_EQ(outResp.completion_code, PLDM_ERROR);
}

TEST(GetFirmwareParameters, errorPathdecodeResponse)
{
    int rc = 0;
    // Invalid ActiveComponentImageSetVersionStringType
    constexpr std::array<uint8_t, 14> invalidGetFwParamsResponse1{
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x06, 0x0e, 0x00, 0x00};

    auto responseMsg =
        reinterpret_cast<const pldm_msg*>(invalidGetFwParamsResponse1.data());
    pldm_get_firmware_parameters_resp outResp{};
    variable_field outActiveCompImageSetVersion{};
    variable_field outPendingCompImageSetVersion{};
    variable_field outCompParameterTable{};

    rc = decode_get_firmware_parameters_resp(
        nullptr, invalidGetFwParamsResponse1.size() - hdrSize, &outResp,
        &outActiveCompImageSetVersion, &outPendingCompImageSetVersion,
        &outCompParameterTable);
    EXPECT_EQ(rc, PLDM_ERROR_INVALID_DATA);

    rc = decode_get_firmware_parameters_resp(
        responseMsg, invalidGetFwParamsResponse1.size() - hdrSize, nullptr,
        &outActiveCompImageSetVersion, &outPendingCompImageSetVersion,
        &outCompParameterTable);
    EXPECT_EQ(rc, PLDM_ERROR_INVALID_DATA);

    rc = decode_get_firmware_parameters_resp(
        responseMsg, invalidGetFwParamsResponse1.size() - hdrSize, &outResp,
        nullptr, &outPendingCompImageSetVersion, &outCompParameterTable);
    EXPECT_EQ(rc, PLDM_ERROR_INVALID_DATA);

    rc = decode_get_firmware_parameters_resp(
        responseMsg, invalidGetFwParamsResponse1.size() - hdrSize, &outResp,
        &outActiveCompImageSetVersion, nullptr, &outCompParameterTable);
    EXPECT_EQ(rc, PLDM_ERROR_INVALID_DATA);

    rc = decode_get_firmware_parameters_resp(
        responseMsg, invalidGetFwParamsResponse1.size() - hdrSize, &outResp,
        &outActiveCompImageSetVersion, &outPendingCompImageSetVersion, nullptr);
    EXPECT_EQ(rc, PLDM_ERROR_INVALID_DATA);

    rc = decode_get_firmware_parameters_resp(
        responseMsg, 0, &outResp, &outActiveCompImageSetVersion,
        &outPendingCompImageSetVersion, &outCompParameterTable);
    EXPECT_EQ(rc, PLDM_ERROR_INVALID_DATA);

    rc = decode_get_firmware_parameters_resp(
        responseMsg, invalidGetFwParamsResponse1.size() - 1 - hdrSize, &outResp,
        &outActiveCompImageSetVersion, &outPendingCompImageSetVersion,
        &outCompParameterTable);
    EXPECT_EQ(rc, PLDM_ERROR_INVALID_LENGTH);

    rc = decode_get_firmware_parameters_resp(
        responseMsg, invalidGetFwParamsResponse1.size() - hdrSize, &outResp,
        &outActiveCompImageSetVersion, &outPendingCompImageSetVersion,
        &outCompParameterTable);
    EXPECT_EQ(rc, PLDM_ERROR_INVALID_DATA);

    // Invalid ActiveComponentImageSetVersionStringLength
    constexpr std::array<uint8_t, 14> invalidGetFwParamsResponse2{
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00};
    responseMsg =
        reinterpret_cast<const pldm_msg*>(invalidGetFwParamsResponse2.data());
    rc = decode_get_firmware_parameters_resp(
        responseMsg, invalidGetFwParamsResponse2.size() - hdrSize, &outResp,
        &outActiveCompImageSetVersion, &outPendingCompImageSetVersion,
        &outCompParameterTable);
    EXPECT_EQ(rc, PLDM_ERROR_INVALID_DATA);

    // Invalid PendingComponentImageSetVersionStringType &
    // PendingComponentImageSetVersionStringLength
    constexpr std::array<uint8_t, 14> invalidGetFwParamsResponse3{
        0x00, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x01, 0x0e, 0x01, 0x00};
    responseMsg =
        reinterpret_cast<const pldm_msg*>(invalidGetFwParamsResponse3.data());
    rc = decode_get_firmware_parameters_resp(
        responseMsg, invalidGetFwParamsResponse3.size() - hdrSize, &outResp,
        &outActiveCompImageSetVersion, &outPendingCompImageSetVersion,
        &outCompParameterTable);
    EXPECT_EQ(rc, PLDM_ERROR_INVALID_DATA);

    // Invalid PendingComponentImageSetVersionStringType &
    // PendingComponentImageSetVersionStringLength
    constexpr std::array<uint8_t, 14> invalidGetFwParamsResponse4{
        0x00, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x01, 0x0e, 0x06, 0x0e};
    responseMsg =
        reinterpret_cast<const pldm_msg*>(invalidGetFwParamsResponse4.data());
    rc = decode_get_firmware_parameters_resp(
        responseMsg, invalidGetFwParamsResponse4.size() - hdrSize, &outResp,
        &outActiveCompImageSetVersion, &outPendingCompImageSetVersion,
        &outCompParameterTable);
    EXPECT_EQ(rc, PLDM_ERROR_INVALID_DATA);

    // Total payload length less than expected
    constexpr std::array<uint8_t, 14> invalidGetFwParamsResponse5{
        0x00, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x01, 0x0e, 0x01, 0x0e};
    responseMsg =
        reinterpret_cast<const pldm_msg*>(invalidGetFwParamsResponse5.data());
    rc = decode_get_firmware_parameters_resp(
        responseMsg, invalidGetFwParamsResponse5.size() - hdrSize, &outResp,
        &outActiveCompImageSetVersion, &outPendingCompImageSetVersion,
        &outCompParameterTable);
    EXPECT_EQ(rc, PLDM_ERROR_INVALID_LENGTH);
}

TEST(GetFirmwareParameters, goodPathDecodeComponentParameterEntry)
{
    // Random value for component classification
    constexpr uint16_t compClassification = 0x0A0B;
    // Random value for component classification
    constexpr uint16_t compIdentifier = 0x0C0D;
    // Random value for component classification
    constexpr uint32_t timestamp = 0X12345678;
    // Random value for component activation methods
    constexpr uint16_t compActivationMethods = 0xBBDD;
    // Random value for capabilities during update
    constexpr uint32_t capabilitiesDuringUpdate = 0xBADBEEFE;

    // ActiveCompImageSetVerStrLen is not fixed here taking it as 8
    constexpr uint8_t activeCompVerStrLen = 8;
    // PendingCompImageSetVerStrLen is not fixed here taking it as 8
    constexpr uint8_t pendingCompVerStrLen = 8;
    constexpr size_t entryLength =
        sizeof(struct pldm_component_parameter_entry) + activeCompVerStrLen +
        pendingCompVerStrLen;
    std::array<uint8_t, entryLength> entry{};

    auto inEntry =
        reinterpret_cast<struct pldm_component_parameter_entry*>(entry.data());

    inEntry->comp_classification = htole16(compClassification);
    inEntry->comp_identifier = htole16(compIdentifier);
    inEntry->comp_classification_index = 0x0F;
    inEntry->active_comp_comparison_stamp = htole32(timestamp);
    inEntry->active_comp_ver_str_type = 1;
    inEntry->active_comp_ver_str_len = activeCompVerStrLen;
    std::fill_n(inEntry->active_comp_release_date,
                sizeof(inEntry->active_comp_release_date), 0xFF);
    inEntry->pending_comp_comparison_stamp = htole32(timestamp);
    inEntry->pending_comp_ver_str_type = 1;
    inEntry->pending_comp_ver_str_len = pendingCompVerStrLen;
    std::fill_n(inEntry->pending_comp_release_date,
                sizeof(inEntry->pending_comp_release_date), 0xFF);
    inEntry->comp_activation_methods.value = htole16(compActivationMethods);
    inEntry->capabilities_during_update.value =
        htole32(capabilitiesDuringUpdate);
    constexpr auto activeCompVerStrPos =
        sizeof(struct pldm_component_parameter_entry);
    std::fill_n(entry.data() + activeCompVerStrPos, activeCompVerStrLen, 0xAA);
    constexpr auto pendingCompVerStrPos =
        activeCompVerStrPos + activeCompVerStrLen;
    std::fill_n(entry.data() + pendingCompVerStrPos, pendingCompVerStrLen,
                0xBB);

    struct pldm_component_parameter_entry outEntry;
    struct variable_field outActiveCompVerStr;
    struct variable_field outPendingCompVerStr;

    auto rc = decode_get_firmware_parameters_resp_comp_entry(
        entry.data(), entryLength, &outEntry, &outActiveCompVerStr,
        &outPendingCompVerStr);

    EXPECT_EQ(rc, PLDM_SUCCESS);

    EXPECT_EQ(outEntry.comp_classification, compClassification);
    EXPECT_EQ(outEntry.comp_identifier, compIdentifier);
    EXPECT_EQ(inEntry->comp_classification_index,
              outEntry.comp_classification_index);
    EXPECT_EQ(outEntry.active_comp_comparison_stamp, timestamp);
    EXPECT_EQ(inEntry->active_comp_ver_str_type,
              outEntry.active_comp_ver_str_type);
    EXPECT_EQ(inEntry->active_comp_ver_str_len,
              outEntry.active_comp_ver_str_len);
    EXPECT_EQ(0, memcmp(inEntry->active_comp_release_date,
                        outEntry.active_comp_release_date,
                        sizeof(inEntry->active_comp_release_date)));
    EXPECT_EQ(outEntry.pending_comp_comparison_stamp, timestamp);
    EXPECT_EQ(inEntry->pending_comp_ver_str_type,
              outEntry.pending_comp_ver_str_type);
    EXPECT_EQ(inEntry->pending_comp_ver_str_len,
              outEntry.pending_comp_ver_str_len);
    EXPECT_EQ(0, memcmp(inEntry->pending_comp_release_date,
                        outEntry.pending_comp_release_date,
                        sizeof(inEntry->pending_comp_release_date)));
    EXPECT_EQ(outEntry.comp_activation_methods.value, compActivationMethods);
    EXPECT_EQ(outEntry.capabilities_during_update.value,
              capabilitiesDuringUpdate);

    EXPECT_EQ(0, memcmp(outActiveCompVerStr.ptr,
                        entry.data() + activeCompVerStrPos,
                        outActiveCompVerStr.length));
    EXPECT_EQ(0, memcmp(outPendingCompVerStr.ptr,
                        entry.data() + pendingCompVerStrPos,
                        outPendingCompVerStr.length));
}

TEST(RequestUpdate, goodPathEncodeRequest)
{
    constexpr uint8_t instanceId = 1;
    constexpr uint32_t maxTransferSize = 512;
    constexpr uint16_t numOfComp = 3;
    constexpr uint8_t maxOutstandingTransferReq = 2;
    constexpr uint16_t pkgDataLen = 0x1234;
    constexpr std::string_view compImgSetVerStr = "0penBmcv1.0";
    constexpr uint8_t compImgSetVerStrLen =
        static_cast<uint8_t>(compImgSetVerStr.size());
    variable_field compImgSetVerStrInfo{};
    compImgSetVerStrInfo.ptr =
        reinterpret_cast<const uint8_t*>(compImgSetVerStr.data());
    compImgSetVerStrInfo.length = compImgSetVerStrLen;

    std::array<uint8_t, hdrSize + sizeof(struct pldm_request_update_req) +
                            compImgSetVerStrLen>
        request{};
    auto requestMsg = reinterpret_cast<pldm_msg*>(request.data());

    auto rc = encode_request_update_req(
        instanceId, maxTransferSize, numOfComp, maxOutstandingTransferReq,
        pkgDataLen, PLDM_STR_TYPE_ASCII, compImgSetVerStrLen,
        &compImgSetVerStrInfo, requestMsg,
        sizeof(struct pldm_request_update_req) + compImgSetVerStrLen);
    EXPECT_EQ(rc, PLDM_SUCCESS);

    std::array<uint8_t, hdrSize + sizeof(struct pldm_request_update_req) +
                            compImgSetVerStrLen>
        outRequest{0x81, 0x05, 0x10, 0x00, 0x02, 0x00, 0x00, 0x03, 0x00,
                   0x02, 0x34, 0x12, 0x01, 0x0b, 0x30, 0x70, 0x65, 0x6e,
                   0x42, 0x6d, 0x63, 0x76, 0x31, 0x2e, 0x30};
    EXPECT_EQ(request, outRequest);
}

TEST(RequestUpdate, errorPathEncodeRequest)
{
    constexpr uint8_t instanceId = 1;
    uint32_t maxTransferSize = 512;
    constexpr uint16_t numOfComp = 3;
    uint8_t maxOutstandingTransferReq = 2;
    constexpr uint16_t pkgDataLen = 0x1234;
    constexpr std::string_view compImgSetVerStr = "0penBmcv1.0";
    uint8_t compImgSetVerStrLen = static_cast<uint8_t>(compImgSetVerStr.size());
    variable_field compImgSetVerStrInfo{};
    compImgSetVerStrInfo.ptr =
        reinterpret_cast<const uint8_t*>(compImgSetVerStr.data());
    compImgSetVerStrInfo.length = compImgSetVerStrLen;

    std::array<uint8_t, hdrSize + sizeof(struct pldm_request_update_req) +
                            compImgSetVerStr.size()>
        request{};
    auto requestMsg = reinterpret_cast<pldm_msg*>(request.data());

    auto rc = encode_request_update_req(
        instanceId, maxTransferSize, numOfComp, maxOutstandingTransferReq,
        pkgDataLen, PLDM_STR_TYPE_ASCII, compImgSetVerStrLen, nullptr,
        requestMsg,
        sizeof(struct pldm_request_update_req) + compImgSetVerStrLen);
    EXPECT_EQ(rc, PLDM_ERROR_INVALID_DATA);

    compImgSetVerStrInfo.ptr = nullptr;
    rc = encode_request_update_req(
        instanceId, maxTransferSize, numOfComp, maxOutstandingTransferReq,
        pkgDataLen, PLDM_STR_TYPE_ASCII, compImgSetVerStrLen,
        &compImgSetVerStrInfo, requestMsg,
        sizeof(struct pldm_request_update_req) + compImgSetVerStrLen);
    EXPECT_EQ(rc, PLDM_ERROR_INVALID_DATA);
    compImgSetVerStrInfo.ptr =
        reinterpret_cast<const uint8_t*>(compImgSetVerStr.data());

    rc = encode_request_update_req(
        instanceId, maxTransferSize, numOfComp, maxOutstandingTransferReq,
        pkgDataLen, PLDM_STR_TYPE_ASCII, compImgSetVerStrLen,
        &compImgSetVerStrInfo, nullptr,
        sizeof(struct pldm_request_update_req) + compImgSetVerStrLen);
    EXPECT_EQ(rc, PLDM_ERROR_INVALID_DATA);

    rc = encode_request_update_req(instanceId, maxTransferSize, numOfComp,
                                   maxOutstandingTransferReq, pkgDataLen,
                                   PLDM_STR_TYPE_ASCII, compImgSetVerStrLen,
                                   &compImgSetVerStrInfo, requestMsg, 0);
    EXPECT_EQ(rc, PLDM_ERROR_INVALID_LENGTH);

    compImgSetVerStrLen = 0;
    rc = encode_request_update_req(
        instanceId, maxTransferSize, numOfComp, maxOutstandingTransferReq,
        pkgDataLen, PLDM_STR_TYPE_ASCII, 0, &compImgSetVerStrInfo, nullptr,
        sizeof(struct pldm_request_update_req) + compImgSetVerStrLen);
    EXPECT_EQ(rc, PLDM_ERROR_INVALID_DATA);
    compImgSetVerStrLen = static_cast<uint8_t>(compImgSetVerStr.size());

    compImgSetVerStrInfo.length = 0xFFFF;
    rc = encode_request_update_req(
        instanceId, maxTransferSize, numOfComp, maxOutstandingTransferReq,
        pkgDataLen, PLDM_STR_TYPE_ASCII, compImgSetVerStrLen,
        &compImgSetVerStrInfo, nullptr,
        sizeof(struct pldm_request_update_req) + compImgSetVerStrLen);
    EXPECT_EQ(rc, PLDM_ERROR_INVALID_DATA);
    compImgSetVerStrInfo.length = compImgSetVerStrLen;

    maxTransferSize = PLDM_FWUP_BASELINE_TRANSFER_SIZE - 1;
    rc = encode_request_update_req(
        instanceId, maxTransferSize, numOfComp, maxOutstandingTransferReq,
        pkgDataLen, PLDM_STR_TYPE_ASCII, compImgSetVerStrLen,
        &compImgSetVerStrInfo, nullptr,
        sizeof(struct pldm_request_update_req) + compImgSetVerStrLen);
    EXPECT_EQ(rc, PLDM_ERROR_INVALID_DATA);
    maxTransferSize = PLDM_FWUP_BASELINE_TRANSFER_SIZE;

    maxOutstandingTransferReq = PLDM_FWUP_MIN_OUTSTANDING_REQ - 1;
    rc = encode_request_update_req(
        instanceId, maxTransferSize, numOfComp, maxOutstandingTransferReq,
        pkgDataLen, PLDM_STR_TYPE_ASCII, compImgSetVerStrLen,
        &compImgSetVerStrInfo, nullptr,
        sizeof(struct pldm_request_update_req) + compImgSetVerStrLen);
    EXPECT_EQ(rc, PLDM_ERROR_INVALID_DATA);
    maxOutstandingTransferReq = PLDM_FWUP_MIN_OUTSTANDING_REQ;

    rc = encode_request_update_req(
        instanceId, maxTransferSize, numOfComp, maxOutstandingTransferReq,
        pkgDataLen, PLDM_STR_TYPE_UNKNOWN, compImgSetVerStrLen,
        &compImgSetVerStrInfo, nullptr,
        sizeof(struct pldm_request_update_req) + compImgSetVerStrLen);
    EXPECT_EQ(rc, PLDM_ERROR_INVALID_DATA);
}

TEST(RequestUpdate, goodPathDecodeResponse)
{
    constexpr uint16_t fdMetaDataLen = 1024;
    constexpr uint8_t fdWillSendPkgData = 1;
    constexpr std::array<uint8_t, hdrSize + sizeof(pldm_request_update_resp)>
        requestUpdateResponse1{0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x01};

    auto responseMsg1 =
        reinterpret_cast<const pldm_msg*>(requestUpdateResponse1.data());
    uint8_t outCompletionCode = 0;
    uint16_t outFdMetaDataLen = 0;
    uint8_t outFdWillSendPkgData = 0;

    auto rc = decode_request_update_resp(
        responseMsg1, requestUpdateResponse1.size() - hdrSize,
        &outCompletionCode, &outFdMetaDataLen, &outFdWillSendPkgData);
    EXPECT_EQ(rc, PLDM_SUCCESS);
    EXPECT_EQ(outCompletionCode, PLDM_SUCCESS);
    EXPECT_EQ(outFdMetaDataLen, fdMetaDataLen);
    EXPECT_EQ(outFdWillSendPkgData, fdWillSendPkgData);

    outCompletionCode = 0;
    outFdMetaDataLen = 0;
    outFdWillSendPkgData = 0;

    constexpr std::array<uint8_t, hdrSize + sizeof(outCompletionCode)>
        requestUpdateResponse2{0x00, 0x00, 0x00, 0x81};
    auto responseMsg2 =
        reinterpret_cast<const pldm_msg*>(requestUpdateResponse2.data());
    rc = decode_request_update_resp(
        responseMsg2, requestUpdateResponse2.size() - hdrSize,
        &outCompletionCode, &outFdMetaDataLen, &outFdWillSendPkgData);
    EXPECT_EQ(rc, PLDM_SUCCESS);
    EXPECT_EQ(outCompletionCode, PLDM_FWUP_ALREADY_IN_UPDATE_MODE);
}

TEST(RequestUpdate, errorPathDecodeResponse)
{
    constexpr std::array<uint8_t,
                         hdrSize + sizeof(pldm_request_update_resp) - 1>
        requestUpdateResponse{0x00, 0x00, 0x00, 0x00, 0x00, 0x04};

    auto responseMsg =
        reinterpret_cast<const pldm_msg*>(requestUpdateResponse.data());
    uint8_t outCompletionCode = 0;
    uint16_t outFdMetaDataLen = 0;
    uint8_t outFdWillSendPkgData = 0;

    auto rc = decode_request_update_resp(
        nullptr, requestUpdateResponse.size() - hdrSize, &outCompletionCode,
        &outFdMetaDataLen, &outFdWillSendPkgData);
    EXPECT_EQ(rc, PLDM_ERROR_INVALID_DATA);

    rc = decode_request_update_resp(
        responseMsg, requestUpdateResponse.size() - hdrSize, nullptr,
        &outFdMetaDataLen, &outFdWillSendPkgData);
    EXPECT_EQ(rc, PLDM_ERROR_INVALID_DATA);

    rc = decode_request_update_resp(
        responseMsg, requestUpdateResponse.size() - hdrSize, &outCompletionCode,
        nullptr, &outFdWillSendPkgData);
    EXPECT_EQ(rc, PLDM_ERROR_INVALID_DATA);

    rc = decode_request_update_resp(
        responseMsg, requestUpdateResponse.size() - hdrSize, &outCompletionCode,
        &outFdMetaDataLen, nullptr);
    EXPECT_EQ(rc, PLDM_ERROR_INVALID_DATA);

    rc = decode_request_update_resp(responseMsg, 0, &outCompletionCode,
                                    &outFdMetaDataLen, &outFdWillSendPkgData);
    EXPECT_EQ(rc, PLDM_ERROR_INVALID_DATA);

    rc = decode_request_update_resp(
        responseMsg, requestUpdateResponse.size() - hdrSize, &outCompletionCode,
        &outFdMetaDataLen, &outFdWillSendPkgData);
    EXPECT_EQ(rc, PLDM_ERROR_INVALID_LENGTH);
}

TEST(PassComponentTable, goodPathEncodeRequest)
{
    constexpr uint8_t instanceId = 1;
    constexpr uint16_t compIdentifier = 400;
    constexpr uint8_t compClassificationIndex = 40;
    constexpr uint32_t compComparisonStamp = 0x12345678;
    constexpr std::string_view compVerStr = "0penBmcv1.1";
    constexpr uint8_t compVerStrLen = static_cast<uint8_t>(compVerStr.size());
    variable_field compVerStrInfo{};
    compVerStrInfo.ptr = reinterpret_cast<const uint8_t*>(compVerStr.data());
    compVerStrInfo.length = compVerStrLen;

    std::array<uint8_t,
               hdrSize + sizeof(pldm_pass_component_table_req) + compVerStrLen>
        request{};
    auto requestMsg = reinterpret_cast<pldm_msg*>(request.data());

    auto rc = encode_pass_component_table_req(
        instanceId, PLDM_START_AND_END, PLDM_COMP_FIRMWARE, compIdentifier,
        compClassificationIndex, compComparisonStamp, PLDM_STR_TYPE_ASCII,
        compVerStrLen, &compVerStrInfo, requestMsg,
        sizeof(pldm_pass_component_table_req) + compVerStrLen);
    EXPECT_EQ(rc, PLDM_SUCCESS);

    std::array<uint8_t,
               hdrSize + sizeof(pldm_pass_component_table_req) + compVerStrLen>
        outRequest{0x81, 0x05, 0x13, 0x05, 0x0A, 0x00, 0x90, 0x01, 0x28,
                   0x78, 0x56, 0x34, 0x12, 0x01, 0x0B, 0x30, 0x70, 0x65,
                   0x6E, 0x42, 0x6D, 0x63, 0x76, 0x31, 0x2E, 0x31};
    EXPECT_EQ(request, outRequest);
}

TEST(PassComponentTable, errorPathEncodeRequest)
{
    constexpr uint8_t instanceId = 1;
    constexpr uint16_t compIdentifier = 400;
    constexpr uint8_t compClassificationIndex = 40;
    constexpr uint32_t compComparisonStamp = 0x12345678;
    constexpr std::string_view compVerStr = "0penBmcv1.1";
    constexpr uint8_t compVerStrLen = static_cast<uint8_t>(compVerStr.size());
    variable_field compVerStrInfo{};
    compVerStrInfo.ptr = reinterpret_cast<const uint8_t*>(compVerStr.data());
    compVerStrInfo.length = compVerStrLen;

    std::array<uint8_t,
               hdrSize + sizeof(pldm_pass_component_table_req) + compVerStrLen>
        request{};
    auto requestMsg = reinterpret_cast<pldm_msg*>(request.data());

    auto rc = encode_pass_component_table_req(
        instanceId, PLDM_START_AND_END, PLDM_COMP_FIRMWARE, compIdentifier,
        compClassificationIndex, compComparisonStamp, PLDM_STR_TYPE_ASCII,
        compVerStrLen, nullptr, requestMsg,
        sizeof(pldm_pass_component_table_req) + compVerStrLen);
    EXPECT_EQ(rc, PLDM_ERROR_INVALID_DATA);

    compVerStrInfo.ptr = nullptr;
    rc = encode_pass_component_table_req(
        instanceId, PLDM_START_AND_END, PLDM_COMP_FIRMWARE, compIdentifier,
        compClassificationIndex, compComparisonStamp, PLDM_STR_TYPE_ASCII,
        compVerStrLen, &compVerStrInfo, requestMsg,
        sizeof(pldm_pass_component_table_req) + compVerStrLen);
    EXPECT_EQ(rc, PLDM_ERROR_INVALID_DATA);
    compVerStrInfo.ptr = reinterpret_cast<const uint8_t*>(compVerStr.data());

    rc = encode_pass_component_table_req(
        instanceId, PLDM_START_AND_END, PLDM_COMP_FIRMWARE, compIdentifier,
        compClassificationIndex, compComparisonStamp, PLDM_STR_TYPE_ASCII,
        compVerStrLen, &compVerStrInfo, nullptr,
        sizeof(pldm_pass_component_table_req) + compVerStrLen);
    EXPECT_EQ(rc, PLDM_ERROR_INVALID_DATA);

    rc = encode_pass_component_table_req(
        instanceId, PLDM_START_AND_END, PLDM_COMP_FIRMWARE, compIdentifier,
        compClassificationIndex, compComparisonStamp, PLDM_STR_TYPE_ASCII,
        compVerStrLen, &compVerStrInfo, requestMsg,
        sizeof(pldm_pass_component_table_req));
    EXPECT_EQ(rc, PLDM_ERROR_INVALID_LENGTH);

    rc = encode_pass_component_table_req(
        instanceId, PLDM_START_AND_END, PLDM_COMP_FIRMWARE, compIdentifier,
        compClassificationIndex, compComparisonStamp, PLDM_STR_TYPE_ASCII, 0,
        &compVerStrInfo, requestMsg,
        sizeof(pldm_pass_component_table_req) + compVerStrLen);
    EXPECT_EQ(rc, PLDM_ERROR_INVALID_DATA);

    rc = encode_pass_component_table_req(
        instanceId, PLDM_START_AND_END, PLDM_COMP_FIRMWARE, compIdentifier,
        compClassificationIndex, compComparisonStamp, PLDM_STR_TYPE_ASCII,
        compVerStrLen - 1, &compVerStrInfo, requestMsg,
        sizeof(pldm_pass_component_table_req) + compVerStrLen);
    EXPECT_EQ(rc, PLDM_ERROR_INVALID_DATA);

    rc = encode_pass_component_table_req(
        instanceId, PLDM_START_AND_END + 1, PLDM_COMP_FIRMWARE, compIdentifier,
        compClassificationIndex, compComparisonStamp, PLDM_STR_TYPE_ASCII,
        compVerStrLen, &compVerStrInfo, requestMsg,
        sizeof(pldm_pass_component_table_req) + compVerStrLen);
    EXPECT_EQ(rc, PLDM_INVALID_TRANSFER_OPERATION_FLAG);

    rc = encode_pass_component_table_req(
        instanceId, PLDM_START_AND_END, PLDM_COMP_FIRMWARE, compIdentifier,
        compClassificationIndex, compComparisonStamp, PLDM_STR_TYPE_UNKNOWN,
        compVerStrLen, &compVerStrInfo, requestMsg,
        sizeof(pldm_pass_component_table_req) + compVerStrLen);
    EXPECT_EQ(rc, PLDM_ERROR_INVALID_DATA);
}

TEST(PassComponentTable, goodPathDecodeResponse)
{
    constexpr std::array<uint8_t,
                         hdrSize + sizeof(pldm_pass_component_table_resp)>
        passCompTableResponse1{0x00, 0x00, 0x00, 0x00, 0x00, 0x01};
    auto responseMsg1 =
        reinterpret_cast<const pldm_msg*>(passCompTableResponse1.data());

    uint8_t completionCode = 0;
    uint8_t compResp = 0;
    uint8_t compRespCode = 0;

    auto rc = decode_pass_component_table_resp(
        responseMsg1, sizeof(pldm_pass_component_table_resp), &completionCode,
        &compResp, &compRespCode);

    EXPECT_EQ(rc, PLDM_SUCCESS);
    EXPECT_EQ(completionCode, PLDM_SUCCESS);
    EXPECT_EQ(compResp, PLDM_CR_COMP_CAN_BE_UPDATED);
    EXPECT_EQ(compRespCode, PLDM_CRC_COMP_COMPARISON_STAMP_IDENTICAL);

    constexpr std::array<uint8_t,
                         hdrSize + sizeof(pldm_pass_component_table_resp)>
        passCompTableResponse2{0x00, 0x00, 0x00, 0x00, 0x00, 0xD0};
    auto responseMsg2 =
        reinterpret_cast<const pldm_msg*>(passCompTableResponse2.data());
    rc = decode_pass_component_table_resp(
        responseMsg2, sizeof(pldm_pass_component_table_resp), &completionCode,
        &compResp, &compRespCode);

    EXPECT_EQ(rc, PLDM_SUCCESS);
    EXPECT_EQ(completionCode, PLDM_SUCCESS);
    EXPECT_EQ(compResp, PLDM_CR_COMP_CAN_BE_UPDATED);
    EXPECT_EQ(compRespCode, PLDM_CRC_VENDOR_COMP_RESP_CODE_RANGE_MIN);

    constexpr std::array<uint8_t,
                         hdrSize + sizeof(pldm_pass_component_table_resp)>
        passCompTableResponse3{0x00, 0x00, 0x00, 0x80};
    auto responseMsg3 =
        reinterpret_cast<const pldm_msg*>(passCompTableResponse3.data());

    rc = decode_pass_component_table_resp(
        responseMsg3, sizeof(pldm_pass_component_table_resp), &completionCode,
        &compResp, &compRespCode);

    EXPECT_EQ(rc, PLDM_SUCCESS);
    EXPECT_EQ(completionCode, PLDM_FWUP_NOT_IN_UPDATE_MODE);
}

TEST(PassComponentTable, errorPathDecodeResponse)
{
    constexpr std::array<uint8_t,
                         hdrSize + sizeof(pldm_pass_component_table_resp) - 1>
        passCompTableResponse1{0x00, 0x00, 0x00, 0x00, 0x00};
    auto responseMsg1 =
        reinterpret_cast<const pldm_msg*>(passCompTableResponse1.data());

    uint8_t completionCode = 0;
    uint8_t compResp = 0;
    uint8_t compRespCode = 0;

    auto rc = decode_pass_component_table_resp(
        nullptr, sizeof(pldm_pass_component_table_resp) - 1, &completionCode,
        &compResp, &compRespCode);
    EXPECT_EQ(rc, PLDM_ERROR_INVALID_DATA);

    rc = decode_pass_component_table_resp(
        responseMsg1, sizeof(pldm_pass_component_table_resp) - 1, nullptr,
        &compResp, &compRespCode);
    EXPECT_EQ(rc, PLDM_ERROR_INVALID_DATA);

    rc = decode_pass_component_table_resp(
        responseMsg1, sizeof(pldm_pass_component_table_resp) - 1,
        &completionCode, nullptr, &compRespCode);
    EXPECT_EQ(rc, PLDM_ERROR_INVALID_DATA);

    rc = decode_pass_component_table_resp(
        responseMsg1, sizeof(pldm_pass_component_table_resp) - 1,
        &completionCode, &compResp, nullptr);
    EXPECT_EQ(rc, PLDM_ERROR_INVALID_DATA);

    rc = decode_pass_component_table_resp(responseMsg1, 0, &completionCode,
                                          &compResp, &compRespCode);
    EXPECT_EQ(rc, PLDM_ERROR_INVALID_DATA);

    rc = decode_pass_component_table_resp(
        responseMsg1, sizeof(pldm_pass_component_table_resp) - 1,
        &completionCode, &compResp, &compRespCode);
    EXPECT_EQ(rc, PLDM_ERROR_INVALID_LENGTH);

    constexpr std::array<uint8_t,
                         hdrSize + sizeof(pldm_pass_component_table_resp)>
        passCompTableResponse2{0x00, 0x00, 0x00, 0x00, 0x02, 0x00};
    auto responseMsg2 =
        reinterpret_cast<const pldm_msg*>(passCompTableResponse2.data());
    rc = decode_pass_component_table_resp(
        responseMsg2, sizeof(pldm_pass_component_table_resp), &completionCode,
        &compResp, &compRespCode);
    EXPECT_EQ(rc, PLDM_ERROR_INVALID_DATA);

    constexpr std::array<uint8_t,
                         hdrSize + sizeof(pldm_pass_component_table_resp)>
        passCompTableResponse3{0x00, 0x00, 0x00, 0x00, 0x00, 0x0C};
    auto responseMsg3 =
        reinterpret_cast<const pldm_msg*>(passCompTableResponse3.data());
    rc = decode_pass_component_table_resp(
        responseMsg3, sizeof(pldm_pass_component_table_resp), &completionCode,
        &compResp, &compRespCode);
    EXPECT_EQ(rc, PLDM_ERROR_INVALID_DATA);

    constexpr std::array<uint8_t,
                         hdrSize + sizeof(pldm_pass_component_table_resp)>
        passCompTableResponse4{0x00, 0x00, 0x00, 0x00, 0x00, 0xF0};
    auto responseMsg4 =
        reinterpret_cast<const pldm_msg*>(passCompTableResponse4.data());
    rc = decode_pass_component_table_resp(
        responseMsg4, sizeof(pldm_pass_component_table_resp), &completionCode,
        &compResp, &compRespCode);
    EXPECT_EQ(rc, PLDM_ERROR_INVALID_DATA);
}

TEST(UpdateComponent, goodPathEncodeRequest)
{
    constexpr uint8_t instanceId = 2;
    constexpr uint16_t compIdentifier = 500;
    constexpr uint8_t compClassificationIndex = 50;
    constexpr uint32_t compComparisonStamp = 0x89ABCDEF;
    constexpr uint32_t compImageSize = 4096;
    constexpr bitfield32_t updateOptionFlags{1};
    constexpr std::string_view compVerStr = "OpenBmcv2.2";
    constexpr uint8_t compVerStrLen = static_cast<uint8_t>(compVerStr.size());
    variable_field compVerStrInfo{};
    compVerStrInfo.ptr = reinterpret_cast<const uint8_t*>(compVerStr.data());
    compVerStrInfo.length = compVerStrLen;

    std::array<uint8_t,
               hdrSize + sizeof(pldm_update_component_req) + compVerStrLen>
        request{};
    auto requestMsg = reinterpret_cast<pldm_msg*>(request.data());

    auto rc = encode_update_component_req(
        instanceId, PLDM_COMP_FIRMWARE, compIdentifier, compClassificationIndex,
        compComparisonStamp, compImageSize, updateOptionFlags,
        PLDM_STR_TYPE_ASCII, compVerStrLen, &compVerStrInfo, requestMsg,
        sizeof(pldm_update_component_req) + compVerStrLen);
    EXPECT_EQ(rc, PLDM_SUCCESS);

    std::array<uint8_t,
               hdrSize + sizeof(pldm_update_component_req) + compVerStrLen>
        outRequest{0x82, 0x05, 0x14, 0x0A, 0x00, 0xF4, 0x01, 0x32, 0xEF,
                   0xCD, 0xAB, 0x89, 0x00, 0x10, 0x00, 0x00, 0x01, 0x00,
                   0x00, 0x00, 0x01, 0x0B, 0x4f, 0x70, 0x65, 0x6E, 0x42,
                   0x6D, 0x63, 0x76, 0x32, 0x2E, 0x32};
    EXPECT_EQ(request, outRequest);
}

TEST(UpdateComponent, errorPathEncodeRequest)
{
    constexpr uint8_t instanceId = 2;
    constexpr uint16_t compIdentifier = 500;
    constexpr uint8_t compClassificationIndex = 50;
    constexpr uint32_t compComparisonStamp = 0x89ABCDEF;
    constexpr uint32_t compImageSize = 4096;
    constexpr bitfield32_t updateOptionFlags{1};
    constexpr std::string_view compVerStr = "OpenBmcv2.2";
    constexpr uint8_t compVerStrLen = static_cast<uint8_t>(compVerStr.size());
    variable_field compVerStrInfo{};
    compVerStrInfo.ptr = reinterpret_cast<const uint8_t*>(compVerStr.data());
    compVerStrInfo.length = compVerStrLen;

    std::array<uint8_t,
               hdrSize + sizeof(pldm_update_component_req) + compVerStrLen>
        request{};
    auto requestMsg = reinterpret_cast<pldm_msg*>(request.data());

    auto rc = encode_update_component_req(
        instanceId, PLDM_COMP_FIRMWARE, compIdentifier, compClassificationIndex,
        compComparisonStamp, compImageSize, updateOptionFlags,
        PLDM_STR_TYPE_ASCII, compVerStrLen, nullptr, requestMsg,
        sizeof(pldm_update_component_req) + compVerStrLen);
    EXPECT_EQ(rc, PLDM_ERROR_INVALID_DATA);

    compVerStrInfo.ptr = nullptr;
    rc = encode_update_component_req(
        instanceId, PLDM_COMP_FIRMWARE, compIdentifier, compClassificationIndex,
        compComparisonStamp, compImageSize, updateOptionFlags,
        PLDM_STR_TYPE_ASCII, compVerStrLen, &compVerStrInfo, requestMsg,
        sizeof(pldm_update_component_req) + compVerStrLen);
    EXPECT_EQ(rc, PLDM_ERROR_INVALID_DATA);
    compVerStrInfo.ptr = reinterpret_cast<const uint8_t*>(compVerStr.data());

    rc = encode_update_component_req(
        instanceId, PLDM_COMP_FIRMWARE, compIdentifier, compClassificationIndex,
        compComparisonStamp, compImageSize, updateOptionFlags,
        PLDM_STR_TYPE_ASCII, compVerStrLen, &compVerStrInfo, nullptr,
        sizeof(pldm_update_component_req) + compVerStrLen);
    EXPECT_EQ(rc, PLDM_ERROR_INVALID_DATA);

    rc = encode_update_component_req(
        instanceId, PLDM_COMP_FIRMWARE, compIdentifier, compClassificationIndex,
        compComparisonStamp, compImageSize, updateOptionFlags,
        PLDM_STR_TYPE_ASCII, compVerStrLen, &compVerStrInfo, requestMsg,
        sizeof(pldm_update_component_req));
    EXPECT_EQ(rc, PLDM_ERROR_INVALID_LENGTH);

    rc = encode_update_component_req(
        instanceId, PLDM_COMP_FIRMWARE, compIdentifier, compClassificationIndex,
        compComparisonStamp, 0, updateOptionFlags, PLDM_STR_TYPE_ASCII,
        compVerStrLen, &compVerStrInfo, requestMsg,
        sizeof(pldm_update_component_req) + compVerStrLen);
    EXPECT_EQ(rc, PLDM_ERROR_INVALID_DATA);

    rc = encode_update_component_req(
        instanceId, PLDM_COMP_FIRMWARE, compIdentifier, compClassificationIndex,
        compComparisonStamp, compImageSize, updateOptionFlags,
        PLDM_STR_TYPE_ASCII, 0, &compVerStrInfo, requestMsg,
        sizeof(pldm_update_component_req) + compVerStrLen);
    EXPECT_EQ(rc, PLDM_ERROR_INVALID_DATA);

    rc = encode_update_component_req(
        instanceId, PLDM_COMP_FIRMWARE, compIdentifier, compClassificationIndex,
        compComparisonStamp, compImageSize, updateOptionFlags,
        PLDM_STR_TYPE_ASCII, compVerStrLen - 1, &compVerStrInfo, requestMsg,
        sizeof(pldm_update_component_req) + compVerStrLen);
    EXPECT_EQ(rc, PLDM_ERROR_INVALID_DATA);

    rc = encode_update_component_req(
        instanceId, PLDM_COMP_FIRMWARE, compIdentifier, compClassificationIndex,
        compComparisonStamp, compImageSize, updateOptionFlags,
        PLDM_STR_TYPE_UNKNOWN, compVerStrLen, &compVerStrInfo, requestMsg,
        sizeof(pldm_update_component_req) + compVerStrLen);
    EXPECT_EQ(rc, PLDM_ERROR_INVALID_DATA);
}

TEST(UpdateComponent, goodPathDecodeResponse)
{
    constexpr std::bitset<32> forceUpdateComp{1};
    constexpr uint16_t timeBeforeSendingReqFwData100s = 100;
    constexpr std::array<uint8_t, hdrSize + sizeof(pldm_update_component_resp)>
        updateComponentResponse1{0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                 0x01, 0x00, 0x00, 0x00, 0x64, 0x00};
    auto responseMsg1 =
        reinterpret_cast<const pldm_msg*>(updateComponentResponse1.data());

    uint8_t completionCode = 0;
    uint8_t compCompatibilityResp = 0;
    uint8_t compCompatibilityRespCode = 0;
    bitfield32_t updateOptionFlagsEnabled{};
    uint16_t timeBeforeReqFWData = 0;

    auto rc = decode_update_component_resp(
        responseMsg1, sizeof(pldm_update_component_resp), &completionCode,
        &compCompatibilityResp, &compCompatibilityRespCode,
        &updateOptionFlagsEnabled, &timeBeforeReqFWData);

    EXPECT_EQ(rc, PLDM_SUCCESS);
    EXPECT_EQ(completionCode, PLDM_SUCCESS);
    EXPECT_EQ(compCompatibilityResp, PLDM_CCR_COMP_CAN_BE_UPDATED);
    EXPECT_EQ(compCompatibilityRespCode, PLDM_CCRC_NO_RESPONSE_CODE);
    EXPECT_EQ(updateOptionFlagsEnabled.value, forceUpdateComp);
    EXPECT_EQ(timeBeforeReqFWData, timeBeforeSendingReqFwData100s);

    constexpr std::bitset<32> noFlags{};
    constexpr uint16_t timeBeforeSendingReqFwData0s = 0;
    constexpr std::array<uint8_t, hdrSize + sizeof(pldm_update_component_resp)>
        updateComponentResponse2{0x00, 0x00, 0x00, 0x00, 0x01, 0x09,
                                 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
    auto responseMsg2 =
        reinterpret_cast<const pldm_msg*>(updateComponentResponse2.data());
    rc = decode_update_component_resp(
        responseMsg2, sizeof(pldm_update_component_resp), &completionCode,
        &compCompatibilityResp, &compCompatibilityRespCode,
        &updateOptionFlagsEnabled, &timeBeforeReqFWData);

    EXPECT_EQ(rc, PLDM_SUCCESS);
    EXPECT_EQ(completionCode, PLDM_SUCCESS);
    EXPECT_EQ(compCompatibilityResp, PLDM_CCR_COMP_CANNOT_BE_UPDATED);
    EXPECT_EQ(compCompatibilityRespCode, PLDM_CCRC_COMP_INFO_NO_MATCH);
    EXPECT_EQ(updateOptionFlagsEnabled.value, noFlags);
    EXPECT_EQ(timeBeforeReqFWData, timeBeforeSendingReqFwData0s);

    constexpr std::array<uint8_t, hdrSize + sizeof(pldm_update_component_resp)>
        updateComponentResponse3{0x00, 0x00, 0x00, 0x80};
    auto responseMsg3 =
        reinterpret_cast<const pldm_msg*>(updateComponentResponse3.data());

    rc = decode_update_component_resp(
        responseMsg3, sizeof(pldm_update_component_resp), &completionCode,
        &compCompatibilityResp, &compCompatibilityRespCode,
        &updateOptionFlagsEnabled, &timeBeforeReqFWData);

    EXPECT_EQ(rc, PLDM_SUCCESS);
    EXPECT_EQ(completionCode, PLDM_FWUP_NOT_IN_UPDATE_MODE);
}

TEST(UpdateComponent, errorPathDecodeResponse)
{
    constexpr std::array<uint8_t,
                         hdrSize + sizeof(pldm_update_component_resp) - 1>
        updateComponentResponse1{0x00, 0x00, 0x00, 0x00, 0x01, 0x09,
                                 0x00, 0x00, 0x00, 0x00, 0x00};
    auto responseMsg1 =
        reinterpret_cast<const pldm_msg*>(updateComponentResponse1.data());

    uint8_t completionCode = 0;
    uint8_t compCompatibilityResp = 0;
    uint8_t compCompatibilityRespCode = 0;
    bitfield32_t updateOptionFlagsEnabled{};
    uint16_t timeBeforeReqFWData = 0;

    auto rc = decode_update_component_resp(
        nullptr, sizeof(pldm_update_component_resp) - 1, &completionCode,
        &compCompatibilityResp, &compCompatibilityRespCode,
        &updateOptionFlagsEnabled, &timeBeforeReqFWData);
    EXPECT_EQ(rc, PLDM_ERROR_INVALID_DATA);

    rc = decode_update_component_resp(
        responseMsg1, sizeof(pldm_update_component_resp) - 1, nullptr,
        &compCompatibilityResp, &compCompatibilityRespCode,
        &updateOptionFlagsEnabled, &timeBeforeReqFWData);
    EXPECT_EQ(rc, PLDM_ERROR_INVALID_DATA);

    rc = decode_update_component_resp(
        responseMsg1, sizeof(pldm_update_component_resp) - 1, &completionCode,
        nullptr, &compCompatibilityRespCode, &updateOptionFlagsEnabled,
        &timeBeforeReqFWData);
    EXPECT_EQ(rc, PLDM_ERROR_INVALID_DATA);

    rc = decode_update_component_resp(
        responseMsg1, sizeof(pldm_update_component_resp) - 1, &completionCode,
        &compCompatibilityResp, nullptr, &updateOptionFlagsEnabled,
        &timeBeforeReqFWData);
    EXPECT_EQ(rc, PLDM_ERROR_INVALID_DATA);

    rc = decode_update_component_resp(
        responseMsg1, sizeof(pldm_update_component_resp) - 1, &completionCode,
        &compCompatibilityResp, &compCompatibilityRespCode, nullptr,
        &timeBeforeReqFWData);
    EXPECT_EQ(rc, PLDM_ERROR_INVALID_DATA);

    rc = decode_update_component_resp(
        responseMsg1, sizeof(pldm_update_component_resp) - 1, &completionCode,
        &compCompatibilityResp, &compCompatibilityRespCode,
        &updateOptionFlagsEnabled, nullptr);
    EXPECT_EQ(rc, PLDM_ERROR_INVALID_DATA);

    rc = decode_update_component_resp(
        responseMsg1, 0, &completionCode, &compCompatibilityResp,
        &compCompatibilityRespCode, &updateOptionFlagsEnabled,
        &timeBeforeReqFWData);
    EXPECT_EQ(rc, PLDM_ERROR_INVALID_DATA);

    rc = decode_update_component_resp(
        responseMsg1, sizeof(pldm_update_component_resp) - 1, &completionCode,
        &compCompatibilityResp, &compCompatibilityRespCode,
        &updateOptionFlagsEnabled, &timeBeforeReqFWData);
    EXPECT_EQ(rc, PLDM_ERROR_INVALID_LENGTH);

    constexpr std::array<uint8_t, hdrSize + sizeof(pldm_update_component_resp)>
        updateComponentResponse2{0x00, 0x00, 0x00, 0x00, 0x02, 0x00,
                                 0x01, 0x00, 0x00, 0x00, 0x64, 0x00};
    auto responseMsg2 =
        reinterpret_cast<const pldm_msg*>(updateComponentResponse2.data());
    rc = decode_update_component_resp(
        responseMsg2, sizeof(pldm_update_component_resp), &completionCode,
        &compCompatibilityResp, &compCompatibilityRespCode,
        &updateOptionFlagsEnabled, &timeBeforeReqFWData);
    EXPECT_EQ(rc, PLDM_ERROR_INVALID_DATA);

    constexpr std::array<uint8_t, hdrSize + sizeof(pldm_update_component_resp)>
        updateComponentResponse3{0x00, 0x00, 0x00, 0x00, 0x00, 0x0C,
                                 0x01, 0x00, 0x00, 0x00, 0x64, 0x00};
    auto responseMsg3 =
        reinterpret_cast<const pldm_msg*>(updateComponentResponse3.data());
    rc = decode_update_component_resp(
        responseMsg3, sizeof(pldm_update_component_resp), &completionCode,
        &compCompatibilityResp, &compCompatibilityRespCode,
        &updateOptionFlagsEnabled, &timeBeforeReqFWData);
    EXPECT_EQ(rc, PLDM_ERROR_INVALID_DATA);

    constexpr std::array<uint8_t, hdrSize + sizeof(pldm_update_component_resp)>
        updateComponentResponse4{0x00, 0x00, 0x00, 0x00, 0x00, 0xF0,
                                 0x01, 0x00, 0x00, 0x00, 0x64, 0x00};
    auto responseMsg4 =
        reinterpret_cast<const pldm_msg*>(updateComponentResponse4.data());
    rc = decode_update_component_resp(
        responseMsg4, sizeof(pldm_update_component_resp), &completionCode,
        &compCompatibilityResp, &compCompatibilityRespCode,
        &updateOptionFlagsEnabled, &timeBeforeReqFWData);
    EXPECT_EQ(rc, PLDM_ERROR_INVALID_DATA);
}

TEST(RequestFirmwareData, goodPathDecodeRequest)
{
    constexpr uint32_t offset = 300;
    constexpr uint32_t length = 255;
    constexpr std::array<uint8_t,
                         hdrSize + sizeof(pldm_request_firmware_data_req)>
        reqFWDataReq{0x00, 0x00, 0x00, 0x2C, 0x01, 0x00,
                     0x00, 0xFF, 0x00, 0x00, 0x00};
    auto requestMsg = reinterpret_cast<const pldm_msg*>(reqFWDataReq.data());

    uint32_t outOffset = 0;
    uint32_t outLength = 0;
    auto rc = decode_request_firmware_data_req(
        requestMsg, sizeof(pldm_request_firmware_data_req), &outOffset,
        &outLength);

    EXPECT_EQ(rc, PLDM_SUCCESS);
    EXPECT_EQ(outOffset, offset);
    EXPECT_EQ(outLength, length);
}

TEST(RequestFirmwareData, errorPathDecodeRequest)
{
    constexpr std::array<uint8_t,
                         hdrSize + sizeof(pldm_request_firmware_data_req)>
        reqFWDataReq{0x00, 0x00, 0x00, 0x2C, 0x01, 0x00,
                     0x00, 0x1F, 0x00, 0x00, 0x00};
    auto requestMsg = reinterpret_cast<const pldm_msg*>(reqFWDataReq.data());

    uint32_t outOffset = 0;
    uint32_t outLength = 0;
    auto rc = decode_request_firmware_data_req(
        nullptr, sizeof(pldm_request_firmware_data_req), &outOffset,
        &outLength);
    EXPECT_EQ(rc, PLDM_ERROR_INVALID_DATA);

    rc = decode_request_firmware_data_req(
        requestMsg, sizeof(pldm_request_firmware_data_req), nullptr,
        &outLength);
    EXPECT_EQ(rc, PLDM_ERROR_INVALID_DATA);

    rc = decode_request_firmware_data_req(
        requestMsg, sizeof(pldm_request_firmware_data_req), &outOffset,
        nullptr);
    EXPECT_EQ(rc, PLDM_ERROR_INVALID_DATA);

    rc = decode_request_firmware_data_req(
        requestMsg, sizeof(pldm_request_firmware_data_req) - 1, &outOffset,
        &outLength);
    EXPECT_EQ(rc, PLDM_ERROR_INVALID_LENGTH);

    rc = decode_request_firmware_data_req(
        requestMsg, sizeof(pldm_request_firmware_data_req), &outOffset,
        &outLength);
    EXPECT_EQ(rc, PLDM_FWUP_INVALID_TRANSFER_LENGTH);
}

TEST(RequestFirmwareData, goodPathEncodeResponse)
{
    constexpr uint8_t instanceId = 3;
    constexpr uint8_t completionCode = PLDM_SUCCESS;
    constexpr std::array<uint8_t, hdrSize + sizeof(completionCode) +
                                      PLDM_FWUP_BASELINE_TRANSFER_SIZE>
        outReqFwDataResponse1{0x03, 0x05, 0x15, 0x00, 0x01, 0x02, 0x03, 0x04,
                              0x05, 0x06, 0x07, 0x08, 0x09, 0x0A, 0x0B, 0x0C,
                              0x0D, 0x0E, 0x0F, 0x10, 0x11, 0x12, 0x13, 0x14,
                              0x15, 0x16, 0x17, 0x18, 0x19, 0x1A, 0x1B, 0x1C,
                              0x1D, 0x1E, 0x1F, 0x20};
    std::array<uint8_t, hdrSize + sizeof(completionCode) +
                            PLDM_FWUP_BASELINE_TRANSFER_SIZE>
        reqFwDataResponse1{0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x03, 0x04,
                           0x05, 0x06, 0x07, 0x08, 0x09, 0x0A, 0x0B, 0x0C,
                           0x0D, 0x0E, 0x0F, 0x10, 0x11, 0x12, 0x13, 0x14,
                           0x15, 0x16, 0x17, 0x18, 0x19, 0x1A, 0x1B, 0x1C,
                           0x1D, 0x1E, 0x1F, 0x20};
    auto responseMsg1 = reinterpret_cast<pldm_msg*>(reqFwDataResponse1.data());
    auto rc = encode_request_firmware_data_resp(
        instanceId, completionCode, responseMsg1,
        sizeof(completionCode) + PLDM_FWUP_BASELINE_TRANSFER_SIZE);
    EXPECT_EQ(rc, PLDM_SUCCESS);
    EXPECT_EQ(reqFwDataResponse1, outReqFwDataResponse1);

    constexpr std::array<uint8_t, hdrSize + sizeof(completionCode)>
        outReqFwDataResponse2{0x03, 0x05, 0x15, 0x82};
    std::array<uint8_t, hdrSize + sizeof(completionCode)> reqFwDataResponse2{
        0x00, 0x00, 0x00, 0x00};
    auto responseMsg2 = reinterpret_cast<pldm_msg*>(reqFwDataResponse2.data());
    rc = encode_request_firmware_data_resp(
        instanceId, PLDM_FWUP_DATA_OUT_OF_RANGE, responseMsg2,
        sizeof(completionCode));
    EXPECT_EQ(rc, PLDM_SUCCESS);
    EXPECT_EQ(reqFwDataResponse2, outReqFwDataResponse2);
}

TEST(RequestFirmwareData, errorPathEncodeResponse)
{
    std::array<uint8_t, hdrSize> reqFwDataResponse{0x00, 0x00, 0x00};
    auto responseMsg = reinterpret_cast<pldm_msg*>(reqFwDataResponse.data());
    auto rc = encode_request_firmware_data_resp(0, PLDM_SUCCESS, nullptr, 0);
    EXPECT_EQ(rc, PLDM_ERROR_INVALID_DATA);

    rc = encode_request_firmware_data_resp(0, PLDM_SUCCESS, responseMsg, 0);
    EXPECT_EQ(rc, PLDM_ERROR_INVALID_DATA);
}

TEST(TransferComplete, goodPathDecodeRequest)
{
    constexpr uint8_t transferResult = PLDM_FWUP_TRANSFER_SUCCESS;
    constexpr std::array<uint8_t, hdrSize + sizeof(transferResult)>
        transferCompleteReq1{0x00, 0x00, 0x00, 0x00};
    auto requestMsg1 =
        reinterpret_cast<const pldm_msg*>(transferCompleteReq1.data());
    uint8_t outTransferResult = 0;

    auto rc = decode_transfer_complete_req(requestMsg1, sizeof(transferResult),
                                           &outTransferResult);
    EXPECT_EQ(rc, PLDM_SUCCESS);
    EXPECT_EQ(outTransferResult, transferResult);

    constexpr std::array<uint8_t, hdrSize + sizeof(transferResult)>
        transferCompleteReq2{0x00, 0x00, 0x00, 0x02};
    auto requestMsg2 =
        reinterpret_cast<const pldm_msg*>(transferCompleteReq2.data());
    rc = decode_transfer_complete_req(requestMsg2, sizeof(transferResult),
                                      &outTransferResult);
    EXPECT_EQ(rc, PLDM_SUCCESS);
    EXPECT_EQ(outTransferResult, PLDM_FWUP_TRANSFER_ERROR_IMAGE_CORRUPT);
}

TEST(TransferComplete, errorPathDecodeRequest)
{
    constexpr std::array<uint8_t, hdrSize> transferCompleteReq{0x00, 0x00,
                                                               0x00};
    auto requestMsg =
        reinterpret_cast<const pldm_msg*>(transferCompleteReq.data());
    uint8_t outTransferResult = 0;

    auto rc = decode_transfer_complete_req(nullptr, 0, &outTransferResult);
    EXPECT_EQ(rc, PLDM_ERROR_INVALID_DATA);

    rc = decode_transfer_complete_req(requestMsg, 0, nullptr);
    EXPECT_EQ(rc, PLDM_ERROR_INVALID_DATA);

    rc = decode_transfer_complete_req(requestMsg, 0, &outTransferResult);
    EXPECT_EQ(rc, PLDM_ERROR_INVALID_LENGTH);
}

TEST(TransferComplete, goodPathEncodeResponse)
{
    constexpr uint8_t instanceId = 4;
    constexpr uint8_t completionCode = PLDM_SUCCESS;
    constexpr std::array<uint8_t, hdrSize + sizeof(completionCode)>
        outTransferCompleteResponse1{0x04, 0x05, 0x16, 0x00};
    std::array<uint8_t, hdrSize + sizeof(completionCode)>
        transferCompleteResponse1{0x00, 0x00, 0x00, 0x00};
    auto responseMsg1 =
        reinterpret_cast<pldm_msg*>(transferCompleteResponse1.data());
    auto rc = encode_transfer_complete_resp(
        instanceId, completionCode, responseMsg1, sizeof(completionCode));
    EXPECT_EQ(rc, PLDM_SUCCESS);
    EXPECT_EQ(transferCompleteResponse1, outTransferCompleteResponse1);

    constexpr std::array<uint8_t, hdrSize + sizeof(completionCode)>
        outTransferCompleteResponse2{0x04, 0x05, 0x16, 0x88};
    std::array<uint8_t, hdrSize + sizeof(completionCode)>
        transferCompleteResponse2{0x00, 0x00, 0x00, 0x00};
    auto responseMsg2 =
        reinterpret_cast<pldm_msg*>(transferCompleteResponse2.data());
    rc = encode_transfer_complete_resp(instanceId,
                                       PLDM_FWUP_COMMAND_NOT_EXPECTED,
                                       responseMsg2, sizeof(completionCode));
    EXPECT_EQ(rc, PLDM_SUCCESS);
    EXPECT_EQ(transferCompleteResponse2, outTransferCompleteResponse2);
}

TEST(TransferComplete, errorPathEncodeResponse)
{
    std::array<uint8_t, hdrSize> transferCompleteResponse{0x00, 0x00, 0x00};
    auto responseMsg =
        reinterpret_cast<pldm_msg*>(transferCompleteResponse.data());
    auto rc = encode_transfer_complete_resp(0, PLDM_SUCCESS, nullptr, 0);
    EXPECT_EQ(rc, PLDM_ERROR_INVALID_DATA);

    rc = encode_transfer_complete_resp(0, PLDM_SUCCESS, responseMsg, 0);
    EXPECT_EQ(rc, PLDM_ERROR_INVALID_LENGTH);
}

TEST(VerifyComplete, goodPathDecodeRequest)
{
    constexpr uint8_t verifyResult = PLDM_FWUP_VERIFY_SUCCESS;
    constexpr std::array<uint8_t, hdrSize + sizeof(verifyResult)>
        verifyCompleteReq1{0x00, 0x00, 0x00, 0x00};
    auto requestMsg1 =
        reinterpret_cast<const pldm_msg*>(verifyCompleteReq1.data());
    uint8_t outVerifyResult = 0;

    auto rc = decode_verify_complete_req(requestMsg1, sizeof(verifyResult),
                                         &outVerifyResult);
    EXPECT_EQ(rc, PLDM_SUCCESS);
    EXPECT_EQ(outVerifyResult, verifyResult);

    constexpr std::array<uint8_t, hdrSize + sizeof(verifyResult)>
        verifyCompleteReq2{0x00, 0x00, 0x00, 0x03};
    auto requestMsg2 =
        reinterpret_cast<const pldm_msg*>(verifyCompleteReq2.data());
    rc = decode_verify_complete_req(requestMsg2, sizeof(verifyResult),
                                    &outVerifyResult);
    EXPECT_EQ(rc, PLDM_SUCCESS);
    EXPECT_EQ(outVerifyResult, PLDM_FWUP_VERIFY_FAILED_FD_SECURITY_CHECKS);
}

TEST(VerifyComplete, errorPathDecodeRequest)
{
    constexpr std::array<uint8_t, hdrSize> verifyCompleteReq{0x00, 0x00, 0x00};
    auto requestMsg =
        reinterpret_cast<const pldm_msg*>(verifyCompleteReq.data());
    uint8_t outVerifyResult = 0;

    auto rc = decode_verify_complete_req(nullptr, 0, &outVerifyResult);
    EXPECT_EQ(rc, PLDM_ERROR_INVALID_DATA);

    rc = decode_verify_complete_req(requestMsg, 0, nullptr);
    EXPECT_EQ(rc, PLDM_ERROR_INVALID_DATA);

    rc = decode_verify_complete_req(requestMsg, 0, &outVerifyResult);
    EXPECT_EQ(rc, PLDM_ERROR_INVALID_LENGTH);
}

TEST(VerifyComplete, goodPathEncodeResponse)
{
    constexpr uint8_t instanceId = 5;
    constexpr uint8_t completionCode = PLDM_SUCCESS;
    constexpr std::array<uint8_t, hdrSize + sizeof(completionCode)>
        outVerifyCompleteResponse1{0x05, 0x05, 0x17, 0x00};
    std::array<uint8_t, hdrSize + sizeof(completionCode)>
        verifyCompleteResponse1{0x00, 0x00, 0x00, 0x00};
    auto responseMsg1 =
        reinterpret_cast<pldm_msg*>(verifyCompleteResponse1.data());
    auto rc = encode_verify_complete_resp(instanceId, completionCode,
                                          responseMsg1, sizeof(completionCode));
    EXPECT_EQ(rc, PLDM_SUCCESS);
    EXPECT_EQ(verifyCompleteResponse1, outVerifyCompleteResponse1);

    constexpr std::array<uint8_t, hdrSize + sizeof(completionCode)>
        outVerifyCompleteResponse2{0x05, 0x05, 0x17, 0x88};
    std::array<uint8_t, hdrSize + sizeof(completionCode)>
        verifyCompleteResponse2{0x00, 0x00, 0x00, 0x00};
    auto responseMsg2 =
        reinterpret_cast<pldm_msg*>(verifyCompleteResponse2.data());
    rc = encode_verify_complete_resp(instanceId, PLDM_FWUP_COMMAND_NOT_EXPECTED,
                                     responseMsg2, sizeof(completionCode));
    EXPECT_EQ(rc, PLDM_SUCCESS);
    EXPECT_EQ(verifyCompleteResponse2, outVerifyCompleteResponse2);
}

TEST(VerifyComplete, errorPathEncodeResponse)
{
    std::array<uint8_t, hdrSize> verifyCompleteResponse{0x00, 0x00, 0x00};
    auto responseMsg =
        reinterpret_cast<pldm_msg*>(verifyCompleteResponse.data());
    auto rc = encode_verify_complete_resp(0, PLDM_SUCCESS, nullptr, 0);
    EXPECT_EQ(rc, PLDM_ERROR_INVALID_DATA);

    rc = encode_verify_complete_resp(0, PLDM_SUCCESS, responseMsg, 0);
    EXPECT_EQ(rc, PLDM_ERROR_INVALID_LENGTH);
}

TEST(ApplyComplete, goodPathDecodeRequest)
{
    constexpr uint8_t applyResult1 =
        PLDM_FWUP_APPLY_SUCCESS_WITH_ACTIVATION_METHOD;
    // DC power cycle [Bit position 4] & AC power cycle [Bit position 5]
    constexpr std::bitset<16> compActivationModification1{0x30};
    constexpr std::array<uint8_t, hdrSize + sizeof(pldm_apply_complete_req)>
        applyCompleteReq1{0x00, 0x00, 0x00, 0x01, 0x30, 0x00};
    auto requestMsg1 =
        reinterpret_cast<const pldm_msg*>(applyCompleteReq1.data());
    uint8_t outApplyResult = 0;
    bitfield16_t outCompActivationModification{};
    auto rc = decode_apply_complete_req(
        requestMsg1, sizeof(pldm_apply_complete_req), &outApplyResult,
        &outCompActivationModification);
    EXPECT_EQ(rc, PLDM_SUCCESS);
    EXPECT_EQ(outApplyResult, applyResult1);
    EXPECT_EQ(outCompActivationModification.value, compActivationModification1);

    constexpr uint8_t applyResult2 = PLDM_FWUP_APPLY_SUCCESS;
    constexpr std::bitset<16> compActivationModification2{};
    constexpr std::array<uint8_t, hdrSize + sizeof(pldm_apply_complete_req)>
        applyCompleteReq2{0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
    auto requestMsg2 =
        reinterpret_cast<const pldm_msg*>(applyCompleteReq2.data());
    rc = decode_apply_complete_req(requestMsg2, sizeof(pldm_apply_complete_req),
                                   &outApplyResult,
                                   &outCompActivationModification);
    EXPECT_EQ(rc, PLDM_SUCCESS);
    EXPECT_EQ(outApplyResult, applyResult2);
    EXPECT_EQ(outCompActivationModification.value, compActivationModification2);
}

TEST(ApplyComplete, errorPathDecodeRequest)
{
    constexpr std::array<uint8_t, hdrSize> applyCompleteReq1{0x00, 0x00, 0x00};
    auto requestMsg1 =
        reinterpret_cast<const pldm_msg*>(applyCompleteReq1.data());
    uint8_t outApplyResult = 0;
    bitfield16_t outCompActivationModification{};

    auto rc = decode_apply_complete_req(
        nullptr, sizeof(pldm_apply_complete_req), &outApplyResult,
        &outCompActivationModification);
    EXPECT_EQ(rc, PLDM_ERROR_INVALID_DATA);

    rc = decode_apply_complete_req(requestMsg1, sizeof(pldm_apply_complete_req),
                                   nullptr, &outCompActivationModification);
    EXPECT_EQ(rc, PLDM_ERROR_INVALID_DATA);

    rc = decode_apply_complete_req(requestMsg1, sizeof(pldm_apply_complete_req),
                                   &outApplyResult, nullptr);
    EXPECT_EQ(rc, PLDM_ERROR_INVALID_DATA);

    rc = decode_apply_complete_req(requestMsg1, 0, &outApplyResult,
                                   &outCompActivationModification);
    EXPECT_EQ(rc, PLDM_ERROR_INVALID_LENGTH);

    constexpr std::array<uint8_t, hdrSize + sizeof(pldm_apply_complete_req)>
        applyCompleteReq2{0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
    auto requestMsg2 =
        reinterpret_cast<const pldm_msg*>(applyCompleteReq2.data());
    rc = decode_apply_complete_req(requestMsg2, sizeof(pldm_apply_complete_req),
                                   &outApplyResult,
                                   &outCompActivationModification);
    EXPECT_EQ(rc, PLDM_ERROR_INVALID_DATA);
}

TEST(ApplyComplete, goodPathEncodeResponse)
{
    constexpr uint8_t instanceId = 6;
    constexpr uint8_t completionCode = PLDM_SUCCESS;
    constexpr std::array<uint8_t, hdrSize + sizeof(completionCode)>
        outApplyCompleteResponse1{0x06, 0x05, 0x18, 0x00};
    std::array<uint8_t, hdrSize + sizeof(completionCode)>
        applyCompleteResponse1{0x00, 0x00, 0x00, 0x00};
    auto responseMsg1 =
        reinterpret_cast<pldm_msg*>(applyCompleteResponse1.data());
    auto rc = encode_apply_complete_resp(instanceId, completionCode,
                                         responseMsg1, sizeof(completionCode));
    EXPECT_EQ(rc, PLDM_SUCCESS);
    EXPECT_EQ(applyCompleteResponse1, outApplyCompleteResponse1);

    constexpr std::array<uint8_t, hdrSize + sizeof(completionCode)>
        outApplyCompleteResponse2{0x06, 0x05, 0x18, 0x88};
    std::array<uint8_t, hdrSize + sizeof(completionCode)>
        applyCompleteResponse2{0x00, 0x00, 0x00, 0x00};
    auto responseMsg2 =
        reinterpret_cast<pldm_msg*>(applyCompleteResponse2.data());
    rc = encode_apply_complete_resp(instanceId, PLDM_FWUP_COMMAND_NOT_EXPECTED,
                                    responseMsg2, sizeof(completionCode));
    EXPECT_EQ(rc, PLDM_SUCCESS);
    EXPECT_EQ(applyCompleteResponse2, outApplyCompleteResponse2);
}

TEST(ApplyComplete, errorPathEncodeResponse)
{
    std::array<uint8_t, hdrSize> applyCompleteResponse{0x00, 0x00, 0x00};
    auto responseMsg =
        reinterpret_cast<pldm_msg*>(applyCompleteResponse.data());
    auto rc = encode_apply_complete_resp(0, PLDM_SUCCESS, nullptr, 0);
    EXPECT_EQ(rc, PLDM_ERROR_INVALID_DATA);

    rc = encode_apply_complete_resp(0, PLDM_SUCCESS, responseMsg, 0);
    EXPECT_EQ(rc, PLDM_ERROR_INVALID_LENGTH);
}

TEST(ActivateFirmware, goodPathEncodeRequest)
{
    constexpr uint8_t instanceId = 7;

    std::array<uint8_t, hdrSize + sizeof(pldm_activate_firmware_req)> request{};
    auto requestMsg = reinterpret_cast<pldm_msg*>(request.data());

    auto rc = encode_activate_firmware_req(
        instanceId, PLDM_ACTIVATE_SELF_CONTAINED_COMPONENTS, requestMsg,
        sizeof(pldm_activate_firmware_req));
    EXPECT_EQ(rc, PLDM_SUCCESS);

    std::array<uint8_t, hdrSize + sizeof(pldm_activate_firmware_req)>
        outRequest{0x87, 0x05, 0x1A, 0x01};
    EXPECT_EQ(request, outRequest);
}

TEST(ActivateFirmware, errorPathEncodeRequest)
{
    std::array<uint8_t, hdrSize + sizeof(pldm_activate_firmware_req)> request{};
    auto requestMsg = reinterpret_cast<pldm_msg*>(request.data());

    auto rc = encode_activate_firmware_req(
        0, PLDM_ACTIVATE_SELF_CONTAINED_COMPONENTS, nullptr,
        sizeof(pldm_activate_firmware_req));
    EXPECT_EQ(rc, PLDM_ERROR_INVALID_DATA);

    rc = encode_activate_firmware_req(
        0, PLDM_ACTIVATE_SELF_CONTAINED_COMPONENTS, requestMsg, 0);
    EXPECT_EQ(rc, PLDM_ERROR_INVALID_LENGTH);

    rc = encode_activate_firmware_req(0, 2, requestMsg,
                                      sizeof(pldm_activate_firmware_req));
    EXPECT_EQ(rc, PLDM_ERROR_INVALID_DATA);
}

TEST(ActivateFirmware, goodPathDecodeResponse)
{
    constexpr uint16_t estimatedTimeForActivation100s = 100;
    constexpr std::array<uint8_t, hdrSize + sizeof(pldm_activate_firmware_resp)>
        activateFirmwareResponse1{0x00, 0x00, 0x00, 0x00, 0x64, 0x00};
    auto responseMsg1 =
        reinterpret_cast<const pldm_msg*>(activateFirmwareResponse1.data());

    uint8_t completionCode = 0;
    uint16_t estimatedTimeForActivation = 0;

    auto rc = decode_activate_firmware_resp(
        responseMsg1, sizeof(pldm_activate_firmware_resp), &completionCode,
        &estimatedTimeForActivation);

    EXPECT_EQ(rc, PLDM_SUCCESS);
    EXPECT_EQ(completionCode, PLDM_SUCCESS);
    EXPECT_EQ(estimatedTimeForActivation, estimatedTimeForActivation100s);

    constexpr std::array<uint8_t, hdrSize + sizeof(completionCode)>
        activateFirmwareResponse2{0x00, 0x00, 0x00, 0x85};
    auto responseMsg2 =
        reinterpret_cast<const pldm_msg*>(activateFirmwareResponse2.data());

    rc = decode_activate_firmware_resp(responseMsg2, sizeof(completionCode),
                                       &completionCode,
                                       &estimatedTimeForActivation);

    EXPECT_EQ(rc, PLDM_SUCCESS);
    EXPECT_EQ(completionCode, PLDM_FWUP_INCOMPLETE_UPDATE);
}

TEST(ActivateFirmware, errorPathDecodeResponse)
{
    constexpr std::array<uint8_t, hdrSize + sizeof(pldm_activate_firmware_resp)>
        activateFirmwareResponse{0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
    auto responseMsg =
        reinterpret_cast<const pldm_msg*>(activateFirmwareResponse.data());

    uint8_t completionCode = 0;
    uint16_t estimatedTimeForActivation = 0;

    auto rc = decode_activate_firmware_resp(
        nullptr, sizeof(pldm_activate_firmware_resp), &completionCode,
        &estimatedTimeForActivation);
    EXPECT_EQ(rc, PLDM_ERROR_INVALID_DATA);

    rc = decode_activate_firmware_resp(responseMsg,
                                       sizeof(pldm_activate_firmware_resp),
                                       nullptr, &estimatedTimeForActivation);
    EXPECT_EQ(rc, PLDM_ERROR_INVALID_DATA);

    rc = decode_activate_firmware_resp(responseMsg,
                                       sizeof(pldm_activate_firmware_resp),
                                       &completionCode, nullptr);
    EXPECT_EQ(rc, PLDM_ERROR_INVALID_DATA);

    rc = decode_activate_firmware_resp(responseMsg, 0, &completionCode,
                                       &estimatedTimeForActivation);
    EXPECT_EQ(rc, PLDM_ERROR_INVALID_DATA);

    rc = decode_activate_firmware_resp(
        responseMsg, sizeof(pldm_activate_firmware_resp) - 1, &completionCode,
        &estimatedTimeForActivation);
    EXPECT_EQ(rc, PLDM_ERROR_INVALID_LENGTH);
}

TEST(GetStatus, goodPathEncodeRequest)
{
    constexpr uint8_t instanceId = 8;
    std::array<uint8_t, hdrSize> request{};
    auto requestMsg = reinterpret_cast<pldm_msg*>(request.data());

    auto rc = encode_get_status_req(instanceId, requestMsg,
                                    PLDM_GET_STATUS_REQ_BYTES);
    EXPECT_EQ(rc, PLDM_SUCCESS);

    constexpr std::array<uint8_t, hdrSize> outRequest{0x88, 0x05, 0x1B};
    EXPECT_EQ(request, outRequest);
}

TEST(GetStatus, errorPathEncodeRequest)
{
    std::array<uint8_t, hdrSize + sizeof(uint8_t)> request{};
    auto requestMsg = reinterpret_cast<pldm_msg*>(request.data());

    auto rc = encode_get_status_req(0, nullptr, PLDM_GET_STATUS_REQ_BYTES);
    EXPECT_EQ(rc, PLDM_ERROR_INVALID_DATA);

    rc = encode_get_status_req(0, requestMsg, PLDM_GET_STATUS_REQ_BYTES + 1);
    EXPECT_EQ(rc, PLDM_ERROR_INVALID_LENGTH);
}

TEST(GetStatus, goodPathDecodeResponse)
{
    constexpr std::bitset<32> updateOptionFlagsEnabled1{0};
    constexpr std::array<uint8_t, hdrSize + sizeof(pldm_get_status_resp)>
        getStatusResponse1{0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x03,
                           0x09, 0x65, 0x05, 0x00, 0x00, 0x00, 0x00};
    auto responseMsg1 =
        reinterpret_cast<const pldm_msg*>(getStatusResponse1.data());

    uint8_t completionCode = 0;
    uint8_t currentState = 0;
    uint8_t previousState = 0;
    uint8_t auxState = 0;
    uint8_t auxStateStatus = 0;
    uint8_t progressPercent = 0;
    uint8_t reasonCode = 0;
    bitfield32_t updateOptionFlagsEnabled{0};

    auto rc = decode_get_status_resp(
        responseMsg1, getStatusResponse1.size() - hdrSize, &completionCode,
        &currentState, &previousState, &auxState, &auxStateStatus,
        &progressPercent, &reasonCode, &updateOptionFlagsEnabled);

    EXPECT_EQ(rc, PLDM_SUCCESS);
    EXPECT_EQ(completionCode, PLDM_SUCCESS);
    EXPECT_EQ(currentState, PLDM_FD_STATE_IDLE);
    EXPECT_EQ(previousState, PLDM_FD_STATE_DOWNLOAD);
    EXPECT_EQ(auxState, PLDM_FD_IDLE_LEARN_COMPONENTS_READ_XFER);
    EXPECT_EQ(auxStateStatus, PLDM_FD_TIMEOUT);
    EXPECT_EQ(progressPercent, PLDM_FWUP_MAX_PROGRESS_PERCENT);
    EXPECT_EQ(reasonCode, PLDM_FD_TIMEOUT_DOWNLOAD);
    EXPECT_EQ(updateOptionFlagsEnabled.value, updateOptionFlagsEnabled1);

    // Bit position 0 - Force update of component – FD will perform a force
    // update of the component.
    constexpr std::bitset<32> updateOptionFlagsEnabled2{1};
    constexpr uint8_t progressPercent2 = 50;
    constexpr std::array<uint8_t, hdrSize + sizeof(pldm_get_status_resp)>
        getStatusResponse2{0x00, 0x00, 0x00, 0x00, 0x04, 0x03, 0x00,
                           0x70, 0x32, 0x05, 0x01, 0x00, 0x00, 0x00};
    auto responseMsg2 =
        reinterpret_cast<const pldm_msg*>(getStatusResponse2.data());

    rc = decode_get_status_resp(
        responseMsg2, getStatusResponse2.size() - hdrSize, &completionCode,
        &currentState, &previousState, &auxState, &auxStateStatus,
        &progressPercent, &reasonCode, &updateOptionFlagsEnabled);

    EXPECT_EQ(rc, PLDM_SUCCESS);
    EXPECT_EQ(completionCode, PLDM_SUCCESS);
    EXPECT_EQ(currentState, PLDM_FD_STATE_VERIFY);
    EXPECT_EQ(previousState, PLDM_FD_STATE_DOWNLOAD);
    EXPECT_EQ(auxState, PLDM_FD_OPERATION_IN_PROGRESS);
    EXPECT_EQ(auxStateStatus, PLDM_FD_VENDOR_DEFINED_STATUS_CODE_START);
    EXPECT_EQ(progressPercent, progressPercent2);
    EXPECT_EQ(reasonCode, PLDM_FD_TIMEOUT_DOWNLOAD);
    EXPECT_EQ(updateOptionFlagsEnabled.value, updateOptionFlagsEnabled2);

    constexpr std::array<uint8_t, hdrSize + sizeof(completionCode)>
        getStatusResponse3{0x00, 0x00, 0x00, 0x04};
    auto responseMsg3 =
        reinterpret_cast<const pldm_msg*>(getStatusResponse3.data());
    rc = decode_get_status_resp(
        responseMsg3, getStatusResponse3.size() - hdrSize, &completionCode,
        &currentState, &previousState, &auxState, &auxStateStatus,
        &progressPercent, &reasonCode, &updateOptionFlagsEnabled);
    EXPECT_EQ(rc, PLDM_SUCCESS);
    EXPECT_EQ(completionCode, PLDM_ERROR_NOT_READY);
}

TEST(GetStatus, errorPathDecodeResponse)
{
    uint8_t completionCode = 0;
    uint8_t currentState = 0;
    uint8_t previousState = 0;
    uint8_t auxState = 0;
    uint8_t auxStateStatus = 0;
    uint8_t progressPercent = 0;
    uint8_t reasonCode = 0;
    bitfield32_t updateOptionFlagsEnabled{0};

    constexpr std::array<uint8_t, hdrSize> getStatusResponse1{0x00, 0x00, 0x00};
    auto responseMsg1 =
        reinterpret_cast<const pldm_msg*>(getStatusResponse1.data());

    auto rc = decode_get_status_resp(
        nullptr, getStatusResponse1.size() - hdrSize, &completionCode,
        &currentState, &previousState, &auxState, &auxStateStatus,
        &progressPercent, &reasonCode, &updateOptionFlagsEnabled);
    EXPECT_EQ(rc, PLDM_ERROR_INVALID_DATA);

    rc = decode_get_status_resp(
        responseMsg1, getStatusResponse1.size() - hdrSize, nullptr,
        &currentState, &previousState, &auxState, &auxStateStatus,
        &progressPercent, &reasonCode, &updateOptionFlagsEnabled);
    EXPECT_EQ(rc, PLDM_ERROR_INVALID_DATA);

    rc = decode_get_status_resp(
        responseMsg1, getStatusResponse1.size() - hdrSize, &completionCode,
        nullptr, &previousState, &auxState, &auxStateStatus, &progressPercent,
        &reasonCode, &updateOptionFlagsEnabled);
    EXPECT_EQ(rc, PLDM_ERROR_INVALID_DATA);

    rc = decode_get_status_resp(
        responseMsg1, getStatusResponse1.size() - hdrSize, &completionCode,
        &currentState, nullptr, &auxState, &auxStateStatus, &progressPercent,
        &reasonCode, &updateOptionFlagsEnabled);
    EXPECT_EQ(rc, PLDM_ERROR_INVALID_DATA);

    rc = decode_get_status_resp(
        responseMsg1, getStatusResponse1.size() - hdrSize, &completionCode,
        &currentState, &previousState, nullptr, &auxStateStatus,
        &progressPercent, &reasonCode, &updateOptionFlagsEnabled);
    EXPECT_EQ(rc, PLDM_ERROR_INVALID_DATA);

    rc = decode_get_status_resp(
        responseMsg1, getStatusResponse1.size() - hdrSize, &completionCode,
        &currentState, &previousState, &auxState, nullptr, &progressPercent,
        &reasonCode, &updateOptionFlagsEnabled);
    EXPECT_EQ(rc, PLDM_ERROR_INVALID_DATA);

    rc = decode_get_status_resp(
        responseMsg1, getStatusResponse1.size() - hdrSize, &completionCode,
        &currentState, &previousState, &auxState, &auxStateStatus, nullptr,
        &reasonCode, &updateOptionFlagsEnabled);
    EXPECT_EQ(rc, PLDM_ERROR_INVALID_DATA);

    rc = decode_get_status_resp(
        responseMsg1, getStatusResponse1.size() - hdrSize, &completionCode,
        &currentState, &previousState, &auxState, &auxStateStatus,
        &progressPercent, nullptr, &updateOptionFlagsEnabled);
    EXPECT_EQ(rc, PLDM_ERROR_INVALID_DATA);

    rc = decode_get_status_resp(
        responseMsg1, getStatusResponse1.size() - hdrSize, &completionCode,
        &currentState, &previousState, &auxState, &auxStateStatus,
        &progressPercent, &reasonCode, nullptr);
    EXPECT_EQ(rc, PLDM_ERROR_INVALID_DATA);

    rc = decode_get_status_resp(
        responseMsg1, getStatusResponse1.size() - hdrSize, &completionCode,
        &currentState, &previousState, &auxState, &auxStateStatus,
        &progressPercent, &reasonCode, &updateOptionFlagsEnabled);
    EXPECT_EQ(rc, PLDM_ERROR_INVALID_DATA);

    constexpr std::array<uint8_t, hdrSize + sizeof(pldm_get_status_resp) - 1>
        getStatusResponse2{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                           0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
    auto responseMsg2 =
        reinterpret_cast<const pldm_msg*>(getStatusResponse2.data());
    rc = decode_get_status_resp(
        responseMsg2, getStatusResponse2.size() - hdrSize, &completionCode,
        &currentState, &previousState, &auxState, &auxStateStatus,
        &progressPercent, &reasonCode, &updateOptionFlagsEnabled);
    EXPECT_EQ(rc, PLDM_ERROR_INVALID_LENGTH);

    constexpr std::array<uint8_t, hdrSize + sizeof(pldm_get_status_resp)>
        getStatusResponse3{0x00, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00,
                           0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
    auto responseMsg3 =
        reinterpret_cast<const pldm_msg*>(getStatusResponse3.data());
    rc = decode_get_status_resp(
        responseMsg3, getStatusResponse3.size() - hdrSize, &completionCode,
        &currentState, &previousState, &auxState, &auxStateStatus,
        &progressPercent, &reasonCode, &updateOptionFlagsEnabled);
    EXPECT_EQ(rc, PLDM_ERROR_INVALID_DATA);

    constexpr std::array<uint8_t, hdrSize + sizeof(pldm_get_status_resp)>
        getStatusResponse4{0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x00,
                           0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
    auto responseMsg4 =
        reinterpret_cast<const pldm_msg*>(getStatusResponse4.data());
    rc = decode_get_status_resp(
        responseMsg4, getStatusResponse4.size() - hdrSize, &completionCode,
        &currentState, &previousState, &auxState, &auxStateStatus,
        &progressPercent, &reasonCode, &updateOptionFlagsEnabled);
    EXPECT_EQ(rc, PLDM_ERROR_INVALID_DATA);

    constexpr std::array<uint8_t, hdrSize + sizeof(pldm_get_status_resp)>
        getStatusResponse5{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04,
                           0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
    auto responseMsg5 =
        reinterpret_cast<const pldm_msg*>(getStatusResponse5.data());
    rc = decode_get_status_resp(
        responseMsg5, getStatusResponse5.size() - hdrSize, &completionCode,
        &currentState, &previousState, &auxState, &auxStateStatus,
        &progressPercent, &reasonCode, &updateOptionFlagsEnabled);
    EXPECT_EQ(rc, PLDM_ERROR_INVALID_DATA);

    constexpr std::array<uint8_t, hdrSize + sizeof(pldm_get_status_resp)>
        getStatusResponse6{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                           0x0B, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
    auto responseMsg6 =
        reinterpret_cast<const pldm_msg*>(getStatusResponse6.data());
    rc = decode_get_status_resp(
        responseMsg6, getStatusResponse6.size() - hdrSize, &completionCode,
        &currentState, &previousState, &auxState, &auxStateStatus,
        &progressPercent, &reasonCode, &updateOptionFlagsEnabled);
    EXPECT_EQ(rc, PLDM_ERROR_INVALID_DATA);

    constexpr std::array<uint8_t, hdrSize + sizeof(pldm_get_status_resp)>
        getStatusResponse7{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                           0x00, 0x66, 0x00, 0x00, 0x00, 0x00, 0x00};
    auto responseMsg7 =
        reinterpret_cast<const pldm_msg*>(getStatusResponse7.data());
    rc = decode_get_status_resp(
        responseMsg7, getStatusResponse7.size() - hdrSize, &completionCode,
        &currentState, &previousState, &auxState, &auxStateStatus,
        &progressPercent, &reasonCode, &updateOptionFlagsEnabled);
    EXPECT_EQ(rc, PLDM_ERROR_INVALID_DATA);

    constexpr std::array<uint8_t, hdrSize + sizeof(pldm_get_status_resp)>
        getStatusResponse8{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                           0x00, 0x00, 0xC7, 0x00, 0x00, 0x00, 0x00};
    auto responseMsg8 =
        reinterpret_cast<const pldm_msg*>(getStatusResponse8.data());
    rc = decode_get_status_resp(
        responseMsg8, getStatusResponse8.size() - hdrSize, &completionCode,
        &currentState, &previousState, &auxState, &auxStateStatus,
        &progressPercent, &reasonCode, &updateOptionFlagsEnabled);
    EXPECT_EQ(rc, PLDM_ERROR_INVALID_DATA);

    // AuxState is not PLDM_FD_IDLE_LEARN_COMPONENTS_READ_XFER when the state is
    // IDLE
    constexpr std::array<uint8_t, hdrSize + sizeof(pldm_get_status_resp)>
        getStatusResponse9{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
                           0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
    auto responseMsg9 =
        reinterpret_cast<const pldm_msg*>(getStatusResponse9.data());
    rc = decode_get_status_resp(
        responseMsg9, getStatusResponse9.size() - hdrSize, &completionCode,
        &currentState, &previousState, &auxState, &auxStateStatus,
        &progressPercent, &reasonCode, &updateOptionFlagsEnabled);
    EXPECT_EQ(rc, PLDM_ERROR_INVALID_DATA);
}

TEST(CancelUpdateComponent, goodPathEncodeRequest)
{
    constexpr uint8_t instanceId = 9;
    std::array<uint8_t, hdrSize> request{};
    auto requestMsg = reinterpret_cast<pldm_msg*>(request.data());

    auto rc = encode_cancel_update_component_req(
        instanceId, requestMsg, PLDM_CANCEL_UPDATE_COMPONENT_REQ_BYTES);
    EXPECT_EQ(rc, PLDM_SUCCESS);

    constexpr std::array<uint8_t, hdrSize> outRequest{0x89, 0x05, 0x1C};
    EXPECT_EQ(request, outRequest);
}

TEST(CancelUpdateComponent, errorPathEncodeRequest)
{
    std::array<uint8_t, hdrSize + sizeof(uint8_t)> request{};
    auto requestMsg = reinterpret_cast<pldm_msg*>(request.data());

    auto rc = encode_cancel_update_component_req(
        0, nullptr, PLDM_CANCEL_UPDATE_COMPONENT_REQ_BYTES);
    EXPECT_EQ(rc, PLDM_ERROR_INVALID_DATA);

    rc = encode_cancel_update_component_req(
        0, requestMsg, PLDM_CANCEL_UPDATE_COMPONENT_REQ_BYTES + 1);
    EXPECT_EQ(rc, PLDM_ERROR_INVALID_LENGTH);
}

TEST(CancelUpdateComponent, testGoodDecodeResponse)
{
    uint8_t completionCode = 0;
    constexpr std::array<uint8_t, hdrSize + sizeof(completionCode)>
        cancelUpdateComponentResponse1{0x00, 0x00, 0x00, 0x00};
    auto responseMsg1 = reinterpret_cast<const pldm_msg*>(
        cancelUpdateComponentResponse1.data());
    auto rc = decode_cancel_update_component_resp(
        responseMsg1, cancelUpdateComponentResponse1.size() - hdrSize,
        &completionCode);
    EXPECT_EQ(rc, PLDM_SUCCESS);
    EXPECT_EQ(completionCode, PLDM_SUCCESS);

    constexpr std::array<uint8_t, hdrSize + sizeof(completionCode)>
        cancelUpdateComponentResponse2{0x00, 0x00, 0x00, 0x86};
    auto responseMsg2 = reinterpret_cast<const pldm_msg*>(
        cancelUpdateComponentResponse2.data());
    rc = decode_cancel_update_component_resp(
        responseMsg2, cancelUpdateComponentResponse2.size() - hdrSize,
        &completionCode);
    EXPECT_EQ(rc, PLDM_SUCCESS);
    EXPECT_EQ(completionCode, PLDM_FWUP_BUSY_IN_BACKGROUND);
}

TEST(CancelUpdateComponent, testBadDecodeResponse)
{
    uint8_t completionCode = 0;
    constexpr std::array<uint8_t, hdrSize> cancelUpdateComponentResponse{
        0x00, 0x00, 0x00};
    auto responseMsg =
        reinterpret_cast<const pldm_msg*>(cancelUpdateComponentResponse.data());

    auto rc = decode_cancel_update_component_resp(
        nullptr, cancelUpdateComponentResponse.size() - hdrSize,
        &completionCode);
    EXPECT_EQ(rc, PLDM_ERROR_INVALID_DATA);

    rc = decode_cancel_update_component_resp(
        responseMsg, cancelUpdateComponentResponse.size() - hdrSize, nullptr);
    EXPECT_EQ(rc, PLDM_ERROR_INVALID_DATA);

    rc = decode_cancel_update_component_resp(
        responseMsg, cancelUpdateComponentResponse.size() - hdrSize,
        &completionCode);
    EXPECT_EQ(rc, PLDM_ERROR_INVALID_LENGTH);
}

TEST(CancelUpdate, goodPathEncodeRequest)
{
    constexpr uint8_t instanceId = 10;
    std::array<uint8_t, hdrSize> request{};
    auto requestMsg = reinterpret_cast<pldm_msg*>(request.data());

    auto rc = encode_cancel_update_req(instanceId, requestMsg,
                                       PLDM_CANCEL_UPDATE_REQ_BYTES);
    EXPECT_EQ(rc, PLDM_SUCCESS);

    constexpr std::array<uint8_t, hdrSize> outRequest{0x8A, 0x05, 0x1D};
    EXPECT_EQ(request, outRequest);
}

TEST(CancelUpdate, errorPathEncodeRequest)
{
    std::array<uint8_t, hdrSize + sizeof(uint8_t)> request{};
    auto requestMsg = reinterpret_cast<pldm_msg*>(request.data());

    auto rc =
        encode_cancel_update_req(0, nullptr, PLDM_CANCEL_UPDATE_REQ_BYTES);
    EXPECT_EQ(rc, PLDM_ERROR_INVALID_DATA);

    rc = encode_cancel_update_req(0, requestMsg,
                                  PLDM_CANCEL_UPDATE_REQ_BYTES + 1);
    EXPECT_EQ(rc, PLDM_ERROR_INVALID_LENGTH);
}

TEST(CancelUpdate, goodPathDecodeResponse)
{
    constexpr std::bitset<64> nonFunctioningComponentBitmap1{0};
    constexpr std::array<uint8_t, hdrSize + sizeof(pldm_cancel_update_resp)>
        cancelUpdateResponse1{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                              0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
    auto responseMsg1 =
        reinterpret_cast<const pldm_msg*>(cancelUpdateResponse1.data());
    uint8_t completionCode = 0;
    bool8_t nonFunctioningComponentIndication = 0;
    bitfield64_t nonFunctioningComponentBitmap{0};
    auto rc = decode_cancel_update_resp(
        responseMsg1, cancelUpdateResponse1.size() - hdrSize, &completionCode,
        &nonFunctioningComponentIndication, &nonFunctioningComponentBitmap);
    EXPECT_EQ(rc, PLDM_SUCCESS);
    EXPECT_EQ(completionCode, PLDM_SUCCESS);
    EXPECT_EQ(nonFunctioningComponentIndication,
              PLDM_FWUP_COMPONENTS_FUNCTIONING);
    EXPECT_EQ(nonFunctioningComponentBitmap.value,
              nonFunctioningComponentBitmap1);

    constexpr std::bitset<64> nonFunctioningComponentBitmap2{0x0101};
    constexpr std::array<uint8_t, hdrSize + sizeof(pldm_cancel_update_resp)>
        cancelUpdateResponse2{0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01,
                              0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
    auto responseMsg2 =
        reinterpret_cast<const pldm_msg*>(cancelUpdateResponse2.data());
    rc = decode_cancel_update_resp(
        responseMsg2, cancelUpdateResponse2.size() - hdrSize, &completionCode,
        &nonFunctioningComponentIndication, &nonFunctioningComponentBitmap);
    EXPECT_EQ(rc, PLDM_SUCCESS);
    EXPECT_EQ(completionCode, PLDM_SUCCESS);
    EXPECT_EQ(nonFunctioningComponentIndication,
              PLDM_FWUP_COMPONENTS_NOT_FUNCTIONING);
    EXPECT_EQ(nonFunctioningComponentBitmap.value,
              nonFunctioningComponentBitmap2);

    constexpr std::array<uint8_t, hdrSize + sizeof(completionCode)>
        cancelUpdateResponse3{0x00, 0x00, 0x00, 0x86};
    auto responseMsg3 =
        reinterpret_cast<const pldm_msg*>(cancelUpdateResponse3.data());
    rc = decode_cancel_update_resp(
        responseMsg3, cancelUpdateResponse3.size() - hdrSize, &completionCode,
        &nonFunctioningComponentIndication, &nonFunctioningComponentBitmap);
    EXPECT_EQ(rc, PLDM_SUCCESS);
    EXPECT_EQ(completionCode, PLDM_FWUP_BUSY_IN_BACKGROUND);
}

TEST(CancelUpdate, errorPathDecodeResponse)
{
    constexpr std::array<uint8_t, hdrSize> cancelUpdateResponse1{0x00, 0x00,
                                                                 0x00};
    auto responseMsg1 =
        reinterpret_cast<const pldm_msg*>(cancelUpdateResponse1.data());
    uint8_t completionCode = 0;
    bool8_t nonFunctioningComponentIndication = 0;
    bitfield64_t nonFunctioningComponentBitmap{0};

    auto rc = decode_cancel_update_resp(
        nullptr, cancelUpdateResponse1.size() - hdrSize, &completionCode,
        &nonFunctioningComponentIndication, &nonFunctioningComponentBitmap);
    EXPECT_EQ(rc, PLDM_ERROR_INVALID_DATA);

    rc = decode_cancel_update_resp(
        responseMsg1, cancelUpdateResponse1.size() - hdrSize, nullptr,
        &nonFunctioningComponentIndication, &nonFunctioningComponentBitmap);
    EXPECT_EQ(rc, PLDM_ERROR_INVALID_DATA);

    rc = decode_cancel_update_resp(
        responseMsg1, cancelUpdateResponse1.size() - hdrSize, &completionCode,
        nullptr, &nonFunctioningComponentBitmap);
    EXPECT_EQ(rc, PLDM_ERROR_INVALID_DATA);

    rc = decode_cancel_update_resp(
        responseMsg1, cancelUpdateResponse1.size() - hdrSize, &completionCode,
        &nonFunctioningComponentIndication, nullptr);
    EXPECT_EQ(rc, PLDM_ERROR_INVALID_DATA);

    rc = decode_cancel_update_resp(
        responseMsg1, cancelUpdateResponse1.size() - hdrSize, &completionCode,
        &nonFunctioningComponentIndication, &nonFunctioningComponentBitmap);
    EXPECT_EQ(rc, PLDM_ERROR_INVALID_DATA);

    constexpr std::array<uint8_t, hdrSize + sizeof(completionCode)>
        cancelUpdateResponse2{0x00, 0x00, 0x00, 0x00};
    auto responseMsg2 =
        reinterpret_cast<const pldm_msg*>(cancelUpdateResponse2.data());
    rc = decode_cancel_update_resp(
        responseMsg2, cancelUpdateResponse2.size() - hdrSize, &completionCode,
        &nonFunctioningComponentIndication, &nonFunctioningComponentBitmap);
    EXPECT_EQ(rc, PLDM_ERROR_INVALID_LENGTH);

    constexpr std::array<uint8_t, hdrSize + sizeof(pldm_cancel_update_resp)>
        cancelUpdateResponse3{0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00,
                              0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
    auto responseMsg3 =
        reinterpret_cast<const pldm_msg*>(cancelUpdateResponse3.data());
    rc = decode_cancel_update_resp(
        responseMsg3, cancelUpdateResponse3.size() - hdrSize, &completionCode,
        &nonFunctioningComponentIndication, &nonFunctioningComponentBitmap);
    EXPECT_EQ(rc, PLDM_ERROR_INVALID_DATA);
}
