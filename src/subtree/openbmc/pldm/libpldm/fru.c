#include <endian.h>
#include <string.h>

#include "fru.h"

int encode_get_fru_record_table_metadata_req(uint8_t instance_id,
					     struct pldm_msg *msg,
					     size_t payload_length)
{
	if (msg == NULL) {
		return PLDM_ERROR_INVALID_DATA;
	}

	if (payload_length != PLDM_GET_FRU_RECORD_TABLE_METADATA_REQ_BYTES) {
		return PLDM_ERROR_INVALID_LENGTH;
	}

	struct pldm_header_info header = {0};
	header.instance = instance_id;
	header.msg_type = PLDM_REQUEST;
	header.pldm_type = PLDM_FRU;
	header.command = PLDM_GET_FRU_RECORD_TABLE_METADATA;
	int rc = pack_pldm_header(&header, &(msg->hdr));
	if (PLDM_SUCCESS != rc) {
		return rc;
	}

	return PLDM_SUCCESS;
}

int decode_get_fru_record_table_metadata_resp(
    const struct pldm_msg *msg, size_t payload_length, uint8_t *completion_code,
    uint8_t *fru_data_major_version, uint8_t *fru_data_minor_version,
    uint32_t *fru_table_maximum_size, uint32_t *fru_table_length,
    uint16_t *total_record_set_identifiers, uint16_t *total_table_records,
    uint32_t *checksum)
{
	if (msg == NULL || completion_code == NULL ||
	    fru_data_major_version == NULL || fru_data_minor_version == NULL ||
	    fru_table_maximum_size == NULL || fru_table_length == NULL ||
	    total_record_set_identifiers == NULL ||
	    total_table_records == NULL || checksum == NULL) {
		return PLDM_ERROR_INVALID_DATA;
	}

	*completion_code = msg->payload[0];
	if (PLDM_SUCCESS != *completion_code) {
		return PLDM_SUCCESS;
	}

	if (payload_length != PLDM_GET_FRU_RECORD_TABLE_METADATA_RESP_BYTES) {
		return PLDM_ERROR_INVALID_LENGTH;
	}

	struct pldm_get_fru_record_table_metadata_resp *response =
	    (struct pldm_get_fru_record_table_metadata_resp *)msg->payload;

	*fru_data_major_version = response->fru_data_major_version;
	*fru_data_minor_version = response->fru_data_minor_version;
	*fru_table_maximum_size = le32toh(response->fru_table_maximum_size);
	*fru_table_length = le32toh(response->fru_table_length);
	*total_record_set_identifiers =
	    le16toh(response->total_record_set_identifiers);
	*total_table_records = le16toh(response->total_table_records);
	*checksum = le32toh(response->checksum);

	return PLDM_SUCCESS;
}

int encode_get_fru_record_table_metadata_resp(
    uint8_t instance_id, uint8_t completion_code,
    uint8_t fru_data_major_version, uint8_t fru_data_minor_version,
    uint32_t fru_table_maximum_size, uint32_t fru_table_length,
    uint16_t total_record_set_identifiers, uint16_t total_table_records,
    uint32_t checksum, struct pldm_msg *msg)
{

	if (msg == NULL) {
		return PLDM_ERROR_INVALID_DATA;
	}

	struct pldm_header_info header = {0};
	header.msg_type = PLDM_RESPONSE;
	header.instance = instance_id;
	header.pldm_type = PLDM_FRU;
	header.command = PLDM_GET_FRU_RECORD_TABLE_METADATA;
	int rc = pack_pldm_header(&header, &(msg->hdr));
	if (PLDM_SUCCESS != rc) {
		return rc;
	}

	struct pldm_get_fru_record_table_metadata_resp *response =
	    (struct pldm_get_fru_record_table_metadata_resp *)msg->payload;
	response->completion_code = completion_code;
	if (response->completion_code == PLDM_SUCCESS) {
		response->fru_data_major_version = fru_data_major_version;
		response->fru_data_minor_version = fru_data_minor_version;
		response->fru_table_maximum_size =
		    htole32(fru_table_maximum_size);
		response->fru_table_length = htole32(fru_table_length);
		response->total_record_set_identifiers =
		    htole16(total_record_set_identifiers);
		response->total_table_records = htole16(total_table_records);
		response->checksum = htole32(checksum);
	}

	return PLDM_SUCCESS;
}

int decode_get_fru_record_table_req(const struct pldm_msg *msg,
				    size_t payload_length,
				    uint32_t *data_transfer_handle,
				    uint8_t *transfer_operation_flag)
{
	if (msg == NULL || data_transfer_handle == NULL ||
	    transfer_operation_flag == NULL) {
		return PLDM_ERROR_INVALID_DATA;
	}

	if (payload_length != PLDM_GET_FRU_RECORD_TABLE_REQ_BYTES) {
		return PLDM_ERROR_INVALID_LENGTH;
	}

	struct pldm_get_fru_record_table_req *req =
	    (struct pldm_get_fru_record_table_req *)msg->payload;

	*data_transfer_handle = le32toh(req->data_transfer_handle);
	*transfer_operation_flag = req->transfer_operation_flag;

	return PLDM_SUCCESS;
}

