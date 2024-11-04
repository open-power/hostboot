/* SPDX-License-Identifier: Apache-2.0 OR GPL-2.0-or-later */
#include "api.h"
#include "compiler.h"
#include "dsp/base.h"
#include "msgbuf.h"
#include "msgbuf/platform.h"

#include <libpldm/base.h>
#include <libpldm/platform.h>
#include <libpldm/pldm_types.h>

#include <endian.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <uchar.h>

LIBPLDM_ABI_STABLE
int encode_state_effecter_pdr(
	struct pldm_state_effecter_pdr *const effecter,
	const size_t allocation_size,
	const struct state_effecter_possible_states *const possible_states,
	const size_t possible_states_size, size_t *const actual_size)
{
	size_t calculated_possible_states_size = 0;

	if (!effecter || !possible_states || !actual_size) {
		return PLDM_ERROR;
	}

	if (SIZE_MAX - (sizeof(*effecter) - sizeof(effecter->possible_states)) <
			possible_states_size) {
		return PLDM_ERROR;
	}

	if (allocation_size <
	    (sizeof(*effecter) - sizeof(effecter->possible_states)) +
		    possible_states_size) {
		return PLDM_ERROR_INVALID_LENGTH;
	}

	// Encode possible states

	{
		char *states_ptr = (char *)possible_states;
		char *const begin_states_ptr = states_ptr;

		for (int i = 0; i < effecter->composite_effecter_count; ++i) {
			struct state_effecter_possible_states *states =
				(struct state_effecter_possible_states *)
					states_ptr;

			HTOLE16(states->state_set_id);

			states_ptr +=
				(sizeof(*states) - sizeof(states->states) +
				 states->possible_states_size);
		}

		calculated_possible_states_size = states_ptr - begin_states_ptr;
	}

	// Check lengths

	if (possible_states_size != calculated_possible_states_size) {
		*actual_size = 0;
		return PLDM_ERROR;
	}

	*actual_size =
		(sizeof(struct pldm_state_effecter_pdr) + possible_states_size -
		 sizeof(effecter->possible_states));

	// Encode rest of PDR

	effecter->hdr.version = 1;
	effecter->hdr.type = PLDM_STATE_EFFECTER_PDR;
	effecter->hdr.length = *actual_size - sizeof(struct pldm_pdr_hdr);

	memcpy(effecter->possible_states, possible_states,
	       possible_states_size);

	// Convert effecter PDR body
	HTOLE16(effecter->terminus_handle);
	HTOLE16(effecter->effecter_id);
	HTOLE16(effecter->entity_type);
	HTOLE16(effecter->entity_instance);
	HTOLE16(effecter->container_id);
	HTOLE16(effecter->effecter_semantic_id);

	// Convert header
	HTOLE32(effecter->hdr.record_handle);
	HTOLE16(effecter->hdr.record_change_num);
	HTOLE16(effecter->hdr.length);

	return PLDM_SUCCESS;
}

LIBPLDM_ABI_STABLE
int encode_state_sensor_pdr(
	struct pldm_state_sensor_pdr *const sensor,
	const size_t allocation_size,
	const struct state_sensor_possible_states *const possible_states,
	const size_t possible_states_size, size_t *const actual_size)
{
	size_t calculated_possible_states_size = 0;

	if (!sensor || !possible_states || !actual_size) {
		return PLDM_ERROR;
	}

	if (SIZE_MAX - (sizeof(*sensor) - sizeof(sensor->possible_states)) <
	    possible_states_size) {
		return PLDM_ERROR;
	}

	if (allocation_size <
	    (sizeof(*sensor) - sizeof(sensor->possible_states) +
	     possible_states_size)) {
		return PLDM_ERROR_INVALID_LENGTH;
	}

	{
		// Encode possible states
		char *states_ptr = (char *)possible_states;
		char *const begin_states_ptr = states_ptr;

		for (int i = 0; i < sensor->composite_sensor_count; ++i) {
			struct state_sensor_possible_states *states =
				(struct state_sensor_possible_states *)
					states_ptr;

			HTOLE16(states->state_set_id);

			states_ptr +=
				(sizeof(*states) - sizeof(states->states) +
				 states->possible_states_size);
		}

		calculated_possible_states_size = states_ptr - begin_states_ptr;
	}

	// Check lengths

	if (possible_states_size != calculated_possible_states_size) {
		*actual_size = 0;
		return PLDM_ERROR;
	}

	*actual_size = (sizeof(struct pldm_state_sensor_pdr) +
			possible_states_size - sizeof(sensor->possible_states));

	// Encode rest of PDR

	sensor->hdr.version = 1;
	sensor->hdr.type = PLDM_STATE_SENSOR_PDR;
	sensor->hdr.length = *actual_size - sizeof(struct pldm_pdr_hdr);

	memcpy(sensor->possible_states, possible_states, possible_states_size);

	// Convert sensor PDR body
	HTOLE16(sensor->terminus_handle);
	HTOLE16(sensor->sensor_id);
	HTOLE16(sensor->entity_type);
	HTOLE16(sensor->entity_instance);
	HTOLE16(sensor->container_id);

	// Convert header
	HTOLE32(sensor->hdr.record_handle);
	HTOLE16(sensor->hdr.record_change_num);
	HTOLE16(sensor->hdr.length);

	return PLDM_SUCCESS;
}

LIBPLDM_ABI_STABLE
int encode_set_state_effecter_states_resp(uint8_t instance_id,
					  uint8_t completion_code,
					  struct pldm_msg *msg)
{
	if (msg == NULL) {
		return PLDM_ERROR_INVALID_DATA;
	}

	struct pldm_header_info header = { 0 };
	header.msg_type = PLDM_RESPONSE;
	header.instance = instance_id;
	header.pldm_type = PLDM_PLATFORM;
	header.command = PLDM_SET_STATE_EFFECTER_STATES;

	uint8_t rc = pack_pldm_header(&header, &(msg->hdr));
	if (rc != PLDM_SUCCESS) {
		return rc;
	}

	msg->payload[0] = completion_code;

	return PLDM_SUCCESS;
}

LIBPLDM_ABI_STABLE
int encode_set_state_effecter_states_req(uint8_t instance_id,
					 uint16_t effecter_id,
					 uint8_t comp_effecter_count,
					 set_effecter_state_field *field,
					 struct pldm_msg *msg)
{
	if (msg == NULL) {
		return PLDM_ERROR_INVALID_DATA;
	}

	if (comp_effecter_count < 0x1 || comp_effecter_count > 0x8 ||
	    field == NULL) {
		return PLDM_ERROR_INVALID_DATA;
	}

	struct pldm_header_info header = { 0 };
	header.msg_type = PLDM_REQUEST;
	header.instance = instance_id;
	header.pldm_type = PLDM_PLATFORM;
	header.command = PLDM_SET_STATE_EFFECTER_STATES;

	uint8_t rc = pack_pldm_header(&header, &(msg->hdr));
	if (rc != PLDM_SUCCESS) {
		return rc;
	}

	struct pldm_set_state_effecter_states_req *request =
		(struct pldm_set_state_effecter_states_req *)msg->payload;
	effecter_id = htole16(effecter_id);
	request->effecter_id = effecter_id;
	request->comp_effecter_count = comp_effecter_count;
	memcpy(request->field, field,
	       (sizeof(set_effecter_state_field) * comp_effecter_count));

	return PLDM_SUCCESS;
}

LIBPLDM_ABI_STABLE
int decode_set_state_effecter_states_resp(const struct pldm_msg *msg,
					  size_t payload_length,
					  uint8_t *completion_code)
{
	if (msg == NULL || completion_code == NULL) {
		return PLDM_ERROR_INVALID_DATA;
	}

	*completion_code = msg->payload[0];
	if (PLDM_SUCCESS != *completion_code) {
		return PLDM_SUCCESS;
	}

	if (payload_length > PLDM_SET_STATE_EFFECTER_STATES_RESP_BYTES) {
		return PLDM_ERROR_INVALID_LENGTH;
	}

	return PLDM_SUCCESS;
}

#define PLDM_SET_STATE_EFFECTER_STATES_MIN_SIZE 3
LIBPLDM_ABI_STABLE
int decode_set_state_effecter_states_req(const struct pldm_msg *msg,
					 size_t payload_length,
					 uint16_t *effecter_id,
					 uint8_t *comp_effecter_count,
					 set_effecter_state_field *field)
{
	struct pldm_msgbuf _buf;
	struct pldm_msgbuf *buf = &_buf;
	int rc;
	int i;

	if (msg == NULL || effecter_id == NULL || comp_effecter_count == NULL ||
	    field == NULL) {
		return PLDM_ERROR_INVALID_DATA;
	}

	if (payload_length > PLDM_SET_STATE_EFFECTER_STATES_REQ_BYTES) {
		return PLDM_ERROR_INVALID_LENGTH;
	}

	rc = pldm_msgbuf_init_errno(buf,
				    PLDM_SET_STATE_EFFECTER_STATES_MIN_SIZE,
				    msg->payload, payload_length);
	if (rc) {
		return pldm_xlate_errno(rc);
	}

	pldm_msgbuf_extract_p(buf, effecter_id);
	pldm_msgbuf_extract_p(buf, comp_effecter_count);

	if (*comp_effecter_count > 8) {
		return PLDM_ERROR_INVALID_DATA;
	}

	for (i = 0; i < *comp_effecter_count; i++) {
		pldm_msgbuf_extract(buf, field[i].set_request);
		pldm_msgbuf_extract(buf, field[i].effecter_state);
	}

	rc = pldm_msgbuf_destroy(buf);
	if (rc) {
		return pldm_xlate_errno(rc);
	}

	return PLDM_SUCCESS;
}

LIBPLDM_ABI_STABLE
int decode_get_pdr_req(const struct pldm_msg *msg, size_t payload_length,
		       uint32_t *record_hndl, uint32_t *data_transfer_hndl,
		       uint8_t *transfer_op_flag, uint16_t *request_cnt,
		       uint16_t *record_chg_num)
{
	struct pldm_msgbuf _buf;
	struct pldm_msgbuf *buf = &_buf;
	int rc;

	if (msg == NULL || record_hndl == NULL || data_transfer_hndl == NULL ||
	    transfer_op_flag == NULL || request_cnt == NULL ||
	    record_chg_num == NULL) {
		return PLDM_ERROR_INVALID_DATA;
	}

	if (payload_length != PLDM_GET_PDR_REQ_BYTES) {
		return PLDM_ERROR_INVALID_LENGTH;
	}

	rc = pldm_msgbuf_init_errno(buf, PLDM_GET_PDR_REQ_BYTES, msg->payload,
				    payload_length);
	if (rc) {
		return pldm_xlate_errno(rc);
	}

	pldm_msgbuf_extract_p(buf, record_hndl);
	pldm_msgbuf_extract_p(buf, data_transfer_hndl);
	pldm_msgbuf_extract_p(buf, transfer_op_flag);
	pldm_msgbuf_extract_p(buf, request_cnt);
	pldm_msgbuf_extract_p(buf, record_chg_num);

	rc = pldm_msgbuf_destroy(buf);
	if (rc) {
		return pldm_xlate_errno(rc);
	}

	return PLDM_SUCCESS;
}

LIBPLDM_ABI_DEPRECATED_UNSAFE
int encode_get_pdr_resp(uint8_t instance_id, uint8_t completion_code,
			uint32_t next_record_hndl,
			uint32_t next_data_transfer_hndl, uint8_t transfer_flag,
			uint16_t resp_cnt, const uint8_t *record_data,
			uint8_t transfer_crc, struct pldm_msg *msg)
{
	if (msg == NULL) {
		return PLDM_ERROR_INVALID_DATA;
	}

	struct pldm_header_info header = { 0 };
	header.msg_type = PLDM_RESPONSE;
	header.instance = instance_id;
	header.pldm_type = PLDM_PLATFORM;
	header.command = PLDM_GET_PDR;

	uint8_t rc = pack_pldm_header(&header, &(msg->hdr));
	if (rc != PLDM_SUCCESS) {
		return rc;
	}

	struct pldm_get_pdr_resp *response =
		(struct pldm_get_pdr_resp *)msg->payload;
	response->completion_code = completion_code;

	if (response->completion_code == PLDM_SUCCESS) {
		response->next_record_handle = htole32(next_record_hndl);
		response->next_data_transfer_handle =
			htole32(next_data_transfer_hndl);
		response->transfer_flag = transfer_flag;
		response->response_count = htole16(resp_cnt);
		if (record_data != NULL && resp_cnt > 0) {
			memcpy(response->record_data, record_data, resp_cnt);
		}
		if (transfer_flag == PLDM_END) {
			uint8_t *dst = msg->payload;
			dst += (sizeof(struct pldm_get_pdr_resp) - 1) +
			       resp_cnt;
			*dst = transfer_crc;
		}
	}

	return PLDM_SUCCESS;
}

LIBPLDM_ABI_STABLE
int encode_get_pdr_repository_info_resp(
	uint8_t instance_id, uint8_t completion_code, uint8_t repository_state,
	const uint8_t *update_time, const uint8_t *oem_update_time,
	uint32_t record_count, uint32_t repository_size,
	uint32_t largest_record_size, uint8_t data_transfer_handle_timeout,
	struct pldm_msg *msg)
{
	if (msg == NULL) {
		return PLDM_ERROR_INVALID_DATA;
	}

	struct pldm_header_info header = { 0 };
	header.msg_type = PLDM_RESPONSE;
	header.instance = instance_id;
	header.pldm_type = PLDM_PLATFORM;
	header.command = PLDM_GET_PDR_REPOSITORY_INFO;

	uint8_t rc = pack_pldm_header(&header, &(msg->hdr));
	if (rc != PLDM_SUCCESS) {
		return rc;
	}

	struct pldm_pdr_repository_info_resp *response =
		(struct pldm_pdr_repository_info_resp *)msg->payload;
	response->completion_code = completion_code;

	if (response->completion_code == PLDM_SUCCESS) {
		response->repository_state = repository_state;
		if (update_time != NULL) {
			memcpy(response->update_time, update_time,
			       PLDM_TIMESTAMP104_SIZE);
		}
		if (oem_update_time != NULL) {
			memcpy(response->oem_update_time, oem_update_time,
			       PLDM_TIMESTAMP104_SIZE);
		}
		response->record_count = htole32(record_count);
		response->repository_size = htole32(repository_size);
		response->largest_record_size = htole32(largest_record_size);
		response->data_transfer_handle_timeout =
			data_transfer_handle_timeout;
	}

