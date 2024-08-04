﻿/***************************************************************************************************
 * Copyright 2024 x-tools-author(x-tools@outlook.com). All rights reserved.
 *
 * The file is encoded using "utf8 with bom", it is a part of eTools project.
 *
 * eTools is licensed according to the terms in the file LICENCE(GPL V3) in the root of the source
 * code directory.
 **************************************************************************************************/
#include "IOUiFactory.h"

#include "../xIO.h"

#include "Communication/BleCentralUi.h"
#include "Communication/CommunicationUi.h"
#include "Communication/SerialPortUi.h"
#include "Communication/TcpClientUi.h"
#include "Communication/TcpServerUi.h"
#include "Communication/UdpClientUi.h"
#include "Communication/UdpServerUi.h"
#include "Communication/WebSocketClientUi.h"
#include "Communication/WebSocketServerUi.h"

IOUiFactory::IOUiFactory() {}

IOUiFactory &IOUiFactory::singleton()
{
    static IOUiFactory instance;
    return instance;
}

CommunicationUi *IOUiFactory::createDeviceUi(xIO::CommunicationType type)
{
    switch (type) {
    case xIO::CommunicationType::SerialPort:
        return new SerialPortUi(type);
    case xIO::CommunicationType::BleCentral:
        return new BleCentralUi(type);
    case xIO::CommunicationType::UdpClient:
        return new UdpClientUi(type);
    case xIO::CommunicationType::UdpServer:
        return new UdpServerUi(type);
    case xIO::CommunicationType::TcpClient:
        return new TcpClientUi(type);
    case xIO::CommunicationType::TcpServer:
        return new TcpServerUi(type);
    case xIO::CommunicationType::WebSocketClient:
        return new WebSocketClientUi(type);
    case xIO::CommunicationType::WebSocketServer:
        return new WebSocketServerUi(type);
    default:
        return nullptr;
    }
}
