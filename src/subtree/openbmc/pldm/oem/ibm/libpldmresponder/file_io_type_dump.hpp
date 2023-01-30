#pragma once

#include "file_io_by_type.hpp"

namespace pldm
{
namespace responder
{
using DumpEntryInterface = std::string;

/** @class DumpHandler
 *
 *  @brief Inherits and implements FileHandler. This class is used
 *  handle the dump offload/streaming from host to the destination via bmc
 */
class DumpHandler : public FileHandler
{
  public:
    /** @brief DumpHandler constructor
     */
    DumpHandler(uint32_t fileHandle, uint16_t fileType) :
        FileHandler(fileHandle), dumpType(fileType)
    {}

    virtual int writeFromMemory(uint32_t offset, uint32_t length,
                                uint64_t address,
                                oem_platform::Handler* /*oemPlatformHandler*/);

    virtual int readIntoMemory(uint32_t offset, uint32_t& length,
                               uint64_t address,
                               oem_platform::Handler* /*oemPlatformHandler*/);

    virtual int read(uint32_t offset, uint32_t& length, Response& response,
                     oem_platform::Handler* /*oemPlatformHandler*/);

    virtual int write(const char* buffer, uint32_t offset, uint32_t& length,
                      oem_platform::Handler* /*oemPlatformHandler*/);

    virtual int newFileAvailable(uint64_t length);

    virtual int fileAck(uint8_t fileStatus);

    std::string findDumpObjPath(uint32_t fileHandle);
    std::string getOffloadUri(uint32_t fileHandle);

    /** @brief DumpHandler destructor
     */
    ~DumpHandler()
    {}

  private:
    static int fd;     //!< fd to manage the dump offload to bmc
    uint16_t dumpType; //!< type of the dump
};

} // namespace responder
} // namespace pldm
