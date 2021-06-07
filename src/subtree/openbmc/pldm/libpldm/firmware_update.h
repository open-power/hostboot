#ifndef FW_UPDATE_H
#define FW_UPDATE_H

#ifdef __cplusplus
extern "C" {
#endif
#include "base.h"
#include "utils.h"

#define PLDM_QUERY_DEVICE_IDENTIFIERS_REQ_BYTES 0
/** @brief Minimum length of device descriptor, 2 bytes for descriptor type,
 *         2 bytes for descriptor length and atleast 1 byte of descriptor data
 */
#define PLDM_FWUP_DEVICE_DESCRIPTOR_MIN_LEN 5
#define PLDM_GET_FIRMWARE_PARAMETERS_REQ_BYTES 0

/** @brief PLDM Firmware update commands
 */
enum pldm_firmware_update_commands {
	PLDM_QUERY_DEVICE_IDENTIFIERS = 0x01,
	PLDM_GET_FIRMWARE_PARAMETERS = 0x02
};

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
 *  Structure representing get firmware parameters response.
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

/** @brief Decode GetFirmwareParameters response parameters except the
 *         ComponentParameterTable
 *
 *  @param[in] msg - Response message
 *  @param[in] payload_length - Length of response message payload
 *  @param[out] resp_data - Pointer to get firmware parameters response
 *  @param[out] active_comp_image_set_ver_str - Pointer to active component
 * image set version string
 *  @param[out] pending_comp_image_set_ver_str - Pointer to pending component
 * image set version string
 *
 *  @return pldm_completion_codes
 */
int decode_get_firmware_parameters_resp_comp_set_info(
    const struct pldm_msg *msg, size_t payload_length,
    struct pldm_get_firmware_parameters_resp *resp_data,
    struct variable_field *active_comp_image_set_ver_str,
    struct variable_field *pending_comp_image_set_ver_str);

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

#ifdef __cplusplus
}
#endif

#endif // End of FW_UPDATE_H
