## Background

For P10, the following should be kept in mind for FCO
- Each P10 processor has 8 EQ units.
- Each EQ unit has 2 Fused Cores (FC) units for a total of 16 per chip.
- Each FC has 2 exposed CORE units for a total of 32 per chip.
- Each pair of CORE targets on a FC are even and odd numbered adjacent pairs
- A CORE can also be put into "Enhanced Cached Option" mode (ECO) where the CORE will not actively run instructions, but the backing cache can be used by other COREs. For the purposes of the FCO algorithm, ECO cores should never be passed into the algorithm as FCO candidates because FCO only considers active execution cores as mentioned in the rules below.

## The Rules of FCO

1. The FCO number is relative to Fused Core mode. In Fused Core mode FCO number refers to FC, in Small Core mode FCO number refers to CORE
    1a. The FCO number applies to the entire system, e.g. FCO=1 in Fused Core mode means 1 FC total, in Small Core mode that means 1 CORE total.
    1b. FCO=0 is a special value that indicates no Field Core Overrides.
2. COREs should be spread across all PROCs as evenly as possible.
    2a. Must always keep the CORE/FC that the SBE booted Hostboot with. Implicitly, this also means FCO cannot deconfigure the boot PROC
    2b. FCO only considers functional cores
    2c. FCO does not include ECO cores, only active execution cores.
    2d. Cores must be deconfigured in the order that the chip team provides.
3. In Fused Core mode, algorithm cannot break apart an FC.
4. The FCO number is the maximum number of CORE/FCs to use in the system. So, if the number of available units is less than that then that's acceptable but should get as close as possible.
5. FCO should never deconfigure a PROC as a result of deconfiguring all its FC/CORE units. PROCs without FC/CORE units can still be used for other purposes.

The Deconfig Priorities for a P10 Chip:

The lowest numerical value indicates the highest deconfigure priority. Below is a table with those priorities listed out. CHIP_UNIT is the value Hostboot uses to get the proc relative position of a child unit.

| Core CHIP_UNIT | Priority |
|----------------|----------|
| 0              | 31       |
| 1              | 32       |
| 2              | 5        |
| 3              | 6        |
| 4              | 13       |
| 5              | 14       |
| 6              | 21       |
| 7              | 22       |
| 8              | 9        |
| 9              | 10       |
| 10             | 19       |
| 11             | 20       |
| 12             | 25       |
| 13             | 26       |
| 14             | 1        |
| 15             | 2        |
| 16             | 27       |
| 17             | 28       |
| 18             | 3        |
| 19             | 4        |
| 20             | 11       |
| 21             | 12       |
| 22             | 17       |
| 23             | 18       |
| 24             | 15       |
| 25             | 16       |
| 26             | 23       |
| 27             | 24       |
| 28             | 29       |
| 29             | 30       |
| 30             | 7        |
| 31             | 8        |

## Algorithm Requirements and Considerations

Since the Chip Team has provided deconfig priorities on a CORE level granularity, the FCO algorithm operates at a CORE level granularity. That means in Fused Core systems the given FCO value will be doubled so that the algorithm can treat Fused Core systems and Small Core systems the same with respect to some calculations.

To apply FCO to a system the process can be thought of as a reduction procedure. The system exists in its current state, whatever that may be. The FCO value is then a requirement that the system reduce its functional execution cores down to, or below, the FCO value. The algorithm is also designed to be greedy, which is to say that if the system can make its total remaining functional execution cores equal to the FCO value it will always attempt to do so and each functional proc in the system will always try to keep the maximum number of cores.

There are two groups a system can fall under regarding FCO:

1. Total System Functional Cores > FCO value
2. Total System Functional Cores <= FCO value

The second group is dealt with trivially due to Rule 4. The FCO is the max and the system has equal to or less than that max. No reduction needs to take place.

The first group is the main concern of the algorithm. In an ideal world the algorithm would do a simple calculation of NumberOfCoresPerProc = FcoValue / NumberOfProcs. So, a system with 4 procs and a given FCO of 32 would result in 8 cores per proc left functional to meet the requirement. The result of this calculation, NumberOfCoresPerProc, is considered to be the ideal number of cores per proc in a perfect situation because it satisfies Rule 2. There are some additional considerations, however:

- The FCO value may not be perfectly divisible by the number of procs in the system.
- The system may be Fused Core. In which case even if the FCO value is perfectly divisible by the number of procs the result could be an odd number. The algorithm must adhere to Rule 3 while still attempting to maximize the number of remaining 
- The functional procs may not have the same number of CORE/FCs configured as all other procs. e.g. P0=16 cores, P1=4 cores, P3=14 cores, P4=6 cores
- The boot proc could be either PROC0 or PROC1
- The boot core must not be deconfigured regardless of its priority given by the chip team and the boot core could be any core.

