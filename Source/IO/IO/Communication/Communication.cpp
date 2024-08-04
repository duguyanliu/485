﻿/***************************************************************************************************
 * Copyright 2024 x-tools-author(x-tools@outlook.com). All rights reserved.
 *
 * The file is encoded using "utf8 with bom", it is a part of eTools project.
 *
 * eTools is licensed according to the terms in the file LICENCE(GPL V3) in the root of the source
 * code directory.
 **************************************************************************************************/
#include "Communication.h"

Communication::Communication(QObject *parent)
    : AbstractIO(parent)
{}

Communication::~Communication()
{
    if (isRunning()) {
        closeDevice();
    }
}

void Communication::openDevice()
{
    if (isRunning()) {
        closeDevice();
    }

    start();
}

void Communication::closeDevice()
{
    exit();
    wait();
}

void Communication::inputBytes(const QByteArray &bytes)
{
    emit invokeWriteBytes(bytes);
}

void Communication::setParameters(const QVariantMap &parameters)
{
    m_parametersMutex.lock();
    m_parameters = parameters;
    m_parametersMutex.unlock();
}

void Communication::run()
{
    m_deviceObj = initDevice();
    if (!m_deviceObj) {
        emit closed();
        return;
    }

    connect(this, &Communication::invokeWriteBytes, m_deviceObj, [this](const QByteArray &bytes) {
        writeBytes(bytes);
    });

    emit opened();
    exec();

    m_deviceObj = nullptr;
    deinitDevice();
    emit closed();
}
