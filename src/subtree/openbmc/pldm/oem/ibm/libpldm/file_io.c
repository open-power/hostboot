#include "file_io.h"
#include <endian.h>
#include <string.h>

int decode_rw_file_memory_req(const struct pldm_msg *msg, size_t payload_length,
			      uint32_t *file_handle, uint32_t *offset,
			      uint32_t *length, uint64_t *address)
{
	if (msg == NULL || file_handle == NULL || offset == NULL ||
	    length == NULL || address == NULL) {
		return PLDM_ERROR_INVALID_DATA;
	}

	if (payload_length != PLDM_RW_FILE_MEM_REQ_BYTES) {
		return PLDM_ERROR_INVALID_LENGTH;
	}

	struct pldm_read_write_file_memory_req *request =
	    (struct pldm_read_write_file_memory_req *)msg->payload;

	*file_handle = le32toh(request->file_handle);
	*offset = le32toh(request->offset);
	*length = le32toh(request->length);
	*address = le64toh(request->address);

	return PLDM_SUCCESS;
}

int encode_rw_file_memory_resp(uint8_t instance_id, uint8_t command,
			       uint8_t completion_code, uint32_t length,
			       struct pldm_msg *msg)
{
	struct pldm_header_info header = {0};
	int rc = PLDM_SUCCESS;

	header.msg_type = PLDM_RESPONSE;
	header.instance = instance_id;
	header.pldm_type = PLDM_OEM;
	header.command = command;

	if ((rc = pack_pldm_header(&header, &(msg->hdr))) > PLDM_SUCCESS) {
		return rc;
	}

	struct pldm_read_write_file_memory_resp *response =
	    (struct pldm_read_write_file_memory_resp *)msg->payload;
	response->completion_code = completion_code;
	if (response->completion_code == PLDM_SUCCESS) {
		response->length = htole32(length);
	}

	return PLDM_SUCCESS;
}

int encode_rw_file_memory_req(uint8_t instance_id, uint8_t command,
			      uint32_t file_handle, uint32_t offset,
			      uint32_t length, uint64_t address,
			      struct pldm_msg *msg)
{
	struct pldm_header_info header = {0};
	int rc = PLDM_SUCCESS;
	if (msg == NULL) {
		return PLDM_ERROR_INVALID_DATA;
	}

	header.msg_type = PLDM_REQUEST;
	header.instance = instance_id;
	header.pldm_type = PLDM_OEM;
	header.command = command;

	if ((rc = pack_pldm_header(&header, &(msg->hdr))) > PLDM_SUCCESS) {
		return rc;
	}

	struct pldm_read_write_file_memory_req *req =
	    (struct pldm_read_write_file_memory_req *)msg->payload;
	req->file_handle = htole32(file_handle);
	req->offset = htole32(offset);
	req->length = htole32(length);
	req->address = htole64(address);
	return PLDM_SUCCESS;
}

int decode_rw_file_memory_resp(const struct pldm_msg *msg,
			       size_t payload_length, uint8_t *completion_code,
			       uint32_t *length)
{
	if (msg == NULL || length == NULL || completion_code == NULL) {
		return PLDM_ERROR_INVALID_DATA;
	}

	if (payload_length != PLDM_RW_FILE_MEM_RESP_BYTES) {
		return PLDM_ERROR_INVALID_LENGTH;
	}

	struct pldm_read_write_file_memory_resp *response =
	    (struct pldm_read_write_file_memory_resp *)msg->payload;
	*completion_code = response->completion_code;
	if (*completion_code == PLDM_SUCCESS) {
		*length = le32toh(response->length);
	}

	return PLDM_SUCCESS;
}

int decode_get_file_table_req(const struct pldm_msg *msg, size_t payload_length,
			      uint32_t *transfer_handle,
			      uint8_t *transfer_opflag, uint8_t *table_type)
{
	if (msg == NULL || transfer_handle == NULL || transfer_opflag == NULL ||
	    table_type == NULL) {
		return PLDM_ERROR_INVALID_DATA;
	}

	if (payload_length != PLDM_GET_FILE_TABLE_REQ_BYTES) {
		return PLDM_ERROR_INVALID_LENGTH;
	}

	struct pldm_get_file_table_req *request =
	    (struct pldm_get_file_table_req *)msg->payload;

	*transfer_handle = le32toh(request->transfer_handle);
	*transfer_opflag = request->operation_flag;
	*table_type = request->table_type;

	return PLDM_SUCCESS;
}

