#pragma once

#include "config.h"

#include "file_io_by_type.hpp"

#include <sstream>
#include <string>

namespace pldm
{
namespace responder
{

using namespace pldm::responder::dma;

/** @class LidHandler
 *
 *  @brief Inherits and implements FileHandler. This class is used
 *  to read/write LIDs.
 */
class LidHandler : public FileHandler
{
  public:
    /** @brief LidHandler constructor
     */
    LidHandler(uint32_t fileHandle, bool permSide) : FileHandler(fileHandle)
    {
        std::string dir = permSide ? LID_PERM_DIR : LID_TEMP_DIR;
        std::stringstream stream;
        stream << std::hex << fileHandle;
        lidPath = std::move(dir) + '/' + stream.str() + ".lid";
    }

    virtual int writeFromMemory(uint32_t /*offset*/, uint32_t /*length*/,
                                uint64_t /*address*/)
    {
        return PLDM_ERROR_UNSUPPORTED_PLDM_CMD;
    }

    virtual int readIntoMemory(uint32_t offset, uint32_t& length,
                               uint64_t address)
    {
        return transferFileData(lidPath, true, offset, length, address);
    }

    virtual int write(const char* /*buffer*/, uint32_t /*offset*/,
                      uint32_t& /*length*/)
    {
        return PLDM_ERROR_UNSUPPORTED_PLDM_CMD;
    }

    virtual int read(uint32_t offset, uint32_t& length, Response& response)
    {
        return readFile(lidPath, offset, length, response);
    }

    virtual int fileAck(uint8_t /*fileStatus*/)
    {
        return PLDM_ERROR_UNSUPPORTED_PLDM_CMD;
    }

    virtual int newFileAvailable(uint64_t /*length*/)

    {
        return PLDM_ERROR_UNSUPPORTED_PLDM_CMD;
    }

    /** @brief LidHandler destructor
     */
    ~LidHandler()
    {}

  protected:
    std::string lidPath;
};

} // namespace responder
} // namespace pldm
