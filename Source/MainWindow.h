/***************************************************************************************************
 * Copyright 2018-2024 x-tools-author(x-tools@outlook.com). All rights reserved.
 *
 * The file is encoded using "utf8 with bom", it is a part of xTools project.
 *
 * xTools is licensed according to the terms in the file LICENCE(GPL V3) in the root of the source
 * code directory.
 **************************************************************************************************/
#pragma once

#include <QButtonGroup>
#include <QMetaEnum>

#ifdef X_TOOLS_ENABLE_MODULE_PRIVATE
#include "xToolsPrivateMainWindow.h"
#else
#include "xToolsMainWindow.h"
#endif

#ifdef X_TOOLS_ENABLE_MODULE_PRIVATE
class MainWindow : public xToolsPrivateMainWindow
#else

class IOPage;
class MainWindow : public xToolsMainWindow
#endif
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget* parent = Q_NULLPTR);
    ~MainWindow() override;

#ifdef Q_OS_WIN
protected:
    void closeEvent(QCloseEvent* event) override;
#endif

private:
    enum class WindowGrid { Grid1x1, Grid1x2, Grid2x1, Grid2x2 };
    struct SettingsKeys
    {
        const QString windowGrid{"MainWindow/windowGrid"};
        const QString isTextBesideIcon{"MainWindow/isTextBesideIcon"};
        const QString pageIndex{"MainWindow/pageIndex"};
        const QString exitToSystemTray{"MainWindow/exitToSystemTray"};
    } m_settingsKey;

    QMenu* m_toolMenu;
    WindowGrid m_windowGrid{WindowGrid::Grid1x1};
    IOPage* m_ioPage00;
    IOPage* m_ioPage01;
    IOPage* m_ioPage10;
    IOPage* m_ioPage11;

private:
    void initMenuBar();
    void initFileMenu();
    void initToolMenu();
    void initOptionMenu();
    void initViewMenu();
    void initLanguageMenu();
    void initHelpMenu();
    void initLinksMenu();
    void initNav();

    void updateGrid(WindowGrid grid);
    void showHistory();
    void showQrCode();
};
