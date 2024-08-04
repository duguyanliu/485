/***************************************************************************************************
 * Copyright 2023-2024 x-tools-author(x-tools@outlook.com). All rights reserved.
 *
 * The file is encoded using "utf8 with bom", it is a part of xTools project.
 *
 * xTools is licensed according to the terms in the file LICENCE(GPL V3) in the root of the source
 * code directory.
 **************************************************************************************************/
#include "xToolsTextFormatComboBox.h"

#include "xToolsDataStructure.h"

xToolsTextFormatComboBox::xToolsTextFormatComboBox(QWidget* parent)
    : xToolsComboBox(parent)
{
    auto formats = xToolsDataStructure::supportedTextFormats();
    for (auto &format : formats) {
        addItem(xToolsDataStructure::textFormatName(format.toInt()), format.toInt());
    }

    blockSignals(true);
    setCurrentIndex(5);
    blockSignals(false);
}