	return PLDM_SUCCESS;
}

LIBPLDM_ABI_DEPRECATED
int decode_get_pdr_repository_info_resp(
	const struct pldm_msg *msg, size_t payload_length,
	uint8_t *completion_code, uint8_t *repository_state,
	uint8_t *update_time, uint8_t *oem_update_time, uint32_t *record_count,
	uint32_t *repository_size, uint32_t *largest_record_size,
	uint8_t *data_transfer_handle_timeout)
{
	struct pldm_msgbuf _buf;
	struct pldm_msgbuf *buf = &_buf;
	int rc;

	if (msg == NULL || completion_code == NULL ||
	    repository_state == NULL || update_time == NULL ||
	    oem_update_time == NULL || record_count == NULL ||
	    repository_size == NULL || largest_record_size == NULL ||
	    data_transfer_handle_timeout == NULL) {
		return PLDM_ERROR_INVALID_DATA;
	}

	rc = pldm_msgbuf_init_errno(buf,
				    PLDM_GET_PDR_REPOSITORY_INFO_RESP_BYTES,
				    msg->payload, payload_length);
	if (rc) {
		return pldm_xlate_errno(rc);
	}

	pldm_msgbuf_extract_p(buf, completion_code);
	if (PLDM_SUCCESS != *completion_code) {
		return PLDM_SUCCESS;
	}

	rc = pldm_msgbuf_extract_p(buf, repository_state);
	if (rc) {
		return pldm_xlate_errno(rc);
	}

	if (*repository_state > PLDM_FAILED) {
		return PLDM_ERROR_INVALID_DATA;
	}

	/* NOTE: Memory safety */
	rc = pldm_msgbuf_extract_array(buf, PLDM_TIMESTAMP104_SIZE, update_time,
				       PLDM_TIMESTAMP104_SIZE);
	if (rc) {
		return pldm_xlate_errno(rc);
	}

	/* NOTE: Memory safety */
	rc = pldm_msgbuf_extract_array(buf, PLDM_TIMESTAMP104_SIZE,
				       oem_update_time, PLDM_TIMESTAMP104_SIZE);
	if (rc) {
		return pldm_xlate_errno(rc);
	}

	pldm_msgbuf_extract_p(buf, record_count);
	pldm_msgbuf_extract_p(buf, repository_size);
	pldm_msgbuf_extract_p(buf, largest_record_size);
	pldm_msgbuf_extract_p(buf, data_transfer_handle_timeout);

	rc = pldm_msgbuf_destroy(buf);
	if (rc) {
		return pldm_xlate_errno(rc);
	}

	return PLDM_SUCCESS;
}

LIBPLDM_ABI_TESTING
int decode_get_pdr_repository_info_resp_safe(
	const struct pldm_msg *msg, size_t payload_length,
	struct pldm_pdr_repository_info_resp *resp)
{
	struct pldm_msgbuf _buf;
	struct pldm_msgbuf *buf = &_buf;
	int rc;

	if (msg == NULL || resp == NULL) {
		return -EINVAL;
	}

	rc = pldm_msg_has_error(msg, payload_length);
	if (rc) {
		resp->completion_code = rc;
		return 0;
	}

	rc = pldm_msgbuf_init_errno(buf,
				    PLDM_GET_PDR_REPOSITORY_INFO_RESP_BYTES,
				    msg->payload, payload_length);
	if (rc) {
		return rc;
	}

	rc = pldm_msgbuf_extract(buf, resp->completion_code);
	if (rc) {
		return rc;
	}

	pldm_msgbuf_extract(buf, resp->repository_state);

	rc = pldm_msgbuf_extract_array(buf, sizeof(resp->update_time),
				       resp->update_time,
				       sizeof(resp->update_time));
	if (rc) {
		return rc;
	}

	rc = pldm_msgbuf_extract_array(buf, sizeof(resp->oem_update_time),
				       resp->oem_update_time,
				       sizeof(resp->oem_update_time));
	if (rc) {
		return rc;
	}

	pldm_msgbuf_extract(buf, resp->record_count);
	pldm_msgbuf_extract(buf, resp->repository_size);
	pldm_msgbuf_extract(buf, resp->largest_record_size);
	pldm_msgbuf_extract(buf, resp->data_transfer_handle_timeout);

	return pldm_msgbuf_destroy_consumed(buf);
}

LIBPLDM_ABI_STABLE
int encode_get_pdr_req(uint8_t instance_id, uint32_t record_hndl,
		       uint32_t data_transfer_hndl, uint8_t transfer_op_flag,
		       uint16_t request_cnt, uint16_t record_chg_num,
		       struct pldm_msg *msg, size_t payload_length)
{
	if (msg == NULL) {
		return PLDM_ERROR_INVALID_DATA;
	}

	if (payload_length != PLDM_GET_PDR_REQ_BYTES) {
		return PLDM_ERROR_INVALID_LENGTH;
	}

	struct pldm_header_info header = { 0 };
	header.msg_type = PLDM_REQUEST;
	header.instance = instance_id;
	header.pldm_type = PLDM_PLATFORM;
	header.command = PLDM_GET_PDR;

	uint8_t rc = pack_pldm_header(&header, &(msg->hdr));
	if (rc != PLDM_SUCCESS) {
		return rc;
	}

	struct pldm_get_pdr_req *request =
		(struct pldm_get_pdr_req *)msg->payload;
	request->record_handle = htole32(record_hndl);
	request->data_transfer_handle = htole32(data_transfer_hndl);
	request->transfer_op_flag = transfer_op_flag;
	request->request_count = htole16(request_cnt);
	request->record_change_number = htole16(record_chg_num);

	return PLDM_SUCCESS;
}

LIBPLDM_ABI_DEPRECATED
int decode_get_pdr_resp(const struct pldm_msg *msg, size_t payload_length,
			uint8_t *completion_code, uint32_t *next_record_hndl,
			uint32_t *next_data_transfer_hndl,
			uint8_t *transfer_flag, uint16_t *resp_cnt,
			uint8_t *record_data, size_t record_data_length,
			uint8_t *transfer_crc)
{
	struct pldm_msgbuf _buf;
	struct pldm_msgbuf *buf = &_buf;
	int rc;

	if (msg == NULL || completion_code == NULL ||
	    next_record_hndl == NULL || next_data_transfer_hndl == NULL ||
	    transfer_flag == NULL || resp_cnt == NULL || transfer_crc == NULL) {
		return PLDM_ERROR_INVALID_DATA;
	}

	rc = pldm_msgbuf_init_errno(buf, PLDM_GET_PDR_MIN_RESP_BYTES,
				    msg->payload, payload_length);
	if (rc) {
		return pldm_xlate_errno(rc);
	}

	rc = pldm_msgbuf_extract_p(buf, completion_code);
	if (rc) {
		return pldm_xlate_errno(rc);
	}

	if (PLDM_SUCCESS != *completion_code) {
		return PLDM_SUCCESS;
	}

	pldm_msgbuf_extract_p(buf, next_record_hndl);
	pldm_msgbuf_extract_p(buf, next_data_transfer_hndl);
	pldm_msgbuf_extract_p(buf, transfer_flag);
	rc = pldm_msgbuf_extract_p(buf, resp_cnt);
	if (rc) {
		return pldm_xlate_errno(rc);
	}

	if (*resp_cnt > 0 && record_data != NULL) {
		if (record_data_length < *resp_cnt) {
			return PLDM_ERROR_INVALID_LENGTH;
		}
		/* NOTE: Memory safety */
		rc = pldm_msgbuf_extract_array(buf, *resp_cnt, record_data,
					       *resp_cnt);
		if (rc) {
			return pldm_xlate_errno(rc);
		}
	}

	if (*transfer_flag == PLDM_END) {
		pldm_msgbuf_extract_p(buf, transfer_crc);
	}

	rc = pldm_msgbuf_destroy(buf);
	if (rc) {
		return pldm_xlate_errno(rc);
	}

	return PLDM_SUCCESS;
}

LIBPLDM_ABI_TESTING
int decode_get_pdr_resp_safe(const struct pldm_msg *msg, size_t payload_length,
			     struct pldm_get_pdr_resp *resp, size_t resp_len,
			     uint8_t *transfer_crc)
{
	struct pldm_msgbuf _buf;
	struct pldm_msgbuf *buf = &_buf;
	int rc;

	if (msg == NULL || resp == NULL || transfer_crc == NULL) {
		return -EINVAL;
	}

	rc = pldm_msg_has_error(msg, payload_length);
	if (rc) {
		resp->completion_code = rc;
		return 0;
	}

	rc = pldm_msgbuf_init_errno(buf, PLDM_GET_PDR_MIN_RESP_BYTES,
				    msg->payload, payload_length);
	if (rc) {
		return rc;
	}

	pldm_msgbuf_extract(buf, resp->completion_code);
	pldm_msgbuf_extract(buf, resp->next_record_handle);
	pldm_msgbuf_extract(buf, resp->next_data_transfer_handle);

	rc = pldm_msgbuf_extract(buf, resp->transfer_flag);
	if (rc) {
		return rc;
	}

	rc = pldm_msgbuf_extract(buf, resp->response_count);
	if (rc) {
		return rc;
	}

	rc = pldm_msgbuf_extract_array(
		buf, resp->response_count, resp->record_data,
		resp_len - (sizeof(*resp) - sizeof(resp->record_data)));
	if (rc) {
		return rc;
	}

	if (resp->transfer_flag == PLDM_END) {
		pldm_msgbuf_extract_p(buf, transfer_crc);
	}

	return pldm_msgbuf_destroy_consumed(buf);
}

LIBPLDM_ABI_STABLE
int decode_set_numeric_effecter_value_req(const struct pldm_msg *msg,
					  size_t payload_length,
					  uint16_t *effecter_id,
					  uint8_t *effecter_data_size,
					  uint8_t effecter_value[4])
{
	struct pldm_msgbuf _buf;
	struct pldm_msgbuf *buf = &_buf;
	int rc;

	if (msg == NULL || effecter_id == NULL || effecter_data_size == NULL ||
	    effecter_value == NULL) {
		return PLDM_ERROR_INVALID_DATA;
	}

	rc = pldm_msgbuf_init_errno(
		buf, PLDM_SET_NUMERIC_EFFECTER_VALUE_MIN_REQ_BYTES,
		msg->payload, payload_length);
	if (rc) {
		return pldm_xlate_errno(rc);
	}

	pldm_msgbuf_extract_p(buf, effecter_id);
	rc = pldm_msgbuf_extract_p(buf, effecter_data_size);
	if (rc) {
		return PLDM_ERROR_INVALID_DATA;
	}

	if (*effecter_data_size > PLDM_EFFECTER_DATA_SIZE_SINT32) {
		return PLDM_ERROR_INVALID_DATA;
	}

	pldm_msgbuf_extract_effecter_value(buf, *effecter_data_size,
					   effecter_value);

	rc = pldm_msgbuf_destroy(buf);
	if (rc) {
		return pldm_xlate_errno(rc);
	}

	return PLDM_SUCCESS;
}

LIBPLDM_ABI_STABLE
int encode_set_numeric_effecter_value_resp(uint8_t instance_id,
					   uint8_t completion_code,
					   struct pldm_msg *msg,
					   size_t payload_length)
{
	if (msg == NULL) {
		return PLDM_ERROR_INVALID_DATA;
	}

	if (payload_length != PLDM_SET_NUMERIC_EFFECTER_VALUE_RESP_BYTES) {
		return PLDM_ERROR_INVALID_LENGTH;
	}

	struct pldm_header_info header = { 0 };
	header.msg_type = PLDM_RESPONSE;
	header.instance = instance_id;
	header.pldm_type = PLDM_PLATFORM;
	header.command = PLDM_SET_NUMERIC_EFFECTER_VALUE;

	uint8_t rc = pack_pldm_header(&header, &(msg->hdr));
	if (rc != PLDM_SUCCESS) {
		return rc;
	}

	msg->payload[0] = completion_code;

	return rc;
}

LIBPLDM_ABI_STABLE
int encode_set_numeric_effecter_value_req(uint8_t instance_id,
					  uint16_t effecter_id,
					  uint8_t effecter_data_size,
					  const uint8_t *effecter_value,
					  struct pldm_msg *msg,
					  size_t payload_length)
{
	if (msg == NULL || effecter_value == NULL) {
		return PLDM_ERROR_INVALID_DATA;
	}

	if (effecter_data_size > PLDM_EFFECTER_DATA_SIZE_SINT32) {
		return PLDM_ERROR_INVALID_DATA;
	}

	struct pldm_header_info header = { 0 };
	header.msg_type = PLDM_REQUEST;
	header.instance = instance_id;
	header.pldm_type = PLDM_PLATFORM;
	header.command = PLDM_SET_NUMERIC_EFFECTER_VALUE;

	uint8_t rc = pack_pldm_header(&header, &(msg->hdr));
	if (rc != PLDM_SUCCESS) {
		return rc;
	}

	struct pldm_set_numeric_effecter_value_req *request =
		(struct pldm_set_numeric_effecter_value_req *)msg->payload;
	if (effecter_data_size == PLDM_EFFECTER_DATA_SIZE_UINT8 ||
	    effecter_data_size == PLDM_EFFECTER_DATA_SIZE_SINT8) {
		if (payload_length !=
		    PLDM_SET_NUMERIC_EFFECTER_VALUE_MIN_REQ_BYTES) {
			return PLDM_ERROR_INVALID_LENGTH;
		}
		request->effecter_value[0] = *effecter_value;
	} else if (effecter_data_size == PLDM_EFFECTER_DATA_SIZE_UINT16 ||
		   effecter_data_size == PLDM_EFFECTER_DATA_SIZE_SINT16) {
		if (payload_length !=
		    PLDM_SET_NUMERIC_EFFECTER_VALUE_MIN_REQ_BYTES + 1) {
			return PLDM_ERROR_INVALID_LENGTH;
		}

		uint16_t val = *(uint16_t *)(effecter_value);
		val = htole16(val);
		memcpy(request->effecter_value, &val, sizeof(uint16_t));

	} else if (effecter_data_size == PLDM_EFFECTER_DATA_SIZE_UINT32 ||
		   effecter_data_size == PLDM_EFFECTER_DATA_SIZE_SINT32) {
		if (payload_length !=
		    PLDM_SET_NUMERIC_EFFECTER_VALUE_MIN_REQ_BYTES + 3) {
			return PLDM_ERROR_INVALID_LENGTH;
		}

		uint32_t val = *(uint32_t *)(effecter_value);
		val = htole32(val);
		memcpy(request->effecter_value, &val, sizeof(uint32_t));
	}

	request->effecter_id = htole16(effecter_id);
	request->effecter_data_size = effecter_data_size;

	return PLDM_SUCCESS;
}

