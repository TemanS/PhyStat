/******************************************************************************
** class MetEngLayout - a Layout that can present metric or english measure
**                      QLineEdit boxes
**
** When the state is set to Metric, only one QLineEdit box appears with the
** label "cm".
** When the state is set to English, two QLineEdit boxes appear with labels
** for "ft" and "in".
**
**  Matias Valenzuela
**  Tony Camuso
**  January 3, 2014
**
**    This class is free software: you can redistribute it and/or modify
**    it under the terms of the GNU General Public License as published by
**    the Free Software Foundation, either version 3 of the License, or
**    (at your option) any later version.
**
**    This class is distributed in the hope that it will be useful,
**    but WITHOUT ANY WARRANTY; without even the implied warranty of
**    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
**    GNU General Public License for more details.
**
**  GNU General Public License http://www.gnu.org/licenses/gpl.html
**
**  Copyright 2014 by Matias Valenzuela and Tony Camuso
**
******************************************************************************/
#include "metenglayout.h"

MetEngLayout::MetEngLayout(bool state, QWidget *parent) :
    QHBoxLayout(parent)
{
    // Create the Edit boxes for ft/cm and inches. We can set the width of
    // the inch edit box now, since that won't change.
    //
    ftcmEdit = new QLineEdit("");
    inchEdit = new QLineEdit("");
    inchEdit->setFixedWidth(INWID);

    // Create the labels for ft/cm and inches. We can put the text into the
    // inches label now, since that won't change, either.
    //
    ftcmLabel = new QLabel;
    inchLabel = new QLabel("in");

    // Set the inchEdit box to its fixed width and to two decimal digits.
    // These parameters won't change, so we can initialize them once for
    // all here.
    //
    inchEdit->setFixedWidth(INWID);
    inchEdit->setInputMask("DD");

    // Initialize the state of the metenglayout object. If the object was
    // instantiated without a state argument, the default is "true", which
    // means the default measurement system is metric.
    //
    state ? setMetric() : setEnglish();

    // When adding the ftcmEdit and ftcmLabel widgets, we want them to fill
    // the available space and align left within the QHBoxLayout. The secret
    // is to set the stretch (second arg) = 1, and the alignment (third arg)
    // = QtAlignLeft.
    // See http://lists.qt.nokia.com/public/qt-interest/2011-March/031994.html
    //
    addWidget(ftcmEdit,  1, Qt::AlignLeft);
    addWidget(ftcmLabel, 1, Qt::AlignLeft);

    // Add the inch Edit box and label.
    //
    addWidget(inchEdit);
    addWidget(inchLabel);
}

void MetEngLayout::setMetric()
{
    // Set the internal flag.
    //
    m_bMetric = true;

    // Hide the inches edit box and label.
    //
    inchEdit->hide();
    inchLabel->hide();

    // Set the text in ftcmLabel to "cm", because we will be expecting
    // input in centimeters.
    //
    ftcmLabel->setText("cm");

    // Set the width of the ftcmEdit box to its size for metric inputs.
    // Set the input mask for three decimal digits.
    // Set the cursor position to 0.
    //
    ftcmEdit->setFixedWidth(CMWID);
    ftcmEdit->setInputMask("DDD");
    ftcmEdit->setCursorPosition(0);
}

void MetEngLayout::setEnglish()
{
    // Set the internal flag
    //
    m_bMetric = false;

    // Set the text in ftcmLabel to "ft", because we will be expecting
    // input in feet. Set the width to the size for input in feet, and
    // set the input mask for one decimal digit.
    //
    ftcmLabel->setText("ft");
    ftcmEdit->setFixedWidth(FTWID);
    ftcmEdit->setInputMask("D");
    ftcmEdit->setCursorPosition(0);

    // Set the cursor postition in the inchEdit box to 0, and make it
    // visible by calling the show() method.
    //
    inchEdit->setCursorPosition(0);
    inchEdit->show();
    inchLabel->show();
}