int encode_get_file_table_resp(uint8_t instance_id, uint8_t completion_code,
			       uint32_t next_transfer_handle,
			       uint8_t transfer_flag, const uint8_t *table_data,
			       size_t table_size, struct pldm_msg *msg)
{
	struct pldm_header_info header = {0};
	int rc = PLDM_SUCCESS;

	header.msg_type = PLDM_RESPONSE;
	header.instance = instance_id;
	header.pldm_type = PLDM_OEM;
	header.command = PLDM_GET_FILE_TABLE;

	if ((rc = pack_pldm_header(&header, &(msg->hdr))) > PLDM_SUCCESS) {
		return rc;
	}

	struct pldm_get_file_table_resp *response =
	    (struct pldm_get_file_table_resp *)msg->payload;
	response->completion_code = completion_code;

	if (completion_code == PLDM_SUCCESS) {
		response->next_transfer_handle = htole32(next_transfer_handle);
		response->transfer_flag = transfer_flag;
		memcpy(response->table_data, table_data, table_size);
	}

	return PLDM_SUCCESS;
}

int decode_read_file_req(const struct pldm_msg *msg, size_t payload_length,
			 uint32_t *file_handle, uint32_t *offset,
			 uint32_t *length)
{
	if (msg == NULL || file_handle == NULL || offset == NULL ||
	    length == NULL) {
		return PLDM_ERROR_INVALID_DATA;
	}

	if (payload_length != PLDM_READ_FILE_REQ_BYTES) {
		return PLDM_ERROR_INVALID_LENGTH;
	}

	struct pldm_read_file_req *request =
	    (struct pldm_read_file_req *)msg->payload;

	*file_handle = le32toh(request->file_handle);
	*offset = le32toh(request->offset);
	*length = le32toh(request->length);

	return PLDM_SUCCESS;
}

int encode_read_file_req(uint8_t instance_id, uint32_t file_handle,
			 uint32_t offset, uint32_t length, struct pldm_msg *msg)
{
	struct pldm_header_info header = {0};
	int rc = PLDM_SUCCESS;

	header.msg_type = PLDM_REQUEST;
	header.instance = instance_id;
	header.pldm_type = PLDM_OEM;
	header.command = PLDM_READ_FILE;

	if (msg == NULL) {
		return PLDM_ERROR_INVALID_DATA;
	}

	if (length == 0) {
		return PLDM_ERROR_INVALID_LENGTH;
	}

	if ((rc = pack_pldm_header(&header, &(msg->hdr))) > PLDM_SUCCESS) {
		return rc;
	}

	struct pldm_read_file_req *request =
	    (struct pldm_read_file_req *)msg->payload;

	request->file_handle = htole32(file_handle);
	request->offset = htole32(offset);
	request->length = htole32(length);

	return PLDM_SUCCESS;
}

int decode_read_file_resp(const struct pldm_msg *msg, size_t payload_length,
			  uint8_t *completion_code, uint32_t *length,
			  size_t *file_data_offset)
{
	if (msg == NULL || completion_code == NULL || length == NULL) {
		return PLDM_ERROR_INVALID_DATA;
	}

	if (payload_length < PLDM_READ_FILE_RESP_BYTES) {
		return PLDM_ERROR_INVALID_LENGTH;
	}

	struct pldm_read_file_resp *response =
	    (struct pldm_read_file_resp *)msg->payload;

	*completion_code = response->completion_code;
	if (*completion_code == PLDM_SUCCESS) {
		*length = le32toh(response->length);
		if (payload_length != PLDM_READ_FILE_RESP_BYTES + *length) {
			return PLDM_ERROR_INVALID_LENGTH;
		}
		*file_data_offset = sizeof(*completion_code) + sizeof(*length);
	}

	return PLDM_SUCCESS;
}

int encode_read_file_resp(uint8_t instance_id, uint8_t completion_code,
			  uint32_t length, struct pldm_msg *msg)
{
	struct pldm_header_info header = {0};
	int rc = PLDM_SUCCESS;

	header.msg_type = PLDM_RESPONSE;
	header.instance = instance_id;
	header.pldm_type = PLDM_OEM;
	header.command = PLDM_READ_FILE;

	if (msg == NULL) {
		return PLDM_ERROR_INVALID_DATA;
	}

	if ((rc = pack_pldm_header(&header, &(msg->hdr))) > PLDM_SUCCESS) {
		return rc;
	}

	struct pldm_read_file_resp *response =
	    (struct pldm_read_file_resp *)msg->payload;
	response->completion_code = completion_code;

	if (response->completion_code == PLDM_SUCCESS) {
		response->length = htole32(length);
	}

	return PLDM_SUCCESS;
}

