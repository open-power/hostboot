#include <libpldm/base.h>
#include <libpldm/instance-id.h>

#include <cerrno>
#include <cstdlib>
#include <cstring>
#include <filesystem>

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

TEST_F(PldmInstanceDbTest, releaseConflictedSameTid)
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
    pldm_instance_id_t iid;

    /* Allocate IID 0 for the TID to the first connection */
    ASSERT_EQ(pldm_instance_db_init(&connections[0].db, dbPath.c_str()), 0);
    EXPECT_EQ(
        pldm_instance_id_alloc(connections[0].db, tid, &connections[0].iid), 0);

    /*
     * On the second connection, allocate the first available IID for the TID.
     * This should generate a conflict on IID 0 (allocated to the first
     * connection), and result in IID 1 being provided.
     *
     * There should now be one read lock held on each of IID 0 and IID 1 for TID
     * 1 (by the first and second connections respectively).
     */
    ASSERT_EQ(pldm_instance_db_init(&connections[1].db, dbPath.c_str()), 0);
    EXPECT_EQ(
        pldm_instance_id_alloc(connections[1].db, tid, &connections[1].iid), 0);

    /*
     * Make sure the implementation hasn't allocated the connections a
     * conflicting IID for the TID.
     */
    EXPECT_NE(connections[0].iid, connections[1].iid);

    /*
     * Now free the IID allocated to the first connection.
     *
     * We should be able to re-acquire this later.
     */
    EXPECT_EQ(pldm_instance_id_free(connections[0].db, tid, connections[0].iid),
              0);

    /*
     * Iterate through the IID space on the first connection to wrap it back
     * around to IID 0.
     *
     * Note that:
     *
     * 1. The first connection has already allocated (and released) IID 0,
     *    eliminating one iteration
     *
     * 2. IID 1 is held by the second connection. This eliminates a second
     *    iteration as it must be skipped to avoid a conflict.
     */
    for (int i = 0; i < (pldmMaxInstanceIds - 1 - 1); i++)
    {
        EXPECT_EQ(pldm_instance_id_alloc(connections[0].db, tid, &iid), 0);
        EXPECT_EQ(pldm_instance_id_free(connections[0].db, tid, iid), 0);
    }

    /*
     * The next IID allocated to the first connection should be the IID it
     * allocated initially (which should be 0).
     */
    EXPECT_EQ(pldm_instance_id_alloc(connections[0].db, tid, &iid), 0);
    EXPECT_EQ(iid, connections[0].iid);

    /* Now tidy up */
    ASSERT_EQ(pldm_instance_id_free(connections[0].db, tid, iid), 0);

    EXPECT_EQ(pldm_instance_id_free(connections[1].db, tid, connections[1].iid),
              0);
    ASSERT_EQ(pldm_instance_db_destroy(connections[1].db), 0);
    ASSERT_EQ(pldm_instance_db_destroy(connections[0].db), 0);
}

TEST_F(PldmInstanceDbTest, freeUnallocatedInstanceId)
{
    struct pldm_instance_db* db = nullptr;
    const pldm_tid_t tid = 1;

    ASSERT_EQ(pldm_instance_db_init(&db, dbPath.c_str()), 0);
    EXPECT_NE(pldm_instance_id_free(db, tid, 0), 0);
    ASSERT_EQ(pldm_instance_db_destroy(db), 0);
}
