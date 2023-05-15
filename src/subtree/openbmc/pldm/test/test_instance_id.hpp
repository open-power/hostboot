#pragma once

#include "instance_id.hpp"

static constexpr uintmax_t pldmMaxInstanceIds = 32;

class TestInstanceIdDb : public pldm::InstanceIdDb
{
  public:
    TestInstanceIdDb() : TestInstanceIdDb(createDb()) {}

    ~TestInstanceIdDb()
    {
        std::filesystem::remove(dbPath);
    };

  private:
    static std::filesystem::path createDb()
    {
        static const char dbTmpl[] = "/tmp/db.XXXXXX";
        char dbName[sizeof(dbTmpl)] = {};

        ::strncpy(dbName, dbTmpl, sizeof(dbName));
        ::close(::mkstemp(dbName));

        std::filesystem::path dbPath(dbName);
        std::filesystem::resize_file(
            dbPath, static_cast<uintmax_t>(PLDM_MAX_TIDS) * pldmMaxInstanceIds);

        return dbPath;
    };

    TestInstanceIdDb(std::filesystem::path dbPath) :
        InstanceIdDb(dbPath), dbPath(dbPath)
    {}

    std::filesystem::path dbPath;
};