int decode_write_file_req(const struct pldm_msg *msg, size_t payload_length,
			  uint32_t *file_handle, uint32_t *offset,
			  uint32_t *length, size_t *file_data_offset)
{
	if (msg == NULL || file_handle == NULL || length == NULL) {
		return PLDM_ERROR_INVALID_DATA;
	}

	if (payload_length < PLDM_WRITE_FILE_REQ_BYTES) {
		return PLDM_ERROR_INVALID_LENGTH;
	}

	struct pldm_write_file_req *request =
	    (struct pldm_write_file_req *)msg->payload;

	*file_handle = le32toh(request->file_handle);
	*offset = le32toh(request->offset);
	*length = le32toh(request->length);
	if (payload_length != PLDM_WRITE_FILE_REQ_BYTES + *length) {
		return PLDM_ERROR_INVALID_LENGTH;
	}
	*file_data_offset =
	    sizeof(*file_handle) + sizeof(*offset) + sizeof(*length);

	return PLDM_SUCCESS;
}

int encode_write_file_req(uint8_t instance_id, uint32_t file_handle,
			  uint32_t offset, uint32_t length,
			  struct pldm_msg *msg)
{
	struct pldm_header_info header = {0};
	int rc = PLDM_SUCCESS;

	header.msg_type = PLDM_REQUEST;
	header.instance = instance_id;
	header.pldm_type = PLDM_OEM;
	header.command = PLDM_WRITE_FILE;

	if (msg == NULL) {
		return PLDM_ERROR_INVALID_DATA;
	}

	if ((rc = pack_pldm_header(&header, &(msg->hdr))) > PLDM_SUCCESS) {
		return rc;
	}

	if (length == 0) {
		return PLDM_ERROR_INVALID_LENGTH;
	}

	struct pldm_write_file_req *request =
	    (struct pldm_write_file_req *)msg->payload;

	request->file_handle = htole32(file_handle);
	request->offset = htole32(offset);
	request->length = htole32(length);

	return PLDM_SUCCESS;
}

int decode_write_file_resp(const struct pldm_msg *msg, size_t payload_length,
			   uint8_t *completion_code, uint32_t *length)
{
	if (msg == NULL || completion_code == NULL || length == NULL) {
		return PLDM_ERROR_INVALID_DATA;
	}

	if (payload_length != PLDM_WRITE_FILE_RESP_BYTES) {
		return PLDM_ERROR_INVALID_LENGTH;
	}

	struct pldm_write_file_resp *response =
	    (struct pldm_write_file_resp *)msg->payload;

	*completion_code = le32toh(response->completion_code);
	if (response->completion_code == PLDM_SUCCESS) {
		*length = le32toh(response->length);
	}

	return PLDM_SUCCESS;
}

int encode_write_file_resp(uint8_t instance_id, uint8_t completion_code,
			   uint32_t length, struct pldm_msg *msg)
{
	struct pldm_header_info header = {0};
	int rc = PLDM_SUCCESS;

	header.msg_type = PLDM_RESPONSE;
	header.instance = instance_id;
	header.pldm_type = PLDM_OEM;
	header.command = PLDM_WRITE_FILE;

	if (msg == NULL) {
		return PLDM_ERROR_INVALID_DATA;
	}

	if ((rc = pack_pldm_header(&header, &(msg->hdr))) > PLDM_SUCCESS) {
		return rc;
	}

	struct pldm_write_file_resp *response =
	    (struct pldm_write_file_resp *)msg->payload;
	response->completion_code = completion_code;

	if (response->completion_code == PLDM_SUCCESS) {
		response->length = htole32(length);
	}

	return PLDM_SUCCESS;
}

int decode_rw_file_by_type_memory_req(const struct pldm_msg *msg,
				      size_t payload_length,
				      uint16_t *file_type,
				      uint32_t *file_handle, uint32_t *offset,
				      uint32_t *length, uint64_t *address)
{
	if (msg == NULL || file_type == NULL || file_handle == NULL ||
	    offset == NULL || length == NULL || address == NULL) {
		return PLDM_ERROR_INVALID_DATA;
	}

	if (payload_length != PLDM_RW_FILE_BY_TYPE_MEM_REQ_BYTES) {
		return PLDM_ERROR_INVALID_LENGTH;
	}

	struct pldm_read_write_file_by_type_memory_req *request =
	    (struct pldm_read_write_file_by_type_memory_req *)msg->payload;
	*file_type = le16toh(request->file_type);
	*file_handle = le32toh(request->file_handle);
	*offset = le32toh(request->offset);
	*length = le32toh(request->length);
	*address = le64toh(request->address);

	return PLDM_SUCCESS;
}

