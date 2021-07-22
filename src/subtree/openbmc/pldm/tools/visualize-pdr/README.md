# Overview

The `pldmtool` for `GetPDR` command lacks to display all PDRs at once. It fetches only
one PDR at a time. With a lot of sensors/effecters & with a lot of Host FRU pdrs
coming in due to concurrent maintenance of the system,where the fru's are added/
removed at runtime, it's really necessary to have a full system view.

`pldm_visualise_pdrs.py` is a python script that can be used to fetch the PDR's
from the BMC and can parse them to display a full view of available PDR's on system
at any given point in time.

# Requirements
- Python 3.6+
- graphviz
    - Graphviz is open source graph visualization software. Graph visualization is
      a way of representing structural information as diagrams of abstract graphs
      and networks.
    - There are standard package availabe for graphviz for both rpm based as well
      as the debian based sytems, it can be installed using :

```bash
   RPM Distro : sudo dnf install graphviz
   Debian Distro : sudo apt install graphviz
   Mac Distro : brew install graphviz
```
- The `requirements.txt` file should list all Python libraries that the tool depend
on, and that can be installed using:

```bash
    sudo pip3 install -r requirements.txt
              (or)
    pip3 install -r requirements.txt --user
```
# Usage

```ascii
usage: pldm_visualise_pdrs.py [-h] --bmc BMC --user USER --password PASSWORD [--port PORT]

optional arguments:
  -h, --help           show this help message and exit
  --bmc BMC            BMC IPAddress/BMC Hostname
  --user USER          BMC username
  --password PASSWORD  BMC Password
  --port PORT          BMC SSH port

```
