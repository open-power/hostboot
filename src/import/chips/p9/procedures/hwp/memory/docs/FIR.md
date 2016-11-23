
# How the memory subsystem handles FIR bits

In order to make handling of FIR bits a bit more straight forward, we have
created a small data structure mss::fir::reg. Given the FIR register which
reports FIR errors, a fir::reg will encapsulate the 2 action registers and
the mask register as well as the reporting register.

FIR actions, and when FIR are unmasked are defined by the team as a whole,
and are documented outside of the ekb.

## FIR actions

FIR actions are configured in 3 parallel registers: action0, action1 and
mask. Bit patterns assigned across these three registers define a response
the system is to take when a FIR bit is asserted. Because they span three
parallel registers, the actions are defined as triples:

```
   Action 0  Action 1    Mask
    +---+     +---+     +---+
    | 0 |     | 0 |     | 0 |
    +---+     +---+     +---+
```

So, for any bit postion representing a FIR, that corresponding bit in the
three registers defines the system response. Consider "bit 12," to define
a response we must set the three bits in position 12 in the three
registers:

```
              bit 0,          ...,    bit 12

   Action 0  Action 1    Mask       Action 0  Action 1    Mask
    +---+     +---+     +---+        +---+     +---+     +---+
    | 0 |     | 0 |     | 1 |        | 0 |     | 0 |     | 0 |
    +---+     +---+     +---+ ...,   +---+     +---+     +---+ ...,
```

This represents that the FIR "bit 0" is masked (1 in the mask register bit
position 0) and the FIR "bit 12" should respond with a check-stop (0 in
the action 0 and action 1 registers in bit position 12, and a 0 to represent
the FIR is unmasked.

## Action Triples

The actions are defined as:

```
   Action 0  Action 1    Mask
    +---+     +---+     +---+
    | 0 |     | 0 |     | 0 |    System Checkstop
    +---+     +---+     +---+

    +---+     +---+     +---+
    | 0 |     | 1 |     | 0 |    Recoverable Error
    +---+     +---+     +---+

    +---+     +---+     +---+
    | 1 |     | 0 |     | 0 |    Attention
    +---+     +---+     +---+

    +---+     +---+     +---+
    | 1 |     | 1 |     | 0 |    Local Checkstop
    +---+     +---+     +---+

    +---+     +---+     +---+
    | X |     | X |     | 1 |    Masked
    +---+     +---+     +---+
```

## The fir::reg class

Given this information, the fir::reg class provides a read-modify-write
interface for specific actions, keyed off of the FIR register. For example
fir::reg::checkstop() configures the appropriate action0, action1 and mask bits.
fir::reg::write() ensures all of the configuration is written to the proper
register. Refer to the fir.H documentation for further explanation on using
the fir::reg class.