LIBPLDM_ABI_STABLE
int decode_set_numeric_effecter_value_resp(const struct pldm_msg *msg,
					   size_t payload_length,
					   uint8_t *completion_code)
{
	if (msg == NULL || completion_code == NULL) {
		return PLDM_ERROR_INVALID_DATA;
	}

	if (payload_length != PLDM_SET_NUMERIC_EFFECTER_VALUE_RESP_BYTES) {
		return PLDM_ERROR_INVALID_LENGTH;
	}

	*completion_code = msg->payload[0];

	return PLDM_SUCCESS;
}

LIBPLDM_ABI_STABLE
int encode_get_state_sensor_readings_resp(uint8_t instance_id,
					  uint8_t completion_code,
					  uint8_t comp_sensor_count,
					  get_sensor_state_field *field,
					  struct pldm_msg *msg)
{
	if (msg == NULL) {
		return PLDM_ERROR_INVALID_DATA;
	}

	if (comp_sensor_count < 0x1 || comp_sensor_count > 0x8) {
		return PLDM_ERROR_INVALID_DATA;
	}

	struct pldm_header_info header = { 0 };
	header.msg_type = PLDM_RESPONSE;
	header.instance = instance_id;
	header.pldm_type = PLDM_PLATFORM;
	header.command = PLDM_GET_STATE_SENSOR_READINGS;

	uint8_t rc = pack_pldm_header(&header, &(msg->hdr));
	if (rc != PLDM_SUCCESS) {
		return rc;
	}

	struct pldm_get_state_sensor_readings_resp *response =
		(struct pldm_get_state_sensor_readings_resp *)msg->payload;

	response->completion_code = completion_code;
	response->comp_sensor_count = comp_sensor_count;
	memcpy(response->field, field,
	       (sizeof(get_sensor_state_field) * comp_sensor_count));

	return PLDM_SUCCESS;
}

LIBPLDM_ABI_STABLE
int encode_get_state_sensor_readings_req(uint8_t instance_id,
					 uint16_t sensor_id,
					 bitfield8_t sensor_rearm,
					 uint8_t reserved, struct pldm_msg *msg)
{
	if (msg == NULL) {
		return PLDM_ERROR_INVALID_DATA;
	}

	struct pldm_header_info header = { 0 };
	header.msg_type = PLDM_REQUEST;
	header.instance = instance_id;
	header.pldm_type = PLDM_PLATFORM;
	header.command = PLDM_GET_STATE_SENSOR_READINGS;

	uint8_t rc = pack_pldm_header(&header, &(msg->hdr));
	if (rc != PLDM_SUCCESS) {
		return rc;
	}

	struct pldm_get_state_sensor_readings_req *request =
		(struct pldm_get_state_sensor_readings_req *)msg->payload;

	request->sensor_id = htole16(sensor_id);
	request->reserved = reserved;
	request->sensor_rearm = sensor_rearm;

	return PLDM_SUCCESS;
}

LIBPLDM_ABI_STABLE
int decode_get_state_sensor_readings_resp(const struct pldm_msg *msg,
					  size_t payload_length,
					  uint8_t *completion_code,
					  uint8_t *comp_sensor_count,
					  get_sensor_state_field *field)
{
	struct pldm_msgbuf _buf;
	struct pldm_msgbuf *buf = &_buf;
	uint8_t i;
	int rc;

	if (msg == NULL || completion_code == NULL ||
	    comp_sensor_count == NULL || field == NULL) {
		return PLDM_ERROR_INVALID_DATA;
	}

	rc = pldm_msgbuf_init_errno(
		buf, PLDM_GET_STATE_SENSOR_READINGS_MIN_RESP_BYTES,
		msg->payload, payload_length);
	if (rc) {
		return pldm_xlate_errno(rc);
	}

	rc = pldm_msgbuf_extract_p(buf, completion_code);
	if (rc) {
		return pldm_xlate_errno(rc);
	}

	if (PLDM_SUCCESS != *completion_code) {
		return PLDM_SUCCESS;
	}

	rc = pldm_msgbuf_extract_p(buf, comp_sensor_count);
	if (rc) {
		return pldm_xlate_errno(rc);
	}

	if (*comp_sensor_count < 0x1 || *comp_sensor_count > 0x8) {
		return PLDM_ERROR_INVALID_DATA;
	}

	for (i = 0; i < *comp_sensor_count; i++) {
		pldm_msgbuf_extract(buf, field[i].sensor_op_state);
		pldm_msgbuf_extract(buf, field[i].present_state);
		pldm_msgbuf_extract(buf, field[i].previous_state);
		pldm_msgbuf_extract(buf, field[i].event_state);
	}

	rc = pldm_msgbuf_destroy_consumed(buf);
	if (rc) {
		return pldm_xlate_errno(rc);
	}

	return PLDM_SUCCESS;
}

LIBPLDM_ABI_STABLE
int decode_get_state_sensor_readings_req(const struct pldm_msg *msg,
					 size_t payload_length,
					 uint16_t *sensor_id,
					 bitfield8_t *sensor_rearm,
					 uint8_t *reserved)
{
	struct pldm_msgbuf _buf;
	struct pldm_msgbuf *buf = &_buf;
	int rc;

	if (msg == NULL || sensor_id == NULL || sensor_rearm == NULL) {
		return PLDM_ERROR_INVALID_DATA;
	}

	rc = pldm_msgbuf_init_errno(buf,
				    PLDM_GET_STATE_SENSOR_READINGS_REQ_BYTES,
				    msg->payload, payload_length);
	if (rc) {
		return pldm_xlate_errno(rc);
	}

	pldm_msgbuf_extract_p(buf, sensor_id);
	pldm_msgbuf_extract(buf, sensor_rearm->byte);
	pldm_msgbuf_extract_p(buf, reserved);

	rc = pldm_msgbuf_destroy(buf);
	if (rc) {
		return pldm_xlate_errno(rc);
	}

	return PLDM_SUCCESS;
}

LIBPLDM_ABI_STABLE
int encode_sensor_event_data(
	struct pldm_sensor_event_data *const event_data,
	const size_t event_data_size, const uint16_t sensor_id,
	const enum sensor_event_class_states sensor_event_class,
	const uint8_t sensor_offset, const uint8_t event_state,
	const uint8_t previous_event_state,
	size_t *const actual_event_data_size)
{
	*actual_event_data_size =
		(sizeof(*event_data) - sizeof(event_data->event_class) +
		 sizeof(struct pldm_sensor_event_state_sensor_state));

	if (!event_data) {
		return PLDM_SUCCESS;
	}

	if (event_data_size < *actual_event_data_size) {
		*actual_event_data_size = 0;
		return PLDM_ERROR_INVALID_LENGTH;
	}

	event_data->sensor_id = htole16(sensor_id);
	event_data->sensor_event_class_type = sensor_event_class;

	struct pldm_sensor_event_state_sensor_state *const state_data =
		(struct pldm_sensor_event_state_sensor_state *)
			event_data->event_class;

	state_data->sensor_offset = sensor_offset;
	state_data->event_state = event_state;
	state_data->previous_event_state = previous_event_state;

	return PLDM_SUCCESS;
}

LIBPLDM_ABI_STABLE
int decode_platform_event_message_req(const struct pldm_msg *msg,
				      size_t payload_length,
				      uint8_t *format_version, uint8_t *tid,
				      uint8_t *event_class,
				      size_t *event_data_offset)
{
	struct pldm_msgbuf _buf;
	struct pldm_msgbuf *buf = &_buf;
	int rc;

	if (msg == NULL || format_version == NULL || tid == NULL ||
	    event_class == NULL || event_data_offset == NULL) {
		return PLDM_ERROR_INVALID_DATA;
	}

	rc = pldm_msgbuf_init_errno(buf,
				    PLDM_PLATFORM_EVENT_MESSAGE_MIN_REQ_BYTES,
				    msg->payload, payload_length);
	if (rc) {
		return pldm_xlate_errno(rc);
	}

	pldm_msgbuf_extract_p(buf, format_version);
	pldm_msgbuf_extract_p(buf, tid);
	pldm_msgbuf_extract_p(buf, event_class);

	rc = pldm_msgbuf_destroy(buf);
	if (rc) {
		return pldm_xlate_errno(rc);
	}

	*event_data_offset =
		sizeof(*format_version) + sizeof(*tid) + sizeof(*event_class);

	return PLDM_SUCCESS;
}

static int pldm_platform_poll_for_platform_event_message_validate(
	uint8_t transfer_operation_flag, uint16_t event_id_to_acknowledge)
{
	if (((transfer_operation_flag == PLDM_GET_FIRSTPART) &&
	     (event_id_to_acknowledge != PLDM_PLATFORM_EVENT_ID_NULL)) ||
	    ((transfer_operation_flag == PLDM_GET_NEXTPART) &&
	     (event_id_to_acknowledge != PLDM_PLATFORM_EVENT_ID_FRAGMENT)) ||
	    ((transfer_operation_flag == PLDM_ACKNOWLEDGEMENT_ONLY) &&
	     (event_id_to_acknowledge == PLDM_PLATFORM_EVENT_ID_FRAGMENT)) ||
	    ((transfer_operation_flag == PLDM_ACKNOWLEDGEMENT_ONLY) &&
	     (event_id_to_acknowledge == PLDM_PLATFORM_EVENT_ID_NULL)) ||
	    (transfer_operation_flag > PLDM_ACKNOWLEDGEMENT_ONLY)) {
		return -EPROTO;
	}

	return 0;
}

LIBPLDM_ABI_STABLE
int decode_poll_for_platform_event_message_req(
	const struct pldm_msg *msg, size_t payload_length,
	uint8_t *format_version, uint8_t *transfer_operation_flag,
	uint32_t *data_transfer_handle, uint16_t *event_id_to_acknowledge)
{
	struct pldm_msgbuf _buf;
	struct pldm_msgbuf *buf = &_buf;
	int rc;

	if (msg == NULL || format_version == NULL ||
	    transfer_operation_flag == NULL || data_transfer_handle == NULL ||
	    event_id_to_acknowledge == NULL) {
		return PLDM_ERROR_INVALID_DATA;
	}

	rc = pldm_msgbuf_init_errno(
		buf, PLDM_POLL_FOR_PLATFORM_EVENT_MESSAGE_REQ_BYTES,
		msg->payload, payload_length);
	if (rc) {
		return pldm_xlate_errno(rc);
	}

	pldm_msgbuf_extract_p(buf, format_version);
	rc = pldm_msgbuf_extract_p(buf, transfer_operation_flag);
	if (rc) {
		return pldm_xlate_errno(rc);
	}
	if (*transfer_operation_flag > PLDM_ACKNOWLEDGEMENT_ONLY) {
		return PLDM_ERROR_INVALID_DATA;
	}

	pldm_msgbuf_extract_p(buf, data_transfer_handle);
	rc = pldm_msgbuf_extract_p(buf, event_id_to_acknowledge);
	if (rc) {
		return pldm_xlate_errno(rc);
	}

	rc = pldm_platform_poll_for_platform_event_message_validate(
		*transfer_operation_flag, *event_id_to_acknowledge);
	if (rc < 0) {
		return PLDM_ERROR_INVALID_DATA;
	}

	rc = pldm_msgbuf_destroy(buf);
	if (rc) {
		return pldm_xlate_errno(rc);
	}

	return PLDM_SUCCESS;
}

LIBPLDM_ABI_STABLE
int encode_platform_event_message_resp(uint8_t instance_id,
				       uint8_t completion_code,
				       uint8_t platform_event_status,
				       struct pldm_msg *msg)
{
	if (msg == NULL) {
		return PLDM_ERROR_INVALID_DATA;
	}

	if (platform_event_status > PLDM_EVENT_LOGGING_REJECTED) {
		return PLDM_ERROR_INVALID_DATA;
	}

	struct pldm_header_info header = { 0 };
	header.msg_type = PLDM_RESPONSE;
	header.instance = instance_id;
	header.pldm_type = PLDM_PLATFORM;
	header.command = PLDM_PLATFORM_EVENT_MESSAGE;

	uint8_t rc = pack_pldm_header(&header, &(msg->hdr));
	if (rc != PLDM_SUCCESS) {
		return rc;
	}

	struct pldm_platform_event_message_resp *response =
		(struct pldm_platform_event_message_resp *)msg->payload;
	response->completion_code = completion_code;
	response->platform_event_status = platform_event_status;

	return PLDM_SUCCESS;
}

LIBPLDM_ABI_STABLE
int encode_poll_for_platform_event_message_resp(
	uint8_t instance_id, uint8_t completion_code, uint8_t tid,
	uint16_t event_id, uint32_t next_data_transfer_handle,
	uint8_t transfer_flag, uint8_t event_class, uint32_t event_data_size,
	uint8_t *event_data, uint32_t checksum, struct pldm_msg *msg,
	size_t payload_length)
{
	struct pldm_msgbuf _buf;
	struct pldm_msgbuf *buf = &_buf;
	int rc;

	if (!msg) {
		return PLDM_ERROR_INVALID_DATA;
	}

	struct pldm_header_info header = { 0 };
	header.msg_type = PLDM_RESPONSE;
	header.instance = instance_id;
	header.pldm_type = PLDM_PLATFORM;
	header.command = PLDM_POLL_FOR_PLATFORM_EVENT_MESSAGE;

	rc = pack_pldm_header(&header, &(msg->hdr));
	if (rc != PLDM_SUCCESS) {
		return rc;
	}

	rc = pldm_msgbuf_init_errno(
		buf, PLDM_POLL_FOR_PLATFORM_EVENT_MESSAGE_MIN_RESP_BYTES,
		msg->payload, payload_length);
	if (rc) {
		return pldm_xlate_errno(rc);
	}

	pldm_msgbuf_insert(buf, completion_code);
	pldm_msgbuf_insert(buf, tid);
	rc = pldm_msgbuf_insert(buf, event_id);
	if (rc) {
		return pldm_xlate_errno(rc);
	}

	if (event_id == 0xffff || event_id == 0x0000) {
		if (PLDM_POLL_FOR_PLATFORM_EVENT_MESSAGE_MIN_RESP_BYTES !=
		    payload_length) {
			return PLDM_ERROR_INVALID_LENGTH;
		}

		rc = pldm_msgbuf_destroy(buf);
		if (rc) {
			return pldm_xlate_errno(rc);
		}

		return PLDM_SUCCESS;
	}

	if ((event_data == NULL) && (event_data_size > 0)) {
		return PLDM_ERROR_INVALID_DATA;
	}

	pldm_msgbuf_insert(buf, next_data_transfer_handle);
	pldm_msgbuf_insert(buf, transfer_flag);
	pldm_msgbuf_insert(buf, event_class);
	rc = pldm_msgbuf_insert(buf, event_data_size);
	if (rc) {
		return pldm_xlate_errno(rc);
	}

	if ((event_data_size > 0) && event_data) {
		rc = pldm_msgbuf_insert_array(buf, event_data_size, event_data,
					      event_data_size);
		if (rc) {
			return pldm_xlate_errno(rc);
		}
	}

	if (transfer_flag == PLDM_END || transfer_flag == PLDM_START_AND_END) {
		pldm_msgbuf_insert(buf, checksum);
	}

	rc = pldm_msgbuf_destroy(buf);
	if (rc) {
		return pldm_xlate_errno(rc);
	}

	return PLDM_SUCCESS;
}

