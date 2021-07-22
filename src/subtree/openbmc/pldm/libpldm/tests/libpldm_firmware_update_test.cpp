#include <bitset>
#include <cstring>

#include "libpldm/base.h"
#include "libpldm/firmware_update.h"

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
    std::array<uint8_t, PLDM_TIMESTAMP104_SIZE> timestamp104{
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
    EXPECT_EQ(true, std::equal(pkgHeader.timestamp104,
                               pkgHeader.timestamp104 + PLDM_TIMESTAMP104_SIZE,
                               timestamp104.begin(), timestamp104.end()));
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
    // ComponentActivationMethods
    // DC Power cycle [Bit position 4] & Self-Contained[Bit position 2]
    constexpr std::bitset<16> compActivationMethod{0x12};
    // CapabilitiesDuringUpdate of the firmware component
    // Component downgrade capability [Bit position 2]
    constexpr std::bitset<32> compCapabilities{0x02};

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
