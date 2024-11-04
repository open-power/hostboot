/* SPDX-License-Identifier: Apache-2.0 OR GPL-2.0-or-later */
#include <endian.h>
#include <libpldm/oem/meta/file_io.h>

#include <cstdlib>
#include <new>

#include "msgbuf.h"

#include "gmock/gmock.h"
#include <gtest/gtest.h>

TEST(DecodeOemMetaFileIoWriteReq, testGoodDecodeRequest)
{
    constexpr const uint8_t postCode[4] = {0x93, 0xe0, 0x00, 0xea};
    struct pldm_msgbuf _ctx;
    struct pldm_msgbuf* ctx = &_ctx;
    int rc;

    constexpr size_t encodedPayloadLen =
        PLDM_OEM_META_FILE_IO_WRITE_REQ_MIN_LENGTH + sizeof(postCode);
    constexpr size_t encodedMsgLen = sizeof(pldm_msg_hdr) + encodedPayloadLen;
    alignas(pldm_msg) unsigned char encodedMsgBuf[encodedMsgLen] = {};
    auto* encodedMsg = new (encodedMsgBuf) pldm_msg;

    rc = pldm_msgbuf_init_errno(ctx, 0, encodedMsg->payload, encodedPayloadLen);
    ASSERT_EQ(rc, 0);

    pldm_msgbuf_insert_uint8(ctx, 0);
    pldm_msgbuf_insert_int32(ctx, sizeof(postCode));
    rc = pldm_msgbuf_insert_array_uint8(ctx, sizeof(postCode), postCode,
                                        sizeof(postCode));
    ASSERT_EQ(rc, 0);

    rc = pldm_msgbuf_destroy_consumed(ctx);
    ASSERT_EQ(rc, 0);

    constexpr size_t decodedReqLen =
        sizeof(struct pldm_oem_meta_file_io_write_req) + sizeof(postCode);
    alignas(pldm_oem_meta_file_io_write_req) unsigned char
        decodedReqBuf[decodedReqLen];
    auto* decodedReq = new (decodedReqBuf) pldm_oem_meta_file_io_write_req;
    auto* decodedReqData =
        static_cast<uint8_t*>(pldm_oem_meta_file_io_write_req_data(decodedReq));

    rc = decode_oem_meta_file_io_write_req(encodedMsg, encodedPayloadLen,
                                           decodedReq, decodedReqLen);
    ASSERT_EQ(rc, 0);

    EXPECT_EQ(decodedReq->handle, 0);
    ASSERT_EQ(decodedReq->length, sizeof(postCode));
    EXPECT_EQ(memcmp(decodedReqData, postCode, decodedReq->length), 0);
}

TEST(DecodeOemMetaFileIoWriteReq, testInvalidFieldsDecodeRequest)
{
    struct pldm_msg msg = {};

    auto rc = decode_oem_meta_file_io_write_req(&msg, sizeof(msg), NULL, 0);
    EXPECT_EQ(rc, -EINVAL);
}

TEST(DecodeOemMetaFileIoWriteReq, testInvalidLengthDecodeRequest)
{
    struct pldm_oem_meta_file_io_write_req req = {};
    struct pldm_msg msg = {};

    auto rc = decode_oem_meta_file_io_write_req(&msg, 0, &req, sizeof(req));
    EXPECT_EQ(rc, -EOVERFLOW);
}

TEST(DecodeOemMetaFileIoWriteReq, testInvalidDataRequest)
{
    struct pldm_oem_meta_file_io_write_req req = {};
    struct pldm_msg msg = {};
    int rc;

    rc = decode_oem_meta_file_io_write_req(
        &msg, PLDM_OEM_META_FILE_IO_WRITE_REQ_MIN_LENGTH - 1, &req,
        sizeof(req));
    EXPECT_EQ(rc, -EOVERFLOW);
}

