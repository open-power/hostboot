#ifndef FW_UPDATE_H
#define FW_UPDATE_H

#ifdef __cplusplus
extern "C" {
#endif
#include "base.h"
#include "utils.h"

#define PLDM_FWUP_COMPONENT_BITMAP_MULTIPLE 8
#define PLDM_FWUP_INVALID_COMPONENT_COMPARISON_TIMESTAMP 0xFFFFFFFF
#define PLDM_QUERY_DEVICE_IDENTIFIERS_REQ_BYTES 0
/** @brief Minimum length of device descriptor, 2 bytes for descriptor type,
 *         2 bytes for descriptor length and atleast 1 byte of descriptor data
 */
#define PLDM_FWUP_DEVICE_DESCRIPTOR_MIN_LEN 5
#define PLDM_GET_FIRMWARE_PARAMETERS_REQ_BYTES 0
#define PLDM_FWUP_BASELINE_TRANSFER_SIZE 32
#define PLDM_FWUP_MIN_OUTSTANDING_REQ 1

/** @brief PLDM Firmware update commands
 */
enum pldm_firmware_update_commands {
	PLDM_QUERY_DEVICE_IDENTIFIERS = 0x01,
	PLDM_GET_FIRMWARE_PARAMETERS = 0x02,
	PLDM_REQUEST_UPDATE = 0x10,
	PLDM_PASS_COMPONENT_TABLE = 0x13,
	PLDM_UPDATE_COMPONENT = 0x14
};

/** @brief PLDM Firmware update completion codes
 */
enum pldm_firmware_update_completion_codes {
	PLDM_FWUP_NOT_IN_UPDATE_MODE = 0x80,
	PLDM_FWUP_ALREADY_IN_UPDATE_MODE = 0x81,
	PLDM_FWUP_DATA_OUT_OF_RANGE = 0x82,
	PLDM_FWUP_INVALID_TRANSFER_LENGTH = 0x83,
	PLDM_FWUP_INVALID_STATE_FOR_COMMAND = 0x84,
	PLDM_FWUP_INCOMPLETE_UPDATE = 0x85,
	PLDM_FWUP_BUSY_IN_BACKGROUND = 0x86,
	PLDM_FWUP_CANCEL_PENDING = 0x87,
	PLDM_FWUP_COMMAND_NOT_EXPECTED = 0x87,
	PLDM_FWUP_RETRY_REQUEST_FW_DATA = 0x89,
	PLDM_FWUP_UNABLE_TO_INITIATE_UPDATE = 0x8A,
	PLDM_FWUP_ACTIVATION_NOT_REQUIRED = 0x8B,
	PLDM_FWUP_SELF_CONTAINED_ACTIVATION_NOT_PERMITTED = 0x8C,
	PLDM_FWUP_NO_DEVICE_METADATA = 0x8D,
	PLDM_FWUP_RETRY_REQUEST_UPDATE = 0x8E,
	PLDM_FWUP_NO_PACKAGE_DATA = 0x8F,
	PLDM_FWUP_INVALID_TRANSFER_HANDLE = 0x90,
	PLDM_FWUP_INVALID_TRANSFER_OPERATION_FLAG = 0x91,
	PLDM_FWUP_ACTIVATE_PENDING_IMAGE_NOT_PERMITTED = 0x92,
	PLDM_FWUP_PACKAGE_DATA_ERROR = 0x93
};

/** @brief String type values defined in the PLDM firmware update specification
 */
enum pldm_firmware_update_string_type {
	PLDM_STR_TYPE_UNKNOWN = 0,
	PLDM_STR_TYPE_ASCII = 1,
	PLDM_STR_TYPE_UTF_8 = 2,
	PLDM_STR_TYPE_UTF_16 = 3,
	PLDM_STR_TYPE_UTF_16LE = 4,
	PLDM_STR_TYPE_UTF_16BE = 5
};

/** @brief Descriptor types defined in PLDM firmware update specification
 */
enum pldm_firmware_update_descriptor_types {
	PLDM_FWUP_PCI_VENDOR_ID = 0x0000,
	PLDM_FWUP_IANA_ENTERPRISE_ID = 0x0001,
	PLDM_FWUP_UUID = 0x0002,
	PLDM_FWUP_PNP_VENDOR_ID = 0x0003,
	PLDM_FWUP_ACPI_VENDOR_ID = 0x0004,
	PLDM_FWUP_IEEE_ASSIGNED_COMPANY_ID = 0x0005,
	PLDM_FWUP_SCSI_VENDOR_ID = 0x0006,
	PLDM_FWUP_PCI_DEVICE_ID = 0x0100,
	PLDM_FWUP_PCI_SUBSYSTEM_VENDOR_ID = 0x0101,
	PLDM_FWUP_PCI_SUBSYSTEM_ID = 0x0102,
	PLDM_FWUP_PCI_REVISION_ID = 0x0103,
	PLDM_FWUP_PNP_PRODUCT_IDENTIFIER = 0x0104,
	PLDM_FWUP_ACPI_PRODUCT_IDENTIFIER = 0x0105,
	PLDM_FWUP_ASCII_MODEL_NUMBER_LONG_STRING = 0x0106,
	PLDM_FWUP_ASCII_MODEL_NUMBER_SHORT_STRING = 0x0107,
	PLDM_FWUP_SCSI_PRODUCT_ID = 0x0108,
	PLDM_FWUP_UBM_CONTROLLER_DEVICE_CODE = 0x0109,
	PLDM_FWUP_VENDOR_DEFINED = 0xFFFF
};

/** @brief Descriptor types length defined in PLDM firmware update specification
 */
enum pldm_firmware_update_descriptor_types_length {
	PLDM_FWUP_PCI_VENDOR_ID_LENGTH = 2,
	PLDM_FWUP_IANA_ENTERPRISE_ID_LENGTH = 4,
	PLDM_FWUP_UUID_LENGTH = 16,
	PLDM_FWUP_PNP_VENDOR_ID_LENGTH = 3,
	PLDM_FWUP_ACPI_VENDOR_ID_LENGTH = 4,
	PLDM_FWUP_IEEE_ASSIGNED_COMPANY_ID_LENGTH = 3,
	PLDM_FWUP_SCSI_VENDOR_ID_LENGTH = 8,
	PLDM_FWUP_PCI_DEVICE_ID_LENGTH = 2,
	PLDM_FWUP_PCI_SUBSYSTEM_VENDOR_ID_LENGTH = 2,
	PLDM_FWUP_PCI_SUBSYSTEM_ID_LENGTH = 2,
	PLDM_FWUP_PCI_REVISION_ID_LENGTH = 1,
	PLDM_FWUP_PNP_PRODUCT_IDENTIFIER_LENGTH = 4,
	PLDM_FWUP_ACPI_PRODUCT_IDENTIFIER_LENGTH = 4,
	PLDM_FWUP_ASCII_MODEL_NUMBER_LONG_STRING_LENGTH = 40,
	PLDM_FWUP_ASCII_MODEL_NUMBER_SHORT_STRING_LENGTH = 10,
	PLDM_FWUP_SCSI_PRODUCT_ID_LENGTH = 16,
	PLDM_FWUP_UBM_CONTROLLER_DEVICE_CODE_LENGTH = 4
};

/** @brief ComponentClassification values defined in firmware update
 *         specification
 */
enum pldm_component_classification_values {
	PLDM_COMP_UNKNOWN = 0x0000,
	PLDM_COMP_OTHER = 0x0001,
	PLDM_COMP_DRIVER = 0x0002,
	PLDM_COMP_CONFIGURATION_SOFTWARE = 0x0003,
	PLDM_COMP_APPLICATION_SOFTWARE = 0x0004,
	PLDM_COMP_INSTRUMENTATION = 0x0005,
	PLDM_COMP_FIRMWARE_OR_BIOS = 0x0006,
	PLDM_COMP_DIAGNOSTIC_SOFTWARE = 0x0007,
	PLDM_COMP_OPERATING_SYSTEM = 0x0008,
	PLDM_COMP_MIDDLEWARE = 0x0009,
	PLDM_COMP_FIRMWARE = 0x000A,
	PLDM_COMP_BIOS_OR_FCODE = 0x000B,
	PLDM_COMP_SUPPORT_OR_SERVICEPACK = 0x000C,
	PLDM_COMP_SOFTWARE_BUNDLE = 0x000D,
	PLDM_COMP_DOWNSTREAM_DEVICE = 0xFFFF
};

/** @brief ComponentResponse values in the response of PassComponentTable
 */
enum pldm_component_responses {
	PLDM_CR_COMP_CAN_BE_UPDATED = 0,
	PLDM_CR_COMP_MAY_BE_UPDATEABLE = 1
};

/** @brief ComponentResponseCode values in the response of PassComponentTable
 */
enum pldm_component_response_codes {
	PLDM_CRC_COMP_CAN_BE_UPDATED = 0x00,
	PLDM_CRC_COMP_COMPARISON_STAMP_IDENTICAL = 0x01,
	PLDM_CRC_COMP_COMPARISON_STAMP_LOWER = 0x02,
	PLDM_CRC_INVALID_COMP_COMPARISON_STAMP = 0x03,
	PLDM_CRC_COMP_CONFLICT = 0x04,
	PLDM_CRC_COMP_PREREQUISITES_NOT_MET = 0x05,
	PLDM_CRC_COMP_NOT_SUPPORTED = 0x06,
	PLDM_CRC_COMP_SECURITY_RESTRICTIONS = 0x07,
	PLDM_CRC_INCOMPLETE_COMP_IMAGE_SET = 0x08,
	PLDM_CRC_ACTIVE_IMAGE_NOT_UPDATEABLE_SUBSEQUENTLY = 0x09,
	PLDM_CRC_COMP_VER_STR_IDENTICAL = 0x0A,
	PLDM_CRC_COMP_VER_STR_LOWER = 0x0B,
	PLDM_CRC_VENDOR_COMP_RESP_CODE_RANGE_MIN = 0xD0,
	PLDM_CRC_VENDOR_COMP_RESP_CODE_RANGE_MAX = 0xEF
};

/** @brief ComponentCompatibilityResponse values in the response of
 *         UpdateComponent
 */
enum pldm_component_compatability_responses {
	PLDM_CCR_COMP_CAN_BE_UPDATED = 0,
	PLDM_CCR_COMP_CANNOT_BE_UPDATED = 1
};

/** @brief ComponentCompatibilityResponse Code values in the response of
 *         UpdateComponent
 */
enum pldm_component_compatability_response_codes {
	PLDM_CCRC_NO_RESPONSE_CODE = 0x00,
	PLDM_CCRC_COMP_COMPARISON_STAMP_IDENTICAL = 0x01,
	PLDM_CCRC_COMP_COMPARISON_STAMP_LOWER = 0x02,
	PLDM_CCRC_INVALID_COMP_COMPARISON_STAMP = 0x03,
	PLDM_CCRC_COMP_CONFLICT = 0x04,
	PLDM_CCRC_COMP_PREREQUISITES_NOT_MET = 0x05,
	PLDM_CCRC_COMP_NOT_SUPPORTED = 0x06,
	PLDM_CCRC_COMP_SECURITY_RESTRICTIONS = 0x07,
	PLDM_CCRC_INCOMPLETE_COMP_IMAGE_SET = 0x08,
	PLDM_CCRC_COMP_INFO_NO_MATCH = 0x09,
	PLDM_CCRC_COMP_VER_STR_IDENTICAL = 0x0A,
	PLDM_CCRC_COMP_VER_STR_LOWER = 0x0B,
	PLDM_CCRC_VENDOR_COMP_RESP_CODE_RANGE_MIN = 0xD0,
	PLDM_CCRC_VENDOR_COMP_RESP_CODE_RANGE_MAX = 0xEF
};

/** @struct pldm_package_header_information
 *
 *  Structure representing fixed part of package header information
 */
struct pldm_package_header_information {
	uint8_t uuid[PLDM_FWUP_UUID_LENGTH];
	uint8_t package_header_format_version;
	uint16_t package_header_size;
	uint8_t timestamp104[PLDM_TIMESTAMP104_SIZE];
	uint16_t component_bitmap_bit_length;
	uint8_t package_version_string_type;
	uint8_t package_version_string_length;
} __attribute__((packed));

/** @struct pldm_firmware_device_id_record
 *
 *  Structure representing firmware device ID record
 */
struct pldm_firmware_device_id_record {
	uint16_t record_length;
	uint8_t descriptor_count;
	bitfield32_t device_update_option_flags;
	uint8_t comp_image_set_version_string_type;
	uint8_t comp_image_set_version_string_length;
	uint16_t fw_device_pkg_data_length;
} __attribute__((packed));

/** @struct pldm_descriptor_tlv
 *
 *  Structure representing descriptor type, length and value
 */
struct pldm_descriptor_tlv {
	uint16_t descriptor_type;
	uint16_t descriptor_length;
	uint8_t descriptor_data[1];
} __attribute__((packed));

/** @struct pldm_vendor_defined_descriptor_title_data
 *
 *  Structure representing vendor defined descriptor title sections
 */
struct pldm_vendor_defined_descriptor_title_data {
	uint8_t vendor_defined_descriptor_title_str_type;
	uint8_t vendor_defined_descriptor_title_str_len;
	uint8_t vendor_defined_descriptor_title_str[1];
} __attribute__((packed));

/** @struct pldm_component_image_information
 *
 *  Structure representing fixed part of individual component information in
 *  PLDM firmware update package
 */
struct pldm_component_image_information {
	uint16_t comp_classification;
	uint16_t comp_identifier;
	uint32_t comp_comparison_stamp;
	bitfield16_t comp_options;
	bitfield16_t requested_comp_activation_method;
	uint32_t comp_location_offset;
	uint32_t comp_size;
	uint8_t comp_version_string_type;
	uint8_t comp_version_string_length;
} __attribute__((packed));

/** @struct pldm_query_device_identifiers_resp
 *
 *  Structure representing query device identifiers response.
 */
struct pldm_query_device_identifiers_resp {
	uint8_t completion_code;
	uint32_t device_identifiers_len;
	uint8_t descriptor_count;
} __attribute__((packed));

/** @struct pldm_get_firmware_parameters_resp
 *
 *  Structure representing the fixed part of GetFirmwareParameters response
 */
struct pldm_get_firmware_parameters_resp {
	uint8_t completion_code;
	bitfield32_t capabilities_during_update;
	uint16_t comp_count;
	uint8_t active_comp_image_set_ver_str_type;
	uint8_t active_comp_image_set_ver_str_len;
	uint8_t pending_comp_image_set_ver_str_type;
	uint8_t pending_comp_image_set_ver_str_len;
} __attribute__((packed));

/** @struct pldm_component_parameter_entry
 *
 *  Structure representing component parameter table entry.
 */
struct pldm_component_parameter_entry {
	uint16_t comp_classification;
	uint16_t comp_identifier;
	uint8_t comp_classification_index;
	uint32_t active_comp_comparison_stamp;
	uint8_t active_comp_ver_str_type;
	uint8_t active_comp_ver_str_len;
	uint8_t active_comp_release_date[8];
	uint32_t pending_comp_comparison_stamp;
	uint8_t pending_comp_ver_str_type;
	uint8_t pending_comp_ver_str_len;
	uint8_t pending_comp_release_date[8];
	bitfield16_t comp_activation_methods;
	bitfield32_t capabilities_during_update;
} __attribute__((packed));

/** @struct pldm_request_update_req
 *
 *  Structure representing fixed part of Request Update request
 */
struct pldm_request_update_req {
	uint32_t max_transfer_size;
	uint16_t num_of_comp;
	uint8_t max_outstanding_transfer_req;
	uint16_t pkg_data_len;
	uint8_t comp_image_set_ver_str_type;
	uint8_t comp_image_set_ver_str_len;
} __attribute__((packed));

/** @struct pldm_request_update_resp
 *
 *  Structure representing Request Update response
 */
struct pldm_request_update_resp {
	uint8_t completion_code;
	uint16_t fd_meta_data_len;
	uint8_t fd_will_send_pkg_data;
} __attribute__((packed));

/** @struct pldm_pass_component_table_req
 *
 *  Structure representing PassComponentTable request
 */
struct pldm_pass_component_table_req {
	uint8_t transfer_flag;
	uint16_t comp_classification;
	uint16_t comp_identifier;
	uint8_t comp_classification_index;
	uint32_t comp_comparison_stamp;
	uint8_t comp_ver_str_type;
	uint8_t comp_ver_str_len;
} __attribute__((packed));

/** @struct pldm_pass_component_table_resp
 *
 *  Structure representing PassComponentTable response
 */
struct pldm_pass_component_table_resp {
	uint8_t completion_code;
	uint8_t comp_resp;
	uint8_t comp_resp_code;
} __attribute__((packed));

/** @struct pldm_update_component_req
 *
 *  Structure representing UpdateComponent request
 */
struct pldm_update_component_req {
	uint16_t comp_classification;
	uint16_t comp_identifier;
	uint8_t comp_classification_index;
	uint32_t comp_comparison_stamp;
	uint32_t comp_image_size;
	bitfield32_t update_option_flags;
	uint8_t comp_ver_str_type;
	uint8_t comp_ver_str_len;
} __attribute__((packed));

/** @struct pldm_update_component_resp
 *
 *  Structure representing UpdateComponent response
 */
struct pldm_update_component_resp {
	uint8_t completion_code;
	uint8_t comp_compatability_resp;
	uint8_t comp_compatability_resp_code;
	bitfield32_t update_option_flags_enabled;
	uint16_t time_before_req_fw_data;
} __attribute__((packed));

/** @brief Decode the PLDM package header information
 *
 *  @param[in] data - pointer to package header information
 *  @param[in] length - available length in the firmware update package
 *  @param[out] package_header_info - pointer to fixed part of PLDM package
 *                                    header information
 *  @param[out] package_version_str - pointer to package version string
 *
 *  @return pldm_completion_codes
 */
int decode_pldm_package_header_info(
    const uint8_t *data, size_t length,
    struct pldm_package_header_information *package_header_info,
    struct variable_field *package_version_str);

/** @brief Decode individual firmware device ID record
 *
 *  @param[in] data - pointer to firmware device ID record
 *  @param[in] length - available length in the firmware update package
 *  @param[in] component_bitmap_bit_length - ComponentBitmapBitLengthfield
 *                                           parsed from the package header info
 *  @param[out] fw_device_id_record - pointer to fixed part of firmware device
 *                                    id record
 *  @param[out] applicable_components - pointer to ApplicableComponents
 *  @param[out] comp_image_set_version_str - pointer to
 *                                           ComponentImageSetVersionString
 *  @param[out] record_descriptors - pointer to RecordDescriptors
 *  @param[out] fw_device_pkg_data - pointer to FirmwareDevicePackageData
 *
 *  @return pldm_completion_codes
 */
int decode_firmware_device_id_record(
    const uint8_t *data, size_t length, uint16_t component_bitmap_bit_length,
    struct pldm_firmware_device_id_record *fw_device_id_record,
    struct variable_field *applicable_components,
    struct variable_field *comp_image_set_version_str,
    struct variable_field *record_descriptors,
    struct variable_field *fw_device_pkg_data);

/** @brief Decode the record descriptor entries in the firmware update package
 *         and the Descriptors in the QueryDeviceIDentifiers command
 *
 *  @param[in] data - pointer to descriptor entry
 *  @param[in] length - remaining length of the descriptor data
 *  @param[out] descriptor_type - pointer to descriptor type
 *  @param[out] descriptor_data - pointer to descriptor data
 *
 *  @return pldm_completion_codes
 */
int decode_descriptor_type_length_value(const uint8_t *data, size_t length,
					uint16_t *descriptor_type,
					struct variable_field *descriptor_data);

/** @brief Decode the vendor defined descriptor value
 *
 *  @param[in] data - pointer to vendor defined descriptor value
 *  @param[in] length - length of the vendor defined descriptor value
 *  @param[out] descriptor_title_str_type - pointer to vendor defined descriptor
 *                                          title string type
 *  @param[out] descriptor_title_str - pointer to vendor defined descriptor
 *                                     title string
 *  @param[out] descriptor_data - pointer to vendor defined descriptor data
 *
 *  @return pldm_completion_codes
 */
int decode_vendor_defined_descriptor_value(
    const uint8_t *data, size_t length, uint8_t *descriptor_title_str_type,
    struct variable_field *descriptor_title_str,
    struct variable_field *descriptor_data);

/** @brief Decode individual component image information
 *
 *  @param[in] data - pointer to component image information
 *  @param[in] length - available length in the firmware update package
 *  @param[out] pldm_comp_image_info - pointer to fixed part of component image
 *                                     information
 *  @param[out] comp_version_str - pointer to component version string
 *
 *  @return pldm_completion_codes
 */
int decode_pldm_comp_image_info(
    const uint8_t *data, size_t length,
    struct pldm_component_image_information *pldm_comp_image_info,
    struct variable_field *comp_version_str);

/** @brief Create a PLDM request message for QueryDeviceIdentifiers
 *
 *  @param[in] instance_id - Message's instance id
 *  @param[in] payload_length - Length of the request message payload
 *  @param[in,out] msg - Message will be written to this
 *
 *  @return pldm_completion_codes
 *
 *  @note  Caller is responsible for memory alloc and dealloc of param
 *         'msg.payload'
 */
int encode_query_device_identifiers_req(uint8_t instance_id,
					size_t payload_length,
					struct pldm_msg *msg);

/** @brief Decode QueryDeviceIdentifiers response message
 *
 *  @param[in] msg - Response message
 *  @param[in] payload_length - Length of response message payload
 *  @param[out] completion_code - Pointer to response msg's PLDM completion code
 *  @param[out] device_identifiers_len - Pointer to device identifiers length
 *  @param[out] descriptor_count - Pointer to descriptor count
 *  @param[out] descriptor_data - Pointer to descriptor data
 *
 *  @return pldm_completion_codes
 */
int decode_query_device_identifiers_resp(const struct pldm_msg *msg,
					 size_t payload_length,
					 uint8_t *completion_code,
					 uint32_t *device_identifiers_len,
					 uint8_t *descriptor_count,
					 uint8_t **descriptor_data);

/** @brief Create a PLDM request message for GetFirmwareParameters
 *
 *  @param[in] instance_id - Message's instance id
 *  @param[in] payload_length - Length of the request message payload
 *  @param[in,out] msg - Message will be written to this
 *
 *  @return pldm_completion_codes
 *
 *  @note  Caller is responsible for memory alloc and dealloc of param
 *         'msg.payload'
 */
int encode_get_firmware_parameters_req(uint8_t instance_id,
				       size_t payload_length,
				       struct pldm_msg *msg);

/** @brief Decode GetFirmwareParameters response
 *
 *  @param[in] msg - Response message
 *  @param[in] payload_length - Length of response message payload
 *  @param[out] resp_data - Pointer to get firmware parameters response
 *  @param[out] active_comp_image_set_ver_str - Pointer to active component
 *                                              image set version string
 *  @param[out] pending_comp_image_set_ver_str - Pointer to pending component
 *                                               image set version string
 *  @param[out] comp_parameter_table - Pointer to component parameter table
 *
 *  @return pldm_completion_codes
 */
int decode_get_firmware_parameters_resp(
    const struct pldm_msg *msg, size_t payload_length,
    struct pldm_get_firmware_parameters_resp *resp_data,
    struct variable_field *active_comp_image_set_ver_str,
    struct variable_field *pending_comp_image_set_ver_str,
    struct variable_field *comp_parameter_table);

/** @brief Decode component entries in the component parameter table which is
 *         part of the response of GetFirmwareParameters command
 *
 *  @param[in] data - Component entry
 *  @param[in] length - Length of component entry
 *  @param[out] component_data - Pointer to component parameter table
 *  @param[out] active_comp_ver_str - Pointer to active component version string
 *  @param[out] pending_comp_ver_str - Pointer to pending component version
 *                                     string
 *
 *  @return pldm_completion_codes
 */
int decode_get_firmware_parameters_resp_comp_entry(
    const uint8_t *data, size_t length,
    struct pldm_component_parameter_entry *component_data,
    struct variable_field *active_comp_ver_str,
    struct variable_field *pending_comp_ver_str);

/** @brief Create PLDM request message for RequestUpdate
 *
 *  @param[in] instance_id - Message's instance id
 *  @param[in] max_transfer_size - Maximum size of the variable payload allowed
 *                                 to be requested via RequestFirmwareData
 *                                 command
 *  @param[in] num_of_comp - Total number of components that will be passed to
 *                           the FD during the update
 *  @param[in] max_outstanding_transfer_req - Total number of outstanding
 * 											  RequestFirmwareData
 * commands that can be sent by the FD
 *  @param[in] pkg_data_len - Value of the FirmwareDevicePackageDataLength field
 *                            present in firmware package header
 *  @param[in] comp_image_set_ver_str_type - StringType of
 *                                           ComponentImageSetVersionString
 *  @param[in] comp_image_set_ver_str_len - The length of the
 *                                          ComponentImageSetVersionString
 *  @param[in] comp_img_set_ver_str - Component Image Set version information
 *  @param[in,out] msg - Message will be written to this
 *  @param[in] payload_length - Length of request message payload
 *
 *  @return pldm_completion_codes
 *
 *  @note Caller is responsible for memory alloc and dealloc of param
 *        'msg.payload'
 */
int encode_request_update_req(uint8_t instance_id, uint32_t max_transfer_size,
			      uint16_t num_of_comp,
			      uint8_t max_outstanding_transfer_req,
			      uint16_t pkg_data_len,
			      uint8_t comp_image_set_ver_str_type,
			      uint8_t comp_image_set_ver_str_len,
			      const struct variable_field *comp_img_set_ver_str,
			      struct pldm_msg *msg, size_t payload_length);

/** @brief Decode a RequestUpdate response message
 *
 *  @param[in] msg - Response message
 *  @param[in] payload_length - Length of response message payload
 *  @param[out] completion_code - Pointer to hold the completion code
 *  @param[out] fd_meta_data_len - Pointer to hold the length of FD metadata
 *  @param[out] fd_will_send_pkg_data - Pointer to hold information whether FD
 *                                      will send GetPackageData command
 *  @return pldm_completion_codes
 */
int decode_request_update_resp(const struct pldm_msg *msg,
			       size_t payload_length, uint8_t *completion_code,
			       uint16_t *fd_meta_data_len,
			       uint8_t *fd_will_send_pkg_data);

/** @brief Create PLDM request message for PassComponentTable
 *
 *  @param[in] instance_id - Message's instance id
 *  @param[in] transfer_flag - TransferFlag
 *  @param[in] comp_classification - ComponentClassification
 *  @param[in] comp_identifier - ComponentIdentifier
 *  @param[in] comp_classification_index - ComponentClassificationIndex
 *  @param[in] comp_comparison_stamp - ComponentComparisonStamp
 *  @param[in] comp_ver_str_type - ComponentVersionStringType
 *  @param[in] comp_ver_str_len - ComponentVersionStringLength
 *  @param[in] comp_ver_str - ComponentVersionString
 *  @param[in,out] msg - Message will be written to this
 *  @param[in] payload_length - Length of request message payload
 *                              information
 *
 *  @return pldm_completion_codes
 *
 *  @note  Caller is responsible for memory alloc and dealloc of param
 *         'msg.payload'
 */
int encode_pass_component_table_req(
    uint8_t instance_id, uint8_t transfer_flag, uint16_t comp_classification,
    uint16_t comp_identifier, uint8_t comp_classification_index,
    uint32_t comp_comparison_stamp, uint8_t comp_ver_str_type,
    uint8_t comp_ver_str_len, const struct variable_field *comp_ver_str,
    struct pldm_msg *msg, size_t payload_length);

/** @brief Decode PassComponentTable response message
 *
 *  @param[in] msg - Response message
 *  @param[in] payload_length - Length of response message payload
 *  @param[out] completion_code - Pointer to hold completion code
 *  @param[out] comp_resp - Pointer to hold component response
 *  @param[out] comp_resp_code - Pointer to hold component response code
 *
 *  @return pldm_completion_codes
 */
int decode_pass_component_table_resp(const struct pldm_msg *msg,
				     size_t payload_length,
				     uint8_t *completion_code,
				     uint8_t *comp_resp,
				     uint8_t *comp_resp_code);

/** @brief Create PLDM request message for UpdateComponent
 *
 *  @param[in] instance_id - Message's instance id
 *  @param[in] comp_classification - ComponentClassification
 *  @param[in] comp_identifier - ComponentIdentifier
 *  @param[in] comp_classification_index - ComponentClassificationIndex
 *  @param[in] comp_comparison_stamp - ComponentComparisonStamp
 *  @param[in] comp_image_size - ComponentImageSize
 *  @param[in] update_option_flags - UpdateOptionFlags
 *  @param[in] comp_ver_str_type - ComponentVersionStringType
 *  @param[in] comp_ver_str_len - ComponentVersionStringLength
 *  @param[in] comp_ver_str - ComponentVersionString
 *  @param[in,out] msg - Message will be written to this
 *  @param[in] payload_length - Length of request message payload
 *                              information
 *
 *  @return pldm_completion_codes
 *
 *  @note  Caller is responsible for memory alloc and dealloc of param
 *         'msg.payload'
 */
int encode_update_component_req(
    uint8_t instance_id, uint16_t comp_classification, uint16_t comp_identifier,
    uint8_t comp_classification_index, uint32_t comp_comparison_stamp,
    uint32_t comp_image_size, bitfield32_t update_option_flags,
    uint8_t comp_ver_str_type, uint8_t comp_ver_str_len,
    const struct variable_field *comp_ver_str, struct pldm_msg *msg,
    size_t payload_length);

/** @brief Decode UpdateComponent response message
 *
 *  @param[in] msg - Response message
 *  @param[in] payload_length - Length of response message payload
 *  @param[out] completion_code - Pointer to hold completion code
 *  @param[out] comp_compatability_resp - Pointer to hold component
 *                                        compatibility response
 *  @param[out] comp_compatability_resp_code - Pointer to hold component
 *                                             compatibility response code
 *  @param[out] update_option_flags_enabled - Pointer to hold
 *                                            UpdateOptionsFlagEnabled
 *  @param[out] time_before_req_fw_data - Pointer to hold the estimated time
 *                                        before sending RequestFirmwareData
 *
 *  @return pldm_completion_codes
 */
int decode_update_component_resp(const struct pldm_msg *msg,
				 size_t payload_length,
				 uint8_t *completion_code,
				 uint8_t *comp_compatability_resp,
				 uint8_t *comp_compatability_resp_code,
				 bitfield32_t *update_option_flags_enabled,
				 uint16_t *time_before_req_fw_data);
#ifdef __cplusplus
}
#endif

#endif // End of FW_UPDATE_H
