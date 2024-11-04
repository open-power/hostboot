/* SPDX-License-Identifier: Apache-2.0 OR GPL-2.0-or-later */
#include <libpldm/oem/meta/file_io.h>
#include <endian.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "api.h"
#include "msgbuf.h"
#include "dsp/base.h"

LIBPLDM_ABI_STABLE
void *pldm_oem_meta_file_io_write_req_data(
	struct pldm_oem_meta_file_io_write_req *req)
{
	return req->data;
}

LIBPLDM_ABI_STABLE
int decode_oem_meta_file_io_write_req(
	const struct pldm_msg *msg, size_t payload_length,
	struct pldm_oem_meta_file_io_write_req *req, size_t req_length)
{
	struct pldm_msgbuf _buf;
	struct pldm_msgbuf *buf = &_buf;
	int rc;

	if (msg == NULL || req == NULL) {
		return -EINVAL;
	}

	if (req_length < sizeof(*req)) {
		return -EINVAL;
	}

	rc = pldm_msgbuf_init_errno(buf,
				    PLDM_OEM_META_FILE_IO_WRITE_REQ_MIN_LENGTH,
				    msg->payload, payload_length);
	if (rc) {
		return rc;
	}

	pldm_msgbuf_extract(buf, req->handle);
	rc = pldm_msgbuf_extract(buf, req->length);
	if (rc) {
		return rc;
	}

	rc = pldm_msgbuf_extract_array(buf, req->length, req->data,
				       req_length - sizeof(*req));
	if (rc) {
		return rc;
	}

	return pldm_msgbuf_destroy_consumed(buf);
}

LIBPLDM_ABI_DEPRECATED_UNSAFE
int decode_oem_meta_file_io_req(const struct pldm_msg *msg,
				size_t payload_length, uint8_t *file_handle,
				uint32_t *length, uint8_t *data)
{
	struct pldm_oem_meta_file_io_write_req *request_msg;
	size_t request_msg_len;
	int rc;

	if (msg == NULL || file_handle == NULL || length == NULL ||
	    data == NULL) {
		return pldm_xlate_errno(-EINVAL);
	}

	if (SIZE_MAX - sizeof(*request_msg) < payload_length) {
		return pldm_xlate_errno(-EOVERFLOW);
	}

	request_msg_len = sizeof(*request_msg) + payload_length;
	request_msg = malloc(request_msg_len);

	rc = decode_oem_meta_file_io_write_req(msg, payload_length, request_msg,
					       request_msg_len);
	if (rc < 0) {
		free(request_msg);
		return pldm_xlate_errno(rc);
	}

	*file_handle = request_msg->handle;
	*length = request_msg->length;

	/* NOTE: Unsafe, memory safety is not possible due to API constraints. */
	memcpy(data, request_msg->data, request_msg->length);

	free(request_msg);

	return 0;
}

LIBPLDM_ABI_STABLE
int decode_oem_meta_file_io_read_req(const struct pldm_msg *msg,
				     size_t payload_length,
				     struct pldm_oem_meta_file_io_read_req *req)
{
	struct pldm_msgbuf _buf;
	struct pldm_msgbuf *buf = &_buf;

	if (msg == NULL || req == NULL) {
		return -EINVAL;
	}

	if (req->version > sizeof(struct pldm_oem_meta_file_io_read_req)) {
		return -E2BIG;
	}

	int rc = pldm_msgbuf_init_errno(
		buf, PLDM_OEM_META_FILE_IO_READ_REQ_MIN_LENGTH, msg->payload,
		payload_length);
	if (rc) {
		return rc;
	}

	pldm_msgbuf_extract(buf, req->handle);
	rc = pldm_msgbuf_extract(buf, req->option);
	if (rc) {
		return rc;
	}

	rc = pldm_msgbuf_extract(buf, req->length);
	if (rc) {
		return rc;
	}

	switch (req->option) {
	case PLDM_OEM_META_FILE_IO_READ_ATTR:
		if (req->length != 0) {
			return -EPROTO;
		}
		break;
	case PLDM_OEM_META_FILE_IO_READ_DATA:
		pldm_msgbuf_extract(buf, req->info.data.transferFlag);
		pldm_msgbuf_extract(buf, req->info.data.offset);
		break;
	default:
		return -EPROTO;
	}

	return pldm_msgbuf_destroy_consumed(buf);
}

LIBPLDM_ABI_STABLE
void *pldm_oem_meta_file_io_read_resp_data(
	struct pldm_oem_meta_file_io_read_resp *resp)
{
	return resp->data;
}

LIBPLDM_ABI_STABLE
int encode_oem_meta_file_io_read_resp(
	uint8_t instance_id, struct pldm_oem_meta_file_io_read_resp *resp,
	size_t resp_len, struct pldm_msg *responseMsg, size_t payload_length)
{
	int rc;
	struct pldm_msgbuf _buf;
	struct pldm_msgbuf *buf = &_buf;
	struct pldm_header_info header = { 0 };

	if (resp == NULL || responseMsg == NULL) {
		return -EINVAL;
	}

	if (resp_len < sizeof(*resp)) {
		return -EINVAL;
	}

	if (resp->version > sizeof(*resp)) {
		return -E2BIG;
	}

	header.instance = instance_id;
	header.msg_type = PLDM_RESPONSE;
	header.pldm_type = PLDM_OEM;
	header.command = PLDM_OEM_META_FILE_IO_CMD_READ_FILE;
	rc = pack_pldm_header_errno(&header, &(responseMsg->hdr));
	if (rc) {
		return rc;
	}

	rc = pldm_msgbuf_init_errno(buf,
				    PLDM_OEM_META_FILE_IO_READ_RESP_MIN_SIZE,
				    responseMsg->payload, payload_length);
	if (rc) {
		return rc;
	}

	pldm_msgbuf_insert(buf, resp->completion_code);
	pldm_msgbuf_insert(buf, resp->handle);
	pldm_msgbuf_insert(buf, resp->option);
	pldm_msgbuf_insert(buf, resp->length);

	switch (resp->option) {
	case PLDM_OEM_META_FILE_IO_READ_ATTR:
		pldm_msgbuf_insert(buf, resp->info.attr.size);
		pldm_msgbuf_insert(buf, resp->info.attr.crc32);
		break;
	case PLDM_OEM_META_FILE_IO_READ_DATA:
		pldm_msgbuf_insert(buf, resp->info.data.transferFlag);
		pldm_msgbuf_insert(buf, resp->info.data.offset);
		rc = pldm_msgbuf_insert_array_uint8(buf, resp->length,
						    resp->data,
						    resp_len - sizeof(*resp));
		if (rc) {
			return rc;
		}
		break;
	default:
		return -EPROTO;
	}

	return pldm_msgbuf_destroy(buf);
}
