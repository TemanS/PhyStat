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
**    Gender     Measurement System    Optimal Measurements
**                                                      +----------+
**    (*) Male     (*) English                  Weight  |          |
**    ( ) Female   ( ) Metric                           +----------+
**                                                      +----------+
**                  +-------+          Body Mass Index  |          |
**             Age  |       |                           +----------+
**                  +-------+                           +----------+
**                  +-------+           Blood Pressure  |          |
**          Height  |       |                           +----------+
**                  +-------+                           +----------+
**                  +-------+               Heart Rate  |          |
**                  |  GO   |                           +----------+
**                  +-------+                           +----------+
**                                   Total Cholesterol  |          |
**                                                      +----------+
**                                                      +----------+
**                               LDL (bad) Cholesterol  |          |
**                                                      +----------+
**                                                      +----------+
**                              HDL (good) Cholesterol  |          |
**                                                      +----------+
**                                                      +----------+
**                                       Triglycerides  |          |
**                                                      +----------+
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
    inputGroupBox = new QGroupBox;
    inputGroupBox->setMinimumWidth(INBOX_WID);
    inputGroupBox->setAlignment(Qt::AlignLeft);

    // Create a grid layout to be placed within the inputGroupBox
    //
    QGridLayout *inputGroupLayout = new QGridLayout;
    inputGroupLayout->setAlignment(Qt::AlignTop);

    //Create the gender radio buttons//
    //
    genderButtonGroup = new QButtonGroup;
    QLabel *gender = new QLabel("Gender");
    QRadioButton *male   = new QRadioButton ("Male");
    QRadioButton *female = new QRadioButton ("Female");

    // Add the radio buttons to the genderButtonGroup, initialize their ID's,
    // and set their attributes to exclusive, set the "Male" radio button
    // as the default by setting it "true" when the app is invoked.
    //
    genderButtonGroup->addButton(male,   sx_male);
    genderButtonGroup->addButton(female, sx_female);
    genderButtonGroup->setExclusive(true);
    male->setChecked(true);

    //Add the buttons to the layout in the first colum (c0)
    //                                  R   C
    //                                 --- ---
    inputGroupLayout->addWidget(gender, 0,  0);
    inputGroupLayout->addWidget(male,   1,  0);
    inputGroupLayout->addWidget(female, 2,  0);

    // Create the "Measurement System" Label and Radio buttons and create a
    // QButtonGroup to contain the two radio buttons.
    //
    measureButtonGroup = new QButtonGroup;
    QLabel *MeasSys = new QLabel("Measurement System");
    QRadioButton *RbEnglish = new QRadioButton("English");
    QRadioButton *RbMetric  = new QRadioButton("Metric");

    // Add the radio buttons to the measureButtonGroup, initialize their ID's,
    // and set their attributes to exclusive, set the "English" radio button
    // as the default by setting it "true" when the app is invoked.
    //
    measureButtonGroup->addButton(RbEnglish, ms_english);
    measureButtonGroup->addButton(RbMetric,  ms_metric);
    measureButtonGroup->setExclusive(true);
    RbEnglish->setChecked(true);

    // Add the buttons to the layout in the second column (c1)
    //                                     R   C
    //                                    --- ---
    inputGroupLayout->addWidget(MeasSys,   0,  1);
    inputGroupLayout->addWidget(RbEnglish, 1,  1);
    inputGroupLayout->addWidget(RbMetric,  2,  1);

    // Connect the measureButtonGroup buttonClicked SIGNAL to the
    // onMeasure SLOT. The integer ID of which radio button was
    // clicked will be passed to the onMeasure SLOT.
    //
    connect(measureButtonGroup, SIGNAL(buttonClicked(int)),
                          this, SLOT(onMeasure(int)));

    // Create the Age and Height labels
    //
    QLabel    *ageLabel = new QLabel("      Age");
    QLabel    *htLabel  = new QLabel("      Height");

    // Create the Age edit box and fix its width.
    //
    QLineEdit *ageEdit = new QLineEdit;
    ageEdit->setFixedWidth(BOX_WID);

    // Create and initialize a validator for the age entries.
    // Set the valid ages to between 1 and 110 years.
    //
    ageEdit->setValidator(&ageValidator);
    ageValidator.setRange(MIN_AGE, MAX_AGE);

    // Create a Metric/English layout. This is a layout that can present
    // one box for input in cm, and two boxes for input in ft and inches.
    // Initialize it with the id of the currently checked Measurement
    // System selection radio button.
    //
    htedit = new MetEngLayout(measureButtonGroup->checkedId() == ms_metric ?
                              true : false);

    // Create the "Go" button and connect it to the SLOT function onGo()
    //
    QPushButton *Go = new QPushButton("Go");
    Go->setMaximumWidth(BOX_WID);
    connect(Go, SIGNAL(clicked()), this, SLOT(onGo()));

    // Add the labels and edit boxes to the layout.
    //                                    R   C
    //                                   --- ---
    inputGroupLayout->addWidget(ageLabel, 3,  0);
    inputGroupLayout->addWidget(ageEdit,  3,  1);
    inputGroupLayout->addWidget(htLabel,  4,  0);
    inputGroupLayout->addLayout(htedit,   4,  1);
    inputGroupLayout->addWidget(Go,       5,  1);

    // Set the layout of the inputGroupBox to the inputGroupLayout created
    // in the above code.
    //
    inputGroupBox->setLayout(inputGroupLayout);
}

void PhyStat::createOutputGroup()
{
    // Create a GroupBox as a container for our layout and set its
    // maximum width.
    //
    outputGroupBox = new QGroupBox;
    outputGroupBox->setMinimumWidth(OUTBOX_WID);

    // Create a grid layout in which to add the widgets we will create
    // for the output.
    //
    QGridLayout *outputGroupLayout = new QGridLayout;
    outputGroupLayout->setAlignment(Qt::AlignTop);

    // Create a label for the output box and allow it to span two columns.
    // Row 0, Col 0, Row Span = 1, Col Span = 2, alignment = left
    //
    QLabel *outputGroupLabel = new QLabel("Maximum Cardio and Metabolic Values");
    outputGroupLayout->addWidget(outputGroupLabel, 0, 0, 1, 2, Qt::AlignLeft);

    //Create a string list to contain the labels for the output boxes.
    //
    QStringList labelStrings;
    labelStrings
           << "Weight"
           << "Body Mass Index"
           << "Blood Pressure"
           << "Heart Rate"
           << "Total Cholesterol"
           << "LDL (bad) Cholesterol"
           << "HDL (good) Cholesterol"
           << "Triglycerides";

    // Create and initialize the ouput QLabels and QLineEdit boxes in a loop
    //
    for(int index = 0; index < labelStrings.size(); index++) {
        QLabel *label = new QLabel;
        outLabelList.append(label);
        label->setText(labelStrings[index]);
        outputGroupLayout->addWidget(outLabelList[index], index+1, 0);

        outBoxList.append(new QLineEdit);
        outputGroupLayout->addWidget(outBoxList[index], index+1, 1);
    }

    outputGroupBox->setLayout(outputGroupLayout);
}

void PhyStat::onGo()
{

}

void PhyStat::onMeasure(int rbId)
{
    rbId == 0 ? htedit->setEnglish() : htedit->setMetric();
}
