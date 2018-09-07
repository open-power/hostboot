<!-- IBM_PROLOG_BEGIN_TAG                                                   -->
<!-- This is an automatically generated prolog.                             -->
<!--                                                                        -->
<!-- $Source: src/build/tools/sort_targeting.xsl $                          -->
<!--                                                                        -->
<!-- OpenPOWER HostBoot Project                                             -->
<!--                                                                        -->
<!-- Contributors Listed Below - COPYRIGHT 2018                             -->
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
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
<xsl:output method="xml" indent="yes" omit-xml-declaration="yes"/>
<xsl:strip-space elements="*"/>

<!-- Setup a key that maps preceding comments to the first following sibling.
     That way the output can keep the comments in the same relative position
     after sorting has occurred.
 -->
<xsl:key name  = "k_precedingComment"
         match = "comment()"
         use   = "generate-id(following-sibling::*[1])" />

<!-- For each element in the file sort it recursively based on its child
     <id> tag. If an element doesn't have a child <id> tag then its order
     relative to its parent won't change.
 -->
<xsl:template match="*">
    <!-- Add the preceding comments back atop the current matched element -->
    <xsl:copy-of select="key('k_precedingComment', generate-id())" />
    <xsl:copy>
        <xsl:apply-templates select="@*"/>
        <xsl:apply-templates select="node()">
            <xsl:sort select="id"/>
        </xsl:apply-templates>
    </xsl:copy>
</xsl:template>

</xsl:stylesheet>