TEST(DecodeOemMetaFileIoReadReq, testGoodDecodeRequest)
{
    struct pldm_msgbuf _ctx;
    struct pldm_msgbuf* ctx = &_ctx;
    int rc;

    constexpr size_t payloadLen = PLDM_OEM_META_FILE_IO_READ_REQ_MIN_LENGTH +
                                  PLDM_OEM_META_FILE_IO_READ_DATA_INFO_LENGTH;
    alignas(pldm_msg) unsigned char buf[sizeof(pldm_msg_hdr) + payloadLen]{};
    auto* msg = new (buf) pldm_msg;

    rc = pldm_msgbuf_init_errno(ctx, 0, msg->payload, payloadLen);
    ASSERT_EQ(rc, 0);

    pldm_msgbuf_insert_uint8(ctx, 0);
    pldm_msgbuf_insert_uint8(ctx, PLDM_OEM_META_FILE_IO_READ_DATA);
    pldm_msgbuf_insert_uint8(ctx, PLDM_OEM_META_FILE_IO_READ_DATA_INFO_LENGTH);
    pldm_msgbuf_insert_uint8(ctx, 1);
    pldm_msgbuf_insert_uint16(ctx, 1223);

    rc = pldm_msgbuf_destroy_consumed(ctx);
    ASSERT_EQ(rc, 0);

    struct pldm_oem_meta_file_io_read_req req = {};
    req.version = sizeof(req);
    rc = decode_oem_meta_file_io_read_req(msg, payloadLen, &req);
    ASSERT_EQ(rc, 0);

    EXPECT_EQ(req.handle, 0);
    EXPECT_EQ(req.option, PLDM_OEM_META_FILE_IO_READ_DATA);
    EXPECT_EQ(req.length, PLDM_OEM_META_FILE_IO_READ_DATA_INFO_LENGTH);
    EXPECT_EQ(req.info.data.transferFlag, 1);
    EXPECT_EQ(req.info.data.offset, 1223);
}

TEST(DecodeOemMetaFileIoReadReq, testInvalidFieldsDecodeRequest)
{
    struct pldm_msg msg = {};

    auto rc = decode_oem_meta_file_io_read_req(
        &msg, PLDM_OEM_META_FILE_IO_READ_REQ_MIN_LENGTH, NULL);
    EXPECT_EQ(rc, -EINVAL);
}

TEST(DecodeOemMetaFileIoReadReq, testInvalidLengthDecodeRequest)
{
    struct pldm_oem_meta_file_io_read_req req = {};
    struct pldm_msg msg = {};

    auto rc = decode_oem_meta_file_io_read_req(&msg, 0, &req);
    EXPECT_EQ(rc, -EOVERFLOW);
}

TEST(DecodeOemMetaFileIoReadReq, testInvalidDataRequest)
{
    struct pldm_oem_meta_file_io_read_req req = {};
    struct pldm_msg msg = {};

    auto rc = decode_oem_meta_file_io_read_req(
        &msg, PLDM_OEM_META_FILE_IO_READ_REQ_MIN_LENGTH - 1, &req);
    EXPECT_EQ(rc, -EOVERFLOW);
}

TEST(EncodeOemMetaFileIoReadResp, testGoodEncodeReadAttrResponse)
{
    int rc;

    alignas(pldm_oem_meta_file_io_read_resp) unsigned char
        decodedBuf[sizeof(pldm_oem_meta_file_io_read_resp)];
    auto* resp = new (decodedBuf) pldm_oem_meta_file_io_read_resp;
    resp->version = sizeof(struct pldm_oem_meta_file_io_read_resp);
    resp->completion_code = PLDM_SUCCESS;
    resp->handle = 1;
    resp->option = PLDM_OEM_META_FILE_IO_READ_ATTR;
    resp->length = 0;
    resp->info.attr.size = 0x1284;
    resp->info.attr.crc32 = 0xab715432;

    constexpr size_t payloadLen = PLDM_OEM_META_FILE_IO_READ_RESP_MIN_SIZE +
                                  PLDM_OEM_META_FILE_IO_READ_ATTR_INFO_LENGTH;
    alignas(pldm_msg) unsigned char
        encodedBuf[sizeof(pldm_msg_hdr) + payloadLen] = {};
    auto* msg = new (encodedBuf) pldm_msg;

    rc = encode_oem_meta_file_io_read_resp(
        0, resp, sizeof(pldm_oem_meta_file_io_read_resp), msg, payloadLen);
    ASSERT_EQ(rc, 0);

    EXPECT_THAT(encodedBuf, testing::ElementsAreArray(
                                {0x00, 0x3f, 0x03, 0x00, 0x01, 0x00, 0x00, 0x84,
                                 0x12, 0x32, 0x54, 0x71, 0xab}));
}