LIBPLDM_ABI_STABLE
int encode_platform_event_message_req(
	uint8_t instance_id, uint8_t format_version, uint8_t tid,
	uint8_t event_class, const uint8_t *event_data,
	size_t event_data_length, struct pldm_msg *msg, size_t payload_length)

{
	if (format_version != 1) {
		return PLDM_ERROR_INVALID_DATA;
	}

	if (msg == NULL || event_data == NULL) {
		return PLDM_ERROR_INVALID_DATA;
	}

	if (event_data_length == 0) {
		return PLDM_ERROR_INVALID_DATA;
	}

	if ((SIZE_MAX - PLDM_PLATFORM_EVENT_MESSAGE_MIN_REQ_BYTES) <
	    event_data_length) {
		return PLDM_ERROR_INVALID_LENGTH;
	}

	if (payload_length !=
	    PLDM_PLATFORM_EVENT_MESSAGE_MIN_REQ_BYTES + event_data_length) {
		return PLDM_ERROR_INVALID_LENGTH;
	}

	if (event_class > PLDM_CPER_EVENT &&
	    !(event_class >= 0xf0 && event_class <= 0xfe)) {
		return PLDM_ERROR_INVALID_DATA;
	}

	struct pldm_header_info header = { 0 };
	header.msg_type = PLDM_REQUEST;
	header.instance = instance_id;
	header.pldm_type = PLDM_PLATFORM;
	header.command = PLDM_PLATFORM_EVENT_MESSAGE;

	uint8_t rc = pack_pldm_header(&header, &(msg->hdr));
	if (rc != PLDM_SUCCESS) {
		return rc;
	}

	struct pldm_platform_event_message_req *request =
		(struct pldm_platform_event_message_req *)msg->payload;
	request->format_version = format_version;
	request->tid = tid;
	request->event_class = event_class;
	memcpy(request->event_data, event_data, event_data_length);

	return PLDM_SUCCESS;
}

LIBPLDM_ABI_STABLE
int decode_platform_event_message_resp(const struct pldm_msg *msg,
				       size_t payload_length,
				       uint8_t *completion_code,
				       uint8_t *platform_event_status)
{
	struct pldm_msgbuf _buf;
	struct pldm_msgbuf *buf = &_buf;
	int rc;

	if (msg == NULL || completion_code == NULL ||
	    platform_event_status == NULL) {
		return PLDM_ERROR_INVALID_DATA;
	}

	rc = pldm_msgbuf_init_errno(buf, PLDM_PLATFORM_EVENT_MESSAGE_RESP_BYTES,
				    msg->payload, payload_length);
	if (rc) {
		return pldm_xlate_errno(rc);
	}

	rc = pldm_msgbuf_extract_p(buf, completion_code);
	if (rc) {
		return pldm_xlate_errno(rc);
	}

	if (PLDM_SUCCESS != *completion_code) {
		return PLDM_SUCCESS;
	}

	rc = pldm_msgbuf_extract_p(buf, platform_event_status);
	if (rc) {
		return pldm_xlate_errno(rc);
	}

	if (*platform_event_status > PLDM_EVENT_LOGGING_REJECTED) {
		return PLDM_ERROR_INVALID_DATA;
	}

	rc = pldm_msgbuf_destroy(buf);
	if (rc) {
		return pldm_xlate_errno(rc);
	}

	return PLDM_SUCCESS;
}

LIBPLDM_ABI_STABLE
int encode_event_message_buffer_size_req(uint8_t instance_id,
					 uint16_t event_receiver_max_buffer_size,
					 struct pldm_msg *msg)
{
	struct pldm_header_info header = { 0 };
	header.msg_type = PLDM_REQUEST;
	header.instance = instance_id;
	header.pldm_type = PLDM_PLATFORM;
	header.command = PLDM_EVENT_MESSAGE_BUFFER_SIZE;

	uint8_t rc = pack_pldm_header(&header, &(msg->hdr));
	if (rc != PLDM_SUCCESS) {
		return rc;
	}

	struct pldm_event_message_buffer_size_req *request =
		(struct pldm_event_message_buffer_size_req *)msg->payload;
	request->event_receiver_max_buffer_size =
		event_receiver_max_buffer_size;

	return PLDM_SUCCESS;
}

LIBPLDM_ABI_STABLE
int decode_event_message_buffer_size_resp(const struct pldm_msg *msg,
					  size_t payload_length,
					  uint8_t *completion_code,
					  uint16_t *terminus_max_buffer_size)
{
	struct pldm_msgbuf _buf;
	struct pldm_msgbuf *buf = &_buf;
	int rc;

	if (msg == NULL || completion_code == NULL ||
	    terminus_max_buffer_size == NULL) {
		return PLDM_ERROR_INVALID_DATA;
	}

	rc = pldm_msgbuf_init_errno(buf,
				    PLDM_EVENT_MESSAGE_BUFFER_SIZE_RESP_BYTES,
				    msg->payload, payload_length);
	if (rc) {
		return pldm_xlate_errno(rc);
	}

	rc = pldm_msgbuf_extract_p(buf, completion_code);
	if (rc) {
		return pldm_xlate_errno(rc);
	}

	if (PLDM_SUCCESS != *completion_code) {
		return PLDM_SUCCESS;
	}

	pldm_msgbuf_extract_p(buf, terminus_max_buffer_size);

	rc = pldm_msgbuf_destroy_consumed(buf);
	if (rc) {
		return pldm_xlate_errno(rc);
	}

	return PLDM_SUCCESS;
}

LIBPLDM_ABI_STABLE
int encode_event_message_supported_req(uint8_t instance_id,
				       uint8_t format_version,
				       struct pldm_msg *msg)
{
	if (format_version != 1) {
		return PLDM_ERROR_INVALID_DATA;
	}

	if (msg == NULL) {
		return PLDM_ERROR_INVALID_DATA;
	}

	struct pldm_header_info header = { 0 };
	header.msg_type = PLDM_REQUEST;
	header.instance = instance_id;
	header.pldm_type = PLDM_PLATFORM;
	header.command = PLDM_EVENT_MESSAGE_SUPPORTED;

	uint8_t rc = pack_pldm_header(&header, &(msg->hdr));
	if (rc != PLDM_SUCCESS) {
		return rc;
	}

	struct pldm_event_message_supported_req *request =
		(struct pldm_event_message_supported_req *)msg->payload;
	request->format_version = format_version;

	return PLDM_SUCCESS;
}

LIBPLDM_ABI_STABLE
int decode_event_message_supported_resp(const struct pldm_msg *msg,
					size_t payload_length,
					uint8_t *completion_code,
					uint8_t *synchrony_config,
					bitfield8_t *synchrony_config_support,
					uint8_t *number_event_class_returned,
					uint8_t *event_class,
					uint8_t event_class_count)
{
	struct pldm_msgbuf _buf;
	struct pldm_msgbuf *buf = &_buf;
	int i;
	int rc;

	if (msg == NULL || completion_code == NULL ||
	    synchrony_config == NULL || synchrony_config_support == NULL ||
	    number_event_class_returned == NULL || event_class == NULL) {
		return PLDM_ERROR_INVALID_DATA;
	}

	rc = pldm_msgbuf_init_errno(buf,
				    PLDM_EVENT_MESSAGE_SUPPORTED_MIN_RESP_BYTES,
				    msg->payload, payload_length);
	if (rc) {
		return pldm_xlate_errno(rc);
	}

	rc = pldm_msgbuf_extract_p(buf, completion_code);
	if (rc) {
		return pldm_xlate_errno(rc);
	}

	if (PLDM_SUCCESS != *completion_code) {
		return PLDM_SUCCESS;
	}

	rc = pldm_msgbuf_extract_p(buf, synchrony_config);
	if (rc) {
		return pldm_xlate_errno(rc);
	}

	if (*synchrony_config > PLDM_MESSAGE_TYPE_ASYNCHRONOUS_WITH_HEARTBEAT) {
		return PLDM_ERROR_INVALID_DATA;
	}

	pldm_msgbuf_extract_p(buf, &synchrony_config_support->byte);

	rc = pldm_msgbuf_extract_p(buf, number_event_class_returned);
	if (rc) {
		return pldm_xlate_errno(rc);
	}

	if (*number_event_class_returned == 0) {
		rc = pldm_msgbuf_destroy(buf);
		if (rc) {
			return pldm_xlate_errno(rc);
		}

		return PLDM_SUCCESS;
	}

	if (event_class_count < *number_event_class_returned) {
		return PLDM_ERROR_INVALID_LENGTH;
	}

	for (i = 0; i < *number_event_class_returned; i++) {
		pldm_msgbuf_extract(buf, event_class[i]);
	}

	rc = pldm_msgbuf_destroy_consumed(buf);
	if (rc) {
		return pldm_xlate_errno(rc);
	}

	return PLDM_SUCCESS;
}

LIBPLDM_ABI_STABLE
int decode_sensor_event_data(const uint8_t *event_data,
			     size_t event_data_length, uint16_t *sensor_id,
			     uint8_t *sensor_event_class_type,
			     size_t *event_class_data_offset)
{
	struct pldm_msgbuf _buf;
	struct pldm_msgbuf *buf = &_buf;
	int rc;

	if (event_data == NULL || sensor_id == NULL ||
	    sensor_event_class_type == NULL ||
	    event_class_data_offset == NULL) {
		return PLDM_ERROR_INVALID_DATA;
	}

	rc = pldm_msgbuf_init_errno(buf, PLDM_SENSOR_EVENT_DATA_MIN_LENGTH,
				    event_data, event_data_length);
	if (rc) {
		return pldm_xlate_errno(rc);
	}

	if (event_data_length < PLDM_PLATFORM_EVENT_MESSAGE_MIN_REQ_BYTES) {
		return PLDM_ERROR_INVALID_LENGTH;
	}

	size_t event_class_data_length =
		event_data_length - PLDM_PLATFORM_EVENT_MESSAGE_MIN_REQ_BYTES;

	pldm_msgbuf_extract_p(buf, sensor_id);
	rc = pldm_msgbuf_extract_p(buf, sensor_event_class_type);
	if (rc) {
		return pldm_xlate_errno(rc);
	}

	if (*sensor_event_class_type == PLDM_SENSOR_OP_STATE) {
		if (event_class_data_length !=
		    PLDM_SENSOR_EVENT_SENSOR_OP_STATE_DATA_LENGTH) {
			return PLDM_ERROR_INVALID_LENGTH;
		}
	} else if (*sensor_event_class_type == PLDM_STATE_SENSOR_STATE) {
		if (event_class_data_length !=
		    PLDM_SENSOR_EVENT_STATE_SENSOR_STATE_DATA_LENGTH) {
			return PLDM_ERROR_INVALID_LENGTH;
		}
	} else if (*sensor_event_class_type == PLDM_NUMERIC_SENSOR_STATE) {
		if (event_class_data_length <
			    PLDM_SENSOR_EVENT_NUMERIC_SENSOR_STATE_MIN_DATA_LENGTH ||
		    event_class_data_length >
			    PLDM_SENSOR_EVENT_NUMERIC_SENSOR_STATE_MAX_DATA_LENGTH) {
			return PLDM_ERROR_INVALID_LENGTH;
		}
	} else {
		return PLDM_ERROR_INVALID_DATA;
	}

	*event_class_data_offset =
		sizeof(*sensor_id) + sizeof(*sensor_event_class_type);

	rc = pldm_msgbuf_destroy(buf);
	if (rc) {
		return pldm_xlate_errno(rc);
	}

	return PLDM_SUCCESS;
}

LIBPLDM_ABI_STABLE
int decode_sensor_op_data(const uint8_t *sensor_data, size_t sensor_data_length,
			  uint8_t *present_op_state, uint8_t *previous_op_state)
{
	struct pldm_msgbuf _buf;
	struct pldm_msgbuf *buf = &_buf;
	int rc;

	if (sensor_data == NULL || present_op_state == NULL ||
	    previous_op_state == NULL) {
		return PLDM_ERROR_INVALID_DATA;
	}

	rc = pldm_msgbuf_init_errno(
		buf, PLDM_SENSOR_EVENT_SENSOR_OP_STATE_DATA_LENGTH, sensor_data,
		sensor_data_length);
	if (rc) {
		return pldm_xlate_errno(rc);
	}

	pldm_msgbuf_extract_p(buf, present_op_state);
	pldm_msgbuf_extract_p(buf, previous_op_state);

	rc = pldm_msgbuf_destroy_consumed(buf);
	if (rc) {
		return pldm_xlate_errno(rc);
	}

	return PLDM_SUCCESS;
}

