# Data inputs for POWER Chip error analysis

## 1) Terms

### 1.1) Isolator

This generic library from [openbmc/openpower-libhei][] is used to isolate all
active attentions on a chip. The isolator is agnostic to any chip specific
information. Instead, it parses that information from the Chip Data Binary
files, which contain all needed hardware register addresses and the attention
hierarchy. After isolation completes, the isolator will return a list of
signatures that represent all active attentions on a chip.

[openbmc/openpower-libhei]: https://github.com/openbmc/openpower-libhei

### 1.2) Analyzer

This is a generic term for a user application that will gather all required Chip
Data Binary files, initialize and initiate the isolator on all functional chips,
and generate output logs based on the signatures provided by the isolator.

There will be many analyzer applications and the complete function will be
dependent on the application:

 * The eBMC analyzer in [openbmc/openpower-hw-diags][] will handle system
   checkstop and TI attentions. Any RAS actions will be defined by the RAS Data
   Binary files.

 * Other applications could include: Hostboot PRD, FSP PRD, cronus fircheck
   tool, HWPs, etc.

[openbmc/openpower-hw-diags]: https://github.com/openbmc/openpower-hw-diags

### 1.3) Signature

Each active attention found by the isolator will be returned to the analyzer in
the form of a 32-bit number called a signature. The value of each signature
within a specific chip model and EC level will be unique.

## 2) Chip Data Files

These files describe how attentions propagate within a chip. They also include
all register addresses needed for isolation and debug.

### 2.1) Chip Data XML

These are machine readable files created by the hardware and firmware teams.
They are consumed by Hostboot and used to build the Chip Data Binary files
during Hostboot builds.

Details: <https://github.com/open-power/hostboot/tree/master/src/usr/diag/prdf/data/chip_data/chip_data_xml.md>.

### 2.2) Chip Data Binary

These are generated during Hostboot builds with input from the Chip Data XML
and stored in the PNOR. The analyzer will pull these files from the PNOR and
feed them into the isolator. Note that each file is scoped to a specific chip
model and EC. All signatures within a file will be unique.

Details: <https://github.com/openbmc/openpower-libhei/blob/master/src/chip_data/CHIP_DATA.md>.

## 3) RAS Data Files

These define the RAS actions (i.e. callouts, garding, thresholding, etc.)
required for each signature. The actions are dependent on the analyzer
application. For example, the eBMC analyzer does not need any thresholding
information since each attention handled by eBMC is a terminating event.

### 3.1) RAS Data XML

These are machine readable files created by the hardware and firmware teams.
They are consumed by Hostboot and used to build the RAS Data Binary files during
Hostboot builds. Much like the Chip Data XML and Binary, the scope of the RAS
Data XML is specific to a chip model and EC.

Details: <https://github.com/open-power/hostboot/tree/master/src/usr/diag/prdf/TBD>.

### 3.2) RAS Data Binary

Unlike the previous data files, the scope of the RAS Data Binary files is
expanded to the scope of an entire system. This is accomplished by combining the
RAS Data XML, Device Tree, and MRW during a Hostboot build. These files are
stored in the PNOR and parsed by the analyzer application. As stated before,
the format of the RAS Data files is dependent on the analyzer application.
However, all of the files have common elements:

 * All hardware targets will be referenced using fully qualified Device Tree
   paths, Hostboot entity paths, or equivalent. For example, sys0/node0/proc0.

 * Each chip will contain a map of signatures to a list of required RAS actions.

 * If a piece of hardware needs to be replaced or garded as a required RAS
   action, the fully qualified path of that target will be stored in the binary.
   Then, the analyzer will use that path to query the Device Tree, Hostboot
   targeting model, etc. for the FRU location and gard information.

#### 3.2.1) RAS Data Binary for eBMC

These are fairly simple since any attention handled by the BMC will be a
terminating event. Therefore, only hardware callout and gard actions are needed.

Details: <https://github.com/openbmc/openpower-hw-diags/tree/master/src/TBD>.

#### 3.2.2) RAS Data Binary for Hostboot

TBD