TEST(EncodeOemMetaFileIoReadResp, testGoodEncodeReadDataResponse)
{
    constexpr static const uint8_t readbuf[4] = {0x23, 0xca, 0x84, 0x9d};
    int rc;

    alignas(pldm_oem_meta_file_io_read_resp) unsigned char
        decodedBuf[sizeof(pldm_oem_meta_file_io_read_resp) + sizeof(readbuf)];
    auto* resp = new (decodedBuf) pldm_oem_meta_file_io_read_resp;
    resp->version = sizeof(struct pldm_oem_meta_file_io_read_resp);
    resp->completion_code = PLDM_SUCCESS;
    resp->handle = 1;
    resp->option = PLDM_OEM_META_FILE_IO_READ_DATA;
    resp->length = 4;
    resp->info.data.transferFlag = 0x05;
    resp->info.data.offset = 0x75cd;
    memcpy(pldm_oem_meta_file_io_read_resp_data(resp), readbuf,
           sizeof(readbuf));

    constexpr size_t payloadLen = PLDM_OEM_META_FILE_IO_READ_RESP_MIN_SIZE +
                                  PLDM_OEM_META_FILE_IO_READ_DATA_INFO_LENGTH +
                                  sizeof(readbuf);
    alignas(pldm_msg) unsigned char
        encodedBuf[sizeof(pldm_msg_hdr) + payloadLen] = {};
    auto* msg = new (encodedBuf) pldm_msg;

    rc = encode_oem_meta_file_io_read_resp(
        0, resp, sizeof(pldm_oem_meta_file_io_read_resp) + sizeof(readbuf), msg,
        payloadLen);
    ASSERT_EQ(rc, 0);

    EXPECT_THAT(encodedBuf, testing::ElementsAreArray(
                                {0x00, 0x3f, 0x03, 0x00, 0x01, 0x01, 0x04, 0x05,
                                 0xcd, 0x75, 0x23, 0xca, 0x84, 0x9d}));
}

TEST(EncodeOemMetaFileIoReadResp, testInvalidFieldsEncodeResponse)
{
    struct pldm_msg msg = {};

    auto rc = encode_oem_meta_file_io_read_resp(
        0, NULL, 0, &msg, PLDM_OEM_META_FILE_IO_READ_RESP_MIN_SIZE);
    EXPECT_EQ(rc, -EINVAL);
}

TEST(EncodeOemMetaFileIoReadResp, testInvalidLengthEncodeResponse)
{
    struct pldm_oem_meta_file_io_read_resp resp = {};
    struct pldm_msg msg = {};

    auto rc =
        encode_oem_meta_file_io_read_resp(0, &resp, sizeof(resp), &msg, 0);
    EXPECT_EQ(rc, -EOVERFLOW);
}

TEST(EncodeOemMetaFileIoReadResp, testInvalidDataEncodeResponse)
{
    struct pldm_oem_meta_file_io_read_resp resp = {};
    struct pldm_msg msg = {};

    auto rc = encode_oem_meta_file_io_read_resp(
        0, &resp, sizeof(resp), &msg,
        PLDM_OEM_META_FILE_IO_READ_RESP_MIN_SIZE - 1);
    EXPECT_EQ(rc, -EOVERFLOW);
}
