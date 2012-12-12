/************************************************************************
**
**  Copyright (C) 2012 Dave Heiland, John Schember
**
**  This file is part of Sigil.
**
**  Sigil is free software: you can redistribute it and/or modify
**  it under the terms of the GNU General Public License as published by
**  the Free Software Foundation, either version 3 of the License, or
**  (at your option) any later version.
**
**  Sigil is distributed in the hope that it will be useful,
**  but WITHOUT ANY WARRANTY; without even the implied warranty of
**  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
**  GNU General Public License for more details.
**
**  You should have received a copy of the GNU General Public License
**  along with Sigil.  If not, see <http://www.gnu.org/licenses/>.
**
*************************************************************************/

#pragma once
#ifndef PREVIEWWINDOW_H
#define PREVIEWWINDOW_H

#include <QtGui/QDockWidget>
#include <QtCore/QTime>

#include "MainUI/MainWindow.h"

class QWidget;
class BookViewPreview;

class PreviewWindow : public QDockWidget
{
    Q_OBJECT

public:
    PreviewWindow(QWidget *parent = 0);
    ~PreviewWindow();

public slots:
    void UpdatePage(QString filename, QString text, QList< ViewEditor::ElementIndex > location, bool highlight_location);
    void ClearPage();
    void SetZoomFactor(float factor);

signals:
    void Shown();

protected:
    virtual void showEvent(QShowEvent *event);

private:
    QWidget &m_MainWidget;
    QVBoxLayout &m_Layout;

    BookViewPreview *m_Preview;
    QString m_OldText;
};

#endif // PREVIEWWINDOW_H