int encode_rw_file_by_type_memory_resp(uint8_t instance_id, uint8_t command,
				       uint8_t completion_code, uint32_t length,
				       struct pldm_msg *msg)
{
	struct pldm_header_info header = {0};
	int rc = PLDM_SUCCESS;

	if (msg == NULL) {
		return PLDM_ERROR_INVALID_DATA;
	}

	header.msg_type = PLDM_RESPONSE;
	header.instance = instance_id;
	header.pldm_type = PLDM_OEM;
	header.command = command;

	if ((rc = pack_pldm_header(&header, &(msg->hdr))) > PLDM_SUCCESS) {
		return rc;
	}

	struct pldm_read_write_file_by_type_memory_resp *response =
	    (struct pldm_read_write_file_by_type_memory_resp *)msg->payload;
	response->completion_code = completion_code;
	if (response->completion_code == PLDM_SUCCESS) {
		response->length = htole32(length);
	}

	return PLDM_SUCCESS;
}

int encode_rw_file_by_type_memory_req(uint8_t instance_id, uint8_t command,
				      uint16_t file_type, uint32_t file_handle,
				      uint32_t offset, uint32_t length,
				      uint64_t address, struct pldm_msg *msg)
{
	struct pldm_header_info header = {0};
	int rc = PLDM_SUCCESS;

	if (msg == NULL) {
		return PLDM_ERROR_INVALID_DATA;
	}

	header.msg_type = PLDM_REQUEST;
	header.instance = instance_id;
	header.pldm_type = PLDM_OEM;
	header.command = command;

	if ((rc = pack_pldm_header(&header, &(msg->hdr))) > PLDM_SUCCESS) {
		return rc;
	}

	struct pldm_read_write_file_by_type_memory_req *req =
	    (struct pldm_read_write_file_by_type_memory_req *)msg->payload;
	req->file_type = htole16(file_type);
	req->file_handle = htole32(file_handle);
	req->offset = htole32(offset);
	req->length = htole32(length);
	req->address = htole64(address);

	return PLDM_SUCCESS;
}

int decode_rw_file_by_type_memory_resp(const struct pldm_msg *msg,
				       size_t payload_length,
				       uint8_t *completion_code,
				       uint32_t *length)
{
	if (msg == NULL || length == NULL || completion_code == NULL) {
		return PLDM_ERROR_INVALID_DATA;
	}

	if (payload_length != PLDM_RW_FILE_BY_TYPE_MEM_RESP_BYTES) {
		return PLDM_ERROR_INVALID_LENGTH;
	}

	struct pldm_read_write_file_by_type_memory_resp *response =
	    (struct pldm_read_write_file_by_type_memory_resp *)msg->payload;
	*completion_code = response->completion_code;
	if (*completion_code == PLDM_SUCCESS) {
		*length = le32toh(response->length);
	}

	return PLDM_SUCCESS;
}

int decode_new_file_req(const struct pldm_msg *msg, size_t payload_length,
			uint16_t *file_type, uint32_t *file_handle,
			uint64_t *length)
{
	if (msg == NULL || file_type == NULL || file_handle == NULL ||
	    length == NULL) {
		return PLDM_ERROR_INVALID_DATA;
	}

	if (payload_length != PLDM_NEW_FILE_REQ_BYTES) {
		return PLDM_ERROR_INVALID_LENGTH;
	}

	struct pldm_new_file_req *request =
	    (struct pldm_new_file_req *)msg->payload;
	*file_type = le16toh(request->file_type);
	*file_handle = le32toh(request->file_handle);
	*length = le64toh(request->length);

	return PLDM_SUCCESS;
}

int encode_new_file_resp(uint8_t instance_id, uint8_t completion_code,
			 struct pldm_msg *msg)
{
	struct pldm_header_info header = {0};
	int rc = PLDM_SUCCESS;

	if (msg == NULL) {
		return PLDM_ERROR_INVALID_DATA;
	}

	header.msg_type = PLDM_RESPONSE;
	header.instance = instance_id;
	header.pldm_type = PLDM_OEM;
	header.command = PLDM_NEW_FILE_AVAILABLE;

