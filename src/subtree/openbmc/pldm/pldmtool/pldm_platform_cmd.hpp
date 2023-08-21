#pragma once

#include <CLI/CLI.hpp>

namespace pldmtool
{

namespace platform
{

void registerCommand(CLI::App& app);

/*@brief method to parse the command line option for
   get PDR command.
*/
void parseGetPDROption();

void getPDRs();

} // namespace platform

} // namespace pldmtool
