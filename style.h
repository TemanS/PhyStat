/******************************************************************************
**
**  qpgui - a library of classes and templates originally devised to
**          accomodate a dialog-based suite of math exercises.
**
**  Tony Camuso
**  December, 2011
**
**  Version 0.1
**
**    mathtest is free software: you can redistribute it and/or modify
**    it under the terms of the GNU General Public License as published by
**    the Free Software Foundation, either version 3 of the License, or
**    (at your option) any later version.
**
**    This program is distributed in the hope that it will be useful,
**    but WITHOUT ANY WARRANTY; without even the implied warranty of
**    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
**    GNU General Public License for more details.
**
**  GNU General Public License http://www.gnu.org/licenses/gpl.html
**
**  Copyright 2011, 2012, 2013 by Tony Camuso.
**
******************************************************************************/

#ifndef STYLESHEET_H
#define STYLESHEET_H

QT_BEGIN_NAMESPACE
class QString;
QT_END_NAMESPACE

class QpAppStyle
{
public:
    QpAppStyle();
    QString* getAppStyle();

private:
    QString *pAppStyle;
};

#endif // STYLESHEET_H