LIBPLDM_ABI_STABLE
int decode_state_sensor_data(const uint8_t *sensor_data,
			     size_t sensor_data_length, uint8_t *sensor_offset,
			     uint8_t *event_state,
			     uint8_t *previous_event_state)
{
	struct pldm_msgbuf _buf;
	struct pldm_msgbuf *buf = &_buf;
	int rc;

	if (sensor_data == NULL || sensor_offset == NULL ||
	    event_state == NULL || previous_event_state == NULL) {
		return PLDM_ERROR_INVALID_DATA;
	}

	rc = pldm_msgbuf_init_errno(
		buf, PLDM_SENSOR_EVENT_STATE_SENSOR_STATE_DATA_LENGTH,
		sensor_data, sensor_data_length);
	if (rc) {
		return pldm_xlate_errno(rc);
	}

	pldm_msgbuf_extract_p(buf, sensor_offset);
	pldm_msgbuf_extract_p(buf, event_state);
	pldm_msgbuf_extract_p(buf, previous_event_state);

	rc = pldm_msgbuf_destroy_consumed(buf);
	if (rc) {
		return pldm_xlate_errno(rc);
	}

	return PLDM_SUCCESS;
}

LIBPLDM_ABI_STABLE
int decode_numeric_sensor_data(const uint8_t *sensor_data,
			       size_t sensor_data_length, uint8_t *event_state,
			       uint8_t *previous_event_state,
			       uint8_t *sensor_data_size,
			       uint32_t *present_reading)
{
	struct pldm_msgbuf _buf;
	struct pldm_msgbuf *buf = &_buf;
	int rc;

	if (sensor_data == NULL || sensor_data_size == NULL ||
	    event_state == NULL || previous_event_state == NULL ||
	    present_reading == NULL) {
		return PLDM_ERROR_INVALID_DATA;
	}

	if (sensor_data_length >
	    PLDM_SENSOR_EVENT_NUMERIC_SENSOR_STATE_MAX_DATA_LENGTH) {
		return PLDM_ERROR_INVALID_LENGTH;
	}

	rc = pldm_msgbuf_init_errno(
		buf, PLDM_SENSOR_EVENT_NUMERIC_SENSOR_STATE_MIN_DATA_LENGTH,
		sensor_data, sensor_data_length);
	if (rc) {
		return pldm_xlate_errno(rc);
	}

	pldm_msgbuf_extract_p(buf, event_state);
	pldm_msgbuf_extract_p(buf, previous_event_state);
	rc = pldm_msgbuf_extract_p(buf, sensor_data_size);
	if (rc) {
		return pldm_xlate_errno(rc);
	}

	/*
	 * The implementation below is bonkers, but it's because the function
	 * prototype is bonkers. The `present_reading` argument should have been
	 * a tagged union.
	 */
	switch (*sensor_data_size) {
	case PLDM_SENSOR_DATA_SIZE_UINT8: {
		uint8_t val;
		if (!pldm_msgbuf_extract(buf, val)) {
			*present_reading = (uint32_t)val;
		}
		break;
	}
	case PLDM_SENSOR_DATA_SIZE_SINT8: {
		int8_t val;
		if (!pldm_msgbuf_extract(buf, val)) {
			*present_reading = (uint32_t)(int32_t)val;
		}
		break;
	}
	case PLDM_SENSOR_DATA_SIZE_UINT16: {
		uint16_t val;
		if (!pldm_msgbuf_extract(buf, val)) {
			*present_reading = (uint32_t)val;
		}
		break;
	}
	case PLDM_SENSOR_DATA_SIZE_SINT16: {
		int16_t val;
		if (!pldm_msgbuf_extract(buf, val)) {
			*present_reading = (uint32_t)(int32_t)val;
		}
		break;
	}
	case PLDM_SENSOR_DATA_SIZE_UINT32: {
		uint32_t val;
		if (!pldm_msgbuf_extract(buf, val)) {
			*present_reading = (uint32_t)val;
		}
		break;
	}
	case PLDM_SENSOR_DATA_SIZE_SINT32: {
		int32_t val;
		if (!pldm_msgbuf_extract(buf, val)) {
			*present_reading = (uint32_t)val;
		}
		break;
	}
	default:
		return PLDM_ERROR_INVALID_DATA;
	}

	rc = pldm_msgbuf_destroy_consumed(buf);
	if (rc) {
		return pldm_xlate_errno(rc);
	}

	return PLDM_SUCCESS;
}

LIBPLDM_ABI_STABLE
int decode_numeric_sensor_pdr_data(
	const void *pdr_data, size_t pdr_data_length,
	struct pldm_numeric_sensor_value_pdr *pdr_value)
{
	struct pldm_msgbuf _buf;
	struct pldm_msgbuf *buf = &_buf;
	int rc;

	rc = pldm_msgbuf_init_errno(buf, PLDM_PDR_NUMERIC_SENSOR_PDR_MIN_LENGTH,
				    pdr_data, pdr_data_length);
	if (rc) {
		return pldm_xlate_errno(rc);
	}

	rc = pldm_msgbuf_extract_value_pdr_hdr(
		buf, &pdr_value->hdr, PLDM_PDR_NUMERIC_SENSOR_PDR_MIN_LENGTH,
		pdr_data_length);
	if (rc) {
		return pldm_xlate_errno(rc);
	}

	pldm_msgbuf_extract(buf, pdr_value->terminus_handle);
	pldm_msgbuf_extract(buf, pdr_value->sensor_id);
	pldm_msgbuf_extract(buf, pdr_value->entity_type);
	pldm_msgbuf_extract(buf, pdr_value->entity_instance_num);
	pldm_msgbuf_extract(buf, pdr_value->container_id);
	pldm_msgbuf_extract(buf, pdr_value->sensor_init);
	pldm_msgbuf_extract(buf, pdr_value->sensor_auxiliary_names_pdr);
	pldm_msgbuf_extract(buf, pdr_value->base_unit);
	pldm_msgbuf_extract(buf, pdr_value->unit_modifier);
	pldm_msgbuf_extract(buf, pdr_value->rate_unit);
	pldm_msgbuf_extract(buf, pdr_value->base_oem_unit_handle);
	pldm_msgbuf_extract(buf, pdr_value->aux_unit);
	pldm_msgbuf_extract(buf, pdr_value->aux_unit_modifier);
	pldm_msgbuf_extract(buf, pdr_value->aux_rate_unit);
	pldm_msgbuf_extract(buf, pdr_value->rel);
	pldm_msgbuf_extract(buf, pdr_value->aux_oem_unit_handle);
	pldm_msgbuf_extract(buf, pdr_value->is_linear);

	rc = pldm_msgbuf_extract(buf, pdr_value->sensor_data_size);
	if (rc) {
		return pldm_xlate_errno(rc);
	}
	if (pdr_value->sensor_data_size > PLDM_SENSOR_DATA_SIZE_MAX) {
		return PLDM_ERROR_INVALID_DATA;
	}

	pldm_msgbuf_extract(buf, pdr_value->resolution);
	pldm_msgbuf_extract(buf, pdr_value->offset);
	pldm_msgbuf_extract(buf, pdr_value->accuracy);
	pldm_msgbuf_extract(buf, pdr_value->plus_tolerance);
	pldm_msgbuf_extract(buf, pdr_value->minus_tolerance);
	pldm_msgbuf_extract_sensor_data(buf, pdr_value->sensor_data_size,
					&pdr_value->hysteresis);
	pldm_msgbuf_extract(buf, pdr_value->supported_thresholds.byte);
	pldm_msgbuf_extract(
		buf, pdr_value->threshold_and_hysteresis_volatility.byte);
	pldm_msgbuf_extract(buf, pdr_value->state_transition_interval);
	pldm_msgbuf_extract(buf, pdr_value->update_interval);
	pldm_msgbuf_extract_sensor_data(buf, pdr_value->sensor_data_size,
					&pdr_value->max_readable);
	pldm_msgbuf_extract_sensor_data(buf, pdr_value->sensor_data_size,
					&pdr_value->min_readable);

	rc = pldm_msgbuf_extract(buf, pdr_value->range_field_format);
	if (rc) {
		return pldm_xlate_errno(rc);
	}
	if (pdr_value->range_field_format > PLDM_RANGE_FIELD_FORMAT_MAX) {
		return PLDM_ERROR_INVALID_DATA;
	}

	pldm_msgbuf_extract(buf, pdr_value->range_field_support.byte);
	pldm_msgbuf_extract_range_field_format(
		buf, pdr_value->range_field_format, pdr_value->nominal_value);
	pldm_msgbuf_extract_range_field_format(
		buf, pdr_value->range_field_format, pdr_value->normal_max);
	pldm_msgbuf_extract_range_field_format(
		buf, pdr_value->range_field_format, pdr_value->normal_min);
	pldm_msgbuf_extract_range_field_format(
		buf, pdr_value->range_field_format, pdr_value->warning_high);
	pldm_msgbuf_extract_range_field_format(
		buf, pdr_value->range_field_format, pdr_value->warning_low);
	pldm_msgbuf_extract_range_field_format(
		buf, pdr_value->range_field_format, pdr_value->critical_high);
	pldm_msgbuf_extract_range_field_format(
		buf, pdr_value->range_field_format, pdr_value->critical_low);
	pldm_msgbuf_extract_range_field_format(
		buf, pdr_value->range_field_format, pdr_value->fatal_high);
	pldm_msgbuf_extract_range_field_format(
		buf, pdr_value->range_field_format, pdr_value->fatal_low);

	rc = pldm_msgbuf_destroy(buf);
	if (rc) {
		return pldm_xlate_errno(rc);
	}

	return PLDM_SUCCESS;
}

LIBPLDM_ABI_STABLE
int encode_get_numeric_effecter_value_req(uint8_t instance_id,
					  uint16_t effecter_id,
					  struct pldm_msg *msg)
{
	if (msg == NULL) {
		return PLDM_ERROR_INVALID_DATA;
	}

	struct pldm_header_info header = { 0 };
	header.msg_type = PLDM_REQUEST;
	header.instance = instance_id;
	header.pldm_type = PLDM_PLATFORM;
	header.command = PLDM_GET_NUMERIC_EFFECTER_VALUE;

	uint8_t rc = pack_pldm_header(&header, &(msg->hdr));
	if (rc != PLDM_SUCCESS) {
		return rc;
	}

	struct pldm_get_numeric_effecter_value_req *request =
		(struct pldm_get_numeric_effecter_value_req *)msg->payload;
	request->effecter_id = htole16(effecter_id);

	return PLDM_SUCCESS;
}

LIBPLDM_ABI_STABLE
int encode_get_numeric_effecter_value_resp(
	uint8_t instance_id, uint8_t completion_code,
	uint8_t effecter_data_size, uint8_t effecter_oper_state,
	const uint8_t *pending_value, const uint8_t *present_value,
	struct pldm_msg *msg, size_t payload_length)
{
	if (msg == NULL || pending_value == NULL || present_value == NULL) {
		return PLDM_ERROR_INVALID_DATA;
	}

	if (effecter_data_size > PLDM_EFFECTER_DATA_SIZE_SINT32) {
		return PLDM_ERROR_INVALID_DATA;
	}

	if (effecter_oper_state > EFFECTER_OPER_STATE_INTEST) {
		return PLDM_ERROR_INVALID_DATA;
	}

	struct pldm_header_info header = { 0 };
	header.msg_type = PLDM_RESPONSE;
	header.instance = instance_id;
	header.pldm_type = PLDM_PLATFORM;
	header.command = PLDM_GET_NUMERIC_EFFECTER_VALUE;

	uint8_t rc = pack_pldm_header(&header, &(msg->hdr));
	if (rc != PLDM_SUCCESS) {
		return rc;
	}

	struct pldm_get_numeric_effecter_value_resp *response =
		(struct pldm_get_numeric_effecter_value_resp *)msg->payload;

	response->completion_code = completion_code;
	response->effecter_data_size = effecter_data_size;
	response->effecter_oper_state = effecter_oper_state;

	if (effecter_data_size == PLDM_EFFECTER_DATA_SIZE_UINT8 ||
	    effecter_data_size == PLDM_EFFECTER_DATA_SIZE_SINT8) {
		if (payload_length !=
		    PLDM_GET_NUMERIC_EFFECTER_VALUE_MIN_RESP_BYTES) {
			return PLDM_ERROR_INVALID_LENGTH;
		}
		response->pending_and_present_values[0] = *pending_value;
		response->pending_and_present_values[1] = *present_value;

	} else if (effecter_data_size == PLDM_EFFECTER_DATA_SIZE_UINT16 ||
		   effecter_data_size == PLDM_EFFECTER_DATA_SIZE_SINT16) {
		if (payload_length !=
		    PLDM_GET_NUMERIC_EFFECTER_VALUE_MIN_RESP_BYTES + 2) {
			return PLDM_ERROR_INVALID_LENGTH;
		}
		uint16_t val_pending = *(uint16_t *)pending_value;
		val_pending = htole16(val_pending);
		memcpy(response->pending_and_present_values, &val_pending,
		       sizeof(uint16_t));
		uint16_t val_present = *(uint16_t *)present_value;
		val_present = htole16(val_present);
		memcpy((response->pending_and_present_values +
			sizeof(uint16_t)),
		       &val_present, sizeof(uint16_t));

	} else if (effecter_data_size == PLDM_EFFECTER_DATA_SIZE_UINT32 ||
		   effecter_data_size == PLDM_EFFECTER_DATA_SIZE_SINT32) {
		if (payload_length !=
		    PLDM_GET_NUMERIC_EFFECTER_VALUE_MIN_RESP_BYTES + 6) {
			return PLDM_ERROR_INVALID_LENGTH;
		}
		uint32_t val_pending = *(uint32_t *)pending_value;
		val_pending = htole32(val_pending);
		memcpy(response->pending_and_present_values, &val_pending,
		       sizeof(uint32_t));
		uint32_t val_present = *(uint32_t *)present_value;
		val_present = htole32(val_present);
		memcpy((response->pending_and_present_values +
			sizeof(uint32_t)),
		       &val_present, sizeof(uint32_t));
	}
	return PLDM_SUCCESS;
}

LIBPLDM_ABI_STABLE
int decode_get_numeric_effecter_value_req(const struct pldm_msg *msg,
					  size_t payload_length,
					  uint16_t *effecter_id)
{
	struct pldm_msgbuf _buf;
	struct pldm_msgbuf *buf = &_buf;
	int rc;

	if (msg == NULL || effecter_id == NULL) {
		return PLDM_ERROR_INVALID_DATA;
	}

	rc = pldm_msgbuf_init_errno(buf,
				    PLDM_GET_NUMERIC_EFFECTER_VALUE_REQ_BYTES,
				    msg->payload, payload_length);
	if (rc) {
		return pldm_xlate_errno(rc);
	}

	pldm_msgbuf_extract_p(buf, effecter_id);

	rc = pldm_msgbuf_destroy_consumed(buf);
	if (rc) {
		return pldm_xlate_errno(rc);
	}

	return PLDM_SUCCESS;
}

