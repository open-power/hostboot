// NOLINTNEXTLINE(bugprone-suspicious-include)
#include "responder.c"

#include <gtest/gtest.h>

TEST(Responder, track_untrack_one)
{
    struct pldm_responder_cookie jar
    {
    };
    struct pldm_responder_cookie cookie = {
        .tid = 1,
        .instance_id = 1,
        .type = 0,
        .command = 0x01, /* SetTID */
        .next = nullptr,
    };

    ASSERT_EQ(pldm_responder_cookie_track(&jar, &cookie), 0);
    ASSERT_NE(jar.next, nullptr);
    ASSERT_EQ(pldm_responder_cookie_untrack(&jar, 1, 1, 0, 0x01), &cookie);
    ASSERT_EQ(jar.next, nullptr);
}

TEST(Responder, untrack_none)
{
    struct pldm_responder_cookie jar
    {
    };

    ASSERT_EQ(jar.next, nullptr);
    ASSERT_EQ(pldm_responder_cookie_untrack(&jar, 1, 1, 0, 0x01), nullptr);
    ASSERT_EQ(jar.next, nullptr);
}

TEST(Responder, track_one_untrack_bad)
{
    struct pldm_responder_cookie jar
    {
    };
    struct pldm_responder_cookie cookie = {
        .tid = 1,
        .instance_id = 1,
        .type = 0,
        .command = 0x01, /* SetTID */
        .next = nullptr,
    };

    ASSERT_EQ(pldm_responder_cookie_track(&jar, &cookie), 0);
    ASSERT_NE(jar.next, nullptr);
    ASSERT_EQ(pldm_responder_cookie_untrack(&jar, 2, 1, 0, 0x01), nullptr);
    ASSERT_EQ(pldm_responder_cookie_untrack(&jar, 1, 2, 0, 0x01), nullptr);
    ASSERT_EQ(pldm_responder_cookie_untrack(&jar, 1, 1, 1, 0x01), nullptr);
    ASSERT_EQ(pldm_responder_cookie_untrack(&jar, 1, 1, 0, 0x02), nullptr);
    ASSERT_NE(jar.next, nullptr);
    ASSERT_EQ(pldm_responder_cookie_untrack(&jar, 1, 1, 0, 0x01), &cookie);
    ASSERT_EQ(jar.next, nullptr);
}

TEST(Responder, track_untrack_two)
{
    struct pldm_responder_cookie jar
    {
    };
    struct pldm_responder_cookie cookies[] = {
        {
            .tid = 1,
            .instance_id = 1,
            .type = 0,
            .command = 0x01, /* SetTID */
            .next = nullptr,
        },
        {
            .tid = 2,
            .instance_id = 1,
            .type = 0,
            .command = 0x01, /* SetTID */
            .next = nullptr,
        },
    };

    ASSERT_EQ(pldm_responder_cookie_track(&jar, &cookies[0]), 0);
    ASSERT_EQ(pldm_responder_cookie_track(&jar, &cookies[1]), 0);
    ASSERT_NE(jar.next, nullptr);
    ASSERT_EQ(pldm_responder_cookie_untrack(&jar, 2, 1, 0, 0x01), &cookies[1]);
    ASSERT_EQ(pldm_responder_cookie_untrack(&jar, 1, 1, 0, 0x01), &cookies[0]);
    ASSERT_EQ(jar.next, nullptr);
}
