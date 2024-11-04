#include <libpldm/transport.h>

#include "array.h"
#include "transport/test.h"

#include <gtest/gtest.h>

TEST(Transport, send_recv_timeout)
{
    uint8_t req[] = {0x81, 0x00, 0x01, 0x01};
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
                    .it_value = {5, 0},
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