	if ((rc = pack_pldm_header(&header, &(msg->hdr))) > PLDM_SUCCESS) {
		return rc;
	}

	struct pldm_new_file_resp *response =
	    (struct pldm_new_file_resp *)msg->payload;
	response->completion_code = completion_code;

	return PLDM_SUCCESS;
}

int encode_new_file_req(uint8_t instance_id, uint16_t file_type,
			uint32_t file_handle, uint64_t length,
			struct pldm_msg *msg)
{
	struct pldm_header_info header = {0};
	int rc = PLDM_SUCCESS;

	if (msg == NULL) {
		return PLDM_ERROR_INVALID_DATA;
	}

	header.msg_type = PLDM_REQUEST;
	header.instance = instance_id;
	header.pldm_type = PLDM_OEM;
	header.command = PLDM_NEW_FILE_AVAILABLE;

	if ((rc = pack_pldm_header(&header, &(msg->hdr))) > PLDM_SUCCESS) {
		return rc;
	}

	struct pldm_new_file_req *req =
	    (struct pldm_new_file_req *)msg->payload;
	req->file_type = htole16(file_type);
	req->file_handle = htole32(file_handle);
	req->length = htole64(length);

	return PLDM_SUCCESS;
}

int decode_new_file_resp(const struct pldm_msg *msg, size_t payload_length,
			 uint8_t *completion_code)
{
	if (msg == NULL || completion_code == NULL) {
		return PLDM_ERROR_INVALID_DATA;
	}

	if (payload_length != PLDM_NEW_FILE_RESP_BYTES) {
		return PLDM_ERROR_INVALID_LENGTH;
	}

	struct pldm_new_file_resp *response =
	    (struct pldm_new_file_resp *)msg->payload;
	*completion_code = response->completion_code;

	return PLDM_SUCCESS;
}

int decode_rw_file_by_type_req(const struct pldm_msg *msg,
			       size_t payload_length, uint16_t *file_type,
			       uint32_t *file_handle, uint32_t *offset,
			       uint32_t *length)
{
	if (msg == NULL || file_type == NULL || file_handle == NULL ||
	    offset == NULL || length == NULL) {
		return PLDM_ERROR_INVALID_DATA;
	}

	if (payload_length < PLDM_RW_FILE_BY_TYPE_REQ_BYTES) {
		return PLDM_ERROR_INVALID_LENGTH;
	}

	struct pldm_read_write_file_by_type_req *request =
	    (struct pldm_read_write_file_by_type_req *)msg->payload;
	*file_type = le16toh(request->file_type);
	*file_handle = le32toh(request->file_handle);
	*offset = le32toh(request->offset);
	*length = le32toh(request->length);

	return PLDM_SUCCESS;
}

int encode_rw_file_by_type_resp(uint8_t instance_id, uint8_t command,
				uint8_t completion_code, uint32_t length,
				struct pldm_msg *msg)
{
	struct pldm_header_info header = {0};
	int rc = PLDM_SUCCESS;

	if (msg == NULL) {
		return PLDM_ERROR_INVALID_DATA;
	}
	if (command != PLDM_READ_FILE_BY_TYPE &&
	    command != PLDM_WRITE_FILE_BY_TYPE) {
		return PLDM_ERROR_INVALID_DATA;
	}

	header.msg_type = PLDM_RESPONSE;
	header.instance = instance_id;
	header.pldm_type = PLDM_OEM;
	header.command = command;

	if ((rc = pack_pldm_header(&header, &(msg->hdr))) > PLDM_SUCCESS) {
		return rc;
	}

	struct pldm_read_write_file_by_type_resp *response =
	    (struct pldm_read_write_file_by_type_resp *)msg->payload;
	response->completion_code = completion_code;
	if (response->completion_code == PLDM_SUCCESS) {
		response->length = htole32(length);
	}

	return PLDM_SUCCESS;
}

int encode_rw_file_by_type_req(uint8_t instance_id, uint8_t command,
			       uint16_t file_type, uint32_t file_handle,
			       uint32_t offset, uint32_t length,
			       struct pldm_msg *msg)
{
	struct pldm_header_info header = {0};
	int rc = PLDM_SUCCESS;

	if (msg == NULL) {
		return PLDM_ERROR_INVALID_DATA;
	}
	if (command != PLDM_READ_FILE_BY_TYPE &&
	    command != PLDM_WRITE_FILE_BY_TYPE) {
		return PLDM_ERROR_INVALID_DATA;
	}