LIBPLDM_ABI_STABLE
int decode_get_numeric_effecter_value_resp(const struct pldm_msg *msg,
					   size_t payload_length,
					   uint8_t *completion_code,
					   uint8_t *effecter_data_size,
					   uint8_t *effecter_oper_state,
					   uint8_t *pending_value,
					   uint8_t *present_value)
{
	struct pldm_msgbuf _buf;
	struct pldm_msgbuf *buf = &_buf;
	int rc;

	if (msg == NULL || effecter_data_size == NULL ||
	    effecter_oper_state == NULL || pending_value == NULL ||
	    present_value == NULL) {
		return PLDM_ERROR_INVALID_DATA;
	}

	rc = pldm_msgbuf_init_errno(
		buf, PLDM_GET_NUMERIC_EFFECTER_VALUE_MIN_RESP_BYTES,
		msg->payload, payload_length);
	if (rc) {
		return pldm_xlate_errno(rc);
	}

	rc = pldm_msgbuf_extract_p(buf, completion_code);
	if (rc) {
		return pldm_xlate_errno(rc);
	}

	if (PLDM_SUCCESS != *completion_code) {
		return PLDM_SUCCESS;
	}

	rc = pldm_msgbuf_extract_p(buf, effecter_data_size);
	if (rc) {
		return pldm_xlate_errno(rc);
	}

	if (*effecter_data_size > PLDM_EFFECTER_DATA_SIZE_SINT32) {
		return PLDM_ERROR_INVALID_DATA;
	}

	rc = pldm_msgbuf_extract_p(buf, effecter_oper_state);
	if (rc) {
		return pldm_xlate_errno(rc);
	}

	if (*effecter_oper_state > EFFECTER_OPER_STATE_INTEST) {
		return PLDM_ERROR_INVALID_DATA;
	}

	pldm_msgbuf_extract_effecter_value(buf, *effecter_data_size,
					   pending_value);
	pldm_msgbuf_extract_effecter_value(buf, *effecter_data_size,
					   present_value);

	rc = pldm_msgbuf_destroy_consumed(buf);
	if (rc) {
		return pldm_xlate_errno(rc);
	}

	return PLDM_SUCCESS;
}

LIBPLDM_ABI_STABLE
int encode_pldm_pdr_repository_chg_event_data(
	uint8_t event_data_format, uint8_t number_of_change_records,
	const uint8_t *event_data_operations,
	const uint8_t *numbers_of_change_entries,
	const uint32_t *const *change_entries,
	struct pldm_pdr_repository_chg_event_data *event_data,
	size_t *actual_change_records_size, size_t max_change_records_size)
{
	if (event_data_operations == NULL ||
	    numbers_of_change_entries == NULL || change_entries == NULL) {
		return PLDM_ERROR_INVALID_DATA;
	}

	size_t expected_size =
		sizeof(event_data_format) + sizeof(number_of_change_records);

	expected_size +=
		sizeof(*event_data_operations) * number_of_change_records;
	expected_size +=
		sizeof(*numbers_of_change_entries) * number_of_change_records;

	for (uint8_t i = 0; i < number_of_change_records; ++i) {
		expected_size += sizeof(*change_entries[0]) *
				 numbers_of_change_entries[i];
	}

	*actual_change_records_size = expected_size;

	if (event_data == NULL) {
		return PLDM_SUCCESS;
	}

	if (max_change_records_size < expected_size) {
		return PLDM_ERROR_INVALID_LENGTH;
	}

	event_data->event_data_format = event_data_format;
	event_data->number_of_change_records = number_of_change_records;

	struct pldm_pdr_repository_change_record_data *record_data =
		(struct pldm_pdr_repository_change_record_data *)
			event_data->change_records;

	for (uint8_t i = 0; i < number_of_change_records; ++i) {
		record_data->event_data_operation = event_data_operations[i];
		record_data->number_of_change_entries =
			numbers_of_change_entries[i];

		for (uint8_t j = 0; j < record_data->number_of_change_entries;
		     ++j) {
			record_data->change_entry[j] =
				htole32(change_entries[i][j]);
		}

		record_data =
			(struct pldm_pdr_repository_change_record_data
				 *)(record_data->change_entry +
				    record_data->number_of_change_entries);
	}

	return PLDM_SUCCESS;
}

LIBPLDM_ABI_STABLE
int decode_pldm_pdr_repository_chg_event_data(const uint8_t *event_data,
					      size_t event_data_size,
					      uint8_t *event_data_format,
					      uint8_t *number_of_change_records,
					      size_t *change_record_data_offset)
{
	struct pldm_msgbuf _buf;
	struct pldm_msgbuf *buf = &_buf;
	int rc;

	if (event_data == NULL || event_data_format == NULL ||
	    number_of_change_records == NULL ||
	    change_record_data_offset == NULL) {
		return PLDM_ERROR_INVALID_DATA;
	}

	rc = pldm_msgbuf_init_errno(buf,
				    PLDM_PDR_REPOSITORY_CHG_EVENT_MIN_LENGTH,
				    event_data, event_data_size);
	if (rc) {
		return pldm_xlate_errno(rc);
	}

	pldm_msgbuf_extract_p(buf, event_data_format);
	pldm_msgbuf_extract_p(buf, number_of_change_records);

	*change_record_data_offset =
		sizeof(*event_data_format) + sizeof(*number_of_change_records);

	rc = pldm_msgbuf_destroy(buf);
	if (rc) {
		return pldm_xlate_errno(rc);
	}

	return PLDM_SUCCESS;
}

LIBPLDM_ABI_STABLE
int decode_pldm_message_poll_event_data(
	const void *event_data, size_t event_data_length,
	struct pldm_message_poll_event *poll_event)
{
	struct pldm_msgbuf _buf;
	struct pldm_msgbuf *buf = &_buf;
	int rc;

	if (!event_data || !poll_event) {
		return -EINVAL;
	}

	rc = pldm_msgbuf_init_errno(buf, PLDM_MSG_POLL_EVENT_LENGTH, event_data,
				    event_data_length);
	if (rc) {
		return rc;
	}

	pldm_msgbuf_extract(buf, poll_event->format_version);
	rc = pldm_msgbuf_extract(buf, poll_event->event_id);
	if (rc) {
		return rc;
	}

	if (poll_event->event_id == 0x0000 || poll_event->event_id == 0xffff) {
		return -EPROTO;
	}

	pldm_msgbuf_extract(buf, poll_event->data_transfer_handle);

	return pldm_msgbuf_destroy_consumed(buf);
}

LIBPLDM_ABI_TESTING
int encode_pldm_message_poll_event_data(
	const struct pldm_message_poll_event *poll_event, void *event_data,
	size_t event_data_length)
{
	struct pldm_msgbuf _buf;
	struct pldm_msgbuf *buf = &_buf;
	int rc;

	if (poll_event == NULL || event_data == NULL) {
		return -EINVAL;
	}

	if (poll_event->event_id == 0x0000 || poll_event->event_id == 0xffff) {
		return -EPROTO;
	}

	rc = pldm_msgbuf_init_errno(buf, PLDM_MSG_POLL_EVENT_LENGTH, event_data,
				    event_data_length);
	if (rc) {
		return rc;
	}
	pldm_msgbuf_insert(buf, poll_event->format_version);
	pldm_msgbuf_insert(buf, poll_event->event_id);
	pldm_msgbuf_insert(buf, poll_event->data_transfer_handle);

	return pldm_msgbuf_destroy_consumed(buf);
}

LIBPLDM_ABI_STABLE
int decode_pldm_pdr_repository_change_record_data(
	const uint8_t *change_record_data, size_t change_record_data_size,
	uint8_t *event_data_operation, uint8_t *number_of_change_entries,
	size_t *change_entry_data_offset)
{
	struct pldm_msgbuf _buf;
	struct pldm_msgbuf *buf = &_buf;
	int rc;

	if (change_record_data == NULL || event_data_operation == NULL ||
	    number_of_change_entries == NULL ||
	    change_entry_data_offset == NULL) {
		return PLDM_ERROR_INVALID_DATA;
	}

	rc = pldm_msgbuf_init_errno(
		buf, PLDM_PDR_REPOSITORY_CHANGE_RECORD_MIN_LENGTH,
		change_record_data, change_record_data_size);
	if (rc) {
		return pldm_xlate_errno(rc);
	}

	pldm_msgbuf_extract_p(buf, event_data_operation);
	pldm_msgbuf_extract_p(buf, number_of_change_entries);

	*change_entry_data_offset = sizeof(*event_data_operation) +
				    sizeof(*number_of_change_entries);

	rc = pldm_msgbuf_destroy(buf);
	if (rc) {
		return pldm_xlate_errno(rc);
	}

	return PLDM_SUCCESS;
}

LIBPLDM_ABI_STABLE
int encode_get_sensor_reading_req(uint8_t instance_id, uint16_t sensor_id,
				  uint8_t rearm_event_state,
				  struct pldm_msg *msg)
{
	if (msg == NULL) {
		return PLDM_ERROR_INVALID_DATA;
	}

	struct pldm_header_info header = { 0 };
	header.msg_type = PLDM_REQUEST;
	header.instance = instance_id;
	header.pldm_type = PLDM_PLATFORM;
	header.command = PLDM_GET_SENSOR_READING;

	uint8_t rc = pack_pldm_header(&header, &(msg->hdr));
	if (rc != PLDM_SUCCESS) {
		return rc;
	}

	struct pldm_get_sensor_reading_req *request =
		(struct pldm_get_sensor_reading_req *)msg->payload;

	request->sensor_id = htole16(sensor_id);
	request->rearm_event_state = rearm_event_state;

	return PLDM_SUCCESS;
}

LIBPLDM_ABI_STABLE
int decode_get_sensor_reading_resp(
	const struct pldm_msg *msg, size_t payload_length,
	uint8_t *completion_code, uint8_t *sensor_data_size,
	uint8_t *sensor_operational_state, uint8_t *sensor_event_message_enable,
	uint8_t *present_state, uint8_t *previous_state, uint8_t *event_state,
	uint8_t *present_reading)
{
	struct pldm_msgbuf _buf;
	struct pldm_msgbuf *buf = &_buf;
	int rc;

	if (msg == NULL || completion_code == NULL ||
	    sensor_data_size == NULL || sensor_operational_state == NULL ||
	    sensor_event_message_enable == NULL || present_state == NULL ||
	    previous_state == NULL || event_state == NULL ||
	    present_reading == NULL) {
		return PLDM_ERROR_INVALID_DATA;
	}

	rc = pldm_msgbuf_init_errno(buf, PLDM_GET_SENSOR_READING_MIN_RESP_BYTES,
				    msg->payload, payload_length);
	if (rc) {
		return pldm_xlate_errno(rc);
	}

	rc = pldm_msgbuf_extract_p(buf, completion_code);
	if (rc) {
		return pldm_xlate_errno(rc);
	}

	if (PLDM_SUCCESS != *completion_code) {
		return PLDM_SUCCESS;
	}

	rc = pldm_msgbuf_extract_p(buf, sensor_data_size);
	if (rc) {
		return pldm_xlate_errno(rc);
	}

	if (*sensor_data_size > PLDM_SENSOR_DATA_SIZE_SINT32) {
		return PLDM_ERROR_INVALID_DATA;
	}

	pldm_msgbuf_extract_p(buf, sensor_operational_state);
	pldm_msgbuf_extract_p(buf, sensor_event_message_enable);
	pldm_msgbuf_extract_p(buf, present_state);
	pldm_msgbuf_extract_p(buf, previous_state);
	pldm_msgbuf_extract_p(buf, event_state);

	pldm_msgbuf_extract_sensor_value(buf, *sensor_data_size,
					 present_reading);

	rc = pldm_msgbuf_destroy_consumed(buf);
	if (rc) {
		return pldm_xlate_errno(rc);
	}

	return PLDM_SUCCESS;
}

LIBPLDM_ABI_STABLE
int encode_get_sensor_reading_resp(uint8_t instance_id, uint8_t completion_code,
				   uint8_t sensor_data_size,
				   uint8_t sensor_operational_state,
				   uint8_t sensor_event_message_enable,
				   uint8_t present_state,
				   uint8_t previous_state, uint8_t event_state,
				   const uint8_t *present_reading,
				   struct pldm_msg *msg, size_t payload_length)
{
	if (msg == NULL || present_reading == NULL) {
		return PLDM_ERROR_INVALID_DATA;
	}

	if (sensor_data_size > PLDM_EFFECTER_DATA_SIZE_SINT32) {
		return PLDM_ERROR_INVALID_DATA;
	}

	struct pldm_header_info header = { 0 };
	header.msg_type = PLDM_RESPONSE;
	header.instance = instance_id;
	header.pldm_type = PLDM_PLATFORM;
	header.command = PLDM_GET_SENSOR_READING;

	uint8_t rc = pack_pldm_header(&header, &(msg->hdr));
	if (rc != PLDM_SUCCESS) {
		return rc;
	}

	struct pldm_get_sensor_reading_resp *response =
		(struct pldm_get_sensor_reading_resp *)msg->payload;

	response->completion_code = completion_code;
	response->sensor_data_size = sensor_data_size;
	response->sensor_operational_state = sensor_operational_state;
	response->sensor_event_message_enable = sensor_event_message_enable;
	response->present_state = present_state;
	response->previous_state = previous_state;
	response->event_state = event_state;

	if (sensor_data_size == PLDM_EFFECTER_DATA_SIZE_UINT8 ||
	    sensor_data_size == PLDM_EFFECTER_DATA_SIZE_SINT8) {
		if (payload_length != PLDM_GET_SENSOR_READING_MIN_RESP_BYTES) {
			return PLDM_ERROR_INVALID_LENGTH;
		}
		response->present_reading[0] = *present_reading;

	} else if (sensor_data_size == PLDM_EFFECTER_DATA_SIZE_UINT16 ||
		   sensor_data_size == PLDM_EFFECTER_DATA_SIZE_SINT16) {
		if (payload_length !=
		    PLDM_GET_SENSOR_READING_MIN_RESP_BYTES + 1) {
			return PLDM_ERROR_INVALID_LENGTH;
		}
		uint16_t val = *(uint16_t *)present_reading;
		val = htole16(val);
		memcpy(response->present_reading, &val, 2);

	} else if (sensor_data_size == PLDM_EFFECTER_DATA_SIZE_UINT32 ||
		   sensor_data_size == PLDM_EFFECTER_DATA_SIZE_SINT32) {
		if (payload_length !=
		    PLDM_GET_SENSOR_READING_MIN_RESP_BYTES + 3) {
			return PLDM_ERROR_INVALID_LENGTH;
		}
		uint32_t val = *(uint32_t *)present_reading;
		val = htole32(val);
		memcpy(response->present_reading, &val, 4);
	}

