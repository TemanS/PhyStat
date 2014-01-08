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
#ifndef METENGLAYOUT_H
#define METENGLAYOUT_H

#include <QHBoxLayout>
#include <QLineEdit>

#define CMWID 100               // Width of Centimeter Box
#define FTWID  50               // Width of Foot Box
#define INWID (CMWID - FTWID)   // Width of Inch box

class MetEngLayout : public QHBoxLayout
{
    Q_OBJECT
public:
    explicit MetEngLayout(bool state = true, QWidget *parent = 0);

    QLineEdit *ftcm;
    QLineEdit *inch;

    // Functions that return and set the state of the MetEngLayout
    //
    bool isMetric()  { return  m_bMetric; }
    bool isEnglish() { return !m_bMetric; }
    void setMetric();
    void setEnglish();

signals:

public slots:

private:
    bool m_bMetric;
};

#endif // METENGLAYOUT_H
