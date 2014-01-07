/******************************************************************************
**
** phystat - an application that returns standare physical attributes for
**           a given age and height.
**
**  Matias Valenzuela
**  Tony Camuso
**  January 3, 2014
**
**    phystat is free software: you can redistribute it and/or modify
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
**  Copyright 2014 by Matias Valenzuela and Tony Camuso
**
******************************************************************************/

/******************************************************************************
**
**    APPLICATION WINDOW LAYOUT
**    =========================
**
**    Gender     Measurement System
**                                                      +----------+
**    (*) Male     (*) English                  Weight  |          |
**    ( ) Female   ( ) Metric                           +----------+
**                                                      +----------+
**                  +-------+              Cholesterol  |          |
**             Age  |       |                           +----------+
**                  +-------+                           +----------+
**                  +-------+           Blood Pressure  |          |
**          Height  |       |                           +----------+
**                  +-------+                           +----------+
**                  +-------+               Heart Rate  |          |
**                  |  GO   |                           +----------+
**                  +-------+
**
******************************************************************************/

#include "phystat.h"


PhyStat::PhyStat(QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle("Physical Statistics");
    this->setWindowFlags(Qt::Window);

    // Apply the CSS sheet from the QpAppStyle class.
    //
    QpAppStyle style;
    setStyleSheet(*style.getAppStyle());

    // Create the main layout
    //
    QHBoxLayout *mainLayout = new QHBoxLayout(this);

    // Create the input group and add it to the main layout.
    //
    createInputGroup();
    createOutputGroup();
    mainLayout->addWidget(inputGroupBox);
    mainLayout->addWidget(outputGroupBox);

    // Set the maximum size to the size given to us by the OS and fix the
    // size so it can't be changed.
    //
    QSize osSize = minimumSize();
    setMaximumSize(osSize);
    setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

    // Set this dialog's layout to mainLayout
    //
    setLayout(mainLayout);

}

PhyStat::~PhyStat()
{

}

void PhyStat::createInputGroup()
{
    // Create a box to contain the Input Parameters with a minimum width.
    // and set the alignment of the Box contents to Left.
    //
    int GroupBoxWidth = 300;
    inputGroupBox = new QGroupBox;
    inputGroupBox->setMinimumWidth(GroupBoxWidth);
    inputGroupBox->setAlignment(Qt::AlignLeft);

    // Create a grid layout within the inputGroupBox
    //
    QGridLayout *inputGroupLayout = new QGridLayout;

    //Create the gender radio buttons//
    //
    QLabel *gender = new QLabel("Gender");
    QButtonGroup *genderButtons = new QButtonGroup;
    QRadioButton *male = new QRadioButton ("Male");
    QRadioButton *female = new QRadioButton ("Female");


    // Add the radio buttons to the genderButtons, initialize their ID's,
    // and set their attributes to exclusive, set the "Male" radio button
    // as the default by setting it "true" when the app is invoked.
    //
    genderButtons->addButton(male, 0);
    genderButtons->addButton(female,  1);
    genderButtons->setExclusive(true);
    male->setChecked(true);

    //Add the buttons to the layout in the first colum (c1)
    inputGroupLayout->addWidget(gender, 0,0);
    inputGroupLayout->addWidget(male, 1, 0);
    inputGroupLayout->addWidget(female, 2, 0);

    // Create the "Measurement System" Label and Radio buttons and create a
    // QButtonGroup to contain the two radio buttons.
    //
    QLabel *MeasSys = new QLabel("Measurement System");
    QButtonGroup *measureButtonGroup = new QButtonGroup;
    QRadioButton *RbEnglish = new QRadioButton("English(ex. inch)");
    QRadioButton *RbMetric  = new QRadioButton("Metric (ex. cm)");

    // Add the radio buttons to the measureButtonGroup, initialize their ID's,
    // and set their attributes to exclusive, set the "English" radio button
    // as the default by setting it "true" when the app is invoked.
    //
    measureButtonGroup->addButton(RbEnglish, 0);
    measureButtonGroup->addButton(RbMetric,  1);
    measureButtonGroup->setExclusive(true);
    RbMetric->setChecked(true);

    // Add the buttons to the layout in the second column (c2)
    //
    inputGroupLayout->addWidget(MeasSys,   0, 1);
    inputGroupLayout->addWidget(RbEnglish, 1, 1);
    inputGroupLayout->addWidget(RbMetric,  2, 1);

    // Create the Age and Height labels
    //
    QLabel    *ageLabel = new QLabel("      Age");
    QLabel    *htLabel  = new QLabel("      Height");
    QPushButton *Go    = new QPushButton("Go");

    // Create the Age and Height edit boxes
    //
    QLineEdit *ageEdit  = new QLineEdit("142");
    QLineEdit *htedit   = new QLineEdit("154");
    ageEdit->setFixedWidth(100);
    htedit->setFixedWidth(100);
    ageEdit->setInputMask("DDD");
    htedit->setInputMask("DDD");
    Go->setMaximumWidth(100);

    //trying to add a minimize widget


    //playing with slots and signals//
     QObject::connect(Go, SIGNAL(pressed()), htedit, SLOT(clear()));
     QObject::connect(Go, SIGNAL(pressed()), ageEdit, SLOT(clear()));

    // Add the labels and edit boxes to the layout.
    //
    inputGroupLayout->addWidget(ageLabel, 3, 0);
    inputGroupLayout->addWidget(ageEdit,  3, 1);
    inputGroupLayout->addWidget(htLabel,  4, 0);
    inputGroupLayout->addWidget(htedit,   4, 1);
    inputGroupLayout->addWidget(Go,   5, 1);

    // Set the layout of the inputGroupBox to the inputGroupLayout created
    // in the above code.
    //
    inputGroupBox->setLayout(inputGroupLayout);
}

void PhyStat::createOutputGroup()
{
    int GroupBoxWidth = 300;
    outputGroupBox = new QGroupBox;
    outputGroupBox->setMinimumWidth(GroupBoxWidth);
    outputGroupBox->setAlignment(Qt::AlignLeft);

    // Create a grid layout within the outputGroupBox
    //
    QGridLayout *outputGroupLayout = new QGridLayout;

    QStringList labelStrings;
    labelStrings
           << "Weight" << "Cholesterol" << "Blood Pressure"
           << "Heart Rate";

    for(int index = 0; index < enum_max_stat; index++) {
        QLabel *label = new QLabel;
        outLabelList.append(label);
        label->setText(labelStrings[index]);
        outputGroupLayout->addWidget(label, index, 0);

        QLineEdit *outBox = new QLineEdit;
        outBoxList.append(outBox);
        outputGroupLayout->addWidget(outBox, index, 1);
    }

    outputGroupBox->setLayout(outputGroupLayout);
}
