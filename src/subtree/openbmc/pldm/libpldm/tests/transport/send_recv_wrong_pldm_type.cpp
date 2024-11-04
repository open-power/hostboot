#include <libpldm/transport.h>

#include "array.h"
#include "transport/test.h"

#include <gtest/gtest.h>

TEST(Transport, send_recv_wrong_pldm_type)
{
    uint8_t req[] = {0x81, 0x00, 0x01, 0x01};
    uint8_t resp[] = {0x01, 0x01, 0x01, 0x00};
    const struct pldm_transport_test_descriptor seq[] = {
        {
            .type = PLDM_TRANSPORT_TEST_ELEMENT_MSG_SEND,
            .send_msg =
                {
                    .dst = 1,
                    .msg = req,
                    .len = sizeof(req),
                },
        },
        {
            .type = PLDM_TRANSPORT_TEST_ELEMENT_LATENCY,
            .latency =
                {
                    .it_interval = {0, 0},
                    .it_value = {1, 0},
                },
        },
        {
            .type = PLDM_TRANSPORT_TEST_ELEMENT_MSG_RECV,
            .recv_msg =
                {
                    .src = 2,
                    .msg = resp,
                    .len = sizeof(resp),
                },
        },
        {
            .type = PLDM_TRANSPORT_TEST_ELEMENT_LATENCY,
            .latency =
                {
                    .it_interval = {0, 0},
                    .it_value = {4, 0},
                },
        },
    };
    struct pldm_transport_test* test = NULL;
    struct pldm_transport* ctx;
    size_t len;
    void* msg;
    int rc;

    EXPECT_EQ(pldm_transport_test_init(&test, seq, ARRAY_SIZE(seq)), 0);
    ctx = pldm_transport_test_core(test);
    rc = pldm_transport_send_recv_msg(ctx, 1, req, sizeof(req), &msg, &len);
    EXPECT_EQ(rc, PLDM_REQUESTER_RECV_FAIL);
    pldm_transport_test_destroy(test);
}