int encode_get_fru_record_table_resp(uint8_t instance_id,
				     uint8_t completion_code,
				     uint32_t next_data_transfer_handle,
				     uint8_t transfer_flag,
				     struct pldm_msg *msg)
{
	struct pldm_header_info header = {0};
	int rc = PLDM_ERROR_INVALID_DATA;

	header.msg_type = PLDM_RESPONSE;
	header.instance = instance_id;
	header.pldm_type = PLDM_FRU;
	header.command = PLDM_GET_FRU_RECORD_TABLE;

	if (msg == NULL) {
		return rc;
	}

	if ((rc = pack_pldm_header(&header, &(msg->hdr))) > PLDM_SUCCESS) {
		return rc;
	}

	struct pldm_get_fru_record_table_resp *resp =
	    (struct pldm_get_fru_record_table_resp *)msg->payload;

	resp->completion_code = completion_code;

	if (resp->completion_code == PLDM_SUCCESS) {

		resp->next_data_transfer_handle =
		    htole32(next_data_transfer_handle);
		resp->transfer_flag = transfer_flag;
	}

	return PLDM_SUCCESS;
}

int encode_fru_record(uint8_t *fru_table, size_t total_size, size_t *curr_size,
		      uint16_t record_set_id, uint8_t record_type,
		      uint8_t num_frus, uint8_t encoding, uint8_t *tlvs,
		      size_t tlvs_size)
{
	size_t record_hdr_size = sizeof(struct pldm_fru_record_data_format) -
				 sizeof(struct pldm_fru_record_tlv);

	if ((*curr_size + record_hdr_size + tlvs_size) != total_size) {
		return PLDM_ERROR_INVALID_LENGTH;
	}

	if (fru_table == NULL || curr_size == NULL || !tlvs_size) {
		return PLDM_ERROR_INVALID_DATA;
	}

	struct pldm_fru_record_data_format *record =
	    (struct pldm_fru_record_data_format *)(fru_table + *curr_size);
	record->record_set_id = htole16(record_set_id);
	record->record_type = record_type;
	record->num_fru_fields = num_frus;
	record->encoding_type = encoding;
	*curr_size += record_hdr_size;

	if (tlvs) {
		memcpy(fru_table + *curr_size, tlvs, tlvs_size);
		*curr_size += tlvs_size;
	}

	return PLDM_SUCCESS;
}

int encode_get_fru_record_table_req(uint8_t instance_id,
				    uint32_t data_transfer_handle,
				    uint8_t transfer_operation_flag,
				    struct pldm_msg *msg, size_t payload_length)

{
	struct pldm_header_info header = {0};
	int rc = PLDM_ERROR_INVALID_DATA;

	header.msg_type = PLDM_REQUEST;
	header.instance = instance_id;
	header.pldm_type = PLDM_FRU;
	header.command = PLDM_GET_FRU_RECORD_TABLE;

	if (msg == NULL) {
		return rc;
	}
	if (payload_length != sizeof(struct pldm_get_fru_record_table_req)) {
		return PLDM_ERROR_INVALID_LENGTH;
	}
	if ((rc = pack_pldm_header(&header, &(msg->hdr))) > PLDM_SUCCESS) {
		return rc;
	}

	struct pldm_get_fru_record_table_req *req =
	    (struct pldm_get_fru_record_table_req *)msg->payload;
	req->data_transfer_handle = htole32(data_transfer_handle);
	req->transfer_operation_flag = transfer_operation_flag;

	return PLDM_SUCCESS;
}

int decode_get_fru_record_table_resp(
    const struct pldm_msg *msg, size_t payload_length, uint8_t *completion_code,
    uint32_t *next_data_transfer_handle, uint8_t *transfer_flag,
    uint8_t *fru_record_table_data, size_t *fru_record_table_length)
{
	if (msg == NULL || completion_code == NULL ||
	    next_data_transfer_handle == NULL || transfer_flag == NULL ||
	    fru_record_table_data == NULL || fru_record_table_length == NULL) {
		return PLDM_ERROR_INVALID_DATA;
	}

	*completion_code = msg->payload[0];
	if (PLDM_SUCCESS != *completion_code) {
		return PLDM_SUCCESS;
	}
	if (payload_length <= PLDM_GET_FRU_RECORD_TABLE_MIN_RESP_BYTES) {
		return PLDM_ERROR_INVALID_LENGTH;
	}

	struct pldm_get_fru_record_table_resp *resp =
	    (struct pldm_get_fru_record_table_resp *)msg->payload;

	*next_data_transfer_handle = le32toh(resp->next_data_transfer_handle);
	*transfer_flag = resp->transfer_flag;
	memcpy(fru_record_table_data, resp->fru_record_table_data,
	       payload_length - PLDM_GET_FRU_RECORD_TABLE_MIN_RESP_BYTES);
	*fru_record_table_length =
	    payload_length - PLDM_GET_FRU_RECORD_TABLE_MIN_RESP_BYTES;

	return PLDM_SUCCESS;
}
