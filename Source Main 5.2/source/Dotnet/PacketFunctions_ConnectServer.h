﻿// <copyright file="PacketFunctions.h" company="MUnique">
// Licensed under the MIT License. See LICENSE file in the project root for full license information.
// </copyright>

//------------------------------------------------------------------------------
// <auto-generated>
//     This source code was auto-generated by an XSL transformation.
//     Do not change this file. Instead, change the XML data which contains
//     the packet definitions and re-run the transformation (publish/rebuild the
//     managed library project).
// </auto-generated>
//------------------------------------------------------------------------------

#pragma once

#include "stdafx.h"

#include <coreclr_delegates.h>

/// <summary>
/// Extension methods to start writing messages of this namespace on a <see cref="Connection"/>.
/// </summary>
class PacketFunctions_ConnectServer
{
private:
    int32_t _handle;
public:
    void SetHandle(int32_t handle) { _handle = handle; }


    /// <summary>
    /// Sends a ConnectionInfoRequest075 to this connection.
    /// </summary>
    /// <param name="serverId">The server id.</param>
    /// <remarks>
    /// Is sent by the client when: This packet is sent by the client after the user clicked on an entry of the server list.
    /// Causes reaction on server side: The server will send a ConnectionInfo back to the client.
    /// </remarks>
    void SendConnectionInfoRequest075(BYTE serverId);

    /// <summary>
    /// Sends a ConnectionInfoRequest to this connection.
    /// </summary>
    /// <param name="serverId">The server id.</param>
    /// <remarks>
    /// Is sent by the client when: This packet is sent by the client after the user clicked on an entry of the server list.
    /// Causes reaction on server side: The server will send a ConnectionInfo back to the client.
    /// </remarks>
    void SendConnectionInfoRequest(uint16_t serverId);

    /// <summary>
    /// Sends a ConnectionInfo to this connection.
    /// </summary>
    /// <param name="ipAddress">The ip address.</param>
    /// <param name="ipAddressByteLength">The length of <paramref name="ipAddress"/> in bytes.
    /// <param name="port">The port.</param>
    /// <remarks>
    /// Is sent by the server when: This packet is sent by the server after the client requested the connection information of a server. This happens after the user clicked on a server.
    /// Causes reaction on client side: The client will try to connect to the server with the specified information.
    /// </remarks>
    void SendConnectionInfo(char* ipAddress, uint32_t ipAddressByteLength, uint16_t port);

    /// <summary>
    /// Sends a ServerListRequest to this connection.
    /// </summary>
    /// <remarks>
    /// Is sent by the client when: This packet is sent by the client after it connected and received the 'Hello' message.
    /// Causes reaction on server side: The server will send a ServerListResponse back to the client.
    /// </remarks>
    void SendServerListRequest();

    /// <summary>
    /// Sends a ServerListRequestOld to this connection.
    /// </summary>
    /// <remarks>
    /// Is sent by the client when: This packet is sent by the client (below season 1) after it connected and received the 'Hello' message.
    /// Causes reaction on server side: The server will send a ServerListResponseOld back to the client.
    /// </remarks>
    void SendServerListRequestOld();

    /// <summary>
    /// Sends a Hello to this connection.
    /// </summary>
    /// <remarks>
    /// Is sent by the server when: This packet is sent by the server after the client connected to the server.
    /// Causes reaction on client side: A game client will request the server list. The launcher would request the patch state.
    /// </remarks>
    void SendHello();

    /// <summary>
    /// Sends a PatchCheckRequest to this connection.
    /// </summary>
    /// <param name="majorVersion">The major version.</param>
    /// <param name="minorVersion">The minor version.</param>
    /// <param name="patchVersion">The patch version.</param>
    /// <remarks>
    /// Is sent by the client when: This packet is sent by the client (launcher) to check if the patch version is high enough to be able to connect to the server.
    /// Causes reaction on server side: The connect server will check the version and sends a 'PatchVersionOkay' or a 'ClientNeedsPatch' message.
    /// </remarks>
    void SendPatchCheckRequest(BYTE majorVersion, BYTE minorVersion, BYTE patchVersion);

    /// <summary>
    /// Sends a PatchVersionOkay to this connection.
    /// </summary>
    /// <remarks>
    /// Is sent by the server when: This packet is sent by the server after the client (launcher) requested the to check the patch version and it was high enough.
    /// Causes reaction on client side: The launcher will activate its start button.
    /// </remarks>
    void SendPatchVersionOkay();

    /// <summary>
    /// Sends a ClientNeedsPatch to this connection.
    /// </summary>
    /// <param name="patchVersion">The patch version.</param>
    /// <param name="patchAddress">The patch address, usually to a ftp server. The address is usually "encrypted" with the 3-byte XOR key (FC CF AB).</param>
    /// <param name="patchAddressByteLength">The length of <paramref name="patchAddress"/> in bytes.
    /// <remarks>
    /// Is sent by the server when: This packet is sent by the server after the client (launcher) requested to check the patch version and it requires an update.
    /// Causes reaction on client side: The launcher will download the required patches and then activate the start button.
    /// </remarks>
    void SendClientNeedsPatch(BYTE patchVersion, char* patchAddress, uint32_t patchAddressByteLength);
};