	return PLDM_SUCCESS;
}

LIBPLDM_ABI_STABLE
int decode_get_sensor_reading_req(const struct pldm_msg *msg,
				  size_t payload_length, uint16_t *sensor_id,
				  uint8_t *rearm_event_state)
{
	struct pldm_msgbuf _buf;
	struct pldm_msgbuf *buf = &_buf;
	int rc;

	if (msg == NULL || sensor_id == NULL || rearm_event_state == NULL) {
		return PLDM_ERROR_INVALID_DATA;
	}

	rc = pldm_msgbuf_init_errno(buf, PLDM_GET_SENSOR_READING_REQ_BYTES,
				    msg->payload, payload_length);
	if (rc) {
		return pldm_xlate_errno(rc);
	}

	pldm_msgbuf_extract_p(buf, sensor_id);
	pldm_msgbuf_extract_p(buf, rearm_event_state);

	rc = pldm_msgbuf_destroy(buf);
	if (rc) {
		return pldm_xlate_errno(rc);
	}

	return PLDM_SUCCESS;
}

LIBPLDM_ABI_STABLE
int encode_set_event_receiver_req(uint8_t instance_id,
				  uint8_t event_message_global_enable,
				  uint8_t transport_protocol_type,
				  uint8_t event_receiver_address_info,
				  uint16_t heartbeat_timer,
				  struct pldm_msg *msg)
{
	if (msg == NULL) {
		return PLDM_ERROR_INVALID_DATA;
	}

	if (transport_protocol_type != PLDM_TRANSPORT_PROTOCOL_TYPE_MCTP) {
		return PLDM_ERROR_INVALID_DATA;
	}

	struct pldm_header_info header = { 0 };
	header.msg_type = PLDM_REQUEST;
	header.instance = instance_id;
	header.pldm_type = PLDM_PLATFORM;
	header.command = PLDM_SET_EVENT_RECEIVER;

	uint8_t rc = pack_pldm_header(&header, &(msg->hdr));
	if (rc != PLDM_SUCCESS) {
		return rc;
	}

	struct pldm_set_event_receiver_req *request =
		(struct pldm_set_event_receiver_req *)msg->payload;
	request->event_message_global_enable = event_message_global_enable;

	request->transport_protocol_type = transport_protocol_type;
	request->event_receiver_address_info = event_receiver_address_info;

	if (event_message_global_enable ==
	    PLDM_EVENT_MESSAGE_GLOBAL_ENABLE_ASYNC_KEEP_ALIVE) {
		if (heartbeat_timer == 0) {
			return PLDM_ERROR_INVALID_DATA;
		}
		request->heartbeat_timer = htole16(heartbeat_timer);
	}

	return PLDM_SUCCESS;
}

LIBPLDM_ABI_STABLE
int decode_set_event_receiver_resp(const struct pldm_msg *msg,
				   size_t payload_length,
				   uint8_t *completion_code)
{
	struct pldm_msgbuf _buf;
	struct pldm_msgbuf *buf = &_buf;
	int rc;

	if (msg == NULL || completion_code == NULL) {
		return PLDM_ERROR_INVALID_DATA;
	}

	rc = pldm_msgbuf_init_errno(buf, PLDM_SET_EVENT_RECEIVER_RESP_BYTES,
				    msg->payload, payload_length);
	if (rc) {
		return pldm_xlate_errno(rc);
	}

	pldm_msgbuf_extract_p(buf, completion_code);

	rc = pldm_msgbuf_destroy(buf);
	if (rc) {
		return pldm_xlate_errno(rc);
	}

	return PLDM_SUCCESS;
}

LIBPLDM_ABI_STABLE
int decode_set_event_receiver_req(const struct pldm_msg *msg,
				  size_t payload_length,
				  uint8_t *event_message_global_enable,
				  uint8_t *transport_protocol_type,
				  uint8_t *event_receiver_address_info,
				  uint16_t *heartbeat_timer)

{
	struct pldm_msgbuf _buf;
	struct pldm_msgbuf *buf = &_buf;
	int rc;

	if (msg == NULL || event_message_global_enable == NULL ||
	    transport_protocol_type == NULL ||
	    event_receiver_address_info == NULL || heartbeat_timer == NULL) {
		return PLDM_ERROR_INVALID_DATA;
	}

	rc = pldm_msgbuf_init_errno(buf, PLDM_SET_EVENT_RECEIVER_MIN_REQ_BYTES,
				    msg->payload, payload_length);
	if (rc) {
		return pldm_xlate_errno(rc);
	}

	pldm_msgbuf_extract_p(buf, event_message_global_enable);
	if (rc) {
		return pldm_xlate_errno(rc);
	}

	pldm_msgbuf_extract_p(buf, transport_protocol_type);
	pldm_msgbuf_extract_p(buf, event_receiver_address_info);
	if ((*event_message_global_enable ==
	     PLDM_EVENT_MESSAGE_GLOBAL_ENABLE_ASYNC_KEEP_ALIVE)) {
		pldm_msgbuf_extract_p(buf, heartbeat_timer);
	}

	rc = pldm_msgbuf_destroy(buf);
	if (rc) {
		return pldm_xlate_errno(rc);
	}

	if ((*event_message_global_enable ==
	     PLDM_EVENT_MESSAGE_GLOBAL_ENABLE_ASYNC_KEEP_ALIVE) &&
	    (*heartbeat_timer == 0)) {
		return PLDM_ERROR_INVALID_DATA;
	}

	return PLDM_SUCCESS;
}

LIBPLDM_ABI_STABLE
int encode_set_event_receiver_resp(uint8_t instance_id, uint8_t completion_code,
				   struct pldm_msg *msg)

{
	if (msg == NULL) {
		return PLDM_ERROR_INVALID_DATA;
	}

	struct pldm_header_info header = { 0 };
	header.instance = instance_id;
	header.msg_type = PLDM_RESPONSE;
	header.pldm_type = PLDM_PLATFORM;
	header.command = PLDM_SET_EVENT_RECEIVER;

	uint8_t rc = pack_pldm_header(&header, &(msg->hdr));
	if (rc != PLDM_SUCCESS) {
		return rc;
	}

	msg->payload[0] = completion_code;

	return PLDM_SUCCESS;
}

LIBPLDM_ABI_STABLE
int encode_poll_for_platform_event_message_req(uint8_t instance_id,
					       uint8_t format_version,
					       uint8_t transfer_operation_flag,
					       uint32_t data_transfer_handle,
					       uint16_t event_id_to_acknowledge,
					       struct pldm_msg *msg,
					       size_t payload_length)
{
	struct pldm_msgbuf _buf;
	struct pldm_msgbuf *buf = &_buf;
	int rc;

	if (msg == NULL) {
		return PLDM_ERROR_INVALID_DATA;
	}

	rc = pldm_platform_poll_for_platform_event_message_validate(
		transfer_operation_flag, event_id_to_acknowledge);
	if (rc < 0) {
		return PLDM_ERROR_INVALID_DATA;
	}

	struct pldm_header_info header = { 0 };
	header.msg_type = PLDM_REQUEST;
	header.instance = instance_id;
	header.pldm_type = PLDM_PLATFORM;
	header.command = PLDM_POLL_FOR_PLATFORM_EVENT_MESSAGE;

	rc = pack_pldm_header(&header, &(msg->hdr));
	if (rc != PLDM_SUCCESS) {
		return rc;
	}

	rc = pldm_msgbuf_init_errno(
		buf, PLDM_POLL_FOR_PLATFORM_EVENT_MESSAGE_MIN_RESP_BYTES,
		msg->payload, payload_length);
	if (rc) {
		return pldm_xlate_errno(rc);
	}

	pldm_msgbuf_insert(buf, format_version);
	pldm_msgbuf_insert(buf, transfer_operation_flag);
	pldm_msgbuf_insert(buf, data_transfer_handle);
	pldm_msgbuf_insert(buf, event_id_to_acknowledge);

	rc = pldm_msgbuf_destroy(buf);
	if (rc) {
		return pldm_xlate_errno(rc);
	}

	return PLDM_SUCCESS;
}

LIBPLDM_ABI_STABLE
int decode_poll_for_platform_event_message_resp(
	const struct pldm_msg *msg, size_t payload_length,
	uint8_t *completion_code, uint8_t *tid, uint16_t *event_id,
	uint32_t *next_data_transfer_handle, uint8_t *transfer_flag,
	uint8_t *event_class, uint32_t *event_data_size, void **event_data,
	uint32_t *event_data_integrity_checksum)
{
	struct pldm_msgbuf _buf;
	struct pldm_msgbuf *buf = &_buf;
	int rc;

	if (msg == NULL || completion_code == NULL || tid == NULL ||
	    event_id == NULL || next_data_transfer_handle == NULL ||
	    transfer_flag == NULL || event_class == NULL ||
	    event_data_size == NULL || event_data == NULL ||
	    event_data_integrity_checksum == NULL) {
		return PLDM_ERROR_INVALID_DATA;
	}

	rc = pldm_msgbuf_init_errno(
		buf, PLDM_POLL_FOR_PLATFORM_EVENT_MESSAGE_MIN_RESP_BYTES,
		msg->payload, payload_length);
	if (rc) {
		return pldm_xlate_errno(rc);
	}

	rc = pldm_msgbuf_extract_p(buf, completion_code);
	if (rc) {
		return pldm_xlate_errno(rc);
	}
	if (PLDM_SUCCESS != *completion_code) {
		return *completion_code;
	}

	pldm_msgbuf_extract_p(buf, tid);
	rc = pldm_msgbuf_extract_p(buf, event_id);
	if (rc) {
		return pldm_xlate_errno(rc);
	}
	if ((*event_id == 0) || (*event_id == 0xffff)) {
		return PLDM_SUCCESS;
	}

	pldm_msgbuf_extract_p(buf, next_data_transfer_handle);
	rc = pldm_msgbuf_extract_p(buf, transfer_flag);
	if (rc) {
		return pldm_xlate_errno(rc);
	}

	pldm_msgbuf_extract_p(buf, event_class);
	rc = pldm_msgbuf_extract_p(buf, event_data_size);
	if (rc) {
		return pldm_xlate_errno(rc);
	}
	if (*event_data_size > payload_length) {
		return PLDM_ERROR_INVALID_DATA;
	}

	if (*event_data_size > 0) {
		pldm_msgbuf_span_required(buf, *event_data_size, event_data);
	}

	if (*transfer_flag == PLDM_END ||
	    *transfer_flag == PLDM_START_AND_END) {
		pldm_msgbuf_extract_p(buf, event_data_integrity_checksum);
	}

	rc = pldm_msgbuf_destroy_consumed(buf);
	if (rc) {
		return pldm_xlate_errno(rc);
	}

	return PLDM_SUCCESS;
}

LIBPLDM_ABI_TESTING
int decode_numeric_effecter_pdr_data(
	const void *pdr_data, size_t pdr_data_length,
	struct pldm_numeric_effecter_value_pdr *pdr_value)
{
	struct pldm_msgbuf _buf;
	struct pldm_msgbuf *buf = &_buf;
	struct pldm_value_pdr_hdr hdr;
	int rc;

	if (!pdr_data || !pdr_value) {
		return PLDM_ERROR_INVALID_DATA;
	}

	rc = pldm_msgbuf_init_errno(buf,
				    PLDM_PDR_NUMERIC_EFFECTER_PDR_MIN_LENGTH,
				    pdr_data, pdr_data_length);
	if (rc) {
		return pldm_xlate_errno(rc);
	}

	rc = pldm_msgbuf_extract_value_pdr_hdr(
		buf, &hdr, PLDM_PDR_NUMERIC_EFFECTER_PDR_MIN_LENGTH,
		pdr_data_length);
	if (rc) {
		return pldm_xlate_errno(rc);
	}

	memcpy(&pdr_value->hdr, &hdr, sizeof(hdr));

	pldm_msgbuf_extract(buf, pdr_value->terminus_handle);
	pldm_msgbuf_extract(buf, pdr_value->effecter_id);
	pldm_msgbuf_extract(buf, pdr_value->entity_type);
	pldm_msgbuf_extract(buf, pdr_value->entity_instance);
	pldm_msgbuf_extract(buf, pdr_value->container_id);
	pldm_msgbuf_extract(buf, pdr_value->effecter_semantic_id);
	pldm_msgbuf_extract(buf, pdr_value->effecter_init);
	pldm_msgbuf_extract(buf, pdr_value->effecter_auxiliary_names);
	pldm_msgbuf_extract(buf, pdr_value->base_unit);
	pldm_msgbuf_extract(buf, pdr_value->unit_modifier);
	pldm_msgbuf_extract(buf, pdr_value->rate_unit);
	pldm_msgbuf_extract(buf, pdr_value->base_oem_unit_handle);
	pldm_msgbuf_extract(buf, pdr_value->aux_unit);
	pldm_msgbuf_extract(buf, pdr_value->aux_unit_modifier);
	pldm_msgbuf_extract(buf, pdr_value->aux_rate_unit);
	pldm_msgbuf_extract(buf, pdr_value->aux_oem_unit_handle);
	pldm_msgbuf_extract(buf, pdr_value->is_linear);

	rc = pldm_msgbuf_extract(buf, pdr_value->effecter_data_size);
	if (rc) {
		return pldm_xlate_errno(rc);
	}
	if (pdr_value->effecter_data_size > PLDM_SENSOR_DATA_SIZE_MAX) {
		return PLDM_ERROR_INVALID_DATA;
	}

	pldm_msgbuf_extract(buf, pdr_value->resolution);
	pldm_msgbuf_extract(buf, pdr_value->offset);
	pldm_msgbuf_extract(buf, pdr_value->accuracy);
	pldm_msgbuf_extract(buf, pdr_value->plus_tolerance);
	pldm_msgbuf_extract(buf, pdr_value->minus_tolerance);
	pldm_msgbuf_extract(buf, pdr_value->state_transition_interval);
	pldm_msgbuf_extract(buf, pdr_value->transition_interval);
	pldm_msgbuf_extract_effecter_data(buf, pdr_value->effecter_data_size,
					  pdr_value->max_settable);
	pldm_msgbuf_extract_effecter_data(buf, pdr_value->effecter_data_size,
					  pdr_value->min_settable);

