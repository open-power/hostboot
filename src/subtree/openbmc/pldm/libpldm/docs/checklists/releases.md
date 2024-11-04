# Checklist for making releases of `libpldm`

- [ ] Update the version in `meson.build`
- [ ] Add the tag value header in `CHANGELOG.md`

- [ ] Generate the ABI dump for the release

  - This must be done from a shell session inside the OpenBMC CI Docker
    container for consistency

- [ ] Rename the directory for unreleased evolutions
- [ ] Commit the changes above with the subject `libpldm: Release <version>`
- [ ] Push the release commit for review in Gerrit
- [ ] Submit the release commit once approved
- [ ] Create the release tag
- [ ] Push the release tag
