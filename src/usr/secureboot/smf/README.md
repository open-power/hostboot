# SMF Memory Allocation Algorithm

### Introduction
The amount of Secure SMF memory to distribute between the available procs on the system
is a user-configurable petitboot setting. Hostboot reads this setting and distributes
the requested amount of memory as evenly as possible between the available procs on the
system.

**NOTE:** We must operate in power-of-two multiples of 256MB to satisfy hardware limitations. That means that the end result of the amount of secure memory behind each proc needs to be a power-of-two multiple of 256MB.

### The Algorithm
* The function to distribute the memory receives the requested amount (in bytes) as a uint64.
* A check is performed to see if the requested amount is 0 (do not allocate secure memory)
  * SMF is turned off in that case
* A structure of proc and memory associations is built
  * Each member of the struct consists of the proc target, the total available memory behind that proc, the amount of secure memory to be allocated behind that proc (0 initially), and the flag indicating whether the proc can still fit secure memory
  * 8GB is subtracted from the available memory pool of the master proc to make sure hostboot has space to run in
* Start allocating the memory in chunks, starting with 256MB, and doubling the amount (where appropriate) every loop
* In a loop:
  * Check if we've allocated all requested memory (or more)
  * Check if the current chunk is more than we can fit under the proc
    * **TRUE**: Flag the proc as out of memory (it will not be considered anymore)
    * **FALSE**: "Pre-allocate" the current chunk behind the proc
  * If we were able to allocate the current chunk, calculate the remaining amt to allocate
  * If we've allocated everything or ran out of procs to allocate the memory on, break out of the loop
  * Double the chunk to allocate for the next loop
* At the end of the loop two checks are performed:
  * Check if we couldn't allocate any memory (the system is memory-starved) - return a predictive error
  * Check if the actual allocated amount does not equal to the requested amount (there may have been rounding) - return an informational error

### Visual Representation of the Allocation Process

| Loop | Allocated on Proc 0 (MB) | Proc 1  | Proc 2|
| -----|:------------------------:| :------:|:-----:|
| 0    |  0                       | 0       | 0     |
| 1    |  256                     | 256     | 256   |
| 2    |  512                     | 512     | 512   |
| 3    |  1024                    | 1024    | 1024  |
| 4    |  2048                    | 2048    | 2048  |
... repeat until allocated or until there are no more remaining procs with memory