	rc = pldm_msgbuf_extract(buf, pdr_value->range_field_format);
	if (rc) {
		return pldm_xlate_errno(rc);
	}
	if (pdr_value->range_field_format > PLDM_RANGE_FIELD_FORMAT_MAX) {
		return PLDM_ERROR_INVALID_DATA;
	}

	pldm_msgbuf_extract(buf, pdr_value->range_field_support.byte);
	pldm_msgbuf_extract_range_field_format(
		buf, pdr_value->range_field_format, pdr_value->nominal_value);
	pldm_msgbuf_extract_range_field_format(
		buf, pdr_value->range_field_format, pdr_value->normal_max);
	pldm_msgbuf_extract_range_field_format(
		buf, pdr_value->range_field_format, pdr_value->normal_min);
	pldm_msgbuf_extract_range_field_format(
		buf, pdr_value->range_field_format, pdr_value->rated_max);
	pldm_msgbuf_extract_range_field_format(
		buf, pdr_value->range_field_format, pdr_value->rated_min);

	rc = pldm_msgbuf_destroy_consumed(buf);
	if (rc) {
		return pldm_xlate_errno(rc);
	}

	return PLDM_SUCCESS;
}

LIBPLDM_ABI_STABLE
int encode_get_state_effecter_states_req(uint8_t instance_id,
					 uint16_t effecter_id,
					 struct pldm_msg *msg,
					 size_t payload_length)
{
	struct pldm_msgbuf _buf;
	struct pldm_msgbuf *buf = &_buf;
	int rc;

	if (msg == NULL) {
		return -EINVAL;
	}

	struct pldm_header_info header = { 0 };
	header.msg_type = PLDM_REQUEST;
	header.instance = instance_id;
	header.pldm_type = PLDM_PLATFORM;
	header.command = PLDM_GET_STATE_EFFECTER_STATES;

	rc = pack_pldm_header_errno(&header, &msg->hdr);
	if (rc < 0) {
		return rc;
	}

	rc = pldm_msgbuf_init_errno(buf,
				    PLDM_GET_STATE_EFFECTER_STATES_REQ_BYTES,
				    msg->payload, payload_length);
	if (rc) {
		return rc;
	}

	pldm_msgbuf_insert(buf, effecter_id);

	return pldm_msgbuf_destroy_consumed(buf);
}

LIBPLDM_ABI_STABLE
int decode_get_state_effecter_states_req(const struct pldm_msg *msg,
					 size_t payload_length,
					 uint16_t *effecter_id)
{
	struct pldm_msgbuf _buf;
	struct pldm_msgbuf *buf = &_buf;
	int rc;

	if (msg == NULL || effecter_id == NULL) {
		return -EINVAL;
	}

	rc = pldm_msgbuf_init_errno(
		buf, PLDM_GET_STATE_EFFECTER_STATES_MIN_RESP_BYTES,
		msg->payload, payload_length);
	if (rc) {
		return rc;
	}

	pldm_msgbuf_extract_p(buf, effecter_id);

	return pldm_msgbuf_destroy_consumed(buf);
}

LIBPLDM_ABI_STABLE
int decode_get_state_effecter_states_resp(
	const struct pldm_msg *msg, size_t payload_length,
	struct pldm_get_state_effecter_states_resp *resp)
{
	struct pldm_msgbuf _buf;
	struct pldm_msgbuf *buf = &_buf;
	get_effecter_state_field *field;
	int rc;
	int i;

	if (msg == NULL || resp == NULL) {
		return -EINVAL;
	}

	rc = pldm_msgbuf_init_errno(
		buf, PLDM_GET_STATE_EFFECTER_STATES_MIN_RESP_BYTES,
		msg->payload, payload_length);
	if (rc) {
		return rc;
	}

	rc = pldm_msgbuf_extract(buf, resp->completion_code);
	if (rc) {
		return rc;
	}

	if (PLDM_SUCCESS != resp->completion_code) {
		return 0;
	}

	rc = pldm_msgbuf_extract(buf, resp->comp_effecter_count);
	if (rc) {
		return rc;
	}

	uint8_t comp_effecter_count = resp->comp_effecter_count;

	if (comp_effecter_count < PLDM_GET_EFFECTER_STATE_FIELD_COUNT_MIN ||
	    comp_effecter_count > PLDM_GET_EFFECTER_STATE_FIELD_COUNT_MAX) {
		return -EBADMSG;
	}

	for (i = 0, field = resp->field; i < comp_effecter_count;
	     i++, field++) {
		pldm_msgbuf_extract(buf, field->effecter_op_state);
		pldm_msgbuf_extract(buf, field->pending_state);
		pldm_msgbuf_extract(buf, field->present_state);
	}

	return pldm_msgbuf_destroy_consumed(buf);
}

LIBPLDM_ABI_STABLE
int encode_get_state_effecter_states_resp(
	uint8_t instance_id, struct pldm_get_state_effecter_states_resp *resp,
	struct pldm_msg *msg, size_t payload_length)
{
	struct pldm_msgbuf _buf;
	struct pldm_msgbuf *buf = &_buf;
	get_effecter_state_field *field;
	int rc;
	int i;

	if (msg == NULL || resp == NULL) {
		return -EINVAL;
	}

	uint8_t comp_effecter_count = resp->comp_effecter_count;

	if (comp_effecter_count < PLDM_GET_EFFECTER_STATE_FIELD_COUNT_MIN ||
	    comp_effecter_count > PLDM_GET_EFFECTER_STATE_FIELD_COUNT_MAX) {
		return -EBADMSG;
	}

	struct pldm_header_info header = { 0 };
	header.msg_type = PLDM_RESPONSE;
	header.instance = instance_id;
	header.pldm_type = PLDM_PLATFORM;
	header.command = PLDM_GET_STATE_EFFECTER_STATES;

	rc = pack_pldm_header_errno(&header, &msg->hdr);
	if (rc < 0) {
		return rc;
	}

	rc = pldm_msgbuf_init_errno(
		buf, PLDM_GET_STATE_EFFECTER_STATES_MIN_RESP_BYTES,
		msg->payload, payload_length);
	if (rc) {
		return rc;
	}

	pldm_msgbuf_insert(buf, resp->completion_code);
	pldm_msgbuf_insert(buf, comp_effecter_count);

	for (i = 0, field = resp->field; i < comp_effecter_count;
	     i++, field++) {
		pldm_msgbuf_insert(buf, field->effecter_op_state);
		pldm_msgbuf_insert(buf, field->pending_state);
		pldm_msgbuf_insert(buf, field->present_state);
	}

	return pldm_msgbuf_destroy_consumed(buf);
}

LIBPLDM_ABI_STABLE
int decode_entity_auxiliary_names_pdr(
	const void *data, size_t data_length,
	struct pldm_entity_auxiliary_names_pdr *pdr, size_t pdr_length)
{
	struct pldm_msgbuf _buf;
	struct pldm_msgbuf *buf = &_buf;
	struct pldm_msgbuf _src;
	struct pldm_msgbuf *src = &_src;
	struct pldm_msgbuf _dst;
	struct pldm_msgbuf *dst = &_dst;
	size_t names_len = 0;
	void *names = NULL;
	int rc;
	int i;

	if (!data || !pdr) {
		return -EINVAL;
	}

	/*
	 * Alignment of auxiliary_name_data is an invariant as we statically assert
	 * its behaviour in the header.
	 */
	assert(!((uintptr_t)pdr->auxiliary_name_data &
		 (alignof(pldm_utf16be) - 1)));

	/* Reject any lengths that are obviously invalid */
	if (pdr_length < data_length || pdr_length < sizeof(*pdr)) {
		return -EINVAL;
	}

	rc = pldm_msgbuf_init_errno(
		buf, PLDM_PDR_ENTITY_AUXILIARY_NAME_PDR_MIN_LENGTH, data,
		data_length);
	if (rc) {
		return rc;
	}

	rc = pldm_msgbuf_extract_value_pdr_hdr(
		buf, &pdr->hdr, PLDM_PDR_ENTITY_AUXILIARY_NAME_PDR_MIN_LENGTH,
		data_length);
	if (rc) {
		return rc;
	}

	pldm_msgbuf_extract(buf, pdr->container.entity_type);
	pldm_msgbuf_extract(buf, pdr->container.entity_instance_num);
	pldm_msgbuf_extract(buf, pdr->container.entity_container_id);
	pldm_msgbuf_extract(buf, pdr->shared_name_count);
	rc = pldm_msgbuf_extract(buf, pdr->name_string_count);
	if (rc < 0) {
		return rc;
	}

	rc = pldm_msgbuf_span_remaining(buf, &names, &names_len);
	if (rc < 0) {
		return rc;
	}
	assert(names);

	pdr->auxiliary_name_data_size = pdr_length - sizeof(*pdr);

	rc = pldm_msgbuf_init_errno(dst, pdr->auxiliary_name_data_size,
				    pdr->auxiliary_name_data,
				    pdr->auxiliary_name_data_size);
	if (rc < 0) {
		return rc;
	}

	/*
	 * Below we do two passes over the same region. This is to first pack the
	 * UTF16-BE strings into auxiliary_name_data, followed by the ASCII strings,
	 * to maintain appropriate alignment.
	 */

	/* Initialise for the first pass to extract the UTF16-BE name strings */
	rc = pldm_msgbuf_init_errno(src, names_len, names, names_len);
	if (rc < 0) {
		return rc;
	}

	for (i = 0; i < pdr->name_string_count; i++) {
		pldm_msgbuf_span_string_ascii(src, NULL, NULL);
		rc = pldm_msgbuf_copy_string_utf16(dst, src);
		if (rc) {
			return rc;
		}
	}

	rc = pldm_msgbuf_destroy_consumed(src);
	if (rc < 0) {
		return rc;
	}

	/* Reinitialise for the second pass to extract the ASCII tag strings */
	rc = pldm_msgbuf_init_errno(src, names_len, names, names_len);
	if (rc < 0) {
		return rc;
	}

	for (i = 0; i < pdr->name_string_count; i++) {
		rc = pldm_msgbuf_copy_string_ascii(dst, src);
		if (rc) {
			return rc;
		}
		pldm_msgbuf_span_string_utf16(src, NULL, NULL);
	}

	if ((rc = pldm_msgbuf_destroy(dst)) ||
	    (rc = pldm_msgbuf_destroy(src)) ||
	    (rc = pldm_msgbuf_destroy(buf))) {
		return rc;
	}

	return 0;
}

LIBPLDM_ABI_STABLE
int decode_pldm_entity_auxiliary_names_pdr_index(
	struct pldm_entity_auxiliary_names_pdr *pdr)
{
	struct pldm_msgbuf _buf;
	struct pldm_msgbuf *buf = &_buf;
	int rc;
	int i;

	if (!pdr) {
		return -EINVAL;
	}

	if (pdr->name_string_count == 0 && pdr->names) {
		return -EINVAL;
	}

	if (pdr->name_string_count > 0 && !pdr->names) {
		return -EINVAL;
	}

	if (pdr->name_string_count == 0) {
		return 0;
	}

	/*
	 * Minimum size is one NUL for each member of each entry
	 *
	 * Note that the definition of nameLanguageTag in DSP0248 v1.2.2
	 * states the following:
	 *
	 * > A null-terminated ISO646 ASCII string ...
	 * >
	 * > special value: null string = 0x0000 = unspecified.
	 *
	 * Until proven otherwise we will assume the "0x0000" is a
	 * misrepresentation of an ASCII NUL, and that ASCII NUL is
	 * represented by a single byte.
	 */
	rc = pldm_msgbuf_init_errno(
		buf, pdr->name_string_count * (sizeof(char) + sizeof(char16_t)),
		pdr->auxiliary_name_data, pdr->auxiliary_name_data_size);
	if (rc) {
		return rc;
	}

	for (i = 0; i < pdr->name_string_count; i++) {
		void *loc = NULL;
		pldm_msgbuf_span_string_utf16(buf, &loc, NULL);
		pdr->names[i].name = loc;
	}

	for (i = 0; i < pdr->name_string_count; i++) {
		void *loc = NULL;
		pldm_msgbuf_span_string_ascii(buf, &loc, NULL);
		pdr->names[i].tag = loc;
	}

	return pldm_msgbuf_destroy_consumed(buf);
}

LIBPLDM_ABI_STABLE
int decode_pldm_platform_cper_event(const void *event_data,
				    size_t event_data_length,
				    struct pldm_platform_cper_event *cper_event,
				    size_t cper_event_length)
{
	struct pldm_msgbuf _buf;
	struct pldm_msgbuf *buf = &_buf;
	int rc;

	if (!cper_event || !event_data) {
		return -EINVAL;
	}

	if (cper_event_length < sizeof(*cper_event)) {
		return -EINVAL;
	}

	rc = pldm_msgbuf_init_errno(buf, PLDM_PLATFORM_CPER_EVENT_MIN_LENGTH,
				    event_data, event_data_length);
	if (rc) {
		return rc;
	}

	pldm_msgbuf_extract(buf, cper_event->format_version);
	rc = pldm_msgbuf_extract(buf, cper_event->format_type);
	if (rc) {
		return rc;
	}
	if (cper_event->format_type != PLDM_PLATFORM_CPER_EVENT_WITH_HEADER &&
	    cper_event->format_type !=
		    PLDM_PLATFORM_CPER_EVENT_WITHOUT_HEADER) {
		return -EPROTO;
	}

	rc = pldm_msgbuf_extract(buf, cper_event->event_data_length);
	if (rc) {
		return rc;
	}

	if (cper_event->event_data_length >
	    (cper_event_length - sizeof(*cper_event))) {
		return -EOVERFLOW;
	}

	rc = pldm_msgbuf_extract_array_uint8(
		buf, cper_event->event_data_length, cper_event->event_data,
		cper_event_length - sizeof(*cper_event));
	if (rc) {
		return rc;
	}

	return pldm_msgbuf_destroy_consumed(buf);
}

LIBPLDM_ABI_STABLE
uint8_t *
pldm_platform_cper_event_event_data(struct pldm_platform_cper_event *event)
{
	return event->event_data;
}
