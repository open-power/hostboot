/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/memory/lab/sdk/example/C/mss_lab_sfwrite.C $ */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* EKB Project                                                            */
/*                                                                        */
/* COPYRIGHT 2016                                                         */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */

///
/// @file mss_lab_sfwrite.C
/// @brief  Memdiags super-fast write
///
// *HWP HWP Owner: Marc Gollub <gollub@us.ibm.com>
// *HWP FW Owner: Brian Silver <bsiler@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: Memory

#include <mss_lab_tools.H>

#include <lib/utils/poll.H>
#include <lib/mcbist/address.H>
#include <lib/mcbist/memdiags.H>
#include <lib/mcbist/mcbist.H>

///
/// @brief display procedure usage
///
void help()
{
    // Note: Use ecmdOutput for usage information so it is always printed to the console.
    //       Otherwise, always use mss::lab::log or mss::lab::logf
    ecmdOutput("mss_lab_sfwrite.exe - Example of building a lab tool to do super-fast write\n");
    ecmdOutput("mss_lab_sfwrite.exe [options] [cronus options]\n");
    ecmdOutput("\n");
    ecmdOutput("  Options:\n");
    ecmdOutput("   --help/-h          Shows this help message\n");
    ecmdOutput("   --cronus-target    Provide the Cronus target to begin operations on.\n");
    ecmdOutput("\n");
    ecmdOutput("  Cronus Options:\n");
    ecmdOutput("   These are cronus specific command line instructions that are passed\n");
    ecmdOutput("    into cronus\n");
    return;
}

///
/// @brief main test function
///
int main(int i_argc, char* i_argv[])
{
    // vars, handles, etc
    fapi2::ReturnCode rc;
    char cronus_target[32] = "p9n.mcbist:k0:n0:s0:p00:c0";
    char* l_target;

    // Memory Lab Tools initialization
    mss::lab::tool_init tool_init(rc, i_argc, i_argv);
    mss::lab::is_ok(rc, "Failed to initialize lab tool");

    // command line handling
    if (ecmdParseOption(&i_argc, &i_argv, "-h"))
    {
        help();
        return 0;
    }

    if ((l_target = ecmdParseOptionWithArgs(&i_argc, &i_argv, "--cronus-target=")) != nullptr)
    {
        strcpy(cronus_target, l_target);
    }

    // get ecmd target
    auto ecmd_target = std::make_shared<ecmdChipTarget>();
    rc = mss::lab::get_ecmd_target(cronus_target, ecmd_target);
    mss::lab::is_ok(rc, "Failed to get ecmd target");

    // get fapi2 target
    fapi2::Target<fapi2::TARGET_TYPE_MCBIST> fapi2_mcbist_target;
    rc = mss::lab::get_fapi2_target(ecmd_target, fapi2_mcbist_target);
    mss::lab::is_ok(rc, "Failed to get mcbist from ecmd target");

    // retrieve the Cronus string representing the fapi2 target
    mss::logf(mss::DEBUG, "MCBIST C_str: %s", mss::c_str(fapi2_mcbist_target));

    rc = memdiags::sf_init(fapi2_mcbist_target, mss::mcbist::PATTERN_5);
    mss::lab::is_ok(rc, "memdiags::sf_init failed");

    // Just for giggles, poll here looking for the FIR bit ...
    {
        // Poll for the fir bit. We expect this to be set ...
        fapi2::buffer<uint64_t> l_status;

        // A small vector of addresses to poll during the polling loop
        static const std::vector<mss::poll_probe<fapi2::TARGET_TYPE_MCBIST>> l_probes =
        {
            {fapi2_mcbist_target, "mcbist current address", MCBIST_MCBMCATQ},
        };

        mss::poll_parameters l_poll_parameters;
        bool l_poll_results = mss::poll(fapi2_mcbist_target, MCBIST_MCBISTFIRQ, l_poll_parameters,
                                        [&l_status](const size_t poll_remaining, const fapi2::buffer<uint64_t>& stat_reg) -> bool
        {
            FAPI_DBG("mcbist firq 0x%llx, remaining: %d", stat_reg, poll_remaining);
            l_status = stat_reg;
            return l_status.getBit<MCBIST_MCBISTFIRQ_MCBIST_PROGRAM_COMPLETE>() == true;
        },
        l_probes);

        mss::lab::is_ok(l_poll_results == true, "memdiags::sf_write timedout");
    }

    mss::log(mss::DEBUG, "Finished");
}
