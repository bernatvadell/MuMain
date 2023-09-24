﻿<?xml version="1.0" encoding="utf-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform"
    xmlns:msxsl="urn:schemas-microsoft-com:xslt" exclude-result-prefixes="msxsl"
    xmlns:pd="http://www.munique.net/OpenMU/PacketDefinitions"
>
  <xsl:param name="resultFileName" />
  <xsl:param name="subNamespace" />
  <xsl:output method="text" indent="yes" />
  <xsl:include href="Common.xslt" />

  <xsl:template match="pd:PacketDefinitions">
    <xsl:text>// &lt;copyright file="PacketFunctions.h" company="MUnique"&gt;
// Licensed under the MIT License. See LICENSE file in the project root for full license information.
// &lt;/copyright&gt;

//------------------------------------------------------------------------------
// &lt;auto-generated&gt;
//     This source code was auto-generated by an XSL transformation.
//     Do not change this file. Instead, change the XML data which contains
//     the packet definitions and re-run the transformation (publish/rebuild the
//     managed library project).
// &lt;/auto-generated&gt;
//------------------------------------------------------------------------------

#pragma once

#include "stdafx.h"

#include &lt;coreclr_delegates.h&gt;

/// &lt;summary&gt;
/// Extension methods to start writing messages of this namespace on a &lt;see cref="Connection"/&gt;.
/// &lt;/summary&gt;
class PacketFunctions_</xsl:text><xsl:value-of select="$subNamespace"/><xsl:text>
{
private:
    int32_t _handle;
public:
    void SetHandle(int32_t handle) { _handle = handle; }
</xsl:text>
    <xsl:apply-templates select="pd:Packets/pd:Packet" mode="function_header" />
    <xsl:text>
};</xsl:text>
  </xsl:template>

  <xsl:template match="pd:Packet[not(pd:Fields/pd:Field/pd:Type = 'Structure[]')]" mode="function_header">
    <xsl:value-of select="$newline" />
    <xsl:text>
    /// &lt;summary&gt;
    /// Sends a </xsl:text>
    <xsl:apply-templates select="pd:Name" />
    <xsl:text> to this connection.
    /// &lt;/summary&gt;</xsl:text>
    <xsl:apply-templates select="pd:Fields/pd:Field" mode="paramdoc">
      <xsl:sort select="pd:DefaultValue"/>
    </xsl:apply-templates>
    <xsl:call-template name="WriteRemarks" />
    <xsl:text>    void Send</xsl:text>
    <xsl:apply-templates select="pd:Name" />
    <xsl:text>(</xsl:text>
    <xsl:apply-templates select="pd:Fields/pd:Field" mode="nativeparams">
      <xsl:sort select="pd:DefaultValue"/>
    </xsl:apply-templates>
    <xsl:text>);</xsl:text>
  </xsl:template>

  <xsl:template match="pd:Field" mode="paramdoc">
    <xsl:value-of select="$newline"/>
    <xsl:text>    /// &lt;param name="</xsl:text>
    <xsl:call-template name="LowerCaseName" />
    <xsl:text>"&gt;</xsl:text>
    <xsl:choose>
      <xsl:when test="pd:Description">
        <xsl:value-of select="pd:Description"/>
      </xsl:when>
      <xsl:otherwise>
        <xsl:text>The</xsl:text>
        <xsl:call-template name="splitName">
          <xsl:with-param name="name" select="pd:Name" />
        </xsl:call-template>
        <xsl:text>.</xsl:text>
      </xsl:otherwise>
    </xsl:choose>

    <xsl:text>&lt;/param&gt;</xsl:text>
    <xsl:if test="(pd:Type = 'Binary') or (pd:Type = 'String')">
      <xsl:value-of select="$newline"/>
      <xsl:text>    /// &lt;param name="</xsl:text>
      <xsl:call-template name="LowerCaseName" />
      <xsl:text>ByteLength"&gt;</xsl:text>
      <xsl:text>The length of &lt;paramref name="</xsl:text>
      <xsl:call-template name="LowerCaseName" />
      <xsl:text>"/> in bytes.</xsl:text>
    </xsl:if>
  </xsl:template>



  <xsl:template name="WriteRemarks">
    <xsl:if test="pd:SentWhen or pd:CausedReaction">
      <xsl:text>
    /// &lt;remarks&gt;
    /// Is sent </xsl:text>
      <xsl:choose>
        <xsl:when test="pd:Direction = 'ClientToServer'">
          <xsl:text>by the client when: </xsl:text>
        </xsl:when>
        <xsl:otherwise>
          <xsl:text>by the server when: </xsl:text>
        </xsl:otherwise>
      </xsl:choose>
      <xsl:value-of select="pd:SentWhen"/>
      <xsl:text>
    /// Causes reaction </xsl:text>
      <xsl:choose>
        <xsl:when test="pd:Direction = 'ClientToServer'">
          <xsl:text>on server side: </xsl:text>
        </xsl:when>
        <xsl:otherwise>
          <xsl:text>on client side: </xsl:text>
        </xsl:otherwise>
      </xsl:choose>
      <xsl:value-of select="pd:CausedReaction"/>
      <xsl:text>
    /// &lt;/remarks&gt;</xsl:text>
      <xsl:value-of select="$newline" />
    </xsl:if>
  </xsl:template>

  <xsl:template match="text()" mode="paramdoc"></xsl:template>
  <xsl:template match="text()" mode="function_header"></xsl:template>
  <xsl:template match="text()"></xsl:template>

</xsl:stylesheet>