### Examples

Let's work through these considerations by looking at a series of examples. For simplicity let's only consider FCO values that have been scaled to the number of cores per chip. So, FCO=3 means 3 cores remaining. When an interesting fused core mode situation arises it'll be called out specifically.

#### Example 1

> The FCO value may not be perfectly divisible by the number of procs in the system.

> Take FCO=27, NumberOfProcs=4, and for simplicity assume all PROCs have all 32 cores.
{.is-info}


IdealCoresPerProc = FCO / NumberOfProcs; IdealCoresPerProc = 6 given these values.

Remember, the ideal value represents a perfect situation that would allow us to follow Rule 2 without exception. The problem here is if we follow Rule 2 we'll end up with 24 cores across the system and we were asked for 27 which we definitely had. This is why the algorithm is greedy.

A new piece to the calculation is then derived as:

> extraRemaining = FCO % NumberOfProcs
{.is-info}


In this example, we left 3 extra cores on the table when we didn't have to if we only accounted for them. So, again, trying to follow Rule 2 we'll split up those extras among the procs as evenly as possible.

Note that for this example, it's not a valid case for fused core mode because the algorithm always operates on a remaining cores-per-proc basis. That means that for any given FCO value in a fused core system the value is scaled to cores-per-proc remaining (instead of FCs-per-proc remaining) which will always be an even number due to doubling. However, this does not mean that a similar situation can't happen for even FCO values because it is possible that some procs in the system may have no functional execution cores or may not have all procs present. The fused core situation is more easily explained by considering the next example.

#### Example 2

> The system may be Fused Core. In which case even if the FCO value is perfectly divisible by the number of procs the result could be an odd number. The algorithm must adhere to Rule 3 while still attempting to maximize the number of remaining

> Take FCO=28, NumberOfProcs=4, again assume all cores are functional and non-ECO.
{.is-info}


IdealCoresPerProc = 28 / 4; IdealCoresPerProc = 7. ExtraRemaining = 0.

For Small Core, this is trivial. However, Rule 3 requires us to not break up the fused cores. This is problematic. We can't round up to 8 because that would leave 32 cores remaining, exceeding the FCO value and breaking Rule 4. So maybe we could round down to 6 to follow Rule 4 but that leaves 24 cores with 4 cores (2 FCs) left on the table. There are no extras left over from the calculation to use to fix this problem either. However, there would be extras left over after trying to follow Rule 2 in the round down situation, those 4 cores. 

If we run with 7 as the ideal value then each proc has a chance to be greedy and "borrow" a core to get to 8. We have to be careful though because all procs can't borrow a core otherwise we'll keep too many around. Some will have to lose a core. This is where the concept of debt comes in:

**A proc can borrow a core, incurring debt, and another proc can pay down that debt so that we can match the FCO value.**

In this example we want 2 PROCs with 8 remaining cores and 2 PROCs with 6 remaining cores to meet the FCO. Here's how that works:
- P0 borrows a core to go from 7 cores to 8, incurring a debt of 1 core.
- P1 sees that there is a debt and it pays that debt by going from 7 cores to 6 cores remaining.
- P2 sees there is no debt outstanding and incurs a debt to go from 7 to 8 cores.
- P3 then pays that debt and has 6 cores remaining.

There is some additional logic and considerations to prevent borrowing when it shouldn't be allowed but that's beyond the scope of this example.

#### Example 3

> The functional procs may not have the same number of CORE/FCs configured as all other procs. e.g. P0=16 cores, P1=4 cores, P3=14 cores, P4=6 cores

> Take FCO=32, NumberOfProcs=4, number of cores per proc as above.
{.is-info}


IdealCoresPerProc = 32 / 4 -> 8. ExtraRemaining = 0.
There are no extras and in the FC case no need to incur debt to follow Rule 3.

Already, there is a problem if this value is applied to the procs in the system. P1 and P4 don't have enough cores to meet the ideal value of 8. However, P0 and P3 could leave extra configured to meet the FCO value. So there needs to be a way to do that. If we "assign" P1 and P4 to keep all the cores they have and then consider how to spread evenly the leftovers between P0 and P3 we can match the FCO value.

This works by raising the ideal value to be as large as possible and then getting rid of the excess cores as normal. This is accomplished by sorting the procs from least available cores to most and then assigning cores to those procs which don't meet the ideal value and recalculating the ideal value for the remaining procs until we're through the list.

For each Proc in List
     If Proc's available cores <= ideal value
          recalculated FCO value = current FCO value - proc's available cores
          recalculated ideal = recalculated FCO / number of procs left in the list
          recalculated extra = recalculated FCO % number of procs left in the list

To start, ideal = 8, extra = 0

