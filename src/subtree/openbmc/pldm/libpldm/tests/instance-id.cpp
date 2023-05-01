#include "libpldm/instance-id.h"

#include <cerrno>
#include <cstdlib>
#include <cstring>
#include <filesystem>

#include "libpldm/base.h"

#include <gtest/gtest.h>

static constexpr auto pldmMaxInstanceIds = 32;
static const std::filesystem::path nonexistentDb = {"remove-this-file"};

TEST(InstanceId, dbInstanceNullDb)
{
    ASSERT_FALSE(std::filesystem::exists(nonexistentDb));
    EXPECT_EQ(::pldm_instance_db_init(nullptr, nonexistentDb.c_str()), -EINVAL);
}

TEST(InstanceId, dbInstanceNonNullDerefDb)
{
    struct pldm_instance_db* db = (struct pldm_instance_db*)8;

    ASSERT_FALSE(std::filesystem::exists(nonexistentDb));
    EXPECT_EQ(::pldm_instance_db_init(&db, nonexistentDb.c_str()), -EINVAL);
}

TEST(InstanceId, dbInstanceInvalidPath)
{
    struct pldm_instance_db* db = nullptr;

    EXPECT_NE(::pldm_instance_db_init(&db, ""), 0);
}

class PldmInstanceDbTest : public ::testing::Test
{
  protected:
    void SetUp() override
    {
        static const char dbTmpl[] = "db.XXXXXX";
        char dbName[sizeof(dbTmpl)] = {};

        ::strncpy(dbName, dbTmpl, sizeof(dbName));
        fd = ::mkstemp(dbName);
        ASSERT_NE(fd, -1);

        dbPath = std::filesystem::path(dbName);
        std::filesystem::resize_file(
            dbPath, (uintmax_t)(PLDM_MAX_TIDS)*pldmMaxInstanceIds);
    }

    void TearDown() override
    {
        std::filesystem::remove(dbPath);
        ::close(fd);
    }

    std::filesystem::path dbPath;

  private:
    int fd;
};

TEST_F(PldmInstanceDbTest, dbLengthZero)
{
    struct pldm_instance_db* db = nullptr;

    std::filesystem::resize_file(dbPath, 0);
    EXPECT_EQ(pldm_instance_db_init(&db, dbPath.c_str()), -EINVAL);
}

TEST_F(PldmInstanceDbTest, dbLengthShort)
{
    struct pldm_instance_db* db = nullptr;

    std::filesystem::resize_file(dbPath,
                                 PLDM_MAX_TIDS * pldmMaxInstanceIds - 1);
    EXPECT_EQ(pldm_instance_db_init(&db, dbPath.c_str()), -EINVAL);
}

TEST_F(PldmInstanceDbTest, dbInstance)
{
    struct pldm_instance_db* db = nullptr;

    EXPECT_EQ(pldm_instance_db_init(&db, dbPath.c_str()), 0);
    EXPECT_EQ(pldm_instance_db_destroy(db), 0);
}

TEST_F(PldmInstanceDbTest, allocFreeOne)
{
    struct pldm_instance_db* db = nullptr;
    const pldm_tid_t tid = 1;
    pldm_instance_id_t iid;

    ASSERT_EQ(pldm_instance_db_init(&db, dbPath.c_str()), 0);
    EXPECT_EQ(pldm_instance_id_alloc(db, tid, &iid), 0);
    EXPECT_EQ(pldm_instance_id_free(db, tid, iid), 0);
    ASSERT_EQ(pldm_instance_db_destroy(db), 0);
}

TEST_F(PldmInstanceDbTest, allocFreeTwoSerialSameTid)
{
    static constexpr pldm_tid_t tid = 1;

    struct pldm_instance_db* db = nullptr;
    pldm_instance_id_t first;
    pldm_instance_id_t second;

    ASSERT_EQ(pldm_instance_db_init(&db, dbPath.c_str()), 0);
    EXPECT_EQ(pldm_instance_id_alloc(db, tid, &first), 0);
    EXPECT_EQ(pldm_instance_id_free(db, tid, first), 0);
    EXPECT_EQ(pldm_instance_id_alloc(db, tid, &second), 0);
    EXPECT_EQ(pldm_instance_id_free(db, tid, second), 0);
    EXPECT_NE(first, second);
    ASSERT_EQ(pldm_instance_db_destroy(db), 0);
}

