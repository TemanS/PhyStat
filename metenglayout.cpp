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
    ftcm = new QLineEdit;
    inch = new QLineEdit;
    inch->setFixedWidth(INWID);

    state ? setMetric() : setEnglish();

    addWidget(ftcm);
    addWidget(inch);
}

void MetEngLayout::setMetric()
{
    m_bMetric = true;
    inch->hide();

    ftcm->setFixedWidth(CMWID);
    ftcm->setInputMask("DDD");
    ftcm->setCursorPosition(0);
    ftcm->repaint();
}

void MetEngLayout::setEnglish()
{
    m_bMetric = false;

    ftcm->setFixedWidth(FTWID);
    ftcm->setInputMask("D");
    ftcm->setCursorPosition(0);
    ftcm->repaint();

    inch->setFixedWidth(INWID);
    inch->setInputMask("DD");
    inch->setCursorPosition(0);
    inch->repaint();
    inch->show();
}