P1, 4 cores
     recalc FCO = 32 - 4 -> 28
     recalc ideal = 28 / 3 -> 9
     recalc extra = 28 % 3 -> 1
P4, 6 cores
     recalc FCO = 28 - 6 -> 22
     recalc ideal = 22 / 2 -> 11
     recalc extra = 22 % 2 -> 0
P3, 14 cores
     P3 has more than ideal cores. No recalculating.
P0, 16 cores
     P0 has more than ideal cores. No recalculating.

**Result: ideal = 11, extra = 0**

With this new ideal value we can proceed with core reduction. You'll notice that in the Fused Core case ideal=11 is a problem. As explained in Example 2, the concept of debt will be applied so that one proc will borrow from another to satisfy Rule 3. Look at Example 6 to see how debt can be applied to resolve this situation.

#### Example 4

> The boot proc could be either PROC0 or PROC1

The algorithm cannot assume that the boot proc is always P0. Instead of creating anymore complex logic than what already is required by the above this can be handled trivially by searching the list for the boot proc and swapping it with the first entry in the list. This guarantees that for low FCO values the boot proc will always be left configured. However, if you reconsider Example 3 then the debt logic must be smart enough not to borrow from procs that have less than the ideal value.

#### Example 5

> The boot core must not be deconfigured regardless of its priority given by the chip team and the boot core could be any core.

This is another trivial case to solve for. Since the boot proc is always first in the list and each core is deconfigured by lowest numerical priority value first. We can assign the boot core the highest numerical value as its priority thus guaranteeing it never gets deconfigured.

#### Example 6

This example resolves the situation from Example 3 and assumes the reader has read all other examples up to this point. This is a fused core mode example with the FCO value scaled in terms of cores as usual. By the end of this example you'll have seen how the algorithm works from start to finish for the given scenario.

> Take FCO=32; NumberOfProcs=4;  P0=16 cores, P1=4 cores, P3=14 cores, P4=6 cores; P0 is the boot proc
{.is-info}

Recall from Example 3 that we needed to raise the Ideal value because 8 was not sufficient in this case. This was done by performing the following logic:

Original calculation: IdealCoresPerProc = 32 / 4 -> 8. ExtraRemaining = 0.

> For each Proc in List
>      If Proc's available cores <= ideal value
>           recalculated FCO value = current FCO value - proc's available cores
>           recalculated ideal = recalculated FCO / number of procs left in the list
>           recalculated extra = recalculated FCO % number of procs left in the list
{.is-info}

Resulting output: IdealCoresPerProc = 11, ExtraRemaining = 0

Since FCs cannot be broken, 11 is not going to work without using the concept of debt to help. The current state of the proc list after raising the ideal value is:

1. P1: 4 cores
2. P4: 6 cores
3. P3: 14 cores
4. P0: 16 cores

The next step before moving on per Example 5 would be to swap P1 and P0 since P0 is the boot proc.

1. P0: 16 cores
2. P4: 6 cores
3. P3: 14 cores
4. P1: 4 cores

Next, we'd want to assign the max cores for P0. Since 11 is odd, this is fused core mode, and P0 has more than the ideal value P0 is going to be greedy and incur a debt of 1 core so that it can keep 12.

**debtFromPriorProc = 1**

After P0 is processed, then P4 is next. It has less than the ideal value of 11 which means that it should keep all its cores. It also can't afford to pay P0's debt, so it won't. It is assigned to keep all 6 cores that it has.

**debtFromPriorProc = 1**

Next up is P3 and it has 14 cores. When deciding how many it can keep we see that it has more than the ideal value of 11 so it *could* borrow a core to get to 12 and be greedy but there is already unpaid debt from P0. P3 graciously pays for P0 and takes 10 as the max cores for itself.

Finally, P1 has only 4 cores and so it's going to keep all those. The end result is:

1. P0: 12
2. P4: 6
3. P3: 10
4. P1: 4

Total Remaining Cores = 32 == FCO value

## The Algorithm

Finally, with all those rules in mind and considerations accounted for the final algorithm is as follows:
- Scale the FCO value to be in terms of COREs, not FCs. If applicable.
- Sort the list of procs by least available cores to most
- Calculate the the ideal number of remaining cores per proc, keep track of any extras to assign to greedy procs.
- Swap the boot proc with the first proc in the list to guarantee it never gets deconfigured.
- For each proc in the list:
    - Sort the available cores by priority
    - Determine the max number of cores this proc gets to keep
    - Reduce the available cores to less than or equal to that max number.

As a result, for any given FCO value, number of available Procs, and number of available cores the algorithm will output a value equal to or less than the FCO value. Additionally, if the value is less than the FCO value then it will be equal to the original number of available cores in the system.
