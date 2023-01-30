#pragma once

#include <config.h>

#include <common/utils.hpp>

#include <fstream>
#include <iomanip>
#include <iostream>
#include <vector>
namespace pldm
{
namespace flightrecorder
{

using ReqOrResponse = bool;
using FlightRecorderData = std::vector<uint8_t>;
using FlightRecorderTimeStamp = std::string;
using FlightRecorderRecord =
    std::tuple<FlightRecorderTimeStamp, ReqOrResponse, FlightRecorderData>;
using FlightRecorderCassette = std::vector<FlightRecorderRecord>;
static constexpr auto flightRecorderDumpPath = "/tmp/pldm_flight_recorder";

/** @class FlightRecorder
 *
 *  The class for implementing the PLDM flight recorder logic. This class
 *  handles the insertion of the data into the recorder and also provides
 *  API's to dump the flight recorder into a file.
 */

class FlightRecorder
{
  private:
    FlightRecorder() : index(0)
    {
        flightRecorderPolicy = FLIGHT_RECORDER_MAX_ENTRIES ? true : false;
        if (flightRecorderPolicy)
        {
            tapeRecorder = FlightRecorderCassette(FLIGHT_RECORDER_MAX_ENTRIES);
        }
    }

  protected:
    int index;
    FlightRecorderCassette tapeRecorder;
    bool flightRecorderPolicy;

  public:
    FlightRecorder(const FlightRecorder&) = delete;
    FlightRecorder(FlightRecorder&&) = delete;
    FlightRecorder& operator=(const FlightRecorder&) = delete;
    FlightRecorder& operator=(FlightRecorder&&) = delete;
    ~FlightRecorder() = default;

    static FlightRecorder& GetInstance()
    {
        static FlightRecorder flightRecorder;
        return flightRecorder;
    }

    /** @brief Add records to the flightRecorder
     *
     *  @param[in] buffer  - The request/respose byte buffer
     *  @param[in] isRequest - bool that captures if it is a request message or
     *                         a response message
     *
     *  @return void
     */
    void saveRecord(const FlightRecorderData& buffer, ReqOrResponse isRequest)
    {
        // if the flight recorder policy is enabled, then only insert the
        // messages into the flight recorder, if not this function will be just
        // a no-op
        if (flightRecorderPolicy)
        {
            int currentIndex = index++;
            tapeRecorder[currentIndex] = std::make_tuple(
                pldm::utils::getCurrentSystemTime(), isRequest, buffer);
            index =
                (currentIndex == FLIGHT_RECORDER_MAX_ENTRIES - 1) ? 0 : index;
        }
    }

    /** @brief play flight recorder
     *
     *  @return void
     */

    void playRecorder()
    {
        if (flightRecorderPolicy)
        {
            std::ofstream recorderOutputFile(flightRecorderDumpPath);
            std::cout << "Dumping the flight recorder into : "
                      << flightRecorderDumpPath << "\n";

            for (const auto& message : tapeRecorder)
            {
                recorderOutputFile << std::get<FlightRecorderTimeStamp>(message)
                                   << " : ";
                if (std::get<ReqOrResponse>(message))
                {
                    recorderOutputFile << "Tx : \n";
                }
                else
                {
                    recorderOutputFile << "Rx : \n";
                }
                for (const auto& word : std::get<FlightRecorderData>(message))
                {
                    recorderOutputFile << std::setfill('0') << std::setw(2)
                                       << std::hex << (unsigned)word << " ";
                }
                recorderOutputFile << std::endl;
            }
            recorderOutputFile.close();
        }
        else
        {
            std::cerr << "Fight recorder policy is disabled\n";
        }
    }
};

} // namespace flightrecorder
} // namespace pldm
