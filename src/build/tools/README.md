# Tools

## eecache_editor.pl
This tool is used to manipulate an ECC-less EECACHE file.
See "eecache_editor.pl --help" for usage examples.

If you have an EECACHE file with ECC, you can use some of HB tools to remove ECC:
- <hb_repo>/standalone/ffs/ecc/ecc
  - This file is placed in your HB repo when you run "hb prime" and your dev environment is using a
    non-FSP config file.
- src/build/simics/ecc.py

e.g.:
<hb_repo>/standalone/ffs/ecc/ecc --remove EECACHE.bin.ecc --output EECACHE.bin --p8

see "<hb_repo>/standalone/ffs/ecc/ecc --help" for more info.