TEST_F(PldmInstanceDbTest, allocFreeTwoSerialDifferentTid)
{
    struct
    {
        pldm_tid_t tid;
        pldm_instance_id_t iid;
    } instances[] = {
        {1, 0},
        {2, 0},
    };

    struct pldm_instance_db* db = nullptr;

    ASSERT_EQ(pldm_instance_db_init(&db, dbPath.c_str()), 0);

    EXPECT_EQ(pldm_instance_id_alloc(db, instances[0].tid, &instances[0].iid),
              0);
    EXPECT_EQ(pldm_instance_id_alloc(db, instances[1].tid, &instances[1].iid),
              0);

    EXPECT_EQ(instances[0].iid, instances[1].iid);

    EXPECT_EQ(pldm_instance_id_free(db, instances[1].tid, instances[1].iid), 0);
    EXPECT_EQ(pldm_instance_id_free(db, instances[0].tid, instances[0].iid), 0);

    ASSERT_EQ(pldm_instance_db_destroy(db), 0);
}

TEST_F(PldmInstanceDbTest, allocFreeTwoConcurrentSameTid)
{
    static constexpr pldm_tid_t tid = 1;

    struct
    {
        struct pldm_instance_db* db;
        pldm_instance_id_t iid;
    } connections[] = {
        {nullptr, 0},
        {nullptr, 0},
    };

    ASSERT_EQ(pldm_instance_db_init(&connections[0].db, dbPath.c_str()), 0);
    EXPECT_EQ(
        pldm_instance_id_alloc(connections[0].db, tid, &connections[0].iid), 0);

    ASSERT_EQ(pldm_instance_db_init(&connections[1].db, dbPath.c_str()), 0);
    EXPECT_EQ(
        pldm_instance_id_alloc(connections[1].db, tid, &connections[1].iid), 0);

    EXPECT_NE(connections[0].iid, connections[1].iid);

    EXPECT_EQ(pldm_instance_id_free(connections[1].db, tid, connections[1].iid),
              0);
    ASSERT_EQ(pldm_instance_db_destroy(connections[1].db), 0);

    EXPECT_EQ(pldm_instance_id_free(connections[0].db, tid, connections[0].iid),
              0);
    ASSERT_EQ(pldm_instance_db_destroy(connections[0].db), 0);
}

TEST_F(PldmInstanceDbTest, allocFreeTwoConcurrentDifferentTid)
{
    struct
    {
        struct pldm_instance_db* db;
        pldm_tid_t tid;
        pldm_instance_id_t iid;
    } connections[] = {
        {nullptr, 1, 0},
        {nullptr, 2, 0},
    };

    ASSERT_EQ(pldm_instance_db_init(&connections[0].db, dbPath.c_str()), 0);
    EXPECT_EQ(pldm_instance_id_alloc(connections[0].db, connections[0].tid,
                                     &connections[0].iid),
              0);

    ASSERT_EQ(pldm_instance_db_init(&connections[1].db, dbPath.c_str()), 0);
    EXPECT_EQ(pldm_instance_id_alloc(connections[1].db, connections[1].tid,
                                     &connections[1].iid),
              0);

    EXPECT_EQ(connections[0].iid, connections[1].iid);

    EXPECT_EQ(pldm_instance_id_free(connections[1].db, connections[1].tid,
                                    connections[1].iid),
              0);
    ASSERT_EQ(pldm_instance_db_destroy(connections[1].db), 0);

    EXPECT_EQ(pldm_instance_id_free(connections[0].db, connections[0].tid,
                                    connections[0].iid),
              0);
    ASSERT_EQ(pldm_instance_db_destroy(connections[0].db), 0);
}

TEST_F(PldmInstanceDbTest, allocAllInstanceIds)
{
    static constexpr pldm_tid_t tid = 1;

    struct pldm_instance_db* db = nullptr;
    std::array<pldm_instance_id_t, pldmMaxInstanceIds> iids = {};
    pldm_instance_id_t extra;

    ASSERT_EQ(pldm_instance_db_init(&db, dbPath.c_str()), 0);

    for (auto& iid : iids)
    {
        EXPECT_EQ(pldm_instance_id_alloc(db, tid, &iid), 0);
    }

    EXPECT_EQ(pldm_instance_id_alloc(db, tid, &extra), -EAGAIN);

    for (auto& iid : iids)
    {
        EXPECT_EQ(pldm_instance_id_free(db, tid, iid), 0);
    }

    EXPECT_EQ(pldm_instance_id_alloc(db, tid, &extra), 0);

    ASSERT_EQ(pldm_instance_db_destroy(db), 0);
}

TEST_F(PldmInstanceDbTest, freeUnallocatedInstanceId)
{
    struct pldm_instance_db* db = nullptr;
    const pldm_tid_t tid = 1;

    ASSERT_EQ(pldm_instance_db_init(&db, dbPath.c_str()), 0);
    EXPECT_NE(pldm_instance_id_free(db, tid, 0), 0);
    ASSERT_EQ(pldm_instance_db_destroy(db), 0);
}