	header.msg_type = PLDM_REQUEST;
	header.instance = instance_id;
	header.pldm_type = PLDM_OEM;
	header.command = command;

	if ((rc = pack_pldm_header(&header, &(msg->hdr))) > PLDM_SUCCESS) {
		return rc;
	}

	struct pldm_read_write_file_by_type_req *req =
	    (struct pldm_read_write_file_by_type_req *)msg->payload;
	req->file_type = htole16(file_type);
	req->file_handle = htole32(file_handle);
	req->offset = htole32(offset);
	req->length = htole32(length);

	return PLDM_SUCCESS;
}

int decode_rw_file_by_type_resp(const struct pldm_msg *msg,
				size_t payload_length, uint8_t *completion_code,
				uint32_t *length)
{
	if (msg == NULL || length == NULL || completion_code == NULL) {
		return PLDM_ERROR_INVALID_DATA;
	}

	if (payload_length != PLDM_RW_FILE_BY_TYPE_RESP_BYTES) {
		return PLDM_ERROR_INVALID_LENGTH;
	}

	struct pldm_read_write_file_by_type_resp *response =
	    (struct pldm_read_write_file_by_type_resp *)msg->payload;
	*completion_code = response->completion_code;
	if (*completion_code == PLDM_SUCCESS) {
		*length = le32toh(response->length);
	}

	return PLDM_SUCCESS;
}

int decode_file_ack_req(const struct pldm_msg *msg, size_t payload_length,
			uint16_t *file_type, uint32_t *file_handle,
			uint8_t *file_status)
{
	if (msg == NULL || file_type == NULL || file_handle == NULL) {
		return PLDM_ERROR_INVALID_DATA;
	}

	if (payload_length != PLDM_FILE_ACK_REQ_BYTES) {
		return PLDM_ERROR_INVALID_LENGTH;
	}

	struct pldm_file_ack_req *request =
	    (struct pldm_file_ack_req *)msg->payload;
	*file_type = le16toh(request->file_type);
	*file_handle = le32toh(request->file_handle);
	*file_status = request->file_status;

	return PLDM_SUCCESS;
}

int encode_file_ack_resp(uint8_t instance_id, uint8_t completion_code,
			 struct pldm_msg *msg)
{
	struct pldm_header_info header = {0};
	int rc = PLDM_SUCCESS;

	if (msg == NULL) {
		return PLDM_ERROR_INVALID_DATA;
	}

	header.msg_type = PLDM_RESPONSE;
	header.instance = instance_id;
	header.pldm_type = PLDM_OEM;
	header.command = PLDM_FILE_ACK;

	if ((rc = pack_pldm_header(&header, &(msg->hdr))) > PLDM_SUCCESS) {
		return rc;
	}

	struct pldm_file_ack_resp *response =
	    (struct pldm_file_ack_resp *)msg->payload;
	response->completion_code = completion_code;

	return PLDM_SUCCESS;
}

int encode_file_ack_req(uint8_t instance_id, uint16_t file_type,
			uint32_t file_handle, uint8_t file_status,
			struct pldm_msg *msg)
{
	struct pldm_header_info header = {0};
	int rc = PLDM_SUCCESS;

	if (msg == NULL) {
		return PLDM_ERROR_INVALID_DATA;
	}

	header.msg_type = PLDM_REQUEST;
	header.instance = instance_id;
	header.pldm_type = PLDM_OEM;
	header.command = PLDM_FILE_ACK;

	if ((rc = pack_pldm_header(&header, &(msg->hdr))) > PLDM_SUCCESS) {
		return rc;
	}

	struct pldm_file_ack_req *req =
	    (struct pldm_file_ack_req *)msg->payload;
	req->file_type = htole16(file_type);
	req->file_handle = htole32(file_handle);
	req->file_status = file_status;

	return PLDM_SUCCESS;
}

int decode_file_ack_resp(const struct pldm_msg *msg, size_t payload_length,
			 uint8_t *completion_code)
{
	if (msg == NULL || completion_code == NULL) {
		return PLDM_ERROR_INVALID_DATA;
	}

	if (payload_length != PLDM_FILE_ACK_RESP_BYTES) {
		return PLDM_ERROR_INVALID_LENGTH;
	}

	struct pldm_file_ack_resp *response =
	    (struct pldm_file_ack_resp *)msg->payload;
	*completion_code = response->completion_code;

	return PLDM_SUCCESS;
}
