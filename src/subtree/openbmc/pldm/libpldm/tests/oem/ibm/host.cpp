#include <endian.h>
#include <libpldm/base.h>
#include <libpldm/oem/ibm/host.h>

#include <array>
#include <cstdint>
#include <cstring>
#include <new>
#include <vector>

#include <gmock/gmock.h>
#include <gtest/gtest.h>

TEST(GetAlertStatus, testGoodEncodeRequest)
{
    PLDM_MSG_DEFINE_P(request, PLDM_GET_ALERT_STATUS_REQ_BYTES);

    uint8_t versionId = 0x0;

    auto rc = encode_get_alert_status_req(0, versionId, request,
                                          PLDM_GET_ALERT_STATUS_REQ_BYTES);
    EXPECT_EQ(rc, PLDM_SUCCESS);
    EXPECT_EQ(versionId, request->payload[0]);
}

TEST(GetAlertStatus, testBadEncodeRequest)
{
    PLDM_MSG_DEFINE_P(request, PLDM_GET_ALERT_STATUS_REQ_BYTES);
    auto rc = encode_get_alert_status_req(0, 0x0, request,
                                          PLDM_GET_ALERT_STATUS_REQ_BYTES + 1);
    EXPECT_EQ(rc, PLDM_ERROR_INVALID_LENGTH);
}

TEST(GetAlertStatus, testGoodDecodeResponse)
{
    uint8_t completionCode = PLDM_SUCCESS;
    uint32_t rack_entry = 0xff000030;
    uint32_t pri_cec_node = 0x00008030;

    PLDM_MSG_DEFINE_P(response, PLDM_GET_ALERT_STATUS_RESP_BYTES);
    auto* resp = new (response->payload) pldm_get_alert_status_resp;
    resp->completion_code = completionCode;
    resp->rack_entry = htole32(rack_entry);
    resp->pri_cec_node = htole32(pri_cec_node);

    uint8_t retCompletionCode = 0;
    uint32_t retRack_entry = 0;
    uint32_t retPri_cec_node = 0;

    auto rc = decode_get_alert_status_resp(
        response, PLDM_GET_ALERT_STATUS_RESP_BYTES, &retCompletionCode,
        &retRack_entry, &retPri_cec_node);
    EXPECT_EQ(rc, PLDM_SUCCESS);
    EXPECT_EQ(retCompletionCode, completionCode);
    EXPECT_EQ(retRack_entry, rack_entry);
    EXPECT_EQ(retPri_cec_node, pri_cec_node);
}

TEST(GetAlertStatus, testBadDecodeResponse)
{
    auto rc = decode_get_alert_status_resp(NULL, 0, NULL, NULL, NULL);
    EXPECT_EQ(rc, PLDM_ERROR_INVALID_DATA);

    uint8_t completionCode = PLDM_SUCCESS;
    uint32_t rack_entry = 0xff000030;
    uint32_t pri_cec_node = 0x00008030;

    PLDM_MSG_DEFINE_P(response, PLDM_GET_ALERT_STATUS_RESP_BYTES);
    auto* resp = new (response->payload) pldm_get_alert_status_resp;
    resp->completion_code = completionCode;
    resp->rack_entry = htole32(rack_entry);
    resp->pri_cec_node = htole32(pri_cec_node);

    uint8_t retCompletionCode = 0;
    uint32_t retRack_entry = 0;
    uint32_t retPri_cec_node = 0;

    rc = decode_get_alert_status_resp(
        response, PLDM_GET_ALERT_STATUS_RESP_BYTES + 1, &retCompletionCode,
        &retRack_entry, &retPri_cec_node);
    EXPECT_EQ(rc, PLDM_ERROR_INVALID_LENGTH);
}

TEST(GetAlertStatus, testGoodEncodeResponse)
{
    uint32_t rack_entry = 0xff000030;
    uint32_t pri_cec_node = 0x00008030;

    PLDM_MSG_DEFINE_P(response, PLDM_GET_ALERT_STATUS_RESP_BYTES);

    auto rc = encode_get_alert_status_resp(0, PLDM_SUCCESS, rack_entry,
                                           pri_cec_node, response,
                                           PLDM_GET_ALERT_STATUS_RESP_BYTES);

    ASSERT_EQ(rc, PLDM_SUCCESS);
    EXPECT_THAT(response_buf, testing::ElementsAreArray(
                                  {0x00, 0x3f, 0xf0, 0x00, 0x30, 0x00, 0x00,
                                   0xff, 0x30, 0x80, 0x00, 0x00}));
}

TEST(GetAlertStatus, testBadEncodeResponse)
{
    uint32_t rack_entry = 0xff000030;
    uint32_t pri_cec_node = 0x00008030;

    PLDM_MSG_DEFINE_P(response, PLDM_GET_ALERT_STATUS_RESP_BYTES);

    auto rc = encode_get_alert_status_resp(
        0, PLDM_SUCCESS, rack_entry, pri_cec_node, response,
        PLDM_GET_ALERT_STATUS_RESP_BYTES + 1);

    EXPECT_EQ(rc, PLDM_ERROR_INVALID_DATA);
}

TEST(GetAlertStatus, testGoodDecodeRequest)
{
    uint8_t versionId = 0x0;
    uint8_t retVersionId;

    PLDM_MSG_DEFINE_P(req, PLDM_GET_ALERT_STATUS_REQ_BYTES);
    req->payload[0] = versionId;

    auto rc = decode_get_alert_status_req(req, PLDM_GET_ALERT_STATUS_REQ_BYTES,
                                          &retVersionId);

    EXPECT_EQ(rc, PLDM_SUCCESS);
    EXPECT_EQ(retVersionId, versionId);
}

TEST(GetAlertStatus, testBadDecodeRequest)
{
    uint8_t versionId = 0x0;
    uint8_t retVersionId;

    PLDM_MSG_DEFINE_P(req, PLDM_GET_ALERT_STATUS_REQ_BYTES);
    req->payload[0] = versionId;

    auto rc = decode_get_alert_status_req(
        req, PLDM_GET_ALERT_STATUS_REQ_BYTES + 1, &retVersionId);

    EXPECT_EQ(rc, PLDM_ERROR_INVALID_LENGTH);
}
