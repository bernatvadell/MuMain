﻿// <copyright file="PacketBindings.h" company="MUnique">
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
#include "DotNetRuntime.h"
#include "Connection.h"
#include <coreclr_delegates.h>


typedef void(CORECLR_DELEGATE_CALLTYPE* SendAuthenticate)(int32_t, uint16_t , char* , uint32_t);
inline SendAuthenticate dotnet_SendAuthenticate = reinterpret_cast<SendAuthenticate>(g_dotnet->get_method(type_name_connection_manager, L"SendAuthenticate"));

typedef void(CORECLR_DELEGATE_CALLTYPE* SendChatRoomClientJoined)(int32_t, BYTE , char* , uint32_t);
inline SendChatRoomClientJoined dotnet_SendChatRoomClientJoined = reinterpret_cast<SendChatRoomClientJoined>(g_dotnet->get_method(type_name_connection_manager, L"SendChatRoomClientJoined"));

typedef void(CORECLR_DELEGATE_CALLTYPE* SendChatRoomClientLeft)(int32_t, BYTE , char* , uint32_t);
inline SendChatRoomClientLeft dotnet_SendChatRoomClientLeft = reinterpret_cast<SendChatRoomClientLeft>(g_dotnet->get_method(type_name_connection_manager, L"SendChatRoomClientLeft"));

typedef void(CORECLR_DELEGATE_CALLTYPE* SendChatMessage)(int32_t, BYTE , BYTE , char* , uint32_t);
inline SendChatMessage dotnet_SendChatMessage = reinterpret_cast<SendChatMessage>(g_dotnet->get_method(type_name_connection_manager, L"SendChatMessage"));

typedef void(CORECLR_DELEGATE_CALLTYPE* SendKeepAlive)(int32_t);
inline SendKeepAlive dotnet_SendKeepAlive = reinterpret_cast<SendKeepAlive>(g_dotnet->get_method(type_name_connection_manager, L"SendKeepAlive"));
