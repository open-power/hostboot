<?xml version="1.0"?>
<!-- IBM_PROLOG_BEGIN_TAG                                                   -->
<!-- This is an automatically generated prolog.                             -->
<!--                                                                        -->
<!-- $Source: src/usr/targeting/common/xmltohb/bios_metadata_petitboot.xslt $ -->
<!--                                                                        -->
<!-- OpenPOWER HostBoot Project                                             -->
<!--                                                                        -->
<!-- Contributors Listed Below - COPYRIGHT 2015                             -->
<!-- [+] International Business Machines Corp.                              -->
<!--                                                                        -->
<!--                                                                        -->
<!-- Licensed under the Apache License, Version 2.0 (the "License");        -->
<!-- you may not use this file except in compliance with the License.       -->
<!-- You may obtain a copy of the License at                                -->
<!--                                                                        -->
<!--     http://www.apache.org/licenses/LICENSE-2.0                         -->
<!--                                                                        -->
<!-- Unless required by applicable law or agreed to in writing, software    -->
<!-- distributed under the License is distributed on an "AS IS" BASIS,      -->
<!-- WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or        -->
<!-- implied. See the License for the specific language governing           -->
<!-- permissions and limitations under the License.                         -->
<!--                                                                        -->
<!-- IBM_PROLOG_END_TAG                                                     -->

<xsl:stylesheet version="1.0"
  xmlns:xsl="http://www.w3.org/1999/XSL/Transform">

<xsl:output method="xml" version="1.0"
  encoding="UTF-8" indent="yes"/>

<xsl:template match="/">
  <firmware-overrides>
    <xsl:apply-templates select="firmware-overrides/attribute"/>
    <xsl:apply-templates select="firmware-overrides/group"/>
  </firmware-overrides>
</xsl:template>

<xsl:template match="attribute">
  <attribute>
    <xsl:attribute name="id">
      <xsl:value-of select="id"/>
    </xsl:attribute>
    <numeric-id><xsl:value-of select="numeric-id"/></numeric-id>
    <type>
        <size><xsl:value-of select="size"/></size>
        <encoding><xsl:value-of select="encoding"/></encoding>
    </type>
    <default><xsl:value-of select="default"/></default>
    <display-name><xsl:value-of select="display-name"/></display-name>
    <description><xsl:value-of select="description"/></description>
    <target>
      <type><xsl:value-of select="target/type"/></type>
      <node><xsl:value-of select="target/node"/></node>
      <position><xsl:value-of select="target/position"/></position>
      <unit><xsl:value-of select="target/unit"/></unit>
    </target>
    <xsl:apply-templates select="numericOverride"/>
    <xsl:apply-templates select="enumeration"/>
  </attribute>
</xsl:template>

<xsl:template match="numericOverride">
  <range>
    <start><xsl:value-of select="start"/></start>
    <end><xsl:value-of select="end"/></end>
  </range>
</xsl:template>

<xsl:template match="enumeration">
  <enumeration>
    <xsl:apply-templates select="./enumerator"/>
  </enumeration>
</xsl:template>

<xsl:template match="enumerator">
  <enumerator>
    <display-name><xsl:value-of select="display-name"/></display-name>
    <description><xsl:value-of select="description"/></description>
    <value><xsl:value-of select="value"/></value>
  </enumerator>
</xsl:template>

<xsl:template match="group">
  <group>
    <name><xsl:value-of select="name"/></name>
    <xsl:apply-templates select="./attribute"/>
    <xsl:apply-templates select="./group"/>
  </group>
</xsl:template>

</xsl:stylesheet>
