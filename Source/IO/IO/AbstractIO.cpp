﻿/***************************************************************************************************
 * Copyright 2023-2024 x-tools-author(x-tools@outlook.com). All rights reserved.
 *
 * The file is encoded using "utf8 with bom", it is a part of xTools project.
 *
 * xTools is licensed according to the terms in the file LICENCE(GPL V3) in the root of the source
 * code directory.
 **************************************************************************************************/
#include "AbstractIO.h"

#include <QDateTime>
#include <QDebug>
#include <QtGlobal>

AbstractIO::AbstractIO(QObject *parent)
    : QThread{parent}
{
    connect(this, &AbstractIO::started, this, [=]() {
        this->m_isWorking = true;
        emit this->isWorkingChanged();
    });
    connect(this, &AbstractIO::finished, this, [=]() {
        this->m_isWorking = false;
        emit this->isWorkingChanged();
    });
    connect(this, &AbstractIO::errorOccurred, this, [=](const QString &errorString) {
        qWarning() << "Error occured: " << errorString;
        exit();
        wait();
    });
}

AbstractIO::~AbstractIO()
{
    if (isRunning()) {
        exit();
        wait();
    }
}

QVariantMap AbstractIO::save() const
{
    QVariantMap data;
    data["isEnable"] = m_enable.load();
    return data;
}

void AbstractIO::load(const QVariantMap &data)
{
    if (data.isEmpty()) {
        return;
    }

    bool isEnable = data["isEnable"].toBool();
    m_enable.store(isEnable);
    emit isEnableChanged();
}

bool AbstractIO::isWorking()
{
    return m_isWorking;
}

bool AbstractIO::isEnable()
{
    return m_enable;
}

void AbstractIO::setIsEnable(bool enable)
{
    m_enable = enable;
    emit isEnableChanged();
}
