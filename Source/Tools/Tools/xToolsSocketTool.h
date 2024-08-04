﻿/***************************************************************************************************
 * Copyright 2024 x-tools-author(x-tools@outlook.com). All rights reserved.
 *
 * The file is encoded using "utf8 with bom", it is a part of eTools project.
 *
 * eTools is licensed according to the terms in the file LICENCE(GPL V3) in the root of the source
 * code directory.
 **************************************************************************************************/
#pragma once

#include <QPair>

#include "xToolsBaseTool.h"

class xToolsSocketTool : public xToolsBaseTool
{
    Q_OBJECT
public:
    explicit xToolsSocketTool(QObject *parent = nullptr);
    ~xToolsSocketTool();

    QVariantMap save() const override;
    void load(const QVariantMap &data) override;

public:
    struct ParameterKeysContext
    {
        const QString baseData{"baseData"};

        const QString clientPort{"clientPort"};
        const QString clientAddress{"clientAddress"};
        const QString serverPort{"serverPort"};
        const QString serverAddress{"serverAddress"};

        const QString channel{"channel"};

        const QString authentication{"authentication"};
        const QString username{"username"};
        const QString password{"password"};
    };

protected:
    quint16 m_clientPort{0};
    QString m_clientAddress{"0.0.0.0"};
    quint16 m_serverPort{0};
    QString m_serverAddress{"0.0.0.0"};

    int m_channel;
    bool m_authentication{false};
    QString m_username;
    QString m_password;

    ParameterKeysContext m_keys;

protected:
    QString makeFlag(const QString &address, quint16 port) const;
    QPair<QString, quint16> splitFlag(const QString &flag) const;
    bool isValidFlag(const QPair<QString, quint16> &pair) const;
};
